// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqlexer.cpp
// Functions: 10
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqlexer.h"

//------------------------------------------------------------------------------
// Address: 0x1004A130
// Name: public: void SQLexer::Init(struct SQSharedState __near *,int (*)(void __near *),void __near *,void (*)(void __near *,char const __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQLexer::Init(
        SQSharedState *ss@<edi>,
        void *ed@<eax>,
        SQLexer *this,
        int (__cdecl *rg)(void *),
        void *up,
        void (__cdecl *efunc)(void *, const char *))
{
  SQTable *v7; // eax
  int i; // esi
  SQCollectable *gc_chain; // eax
  SQString *v10; // eax
  tagSQObjectValue v11; // eax
  tagSQObjectValue v12; // eax
  SQString *v13; // eax
  tagSQObjectValue v14; // eax
  tagSQObjectValue v15; // eax
  SQString *v16; // eax
  tagSQObjectValue v17; // eax
  tagSQObjectValue v18; // eax
  SQString *v19; // eax
  tagSQObjectValue v20; // eax
  tagSQObjectValue v21; // eax
  SQString *v22; // eax
  tagSQObjectValue v23; // eax
  tagSQObjectValue v24; // eax
  SQString *v25; // eax
  tagSQObjectValue v26; // eax
  tagSQObjectValue v27; // eax
  SQString *v28; // eax
  tagSQObjectValue v29; // eax
  tagSQObjectValue v30; // eax
  SQString *v31; // eax
  tagSQObjectValue v32; // eax
  tagSQObjectValue v33; // eax
  SQString *v34; // eax
  tagSQObjectValue v35; // eax
  tagSQObjectValue v36; // eax
  SQString *v37; // eax
  tagSQObjectValue v38; // eax
  tagSQObjectValue v39; // eax
  SQString *v40; // eax
  tagSQObjectValue v41; // eax
  tagSQObjectValue v42; // eax
  SQString *v43; // eax
  tagSQObjectValue v44; // eax
  tagSQObjectValue v45; // eax
  SQString *v46; // eax
  tagSQObjectValue v47; // eax
  tagSQObjectValue v48; // eax
  SQString *v49; // eax
  tagSQObjectValue v50; // eax
  tagSQObjectValue v51; // eax
  SQString *v52; // eax
  tagSQObjectValue v53; // eax
  tagSQObjectValue v54; // eax
  SQString *v55; // eax
  tagSQObjectValue v56; // eax
  tagSQObjectValue v57; // eax
  SQString *v58; // eax
  tagSQObjectValue v59; // eax
  tagSQObjectValue v60; // eax
  SQString *v61; // eax
  tagSQObjectValue v62; // eax
  tagSQObjectValue v63; // eax
  SQString *v64; // eax
  tagSQObjectValue v65; // eax
  tagSQObjectValue v66; // eax
  SQString *v67; // eax
  tagSQObjectValue v68; // eax
  tagSQObjectValue v69; // eax
  SQString *v70; // eax
  tagSQObjectValue v71; // eax
  tagSQObjectValue v72; // eax
  SQString *v73; // eax
  tagSQObjectValue v74; // eax
  tagSQObjectValue v75; // eax
  SQString *v76; // eax
  tagSQObjectValue v77; // eax
  tagSQObjectValue v78; // eax
  SQString *v79; // eax
  tagSQObjectValue v80; // eax
  tagSQObjectValue v81; // eax
  SQString *v82; // eax
  tagSQObjectValue v83; // eax
  tagSQObjectValue v84; // eax
  SQString *v85; // eax
  tagSQObjectValue v86; // eax
  tagSQObjectValue v87; // eax
  SQString *v88; // eax
  tagSQObjectValue v89; // eax
  tagSQObjectValue v90; // eax
  SQString *v91; // eax
  tagSQObjectValue v92; // eax
  tagSQObjectValue v93; // eax
  SQString *v94; // eax
  tagSQObjectValue v95; // eax
  tagSQObjectValue v96; // eax
  SQString *v97; // eax
  tagSQObjectValue v98; // eax
  tagSQObjectValue v99; // eax
  SQString *v100; // eax
  tagSQObjectValue v101; // eax
  tagSQObjectValue v102; // eax
  SQString *v103; // eax
  tagSQObjectValue v104; // eax
  tagSQObjectValue v105; // eax
  SQString *v106; // eax
  tagSQObjectValue v107; // eax
  tagSQObjectValue v108; // eax
  SQString *v109; // eax
  tagSQObjectValue v110; // eax
  tagSQObjectValue v111; // eax
  SQString *v112; // eax
  tagSQObjectValue v113; // eax
  tagSQObjectValue v114; // eax
  SQString *v115; // eax
  tagSQObjectValue v116; // eax
  tagSQObjectValue v117; // eax
  SQString *v118; // eax
  tagSQObjectValue v119; // eax
  tagSQObjectValue v120; // eax
  SQString *v121; // eax
  tagSQObjectValue v122; // eax
  tagSQObjectValue v123; // eax
  int v124; // eax
  StringTable *stringtable; // [esp-8h] [ebp-20h]
  StringTable *v126; // [esp-8h] [ebp-20h]
  StringTable *v127; // [esp-8h] [ebp-20h]
  StringTable *v128; // [esp-8h] [ebp-20h]
  StringTable *v129; // [esp-8h] [ebp-20h]
  StringTable *v130; // [esp-8h] [ebp-20h]
  StringTable *v131; // [esp-8h] [ebp-20h]
  StringTable *v132; // [esp-8h] [ebp-20h]
  StringTable *v133; // [esp-8h] [ebp-20h]
  StringTable *v134; // [esp-8h] [ebp-20h]
  StringTable *v135; // [esp-8h] [ebp-20h]
  StringTable *v136; // [esp-8h] [ebp-20h]
  StringTable *v137; // [esp-8h] [ebp-20h]
  StringTable *v138; // [esp-8h] [ebp-20h]
  StringTable *v139; // [esp-8h] [ebp-20h]
  StringTable *v140; // [esp-8h] [ebp-20h]
  StringTable *v141; // [esp-8h] [ebp-20h]
  StringTable *v142; // [esp-8h] [ebp-20h]
  StringTable *v143; // [esp-8h] [ebp-20h]
  StringTable *v144; // [esp-8h] [ebp-20h]
  StringTable *v145; // [esp-8h] [ebp-20h]
  StringTable *v146; // [esp-8h] [ebp-20h]
  StringTable *v147; // [esp-8h] [ebp-20h]
  StringTable *v148; // [esp-8h] [ebp-20h]
  StringTable *v149; // [esp-8h] [ebp-20h]
  StringTable *v150; // [esp-8h] [ebp-20h]
  StringTable *v151; // [esp-8h] [ebp-20h]
  StringTable *v152; // [esp-8h] [ebp-20h]
  StringTable *v153; // [esp-8h] [ebp-20h]
  StringTable *v154; // [esp-8h] [ebp-20h]
  StringTable *v155; // [esp-8h] [ebp-20h]
  StringTable *v156; // [esp-8h] [ebp-20h]
  StringTable *v157; // [esp-8h] [ebp-20h]
  StringTable *v158; // [esp-8h] [ebp-20h]
  StringTable *v159; // [esp-8h] [ebp-20h]
  StringTable *v160; // [esp-8h] [ebp-20h]
  StringTable *v161; // [esp-8h] [ebp-20h]
  StringTable *v162; // [esp-8h] [ebp-20h]
  SQObjectPtr val; // [esp+8h] [ebp-10h] BYREF
  SQObjectPtr key; // [esp+10h] [ebp-8h] BYREF
  SQCollectable *thisa; // [esp+20h] [ebp+8h]
  SQLexer *thisb; // [esp+20h] [ebp+8h]

  this->_errtarget = ed;
  this->_errfunc = (void (__cdecl *)(void *, const char *))SQCompiler::ThrowError;
  this->_sharedstate = ss;
  v7 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  thisa = v7;
  if ( v7 != nullptr )
  {
    v7->_uiRef = 0;
    v7->_weakref = nullptr;
    v7->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    for ( i = 4; i < 26; i *= 2 )
      ;
    SQTable::AllocNodes(this: v7, nSize: i);
    thisa->_next = nullptr;
    thisa[1]._prev = nullptr;
    thisa[1].__vftable = nullptr;
    thisa->_sharedstate = ss;
    thisa->_prev = nullptr;
    thisa->_next = ss->_gc_chain;
    gc_chain = ss->_gc_chain;
    if ( gc_chain != nullptr )
      gc_chain->_prev = thisa;
    ss->_gc_chain = thisa;
    v7 = (SQTable *)thisa;
  }
  v7->_delegate = nullptr;
  this->_keywords = v7;
  stringtable = ss->_stringtable;
  val._type = OT_INTEGER;
  val._unVal.nInteger = 274;
  v10 = StringTable::Add(this: stringtable, news: "while", len: -1);
  v10->_sharedstate = ss;
  key._type = OT_STRING;
  key._unVal.nInteger = (int)v10;
  ++v10->_uiRef;
  SQTable::NewSlot(this: this->_keywords, &key, &val);
  if ( (key._type & 0x8000000) != 0 )
  {
    v11.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v11.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  if ( (val._type & 0x8000000) != 0 )
  {
    v12.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v12.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  v126 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 277;
  v13 = StringTable::Add(this: v126, news: "do", len: -1);
  v13->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v13;
  ++v13->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v14.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v14.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v15.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v15.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v127 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 272;
  v16 = StringTable::Add(this: v127, news: "if", len: -1);
  v16->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v16;
  ++v16->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v17.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v17.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v18.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v18.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v128 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 273;
  v19 = StringTable::Add(this: v128, news: "else", len: -1);
  v19->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v19;
  ++v19->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v20.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v20.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v21.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v21.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v129 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 275;
  v22 = StringTable::Add(this: v129, news: "break", len: -1);
  v22->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v22;
  ++v22->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v23.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v23.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v24.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v24.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v130 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 291;
  v25 = StringTable::Add(this: v130, news: "continue", len: -1);
  v25->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v25;
  ++v25->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v26.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v26.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v27.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v27.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v131 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 286;
  v28 = StringTable::Add(this: v131, news: "return", len: -1);
  v28->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v28;
  ++v28->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v29.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v29.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v30.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v30.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v132 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 278;
  v31 = StringTable::Add(this: v132, news: "null", len: -1);
  v31->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v31;
  ++v31->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v32.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v32.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v33.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v33.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v133 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 285;
  v34 = StringTable::Add(this: v133, news: "function", len: -1);
  v34->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v34;
  ++v34->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v35.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v35.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v36.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v36.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v134 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 283;
  v37 = StringTable::Add(this: v134, news: "local", len: -1);
  v37->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v37;
  ++v37->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v38.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v38.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v39.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v39.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v135 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 276;
  v40 = StringTable::Add(this: v135, news: "for", len: -1);
  v40->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v40;
  ++v40->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v41.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v41.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v42.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v42.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v136 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 279;
  v43 = StringTable::Add(this: v136, news: "foreach", len: -1);
  v43->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v43;
  ++v43->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v44.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v44.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v45.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v45.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v137 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 280;
  v46 = StringTable::Add(this: v137, news: "in", len: -1);
  v46->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v46;
  ++v46->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v47.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v47.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v48.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v48.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v138 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 287;
  v49 = StringTable::Add(this: v138, news: "typeof", len: -1);
  v49->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v49;
  ++v49->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v50.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v50.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v51.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v51.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v139 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 262;
  v52 = StringTable::Add(this: v139, news: "delegate", len: -1);
  v52->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v52;
  ++v52->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v53.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v53.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v54.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v54.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v140 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 263;
  v55 = StringTable::Add(this: v140, news: "delete", len: -1);
  v55->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v55;
  ++v55->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v56.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v56.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v57.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v57.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v141 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 293;
  v58 = StringTable::Add(this: v141, news: "try", len: -1);
  v58->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v58;
  ++v58->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v59.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v59.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v60.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v60.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v142 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 294;
  v61 = StringTable::Add(this: v142, news: "catch", len: -1);
  v61->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v61;
  ++v61->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v62.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v62.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v63.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v63.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v143 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 295;
  v64 = StringTable::Add(this: v143, news: "throw", len: -1);
  v64->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v64;
  ++v64->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v65.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v65.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v66.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v66.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v144 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 284;
  v67 = StringTable::Add(this: v144, news: "clone", len: -1);
  v67->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v67;
  ++v67->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v68.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v68.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v69.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v69.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v145 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 292;
  v70 = StringTable::Add(this: v145, news: "yield", len: -1);
  v70->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v70;
  ++v70->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v71.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v71.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v72.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v72.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v146 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 298;
  v73 = StringTable::Add(this: v146, news: "resume", len: -1);
  v73->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v73;
  ++v73->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v74.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v74.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v75.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v75.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v147 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 268;
  v76 = StringTable::Add(this: v147, news: "switch", len: -1);
  v76->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v76;
  ++v76->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v77.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v77.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v78.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v78.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v148 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 300;
  v79 = StringTable::Add(this: v148, news: "case", len: -1);
  v79->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v79;
  ++v79->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v80.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v80.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v81.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v81.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v149 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 301;
  v82 = StringTable::Add(this: v149, news: "default", len: -1);
  v82->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v82;
  ++v82->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v83.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v83.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v84.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v84.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v150 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 302;
  v85 = StringTable::Add(this: v150, news: (const char *)&stru_1009C274._lex._longstr, len: -1);
  v85->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v85;
  ++v85->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v86.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v86.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v87.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v87.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v151 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 305;
  v88 = StringTable::Add(this: v151, news: "parent", len: -1);
  v88->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v88;
  ++v88->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v89.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v89.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v90.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v90.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v152 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 307;
  v91 = StringTable::Add(this: v152, news: "class", len: -1);
  v91->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v91;
  ++v91->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v92.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v92.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v93.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v93.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v153 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 308;
  v94 = StringTable::Add(this: v153, news: "extends", len: -1);
  v94->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v94;
  ++v94->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v95.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v95.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v96.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v96.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v154 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 310;
  v97 = StringTable::Add(this: v154, news: "constructor", len: -1);
  v97->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v97;
  ++v97->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v98.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v98.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v99.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v99.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v155 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 311;
  v100 = StringTable::Add(this: v155, news: "instanceof", len: -1);
  v100->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v100;
  ++v100->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v101.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v101.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v102.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v102.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v156 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 313;
  v103 = StringTable::Add(this: v156, news: "vargc", len: -1);
  v103->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v103;
  ++v103->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v104.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v104.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v105.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v105.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v157 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 314;
  v106 = StringTable::Add(this: v157, news: "vargv", len: -1);
  v106->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v106;
  ++v106->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v107.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v107.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v108.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v108.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v158 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 315;
  v109 = StringTable::Add(this: v158, news: "true", len: -1);
  v109->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v109;
  ++v109->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v110.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v110.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v111.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v111.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v159 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 316;
  v112 = StringTable::Add(this: v159, news: "false", len: -1);
  v112->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v112;
  ++v112->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v113.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v113.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v114.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v114.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v160 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 322;
  v115 = StringTable::Add(this: v160, news: "static", len: -1);
  v115->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v115;
  ++v115->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v116.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v116.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v117.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v117.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v161 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 323;
  v118 = StringTable::Add(this: v161, news: "enum", len: -1);
  v118->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v118;
  ++v118->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v119.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v119.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v120.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v120.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  v162 = ss->_stringtable;
  key._type = OT_INTEGER;
  key._unVal.nInteger = 324;
  v121 = StringTable::Add(this: v162, news: "const", len: -1);
  v121->_sharedstate = ss;
  val._type = OT_STRING;
  val._unVal.nInteger = (int)v121;
  ++v121->_uiRef;
  SQTable::NewSlot(this: this->_keywords, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v122.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v122.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v123.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v123.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  this->_readf = (int (__cdecl *)(void *))buf_lexfeed;
  this->_up = rg;
  this->_currentline = 1;
  this->_lasttokenline = 1;
  this->_currentcolumn = 0;
  this->_prevtoken = -1;
  v124 = buf_lexfeed(file: rg);
  thisb = (SQLexer *)v124;
  if ( v124 > 255 )
  {
    this->_errfunc(a1: this->_errtarget, a2: "Invalid character");
    v124 = (int)thisb;
  }
  this->_currdata = v124 != 0 ? v124 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004B380
// Name: public: char const __near * SQLexer::Tok2Str(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SQLexer::Tok2Str(SQLexer *this, SQLexer *tok, int toka)
{
  tagSQObjectValue v3; // edi
  int *v4; // ecx
  int *pTable; // ecx
  int *v6; // ecx
  _DWORD *v8; // esi
  SQTable *keywords; // [esp-Ch] [ebp-34h]
  SQObjectPtr itr; // [esp+10h] [ebp-18h] BYREF
  SQObjectPtr key; // [esp+18h] [ebp-10h] BYREF
  SQObjectPtr val; // [esp+20h] [ebp-8h] BYREF

  keywords = tok->_keywords;
  itr._type = OT_NULL;
  itr._unVal.nInteger = 0;
  key._type = OT_NULL;
  key._unVal.nInteger = 0;
  val._type = OT_NULL;
  val._unVal.nInteger = 0;
  v3.nInteger = SQTable::Next(this: keywords, getweakrefs: false, refpos: &itr, outkey: &key, outval: &val);
  if ( v3.nInteger == -1 )
  {
LABEL_4:
    if ( (val._type & 0x8000000) != 0 )
    {
      pTable = (int *)val._unVal.pTable;
      --*(_DWORD *)(val._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    if ( (key._type & 0x8000000) != 0 )
    {
      v6 = (int *)key._unVal.pTable;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( v6[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v6 + 8))(a1: v6);
    }
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v4 = (int *)val._unVal.pTable;
      itr._unVal = v3;
      itr._type = OT_INTEGER;
      if ( val._unVal.nInteger == toka )
        break;
      v3.nInteger = SQTable::Next(this: tok->_keywords, getweakrefs: false, refpos: &itr, outkey: &key, outval: &val);
      if ( v3.nInteger == -1 )
        goto LABEL_4;
    }
    v8 = &key._unVal.pTable->__vftable;
    if ( (val._type & 0x8000000) != 0 )
    {
      --*(_DWORD *)(val._unVal.nInteger + 4);
      if ( v4[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v4 + 8))(a1: v4);
    }
    if ( (key._type & 0x8000000) != 0 && (int)--v8[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
    return (const char *)(v8 + 7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B4B0
// Name: private: void SQLexer::LexBlockComment(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQLexer::LexBlockComment(SQLexer *this@<ecx>, int a2@<esi>)
{
  char v2; // al
  int v3; // ebx
  char v4; // cl
  int v5; // ebx
  int v6; // edx
  int (__cdecl *v7)(int); // eax
  int v8; // ebx
  int v9; // ebx

  do
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v2 = *(_BYTE *)(a2 + 44);
        if ( v2 != 0 )
          break;
        (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "missing \"*/\" in comment");
LABEL_14:
        v9 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v9 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v9 != 0 ? v9 : 0;
      }
      if ( v2 != 10 )
        break;
      v6 = *(_DWORD *)(a2 + 40);
      v7 = *(int (__cdecl **)(int))(a2 + 36);
      ++*(_DWORD *)(a2 + 12);
      v8 = v7(a1: v6);
      if ( v8 > 255 )
        (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
      ++*(_DWORD *)(a2 + 20);
      *(_BYTE *)(a2 + 44) = v8 != 0 ? v8 : 0;
    }
    if ( v2 != 42 )
      goto LABEL_14;
    v3 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
    if ( v3 > 255 )
      (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
    ++*(_DWORD *)(a2 + 20);
    v4 = v3 != 0 ? v3 : 0;
    *(_BYTE *)(a2 + 44) = v4;
  }
  while ( v4 != 47 );
  v5 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
  if ( v5 > 255 )
    (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
  ++*(_DWORD *)(a2 + 20);
  *(_BYTE *)(a2 + 44) = v5 != 0 ? v5 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004B5E0
// Name: public: int SQLexer::Lex(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall SQLexer::Lex@<eax>(SQLexer *this@<ecx>, int a2@<eax>)
{
  bool v3; // zf
  int v4; // ebx
  int v5; // ecx
  int v6; // edx
  int (__cdecl *v7)(int); // eax
  int v8; // ebx
  int v9; // ebx
  char v10; // dl
  SQLexer *v11; // ecx
  int v12; // ebx
  int v13; // ebx
  char v14; // cl
  int result; // eax
  int v16; // ebx
  int v17; // ecx
  int v18; // ebx
  int v19; // ecx
  int v20; // ebx
  char v21; // cl
  int v22; // ebx
  int v23; // edx
  int v24; // ebx
  char v25; // cl
  int v26; // ebx
  int v27; // ecx
  int v28; // ebx
  int v29; // ecx
  int v30; // ebx
  int v31; // ecx
  int v32; // ebx
  int v33; // ecx
  int v34; // ebx
  char v35; // cl
  int v36; // ebx
  int v37; // ecx
  int v38; // ebx
  char v39; // al
  int v40; // ebx
  int v41; // eax
  int v42; // ebx
  char v43; // cl
  int v44; // ebx
  int v45; // edx
  int v46; // ebx
  SQLexer *v47; // ecx
  int v48; // edi
  int v49; // ebx
  int v50; // ecx
  int v51; // ebx
  char v52; // al
  int v53; // ebx
  char v54; // al
  int v55; // ebx
  int v56; // edx
  int v57; // ebx
  char v58; // cl
  int v59; // ebx
  int v60; // edx
  int v61; // ebx
  char v62; // cl
  int v63; // ebx
  int v64; // edx
  int v65; // ebx
  char v66; // cl
  int v67; // ebx
  int v68; // edx
  int v69; // ebx
  char v70; // cl
  int v71; // ebx
  int v72; // ecx
  int v73; // ebx
  char v74; // cl
  int v75; // ebx
  int v76; // ecx
  int v77; // ebx
  char v78; // cl
  int v79; // ebx
  int v80; // ecx
  int v81; // ebx
  int v82; // ecx
  int v83; // ebx
  char v84; // cl
  int v85; // ebx
  int v86; // ecx
  int v87; // ebx
  int v88; // ecx
  int v89; // edx
  SQLexer *v90; // ecx
  SQLexer *v91; // ecx
  unsigned __int8 v92; // al
  int v93; // ecx
  int v94; // edx

  v3 = *(_BYTE *)(a2 + 44) == 0;
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(a2 + 12);
  if ( v3 )
    return 0;
  while ( 2 )
  {
    switch ( *(_BYTE *)(a2 + 44) )
    {
      case 0:
        return 0;
      case 9:
      case 0xD:
      case 0x20:
        v4 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v4 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v4 != 0 ? v4 : 0;
        goto LABEL_19;
      case 0xA:
        v5 = *(_DWORD *)a2;
        v6 = *(_DWORD *)(a2 + 40);
        v7 = *(int (__cdecl **)(int))(a2 + 36);
        ++*(_DWORD *)(a2 + 12);
        *(_DWORD *)(a2 + 8) = v5;
        *(_DWORD *)a2 = 10;
        v8 = v7(a1: v6);
        if ( v8 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        *(_BYTE *)(a2 + 44) = v8 != 0 ? v8 : 0;
        *(_DWORD *)(a2 + 20) = 1;
LABEL_19:
        if ( *(_BYTE *)(a2 + 44) == 0 )
          return 0;
        continue;
      case 0x21:
        v42 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v42 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v43 = v42 != 0 ? v42 : 0;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v43;
        if ( v43 == 61 )
        {
          v44 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v44 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          v45 = *(_DWORD *)a2;
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v44 != 0 ? v44 : 0;
          *(_DWORD *)(a2 + 8) = v45;
          *(_DWORD *)a2 = 265;
          return 265;
        }
        else
        {
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
          *(_DWORD *)a2 = 33;
          return 33;
        }
      case 0x22:
      case 0x27:
        goto $LN212;
      case 0x25:
        v73 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v73 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v74 = v73 != 0 ? v73 : 0;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v74;
        if ( v74 == 61 )
        {
          v75 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v75 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          v76 = *(_DWORD *)a2;
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v75 != 0 ? v75 : 0;
          *(_DWORD *)(a2 + 8) = v76;
          *(_DWORD *)a2 = 319;
          return 319;
        }
        else
        {
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
          *(_DWORD *)a2 = 37;
          return 37;
        }
      case 0x26:
        v57 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v57 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v58 = v57 != 0 ? v57 : 0;
        ++*(_DWORD *)(a2 + 20);
        result = 38;
        *(_BYTE *)(a2 + 44) = v58;
        if ( v58 != 38 )
          goto LABEL_31;
        v59 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v59 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v60 = *(_DWORD *)a2;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v59 != 0 ? v59 : 0;
        *(_DWORD *)(a2 + 8) = v60;
        *(_DWORD *)a2 = 270;
        return 270;
      case 0x28:
      case 0x29:
      case 0x2C:
      case 0x3B:
      case 0x3F:
      case 0x5B:
      case 0x5D:
      case 0x5E:
      case 0x7B:
      case 0x7D:
      case 0x7E:
        goto $LN214;
      case 0x2A:
        v69 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v69 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v70 = v69 != 0 ? v69 : 0;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v70;
        if ( v70 == 61 )
        {
          v71 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v71 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          v72 = *(_DWORD *)a2;
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v71 != 0 ? v71 : 0;
          *(_DWORD *)(a2 + 8) = v72;
          *(_DWORD *)a2 = 317;
          return 317;
        }
        else
        {
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
          *(_DWORD *)a2 = 42;
          return 42;
        }
      case 0x2B:
        v83 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v83 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v84 = v83 != 0 ? v83 : 0;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v84;
        if ( v84 == 61 )
        {
          v85 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v85 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          v86 = *(_DWORD *)a2;
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v85 != 0 ? v85 : 0;
          *(_DWORD *)(a2 + 8) = v86;
          *(_DWORD *)a2 = 289;
          return 289;
        }
        else if ( v84 == 43 )
        {
          v87 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v87 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          v88 = *(_DWORD *)a2;
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v87 != 0 ? v87 : 0;
          *(_DWORD *)(a2 + 8) = v88;
          *(_DWORD *)a2 = 303;
          return 303;
        }
        else
        {
          v89 = *(_DWORD *)a2;
          *(_DWORD *)a2 = 43;
          *(_DWORD *)(a2 + 8) = v89;
          return 43;
        }
      case 0x2D:
        v77 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v77 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v78 = v77 != 0 ? v77 : 0;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v78;
        if ( v78 == 61 )
        {
          v79 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v79 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          v80 = *(_DWORD *)a2;
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v79 != 0 ? v79 : 0;
          *(_DWORD *)(a2 + 8) = v80;
          *(_DWORD *)a2 = 290;
          return 290;
        }
        else if ( v78 == 45 )
        {
          v81 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v81 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          v82 = *(_DWORD *)a2;
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v81 != 0 ? v81 : 0;
          *(_DWORD *)(a2 + 8) = v82;
          *(_DWORD *)a2 = 304;
          return 304;
        }
        else
        {
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
          *(_DWORD *)a2 = 45;
          return 45;
        }
      case 0x2E:
        v51 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v51 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v52 = v51 != 0 ? v51 : 0;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v52;
        if ( v52 == 46 )
        {
          v53 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v53 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          ++*(_DWORD *)(a2 + 20);
          v54 = v53 != 0 ? v53 : 0;
          *(_BYTE *)(a2 + 44) = v54;
          if ( v54 != 46 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "invalid token '..'");
          v55 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v55 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          v56 = *(_DWORD *)a2;
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v55 != 0 ? v55 : 0;
          *(_DWORD *)(a2 + 8) = v56;
          *(_DWORD *)a2 = 312;
          return 312;
        }
        else
        {
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
          *(_DWORD *)a2 = 46;
          return 46;
        }
      case 0x2F:
        v9 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v9 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v10 = v9 != 0 ? v9 : 0;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v10;
        switch ( v10 )
        {
          case '*':
            v12 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
            if ( v12 > 255 )
              (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
            ++*(_DWORD *)(a2 + 20);
            *(_BYTE *)(a2 + 44) = v12 != 0 ? v12 : 0;
            SQLexer::LexBlockComment(this: v11, a2);
            goto LABEL_19;
          case '/':
            do
            {
              v13 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
              if ( v13 > 255 )
                (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
              ++*(_DWORD *)(a2 + 20);
              v14 = v13 != 0 ? v13 : 0;
              *(_BYTE *)(a2 + 44) = v14;
            }
            while ( v14 != 10 && v14 != 0 );
            goto LABEL_19;
          case '=':
            v16 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
            if ( v16 > 255 )
              (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
            v17 = *(_DWORD *)a2;
            ++*(_DWORD *)(a2 + 20);
            *(_BYTE *)(a2 + 44) = v16 != 0 ? v16 : 0;
            *(_DWORD *)(a2 + 8) = v17;
            *(_DWORD *)a2 = 318;
            result = 318;
            break;
          case '>':
            v18 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
            if ( v18 > 255 )
              (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
            v19 = *(_DWORD *)a2;
            ++*(_DWORD *)(a2 + 20);
            *(_BYTE *)(a2 + 44) = v18 != 0 ? v18 : 0;
            *(_DWORD *)(a2 + 8) = v19;
            *(_DWORD *)a2 = 321;
            result = 321;
            break;
          default:
            *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
            *(_DWORD *)a2 = 47;
            result = 47;
            break;
        }
        return result;
      case 0x3A:
        v65 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v65 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v66 = v65 != 0 ? v65 : 0;
        ++*(_DWORD *)(a2 + 20);
        result = 58;
        *(_BYTE *)(a2 + 44) = v66;
        if ( v66 != 58 )
          goto LABEL_31;
        v67 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v67 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v68 = *(_DWORD *)a2;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v67 != 0 ? v67 : 0;
        *(_DWORD *)(a2 + 8) = v68;
        *(_DWORD *)a2 = 299;
        return 299;
      case 0x3C:
        v24 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v24 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v25 = v24 != 0 ? v24 : 0;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v25;
        switch ( v25 )
        {
          case '=':
            v26 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
            if ( v26 > 255 )
              (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
            v27 = *(_DWORD *)a2;
            ++*(_DWORD *)(a2 + 20);
            *(_BYTE *)(a2 + 44) = v26 != 0 ? v26 : 0;
            *(_DWORD *)(a2 + 8) = v27;
            *(_DWORD *)a2 = 266;
            return 266;
          case '-':
            v28 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
            if ( v28 > 255 )
              (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
            v29 = *(_DWORD *)a2;
            ++*(_DWORD *)(a2 + 20);
            *(_BYTE *)(a2 + 44) = v28 != 0 ? v28 : 0;
            *(_DWORD *)(a2 + 8) = v29;
            *(_DWORD *)a2 = 281;
            return 281;
          case '<':
            v30 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
            if ( v30 > 255 )
              (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
            v31 = *(_DWORD *)a2;
            ++*(_DWORD *)(a2 + 20);
            *(_BYTE *)(a2 + 44) = v30 != 0 ? v30 : 0;
            *(_DWORD *)(a2 + 8) = v31;
            *(_DWORD *)a2 = 296;
            return 296;
          case '/':
            v32 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
            if ( v32 > 255 )
              (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
            v33 = *(_DWORD *)a2;
            ++*(_DWORD *)(a2 + 20);
            *(_BYTE *)(a2 + 44) = v32 != 0 ? v32 : 0;
            *(_DWORD *)(a2 + 8) = v33;
            *(_DWORD *)a2 = 320;
            return 320;
          default:
            *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
            *(_DWORD *)a2 = 60;
            return 60;
        }
      case 0x3D:
        v20 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v20 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v21 = v20 != 0 ? v20 : 0;
        ++*(_DWORD *)(a2 + 20);
        result = 61;
        *(_BYTE *)(a2 + 44) = v21;
        if ( v21 != 61 )
          goto LABEL_31;
        v22 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v22 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v23 = *(_DWORD *)a2;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v22 != 0 ? v22 : 0;
        *(_DWORD *)(a2 + 8) = v23;
        *(_DWORD *)a2 = 264;
        return 264;
      case 0x3E:
        v34 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v34 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v35 = v34 != 0 ? v34 : 0;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v35;
        if ( v35 == 61 )
        {
          v36 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v36 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          v37 = *(_DWORD *)a2;
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v36 != 0 ? v36 : 0;
          *(_DWORD *)(a2 + 8) = v37;
          *(_DWORD *)a2 = 267;
          return 267;
        }
        else if ( v35 == 62 )
        {
          v38 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v38 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          ++*(_DWORD *)(a2 + 20);
          v39 = v38 != 0 ? v38 : 0;
          *(_BYTE *)(a2 + 44) = v39;
          if ( v39 == 62 )
          {
            v40 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
            if ( v40 > 255 )
              (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
            v41 = *(_DWORD *)a2;
            ++*(_DWORD *)(a2 + 20);
            *(_DWORD *)(a2 + 8) = v41;
            *(_BYTE *)(a2 + 44) = v40 != 0 ? v40 : 0;
            *(_DWORD *)a2 = 306;
            return 306;
          }
          else
          {
            *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
            *(_DWORD *)a2 = 297;
            return 297;
          }
        }
        else
        {
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
          *(_DWORD *)a2 = 62;
          return 62;
        }
      case 0x40:
        v46 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v46 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v47 = (SQLexer *)-v46;
        ++*(_DWORD *)(a2 + 20);
        LOBYTE(v47) = v46 != 0 ? v46 : 0;
        *(_BYTE *)(a2 + 44) = (_BYTE)v47;
        if ( (_BYTE)v47 != 34 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "string expected");
        result = SQLexer::ReadString(this: v47, ndelim: 34, verbatim: true);
        if ( result != -1 )
          goto LABEL_154;
        (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "error parsing the string");
$LN212:
        result = SQLexer::ReadString(
                   this: (SQLexer *)*(unsigned __int8 *)(a2 + 44),
                   ndelim: *(unsigned __int8 *)(a2 + 44),
                   verbatim: false);
        if ( result != -1 )
        {
LABEL_31:
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
          *(_DWORD *)a2 = result;
          return result;
        }
        (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "error parsing the string");
$LN214:
        v48 = *(unsigned __int8 *)(a2 + 44);
        v49 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v49 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        goto LABEL_86;
      case 0x7C:
        v61 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v61 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v62 = v61 != 0 ? v61 : 0;
        ++*(_DWORD *)(a2 + 20);
        result = 124;
        *(_BYTE *)(a2 + 44) = v62;
        if ( v62 != 124 )
          goto LABEL_31;
        v63 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v63 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        v64 = *(_DWORD *)a2;
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v63 != 0 ? v63 : 0;
        *(_DWORD *)(a2 + 8) = v64;
        *(_DWORD *)a2 = 271;
        return 271;
      default:
        if ( isdigit(c: *(unsigned __int8 *)(a2 + 44)) != 0 )
        {
          result = SQLexer::ReadNumber(this: v90);
LABEL_154:
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
          *(_DWORD *)a2 = result;
        }
        else if ( isalpha(c: *(unsigned __int8 *)(a2 + 44)) != 0 || (v92 = *(_BYTE *)(a2 + 44)) == 95 )
        {
          result = SQLexer::ReadID(this: v91);
          v94 = *(_DWORD *)a2;
          *(_DWORD *)a2 = result;
          *(_DWORD *)(a2 + 8) = v94;
        }
        else
        {
          v48 = v92;
          if ( iscntrl(c: v92) != 0 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(
              a1: *(_DWORD *)(a2 + 68),
              a2: "unexpected character(control)");
          v49 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v49 <= 255 )
          {
LABEL_86:
            v50 = *(_DWORD *)a2;
            ++*(_DWORD *)(a2 + 20);
            *(_BYTE *)(a2 + 44) = v49 != 0 ? v49 : 0;
            *(_DWORD *)(a2 + 8) = v50;
            *(_DWORD *)a2 = v48;
            result = v48;
          }
          else
          {
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
            v93 = *(_DWORD *)a2;
            ++*(_DWORD *)(a2 + 20);
            *(_BYTE *)(a2 + 44) = v49 != 0 ? v49 : 0;
            *(_DWORD *)(a2 + 8) = v93;
            *(_DWORD *)a2 = v48;
            result = v48;
          }
        }
        break;
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C450
// Name: private: int SQLexer::GetIDType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int *__userpurge SQLexer::GetIDType@<eax>(char *s@<eax>, SQLexer *this)
{
  SQSharedState *sharedstate; // esi
  SQString *v3; // edi
  bool v4; // al
  bool v5; // bl
  int *pTable; // esi
  int *v8; // ecx
  StringTable *stringtable; // [esp-8h] [ebp-28h]
  SQTable *keywords; // [esp-4h] [ebp-24h]
  SQObjectPtr t; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr key; // [esp+18h] [ebp-8h] BYREF

  sharedstate = this->_sharedstate;
  stringtable = sharedstate->_stringtable;
  t._type = OT_NULL;
  t._unVal.nInteger = 0;
  v3 = StringTable::Add(this: stringtable, news: s, len: -1);
  v3->_sharedstate = sharedstate;
  ++v3->_uiRef;
  keywords = this->_keywords;
  key._type = OT_STRING;
  key._unVal.nInteger = (int)v3;
  v4 = SQTable::Get(this: keywords, &key, val: &t);
  --v3->_uiRef;
  v5 = v4;
  if ( v3->_uiRef <= 0 )
    v3->Release(this: v3);
  if ( v5 )
  {
    pTable = (int *)t._unVal.pTable;
    if ( (t._type & 0x8000000) != 0 )
    {
      --*(_DWORD *)(t._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    return pTable;
  }
  else
  {
    if ( (t._type & 0x8000000) != 0 )
    {
      v8 = (int *)t._unVal.pTable;
      --*(_DWORD *)(t._unVal.nInteger + 4);
      if ( v8[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v8 + 8))(a1: v8);
    }
    return (int *)258;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C520
// Name: private: int SQLexer::ReadString(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __userpurge SQLexer::ReadString@<eax>(SQLexer *this@<ecx>, int a2@<edi>, int ndelim, bool verbatim)
{
  void **v4; // esi
  int v5; // ebx
  char v6; // dl
  unsigned int v7; // eax
  unsigned int v8; // ebx
  void *v9; // eax
  int v10; // ecx
  bool v11; // zf
  char *v12; // eax
  int v13; // ebx
  unsigned int v14; // eax
  unsigned int v15; // ebx
  int v16; // ecx
  _BYTE *v17; // eax
  int v18; // ebx
  int v19; // ebx
  char v20; // al
  int v21; // ebx
  unsigned __int8 v22; // al
  int v23; // eax
  int (__cdecl *v24)(_DWORD); // ecx
  int v25; // ebx
  unsigned __int8 v26; // cl
  sqvector<char> *v27; // ecx
  int v28; // ebx
  unsigned int v29; // eax
  unsigned int v30; // ebx
  int v31; // ecx
  char *v32; // eax
  int v33; // ebx
  int v34; // ebx
  char v35; // al
  unsigned int v36; // eax
  unsigned int v37; // ebx
  int v38; // ecx
  _BYTE *v39; // eax
  int v40; // ebx
  unsigned int v42; // eax
  unsigned int v43; // ebx
  int v44; // ecx
  _BYTE *v45; // eax
  int v46; // [esp-4h] [ebp-20h]
  char temp[8]; // [esp+8h] [ebp-14h] BYREF
  char *sTemp; // [esp+10h] [ebp-Ch] BYREF
  int n; // [esp+14h] [ebp-8h]
  char val; // [esp+1Bh] [ebp-1h] BYREF

  v4 = (void **)(a2 + 52);
  *(_DWORD *)(a2 + 56) = 0;
  v5 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
  if ( v5 > 255 )
    (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
  if ( v5 != 0 )
    *(_BYTE *)(a2 + 44) = v5;
  else
    *(_BYTE *)(a2 + 44) = 0;
  ++*(_DWORD *)(a2 + 20);
  if ( *(_BYTE *)(a2 + 44) != 0 )
  {
    while ( *(unsigned __int8 *)(a2 + 44) == ndelim )
    {
LABEL_70:
      v34 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
      if ( v34 > 255 )
        (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
      ++*(_DWORD *)(a2 + 20);
      v35 = v34 != 0 ? v34 : 0;
      *(_BYTE *)(a2 + 44) = v35;
      if ( !verbatim || v35 != 34 )
      {
        v42 = *(_DWORD *)(a2 + 56);
        if ( *(_DWORD *)(a2 + 60) <= v42 )
        {
          v43 = 2 * v42;
          if ( 2 * v42 == 0 )
            v43 = 4;
          *v4 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *v4, a3: v43);
          *(_DWORD *)(a2 + 60) = v43;
        }
        v44 = *(_DWORD *)(a2 + 56);
        v11 = (char *)*v4 + v44 == nullptr;
        v45 = (char *)*v4 + v44;
        *(_DWORD *)(a2 + 56) = v44 + 1;
        if ( !v11 )
          *v45 = 0;
        if ( ndelim == 39 )
        {
          if ( *(_DWORD *)(a2 + 56) == 1 )
          {
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "empty constant");
          }
          else if ( *(_DWORD *)(a2 + 56) - 1 > 1 )
          {
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "constant too long");
          }
          *(_DWORD *)(a2 + 28) = *(char *)*v4;
          return 260;
        }
        else
        {
          *(_DWORD *)(a2 + 24) = *v4;
          return 259;
        }
      }
      v36 = *(_DWORD *)(a2 + 56);
      if ( *(_DWORD *)(a2 + 60) <= v36 )
      {
        v37 = 2 * v36;
        if ( 2 * v36 == 0 )
          v37 = 4;
        *v4 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *v4, a3: v37);
        *(_DWORD *)(a2 + 60) = v37;
      }
      v38 = *(_DWORD *)(a2 + 56);
      v11 = (char *)*v4 + v38 == nullptr;
      v39 = (char *)*v4 + v38;
      *(_DWORD *)(a2 + 56) = v38 + 1;
      if ( !v11 )
        *v39 = 34;
      v40 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
      if ( v40 > 255 )
        (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
      ++*(_DWORD *)(a2 + 20);
      *(_BYTE *)(a2 + 44) = v40 != 0 ? v40 : 0;
    }
    while ( 1 )
    {
      v6 = *(_BYTE *)(a2 + 44);
      val = v6;
      if ( v6 == 0 )
        break;
      if ( v6 == 10 )
      {
        if ( !verbatim )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "newline in a constant");
        v29 = *(_DWORD *)(a2 + 56);
        val = *(_BYTE *)(a2 + 44);
        if ( *(_DWORD *)(a2 + 60) <= v29 )
        {
          v30 = 2 * v29;
          if ( 2 * v29 == 0 )
            v30 = 4;
          *v4 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *v4, a3: v30);
          *(_DWORD *)(a2 + 60) = v30;
        }
        v31 = *(_DWORD *)(a2 + 56);
        v11 = (char *)*v4 + v31 == nullptr;
        v32 = (char *)*v4 + v31;
        *(_DWORD *)(a2 + 56) = v31 + 1;
        if ( !v11 )
          *v32 = val;
        v33 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v33 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        *(_BYTE *)(a2 + 44) = v33 != 0 ? v33 : 0;
        ++*(_DWORD *)(a2 + 20);
        ++*(_DWORD *)(a2 + 12);
      }
      else if ( v6 == 92 )
      {
        if ( verbatim )
        {
          v14 = *(_DWORD *)(a2 + 56);
          if ( *(_DWORD *)(a2 + 60) <= v14 )
          {
            v15 = 2 * v14;
            if ( 2 * v14 == 0 )
              v15 = 4;
            *v4 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *v4, a3: v15);
            *(_DWORD *)(a2 + 60) = v15;
          }
          v16 = *(_DWORD *)(a2 + 56);
          v11 = (char *)*v4 + v16 == nullptr;
          v17 = (char *)*v4 + v16;
          *(_DWORD *)(a2 + 56) = v16 + 1;
          if ( !v11 )
            *v17 = 92;
          v18 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v18 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v18 != 0 ? v18 : 0;
        }
        else
        {
          v19 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v19 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          ++*(_DWORD *)(a2 + 20);
          v20 = v19 != 0 ? v19 : 0;
          *(_BYTE *)(a2 + 44) = v20;
          switch ( v20 )
          {
            case '"':
              val = 34;
              goto LABEL_44;
            case '\'':
              val = 39;
              goto LABEL_44;
            case '0':
              val = 0;
              goto LABEL_44;
            case '\\':
              val = 92;
              goto LABEL_44;
            case 'a':
              val = 7;
              goto LABEL_44;
            case 'b':
              val = 8;
              goto LABEL_44;
            case 'f':
              val = 12;
              goto LABEL_44;
            case 'n':
              val = 10;
              goto LABEL_44;
            case 'r':
              val = 13;
              goto LABEL_44;
            case 't':
              val = 9;
              goto LABEL_44;
            case 'v':
              val = 11;
LABEL_44:
              sqvector<char>::push_back(this: (sqvector<char> *)&val, &val);
              v28 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
              if ( v28 > 255 )
                (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
              ++*(_DWORD *)(a2 + 20);
              *(_BYTE *)(a2 + 44) = v28 != 0 ? v28 : 0;
              break;
            case 'x':
              v21 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
              if ( v21 > 255 )
                (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
              ++*(_DWORD *)(a2 + 20);
              v22 = v21 != 0 ? v21 : 0;
              *(_BYTE *)(a2 + 44) = v22;
              if ( isxdigit(c: v22) == 0 )
                (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(
                  a1: *(_DWORD *)(a2 + 68),
                  a2: "hexadecimal number expected");
              v46 = *(unsigned __int8 *)(a2 + 44);
              n = 0;
              if ( isxdigit(c: v46) != 0 )
              {
                do
                {
                  if ( n >= 4 )
                    break;
                  v23 = n;
                  v24 = *(int (__cdecl **)(_DWORD))(a2 + 36);
                  temp[n] = *(_BYTE *)(a2 + 44);
                  n = v23 + 1;
                  v25 = v24(a1: *(_DWORD *)(a2 + 40));
                  if ( v25 > 255 )
                    (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(
                      a1: *(_DWORD *)(a2 + 68),
                      a2: "Invalid character");
                  ++*(_DWORD *)(a2 + 20);
                  v26 = v25 != 0 ? v25 : 0;
                  *(_BYTE *)(a2 + 44) = v26;
                }
                while ( isxdigit(c: v26) != 0 );
              }
              temp[n] = 0;
              val = strtoul(nptr: temp, endptr: &sTemp, ibase: 16);
              sqvector<char>::push_back(this: v27, &val);
              break;
            default:
              (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(
                a1: *(_DWORD *)(a2 + 68),
                a2: "unrecognised escaper char");
              break;
          }
        }
      }
      else
      {
        v7 = *(_DWORD *)(a2 + 56);
        if ( *(_DWORD *)(a2 + 60) <= v7 )
        {
          v8 = 2 * v7;
          if ( 2 * v7 == 0 )
            v8 = 4;
          v9 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *v4, a3: v8);
          v6 = val;
          *v4 = v9;
          *(_DWORD *)(a2 + 60) = v8;
        }
        v10 = *(_DWORD *)(a2 + 56);
        v11 = (char *)*v4 + v10 == nullptr;
        v12 = (char *)*v4 + v10;
        *(_DWORD *)(a2 + 56) = v10 + 1;
        if ( !v11 )
          *v12 = v6;
        v13 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v13 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        ++*(_DWORD *)(a2 + 20);
        *(_BYTE *)(a2 + 44) = v13 != 0 ? v13 : 0;
      }
      if ( *(unsigned __int8 *)(a2 + 44) == ndelim )
        goto LABEL_70;
    }
    (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "unfinished string");
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004CB20
// Name: void LexHexadecimal(char const __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall LexHexadecimal(const char *s@<eax>, unsigned int *res@<edi>)
{
  const char *v2; // esi
  char v3; // al
  unsigned int v4; // eax

  v2 = s;
  *res = 0;
  v3 = *s;
  if ( v3 != 0 )
  {
    while ( isdigit(c: v3) == 0 )
    {
      if ( isxdigit(c: *v2) != 0 )
      {
        v4 = toupper(c: *v2) + 16 * *res - 55;
        goto LABEL_6;
      }
LABEL_7:
      v3 = *v2;
      if ( *v2 == 0 )
        return;
    }
    v4 = *v2 + 16 * *res - 48;
LABEL_6:
    ++v2;
    *res = v4;
    goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CB80
// Name: private: int SQLexer::ReadNumber(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall SQLexer::ReadNumber@<eax>(SQLexer *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int (__cdecl *v3)(int); // edx
  int v4; // edi
  int v5; // ebx
  unsigned __int8 v6; // dl
  bool v7; // zf
  unsigned __int8 v8; // dl
  unsigned int v9; // eax
  unsigned int v10; // ebx
  void *v11; // eax
  int v12; // ecx
  int v13; // eax
  unsigned __int8 *v14; // eax
  int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // ebx
  int v18; // ecx
  int v19; // eax
  _BYTE *v20; // eax
  int v21; // ebx
  unsigned __int8 v22; // al
  unsigned int v23; // eax
  unsigned int v24; // ebx
  int v25; // ecx
  int v26; // eax
  unsigned __int8 *v27; // eax
  int v28; // ebx
  unsigned __int8 v29; // al
  unsigned int v30; // eax
  unsigned int v31; // ebx
  int v32; // ecx
  int v33; // eax
  _BYTE *v34; // eax
  unsigned __int8 v35; // al
  int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ebx
  int v39; // ecx
  int v40; // eax
  unsigned __int8 *v41; // eax
  int v42; // ebx
  unsigned __int8 v43; // al
  unsigned __int8 v44; // dl
  unsigned int v45; // eax
  unsigned int v46; // ebx
  void *v47; // eax
  int v48; // ecx
  int v49; // eax
  unsigned __int8 *v50; // eax
  int v51; // ebx
  unsigned int v52; // eax
  unsigned int v53; // ebx
  int v54; // ecx
  int v55; // eax
  unsigned __int8 *v56; // eax
  int v57; // ebx
  int result; // eax
  char *v59; // edx
  int v60; // eax
  char i; // cl
  char *v62; // ecx
  char j; // al
  int v64; // [esp-4h] [ebp-18h]
  char *sTemp; // [esp+8h] [ebp-Ch] BYREF
  int firstchar; // [esp+Ch] [ebp-8h]
  unsigned __int8 v67; // [esp+13h] [ebp-1h]

  v2 = *(unsigned __int8 *)(a2 + 44);
  *(_DWORD *)(a2 + 56) = 0;
  v3 = *(int (__cdecl **)(int))(a2 + 36);
  v64 = *(_DWORD *)(a2 + 40);
  v4 = 1;
  firstchar = v2;
  v5 = v3(a1: v64);
  if ( v5 > 255 )
    (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
  ++*(_DWORD *)(a2 + 20);
  v6 = v5 != 0 ? v5 : 0;
  v7 = firstchar == 48;
  *(_BYTE *)(a2 + 44) = v6;
  if ( !v7 || toupper(c: v6) != 88 && (unsigned int)*(unsigned __int8 *)(a2 + 44) - 48 > 7 )
  {
    v30 = *(_DWORD *)(a2 + 56);
    if ( *(_DWORD *)(a2 + 60) <= v30 )
    {
      v31 = 2 * v30;
      if ( 2 * v30 == 0 )
        v31 = 4;
      *(_DWORD *)(a2 + 52) = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 52), a3: v31);
      *(_DWORD *)(a2 + 60) = v31;
    }
    v32 = *(_DWORD *)(a2 + 56);
    v33 = *(_DWORD *)(a2 + 52);
    v7 = v32 + v33 == 0;
    v34 = (_BYTE *)(v32 + v33);
    *(_DWORD *)(a2 + 56) = v32 + 1;
    if ( !v7 )
      *v34 = firstchar;
    while ( 1 )
    {
      v35 = *(_BYTE *)(a2 + 44);
      if ( v35 == 46 )
        goto LABEL_52;
      if ( isdigit(c: v35) == 0 )
      {
        v36 = *(unsigned __int8 *)(a2 + 44);
        if ( v36 != 101 && v36 != 69 )
          goto LABEL_20;
      }
      v35 = *(_BYTE *)(a2 + 44);
      if ( v35 == 46 )
LABEL_52:
        v4 = 2;
      if ( v35 == 101 || v35 == 69 )
      {
        if ( v4 != 2 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "invalid numeric format");
        v37 = *(_DWORD *)(a2 + 56);
        v4 = 4;
        v67 = *(_BYTE *)(a2 + 44);
        if ( *(_DWORD *)(a2 + 60) <= v37 )
        {
          v38 = 2 * v37;
          if ( 2 * v37 == 0 )
            v38 = 4;
          *(_DWORD *)(a2 + 52) = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 52), a3: v38);
          *(_DWORD *)(a2 + 60) = v38;
        }
        v39 = *(_DWORD *)(a2 + 56);
        v40 = *(_DWORD *)(a2 + 52);
        v7 = v39 + v40 == 0;
        v41 = (unsigned __int8 *)(v39 + v40);
        *(_DWORD *)(a2 + 56) = v39 + 1;
        if ( !v7 )
          *v41 = v67;
        v42 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v42 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        ++*(_DWORD *)(a2 + 20);
        v43 = v42 != 0 ? v42 : 0;
        v44 = v43;
        *(_BYTE *)(a2 + 44) = v43;
        v67 = v43;
        if ( v43 == 43 || v43 == 45 )
        {
          v45 = *(_DWORD *)(a2 + 56);
          if ( *(_DWORD *)(a2 + 60) <= v45 )
          {
            v46 = 2 * v45;
            if ( 2 * v45 == 0 )
              v46 = 4;
            v47 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 52), a3: v46);
            v44 = v67;
            *(_DWORD *)(a2 + 52) = v47;
            *(_DWORD *)(a2 + 60) = v46;
          }
          v48 = *(_DWORD *)(a2 + 56);
          v49 = *(_DWORD *)(a2 + 52);
          v7 = v48 + v49 == 0;
          v50 = (unsigned __int8 *)(v48 + v49);
          *(_DWORD *)(a2 + 56) = v48 + 1;
          if ( !v7 )
            *v50 = v44;
          v51 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
          if ( v51 > 255 )
            (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
          ++*(_DWORD *)(a2 + 20);
          *(_BYTE *)(a2 + 44) = v51 != 0 ? v51 : 0;
        }
        if ( isdigit(c: *(unsigned __int8 *)(a2 + 44)) == 0 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "exponent expected");
      }
      v52 = *(_DWORD *)(a2 + 56);
      v67 = *(_BYTE *)(a2 + 44);
      if ( *(_DWORD *)(a2 + 60) <= v52 )
      {
        v53 = 2 * v52;
        if ( 2 * v52 == 0 )
          v53 = 4;
        *(_DWORD *)(a2 + 52) = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 52), a3: v53);
        *(_DWORD *)(a2 + 60) = v53;
      }
      v54 = *(_DWORD *)(a2 + 56);
      v55 = *(_DWORD *)(a2 + 52);
      v7 = v54 + v55 == 0;
      v56 = (unsigned __int8 *)(v54 + v55);
      *(_DWORD *)(a2 + 56) = v54 + 1;
      if ( !v7 )
        *v56 = v67;
      v57 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
      if ( v57 > 255 )
        (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
      ++*(_DWORD *)(a2 + 20);
      *(_BYTE *)(a2 + 44) = v57 != 0 ? v57 : 0;
    }
  }
  if ( (unsigned int)*(unsigned __int8 *)(a2 + 44) - 48 > 7 )
  {
    v21 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
    if ( v21 > 255 )
      (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
    ++*(_DWORD *)(a2 + 20);
    v22 = v21 != 0 ? v21 : 0;
    *(_BYTE *)(a2 + 44) = v22;
    v4 = 3;
    if ( isxdigit(c: v22) != 0 )
    {
      do
      {
        v23 = *(_DWORD *)(a2 + 56);
        v67 = *(_BYTE *)(a2 + 44);
        if ( *(_DWORD *)(a2 + 60) <= v23 )
        {
          v24 = 2 * v23;
          if ( 2 * v23 == 0 )
            v24 = 4;
          *(_DWORD *)(a2 + 52) = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 52), a3: v24);
          *(_DWORD *)(a2 + 60) = v24;
        }
        v25 = *(_DWORD *)(a2 + 56);
        v26 = *(_DWORD *)(a2 + 52);
        v7 = v25 + v26 == 0;
        v27 = (unsigned __int8 *)(v25 + v26);
        *(_DWORD *)(a2 + 56) = v25 + 1;
        if ( !v7 )
          *v27 = v67;
        v28 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
        if ( v28 > 255 )
          (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
        ++*(_DWORD *)(a2 + 20);
        v29 = v28 != 0 ? v28 : 0;
        *(_BYTE *)(a2 + 44) = v29;
      }
      while ( isxdigit(c: v29) != 0 );
    }
    if ( *(_DWORD *)(a2 + 56) > 8u )
      (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(
        a1: *(_DWORD *)(a2 + 68),
        a2: "too many digits for an Hex number");
  }
  else
  {
    v4 = 5;
    while ( 1 )
    {
      v67 = *(_BYTE *)(a2 + 44);
      v8 = v67;
      if ( (unsigned int)v67 - 48 > 7 )
        break;
      v9 = *(_DWORD *)(a2 + 56);
      if ( *(_DWORD *)(a2 + 60) <= v9 )
      {
        v10 = 2 * v9;
        if ( 2 * v9 == 0 )
          v10 = 4;
        v11 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 52), a3: v10);
        v8 = v67;
        *(_DWORD *)(a2 + 52) = v11;
        *(_DWORD *)(a2 + 60) = v10;
      }
      v12 = *(_DWORD *)(a2 + 56);
      v13 = *(_DWORD *)(a2 + 52);
      v7 = v12 + v13 == 0;
      v14 = (unsigned __int8 *)(v12 + v13);
      *(_DWORD *)(a2 + 56) = v12 + 1;
      if ( !v7 )
        *v14 = v8;
      v15 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
      if ( v15 > 255 )
        (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
      ++*(_DWORD *)(a2 + 20);
      *(_BYTE *)(a2 + 44) = v15 != 0 ? v15 : 0;
    }
    if ( isdigit(c: *(unsigned __int8 *)(a2 + 44)) != 0 )
      (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "invalid octal number");
  }
LABEL_20:
  v16 = *(_DWORD *)(a2 + 56);
  if ( *(_DWORD *)(a2 + 60) <= v16 )
  {
    v17 = 2 * v16;
    if ( 2 * v16 == 0 )
      v17 = 4;
    *(_DWORD *)(a2 + 52) = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 52), a3: v17);
    *(_DWORD *)(a2 + 60) = v17;
  }
  v18 = *(_DWORD *)(a2 + 56);
  v19 = *(_DWORD *)(a2 + 52);
  v7 = v18 + v19 == 0;
  v20 = (_BYTE *)(v18 + v19);
  *(_DWORD *)(a2 + 56) = v18 + 1;
  if ( !v7 )
    *v20 = 0;
  switch ( v4 )
  {
    case 1:
      v59 = *(char **)(a2 + 52);
      v60 = 0;
      *(_DWORD *)(a2 + 28) = 0;
      for ( i = *v59; *v59 != 0; i = *v59 )
      {
        v60 = i + 10 * v60 - 48;
        ++v59;
        *(_DWORD *)(a2 + 28) = v60;
      }
      result = 260;
      break;
    case 2:
    case 4:
      *(float *)(a2 + 32) = strtod(nptr: (const char *)*(_DWORD *)(a2 + 52), endptr: &sTemp);
      result = 261;
      break;
    case 3:
      LexHexadecimal(s: *(const char **)(a2 + 52), res: (unsigned int *)(a2 + 28));
      result = 260;
      break;
    case 5:
      v62 = *(char **)(a2 + 52);
      *(_DWORD *)(a2 + 28) = 0;
      for ( j = *v62; *v62 != 0; j = *v62 )
      {
        if ( (unsigned int)(j - 48) <= 7 )
        {
          *(_DWORD *)(a2 + 28) = j + 8 * *(_DWORD *)(a2 + 28) - 48;
          ++v62;
        }
      }
      result = 260;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004D110
// Name: private: int SQLexer::ReadID(void)
// Source: json
//------------------------------------------------------------------------------
int *__usercall SQLexer::ReadID@<eax>(SQLexer *this@<ecx>, int a2@<esi>)
{
  unsigned int v2; // eax
  char v3; // bl
  unsigned int v4; // edi
  int v5; // ecx
  int v6; // eax
  bool v7; // zf
  _BYTE *v8; // eax
  int v9; // ebx
  unsigned __int8 v10; // cl
  unsigned int v11; // eax
  unsigned int v12; // edi
  int v13; // ecx
  int v14; // eax
  _BYTE *v15; // eax
  int *result; // eax

  *(_DWORD *)(a2 + 56) = 0;
  do
  {
    v2 = *(_DWORD *)(a2 + 56);
    v3 = *(_BYTE *)(a2 + 44);
    if ( *(_DWORD *)(a2 + 60) <= v2 )
    {
      v4 = 2 * v2;
      if ( 2 * v2 == 0 )
        v4 = 4;
      *(_DWORD *)(a2 + 52) = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 52), a3: v4);
      *(_DWORD *)(a2 + 60) = v4;
    }
    v5 = *(_DWORD *)(a2 + 56);
    v6 = *(_DWORD *)(a2 + 52);
    v7 = v5 + v6 == 0;
    v8 = (_BYTE *)(v5 + v6);
    *(_DWORD *)(a2 + 56) = v5 + 1;
    if ( !v7 )
      *v8 = v3;
    v9 = (*(int (__cdecl **)(_DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40));
    if ( v9 > 255 )
      (*(void (__cdecl **)(_DWORD, const char *))(a2 + 64))(a1: *(_DWORD *)(a2 + 68), a2: "Invalid character");
    ++*(_DWORD *)(a2 + 20);
    v10 = v9 != 0 ? v9 : 0;
    *(_BYTE *)(a2 + 44) = v10;
  }
  while ( isalnum(c: v10) != 0 || *(_BYTE *)(a2 + 44) == 95 );
  v11 = *(_DWORD *)(a2 + 56);
  if ( *(_DWORD *)(a2 + 60) <= v11 )
  {
    v12 = 2 * v11;
    if ( 2 * v11 == 0 )
      v12 = 4;
    *(_DWORD *)(a2 + 52) = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 52), a3: v12);
    *(_DWORD *)(a2 + 60) = v12;
  }
  v13 = *(_DWORD *)(a2 + 56);
  v14 = *(_DWORD *)(a2 + 52);
  v7 = v13 + v14 == 0;
  v15 = (_BYTE *)(v13 + v14);
  *(_DWORD *)(a2 + 56) = v13 + 1;
  if ( !v7 )
    *v15 = 0;
  result = SQLexer::GetIDType(s: *(char **)(a2 + 52), this: (SQLexer *)a2);
  if ( result == (int *)258 || result == (int *)310 )
    *(_DWORD *)(a2 + 24) = *(_DWORD *)(a2 + 52);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004D210
// Name: public: char __near & sqvector<char>::push_back(char const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__userpurge sqvector<char>::push_back@<eax>(sqvector<char> *this@<ecx>, int a2@<esi>, const char *val)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // eax
  int v6; // ecx
  bool v7; // zf
  char *result; // eax

  v3 = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a2 + 8) <= v3 )
  {
    v4 = 2 * v3;
    if ( 2 * v3 == 0 )
      v4 = 4;
    v5 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)a2, a3: v4);
    *(_DWORD *)(a2 + 8) = v4;
    *(_DWORD *)a2 = v5;
  }
  v6 = *(_DWORD *)(a2 + 4);
  v7 = v6 + *(_DWORD *)a2 == 0;
  result = (char *)(v6 + *(_DWORD *)a2);
  *(_DWORD *)(a2 + 4) = v6 + 1;
  if ( v7 )
    return nullptr;
  *result = *val;
  return result;
}
