// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/sqstdlib/sqstdblob.cpp
// Functions: 24
// ============================================================

#include "vscript\languages\squirrel\sqstdlib\sqstdblob.h"

//------------------------------------------------------------------------------
// Address: 0x10030D30
// Name: public: virtual int SQBlob::Write(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SQBlob::Write(SQBlob *this, unsigned __int8 *buffer, unsigned int size)
{
  int ptr; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int sizea; // [esp+14h] [ebp+Ch]

  ptr = this->_ptr;
  v6 = this->_size;
  if ( (int)(ptr + size) > v6 )
  {
    sizea = size + ptr - v6;
    v7 = size + ptr;
    if ( v7 > this->_allocated )
    {
      v8 = 2 * v6;
      if ( v7 > 2 * v6 )
        v8 = v7;
      SQBlob::Resize(this, n: v8);
    }
    this->_size += sizea;
  }
  memcpy(dst: &this->_buf[this->_ptr], src: buffer, count: size);
  this->_ptr += size;
  return size;
}

//------------------------------------------------------------------------------
// Address: 0x10030D90
// Name: public: virtual int SQBlob::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SQBlob::Read(SQBlob *this, unsigned __int8 *buffer, unsigned int size)
{
  int ptr; // eax
  int v5; // ecx
  unsigned int v6; // edi
  int v7; // ecx

  ptr = this->_ptr;
  v5 = this->_size;
  v6 = size;
  if ( (int)(ptr + size) <= v5 )
    goto LABEL_4;
  v7 = v5 - ptr;
  if ( v7 > 0 )
  {
    v6 = v7;
LABEL_4:
    memcpy(dst: buffer, src: &this->_buf[ptr], count: v6);
    this->_ptr += v6;
    return v6;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10030DE0
// Name: public: bool SQBlob::Resize(int)
// Source: json
//------------------------------------------------------------------------------
char __usercall SQBlob::Resize@<al>(SQBlob *this@<esi>, int n@<edi>, int a3@<ebx>)
{
  unsigned __int8 *v4; // ebx

  if ( !this->_owns )
    return 0;
  if ( n != this->_allocated )
  {
    v4 = (unsigned __int8 *)((int (__thiscall *)(IMemAlloc *, int, int))_g_pMemAlloc->Alloc_2)(
                              a1: _g_pMemAlloc,
                              a2: n,
                              a3);
    memset(dst: (int)v4, value: nullptr, count: n);
    if ( this->_size <= n )
      memcpy(dst: v4, src: this->_buf, count: this->_size);
    else
      memcpy(dst: v4, src: this->_buf, count: n);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_buf);
    this->_buf = v4;
    this->_allocated = n;
    if ( this->_size > n )
      this->_size = n;
    if ( this->_ptr > n )
      this->_ptr = n;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030E60
// Name: public: virtual int SQBlob::Seek(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SQBlob::Seek(SQBlob *this, int offset, int origin)
{
  int v3; // eax
  int size; // eax
  int v6; // edx

  if ( origin == 0 )
  {
    v3 = offset + this->_ptr;
    if ( v3 > this->_size || v3 < 0 )
      return -1;
LABEL_12:
    this->_ptr = v3;
    return 0;
  }
  if ( origin != 1 )
  {
    if ( origin != 2 )
      return -1;
    v3 = offset;
    if ( offset > this->_size || offset < 0 )
      return -1;
    goto LABEL_12;
  }
  size = this->_size;
  v6 = size + offset;
  if ( size + offset > size || v6 < 0 )
    return -1;
  this->_ptr = v6;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10030EC0
// Name: public: virtual bool SQBlob::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SQBlob::IsValid(SQBlob *this)
{
  return this->_buf != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10030ED0
// Name: public: virtual bool SQBlob::EOS(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SQBlob::EOS(SQBlob *this)
{
  return this->_ptr == this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x10030EE0
// Name: public: virtual int SQBlob::Tell(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SQBlob::Tell(ConCommandBase *this)
{
  return this->m_pszName;
}

//------------------------------------------------------------------------------
// Address: 0x10030EF0
// Name: public: virtual int SQBlob::Len(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SQBlob::Len(SQBlob *this)
{
  return this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x10031890
// Name: _sqstd_getblobsize
// Source: json
//------------------------------------------------------------------------------
int __usercall sqstd_getblobsize@<eax>(SQVM *v@<eax>)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  SQBlob *v7; // esi
  int v8; // eax
  int v9; // eax
  SQBlob *blob; // [esp+Ch] [ebp-4h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v4 = vals[stackbase + 1]._type == OT_INSTANCE;
  v5 = (int)&vals[stackbase + 1];
  if ( v4 )
  {
    v8 = *(_DWORD *)(v5 + 4);
    v7 = *(SQBlob **)(v8 + 32);
    v9 = *(_DWORD *)(v8 + 28);
    while ( *(_DWORD *)(v9 + 76) != -2147483646 )
    {
      v9 = *(_DWORD *)(v9 + 28);
      if ( v9 == 0 )
      {
        v6 = sq_throwerror(v, err: "invalid type tag");
        goto LABEL_7;
      }
    }
  }
  else
  {
    v6 = sq_throwerror(v, err: "the object is not a class instance");
    v7 = blob;
LABEL_7:
    if ( v6 < 0 )
      return -1;
  }
  return v7->Len(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10031910
// Name: _sqstd_createblob
// Source: json
//------------------------------------------------------------------------------
void *__usercall sqstd_createblob@<eax>(SQVM *v@<eax>, int size)
{
  int v3; // eax
  SQSharedState *sharedstate; // edx
  int v5; // ebx
  SQObjectPtr *v6; // eax
  tagSQObjectValue v7; // edi
  _DWORD *v8; // ecx
  tagSQObjectType v9; // edx
  int v10; // edx
  SQObjectPtr *vals; // eax
  int stackbase; // ecx
  SQObjectPtr *v13; // ecx
  tagSQObjectValue v14; // ebx
  tagSQObjectType v15; // ecx
  int v16; // eax
  int v17; // ecx
  SQObjectPtr *v18; // eax
  tagSQObjectType v19; // edx
  _DWORD *v20; // ecx
  int v21; // ebx
  int v22; // eax
  SQObjectPtr *v23; // ecx
  bool v24; // zf
  int v25; // eax
  const char *v26; // eax
  int v27; // eax
  int v28; // eax
  int top; // [esp+10h] [ebp-Ch]
  _DWORD *v31; // [esp+14h] [ebp-8h]
  tagSQObjectType type; // [esp+18h] [ebp-4h]
  tagSQObjectType v33; // [esp+18h] [ebp-4h]

  v3 = v->_top;
  sharedstate = v->_sharedstate;
  v->_top = v3 + 1;
  v5 = v3 - v->_stackbase;
  v6 = &v->_stack._vals[v3];
  v7.pTable = (SQTable *)sharedstate->_registry._unVal;
  type = v6->_type;
  v8 = &v6->_unVal.pTable->__vftable;
  v6->_unVal = v7;
  v9 = sharedstate->_registry._type;
  top = v5;
  v6->_type = v9;
  if ( (v9 & 0x8000000) != 0 )
    ++*(_DWORD *)(v7.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  sq_pushstring(v, s: "std_blob", len: -1);
  if ( SQVM::Get(
         this: v,
         self: &v->_stack._vals[v->_top - 2],
         key: &v->_stack._vals[v->_top - 1],
         dest: &v->_stack._vals[v->_top - 1],
         raw: false,
         fetchroot: false)
    || (SQVM::Pop(this: v, n: 1), sq_throwerror(v, err: "the index doesn't exist") >= 0) )
  {
    SQVM::Remove(this: v, n: -2);
    v10 = v->_top;
    vals = v->_stack._vals;
    stackbase = v->_stackbase;
    v->_top = v10 + 1;
    v33 = vals[v10]._type;
    v13 = &vals[stackbase];
    v31 = &vals[v10]._unVal.pTable->__vftable;
    v14.pTable = (SQTable *)v13->_unVal;
    vals[v10]._unVal = v14;
    v15 = v13->_type;
    vals[v10]._type = v15;
    if ( (v15 & 0x8000000) != 0 )
      ++*(_DWORD *)(v14.nInteger + 4);
    if ( (v33 & 0x8000000) != 0 && (int)--v31[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v31 + 8))(a1: v31);
    v16 = v->_top;
    v17 = v16 + 1;
    v18 = &v->_stack._vals[v16];
    v->_top = v17;
    v19 = v18->_type;
    v20 = &v18->_unVal.pTable->__vftable;
    v18->_unVal.nInteger = size;
    v18->_type = OT_INTEGER;
    if ( (v19 & 0x8000000) != 0 && (int)--v20[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v20 + 8))(a1: v20);
    v21 = 0;
    if ( sq_call(v, params: 2, retval: 1u, raiseerror: 0) >= 0 )
    {
      v22 = v->_top;
      v23 = v->_stack._vals;
      v24 = v23[v22 - 1]._type == OT_INSTANCE;
      v25 = (int)&v23[v22 - 1];
      if ( v24 )
      {
        v27 = *(_DWORD *)(v25 + 4);
        v21 = *(_DWORD *)(v27 + 32);
        v28 = *(_DWORD *)(v27 + 28);
        while ( *(_DWORD *)(v28 + 76) != -2147483646 )
        {
          v28 = *(_DWORD *)(v28 + 28);
          if ( v28 == 0 )
          {
            v26 = "invalid type tag";
            goto LABEL_23;
          }
        }
        goto LABEL_24;
      }
      v26 = "the object is not a class instance";
LABEL_23:
      if ( sq_throwerror(v, err: v26) >= 0 )
      {
LABEL_24:
        SQVM::Remove(this: v, n: -2);
        return *(void **)(v21 + 16);
      }
    }
    v5 = top;
  }
  sq_settop(v, newtop: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10030F40
// Name: _blob_resize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl blob_resize(int v)
{
  SQObjectPtr *v1; // eax
  SQBlob *v2; // esi
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax
  int v7; // edx
  SQObjectPtr *v8; // eax
  tagSQObjectType type; // ecx
  int v10; // eax
  SQVM *v11; // eax

  v1 = (SQObjectPtr *)(*(_DWORD *)(v + 32) + 8 * *(_DWORD *)(v + 60));
  v2 = nullptr;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(SQBlob **)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != -2147483646 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror((SQVM *)v, err: v3) < 0 )
      return -1;
  }
  v7 = *(_DWORD *)(v + 60);
  v8 = *(SQObjectPtr **)(v + 32);
  type = v8[v7 + 1]._type;
  v10 = (int)&v8[v7 + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      v11 = (SQVM *)(int)*(float *)(v10 + 4);
    else
      v11 = *(SQVM **)(v10 + 4);
  }
  else
  {
    v11 = (SQVM *)v;
  }
  if ( SQBlob::Resize(this: v2, n: (int)v11, a3: v) != 0 )
    return 0;
  else
    return sq_throwerror((SQVM *)v, err: "resize failed");
}

//------------------------------------------------------------------------------
// Address: 0x10030FF0
// Name: _blob_swap4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl blob_swap4(SQVM *v)
{
  SQObjectPtr *v1; // eax
  _DWORD *v2; // esi
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax
  int v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int i; // edx

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = nullptr;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD **)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != -2147483646 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return -1;
  }
  v7 = (*(int (__thiscall **)(_DWORD *))(*v2 + 20))(a1: v2) % 4;
  v8 = (*(int (__thiscall **)(_DWORD *))(*v2 + 20))(a1: v2);
  v9 = v2[4];
  v10 = (v8 - v7) >> 2;
  for ( i = 0; i < v10; ++i )
    *(_DWORD *)(v9 + 4 * i) = (*(_DWORD *)(v9 + 4 * i) >> 8) & 0xFF00
                            | *(unsigned __int8 *)(v9 + 4 * i + 3)
                            | ((*(_DWORD *)(v9 + 4 * i) & 0xFF00 | (*(_DWORD *)(v9 + 4 * i) << 16)) << 8);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100310B0
// Name: _blob_swap2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl blob_swap2(SQVM *v)
{
  SQObjectPtr *v1; // eax
  _DWORD *v2; // esi
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax
  int v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int i; // ecx

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = nullptr;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD **)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != -2147483646 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return -1;
  }
  v7 = (*(int (__thiscall **)(_DWORD *))(*v2 + 20))(a1: v2) % 2;
  v8 = (*(int (__thiscall **)(_DWORD *))(*v2 + 20))(a1: v2);
  v9 = v2[4];
  v10 = (v8 - v7) >> 1;
  for ( i = 0; i < v10; ++i )
    *(_WORD *)(v9 + 2 * i) = (*(_WORD *)(v9 + 2 * i) << 8) | *(unsigned __int8 *)(v9 + 2 * i + 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10031150
// Name: _blob__set
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl blob__set(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  const char *v5; // eax
  tagSQObjectValue v6; // eax
  SQBlob *v7; // edx
  int v8; // eax
  int v10; // eax
  SQObjectPtr *v11; // ecx
  tagSQObjectType type; // edx
  SQVM *fFloat; // esi
  tagSQObjectType v14; // edx
  int nInteger; // ebx
  SQBlob *self; // [esp+4h] [ebp-4h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  self = nullptr;
  if ( v3 )
  {
    v6.pTable = (SQTable *)v4->_unVal;
    v7 = *(SQBlob **)(v6.nInteger + 32);
    v8 = *(_DWORD *)(v6.nInteger + 28);
    self = v7;
    while ( *(_DWORD *)(v8 + 76) != -2147483646 )
    {
      v8 = *(_DWORD *)(v8 + 28);
      if ( v8 == 0 )
      {
        v5 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v5 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v5) < 0 )
      return -1;
  }
  v10 = v->_stackbase;
  v11 = v->_stack._vals;
  type = v11[v10 + 1]._type;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      fFloat = (SQVM *)(int)v11[v10 + 1]._unVal.fFloat;
    else
      fFloat = v11[v10 + 1]._unVal.pThread;
  }
  else
  {
    fFloat = v;
  }
  v14 = v11[v10 + 2]._type;
  if ( (v14 & 0x4000000) != 0 )
  {
    if ( v14 == OT_FLOAT )
      nInteger = (int)v11[v10 + 2]._unVal.fFloat;
    else
      nInteger = v11[v10 + 2]._unVal.nInteger;
  }
  else
  {
    LOBYTE(nInteger) = (_BYTE)v;
  }
  if ( (int)fFloat < 0 || (int)fFloat >= self->Len(this: self) )
    return sq_throwerror(v, err: "index out of range");
  *((_BYTE *)&fFloat->__vftable + (unsigned int)self->_buf) = nInteger;
  sq_push(v, idx: 3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031250
// Name: _blob__get
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl blob__get(SQVM *v)
{
  SQObjectPtr *v1; // eax
  _DWORD *v2; // ebx
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax
  int stackbase; // edx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // ecx
  int v10; // eax
  int v11; // esi
  int idx; // [esp+Ch] [ebp-4h]

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = nullptr;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD **)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != -2147483646 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return -1;
  }
  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  type = vals[stackbase + 1]._type;
  v10 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      v11 = (int)*(float *)(v10 + 4);
    else
      v11 = *(_DWORD *)(v10 + 4);
  }
  else
  {
    v11 = idx;
  }
  if ( v11 < 0 || v11 >= (*(int (__thiscall **)(_DWORD *))(*v2 + 20))(a1: v2) )
    return sq_throwerror(v, err: "index out of range");
  sq_pushinteger(v, n: (tagSQObjectValue)*(unsigned __int8 *)(v2[4] + v11));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031320
// Name: _blob__nexti
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl blob__nexti(SQVM *v)
{
  SQObjectPtr *v1; // eax
  int v2; // ebx
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax
  SQObjectPtr *vals; // edx
  int stackbase; // eax
  bool v9; // zf
  int v10; // eax
  int top; // eax
  tagSQObjectType type; // esi
  _DWORD *v13; // ecx
  int v14; // eax
  tagSQObjectValue v15; // esi

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = 0;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD *)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != -2147483646 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return -1;
  }
  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  v9 = vals[stackbase + 1]._type == OT_NULL;
  v10 = (int)&vals[stackbase + 1];
  if ( v9 )
  {
    top = v->_top;
    v->_top = top + 1;
    type = vals[top]._type;
    v13 = &vals[top]._unVal.pTable->__vftable;
    vals[top]._unVal.nInteger = 0;
    vals[top]._type = OT_INTEGER;
    if ( (type & 0x8000000) != 0 && (int)--v13[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
    return 1;
  }
  else if ( (*(_DWORD *)v10 & 0x4000000) != 0 )
  {
    if ( *(_DWORD *)v10 == 83886084 )
      v14 = (int)*(float *)(v10 + 4);
    else
      v14 = *(_DWORD *)(v10 + 4);
    v15.nInteger = v14 + 1;
    if ( v14 + 1 >= (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 20))(a1: v2) )
      sq_pushnull(v);
    else
      sq_pushinteger(v, n: v15);
    return 1;
  }
  else
  {
    return sq_throwerror(v, err: "internal error (_nexti) wrong argument type");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031440
// Name: _blob__typeof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl blob__typeof(SQVM *v)
{
  sq_pushstring(v, s: "blob", len: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031460
// Name: _blob_releasehook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl blob_releasehook(void (__thiscall ***p)(void *, int))
{
  if ( p != nullptr )
    (**p)(a1: p, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031480
// Name: _blob_constructor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl blob_constructor(SQVM *v)
{
  int stackbase; // eax
  signed int v2; // ebx
  SQObjectPtr *vals; // edx
  tagSQObjectType type; // ecx
  int v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  void *v8; // eax
  int v9; // edx
  SQObjectPtr *v10; // eax
  bool v11; // zf
  SQObjectPtr *v12; // eax
  int v14; // eax
  SQObjectPtr *v15; // ecx
  tagSQObjectType v16; // eax
  unsigned int v17; // [esp-4h] [ebp-14h]

  stackbase = v->_stackbase;
  v2 = 0;
  if ( v->_top - stackbase == 2 )
  {
    vals = v->_stack._vals;
    type = vals[stackbase + 1]._type;
    v5 = (int)&vals[stackbase + 1];
    if ( (type & 0x4000000) != 0 )
    {
      v2 = type == OT_FLOAT ? (int)*(float *)(v5 + 4) : *(_DWORD *)(v5 + 4);
      if ( v2 < 0 )
        return sq_throwerror(v, err: "cannot create blob with negative size");
    }
  }
  v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24);
  v7 = v6;
  if ( v6 != nullptr )
  {
    *v6 = &SQBlob::`vftable';
    v6[1] = v2;
    v6[2] = v2;
    v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v2);
    v17 = v7[1];
    v7[4] = v8;
    memset(dst: (int)v8, value: nullptr, count: v17);
    v7[3] = 0;
    *((_BYTE *)v7 + 20) = 1;
  }
  else
  {
    v7 = nullptr;
  }
  v9 = v->_stackbase;
  v10 = v->_stack._vals;
  v11 = v10[v9]._type == OT_INSTANCE;
  v12 = &v10[v9];
  if ( v11 )
  {
    *(_DWORD *)(v12->_unVal.nInteger + 32) = v7;
  }
  else if ( sq_throwerror(v, err: "the object is not a class instance") < 0 )
  {
    if ( v7 != nullptr )
      (*(void (__thiscall **)(_DWORD *, int))*v7)(a1: v7, a2: 1);
    return sq_throwerror(v, err: "cannot create blob with negative size");
  }
  v14 = v->_stackbase;
  if ( v->_top - v14 >= 1 )
  {
    v15 = &v->_stack._vals[v14];
    v16 = v15->_type;
    if ( v15->_type == OT_CLASS )
    {
      *(_DWORD *)(v15->_unVal.nInteger + 80) = blob_releasehook;
    }
    else
    {
      if ( v16 == OT_USERDATA )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 32) = blob_releasehook;
        return 0;
      }
      if ( v16 == OT_INSTANCE )
      {
        *(_DWORD *)(v15->_unVal.nInteger + 36) = blob_releasehook;
        return 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100315D0
// Name: _g_blob_casti2f
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl g_blob_casti2f(tagSQObjectValue v)
{
  SQVM *nInteger; // ecx
  SQObjectPtr *v2; // edx
  tagSQObjectType type; // eax
  SQVM *fFloat; // eax
  int top; // eax
  tagSQObjectType v6; // esi
  _DWORD *v7; // ecx

  nInteger = (SQVM *)v.nInteger;
  v2 = *(SQObjectPtr **)(v.nInteger + 32);
  type = v2[*(_DWORD *)(v.nInteger + 60) + 1]._type;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      fFloat = (SQVM *)(int)v2[*(_DWORD *)(v.nInteger + 60) + 1]._unVal.fFloat;
    else
      fFloat = v2[*(_DWORD *)(v.nInteger + 60) + 1]._unVal.pThread;
    v.nInteger = (int)fFloat;
  }
  top = nInteger->_top;
  nInteger->_top = top + 1;
  v6 = v2[top]._type;
  v7 = &v2[top]._unVal.pTable->__vftable;
  v2[top]._unVal = v;
  v2[top]._type = OT_FLOAT;
  if ( (v6 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031650
// Name: _g_blob_castf2i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl g_blob_castf2i(tagSQObjectValue v)
{
  SQVM *nInteger; // ecx
  SQObjectPtr *v2; // edx
  tagSQObjectType type; // eax
  float fFloat; // xmm0_4
  int top; // eax
  tagSQObjectType v6; // esi
  _DWORD *v7; // ecx

  nInteger = (SQVM *)v.nInteger;
  v2 = *(SQObjectPtr **)(v.nInteger + 32);
  type = v2[*(_DWORD *)(v.nInteger + 60) + 1]._type;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      fFloat = (float)v2[*(_DWORD *)(v.nInteger + 60) + 1]._unVal.nInteger;
    else
      fFloat = v2[*(_DWORD *)(v.nInteger + 60) + 1]._unVal.fFloat;
    v.fFloat = fFloat;
  }
  top = nInteger->_top;
  nInteger->_top = top + 1;
  v6 = v2[top]._type;
  v7 = &v2[top]._unVal.pTable->__vftable;
  v2[top]._unVal = v;
  v2[top]._type = OT_INTEGER;
  if ( (v6 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100316D0
// Name: _g_blob_swap2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl g_blob_swap2(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // esi
  tagSQObjectType type; // edx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int top; // edx
  tagSQObjectType v8; // edi
  _DWORD *v9; // ecx

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      v5 = (int)*(float *)(v4 + 4);
    else
      v5 = *(_DWORD *)(v4 + 4);
  }
  else
  {
    LOWORD(v5) = (_WORD)v;
  }
  v6 = ((__int16)v5 << 8) | BYTE1(v5);
  top = v->_top;
  v->_top = top + 1;
  v8 = vals[top]._type;
  v9 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.nInteger = v6;
  vals[top]._type = OT_INTEGER;
  if ( (v8 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031750
// Name: _g_blob_swap4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl g_blob_swap4(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  int top; // edx
  tagSQObjectType v8; // edi
  _DWORD *v9; // ecx

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      v5 = (int)*(float *)(v4 + 4);
    else
      v5 = *(_DWORD *)(v4 + 4);
  }
  else
  {
    v5 = (unsigned int)v;
  }
  v6 = (((v5 << 16) | v5 & 0xFF00) << 8) | ((HIWORD(v5) | v5 & 0xFF0000) >> 8);
  top = v->_top;
  v->_top = top + 1;
  v8 = vals[top]._type;
  v9 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.nInteger = v6;
  vals[top]._type = OT_INTEGER;
  if ( (v8 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100317F0
// Name: _g_blob_swapfloat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl g_blob_swapfloat(unsigned int v)
{
  SQVM *v1; // edi
  SQObjectPtr *v2; // esi
  int v3; // eax
  tagSQObjectType type; // ecx
  int v5; // eax
  float v6; // xmm0_4
  int top; // edx
  tagSQObjectType v8; // edi
  _DWORD *v9; // ecx

  v1 = (SQVM *)v;
  v2 = *(SQObjectPtr **)(v + 32);
  v3 = *(_DWORD *)(v + 60);
  type = v2[v3 + 1]._type;
  v5 = (int)&v2[v3 + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v6 = (float)*(int *)(v5 + 4);
    else
      v6 = *(float *)(v5 + 4);
    v = LODWORD(v6);
  }
  top = v1->_top;
  v1->_top = top + 1;
  v8 = v2[top]._type;
  v9 = &v2[top]._unVal.pTable->__vftable;
  v2[top]._unVal.nInteger = (((v << 16) | v & 0xFF00) << 8) | ((HIWORD(v) | v & 0xFF0000) >> 8);
  v2[top]._type = OT_FLOAT;
  if ( (v8 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  return 1;
}
