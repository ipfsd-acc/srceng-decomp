// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/predictioncopy.cpp
// Functions: 43
// ============================================================

#include "game\shared\predictioncopy.h"

//------------------------------------------------------------------------------
// Address: 0x10047600
// Name: struct datamap_t __near * DataMapInit<struct flexsettinghdr_t>(struct flexsettinghdr_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<flexsettinghdr_t>()
{
  if ( (_S7_4 & 1) == 0 )
  {
    _S7_4 |= 1u;
    nameHolder_3.m_pszBase = "flexsettinghdr_t";
    nameHolder_3.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_3.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_3.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_3.m_Names.m_Size = 0;
    nameHolder_3.m_Names.m_pElements = nullptr;
    nameHolder_3.m_nLenBase = 16;
    atexit(func: DataMapInit_flexsettinghdr_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  flexsettinghdr_t::m_DataMap.baseMap = nullptr;
  flexsettinghdr_t::m_DataMap.dataNumFields = 12;
  flexsettinghdr_t::m_DataMap.dataDesc = &dataDesc_3[1];
  return &flexsettinghdr_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10047680
// Name: struct datamap_t __near * DataMapInit<struct flexsetting_t>(struct flexsetting_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<flexsetting_t>()
{
  if ( (_S8_3 & 1) == 0 )
  {
    _S8_3 |= 1u;
    nameHolder_4.m_pszBase = "flexsetting_t";
    nameHolder_4.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_4.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_4.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_4.m_Names.m_Size = 0;
    nameHolder_4.m_Names.m_pElements = nullptr;
    nameHolder_4.m_nLenBase = 13;
    atexit(func: DataMapInit_flexsetting_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  flexsetting_t::m_DataMap.baseMap = nullptr;
  flexsetting_t::m_DataMap.dataNumFields = 6;
  flexsetting_t::m_DataMap.dataDesc = &dataDesc_4[1];
  return &flexsetting_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10047700
// Name: struct datamap_t __near * DataMapInit<struct flexweight_t>(struct flexweight_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<flexweight_t>()
{
  if ( (_S9_1 & 1) == 0 )
  {
    _S9_1 |= 1u;
    nameHolder_5.m_pszBase = "flexweight_t";
    nameHolder_5.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_5.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_5.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_5.m_Names.m_Size = 0;
    nameHolder_5.m_Names.m_pElements = nullptr;
    nameHolder_5.m_nLenBase = 12;
    atexit(func: DataMapInit_flexweight_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  flexweight_t::m_DataMap.baseMap = nullptr;
  flexweight_t::m_DataMap.dataNumFields = 3;
  flexweight_t::m_DataMap.dataDesc = &dataDesc_5[1];
  return &flexweight_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100C5230
// Name: struct datamap_t __near * DataMapInit<struct CompiledCaptionHeader_t>(struct CompiledCaptionHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CompiledCaptionHeader_t>()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    nameHolder_10.m_pszBase = "CompiledCaptionHeader_t";
    nameHolder_10.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_10.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_10.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_10.m_Names.m_Size = 0;
    nameHolder_10.m_Names.m_pElements = nullptr;
    nameHolder_10.m_nLenBase = 23;
    atexit(func: DataMapInit_CompiledCaptionHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CompiledCaptionHeader_t::m_DataMap.baseMap = nullptr;
  CompiledCaptionHeader_t::m_DataMap.dataNumFields = 6;
  CompiledCaptionHeader_t::m_DataMap.dataDesc = &dataDesc_10[1];
  return &CompiledCaptionHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100C52B0
// Name: struct datamap_t __near * DataMapInit<struct CaptionLookup_t>(struct CaptionLookup_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CaptionLookup_t>()
{
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    nameHolder_11.m_pszBase = "CaptionLookup_t";
    nameHolder_11.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_11.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_11.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_11.m_Names.m_Size = 0;
    nameHolder_11.m_Names.m_pElements = nullptr;
    nameHolder_11.m_nLenBase = 15;
    atexit(func: DataMapInit_CaptionLookup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CaptionLookup_t::m_DataMap.baseMap = nullptr;
  CaptionLookup_t::m_DataMap.dataNumFields = 4;
  CaptionLookup_t::m_DataMap.dataDesc = &dataDesc_11[1];
  return &CaptionLookup_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10144E00
// Name: struct datamap_t __near * DataMapInit<struct PhysBlockHeader_t>(struct PhysBlockHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<PhysBlockHeader_t>()
{
  if ( (_S5_109 & 1) == 0 )
  {
    _S5_109 |= 1u;
    nameHolder_14.m_pszBase = "PhysBlockHeader_t";
    nameHolder_14.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_14.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_14.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_14.m_Names.m_Size = 0;
    nameHolder_14.m_Names.m_pElements = nullptr;
    nameHolder_14.m_nLenBase = 17;
    atexit(func: DataMapInit_PhysBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  PhysBlockHeader_t::m_DataMap.baseMap = nullptr;
  PhysBlockHeader_t::m_DataMap.dataNumFields = 2;
  PhysBlockHeader_t::m_DataMap.dataDesc = &dataDesc_13[1];
  return &PhysBlockHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10144E80
// Name: struct datamap_t __near * DataMapInit<struct PhysObjectHeader_t>(struct PhysObjectHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<PhysObjectHeader_t>()
{
  if ( (_S6_35 & 1) == 0 )
  {
    _S6_35 |= 1u;
    nameHolder_15.m_pszBase = "PhysObjectHeader_t";
    nameHolder_15.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_15.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_15.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_15.m_Names.m_Size = 0;
    nameHolder_15.m_Names.m_pElements = nullptr;
    nameHolder_15.m_nLenBase = 18;
    atexit(func: DataMapInit_PhysObjectHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  PhysObjectHeader_t::m_DataMap.baseMap = nullptr;
  PhysObjectHeader_t::m_DataMap.dataNumFields = 9;
  PhysObjectHeader_t::m_DataMap.dataDesc = &dataDesc_14[1];
  return &PhysObjectHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10153460
// Name: private: void CPredictionCopy::OutputFieldDescription(struct datamap_t const __near *,struct typedescription_t const __near *,enum CPredictionCopy::difftype_t,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CPredictionCopy::OutputFieldDescription(
        CPredictionCopy *this,
        const datamap_t *pCurrentMap,
        const typedescription_t *pField,
        CPredictionCopy::difftype_t dt,
        char *fmt,
        ...)
{
  const char *fieldName; // ebx
  __int16 flags; // si
  char pDest[4096]; // [esp+0h] [ebp-1004h] BYREF
  const char *dataClassName; // [esp+1000h] [ebp-4h]
  va_list params; // [esp+1020h] [ebp+1Ch] BYREF

  va_start(params, fmt);
  if ( this->m_FieldCompareFunc != nullptr )
  {
    fieldName = "empty";
    flags = 0;
    dataClassName = "empty";
    if ( pField != nullptr )
    {
      fieldName = pField->fieldName;
      flags = pField->flags;
      if ( fieldName == nullptr )
        fieldName = "NULL";
      dataClassName = pCurrentMap->dataClassName;
    }
    V_vsnprintf(pDest, maxLen: 0x1000u, pFormat: fmt, params);
    this->m_FieldCompareFunc(
      a1: dataClassName,
      a2: fieldName,
      a3: g_FieldTypes[pField->fieldType],
      a4: flags & 0x100,
      a5: (flags & 0x400) != 0,
      a6: dt != IDENTICAL,
      a7: dt == WITHINTOLERANCE,
      a8: pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153520
// Name: private: void CPredictionCopy::WatchMsg(struct typedescription_t const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CPredictionCopy::WatchMsg(CPredictionCopy *this, const typedescription_t *pField, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 0x1000u, pFormat: fmt, params);
  _Msg(a1: "%i %s %s : %s\n", *(_DWORD *)(gpGlobals.m_Index + 24), this->m_pOperation, pField->fieldName, pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10153580
// Name: CompareFlattenedOffsets
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareFlattenedOffsets(_DWORD *pv1, _DWORD *pv2)
{
  int v2; // eax
  int v3; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // cx

  v2 = pv1[12];
  v3 = pv2[12];
  if ( v2 < v3 )
    return -1;
  if ( v2 > v3 )
    return 1;
  v5 = *((_WORD *)pv1 + 28);
  v6 = *((_WORD *)pv2 + 28);
  if ( v6 > v5 )
    return -1;
  return v6 < v5;
}

//------------------------------------------------------------------------------
// Address: 0x10153670
// Name: private: void CPredictionCopy::DumpWatchField(struct typedescription_t const __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictionCopy::DumpWatchField(
        CPredictionCopy *this,
        const typedescription_t *pField,
        const unsigned __int8 *outvalue,
        int count)
{
  const char *v5; // eax
  const struct model_t *v6; // eax
  const char *v7; // eax
  unsigned int v8; // ecx
  C_BaseEntity **v9; // eax
  C_BaseEntity *v10; // ebx
  char *Classname; // eax
  type_info *v12; // eax
  unsigned int v13; // edx
  IHandleEntity *m_pEntity; // ecx
  char out[512]; // [esp+2Ch] [ebp-200h] BYREF

  switch ( pField->fieldType )
  {
    case FIELD_FLOAT:
      CPredictionCopy::WatchMsg(this, pField, fmt: "float (%f)", *(float *)outvalue);
      break;
    case FIELD_STRING:
      CPredictionCopy::WatchMsg(this, pField, fmt: "string (%s)", (const char *)outvalue);
      break;
    case FIELD_VECTOR:
      CPredictionCopy::WatchMsg(
        this,
        pField,
        fmt: "vector (%f %f %f)",
        *(float *)outvalue,
        *((float *)outvalue + 1),
        *((float *)outvalue + 2));
      break;
    case FIELD_QUATERNION:
      CPredictionCopy::WatchMsg(
        this,
        pField,
        fmt: "quaternion (%f %f %f %f)",
        *(float *)outvalue,
        *((float *)outvalue + 1),
        *((float *)outvalue + 2),
        *((float *)outvalue + 3));
      break;
    case FIELD_INTEGER:
      if ( (pField->flags & 0x800) != 0
        && (v6 = modelinfo->GetModel(this: modelinfo, a2: *(_DWORD *)outvalue)) != nullptr )
      {
        out[0] = 0;
        v7 = modelinfo->GetModelName(this: modelinfo, a2: v6);
        V_FileBase(in: v7, out, maxlen: 512);
        CPredictionCopy::WatchMsg(this, pField, fmt: "integer (%i->%s)", *(_DWORD *)outvalue, out);
      }
      else
      {
        CPredictionCopy::WatchMsg(this, pField, fmt: "integer (%i)", *(_DWORD *)outvalue);
      }
      break;
    case FIELD_BOOLEAN:
      v5 = "true";
      if ( *outvalue == 0 )
        v5 = "false";
      CPredictionCopy::WatchMsg(this, pField, fmt: "bool (%s)", v5);
      break;
    case FIELD_SHORT:
      CPredictionCopy::WatchMsg(this, pField, fmt: "short (%i)", *(__int16 *)outvalue);
      break;
    case FIELD_COLOR32:
      CPredictionCopy::WatchMsg(
        this,
        pField,
        fmt: "color32 (%d %d %d %d)",
        *outvalue,
        outvalue[1],
        outvalue[2],
        outvalue[3]);
      break;
    case FIELD_EHANDLE:
      v8 = *(_DWORD *)outvalue;
      if ( *(_DWORD *)outvalue != -1
        && (v9 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v8],
            g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber == HIWORD(v8))
        && (v10 = *v9, *v9 != nullptr) )
      {
        Classname = C_BaseEntity::GetClassname(this: *v9);
        if ( *Classname == 0 )
        {
          v12 = (type_info *)__RTtypeid(inptr: v10);
          Classname = (char *)type_info::name(this: v12, __ptype_info_node: &__type_info_root_node);
        }
        v13 = *(_DWORD *)outvalue;
        if ( *(_DWORD *)outvalue == -1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
        {
          m_pEntity = nullptr;
        }
        else
        {
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
        }
        CPredictionCopy::WatchMsg(this, pField, fmt: "EHandle (0x%p->%s)", m_pEntity, Classname);
      }
      else
      {
        CPredictionCopy::WatchMsg(this, pField, fmt: "EHandle (NULL)");
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153960
// Name: BuildPackedFlattenedOffsets
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall BuildPackedFlattenedOffsets@<eax>(flattenedoffsets_t *a1@<edi>, int nStartOffset)
{
  int v2; // eax
  int v3; // ebx
  unsigned int v4; // esi
  typedescription_t *v5; // eax
  int i; // [esp+8h] [ebp-4h]

  v2 = nStartOffset;
  v3 = 0;
  v4 = nStartOffset;
  i = 0;
  if ( a1->m_Flattened.m_Size > 0 )
  {
    do
    {
      v5 = &a1->m_Flattened.m_Memory.m_pMemory[v3];
      switch ( v5->fieldType )
      {
        case FIELD_FLOAT:
        case FIELD_VECTOR:
        case FIELD_QUATERNION:
        case FIELD_INTEGER:
        case FIELD_COLOR32:
        case FIELD_EHANDLE:
        case FIELD_VMATRIX:
        case FIELD_VECTOR4D:
          v4 = (v4 + 3) & 0xFFFFFFFC;
          goto $LN2_22;
        case FIELD_STRING:
        case FIELD_BOOLEAN:
        case FIELD_CHARACTER:
          goto $LN2_22;
        case FIELD_SHORT:
          v4 = (v4 + 1) & 0xFFFFFFFE;
$LN2_22:
          v5->flatOffset[1] = v4;
          v4 += v5->fieldSizeInBytes;
          break;
        case FIELD_EMBEDDED:
          _Error(this: (ISceneTokenProcessor *)&stru_10488610, a2: v5->fieldName);
          break;
        default:
          break;
      }
      ++v3;
      ++i;
    }
    while ( i < a1->m_Flattened.m_Size );
    v2 = nStartOffset;
  }
  a1->m_nPackedStartOffset = v2;
  a1->m_nPackedSize = v4 - v2;
  return (v4 + 3) & 0xFFFFFFFC;
}

//------------------------------------------------------------------------------
// Address: 0x10153A20
// Name: DescribeRuns
// Source: json
//------------------------------------------------------------------------------
void __fastcall DescribeRuns(const datamap_t *dmap, int nPredictionCopyType, int packType)
{
  int v3; // ebx
  datamapinfo_t *v4; // edi
  const tokenset_t<int> *v5; // eax
  const char *name; // eax
  const tokenset_t<int> *v7; // ecx
  const char *v8; // ecx
  int v9; // esi
  datarun_t *v10; // eax
  datamapinfo_t *v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+14h] [ebp-4h]

  v3 = packType;
  v4 = &dmap->m_pOptimizedDataMap->m_Info[nPredictionCopyType];
  v11 = v4;
  v5 = s_PredPackType;
  if ( "Normal" != nullptr )
  {
    while ( v5->token != packType )
    {
      ++v5;
      if ( v5->name == nullptr )
        goto LABEL_4;
    }
    name = v5->name;
  }
  else
  {
LABEL_4:
    name = `tokenset_t<int>::GetNameByToken'::`2'::unknown;
  }
  v7 = s_PredCopyType;
  if ( "Non-Sendtable" != nullptr )
  {
    while ( v7->token != nPredictionCopyType )
    {
      ++v7;
      if ( v7->name == nullptr )
        goto LABEL_8;
    }
    v8 = v7->name;
  }
  else
  {
LABEL_8:
    v8 = `tokenset_t<int>::GetNameByToken'::`2'::unknown;
  }
  _Msg(a1: "   Runs for copy type: %s, packing: %s\n", v8, name);
  v9 = 0;
  if ( v4->m_CopyRuns.m_vecRuns.m_Size > 0 )
  {
    v12 = 0;
    while ( 1 )
    {
      v10 = &v4->m_CopyRuns.m_vecRuns.m_Memory.m_pMemory[v12];
      _Msg(
        a1: "     %5d:  %5d -> %5d (%5d bytes): %s to %s\n",
        v9,
        v10->m_nStartOffset[v3],
        v10->m_nStartOffset[v3] + v10->m_nLength,
        v10->m_nLength,
        v4->m_Flat.m_Flattened.m_Memory.m_pMemory[v10->m_nStartFlatField].fieldName,
        v4->m_Flat.m_Flattened.m_Memory.m_pMemory[v10->m_nEndFlatField].fieldName);
      v4 = v11;
      ++v12;
      if ( ++v9 >= v11->m_CopyRuns.m_vecRuns.m_Size )
        break;
      v3 = packType;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153B10
// Name: DescribeFlattenedList
// Source: json
//------------------------------------------------------------------------------
void __cdecl DescribeFlattenedList(const datamap_t *dmap, int nPredictionCopyType, int packType)
{
  int v3; // esi
  const tokenset_t<int> *v4; // eax
  const char *name; // eax
  const tokenset_t<int> *v6; // ecx
  int v7; // ebx
  const char *v8; // ecx
  datamapinfo_t *v9; // eax
  int v10; // ecx
  int v11; // ebx
  int v12; // edi
  int v13; // eax
  int v14; // ecx
  const flattenedoffsets_t *list; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  int nRuns; // [esp+1Ch] [ebp-Ch]
  int nBytesInRuns; // [esp+20h] [ebp-8h]
  int nCurrentRunStartOffset; // [esp+24h] [ebp-4h]

  v3 = 0;
  v4 = s_PredPackType;
  if ( "Normal" != nullptr )
  {
    while ( v4->token != packType )
    {
      ++v4;
      if ( v4->name == nullptr )
        goto LABEL_4;
    }
    name = v4->name;
  }
  else
  {
LABEL_4:
    name = `tokenset_t<int>::GetNameByToken'::`2'::unknown;
  }
  v6 = s_PredCopyType;
  if ( "Non-Sendtable" != nullptr )
  {
    while ( 1 )
    {
      v7 = nPredictionCopyType;
      if ( v6->token == nPredictionCopyType )
        break;
      ++v6;
      if ( v6->name == nullptr )
        goto LABEL_8;
    }
    v8 = v6->name;
  }
  else
  {
LABEL_8:
    v7 = nPredictionCopyType;
    v8 = `tokenset_t<int>::GetNameByToken'::`2'::unknown;
  }
  _Msg(a1: "->Sorted %s for copy type: %s, packing: %s\n", dmap->dataClassName, v8, name);
  v9 = &dmap->m_pOptimizedDataMap->m_Info[v7];
  v10 = 0;
  nCurrentRunStartOffset = 0;
  nRuns = 0;
  nBytesInRuns = 0;
  list = &v9->m_Flat;
  i = 0;
  if ( v9->m_Flat.m_Flattened.m_Size > 0 )
  {
    while ( 1 )
    {
      v11 = (int)&v9->m_Flat.m_Flattened.m_Memory.m_pMemory[v10];
      v12 = *(_DWORD *)(v11 + 4 * packType + 48);
      if ( v10 == 0 )
      {
        v3 = *(_DWORD *)(v11 + 4 * packType + 48);
        nCurrentRunStartOffset = v3;
      }
      if ( *(_DWORD *)v11 != 10 )
      {
        if ( v3 != v12 )
        {
          _Msg(a1: "  gap of %d bytes [last run %d]\n", v12 - v3, v3 - nCurrentRunStartOffset);
          ++nRuns;
          nBytesInRuns += v3 - nCurrentRunStartOffset;
          nCurrentRunStartOffset = v12;
        }
        v12 = *(_DWORD *)(v11 + 4 * packType + 48);
        v3 = v12 + *(_DWORD *)(v11 + 32);
      }
      _Msg(
        a1: "group %s [flat %d] [sort %d] %d bytes\n",
        *(const char **)(v11 + 4),
        v12,
        *(_DWORD *)(v11 + 48),
        *(_DWORD *)(v11 + 32));
      if ( ++i >= list->m_Flattened.m_Size )
        break;
      v9 = (datamapinfo_t *)list;
      v10 = i;
    }
    if ( v3 == nCurrentRunStartOffset )
    {
      v14 = nBytesInRuns;
      v13 = nRuns;
    }
    else
    {
      _Msg(a1: "Last run %d\n", v3 - nCurrentRunStartOffset);
      v13 = nRuns + 1;
      v14 = v3 - nCurrentRunStartOffset + nBytesInRuns;
    }
    if ( v13 > 0 )
      _Msg(a1: "%d runs, %d bytes in runs, %f avg bytes per run\n", v13, v14, (float)((float)v14 / (float)v13));
  }
  _Msg(a1: "->\n");
  DescribeRuns(dmap, nPredictionCopyType, packType);
}

//------------------------------------------------------------------------------
// Address: 0x10153CC0
// Name: private: void CPredictionCopy::TransferDataCopyOnly(struct datamap_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictionCopy::TransferDataCopyOnly(CPredictionCopy *this, const datamap_t *dmap)
{
  int v3; // edx
  int v4; // ecx
  _DWORD *v5; // ebx
  int v6; // edi
  int types; // [esp+Ch] [ebp-18h]
  unsigned __int8 *m_pDest; // [esp+10h] [ebp-14h]
  const unsigned __int8 *m_pSrc; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-8h]
  int v12; // [esp+20h] [ebp-4h]

  v3 = this->m_nType + 1;
  v4 = 0;
  types = v3;
  v12 = 1;
  v10 = 0;
  do
  {
    if ( (v3 & v12) != 0 )
    {
      v5 = (datarun_t **)((char *)&dmap->m_pOptimizedDataMap->m_Info[0].m_CopyRuns.m_vecRuns.m_Memory.m_pMemory + v4);
      m_pDest = this->m_pDest;
      m_pSrc = this->m_pSrc;
      if ( *(int *)((char *)&dmap->m_pOptimizedDataMap->m_Info[0].m_CopyRuns.m_vecRuns.m_Size + v4) > 0 )
      {
        v6 = 0;
        v11 = *(int *)((char *)&dmap->m_pOptimizedDataMap->m_Info[0].m_CopyRuns.m_vecRuns.m_Size + v4);
        do
        {
          _V_memcpy(
            dest: &m_pDest[*(_DWORD *)(v6 + *v5 + 4 * this->m_nDestOffsetIndex + 8)],
            src: (unsigned __int8 *)&m_pSrc[*(_DWORD *)(v6 + *v5 + 4 * this->m_nSrcOffsetIndex + 8)],
            count: *(_DWORD *)(*v5 + v6 + 16));
          v6 += 20;
          --v11;
        }
        while ( v11 != 0 );
        v3 = types;
        v4 = v10;
      }
    }
    v4 += 48;
    v10 = v4;
    v12 = __ROL4__(v12, 1);
  }
  while ( v4 < 96 );
}

//------------------------------------------------------------------------------
// Address: 0x10153D60
// Name: private: void CPredictionCopy::TransferDataErrorCheckNoSpew(char const __near *,struct datamap_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictionCopy::TransferDataErrorCheckNoSpew(
        CPredictionCopy *this@<ecx>,
        const char *a2@<edi>,
        const char *pchOperation,
        const datamap_t *dmap)
{
  int v4; // eax
  datamapinfo_t *v5; // eax
  typedescription_t *m_pMemory; // edx
  int m_Size; // eax
  unsigned __int8 *m_pDest; // edx
  const unsigned __int8 *m_pSrc; // ecx
  int v10; // eax
  CPredictionCopy *v11; // ebx
  typedescription_t *v12; // edx
  const char *v13; // ecx
  const char *v14; // eax
  int fieldSize; // esi
  float fieldTolerance; // xmm0_4
  int v17; // edx
  int v18; // ecx
  int v19; // edi
  float *v20; // edx
  int v21; // ecx
  float v22; // xmm4_4
  int v23; // ebx
  float *v24; // edi
  float *v25; // edx
  int v26; // ecx
  float *v27; // edi
  float *v28; // edx
  float v29; // xmm0_4
  int v30; // edx
  float *v31; // edi
  int v32; // ecx
  int v33; // ebx
  float *v34; // ecx
  int v35; // edi
  float *v36; // edx
  int v37; // ebx
  _BYTE *v38; // edi
  _BYTE *v39; // edx
  int v40; // eax
  int v41; // edx
  int v42; // edi
  int v43; // edx
  int v44; // eax
  int v45; // edx
  int v46; // eax
  int v47; // edx
  int v48; // edi
  const char *v49; // edi
  unsigned int v50; // edx
  IHandleEntity *m_pEntity; // ecx
  unsigned int v52; // edx
  IHandleEntity *v53; // eax
  const char *v54; // [esp-Ch] [ebp-48h]
  float v55[4]; // [esp+0h] [ebp-3Ch]
  int v56; // [esp+10h] [ebp-2Ch]
  const unsigned __int8 *v57; // [esp+14h] [ebp-28h]
  unsigned __int8 *v58; // [esp+18h] [ebp-24h]
  typedescription_t *v59; // [esp+1Ch] [ebp-20h]
  int types; // [esp+20h] [ebp-1Ch]
  int v61; // [esp+24h] [ebp-18h]
  int v62; // [esp+28h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-10h]
  int v64; // [esp+30h] [ebp-Ch]
  int v65; // [esp+34h] [ebp-8h]
  CPredictionCopy *v66; // [esp+38h] [ebp-4h]

  v4 = this->m_nType + 1;
  v54 = a2;
  v66 = this;
  types = v4;
  i = 0;
  v62 = 1;
  while ( this->m_nErrorCount == 0 )
  {
    if ( (v4 & v62) != 0 )
    {
      v5 = &dmap->m_pOptimizedDataMap->m_Info[i];
      m_pMemory = v5->m_Flat.m_Flattened.m_Memory.m_pMemory;
      m_Size = v5->m_Flat.m_Flattened.m_Size;
      v59 = m_pMemory;
      m_pDest = v66->m_pDest;
      m_pSrc = v66->m_pSrc;
      v56 = m_Size;
      v58 = m_pDest;
      v57 = m_pSrc;
      v64 = 0;
      if ( m_Size > 0 )
      {
        v10 = v64;
        do
        {
          v11 = v66;
          if ( v66->m_nErrorCount != 0 )
            break;
          v12 = &v59[v10];
          if ( (v12->flags & 0x400) == 0 )
          {
            v13 = (const char *)&v58[v12->flatOffset[v66->m_nDestOffsetIndex]];
            v14 = (const char *)&v57[v12->flatOffset[v66->m_nSrcOffsetIndex]];
            fieldSize = v12->fieldSize;
            switch ( v12->fieldType )
            {
              case FIELD_FLOAT:
                fieldTolerance = v12->fieldTolerance;
                if ( fieldTolerance <= 0.0 )
                {
                  v19 = 0;
                  if ( v12->fieldSize != 0 )
                  {
                    v20 = (float *)&v57[v12->flatOffset[v66->m_nSrcOffsetIndex]];
                    v21 = v13 - v14;
                    do
                    {
                      if ( *(float *)((char *)v20 + v21) != *v20 )
                        goto LABEL_25;
                      ++v19;
                      ++v20;
                    }
                    while ( v19 < fieldSize );
                  }
                }
                else
                {
                  v17 = 0;
                  if ( fieldSize > 0 )
                  {
                    v18 = v13 - v14;
                    do
                    {
                      if ( fieldTolerance < fabs(*(float *)&v14[v18] - *(float *)v14) )
                        goto LABEL_25;
                      ++v17;
                      v14 += 4;
                    }
                    while ( v17 < fieldSize );
                  }
                }
                break;
              case FIELD_STRING:
                if ( _V_strcmp(s1: v13, s2: v14) != 0 )
                  ++v11->m_nErrorCount;
                break;
              case FIELD_VECTOR:
                v22 = v12->fieldTolerance;
                v23 = 0;
                if ( v22 <= 0.0 )
                {
                  if ( v12->fieldSize != 0 )
                  {
                    v27 = (float *)&v57[v12->flatOffset[v66->m_nSrcOffsetIndex]];
                    v28 = (float *)(v13 + 4);
                    v61 = v14 - v13;
                    do
                    {
                      if ( *v27 != *(v28 - 1) || *(float *)((char *)v28 + v61) != *v28 || v27[2] != v28[1] )
                        goto LABEL_43;
                      ++v23;
                      v27 += 3;
                      v28 += 3;
                    }
                    while ( v23 < fieldSize );
                  }
                }
                else if ( v12->fieldSize != 0 )
                {
                  v24 = (float *)&v58[v12->flatOffset[v66->m_nDestOffsetIndex]];
                  v25 = (float *)(v14 + 4);
                  v26 = v13 - v14;
                  do
                  {
                    if ( v22 < fabs(*v24 - *(v25 - 1))
                      || v22 < fabs(*(float *)((char *)v25 + v26) - *v25)
                      || v22 < fabs(v24[2] - v25[1]) )
                    {
                      goto LABEL_43;
                    }
                    ++v23;
                    v25 += 3;
                    v24 += 3;
                  }
                  while ( v23 < fieldSize );
                }
                break;
              case FIELD_QUATERNION:
                v29 = v12->fieldTolerance;
                if ( v29 <= 0.0 )
                {
                  v33 = 0;
                  if ( v12->fieldSize != 0 )
                  {
                    v65 = v13 - v14;
                    v34 = (float *)v14;
LABEL_55:
                    v35 = 0;
                    v36 = v34;
                    while ( *(float *)((char *)v36 + v65) == *v36 )
                    {
                      ++v35;
                      ++v36;
                      if ( v35 >= 4 )
                      {
                        ++v33;
                        v34 += 4;
                        if ( v33 < fieldSize )
                          goto LABEL_55;
                        goto LABEL_11;
                      }
                    }
                    goto LABEL_60;
                  }
                }
                else
                {
                  v30 = 0;
                  if ( fieldSize > 0 )
                  {
                    v31 = (float *)(v14 + 12);
                    v32 = v13 - v14;
                    while ( 1 )
                    {
                      v55[v30] = *(float *)((char *)v31 + v32) - *v31;
                      if ( v29 < fabs(v55[0]) || v29 < fabs(v55[1]) || v29 < fabs(v55[2]) || v29 < fabs(v55[3]) )
                        break;
                      ++v30;
                      v31 += 4;
                      if ( v30 >= fieldSize )
                        goto LABEL_11;
                    }
LABEL_60:
                    v66->m_nErrorCount = 1;
                    break;
                  }
                }
                break;
              case FIELD_INTEGER:
                v43 = 0;
                if ( fieldSize > 0 )
                {
                  v44 = v14 - v13;
                  do
                  {
                    if ( *(_DWORD *)v13 != *(_DWORD *)&v13[v44] )
                      goto LABEL_25;
                    ++v43;
                    v13 += 4;
                  }
                  while ( v43 < fieldSize );
                }
                break;
              case FIELD_BOOLEAN:
                v41 = 0;
                if ( fieldSize > 0 )
                {
                  v42 = v14 - v13;
                  do
                  {
                    if ( *v13 != v13[v42] )
                      goto LABEL_25;
                    ++v41;
                    ++v13;
                  }
                  while ( v41 < fieldSize );
                }
                break;
              case FIELD_SHORT:
                v45 = 0;
                if ( fieldSize > 0 )
                {
                  v46 = v14 - v13;
                  do
                  {
                    if ( *(_WORD *)v13 != *(_WORD *)&v13[v46] )
                      goto LABEL_25;
                    ++v45;
                    v13 += 2;
                  }
                  while ( v45 < fieldSize );
                }
                break;
              case FIELD_CHARACTER:
                v47 = 0;
                if ( fieldSize > 0 )
                {
                  v48 = v14 - v13;
                  while ( *v13 == v13[v48] )
                  {
                    ++v47;
                    ++v13;
                    if ( v47 >= fieldSize )
                      goto LABEL_11;
                  }
LABEL_25:
                  v66->m_nErrorCount = 1;
                }
                break;
              case FIELD_COLOR32:
                v37 = 0;
                if ( v12->fieldSize != 0 )
                {
                  v38 = v14 + 3;
                  v39 = v13 + 1;
                  v40 = v14 - v13;
                  do
                  {
                    if ( *(v39 - 1) != *(v38 - 3) || *v39 != v39[v40] || v39[1] != *(v38 - 1) || v39[2] != *v38 )
                      goto LABEL_43;
                    ++v37;
                    v38 += 4;
                    v39 += 4;
                  }
                  while ( v37 < fieldSize );
                }
                break;
              case FIELD_EMBEDDED:
                _Error(this: (ISceneTokenProcessor *)&stru_1048875C, a2: v54);
                break;
              case FIELD_EHANDLE:
                v61 = 0;
                if ( fieldSize > 0 )
                {
                  v49 = v14;
                  v65 = v13 - v14;
                  while ( 1 )
                  {
                    v50 = *(_DWORD *)&v49[v65];
                    if ( v50 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v50].m_SerialNumber != HIWORD(v50) )
                      m_pEntity = nullptr;
                    else
                      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v50].m_pEntity;
                    v52 = *(_DWORD *)v49;
                    if ( *(_DWORD *)v49 == -1
                      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v52].m_SerialNumber != HIWORD(v52) )
                    {
                      v53 = nullptr;
                    }
                    else
                    {
                      v53 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v52].m_pEntity;
                    }
                    if ( m_pEntity != v53 )
                      break;
                    v49 += 4;
                    if ( ++v61 >= fieldSize )
                      goto LABEL_11;
                  }
LABEL_43:
                  v66->m_nErrorCount = 1;
                }
                break;
              default:
                break;
            }
          }
LABEL_11:
          v10 = v64 + 1;
          v64 = v10;
        }
        while ( v10 < v56 );
      }
    }
    ++i;
    v62 = __ROL4__(v62, 1);
    if ( i >= 2 )
      return;
    this = v66;
    v4 = types;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154210
// Name: RemoveFieldsByName
// Source: json
//------------------------------------------------------------------------------
void __usercall RemoveFieldsByName(
        CUtlVector<typedescription_t,CUtlMemory<typedescription_t,int> > *build@<edi>,
        const char *pchFieldName)
{
  int v2; // esi
  int v3; // ebx

  v2 = build->m_Size - 2;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      if ( build->m_Memory.m_pMemory[v3].fieldType != FIELD_EMBEDDED
        && _V_stricmp(s1: build->m_Memory.m_pMemory[v3].fieldName, s2: pchFieldName) == 0 )
      {
        if ( build->m_Size - v2 - 1 > 0 )
          _V_memmove(
            dest: &build->m_Memory.m_pMemory[v3],
            src: &build->m_Memory.m_pMemory[v3 + 1],
            count: 60 * (build->m_Size - v2 - 1));
        --build->m_Size;
      }
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154300
// Name: public: CPredictionCopy::CPredictionCopy(int,unsigned char __near *,bool,unsigned char const __near *,bool,enum CPredictionCopy::optype_t,void (*)(char const __near *,char const __near *,char const __near *,bool,bool,bool,bool,char const __near *))
// Source: json
//------------------------------------------------------------------------------
CPredictionCopy *__userpurge CPredictionCopy::CPredictionCopy@<dx:ax>(
        CPredictionCopy *this@<ecx>,
        int type,
        unsigned __int8 *dest,
        bool dest_packed,
        const unsigned __int8 *src,
        bool src_packed,
        CPredictionCopy::optype_t opType,
        void (__cdecl *func)(const char *, const char *, const char *, bool, bool, bool, bool, const char *))
{
  __int64 result; // rax

  LODWORD(result) = this;
  this->m_FieldStack.m_Memory.m_pMemory = nullptr;
  this->m_FieldStack.m_Memory.m_nAllocationCount = 0;
  this->m_FieldStack.m_Memory.m_nGrowSize = 0;
  this->m_FieldStack.m_Size = 0;
  this->m_FieldStack.m_pElements = nullptr;
  this->m_OpType = opType;
  this->m_nType = type;
  this->m_pDest = dest;
  this->m_pSrc = src;
  this->m_nErrorCount = 0;
  this->m_pWatchField = nullptr;
  this->m_nEntIndex = -1;
  this->m_nDestOffsetIndex = dest_packed;
  HIDWORD(result) = src_packed;
  this->m_FieldCompareFunc = func;
  this->m_nSrcOffsetIndex = HIDWORD(result);
  return (CPredictionCopy *)result;
}

//------------------------------------------------------------------------------
// Address: 0x10154360
// Name: private: void CPredictionCopy::ReportFieldsDiffer(struct datamap_t const __near *,struct typedescription_t const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CPredictionCopy::ReportFieldsDiffer(
        CPredictionCopy *this,
        const datamap_t *pCurrentMap,
        const typedescription_t *pField,
        char *fmt,
        ...)
{
  int m_nValue; // eax
  bool v6; // bl
  int i; // edi
  const typedescription_t *v8; // eax
  char *v9; // eax
  const char *v10; // eax
  char pDest[4096]; // [esp+4h] [ebp-1014h] BYREF
  CUtlString v12; // [esp+1004h] [ebp-14h] BYREF
  const char *dataClassName; // [esp+1014h] [ebp-4h]
  const char *fieldName; // [esp+1020h] [ebp+8h]
  va_list params; // [esp+1030h] [ebp+18h] BYREF

  va_start(params, fmt);
  ++this->m_nErrorCount;
  if ( this->m_FieldCompareFunc == nullptr )
  {
    fieldName = "empty";
    dataClassName = "empty";
    if ( pField != nullptr )
    {
      fieldName = pField->fieldName;
      if ( fieldName == nullptr )
        fieldName = "NULL";
      dataClassName = pCurrentMap->dataClassName;
    }
    V_vsnprintf(pDest, maxLen: 0x1000u, pFormat: fmt, params);
    if ( cl_pred_error_verbose.m_pParent != nullptr )
      m_nValue = cl_pred_error_verbose.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v6 = m_nValue != 0;
    CUtlString::CUtlString(this: &v12);
    for ( i = 0; i < this->m_FieldStack.m_Size; ++i )
    {
      v8 = this->m_FieldStack.m_Memory.m_pMemory[i];
      if ( v8 != nullptr )
      {
        if ( (v8->flags & 4) != 0 )
          v6 = true;
        v9 = (char *)v8->fieldName;
        if ( v9 == nullptr )
          v9 = "NULL";
        CUtlString::operator+=(this: &v12, rhs: v9);
        CUtlString::operator+=(this: &v12, rhs: "/");
      }
    }
    if ( v6 )
    {
      v10 = CUtlString::operator char const *(this: &v12);
      _Msg(a1: "%2d (%d)%s%s::%s - %s", this->m_nErrorCount, this->m_nEntIndex, v10, dataClassName, fieldName, pDest);
    }
    else
    {
      _Msg(a1: "%2d (%d)%s::%s - %s", this->m_nErrorCount, this->m_nEntIndex, dataClassName, fieldName, pDest);
    }
    v12.m_Storage.m_nActualLength = 0;
    if ( v12.m_Storage.m_Memory.m_nGrowSize >= 0 && v12.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101544B0
// Name: BuildGroupList_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGroupList_R(
        int nPredictionCopyType,
        int nGroup,
        const datamap_t *dmap,
        CUtlVector<datamap_t const *,CUtlMemory<datamap_t const *,int> > *vecGroups)
{
  datamap_t *baseMap; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  const datamap_t **m_pMemory; // ecx
  int v8; // eax
  const datamap_t **v9; // eax

  baseMap = dmap->baseMap;
  if ( baseMap != nullptr )
    BuildGroupList_R(nPredictionCopyType, nGroup: nGroup + 1, dmap: baseMap, vecGroups);
  m_nAllocationCount = vecGroups->m_Memory.m_nAllocationCount;
  m_Size = vecGroups->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)vecGroups,
      num: m_Size - m_nAllocationCount + 1);
  ++vecGroups->m_Size;
  m_pMemory = vecGroups->m_Memory.m_pMemory;
  v8 = vecGroups->m_Size - m_Size - 1;
  vecGroups->m_pElements = vecGroups->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &vecGroups->m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = dmap;
}

//------------------------------------------------------------------------------
// Address: 0x10154530
// Name: BuildFlattenedChains_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildFlattenedChains_R(
        int nPredictionCopyType,
        int *nMaxGroupSeen,
        int nGroup,
        datamap_t *dmap,
        CUtlVector<typedescription_t,CUtlMemory<typedescription_t,int> > *build,
        int nBaseOffset)
{
  datamap_t *v7; // esi
  datamap_t *baseMap; // eax
  const typedescription_t *v9; // esi
  char v10; // cl
  __int16 flags; // ax
  int v12; // eax
  int dataNumFields; // [esp+Ch] [ebp-4h]
  int nGroupa; // [esp+20h] [ebp+10h]

  v7 = dmap;
  baseMap = dmap->baseMap;
  if ( baseMap != nullptr )
    BuildFlattenedChains_R(nPredictionCopyType, nMaxGroupSeen, nGroup: nGroup + 1, dmap: baseMap, build, nBaseOffset);
  if ( nGroup > *nMaxGroupSeen )
    *nMaxGroupSeen = nGroup;
  if ( dmap->dataNumFields > 0 )
  {
    nGroupa = 0;
    dataNumFields = dmap->dataNumFields;
    while ( 1 )
    {
      v9 = &v7->dataDesc[nGroupa];
      if ( v9->fieldType == FIELD_VOID )
        goto LABEL_31;
      v10 = 1;
      if ( v9->fieldType == FIELD_EMBEDDED )
        goto LABEL_18;
      flags = v9->flags;
      if ( (flags & 0x200) != 0 )
      {
        if ( (flags & 0x80u) == 0 )
          goto LABEL_31;
LABEL_30:
        RemoveFieldsByName(build, pchFieldName: v9->fieldName);
        goto LABEL_31;
      }
      if ( nPredictionCopyType == 0 )
        break;
      if ( nPredictionCopyType == 1 && (v9->flags & 0x100) == 0 )
        goto LABEL_18;
LABEL_19:
      v12 = nBaseOffset + v9->fieldOffset;
      v9->flatGroup = nGroup;
      v9->flatOffset[0] = v12;
      if ( v10 != 0 )
        CUtlVector<typedescription_t,CUtlMemory<typedescription_t,int>>::InsertBefore(
          this: build,
          elem: build->m_Size,
          src: v9);
      if ( v9->fieldType == FIELD_EMBEDDED )
      {
        if ( (v9->flags & 0x40) != 0
          && _LoggingSystem_LogAssert(
               a1: "%s (%d) : %s\n",
               "..\\..\\game\\shared\\predictioncopy.cpp",
               1050,
               v9->fieldName) == 1 )
        {
          if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
            || (unsigned __int8)_DoNewAssertDialog(
                                  a1: "..\\..\\game\\shared\\predictioncopy.cpp",
                                  a2: 1050,
                                  a3: v9->fieldName) != 0 )
          {
            __debugbreak();
          }
          __ExitOnFatalAssert(a1: "..\\..\\game\\shared\\predictioncopy.cpp", a2: 1050);
        }
        BuildFlattenedChains_R(
          nPredictionCopyType,
          nMaxGroupSeen,
          nGroup,
          dmap: v9->td,
          build,
          nBaseOffset: v9->flatOffset[0]);
      }
      if ( SLOBYTE(v9->flags) < 0 )
        goto LABEL_30;
LABEL_31:
      ++nGroupa;
      if ( --dataNumFields == 0 )
        return;
      v7 = dmap;
    }
    if ( (v9->flags & 0x100) == 0 )
      goto LABEL_19;
LABEL_18:
    v10 = 0;
    goto LABEL_19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101546A0
// Name: private: void CPredictionCopy::DescribeFields(class CUtlVector<struct datamap_t const __near *,class CUtlMemory<struct datamap_t const __near *,int>> const __near &,struct datamap_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictionCopy::DescribeFields(
        CPredictionCopy *this@<ecx>,
        const char *a2@<edi>,
        const CUtlVector<datamap_t const *,CUtlMemory<datamap_t const *,int> > *vecGroups,
        const datamap_t *pCurrentMap,
        const datamap_t *nPredictionCopyType)
{
  datamapinfo_t *v5; // eax
  const typedescription_t *m_pMemory; // ebx
  float *v7; // esi
  float *v8; // edi
  CPredictionCopy::difftype_t fieldSize; // ecx
  int flatGroup; // eax
  float fieldTolerance; // xmm0_4
  int v12; // edx
  float *v13; // eax
  int v14; // eax
  float *v15; // edx
  CPredictionCopy::difftype_t v16; // eax
  float v17; // xmm4_4
  float *v18; // eax
  float *v19; // edx
  float v20; // xmm0_4
  int v21; // edx
  float *v22; // eax
  float v23; // xmm1_4
  CPredictionCopy::difftype_t v24; // edx
  float *v25; // edx
  char *v26; // eax
  float *v27; // eax
  bool v28; // zf
  const char *v29; // ecx
  const char *v30; // eax
  const char *v31; // eax
  float *v32; // eax
  int v33; // edi
  int v34; // edi
  const struct model_t *v35; // eax
  const char *v36; // eax
  float *v37; // eax
  int v38; // edx
  float *v39; // eax
  int v40; // eax
  unsigned int v41; // edx
  unsigned int v42; // edx
  IHandleEntity *v43; // eax
  unsigned int v44; // ecx
  IHandleEntity *v45; // ecx
  unsigned int v46; // edi
  IHandleEntity *v47; // eax
  unsigned int v48; // esi
  int v49; // edi
  CEntInfo *v50; // eax
  unsigned int v51; // esi
  C_BaseEntity *v52; // eax
  char *Classname; // eax
  type_info *v54; // eax
  int v55; // edi
  int v56; // [esp+40h] [ebp-25Ch]
  int v57; // [esp+44h] [ebp-258h]
  int v58; // [esp+48h] [ebp-254h]
  int v59; // [esp+4Ch] [ebp-250h]
  int v60; // [esp+50h] [ebp-24Ch]
  int v61; // [esp+54h] [ebp-248h]
  int v62; // [esp+54h] [ebp-248h]
  int v63; // [esp+58h] [ebp-244h]
  int v64; // [esp+58h] [ebp-244h]
  int v65; // [esp+58h] [ebp-244h]
  int v66; // [esp+58h] [ebp-244h]
  IHandleEntity *v67; // [esp+58h] [ebp-244h]
  int v68; // [esp+5Ch] [ebp-240h]
  int v69; // [esp+5Ch] [ebp-240h]
  int v70; // [esp+5Ch] [ebp-240h]
  int v71; // [esp+5Ch] [ebp-240h]
  int v72; // [esp+5Ch] [ebp-240h]
  const char *v73; // [esp+60h] [ebp-23Ch]
  char out[512]; // [esp+6Ch] [ebp-230h] BYREF
  float v75; // [esp+26Ch] [ebp-30h]
  float v76; // [esp+270h] [ebp-2Ch]
  float v77; // [esp+274h] [ebp-28h]
  float v78; // [esp+278h] [ebp-24h]
  int fieldCount; // [esp+27Ch] [ebp-20h]
  int i; // [esp+280h] [ebp-1Ch]
  float *j; // [esp+284h] [ebp-18h]
  CPredictionCopy::difftype_t m_pEntity; // [esp+288h] [ebp-14h]
  CPredictionCopy *v83; // [esp+28Ch] [ebp-10h]
  const typedescription_t *pField; // [esp+290h] [ebp-Ch]
  CPredictionCopy::difftype_t dt; // [esp+294h] [ebp-8h]
  CPredictionCopy::difftype_t v86; // [esp+298h] [ebp-4h]
  const datamap_t *sourceGroup; // [esp+2ACh] [ebp+10h]

  v83 = this;
  v5 = &pCurrentMap->m_pOptimizedDataMap->m_Info[(_DWORD)nPredictionCopyType];
  m_pMemory = v5->m_Flat.m_Flattened.m_Memory.m_pMemory;
  fieldCount = v5->m_Flat.m_Flattened.m_Size;
  pField = m_pMemory;
  i = 0;
  if ( fieldCount > 0 )
  {
    v73 = a2;
    while ( 2 )
    {
      v7 = (float *)&v83->m_pDest[m_pMemory->flatOffset[v83->m_nSrcOffsetIndex]];
      v8 = (float *)&v83->m_pSrc[m_pMemory->flatOffset[v83->m_nDestOffsetIndex]];
      fieldSize = m_pMemory->fieldSize;
      sourceGroup = pCurrentMap;
      flatGroup = m_pMemory->flatGroup;
      if ( flatGroup < vecGroups->m_Size )
        sourceGroup = vecGroups->m_Memory.m_pMemory[flatGroup];
      switch ( m_pMemory->fieldType )
      {
        case FIELD_FLOAT:
          fieldTolerance = m_pMemory->fieldTolerance;
          m_pEntity = IDENTICAL;
          dt = DIFFERS;
          if ( fieldTolerance <= 0.0 )
          {
            if ( fieldSize <= DIFFERS )
            {
LABEL_20:
              dt = m_pEntity;
              goto LABEL_21;
            }
            v14 = (char *)v7 - (char *)v8;
            v15 = v8;
            j = (float *)((char *)v7 - (char *)v8);
            while ( *(float *)((char *)v15 + v14) == *v15 )
            {
              ++dt;
              ++v15;
              if ( dt >= fieldSize )
                goto LABEL_20;
              v14 = (int)j;
            }
          }
          else
          {
            if ( fieldSize <= DIFFERS )
              goto LABEL_20;
            v12 = (char *)v7 - (char *)v8;
            v13 = v8;
            j = (float *)((char *)v7 - (char *)v8);
            while ( fieldTolerance >= fabs(*(float *)((char *)v13 + v12) - *v13) )
            {
              ++dt;
              ++v13;
              m_pEntity = WITHINTOLERANCE;
              if ( dt >= fieldSize )
                goto LABEL_20;
              v12 = (int)j;
            }
          }
          dt = DIFFERS;
          CPredictionCopy::ReportFieldsDiffer(
            this: v83,
            pCurrentMap: sourceGroup,
            pField: m_pMemory,
            fmt: "float differs (net %f pred %f) diff(%f)\n",
            *v8,
            *v7,
            (float)(*v7 - *v8));
LABEL_21:
          CPredictionCopy::OutputFieldDescription(
            this: v83,
            pCurrentMap: sourceGroup,
            pField: m_pMemory,
            dt,
            fmt: "float (%f)\n",
            *v7);
LABEL_145:
          ++m_pMemory;
          ++i;
          pField = m_pMemory;
          if ( i >= fieldCount )
            return;
          continue;
        case FIELD_STRING:
          if ( _V_strcmp(s1: (const char *)v7, s2: (const char *)v8) != 0 )
          {
            v86 = DIFFERS;
            CPredictionCopy::ReportFieldsDiffer(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              fmt: "string differs (net %s pred %s)\n",
              (const char *)v8,
              (const char *)v7);
            v16 = v86;
          }
          else
          {
            v16 = IDENTICAL;
          }
          CPredictionCopy::OutputFieldDescription(
            this: v83,
            pCurrentMap: sourceGroup,
            pField: m_pMemory,
            dt: v16,
            fmt: "string (%s)\n",
            (const char *)v7);
          goto LABEL_145;
        case FIELD_VECTOR:
          v17 = m_pMemory->fieldTolerance;
          v86 = IDENTICAL;
          dt = DIFFERS;
          if ( v17 <= 0.0 )
          {
            if ( fieldSize > DIFFERS )
            {
              j = v8;
              v19 = v7 + 1;
              m_pEntity = (char *)v8 - (char *)v7;
              while ( *j == *(v19 - 1) && *(float *)((char *)v19 + m_pEntity) == *v19 && j[2] == v19[1] )
              {
                ++dt;
                j += 3;
                v19 += 3;
                if ( dt >= fieldSize )
                  goto LABEL_41;
              }
              goto LABEL_34;
            }
          }
          else if ( fieldSize > DIFFERS )
          {
            pField = (const typedescription_t *)v7;
            v18 = v8 + 1;
            j = (float *)((char *)v7 - (char *)v8);
            while ( v17 >= fabs(*(float *)&pField->fieldType - *(v18 - 1))
                 && v17 >= fabs(*(float *)((char *)j + (_DWORD)v18) - *v18)
                 && v17 >= fabs(*(float *)&pField->fieldOffset - v18[1]) )
            {
              ++dt;
              pField = (const typedescription_t *)((char *)pField + 12);
              v18 += 3;
              v86 = WITHINTOLERANCE;
              if ( dt >= fieldSize )
                goto LABEL_41;
            }
LABEL_34:
            dt = DIFFERS;
            CPredictionCopy::ReportFieldsDiffer(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              fmt: "vec[] differs (1st diff) (net %f %f %f - pred %f %f %f) delta(%f %f %f)\n",
              *v8,
              v8[1],
              v8[2],
              *v7,
              v7[1],
              v7[2],
              (float)(*v7 - *v8),
              (float)(v7[1] - v8[1]),
              (float)(v7[2] - v8[2]));
LABEL_42:
            CPredictionCopy::OutputFieldDescription(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              dt,
              fmt: "vector (%f %f %f)\n",
              *v7,
              v7[1],
              v7[2]);
            goto LABEL_145;
          }
LABEL_41:
          dt = v86;
          goto LABEL_42;
        case FIELD_QUATERNION:
          v20 = m_pMemory->fieldTolerance;
          pField = (const typedescription_t *)1;
          if ( v20 <= 0.0 )
          {
            m_pEntity = DIFFERS;
            if ( fieldSize > DIFFERS )
            {
              j = (float *)((char *)v7 - (char *)v8);
              dt = (CPredictionCopy::difftype_t)v8;
LABEL_56:
              v25 = (float *)dt;
              v86 = DIFFERS;
              while ( *(float *)((char *)v25 + (_DWORD)j) == *v25 )
              {
                ++v25;
                if ( ++v86 >= 4 )
                {
                  dt += 16;
                  if ( ++m_pEntity < fieldSize )
                    goto LABEL_56;
                  goto LABEL_60;
                }
              }
              goto LABEL_53;
            }
          }
          else
          {
            v86 = DIFFERS;
            if ( fieldSize > DIFFERS )
            {
              v21 = (char *)v7 - (char *)v8;
              v22 = v8 + 3;
              for ( j = (float *)((char *)v7 - (char *)v8); ; v21 = (int)j )
              {
                v23 = *(float *)((char *)v22 + v21) - *v22;
                v24 = v86;
                *(&v75 + v86) = v23;
                if ( v20 < fabs(v75) || v20 < fabs(v76) || v20 < fabs(v77) || v20 < fabs(v78) )
                  break;
                v22 += 4;
                pField = (const typedescription_t *)2;
                v86 = v24 + 1;
                if ( v24 + 1 >= fieldSize )
                  goto LABEL_60;
              }
LABEL_53:
              dt = DIFFERS;
              CPredictionCopy::ReportFieldsDiffer(
                this: v83,
                pCurrentMap: sourceGroup,
                pField: m_pMemory,
                fmt: "quaternion[] differs (1st diff) (net %f %f %f %f - pred %f %f %f %f) delta(%f %f %f %f)\n",
                *v8,
                v8[1],
                v8[2],
                v8[3],
                *v7,
                v7[1],
                v7[2],
                v7[3],
                (float)(v7[3] - v8[3]),
                v76,
                v77,
                v78);
LABEL_61:
              CPredictionCopy::OutputFieldDescription(
                this: v83,
                pCurrentMap: sourceGroup,
                pField: m_pMemory,
                dt,
                fmt: "quaternion (%f %f %f %f)\n",
                *v7,
                v7[1],
                v7[2],
                v7[3]);
              goto LABEL_145;
            }
          }
LABEL_60:
          dt = (CPredictionCopy::difftype_t)pField;
          goto LABEL_61;
        case FIELD_INTEGER:
          v86 = DIFFERS;
          if ( fieldSize <= DIFFERS )
          {
LABEL_92:
            m_pEntity = IDENTICAL;
          }
          else
          {
            v32 = v7;
            while ( *(_DWORD *)v32 == *(_DWORD *)((char *)v32 + (char *)v8 - (char *)v7) )
            {
              ++v32;
              if ( ++v86 >= fieldSize )
              {
                m_pMemory = pField;
                goto LABEL_92;
              }
            }
            v33 = *(_DWORD *)v8;
            m_pMemory = pField;
            v69 = *(_DWORD *)v7 - v33;
            v64 = *(_DWORD *)v7;
            m_pEntity = DIFFERS;
            CPredictionCopy::ReportFieldsDiffer(
              this: v83,
              pCurrentMap: sourceGroup,
              pField,
              fmt: "int differs (net %i pred %i) diff(%i)\n",
              v33,
              v64,
              v69);
          }
          if ( (m_pMemory->flags & 0x800) != 0
            && (v34 = *(_DWORD *)v7, (v35 = modelinfo->GetModel(this: modelinfo, a2: *(_DWORD *)v7)) != nullptr) )
          {
            out[0] = 0;
            v36 = modelinfo->GetModelName(this: modelinfo, a2: v35);
            V_FileBase(in: v36, out, maxlen: 512);
            CPredictionCopy::OutputFieldDescription(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              dt: m_pEntity,
              fmt: "integer (%i->%s)\n",
              v34,
              out);
          }
          else
          {
            CPredictionCopy::OutputFieldDescription(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              dt: m_pEntity,
              fmt: "integer (%i)\n",
              *(_DWORD *)v7);
          }
          goto LABEL_145;
        case FIELD_BOOLEAN:
          v86 = DIFFERS;
          if ( fieldSize <= DIFFERS )
          {
LABEL_78:
            v86 = IDENTICAL;
          }
          else
          {
            v27 = v7;
            while ( *(_BYTE *)v27 == *((_BYTE *)v27 + (char *)v8 - (char *)v7) )
            {
              v27 = (float *)((char *)v27 + 1);
              if ( ++v86 >= fieldSize )
              {
                m_pMemory = pField;
                goto LABEL_78;
              }
            }
            v28 = *(_BYTE *)v7 == 0;
            v86 = DIFFERS;
            v29 = "true";
            if ( v28 )
              v29 = "false";
            v30 = "true";
            if ( *(_BYTE *)v8 == 0 )
              v30 = "false";
            m_pMemory = pField;
            CPredictionCopy::ReportFieldsDiffer(
              this: v83,
              pCurrentMap: sourceGroup,
              pField,
              fmt: "bool differs (net %s pred %s)\n",
              v30,
              v29);
          }
          v31 = "true";
          if ( *(_BYTE *)v7 == 0 )
            v31 = "false";
          CPredictionCopy::OutputFieldDescription(
            this: v83,
            pCurrentMap: sourceGroup,
            pField: m_pMemory,
            dt: v86,
            fmt: "bool (%s)\n",
            v31);
          goto LABEL_145;
        case FIELD_SHORT:
          v86 = DIFFERS;
          if ( fieldSize <= DIFFERS )
          {
LABEL_103:
            v38 = *(__int16 *)v7;
            v86 = IDENTICAL;
            CPredictionCopy::OutputFieldDescription(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              dt: IDENTICAL,
              fmt: "short (%i)\n",
              v38);
          }
          else
          {
            v37 = v7;
            while ( *(_WORD *)v37 == *(_WORD *)((char *)v37 + (char *)v8 - (char *)v7) )
            {
              v37 = (float *)((char *)v37 + 2);
              if ( ++v86 >= fieldSize )
              {
                m_pMemory = pField;
                goto LABEL_103;
              }
            }
            m_pMemory = pField;
            v70 = *(__int16 *)v7 - *(__int16 *)v8;
            v65 = *(__int16 *)v7;
            v62 = *(__int16 *)v8;
            v86 = DIFFERS;
            CPredictionCopy::ReportFieldsDiffer(
              this: v83,
              pCurrentMap: sourceGroup,
              pField,
              fmt: "short differs (net %i pred %i) diff(%i)\n",
              v62,
              v65,
              v70);
            CPredictionCopy::OutputFieldDescription(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              dt: v86,
              fmt: "short (%i)\n",
              *(__int16 *)v7);
          }
          goto LABEL_145;
        case FIELD_CHARACTER:
          v86 = DIFFERS;
          if ( fieldSize <= DIFFERS )
          {
LABEL_110:
            v71 = *(unsigned __int8 *)v7;
            v86 = IDENTICAL;
            CPredictionCopy::OutputFieldDescription(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              dt: IDENTICAL,
              fmt: "byte (%d)\n",
              v71);
          }
          else
          {
            v39 = v7;
            while ( *(_BYTE *)v39 == *((_BYTE *)v39 + (char *)v8 - (char *)v7) )
            {
              v39 = (float *)((char *)v39 + 1);
              if ( ++v86 >= fieldSize )
              {
                m_pMemory = pField;
                goto LABEL_110;
              }
            }
            m_pMemory = pField;
            v72 = *(unsigned __int8 *)v7;
            v66 = *(unsigned __int8 *)v8;
            v86 = DIFFERS;
            CPredictionCopy::ReportFieldsDiffer(
              this: v83,
              pCurrentMap: sourceGroup,
              pField,
              fmt: "byte differs (net %d pred %d)\n",
              v66,
              v72);
            CPredictionCopy::OutputFieldDescription(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              dt: v86,
              fmt: "byte (%d)\n",
              *(unsigned __int8 *)v7);
          }
          goto LABEL_145;
        case FIELD_COLOR32:
          v86 = DIFFERS;
          if ( fieldSize <= DIFFERS )
          {
LABEL_69:
            v86 = IDENTICAL;
          }
          else
          {
            dt = (CPredictionCopy::difftype_t)((char *)v8 + 3);
            v26 = (char *)v7 + 1;
            j = (float *)((char *)v7 + 1);
            m_pEntity = (char *)v8 - (char *)v7;
            while ( *(v26 - 1) == *(_BYTE *)(dt - 3) )
            {
              if ( *(_BYTE *)j != *((_BYTE *)j + m_pEntity)
                || *((_BYTE *)j + 1) != *(_BYTE *)(dt - 1)
                || *((_BYTE *)j + 2) != *(_BYTE *)dt )
              {
                m_pMemory = pField;
                break;
              }
              v26 = (char *)(j + 1);
              dt += 4;
              m_pMemory = pField;
              ++v86;
              ++j;
              if ( v86 >= fieldSize )
                goto LABEL_69;
            }
            v68 = *((unsigned __int8 *)v8 + 3);
            v63 = *((unsigned __int8 *)v8 + 2);
            v61 = *((unsigned __int8 *)v8 + 1);
            v60 = *(unsigned __int8 *)v8;
            v59 = *((unsigned __int8 *)v7 + 3);
            v58 = *((unsigned __int8 *)v7 + 2);
            v57 = *((unsigned __int8 *)v7 + 1);
            v56 = *(unsigned __int8 *)v7;
            v86 = DIFFERS;
            CPredictionCopy::ReportFieldsDiffer(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              fmt: "color differs (net %d %d %d %d pred %d %d %d %d)\n",
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v63,
              v68);
          }
          CPredictionCopy::OutputFieldDescription(
            this: v83,
            pCurrentMap: sourceGroup,
            pField: m_pMemory,
            dt: v86,
            fmt: "color (%d %d %d %d)\n",
            *(unsigned __int8 *)v7,
            *((unsigned __int8 *)v7 + 1),
            *((unsigned __int8 *)v7 + 2),
            *((unsigned __int8 *)v7 + 3));
          goto LABEL_145;
        case FIELD_EMBEDDED:
          _Error(this: (ISceneTokenProcessor *)&stru_1048875C, a2: v73);
          goto LABEL_145;
        case FIELD_EHANDLE:
          v86 = DIFFERS;
          if ( fieldSize <= DIFFERS )
          {
LABEL_125:
            m_pEntity = IDENTICAL;
          }
          else
          {
            v40 = (char *)v7 - (char *)v8;
            dt = (CPredictionCopy::difftype_t)v8;
            for ( j = (float *)((char *)v7 - (char *)v8); ; v40 = (int)j )
            {
              v41 = *(_DWORD *)(v40 + dt);
              if ( v41 == -1
                || (m_pMemory = pField, g_pEntityList->m_EntPtrArray[(unsigned __int16)v41].m_SerialNumber != HIWORD(v41)) )
              {
                m_pEntity = DIFFERS;
              }
              else
              {
                m_pEntity = (CPredictionCopy::difftype_t)g_pEntityList->m_EntPtrArray[(unsigned __int16)v41].m_pEntity;
              }
              v42 = *(_DWORD *)dt;
              if ( *(_DWORD *)dt == -1
                || (m_pMemory = pField, g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_SerialNumber != HIWORD(v42)) )
              {
                v43 = nullptr;
              }
              else
              {
                v43 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_pEntity;
              }
              if ( (IHandleEntity *)m_pEntity != v43 )
                break;
              dt += 4;
              if ( ++v86 >= fieldSize )
                goto LABEL_125;
            }
            v44 = *(_DWORD *)v7;
            m_pEntity = DIFFERS;
            if ( v44 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_SerialNumber != HIWORD(v44) )
              v45 = nullptr;
            else
              v45 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_pEntity;
            v46 = *(_DWORD *)v8;
            if ( v46 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_SerialNumber != HIWORD(v46) )
              v47 = nullptr;
            else
              v47 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_pEntity;
            CPredictionCopy::ReportFieldsDiffer(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              fmt: "EHandles differ (net) 0x%p (pred) 0x%p\n",
              v47,
              v45);
          }
          v48 = *(_DWORD *)v7;
          if ( v48 != -1
            && (v49 = (unsigned __int16)v48,
                v50 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v48],
                v51 = HIWORD(v48),
                v50->m_SerialNumber == v51)
            && (v52 = (C_BaseEntity *)v50->m_pEntity, v86 = (CPredictionCopy::difftype_t)v52, v52 != nullptr) )
          {
            Classname = C_BaseEntity::GetClassname(this: v52);
            if ( *Classname == 0 )
            {
              v54 = (type_info *)__RTtypeid(inptr: (_DWORD *)v86);
              Classname = (char *)type_info::name(this: v54, __ptype_info_node: &__type_info_root_node);
            }
            v55 = v49;
            if ( g_pEntityList->m_EntPtrArray[v55].m_SerialNumber == v51 )
              v67 = g_pEntityList->m_EntPtrArray[v55].m_pEntity;
            else
              v67 = nullptr;
            CPredictionCopy::OutputFieldDescription(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              dt: m_pEntity,
              fmt: "EHandle (0x%p->%s)",
              v67,
              Classname);
          }
          else
          {
            CPredictionCopy::OutputFieldDescription(
              this: v83,
              pCurrentMap: sourceGroup,
              pField: m_pMemory,
              dt: m_pEntity,
              fmt: "EHandle (NULL)");
          }
          goto LABEL_145;
        default:
          goto LABEL_145;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155220
// Name: BuildDataRuns
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildDataRuns(datamap_t *dmap)
{
  int v1; // eax
  char *v2; // edi
  int v3; // eax
  __int64 v4; // rcx
  int v5; // edx
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *v6; // esi
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *v9; // ecx
  int v10; // eax
  int v11; // eax
  vgui::CTreeViewListControl::CColumnInfo *v12; // edi
  int v13; // ebx
  int v14; // eax
  vgui::CTreeViewListControl::CColumnInfo *v15; // ecx
  int v16; // eax
  int v17; // eax
  unsigned __int64 run; // [esp+Ch] [ebp-2Ch]
  __int64 runa; // [esp+Ch] [ebp-2Ch]
  __int64 run_8; // [esp+14h] [ebp-24h]
  __int64 run_8a; // [esp+14h] [ebp-24h]
  int run_16; // [esp+1Ch] [ebp-1Ch]
  int v23; // [esp+24h] [ebp-14h]
  datamapinfo_t *info; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  const typedescription_t *td; // [esp+30h] [ebp-8h]
  int offset; // [esp+34h] [ebp-4h]

  v1 = 0;
  v23 = 0;
  do
  {
    v2 = (char *)dmap->m_pOptimizedDataMap + v1;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    info = (datamapinfo_t *)v2;
    v6 = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)(v2 + 28);
    i = 0;
    if ( *((int *)v2 + 3) > 0 )
    {
      do
      {
        td = &info->m_Flat.m_Flattened.m_Memory.m_pMemory[HIDWORD(v4)];
        offset = td->flatOffset[0];
        if ( i == 0 )
        {
          LODWORD(v4) = 0;
          v3 = td->flatOffset[0];
          v5 = v3;
        }
        if ( td->fieldType != FIELD_EMBEDDED )
        {
          if ( v3 != td->flatOffset[0] )
          {
            run = __PAIR64__(i, v4);
            m_pMemory = v6[1].m_pMemory;
            LODWORD(run_8) = v5;
            run_16 = v3 - v5;
            m_nAllocationCount = v6->m_nAllocationCount;
            HIDWORD(run_8) = info->m_Flat.m_Flattened.m_Memory.m_pMemory[v4].flatOffset[1];
            if ( (int)&m_pMemory->m_Title.m_Id + 1 > m_nAllocationCount )
              CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
                this: v6,
                num: (int)&m_pMemory->m_Title.m_Id - m_nAllocationCount + 1);
            ++v6[1].m_pMemory;
            v9 = v6->m_pMemory;
            v10 = (char *)v6[1].m_pMemory - (char *)m_pMemory - 1;
            v6[1].m_nAllocationCount = (int)v6->m_pMemory;
            if ( v10 > 0 )
              _V_memmove(dest: &v9[(int)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: 20 * v10);
            v11 = (int)&v6->m_pMemory[(_DWORD)m_pMemory];
            if ( v11 != 0 )
            {
              *(_QWORD *)v11 = run;
              *(_QWORD *)(v11 + 8) = run_8;
              *(_DWORD *)(v11 + 16) = run_16;
            }
            v5 = offset;
            LODWORD(v4) = i;
          }
          v3 = td->flatOffset[0] + td->fieldSizeInBytes;
        }
        HIDWORD(v4) = i + 1;
        i = HIDWORD(v4);
      }
      while ( SHIDWORD(v4) < info->m_Flat.m_Flattened.m_Size );
      if ( v3 != v5 )
      {
        runa = v4 - 0x100000000LL;
        v12 = v6[1].m_pMemory;
        LODWORD(run_8a) = v5;
        v13 = v3 - v5;
        v14 = v6->m_nAllocationCount;
        HIDWORD(run_8a) = info->m_Flat.m_Flattened.m_Memory.m_pMemory[v4].flatOffset[1];
        if ( (int)&v12->m_Title.m_Id + 1 > v14 )
          CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
            this: v6,
            num: (int)&v12->m_Title.m_Id - v14 + 1);
        ++v6[1].m_pMemory;
        v15 = v6->m_pMemory;
        v16 = (char *)v6[1].m_pMemory - (char *)v12 - 1;
        v6[1].m_nAllocationCount = (int)v6->m_pMemory;
        if ( v16 > 0 )
          _V_memmove(dest: &v15[(int)v12 + 1], src: &v15[(_DWORD)v12], count: 20 * v16);
        v17 = (int)&v6->m_pMemory[(_DWORD)v12];
        if ( v17 != 0 )
        {
          *(_QWORD *)v17 = runa;
          *(_QWORD *)(v17 + 8) = run_8a;
          *(_DWORD *)(v17 + 16) = v13;
        }
      }
    }
    v1 = v23 + 48;
    v23 = v1;
  }
  while ( v1 < 96 );
}

//------------------------------------------------------------------------------
// Address: 0x10155400
// Name: private: void CPredictionCopy::ErrorCheckFlatFields_Spew(struct datamap_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictionCopy::ErrorCheckFlatFields_Spew(
        CPredictionCopy *this@<ecx>,
        const char *a2@<edi>,
        const datamap_t *pCurrentMap,
        const typedescription_t *nPredictionCopyType)
{
  datamapinfo_t *v4; // eax
  const typedescription_t *m_pMemory; // edx
  int m_Size; // eax
  unsigned __int8 *m_pDest; // edx
  const unsigned __int8 *m_pSrc; // ecx
  const typedescription_t *v9; // ebx
  float *v10; // esi
  float *v11; // edi
  CPredictionCopy::difftype_t fieldSize; // ecx
  float fieldTolerance; // xmm0_4
  int v14; // edx
  float *v15; // eax
  int v16; // eax
  float *v17; // edx
  CPredictionCopy::difftype_t v18; // eax
  float v19; // xmm4_4
  float *v20; // eax
  float *v21; // edx
  float v22; // xmm0_4
  int v23; // edx
  float *v24; // eax
  float v25; // xmm1_4
  const typedescription_t *v26; // edx
  float *v27; // edx
  char *v28; // eax
  float *v29; // eax
  bool v30; // zf
  const char *v31; // ecx
  const char *v32; // eax
  const char *v33; // eax
  float *v34; // eax
  int v35; // edi
  int v36; // edi
  const struct model_t *v37; // eax
  const char *v38; // eax
  float *v39; // eax
  int v40; // edx
  float *v41; // eax
  int v42; // eax
  unsigned int v43; // edx
  unsigned int v44; // edx
  IHandleEntity *v45; // eax
  unsigned int v46; // ecx
  IHandleEntity *v47; // ecx
  unsigned int v48; // edi
  IHandleEntity *v49; // eax
  unsigned int v50; // esi
  int v51; // edi
  CEntInfo *v52; // eax
  unsigned int v53; // esi
  C_BaseEntity *v54; // eax
  char *Classname; // eax
  type_info *v56; // eax
  int v57; // edi
  IHandleEntity *v58; // ecx
  int v59; // [esp+54h] [ebp-250h]
  int v60; // [esp+58h] [ebp-24Ch]
  int v61; // [esp+58h] [ebp-24Ch]
  int v62; // [esp+58h] [ebp-24Ch]
  int v63; // [esp+5Ch] [ebp-248h]
  int v64; // [esp+5Ch] [ebp-248h]
  int v65; // [esp+5Ch] [ebp-248h]
  const char *v66; // [esp+60h] [ebp-244h]
  char out[512]; // [esp+6Ch] [ebp-238h] BYREF
  const unsigned __int8 *pSrc; // [esp+26Ch] [ebp-38h]
  float v69; // [esp+270h] [ebp-34h]
  float v70; // [esp+274h] [ebp-30h]
  float v71; // [esp+278h] [ebp-2Ch]
  float v72; // [esp+27Ch] [ebp-28h]
  const unsigned __int8 *pDest; // [esp+280h] [ebp-24h]
  int fieldCount; // [esp+284h] [ebp-20h]
  const typedescription_t *pBase; // [esp+288h] [ebp-1Ch]
  int i; // [esp+28Ch] [ebp-18h]
  int j; // [esp+290h] [ebp-14h]
  int m_pEntity; // [esp+294h] [ebp-10h]
  CPredictionCopy::difftype_t v79; // [esp+298h] [ebp-Ch]
  CPredictionCopy *v80; // [esp+29Ch] [ebp-8h]
  CPredictionCopy::difftype_t dt; // [esp+2A0h] [ebp-4h]
  const typedescription_t *pField; // [esp+2B0h] [ebp+Ch]
  const typedescription_t *pFielda; // [esp+2B0h] [ebp+Ch]
  const typedescription_t *pFieldb; // [esp+2B0h] [ebp+Ch]
  float *pFieldc; // [esp+2B0h] [ebp+Ch]
  const typedescription_t *pFieldd; // [esp+2B0h] [ebp+Ch]
  float *pFielde; // [esp+2B0h] [ebp+Ch]
  const typedescription_t *pFieldf; // [esp+2B0h] [ebp+Ch]
  const typedescription_t *pFieldg; // [esp+2B0h] [ebp+Ch]
  const typedescription_t *pFieldh; // [esp+2B0h] [ebp+Ch]
  CPredictionCopy::difftype_t pFieldi; // [esp+2B0h] [ebp+Ch]
  CPredictionCopy::difftype_t pFieldj; // [esp+2B0h] [ebp+Ch]

  v4 = &pCurrentMap->m_pOptimizedDataMap->m_Info[(_DWORD)nPredictionCopyType];
  v80 = this;
  m_pMemory = v4->m_Flat.m_Flattened.m_Memory.m_pMemory;
  m_Size = v4->m_Flat.m_Flattened.m_Size;
  pBase = m_pMemory;
  m_pDest = this->m_pDest;
  m_pSrc = this->m_pSrc;
  fieldCount = m_Size;
  pDest = m_pDest;
  pSrc = m_pSrc;
  i = 0;
  if ( m_Size > 0 )
  {
    v66 = a2;
    while ( 1 )
    {
      v9 = &pBase[i];
      pField = v9;
      if ( (v9->flags & 0x400) == 0 )
        break;
LABEL_145:
      if ( ++i >= fieldCount )
        return;
    }
    v10 = (float *)&pDest[v9->flatOffset[v80->m_nDestOffsetIndex]];
    v11 = (float *)&pSrc[v9->flatOffset[v80->m_nSrcOffsetIndex]];
    fieldSize = v9->fieldSize;
    switch ( v9->fieldType )
    {
      case FIELD_FLOAT:
        fieldTolerance = v9->fieldTolerance;
        m_pEntity = 1;
        pFielda = nullptr;
        if ( fieldTolerance <= 0.0 )
        {
          if ( fieldSize > DIFFERS )
          {
            v16 = (char *)v10 - (char *)v11;
            v17 = v11;
            j = (char *)v10 - (char *)v11;
            while ( *(float *)((char *)v17 + v16) == *v17 )
            {
              pFielda = (const typedescription_t *)((char *)pFielda + 1);
              ++v17;
              if ( (int)pFielda >= fieldSize )
                goto LABEL_19;
              v16 = j;
            }
            goto LABEL_13;
          }
        }
        else if ( fieldSize > DIFFERS )
        {
          v14 = (char *)v10 - (char *)v11;
          v15 = v11;
          j = (char *)v10 - (char *)v11;
          while ( fieldTolerance >= fabs(*(float *)((char *)v15 + v14) - *v15) )
          {
            pFielda = (const typedescription_t *)((char *)pFielda + 1);
            ++v15;
            m_pEntity = 2;
            if ( (int)pFielda >= fieldSize )
              goto LABEL_19;
            v14 = j;
          }
LABEL_13:
          pFieldb = nullptr;
          CPredictionCopy::ReportFieldsDiffer(
            this: v80,
            pCurrentMap,
            pField: &pBase[i],
            fmt: "float differs (net %f pred %f) diff(%f)\n",
            *v11,
            *v10,
            (float)(*v10 - *v11));
LABEL_20:
          CPredictionCopy::OutputFieldDescription(
            this: v80,
            pCurrentMap,
            pField: v9,
            dt: (CPredictionCopy::difftype_t)pFieldb,
            fmt: "float (%f)\n",
            *v10);
          goto LABEL_145;
        }
LABEL_19:
        pFieldb = (const typedescription_t *)m_pEntity;
        goto LABEL_20;
      case FIELD_STRING:
        if ( _V_strcmp(s1: (const char *)v10, s2: (const char *)v11) != 0 )
        {
          CPredictionCopy::ReportFieldsDiffer(
            this: v80,
            pCurrentMap,
            pField: v9,
            fmt: "string differs (net %s pred %s)\n",
            (const char *)v11,
            (const char *)v10);
          v18 = DIFFERS;
        }
        else
        {
          v18 = IDENTICAL;
        }
        CPredictionCopy::OutputFieldDescription(this: v80, pCurrentMap, pField: v9, dt: v18, fmt: "string (%s)\n", v10);
        goto LABEL_145;
      case FIELD_VECTOR:
        v19 = v9->fieldTolerance;
        m_pEntity = 1;
        v79 = DIFFERS;
        if ( v19 <= 0.0 )
        {
          if ( fieldSize > DIFFERS )
          {
            pFielde = v11;
            v21 = v10 + 1;
            j = (char *)v11 - (char *)v10;
            while ( *pFielde == *(v21 - 1) && *(float *)((char *)v21 + j) == *v21 && pFielde[2] == v21[1] )
            {
              ++v79;
              pFielde += 3;
              v21 += 3;
              if ( v79 >= fieldSize )
                goto LABEL_40;
            }
            goto LABEL_33;
          }
        }
        else if ( fieldSize > DIFFERS )
        {
          pFieldc = v10;
          v20 = v11 + 1;
          j = (char *)v10 - (char *)v11;
          while ( v19 >= fabs(*pFieldc - *(v20 - 1))
               && v19 >= fabs(*(float *)((char *)v20 + j) - *v20)
               && v19 >= fabs(pFieldc[2] - v20[1]) )
          {
            ++v79;
            pFieldc += 3;
            v20 += 3;
            m_pEntity = 2;
            if ( v79 >= fieldSize )
              goto LABEL_40;
          }
LABEL_33:
          pFieldd = nullptr;
          CPredictionCopy::ReportFieldsDiffer(
            this: v80,
            pCurrentMap,
            pField: &pBase[i],
            fmt: "vec[] differs (1st diff) (net %f %f %f - pred %f %f %f) delta(%f %f %f)\n",
            *v11,
            v11[1],
            v11[2],
            *v10,
            v10[1],
            v10[2],
            (float)(*v10 - *v11),
            (float)(v10[1] - v11[1]),
            (float)(v10[2] - v11[2]));
LABEL_41:
          CPredictionCopy::OutputFieldDescription(
            this: v80,
            pCurrentMap,
            pField: v9,
            dt: (CPredictionCopy::difftype_t)pFieldd,
            fmt: "vector (%f %f %f)\n",
            *v10,
            v10[1],
            v10[2]);
          goto LABEL_145;
        }
LABEL_40:
        pFieldd = (const typedescription_t *)m_pEntity;
        goto LABEL_41;
      case FIELD_QUATERNION:
        v22 = v9->fieldTolerance;
        dt = IDENTICAL;
        if ( v22 <= 0.0 )
        {
          v79 = DIFFERS;
          if ( fieldSize > DIFFERS )
          {
            j = (char *)v10 - (char *)v11;
            pFieldh = (const typedescription_t *)v11;
LABEL_55:
            v27 = (float *)pFieldh;
            m_pEntity = 0;
            while ( *(float *)((char *)v27 + j) == *v27 )
            {
              ++v27;
              if ( ++m_pEntity >= 4 )
              {
                pFieldh = (const typedescription_t *)((char *)pFieldh + 16);
                if ( ++v79 < fieldSize )
                  goto LABEL_55;
                goto LABEL_59;
              }
            }
            goto LABEL_52;
          }
        }
        else
        {
          pFieldf = nullptr;
          if ( fieldSize > DIFFERS )
          {
            v23 = (char *)v10 - (char *)v11;
            v24 = v11 + 3;
            for ( j = (char *)v10 - (char *)v11; ; v23 = j )
            {
              v25 = *(float *)((char *)v24 + v23) - *v24;
              v26 = pFieldf;
              *(&v69 + (_DWORD)pFieldf) = v25;
              if ( v22 < fabs(v69) || v22 < fabs(v70) || v22 < fabs(v71) || v22 < fabs(v72) )
                break;
              v24 += 4;
              dt = WITHINTOLERANCE;
              pFieldf = (const typedescription_t *)((char *)pFieldf + 1);
              if ( (int)&v26->fieldType + 1 >= fieldSize )
                goto LABEL_59;
            }
LABEL_52:
            pFieldg = nullptr;
            CPredictionCopy::ReportFieldsDiffer(
              this: v80,
              pCurrentMap,
              pField: v9,
              fmt: "quaternion[] differs (1st diff) (net %f %f %f %f - pred %f %f %f %f) delta(%f %f %f %f)\n",
              *v11,
              v11[1],
              v11[2],
              v11[3],
              *v10,
              v10[1],
              v10[2],
              v10[3],
              (float)(v10[3] - v11[3]),
              v70,
              v71,
              v72);
LABEL_60:
            CPredictionCopy::OutputFieldDescription(
              this: v80,
              pCurrentMap,
              pField: v9,
              dt: (CPredictionCopy::difftype_t)pFieldg,
              fmt: "quaternion (%f %f %f %f)\n",
              *v10,
              v10[1],
              v10[2],
              v10[3]);
            goto LABEL_145;
          }
        }
LABEL_59:
        pFieldg = (const typedescription_t *)dt;
        goto LABEL_60;
      case FIELD_INTEGER:
        dt = DIFFERS;
        if ( fieldSize <= DIFFERS )
        {
LABEL_91:
          v79 = IDENTICAL;
        }
        else
        {
          v34 = v10;
          while ( *(_DWORD *)v34 == *(_DWORD *)((char *)v34 + (char *)v11 - (char *)v10) )
          {
            ++v34;
            if ( ++dt >= fieldSize )
            {
              v9 = &pBase[i];
              goto LABEL_91;
            }
          }
          v35 = *(_DWORD *)v11;
          v9 = &pBase[i];
          v63 = *(_DWORD *)v10 - v35;
          v60 = *(_DWORD *)v10;
          v79 = DIFFERS;
          CPredictionCopy::ReportFieldsDiffer(
            this: v80,
            pCurrentMap,
            pField,
            fmt: "int differs (net %i pred %i) diff(%i)\n",
            v35,
            v60,
            v63);
        }
        if ( (v9->flags & 0x800) != 0
          && (v36 = *(_DWORD *)v10, (v37 = modelinfo->GetModel(this: modelinfo, a2: *(_DWORD *)v10)) != nullptr) )
        {
          out[0] = 0;
          v38 = modelinfo->GetModelName(this: modelinfo, a2: v37);
          V_FileBase(in: v38, out, maxlen: 512);
          CPredictionCopy::OutputFieldDescription(
            this: v80,
            pCurrentMap,
            pField: v9,
            dt: v79,
            fmt: "integer (%i->%s)\n",
            v36,
            out);
        }
        else
        {
          CPredictionCopy::OutputFieldDescription(
            this: v80,
            pCurrentMap,
            pField: v9,
            dt: v79,
            fmt: "integer (%i)\n",
            *(_DWORD *)v10);
        }
        goto LABEL_145;
      case FIELD_BOOLEAN:
        dt = DIFFERS;
        if ( fieldSize <= DIFFERS )
        {
LABEL_77:
          dt = IDENTICAL;
        }
        else
        {
          v29 = v10;
          while ( *(_BYTE *)v29 == *((_BYTE *)v29 + (char *)v11 - (char *)v10) )
          {
            v29 = (float *)((char *)v29 + 1);
            if ( ++dt >= fieldSize )
            {
              v9 = &pBase[i];
              goto LABEL_77;
            }
          }
          v30 = *(_BYTE *)v10 == 0;
          dt = DIFFERS;
          v31 = "true";
          if ( v30 )
            v31 = "false";
          v32 = "true";
          if ( *(_BYTE *)v11 == 0 )
            v32 = "false";
          v9 = &pBase[i];
          CPredictionCopy::ReportFieldsDiffer(
            this: v80,
            pCurrentMap,
            pField,
            fmt: "bool differs (net %s pred %s)\n",
            v32,
            v31);
        }
        v33 = "true";
        if ( *(_BYTE *)v10 == 0 )
          v33 = "false";
        CPredictionCopy::OutputFieldDescription(this: v80, pCurrentMap, pField: v9, dt, fmt: "bool (%s)\n", v33);
        goto LABEL_145;
      case FIELD_SHORT:
        dt = DIFFERS;
        if ( fieldSize <= DIFFERS )
        {
LABEL_102:
          v40 = *(__int16 *)v10;
          dt = IDENTICAL;
          CPredictionCopy::OutputFieldDescription(
            this: v80,
            pCurrentMap,
            pField: v9,
            dt: IDENTICAL,
            fmt: "short (%i)\n",
            v40);
        }
        else
        {
          v39 = v10;
          while ( *(_WORD *)v39 == *(_WORD *)((char *)v39 + (char *)v11 - (char *)v10) )
          {
            v39 = (float *)((char *)v39 + 2);
            if ( ++dt >= fieldSize )
            {
              v9 = &pBase[i];
              goto LABEL_102;
            }
          }
          v64 = *(__int16 *)v10 - *(__int16 *)v11;
          v61 = *(__int16 *)v10;
          v59 = *(__int16 *)v11;
          dt = DIFFERS;
          CPredictionCopy::ReportFieldsDiffer(
            this: v80,
            pCurrentMap,
            pField: v9,
            fmt: "short differs (net %i pred %i) diff(%i)\n",
            v59,
            v61,
            v64);
          CPredictionCopy::OutputFieldDescription(
            this: v80,
            pCurrentMap,
            pField: v9,
            dt,
            fmt: "short (%i)\n",
            *(__int16 *)v10);
        }
        goto LABEL_145;
      case FIELD_CHARACTER:
        dt = DIFFERS;
        if ( fieldSize <= DIFFERS )
        {
LABEL_109:
          dt = IDENTICAL;
        }
        else
        {
          v41 = v10;
          while ( *(_BYTE *)v41 == *((_BYTE *)v41 + (char *)v11 - (char *)v10) )
          {
            v41 = (float *)((char *)v41 + 1);
            if ( ++dt >= fieldSize )
            {
              v9 = &pBase[i];
              goto LABEL_109;
            }
          }
          v9 = &pBase[i];
          v65 = *(unsigned __int8 *)v10;
          v62 = *(unsigned __int8 *)v11;
          dt = DIFFERS;
          CPredictionCopy::ReportFieldsDiffer(
            this: v80,
            pCurrentMap,
            pField,
            fmt: "byte differs (net %d pred %d)\n",
            v62,
            v65);
        }
        CPredictionCopy::OutputFieldDescription(
          this: v80,
          pCurrentMap,
          pField: v9,
          dt,
          fmt: "byte (%d)\n",
          *(unsigned __int8 *)v10);
        goto LABEL_145;
      case FIELD_COLOR32:
        dt = DIFFERS;
        if ( fieldSize <= DIFFERS )
        {
LABEL_68:
          pFieldi = IDENTICAL;
        }
        else
        {
          v79 = (CPredictionCopy::difftype_t)((char *)v11 + 3);
          v28 = (char *)v10 + 1;
          m_pEntity = (int)v10 + 1;
          j = (char *)v11 - (char *)v10;
          while ( *(v28 - 1) == *(_BYTE *)(v79 - 3) )
          {
            if ( *(_BYTE *)m_pEntity != *(_BYTE *)(j + m_pEntity)
              || *(_BYTE *)(m_pEntity + 1) != *(_BYTE *)(v79 - 1)
              || *(_BYTE *)(m_pEntity + 2) != *(_BYTE *)v79 )
            {
              v9 = &pBase[i];
              break;
            }
            v28 = (char *)(m_pEntity + 4);
            v79 += 4;
            v9 = &pBase[i];
            ++dt;
            m_pEntity += 4;
            if ( dt >= fieldSize )
              goto LABEL_68;
          }
          pFieldi = DIFFERS;
          CPredictionCopy::ReportFieldsDiffer(
            this: v80,
            pCurrentMap,
            pField: v9,
            fmt: "color differs (net %d %d %d %d pred %d %d %d %d)\n",
            *(unsigned __int8 *)v10,
            *((unsigned __int8 *)v10 + 1),
            *((unsigned __int8 *)v10 + 2),
            *((unsigned __int8 *)v10 + 3),
            *(unsigned __int8 *)v11,
            *((unsigned __int8 *)v11 + 1),
            *((unsigned __int8 *)v11 + 2),
            *((unsigned __int8 *)v11 + 3));
        }
        CPredictionCopy::OutputFieldDescription(
          this: v80,
          pCurrentMap,
          pField: v9,
          dt: pFieldi,
          fmt: "color (%d %d %d %d)\n",
          *(unsigned __int8 *)v10,
          *((unsigned __int8 *)v10 + 1),
          *((unsigned __int8 *)v10 + 2),
          *((unsigned __int8 *)v10 + 3));
        goto LABEL_145;
      case FIELD_EMBEDDED:
        _Error(this: (ISceneTokenProcessor *)&stru_1048875C, a2: v66);
        goto LABEL_145;
      case FIELD_EHANDLE:
        dt = DIFFERS;
        if ( fieldSize <= DIFFERS )
        {
LABEL_125:
          pFieldj = IDENTICAL;
        }
        else
        {
          v42 = (char *)v10 - (char *)v11;
          v79 = (CPredictionCopy::difftype_t)v11;
          for ( j = (char *)v10 - (char *)v11; ; v42 = j )
          {
            v43 = *(_DWORD *)(v42 + v79);
            if ( v43 == -1
              || (v9 = &pBase[i], g_pEntityList->m_EntPtrArray[(unsigned __int16)v43].m_SerialNumber != HIWORD(v43)) )
            {
              m_pEntity = 0;
            }
            else
            {
              m_pEntity = (int)g_pEntityList->m_EntPtrArray[(unsigned __int16)v43].m_pEntity;
            }
            v44 = *(_DWORD *)v79;
            if ( *(_DWORD *)v79 == -1
              || (v9 = &pBase[i], g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_SerialNumber != HIWORD(v44)) )
            {
              v45 = nullptr;
            }
            else
            {
              v45 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_pEntity;
            }
            if ( (IHandleEntity *)m_pEntity != v45 )
              break;
            v79 += 4;
            if ( ++dt >= fieldSize )
              goto LABEL_125;
          }
          v46 = *(_DWORD *)v10;
          pFieldj = DIFFERS;
          if ( *(_DWORD *)v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_SerialNumber != HIWORD(v46) )
            v47 = nullptr;
          else
            v47 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_pEntity;
          v48 = *(_DWORD *)v11;
          if ( v48 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v48].m_SerialNumber != HIWORD(v48) )
            v49 = nullptr;
          else
            v49 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v48].m_pEntity;
          CPredictionCopy::ReportFieldsDiffer(
            this: v80,
            pCurrentMap,
            pField: v9,
            fmt: "EHandles differ (net) 0x%p (pred) 0x%p\n",
            v49,
            v47);
        }
        v50 = *(_DWORD *)v10;
        if ( v50 != -1
          && (v51 = (unsigned __int16)v50,
              v52 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v50],
              v53 = HIWORD(v50),
              v52->m_SerialNumber == v53)
          && (v54 = (C_BaseEntity *)v52->m_pEntity, dt = (CPredictionCopy::difftype_t)v54, v54 != nullptr) )
        {
          Classname = C_BaseEntity::GetClassname(this: v54);
          if ( *Classname == 0 )
          {
            v56 = (type_info *)__RTtypeid(inptr: (_DWORD *)dt);
            Classname = (char *)type_info::name(this: v56, __ptype_info_node: &__type_info_root_node);
          }
          v57 = v51;
          if ( g_pEntityList->m_EntPtrArray[v57].m_SerialNumber == v53 )
            v58 = g_pEntityList->m_EntPtrArray[v57].m_pEntity;
          else
            v58 = nullptr;
          CPredictionCopy::OutputFieldDescription(
            this: v80,
            pCurrentMap,
            pField: v9,
            dt: pFieldj,
            fmt: "EHandle (0x%p->%s)",
            v58,
            Classname);
        }
        else
        {
          CPredictionCopy::OutputFieldDescription(
            this: v80,
            pCurrentMap,
            pField: v9,
            dt: pFieldj,
            fmt: "EHandle (NULL)");
        }
        goto LABEL_145;
      default:
        goto LABEL_145;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155F80
// Name: private: void CPredictionCopy::TransferDataErrorCheckSpew(char const __near *,struct datamap_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictionCopy::TransferDataErrorCheckSpew(
        CPredictionCopy *this,
        const char *pchOperation,
        const datamap_t *dmap)
{
  int v3; // ebx
  int v4; // esi
  int v5; // edi
  CPredictionCopy *v6; // [esp+Ch] [ebp-4h]

  v3 = this->m_nType + 1;
  v6 = this;
  v4 = 0;
  v5 = 1;
  do
  {
    if ( (v5 & v3) != 0 )
    {
      CPredictionCopy::ErrorCheckFlatFields_Spew(
        this,
        a2: (const char *)v5,
        pCurrentMap: dmap,
        nPredictionCopyType: (const typedescription_t *)v4);
      this = v6;
    }
    ++v4;
    v5 = __ROL4__(v5, 1);
  }
  while ( v4 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x10155FC0
// Name: private: void CPredictionCopy::TransferDataDescribe(char const __near *,struct datamap_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictionCopy::TransferDataDescribe(
        CPredictionCopy *this,
        const char *pchOperation,
        const datamap_t *dmap)
{
  int v3; // ecx
  int v4; // edi
  datamap_t *baseMap; // ecx
  int m_nAllocationCount; // edx
  int m_Size; // eax
  int v8; // esi
  const datamap_t **m_pMemory; // ecx
  int v10; // eax
  const datamap_t **v11; // eax
  const datamap_t **v12; // eax
  CUtlVector<datamap_t const *,CUtlMemory<datamap_t const *,int> > vecGroups; // [esp+Ch] [ebp-20h] BYREF
  CPredictionCopy *v14; // [esp+20h] [ebp-Ch]
  int types; // [esp+24h] [ebp-8h]
  int v16; // [esp+28h] [ebp-4h]

  v14 = this;
  v3 = this->m_nType + 1;
  types = v3;
  v4 = 0;
  v16 = 1;
  while ( 1 )
  {
    if ( (v3 & v16) != 0 )
    {
      baseMap = dmap->baseMap;
      m_nAllocationCount = 0;
      m_Size = 0;
      memset(&vecGroups, 0, sizeof(vecGroups));
      if ( baseMap != nullptr )
      {
        BuildGroupList_R(nPredictionCopyType: v4, nGroup: 1, dmap: baseMap, &vecGroups);
        m_Size = vecGroups.m_Size;
        m_nAllocationCount = vecGroups.m_Memory.m_nAllocationCount;
      }
      v8 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&vecGroups,
          num: m_Size - m_nAllocationCount + 1);
        m_Size = vecGroups.m_Size;
      }
      m_pMemory = vecGroups.m_Memory.m_pMemory;
      vecGroups.m_Size = m_Size + 1;
      v10 = m_Size - v8;
      vecGroups.m_pElements = vecGroups.m_Memory.m_pMemory;
      if ( v10 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&vecGroups.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&vecGroups.m_Memory.m_pMemory[v8],
          count: 4 * v10);
        m_pMemory = vecGroups.m_Memory.m_pMemory;
      }
      v11 = &m_pMemory[v8];
      if ( v11 != nullptr )
        *v11 = dmap;
      CPredictionCopy::DescribeFields(
        this: v14,
        a2: (const char *)v4,
        &vecGroups,
        pCurrentMap: dmap,
        nPredictionCopyType: (const datamap_t *)v4);
      v12 = vecGroups.m_Memory.m_pMemory;
      vecGroups.m_Size = 0;
      if ( vecGroups.m_Memory.m_nGrowSize >= 0 )
      {
        if ( vecGroups.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecGroups.m_Memory.m_pMemory);
          v12 = nullptr;
          vecGroups.m_Memory.m_pMemory = nullptr;
        }
        vecGroups.m_Memory.m_nAllocationCount = 0;
      }
      vecGroups.m_pElements = v12;
      if ( vecGroups.m_Memory.m_nGrowSize >= 0 && v12 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
    }
    ++v4;
    v16 = __ROL4__(v16, 1);
    if ( v4 >= 2 )
      break;
    v3 = types;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101560E0
// Name: public: optimized_datamap_t::optimized_datamap_t(void)
// Source: json
//------------------------------------------------------------------------------
optimized_datamap_t *__thiscall optimized_datamap_t::optimized_datamap_t(optimized_datamap_t *this)
{
  optimized_datamap_t *result; // eax
  int v2; // edi
  int *p_m_nGrowSize; // edx

  result = this;
  v2 = 1;
  p_m_nGrowSize = &this->m_Info[0].m_CopyRuns.m_vecRuns.m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 9) = 0;
    *(p_m_nGrowSize - 8) = 0;
    *(p_m_nGrowSize - 7) = 0;
    *(p_m_nGrowSize - 6) = 0;
    *(p_m_nGrowSize - 5) = 0;
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 12;
    --v2;
  }
  while ( v2 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10156120
// Name: BuildFlattenedChains
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildFlattenedChains(datamap_t *dmap@<esi>)
{
  int v1; // ebx
  optimized_datamap_t *v2; // eax
  optimized_datamap_t *v3; // edi
  int v4; // edi
  int v5; // eax
  optimized_datamap_t *v6; // ecx
  int v7; // edx
  int v8; // edi
  unsigned int v9; // ebx
  flattenedoffsets_t *v10; // edi
  int *v11; // eax
  int nMaxGroupSeen[2]; // [esp+4h] [ebp-14h] BYREF
  int nMaxGroup; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]
  int *v15; // [esp+14h] [ebp-4h]

  v1 = 0;
  if ( dmap->m_pOptimizedDataMap == nullptr )
  {
    v2 = (optimized_datamap_t *)CUtlMemoryPool::AllocZero(this: &g_OptimizedDataMapPool);
    v3 = v2;
    if ( v2 != nullptr )
      optimized_datamap_t::optimized_datamap_t(this: v2);
    dmap->m_pOptimizedDataMap = v3;
    nMaxGroupSeen[0] = 0;
    nMaxGroupSeen[1] = 0;
    v4 = 0;
    v15 = nMaxGroupSeen;
    do
    {
      BuildFlattenedChains_R(
        nPredictionCopyType: v1,
        nMaxGroupSeen: v15++,
        nGroup: 0,
        dmap,
        build: (CUtlVector<typedescription_t,CUtlMemory<typedescription_t,int> > *)((char *)dmap->m_pOptimizedDataMap + v4),
        nBaseOffset: 0);
      v4 += 48;
      ++v1;
    }
    while ( v4 < 96 );
    v5 = 0;
    v14 = 0;
    v15 = nMaxGroupSeen;
    do
    {
      nMaxGroup = *v15;
      v6 = (optimized_datamap_t *)((char *)dmap->m_pOptimizedDataMap + v5);
      v7 = 0;
      if ( v6->m_Info[0].m_Flat.m_Flattened.m_Size > 0 )
      {
        v8 = 0;
        do
        {
          ++v7;
          v6->m_Info[0].m_Flat.m_Flattened.m_Memory.m_pMemory[v8].flatGroup = nMaxGroup
                                                                            - v6->m_Info[0].m_Flat.m_Flattened.m_Memory.m_pMemory[v8].flatGroup;
          ++v8;
        }
        while ( v7 < v6->m_Info[0].m_Flat.m_Flattened.m_Size );
        v5 = v14;
      }
      ++v15;
      v5 += 48;
      v14 = v5;
    }
    while ( v5 < 96 );
    v9 = 0;
    v15 = nullptr;
    do
    {
      v10 = (flattenedoffsets_t *)((char *)v15 + (unsigned int)dmap->m_pOptimizedDataMap);
      qsort(
        base: v10->m_Flattened.m_Memory.m_pMemory,
        num: v10->m_Flattened.m_Size,
        width: 0x3Cu,
        comp: (int (__cdecl *)(const void *, const void *))CompareFlattenedOffsets);
      v9 = BuildPackedFlattenedOffsets(a1: v10, nStartOffset: v9);
      v11 = v15 + 12;
      dmap->m_nPackedSize = v9;
      v15 = v11;
    }
    while ( (int)v11 < 96 );
    BuildDataRuns(dmap);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156230
// Name: public: static bool CPredictionCopy::PrepareDataMap(struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CPredictionCopy::PrepareDataMap(datamap_t *dmap)
{
  char result; // al

  result = 0;
  if ( dmap != nullptr && dmap->m_pOptimizedDataMap == nullptr )
  {
    BuildFlattenedChains(dmap);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10156260
// Name: cl_predictioncopy_describe
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_predictioncopy_describe(const CCommand *args)
{
  int v1; // esi
  C_BaseEntity *v2; // eax
  datamap_t *v3; // eax
  const datamap_t *v4; // esi
  int i; // edi

  if ( args->m_nArgc > 1 )
  {
    v1 = V_atoi(str: args->m_ppArgv[1]);
    v2 = C_BaseEntity::Instance(iEnt: v1);
    if ( v2 != nullptr )
    {
      v3 = v2->GetPredDescMap(this: v2);
      v4 = v3;
      if ( v3 != nullptr )
      {
        if ( v3->m_pOptimizedDataMap == nullptr )
          BuildFlattenedChains(dmap: v3);
        for ( i = 0; i < 2; ++i )
          DescribeFlattenedList(dmap: v4, nPredictionCopyType: i, packType: 0);
      }
    }
    else
    {
      _Msg(a1: "cl_predictioncopy_describe:  no such entity %d\n", v1);
    }
  }
  else if ( args->m_nArgc > 0 )
  {
    _Msg(a1: "Usage:  %s <entindex>", args->m_ppArgv[0]);
  }
  else
  {
    _Msg(a1: "Usage:  %s <entindex>", prType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156310
// Name: public: static struct typedescription_t const __near * CPredictionCopy::FindFlatFieldByName(char const __near *,struct datamap_t const __near *)
// Source: json
//------------------------------------------------------------------------------
const typedescription_t *__cdecl CPredictionCopy::FindFlatFieldByName(const char *fieldname, datamap_t *dmap)
{
  datamap_t *v2; // edi
  int v3; // ecx
  optimized_datamap_t *m_pOptimizedDataMap; // ebx
  int v5; // eax
  optimized_datamap_t *v6; // ebx
  int v7; // esi
  typedescription_t *v8; // edi
  int c; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]

  v2 = dmap;
  if ( dmap != nullptr && dmap->m_pOptimizedDataMap == nullptr )
    BuildFlattenedChains(dmap);
  v3 = 0;
  v11 = 0;
  while ( 1 )
  {
    m_pOptimizedDataMap = v2->m_pOptimizedDataMap;
    v5 = *(int *)((char *)&m_pOptimizedDataMap->m_Info[0].m_Flat.m_Flattened.m_Size + v3);
    v6 = (optimized_datamap_t *)((char *)m_pOptimizedDataMap + v3);
    v7 = 0;
    c = v5;
    if ( v5 > 0 )
      break;
LABEL_10:
    v3 += 48;
    v11 = v3;
    if ( v3 >= 96 )
      return nullptr;
  }
  v12 = 0;
  while ( 1 )
  {
    v8 = &v6->m_Info[0].m_Flat.m_Flattened.m_Memory.m_pMemory[v12];
    if ( _V_stricmp(s1: v8->fieldName, s2: fieldname) == 0 )
      return v8;
    ++v12;
    if ( ++v7 >= c )
    {
      v2 = dmap;
      v3 = v11;
      goto LABEL_10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156390
// Name: private: void CPredictionCopy::DetermineWatchField(char const __near *,int,struct datamap_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictionCopy::DetermineWatchField(
        CPredictionCopy *this,
        const char *operation,
        int entindex,
        datamap_t *dmap)
{
  int m_nValue; // eax
  char *v5; // eax
  char *m_pszString; // eax

  this->m_pWatchField = nullptr;
  this->m_pOperation = operation;
  if ( operation != nullptr && *operation != 0 )
  {
    if ( pwatchent.m_pParent != nullptr )
    {
      m_nValue = pwatchent.m_pParent->m_Value.m_nValue;
      if ( m_nValue < 0 )
        return;
    }
    else
    {
      m_nValue = 0;
    }
    if ( entindex == m_nValue
      && ((pwatchvar.m_nFlags & 0x1000) != 0 || (v5 = pwatchvar.m_pParent->m_Value.m_pszString) != nullptr && *v5 != 0) )
    {
      if ( (pwatchvar.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = pwatchvar.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)prType;
      }
      this->m_pWatchField = CPredictionCopy::FindFlatFieldByName(fieldname: m_pszString, dmap);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156420
// Name: public: int CPredictionCopy::TransferData(char const __near *,int,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPredictionCopy::TransferData(
        CPredictionCopy *this,
        const char *operation,
        int entindex,
        datamap_t *dmap)
{
  const typedescription_t *m_pWatchField; // eax

  this->m_nEntIndex = entindex;
  if ( dmap != nullptr && dmap->m_pOptimizedDataMap == nullptr )
    BuildFlattenedChains(dmap);
  switch ( this->m_OpType )
  {
    case TRANSFERDATA_ERRORCHECK_NOSPEW:
      CPredictionCopy::TransferDataErrorCheckNoSpew(this, a2: (const char *)this, pchOperation: operation, dmap);
      break;
    case TRANSFERDATA_ERRORCHECK_SPEW:
      CPredictionCopy::TransferDataErrorCheckSpew(this, pchOperation: operation, dmap);
      break;
    case TRANSFERDATA_ERRORCHECK_DESCRIBE:
      CPredictionCopy::TransferDataDescribe(this, pchOperation: operation, dmap);
      break;
    default:
      CPredictionCopy::DetermineWatchField(this, operation, entindex, dmap);
      CPredictionCopy::TransferDataCopyOnly(this, dmap);
      break;
  }
  m_pWatchField = this->m_pWatchField;
  if ( m_pWatchField != nullptr )
    CPredictionCopy::DumpWatchField(
      this,
      pField: m_pWatchField,
      outvalue: &this->m_pDest[m_pWatchField->flatOffset[this->m_nDestOffsetIndex]],
      count: m_pWatchField->fieldSize);
  return this->m_nErrorCount;
}

//------------------------------------------------------------------------------
// Address: 0x10169130
// Name: struct datamap_t __near * DataMapInit<struct entitytable_t>(struct entitytable_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<entitytable_t>()
{
  if ( (_S5_114 & 1) == 0 )
  {
    _S5_114 |= 1u;
    nameHolder_17.m_pszBase = "entitytable_t";
    nameHolder_17.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_17.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_17.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_17.m_Names.m_Size = 0;
    nameHolder_17.m_Names.m_pElements = nullptr;
    nameHolder_17.m_nLenBase = 13;
    atexit(func: DataMapInit_entitytable_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  entitytable_t::m_DataMap.baseMap = nullptr;
  entitytable_t::m_DataMap.dataNumFields = 10;
  entitytable_t::m_DataMap.dataDesc = &dataDesc_16[1];
  return &entitytable_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101693F0
// Name: struct datamap_t __near * DataMapInit<struct SaveRestoreBlockHeader_t>(struct SaveRestoreBlockHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SaveRestoreBlockHeader_t>()
{
  if ( (_S6_37 & 1) == 0 )
  {
    _S6_37 |= 1u;
    nameHolder_18.m_pszBase = "SaveRestoreBlockHeader_t";
    nameHolder_18.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_18.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_18.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_18.m_Names.m_Size = 0;
    nameHolder_18.m_Names.m_pElements = nullptr;
    nameHolder_18.m_nLenBase = 24;
    atexit(func: DataMapInit_SaveRestoreBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SaveRestoreBlockHeader_t::m_DataMap.baseMap = nullptr;
  SaveRestoreBlockHeader_t::m_DataMap.dataNumFields = 3;
  SaveRestoreBlockHeader_t::m_DataMap.dataDesc = &dataDesc_17[1];
  return &SaveRestoreBlockHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016E3B0
// Name: struct datamap_t __near * DataMapInit<struct SoundCommand_t>(struct SoundCommand_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SoundCommand_t>()
{
  if ( (_S8_9 & 1) == 0 )
  {
    _S8_9 |= 1u;
    nameHolder_28.m_pszBase = "SoundCommand_t";
    nameHolder_28.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_28.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_28.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_28.m_Names.m_Size = 0;
    nameHolder_28.m_Names.m_pElements = nullptr;
    nameHolder_28.m_nLenBase = 14;
    atexit(func: DataMapInit_SoundCommand_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SoundCommand_t::m_DataMap.baseMap = nullptr;
  SoundCommand_t::m_DataMap.dataNumFields = 4;
  SoundCommand_t::m_DataMap.dataDesc = &dataDesc_27[1];
  return &SoundCommand_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10171A70
// Name: struct datamap_t __near * DataMapInit<struct TrailPoint_t>(struct TrailPoint_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<TrailPoint_t>()
{
  if ( (_S5_119 & 1) == 0 )
  {
    _S5_119 |= 1u;
    nameHolder_29.m_pszBase = "TrailPoint_t";
    nameHolder_29.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_29.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_29.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_29.m_Names.m_Size = 0;
    nameHolder_29.m_Names.m_pElements = nullptr;
    nameHolder_29.m_nLenBase = 12;
    atexit(func: DataMapInit_TrailPoint_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  TrailPoint_t::m_DataMap.baseMap = nullptr;
  TrailPoint_t::m_DataMap.dataNumFields = 4;
  TrailPoint_t::m_DataMap.dataDesc = &dataDesc_28[1];
  return &TrailPoint_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017F620
// Name: struct datamap_t __near * DataMapInit<struct ViewSmoothingData_t>(struct ViewSmoothingData_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ViewSmoothingData_t>()
{
  if ( (_S5_123 & 1) == 0 )
  {
    _S5_123 |= 1u;
    nameHolder_35.m_pszBase = "ViewSmoothingData_t";
    nameHolder_35.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_35.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_35.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_35.m_Names.m_Size = 0;
    nameHolder_35.m_Names.m_pElements = nullptr;
    nameHolder_35.m_nLenBase = 19;
    atexit(func: DataMapInit_ViewSmoothingData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ViewSmoothingData_t::m_DataMap.baseMap = nullptr;
  ViewSmoothingData_t::m_DataMap.dataNumFields = 9;
  ViewSmoothingData_t::m_DataMap.dataDesc = &dataDesc_33[1];
  return &ViewSmoothingData_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10192CA0
// Name: struct datamap_t __near * DataMapInit<struct screenfade_t>(struct screenfade_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<screenfade_t>()
{
  if ( (_S6_47 & 1) == 0 )
  {
    _S6_47 |= 1u;
    nameHolder_36.m_pszBase = "screenfade_t";
    nameHolder_36.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_36.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_36.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_36.m_Names.m_Size = 0;
    nameHolder_36.m_Names.m_pElements = nullptr;
    nameHolder_36.m_nLenBase = 12;
    atexit(func: DataMapInit_screenfade_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  screenfade_t::m_DataMap.baseMap = nullptr;
  screenfade_t::m_DataMap.dataNumFields = 8;
  screenfade_t::m_DataMap.dataDesc = &dataDesc_34[1];
  return &screenfade_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10192D20
// Name: struct datamap_t __near * DataMapInit<struct screenshake_t>(struct screenshake_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<screenshake_t>()
{
  if ( (_S7_19 & 1) == 0 )
  {
    _S7_19 |= 1u;
    nameHolder_37.m_pszBase = "screenshake_t";
    nameHolder_37.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_37.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_37.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_37.m_Names.m_Size = 0;
    nameHolder_37.m_Names.m_pElements = nullptr;
    nameHolder_37.m_nLenBase = 13;
    atexit(func: DataMapInit_screenshake_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  screenshake_t::m_DataMap.baseMap = nullptr;
  screenshake_t::m_DataMap.dataNumFields = 9;
  screenshake_t::m_DataMap.dataDesc = &dataDesc_35[1];
  return &screenshake_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10192DA0
// Name: struct datamap_t __near * DataMapInit<struct screentilt_t>(struct screentilt_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<screentilt_t>()
{
  if ( (_S8_12 & 1) == 0 )
  {
    _S8_12 |= 1u;
    nameHolder_38.m_pszBase = "screentilt_t";
    nameHolder_38.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_38.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_38.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_38.m_Names.m_Size = 0;
    nameHolder_38.m_Names.m_pElements = nullptr;
    nameHolder_38.m_nLenBase = 12;
    atexit(func: DataMapInit_screentilt_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  screentilt_t::m_DataMap.baseMap = nullptr;
  screentilt_t::m_DataMap.dataNumFields = 6;
  screentilt_t::m_DataMap.dataDesc = &dataDesc_36[1];
  return &screentilt_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10047780
// Name: _C_BaseFlex_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseFlex_CreateObject(int entnum, int serialNum)
{
  C_BaseFlex *v2; // eax
  C_BaseFlex *v3; // eax
  C_BaseFlex *v4; // esi

  v2 = (C_BaseFlex *)C_BaseEntity::operator new(stAllocateBlock: 0x10A0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseFlex::C_BaseFlex(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10171AF0
// Name: struct datamap_t __near * DataMapInit<class C_SpriteTrail>(class C_SpriteTrail __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<C_SpriteTrail>()
{
  if ( (_S6_41 & 1) == 0 )
  {
    _S6_41 |= 1u;
    nameHolder_30.m_pszBase = "C_SpriteTrail";
    nameHolder_30.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_30.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_30.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_30.m_Names.m_Size = 0;
    nameHolder_30.m_Names.m_pElements = nullptr;
    nameHolder_30.m_nLenBase = 13;
    atexit(func: DataMapInit_C_SpriteTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  C_SpriteTrail::m_DataMap.baseMap = &C_BaseEntity::m_DataMap;
  C_SpriteTrail::m_DataMap.dataNumFields = 18;
  C_SpriteTrail::m_DataMap.dataDesc = &dataDesc_29[1];
  return &C_SpriteTrail::m_DataMap;
}
