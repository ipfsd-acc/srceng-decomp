// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqdebug.cpp
// Functions: 7
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqdebug.h"

//------------------------------------------------------------------------------
// Address: 0x10047CF0
// Name: _sq_stackinfos
// Source: json
//------------------------------------------------------------------------------
int __fastcall sq_stackinfos(int level, SQVM *v, tagSQStackInfos *si)
{
  int callsstacksize; // eax
  SQVM::CallInfo *v4; // eax
  tagSQObjectType type; // ecx
  tagSQObjectValue v6; // eax
  bool v7; // zf
  char *v9; // ecx
  int *v10; // edx
  int v11; // edi
  int v12; // eax
  int v13; // ecx
  int v14; // esi
  int v15; // eax
  int *v16; // edx

  callsstacksize = v->_callsstacksize;
  if ( callsstacksize <= level )
    return -1;
  v4 = &v->_callsstack[callsstacksize - level - 1];
  type = v4->_closure._type;
  *(_QWORD *)&si->funcname = 0;
  si->line = 0;
  if ( type == OT_CLOSURE )
  {
    v9 = *(char **)(v4->_closure._unVal.nInteger + 36);
    if ( *((_DWORD *)v9 + 5) == 134217744 )
      si->funcname = (const char *)(*((_DWORD *)v9 + 6) + 28);
    if ( *((_DWORD *)v9 + 3) == 134217744 )
      si->source = (const char *)(*((_DWORD *)v9 + 4) + 28);
    v10 = *((int **)v9 + 12);
    v11 = *v10;
    v12 = (char *)v4->_ip - v9;
    v13 = *((_DWORD *)v9 + 11);
    v14 = 1;
    v15 = (v12 - 96) >> 3;
    if ( v13 > 1 )
    {
      v16 = v10 + 2;
      do
      {
        if ( v16[1] >= v15 )
          break;
        v11 = *v16;
        ++v14;
        v16 += 2;
      }
      while ( v14 < v13 );
    }
    si->line = v11;
  }
  else if ( type == OT_NATIVECLOSURE )
  {
    v6.pTable = (SQTable *)v4->_closure._unVal;
    v7 = *(_DWORD *)(v6.nInteger + 64) == 134217744;
    si->source = "NATIVE";
    si->funcname = "unknown";
    if ( v7 )
      si->funcname = (const char *)(*(_DWORD *)(v6.nInteger + 68) + 28);
    si->line = -1;
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10047DD0
// Name: public: void SQVM::Raise_Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQVM::Raise_Error(_DWORD *a1@<edi>, SQVM *this, const char *s, ...)
{
  unsigned int v3; // kr00_4
  char *ScratchPad; // eax
  SQSharedState *v5; // ebx
  SQString *v6; // esi
  int v7; // eax
  _DWORD *v8; // ecx
  int v9; // [esp+0h] [ebp-8h]

  v3 = strlen((const char *)this);
  if ( (int)(v3 + 100) <= 0 )
    ScratchPad = *(char **)(a1[37] + 180);
  else
    ScratchPad = SQSharedState::GetScratchPad(this: (SQSharedState *)(v3 + 100), size: v9);
  vsprintf(string: ScratchPad, format: (const char *)this, ap: (char *)&s);
  v5 = (SQSharedState *)a1[37];
  v6 = StringTable::Add(this: v5->_stringtable, news: v5->_scratchpad, len: -1);
  v6->_sharedstate = v5;
  ++v6->_uiRef;
  v7 = a1[18];
  v8 = (_DWORD *)a1[19];
  a1[19] = v6;
  a1[18] = 134217744;
  ++v6->_uiRef;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  if ( --v6->_uiRef <= 0 )
    v6->Release(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10047E80
// Name: public: void SQVM::Raise_Error(struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQVM::Raise_Error(SQVM *this@<eax>, SQObjectPtr *desc@<edx>)
{
  _DWORD *v2; // ecx
  tagSQObjectType type; // esi
  tagSQObjectValue v4; // edi
  tagSQObjectType v5; // edx

  v2 = &this->_lasterror._unVal.pTable->__vftable;
  type = this->_lasterror._type;
  v4.pTable = (SQTable *)desc->_unVal;
  this->_lasterror._unVal = v4;
  v5 = desc->_type;
  this->_lasterror._type = v5;
  if ( (v5 & 0x8000000) != 0 )
    ++*(_DWORD *)(v4.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v2[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v2 + 8))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10047EC0
// Name: public: struct SQString __near * SQVM::PrintObjVal(struct tagSQObject const __near &)
// Source: json
//------------------------------------------------------------------------------
SQString *__thiscall SQVM::PrintObjVal(SQVM *this, SQVM *o, const tagSQObject *oa)
{
  tagSQObjectType type; // eax
  _DWORD *v4; // edi
  int v5; // ebx
  SQSharedState *v6; // esi
  const char *v7; // eax
  SQString *result; // eax
  tagSQObjectValue v9; // esi
  int v10; // eax
  void *v11; // eax
  int v12; // edi
  SQSharedState *v13; // esi
  tagSQObjectValue v14; // esi
  int v15; // eax
  void *v16; // eax
  int v17; // edi
  SQSharedState *sharedstate; // esi
  SQVM *thisa; // [esp+24h] [ebp+8h]

  type = oa->_type;
  switch ( oa->_type )
  {
    case OT_INTEGER:
      v14.pTable = (SQTable *)o->_sharedstate;
      v15 = *(_DWORD *)(v14.nInteger + 184);
      if ( v15 >= 51 )
      {
        if ( v15 < 1632 )
        {
LABEL_21:
          sprintf(string: *(char **)(v14.nInteger + 180), format: "%d", oa->_unVal.nInteger);
          sharedstate = o->_sharedstate;
          result = StringTable::Add(this: sharedstate->_stringtable, news: sharedstate->_scratchpad, len: -1);
          result->_sharedstate = sharedstate;
          return result;
        }
        v17 = v15 >> 1;
        v16 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(v14.nInteger + 180), a3: v15 >> 1);
        *(_DWORD *)(v14.nInteger + 184) = v17;
      }
      else
      {
        v16 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(v14.nInteger + 180), a3: 76);
        *(_DWORD *)(v14.nInteger + 184) = 76;
      }
      *(_DWORD *)(v14.nInteger + 180) = v16;
      goto LABEL_21;
    case OT_FLOAT:
      v9.pTable = (SQTable *)o->_sharedstate;
      v10 = *(_DWORD *)(v9.nInteger + 184);
      if ( v10 >= 51 )
      {
        if ( v10 < 1632 )
        {
LABEL_15:
          sprintf(string: *(char **)(v9.nInteger + 180), format: "%.14g", oa->_unVal.fFloat);
          v13 = o->_sharedstate;
          result = StringTable::Add(this: v13->_stringtable, news: v13->_scratchpad, len: -1);
          result->_sharedstate = v13;
          return result;
        }
        v12 = v10 >> 1;
        v11 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(v9.nInteger + 180), a3: v10 >> 1);
        *(_DWORD *)(v9.nInteger + 184) = v12;
      }
      else
      {
        v11 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(v9.nInteger + 180), a3: 76);
        *(_DWORD *)(v9.nInteger + 184) = 76;
      }
      *(_DWORD *)(v9.nInteger + 180) = v11;
      goto LABEL_15;
    case OT_STRING:
      return oa->_unVal.pString;
    default:
      break;
  }
  v4 = &oa->_unVal.pTable->__vftable;
  v5 = type & 0x8000000;
  if ( (type & 0x8000000) != 0 )
    ++v4[1];
  v6 = o->_sharedstate;
  v7 = IdType2Name(type);
  result = StringTable::Add(this: v6->_stringtable, news: v7, len: -1);
  thisa = (SQVM *)result;
  result->_sharedstate = v6;
  if ( v5 != 0 && (int)--v4[1] <= 0 )
  {
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
    return (SQString *)thisa;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100480A0
// Name: public: void SQVM::Raise_IdxError(struct tagSQObject __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQVM::Raise_IdxError(SQVM *this@<ecx>, tagSQObject *o@<eax>)
{
  SQString *v3; // esi

  v3 = SQVM::PrintObjVal(this, o: this, oa: o);
  ++v3->_uiRef;
  SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009C8A0, s: v3->_val);
  if ( --v3->_uiRef <= 0 )
    v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100480E0
// Name: public: void SQVM::Raise_CompareError(struct tagSQObject const __near &,struct tagSQObject const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQVM::Raise_CompareError(SQVM *this@<ecx>, const tagSQObject *o1@<eax>, SQVM *o2)
{
  SQString *v4; // ebx
  SQString *v5; // esi

  v4 = SQVM::PrintObjVal(this, o: this, oa: o1);
  ++v4->_uiRef;
  v5 = SQVM::PrintObjVal(this: o2, o: this, oa: (const tagSQObject *)o2);
  ++v5->_uiRef;
  SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009C8A0._stack._size, s: v4->_val, v5->_val);
  if ( --v5->_uiRef <= 0 )
    v5->Release(this: v5);
  if ( --v4->_uiRef <= 0 )
    v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10048150
// Name: public: void SQVM::Raise_ParamTypeError(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQVM::Raise_ParamTypeError(
        SQVM *this@<ecx>,
        SQObjectPtr *a2@<eax>,
        const char *nparam,
        int typemask,
        tagSQObjectType type)
{
  SQSharedState *pTable; // esi
  SQString *v7; // eax
  SQSharedState *v8; // ebx
  SQString *v9; // esi
  SQSharedState *v10; // ebx
  const char *v11; // eax
  SQString *v12; // esi
  bool v13; // zf
  _DWORD *v14; // esi
  const char *v15; // eax
  int v16; // [esp-4h] [ebp-38h]
  SQObjectPtr v17; // [esp+Ch] [ebp-28h] BYREF
  SQObjectPtr dest; // [esp+14h] [ebp-20h] BYREF
  SQObjectPtr exptypes; // [esp+1Ch] [ebp-18h] BYREF
  int v20; // [esp+24h] [ebp-10h]
  int found; // [esp+28h] [ebp-Ch]
  tagSQObjectType v22; // [esp+2Ch] [ebp-8h]

  pTable = (SQSharedState *)a2[18]._unVal.pTable;
  v7 = StringTable::Add(this: pTable->_stringtable, news: Ptr, len: -1);
  v7->_sharedstate = pTable;
  ++v7->_uiRef;
  exptypes._type = OT_STRING;
  exptypes._unVal.nInteger = (int)v7;
  found = 0;
  v22 = 1;
  v20 = 16;
  do
  {
    if ( (typemask & v22) != 0 )
    {
      if ( found > 0 )
      {
        v8 = (SQSharedState *)a2[18]._unVal.pTable;
        v9 = StringTable::Add(this: v8->_stringtable, news: (const char *)&stru_1009C8A0._lasterror._unVal, len: -1);
        v9->_sharedstate = v8;
        ++v9->_uiRef;
        dest._type = OT_STRING;
        dest._unVal.nInteger = (int)v9;
        SQVM::StringCat(this: (SQVM *)&dest, str: a2, obj: &exptypes, &dest);
        if ( --v9->_uiRef <= 0 )
          v9->Release(this: v9);
      }
      ++found;
      v10 = (SQSharedState *)a2[18]._unVal.pTable;
      v11 = IdType2Name(type: v22);
      v12 = StringTable::Add(this: v10->_stringtable, news: v11, len: -1);
      v12->_sharedstate = v10;
      ++v12->_uiRef;
      v17._type = OT_STRING;
      v17._unVal.nInteger = (int)v12;
      SQVM::StringCat(this: (SQVM *)&exptypes, str: a2, obj: &exptypes, dest: &v17);
      if ( --v12->_uiRef <= 0 )
        v12->Release(this: v12);
    }
    v13 = v20-- == 1;
    v22 = __ROL4__(v22, 1);
  }
  while ( !v13 );
  v14 = &exptypes._unVal.pTable->__vftable;
  v16 = exptypes._unVal.nInteger + 28;
  v15 = IdType2Name(type);
  SQVM::Raise_Error(a1: a2, this: (SQVM *)&stru_1009C8A0._errorhandler, s: nparam, v15, v16);
  if ( (exptypes._type & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
}
