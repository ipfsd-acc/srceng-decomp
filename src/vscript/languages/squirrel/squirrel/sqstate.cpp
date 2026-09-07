// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqstate.cpp
// Functions: 20
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqstate.h"

//------------------------------------------------------------------------------
// Address: 0x10051410
// Name: unsigned int HashObj(struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall HashObj(const SQObjectPtr *key)
{
  tagSQObjectType type; // eax

  type = key->_type;
  if ( key->_type <= OT_FLOAT )
  {
    if ( key->_type == OT_FLOAT )
      return (int)key->_unVal.fFloat;
    if ( type == OT_BOOL || type == OT_INTEGER )
      return key->_unVal.nInteger;
  }
  else if ( type == OT_STRING )
  {
    return *(_DWORD *)(key->_unVal.nInteger + 24);
  }
  return key->_unVal.nInteger >> 3;
}

//------------------------------------------------------------------------------
// Address: 0x10051450
// Name: public: SQSharedState::SQSharedState(void)
// Source: json
//------------------------------------------------------------------------------
SQSharedState *__usercall SQSharedState::SQSharedState@<eax>(SQSharedState *this@<ecx>, int a2@<esi>)
{
  *(_DWORD *)(a2 + 4) = 16777217;
  *(_DWORD *)(a2 + 8) = 0;
  RefTable::AllocNodes(this: (RefTable *)(a2 + 24), size: 4u);
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 44) = 16777217;
  *(_DWORD *)(a2 + 52) = 16777217;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 16777217;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 72) = 16777217;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 16777217;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 16777217;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 16777217;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 16777217;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 112) = 16777217;
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 120) = 16777217;
  *(_DWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 128) = 16777217;
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 16777217;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 144) = 16777217;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 152) = 16777217;
  *(_DWORD *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  *(_WORD *)(a2 + 168) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  *(_DWORD *)(a2 + 176) = 0;
  return (SQSharedState *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10051500
// Name: bool CompileTypemask(class sqvector<int> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall CompileTypemask@<al>(const char *typemask@<eax>, sqvector<int> *res)
{
  int v2; // esi
  const char *v3; // edi
  unsigned int v5; // eax
  unsigned int v6; // edi
  int *v7; // eax
  unsigned int v8; // eax
  int *v9; // ecx
  unsigned int size; // eax
  unsigned int v11; // esi
  unsigned int v12; // eax
  int *v13; // ecx
  const char *v14; // [esp+Ch] [ebp-4h]

  v2 = 0;
  if ( *typemask != 0 )
  {
    v3 = typemask;
    while ( 1 )
    {
      switch ( *v3 )
      {
        case ' ':
          ++v3;
          goto LABEL_38;
        case '.':
          size = res->_size;
          if ( res->_allocated <= size )
          {
            v11 = 2 * size;
            if ( 2 * size == 0 )
              v11 = 4;
            res->_vals = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: res->_vals, a3: 4 * v11);
            res->_allocated = v11;
          }
          v12 = res->_size;
          v13 = &res->_vals[v12];
          res->_size = v12 + 1;
          if ( v13 != nullptr )
            *v13 = -1;
          ++v3;
          v2 = 0;
          goto LABEL_38;
        case 'a':
          v2 |= 0x40u;
          goto LABEL_20;
        case 'b':
          v2 |= 8u;
          goto LABEL_20;
        case 'c':
          v2 |= 0x300u;
          goto LABEL_20;
        case 'f':
          v2 |= 4u;
          goto LABEL_20;
        case 'g':
          v2 |= 0x400u;
          goto LABEL_20;
        case 'i':
          v2 |= 2u;
          goto LABEL_20;
        case 'n':
          v2 |= 6u;
          goto LABEL_20;
        case 'o':
          v2 |= 1u;
          goto LABEL_20;
        case 'p':
          v2 |= 0x800u;
          goto LABEL_20;
        case 'r':
          v2 |= 0x10000u;
          goto LABEL_20;
        case 's':
          v2 |= 0x10u;
          goto LABEL_20;
        case 't':
          v2 |= 0x20u;
          goto LABEL_20;
        case 'u':
          v2 |= 0x80u;
          goto LABEL_20;
        case 'v':
          v2 |= 0x1000u;
          goto LABEL_20;
        case 'x':
          v2 |= 0x8000u;
          goto LABEL_20;
        case 'y':
          v2 |= 0x4000u;
LABEL_20:
          v14 = ++v3;
          if ( *v3 == 124 )
          {
            if ( *++v3 == 0 )
              return 0;
          }
          else
          {
            v5 = res->_size;
            if ( res->_allocated <= v5 )
            {
              v6 = 2 * v5;
              if ( 2 * v5 == 0 )
                v6 = 4;
              v7 = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: res->_vals, a3: 4 * v6);
              res->_allocated = v6;
              v3 = v14;
              res->_vals = v7;
            }
            v8 = res->_size;
            v9 = &res->_vals[v8];
            res->_size = v8 + 1;
            if ( v9 != nullptr )
              *v9 = v2;
            v2 = 0;
LABEL_38:
            if ( *v3 == 0 )
              return 1;
          }
          break;
        default:
          return 0;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10051710
// Name: struct SQTable __near * CreateDefaultDelegate(struct SQSharedState __near *,struct tagSQRegFunction __near *)
// Source: json
//------------------------------------------------------------------------------
SQTable *__cdecl CreateDefaultDelegate(SQSharedState *ss, tagSQRegFunction *funcz)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  SQTable *result; // eax
  SQCollectable *gc_chain; // ecx
  IMemAlloc_vtbl *v5; // edx
  _DWORD *v6; // eax
  tagSQObjectValue v7; // esi
  int (__cdecl *v8)(SQVM *); // ecx
  SQCollectable *v9; // eax
  const char **p_name; // eax
  SQString *v11; // edi
  int v12; // eax
  _DWORD *v13; // ecx
  const char **v14; // edi
  const char *typemask; // eax
  SQString *v16; // eax
  tagSQObjectValue v17; // eax
  tagSQObjectValue v18; // eax
  bool v19; // zf
  SQObjectPtr val; // [esp+10h] [ebp-20h] BYREF
  SQObjectPtr key; // [esp+18h] [ebp-18h] BYREF
  int (__cdecl *f)(SQVM *); // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  SQTable *v24; // [esp+28h] [ebp-8h]
  tagSQRegFunction *v25; // [esp+2Ch] [ebp-4h]

  Alloc_2 = _g_pMemAlloc->Alloc_2;
  i = 0;
  result = (SQTable *)Alloc_2(this: _g_pMemAlloc, a2: 44u);
  v24 = result;
  if ( result != nullptr )
  {
    result->_uiRef = 0;
    result->_weakref = nullptr;
    result->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    SQTable::AllocNodes(this: result, nSize: 4);
    result = v24;
    v24->_next = nullptr;
    result->_usednodes = 0;
    result->_delegate = nullptr;
    result->_sharedstate = ss;
    result->_prev = nullptr;
    result->_next = ss->_gc_chain;
    gc_chain = ss->_gc_chain;
    if ( gc_chain != nullptr )
      gc_chain->_prev = result;
    ss->_gc_chain = result;
  }
  result->_delegate = nullptr;
  if ( funcz->name != nullptr )
  {
    v25 = funcz;
    while ( 1 )
    {
      v5 = _g_pMemAlloc->__vftable;
      f = v25->f;
      v6 = v5->Alloc_2(this: _g_pMemAlloc, a2: 72u);
      v7.nInteger = (int)v6;
      if ( v6 != nullptr )
      {
        v8 = f;
        v6[1] = 0;
        v6[2] = 0;
        *v6 = &SQNativeClosure::`vftable';
        v6[7] = 0;
        v6[8] = 0;
        v6[9] = 0;
        v6[10] = 0;
        v6[11] = 0;
        v6[12] = 0;
        v6[14] = 0;
        v6[13] = 16777217;
        v6[16] = 16777217;
        v6[17] = 0;
        v6[3] = 0;
        v6[15] = v8;
        v6[5] = ss;
        v6[4] = 0;
        v6[3] = ss->_gc_chain;
        v9 = ss->_gc_chain;
        if ( v9 != nullptr )
          v9->_prev = v7.pTable;
        ss->_gc_chain = v7.pTable;
      }
      p_name = &v25->name;
      *(_DWORD *)(v7.nInteger + 24) = v25->nparamscheck;
      v11 = StringTable::Add(this: ss->_stringtable, news: *p_name, len: -1);
      v11->_sharedstate = ss;
      ++v11->_uiRef;
      v12 = *(_DWORD *)(v7.nInteger + 64);
      v13 = *(_DWORD **)(v7.nInteger + 68);
      *(_DWORD *)(v7.nInteger + 68) = v11;
      *(_DWORD *)(v7.nInteger + 64) = 134217744;
      ++v11->_uiRef;
      if ( (v12 & 0x8000000) != 0 && (int)--v13[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
      if ( --v11->_uiRef <= 0 )
        v11->Release(this: v11);
      v14 = &v25->name;
      typemask = v25->typemask;
      if ( typemask != nullptr && CompileTypemask(typemask, res: (sqvector<int> *)(v7.nInteger + 28)) == 0 )
        break;
      val._type = OT_NATIVECLOSURE;
      val._unVal = v7;
      ++*(_DWORD *)(v7.nInteger + 4);
      v16 = StringTable::Add(this: ss->_stringtable, news: *v14, len: -1);
      v16->_sharedstate = ss;
      key._unVal.nInteger = (int)v16;
      key._type = OT_STRING;
      ++v16->_uiRef;
      SQTable::NewSlot(this: v24, &key, &val);
      if ( (key._type & 0x8000000) != 0 )
      {
        v17.pTable = (SQTable *)key._unVal;
        --*(_DWORD *)(key._unVal.nInteger + 4);
        if ( *(int *)(v17.nInteger + 4) <= 0 )
          key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
      }
      if ( (val._type & 0x8000000) != 0 )
      {
        v18.pTable = (SQTable *)val._unVal;
        --*(_DWORD *)(val._unVal.nInteger + 4);
        if ( *(int *)(v18.nInteger + 4) <= 0 )
          val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
      }
      v19 = funcz[++i].name == nullptr;
      v25 = &funcz[i];
      if ( v19 )
        return v24;
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051920
// Name: public: void SQSharedState::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQSharedState::Init(SQSharedState *this@<ecx>, int a2@<edi>)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ebx
  void *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  SQTable *v8; // eax
  _DWORD *v9; // ebx
  int i; // esi
  int v11; // eax
  int v12; // eax
  _DWORD *v13; // ecx
  SQString *v14; // ebx
  int v15; // esi
  SQString *v16; // ebx
  int v17; // esi
  sqvector<SQObjectPtr> *v18; // ecx
  SQString *v19; // ebx
  int v20; // esi
  SQString *v21; // ebx
  int v22; // esi
  sqvector<SQObjectPtr> *v23; // ecx
  SQString *v24; // ebx
  int v25; // esi
  SQString *v26; // ebx
  int v27; // esi
  sqvector<SQObjectPtr> *v28; // ecx
  SQString *v29; // ebx
  int v30; // esi
  SQString *v31; // ebx
  int v32; // esi
  sqvector<SQObjectPtr> *v33; // ecx
  SQString *v34; // ebx
  int v35; // esi
  SQString *v36; // ebx
  int v37; // esi
  sqvector<SQObjectPtr> *v38; // ecx
  SQString *v39; // ebx
  int v40; // esi
  SQString *v41; // ebx
  int v42; // esi
  sqvector<SQObjectPtr> *v43; // ecx
  SQString *v44; // ebx
  int v45; // esi
  SQString *v46; // ebx
  int v47; // esi
  sqvector<SQObjectPtr> *v48; // ecx
  SQString *v49; // ebx
  int v50; // esi
  SQString *v51; // ebx
  int v52; // esi
  sqvector<SQObjectPtr> *v53; // ecx
  _DWORD *v54; // eax
  _DWORD *v55; // eax
  SQString *v56; // ebx
  int v57; // esi
  sqvector<SQObjectPtr> *v58; // ecx
  _DWORD *v59; // eax
  _DWORD *v60; // eax
  SQString *v61; // ebx
  int v62; // esi
  sqvector<SQObjectPtr> *v63; // ecx
  _DWORD *v64; // eax
  _DWORD *v65; // eax
  SQString *v66; // ebx
  int v67; // esi
  sqvector<SQObjectPtr> *v68; // ecx
  _DWORD *v69; // eax
  _DWORD *v70; // eax
  SQString *v71; // ebx
  int v72; // esi
  sqvector<SQObjectPtr> *v73; // ecx
  _DWORD *v74; // eax
  _DWORD *v75; // eax
  SQString *v76; // ebx
  int v77; // esi
  sqvector<SQObjectPtr> *v78; // ecx
  _DWORD *v79; // eax
  _DWORD *v80; // eax
  SQString *v81; // ebx
  int v82; // esi
  sqvector<SQObjectPtr> *v83; // ecx
  _DWORD *v84; // eax
  _DWORD *v85; // eax
  SQString *v86; // ebx
  int v87; // esi
  sqvector<SQObjectPtr> *v88; // ecx
  _DWORD *v89; // eax
  _DWORD *v90; // eax
  SQString *v91; // ebx
  int v92; // esi
  sqvector<SQObjectPtr> *v93; // ecx
  _DWORD *v94; // eax
  _DWORD *v95; // eax
  SQString *v96; // ebx
  int v97; // esi
  sqvector<SQObjectPtr> *v98; // ecx
  _DWORD *v99; // eax
  _DWORD *v100; // eax
  SQString *v101; // ebx
  int v102; // esi
  sqvector<SQObjectPtr> *v103; // ecx
  _DWORD *v104; // eax
  _DWORD *v105; // eax
  SQString *v106; // ebx
  int v107; // esi
  sqvector<SQObjectPtr> *v108; // ecx
  _DWORD *v109; // eax
  _DWORD *v110; // eax
  SQString *v111; // ebx
  int v112; // esi
  sqvector<SQObjectPtr> *v113; // ecx
  _DWORD *v114; // eax
  _DWORD *v115; // eax
  SQString *v116; // ebx
  int v117; // esi
  sqvector<SQObjectPtr> *v118; // ecx
  _DWORD *v119; // eax
  _DWORD *v120; // eax
  SQString *v121; // ebx
  int v122; // esi
  sqvector<SQObjectPtr> *v123; // ecx
  _DWORD *v124; // eax
  _DWORD *v125; // eax
  SQString *v126; // ebx
  int v127; // esi
  sqvector<SQObjectPtr> *v128; // ecx
  _DWORD *v129; // eax
  _DWORD *v130; // eax
  SQString *v131; // ebx
  int v132; // esi
  sqvector<SQObjectPtr> *v133; // ecx
  _DWORD *v134; // eax
  _DWORD *v135; // eax
  SQString *v136; // ebx
  int v137; // esi
  sqvector<SQObjectPtr> *v138; // ecx
  _DWORD *v139; // eax
  _DWORD *v140; // eax
  SQString *v141; // esi
  int v142; // eax
  _DWORD *v143; // ecx
  SQTable *v144; // ebx
  int v145; // eax
  int v146; // eax
  _DWORD *v147; // ecx
  SQTable *v148; // ebx
  int v149; // eax
  int v150; // eax
  _DWORD *v151; // ecx
  SQTable *DefaultDelegate; // ebx
  int v153; // eax
  _DWORD *v154; // ecx
  SQTable *v155; // ebx
  int v156; // eax
  _DWORD *v157; // ecx
  SQTable *v158; // ebx
  int v159; // eax
  _DWORD *v160; // ecx
  SQTable *v161; // ebx
  int v162; // eax
  _DWORD *v163; // ecx
  SQTable *v164; // ebx
  int v165; // eax
  _DWORD *v166; // ecx
  SQTable *v167; // ebx
  int v168; // eax
  _DWORD *v169; // ecx
  SQTable *v170; // ebx
  int v171; // eax
  _DWORD *v172; // ecx
  SQTable *v173; // ebx
  int v174; // eax
  _DWORD *v175; // ecx
  SQTable *v176; // ebx
  int v177; // eax
  _DWORD *v178; // ecx
  SQTable *v179; // ebx
  int v180; // eax
  _DWORD *v181; // ecx
  unsigned int v182; // [esp-4h] [ebp-14h]
  int val; // [esp+8h] [ebp-8h] BYREF
  _DWORD *val_4; // [esp+Ch] [ebp-4h]

  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  v2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
  v3 = v2;
  *(_DWORD *)(a2 + 20) = v2;
  if ( v2 != nullptr )
  {
    v2[1] = 4;
    v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16);
    v182 = 4 * v3[1];
    *v3 = v4;
    memset(dst: (int)v4, value: nullptr, count: v182);
    v3[2] = 0;
  }
  v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
  *(_DWORD *)a2 = v5;
  if ( v5 != nullptr )
  {
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
  }
  v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
  *(_DWORD *)(a2 + 12) = v6;
  if ( v6 != nullptr )
  {
    *v6 = 0;
    v6[1] = 0;
    v6[2] = 0;
  }
  v7 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12);
  *(_DWORD *)(a2 + 16) = v7;
  if ( v7 != nullptr )
  {
    *v7 = 0;
    v7[1] = 0;
    v7[2] = 0;
  }
  v8 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  v9 = &v8->__vftable;
  if ( v8 != nullptr )
  {
    v8->_uiRef = 0;
    v8->_weakref = nullptr;
    v8->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    for ( i = 4; i < 17; i *= 2 )
      ;
    SQTable::AllocNodes(this: v8, nSize: i);
    v9[3] = 0;
    v9[10] = 0;
    v9[6] = 0;
    v9[5] = a2;
    v9[4] = 0;
    v9[3] = *(_DWORD *)(a2 + 68);
    v11 = *(_DWORD *)(a2 + 68);
    if ( v11 != 0 )
      *(_DWORD *)(v11 + 16) = v9;
    *(_DWORD *)(a2 + 68) = v9;
  }
  v9[6] = 0;
  ++v9[1];
  v12 = *(_DWORD *)(a2 + 4);
  v13 = *(_DWORD **)(a2 + 8);
  *(_DWORD *)(a2 + 8) = v9;
  *(_DWORD *)(a2 + 4) = 167772192;
  ++v9[1];
  if ( (v12 & 0x8000000) != 0 && (int)--v13[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
  if ( (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  v14 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "null", len: -1);
  v14->_sharedstate = (SQSharedState *)a2;
  ++v14->_uiRef;
  v15 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v14->__vftable;
  sqvector<SQObjectPtr>::push_back(this: (sqvector<SQObjectPtr> *)&val, a2: v15, (const SQObjectPtr *)&val);
  if ( --v14->_uiRef <= 0 )
    v14->Release(this: v14);
  v16 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "table", len: -1);
  v16->_sharedstate = (SQSharedState *)a2;
  ++v16->_uiRef;
  v17 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v16->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v18, a2: v17, (const SQObjectPtr *)&val);
  if ( --v16->_uiRef <= 0 )
    v16->Release(this: v16);
  v19 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "array", len: -1);
  v19->_sharedstate = (SQSharedState *)a2;
  ++v19->_uiRef;
  v20 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v19->__vftable;
  sqvector<SQObjectPtr>::push_back(this: (sqvector<SQObjectPtr> *)&val, a2: v20, (const SQObjectPtr *)&val);
  if ( --v19->_uiRef <= 0 )
    v19->Release(this: v19);
  v21 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "closure", len: -1);
  v21->_sharedstate = (SQSharedState *)a2;
  ++v21->_uiRef;
  v22 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v21->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v23, a2: v22, (const SQObjectPtr *)&val);
  if ( --v21->_uiRef <= 0 )
    v21->Release(this: v21);
  v24 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "string", len: -1);
  v24->_sharedstate = (SQSharedState *)a2;
  ++v24->_uiRef;
  v25 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v24->__vftable;
  sqvector<SQObjectPtr>::push_back(this: (sqvector<SQObjectPtr> *)&val, a2: v25, (const SQObjectPtr *)&val);
  if ( --v24->_uiRef <= 0 )
    v24->Release(this: v24);
  v26 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "userdata", len: -1);
  v26->_sharedstate = (SQSharedState *)a2;
  ++v26->_uiRef;
  v27 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v26->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v28, a2: v27, (const SQObjectPtr *)&val);
  if ( --v26->_uiRef <= 0 )
    v26->Release(this: v26);
  v29 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "integer", len: -1);
  v29->_sharedstate = (SQSharedState *)a2;
  ++v29->_uiRef;
  v30 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v29->__vftable;
  sqvector<SQObjectPtr>::push_back(this: (sqvector<SQObjectPtr> *)&val, a2: v30, (const SQObjectPtr *)&val);
  if ( --v29->_uiRef <= 0 )
    v29->Release(this: v29);
  v31 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "float", len: -1);
  v31->_sharedstate = (SQSharedState *)a2;
  ++v31->_uiRef;
  v32 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v31->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v33, a2: v32, (const SQObjectPtr *)&val);
  if ( --v31->_uiRef <= 0 )
    v31->Release(this: v31);
  v34 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "userpointer", len: -1);
  v34->_sharedstate = (SQSharedState *)a2;
  ++v34->_uiRef;
  v35 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v34->__vftable;
  sqvector<SQObjectPtr>::push_back(this: (sqvector<SQObjectPtr> *)&val, a2: v35, (const SQObjectPtr *)&val);
  if ( --v34->_uiRef <= 0 )
    v34->Release(this: v34);
  v36 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "function", len: -1);
  v36->_sharedstate = (SQSharedState *)a2;
  ++v36->_uiRef;
  v37 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v36->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v38, a2: v37, (const SQObjectPtr *)&val);
  if ( --v36->_uiRef <= 0 )
    v36->Release(this: v36);
  v39 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "generator", len: -1);
  v39->_sharedstate = (SQSharedState *)a2;
  ++v39->_uiRef;
  v40 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v39->__vftable;
  sqvector<SQObjectPtr>::push_back(this: (sqvector<SQObjectPtr> *)&val, a2: v40, (const SQObjectPtr *)&val);
  if ( --v39->_uiRef <= 0 )
    v39->Release(this: v39);
  v41 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "thread", len: -1);
  v41->_sharedstate = (SQSharedState *)a2;
  ++v41->_uiRef;
  v42 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v41->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v43, a2: v42, (const SQObjectPtr *)&val);
  if ( --v41->_uiRef <= 0 )
    v41->Release(this: v41);
  v44 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "class", len: -1);
  v44->_sharedstate = (SQSharedState *)a2;
  ++v44->_uiRef;
  v45 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v44->__vftable;
  sqvector<SQObjectPtr>::push_back(this: (sqvector<SQObjectPtr> *)&val, a2: v45, (const SQObjectPtr *)&val);
  if ( --v44->_uiRef <= 0 )
    v44->Release(this: v44);
  v46 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "instance", len: -1);
  v46->_sharedstate = (SQSharedState *)a2;
  ++v46->_uiRef;
  v47 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v46->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v48, a2: v47, (const SQObjectPtr *)&val);
  if ( --v46->_uiRef <= 0 )
    v46->Release(this: v46);
  v49 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "bool", len: -1);
  v49->_sharedstate = (SQSharedState *)a2;
  ++v49->_uiRef;
  v50 = *(_DWORD *)(a2 + 12);
  val = 134217744;
  val_4 = &v49->__vftable;
  sqvector<SQObjectPtr>::push_back(this: (sqvector<SQObjectPtr> *)&val, a2: v50, (const SQObjectPtr *)&val);
  if ( --v49->_uiRef <= 0 )
    v49->Release(this: v49);
  v51 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_add", len: -1);
  v51->_sharedstate = (SQSharedState *)a2;
  ++v51->_uiRef;
  v52 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v51->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v53, a2: v52, (const SQObjectPtr *)&val);
  if ( --v51->_uiRef <= 0 )
    v51->Release(this: v51);
  v54 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v54 + 8 * v54[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v55 = val_4;
    --val_4[1];
    if ( (int)v55[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v56 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_sub", len: -1);
  v56->_sharedstate = (SQSharedState *)a2;
  ++v56->_uiRef;
  v57 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v56->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v58, a2: v57, (const SQObjectPtr *)&val);
  if ( --v56->_uiRef <= 0 )
    v56->Release(this: v56);
  v59 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v59 + 8 * v59[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v60 = val_4;
    --val_4[1];
    if ( (int)v60[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v61 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_mul", len: -1);
  v61->_sharedstate = (SQSharedState *)a2;
  ++v61->_uiRef;
  v62 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v61->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v63, a2: v62, (const SQObjectPtr *)&val);
  if ( --v61->_uiRef <= 0 )
    v61->Release(this: v61);
  v64 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v64 + 8 * v64[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v65 = val_4;
    --val_4[1];
    if ( (int)v65[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v66 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_div", len: -1);
  v66->_sharedstate = (SQSharedState *)a2;
  ++v66->_uiRef;
  v67 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v66->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v68, a2: v67, (const SQObjectPtr *)&val);
  if ( --v66->_uiRef <= 0 )
    v66->Release(this: v66);
  v69 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v69 + 8 * v69[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v70 = val_4;
    --val_4[1];
    if ( (int)v70[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v71 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_unm", len: -1);
  v71->_sharedstate = (SQSharedState *)a2;
  ++v71->_uiRef;
  v72 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v71->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v73, a2: v72, (const SQObjectPtr *)&val);
  if ( --v71->_uiRef <= 0 )
    v71->Release(this: v71);
  v74 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v74 + 8 * v74[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v75 = val_4;
    --val_4[1];
    if ( (int)v75[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v76 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_modulo", len: -1);
  v76->_sharedstate = (SQSharedState *)a2;
  ++v76->_uiRef;
  v77 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v76->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v78, a2: v77, (const SQObjectPtr *)&val);
  if ( --v76->_uiRef <= 0 )
    v76->Release(this: v76);
  v79 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v79 + 8 * v79[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v80 = val_4;
    --val_4[1];
    if ( (int)v80[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v81 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_set", len: -1);
  v81->_sharedstate = (SQSharedState *)a2;
  ++v81->_uiRef;
  v82 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v81->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v83, a2: v82, (const SQObjectPtr *)&val);
  if ( --v81->_uiRef <= 0 )
    v81->Release(this: v81);
  v84 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v84 + 8 * v84[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v85 = val_4;
    --val_4[1];
    if ( (int)v85[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v86 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_get", len: -1);
  v86->_sharedstate = (SQSharedState *)a2;
  ++v86->_uiRef;
  v87 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v86->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v88, a2: v87, (const SQObjectPtr *)&val);
  if ( --v86->_uiRef <= 0 )
    v86->Release(this: v86);
  v89 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v89 + 8 * v89[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v90 = val_4;
    --val_4[1];
    if ( (int)v90[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v91 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_typeof", len: -1);
  v91->_sharedstate = (SQSharedState *)a2;
  ++v91->_uiRef;
  v92 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v91->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v93, a2: v92, (const SQObjectPtr *)&val);
  if ( --v91->_uiRef <= 0 )
    v91->Release(this: v91);
  v94 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v94 + 8 * v94[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v95 = val_4;
    --val_4[1];
    if ( (int)v95[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v96 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_nexti", len: -1);
  v96->_sharedstate = (SQSharedState *)a2;
  ++v96->_uiRef;
  v97 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v96->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v98, a2: v97, (const SQObjectPtr *)&val);
  if ( --v96->_uiRef <= 0 )
    v96->Release(this: v96);
  v99 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v99 + 8 * v99[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v100 = val_4;
    --val_4[1];
    if ( (int)v100[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v101 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_cmp", len: -1);
  v101->_sharedstate = (SQSharedState *)a2;
  ++v101->_uiRef;
  v102 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v101->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v103, a2: v102, (const SQObjectPtr *)&val);
  if ( --v101->_uiRef <= 0 )
    v101->Release(this: v101);
  v104 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v104 + 8 * v104[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v105 = val_4;
    --val_4[1];
    if ( (int)v105[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v106 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_call", len: -1);
  v106->_sharedstate = (SQSharedState *)a2;
  ++v106->_uiRef;
  v107 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v106->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v108, a2: v107, (const SQObjectPtr *)&val);
  if ( --v106->_uiRef <= 0 )
    v106->Release(this: v106);
  v109 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v109 + 8 * v109[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v110 = val_4;
    --val_4[1];
    if ( (int)v110[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v111 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_cloned", len: -1);
  v111->_sharedstate = (SQSharedState *)a2;
  ++v111->_uiRef;
  v112 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v111->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v113, a2: v112, (const SQObjectPtr *)&val);
  if ( --v111->_uiRef <= 0 )
    v111->Release(this: v111);
  v114 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v114 + 8 * v114[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v115 = val_4;
    --val_4[1];
    if ( (int)v115[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v116 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_newslot", len: -1);
  v116->_sharedstate = (SQSharedState *)a2;
  ++v116->_uiRef;
  v117 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v116->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v118, a2: v117, (const SQObjectPtr *)&val);
  if ( --v116->_uiRef <= 0 )
    v116->Release(this: v116);
  v119 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v119 + 8 * v119[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v120 = val_4;
    --val_4[1];
    if ( (int)v120[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v121 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_delslot", len: -1);
  v121->_sharedstate = (SQSharedState *)a2;
  ++v121->_uiRef;
  v122 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v121->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v123, a2: v122, (const SQObjectPtr *)&val);
  if ( --v121->_uiRef <= 0 )
    v121->Release(this: v121);
  v124 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v124 + 8 * v124[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v125 = val_4;
    --val_4[1];
    if ( (int)v125[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v126 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_tostring", len: -1);
  v126->_sharedstate = (SQSharedState *)a2;
  ++v126->_uiRef;
  v127 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v126->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v128, a2: v127, (const SQObjectPtr *)&val);
  if ( --v126->_uiRef <= 0 )
    v126->Release(this: v126);
  v129 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v129 + 8 * v129[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v130 = val_4;
    --val_4[1];
    if ( (int)v130[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v131 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_newmember", len: -1);
  v131->_sharedstate = (SQSharedState *)a2;
  ++v131->_uiRef;
  v132 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v131->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v133, a2: v132, (const SQObjectPtr *)&val);
  if ( --v131->_uiRef <= 0 )
    v131->Release(this: v131);
  v134 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v134 + 8 * v134[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v135 = val_4;
    --val_4[1];
    if ( (int)v135[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v136 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "_inherited", len: -1);
  v136->_sharedstate = (SQSharedState *)a2;
  ++v136->_uiRef;
  v137 = *(_DWORD *)a2;
  val = 134217744;
  val_4 = &v136->__vftable;
  sqvector<SQObjectPtr>::push_back(this: v138, a2: v137, (const SQObjectPtr *)&val);
  if ( --v136->_uiRef <= 0 )
    v136->Release(this: v136);
  v139 = *(_DWORD **)a2;
  val_4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) - 1);
  val = 83886082;
  SQTable::NewSlot(
    this: *(SQTable **)(a2 + 8),
    key: (const SQObjectPtr *)(*v139 + 8 * v139[1] - 8),
    (const SQObjectPtr *)&val);
  if ( (val & 0x8000000) != 0 )
  {
    v140 = val_4;
    --val_4[1];
    if ( (int)v140[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*val_4 + 8))(a1: val_4);
  }
  v141 = StringTable::Add(this: *(StringTable **)(a2 + 20), news: "constructor", len: -1);
  v141->_sharedstate = (SQSharedState *)a2;
  ++v141->_uiRef;
  v142 = *(_DWORD *)(a2 + 60);
  v143 = *(_DWORD **)(a2 + 64);
  *(_DWORD *)(a2 + 64) = v141;
  *(_DWORD *)(a2 + 60) = 134217744;
  ++v141->_uiRef;
  if ( (v142 & 0x8000000) != 0 && (int)--v143[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v143 + 8))(a1: v143);
  if ( --v141->_uiRef <= 0 )
    v141->Release(this: v141);
  v144 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  if ( v144 != nullptr )
  {
    v144->_uiRef = 0;
    v144->_weakref = nullptr;
    v144->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    SQTable::AllocNodes(this: v144, nSize: 4);
    v144->_next = nullptr;
    v144->_usednodes = 0;
    v144->_delegate = nullptr;
    v144->_sharedstate = (SQSharedState *)a2;
    v144->_prev = nullptr;
    v144->_next = *(SQCollectable **)(a2 + 68);
    v145 = *(_DWORD *)(a2 + 68);
    if ( v145 != 0 )
      *(_DWORD *)(v145 + 16) = v144;
    *(_DWORD *)(a2 + 68) = v144;
  }
  v144->_delegate = nullptr;
  ++v144->_uiRef;
  v146 = *(_DWORD *)(a2 + 44);
  v147 = *(_DWORD **)(a2 + 48);
  *(_DWORD *)(a2 + 48) = v144;
  *(_DWORD *)(a2 + 44) = 167772192;
  ++v144->_uiRef;
  if ( (v146 & 0x8000000) != 0 && (int)--v147[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v147 + 8))(a1: v147);
  if ( --v144->_uiRef <= 0 )
    v144->Release(this: v144);
  v148 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  if ( v148 != nullptr )
  {
    v148->_uiRef = 0;
    v148->_weakref = nullptr;
    v148->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    SQTable::AllocNodes(this: v148, nSize: 4);
    v148->_next = nullptr;
    v148->_usednodes = 0;
    v148->_delegate = nullptr;
    v148->_sharedstate = (SQSharedState *)a2;
    v148->_prev = nullptr;
    v148->_next = *(SQCollectable **)(a2 + 68);
    v149 = *(_DWORD *)(a2 + 68);
    if ( v149 != 0 )
      *(_DWORD *)(v149 + 16) = v148;
    *(_DWORD *)(a2 + 68) = v148;
  }
  v148->_delegate = nullptr;
  ++v148->_uiRef;
  v150 = *(_DWORD *)(a2 + 52);
  v151 = *(_DWORD **)(a2 + 56);
  *(_DWORD *)(a2 + 56) = v148;
  *(_DWORD *)(a2 + 52) = 167772192;
  ++v148->_uiRef;
  if ( (v150 & 0x8000000) != 0 && (int)--v151[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v151 + 8))(a1: v151);
  if ( --v148->_uiRef <= 0 )
    v148->Release(this: v148);
  DefaultDelegate = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_table_default_delegate_funcz);
  ++DefaultDelegate->_uiRef;
  v153 = *(_DWORD *)(a2 + 80);
  v154 = *(_DWORD **)(a2 + 84);
  *(_DWORD *)(a2 + 84) = DefaultDelegate;
  *(_DWORD *)(a2 + 80) = 167772192;
  ++DefaultDelegate->_uiRef;
  if ( (v153 & 0x8000000) != 0 && (int)--v154[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v154 + 8))(a1: v154);
  if ( --DefaultDelegate->_uiRef <= 0 )
    DefaultDelegate->Release(this: DefaultDelegate);
  v155 = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_array_default_delegate_funcz);
  ++v155->_uiRef;
  v156 = *(_DWORD *)(a2 + 88);
  v157 = *(_DWORD **)(a2 + 92);
  *(_DWORD *)(a2 + 92) = v155;
  *(_DWORD *)(a2 + 88) = 167772192;
  ++v155->_uiRef;
  if ( (v156 & 0x8000000) != 0 && (int)--v157[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v157 + 8))(a1: v157);
  if ( --v155->_uiRef <= 0 )
    v155->Release(this: v155);
  v158 = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_string_default_delegate_funcz);
  ++v158->_uiRef;
  v159 = *(_DWORD *)(a2 + 96);
  v160 = *(_DWORD **)(a2 + 100);
  *(_DWORD *)(a2 + 100) = v158;
  *(_DWORD *)(a2 + 96) = 167772192;
  ++v158->_uiRef;
  if ( (v159 & 0x8000000) != 0 && (int)--v160[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v160 + 8))(a1: v160);
  if ( --v158->_uiRef <= 0 )
    v158->Release(this: v158);
  v161 = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_number_default_delegate_funcz);
  ++v161->_uiRef;
  v162 = *(_DWORD *)(a2 + 104);
  v163 = *(_DWORD **)(a2 + 108);
  *(_DWORD *)(a2 + 108) = v161;
  *(_DWORD *)(a2 + 104) = 167772192;
  ++v161->_uiRef;
  if ( (v162 & 0x8000000) != 0 && (int)--v163[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v163 + 8))(a1: v163);
  if ( --v161->_uiRef <= 0 )
    v161->Release(this: v161);
  v164 = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_closure_default_delegate_funcz);
  ++v164->_uiRef;
  v165 = *(_DWORD *)(a2 + 120);
  v166 = *(_DWORD **)(a2 + 124);
  *(_DWORD *)(a2 + 124) = v164;
  *(_DWORD *)(a2 + 120) = 167772192;
  ++v164->_uiRef;
  if ( (v165 & 0x8000000) != 0 && (int)--v166[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v166 + 8))(a1: v166);
  if ( --v164->_uiRef <= 0 )
    v164->Release(this: v164);
  v167 = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_generator_default_delegate_funcz);
  ++v167->_uiRef;
  v168 = *(_DWORD *)(a2 + 112);
  v169 = *(_DWORD **)(a2 + 116);
  *(_DWORD *)(a2 + 116) = v167;
  *(_DWORD *)(a2 + 112) = 167772192;
  ++v167->_uiRef;
  if ( (v168 & 0x8000000) != 0 && (int)--v169[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v169 + 8))(a1: v169);
  if ( --v167->_uiRef <= 0 )
    v167->Release(this: v167);
  v170 = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_thread_default_delegate_funcz);
  ++v170->_uiRef;
  v171 = *(_DWORD *)(a2 + 128);
  v172 = *(_DWORD **)(a2 + 132);
  *(_DWORD *)(a2 + 132) = v170;
  *(_DWORD *)(a2 + 128) = 167772192;
  ++v170->_uiRef;
  if ( (v171 & 0x8000000) != 0 && (int)--v172[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v172 + 8))(a1: v172);
  if ( --v170->_uiRef <= 0 )
    v170->Release(this: v170);
  v173 = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_class_default_delegate_funcz);
  ++v173->_uiRef;
  v174 = *(_DWORD *)(a2 + 136);
  v175 = *(_DWORD **)(a2 + 140);
  *(_DWORD *)(a2 + 140) = v173;
  *(_DWORD *)(a2 + 136) = 167772192;
  ++v173->_uiRef;
  if ( (v174 & 0x8000000) != 0 && (int)--v175[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v175 + 8))(a1: v175);
  if ( --v173->_uiRef <= 0 )
    v173->Release(this: v173);
  v176 = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_instance_default_delegate_funcz);
  ++v176->_uiRef;
  v177 = *(_DWORD *)(a2 + 144);
  v178 = *(_DWORD **)(a2 + 148);
  *(_DWORD *)(a2 + 148) = v176;
  *(_DWORD *)(a2 + 144) = 167772192;
  ++v176->_uiRef;
  if ( (v177 & 0x8000000) != 0 && (int)--v178[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v178 + 8))(a1: v178);
  if ( --v176->_uiRef <= 0 )
    v176->Release(this: v176);
  v179 = CreateDefaultDelegate(ss: (SQSharedState *)a2, funcz: SQSharedState::_weakref_default_delegate_funcz);
  ++v179->_uiRef;
  v180 = *(_DWORD *)(a2 + 152);
  v181 = *(_DWORD **)(a2 + 156);
  *(_DWORD *)(a2 + 156) = v179;
  *(_DWORD *)(a2 + 152) = 167772192;
  ++v179->_uiRef;
  if ( (v180 & 0x8000000) != 0 && (int)--v181[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v181 + 8))(a1: v181);
  if ( --v179->_uiRef <= 0 )
    v179->Release(this: v179);
}

//------------------------------------------------------------------------------
// Address: 0x10052C90
// Name: public: SQSharedState::~SQSharedState(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQSharedState::~SQSharedState(SQSharedState *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  _DWORD *v3; // ecx
  int v4; // edx
  tagSQObjectType type; // eax
  _DWORD *v6; // ecx
  int v7; // edx
  tagSQObjectType v8; // eax
  _DWORD *v9; // ecx
  int v10; // edx
  tagSQObjectType v11; // eax
  _DWORD *v12; // ecx
  int v13; // edx
  tagSQObjectType v14; // eax
  _DWORD *i; // eax
  tagSQObjectType *v16; // eax
  _DWORD *v17; // ecx
  tagSQObjectType v18; // edx
  tagSQObjectType v19; // ebx
  int *v20; // eax
  int v21; // ecx
  int v22; // eax
  bool v23; // zf
  int v24; // ecx
  int v25; // eax
  _DWORD *v26; // ecx
  int v27; // edx
  tagSQObjectType v28; // eax
  _DWORD *v29; // ecx
  int v30; // edx
  tagSQObjectType v31; // eax
  _DWORD *v32; // ecx
  int v33; // edx
  tagSQObjectType v34; // eax
  _DWORD *v35; // ecx
  int v36; // edx
  tagSQObjectType v37; // eax
  _DWORD *v38; // ecx
  int v39; // edx
  tagSQObjectType v40; // eax
  _DWORD *v41; // ecx
  int v42; // edx
  tagSQObjectType v43; // eax
  _DWORD *v44; // ecx
  int v45; // edx
  tagSQObjectType v46; // eax
  _DWORD *v47; // ecx
  int v48; // edx
  tagSQObjectType v49; // eax
  _DWORD *v50; // ecx
  int v51; // edx
  tagSQObjectType v52; // eax
  _DWORD *v53; // ecx
  int v54; // edx
  tagSQObjectType v55; // eax
  _DWORD *v56; // ecx
  int v57; // edx
  tagSQObjectType v58; // eax
  sqvector<SQObjectPtr> *v59; // ecx
  int *v60; // edi
  void (__thiscall *v61)(int *); // eax
  int *v62; // ebx
  sqvector<SQObjectPtr> *v63; // ecx
  sqvector<SQObjectPtr> *v64; // ecx
  void **v65; // edi
  int v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  int v71; // eax
  int v72; // eax
  int v73; // eax
  int v74; // eax
  int v75; // eax
  int v76; // eax
  int v77; // eax
  int v78; // eax
  int v79; // eax
  int v80; // eax
  int v81; // [esp-4h] [ebp-8h]

  v3 = *(_DWORD **)(a3 + 64);
  v4 = *(_DWORD *)(a3 + 60);
  *(_DWORD *)(a3 + 64) = _null_._unVal.pTable;
  type = _null_._type;
  *(_DWORD *)(a3 + 60) = _null_._type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 64) + 4);
  v81 = a2;
  if ( (v4 & 0x8000000) != 0 && (int)--v3[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *, int))(*v3 + 8))(a1: v3, a2);
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a3 + 48) + 16))(a1: *(_DWORD *)(a3 + 48), a2: v81);
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 56) + 16))(a1: *(_DWORD *)(a3 + 56));
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 8) + 16))(a1: *(_DWORD *)(a3 + 8));
  v6 = *(_DWORD **)(a3 + 48);
  v7 = *(_DWORD *)(a3 + 44);
  *(_DWORD *)(a3 + 48) = _null_._unVal.pTable;
  v8 = _null_._type;
  *(_DWORD *)(a3 + 44) = _null_._type;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 48) + 4);
  if ( (v7 & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  v9 = *(_DWORD **)(a3 + 56);
  v10 = *(_DWORD *)(a3 + 52);
  *(_DWORD *)(a3 + 56) = _null_._unVal.pTable;
  v11 = _null_._type;
  *(_DWORD *)(a3 + 52) = _null_._type;
  if ( (v11 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 56) + 4);
  if ( (v10 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  v12 = *(_DWORD **)(a3 + 8);
  v13 = *(_DWORD *)(a3 + 4);
  *(_DWORD *)(a3 + 8) = _null_._unVal.pTable;
  v14 = _null_._type;
  *(_DWORD *)(a3 + 4) = _null_._type;
  if ( (v14 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 8) + 4);
  if ( (v13 & 0x8000000) != 0 && (int)--v12[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  for ( i = *(_DWORD **)(a3 + 12); i[1] != 0; i = *(_DWORD **)(a3 + 12) )
  {
    v16 = (tagSQObjectType *)(*i + 8 * i[1] - 8);
    v17 = *((_DWORD **)v16 + 1);
    v18 = *v16;
    v16[1] = (tagSQObjectType)_null_._unVal.pTable;
    v19 = _null_._type;
    *v16 = _null_._type;
    if ( (v19 & 0x8000000) != 0 )
      ++*(_DWORD *)(*((_DWORD *)v16 + 1) + 4);
    if ( (v18 & 0x8000000) != 0 && (int)--v17[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v17 + 8))(a1: v17);
    v20 = *(int **)(a3 + 12);
    v21 = --v20[1];
    v22 = *v20;
    v23 = (*(_DWORD *)(v22 + 8 * v21) & 0x8000000) == 0;
    v24 = v22 + 8 * v21;
    if ( !v23 )
    {
      v25 = *(_DWORD *)(v24 + 4);
      if ( (int)--*(_DWORD *)(v25 + 4) <= 0 )
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v24 + 4) + 8))(a1: *(_DWORD *)(v24 + 4));
    }
  }
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 76) + 16))(a1: *(_DWORD *)(a3 + 76));
  v26 = *(_DWORD **)(a3 + 76);
  v27 = *(_DWORD *)(a3 + 72);
  *(_DWORD *)(a3 + 76) = _null_._unVal.pTable;
  v28 = _null_._type;
  *(_DWORD *)(a3 + 72) = _null_._type;
  if ( (v28 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 76) + 4);
  if ( (v27 & 0x8000000) != 0 && (int)--v26[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v26 + 8))(a1: v26);
  v29 = *(_DWORD **)(a3 + 84);
  v30 = *(_DWORD *)(a3 + 80);
  *(_DWORD *)(a3 + 84) = _null_._unVal.pTable;
  v31 = _null_._type;
  *(_DWORD *)(a3 + 80) = _null_._type;
  if ( (v31 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 84) + 4);
  if ( (v30 & 0x8000000) != 0 && (int)--v29[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v29 + 8))(a1: v29);
  v32 = *(_DWORD **)(a3 + 92);
  v33 = *(_DWORD *)(a3 + 88);
  *(_DWORD *)(a3 + 92) = _null_._unVal.pTable;
  v34 = _null_._type;
  *(_DWORD *)(a3 + 88) = _null_._type;
  if ( (v34 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 92) + 4);
  if ( (v33 & 0x8000000) != 0 && (int)--v32[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v32 + 8))(a1: v32);
  v35 = *(_DWORD **)(a3 + 100);
  v36 = *(_DWORD *)(a3 + 96);
  *(_DWORD *)(a3 + 100) = _null_._unVal.pTable;
  v37 = _null_._type;
  *(_DWORD *)(a3 + 96) = _null_._type;
  if ( (v37 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 100) + 4);
  if ( (v36 & 0x8000000) != 0 && (int)--v35[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v35 + 8))(a1: v35);
  v38 = *(_DWORD **)(a3 + 108);
  v39 = *(_DWORD *)(a3 + 104);
  *(_DWORD *)(a3 + 108) = _null_._unVal.pTable;
  v40 = _null_._type;
  *(_DWORD *)(a3 + 104) = _null_._type;
  if ( (v40 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 108) + 4);
  if ( (v39 & 0x8000000) != 0 && (int)--v38[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v38 + 8))(a1: v38);
  v41 = *(_DWORD **)(a3 + 124);
  v42 = *(_DWORD *)(a3 + 120);
  *(_DWORD *)(a3 + 124) = _null_._unVal.pTable;
  v43 = _null_._type;
  *(_DWORD *)(a3 + 120) = _null_._type;
  if ( (v43 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 124) + 4);
  if ( (v42 & 0x8000000) != 0 && (int)--v41[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v41 + 8))(a1: v41);
  v44 = *(_DWORD **)(a3 + 116);
  v45 = *(_DWORD *)(a3 + 112);
  *(_DWORD *)(a3 + 116) = _null_._unVal.pTable;
  v46 = _null_._type;
  *(_DWORD *)(a3 + 112) = _null_._type;
  if ( (v46 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 116) + 4);
  if ( (v45 & 0x8000000) != 0 && (int)--v44[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v44 + 8))(a1: v44);
  v47 = *(_DWORD **)(a3 + 132);
  v48 = *(_DWORD *)(a3 + 128);
  *(_DWORD *)(a3 + 132) = _null_._unVal.pTable;
  v49 = _null_._type;
  *(_DWORD *)(a3 + 128) = _null_._type;
  if ( (v49 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 132) + 4);
  if ( (v48 & 0x8000000) != 0 && (int)--v47[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v47 + 8))(a1: v47);
  v50 = *(_DWORD **)(a3 + 140);
  v51 = *(_DWORD *)(a3 + 136);
  *(_DWORD *)(a3 + 140) = _null_._unVal.pTable;
  v52 = _null_._type;
  *(_DWORD *)(a3 + 136) = _null_._type;
  if ( (v52 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 140) + 4);
  if ( (v51 & 0x8000000) != 0 && (int)--v50[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v50 + 8))(a1: v50);
  v53 = *(_DWORD **)(a3 + 148);
  v54 = *(_DWORD *)(a3 + 144);
  *(_DWORD *)(a3 + 148) = _null_._unVal.pTable;
  v55 = _null_._type;
  *(_DWORD *)(a3 + 144) = _null_._type;
  if ( (v55 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 148) + 4);
  if ( (v54 & 0x8000000) != 0 && (int)--v53[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v53 + 8))(a1: v53);
  v56 = *(_DWORD **)(a3 + 156);
  v57 = *(_DWORD *)(a3 + 152);
  *(_DWORD *)(a3 + 156) = _null_._unVal.pTable;
  v58 = _null_._type;
  *(_DWORD *)(a3 + 152) = _null_._type;
  if ( (v58 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a3 + 156) + 4);
  if ( (v57 & 0x8000000) != 0 && (int)--v56[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v56 + 8))(a1: v56);
  RefTable::Finalize(this: (RefTable *)(a3 + 24));
  v60 = *(int **)(a3 + 68);
  if ( v60 != nullptr )
  {
    do
    {
      v61 = *(void (__thiscall **)(int *))(*v60 + 16);
      ++v60[1];
      v61(a1: v60);
      --v60[1];
      v62 = (int *)v60[3];
      if ( v60[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v60 + 8))(a1: v60);
      v60 = v62;
    }
    while ( v62 != nullptr );
  }
  while ( *(_DWORD *)(a3 + 68) != 0 )
  {
    ++*(_DWORD *)(*(_DWORD *)(a3 + 68) + 4);
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 68) + 8))(a1: *(_DWORD *)(a3 + 68));
  }
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v59, a2: *(_DWORD *)(a3 + 16));
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a3 + 16));
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v63, a2: *(_DWORD *)(a3 + 12));
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a3 + 12));
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v64, a2: *(_DWORD *)a3);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)a3);
  v65 = *(void ***)(a3 + 20);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *v65);
  *v65 = nullptr;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a3 + 20));
  if ( *(_DWORD *)(a3 + 180) != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a3 + 180));
  if ( (*(_DWORD *)(a3 + 152) & 0x8000000) != 0 )
  {
    v66 = *(_DWORD *)(a3 + 156);
    if ( (int)--*(_DWORD *)(v66 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 156) + 8))(a1: *(_DWORD *)(a3 + 156));
  }
  if ( (*(_DWORD *)(a3 + 144) & 0x8000000) != 0 )
  {
    v67 = *(_DWORD *)(a3 + 148);
    if ( (int)--*(_DWORD *)(v67 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 148) + 8))(a1: *(_DWORD *)(a3 + 148));
  }
  if ( (*(_DWORD *)(a3 + 136) & 0x8000000) != 0 )
  {
    v68 = *(_DWORD *)(a3 + 140);
    if ( (int)--*(_DWORD *)(v68 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 140) + 8))(a1: *(_DWORD *)(a3 + 140));
  }
  if ( (*(_DWORD *)(a3 + 128) & 0x8000000) != 0 )
  {
    v69 = *(_DWORD *)(a3 + 132);
    if ( (int)--*(_DWORD *)(v69 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 132) + 8))(a1: *(_DWORD *)(a3 + 132));
  }
  if ( (*(_DWORD *)(a3 + 120) & 0x8000000) != 0 )
  {
    v70 = *(_DWORD *)(a3 + 124);
    if ( (int)--*(_DWORD *)(v70 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 124) + 8))(a1: *(_DWORD *)(a3 + 124));
  }
  if ( (*(_DWORD *)(a3 + 112) & 0x8000000) != 0 )
  {
    v71 = *(_DWORD *)(a3 + 116);
    if ( (int)--*(_DWORD *)(v71 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 116) + 8))(a1: *(_DWORD *)(a3 + 116));
  }
  if ( (*(_DWORD *)(a3 + 104) & 0x8000000) != 0 )
  {
    v72 = *(_DWORD *)(a3 + 108);
    if ( (int)--*(_DWORD *)(v72 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 108) + 8))(a1: *(_DWORD *)(a3 + 108));
  }
  if ( (*(_DWORD *)(a3 + 96) & 0x8000000) != 0 )
  {
    v73 = *(_DWORD *)(a3 + 100);
    if ( (int)--*(_DWORD *)(v73 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 100) + 8))(a1: *(_DWORD *)(a3 + 100));
  }
  if ( (*(_DWORD *)(a3 + 88) & 0x8000000) != 0 )
  {
    v74 = *(_DWORD *)(a3 + 92);
    if ( (int)--*(_DWORD *)(v74 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 92) + 8))(a1: *(_DWORD *)(a3 + 92));
  }
  if ( (*(_DWORD *)(a3 + 80) & 0x8000000) != 0 )
  {
    v75 = *(_DWORD *)(a3 + 84);
    if ( (int)--*(_DWORD *)(v75 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 84) + 8))(a1: *(_DWORD *)(a3 + 84));
  }
  if ( (*(_DWORD *)(a3 + 72) & 0x8000000) != 0 )
  {
    v76 = *(_DWORD *)(a3 + 76);
    if ( (int)--*(_DWORD *)(v76 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 76) + 8))(a1: *(_DWORD *)(a3 + 76));
  }
  if ( (*(_DWORD *)(a3 + 60) & 0x8000000) != 0 )
  {
    v77 = *(_DWORD *)(a3 + 64);
    if ( (int)--*(_DWORD *)(v77 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 64) + 8))(a1: *(_DWORD *)(a3 + 64));
  }
  if ( (*(_DWORD *)(a3 + 52) & 0x8000000) != 0 )
  {
    v78 = *(_DWORD *)(a3 + 56);
    if ( (int)--*(_DWORD *)(v78 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 56) + 8))(a1: *(_DWORD *)(a3 + 56));
  }
  if ( (*(_DWORD *)(a3 + 44) & 0x8000000) != 0 )
  {
    v79 = *(_DWORD *)(a3 + 48);
    if ( (int)--*(_DWORD *)(v79 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 48) + 8))(a1: *(_DWORD *)(a3 + 48));
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a3 + 40));
  if ( (*(_DWORD *)(a3 + 4) & 0x8000000) != 0 )
  {
    v80 = *(_DWORD *)(a3 + 8);
    if ( (int)--*(_DWORD *)(v80 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 8) + 8))(a1: *(_DWORD *)(a3 + 8));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053350
// Name: public: int SQSharedState::GetMetaMethodIdxByName(struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
int __usercall SQSharedState::GetMetaMethodIdxByName@<eax>(SQSharedState *this@<ecx>, const SQObjectPtr *name@<eax>)
{
  int *v2; // esi
  int *v4; // ecx
  SQTable *pTable; // [esp-4h] [ebp-14h]
  SQObjectPtr ret; // [esp+8h] [ebp-8h] BYREF

  if ( name->_type != OT_STRING )
    return -1;
  pTable = this->_metamethodsmap._unVal.pTable;
  ret._type = OT_NULL;
  ret._unVal.nInteger = 0;
  if ( !SQTable::Get(this: pTable, key: name, val: &ret) )
  {
    if ( (ret._type & 0x8000000) != 0 )
    {
      v4 = (int *)ret._unVal.pTable;
      --*(_DWORD *)(ret._unVal.nInteger + 4);
      if ( v4[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v4 + 8))(a1: v4);
    }
    return -1;
  }
  v2 = (int *)ret._unVal.pTable;
  if ( (ret._type & 0x8000000) != 0 )
  {
    --*(_DWORD *)(ret._unVal.nInteger + 4);
    if ( v2[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v2 + 8))(a1: v2);
  }
  return (int)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100533D0
// Name: public: void SQSharedState::Iterate(struct SQVM __near *,class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQSharedState::Iterate(
        SQSharedState *this@<eax>,
        CSQStateIterator *pIterator@<edi>,
        SQSharedState *a3@<ecx>,
        int a4@<ebx>)
{
  tagSQObjectType type; // eax
  tagSQObjectType v6; // eax
  tagSQObjectType v7; // eax
  tagSQObjectType v8; // eax
  tagSQObjectType v9; // eax
  tagSQObjectType v10; // eax
  tagSQObjectType v11; // eax
  tagSQObjectType v12; // eax
  tagSQObjectType v13; // eax
  tagSQObjectType v14; // eax
  tagSQObjectType v15; // eax
  tagSQObjectType v16; // eax
  tagSQObjectType v17; // eax
  SQCollectable *i; // esi
  SQVM *v19; // [esp+0h] [ebp-4h]

  if ( this->_gc_disableDepth <= 0 )
    SQSharedState::CollectGarbage(this: a3, tchain: v19);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->_root_vm._unVal.pTable->Iterate)(
    a1: (tagSQObjectValue)this->_root_vm._unVal.nInteger,
    a2: pIterator,
    a3: a4);
  pIterator->PsuedoKey(this: pIterator, a2: "_registry");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->_registry);
  type = this->_registry._type;
  if ( type > OT_THREAD )
  {
    if ( type > OT_USERDATA )
    {
      if ( type != OT_INSTANCE )
        goto LABEL_21;
    }
    else if ( type != OT_USERDATA && type != OT_CLASS && type != OT_TABLE )
    {
      goto LABEL_21;
    }
  }
  else if ( this->_registry._type != OT_THREAD )
  {
    if ( type > OT_NATIVECLOSURE )
    {
      if ( type != OT_GENERATOR )
        goto LABEL_21;
    }
    else if ( type != OT_NATIVECLOSURE && type != OT_ARRAY && type != OT_CLOSURE )
    {
      goto LABEL_21;
    }
  }
  if ( (*(_DWORD *)(this->_registry._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_registry._unVal.nInteger + 4) |= 0x40000000u;
    this->_registry._unVal.pTable->Iterate(this: (struct SQTable *)this->_registry._unVal.nInteger, a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_21:
  pIterator->PsuedoKey(this: pIterator, a2: "_consts");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->_consts);
  v6 = this->_consts._type;
  if ( v6 > OT_THREAD )
  {
    if ( v6 > OT_USERDATA )
    {
      if ( v6 != OT_INSTANCE )
        goto LABEL_39;
    }
    else if ( v6 != OT_USERDATA && v6 != OT_CLASS && v6 != OT_TABLE )
    {
      goto LABEL_39;
    }
  }
  else if ( this->_consts._type != OT_THREAD )
  {
    if ( v6 > OT_NATIVECLOSURE )
    {
      if ( v6 != OT_GENERATOR )
        goto LABEL_39;
    }
    else if ( v6 != OT_NATIVECLOSURE && v6 != OT_ARRAY && v6 != OT_CLOSURE )
    {
      goto LABEL_39;
    }
  }
  if ( (*(_DWORD *)(this->_consts._unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_consts._unVal.nInteger + 4) |= 0x40000000u;
    this->_consts._unVal.pTable->Iterate(this: (struct SQTable *)this->_consts._unVal.nInteger, a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_39:
  pIterator->PsuedoKey(this: pIterator, a2: "_metamethodsmap");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->_metamethodsmap);
  v7 = this->_metamethodsmap._type;
  if ( v7 > OT_THREAD )
  {
    if ( v7 > OT_USERDATA )
    {
      if ( v7 != OT_INSTANCE )
        goto LABEL_57;
    }
    else if ( v7 != OT_USERDATA && v7 != OT_CLASS && v7 != OT_TABLE )
    {
      goto LABEL_57;
    }
  }
  else if ( this->_metamethodsmap._type != OT_THREAD )
  {
    if ( v7 > OT_NATIVECLOSURE )
    {
      if ( v7 != OT_GENERATOR )
        goto LABEL_57;
    }
    else if ( v7 != OT_NATIVECLOSURE && v7 != OT_ARRAY && v7 != OT_CLOSURE )
    {
      goto LABEL_57;
    }
  }
  if ( (*(_DWORD *)(this->_metamethodsmap._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_metamethodsmap._unVal.nInteger + 4) |= 0x40000000u;
    this->_metamethodsmap._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_metamethodsmap._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_57:
  pIterator->PsuedoKey(this: pIterator, a2: "_table_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_table_default_delegate);
  v8 = this->_table_default_delegate._type;
  if ( v8 > OT_THREAD )
  {
    if ( v8 > OT_USERDATA )
    {
      if ( v8 != OT_INSTANCE )
        goto LABEL_75;
    }
    else if ( v8 != OT_USERDATA && v8 != OT_CLASS && v8 != OT_TABLE )
    {
      goto LABEL_75;
    }
  }
  else if ( this->_table_default_delegate._type != OT_THREAD )
  {
    if ( v8 > OT_NATIVECLOSURE )
    {
      if ( v8 != OT_GENERATOR )
        goto LABEL_75;
    }
    else if ( v8 != OT_NATIVECLOSURE && v8 != OT_ARRAY && v8 != OT_CLOSURE )
    {
      goto LABEL_75;
    }
  }
  if ( (*(_DWORD *)(this->_table_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_table_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_table_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_table_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_75:
  pIterator->PsuedoKey(this: pIterator, a2: "_array_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_array_default_delegate);
  v9 = this->_array_default_delegate._type;
  if ( v9 > OT_THREAD )
  {
    if ( v9 > OT_USERDATA )
    {
      if ( v9 != OT_INSTANCE )
        goto LABEL_93;
    }
    else if ( v9 != OT_USERDATA && v9 != OT_CLASS && v9 != OT_TABLE )
    {
      goto LABEL_93;
    }
  }
  else if ( this->_array_default_delegate._type != OT_THREAD )
  {
    if ( v9 > OT_NATIVECLOSURE )
    {
      if ( v9 != OT_GENERATOR )
        goto LABEL_93;
    }
    else if ( v9 != OT_NATIVECLOSURE && v9 != OT_ARRAY && v9 != OT_CLOSURE )
    {
      goto LABEL_93;
    }
  }
  if ( (*(_DWORD *)(this->_array_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_array_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_array_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_array_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_93:
  pIterator->PsuedoKey(this: pIterator, a2: "_string_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_string_default_delegate);
  v10 = this->_string_default_delegate._type;
  if ( v10 > OT_THREAD )
  {
    if ( v10 > OT_USERDATA )
    {
      if ( v10 != OT_INSTANCE )
        goto LABEL_111;
    }
    else if ( v10 != OT_USERDATA && v10 != OT_CLASS && v10 != OT_TABLE )
    {
      goto LABEL_111;
    }
  }
  else if ( this->_string_default_delegate._type != OT_THREAD )
  {
    if ( v10 > OT_NATIVECLOSURE )
    {
      if ( v10 != OT_GENERATOR )
        goto LABEL_111;
    }
    else if ( v10 != OT_NATIVECLOSURE && v10 != OT_ARRAY && v10 != OT_CLOSURE )
    {
      goto LABEL_111;
    }
  }
  if ( (*(_DWORD *)(this->_string_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_string_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_string_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_string_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_111:
  pIterator->PsuedoKey(this: pIterator, a2: "_number_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_number_default_delegate);
  v11 = this->_number_default_delegate._type;
  if ( v11 > OT_THREAD )
  {
    if ( v11 > OT_USERDATA )
    {
      if ( v11 != OT_INSTANCE )
        goto LABEL_129;
    }
    else if ( v11 != OT_USERDATA && v11 != OT_CLASS && v11 != OT_TABLE )
    {
      goto LABEL_129;
    }
  }
  else if ( this->_number_default_delegate._type != OT_THREAD )
  {
    if ( v11 > OT_NATIVECLOSURE )
    {
      if ( v11 != OT_GENERATOR )
        goto LABEL_129;
    }
    else if ( v11 != OT_NATIVECLOSURE && v11 != OT_ARRAY && v11 != OT_CLOSURE )
    {
      goto LABEL_129;
    }
  }
  if ( (*(_DWORD *)(this->_number_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_number_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_number_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_number_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_129:
  pIterator->PsuedoKey(this: pIterator, a2: "_generator_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_generator_default_delegate);
  v12 = this->_generator_default_delegate._type;
  if ( v12 > OT_THREAD )
  {
    if ( v12 > OT_USERDATA )
    {
      if ( v12 != OT_INSTANCE )
        goto LABEL_147;
    }
    else if ( v12 != OT_USERDATA && v12 != OT_CLASS && v12 != OT_TABLE )
    {
      goto LABEL_147;
    }
  }
  else if ( this->_generator_default_delegate._type != OT_THREAD )
  {
    if ( v12 > OT_NATIVECLOSURE )
    {
      if ( v12 != OT_GENERATOR )
        goto LABEL_147;
    }
    else if ( v12 != OT_NATIVECLOSURE && v12 != OT_ARRAY && v12 != OT_CLOSURE )
    {
      goto LABEL_147;
    }
  }
  if ( (*(_DWORD *)(this->_generator_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_generator_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_generator_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_generator_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_147:
  pIterator->PsuedoKey(this: pIterator, a2: "_thread_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_thread_default_delegate);
  v13 = this->_thread_default_delegate._type;
  if ( v13 > OT_THREAD )
  {
    if ( v13 > OT_USERDATA )
    {
      if ( v13 != OT_INSTANCE )
        goto LABEL_165;
    }
    else if ( v13 != OT_USERDATA && v13 != OT_CLASS && v13 != OT_TABLE )
    {
      goto LABEL_165;
    }
  }
  else if ( this->_thread_default_delegate._type != OT_THREAD )
  {
    if ( v13 > OT_NATIVECLOSURE )
    {
      if ( v13 != OT_GENERATOR )
        goto LABEL_165;
    }
    else if ( v13 != OT_NATIVECLOSURE && v13 != OT_ARRAY && v13 != OT_CLOSURE )
    {
      goto LABEL_165;
    }
  }
  if ( (*(_DWORD *)(this->_thread_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_thread_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_thread_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_thread_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_165:
  pIterator->PsuedoKey(this: pIterator, a2: "_closure_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_closure_default_delegate);
  v14 = this->_closure_default_delegate._type;
  if ( v14 > OT_THREAD )
  {
    if ( v14 > OT_USERDATA )
    {
      if ( v14 != OT_INSTANCE )
        goto LABEL_183;
    }
    else if ( v14 != OT_USERDATA && v14 != OT_CLASS && v14 != OT_TABLE )
    {
      goto LABEL_183;
    }
  }
  else if ( this->_closure_default_delegate._type != OT_THREAD )
  {
    if ( v14 > OT_NATIVECLOSURE )
    {
      if ( v14 != OT_GENERATOR )
        goto LABEL_183;
    }
    else if ( v14 != OT_NATIVECLOSURE && v14 != OT_ARRAY && v14 != OT_CLOSURE )
    {
      goto LABEL_183;
    }
  }
  if ( (*(_DWORD *)(this->_closure_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_closure_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_closure_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_closure_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_183:
  pIterator->PsuedoKey(this: pIterator, a2: "_class_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_class_default_delegate);
  v15 = this->_class_default_delegate._type;
  if ( v15 > OT_THREAD )
  {
    if ( v15 > OT_USERDATA )
    {
      if ( v15 != OT_INSTANCE )
        goto LABEL_201;
    }
    else if ( v15 != OT_USERDATA && v15 != OT_CLASS && v15 != OT_TABLE )
    {
      goto LABEL_201;
    }
  }
  else if ( this->_class_default_delegate._type != OT_THREAD )
  {
    if ( v15 > OT_NATIVECLOSURE )
    {
      if ( v15 != OT_GENERATOR )
        goto LABEL_201;
    }
    else if ( v15 != OT_NATIVECLOSURE && v15 != OT_ARRAY && v15 != OT_CLOSURE )
    {
      goto LABEL_201;
    }
  }
  if ( (*(_DWORD *)(this->_class_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_class_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_class_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_class_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_201:
  pIterator->PsuedoKey(this: pIterator, a2: "_instance_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_instance_default_delegate);
  v16 = this->_instance_default_delegate._type;
  if ( v16 > OT_THREAD )
  {
    if ( v16 > OT_USERDATA )
    {
      if ( v16 != OT_INSTANCE )
        goto LABEL_219;
    }
    else if ( v16 != OT_USERDATA && v16 != OT_CLASS && v16 != OT_TABLE )
    {
      goto LABEL_219;
    }
  }
  else if ( this->_instance_default_delegate._type != OT_THREAD )
  {
    if ( v16 > OT_NATIVECLOSURE )
    {
      if ( v16 != OT_GENERATOR )
        goto LABEL_219;
    }
    else if ( v16 != OT_NATIVECLOSURE && v16 != OT_ARRAY && v16 != OT_CLOSURE )
    {
      goto LABEL_219;
    }
  }
  if ( (*(_DWORD *)(this->_instance_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_instance_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_instance_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_instance_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_219:
  pIterator->PsuedoKey(this: pIterator, a2: "_weakref_default_delegate");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(
    a1: pIterator,
    a2: &this->_weakref_default_delegate);
  v17 = this->_weakref_default_delegate._type;
  if ( v17 > OT_THREAD )
  {
    if ( v17 > OT_USERDATA )
    {
      if ( v17 != OT_INSTANCE )
        goto LABEL_237;
    }
    else if ( v17 != OT_USERDATA && v17 != OT_CLASS && v17 != OT_TABLE )
    {
      goto LABEL_237;
    }
  }
  else if ( this->_weakref_default_delegate._type != OT_THREAD )
  {
    if ( v17 > OT_NATIVECLOSURE )
    {
      if ( v17 != OT_GENERATOR )
        goto LABEL_237;
    }
    else if ( v17 != OT_NATIVECLOSURE && v17 != OT_ARRAY && v17 != OT_CLOSURE )
    {
      goto LABEL_237;
    }
  }
  if ( (*(_DWORD *)(this->_weakref_default_delegate._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_weakref_default_delegate._unVal.nInteger + 4) |= 0x40000000u;
    this->_weakref_default_delegate._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_weakref_default_delegate._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_237:
  *(_DWORD *)(this->_registry._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_consts._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_metamethodsmap._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_table_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_array_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_string_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_number_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_generator_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_thread_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_closure_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_class_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_instance_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  *(_DWORD *)(this->_weakref_default_delegate._unVal.nInteger + 4) &= ~0x40000000u;
  for ( i = this->_gc_chain; i != nullptr; i = i->_next )
    i->_uiRef &= ~0x40000000u;
}

//------------------------------------------------------------------------------
// Address: 0x10053C80
// Name: public: static void SQSharedState::MarkObject(struct SQObjectPtr __near &,struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __fastcall SQSharedState::MarkObject(SQObjectPtr *o, SQCollectable **chain)
{
  tagSQObjectType type; // eax
  bool v3; // zf

  type = o->_type;
  if ( o->_type > OT_THREAD )
  {
    if ( type > OT_USERDATA )
    {
      v3 = type == OT_INSTANCE;
    }
    else
    {
      if ( type == OT_USERDATA || type == OT_CLASS )
        goto LABEL_14;
      v3 = type == OT_TABLE;
    }
LABEL_13:
    if ( !v3 )
      return;
    goto LABEL_14;
  }
  if ( o->_type != OT_THREAD )
  {
    if ( type > OT_NATIVECLOSURE )
    {
      v3 = type == OT_GENERATOR;
      goto LABEL_13;
    }
    if ( type != OT_NATIVECLOSURE && type != OT_ARRAY )
    {
      v3 = type == OT_CLOSURE;
      goto LABEL_13;
    }
  }
LABEL_14:
  o->_unVal.pTable->Mark(this: (struct SQTable *)o->_unVal.nInteger, a2: chain);
}

//------------------------------------------------------------------------------
// Address: 0x10053CE0
// Name: public: int SQSharedState::CollectGarbage(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall SQSharedState::CollectGarbage@<eax>(SQSharedState *this@<ecx>, int a2@<esi>)
{
  int v2; // ecx
  int v3; // eax
  bool v4; // zf
  int v5; // eax
  bool v6; // zf
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  bool v10; // zf
  int v11; // eax
  bool v12; // zf
  int v13; // eax
  bool v14; // zf
  int v15; // eax
  bool v16; // zf
  int v17; // eax
  bool v18; // zf
  int v19; // eax
  bool v20; // zf
  bool v21; // zf
  int v22; // eax
  bool v23; // zf
  int v24; // eax
  bool v25; // zf
  bool v26; // zf
  int v27; // eax
  bool v28; // zf
  bool v29; // zf
  int v30; // eax
  bool v31; // zf
  bool v32; // zf
  int *v33; // edi
  void (__thiscall *v34)(int *); // edx
  int *v35; // ebx
  SQCollectable *v36; // eax
  int n; // [esp+8h] [ebp-8h]
  SQCollectable *tchaina; // [esp+Ch] [ebp-4h] BYREF

  v2 = *(_DWORD *)(a2 + 76);
  tchaina = nullptr;
  n = 0;
  (*(void (__thiscall **)(int, SQCollectable **))(*(_DWORD *)v2 + 12))(a1: v2, a2: &tchaina);
  RefTable::Mark(this: (RefTable *)(a2 + 24), chain: &tchaina);
  v3 = *(_DWORD *)(a2 + 44);
  if ( v3 <= 134221824 )
  {
    if ( v3 != 134221824 )
    {
      if ( v3 > 134218240 )
      {
        if ( v3 != 134218752 )
          goto LABEL_17;
      }
      else if ( v3 != 134218240 && v3 != 134217792 )
      {
        v4 = v3 == 134217984;
        goto LABEL_15;
      }
    }
    goto LABEL_16;
  }
  if ( v3 > 167772288 )
  {
    v4 = v3 == 167804928;
LABEL_15:
    if ( !v4 )
      goto LABEL_17;
    goto LABEL_16;
  }
  if ( v3 == 167772288 || v3 == 134234112 || v3 == 167772192 )
LABEL_16:
    (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 48) + 12))(
      a1: *(_DWORD *)(a2 + 48),
      a2: &tchaina);
LABEL_17:
  v5 = *(_DWORD *)(a2 + 52);
  if ( v5 <= 134221824 )
  {
    if ( v5 != 134221824 )
    {
      if ( v5 > 134218240 )
      {
        if ( v5 != 134218752 )
          goto LABEL_33;
      }
      else if ( v5 != 134218240 && v5 != 134217792 )
      {
        v6 = v5 == 134217984;
        goto LABEL_31;
      }
    }
    goto LABEL_32;
  }
  if ( v5 > 167772288 )
  {
    v6 = v5 == 167804928;
LABEL_31:
    if ( !v6 )
      goto LABEL_33;
    goto LABEL_32;
  }
  if ( v5 == 167772288 || v5 == 134234112 || v5 == 167772192 )
LABEL_32:
    (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 56) + 12))(
      a1: *(_DWORD *)(a2 + 56),
      a2: &tchaina);
LABEL_33:
  v7 = *(_DWORD *)(a2 + 4);
  if ( v7 <= 134221824 )
  {
    if ( v7 != 134221824 )
    {
      if ( v7 > 134218240 )
      {
        if ( v7 != 134218752 )
          goto LABEL_49;
      }
      else if ( v7 != 134218240 && v7 != 134217792 )
      {
        v8 = v7 == 134217984;
        goto LABEL_47;
      }
    }
    goto LABEL_48;
  }
  if ( v7 > 167772288 )
  {
    v8 = v7 == 167804928;
LABEL_47:
    if ( !v8 )
      goto LABEL_49;
    goto LABEL_48;
  }
  if ( v7 == 167772288 || v7 == 134234112 || v7 == 167772192 )
LABEL_48:
    (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 8) + 12))(
      a1: *(_DWORD *)(a2 + 8),
      a2: &tchaina);
LABEL_49:
  v9 = *(_DWORD *)(a2 + 80);
  if ( v9 <= 134221824 )
  {
    if ( v9 != 134221824 )
    {
      if ( v9 > 134218240 )
      {
        if ( v9 != 134218752 )
          goto LABEL_65;
      }
      else if ( v9 != 134218240 && v9 != 134217792 )
      {
        v10 = v9 == 134217984;
        goto LABEL_63;
      }
    }
    goto LABEL_64;
  }
  if ( v9 > 167772288 )
  {
    v10 = v9 == 167804928;
LABEL_63:
    if ( !v10 )
      goto LABEL_65;
    goto LABEL_64;
  }
  if ( v9 == 167772288 || v9 == 134234112 || v9 == 167772192 )
LABEL_64:
    (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 84) + 12))(
      a1: *(_DWORD *)(a2 + 84),
      a2: &tchaina);
LABEL_65:
  v11 = *(_DWORD *)(a2 + 88);
  if ( v11 <= 134221824 )
  {
    if ( v11 != 134221824 )
    {
      if ( v11 > 134218240 )
      {
        if ( v11 != 134218752 )
          goto LABEL_81;
      }
      else if ( v11 != 134218240 && v11 != 134217792 )
      {
        v12 = v11 == 134217984;
        goto LABEL_79;
      }
    }
    goto LABEL_80;
  }
  if ( v11 > 167772288 )
  {
    v12 = v11 == 167804928;
LABEL_79:
    if ( !v12 )
      goto LABEL_81;
    goto LABEL_80;
  }
  if ( v11 == 167772288 || v11 == 134234112 || v11 == 167772192 )
LABEL_80:
    (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 92) + 12))(
      a1: *(_DWORD *)(a2 + 92),
      a2: &tchaina);
LABEL_81:
  v13 = *(_DWORD *)(a2 + 96);
  if ( v13 <= 134221824 )
  {
    if ( v13 != 134221824 )
    {
      if ( v13 > 134218240 )
      {
        if ( v13 != 134218752 )
          goto LABEL_97;
      }
      else if ( v13 != 134218240 && v13 != 134217792 )
      {
        v14 = v13 == 134217984;
        goto LABEL_95;
      }
    }
    goto LABEL_96;
  }
  if ( v13 > 167772288 )
  {
    v14 = v13 == 167804928;
LABEL_95:
    if ( !v14 )
      goto LABEL_97;
    goto LABEL_96;
  }
  if ( v13 == 167772288 || v13 == 134234112 || v13 == 167772192 )
LABEL_96:
    (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 100) + 12))(
      a1: *(_DWORD *)(a2 + 100),
      a2: &tchaina);
LABEL_97:
  v15 = *(_DWORD *)(a2 + 104);
  if ( v15 <= 134221824 )
  {
    if ( v15 != 134221824 )
    {
      if ( v15 > 134218240 )
      {
        if ( v15 != 134218752 )
          goto LABEL_113;
      }
      else if ( v15 != 134218240 && v15 != 134217792 )
      {
        v16 = v15 == 134217984;
        goto LABEL_111;
      }
    }
    goto LABEL_112;
  }
  if ( v15 > 167772288 )
  {
    v16 = v15 == 167804928;
LABEL_111:
    if ( !v16 )
      goto LABEL_113;
    goto LABEL_112;
  }
  if ( v15 == 167772288 || v15 == 134234112 || v15 == 167772192 )
LABEL_112:
    (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 108) + 12))(
      a1: *(_DWORD *)(a2 + 108),
      a2: &tchaina);
LABEL_113:
  v17 = *(_DWORD *)(a2 + 112);
  if ( v17 <= 134221824 )
  {
    if ( v17 != 134221824 )
    {
      if ( v17 > 134218240 )
      {
        if ( v17 != 134218752 )
          goto LABEL_129;
      }
      else if ( v17 != 134218240 && v17 != 134217792 )
      {
        v18 = v17 == 134217984;
        goto LABEL_127;
      }
    }
    goto LABEL_128;
  }
  if ( v17 > 167772288 )
  {
    v18 = v17 == 167804928;
LABEL_127:
    if ( !v18 )
      goto LABEL_129;
    goto LABEL_128;
  }
  if ( v17 == 167772288 || v17 == 134234112 || v17 == 167772192 )
LABEL_128:
    (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 116) + 12))(
      a1: *(_DWORD *)(a2 + 116),
      a2: &tchaina);
LABEL_129:
  v19 = *(_DWORD *)(a2 + 128);
  if ( v19 <= 134221824 )
  {
    if ( v19 == 134221824 )
      goto LABEL_144;
    if ( v19 <= 134218240 )
    {
      if ( v19 != 134218240 && v19 != 134217792 )
      {
        v20 = v19 == 134217984;
        goto LABEL_143;
      }
      goto LABEL_144;
    }
    v21 = v19 == 134218752;
LABEL_140:
    if ( !v21 )
      goto LABEL_145;
    goto LABEL_144;
  }
  if ( v19 > 167772288 )
  {
    v20 = v19 == 167804928;
LABEL_143:
    if ( !v20 )
      goto LABEL_145;
    goto LABEL_144;
  }
  if ( v19 != 167772288 && v19 != 134234112 )
  {
    v21 = v19 == 167772192;
    goto LABEL_140;
  }
LABEL_144:
  (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 132) + 12))(
    a1: *(_DWORD *)(a2 + 132),
    a2: &tchaina);
LABEL_145:
  v22 = *(_DWORD *)(a2 + 120);
  if ( v22 <= 134221824 )
  {
    if ( v22 != 134221824 )
    {
      if ( v22 > 134218240 )
      {
        if ( v22 != 134218752 )
          goto LABEL_161;
      }
      else if ( v22 != 134218240 && v22 != 134217792 )
      {
        v23 = v22 == 134217984;
        goto LABEL_159;
      }
    }
    goto LABEL_160;
  }
  if ( v22 > 167772288 )
  {
    v23 = v22 == 167804928;
LABEL_159:
    if ( !v23 )
      goto LABEL_161;
    goto LABEL_160;
  }
  if ( v22 == 167772288 || v22 == 134234112 || v22 == 167772192 )
LABEL_160:
    (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 124) + 12))(
      a1: *(_DWORD *)(a2 + 124),
      a2: &tchaina);
LABEL_161:
  v24 = *(_DWORD *)(a2 + 136);
  if ( v24 <= 134221824 )
  {
    if ( v24 == 134221824 )
      goto LABEL_176;
    if ( v24 <= 134218240 )
    {
      if ( v24 != 134218240 && v24 != 134217792 )
      {
        v25 = v24 == 134217984;
        goto LABEL_175;
      }
      goto LABEL_176;
    }
    v26 = v24 == 134218752;
LABEL_172:
    if ( !v26 )
      goto LABEL_177;
    goto LABEL_176;
  }
  if ( v24 > 167772288 )
  {
    v25 = v24 == 167804928;
LABEL_175:
    if ( !v25 )
      goto LABEL_177;
    goto LABEL_176;
  }
  if ( v24 != 167772288 && v24 != 134234112 )
  {
    v26 = v24 == 167772192;
    goto LABEL_172;
  }
LABEL_176:
  (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 140) + 12))(
    a1: *(_DWORD *)(a2 + 140),
    a2: &tchaina);
LABEL_177:
  v27 = *(_DWORD *)(a2 + 144);
  if ( v27 <= 134221824 )
  {
    if ( v27 == 134221824 )
      goto LABEL_192;
    if ( v27 <= 134218240 )
    {
      if ( v27 != 134218240 && v27 != 134217792 )
      {
        v28 = v27 == 134217984;
        goto LABEL_191;
      }
      goto LABEL_192;
    }
    v29 = v27 == 134218752;
LABEL_188:
    if ( !v29 )
      goto LABEL_193;
    goto LABEL_192;
  }
  if ( v27 > 167772288 )
  {
    v28 = v27 == 167804928;
LABEL_191:
    if ( !v28 )
      goto LABEL_193;
    goto LABEL_192;
  }
  if ( v27 != 167772288 && v27 != 134234112 )
  {
    v29 = v27 == 167772192;
    goto LABEL_188;
  }
LABEL_192:
  (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 148) + 12))(
    a1: *(_DWORD *)(a2 + 148),
    a2: &tchaina);
LABEL_193:
  v30 = *(_DWORD *)(a2 + 152);
  if ( v30 <= 134221824 )
  {
    if ( v30 == 134221824 )
      goto LABEL_208;
    if ( v30 <= 134218240 )
    {
      if ( v30 != 134218240 && v30 != 134217792 )
      {
        v31 = v30 == 134217984;
        goto LABEL_207;
      }
      goto LABEL_208;
    }
    v32 = v30 == 134218752;
LABEL_204:
    if ( !v32 )
      goto LABEL_209;
    goto LABEL_208;
  }
  if ( v30 > 167772288 )
  {
    v31 = v30 == 167804928;
LABEL_207:
    if ( !v31 )
      goto LABEL_209;
    goto LABEL_208;
  }
  if ( v30 != 167772288 && v30 != 134234112 )
  {
    v32 = v30 == 167772192;
    goto LABEL_204;
  }
LABEL_208:
  (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(a2 + 156) + 12))(
    a1: *(_DWORD *)(a2 + 156),
    a2: &tchaina);
LABEL_209:
  v33 = *(int **)(a2 + 68);
  if ( v33 != nullptr )
  {
    do
    {
      v34 = *(void (__thiscall **)(int *))(*v33 + 16);
      ++v33[1];
      v34(a1: v33);
      --v33[1];
      v35 = (int *)v33[3];
      if ( v33[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v33 + 8))(a1: v33);
      ++n;
      v33 = v35;
    }
    while ( v35 != nullptr );
  }
  v36 = tchaina;
  if ( tchaina != nullptr )
  {
    do
    {
      v36->_uiRef &= ~0x40000000u;
      v36 = v36->_next;
    }
    while ( v36 != nullptr );
    v36 = tchaina;
  }
  *(_DWORD *)(a2 + 68) = v36;
  return n;
}

//------------------------------------------------------------------------------
// Address: 0x10054350
// Name: public: char __near * SQSharedState::GetScratchPad(int)
// Source: json
//------------------------------------------------------------------------------
char *__usercall SQSharedState::GetScratchPad@<eax>(SQSharedState *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  char *v3; // edi
  char *result; // eax
  int v5; // edi

  v2 = *(_DWORD *)(a2 + 184);
  if ( v2 >= (int)this )
  {
    if ( v2 < 32 * (int)this )
    {
      return *(char **)(a2 + 180);
    }
    else
    {
      v5 = v2 >> 1;
      result = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 180), a3: v2 >> 1);
      *(_DWORD *)(a2 + 184) = v5;
      *(_DWORD *)(a2 + 180) = result;
    }
  }
  else
  {
    v3 = (char *)this + ((int)this >> 1);
    result = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 180), a3: v3);
    *(_DWORD *)(a2 + 184) = v3;
    *(_DWORD *)(a2 + 180) = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100543C0
// Name: public: void RefTable::Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RefTable::Finalize(RefTable *this, RefTable *thisa)
{
  RefTable::RefNode *nodes; // esi
  unsigned int i; // edi
  _DWORD *v4; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v6; // eax

  nodes = thisa->_nodes;
  for ( i = 0; i < thisa->_numofslots; ++nodes )
  {
    v4 = &nodes->obj._unVal.pTable->__vftable;
    type = nodes->obj._type;
    nodes->obj._unVal.nInteger = _null_._unVal.nInteger;
    v6 = _null_._type;
    nodes->obj._type = _null_._type;
    if ( (v6 & 0x8000000) != 0 )
      ++*(_DWORD *)(nodes->obj._unVal.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054420
// Name: public: void RefTable::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RefTable::Mark(SQCollectable **chain@<edi>, RefTable *this)
{
  unsigned int v2; // ebx
  RefTable::RefNode *i; // esi
  int type; // eax
  bool v5; // zf

  v2 = 0;
  for ( i = this->_nodes; v2 < this->_numofslots; ++i )
  {
    type = i->obj._type;
    if ( i->obj._type != OT_NULL )
    {
      if ( type > 134221824 )
      {
        if ( type > 167772288 )
        {
          v5 = type == 167804928;
        }
        else
        {
          if ( type == 167772288 || type == 134234112 )
          {
LABEL_16:
            i->obj._unVal.pTable->Mark(this: i->obj._unVal.pTable, a2: chain);
            goto LABEL_17;
          }
          v5 = type == 167772192;
        }
      }
      else
      {
        if ( type == 134221824 )
          goto LABEL_16;
        if ( type > 134218240 )
        {
          v5 = type == 134218752;
        }
        else
        {
          if ( type == 134218240 || type == 134217792 )
            goto LABEL_16;
          v5 = type == 134217984;
        }
      }
      if ( v5 )
        goto LABEL_16;
    }
LABEL_17:
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100544A0
// Name: public: unsigned int RefTable::Release(struct tagSQObject __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge RefTable::Release@<eax>(RefTable *this@<ecx>, RefTable *a2@<eax>, tagSQObject *obj)
{
  RefTable::RefNode *v4; // eax
  _DWORD *v6; // edi
  int v7; // ebx
  RefTable::RefNode *next; // edx
  _DWORD *v9; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v11; // esi
  RefTable::RefNode *prev; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int mainpos; // [esp+10h] [ebp-8h] BYREF
  int v15; // [esp+14h] [ebp-4h]

  v4 = RefTable::Get(this: a2, obj, &mainpos, &prev, add: false);
  if ( v4 == nullptr )
    return 0;
  if ( v4->refs-- != 1 )
    return 0;
  v6 = &v4->obj._unVal.pTable->__vftable;
  v7 = v4->obj._type & 0x8000000;
  v15 = v7;
  if ( v7 != 0 )
    ++v6[1];
  next = v4->next;
  if ( prev != nullptr )
  {
    prev->next = next;
  }
  else
  {
    a2->_buckets[mainpos] = next;
    v7 = v15;
  }
  v4->next = a2->_freelist;
  --a2->_slotused;
  a2->_freelist = v4;
  v9 = &v4->obj._unVal.pTable->__vftable;
  type = v4->obj._type;
  v4->obj._unVal.nInteger = _null_._unVal.nInteger;
  v11 = _null_._type;
  v4->obj._type = _null_._type;
  if ( (v11 & 0x8000000) != 0 )
    ++*(_DWORD *)(v4->obj._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  if ( v7 != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10054580
// Name: private: void RefTable::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __fastcall RefTable::Resize(int a1, unsigned int size, RefTable *this)
{
  unsigned int numofslots; // esi
  tagSQObjectValue *p_unVal; // edi
  int nInteger; // eax
  int fFloat; // ecx
  RefTable::RefNode *freelist; // esi
  unsigned int v9; // eax
  _DWORD *v10; // ecx
  tagSQObjectType pTable; // edx
  _DWORD *v12; // ecx
  tagSQObjectValue v13; // eax
  tagSQObjectType type; // edx
  RefTable::RefNode **oldbucks; // [esp+Ch] [ebp-14h]
  RefTable::RefNode *v17; // [esp+14h] [ebp-Ch]
  unsigned int v18; // [esp+18h] [ebp-8h]
  unsigned int v19; // [esp+1Ch] [ebp-4h]
  RefTable::RefNode *t; // [esp+28h] [ebp+8h]
  tagSQObjectType ta; // [esp+28h] [ebp+8h]

  numofslots = this->_numofslots;
  oldbucks = this->_buckets;
  t = this->_nodes;
  RefTable::AllocNodes(this, size);
  if ( numofslots != 0 )
  {
    p_unVal = &t->obj._unVal;
    v19 = numofslots;
    while ( 1 )
    {
      nInteger = p_unVal[-1].nInteger;
      if ( nInteger != 16777217 )
        break;
LABEL_23:
      p_unVal += 4;
      if ( --v19 == 0 )
        goto LABEL_24;
    }
    if ( nInteger > 83886084 )
    {
      if ( nInteger == 134217744 )
      {
        fFloat = *(_DWORD *)(p_unVal->nInteger + 24);
        goto LABEL_13;
      }
    }
    else
    {
      if ( nInteger == 83886084 )
      {
        fFloat = (__int64)p_unVal->fFloat;
        goto LABEL_13;
      }
      if ( nInteger == 16777224 || nInteger == 83886082 )
      {
        fFloat = p_unVal->nInteger;
LABEL_13:
        freelist = this->_freelist;
        v9 = fFloat & (this->_numofslots - 1);
        v17 = this->_buckets[v9];
        ta = freelist->obj._type;
        v10 = &freelist->obj._unVal.pTable->__vftable;
        freelist->obj._unVal = (tagSQObjectValue)p_unVal->pTable;
        pTable = (tagSQObjectType)p_unVal[-1].pTable;
        v18 = v9;
        freelist->obj._type = pTable;
        if ( (pTable & 0x8000000) != 0 )
          ++*(_DWORD *)(freelist->obj._unVal.nInteger + 4);
        if ( (ta & 0x8000000) != 0 && (int)--v10[1] <= 0 )
        {
          (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
          v9 = v18;
        }
        this->_buckets[v9] = freelist;
        this->_freelist = this->_freelist->next;
        freelist->next = v17;
        ++this->_slotused;
        freelist->refs = p_unVal[1].raw;
        v12 = (_DWORD *)p_unVal->nInteger;
        v13.pTable = p_unVal[-1].pTable;
        p_unVal->pTable = (SQTable *)_null_._unVal;
        type = _null_._type;
        p_unVal[-1].pTable = (SQTable *)_null_._type;
        if ( (type & 0x8000000) != 0 )
          ++*(_DWORD *)(p_unVal->nInteger + 4);
        if ( (v13.nInteger & 0x8000000) != 0 && (int)--v12[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
        goto LABEL_23;
      }
    }
    fFloat = p_unVal->nInteger >> 3;
    goto LABEL_13;
  }
LABEL_24:
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: oldbucks);
}

//------------------------------------------------------------------------------
// Address: 0x100546F0
// Name: private: struct RefTable::RefNode __near * RefTable::Add(unsigned int,struct tagSQObject __near &)
// Source: json
//------------------------------------------------------------------------------
RefTable::RefNode *__userpurge RefTable::Add@<eax>(RefTable *this@<edi>, tagSQObject *obj@<eax>, unsigned int mainpos)
{
  RefTable::RefNode *freelist; // esi
  tagSQObjectValue v5; // edx
  _DWORD *v6; // ecx
  tagSQObjectType type; // eax
  RefTable::RefNode *t; // [esp+8h] [ebp-4h]
  unsigned int mainposa; // [esp+14h] [ebp+8h]

  freelist = this->_freelist;
  t = this->_buckets[mainpos];
  v5.pTable = (SQTable *)obj->_unVal;
  mainposa = freelist->obj._type;
  v6 = &freelist->obj._unVal.pTable->__vftable;
  freelist->obj._unVal = v5;
  type = obj->_type;
  freelist->obj._type = type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(v5.nInteger + 4);
  if ( (mainposa & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  this->_buckets[mainpos] = freelist;
  this->_freelist = this->_freelist->next;
  freelist->next = t;
  ++this->_slotused;
  return freelist;
}

//------------------------------------------------------------------------------
// Address: 0x10054760
// Name: private: struct RefTable::RefNode __near * RefTable::Get(struct tagSQObject __near &,unsigned int __near &,struct RefTable::RefNode __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
RefTable::RefNode *__userpurge RefTable::Get@<eax>(
        SQObjectPtr *obj@<eax>,
        RefTable *this,
        unsigned int *mainpos,
        RefTable::RefNode **prev,
        bool add)
{
  tagSQObjectType type; // eax
  int nInteger; // ecx
  int v8; // edx
  __int32 v9; // eax
  RefTable *v10; // esi
  RefTable::RefNode *result; // eax
  tagSQObjectValue v12; // edx
  _DWORD *v13; // esi
  __int32 v14; // ebx
  SQObjectPtr key; // [esp+10h] [ebp-10h] BYREF

  type = obj->_type;
  nInteger = obj->_unVal.nInteger;
  v8 = type & 0x8000000;
  key._unVal.nInteger = nInteger;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(nInteger + 4);
  if ( type > OT_FLOAT )
  {
    if ( type == OT_STRING )
    {
      v9 = *(_DWORD *)(nInteger + 24);
      goto LABEL_12;
    }
    goto LABEL_10;
  }
  if ( type == OT_FLOAT )
  {
    key = (SQObjectPtr)(__int64)key._unVal.fFloat;
    v9 = key._type;
    goto LABEL_12;
  }
  if ( type != OT_BOOL && type != OT_INTEGER )
  {
LABEL_10:
    v9 = nInteger >> 3;
    goto LABEL_12;
  }
  v9 = nInteger;
LABEL_12:
  v10 = this;
  *mainpos = v9 & (this->_numofslots - 1);
  if ( v8 != 0 && (int)--*(_DWORD *)(nInteger + 4) <= 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)nInteger + 8))(a1: nInteger);
  result = this->_buckets[*mainpos];
  *prev = nullptr;
  if ( result != nullptr )
  {
    v12.pTable = (SQTable *)obj->_unVal;
    while ( result->obj._unVal.nInteger != v12.nInteger || result->obj._type != obj->_type )
    {
      *prev = result;
      result = result->next;
      if ( result == nullptr )
        goto LABEL_20;
    }
  }
  else
  {
LABEL_20:
    if ( add )
    {
      if ( this->_numofslots == this->_slotused )
      {
        RefTable::Resize(a1: (int)prev, size: 2 * this->_numofslots, this);
        v13 = &obj->_unVal.pTable->__vftable;
        key = *obj;
        v14 = key._type & 0x8000000;
        if ( (key._type & 0x8000000) != 0 )
          ++v13[1];
        *mainpos = (this->_numofslots - 1) & HashObj(&key);
        if ( v14 != 0 && (int)--v13[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
        v10 = this;
      }
      return RefTable::Add(this: v10, obj, mainpos: *mainpos);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054890
// Name: private: void RefTable::AllocNodes(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RefTable::AllocNodes(unsigned int size@<edi>, RefTable *this)
{
  RefTable::RefNode **v2; // eax
  unsigned int v3; // edx
  RefTable::RefNode **v4; // ecx
  RefTable::RefNode *v5; // edx

  v2 = (RefTable::RefNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20 * size);
  v3 = 0;
  v4 = &v2[size];
  if ( size != 1 )
  {
    do
    {
      v2[v3] = nullptr;
      v4[2] = nullptr;
      v4[1] = nullptr;
      v4[3] = (RefTable::RefNode *)(v4 + 4);
      *v4 = (RefTable::RefNode *)16777217;
      v4 += 4;
      ++v3;
    }
    while ( v3 < size - 1 );
  }
  v2[v3] = nullptr;
  v4[2] = nullptr;
  v4[1] = nullptr;
  v4[3] = nullptr;
  *v4 = (RefTable::RefNode *)16777217;
  v5 = (RefTable::RefNode *)&v2[size];
  this->_slotused = 0;
  this->_freelist = v5;
  this->_nodes = v5;
  this->_buckets = v2;
  this->_numofslots = size;
}

//------------------------------------------------------------------------------
// Address: 0x10054910
// Name: public: struct SQString __near * StringTable::Add(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
SQString *__userpurge StringTable::Add@<eax>(int len@<eax>, StringTable *this, char *news)
{
  unsigned int v3; // edi
  char *v4; // ecx
  unsigned int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // ecx
  SQString *result; // eax
  char *v9; // esi
  unsigned int v10; // ecx
  char *val; // edx
  SQString *v12; // ebx
  char *v13; // ecx
  unsigned int j; // eax
  unsigned int numofslots; // eax
  unsigned int h; // [esp+Ch] [ebp-Ch]
  unsigned int i; // [esp+10h] [ebp-8h]
  unsigned int v18; // [esp+14h] [ebp-4h]
  unsigned int v19; // [esp+14h] [ebp-4h]

  v3 = len;
  if ( len < 0 )
    v3 = strlen(news);
  v4 = news;
  v5 = (v3 | 0x20) >> 5;
  v18 = v3;
  v6 = v3;
  for ( i = v5; v18 >= v5; v18 -= v5 )
    v6 ^= (unsigned __int16)*v4++ + (v6 >> 2) + 32 * v6;
  v7 = v6 & (this->_numofslots - 1);
  result = this->_strings[v7];
  h = v7;
  while ( result != nullptr )
  {
    if ( result->_len == v3 )
    {
      v9 = news;
      v10 = v3;
      val = result->_val;
      if ( v3 < 4 )
      {
LABEL_10:
        if ( v10 == 0 || *val == *v9 && (v10 <= 1 || val[1] == v9[1] && (v10 <= 2 || val[2] == v9[2])) )
          return result;
      }
      else
      {
        while ( *(_DWORD *)v9 == *(_DWORD *)val )
        {
          v10 -= 4;
          val += 4;
          v9 += 4;
          if ( v10 < 4 )
            goto LABEL_10;
        }
      }
      v5 = i;
    }
    result = result->_next;
  }
  v12 = (SQString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v3 + 32);
  if ( v12 != nullptr )
  {
    v12->_uiRef = 0;
    v12->_weakref = nullptr;
    v12->__vftable = (SQString_vtbl *)&SQString::`vftable';
  }
  memcpy(dst: (unsigned __int8 *)v12->_val, src: (unsigned __int8 *)news, count: v3);
  v13 = news;
  v12->_val[v3] = 0;
  v12->_len = v3;
  v19 = v3;
  for ( j = v3; v19 >= v5; v19 -= v5 )
    j ^= (unsigned __int16)*v13++ + (j >> 2) + 32 * j;
  v12->_hash = j;
  v12->_next = this->_strings[h];
  this->_strings[h] = v12;
  numofslots = this->_numofslots;
  if ( ++this->_slotused > numofslots )
    StringTable::Resize(this, size: 2 * numofslots);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10054A90
// Name: private: void StringTable::Resize(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall StringTable::Resize(StringTable *this@<esi>, unsigned int size@<eax>)
{
  SQString **strings; // ecx
  signed int numofslots; // ebx
  SQString **v4; // eax
  signed int i; // edi
  SQString *v6; // eax
  SQString *next; // edx
  unsigned int v8; // ecx
  unsigned int v9; // [esp-4h] [ebp-14h]
  int oldsize; // [esp+8h] [ebp-8h]
  SQString **oldtable; // [esp+Ch] [ebp-4h]

  strings = this->_strings;
  numofslots = this->_numofslots;
  this->_numofslots = size;
  oldtable = strings;
  oldsize = numofslots;
  v4 = (SQString **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * size);
  v9 = 4 * this->_numofslots;
  this->_strings = v4;
  memset(dst: (int)v4, value: nullptr, count: v9);
  for ( i = 0; i < numofslots; ++i )
  {
    v6 = oldtable[i];
    if ( v6 != nullptr )
    {
      do
      {
        next = v6->_next;
        v8 = (this->_numofslots - 1) & v6->_hash;
        v6->_next = this->_strings[v8];
        this->_strings[v8] = v6;
        v6 = next;
      }
      while ( next != nullptr );
      numofslots = oldsize;
    }
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: oldtable);
}
