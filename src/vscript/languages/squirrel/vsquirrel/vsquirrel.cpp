// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/vsquirrel/vsquirrel.cpp
// Functions: 186
// ============================================================

#include "vscript\languages\squirrel\vsquirrel\vsquirrel.h"

//------------------------------------------------------------------------------
// Address: 0x10023EA0
// Name: __heap_term
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall _heap_term(CSquirrelVM *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10025370
// Name: public: virtual void CSquirrelVM::AddSearchPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::AddSearchPath(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10026240
// Name: public: void CUtlBuffer::PutInt(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlBuffer::PutInt(CUtlBuffer *this@<ecx>, void *i@<eax>)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%d", i);
  else
    CUtlBuffer::PutTypeBin<void *>(this, src: i);
}

//------------------------------------------------------------------------------
// Address: 0x10026270
// Name: public: int StackHandler::Return(float)
// Source: json
//------------------------------------------------------------------------------
int __usercall StackHandler::Return@<eax>(StackHandler *this@<ecx>, int a2@<eax>, int a3@<xmm0>)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  _DWORD *v7; // eax
  _DWORD *v8; // ecx

  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(_DWORD *)(v3 + 56);
  *(_DWORD *)(v3 + 56) = v4 + 1;
  v5 = *(_DWORD *)(v3 + 32);
  v6 = *(_DWORD *)(v5 + 8 * v4);
  v7 = (_DWORD *)(v5 + 8 * v4);
  v8 = (_DWORD *)v7[1];
  v7[1] = a3;
  *v7 = 83886084;
  if ( (v6 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100262D0
// Name: public: int StackHandler::Return(int)
// Source: json
//------------------------------------------------------------------------------
int __usercall StackHandler::Return@<eax>(StackHandler *this@<eax>, tagSQObjectValue i@<esi>, int a3@<ecx>)
{
  SQVM *v; // eax
  int top; // ecx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // edx
  SQObjectPtr *v7; // eax
  _DWORD *v8; // ecx

  v = this->v;
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  v7 = &vals[top];
  v8 = &v7->_unVal.pTable->__vftable;
  v7->_unVal = i;
  v7->_type = OT_INTEGER;
  if ( (type & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__cdecl **)(int))(*v8 + 8))(a1: a3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026320
// Name: public: int StackHandler::Return(bool)
// Source: json
//------------------------------------------------------------------------------
int __userpurge StackHandler::Return@<eax>(StackHandler *this@<ecx>, int a2@<eax>, bool b)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // ecx

  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(_DWORD *)(v3 + 56);
  *(_DWORD *)(v3 + 56) = v4 + 1;
  v5 = *(_DWORD *)(v3 + 32);
  v6 = *(_DWORD *)(v5 + 8 * v4);
  v7 = (_DWORD *)(v5 + 8 * v4);
  v8 = (_DWORD *)v7[1];
  *v7 = 16777224;
  v7[1] = b;
  if ( (v6 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026370
// Name: public: SQObjectPtr::~SQObjectPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQObjectPtr::~SQObjectPtr(SQLocalVarInfo *this)
{
  tagSQObjectValue v1; // eax

  if ( (this->_name._type & 0x8000000) != 0 )
  {
    v1.pTable = (SQTable *)this->_name._unVal;
    if ( (int)--*(_DWORD *)(v1.nInteger + 4) <= 0 )
      this->_name._unVal.pTable->Release(this: (struct SQTable *)this->_name._unVal.nInteger);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026390
// Name: public: void SQObjectPtr::Null(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQObjectPtr::Null(SQObjectPtr *this@<ecx>, int *a2@<eax>)
{
  int v2; // edx
  _DWORD *v3; // ecx

  v2 = *a2;
  v3 = (_DWORD *)a2[1];
  *a2 = 16777217;
  a2[1] = 0;
  if ( (v2 & 0x8000000) != 0 && (int)--v3[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100263C0
// Name: public: struct SQObjectPtr __near & SQObjectPtr::operator=(struct tagSQObject const __near &)
// Source: json
//------------------------------------------------------------------------------
SQObjectPtr *__usercall SQObjectPtr::operator=@<eax>(SQObjectPtr *this@<esi>, const SQObjectPtr *obj@<eax>)
{
  _DWORD *v2; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v4; // eax

  v2 = &this->_unVal.pTable->__vftable;
  type = this->_type;
  this->_unVal.nInteger = obj->_unVal.nInteger;
  v4 = obj->_type;
  this->_type = v4;
  if ( (v4 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v2[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v2 + 8))(a1: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10026400
// Name: private: virtual SQArray::~SQArray(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQArray::~SQArray(SQArray *this@<ecx>, int a2@<esi>)
{
  bool v2; // zf
  int v3; // eax
  int v4; // eax

  v2 = (*(_DWORD *)(a2 + 4) & 0x40000000) == 0;
  *(_DWORD *)a2 = &SQArray::`vftable';
  if ( v2 )
  {
    this = *(SQArray **)(a2 + 16);
    if ( this != nullptr )
    {
      this->_next = *(SQCollectable **)(a2 + 12);
    }
    else
    {
      this = *(SQArray **)(a2 + 12);
      *(_DWORD *)(*(_DWORD *)(a2 + 20) + 68) = this;
    }
    v3 = *(_DWORD *)(a2 + 12);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = 0;
  }
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>((sqvector<SQObjectPtr> *)this);
  v4 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)a2 = &SQRefCounted::`vftable';
  if ( v4 != 0 )
  {
    *(_DWORD *)(v4 + 12) = 16777217;
    *(_DWORD *)(*(_DWORD *)(a2 + 8) + 16) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026470
// Name: public: static struct SQArray __near * SQArray::Create(struct SQSharedState __near *,int)
// Source: json
//------------------------------------------------------------------------------
SQArray *__cdecl SQArray::Create(SQSharedState *ss, unsigned int nInitialSize)
{
  SQArray *result; // eax
  SQArray *v3; // edi
  SQCollectable *gc_chain; // ecx
  SQObjectPtr fill; // [esp+10h] [ebp-8h] BYREF

  result = (SQArray *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 36);
  v3 = result;
  if ( result != nullptr )
  {
    result->_uiRef = 0;
    result->_weakref = nullptr;
    result->__vftable = (SQArray_vtbl *)&SQArray::`vftable';
    result->_values._vals = nullptr;
    result->_values._size = 0;
    result->_values._allocated = 0;
    fill._type = OT_NULL;
    fill._unVal.nInteger = 0;
    sqvector<SQObjectPtr>::resize(this: (sqvector<SQObjectPtr> *)&fill, newsize: nInitialSize, &fill);
    v3->_next = nullptr;
    v3->_sharedstate = ss;
    v3->_prev = nullptr;
    v3->_next = ss->_gc_chain;
    gc_chain = ss->_gc_chain;
    if ( gc_chain != nullptr )
      gc_chain->_prev = v3;
    ss->_gc_chain = v3;
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100264F0
// Name: public: virtual void SQArray::Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQArray::Finalize(SQArray *this)
{
  SQObjectPtr fill; // [esp+4h] [ebp-8h] BYREF

  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize((sqvector<SQObjectPtr> *)this, newsize: 0, &fill);
}

//------------------------------------------------------------------------------
// Address: 0x10026550
// Name: public: SQClassMember::SQClassMember(struct SQClassMember const __near &)
// Source: json
//------------------------------------------------------------------------------
SQClassMember *__usercall SQClassMember::SQClassMember@<eax>(SQClassMember *this@<esi>, const SQClassMember *o@<eax>)
{
  _DWORD *v2; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v5; // eax
  tagSQObjectValue v6; // eax
  _DWORD *v7; // ecx
  tagSQObjectType v8; // edx
  tagSQObjectType v9; // edi

  this->val._type = OT_NULL;
  this->val._unVal.nInteger = 0;
  this->attrs._type = OT_NULL;
  this->attrs._unVal.nInteger = 0;
  v2 = &this->val._unVal.pTable->__vftable;
  type = this->val._type;
  this->val._unVal.nInteger = o->val._unVal.nInteger;
  v5 = o->val._type;
  this->val._type = v5;
  if ( (v5 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->val._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v2[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v2 + 8))(a1: v2);
  v6.pTable = (SQTable *)o->attrs._unVal;
  v7 = &this->attrs._unVal.pTable->__vftable;
  v8 = this->attrs._type;
  this->attrs._unVal = v6;
  v9 = o->attrs._type;
  this->attrs._type = v9;
  if ( (v9 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6.nInteger + 4);
  if ( (v8 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100265E0
// Name: public: static struct SQInstance __near * SQInstance::Create(struct SQSharedState __near *,struct SQClass __near *)
// Source: json
//------------------------------------------------------------------------------
SQInstance *__usercall SQInstance::Create@<eax>(SQClass *theclass@<eax>, SQSharedState *ss)
{
  unsigned int size; // eax
  unsigned int v4; // eax
  int v5; // esi
  SQInstance *result; // eax
  int udsize; // edi

  size = theclass->_defaultvalues._size;
  if ( size != 0 )
    v4 = size - 1;
  else
    v4 = 0;
  v5 = theclass->_udsize + 8 * v4 + 52;
  result = (SQInstance *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v5);
  if ( result != nullptr )
    result = SQInstance::SQInstance(this: result, ss, c: theclass, memsize: v5);
  udsize = theclass->_udsize;
  if ( udsize != 0 )
    result->_userpointer = (char *)result + v5 - udsize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026630
// Name: private: SQClosure::SQClosure(struct SQSharedState __near *,struct SQFunctionProto __near *)
// Source: json
//------------------------------------------------------------------------------
SQClosure *__userpurge SQClosure::SQClosure@<eax>(
        SQClosure *this@<esi>,
        SQFunctionProto *func@<edi>,
        SQSharedState *ss)
{
  tagSQObjectType type; // eax
  _DWORD *v4; // ecx
  SQCollectable *gc_chain; // ecx

  this->__vftable = (SQClosure_vtbl *)&SQClosure::`vftable';
  this->_uiRef = 0;
  this->_weakref = nullptr;
  this->_env._unVal.nInteger = 0;
  this->_env._type = OT_NULL;
  this->_function._type = OT_NULL;
  this->_function._unVal.nInteger = 0;
  this->_outervalues._vals = nullptr;
  this->_outervalues._size = 0;
  this->_outervalues._allocated = 0;
  this->_defaultparams._vals = nullptr;
  this->_defaultparams._size = 0;
  this->_defaultparams._allocated = 0;
  ++func->_uiRef;
  type = this->_function._type;
  v4 = &this->_function._unVal.pTable->__vftable;
  this->_function._unVal.nInteger = (int)func;
  this->_function._type = OT_FUNCPROTO;
  ++func->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  if ( --func->_uiRef <= 0 )
    func->Release(this: func);
  this->_next = nullptr;
  this->_sharedstate = ss;
  this->_prev = nullptr;
  this->_next = ss->_gc_chain;
  gc_chain = ss->_gc_chain;
  if ( gc_chain != nullptr )
    gc_chain->_prev = this;
  ss->_gc_chain = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100266F0
// Name: public: virtual SQClosure::~SQClosure(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQClosure::~SQClosure(SQClosure *this@<ecx>, int a2@<esi>)
{
  bool v2; // zf
  int v3; // eax
  sqvector<SQObjectPtr> *v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v2 = (*(_DWORD *)(a2 + 4) & 0x40000000) == 0;
  *(_DWORD *)a2 = &SQClosure::`vftable';
  if ( v2 )
  {
    this = *(SQClosure **)(a2 + 16);
    if ( this != nullptr )
    {
      this->_next = *(SQCollectable **)(a2 + 12);
    }
    else
    {
      this = *(SQClosure **)(a2 + 12);
      *(_DWORD *)(*(_DWORD *)(a2 + 20) + 68) = this;
    }
    v3 = *(_DWORD *)(a2 + 12);
    if ( v3 != 0 )
    {
      this = *(SQClosure **)(a2 + 16);
      *(_DWORD *)(v3 + 16) = this;
    }
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = 0;
  }
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>((sqvector<SQObjectPtr> *)this);
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v4);
  if ( (*(_DWORD *)(a2 + 32) & 0x8000000) != 0 )
  {
    v5 = *(_DWORD *)(a2 + 36);
    if ( (int)--*(_DWORD *)(v5 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 36) + 8))(a1: *(_DWORD *)(a2 + 36));
  }
  if ( (*(_DWORD *)(a2 + 24) & 0x8000000) != 0 )
  {
    v6 = *(_DWORD *)(a2 + 28);
    if ( (int)--*(_DWORD *)(v6 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 28) + 8))(a1: *(_DWORD *)(a2 + 28));
  }
  v7 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)a2 = &SQRefCounted::`vftable';
  if ( v7 != 0 )
  {
    *(_DWORD *)(v7 + 12) = 16777217;
    *(_DWORD *)(*(_DWORD *)(a2 + 8) + 16) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100267D0
// Name: private: SQGenerator::SQGenerator(struct SQSharedState __near *,struct SQClosure __near *)
// Source: json
//------------------------------------------------------------------------------
SQGenerator *__userpurge SQGenerator::SQGenerator@<eax>(
        SQGenerator *this@<ecx>,
        int a2@<esi>,
        SQSharedState *ss,
        SQClosure *closure)
{
  int v4; // eax
  _DWORD *v5; // ecx
  SQCollectable *gc_chain; // ecx

  *(_DWORD *)a2 = &SQGenerator::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 24) = 16777217;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 64) = 16777217;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 112) = 0;
  ++closure->_uiRef;
  v4 = *(_DWORD *)(a2 + 24);
  v5 = *(_DWORD **)(a2 + 28);
  *(_DWORD *)(a2 + 28) = closure;
  *(_DWORD *)(a2 + 24) = 134217984;
  ++closure->_uiRef;
  if ( (v4 & 0x8000000) != 0 && (int)--v5[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
  if ( --closure->_uiRef <= 0 )
    closure->Release(this: closure);
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 20) = ss;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 12) = ss->_gc_chain;
  gc_chain = ss->_gc_chain;
  if ( gc_chain != nullptr )
    gc_chain->_prev = (SQCollectable *)a2;
  ss->_gc_chain = (SQCollectable *)a2;
  return (SQGenerator *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10026890
// Name: public: static struct SQGenerator __near * SQGenerator::Create(struct SQSharedState __near *,struct SQClosure __near *)
// Source: json
//------------------------------------------------------------------------------
SQGenerator *__cdecl SQGenerator::Create(SQSharedState *ss, SQGenerator *closure)
{
  SQGenerator *result; // eax
  SQGenerator *v3; // esi

  result = (SQGenerator *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 120);
  v3 = result;
  if ( result != nullptr )
  {
    SQGenerator::SQGenerator(this: closure, a2: (int)result, ss, (SQClosure *)closure);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100268C0
// Name: public: virtual SQGenerator::~SQGenerator(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQGenerator::~SQGenerator(SQGenerator *this@<ecx>, int a2@<esi>)
{
  bool v2; // zf
  int v3; // eax
  int v4; // eax
  sqvector<SQObjectPtr> *v5; // ecx
  int v6; // eax
  int v7; // eax

  v2 = (*(_DWORD *)(a2 + 4) & 0x40000000) == 0;
  *(_DWORD *)a2 = &SQGenerator::`vftable';
  if ( v2 )
  {
    this = *(SQGenerator **)(a2 + 16);
    if ( this != nullptr )
    {
      this->_next = *(SQCollectable **)(a2 + 12);
    }
    else
    {
      this = *(SQGenerator **)(a2 + 12);
      *(_DWORD *)(*(_DWORD *)(a2 + 20) + 68) = this;
    }
    v3 = *(_DWORD *)(a2 + 12);
    if ( v3 != 0 )
    {
      this = *(SQGenerator **)(a2 + 16);
      *(_DWORD *)(v3 + 16) = this;
    }
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = 0;
  }
  if ( *(_DWORD *)(a2 + 112) != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a2 + 104));
  if ( (*(_DWORD *)(a2 + 64) & 0x8000000) != 0 )
  {
    v4 = *(_DWORD *)(a2 + 68);
    if ( (int)--*(_DWORD *)(v4 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 68) + 8))(a1: *(_DWORD *)(a2 + 68));
  }
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>((sqvector<SQObjectPtr> *)this);
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v5);
  if ( (*(_DWORD *)(a2 + 24) & 0x8000000) != 0 )
  {
    v6 = *(_DWORD *)(a2 + 28);
    if ( (int)--*(_DWORD *)(v6 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 28) + 8))(a1: *(_DWORD *)(a2 + 28));
  }
  v7 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)a2 = &SQRefCounted::`vftable';
  if ( v7 != 0 )
  {
    *(_DWORD *)(v7 + 12) = 16777217;
    *(_DWORD *)(*(_DWORD *)(a2 + 8) + 16) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026990
// Name: public: virtual void SQGenerator::Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQGenerator::Finalize(SQGenerator *this)
{
  _DWORD *v2; // ecx
  tagSQObjectType type; // eax
  tagSQObjectType v4; // edx
  SQObjectPtr fill; // [esp+8h] [ebp-8h] BYREF

  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize((sqvector<SQObjectPtr> *)this, newsize: 0, &fill);
  v2 = &this->_closure._unVal.pTable->__vftable;
  type = this->_closure._type;
  this->_closure._unVal.nInteger = _null_._unVal.nInteger;
  v4 = _null_._type;
  this->_closure._type = _null_._type;
  if ( (v4 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_closure._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v2[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v2 + 8))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10026A30
// Name: SQTypeToString
// Source: json
//------------------------------------------------------------------------------
const char *__usercall SQTypeToString@<eax>(int sqType@<eax>)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax

  if ( sqType <= 134218240 )
  {
    if ( sqType == 134218240 )
      return "NATIVECLOSURE";
    if ( sqType > 83886084 )
    {
      v2 = sqType - 134217744;
      if ( v2 == 0 )
        return "STRING";
      v3 = v2 - 48;
      if ( v3 == 0 )
        return "ARRAY";
      if ( v3 == 192 )
        return "CLOSURE";
    }
    else
    {
      if ( sqType == 83886084 )
        return "FLOAT";
      if ( sqType > 16777224 )
      {
        if ( sqType == 83886082 )
          return "INTEGER";
      }
      else
      {
        switch ( sqType )
        {
          case 16777224:
            return "BOOL";
          case 2048:
            return "USERPOINTER";
          case 16777217:
            return "NULL";
          default:
            break;
        }
      }
    }
    return "<unknown>";
  }
  if ( sqType <= 134283264 )
  {
    switch ( sqType )
    {
      case 134283264:
        return "WEAKREF";
      case 134218752:
        return "GENERATOR";
      case 134221824:
        return "THREAD";
      case 134234112:
        return "CLASS";
      default:
        break;
    }
    return "<unknown>";
  }
  v4 = sqType - 167772192;
  if ( v4 == 0 )
    return "TABLE";
  v5 = v4 - 96;
  if ( v5 == 0 )
    return "USERDATA";
  if ( v5 != 32640 )
    return "<unknown>";
  return "INSTANCE";
}

//------------------------------------------------------------------------------
// Address: 0x10026B20
// Name: int VectorRelease(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorRelease(void *p)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10026B40
// Name: int VectorConstruct(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorConstruct(SQVM *hVM)
{
  int v1; // ebx
  float *v2; // edi
  int v3; // edx
  int v4; // eax
  float nInteger; // xmm0_4
  SQObjectPtr *v6; // edi
  int stackbase; // edx
  SQObjectPtr *vals; // eax
  bool v9; // zf
  SQObjectPtr *v10; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v12; // edi
  tagSQObjectType type; // eax
  _DWORD *v14; // ecx
  int v15; // eax
  SQObjectPtr *v16; // ecx
  tagSQObjectType v17; // eax
  float *v19; // [esp+Ch] [ebp-4h]

  v1 = hVM->_top - hVM->_stackbase;
  v2 = (float *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
  v3 = 0;
  v19 = v2;
  v4 = 2;
  while ( v3 < v1 - 1 )
  {
    nInteger = 0.0;
    if ( v4 > 0 && v4 <= v1 )
    {
      v6 = &hVM->_stack._vals[v4 - 1 + hVM->_stackbase];
      if ( (v6->_type & 0x4000000) != 0 )
      {
        if ( v6->_type == OT_INTEGER )
          nInteger = (float)v6->_unVal.nInteger;
        else
          nInteger = v6->_unVal.fFloat;
      }
    }
    v2 = v19;
    v19[v3] = nInteger;
    ++v4;
    ++v3;
    if ( v4 >= 5 )
      goto LABEL_13;
  }
  if ( v3 < 3 )
    memset(&v2[v3], 0, 4 * (3 - v3));
LABEL_13:
  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v9 = vals[stackbase]._type == OT_INSTANCE;
  v10 = &vals[stackbase];
  if ( v9 )
  {
    *(_DWORD *)(v10->_unVal.nInteger + 32) = v19;
  }
  else
  {
    sharedstate = hVM->_sharedstate;
    v12 = StringTable::Add(this: sharedstate->_stringtable, news: "the object is not a class instance", len: -1);
    v12->_sharedstate = sharedstate;
    ++v12->_uiRef;
    type = hVM->_lasterror._type;
    v14 = &hVM->_lasterror._unVal.pTable->__vftable;
    hVM->_lasterror._unVal.nInteger = (int)v12;
    hVM->_lasterror._type = OT_STRING;
    ++v12->_uiRef;
    if ( (type & 0x8000000) != 0 && (int)--v14[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
    if ( --v12->_uiRef <= 0 )
      v12->Release(this: v12);
  }
  v15 = hVM->_stackbase;
  if ( hVM->_top - v15 >= 1 )
  {
    v16 = &hVM->_stack._vals[v15];
    v17 = v16->_type;
    if ( v16->_type == OT_CLASS )
    {
      *(_DWORD *)(v16->_unVal.nInteger + 80) = VectorRelease;
    }
    else
    {
      if ( v17 == OT_USERDATA )
      {
        *(_DWORD *)(v16->_unVal.nInteger + 32) = VectorRelease;
        return 0;
      }
      if ( v17 == OT_INSTANCE )
      {
        *(_DWORD *)(v16->_unVal.nInteger + 36) = VectorRelease;
        return 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10026CC0
// Name: int VectorGet(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorGet(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  int v3; // esi
  bool v4; // zf
  SQObjectPtr *v5; // eax
  int v6; // edx
  int v8; // eax
  SQObjectPtr *v9; // ecx
  int v10; // eax
  SQString *v11; // esi
  const char *v12; // eax
  char *v13; // eax
  int v14; // [esp+Ch] [ebp-4h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = hVM->_top - stackbase;
  v4 = vals[stackbase]._type == OT_INSTANCE;
  v5 = &vals[stackbase];
  if ( v4 )
  {
    v6 = *(_DWORD *)(v5->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_5:
      sq_throwerror(v: hVM, err: "null vector");
      return -1;
    }
    v6 = v14;
  }
  if ( v6 == 0 )
    goto LABEL_5;
  if ( v3 < 2 )
    return -1;
  v8 = hVM->_stackbase;
  v9 = hVM->_stack._vals;
  v4 = v9[v8 + 1]._type == OT_STRING;
  v10 = (int)&v9[v8 + 1];
  if ( v4 )
  {
    v13 = (char *)(*(_DWORD *)(v10 + 4) + 28);
    if ( v13 == nullptr || *v13 == 0 || v13[1] != 0 || (unsigned int)(*v13 - 120) > 2 )
      return -1;
    sq_pushfloat();
    return 1;
  }
  else
  {
    v11 = SQVM::PrintObjVal(this: (SQVM *)v9, o: (const tagSQObject *)hVM);
    ++v11->_uiRef;
    v12 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v12, v11->_val);
    if ( --v11->_uiRef > 0 )
      return -1;
    v11->Release(this: v11);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026DB0
// Name: int VectorSet(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorSet(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  int v3; // ebx
  bool v4; // zf
  SQObjectPtr *v5; // eax
  int v7; // ecx
  SQObjectPtr *v8; // esi
  SQString *v9; // esi
  const char *v10; // eax
  _BYTE *v11; // eax
  unsigned int v12; // eax
  float nInteger; // xmm0_4
  tagSQObjectType type; // edx
  int v15; // [esp+Ch] [ebp-4h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = hVM->_top - stackbase;
  v4 = vals[stackbase]._type == OT_INSTANCE;
  v5 = &vals[stackbase];
  if ( v4 )
  {
    v15 = *(_DWORD *)(v5->_unVal.nInteger + 32);
  }
  else if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
  {
LABEL_4:
    sq_throwerror(v: hVM, err: "null vector");
    return -1;
  }
  if ( v15 == 0 )
    goto LABEL_4;
  if ( v3 < 2 )
    return -1;
  v7 = hVM->_stackbase;
  v8 = hVM->_stack._vals;
  if ( v8[v7 + 1]._type == OT_STRING )
  {
    v11 = (_BYTE *)(v8[v7 + 1]._unVal.nInteger + 28);
    if ( v8[v7 + 1]._unVal.nInteger == -28 )
      return -1;
    if ( *v11 == 0 )
      return -1;
    if ( *(_BYTE *)(v8[v7 + 1]._unVal.nInteger + 29) != 0 )
      return -1;
    v12 = (char)*v11 - 120;
    if ( v12 > 2 )
      return -1;
    nInteger = 0.0;
    if ( v3 >= 3 )
    {
      type = v8[v7 + 2]._type;
      if ( (type & 0x4000000) != 0 )
      {
        if ( type == OT_INTEGER )
          nInteger = (float)v8[v7 + 2]._unVal.nInteger;
        else
          nInteger = v8[v7 + 2]._unVal.fFloat;
      }
    }
    *(float *)(v15 + 4 * v12) = nInteger;
    sq_pushfloat();
    return 0;
  }
  else
  {
    v9 = SQVM::PrintObjVal(this: (SQVM *)v7, o: (const tagSQObject *)hVM);
    ++v9->_uiRef;
    v10 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v10, v9->_val);
    if ( --v9->_uiRef > 0 )
      return -1;
    v9->Release(this: v9);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026EE0
// Name: int VectorIterate(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorIterate(SQVM *hVM)
{
  int stackbase; // ecx
  int v2; // eax
  const char *v3; // ebx
  SQObjectPtr *vals; // eax
  bool v5; // zf
  int v6; // eax
  SQString *v7; // esi
  const char *v8; // eax
  unsigned int v9; // eax

  stackbase = hVM->_stackbase;
  v2 = hVM->_top - stackbase;
  if ( v2 >= 2 && hVM->_stack._vals[stackbase + 1]._type == OT_NULL )
  {
    v3 = "w";
  }
  else
  {
    v3 = nullptr;
    if ( v2 >= 2 )
    {
      vals = hVM->_stack._vals;
      v5 = vals[stackbase + 1]._type == OT_STRING;
      v6 = (int)&vals[stackbase + 1];
      if ( v5 )
      {
        v3 = (const char *)(*(_DWORD *)(v6 + 4) + 28);
      }
      else
      {
        v7 = SQVM::PrintObjVal(this: (SQVM *)stackbase, o: (const tagSQObject *)hVM);
        ++v7->_uiRef;
        v8 = IdType2Name(type: OT_STRING);
        SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v8, v7->_val);
        if ( --v7->_uiRef <= 0 )
          v7->Release(this: v7);
      }
    }
    if ( v3 == nullptr || *v3 == 0 )
      return -1;
  }
  if ( v3[1] != 0 )
    return -1;
  v9 = *v3 - 119;
  if ( v9 > 2 )
    sq_pushnull(v: hVM);
  else
    sq_pushstring(v: hVM, s: results[v9], len: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026FC0
// Name: int VectorToString(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorToString(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  float *v5; // eax
  CFmtStrN<256> *v7; // eax
  float *v8; // [esp+48h] [ebp-110h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(float **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_5:
      sq_throwerror(v: hVM, err: "null vector");
      return -1;
    }
    v5 = v8;
  }
  if ( v5 == nullptr )
    goto LABEL_5;
  v7 = CFmtStrN<256>::CFmtStrN<256>(
         this: (CFmtStrN<256> *)&stru_1009B118,
         pszFormat: (const char *)COERCE_UNSIGNED_INT64(*v5),
         (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*v5)),
         v5[1],
         v5[2]);
  sq_pushstring(v: hVM, s: v7->m_szBuf, len: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027070
// Name: int VectorTypeOf(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorTypeOf(SQVM *hVM)
{
  sq_pushstring(v: hVM, s: "Vector", len: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027090
// Name: int VectorToKeyValueString(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorToKeyValueString(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  float *v5; // eax
  CFmtStrN<256> *v7; // eax
  float *v8; // [esp+48h] [ebp-110h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(float **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_5:
      sq_throwerror(v: hVM, err: "null vector");
      return -1;
    }
    v5 = v8;
  }
  if ( v5 == nullptr )
    goto LABEL_5;
  v7 = CFmtStrN<256>::CFmtStrN<256>(
         this: (CFmtStrN<256> *)&stru_1009B118.m_szBuf[19],
         pszFormat: (const char *)COERCE_UNSIGNED_INT64(*v5),
         (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*v5)),
         v5[1],
         v5[2]);
  sq_pushstring(v: hVM, s: v7->m_szBuf, len: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027140
// Name: int VectorAdd(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorAdd(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  Vector *v5; // eax
  int v6; // eax
  SQObjectPtr *v7; // ecx
  int v8; // eax
  float *p_x; // ebx
  float *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm2_4
  int top; // ecx
  SQObjectPtr *v14; // edx
  SQObjectPtr *v15; // ecx
  tagSQObjectType type; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v19; // esi
  tagSQObjectType v20; // eax
  _DWORD *v21; // ecx
  int v22; // [esp+0h] [ebp-10h]
  Vector *pVectorSrc; // [esp+Ch] [ebp-4h]
  Vector *pVectorSrca; // [esp+Ch] [ebp-4h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(Vector **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
      pVectorSrca = nullptr;
      goto LABEL_7;
    }
    v5 = pVectorSrc;
  }
  pVectorSrca = v5;
LABEL_7:
  v6 = hVM->_stackbase;
  v7 = hVM->_stack._vals;
  v3 = v7[v6 + 1]._type == OT_INSTANCE;
  v8 = (int)&v7[v6 + 1];
  if ( v3 )
  {
    p_x = *(float **)(*(_DWORD *)(v8 + 4) + 32);
  }
  else if ( sq_throwerror(v: hVM, err: "the object is not a class instance") >= 0 )
  {
    p_x = &pVectorSrca->x;
  }
  else
  {
    p_x = nullptr;
  }
  if ( pVectorSrca != nullptr && p_x != nullptr )
  {
    v10 = (float *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
    v11 = p_x[1] + pVectorSrca->y;
    v12 = p_x[2] + pVectorSrca->z;
    *v10 = *p_x + pVectorSrca->x;
    v10[1] = v11;
    v10[2] = v12;
    sq_getclass(v: hVM, idx: -1);
    sq_createinstance(v: hVM, idx: v22);
    top = hVM->_top;
    v14 = hVM->_stack._vals;
    if ( v14[top - 1]._type == OT_INSTANCE )
      *(_DWORD *)(v14[top - 1]._unVal.nInteger + 32) = v10;
    else
      sq_throwerror(v: hVM, err: "the object is not a class instance");
    if ( hVM->_top - hVM->_stackbase >= 1 )
    {
      v15 = &hVM->_stack._vals[hVM->_top - 1];
      type = v15->_type;
      if ( v15->_type == OT_CLASS )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 80) = VectorRelease;
      }
      else if ( type == OT_USERDATA )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 32) = VectorRelease;
      }
      else if ( type == OT_INSTANCE )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 36) = VectorRelease;
      }
    }
    SQVM::Remove(this: hVM, n: -2);
    return 1;
  }
  else
  {
    sharedstate = hVM->_sharedstate;
    v19 = StringTable::Add(this: sharedstate->_stringtable, news: "null vector", len: -1);
    v19->_sharedstate = sharedstate;
    ++v19->_uiRef;
    v20 = hVM->_lasterror._type;
    v21 = &hVM->_lasterror._unVal.pTable->__vftable;
    hVM->_lasterror._unVal.nInteger = (int)v19;
    hVM->_lasterror._type = OT_STRING;
    ++v19->_uiRef;
    if ( (v20 & 0x8000000) != 0 && (int)--v21[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v21 + 8))(a1: v21);
    if ( --v19->_uiRef <= 0 )
      v19->Release(this: v19);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027310
// Name: int VectorSubtract(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorSubtract(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  Vector *v5; // eax
  int v6; // eax
  SQObjectPtr *v7; // ecx
  int v8; // eax
  float *p_x; // ebx
  float *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm2_4
  int top; // ecx
  SQObjectPtr *v14; // edx
  SQObjectPtr *v15; // ecx
  tagSQObjectType type; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v19; // esi
  tagSQObjectType v20; // eax
  _DWORD *v21; // ecx
  int v22; // [esp+0h] [ebp-10h]
  Vector *pVectorSrc; // [esp+Ch] [ebp-4h]
  Vector *pVectorSrca; // [esp+Ch] [ebp-4h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(Vector **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
      pVectorSrca = nullptr;
      goto LABEL_7;
    }
    v5 = pVectorSrc;
  }
  pVectorSrca = v5;
LABEL_7:
  v6 = hVM->_stackbase;
  v7 = hVM->_stack._vals;
  v3 = v7[v6 + 1]._type == OT_INSTANCE;
  v8 = (int)&v7[v6 + 1];
  if ( v3 )
  {
    p_x = *(float **)(*(_DWORD *)(v8 + 4) + 32);
  }
  else if ( sq_throwerror(v: hVM, err: "the object is not a class instance") >= 0 )
  {
    p_x = &pVectorSrca->x;
  }
  else
  {
    p_x = nullptr;
  }
  if ( pVectorSrca != nullptr && p_x != nullptr )
  {
    v10 = (float *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
    v11 = pVectorSrca->y - p_x[1];
    v12 = pVectorSrca->z - p_x[2];
    *v10 = pVectorSrca->x - *p_x;
    v10[1] = v11;
    v10[2] = v12;
    sq_getclass(v: hVM, idx: -1);
    sq_createinstance(v: hVM, idx: v22);
    top = hVM->_top;
    v14 = hVM->_stack._vals;
    if ( v14[top - 1]._type == OT_INSTANCE )
      *(_DWORD *)(v14[top - 1]._unVal.nInteger + 32) = v10;
    else
      sq_throwerror(v: hVM, err: "the object is not a class instance");
    if ( hVM->_top - hVM->_stackbase >= 1 )
    {
      v15 = &hVM->_stack._vals[hVM->_top - 1];
      type = v15->_type;
      if ( v15->_type == OT_CLASS )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 80) = VectorRelease;
      }
      else if ( type == OT_USERDATA )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 32) = VectorRelease;
      }
      else if ( type == OT_INSTANCE )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 36) = VectorRelease;
      }
    }
    SQVM::Remove(this: hVM, n: -2);
    return 1;
  }
  else
  {
    sharedstate = hVM->_sharedstate;
    v19 = StringTable::Add(this: sharedstate->_stringtable, news: "null vector", len: -1);
    v19->_sharedstate = sharedstate;
    ++v19->_uiRef;
    v20 = hVM->_lasterror._type;
    v21 = &hVM->_lasterror._unVal.pTable->__vftable;
    hVM->_lasterror._unVal.nInteger = (int)v19;
    hVM->_lasterror._type = OT_STRING;
    ++v19->_uiRef;
    if ( (v20 & 0x8000000) != 0 && (int)--v21[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v21 + 8))(a1: v21);
    if ( --v19->_uiRef <= 0 )
      v19->Release(this: v19);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100274E0
// Name: int VectorScale(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorScale(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  int v3; // esi
  bool v4; // zf
  SQObjectPtr *v5; // eax
  float *v6; // ebx
  tagSQObjectType type; // ecx
  float nInteger; // xmm0_4
  float *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm2_4
  int top; // eax
  SQObjectPtr *v14; // ecx
  int v15; // eax
  SQObjectPtr *v16; // ecx
  tagSQObjectType v17; // eax
  int v18; // [esp+0h] [ebp-10h]
  float *v19; // [esp+Ch] [ebp-4h]
  float v20; // [esp+Ch] [ebp-4h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = hVM->_top - stackbase;
  v4 = vals[stackbase]._type == OT_INSTANCE;
  v5 = &vals[stackbase];
  if ( v4 )
  {
    v6 = *(float **)(v5->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_5:
      sq_throwerror(v: hVM, err: "null vector");
      return -1;
    }
    v6 = v19;
  }
  if ( v6 == nullptr )
    goto LABEL_5;
  v20 = 0.0;
  if ( v3 >= 2 )
  {
    type = hVM->_stack._vals[hVM->_stackbase + 1]._type;
    if ( (type & 0x4000000) != 0 )
    {
      if ( type == OT_INTEGER )
        nInteger = (float)hVM->_stack._vals[hVM->_stackbase + 1]._unVal.nInteger;
      else
        nInteger = hVM->_stack._vals[hVM->_stackbase + 1]._unVal.fFloat;
      v20 = nInteger;
    }
  }
  v10 = (float *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
  v11 = v6[1] * v20;
  v12 = v6[2] * v20;
  *v10 = *v6 * v20;
  v10[1] = v11;
  v10[2] = v12;
  sq_getclass(v: hVM, idx: -2);
  sq_createinstance(v: hVM, idx: v18);
  top = hVM->_top;
  v14 = hVM->_stack._vals;
  v4 = v14[top - 1]._type == OT_INSTANCE;
  v15 = (int)&v14[top - 1];
  if ( v4 )
    *(_DWORD *)(*(_DWORD *)(v15 + 4) + 32) = v10;
  else
    sq_throwerror(v: hVM, err: "the object is not a class instance");
  if ( hVM->_top - hVM->_stackbase >= 1 )
  {
    v16 = &hVM->_stack._vals[hVM->_top - 1];
    v17 = v16->_type;
    if ( v16->_type == OT_CLASS )
    {
      *(_DWORD *)(v16->_unVal.nInteger + 80) = VectorRelease;
    }
    else if ( v17 == OT_USERDATA )
    {
      *(_DWORD *)(v16->_unVal.nInteger + 32) = VectorRelease;
    }
    else if ( v17 == OT_INSTANCE )
    {
      *(_DWORD *)(v16->_unVal.nInteger + 36) = VectorRelease;
    }
  }
  SQVM::Remove(this: hVM, n: -2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027660
// Name: int VectorLength(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorLength(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  float *v5; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  int top; // eax
  int v11; // ecx
  SQObjectPtr *v12; // eax
  tagSQObjectType type; // edx
  _DWORD *v14; // ecx
  float *v15; // [esp+10h] [ebp-10h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(float **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_5:
      sq_throwerror(v: hVM, err: "null vector");
      return -1;
    }
    v5 = v15;
  }
  if ( v5 == nullptr )
    goto LABEL_5;
  v7 = v5[2];
  v8 = v5[1];
  v9 = *v5;
  top = hVM->_top;
  v11 = top + 1;
  v12 = &hVM->_stack._vals[top];
  hVM->_top = v11;
  type = v12->_type;
  v14 = &v12->_unVal.pTable->__vftable;
  v12->_unVal.fFloat = fsqrt((float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v7 * v7));
  v12->_type = OT_FLOAT;
  if ( (type & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027740
// Name: int VectorLengthSqr(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorLengthSqr(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  float *v5; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  int top; // eax
  int v11; // ecx
  SQObjectPtr *v12; // eax
  tagSQObjectType type; // edx
  _DWORD *v14; // ecx
  float *v15; // [esp+8h] [ebp-8h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(float **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_5:
      sq_throwerror(v: hVM, err: "null vector");
      return -1;
    }
    v5 = v15;
  }
  if ( v5 == nullptr )
    goto LABEL_5;
  v7 = v5[1];
  v8 = *v5;
  v9 = v5[2];
  top = hVM->_top;
  v11 = top + 1;
  v12 = &hVM->_stack._vals[top];
  hVM->_top = v11;
  type = v12->_type;
  v14 = &v12->_unVal.pTable->__vftable;
  v12->_unVal.fFloat = (float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9);
  v12->_type = OT_FLOAT;
  if ( (type & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027800
// Name: int VectorLength2D(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorLength2D(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  float *v5; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  int top; // eax
  int v10; // ecx
  SQObjectPtr *v11; // eax
  tagSQObjectType type; // edx
  _DWORD *v13; // ecx
  float *v14; // [esp+10h] [ebp-10h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(float **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_5:
      sq_throwerror(v: hVM, err: "null vector");
      return -1;
    }
    v5 = v14;
  }
  if ( v5 == nullptr )
    goto LABEL_5;
  v7 = v5[1];
  v8 = *v5;
  top = hVM->_top;
  v10 = top + 1;
  v11 = &hVM->_stack._vals[top];
  hVM->_top = v10;
  type = v11->_type;
  v13 = &v11->_unVal.pTable->__vftable;
  v11->_unVal.fFloat = fsqrt((float)(v8 * v8) + (float)(v7 * v7));
  v11->_type = OT_FLOAT;
  if ( (type & 0x8000000) != 0 && (int)--v13[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100278D0
// Name: int VectorLength2DSqr(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorLength2DSqr(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  float *v5; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  int top; // eax
  int v10; // ecx
  SQObjectPtr *v11; // eax
  tagSQObjectType type; // edx
  _DWORD *v13; // ecx
  float *v14; // [esp+8h] [ebp-8h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(float **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_5:
      sq_throwerror(v: hVM, err: "null vector");
      return -1;
    }
    v5 = v14;
  }
  if ( v5 == nullptr )
    goto LABEL_5;
  v7 = v5[1];
  v8 = *v5;
  top = hVM->_top;
  v10 = top + 1;
  v11 = &hVM->_stack._vals[top];
  hVM->_top = v10;
  type = v11->_type;
  v13 = &v11->_unVal.pTable->__vftable;
  v11->_unVal.fFloat = (float)(v8 * v8) + (float)(v7 * v7);
  v11->_type = OT_FLOAT;
  if ( (type & 0x8000000) != 0 && (int)--v13[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027980
// Name: int VectorCross(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorCross(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  Vector *v5; // eax
  int v6; // eax
  SQObjectPtr *v7; // ecx
  int v8; // eax
  float *p_x; // ebx
  float *v10; // esi
  float v11; // xmm3_4
  float v12; // xmm0_4
  int top; // ecx
  SQObjectPtr *v14; // edx
  SQObjectPtr *v15; // ecx
  tagSQObjectType type; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v19; // esi
  tagSQObjectType v20; // eax
  _DWORD *v21; // ecx
  int v22; // [esp+0h] [ebp-10h]
  Vector *pVectorSrc; // [esp+Ch] [ebp-4h]
  Vector *pVectorSrca; // [esp+Ch] [ebp-4h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(Vector **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
      pVectorSrca = nullptr;
      goto LABEL_7;
    }
    v5 = pVectorSrc;
  }
  pVectorSrca = v5;
LABEL_7:
  v6 = hVM->_stackbase;
  v7 = hVM->_stack._vals;
  v3 = v7[v6 + 1]._type == OT_INSTANCE;
  v8 = (int)&v7[v6 + 1];
  if ( v3 )
  {
    p_x = *(float **)(*(_DWORD *)(v8 + 4) + 32);
  }
  else if ( sq_throwerror(v: hVM, err: "the object is not a class instance") >= 0 )
  {
    p_x = &pVectorSrca->x;
  }
  else
  {
    p_x = nullptr;
  }
  if ( pVectorSrca != nullptr && p_x != nullptr )
  {
    v10 = (float *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
    v11 = (float)(*p_x * pVectorSrca->z) - (float)(pVectorSrca->x * p_x[2]);
    v12 = (float)(pVectorSrca->x * p_x[1]) - (float)(*p_x * pVectorSrca->y);
    *v10 = (float)(pVectorSrca->y * p_x[2]) - (float)(pVectorSrca->z * p_x[1]);
    v10[1] = v11;
    v10[2] = v12;
    sq_getclass(v: hVM, idx: -1);
    sq_createinstance(v: hVM, idx: v22);
    top = hVM->_top;
    v14 = hVM->_stack._vals;
    if ( v14[top - 1]._type == OT_INSTANCE )
      *(_DWORD *)(v14[top - 1]._unVal.nInteger + 32) = v10;
    else
      sq_throwerror(v: hVM, err: "the object is not a class instance");
    if ( hVM->_top - hVM->_stackbase >= 1 )
    {
      v15 = &hVM->_stack._vals[hVM->_top - 1];
      type = v15->_type;
      if ( v15->_type == OT_CLASS )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 80) = VectorRelease;
      }
      else if ( type == OT_USERDATA )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 32) = VectorRelease;
      }
      else if ( type == OT_INSTANCE )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 36) = VectorRelease;
      }
    }
    SQVM::Remove(this: hVM, n: -2);
    return 1;
  }
  else
  {
    sharedstate = hVM->_sharedstate;
    v19 = StringTable::Add(this: sharedstate->_stringtable, news: "null vector", len: -1);
    v19->_sharedstate = sharedstate;
    ++v19->_uiRef;
    v20 = hVM->_lasterror._type;
    v21 = &hVM->_lasterror._unVal.pTable->__vftable;
    hVM->_lasterror._unVal.nInteger = (int)v19;
    hVM->_lasterror._type = OT_STRING;
    ++v19->_uiRef;
    if ( (v20 & 0x8000000) != 0 && (int)--v21[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v21 + 8))(a1: v21);
    if ( --v19->_uiRef <= 0 )
      v19->Release(this: v19);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027B80
// Name: int VectorDot(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorDot(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  float *v5; // esi
  int v6; // eax
  SQObjectPtr *v7; // ecx
  int v8; // eax
  float *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  int top; // eax
  float v13; // xmm1_4
  int v14; // ecx
  SQObjectPtr *v15; // eax
  tagSQObjectType type; // edx
  _DWORD *v17; // ecx
  SQSharedState *sharedstate; // ebx
  SQString *v20; // esi
  tagSQObjectType v21; // eax
  _DWORD *v22; // ecx
  float *v23; // [esp+10h] [ebp-8h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(float **)(v4->_unVal.nInteger + 32);
  }
  else if ( sq_throwerror(v: hVM, err: "the object is not a class instance") >= 0 )
  {
    v5 = v23;
  }
  else
  {
    v5 = nullptr;
  }
  v6 = hVM->_stackbase;
  v7 = hVM->_stack._vals;
  v3 = v7[v6 + 1]._type == OT_INSTANCE;
  v8 = (int)&v7[v6 + 1];
  if ( v3 )
  {
    v9 = *(float **)(*(_DWORD *)(v8 + 4) + 32);
  }
  else if ( sq_throwerror(v: hVM, err: "the object is not a class instance") >= 0 )
  {
    v9 = v23;
  }
  else
  {
    v9 = nullptr;
  }
  if ( v5 != nullptr && v9 != nullptr )
  {
    v10 = (float)(v9[1] * v5[1]) + (float)(*v9 * *v5);
    v11 = v9[2];
    top = hVM->_top;
    v13 = v11 * v5[2];
    v14 = top + 1;
    v15 = &hVM->_stack._vals[top];
    hVM->_top = v14;
    type = v15->_type;
    v17 = &v15->_unVal.pTable->__vftable;
    v15->_unVal.fFloat = v10 + v13;
    v15->_type = OT_FLOAT;
    if ( (type & 0x8000000) != 0 && (int)--v17[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v17 + 8))(a1: v17);
    return 1;
  }
  else
  {
    sharedstate = hVM->_sharedstate;
    v20 = StringTable::Add(this: sharedstate->_stringtable, news: "null vector", len: -1);
    v20->_sharedstate = sharedstate;
    ++v20->_uiRef;
    v21 = hVM->_lasterror._type;
    v22 = &hVM->_lasterror._unVal.pTable->__vftable;
    hVM->_lasterror._unVal.nInteger = (int)v20;
    hVM->_lasterror._type = OT_STRING;
    ++v20->_uiRef;
    if ( (v21 & 0x8000000) != 0 && (int)--v22[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v22 + 8))(a1: v22);
    if ( --v20->_uiRef <= 0 )
      v20->Release(this: v20);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027CE0
// Name: int VectorNorm(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorNorm(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  Vector *v5; // eax
  int top; // eax
  int v8; // ecx
  SQObjectPtr *v9; // eax
  tagSQObjectType type; // edx
  _DWORD *v11; // ecx
  Vector *vec; // [esp+8h] [ebp-8h]
  float v13; // [esp+Ch] [ebp-4h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(Vector **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_5:
      sq_throwerror(v: hVM, err: "null vector");
      return -1;
    }
    v5 = vec;
  }
  if ( v5 == nullptr )
    goto LABEL_5;
  v13 = VectorNormalize(vec: v5);
  top = hVM->_top;
  v8 = top + 1;
  v9 = &hVM->_stack._vals[top];
  hVM->_top = v8;
  type = v9->_type;
  v11 = &v9->_unVal.pTable->__vftable;
  v9->_unVal.fFloat = v13;
  v9->_type = OT_FLOAT;
  if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027D90
// Name: bool RegisterVector(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall RegisterVector@<al>(SQVM *hVM@<eax>)
{
  int v2; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v4; // ecx
  tagSQObjectType type; // ebx
  int v6; // esi
  SQObjectPtr *v7; // eax
  tagSQObjectType v8; // edx
  SQObjectPtr *v10; // ecx
  int v11; // eax
  tagSQObjectType v12; // ebx
  tagSQObjectValue v13; // edx
  int v14; // eax
  SQObjectPtr *v15; // ecx
  tagSQObjectType v16; // esi
  unsigned int i; // ebx
  int v18; // eax
  SQObjectPtr *v19; // ecx
  tagSQObjectType v20; // esi
  const char *v21; // [esp+0h] [ebp-18h]
  unsigned int hClass_4; // [esp+10h] [ebp-8h]
  int top; // [esp+14h] [ebp-4h]

  v2 = hVM->_top;
  vals = hVM->_stack._vals;
  hVM->_top = v2 + 1;
  v4 = &vals[v2]._unVal.pTable->__vftable;
  type = vals[v2]._type;
  v6 = v2 - hVM->_stackbase;
  v7 = &vals[v2];
  v7->_unVal.nInteger = hVM->_roottable._unVal.nInteger;
  v8 = hVM->_roottable._type;
  top = v6;
  v7->_type = v8;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(v7->_unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  sq_pushstring(v: hVM, s: "Vector", len: -1);
  if ( sq_newclass(v: hVM, hasbase: 0) >= 0 )
  {
    v10 = hVM->_stack._vals;
    v11 = hVM->_top;
    v12 = v10[v11 - 1]._type;
    v13.pTable = (SQTable *)v10[v11 - 1]._unVal;
    hClass_4 = v13.nInteger;
    if ( v12 == OT_CLASS )
    {
      *(_DWORD *)(v13.nInteger + 76) = 1;
    }
    else if ( v12 == OT_USERDATA )
    {
      *(_DWORD *)(v13.nInteger + 36) = 1;
    }
    else
    {
      sq_throwerror(v: hVM, err: "invalid object type");
    }
    v14 = hVM->_top;
    if ( v14 - hVM->_stackbase >= 3 )
    {
      v15 = hVM->_stack._vals;
      v16 = v15[v14 - 3]._type;
      if ( v16 == OT_TABLE || v16 == OT_CLASS )
      {
        if ( v15[v14 - 2]._type == OT_NULL )
        {
          sq_throwerror(v: hVM, err: "null is not a valid key");
        }
        else
        {
          SQVM::NewSlot(this: (SQVM *)v15, self: &v15[v14 - 3], key: &v15[v14 - 2], val: &v15[v14 - 1], bstatic: false);
          SQVM::Pop(this: hVM, n: 2);
        }
      }
    }
    else
    {
      SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v21);
    }
    sq_pushobject(v: hVM, obj: (tagSQObject)__PAIR64__(hClass_4, v12));
    for ( i = 0; i < 0x120; i += 16 )
    {
      sq_pushstring(v: hVM, s: g_VectorFuncs[i / 0x10].name, len: -1);
      sq_newclosure(v: hVM, func: *(int (__cdecl **)(SQVM *))((char *)&off_100A6FBC + i), nfreevars: 0);
      if ( dword_100A6FC0[i / 4] != 0 )
        sq_setparamscheck(v: hVM, nparamscheck: dword_100A6FC0[i / 4], typemask: (const char *)dword_100A6FC4[i / 4]);
      sq_setnativeclosurename(v: hVM, idx: (int)v21, name: g_VectorFuncs[i / 0x10].name);
      v18 = hVM->_top;
      if ( v18 - hVM->_stackbase >= 3 )
      {
        v19 = hVM->_stack._vals;
        v20 = v19[v18 - 3]._type;
        if ( v20 == OT_TABLE || v20 == OT_CLASS )
        {
          if ( v19[v18 - 2]._type == OT_NULL )
          {
            sq_throwerror(v: hVM, err: "null is not a valid key");
          }
          else
          {
            SQVM::NewSlot(
              this: (SQVM *)v19,
              self: &v19[v18 - 3],
              key: &v19[v18 - 2],
              val: &v19[v18 - 1],
              bstatic: false);
            SQVM::Pop(this: hVM, n: 2);
          }
        }
      }
      else
      {
        SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v21);
      }
    }
    SQVM::Pop(this: hVM, n: 1);
    sq_settop(v: hVM, newtop: top);
    return 1;
  }
  else
  {
    sq_settop(v: hVM, newtop: v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027FD0
// Name: public: CSquirrelVM::CSquirrelVM(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
CSquirrelVM *__usercall CSquirrelVM::CSquirrelVM@<eax>(CSquirrelVM *this@<ecx>, int a2@<esi>)
{
  CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *v2; // ecx
  int v3; // ecx
  _DWORD *v4; // ecx
  int v5; // eax
  tagSQObjectType type; // edx

  *(_DWORD *)a2 = &CSquirrelVM::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 36) = 16777217;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  ConVarRef::ConVarRef(this: (ConVarRef *)(a2 + 60), pName: &stru_1009B118.m_szBuf[31]);
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 128) = -1;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 120) = 0;
  *(_DWORD *)(a2 + 132) = 0;
  CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Purge(this: v2);
  *(_DWORD *)(a2 + 140) = CDefOps<void *>::LessFunc;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 152) = 0;
  v3 = *(_DWORD *)(a2 + 144);
  *(_DWORD *)(a2 + 156) = 0xFFFF;
  *(_DWORD *)(a2 + 160) = -1;
  *(_DWORD *)(a2 + 164) = v3;
  *(SQObjectPtr *)(a2 + 12) = _null_;
  *(SQObjectPtr *)(a2 + 20) = _null_;
  *(SQObjectPtr *)(a2 + 28) = _null_;
  v4 = *(_DWORD **)(a2 + 40);
  v5 = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(a2 + 40) = _null_._unVal.pTable;
  type = _null_._type;
  *(_DWORD *)(a2 + 36) = _null_._type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a2 + 40) + 4);
  if ( (v5 & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  return (CSquirrelVM *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100280F0
// Name: public: virtual bool CSquirrelVM::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSquirrelVM::Init(CSquirrelVM *this)
{
  SQVM *v2; // eax
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v6; // edi
  tagSQObjectType type; // esi
  SQObjectPtr *v8; // edx
  _DWORD *v9; // ecx
  tagSQObjectType v10; // eax
  SQVM *v11; // edi
  SQVM *v12; // eax
  int v13; // ecx
  SQObjectPtr *v14; // edx
  tagSQObjectValue v15; // edi
  tagSQObjectType v16; // esi
  SQObjectPtr *v17; // edx
  _DWORD *v18; // ecx
  tagSQObjectType v19; // eax
  SQVM *v20; // edi
  int v21; // eax
  SQVM *v22; // ecx
  int v23; // esi
  SQVM *v24; // edi
  int v25; // eax
  SQVM *v26; // ecx
  int v27; // esi
  CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *v28; // ecx
  SQVM *v29; // eax
  int v30; // ecx
  SQObjectPtr *v31; // edx
  tagSQObjectValue v32; // edi
  tagSQObjectType v33; // esi
  SQObjectPtr *v34; // edx
  _DWORD *v35; // ecx
  tagSQObjectType v36; // eax
  SQVM *v37; // esi
  SQVM *v38; // ecx
  SQObjectPtr *v39; // edx
  int v40; // esi
  tagSQObjectType v41; // edi
  RefTable::RefNode *v42; // eax
  tagSQObjectType v43; // eax
  tagSQObjectType v44; // eax
  SQObjectPtr *v46; // [esp-10h] [ebp-28h]
  int v47; // [esp+0h] [ebp-18h]
  int v48; // [esp+0h] [ebp-18h]
  const char *v49; // [esp+0h] [ebp-18h]
  const char *v50; // [esp+0h] [ebp-18h]
  RefTable::RefNode *prev; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int mainpos[2]; // [esp+10h] [ebp-8h] BYREF

  v2 = sq_open(initialstacksize: v47);
  this->m_hVM = v2;
  v2->_sharedstate->m_pOwnerData = this;
  this->m_hVM->_qs_fn = CSquirrelVM::QueryContinue;
  this->m_hVM->_sharedstate->_printfunc = CSquirrelVM::PrintFunc;
  m_hVM = this->m_hVM;
  top = m_hVM->_top;
  m_hVM->_top = top + 1;
  vals = m_hVM->_stack._vals;
  v6.pTable = (SQTable *)m_hVM->_roottable._unVal;
  type = vals[top]._type;
  v8 = &vals[top];
  v9 = &v8->_unVal.pTable->__vftable;
  v8->_unVal = v6;
  v10 = m_hVM->_roottable._type;
  v8->_type = v10;
  if ( (v10 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  sqstd_register_mathlib(v: this->m_hVM);
  sqstd_register_stringlib(v: this->m_hVM);
  v11 = this->m_hVM;
  v11->_sharedstate->_compilererrorhandler = _sqstd_compiler_error;
  sq_newclosure(v: v11, func: sqstd_aux_printerror, nfreevars: 0);
  sq_seterrorhandler(v: v11);
  SQVM::Pop(this: this->m_hVM, n: 1);
  if ( this->developer.m_pConVarState->m_Value.m_nValue > 0 )
    this->m_hVM->_sharedstate->_debuginfo = true;
  v12 = this->m_hVM;
  v13 = v12->_top;
  v12->_top = v13 + 1;
  v14 = v12->_stack._vals;
  v15.pTable = (SQTable *)v12->_roottable._unVal;
  v16 = v14[v13]._type;
  v17 = &v14[v13];
  v18 = &v17->_unVal.pTable->__vftable;
  v17->_unVal = v15;
  v19 = v12->_roottable._type;
  v17->_type = v19;
  if ( (v19 & 0x8000000) != 0 )
    ++*(_DWORD *)(v15.nInteger + 4);
  if ( (v16 & 0x8000000) != 0 && (int)--v18[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v18 + 8))(a1: v18);
  sq_pushstring(v: this->m_hVM, s: &stru_1009B118.m_szBuf[31], len: -1);
  sq_newclosure(v: this->m_hVM, func: CSquirrelVM::GetDeveloper, nfreevars: 0);
  sq_setnativeclosurename(v: this->m_hVM, idx: v48, name: &stru_1009B118.m_szBuf[31]);
  v20 = this->m_hVM;
  v21 = v20->_top;
  if ( v21 - v20->_stackbase >= 3 )
  {
    v22 = (SQVM *)v20->_stack._vals;
    v23 = *((_DWORD *)v22 + 2 * v21 - 6);
    if ( v23 == 167772192 || v23 == 134234112 )
    {
      if ( *((_DWORD *)v22 + 2 * v21 - 4) == 16777217 )
      {
        sq_throwerror(v: v20, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: v22,
          self: (const SQObjectPtr *)v22 + v21 - 3,
          key: (const SQObjectPtr *)v22 + v21 - 2,
          val: (const SQObjectPtr *)v22 + v21 - 1,
          bstatic: false);
        SQVM::Pop(this: v20, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v49);
  }
  sq_pushstring(v: this->m_hVM, s: &stru_1009B118.m_szBuf[43], len: -1);
  sq_newclosure(v: this->m_hVM, func: CSquirrelVM::GetFunctionSignature, nfreevars: 0);
  sq_setnativeclosurename(v: this->m_hVM, idx: (int)v49, name: &stru_1009B118.m_szBuf[43]);
  v24 = this->m_hVM;
  v25 = v24->_top;
  if ( v25 - v24->_stackbase >= 3 )
  {
    v26 = (SQVM *)v24->_stack._vals;
    v27 = *((_DWORD *)v26 + 2 * v25 - 6);
    if ( v27 == 167772192 || v27 == 134234112 )
    {
      if ( *((_DWORD *)v26 + 2 * v25 - 4) == 16777217 )
      {
        sq_throwerror(v: v24, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: v26,
          self: (const SQObjectPtr *)v26 + v25 - 3,
          key: (const SQObjectPtr *)v26 + v25 - 2,
          val: (const SQObjectPtr *)v26 + v25 - 1,
          bstatic: false);
        SQVM::Pop(this: v24, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v50);
  }
  SQVM::Pop(this: this->m_hVM, n: 1);
  CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Init(this: v28, nBucketCount: (int)v50);
  RegisterVector(hVM: this->m_hVM);
  v29 = this->m_hVM;
  v30 = v29->_top;
  v29->_top = v30 + 1;
  v31 = v29->_stack._vals;
  v32.pTable = (SQTable *)v29->_roottable._unVal;
  v33 = v31[v30]._type;
  v34 = &v31[v30];
  v35 = &v34->_unVal.pTable->__vftable;
  v34->_unVal = v32;
  v36 = v29->_roottable._type;
  v34->_type = v36;
  if ( (v36 & 0x8000000) != 0 )
    ++*(_DWORD *)(v32.nInteger + 4);
  if ( (v33 & 0x8000000) != 0 && (int)--v35[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v35 + 8))(a1: v35);
  sq_pushstring(v: this->m_hVM, s: "Vector", len: -1);
  v37 = this->m_hVM;
  v46 = &v37->_stack._vals[v37->_top - 1];
  if ( !SQVM::Get(this: v37, self: &v37->_stack._vals[v37->_top - 2], key: v46, dest: v46, raw: false, fetchroot: false) )
  {
    SQVM::Pop(this: v37, n: 1);
    sq_throwerror(v: v37, err: "the index doesn't exist");
  }
  v38 = this->m_hVM;
  v39 = v38->_stack._vals;
  v40 = v38->_top;
  v41 = v39[v40 - 1]._type;
  this->m_hClassVector._type = v41;
  this->m_hClassVector._unVal.nInteger = v39[v40 - 1]._unVal.nInteger;
  if ( (v41 & 0x8000000) != 0 )
  {
    v42 = RefTable::Get(this: &v38->_sharedstate->_refs_table, obj: &this->m_hClassVector, mainpos, &prev, add: true);
    ++v42->refs;
  }
  SQVM::Pop(this: this->m_hVM, n: 2);
  this->Run_3(this, a2: (const char *)g_Script_init, a3: true);
  v43 = CSquirrelVM::LookupObject(
          this,
          pszObject: (const char *)mainpos,
          hScope: nullptr,
          bAddRef: (bool)&stru_1009B118.m_szBuf[67])._type;
  this->m_hOnCreateScopeFunc._type = *(_DWORD *)v43;
  this->m_hOnCreateScopeFunc._unVal.nInteger = *(_DWORD *)(v43 + 4);
  v44 = CSquirrelVM::LookupObject(
          this,
          pszObject: (const char *)mainpos,
          hScope: nullptr,
          bAddRef: (bool)&stru_1009B118.m_szBuf[91])._type;
  this->m_hOnReleaseScopeFunc._type = *(_DWORD *)v44;
  this->m_hOnReleaseScopeFunc._unVal.nInteger = *(_DWORD *)(v44 + 4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100284C0
// Name: public: virtual bool CSquirrelVM::Frame(float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSquirrelVM::Frame(CSquirrelVM *this, float simTime)
{
  SQDbgServer *m_hDbg; // eax
  struct timeval timeout; // [esp+8h] [ebp-110h] BYREF
  fd_set readfds; // [esp+10h] [ebp-108h] BYREF

  m_hDbg = this->m_hDbg;
  if ( m_hDbg != nullptr )
  {
    sq_rdbg_update(rdbg: m_hDbg);
    if ( this->m_hDbg->_endpoint == -1 )
    {
LABEL_5:
      this->DisconnectDebugger(this);
      return false;
    }
    readfds.fd_array[0] = this->m_hDbg->_endpoint;
    readfds.fd_count = 1;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    if ( select(nfds: 0, &readfds, writefds: nullptr, exceptfds: nullptr, &timeout) == -1 )
    {
      DevMsg(a1: "Script debugger disconnected\n");
      goto LABEL_5;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10028540
// Name: public: virtual void CSquirrelVM::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSquirrelVM::Shutdown(CSquirrelVM *this@<ecx>, SQVM *a2@<esi>)
{
  SQVM *m_hVM; // eax
  SQVM *v4; // eax
  int top; // ecx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // edx
  tagSQObjectType *p_type; // eax
  _DWORD *v9; // ecx
  tagSQObjectType v10; // esi
  SQSharedState *sharedstate; // esi
  SQSharedState *v12; // ecx

  m_hVM = this->m_hVM;
  if ( m_hVM != nullptr )
  {
    if ( m_hVM->_sharedstate->_gc_disableDepth <= 0 )
      SQSharedState::CollectGarbage((SQSharedState *)this, tchain: a2);
    v4 = this->m_hVM;
    top = v4->_top;
    v4->_top = top + 1;
    vals = v4->_stack._vals;
    type = vals[top]._type;
    p_type = &vals[top]._type;
    v9 = *((_DWORD **)p_type + 1);
    p_type[1] = (tagSQObjectType)_null_._unVal.pTable;
    v10 = _null_._type;
    *p_type = _null_._type;
    if ( (v10 & 0x8000000) != 0 )
      ++*(_DWORD *)(*((_DWORD *)p_type + 1) + 4);
    if ( (type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
    sq_setroottable(v: this->m_hVM);
    this->DisconnectDebugger(this);
    sharedstate = this->m_hVM->_sharedstate;
    sharedstate->_root_vm._unVal.pTable->Finalize(this: (struct SQTable *)sharedstate->_root_vm._unVal.nInteger);
    SQSharedState::~SQSharedState(this: v12);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sharedstate);
    this->m_hVM = nullptr;
  }
  CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Purge((CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10028600
// Name: public: virtual enum ScriptLanguage_t CSquirrelVM::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSquirrelVM::GetLanguage(CSquirrelVM *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10028610
// Name: public: virtual char const __near * CSquirrelVM::GetLanguageName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSquirrelVM::GetLanguageName(CSquirrelVM *this)
{
  return &stru_1009B118.m_szBuf[119];
}

//------------------------------------------------------------------------------
// Address: 0x10028620
// Name: public: virtual bool CSquirrelVM::ConnectDebugger(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSquirrelVM::ConnectDebugger(CSquirrelVM *this)
{
  SQDbgServer *m_hDbg; // esi
  unsigned __int16 v4; // [esp+0h] [ebp-8h]
  unsigned int v5; // [esp+4h] [ebp-4h]

  if ( this->developer.m_pConVarState->m_Value.m_nValue <= 0 )
    return false;
  if ( this->m_hDbg == nullptr )
    this->m_hDbg = sq_rdbg_init(v: this->m_hVM, port: v4, autoupdate: v5);
  m_hDbg = this->m_hDbg;
  return m_hDbg != nullptr && sq_rdbg_waitforconnections(rdbg: m_hDbg) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10028670
// Name: public: virtual void CSquirrelVM::DisconnectDebugger(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::DisconnectDebugger(CSquirrelVM *this)
{
  SQDbgServer *m_hDbg; // esi

  m_hDbg = this->m_hDbg;
  if ( m_hDbg != nullptr )
  {
    SQDbgServer::~SQDbgServer((SQDbgServer *)this);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_hDbg);
    WSACleanup();
    this->m_hDbg = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100286A0
// Name: public: virtual enum ScriptStatus_t CSquirrelVM::Run(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSquirrelVM::Run(CSquirrelVM *this, const char *pszScript, bool bWait)
{
  int v4; // eax
  SQVM *m_hVM; // ecx
  SQVM *v6; // eax
  int v7; // ecx
  tagSQObjectType v8; // edx
  tagSQObjectValue v9; // ecx
  RefTable::RefNode *v10; // eax
  ScriptStatus_t v11; // esi
  unsigned int v13; // [esp+0h] [ebp-20h]
  RefTable::RefNode *prev; // [esp+Ch] [ebp-14h] BYREF
  unsigned int mainpos; // [esp+10h] [ebp-10h] BYREF
  tagSQObject hScript; // [esp+14h] [ebp-Ch] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v4 = _V_strlen(str: pszScript);
  m_hVM = this->m_hVM;
  v17 = v4;
  hScript._type = (tagSQObjectType)pszScript;
  hScript._unVal.nInteger = 0;
  if ( sq_compile(
         v: m_hVM,
         read: (int (__cdecl *)(void *))&hScript,
         p: &stru_1009B118.m_szBuf[131],
         sourcename: (const char *)1,
         raiseerror: v13) < 0 )
    return -1;
  v6 = this->m_hVM;
  v7 = (int)&v6->_stack._vals[v6->_top - 1];
  v8 = *(_DWORD *)v7;
  v9.pTable = *(SQTable **)(v7 + 4);
  hScript._type = v8;
  hScript._unVal = v9;
  if ( (v8 & 0x8000000) != 0 )
  {
    v10 = RefTable::Get(this: &v6->_sharedstate->_refs_table, obj: &hScript, &mainpos, &prev, add: true);
    ++v10->refs;
  }
  SQVM::Pop(this: this->m_hVM, n: 1);
  v11 = CSquirrelVM::ExecuteFunction(
          this,
          hFunction: (HSCRIPT__ *)&hScript,
          pArgs: nullptr,
          nArgs: 0,
          pReturn: nullptr,
          hScope: nullptr,
          bWait);
  if ( (hScript._type & 0x8000000) != 0 )
    RefTable::Release(this: (RefTable *)&hScript, obj: &hScript);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10028790
// Name: public: virtual struct HSCRIPT__ __near * CSquirrelVM::CompileScript(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
tagSQObject *__thiscall CSquirrelVM::CompileScript(CSquirrelVM *this, const char *pszScript, char *pszId)
{
  const char *v3; // edi
  char *v5; // ebx
  int v6; // eax
  SQVM *m_hVM; // ecx
  tagSQObject *v8; // edi
  SQVM *v9; // eax
  SQObjectPtr *vals; // ecx
  int top; // eax
  tagSQObjectType type; // edx
  RefTable::RefNode *v13; // eax
  unsigned int v15; // [esp-8h] [ebp-1Ch]
  _DWORD v16[3]; // [esp+8h] [ebp-Ch] BYREF

  v3 = pszScript;
  if ( pszScript == nullptr || *pszScript == 0 )
    return nullptr;
  v5 = pszId;
  if ( pszId == nullptr )
    v5 = &stru_1009B118.m_szBuf[131];
  v6 = _V_strlen(str: pszScript);
  m_hVM = this->m_hVM;
  v16[2] = v6;
  v16[0] = v3;
  v16[1] = 0;
  if ( sq_compile(v: m_hVM, read: (int (__cdecl *)(void *))v16, p: v5, sourcename: (const char *)1, raiseerror: v15) < 0 )
    return nullptr;
  v8 = (tagSQObject *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8);
  v9 = this->m_hVM;
  vals = v9->_stack._vals;
  top = v9->_top;
  type = vals[top - 1]._type;
  v8->_type = type;
  v8->_unVal.nInteger = vals[top - 1]._unVal.nInteger;
  if ( (type & 0x8000000) != 0 )
  {
    v13 = RefTable::Get(
            this: &this->m_hVM->_sharedstate->_refs_table,
            obj: v8,
            mainpos: (unsigned int *)&pszId,
            prev: (RefTable::RefNode **)&pszScript,
            add: true);
    ++v13->refs;
  }
  SQVM::Pop(this: this->m_hVM, n: 1);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10028860
// Name: public: virtual void CSquirrelVM::ReleaseFunction(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::ReleaseFunction(CSquirrelVM *this, HSCRIPT__ *hScript)
{
  if ( hScript != nullptr )
  {
    if ( (*(_DWORD *)hScript & 0x8000000) != 0 )
      RefTable::Release((RefTable *)this, obj: (tagSQObject *)hScript);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hScript);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100288A0
// Name: public: virtual enum ScriptStatus_t CSquirrelVM::Run(struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
ScriptStatus_t __thiscall CSquirrelVM::Run(CSquirrelVM *this, HSCRIPT__ *hScript, HSCRIPT__ *hScope, bool bWait)
{
  return CSquirrelVM::ExecuteFunction(
           this,
           hFunction: hScript,
           pArgs: nullptr,
           nArgs: 0,
           pReturn: nullptr,
           hScope,
           bWait);
}

//------------------------------------------------------------------------------
// Address: 0x100288C0
// Name: public: virtual enum ScriptStatus_t CSquirrelVM::Run(struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
ScriptStatus_t __thiscall CSquirrelVM::Run(CSquirrelVM *this, HSCRIPT__ *hScript, bool bWait)
{
  return CSquirrelVM::ExecuteFunction(
           this,
           hFunction: hScript,
           pArgs: nullptr,
           nArgs: 0,
           pReturn: nullptr,
           hScope: nullptr,
           bWait);
}

//------------------------------------------------------------------------------
// Address: 0x100288E0
// Name: public: virtual struct HSCRIPT__ __near * CSquirrelVM::CreateScope(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CSquirrelVM::CreateScope(CSquirrelVM *this, const char *pszScope, SQObjectPtr *hParent)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v7; // ebx
  tagSQObjectType type; // esi
  SQObjectPtr *v9; // edx
  _DWORD *v10; // ecx
  tagSQObjectType v11; // eax
  int v12; // eax
  SQVM *v13; // esi
  int v14; // eax
  SQObjectPtr *v15; // ecx
  tagSQObjectType v16; // ebx
  int v17; // eax
  HSCRIPT__ *result; // eax
  RefTable::RefNode *v19; // eax
  tagSQObjectValue v20; // ecx
  RefTable::RefNode *prev; // [esp+10h] [ebp-10h] BYREF
  unsigned int mainpos; // [esp+14h] [ebp-Ch] BYREF
  tagSQObject v23; // [esp+18h] [ebp-8h] BYREF

  if ( hParent == nullptr )
    hParent = &this->m_hVM->_roottable;
  sq_pushobject(v: this->m_hVM, obj: this->m_hOnCreateScopeFunc);
  m_hVM = this->m_hVM;
  top = m_hVM->_top;
  m_hVM->_top = top + 1;
  vals = m_hVM->_stack._vals;
  v7.pTable = (SQTable *)m_hVM->_roottable._unVal;
  type = vals[top]._type;
  v9 = &vals[top];
  v10 = &v9->_unVal.pTable->__vftable;
  v9->_unVal = v7;
  v11 = m_hVM->_roottable._type;
  v9->_type = v11;
  if ( (v11 & 0x8000000) != 0 )
    ++*(_DWORD *)(v7.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  sq_pushstring(v: this->m_hVM, s: pszScope, len: -1);
  sq_pushobject(v: this->m_hVM, obj: hParent->tagSQObject);
  v12 = sq_call(v: this->m_hVM, params: 3, retval: 1u, raiseerror: 1u);
  v13 = this->m_hVM;
  if ( v12 != 0 )
  {
    v16 = _null_._type;
    v23._unVal.nInteger = _null_._unVal.nInteger;
    v17 = 1;
  }
  else
  {
    v14 = v13->_top;
    v15 = v13->_stack._vals;
    v16 = v15[v14 - 1]._type;
    v23._unVal.nInteger = v15[v14 - 1]._unVal.nInteger;
    v17 = 2;
  }
  v23._type = v16;
  SQVM::Pop(this: v13, n: v17);
  if ( v16 == OT_NULL )
    return nullptr;
  if ( (v16 & 0x8000000) != 0 )
  {
    v19 = RefTable::Get(this: &this->m_hVM->_sharedstate->_refs_table, obj: &v23, &mainpos, &prev, add: true);
    ++v19->refs;
  }
  result = (HSCRIPT__ *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8);
  v20.pTable = (SQTable *)v23._unVal;
  *(_DWORD *)result = v16;
  result[1] = (HSCRIPT__)v20.pTable;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028A40
// Name: public: virtual void CSquirrelVM::ReleaseScope(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::ReleaseScope(CSquirrelVM *this, tagSQObject *hScript)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v6; // ebx
  tagSQObjectType type; // esi
  SQObjectPtr *v8; // edx
  _DWORD *v9; // ecx
  tagSQObjectType v10; // eax
  SQVM *v11; // esi
  int v12; // eax
  int *pTable; // ecx
  RefTable *v14; // ecx
  SQObjectPtr *v15; // [esp-14h] [ebp-2Ch]
  SQObjectPtr outres; // [esp+10h] [ebp-8h] BYREF

  sq_pushobject(v: this->m_hVM, obj: this->m_hOnReleaseScopeFunc);
  m_hVM = this->m_hVM;
  top = m_hVM->_top;
  m_hVM->_top = top + 1;
  vals = m_hVM->_stack._vals;
  v6.pTable = (SQTable *)m_hVM->_roottable._unVal;
  type = vals[top]._type;
  v8 = &vals[top];
  v9 = &v8->_unVal.pTable->__vftable;
  v8->_unVal = v6;
  v10 = m_hVM->_roottable._type;
  v8->_type = v10;
  if ( (v10 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  sq_pushobject(v: this->m_hVM, obj: *hScript);
  v11 = this->m_hVM;
  v12 = v11->_top;
  v15 = &v11->_stack._vals[v12 - 3];
  outres._type = OT_NULL;
  outres._unVal.nInteger = 0;
  if ( !SQVM::Call(this: v11, closure: v15, nparams: 2, stackbase: v12 - 2, &outres, raiseerror: 1u)
    || v11->_suspended == 0 )
  {
    SQVM::Pop(this: v11, n: 2);
  }
  if ( (outres._type & 0x8000000) != 0 )
  {
    pTable = (int *)outres._unVal.pTable;
    --*(_DWORD *)(outres._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  SQVM::Pop(this: this->m_hVM, n: 1);
  if ( (hScript->_type & 0x8000000) != 0 )
    RefTable::Release(this: v14, obj: hScript);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hScript);
}

//------------------------------------------------------------------------------
// Address: 0x10028B70
// Name: public: struct tagSQObject CSquirrelVM::LookupObject(char const __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char *__userpurge CSquirrelVM::LookupObject@<eax>(
        HSCRIPT__ *hScope@<eax>,
        CSquirrelVM *this,
        tagSQObjectValue *pszObject,
        const char *bAddRef,
        bool bAddRefa)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v8; // edi
  tagSQObjectType type; // esi
  SQObjectPtr *v10; // edx
  _DWORD *v11; // ecx
  tagSQObjectType v12; // eax
  SQVM *v13; // esi
  SQVM *v14; // eax
  int v15; // ecx
  SQObjectPtr *v16; // edx
  tagSQObjectType v17; // edi
  tagSQObjectValue v18; // ecx
  RefTable::RefNode *v19; // eax
  tagSQObjectValue v21; // edx
  SQObjectPtr *v22; // [esp-10h] [ebp-30h]
  RefTable::RefNode *prev; // [esp+10h] [ebp-10h] BYREF
  unsigned int mainpos; // [esp+14h] [ebp-Ch] BYREF
  tagSQObject v25; // [esp+18h] [ebp-8h] BYREF

  v25._type = OT_NULL;
  v25._unVal.nInteger = 0;
  if ( hScope != nullptr )
  {
    if ( hScope == (HSCRIPT__ *)-1
      || *(_DWORD *)hScope == -1 && *((_DWORD *)hScope + 1) == -1
      || *(_DWORD *)hScope != 167772192 )
    {
      *(SQObjectPtr *)&pszObject->pTable = _null_;
      return (char *)pszObject;
    }
    sq_pushobject(v: this->m_hVM, obj: *(tagSQObject *)hScope);
  }
  else
  {
    m_hVM = this->m_hVM;
    top = m_hVM->_top;
    m_hVM->_top = top + 1;
    vals = m_hVM->_stack._vals;
    v8.pTable = (SQTable *)m_hVM->_roottable._unVal;
    type = vals[top]._type;
    v10 = &vals[top];
    v11 = &v10->_unVal.pTable->__vftable;
    v10->_unVal = v8;
    v12 = m_hVM->_roottable._type;
    v10->_type = v12;
    if ( (v12 & 0x8000000) != 0 )
      ++*(_DWORD *)(v8.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  }
  sq_pushstring(v: this->m_hVM, s: bAddRef, len: -1);
  v13 = this->m_hVM;
  v22 = &v13->_stack._vals[v13->_top - 1];
  if ( !SQVM::Get(this: v13, self: &v13->_stack._vals[v13->_top - 2], key: v22, dest: v22, raw: false, fetchroot: false)
    && (SQVM::Pop(this: v13, n: 1), sq_throwerror(v: v13, err: "the index doesn't exist") != 0) )
  {
    v17 = v25._type;
  }
  else
  {
    v14 = this->m_hVM;
    v15 = v14->_top;
    v16 = v14->_stack._vals;
    v17 = v16[v15 - 1]._type;
    v18.pTable = (SQTable *)v16[v15 - 1]._unVal;
    v25._type = v17;
    v25._unVal = v18;
    if ( bAddRefa && (v17 & 0x8000000) != 0 )
    {
      v19 = RefTable::Get(this: &v14->_sharedstate->_refs_table, obj: &v25, &mainpos, &prev, add: true);
      ++v19->refs;
    }
    SQVM::Pop(this: this->m_hVM, n: 1);
  }
  SQVM::Pop(this: this->m_hVM, n: 1);
  v21.pTable = (SQTable *)v25._unVal;
  pszObject->nInteger = v17;
  pszObject[1].pTable = v21.pTable;
  return (char *)pszObject;
}

//------------------------------------------------------------------------------
// Address: 0x10028D10
// Name: public: virtual struct HSCRIPT__ __near * CSquirrelVM::LookupFunction(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CSquirrelVM::LookupFunction(CSquirrelVM *this, const char *pszFunction, HSCRIPT__ *hScope)
{
  RefTable *v3; // ecx
  HSCRIPT__ *result; // eax
  tagSQObjectValue v5; // ecx
  tagSQObject v6; // [esp+8h] [ebp-8h] BYREF

  CSquirrelVM::LookupObject(hScope, this, pszObject: (tagSQObjectValue *)&v6, bAddRef: pszFunction, bAddRefa: true);
  if ( v6._type != OT_NULL )
  {
    if ( v6._type == OT_CLOSURE )
    {
      result = (HSCRIPT__ *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8);
      v5.pTable = (SQTable *)v6._unVal;
      *(_DWORD *)result = 134217984;
      result[1] = (HSCRIPT__)v5.pTable;
      return result;
    }
    if ( (v6._type & 0x8000000) != 0 )
      RefTable::Release(this: v3, obj: &v6);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10028D90
// Name: public: virtual enum ScriptStatus_t CSquirrelVM::ExecuteFunction(struct HSCRIPT__ __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSquirrelVM::ExecuteFunction(
        CSquirrelVM *this,
        HSCRIPT__ *hFunction,
        ScriptVariant_t *pArgs,
        int nArgs,
        ScriptVariant_t *pReturn,
        HSCRIPT__ *hScope,
        bool bWait)
{
  SQVM *m_hVM; // ecx
  int v10; // edi
  ScriptVariant_t *v12; // edi
  int v13; // eax
  int v14; // eax
  tagSQObjectType type; // eax
  const char *v16; // eax
  _DWORD *v17; // ecx
  tagSQObjectType v18; // eax
  tagSQObjectType v19; // edx
  tagSQObject v20; // [esp-8h] [ebp-18h]
  bool v21; // [esp+0h] [ebp-10h]
  int initialTop; // [esp+Ch] [ebp-4h]

  if ( hScope == (HSCRIPT__ *)-1 )
  {
    DevWarning(a1: &stru_1009B118.m_szBuf[139]);
    return -1;
  }
  if ( this->m_hDbg != nullptr && g_bSqDbgTerminateScript )
  {
    this->DisconnectDebugger(this);
    g_bSqDbgTerminateScript = false;
  }
  if ( hFunction == nullptr )
  {
    v12 = pReturn;
LABEL_36:
    if ( v12 != nullptr )
      v12->m_type = 0;
    return -1;
  }
  m_hVM = this->m_hVM;
  initialTop = m_hVM->_top;
  sq_pushobject(v: m_hVM, obj: *(tagSQObject *)hFunction);
  if ( hScope != nullptr )
  {
    if ( *(_DWORD *)hScope == -1 && *((_DWORD *)hScope + 1) == -1 || *(_DWORD *)hScope != 167772192 )
    {
      SQVM::Pop(this: this->m_hVM, n: 1);
      return -1;
    }
    v20._unVal.pTable = (SQTable *)hScope[1];
    v20._type = OT_TABLE;
    sq_pushobject(v: this->m_hVM, obj: v20);
  }
  else
  {
    sq_pushroottable(v: this->m_hVM);
  }
  v10 = nArgs;
  if ( nArgs > 0 )
  {
    do
    {
      CSquirrelVM::PushVariant(this, value: pArgs++, bCopy: v21);
      --v10;
    }
    while ( v10 != 0 );
  }
  this->m_TimeStartExecute = _Plat_FloatTime();
  v12 = pReturn;
  v13 = sq_call(v: this->m_hVM, params: nArgs + 1, retval: pReturn != nullptr, raiseerror: 1u);
  this->m_TimeStartExecute = 0.0;
  if ( v13 < 0 )
  {
    SQVM::Pop(this: this->m_hVM, n: 1);
    goto LABEL_36;
  }
  if ( pReturn != nullptr )
  {
    if ( !CSquirrelVM::ConvertToVariant(
            this,
            object: this->m_hVM->_stack._vals[this->m_hVM->_top - 1].tagSQObject,
            pReturn) )
      DevMsg(a1: &stru_1009B118.m_szBuf[175]);
    v14 = 2;
  }
  else
  {
    v14 = 1;
  }
  SQVM::Pop(this: this->m_hVM, n: v14);
  if ( this->m_hVM->_top != initialTop )
    _Warning(a1: &stru_1009B118.m_szBuf[219]);
  type = this->m_ErrorString._type;
  if ( type == OT_NULL )
    return 0;
  if ( type == OT_STRING )
    v16 = (const char *)(this->m_ErrorString._unVal.nInteger + 28);
  else
    v16 = "Internal error";
  sq_throwerror(v: this->m_hVM, err: v16);
  v17 = &this->m_ErrorString._unVal.pTable->__vftable;
  v18 = this->m_ErrorString._type;
  this->m_ErrorString._unVal.nInteger = _null_._unVal.nInteger;
  v19 = _null_._type;
  this->m_ErrorString._type = _null_._type;
  if ( (v19 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->m_ErrorString._unVal.nInteger + 4);
  if ( (v18 & 0x8000000) != 0 && (int)--v17[1] <= 0 )
  {
    (*(void (__thiscall **)(_DWORD *))(*v17 + 8))(a1: v17);
    return -1;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10028FA0
// Name: public: virtual void CSquirrelVM::RegisterFunction(struct ScriptFunctionBinding_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::RegisterFunction(CSquirrelVM *this, ScriptFunctionBinding_t *pScriptFunction)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  tagSQObjectValue v5; // ebx
  SQObjectPtr *v6; // edx
  CSquirrelVM *pTable; // ecx
  tagSQObjectType type; // eax
  tagSQObjectType v9; // edi

  m_hVM = this->m_hVM;
  top = m_hVM->_top;
  m_hVM->_top = top + 1;
  v5.pTable = (SQTable *)m_hVM->_roottable._unVal;
  v6 = &m_hVM->_stack._vals[top];
  pTable = (CSquirrelVM *)v6->_unVal.pTable;
  v6->_unVal = v5;
  type = m_hVM->_roottable._type;
  v9 = v6->_type;
  v6->_type = type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(v5.nInteger + 4);
  if ( (v9 & 0x8000000) != 0 && (int)--pTable->m_hVM <= 0 )
    pTable->ConnectDebugger(this: pTable);
  CSquirrelVM::RegisterFunctionGuts(
    this: pTable,
    pScriptFunction: (ScriptFunctionBinding_t *)this,
    pClassDesc: (ScriptClassDesc_t *)pScriptFunction);
  SQVM::Pop(this: this->m_hVM, n: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10029010
// Name: public: virtual bool CSquirrelVM::RegisterClass(struct ScriptClassDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSquirrelVM::RegisterClass(CSquirrelVM *this, ScriptClassDesc_t *pClassDesc)
{
  SQVM *m_hVM; // eax
  int v4; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v6; // edi
  tagSQObjectType type; // esi
  SQObjectPtr *v8; // edx
  _DWORD *v9; // ecx
  tagSQObjectType v10; // eax
  SQVM *v11; // esi
  SQObjectPtr *v12; // edx
  CSquirrelVM *v14; // ecx
  CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *v15; // esi
  int v16; // edi
  unsigned int *v17; // eax
  unsigned int v18; // ecx
  tagSQObjectValue v19; // edx
  CSquirrelVM *v20; // ecx
  int v21; // edi
  SQObjectPtr *v22; // [esp-10h] [ebp-3Ch]
  unsigned int v23; // [esp+0h] [ebp-2Ch]
  unsigned int v24; // [esp+0h] [ebp-2Ch]
  unsigned int v25; // [esp+0h] [ebp-2Ch]
  unsigned int v26; // [esp+0h] [ebp-2Ch]
  tagSQObject newClass; // [esp+10h] [ebp-1Ch] BYREF
  CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *p_m_TypeMap; // [esp+18h] [ebp-14h]
  int top; // [esp+1Ch] [ebp-10h]
  unsigned int v30; // [esp+24h] [ebp-8h]

  p_m_TypeMap = &this->m_TypeMap;
  if ( CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Find(
         this: (CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *)pClassDesc,
         uiKey: v23) == -1 )
  {
    m_hVM = this->m_hVM;
    v4 = m_hVM->_top;
    m_hVM->_top = v4 + 1;
    vals = m_hVM->_stack._vals;
    v6.pTable = (SQTable *)m_hVM->_roottable._unVal;
    type = vals[v4]._type;
    v8 = &vals[v4];
    v9 = &v8->_unVal.pTable->__vftable;
    v8->_unVal = v6;
    v10 = m_hVM->_roottable._type;
    v8->_type = v10;
    if ( (v10 & 0x8000000) != 0 )
      ++*(_DWORD *)(v6.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
    sq_pushstring(v: this->m_hVM, s: pClassDesc->m_pszScriptName, len: -1);
    v11 = this->m_hVM;
    v12 = v11->_stack._vals;
    v22 = &v12[v11->_top - 1];
    if ( SQVM::Get(this: v11, self: &v12[v11->_top - 2], key: v22, dest: v22, raw: false, fetchroot: false)
      || (SQVM::Pop(this: v11, n: 1), sq_throwerror(v: v11, err: "the index doesn't exist") == 0) )
    {
      SQVM::Pop(this: this->m_hVM, n: 2);
      return 0;
    }
    SQVM::Pop(this: this->m_hVM, n: 1);
    v15 = (CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *)pClassDesc;
    if ( pClassDesc->m_pBaseDesc != nullptr )
      CSquirrelVM::RegisterClass(this, pClassDesc: pClassDesc->m_pBaseDesc);
    v16 = this->m_hVM->_top - this->m_hVM->_stackbase;
    top = v16;
    v17 = (unsigned int *)CSquirrelVM::CreateClass(this: v14, pDesc: (ScriptClassDesc_t *)this)._type;
    v18 = *v17;
    v19.nInteger = v17[1];
    newClass._unVal = v19;
    if ( v18 != -1 || v19.nInteger != -1 )
    {
      sq_pushobject(v: this->m_hVM, obj: (tagSQObject)__PAIR64__(v19.raw, v18));
      if ( pClassDesc->m_pfnConstruct != nullptr )
      {
        sq_pushstring(v: this->m_hVM, s: "constructor", len: -1);
        *(_DWORD *)sq_newuserdata(v: this->m_hVM, size: v24) = pClassDesc;
        sq_newclosure(v: this->m_hVM, func: CSquirrelVM::CallConstructor, nfreevars: 1u);
        sq_newslot(v: this->m_hVM, idx: -3, bstatic: v25);
      }
      sq_pushstring(v: this->m_hVM, s: "_tostring", len: -1);
      sq_newclosure(v: this->m_hVM, func: CSquirrelVM::InstanceToString, nfreevars: 0);
      sq_newslot(v: this->m_hVM, idx: -3, bstatic: v24);
      sq_pushstring(v: this->m_hVM, s: "IsValid", len: -1);
      sq_newclosure(v: this->m_hVM, func: CSquirrelVM::InstanceIsValid, nfreevars: 0);
      sq_newslot(v: this->m_hVM, idx: -3, bstatic: v26);
      v21 = 0;
      if ( pClassDesc->m_FunctionBindings.m_Size > 0 )
      {
        v30 = 0;
        do
        {
          CSquirrelVM::RegisterFunctionGuts(
            this: v20,
            pScriptFunction: (ScriptFunctionBinding_t *)this,
            pClassDesc: (ScriptClassDesc_t *)&pClassDesc->m_FunctionBindings.m_Memory.m_pMemory[v30 / 0x30]);
          v30 += 48;
          ++v21;
        }
        while ( v21 < pClassDesc->m_FunctionBindings.m_Size );
      }
      SQVM::Pop(this: this->m_hVM, n: 1);
      v15 = (CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *)pClassDesc;
      v16 = top;
    }
    sq_settop(v: this->m_hVM, newtop: v16);
    if ( CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Find(this: v15, uiKey: v24) == -1 )
      CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::FastInsert(
        this: p_m_TypeMap,
        uiKey: (unsigned int)pClassDesc,
        data: (SQClass *const *)&newClass._unVal);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029250
// Name: public: bool CSquirrelVM::CreateNativeInstance(struct ScriptClassDesc_t __near *,void __near *,int (*)(void __near *,int))
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSquirrelVM::CreateNativeInstance@<al>(
        CSquirrelVM *this@<ecx>,
        CSquirrelVM *pDesc,
        void *ud,
        int (__cdecl *hook)(void *, int))
{
  _DWORD *v4; // esi
  int v5; // eax
  SQVM *m_hVM; // esi
  SQVM *v8; // edi
  int top; // eax
  SQObjectPtr *vals; // ecx
  bool v11; // zf
  int v12; // eax
  const char *v13; // ebx
  int *v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+0h] [ebp-10h]
  int v17; // [esp+0h] [ebp-10h]

  v4 = *(_DWORD **)(CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Find(
                      (CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *)this,
                      uiKey: v16)
                  + 4);
  ++v4[1];
  sq_pushobject(v: pDesc->m_hVM, obj: (tagSQObject)__PAIR64__((unsigned int)v4, 134234112));
  if ( (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  v5 = sq_createinstance(v: pDesc->m_hVM, idx: v17);
  m_hVM = pDesc->m_hVM;
  if ( v5 < 0 )
  {
    SQVM::Pop(this: m_hVM, n: 1);
    return 0;
  }
  SQVM::Remove(this: m_hVM, n: -2);
  v8 = pDesc->m_hVM;
  top = v8->_top;
  vals = v8->_stack._vals;
  v11 = vals[top - 1]._type == OT_INSTANCE;
  v12 = (int)&vals[top - 1];
  if ( v11 )
  {
    *(_DWORD *)(*(_DWORD *)(v12 + 4) + 32) = ud;
  }
  else if ( sq_throwerror(v: v8, err: "the object is not a class instance") < 0 )
  {
    return 0;
  }
  v13 = (const char *)pDesc->m_hVM;
  if ( *((_DWORD *)v13 + 14) - *((_DWORD *)v13 + 15) >= 1 )
  {
    v14 = (int *)(*((_DWORD *)v13 + 8) + 8 * *((_DWORD *)v13 + 14) - 8);
    v15 = *v14;
    if ( *v14 == 134234112 )
    {
      *(_DWORD *)(v14[1] + 80) = CSquirrelVM::ExternalInstanceReleaseHook;
    }
    else
    {
      if ( v15 == 167772288 )
      {
        *(_DWORD *)(v14[1] + 32) = CSquirrelVM::ExternalInstanceReleaseHook;
        return 1;
      }
      if ( v15 == 167804928 )
      {
        *(_DWORD *)(v14[1] + 36) = CSquirrelVM::ExternalInstanceReleaseHook;
        return 1;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029360
// Name: public: virtual struct HSCRIPT__ __near * CSquirrelVM::RegisterInstance(struct ScriptClassDesc_t __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CSquirrelVM::RegisterInstance(CSquirrelVM *this, ScriptClassDesc_t *pDesc, void *pInstance)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // ecx
  int v7; // edx
  tagSQObjectType type; // eax
  CSquirrelVM::InstanceContext_t *v9; // ecx
  HSCRIPT__ *result; // eax
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectType v14; // edi
  tagSQObjectValue v15; // ebx
  RefTable::RefNode *v16; // eax
  int (__cdecl *v17)(void *, int); // [esp+0h] [ebp-20h]
  unsigned int v18; // [esp+0h] [ebp-20h]
  RefTable::RefNode *prev; // [esp+10h] [ebp-10h] BYREF
  unsigned int mainpos; // [esp+14h] [ebp-Ch] BYREF
  tagSQObject hObject; // [esp+18h] [ebp-8h] BYREF

  if ( CSquirrelVM::RegisterClass(this, pClassDesc: pDesc) == 0 )
    return nullptr;
  v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[3] = 0;
    v4[2] = 16777217;
    v5 = v4;
  }
  *v5 = pInstance;
  v5[1] = pDesc;
  v6 = (_DWORD *)v5[3];
  v7 = v5[2];
  v5[3] = _null_._unVal.pTable;
  type = _null_._type;
  v5[2] = _null_._type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(v5[3] + 4);
  if ( (v7 & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  if ( CSquirrelVM::CreateNativeInstance(this: (CSquirrelVM *)pDesc, pDesc: this, ud: v5, hook: v17) == 0 )
  {
    CSquirrelVM::InstanceContext_t::`scalar deleting destructor'(this: v9, a2: v18);
    return nullptr;
  }
  m_hVM = this->m_hVM;
  top = m_hVM->_top;
  vals = m_hVM->_stack._vals;
  v14 = vals[top - 1]._type;
  v15.pTable = (SQTable *)vals[top - 1]._unVal;
  hObject._type = v14;
  hObject._unVal = v15;
  if ( (v14 & 0x8000000) != 0 )
  {
    v16 = RefTable::Get(this: &m_hVM->_sharedstate->_refs_table, obj: &hObject, &mainpos, &prev, add: true);
    ++v16->refs;
  }
  SQVM::Pop(this: this->m_hVM, n: 1);
  result = (HSCRIPT__ *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8);
  *(_DWORD *)result = v14;
  result[1] = (HSCRIPT__)v15.pTable;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029480
// Name: public: virtual void CSquirrelVM::SetInstanceUniqeId(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::SetInstanceUniqeId(CSquirrelVM *this, HSCRIPT__ *hInstance, const char *pszId)
{
  SQSharedState *sharedstate; // edi
  SQString *v4; // esi
  int v5; // eax
  int v6; // edx
  _DWORD *v7; // ecx

  if ( hInstance != nullptr )
  {
    if ( *(_DWORD *)hInstance == 167804928 )
    {
      sharedstate = this->m_hVM->_sharedstate;
      v4 = StringTable::Add(this: sharedstate->_stringtable, news: pszId, len: -1);
      v4->_sharedstate = sharedstate;
      ++v4->_uiRef;
      v5 = *(_DWORD *)(*((_DWORD *)hInstance + 1) + 32);
      v6 = *(_DWORD *)(v5 + 8);
      v7 = *(_DWORD **)(v5 + 12);
      *(_DWORD *)(v5 + 12) = v4;
      *(_DWORD *)(v5 + 8) = 134217744;
      ++v4->_uiRef;
      if ( (v6 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
      if ( --v4->_uiRef <= 0 )
        v4->Release(this: v4);
    }
  }
  else if ( `CSquirrelVM::SetInstanceUniqeId'::`6'::__executeCount < 1 )
  {
    ++`CSquirrelVM::SetInstanceUniqeId'::`6'::__executeCount;
    DevMsg(a1: "NULL instance passed to vscript!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029530
// Name: public: virtual void CSquirrelVM::RemoveInstance(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::RemoveInstance(CSquirrelVM *this, HSCRIPT__ *hInstance)
{
  if ( hInstance != nullptr )
  {
    if ( *(_DWORD *)hInstance == 167804928 )
      **(_DWORD **)(*((_DWORD *)hInstance + 1) + 32) = 0;
    if ( (*(_DWORD *)hInstance & 0x8000000) != 0 )
      RefTable::Release((RefTable *)this, obj: (tagSQObject *)hInstance);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hInstance);
  }
  else if ( `CSquirrelVM::RemoveInstance'::`6'::__executeCount < 1 )
  {
    ++`CSquirrelVM::RemoveInstance'::`6'::__executeCount;
    DevMsg(a1: "NULL instance passed to vscript!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100295B0
// Name: public: virtual void __near * CSquirrelVM::GetInstanceValue(struct HSCRIPT__ __near *,struct ScriptClassDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall CSquirrelVM::GetInstanceValue(
        CSquirrelVM *this,
        HSCRIPT__ *hInstance,
        ScriptClassDesc_t *pExpectedType)
{
  ScriptClassDesc_t *result; // eax
  _DWORD *v4; // edx
  ScriptClassDesc_t *v5; // eax

  if ( hInstance == nullptr )
  {
    if ( `CSquirrelVM::GetInstanceValue'::`6'::__executeCount < 1 )
    {
      ++`CSquirrelVM::GetInstanceValue'::`6'::__executeCount;
      DevMsg(a1: "NULL instance passed to vscript!\n");
    }
    return nullptr;
  }
  if ( *(_DWORD *)hInstance != 167804928 )
    return nullptr;
  v4 = *(_DWORD **)(*((_DWORD *)hInstance + 1) + 32);
  if ( v4 == nullptr )
    return nullptr;
  if ( pExpectedType != nullptr )
  {
    v5 = (ScriptClassDesc_t *)v4[1];
    if ( v5 != pExpectedType )
    {
      result = v5->m_pBaseDesc;
      if ( result == nullptr )
        return nullptr;
      while ( result != pExpectedType )
      {
        result = result->m_pBaseDesc;
        if ( result == nullptr )
          return result;
      }
    }
  }
  return (ScriptClassDesc_t *)*v4;
}

//------------------------------------------------------------------------------
// Address: 0x10029620
// Name: public: virtual bool CSquirrelVM::GenerateUniqueKey(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSquirrelVM::GenerateUniqueKey(CSquirrelVM *this, const char *pszRoot, char *pBuf, int nBufSize)
{
  unsigned int m_iUniqueIdSerialNumber; // edx
  unsigned int m_iUniqueIdSerialNumber_high; // edi
  int v7; // eax
  int v9; // [esp-14h] [ebp-1Ch]
  __int64 v10; // [esp-10h] [ebp-18h]
  const char *v11; // [esp-8h] [ebp-10h]

  if ( _V_strlen(str: pszRoot) + 41 > nBufSize )
  {
    _Error(a1: "GenerateUniqueKey: buffer too small");
    if ( nBufSize != 0 )
      *pBuf = 0;
    return 0;
  }
  else
  {
    m_iUniqueIdSerialNumber = this->m_iUniqueIdSerialNumber;
    m_iUniqueIdSerialNumber_high = HIDWORD(this->m_iUniqueIdSerialNumber);
    this->m_iUniqueIdSerialNumber = __PAIR64__(m_iUniqueIdSerialNumber_high, m_iUniqueIdSerialNumber) + 1;
    v9 = _Plat_MSTime(a1: m_iUniqueIdSerialNumber, a2: m_iUniqueIdSerialNumber_high, a3: pszRoot);
    v7 = _RandomInt(a1: 0, a2: 4095);
    V_snprintf(pDest: pBuf, maxLen: nBufSize, pFormat: "%x%x%llx_%s", v7, v9, v10, v11);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100296B0
// Name: public: virtual bool CSquirrelVM::ValueExists(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSquirrelVM::ValueExists(CSquirrelVM *this, HSCRIPT__ *hScope, const char *pszKey)
{
  tagSQObjectValue pszObject[2]; // [esp+0h] [ebp-8h] BYREF

  return *(_DWORD *)CSquirrelVM::LookupObject(hScope, this, pszObject, bAddRef: pszKey, bAddRefa: false) != 16777217;
}

//------------------------------------------------------------------------------
// Address: 0x100296E0
// Name: public: virtual bool CSquirrelVM::SetValue(struct HSCRIPT__ __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSquirrelVM::SetValue(CSquirrelVM *this, HSCRIPT__ *hScope, const char *pszKey, const char *pszValue)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v8; // edi
  tagSQObjectType type; // esi
  SQObjectPtr *v10; // edx
  _DWORD *v11; // ecx
  tagSQObjectType v12; // eax
  SQVM *v13; // edi
  int v14; // eax
  SQVM *v16; // ecx
  int v17; // esi
  const char *v18; // [esp+0h] [ebp-10h]

  if ( hScope != nullptr )
  {
    if ( hScope == (HSCRIPT__ *)-1
      || *(_DWORD *)hScope == -1 && *((_DWORD *)hScope + 1) == -1
      || *(_DWORD *)hScope != 167772192 )
    {
      return 0;
    }
    sq_pushobject(v: this->m_hVM, obj: *(tagSQObject *)hScope);
  }
  else
  {
    m_hVM = this->m_hVM;
    top = m_hVM->_top;
    m_hVM->_top = top + 1;
    vals = m_hVM->_stack._vals;
    v8.pTable = (SQTable *)m_hVM->_roottable._unVal;
    type = vals[top]._type;
    v10 = &vals[top];
    v11 = &v10->_unVal.pTable->__vftable;
    v10->_unVal = v8;
    v12 = m_hVM->_roottable._type;
    v10->_type = v12;
    if ( (v12 & 0x8000000) != 0 )
      ++*(_DWORD *)(v8.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  }
  sq_pushstring(v: this->m_hVM, s: pszKey, len: -1);
  sq_pushstring(v: this->m_hVM, s: pszValue, len: -1);
  v13 = this->m_hVM;
  v14 = v13->_top;
  if ( v14 - v13->_stackbase < 3 )
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v18);
    SQVM::Pop(this: this->m_hVM, n: 1);
    return 1;
  }
  v16 = (SQVM *)v13->_stack._vals;
  v17 = *((_DWORD *)v16 + 2 * v14 - 6);
  if ( v17 == 167772192 || v17 == 134234112 )
  {
    if ( *((_DWORD *)v16 + 2 * v14 - 4) == 16777217 )
    {
      sq_throwerror(v: v13, err: "null is not a valid key");
      SQVM::Pop(this: this->m_hVM, n: 1);
      return 1;
    }
    SQVM::NewSlot(
      this: v16,
      self: (const SQObjectPtr *)v16 + v14 - 3,
      key: (const SQObjectPtr *)v16 + v14 - 2,
      val: (const SQObjectPtr *)v16 + v14 - 1,
      bstatic: false);
    SQVM::Pop(this: v13, n: 2);
  }
  SQVM::Pop(this: this->m_hVM, n: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029860
// Name: public: virtual bool CSquirrelVM::SetValue(struct HSCRIPT__ __near *,char const __near *,struct ScriptVariant_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSquirrelVM::SetValue(
        CSquirrelVM *this,
        HSCRIPT__ *hScope,
        const char *pszKey,
        const ScriptVariant_t *value)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v8; // edi
  tagSQObjectType type; // esi
  SQObjectPtr *v10; // edx
  _DWORD *v11; // ecx
  tagSQObjectType v12; // eax
  int *m_int; // eax
  int v14; // ecx
  int v15; // eax
  SQObjectPtr *v16; // esi
  SQVM *v17; // edi
  int v18; // eax
  SQVM *v20; // ecx
  int v21; // esi
  bool v22; // [esp+0h] [ebp-10h]
  const char *v23; // [esp+0h] [ebp-10h]

  if ( hScope != nullptr )
  {
    if ( hScope == (HSCRIPT__ *)-1
      || *(_DWORD *)hScope == -1 && *((_DWORD *)hScope + 1) == -1
      || *(_DWORD *)hScope != 167772192 )
    {
      return 0;
    }
    sq_pushobject(v: this->m_hVM, obj: *(tagSQObject *)hScope);
  }
  else
  {
    m_hVM = this->m_hVM;
    top = m_hVM->_top;
    m_hVM->_top = top + 1;
    vals = m_hVM->_stack._vals;
    v8.pTable = (SQTable *)m_hVM->_roottable._unVal;
    type = vals[top]._type;
    v10 = &vals[top];
    v11 = &v10->_unVal.pTable->__vftable;
    v10->_unVal = v8;
    v12 = m_hVM->_roottable._type;
    v10->_type = v12;
    if ( (v12 & 0x8000000) != 0 )
      ++*(_DWORD *)(v8.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  }
  sq_pushstring(v: this->m_hVM, s: pszKey, len: -1);
  if ( value->m_type == 33 )
  {
    m_int = (int *)value->m_int;
    if ( value->m_int != 0 )
    {
      v14 = *m_int;
      v15 = m_int[1];
      if ( v14 == 167804928 && *(_DWORD *)(*(_DWORD *)(v15 + 28) + 76) >= 2u )
      {
        v16 = (SQObjectPtr *)(*(_DWORD *)(v15 + 32) + 8);
        if ( v16->_type == OT_NULL )
          SQObjectPtr::operator=(this: v16, obj: &this->m_hVM->_stack._vals[this->m_hVM->_top - 1]);
      }
    }
  }
  CSquirrelVM::PushVariant(this, value, bCopy: v22);
  v17 = this->m_hVM;
  v18 = v17->_top;
  if ( v18 - v17->_stackbase < 3 )
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v23);
    SQVM::Pop(this: this->m_hVM, n: 1);
    return 1;
  }
  v20 = (SQVM *)v17->_stack._vals;
  v21 = *((_DWORD *)v20 + 2 * v18 - 6);
  if ( v21 == 167772192 || v21 == 134234112 )
  {
    if ( *((_DWORD *)v20 + 2 * v18 - 4) == 16777217 )
    {
      sq_throwerror(v: v17, err: "null is not a valid key");
      SQVM::Pop(this: this->m_hVM, n: 1);
      return 1;
    }
    SQVM::NewSlot(
      this: v20,
      self: (const SQObjectPtr *)v20 + v18 - 3,
      key: (const SQObjectPtr *)v20 + v18 - 2,
      val: (const SQObjectPtr *)v20 + v18 - 1,
      bstatic: false);
    SQVM::Pop(this: v17, n: 2);
  }
  SQVM::Pop(this: this->m_hVM, n: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029A20
// Name: public: virtual void CSquirrelVM::CreateTable(struct ScriptVariant_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::CreateTable(CSquirrelVM *this, ScriptVariant_t *Table)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectType type; // esi
  tagSQObjectValue v7; // ebx
  RefTable::RefNode *v8; // eax
  RefTable::RefNode *prev; // [esp+10h] [ebp-10h] BYREF
  unsigned int mainpos; // [esp+14h] [ebp-Ch] BYREF
  tagSQObject hObject; // [esp+18h] [ebp-8h] BYREF

  sq_newtable(v: this->m_hVM);
  m_hVM = this->m_hVM;
  top = m_hVM->_top;
  vals = m_hVM->_stack._vals;
  type = vals[top - 1]._type;
  v7.pTable = (SQTable *)vals[top - 1]._unVal;
  hObject._type = type;
  hObject._unVal = v7;
  if ( (type & 0x8000000) != 0 )
  {
    v8 = RefTable::Get(this: &m_hVM->_sharedstate->_refs_table, obj: &hObject, &mainpos, &prev, add: true);
    ++v8->refs;
  }
  CSquirrelVM::ConvertToVariant(this, object: (tagSQObject)__PAIR64__(v7.raw, type), pReturn: Table);
  SQVM::Pop(this: this->m_hVM, n: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10029AB0
// Name: public: virtual int CSquirrelVM::GetNumTableEntries(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSquirrelVM::GetNumTableEntries(CSquirrelVM *this, HSCRIPT__ *hScope)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v6; // edi
  tagSQObjectType type; // esi
  SQObjectPtr *v8; // edx
  _DWORD *v9; // ecx
  tagSQObjectType v10; // eax
  SQVM *v11; // edi
  int v12; // ecx
  tagSQObjectType v13; // eax
  int v14; // edi

  if ( hScope == nullptr )
  {
    m_hVM = this->m_hVM;
    top = m_hVM->_top;
    m_hVM->_top = top + 1;
    vals = m_hVM->_stack._vals;
    v6.pTable = (SQTable *)m_hVM->_roottable._unVal;
    type = vals[top]._type;
    v8 = &vals[top];
    v9 = &v8->_unVal.pTable->__vftable;
    v8->_unVal = v6;
    v10 = m_hVM->_roottable._type;
    v8->_type = v10;
    if ( (v10 & 0x8000000) != 0 )
      ++*(_DWORD *)(v6.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
LABEL_12:
    v11 = this->m_hVM;
    v12 = (int)&v11->_stack._vals[v11->_top - 1];
    v13 = *(_DWORD *)v12;
    if ( *(int *)v12 > 167772192 )
    {
      if ( v13 == OT_USERDATA )
        goto LABEL_16;
    }
    else
    {
      if ( *(_DWORD *)v12 == 167772192 )
      {
        v14 = *(_DWORD *)(*(_DWORD *)(v12 + 4) + 40);
        goto LABEL_17;
      }
      if ( v13 == OT_STRING )
      {
        v14 = *(_DWORD *)(*(_DWORD *)(v12 + 4) + 20);
        goto LABEL_17;
      }
      if ( v13 == OT_ARRAY )
      {
LABEL_16:
        v14 = *(_DWORD *)(*(_DWORD *)(v12 + 4) + 28);
LABEL_17:
        SQVM::Pop(this: this->m_hVM, n: 1);
        return v14;
      }
    }
    v14 = sq_aux_invalidtype(v: v11, type: *(tagSQObjectType *)v12);
    goto LABEL_17;
  }
  if ( hScope != (HSCRIPT__ *)-1
    && (*(_DWORD *)hScope != -1 || *((_DWORD *)hScope + 1) != -1)
    && *(_DWORD *)hScope == 167772192 )
  {
    sq_pushobject(v: this->m_hVM, obj: *(tagSQObject *)hScope);
    goto LABEL_12;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10029BB0
// Name: public: virtual int CSquirrelVM::GetKeyValue(struct HSCRIPT__ __near *,int,struct ScriptVariant_t __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSquirrelVM::GetKeyValue(
        CSquirrelVM *this,
        HSCRIPT__ *hScope,
        int nIterator,
        ScriptVariant_t *pKey,
        ScriptVariant_t *pValue)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v9; // ebx
  tagSQObjectType type; // esi
  SQObjectPtr *v11; // edx
  _DWORD *v12; // ecx
  tagSQObjectType v13; // eax
  SQVM *v14; // eax
  int v15; // ecx
  SQObjectPtr *v16; // eax
  tagSQObjectType v17; // edx
  SQObjectPtr *v18; // eax
  _DWORD *v19; // ecx
  SQVM *v20; // eax
  SQObjectPtr *v21; // edx
  int v22; // ecx
  tagSQObjectType v23; // esi
  tagSQObjectValue v24; // ecx
  int v25; // edx
  SQObjectPtr *v26; // ecx
  tagSQObjectType v27; // ebx
  tagSQObjectValue v28; // edx
  RefTable::RefNode *v29; // eax
  RefTable::RefNode *v30; // eax
  SQVM *v31; // eax
  int v32; // edx
  SQObjectPtr *v33; // eax
  tagSQObjectType v34; // ecx
  int v35; // eax
  int v36; // ebx
  int v38; // [esp+0h] [ebp-28h]
  RefTable::RefNode *prev; // [esp+10h] [ebp-18h] BYREF
  int nReturnValue; // [esp+14h] [ebp-14h] BYREF
  tagSQObject KeyResult; // [esp+18h] [ebp-10h] BYREF
  tagSQObject ValueResult; // [esp+20h] [ebp-8h] BYREF

  if ( hScope != nullptr )
  {
    if ( hScope == (HSCRIPT__ *)-1
      || *(_DWORD *)hScope == -1 && *((_DWORD *)hScope + 1) == -1
      || *(_DWORD *)hScope != 167772192 )
    {
      return -1;
    }
    sq_pushobject(v: this->m_hVM, obj: *(tagSQObject *)hScope);
  }
  else
  {
    m_hVM = this->m_hVM;
    top = m_hVM->_top;
    m_hVM->_top = top + 1;
    vals = m_hVM->_stack._vals;
    v9.pTable = (SQTable *)m_hVM->_roottable._unVal;
    type = vals[top]._type;
    v11 = &vals[top];
    v12 = &v11->_unVal.pTable->__vftable;
    v11->_unVal = v9;
    v13 = m_hVM->_roottable._type;
    v11->_type = v13;
    if ( (v13 & 0x8000000) != 0 )
      ++*(_DWORD *)(v9.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v12[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  }
  v14 = this->m_hVM;
  v15 = v14->_top;
  v14->_top = v15 + 1;
  v16 = v14->_stack._vals;
  v17 = v16[v15]._type;
  v18 = &v16[v15];
  v19 = &v18->_unVal.pTable->__vftable;
  v18->_unVal.nInteger = nIterator;
  v18->_type = OT_INTEGER;
  if ( (v17 & 0x8000000) != 0 && (int)--v19[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v19 + 8))(a1: v19);
  if ( sq_next(v: this->m_hVM, idx: v38) < 0 )
  {
    v36 = -1;
  }
  else
  {
    v20 = this->m_hVM;
    v21 = v20->_stack._vals;
    v22 = v20->_top;
    v23 = v21[v22 - 2]._type;
    v24.pTable = (SQTable *)v21[v22 - 2]._unVal;
    v25 = v20->_top;
    KeyResult._unVal = v24;
    v26 = v20->_stack._vals;
    v27 = v26[v25 - 1]._type;
    v28.pTable = (SQTable *)v26[v25 - 1]._unVal;
    KeyResult._type = v23;
    ValueResult._type = v27;
    ValueResult._unVal = v28;
    if ( (v23 & 0x8000000) != 0 )
    {
      v29 = RefTable::Get(
              this: &v20->_sharedstate->_refs_table,
              obj: &KeyResult,
              mainpos: (unsigned int *)&nReturnValue,
              &prev,
              add: true);
      ++v29->refs;
    }
    if ( (v27 & 0x8000000) != 0 )
    {
      v30 = RefTable::Get(
              this: &this->m_hVM->_sharedstate->_refs_table,
              obj: &ValueResult,
              mainpos: (unsigned int *)&prev,
              prev: (RefTable::RefNode **)&nReturnValue,
              add: true);
      ++v30->refs;
    }
    CSquirrelVM::ConvertToVariant(this, object: (tagSQObject)__PAIR64__(KeyResult._unVal.raw, v23), pReturn: pKey);
    CSquirrelVM::ConvertToVariant(this, object: (tagSQObject)__PAIR64__(ValueResult._unVal.raw, v27), pReturn: pValue);
    SQVM::Pop(this: this->m_hVM, n: 2);
    v31 = this->m_hVM;
    v32 = v31->_top;
    v33 = v31->_stack._vals;
    v34 = v33[v32 - 1]._type;
    v35 = (int)&v33[v32 - 1];
    if ( (v34 & 0x4000000) != 0 )
    {
      if ( v34 == OT_FLOAT )
        v36 = (int)*(float *)(v35 + 4);
      else
        v36 = *(_DWORD *)(v35 + 4);
    }
    else
    {
      v36 = nReturnValue;
    }
  }
  SQVM::Pop(this: this->m_hVM, n: 1);
  SQVM::Pop(this: this->m_hVM, n: 1);
  return v36;
}

//------------------------------------------------------------------------------
// Address: 0x10029DB0
// Name: public: virtual bool CSquirrelVM::GetValue(struct HSCRIPT__ __near *,char const __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSquirrelVM::GetValue(
        CSquirrelVM *this,
        HSCRIPT__ *hScope,
        const char *pszKey,
        ScriptVariant_t *pValue)
{
  _DWORD *v5; // edi
  tagSQObjectType type; // ebx
  tagSQObject v8; // [esp+10h] [ebp-8h] BYREF

  CSquirrelVM::LookupObject(hScope, this, pszObject: (tagSQObjectValue *)&v8, bAddRef: pszKey, bAddRefa: true);
  v5 = &v8._unVal.pTable->__vftable;
  type = v8._type;
  if ( CSquirrelVM::ConvertToVariant(this, object: v8, pReturn: pValue) && type != OT_NULL )
    return 1;
  if ( (type & 0x8000000) != 0 && (int)--v5[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10029E30
// Name: public: virtual bool CSquirrelVM::ClearValue(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSquirrelVM::ClearValue(CSquirrelVM *this, HSCRIPT__ *hScope, const char *pszKey)
{
  SQVM *m_hVM; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectValue v7; // ebx
  tagSQObjectType type; // edi
  SQObjectPtr *v9; // edx
  _DWORD *v10; // ecx
  tagSQObjectType v11; // eax
  int v13; // [esp+0h] [ebp-10h]
  unsigned int v14; // [esp+4h] [ebp-Ch]

  if ( hScope == nullptr )
  {
    m_hVM = this->m_hVM;
    top = m_hVM->_top;
    m_hVM->_top = top + 1;
    vals = m_hVM->_stack._vals;
    v7.pTable = (SQTable *)m_hVM->_roottable._unVal;
    type = vals[top]._type;
    v9 = &vals[top];
    v10 = &v9->_unVal.pTable->__vftable;
    v9->_unVal = v7;
    v11 = m_hVM->_roottable._type;
    v9->_type = v11;
    if ( (v11 & 0x8000000) != 0 )
      ++*(_DWORD *)(v7.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v10[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
    goto LABEL_12;
  }
  if ( hScope != (HSCRIPT__ *)-1
    && (*(_DWORD *)hScope != -1 || *((_DWORD *)hScope + 1) != -1)
    && *(_DWORD *)hScope == 167772192 )
  {
    sq_pushobject(v: this->m_hVM, obj: *(tagSQObject *)hScope);
LABEL_12:
    sq_pushstring(v: this->m_hVM, s: pszKey, len: -1);
    sq_deleteslot(v: this->m_hVM, idx: v13, pushval: v14);
    SQVM::Pop(this: this->m_hVM, n: 1);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10029EF0
// Name: public: virtual void CSquirrelVM::ReleaseValue(struct ScriptVariant_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::ReleaseValue(CSquirrelVM *this, ScriptVariant_t *value)
{
  __int16 m_type; // ax

  m_type = value->m_type;
  if ( m_type == 33 )
  {
    if ( (*(_DWORD *)value->m_int & 0x8000000) != 0 )
      RefTable::Release((RefTable *)this, obj: (tagSQObject *)value->m_int);
LABEL_4:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)value->m_int);
    value->m_type = 0;
    return;
  }
  if ( (value->m_flags & 1) != 0 )
  {
    if ( m_type == 3 || m_type == 32 )
      goto LABEL_4;
    value->m_type = 0;
  }
  else
  {
    value->m_type = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029F80
// Name: public: virtual bool CSquirrelVM::RaiseException(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSquirrelVM::RaiseException(CSquirrelVM *this, const char *pszExceptionText)
{
  SQSharedState *sharedstate; // ebx
  SQString *v4; // esi
  tagSQObjectType type; // eax
  _DWORD *v6; // ecx

  sharedstate = this->m_hVM->_sharedstate;
  v4 = StringTable::Add(this: sharedstate->_stringtable, news: pszExceptionText, len: -1);
  v4->_sharedstate = sharedstate;
  ++v4->_uiRef;
  type = this->m_ErrorString._type;
  v6 = &this->m_ErrorString._unVal.pTable->__vftable;
  this->m_ErrorString._unVal.nInteger = (int)v4;
  this->m_ErrorString._type = OT_STRING;
  ++v4->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  if ( --v4->_uiRef <= 0 )
    v4->Release(this: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A000
// Name: public: virtual void CSquirrelVM::DumpState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::DumpState(CSquirrelVM *this)
{
  SQVM *m_hVM; // eax
  SQVM *v2; // [esp+0h] [ebp-14h]
  CSquirrelVM::DumpState::__l2::CIterator iter; // [esp+4h] [ebp-10h] BYREF

  m_hVM = this->m_hVM;
  iter.__vftable = (CSquirrelVM::DumpState::__l2::CIterator_vtbl *)&`CSquirrelVM::DumpState'::`2'::CIterator::`vftable';
  iter.indent = 0;
  iter.m_hVM = m_hVM;
  iter.m_bKey = false;
  SQSharedState::Iterate(this: m_hVM->_sharedstate, vm: v2, pIterator: &iter);
}

//------------------------------------------------------------------------------
// Address: 0x1002A030
// Name: public: virtual void CSquirrelVM::WriteState(class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::WriteState(CSquirrelVM *this, CUtlBuffer *pBuffer)
{
  SQSharedState *m_hVM; // ecx
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v5; // esi
  int v6; // ecx
  SQVM *v7; // edx
  SQCollectable *gc_chain; // eax
  unsigned __int64 m_iUniqueIdSerialNumber; // [esp-8h] [ebp-18h]
  SQVM *v10; // [esp+0h] [ebp-10h]

  m_hVM = (SQSharedState *)this->m_hVM;
  this->m_pBuffer = pBuffer;
  if ( *(int *)(m_hVM->_instance_default_delegate._unVal.nInteger + 176) <= 0 )
    SQSharedState::CollectGarbage(this: m_hVM, tchain: v10);
  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 2);
  else
    CUtlBuffer::PutTypeBin<void *>(this: (CUtlBuffer *)m_hVM, src: (void *)2);
  v5 = this->m_pBuffer;
  m_iUniqueIdSerialNumber = this->m_iUniqueIdSerialNumber;
  if ( (v5->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v5, pFmt: "%lld", m_iUniqueIdSerialNumber);
  else
    CUtlBuffer::PutTypeBin<__int64>(
      this: (CUtlBuffer *)HIDWORD(this->m_iUniqueIdSerialNumber),
      src: m_iUniqueIdSerialNumber);
  CSquirrelVM::WriteVM(this, pVM: this->m_hVM);
  v7 = this->m_hVM;
  this->m_pBuffer = nullptr;
  gc_chain = v7->_sharedstate->_gc_chain;
  if ( gc_chain != nullptr )
  {
    v6 = -1073741825;
    do
    {
      gc_chain->_uiRef &= ~0x40000000u;
      gc_chain = gc_chain->_next;
    }
    while ( gc_chain != nullptr );
  }
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)v6);
  this->m_PtrMap.m_Tree.m_FirstFree = -1;
  if ( this->m_PtrMap.m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    this->m_PtrMap.m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( this->m_PtrMap.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PtrMap.m_Tree.m_Elements.m_pMemory);
      this->m_PtrMap.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_PtrMap.m_Tree.m_Elements.m_nAllocationCount = 0;
    this->m_PtrMap.m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A140
// Name: public: virtual void CSquirrelVM::ReadState(class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::ReadState(CSquirrelVM *this, CUtlBuffer *pBuffer)
{
  SQSharedState *m_hVM; // ecx
  CUtlBuffer *m_iUniqueIdSerialNumber_high; // ecx
  CUtlBuffer *m_iUniqueIdSerialNumber; // eax
  CUtlBuffer *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // edx
  CUtlMap<void *,void *,unsigned short>::Node_t *p_m_Data; // eax
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v10; // ecx
  SQVM *v11; // [esp+0h] [ebp-20h]
  int dest; // [esp+14h] [ebp-Ch] BYREF
  CUtlBuffer *v13[2]; // [esp+18h] [ebp-8h] BYREF

  CUtlBuffer::GetType<int>((CUtlBuffer *)this, &dest);
  if ( dest == 2 )
  {
    m_hVM = (SQSharedState *)this->m_hVM;
    if ( *(int *)(m_hVM->_instance_default_delegate._unVal.nInteger + 176) <= 0 )
      SQSharedState::CollectGarbage(this: m_hVM, tchain: v11);
    ++this->m_hVM->_sharedstate->_gc_disableDepth;
    this->m_pBuffer = pBuffer;
    CUtlBuffer::GetType<__int64>(this: pBuffer, dest: (__int64 *)v13);
    m_iUniqueIdSerialNumber_high = (CUtlBuffer *)HIDWORD(this->m_iUniqueIdSerialNumber);
    m_iUniqueIdSerialNumber = (CUtlBuffer *)this->m_iUniqueIdSerialNumber;
    if ( __PAIR64__((unsigned int)m_iUniqueIdSerialNumber_high, (unsigned int)m_iUniqueIdSerialNumber) <= *(_QWORD *)v13 )
    {
      m_iUniqueIdSerialNumber = v13[0];
      m_iUniqueIdSerialNumber_high = v13[1];
    }
    LODWORD(this->m_iUniqueIdSerialNumber) = m_iUniqueIdSerialNumber;
    HIDWORD(this->m_iUniqueIdSerialNumber) = m_iUniqueIdSerialNumber_high;
    CUtlBuffer::GetType<int>(this: m_iUniqueIdSerialNumber_high, &dest);
    v6 = (CUtlBuffer *)this->m_hVM;
    CUtlBuffer::GetType<unsigned int>(this: (CUtlBuffer *)&dest, (unsigned int *)&dest);
    v13[0] = (CUtlBuffer *)dest;
    v13[1] = v6;
    dest = 0xFFFF;
    CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&dest,
      insert: (const CUtlMap<void *,void *,unsigned short>::Node_t *)&this->m_PtrMap,
      parent: (unsigned __int16 *)v13,
      leftchild: (bool *)&dest);
    v7 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertAt(
           this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)dest,
           parent: dest,
           leftchild: false);
    v8 = v7;
    p_m_Data = &this->m_PtrMap.m_Tree.m_Elements.m_pMemory[v7].m_Data;
    if ( &this->m_PtrMap.m_Tree.m_Elements.m_pMemory[v8] != (UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *)-8 )
      *p_m_Data = *(CUtlMap<void *,void *,unsigned short>::Node_t *)v13;
    CSquirrelVM::ReadVM(this, pVM: this->m_hVM);
    this->m_pBuffer = nullptr;
    CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: v10);
    this->m_PtrMap.m_Tree.m_FirstFree = -1;
    if ( this->m_PtrMap.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( this->m_PtrMap.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PtrMap.m_Tree.m_Elements.m_pMemory);
        this->m_PtrMap.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      this->m_PtrMap.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    this->m_PtrMap.m_Tree.m_LastAlloc.index = -1;
    if ( --this->m_hVM->_sharedstate->_gc_disableDepth <= 0 )
      SQSharedState::CollectGarbage(this: (SQSharedState *)0xFFFF, tchain: v11);
  }
  else
  {
    DevMsg(a1: "Incompatible script version\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A2D0
// Name: private: static void CSquirrelVM::PrintFunc(struct SQVM __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSquirrelVM::PrintFunc(SQVM *m_hVM, const char *s, ...)
{
  char string[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+810h] [ebp+10h] BYREF

  va_start(params, s);
  V_vsnprintf(pDest: string, maxLen: 2048, pFormat: s, params);
  _Msg(a1: string);
}

//------------------------------------------------------------------------------
// Address: 0x1002A310
// Name: private: static int CSquirrelVM::ReleaseHook(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::ReleaseHook(_DWORD *p)
{
  int v1; // eax

  (*(void (__cdecl **)(_DWORD))(p[1] + 40))(a1: *p);
  if ( (p[2] & 0x8000000) != 0 )
  {
    v1 = p[3];
    if ( (int)--*(_DWORD *)(v1 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)p[3] + 8))(a1: p[3]);
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A360
// Name: private: static int CSquirrelVM::ExternalInstanceReleaseHook(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::ExternalInstanceReleaseHook(_DWORD *p)
{
  int v1; // eax

  if ( p != nullptr )
  {
    if ( (p[2] & 0x8000000) != 0 )
    {
      v1 = p[3];
      if ( (int)--*(_DWORD *)(v1 + 4) <= 0 )
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)p[3] + 8))(a1: p[3]);
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A3A0
// Name: private: static int CSquirrelVM::GetFunctionSignature(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::GetFunctionSignature(SQVM *hVM)
{
  int stackbase; // esi
  SQObjectPtr *vals; // edi
  SQVM *v4; // ecx
  const char *v5; // ebx
  SQString *v6; // esi
  const char *v7; // eax
  _DWORD *v8; // edi
  int i; // esi
  int v10; // eax
  bool v11; // zf
  int v12; // eax
  const char *v13; // [esp-8h] [ebp-220h]
  tagSQObjectValue hFunction_4; // [esp+14h] [ebp-204h]
  char v15[512]; // [esp+18h] [ebp-200h] BYREF

  stackbase = hVM->_stackbase;
  if ( hVM->_top - stackbase != 3 )
    return 0;
  vals = hVM->_stack._vals;
  hFunction_4.pTable = (SQTable *)vals[stackbase + 1]._unVal;
  if ( vals[stackbase + 1]._type != OT_CLOSURE )
    return 0;
  memset(v15, 0, sizeof(v15));
  v5 = nullptr;
  if ( vals[stackbase + 2]._type == OT_STRING )
  {
    v5 = (const char *)(vals[stackbase + 2]._unVal.nInteger + 28);
  }
  else
  {
    v6 = SQVM::PrintObjVal(this: v4, o: (const tagSQObject *)hVM);
    ++v6->_uiRef;
    v7 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v7, v6->_val);
    if ( --v6->_uiRef <= 0 )
      v6->Release(this: v6);
  }
  v8 = *(_DWORD **)(hFunction_4.nInteger + 36);
  strncat(Destination: v15, Source: "function ", Count: 0x200u);
  if ( v5 != nullptr && *v5 != 0 )
  {
    v13 = v5;
LABEL_14:
    strncat(Destination: v15, Source: v13, Count: 0x200u);
    goto LABEL_15;
  }
  if ( v8[5] != 134217744 )
  {
    v13 = "<unnamed>";
    goto LABEL_14;
  }
  strncat(Destination: v15, Source: (const char *)(v8[6] + 28), Count: 0x200u);
LABEL_15:
  strncat(Destination: v15, Source: "(", Count: 0x200u);
  for ( i = 1; i < v8[15]; ++i )
  {
    if ( i != 1 )
      strncat(Destination: v15, Source: ", ", Count: 0x200u);
    v10 = v8[16];
    v11 = *(_DWORD *)(v10 + 8 * i) == 134217744;
    v12 = v10 + 8 * i;
    if ( v11 )
      strncat(Destination: v15, Source: (const char *)(*(_DWORD *)(v12 + 4) + 28), Count: 0x200u);
    else
      strncat(Destination: v15, Source: "arg", Count: 0x200u);
  }
  strncat(Destination: v15, Source: ")", Count: 0x200u);
  v15[511] = 0;
  sq_pushstring(v: hVM, s: v15, len: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A560
// Name: private: static int CSquirrelVM::GetDeveloper(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::GetDeveloper(SQVM *hVM)
{
  tagSQObjectValue v1; // edx
  int top; // ecx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // esi
  SQObjectPtr *v5; // eax
  _DWORD *v6; // ecx

  v1.pTable = *(SQTable **)(*((_DWORD *)hVM->_sharedstate->m_pOwnerData + 16) + 48);
  top = hVM->_top;
  hVM->_top = top + 1;
  vals = hVM->_stack._vals;
  type = vals[top]._type;
  v5 = &vals[top];
  v6 = &v5->_unVal.pTable->__vftable;
  v5->_unVal = v1;
  v5->_type = OT_INTEGER;
  if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A5C0
// Name: private: static int CSquirrelVM::CallConstructor(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::CallConstructor(SQVM *hVM)
{
  _DWORD *v1; // esi
  int *v2; // eax
  int v3; // ebx
  _DWORD *v4; // eax
  int stackbase; // ecx
  SQObjectPtr *vals; // edx
  int v7; // eax
  SQObjectPtr *v8; // ecx
  tagSQObjectType type; // eax
  void *typetag; // [esp+10h] [ebp-8h] BYREF
  void *p; // [esp+14h] [ebp-4h] BYREF

  v1 = nullptr;
  if ( hVM->_top - hVM->_stackbase <= 0
    || sq_getuserdata(v: hVM, idx: hVM->_top - hVM->_stackbase, &p, &typetag) < 0
    || typetag != nullptr )
  {
    v2 = nullptr;
  }
  else
  {
    v2 = (int *)p;
  }
  v3 = *v2;
  v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16);
  if ( v4 != nullptr )
  {
    v4[3] = 0;
    v4[2] = 16777217;
    v1 = v4;
  }
  *v1 = (*(int (**)(void))(v3 + 36))();
  v1[1] = v3;
  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  if ( vals[stackbase]._type == OT_INSTANCE )
    *(_DWORD *)(vals[stackbase]._unVal.nInteger + 32) = v1;
  else
    sq_throwerror(v: hVM, err: "the object is not a class instance");
  v7 = hVM->_stackbase;
  if ( hVM->_top - v7 >= 1 )
  {
    v8 = &hVM->_stack._vals[v7];
    type = v8->_type;
    if ( v8->_type == OT_CLASS )
    {
      *(_DWORD *)(v8->_unVal.nInteger + 80) = CSquirrelVM::ReleaseHook;
    }
    else
    {
      if ( type == OT_USERDATA )
      {
        *(_DWORD *)(v8->_unVal.nInteger + 32) = CSquirrelVM::ReleaseHook;
        return 0;
      }
      if ( type == OT_INSTANCE )
      {
        *(_DWORD *)(v8->_unVal.nInteger + 36) = CSquirrelVM::ReleaseHook;
        return 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A6C0
// Name: private: static int CSquirrelVM::TranslateCall(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::TranslateCall(SQVM *hVM)
{
  int v1; // eax
  ScriptFunctionBinding_t **v2; // eax
  ScriptFunctionBinding_t *v3; // eax
  int m_Size; // ebx
  int v5; // esi
  CUtlVectorFixed<ScriptVariant_t,14> *p_params; // ebx
  tagSQObjectValue v7; // xmm0_4
  SQObjectPtr *v8; // ecx
  float nInteger; // xmm0_4
  void *v10; // edx
  SQObjectPtr *v11; // eax
  const char *v12; // eax
  tagSQObjectValue v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  void *v17; // edx
  SQObjectPtr *vals; // ecx
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  bool v22; // al
  char v23; // al
  SQObjectPtr *v24; // ecx
  int v25; // eax
  tagSQObjectValue v26; // edx
  tagSQObject *v27; // eax
  ScriptFunctionBinding_t *v28; // esi
  int stackbase; // eax
  SQObjectPtr *v30; // ecx
  SQObjectPtr *v31; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v33; // esi
  tagSQObjectType type; // eax
  _DWORD *v35; // ecx
  int *v37; // ecx
  SQSharedState *v38; // ebx
  SQString *v39; // esi
  tagSQObjectType v40; // eax
  _DWORD *v41; // ecx
  int v42; // eax
  int v43; // edx
  StackHandler *v44; // ecx
  const char *m_int; // eax
  int top; // eax
  SQObjectPtr *v47; // ecx
  int v48; // eax
  SQObjectPtr *v49; // ecx
  tagSQObjectType v50; // eax
  int v51; // eax
  SQObjectPtr *v52; // edx
  _DWORD *v53; // ecx
  SQObjectPtr *v54; // eax
  tagSQObjectType v55; // edx
  tagSQObjectType v56; // esi
  int v57; // ebx
  char *v58; // esi
  __int16 v59; // ax
  SQSharedState *v60; // ebx
  _DWORD *m_pOwnerData; // eax
  int v62; // ecx
  SQString *v63; // eax
  _DWORD *v64; // esi
  tagSQObjectType v65; // eax
  _DWORD *v66; // ecx
  _DWORD *v67; // eax
  _DWORD *v68; // ecx
  int v69; // edx
  tagSQObjectType v70; // esi
  int v71; // [esp+0h] [ebp-B8h]
  bool bCallFree; // [esp+13h] [ebp-A5h]
  void *p; // [esp+14h] [ebp-A4h] BYREF
  StackHandler sa; // [esp+18h] [ebp-A0h] BYREF
  ScriptVariant_t returnValue; // [esp+20h] [ebp-98h] BYREF
  int iLimit; // [esp+28h] [ebp-90h] BYREF
  ScriptFunctionBinding_t *pVMScriptFunction; // [esp+2Ch] [ebp-8Ch]
  int *pCurParamType; // [esp+30h] [ebp-88h]
  int v79; // [esp+34h] [ebp-84h]
  tagSQObject object; // [esp+38h] [ebp-80h]
  CUtlVectorFixed<ScriptVariant_t,14> params; // [esp+40h] [ebp-78h] BYREF

  v1 = hVM->_top - hVM->_stackbase;
  sa.v = hVM;
  sa._top = v1;
  if ( v1 <= 0 || sq_getuserdata(v: hVM, idx: v1, &p, typetag: (void **)&iLimit) < 0 || iLimit != 0 )
    v2 = nullptr;
  else
    v2 = (ScriptFunctionBinding_t **)p;
  v3 = *v2;
  m_Size = v3->m_desc.m_Parameters.m_Size;
  pVMScriptFunction = v3;
  *(_DWORD *)&returnValue.m_type = 0;
  returnValue.m_int = 0;
  bCallFree = false;
  params.m_Size = 0;
  params.m_pElements = (ScriptVariant_t *)&params;
  CUtlVector<ScriptVariant_t,CUtlMemoryFixed<ScriptVariant_t,14,0>>::InsertMultipleBefore(
    this: &params,
    num: m_Size,
    elem: 0);
  if ( sa._top != 0 )
  {
    if ( sa._top >= m_Size )
    {
      iLimit = m_Size;
    }
    else
    {
      m_Size = sa._top;
      iLimit = sa._top;
    }
    pCurParamType = pVMScriptFunction->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( m_Size > 0 )
    {
      v5 = 2;
      p_params = &params;
      while ( 1 )
      {
        switch ( *pCurParamType )
        {
          case 1:
            v7.nInteger = 0;
            if ( v5 > 0 && v5 <= sa._top )
            {
              v8 = &hVM->_stack._vals[v5 - 1 + hVM->_stackbase];
              if ( (v8->_type & 0x4000000) != 0 )
              {
                if ( v8->_type == OT_INTEGER )
                {
                  nInteger = (float)v8->_unVal.nInteger;
                  *(_WORD *)&p_params->m_Memory.m_Memory[4] = 1;
                  *(float *)p_params->m_Memory.m_Memory = nInteger;
                  goto LABEL_54;
                }
                v7.pTable = (SQTable *)v8->_unVal;
              }
            }
            *(_WORD *)&p_params->m_Memory.m_Memory[4] = 1;
            *(tagSQObjectValue *)p_params->m_Memory.m_Memory = v7;
            goto LABEL_54;
          case 3:
            if ( v5 < 0 )
              v11 = &hVM->_stack._vals[v5 + hVM->_top];
            else
              v11 = &hVM->_stack._vals[v5 - 1 + hVM->_stackbase];
            if ( v11->_type == OT_INSTANCE )
            {
              v13.pTable = (SQTable *)v11->_unVal;
              v14 = *(_DWORD *)(v13.nInteger + 32);
              v15 = *(_DWORD *)(v13.nInteger + 28);
              v79 = v14;
              do
              {
                if ( *(_DWORD *)(v15 + 76) == 1 )
                  goto LABEL_34;
                v15 = *(_DWORD *)(v15 + 28);
              }
              while ( v15 != 0 );
              v12 = "invalid type tag";
            }
            else
            {
              v12 = "the object is not a class instance";
            }
            if ( sq_throwerror(v: hVM, err: v12) < 0 )
              goto LABEL_62;
LABEL_34:
            v16 = v79;
            if ( v79 == 0 )
            {
LABEL_62:
              sq_throwerror(v: hVM, err: "Vector argument expected");
              return -1;
            }
            *(_WORD *)&p_params->m_Memory.m_Memory[4] = 3;
            *(_DWORD *)p_params->m_Memory.m_Memory = v16;
LABEL_54:
            ++pCurParamType;
            ++v5;
            p_params = (CUtlVectorFixed<ScriptVariant_t,14> *)((char *)p_params + 8);
            if ( v5 - 2 >= iLimit )
              goto LABEL_55;
            break;
          case 5:
            p = nullptr;
            if ( v5 > 0 && v5 <= sa._top )
              sq_getinteger(v: hVM, idx: v5, i: (int *)&p);
            v17 = p;
            *(_WORD *)&p_params->m_Memory.m_Memory[4] = 5;
            *(_DWORD *)p_params->m_Memory.m_Memory = v17;
            goto LABEL_54;
          case 6:
            if ( v5 > 0
              && v5 <= sa._top
              && (vals = hVM->_stack._vals,
                  v19 = v5 + hVM->_stackbase,
                  v20 = vals[v19 - 1]._type == OT_BOOL,
                  v21 = (int)&vals[v19 - 1],
                  v20) )
            {
              v22 = *(_DWORD *)(v21 + 4) != 0;
              *(_WORD *)&p_params->m_Memory.m_Memory[4] = 6;
              p_params->m_Memory.m_Memory[0] = v22;
            }
            else
            {
              *(_WORD *)&p_params->m_Memory.m_Memory[4] = 6;
              p_params->m_Memory.m_Memory[0] = 0;
            }
            goto LABEL_54;
          case 8:
            p = nullptr;
            if ( v5 > 0 && v5 <= sa._top )
              sq_getstring(v: hVM, idx: v5, c: (const char **)&p);
            v23 = *(_BYTE *)p;
            *(_WORD *)&p_params->m_Memory.m_Memory[4] = 8;
            p_params->m_Memory.m_Memory[0] = v23;
            goto LABEL_54;
          case 32:
            p = nullptr;
            if ( v5 > 0 && v5 <= sa._top )
              sq_getstring(v: hVM, idx: v5, c: (const char **)&p);
            v10 = p;
            *(_WORD *)&p_params->m_Memory.m_Memory[4] = 32;
            *(_DWORD *)p_params->m_Memory.m_Memory = v10;
            goto LABEL_54;
          case 33:
            if ( v5 <= 0
              || v5 > sa._top
              || (v24 = hVM->_stack._vals,
                  v25 = v5 + hVM->_stackbase,
                  v26.pTable = (SQTable *)v24[v25 - 1]._unVal,
                  object._type = v24[v25 - 1]._type,
                  object._unVal = v26,
                  object._type == OT_NULL) )
            {
              *(_WORD *)&p_params->m_Memory.m_Memory[4] = 33;
              *(_DWORD *)p_params->m_Memory.m_Memory = 0;
            }
            else
            {
              v27 = (tagSQObject *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8);
              *v27 = object;
              *(_WORD *)&p_params->m_Memory.m_Memory[4] = 33;
              *(_DWORD *)p_params->m_Memory.m_Memory = v27;
              *(_WORD *)&p_params->m_Memory.m_Memory[6] |= 1u;
              bCallFree = true;
            }
            goto LABEL_54;
          default:
            goto LABEL_54;
        }
      }
    }
  }
LABEL_55:
  v28 = pVMScriptFunction;
  if ( (pVMScriptFunction->m_flags & 1) != 0 )
  {
    stackbase = hVM->_stackbase;
    v30 = hVM->_stack._vals;
    v20 = v30[stackbase]._type == OT_INSTANCE;
    v31 = &v30[stackbase];
    if ( !v20 )
    {
      sharedstate = hVM->_sharedstate;
      v33 = StringTable::Add(this: sharedstate->_stringtable, news: "the object is not a class instance", len: -1);
      v33->_sharedstate = sharedstate;
      ++v33->_uiRef;
      type = hVM->_lasterror._type;
      v35 = &hVM->_lasterror._unVal.pTable->__vftable;
      hVM->_lasterror._unVal.nInteger = (int)v33;
      hVM->_lasterror._type = OT_STRING;
      ++v33->_uiRef;
      if ( (type & 0x8000000) != 0 && (int)--v35[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v35 + 8))(a1: v35);
      if ( --v33->_uiRef <= 0 )
        v33->Release(this: v33);
      goto LABEL_64;
    }
    v37 = *(int **)(v31->_unVal.nInteger + 32);
    if ( v37 == nullptr )
    {
LABEL_64:
      v38 = hVM->_sharedstate;
      v39 = StringTable::Add(this: v38->_stringtable, news: "Accessed null instance", len: -1);
      v39->_sharedstate = v38;
      ++v39->_uiRef;
      v40 = hVM->_lasterror._type;
      v41 = &hVM->_lasterror._unVal.pTable->__vftable;
      hVM->_lasterror._unVal.nInteger = (int)v39;
      hVM->_lasterror._type = OT_STRING;
      ++v39->_uiRef;
      if ( (v40 & 0x8000000) != 0 && (int)--v41[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v41 + 8))(a1: v41);
      if ( --v39->_uiRef <= 0 )
        v39->Release(this: v39);
      return -1;
    }
    v42 = *v37;
    if ( *v37 == 0 )
      goto LABEL_74;
    v43 = v37[1];
    if ( *(_DWORD *)(v43 + 44) != 0 )
      v42 = (***(int (__thiscall ****)(_DWORD, int))(v43 + 44))(a1: *(_DWORD *)(v43 + 44), a2: v42);
    if ( v42 == 0 )
    {
LABEL_74:
      sq_throwerror(v: hVM, err: "Accessed null instance");
      return -1;
    }
  }
  else
  {
    v42 = 0;
  }
  v28->m_pfnBinding(
    a1: v28->m_pFunction,
    a2: (void *)v42,
    a3: (ScriptVariant_t *)&params,
    a4: params.m_Size,
    a5: v28->m_desc.m_ReturnType != 0 ? &returnValue : nullptr);
  if ( v28->m_desc.m_ReturnType != 0 )
  {
    switch ( returnValue.m_type )
    {
      case 1:
        StackHandler::Return(this: v44, a2: (int)&sa, a3: returnValue.m_int);
        break;
      case 3:
        sq_pushobject(v: hVM, obj: *(tagSQObject *)((char *)hVM->_sharedstate->m_pOwnerData + 28));
        sq_createinstance(v: hVM, idx: v71);
        top = hVM->_top;
        v47 = hVM->_stack._vals;
        v20 = v47[top - 1]._type == OT_INSTANCE;
        v48 = (int)&v47[top - 1];
        if ( v20 )
          *(_DWORD *)(*(_DWORD *)(v48 + 4) + 32) = returnValue.m_int;
        else
          sq_throwerror(v: hVM, err: "the object is not a class instance");
        if ( hVM->_top - hVM->_stackbase >= 1 )
        {
          v49 = &hVM->_stack._vals[hVM->_top - 1];
          v50 = v49->_type;
          if ( v49->_type == OT_CLASS )
          {
            *(_DWORD *)(v49->_unVal.nInteger + 80) = VectorRelease;
          }
          else
          {
            if ( v50 == OT_USERDATA )
            {
              *(_DWORD *)(v49->_unVal.nInteger + 32) = VectorRelease;
              SQVM::Remove(this: hVM, n: -2);
              break;
            }
            if ( v50 == OT_INSTANCE )
            {
              *(_DWORD *)(v49->_unVal.nInteger + 36) = VectorRelease;
              SQVM::Remove(this: hVM, n: -2);
              break;
            }
          }
        }
        SQVM::Remove(this: hVM, n: -2);
        break;
      case 5:
        StackHandler::Return(this: &sa, i: (tagSQObjectValue)returnValue.m_int, a3: (int)v44);
        break;
      case 6:
        StackHandler::Return(this: v44, a2: (int)&sa, b: returnValue.m_bool);
        break;
      case 8:
        goto $LN12_17;
      case 0x20:
        m_int = (const char *)returnValue.m_int;
        if ( returnValue.m_int == 0 )
          m_int = Ptr;
        sq_pushstring(v: hVM, s: m_int, len: -1);
        break;
      case 0x21:
        if ( returnValue.m_int != 0 )
          sq_pushobject(v: hVM, obj: *(tagSQObject *)returnValue.m_int);
        else
$LN12_17:
          sq_pushnull(v: hVM);
        break;
      default:
        v51 = hVM->_top;
        v52 = hVM->_stack._vals;
        hVM->_top = v51 + 1;
        v53 = &v52[v51]._unVal.pTable->__vftable;
        v54 = &v52[v51];
        v55 = v54->_type;
        v54->_unVal.nInteger = _null_._unVal.nInteger;
        v56 = _null_._type;
        v54->_type = _null_._type;
        if ( (v56 & 0x8000000) != 0 )
          ++*(_DWORD *)(v54->_unVal.nInteger + 4);
        if ( (v55 & 0x8000000) != 0 && (int)--v53[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v53 + 8))(a1: v53);
        break;
    }
  }
  if ( bCallFree )
  {
    v57 = 0;
    if ( params.m_Size > 0 )
    {
      v58 = &params.m_Memory.m_Memory[4];
      do
      {
        if ( (v58[2] & 1) != 0 )
        {
          v59 = *(_WORD *)v58;
          if ( *(_WORD *)v58 == 33 || v59 == 3 || v59 == 32 )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v58 - 1));
        }
        ++v57;
        v58 += 8;
      }
      while ( v57 < params.m_Size );
    }
  }
  v60 = hVM->_sharedstate;
  m_pOwnerData = v60->m_pOwnerData;
  v62 = m_pOwnerData[9];
  if ( v62 == 16777217 )
    return pVMScriptFunction->m_desc.m_ReturnType != 0;
  if ( v62 == 134217744 )
    v63 = StringTable::Add(this: v60->_stringtable, news: (const char *)(m_pOwnerData[10] + 28), len: -1);
  else
    v63 = StringTable::Add(this: v60->_stringtable, news: "Internal error", len: -1);
  v64 = &v63->__vftable;
  v63->_sharedstate = v60;
  ++v63->_uiRef;
  v65 = hVM->_lasterror._type;
  v66 = &hVM->_lasterror._unVal.pTable->__vftable;
  hVM->_lasterror._unVal.nInteger = (int)v64;
  hVM->_lasterror._type = OT_STRING;
  ++v64[1];
  if ( (v65 & 0x8000000) != 0 && (int)--v66[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v66 + 8))(a1: v66);
  if ( (int)--v64[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v64 + 8))(a1: v64);
  v67 = hVM->_sharedstate->m_pOwnerData;
  v68 = (_DWORD *)v67[10];
  v69 = v67[9];
  v67[10] = _null_._unVal.pTable;
  v70 = _null_._type;
  v67[9] = _null_._type;
  if ( (v70 & 0x8000000) != 0 )
    ++*(_DWORD *)(v67[10] + 4);
  if ( (v69 & 0x8000000) != 0 && (int)--v68[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v68 + 8))(a1: v68);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002AEC0
// Name: private: static int CSquirrelVM::QueryContinue(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::QueryContinue(SQVM *hVM)
{
  float *m_pOwnerData; // esi

  m_pOwnerData = (float *)hVM->_sharedstate->m_pOwnerData;
  if ( *((_DWORD *)m_pOwnerData + 2) != 0
    || m_pOwnerData[14] == 0.0
    || _Plat_FloatTime() - m_pOwnerData[14] <= 0.02999999932944775 )
  {
    return 0;
  }
  DevMsg(a1: "Script running too long, terminating\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002AF20
// Name: private: static int CSquirrelVM::InstanceToString(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::InstanceToString(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  int v3; // esi
  bool v4; // zf
  SQObjectPtr *v5; // eax
  _DWORD *v6; // eax
  int v7; // ecx
  const char *pTable; // eax
  CFmtStrN<256> *v10; // eax
  _DWORD *hInstance; // [esp+10h] [ebp-158h]
  char szBuf[68]; // [esp+18h] [ebp-150h] BYREF

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = hVM->_top - stackbase;
  v4 = vals[stackbase]._type == OT_INSTANCE;
  v5 = &vals[stackbase];
  if ( v4 )
  {
    v6 = *(_DWORD **)(v5->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
      goto LABEL_10;
    v6 = hInstance;
  }
  if ( v6 != nullptr && *v6 != 0 )
  {
    v7 = v6[1];
    if ( *(_DWORD *)(v7 + 44) != 0
      && (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD, char *, int))(**(_DWORD **)(v7 + 44) + 4))(
           a1: *(_DWORD *)(v7 + 44),
           a2: *v6,
           a3: szBuf,
           a4: 64) != 0 )
    {
      sq_pushstring(v: hVM, s: szBuf, len: -1);
      return 1;
    }
  }
LABEL_10:
  if ( v3 < 1 )
    pTable = nullptr;
  else
    pTable = (const char *)hVM->_stack._vals[hVM->_stackbase]._unVal.pTable;
  v10 = CFmtStrN<256>::CFmtStrN<256>(this: (CFmtStrN<256> *)&stru_1009B330, pszFormat: pTable);
  sq_pushstring(v: hVM, s: v10->m_szBuf, len: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002AFF0
// Name: private: static int CSquirrelVM::InstanceIsValid(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::InstanceIsValid(SQVM *hVM)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  _DWORD *v5; // eax
  int v6; // eax
  int top; // eax
  SQObjectPtr *v8; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v10; // eax
  _DWORD *v11; // ecx
  _DWORD *v13; // [esp+Ch] [ebp-4h]

  stackbase = hVM->_stackbase;
  vals = hVM->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  if ( v3 )
  {
    v5 = *(_DWORD **)(v4->_unVal.nInteger + 32);
  }
  else
  {
    if ( sq_throwerror(v: hVM, err: "the object is not a class instance") < 0 )
    {
LABEL_8:
      v6 = 0;
      goto LABEL_9;
    }
    v5 = v13;
  }
  if ( v5 == nullptr || *v5 == 0 )
    goto LABEL_8;
  v6 = 1;
LABEL_9:
  v3 = v6 == 0;
  top = hVM->_top;
  hVM->_top = top + 1;
  v8 = hVM->_stack._vals;
  type = v8[top]._type;
  v10 = &v8[top];
  v11 = &v10->_unVal.pTable->__vftable;
  v10->_type = OT_BOOL;
  v10->_unVal.nInteger = !v3;
  if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B090
// Name: private: struct tagSQObject CSquirrelVM::CreateClass(struct ScriptClassDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
tagSQObjectType *__thiscall CSquirrelVM::CreateClass(
        CSquirrelVM *this,
        ScriptClassDesc_t *pDesc,
        tagSQObjectType *a3,
        ScriptClassDesc_t *pDesca)
{
  ScriptClassDesc_t *v4; // ebx
  const char *m_pszClassname; // eax
  int v6; // ecx
  ScriptClassDesc_t *v7; // edi
  tagSQObjectValue v8; // esi
  tagSQObjectValue *v9; // edx
  _DWORD *v10; // ecx
  int v11; // eax
  ScriptClassDesc_t *v12; // esi
  const char **p_m_pszScriptName; // eax
  SQVM *v14; // esi
  SQObjectPtr *vals; // edx
  ScriptClassDesc_t *v16; // ecx
  SQVM *v17; // eax
  tagSQObjectType *result; // eax
  bool v19; // sf
  int top; // ecx
  SQObjectPtr *v21; // edx
  tagSQObjectType type; // edi
  tagSQObjectValue v23; // ecx
  RefTable::RefNode *v24; // eax
  _DWORD *v25; // eax
  tagSQObjectValue v26; // ecx
  SQObjectPtr *v27; // [esp-10h] [ebp-2Ch]
  unsigned int v28; // [esp+0h] [ebp-1Ch]
  tagSQObject hObject; // [esp+10h] [ebp-Ch] BYREF

  v4 = pDesc;
  m_pszClassname = pDesc->m_pszClassname;
  v6 = *((_DWORD *)m_pszClassname + 14);
  v7 = (ScriptClassDesc_t *)(v6 - *((_DWORD *)m_pszClassname + 15));
  *((_DWORD *)m_pszClassname + 14) = v6 + 1;
  v8.pTable = *(SQTable **)(m_pszClassname + 68);
  v9 = (tagSQObjectValue *)(*((_DWORD *)m_pszClassname + 8) + 8 * v6);
  hObject._unVal = (tagSQObjectValue)v9->pTable;
  v10 = &v9[1].pTable->__vftable;
  v9[1].pTable = v8.pTable;
  v11 = *((_DWORD *)m_pszClassname + 16);
  pDesc = v7;
  v9->nInteger = v11;
  if ( (v11 & 0x8000000) != 0 )
    ++*(_DWORD *)(v8.nInteger + 4);
  if ( (hObject._unVal.nInteger & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  v12 = pDesca;
  sq_pushstring(v: (SQVM *)v4->m_pszClassname, s: pDesca->m_pszScriptName, len: -1);
  p_m_pszScriptName = &v12->m_pBaseDesc->m_pszScriptName;
  if ( p_m_pszScriptName != nullptr )
  {
    sq_pushstring(v: (SQVM *)v4->m_pszClassname, s: *p_m_pszScriptName, len: -1);
    v14 = (SQVM *)v4->m_pszClassname;
    vals = v14->_stack._vals;
    v27 = &vals[v14->_top - 1];
    if ( !SQVM::Get(this: v14, self: &vals[v14->_top - 3], key: v27, dest: v27, raw: false, fetchroot: false) )
    {
      SQVM::Pop(this: v14, n: 1);
      if ( sq_throwerror(v: v14, err: "the index doesn't exist") < 0 )
      {
        v16 = pDesc;
        v17 = (SQVM *)v4->m_pszClassname;
LABEL_10:
        sq_settop(v: v17, newtop: (int)v16);
        result = a3;
        *a3 = -1;
        *((_DWORD *)result + 1) = -1;
        return result;
      }
      v7 = pDesc;
    }
    v12 = pDesca;
  }
  v19 = sq_newclass(v: (SQVM *)v4->m_pszClassname, hasbase: v12->m_pBaseDesc != nullptr) < 0;
  v17 = (SQVM *)v4->m_pszClassname;
  if ( v19 )
  {
    v16 = v7;
    goto LABEL_10;
  }
  top = v17->_top;
  v21 = v17->_stack._vals;
  type = v21[top - 1]._type;
  v23.pTable = (SQTable *)v21[top - 1]._unVal;
  hObject._type = type;
  hObject._unVal = v23;
  if ( (type & 0x8000000) != 0 )
  {
    v24 = RefTable::Get(
            this: &v17->_sharedstate->_refs_table,
            obj: &hObject,
            mainpos: (unsigned int *)&pDesc,
            prev: (RefTable::RefNode **)&pDesca,
            add: true);
    ++v24->refs;
  }
  v25 = (_DWORD *)(*((_DWORD *)v4->m_pszClassname + 8) + 8 * *((_DWORD *)v4->m_pszClassname + 14) - 8);
  if ( *v25 == 134234112 )
  {
    *(_DWORD *)(v25[1] + 76) = v12;
  }
  else if ( *v25 == 167772288 )
  {
    *(_DWORD *)(v25[1] + 36) = v12;
  }
  else
  {
    sq_throwerror(v: (SQVM *)v4->m_pszClassname, err: "invalid object type");
    type = hObject._type;
  }
  sq_newslot(v: (SQVM *)v4->m_pszClassname, idx: -3, bstatic: v28);
  SQVM::Pop(this: (SQVM *)v4->m_pszClassname, n: 1);
  result = a3;
  v26.pTable = (SQTable *)hObject._unVal;
  *a3 = type;
  result[1] = (tagSQObjectType)v26.pTable;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B250
// Name: private: void CSquirrelVM::RegisterFunctionGuts(struct ScriptFunctionBinding_t __near *,struct ScriptClassDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::RegisterFunctionGuts(
        CSquirrelVM *this,
        CSquirrelVM *pScriptFunction,
        ScriptFunctionBinding_t *pClassDesc,
        ScriptClassDesc_t *pClassDesca)
{
  int m_Size; // ecx
  char *v5; // eax
  ScriptFunctionBinding_t *m_pMemory; // edx
  int i; // esi
  CSquirrelVM *v8; // esi
  SQVM *m_hVM; // ecx
  SQVM *v10; // eax
  int v11; // ecx
  tagSQObjectType v12; // edx
  tagSQObjectValue v13; // ecx
  const char *m_pszScriptName; // edx
  SQVM *v15; // edi
  int top; // eax
  SQVM *vals; // ecx
  int v18; // edx
  const char *m_pszDescription; // eax
  const char *v20; // eax
  int j; // edi
  const char *v22; // eax
  char *v23; // eax
  int v24; // edx
  _DWORD *v25; // esi
  const char *v26; // eax
  int v27; // edi
  int v28; // ecx
  int v29; // eax
  int v30; // ebx
  _DWORD *v31; // eax
  _DWORD *v32; // ecx
  const char *v33; // eax
  int v34; // ecx
  int v35; // edx
  int v36; // ebx
  int v37; // esi
  _DWORD *v38; // edx
  _DWORD *v39; // ecx
  int v40; // eax
  __int32 v41; // ebx
  const char *v42; // eax
  _DWORD *v43; // esi
  int v44; // ecx
  tagSQObjectType type; // edx
  int v46; // eax
  _DWORD *v47; // ecx
  SQVM *v48; // esi
  int v49; // eax
  int *pTable; // ecx
  SQObjectPtr *v51; // [esp-14h] [ebp-474h]
  unsigned int v52; // [esp+0h] [ebp-460h]
  int v53; // [esp+0h] [ebp-460h]
  const char *v54; // [esp+0h] [ebp-460h]
  SQObjectPtr pszObject; // [esp+10h] [ebp-450h] BYREF
  tagSQObject hFunction; // [esp+18h] [ebp-448h]
  char szTypeMask[64]; // [esp+20h] [ebp-440h] BYREF
  char signature[512]; // [esp+60h] [ebp-400h] BYREF
  char name[512]; // [esp+260h] [ebp-200h] BYREF

  m_Size = pClassDesc->m_desc.m_Parameters.m_Size;
  if ( (unsigned int)m_Size <= 0x3F )
  {
    szTypeMask[0] = 46;
    v5 = &szTypeMask[1];
    if ( m_Size > 0 )
    {
      m_pMemory = (ScriptFunctionBinding_t *)pClassDesc->m_desc.m_Parameters.m_Memory.m_pMemory;
      for ( i = m_Size; i != 0; --i )
      {
        switch ( (unsigned int)m_pMemory->m_desc.m_pszScriptName )
        {
          case 1u:
          case 5u:
            *v5 = 110;
            break;
          case 3u:
            *v5 = 120;
            break;
          case 6u:
            *v5 = 98;
            break;
          case 0x20u:
            *v5 = 115;
            break;
          case 0x21u:
            *v5 = 46;
            break;
          default:
            *v5 = 0;
            break;
        }
        m_pMemory = (ScriptFunctionBinding_t *)((char *)m_pMemory + 4);
        ++v5;
      }
    }
    v8 = pScriptFunction;
    m_hVM = pScriptFunction->m_hVM;
    *v5 = 0;
    sq_pushstring(v: m_hVM, s: pClassDesc->m_desc.m_pszScriptName, len: -1);
    *(_DWORD *)sq_newuserdata(v: pScriptFunction->m_hVM, size: v52) = pClassDesc;
    sq_newclosure(v: pScriptFunction->m_hVM, func: CSquirrelVM::TranslateCall, nfreevars: 1u);
    v10 = pScriptFunction->m_hVM;
    v11 = (int)&v10->_stack._vals[v10->_top - 1];
    v12 = *(_DWORD *)v11;
    v13.pTable = *(SQTable **)(v11 + 4);
    hFunction._type = v12;
    m_pszScriptName = pClassDesc->m_desc.m_pszScriptName;
    hFunction._unVal = v13;
    sq_setnativeclosurename(v: v10, idx: v53, name: m_pszScriptName);
    sq_setparamscheck(
      v: pScriptFunction->m_hVM,
      nparamscheck: pClassDesc->m_desc.m_Parameters.m_Size + 1,
      typemask: szTypeMask);
    v15 = pScriptFunction->m_hVM;
    top = v15->_top;
    if ( top - v15->_stackbase >= 3 )
    {
      vals = (SQVM *)v15->_stack._vals;
      v18 = *((_DWORD *)vals + 2 * top - 6);
      if ( v18 == 167772192 || v18 == 134234112 )
      {
        if ( *((_DWORD *)vals + 2 * top - 4) == 16777217 )
        {
          sq_throwerror(v: v15, err: "null is not a valid key");
        }
        else
        {
          SQVM::NewSlot(
            this: vals,
            self: (const SQObjectPtr *)vals + top - 3,
            key: (const SQObjectPtr *)vals + top - 2,
            val: (const SQObjectPtr *)vals + top - 1,
            bstatic: false);
          SQVM::Pop(this: v15, n: 2);
        }
      }
      v8 = pScriptFunction;
    }
    else
    {
      SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v54);
    }
    if ( v8->developer.m_pConVarState->m_Value.m_nValue != 0 )
    {
      m_pszDescription = pClassDesc->m_desc.m_pszDescription;
      if ( m_pszDescription == nullptr || *m_pszDescription != 64 )
      {
        memset(name, 0, sizeof(name));
        memset(signature, 0, sizeof(signature));
        if ( pClassDesca != nullptr )
        {
          strncat(Destination: name, Source: pClassDesca->m_pszScriptName, Count: 0x200u);
          strncat(Destination: name, Source: &stru_1009B330.m_szBuf[15], Count: 0x200u);
        }
        strncat(Destination: name, Source: pClassDesc->m_desc.m_pszScriptName, Count: 0x200u);
        switch ( pClassDesc->m_desc.m_ReturnType )
        {
          case 0:
            v20 = "void";
            break;
          case 1:
            v20 = "float";
            break;
          case 3:
            v20 = "Vector";
            break;
          case 5:
            v20 = "int";
            break;
          case 6:
            v20 = "bool";
            break;
          case 8:
            v20 = "char";
            break;
          case 0x20:
            v20 = "string";
            break;
          case 0x21:
            v20 = "handle";
            break;
          default:
            v20 = "<unknown>";
            break;
        }
        strncat(Destination: signature, Source: v20, Count: 0x200u);
        strncat(Destination: signature, Source: " ", Count: 0x200u);
        strncat(Destination: signature, Source: name, Count: 0x200u);
        strncat(Destination: signature, Source: "(", Count: 0x200u);
        for ( j = 0; j < pClassDesc->m_desc.m_Parameters.m_Size; ++j )
        {
          if ( j != 0 )
            strncat(Destination: signature, Source: ", ", Count: 0x200u);
          switch ( pClassDesc->m_desc.m_Parameters.m_Memory.m_pMemory[j] )
          {
            case 0:
              v22 = "void";
              break;
            case 1:
              v22 = "float";
              break;
            case 3:
              v22 = "Vector";
              break;
            case 5:
              v22 = "int";
              break;
            case 6:
              v22 = "bool";
              break;
            case 8:
              v22 = "char";
              break;
            case 0x20:
              v22 = "string";
              break;
            case 0x21:
              v22 = "handle";
              break;
            default:
              v22 = "<unknown>";
              break;
          }
          strncat(Destination: signature, Source: v22, Count: 0x200u);
        }
        strncat(Destination: signature, Source: ")", Count: 0x200u);
        v23 = CSquirrelVM::LookupObject(
                hScope: nullptr,
                this: v8,
                (tagSQObjectValue *)&pszObject,
                bAddRef: &stru_1009B330.m_szBuf[19],
                bAddRefa: false);
        v24 = *(_DWORD *)v23;
        v25 = *((_DWORD **)v23 + 1);
        v26 = (const char *)pScriptFunction->m_hVM;
        v27 = v24 & 0x8000000;
        if ( (v24 & 0x8000000) != 0 )
          ++v25[1];
        v28 = *((_DWORD *)v26 + 14);
        *((_DWORD *)v26 + 14) = v28 + 1;
        v29 = *((_DWORD *)v26 + 8);
        v30 = *(_DWORD *)(v29 + 8 * v28);
        v31 = (_DWORD *)(v29 + 8 * v28);
        v32 = (_DWORD *)v31[1];
        v31[1] = v25;
        *v31 = v24;
        if ( v27 != 0 )
          ++v25[1];
        if ( (v30 & 0x8000000) != 0 && (int)--v32[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v32 + 8))(a1: v32);
        if ( v27 != 0 && (int)--v25[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v25 + 8))(a1: v25);
        v33 = (const char *)pScriptFunction->m_hVM;
        v34 = *((_DWORD *)v33 + 14);
        *((_DWORD *)v33 + 14) = v34 + 1;
        v35 = *((_DWORD *)v33 + 8);
        v36 = *((_DWORD *)v33 + 17);
        v37 = *(_DWORD *)(v35 + 8 * v34);
        v38 = (_DWORD *)(v35 + 8 * v34);
        v39 = (_DWORD *)v38[1];
        v38[1] = v36;
        v40 = *((_DWORD *)v33 + 16);
        *v38 = v40;
        if ( (v40 & 0x8000000) != 0 )
          ++*(_DWORD *)(v36 + 4);
        if ( (v37 & 0x8000000) != 0 && (int)--v39[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v39 + 8))(a1: v39);
        v41 = hFunction._type & 0x8000000;
        v42 = (const char *)pScriptFunction->m_hVM;
        v43 = &hFunction._unVal.pTable->__vftable;
        if ( (hFunction._type & 0x8000000) != 0 )
          ++*(_DWORD *)(hFunction._unVal.nInteger + 4);
        v44 = *((_DWORD *)v42 + 14);
        *((_DWORD *)v42 + 14) = v44 + 1;
        type = hFunction._type;
        v46 = *((_DWORD *)v42 + 8) + 8 * v44;
        pszObject._type = *(_DWORD *)v46;
        v47 = *(_DWORD **)(v46 + 4);
        *(_DWORD *)(v46 + 4) = v43;
        *(_DWORD *)v46 = type;
        if ( v41 != 0 )
          ++v43[1];
        if ( (pszObject._type & 0x8000000) != 0 && (int)--v47[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v47 + 8))(a1: v47);
        if ( v41 != 0 && (int)--v43[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v43 + 8))(a1: v43);
        sq_pushstring(v: pScriptFunction->m_hVM, s: name, len: -1);
        sq_pushstring(v: pScriptFunction->m_hVM, s: signature, len: -1);
        sq_pushstring(v: pScriptFunction->m_hVM, s: pClassDesc->m_desc.m_pszDescription, len: -1);
        v48 = pScriptFunction->m_hVM;
        v49 = v48->_top;
        v51 = &v48->_stack._vals[v49 - 6];
        pszObject._type = OT_NULL;
        pszObject._unVal.nInteger = 0;
        if ( !SQVM::Call(this: v48, closure: v51, nparams: 5, stackbase: v49 - 5, outres: &pszObject, raiseerror: 1u)
          || v48->_suspended == 0 )
        {
          SQVM::Pop(this: v48, n: 5);
        }
        if ( (pszObject._type & 0x8000000) != 0 )
        {
          pTable = (int *)pszObject._unVal.pTable;
          --*(_DWORD *)(pszObject._unVal.nInteger + 4);
          if ( pTable[1] <= 0 )
            (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
        }
        SQVM::Pop(this: pScriptFunction->m_hVM, n: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B850
// Name: private: void CSquirrelVM::PushVariant(struct ScriptVariant_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::PushVariant(const ScriptVariant_t *value@<eax>, CSquirrelVM *this, bool bCopy)
{
  CSquirrelVM *v3; // ebx
  const char *v5; // esi
  int v6; // eax
  _DWORD *v7; // eax
  int m_int; // esi
  SQVM *m_hVM; // edi
  int top; // edx
  SQObjectPtr *vals; // ecx
  bool v12; // zf
  int v13; // ecx
  int v14; // [esp+0h] [ebp-Ch]

  v3 = this;
  switch ( value->m_type )
  {
    case 0:
      goto $LN2_26;
    case 1:
      sq_pushfloat();
      break;
    case 3:
      sq_pushobject(v: this->m_hVM, obj: this->m_hClassVector);
      sq_createinstance(v: v3->m_hVM, idx: v14);
      v7 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
      if ( v7 != nullptr )
      {
        m_int = value->m_int;
        *(_QWORD *)v7 = *(_QWORD *)m_int;
        v7[2] = *(_DWORD *)(m_int + 8);
      }
      else
      {
        v7 = nullptr;
      }
      m_hVM = v3->m_hVM;
      top = m_hVM->_top;
      vals = m_hVM->_stack._vals;
      v12 = vals[top - 1]._type == OT_INSTANCE;
      v13 = (int)&vals[top - 1];
      if ( v12 )
        *(_DWORD *)(*(_DWORD *)(v13 + 4) + 32) = v7;
      else
        sq_throwerror(v: m_hVM, err: "the object is not a class instance");
      sq_setreleasehook(v: v3->m_hVM, idx: -1, hook: (int (__cdecl *)(void *, int))VectorRelease);
      SQVM::Remove(this: v3->m_hVM, n: -2);
      break;
    case 5:
      sq_pushinteger(v: this->m_hVM, n: value->m_int);
      break;
    case 6:
      sq_pushbool(v: this->m_hVM, b: (unsigned __int8)value->m_char);
      break;
    case 8:
      LOWORD(this) = (unsigned __int8)value->m_char;
      sq_pushstring(v: v3->m_hVM, s: (const char *)&this, len: 1);
      break;
    case 0x20:
      v5 = (const char *)value->m_int;
      v6 = strlen(value->m_pszString);
      if ( v5 == nullptr )
        v5 = Ptr;
      sq_pushstring(v: this->m_hVM, s: v5, len: v6);
      break;
    case 0x21:
      if ( value->m_int != 0 )
        sq_pushobject(v: this->m_hVM, obj: *(tagSQObject *)value->m_int);
      else
$LN2_26:
        sq_pushnull(v: this->m_hVM);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BA10
// Name: private: bool CSquirrelVM::ConvertToVariant(struct tagSQObject,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSquirrelVM::ConvertToVariant@<al>(
        ScriptVariant_t *pReturn@<esi>,
        CSquirrelVM *this,
        tagSQObject object)
{
  CSquirrelVM *v3; // ebx
  SQVM *m_hVM; // edi
  SQObjectPtr *v6; // eax
  const char *v7; // eax
  tagSQObjectValue v8; // eax
  CSquirrelVM *v9; // ecx
  int v10; // eax
  int v11; // edi
  _DWORD *v12; // eax
  tagSQObject *v13; // eax
  unsigned int v14; // edi
  unsigned __int8 *v15; // eax

  v3 = this;
  if ( object._type <= OT_FLOAT )
  {
    switch ( object._type )
    {
      case OT_FLOAT:
        pReturn->m_type = 1;
        pReturn->m_int = object._unVal.nInteger;
        return 1;
      case OT_NULL:
        pReturn->m_type = 0;
        return 1;
      case OT_BOOL:
        pReturn->m_char = object._unVal.nInteger != 0;
        pReturn->m_type = 6;
        return 1;
      case OT_INTEGER:
        pReturn->m_type = 5;
        pReturn->m_int = object._unVal.nInteger;
        return 1;
      default:
        break;
    }
    goto LABEL_25;
  }
  if ( object._type == OT_STRING )
  {
    v14 = *(_DWORD *)(object._unVal.nInteger + 20);
    pReturn->m_type = 32;
    v15 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: ++v14);
    pReturn->m_int = (int)v15;
    memcpy(dst: v15, src: (unsigned __int8 *)(object._unVal.nInteger + 28), count: v14);
    pReturn->m_flags |= 1u;
    return 1;
  }
  else
  {
    if ( object._type != OT_INSTANCE )
      goto LABEL_25;
    sq_pushobject(v: this->m_hVM, obj: (tagSQObject)__PAIR64__(object._unVal.raw, 167804928));
    m_hVM = this->m_hVM;
    v6 = &m_hVM->_stack._vals[m_hVM->_top - 1];
    if ( v6->_type == OT_INSTANCE )
    {
      v8.pTable = (SQTable *)v6->_unVal;
      v9 = *(CSquirrelVM **)(v8.nInteger + 32);
      v10 = *(_DWORD *)(v8.nInteger + 28);
      this = v9;
      while ( *(_DWORD *)(v10 + 76) != 1 )
      {
        v10 = *(_DWORD *)(v10 + 28);
        if ( v10 == 0 )
        {
          v7 = "invalid type tag";
          goto LABEL_18;
        }
      }
      v11 = 0;
    }
    else
    {
      v7 = "the object is not a class instance";
LABEL_18:
      v11 = sq_throwerror(v: m_hVM, err: v7);
    }
    SQVM::Pop(this: v3->m_hVM);
    if ( v11 != 0 )
    {
LABEL_25:
      pReturn->m_type = 33;
      v13 = (tagSQObject *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8);
      *v13 = object;
      pReturn->m_int = (int)v13;
      return 1;
    }
    pReturn->m_type = 3;
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
    if ( v12 != nullptr )
    {
      *(_QWORD *)v12 = *(_QWORD *)&this->__vftable;
      v12[2] = this->m_hDbg;
      pReturn->m_flags |= 1u;
      pReturn->m_int = (int)v12;
    }
    else
    {
      pReturn->m_flags |= 1u;
      pReturn->m_int = 0;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BBD0
// Name: private: void CSquirrelVM::WriteObject(struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::WriteObject(CSquirrelVM *this, const SQObjectPtr *object)
{
  tagSQObjectType type; // eax
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v5; // ecx
  CUtlBuffer *v6; // esi
  float src; // xmm0_4
  __int32 v8; // eax
  __int32 v9; // eax
  __int32 v10; // eax
  __int32 v11; // eax

  type = object->_type;
  if ( object->_type > OT_NATIVECLOSURE )
  {
    if ( type > OT_WEAKREF )
    {
      v10 = type - 167772192;
      if ( v10 != 0 )
      {
        v11 = v10 - 96;
        if ( v11 != 0 )
        {
          if ( v11 == 32640 )
            CSquirrelVM::WriteInstance(this, pInstance: object->_unVal.pInstance);
        }
        else
        {
          CSquirrelVM::WriteUserData(this, pUserData: object->_unVal.pUserData);
        }
      }
      else
      {
        CSquirrelVM::WriteTable(this, pTable: object->_unVal.pTable);
      }
    }
    else if ( type == OT_WEAKREF )
    {
      CSquirrelVM::WriteWeakRef(this, pWeakRef: object->_unVal.pWeakRef);
    }
    else if ( type > OT_FUNCPROTO )
    {
      if ( type == OT_CLASS )
        CSquirrelVM::WriteClass(this, pClass: object->_unVal.pClass);
    }
    else
    {
      switch ( type )
      {
        case OT_FUNCPROTO:
          CSquirrelVM::WriteFuncProto(this, pFuncProto: object->_unVal.pFunctionProto);
          break;
        case OT_GENERATOR:
          CSquirrelVM::WriteGenerator(this, pGenerator: object->_unVal.pGenerator);
          break;
        case OT_THREAD:
          CSquirrelVM::WriteVM(this, pVM: object->_unVal.pThread);
          break;
        default:
          break;
      }
    }
  }
  else if ( object->_type == OT_NATIVECLOSURE )
  {
    CSquirrelVM::WriteNativeClosure(this, pNativeClosure: object->_unVal.pNativeClosure);
  }
  else if ( type > OT_FLOAT )
  {
    v8 = type - 134217744;
    if ( v8 != 0 )
    {
      v9 = v8 - 48;
      if ( v9 != 0 )
      {
        if ( v9 == 192 )
          CSquirrelVM::WriteClosure(this, pClosure: object->_unVal.pClosure);
      }
      else
      {
        CSquirrelVM::WriteArray(this: (CSquirrelVM *)object->_unVal.pTable, pArray: (SQArray *)this);
      }
    }
    else
    {
      CUtlBuffer::PutInt(this: this->m_pBuffer, i: (void *)0x8000010);
      CUtlBuffer::PutInt(this: this->m_pBuffer, i: *(void **)(object->_unVal.nInteger + 20));
      CUtlBuffer::PutString(this: this->m_pBuffer, pString: (const char *)(object->_unVal.nInteger + 28));
    }
  }
  else if ( type == OT_FLOAT )
  {
    m_pBuffer = this->m_pBuffer;
    if ( (m_pBuffer->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 83886084);
    else
      CUtlBuffer::PutTypeBin<void *>((CUtlBuffer *)this, src: (void *)0x5000004);
    v6 = this->m_pBuffer;
    src = object->_unVal.fFloat;
    if ( (v6->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v6, pFmt: "%f", src);
    else
      CUtlBuffer::PutTypeBin<float>(this: v5, src);
  }
  else if ( type > OT_BOOL )
  {
    if ( type == OT_INTEGER )
    {
      CUtlBuffer::PutInt(this: this->m_pBuffer, i: (void *)0x5000002);
      CUtlBuffer::PutInt(this: this->m_pBuffer, i: object->_unVal.pTable);
    }
  }
  else
  {
    switch ( type )
    {
      case OT_BOOL:
        CUtlBuffer::PutInt(this: this->m_pBuffer, i: (void *)0x1000008);
        CUtlBuffer::PutInt(this: this->m_pBuffer, i: object->_unVal.pTable);
        break;
      case OT_USERPOINTER:
        CSquirrelVM::WriteUserPointer(this, pUserPointer: object->_unVal.pTable);
        break;
      case OT_NULL:
        CUtlBuffer::PutInt(this: this->m_pBuffer, i: (void *)0x1000001);
        break;
      default:
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BE30
// Name: private: void CSquirrelVM::WriteVM(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteVM(SQVM *pVM@<edi>, CUtlBuffer *a2@<ecx>, CSquirrelVM *this)
{
  CSquirrelVM *v3; // ebx
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v5; // ecx
  CUtlBuffer *v6; // esi
  int uiRef; // eax
  CUtlBuffer *v8; // ecx
  CUtlBuffer *v9; // esi
  CUtlBuffer *v10; // ecx
  CUtlBuffer *v11; // esi
  CUtlBuffer *v12; // ecx
  CUtlBuffer *v13; // esi
  unsigned int i; // esi
  CUtlBuffer *v15; // esi
  unsigned int j; // esi
  void *top; // [esp-4h] [ebp-10h]
  void *stackbase; // [esp-4h] [ebp-10h]
  void *size; // [esp-4h] [ebp-10h]
  unsigned int v20; // [esp+8h] [ebp-4h]

  v3 = this;
  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 134221824);
  else
    CUtlBuffer::PutTypeBin<void *>(this: a2, src: (void *)0x8001000);
  v6 = v3->m_pBuffer;
  if ( (v6->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v6, pFmt: "0x%p", pVM);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v5, src: pVM);
  uiRef = pVM->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    pVM->_uiRef = uiRef | 0x40000000;
    CSquirrelVM::WriteObject(this: v3, object: &pVM->_roottable);
    v9 = v3->m_pBuffer;
    top = (void *)pVM->_top;
    if ( (v9->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v9, pFmt: "%d", top);
    else
      CUtlBuffer::PutTypeBin<void *>(this: v8, src: top);
    v11 = v3->m_pBuffer;
    stackbase = (void *)pVM->_stackbase;
    if ( (v11->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v11, pFmt: "%d", stackbase);
    else
      CUtlBuffer::PutTypeBin<void *>(this: v10, src: stackbase);
    v13 = v3->m_pBuffer;
    size = (void *)pVM->_stack._size;
    if ( (v13->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v13, pFmt: "%u", size);
    else
      CUtlBuffer::PutTypeBin<void *>(this: v12, src: size);
    for ( i = 0; i < pVM->_stack._size; ++i )
      CSquirrelVM::WriteObject(this: v3, object: &pVM->_stack._vals[i]);
    v15 = v3->m_pBuffer;
    v20 = pVM->_vargsstack._size;
    if ( (v15->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v15, pFmt: "%u", pVM->_vargsstack._size);
    }
    else
    {
      this = (CSquirrelVM *)pVM->_vargsstack._size;
      if ( CUtlBuffer::CheckPut(this: v15, nSize: 4) )
      {
        if ( (*(_BYTE *)&v15->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<void *>(
            this: &v15->m_Byteswap,
            outputBuffer: (unsigned int *)&v15->m_Memory.m_pMemory[v15->m_Put - v15->m_nOffset],
            inputBuffer: (unsigned int *)&this,
            count: 1);
        else
          *(_DWORD *)&v15->m_Memory.m_pMemory[v15->m_Put - v15->m_nOffset] = v20;
        v15->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v15, nPut: v15->m_Put);
      }
    }
    for ( j = 0; j < pVM->_vargsstack._size; ++j )
      CSquirrelVM::WriteObject(this: v3, object: &pVM->_vargsstack._vals[j]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BFD0
// Name: private: void CSquirrelVM::WriteArray(struct SQArray __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::WriteArray(CSquirrelVM *this, CSquirrelVM *pArray, SQArray *pArraya)
{
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v4; // ecx
  CUtlBuffer *v5; // esi
  CUtlBuffer *v6; // ecx
  int uiRef; // eax
  void *size; // edi
  CUtlBuffer *v9; // esi
  int i; // esi

  m_pBuffer = pArray->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 134217792);
  else
    CUtlBuffer::PutTypeBin<void *>((CUtlBuffer *)this, src: (void *)0x8000040);
  v5 = pArray->m_pBuffer;
  if ( (v5->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v5, pFmt: "0x%p", pArraya);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v4, src: pArraya);
  uiRef = pArraya->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    size = (void *)pArraya->_values._size;
    pArraya->_uiRef = uiRef | 0x40000000;
    v9 = pArray->m_pBuffer;
    if ( (v9->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v9, pFmt: "%d", size);
    else
      CUtlBuffer::PutTypeBin<void *>(this: v6, src: size);
    for ( i = 0; i < (int)size; ++i )
      CSquirrelVM::WriteObject(this: pArray, object: &pArraya->_values._vals[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C080
// Name: private: void CSquirrelVM::WriteTable(struct SQTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteTable(SQTable *pTable@<edi>, CUtlBuffer *a2@<ecx>, CSquirrelVM *this)
{
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v5; // ecx
  CUtlBuffer *v6; // esi
  CUtlBuffer *v7; // ecx
  int uiRef; // eax
  CUtlBuffer *v9; // esi
  CUtlBuffer *v10; // ecx
  SQTable *delegate; // eax
  tagSQObjectValue v12; // eax
  void *numofnodes; // esi
  CUtlBuffer *v14; // eax
  int v15; // esi
  BOOL v16; // [esp-4h] [ebp-14h]
  SQObjectPtr object; // [esp+8h] [ebp-8h] BYREF
  int len; // [esp+18h] [ebp+8h]

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 167772192);
  else
    CUtlBuffer::PutTypeBin<void *>(this: a2, src: (void *)0xA000020);
  v6 = this->m_pBuffer;
  if ( (v6->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v6, pFmt: "0x%p", pTable);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v5, src: pTable);
  uiRef = pTable->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    pTable->_uiRef = uiRef | 0x40000000;
    v9 = this->m_pBuffer;
    v16 = pTable->_delegate != nullptr;
    if ( (v9->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v9, pFmt: "%d", v16);
    else
      CUtlBuffer::PutTypeBin<void *>(this: v7, src: (void *)v16);
    delegate = pTable->_delegate;
    if ( delegate != nullptr )
    {
      object._unVal.nInteger = (int)pTable->_delegate;
      object._type = OT_TABLE;
      ++delegate->_uiRef;
      CSquirrelVM::WriteObject(this, &object);
      if ( (object._type & 0x8000000) != 0 )
      {
        v12.pTable = (SQTable *)object._unVal;
        --*(_DWORD *)(object._unVal.nInteger + 4);
        if ( *(int *)(v12.nInteger + 4) <= 0 )
          object._unVal.pTable->Release(this: (struct SQTable *)object._unVal.nInteger);
      }
    }
    numofnodes = (void *)pTable->_numofnodes;
    v14 = this->m_pBuffer;
    len = (int)numofnodes;
    if ( (v14->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v14, pFmt: "%d", numofnodes);
    else
      CUtlBuffer::PutTypeBin<void *>(this: v10, src: numofnodes);
    if ( (int)numofnodes > 0 )
    {
      v15 = 0;
      do
      {
        CSquirrelVM::WriteObject(this, object: &pTable->_nodes[v15].key);
        CSquirrelVM::WriteObject(this, object: &pTable->_nodes[v15++].val);
        --len;
      }
      while ( len != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C1C0
// Name: private: void CSquirrelVM::WriteClass(struct SQClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteClass(SQClass *pClass@<edi>, CUtlBuffer *a2@<ecx>, CSquirrelVM *this)
{
  CSquirrelVM *v3; // ebx
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v5; // ecx
  CUtlBuffer *v6; // esi
  CUtlBuffer *vals; // ecx
  int uiRef; // eax
  bool v9; // zf
  bool v10; // dl
  unsigned int v11; // eax
  CUtlBuffer *v12; // esi
  CUtlBuffer *v13; // ecx
  CUtlBuffer *v14; // esi
  SQClass *base; // eax
  tagSQObjectValue v16; // eax
  SQTable *members; // eax
  tagSQObjectValue v18; // eax
  CUtlBuffer *v19; // ecx
  CUtlBuffer *v20; // esi
  int v21; // esi
  CUtlBuffer *v22; // esi
  CSquirrelVM *v23; // eax
  int v24; // esi
  CUtlBuffer *v25; // esi
  CSquirrelVM *v26; // eax
  unsigned int i; // esi
  const char **typetag; // eax
  CUtlBuffer *v29; // ecx
  bool KeyForObject; // al
  CUtlBuffer *v31; // ecx
  tagSQObjectValue v32; // eax
  const SQObjectPtr *p_roottable; // [esp-Ch] [ebp-1Ch]
  BOOL v34; // [esp-4h] [ebp-14h]
  void *size; // [esp-4h] [ebp-14h]
  SQObjectPtr key; // [esp+8h] [ebp-8h] BYREF

  v3 = this;
  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 134234112);
  else
    CUtlBuffer::PutTypeBin<void *>(this: a2, src: (void *)0x8004000);
  v6 = v3->m_pBuffer;
  if ( (v6->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v6, pFmt: "0x%p", pClass);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v5, src: pClass);
  if ( pClass != nullptr )
  {
    uiRef = pClass->_uiRef;
    if ( (uiRef & 0x40000000) == 0 )
    {
      v9 = pClass->_typetag == nullptr;
      pClass->_uiRef = uiRef | 0x40000000;
      v10 = !v9;
      HIBYTE(this) = !v9;
      if ( v9 )
      {
        v11 = 0;
        if ( pClass->_methods._size != 0 )
        {
          vals = (CUtlBuffer *)pClass->_methods._vals;
          while ( vals->m_Memory.m_pMemory != (unsigned __int8 *)134218240 )
          {
            ++v11;
            vals = (CUtlBuffer *)((char *)vals + 16);
            if ( v11 >= pClass->_methods._size )
              goto LABEL_16;
          }
          HIBYTE(this) = 1;
          v10 = true;
        }
      }
LABEL_16:
      v12 = v3->m_pBuffer;
      if ( (v12->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v12, pFmt: "%d", v10);
      else
        CUtlBuffer::PutTypeBin<void *>(this: vals, src: (void *)v10);
      if ( HIBYTE(this) != 0 )
      {
        typetag = (const char **)pClass->_typetag;
        if ( typetag != nullptr )
        {
          v29 = v3->m_pBuffer;
          if ( typetag == (const char **)1 )
            CUtlBuffer::PutString(this: v29, pString: "Vector");
          else
            CUtlBuffer::PutString(this: v29, pString: *typetag);
        }
        else
        {
          p_roottable = &v3->m_hVM->_roottable;
          key._type = OT_NULL;
          key._unVal.nInteger = 0;
          KeyForObject = CSquirrelVM::FindKeyForObject(this: v3, table: p_roottable, p: pClass, &key);
          v31 = v3->m_pBuffer;
          if ( KeyForObject )
            CUtlBuffer::PutString(this: v31, pString: (const char *)(key._unVal.nInteger + 28));
          else
            CUtlBuffer::PutString(this: v31, pString: Ptr);
          if ( (key._type & 0x8000000) != 0 )
          {
            v32.pTable = (SQTable *)key._unVal;
            --*(_DWORD *)(key._unVal.nInteger + 4);
            if ( *(int *)(v32.nInteger + 4) <= 0 )
              key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
          }
        }
      }
      else
      {
        v14 = v3->m_pBuffer;
        v34 = pClass->_base != nullptr;
        if ( (v14->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v14, pFmt: "%d", v34);
        else
          CUtlBuffer::PutTypeBin<void *>(this: v13, src: (void *)v34);
        base = pClass->_base;
        if ( base != nullptr )
        {
          key._unVal.nInteger = (int)pClass->_base;
          key._type = OT_CLASS;
          ++base->_uiRef;
          CSquirrelVM::WriteObject(this: v3, object: &key);
          if ( (key._type & 0x8000000) != 0 )
          {
            v16.pTable = (SQTable *)key._unVal;
            --*(_DWORD *)(key._unVal.nInteger + 4);
            if ( *(int *)(v16.nInteger + 4) <= 0 )
              key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
          }
        }
        members = pClass->_members;
        key._type = OT_TABLE;
        key._unVal.nInteger = (int)members;
        ++members->_uiRef;
        CSquirrelVM::WriteObject(this: v3, object: &key);
        if ( (key._type & 0x8000000) != 0 )
        {
          v18.pTable = (SQTable *)key._unVal;
          --*(_DWORD *)(key._unVal.nInteger + 4);
          if ( *(int *)(v18.nInteger + 4) <= 0 )
            key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
        }
        CSquirrelVM::WriteObject(this: v3, object: &pClass->_attributes);
        v20 = v3->m_pBuffer;
        size = (void *)pClass->_defaultvalues._size;
        if ( (v20->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v20, pFmt: "%d", size);
        else
          CUtlBuffer::PutTypeBin<void *>(this: v19, src: size);
        v21 = 0;
        for ( this = nullptr; (unsigned int)this < pClass->_defaultvalues._size; this = (CSquirrelVM *)((char *)this + 1) )
        {
          CSquirrelVM::WriteObject(this: v3, object: &pClass->_defaultvalues._vals[v21].val);
          CSquirrelVM::WriteObject(this: v3, object: &pClass->_defaultvalues._vals[v21++].attrs);
        }
        v22 = v3->m_pBuffer;
        v9 = (v22->m_Flags & 1) == 0;
        v23 = (CSquirrelVM *)pClass->_methods._size;
        key._unVal.nInteger = (int)v23;
        if ( v9 )
        {
          this = v23;
          if ( CUtlBuffer::CheckPut(this: v22, nSize: 4) )
          {
            if ( (*(_BYTE *)&v22->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<void *>(
                this: &v22->m_Byteswap,
                outputBuffer: (unsigned int *)&v22->m_Memory.m_pMemory[v22->m_Put - v22->m_nOffset],
                inputBuffer: (unsigned int *)&this,
                count: 1);
            else
              *(_DWORD *)&v22->m_Memory.m_pMemory[v22->m_Put - v22->m_nOffset] = key._unVal.pTable;
            v22->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v22, nPut: v22->m_Put);
          }
        }
        else
        {
          CUtlBuffer::Printf(this: v22, pFmt: "%d", v23);
        }
        v24 = 0;
        for ( this = nullptr; (unsigned int)this < pClass->_methods._size; this = (CSquirrelVM *)((char *)this + 1) )
        {
          CSquirrelVM::WriteObject(this: v3, object: &pClass->_methods._vals[v24].val);
          CSquirrelVM::WriteObject(this: v3, object: &pClass->_methods._vals[v24++].attrs);
        }
        v25 = v3->m_pBuffer;
        v9 = (v25->m_Flags & 1) == 0;
        v26 = (CSquirrelVM *)pClass->_metamethods._size;
        key._unVal.nInteger = (int)v26;
        if ( v9 )
        {
          this = v26;
          if ( CUtlBuffer::CheckPut(this: v25, nSize: 4) )
          {
            if ( (*(_BYTE *)&v25->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<void *>(
                this: &v25->m_Byteswap,
                outputBuffer: (unsigned int *)&v25->m_Memory.m_pMemory[v25->m_Put - v25->m_nOffset],
                inputBuffer: (unsigned int *)&this,
                count: 1);
            else
              *(_DWORD *)&v25->m_Memory.m_pMemory[v25->m_Put - v25->m_nOffset] = key._unVal.pTable;
            v25->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v25, nPut: v25->m_Put);
          }
        }
        else
        {
          CUtlBuffer::Printf(this: v25, pFmt: "%d", v26);
        }
        for ( i = 0; i < pClass->_metamethods._size; ++i )
          CSquirrelVM::WriteObject(this: v3, object: &pClass->_metamethods._vals[i]);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C590
// Name: private: void CSquirrelVM::WriteInstance(struct SQInstance __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteInstance(
        CSquirrelVM *this@<ecx>,
        CSquirrelVM *a2@<eax>,
        tagSQObjectValue *pInstance)
{
  tagSQObjectValue *v3; // ebx
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v6; // ecx
  CUtlBuffer *v7; // esi
  tagSQObjectValue v8; // eax
  tagSQObjectValue v9; // eax
  CUtlBuffer *pTable; // ecx
  SQInstance *m_GetOverflowFunc; // esi
  CUtlBuffer *v12; // eax
  bool v13; // zf
  const SQObjectPtr *v14; // esi
  CUtlBuffer *v15; // esi
  SQInstance *v16; // eax
  CUtlBuffer *v17; // ecx
  int v18; // eax
  tagSQObjectValue v19; // ebx
  CUtlBuffer *v20; // esi
  float v21; // xmm0_4
  CUtlBuffer *v22; // ecx
  CUtlBuffer *v23; // esi
  float v24; // xmm0_4
  CUtlBuffer *v25; // ecx
  CUtlBuffer *v26; // edi
  float v27; // xmm0_4
  CUtlBuffer *v28; // ecx
  CUtlBuffer *v29; // esi
  CUtlBuffer *v30; // esi
  CUtlBuffer *v31; // edi
  SQTable_vtbl *src; // [esp+4h] [ebp-18h]
  SQObjectPtr object; // [esp+14h] [ebp-8h] BYREF

  v3 = pInstance;
  m_pBuffer = a2->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 167804928);
  else
    CUtlBuffer::PutTypeBin<void *>((CUtlBuffer *)this, src: (void *)0xA008000);
  v7 = a2->m_pBuffer;
  if ( (v7->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v7, pFmt: "0x%p", v3);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v6, src: v3);
  v8.pTable = v3[1].pTable;
  if ( (v8.nInteger & 0x40000000) != 0 )
    return;
  v3[1].nInteger = v8.nInteger | 0x40000000;
  object._unVal = v3[7];
  object._type = OT_CLASS;
  ++*(_DWORD *)(object._unVal.nInteger + 4);
  CSquirrelVM::WriteObject(this: a2, &object);
  if ( (object._type & 0x8000000) != 0 )
  {
    v9.pTable = (SQTable *)object._unVal;
    --*(_DWORD *)(object._unVal.nInteger + 4);
    if ( *(int *)(v9.nInteger + 4) <= 0 )
      object._unVal.pTable->Release(this: (struct SQTable *)object._unVal.nInteger);
  }
  pTable = (CUtlBuffer *)v3[7].pTable;
  m_GetOverflowFunc = (SQInstance *)pTable->m_GetOverflowFunc;
  v12 = a2->m_pBuffer;
  v13 = (v12->m_Flags & 1) == 0;
  pInstance = (tagSQObjectValue *)m_GetOverflowFunc;
  if ( v13 )
  {
    CUtlBuffer::PutTypeBin<void *>(this: pTable, src: m_GetOverflowFunc);
    m_GetOverflowFunc = (SQInstance *)pInstance;
  }
  else
  {
    CUtlBuffer::Printf(this: v12, pFmt: "%d", m_GetOverflowFunc);
  }
  if ( m_GetOverflowFunc != nullptr )
  {
    v14 = (const SQObjectPtr *)&v3[11];
    do
    {
      CSquirrelVM::WriteObject(this: a2, object: v14++);
      pInstance = (tagSQObjectValue *)((char *)pInstance - 1);
    }
    while ( pInstance != nullptr );
  }
  v15 = a2->m_pBuffer;
  v13 = (v15->m_Flags & 1) == 0;
  v16 = *(SQInstance **)(v3[7].nInteger + 76);
  object._unVal.nInteger = (int)v16;
  if ( v13 )
  {
    pInstance = (tagSQObjectValue *)v16;
    if ( CUtlBuffer::CheckPut(this: v15, nSize: 4) )
    {
      if ( (*(_BYTE *)&v15->m_Byteswap & 1) != 0 )
        CByteswap::SwapBufferToTargetEndian<void *>(
          this: &v15->m_Byteswap,
          outputBuffer: (unsigned int *)&v15->m_Memory.m_pMemory[v15->m_Put - v15->m_nOffset],
          inputBuffer: (unsigned int *)&pInstance,
          count: 1);
      else
        *(_DWORD *)&v15->m_Memory.m_pMemory[v15->m_Put - v15->m_nOffset] = object._unVal.pTable;
      v15->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v15, nPut: v15->m_Put);
    }
  }
  else
  {
    CUtlBuffer::Printf(this: v15, pFmt: "0x%p", v16);
  }
  v18 = *(_DWORD *)(v3[7].nInteger + 76);
  if ( v18 == 0 )
  {
    v30 = a2->m_pBuffer;
    if ( (v30->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v30, pFmt: "%d", 2048);
    else
      CUtlBuffer::PutTypeBin<void *>(this: v17, src: (void *)0x800);
    v31 = a2->m_pBuffer;
    src = nullptr;
    if ( (v31->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v31, pFmt: "0x%p", nullptr);
      return;
    }
LABEL_41:
    CUtlBuffer::PutTypeBin<void *>(this: v28, src);
    return;
  }
  v19.pTable = v3[8].pTable;
  if ( v18 != 1 )
  {
    CSquirrelVM::WriteObject(this: a2, object: (const SQObjectPtr *)(v19.nInteger + 8));
    v29 = a2->m_pBuffer;
    src = v19.pTable->__vftable;
    if ( (v29->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v29, pFmt: "0x%p", src);
      return;
    }
    goto LABEL_41;
  }
  v20 = a2->m_pBuffer;
  v21 = *(float *)&v19.pTable->__vftable;
  if ( (v20->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v20, pFmt: "%f", v21);
  else
    CUtlBuffer::PutTypeBin<float>(this: v17, src: v21);
  v23 = a2->m_pBuffer;
  v24 = *(float *)(v19.nInteger + 4);
  if ( (v23->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v23, pFmt: "%f", v24);
  else
    CUtlBuffer::PutTypeBin<float>(this: v22, src: v24);
  v26 = a2->m_pBuffer;
  v27 = *(float *)(v19.nInteger + 8);
  if ( (v26->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v26, pFmt: "%f", v27);
  else
    CUtlBuffer::PutTypeBin<float>(this: v25, src: v27);
}

//------------------------------------------------------------------------------
// Address: 0x1002C860
// Name: private: void CSquirrelVM::WriteGenerator(struct SQGenerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteGenerator(SQGenerator *pGenerator@<edi>, CSquirrelVM *this)
{
  CSquirrelVM *v2; // ebx
  CUtlBuffer *v3; // ecx
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v5; // ecx
  CUtlBuffer *v6; // esi
  int uiRef; // eax
  CUtlBuffer *v8; // ecx
  CUtlBuffer *v9; // esi
  unsigned int i; // esi
  CUtlBuffer *v11; // esi
  unsigned int j; // esi
  void *size; // [esp-4h] [ebp-10h]
  unsigned int v14; // [esp+8h] [ebp-4h]

  v2 = this;
  if ( `CSquirrelVM::WriteGenerator'::`3'::__executeCount < 1 )
  {
    ++`CSquirrelVM::WriteGenerator'::`3'::__executeCount;
    _Msg(a1: &stru_1009B330.m_szBuf[51]);
  }
  CSquirrelVM::WriteObject(this: v2, object: &pGenerator->_closure);
  m_pBuffer = v2->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 134218752);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v3, src: (void *)0x8000400);
  v6 = v2->m_pBuffer;
  if ( (v6->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v6, pFmt: "0x%p", pGenerator);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v5, src: pGenerator);
  uiRef = pGenerator->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    pGenerator->_uiRef = uiRef | 0x40000000;
    CSquirrelVM::WriteObject(this: v2, object: &pGenerator->_closure);
    v9 = v2->m_pBuffer;
    size = (void *)pGenerator->_stack._size;
    if ( (v9->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v9, pFmt: "%d", size);
    else
      CUtlBuffer::PutTypeBin<void *>(this: v8, src: size);
    for ( i = 0; i < pGenerator->_stack._size; ++i )
      CSquirrelVM::WriteObject(this: v2, object: &pGenerator->_stack._vals[i]);
    v11 = v2->m_pBuffer;
    v14 = pGenerator->_vargsstack._size;
    if ( (v11->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v11, pFmt: "%d", pGenerator->_vargsstack._size);
    }
    else
    {
      this = (CSquirrelVM *)pGenerator->_vargsstack._size;
      if ( CUtlBuffer::CheckPut(this: v11, nSize: 4) )
      {
        if ( (*(_BYTE *)&v11->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<void *>(
            this: &v11->m_Byteswap,
            outputBuffer: (unsigned int *)&v11->m_Memory.m_pMemory[v11->m_Put - v11->m_nOffset],
            inputBuffer: (unsigned int *)&this,
            count: 1);
        else
          *(_DWORD *)&v11->m_Memory.m_pMemory[v11->m_Put - v11->m_nOffset] = v14;
        v11->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v11, nPut: v11->m_Put);
      }
    }
    for ( j = 0; j < pGenerator->_vargsstack._size; ++j )
      CSquirrelVM::WriteObject(this: v2, object: &pGenerator->_vargsstack._vals[j]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C9F0
// Name: private: void CSquirrelVM::WriteClosure(struct SQClosure __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteClosure(SQClosure *pClosure@<edi>, CUtlBuffer *a2@<ecx>, CSquirrelVM *this)
{
  CSquirrelVM *v3; // ebx
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v5; // ecx
  CUtlBuffer *v6; // esi
  int uiRef; // eax
  CUtlBuffer *v8; // ecx
  CUtlBuffer *v9; // esi
  unsigned int i; // esi
  CUtlBuffer *v11; // esi
  unsigned int j; // esi
  void *size; // [esp-4h] [ebp-10h]
  unsigned int v14; // [esp+8h] [ebp-4h]

  v3 = this;
  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 134217984);
  else
    CUtlBuffer::PutTypeBin<void *>(this: a2, src: (void *)0x8000100);
  v6 = v3->m_pBuffer;
  if ( (v6->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v6, pFmt: "0x%p", pClosure);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v5, src: pClosure);
  uiRef = pClosure->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    pClosure->_uiRef = uiRef | 0x40000000;
    CSquirrelVM::WriteObject(this: v3, object: &pClosure->_function);
    CSquirrelVM::WriteObject(this: v3, object: &pClosure->_env);
    v9 = v3->m_pBuffer;
    size = (void *)pClosure->_outervalues._size;
    if ( (v9->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v9, pFmt: "%d", size);
    else
      CUtlBuffer::PutTypeBin<void *>(this: v8, src: size);
    for ( i = 0; i < pClosure->_outervalues._size; ++i )
      CSquirrelVM::WriteObject(this: v3, object: &pClosure->_outervalues._vals[i]);
    v11 = v3->m_pBuffer;
    v14 = pClosure->_defaultparams._size;
    if ( (v11->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v11, pFmt: "%d", pClosure->_defaultparams._size);
    }
    else
    {
      this = (CSquirrelVM *)pClosure->_defaultparams._size;
      if ( CUtlBuffer::CheckPut(this: v11, nSize: 4) )
      {
        if ( (*(_BYTE *)&v11->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<void *>(
            this: &v11->m_Byteswap,
            outputBuffer: (unsigned int *)&v11->m_Memory.m_pMemory[v11->m_Put - v11->m_nOffset],
            inputBuffer: (unsigned int *)&this,
            count: 1);
        else
          *(_DWORD *)&v11->m_Memory.m_pMemory[v11->m_Put - v11->m_nOffset] = v14;
        v11->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v11, nPut: v11->m_Put);
      }
    }
    for ( j = 0; j < pClosure->_defaultparams._size; ++j )
      CSquirrelVM::WriteObject(this: v3, object: &pClosure->_defaultparams._vals[j]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CB60
// Name: private: void CSquirrelVM::WriteNativeClosure(struct SQNativeClosure __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteNativeClosure(
        SQNativeClosure *pNativeClosure@<eax>,
        CUtlBuffer *a2@<ecx>,
        CSquirrelVM *this)
{
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v5; // ecx
  CUtlBuffer *v6; // esi
  int uiRef; // eax

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 134218240);
  else
    CUtlBuffer::PutTypeBin<void *>(this: a2, src: (void *)0x8000200);
  v6 = this->m_pBuffer;
  if ( (v6->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v6, pFmt: "0x%p", pNativeClosure);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v5, src: pNativeClosure);
  uiRef = pNativeClosure->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    pNativeClosure->_uiRef = uiRef | 0x40000000;
    CSquirrelVM::WriteObject(this, object: &pNativeClosure->_name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CBE0
// Name: private: void CSquirrelVM::WriteUserData(struct SQUserData __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteUserData(SQUserData *pUserData@<edi>, CUtlBuffer *a2@<ecx>, CSquirrelVM *this)
{
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v4; // ecx
  CUtlBuffer *v5; // esi
  int uiRef; // eax

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 167772288);
  else
    CUtlBuffer::PutTypeBin<void *>(this: a2, src: (void *)0xA000080);
  v5 = this->m_pBuffer;
  if ( (v5->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v5, pFmt: "0x%p", pUserData);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v4, src: pUserData);
  uiRef = pUserData->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
    pUserData->_uiRef = uiRef | 0x40000000;
}

//------------------------------------------------------------------------------
// Address: 0x1002CC50
// Name: private: void CSquirrelVM::WriteUserPointer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteUserPointer(CSquirrelVM *this@<ecx>, int a2@<edi>, void *pUserPointer)
{
  CUtlBuffer *v3; // esi
  CUtlBuffer *v4; // ecx
  CUtlBuffer *v5; // esi

  v3 = *(CUtlBuffer **)(a2 + 136);
  if ( (v3->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v3, pFmt: "%d", 2048);
  else
    CUtlBuffer::PutTypeBin<void *>((CUtlBuffer *)this, src: (void *)0x800);
  v5 = *(CUtlBuffer **)(a2 + 136);
  if ( (v5->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v5, pFmt: "0x%p", pUserPointer);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v4, src: pUserPointer);
}

//------------------------------------------------------------------------------
// Address: 0x1002CCB0
// Name: private: static int CSquirrelVM::SqWriteFunc(void __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::SqWriteFunc(CUtlBuffer **up, void *data, int size)
{
  CUtlBuffer::Put(this: up[34], pMem: data, size);
  return size;
}

//------------------------------------------------------------------------------
// Address: 0x1002CCD0
// Name: private: void CSquirrelVM::WriteFuncProto(struct SQFunctionProto __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::WriteFuncProto(
        SQFunctionProto *pFuncProto@<edi>,
        CUtlBuffer *a2@<ecx>,
        CSquirrelVM *this)
{
  CUtlBuffer *m_pBuffer; // esi
  CUtlBuffer *v4; // ecx
  CUtlBuffer *v5; // esi
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v6; // ecx
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v7; // ecx
  CUtlMap<void *,void *,unsigned short>::Node_t *p_m_Data; // eax
  CUtlMap<void *,void *,unsigned short>::Node_t parent; // [esp+8h] [ebp-Ch] BYREF
  bool leftchild[4]; // [esp+10h] [ebp-4h] BYREF

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 134225920);
  else
    CUtlBuffer::PutTypeBin<void *>(this: a2, src: (void *)0x8002000);
  v5 = this->m_pBuffer;
  if ( (v5->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v5, pFmt: "0x%p", pFuncProto);
  else
    CUtlBuffer::PutTypeBin<void *>(this: v4, src: pFuncProto);
  parent.key = pFuncProto;
  if ( CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: v6,
         search: (const CUtlMap<void *,void *,unsigned short>::Node_t *)&this->m_PtrMap) == 0xFFFF )
  {
    *(_DWORD *)leftchild = 0xFFFF;
    parent.key = pFuncProto;
    parent.elem = pFuncProto;
    CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&parent,
      insert: (const CUtlMap<void *,void *,unsigned short>::Node_t *)&this->m_PtrMap,
      (unsigned __int16 *)&parent,
      leftchild);
    p_m_Data = &this->m_PtrMap.m_Tree.m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertAt(
                                                             this: v7,
                                                             parent: *(unsigned __int16 *)leftchild,
                                                             leftchild: false)].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = parent;
    SQFunctionProto::Save(
      this: pFuncProto,
      v: this->m_hVM,
      up: this,
      write: (int (__cdecl *)(void *, void *, int))CSquirrelVM::SqWriteFunc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CDB0
// Name: private: void CSquirrelVM::WriteWeakRef(struct SQWeakRef __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::WriteWeakRef(CSquirrelVM *this, SQWeakRef *pWeakRef)
{
  CUtlBuffer *m_pBuffer; // esi
  _DWORD *v4; // esi
  __int32 v5; // edi
  SQObjectPtr object; // [esp+Ch] [ebp-8h] BYREF

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", 134283264);
  else
    CUtlBuffer::PutTypeBin<void *>((CUtlBuffer *)this, src: (void *)0x8010000);
  v4 = &pWeakRef->_obj._unVal.pTable->__vftable;
  object._type = pWeakRef->_obj._type;
  v5 = object._type & 0x8000000;
  object._unVal.nInteger = (int)v4;
  if ( (object._type & 0x8000000) != 0 )
    ++v4[1];
  CSquirrelVM::WriteObject(this, &object);
  if ( v5 != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1002CE30
// Name: private: void CSquirrelVM::MapPtr(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::MapPtr(unsigned int pOld@<eax>, unsigned int pNew@<ecx>, CSquirrelVM *this)
{
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v3; // ecx
  CUtlMap<void *,void *,unsigned short>::Node_t *p_m_Data; // eax
  CUtlMap<void *,void *,unsigned short>::Node_t parent; // [esp+4h] [ebp-10h] BYREF
  unsigned __int16 leftchild[4]; // [esp+Ch] [ebp-8h] BYREF

  parent = (CUtlMap<void *,void *,unsigned short>::Node_t)__PAIR64__(pNew, pOld);
  *(_DWORD *)leftchild = 0xFFFF;
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&parent,
    insert: (const CUtlMap<void *,void *,unsigned short>::Node_t *)&this->m_PtrMap,
    (unsigned __int16 *)&parent,
    (bool *)leftchild);
  p_m_Data = &this->m_PtrMap.m_Tree.m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertAt(
                                                           this: v3,
                                                           parent: leftchild[0],
                                                           leftchild: false)].m_Data;
  if ( p_m_Data != nullptr )
    *p_m_Data = parent;
}

//------------------------------------------------------------------------------
// Address: 0x1002CEA0
// Name: private: bool CSquirrelVM::ReadObject(struct SQObjectPtr __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSquirrelVM::ReadObject(CSquirrelVM *this, SQObjectPtr *objectOut, char *pszName)
{
  int nInteger; // ebx
  CUtlBuffer *v5; // ecx
  SQInstance *Instance; // esi
  int v7; // esi
  void *v8; // esp
  SQSharedState *sharedstate; // edi
  SQString *v10; // eax
  tagSQObjectType type; // edi
  tagSQObjectType v12; // edx
  _DWORD *v13; // ecx
  SQWeakRef *Table; // eax
  const char *v16; // eax
  char v17[12]; // [esp+0h] [ebp-20h] BYREF
  tagSQObject hExistingObject; // [esp+Ch] [ebp-14h] BYREF
  tagSQObject object; // [esp+14h] [ebp-Ch] BYREF
  bool bResult; // [esp+1Fh] [ebp-1h]

  bResult = true;
  CUtlBuffer::GetType<int>((CUtlBuffer *)this, dest: (int *)&object._unVal);
  nInteger = object._unVal.nInteger;
  v5 = (CUtlBuffer *)(object._unVal.nInteger & 0xFFFFFF);
  object._type = (tagSQObjectType)object._unVal.pTable;
  if ( (object._unVal.nInteger & 0xFFFFFFu) >= 0x20 )
  {
    if ( object._unVal.nInteger > 134225920 )
    {
      if ( object._unVal.nInteger > 167772192 )
      {
        if ( object._unVal.nInteger == 167772288 )
        {
LABEL_32:
          CUtlBuffer::GetType<unsigned int>(this: v5, dest: (unsigned int *)&pszName);
          Instance = nullptr;
          goto LABEL_30;
        }
        if ( object._unVal.nInteger == 167804928 )
        {
          Instance = CSquirrelVM::ReadInstance(this: (CSquirrelVM *)v5);
          if ( Instance != nullptr )
            goto LABEL_14;
          CSquirrelVM::LookupObject(
            hScope: nullptr,
            this,
            pszObject: (tagSQObjectValue *)&hExistingObject,
            bAddRef: pszName,
            bAddRefa: false);
          if ( hExistingObject._type == OT_INSTANCE )
          {
            Instance = hExistingObject._unVal.pInstance;
LABEL_29:
            if ( Instance != nullptr )
              goto LABEL_14;
          }
LABEL_30:
          v16 = SQTypeToString(sqType: nInteger);
          DevMsg(a1: &stru_1009B330.m_szBuf[107], v16);
          object._type = OT_NULL;
          bResult = false;
          goto LABEL_14;
        }
      }
      else
      {
        switch ( object._unVal.nInteger )
        {
          case 0xA000020:
            Table = (SQWeakRef *)CSquirrelVM::ReadTable(this: (CSquirrelVM *)v5);
            goto LABEL_28;
          case 0x8004000:
            Table = (SQWeakRef *)CSquirrelVM::ReadClass(this: (CSquirrelVM *)v5);
            goto LABEL_28;
          case 0x8010000:
            Table = CSquirrelVM::ReadWeakRef(this);
            goto LABEL_28;
          default:
            break;
        }
      }
    }
    else
    {
      if ( object._unVal.nInteger == 134225920 )
      {
        Table = (SQWeakRef *)CSquirrelVM::ReadFuncProto(this: (CSquirrelVM *)v5);
        goto LABEL_28;
      }
      if ( object._unVal.nInteger <= 134218240 )
      {
        if ( object._unVal.nInteger == 134218240 )
        {
          Table = (SQWeakRef *)CSquirrelVM::ReadNativeClosure(this: (CSquirrelVM *)v5);
          goto LABEL_28;
        }
        if ( object._unVal.nInteger != 2048 )
        {
          if ( object._unVal.nInteger == 134217792 )
          {
            Table = (SQWeakRef *)CSquirrelVM::ReadArray(this: (CSquirrelVM *)v5);
            goto LABEL_28;
          }
          if ( object._unVal.nInteger == 134217984 )
          {
            Table = (SQWeakRef *)CSquirrelVM::ReadClosure(this: (CSquirrelVM *)v5);
LABEL_28:
            Instance = (SQInstance *)Table;
            goto LABEL_29;
          }
          goto LABEL_48;
        }
        goto LABEL_32;
      }
      if ( object._unVal.nInteger == 134218752 )
      {
        Table = (SQWeakRef *)CSquirrelVM::ReadGenerator(this: (CSquirrelVM *)v5);
        goto LABEL_28;
      }
      if ( object._unVal.nInteger == 134221824 )
      {
        Table = (SQWeakRef *)CSquirrelVM::ReadVM(this: (CSquirrelVM *)v5);
        goto LABEL_28;
      }
    }
LABEL_48:
    Instance = nullptr;
    goto LABEL_30;
  }
  if ( object._unVal.nInteger > 83886082 )
  {
    if ( object._unVal.nInteger == 83886084 )
    {
      CUtlBuffer::GetType<float>(this: v5, dest: (float *)&pszName);
      object._unVal.nInteger = (int)pszName;
    }
    else if ( object._unVal.nInteger == 134217744 )
    {
      CUtlBuffer::GetType<int>(this: (CUtlBuffer *)&pszName, dest: (int *)&pszName);
      v7 = (int)pszName;
      v8 = alloca((int)(pszName + 1));
      CUtlBuffer::GetString(this: this->m_pBuffer, pString: v17, nMaxChars: (int)(pszName + 1));
      v17[v7] = 0;
      sharedstate = this->m_hVM->_sharedstate;
      v10 = StringTable::Add(this: sharedstate->_stringtable, news: v17, len: v7);
      v10->_sharedstate = sharedstate;
      Instance = (SQInstance *)v10;
      goto LABEL_14;
    }
  }
  else
  {
    switch ( object._unVal.nInteger )
    {
      case 0x5000002:
        goto LABEL_6;
      case 0x1000001:
        Instance = nullptr;
        goto LABEL_14;
      case 0x1000008:
LABEL_6:
        CUtlBuffer::GetType<int>(this: v5, dest: (int *)&pszName);
        Instance = (SQInstance *)pszName;
        goto LABEL_14;
      default:
        break;
    }
  }
  Instance = object._unVal.pInstance;
LABEL_14:
  type = object._type;
  v12 = objectOut->_type;
  v13 = &objectOut->_unVal.pTable->__vftable;
  objectOut->_unVal.nInteger = (int)Instance;
  objectOut->_type = type;
  if ( (type & 0x8000000) != 0 )
    ++Instance->_uiRef;
  if ( (v12 & 0x8000000) != 0 && (int)--v13[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x1002D130
// Name: private: struct SQVM __near * CSquirrelVM::ReadVM(void)
// Source: json
//------------------------------------------------------------------------------
SQVM *__usercall CSquirrelVM::ReadVM@<eax>(CSquirrelVM *this@<ecx>, int a2@<eax>)
{
  SQVM *v3; // eax
  int v4; // ecx
  SQVM *v5; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  tagSQObjectType *v9; // eax
  _DWORD *v10; // ecx
  tagSQObjectType type; // esi

  v3 = sq_newthread(friendvm: *(SQVM **)(a2 + 4), initialstacksize: 12);
  v4 = *(_DWORD *)(a2 + 4);
  v5 = v3;
  v6 = *(_DWORD *)(v4 + 56) - 1;
  *(_DWORD *)(v4 + 56) = v6;
  v7 = *(_DWORD *)(v4 + 32);
  v8 = *(_DWORD *)(v7 + 8 * v6);
  v9 = (tagSQObjectType *)(v7 + 8 * v6);
  v10 = *((_DWORD **)v9 + 1);
  v9[1] = (tagSQObjectType)_null_._unVal.pTable;
  type = _null_._type;
  *v9 = _null_._type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(*((_DWORD *)v9 + 1) + 4);
  if ( (v8 & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002D1A0
// Name: private: void CSquirrelVM::ReadVM(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSquirrelVM::ReadVM(SQVM *pVM@<edi>, CSquirrelVM *this)
{
  CSquirrelVM *v2; // ebx
  CUtlBuffer *v3; // ecx
  CUtlBuffer *v4; // ecx
  unsigned int i; // esi
  unsigned int j; // esi
  SQObjectPtr fill; // [esp+8h] [ebp-Ch] BYREF

  v2 = this;
  CSquirrelVM::ReadObject(this, objectOut: &pVM->_roottable, pszName: nullptr);
  CUtlBuffer::GetType<int>((CUtlBuffer *)&this, dest: (int *)&this);
  pVM->_top = (int)this;
  CUtlBuffer::GetType<int>(this: v3, dest: (int *)&this);
  v4 = (CUtlBuffer *)this;
  pVM->_stackbase = (int)this;
  CUtlBuffer::GetType<unsigned int>(this: v4, dest: (unsigned int *)&this);
  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize((sqvector<SQObjectPtr> *)this, newsize: (unsigned int)this, &fill);
  for ( i = 0; i < pVM->_stack._size; ++i )
    CSquirrelVM::ReadObject(this: v2, objectOut: &pVM->_stack._vals[i], pszName: nullptr);
  CUtlBuffer::GetType<unsigned int>((CUtlBuffer *)&this, dest: (unsigned int *)&this);
  for ( j = 0; j < pVM->_vargsstack._size; ++j )
    CSquirrelVM::ReadObject(this: v2, objectOut: &pVM->_vargsstack._vals[j], pszName: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002D260
// Name: private: struct SQTable __near * CSquirrelVM::ReadTable(void)
// Source: json
//------------------------------------------------------------------------------
SQTable *__thiscall CSquirrelVM::ReadTable(CSquirrelVM *this, CSquirrelVM *thisa)
{
  unsigned __int16 v2; // ax
  SQSharedState *sharedstate; // edi
  SQTable *v5; // eax
  SQTable *v6; // ebx
  SQCollectable *gc_chain; // eax
  CSquirrelVM *v8; // edi
  tagSQObjectType type; // eax
  CUtlBuffer *v10; // ecx
  tagSQObjectValue v11; // eax
  char *v12; // eax
  const char *v13; // eax
  tagSQObjectValue v14; // eax
  tagSQObjectValue v15; // eax
  int n; // [esp+Ch] [ebp-14h] BYREF
  SQObjectPtr key; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr value; // [esp+18h] [ebp-8h] BYREF

  CUtlBuffer::GetType<unsigned int>((CUtlBuffer *)this, dest: (unsigned int *)&n);
  key._type = n;
  if ( n != 0 )
  {
    value._type = n;
    v2 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&value,
           search: (const CUtlMap<void *,void *,unsigned short>::Node_t *)&thisa->m_PtrMap);
    if ( v2 != 0xFFFF )
      return (SQTable *)thisa->m_PtrMap.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
  sharedstate = thisa->m_hVM->_sharedstate;
  v5 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  v6 = v5;
  if ( v5 != nullptr )
  {
    v5->_uiRef = 0;
    v5->_weakref = nullptr;
    v5->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    SQTable::AllocNodes(this: v5, nSize: 4);
    v6->_next = nullptr;
    v6->_usednodes = 0;
    v6->_delegate = nullptr;
    v6->_sharedstate = sharedstate;
    v6->_prev = nullptr;
    v6->_next = sharedstate->_gc_chain;
    gc_chain = sharedstate->_gc_chain;
    if ( gc_chain != nullptr )
      gc_chain->_prev = v6;
    sharedstate->_gc_chain = v6;
  }
  v8 = thisa;
  type = key._type;
  v6->_delegate = nullptr;
  CSquirrelVM::MapPtr(pOld: type, pNew: (unsigned int)v6, this: thisa);
  CUtlBuffer::GetType<int>(this: v10, dest: (int *)&key);
  if ( key._type != 0 )
  {
    key._type = OT_NULL;
    key._unVal.nInteger = 0;
    CSquirrelVM::ReadObject(this: thisa, objectOut: &key, pszName: nullptr);
    SQDelegable::SetDelegate(this: v6, mt: key._unVal.pTable);
    if ( (key._type & 0x8000000) != 0 )
    {
      v11.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v11.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    v8 = thisa;
  }
  else
  {
    v6->_delegate = nullptr;
  }
  CUtlBuffer::GetType<int>(this: (CUtlBuffer *)&key, dest: (int *)&key);
  n = key._type;
  while ( n != 0 )
  {
    --n;
    key._unVal.nInteger = 0;
    value._unVal.nInteger = 0;
    key._type = OT_NULL;
    value._type = OT_NULL;
    CSquirrelVM::ReadObject(this: v8, objectOut: &key, pszName: nullptr);
    if ( key._type == OT_STRING )
      v12 = (char *)(key._unVal.nInteger + 28);
    else
      v12 = nullptr;
    if ( !CSquirrelVM::ReadObject(this: v8, objectOut: &value, pszName: v12) )
    {
      if ( key._type == OT_STRING )
        v13 = (const char *)(key._unVal.nInteger + 28);
      else
        v13 = SQTypeToString(sqType: key._type);
      DevMsg(a1: &stru_1009B330.m_szBuf[155], v13);
    }
    if ( key._type != OT_NULL )
      SQTable::NewSlot(this: v6, &key, val: &value);
    if ( (value._type & 0x8000000) != 0 )
    {
      v14.pTable = (SQTable *)value._unVal;
      --*(_DWORD *)(value._unVal.nInteger + 4);
      if ( *(int *)(v14.nInteger + 4) <= 0 )
        value._unVal.pTable->Release(this: (struct SQTable *)value._unVal.nInteger);
    }
    if ( (key._type & 0x8000000) != 0 )
    {
      v15.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v15.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1002D4B0
// Name: private: struct SQArray __near * CSquirrelVM::ReadArray(void)
// Source: json
//------------------------------------------------------------------------------
SQArray *__thiscall CSquirrelVM::ReadArray(CSquirrelVM *this, CSquirrelVM *thisa)
{
  unsigned int v2; // esi
  unsigned __int16 v3; // ax
  SQArray *v5; // edi
  int v6; // esi
  int v7; // ebx
  _DWORD *v8; // esi
  __int32 v9; // ecx
  unsigned int size; // eax
  int v11; // ebx
  SQObjectPtr *v12; // eax
  unsigned int v13; // edx
  SQObjectPtr *v14; // eax
  tagSQObjectValue v15; // eax
  int n; // [esp+10h] [ebp-18h] BYREF
  int dest; // [esp+14h] [ebp-14h] BYREF
  SQObjectPtr value; // [esp+18h] [ebp-10h] BYREF
  tagSQObjectType type; // [esp+20h] [ebp-8h]

  CUtlBuffer::GetType<unsigned int>((CUtlBuffer *)this, dest: (unsigned int *)&n);
  v2 = n;
  if ( n != 0 )
  {
    value._type = n;
    v3 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&value,
           search: (const CUtlMap<void *,void *,unsigned short>::Node_t *)&thisa->m_PtrMap);
    if ( v3 != 0xFFFF )
      return (SQArray *)thisa->m_PtrMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  }
  v5 = SQArray::Create(ss: thisa->m_hVM->_sharedstate, nInitialSize: 0);
  CSquirrelVM::MapPtr(pOld: v2, pNew: (unsigned int)v5, this: thisa);
  CUtlBuffer::GetType<int>(this: (CUtlBuffer *)&dest, &dest);
  v6 = dest;
  n = dest;
  v7 = dest;
  if ( dest == 0 )
    v7 = 4;
  v5->_values._vals = (SQObjectPtr *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v5->_values._vals, a3: 8 * v7);
  v5->_values._allocated = v7;
  if ( v6 != 0 )
  {
    while ( 1 )
    {
      --n;
      value._type = OT_NULL;
      value._unVal.nInteger = 0;
      CSquirrelVM::ReadObject(this: thisa, objectOut: &value, pszName: nullptr);
      v8 = &value._unVal.pTable->__vftable;
      type = value._type;
      v9 = value._type & 0x8000000;
      dest = value._type & 0x8000000;
      if ( (value._type & 0x8000000) != 0 )
        ++*(_DWORD *)(value._unVal.nInteger + 4);
      size = v5->_values._size;
      if ( v5->_values._allocated <= size )
      {
        v11 = 2 * size;
        if ( 2 * size == 0 )
          v11 = 4;
        v12 = (SQObjectPtr *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v5->_values._vals, a3: 8 * v11);
        v9 = dest;
        v5->_values._allocated = v11;
        v5->_values._vals = v12;
      }
      v13 = v5->_values._size;
      v14 = &v5->_values._vals[v13];
      v5->_values._size = v13 + 1;
      if ( v14 == nullptr )
        goto LABEL_16;
      v14->_type = type;
      v14->_unVal.nInteger = (int)v8;
      if ( v9 != 0 )
        break;
LABEL_19:
      if ( (value._type & 0x8000000) != 0 )
      {
        v15.pTable = (SQTable *)value._unVal;
        --*(_DWORD *)(value._unVal.nInteger + 4);
        if ( *(int *)(v15.nInteger + 4) <= 0 )
          value._unVal.pTable->Release(this: (struct SQTable *)value._unVal.nInteger);
      }
      if ( n == 0 )
        return v5;
    }
    ++v8[1];
LABEL_16:
    if ( v9 != 0 && (int)--v8[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
    goto LABEL_19;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002D670
// Name: private: struct SQClass __near * CSquirrelVM::ReadClass(void)
// Source: json
//------------------------------------------------------------------------------
SQClass *__usercall CSquirrelVM::ReadClass@<eax>(CSquirrelVM *this@<ecx>, int a2@<eax>)
{
  CUtlBuffer *v3; // ecx
  unsigned __int16 v4; // ax
  CUtlBuffer *v6; // ecx
  tagSQObjectValue v7; // eax
  SQClass *v8; // esi
  SQClass *v9; // ecx
  char *v10; // ebx
  CUtlBuffer *v11; // ecx
  int v12; // esi
  CUtlBuffer *v13; // ecx
  int v14; // esi
  CUtlBuffer *v15; // ecx
  unsigned int v16; // esi
  tagSQObjectValue v17; // eax
  void *v18; // esp
  SQSharedState *v19; // esi
  SQString *v20; // ebx
  bool v21; // al
  tagSQObjectType type; // esi
  _DWORD *v23; // edi
  int *pTable; // ecx
  StringTable *stringtable; // [esp-408h] [ebp-440h]
  SQTable *v26; // [esp-404h] [ebp-43Ch]
  CSquirrelVM *v27; // [esp-404h] [ebp-43Ch]
  _DWORD v28[259]; // [esp-400h] [ebp-438h] BYREF
  SQClassMember fill; // [esp+Ch] [ebp-2Ch] BYREF
  SQObjectPtr members; // [esp+1Ch] [ebp-1Ch] BYREF
  int v31; // [esp+24h] [ebp-14h] BYREF
  unsigned int dest; // [esp+28h] [ebp-10h] BYREF
  SQClass *pBase; // [esp+2Ch] [ebp-Ch]
  SQClass *pOld; // [esp+30h] [ebp-8h] BYREF
  char v35; // [esp+37h] [ebp-1h]

  v31 = 0;
  CUtlBuffer::GetType<unsigned int>((CUtlBuffer *)this, &dest);
  pOld = (SQClass *)dest;
  if ( dest != 0 )
  {
    v28[255] = &fill.attrs;
    fill.attrs._type = dest;
    v4 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&fill.attrs,
           search: (const CUtlMap<void *,void *,unsigned short>::Node_t *)(a2 + 140));
    if ( v4 != 0xFFFF )
      return *(SQClass **)(*(_DWORD *)(a2 + 144) + 16 * v4 + 12);
  }
  pBase = nullptr;
  CUtlBuffer::GetType<int>(this: v3, dest: &v31);
  if ( v31 != 0 )
  {
    v18 = alloca(1024);
    CUtlBuffer::GetString(this: *(CUtlBuffer **)(a2 + 136), pString: (char *)v28, nMaxChars: 1024);
    HIBYTE(v28[255]) = 0;
    v19 = *(SQSharedState **)(*(_DWORD *)(a2 + 4) + 148);
    stringtable = v19->_stringtable;
    fill.attrs._type = OT_NULL;
    fill.attrs._unVal.nInteger = 0;
    v20 = StringTable::Add(this: stringtable, news: (const char *)v28, len: -1);
    v20->_sharedstate = v19;
    ++v20->_uiRef;
    v26 = *(SQTable **)(*(_DWORD *)(a2 + 4) + 68);
    members._type = OT_STRING;
    members._unVal.nInteger = (int)v20;
    v21 = SQTable::Get(this: v26, key: &members, val: &fill.attrs);
    type = fill.attrs._type;
    if ( !v21 || (v35 = 1, fill.attrs._type != OT_CLASS) )
      v35 = 0;
    if ( --v20->_uiRef <= 0 )
      v20->Release(this: v20);
    v27 = (CSquirrelVM *)a2;
    if ( v35 != 0 )
    {
      v23 = &fill.attrs._unVal.pTable->__vftable;
      CSquirrelVM::MapPtr((unsigned int)pOld, pNew: fill.attrs._unVal.raw, this: v27);
      if ( (type & 0x8000000) != 0 && (int)--v23[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v23 + 8))(a1: v23);
      return (SQClass *)v23;
    }
    else
    {
      CSquirrelVM::MapPtr((unsigned int)pOld, pNew: 0, this: (CSquirrelVM *)a2);
      if ( (type & 0x8000000) != 0 )
      {
        pTable = (int *)fill.attrs._unVal.pTable;
        --*(_DWORD *)(fill.attrs._unVal.nInteger + 4);
        if ( pTable[1] <= 0 )
          (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
      }
      return nullptr;
    }
  }
  else
  {
    CUtlBuffer::GetType<int>(this: v6, dest: &v31);
    if ( v31 != 0 )
    {
      fill.attrs._type = OT_NULL;
      fill.attrs._unVal.nInteger = 0;
      CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: &fill.attrs, pszName: nullptr);
      v7.pTable = (SQTable *)fill.attrs._unVal;
      pBase = fill.attrs._unVal.pClass;
      if ( (fill.attrs._type & 0x8000000) != 0 )
      {
        --*(_DWORD *)(fill.attrs._unVal.nInteger + 4);
        if ( *(int *)(v7.nInteger + 4) <= 0 )
          fill.attrs._unVal.pTable->Release(this: (struct SQTable *)fill.attrs._unVal.nInteger);
      }
    }
    v8 = *(SQClass **)(*(_DWORD *)(a2 + 4) + 148);
    v10 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 92);
    if ( v10 != nullptr )
    {
      v28[255] = pBase;
      SQClass::SQClass(this: v9, ss: (SQSharedState *)v10, base: v8);
    }
    CSquirrelVM::MapPtr((unsigned int)pOld, pNew: (unsigned int)v10, this: (CSquirrelVM *)a2);
    members._type = OT_NULL;
    members._unVal.nInteger = 0;
    CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: &members, pszName: nullptr);
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 6) + 8))(a1: *((_DWORD *)v10 + 6));
    *((_DWORD *)v10 + 6) = members._unVal.pTable;
    ++*(_DWORD *)(members._unVal.nInteger + 4);
    CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: (SQObjectPtr *)(v10 + 68), pszName: nullptr);
    CUtlBuffer::GetType<unsigned int>(this: v11, dest: (unsigned int *)&pOld);
    fill.val._type = OT_NULL;
    fill.attrs._type = OT_NULL;
    v12 = 0;
    fill.val._unVal.nInteger = 0;
    fill.attrs._unVal.nInteger = 0;
    sqvector<SQClassMember>::resize(this: (sqvector<SQClassMember> *)(v10 + 32), newsize: (unsigned int)pOld, &fill);
    if ( (fill.attrs._type & 0x8000000) != 0 )
    {
      v13 = (CUtlBuffer *)fill.attrs._unVal.pTable;
      --*(_DWORD *)(fill.attrs._unVal.nInteger + 4);
      if ( v13->m_Memory.m_nAllocationCount <= 0 )
        (*((void (__thiscall **)(CUtlBuffer *))v13->m_Memory.m_pMemory + 2))(a1: v13);
    }
    if ( (fill.val._type & 0x8000000) != 0 )
    {
      v13 = (CUtlBuffer *)fill.val._unVal.pTable;
      --*(_DWORD *)(fill.val._unVal.nInteger + 4);
      if ( v13->m_Memory.m_nAllocationCount <= 0 )
        (*((void (__thiscall **)(CUtlBuffer *))v13->m_Memory.m_pMemory + 2))(a1: v13);
    }
    if ( pOld != nullptr )
    {
      for ( pBase = pOld; pBase != nullptr; pBase = (SQClass *)((char *)pBase - 1) )
      {
        CSquirrelVM::ReadObject(
          this: (CSquirrelVM *)a2,
          objectOut: (SQObjectPtr *)(v12 + *((_DWORD *)v10 + 8)),
          pszName: nullptr);
        CSquirrelVM::ReadObject(
          this: (CSquirrelVM *)a2,
          objectOut: (SQObjectPtr *)(*((_DWORD *)v10 + 8) + v12 + 8),
          pszName: nullptr);
        v12 += 16;
      }
    }
    CUtlBuffer::GetType<unsigned int>(this: v13, dest: (unsigned int *)&pOld);
    fill.val._type = OT_NULL;
    fill.attrs._type = OT_NULL;
    v14 = 0;
    fill.val._unVal.nInteger = 0;
    fill.attrs._unVal.nInteger = 0;
    sqvector<SQClassMember>::resize(this: (sqvector<SQClassMember> *)(v10 + 44), newsize: (unsigned int)pOld, &fill);
    if ( (fill.attrs._type & 0x8000000) != 0 )
    {
      v15 = (CUtlBuffer *)fill.attrs._unVal.pTable;
      --*(_DWORD *)(fill.attrs._unVal.nInteger + 4);
      if ( v15->m_Memory.m_nAllocationCount <= 0 )
        (*((void (__thiscall **)(CUtlBuffer *))v15->m_Memory.m_pMemory + 2))(a1: v15);
    }
    if ( (fill.val._type & 0x8000000) != 0 )
    {
      v15 = (CUtlBuffer *)fill.val._unVal.pTable;
      --*(_DWORD *)(fill.val._unVal.nInteger + 4);
      if ( v15->m_Memory.m_nAllocationCount <= 0 )
        (*((void (__thiscall **)(CUtlBuffer *))v15->m_Memory.m_pMemory + 2))(a1: v15);
    }
    if ( pOld != nullptr )
    {
      for ( pBase = pOld; pBase != nullptr; pBase = (SQClass *)((char *)pBase - 1) )
      {
        CSquirrelVM::ReadObject(
          this: (CSquirrelVM *)a2,
          objectOut: (SQObjectPtr *)(v14 + *((_DWORD *)v10 + 11)),
          pszName: nullptr);
        CSquirrelVM::ReadObject(
          this: (CSquirrelVM *)a2,
          objectOut: (SQObjectPtr *)(*((_DWORD *)v10 + 11) + v14 + 8),
          pszName: nullptr);
        v14 += 16;
      }
    }
    CUtlBuffer::GetType<unsigned int>(this: v15, dest: (unsigned int *)&pOld);
    fill.attrs._type = OT_NULL;
    fill.attrs._unVal.nInteger = 0;
    sqvector<SQObjectPtr>::resize(this: (sqvector<SQObjectPtr> *)pOld, newsize: (unsigned int)pOld, fill: &fill.attrs);
    v16 = 0;
    if ( pOld != nullptr )
    {
      do
        CSquirrelVM::ReadObject(
          this: (CSquirrelVM *)a2,
          objectOut: (SQObjectPtr *)(*((_DWORD *)v10 + 14) + 8 * v16++),
          pszName: nullptr);
      while ( v16 < (unsigned int)pOld );
    }
    if ( (members._type & 0x8000000) != 0 )
    {
      v17.pTable = (SQTable *)members._unVal;
      --*(_DWORD *)(members._unVal.nInteger + 4);
      if ( *(int *)(v17.nInteger + 4) <= 0 )
        members._unVal.pTable->Release(this: (struct SQTable *)members._unVal.nInteger);
    }
    return (SQClass *)v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DA60
// Name: private: struct SQInstance __near * CSquirrelVM::ReadInstance(void)
// Source: json
//------------------------------------------------------------------------------
SQInstance *__usercall CSquirrelVM::ReadInstance@<eax>(CSquirrelVM *this@<ecx>, int a2@<eax>)
{
  SQInstance *v3; // ebx
  char *v4; // esi
  unsigned __int16 v5; // ax
  CUtlBuffer *v7; // ecx
  CUtlBuffer *v8; // ecx
  SQObjectPtr *values; // esi
  CUtlBuffer *v10; // ecx
  int m_nMaxPut; // eax
  CSquirrelVM::InstanceContext_t *v12; // esi
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  CUtlBuffer *v14; // ecx
  CUtlBuffer *v15; // ecx
  CSquirrelVM::InstanceContext_t *v16; // eax
  int v17; // eax
  CUtlBuffer *typetag; // ecx
  CSquirrelVM::InstanceContext_t *v19; // esi
  char *v20; // eax
  bool v21; // zf
  tagSQObject *v22; // esi
  CSquirrelVM::InstanceContext_t *v23; // eax
  void *v24; // eax
  const CUtlMap<void *,void *,unsigned short>::Node_t *v25; // edi
  unsigned __int16 v26; // ax
  int v27; // edx
  SQObjectPtr *v28; // eax
  CUtlBuffer *v29; // ecx
  tagSQObjectType i; // esi
  tagSQObjectValue v31; // eax
  CUtlBuffer *v32; // ecx
  CUtlBuffer *v33; // ecx
  CUtlBuffer *v34; // ecx
  tagSQObjectValue v35; // eax
  CUtlBuffer *v36; // ecx
  tagSQObjectValue v37; // eax
  CSquirrelVM::InstanceContext_t *pContext; // [esp+18h] [ebp-20h] BYREF
  char *pszName; // [esp+1Ch] [ebp-1Ch] BYREF
  tagSQObject hExistingObject; // [esp+20h] [ebp-18h] BYREF
  SQObjectPtr ignored; // [esp+28h] [ebp-10h] BYREF
  SQObjectPtr pClass; // [esp+30h] [ebp-8h] BYREF

  CUtlBuffer::GetType<unsigned int>((CUtlBuffer *)this, dest: (unsigned int *)&pszName);
  v3 = nullptr;
  v4 = pszName;
  ignored._type = (tagSQObjectType)pszName;
  if ( pszName != nullptr )
  {
    hExistingObject._type = (tagSQObjectType)pszName;
    v5 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&hExistingObject,
           search: (const CUtlMap<void *,void *,unsigned short>::Node_t *)(a2 + 140));
    if ( v5 != 0xFFFF )
      return *(SQInstance **)(*(_DWORD *)(a2 + 144) + 16 * v5 + 12);
  }
  pClass._type = OT_NULL;
  pClass._unVal.nInteger = 0;
  CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: &pClass, pszName: nullptr);
  if ( pClass._unVal.nInteger != 0 )
  {
    v3 = SQInstance::Create(theclass: pClass._unVal.pClass, ss: *(SQSharedState **)(*(_DWORD *)(a2 + 4) + 148));
    CUtlBuffer::GetType<unsigned int>(this: v7, dest: (unsigned int *)&pszName);
    if ( pszName != nullptr )
    {
      values = v3->_values;
      do
      {
        CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: values++, pszName: nullptr);
        --pszName;
      }
      while ( pszName != nullptr );
    }
    CUtlBuffer::GetType<unsigned int>(this: v8, dest: (unsigned int *)&hExistingObject);
    v10 = (CUtlBuffer *)v3->_class;
    m_nMaxPut = v10[1].m_nMaxPut;
    v12 = nullptr;
    if ( m_nMaxPut != 0 )
    {
      Alloc_2 = _g_pMemAlloc->Alloc_2;
      if ( m_nMaxPut == 1 )
      {
        pContext = (CSquirrelVM::InstanceContext_t *)((int (__stdcall *)(int))Alloc_2)(a1: 12);
        CUtlBuffer::GetType<float>(this: v14, dest: (float *)&pszName);
        v15 = (CUtlBuffer *)pContext;
        pContext->pInstance = pszName;
        CUtlBuffer::GetType<float>(this: v15, dest: (float *)&pszName);
        pContext->pClassDesc = (ScriptClassDesc_t *)pszName;
        CUtlBuffer::GetType<float>(this: (CUtlBuffer *)&pszName, dest: (float *)&pszName);
        v16 = pContext;
        pContext->name._type = (tagSQObjectType)pszName;
        v3->_userpointer = v16;
      }
      else
      {
        v17 = ((int (__stdcall *)(int))Alloc_2)(a1: 16);
        if ( v17 != 0 )
        {
          *(_DWORD *)(v17 + 12) = 0;
          *(_DWORD *)(v17 + 8) = 16777217;
          v12 = (CSquirrelVM::InstanceContext_t *)v17;
        }
        pContext = v12;
        v12->pInstance = nullptr;
        CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: &v12->name, pszName: nullptr);
        typetag = (CUtlBuffer *)v3->_class->_typetag;
        v12->pClassDesc = (ScriptClassDesc_t *)typetag;
        CUtlBuffer::GetType<unsigned int>(this: typetag, dest: (unsigned int *)&hExistingObject);
        v19 = pContext;
        if ( pContext->name._type == OT_STRING )
        {
          v20 = (char *)(pContext->name._unVal.nInteger + 28);
          v21 = pContext->pClassDesc->pHelper == nullptr;
          pszName = v20;
          if ( !v21 )
          {
            v22 = (tagSQObject *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8);
            v23 = pContext;
            v22->_type = OT_INSTANCE;
            v22->_unVal.nInteger = (int)v3;
            v24 = v23->pClassDesc->pHelper->BindOnRead(
                    this: v23->pClassDesc->pHelper,
                    a2: (HSCRIPT__ *)v22,
                    a3: (void *)hExistingObject._type,
                    a4: pszName);
            pContext->pInstance = v24;
            if ( v24 != nullptr )
            {
              ++v3->_uiRef;
              sq_addref(v: *(SQVM **)(a2 + 4), po: v22);
              --v3->_uiRef;
            }
            else
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
            }
            v20 = pszName;
            v19 = pContext;
          }
          if ( v19->pInstance == nullptr )
          {
            CSquirrelVM::LookupObject(
              hScope: nullptr,
              this: (CSquirrelVM *)a2,
              pszObject: (tagSQObjectValue *)&hExistingObject,
              bAddRef: v20,
              bAddRefa: false);
            if ( hExistingObject._type == OT_INSTANCE
              && *(SQClass **)(hExistingObject._unVal.nInteger + 28) == v3->_class )
            {
              ((void (__thiscall *)(SQInstance *, int))v3->dtr_SQRefCounted)(a1: v3, a2: 1);
              SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&pClass);
              return hExistingObject._unVal.pInstance;
            }
            v19->pInstance = nullptr;
          }
        }
        v3->_userpointer = v19;
      }
    }
    else
    {
      CUtlBuffer::GetType<int>(this: v10, dest: (int *)&hExistingObject);
      CUtlBuffer::GetType<unsigned int>(this: (CUtlBuffer *)&hExistingObject, dest: (unsigned int *)&hExistingObject);
      v3->_userpointer = nullptr;
    }
    v25 = (const CUtlMap<void *,void *,unsigned short>::Node_t *)(a2 + 140);
    ignored._unVal.nInteger = (int)v3;
    pContext = (CSquirrelVM::InstanceContext_t *)0xFFFF;
    LOBYTE(pszName) = 0;
    CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&pContext,
      insert: v25,
      parent: (unsigned __int16 *)&ignored,
      leftchild: (bool *)&pContext);
    v26 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertAt(
            this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)pContext,
            parent: (unsigned __int16)pContext,
            leftchild: (bool)pszName);
    v27 = 2 * v26;
    v28 = (SQObjectPtr *)((char *)v25->elem + 16 * v26 + 8);
    if ( (char *)v25->elem + 8 * v27 != (void *)-8 )
      *v28 = ignored;
  }
  else
  {
    CSquirrelVM::MapPtr(pOld: (unsigned int)v4, pNew: 0, this: (CSquirrelVM *)a2);
    CUtlBuffer::GetType<unsigned int>(this: v29, dest: (unsigned int *)&ignored);
    if ( ignored._type != 0 )
    {
      for ( i = ignored._type; i != 0; --i )
      {
        ignored._type = OT_NULL;
        ignored._unVal.nInteger = 0;
        CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: &ignored, pszName: nullptr);
        if ( (ignored._type & 0x8000000) != 0 )
        {
          v31.pTable = (SQTable *)ignored._unVal;
          --*(_DWORD *)(ignored._unVal.nInteger + 4);
          if ( *(int *)(v31.nInteger + 4) <= 0 )
            ignored._unVal.pTable->Release(this: (struct SQTable *)ignored._unVal.nInteger);
        }
      }
    }
    CUtlBuffer::GetType<unsigned int>(this: (CUtlBuffer *)&ignored, dest: (unsigned int *)&ignored);
    if ( ignored._type != 0 )
    {
      if ( ignored._type == 1 )
      {
        CUtlBuffer::GetType<float>(this: v32, dest: (float *)&ignored);
        CUtlBuffer::GetType<float>(this: v33, dest: (float *)&ignored);
        CUtlBuffer::GetType<float>(this: (CUtlBuffer *)&ignored, dest: (float *)&ignored);
      }
      else
      {
        hExistingObject._type = OT_NULL;
        hExistingObject._unVal.nInteger = 0;
        CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: (SQObjectPtr *)&hExistingObject, pszName: nullptr);
        CUtlBuffer::GetType<unsigned int>(this: v34, dest: (unsigned int *)&ignored);
        if ( (hExistingObject._type & 0x8000000) != 0 )
        {
          v35.pTable = (SQTable *)hExistingObject._unVal;
          --*(_DWORD *)(hExistingObject._unVal.nInteger + 4);
          if ( *(int *)(v35.nInteger + 4) <= 0 )
            hExistingObject._unVal.pTable->Release(this: (struct SQTable *)hExistingObject._unVal.nInteger);
        }
      }
    }
    else
    {
      CUtlBuffer::GetType<int>(this: (CUtlBuffer *)&ignored, dest: (int *)&ignored);
      CUtlBuffer::GetType<unsigned int>(this: v36, dest: (unsigned int *)&ignored);
    }
  }
  if ( (pClass._type & 0x8000000) != 0 )
  {
    v37.pTable = (SQTable *)pClass._unVal;
    --*(_DWORD *)(pClass._unVal.nInteger + 4);
    if ( *(int *)(v37.nInteger + 4) <= 0 )
      pClass._unVal.pTable->Release(this: (struct SQTable *)pClass._unVal.nInteger);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1002DEE0
// Name: private: struct SQGenerator __near * CSquirrelVM::ReadGenerator(void)
// Source: json
//------------------------------------------------------------------------------
SQGenerator *__usercall CSquirrelVM::ReadGenerator@<eax>(CSquirrelVM *this@<ecx>, int a2@<edi>)
{
  unsigned __int16 v2; // ax
  SQClosure *v4; // esi
  SQGenerator *v5; // ecx
  _DWORD *v6; // ebx
  sqvector<SQObjectPtr> *v7; // ecx
  CUtlBuffer *v8; // ecx
  unsigned int i; // esi
  _DWORD *v10; // ebx
  unsigned int j; // esi
  int v12; // eax
  unsigned int dest; // [esp+8h] [ebp-20h] BYREF
  _DWORD *v14; // [esp+Ch] [ebp-1Ch]
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > var18; // [esp+10h] [ebp-18h] BYREF

  CUtlBuffer::GetType<unsigned int>((CUtlBuffer *)this, &dest);
  var18.m_Elements.m_nAllocationCount = dest;
  if ( dest != 0 )
  {
    var18.m_LessFunc.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))dest;
    v2 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &var18,
           search: (const CUtlMap<void *,void *,unsigned short>::Node_t *)(a2 + 140));
    if ( v2 != 0xFFFF )
      return *(SQGenerator **)(*(_DWORD *)(a2 + 144) + 16 * v2 + 12);
  }
  *(_DWORD *)&var18.m_Root = 16777217;
  *(_DWORD *)&var18.m_FirstFree = 0;
  CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: (SQObjectPtr *)&var18.m_Root, pszName: nullptr);
  v4 = *(SQClosure **)&var18.m_FirstFree;
  var18.m_LessFunc.m_LessFunc = *(bool (__cdecl **)(void *const *, void *const *))(*(_DWORD *)(a2 + 4) + 148);
  v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 120);
  v14 = v6;
  if ( v6 != nullptr )
    SQGenerator::SQGenerator(this: v5, a2: (int)v6, ss: (SQSharedState *)var18.m_LessFunc.m_LessFunc, closure: v4);
  CSquirrelVM::MapPtr(pOld: var18.m_Elements.m_nAllocationCount, pNew: (unsigned int)v6, this: (CSquirrelVM *)a2);
  CUtlBuffer::GetType<unsigned int>(this: (CUtlBuffer *)&dest, &dest);
  var18.m_Elements.m_nAllocationCount = 16777217;
  var18.m_Elements.m_nGrowSize = 0;
  sqvector<SQObjectPtr>::resize(
    this: v7,
    newsize: dest,
    fill: (const SQObjectPtr *)&var18.m_Elements.m_nAllocationCount);
  for ( i = 0; i < dest; ++i )
    CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: (SQObjectPtr *)(v6[8] + 8 * i), pszName: nullptr);
  CUtlBuffer::GetType<unsigned int>(this: v8, &dest);
  v10 = v14;
  var18.m_Elements.m_nAllocationCount = 16777217;
  var18.m_Elements.m_nGrowSize = 0;
  sqvector<SQObjectPtr>::resize(
    this: (sqvector<SQObjectPtr> *)&var18.m_Elements.m_nAllocationCount,
    newsize: dest,
    fill: (const SQObjectPtr *)&var18.m_Elements.m_nAllocationCount);
  for ( j = 0; j < dest; ++j )
    CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: (SQObjectPtr *)(v10[11] + 8 * j), pszName: nullptr);
  if ( (*(_DWORD *)&var18.m_Root & 0x8000000) != 0 )
  {
    v12 = *(_DWORD *)&var18.m_FirstFree;
    --*(_DWORD *)(*(_DWORD *)&var18.m_FirstFree + 4);
    if ( *(int *)(v12 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&var18.m_FirstFree + 8))(a1: *(_DWORD *)&var18.m_FirstFree);
  }
  return (SQGenerator *)v14;
}

//------------------------------------------------------------------------------
// Address: 0x1002E070
// Name: private: struct SQClosure __near * CSquirrelVM::ReadClosure(void)
// Source: json
//------------------------------------------------------------------------------
SQClosure *__thiscall CSquirrelVM::ReadClosure(CSquirrelVM *this, CSquirrelVM *thisa)
{
  unsigned __int16 v2; // ax
  SQFunctionProto *v4; // edi
  SQClosure *v5; // esi
  sqvector<SQObjectPtr> *v6; // ecx
  CUtlBuffer *v7; // ecx
  unsigned int i; // esi
  unsigned int j; // esi
  int v10; // eax
  SQClosure *v11; // [esp+10h] [ebp-20h]
  unsigned int dest; // [esp+14h] [ebp-1Ch] BYREF
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > var18; // [esp+18h] [ebp-18h] BYREF

  CUtlBuffer::GetType<unsigned int>((CUtlBuffer *)this, &dest);
  var18.m_Elements.m_nAllocationCount = dest;
  if ( dest != 0 )
  {
    var18.m_LessFunc.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))dest;
    v2 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &var18,
           search: (const CUtlMap<void *,void *,unsigned short>::Node_t *)&thisa->m_PtrMap);
    if ( v2 != 0xFFFF )
      return (SQClosure *)thisa->m_PtrMap.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
  *(_DWORD *)&var18.m_Root = 16777217;
  *(_DWORD *)&var18.m_FirstFree = 0;
  CSquirrelVM::ReadObject(this: thisa, objectOut: (SQObjectPtr *)&var18.m_Root, pszName: nullptr);
  v4 = *(SQFunctionProto **)&var18.m_FirstFree;
  var18.m_LessFunc.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))thisa->m_hVM->_sharedstate;
  v5 = (SQClosure *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 64);
  v11 = v5;
  if ( v5 != nullptr )
    SQClosure::SQClosure(this: v5, func: v4, ss: (SQSharedState *)var18.m_LessFunc.m_LessFunc);
  CSquirrelVM::MapPtr(pOld: var18.m_Elements.m_nAllocationCount, pNew: (unsigned int)v5, this: thisa);
  CSquirrelVM::ReadObject(this: thisa, objectOut: &v5->_env, pszName: nullptr);
  CUtlBuffer::GetType<unsigned int>(this: (CUtlBuffer *)&dest, &dest);
  var18.m_Elements.m_nAllocationCount = 16777217;
  var18.m_Elements.m_nGrowSize = 0;
  sqvector<SQObjectPtr>::resize(
    this: v6,
    newsize: dest,
    fill: (const SQObjectPtr *)&var18.m_Elements.m_nAllocationCount);
  for ( i = 0; i < dest; ++i )
    CSquirrelVM::ReadObject(this: thisa, objectOut: &v11->_outervalues._vals[i], pszName: nullptr);
  CUtlBuffer::GetType<unsigned int>(this: v7, &dest);
  var18.m_Elements.m_nAllocationCount = 16777217;
  var18.m_Elements.m_nGrowSize = 0;
  sqvector<SQObjectPtr>::resize(
    this: (sqvector<SQObjectPtr> *)&var18.m_Elements.m_nAllocationCount,
    newsize: dest,
    fill: (const SQObjectPtr *)&var18.m_Elements.m_nAllocationCount);
  for ( j = 0; j < dest; ++j )
    CSquirrelVM::ReadObject(this: thisa, objectOut: &v11->_defaultparams._vals[j], pszName: nullptr);
  if ( (*(_DWORD *)&var18.m_Root & 0x8000000) != 0 )
  {
    v10 = *(_DWORD *)&var18.m_FirstFree;
    --*(_DWORD *)(*(_DWORD *)&var18.m_FirstFree + 4);
    if ( *(int *)(v10 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&var18.m_FirstFree + 8))(a1: *(_DWORD *)&var18.m_FirstFree);
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1002E220
// Name: private: struct SQNativeClosure __near * CSquirrelVM::ReadNativeClosure(void)
// Source: json
//------------------------------------------------------------------------------
SQNativeClosure *__usercall CSquirrelVM::ReadNativeClosure@<eax>(CSquirrelVM *this@<ecx>, int a2@<edi>)
{
  unsigned int v2; // ebx
  unsigned __int16 v3; // ax
  SQTable *v5; // ecx
  bool v6; // al
  tagSQObjectType type; // esi
  _DWORD *v8; // esi
  tagSQObjectValue v9; // eax
  int *pTable; // ecx
  tagSQObjectValue v11; // eax
  unsigned int dest; // [esp+Ch] [ebp-14h] BYREF
  SQObjectPtr name; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr value; // [esp+18h] [ebp-8h] BYREF

  CUtlBuffer::GetType<unsigned int>((CUtlBuffer *)this, &dest);
  v2 = dest;
  if ( dest != 0 )
  {
    value._type = dest;
    v3 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&value,
           search: (const CUtlMap<void *,void *,unsigned short>::Node_t *)(a2 + 140));
    if ( v3 != 0xFFFF )
      return *(SQNativeClosure **)(*(_DWORD *)(a2 + 144) + 16 * v3 + 12);
  }
  name._type = OT_NULL;
  name._unVal.nInteger = 0;
  CSquirrelVM::ReadObject(this: (CSquirrelVM *)a2, objectOut: &name, pszName: nullptr);
  v5 = *(SQTable **)(*(_DWORD *)(a2 + 4) + 68);
  value._type = OT_NULL;
  value._unVal.nInteger = 0;
  v6 = SQTable::Get(this: v5, key: &name, val: &value);
  type = value._type;
  if ( v6 && value._type == OT_NATIVECLOSURE )
  {
    v8 = &value._unVal.pTable->__vftable;
    CSquirrelVM::MapPtr(pOld: v2, pNew: value._unVal.raw, this: (CSquirrelVM *)a2);
    if ( (int)--v8[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
    if ( (name._type & 0x8000000) != 0 )
    {
      v9.pTable = (SQTable *)name._unVal;
      --*(_DWORD *)(name._unVal.nInteger + 4);
      if ( *(int *)(v9.nInteger + 4) <= 0 )
        name._unVal.pTable->Release(this: (struct SQTable *)name._unVal.nInteger);
    }
    return (SQNativeClosure *)v8;
  }
  else
  {
    CSquirrelVM::MapPtr(pOld: v2, pNew: 0, this: (CSquirrelVM *)a2);
    if ( (type & 0x8000000) != 0 )
    {
      pTable = (int *)value._unVal.pTable;
      --*(_DWORD *)(value._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    if ( (name._type & 0x8000000) != 0 )
    {
      v11.pTable = (SQTable *)name._unVal;
      --*(_DWORD *)(name._unVal.nInteger + 4);
      if ( *(int *)(v11.nInteger + 4) <= 0 )
        name._unVal.pTable->Release(this: (struct SQTable *)name._unVal.nInteger);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E360
// Name: private: static int CSquirrelVM::SqReadFunc(void __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSquirrelVM::SqReadFunc(CUtlBuffer **up, void *data, int size)
{
  CUtlBuffer::Get(this: up[34], pMem: data, size);
  return size;
}

//------------------------------------------------------------------------------
// Address: 0x1002E380
// Name: private: struct SQFunctionProto __near * CSquirrelVM::ReadFuncProto(void)
// Source: json
//------------------------------------------------------------------------------
SQFunctionProto *__usercall CSquirrelVM::ReadFuncProto@<eax>(CSquirrelVM *this@<ecx>, int a2@<edi>)
{
  unsigned __int16 v2; // ax
  _DWORD *v4; // esi
  SQFunctionProto *v5; // eax
  SQVM *v6; // [esp-10h] [ebp-28h]
  unsigned int dest; // [esp+8h] [ebp-10h] BYREF
  SQFunctionProto *pOld; // [esp+Ch] [ebp-Ch]
  SQObjectPtr v9; // [esp+10h] [ebp-8h] BYREF

  CUtlBuffer::GetType<unsigned int>((CUtlBuffer *)this, &dest);
  pOld = (SQFunctionProto *)dest;
  if ( dest != 0 )
  {
    v9._type = dest;
    v2 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v9,
           search: (const CUtlMap<void *,void *,unsigned short>::Node_t *)(a2 + 140));
    if ( v2 != 0xFFFF )
      return *(SQFunctionProto **)(*(_DWORD *)(a2 + 144) + 16 * v2 + 12);
  }
  v6 = *(SQVM **)(a2 + 4);
  v9._type = OT_NULL;
  v9._unVal.nInteger = 0;
  SQFunctionProto::Load(
    v: v6,
    up: (void *)a2,
    read: (int (__cdecl *)(void *, void *, int))CSquirrelVM::SqReadFunc,
    ret: &v9);
  v4 = &v9._unVal.pTable->__vftable;
  ++*(_DWORD *)(v9._unVal.nInteger + 4);
  if ( (v9._type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  v5 = pOld;
  --v4[1];
  CSquirrelVM::MapPtr(pOld: (unsigned int)v5, pNew: (unsigned int)v4, this: (CSquirrelVM *)a2);
  return (SQFunctionProto *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1002E440
// Name: private: struct SQWeakRef __near * CSquirrelVM::ReadWeakRef(void)
// Source: json
//------------------------------------------------------------------------------
SQWeakRef *__thiscall CSquirrelVM::ReadWeakRef(CSquirrelVM *this)
{
  _DWORD *v1; // esi
  tagSQObjectType type; // ebx
  _DWORD *v4; // eax
  int v5; // edi
  SQObjectPtr obj; // [esp+8h] [ebp-8h] BYREF

  obj._type = OT_NULL;
  obj._unVal.nInteger = 0;
  CSquirrelVM::ReadObject(this, objectOut: &obj, pszName: nullptr);
  v1 = &obj._unVal.pTable->__vftable;
  if ( obj._unVal.nInteger != 0 )
  {
    ++*(_DWORD *)(obj._unVal.nInteger + 4);
    type = obj._type;
    if ( v1[2] == 0 )
    {
      v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20);
      v1[2] = v4;
      if ( v4 != nullptr )
      {
        v4[1] = 0;
        v4[2] = 0;
        *v4 = &SQWeakRef::`vftable';
      }
      *(_DWORD *)(v1[2] + 12) = type;
      *(_DWORD *)(v1[2] + 16) = v1;
    }
    v5 = v1[2];
    if ( (type & 0x8000000) != 0 && (int)--v1[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v1 + 8))(a1: v1);
    --v1[1];
    return (SQWeakRef *)v5;
  }
  else
  {
    if ( (obj._type & 0x8000000) != 0 )
    {
      --MEMORY[4];
      if ( MEMORY[4] <= 0 )
        obj._unVal.pTable->Release(this: nullptr);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E500
// Name: private: bool CSquirrelVM::FindKeyForObject(struct SQObjectPtr const __near &,void __near *,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSquirrelVM::FindKeyForObject(CSquirrelVM *this, SQTable *table, void *p, SQObjectPtr *key)
{
  SQTable *v4; // ecx
  int v5; // edi
  int i; // ebx
  const SQObjectPtr *p_val; // eax
  SQTable::_HashNode *nodes; // ecx
  tagSQObjectType type; // edx
  int v11; // eax
  tagSQObjectValue v12; // edi
  tagSQObjectType *p_type; // eax
  _DWORD *v14; // ecx
  tagSQObjectType v15; // eax
  int len; // [esp+Ch] [ebp-8h]
  SQTable *pTable; // [esp+1Ch] [ebp+8h]

  v5 = 0;
  pTable = (SQTable *)table->_uiRef;
  v4 = pTable;
  len = pTable->_numofnodes;
  if ( len <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    p_val = &v4->_nodes[i].val;
    if ( p_val->_unVal.pUserPointer == p )
      break;
    if ( p_val->_type == OT_TABLE )
    {
      if ( CSquirrelVM::FindKeyForObject(this, table: p_val, p, key) )
        return 1;
      v4 = pTable;
    }
    if ( ++v5 >= len )
      return 0;
  }
  nodes = v4->_nodes;
  type = key->_type;
  v11 = v5;
  v12.pTable = (SQTable *)nodes[v5].key._unVal;
  p_type = &nodes[v11].key._type;
  v14 = &key->_unVal.pTable->__vftable;
  key->_unVal = v12;
  v15 = *p_type;
  key->_type = v15;
  if ( (v15 & 0x8000000) != 0 )
    ++*(_DWORD *)(v12.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002E5B0
// Name: _CSquirrelVM::DumpState_::_2_::CIterator::PsuedoKey
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::DumpState_::_2_::CIterator::PsuedoKey(
        CSquirrelVM::DumpState::__l2::CIterator *this,
        const char *pszPsuedoKey)
{
  int i; // esi

  for ( i = 0; i < this->indent; ++i )
    _Msg(a1: &stru_1009B330.m_szBuf[195]);
  _Msg(a1: &stru_1009B330.m_szBuf[199], pszPsuedoKey);
  this->m_bKey = true;
}

//------------------------------------------------------------------------------
// Address: 0x1002E5F0
// Name: _CSquirrelVM::DumpState_::_2_::CIterator::Key
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::DumpState_::_2_::CIterator::Key(
        CSquirrelVM::DumpState::__l2::CIterator *this,
        SQObjectPtr *key)
{
  int i; // edi
  SQVM *m_hVM; // ecx
  bool v5; // zf
  tagSQObjectValue v6; // eax
  SQObjectPtr res; // [esp+10h] [ebp-8h] BYREF

  for ( i = 0; i < this->indent; ++i )
    _Msg(a1: &stru_1009B330.m_szBuf[195]);
  m_hVM = this->m_hVM;
  res._type = OT_NULL;
  res._unVal.nInteger = 0;
  SQVM::ToString(this: m_hVM, o: key, &res);
  _Msg(a1: &stru_1009B330.m_szBuf[199], res._unVal.nInteger + 28);
  v5 = (res._type & 0x8000000) == 0;
  this->m_bKey = true;
  if ( !v5 )
  {
    v6.pTable = (SQTable *)res._unVal;
    --*(_DWORD *)(res._unVal.nInteger + 4);
    if ( *(int *)(v6.nInteger + 4) <= 0 )
      res._unVal.pTable->Release(this: (struct SQTable *)res._unVal.nInteger);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E690
// Name: _CSquirrelVM::DumpState_::_2_::CIterator::Value
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::DumpState_::_2_::CIterator::Value(
        CSquirrelVM::DumpState::__l2::CIterator *this,
        SQObjectPtr *value)
{
  int i; // edi
  SQVM *m_hVM; // ecx
  tagSQObjectValue v5; // eax
  SQObjectPtr res; // [esp+10h] [ebp-8h] BYREF

  if ( !this->m_bKey )
  {
    for ( i = 0; i < this->indent; ++i )
      _Msg(a1: &stru_1009B330.m_szBuf[195]);
  }
  m_hVM = this->m_hVM;
  this->m_bKey = false;
  res._type = OT_NULL;
  res._unVal.nInteger = 0;
  SQVM::ToString(this: m_hVM, o: value, &res);
  if ( (value->_type & 0x8000000) != 0 )
    _Msg(a1: &stru_1009B330.m_szBuf[207], res._unVal.nInteger + 28, *(_DWORD *)(value->_unVal.nInteger + 4));
  else
    _Msg(a1: "%s\n", (const char *)(res._unVal.nInteger + 28));
  if ( (res._type & 0x8000000) != 0 )
  {
    v5.pTable = (SQTable *)res._unVal;
    --*(_DWORD *)(res._unVal.nInteger + 4);
    if ( *(int *)(v5.nInteger + 4) <= 0 )
      res._unVal.pTable->Release(this: (struct SQTable *)res._unVal.nInteger);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E750
// Name: _CSquirrelVM::DumpState_::_2_::CIterator::BeginContained
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSquirrelVM::DumpState_::_2_::CIterator::BeginContained(CSquirrelVM::DumpState::__l2::CIterator *this)
{
  int v2; // edi

  if ( this->m_bKey )
    _Msg(a1: "\n");
  v2 = 0;
  for ( this->m_bKey = false; v2 < this->indent; ++v2 )
    _Msg(a1: &stru_1009B330.m_szBuf[195]);
  _Msg(a1: &stru_1009B330.m_szBuf[219]);
  ++this->indent;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002E7A0
// Name: _CSquirrelVM::DumpState_::_2_::CIterator::EndContained
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::DumpState_::_2_::CIterator::EndContained(CSquirrelVM::DumpState::__l2::CIterator *this)
{
  int i; // edi

  --this->indent;
  for ( i = 0; i < this->indent; ++i )
    _Msg(a1: &stru_1009B330.m_szBuf[195]);
  _Msg(a1: &stru_1009B330.m_szBuf[223]);
}

//------------------------------------------------------------------------------
// Address: 0x1002E820
// Name: public: SQClassMember::~SQClassMember(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQClassMember::~SQClassMember(SQClassMember *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // eax
  int v3; // eax

  if ( (a2[2] & 0x8000000) != 0 )
  {
    v2 = a2[3];
    if ( (int)--*(_DWORD *)(v2 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)a2[3] + 8))(a1: a2[3]);
  }
  if ( (*a2 & 0x8000000) != 0 )
  {
    v3 = a2[1];
    if ( (int)--*(_DWORD *)(v3 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)a2[1] + 8))(a1: a2[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E860
// Name: public: CSquirrelVM::~CSquirrelVM(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSquirrelVM::~CSquirrelVM(CSquirrelVM *this, CSquirrelVM *thisa)
{
  CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *v2; // ecx
  CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > *v3; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *v4; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *m_pBlocks; // esi
  tagSQObjectValue v6; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *v7; // [esp-4h] [ebp-10h]

  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>((CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)this);
  CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Purge(this: v2);
  CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::RemoveAll(this: v3);
  m_pBlocks = thisa->m_TypeMap.m_aDataPool.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v7 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
    }
    while ( m_pBlocks != nullptr );
    thisa->m_TypeMap.m_aDataPool.m_Memory.m_pBlocks = nullptr;
    thisa->m_TypeMap.m_aDataPool.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<int,CUtlMemory<int,int>>::~CUtlVector<int,CUtlMemory<int,int>>(
    this: v4,
    a2: (int)&thisa->m_TypeMap.m_aBuckets);
  if ( (thisa->m_ErrorString._type & 0x8000000) != 0 )
  {
    v6.pTable = (SQTable *)thisa->m_ErrorString._unVal;
    if ( (int)--*(_DWORD *)(v6.nInteger + 4) <= 0 )
      thisa->m_ErrorString._unVal.pTable->Release(this: (struct SQTable *)thisa->m_ErrorString._unVal.nInteger);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E8E0
// Name: public: sqvector<struct SQObjectPtr>::~sqvector<struct SQObjectPtr>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(sqvector<SQObjectPtr> *this@<ecx>, int a2@<edi>)
{
  unsigned int i; // esi
  _DWORD *v3; // ecx
  int v4; // eax

  if ( *(_DWORD *)(a2 + 8) != 0 )
  {
    for ( i = 0; i < *(_DWORD *)(a2 + 4); ++i )
    {
      v3 = (_DWORD *)(*(_DWORD *)a2 + 8 * i);
      if ( (*v3 & 0x8000000) != 0 )
      {
        v4 = v3[1];
        if ( (int)--*(_DWORD *)(v4 + 4) <= 0 )
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v3[1] + 8))(a1: v3[1]);
      }
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E930
// Name: public: void sqvector<struct SQObjectPtr>::resize(unsigned int,struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge sqvector<SQObjectPtr>::resize(
        sqvector<SQObjectPtr> *this@<ecx>,
        int a2@<esi>,
        unsigned int newsize,
        const SQObjectPtr *fill)
{
  unsigned int v4; // edi
  unsigned int v5; // eax
  tagSQObjectType *v6; // eax
  tagSQObjectType type; // edx
  tagSQObjectValue v8; // ecx
  unsigned int v9; // edi
  _DWORD *v10; // ecx
  int v11; // eax

  if ( newsize > *(_DWORD *)(a2 + 8) )
  {
    v4 = newsize;
    if ( newsize == 0 )
      v4 = 4;
    *(_DWORD *)a2 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)a2, a3: 8 * v4);
    *(_DWORD *)(a2 + 8) = v4;
  }
  v5 = *(_DWORD *)(a2 + 4);
  if ( v5 >= newsize )
  {
    v9 = newsize;
    if ( newsize < v5 )
    {
      do
      {
        v10 = (_DWORD *)(*(_DWORD *)a2 + 8 * v9);
        if ( (*v10 & 0x8000000) != 0 )
        {
          v11 = v10[1];
          if ( (int)--*(_DWORD *)(v11 + 4) <= 0 )
            (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v10[1] + 8))(a1: v10[1]);
        }
        ++v9;
      }
      while ( v9 < *(_DWORD *)(a2 + 4) );
    }
    *(_DWORD *)(a2 + 4) = newsize;
  }
  else
  {
    do
    {
      v6 = (tagSQObjectType *)(*(_DWORD *)a2 + 8 * *(_DWORD *)(a2 + 4));
      if ( v6 != nullptr )
      {
        type = fill->_type;
        *v6 = fill->_type;
        v8.pTable = (SQTable *)fill->_unVal;
        v6[1] = (tagSQObjectType)v8.pTable;
        if ( (type & 0x8000000) != 0 )
          ++*(_DWORD *)(v8.nInteger + 4);
      }
      ++*(_DWORD *)(a2 + 4);
    }
    while ( *(_DWORD *)(a2 + 4) < newsize );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E9F0
// Name: public: struct SQObjectPtr __near & sqvector<struct SQObjectPtr>::push_back(struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
SQObjectPtr *__userpurge sqvector<SQObjectPtr>::push_back@<eax>(
        sqvector<SQObjectPtr> *this@<ecx>,
        int a2@<esi>,
        const SQObjectPtr *val)
{
  unsigned int v3; // eax
  int v4; // edi
  void *v5; // eax
  int v6; // ecx
  SQObjectPtr *result; // eax
  bool v8; // zf
  tagSQObjectValue v9; // ecx

  v3 = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a2 + 8) <= v3 )
  {
    v4 = 2 * v3;
    if ( 2 * v3 == 0 )
      v4 = 4;
    v5 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)a2, a3: 8 * v4);
    *(_DWORD *)(a2 + 8) = v4;
    *(_DWORD *)a2 = v5;
  }
  v6 = *(_DWORD *)(a2 + 4);
  result = (SQObjectPtr *)(*(_DWORD *)a2 + 8 * v6);
  *(_DWORD *)(a2 + 4) = v6 + 1;
  if ( result == nullptr )
    return nullptr;
  result->_type = val->_type;
  v8 = (result->_type & 0x8000000) == 0;
  v9.pTable = (SQTable *)val->_unVal;
  result->_unVal = v9;
  if ( !v8 )
    ++*(_DWORD *)(v9.nInteger + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002EA60
// Name: public: void sqvector<struct SQClassMember>::resize(unsigned int,struct SQClassMember const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge sqvector<SQClassMember>::resize(
        const SQClassMember *fill@<eax>,
        sqvector<SQClassMember> *this,
        unsigned int newsize)
{
  unsigned int v3; // ecx
  unsigned int v6; // esi
  SQClassMember *v7; // eax
  unsigned int size; // eax
  SQClassMember *v9; // esi
  _DWORD *v10; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v12; // eax
  _DWORD *v13; // ecx
  tagSQObjectType v14; // edx
  tagSQObjectType v15; // eax
  unsigned int v16; // edi
  SQClassMember *v17; // esi
  tagSQObjectValue v18; // eax
  tagSQObjectValue v19; // eax
  unsigned int i; // [esp+14h] [ebp+8h]

  v3 = newsize;
  if ( newsize > this->_allocated )
  {
    v6 = newsize;
    if ( newsize == 0 )
      v6 = 4;
    v7 = (SQClassMember *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: this->_vals, a3: 16 * v6);
    v3 = newsize;
    this->_vals = v7;
    this->_allocated = v6;
  }
  size = this->_size;
  if ( size >= v3 )
  {
    i = v3;
    if ( v3 < size )
    {
      v16 = v3;
      do
      {
        v17 = &this->_vals[v16];
        if ( (v17->attrs._type & 0x8000000) != 0 )
        {
          v18.pTable = (SQTable *)v17->attrs._unVal;
          if ( (int)--*(_DWORD *)(v18.nInteger + 4) <= 0 )
          {
            v17->attrs._unVal.pTable->Release(this: (struct SQTable *)v17->attrs._unVal.nInteger);
            v3 = newsize;
          }
        }
        if ( (v17->val._type & 0x8000000) != 0 )
        {
          v19.pTable = (SQTable *)v17->val._unVal;
          if ( (int)--*(_DWORD *)(v19.nInteger + 4) <= 0 )
          {
            v17->val._unVal.pTable->Release(this: (struct SQTable *)v17->val._unVal.nInteger);
            v3 = newsize;
          }
        }
        ++v16;
        ++i;
      }
      while ( i < this->_size );
    }
    this->_size = v3;
  }
  else
  {
    do
    {
      v9 = &this->_vals[this->_size];
      if ( v9 != nullptr )
      {
        v9->val._type = OT_NULL;
        v9->val._unVal.nInteger = 0;
        v9->attrs._type = OT_NULL;
        v9->attrs._unVal.nInteger = 0;
        v10 = &v9->val._unVal.pTable->__vftable;
        type = v9->val._type;
        v9->val._unVal.nInteger = fill->val._unVal.nInteger;
        v12 = fill->val._type;
        v9->val._type = fill->val._type;
        if ( (v12 & 0x8000000) != 0 )
          ++*(_DWORD *)(v9->val._unVal.nInteger + 4);
        if ( (type & 0x8000000) != 0 && (int)--v10[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
        v13 = &v9->attrs._unVal.pTable->__vftable;
        v14 = v9->attrs._type;
        v9->attrs._unVal.nInteger = fill->attrs._unVal.nInteger;
        v15 = fill->attrs._type;
        v9->attrs._type = v15;
        if ( (v15 & 0x8000000) != 0 )
          ++*(_DWORD *)(v9->attrs._unVal.nInteger + 4);
        if ( (v14 & 0x8000000) != 0 && (int)--v13[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
        v3 = newsize;
      }
      ++this->_size;
    }
    while ( this->_size < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EBC0
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  bool v3; // zf
  bool bTruncated; // [esp+7h] [ebp-1h] BYREF

  v2->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  bTruncated = false;
  V_vsnprintfRet(
    pDest: v2->m_szBuf,
    maxLen: 255,
    pFormat: (const char *)this,
    params: (char *)&pszFormat,
    pbTruncated: &bTruncated);
  v3 = !bTruncated;
  v2->m_szBuf[255] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1002EC30
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x1002EC40
// Name: public: static bool CDefOps<void __near *>::LessFunc(void __near * const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<void *>::LessFunc(void *const *lhs, void *const *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x1002EC60
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this@<ecx>,
        float *inputBuffer@<eax>,
        float *outputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  char *v6; // esi
  char v7; // dl
  char v8; // al
  char v9; // cl
  char v10; // dl

  v4 = count;
  v5 = outputBuffer;
  if ( outputBuffer != nullptr )
  {
    if ( inputBuffer == nullptr )
      inputBuffer = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      if ( count > 0 )
      {
        v6 = (char *)inputBuffer + 2;
        do
        {
          v7 = v6[1];
          v8 = *v6;
          v9 = *(v6 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v8;
          LOBYTE(count) = v7;
          v10 = *(v6 - 2);
          BYTE2(count) = v9;
          HIBYTE(count) = v10;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v6 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
    }
    else if ( outputBuffer != inputBuffer )
    {
      memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)inputBuffer, count: 4 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ECF0
// Name: protected: void CUtlBuffer::GetType<int>(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlBuffer::GetType<int>(CUtlBuffer *this@<ecx>, CUtlBuffer *a2@<esi>, int *dest)
{
  unsigned int *v3; // ebx
  int v4; // eax
  int *v5; // edi
  int nIncrement; // [esp+4h] [ebp-4h] BYREF

  v3 = (unsigned int *)dest;
  if ( (a2->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this: a2, nSize: 4) )
    {
      v4 = a2->m_Get - a2->m_nOffset;
      if ( (*(_BYTE *)&a2->m_Byteswap & 1) != 0 )
        CByteswap::SwapBufferToTargetEndian<void *>(
          this: &a2->m_Byteswap,
          outputBuffer: v3,
          inputBuffer: (unsigned int *)&a2->m_Memory.m_pMemory[v4],
          count: 1);
      else
        *v3 = *(_DWORD *)&a2->m_Memory.m_pMemory[v4];
      a2->m_Get += 4;
      return;
    }
LABEL_8:
    *v3 = 0;
    return;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this: a2, nOffset: 0, &nIncrement) )
    goto LABEL_8;
  dest = (int *)&a2->m_Memory.m_pMemory[a2->m_Get - a2->m_nOffset];
  v5 = dest;
  *v3 = strtol(nptr: (const char *)dest, endptr: (char **)&dest, ibase: 10);
  if ( dest != v5 )
    a2->m_Get += (char *)dest - (char *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002EDA0
// Name: protected: void CUtlBuffer::GetType<__int64>(__int64 __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlBuffer::GetType<__int64>(CUtlBuffer *this@<esi>, __int64 *dest@<edi>)
{
  int v2; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    CUtlBuffer::GetTypeText<__int64>(this, value: dest, nRadix: 10);
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 8) )
  {
    v2 = this->m_Get - this->m_nOffset;
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<__int64>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: (__int64 *)&this->m_Memory.m_pMemory[v2],
        count: 1);
    else
      *dest = *(_QWORD *)&this->m_Memory.m_pMemory[v2];
    this->m_Get += 8;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EE00
// Name: protected: void CUtlBuffer::GetType<unsigned int>(unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlBuffer::GetType<unsigned int>(CUtlBuffer *this@<ecx>, CUtlBuffer *a2@<esi>, unsigned int *dest)
{
  unsigned int *v3; // ebx
  int v4; // eax
  unsigned int *v5; // edi
  int nIncrement; // [esp+4h] [ebp-4h] BYREF

  v3 = dest;
  if ( (a2->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this: a2, nSize: 4) )
    {
      v4 = a2->m_Get - a2->m_nOffset;
      if ( (*(_BYTE *)&a2->m_Byteswap & 1) != 0 )
        CByteswap::SwapBufferToTargetEndian<void *>(
          this: &a2->m_Byteswap,
          outputBuffer: v3,
          inputBuffer: (unsigned int *)&a2->m_Memory.m_pMemory[v4],
          count: 1);
      else
        *v3 = *(_DWORD *)&a2->m_Memory.m_pMemory[v4];
      a2->m_Get += 4;
      return;
    }
LABEL_8:
    *v3 = 0;
    return;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this: a2, nOffset: 0, &nIncrement) )
    goto LABEL_8;
  dest = (unsigned int *)&a2->m_Memory.m_pMemory[a2->m_Get - a2->m_nOffset];
  v5 = dest;
  *v3 = strtoul(nptr: (const char *)dest, endptr: (char **)&dest, ibase: 10);
  if ( dest != v5 )
    a2->m_Get += (char *)dest - (char *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002EEB0
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlBuffer::GetType<float>(CUtlBuffer *this@<ecx>, CUtlBuffer *a2@<esi>, float *dest)
{
  float *v3; // ebx
  float *v4; // edi
  int nIncrement; // [esp+4h] [ebp-4h] BYREF

  v3 = dest;
  if ( (a2->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this: a2, nSize: 4) )
    {
      *v3 = *(float *)&a2->m_Memory.m_pMemory[a2->m_Get - a2->m_nOffset];
      if ( (*(_BYTE *)&a2->m_Byteswap & 1) != 0 )
        CByteswap::SwapBufferToTargetEndian<float>(this: &a2->m_Byteswap, inputBuffer: v3, outputBuffer: v3, count: 1);
      a2->m_Get += 4;
      return;
    }
LABEL_7:
    *v3 = 0.0;
    return;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this: a2, nOffset: 0, &nIncrement) )
    goto LABEL_7;
  dest = (float *)&a2->m_Memory.m_pMemory[a2->m_Get - a2->m_nOffset];
  v4 = dest;
  *v3 = strtod(nptr: (const char *)dest, endptr: (char **)&dest);
  if ( dest != v4 )
    a2->m_Get += (char *)dest - (char *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1002EF50
// Name: public: void CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Purge(
        CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *this@<ecx>,
        int a2@<eax>)
{
  CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > *v3; // ecx
  int v4; // edi
  _DWORD *v5; // esi
  void *v6; // [esp-4h] [ebp-14h]

  *(_DWORD *)(a2 + 16) = 0;
  if ( *(int *)(a2 + 12) >= 0 )
  {
    if ( *(_DWORD *)(a2 + 4) != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a2 + 4));
      *(_DWORD *)(a2 + 4) = 0;
    }
    *(_DWORD *)(a2 + 8) = 0;
  }
  v3 = *(CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > **)(a2 + 4);
  v4 = a2 + 24;
  *(_DWORD *)(a2 + 20) = v3;
  CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::RemoveAll(this: v3);
  v5 = *(_DWORD **)v4;
  if ( *(_DWORD *)v4 != 0 )
  {
    do
    {
      v6 = v5;
      v5 = (_DWORD *)*v5;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
    }
    while ( v5 != nullptr );
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 4) = 0;
  }
  *(_DWORD *)(v4 + 20) = 0;
  *(_DWORD *)(v4 + 28) = 0;
  *(_DWORD *)(v4 + 40) = 0;
  *(_DWORD *)(v4 + 32) = 0;
  *(_DWORD *)(v4 + 36) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002EFE0
// Name: public: bool CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::Init(int)
// Source: json
//------------------------------------------------------------------------------
char __usercall CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Init@<al>(
        CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  int v3; // eax
  int *v4; // edi
  int v5; // eax
  int v6; // ecx
  int i; // eax
  _DWORD *v8; // edi
  _DWORD *v9; // esi
  void *v11; // [esp-4h] [ebp-10h]
  int v12; // [esp+0h] [ebp-Ch]

  v3 = a2[2];
  v4 = a2 + 1;
  a2[4] = 0;
  if ( v3 < 256 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<int,int> *)(256 - v3), num: v12);
  a2[4] += 256;
  v5 = *v4;
  v6 = a2[4] - 256;
  a2[5] = a2[1];
  if ( v6 > 0 )
    _V_memmove(dest: (void *)(v5 + 1024), src: (const void *)v5, count: 4 * v6);
  for ( i = 0; i < 1024; i += 4 )
    *(_DWORD *)(i + *v4) = 0;
  v8 = a2 + 6;
  *a2 = 255;
  CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::RemoveAll(this: (CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > *)v6);
  v9 = (_DWORD *)*v8;
  if ( *v8 != 0 )
  {
    do
    {
      v11 = v9;
      v9 = (_DWORD *)*v9;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
    }
    while ( v9 != nullptr );
    *v8 = 0;
    v8[1] = 0;
  }
  v8[2] = 512;
  v8[10] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002F090
// Name: public: int CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::Find(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::Find@<eax>(
        CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int result; // eax

  result = *(_DWORD *)(a2[1]
                     + 4
                     * (*a2 & (HIBYTE(this) + 33 * (BYTE2(this) + 33 * (33 * (unsigned __int8)this + BYTE1(this) - 22)))));
  if ( result == 0 )
    return -1;
  while ( *(CUtlHashFast<SQClass *,CUtlHashFastGenericHash> **)result != this )
  {
    result = *(_DWORD *)(result + 12);
    if ( result == 0 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002F0F0
// Name: public: CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        int a2@<eax>)
{
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
  *(_WORD *)(a2 + 20) = -1;
  if ( *(int *)(a2 + 12) >= 0 )
  {
    if ( *(_DWORD *)(a2 + 4) != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a2 + 4));
      *(_DWORD *)(a2 + 4) = 0;
    }
    *(_DWORD *)(a2 + 8) = 0;
  }
  *(_WORD *)(a2 + 22) = -1;
  if ( *(int *)(a2 + 12) >= 0 )
  {
    if ( *(_DWORD *)(a2 + 4) != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a2 + 4));
      *(_DWORD *)(a2 + 4) = 0;
    }
    *(_DWORD *)(a2 + 8) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F160
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *search,
        const CUtlMap<void *,void *,unsigned short>::Node_t *searcha)
{
  unsigned __int16 m_Root; // di
  int v4; // esi

  m_Root = search->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( search->m_LessFunc.m_LessFunc(a1: searcha, a2: &search->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100B8D80 = 0x1FFFF;
      }
      m_Root = search->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( search->m_LessFunc.m_LessFunc(a1: &search->m_Elements.m_pMemory[v4].m_Data, a2: searcha) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100B8D80 = 0x1FFFF;
      }
      m_Root = search->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x1002F260
// Name: protected: bool CUtlBuffer::GetTypeText<__int64>(__int64 __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<__int64>(CUtlBuffer *this, __int64 *value, int nRadix)
{
  char *v5; // esi
  __int64 v6; // rax
  bool v7; // zf
  char *v8; // eax
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  v6 = _strtoi64(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  *(_DWORD *)value = v6;
  v8 = (char *)(pEnd - v5);
  v7 = pEnd == v5;
  *((_DWORD *)value + 1) = HIDWORD(v6);
  if ( v7 )
    return 0;
  this->m_Get += (int)v8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002F2E0
// Name: protected: void CUtlBuffer::PutTypeBin<void __near *>(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlBuffer::PutTypeBin<void *>(CUtlBuffer *this@<ecx>, CUtlBuffer *a2@<esi>, void *src)
{
  if ( CUtlBuffer::CheckPut(this: a2, nSize: 4) )
  {
    if ( (*(_BYTE *)&a2->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<void *>(
        this: &a2->m_Byteswap,
        outputBuffer: (unsigned int *)&a2->m_Memory.m_pMemory[a2->m_Put - a2->m_nOffset],
        inputBuffer: (unsigned int *)&src,
        count: 1);
    else
      *(_DWORD *)&a2->m_Memory.m_pMemory[a2->m_Put - a2->m_nOffset] = src;
    a2->m_Put += 4;
    CUtlBuffer::AddNullTermination(this: a2, nPut: a2->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F340
// Name: protected: void CUtlBuffer::PutTypeBin<__int64>(__int64)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlBuffer::PutTypeBin<__int64>(CUtlBuffer *this@<ecx>, CUtlBuffer *a2@<esi>, __int64 src)
{
  int v3; // eax

  if ( CUtlBuffer::CheckPut(this: a2, nSize: 8) )
  {
    v3 = a2->m_Put - a2->m_nOffset;
    if ( (*(_BYTE *)&a2->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<__int64>(
        this: &a2->m_Byteswap,
        outputBuffer: (__int64 *)&a2->m_Memory.m_pMemory[v3],
        inputBuffer: &src,
        count: 1);
    else
      *(_QWORD *)&a2->m_Memory.m_pMemory[v3] = src;
    a2->m_Put += 8;
    CUtlBuffer::AddNullTermination(this: a2, nPut: a2->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F3B0
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this@<ecx>, CUtlBuffer *a2@<esi>, float src)
{
  if ( CUtlBuffer::CheckPut(this: a2, nSize: 4) )
  {
    if ( (*(_BYTE *)&a2->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &a2->m_Byteswap,
        inputBuffer: &src,
        outputBuffer: (float *)&a2->m_Memory.m_pMemory[a2->m_Put - a2->m_nOffset],
        count: 1);
    else
      *(float *)&a2->m_Memory.m_pMemory[a2->m_Put - a2->m_nOffset] = src;
    a2->m_Put += 4;
    CUtlBuffer::AddNullTermination(this: a2, nPut: a2->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F420
// Name: public: void CByteswap::SwapBufferToTargetEndian<void __near *>(void __near * __near *,void __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CByteswap::SwapBufferToTargetEndian<void *>(
        CByteswap *this@<ecx>,
        unsigned __int8 *inputBuffer@<eax>,
        unsigned int *outputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  char *v6; // esi
  char v7; // al
  char v8; // cl
  char v9; // dl
  char v10; // al

  v4 = count;
  v5 = (int *)outputBuffer;
  if ( outputBuffer != nullptr )
  {
    if ( inputBuffer == nullptr )
      inputBuffer = (unsigned __int8 *)outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      if ( count > 0 )
      {
        v6 = (char *)(inputBuffer + 2);
        do
        {
          v7 = v6[1];
          v8 = *v6;
          count = *v5;
          v9 = *(v6 - 1);
          BYTE1(count) = v8;
          LOBYTE(count) = v7;
          v10 = *(v6 - 2);
          BYTE2(count) = v9;
          HIBYTE(count) = v10;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v6 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
    }
    else if ( outputBuffer != (unsigned int *)inputBuffer )
    {
      memcpy(dst: (unsigned __int8 *)outputBuffer, src: inputBuffer, count: 4 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F4A0
// Name: public: int CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::FastInsert(unsigned int,struct SQClass __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::FastInsert@<eax>(
        unsigned int uiKey@<eax>,
        CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > *a2@<ecx>,
        CUtlHashFast<SQClass *,CUtlHashFastGenericHash> *this,
        SQClass *const *data)
{
  int v5; // eax
  unsigned int v7; // ebx
  int v8; // esi
  bool v9; // [esp+0h] [ebp-10h]

  v5 = CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::AllocInternal(
         this: a2,
         multilist: v9);
  if ( v5 == 0 )
    return -1;
  *(_DWORD *)v5 = uiKey;
  *(SQClass **)(v5 + 4) = *data;
  v7 = this->m_uiBucketMask
     & (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)));
  v8 = v5;
  CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::LinkBefore(
    this: &this->m_aDataPool,
    before: this->m_aBuckets.m_Memory.m_pMemory[v7],
    elem: v5);
  this->m_aBuckets.m_Memory.m_pMemory[v7] = v8;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1002F540
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild@<ax>(
        unsigned __int16 i@<ax>,
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1002F5A0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild@<ax>(
        unsigned __int16 i@<ax>,
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1002F600
// Name: public: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        int a2@<esi>)
{
  unsigned __int16 v2; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+0h] [ebp-4h]

  v2 = *(_WORD *)(a2 + 22);
  if ( v2 != 0xFFFF )
  {
    v3 = (*(_DWORD *)(a2 + 8) > 0) - 1;
    it = v3;
    if ( *(int *)(a2 + 8) > 0 )
    {
      do
      {
        if ( v3 < *(int *)(a2 + 8)
          && v3 <= v2
          && CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               i: it,
               this: (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)a2) != v3 )
        {
          v4 = 2 * v3;
          *(_WORD *)(*(_DWORD *)(a2 + 4) + 8 * v4 + 2) = *(_WORD *)(a2 + 20);
          *(_WORD *)(*(_DWORD *)(a2 + 4) + 8 * v4) = v3;
          *(_WORD *)(a2 + 20) = v3;
        }
        v2 = *(_WORD *)(a2 + 22);
        if ( v3 == v2 )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= *(int *)(a2 + 8) )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)(a2 + 16) = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F6B0
// Name: protected: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertAt(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertAt@<ax>(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        int a2@<eax>,
        unsigned __int16 parent,
        bool leftchild)
{
  unsigned __int16 v5; // di
  int v6; // eax
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v7; // ecx

  v5 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  v6 = *(_DWORD *)(a2 + 4) + 16 * v5;
  v7 = nullptr;
  *(_WORD *)(v6 + 4) = parent;
  *(_DWORD *)v6 = -1;
  *(_WORD *)(v6 + 6) = 0;
  if ( parent == 0xFFFF )
  {
    *(_WORD *)(a2 + 16) = v5;
  }
  else if ( leftchild )
  {
    v7 = *(CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > **)(a2 + 4);
    *((_WORD *)&v7->m_LessFunc.m_LessFunc + 8 * parent) = v5;
  }
  else
  {
    *(_WORD *)(*(_DWORD *)(a2 + 4) + 16 * parent + 2) = v5;
  }
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
    this: v7,
    elem: v5);
  ++*(_WORD *)(a2 + 18);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002F730
// Name: protected: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *insert,
        const CUtlMap<void *,void *,unsigned short>::Node_t *parent,
        bool *leftchild,
        bool *leftchilda)
{
  unsigned __int16 m_Root; // si
  int v6; // edi
  bool v7; // zf
  CUtlMap<void *,void *,unsigned short>::Node_t *p_m_Data; // [esp-8h] [ebp-10h]

  m_Root = insert->m_Root;
  *(_WORD *)leftchild = -1;
  *leftchilda = false;
  while ( m_Root != 0xFFFF )
  {
    v6 = m_Root;
    p_m_Data = &insert->m_Elements.m_pMemory[v6].m_Data;
    *(_WORD *)leftchild = m_Root;
    if ( insert->m_LessFunc.m_LessFunc(a1: parent, a2: p_m_Data) != 0 )
    {
      v7 = (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0;
      *leftchilda = true;
      if ( v7 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100B8D80 = 0x1FFFF;
      }
      m_Root = insert->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      v7 = (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0;
      *leftchilda = false;
      if ( v7 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100B8D80 = 0x1FFFF;
      }
      m_Root = insert->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F820
// Name: public: void CByteswap::SwapBufferToTargetEndian<__int64>(__int64 __near *,__int64 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CByteswap::SwapBufferToTargetEndian<__int64>(
        CByteswap *this@<ecx>,
        unsigned __int8 *inputBuffer@<eax>,
        __int64 *outputBuffer,
        int count)
{
  int v4; // ebx
  __int64 *v5; // edi
  char *v6; // esi
  int v7; // edx
  char v8; // cl
  char v9; // al
  char v10; // al
  char v11; // cl
  char v12; // cl
  int src; // [esp+10h] [ebp-8h] BYREF
  int v14; // [esp+14h] [ebp-4h]

  v4 = count;
  v5 = outputBuffer;
  if ( outputBuffer != nullptr )
  {
    if ( inputBuffer == nullptr )
      inputBuffer = (unsigned __int8 *)outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      if ( count > 0 )
      {
        v6 = (char *)(inputBuffer + 6);
        do
        {
          v7 = *(_DWORD *)v5;
          v8 = v6[1];
          v14 = *((_DWORD *)v5 + 1);
          v9 = *(v6 - 1);
          src = v7;
          LOBYTE(v7) = *v6;
          BYTE2(src) = v9;
          v10 = *(v6 - 4);
          LOBYTE(src) = v8;
          v11 = *(v6 - 2);
          BYTE1(src) = v7;
          LOBYTE(v7) = *(v6 - 3);
          BYTE1(v14) = v10;
          HIBYTE(src) = v11;
          v12 = *(v6 - 5);
          LOBYTE(v14) = v7;
          LOBYTE(v7) = *(v6 - 6);
          BYTE2(v14) = v12;
          HIBYTE(v14) = v7;
          _V_memcpy(dest: v5++, &src, count: 8);
          v6 += 8;
          --v4;
        }
        while ( v4 != 0 );
      }
    }
    else if ( outputBuffer != (__int64 *)inputBuffer )
    {
      memcpy(dst: (unsigned __int8 *)outputBuffer, src: inputBuffer, count: 8 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F8E0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::RemoveAll(
        CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > *this,
        CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > *thisa)
{
  CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > *v2; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > *v6; // [esp+0h] [ebp-20h]
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t it; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *m_pBlocks; // [esp+18h] [ebp-8h] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  v2 = thisa;
  if ( thisa->m_LastAlloc.m_pBlockHeader != nullptr || thisa->m_LastAlloc.m_nIndex != -1 )
  {
    if ( thisa->m_Memory.m_pBlocks != nullptr )
    {
      m_pBlocks = thisa->m_Memory.m_pBlocks;
      v9 = 0;
    }
    else
    {
      m_pBlocks = nullptr;
      v9 = -1;
    }
    for ( i = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *)&m_pBlocks;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>::Next(
                this: v6,
                &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>::IsIdxAfter(
                 this: v6,
                 i: (int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: &thisa->m_LastAlloc)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v2 = thisa;
          }
          else
          {
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = thisa->m_FirstFree;
            thisa->m_FirstFree = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v2 = thisa;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == v2->m_LastAlloc.m_pBlockHeader && m_nIndex == v2->m_LastAlloc.m_nIndex )
        break;
    }
    v2->m_Head = 0;
    v2->m_Tail = 0;
    v2->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F9B0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::LinkBefore(
        CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > *this@<edi>,
        int elem@<esi>,
        int before)
{
  int v3; // eax
  int v4; // eax
  int m_Tail; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > *v6; // [esp+0h] [ebp-4h]

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>::IsIdxAfter(
          this: v6,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 8);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Head = *(_DWORD *)(elem + 12);
      v4 = *(_DWORD *)(elem + 12);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Tail = *(_DWORD *)(elem + 8);
      *(_DWORD *)(elem + 12) = elem;
      *(_DWORD *)(elem + 8) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 12) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 8);
    *(_DWORD *)(before + 8) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 8) = m_Tail;
  if ( m_Tail != 0 )
    *(_DWORD *)(m_Tail + 12) = elem;
  else
    this->m_Head = elem;
  ++this->m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x1002FA40
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode@<eax>(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>)
{
  int v3; // ecx
  int v4; // eax
  __int16 v5; // cx
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // di
  int v8; // eax
  __int16 v9; // cx
  unsigned __int16 v10; // cx
  int v11; // edx
  int result; // eax
  int v13; // edx

  v3 = *(unsigned __int16 *)(a3 + 20);
  if ( (_WORD)v3 == 0xFFFF )
  {
    v4 = *(_DWORD *)(a3 + 8);
    if ( *(unsigned __int16 *)(a3 + 22) >= v4 )
    {
      v4 = *(_DWORD *)(a3 + 8);
      v6 = (v4 > 0) - 1;
    }
    else
    {
      v5 = *(_WORD *)(a3 + 22);
      if ( (unsigned __int16)(v5 + 1) >= v4 )
        v6 = -1;
      else
        v6 = v5 + 1;
    }
    v7 = v6;
    if ( v6 >= v4 )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> *)v6,
        num: a2);
      v8 = *(_DWORD *)(a3 + 8);
      if ( *(unsigned __int16 *)(a3 + 22) >= v8 )
      {
        v8 = *(_DWORD *)(a3 + 8);
        v10 = (v8 > 0) - 1;
      }
      else
      {
        v9 = *(_WORD *)(a3 + 22);
        if ( (unsigned __int16)(v9 + 1) >= v8 )
          v10 = -1;
        else
          v10 = v9 + 1;
      }
      v7 = v10;
      if ( v10 >= v8 )
        _Error(a1: &stru_1009B330.m_szBuf[227]);
    }
    v11 = *(_DWORD *)(a3 + 4);
    *(_WORD *)(a3 + 22) = v7;
    *(_DWORD *)(a3 + 24) = v11;
    return v7;
  }
  else
  {
    v13 = *(_DWORD *)(a3 + 4);
    result = *(unsigned __int16 *)(a3 + 20);
    *(_WORD *)(a3 + 20) = *(_WORD *)(v13 + 16 * v3 + 2);
    *(_DWORD *)(a3 + 24) = v13;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002FB40
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *__usercall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>::Next@<eax>(
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *it@<edx>,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *result@<eax>,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // edx
  int v5; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *m_pNext; // ecx

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v5 = m_nIndex + 1;
    if ( v5 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        result->m_pBlockHeader = m_pNext;
        result->m_nIndex = 0;
      }
      else
      {
        result->m_pBlockHeader = nullptr;
        result->m_nIndex = -1;
      }
    }
    else
    {
      result->m_pBlockHeader = m_pBlockHeader;
      result->m_nIndex = v5;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002FBC0
// Name: protected: int CUtlLinkedList<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *__usercall CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::AllocInternal@<eax>(
        CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > > *this@<ecx>,
        int a2@<edi>)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *result; // eax
  int v3; // eax
  int v4; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  int v8; // eax
  int v9; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *v10; // eax
  int v11; // esi
  int m_nBlockSize; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > *v13; // [esp+0h] [ebp-20h]
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t v14; // [esp+8h] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t v15; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t v16; // [esp+18h] [ebp-8h] BYREF

  result = *(CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t **)(a2 + 20);
  if ( result != nullptr )
  {
    m_nBlockSize = result[1].m_nBlockSize;
    result[1].m_nBlockSize = 0;
    result[1].m_pNext = nullptr;
    *(_DWORD *)(a2 + 20) = m_nBlockSize;
  }
  else
  {
    v3 = *(_DWORD *)(a2 + 32);
    if ( v3 != 0 && (v4 = *(_DWORD *)(a2 + 36)) >= 0 && v4 < *(_DWORD *)(v3 + 4) )
    {
      v5 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>::Next(
             it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *)(a2 + 32),
             result: &v14,
             this: v13);
    }
    else
    {
      if ( *(_DWORD *)a2 != 0 )
      {
        v16.m_pBlockHeader = *(CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t **)a2;
        v16.m_nIndex = 0;
      }
      else
      {
        v16.m_pBlockHeader = nullptr;
        v16.m_nIndex = -1;
      }
      v15 = v16;
      v5 = &v15;
    }
    m_pBlockHeader = v5->m_pBlockHeader;
    m_nIndex = v5->m_nIndex;
    if ( m_pBlockHeader == nullptr || m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    {
      CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>::Grow(
        this: (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > *)a2,
        num: 1);
      *(_DWORD *)(a2 + 40) = 0;
      v8 = *(_DWORD *)(a2 + 32);
      if ( v8 != 0 && (v9 = *(_DWORD *)(a2 + 36)) >= 0 && v9 < *(_DWORD *)(v8 + 4) )
      {
        v10 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>::Next(
                it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *)(a2 + 32),
                result: &v15,
                this: v13);
      }
      else
      {
        if ( *(_DWORD *)a2 != 0 )
        {
          v15.m_pBlockHeader = *(CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t **)a2;
          v15.m_nIndex = 0;
        }
        else
        {
          v15.m_pBlockHeader = nullptr;
          v15.m_nIndex = -1;
        }
        v16 = v15;
        v10 = &v16;
      }
      m_pBlockHeader = v10->m_pBlockHeader;
      m_nIndex = v10->m_nIndex;
      if ( m_pBlockHeader == nullptr || m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
      {
        if ( `CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::AllocInternal'::`12'::__executeCount < 10 )
        {
          ++`CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::AllocInternal'::`12'::__executeCount;
          _Warning(a1: &stru_1009B330.m_szBuf[251]);
        }
        return nullptr;
      }
    }
    if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *)-8 )
    {
      if ( `CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
        return nullptr;
      ++`CUtlLinkedList<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>>::AllocInternal'::`19'::__executeCount;
      _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
      return nullptr;
    }
    else
    {
      *(_DWORD *)(a2 + 36) = m_nIndex;
      *(_DWORD *)(a2 + 32) = m_pBlockHeader;
      v11 = *(_DWORD *)(a2 + 36);
      if ( v11 >= 0 && v11 < m_pBlockHeader->m_nBlockSize )
      {
        ++*(_DWORD *)(a2 + 28);
        result = &m_pBlockHeader[2 * v11 + 1];
        result[1].m_nBlockSize = 0;
        result[1].m_pNext = nullptr;
      }
      else
      {
        ++*(_DWORD *)(a2 + 28);
        MEMORY[0xC] = 0;
        MEMORY[8] = 0;
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002FD50
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>::Grow(
        int num@<eax>,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > *this)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *v3; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v3 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nGrowSize + 8);
    if ( v3 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v3->m_pNext = nullptr;
    v3->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v3;
    }
    else
    {
      this->m_pBlocks = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FDF0
// Name: protected: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2@<eax>,
        unsigned __int16 elem)
{
  unsigned __int16 v3; // dx
  int v5; // ecx
  int *v6; // eax
  int v7; // eax
  int *v8; // eax
  int *v9; // eax
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v10; // edi
  int *v11; // eax
  int v12; // ebx
  bool IsLeftChild; // al
  int *v14; // eax
  unsigned __int16 v15; // ax
  int *v16; // eax
  int v17; // ecx
  int *v18; // eax
  int *v19; // eax
  int *v20; // eax
  unsigned __int16 v21; // ax
  int *v22; // eax
  int v23; // ecx
  int *v24; // eax
  int *v25; // eax
  unsigned __int16 uncle; // [esp+4h] [ebp-4h]

  v3 = elem;
  if ( elem != a2->m_Root )
  {
    v5 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100B8D80 = 0x1FFFF;
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
      }
      if ( v3 == 0xFFFF )
        v6 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v6 = (int *)&a2->m_Elements.m_pMemory[v3];
      v7 = *((unsigned __int16 *)v6 + 2);
      if ( (v5 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100B8D80 = 0x1FFFF;
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
      }
      if ( (_WORD)v7 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&a2->m_Elements.m_pMemory[v7];
      if ( *((_WORD *)v8 + 3) != 0 )
        break;
      if ( (v5 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100B8D80 = 0x1FFFF;
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
      }
      if ( v3 == 0xFFFF )
        v9 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v9 = (int *)&a2->m_Elements.m_pMemory[v3];
      v10 = (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)*((unsigned __int16 *)v9 + 2);
      if ( (v5 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5 | 1;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100B8D80 = 0x1FFFF;
      }
      if ( (_WORD)v10 == 0xFFFF )
        v11 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v11 = (int *)&a2->m_Elements.m_pMemory[(_DWORD)v10];
      v12 = *((unsigned __int16 *)v11 + 2);
      IsLeftChild = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild(
                      this: a2,
                      i: (unsigned __int16)v10);
      v5 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v5 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
             | 1;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100B8D80 = 0x1FFFF;
        }
        if ( (_WORD)v12 == 0xFFFF )
          v14 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v14 = (int *)&a2->m_Elements.m_pMemory[v12];
        v15 = *((_WORD *)v14 + 1);
        uncle = v15;
        if ( (v5 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100B8D80 = 0x1FFFF;
          v5 |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        }
        if ( v15 == 0xFFFF )
          v16 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v16 = (int *)&a2->m_Elements.m_pMemory[v15];
        if ( *((_WORD *)v16 + 3) == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRightChild(
               this: a2,
               i: elem) )
        {
          elem = (unsigned __int16)v10;
          CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this: v10,
            elem: (unsigned __int16)v10);
          v17 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100B8D80 = 0x1FFFF;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v18 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v18 = (int *)&a2->m_Elements.m_pMemory[(_DWORD)v10];
          v10 = (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)*((unsigned __int16 *)v18 + 2);
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100B8D80 = 0x1FFFF;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v19 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v19 = (int *)&a2->m_Elements.m_pMemory[(_DWORD)v10];
          LOWORD(v12) = *((_WORD *)v19 + 2);
        }
        a2->m_Elements.m_pMemory[(unsigned __int16)v10].m_Tag = 1;
        a2->m_Elements.m_pMemory[(unsigned __int16)v12].m_Tag = 0;
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this: nullptr,
          elem: v12);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v5 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
             | 1;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100B8D80 = 0x1FFFF;
        }
        if ( (_WORD)v12 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&a2->m_Elements.m_pMemory[v12];
        v21 = *(_WORD *)v20;
        uncle = v21;
        if ( (v5 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100B8D80 = 0x1FFFF;
          v5 |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        }
        if ( v21 == 0xFFFF )
          v22 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v22 = (int *)&a2->m_Elements.m_pMemory[v21];
        if ( *((_WORD *)v22 + 3) == 0 )
        {
LABEL_61:
          a2->m_Elements.m_pMemory[(_DWORD)v10].m_Tag = 1;
          a2->m_Elements.m_pMemory[uncle].m_Tag = 1;
          a2->m_Elements.m_pMemory[v12].m_Tag = 0;
          elem = v12;
          goto LABEL_76;
        }
        if ( CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild(
               this: a2,
               i: elem) )
        {
          elem = (unsigned __int16)v10;
          CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this: v10,
            elem: (unsigned __int16)v10);
          v23 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v23 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100B8D80 = 0x1FFFF;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v24 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v24 = (int *)&a2->m_Elements.m_pMemory[(_DWORD)v10];
          v10 = (CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)*((unsigned __int16 *)v24 + 2);
          if ( (v23 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v23 | 1;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100B8D80 = 0x1FFFF;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v25 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v25 = (int *)&a2->m_Elements.m_pMemory[(_DWORD)v10];
          LOWORD(v12) = *((_WORD *)v25 + 2);
        }
        a2->m_Elements.m_pMemory[(unsigned __int16)v10].m_Tag = 1;
        a2->m_Elements.m_pMemory[(unsigned __int16)v12].m_Tag = 0;
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this: nullptr,
          elem: v12);
      }
      v5 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
LABEL_76:
      if ( elem == a2->m_Root )
        break;
      v3 = elem;
    }
  }
  a2->m_Elements.m_pMemory[a2->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030280
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> *this@<ecx>,
        int a2@<edi>)
{
  int v2; // esi
  int v3; // eax
  int v4; // ecx
  void *v5; // edx
  unsigned int v6; // [esp-4h] [ebp-8h]

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 >= 0 )
  {
    v3 = *(_DWORD *)(a2 + 4);
    v4 = v3 + 1;
    if ( v2 != 0 )
    {
      v3 = v2 * (v3 / v2 + 1);
    }
    else
    {
      if ( v3 == 0 )
        v3 = 2;
      for ( ; v3 < v4; v3 *= 2 )
        ;
    }
    if ( (unsigned __int16)v3 < v4 )
    {
      if ( (_WORD)v3 != 0 || v4 > 0xFFFF )
      {
        if ( (unsigned __int16)v4 != v4 )
          return;
        do
          v3 = (v4 + v3) / 2;
        while ( (unsigned __int16)v3 < v4 );
      }
      else
      {
        --v3;
      }
    }
    v5 = *(void **)a2;
    *(_DWORD *)(a2 + 4) = v3;
    v6 = 16 * v3;
    if ( v5 != nullptr )
      *(_DWORD *)a2 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v5, a3: v6);
    else
      *(_DWORD *)a2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030310
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct SQClass __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct SQClass __near *>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __fastcall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int>>::IsIdxAfter(
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::Iterator_t *it,
        unsigned int i,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<SQClass *,CUtlHashFastGenericHash>::HashFastData_t_<SQClass *>,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[2 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[2 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[2 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10030380
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent@<ax>(
        unsigned __int16 i@<ax>,
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_100B8D80;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100303E0
// Name: public: bool CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __usercall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild@<al>(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<esi>,
        unsigned __int16 i@<dx>)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // eax

  v2 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
    v2 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
  }
  if ( i == 0xFFFF )
    v3 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    v3 = (int *)&this->m_Elements.m_pMemory[i];
  v4 = *((unsigned __int16 *)v3 + 2);
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( (_WORD)v4 == 0xFFFF )
    return (_WORD)`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v4].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x10030490
// Name: public: bool CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __usercall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRightChild@<al>(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<esi>,
        unsigned __int16 i@<dx>)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // eax

  v2 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
    v2 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
  }
  if ( i == 0xFFFF )
    v3 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    v3 = (int *)&this->m_Elements.m_pMemory[i];
  v4 = *((unsigned __int16 *)v3 + 2);
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( (_WORD)v4 == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel) == i;
  else
    return this->m_Elements.m_pMemory[v4].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x10030550
// Name: protected: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2@<eax>,
        unsigned __int16 elem)
{
  int v3; // ecx
  int *v6; // eax
  int v7; // edi
  int *v8; // eax
  int *v9; // eax
  int elema; // [esp+14h] [ebp+8h]

  v3 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v3 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( elem == 0xFFFF )
    v6 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    v6 = (int *)&a2->m_Elements.m_pMemory[elem];
  v7 = *((unsigned __int16 *)v6 + 1);
  if ( (v3 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v3 | 1;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( (_WORD)v7 == 0xFFFF )
    v8 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    v8 = (int *)&a2->m_Elements.m_pMemory[v7];
  a2->m_Elements.m_pMemory[elem].m_Right = *(_WORD *)v8;
  elema = elem;
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( (_WORD)v7 == 0xFFFF )
    v9 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    v9 = (int *)&a2->m_Elements.m_pMemory[v7];
  if ( *(_WORD *)v9 != 0xFFFF )
    a2->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                               i: v7,
                               this: a2)].m_Parent = elem;
  if ( (_WORD)v7 != 0xFFFF )
    a2->m_Elements.m_pMemory[v7].m_Parent = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                              i: elem,
                                              this: a2);
  if ( elem == a2->m_Root )
  {
    a2->m_Root = v7;
  }
  else if ( CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild(
              this: a2,
              i: elem) )
  {
    a2->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                               i: elem,
                               this: a2)].m_Left = v7;
  }
  else
  {
    a2->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                               i: elem,
                               this: a2)].m_Right = v7;
  }
  a2->m_Elements.m_pMemory[v7].m_Left = elem;
  if ( elem != 0xFFFF )
    a2->m_Elements.m_pMemory[elema].m_Parent = v7;
}

//------------------------------------------------------------------------------
// Address: 0x100306E0
// Name: protected: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2@<eax>,
        unsigned __int16 elem)
{
  int v3; // ecx
  int *v6; // eax
  int v7; // edi
  int *v8; // eax
  int *v9; // eax
  int elema; // [esp+14h] [ebp+8h]

  v3 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v3 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( elem == 0xFFFF )
    v6 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    v6 = (int *)&a2->m_Elements.m_pMemory[elem];
  v7 = *(unsigned __int16 *)v6;
  if ( (v3 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v3 | 1;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( (_WORD)v7 == 0xFFFF )
    v8 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    v8 = (int *)&a2->m_Elements.m_pMemory[v7];
  a2->m_Elements.m_pMemory[elem].m_Left = *((_WORD *)v8 + 1);
  elema = elem;
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100B8D80 = 0x1FFFF;
  }
  if ( (_WORD)v7 == 0xFFFF )
    v9 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    v9 = (int *)&a2->m_Elements.m_pMemory[v7];
  if ( *((_WORD *)v9 + 1) != 0xFFFF )
    a2->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                               i: v7,
                               this: a2)].m_Parent = elem;
  if ( (_WORD)v7 != 0xFFFF )
    a2->m_Elements.m_pMemory[v7].m_Parent = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                              i: elem,
                                              this: a2);
  if ( elem == a2->m_Root )
  {
    a2->m_Root = v7;
  }
  else if ( CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRightChild(
              this: a2,
              i: elem) )
  {
    a2->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                               i: elem,
                               this: a2)].m_Right = v7;
  }
  else
  {
    a2->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                               i: elem,
                               this: a2)].m_Left = v7;
  }
  a2->m_Elements.m_pMemory[v7].m_Right = elem;
  if ( elem != 0xFFFF )
    a2->m_Elements.m_pMemory[elema].m_Parent = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10036100
// Name: public: virtual void SQClosure::Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQClosure::Finalize(SQNativeClosure *this)
{
  SQObjectPtr fill; // [esp+4h] [ebp-8h] BYREF

  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize((sqvector<SQObjectPtr> *)this, a2: (int)&this->_outervalues, newsize: 0, &fill);
}

//------------------------------------------------------------------------------
// Address: 0x10039290
// Name: public: void sqvector<struct SQObjectPtr>::copy(class sqvector<struct SQObjectPtr> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall sqvector<SQObjectPtr>::copy(sqvector<SQObjectPtr> *this@<eax>, const sqvector<SQObjectPtr> *v@<edi>)
{
  unsigned int v3; // ebx
  SQObjectPtr *v4; // ecx
  SQObjectPtr *v5; // eax
  tagSQObjectType type; // edx
  tagSQObjectValue v7; // eax
  sqvector<SQObjectPtr> *size; // [esp-8h] [ebp-18h]
  SQObjectPtr fill; // [esp+8h] [ebp-8h] BYREF

  v3 = 0;
  size = (sqvector<SQObjectPtr> *)v->_size;
  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize(this: size, a2: (int)this, newsize: (unsigned int)size, &fill);
  if ( v->_size != 0 )
  {
    do
    {
      v4 = &this->_vals[v3];
      if ( v4 != nullptr )
      {
        v5 = &v->_vals[v3];
        type = v5->_type;
        v4->_type = v5->_type;
        v7.pTable = (SQTable *)v5->_unVal;
        v4->_unVal = v7;
        if ( (type & 0x8000000) != 0 )
          ++*(_DWORD *)(v7.nInteger + 4);
      }
      ++v3;
    }
    while ( v3 < v->_size );
    this->_size = v->_size;
  }
  else
  {
    this->_size = v->_size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039310
// Name: public: void sqvector<struct SQObjectPtr>::insert(unsigned int,struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge sqvector<SQObjectPtr>::insert(
        sqvector<SQObjectPtr> *this@<ecx>,
        int *a2@<eax>,
        unsigned int idx,
        const SQObjectPtr *val)
{
  unsigned int i; // edi
  _DWORD *v6; // ecx
  int v7; // ebx
  _DWORD *v8; // eax
  int v9; // edx
  int v10; // eax
  tagSQObjectValue v11; // edi
  int v12; // esi
  tagSQObjectType *v13; // eax
  _DWORD *v14; // ecx
  tagSQObjectType type; // edx
  sqvector<SQObjectPtr> *v16; // [esp-8h] [ebp-20h]
  SQObjectPtr fill; // [esp+10h] [ebp-8h] BYREF

  v16 = (sqvector<SQObjectPtr> *)(a2[1] + 1);
  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize(this: v16, (int)a2, newsize: (unsigned int)v16, &fill);
  for ( i = a2[1] - 1; i > idx; --i )
  {
    v6 = *(_DWORD **)(*a2 + 8 * i + 4);
    v7 = *(_DWORD *)(*a2 + 8 * i);
    v8 = (_DWORD *)(*a2 + 8 * i);
    v8[1] = *(v8 - 1);
    v9 = *(v8 - 2);
    *v8 = v9;
    if ( (v9 & 0x8000000) != 0 )
      ++*(_DWORD *)(v8[1] + 4);
    if ( (v7 & 0x8000000) != 0 && (int)--v6[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  }
  v10 = *a2;
  v11.pTable = (SQTable *)val->_unVal;
  v12 = *(_DWORD *)(*a2 + 8 * idx);
  v13 = (tagSQObjectType *)(v10 + 8 * idx);
  v14 = *((_DWORD **)v13 + 1);
  v13[1] = (tagSQObjectType)v11.pTable;
  type = val->_type;
  *v13 = val->_type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(v11.nInteger + 4);
  if ( (v12 & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
}

//------------------------------------------------------------------------------
// Address: 0x100393D0
// Name: public: void sqvector<struct SQObjectPtr>::remove(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge sqvector<SQObjectPtr>::remove(sqvector<SQObjectPtr> *this@<ecx>, int *a2@<esi>, unsigned int idx)
{
  int v3; // eax
  unsigned int v4; // edi
  int v5; // ecx
  int v6; // eax

  v3 = *a2;
  v4 = 8 * idx;
  if ( (*(_DWORD *)(*a2 + 8 * idx) & 0x8000000) != 0 )
  {
    v5 = *(_DWORD *)(v3 + v4 + 4);
    if ( (int)--*(_DWORD *)(v5 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v3 + v4 + 4) + 8))(a1: *(_DWORD *)(v3 + v4 + 4));
  }
  v6 = a2[1];
  if ( idx < v6 - 1 )
    memmove(dst: (unsigned __int8 *)(v4 + *a2), src: (unsigned __int8 *)(v4 + *a2 + 8), count: 8 * (v6 - idx) - 8);
  --a2[1];
}

//------------------------------------------------------------------------------
// Address: 0x10039510
// Name: public: struct SQObjectPtr __near & SQObjectPtr::operator=(int)
// Source: json
//------------------------------------------------------------------------------
SQObjectPtr *__userpurge SQObjectPtr::operator=@<eax>(SQObjectPtr *this@<ecx>, _DWORD *a2@<esi>, int i)
{
  int v3; // eax

  if ( (*a2 & 0x8000000) != 0 )
  {
    v3 = a2[1];
    if ( (int)--*(_DWORD *)(v3 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)a2[1] + 8))(a1: a2[1]);
  }
  a2[1] = i;
  *a2 = 83886082;
  return (SQObjectPtr *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10039550
// Name: public: struct SQObjectPtr __near & SQObjectPtr::operator=(float)
// Source: json
//------------------------------------------------------------------------------
SQObjectPtr *__userpurge SQObjectPtr::operator=@<eax>(SQObjectPtr *this@<ecx>, float *a2@<esi>, float f)
{
  int v3; // eax

  if ( (*(_DWORD *)a2 & 0x8000000) != 0 )
  {
    v3 = *((_DWORD *)a2 + 1);
    if ( (int)--*(_DWORD *)(v3 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**((_DWORD **)a2 + 1) + 8))(a1: *((_DWORD *)a2 + 1));
  }
  a2[1] = f;
  *a2 = 6.0185339e-36;
  return (SQObjectPtr *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x1003DBB0
// Name: public: void sqvector<struct SQClassMember>::copy(class sqvector<struct SQClassMember> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sqvector<SQClassMember>::copy(
        sqvector<SQClassMember> *this,
        sqvector<SQClassMember> *v,
        const sqvector<SQClassMember> *va)
{
  sqvector<SQClassMember> *v3; // esi
  const sqvector<SQClassMember> *v4; // edi
  int v5; // ebx
  int *pTable; // ecx
  int *v7; // ecx
  SQClassMember *v8; // esi
  SQClassMember *vals; // edi
  tagSQObjectValue v10; // eax
  _DWORD *v11; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType *p_type; // edi
  tagSQObjectType v14; // eax
  tagSQObjectValue v15; // edx
  _DWORD *v16; // ecx
  tagSQObjectType v17; // eax
  tagSQObjectType v18; // edi
  unsigned int size; // [esp-4h] [ebp-24h]
  SQClassMember fill; // [esp+Ch] [ebp-14h] BYREF
  unsigned int i; // [esp+1Ch] [ebp-4h]

  v3 = v;
  v4 = va;
  fill.val._type = OT_NULL;
  fill.attrs._type = OT_NULL;
  size = va->_size;
  v5 = 0;
  fill.val._unVal.nInteger = 0;
  fill.attrs._unVal.nInteger = 0;
  sqvector<SQClassMember>::resize(&fill, this: v, newsize: size);
  if ( (fill.attrs._type & 0x8000000) != 0 )
  {
    pTable = (int *)fill.attrs._unVal.pTable;
    --*(_DWORD *)(fill.attrs._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  if ( (fill.val._type & 0x8000000) != 0 )
  {
    v7 = (int *)fill.val._unVal.pTable;
    --*(_DWORD *)(fill.val._unVal.nInteger + 4);
    if ( v7[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v7 + 8))(a1: v7);
  }
  i = 0;
  if ( va->_size != 0 )
  {
    while ( 1 )
    {
      v8 = &v3->_vals[v5];
      if ( v8 != nullptr )
      {
        vals = v4->_vals;
        v8->val._type = OT_NULL;
        v8->val._unVal.nInteger = 0;
        v8->attrs._type = OT_NULL;
        v8->attrs._unVal.nInteger = 0;
        v10.pTable = (SQTable *)vals[v5].val._unVal;
        v11 = &v8->val._unVal.pTable->__vftable;
        type = v8->val._type;
        p_type = &vals[v5].val._type;
        v8->val._unVal = v10;
        v14 = *p_type;
        v8->val._type = *p_type;
        if ( (v14 & 0x8000000) != 0 )
          ++*(_DWORD *)(v8->val._unVal.nInteger + 4);
        if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
        v15.pTable = (SQTable *)p_type[3];
        v16 = &v8->attrs._unVal.pTable->__vftable;
        v17 = v8->attrs._type;
        v8->attrs._unVal = v15;
        v18 = *((_DWORD *)p_type + 2);
        v8->attrs._type = v18;
        if ( (v18 & 0x8000000) != 0 )
          ++*(_DWORD *)(v15.nInteger + 4);
        if ( (v17 & 0x8000000) != 0 && (int)--v16[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v16 + 8))(a1: v16);
        v4 = va;
      }
      ++v5;
      if ( ++i >= v4->_size )
        break;
      v3 = v;
    }
    v->_size = v4->_size;
  }
  else
  {
    v->_size = va->_size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DCF0
// Name: public: sqvector<struct SQClassMember>::~sqvector<struct SQClassMember>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall sqvector<SQClassMember>::~sqvector<SQClassMember>(sqvector<SQClassMember> *this@<ecx>, int a2@<edi>)
{
  int v2; // ebx
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( *(_DWORD *)(a2 + 8) != 0 )
  {
    for ( i = 0; i < *(_DWORD *)(a2 + 4); ++i )
    {
      v3 = (_DWORD *)(v2 + *(_DWORD *)a2);
      if ( (v3[2] & 0x8000000) != 0 )
      {
        v4 = v3[3];
        if ( (int)--*(_DWORD *)(v4 + 4) <= 0 )
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v3[3] + 8))(a1: v3[3]);
      }
      if ( (*v3 & 0x8000000) != 0 )
      {
        v5 = v3[1];
        if ( (int)--*(_DWORD *)(v5 + 4) <= 0 )
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v3[1] + 8))(a1: v3[1]);
      }
      v2 += 16;
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DD70
// Name: public: struct SQClassMember __near & sqvector<struct SQClassMember>::push_back(struct SQClassMember const __near &)
// Source: json
//------------------------------------------------------------------------------
SQClassMember *__userpurge sqvector<SQClassMember>::push_back@<eax>(
        sqvector<SQClassMember> *this@<ecx>,
        int a2@<edi>,
        const SQClassMember *val)
{
  unsigned int v3; // eax
  int v4; // esi
  int v5; // esi
  bool v6; // zf
  SQClassMember *v7; // esi

  v3 = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a2 + 8) <= v3 )
  {
    v4 = 2 * v3;
    if ( 2 * v3 == 0 )
      v4 = 4;
    *(_DWORD *)a2 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)a2, a3: 16 * v4);
    *(_DWORD *)(a2 + 8) = v4;
  }
  v5 = 16 * *(_DWORD *)(a2 + 4);
  v6 = *(_DWORD *)a2 + v5 == 0;
  v7 = (SQClassMember *)(*(_DWORD *)a2 + v5);
  ++*(_DWORD *)(a2 + 4);
  if ( v6 )
    return nullptr;
  else
    return SQClassMember::SQClassMember(this: v7, o: val);
}

//------------------------------------------------------------------------------
// Address: 0x10049F50
// Name: public: sqvector<struct SQLocalVarInfo>::~sqvector<struct SQLocalVarInfo>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall sqvector<SQLocalVarInfo>::~sqvector<SQLocalVarInfo>(
        sqvector<SQLocalVarInfo> *this@<ecx>,
        void **a2@<esi>)
{
  unsigned int v2; // ebx
  int v3; // edi
  char *v4; // eax
  int v5; // ecx

  if ( a2[2] != nullptr )
  {
    v2 = 0;
    if ( a2[1] != nullptr )
    {
      v3 = 0;
      do
      {
        v4 = (char *)*a2;
        if ( (*(_DWORD *)((_BYTE *)*a2 + v3) & 0x8000000) != 0 )
        {
          v5 = *(_DWORD *)&v4[v3 + 4];
          if ( (int)--*(_DWORD *)(v5 + 4) <= 0 )
            (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&v4[v3 + 4] + 8))(a1: *(_DWORD *)&v4[v3 + 4]);
        }
        ++v2;
        v3 += 20;
      }
      while ( v2 < (unsigned int)a2[1] );
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049FB0
// Name: public: struct SQLocalVarInfo __near & sqvector<struct SQLocalVarInfo>::push_back(struct SQLocalVarInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
SQLocalVarInfo *__userpurge sqvector<SQLocalVarInfo>::push_back@<eax>(
        sqvector<SQLocalVarInfo> *this@<ecx>,
        int a2@<esi>,
        const SQLocalVarInfo *val)
{
  unsigned int v3; // eax
  int v4; // edi
  void *v5; // eax
  int v6; // ecx
  SQLocalVarInfo *result; // eax
  tagSQObjectType type; // ecx

  v3 = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a2 + 8) <= v3 )
  {
    v4 = 2 * v3;
    if ( 2 * v3 == 0 )
      v4 = 4;
    v5 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)a2, a3: 20 * v4);
    *(_DWORD *)(a2 + 8) = v4;
    *(_DWORD *)a2 = v5;
  }
  v6 = *(_DWORD *)(a2 + 4);
  result = (SQLocalVarInfo *)(*(_DWORD *)a2 + 20 * v6);
  *(_DWORD *)(a2 + 4) = v6 + 1;
  if ( result == nullptr )
    return nullptr;
  result->_name._type = OT_NULL;
  result->_name._unVal.nInteger = 0;
  result->_name._unVal.nInteger = val->_name._unVal.nInteger;
  type = val->_name._type;
  result->_name._type = val->_name._type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(result->_name._unVal.nInteger + 4);
  result->_start_op = val->_start_op;
  result->_end_op = val->_end_op;
  result->_pos = val->_pos;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004A050
// Name: public: sqvector<struct SQOuterVar>::~sqvector<struct SQOuterVar>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall sqvector<SQOuterVar>::~sqvector<SQOuterVar>(sqvector<SQOuterVar> *this@<ecx>, int a2@<edi>)
{
  int v2; // ebx
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  v2 = 0;
  if ( *(_DWORD *)(a2 + 8) != 0 )
  {
    for ( i = 0; i < *(_DWORD *)(a2 + 4); ++i )
    {
      v3 = (_DWORD *)(v2 + *(_DWORD *)a2);
      if ( (v3[3] & 0x8000000) != 0 )
      {
        v4 = v3[4];
        if ( (int)--*(_DWORD *)(v4 + 4) <= 0 )
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v3[4] + 8))(a1: v3[4]);
      }
      if ( (v3[1] & 0x8000000) != 0 )
      {
        v5 = v3[2];
        if ( (int)--*(_DWORD *)(v5 + 4) <= 0 )
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v3[2] + 8))(a1: v3[2]);
      }
      v2 += 20;
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A0D0
// Name: public: struct SQOuterVar __near & sqvector<struct SQOuterVar>::push_back(struct SQOuterVar const __near &)
// Source: json
//------------------------------------------------------------------------------
SQOuterVar *__userpurge sqvector<SQOuterVar>::push_back@<eax>(
        sqvector<SQOuterVar> *this@<ecx>,
        int a2@<edi>,
        const SQOuterVar *val)
{
  unsigned int v3; // eax
  int v4; // esi
  int v5; // eax
  SQOuterVar *v6; // esi

  v3 = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a2 + 8) <= v3 )
  {
    v4 = 2 * v3;
    if ( 2 * v3 == 0 )
      v4 = 4;
    *(_DWORD *)a2 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)a2, a3: 20 * v4);
    *(_DWORD *)(a2 + 8) = v4;
  }
  v5 = *(_DWORD *)(a2 + 4);
  v6 = (SQOuterVar *)(*(_DWORD *)a2 + 20 * v5);
  *(_DWORD *)(a2 + 4) = v5 + 1;
  if ( v6 != nullptr )
    return SQOuterVar::SQOuterVar(this: v6, ov: val);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10050C90
// Name: public: struct SQExceptionTrap __near & sqvector<struct SQExceptionTrap>::push_back(struct SQExceptionTrap const __near &)
// Source: json
//------------------------------------------------------------------------------
SQExceptionTrap *__userpurge sqvector<SQExceptionTrap>::push_back@<eax>(
        sqvector<SQExceptionTrap> *this@<ecx>,
        int a2@<esi>,
        const SQExceptionTrap *val)
{
  unsigned int v3; // eax
  int v4; // edi
  void *v5; // eax
  int v6; // eax
  bool v7; // zf
  SQExceptionTrap *result; // eax

  v3 = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a2 + 8) <= v3 )
  {
    v4 = 2 * v3;
    if ( 2 * v3 == 0 )
      v4 = 4;
    v5 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)a2, a3: 16 * v4);
    *(_DWORD *)(a2 + 8) = v4;
    *(_DWORD *)a2 = v5;
  }
  v6 = 16 * *(_DWORD *)(a2 + 4);
  v7 = *(_DWORD *)a2 + v6 == 0;
  result = (SQExceptionTrap *)(*(_DWORD *)a2 + v6);
  ++*(_DWORD *)(a2 + 4);
  if ( v7 )
    return nullptr;
  *result = *val;
  return result;
}
