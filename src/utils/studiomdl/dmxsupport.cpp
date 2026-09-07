// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/dmxsupport.cpp
// Functions: 229
// ============================================================

#include "utils\studiomdl\dmxsupport.h"

//------------------------------------------------------------------------------
// Address: 0x00406CF0
// Name: bool IsPowerOfTwo(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsPowerOfTwo(int value)
{
  return (value & (value - 1)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406D10
// Name: public: void CChangeUndoScopeGuard::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeUndoScopeGuard::Release(CChangeUndoScopeGuard *this)
{
  bool v2; // zf

  if ( !this->m_bReleased )
  {
    (*(void (__stdcall **)(bool))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(a1: this->m_bOldValue);
    v2 = !this->m_bNotify;
    this->m_bReleased = true;
    if ( !v2 )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
        a1: g_pDataModel.u,
        a2: 0);
      this->m_bNotify = false;
    }
    if ( this->m_pNotify != nullptr )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: this->m_pNotify);
      this->m_pNotify = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406D70
// Name: bool ShouldTraverse(class CDmAttribute const __near *,enum TraversalDepth_t)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldTraverse(const CDmAttribute *pAttr, TraversalDepth_t depth)
{
  switch ( depth )
  {
    case TD_ALL:
      return 1;
    case TD_DEEP:
      return (pAttr->m_nFlags & 0x1000) == 0;
    case TD_SHALLOW:
      if ( (pAttr->m_nFlags & 0x800) == 0 )
        return 0;
      return (pAttr->m_nFlags & 0x1000) == 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406DC0
// Name: public: char const __near * CDmElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmElement::GetTypeString(CDmElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return pDeltaStateName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406DD0
// Name: public: s_tmpface_t::s_tmpface_t(void)
// Source: json
//------------------------------------------------------------------------------
s_tmpface_t *__thiscall s_tmpface_t::s_tmpface_t(s_tmpface_t *this)
{
  this->d = -1;
  this->c = -1;
  this->b = -1;
  this->a = -1;
  this->td = -1;
  this->tc = -1;
  this->tb = -1;
  this->ta = -1;
  this->nd = -1;
  this->nc = -1;
  this->nb = -1;
  this->na = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406E00
// Name: public: void CLodScriptReplacement_t::SetSrcName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLodScriptReplacement_t::SetSrcName(CLodScriptReplacement_t *this, const char *pSrcName)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al

  if ( this->m_pSrcName != nullptr )
    free(pMem: this->m_pSrcName);
  v3 = (char *)MemAlloc_Alloc(nSize: strlen(pSrcName) + 1);
  v4 = pSrcName;
  this->m_pSrcName = v3;
  v5 = v3;
  do
  {
    v6 = *v4;
    *v5++ = *v4++;
  }
  while ( v6 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00406E50
// Name: public: void CLodScriptReplacement_t::SetDstName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLodScriptReplacement_t::SetDstName(CLodScriptReplacement_t *this, const char *pDstName)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al

  if ( this->m_pDstName != nullptr )
    free(pMem: this->m_pDstName);
  v3 = (char *)MemAlloc_Alloc(nSize: strlen(pDstName) + 1);
  v4 = pDstName;
  this->m_pDstName = v3;
  v5 = v3;
  do
  {
    v6 = *v4;
    *v5++ = *v4++;
  }
  while ( v6 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00406EA0
// Name: VertexLookup_CompareFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VertexLookup_CompareFunc(const VertexLookup_t *a, const VertexLookup_t *b)
{
  return a->v == b->v && a->n == b->n && a->t == b->t;
}

//------------------------------------------------------------------------------
// Address: 0x00406ED0
// Name: VertexLookup_KeyFunc
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl VertexLookup_KeyFunc(const VertexLookup_t *a)
{
  return Hash12(pKey: a);
}

//------------------------------------------------------------------------------
// Address: 0x00406EE0
// Name: AllocateDmxSource
// Source: json
//------------------------------------------------------------------------------
s_source_t *__cdecl AllocateDmxSource(const char *pSourceName)
{
  s_source_t *v1; // esi
  int v2; // eax

  v1 = (s_source_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 202400);
  memset(dst: (unsigned __int8 *)v1, value: 0, count: sizeof(s_source_t));
  v2 = g_numsources;
  g_source[g_numsources] = v1;
  g_numsources = v2 + 1;
  V_strncpy(pDest: v1->filename, pSrc: pSourceName, maxLen: 260);
  V_SetExtension(path: v1->filename, extension: "dmx", pathStringLength: 260);
  v1->adjust = g_defaultadjust;
  v1->scale = 1.0;
  v1->rotation = g_defaultrotation;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00406FA0
// Name: int FindWeightList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindWeightList(const char *pWeightListName)
{
  int v1; // esi
  s_weightlist_t *i; // edi

  v1 = 0;
  if ( g_numweightlist <= 0 )
    return -1;
  for ( i = g_weightlist; _V_stricmp(s1: pWeightListName, s2: i->name) != 0; ++i )
  {
    if ( ++v1 >= g_numweightlist )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x004071B0
// Name: public: class Quaternion const __near & CDmAttribute::GetValue<class Quaternion>(class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
const Quaternion *__thiscall CDmAttribute::GetValue<Quaternion>(CDmAttribute *this, const Quaternion *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0xD )
    return (const Quaternion *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<Quaternion>(this) )
    return defaultValue;
  if ( (`CDmAttribute::GetValue<Quaternion>'::`7'::`local static guard' & 1) == 0 )
    `CDmAttribute::GetValue<Quaternion>'::`7'::`local static guard' |= 1u;
  CDmAttribute::CopyDataOut<Quaternion>(this, value: &`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal);
  return &`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x004072B0
// Name: float RemapValClamped(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapValClamped(float val, float A, float B, float C, float D)
{
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( A == B )
  {
    if ( (float)(val - B) < 0.0 )
      return C;
    else
      return D;
  }
  else
  {
    v6 = (float)(val - A) / (float)(B - A);
    v7 = 0.0;
    if ( v6 < 0.0 )
      return C + (D - C) * v7;
    v7 = 1.0;
    if ( v6 > 1.0 )
      return C + (D - C) * v7;
    else
      return C + (D - C) * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407350
// Name: public: CDisableUndoScopeGuard::CDisableUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
CDisableUndoScopeGuard *__thiscall CDisableUndoScopeGuard::CDisableUndoScopeGuard(CDisableUndoScopeGuard *this)
{
  *(_WORD *)&this->m_bReleased = 0;
  this->m_pNotify = nullptr;
  this->m_bOldValue = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00407390
// Name: public: int CDmrElementArray<class CDmElement>::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmrElementArray<CDmElement>::Count(CDmrElementArray<CDmElement> *this)
{
  if ( this->m_pAttribute != nullptr )
    return this->m_pStorage->m_Size;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004073A0
// Name: public: class CUtlSymbolLarge const __near & CDmAttribute::GetValue<class CUtlSymbolLarge>(void)const
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__thiscall CDmAttribute::GetValue<CUtlSymbolLarge>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  if ( (this->m_nFlags & 0x1F) == 5 )
    return (DmElementHandle_t *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<CUtlSymbolLarge>(this) )
    return (DmElementHandle_t *)&`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal = DMELEMENT_HANDLE_INVALID;
  }
  CDmAttribute::CopyDataOut<enum DmElementHandle_t>(
    this,
    value: &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal);
  return &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x00407450
// Name: public: float const __near & CDmAttribute::GetValue<float>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<float> *__thiscall CDmAttribute::GetValue<float>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 3 )
    return (CDmaVar<float> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<bool>(this) )
    return &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
  CDmAttribute::CopyDataOut<float>(this, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
  return (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x004074B0
// Name: public: class CDmElement __near * CAttributeReferenceIterator::FilterReference<class CDmElement>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CAttributeReferenceIterator::FilterReference<CDmElement>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmElement *result; // eax
  CDmElement *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_1;
    case TD_DEEP:
      goto $LN11;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_1:
      v7 = *(CDmElement **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmElement::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004075A0
// Name: public: bool const __near & CDmAttribute::GetValue<bool>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<bool> *__thiscall CDmAttribute::GetValue<bool>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<bool>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
  }
  if ( (this->m_nFlags & 0x1F) == 4 )
    return (CDmaVar<bool> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<bool>(this) )
    return &`CDmAttribute::GetValue<bool>'::`2'::defaultVal;
  CDmAttribute::CopyDataOut<bool>(this, value: &`CDmAttribute::GetValue<bool>'::`7'::tempVal);
  return (CDmaVar<bool> *)&`CDmAttribute::GetValue<bool>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x00407600
// Name: public: int const __near & CDmAttribute::GetValue<int>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CDmAttribute::GetValue<int>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (this->m_nFlags & 0x1F) == 2 )
    return (CDmaVar<int> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<bool>(this) )
    return &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  CDmAttribute::CopyDataOut<int>(this, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
  return (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x00407660
// Name: public: class Quaternion const __near & CDmAttribute::GetValue<class Quaternion>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmAttribute::GetValue<Quaternion>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xD )
    return (CDmaVar<Quaternion> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<Quaternion>(this) )
    return &`CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal;
  if ( (`CDmAttribute::GetValue<Quaternion>'::`7'::`local static guard' & 1) == 0 )
    `CDmAttribute::GetValue<Quaternion>'::`7'::`local static guard' |= 1u;
  CDmAttribute::CopyDataOut<Quaternion>(this, value: &`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal);
  return (CDmaVar<Quaternion> *)&`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x004076F0
// Name: public: class Vector const __near & CDmAttribute::GetValue<class Vector>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmAttribute::GetValue<Vector>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xA )
    return (CDmaVar<Vector> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<Vector>(this) )
    return &`CDmAttribute::GetValue<Vector>'::`2'::defaultVal;
  if ( (`CDmAttribute::GetValue<Vector>'::`7'::`local static guard' & 1) == 0 )
    `CDmAttribute::GetValue<Vector>'::`7'::`local static guard' |= 1u;
  CDmAttribute::CopyDataOut<Vector>(this, value: &`CDmAttribute::GetValue<Vector>'::`7'::tempVal);
  return (CDmaVar<Vector> *)&`CDmAttribute::GetValue<Vector>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x00407BA0
// Name: public: enum DmElementHandle_t const __near & CDmAttribute::GetValue<enum DmElementHandle_t>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CDmAttribute::GetValue<enum DmElementHandle_t>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  if ( (this->m_nFlags & 0x1F) == 1 )
    return (CDmaVar<enum DmElementHandle_t> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<enum DmElementHandle_t>(this) )
    return &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  CDmAttribute::CopyDataOut<enum DmElementHandle_t>(
    this,
    value: &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`7'::tempVal);
  return (CDmaVar<enum DmElementHandle_t> *)&`CDmAttribute::GetValue<enum DmElementHandle_t>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x00407D30
// Name: BuildVertexAnimations
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVertexAnimations(s_source_t *pSource)
{
  int m_Size; // esi
  DeltaState_t *v2; // esi
  const char *v3; // eax
  s_sourceanim_t *v4; // ebx
  int m_nFirstDelta; // edx
  int v6; // eax
  DeltaIndex_t *m_pMemory; // edi
  int v8; // edx
  VertIndices_t *v9; // eax
  v_unify_t *v10; // esi
  unsigned __int8 *v11; // eax
  int m_nPositionIndex; // ecx
  Vector *v13; // ebx
  int v14; // ecx
  double x; // st7
  Vector *v16; // ecx
  int m_nNormalIndex; // ecx
  Vector *v18; // ebx
  int v19; // ecx
  double v20; // st7
  Vector *v21; // ecx
  int m_nWrinkleIndex; // ecx
  unsigned int v23; // esi
  unsigned __int8 *v24; // edi
  s_sourceanim_t *pSourceAnim; // [esp+8h] [ebp-20h]
  int i; // [esp+Ch] [ebp-1Ch]
  VertIndices_t *uniqueVert; // [esp+10h] [ebp-18h]
  unsigned __int8 *v28; // [esp+14h] [ebp-14h]
  unsigned __int8 *pVertAnim; // [esp+18h] [ebp-10h]
  int v30; // [esp+1Ch] [ebp-Ch]
  int nVertAnimCount; // [esp+20h] [ebp-8h]
  DeltaState_t *state; // [esp+24h] [ebp-4h]

  m_Size = s_DeltaStates.m_Size;
  if ( s_DeltaStates.m_Size != 0 )
  {
    pVertAnim = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 40 * g_numvlist);
    if ( m_Size > 0 )
    {
      v30 = 0;
      for ( i = m_Size; i != 0; --i )
      {
        v2 = &s_DeltaStates.m_Memory.m_pMemory[v30];
        state = &s_DeltaStates.m_Memory.m_pMemory[v30];
        v3 = CUtlString::operator char const *(this: &s_DeltaStates.m_Memory.m_pMemory[v30].m_Name);
        v4 = FindOrAddSourceAnim(pSource, pAnimName: v3);
        v4->numframes = 1;
        v4->startframe = 0;
        v4->endframe = 0;
        v4->newStyleVertexAnimations = true;
        m_nFirstDelta = v2->m_nFirstDelta;
        v6 = 0;
        pSourceAnim = v4;
        nVertAnimCount = 0;
        if ( m_nFirstDelta >= 0 )
        {
          while ( 1 )
          {
            m_pMemory = v2->m_DeltaIndices.m_Memory.m_pMemory;
            v8 = m_nFirstDelta;
            v9 = &s_UniqueVertices.m_Memory.m_pMemory[v8];
            v10 = v_list[s_UniqueVertices.m_Memory.m_pMemory[v8].v];
            uniqueVert = &s_UniqueVertices.m_Memory.m_pMemory[v8];
            if ( v10 != nullptr )
            {
              v28 = &pVertAnim[40 * nVertAnimCount];
              do
              {
                if ( v10->n == v9->n && v10->t == v9->t )
                {
                  v11 = v28;
                  ++nVertAnimCount;
                  v28 += 40;
                  *(_DWORD *)v11 = v10 - v_listdata;
                  *((float *)v11 + 1) = s_Speed.m_Memory.m_pMemory[s_UniqueVertices.m_Memory.m_pMemory[v8].speed];
                  *((float *)v11 + 2) = s_Balance.m_Memory.m_pMemory[s_UniqueVertices.m_Memory.m_pMemory[v8].balance];
                  m_nPositionIndex = m_pMemory[v8].m_nPositionIndex;
                  if ( m_nPositionIndex < 0 )
                  {
                    *((Vector *)v11 + 1) = vec3_origin;
                  }
                  else
                  {
                    v13 = state->m_PositionDeltas.m_Memory.m_pMemory;
                    v14 = m_nPositionIndex;
                    x = v13[v14].x;
                    v16 = &v13[v14];
                    *((float *)v11 + 3) = x;
                    *((float *)v11 + 4) = v16->y;
                    *((float *)v11 + 5) = v16->z;
                  }
                  m_nNormalIndex = m_pMemory[v8].m_nNormalIndex;
                  if ( m_nNormalIndex < 0 )
                  {
                    *((Vector *)v11 + 2) = vec3_origin;
                  }
                  else
                  {
                    v18 = state->m_NormalDeltas.m_Memory.m_pMemory;
                    v19 = m_nNormalIndex;
                    v20 = v18[v19].x;
                    v21 = &v18[v19];
                    *((float *)v11 + 6) = v20;
                    *((float *)v11 + 7) = v21->y;
                    *((float *)v11 + 8) = v21->z;
                  }
                  m_nWrinkleIndex = m_pMemory[v8].m_nWrinkleIndex;
                  if ( m_nWrinkleIndex < 0 )
                    *((_DWORD *)v11 + 9) = 0;
                  else
                    *((float *)v11 + 9) = state->m_WrinkleDeltas.m_Memory.m_pMemory[m_nWrinkleIndex];
                  v9 = uniqueVert;
                }
                v10 = v10->next;
              }
              while ( v10 != nullptr );
              v4 = pSourceAnim;
            }
            m_nFirstDelta = state->m_DeltaIndices.m_Memory.m_pMemory[v8].m_nNextDelta;
            if ( m_nFirstDelta < 0 )
              break;
            v2 = state;
          }
          v6 = nVertAnimCount;
        }
        v4->numvanims[0] = v6;
        v23 = 40 * v6;
        v24 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 40 * v6);
        memset(dst: v24, value: 0, count: v23);
        v4->vanim[0] = (s_vertanim_t *)v24;
        memcpy(dst: v24, src: pVertAnim, count: v23);
        ++v30;
      }
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pVertAnim);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407FD0
// Name: HandleDmeJiggleBone
// Source: json
//------------------------------------------------------------------------------
void __usercall HandleDmeJiggleBone(const CDmeDag *pDmeDag@<edi>)
{
  int v1; // eax
  int v2; // esi
  char *bonename; // ebx
  s_jigglebone_t *v4; // esi
  mstudiojigglebone_t *p_data; // ebx
  int v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  char *s1; // [esp+8h] [ebp-4h]

  if ( pDmeDag != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pDmeDag->IsA)(
         a1: (struct CDmeDag *)pDmeDag,
         a2: (CUtlSymbolLarge)CDmeJiggleBone::m_classType.u.m_Id) )
  {
    s1 = (char *)pDeltaStateName;
    if ( pDmeDag->m_Name.m_Storage.u.CDmElement::m_Id != -1 )
      s1 = (char *)pDmeDag->m_Name.m_Storage.u.CDmElement::m_Id;
    v1 = g_numjigglebones;
    v2 = 0;
    if ( g_numjigglebones <= 0 )
    {
LABEL_9:
      g_numjigglebones = v1 + 1;
      v4 = &g_jigglebones[v1];
      V_strncpy(pDest: v4->bonename, pSrc: s1, maxLen: 128);
      p_data = &v4->data;
      memset(dst: (unsigned __int8 *)&v4->data, value: 0, count: sizeof(v4->data));
      v4->data.baseMinUp = -100.0;
      v4->data.baseMinLeft = -100.0;
      v4->data.baseMinForward = -100.0;
      v4->data.yawStiffness = 100.0;
      v4->data.pitchStiffness = 100.0;
      v4->data.alongStiffness = 100.0;
      v4->data.baseStiffness = 100.0;
      v4->data.baseMaxUp = 100.0;
      v4->data.baseMaxLeft = 100.0;
      v4->data.baseMaxForward = 100.0;
      v4->data.length = 10.0;
      v4->data.length = *((float *)&pDmeDag[1].CDmElement + 15);
      v4->data.tipMass = *(float *)&pDmeDag[1].m_Visible.m_Storage;
      v4->data.flags |= LOBYTE(pDmeDag[1].m_ref.m_attributes.m_pNext) != 0 ? 0x20 : 0;
      v4->data.angleLimit = *(float *)&pDmeDag[1].m_bDisableOverrideParent.m_Storage * 0.017453292;
      v4->data.flags |= LOBYTE(pDmeDag[1].m_ref.m_hElement) != 0 ? 4 : 0;
      v4->data.minYaw = *(float *)&pDmeDag[1].m_Transform.m_Storage.m_Handle * 0.017453292;
      v4->data.maxYaw = *(float *)&pDmeDag[1].m_Transform.m_pAttribute * 0.017453292;
      v4->data.yawFriction = *(float *)&pDmeDag[1].m_Shape.m_Storage.m_ElementType.u.m_Id;
      v4->data.yawBounce = *(float *)&pDmeDag[1].m_Children.m_Storage.m_Memory.m_pMemory;
      v4->data.flags |= LOBYTE(pDmeDag[1].m_Type.u.CDmElement::m_Id) != 0 ? 0x10 : 0;
      v4->data.minPitch = *(float *)&pDmeDag[1].m_Children.m_Storage.m_Memory.m_nGrowSize * 0.017453292;
      v6 = 0;
      v4->data.maxPitch = *(float *)&pDmeDag[1].m_Children.m_Storage.m_pElements * 0.017453292;
      v4->data.pitchFriction = *(float *)&pDmeDag[1].m_Children.m_pAttribute;
      v4->data.pitchBounce = *(float *)pDmeDag[2].m_Id.m_Value;
      if ( pDmeDag[1].m_Id.m_Value[8] != 0 )
      {
        if ( pDmeDag[1].m_Id.m_Value[0] != 0 )
        {
          MdlWarning(fmt: "2001: Jiggle Bone %s: Both flexible and rigid set, ignoring rigid\n", s1);
          v6 = 0;
        }
        p_data->flags |= 1u;
        p_data->flags |= *((_BYTE *)&pDmeDag[1].m_ref + 8) != 0 ? 8 : 0;
        v7 = *(float *)&pDmeDag[2].m_Id.m_Value[8];
        if ( v7 >= 0.0 )
        {
          if ( v7 > 1000.0 )
            v7 = 1000.0;
        }
        else
        {
          v7 = 0.0;
        }
        v4->data.yawStiffness = v7;
        v8 = *(float *)&pDmeDag[2].m_Name.m_Storage.u.CDmElement::m_Id;
        if ( v8 >= 0.0 )
        {
          if ( v8 > 10.0 )
            v8 = 10.0;
        }
        else
        {
          v8 = 0.0;
        }
        v4->data.yawDamping = v8;
        v9 = *(float *)&pDmeDag[2].m_ref.m_hElement;
        if ( v9 >= 0.0 )
        {
          if ( v9 > 1000.0 )
            v9 = 1000.0;
        }
        else
        {
          v9 = 0.0;
        }
        v4->data.pitchStiffness = v9;
        v10 = *((float *)&pDmeDag[2].m_ref + 2);
        if ( v10 >= 0.0 )
        {
          if ( v10 > 10.0 )
            v10 = 10.0;
        }
        else
        {
          v10 = 0.0;
        }
        v4->data.pitchDamping = v10;
        v11 = *(float *)&pDmeDag[2].m_ref.m_attributes.m_pNext;
        if ( v11 >= 0.0 )
        {
          if ( v11 > 1000.0 )
            v11 = 1000.0;
        }
        else
        {
          v11 = 0.0;
        }
        v4->data.alongStiffness = v11;
        v12 = *(float *)&pDmeDag[2].m_Type.u.CDmElement::m_Id;
        if ( v12 >= 0.0 )
        {
          if ( v12 > 10.0 )
            v12 = 10.0;
          v4->data.alongDamping = v12;
        }
        else
        {
          v4->data.alongDamping = 0.0;
        }
      }
      else if ( pDmeDag[1].m_Id.m_Value[0] != 0 )
      {
        p_data->flags |= 0x21u;
      }
      if ( LOBYTE(pDmeDag[1].m_Name.m_Storage.u.CDmElement::m_Id) != 0 )
      {
        v4->data.baseMass = *((float *)&pDmeDag[2].CDmElement + 15);
        v13 = *(float *)&pDmeDag[2].m_Visible.m_Storage;
        if ( v13 >= 0.0 )
        {
          if ( v13 > 1000.0 )
            v13 = 1000.0;
        }
        else
        {
          v13 = 0.0;
        }
        v4->data.baseStiffness = v13;
        v14 = *(float *)&pDmeDag[2].m_Visible.m_Storage;
        if ( v14 >= 0.0 )
        {
          if ( v14 <= 10.0 )
            v6 = *(_DWORD *)&pDmeDag[2].m_Visible.m_Storage;
          else
            v6 = 1092616192;
        }
        LODWORD(v4->data.baseDamping) = v6;
        v4->data.baseMinLeft = *(float *)&pDmeDag[2].m_Transform.m_Storage.m_Handle;
        v4->data.baseMaxLeft = *(float *)&pDmeDag[2].m_Transform.m_pAttribute;
        v4->data.baseLeftFriction = *(float *)&pDmeDag[2].m_Shape.m_Storage.m_ElementType.u.m_Id;
        v4->data.baseMinUp = *(float *)&pDmeDag[2].m_Children.m_Storage.m_Memory.m_pMemory;
        v4->data.baseMaxUp = *(float *)&pDmeDag[2].m_Children.m_Storage.m_Memory.m_nGrowSize;
        v4->data.baseUpFriction = *(float *)&pDmeDag[2].m_Children.m_Storage.m_pElements;
        v4->data.baseMinForward = *(float *)&pDmeDag[2].m_Children.m_pAttribute;
        v4->data.baseMaxForward = *(float *)pDmeDag[3].m_Id.m_Value;
        v4->data.baseForwardFriction = *(float *)&pDmeDag[3].m_Id.m_Value[8];
      }
    }
    else
    {
      bonename = g_jigglebones[0].bonename;
      while ( _V_stricmp(s1, s2: bonename) != 0 )
      {
        v1 = g_numjigglebones;
        ++v2;
        bonename += 256;
        if ( v2 >= g_numjigglebones )
          goto LABEL_9;
      }
      MdlWarning(fmt: "2000: Jiggle Bone: %s already defined, ignoring additional declarations\n", s1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408400
// Name: AddDagJoint
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddDagJoint(
        CDmeModel *pModel,
        CDmeDag *pDag,
        s_node_t *pNodes,
        int nParentIndex,
        BoneTransformMap_t *boneMap)
{
  CDmeTransform *Transform; // eax
  int m_nBoneCount; // ebx
  const char *m_pAsString; // edi
  int JointIndex; // eax
  const char *v10; // ecx
  const char *v11; // eax
  const char *v12; // eax
  int v13; // esi
  CDmeDag *Child; // eax

  Transform = CDmeDag::GetTransform(this: pDag);
  if ( Transform == nullptr )
    return 1;
  m_nBoneCount = boneMap->m_nBoneCount;
  if ( boneMap->m_nBoneCount >= 1023 )
  {
    m_pAsString = pDag->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    MdlWarning(fmt: "Ignoring Bone %s and children, too many bones [max can be %d]!\n", m_pAsString, 1023);
    return 0;
  }
  boneMap->m_nBoneCount = m_nBoneCount + 1;
  boneMap->m_ppTransforms[m_nBoneCount] = Transform;
  if ( pModel != nullptr )
  {
    JointIndex = CDmeModel::GetJointIndex(this: pModel, pJoint: pDag);
    if ( JointIndex < 0 )
    {
      v10 = pDeltaStateName;
      if ( pModel->m_Name.m_Storage.u.CDmeDag::CDmElement::m_Id != -1 )
        v10 = pModel->m_Name.m_Storage.u.m_pAsString;
      v11 = pDag->m_Name.m_Storage.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = pDeltaStateName;
      MdlWarning(fmt: "Joint %s doesn't appear in DmeModel[%s].jointList\n", v11, v10);
    }
    else
    {
      boneMap->m_pnDmeModelToMdl[JointIndex] = m_nBoneCount;
      boneMap->m_pnMdlToDmeModel[m_nBoneCount] = JointIndex;
    }
  }
  HandleDmeJiggleBone(pDmeDag: pDag);
  v12 = pDag->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = pDeltaStateName;
  V_strncpy(pDest: pNodes[m_nBoneCount].name, pSrc: v12, maxLen: 128);
  pNodes[m_nBoneCount].parent = nParentIndex;
  v13 = 0;
  if ( CDmElementFramework::GetPhase(this: pDag) > 0 )
  {
    while ( 1 )
    {
      Child = CDmeDag::GetChild(this: pDag, i: v13);
      if ( Child != nullptr && !AddDagJoint(pModel, pDag: Child, pNodes, nParentIndex: m_nBoneCount, boneMap) )
        break;
      if ( ++v13 >= CDmElementFramework::GetPhase(this: pDag) )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408530
// Name: LoadSkeleton
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoadSkeleton(CDmeDag *pRoot, CDmeModel *pModel, s_node_t *pNodes, BoneTransformMap_t *boneMap)
{
  BoneTransformMap_t *v4; // esi
  s_node_t *v5; // edi
  s_node_t *v6; // ecx
  int *m_pnMdlToDmeModel; // eax
  int j; // edx
  int v9; // ebx
  CDmeDag *Child; // eax
  CDmeDag *v11; // edi
  CDmeTransform *Transform; // eax
  int m_nBoneCount; // ebx
  int JointIndex; // eax
  const char *v15; // ecx
  const char *v16; // eax
  const char *v17; // eax
  int v18; // esi
  CDmeDag *v19; // eax
  const char *m_pAsString; // edi
  int i; // [esp+Ch] [ebp-4h]

  v4 = boneMap;
  v5 = pNodes;
  boneMap->m_nBoneCount = 0;
  v6 = pNodes;
  m_pnMdlToDmeModel = boneMap->m_pnMdlToDmeModel;
  for ( j = 1024; j != 0; --j )
  {
    v6->name[0] = 0;
    v6->parent = -1;
    *(m_pnMdlToDmeModel - 1024) = -1;
    *m_pnMdlToDmeModel = -1;
    *(m_pnMdlToDmeModel - 2048) = 0;
    ++v6;
    ++m_pnMdlToDmeModel;
  }
  v9 = 0;
  i = 0;
  if ( CDmElementFramework::GetPhase(this: pRoot) <= 0 )
  {
LABEL_24:
    s_nDefaultRootNode = v4->m_nBoneCount;
    V_strncpy(pDest: v5[s_nDefaultRootNode].name, pSrc: "defaultRoot", maxLen: 128);
    v5[s_nDefaultRootNode].parent = -1;
    return v4->m_nBoneCount + 1;
  }
  while ( 1 )
  {
    Child = CDmeDag::GetChild(this: pRoot, i: v9);
    v11 = Child;
    if ( Child == nullptr )
      goto LABEL_22;
    Transform = CDmeDag::GetTransform(this: Child);
    if ( Transform == nullptr )
      goto LABEL_22;
    m_nBoneCount = v4->m_nBoneCount;
    if ( v4->m_nBoneCount >= 1023 )
    {
      m_pAsString = v11->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      MdlWarning(fmt: "Ignoring Bone %s and children, too many bones [max can be %d]!\n", m_pAsString, 1023);
      return 0;
    }
    v4->m_nBoneCount = m_nBoneCount + 1;
    v4->m_ppTransforms[m_nBoneCount] = Transform;
    if ( pModel != nullptr )
    {
      JointIndex = CDmeModel::GetJointIndex(this: pModel, pJoint: v11);
      if ( JointIndex < 0 )
      {
        v15 = pDeltaStateName;
        if ( pModel->m_Name.m_Storage.u.CDmeDag::CDmElement::m_Id != -1 )
          v15 = pModel->m_Name.m_Storage.u.m_pAsString;
        v16 = v11->m_Name.m_Storage.u.m_pAsString;
        if ( v16 == (const char *)-1 )
          v16 = pDeltaStateName;
        MdlWarning(fmt: "Joint %s doesn't appear in DmeModel[%s].jointList\n", v16, v15);
      }
      else
      {
        v4->m_pnDmeModelToMdl[JointIndex] = m_nBoneCount;
        v4->m_pnMdlToDmeModel[m_nBoneCount] = JointIndex;
      }
    }
    HandleDmeJiggleBone(pDmeDag: v11);
    v17 = v11->m_Name.m_Storage.u.m_pAsString;
    if ( v17 == (const char *)-1 )
      v17 = pDeltaStateName;
    V_strncpy(pDest: pNodes[m_nBoneCount].name, pSrc: v17, maxLen: 128);
    pNodes[m_nBoneCount].parent = -1;
    v18 = 0;
    if ( CDmElementFramework::GetPhase(this: v11) > 0 )
      break;
LABEL_21:
    v4 = boneMap;
    v9 = i;
LABEL_22:
    i = ++v9;
    if ( v9 >= CDmElementFramework::GetPhase(this: pRoot) )
    {
      v5 = pNodes;
      goto LABEL_24;
    }
  }
  while ( 1 )
  {
    v19 = CDmeDag::GetChild(this: v11, i: v18);
    if ( v19 != nullptr && AddDagJoint(pModel, pDag: v19, pNodes, nParentIndex: m_nBoneCount, boneMap) == 0 )
      return 0;
    if ( ++v18 >= CDmElementFramework::GetPhase(this: v11) )
      goto LABEL_21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408720
// Name: AddFlexKeys
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddFlexKeys(CDmeDag *pRoot, CDmeDag *pDag, CDmeCombinationOperator *pComboOp, s_source_t *pSource)
{
  CDmeDag *v4; // ebx
  CDmeShape *Shape; // eax
  CDmeMesh *v6; // edi
  int v7; // ebx
  int i; // esi
  const char *m_pAsString; // eax
  int Phase; // edi
  int j; // esi
  CDmeDag *Child; // eax

  v4 = pDag;
  Shape = CDmeDag::GetShape(this: pDag);
  v6 = (CDmeMesh *)Shape;
  if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) && pDag != pRoot )
  {
    v7 = CDmeMesh::DeltaStateCount(this: v6);
    for ( i = 0; i < v7; ++i )
    {
      m_pAsString = CDmeMesh::GetDeltaState(this: v6, nDeltaIndex: i)->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      AddFlexKey(pSource, pComboOp, pFlexKeyName: m_pAsString);
    }
    v4 = pDag;
  }
  Phase = CDmElementFramework::GetPhase(this: v4);
  for ( j = 0; j < Phase; ++j )
  {
    Child = CDmeDag::GetChild(this: v4, i: j);
    if ( Child != nullptr )
      AddFlexKeys(pRoot, pDag: Child, pComboOp, pSource);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004087D0
// Name: FindDuplicateConstraint
// Source: json
//------------------------------------------------------------------------------
char __usercall FindDuplicateConstraint@<al>(CConstraintBoneBase *pConstraintA@<edi>)
{
  int v1; // esi

  v1 = 0;
  if ( g_constraintBones.m_Size <= 0 )
    return 0;
  while ( !CConstraintBoneBase::operator==(this: pConstraintA, rhs: g_constraintBones.m_Memory.m_pMemory[v1]) )
  {
    if ( ++v1 >= g_constraintBones.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408810
// Name: LoadMouth
// Source: json
//------------------------------------------------------------------------------
bool __usercall LoadMouth@<al>(CDmeMouth *pDmeMouth@<edi>)
{
  int m_Storage; // eax
  s_mouth_t *v2; // esi
  const char *m_pAsString; // eax
  const char *v4; // eax

  if ( pDmeMouth != nullptr )
  {
    m_Storage = pDmeMouth->m_nMouthNumber.m_Storage;
    if ( g_nummouths <= m_Storage )
    {
      g_nummouths = m_Storage + 1;
      v2 = &g_mouth[m_Storage];
      m_pAsString = pDmeMouth->m_sFlexControllerName.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v2->flexdesc = Add_Flexdesc(name: m_pAsString);
      v4 = pDmeMouth->m_sBoneName.m_Storage.u.m_pAsString;
      if ( v4 == (const char *)-1 )
        v4 = pDeltaStateName;
      V_strncpy(pDest: v2->bonename, pSrc: v4, maxLen: 128);
      v2->forward = pDmeMouth->m_vForward.m_Storage;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00408890
// Name: void LoadAnimationOptions(class CDmeSequence __near *,struct s_animation_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadAnimationOptions(CDmeSequence *pDmeSimpleSequence, s_animation_t *pAnimation)
{
  CDmeMotionControl *v2; // eax

  if ( pAnimation != nullptr && pDmeSimpleSequence != nullptr )
  {
    pAnimation->fps = pDmeSimpleSequence->m_flFPS.m_Storage;
    pAnimation->adjust = pDmeSimpleSequence->m_vOrigin.m_Storage;
    pAnimation->scale = pDmeSimpleSequence->m_flScale.m_Storage;
    pAnimation->looprestart = pDmeSimpleSequence->m_nStartLoop.m_Storage;
    if ( pDmeSimpleSequence->m_bLoop.m_Storage )
      pAnimation->flags |= 1u;
    if ( !pDmeSimpleSequence->m_bForceLoop.m_Storage )
      pAnimation->flags |= 0x8000u;
    if ( pDmeSimpleSequence->m_bSnap.m_Storage )
      pAnimation->flags |= 2u;
    if ( pDmeSimpleSequence->m_bPost.m_Storage )
      pAnimation->flags |= 0x10u;
    pAnimation->noAutoIK = !pDmeSimpleSequence->m_bAutoIk.m_Storage;
    pAnimation->motionrollback = pDmeSimpleSequence->m_flMotionRollback.m_Storage;
    pAnimation->disableAnimblocks = !pDmeSimpleSequence->m_bAnimBlocks.m_Storage;
    pAnimation->isFirstSectionLocal = !pDmeSimpleSequence->m_bAnimBlockStall.m_Storage;
    v2 = (CDmeMotionControl *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                a1: g_pDataModel.u,
                                a2: pDmeSimpleSequence->m_eMotionControl.m_Storage.m_Handle);
    pAnimation->motiontype = CDmeMotionControl::GetStudioMotionControl(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004089A0
// Name: bool HandleDmeAnimCmdAlign(struct s_animcmd_t __near *,class CDmeAnimCmd __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl HandleDmeAnimCmdAlign(s_animcmd_t *pAnimCmd, CDmeAnimCmd *pDmeAnimCmd)
{
  int v2; // eax
  int v3; // edi
  const char *m_pAsString; // eax
  const char *v5; // esi
  const char *v7; // eax
  s_animation_t *v8; // eax
  const char *v9; // ecx
  const char *v10; // esi
  const char *v11; // eax
  const char *v12; // eax
  char *v13; // eax
  CDmeMotionControl *v14; // eax

  if ( pDmeAnimCmd == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pDmeAnimCmd->IsA)(
          a1: pDmeAnimCmd,
          a2: (CUtlSymbolLarge)CDmeAnimCmdAlign::m_classType.u.m_Id) )
  {
    return 0;
  }
  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmeAnimCmd_vtbl *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: pDmeAnimCmd[1].__vftable);
  v3 = v2;
  if ( v2 == 0 )
  {
    m_pAsString = pDmeAnimCmd->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    v5 = pDmeAnimCmd->m_Type.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = pDeltaStateName;
    MdlWarning(fmt: "1608: No DmeSequence specified for %s:%s\n", v5, m_pAsString);
    return 0;
  }
  v7 = *(const char **)(v2 + 20);
  if ( v7 == (const char *)-1 )
    v7 = pDeltaStateName;
  v8 = LookupAnimation(name: v7);
  if ( v8 != nullptr )
  {
    pAnimCmd->cmd = 3;
    pAnimCmd->u.weightlist.index = (int)v8;
    v12 = *(const char **)&pDmeAnimCmd[1].m_Id.m_Value[8];
    if ( v12 != (const char *)-1 && v12 != nullptr && *v12 != 0 )
      v13 = MemAlloc_StrDup(pString: v12);
    else
      v13 = nullptr;
    pAnimCmd->u.match.destpost = (int)v13;
    pAnimCmd->u.subtract.flags = pDmeAnimCmd[1].m_Name.m_Storage.u.CDmElement::m_Id;
    pAnimCmd->u.ao.destframe = pDmeAnimCmd[1].m_ref.m_hElement;
    v14 = (CDmeMotionControl *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                                 a1: g_pDataModel.u,
                                 a2: *((_DWORD *)&pDmeAnimCmd[1].m_ref + 2));
    pAnimCmd->u.subtract.frame = CDmeMotionControl::GetStudioMotionControl(this: v14);
    return 1;
  }
  else
  {
    v9 = pDeltaStateName;
    if ( pDmeAnimCmd->m_Name.m_Storage.u.CDmElement::m_Id != -1 )
      v9 = pDmeAnimCmd->m_Name.m_Storage.u.m_pAsString;
    v10 = pDmeAnimCmd->m_Type.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = pDeltaStateName;
    v11 = *(const char **)(v3 + 20);
    if ( v11 == (const char *)-1 )
      v11 = pDeltaStateName;
    MdlWarning(fmt: "1604: Unknown animation \"%s\" specified for %s:%s\n", v11, v10, v9);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408AD0
// Name: void LoadBlendRefCompCenter(class CDmeMultiSequence __near *,class s_sequence_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadBlendRefCompCenter(CDmeMultiSequence *pDmeMultiSequence, s_sequence_t *pSequence)
{
  int v2; // eax
  int v3; // esi
  const char *v4; // esi
  s_animation_t *v5; // eax
  const char *m_pAsString; // eax
  int v7; // eax
  int v8; // esi
  const char *v9; // esi
  s_animation_t *v10; // eax
  const char *v11; // eax
  int v12; // eax
  int v13; // esi
  const char *v14; // esi
  s_animation_t *v15; // eax
  const char *v16; // eax

  if ( pDmeMultiSequence != nullptr && pSequence != nullptr )
  {
    v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: pDmeMultiSequence->m_eBlendRef.m_Storage.m_Handle);
    v3 = v2;
    if ( v2 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
           a1: v2,
           a2: CDmeSequence::m_classType.u) != 0 )
    {
      v4 = *(const char **)(v3 + 20);
      if ( v4 != (const char *)-1 && v4 != nullptr && *v4 != 0 )
      {
        v5 = LookupAnimation(name: v4);
        pSequence->paramanim = v5;
        if ( v5 == nullptr )
        {
          m_pAsString = pDmeMultiSequence->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = pDeltaStateName;
          MdlWarning(fmt: "1202: DmeSequence %s: Unknown .blendRef animation: %s\n", m_pAsString, v4);
        }
      }
    }
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: pDmeMultiSequence->m_eBlendComp.m_Storage.m_Handle);
    v8 = v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeSequence::m_classType.u) != 0 )
    {
      v9 = *(const char **)(v8 + 20);
      if ( v9 != (const char *)-1 && v9 != nullptr && *v9 != 0 )
      {
        v10 = LookupAnimation(name: v9);
        pSequence->paramcompanim = v10;
        if ( v10 == nullptr )
        {
          v11 = pDmeMultiSequence->m_Name.m_Storage.u.m_pAsString;
          if ( v11 == (const char *)-1 )
            v11 = pDeltaStateName;
          MdlWarning(fmt: "1203: DmeSequence %s: Unknown .blendComp animation: %s\n", v11, v9);
        }
      }
    }
    v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: pDmeMultiSequence->m_eBlendCenter.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
           a1: v12,
           a2: CDmeSequence::m_classType.u) != 0 )
    {
      v14 = *(const char **)(v13 + 20);
      if ( v14 != (const char *)-1 && v14 != nullptr && *v14 != 0 )
      {
        v15 = LookupAnimation(name: v14);
        pSequence->paramcenter = v15;
        if ( v15 == nullptr )
        {
          v16 = pDmeMultiSequence->m_Name.m_Storage.u.m_pAsString;
          if ( v16 == (const char *)-1 )
            v16 = pDeltaStateName;
          MdlWarning(fmt: "1204: DmeSequence %s: Unknown .blendCenter animation: %s\n", v16, v14);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408C50
// Name: LoadAnimBlockSize
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadAnimBlockSize(CDmeAnimBlockSize *pDmeAnimBlockSize@<eax>)
{
  int m_Storage; // ecx

  if ( pDmeAnimBlockSize != nullptr )
  {
    m_Storage = pDmeAnimBlockSize->m_nSize.m_Storage;
    g_animblocksize = m_Storage;
    if ( m_Storage < 1024 )
      g_animblocksize = m_Storage << 10;
    g_bNoAnimblockStall = !pDmeAnimBlockSize->m_bStall.m_Storage;
    if ( pDmeAnimBlockSize->m_nStorageType.m_Storage == 1 )
    {
      g_bAnimblockLowRes = false;
      g_bAnimblockHighRes = true;
    }
    else
    {
      g_bAnimblockLowRes = true;
      g_bAnimblockHighRes = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408CB0
// Name: LoadBoneFlexDriverList
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadBoneFlexDriverList(const CDmeBoneFlexDriverList *pDmeBoneFlexDriverList@<eax>)
{
  int v2; // eax
  int v3; // esi
  const char *m_pAsString; // edi
  const char *v5; // esi
  CDmElement *v6; // esi
  char szTmpBuf0[40]; // [esp+8h] [ebp-50h] BYREF
  char szTmpBuf1[40]; // [esp+30h] [ebp-28h] BYREF

  if ( pDmeBoneFlexDriverList != nullptr )
  {
    v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: g_hDmeBoneFlexDriverList);
    v3 = v2;
    if ( v2 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
           a1: v2,
           a2: CDmeBoneFlexDriverList::m_classType.u) != 0 )
    {
      UniqueIdToString(id: (const UniqueId_t *)(v3 + 4), pBuf: szTmpBuf0, nMaxLen: 40);
      UniqueIdToString(id: &pDmeBoneFlexDriverList->m_Id, pBuf: szTmpBuf1, nMaxLen: 40);
      m_pAsString = pDmeBoneFlexDriverList->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v5 = *(const char **)(v3 + 20);
      if ( v5 == (const char *)-1 )
        v5 = pDeltaStateName;
      MdlError(
        fmt: "DmeBoneFlexDriverList already defined (%s:%s), ignoring (%s:%s)\n",
        v5,
        szTmpBuf0,
        m_pAsString,
        szTmpBuf1);
    }
    v6 = CDmElement::CopyInternal(this: &pDmeBoneFlexDriverList->CDmeMdlList, depth: TD_DEEP);
    CDmElement::SetFileId(this: v6, fileid: DMFILEID_INVALID, depth: TD_DEEP, bOnlyIfMatch: false);
    g_hDmeBoneFlexDriverList = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408D80
// Name: LodDistanceCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl LodDistanceCompare(const void *elem1, const void *elem2)
{
  char v2; // dl
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = *(_BYTE *)(*(_DWORD *)elem1 + 128);
  if ( v2 != *(_BYTE *)(*(_DWORD *)elem2 + 128) )
    return 2 * (v2 != 0) - 1;
  v4 = *(float *)(*(_DWORD *)elem1 + 112);
  v5 = *(float *)(*(_DWORD *)elem2 + 112);
  if ( v4 > v5 )
    return 1;
  if ( v4 == v5 )
    return 0;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00408DD0
// Name: public: class CDmElement __near * CDmaElementArrayConstBase<class CDmElement,class CDmaArrayBase<enum DmElementHandle_t,class CDmaDataExternal<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](
        CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > > *this,
        int i)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_pStorage->m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408E20
// Name: public: bool const __near & CDmElement::GetValue<bool>(char const __near *,bool const __near &)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<bool> *__thiscall CDmElement::GetValue<bool>(
        CDmElement *this,
        const char *pAttributeName,
        const bool *defaultVal)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<bool>(this: Attribute);
  else
    return (CDmaVar<bool> *)defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00408FC0
// Name: public: char const __near * CDmElement::GetValueString(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmElement::GetValueString(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  DmElementHandle_t *v3; // eax

  if ( (`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    dword_660BA8 = 0;
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal != -1
         ? (const char *)`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal
         : nullptr;
  v3 = CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
  return *v3 != DMELEMENT_HANDLE_INVALID ? (const char *)*v3 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00409030
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeTransform::m_classType.u) != 0 )
  {
    return (CDmeTransform *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409080
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004090C0
// Name: UpdateChannels
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateChannels(
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators,
        CDmeChannelsClip *pAnimation,
        DmeTime_t clipTime)
{
  CDmeChannelsClip *v3; // ebx
  int m_Size; // esi
  int v5; // edi
  int v6; // eax
  int v7; // esi
  CDmeChannel *v8; // ecx
  int nChannelsCount; // [esp+10h] [ebp-4h]

  v3 = pAnimation;
  m_Size = pAnimation->m_Channels.m_Storage.m_Size;
  nChannelsCount = m_Size;
  CDmeClip::ToChildMediaTime(this: pAnimation, result: (DmeTime_t *)&pAnimation, t: clipTime, bClamp: true);
  v5 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v3->m_Channels.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v8 = (CDmeChannel *)(v7 - 4);
      }
      else
      {
        v8 = nullptr;
      }
      CDmeChannel::SetCurrentTime(this: v8, time: (DmeTime_t)pAnimation);
      ++v5;
    }
    while ( v5 < nChannelsCount );
  }
  LOBYTE(nChannelsCount) = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: operators);
  g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: nChannelsCount);
  g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
}

//------------------------------------------------------------------------------
// Address: 0x004091B0
// Name: LoadEyeballs
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadEyeballs(s_source_t *pSource, s_model_t *pModel, CDmrElementArray<CDmElement> *elementArray)
{
  s_source_t *v3; // ebx
  CDmrElementArray<CDmElement> *v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // edi
  const char *v8; // edi
  int v9; // esi
  const char *name; // ebx
  const char *v11; // eax
  const char *v12; // ecx
  const char *v13; // edi
  const char *v14; // eax
  unsigned __int8 *v15; // ebx
  int v16; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  int v20; // eax
  int nummeshes; // ecx
  int v22; // ebx
  int *meshindex; // edx
  const char *v24; // ecx
  const char *v25; // edi
  const char *v26; // eax
  int numeyeballs; // ecx
  s_eyeball_t *v28; // esi
  const char *v29; // eax
  double v30; // xmm0_8
  int v31; // ecx
  int v32; // ebx
  int v33; // ecx
  const char **v34; // ebx
  signed int v35; // esi
  s_flexcontroller_t *v36; // edi
  int v37; // eax
  unsigned int v38; // ecx
  unsigned int v39; // eax
  long double v40; // [esp-Ch] [ebp-78h]
  matrix3x4_t mDefRot; // [esp+Ch] [ebp-60h] BYREF
  Vector vTmp; // [esp+3Ch] [ebp-30h] BYREF
  float v43[3]; // [esp+48h] [ebp-24h] BYREF
  float in1[3]; // [esp+54h] [ebp-18h] BYREF
  int i; // [esp+60h] [ebp-Ch]
  BOOL bRelative; // [esp+64h] [ebp-8h]
  int nSearchBoneIndex; // [esp+68h] [ebp-4h]
  int pSourcea; // [esp+74h] [ebp+8h]

  v3 = pSource;
  if ( pSource != nullptr && pModel != nullptr )
  {
    v4 = elementArray;
    if ( elementArray->m_pAttribute != nullptr && elementArray->m_pStorage->m_Size > 0 )
    {
      AngleMatrix(angles: &g_defaultrotation, matrix: &mDefRot);
      v5 = 0;
      i = 0;
      if ( CDmrElementArray<CDmElement>::Count(this: elementArray) > 0 )
      {
        while ( 1 )
        {
          v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v4->m_pStorage->m_Memory.m_pMemory[v5]);
          v7 = v6;
          if ( v6 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
                 a1: v6,
                 a2: CDmElement::m_classType.u) != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmeEyeball::m_classType.u) != 0 )
          {
            if ( pModel->numeyeballs < 4u )
            {
              v9 = 0;
              if ( v3->numbones <= 0 )
                goto LABEL_23;
              name = v3->localBone[0].name;
              while ( 1 )
              {
                v11 = *(const char **)(v7 + 100);
                if ( v11 == (const char *)-1 )
                  v11 = pDeltaStateName;
                if ( _V_stricmp(s1: name, s2: v11) == 0 )
                  break;
                ++v9;
                name += 132;
                if ( v9 >= pSource->numbones )
                  goto LABEL_23;
              }
              nSearchBoneIndex = v9;
              if ( v9 >= 0 )
              {
                v15 = *(unsigned __int8 **)(v7 + 92);
                if ( v15 == (unsigned __int8 *)-1 )
                  v15 = (unsigned __int8 *)pDeltaStateName;
                strchr(string: v15, chr: 0x2Fu);
                if ( v16 != 0 || (strchr(string: v15, chr: 0x5Cu), LOBYTE(bRelative) = 0, v17 != 0) )
                  LOBYTE(bRelative) = 1;
                v18 = *(const char **)(v7 + 92);
                if ( v18 == (const char *)-1 )
                  v18 = pDeltaStateName;
                v19 = LookupTexture(pTextureName: v18, bRelativePath: bRelative);
                v20 = UseTextureAsMaterial(textureindex: v19);
                nummeshes = pSource->nummeshes;
                v22 = 0;
                if ( nummeshes <= 0 )
                  goto LABEL_41;
                meshindex = pSource->meshindex;
                while ( *meshindex != v20 )
                {
                  ++v22;
                  ++meshindex;
                  if ( v22 >= nummeshes )
                    goto LABEL_41;
                }
                if ( v22 >= 0 )
                {
                  numeyeballs = pModel->numeyeballs;
                  v28 = &pModel->eyeball[numeyeballs];
                  v29 = *(const char **)(v7 + 20);
                  if ( v29 == (const char *)-1 )
                    v29 = pDeltaStateName;
                  V_strncpy(pDest: pModel->eyeball[numeyeballs].name, pSrc: v29, maxLen: 128);
                  v28->bone = nSearchBoneIndex;
                  v28->mesh = v22;
                  v28->radius = *(float *)(v7 + 68);
                  v30 = (float)(*(float *)(v7 + 76) * 0.017453292);
                  __libm_sse2_tan(x: v40);
                  *(float *)&v30 = v30;
                  v31 = nSearchBoneIndex;
                  v28->zoffset = *(float *)&v30;
                  v28->iris_scale = 1.0 / *(float *)(v7 + 84);
                  VectorITransform(in1: (const float *)(v7 + 108), in2: &pSource->boneToPose[v31], out: &v28->org.x);
                  in1[0] = 0.0;
                  in1[1] = 0.0;
                  in1[2] = 1.0;
                  VectorIRotate(in1, in2: &mDefRot, out: &vTmp.x);
                  VectorIRotate(in1: &vTmp.x, in2: &pSource->boneToPose[v28->bone], out: &v28->up.x);
                  v43[0] = 1.0;
                  v43[1] = 0.0;
                  v43[2] = 0.0;
                  VectorIRotate(in1: v43, in2: &mDefRot, out: &vTmp.x);
                  VectorIRotate(in1: &vTmp.x, in2: &pSource->boneToPose[v28->bone], out: &v28->forward.x);
                  v32 = 0;
                  v28->upperlidflexdesc = -1;
                  v28->lowerlidflexdesc = -1;
                  if ( pModel->numeyeballs <= 0 )
                  {
LABEL_52:
                    ++pModel->numeyeballs;
                  }
                  else
                  {
                    nSearchBoneIndex = (int)pModel->eyeball;
                    while ( _V_stricmp(s1: v28->name, s2: (const char *)nSearchBoneIndex) != 0 )
                    {
                      nSearchBoneIndex += 244;
                      if ( ++v32 >= pModel->numeyeballs )
                        goto LABEL_52;
                    }
                    _V_memset(dest: v28, fill: 0, count: 244);
                  }
                }
                else
                {
LABEL_41:
                  v24 = pDeltaStateName;
                  if ( *(_DWORD *)(v7 + 20) != -1 )
                    v24 = *(const char **)(v7 + 20);
                  v25 = *(const char **)(v7 + 92);
                  v26 = pDeltaStateName;
                  if ( v25 != (const char *)-1 )
                    v26 = v25;
                  MdlWarning(
                    fmt: "1102: Couldn't find eyeball material %s on model %s, ignoring eyeball %s\n",
                    v26,
                    pModel->name,
                    v24);
                }
              }
              else
              {
LABEL_23:
                v12 = pDeltaStateName;
                if ( *(_DWORD *)(v7 + 20) != -1 )
                  v12 = *(const char **)(v7 + 20);
                v13 = *(const char **)(v7 + 100);
                v14 = pDeltaStateName;
                if ( v13 != (const char *)-1 )
                  v14 = v13;
                MdlWarning(
                  fmt: "1101: Couldn't find bone %s on model %s, ignoring eyeball %s\n",
                  v14,
                  pModel->name,
                  v12);
              }
            }
            else
            {
              v8 = *(const char **)(v7 + 20);
              if ( v8 == (const char *)-1 )
                v8 = pDeltaStateName;
              MdlWarning(
                fmt: "1100: Max number of eyeballs reached for model %s, ignoring eyeball %s\n",
                pModel->name,
                v8);
            }
          }
          v4 = elementArray;
          v5 = ++i;
          if ( v5 >= CDmrElementArray<CDmElement>::Count(this: elementArray) )
            break;
          v3 = pSource;
        }
      }
      v33 = g_numflexcontrollers;
      v34 = szEyesFlexControllers;
      for ( pSourcea = 2; pSourcea != 0; --pSourcea )
      {
        v35 = 0;
        if ( v33 <= 0 )
        {
LABEL_60:
          if ( v33 < 96 )
          {
            V_strncpy(pDest: g_flexcontroller[v33].name, pSrc: *v34, maxLen: 128);
            V_strncpy(pDest: g_flexcontroller[g_numflexcontrollers].type, pSrc: "eyes", maxLen: 128);
            v38 = g_numflexcontrollers;
            v39 = g_numflexcontrollers;
            g_flexcontroller[v39].min = -45.0;
            v33 = v38 + 1;
            g_flexcontroller[v39].max = 45.0;
            g_numflexcontrollers = v33;
          }
          else
          {
            MdlWarning(fmt: "1103: Couldn't make eyes flexcontroller %s, too many flex controllers defined\n", *v34);
            v33 = g_numflexcontrollers;
          }
        }
        else
        {
          v36 = g_flexcontroller;
          while ( 1 )
          {
            v37 = _V_strcmp(s1: *v34, s2: v36->name);
            v33 = g_numflexcontrollers;
            if ( v37 == 0 )
              break;
            ++v35;
            ++v36;
            if ( v35 >= (int)g_numflexcontrollers )
              goto LABEL_60;
          }
        }
        ++v34;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409660
// Name: LoadBoneMaskList
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadBoneMaskList(CDmeBoneMaskList *pDmeBoneMaskList)
{
  CDmeBoneMaskList *v1; // esi
  int v2; // eax
  CDmeBoneMask *v3; // ebx
  int v4; // edi
  const char *m_pAsString; // eax
  s_weightlist_t *v6; // esi
  const char *Name; // eax
  const char *v8; // eax
  s_weightlist_t *v9; // esi
  int v10; // eax
  int v11; // edi
  int numbones; // ebx
  const char *v13; // eax
  const char *v14; // ebx
  char *v15; // eax
  char *v16; // ebx
  const char *v17; // ecx
  int v18; // eax
  char v19; // dl
  char *v20; // eax
  float v21; // xmm0_4
  CDmAttribute *Attribute; // eax
  CDmAttribute *v23; // edi
  CDmaVar<float> *m_pData; // edi
  float v25; // xmm1_4
  float m_Storage; // xmm0_4
  CDmeBoneMask *pDmeDefaultBoneMask; // [esp+34h] [ebp-1Ch]
  int v28; // [esp+38h] [ebp-18h]
  int nBoneWeightIndex; // [esp+3Ch] [ebp-14h]
  int i; // [esp+40h] [ebp-10h]
  int nBoneMaskIndex; // [esp+44h] [ebp-Ch]
  int j; // [esp+48h] [ebp-8h]
  const char *v33; // [esp+4Ch] [ebp-4h]

  v1 = pDmeBoneMaskList;
  if ( pDmeBoneMaskList != nullptr )
  {
    pDmeDefaultBoneMask = (CDmeBoneMask *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                            a1: g_pDataModel.u,
                                            a2: pDmeBoneMaskList->m_eDefaultBoneMask.m_Storage.m_Handle);
    i = 0;
    if ( pDmeBoneMaskList->m_BoneMaskList.m_Storage.m_Size > 0 )
    {
      while ( 1 )
      {
        v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v1->m_BoneMaskList.m_Storage.m_Memory.m_pMemory[i]);
        v3 = (CDmeBoneMask *)v2;
        v4 = 0;
        v28 = v2;
        if ( v2 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
               a1: v2,
               a2: CDmeBoneMask::m_classType.u) == 0 )
        {
          return;
        }
        nBoneMaskIndex = g_numweightlist;
        if ( v3 == pDmeDefaultBoneMask )
        {
          nBoneMaskIndex = 0;
        }
        else if ( g_numweightlist >= 128 )
        {
          m_pAsString = v3->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = pDeltaStateName;
          MdlWarning(fmt: "1300: Too many bone masks, max %d, ignoring %s\n", 128, m_pAsString);
        }
        if ( g_numweightlist <= 0 )
          break;
        v6 = g_weightlist;
        while ( 1 )
        {
          if ( v6 != nullptr )
          {
            Name = CDmElement::GetName(this: v3);
            if ( _V_stricmp(s1: v6->name, s2: Name) == 0 )
              break;
          }
          ++v4;
          ++v6;
          if ( v4 >= g_numweightlist )
            goto LABEL_18;
        }
        v14 = v3->m_Name.m_Storage.u.m_pAsString;
        if ( v14 == (const char *)-1 )
          v14 = pDeltaStateName;
        MdlWarning(fmt: "1301: Ignoring duplicate bone mask %s\n", v14);
LABEL_56:
        if ( ++i >= pDmeBoneMaskList->m_BoneMaskList.m_Storage.m_Size )
          return;
        v1 = pDmeBoneMaskList;
      }
LABEL_18:
      v8 = v3->m_Name.m_Storage.u.m_pAsString;
      v9 = &g_weightlist[nBoneMaskIndex];
      if ( v8 == (const char *)-1 )
        v8 = pDeltaStateName;
      V_strncpy(pDest: g_weightlist[nBoneMaskIndex].name, pSrc: v8, maxLen: 128);
      v9->numbones = 0;
      j = 0;
      if ( v3->m_BoneWeights.m_Storage.m_Size <= 0 )
      {
LABEL_54:
        if ( nBoneMaskIndex != 0 )
          ++g_numweightlist;
        goto LABEL_56;
      }
      while ( 1 )
      {
        v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v3->m_BoneWeights.m_Storage.m_Memory.m_pMemory[j]);
        v11 = v10;
        if ( v10 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
               a1: v10,
               a2: CDmeBoneWeight::m_classType.u) != 0 )
        {
          numbones = v9->numbones;
          v13 = *(const char **)(v11 + 20);
          nBoneWeightIndex = numbones;
          if ( numbones < 256 )
            break;
          if ( v13 == (const char *)-1 )
            v13 = pDeltaStateName;
          MdlWarning(
            fmt: "1302: Too many bones in weightlist %s, ignoring weight for %s (%f)\n",
            v9->name,
            v13,
            *(float *)(v11 + 68));
LABEL_52:
          v3 = (CDmeBoneMask *)v28;
        }
        if ( ++j >= v3->m_BoneWeights.m_Storage.m_Size )
          goto LABEL_54;
      }
      if ( v13 == (const char *)-1 )
      {
        v33 = pDeltaStateName;
      }
      else
      {
        v33 = *(const char **)(v11 + 20);
        if ( v13 == nullptr )
          goto LABEL_38;
      }
      v15 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v33) + 1);
      v16 = v15;
      if ( v15 != nullptr )
      {
        v17 = v33;
        v18 = v15 - v33;
        do
        {
          v19 = *v17;
          v17[v18] = *v17;
          ++v17;
        }
        while ( v19 != 0 );
        v20 = v16;
        numbones = nBoneWeightIndex;
        goto LABEL_39;
      }
      numbones = nBoneWeightIndex;
LABEL_38:
      v20 = nullptr;
LABEL_39:
      v9->bonename[numbones] = v20;
      v21 = *(float *)(v11 + 68);
      v9->boneweight[numbones] = v21;
      v9->boneposweight[numbones] = v21;
      Attribute = CDmElement::FindAttribute(this: (CDmElement *)v11, pAttributeName: "positionWeight");
      v23 = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 3 )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v23, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
        v25 = v9->boneweight[numbones];
        m_Storage = m_pData->m_Storage;
        v9->boneposweight[numbones] = m_pData->m_Storage;
        if ( v25 == 0.0 && m_Storage > 0.0 )
        {
          MdlWarning(
            fmt: "1303: Non-zero position weight with zero rotation weight not allowed for bone weight list %s:%s P: %f R: %f,"
            " ignoring position weight\n",
            v9->name,
            v9->bonename[numbones],
            m_Storage,
            v25);
          v9->boneposweight[numbones] = v9->boneweight[numbones];
        }
      }
      ++v9->numbones;
      goto LABEL_52;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004099E0
// Name: LoadPoseParameterList
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadPoseParameterList(CDmePoseParameterList *pDmePoseParameterList)
{
  CDmePoseParameterList *v1; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  int v7; // esi
  const char *v8; // eax
  s_poseparameter_t *v9; // esi
  float v10; // xmm0_4
  int nPoseParameterCount; // [esp+Ch] [ebp-4h]

  v1 = pDmePoseParameterList;
  if ( pDmePoseParameterList != nullptr )
  {
    v2 = 0;
    nPoseParameterCount = pDmePoseParameterList->m_ePoseParameterList.m_Storage.m_Size;
    if ( nPoseParameterCount > 0 )
    {
      while ( 1 )
      {
        v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v1->m_ePoseParameterList.m_Storage.m_Memory.m_pMemory[v2]);
        v4 = v3;
        if ( v3 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
               a1: v3,
               a2: CDmePoseParameter::m_classType.u) == 0 )
        {
          v4 = 0;
        }
        if ( g_numposeparameters >= 24 )
        {
          v5 = *(const char **)(v4 + 20);
          if ( v5 == (const char *)-1 )
            v5 = pDeltaStateName;
          MdlWarning(fmt: "1900: Too many pose parameters, ignoring from %s\n", v5);
        }
        v6 = *(const char **)(v4 + 20);
        if ( v6 == (const char *)-1 )
          v6 = pDeltaStateName;
        v7 = LookupPoseParameter(name: v6);
        v8 = *(const char **)(v4 + 20);
        v9 = &g_pose[v7];
        if ( v8 == (const char *)-1 )
          v8 = pDeltaStateName;
        V_strncpy(pDest: v9->name, pSrc: v8, maxLen: 128);
        v9->min = *(float *)(v4 + 68);
        v9->max = *(float *)(v4 + 76);
        if ( *(_BYTE *)(v4 + 100) != 0 )
        {
          v10 = v9->max - v9->min;
          v9->flags |= 1u;
          v9->loop = v10;
        }
        else if ( *(_BYTE *)(v4 + 84) != 0 )
        {
          v9->flags |= 1u;
          v9->loop = *(float *)(v4 + 92);
        }
        if ( ++v2 >= nPoseParameterCount )
          break;
        v1 = pDmePoseParameterList;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409B00
// Name: LoadIkChainList
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadIkChainList(CDmeSequenceList *pDmeSequenceList)
{
  CDmeSequenceList *v1; // ebx
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v5; // edi
  s_ikchain_t *v6; // ebx
  int v7; // eax
  const char *v8; // eax
  int v9; // ecx
  int v10; // eax
  double v11; // st7
  int nIkChainCount; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  char *s1; // [esp+14h] [ebp-4h]

  v1 = pDmeSequenceList;
  if ( pDmeSequenceList != nullptr )
  {
    v2 = 0;
    nIkChainCount = pDmeSequenceList->m_eIkChainList.m_Storage.m_Size;
    i = 0;
    if ( nIkChainCount > 0 )
    {
      do
      {
        v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v1->m_eIkChainList.m_Storage.m_Memory.m_pMemory[v2]);
        v4 = v3;
        if ( v3 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
               a1: v3,
               a2: CDmeIkChain::m_classType.u) != 0 )
        {
          s1 = (char *)pDeltaStateName;
          if ( *(_DWORD *)(v4 + 20) != -1 )
            s1 = *(char **)(v4 + 20);
          v5 = 0;
          if ( g_numikchains > 0 )
          {
            v6 = g_ikchain;
            while ( _V_stricmp(s1, s2: v6->name) != 0 )
            {
              ++v5;
              ++v6;
              if ( v5 >= g_numikchains )
                goto LABEL_15;
            }
            if ( v5 < g_numikchains && !g_quiet )
              MdlWarning(fmt: "1401: Duplicate IkChain: %s Ignored\n", s1);
          }
LABEL_15:
          v7 = g_numikchains;
          g_ikchain[v7].axis = 4;
          g_ikchain[v7].value = 0.0;
          g_ikchain[v7].height = 18.0;
          g_ikchain[v7].floor = 0.0;
          g_ikchain[v7].radius = 0.0;
          V_strncpy(pDest: g_ikchain[v7].name, pSrc: s1, maxLen: 128);
          v8 = *(const char **)(v4 + 68);
          if ( v8 == (const char *)-1 )
            v8 = pDeltaStateName;
          V_strncpy(pDest: g_ikchain[g_numikchains].bonename, pSrc: v8, maxLen: 128);
          v9 = g_numikchains;
          v10 = g_numikchains;
          v2 = i;
          v1 = pDmeSequenceList;
          g_ikchain[v10].height = *(float *)(v4 + 76);
          g_ikchain[v10].floor = *(float *)(v4 + 92);
          g_ikchain[v10].radius = *(float *)(v4 + 84) * 0.5;
          g_ikchain[v10].link[0].kneeDir.x = *(float *)(v4 + 100);
          g_ikchain[v10].link[0].kneeDir.y = *(float *)(v4 + 104);
          g_ikchain[v10].link[0].kneeDir.z = *(float *)(v4 + 108);
          g_ikchain[v10].center.x = *(float *)(v4 + 116);
          g_ikchain[v10].center.y = *(float *)(v4 + 120);
          v11 = *(float *)(v4 + 124);
          g_numikchains = v9 + 1;
          g_ikchain[v10].center.z = v11;
        }
        i = ++v2;
      }
      while ( v2 < nIkChainCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409CF0
// Name: void LoadAnimationCommands(class CDmeSequence __near *,struct s_animation_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadAnimationCommands(CDmeSequence *pDmeSimpleSequence, s_animation_t *pAnimation)
{
  CDmeSequence *v2; // eax
  int v3; // eax
  CDmeAnimCmd *v4; // esi
  int numcmds; // eax
  s_animcmd_t *v6; // edi
  CDmeAnimCmd *v7; // eax
  CDmeAnimCmdWeightList *v8; // ebx
  const char *m_pAsString; // eax
  int WeightList; // eax
  const char *v11; // eax
  const char *v12; // esi
  const char *Name; // eax
  CDmeAnimCmdSubtract *v14; // ebx
  int v15; // eax
  const char *v16; // eax
  s_animation_t *v17; // eax
  const char *v18; // esi
  const char *v19; // eax
  const char *v20; // edi
  const char *v21; // esi
  const char *v22; // eax
  const char *v23; // esi
  const char *v24; // edx
  const char *v25; // eax
  const char *v26; // esi
  const char *v27; // eax
  CDmeAnimCmdRotateTo *v28; // eax
  CDmeAnimCmdWalkFrame *v29; // eax
  CDmeMotionControl *v30; // eax
  CDmeAnimCmdDerivative *v31; // eax
  CDmeAnimCmdCompress *v32; // eax
  CDmeAnimCmdNumFrames *v33; // eax
  CDmeAnimCmdLocalHierarchy *v34; // esi
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // esi
  const char *v39; // esi
  const char *v40; // [esp-Ch] [ebp-28h]
  const char *v41; // [esp-Ch] [ebp-28h]
  const char *v42; // [esp-Ch] [ebp-28h]
  const char *v43; // [esp-4h] [ebp-20h]
  CUtlSymbolLarge::<unnamed_type_u> v44; // [esp+0h] [ebp-1Ch]
  int nAnimCmdCount; // [esp+Ch] [ebp-10h]
  const char *v46; // [esp+10h] [ebp-Ch]
  CDmeSequenceBase *pDmeSequenceBase; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v2 = pDmeSimpleSequence;
  if ( pDmeSimpleSequence == nullptr )
    return;
  if ( pAnimation == nullptr )
    return;
  nAnimCmdCount = pDmeSimpleSequence->m_eAnimationCommandList.m_Storage.m_Size;
  i = 0;
  if ( nAnimCmdCount <= 0 )
    return;
  while ( 1 )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v2->m_eAnimationCommandList.m_Storage.m_Memory.m_pMemory[i]);
    v4 = (CDmeAnimCmd *)v3;
    if ( v3 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeAnimCmd::m_classType.u) == 0 )
    {
      goto LABEL_76;
    }
    numcmds = pAnimation->numcmds;
    if ( numcmds >= 64 )
      break;
    v6 = &pAnimation->cmds[numcmds];
    if ( ((unsigned __int8 (__thiscall *)(CDmeAnimCmd *, CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>))v4->IsA)(
           a1: v4,
           a2: CDmeAnimCmdFixupLoop::m_classType.u,
           a3: v44) != 0 )
    {
      v44.m_Id = CDmeAnimCmdFixupLoop::m_classType.u.m_Id;
      v7 = ((unsigned __int8 (__thiscall *)(CDmeAnimCmd *))v4->IsA)(a1: v4) != 0 ? v4 : nullptr;
      v6->cmd = 5;
      v6->u.weightlist.index = (int)v7[1].__vftable;
      v6->u.subtract.frame = *(_DWORD *)&v7[1].m_Id.m_Value[4];
      ++pAnimation->numcmds;
      goto LABEL_76;
    }
    v44.m_Id = CDmeAnimCmdWeightList::m_classType.u.m_Id;
    if ( ((unsigned __int8 (__thiscall *)(CDmeAnimCmd *))v4->IsA)(a1: v4) != 0 )
    {
      v8 = CastElement<CDmeAnimCmdWeightList>(pElement: v4);
      m_pAsString = v8->m_sWeightListName.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      WeightList = FindWeightList(pWeightListName: m_pAsString);
      if ( WeightList >= 0 )
      {
        v6->u.weightlist.index = WeightList;
        v6->cmd = 1;
        ++pAnimation->numcmds;
      }
      else
      {
        v11 = pDmeSimpleSequence->m_eAnimationCommandList.m_pAttribute->m_Name.u.m_pAsString;
        if ( v11 == (const char *)-1 )
          v11 = pDeltaStateName;
        v12 = v8->m_Type.u.m_pAsString;
        if ( v12 == (const char *)-1 )
          v12 = pDeltaStateName;
        v40 = v11;
        Name = CDmElement::GetName(this: pDmeSimpleSequence);
        MdlWarning(
          fmt: "1602: Unknown weightList \"%s\" specified for %s animation command %s.%s[%d] %s\n",
          v8->m_sWeightListName.m_Storage.u.m_pAsString,
          (const char *)v8->m_sWeightListName.m_pAttribute,
          v12,
          Name,
          v40,
          (const char *)i);
      }
    }
    else if ( v4->IsA(this: v4, a2: CDmeAnimCmdSubtract::m_classType) )
    {
      v14 = CastElement<CDmeAnimCmdSubtract>(pElement: v4);
      v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: v14->m_eAnimation.m_Storage.m_Handle);
      pDmeSequenceBase = (CDmeSequenceBase *)v15;
      if ( v15 != 0 )
      {
        v16 = *(const char **)(v15 + 20);
        if ( v16 == (const char *)-1 )
          v16 = pDeltaStateName;
        v17 = LookupAnimation(name: v16);
        if ( v17 != nullptr )
        {
          v6->u.weightlist.index = (int)v17;
          v6->cmd = 2;
          v6->u.subtract.frame = v14->m_nFrame.m_Storage;
          if ( !v4->IsA(this: v4, a2: CDmeAnimCmdPreSubtract::m_classType) )
          {
            v6->u.subtract.flags |= 0x10u;
            ++pAnimation->numcmds;
            goto LABEL_76;
          }
          goto LABEL_70;
        }
        v18 = v4->m_Name.m_Storage.u.m_pAsString;
        v46 = pDeltaStateName;
        if ( v18 != (const char *)-1 )
          v46 = v18;
        v19 = pDmeSimpleSequence->m_eAnimationCommandList.m_pAttribute->m_Name.u.m_pAsString;
        if ( v19 == (const char *)-1 )
          v19 = pDeltaStateName;
        v20 = pDeltaStateName;
        if ( v14->m_Type.u.CDmeAnimCmd::CDmElement::m_Id != -1 )
          v20 = v14->m_Type.u.m_pAsString;
        v21 = pDmeSequenceBase->m_Name.m_Storage.u.m_pAsString;
        if ( v21 == (const char *)-1 )
          v21 = pDeltaStateName;
        v41 = v19;
        v22 = CDmElement::GetName(this: pDmeSimpleSequence);
        MdlWarning(fmt: "1603: Unknown animation \"%s\" specified for %s %s.%s[%d] %s\n", v21, v20, v22, v41, i, v46);
      }
      else
      {
        v23 = v4->m_Name.m_Storage.u.m_pAsString;
        v24 = pDeltaStateName;
        if ( v23 != (const char *)-1 )
          v24 = v23;
        v25 = pDmeSimpleSequence->m_eAnimationCommandList.m_pAttribute->m_Name.u.m_pAsString;
        if ( v25 == (const char *)-1 )
          v25 = pDeltaStateName;
        v26 = v14->m_Type.u.m_pAsString;
        if ( v26 == (const char *)-1 )
          v26 = pDeltaStateName;
        v43 = v24;
        v42 = v25;
        v27 = CDmElement::GetName(this: pDmeSimpleSequence);
        MdlWarning(fmt: "1607: No DmeSequenceBase specified for %s %s.%s[%d] %s\n", v26, v27, v42, i, v43);
      }
    }
    else if ( v4->IsA(this: v4, a2: CDmeAnimCmdAlign::m_classType) )
    {
      if ( HandleDmeAnimCmdAlign(pAnimCmd: v6, pDmeAnimCmd: v4) != 0 )
        ++pAnimation->numcmds;
    }
    else
    {
      if ( v4->IsA(this: v4, a2: CDmeAnimCmdRotateTo::m_classType) )
      {
        v28 = CastElement<CDmeAnimCmdRotateTo>(pElement: v4);
        v6->cmd = 6;
        v6->u.angle.angle = v28->m_flAngle.m_Storage;
        ++pAnimation->numcmds;
        goto LABEL_76;
      }
      if ( v4->IsA(this: v4, a2: CDmeAnimCmdWalkFrame::m_classType) )
      {
        v29 = CastElement<CDmeAnimCmdWalkFrame>(pElement: v4);
        v6->cmd = 9;
        v6->u.subtract.flags = v29->m_nEndFrame.m_Storage;
        v30 = (CDmeMotionControl *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                     a1: g_pDataModel.u,
                                     a2: v29->m_eMotionControl.m_Storage.m_Handle);
        v6->u.weightlist.index = CDmeMotionControl::GetStudioMotionControl(this: v30);
        ++pAnimation->numcmds;
        goto LABEL_76;
      }
      if ( v4->IsA(this: v4, a2: CDmeAnimCmdDerivative::m_classType)
        || v4->IsA(this: v4, a2: CDmeAnimCmdDerivative::m_classType) )
      {
        v31 = CastElement<CDmeAnimCmdDerivative>(pElement: v4);
        v6->cmd = 11;
        v6->u.angle.angle = v31->m_flScale.m_Storage;
        ++pAnimation->numcmds;
        goto LABEL_76;
      }
      if ( v4->IsA(this: v4, a2: CDmeAnimCmdLinearDelta::m_classType) )
      {
        v6->u.weightlist.index |= 0x10u;
        v6->cmd = 13;
        ++pAnimation->numcmds;
        goto LABEL_76;
      }
      if ( v4->IsA(this: v4, a2: CDmeAnimCmdSplineDelta::m_classType) )
      {
        v6->u.weightlist.index |= 0x50u;
        v6->cmd = 13;
        ++pAnimation->numcmds;
        goto LABEL_76;
      }
      if ( v4->IsA(this: v4, a2: CDmeAnimCmdCompress::m_classType) )
      {
        v32 = CastElement<CDmeAnimCmdCompress>(pElement: v4);
        v6->cmd = 15;
        v6->u.weightlist.index = v32->m_nSkipFrames.m_Storage;
        ++pAnimation->numcmds;
        goto LABEL_76;
      }
      if ( v4->IsA(this: v4, a2: CDmeAnimCmdNumFrames::m_classType) )
      {
        v33 = CastElement<CDmeAnimCmdNumFrames>(pElement: v4);
        v6->cmd = 16;
        v6->u.weightlist.index = v33->m_nFrames.m_Storage;
        ++pAnimation->numcmds;
        goto LABEL_76;
      }
      if ( v4->IsA(this: v4, a2: CDmeAnimCmdLocalHierarchy::m_classType) )
      {
        v34 = CastElement<CDmeAnimCmdLocalHierarchy>(pElement: v4);
        v6->cmd = 21;
        v35 = v34->m_sBoneName.m_Storage.u.m_pAsString;
        if ( v35 == (const char *)-1 )
          v35 = pDeltaStateName;
        v6->u.weightlist.index = (int)MemAlloc_StrDup(pString: v35);
        v36 = v34->m_sParentBoneName.m_Storage.u.m_pAsString;
        if ( v36 == (const char *)-1 )
          v36 = pDeltaStateName;
        v6->u.subtract.frame = (int)MemAlloc_StrDup(pString: v36);
        v6->u.subtract.flags = (int)v34->m_flStartFrame.m_Storage;
        v6->u.ao.destframe = (int)v34->m_flPeakFrame.m_Storage;
        v6->u.match.destpost = (int)v34->m_flTailFrame.m_Storage;
        v6->u.localhierarchy.end = (int)v34->m_flEndFrame.m_Storage;
        ++pAnimation->numcmds;
      }
      else
      {
        if ( v4->IsA(this: v4, a2: CDmeAnimCmdNoAnimation::m_classType) )
        {
          v6->cmd = 12;
LABEL_70:
          ++pAnimation->numcmds;
          goto LABEL_76;
        }
        v37 = v4->m_Name.m_Storage.u.m_pAsString;
        if ( v37 == (const char *)-1 )
          v37 = pDeltaStateName;
        v38 = v4->m_Type.u.m_pAsString;
        if ( v38 == (const char *)-1 )
          v38 = pDeltaStateName;
        MdlWarning(fmt: "1601: Unhandled DmeAnimCmd %s (%s)\n", v38, v37);
      }
    }
LABEL_76:
    if ( ++i >= nAnimCmdCount )
      return;
    v2 = pDmeSimpleSequence;
  }
  v39 = v4->m_Name.m_Storage.u.m_pAsString;
  if ( v39 == (const char *)-1 )
    v39 = pDeltaStateName;
  MdlWarning(fmt: "1600: Too many animation commands for anim: %s, ignoring from %d:%s\n", pAnimation->name, i, v39);
}

//------------------------------------------------------------------------------
// Address: 0x0040A300
// Name: void LoadLayerList(class CDmeSequenceBase __near *,class s_sequence_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadLayerList(CDmeSequenceBase *pDmeSequenceBase, s_sequence_t *pSequence)
{
  CDmeSequenceBase *v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // edi
  int v6; // eax
  unsigned int numautolayers; // ecx
  const char *v8; // eax
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // edi
  int *p_flags; // eax
  int *v14; // eax
  _BYTE *v15; // eax
  const char *v16; // edi
  int nLayerCount; // [esp+Ch] [ebp-4h]

  v2 = pDmeSequenceBase;
  if ( pDmeSequenceBase != nullptr && pSequence != nullptr )
  {
    v3 = 0;
    nLayerCount = pDmeSequenceBase->m_eLayerList.m_Storage.m_Size;
    if ( nLayerCount > 0 )
    {
      while ( 1 )
      {
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v2->m_eLayerList.m_Storage.m_Memory.m_pMemory[v3]);
        v5 = v4;
        if ( v4 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
               a1: v4,
               a2: CDmeSequenceLayerBase::m_classType.u) != 0 )
        {
          v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                 a1: g_pDataModel.u,
                 a2: *(_DWORD *)(v5 + 68));
          if ( v6 != 0 )
          {
            numautolayers = pSequence->numautolayers;
            if ( numautolayers >= 0x40 )
              return;
            v8 = *(const char **)(v6 + 20);
            if ( v8 == (const char *)-1 )
              v8 = pDeltaStateName;
            V_strncpy(pDest: pSequence->autolayer[numautolayers].name, pSrc: v8, maxLen: 128);
            v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: pDmeSequenceBase->m_eLayerList.m_Storage.m_Memory.m_pMemory[v3]);
            v10 = v9;
            if ( v9 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                   a1: v9,
                   a2: CDmeSequenceLayerBase::m_classType.u) != 0 )
            {
              (*(void (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                a1: v10,
                a2: CDmeSequenceAddLayer::m_classType.u);
            }
            v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: pDmeSequenceBase->m_eLayerList.m_Storage.m_Memory.m_pMemory[v3]);
            v12 = v11;
            if ( v11 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
                   a1: v11,
                   a2: CDmeSequenceLayerBase::m_classType.u) != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
                   a1: v12,
                   a2: CDmeSequenceBlendLayer::m_classType.u) != 0 )
            {
              pSequence->autolayer[pSequence->numautolayers].start = *(float *)(v12 + 80);
              pSequence->autolayer[pSequence->numautolayers].peak = *(float *)(v12 + 88);
              pSequence->autolayer[pSequence->numautolayers].tail = *(float *)(v12 + 96);
              pSequence->autolayer[pSequence->numautolayers].end = *(float *)(v12 + 104);
              pSequence->autolayer[pSequence->numautolayers].flags |= *(_BYTE *)(v12 + 120) != 0 ? 0x80 : 0;
              pSequence->autolayer[pSequence->numautolayers].flags |= *(_BYTE *)(v12 + 112) != 0 ? 0x40 : 0;
              p_flags = &pSequence->autolayer[pSequence->numautolayers].flags;
              *p_flags |= *(_BYTE *)(v12 + 128) != 0 ? 0x200 : 0;
              v14 = &pSequence->autolayer[pSequence->numautolayers].flags;
              *v14 |= *(_BYTE *)(v12 + 136) != 0 ? 0x1000 : 0;
              pSequence->flags |= *(_BYTE *)(v12 + 136) != 0 ? 0x1000 : 0;
              v15 = *(_BYTE **)(v12 + 144);
              if ( v15 != (_BYTE *)-1 && v15 != nullptr && *v15 != 0 )
              {
                pSequence->autolayer[pSequence->numautolayers].flags |= 0x4000u;
                v16 = *(const char **)(v12 + 144);
                if ( v16 == (const char *)-1 )
                  v16 = pDeltaStateName;
                pSequence->autolayer[pSequence->numautolayers].pose = LookupPoseParameter(name: v16);
              }
            }
            ++pSequence->numautolayers;
          }
        }
        if ( ++v3 >= nLayerCount )
          break;
        v2 = pDmeSequenceBase;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A5F0
// Name: void LoadIkLockList(class CDmeSequenceBase __near *,class s_sequence_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadIkLockList(CDmeSequenceBase *pDmeSequenceBase, s_sequence_t *pSequence)
{
  CDmeSequenceBase *v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  int v6; // eax
  const char *v7; // eax
  const char *v8; // ecx
  const char *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm1_4
  int nIkLockCount; // [esp+Ch] [ebp-4h]

  v2 = pDmeSequenceBase;
  if ( pDmeSequenceBase != nullptr && pSequence != nullptr )
  {
    v3 = 0;
    nIkLockCount = pDmeSequenceBase->m_eIkLockList.m_Storage.m_Size;
    if ( nIkLockCount > 0 )
    {
      while ( 1 )
      {
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v2->m_eIkLockList.m_Storage.m_Memory.m_pMemory[v3]);
        v5 = v4;
        if ( v4 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
               a1: v4,
               a2: CDmeIkLock::m_classType.u) != 0 )
        {
          v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                 a1: g_pDataModel.u,
                 a2: *(_DWORD *)(v5 + 68));
          if ( v6 == 0 )
          {
            v8 = pDeltaStateName;
            if ( *(_DWORD *)(v5 + 20) != -1 )
              v8 = *(const char **)(v5 + 20);
            v9 = *(const char **)(v5 + 52);
            if ( v9 == (const char *)-1 )
              v9 = pDeltaStateName;
            MdlError(fmt: "1700: No IkChain element assigned to %s:%s\n", v9, v8);
          }
          v7 = *(const char **)(v6 + 20);
          if ( v7 == (const char *)-1 )
            v7 = pDeltaStateName;
          V_strncpy(pDest: pSequence->iklock[pSequence->numiklocks].name, pSrc: v7, maxLen: 128);
          v10 = *(float *)(v5 + 80);
          if ( v10 >= 0.0 )
          {
            if ( v10 > 1.0 )
              v10 = 1.0;
          }
          else
          {
            v10 = 0.0;
          }
          pSequence->iklock[pSequence->numiklocks].flPosWeight = v10;
          v11 = *(float *)(v5 + 88);
          if ( v11 >= 0.0 )
          {
            if ( v11 > 1.0 )
              v11 = 1.0;
          }
          else
          {
            v11 = 0.0;
          }
          pSequence->iklock[pSequence->numiklocks++].flLocalQWeight = 1.0 - v11;
        }
        if ( ++v3 >= nIkLockCount )
          break;
        v2 = pDmeSequenceBase;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A750
// Name: void LoadAnimationEventList(class CDmeSequenceBase __near *,class s_sequence_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadAnimationEventList(CDmeSequenceBase *pDmeSequenceBase, s_sequence_t *pSequence)
{
  CDmeSequenceBase *v2; // esi
  const CDmAttribute *Attribute; // eax
  CDmrGenericArrayConst *v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // esi
  int numevents; // eax
  const char *v9; // ecx
  _BYTE *v10; // eax
  const char *v11; // edi
  const char *m_pAsString; // edx
  const char *v13; // ecx
  const char *v14; // eax
  int nAnimEventCount; // [esp+Ch] [ebp-4h] BYREF

  v2 = pDmeSequenceBase;
  if ( pDmeSequenceBase != nullptr && pSequence != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pDmeSequenceBase, pAttributeName: "animationEventList");
    if ( Attribute != nullptr )
    {
      v4 = CDmrGenericArrayConst::CDmrGenericArrayConst(
             this: (CDmrGenericArrayConst *)&nAnimEventCount,
             pAttribute: Attribute);
      CDmrGenericArrayConst::Count(this: v4);
    }
    v5 = 0;
    nAnimEventCount = pDmeSequenceBase->m_eAnimationEventList.m_Storage.m_Size;
    if ( nAnimEventCount > 0 )
    {
      while ( 1 )
      {
        v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v2->m_eAnimationEventList.m_Storage.m_Memory.m_pMemory[v5]);
        v7 = v6;
        if ( v6 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeAnimationEvent::m_classType.u) != 0 )
        {
          numevents = pSequence->numevents;
          if ( numevents + 1 >= 1024 )
          {
            v11 = pDeltaStateName;
            if ( *(_DWORD *)(v7 + 20) != -1 )
              v11 = *(const char **)(v7 + 20);
            m_pAsString = pDeltaStateName;
            if ( pDmeSequenceBase->m_Name.m_Storage.u.CDmElement::m_Id != -1 )
              m_pAsString = pDmeSequenceBase->m_Name.m_Storage.u.m_pAsString;
            v13 = pDeltaStateName;
            if ( pDmeSequenceBase->m_Type.u.CDmElement::m_Id != -1 )
              v13 = pDmeSequenceBase->m_Type.u.m_pAsString;
            v14 = *(const char **)(v7 + 52);
            if ( v14 == (const char *)-1 )
              v14 = pDeltaStateName;
            MdlError(fmt: "1800: Too many %s's on %s:%s, ignoring from %s\n", v14, v13, m_pAsString, v11);
          }
          v9 = *(const char **)(v7 + 20);
          if ( v9 == (const char *)-1 )
            v9 = pDeltaStateName;
          V_strncpy(pDest: pSequence->event[numevents].eventname, pSrc: v9, maxLen: 128);
          pSequence->event[pSequence->numevents].frame = *(_DWORD *)(v7 + 68);
          v10 = *(_BYTE **)(v7 + 76);
          if ( v10 != (_BYTE *)-1 && v10 != nullptr && *v10 != 0 )
            V_strncpy(
              pDest: pSequence->event[pSequence->numevents].options,
              pSrc: *(const char **)(v7 + 76),
              maxLen: 64);
          else
            pSequence->event[pSequence->numevents].options[0] = 0;
          ++pSequence->numevents;
        }
        if ( ++v5 >= nAnimEventCount )
          break;
        v2 = pDmeSequenceBase;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A900
// Name: LoadSequenceBlends
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadSequenceBlends(CDmeMultiSequence *pDmeMultiSequence, s_sequence_t *pSequence)
{
  CDmeMultiSequence *v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // edi
  const char *v8; // eax
  BOOL v9; // esi
  int v10; // eax
  float v11; // xmm1_4
  int v12; // eax
  float min; // xmm0_4
  float max; // xmm0_4
  _DWORD *v15; // edi
  const char *v16; // eax
  BOOL v17; // esi
  const char *v18; // eax
  CDmeMotionControl *v19; // eax
  int StudioMotionControl; // eax
  bool v21; // sf
  const char *v22; // esi
  const char *v23; // eax
  const char *v24; // edx
  const char *v25; // edi
  const char *v26; // ecx
  CUtlSymbolLarge::<unnamed_type_u> v27; // [esp+0h] [ebp-10h]
  int nBlendCount; // [esp+Ch] [ebp-4h]
  int i; // [esp+1Ch] [ebp+Ch]

  if ( pSequence != nullptr )
  {
    v3 = pDmeMultiSequence;
    if ( pDmeMultiSequence != nullptr )
    {
      v4 = 0;
      nBlendCount = pDmeMultiSequence->m_eBlendList.m_Storage.m_Size;
      i = 0;
      if ( nBlendCount > 0 )
      {
        while ( 1 )
        {
          v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v3->m_eBlendList.m_Storage.m_Memory.m_pMemory[v4]);
          v6 = v5;
          if ( v5 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
                 a1: v5,
                 a2: CDmeSequenceBlendBase::m_classType.u) != 0 )
          {
            if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
                   a1: v6,
                   a2: CDmeSequenceBlend::m_classType.u,
                   a3: v27) != 0 )
            {
              v27.m_Id = CDmeSequenceBlend::m_classType.u.m_Id;
              v7 = (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 16))(a1: v6) != 0 ? v6 : 0;
              v8 = *(const char **)(v7 + 0x44);
              v9 = pSequence->paramindex[0] != -1;
              if ( v8 == (const char *)-1 )
                v8 = pDeltaStateName;
              v10 = LookupPoseParameter(name: v8);
              pSequence->paramindex[v9] = v10;
              pSequence->paramattachment[v9] = -1;
              pSequence->paramstart[v9] = *(float *)(v7 + 76);
              v11 = pSequence->paramstart[v9];
              v12 = v10;
              pSequence->paramend[v9] = *(float *)(v7 + 84);
              min = g_pose[v12].min;
              if ( v11 <= min )
                min = v11;
              g_pose[v12].min = min;
              if ( pSequence->paramend[v9] <= min )
                min = pSequence->paramend[v9];
              g_pose[v12].min = min;
              max = g_pose[v12].max;
              if ( max <= pSequence->paramstart[v9] )
                max = pSequence->paramstart[v9];
              g_pose[v12].max = max;
              if ( max <= pSequence->paramend[v9] )
                max = pSequence->paramend[v9];
              g_pose[v12].max = max;
            }
            else
            {
              v27.m_Id = CDmeSequenceCalcBlend::m_classType.u.m_Id;
              if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 16))(a1: v6) != 0 )
              {
                v15 = (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
                        a1: v6,
                        a2: CDmeSequenceCalcBlend::m_classType.u) != 0
                    ? (_DWORD *)v6
                    : nullptr;
                v16 = (const char *)v15[17];
                v17 = pSequence->paramindex[0] != -1;
                if ( v16 == (const char *)-1 )
                  v16 = pDeltaStateName;
                pSequence->paramindex[v17] = LookupPoseParameter(name: v16);
                v18 = (const char *)v15[19];
                if ( v18 == (const char *)-1 )
                  v18 = pDeltaStateName;
                pSequence->paramattachment[v17] = LookupAttachment(name: v18);
                v19 = (CDmeMotionControl *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                             a1: g_pDataModel.u,
                                             a2: v15[21]);
                StudioMotionControl = CDmeMotionControl::GetStudioMotionControl(this: v19);
                v21 = pSequence->paramattachment[v17] < 0;
                pSequence->paramcontrol[v17] = StudioMotionControl;
                if ( v21 )
                {
                  v22 = pDeltaStateName;
                  if ( v15[19] != -1 )
                    v22 = (const char *)v15[19];
                  v23 = *(const char **)(v15[20] + 20);
                  if ( v23 == (const char *)-1 )
                    v23 = pDeltaStateName;
                  v24 = pDeltaStateName;
                  if ( v15[5] != -1 )
                    v24 = (const char *)v15[5];
                  v25 = (const char *)v15[13];
                  v26 = pDeltaStateName;
                  if ( v25 != (const char *)-1 )
                    v26 = v25;
                  MdlWarning(fmt: "1606: Unknown Attachment For %s - %s.%s = %s\n", v26, v24, v23, v22);
                }
              }
            }
          }
          v4 = i + 1;
          i = v4;
          if ( v4 >= nBlendCount )
            break;
          v3 = pDmeMultiSequence;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AB90
// Name: LoadIncludeModelList
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadIncludeModelList(CDmeIncludeModelList *pIncludeModelList@<edi>)
{
  int m_Size; // ebx
  int i; // esi
  const char *m_pAsString; // eax
  const char *v4; // eax

  if ( pIncludeModelList != nullptr )
  {
    m_Size = pIncludeModelList->m_IncludeModels.m_Storage.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      if ( (unsigned int)g_numincludemodels >= 0x80 )
      {
        m_pAsString = pIncludeModelList->m_IncludeModels.m_Storage.m_Memory.m_pMemory[i].u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = pDeltaStateName;
        MdlError(fmt: "Too Many Include Models while including: \"%s\", Max: %d\n", m_pAsString, 128);
      }
      v4 = pIncludeModelList->m_IncludeModels.m_Storage.m_Memory.m_pMemory[i].u.m_pAsString;
      if ( v4 == (const char *)-1 )
        v4 = pDeltaStateName;
      V_strncpy(pDest: g_includemodel[g_numincludemodels].name, pSrc: v4, maxLen: 128);
      V_FixSlashes(pname: g_includemodel[g_numincludemodels].name, separator: 47);
      ++g_numincludemodels;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AC40
// Name: LoadMaterialGroups
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadMaterialGroups(const CDmeMaterialGroupList *pDmeMaterialGroupList)
{
  const CDmeMaterialGroupList *v1; // ecx
  int m_Size; // edx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int nMaterialGroupCount; // [esp+Ch] [ebp-Ch]
  int nTextureCount; // [esp+10h] [ebp-8h]
  int nMaterialCount; // [esp+14h] [ebp-4h]

  v1 = pDmeMaterialGroupList;
  if ( pDmeMaterialGroupList != nullptr )
  {
    if ( g_numskinref == 0 )
      g_numskinref = g_numtextures;
    m_Size = pDmeMaterialGroupList->m_MaterialGroups.m_Storage.m_Size;
    nMaterialGroupCount = m_Size;
    if ( (unsigned int)m_Size >= 0x20 )
      MdlError(fmt: "Too Many Material Groups, Max: %d\n", 32);
    v3 = g_numtextures;
    v4 = 0;
    nTextureCount = g_numtextures;
    if ( m_Size > 0 )
    {
      while ( 1 )
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v1->m_MaterialGroups.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmeMaterialGroup::m_classType.u) == 0 )
        {
          goto LABEL_22;
        }
        v7 = *(_DWORD *)(v6 + 80);
        nMaterialCount = v7;
        if ( v4 > 0 && v7 < v3 )
        {
          MdlWarning(
            fmt: "Only Setting %d of %d Textures via MaterialGroup %d, Skin %d will have bad materials\n",
            v7,
            v3,
            v4,
            v4);
          v7 = nMaterialCount;
        }
        v8 = 0;
        if ( v7 > 0 )
        {
          do
          {
            v9 = *(const char **)(*(_DWORD *)(v6 + 68) + 4 * v8);
            if ( v9 == (const char *)-1 )
              v9 = pDeltaStateName;
            v10 = LookupTexture(pTextureName: v9, bRelativePath: true);
            v11 = UseTextureAsMaterial(textureindex: v10);
            v12 = g_numtexturegroups;
            g_texturegroup[g_numtexturegroups][v4][v8] = v11;
            if ( v4 != 0 )
              g_texture[v11].parent = g_texturegroup[v12][0][v8];
            ++v8;
            g_numtexturelayers[v12] = v4 + 1;
            g_numtexturereps[v12] = v8;
          }
          while ( v8 < nMaterialCount );
        }
        else
        {
LABEL_22:
          v12 = g_numtexturegroups;
        }
        if ( ++v4 >= nMaterialGroupCount )
          break;
        v3 = nTextureCount;
        v1 = pDmeMaterialGroupList;
      }
      g_numtexturegroups = v12 + 1;
    }
    else
    {
      ++g_numtexturegroups;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ADB0
// Name: LoadEyeballs_0
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadEyeballs_0(s_model_t *ps_model_t, CDmeLODList *pDmeLODList)
{
  CDmeLODList *v2; // esi
  int v3; // eax
  int v4; // edi
  int v5; // esi
  const char *v6; // edi
  s_source_t *source; // ecx
  const char *v8; // eax
  s_source_t *v9; // ecx
  const char *v10; // ecx
  const char *v11; // edi
  const char *v12; // eax
  unsigned __int8 *v13; // esi
  int v14; // eax
  int v15; // eax
  const char *v16; // eax
  int v17; // eax
  int v18; // eax
  s_source_t *v19; // edx
  int v20; // ecx
  int *meshindex; // edx
  const char *v22; // ecx
  const char *v23; // edi
  const char *v24; // eax
  int v25; // ecx
  const char *v26; // eax
  s_eyeball_t *v27; // esi
  int v28; // eax
  double v29; // xmm0_8
  int v30; // eax
  int v31; // ecx
  const char **v32; // ebx
  signed int v33; // esi
  s_flexcontroller_t *v34; // edi
  int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // eax
  long double v38; // [esp-Ch] [ebp-80h]
  matrix3x4_t mDefRot; // [esp+Ch] [ebp-68h] BYREF
  Vector vTmp; // [esp+3Ch] [ebp-38h] BYREF
  float v41[3]; // [esp+48h] [ebp-2Ch] BYREF
  float in1[3]; // [esp+54h] [ebp-20h] BYREF
  int nEyeballCount; // [esp+60h] [ebp-14h]
  int nEyeballIndex; // [esp+64h] [ebp-10h]
  BOOL bRelative; // [esp+68h] [ebp-Ch]
  int i; // [esp+6Ch] [ebp-8h]
  int nSearchBoneIndex; // [esp+70h] [ebp-4h]
  int pDmeLODLista; // [esp+80h] [ebp+Ch]

  v2 = pDmeLODList;
  if ( pDmeLODList != nullptr )
  {
    AngleMatrix(angles: &g_defaultrotation, matrix: &mDefRot);
    nEyeballCount = pDmeLODList->m_EyeballList.m_Storage.m_Size;
    if ( nEyeballCount > 0 )
    {
      v3 = 0;
      nEyeballIndex = 0;
      while ( 1 )
      {
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v2->m_EyeballList.m_Storage.m_Memory.m_pMemory[v3]);
        v5 = 0;
        if ( v4 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
               a1: v4,
               a2: CDmeEyeball::m_classType.u) != 0 )
        {
          if ( ps_model_t->numeyeballs < 4u )
          {
            source = ps_model_t->source;
            nSearchBoneIndex = 0;
            if ( source->numbones <= 0 )
              goto LABEL_18;
            while ( 1 )
            {
              v8 = *(const char **)(v4 + 100);
              if ( v8 == (const char *)-1 )
                v8 = pDeltaStateName;
              if ( _V_stricmp(s1: ps_model_t->source->localBone[v5].name, s2: v8) == 0 )
                break;
              v9 = ps_model_t->source;
              ++v5;
              if ( ++nSearchBoneIndex >= v9->numbones )
                goto LABEL_18;
            }
            if ( nSearchBoneIndex >= 0 )
            {
              v13 = *(unsigned __int8 **)(v4 + 92);
              if ( v13 == (unsigned __int8 *)-1 )
                v13 = (unsigned __int8 *)pDeltaStateName;
              strchr(string: v13, chr: 0x2Fu);
              if ( v14 != 0 || (strchr(string: v13, chr: 0x5Cu), LOBYTE(bRelative) = 0, v15 != 0) )
                LOBYTE(bRelative) = 1;
              v16 = *(const char **)(v4 + 92);
              if ( v16 == (const char *)-1 )
                v16 = pDeltaStateName;
              v17 = LookupTexture(pTextureName: v16, bRelativePath: bRelative);
              v18 = UseTextureAsMaterial(textureindex: v17);
              v19 = ps_model_t->source;
              v20 = 0;
              if ( v19->nummeshes <= 0 )
                goto LABEL_36;
              meshindex = v19->meshindex;
              while ( *meshindex != v18 )
              {
                ++v20;
                ++meshindex;
                if ( v20 >= ps_model_t->source->nummeshes )
                  goto LABEL_36;
              }
              i = v20;
              if ( v20 >= 0 )
              {
                v25 = ps_model_t->numeyeballs++;
                v26 = *(const char **)(v4 + 20);
                v27 = &ps_model_t->eyeball[v25];
                if ( v26 == (const char *)-1 )
                  v26 = pDeltaStateName;
                V_strncpy(pDest: ps_model_t->eyeball[v25].name, pSrc: v26, maxLen: 128);
                v28 = i;
                v27->bone = nSearchBoneIndex;
                v27->mesh = v28;
                v27->radius = *(float *)(v4 + 68);
                v29 = (float)(*(float *)(v4 + 76) * 0.017453292);
                __libm_sse2_tan(x: v38);
                v30 = nSearchBoneIndex;
                *(float *)&v29 = v29;
                v27->zoffset = *(float *)&v29;
                v27->iris_scale = 1.0 / *(float *)(v4 + 84);
                VectorITransform(
                  in1: (const float *)(v4 + 108),
                  in2: &ps_model_t->source->boneToPose[v30],
                  out: &v27->org.x);
                in1[0] = 0.0;
                in1[1] = 0.0;
                in1[2] = 1.0;
                VectorIRotate(in1, in2: &mDefRot, out: &vTmp.x);
                VectorIRotate(in1: &vTmp.x, in2: &ps_model_t->source->boneToPose[v27->bone], out: &v27->up.x);
                v41[0] = 1.0;
                v41[1] = 0.0;
                v41[2] = 0.0;
                VectorIRotate(in1: v41, in2: &mDefRot, out: &vTmp.x);
                VectorIRotate(in1: &vTmp.x, in2: &ps_model_t->source->boneToPose[v27->bone], out: &v27->forward.x);
                v27->upperlidflexdesc = -1;
                v27->lowerlidflexdesc = -1;
              }
              else
              {
LABEL_36:
                v22 = pDeltaStateName;
                if ( *(_DWORD *)(v4 + 20) != -1 )
                  v22 = *(const char **)(v4 + 20);
                v23 = *(const char **)(v4 + 92);
                v24 = pDeltaStateName;
                if ( v23 != (const char *)-1 )
                  v24 = v23;
                MdlWarning(
                  fmt: "1102: Couldn't find eyeball material %s on model %s, ignoring eyeball %s\n",
                  v24,
                  ps_model_t->name,
                  v22);
              }
            }
            else
            {
LABEL_18:
              v10 = pDeltaStateName;
              if ( *(_DWORD *)(v4 + 20) != -1 )
                v10 = *(const char **)(v4 + 20);
              v11 = *(const char **)(v4 + 100);
              v12 = pDeltaStateName;
              if ( v11 != (const char *)-1 )
                v12 = v11;
              MdlWarning(
                fmt: "1101: Couldn't find bone %s on model %s, ignoring eyeball %s\n",
                v12,
                ps_model_t->name,
                v10);
            }
          }
          else
          {
            v6 = *(const char **)(v4 + 20);
            if ( v6 == (const char *)-1 )
              v6 = pDeltaStateName;
            MdlWarning(
              fmt: "1100: Max number of eyeballs reached for model %s, ignoring eyeball %s\n",
              ps_model_t->name,
              v6);
          }
        }
        v3 = nEyeballIndex + 1;
        nEyeballIndex = v3;
        if ( v3 >= nEyeballCount )
          break;
        v2 = pDmeLODList;
      }
      v31 = g_numflexcontrollers;
      v32 = szEyesFlexControllers_0;
      for ( pDmeLODLista = 2; pDmeLODLista != 0; --pDmeLODLista )
      {
        v33 = 0;
        if ( v31 <= 0 )
        {
LABEL_50:
          if ( v31 < 96 )
          {
            V_strncpy(pDest: g_flexcontroller[v31].name, pSrc: *v32, maxLen: 128);
            V_strncpy(pDest: g_flexcontroller[g_numflexcontrollers].type, pSrc: "eyes", maxLen: 128);
            v36 = g_numflexcontrollers;
            v37 = g_numflexcontrollers;
            g_flexcontroller[v37].min = -45.0;
            v31 = v36 + 1;
            g_flexcontroller[v37].max = 45.0;
            g_numflexcontrollers = v31;
          }
          else
          {
            MdlWarning(fmt: "1103: Couldn't make eyes flexcontroller %s, too many flex controllers defined\n", *v32);
            v31 = g_numflexcontrollers;
          }
        }
        else
        {
          v34 = g_flexcontroller;
          while ( 1 )
          {
            v35 = _V_strcmp(s1: *v32, s2: v34->name);
            v31 = g_numflexcontrollers;
            if ( v35 == 0 )
              break;
            ++v33;
            ++v34;
            if ( v33 >= (int)g_numflexcontrollers )
              goto LABEL_50;
          }
        }
        ++v32;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B210
// Name: public: bool const __near & CDmElement::GetValue<bool>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<bool> *__thiscall CDmElement::GetValue<bool>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<bool>(this: Attribute);
  else
    return &`CDmElement::GetValue<bool>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040B320
// Name: public: int const __near & CDmElement::GetValue<int>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CDmElement::GetValue<int>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<int>(this: Attribute);
  else
    return &`CDmElement::GetValue<int>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040B370
// Name: public: class Quaternion const __near & CDmElement::GetValue<class Quaternion>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmElement::GetValue<Quaternion>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    return &`CDmElement::GetValue<Quaternion>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040B3E0
// Name: public: class Vector const __near & CDmElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmElement::GetValue<Vector>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Vector>(this: Attribute);
  else
    return &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040B970
// Name: void LoadIkRuleList(class CDmeSequence __near *,struct s_animation_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadIkRuleList(CDmeSequence *pDmeSimpleSequence, s_animation_t *pAnimation)
{
  CDmeSequence *v2; // esi
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  CDmeIkFootstepRule *v6; // eax
  const char *v7; // eax
  const char *v8; // esi
  int v9; // ebx
  s_ikchain_t *v10; // edi
  const char *Name; // eax
  const char *v12; // eax
  const char *v13; // esi
  int *v14; // edi
  CDmElement *v15; // ebx
  char v16; // al
  CDmeIkTouchRule *v17; // ecx
  _DWORD *v18; // eax
  const char *m_pAsString; // ecx
  CDmeIkFootstepRule *v20; // ecx
  int v21; // ebx
  float *p_height; // ebx
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v24; // eax
  CDmeIkFootstepRule *v25; // ecx
  int v26; // ebx
  float *p_floor; // ebx
  CDmAttribute *v28; // eax
  CDmaVar<float> *v29; // eax
  CDmeIkFootstepRule *v30; // ebx
  int v31; // edx
  CDmAttribute *v32; // eax
  CDmaVar<float> *v33; // eax
  const char *v34; // eax
  const char *ValueString; // eax
  CDmaVar<Vector> *v36; // eax
  _DWORD *v37; // eax
  s_animcmd_t *v38; // ecx
  const char *v39; // eax
  const char *v40; // esi
  const char *v41; // eax
  const char *v42; // esi
  const char *v43; // eax
  const char *v44; // esi
  matrix3x4_t mDefRot; // [esp+Ch] [ebp-44h] BYREF
  int nIkRuleCount; // [esp+3Ch] [ebp-14h]
  float v47; // [esp+40h] [ebp-10h] BYREF
  CDmeIkTouchRule *pDmeIkTouchRule; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  CDmeIkFootstepRule *pDmeIkFootstepRule; // [esp+4Ch] [ebp-4h]

  v2 = pDmeSimpleSequence;
  if ( pDmeSimpleSequence == nullptr )
    return;
  AngleMatrix(angles: &g_defaultrotation, matrix: &mDefRot);
  nIkRuleCount = pDmeSimpleSequence->m_eIkRuleList.m_Storage.m_Size;
  if ( nIkRuleCount <= 0 )
    return;
  v3 = 0;
  i = 0;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v2->m_eIkRuleList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (_DWORD *)v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeIkRule::m_classType.u) == 0 )
    {
      goto LABEL_66;
    }
    if ( pAnimation->numcmds >= 64 )
      break;
    v6 = (CDmeIkFootstepRule *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                                 a1: g_pDataModel.u,
                                 a2: v5[17]);
    pDmeIkFootstepRule = v6;
    if ( v6 == nullptr )
    {
      v7 = (const char *)v5[5];
      if ( v7 == (const char *)-1 )
        v7 = pDeltaStateName;
      v8 = (const char *)v5[13];
      if ( v8 == (const char *)-1 )
        v8 = pDeltaStateName;
      MdlError(fmt: "1501: No IkChain element assigned to %s:%s\n", v8, v7);
    }
    v9 = 0;
    if ( g_numikchains <= 0 )
      goto LABEL_21;
    v10 = g_ikchain;
    while ( 1 )
    {
      Name = CDmElement::GetName(this: v6);
      if ( _V_stricmp(s1: Name, s2: v10->name) == 0 )
        break;
      ++v9;
      ++v10;
      if ( v9 >= g_numikchains )
        goto LABEL_21;
      v6 = pDmeIkFootstepRule;
    }
    if ( v9 < 0 )
    {
LABEL_21:
      v12 = (const char *)v5[13];
      if ( v12 == (const char *)-1 )
        v12 = pDeltaStateName;
      v13 = (const char *)v5[5];
      if ( v13 == (const char *)-1 )
        v13 = pDeltaStateName;
      MdlWarning(fmt: "1504: Cannot find IkChain referenced by IkRule %s:%s, ignoring\n", v13, v12);
      goto LABEL_66;
    }
    v14 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 424);
    memset(dst: (unsigned __int8 *)v14, value: 0, count: 0x1A8u);
    if ( v14 == nullptr )
    {
      v43 = (const char *)v5[13];
      if ( v43 == (const char *)-1 )
        v43 = pDeltaStateName;
      v44 = (const char *)v5[5];
      if ( v44 == (const char *)-1 )
        v44 = pDeltaStateName;
      MdlWarning(fmt: "1502: Cannot allocate memory for IkRule %s:%s, ignoring\n", v44, v43);
      return;
    }
    *v14 = v9;
    v14[3] = v9;
    pDmeIkTouchRule = (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v5 + 16))(
                        a1: v5,
                        a2: CDmeIkTouchRule::m_classType.u) != 0
                    ? (CDmeIkTouchRule *)v5
                    : nullptr;
    pDmeIkFootstepRule = (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v5 + 16))(
                           a1: v5,
                           a2: CDmeIkFootstepRule::m_classType.u) != 0
                       ? (CDmeIkFootstepRule *)v5
                       : nullptr;
    v15 = (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v5 + 16))(
            a1: v5,
            a2: CDmeIkAttachmentRule::m_classType.u) != 0
        ? (CDmElement *)v5
        : nullptr;
    v16 = (*(int (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v5 + 16))(
            a1: v5,
            a2: CDmeIkReleaseRule::m_classType.u);
    v17 = pDmeIkTouchRule;
    v18 = v16 != 0 ? v5 : nullptr;
    if ( pDmeIkTouchRule != nullptr )
    {
      v14[2] = 1;
      m_pAsString = v17->m_sBoneName.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      V_strncpy(pDest: (char *)v14 + 16, pSrc: m_pAsString, maxLen: 128);
      goto LABEL_54;
    }
    v20 = pDmeIkFootstepRule;
    if ( pDmeIkFootstepRule != nullptr )
    {
      v21 = *v14;
      v14[2] = 3;
      p_height = &g_ikchain[v21].height;
      Attribute = CDmElement::FindAttribute(this: v20, pAttributeName: "height");
      if ( Attribute != nullptr )
        v24 = CDmAttribute::GetValue<float>(this: Attribute);
      else
        v24 = (CDmaVar<float> *)p_height;
      v25 = pDmeIkFootstepRule;
      v26 = *v14;
      v14[76] = SLODWORD(v24->m_Storage);
      p_floor = &g_ikchain[v26].floor;
      v28 = CDmElement::FindAttribute(this: v25, pAttributeName: "floor");
      if ( v28 != nullptr )
        v29 = CDmAttribute::GetValue<float>(this: v28);
      else
        v29 = (CDmaVar<float> *)p_floor;
      v30 = pDmeIkFootstepRule;
      v31 = *v14;
      v14[77] = SLODWORD(v29->m_Storage);
      v47 = g_ikchain[v31].radius * 2.0;
      v32 = CDmElement::FindAttribute(this: v30, pAttributeName: "pad");
      if ( v32 != nullptr )
        v33 = CDmAttribute::GetValue<float>(this: v32);
      else
        v33 = (CDmaVar<float> *)&v47;
      *((float *)v14 + 78) = v33->m_Storage * 0.5;
      if ( CDmElement::HasAttribute(this: v30, pAttributeName: "contact", type: AT_INT) )
        v14[83] = CDmElement::GetValue<int>(this: v30, pAttributeName: "contact")->m_Storage;
      goto LABEL_54;
    }
    if ( v15 != nullptr )
    {
      v14[2] = 5;
      v34 = *((const char **)&v15[1].m_ref + 1);
      if ( v34 == (const char *)-1 )
        v34 = pDeltaStateName;
      V_strncpy(pDest: (char *)v14 + 144, pSrc: v34, maxLen: 128);
      if ( CDmElement::HasAttribute(this: v15, pAttributeName: "fallbackBone", type: AT_STRING) )
      {
        ValueString = CDmElement::GetValueString(this: v15, pAttributeName: "fallbackBone");
        V_strncpy(pDest: (char *)v14 + 16, pSrc: ValueString, maxLen: 128);
      }
      if ( CDmElement::HasAttribute(this: v15, pAttributeName: "fallbackPosition", type: AT_VECTOR3) )
      {
        v36 = CDmElement::GetValue<Vector>(this: v15, pAttributeName: "fallbackPosition");
        VectorIRotate(in1: &v36->m_Storage.x, in2: &mDefRot, out: (float *)v14 + 69);
        v14[68] = -1;
      }
      if ( CDmElement::HasAttribute(this: v15, pAttributeName: "fallbackRotation", type: AT_QUATERNION) )
      {
        *((Quaternion *)v14 + 18) = CDmElement::GetValue<Quaternion>(this: v15, pAttributeName: "fallbackRotation")->m_Storage;
        v14[68] = -1;
      }
      goto LABEL_54;
    }
    if ( v18 != nullptr )
    {
      v14[2] = 4;
LABEL_54:
      if ( v5[23] == 1 )
      {
        *((_WORD *)v14 + 168) = 1;
      }
      else if ( v5[23] == 2 )
      {
        *((_WORD *)v14 + 168) = 256;
      }
      v37 = (_DWORD *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
                        a1: g_pDataModel.u,
                        a2: v5[20]);
      if ( v37 != nullptr )
      {
        v14[79] = v37[17];
        v14[80] = v37[19];
        v14[81] = v37[21];
        v14[82] = v37[23];
      }
      v38 = &pAnimation->cmds[pAnimation->numcmds];
      v38->cmd = 8;
      v38->u.weightlist.index = (int)v14;
      ++pAnimation->numcmds;
      goto LABEL_66;
    }
    v39 = (const char *)v5[13];
    if ( v39 == (const char *)-1 )
      v39 = pDeltaStateName;
    v40 = (const char *)v5[5];
    if ( v40 == (const char *)-1 )
      v40 = pDeltaStateName;
    MdlWarning(fmt: "1500: Unknown IkRuleType %s:%s, ignoring\n", v40, v39);
LABEL_66:
    v3 = i + 1;
    i = v3;
    if ( v3 >= nIkRuleCount )
      return;
    v2 = pDmeSimpleSequence;
  }
  v41 = (const char *)v5[5];
  if ( v41 == (const char *)-1 )
    v41 = pDeltaStateName;
  v42 = (const char *)v5[13];
  if ( v42 == (const char *)-1 )
    v42 = pDeltaStateName;
  MdlWarning(fmt: "1503: Too many animation commands for anim: %s, ignoring from %s:%s\n", pAnimation->name, v42, v41);
}

//------------------------------------------------------------------------------
// Address: 0x0040BF60
// Name: public: class CDmElement __near * CDmElement::GetValueElement<class CDmElement>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmElement::GetValueElement<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BFF0
// Name: public: class CDmeBBox __near * CDmElement::GetValueElement<class CDmeBBox>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeBBox *__thiscall CDmElement::GetValueElement<CDmeBBox>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeBBox::m_classType.u) != 0 )
  {
    return (CDmeBBox *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C080
// Name: public: class CDmeModel __near * CDmElement::GetValueElement<class CDmeModel>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmElement::GetValueElement<CDmeModel>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeModel::m_classType.u) != 0 )
  {
    return (CDmeModel *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C110
// Name: public: class CDmeDag __near * CDmElement::GetValueElement<class CDmeDag>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmElement::GetValueElement<CDmeDag>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return (CDmeDag *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C1A0
// Name: public: class CDmeCombinationOperator __near * CDmElement::GetValueElement<class CDmeCombinationOperator>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationOperator *__thiscall CDmElement::GetValueElement<CDmeCombinationOperator>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeCombinationOperator::m_classType.u) != 0 )
  {
    return (CDmeCombinationOperator *)(v5 - 4);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C230
// Name: public: class CDmeAnimationList __near * CDmElement::GetValueElement<class CDmeAnimationList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationList *__thiscall CDmElement::GetValueElement<CDmeAnimationList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeAnimationList::m_classType.u) != 0 )
  {
    return (CDmeAnimationList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C2C0
// Name: public: class CDmeBodyGroupList __near * CDmElement::GetValueElement<class CDmeBodyGroupList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeBodyGroupList *__thiscall CDmElement::GetValueElement<CDmeBodyGroupList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeBodyGroupList::m_classType.u) != 0 )
  {
    return (CDmeBodyGroupList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C350
// Name: public: class CDmeEyeballGlobals __near * CDmElement::GetValueElement<class CDmeEyeballGlobals>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeEyeballGlobals *__thiscall CDmElement::GetValueElement<CDmeEyeballGlobals>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeEyeballGlobals::m_classType.u) != 0 )
  {
    return (CDmeEyeballGlobals *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C3E0
// Name: public: class CDmeCollisionModel __near * CDmElement::GetValueElement<class CDmeCollisionModel>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionModel *__thiscall CDmElement::GetValueElement<CDmeCollisionModel>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeCollisionModel::m_classType.u) != 0 )
  {
    return (CDmeCollisionModel *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C470
// Name: public: class CDmeMaterialGroupList __near * CDmElement::GetValueElement<class CDmeMaterialGroupList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialGroupList *__thiscall CDmElement::GetValueElement<CDmeMaterialGroupList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeMaterialGroupList::m_classType.u) != 0 )
  {
    return (CDmeMaterialGroupList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C500
// Name: public: class CDmeBoneMaskList __near * CDmElement::GetValueElement<class CDmeBoneMaskList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeBoneMaskList *__thiscall CDmElement::GetValueElement<CDmeBoneMaskList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeBoneMaskList::m_classType.u) != 0 )
  {
    return (CDmeBoneMaskList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C590
// Name: public: class CDmePoseParameterList __near * CDmElement::GetValueElement<class CDmePoseParameterList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmePoseParameterList *__thiscall CDmElement::GetValueElement<CDmePoseParameterList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmePoseParameterList::m_classType.u) != 0 )
  {
    return (CDmePoseParameterList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C620
// Name: public: class CDmeAnimBlockSize __near * CDmElement::GetValueElement<class CDmeAnimBlockSize>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimBlockSize *__thiscall CDmElement::GetValueElement<CDmeAnimBlockSize>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeAnimBlockSize::m_classType.u) != 0 )
  {
    return (CDmeAnimBlockSize *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C6B0
// Name: public: class CDmeSequenceList __near * CDmElement::GetValueElement<class CDmeSequenceList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceList *__thiscall CDmElement::GetValueElement<CDmeSequenceList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeSequenceList::m_classType.u) != 0 )
  {
    return (CDmeSequenceList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C740
// Name: public: class CDmeIncludeModelList __near * CDmElement::GetValueElement<class CDmeIncludeModelList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeIncludeModelList *__thiscall CDmElement::GetValueElement<CDmeIncludeModelList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeIncludeModelList::m_classType.u) != 0 )
  {
    return (CDmeIncludeModelList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C7D0
// Name: public: class CDmeDefineBoneList __near * CDmElement::GetValueElement<class CDmeDefineBoneList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeDefineBoneList *__thiscall CDmElement::GetValueElement<CDmeDefineBoneList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeDefineBoneList::m_classType.u) != 0 )
  {
    return (CDmeDefineBoneList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C860
// Name: public: class CDmeHitboxSetList __near * CDmElement::GetValueElement<class CDmeHitboxSetList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeHitboxSetList *__thiscall CDmElement::GetValueElement<CDmeHitboxSetList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeHitboxSetList::m_classType.u) != 0 )
  {
    return (CDmeHitboxSetList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C8F0
// Name: public: class CDmeBoneFlexDriverList __near * CDmElement::GetValueElement<class CDmeBoneFlexDriverList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeBoneFlexDriverList *__thiscall CDmElement::GetValueElement<CDmeBoneFlexDriverList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeBoneFlexDriverList::m_classType.u) != 0 )
  {
    return (CDmeBoneFlexDriverList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CA10
// Name: class CTwistBone __near * Construct<class CTwistBone>(class CTwistBone __near *)
// Source: json
//------------------------------------------------------------------------------
CTwistBone *__cdecl Construct<CTwistBone>(CTwistBone *pMemory)
{
  CTwistBone *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->m_twistBoneTargets.m_Memory.m_pMemory = nullptr;
  pMemory->m_twistBoneTargets.m_Memory.m_nAllocationCount = 0;
  pMemory->m_twistBoneTargets.m_Memory.m_nGrowSize = 0;
  pMemory->m_twistBoneTargets.m_Size = 0;
  pMemory->m_twistBoneTargets.m_pElements = nullptr;
  pMemory->m_bInverse = false;
  pMemory->m_vUpVector.x = 0.0;
  pMemory->m_vUpVector.y = 0.0;
  pMemory->m_vUpVector.z = 0.0;
  pMemory->m_szParentBoneName[0] = 0;
  pMemory->m_nParentBone = -1;
  pMemory->m_qBaseRotation.x = 0.0;
  pMemory->m_qBaseRotation.y = 0.0;
  pMemory->m_qBaseRotation.z = 0.0;
  pMemory->m_qBaseRotation.w = 0.0;
  pMemory->m_szChildBoneName[0] = 0;
  pMemory->m_nChildBone = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CA90
// Name: public: LodScriptData_t::LodScriptData_t(void)
// Source: json
//------------------------------------------------------------------------------
LodScriptData_t *__thiscall LodScriptData_t::LodScriptData_t(LodScriptData_t *this)
{
  this->modelReplacements.m_Memory.m_pMemory = nullptr;
  this->modelReplacements.m_Memory.m_nAllocationCount = 0;
  this->modelReplacements.m_Memory.m_nGrowSize = 0;
  this->modelReplacements.m_Size = 0;
  this->modelReplacements.m_pElements = nullptr;
  this->boneReplacements.m_Memory.m_pMemory = nullptr;
  this->boneReplacements.m_Memory.m_nAllocationCount = 0;
  this->boneReplacements.m_Memory.m_nGrowSize = 0;
  this->boneReplacements.m_Size = 0;
  this->boneReplacements.m_pElements = nullptr;
  this->boneTreeCollapses.m_Memory.m_pMemory = nullptr;
  this->boneTreeCollapses.m_Memory.m_nAllocationCount = 0;
  this->boneTreeCollapses.m_Memory.m_nGrowSize = 0;
  this->boneTreeCollapses.m_Size = 0;
  this->boneTreeCollapses.m_pElements = nullptr;
  this->materialReplacements.m_Memory.m_pMemory = nullptr;
  this->materialReplacements.m_Memory.m_nAllocationCount = 0;
  this->materialReplacements.m_Memory.m_nGrowSize = 0;
  this->materialReplacements.m_Size = 0;
  this->materialReplacements.m_pElements = nullptr;
  this->meshRemovals.m_Memory.m_pMemory = nullptr;
  this->meshRemovals.m_Memory.m_nAllocationCount = 0;
  this->meshRemovals.m_Memory.m_nGrowSize = 0;
  this->meshRemovals.m_Size = 0;
  this->meshRemovals.m_pElements = nullptr;
  *(_WORD *)&this->m_bFacialAnimation = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040CAF0
// Name: void LoadModelInfo(class CDmElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadModelInfo(CDmElement *pRoot, const char *pFullPath)
{
  CDmElement *Value; // eax
  int v3; // edi
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ecx
  int v7; // eax
  int v8; // esi
  int v9; // eax
  CDmrElementArray<CDmElement> arrSources; // [esp+Ch] [ebp-8h] BYREF

  Value = CDmElement::GetValueElement<CDmElement>(this: pRoot, pAttributeName: "makefile");
  v3 = 0;
  if ( Value != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: Value, pAttributeName: "sources");
    if ( Attribute != nullptr )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&arrSources);
      if ( (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        arrSources.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
      }
      else
      {
        arrSources.m_pAttribute = nullptr;
        m_pData = nullptr;
      }
      arrSources.m_pStorage = m_pData;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( arrSources.m_pAttribute != nullptr )
            m_Size = m_pData->m_Size;
          else
            m_Size = 0;
          if ( v3 >= m_Size )
            return;
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: m_pData->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            break;
          }
LABEL_17:
          m_pData = arrSources.m_pStorage;
          ++v3;
        }
        v9 = *(_DWORD *)(v8 + 20);
        if ( v9 != -1 )
        {
          if ( v9 != 0 )
            ProcessOriginalContentFile(szDataFile: pFullPath, szOriginalContentFile: *(const char **)(v8 + 20));
          goto LABEL_17;
        }
        ProcessOriginalContentFile(szDataFile: pFullPath, szOriginalContentFile: pDeltaStateName);
        m_pData = arrSources.m_pStorage;
        ++v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CBD0
// Name: bool LoadBaseConstraintParams(class CConstraintBoneBase __near *,class CDmeRigBaseConstraintOperator __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadBaseConstraintParams(
        CConstraintBoneBase *pConstraintBone,
        CDmeRigBaseConstraintOperator *pDmeBaseConstraint)
{
  int v4; // eax
  int v5; // eax
  int v6; // edi
  s_constraintbonetarget_t *v7; // esi
  const char *m_pAsString; // eax
  int v9; // edi
  const CDmeDag *v10; // eax
  const char *v11; // eax
  Quaternion qRot; // [esp+Ch] [ebp-14h] BYREF
  CDmeDag *pDmeTargetDag; // [esp+1Ch] [ebp-4h]
  int i; // [esp+2Ch] [ebp+Ch]

  if ( pDmeBaseConstraint->m_Targets.m_Storage.m_Size <= 0 )
    return 0;
  AngleQuaternion(angles: &g_defaultrotation, outQuat: &qRot);
  v4 = 0;
  for ( i = 0; v4 < pDmeBaseConstraint->m_Targets.m_Storage.m_Size; i = v4 )
  {
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: pDmeBaseConstraint->m_Targets.m_Storage.m_Memory.m_pMemory[v4]);
    v6 = v5;
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeConstraintTarget::m_classType.u) != 0 )
    {
      pDmeTargetDag = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                                   a1: g_pDataModel.u,
                                   a2: *(_DWORD *)(v6 + 68));
      if ( pDmeTargetDag != nullptr )
      {
        v7 = &pConstraintBone->m_targets.m_Memory.m_pMemory[CUtlVector<s_constraintbonetarget_t,CUtlMemory<s_constraintbonetarget_t,int>>::AddToTail(this: &pConstraintBone->m_targets)];
        m_pAsString = pDmeTargetDag->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = pDeltaStateName;
        V_strncpy(pDest: v7->m_szBoneName, pSrc: m_pAsString, maxLen: 128);
        v7->m_nBone = -1;
        v7->m_flWeight = *(float *)(v6 + 80);
        *(_QWORD *)&v7->m_qOffset.x = *(_QWORD *)(v6 + 104);
        *(_QWORD *)&v7->m_qOffset.z = *(_QWORD *)(v6 + 112);
        if ( ((int (__thiscall *)(_DWORD, _DWORD))pDmeBaseConstraint->IsA)(
               a1: &pDmeBaseConstraint->CDmElement,
               a2: (CUtlSymbolLarge)CDmeRigPointConstraintOperator::m_classType.u.m_Id) )
        {
          VectorRotate(in1: (const Vector *)(v6 + 88), in2: &qRot, out: &v7->m_vOffset);
        }
        else
        {
          v7->m_vOffset.x = *(float *)(v6 + 88);
          v7->m_vOffset.y = *(float *)(v6 + 92);
          v7->m_vOffset.z = *(float *)(v6 + 96);
        }
      }
    }
    v4 = i + 1;
  }
  if ( pConstraintBone->m_targets.m_Size <= 0 )
    return 0;
  v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: pDmeBaseConstraint->m_Slave.m_Storage.m_Handle);
  if ( v9 == 0 )
    return 0;
  v10 = pDmeBaseConstraint->GetSlave(this: pDmeBaseConstraint);
  if ( v10 == nullptr )
    return 0;
  v11 = v10->m_Name.m_Storage.u.m_pAsString;
  if ( v11 == (const char *)-1 )
    v11 = pDeltaStateName;
  V_strncpy(pDest: pConstraintBone->m_slave.m_szBoneName, pSrc: v11, maxLen: 128);
  pConstraintBone->m_slave.m_nBone = -1;
  pConstraintBone->m_slave.m_vBaseTranslate = *(Vector *)(v9 + 80);
  pConstraintBone->m_slave.m_qBaseRotation = *(Quaternion *)(v9 + 96);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040CDD0
// Name: LoadSpecializedConstraintParams_CDmeRigAimConstraintOperator_CAimConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadSpecializedConstraintParams_CDmeRigAimConstraintOperator_CAimConstraint_@<al>(
        CAimConstraint *pConstraint@<esi>,
        CDmeRigAimConstraintOperator *pDmeConstraint)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Quaternion> *v4; // eax
  CDmAttribute *v5; // eax
  CDmaVar<Vector> *v6; // eax
  CDmElement *Value; // eax
  const char *m_pAsString; // eax
  Quaternion qRot; // [esp+0h] [ebp-10h] BYREF

  AngleQuaternion(angles: &g_defaultrotation, outQuat: &qRot);
  if ( (`CDmElement::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  v2 = &pDmeConstraint->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &pDmeConstraint->CDmElement, pAttributeName: "aimOffset");
  if ( Attribute != nullptr )
    v4 = CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    v4 = &`CDmElement::GetValue<Quaternion>'::`2'::defaultVal;
  pConstraint->m_qAimOffset = v4->m_Storage;
  if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "upVector");
  if ( v5 != nullptr )
    v6 = CDmAttribute::GetValue<Vector>(this: v5);
  else
    v6 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
  VectorRotate(in1: &v6->m_Storage, in2: &qRot, out: &pConstraint->m_vUpVector);
  Value = CDmElement::GetValueElement<CDmElement>(this: v2, pAttributeName: "upSpaceTarget");
  if ( Value != nullptr )
  {
    m_pAsString = Value->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    V_strncpy(pDest: pConstraint->m_szUpSpaceTargetBone, pSrc: m_pAsString, maxLen: 128);
  }
  pConstraint->m_nUpSpaceTargetBone = -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040CF20
// Name: LoadSequenceList
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadSequenceList(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *animations@<esi>,
        CDmeMultiSequence *pDmeMultiSequence)
{
  CDmeMultiSequence *v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // edi
  const char *v6; // eax
  s_animation_t *v7; // ebx
  const char *v8; // edi
  const char *Name; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  s_animation_t **v12; // ecx
  int v13; // eax
  s_animation_t **v14; // eax
  int nSequenceCount; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = pDmeMultiSequence;
  if ( pDmeMultiSequence != nullptr )
  {
    v3 = 0;
    nSequenceCount = pDmeMultiSequence->m_eSequenceList.m_Storage.m_Size;
    i = 0;
    if ( nSequenceCount > 0 )
    {
      while ( 1 )
      {
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v2->m_eSequenceList.m_Storage.m_Memory.m_pMemory[v3]);
        v5 = v4;
        if ( v4 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
               a1: v4,
               a2: CDmeSequence::m_classType.u) != 0 )
        {
          v6 = *(const char **)(v5 + 20);
          if ( v6 == (const char *)-1 )
            v6 = pDeltaStateName;
          v7 = LookupAnimation(name: v6);
          if ( v7 != nullptr )
          {
            m_pMemory = (int)animations[1].m_pMemory;
            m_nAllocationCount = animations->m_nAllocationCount;
            if ( m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: animations, num: m_pMemory - m_nAllocationCount + 1);
            ++animations[1].m_pMemory;
            v12 = (s_animation_t **)animations->m_pMemory;
            v13 = (int)animations[1].m_pMemory - m_pMemory - 1;
            animations[1].m_nAllocationCount = (int)animations->m_pMemory;
            if ( v13 > 0 )
              _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 4 * v13);
            v14 = (s_animation_t **)&animations->m_pMemory[m_pMemory];
            if ( v14 != nullptr )
              *v14 = v7;
          }
          else
          {
            v8 = *(const char **)(v5 + 20);
            if ( v8 == (const char *)-1 )
              v8 = pDeltaStateName;
            Name = CDmElement::GetName(this: pDmeMultiSequence);
            MdlWarning(fmt: "1208: DmeSequence %s: Couldn't find referenced animation: %s\n", Name, v8);
          }
        }
        v3 = i + 1;
        i = v3;
        if ( v3 >= nSequenceCount )
          break;
        v2 = pDmeMultiSequence;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D170
// Name: public: struct s_bone_t __near * __near & CUtlVectorAuto<struct s_bone_t __near *>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
s_bone_t **__thiscall CUtlVectorAuto<s_bone_t *>::operator[](CUtlVectorAuto<s_bone_t *> *this, int i)
{
  if ( this->m_Size < i + 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)this,
      elem: this->m_Size,
      num: i + 1 - this->m_Size);
  return &this->m_Memory.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x0040D300
// Name: LoadAttachments
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadAttachments(CDmeDag *pRoot, CDmeDag *pDag, s_source_t *pSource, bool bStaticProp)
{
  CDmeDag *v4; // ebx
  CDmeShape *Shape; // eax
  CDmeShape *v6; // edi
  s_attachment_t *v7; // esi
  const char *m_pAsString; // eax
  const char *v9; // eax
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax

  v4 = pDag;
  Shape = CDmeDag::GetShape(this: pDag);
  v6 = Shape;
  if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeAttachment::m_classType) && pDag != pRoot )
  {
    v7 = &pSource->m_Attachments.m_Memory.m_pMemory[CUtlVector<s_attachment_t,CUtlMemory<s_attachment_t,int>>::AddToTail(this: &pSource->m_Attachments)];
    memset(dst: (unsigned __int8 *)v7, value: 0, count: sizeof(s_attachment_t));
    m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    V_strncpy(pDest: v7->name, pSrc: m_pAsString, maxLen: 128);
    v9 = pDag->m_Name.m_Storage.u.m_pAsString;
    if ( v9 == (const char *)-1 )
      v9 = pDeltaStateName;
    V_strncpy(pDest: v7->bonename, pSrc: v9, maxLen: 128);
    SetIdentityMatrix(matrix: &v7->local);
    if ( bStaticProp )
    {
      CDmeDag::GetAbsTransform(this: pDag, matAbsTransform: &v7->local);
    }
    else
    {
      if ( LOBYTE(v6[1].__vftable) != 0 )
        v7->type |= 2u;
      if ( v6[1].m_Id.m_Value[4] != 0 )
        v7->flags |= 0x10000u;
    }
    v4 = pDag;
  }
  Phase = CDmElementFramework::GetPhase(this: v4);
  for ( i = 0; i < Phase; ++i )
  {
    Child = CDmeDag::GetChild(this: v4, i);
    if ( Child != nullptr )
      LoadAttachments(pRoot, pDag: Child, pSource, bStaticProp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D420
// Name: GetDependentOperators
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDependentOperators(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList,
        CUtlSymbolTable::StringPool_t *pDmeOperator)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v2; // edx
  int k; // edi
  CUtlSymbolTable::StringPool_t *v4; // eax
  int *v5; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // esi
  void (__thiscall *v11)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int v12; // edi
  CDmElement *m_pOwner; // esi
  void (__stdcall *v14)(CUtlSymbolLarge *, const char *); // edx
  int v15; // eax
  const CDmElement *v16; // esi
  void (__stdcall *v17)(CUtlSymbolLarge *, const char *); // eax
  int m; // edi
  CDmElement *v19; // esi
  CDmeOperator *v20; // eax
  CDmAttribute **v21; // eax
  CUtlSymbolLarge v22; // [esp-Ch] [ebp-5Ch] BYREF
  BOOL v23; // [esp-8h] [ebp-58h]
  TraversalDepth_t v24; // [esp-4h] [ebp-54h]
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList0; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList1; // [esp+20h] [ebp-30h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outAttrList; // [esp+34h] [ebp-1Ch] BYREF
  CDmElement *p_m_SpaceUsed; // [esp+48h] [ebp-8h]
  int i; // [esp+4Ch] [ebp-4h]
  int j; // [esp+5Ch] [ebp+Ch]

  if ( pDmeOperator != nullptr )
  {
    p_m_SpaceUsed = (CDmElement *)&pDmeOperator->m_SpaceUsed;
    if ( pDmeOperator != (CUtlSymbolTable::StringPool_t *)-4
      && (*(unsigned __int8 (__thiscall **)(int *, CUtlSymbolLarge::<unnamed_type_u>))(pDmeOperator->m_SpaceUsed + 16))(
           a1: &pDmeOperator->m_SpaceUsed,
           a2: CDmeOperator::m_classType.u) != 0 )
    {
      v2 = operatorList;
      for ( k = 0; k < (int)v2[1].m_pMemory; ++k )
      {
        v4 = v2->m_pMemory[k];
        if ( v4 != nullptr )
        {
          v5 = &v4->m_SpaceUsed;
          if ( v4 != (CUtlSymbolTable::StringPool_t *)-4 )
          {
            if ( (*(unsigned __int8 (__thiscall **)(int *, CUtlSymbolLarge::<unnamed_type_u>))(*v5 + 16))(
                   a1: v5,
                   a2: CDmeOperator::m_classType.u) != 0
              && v5 != (int *)4
              && v5 - 1 == (int *)pDmeOperator )
            {
              return;
            }
            v2 = operatorList;
          }
        }
      }
      m_pMemory = v2[1].m_pMemory;
      m_nAllocationCount = v2->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v2, num: (int)m_pMemory - m_nAllocationCount + 1);
        v2 = operatorList;
      }
      ++v2[1].m_pMemory;
      v8 = v2->m_pMemory;
      v9 = (char *)v2[1].m_pMemory - (char *)m_pMemory - 1;
      v2[1].m_nAllocationCount = (int)v2->m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
        v2 = operatorList;
      }
      v10 = &v2->m_pMemory[(_DWORD)m_pMemory];
      if ( v10 != nullptr )
        *v10 = pDmeOperator;
      v11 = *(void (__thiscall **)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))(pDmeOperator->m_TotalLen + 16);
      memset(&outAttrList, 0, sizeof(outAttrList));
      v11(this: (struct CDmeOperator *)pDmeOperator, a2: &outAttrList);
      v12 = 0;
      for ( i = 0; v12 < outAttrList.m_Size; i = v12 )
      {
        m_pOwner = outAttrList.m_Memory.m_pMemory[v12]->m_pOwner;
        if ( m_pOwner != nullptr )
        {
          if ( m_pOwner == p_m_SpaceUsed )
          {
            v14 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
            v24 = TD_ALL;
            v23 = true;
            v22.u.m_Id = g_pDataModel.u.m_Id;
            memset(&reList0, 0, sizeof(reList0));
            v14(a1: &v22, a2: "element");
            FindReferringElements<CDmElement>(
              list: &reList0,
              pElement: m_pOwner,
              symAttrName: v22,
              bMustBeInSameFile: v23,
              depth: v24);
            v15 = 0;
            j = 0;
            if ( reList0.m_Size > 0 )
            {
              do
              {
                v16 = reList0.m_Memory.m_pMemory[v15];
                if ( v16 != nullptr && v16->IsA(this: (CDmElement *)v16, a2: CDmeAttributeReference::m_classType) )
                {
                  v17 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
                  v24 = TD_ALL;
                  v23 = true;
                  v22.u.m_Id = g_pDataModel.u.m_Id;
                  memset(&reList1, 0, sizeof(reList1));
                  v17(a1: &v22, a2: "input");
                  FindReferringElements<CDmElement>(
                    list: &reList1,
                    pElement: v16,
                    symAttrName: v22,
                    bMustBeInSameFile: v23,
                    depth: v24);
                  for ( m = 0; m < reList1.m_Size; ++m )
                  {
                    v19 = reList1.m_Memory.m_pMemory[m];
                    if ( v19 != nullptr
                      && v19->IsA(this: v19, a2: CDmeConnectionOperator::m_classType)
                      && v19 != (CDmElement *)4 )
                    {
                      GetDependentOperators(
                        (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
                        pDmeOperator: (CDmeOperator *)((char *)&v19[-1] + 64));
                    }
                  }
                  if ( reList1.m_Memory.m_nGrowSize >= 0 && reList1.m_Memory.m_pMemory != nullptr )
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList1.m_Memory.m_pMemory);
                }
                v15 = j + 1;
                j = v15;
              }
              while ( v15 < reList0.m_Size );
              v12 = i;
            }
            if ( reList0.m_Memory.m_nGrowSize >= 0 && reList0.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList0.m_Memory.m_pMemory);
          }
          else
          {
            if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
              v20 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
            else
              v20 = nullptr;
            GetDependentOperators(
              (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
              pDmeOperator: v20);
          }
        }
        ++v12;
      }
      v21 = outAttrList.m_Memory.m_pMemory;
      outAttrList.m_Size = 0;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( outAttrList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outAttrList.m_Memory.m_pMemory);
          v21 = nullptr;
          outAttrList.m_Memory.m_pMemory = nullptr;
        }
        outAttrList.m_Memory.m_nAllocationCount = 0;
      }
      outAttrList.m_pElements = v21;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 && v21 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D710
// Name: PrepareChannels
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrepareChannels(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList,
        CDmeChannelsClip *pAnimation)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  CDmeChannel *v6; // ecx
  int v7; // eax
  int v8; // esi
  CUtlSymbolTable::StringPool_t *v9; // eax
  int nChannelsCount; // [esp+18h] [ebp+Ch]

  v3 = 0;
  nChannelsCount = pAnimation->m_Channels.m_Storage.m_Size;
  if ( nChannelsCount > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: pAnimation->m_Channels.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v6 = (CDmeChannel *)(v5 - 4);
      }
      else
      {
        v6 = nullptr;
      }
      CDmeChannel::SetMode(this: v6, mode: CM_PLAY);
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: pAnimation->m_Channels.m_Storage.m_Memory.m_pMemory[v3]);
      v8 = v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v9 = (CUtlSymbolTable::StringPool_t *)(v8 - 4);
      }
      else
      {
        v9 = nullptr;
      }
      GetDependentOperators(operatorList, pDmeOperator: v9);
      ++v3;
    }
    while ( v3 < nChannelsCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D7D0
// Name: FindModelIndex
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindModelIndex(s_model_t *pModel)
{
  s_model_t *v1; // edi
  int result; // eax
  int m_Size; // ecx
  s_model_t **m_pMemory; // edx
  int v5; // esi
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  int v9; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v1 = pModel;
  if ( pModel == nullptr )
    return -1;
  result = 0;
  i = 0;
  if ( g_nummodels <= 0 )
  {
LABEL_14:
    MdlWarning(fmt: "Cannot Find s_model_t: \"%s\" in g_model\n", v1->name);
    return -1;
  }
  m_Size = g_model.m_Size;
  m_pMemory = g_model.m_Memory.m_pMemory;
  v5 = 1;
  v9 = 1;
  while ( 1 )
  {
    if ( m_Size < v5 )
    {
      v6 = v5 - m_Size;
      v7 = m_Size;
      if ( v6 != 0 )
      {
        v8 = m_Size + v6;
        if ( m_Size + v6 > g_model.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
            num: v6 + m_Size - g_model.m_Memory.m_nAllocationCount);
          m_Size = g_model.m_Size;
          m_pMemory = g_model.m_Memory.m_pMemory;
        }
        m_Size += v6;
        g_model.m_Size = m_Size;
        g_model.m_pElements = m_pMemory;
        if ( m_Size - v7 - v6 > 0 && v6 > 0 )
        {
          _V_memmove(dest: &m_pMemory[v8], src: &m_pMemory[v7], count: 4 * (m_Size - v7 - v6));
          m_Size = g_model.m_Size;
          m_pMemory = g_model.m_Memory.m_pMemory;
        }
        result = i;
      }
    }
    v1 = pModel;
    if ( m_pMemory[result] == pModel )
      return result;
    ++result;
    v5 = v9 + 1;
    i = result;
    ++v9;
    if ( result >= g_nummodels )
      goto LABEL_14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DAE0
// Name: LoadEyelid
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadEyelid(s_model_t *pModel, CDmeEyelid *pDmeEyelid)
{
  s_source_t *source; // edi
  const char *m_pAsString; // eax
  const s_sourceanim_t *NewStyleSourceVertexAnim; // eax
  float m_Storage; // xmm0_4
  const char *v7; // eax
  const s_sourceanim_t *v8; // eax
  float v9; // xmm0_4
  const char *v10; // eax
  const s_sourceanim_t *v11; // eax
  float v12; // xmm0_4
  const char *v13; // edi
  int *v14; // esi
  const char *v15; // eax
  const char *v16; // edi
  LoadEyelid::__l6::EyelidData_t *v17; // esi
  int k; // ebx
  const char *v19; // eax
  int v20; // eax
  bool v21; // sf
  EyelidType_t v22; // esi
  const char **p_m_pSourceAnim; // edi
  bool v24; // cc
  s_eyeball_t *eyeball; // esi
  const char *v26; // eax
  int v27; // ebx
  const char *v28; // eax
  float *p_m_flTarget; // edi
  float radius; // xmm1_4
  const char *v31; // eax
  float m_flTarget; // xmm0_4
  int v33; // eax
  int v34; // ecx
  int v35; // edx
  float v36; // xmm0_4
  int v37; // ecx
  int v38; // edx
  int v39; // eax
  float v40; // xmm0_4
  const char *v41; // eax
  const char *v42; // eax
  LoadEyelid::__l6::EyelidData_t eyelidData[3]; // [esp+2Ch] [ebp-60h] BYREF
  CUtlString sLeftLocalDesc; // [esp+68h] [ebp-24h] BYREF
  int nRightLeftBaseDesc[2]; // [esp+78h] [ebp-14h]
  int i; // [esp+80h] [ebp-Ch]
  int j; // [esp+84h] [ebp-8h]
  bool bLeftOk; // [esp+89h] [ebp-3h]
  bool bRightOk; // [esp+8Ah] [ebp-2h]
  bool bUpper; // [esp+8Bh] [ebp-1h]

  if ( pModel == nullptr || pDmeEyelid == nullptr )
    return 0;
  source = pModel->source;
  i = (int)source;
  if ( source == nullptr )
    return 0;
  bUpper = pDmeEyelid->m_bUpper.m_Storage;
  m_pAsString = pDmeEyelid->m_sLowererFlex.m_Storage.u.m_pAsString;
  eyelidData[0].m_nFlexDesc[0] = -1;
  eyelidData[0].m_nFlexDesc[1] = -1;
  eyelidData[0].m_pszSuffix = "lowerer";
  eyelidData[1].m_nFlexDesc[0] = -1;
  eyelidData[1].m_nFlexDesc[1] = -1;
  eyelidData[1].m_pszSuffix = "neutral";
  eyelidData[2].m_nFlexDesc[0] = -1;
  eyelidData[2].m_nFlexDesc[1] = -1;
  eyelidData[2].m_pszSuffix = "raiser";
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  NewStyleSourceVertexAnim = GetNewStyleSourceVertexAnim(pSource: source, pszVertexAnimName: m_pAsString);
  m_Storage = pDmeEyelid->m_flLowererHeight.m_Storage;
  eyelidData[0].m_pSourceAnim = NewStyleSourceVertexAnim;
  v7 = pDmeEyelid->m_sNeutralFlex.m_Storage.u.m_pAsString;
  eyelidData[0].m_flTarget = m_Storage;
  if ( v7 == (const char *)-1 )
    v7 = pDeltaStateName;
  v8 = GetNewStyleSourceVertexAnim(pSource: source, pszVertexAnimName: v7);
  v9 = pDmeEyelid->m_flNeutralHeight.m_Storage;
  eyelidData[1].m_pSourceAnim = v8;
  v10 = pDmeEyelid->m_sRaiserFlex.m_Storage.u.m_pAsString;
  eyelidData[1].m_flTarget = v9;
  if ( v10 == (const char *)-1 )
    v10 = pDeltaStateName;
  v11 = GetNewStyleSourceVertexAnim(pSource: source, pszVertexAnimName: v10);
  v12 = pDmeEyelid->m_flRaiserHeight.m_Storage;
  eyelidData[2].m_pSourceAnim = v11;
  eyelidData[2].m_flTarget = v12;
  v13 = "upper_right";
  if ( !bUpper )
    v13 = "lower_right";
  nRightLeftBaseDesc[1] = Add_Flexdesc(name: v13);
  v14 = &eyelidData[0].m_nFlexDesc[1];
  for ( j = 3; j != 0; --j )
  {
    CUtlString::CUtlString(this: &sLeftLocalDesc, pString: v13);
    CUtlString::operator+=(this: &sLeftLocalDesc, rhs: "_");
    CUtlString::operator+=(this: &sLeftLocalDesc, rhs: (const char *)v14[3]);
    v15 = CUtlString::Get(this: &sLeftLocalDesc);
    *v14 = Add_Flexdesc(name: v15);
    sLeftLocalDesc.m_Storage.m_nActualLength = 0;
    if ( sLeftLocalDesc.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( sLeftLocalDesc.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sLeftLocalDesc.m_Storage.m_Memory.m_pMemory);
        sLeftLocalDesc.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      sLeftLocalDesc.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v14 += 5;
  }
  v16 = "upper_left";
  if ( !bUpper )
    v16 = "lower_left";
  nRightLeftBaseDesc[0] = Add_Flexdesc(name: v16);
  v17 = eyelidData;
  for ( k = 3; k != 0; --k )
  {
    CUtlString::CUtlString(this: &sLeftLocalDesc, pString: v16);
    CUtlString::operator+=(this: &sLeftLocalDesc, rhs: "_");
    CUtlString::operator+=(this: &sLeftLocalDesc, rhs: v17->m_pszSuffix);
    v19 = CUtlString::Get(this: &sLeftLocalDesc);
    v20 = Add_Flexdesc(name: v19);
    v21 = sLeftLocalDesc.m_Storage.m_Memory.m_nGrowSize < 0;
    v17->m_nFlexDesc[0] = v20;
    sLeftLocalDesc.m_Storage.m_nActualLength = 0;
    if ( !v21 )
    {
      if ( sLeftLocalDesc.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sLeftLocalDesc.m_Storage.m_Memory.m_pMemory);
        sLeftLocalDesc.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      sLeftLocalDesc.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    ++v17;
  }
  v22 = kLowerer;
  p_m_pSourceAnim = (const char **)&eyelidData[0].m_pSourceAnim;
  do
  {
    if ( !AddFlexKey(
            pSource: (s_source_t *)i,
            pModel,
            pszAnimationName: *p_m_pSourceAnim,
            nFlexDesc: nRightLeftBaseDesc[0],
            nFlexPair: nRightLeftBaseDesc[1],
            nEyelidType: v22,
            flLowererHeight: eyelidData[0].m_flTarget,
            flNeutralHeight: eyelidData[1].m_flTarget,
            flRaiserHeight: eyelidData[2].m_flTarget,
            flSplit: 0.0,
            flDecay: 1.0,
            nFrame: 0) )
      return 0;
    ++v22;
    p_m_pSourceAnim += 5;
  }
  while ( v22 < kEyelidTypeCount );
  v24 = pModel->numeyeballs <= 0;
  bRightOk = false;
  bLeftOk = false;
  i = 0;
  if ( v24 )
    goto LABEL_53;
  eyeball = pModel->eyeball;
  do
  {
    if ( eyeball == nullptr )
      goto LABEL_51;
    v26 = pDmeEyelid->m_sRightEyeballName.m_Storage.u.m_pAsString;
    if ( v26 == (const char *)-1 )
      v26 = pDeltaStateName;
    if ( _V_stricmp(s1: v26, s2: eyeball->name) != 0 )
    {
      v28 = pDmeEyelid->m_sLeftEyeballName.m_Storage.u.m_pAsString;
      if ( v28 == (const char *)-1 )
        v28 = pDeltaStateName;
      if ( _V_stricmp(s1: v28, s2: eyeball->name) != 0 )
      {
        MdlWarning(fmt: "Unknown Eyeball: %s\n", eyeball->name);
        goto LABEL_51;
      }
      v27 = 0;
      bLeftOk = true;
    }
    else
    {
      v27 = 1;
      bRightOk = true;
    }
    p_m_flTarget = &eyelidData[0].m_flTarget;
    for ( j = 3; j != 0; --j )
    {
      radius = eyeball->radius;
      if ( COERCE_FLOAT(*(_DWORD *)p_m_flTarget & _mask__AbsFloat_) > radius )
      {
        v31 = "upper";
        if ( !bUpper )
          v31 = "lower";
        MdlError(
          fmt: "Eyelid \"%s\" %s %.1f out of range (+-%.1f)\n",
          v31,
          *((const char **)p_m_flTarget + 1),
          *p_m_flTarget,
          radius);
      }
      p_m_flTarget += 5;
    }
    m_flTarget = eyelidData[0].m_flTarget;
    if ( bUpper )
    {
      v33 = eyelidData[0].m_nFlexDesc[v27];
      v34 = eyelidData[1].m_nFlexDesc[v27];
      eyeball->upperlidflexdesc = nRightLeftBaseDesc[v27];
      v35 = eyelidData[2].m_nFlexDesc[v27];
      eyeball->uppertarget[0] = m_flTarget;
      eyeball->uppertarget[1] = eyelidData[1].m_flTarget;
      v36 = eyelidData[2].m_flTarget;
      eyeball->upperflexdesc[0] = v33;
      eyeball->upperflexdesc[1] = v34;
      eyeball->upperflexdesc[2] = v35;
      eyeball->uppertarget[2] = v36;
    }
    else
    {
      v37 = eyelidData[0].m_nFlexDesc[v27];
      v38 = eyelidData[1].m_nFlexDesc[v27];
      eyeball->lowerlidflexdesc = nRightLeftBaseDesc[v27];
      v39 = eyelidData[2].m_nFlexDesc[v27];
      eyeball->lowertarget[0] = m_flTarget;
      eyeball->lowertarget[1] = eyelidData[1].m_flTarget;
      v40 = eyelidData[2].m_flTarget;
      eyeball->lowerflexdesc[0] = v37;
      eyeball->lowerflexdesc[1] = v38;
      eyeball->lowerflexdesc[2] = v39;
      eyeball->lowertarget[2] = v40;
    }
LABEL_51:
    ++eyeball;
    ++i;
  }
  while ( i < pModel->numeyeballs );
  if ( !bRightOk )
  {
LABEL_53:
    v41 = pDmeEyelid->m_sRightEyeballName.m_Storage.u.m_pAsString;
    if ( v41 == (const char *)-1 )
      v41 = pDeltaStateName;
    MdlError(fmt: "Could not find right eye \"%s\"\n", v41);
  }
  if ( !bLeftOk )
  {
    v42 = pDmeEyelid->m_sLeftEyeballName.m_Storage.u.m_pAsString;
    if ( v42 == (const char *)-1 )
      v42 = pDeltaStateName;
    MdlError(fmt: "Could not find left eye \"%s\"\n", v42);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DF70
// Name: void LoadQcModelElements(struct s_source_t __near *,struct s_model_t __near *,class CDmeModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadQcModelElements(s_source_t *pSource, s_model_t *pModel, CDmeModel *pDmeModel)
{
  CDmAttribute *Attribute; // eax
  int i; // edi
  DmElementArray_t *m_pStorage; // eax
  int v6; // ecx
  int v7; // eax
  CDmeEyelid *v8; // esi
  int j; // ebx
  int v10; // ecx
  int v11; // eax
  CDmeMouth *v12; // esi
  CDmrElementArray<CDmElement> qcModelElements; // [esp+Ch] [ebp-8h] BYREF

  if ( pModel != nullptr && pDmeModel != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pDmeModel, pAttributeName: "qcModelElements");
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(this: &qcModelElements, pAttribute: Attribute);
      LoadEyeballs(pSource, pModel, elementArray: &qcModelElements);
      for ( i = 0; ; ++i )
      {
        m_pStorage = qcModelElements.m_pStorage;
        v6 = qcModelElements.m_pAttribute != nullptr ? qcModelElements.m_pStorage->m_Size : 0;
        if ( i >= v6 )
          break;
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: qcModelElements.m_pStorage->m_Memory.m_pMemory[i]);
        v8 = (CDmeEyelid *)v7;
        if ( v7 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmElement::m_classType.u) == 0
          || !v8->IsA(this: v8, a2: CDmeEyelid::m_classType) )
        {
          v8 = nullptr;
        }
        LoadEyelid(pModel, pDmeEyelid: v8);
      }
      for ( j = 0; ; ++j )
      {
        v10 = qcModelElements.m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
        if ( j >= v10 )
          break;
        v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: m_pStorage->m_Memory.m_pMemory[j]);
        v12 = (CDmeMouth *)v11;
        if ( v11 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: CDmElement::m_classType.u) == 0
          || !v12->IsA(this: v12, a2: CDmeMouth::m_classType) )
        {
          v12 = nullptr;
        }
        LoadMouth(pDmeMouth: v12);
        m_pStorage = qcModelElements.m_pStorage;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E0B0
// Name: UnderscoreSplitAndSortStrings
// Source: json
//------------------------------------------------------------------------------
void __usercall UnderscoreSplitAndSortStrings(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *splitAndSortedString@<esi>,
        const char *pszString)
{
  int v2; // edi
  void *v3; // esp
  unsigned __int8 *v4; // ebx
  int v5; // edi
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // edi
  const CUtlString *v8; // eax
  const CUtlString *v9; // eax
  int v10; // edi
  int v11; // ebx
  unsigned int v12; // edi
  const char *v13; // eax
  const char *v14; // [esp-4h] [ebp-38h]
  char v15[8]; // [esp+0h] [ebp-34h] BYREF
  CUtlString v16; // [esp+8h] [ebp-2Ch] BYREF
  CUtlString sValue; // [esp+18h] [ebp-1Ch] BYREF
  CUtlString *v18; // [esp+28h] [ebp-Ch]
  int v19; // [esp+2Ch] [ebp-8h]
  unsigned int v20; // [esp+30h] [ebp-4h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: splitAndSortedString);
  v2 = _V_strlen(str: pszString);
  if ( v2 > 0 )
  {
    v3 = alloca(v2 + 1);
    v4 = (unsigned __int8 *)v15;
    if ( v15 != nullptr )
    {
      v5 = v2 + 1;
      _V_memset(dest: v15, fill: 0, count: v5);
      V_strncpy(pDest: v15, pSrc: pszString, maxLen: v5);
      do
      {
        if ( *v4 == 0 )
          break;
        strchr(string: v4, chr: 0x5Fu);
        v7 = v6;
        if ( v6 != nullptr )
        {
          *v6 = 0;
          v7 = v6 + 1;
          v9 = CUtlString::CUtlString(this: &v16, pString: (const char *)v4);
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
            this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)splitAndSortedString,
            elem: splitAndSortedString->m_Size,
            src: v9);
          v16.m_Storage.m_nActualLength = 0;
          if ( v16.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v16.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16.m_Storage.m_Memory.m_pMemory);
              v16.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v16.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
        else
        {
          v8 = CUtlString::CUtlString(this: &sValue, pString: (const char *)v4);
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
            this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)splitAndSortedString,
            elem: splitAndSortedString->m_Size,
            src: v8);
          sValue.m_Storage.m_nActualLength = 0;
          if ( sValue.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( sValue.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sValue.m_Storage.m_Memory.m_pMemory);
              sValue.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            sValue.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
        v4 = v7;
      }
      while ( v7 != nullptr );
      if ( splitAndSortedString->m_Size > 1 )
      {
        v10 = 0;
        v19 = 0;
        v20 = 16;
        do
        {
          CUtlString::CUtlString(
            this: &sValue,
            string: (const CUtlString *)&splitAndSortedString->m_Memory.m_pMemory[v20 / 0x10]);
          v11 = v10;
          if ( v10 >= 0 )
          {
            v12 = v20 - 16;
            do
            {
              v18 = (CUtlString *)((char *)splitAndSortedString->m_Memory.m_pMemory + v12);
              v14 = CUtlString::operator char const *(this: &sValue);
              v13 = CUtlString::Get(this: v18);
              if ( _V_stricmp(s1: v13, s2: v14) <= 0 )
                break;
              CUtlString::operator=(
                this: (CUtlString *)((char *)&splitAndSortedString->m_Memory.m_pMemory[1] + v12),
                src: (const CUtlString *)((char *)splitAndSortedString->m_Memory.m_pMemory + v12));
              v12 -= 16;
              --v11;
            }
            while ( v11 >= 0 );
            v10 = v19;
          }
          CUtlString::operator=(this: (CUtlString *)&splitAndSortedString->m_Memory.m_pMemory[v11 + 1], src: &sValue);
          sValue.m_Storage.m_nActualLength = 0;
          if ( sValue.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( sValue.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sValue.m_Storage.m_Memory.m_pMemory);
              sValue.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            sValue.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v20 += 16;
          v19 = ++v10;
        }
        while ( v10 + 1 < splitAndSortedString->m_Size );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E280
// Name: LoadKeyValues
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadKeyValues(const char *pszKeyValues@<edi>)
{
  int v1; // esi
  int v2; // eax
  int v3; // eax

  if ( pszKeyValues != nullptr )
  {
    v1 = _V_strlen(str: pszKeyValues);
    if ( v1 > 0 )
    {
      v2 = _V_strlen(str: "mdlkeyvalue\n{\n");
      CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        this: &g_KeyValueText,
        elem: g_KeyValueText.m_Size,
        num: v2,
        pToInsert: "mdlkeyvalue\n{\n");
      CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        this: &g_KeyValueText,
        elem: g_KeyValueText.m_Size,
        num: v1,
        pToInsert: pszKeyValues);
      v3 = _V_strlen(str: "}\n");
      CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        this: &g_KeyValueText,
        elem: g_KeyValueText.m_Size,
        num: v3,
        pToInsert: "}\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E2F0
// Name: AllocateHitboxSet
// Source: json
//------------------------------------------------------------------------------
s_hitboxset *__cdecl AllocateHitboxSet()
{
  int m_Size; // eax
  int v1; // esi
  s_hitboxset *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 *v4; // esi

  m_Size = g_hitboxsets.m_Size;
  v1 = g_hitboxsets.m_Size;
  if ( g_hitboxsets.m_Size + 1 > g_hitboxsets.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<s_hitboxset,int>::Grow(
      this: &g_hitboxsets.m_Memory,
      num: g_hitboxsets.m_Size - g_hitboxsets.m_Memory.m_nAllocationCount + 1);
    m_Size = g_hitboxsets.m_Size;
  }
  m_pMemory = g_hitboxsets.m_Memory.m_pMemory;
  g_hitboxsets.m_Size = m_Size + 1;
  v3 = m_Size - v1;
  g_hitboxsets.m_pElements = g_hitboxsets.m_Memory.m_pMemory;
  if ( v3 > 0 )
  {
    _V_memmove(
      dest: &g_hitboxsets.m_Memory.m_pMemory[v1 + 1],
      src: &g_hitboxsets.m_Memory.m_pMemory[v1],
      count: 299076 * v3);
    m_pMemory = g_hitboxsets.m_Memory.m_pMemory;
  }
  v4 = (unsigned __int8 *)&m_pMemory[v1];
  memset(dst: v4, value: 0, count: 0x49044u);
  return (s_hitboxset *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040E380
// Name: LoadHitboxSetList
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadHitboxSetList(const CDmeHitboxSetList *pDmeHitboxSetList)
{
  const CDmeHitboxSetList *v1; // eax
  int v2; // edi
  int v3; // eax
  _DWORD *v4; // esi
  s_hitboxset *HitboxSet; // ebx
  const char *v6; // eax
  int v7; // eax
  int v8; // esi
  const char *v9; // eax
  unsigned int numhitboxes; // eax
  int name; // edi
  const char *v12; // eax
  const char *v13; // eax
  _BYTE *v14; // eax
  const char *SurfaceProp; // ebx
  const char *v16; // eax
  const char *v17; // ecx
  const char *v18; // eax
  const char *v19; // esi
  int nHitboxSetCount; // [esp+Ch] [ebp-18h]
  int nHitboxCount; // [esp+10h] [ebp-14h]
  int nHitBoxSetIndex; // [esp+14h] [ebp-10h]
  s_hitboxset *pHitboxSet; // [esp+18h] [ebp-Ch]
  int nHitboxIndex; // [esp+1Ch] [ebp-8h]
  _DWORD *v25; // [esp+20h] [ebp-4h]

  v1 = pDmeHitboxSetList;
  if ( pDmeHitboxSetList != nullptr )
  {
    v2 = 0;
    nHitboxSetCount = pDmeHitboxSetList->m_HitboxSetList.m_Storage.m_Size;
    nHitBoxSetIndex = 0;
    if ( nHitboxSetCount > 0 )
    {
      while ( 1 )
      {
        v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v1->m_HitboxSetList.m_Storage.m_Memory.m_pMemory[v2]);
        v4 = (_DWORD *)v3;
        if ( v3 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
               a1: v3,
               a2: CDmeHitboxSet::m_classType.u) != 0 )
        {
          v25 = v4;
        }
        else
        {
          v25 = nullptr;
          v4 = nullptr;
        }
        HitboxSet = AllocateHitboxSet();
        v6 = (const char *)v4[5];
        pHitboxSet = HitboxSet;
        if ( v6 == (const char *)-1 )
          v6 = pDeltaStateName;
        V_strncpy(pDest: HitboxSet->hitboxsetname, pSrc: v6, maxLen: 64);
        nHitboxCount = v4[20];
        nHitboxIndex = 0;
        if ( nHitboxCount > 0 )
        {
          while ( 1 )
          {
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: *(_DWORD *)(v4[17] + 4 * nHitboxIndex));
            v8 = v7;
            if ( v7 == 0
              || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmeHitbox::m_classType.u) == 0 )
            {
              v8 = 0;
            }
            v9 = *(const char **)(v8 + 124);
            if ( v9 == (const char *)-1 )
              v9 = pDeltaStateName;
            findGlobalBone(name: v9);
            numhitboxes = HitboxSet->numhitboxes;
            if ( numhitboxes >= 0x400 )
            {
              MdlWarning(
                fmt: "Too many hitboxes request for hitbox set \"%s\", max %d\n",
                HitboxSet->hitboxsetname,
                1024);
              name = 0;
            }
            else
            {
              name = (int)HitboxSet->hitbox[numhitboxes].name;
              HitboxSet->numhitboxes = numhitboxes + 1;
            }
            v12 = *(const char **)(v8 + 124);
            if ( v12 == (const char *)-1 )
              v12 = pDeltaStateName;
            V_strncpy(pDest: (char *)name, pSrc: v12, maxLen: 128);
            v13 = *(const char **)(v8 + 20);
            if ( v13 == (const char *)-1 )
              v13 = pDeltaStateName;
            V_strncpy(pDest: (char *)(name + 128), pSrc: v13, maxLen: 128);
            *(_DWORD *)(name + 260) = *(_DWORD *)(v8 + 116);
            *(float *)(name + 268) = *(float *)(v8 + 76);
            *(float *)(name + 272) = *(float *)(v8 + 80);
            *(float *)(name + 276) = *(float *)(v8 + 84);
            *(float *)(name + 280) = *(float *)(v8 + 92);
            *(float *)(name + 284) = *(float *)(v8 + 96);
            *(float *)(name + 288) = *(float *)(v8 + 100);
            v14 = *(_BYTE **)(v8 + 108);
            if ( v14 != (_BYTE *)-1 && v14 != nullptr && *v14 != 0 )
            {
              SurfaceProp = FindSurfaceProp(pJointName: (const char *)name);
              if ( SurfaceProp == nullptr )
                goto LABEL_38;
              v16 = *(const char **)(v8 + 108);
              if ( v16 == (const char *)-1 )
                v16 = pDeltaStateName;
              if ( _V_stricmp(s1: SurfaceProp, s2: v16) != 0 )
              {
                v17 = pDeltaStateName;
                if ( *(_DWORD *)(v8 + 124) != -1 )
                  v17 = *(const char **)(v8 + 124);
                v18 = *(const char **)(v8 + 108);
                if ( v18 == (const char *)-1 )
                  v18 = pDeltaStateName;
                MdlWarning(
                  fmt: "Hitbox surface property \"%s\" for bone \"%s\" conflicts with existing \"%s\"",
                  v18,
                  v17,
                  SurfaceProp);
              }
              else
              {
LABEL_38:
                v19 = *(const char **)(v8 + 108);
                if ( v19 == (const char *)-1 )
                  v19 = pDeltaStateName;
                AddSurfaceProp(pBoneName: (const char *)name, pSurfaceProperty: v19);
              }
              HitboxSet = pHitboxSet;
            }
            if ( ++nHitboxIndex >= nHitboxCount )
              break;
            v4 = v25;
          }
          v2 = nHitBoxSetIndex;
        }
        nHitBoxSetIndex = ++v2;
        if ( v2 >= nHitboxSetCount )
          break;
        v1 = pDmeHitboxSetList;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E5E0
// Name: LoadBoneMergeList
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadBoneMergeList(CDmAttribute *pDmeBoneMergeListAttr@<eax>)
{
  int v2; // edi
  unsigned __int8 *m_Id; // ebx
  int m_Size; // eax
  int v5; // esi
  s_bonemerge_t *m_pMemory; // ecx
  int v7; // eax
  CDmrStringArrayConst boneMergeList; // [esp+4h] [ebp-Ch] BYREF
  int nBoneMergeCount; // [esp+Ch] [ebp-4h]

  if ( pDmeBoneMergeListAttr != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&boneMergeList);
    CDmrDecoratorConst<CUtlSymbolLarge,CDmaArrayConstBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
      this: (CDmrDecoratorConst<CUtlSymbolLarge,CDmaArrayConstBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&boneMergeList,
      pAttribute: pDmeBoneMergeListAttr);
    if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&boneMergeList) )
    {
      v2 = 0;
      nBoneMergeCount = boneMergeList.m_pStorage->m_Size;
      if ( nBoneMergeCount > 0 )
      {
        do
        {
          m_Id = (unsigned __int8 *)pDeltaStateName;
          if ( boneMergeList.m_pStorage->m_Memory.m_pMemory[v2].u.m_Id != -1 )
            m_Id = (unsigned __int8 *)boneMergeList.m_pStorage->m_Memory.m_pMemory[v2].u.m_Id;
          m_Size = g_BoneMerge.m_Size;
          v5 = g_BoneMerge.m_Size;
          if ( g_BoneMerge.m_Size + 1 > g_BoneMerge.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<s_bonemerge_t,int>::Grow(
              this: &g_BoneMerge.m_Memory,
              num: g_BoneMerge.m_Size - g_BoneMerge.m_Memory.m_nAllocationCount + 1);
            m_Size = g_BoneMerge.m_Size;
          }
          m_pMemory = g_BoneMerge.m_Memory.m_pMemory;
          g_BoneMerge.m_Size = m_Size + 1;
          v7 = m_Size - v5;
          g_BoneMerge.m_pElements = g_BoneMerge.m_Memory.m_pMemory;
          if ( v7 > 0 )
          {
            _V_memmove(
              dest: &g_BoneMerge.m_Memory.m_pMemory[v5 + 1],
              src: &g_BoneMerge.m_Memory.m_pMemory[v5],
              count: v7 << 7);
            m_pMemory = g_BoneMerge.m_Memory.m_pMemory;
          }
          strncpy(dest: (unsigned __int8 *)&m_pMemory[v5], source: m_Id, count: 0x80u);
          ++v2;
        }
        while ( v2 < nBoneMergeCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E9A0
// Name: LoadConstraint_CDmeRigPointConstraintOperator_CPointConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadConstraint_CDmeRigPointConstraintOperator_CPointConstraint_@<al>(CDmElement *pDmElement@<eax>)
{
  CDmeRigBaseConstraintOperator *v3; // esi
  CConstraintBoneBase *v4; // eax
  CConstraintBoneBase *v5; // edi
  int m_Size; // eax
  int v7; // esi
  CConstraintBoneBase **m_pMemory; // ecx
  int v9; // eax
  CConstraintBoneBase **v10; // eax

  if ( g_constraintBones.m_Size == 256 )
    MdlError(fmt: "Too Many Constraint Bones, Max: %d\n", 256);
  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigPointConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v3 = (CDmeRigBaseConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( v3 == nullptr )
    return 0;
  v4 = (CConstraintBoneBase *)MemAlloc_Alloc(nSize: 0xB8u);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v4->m_targets.m_Memory.m_pMemory = nullptr;
  v4->m_targets.m_Memory.m_nAllocationCount = 0;
  v4->m_targets.m_Memory.m_nGrowSize = 0;
  v4->m_targets.m_Size = 0;
  v4->m_targets.m_pElements = nullptr;
  v4->__vftable = (CConstraintBoneBase_vtbl *)&CPointConstraint::`vftable';
  if ( LoadBaseConstraintParams(pConstraintBone: v4, pDmeBaseConstraint: v3) != 0 )
  {
    if ( FindDuplicateConstraint(pConstraintA: v5) != 0 )
    {
      ((void (__thiscall *)(CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
      return 1;
    }
    else
    {
      m_Size = g_constraintBones.m_Size;
      v7 = g_constraintBones.m_Size;
      if ( g_constraintBones.m_Size + 1 > g_constraintBones.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_constraintBones,
          num: g_constraintBones.m_Size - g_constraintBones.m_Memory.m_nAllocationCount + 1);
        m_Size = g_constraintBones.m_Size;
      }
      m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      g_constraintBones.m_Size = m_Size + 1;
      v9 = m_Size - v7;
      g_constraintBones.m_pElements = g_constraintBones.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(
          dest: &g_constraintBones.m_Memory.m_pMemory[v7 + 1],
          src: &g_constraintBones.m_Memory.m_pMemory[v7],
          count: 4 * v9);
        m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      }
      v10 = &m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = v5;
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EAC0
// Name: LoadConstraint_CDmeRigOrientConstraintOperator_COrientConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadConstraint_CDmeRigOrientConstraintOperator_COrientConstraint_@<al>(CDmElement *pDmElement@<eax>)
{
  CDmeRigBaseConstraintOperator *v3; // esi
  CConstraintBoneBase *v4; // eax
  CConstraintBoneBase *v5; // edi
  int m_Size; // eax
  int v7; // esi
  CConstraintBoneBase **m_pMemory; // ecx
  int v9; // eax
  CConstraintBoneBase **v10; // eax

  if ( g_constraintBones.m_Size == 256 )
    MdlError(fmt: "Too Many Constraint Bones, Max: %d\n", 256);
  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigOrientConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v3 = (CDmeRigBaseConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( v3 == nullptr )
    return 0;
  v4 = (CConstraintBoneBase *)MemAlloc_Alloc(nSize: 0xB8u);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v4->m_targets.m_Memory.m_pMemory = nullptr;
  v4->m_targets.m_Memory.m_nAllocationCount = 0;
  v4->m_targets.m_Memory.m_nGrowSize = 0;
  v4->m_targets.m_Size = 0;
  v4->m_targets.m_pElements = nullptr;
  v4->__vftable = (CConstraintBoneBase_vtbl *)&COrientConstraint::`vftable';
  if ( LoadBaseConstraintParams(pConstraintBone: v4, pDmeBaseConstraint: v3) != 0 )
  {
    if ( FindDuplicateConstraint(pConstraintA: v5) != 0 )
    {
      ((void (__thiscall *)(CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
      return 1;
    }
    else
    {
      m_Size = g_constraintBones.m_Size;
      v7 = g_constraintBones.m_Size;
      if ( g_constraintBones.m_Size + 1 > g_constraintBones.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_constraintBones,
          num: g_constraintBones.m_Size - g_constraintBones.m_Memory.m_nAllocationCount + 1);
        m_Size = g_constraintBones.m_Size;
      }
      m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      g_constraintBones.m_Size = m_Size + 1;
      v9 = m_Size - v7;
      g_constraintBones.m_pElements = g_constraintBones.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(
          dest: &g_constraintBones.m_Memory.m_pMemory[v7 + 1],
          src: &g_constraintBones.m_Memory.m_pMemory[v7],
          count: 4 * v9);
        m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      }
      v10 = &m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = v5;
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EBE0
// Name: LoadConstraint_CDmeRigAimConstraintOperator_CAimConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadConstraint_CDmeRigAimConstraintOperator_CAimConstraint_@<al>(CDmElement *pDmElement@<eax>)
{
  CDmeRigAimConstraintOperator *v3; // edi
  CAimConstraint *v4; // eax
  CAimConstraint *v5; // esi
  int m_Size; // eax
  int v7; // edi
  CConstraintBoneBase **m_pMemory; // ecx
  int v9; // eax
  CAimConstraint **v10; // eax

  if ( g_constraintBones.m_Size == 256 )
    MdlError(fmt: "Too Many Constraint Bones, Max: %d\n", 256);
  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigAimConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v3 = (CDmeRigAimConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( pDmElement == (CDmElement *)4 )
    return 0;
  v4 = (CAimConstraint *)MemAlloc_Alloc(nSize: 0x158u);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v4->m_targets.m_Memory.m_pMemory = nullptr;
  v4->m_targets.m_Memory.m_nAllocationCount = 0;
  v4->m_targets.m_Memory.m_nGrowSize = 0;
  v4->m_targets.m_Size = 0;
  v4->m_targets.m_pElements = nullptr;
  v4->__vftable = (CAimConstraint_vtbl *)&CAimConstraint::`vftable';
  v4->m_nUpSpaceTargetBone = -1;
  if ( LoadBaseConstraintParams(pConstraintBone: v4, pDmeBaseConstraint: v3) != 0
    && LoadSpecializedConstraintParams_CDmeRigAimConstraintOperator_CAimConstraint_(pConstraint: v5, pDmeConstraint: v3) != 0 )
  {
    if ( FindDuplicateConstraint(pConstraintA: v5) != 0 )
    {
      ((void (__thiscall *)(CAimConstraint *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
      return 1;
    }
    else
    {
      m_Size = g_constraintBones.m_Size;
      v7 = g_constraintBones.m_Size;
      if ( g_constraintBones.m_Size + 1 > g_constraintBones.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_constraintBones,
          num: g_constraintBones.m_Size - g_constraintBones.m_Memory.m_nAllocationCount + 1);
        m_Size = g_constraintBones.m_Size;
      }
      m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      g_constraintBones.m_Size = m_Size + 1;
      v9 = m_Size - v7;
      g_constraintBones.m_pElements = g_constraintBones.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(
          dest: &g_constraintBones.m_Memory.m_pMemory[v7 + 1],
          src: &g_constraintBones.m_Memory.m_pMemory[v7],
          count: 4 * v9);
        m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      }
      v10 = (CAimConstraint **)&m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = v5;
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(CAimConstraint *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ED10
// Name: LoadConstraint_CDmeRigParentConstraintOperator_CParentConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadConstraint_CDmeRigParentConstraintOperator_CParentConstraint_@<al>(CDmElement *pDmElement@<eax>)
{
  CDmeRigBaseConstraintOperator *v3; // esi
  CConstraintBoneBase *v4; // eax
  CConstraintBoneBase *v5; // edi
  int m_Size; // eax
  int v7; // esi
  CConstraintBoneBase **m_pMemory; // ecx
  int v9; // eax
  CConstraintBoneBase **v10; // eax

  if ( g_constraintBones.m_Size == 256 )
    MdlError(fmt: "Too Many Constraint Bones, Max: %d\n", 256);
  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigParentConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v3 = (CDmeRigBaseConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( v3 == nullptr )
    return 0;
  v4 = (CConstraintBoneBase *)MemAlloc_Alloc(nSize: 0xB8u);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v4->m_targets.m_Memory.m_pMemory = nullptr;
  v4->m_targets.m_Memory.m_nAllocationCount = 0;
  v4->m_targets.m_Memory.m_nGrowSize = 0;
  v4->m_targets.m_Size = 0;
  v4->m_targets.m_pElements = nullptr;
  v4->__vftable = (CConstraintBoneBase_vtbl *)&CParentConstraint::`vftable';
  if ( LoadBaseConstraintParams(pConstraintBone: v4, pDmeBaseConstraint: v3) != 0 )
  {
    if ( FindDuplicateConstraint(pConstraintA: v5) != 0 )
    {
      ((void (__thiscall *)(CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
      return 1;
    }
    else
    {
      m_Size = g_constraintBones.m_Size;
      v7 = g_constraintBones.m_Size;
      if ( g_constraintBones.m_Size + 1 > g_constraintBones.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_constraintBones,
          num: g_constraintBones.m_Size - g_constraintBones.m_Memory.m_nAllocationCount + 1);
        m_Size = g_constraintBones.m_Size;
      }
      m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      g_constraintBones.m_Size = m_Size + 1;
      v9 = m_Size - v7;
      g_constraintBones.m_pElements = g_constraintBones.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(
          dest: &g_constraintBones.m_Memory.m_pMemory[v7 + 1],
          src: &g_constraintBones.m_Memory.m_pMemory[v7],
          count: 4 * v9);
        m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      }
      v10 = &m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = v5;
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EEA0
// Name: FindOrAddDeltaState
// Source: json
//------------------------------------------------------------------------------
DeltaState_t *__cdecl FindOrAddDeltaState(const char *pDeltaStateName, int nBaseStateVertexCount)
{
  int m_Size; // eax
  int v3; // esi
  int v4; // edi
  const char *v5; // eax
  unsigned int v6; // edi
  DeltaState_t *m_pMemory; // ecx
  int v8; // eax
  unsigned int v9; // edi
  DeltaState_t *v10; // esi
  CUtlVector<DeltaIndex_t,CUtlMemory<DeltaIndex_t,int> > *p_m_DeltaIndices; // ecx
  int v13; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  m_Size = s_DeltaStates.m_Size;
  v3 = 0;
  nCount = s_DeltaStates.m_Size;
  if ( s_DeltaStates.m_Size <= 0 )
  {
LABEL_6:
    v6 = m_Size;
    if ( m_Size + 1 > s_DeltaStates.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<DeltaState_t,int>::Grow(
        this: &s_DeltaStates.m_Memory,
        num: m_Size - s_DeltaStates.m_Memory.m_nAllocationCount + 1);
      m_Size = s_DeltaStates.m_Size;
    }
    m_pMemory = s_DeltaStates.m_Memory.m_pMemory;
    s_DeltaStates.m_Size = m_Size + 1;
    v8 = m_Size - v6;
    s_DeltaStates.m_pElements = s_DeltaStates.m_Memory.m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(
        dest: &s_DeltaStates.m_Memory.m_pMemory[v6 + 1],
        src: &s_DeltaStates.m_Memory.m_pMemory[v6],
        count: 104 * v8);
      m_pMemory = s_DeltaStates.m_Memory.m_pMemory;
    }
    v9 = v6;
    v10 = &m_pMemory[v9];
    if ( &m_pMemory[v9] != nullptr )
    {
      CUtlString::CUtlString(this: &m_pMemory[v9].m_Name);
      v10->m_PositionDeltas.m_Memory.m_pMemory = nullptr;
      v10->m_PositionDeltas.m_Memory.m_nAllocationCount = 0;
      v10->m_PositionDeltas.m_Memory.m_nGrowSize = 0;
      v10->m_PositionDeltas.m_Size = 0;
      v10->m_PositionDeltas.m_pElements = nullptr;
      v10->m_NormalDeltas.m_Memory.m_pMemory = nullptr;
      v10->m_NormalDeltas.m_Memory.m_nAllocationCount = 0;
      v10->m_NormalDeltas.m_Memory.m_nGrowSize = 0;
      v10->m_NormalDeltas.m_Size = 0;
      v10->m_NormalDeltas.m_pElements = nullptr;
      v10->m_WrinkleDeltas.m_Memory.m_pMemory = nullptr;
      v10->m_WrinkleDeltas.m_Memory.m_nAllocationCount = 0;
      v10->m_WrinkleDeltas.m_Memory.m_nGrowSize = 0;
      v10->m_WrinkleDeltas.m_Size = 0;
      v10->m_WrinkleDeltas.m_pElements = nullptr;
      v10->m_DeltaIndices.m_Memory.m_pMemory = nullptr;
      v10->m_DeltaIndices.m_Memory.m_nAllocationCount = 0;
      v10->m_DeltaIndices.m_Memory.m_nGrowSize = 0;
      v10->m_DeltaIndices.m_Size = 0;
      v10->m_DeltaIndices.m_pElements = nullptr;
      v10->m_nDeltaCount = 0;
      v10->m_nFirstDelta = -1;
      m_pMemory = s_DeltaStates.m_Memory.m_pMemory;
    }
    CUtlString::operator=(this: &m_pMemory[v9].m_Name, src: pDeltaStateName);
    p_m_DeltaIndices = &s_DeltaStates.m_Memory.m_pMemory[v9].m_DeltaIndices;
    p_m_DeltaIndices->m_Size = 0;
    CUtlVector<DeltaIndex_t,CUtlMemory<DeltaIndex_t,int>>::InsertMultipleBefore(
      this: p_m_DeltaIndices,
      elem: 0,
      num: nBaseStateVertexCount);
    return &s_DeltaStates.m_Memory.m_pMemory[v9];
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = CUtlString::operator char const *(this: &s_DeltaStates.m_Memory.m_pMemory[v4].m_Name);
      if ( _V_stricmp(s1: v5, s2: pDeltaStateName) == 0 )
        break;
      ++v3;
      ++v4;
      if ( v3 >= nCount )
      {
        m_Size = s_DeltaStates.m_Size;
        goto LABEL_6;
      }
    }
    MdlWarning(fmt: "Unsupported duplicate delta state named \"%s\" in DMX file\n", pDeltaStateName);
    v13 = v3;
    if ( s_DeltaStates.m_Memory.m_pMemory[v13].m_DeltaIndices.m_Size < nBaseStateVertexCount )
      CUtlVector<DeltaIndex_t,CUtlMemory<DeltaIndex_t,int>>::InsertMultipleBefore(
        this: &s_DeltaStates.m_Memory.m_pMemory[v13].m_DeltaIndices,
        elem: s_DeltaStates.m_Memory.m_pMemory[v13].m_DeltaIndices.m_Size,
        num: nBaseStateVertexCount - s_DeltaStates.m_Memory.m_pMemory[v13].m_DeltaIndices.m_Size);
    return &s_DeltaStates.m_Memory.m_pMemory[v13];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F020
// Name: LoadDeltaState
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadDeltaState@<al>(
        CDmeVertexDeltaData *pDeltaState@<eax>,
        int nStartingUniqueVertex@<edx>,
        CDmeVertexData *pBindState,
        const matrix3x4_t *mat,
        float flScale,
        int nStartingUniqueVertexMap)
{
  const char *m_pAsString; // ecx
  DeltaState_t *v8; // esi
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *VertexIndexData; // eax
  int v10; // ecx
  const char *v11; // edi
  const char *v12; // edi
  const char *v13; // edi
  int v14; // edi
  int m_Size; // eax
  int v16; // eax
  int *m_pMemory; // edx
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndicesFromDataIndex; // ecx
  int v19; // edx
  int v20; // eax
  int v21; // edi
  DeltaIndex_t *v22; // ecx
  int v23; // edx
  int v24; // eax
  int m_nAllocationCount; // ecx
  Vector *v26; // edx
  int v27; // ecx
  Vector *v28; // eax
  const CUtlVector<int,CUtlMemory<int,int> > *v29; // ecx
  int v30; // edx
  int v31; // eax
  int v32; // edi
  DeltaIndex_t *v33; // ecx
  int v34; // edx
  int v35; // ecx
  const CUtlVector<int,CUtlMemory<int,int> > *v36; // eax
  float *v37; // edx
  int v38; // ecx
  float *v39; // eax
  const CUtlVector<int,CUtlMemory<int,int> > *v40; // ecx
  int v41; // edx
  int v42; // eax
  int v43; // edi
  DeltaIndex_t *v44; // ecx
  int v45; // edx
  matrix3x4_t normalMat; // [esp+Ch] [ebp-6Ch] BYREF
  Vector vecDelta; // [esp+3Ch] [ebp-3Ch] BYREF
  float *v49; // [esp+48h] [ebp-30h]
  int nBaseVertCount; // [esp+4Ch] [ebp-2Ch]
  int nPositionIndex; // [esp+50h] [ebp-28h]
  const CUtlVector<int,CUtlMemory<int,int> > *baseVerts; // [esp+54h] [ebp-24h]
  const CUtlVector<int,CUtlMemory<int,int> > *wrinkleIndices; // [esp+58h] [ebp-20h]
  const CUtlVector<int,CUtlMemory<int,int> > *normalIndices; // [esp+5Ch] [ebp-1Ch]
  int nCount; // [esp+60h] [ebp-18h]
  const CUtlVector<float,CUtlMemory<float,int> > *wrinkle; // [esp+64h] [ebp-14h]
  const CUtlVector<int,CUtlMemory<int,int> > *positionIndices; // [esp+68h] [ebp-10h]
  int i; // [esp+6Ch] [ebp-Ch]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *normals; // [esp+70h] [ebp-8h]
  int j; // [esp+74h] [ebp-4h]

  m_pAsString = pDeltaState->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  v8 = FindOrAddDeltaState(
         pDeltaStateName: m_pAsString,
         nBaseStateVertexCount: nStartingUniqueVertex + pBindState->m_nVertexCount);
  MatrixInverseTranspose(src: mat, dst: &normalMat);
  nCount = (int)CDmeVertexDataBase::GetPositionData(this: pDeltaState);
  positionIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                    this: pDeltaState,
                                                                    fieldId: FIELD_POSITION);
  normals = CDmeVertexDataBase::GetNormalData(this: pDeltaState);
  normalIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                  this: pDeltaState,
                                                                  fieldId: FIELD_NORMAL);
  wrinkle = CDmeVertexDataBase::GetWrinkleData(this: pDeltaState);
  VertexIndexData = CDmeVertexDataBase::GetVertexIndexData(this: pDeltaState, fieldId: FIELD_WRINKLE);
  v10 = *(_DWORD *)(nCount + 12);
  wrinkleIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)VertexIndexData;
  v49 = (float *)v10;
  if ( v10 != positionIndices->m_Size )
  {
    v11 = pDeltaState->m_Name.m_Storage.u.m_pAsString;
    if ( v11 == (const char *)-1 )
      v11 = pDeltaStateName;
    MdlError(fmt: "DeltaState %s contains a different number of positions + position indices!\n", v11);
  }
  if ( normals->m_Size != normalIndices->m_Size )
  {
    v12 = pDeltaState->m_Name.m_Storage.u.m_pAsString;
    if ( v12 == (const char *)-1 )
      v12 = pDeltaStateName;
    MdlError(fmt: "DeltaState %s contains a different number of normals + normal indices!\n", v12);
  }
  if ( wrinkle->m_Size != wrinkleIndices->m_Size )
  {
    v13 = pDeltaState->m_Name.m_Storage.u.m_pAsString;
    if ( v13 == (const char *)-1 )
      v13 = pDeltaStateName;
    MdlError(fmt: "DeltaState %s contains a different number of wrinkles + wrinkle indices!\n", v13);
  }
  v14 = 0;
  i = 0;
  if ( v10 > 0 )
  {
    j = 0;
    do
    {
      VectorRotate(in1: (const float *)(j + *(_DWORD *)nCount), in2: mat, out: &vecDelta.x);
      m_Size = v8->m_PositionDeltas.m_Size;
      vecDelta.x = vecDelta.x * flScale;
      vecDelta.y = vecDelta.y * flScale;
      vecDelta.z = vecDelta.z * flScale;
      v16 = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
              this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&v8->m_PositionDeltas,
              elem: m_Size,
              src: (const QAngle *)&vecDelta);
      m_pMemory = positionIndices->m_Memory.m_pMemory;
      nPositionIndex = v16;
      VertexIndicesFromDataIndex = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                                     this: pBindState,
                                     fieldId: FIELD_POSITION,
                                     nDataIndex: m_pMemory[v14]);
      v19 = VertexIndicesFromDataIndex->m_Size;
      v20 = 0;
      baseVerts = VertexIndicesFromDataIndex;
      nBaseVertCount = v19;
      if ( v19 > 0 )
      {
        while ( 1 )
        {
          v21 = s_UniqueVerticesMap.m_Memory.m_pMemory[nStartingUniqueVertexMap
                                                     + VertexIndicesFromDataIndex->m_Memory.m_pMemory[v20]];
          v22 = v8->m_DeltaIndices.m_Memory.m_pMemory;
          v23 = v21;
          if ( !v22[v21].m_bInList )
          {
            v22[v23].m_nNextDelta = v8->m_nFirstDelta;
            ++v8->m_nDeltaCount;
            v8->m_nFirstDelta = v21;
            v22[v23].m_bInList = true;
          }
          ++v20;
          v8->m_DeltaIndices.m_Memory.m_pMemory[v23].m_nPositionIndex = nPositionIndex;
          if ( v20 >= nBaseVertCount )
            break;
          VertexIndicesFromDataIndex = baseVerts;
        }
        v14 = i;
      }
      j += 12;
      i = ++v14;
    }
    while ( v14 < (int)v49 );
  }
  nCount = normals->m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    positionIndices = nullptr;
    do
    {
      VectorRotate(
        in1: (const float *)((char *)positionIndices + (unsigned int)normals->m_Memory.m_pMemory),
        in2: &normalMat,
        out: &vecDelta.x);
      m_nAllocationCount = v8->m_NormalDeltas.m_Memory.m_nAllocationCount;
      j = v8->m_NormalDeltas.m_Size;
      v24 = j;
      if ( j + 1 > m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&v8->m_NormalDeltas,
          num: j - m_nAllocationCount + 1);
        v24 = j;
      }
      ++v8->m_NormalDeltas.m_Size;
      v26 = v8->m_NormalDeltas.m_Memory.m_pMemory;
      v27 = v8->m_NormalDeltas.m_Size - v24 - 1;
      v8->m_NormalDeltas.m_pElements = v26;
      if ( v27 > 0 )
      {
        _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 12 * v27);
        v24 = j;
      }
      v28 = &v8->m_NormalDeltas.m_Memory.m_pMemory[v24];
      if ( v28 != nullptr )
        *v28 = vecDelta;
      v29 = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
              this: pBindState,
              fieldId: FIELD_NORMAL,
              nDataIndex: normalIndices->m_Memory.m_pMemory[i]);
      v30 = v29->m_Size;
      v31 = 0;
      v49 = (float *)v29;
      nBaseVertCount = v30;
      if ( v30 > 0 )
      {
        while ( 1 )
        {
          v32 = s_UniqueVerticesMap.m_Memory.m_pMemory[nStartingUniqueVertexMap + v29->m_Memory.m_pMemory[v31]];
          v33 = v8->m_DeltaIndices.m_Memory.m_pMemory;
          v34 = v32;
          if ( !v33[v32].m_bInList )
          {
            v33[v34].m_nNextDelta = v8->m_nFirstDelta;
            ++v8->m_nDeltaCount;
            v8->m_nFirstDelta = v32;
            v33[v34].m_bInList = true;
          }
          ++v31;
          v8->m_DeltaIndices.m_Memory.m_pMemory[v34].m_nNormalIndex = j;
          if ( v31 >= nBaseVertCount )
            break;
          v29 = (const CUtlVector<int,CUtlMemory<int,int> > *)v49;
        }
      }
      positionIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)positionIndices + 12);
      ++i;
    }
    while ( i < nCount );
  }
  nCount = wrinkle->m_Size;
  for ( j = 0; j < nCount; ++j )
  {
    v35 = v8->m_WrinkleDeltas.m_Memory.m_nAllocationCount;
    v49 = &wrinkle->m_Memory.m_pMemory[j];
    positionIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)v8->m_WrinkleDeltas.m_Size;
    v36 = positionIndices;
    if ( (int)&positionIndices->m_Memory.m_pMemory + 1 > v35 )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v8->m_WrinkleDeltas,
        num: (int)&positionIndices->m_Memory.m_pMemory - v35 + 1);
      v36 = positionIndices;
    }
    ++v8->m_WrinkleDeltas.m_Size;
    v37 = v8->m_WrinkleDeltas.m_Memory.m_pMemory;
    v38 = v8->m_WrinkleDeltas.m_Size - (_DWORD)v36 - 1;
    v8->m_WrinkleDeltas.m_pElements = v37;
    if ( v38 > 0 )
    {
      _V_memmove(dest: &v37[(_DWORD)v36 + 1], src: &v37[(_DWORD)v36], count: 4 * v38);
      v36 = positionIndices;
    }
    v39 = &v8->m_WrinkleDeltas.m_Memory.m_pMemory[(_DWORD)v36];
    if ( v39 != nullptr )
      *v39 = *v49;
    v40 = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
            this: pBindState,
            fieldId: FIELD_WRINKLE,
            nDataIndex: wrinkleIndices->m_Memory.m_pMemory[j]);
    v41 = v40->m_Size;
    v42 = 0;
    v49 = (float *)v40;
    nBaseVertCount = v41;
    if ( v41 > 0 )
    {
      while ( 1 )
      {
        v43 = s_UniqueVerticesMap.m_Memory.m_pMemory[nStartingUniqueVertexMap + v40->m_Memory.m_pMemory[v42]];
        v44 = v8->m_DeltaIndices.m_Memory.m_pMemory;
        v45 = v43;
        if ( !v44[v43].m_bInList )
        {
          v44[v45].m_nNextDelta = v8->m_nFirstDelta;
          ++v8->m_nDeltaCount;
          v8->m_nFirstDelta = v43;
          v44[v45].m_bInList = true;
        }
        ++v42;
        v8->m_DeltaIndices.m_Memory.m_pMemory[v45].m_nWrinkleIndex = (int)positionIndices;
        if ( v42 >= nBaseVertCount )
          break;
        v40 = (const CUtlVector<int,CUtlMemory<int,int> > *)v49;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040F490
// Name: ParseQuadFaceData
// Source: json
//------------------------------------------------------------------------------
void __usercall ParseQuadFaceData(
        int material@<eax>,
        int *pIndices@<ecx>,
        CDmeVertexData *pVertexData,
        int vi,
        int ni,
        int ti)
{
  int PositionIndex; // ebx
  int TexCoordIndex; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  unsigned int v15; // edi
  int v16; // eax
  int n; // [esp+40h] [ebp-4h]
  int na; // [esp+40h] [ebp-4h]
  int nb; // [esp+40h] [ebp-4h]
  int nc; // [esp+40h] [ebp-4h]
  s_tmpface_t f; // 0:^14.52

  f.material = material;
  PositionIndex = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: *pIndices);
  n = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: *pIndices);
  TexCoordIndex = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: *pIndices);
  if ( PositionIndex < 0 )
    f.a = 0;
  else
    f.a = vi + PositionIndex;
  if ( n < 0 )
    f.na = 0;
  else
    f.na = ni + n;
  if ( TexCoordIndex < 0 )
    f.ta = 0;
  else
    f.ta = ti + TexCoordIndex;
  v9 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: pIndices[3]);
  na = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: pIndices[3]);
  v10 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: pIndices[3]);
  if ( v9 < 0 )
    f.b = 0;
  else
    f.b = vi + v9;
  if ( na < 0 )
    f.nb = 0;
  else
    f.nb = ni + na;
  if ( v10 < 0 )
    f.tb = 0;
  else
    f.tb = ti + v10;
  v11 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: pIndices[2]);
  nb = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: pIndices[2]);
  v12 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: pIndices[2]);
  if ( v11 < 0 )
    f.c = 0;
  else
    f.c = vi + v11;
  if ( nb < 0 )
    f.nc = 0;
  else
    f.nc = ni + nb;
  if ( v12 < 0 )
    f.tc = 0;
  else
    f.tc = ti + v12;
  v13 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: pIndices[1]);
  nc = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: pIndices[1]);
  v14 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: pIndices[1]);
  if ( v13 < 0 )
    f.d = 0;
  else
    f.d = vi + v13;
  if ( nc < 0 )
    f.nd = 0;
  else
    f.nd = ni + nc;
  if ( v14 < 0 )
    f.td = 0;
  else
    f.td = ti + v14;
  v15 = g_numfaces;
  v16 = g_numfaces + 1;
  g_numfaces = v16;
  if ( g_face.m_Size < v16 )
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: g_face.m_Size,
      num: v16 - g_face.m_Size);
  g_face.m_Memory.m_pMemory[v15] = f;
}

//------------------------------------------------------------------------------
// Address: 0x0040F790
// Name: LoadBindPose
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadBindPose(CDmeModel *pModel, float flScale, const BoneTransformMap_t *boneMap, s_source_t *pSource)
{
  s_source_t *v4; // ebx
  s_sourceanim_t *v5; // esi
  unsigned __int8 *v6; // edi
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *p_rawanim; // esi
  int m_Size; // eax
  int v9; // edi
  int v10; // ebx
  int m_nAllocationCount; // ecx
  CUtlSymbolTableLargeBaseTreeEntry_t **m_pMemory; // ecx
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // ebx
  int v18; // ecx
  CUtlSymbolTableLargeBaseTreeEntry_t **v19; // ecx
  int v20; // eax
  int v21; // ecx
  char *v22; // eax
  CDmeTransformList *BaseState; // edx
  CDmeTransform **m_ppTransforms; // ecx
  int v25; // eax
  CDmeTransform *v26; // eax
  int v27; // eax
  CDmeTransform *v28; // edi
  int v29; // eax
  int v30; // edi
  int v31; // ebx
  int v32; // ecx
  CUtlSymbolTableLargeBaseTreeEntry_t **v33; // ecx
  int v34; // eax
  int v35; // edi
  matrix3x4_t jointTransform; // [esp+Ch] [ebp-44h] BYREF
  int v37; // [esp+3Ch] [ebp-14h]
  CDmeTransformList *pBindPose; // [esp+40h] [ebp-10h]
  int v39; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  int nMdlBoneIndex; // [esp+4Ch] [ebp-4h]

  v4 = pSource;
  v5 = FindOrAddSourceAnim(pSource, pAnimName: "BindPose");
  v5->startframe = 0;
  v5->endframe = 0;
  v5->numframes = 1;
  v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * pSource->numbones);
  memset(dst: v6, value: 0, count: 24 * pSource->numbones);
  p_rawanim = (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v5->rawanim;
  if ( p_rawanim->m_Size < 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: p_rawanim,
      elem: p_rawanim->m_Size,
      num: 1 - p_rawanim->m_Size);
  *p_rawanim->m_Memory.m_pMemory = (CUtlSymbolTableLargeBaseTreeEntry_t *)v6;
  i = 0;
  if ( pSource->numbones > 0 )
  {
    nMdlBoneIndex = 0;
    do
    {
      m_Size = p_rawanim->m_Size;
      if ( m_Size < 1 )
      {
        v9 = 1 - m_Size;
        v10 = p_rawanim->m_Size;
        m_nAllocationCount = p_rawanim->m_Memory.m_nAllocationCount;
        v39 = v10 + v9;
        if ( v10 + v9 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)p_rawanim,
            num: v9 + v10 - m_nAllocationCount);
        p_rawanim->m_Size += v9;
        m_pMemory = p_rawanim->m_Memory.m_pMemory;
        v13 = p_rawanim->m_Size - v10 - v9;
        p_rawanim->m_pElements = p_rawanim->m_Memory.m_pMemory;
        if ( v13 > 0 && v9 > 0 )
          _V_memmove(dest: &m_pMemory[v39], src: &m_pMemory[v10], count: 4 * v13);
      }
      v14 = (unsigned int *)((char *)&(*p_rawanim->m_Memory.m_pMemory)->m_Hash + nMdlBoneIndex);
      *v14 = 0;
      v14[1] = 0;
      v14[2] = 0;
      v15 = p_rawanim->m_Size;
      if ( v15 < 1 )
      {
        v16 = 1 - v15;
        v17 = p_rawanim->m_Size;
        v18 = p_rawanim->m_Memory.m_nAllocationCount;
        v39 = v17 + v16;
        if ( v17 + v16 > v18 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)p_rawanim,
            num: v16 + v17 - v18);
        p_rawanim->m_Size += v16;
        v19 = p_rawanim->m_Memory.m_pMemory;
        v20 = p_rawanim->m_Size - v17 - v16;
        p_rawanim->m_pElements = p_rawanim->m_Memory.m_pMemory;
        if ( v20 > 0 && v16 > 0 )
          _V_memmove(dest: &v19[v39], src: &v19[v17], count: 4 * v20);
      }
      v21 = nMdlBoneIndex;
      v4 = pSource;
      v22 = &(*p_rawanim->m_Memory.m_pMemory)[1].m_String[nMdlBoneIndex];
      *(_DWORD *)v22 = 0;
      *((_DWORD *)v22 + 1) = 0;
      *((_DWORD *)v22 + 2) = 0;
      ++i;
      nMdlBoneIndex = v21 + 24;
    }
    while ( i < pSource->numbones );
  }
  BaseState = CDmeModel::FindBaseState(this: pModel, pBaseStateName: "bind");
  pBindPose = BaseState;
  nMdlBoneIndex = 0;
  if ( boneMap->m_nBoneCount > 0 )
  {
    i = 0;
    m_ppTransforms = boneMap->m_ppTransforms;
    v39 = (int)boneMap->m_ppTransforms;
    while ( 1 )
    {
      v25 = (int)m_ppTransforms[2048];
      if ( v25 >= 0 )
      {
        if ( BaseState != nullptr )
        {
          v27 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: BaseState->m_Transforms.m_Storage.m_Memory.m_pMemory[v25]);
          v28 = (CDmeTransform *)v27;
          if ( v27 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v27 + 16))(
                 a1: v27,
                 a2: CDmeTransform::m_classType.u) != 0 )
          {
            v26 = v28;
          }
          else
          {
            v26 = nullptr;
          }
        }
        else
        {
          v26 = CDmeModel::GetJointTransform(this: pModel, nIndex: v25);
        }
      }
      else
      {
        v26 = *m_ppTransforms;
      }
      if ( v26 != nullptr )
      {
        CDmeTransform::GetTransform(this: v26, transform: &jointTransform);
        v29 = p_rawanim->m_Size;
        if ( v29 < 1 )
        {
          v30 = 1 - v29;
          v31 = p_rawanim->m_Size;
          v32 = p_rawanim->m_Memory.m_nAllocationCount;
          v37 = v31 + v30;
          if ( v31 + v30 > v32 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)p_rawanim,
              num: v30 + v31 - v32);
          p_rawanim->m_Size += v30;
          v33 = p_rawanim->m_Memory.m_pMemory;
          v34 = p_rawanim->m_Size - v31 - v30;
          p_rawanim->m_pElements = p_rawanim->m_Memory.m_pMemory;
          if ( v34 > 0 && v30 > 0 )
            _V_memmove(dest: &v33[v37], src: &v33[v31], count: 4 * v34);
        }
        v35 = (int)*p_rawanim->m_Memory.m_pMemory + i;
        MatrixAngles(matrix: &jointTransform, angles: (RadianEuler *)(v35 + 12), position: (Vector *)v35);
        v4 = pSource;
        *(float *)v35 = *(float *)v35 * flScale;
        *(float *)(v35 + 4) = *(float *)(v35 + 4) * flScale;
        *(float *)(v35 + 8) = *(float *)(v35 + 8) * flScale;
      }
      else
      {
        MdlWarning(fmt: "Cannot find DmeTransform for MDL Bone %d\n", nMdlBoneIndex);
      }
      i += 24;
      m_ppTransforms = (CDmeTransform **)(v39 + 4);
      ++nMdlBoneIndex;
      v39 += 4;
      if ( nMdlBoneIndex >= boneMap->m_nBoneCount )
        break;
      BaseState = pBindPose;
    }
  }
  Build_Reference(pSource: v4, pAnimName: "BindPose");
}

//------------------------------------------------------------------------------
// Address: 0x0040FAE0
// Name: ComputeFramePose
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeFramePose(s_sourceanim_t *pSourceAnim, int nFrame, float flScale, BoneTransformMap_t *boneMap)
{
  unsigned __int8 *v4; // eax
  int v5; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_rawanim; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax
  int v8; // edi
  CUtlSymbolTable::StringPool_t **v9; // ecx
  int m_nAllocationCount; // edx
  CUtlSymbolTable::StringPool_t **v11; // edx
  int v12; // eax
  CUtlSymbolTable::StringPool_t **v13; // eax
  int v14; // edi
  CUtlSymbolTable::StringPool_t **v15; // ebx
  int v16; // ecx
  CUtlSymbolTable::StringPool_t **v17; // ecx
  int v18; // eax
  CUtlSymbolTable::StringPool_t **v19; // eax
  int v20; // edi
  CUtlSymbolTable::StringPool_t **v21; // ebx
  int v22; // ecx
  CUtlSymbolTable::StringPool_t **v23; // ecx
  int v24; // eax
  int v25; // ecx
  float *v26; // eax
  unsigned int v27; // [esp-4h] [ebp-50h]
  matrix3x4_t jointTransform; // [esp+Ch] [ebp-40h] BYREF
  char *v29; // [esp+3Ch] [ebp-10h]
  CUtlSymbolTable::StringPool_t **v30; // [esp+40h] [ebp-Ch]
  int i; // [esp+44h] [ebp-8h]
  int v32; // [esp+48h] [ebp-4h]
  CDmeTransform **pSourceAnima; // [esp+54h] [ebp+8h]

  v4 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * boneMap->m_nBoneCount);
  v27 = 24 * boneMap->m_nBoneCount;
  i = (int)v4;
  memset(dst: v4, value: 0, count: v27);
  v5 = nFrame;
  p_rawanim = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pSourceAnim->rawanim;
  if ( pSourceAnim->rawanim.m_Size < nFrame + 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&pSourceAnim->rawanim,
      elem: pSourceAnim->rawanim.m_Size,
      num: nFrame + 1 - pSourceAnim->rawanim.m_Size);
  p_rawanim->m_pMemory[nFrame] = (CUtlSymbolTable::StringPool_t *)i;
  i = 0;
  if ( boneMap->m_nBoneCount > 0 )
  {
    v32 = 0;
    pSourceAnima = boneMap->m_ppTransforms;
    do
    {
      CDmeTransform::GetTransform(this: *pSourceAnima, transform: &jointTransform);
      m_pMemory = p_rawanim[1].m_pMemory;
      if ( (int)m_pMemory < v5 + 1 )
      {
        v8 = v5 + 1 - (_DWORD)m_pMemory;
        v9 = p_rawanim[1].m_pMemory;
        v30 = v9;
        if ( v8 != 0 )
        {
          m_nAllocationCount = p_rawanim->m_nAllocationCount;
          v29 = (char *)v9 + v8;
          if ( (int)v9 + v8 > m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_rawanim, num: (int)v9 + v8 - m_nAllocationCount);
            v9 = v30;
          }
          p_rawanim[1].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)p_rawanim[1].m_pMemory + v8);
          v11 = p_rawanim->m_pMemory;
          v12 = (char *)p_rawanim[1].m_pMemory - (char *)v9 - v8;
          p_rawanim[1].m_nAllocationCount = (int)p_rawanim->m_pMemory;
          if ( v12 > 0 && v8 > 0 )
            _V_memmove(dest: &v11[(_DWORD)v29], src: &v11[(_DWORD)v9], count: 4 * v12);
        }
      }
      v13 = p_rawanim[1].m_pMemory;
      v30 = p_rawanim->m_pMemory;
      if ( (int)v13 < v5 + 1 )
      {
        v14 = v5 + 1 - (_DWORD)v13;
        v15 = v13;
        if ( v14 != 0 )
        {
          v16 = p_rawanim->m_nAllocationCount;
          v29 = (char *)v13 + v14;
          if ( (int)v13 + v14 > v16 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_rawanim, num: (int)v13 + v14 - v16);
          p_rawanim[1].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)p_rawanim[1].m_pMemory + v14);
          v17 = p_rawanim->m_pMemory;
          v18 = (char *)p_rawanim[1].m_pMemory - (char *)v15 - v14;
          p_rawanim[1].m_nAllocationCount = (int)p_rawanim->m_pMemory;
          if ( v18 > 0 && v14 > 0 )
            _V_memmove(dest: &v17[(_DWORD)v29], src: &v17[(_DWORD)v15], count: 4 * v18);
        }
        v5 = nFrame;
      }
      MatrixAngles(
        matrix: &jointTransform,
        angles: (RadianEuler *)((char *)&p_rawanim->m_pMemory[v5][1] + v32),
        position: (Vector *)((char *)v30[v5] + v32));
      v19 = p_rawanim[1].m_pMemory;
      if ( (int)v19 < v5 + 1 )
      {
        v20 = v5 + 1 - (_DWORD)v19;
        v21 = p_rawanim[1].m_pMemory;
        if ( v20 != 0 )
        {
          v22 = p_rawanim->m_nAllocationCount;
          v29 = (char *)v21 + v20;
          if ( (int)v21 + v20 > v22 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_rawanim, num: (int)v21 + v20 - v22);
          p_rawanim[1].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)p_rawanim[1].m_pMemory + v20);
          v23 = p_rawanim->m_pMemory;
          v24 = (char *)p_rawanim[1].m_pMemory - (char *)v21 - v20;
          p_rawanim[1].m_nAllocationCount = (int)p_rawanim->m_pMemory;
          if ( v24 > 0 && v20 > 0 )
            _V_memmove(dest: &v23[(_DWORD)v29], src: &v23[(_DWORD)v21], count: 4 * v24);
        }
        v5 = nFrame;
      }
      v25 = v32;
      ++pSourceAnima;
      v26 = (float *)((char *)&p_rawanim->m_pMemory[v5]->m_TotalLen + v32);
      *v26 = flScale * *v26;
      v26[1] = v26[1] * flScale;
      v26[2] = v26[2] * flScale;
      v32 = v25 + 24;
      ++i;
    }
    while ( i < boneMap->m_nBoneCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FD10
// Name: LoadAnimations
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadAnimations(
        s_source_t *pSource,
        CDmeAnimationList *pAnimationList,
        float flScale,
        BoneTransformMap_t *boneMap)
{
  CDmeAnimationList *v4; // ebx
  int v5; // edi
  int v6; // eax
  CDmeChannelsClip *v7; // esi
  const char *Name; // eax
  const char *m_pAsString; // eax
  s_sourceanim_t *v10; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v12; // esi
  CDmaVar<int> *m_pData; // esi
  int m_Storage; // esi
  int v15; // eax
  CDmeChannelsClip *v16; // edx
  float v17; // xmm0_4
  int v18; // esi
  int v19; // eax
  IDmeOperator **m_pMemory; // eax
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > operatorList; // [esp+18h] [ebp-34h] BYREF
  int nAnimationCount; // [esp+2Ch] [ebp-20h]
  float flOOFrameRate; // [esp+30h] [ebp-1Ch]
  DmeTime_t nEndTime; // [esp+34h] [ebp-18h] BYREF
  DmeTime_t nStartTime; // [esp+38h] [ebp-14h] BYREF
  int i; // [esp+3Ch] [ebp-10h]
  CDmeChannelsClip *pAnimation; // [esp+40h] [ebp-Ch]
  int nFrameRateVal; // [esp+44h] [ebp-8h]
  DmeFramerate_t nFrameRate; // [esp+48h] [ebp-4h] BYREF

  v4 = pAnimationList;
  v5 = 0;
  nAnimationCount = pAnimationList->m_Animations.m_Storage.m_Size;
  i = 0;
  if ( nAnimationCount > 0 )
  {
    while ( 1 )
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v4->m_Animations.m_Storage.m_Memory.m_pMemory[i]);
      v7 = (CDmeChannelsClip *)v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        pAnimation = v7;
      }
      else
      {
        pAnimation = nullptr;
        v7 = nullptr;
      }
      Name = CDmElement::GetName(this: v4);
      if ( _V_stricmp(s1: Name, s2: "BindPose") == 0 )
        MdlError(fmt: "Error: Cannot use \"BindPose\" as an animation name!\n");
      m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v10 = FindOrAddSourceAnim(pSource, pAnimName: m_pAsString);
      CDmeClip::GetStartTime(this: v7, result: &nStartTime);
      CDmeClip::GetEndTime(this: v7, result: &nEndTime);
      if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "frameRate");
      v12 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 2 )
        {
          m_pData = (CDmaVar<int> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<int>(this: v12, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
          m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = m_pData->m_Storage;
      nFrameRateVal = m_Storage;
      if ( m_Storage <= 0 )
      {
        nFrameRateVal = 30;
        m_Storage = 30;
      }
      DmeFramerate_t::DmeFramerate_t(this: &nFrameRate, fps: m_Storage);
      v10->startframe = DmeTime_t::CurrentFrame(this: &nStartTime, framerate: nFrameRate, roundStyle: ROUND_DOWN);
      v15 = DmeTime_t::CurrentFrame(this: &nEndTime, framerate: nFrameRate, roundStyle: ROUND_DOWN);
      v16 = pAnimation;
      v10->endframe = v15;
      v10->numframes = v15 - v10->startframe + 1;
      memset((void *)&operatorList, 0, sizeof(operatorList));
      PrepareChannels((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&operatorList, pAnimation: v16);
      v17 = 1.0 / (float)m_Storage;
      flOOFrameRate = v17;
      if ( v10->numframes > 0 )
      {
        while ( 1 )
        {
          v18 = v5 / m_Storage;
          v19 = DmeTime_t::RoundSecondsToTMS(sec: (float)(v5 - nFrameRateVal * v18) * v17);
          UpdateChannels(
            operators: &operatorList,
            pAnimation,
            clipTime: (DmeTime_t)(nStartTime.m_tms + v19 + 10000 * v18));
          ComputeFramePose(pSourceAnim: v10, nFrame: v5++, flScale, boneMap);
          if ( v5 >= v10->numframes )
            break;
          v17 = flOOFrameRate;
          m_Storage = nFrameRateVal;
        }
        v5 = 0;
      }
      m_pMemory = operatorList.m_Memory.m_pMemory;
      operatorList.m_Size = 0;
      if ( operatorList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( operatorList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorList.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          operatorList.m_Memory.m_pMemory = nullptr;
        }
        operatorList.m_Memory.m_nAllocationCount = 0;
      }
      operatorList.m_pElements = m_pMemory;
      if ( operatorList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      if ( ++i >= nAnimationCount )
        break;
      v4 = pAnimationList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FFE0
// Name: bool LoadTwistConstraint(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadTwistConstraint(CDmElement *pDmElement)
{
  CDmeRigTwistConstraintOperator *v1; // edi
  CDmeDag *ParentTarget; // ebx
  CDmeDag *ChildTarget; // eax
  CTwistBone *v4; // esi
  const char *m_pAsString; // eax
  _QWORD *p_x; // eax
  const char *v7; // eax
  int v8; // eax
  CDmeDag *SlaveDag; // eax
  char *m_Id; // eax
  char v11; // cl
  int v12; // eax
  int v13; // edi
  int *v14; // ebx
  int v15; // esi
  int m_szBoneName; // esi
  const char *v17; // eax
  CDmeTransform *Transform; // eax
  char *s1; // [esp+Ch] [ebp-20h]
  _DWORD *v21; // [esp+10h] [ebp-1Ch]
  CDmeDag *pDmeTwistDag; // [esp+14h] [ebp-18h]
  int v23; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  CTwistBone *twistBone; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]
  CDmeRigTwistConstraintOperator *pDmeTwist; // [esp+28h] [ebp-4h]
  CDmeDag *bFound; // [esp+34h] [ebp+8h]
  char bFound_3; // [esp+37h] [ebp+Bh]

  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigTwistConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v1 = (CDmeRigTwistConstraintOperator *)((char *)&pDmElement[-1] + 64);
  pDmeTwist = (CDmeRigTwistConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( pDmElement == (CDmElement *)4 )
    return 0;
  if ( g_twistbones.m_Size == 256 )
    return 0;
  ParentTarget = CDmeRigTwistConstraintOperator::GetParentTarget(this: v1);
  ChildTarget = CDmeRigTwistConstraintOperator::GetChildTarget(this: v1);
  bFound = ChildTarget;
  if ( ParentTarget == nullptr || ChildTarget == nullptr )
    return 0;
  v4 = &g_twistbones.m_Memory.m_pMemory[CUtlVector<CTwistBone,CUtlMemory<CTwistBone,int>>::InsertBefore(
                                          this: &g_twistbones,
                                          elem: g_twistbones.m_Size)];
  v4->m_bInverse = v1->m_bInverse.m_Storage;
  twistBone = v4;
  v4->m_vUpVector.x = v1->m_vUpAxis.m_Storage.x;
  v4->m_vUpVector.y = v1->m_vUpAxis.m_Storage.y;
  v4->m_vUpVector.z = v1->m_vUpAxis.m_Storage.z;
  m_pAsString = ParentTarget->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  V_strncpy(pDest: v4->m_szParentBoneName, pSrc: m_pAsString, maxLen: 128);
  p_x = (_QWORD *)&v1->m_qParentBindRotation.m_Storage.x;
  if ( !v4->m_bInverse )
    p_x = (_QWORD *)&v1->m_qChildBindRotation.m_Storage.x;
  *(_QWORD *)&v4->m_qBaseRotation.x = *p_x;
  *(_QWORD *)&v4->m_qBaseRotation.z = p_x[1];
  v7 = bFound->m_Name.m_Storage.u.m_pAsString;
  if ( v7 == (const char *)-1 )
    v7 = pDeltaStateName;
  V_strncpy(pDest: v4->m_szChildBoneName, pSrc: v7, maxLen: 128);
  v8 = 0;
  for ( i = 0; v8 < v1->m_eSlaves.m_Storage.m_Size; i = v8 )
  {
    SlaveDag = CDmeRigTwistConstraintOperator::GetSlaveDag(this: v1, i: v8);
    pDmeTwistDag = SlaveDag;
    if ( SlaveDag != nullptr )
    {
      m_Id = (char *)SlaveDag->m_Name.m_Storage.u.CDmElement::m_Id;
      s1 = m_Id;
      if ( m_Id != (char *)-1 && m_Id != nullptr && *m_Id != 0 )
      {
        v11 = 0;
        v12 = 0;
        bFound_3 = 0;
        j = 0;
        v23 = 0;
        while ( j < g_twistbones.m_Size )
        {
          v13 = 0;
          v14 = (int *)((char *)&g_twistbones.m_Memory.m_pMemory->m_twistBoneTargets.m_Size + v12);
          if ( *v14 > 0 )
          {
            v21 = (s_constraintbonetarget_t **)((char *)&g_twistbones.m_Memory.m_pMemory->m_twistBoneTargets.m_Memory.m_pMemory
                                              + v12);
            v15 = 0;
            while ( _V_stricmp(s1, s2: (const char *)(v15 + *v21)) != 0 )
            {
              ++v13;
              v15 += 164;
              if ( v13 >= *v14 )
                goto LABEL_26;
            }
            bFound_3 = 1;
LABEL_26:
            v4 = twistBone;
          }
          v11 = bFound_3;
          ++j;
          v1 = pDmeTwist;
          v12 = v23 + 316;
          v23 += 316;
          if ( bFound_3 != 0 )
            goto LABEL_33;
        }
        if ( v11 == 0 )
        {
          m_szBoneName = (int)v4->m_twistBoneTargets.m_Memory.m_pMemory[CUtlVector<s_constraintbonetarget_t,CUtlMemory<s_constraintbonetarget_t,int>>::AddToTail(this: &v4->m_twistBoneTargets)].m_szBoneName;
          v17 = pDmeTwistDag->m_Name.m_Storage.u.m_pAsString;
          if ( v17 == (const char *)-1 )
            v17 = pDeltaStateName;
          V_strncpy(pDest: (char *)m_szBoneName, pSrc: v17, maxLen: 128);
          *(_DWORD *)(m_szBoneName + 128) = -1;
          *(float *)(m_szBoneName + 132) = CDmeRigTwistConstraintOperator::GetSlaveWeight(this: pDmeTwist, i);
          Transform = CDmeDag::GetTransform(this: pDmeTwistDag);
          *(Vector *)(m_szBoneName + 136) = *CDmeTransform::GetPosition(this: Transform);
          *(Quaternion *)(m_szBoneName + 148) = *CDmeRigTwistConstraintOperator::GetSlaveBindOrientation(
                                                   this: pDmeTwist,
                                                   i);
          v4 = twistBone;
          v1 = pDmeTwist;
        }
      }
    }
LABEL_33:
    v8 = i + 1;
  }
  if ( v4->m_twistBoneTargets.m_Size <= 0 )
    CUtlVector<CTwistBone,CUtlMemory<CTwistBone,int>>::RemoveMultipleFromTail(this: &g_twistbones, num: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004102C0
// Name: void LoadConstraints(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadConstraints(CDmElement *pDmeRoot)
{
  int v1; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // esi
  DmElementArray_t *m_pData; // esi
  int v5; // eax
  int v6; // eax
  CDmElement *v7; // esi
  int v8; // eax
  CDmElement *v9; // esi
  CDmElement *v10; // eax
  int v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // eax
  int v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // eax
  CDmElement *v17; // eax
  const char *m_pAsString; // eax
  CDmrElementArray<CDmElement> constraints; // [esp+Ch] [ebp-8h] BYREF

  v1 = 0;
  if ( pDmeRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pDmeRoot, pAttributeName: "constraints");
    v3 = Attribute;
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&constraints);
      if ( (v3->m_nFlags & 0x1F) == 0xF )
      {
        constraints.m_pAttribute = v3;
        m_pData = (DmElementArray_t *)v3->m_pData;
      }
      else
      {
        constraints.m_pAttribute = nullptr;
        m_pData = nullptr;
      }
      constraints.m_pStorage = m_pData;
      while ( 1 )
      {
        v5 = constraints.m_pAttribute != nullptr ? m_pData->m_Size : 0;
        if ( v1 >= v5 )
          break;
        v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: m_pData->m_Memory.m_pMemory[v1]);
        v7 = (CDmElement *)v6;
        if ( v6 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v7 = nullptr;
        }
        if ( LoadTwistConstraint(pDmElement: v7) == 0 )
        {
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: constraints.m_pStorage->m_Memory.m_pMemory[v1]);
          v9 = (CDmElement *)v8;
          if ( v8 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            v10 = v9;
          }
          else
          {
            v10 = nullptr;
          }
          if ( LoadConstraint_CDmeRigPointConstraintOperator_CPointConstraint_(pDmElement: v10) == 0 )
          {
            v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: constraints.m_pStorage->m_Memory.m_pMemory[v1]);
            v12 = (CDmElement *)v11;
            if ( v11 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
                   a1: v11,
                   a2: CDmElement::m_classType.u) != 0 )
            {
              v13 = v12;
            }
            else
            {
              v13 = nullptr;
            }
            if ( LoadConstraint_CDmeRigOrientConstraintOperator_COrientConstraint_(pDmElement: v13) == 0 )
            {
              v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: constraints.m_pStorage->m_Memory.m_pMemory[v1]);
              v15 = (CDmElement *)v14;
              if ( v14 != 0
                && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v14 + 16))(
                     a1: v14,
                     a2: CDmElement::m_classType.u) != 0 )
              {
                v16 = v15;
              }
              else
              {
                v16 = nullptr;
              }
              if ( LoadConstraint_CDmeRigAimConstraintOperator_CAimConstraint_(pDmElement: v16) == 0 )
              {
                v17 = CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](
                        this: &constraints,
                        i: v1);
                if ( LoadConstraint_CDmeRigParentConstraintOperator_CParentConstraint_(pDmElement: v17) == 0 )
                {
                  m_pAsString = CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](
                                  this: &constraints,
                                  i: v1)->m_Name.m_Storage.u.m_pAsString;
                  if ( m_pAsString == (const char *)-1 )
                    m_pAsString = pDeltaStateName;
                  _Error(a1: "TODO: Support Constraint: %s\n", m_pAsString);
                }
              }
            }
          }
        }
        m_pData = constraints.m_pStorage;
        ++v1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410490
// Name: CreateAnimFromSkeleton
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateAnimFromSkeleton(s_source_t *pSource, const char *pSequenceName, const BoneTransformMap_t *boneMap)
{
  s_source_t *v3; // ebx
  s_sourceanim_t *v4; // esi
  unsigned __int8 *v5; // edi
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *p_rawanim; // esi
  int m_Size; // eax
  int v8; // edi
  int v9; // ebx
  int m_nAllocationCount; // ecx
  CUtlSymbolTableLargeBaseTreeEntry_t **m_pMemory; // ecx
  int v12; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t *v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // ecx
  CUtlSymbolTableLargeBaseTreeEntry_t **v18; // ecx
  int v19; // eax
  char *m_String; // eax
  int v21; // eax
  int v22; // edi
  int v23; // ebx
  int v24; // ecx
  CUtlSymbolTableLargeBaseTreeEntry_t **v25; // ecx
  int v26; // eax
  RadianEuler *v27; // edi
  const Vector *Position; // eax
  float v29; // xmm1_4
  float v30; // xmm2_4
  const Quaternion *Orientation; // eax
  float v32; // [esp+Ch] [ebp-18h]
  int nBoneIndex; // [esp+14h] [ebp-10h]
  CDmeTransform *pDmeTransform; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int ia; // [esp+1Ch] [ebp-8h]
  int v37; // [esp+20h] [ebp-4h]
  CDmeTransform **m_ppTransforms; // [esp+20h] [ebp-4h]

  v3 = pSource;
  v4 = FindOrAddSourceAnim(pSource, pAnimName: pSequenceName);
  v4->startframe = 0;
  v4->endframe = 0;
  v4->numframes = 1;
  v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * pSource->numbones);
  memset(dst: v5, value: 0, count: 24 * pSource->numbones);
  p_rawanim = (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v4->rawanim;
  if ( p_rawanim->m_Size < 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: p_rawanim,
      elem: p_rawanim->m_Size,
      num: 1 - p_rawanim->m_Size);
  *p_rawanim->m_Memory.m_pMemory = (CUtlSymbolTableLargeBaseTreeEntry_t *)v5;
  i = 0;
  if ( pSource->numbones > 0 )
  {
    v37 = 0;
    do
    {
      m_Size = p_rawanim->m_Size;
      if ( m_Size < 1 )
      {
        v8 = 1 - m_Size;
        v9 = p_rawanim->m_Size;
        m_nAllocationCount = p_rawanim->m_Memory.m_nAllocationCount;
        if ( v9 + v8 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)p_rawanim,
            num: v8 + v9 - m_nAllocationCount);
        p_rawanim->m_Size += v8;
        m_pMemory = p_rawanim->m_Memory.m_pMemory;
        v12 = p_rawanim->m_Size - v9 - v8;
        p_rawanim->m_pElements = p_rawanim->m_Memory.m_pMemory;
        if ( v12 > 0 && v8 > 0 )
          _V_memmove(dest: &m_pMemory[v9] + v8, src: &m_pMemory[v9], count: 4 * v12);
      }
      v13 = &(*p_rawanim->m_Memory.m_pMemory)[v37];
      v13->m_Hash = 0;
      *(_DWORD *)v13->m_String = 0;
      v13[1].m_Hash = 0;
      v14 = p_rawanim->m_Size;
      if ( v14 < 1 )
      {
        v15 = 1 - v14;
        v16 = p_rawanim->m_Size;
        v17 = p_rawanim->m_Memory.m_nAllocationCount;
        if ( v16 + v15 > v17 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)p_rawanim,
            num: v15 + v16 - v17);
        p_rawanim->m_Size += v15;
        v18 = p_rawanim->m_Memory.m_pMemory;
        v19 = p_rawanim->m_Size - v16 - v15;
        p_rawanim->m_pElements = p_rawanim->m_Memory.m_pMemory;
        if ( v19 > 0 && v15 > 0 )
          _V_memmove(dest: &v18[v16] + v15, src: &v18[v16], count: 4 * v19);
      }
      v3 = pSource;
      m_String = (*p_rawanim->m_Memory.m_pMemory)[v37 + 1].m_String;
      *(_DWORD *)m_String = 0;
      *((_DWORD *)m_String + 1) = 0;
      *((_DWORD *)m_String + 2) = 0;
      ++i;
      v37 += 3;
    }
    while ( i < pSource->numbones );
  }
  nBoneIndex = 0;
  if ( boneMap->m_nBoneCount > 0 )
  {
    ia = 0;
    m_ppTransforms = boneMap->m_ppTransforms;
    do
    {
      v21 = p_rawanim->m_Size;
      pDmeTransform = *m_ppTransforms;
      if ( v21 < 1 )
      {
        v22 = 1 - v21;
        v23 = p_rawanim->m_Size;
        v24 = p_rawanim->m_Memory.m_nAllocationCount;
        if ( v24 < 1 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)p_rawanim,
            num: 1 - v24);
        p_rawanim->m_Size += v22;
        v25 = p_rawanim->m_Memory.m_pMemory;
        v26 = p_rawanim->m_Size - v23 - v22;
        p_rawanim->m_pElements = p_rawanim->m_Memory.m_pMemory;
        if ( v26 > 0 && v22 > 0 )
          _V_memmove(dest: &v25[v23] + v22, src: &v25[v23], count: 4 * v26);
      }
      v27 = (RadianEuler *)&(*p_rawanim->m_Memory.m_pMemory)[ia];
      v32 = g_currentscale;
      Position = CDmeTransform::GetPosition(this: pDmeTransform);
      v29 = Position->y * v32;
      v30 = Position->z * v32;
      v27->x = Position->x * v32;
      v27->y = v29;
      v27->z = v30;
      Orientation = CDmeTransform::GetOrientation(this: pDmeTransform);
      QuaternionAngles(q: Orientation, angles: v27 + 1);
      ++m_ppTransforms;
      ia += 3;
      ++nBoneIndex;
    }
    while ( nBoneIndex < boneMap->m_nBoneCount );
    v3 = pSource;
  }
  Build_Reference(pSource: v3, pAnimName: pSequenceName);
}

//------------------------------------------------------------------------------
// Address: 0x00410770
// Name: GetContentsDescription
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetContentsDescription(int *nContentsDescription, CDmElement *pDmElement)
{
  unsigned int v2; // edi
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *v6; // esi
  int m_Size; // ebx
  int v8; // edi
  CUtlString *m_pMemory; // esi
  int v10; // eax
  const char *v11; // eax
  const char *m_pAsString; // eax
  int k; // esi
  const char *v14; // eax
  const char *v15; // [esp-Ch] [ebp-ACh]
  GetContentsDescription::__l10::ContentDesc_t contentDescs[11]; // [esp+4h] [ebp-9Ch]
  int j; // [esp+5Ch] [ebp-44h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > userContentsDesc; // [esp+60h] [ebp-40h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > validContentsDesc; // [esp+74h] [ebp-2Ch] BYREF
  CUtlString sWarn; // [esp+88h] [ebp-18h] BYREF
  const char *v21; // [esp+98h] [ebp-8h]
  int i; // [esp+9Ch] [ebp-4h]

  v2 = 0;
  *nContentsDescription = 1;
  if ( pDmElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pDmElement, pAttributeName: "contentsDescription");
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 5 )
    return 0;
  v5 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
  if ( v5 == (const char *)-1 )
  {
    v6 = pDeltaStateName;
    v21 = pDeltaStateName;
  }
  else
  {
    v21 = v5;
    if ( v5 == nullptr )
      return 0;
    v6 = v5;
  }
  if ( _V_strlen(str: v6) <= 0 )
    return 0;
  contentDescs[0].m_pszName = "notsolid";
  contentDescs[0].m_nContentDescriptionFlags = 0;
  contentDescs[1].m_pszName = "monster";
  contentDescs[1].m_nContentDescriptionFlags = (int)&v_listdata[508764];
  contentDescs[2].m_pszName = "ladder";
  contentDescs[2].m_nContentDescriptionFlags = 0x20000000;
  contentDescs[3].m_pszName = "solid";
  contentDescs[3].m_nContentDescriptionFlags = 1;
  contentDescs[4].m_pszName = "solid_monster";
  contentDescs[4].m_nContentDescriptionFlags = (int)&v_listdata[508764].refcount + 1;
  contentDescs[5].m_pszName = "solid_ladder";
  contentDescs[5].m_nContentDescriptionFlags = 536870913;
  contentDescs[6].m_pszName = "solid_monster_ladder";
  contentDescs[6].m_nContentDescriptionFlags = 570425345;
  contentDescs[7].m_pszName = "grate";
  contentDescs[7].m_nContentDescriptionFlags = 8;
  contentDescs[8].m_pszName = "grate_monster";
  contentDescs[8].m_nContentDescriptionFlags = (int)&v_listdata[508764].firstref;
  contentDescs[9].m_pszName = "grate_ladder";
  contentDescs[9].m_nContentDescriptionFlags = 536870920;
  contentDescs[10].m_pszName = "grate_monster_ladder";
  contentDescs[10].m_nContentDescriptionFlags = 570425352;
  memset(&userContentsDesc, 0, sizeof(userContentsDesc));
  UnderscoreSplitAndSortStrings(
    splitAndSortedString: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&userContentsDesc,
    pszString: v6);
  m_Size = userContentsDesc.m_Size;
  memset(&validContentsDesc, 0, sizeof(validContentsDesc));
  i = 0;
  do
  {
    UnderscoreSplitAndSortStrings(
      splitAndSortedString: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&validContentsDesc,
      pszString: contentDescs[v2].m_pszName);
    if ( m_Size == validContentsDesc.m_Size )
    {
      v8 = 0;
      if ( m_Size <= 0 )
      {
LABEL_28:
        *nContentsDescription = contentDescs[i].m_nContentDescriptionFlags;
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&validContentsDesc);
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&userContentsDesc);
        return 1;
      }
      m_pMemory = userContentsDesc.m_Memory.m_pMemory;
      v10 = (char *)validContentsDesc.m_Memory.m_pMemory - (char *)userContentsDesc.m_Memory.m_pMemory;
      for ( j = (char *)validContentsDesc.m_Memory.m_pMemory - (char *)userContentsDesc.m_Memory.m_pMemory; ; v10 = j )
      {
        v15 = CUtlString::Get(this: (CUtlString *)((char *)m_pMemory + v10));
        v11 = CUtlString::Get(this: m_pMemory);
        if ( _V_stricmp(s1: v11, s2: v15) != 0 )
          break;
        ++v8;
        ++m_pMemory;
        if ( v8 >= m_Size )
          goto LABEL_28;
      }
      v2 = i;
    }
    i = ++v2;
  }
  while ( v2 < 0xB );
  m_pAsString = pDmElement->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  MdlWarning(fmt: "2100: Invalid \"contentsDescription\" \"%s\" on \"%s\"\n", v21, m_pAsString);
  if ( !bWarned )
  {
    bWarned = true;
    CUtlString::CUtlString(this: &sWarn);
    CUtlString::operator=(this: &sWarn, src: "notsolid");
    for ( k = 1; k < 11; ++k )
    {
      CUtlString::operator+=(this: &sWarn, rhs: ", ");
      CUtlString::operator+=(this: &sWarn, rhs: contentDescs[k].m_pszName);
    }
    v14 = CUtlString::Get(this: &sWarn);
    MdlWarning(fmt: "      Valid ones are: %s\n", v14);
    sWarn.m_Storage.m_nActualLength = 0;
    if ( sWarn.m_Storage.m_Memory.m_nGrowSize >= 0 && sWarn.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sWarn.m_Storage.m_Memory.m_pMemory);
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&validContentsDesc);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&userContentsDesc);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410A30
// Name: LoadDefineBoneList
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadDefineBoneList(CDmeDefineBoneList *pDmeDefineBoneList)
{
  CDmeDefineBoneList *v1; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // esi
  const char *v6; // eax
  s_importbone_t *v7; // esi
  const char *v8; // eax
  float v9; // xmm2_4
  float *v10; // ecx
  float v11; // xmm2_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  int m_Size; // eax
  int v16; // esi
  int v17; // ebx
  const char *Name; // eax
  ContentsName_t *v19; // esi
  int v20; // esi
  int v21; // eax
  const char *v22; // edi
  const char *v23; // edi
  int nDefineBoneCount; // [esp+Ch] [ebp-10h]
  ContentsName_t *s1; // [esp+10h] [ebp-Ch]
  int ni; // [esp+14h] [ebp-8h]
  int nContentsDescription; // [esp+18h] [ebp-4h] BYREF

  v1 = pDmeDefineBoneList;
  if ( pDmeDefineBoneList != nullptr )
  {
    v2 = 0;
    nDefineBoneCount = pDmeDefineBoneList->m_DefineBones.m_Storage.m_Size;
    ni = 0;
    if ( nDefineBoneCount > 0 )
    {
      while ( 1 )
      {
        v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v1->m_DefineBones.m_Storage.m_Memory.m_pMemory[v2]);
        v4 = v3;
        if ( v3 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
               a1: v3,
               a2: CDmeDefineBone::m_classType.u) != 0 )
        {
          if ( (unsigned int)g_numimportbones >= 0x400 )
          {
            v23 = *(const char **)(v4 + 20);
            if ( v23 == (const char *)-1 )
              v23 = pDeltaStateName;
            MdlError(fmt: "Too Many Define Bones while processing: \"%s\", Max: %d\n", v23, 1024);
          }
          v5 = g_numimportbones++;
          v6 = *(const char **)(v4 + 20);
          v7 = &g_importbone[v5];
          if ( v6 == (const char *)-1 )
            v6 = pDeltaStateName;
          V_strncpy(pDest: v7->name, pSrc: v6, maxLen: 128);
          v8 = *(const char **)(v4 + 68);
          if ( v8 == (const char *)-1 )
            v8 = pDeltaStateName;
          V_strncpy(pDest: v7->parent, pSrc: v8, maxLen: 128);
          AngleMatrix(angles: (const QAngle *)(v4 + 92), position: (const Vector *)(v4 + 76), matrix: &v7->rawLocal);
          v9 = *(float *)(v4 + 108);
          v10 = (float *)(v4 + 124);
          if ( v9 <= -0.0099999998
            || v9 >= 0.0099999998
            || (v11 = *(float *)(v4 + 112)) <= -0.0099999998
            || v11 >= 0.0099999998
            || (v12 = *(float *)(v4 + 116)) <= -0.0099999998
            || v12 >= 0.0099999998
            || *v10 <= -0.0099999998
            || *v10 >= 0.0099999998
            || (v13 = *(float *)(v4 + 128)) <= -0.0099999998
            || v13 >= 0.0099999998
            || (v14 = *(float *)(v4 + 132)) <= -0.0099999998
            || v14 >= 0.0099999998 )
          {
            v7->bPreAligned = true;
            AngleMatrix(
              angles: (const QAngle *)(v4 + 124),
              position: (const Vector *)(v4 + 108),
              matrix: &v7->srcRealign);
          }
          else
          {
            v7->bPreAligned = false;
            SetIdentityMatrix(matrix: &v7->srcRealign);
          }
          nContentsDescription = 1;
          if ( GetContentsDescription(&nContentsDescription, pDmElement: (CDmElement *)v4) != 0 )
            break;
        }
LABEL_42:
        ni = ++v2;
        if ( v2 >= nDefineBoneCount )
          return;
        v1 = pDmeDefineBoneList;
      }
      m_Size = s_JointContents.m_Size;
      v16 = 0;
      if ( s_JointContents.m_Size > 0 )
      {
        v17 = 0;
        while ( 1 )
        {
          s1 = &s_JointContents.m_Memory.m_pMemory[v17];
          Name = CDmElement::GetName(this: (CDmElement *)v4);
          if ( _V_stricmp(s1: s1->m_pJointName, s2: Name) == 0 )
            break;
          m_Size = s_JointContents.m_Size;
          ++v16;
          ++v17;
          if ( v16 >= s_JointContents.m_Size )
            goto LABEL_34;
        }
        v19 = &s_JointContents.m_Memory.m_pMemory[v16];
        if ( v19 != nullptr )
          goto LABEL_41;
        m_Size = s_JointContents.m_Size;
      }
LABEL_34:
      v20 = m_Size;
      if ( m_Size + 1 > s_JointContents.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ikcontextikrule_t,int>::Grow(
          this: (CUtlMemory<ikcontextikrule_t,int> *)&s_JointContents,
          num: m_Size - s_JointContents.m_Memory.m_nAllocationCount + 1);
        m_Size = s_JointContents.m_Size;
      }
      s_JointContents.m_Size = m_Size + 1;
      v21 = m_Size - v20;
      s_JointContents.m_pElements = s_JointContents.m_Memory.m_pMemory;
      if ( v21 > 0 )
        _V_memmove(
          dest: &s_JointContents.m_Memory.m_pMemory[v20 + 1],
          src: &s_JointContents.m_Memory.m_pMemory[v20],
          count: 132 * v21);
      v22 = *(const char **)(v4 + 20);
      v19 = &s_JointContents.m_Memory.m_pMemory[v20];
      if ( v22 == (const char *)-1 )
        v22 = pDeltaStateName;
      V_strncpy(pDest: v19->m_pJointName, pSrc: v22, maxLen: 128);
LABEL_41:
      v2 = ni;
      v19->m_nContents = nContentsDescription;
      goto LABEL_42;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410D00
// Name: LoadGlobalFlags
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadGlobalFlags(CDmElement *pDmeRoot@<esi>)
{
  CDmeBBox *Value; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v3; // eax
  int m_Storage; // eax
  int v5; // eax
  CDmAttribute *v6; // eax
  CDmaVar<Vector> *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  matrix3x4_t mDefRot; // [esp+4h] [ebp-38h] BYREF
  int nContentsDescription; // [esp+34h] [ebp-8h] BYREF
  char v15; // [esp+3Bh] [ebp-1h]

  AngleMatrix(angles: &g_defaultrotation, matrix: &mDefRot);
  Value = CDmElement::GetValueElement<CDmeBBox>(this: pDmeRoot, pAttributeName: "bbox");
  if ( Value != nullptr )
    ITransformAABB(
      transform: &mDefRot,
      vecMinsIn: &Value->m_vMinBounds.m_Storage,
      vecMaxsIn: &Value->m_vMaxBounds.m_Storage,
      vecMinsOut: bbox,
      vecMaxsOut: &maxs);
  if ( CDmElement::HasAttribute(this: pDmeRoot, pAttributeName: "opacity", type: AT_UNKNOWN) )
  {
    if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
    }
    Attribute = CDmElement::FindAttribute(this: pDmeRoot, pAttributeName: "opacity");
    if ( Attribute != nullptr )
      v3 = CDmAttribute::GetValue<int>(this: Attribute);
    else
      v3 = &`CDmElement::GetValue<int>'::`2'::defaultVal;
    m_Storage = v3->m_Storage;
    if ( m_Storage != 0 )
    {
      v5 = m_Storage - 1;
      if ( v5 != 0 )
      {
        if ( v5 == 1 && (gflags & 4) == 0 )
          gflags |= 8u;
      }
      else
      {
        gflags = gflags & 0xFFFFFFF3 | 4;
      }
    }
    else
    {
      gflags &= 0xFFFFFFF3;
    }
  }
  if ( CDmElement::HasAttribute(this: pDmeRoot, pAttributeName: "illuminationPosition", type: AT_VECTOR3) )
  {
    if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
    }
    v6 = CDmElement::FindAttribute(this: pDmeRoot, pAttributeName: "illuminationPosition");
    if ( v6 != nullptr )
      v7 = CDmAttribute::GetValue<Vector>(this: v6);
    else
      v7 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
    VectorIRotate(in1: &v7->m_Storage.x, in2: &mDefRot, out: &illumposition.x);
  }
  v15 = 0;
  v8 = CDmElement::FindAttribute(this: pDmeRoot, pAttributeName: "ambientBoost");
  if ( v8 != nullptr && CDmAttribute::GetValue<bool>(this: v8)->m_Storage )
    gflags |= 0x10000u;
  v15 = 0;
  v9 = CDmElement::FindAttribute(this: pDmeRoot, pAttributeName: "subdivisionSurface");
  if ( v9 != nullptr && CDmAttribute::GetValue<bool>(this: v9)->m_Storage )
    gflags |= 0x80000u;
  v15 = 0;
  v10 = CDmElement::FindAttribute(this: pDmeRoot, pAttributeName: "doNotCastShadows");
  if ( v10 != nullptr && CDmAttribute::GetValue<bool>(this: v10)->m_Storage )
    gflags |= 0x20000u;
  v15 = 0;
  v11 = CDmElement::FindAttribute(this: pDmeRoot, pAttributeName: "castTextureShadows");
  if ( v11 != nullptr && CDmAttribute::GetValue<bool>(this: v11)->m_Storage )
    gflags |= 0x20000u;
  v15 = 0;
  v12 = CDmElement::FindAttribute(this: pDmeRoot, pAttributeName: "noForcedFade");
  if ( v12 != nullptr && CDmAttribute::GetValue<bool>(this: v12)->m_Storage )
    gflags |= 0x800u;
  nContentsDescription = 1;
  if ( GetContentsDescription(&nContentsDescription, pDmElement: pDmeRoot) != 0 )
    s_nDefaultContents = nContentsDescription;
}

//------------------------------------------------------------------------------
// Address: 0x00411060
// Name: public: class CUtlVectorAuto<struct s_animation_t __near *> __near & CUtlVectorAuto<class CUtlVectorAuto<struct s_animation_t __near *>>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
CUtlVectorAuto<s_animation_t *> *__thiscall CUtlVectorAuto<CUtlVectorAuto<s_animation_t *>>::operator[](
        CUtlVectorAuto<CUtlVectorAuto<s_animation_t *> > *this,
        int i)
{
  if ( this->m_Size < i + 1 )
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
      (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this,
      elem: this->m_Size,
      num: i + 1 - this->m_Size);
  return &this->m_Memory.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00411090
// Name: CreateBindPoseSequence
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateBindPoseSequence(s_source_t *pMainSource@<eax>)
{
  s_sequence_t *v2; // edi
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *m_pMemory; // esi
  s_animation_t *pAnim; // [esp+4h] [ebp-4h] BYREF

  if ( FindSourceAnim(pSource: pMainSource, pAnimName: "BindPose") != nullptr )
  {
    v2 = ProcessCmdSequence(pSequenceName: "BindPose");
    pAnim = ProcessImpliedAnimation(psequence: v2, filename: pMainSource->filename);
    if ( v2->panim.m_Size < 1 )
      CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
        this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v2->panim,
        elem: v2->panim.m_Size,
        num: 1 - v2->panim.m_Size);
    m_pMemory = (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)v2->panim.m_Memory.m_pMemory;
    if ( m_pMemory->m_Size < 1 )
      CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
        this: m_pMemory,
        elem: m_pMemory->m_Size,
        num: 1 - m_pMemory->m_Size);
    *m_pMemory->m_Memory.m_pMemory = (CUtlSymbolTableLargeBaseTreeEntry_t *)pAnim;
    ProcessSequence(pseq: v2, numblends: 1, animations: &pAnim, isAppend: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411130
// Name: SetupStaticProp
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupStaticProp(s_source_t *pSource)
{
  s_sequence_t *v1; // edi
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *m_pMemory; // esi
  s_animation_t *pAnim; // [esp+8h] [ebp-4h] BYREF

  Cmd_StaticProp();
  v1 = ProcessCmdSequence(pSequenceName: "BindPose");
  pAnim = ProcessImpliedAnimation(psequence: v1, filename: pSource->filename);
  if ( v1->panim.m_Size < 1 )
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v1->panim,
      elem: v1->panim.m_Size,
      num: 1 - v1->panim.m_Size);
  m_pMemory = (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)v1->panim.m_Memory.m_pMemory;
  if ( m_pMemory->m_Size < 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: m_pMemory,
      elem: m_pMemory->m_Size,
      num: 1 - m_pMemory->m_Size);
  *m_pMemory->m_Memory.m_pMemory = (CUtlSymbolTableLargeBaseTreeEntry_t *)pAnim;
  ProcessSequence(pseq: v1, numblends: 1, animations: &pAnim, isAppend: false);
}

//------------------------------------------------------------------------------
// Address: 0x004112B0
// Name: DefineUniqueVertices
// Source: json
//------------------------------------------------------------------------------
char __usercall DefineUniqueVertices@<al>(CDmeVertexData *pBindState@<eax>)
{
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndexData; // edi
  const CUtlVector<int,CUtlMemory<int,int> > *v3; // eax
  int m_Size; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // ebx
  int v8; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // esi
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  int v17; // esi
  VertIndices_t *v18; // ecx
  int v19; // eax
  VertIndices_t *v20; // eax
  int v21; // eax
  int v22; // edi
  int *v23; // ecx
  int v24; // eax
  int *v25; // eax
  VertexLookup_t *v26; // edi
  int v27; // eax
  int v28; // esi
  int *m_pMemory; // ecx
  int v30; // eax
  int *v31; // eax
  CUtlHash<VertexLookup_t,bool (__cdecl*)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl*)(VertexLookup_t const &)> vertexLookupHash; // [esp+Ch] [ebp-7Ch] BYREF
  VertIndices_t vert; // [esp+30h] [ebp-58h]
  VertexLookup_t vertexLookup; // [esp+44h] [ebp-44h] BYREF
  unsigned int v36; // [esp+54h] [ebp-34h] BYREF
  unsigned int pBucket; // [esp+58h] [ebp-30h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *speedIndices; // [esp+5Ch] [ebp-2Ch]
  int nSpeedCount; // [esp+60h] [ebp-28h]
  int nBalanceCount; // [esp+64h] [ebp-24h]
  int nTexcoordCount; // [esp+68h] [ebp-20h]
  const CUtlVector<int,CUtlMemory<int,int> > *normalIndices; // [esp+6Ch] [ebp-1Ch]
  int nNormalCount; // [esp+70h] [ebp-18h]
  const CUtlVector<int,CUtlMemory<int,int> > *positionIndices; // [esp+74h] [ebp-14h]
  int nPositionCount; // [esp+78h] [ebp-10h]
  int pIndex; // [esp+7Ch] [ebp-Ch] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *balanceIndices; // [esp+80h] [ebp-8h]
  const CUtlVector<int,CUtlMemory<int,int> > *texcoordIndices; // [esp+84h] [ebp-4h]

  VertexIndexData = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                    this: pBindState,
                                                                    fieldId: FIELD_POSITION);
  positionIndices = VertexIndexData;
  normalIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                  this: pBindState,
                                                                  fieldId: FIELD_NORMAL);
  texcoordIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                    this: pBindState,
                                                                    fieldId: FIELD_TEXCOORD);
  balanceIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                   this: pBindState,
                                                                   fieldId: FIELD_BALANCE);
  v3 = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                       this: pBindState,
                                                       fieldId: FIELD_MORPH_SPEED);
  m_Size = normalIndices->m_Size;
  v5 = VertexIndexData->m_Size;
  v6 = texcoordIndices->m_Size;
  v7 = balanceIndices->m_Size;
  speedIndices = v3;
  v8 = v3->m_Size;
  nPositionCount = v5;
  nNormalCount = m_Size;
  nTexcoordCount = v6;
  nBalanceCount = v7;
  nSpeedCount = v8;
  if ( m_Size != 0 && v5 != m_Size || v6 != 0 && v5 != v6 || v7 != 0 && v5 != v7 || v8 != 0 && v5 != v8 )
    MdlError(fmt: "Encountered a mesh with invalid geometry (different number of indices for various data fields)\n");
  CUtlHash<VertexLookup_t,bool (__cdecl *)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl *)(VertexLookup_t const &)>::CUtlHash<VertexLookup_t,bool (__cdecl *)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl *)(VertexLookup_t const &)>(
    this: &vertexLookupHash,
    bucketCount: v5,
    growCount: 0,
    initCount: 0,
    compareFunc: (bool (__cdecl *)(const VertexLookup_t *, const VertexLookup_t *))VertexLookup_CompareFunc,
    keyFunc: VertexLookup_KeyFunc);
  v9 = 0;
  if ( nPositionCount > 0 )
  {
    while ( 1 )
    {
      v10 = g_numverts + VertexIndexData->m_Memory.m_pMemory[v9];
      vert.v = v10;
      v11 = m_Size <= 0 ? -1 : g_numnormals + normalIndices->m_Memory.m_pMemory[v9];
      vert.n = v11;
      v12 = nTexcoordCount <= 0 ? -1 : g_numtexcoords + texcoordIndices->m_Memory.m_pMemory[v9];
      vert.t = v12;
      v13 = nBalanceCount <= 0 ? 0 : balanceIndices->m_Memory.m_pMemory[v9];
      vert.balance = s_Balance.m_Size + v13;
      v14 = nSpeedCount <= 0 ? 0 : speedIndices->m_Memory.m_pMemory[v9];
      vertexLookup.t = v12;
      vertexLookup.v = v10;
      v15 = v14 + s_Speed.m_Size;
      vertexLookup.n = v11;
      vertexLookup.index = -1;
      pIndex = 0;
      if ( CUtlHash<VertexLookup_t,bool (__cdecl *)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl *)(VertexLookup_t const &)>::DoFind(
             this: &vertexLookupHash,
             src: &vertexLookup,
             &pBucket,
             &pIndex) != 0
        && (pIndex | (pBucket << 16)) != 0xFFFFFFFF )
      {
        v26 = &vertexLookupHash.m_Buckets.m_Memory.m_pMemory[(pIndex | (pBucket << 16)) >> 16].m_Memory.m_pMemory[(unsigned __int16)pIndex];
        v27 = s_UniqueVerticesMap.m_Size;
        v28 = s_UniqueVerticesMap.m_Size;
        if ( s_UniqueVerticesMap.m_Size + 1 > s_UniqueVerticesMap.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&s_UniqueVerticesMap,
            num: s_UniqueVerticesMap.m_Size - s_UniqueVerticesMap.m_Memory.m_nAllocationCount + 1);
          v27 = s_UniqueVerticesMap.m_Size;
        }
        m_pMemory = s_UniqueVerticesMap.m_Memory.m_pMemory;
        s_UniqueVerticesMap.m_Size = v27 + 1;
        v30 = v27 - v28;
        s_UniqueVerticesMap.m_pElements = s_UniqueVerticesMap.m_Memory.m_pMemory;
        if ( v30 > 0 )
        {
          _V_memmove(
            dest: &s_UniqueVerticesMap.m_Memory.m_pMemory[v28 + 1],
            src: &s_UniqueVerticesMap.m_Memory.m_pMemory[v28],
            count: 4 * v30);
          m_pMemory = s_UniqueVerticesMap.m_Memory.m_pMemory;
        }
        v31 = &m_pMemory[v28];
        if ( v31 != nullptr )
          *v31 = v26->index;
      }
      else
      {
        v16 = s_UniqueVertices.m_Size;
        v17 = s_UniqueVertices.m_Size;
        if ( s_UniqueVertices.m_Size + 1 > s_UniqueVertices.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CUtlVectorAuto<s_compressed_t>,int>::Grow(
            this: (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)&s_UniqueVertices,
            num: s_UniqueVertices.m_Size - s_UniqueVertices.m_Memory.m_nAllocationCount + 1);
          v16 = s_UniqueVertices.m_Size;
        }
        v18 = s_UniqueVertices.m_Memory.m_pMemory;
        s_UniqueVertices.m_Size = v16 + 1;
        v19 = v16 - v17;
        s_UniqueVertices.m_pElements = s_UniqueVertices.m_Memory.m_pMemory;
        if ( v19 > 0 )
        {
          _V_memmove(
            dest: &s_UniqueVertices.m_Memory.m_pMemory[v17 + 1],
            src: &s_UniqueVertices.m_Memory.m_pMemory[v17],
            count: 20 * v19);
          v18 = s_UniqueVertices.m_Memory.m_pMemory;
        }
        v20 = &v18[v17];
        *(_QWORD *)&v20->v = *(_QWORD *)&vert.v;
        *(_QWORD *)&v20->t = *(_QWORD *)&vert.t;
        v20->speed = v15;
        v21 = s_UniqueVerticesMap.m_Size;
        v22 = s_UniqueVerticesMap.m_Size;
        if ( s_UniqueVerticesMap.m_Size + 1 > s_UniqueVerticesMap.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&s_UniqueVerticesMap,
            num: s_UniqueVerticesMap.m_Size - s_UniqueVerticesMap.m_Memory.m_nAllocationCount + 1);
          v21 = s_UniqueVerticesMap.m_Size;
        }
        v23 = s_UniqueVerticesMap.m_Memory.m_pMemory;
        s_UniqueVerticesMap.m_Size = v21 + 1;
        v24 = v21 - v22;
        s_UniqueVerticesMap.m_pElements = s_UniqueVerticesMap.m_Memory.m_pMemory;
        if ( v24 > 0 )
        {
          _V_memmove(
            dest: &s_UniqueVerticesMap.m_Memory.m_pMemory[v22 + 1],
            src: &s_UniqueVerticesMap.m_Memory.m_pMemory[v22],
            count: 4 * v24);
          v23 = s_UniqueVerticesMap.m_Memory.m_pMemory;
        }
        v25 = &v23[v22];
        if ( v25 != nullptr )
          *v25 = v17;
        vertexLookup.index = v17;
        if ( CUtlHash<VertexLookup_t,bool (__cdecl *)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl *)(VertexLookup_t const &)>::DoFind(
               this: &vertexLookupHash,
               src: &vertexLookup,
               pBucket: &v36,
               &pIndex) == 0 )
          CUtlVector<VertexLookup_t,CUtlMemory<VertexLookup_t,int>>::InsertBefore(
            this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)&vertexLookupHash.m_Buckets.m_Memory.m_pMemory[v36],
            elem: vertexLookupHash.m_Buckets.m_Memory.m_pMemory[v36].m_Size,
            src: (const Quaternion *)&vertexLookup);
      }
      if ( ++v9 >= nPositionCount )
        break;
      VertexIndexData = positionIndices;
      m_Size = nNormalCount;
    }
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&vertexLookupHash);
  CUtlVector<CUtlVectorAuto<s_animation_t *>,CUtlMemory<CUtlVectorAuto<s_animation_t *>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&vertexLookupHash);
  if ( vertexLookupHash.m_Buckets.m_Memory.m_nGrowSize >= 0 && vertexLookupHash.m_Buckets.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertexLookupHash.m_Buckets.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00411620
// Name: LoadVertices
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __usercall LoadVertices@<al>(
        float *a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CDmeDag *pDmeDag,
        CDmeVertexData *pBindState,
        const matrix3x4_t *mat,
        float flScale,
        int nBoneAssign,
        int *pBoneRemap,
        s_source_t *pSource)
{
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // edi
  const CUtlVector<float,CUtlMemory<float,int> > *MorphSpeedData; // eax
  int m_Size; // edx
  int m_Storage; // edi
  int v14; // esi
  s_node_t *localBone; // edi
  const char *Name; // eax
  unsigned __int8 *v17; // eax
  IMemAlloc_vtbl *v18; // edx
  int v19; // eax
  int v20; // esi
  int v21; // eax
  int v22; // esi
  int v23; // edi
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v24; // edx
  Vector *m_pMemory; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  int v29; // esi
  int v30; // edi
  Vector *v31; // ecx
  int v32; // eax
  bool v33; // zf
  float *p_x; // eax
  int v35; // esi
  int v36; // esi
  int v37; // esi
  int y_low; // edi
  unsigned __int8 *JointWeightData; // esi
  const int *JointIndexData; // edi
  float *v41; // esi
  int *v42; // edi
  int v43; // esi
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v44; // eax
  unsigned __int8 *v45; // edi
  int v46; // eax
  int v47; // esi
  const char *v48; // eax
  int v49; // esi
  int v50; // edi
  int v51; // eax
  int v52; // esi
  int v53; // edi
  s_boneweight_t *v54; // ecx
  int v55; // eax
  int v56; // edx
  int v57; // eax
  unsigned __int8 *v58; // eax
  __int128 v59; // xmm4
  int v60; // eax
  int v61; // esi
  int v62; // edi
  Vector *v63; // ecx
  int v64; // eax
  bool v65; // dl
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v66; // ecx
  float *v67; // edi
  int v68; // eax
  int v69; // ecx
  int v70; // esi
  Vector2D *v71; // ecx
  int v72; // eax
  float y; // xmm0_4
  int v74; // eax
  int v75; // esi
  int v76; // edi
  int v77; // edx
  Vector2D *v78; // ecx
  int v79; // eax
  int v80; // eax
  int v81; // eax
  int v82; // eax
  int v83; // esi
  float *v84; // ecx
  int v85; // eax
  float *v86; // eax
  int v87; // eax
  int v89; // eax
  int v90; // esi
  float *v91; // ecx
  int v92; // eax
  float *v93; // eax
  _BYTE v96[12]; // [esp+38h] [ebp-1ACh] BYREF
  bool pbWarnmap[256]; // [esp+44h] [ebp-1A0h] BYREF
  __int128 normalMat_36; // [esp+168h] [ebp-7Ch] OVERLAPPED
  const CUtlVector<float,CUtlMemory<float,int> > *BalanceData; // [esp+184h] [ebp-60h]
  int v100; // [esp+188h] [ebp-5Ch]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v101; // [esp+18Ch] [ebp-58h]
  const CUtlVector<float,CUtlMemory<float,int> > *balances; // [esp+190h] [ebp-54h]
  float v103; // [esp+194h] [ebp-50h] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *positions; // [esp+198h] [ebp-4Ch]
  const CUtlVector<float,CUtlMemory<float,int> > *speeds; // [esp+19Ch] [ebp-48h]
  Vector vNormal; // [esp+1A0h] [ebp-44h]
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *TextureCoordData; // [esp+1ACh] [ebp-38h]
  int i; // [esp+1B0h] [ebp-34h]
  int j; // [esp+1B4h] [ebp-30h]
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *texcoords; // [esp+1B8h] [ebp-2Ch]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *normals; // [esp+1BCh] [ebp-28h]
  int nCount; // [esp+1C0h] [ebp-24h]
  int nBoneCount; // [esp+1C4h] [ebp-20h]
  int v114; // [esp+1C8h] [ebp-1Ch]
  float *v115; // [esp+1CCh] [ebp-18h]
  float v116; // [esp+1D0h] [ebp-14h] OVERLAPPED
  int v117; // [esp+1D4h] [ebp-10h]
  float *pWeightBuf; // [esp+1D8h] [ebp-Ch]
  int *pIndexBuf; // [esp+1DCh] [ebp-8h]
  int *retaddr; // [esp+1E4h] [ebp+0h]
  int nBoneAssigna; // [esp+1F8h] [ebp+14h]

  pWeightBuf = a1;
  pIndexBuf = retaddr;
  if ( nBoneAssign >= 0 )
  {
    nBoneAssigna = pBoneRemap[nBoneAssign];
    if ( nBoneAssigna < 0 )
      nBoneAssigna = s_nDefaultRootNode;
  }
  else
  {
    nBoneAssigna = s_nDefaultRootNode;
  }
  DefineUniqueVertices(pBindState);
  MatrixInverseTranspose(src: mat, dst: (matrix3x4_t *)&pbWarnmap[244]);
  PositionData = CDmeVertexDataBase::GetPositionData(this: pBindState);
  v101 = PositionData;
  i = (int)CDmeVertexDataBase::GetNormalData(this: pBindState);
  TextureCoordData = CDmeVertexDataBase::GetTextureCoordData(this: pBindState);
  BalanceData = CDmeVertexDataBase::GetBalanceData(this: pBindState);
  MorphSpeedData = CDmeVertexDataBase::GetMorphSpeedData(this: pBindState);
  m_Size = PositionData->m_Size;
  balances = MorphSpeedData;
  j = m_Size;
  if ( CDmeVertexDataBase::HasSkinningData(this: pBindState) )
    m_Storage = pBindState->m_nJointCount.m_Storage;
  else
    m_Storage = 0;
  v117 = m_Storage;
  if ( m_Storage > 3 )
    MdlError(fmt: "Too many bone influences per vertex!\n");
  if ( m_Storage <= 0 && nBoneAssigna == s_nDefaultRootNode && pDmeDag != nullptr )
  {
    v14 = 0;
    if ( pSource->numbones > 0 )
    {
      localBone = pSource->localBone;
      while ( 1 )
      {
        Name = CDmElement::GetName(this: pDmeDag);
        if ( _V_strcmp(s1: Name, s2: localBone->name) == 0 )
          break;
        ++v14;
        ++localBone;
        if ( v14 >= pSource->numbones )
          goto LABEL_19;
      }
      nBoneAssigna = v14;
LABEL_19:
      m_Storage = v117;
    }
  }
  _V_memset(dest: v96, fill: 0, count: 256);
  v17 = (unsigned __int8 *)((int (__thiscall *)(IMemAlloc *, int, int, int))_g_pMemAlloc->Alloc_2)(
                             a1: _g_pMemAlloc,
                             a2: 4 * m_Storage,
                             a3: a2,
                             a4: a3);
  v18 = _g_pMemAlloc->__vftable;
  v115 = (float *)v17;
  v116 = COERCE_FLOAT((int)v18->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Storage));
  vNormal.y = 0.0;
  if ( j > 0 )
  {
    vNormal.x = 0.0;
    v19 = g_numverts;
    while ( 1 )
    {
      v20 = v19 + 1;
      v114 = v19;
      v21 = g_vertex.m_Size;
      if ( g_vertex.m_Size >= v20 )
        goto LABEL_29;
      v22 = v20 - g_vertex.m_Size;
      v23 = g_vertex.m_Size;
      if ( v22 == 0 )
        goto LABEL_29;
      v24 = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)(v22 + g_vertex.m_Size);
      texcoords = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)(v22 + g_vertex.m_Size);
      if ( v22 + g_vertex.m_Size > g_vertex.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_vertex,
          num: g_vertex.m_Size + v22 - g_vertex.m_Memory.m_nAllocationCount);
        v21 = g_vertex.m_Size;
        v24 = texcoords;
      }
      m_pMemory = g_vertex.m_Memory.m_pMemory;
      g_vertex.m_Size = v22 + v21;
      v26 = v21 - v23;
      g_vertex.m_pElements = g_vertex.m_Memory.m_pMemory;
      if ( v26 > 0 && v22 > 0 )
        break;
LABEL_30:
      VectorTransform(
        in1: (const float *)((char *)&v101->m_Memory.m_pMemory->x + LODWORD(vNormal.x)),
        in2: mat,
        out: &m_pMemory[v114].x);
      v27 = g_vertex.m_Size;
      v114 = g_numverts;
      v28 = g_numverts + 1;
      if ( g_vertex.m_Size >= g_numverts + 1 )
        goto LABEL_37;
      v29 = v28 - g_vertex.m_Size;
      v30 = g_vertex.m_Size;
      if ( v28 == g_vertex.m_Size )
        goto LABEL_37;
      texcoords = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)(g_numverts + 1);
      if ( v28 > g_vertex.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_vertex,
          num: g_vertex.m_Size + v29 - g_vertex.m_Memory.m_nAllocationCount);
        v27 = g_vertex.m_Size;
      }
      v31 = g_vertex.m_Memory.m_pMemory;
      g_vertex.m_Size = v29 + v27;
      v32 = v27 - v30;
      g_vertex.m_pElements = g_vertex.m_Memory.m_pMemory;
      if ( v32 > 0 && v29 > 0 )
      {
        _V_memmove(
          dest: &g_vertex.m_Memory.m_pMemory[(_DWORD)texcoords],
          src: &g_vertex.m_Memory.m_pMemory[v30],
          count: 12 * v32);
LABEL_37:
        v31 = g_vertex.m_Memory.m_pMemory;
      }
      v33 = v117 == 0;
      p_x = &v31[v114].x;
      *p_x = *p_x * flScale;
      p_x[1] = p_x[1] * flScale;
      p_x[2] = p_x[2] * flScale;
      if ( !v33 )
      {
        y_low = LODWORD(vNormal.y);
        JointWeightData = (unsigned __int8 *)CDmeVertexDataBase::GetJointWeightData(
                                               this: pBindState,
                                               nDataIndex: SLODWORD(vNormal.y));
        JointIndexData = CDmeVertexDataBase::GetJointIndexData(this: pBindState, nDataIndex: y_low);
        v117 *= 4;
        v116 = *(float *)&JointWeightData;
        v41 = v115;
        memcpy(dst: (unsigned __int8 *)v115, src: (unsigned __int8 *)LODWORD(v116), count: v117);
        v114 = 4 * v117;
        nBoneCount = (int)JointIndexData;
        v42 = (int *)LODWORD(v116);
        memcpy(dst: (unsigned __int8 *)LODWORD(v116), src: (unsigned __int8 *)nBoneCount, count: 4 * v117);
        texcoords = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)SortAndBalanceBones(
                                                                              iCount: v117,
                                                                              iMaxCount: 3,
                                                                              bones: v42,
                                                                              weights: v41);
        v43 = g_numverts;
        if ( g_bone.m_Size < g_numverts + 1 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: g_numverts + 1 - g_bone.m_Size);
        v44 = texcoords;
        g_bone.m_Memory.m_pMemory[v43].numbones = (int)texcoords;
        vNormal.z = 0.0;
        if ( (int)v44 <= 0 )
          goto LABEL_70;
        v45 = (unsigned __int8 *)LODWORD(v116);
        v114 = LODWORD(v116);
        nCount = (int)v115 - LODWORD(v116);
        while ( 2 )
        {
          v46 = *(_DWORD *)v45;
          v47 = pBoneRemap[*(_DWORD *)v45];
          if ( v47 >= 0 )
          {
            v50 = g_numverts;
            if ( g_bone.m_Size < g_numverts + 1 )
              CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                this: &g_bone,
                elem: g_bone.m_Size,
                num: g_numverts + 1 - g_bone.m_Size);
            g_bone.m_Memory.m_pMemory[v50].bone[LODWORD(vNormal.z)] = v47;
          }
          else
          {
            if ( v46 < 256 && v96[v46] == 0 )
            {
              v117 = *(_DWORD *)v45;
              v48 = CDmElement::GetName(this: pDmeDag);
              MdlWarning(
                fmt: "DmeMesh[%s] Verts Assigned To DmeModel.jointList[%d] Which Isn't Mapped To The Dag Hierarchy\n",
                v48,
                v117);
              v96[*(_DWORD *)v45] = 1;
            }
            v49 = g_numverts;
            if ( g_bone.m_Size < g_numverts + 1 )
              CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                this: &g_bone,
                elem: g_bone.m_Size,
                num: g_numverts + 1 - g_bone.m_Size);
            g_bone.m_Memory.m_pMemory[v49].bone[LODWORD(vNormal.z)] = nBoneAssigna;
          }
          v51 = g_bone.m_Size;
          normals = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)g_numverts;
          if ( g_bone.m_Size < g_numverts + 1 && (v52 = g_numverts + 1 - g_bone.m_Size, v53 = g_bone.m_Size, v52 != 0) )
          {
            v100 = g_numverts + 1;
            if ( g_numverts + 1 > g_bone.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
                this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
                num: g_bone.m_Size + v52 - g_bone.m_Memory.m_nAllocationCount);
              v51 = g_bone.m_Size;
            }
            v54 = g_bone.m_Memory.m_pMemory;
            g_bone.m_Size = v52 + v51;
            v55 = v51 - v53;
            g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
            if ( v55 > 0 && v52 > 0 )
            {
              _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v100], src: &g_bone.m_Memory.m_pMemory[v53], count: 28 * v55);
              goto LABEL_68;
            }
          }
          else
          {
LABEL_68:
            v54 = g_bone.m_Memory.m_pMemory;
          }
          v56 = v114;
          v57 = LODWORD(vNormal.z) + 1;
          v54[(_DWORD)normals].weight[LODWORD(vNormal.z)] = *(float *)(nCount + v114);
          LODWORD(vNormal.z) = v57;
          v114 = v56 + 4;
          if ( v57 >= (int)texcoords )
            goto LABEL_70;
          v45 = (unsigned __int8 *)v114;
          continue;
        }
      }
      v35 = g_numverts;
      if ( g_bone.m_Size < g_numverts + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: g_numverts + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v35].numbones = 1;
      v36 = g_numverts;
      if ( g_bone.m_Size < g_numverts + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: g_numverts + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v36].bone[0] = nBoneAssigna;
      v37 = g_numverts;
      if ( g_bone.m_Size < g_numverts + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: g_numverts + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v37].weight[0] = 1.0;
LABEL_70:
      LODWORD(vNormal.x) += 12;
      v19 = ++g_numverts;
      ++LODWORD(vNormal.y);
      if ( SLODWORD(vNormal.y) >= j )
        goto LABEL_71;
    }
    _V_memmove(dest: &g_vertex.m_Memory.m_pMemory[(_DWORD)v24], src: &g_vertex.m_Memory.m_pMemory[v23], count: 12 * v26);
LABEL_29:
    m_pMemory = g_vertex.m_Memory.m_pMemory;
    goto LABEL_30;
  }
LABEL_71:
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v115);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v116));
  j = *(_DWORD *)(i + 12);
  v116 = 0.0;
  if ( j > 0 )
  {
    v115 = nullptr;
    do
    {
      v58 = (unsigned __int8 *)v115 + *(_DWORD *)i;
      v103 = *(float *)v58;
      positions = *((const CUtlVector<Vector,CUtlMemory<Vector,int> > **)v58 + 1);
      speeds = *((const CUtlVector<float,CUtlMemory<float,int> > **)v58 + 2);
      VectorNormalize(vec: (Vector *)&v103);
      v59 = 0;
      *(float *)&v59 = fsqrt(
                         (float)((float)(*(float *)&positions * *(float *)&positions)
                               + (float)(*(float *)&speeds * *(float *)&speeds))
                       + (float)(v103 * v103));
      normalMat_36 = v59;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v59 - 1.0) & _mask__AbsFloat_) > 0.01 )
        MdlWarning(
          fmt: "Non-Unit Length Normal [%d] < %8.6f %8.6f %8.6f >\n",
          v116,
          v103,
          *(float *)&positions,
          *(float *)&speeds);
      normals = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)g_numnormals;
      v60 = g_normal.m_Size;
      if ( g_normal.m_Size < g_numnormals + 1 )
      {
        v61 = g_numnormals + 1 - g_normal.m_Size;
        v62 = g_normal.m_Size;
        if ( v61 != 0 )
        {
          nCount = g_numnormals + 1;
          if ( g_numnormals + 1 > g_normal.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
              this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_normal,
              num: g_normal.m_Size + v61 - g_normal.m_Memory.m_nAllocationCount);
            v60 = g_normal.m_Size;
          }
          v63 = g_normal.m_Memory.m_pMemory;
          g_normal.m_Size = v61 + v60;
          v64 = v60 - v62;
          g_normal.m_pElements = g_normal.m_Memory.m_pMemory;
          if ( v64 <= 0 || v61 <= 0 )
            goto LABEL_83;
          _V_memmove(
            dest: &g_normal.m_Memory.m_pMemory[nCount],
            src: &g_normal.m_Memory.m_pMemory[v62],
            count: 12 * v64);
        }
      }
      v63 = g_normal.m_Memory.m_pMemory;
LABEL_83:
      VectorRotate(in1: &v103, in2: (const matrix3x4_t *)&pbWarnmap[244], out: &v63[(_DWORD)normals].x);
      ++g_numnormals;
      v115 += 3;
      ++LODWORD(v116);
    }
    while ( SLODWORD(v116) < j );
  }
  v65 = pBindState->m_bFlipVCoordinates.m_Storage;
  j = TextureCoordData->m_Size;
  HIBYTE(nBoneCount) = v65;
  v117 = 0;
  if ( j > 0 )
  {
    v66 = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)g_numtexcoords;
    while ( 1 )
    {
      v67 = &TextureCoordData->m_Memory.m_pMemory[v117].x;
      v68 = g_texcoord.m_Size;
      normals = v66;
      v69 = (int)&v66->m_Memory.m_pMemory + 1;
      if ( g_texcoord.m_Size >= v69 )
        goto LABEL_93;
      v70 = v69 - g_texcoord.m_Size;
      i = g_texcoord.m_Size;
      if ( v69 == g_texcoord.m_Size )
        goto LABEL_93;
      nCount = v69;
      if ( v69 > g_texcoord.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<mergelist_t,int>::Grow(
          this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
          num: g_texcoord.m_Size + v70 - g_texcoord.m_Memory.m_nAllocationCount);
        v68 = g_texcoord.m_Size;
      }
      v71 = g_texcoord.m_Memory.m_pMemory;
      g_texcoord.m_Size = v70 + v68;
      g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
      v72 = v68 - i;
      if ( v72 > 0 && v70 > 0 )
        break;
LABEL_94:
      v33 = HIBYTE(nBoneCount) == 0;
      v71[(_DWORD)normals].x = *v67;
      if ( v33 )
        y = TextureCoordData->m_Memory.m_pMemory[v117].y;
      else
        y = 1.0 - TextureCoordData->m_Memory.m_pMemory[v117].y;
      v74 = g_texcoord.m_Size;
      normals = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)g_numtexcoords;
      v116 = y;
      if ( g_texcoord.m_Size < g_numtexcoords + 1 )
      {
        v75 = g_numtexcoords + 1 - g_texcoord.m_Size;
        v76 = g_texcoord.m_Size;
        if ( v75 != 0 )
        {
          v77 = g_numtexcoords + 1;
          nCount = g_numtexcoords + 1;
          if ( g_numtexcoords + 1 > g_texcoord.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<mergelist_t,int>::Grow(
              this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
              num: g_texcoord.m_Size + v75 - g_texcoord.m_Memory.m_nAllocationCount);
            v74 = g_texcoord.m_Size;
            y = v116;
            v77 = nCount;
          }
          v78 = g_texcoord.m_Memory.m_pMemory;
          g_texcoord.m_Size = v75 + v74;
          v79 = v74 - v76;
          g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
          if ( v79 <= 0 || v75 <= 0 )
            goto LABEL_105;
          _V_memmove(
            dest: &g_texcoord.m_Memory.m_pMemory[v77],
            src: &g_texcoord.m_Memory.m_pMemory[v76],
            count: 8 * v79);
          y = v116;
        }
      }
      v78 = g_texcoord.m_Memory.m_pMemory;
LABEL_105:
      v80 = v117;
      v78[(_DWORD)normals].y = y;
      v66 = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)++g_numtexcoords;
      v117 = v80 + 1;
      if ( v80 + 1 >= j )
        goto LABEL_106;
    }
    _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[nCount], src: &g_texcoord.m_Memory.m_pMemory[i], count: 8 * v72);
LABEL_93:
    v71 = g_texcoord.m_Memory.m_pMemory;
    goto LABEL_94;
  }
LABEL_106:
  v81 = BalanceData->m_Size;
  if ( v81 != 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::InsertMultipleBefore(
      this: &s_Balance,
      elem: s_Balance.m_Size,
      num: v81,
      pToInsert: BalanceData->m_Memory.m_pMemory);
  }
  else
  {
    v82 = s_Balance.m_Size;
    v83 = s_Balance.m_Size;
    if ( s_Balance.m_Size + 1 > s_Balance.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&s_Balance,
        num: s_Balance.m_Size - s_Balance.m_Memory.m_nAllocationCount + 1);
      v82 = s_Balance.m_Size;
    }
    v84 = s_Balance.m_Memory.m_pMemory;
    s_Balance.m_Size = v82 + 1;
    v85 = v82 - v83;
    s_Balance.m_pElements = s_Balance.m_Memory.m_pMemory;
    if ( v85 > 0 )
    {
      _V_memmove(dest: &s_Balance.m_Memory.m_pMemory[v83 + 1], src: &s_Balance.m_Memory.m_pMemory[v83], count: 4 * v85);
      v84 = s_Balance.m_Memory.m_pMemory;
    }
    v86 = &v84[v83];
    if ( v86 != nullptr )
      *v86 = 1.0;
  }
  v87 = balances->m_Size;
  if ( v87 != 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::InsertMultipleBefore(
      this: &s_Speed,
      elem: s_Speed.m_Size,
      num: v87,
      pToInsert: balances->m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    v89 = s_Speed.m_Size;
    v90 = s_Speed.m_Size;
    if ( s_Speed.m_Size + 1 > s_Speed.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&s_Speed,
        num: s_Speed.m_Size - s_Speed.m_Memory.m_nAllocationCount + 1);
      v89 = s_Speed.m_Size;
    }
    v91 = s_Speed.m_Memory.m_pMemory;
    s_Speed.m_Size = v89 + 1;
    v92 = v89 - v90;
    s_Speed.m_pElements = s_Speed.m_Memory.m_pMemory;
    if ( v92 > 0 )
    {
      _V_memmove(dest: &s_Speed.m_Memory.m_pMemory[v90 + 1], src: &s_Speed.m_Memory.m_pMemory[v90], count: 4 * v92);
      v91 = s_Speed.m_Memory.m_pMemory;
    }
    v93 = &v91[v90];
    if ( v93 != nullptr )
      *v93 = 1.0;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004120A0
// Name: LoadMesh
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadMesh@<al>(
        int *a1@<edi>,
        int a2@<esi>,
        CDmeDag *pDmeDag,
        CDmeMesh *pMesh,
        CDmeVertexData *pBindState,
        const matrix3x4_t *mat,
        float flScale,
        int nBoneAssign,
        int *pBoneRemap,
        s_source_t *pSource)
{
  CDmeMesh *v10; // edi
  int v11; // esi
  CDmeVertexDeltaData *DeltaState; // eax
  CDmeFaceSet *FaceSet; // ebx
  CDmeMaterial *v14; // eax
  const char *MaterialName; // eax
  int v16; // esi
  char *v17; // eax
  int v19; // eax
  int v20; // eax
  int m_Size; // esi
  int v22; // edi
  int NextPolygonVertexCount; // eax
  int *m_pMemory; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // edx
  int v28; // ebx
  int *v29; // esi
  int *v30; // esi
  unsigned int v31; // ebx
  char pPathNoExt[260]; // [esp+1Ch] [ebp-244h] BYREF
  char pTextureName[260]; // [esp+120h] [ebp-140h] BYREF
  int quadIndices[4]; // [esp+224h] [ebp-3Ch] BYREF
  int *pIndices; // [esp+234h] [ebp-2Ch]
  int nVertexCount; // [esp+238h] [ebp-28h]
  int nFaceSetCount; // [esp+23Ch] [ebp-24h]
  int nIndexCount; // [esp+240h] [ebp-20h]
  int nStartingTexCoord; // [esp+244h] [ebp-1Ch]
  int nStartingNormal; // [esp+248h] [ebp-18h]
  int nStartingVertex; // [esp+24Ch] [ebp-14h]
  CDmeFaceSet *pFaceSet; // [esp+250h] [ebp-10h]
  int i; // [esp+254h] [ebp-Ch]
  bool bQuadSubd; // [esp+25Bh] [ebp-5h]
  int material; // [esp+25Ch] [ebp-4h]
  int savedregs; // [esp+260h] [ebp+0h] BYREF

  v10 = pMesh;
  CDmeMesh::CollapseRedundantNormals(this: pMesh, flNormalBlend: normal_blend);
  nStartingVertex = g_numverts;
  nStartingTexCoord = g_numtexcoords;
  nStartingNormal = g_numnormals;
  i = s_UniqueVertices.m_Size;
  pFaceSet = (CDmeFaceSet *)s_UniqueVerticesMap.m_Size;
  LoadVertices(
    a1: (float *)&savedregs,
    a2: (int)pMesh,
    a3: a2,
    pDmeDag,
    pBindState,
    mat,
    flScale,
    nBoneAssign,
    pBoneRemap,
    pSource);
  v11 = 0;
  material = CDmeMesh::DeltaStateCount(this: pMesh);
  if ( material <= 0 )
  {
LABEL_4:
    nFaceSetCount = CDmeMesh::FaceSetCount(this: pMesh);
    for ( i = 0; i < nFaceSetCount; ++i )
    {
      FaceSet = CDmeMesh::GetFaceSet(this: v10, faceSetIndex: i);
      pFaceSet = FaceSet;
      v14 = CDmeFaceSet::GetMaterial(this: FaceSet);
      MaterialName = CDmeMaterial::GetMaterialName(this: v14);
      V_strncpy(pDest: pTextureName, pSrc: MaterialName, maxLen: 260);
      v16 = 0;
      if ( numrep > 0 )
      {
        v17 = sourcetexture[0];
        material = (int)sourcetexture;
        while ( *v17 != 0 && _V_stricmp(s1: pTextureName, s2: v17) != 0 )
        {
          material += 260;
          if ( ++v16 >= numrep )
            goto LABEL_14;
          v17 = (char *)material;
        }
        V_strncpy(pDest: pTextureName, pSrc: defaulttexture[v16], maxLen: 260);
      }
LABEL_14:
      V_StripExtension(in: pTextureName, out: pPathNoExt, outSize: 260);
      if ( _V_stricmp(s1: pPathNoExt, s2: "null") != 0 )
      {
        v19 = LookupTexture(pTextureName, bRelativePath: true);
        pSource->texmap[v19] = v19;
        v20 = UseTextureAsMaterial(textureindex: v19);
        m_Size = FaceSet->m_indices.m_Storage.m_Size;
        v22 = 0;
        material = v20;
        bQuadSubd = (gflags & 0x80000) != 0;
        nIndexCount = m_Size;
        while ( v22 < m_Size )
        {
          NextPolygonVertexCount = CDmeFaceSet::GetNextPolygonVertexCount(this: FaceSet, nFirstIndex: v22);
          nVertexCount = NextPolygonVertexCount;
          if ( bQuadSubd && NextPolygonVertexCount == 4 )
          {
            m_pMemory = FaceSet->m_indices.m_Storage.m_Memory.m_pMemory;
            v25 = m_pMemory[v22 + 1];
            quadIndices[0] = m_pMemory[v22];
            v26 = m_pMemory[v22 + 2];
            quadIndices[1] = v25;
            v27 = m_pMemory[v22 + 3];
            quadIndices[2] = v26;
            quadIndices[3] = v27;
            ParseQuadFaceData(
              material,
              pIndices: quadIndices,
              pVertexData: pBindState,
              vi: nStartingVertex,
              ni: nStartingNormal,
              ti: nStartingTexCoord);
            v22 += 5;
          }
          else
          {
            if ( NextPolygonVertexCount >= 3 )
            {
              v28 = 3 * NextPolygonVertexCount - 6;
              v29 = (int *)((int (__thiscall *)(IMemAlloc *, int, int *))_g_pMemAlloc->Alloc_2)(
                             a1: _g_pMemAlloc,
                             a2: 4 * v28,
                             a3: a1);
              pIndices = v29;
              CDmeMesh::ComputeTriangulatedIndices(
                this: pMesh,
                pBaseState: pBindState,
                pFaceSet,
                nFirstIndex: v22,
                pIndices: v29,
                nOutCount: v28);
              if ( v28 > 0 )
              {
                v30 = v29 + 2;
                v31 = (v28 - 1) / 3u + 1;
                do
                {
                  ParseFaceData(
                    pVertexData: pBindState,
                    material,
                    v1: *(v30 - 2),
                    v2: *v30,
                    v3: *(v30 - 1),
                    vi: nStartingVertex,
                    ni: nStartingNormal,
                    ti: nStartingTexCoord);
                  v30 += 3;
                  --v31;
                }
                while ( v31 != 0 );
                v29 = pIndices;
              }
              a1 = v29;
              ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
              FaceSet = pFaceSet;
              m_Size = nIndexCount;
              NextPolygonVertexCount = nVertexCount;
            }
            v22 += NextPolygonVertexCount + 1;
          }
        }
        v10 = pMesh;
      }
    }
    return 1;
  }
  else
  {
    while ( 1 )
    {
      DeltaState = CDmeMesh::GetDeltaState(this: pMesh, nDeltaIndex: v11);
      if ( LoadDeltaState(
             pDeltaState: DeltaState,
             nStartingUniqueVertex: i,
             pBindState,
             mat,
             flScale,
             nStartingUniqueVertexMap: (int)pFaceSet) == 0 )
        return 0;
      if ( ++v11 >= material )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004123D0
// Name: LoadMeshes
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadMeshes(
        const LoadMeshInfo_t *info,
        CDmeDag *pDag,
        const matrix3x4_t *parentToBindPose,
        int nBoneAssign)
{
  int JointIndex; // eax
  CDmeTransform *Transform; // eax
  CDmeShape *Shape; // eax
  CDmeMesh *v8; // esi
  CDmeVertexData *BaseState; // eax
  int v11; // esi
  CDmeDag *Child; // eax
  matrix3x4_t dagToParent; // [esp+20h] [ebp-60h] BYREF
  matrix3x4_t dagToBindPose; // [esp+50h] [ebp-30h] BYREF
  int nCount; // [esp+88h] [ebp+8h]

  JointIndex = CDmeModel::GetJointIndex(this: info->m_pModel, pJoint: pDag);
  if ( JointIndex < 0 )
  {
    Transform = CDmeDag::GetTransform(this: pDag);
    CDmeTransform::GetTransform(this: Transform, transform: &dagToParent);
    ConcatTransforms(in1: parentToBindPose, in2: &dagToParent, out: &dagToBindPose);
  }
  else
  {
    nBoneAssign = JointIndex;
    ConcatTransforms(in1: parentToBindPose, in2: &info->m_pBindPose[JointIndex], out: &dagToBindPose);
  }
  Shape = CDmeDag::GetShape(this: pDag);
  v8 = (CDmeMesh *)Shape;
  if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
  {
    BaseState = CDmeMesh::FindBaseState(this: v8, pStateName: "bind");
    if ( BaseState == nullptr
      || LoadMesh(
           a1: (int *)pDag,
           a2: (int)v8,
           pDmeDag: pDag,
           pMesh: v8,
           pBindState: BaseState,
           mat: &dagToBindPose,
           flScale: info->m_flScale,
           nBoneAssign,
           pBoneRemap: info->m_pBoneRemap,
           pSource: info->m_pSource) == 0 )
    {
      return 0;
    }
  }
  v11 = 0;
  nCount = CDmElementFramework::GetPhase(this: pDag);
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      Child = CDmeDag::GetChild(this: pDag, i: v11);
      if ( !LoadMeshes(info, pDag: Child, parentToBindPose: &dagToBindPose, nBoneAssign) )
        break;
      if ( ++v11 >= nCount )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004124D0
// Name: LoadMeshes_0
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadMeshes_0(CDmeModel *pModel, __int64 flScale, s_source_t *pSource)
{
  CDmeModel *v3; // esi
  CDmeTransformList *BaseState; // eax
  CDmeTransformList *v5; // ebx
  int m_Size; // eax
  int v7; // edi
  int v8; // eax
  CDmeTransform *v9; // esi
  CDmeTransform *JointTransform; // eax
  int Phase; // edi
  int v12; // esi
  CDmeDag *Child; // eax
  LoadMeshInfo_t info; // [esp+Ch] [ebp-C040h] BYREF
  matrix3x4_t matrix; // [esp+C01Ch] [ebp-30h] BYREF
  matrix3x4_t *transform; // [esp+C058h] [ebp+Ch]
  int transform_4; // [esp+C05Ch] [ebp+10h]

  SetIdentityMatrix(&matrix);
  v3 = pModel;
  info.m_pModel = pModel;
  *(_QWORD *)&info.m_flScale = flScale;
  info.m_pSource = pSource;
  BaseState = CDmeModel::FindBaseState(this: pModel, pBaseStateName: "bind");
  v5 = BaseState;
  if ( BaseState != nullptr )
    m_Size = BaseState->m_Transforms.m_Storage.m_Size;
  else
    m_Size = CDmeModel::GetJointCount(this: pModel);
  v7 = 0;
  transform_4 = m_Size;
  if ( m_Size > 0 )
  {
    transform = info.m_pBindPose;
    do
    {
      if ( v5 != nullptr )
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v5->m_Transforms.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTransform *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTransform::m_classType.u) != 0 )
        {
          JointTransform = v9;
          v3 = pModel;
        }
        else
        {
          v3 = pModel;
          JointTransform = nullptr;
        }
      }
      else
      {
        JointTransform = CDmeModel::GetJointTransform(this: v3, nIndex: v7);
      }
      CDmeTransform::GetTransform(this: JointTransform, transform: transform++);
      ++v7;
    }
    while ( v7 < transform_4 );
  }
  Phase = CDmElementFramework::GetPhase(this: v3);
  v12 = 0;
  if ( Phase <= 0 )
    return 1;
  while ( 1 )
  {
    Child = CDmeDag::GetChild(this: pModel, i: v12);
    if ( LoadMeshes(&info, pDag: Child, parentToBindPose: &matrix, nBoneAssign: -1) == 0 )
      break;
    if ( ++v12 >= Phase )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004125F0
// Name: LoadModelAndSkeleton
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadModelAndSkeleton@<al>(
        s_source_t *pSource@<esi>,
        CDmeModel *pModel@<edi>,
        BoneTransformMap_t *boneMap,
        CDmeDag *pSkeleton,
        CDmeCombinationOperator *pCombinationOperator,
        bool bStaticProp)
{
  int Skeleton; // eax
  __int64 v8; // [esp+0h] [ebp-10h]

  CUtlVector<DeltaState_t,CUtlMemory<DeltaState_t,int>>::RemoveAll(this: &s_DeltaStates);
  s_Balance.m_Size = 0;
  s_Speed.m_Size = 0;
  s_UniqueVertices.m_Size = 0;
  s_UniqueVerticesMap.m_Size = 0;
  if ( pSkeleton == nullptr )
    return 0;
  Skeleton = LoadSkeleton(pRoot: pSkeleton, pModel, pNodes: pSource->localBone, boneMap);
  pSource->numbones = Skeleton;
  if ( Skeleton == 0 )
    return 0;
  g_numfaces = 0;
  if ( pModel != nullptr )
  {
    if ( pCombinationOperator != nullptr )
      CDmeCombinationOperator::GenerateWrinkleDeltas(
        this: pCombinationOperator,
        bOverwrite: false,
        bUseNormalForSign: false,
        flScale: 1.0);
    LoadBindPose(pModel, flScale: g_currentscale, boneMap, pSource);
    HIDWORD(v8) = boneMap->m_pnDmeModelToMdl;
    *(float *)&v8 = g_currentscale;
    if ( LoadMeshes_0(pModel, flScale: v8, pSource) != 0 )
    {
      UnifyIndices(psource: pSource);
      BuildVertexAnimations(pSource);
      BuildIndividualMeshes(pSource);
      goto LABEL_9;
    }
    return 0;
  }
LABEL_9:
  if ( pCombinationOperator != nullptr )
  {
    AddFlexKeys(pRoot: pModel, pDag: pModel, pComboOp: pCombinationOperator, pSource);
    AddCombination(pSource, pCombination: pCombinationOperator);
  }
  LoadAttachments(pRoot: pSkeleton, pDag: pSkeleton, pSource, bStaticProp);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412700
// Name: LoadAndCreateSequences
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoadAndCreateSequences(s_source_t *pMainSource, CDmeSequenceList *pSequenceList, bool *bSetUpAxis)
{
  CDmeSequenceList *v3; // ebx
  CDmeMultiSequence *v4; // esi
  unsigned __int8 *m_Size; // eax
  signed int v6; // edi
  int v7; // eax
  int v8; // ebx
  _BYTE *v9; // eax
  signed int v10; // esi
  CUtlSymbolTable::StringPool_t **v11; // esi
  CDmeSequence *v12; // esi
  const char *m_pAsString; // eax
  _DWORD *v14; // edi
  const char *v15; // eax
  int v16; // eax
  CDmeModel *v17; // esi
  bool v18; // zf
  CDmAttribute *Attribute; // eax
  DmElementHandle_t *v20; // eax
  const char *v21; // eax
  CDmeDag *v22; // ebx
  s_source_t *DmxSource; // esi
  int v24; // eax
  CDmeAnimationList *v25; // eax
  bool v26; // cc
  int v27; // ebx
  int v28; // eax
  int v29; // esi
  int v30; // ecx
  const char *v31; // ebx
  int v32; // eax
  int v33; // esi
  int v34; // ecx
  int v35; // eax
  int v36; // esi
  int v37; // ecx
  int v38; // eax
  int v39; // esi
  int v40; // ecx
  s_animation_t *v41; // esi
  int v42; // eax
  s_animation_t *v43; // ebx
  s_sequence_t *v44; // eax
  s_sequence_t *v45; // edi
  unsigned int v46; // eax
  s_sequence_t *v47; // edx
  s_sequence_t *v48; // esi
  char v49; // cl
  s_sequence_t *v50; // edi
  s_sequence_t *v51; // esi
  unsigned __int8 *v52; // edx
  unsigned __int8 *v53; // ecx
  int v54; // eax
  int v55; // esi
  int v56; // eax
  int v57; // esi
  CUtlSymbolTable::StringPool_t **v58; // esi
  s_sequence_t *v59; // esi
  CUtlVectorAuto<s_animation_t *> *v60; // esi
  int v61; // eax
  int v62; // edi
  int m_nAllocationCount; // ecx
  s_animation_t **v64; // ecx
  int v65; // eax
  s_animation_t **v66; // ecx
  CDmeSequence *v67; // esi
  CDmeMultiSequence *v68; // edi
  s_sequence_t *v69; // esi
  s_sequence_t *v70; // esi
  CDmeSequenceBase *v71; // edi
  int v72; // eax
  _DWORD *v73; // edi
  const char *v74; // ebx
  int v75; // ebx
  int v76; // edx
  unsigned __int8 *v77; // eax
  int v78; // edi
  CDmeSequenceBase *v79; // edi
  const char *v80; // eax
  const char *v81; // eax
  const char *v82; // eax
  const char *v83; // eax
  const char *v84; // eax
  int v85; // eax
  const char *v86; // edi
  int v87; // edi
  const char *v88; // eax
  const char *v90; // [esp+1Ch] [ebp-31ACh]
  const char *Name; // [esp+1Ch] [ebp-31ACh]
  CDmeSequence *v92; // [esp+1Ch] [ebp-31ACh]
  signed int v93; // [esp+20h] [ebp-31A8h]
  BoneTransformMap_t boneMap; // [esp+30h] [ebp-3198h] BYREF
  char out[260]; // [esp+3034h] [ebp-194h] BYREF
  __int64 v96; // [esp+3138h] [ebp-90h]
  int v97; // [esp+3140h] [ebp-88h]
  int v98; // [esp+3144h] [ebp-84h]
  CUtlString v99; // [esp+3148h] [ebp-80h] BYREF
  CUtlString v100; // [esp+3158h] [ebp-70h] BYREF
  CUtlString v101; // [esp+3168h] [ebp-60h] BYREF
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> v102; // [esp+3178h] [ebp-50h] BYREF
  int numblends; // [esp+3184h] [ebp-44h]
  CUtlSymbolTable::StringPool_t **v104; // [esp+3188h] [ebp-40h]
  CDmeSequenceBase *pDmeSequenceBase; // [esp+318Ch] [ebp-3Ch]
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> v106; // [esp+3190h] [ebp-38h] BYREF
  signed int v107; // [esp+319Ch] [ebp-2Ch]
  CUtlSymbolTable::StringPool_t **m_pMemory; // [esp+31A0h] [ebp-28h]
  CDmeSequence *pDmeSimpleSequence; // [esp+31A4h] [ebp-24h]
  signed int v110; // [esp+31A8h] [ebp-20h]
  const char *v111; // [esp+31ACh] [ebp-1Ch]
  int v112; // [esp+31B0h] [ebp-18h]
  unsigned __int8 *source; // [esp+31B4h] [ebp-14h]
  CDmeMultiSequence *pDmeMultiSequence; // [esp+31B8h] [ebp-10h]
  s_sequence_t *psequence; // [esp+31BCh] [ebp-Ch]
  char v116; // [esp+31C3h] [ebp-5h]
  CDmeModel *pModel; // [esp+31C4h] [ebp-4h]

  CreateBindPoseSequence(pMainSource);
  v3 = pSequenceList;
  LoadIkChainList(pDmeSequenceList: pSequenceList);
  v4 = nullptr;
  v112 = 0;
  if ( pSequenceList != nullptr )
    m_Size = (unsigned __int8 *)pSequenceList->m_Sequences.m_Storage.m_Size;
  else
    m_Size = nullptr;
  v6 = 0;
  source = m_Size;
  memset(&v106, 0, sizeof(v106));
  v107 = 0;
  m_pMemory = nullptr;
  pDmeMultiSequence = nullptr;
  if ( (int)m_Size > 0 )
  {
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v3->m_Sequences.m_Storage.m_Memory.m_pMemory[(_DWORD)v4]);
      v8 = v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeSequenceBase::m_classType.u) != 0 )
      {
        v9 = *(_BYTE **)(v8 + 20);
        if ( v9 != (_BYTE *)-1 && v9 != nullptr && *v9 != 0 )
        {
          v10 = v6;
          if ( v6 + 1 > v106.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &v106, num: v6 - v106.m_nAllocationCount + 1);
            v6 = v107;
          }
          v107 = ++v6;
          m_pMemory = v106.m_pMemory;
          if ( v6 - v10 - 1 > 0 )
            _V_memmove(dest: &v106.m_pMemory[v10 + 1], src: &v106.m_pMemory[v10], count: 4 * (v6 - v10 - 1));
          v11 = &v106.m_pMemory[v10];
          if ( v11 != nullptr )
            *v11 = (CUtlSymbolTable::StringPool_t *)v8;
        }
        else
        {
          Name = CDmElement::GetName(this: pSequenceList);
          MdlWarning(fmt: "1200: Ignoring Unnamed Sequence On %s[%d]\n", Name, v4);
        }
      }
      else
      {
        v90 = CDmElement::GetName(this: pSequenceList);
        MdlWarning(fmt: "1201: Empty DmeSequence %s[ %d ]\n", v90, v4);
      }
      v4 = (CDmeMultiSequence *)((char *)&pDmeMultiSequence->__vftable + 1);
      pDmeMultiSequence = v4;
      if ( (int)v4 >= (int)source )
        break;
      v3 = pSequenceList;
    }
  }
  qsort(base: v106.m_pMemory, num: v6, width: 4u, comp: CDmeSequenceBase::QSortFunction);
  v110 = 0;
  if ( v6 > 0 )
  {
    do
    {
      v12 = (CDmeSequence *)v106.m_pMemory[v110];
      m_pAsString = v12->m_Name.m_Storage.u.m_pAsString;
      memset(&v102, 0, sizeof(v102));
      numblends = 0;
      v104 = nullptr;
      pDmeSequenceBase = v12;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v111 = m_pAsString;
      V_StripExtension(in: m_pAsString, out, outSize: 260);
      psequence = ProcessCmdSequence(pSequenceName: out);
      if ( v12 != nullptr && v12->IsA(this: v12, a2: CDmeSequence::m_classType) )
      {
        v14 = &v12->__vftable;
        pDmeSimpleSequence = v12;
      }
      else
      {
        v14 = nullptr;
        pDmeSimpleSequence = nullptr;
      }
      if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmeMultiSequence::m_classType) )
        v12 = nullptr;
      pDmeMultiSequence = (CDmeMultiSequence *)v12;
      if ( v14 != nullptr )
      {
        v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                a1: g_pDataModel.u,
                a2: v14[71]);
        v17 = (CDmeModel *)v16;
        if ( v16 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v16 + 16))(
               a1: v16,
               a2: CDmeModel::m_classType.u) == 0 )
        {
          v17 = nullptr;
        }
        v18 = !*bSetUpAxis;
        pModel = v17;
        if ( !v18 && v17 != nullptr )
        {
          if ( (`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
            dword_660BA8 = 0;
            `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal = -1;
          }
          Attribute = CDmElement::FindAttribute(this: v17, pAttributeName: "upAxis");
          if ( Attribute != nullptr )
            v20 = CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
          else
            v20 = (DmElementHandle_t *)&`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
          v21 = (const char *)*v20;
          if ( v21 != (const char *)-1 && v21 != nullptr && StringAfterPrefix(str: v21, prefix: "Y") != nullptr )
          {
            v97 = 1070141403;
            v96 = 1070141403;
            *(_QWORD *)&g_defaultrotation.x = 1070141403;
            g_defaultrotation.z = 1.5707964;
          }
          *bSetUpAxis = false;
        }
        v22 = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                           a1: g_pDataModel.u,
                           a2: v14[71]);
        if ( v22 != nullptr )
        {
          DmxSource = AllocateDmxSource(pSourceName: out);
          source = (unsigned __int8 *)DmxSource;
          CUtlVector<DeltaState_t,CUtlMemory<DeltaState_t,int>>::RemoveAll(this: &s_DeltaStates);
          s_Balance.m_Size = 0;
          s_Speed.m_Size = 0;
          s_UniqueVertices.m_Size = 0;
          s_UniqueVerticesMap.m_Size = 0;
          v24 = LoadSkeleton(pRoot: v22, pModel, pNodes: DmxSource->localBone, &boneMap);
          DmxSource->numbones = v24;
          if ( v24 == 0 )
            goto LABEL_60;
          g_numfaces = 0;
          if ( pModel != nullptr )
          {
            LoadBindPose(pModel, flScale: g_currentscale, &boneMap, pSource: DmxSource);
            if ( LoadMeshes_0(
                   pModel,
                   flScale: __SPAIR64__((BoneTransformMap_t *)boneMap.m_pnDmeModelToMdl, LODWORD(g_currentscale)),
                   pSource: DmxSource) == 0 )
            {
LABEL_60:
              v31 = v22->m_Name.m_Storage.u.m_pAsString;
              if ( v31 == (const char *)-1 )
                v31 = pDeltaStateName;
              MdlWarning(fmt: "1206: Sequence %s: Ignoring Sequence, Couldn't Load Specified Skeleton: %s\n", v111, v31);
              goto LABEL_172;
            }
            UnifyIndices(psource: DmxSource);
            BuildVertexAnimations(pSource: DmxSource);
            BuildIndividualMeshes(pSource: DmxSource);
          }
          LoadAttachments(pRoot: v22, pDag: v22, pSource: DmxSource, bStaticProp: false);
          v25 = (CDmeAnimationList *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                       a1: g_pDataModel.u,
                                       a2: v14[74]);
          if ( v25 != nullptr )
          {
            LoadAnimations(pSource: DmxSource, pAnimationList: v25, flScale: g_currentscale, &boneMap);
            v26 = v14[103] <= 0;
            v116 = 0;
            pModel = nullptr;
            if ( !v26 )
            {
              do
              {
                v27 = 4 * (_DWORD)pModel;
                v28 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
                        a1: g_pDataModel.u,
                        a2: *(_DWORD *)(v14[100] + 4 * (_DWORD)pModel));
                v29 = v28;
                if ( v28 != 0
                  && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v28 + 16))(
                       a1: v28,
                       a2: CDmeAnimCmd::m_classType.u) != 0 )
                {
                  v30 = v29;
                }
                else
                {
                  v30 = 0;
                }
                if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v30 + 16))(
                       a1: v30,
                       a2: CDmeAnimCmdSubtract::m_classType.u) != 0 )
                  goto LABEL_80;
                v32 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
                        a1: g_pDataModel.u,
                        a2: *(_DWORD *)(v14[100] + v27));
                v33 = v32;
                if ( v32 != 0
                  && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v32 + 16))(
                       a1: v32,
                       a2: CDmeAnimCmd::m_classType.u) != 0 )
                {
                  v34 = v33;
                }
                else
                {
                  v34 = 0;
                }
                if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v34 + 16))(
                       a1: v34,
                       a2: CDmeAnimCmdPreSubtract::m_classType.u) != 0
                  || ((v35 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                               a1: g_pDataModel.u,
                               a2: *(_DWORD *)(v14[100] + v27)),
                       v36 = v35,
                       v35 == 0)
                   || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v35 + 16))(
                        a1: v35,
                        a2: CDmeAnimCmd::m_classType.u) == 0
                    ? (v37 = 0)
                    : (v37 = v36),
                      (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v37 + 16))(
                        a1: v37,
                        a2: CDmeAnimCmdLinearDelta::m_classType.u) != 0
                   || ((v38 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
                                a1: g_pDataModel.u,
                                a2: *(_DWORD *)(v14[100] + v27)),
                        v39 = v38,
                        v38 == 0)
                    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v38 + 16))(
                         a1: v38,
                         a2: CDmeAnimCmd::m_classType.u) == 0
                     ? (v40 = 0)
                     : (v40 = v39),
                       (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v40 + 16))(
                         a1: v40,
                         a2: CDmeAnimCmdSplineDelta::m_classType.u) != 0)) )
                {
LABEL_80:
                  psequence->flags |= 4u;
                  v116 = 1;
                }
                pModel = (CDmeModel *)((char *)pModel + 1);
              }
              while ( (int)pModel < v14[103] );
            }
            v41 = (s_animation_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 47928);
            memset(dst: (unsigned __int8 *)v41, value: 0, count: sizeof(s_animation_t));
            v42 = g_numani;
            g_panimation[g_numani] = v41;
            v41->index = v42;
            v43 = g_panimation[g_numani++];
            v44 = psequence;
            v43->isImplied = true;
            v43->startframe = 0;
            v43->endframe = 4999;
            *(_WORD *)v43->name = 64;
            v45 = v44;
            v46 = strlen(v44->name) + 1;
            v47 = v45;
            v48 = (s_sequence_t *)((char *)&v43->index + 3);
            do
            {
              v49 = v48->name[1];
              v48 = (s_sequence_t *)((char *)v48 + 1);
            }
            while ( v49 != 0 );
            v50 = v48;
            v51 = v47;
            v52 = source;
            qmemcpy(v50, v51, v46);
            strncpy(dest: (unsigned __int8 *)v43->filename, source: v52, count: 0x104u);
            v43->adjust = g_defaultadjust;
            v18 = v116 == 0;
            v43->scale = 1.0;
            if ( !v18 || !pDmeSimpleSequence->m_bDelta.m_Storage && !pDmeSimpleSequence->m_bPreDelta.m_Storage )
              v43->rotation = g_defaultrotation;
            v53 = source;
            v43->fps = 30.0;
            v43->motionrollback = g_flDefaultMotionRollback;
            v43->source = (s_source_t *)v53;
            v54 = *((_DWORD *)v53 + 50544);
            if ( v54 <= 0 )
            {
              V_strncpy(pDest: v43->animationname, pSrc: pDeltaStateName, maxLen: 260);
            }
            else
            {
              v55 = 40308 * v54 + *((_DWORD *)v53 + 50541) - 40308;
              V_strncpy(pDest: v43->animationname, pSrc: (const char *)v55, maxLen: 260);
              v56 = *(_DWORD *)(v55 + 264);
              if ( v43->startframe < v56 )
                v43->startframe = v56;
              v57 = *(_DWORD *)(v55 + 268);
              if ( v43->endframe > v57 )
                v43->endframe = v57;
            }
            v43->numframes = v43->endframe - v43->startframe + 1;
          }
          else
          {
            CreateAnimFromSkeleton(pSource: DmxSource, pSequenceName: out, &boneMap);
            v43 = ProcessImpliedAnimation(psequence, filename: DmxSource->filename);
          }
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &v102, num: 1);
          v58 = v102.m_pMemory;
          ++numblends;
          v104 = v102.m_pMemory;
          if ( numblends - 1 > 0 )
            _V_memmove(dest: v102.m_pMemory + 1, src: v102.m_pMemory, count: 4 * (numblends - 1));
          if ( v58 != nullptr )
            *v58 = (CUtlSymbolTable::StringPool_t *)v43;
          v59 = psequence;
          if ( psequence->panim.m_Size < 1 )
            CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
              this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&psequence->panim,
              elem: psequence->panim.m_Size,
              num: 1 - psequence->panim.m_Size);
          v60 = v59->panim.m_Memory.m_pMemory;
          v61 = v60->m_Size;
          if ( v61 < 1 )
          {
            v62 = 1 - v61;
            pModel = (CDmeModel *)v60->m_Size;
            if ( 1 != v61 )
            {
              m_nAllocationCount = v60->m_Memory.m_nAllocationCount;
              v98 = 1;
              if ( m_nAllocationCount < 1 )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(
                  this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)v60,
                  num: (int)pModel + v62 - m_nAllocationCount);
              v60->m_Size += v62;
              v64 = v60->m_Memory.m_pMemory;
              v65 = v60->m_Size - (_DWORD)pModel - v62;
              v60->m_pElements = v60->m_Memory.m_pMemory;
              if ( v65 > 0 && v62 > 0 )
                _V_memmove(dest: &v64[v98], src: &v64[(_DWORD)pModel], count: 4 * v65);
            }
          }
          v66 = v60->m_Memory.m_pMemory;
          v67 = pDmeSimpleSequence;
          v92 = pDmeSimpleSequence;
          *v66 = v43;
          LoadAnimationOptions(pDmeSimpleSequence: v92, pAnimation: v43);
          LoadAnimationCommands(pDmeSimpleSequence: v67, pAnimation: v43);
          LoadIkRuleList(pDmeSimpleSequence: v67, pAnimation: v43);
          AddBodyAttachments(pSource: (s_source_t *)source);
          if ( pDmeMultiSequence != nullptr )
          {
LABEL_110:
            v68 = pDmeMultiSequence;
            LoadSequenceList(animations: &v102, pDmeMultiSequence);
            v69 = psequence;
            LoadSequenceBlends(pDmeMultiSequence: v68, pSequence: psequence);
            LoadBlendRefCompCenter(pDmeMultiSequence: v68, pSequence: v69);
            v69->groupsize[0] = v68->m_nBlendWidth.m_Storage;
          }
          v70 = psequence;
          v71 = pDmeSequenceBase;
          LoadAnimationEventList(pDmeSequenceBase, pSequence: psequence);
          v72 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: v71->m_eActivity.m_Storage.m_Handle);
          v73 = (_DWORD *)v72;
          if ( v72 != 0 )
          {
            v74 = *(const char **)(v72 + 20);
            if ( v74 == (const char *)-1 )
            {
              v74 = pDeltaStateName;
LABEL_115:
              if ( _V_strlen(str: v74) > 0 )
              {
                V_strncpy(pDest: v70->activityname, pSrc: v74, maxLen: 128);
                v75 = 0;
                for ( v70->actweight = v73[17]; v75 < v73[22]; ++v75 )
                {
                  v76 = v70->numactivitymodifiers++;
                  v77 = *(unsigned __int8 **)(v73[19] + 4 * v75);
                  if ( v77 == (unsigned __int8 *)-1 )
                    v77 = (unsigned __int8 *)pDeltaStateName;
                  strncpy(dest: (unsigned __int8 *)v70->activitymodifier[v76].name, source: v77, count: 0x40u);
                  if ( v70->numactivitymodifiers == 128 )
                    break;
                }
                v78 = v73[22];
                if ( v78 > 128 )
                  MdlWarning(
                    fmt: "1210: Too many activity modifiers (%d) on DmeSequence %s, only using first %d\n",
                    v78,
                    v70->name,
                    128);
              }
            }
            else if ( v74 != nullptr )
            {
              goto LABEL_115;
            }
          }
          v79 = pDmeSequenceBase;
          if ( pDmeSequenceBase->m_bLoop.m_Storage )
            v70->flags |= 1u;
          if ( v79->m_bSnap.m_Storage )
            v70->flags |= 2u;
          if ( v79->m_bPost.m_Storage )
            v70->flags |= 0x10u;
          if ( v79->m_bHidden.m_Storage )
            v70->flags |= 0x400u;
          if ( v79->m_bDelta.m_Storage )
            v70->flags |= 0x14u;
          if ( v79->m_bWorldSpace.m_Storage )
            v70->flags |= 0x4010u;
          if ( v79->m_bPreDelta.m_Storage )
            v70->flags |= 4u;
          if ( v79->m_bAutoPlay.m_Storage )
            v70->flags |= 8u;
          if ( v79->m_bRealtime.m_Storage )
            v70->flags |= 0x100u;
          LoadLayerList(pDmeSequenceBase: v79, pSequence: v70);
          LoadIkLockList(pDmeSequenceBase: v79, pSequence: v70);
          v70->fadeintime = v79->m_flFadeIn.m_Storage;
          v70->fadeouttime = v79->m_flFadeOut.m_Storage;
          v80 = v79->m_sEntryNode.m_Storage.u.m_pAsString;
          if ( v80 == (const char *)-1 )
            v80 = pDeltaStateName;
          CUtlString::CUtlString(this: &v101, pString: v80);
          v81 = v79->m_sExitNode.m_Storage.u.m_pAsString;
          if ( v81 == (const char *)-1 )
            v81 = pDeltaStateName;
          CUtlString::CUtlString(this: &v100, pString: v81);
          if ( CUtlString::Length(this: &v101) != 0 )
          {
            if ( CUtlString::Length(this: &v100) != 0 )
            {
              v82 = CUtlString::operator char const *(this: &v101);
              v70->entrynode = LookupXNode(name: v82);
              v83 = CUtlString::operator char const *(this: &v100);
              v70->exitnode = LookupXNode(name: v83);
              if ( v79->m_bReverseNodeTransition.m_Storage )
                v70->nodeflags |= 1u;
            }
            else
            {
              v84 = CUtlString::operator char const *(this: &v101);
              v85 = LookupXNode(name: v84);
              v70->exitnode = v85;
              v70->entrynode = v85;
            }
          }
          if ( numblends <= 0 )
          {
            MdlWarning(fmt: "1207: DmeSequence %s: No animations created or referenced, ignoring\n", v111);
          }
          else
          {
            ProcessSequence(pseq: v70, numblends, animations: (s_animation_t **)v102.m_pMemory, isAppend: false);
            ++v112;
          }
          v86 = v79->m_sKeyValues.m_Storage.u.m_pAsString;
          if ( v86 == (const char *)-1 )
            v86 = pDeltaStateName;
          CUtlString::CUtlString(this: &v99, pString: v86);
          v87 = CUtlString::Length(this: &v99);
          if ( v87 > 0 )
          {
            v88 = CUtlString::operator char const *(this: &v99);
            CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
              this: &v70->KeyValue,
              elem: v70->KeyValue.m_Size,
              num: v87,
              pToInsert: v88);
          }
          v99.m_Storage.m_nActualLength = 0;
          if ( v99.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v99.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v99.m_Storage.m_Memory.m_pMemory);
              v99.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v99.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v100.m_Storage.m_nActualLength = 0;
          if ( v100.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v100.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v100.m_Storage.m_Memory.m_pMemory);
              v100.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v100.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v101.m_Storage.m_nActualLength = 0;
          if ( v101.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v101.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v101.m_Storage.m_Memory.m_pMemory);
              v101.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v101.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          if ( v102.m_nGrowSize >= 0 && v102.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v102.m_pMemory);
          goto LABEL_172;
        }
        MdlWarning(fmt: "1205: Ignoring Sequence %s, No Skeleton Specified\n", v111);
      }
      else
      {
        if ( v12 != nullptr )
          goto LABEL_110;
        v93 = v110;
        v15 = CDmElement::GetName(this: pSequenceList);
        MdlWarning(fmt: "1209: Invalid DmeSequence %s[ %d ], not Simple or Multi\n", v15, v93);
      }
LABEL_172:
      ++v110;
    }
    while ( v110 < v107 );
  }
  if ( v106.m_nGrowSize >= 0 && v106.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v106.m_pMemory);
  return v112;
}

//------------------------------------------------------------------------------
// Address: 0x00413390
// Name: LoadLODs
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadLODs(s_source_t **ppRootLODSource, bool *bSetUpAxis, bool bStaticProp)
{
  CDmeLODList *pLodList; // ecx
  CDmeLODList *v4; // edi
  signed int m_Size; // esi
  void *v6; // esp
  signed int v7; // ebx
  int v8; // eax
  int v9; // esi
  CDmElement *v10; // eax
  CDmElement *v11; // edi
  CDmeModel *Value; // eax
  const char *ValueString; // eax
  const char *m_pAsString; // eax
  signed int v15; // eax
  CDmElement *v16; // ebx
  char v17; // al
  const char *v18; // eax
  const char *v19; // eax
  s_source_t *DmxSource; // esi
  int v21; // eax
  CDmeModel *v22; // edi
  CDmeDag *v23; // eax
  CDmeModel *v24; // eax
  int v25; // eax
  char v26; // cl
  LodScriptData_t *v27; // eax
  int m_pNext; // xmm0_4
  bool v29; // cl
  CLodScriptReplacement_t *v30; // edi
  const char *v32; // ebx
  const char *v33; // ebx
  const char *v34; // ebx
  const char *v35; // ebx
  const char *v36; // ebx
  const char *v37; // ebx
  const char *v38; // ebx
  int v39; // [esp+0h] [ebp-3138h] BYREF
  BoneTransformMap_t boneMap; // [esp+Ch] [ebp-312Ch] BYREF
  char out[260]; // [esp+3010h] [ebp-128h] BYREF
  __int64 v42; // [esp+3114h] [ebp-24h]
  int v43; // [esp+311Ch] [ebp-1Ch]
  signed int i; // [esp+3120h] [ebp-18h]
  CDmElement *v45; // [esp+3124h] [ebp-14h]
  CDmeCombinationOperator *pCombinationOperator; // [esp+3128h] [ebp-10h]
  void *base; // [esp+312Ch] [ebp-Ch]
  signed int v48; // [esp+3130h] [ebp-8h]
  bool v49; // [esp+3135h] [ebp-3h]
  char v50; // [esp+3136h] [ebp-2h]
  bool v51; // [esp+3137h] [ebp-1h]

  v4 = pLodList;
  *ppRootLODSource = nullptr;
  m_Size = pLodList->m_LODs.m_Storage.m_Size;
  v48 = m_Size;
  if ( m_Size != 0 )
  {
    v6 = alloca(4 * m_Size);
    v7 = 0;
    base = &v39;
    if ( m_Size > 0 )
    {
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v4->m_LODs.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = v8;
        if ( v8 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeLOD::m_classType.u) == 0 )
        {
          v9 = 0;
        }
        *((_DWORD *)base + v7++) = v9;
      }
      while ( v7 < v48 );
      m_Size = v48;
    }
    qsort(base, num: m_Size, width: 4u, comp: LodDistanceCompare);
    v10 = v4->GetRootLOD(this: v4);
    v11 = v10;
    v45 = v10;
    if ( v10 != nullptr && *bSetUpAxis )
    {
      Value = CDmElement::GetValueElement<CDmeModel>(this: v10, pAttributeName: "model");
      if ( Value != nullptr )
      {
        ValueString = CDmElement::GetValueString(this: Value, pAttributeName: "upAxis");
        if ( ValueString != nullptr && StringAfterPrefix(str: ValueString, prefix: "Y") != nullptr )
        {
          v43 = 1070141403;
          v42 = 1070141403;
          *(_QWORD *)&g_defaultrotation.x = 1070141403;
          g_defaultrotation.z = 1.5707964;
        }
        *bSetUpAxis = false;
      }
    }
    m_pAsString = v11->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    V_StripExtension(in: m_pAsString, out, outSize: 260);
    v15 = 0;
    for ( i = 0; v15 < m_Size; i = v15 )
    {
      v16 = *((CDmElement **)base + v15);
      v17 = *((_BYTE *)&v16[1] + 60);
      v50 = v17;
      if ( v17 != 0 )
      {
        if ( (gflags & 0x40) != 0 )
        {
          v32 = v16->m_Name.m_Storage.u.m_pAsString;
          if ( v32 == (const char *)-1 )
            v32 = pDeltaStateName;
          MdlError(fmt: "Invalid LOD: \"%s\": Multiple Shadow LODs Defined\n", v32);
        }
        gflags |= 0x40u;
      }
      else if ( *(float *)&v16[1].m_ref.m_attributes.m_pNext < 0.0 )
      {
        v33 = v16->m_Name.m_Storage.u.m_pAsString;
        if ( v33 == (const char *)-1 )
          v33 = pDeltaStateName;
        MdlError(fmt: "Invalid LOD: \"%s\": Negative switch value\n", v33);
      }
      v51 = v16 == v11;
      if ( !g_bStripLods || v17 != 0 || v16 == v11 )
      {
        v49 = *(_DWORD *)&v16[1].m_Id.m_Value[4] != -1;
        if ( !v49 && v16[1].m_Name.m_Storage.u.m_Id == -1 )
        {
          v34 = v16->m_Name.m_Storage.u.m_pAsString;
          if ( v34 == (const char *)-1 )
            v34 = pDeltaStateName;
          MdlError(fmt: "Invalid LOD: \"%s\": No Model or Skeleton defined\n", v34);
        }
        if ( g_ScriptLODs.m_Size == 8 )
        {
          v35 = v16->m_Name.m_Storage.u.m_pAsString;
          if ( v35 == (const char *)-1 )
            v35 = pDeltaStateName;
          MdlError(fmt: "Too many LODs (MAX_NUM_LODS==%d) while loading LOD: \"%s\"\n", 8, v35);
        }
        if ( g_numsources >= 1524 )
        {
          v36 = v16->m_Name.m_Storage.u.m_pAsString;
          if ( v36 == (const char *)-1 )
            v36 = pDeltaStateName;
          MdlError(
            fmt: "Too many source models/animations (MAXSTUDIOSEQUENCES==%d) while loading LOD: \"%s\"\n",
            1524,
            v36);
        }
        v19 = (const char *)v16[1].__vftable;
        if ( v19 == (const char *)-1 )
          v19 = pDeltaStateName;
        DmxSource = AllocateDmxSource(pSourceName: v19);
        if ( DmxSource == nullptr )
        {
          v37 = v16->m_Name.m_Storage.u.m_pAsString;
          if ( v37 == (const char *)-1 )
            v37 = pDeltaStateName;
          MdlError(fmt: "Couldn't allocate new source while loading LOD: \"%s\"\n", v37);
        }
        if ( v51 )
        {
          *ppRootLODSource = DmxSource;
          DmxSource->isActiveModel = true;
        }
        if ( v49 )
        {
          v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: *((_DWORD *)&v16[1].m_ref + 1));
          if ( v21 != 0 )
            pCombinationOperator = (CDmeCombinationOperator *)(v21 - 4);
          else
            pCombinationOperator = nullptr;
          v22 = (CDmeModel *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                               a1: g_pDataModel.u,
                               a2: *(_DWORD *)&v16[1].m_Id.m_Value[4]);
          v23 = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: v16[1].m_Name.m_Storage.u);
          if ( LoadModelAndSkeleton(
                 pSource: DmxSource,
                 pModel: v22,
                 &boneMap,
                 pSkeleton: v23,
                 pCombinationOperator,
                 bStaticProp) == 0 )
          {
            v38 = v16->m_Name.m_Storage.u.m_pAsString;
            if ( v38 == (const char *)-1 )
              v38 = pDeltaStateName;
            MdlError(fmt: "Couldn't load skeleton and model while loading LOD: \"%s\"\n", v38);
          }
          v24 = (CDmeModel *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                               a1: g_pDataModel.u,
                               a2: *(_DWORD *)&v16[1].m_Id.m_Value[4]);
          LoadQcModelElements(pSource: DmxSource, pModel: g_pCurrentModel, pDmeModel: v24);
          v11 = v45;
        }
        if ( !v51 )
        {
          v25 = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::InsertBefore(
                  this: &g_ScriptLODs,
                  elem: g_ScriptLODs.m_Size);
          v26 = v50;
          v27 = &g_ScriptLODs.m_Memory.m_pMemory[v25];
          if ( v50 != 0 )
            m_pNext = -1082130432;
          else
            m_pNext = (int)v16[1].m_ref.m_attributes.m_pNext;
          LODWORD(v27->switchValue) = m_pNext;
          v29 = v26 == 0 && LOBYTE(v16[1].m_Type.u.m_Id) == 0;
          v27->m_bFacialAnimation = v29;
          v27->m_bStrippedFromModel = false;
          v30 = &v27->modelReplacements.m_Memory.m_pMemory[CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::InsertBefore(
                                                             this: &v27->modelReplacements,
                                                             elem: v27->modelReplacements.m_Size)];
          CLodScriptReplacement_t::SetSrcName(this: v30, pSrcName: out);
          CLodScriptReplacement_t::SetDstName(this: v30, pDstName: DmxSource->filename);
          v30->m_pSource = DmxSource;
          v11 = v45;
        }
        m_Size = v48;
      }
      else if ( !g_quiet )
      {
        if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: *(_DWORD *)&v16[1].m_Id.m_Value[4]) != 0 )
        {
          v18 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                                   a1: g_pDataModel.u,
                                   a2: *(_DWORD *)&v16[1].m_Id.m_Value[4])
                               + 20);
          if ( v18 == (const char *)-1 )
            v18 = pDeltaStateName;
        }
        else
        {
          v18 = "<none>";
        }
        _Msg(a1: "Stripped lod \"%s\" @ %.1f\n", v18, *(double *)&v16[1].m_ref.m_attributes.m_pNext);
      }
      v15 = i + 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00413860
// Name: bool LoadCollisionModel(class CDmeCollisionModel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadCollisionModel(CDmeCollisionModel *pCollisionInfo, bool bStaticProp)
{
  const char *m_pAsString; // eax
  s_source_t *DmxSource; // esi
  CDmeDag *Value; // ebx
  const char *v6; // eax
  const char *v7; // edi
  CDmeModel *v8; // edi
  const char *v9; // edx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // edi
  const char *v13; // esi
  const char *v14; // edi
  const char *v15; // ebx
  const char *v16; // ecx
  const char *v17; // eax
  const char *ValueString; // eax
  BoneTransformMap_t boneMap; // [esp+4h] [ebp-300Ch] BYREF
  int v20; // [esp+3008h] [ebp-8h]
  const char *v21; // [esp+300Ch] [ebp-4h]

  if ( pCollisionInfo == nullptr )
    return 0;
  if ( g_numsources >= 1524 )
    MdlError(fmt: "Load_Source - overflowed g_numsources loading LODs.");
  m_pAsString = pCollisionInfo->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  DmxSource = AllocateDmxSource(pSourceName: m_pAsString);
  if ( DmxSource == nullptr )
    return 0;
  v20 = g_numtextures;
  v21 = (const char *)g_nummaterials;
  Value = CDmElement::GetValueElement<CDmeDag>(this: pCollisionInfo, pAttributeName: "skeleton");
  if ( Value == nullptr )
  {
    v6 = pCollisionInfo->m_Name.m_Storage.u.m_pAsString;
    if ( v6 == (const char *)-1 )
      v6 = pDeltaStateName;
    v7 = pCollisionInfo->m_Type.u.m_pAsString;
    if ( v7 == (const char *)-1 )
      v7 = pDeltaStateName;
    MdlError(fmt: "%s(%s): No \"skeleton\" defined\n", v7, v6);
  }
  v8 = CDmElement::GetValueElement<CDmeModel>(this: pCollisionInfo, pAttributeName: "model");
  if ( v8 == nullptr )
  {
    v9 = pDeltaStateName;
    if ( pCollisionInfo->m_Name.m_Storage.u.CDmElement::m_Id != -1 )
      v9 = pCollisionInfo->m_Name.m_Storage.u.m_pAsString;
    v10 = pCollisionInfo->m_Type.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = pDeltaStateName;
    MdlError(fmt: "%s(%s): No \"model\" defined\n", v10, v9);
  }
  if ( LoadModelAndSkeleton(
         pSource: DmxSource,
         pModel: v8,
         &boneMap,
         pSkeleton: Value,
         pCombinationOperator: nullptr,
         bStaticProp) == 0 )
  {
    v11 = v8->m_Name.m_Storage.u.m_pAsString;
    v21 = pDeltaStateName;
    if ( v11 != (const char *)-1 )
      v21 = v11;
    v12 = v8->m_Type.u.m_pAsString;
    v13 = pDeltaStateName;
    if ( v12 != (const char *)-1 )
      v13 = v12;
    v14 = pDeltaStateName;
    if ( Value->m_Name.m_Storage.u.CDmElement::m_Id != -1 )
      v14 = Value->m_Name.m_Storage.u.m_pAsString;
    v15 = Value->m_Type.u.m_pAsString;
    if ( v15 == (const char *)-1 )
      v15 = pDeltaStateName;
    v16 = pDeltaStateName;
    if ( pCollisionInfo->m_Name.m_Storage.u.CDmElement::m_Id != -1 )
      v16 = pCollisionInfo->m_Name.m_Storage.u.m_pAsString;
    v17 = pCollisionInfo->m_Type.u.m_pAsString;
    if ( v17 == (const char *)-1 )
      v17 = pDeltaStateName;
    MdlError(fmt: "%s(%s): Couldn't Load Skeleton: %s(%s) & Model: %s(%s)\n", v17, v16, v15, v14, v13, v21);
  }
  if ( v21 != nullptr && v20 != 0 && (v20 != g_numtextures || v21 != (const char *)g_nummaterials) )
  {
    g_numtextures = v20;
    g_nummaterials = (int)v21;
    DmxSource->texmap[0] = 0;
  }
  if ( DoCollisionModel(a1: (int)Value, pSource: DmxSource, pInfo: pCollisionInfo, bStaticProp) == 0 )
    return 0;
  ValueString = CDmElement::GetValueString(this: pCollisionInfo, pAttributeName: "surfaceProperty");
  if ( ValueString != nullptr && *ValueString != 0 )
    SetDefaultSurfaceProp(pSurfaceProperty: ValueString);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00413A60
// Name: int Load_DMX(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_DMX(s_source_t *pSource)
{
  CDmeDag *Value; // ebx
  CDmeModel *v3; // edi
  CDmeCombinationOperator *v4; // eax
  CDmeAnimationList *v5; // eax
  BoneTransformMap_t boneMap; // [esp+2Ch] [ebp-310Ch] BYREF
  char pFullPath[260]; // [esp+3030h] [ebp-108h] BYREF
  CDmElement *pRoot; // [esp+3134h] [ebp-4h] BYREF

  if ( !GetGlobalFilePath(pSrc: pSource->filename, pFullPath, nMaxLen: 260)
    || (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, _DWORD, _DWORD, CDmElement **, _DWORD, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
         a1: g_pDataModel.u,
         a2: pFullPath,
         a3: 0,
         a4: 0,
         a5: &pRoot,
         a6: 0,
         a7: 0) == -1 )
  {
    return 0;
  }
  if ( !g_quiet )
    _Msg(a1: "DMX Model %s\n", pFullPath);
  LoadModelInfo(pRoot, pFullPath);
  LoadConstraints(pDmeRoot: pRoot);
  Value = CDmElement::GetValueElement<CDmeDag>(this: pRoot, pAttributeName: "skeleton");
  v3 = CDmElement::GetValueElement<CDmeModel>(this: pRoot, pAttributeName: "model");
  v4 = CDmElement::GetValueElement<CDmeCombinationOperator>(this: pRoot, pAttributeName: "combinationOperator");
  if ( LoadModelAndSkeleton(
         pSource,
         pModel: v3,
         &boneMap,
         pSkeleton: Value,
         pCombinationOperator: v4,
         bStaticProp: false) != 0 )
  {
    LoadQcModelElements(pSource, pModel: g_pCurrentModel, pDmeModel: v3);
    v5 = CDmElement::GetValueElement<CDmeAnimationList>(this: pRoot, pAttributeName: "animationList");
    if ( v5 != nullptr )
      LoadAnimations(pSource, pAnimationList: v5, flScale: g_currentscale, &boneMap);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
      a1: g_pDataModel.u,
      a2: pRoot->m_fileId);
    return 1;
  }
  else
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
      a1: g_pDataModel.u,
      a2: pRoot->m_fileId);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413BC0
// Name: LoadBodyGroupList
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadBodyGroupList(
        s_source_t **ppMainSource,
        CDmeBodyGroupList *pBodyGroupList,
        CDmeEyeballGlobals *pDmeEyeballGlobals,
        bool bStaticProp,
        bool *bSetUpAxis)
{
  CDmeBodyGroupList *v5; // esi
  int m_Size; // ebx
  int v7; // eax
  int v9; // eax
  int v10; // esi
  char v11; // al
  int v12; // ebx
  s_bodypart_t *v13; // ebx
  int v14; // edx
  int v15; // eax
  int v16; // esi
  s_bodypart_t *v17; // edi
  int v18; // esi
  int v19; // esi
  const char *v20; // eax
  s_model_t *v21; // edi
  int v22; // eax
  int v23; // ecx
  int v24; // esi
  s_model_t **m_pMemory; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  int v29; // esi
  int v30; // ebx
  int m_nAllocationCount; // edx
  s_bodypart_t *v32; // ecx
  s_model_t **v33; // edx
  int v34; // eax
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  CDmeLODList *v38; // esi
  CDmeLODList *v39; // ebx
  const char *m_pAsString; // eax
  const char **p_source; // esi
  float m_Storage; // xmm0_4
  const char *v43; // eax
  long double v44; // [esp+0h] [ebp-68h]
  matrix3x4_t matrix; // [esp+Ch] [ebp-5Ch] BYREF
  int nDmeBodyGroupCount; // [esp+3Ch] [ebp-2Ch]
  int nDmeBodyPartCount; // [esp+40h] [ebp-28h]
  const CDmeLODList *pMainBodyPart; // [esp+44h] [ebp-24h]
  int v49; // [esp+48h] [ebp-20h]
  int nummodels; // [esp+4Ch] [ebp-1Ch]
  int i; // [esp+50h] [ebp-18h]
  int nModel; // [esp+54h] [ebp-14h]
  int j; // [esp+58h] [ebp-10h]
  int v54; // [esp+5Ch] [ebp-Ch]
  s_bodypart_t *pBodyPart; // [esp+60h] [ebp-8h]
  bool bLoadEyeballGlobals; // [esp+67h] [ebp-1h]

  v5 = pBodyGroupList;
  *ppMainSource = nullptr;
  m_Size = pBodyGroupList->m_BodyGroups.m_Storage.m_Size;
  nDmeBodyGroupCount = m_Size;
  if ( m_Size == 0 )
    return 1;
  bLoadEyeballGlobals = true;
  pMainBodyPart = CDmeBodyGroupList::GetMainBodyPart(this: pBodyGroupList);
  v7 = 0;
  i = 0;
  if ( m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v5->m_BodyGroups.m_Storage.m_Memory.m_pMemory[v7]);
    v10 = v9;
    if ( v9 == 0
      || (v11 = (*(int (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                  a1: v9,
                  a2: CDmeBodyGroup::m_classType.u),
          v54 = v10,
          v11 == 0) )
    {
      v54 = 0;
    }
    v12 = g_numbodyparts;
    if ( g_bodypart.m_Size < g_numbodyparts + 1 )
      CUtlVector<s_bodypart_t,CUtlMemory<s_bodypart_t,int>>::InsertMultipleBefore(
        this: &g_bodypart,
        elem: g_bodypart.m_Size,
        num: g_numbodyparts + 1 - g_bodypart.m_Size);
    v13 = &g_bodypart.m_Memory.m_pMemory[v12];
    v13->nummodels = 0;
    v14 = g_numbodyparts;
    pBodyPart = v13;
    if ( g_numbodyparts != 0 )
    {
      v15 = g_bodypart.m_Size;
      v16 = g_numbodyparts - 1;
      if ( g_bodypart.m_Size < g_numbodyparts )
      {
        CUtlVector<s_bodypart_t,CUtlMemory<s_bodypart_t,int>>::InsertMultipleBefore(
          this: &g_bodypart,
          elem: g_bodypart.m_Size,
          num: g_numbodyparts - g_bodypart.m_Size);
        v15 = g_bodypart.m_Size;
        v14 = g_numbodyparts;
      }
      v17 = &g_bodypart.m_Memory.m_pMemory[v16];
      v18 = v14 - 1;
      if ( v15 < v14 )
        CUtlVector<s_bodypart_t,CUtlMemory<s_bodypart_t,int>>::InsertMultipleBefore(
          this: &g_bodypart,
          elem: v15,
          num: v14 - v15);
      v13->base = v17->base * g_bodypart.m_Memory.m_pMemory[v18].nummodels;
    }
    else
    {
      v13->base = 1;
    }
    v19 = v54;
    v20 = *(const char **)(v54 + 20);
    if ( v20 == (const char *)-1 )
      v20 = pDeltaStateName;
    V_strncpy(pDest: v13->name, pSrc: v20, maxLen: 128);
    ++g_numbodyparts;
    nDmeBodyPartCount = *(_DWORD *)(v19 + 80);
    j = 0;
    if ( nDmeBodyPartCount > 0 )
    {
      while ( 1 )
      {
        v21 = (s_model_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 36096);
        memset(dst: (unsigned __int8 *)v21, value: 0, count: sizeof(s_model_t));
        v22 = g_model.m_Size;
        nModel = g_nummodels;
        v23 = g_nummodels + 1;
        g_nummodels = v23;
        if ( g_model.m_Size >= v23 )
          goto LABEL_29;
        v24 = v23 - g_model.m_Size;
        nummodels = g_model.m_Size;
        if ( v23 == g_model.m_Size )
          goto LABEL_29;
        v49 = v23;
        if ( v23 > g_model.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
            num: g_model.m_Size + v24 - g_model.m_Memory.m_nAllocationCount);
          v22 = g_model.m_Size;
        }
        m_pMemory = g_model.m_Memory.m_pMemory;
        g_model.m_Size = v24 + v22;
        v26 = v22 - nummodels;
        g_model.m_pElements = g_model.m_Memory.m_pMemory;
        if ( v26 > 0 && v24 > 0 )
          break;
LABEL_30:
        m_pMemory[nModel] = v21;
        nummodels = v13->nummodels;
        v27 = nummodels + 1;
        v13->nummodels = nummodels + 1;
        v28 = v13->pmodel.m_Size;
        if ( v28 < v27 )
        {
          v29 = v27 - v28;
          v30 = v13->pmodel.m_Size;
          if ( v27 != v28 )
          {
            m_nAllocationCount = pBodyPart->pmodel.m_Memory.m_nAllocationCount;
            v49 = v30 + v29;
            if ( v30 + v29 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pBodyPart->pmodel,
                num: v29 + v30 - m_nAllocationCount);
            v32 = pBodyPart;
            pBodyPart->pmodel.m_Size += v29;
            v33 = v32->pmodel.m_Memory.m_pMemory;
            v34 = v32->pmodel.m_Size - v30 - v29;
            v32->pmodel.m_pElements = v33;
            if ( v34 <= 0 || v29 <= 0 )
            {
              v13 = v32;
              goto LABEL_38;
            }
            _V_memmove(dest: &v33[v49], src: &v33[v30], count: 4 * v34);
          }
          v13 = pBodyPart;
        }
LABEL_38:
        v35 = v54;
        v13->pmodel.m_Memory.m_pMemory[nummodels] = v21;
        v36 = j;
        v21->scale = 1.0;
        v37 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                a1: g_pDataModel.u,
                a2: *(_DWORD *)(*(_DWORD *)(v35 + 68) + 4 * v36));
        v38 = (CDmeLODList *)v37;
        if ( v37 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v37 + 16))(
               a1: v37,
               a2: CDmeBodyPart::m_classType.u) != 0 )
        {
          if ( v38->IsA(this: v38, a2: CDmeLODList::m_classType) )
          {
            v39 = v38;
            goto LABEL_42;
          }
        }
        else
        {
          v38 = nullptr;
        }
        v39 = nullptr;
LABEL_42:
        if ( v38->LODCount(this: v38) != 0 && v39 != nullptr )
        {
          m_pAsString = v39->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = pDeltaStateName;
          V_strncpy(pDest: v21->name, pSrc: m_pAsString, maxLen: 128);
          p_source = (const char **)&v21->source;
          g_pCurrentModel = v21;
          if ( LoadLODs(ppRootLODSource: &v21->source, bSetUpAxis, bStaticProp) == 0 )
          {
            v43 = *(const char **)(v54 + 20);
            if ( v43 == (const char *)-1 )
              v43 = pDeltaStateName;
            MdlError(fmt: "Bad LOD On BodyGroup \"%s\".bodyPartList[%d]\n", v43, j);
          }
          g_pCurrentModel = nullptr;
          if ( bLoadEyeballGlobals )
          {
            bLoadEyeballGlobals = false;
            if ( pDmeEyeballGlobals != nullptr )
            {
              m_Storage = pDmeEyeballGlobals->m_flMaxEyeDeflection.m_Storage;
              __libm_sse2_cos(x: v44);
              g_flMaxEyeDeflection = m_Storage * 0.017453292;
              AngleMatrix(angles: &g_defaultrotation, &matrix);
              VectorIRotate(in1: &pDmeEyeballGlobals->m_vEyePosition.m_Storage.x, in2: &matrix, out: &eyeposition.x);
            }
          }
          LoadEyeballs_0(ps_model_t: v21, pDmeLODList: v39);
          if ( *p_source != nullptr )
            V_strncpy(pDest: v21->filename, pSrc: *p_source, maxLen: 260);
          PostProcessSource(pSource: (s_source_t *)*p_source, imodel: nModel);
          if ( pMainBodyPart == v39 )
            *ppMainSource = (s_source_t *)*p_source;
        }
        else
        {
          v21->source = AllocateDmxSource(pSourceName: "blank");
          V_strncpy(pDest: v21->name, pSrc: "blank", maxLen: 128);
        }
        if ( ++j >= nDmeBodyPartCount )
          goto LABEL_59;
        v13 = pBodyPart;
      }
      _V_memmove(dest: &g_model.m_Memory.m_pMemory[v49], src: &g_model.m_Memory.m_pMemory[nummodels], count: 4 * v26);
LABEL_29:
      m_pMemory = g_model.m_Memory.m_pMemory;
      goto LABEL_30;
    }
LABEL_59:
    v7 = i + 1;
    i = v7;
    if ( v7 >= nDmeBodyGroupCount )
      return 1;
    v5 = pBodyGroupList;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414080
// Name: bool LoadPreprocessedFile(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadPreprocessedFile(const char *pFileName)
{
  const char *ValueString; // eax
  const char *v2; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *p_bSetUpAxis; // eax
  bool m_Storage; // bl
  CDmeBodyGroupList *Value; // esi
  bool v7; // di
  CDmeEyeballGlobals *v8; // eax
  CDmeCollisionModel *v9; // eax
  const char *v10; // eax
  const CDmeMaterialGroupList *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  s_source_t *DmxSource; // edi
  CDmeBoneMaskList *v15; // eax
  CDmePoseParameterList *v16; // eax
  CDmeAnimBlockSize *v17; // eax
  CDmeSequenceList *v18; // eax
  CDmeIncludeModelList *v20; // eax
  CDmeDefineBoneList *v21; // eax
  const CDmeHitboxSetList *v22; // eax
  const CDmeBoneFlexDriverList *v23; // eax
  const char *v24; // edi
  bool v25; // [esp-10h] [ebp-128h]
  char pFullPath[260]; // [esp+4h] [ebp-114h] BYREF
  BOOL bStaticProp; // [esp+108h] [ebp-10h]
  s_source_t *pMainSource; // [esp+10Ch] [ebp-Ch] BYREF
  bool bSetUpAxis; // [esp+113h] [ebp-5h] BYREF
  CDmElement *pRoot; // [esp+114h] [ebp-4h] BYREF

  if ( !GetGlobalFilePath(pSrc: pFileName, pFullPath, nMaxLen: 260) )
    MdlError(fmt: "Invalid MPP Filename: %s\n", pFileName);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, _DWORD, _DWORD, CDmElement **, _DWORD, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
         a1: g_pDataModel.u,
         a2: pFullPath,
         a3: 0,
         a4: 0,
         a5: &pRoot,
         a6: 0,
         a7: 0) == -1 )
    MdlError(fmt: "0001: Couldn't Load MPP File: %s\n", pFullPath);
  if ( !g_quiet )
    _Msg(a1: "Loaded Preprocessed File %s\n", pFullPath);
  ValueString = CDmElement::GetValueString(this: pRoot, pAttributeName: "mdlPath");
  v2 = ValueString;
  if ( ValueString != nullptr && *ValueString != 0 )
  {
    if ( V_strnicmp(s1: ValueString, s2: "models", n: 6) == 0 && v2[6] == 47 || v2[7] == 92 )
      v2 += 7;
    ProcessModelName(pModelName: v2);
  }
  bSetUpAxis = false;
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "skinnedLODs");
  if ( Attribute != nullptr )
    p_bSetUpAxis = CDmAttribute::GetValue<bool>(this: Attribute);
  else
    p_bSetUpAxis = (CDmaVar<bool> *)&bSetUpAxis;
  g_bSkinnedLODs = p_bSetUpAxis->m_Storage;
  LoadModelInfo(pRoot, pFullPath);
  m_Storage = CDmElement::GetValue<bool>(this: pRoot, pAttributeName: "staticProp")->m_Storage;
  LOBYTE(bStaticProp) = m_Storage;
  bSetUpAxis = true;
  pMainSource = nullptr;
  Value = CDmElement::GetValueElement<CDmeBodyGroupList>(this: pRoot, pAttributeName: "bodyGroupList");
  if ( Value == nullptr )
  {
    if ( m_Storage )
      MdlError(fmt: "0002: Static prop specified but no body groups present\n");
    DmxSource = AllocateDmxSource(pSourceName: "anim");
    goto LABEL_27;
  }
  v7 = bStaticProp;
  v25 = bStaticProp;
  v8 = CDmElement::GetValueElement<CDmeEyeballGlobals>(this: pRoot, pAttributeName: "eyeballGlobals");
  if ( LoadBodyGroupList(
         ppMainSource: &pMainSource,
         pBodyGroupList: Value,
         pDmeEyeballGlobals: v8,
         bStaticProp: v25,
         &bSetUpAxis) == 0
    || (v9 = CDmElement::GetValueElement<CDmeCollisionModel>(this: pRoot, pAttributeName: "collisionModel")) != nullptr
    && LoadCollisionModel(pCollisionInfo: v9, bStaticProp: v7) == 0 )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
      a1: g_pDataModel.u,
      a2: pRoot->m_fileId);
    return 0;
  }
  v10 = CDmElement::GetValueString(this: pRoot, pAttributeName: "collisionText");
  LoadCollisionText(pszKeyValues: v10);
  v11 = CDmElement::GetValueElement<CDmeMaterialGroupList>(this: pRoot, pAttributeName: "materialGroupList");
  LoadMaterialGroups(pDmeMaterialGroupList: v11);
  v12 = CDmElement::FindAttribute(this: Value, pAttributeName: "boneMergeList");
  LoadBoneMergeList(pDmeBoneMergeListAttr: v12);
  v13 = CDmElement::FindAttribute(this: Value, pAttributeName: "boneKeepList");
  LoadBoneMergeList(pDmeBoneMergeListAttr: v13);
  if ( !m_Storage )
  {
    DmxSource = pMainSource;
LABEL_27:
    v15 = CDmElement::GetValueElement<CDmeBoneMaskList>(this: pRoot, pAttributeName: "boneMaskList");
    LoadBoneMaskList(pDmeBoneMaskList: v15);
    v16 = CDmElement::GetValueElement<CDmePoseParameterList>(this: pRoot, pAttributeName: "poseParameterList");
    LoadPoseParameterList(pDmePoseParameterList: v16);
    v17 = CDmElement::GetValueElement<CDmeAnimBlockSize>(this: pRoot, pAttributeName: "animBlockSize");
    LoadAnimBlockSize(pDmeAnimBlockSize: v17);
    v18 = CDmElement::GetValueElement<CDmeSequenceList>(this: pRoot, pAttributeName: "sequenceList");
    if ( LoadAndCreateSequences(pMainSource: DmxSource, pSequenceList: v18, &bSetUpAxis) == 0 && Value == nullptr )
      MdlError(fmt: "0003: MPP has no body groups and no animations\n");
    v20 = CDmElement::GetValueElement<CDmeIncludeModelList>(this: pRoot, pAttributeName: "includeModelList");
    LoadIncludeModelList(pIncludeModelList: v20);
    v21 = CDmElement::GetValueElement<CDmeDefineBoneList>(this: pRoot, pAttributeName: "defineBoneList");
    LoadDefineBoneList(pDmeDefineBoneList: v21);
    v22 = CDmElement::GetValueElement<CDmeHitboxSetList>(this: pRoot, pAttributeName: "hitboxSetList");
    LoadHitboxSetList(pDmeHitboxSetList: v22);
    v23 = CDmElement::GetValueElement<CDmeBoneFlexDriverList>(this: pRoot, pAttributeName: "boneFlexDriverList");
    LoadBoneFlexDriverList(pDmeBoneFlexDriverList: v23);
    v24 = CDmElement::GetValueString(this: pRoot, pAttributeName: "keyValues");
    LoadKeyValues(pszKeyValues: v24);
    LoadGlobalFlags(pDmeRoot: pRoot);
    goto dmxSuccess;
  }
  SetupStaticProp(pSource: pMainSource);
dmxSuccess:
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
    a1: g_pDataModel.u,
    a2: pRoot->m_fileId);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00452800
// Name: public: CDmrElementArray<class CDmElement>::CDmrElementArray<class CDmElement>(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CDmrElementArray<CDmElement> *__thiscall CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
        CDmrElementArray<CDmElement> *this,
        CDmAttribute *pAttribute)
{
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>((CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)this);
  if ( pAttribute != nullptr && (pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    this->m_pAttribute = pAttribute;
    this->m_pStorage = (DmElementArray_t *)pAttribute->m_pData;
    return this;
  }
  else
  {
    this->m_pAttribute = nullptr;
    this->m_pStorage = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481770
// Name: public: class CDmElement __near * CDmAttribute::GetValueElement<class CDmElement>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAttribute::GetValueElement<CDmElement>(CDmAttribute *this)
{
  CDmaVar<enum DmElementHandle_t> *v1; // eax
  int v2; // eax
  int v3; // esi

  if ( (this->m_nFlags & 0x1F) == 1
    && (v1 = CDmAttribute::GetValue<enum DmElementHandle_t>(this),
        v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v1->m_Storage.m_Handle),
        v3 = v2,
        v2 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A4E0
// Name: public: int CDmaElementArrayConstBase<class CDmElement,class CDmaArrayBase<enum DmElementHandle_t,class CDmaDataExternal<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>>>::Find(class CDmElement const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::Find(
        CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > > *this,
        const CDmElement *pValue)
{
  if ( pValue == nullptr )
    return -1;
  pValue = (const CDmElement *)pValue->m_ref.m_hElement;
  return CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
           this,
           value: (const DmElementHandle_t *)&pValue);
}

//------------------------------------------------------------------------------
// Address: 0x0048D4F0
// Name: private: bool CDmAttribute::IsTypeConvertable<class Quaternion>(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmAttribute::IsTypeConvertable<Quaternion>(CDmAttribute *this)
{
  int v1; // eax

  v1 = this->m_nFlags & 0x1F;
  return v1 == 13 || v1 == 12;
}

//------------------------------------------------------------------------------
// Address: 0x0048D820
// Name: private: void CDmAttribute::CopyDataOut<class DmeTime_t>(class DmeTime_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyDataOut<DmeTime_t>(CDmAttribute *this, DmeTime_t *value)
{
  switch ( this->m_nFlags & 0x1F )
  {
    case 2:
      value->m_tms = *(int *)this->m_pData;
      break;
    case 3:
      value->m_tms = DmeTime_t::RoundSecondsToTMS(sec: *(float *)this->m_pData);
      break;
    case 4:
      if ( *(_BYTE *)this->m_pData != 0 )
        value->m_tms = DmeTime_t::RoundSecondsToTMS(sec: 1.0);
      else
        value->m_tms = 0;
      break;
    case 7:
      value->m_tms = *(int *)this->m_pData;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048D8E0
// Name: private: void CDmAttribute::CopyData<class QAngle>(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyData<QAngle>(CDmAttribute *this, const QAngle *value)
{
  Quaternion qValue; // [esp+4h] [ebp-10h] BYREF

  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    *(QAngle *)this->m_pData = *value;
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    AngleQuaternion(angles: value, outQuat: &qValue);
    *(Quaternion *)this->m_pData = qValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048D950
// Name: private: void CDmAttribute::CopyDataOut<class Quaternion>(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyDataOut<Quaternion>(CDmAttribute *this, Quaternion *value)
{
  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    AngleQuaternion(angles: (const QAngle *)this->m_pData, outQuat: value);
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    *value = *(Quaternion *)this->m_pData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048DE00
// Name: private: bool CDmAttribute::IsTypeConvertable<class CUtlSymbolLarge>(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::IsTypeConvertable<CUtlSymbolLarge>(CDmAttribute *this)
{
  return (this->m_nFlags & 0x1F) == 5;
}

//------------------------------------------------------------------------------
// Address: 0x0048DE30
// Name: public: class DmeTime_t const __near & CDmAttribute::GetValue<class DmeTime_t>(class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
const DmeTime_t *__thiscall CDmAttribute::GetValue<DmeTime_t>(CDmAttribute *this, const DmeTime_t *defaultValue)
{
  unsigned __int16 m_nFlags; // ax
  int v4; // eax

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x1F) == 7 )
    return (const DmeTime_t *)this->m_pData;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 7 && v4 != 3 && v4 != 2 && v4 != 4 )
    return defaultValue;
  if ( (`CDmAttribute::GetValue<DmeTime_t>'::`7'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<DmeTime_t>'::`7'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<DmeTime_t>'::`7'::tempVal.m_tms = 0x80000000;
  }
  CDmAttribute::CopyDataOut<DmeTime_t>(this, value: &`CDmAttribute::GetValue<DmeTime_t>'::`7'::tempVal);
  return &`CDmAttribute::GetValue<DmeTime_t>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x0048DEA0
// Name: public: class QAngle const __near & CDmAttribute::GetValue<class QAngle>(class QAngle const __near &)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CDmAttribute::GetValue<QAngle>(CDmAttribute *this, const QAngle *defaultValue)
{
  unsigned __int16 m_nFlags; // ax
  int v4; // eax

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x1F) == 0xC )
    return (const QAngle *)this->m_pData;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 12 && v4 != 13 )
    return defaultValue;
  if ( (`CDmAttribute::GetValue<QAngle>'::`7'::`local static guard' & 1) == 0 )
    `CDmAttribute::GetValue<QAngle>'::`7'::`local static guard' |= 1u;
  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    `CDmAttribute::GetValue<QAngle>'::`7'::tempVal = *(QAngle *)this->m_pData;
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    QuaternionAngles(q: (const Quaternion *)this->m_pData, angles: &`CDmAttribute::GetValue<QAngle>'::`7'::tempVal);
    return &`CDmAttribute::GetValue<QAngle>'::`7'::tempVal;
  }
  return &`CDmAttribute::GetValue<QAngle>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x0048DF40
// Name: private: bool CDmAttribute::IsTypeConvertable<class Vector>(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::IsTypeConvertable<Vector>(CDmAttribute *this)
{
  return (this->m_nFlags & 0x1F) == 10;
}

//------------------------------------------------------------------------------
// Address: 0x0048DF50
// Name: private: void CDmAttribute::CopyDataOut<class Vector>(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyDataOut<Vector>(CDmAttribute *this, Vector *value)
{
  *value = *(Vector *)this->m_pData;
}

//------------------------------------------------------------------------------
// Address: 0x0048FB10
// Name: public: class DmeTime_t const __near & CDmAttribute::GetValue<class DmeTime_t>(void)const
// Source: json
//------------------------------------------------------------------------------
const DmeTime_t *__thiscall CDmAttribute::GetValue<DmeTime_t>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage.m_tms = 0;
  }
  return CDmAttribute::GetValue<DmeTime_t>(
           this,
           defaultValue: &`CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00490810
// Name: private: bool CDmAttribute::ShouldModify<class CUtlSymbolLarge>(class CUtlSymbolLarge const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<CUtlSymbolLarge>(CDmAttribute *this, const CUtlSymbolLarge *value)
{
  _DWORD *v3; // eax

  if ( (this->m_nFlags & 0x1F) != 5 )
    return false;
  if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  v3 = (this->m_nFlags & 0x1F) == 5 ? this->m_pData : &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
  return *v3 != value->u.m_Id && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x00490870
// Name: private: bool CDmAttribute::ShouldModify<class DmeTime_t>(class DmeTime_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<DmeTime_t>(CDmAttribute *this, const DmeTime_t *value)
{
  unsigned __int16 m_nFlags; // cx
  int v4; // eax

  m_nFlags = this->m_nFlags;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 7 && v4 != 3 && v4 != 2 && v4 != 4 )
    return false;
  if ( (m_nFlags & 0x1F) != 7 )
    return CDmAttribute::MarkDirty(this);
  if ( (`CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage.m_tms = 0;
  }
  return CDmAttribute::GetValue<DmeTime_t>(
           this,
           defaultValue: &`CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage)->m_tms != value->m_tms
      && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x004908F0
// Name: public: class QAngle const __near & CDmAttribute::GetValue<class QAngle>(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CDmAttribute::GetValue<QAngle>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  return CDmAttribute::GetValue<QAngle>(
           this,
           defaultValue: &`CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00490940
// Name: private: bool CDmAttribute::ShouldModify<class QAngle>(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<QAngle>(CDmAttribute *this, const QAngle *value)
{
  unsigned __int16 m_nFlags; // cx
  int v4; // eax
  const QAngle *v6; // eax

  m_nFlags = this->m_nFlags;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 12 && v4 != 13 )
    return false;
  if ( (m_nFlags & 0x1F) != 0xC )
    return CDmAttribute::MarkDirty(this);
  if ( (`CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  v6 = CDmAttribute::GetValue<QAngle>(this, defaultValue: &`CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage);
  return (value->x != v6->x || value->y != v6->y || value->z != v6->z) && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x004909F0
// Name: public: class Color const __near & CDmAttribute::GetValue<class Color>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CDmAttribute::GetValue<Color>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Color>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Color>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_Storage = (Color)-16777216;
  }
  if ( (this->m_nFlags & 0x1F) == 8 )
    return (CDmaVar<Color> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Color>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00490A30
// Name: public: class Vector2D const __near & CDmAttribute::GetValue<class Vector2D>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector2D> *__thiscall CDmAttribute::GetValue<Vector2D>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.y = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 9 )
    return (CDmaVar<Vector2D> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00490A80
// Name: public: class Vector4D const __near & CDmAttribute::GetValue<class Vector4D>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector4D> *__thiscall CDmAttribute::GetValue<Vector4D>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector4D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector4D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.w = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xB )
    return (CDmaVar<Vector4D> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00490AE0
// Name: public: class VMatrix const __near & CDmAttribute::GetValue<class VMatrix>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<VMatrix> *__thiscall CDmAttribute::GetValue<VMatrix>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_pAttribute = nullptr;
    MatrixSetIdentity(dst: &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_Storage);
  }
  if ( (this->m_nFlags & 0x1F) == 0xE )
    return (CDmaVar<VMatrix> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00497860
// Name: private: bool CDmAttribute::ShouldModify<class Vector2D>(class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<Vector2D>(CDmAttribute *this, const Vector2D *value)
{
  CDmaVar<Vector2D> *m_pData; // edx

  if ( (this->m_nFlags & 0x1F) != 9 )
    return false;
  if ( (`CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.y = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 9 )
    m_pData = (CDmaVar<Vector2D> *)this->m_pData;
  else
    m_pData = &`CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal;
  return (value->x != m_pData->m_Storage.x || value->y != m_pData->m_Storage.y) && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x004978F0
// Name: private: bool CDmAttribute::ShouldModify<class VMatrix>(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<VMatrix>(CDmAttribute *this, const VMatrix *value)
{
  VMatrix *v4; // ecx

  if ( (this->m_nFlags & 0x1F) != 0xE )
    return false;
  if ( (`CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_pAttribute = nullptr;
    MatrixSetIdentity(dst: &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_Storage);
  }
  v4 = (VMatrix *)((this->m_nFlags & 0x1F) == 0xE ? this->m_pData : &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal);
  return !VMatrix::operator==(this: v4, src: value) && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A6A70
// Name: public: class CUtlBinaryBlock const __near & CDmAttribute::GetValue<class CUtlBinaryBlock>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlBinaryBlock> *__thiscall CDmAttribute::GetValue<CUtlBinaryBlock>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`local static guard' |= 1u;
    CUtlBinaryBlock::CUtlBinaryBlock(
      this: &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_Storage,
      growSize: 0,
      initSize: 0);
    `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlBinaryBlock::Set(
      this: &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_Storage,
      pValue: nullptr,
      nLen: 0);
    atexit(func: `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 6 )
    return (CDmaVar<CUtlBinaryBlock> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004C6F00
// Name: public: class CDmAttribute __near * CDmElement::AddAttributeElementArray<class CDmElement>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::AddAttributeElementArray<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v4 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v4 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_ARRAY_TYPE);
  if ( v4 == nullptr )
    return nullptr;
  CDmAttribute::SetElementTypeSymbol(this: v4, typeSymbol: CDmElement::m_classType);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004C7000
// Name: public: class CDmAttribute __near * CDmElement::SetValue<char const>(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue,
        char bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( bCreateIfNotFound == 0 && !CDmElement::HasAttribute(this, pAttributeName, type: AT_STRING) )
    return nullptr;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
    a1: g_pDataModel.u,
    a2: &bCreateIfNotFound,
    a3: pValue);
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&bCreateIfNotFound);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x004C7080
// Name: public: class CDmAttribute __near * CDmElement::InitValue<char const>(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::InitValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue)
{
  CDmAttribute *result; // eax
  CDmAttribute *Attribute; // esi

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pValue,
    a3: pValue);
  result = CDmElement::FindAttribute(this, pAttributeName);
  if ( result == nullptr )
  {
    Attribute = CDmElement::FindAttribute(this, pAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pValue);
      return Attribute;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C7400
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class CDmElement>(char const __near *,class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<CDmElement>(
        CDmElement *this,
        const char *pAttributeName,
        DmElementHandle_t pElement,
        bool bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    if ( !bCreateIfNotFound )
      return nullptr;
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_VALUE_TYPE);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: &pElement);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x004C8050
// Name: public: class Color const __near & CDmElement::GetValue<class Color>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CDmElement::GetValue<Color>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Color>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Color>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_Storage = (Color)-16777216;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Color>(this: Attribute);
  else
    return &`CDmElement::GetValue<Color>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004EC040
// Name: public: class CDmeDag __near * CAttributeReferenceIterator::FilterReference<class CDmeDag>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CAttributeReferenceIterator::FilterReference<CDmeDag>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeDag *result; // eax
  CDmeDag *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_24;
    case TD_DEEP:
      goto $LN11_20;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_20:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_24:
      v7 = *(CDmeDag **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeDag::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F3530
// Name: public: class CDmeChannel __near * CAttributeReferenceIterator::FilterReference<class CDmeChannel>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CAttributeReferenceIterator::FilterReference<CDmeChannel>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeChannel *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_25;
      case TD_DEEP:
        goto $LN11_21;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_21:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_25:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeChannel::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeChannel *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004F3DD0
// Name: public: class CDmeOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeOperator *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_26;
      case TD_DEEP:
        goto $LN11_22;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_22:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_26:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeOperator::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeOperator *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00500B00
// Name: public: class CDmeLog __near * CDmElement::GetValueElement<class CDmeLog>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmElement::GetValueElement<CDmeLog>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_660BF8 = -1;
    dword_660BFC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeLog::m_classType.u) != 0 )
  {
    return (CDmeLog *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005051C0
// Name: public: class CDmeRigBaseConstraintOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeRigBaseConstraintOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeRigBaseConstraintOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeRigBaseConstraintOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeRigBaseConstraintOperator *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_28;
      case TD_DEEP:
        goto $LN11_23;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_23:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_28:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeRigBaseConstraintOperator::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeRigBaseConstraintOperator *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0050F1F0
// Name: public: class CDmeClip __near * CAttributeReferenceIterator::FilterReference<class CDmeClip>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CAttributeReferenceIterator::FilterReference<CDmeClip>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeClip *result; // eax
  CDmeClip *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_29;
    case TD_DEEP:
      goto $LN11_24;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_24:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_29:
      v7 = *(CDmeClip **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeClip::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AC600
// Name: public: class CDmeFlexRules __near * CAttributeReferenceIterator::FilterReference<class CDmeFlexRules>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeFlexRules *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_31;
      case TD_DEEP:
        goto $LN11_38;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_38:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_31:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeFlexRules::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeFlexRules *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005EC740
// Name: _dynamic_initializer_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmElement::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmElement pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmElement::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F01B0
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2EA0
// Name: _dynamic_atexit_destructor_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmElement::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F41E0
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00407560
// Name: class CDmElement __near * GetElement<class CDmElement>(enum DmElementHandle_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl GetElement<CDmElement>(DmElementHandle_t hElement)
{
  int v1; // eax
  int v2; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: hElement);
  v2 = v1;
  if ( v1 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v2;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D1A0
// Name: bool FindReferringElements<class CDmElement>(class CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmElement>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmElement *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmElement **v11; // ecx
  int v12; // eax
  CDmElement **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(a1: g_pDataModel.u, a2: v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmElement>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmElement **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmElement **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004F3E80
// Name: class CDmeOperator __near * FindReferringElement<class CDmeOperator>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeOperator *__cdecl FindReferringElement<CDmeOperator>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeOperator *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeOperator>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC770
// Name: _dynamic_initializer_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC780
// Name: _dynamic_initializer_for__g_CDmElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmElement_Helper,
           classname: "DmElement",
           pFactory: &g_CDmElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC7A0
// Name: _dynamic_initializer_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC7B0
// Name: _dynamic_initializer_for__g_CDmeElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElement_Helper,
           classname: "DmeElement",
           pFactory: &g_CDmeElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC7D0
// Name: _dynamic_initializer_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc4__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_DataAlloc4,
    blockSize: 4,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "4-byte data pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc4__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC800
// Name: _dynamic_initializer_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc8__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_DataAlloc8,
    blockSize: 8,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "8-byte data pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc8__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC830
// Name: _dynamic_initializer_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrAlloc__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_AttrAlloc,
    blockSize: 24,
    numElements: 4096,
    growMode: 2,
    pszAllocOwner: "CDmAttribute pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrAlloc__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC860
// Name: _dynamic_initializer_for____s_AttrDmUnknownAttribute_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmUnknownAttribute_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<DmUnknownAttribute_t>::`vftable';
    s_pAttrInfo[0] = result;
  }
  else
  {
    s_pAttrInfo[0] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC890
// Name: _dynamic_initializer_for____s_Attrint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<int>::`vftable';
    s_pAttrInfo[2] = result;
  }
  else
  {
    s_pAttrInfo[2] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC8C0
// Name: _dynamic_initializer_for____s_AttrArrayint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<int>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[16] = result;
  }
  else
  {
    s_pAttrInfo[16] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC8F0
// Name: _dynamic_initializer_for____s_Attrfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<float>::`vftable';
    s_pAttrInfo[3] = result;
  }
  else
  {
    s_pAttrInfo[3] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC920
// Name: _dynamic_initializer_for____s_AttrArrayfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<float>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[17] = result;
  }
  else
  {
    s_pAttrInfo[17] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC950
// Name: _dynamic_initializer_for____s_Attrbool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrbool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<bool>::`vftable';
    s_pAttrInfo[4] = result;
  }
  else
  {
    s_pAttrInfo[4] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC980
// Name: _dynamic_initializer_for____s_AttrArraybool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArraybool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<bool>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[18] = result;
  }
  else
  {
    s_pAttrInfo[18] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC9B0
// Name: _dynamic_initializer_for____s_AttrColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Color>::`vftable';
    s_pAttrInfo[8] = result;
  }
  else
  {
    s_pAttrInfo[8] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC9E0
// Name: _dynamic_initializer_for____s_AttrArrayColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Color>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[22] = result;
  }
  else
  {
    s_pAttrInfo[22] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECA10
// Name: _dynamic_initializer_for____s_AttrVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector2D>::`vftable';
    s_pAttrInfo[9] = result;
  }
  else
  {
    s_pAttrInfo[9] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECA40
// Name: _dynamic_initializer_for____s_AttrArrayVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector2D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[23] = result;
  }
  else
  {
    s_pAttrInfo[23] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECA70
// Name: _dynamic_initializer_for____s_AttrVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector>::`vftable';
    s_pAttrInfo[10] = result;
  }
  else
  {
    s_pAttrInfo[10] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECAA0
// Name: _dynamic_initializer_for____s_AttrArrayVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[24] = result;
  }
  else
  {
    s_pAttrInfo[24] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECAD0
// Name: _dynamic_initializer_for____s_AttrVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector4D>::`vftable';
    s_pAttrInfo[11] = result;
  }
  else
  {
    s_pAttrInfo[11] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECB00
// Name: _dynamic_initializer_for____s_AttrArrayVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector4D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[25] = result;
  }
  else
  {
    s_pAttrInfo[25] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECB30
// Name: _dynamic_initializer_for____s_AttrQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<QAngle>::`vftable';
    s_pAttrInfo[12] = result;
  }
  else
  {
    s_pAttrInfo[12] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECB60
// Name: _dynamic_initializer_for____s_AttrArrayQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<QAngle>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[26] = result;
  }
  else
  {
    s_pAttrInfo[26] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECB90
// Name: _dynamic_initializer_for____s_AttrQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Quaternion>::`vftable';
    s_pAttrInfo[13] = result;
  }
  else
  {
    s_pAttrInfo[13] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECBC0
// Name: _dynamic_initializer_for____s_AttrArrayQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Quaternion>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[27] = result;
  }
  else
  {
    s_pAttrInfo[27] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECBF0
// Name: _dynamic_initializer_for____s_AttrVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<VMatrix>::`vftable';
    s_pAttrInfo[14] = result;
  }
  else
  {
    s_pAttrInfo[14] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECC20
// Name: _dynamic_initializer_for____s_AttrArrayVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<VMatrix>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[28] = result;
  }
  else
  {
    s_pAttrInfo[28] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECC50
// Name: _dynamic_initializer_for____s_AttrCUtlSymbolLarge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlSymbolLarge__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlSymbolLarge>::`vftable';
    s_pAttrInfo[5] = result;
  }
  else
  {
    s_pAttrInfo[5] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECC80
// Name: _dynamic_initializer_for____s_AttrArrayCUtlSymbolLarge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlSymbolLarge__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlSymbolLarge>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[19] = result;
  }
  else
  {
    s_pAttrInfo[19] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECCB0
// Name: _dynamic_initializer_for____s_AttrCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlBinaryBlock>::`vftable';
    s_pAttrInfo[6] = result;
  }
  else
  {
    s_pAttrInfo[6] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECCE0
// Name: _dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlBinaryBlock>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[20] = result;
  }
  else
  {
    s_pAttrInfo[20] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECD10
// Name: _dynamic_initializer_for____s_AttrDmeTime_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmeTime_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<DmeTime_t>::`vftable';
    s_pAttrInfo[7] = result;
  }
  else
  {
    s_pAttrInfo[7] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECD40
// Name: _dynamic_initializer_for____s_AttrArrayDmeTime_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmeTime_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<DmeTime_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[21] = result;
  }
  else
  {
    s_pAttrInfo[21] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECD70
// Name: _dynamic_initializer_for____s_AttrDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<enum DmElementHandle_t>::`vftable';
    s_pAttrInfo[1] = result;
  }
  else
  {
    s_pAttrInfo[1] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECDA0
// Name: _dynamic_initializer_for____s_AttrArrayDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<enum DmElementHandle_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[15] = result;
  }
  else
  {
    s_pAttrInfo[15] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECDD0
// Name: _dynamic_initializer_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DmElementFramework__()
{
  CDependencyGraph::CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = nullptr;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nAllocationCount = 256;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nGrowSize = 128;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = (DmElementHandle_t *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: 1024);
  g_DmElementFramework.m_dirtyElements.m_Size = 0;
  g_DmElementFramework.m_dirtyElements.m_pElements = g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory;
  g_DmElementFramework.m_phase = PH_EDIT;
  return atexit(func: dynamic_atexit_destructor_for__g_DmElementFramework__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECE40
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005ECE80
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2.m_ElementDict);
  s_DMSerializerKeyValues2.m_bFlatMode = false;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECEA0
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2Flat__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2Flat.m_ElementDict);
  s_DMSerializerKeyValues2Flat.m_bFlatMode = true;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECEC0
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECED0
// Name: _dynamic_initializer_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_AttrNodePool,
    blockSize: 28,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECF00
// Name: _dynamic_initializer_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_OperatorNodePool,
    blockSize: 32,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_OperatorNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECF30
// Name: _dynamic_initializer_for__s_ImportSFMV9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV9__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV9, formatName: "sfm_v9", nextFormatName: "sfm_v10");
  s_ImportSFMV9.__vftable = (CImportSFMV9_vtbl *)&CImportSFMV9::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECF50
// Name: _dynamic_initializer_for__s_ImportSFMV8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV8__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV8, formatName: "sfm_v8", nextFormatName: "sfm_v9");
  s_ImportSFMV8.__vftable = (CImportSFMV8_vtbl *)&CImportSFMV8::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECF70
// Name: _dynamic_initializer_for__s_ImportSFMV7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV7__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV7, formatName: "sfm_v7", nextFormatName: "sfm_v8");
  s_ImportSFMV7.__vftable = (CImportSFMV7_vtbl *)&CImportSFMV7::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECF90
// Name: _dynamic_initializer_for__s_ImportSFMV6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV6__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV6, formatName: "sfm_v6", nextFormatName: "sfm_v7");
  s_ImportSFMV6.__vftable = (CImportSFMV6_vtbl *)&CImportSFMV6::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECFB0
// Name: _dynamic_initializer_for__s_ImportSFMV5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV5__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV5, formatName: "sfm_v5", nextFormatName: "sfm_v6");
  s_ImportSFMV5.__vftable = (CImportSFMV5_vtbl *)&CImportSFMV5::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECFD0
// Name: _dynamic_initializer_for__s_ImportSFMV4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV4__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV4, formatName: "sfm_v4", nextFormatName: "sfm_v5");
  s_ImportSFMV4.__vftable = (CImportSFMV4_vtbl *)&CImportSFMV4::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECFF0
// Name: _dynamic_initializer_for__s_ImportSFMV3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV3__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV3, formatName: "sfm_v3", nextFormatName: "sfm_v4");
  s_ImportSFMV3.__vftable = (CImportSFMV3_vtbl *)&CImportSFMV3::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ED010
// Name: _dynamic_initializer_for__s_ImportSFMV2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV2__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV2, formatName: "sfm_v2", nextFormatName: "sfm_v3");
  s_ImportSFMV2.__vftable = (CImportSFMV2_vtbl *)&CImportSFMV2::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ED030
// Name: _dynamic_initializer_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ImportDmxV1__()
{
  CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportDmxV1, formatName: "sfm_v1", nextFormatName: "sfm_v2");
  s_ImportDmxV1.__vftable = (CImportSFMV1_vtbl *)&CImportSFMV1::`vftable';
  s_ImportDmxV1.m_fixedElements.m_Elements.m_pMemory = nullptr;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nAllocationCount = 0;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nGrowSize = 0;
  s_ImportDmxV1.m_fixedElements.m_Root = -1;
  s_ImportDmxV1.m_fixedElements.m_NumElements = 0;
  s_ImportDmxV1.m_fixedElements.m_FirstFree = -1;
  s_ImportDmxV1.m_fixedElements.m_LastAlloc.index = -1;
  s_ImportDmxV1.m_fixedElements.m_pElements = nullptr;
  s_ImportDmxV1.m_fixedElements.m_LessFunc = CDefOps<CDmAttribute *>::LessFunc;
  return atexit(func: dynamic_atexit_destructor_for__s_ImportDmxV1__);
}

//------------------------------------------------------------------------------
// Address: 0x005F01E0
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F01F0
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F2EB0
// Name: _dynamic_atexit_destructor_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeElement_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F2EC0
// Name: _dynamic_atexit_destructor_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmElement_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F2ED0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x005F2EE0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x005F2EF0
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x005F41F0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004063E0
// Name: bool IsPowerOfTwo(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsPowerOfTwo(int value)
{
  return (value & (value - 1)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406400
// Name: public: void CChangeUndoScopeGuard::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeUndoScopeGuard::Release(CChangeUndoScopeGuard *this)
{
  bool v2; // zf

  if ( !this->m_bReleased )
  {
    (*(void (__stdcall **)(bool))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(a1: this->m_bOldValue);
    v2 = !this->m_bNotify;
    this->m_bReleased = true;
    if ( !v2 )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
        a1: g_pDataModel.u,
        a2: 0);
      this->m_bNotify = false;
    }
    if ( this->m_pNotify != nullptr )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: this->m_pNotify);
      this->m_pNotify = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406460
// Name: bool ShouldTraverse(class CDmAttribute const __near *,enum TraversalDepth_t)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldTraverse(const CDmAttribute *pAttr, TraversalDepth_t depth)
{
  switch ( depth )
  {
    case TD_ALL:
      return 1;
    case TD_DEEP:
      return (pAttr->m_nFlags & 0x1000) == 0;
    case TD_SHALLOW:
      if ( (pAttr->m_nFlags & 0x800) == 0 )
        return 0;
      return (pAttr->m_nFlags & 0x1000) == 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004064B0
// Name: public: s_tmpface_t::s_tmpface_t(void)
// Source: json
//------------------------------------------------------------------------------
s_tmpface_t *__thiscall s_tmpface_t::s_tmpface_t(s_tmpface_t *this)
{
  this->d = -1;
  this->c = -1;
  this->b = -1;
  this->a = -1;
  this->td = -1;
  this->tc = -1;
  this->tb = -1;
  this->ta = -1;
  this->nd = -1;
  this->nc = -1;
  this->nb = -1;
  this->na = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004064E0
// Name: VertexLookup_CompareFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VertexLookup_CompareFunc(const VertexLookup_t *a, const VertexLookup_t *b)
{
  return a->v == b->v && a->n == b->n && a->t == b->t;
}

//------------------------------------------------------------------------------
// Address: 0x00406510
// Name: VertexLookup_KeyFunc
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl VertexLookup_KeyFunc(const VertexLookup_t *a)
{
  return Hash12(pKey: a);
}

//------------------------------------------------------------------------------
// Address: 0x00406580
// Name: public: CDisableUndoScopeGuard::CDisableUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
CDisableUndoScopeGuard *__thiscall CDisableUndoScopeGuard::CDisableUndoScopeGuard(CDisableUndoScopeGuard *this)
{
  *(_WORD *)&this->m_bReleased = 0;
  this->m_pNotify = nullptr;
  this->m_bOldValue = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004065C0
// Name: public: int CDmrElementArray<class CDmElement>::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmrElementArray<CDmElement>::Count(CDmrElementArray<CDmElement> *this)
{
  if ( this->m_pAttribute != nullptr )
    return this->m_pStorage->m_Size;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004065D0
// Name: public: class CDmElement __near * CAttributeReferenceIterator::FilterReference<class CDmElement>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CAttributeReferenceIterator::FilterReference<CDmElement>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmElement *result; // eax
  CDmElement *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_1;
    case TD_DEEP:
      goto $LN11;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_1:
      v7 = *(CDmElement **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmElement::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004066C0
// Name: public: int const __near & CDmAttribute::GetValue<int>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CDmAttribute::GetValue<int>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (this->m_nFlags & 0x1F) == 2 )
    return (CDmaVar<int> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<bool>(this) )
    return &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  CDmAttribute::CopyDataOut<int>(this, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
  return (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x00406A90
// Name: public: enum DmElementHandle_t const __near & CDmAttribute::GetValue<enum DmElementHandle_t>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CDmAttribute::GetValue<enum DmElementHandle_t>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  if ( (this->m_nFlags & 0x1F) == 1 )
    return (CDmaVar<enum DmElementHandle_t> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<enum DmElementHandle_t>(this) )
    return &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  CDmAttribute::CopyDataOut<enum DmElementHandle_t>(
    this,
    value: &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`7'::tempVal);
  return (CDmaVar<enum DmElementHandle_t> *)&`CDmAttribute::GetValue<enum DmElementHandle_t>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x00406AF0
// Name: public: char const __near * CDmElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmElement::GetName(CDmElement *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return pDeltaStateName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406B00
// Name: BuildVertexAnimations
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVertexAnimations(s_source_t *pSource)
{
  int m_Size; // esi
  DeltaState_t *v2; // esi
  const char *v3; // eax
  s_sourceanim_t *v4; // ebx
  int m_nFirstDelta; // edx
  int v6; // eax
  DeltaIndex_t *m_pMemory; // edi
  int v8; // edx
  VertIndices_t *v9; // eax
  v_unify_t *v10; // esi
  unsigned __int8 *v11; // eax
  int m_nPositionIndex; // ecx
  Vector *v13; // ebx
  int v14; // ecx
  double x; // st7
  Vector *v16; // ecx
  int m_nNormalIndex; // ecx
  Vector *v18; // ebx
  int v19; // ecx
  double v20; // st7
  Vector *v21; // ecx
  int m_nWrinkleIndex; // ecx
  unsigned int v23; // esi
  unsigned __int8 *v24; // edi
  s_sourceanim_t *pSourceAnim; // [esp+8h] [ebp-20h]
  int i; // [esp+Ch] [ebp-1Ch]
  VertIndices_t *uniqueVert; // [esp+10h] [ebp-18h]
  unsigned __int8 *v28; // [esp+14h] [ebp-14h]
  unsigned __int8 *pVertAnim; // [esp+18h] [ebp-10h]
  int v30; // [esp+1Ch] [ebp-Ch]
  int nVertAnimCount; // [esp+20h] [ebp-8h]
  DeltaState_t *state; // [esp+24h] [ebp-4h]

  m_Size = s_DeltaStates.m_Size;
  if ( s_DeltaStates.m_Size != 0 )
  {
    pVertAnim = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 40 * g_numvlist);
    if ( m_Size > 0 )
    {
      v30 = 0;
      for ( i = m_Size; i != 0; --i )
      {
        v2 = &s_DeltaStates.m_Memory.m_pMemory[v30];
        state = &s_DeltaStates.m_Memory.m_pMemory[v30];
        v3 = CUtlString::operator char const *(this: &s_DeltaStates.m_Memory.m_pMemory[v30].m_Name);
        v4 = FindOrAddSourceAnim(pSource, pAnimName: v3);
        v4->numframes = 1;
        v4->startframe = 0;
        v4->endframe = 0;
        v4->newStyleVertexAnimations = true;
        m_nFirstDelta = v2->m_nFirstDelta;
        v6 = 0;
        pSourceAnim = v4;
        nVertAnimCount = 0;
        if ( m_nFirstDelta >= 0 )
        {
          while ( 1 )
          {
            m_pMemory = v2->m_DeltaIndices.m_Memory.m_pMemory;
            v8 = m_nFirstDelta;
            v9 = &s_UniqueVertices.m_Memory.m_pMemory[v8];
            v10 = v_list[s_UniqueVertices.m_Memory.m_pMemory[v8].v];
            uniqueVert = &s_UniqueVertices.m_Memory.m_pMemory[v8];
            if ( v10 != nullptr )
            {
              v28 = &pVertAnim[40 * nVertAnimCount];
              do
              {
                if ( v10->n == v9->n && v10->t == v9->t )
                {
                  v11 = v28;
                  ++nVertAnimCount;
                  v28 += 40;
                  *(_DWORD *)v11 = v10 - v_listdata;
                  *((float *)v11 + 1) = s_Speed.m_Memory.m_pMemory[s_UniqueVertices.m_Memory.m_pMemory[v8].speed];
                  *((float *)v11 + 2) = s_Balance.m_Memory.m_pMemory[s_UniqueVertices.m_Memory.m_pMemory[v8].balance];
                  m_nPositionIndex = m_pMemory[v8].m_nPositionIndex;
                  if ( m_nPositionIndex < 0 )
                  {
                    *((Vector *)v11 + 1) = vec3_origin;
                  }
                  else
                  {
                    v13 = state->m_PositionDeltas.m_Memory.m_pMemory;
                    v14 = m_nPositionIndex;
                    x = v13[v14].x;
                    v16 = &v13[v14];
                    *((float *)v11 + 3) = x;
                    *((float *)v11 + 4) = v16->y;
                    *((float *)v11 + 5) = v16->z;
                  }
                  m_nNormalIndex = m_pMemory[v8].m_nNormalIndex;
                  if ( m_nNormalIndex < 0 )
                  {
                    *((Vector *)v11 + 2) = vec3_origin;
                  }
                  else
                  {
                    v18 = state->m_NormalDeltas.m_Memory.m_pMemory;
                    v19 = m_nNormalIndex;
                    v20 = v18[v19].x;
                    v21 = &v18[v19];
                    *((float *)v11 + 6) = v20;
                    *((float *)v11 + 7) = v21->y;
                    *((float *)v11 + 8) = v21->z;
                  }
                  m_nWrinkleIndex = m_pMemory[v8].m_nWrinkleIndex;
                  if ( m_nWrinkleIndex < 0 )
                    *((_DWORD *)v11 + 9) = 0;
                  else
                    *((float *)v11 + 9) = state->m_WrinkleDeltas.m_Memory.m_pMemory[m_nWrinkleIndex];
                  v9 = uniqueVert;
                }
                v10 = v10->next;
              }
              while ( v10 != nullptr );
              v4 = pSourceAnim;
            }
            m_nFirstDelta = state->m_DeltaIndices.m_Memory.m_pMemory[v8].m_nNextDelta;
            if ( m_nFirstDelta < 0 )
              break;
            v2 = state;
          }
          v6 = nVertAnimCount;
        }
        v4->numvanims[0] = v6;
        v23 = 40 * v6;
        v24 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 40 * v6);
        memset(dst: v24, value: 0, count: v23);
        v4->vanim[0] = (s_vertanim_t *)v24;
        memcpy(dst: v24, src: pVertAnim, count: v23);
        ++v30;
      }
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pVertAnim);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406DA0
// Name: HandleDmeJiggleBone
// Source: json
//------------------------------------------------------------------------------
void __usercall HandleDmeJiggleBone(const CDmeDag *pDmeDag@<edi>)
{
  int v1; // eax
  int v2; // esi
  char *bonename; // ebx
  s_jigglebone_t *v4; // esi
  mstudiojigglebone_t *p_data; // ebx
  int v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  char *s1; // [esp+8h] [ebp-4h]

  if ( pDmeDag != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pDmeDag->IsA)(
         a1: (struct CDmeDag *)pDmeDag,
         a2: (CUtlSymbolLarge)CDmeJiggleBone::m_classType.u.m_Id) )
  {
    s1 = (char *)pDeltaStateName;
    if ( pDmeDag->m_Name.m_Storage.u.CDmElement::m_Id != -1 )
      s1 = (char *)pDmeDag->m_Name.m_Storage.u.CDmElement::m_Id;
    v1 = g_numjigglebones;
    v2 = 0;
    if ( g_numjigglebones <= 0 )
    {
LABEL_9:
      g_numjigglebones = v1 + 1;
      v4 = &g_jigglebones[v1];
      V_strncpy(pDest: v4->bonename, pSrc: s1, maxLen: 128);
      p_data = &v4->data;
      memset(dst: (unsigned __int8 *)&v4->data, value: 0, count: sizeof(v4->data));
      v4->data.baseMinUp = -100.0;
      v4->data.baseMinLeft = -100.0;
      v4->data.baseMinForward = -100.0;
      v4->data.yawStiffness = 100.0;
      v4->data.pitchStiffness = 100.0;
      v4->data.alongStiffness = 100.0;
      v4->data.baseStiffness = 100.0;
      v4->data.baseMaxUp = 100.0;
      v4->data.baseMaxLeft = 100.0;
      v4->data.baseMaxForward = 100.0;
      v4->data.length = 10.0;
      v4->data.length = *((float *)&pDmeDag[1].CDmElement + 15);
      v4->data.tipMass = *(float *)&pDmeDag[1].m_Visible.m_Storage;
      v4->data.flags |= LOBYTE(pDmeDag[1].m_ref.m_attributes.m_pNext) != 0 ? 0x20 : 0;
      v4->data.angleLimit = *(float *)&pDmeDag[1].m_bDisableOverrideParent.m_Storage * 0.017453292;
      v4->data.flags |= LOBYTE(pDmeDag[1].m_ref.m_hElement) != 0 ? 4 : 0;
      v4->data.minYaw = *(float *)&pDmeDag[1].m_Transform.m_Storage.m_Handle * 0.017453292;
      v4->data.maxYaw = *(float *)&pDmeDag[1].m_Transform.m_pAttribute * 0.017453292;
      v4->data.yawFriction = *(float *)&pDmeDag[1].m_Shape.m_Storage.m_ElementType.u.m_Id;
      v4->data.yawBounce = *(float *)&pDmeDag[1].m_Children.m_Storage.m_Memory.m_pMemory;
      v4->data.flags |= LOBYTE(pDmeDag[1].m_Type.u.CDmElement::m_Id) != 0 ? 0x10 : 0;
      v4->data.minPitch = *(float *)&pDmeDag[1].m_Children.m_Storage.m_Memory.m_nGrowSize * 0.017453292;
      v6 = 0;
      v4->data.maxPitch = *(float *)&pDmeDag[1].m_Children.m_Storage.m_pElements * 0.017453292;
      v4->data.pitchFriction = *(float *)&pDmeDag[1].m_Children.m_pAttribute;
      v4->data.pitchBounce = *(float *)pDmeDag[2].m_Id.m_Value;
      if ( pDmeDag[1].m_Id.m_Value[8] != 0 )
      {
        if ( pDmeDag[1].m_Id.m_Value[0] != 0 )
        {
          MdlWarning(fmt: "2001: Jiggle Bone %s: Both flexible and rigid set, ignoring rigid\n", s1);
          v6 = 0;
        }
        p_data->flags |= 1u;
        p_data->flags |= *((_BYTE *)&pDmeDag[1].m_ref + 8) != 0 ? 8 : 0;
        v7 = *(float *)&pDmeDag[2].m_Id.m_Value[8];
        if ( v7 >= 0.0 )
        {
          if ( v7 > 1000.0 )
            v7 = 1000.0;
        }
        else
        {
          v7 = 0.0;
        }
        v4->data.yawStiffness = v7;
        v8 = *(float *)&pDmeDag[2].m_Name.m_Storage.u.CDmElement::m_Id;
        if ( v8 >= 0.0 )
        {
          if ( v8 > 10.0 )
            v8 = 10.0;
        }
        else
        {
          v8 = 0.0;
        }
        v4->data.yawDamping = v8;
        v9 = *(float *)&pDmeDag[2].m_ref.m_hElement;
        if ( v9 >= 0.0 )
        {
          if ( v9 > 1000.0 )
            v9 = 1000.0;
        }
        else
        {
          v9 = 0.0;
        }
        v4->data.pitchStiffness = v9;
        v10 = *((float *)&pDmeDag[2].m_ref + 2);
        if ( v10 >= 0.0 )
        {
          if ( v10 > 10.0 )
            v10 = 10.0;
        }
        else
        {
          v10 = 0.0;
        }
        v4->data.pitchDamping = v10;
        v11 = *(float *)&pDmeDag[2].m_ref.m_attributes.m_pNext;
        if ( v11 >= 0.0 )
        {
          if ( v11 > 1000.0 )
            v11 = 1000.0;
        }
        else
        {
          v11 = 0.0;
        }
        v4->data.alongStiffness = v11;
        v12 = *(float *)&pDmeDag[2].m_Type.u.CDmElement::m_Id;
        if ( v12 >= 0.0 )
        {
          if ( v12 > 10.0 )
            v12 = 10.0;
          v4->data.alongDamping = v12;
        }
        else
        {
          v4->data.alongDamping = 0.0;
        }
      }
      else if ( pDmeDag[1].m_Id.m_Value[0] != 0 )
      {
        p_data->flags |= 0x21u;
      }
      if ( LOBYTE(pDmeDag[1].m_Name.m_Storage.u.CDmElement::m_Id) != 0 )
      {
        v4->data.baseMass = *((float *)&pDmeDag[2].CDmElement + 15);
        v13 = *(float *)&pDmeDag[2].m_Visible.m_Storage;
        if ( v13 >= 0.0 )
        {
          if ( v13 > 1000.0 )
            v13 = 1000.0;
        }
        else
        {
          v13 = 0.0;
        }
        v4->data.baseStiffness = v13;
        v14 = *(float *)&pDmeDag[2].m_Visible.m_Storage;
        if ( v14 >= 0.0 )
        {
          if ( v14 <= 10.0 )
            v6 = *(_DWORD *)&pDmeDag[2].m_Visible.m_Storage;
          else
            v6 = 1092616192;
        }
        LODWORD(v4->data.baseDamping) = v6;
        v4->data.baseMinLeft = *(float *)&pDmeDag[2].m_Transform.m_Storage.m_Handle;
        v4->data.baseMaxLeft = *(float *)&pDmeDag[2].m_Transform.m_pAttribute;
        v4->data.baseLeftFriction = *(float *)&pDmeDag[2].m_Shape.m_Storage.m_ElementType.u.m_Id;
        v4->data.baseMinUp = *(float *)&pDmeDag[2].m_Children.m_Storage.m_Memory.m_pMemory;
        v4->data.baseMaxUp = *(float *)&pDmeDag[2].m_Children.m_Storage.m_Memory.m_nGrowSize;
        v4->data.baseUpFriction = *(float *)&pDmeDag[2].m_Children.m_Storage.m_pElements;
        v4->data.baseMinForward = *(float *)&pDmeDag[2].m_Children.m_pAttribute;
        v4->data.baseMaxForward = *(float *)pDmeDag[3].m_Id.m_Value;
        v4->data.baseForwardFriction = *(float *)&pDmeDag[3].m_Id.m_Value[8];
      }
    }
    else
    {
      bonename = g_jigglebones[0].bonename;
      while ( _V_stricmp(s1, s2: bonename) != 0 )
      {
        v1 = g_numjigglebones;
        ++v2;
        bonename += 256;
        if ( v2 >= g_numjigglebones )
          goto LABEL_9;
      }
      MdlWarning(fmt: "2000: Jiggle Bone: %s already defined, ignoring additional declarations\n", s1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004071D0
// Name: AddDagJoint
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddDagJoint(
        CDmeModel *pModel,
        CDmeDag *pDag,
        s_node_t *pNodes,
        int nParentIndex,
        BoneTransformMap_t *boneMap)
{
  CDmeTransform *Transform; // eax
  int m_nBoneCount; // ebx
  const char *m_pAsString; // edi
  int JointIndex; // eax
  const char *v10; // ecx
  const char *v11; // eax
  const char *v12; // eax
  int v13; // esi
  CDmeDag *Child; // eax

  Transform = CDmeDag::GetTransform(this: pDag);
  if ( Transform == nullptr )
    return 1;
  m_nBoneCount = boneMap->m_nBoneCount;
  if ( boneMap->m_nBoneCount >= 1023 )
  {
    m_pAsString = pDag->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    MdlWarning(fmt: "Ignoring Bone %s and children, too many bones [max can be %d]!\n", m_pAsString, 1023);
    return 0;
  }
  boneMap->m_nBoneCount = m_nBoneCount + 1;
  boneMap->m_ppTransforms[m_nBoneCount] = Transform;
  if ( pModel != nullptr )
  {
    JointIndex = CDmeModel::GetJointIndex(this: pModel, pJoint: pDag);
    if ( JointIndex < 0 )
    {
      v10 = pDeltaStateName;
      if ( pModel->m_Name.m_Storage.u.CDmeDag::CDmElement::m_Id != -1 )
        v10 = pModel->m_Name.m_Storage.u.m_pAsString;
      v11 = pDag->m_Name.m_Storage.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = pDeltaStateName;
      MdlWarning(fmt: "Joint %s doesn't appear in DmeModel[%s].jointList\n", v11, v10);
    }
    else
    {
      boneMap->m_pnDmeModelToMdl[JointIndex] = m_nBoneCount;
      boneMap->m_pnMdlToDmeModel[m_nBoneCount] = JointIndex;
    }
  }
  HandleDmeJiggleBone(pDmeDag: pDag);
  v12 = pDag->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = pDeltaStateName;
  V_strncpy(pDest: pNodes[m_nBoneCount].name, pSrc: v12, maxLen: 128);
  pNodes[m_nBoneCount].parent = nParentIndex;
  v13 = 0;
  if ( CDmElementFramework::GetPhase(this: pDag) > 0 )
  {
    while ( 1 )
    {
      Child = CDmeDag::GetChild(this: pDag, i: v13);
      if ( Child != nullptr && !AddDagJoint(pModel, pDag: Child, pNodes, nParentIndex: m_nBoneCount, boneMap) )
        break;
      if ( ++v13 >= CDmElementFramework::GetPhase(this: pDag) )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407300
// Name: LoadSkeleton
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoadSkeleton(CDmeDag *pRoot, CDmeModel *pModel, s_node_t *pNodes, BoneTransformMap_t *boneMap)
{
  BoneTransformMap_t *v4; // esi
  s_node_t *v5; // edi
  s_node_t *v6; // ecx
  int *m_pnMdlToDmeModel; // eax
  int j; // edx
  int v9; // ebx
  CDmeDag *Child; // eax
  CDmeDag *v11; // edi
  CDmeTransform *Transform; // eax
  int m_nBoneCount; // ebx
  int JointIndex; // eax
  const char *v15; // ecx
  const char *v16; // eax
  const char *v17; // eax
  int v18; // esi
  CDmeDag *v19; // eax
  const char *m_pAsString; // edi
  int i; // [esp+Ch] [ebp-4h]

  v4 = boneMap;
  v5 = pNodes;
  boneMap->m_nBoneCount = 0;
  v6 = pNodes;
  m_pnMdlToDmeModel = boneMap->m_pnMdlToDmeModel;
  for ( j = 1024; j != 0; --j )
  {
    v6->name[0] = 0;
    v6->parent = -1;
    *(m_pnMdlToDmeModel - 1024) = -1;
    *m_pnMdlToDmeModel = -1;
    *(m_pnMdlToDmeModel - 2048) = 0;
    ++v6;
    ++m_pnMdlToDmeModel;
  }
  v9 = 0;
  i = 0;
  if ( CDmElementFramework::GetPhase(this: pRoot) <= 0 )
  {
LABEL_24:
    s_nDefaultRootNode = v4->m_nBoneCount;
    V_strncpy(pDest: v5[s_nDefaultRootNode].name, pSrc: "defaultRoot", maxLen: 128);
    v5[s_nDefaultRootNode].parent = -1;
    return v4->m_nBoneCount + 1;
  }
  while ( 1 )
  {
    Child = CDmeDag::GetChild(this: pRoot, i: v9);
    v11 = Child;
    if ( Child == nullptr )
      goto LABEL_22;
    Transform = CDmeDag::GetTransform(this: Child);
    if ( Transform == nullptr )
      goto LABEL_22;
    m_nBoneCount = v4->m_nBoneCount;
    if ( v4->m_nBoneCount >= 1023 )
    {
      m_pAsString = v11->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      MdlWarning(fmt: "Ignoring Bone %s and children, too many bones [max can be %d]!\n", m_pAsString, 1023);
      return 0;
    }
    v4->m_nBoneCount = m_nBoneCount + 1;
    v4->m_ppTransforms[m_nBoneCount] = Transform;
    if ( pModel != nullptr )
    {
      JointIndex = CDmeModel::GetJointIndex(this: pModel, pJoint: v11);
      if ( JointIndex < 0 )
      {
        v15 = pDeltaStateName;
        if ( pModel->m_Name.m_Storage.u.CDmeDag::CDmElement::m_Id != -1 )
          v15 = pModel->m_Name.m_Storage.u.m_pAsString;
        v16 = v11->m_Name.m_Storage.u.m_pAsString;
        if ( v16 == (const char *)-1 )
          v16 = pDeltaStateName;
        MdlWarning(fmt: "Joint %s doesn't appear in DmeModel[%s].jointList\n", v16, v15);
      }
      else
      {
        v4->m_pnDmeModelToMdl[JointIndex] = m_nBoneCount;
        v4->m_pnMdlToDmeModel[m_nBoneCount] = JointIndex;
      }
    }
    HandleDmeJiggleBone(pDmeDag: v11);
    v17 = v11->m_Name.m_Storage.u.m_pAsString;
    if ( v17 == (const char *)-1 )
      v17 = pDeltaStateName;
    V_strncpy(pDest: pNodes[m_nBoneCount].name, pSrc: v17, maxLen: 128);
    pNodes[m_nBoneCount].parent = -1;
    v18 = 0;
    if ( CDmElementFramework::GetPhase(this: v11) > 0 )
      break;
LABEL_21:
    v4 = boneMap;
    v9 = i;
LABEL_22:
    i = ++v9;
    if ( v9 >= CDmElementFramework::GetPhase(this: pRoot) )
    {
      v5 = pNodes;
      goto LABEL_24;
    }
  }
  while ( 1 )
  {
    v19 = CDmeDag::GetChild(this: v11, i: v18);
    if ( v19 != nullptr && AddDagJoint(pModel, pDag: v19, pNodes, nParentIndex: m_nBoneCount, boneMap) == 0 )
      return 0;
    if ( ++v18 >= CDmElementFramework::GetPhase(this: v11) )
      goto LABEL_21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004074F0
// Name: AddFlexKeys
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddFlexKeys(CDmeDag *pRoot, CDmeDag *pDag, CDmeCombinationOperator *pComboOp, s_source_t *pSource)
{
  CDmeDag *v4; // ebx
  CDmeShape *Shape; // eax
  CDmeMesh *v6; // edi
  int v7; // ebx
  int i; // esi
  const char *m_pAsString; // eax
  int Phase; // edi
  int j; // esi
  CDmeDag *Child; // eax

  v4 = pDag;
  Shape = CDmeDag::GetShape(this: pDag);
  v6 = (CDmeMesh *)Shape;
  if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) && pDag != pRoot )
  {
    v7 = CDmeMesh::DeltaStateCount(this: v6);
    for ( i = 0; i < v7; ++i )
    {
      m_pAsString = CDmeMesh::GetDeltaState(this: v6, nDeltaIndex: i)->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      AddFlexKey(pSource, pComboOp, pFlexKeyName: m_pAsString);
    }
    v4 = pDag;
  }
  Phase = CDmElementFramework::GetPhase(this: v4);
  for ( j = 0; j < Phase; ++j )
  {
    Child = CDmeDag::GetChild(this: v4, i: j);
    if ( Child != nullptr )
      AddFlexKeys(pRoot, pDag: Child, pComboOp, pSource);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004075E0
// Name: LoadMouth
// Source: json
//------------------------------------------------------------------------------
bool __usercall LoadMouth@<al>(CDmeMouth *pDmeMouth@<edi>)
{
  int m_Storage; // eax
  s_mouth_t *v2; // esi
  const char *m_pAsString; // eax
  const char *v4; // eax

  if ( pDmeMouth != nullptr )
  {
    m_Storage = pDmeMouth->m_nMouthNumber.m_Storage;
    if ( g_nummouths <= m_Storage )
    {
      g_nummouths = m_Storage + 1;
      v2 = &g_mouth[m_Storage];
      m_pAsString = pDmeMouth->m_sFlexControllerName.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v2->flexdesc = Add_Flexdesc(name: m_pAsString);
      v4 = pDmeMouth->m_sBoneName.m_Storage.u.m_pAsString;
      if ( v4 == (const char *)-1 )
        v4 = pDeltaStateName;
      V_strncpy(pDest: v2->bonename, pSrc: v4, maxLen: 128);
      v2->forward = pDmeMouth->m_vForward.m_Storage;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004077C0
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeTransform::m_classType.u) != 0 )
  {
    return (CDmeTransform *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407810
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407850
// Name: UpdateChannels
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateChannels(
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators,
        CDmeChannelsClip *pAnimation,
        DmeTime_t clipTime)
{
  CDmeChannelsClip *v3; // ebx
  int m_Size; // esi
  int v5; // edi
  int v6; // eax
  int v7; // esi
  CDmeChannel *v8; // ecx
  int nChannelsCount; // [esp+10h] [ebp-4h]

  v3 = pAnimation;
  m_Size = pAnimation->m_Channels.m_Storage.m_Size;
  nChannelsCount = m_Size;
  CDmeClip::ToChildMediaTime(this: pAnimation, result: (DmeTime_t *)&pAnimation, t: clipTime, bClamp: true);
  v5 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v3->m_Channels.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v8 = (CDmeChannel *)(v7 - 4);
      }
      else
      {
        v8 = nullptr;
      }
      CDmeChannel::SetCurrentTime(this: v8, time: (DmeTime_t)pAnimation);
      ++v5;
    }
    while ( v5 < nChannelsCount );
  }
  LOBYTE(nChannelsCount) = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: operators);
  g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: nChannelsCount);
  g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
}

//------------------------------------------------------------------------------
// Address: 0x00407940
// Name: LoadEyeballs
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadEyeballs(s_source_t *pSource, s_model_t *pModel, CDmrElementArray<CDmElement> *elementArray)
{
  s_source_t *v3; // ebx
  CDmrElementArray<CDmElement> *v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // edi
  const char *v8; // edi
  int v9; // esi
  const char *name; // ebx
  const char *v11; // eax
  const char *v12; // ecx
  const char *v13; // edi
  const char *v14; // eax
  unsigned __int8 *v15; // ebx
  int v16; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  int v20; // eax
  int nummeshes; // ecx
  int v22; // ebx
  int *meshindex; // edx
  const char *v24; // ecx
  const char *v25; // edi
  const char *v26; // eax
  int numeyeballs; // ecx
  s_eyeball_t *v28; // esi
  const char *v29; // eax
  double v30; // xmm0_8
  int v31; // ecx
  int v32; // ebx
  int v33; // ecx
  const char **v34; // ebx
  signed int v35; // esi
  s_flexcontroller_t *v36; // edi
  int v37; // eax
  unsigned int v38; // ecx
  unsigned int v39; // eax
  long double v40; // [esp-Ch] [ebp-78h]
  matrix3x4_t mDefRot; // [esp+Ch] [ebp-60h] BYREF
  Vector vTmp; // [esp+3Ch] [ebp-30h] BYREF
  float v43[3]; // [esp+48h] [ebp-24h] BYREF
  float in1[3]; // [esp+54h] [ebp-18h] BYREF
  int i; // [esp+60h] [ebp-Ch]
  BOOL bRelative; // [esp+64h] [ebp-8h]
  int nSearchBoneIndex; // [esp+68h] [ebp-4h]
  int pSourcea; // [esp+74h] [ebp+8h]

  v3 = pSource;
  if ( pSource != nullptr && pModel != nullptr )
  {
    v4 = elementArray;
    if ( elementArray->m_pAttribute != nullptr && elementArray->m_pStorage->m_Size > 0 )
    {
      AngleMatrix(angles: &g_defaultrotation, matrix: &mDefRot);
      v5 = 0;
      i = 0;
      if ( CDmrElementArray<CDmElement>::Count(this: elementArray) > 0 )
      {
        while ( 1 )
        {
          v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v4->m_pStorage->m_Memory.m_pMemory[v5]);
          v7 = v6;
          if ( v6 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
                 a1: v6,
                 a2: CDmElement::m_classType.u) != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmeEyeball::m_classType.u) != 0 )
          {
            if ( pModel->numeyeballs < 4u )
            {
              v9 = 0;
              if ( v3->numbones <= 0 )
                goto LABEL_23;
              name = v3->localBone[0].name;
              while ( 1 )
              {
                v11 = *(const char **)(v7 + 100);
                if ( v11 == (const char *)-1 )
                  v11 = pDeltaStateName;
                if ( _V_stricmp(s1: name, s2: v11) == 0 )
                  break;
                ++v9;
                name += 132;
                if ( v9 >= pSource->numbones )
                  goto LABEL_23;
              }
              nSearchBoneIndex = v9;
              if ( v9 >= 0 )
              {
                v15 = *(unsigned __int8 **)(v7 + 92);
                if ( v15 == (unsigned __int8 *)-1 )
                  v15 = (unsigned __int8 *)pDeltaStateName;
                strchr(string: v15, chr: 0x2Fu);
                if ( v16 != 0 || (strchr(string: v15, chr: 0x5Cu), LOBYTE(bRelative) = 0, v17 != 0) )
                  LOBYTE(bRelative) = 1;
                v18 = *(const char **)(v7 + 92);
                if ( v18 == (const char *)-1 )
                  v18 = pDeltaStateName;
                v19 = LookupTexture(pTextureName: v18, bRelativePath: bRelative);
                v20 = UseTextureAsMaterial(textureindex: v19);
                nummeshes = pSource->nummeshes;
                v22 = 0;
                if ( nummeshes <= 0 )
                  goto LABEL_41;
                meshindex = pSource->meshindex;
                while ( *meshindex != v20 )
                {
                  ++v22;
                  ++meshindex;
                  if ( v22 >= nummeshes )
                    goto LABEL_41;
                }
                if ( v22 >= 0 )
                {
                  numeyeballs = pModel->numeyeballs;
                  v28 = &pModel->eyeball[numeyeballs];
                  v29 = *(const char **)(v7 + 20);
                  if ( v29 == (const char *)-1 )
                    v29 = pDeltaStateName;
                  V_strncpy(pDest: pModel->eyeball[numeyeballs].name, pSrc: v29, maxLen: 128);
                  v28->bone = nSearchBoneIndex;
                  v28->mesh = v22;
                  v28->radius = *(float *)(v7 + 68);
                  v30 = (float)(*(float *)(v7 + 76) * 0.017453292);
                  __libm_sse2_tan(x: v40);
                  *(float *)&v30 = v30;
                  v31 = nSearchBoneIndex;
                  v28->zoffset = *(float *)&v30;
                  v28->iris_scale = 1.0 / *(float *)(v7 + 84);
                  VectorITransform(in1: (const float *)(v7 + 108), in2: &pSource->boneToPose[v31], out: &v28->org.x);
                  in1[0] = 0.0;
                  in1[1] = 0.0;
                  in1[2] = 1.0;
                  VectorIRotate(in1, in2: &mDefRot, out: &vTmp.x);
                  VectorIRotate(in1: &vTmp.x, in2: &pSource->boneToPose[v28->bone], out: &v28->up.x);
                  v43[0] = 1.0;
                  v43[1] = 0.0;
                  v43[2] = 0.0;
                  VectorIRotate(in1: v43, in2: &mDefRot, out: &vTmp.x);
                  VectorIRotate(in1: &vTmp.x, in2: &pSource->boneToPose[v28->bone], out: &v28->forward.x);
                  v32 = 0;
                  v28->upperlidflexdesc = -1;
                  v28->lowerlidflexdesc = -1;
                  if ( pModel->numeyeballs <= 0 )
                  {
LABEL_52:
                    ++pModel->numeyeballs;
                  }
                  else
                  {
                    nSearchBoneIndex = (int)pModel->eyeball;
                    while ( _V_stricmp(s1: v28->name, s2: (const char *)nSearchBoneIndex) != 0 )
                    {
                      nSearchBoneIndex += 244;
                      if ( ++v32 >= pModel->numeyeballs )
                        goto LABEL_52;
                    }
                    _V_memset(dest: v28, fill: 0, count: 244);
                  }
                }
                else
                {
LABEL_41:
                  v24 = pDeltaStateName;
                  if ( *(_DWORD *)(v7 + 20) != -1 )
                    v24 = *(const char **)(v7 + 20);
                  v25 = *(const char **)(v7 + 92);
                  v26 = pDeltaStateName;
                  if ( v25 != (const char *)-1 )
                    v26 = v25;
                  MdlWarning(
                    fmt: "1102: Couldn't find eyeball material %s on model %s, ignoring eyeball %s\n",
                    v26,
                    pModel->name,
                    v24);
                }
              }
              else
              {
LABEL_23:
                v12 = pDeltaStateName;
                if ( *(_DWORD *)(v7 + 20) != -1 )
                  v12 = *(const char **)(v7 + 20);
                v13 = *(const char **)(v7 + 100);
                v14 = pDeltaStateName;
                if ( v13 != (const char *)-1 )
                  v14 = v13;
                MdlWarning(
                  fmt: "1101: Couldn't find bone %s on model %s, ignoring eyeball %s\n",
                  v14,
                  pModel->name,
                  v12);
              }
            }
            else
            {
              v8 = *(const char **)(v7 + 20);
              if ( v8 == (const char *)-1 )
                v8 = pDeltaStateName;
              MdlWarning(
                fmt: "1100: Max number of eyeballs reached for model %s, ignoring eyeball %s\n",
                pModel->name,
                v8);
            }
          }
          v4 = elementArray;
          v5 = ++i;
          if ( v5 >= CDmrElementArray<CDmElement>::Count(this: elementArray) )
            break;
          v3 = pSource;
        }
      }
      v33 = g_numflexcontrollers;
      v34 = szEyesFlexControllers;
      for ( pSourcea = 2; pSourcea != 0; --pSourcea )
      {
        v35 = 0;
        if ( v33 <= 0 )
        {
LABEL_60:
          if ( v33 < 96 )
          {
            V_strncpy(pDest: g_flexcontroller[v33].name, pSrc: *v34, maxLen: 128);
            V_strncpy(pDest: g_flexcontroller[g_numflexcontrollers].type, pSrc: "eyes", maxLen: 128);
            v38 = g_numflexcontrollers;
            v39 = g_numflexcontrollers;
            g_flexcontroller[v39].min = -45.0;
            v33 = v38 + 1;
            g_flexcontroller[v39].max = 45.0;
            g_numflexcontrollers = v33;
          }
          else
          {
            MdlWarning(fmt: "1103: Couldn't make eyes flexcontroller %s, too many flex controllers defined\n", *v34);
            v33 = g_numflexcontrollers;
          }
        }
        else
        {
          v36 = g_flexcontroller;
          while ( 1 )
          {
            v37 = _V_strcmp(s1: *v34, s2: v36->name);
            v33 = g_numflexcontrollers;
            if ( v37 == 0 )
              break;
            ++v35;
            ++v36;
            if ( v35 >= (int)g_numflexcontrollers )
              goto LABEL_60;
          }
        }
        ++v34;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407DF0
// Name: public: CDmrElementArray<class CDmElement>::CDmrElementArray<class CDmElement>(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CDmrElementArray<CDmElement> *__thiscall CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
        CDmrElementArray<CDmElement> *this,
        CDmAttribute *pAttribute)
{
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>((CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)this);
  if ( pAttribute != nullptr && (pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    this->m_pAttribute = pAttribute;
    this->m_pStorage = (DmElementArray_t *)pAttribute->m_pData;
    return this;
  }
  else
  {
    this->m_pAttribute = nullptr;
    this->m_pStorage = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407EF0
// Name: public: int const __near & CDmElement::GetValue<int>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CDmElement::GetValue<int>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<int>(this: Attribute);
  else
    return &`CDmElement::GetValue<int>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00408780
// Name: class CTwistBone __near * Construct<class CTwistBone>(class CTwistBone __near *)
// Source: json
//------------------------------------------------------------------------------
CTwistBone *__cdecl Construct<CTwistBone>(CTwistBone *pMemory)
{
  CTwistBone *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->m_twistBoneTargets.m_Memory.m_pMemory = nullptr;
  pMemory->m_twistBoneTargets.m_Memory.m_nAllocationCount = 0;
  pMemory->m_twistBoneTargets.m_Memory.m_nGrowSize = 0;
  pMemory->m_twistBoneTargets.m_Size = 0;
  pMemory->m_twistBoneTargets.m_pElements = nullptr;
  pMemory->m_bInverse = false;
  pMemory->m_vUpVector.x = 0.0;
  pMemory->m_vUpVector.y = 0.0;
  pMemory->m_vUpVector.z = 0.0;
  pMemory->m_szParentBoneName[0] = 0;
  pMemory->m_nParentBone = -1;
  pMemory->m_qBaseRotation.x = 0.0;
  pMemory->m_qBaseRotation.y = 0.0;
  pMemory->m_qBaseRotation.z = 0.0;
  pMemory->m_qBaseRotation.w = 0.0;
  pMemory->m_szChildBoneName[0] = 0;
  pMemory->m_nChildBone = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408800
// Name: void LoadModelInfo(class CDmElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadModelInfo(CDmElement *pRoot, const char *pFullPath)
{
  CDmElement *Value; // eax
  int v3; // edi
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ecx
  int v7; // eax
  int v8; // esi
  int v9; // eax
  CDmrElementArray<CDmElement> arrSources; // [esp+Ch] [ebp-8h] BYREF

  Value = CDmElement::GetValueElement<CDmElement>(this: pRoot, pAttributeName: "makefile");
  v3 = 0;
  if ( Value != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: Value, pAttributeName: "sources");
    if ( Attribute != nullptr )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&arrSources);
      if ( (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        arrSources.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
      }
      else
      {
        arrSources.m_pAttribute = nullptr;
        m_pData = nullptr;
      }
      arrSources.m_pStorage = m_pData;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( arrSources.m_pAttribute != nullptr )
            m_Size = m_pData->m_Size;
          else
            m_Size = 0;
          if ( v3 >= m_Size )
            return;
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: m_pData->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            break;
          }
LABEL_17:
          m_pData = arrSources.m_pStorage;
          ++v3;
        }
        v9 = *(_DWORD *)(v8 + 20);
        if ( v9 != -1 )
        {
          if ( v9 != 0 )
            ProcessOriginalContentFile(szDataFile: pFullPath, szOriginalContentFile: *(const char **)(v8 + 20));
          goto LABEL_17;
        }
        ProcessOriginalContentFile(szDataFile: pFullPath, szOriginalContentFile: pDeltaStateName);
        m_pData = arrSources.m_pStorage;
        ++v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004088E0
// Name: bool LoadBaseConstraintParams(class CConstraintBoneBase __near *,class CDmeRigBaseConstraintOperator __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadBaseConstraintParams(
        CConstraintBoneBase *pConstraintBone,
        CDmeRigBaseConstraintOperator *pDmeBaseConstraint)
{
  int v4; // eax
  int v5; // eax
  int v6; // edi
  s_constraintbonetarget_t *v7; // esi
  const char *m_pAsString; // eax
  int v9; // edi
  const CDmeDag *v10; // eax
  const char *v11; // eax
  Quaternion qRot; // [esp+Ch] [ebp-14h] BYREF
  CDmeDag *pDmeTargetDag; // [esp+1Ch] [ebp-4h]
  int i; // [esp+2Ch] [ebp+Ch]

  if ( pDmeBaseConstraint->m_Targets.m_Storage.m_Size <= 0 )
    return 0;
  AngleQuaternion(angles: &g_defaultrotation, outQuat: &qRot);
  v4 = 0;
  for ( i = 0; v4 < pDmeBaseConstraint->m_Targets.m_Storage.m_Size; i = v4 )
  {
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: pDmeBaseConstraint->m_Targets.m_Storage.m_Memory.m_pMemory[v4]);
    v6 = v5;
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeConstraintTarget::m_classType.u) != 0 )
    {
      pDmeTargetDag = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                                   a1: g_pDataModel.u,
                                   a2: *(_DWORD *)(v6 + 68));
      if ( pDmeTargetDag != nullptr )
      {
        v7 = &pConstraintBone->m_targets.m_Memory.m_pMemory[CUtlVector<s_constraintbonetarget_t,CUtlMemory<s_constraintbonetarget_t,int>>::AddToTail(this: &pConstraintBone->m_targets)];
        m_pAsString = pDmeTargetDag->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = pDeltaStateName;
        V_strncpy(pDest: v7->m_szBoneName, pSrc: m_pAsString, maxLen: 128);
        v7->m_nBone = -1;
        v7->m_flWeight = *(float *)(v6 + 80);
        *(_QWORD *)&v7->m_qOffset.x = *(_QWORD *)(v6 + 104);
        *(_QWORD *)&v7->m_qOffset.z = *(_QWORD *)(v6 + 112);
        if ( ((int (__thiscall *)(_DWORD, _DWORD))pDmeBaseConstraint->IsA)(
               a1: &pDmeBaseConstraint->CDmElement,
               a2: (CUtlSymbolLarge)CDmeRigPointConstraintOperator::m_classType.u.m_Id) )
        {
          VectorRotate(in1: (const Vector *)(v6 + 88), in2: &qRot, out: &v7->m_vOffset);
        }
        else
        {
          v7->m_vOffset.x = *(float *)(v6 + 88);
          v7->m_vOffset.y = *(float *)(v6 + 92);
          v7->m_vOffset.z = *(float *)(v6 + 96);
        }
      }
    }
    v4 = i + 1;
  }
  if ( pConstraintBone->m_targets.m_Size <= 0 )
    return 0;
  v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: pDmeBaseConstraint->m_Slave.m_Storage.m_Handle);
  if ( v9 == 0 )
    return 0;
  v10 = pDmeBaseConstraint->GetSlave(this: pDmeBaseConstraint);
  if ( v10 == nullptr )
    return 0;
  v11 = v10->m_Name.m_Storage.u.m_pAsString;
  if ( v11 == (const char *)-1 )
    v11 = pDeltaStateName;
  V_strncpy(pDest: pConstraintBone->m_slave.m_szBoneName, pSrc: v11, maxLen: 128);
  pConstraintBone->m_slave.m_nBone = -1;
  pConstraintBone->m_slave.m_vBaseTranslate = *(Vector *)(v9 + 80);
  pConstraintBone->m_slave.m_qBaseRotation = *(Quaternion *)(v9 + 96);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408AE0
// Name: LoadSpecializedConstraintParams_CDmeRigAimConstraintOperator_CAimConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadSpecializedConstraintParams_CDmeRigAimConstraintOperator_CAimConstraint_@<al>(
        CAimConstraint *pConstraint@<esi>,
        CDmeRigAimConstraintOperator *pDmeConstraint)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Quaternion> *v4; // eax
  CDmAttribute *v5; // eax
  CDmaVar<Vector> *v6; // eax
  CDmElement *Value; // eax
  const char *m_pAsString; // eax
  Quaternion qRot; // [esp+0h] [ebp-10h] BYREF

  AngleQuaternion(angles: &g_defaultrotation, outQuat: &qRot);
  if ( (`CDmElement::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  v2 = &pDmeConstraint->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &pDmeConstraint->CDmElement, pAttributeName: "aimOffset");
  if ( Attribute != nullptr )
    v4 = (CDmaVar<Quaternion> *)CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    v4 = &`CDmElement::GetValue<Quaternion>'::`2'::defaultVal;
  pConstraint->m_qAimOffset = v4->m_Storage;
  if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "upVector");
  if ( v5 != nullptr )
    v6 = (CDmaVar<Vector> *)CDmAttribute::GetValue<Vector>(this: v5);
  else
    v6 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
  VectorRotate(in1: &v6->m_Storage, in2: &qRot, out: &pConstraint->m_vUpVector);
  Value = CDmElement::GetValueElement<CDmElement>(this: v2, pAttributeName: "upSpaceTarget");
  if ( Value != nullptr )
  {
    m_pAsString = Value->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    V_strncpy(pDest: pConstraint->m_szUpSpaceTargetBone, pSrc: m_pAsString, maxLen: 128);
  }
  pConstraint->m_nUpSpaceTargetBone = -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408DF0
// Name: LoadAttachments
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadAttachments(CDmeDag *pRoot, CDmeDag *pDag, s_source_t *pSource, bool bStaticProp)
{
  CDmeDag *v4; // ebx
  CDmeShape *Shape; // eax
  CDmeShape *v6; // edi
  s_attachment_t *v7; // esi
  const char *m_pAsString; // eax
  const char *v9; // eax
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax

  v4 = pDag;
  Shape = CDmeDag::GetShape(this: pDag);
  v6 = Shape;
  if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeAttachment::m_classType) && pDag != pRoot )
  {
    v7 = &pSource->m_Attachments.m_Memory.m_pMemory[CUtlVector<s_attachment_t,CUtlMemory<s_attachment_t,int>>::AddToTail(this: &pSource->m_Attachments)];
    memset(dst: (unsigned __int8 *)v7, value: 0, count: sizeof(s_attachment_t));
    m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    V_strncpy(pDest: v7->name, pSrc: m_pAsString, maxLen: 128);
    v9 = pDag->m_Name.m_Storage.u.m_pAsString;
    if ( v9 == (const char *)-1 )
      v9 = pDeltaStateName;
    V_strncpy(pDest: v7->bonename, pSrc: v9, maxLen: 128);
    SetIdentityMatrix(matrix: &v7->local);
    if ( bStaticProp )
    {
      CDmeDag::GetAbsTransform(this: pDag, matAbsTransform: &v7->local);
    }
    else
    {
      if ( LOBYTE(v6[1].__vftable) != 0 )
        v7->type |= 2u;
      if ( v6[1].m_Id.m_Value[4] != 0 )
        v7->flags |= 0x10000u;
    }
    v4 = pDag;
  }
  Phase = CDmElementFramework::GetPhase(this: v4);
  for ( i = 0; i < Phase; ++i )
  {
    Child = CDmeDag::GetChild(this: v4, i);
    if ( Child != nullptr )
      LoadAttachments(pRoot, pDag: Child, pSource, bStaticProp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408F10
// Name: GetDependentOperators
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDependentOperators(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList,
        CUtlSymbolTable::StringPool_t *pDmeOperator)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v2; // edx
  int k; // edi
  CUtlSymbolTable::StringPool_t *v4; // eax
  int *v5; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // esi
  void (__thiscall *v11)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int v12; // edi
  CDmElement *m_pOwner; // esi
  void (__stdcall *v14)(CUtlSymbolLarge *, const char *); // edx
  int v15; // eax
  CExpressionCalculator *v16; // esi
  void (__stdcall *v17)(CUtlSymbolLarge *, const char *); // eax
  int m; // edi
  CDmElement *v19; // esi
  CDmeOperator *v20; // eax
  CDmAttribute **v21; // eax
  CUtlSymbolLarge v22; // [esp-Ch] [ebp-5Ch] BYREF
  BOOL v23; // [esp-8h] [ebp-58h]
  TraversalDepth_t v24; // [esp-4h] [ebp-54h]
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList0; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList1; // [esp+20h] [ebp-30h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outAttrList; // [esp+34h] [ebp-1Ch] BYREF
  CDmElement *p_m_SpaceUsed; // [esp+48h] [ebp-8h]
  int i; // [esp+4Ch] [ebp-4h]
  int j; // [esp+5Ch] [ebp+Ch]

  if ( pDmeOperator != nullptr )
  {
    p_m_SpaceUsed = (CDmElement *)&pDmeOperator->m_SpaceUsed;
    if ( pDmeOperator != (CUtlSymbolTable::StringPool_t *)-4
      && (*(unsigned __int8 (__thiscall **)(int *, CUtlSymbolLarge::<unnamed_type_u>))(pDmeOperator->m_SpaceUsed + 16))(
           a1: &pDmeOperator->m_SpaceUsed,
           a2: CDmeOperator::m_classType.u) != 0 )
    {
      v2 = operatorList;
      for ( k = 0; k < (int)v2[1].m_pMemory; ++k )
      {
        v4 = v2->m_pMemory[k];
        if ( v4 != nullptr )
        {
          v5 = &v4->m_SpaceUsed;
          if ( v4 != (CUtlSymbolTable::StringPool_t *)-4 )
          {
            if ( (*(unsigned __int8 (__thiscall **)(int *, CUtlSymbolLarge::<unnamed_type_u>))(*v5 + 16))(
                   a1: v5,
                   a2: CDmeOperator::m_classType.u) != 0
              && v5 != (int *)4
              && v5 - 1 == (int *)pDmeOperator )
            {
              return;
            }
            v2 = operatorList;
          }
        }
      }
      m_pMemory = v2[1].m_pMemory;
      m_nAllocationCount = v2->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v2, num: (int)m_pMemory - m_nAllocationCount + 1);
        v2 = operatorList;
      }
      ++v2[1].m_pMemory;
      v8 = v2->m_pMemory;
      v9 = (char *)v2[1].m_pMemory - (char *)m_pMemory - 1;
      v2[1].m_nAllocationCount = (int)v2->m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
        v2 = operatorList;
      }
      v10 = &v2->m_pMemory[(_DWORD)m_pMemory];
      if ( v10 != nullptr )
        *v10 = pDmeOperator;
      v11 = *(void (__thiscall **)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))(pDmeOperator->m_TotalLen + 16);
      memset(&outAttrList, 0, sizeof(outAttrList));
      v11(this: (struct CDmeOperator *)pDmeOperator, a2: &outAttrList);
      v12 = 0;
      for ( i = 0; v12 < outAttrList.m_Size; i = v12 )
      {
        m_pOwner = outAttrList.m_Memory.m_pMemory[v12]->m_pOwner;
        if ( m_pOwner != nullptr )
        {
          if ( m_pOwner == p_m_SpaceUsed )
          {
            v14 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
            v24 = TD_ALL;
            v23 = true;
            v22.u.m_Id = g_pDataModel.u.m_Id;
            memset(&reList0, 0, sizeof(reList0));
            v14(a1: &v22, a2: "element");
            FindReferringElements<CDmElement>(
              list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&reList0,
              pElement: (CExpressionCalculator *)m_pOwner,
              symAttrName: v22,
              bMustBeInSameFile: v23,
              depth: v24);
            v15 = 0;
            j = 0;
            if ( reList0.m_Size > 0 )
            {
              do
              {
                v16 = (CExpressionCalculator *)reList0.m_Memory.m_pMemory[v15];
                if ( v16 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v16->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v16,
                       a2: CDmeAttributeReference::m_classType.u) != 0 )
                {
                  v17 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
                  v24 = TD_ALL;
                  v23 = true;
                  v22.u.m_Id = g_pDataModel.u.m_Id;
                  memset(&reList1, 0, sizeof(reList1));
                  v17(a1: &v22, a2: "input");
                  FindReferringElements<CDmElement>(
                    list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&reList1,
                    pElement: v16,
                    symAttrName: v22,
                    bMustBeInSameFile: v23,
                    depth: v24);
                  for ( m = 0; m < reList1.m_Size; ++m )
                  {
                    v19 = reList1.m_Memory.m_pMemory[m];
                    if ( v19 != nullptr
                      && v19->IsA(this: v19, a2: CDmeConnectionOperator::m_classType)
                      && v19 != (CDmElement *)4 )
                    {
                      GetDependentOperators(
                        (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
                        pDmeOperator: (CDmeOperator *)((char *)&v19[-1] + 64));
                    }
                  }
                  if ( reList1.m_Memory.m_nGrowSize >= 0 && reList1.m_Memory.m_pMemory != nullptr )
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList1.m_Memory.m_pMemory);
                }
                v15 = j + 1;
                j = v15;
              }
              while ( v15 < reList0.m_Size );
              v12 = i;
            }
            if ( reList0.m_Memory.m_nGrowSize >= 0 && reList0.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList0.m_Memory.m_pMemory);
          }
          else
          {
            if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
              v20 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
            else
              v20 = nullptr;
            GetDependentOperators(
              (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
              pDmeOperator: v20);
          }
        }
        ++v12;
      }
      v21 = outAttrList.m_Memory.m_pMemory;
      outAttrList.m_Size = 0;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( outAttrList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outAttrList.m_Memory.m_pMemory);
          v21 = nullptr;
          outAttrList.m_Memory.m_pMemory = nullptr;
        }
        outAttrList.m_Memory.m_nAllocationCount = 0;
      }
      outAttrList.m_pElements = v21;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 && v21 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409200
// Name: PrepareChannels
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrepareChannels(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList,
        CDmeChannelsClip *pAnimation)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  CDmeChannel *v6; // ecx
  int v7; // eax
  int v8; // esi
  CUtlSymbolTable::StringPool_t *v9; // eax
  int nChannelsCount; // [esp+18h] [ebp+Ch]

  v3 = 0;
  nChannelsCount = pAnimation->m_Channels.m_Storage.m_Size;
  if ( nChannelsCount > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: pAnimation->m_Channels.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v6 = (CDmeChannel *)(v5 - 4);
      }
      else
      {
        v6 = nullptr;
      }
      CDmeChannel::SetMode(this: v6, mode: CM_PLAY);
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: pAnimation->m_Channels.m_Storage.m_Memory.m_pMemory[v3]);
      v8 = v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v9 = (CUtlSymbolTable::StringPool_t *)(v8 - 4);
      }
      else
      {
        v9 = nullptr;
      }
      GetDependentOperators(operatorList, pDmeOperator: v9);
      ++v3;
    }
    while ( v3 < nChannelsCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004092C0
// Name: FindModelIndex
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindModelIndex(s_model_t *pModel)
{
  s_model_t *v1; // edi
  int result; // eax
  int m_Size; // ecx
  s_model_t **m_pMemory; // edx
  int v5; // esi
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  int v9; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v1 = pModel;
  if ( pModel == nullptr )
    return -1;
  result = 0;
  i = 0;
  if ( g_nummodels <= 0 )
  {
LABEL_14:
    MdlWarning(fmt: "Cannot Find s_model_t: \"%s\" in g_model\n", v1->name);
    return -1;
  }
  m_Size = g_model.m_Size;
  m_pMemory = g_model.m_Memory.m_pMemory;
  v5 = 1;
  v9 = 1;
  while ( 1 )
  {
    if ( m_Size < v5 )
    {
      v6 = v5 - m_Size;
      v7 = m_Size;
      if ( v6 != 0 )
      {
        v8 = m_Size + v6;
        if ( m_Size + v6 > g_model.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
            num: v6 + m_Size - g_model.m_Memory.m_nAllocationCount);
          m_Size = g_model.m_Size;
          m_pMemory = g_model.m_Memory.m_pMemory;
        }
        m_Size += v6;
        g_model.m_Size = m_Size;
        g_model.m_pElements = m_pMemory;
        if ( m_Size - v7 - v6 > 0 && v6 > 0 )
        {
          _V_memmove(dest: &m_pMemory[v8], src: &m_pMemory[v7], count: 4 * (m_Size - v7 - v6));
          m_Size = g_model.m_Size;
          m_pMemory = g_model.m_Memory.m_pMemory;
        }
        result = i;
      }
    }
    v1 = pModel;
    if ( m_pMemory[result] == pModel )
      return result;
    ++result;
    v5 = v9 + 1;
    i = result;
    ++v9;
    if ( result >= g_nummodels )
      goto LABEL_14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004095D0
// Name: LoadEyelid
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadEyelid(s_model_t *pModel, CDmeEyelid *pDmeEyelid)
{
  s_source_t *source; // edi
  const char *m_pAsString; // eax
  const s_sourceanim_t *NewStyleSourceVertexAnim; // eax
  float m_Storage; // xmm0_4
  const char *v7; // eax
  const s_sourceanim_t *v8; // eax
  float v9; // xmm0_4
  const char *v10; // eax
  const s_sourceanim_t *v11; // eax
  float v12; // xmm0_4
  const char *v13; // edi
  int *v14; // esi
  const char *v15; // eax
  const char *v16; // edi
  LoadEyelid::__l6::EyelidData_t *v17; // esi
  int k; // ebx
  const char *v19; // eax
  int v20; // eax
  bool v21; // sf
  EyelidType_t v22; // esi
  const char **p_m_pSourceAnim; // edi
  bool v24; // cc
  s_eyeball_t *eyeball; // esi
  const char *v26; // eax
  int v27; // ebx
  const char *v28; // eax
  float *p_m_flTarget; // edi
  float radius; // xmm1_4
  const char *v31; // eax
  float m_flTarget; // xmm0_4
  int v33; // eax
  int v34; // ecx
  int v35; // edx
  float v36; // xmm0_4
  int v37; // ecx
  int v38; // edx
  int v39; // eax
  float v40; // xmm0_4
  const char *v41; // eax
  const char *v42; // eax
  LoadEyelid::__l6::EyelidData_t eyelidData[3]; // [esp+2Ch] [ebp-60h] BYREF
  CUtlString sLeftLocalDesc; // [esp+68h] [ebp-24h] BYREF
  int nRightLeftBaseDesc[2]; // [esp+78h] [ebp-14h]
  int i; // [esp+80h] [ebp-Ch]
  int j; // [esp+84h] [ebp-8h]
  bool bLeftOk; // [esp+89h] [ebp-3h]
  bool bRightOk; // [esp+8Ah] [ebp-2h]
  bool bUpper; // [esp+8Bh] [ebp-1h]

  if ( pModel == nullptr || pDmeEyelid == nullptr )
    return 0;
  source = pModel->source;
  i = (int)source;
  if ( source == nullptr )
    return 0;
  bUpper = pDmeEyelid->m_bUpper.m_Storage;
  m_pAsString = pDmeEyelid->m_sLowererFlex.m_Storage.u.m_pAsString;
  eyelidData[0].m_nFlexDesc[0] = -1;
  eyelidData[0].m_nFlexDesc[1] = -1;
  eyelidData[0].m_pszSuffix = "lowerer";
  eyelidData[1].m_nFlexDesc[0] = -1;
  eyelidData[1].m_nFlexDesc[1] = -1;
  eyelidData[1].m_pszSuffix = "neutral";
  eyelidData[2].m_nFlexDesc[0] = -1;
  eyelidData[2].m_nFlexDesc[1] = -1;
  eyelidData[2].m_pszSuffix = "raiser";
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  NewStyleSourceVertexAnim = GetNewStyleSourceVertexAnim(pSource: source, pszVertexAnimName: m_pAsString);
  m_Storage = pDmeEyelid->m_flLowererHeight.m_Storage;
  eyelidData[0].m_pSourceAnim = NewStyleSourceVertexAnim;
  v7 = pDmeEyelid->m_sNeutralFlex.m_Storage.u.m_pAsString;
  eyelidData[0].m_flTarget = m_Storage;
  if ( v7 == (const char *)-1 )
    v7 = pDeltaStateName;
  v8 = GetNewStyleSourceVertexAnim(pSource: source, pszVertexAnimName: v7);
  v9 = pDmeEyelid->m_flNeutralHeight.m_Storage;
  eyelidData[1].m_pSourceAnim = v8;
  v10 = pDmeEyelid->m_sRaiserFlex.m_Storage.u.m_pAsString;
  eyelidData[1].m_flTarget = v9;
  if ( v10 == (const char *)-1 )
    v10 = pDeltaStateName;
  v11 = GetNewStyleSourceVertexAnim(pSource: source, pszVertexAnimName: v10);
  v12 = pDmeEyelid->m_flRaiserHeight.m_Storage;
  eyelidData[2].m_pSourceAnim = v11;
  eyelidData[2].m_flTarget = v12;
  v13 = "upper_right";
  if ( !bUpper )
    v13 = "lower_right";
  nRightLeftBaseDesc[1] = Add_Flexdesc(name: v13);
  v14 = &eyelidData[0].m_nFlexDesc[1];
  for ( j = 3; j != 0; --j )
  {
    CUtlString::CUtlString(this: &sLeftLocalDesc, pString: v13);
    CUtlString::operator+=(this: &sLeftLocalDesc, rhs: "_");
    CUtlString::operator+=(this: &sLeftLocalDesc, rhs: (const char *)v14[3]);
    v15 = CUtlString::Get(this: &sLeftLocalDesc);
    *v14 = Add_Flexdesc(name: v15);
    sLeftLocalDesc.m_Storage.m_nActualLength = 0;
    if ( sLeftLocalDesc.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( sLeftLocalDesc.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sLeftLocalDesc.m_Storage.m_Memory.m_pMemory);
        sLeftLocalDesc.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      sLeftLocalDesc.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v14 += 5;
  }
  v16 = "upper_left";
  if ( !bUpper )
    v16 = "lower_left";
  nRightLeftBaseDesc[0] = Add_Flexdesc(name: v16);
  v17 = eyelidData;
  for ( k = 3; k != 0; --k )
  {
    CUtlString::CUtlString(this: &sLeftLocalDesc, pString: v16);
    CUtlString::operator+=(this: &sLeftLocalDesc, rhs: "_");
    CUtlString::operator+=(this: &sLeftLocalDesc, rhs: v17->m_pszSuffix);
    v19 = CUtlString::Get(this: &sLeftLocalDesc);
    v20 = Add_Flexdesc(name: v19);
    v21 = sLeftLocalDesc.m_Storage.m_Memory.m_nGrowSize < 0;
    v17->m_nFlexDesc[0] = v20;
    sLeftLocalDesc.m_Storage.m_nActualLength = 0;
    if ( !v21 )
    {
      if ( sLeftLocalDesc.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sLeftLocalDesc.m_Storage.m_Memory.m_pMemory);
        sLeftLocalDesc.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      sLeftLocalDesc.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    ++v17;
  }
  v22 = kLowerer;
  p_m_pSourceAnim = (const char **)&eyelidData[0].m_pSourceAnim;
  do
  {
    if ( !AddFlexKey(
            pSource: (s_source_t *)i,
            pModel,
            pszAnimationName: *p_m_pSourceAnim,
            nFlexDesc: nRightLeftBaseDesc[0],
            nFlexPair: nRightLeftBaseDesc[1],
            nEyelidType: v22,
            flLowererHeight: eyelidData[0].m_flTarget,
            flNeutralHeight: eyelidData[1].m_flTarget,
            flRaiserHeight: eyelidData[2].m_flTarget,
            flSplit: 0.0,
            flDecay: 1.0,
            nFrame: 0) )
      return 0;
    ++v22;
    p_m_pSourceAnim += 5;
  }
  while ( v22 < kEyelidTypeCount );
  v24 = pModel->numeyeballs <= 0;
  bRightOk = false;
  bLeftOk = false;
  i = 0;
  if ( v24 )
    goto LABEL_53;
  eyeball = pModel->eyeball;
  do
  {
    if ( eyeball == nullptr )
      goto LABEL_51;
    v26 = pDmeEyelid->m_sRightEyeballName.m_Storage.u.m_pAsString;
    if ( v26 == (const char *)-1 )
      v26 = pDeltaStateName;
    if ( _V_stricmp(s1: v26, s2: eyeball->name) != 0 )
    {
      v28 = pDmeEyelid->m_sLeftEyeballName.m_Storage.u.m_pAsString;
      if ( v28 == (const char *)-1 )
        v28 = pDeltaStateName;
      if ( _V_stricmp(s1: v28, s2: eyeball->name) != 0 )
      {
        MdlWarning(fmt: "Unknown Eyeball: %s\n", eyeball->name);
        goto LABEL_51;
      }
      v27 = 0;
      bLeftOk = true;
    }
    else
    {
      v27 = 1;
      bRightOk = true;
    }
    p_m_flTarget = &eyelidData[0].m_flTarget;
    for ( j = 3; j != 0; --j )
    {
      radius = eyeball->radius;
      if ( COERCE_FLOAT(*(_DWORD *)p_m_flTarget & _mask__AbsFloat_) > radius )
      {
        v31 = "upper";
        if ( !bUpper )
          v31 = "lower";
        MdlError(
          fmt: "Eyelid \"%s\" %s %.1f out of range (+-%.1f)\n",
          v31,
          *((const char **)p_m_flTarget + 1),
          *p_m_flTarget,
          radius);
      }
      p_m_flTarget += 5;
    }
    m_flTarget = eyelidData[0].m_flTarget;
    if ( bUpper )
    {
      v33 = eyelidData[0].m_nFlexDesc[v27];
      v34 = eyelidData[1].m_nFlexDesc[v27];
      eyeball->upperlidflexdesc = nRightLeftBaseDesc[v27];
      v35 = eyelidData[2].m_nFlexDesc[v27];
      eyeball->uppertarget[0] = m_flTarget;
      eyeball->uppertarget[1] = eyelidData[1].m_flTarget;
      v36 = eyelidData[2].m_flTarget;
      eyeball->upperflexdesc[0] = v33;
      eyeball->upperflexdesc[1] = v34;
      eyeball->upperflexdesc[2] = v35;
      eyeball->uppertarget[2] = v36;
    }
    else
    {
      v37 = eyelidData[0].m_nFlexDesc[v27];
      v38 = eyelidData[1].m_nFlexDesc[v27];
      eyeball->lowerlidflexdesc = nRightLeftBaseDesc[v27];
      v39 = eyelidData[2].m_nFlexDesc[v27];
      eyeball->lowertarget[0] = m_flTarget;
      eyeball->lowertarget[1] = eyelidData[1].m_flTarget;
      v40 = eyelidData[2].m_flTarget;
      eyeball->lowerflexdesc[0] = v37;
      eyeball->lowerflexdesc[1] = v38;
      eyeball->lowerflexdesc[2] = v39;
      eyeball->lowertarget[2] = v40;
    }
LABEL_51:
    ++eyeball;
    ++i;
  }
  while ( i < pModel->numeyeballs );
  if ( !bRightOk )
  {
LABEL_53:
    v41 = pDmeEyelid->m_sRightEyeballName.m_Storage.u.m_pAsString;
    if ( v41 == (const char *)-1 )
      v41 = pDeltaStateName;
    MdlError(fmt: "Could not find right eye \"%s\"\n", v41);
  }
  if ( !bLeftOk )
  {
    v42 = pDmeEyelid->m_sLeftEyeballName.m_Storage.u.m_pAsString;
    if ( v42 == (const char *)-1 )
      v42 = pDeltaStateName;
    MdlError(fmt: "Could not find left eye \"%s\"\n", v42);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409A60
// Name: void LoadQcModelElements(struct s_source_t __near *,struct s_model_t __near *,class CDmeModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadQcModelElements(s_source_t *pSource, s_model_t *pModel, CDmeModel *pDmeModel)
{
  CDmAttribute *Attribute; // eax
  int i; // edi
  DmElementArray_t *m_pStorage; // eax
  int v6; // ecx
  int v7; // eax
  CDmeEyelid *v8; // esi
  int j; // ebx
  int v10; // ecx
  int v11; // eax
  CDmeMouth *v12; // esi
  CDmrElementArray<CDmElement> qcModelElements; // [esp+Ch] [ebp-8h] BYREF

  if ( pModel != nullptr && pDmeModel != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pDmeModel, pAttributeName: "qcModelElements");
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(this: &qcModelElements, pAttribute: Attribute);
      LoadEyeballs(pSource, pModel, elementArray: &qcModelElements);
      for ( i = 0; ; ++i )
      {
        m_pStorage = qcModelElements.m_pStorage;
        v6 = qcModelElements.m_pAttribute != nullptr ? qcModelElements.m_pStorage->m_Size : 0;
        if ( i >= v6 )
          break;
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: qcModelElements.m_pStorage->m_Memory.m_pMemory[i]);
        v8 = (CDmeEyelid *)v7;
        if ( v7 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmElement::m_classType.u) == 0
          || !v8->IsA(this: v8, a2: CDmeEyelid::m_classType) )
        {
          v8 = nullptr;
        }
        LoadEyelid(pModel, pDmeEyelid: v8);
      }
      for ( j = 0; ; ++j )
      {
        v10 = qcModelElements.m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
        if ( j >= v10 )
          break;
        v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: m_pStorage->m_Memory.m_pMemory[j]);
        v12 = (CDmeMouth *)v11;
        if ( v11 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: CDmElement::m_classType.u) == 0
          || !v12->IsA(this: v12, a2: CDmeMouth::m_classType) )
        {
          v12 = nullptr;
        }
        LoadMouth(pDmeMouth: v12);
        m_pStorage = qcModelElements.m_pStorage;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409E20
// Name: LoadConstraint_CDmeRigPointConstraintOperator_CPointConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadConstraint_CDmeRigPointConstraintOperator_CPointConstraint_@<al>(CDmElement *pDmElement@<eax>)
{
  CDmeRigBaseConstraintOperator *v3; // esi
  CConstraintBoneBase *v4; // eax
  const CConstraintBoneBase *v5; // edi
  int m_Size; // eax
  int v7; // esi
  CConstraintBoneBase **m_pMemory; // ecx
  int v9; // eax
  const CConstraintBoneBase **v10; // eax

  if ( g_constraintBones.m_Size == 256 )
    MdlError(fmt: "Too Many Constraint Bones, Max: %d\n", 256);
  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigPointConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v3 = (CDmeRigBaseConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( v3 == nullptr )
    return 0;
  v4 = (CConstraintBoneBase *)MemAlloc_Alloc(nSize: 0xB8u);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v4->m_targets.m_Memory.m_pMemory = nullptr;
  v4->m_targets.m_Memory.m_nAllocationCount = 0;
  v4->m_targets.m_Memory.m_nGrowSize = 0;
  v4->m_targets.m_Size = 0;
  v4->m_targets.m_pElements = nullptr;
  v4->__vftable = (CConstraintBoneBase_vtbl *)&CPointConstraint::`vftable';
  if ( LoadBaseConstraintParams(pConstraintBone: v4, pDmeBaseConstraint: v3) != 0 )
  {
    if ( FindDuplicateConstraint(pConstraintA: v5) )
    {
      ((void (__thiscall *)(const CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
      return 1;
    }
    else
    {
      m_Size = g_constraintBones.m_Size;
      v7 = g_constraintBones.m_Size;
      if ( g_constraintBones.m_Size + 1 > g_constraintBones.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_constraintBones,
          num: g_constraintBones.m_Size - g_constraintBones.m_Memory.m_nAllocationCount + 1);
        m_Size = g_constraintBones.m_Size;
      }
      m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      g_constraintBones.m_Size = m_Size + 1;
      v9 = m_Size - v7;
      g_constraintBones.m_pElements = g_constraintBones.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(
          dest: &g_constraintBones.m_Memory.m_pMemory[v7 + 1],
          src: &g_constraintBones.m_Memory.m_pMemory[v7],
          count: 4 * v9);
        m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      }
      v10 = (const CConstraintBoneBase **)&m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = v5;
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(const CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409F40
// Name: LoadConstraint_CDmeRigOrientConstraintOperator_COrientConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadConstraint_CDmeRigOrientConstraintOperator_COrientConstraint_@<al>(CDmElement *pDmElement@<eax>)
{
  CDmeRigBaseConstraintOperator *v3; // esi
  CConstraintBoneBase *v4; // eax
  const CConstraintBoneBase *v5; // edi
  int m_Size; // eax
  int v7; // esi
  CConstraintBoneBase **m_pMemory; // ecx
  int v9; // eax
  const CConstraintBoneBase **v10; // eax

  if ( g_constraintBones.m_Size == 256 )
    MdlError(fmt: "Too Many Constraint Bones, Max: %d\n", 256);
  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigOrientConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v3 = (CDmeRigBaseConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( v3 == nullptr )
    return 0;
  v4 = (CConstraintBoneBase *)MemAlloc_Alloc(nSize: 0xB8u);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v4->m_targets.m_Memory.m_pMemory = nullptr;
  v4->m_targets.m_Memory.m_nAllocationCount = 0;
  v4->m_targets.m_Memory.m_nGrowSize = 0;
  v4->m_targets.m_Size = 0;
  v4->m_targets.m_pElements = nullptr;
  v4->__vftable = (CConstraintBoneBase_vtbl *)&COrientConstraint::`vftable';
  if ( LoadBaseConstraintParams(pConstraintBone: v4, pDmeBaseConstraint: v3) != 0 )
  {
    if ( FindDuplicateConstraint(pConstraintA: v5) )
    {
      ((void (__thiscall *)(const CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
      return 1;
    }
    else
    {
      m_Size = g_constraintBones.m_Size;
      v7 = g_constraintBones.m_Size;
      if ( g_constraintBones.m_Size + 1 > g_constraintBones.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_constraintBones,
          num: g_constraintBones.m_Size - g_constraintBones.m_Memory.m_nAllocationCount + 1);
        m_Size = g_constraintBones.m_Size;
      }
      m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      g_constraintBones.m_Size = m_Size + 1;
      v9 = m_Size - v7;
      g_constraintBones.m_pElements = g_constraintBones.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(
          dest: &g_constraintBones.m_Memory.m_pMemory[v7 + 1],
          src: &g_constraintBones.m_Memory.m_pMemory[v7],
          count: 4 * v9);
        m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      }
      v10 = (const CConstraintBoneBase **)&m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = v5;
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(const CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A060
// Name: LoadConstraint_CDmeRigAimConstraintOperator_CAimConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadConstraint_CDmeRigAimConstraintOperator_CAimConstraint_@<al>(CDmElement *pDmElement@<eax>)
{
  CDmeRigAimConstraintOperator *v3; // edi
  CAimConstraint *v4; // eax
  CAimConstraint *v5; // esi
  int m_Size; // eax
  int v7; // edi
  CConstraintBoneBase **m_pMemory; // ecx
  int v9; // eax
  CAimConstraint **v10; // eax

  if ( g_constraintBones.m_Size == 256 )
    MdlError(fmt: "Too Many Constraint Bones, Max: %d\n", 256);
  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigAimConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v3 = (CDmeRigAimConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( pDmElement == (CDmElement *)4 )
    return 0;
  v4 = (CAimConstraint *)MemAlloc_Alloc(nSize: 0x158u);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v4->m_targets.m_Memory.m_pMemory = nullptr;
  v4->m_targets.m_Memory.m_nAllocationCount = 0;
  v4->m_targets.m_Memory.m_nGrowSize = 0;
  v4->m_targets.m_Size = 0;
  v4->m_targets.m_pElements = nullptr;
  v4->__vftable = (CAimConstraint_vtbl *)&CAimConstraint::`vftable';
  v4->m_nUpSpaceTargetBone = -1;
  if ( LoadBaseConstraintParams(pConstraintBone: v4, pDmeBaseConstraint: v3) != 0
    && LoadSpecializedConstraintParams_CDmeRigAimConstraintOperator_CAimConstraint_(pConstraint: v5, pDmeConstraint: v3) != 0 )
  {
    if ( FindDuplicateConstraint(pConstraintA: v5) )
    {
      ((void (__thiscall *)(CAimConstraint *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
      return 1;
    }
    else
    {
      m_Size = g_constraintBones.m_Size;
      v7 = g_constraintBones.m_Size;
      if ( g_constraintBones.m_Size + 1 > g_constraintBones.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_constraintBones,
          num: g_constraintBones.m_Size - g_constraintBones.m_Memory.m_nAllocationCount + 1);
        m_Size = g_constraintBones.m_Size;
      }
      m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      g_constraintBones.m_Size = m_Size + 1;
      v9 = m_Size - v7;
      g_constraintBones.m_pElements = g_constraintBones.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(
          dest: &g_constraintBones.m_Memory.m_pMemory[v7 + 1],
          src: &g_constraintBones.m_Memory.m_pMemory[v7],
          count: 4 * v9);
        m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      }
      v10 = (CAimConstraint **)&m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = v5;
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(CAimConstraint *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A190
// Name: LoadConstraint_CDmeRigParentConstraintOperator_CParentConstraint_
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadConstraint_CDmeRigParentConstraintOperator_CParentConstraint_@<al>(CDmElement *pDmElement@<eax>)
{
  CDmeRigBaseConstraintOperator *v3; // esi
  CConstraintBoneBase *v4; // eax
  const CConstraintBoneBase *v5; // edi
  int m_Size; // eax
  int v7; // esi
  CConstraintBoneBase **m_pMemory; // ecx
  int v9; // eax
  const CConstraintBoneBase **v10; // eax

  if ( g_constraintBones.m_Size == 256 )
    MdlError(fmt: "Too Many Constraint Bones, Max: %d\n", 256);
  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigParentConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v3 = (CDmeRigBaseConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( v3 == nullptr )
    return 0;
  v4 = (CConstraintBoneBase *)MemAlloc_Alloc(nSize: 0xB8u);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v4->m_targets.m_Memory.m_pMemory = nullptr;
  v4->m_targets.m_Memory.m_nAllocationCount = 0;
  v4->m_targets.m_Memory.m_nGrowSize = 0;
  v4->m_targets.m_Size = 0;
  v4->m_targets.m_pElements = nullptr;
  v4->__vftable = (CConstraintBoneBase_vtbl *)&CParentConstraint::`vftable';
  if ( LoadBaseConstraintParams(pConstraintBone: v4, pDmeBaseConstraint: v3) != 0 )
  {
    if ( FindDuplicateConstraint(pConstraintA: v5) )
    {
      ((void (__thiscall *)(const CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
      return 1;
    }
    else
    {
      m_Size = g_constraintBones.m_Size;
      v7 = g_constraintBones.m_Size;
      if ( g_constraintBones.m_Size + 1 > g_constraintBones.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_constraintBones,
          num: g_constraintBones.m_Size - g_constraintBones.m_Memory.m_nAllocationCount + 1);
        m_Size = g_constraintBones.m_Size;
      }
      m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      g_constraintBones.m_Size = m_Size + 1;
      v9 = m_Size - v7;
      g_constraintBones.m_pElements = g_constraintBones.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(
          dest: &g_constraintBones.m_Memory.m_pMemory[v7 + 1],
          src: &g_constraintBones.m_Memory.m_pMemory[v7],
          count: 4 * v9);
        m_pMemory = g_constraintBones.m_Memory.m_pMemory;
      }
      v10 = (const CConstraintBoneBase **)&m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = v5;
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(const CConstraintBoneBase *, int))v5->dtr_CConstraintBoneBase)(a1: v5, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A350
// Name: FindOrAddDeltaState
// Source: json
//------------------------------------------------------------------------------
DeltaState_t *__cdecl FindOrAddDeltaState(const char *pDeltaStateName, int nBaseStateVertexCount)
{
  int m_Size; // eax
  int v3; // esi
  int v4; // edi
  const char *v5; // eax
  unsigned int v6; // edi
  DeltaState_t *m_pMemory; // ecx
  int v8; // eax
  unsigned int v9; // edi
  DeltaState_t *v10; // esi
  CUtlVector<DeltaIndex_t,CUtlMemory<DeltaIndex_t,int> > *p_m_DeltaIndices; // ecx
  int v13; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  m_Size = s_DeltaStates.m_Size;
  v3 = 0;
  nCount = s_DeltaStates.m_Size;
  if ( s_DeltaStates.m_Size <= 0 )
  {
LABEL_6:
    v6 = m_Size;
    if ( m_Size + 1 > s_DeltaStates.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<DeltaState_t,int>::Grow(
        this: &s_DeltaStates.m_Memory,
        num: m_Size - s_DeltaStates.m_Memory.m_nAllocationCount + 1);
      m_Size = s_DeltaStates.m_Size;
    }
    m_pMemory = s_DeltaStates.m_Memory.m_pMemory;
    s_DeltaStates.m_Size = m_Size + 1;
    v8 = m_Size - v6;
    s_DeltaStates.m_pElements = s_DeltaStates.m_Memory.m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(
        dest: &s_DeltaStates.m_Memory.m_pMemory[v6 + 1],
        src: &s_DeltaStates.m_Memory.m_pMemory[v6],
        count: 104 * v8);
      m_pMemory = s_DeltaStates.m_Memory.m_pMemory;
    }
    v9 = v6;
    v10 = &m_pMemory[v9];
    if ( &m_pMemory[v9] != nullptr )
    {
      CUtlString::CUtlString(this: &m_pMemory[v9].m_Name);
      v10->m_PositionDeltas.m_Memory.m_pMemory = nullptr;
      v10->m_PositionDeltas.m_Memory.m_nAllocationCount = 0;
      v10->m_PositionDeltas.m_Memory.m_nGrowSize = 0;
      v10->m_PositionDeltas.m_Size = 0;
      v10->m_PositionDeltas.m_pElements = nullptr;
      v10->m_NormalDeltas.m_Memory.m_pMemory = nullptr;
      v10->m_NormalDeltas.m_Memory.m_nAllocationCount = 0;
      v10->m_NormalDeltas.m_Memory.m_nGrowSize = 0;
      v10->m_NormalDeltas.m_Size = 0;
      v10->m_NormalDeltas.m_pElements = nullptr;
      v10->m_WrinkleDeltas.m_Memory.m_pMemory = nullptr;
      v10->m_WrinkleDeltas.m_Memory.m_nAllocationCount = 0;
      v10->m_WrinkleDeltas.m_Memory.m_nGrowSize = 0;
      v10->m_WrinkleDeltas.m_Size = 0;
      v10->m_WrinkleDeltas.m_pElements = nullptr;
      v10->m_DeltaIndices.m_Memory.m_pMemory = nullptr;
      v10->m_DeltaIndices.m_Memory.m_nAllocationCount = 0;
      v10->m_DeltaIndices.m_Memory.m_nGrowSize = 0;
      v10->m_DeltaIndices.m_Size = 0;
      v10->m_DeltaIndices.m_pElements = nullptr;
      v10->m_nDeltaCount = 0;
      v10->m_nFirstDelta = -1;
      m_pMemory = s_DeltaStates.m_Memory.m_pMemory;
    }
    CUtlString::operator=(this: &m_pMemory[v9].m_Name, src: pDeltaStateName);
    p_m_DeltaIndices = &s_DeltaStates.m_Memory.m_pMemory[v9].m_DeltaIndices;
    p_m_DeltaIndices->m_Size = 0;
    CUtlVector<DeltaIndex_t,CUtlMemory<DeltaIndex_t,int>>::InsertMultipleBefore(
      this: p_m_DeltaIndices,
      elem: 0,
      num: nBaseStateVertexCount);
    return &s_DeltaStates.m_Memory.m_pMemory[v9];
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = CUtlString::operator char const *(this: &s_DeltaStates.m_Memory.m_pMemory[v4].m_Name);
      if ( _V_stricmp(s1: v5, s2: pDeltaStateName) == 0 )
        break;
      ++v3;
      ++v4;
      if ( v3 >= nCount )
      {
        m_Size = s_DeltaStates.m_Size;
        goto LABEL_6;
      }
    }
    MdlWarning(fmt: "Unsupported duplicate delta state named \"%s\" in DMX file\n", pDeltaStateName);
    v13 = v3;
    if ( s_DeltaStates.m_Memory.m_pMemory[v13].m_DeltaIndices.m_Size < nBaseStateVertexCount )
      CUtlVector<DeltaIndex_t,CUtlMemory<DeltaIndex_t,int>>::InsertMultipleBefore(
        this: &s_DeltaStates.m_Memory.m_pMemory[v13].m_DeltaIndices,
        elem: s_DeltaStates.m_Memory.m_pMemory[v13].m_DeltaIndices.m_Size,
        num: nBaseStateVertexCount - s_DeltaStates.m_Memory.m_pMemory[v13].m_DeltaIndices.m_Size);
    return &s_DeltaStates.m_Memory.m_pMemory[v13];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A4D0
// Name: LoadDeltaState
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadDeltaState@<al>(
        CDmeVertexDeltaData *pDeltaState@<eax>,
        int nStartingUniqueVertex@<edx>,
        CDmeVertexData *pBindState,
        const matrix3x4_t *mat,
        float flScale,
        int nStartingUniqueVertexMap)
{
  const char *m_pAsString; // ecx
  DeltaState_t *v8; // esi
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *VertexIndexData; // eax
  int v10; // ecx
  const char *v11; // edi
  const char *v12; // edi
  const char *v13; // edi
  int v14; // edi
  int m_Size; // eax
  int v16; // eax
  int *m_pMemory; // edx
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndicesFromDataIndex; // ecx
  int v19; // edx
  int v20; // eax
  int v21; // edi
  DeltaIndex_t *v22; // ecx
  int v23; // edx
  int v24; // eax
  int m_nAllocationCount; // ecx
  Vector *v26; // edx
  int v27; // ecx
  Vector *v28; // eax
  const CUtlVector<int,CUtlMemory<int,int> > *v29; // ecx
  int v30; // edx
  int v31; // eax
  int v32; // edi
  DeltaIndex_t *v33; // ecx
  int v34; // edx
  int v35; // ecx
  const CUtlVector<int,CUtlMemory<int,int> > *v36; // eax
  float *v37; // edx
  int v38; // ecx
  float *v39; // eax
  const CUtlVector<int,CUtlMemory<int,int> > *v40; // ecx
  int v41; // edx
  int v42; // eax
  int v43; // edi
  DeltaIndex_t *v44; // ecx
  int v45; // edx
  matrix3x4_t normalMat; // [esp+Ch] [ebp-6Ch] BYREF
  Vector vecDelta; // [esp+3Ch] [ebp-3Ch] BYREF
  float *v49; // [esp+48h] [ebp-30h]
  int nBaseVertCount; // [esp+4Ch] [ebp-2Ch]
  int nPositionIndex; // [esp+50h] [ebp-28h]
  const CUtlVector<int,CUtlMemory<int,int> > *baseVerts; // [esp+54h] [ebp-24h]
  const CUtlVector<int,CUtlMemory<int,int> > *wrinkleIndices; // [esp+58h] [ebp-20h]
  const CUtlVector<int,CUtlMemory<int,int> > *normalIndices; // [esp+5Ch] [ebp-1Ch]
  int nCount; // [esp+60h] [ebp-18h]
  const CUtlVector<float,CUtlMemory<float,int> > *wrinkle; // [esp+64h] [ebp-14h]
  const CUtlVector<int,CUtlMemory<int,int> > *positionIndices; // [esp+68h] [ebp-10h]
  int i; // [esp+6Ch] [ebp-Ch]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *normals; // [esp+70h] [ebp-8h]
  int j; // [esp+74h] [ebp-4h]

  m_pAsString = pDeltaState->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  v8 = FindOrAddDeltaState(
         pDeltaStateName: m_pAsString,
         nBaseStateVertexCount: nStartingUniqueVertex + pBindState->m_nVertexCount);
  MatrixInverseTranspose(src: mat, dst: &normalMat);
  nCount = (int)CDmeVertexDataBase::GetPositionData(this: pDeltaState);
  positionIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                    this: pDeltaState,
                                                                    fieldId: FIELD_POSITION);
  normals = CDmeVertexDataBase::GetNormalData(this: pDeltaState);
  normalIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                  this: pDeltaState,
                                                                  fieldId: FIELD_NORMAL);
  wrinkle = CDmeVertexDataBase::GetWrinkleData(this: pDeltaState);
  VertexIndexData = CDmeVertexDataBase::GetVertexIndexData(this: pDeltaState, fieldId: FIELD_WRINKLE);
  v10 = *(_DWORD *)(nCount + 12);
  wrinkleIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)VertexIndexData;
  v49 = (float *)v10;
  if ( v10 != positionIndices->m_Size )
  {
    v11 = pDeltaState->m_Name.m_Storage.u.m_pAsString;
    if ( v11 == (const char *)-1 )
      v11 = pDeltaStateName;
    MdlError(fmt: "DeltaState %s contains a different number of positions + position indices!\n", v11);
  }
  if ( normals->m_Size != normalIndices->m_Size )
  {
    v12 = pDeltaState->m_Name.m_Storage.u.m_pAsString;
    if ( v12 == (const char *)-1 )
      v12 = pDeltaStateName;
    MdlError(fmt: "DeltaState %s contains a different number of normals + normal indices!\n", v12);
  }
  if ( wrinkle->m_Size != wrinkleIndices->m_Size )
  {
    v13 = pDeltaState->m_Name.m_Storage.u.m_pAsString;
    if ( v13 == (const char *)-1 )
      v13 = pDeltaStateName;
    MdlError(fmt: "DeltaState %s contains a different number of wrinkles + wrinkle indices!\n", v13);
  }
  v14 = 0;
  i = 0;
  if ( v10 > 0 )
  {
    j = 0;
    do
    {
      VectorRotate(in1: (const float *)(j + *(_DWORD *)nCount), in2: mat, out: &vecDelta.x);
      m_Size = v8->m_PositionDeltas.m_Size;
      vecDelta.x = vecDelta.x * flScale;
      vecDelta.y = vecDelta.y * flScale;
      vecDelta.z = vecDelta.z * flScale;
      v16 = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
              this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&v8->m_PositionDeltas,
              elem: m_Size,
              src: (const QAngle *)&vecDelta);
      m_pMemory = positionIndices->m_Memory.m_pMemory;
      nPositionIndex = v16;
      VertexIndicesFromDataIndex = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                                     this: pBindState,
                                     fieldId: FIELD_POSITION,
                                     nDataIndex: m_pMemory[v14]);
      v19 = VertexIndicesFromDataIndex->m_Size;
      v20 = 0;
      baseVerts = VertexIndicesFromDataIndex;
      nBaseVertCount = v19;
      if ( v19 > 0 )
      {
        while ( 1 )
        {
          v21 = s_UniqueVerticesMap.m_Memory.m_pMemory[nStartingUniqueVertexMap
                                                     + VertexIndicesFromDataIndex->m_Memory.m_pMemory[v20]];
          v22 = v8->m_DeltaIndices.m_Memory.m_pMemory;
          v23 = v21;
          if ( !v22[v21].m_bInList )
          {
            v22[v23].m_nNextDelta = v8->m_nFirstDelta;
            ++v8->m_nDeltaCount;
            v8->m_nFirstDelta = v21;
            v22[v23].m_bInList = true;
          }
          ++v20;
          v8->m_DeltaIndices.m_Memory.m_pMemory[v23].m_nPositionIndex = nPositionIndex;
          if ( v20 >= nBaseVertCount )
            break;
          VertexIndicesFromDataIndex = baseVerts;
        }
        v14 = i;
      }
      j += 12;
      i = ++v14;
    }
    while ( v14 < (int)v49 );
  }
  nCount = normals->m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    positionIndices = nullptr;
    do
    {
      VectorRotate(
        in1: (const float *)((char *)positionIndices + (unsigned int)normals->m_Memory.m_pMemory),
        in2: &normalMat,
        out: &vecDelta.x);
      m_nAllocationCount = v8->m_NormalDeltas.m_Memory.m_nAllocationCount;
      j = v8->m_NormalDeltas.m_Size;
      v24 = j;
      if ( j + 1 > m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&v8->m_NormalDeltas,
          num: j - m_nAllocationCount + 1);
        v24 = j;
      }
      ++v8->m_NormalDeltas.m_Size;
      v26 = v8->m_NormalDeltas.m_Memory.m_pMemory;
      v27 = v8->m_NormalDeltas.m_Size - v24 - 1;
      v8->m_NormalDeltas.m_pElements = v26;
      if ( v27 > 0 )
      {
        _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 12 * v27);
        v24 = j;
      }
      v28 = &v8->m_NormalDeltas.m_Memory.m_pMemory[v24];
      if ( v28 != nullptr )
        *v28 = vecDelta;
      v29 = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
              this: pBindState,
              fieldId: FIELD_NORMAL,
              nDataIndex: normalIndices->m_Memory.m_pMemory[i]);
      v30 = v29->m_Size;
      v31 = 0;
      v49 = (float *)v29;
      nBaseVertCount = v30;
      if ( v30 > 0 )
      {
        while ( 1 )
        {
          v32 = s_UniqueVerticesMap.m_Memory.m_pMemory[nStartingUniqueVertexMap + v29->m_Memory.m_pMemory[v31]];
          v33 = v8->m_DeltaIndices.m_Memory.m_pMemory;
          v34 = v32;
          if ( !v33[v32].m_bInList )
          {
            v33[v34].m_nNextDelta = v8->m_nFirstDelta;
            ++v8->m_nDeltaCount;
            v8->m_nFirstDelta = v32;
            v33[v34].m_bInList = true;
          }
          ++v31;
          v8->m_DeltaIndices.m_Memory.m_pMemory[v34].m_nNormalIndex = j;
          if ( v31 >= nBaseVertCount )
            break;
          v29 = (const CUtlVector<int,CUtlMemory<int,int> > *)v49;
        }
      }
      positionIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)positionIndices + 12);
      ++i;
    }
    while ( i < nCount );
  }
  nCount = wrinkle->m_Size;
  for ( j = 0; j < nCount; ++j )
  {
    v35 = v8->m_WrinkleDeltas.m_Memory.m_nAllocationCount;
    v49 = &wrinkle->m_Memory.m_pMemory[j];
    positionIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)v8->m_WrinkleDeltas.m_Size;
    v36 = positionIndices;
    if ( (int)&positionIndices->m_Memory.m_pMemory + 1 > v35 )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v8->m_WrinkleDeltas,
        num: (int)&positionIndices->m_Memory.m_pMemory - v35 + 1);
      v36 = positionIndices;
    }
    ++v8->m_WrinkleDeltas.m_Size;
    v37 = v8->m_WrinkleDeltas.m_Memory.m_pMemory;
    v38 = v8->m_WrinkleDeltas.m_Size - (_DWORD)v36 - 1;
    v8->m_WrinkleDeltas.m_pElements = v37;
    if ( v38 > 0 )
    {
      _V_memmove(dest: &v37[(_DWORD)v36 + 1], src: &v37[(_DWORD)v36], count: 4 * v38);
      v36 = positionIndices;
    }
    v39 = &v8->m_WrinkleDeltas.m_Memory.m_pMemory[(_DWORD)v36];
    if ( v39 != nullptr )
      *v39 = *v49;
    v40 = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
            this: pBindState,
            fieldId: FIELD_WRINKLE,
            nDataIndex: wrinkleIndices->m_Memory.m_pMemory[j]);
    v41 = v40->m_Size;
    v42 = 0;
    v49 = (float *)v40;
    nBaseVertCount = v41;
    if ( v41 > 0 )
    {
      while ( 1 )
      {
        v43 = s_UniqueVerticesMap.m_Memory.m_pMemory[nStartingUniqueVertexMap + v40->m_Memory.m_pMemory[v42]];
        v44 = v8->m_DeltaIndices.m_Memory.m_pMemory;
        v45 = v43;
        if ( !v44[v43].m_bInList )
        {
          v44[v45].m_nNextDelta = v8->m_nFirstDelta;
          ++v8->m_nDeltaCount;
          v8->m_nFirstDelta = v43;
          v44[v45].m_bInList = true;
        }
        ++v42;
        v8->m_DeltaIndices.m_Memory.m_pMemory[v45].m_nWrinkleIndex = (int)positionIndices;
        if ( v42 >= nBaseVertCount )
          break;
        v40 = (const CUtlVector<int,CUtlMemory<int,int> > *)v49;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A940
// Name: ParseQuadFaceData
// Source: json
//------------------------------------------------------------------------------
void __usercall ParseQuadFaceData(
        int material@<eax>,
        int *pIndices@<ecx>,
        CDmeVertexData *pVertexData,
        int vi,
        int ni,
        int ti)
{
  int PositionIndex; // ebx
  int TexCoordIndex; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  unsigned int v15; // edi
  int v16; // eax
  int n; // [esp+40h] [ebp-4h]
  int na; // [esp+40h] [ebp-4h]
  int nb; // [esp+40h] [ebp-4h]
  int nc; // [esp+40h] [ebp-4h]
  s_tmpface_t f; // 0:^14.52

  f.material = material;
  PositionIndex = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: *pIndices);
  n = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: *pIndices);
  TexCoordIndex = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: *pIndices);
  if ( PositionIndex < 0 )
    f.a = 0;
  else
    f.a = vi + PositionIndex;
  if ( n < 0 )
    f.na = 0;
  else
    f.na = ni + n;
  if ( TexCoordIndex < 0 )
    f.ta = 0;
  else
    f.ta = ti + TexCoordIndex;
  v9 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: pIndices[3]);
  na = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: pIndices[3]);
  v10 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: pIndices[3]);
  if ( v9 < 0 )
    f.b = 0;
  else
    f.b = vi + v9;
  if ( na < 0 )
    f.nb = 0;
  else
    f.nb = ni + na;
  if ( v10 < 0 )
    f.tb = 0;
  else
    f.tb = ti + v10;
  v11 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: pIndices[2]);
  nb = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: pIndices[2]);
  v12 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: pIndices[2]);
  if ( v11 < 0 )
    f.c = 0;
  else
    f.c = vi + v11;
  if ( nb < 0 )
    f.nc = 0;
  else
    f.nc = ni + nb;
  if ( v12 < 0 )
    f.tc = 0;
  else
    f.tc = ti + v12;
  v13 = CDmeVertexDataBase::GetPositionIndex(this: pVertexData, nVertexIndex: pIndices[1]);
  nc = CDmeVertexDataBase::GetNormalIndex(this: pVertexData, nVertexIndex: pIndices[1]);
  v14 = CDmeVertexDataBase::GetTexCoordIndex(this: pVertexData, nVertexIndex: pIndices[1]);
  if ( v13 < 0 )
    f.d = 0;
  else
    f.d = vi + v13;
  if ( nc < 0 )
    f.nd = 0;
  else
    f.nd = ni + nc;
  if ( v14 < 0 )
    f.td = 0;
  else
    f.td = ti + v14;
  v15 = g_numfaces;
  v16 = g_numfaces + 1;
  g_numfaces = v16;
  if ( g_face.m_Size < v16 )
    CUtlVector<s_tmpface_t,CUtlMemory<s_tmpface_t,int>>::InsertMultipleBefore(
      this: &g_face,
      elem: g_face.m_Size,
      num: v16 - g_face.m_Size);
  g_face.m_Memory.m_pMemory[v15] = f;
}

//------------------------------------------------------------------------------
// Address: 0x0040AF90
// Name: ComputeFramePose
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeFramePose(s_sourceanim_t *pSourceAnim, int nFrame, float flScale, BoneTransformMap_t *boneMap)
{
  unsigned __int8 *v4; // eax
  int v5; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_rawanim; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax
  int v8; // edi
  CUtlSymbolTable::StringPool_t **v9; // ecx
  int m_nAllocationCount; // edx
  CUtlSymbolTable::StringPool_t **v11; // edx
  int v12; // eax
  CUtlSymbolTable::StringPool_t **v13; // eax
  int v14; // edi
  CUtlSymbolTable::StringPool_t **v15; // ebx
  int v16; // ecx
  CUtlSymbolTable::StringPool_t **v17; // ecx
  int v18; // eax
  CUtlSymbolTable::StringPool_t **v19; // eax
  int v20; // edi
  CUtlSymbolTable::StringPool_t **v21; // ebx
  int v22; // ecx
  CUtlSymbolTable::StringPool_t **v23; // ecx
  int v24; // eax
  int v25; // ecx
  float *v26; // eax
  unsigned int v27; // [esp-4h] [ebp-50h]
  matrix3x4_t jointTransform; // [esp+Ch] [ebp-40h] BYREF
  char *v29; // [esp+3Ch] [ebp-10h]
  CUtlSymbolTable::StringPool_t **v30; // [esp+40h] [ebp-Ch]
  int i; // [esp+44h] [ebp-8h]
  int v32; // [esp+48h] [ebp-4h]
  CDmeTransform **pSourceAnima; // [esp+54h] [ebp+8h]

  v4 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * boneMap->m_nBoneCount);
  v27 = 24 * boneMap->m_nBoneCount;
  i = (int)v4;
  memset(dst: v4, value: 0, count: v27);
  v5 = nFrame;
  p_rawanim = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pSourceAnim->rawanim;
  if ( pSourceAnim->rawanim.m_Size < nFrame + 1 )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&pSourceAnim->rawanim,
      elem: pSourceAnim->rawanim.m_Size,
      num: nFrame + 1 - pSourceAnim->rawanim.m_Size);
  p_rawanim->m_pMemory[nFrame] = (CUtlSymbolTable::StringPool_t *)i;
  i = 0;
  if ( boneMap->m_nBoneCount > 0 )
  {
    v32 = 0;
    pSourceAnima = boneMap->m_ppTransforms;
    do
    {
      CDmeTransform::GetTransform(this: *pSourceAnima, transform: &jointTransform);
      m_pMemory = p_rawanim[1].m_pMemory;
      if ( (int)m_pMemory < v5 + 1 )
      {
        v8 = v5 + 1 - (_DWORD)m_pMemory;
        v9 = p_rawanim[1].m_pMemory;
        v30 = v9;
        if ( v8 != 0 )
        {
          m_nAllocationCount = p_rawanim->m_nAllocationCount;
          v29 = (char *)v9 + v8;
          if ( (int)v9 + v8 > m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_rawanim, num: (int)v9 + v8 - m_nAllocationCount);
            v9 = v30;
          }
          p_rawanim[1].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)p_rawanim[1].m_pMemory + v8);
          v11 = p_rawanim->m_pMemory;
          v12 = (char *)p_rawanim[1].m_pMemory - (char *)v9 - v8;
          p_rawanim[1].m_nAllocationCount = (int)p_rawanim->m_pMemory;
          if ( v12 > 0 && v8 > 0 )
            _V_memmove(dest: &v11[(_DWORD)v29], src: &v11[(_DWORD)v9], count: 4 * v12);
        }
      }
      v13 = p_rawanim[1].m_pMemory;
      v30 = p_rawanim->m_pMemory;
      if ( (int)v13 < v5 + 1 )
      {
        v14 = v5 + 1 - (_DWORD)v13;
        v15 = v13;
        if ( v14 != 0 )
        {
          v16 = p_rawanim->m_nAllocationCount;
          v29 = (char *)v13 + v14;
          if ( (int)v13 + v14 > v16 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_rawanim, num: (int)v13 + v14 - v16);
          p_rawanim[1].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)p_rawanim[1].m_pMemory + v14);
          v17 = p_rawanim->m_pMemory;
          v18 = (char *)p_rawanim[1].m_pMemory - (char *)v15 - v14;
          p_rawanim[1].m_nAllocationCount = (int)p_rawanim->m_pMemory;
          if ( v18 > 0 && v14 > 0 )
            _V_memmove(dest: &v17[(_DWORD)v29], src: &v17[(_DWORD)v15], count: 4 * v18);
        }
        v5 = nFrame;
      }
      MatrixAngles(
        matrix: &jointTransform,
        angles: (RadianEuler *)((char *)&p_rawanim->m_pMemory[v5][1] + v32),
        position: (Vector *)((char *)v30[v5] + v32));
      v19 = p_rawanim[1].m_pMemory;
      if ( (int)v19 < v5 + 1 )
      {
        v20 = v5 + 1 - (_DWORD)v19;
        v21 = p_rawanim[1].m_pMemory;
        if ( v20 != 0 )
        {
          v22 = p_rawanim->m_nAllocationCount;
          v29 = (char *)v21 + v20;
          if ( (int)v21 + v20 > v22 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_rawanim, num: (int)v21 + v20 - v22);
          p_rawanim[1].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)p_rawanim[1].m_pMemory + v20);
          v23 = p_rawanim->m_pMemory;
          v24 = (char *)p_rawanim[1].m_pMemory - (char *)v21 - v20;
          p_rawanim[1].m_nAllocationCount = (int)p_rawanim->m_pMemory;
          if ( v24 > 0 && v20 > 0 )
            _V_memmove(dest: &v23[(_DWORD)v29], src: &v23[(_DWORD)v21], count: 4 * v24);
        }
        v5 = nFrame;
      }
      v25 = v32;
      ++pSourceAnima;
      v26 = (float *)((char *)&p_rawanim->m_pMemory[v5]->m_TotalLen + v32);
      *v26 = flScale * *v26;
      v26[1] = v26[1] * flScale;
      v26[2] = v26[2] * flScale;
      v32 = v25 + 24;
      ++i;
    }
    while ( i < boneMap->m_nBoneCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B1C0
// Name: LoadAnimations
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadAnimations(
        s_source_t *pSource,
        CDmeAnimationList *pAnimationList,
        float flScale,
        BoneTransformMap_t *boneMap)
{
  CDmeAnimationList *v4; // ebx
  int v5; // edi
  int v6; // eax
  CDmeChannelsClip *v7; // esi
  const char *Name; // eax
  const char *m_pAsString; // eax
  s_sourceanim_t *v10; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v12; // esi
  CDmaVar<int> *m_pData; // esi
  int m_Storage; // esi
  int v15; // eax
  CDmeChannelsClip *v16; // edx
  float v17; // xmm0_4
  int v18; // esi
  int v19; // eax
  IDmeOperator **m_pMemory; // eax
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > operatorList; // [esp+18h] [ebp-34h] BYREF
  int nAnimationCount; // [esp+2Ch] [ebp-20h]
  float flOOFrameRate; // [esp+30h] [ebp-1Ch]
  DmeTime_t nEndTime; // [esp+34h] [ebp-18h] BYREF
  DmeTime_t nStartTime; // [esp+38h] [ebp-14h] BYREF
  int i; // [esp+3Ch] [ebp-10h]
  CDmeChannelsClip *pAnimation; // [esp+40h] [ebp-Ch]
  int nFrameRateVal; // [esp+44h] [ebp-8h]
  DmeFramerate_t nFrameRate; // [esp+48h] [ebp-4h] BYREF

  v4 = pAnimationList;
  v5 = 0;
  nAnimationCount = pAnimationList->m_Animations.m_Storage.m_Size;
  i = 0;
  if ( nAnimationCount > 0 )
  {
    while ( 1 )
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v4->m_Animations.m_Storage.m_Memory.m_pMemory[i]);
      v7 = (CDmeChannelsClip *)v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        pAnimation = v7;
      }
      else
      {
        pAnimation = nullptr;
        v7 = nullptr;
      }
      Name = CDmElement::GetName(this: v4);
      if ( _V_stricmp(s1: Name, s2: "BindPose") == 0 )
        MdlError(fmt: "Error: Cannot use \"BindPose\" as an animation name!\n");
      m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v10 = FindOrAddSourceAnim(pSource, pAnimName: m_pAsString);
      CDmeClip::GetStartTime(this: v7, result: &nStartTime);
      CDmeClip::GetEndTime(this: v7, result: &nEndTime);
      if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "frameRate");
      v12 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 2 )
        {
          m_pData = (CDmaVar<int> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<int>(this: v12, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
          m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = m_pData->m_Storage;
      nFrameRateVal = m_Storage;
      if ( m_Storage <= 0 )
      {
        nFrameRateVal = 30;
        m_Storage = 30;
      }
      DmeFramerate_t::DmeFramerate_t(this: &nFrameRate, fps: m_Storage);
      v10->startframe = DmeTime_t::CurrentFrame(this: &nStartTime, framerate: nFrameRate, roundStyle: ROUND_DOWN);
      v15 = DmeTime_t::CurrentFrame(this: &nEndTime, framerate: nFrameRate, roundStyle: ROUND_DOWN);
      v16 = pAnimation;
      v10->endframe = v15;
      v10->numframes = v15 - v10->startframe + 1;
      memset((void *)&operatorList, 0, sizeof(operatorList));
      PrepareChannels((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&operatorList, pAnimation: v16);
      v17 = 1.0 / (float)m_Storage;
      flOOFrameRate = v17;
      if ( v10->numframes > 0 )
      {
        while ( 1 )
        {
          v18 = v5 / m_Storage;
          v19 = DmeTime_t::RoundSecondsToTMS(sec: (float)(v5 - nFrameRateVal * v18) * v17);
          UpdateChannels(
            operators: &operatorList,
            pAnimation,
            clipTime: (DmeTime_t)(nStartTime.m_tms + v19 + 10000 * v18));
          ComputeFramePose(pSourceAnim: v10, nFrame: v5++, flScale, boneMap);
          if ( v5 >= v10->numframes )
            break;
          v17 = flOOFrameRate;
          m_Storage = nFrameRateVal;
        }
        v5 = 0;
      }
      m_pMemory = operatorList.m_Memory.m_pMemory;
      operatorList.m_Size = 0;
      if ( operatorList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( operatorList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorList.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          operatorList.m_Memory.m_pMemory = nullptr;
        }
        operatorList.m_Memory.m_nAllocationCount = 0;
      }
      operatorList.m_pElements = m_pMemory;
      if ( operatorList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      if ( ++i >= nAnimationCount )
        break;
      v4 = pAnimationList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B490
// Name: bool LoadTwistConstraint(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadTwistConstraint(CDmElement *pDmElement)
{
  CDmeRigTwistConstraintOperator *v1; // edi
  CDmeDag *ParentTarget; // ebx
  CDmeDag *ChildTarget; // eax
  CTwistBone *v4; // esi
  const char *m_pAsString; // eax
  _QWORD *p_x; // eax
  const char *v7; // eax
  int v8; // eax
  CDmeDag *SlaveDag; // eax
  char *m_Id; // eax
  char v11; // cl
  int v12; // eax
  int v13; // edi
  int *v14; // ebx
  int v15; // esi
  int m_szBoneName; // esi
  const char *v17; // eax
  CDmeTransform *Transform; // eax
  char *s1; // [esp+Ch] [ebp-20h]
  _DWORD *v21; // [esp+10h] [ebp-1Ch]
  CDmeDag *pDmeTwistDag; // [esp+14h] [ebp-18h]
  int v23; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  CTwistBone *twistBone; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]
  CDmeRigTwistConstraintOperator *pDmeTwist; // [esp+28h] [ebp-4h]
  CDmeDag *bFound; // [esp+34h] [ebp+8h]
  char bFound_3; // [esp+37h] [ebp+Bh]

  if ( pDmElement == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
          a1: pDmElement,
          a2: (CUtlSymbolLarge)CDmeRigTwistConstraintOperator::m_classType.u.m_Id) )
    return 0;
  v1 = (CDmeRigTwistConstraintOperator *)((char *)&pDmElement[-1] + 64);
  pDmeTwist = (CDmeRigTwistConstraintOperator *)((char *)&pDmElement[-1] + 64);
  if ( pDmElement == (CDmElement *)4 )
    return 0;
  if ( g_twistbones.m_Size == 256 )
    return 0;
  ParentTarget = CDmeRigTwistConstraintOperator::GetParentTarget(this: v1);
  ChildTarget = CDmeRigTwistConstraintOperator::GetChildTarget(this: v1);
  bFound = ChildTarget;
  if ( ParentTarget == nullptr || ChildTarget == nullptr )
    return 0;
  v4 = &g_twistbones.m_Memory.m_pMemory[CUtlVector<CTwistBone,CUtlMemory<CTwistBone,int>>::InsertBefore(
                                          this: &g_twistbones,
                                          elem: g_twistbones.m_Size)];
  v4->m_bInverse = v1->m_bInverse.m_Storage;
  twistBone = v4;
  v4->m_vUpVector.x = v1->m_vUpAxis.m_Storage.x;
  v4->m_vUpVector.y = v1->m_vUpAxis.m_Storage.y;
  v4->m_vUpVector.z = v1->m_vUpAxis.m_Storage.z;
  m_pAsString = ParentTarget->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  V_strncpy(pDest: v4->m_szParentBoneName, pSrc: m_pAsString, maxLen: 128);
  p_x = (_QWORD *)&v1->m_qParentBindRotation.m_Storage.x;
  if ( !v4->m_bInverse )
    p_x = (_QWORD *)&v1->m_qChildBindRotation.m_Storage.x;
  *(_QWORD *)&v4->m_qBaseRotation.x = *p_x;
  *(_QWORD *)&v4->m_qBaseRotation.z = p_x[1];
  v7 = bFound->m_Name.m_Storage.u.m_pAsString;
  if ( v7 == (const char *)-1 )
    v7 = pDeltaStateName;
  V_strncpy(pDest: v4->m_szChildBoneName, pSrc: v7, maxLen: 128);
  v8 = 0;
  for ( i = 0; v8 < v1->m_eSlaves.m_Storage.m_Size; i = v8 )
  {
    SlaveDag = CDmeRigTwistConstraintOperator::GetSlaveDag(this: v1, i: v8);
    pDmeTwistDag = SlaveDag;
    if ( SlaveDag != nullptr )
    {
      m_Id = (char *)SlaveDag->m_Name.m_Storage.u.CDmElement::m_Id;
      s1 = m_Id;
      if ( m_Id != (char *)-1 && m_Id != nullptr && *m_Id != 0 )
      {
        v11 = 0;
        v12 = 0;
        bFound_3 = 0;
        j = 0;
        v23 = 0;
        while ( j < g_twistbones.m_Size )
        {
          v13 = 0;
          v14 = (int *)((char *)&g_twistbones.m_Memory.m_pMemory->m_twistBoneTargets.m_Size + v12);
          if ( *v14 > 0 )
          {
            v21 = (s_constraintbonetarget_t **)((char *)&g_twistbones.m_Memory.m_pMemory->m_twistBoneTargets.m_Memory.m_pMemory
                                              + v12);
            v15 = 0;
            while ( _V_stricmp(s1, s2: (const char *)(v15 + *v21)) != 0 )
            {
              ++v13;
              v15 += 164;
              if ( v13 >= *v14 )
                goto LABEL_26;
            }
            bFound_3 = 1;
LABEL_26:
            v4 = twistBone;
          }
          v11 = bFound_3;
          ++j;
          v1 = pDmeTwist;
          v12 = v23 + 316;
          v23 += 316;
          if ( bFound_3 != 0 )
            goto LABEL_33;
        }
        if ( v11 == 0 )
        {
          m_szBoneName = (int)v4->m_twistBoneTargets.m_Memory.m_pMemory[CUtlVector<s_constraintbonetarget_t,CUtlMemory<s_constraintbonetarget_t,int>>::AddToTail(this: &v4->m_twistBoneTargets)].m_szBoneName;
          v17 = pDmeTwistDag->m_Name.m_Storage.u.m_pAsString;
          if ( v17 == (const char *)-1 )
            v17 = pDeltaStateName;
          V_strncpy(pDest: (char *)m_szBoneName, pSrc: v17, maxLen: 128);
          *(_DWORD *)(m_szBoneName + 128) = -1;
          *(float *)(m_szBoneName + 132) = CDmeRigTwistConstraintOperator::GetSlaveWeight(this: pDmeTwist, i);
          Transform = CDmeDag::GetTransform(this: pDmeTwistDag);
          *(Vector *)(m_szBoneName + 136) = *CDmeTransform::GetPosition(this: Transform);
          *(Quaternion *)(m_szBoneName + 148) = *CDmeRigTwistConstraintOperator::GetSlaveBindOrientation(
                                                   this: pDmeTwist,
                                                   i);
          v4 = twistBone;
          v1 = pDmeTwist;
        }
      }
    }
LABEL_33:
    v8 = i + 1;
  }
  if ( v4->m_twistBoneTargets.m_Size <= 0 )
    CUtlVector<CTwistBone,CUtlMemory<CTwistBone,int>>::RemoveMultipleFromTail(this: &g_twistbones, num: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B770
// Name: void LoadConstraints(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadConstraints(CDmElement *pDmeRoot)
{
  int v1; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // esi
  DmElementArray_t *m_pData; // esi
  int v5; // eax
  int v6; // eax
  CDmElement *v7; // esi
  int v8; // eax
  CDmElement *v9; // esi
  CDmElement *v10; // eax
  int v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // eax
  int v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // eax
  CDmElement *v17; // eax
  const char *m_pAsString; // eax
  CDmrElementArray<CDmElement> constraints; // [esp+Ch] [ebp-8h] BYREF

  v1 = 0;
  if ( pDmeRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pDmeRoot, pAttributeName: "constraints");
    v3 = Attribute;
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&constraints);
      if ( (v3->m_nFlags & 0x1F) == 0xF )
      {
        constraints.m_pAttribute = v3;
        m_pData = (DmElementArray_t *)v3->m_pData;
      }
      else
      {
        constraints.m_pAttribute = nullptr;
        m_pData = nullptr;
      }
      constraints.m_pStorage = m_pData;
      while ( 1 )
      {
        v5 = constraints.m_pAttribute != nullptr ? m_pData->m_Size : 0;
        if ( v1 >= v5 )
          break;
        v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: m_pData->m_Memory.m_pMemory[v1]);
        v7 = (CDmElement *)v6;
        if ( v6 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v7 = nullptr;
        }
        if ( LoadTwistConstraint(pDmElement: v7) == 0 )
        {
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: constraints.m_pStorage->m_Memory.m_pMemory[v1]);
          v9 = (CDmElement *)v8;
          if ( v8 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            v10 = v9;
          }
          else
          {
            v10 = nullptr;
          }
          if ( LoadConstraint_CDmeRigPointConstraintOperator_CPointConstraint_(pDmElement: v10) == 0 )
          {
            v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: constraints.m_pStorage->m_Memory.m_pMemory[v1]);
            v12 = (CDmElement *)v11;
            if ( v11 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
                   a1: v11,
                   a2: CDmElement::m_classType.u) != 0 )
            {
              v13 = v12;
            }
            else
            {
              v13 = nullptr;
            }
            if ( LoadConstraint_CDmeRigOrientConstraintOperator_COrientConstraint_(pDmElement: v13) == 0 )
            {
              v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: constraints.m_pStorage->m_Memory.m_pMemory[v1]);
              v15 = (CDmElement *)v14;
              if ( v14 != 0
                && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v14 + 16))(
                     a1: v14,
                     a2: CDmElement::m_classType.u) != 0 )
              {
                v16 = v15;
              }
              else
              {
                v16 = nullptr;
              }
              if ( LoadConstraint_CDmeRigAimConstraintOperator_CAimConstraint_(pDmElement: v16) == 0 )
              {
                v17 = CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](
                        this: &constraints,
                        i: v1);
                if ( LoadConstraint_CDmeRigParentConstraintOperator_CParentConstraint_(pDmElement: v17) == 0 )
                {
                  m_pAsString = CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](
                                  this: &constraints,
                                  i: v1)->m_Name.m_Storage.u.m_pAsString;
                  if ( m_pAsString == (const char *)-1 )
                    m_pAsString = pDeltaStateName;
                  _Error(a1: "TODO: Support Constraint: %s\n", m_pAsString);
                }
              }
            }
          }
        }
        m_pData = constraints.m_pStorage;
        ++v1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BA90
// Name: DefineUniqueVertices
// Source: json
//------------------------------------------------------------------------------
char __usercall DefineUniqueVertices@<al>(CDmeVertexData *pBindState@<eax>)
{
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndexData; // edi
  const CUtlVector<int,CUtlMemory<int,int> > *v3; // eax
  int m_Size; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // ebx
  int v8; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // esi
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  int v17; // esi
  VertIndices_t *v18; // ecx
  int v19; // eax
  VertIndices_t *v20; // eax
  int v21; // eax
  int v22; // edi
  int *v23; // ecx
  int v24; // eax
  int *v25; // eax
  VertexLookup_t *v26; // edi
  int v27; // eax
  int v28; // esi
  int *m_pMemory; // ecx
  int v30; // eax
  int *v31; // eax
  CUtlHash<VertexLookup_t,bool (__cdecl*)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl*)(VertexLookup_t const &)> vertexLookupHash; // [esp+Ch] [ebp-7Ch] BYREF
  VertIndices_t vert; // [esp+30h] [ebp-58h]
  VertexLookup_t vertexLookup; // [esp+44h] [ebp-44h] BYREF
  unsigned int v36; // [esp+54h] [ebp-34h] BYREF
  unsigned int pBucket; // [esp+58h] [ebp-30h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *speedIndices; // [esp+5Ch] [ebp-2Ch]
  int nSpeedCount; // [esp+60h] [ebp-28h]
  int nBalanceCount; // [esp+64h] [ebp-24h]
  int nTexcoordCount; // [esp+68h] [ebp-20h]
  const CUtlVector<int,CUtlMemory<int,int> > *normalIndices; // [esp+6Ch] [ebp-1Ch]
  int nNormalCount; // [esp+70h] [ebp-18h]
  const CUtlVector<int,CUtlMemory<int,int> > *positionIndices; // [esp+74h] [ebp-14h]
  int nPositionCount; // [esp+78h] [ebp-10h]
  int pIndex; // [esp+7Ch] [ebp-Ch] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *balanceIndices; // [esp+80h] [ebp-8h]
  const CUtlVector<int,CUtlMemory<int,int> > *texcoordIndices; // [esp+84h] [ebp-4h]

  VertexIndexData = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                    this: pBindState,
                                                                    fieldId: FIELD_POSITION);
  positionIndices = VertexIndexData;
  normalIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                  this: pBindState,
                                                                  fieldId: FIELD_NORMAL);
  texcoordIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                    this: pBindState,
                                                                    fieldId: FIELD_TEXCOORD);
  balanceIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                   this: pBindState,
                                                                   fieldId: FIELD_BALANCE);
  v3 = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                       this: pBindState,
                                                       fieldId: FIELD_MORPH_SPEED);
  m_Size = normalIndices->m_Size;
  v5 = VertexIndexData->m_Size;
  v6 = texcoordIndices->m_Size;
  v7 = balanceIndices->m_Size;
  speedIndices = v3;
  v8 = v3->m_Size;
  nPositionCount = v5;
  nNormalCount = m_Size;
  nTexcoordCount = v6;
  nBalanceCount = v7;
  nSpeedCount = v8;
  if ( m_Size != 0 && v5 != m_Size || v6 != 0 && v5 != v6 || v7 != 0 && v5 != v7 || v8 != 0 && v5 != v8 )
    MdlError(fmt: "Encountered a mesh with invalid geometry (different number of indices for various data fields)\n");
  CUtlHash<VertexLookup_t,bool (__cdecl *)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl *)(VertexLookup_t const &)>::CUtlHash<VertexLookup_t,bool (__cdecl *)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl *)(VertexLookup_t const &)>(
    this: &vertexLookupHash,
    bucketCount: v5,
    growCount: 0,
    initCount: 0,
    compareFunc: (bool (__cdecl *)(const VertexLookup_t *, const VertexLookup_t *))VertexLookup_CompareFunc,
    keyFunc: VertexLookup_KeyFunc);
  v9 = 0;
  if ( nPositionCount > 0 )
  {
    while ( 1 )
    {
      v10 = g_numverts + VertexIndexData->m_Memory.m_pMemory[v9];
      vert.v = v10;
      v11 = m_Size <= 0 ? -1 : g_numnormals + normalIndices->m_Memory.m_pMemory[v9];
      vert.n = v11;
      v12 = nTexcoordCount <= 0 ? -1 : g_numtexcoords + texcoordIndices->m_Memory.m_pMemory[v9];
      vert.t = v12;
      v13 = nBalanceCount <= 0 ? 0 : balanceIndices->m_Memory.m_pMemory[v9];
      vert.balance = s_Balance.m_Size + v13;
      v14 = nSpeedCount <= 0 ? 0 : speedIndices->m_Memory.m_pMemory[v9];
      vertexLookup.t = v12;
      vertexLookup.v = v10;
      v15 = v14 + s_Speed.m_Size;
      vertexLookup.n = v11;
      vertexLookup.index = -1;
      pIndex = 0;
      if ( CUtlHash<VertexLookup_t,bool (__cdecl *)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl *)(VertexLookup_t const &)>::DoFind(
             this: &vertexLookupHash,
             src: &vertexLookup,
             &pBucket,
             &pIndex) != 0
        && (pIndex | (pBucket << 16)) != 0xFFFFFFFF )
      {
        v26 = &vertexLookupHash.m_Buckets.m_Memory.m_pMemory[(pIndex | (pBucket << 16)) >> 16].m_Memory.m_pMemory[(unsigned __int16)pIndex];
        v27 = s_UniqueVerticesMap.m_Size;
        v28 = s_UniqueVerticesMap.m_Size;
        if ( s_UniqueVerticesMap.m_Size + 1 > s_UniqueVerticesMap.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&s_UniqueVerticesMap,
            num: s_UniqueVerticesMap.m_Size - s_UniqueVerticesMap.m_Memory.m_nAllocationCount + 1);
          v27 = s_UniqueVerticesMap.m_Size;
        }
        m_pMemory = s_UniqueVerticesMap.m_Memory.m_pMemory;
        s_UniqueVerticesMap.m_Size = v27 + 1;
        v30 = v27 - v28;
        s_UniqueVerticesMap.m_pElements = s_UniqueVerticesMap.m_Memory.m_pMemory;
        if ( v30 > 0 )
        {
          _V_memmove(
            dest: &s_UniqueVerticesMap.m_Memory.m_pMemory[v28 + 1],
            src: &s_UniqueVerticesMap.m_Memory.m_pMemory[v28],
            count: 4 * v30);
          m_pMemory = s_UniqueVerticesMap.m_Memory.m_pMemory;
        }
        v31 = &m_pMemory[v28];
        if ( v31 != nullptr )
          *v31 = v26->index;
      }
      else
      {
        v16 = s_UniqueVertices.m_Size;
        v17 = s_UniqueVertices.m_Size;
        if ( s_UniqueVertices.m_Size + 1 > s_UniqueVertices.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CUtlVectorAuto<s_compressed_t>,int>::Grow(
            this: (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)&s_UniqueVertices,
            num: s_UniqueVertices.m_Size - s_UniqueVertices.m_Memory.m_nAllocationCount + 1);
          v16 = s_UniqueVertices.m_Size;
        }
        v18 = s_UniqueVertices.m_Memory.m_pMemory;
        s_UniqueVertices.m_Size = v16 + 1;
        v19 = v16 - v17;
        s_UniqueVertices.m_pElements = s_UniqueVertices.m_Memory.m_pMemory;
        if ( v19 > 0 )
        {
          _V_memmove(
            dest: &s_UniqueVertices.m_Memory.m_pMemory[v17 + 1],
            src: &s_UniqueVertices.m_Memory.m_pMemory[v17],
            count: 20 * v19);
          v18 = s_UniqueVertices.m_Memory.m_pMemory;
        }
        v20 = &v18[v17];
        *(_QWORD *)&v20->v = *(_QWORD *)&vert.v;
        *(_QWORD *)&v20->t = *(_QWORD *)&vert.t;
        v20->speed = v15;
        v21 = s_UniqueVerticesMap.m_Size;
        v22 = s_UniqueVerticesMap.m_Size;
        if ( s_UniqueVerticesMap.m_Size + 1 > s_UniqueVerticesMap.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&s_UniqueVerticesMap,
            num: s_UniqueVerticesMap.m_Size - s_UniqueVerticesMap.m_Memory.m_nAllocationCount + 1);
          v21 = s_UniqueVerticesMap.m_Size;
        }
        v23 = s_UniqueVerticesMap.m_Memory.m_pMemory;
        s_UniqueVerticesMap.m_Size = v21 + 1;
        v24 = v21 - v22;
        s_UniqueVerticesMap.m_pElements = s_UniqueVerticesMap.m_Memory.m_pMemory;
        if ( v24 > 0 )
        {
          _V_memmove(
            dest: &s_UniqueVerticesMap.m_Memory.m_pMemory[v22 + 1],
            src: &s_UniqueVerticesMap.m_Memory.m_pMemory[v22],
            count: 4 * v24);
          v23 = s_UniqueVerticesMap.m_Memory.m_pMemory;
        }
        v25 = &v23[v22];
        if ( v25 != nullptr )
          *v25 = v17;
        vertexLookup.index = v17;
        if ( CUtlHash<VertexLookup_t,bool (__cdecl *)(VertexLookup_t const &,VertexLookup_t const &),unsigned int (__cdecl *)(VertexLookup_t const &)>::DoFind(
               this: &vertexLookupHash,
               src: &vertexLookup,
               pBucket: &v36,
               &pIndex) == 0 )
          CUtlVector<VertexLookup_t,CUtlMemory<VertexLookup_t,int>>::InsertBefore(
            this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)&vertexLookupHash.m_Buckets.m_Memory.m_pMemory[v36],
            elem: vertexLookupHash.m_Buckets.m_Memory.m_pMemory[v36].m_Size,
            src: (const Quaternion *)&vertexLookup);
      }
      if ( ++v9 >= nPositionCount )
        break;
      VertexIndexData = positionIndices;
      m_Size = nNormalCount;
    }
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&vertexLookupHash);
  CUtlVector<CUtlVectorAuto<s_animation_t *>,CUtlMemory<CUtlVectorAuto<s_animation_t *>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&vertexLookupHash);
  if ( vertexLookupHash.m_Buckets.m_Memory.m_nGrowSize >= 0 && vertexLookupHash.m_Buckets.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertexLookupHash.m_Buckets.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040BE00
// Name: LoadVertices
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __usercall LoadVertices@<al>(
        float *a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CDmeDag *pDmeDag,
        CDmeVertexData *pBindState,
        const matrix3x4_t *mat,
        float flScale,
        int nBoneAssign,
        int *pBoneRemap,
        s_source_t *pSource)
{
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // edi
  const CUtlVector<float,CUtlMemory<float,int> > *MorphSpeedData; // eax
  int m_Size; // edx
  int m_Storage; // edi
  int v14; // esi
  s_node_t *localBone; // edi
  const char *Name; // eax
  unsigned __int8 *v17; // eax
  IMemAlloc_vtbl *v18; // edx
  int v19; // eax
  int v20; // esi
  int v21; // eax
  int v22; // esi
  int v23; // edi
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v24; // edx
  Vector *m_pMemory; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  int v29; // esi
  int v30; // edi
  Vector *v31; // ecx
  int v32; // eax
  bool v33; // zf
  float *p_x; // eax
  int v35; // esi
  int v36; // esi
  int v37; // esi
  int y_low; // edi
  unsigned __int8 *JointWeightData; // esi
  const int *JointIndexData; // edi
  float *v41; // esi
  int *v42; // edi
  int v43; // esi
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v44; // eax
  unsigned __int8 *v45; // edi
  int v46; // eax
  int v47; // esi
  const char *v48; // eax
  int v49; // esi
  int v50; // edi
  int v51; // eax
  int v52; // esi
  int v53; // edi
  s_boneweight_t *v54; // ecx
  int v55; // eax
  int v56; // edx
  int v57; // eax
  unsigned __int8 *v58; // eax
  __int128 v59; // xmm4
  int v60; // eax
  int v61; // esi
  int v62; // edi
  Vector *v63; // ecx
  int v64; // eax
  bool v65; // dl
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v66; // ecx
  float *v67; // edi
  int v68; // eax
  int v69; // ecx
  int v70; // esi
  Vector2D *v71; // ecx
  int v72; // eax
  float y; // xmm0_4
  int v74; // eax
  int v75; // esi
  int v76; // edi
  int v77; // edx
  Vector2D *v78; // ecx
  int v79; // eax
  int v80; // eax
  int v81; // eax
  int v82; // eax
  int v83; // esi
  float *v84; // ecx
  int v85; // eax
  float *v86; // eax
  int v87; // eax
  int v89; // eax
  int v90; // esi
  float *v91; // ecx
  int v92; // eax
  float *v93; // eax
  _BYTE v96[12]; // [esp+38h] [ebp-1ACh] BYREF
  bool pbWarnmap[256]; // [esp+44h] [ebp-1A0h] BYREF
  __int128 normalMat_36; // [esp+168h] [ebp-7Ch] OVERLAPPED
  const CUtlVector<float,CUtlMemory<float,int> > *BalanceData; // [esp+184h] [ebp-60h]
  int v100; // [esp+188h] [ebp-5Ch]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v101; // [esp+18Ch] [ebp-58h]
  const CUtlVector<float,CUtlMemory<float,int> > *balances; // [esp+190h] [ebp-54h]
  float v103; // [esp+194h] [ebp-50h] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *positions; // [esp+198h] [ebp-4Ch]
  const CUtlVector<float,CUtlMemory<float,int> > *speeds; // [esp+19Ch] [ebp-48h]
  Vector vNormal; // [esp+1A0h] [ebp-44h]
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *TextureCoordData; // [esp+1ACh] [ebp-38h]
  int i; // [esp+1B0h] [ebp-34h]
  int j; // [esp+1B4h] [ebp-30h]
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *texcoords; // [esp+1B8h] [ebp-2Ch]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *normals; // [esp+1BCh] [ebp-28h]
  int nCount; // [esp+1C0h] [ebp-24h]
  int nBoneCount; // [esp+1C4h] [ebp-20h]
  int v114; // [esp+1C8h] [ebp-1Ch]
  float *v115; // [esp+1CCh] [ebp-18h]
  float v116; // [esp+1D0h] [ebp-14h] OVERLAPPED
  int v117; // [esp+1D4h] [ebp-10h]
  float *pWeightBuf; // [esp+1D8h] [ebp-Ch]
  int *pIndexBuf; // [esp+1DCh] [ebp-8h]
  int *retaddr; // [esp+1E4h] [ebp+0h]
  int nBoneAssigna; // [esp+1F8h] [ebp+14h]

  pWeightBuf = a1;
  pIndexBuf = retaddr;
  if ( nBoneAssign >= 0 )
  {
    nBoneAssigna = pBoneRemap[nBoneAssign];
    if ( nBoneAssigna < 0 )
      nBoneAssigna = s_nDefaultRootNode;
  }
  else
  {
    nBoneAssigna = s_nDefaultRootNode;
  }
  DefineUniqueVertices(pBindState);
  MatrixInverseTranspose(src: mat, dst: (matrix3x4_t *)&pbWarnmap[244]);
  PositionData = CDmeVertexDataBase::GetPositionData(this: pBindState);
  v101 = PositionData;
  i = (int)CDmeVertexDataBase::GetNormalData(this: pBindState);
  TextureCoordData = CDmeVertexDataBase::GetTextureCoordData(this: pBindState);
  BalanceData = CDmeVertexDataBase::GetBalanceData(this: pBindState);
  MorphSpeedData = CDmeVertexDataBase::GetMorphSpeedData(this: pBindState);
  m_Size = PositionData->m_Size;
  balances = MorphSpeedData;
  j = m_Size;
  if ( CDmeVertexDataBase::HasSkinningData(this: pBindState) )
    m_Storage = pBindState->m_nJointCount.m_Storage;
  else
    m_Storage = 0;
  v117 = m_Storage;
  if ( m_Storage > 3 )
    MdlError(fmt: "Too many bone influences per vertex!\n");
  if ( m_Storage <= 0 && nBoneAssigna == s_nDefaultRootNode && pDmeDag != nullptr )
  {
    v14 = 0;
    if ( pSource->numbones > 0 )
    {
      localBone = pSource->localBone;
      while ( 1 )
      {
        Name = CDmElement::GetName(this: pDmeDag);
        if ( _V_strcmp(s1: Name, s2: localBone->name) == 0 )
          break;
        ++v14;
        ++localBone;
        if ( v14 >= pSource->numbones )
          goto LABEL_19;
      }
      nBoneAssigna = v14;
LABEL_19:
      m_Storage = v117;
    }
  }
  _V_memset(dest: v96, fill: 0, count: 256);
  v17 = (unsigned __int8 *)((int (__thiscall *)(IMemAlloc *, int, int, int))_g_pMemAlloc->Alloc_2)(
                             a1: _g_pMemAlloc,
                             a2: 4 * m_Storage,
                             a3: a2,
                             a4: a3);
  v18 = _g_pMemAlloc->__vftable;
  v115 = (float *)v17;
  v116 = COERCE_FLOAT((int)v18->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Storage));
  vNormal.y = 0.0;
  if ( j > 0 )
  {
    vNormal.x = 0.0;
    v19 = g_numverts;
    while ( 1 )
    {
      v20 = v19 + 1;
      v114 = v19;
      v21 = g_vertex.m_Size;
      if ( g_vertex.m_Size >= v20 )
        goto LABEL_29;
      v22 = v20 - g_vertex.m_Size;
      v23 = g_vertex.m_Size;
      if ( v22 == 0 )
        goto LABEL_29;
      v24 = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)(v22 + g_vertex.m_Size);
      texcoords = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)(v22 + g_vertex.m_Size);
      if ( v22 + g_vertex.m_Size > g_vertex.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_vertex,
          num: g_vertex.m_Size + v22 - g_vertex.m_Memory.m_nAllocationCount);
        v21 = g_vertex.m_Size;
        v24 = texcoords;
      }
      m_pMemory = g_vertex.m_Memory.m_pMemory;
      g_vertex.m_Size = v22 + v21;
      v26 = v21 - v23;
      g_vertex.m_pElements = g_vertex.m_Memory.m_pMemory;
      if ( v26 > 0 && v22 > 0 )
        break;
LABEL_30:
      VectorTransform(
        in1: (const float *)((char *)&v101->m_Memory.m_pMemory->x + LODWORD(vNormal.x)),
        in2: mat,
        out: &m_pMemory[v114].x);
      v27 = g_vertex.m_Size;
      v114 = g_numverts;
      v28 = g_numverts + 1;
      if ( g_vertex.m_Size >= g_numverts + 1 )
        goto LABEL_37;
      v29 = v28 - g_vertex.m_Size;
      v30 = g_vertex.m_Size;
      if ( v28 == g_vertex.m_Size )
        goto LABEL_37;
      texcoords = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)(g_numverts + 1);
      if ( v28 > g_vertex.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_vertex,
          num: g_vertex.m_Size + v29 - g_vertex.m_Memory.m_nAllocationCount);
        v27 = g_vertex.m_Size;
      }
      v31 = g_vertex.m_Memory.m_pMemory;
      g_vertex.m_Size = v29 + v27;
      v32 = v27 - v30;
      g_vertex.m_pElements = g_vertex.m_Memory.m_pMemory;
      if ( v32 > 0 && v29 > 0 )
      {
        _V_memmove(
          dest: &g_vertex.m_Memory.m_pMemory[(_DWORD)texcoords],
          src: &g_vertex.m_Memory.m_pMemory[v30],
          count: 12 * v32);
LABEL_37:
        v31 = g_vertex.m_Memory.m_pMemory;
      }
      v33 = v117 == 0;
      p_x = &v31[v114].x;
      *p_x = *p_x * flScale;
      p_x[1] = p_x[1] * flScale;
      p_x[2] = p_x[2] * flScale;
      if ( !v33 )
      {
        y_low = LODWORD(vNormal.y);
        JointWeightData = (unsigned __int8 *)CDmeVertexDataBase::GetJointWeightData(
                                               this: pBindState,
                                               nDataIndex: SLODWORD(vNormal.y));
        JointIndexData = CDmeVertexDataBase::GetJointIndexData(this: pBindState, nDataIndex: y_low);
        v117 *= 4;
        v116 = *(float *)&JointWeightData;
        v41 = v115;
        memcpy(dst: (unsigned __int8 *)v115, src: (unsigned __int8 *)LODWORD(v116), count: v117);
        v114 = 4 * v117;
        nBoneCount = (int)JointIndexData;
        v42 = (int *)LODWORD(v116);
        memcpy(dst: (unsigned __int8 *)LODWORD(v116), src: (unsigned __int8 *)nBoneCount, count: 4 * v117);
        texcoords = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)SortAndBalanceBones(
                                                                              iCount: v117,
                                                                              iMaxCount: 3,
                                                                              bones: v42,
                                                                              weights: v41);
        v43 = g_numverts;
        if ( g_bone.m_Size < g_numverts + 1 )
          CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
            this: &g_bone,
            elem: g_bone.m_Size,
            num: g_numverts + 1 - g_bone.m_Size);
        v44 = texcoords;
        g_bone.m_Memory.m_pMemory[v43].numbones = (int)texcoords;
        vNormal.z = 0.0;
        if ( (int)v44 <= 0 )
          goto LABEL_70;
        v45 = (unsigned __int8 *)LODWORD(v116);
        v114 = LODWORD(v116);
        nCount = (int)v115 - LODWORD(v116);
        while ( 2 )
        {
          v46 = *(_DWORD *)v45;
          v47 = pBoneRemap[*(_DWORD *)v45];
          if ( v47 >= 0 )
          {
            v50 = g_numverts;
            if ( g_bone.m_Size < g_numverts + 1 )
              CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                this: &g_bone,
                elem: g_bone.m_Size,
                num: g_numverts + 1 - g_bone.m_Size);
            g_bone.m_Memory.m_pMemory[v50].bone[LODWORD(vNormal.z)] = v47;
          }
          else
          {
            if ( v46 < 256 && v96[v46] == 0 )
            {
              v117 = *(_DWORD *)v45;
              v48 = CDmElement::GetName(this: pDmeDag);
              MdlWarning(
                fmt: "DmeMesh[%s] Verts Assigned To DmeModel.jointList[%d] Which Isn't Mapped To The Dag Hierarchy\n",
                v48,
                v117);
              v96[*(_DWORD *)v45] = 1;
            }
            v49 = g_numverts;
            if ( g_bone.m_Size < g_numverts + 1 )
              CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
                this: &g_bone,
                elem: g_bone.m_Size,
                num: g_numverts + 1 - g_bone.m_Size);
            g_bone.m_Memory.m_pMemory[v49].bone[LODWORD(vNormal.z)] = nBoneAssigna;
          }
          v51 = g_bone.m_Size;
          normals = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)g_numverts;
          if ( g_bone.m_Size < g_numverts + 1 && (v52 = g_numverts + 1 - g_bone.m_Size, v53 = g_bone.m_Size, v52 != 0) )
          {
            v100 = g_numverts + 1;
            if ( g_numverts + 1 > g_bone.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
                this: (CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> *)&g_bone,
                num: g_bone.m_Size + v52 - g_bone.m_Memory.m_nAllocationCount);
              v51 = g_bone.m_Size;
            }
            v54 = g_bone.m_Memory.m_pMemory;
            g_bone.m_Size = v52 + v51;
            v55 = v51 - v53;
            g_bone.m_pElements = g_bone.m_Memory.m_pMemory;
            if ( v55 > 0 && v52 > 0 )
            {
              _V_memmove(dest: &g_bone.m_Memory.m_pMemory[v100], src: &g_bone.m_Memory.m_pMemory[v53], count: 28 * v55);
              goto LABEL_68;
            }
          }
          else
          {
LABEL_68:
            v54 = g_bone.m_Memory.m_pMemory;
          }
          v56 = v114;
          v57 = LODWORD(vNormal.z) + 1;
          v54[(_DWORD)normals].weight[LODWORD(vNormal.z)] = *(float *)(nCount + v114);
          LODWORD(vNormal.z) = v57;
          v114 = v56 + 4;
          if ( v57 >= (int)texcoords )
            goto LABEL_70;
          v45 = (unsigned __int8 *)v114;
          continue;
        }
      }
      v35 = g_numverts;
      if ( g_bone.m_Size < g_numverts + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: g_numverts + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v35].numbones = 1;
      v36 = g_numverts;
      if ( g_bone.m_Size < g_numverts + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: g_numverts + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v36].bone[0] = nBoneAssigna;
      v37 = g_numverts;
      if ( g_bone.m_Size < g_numverts + 1 )
        CUtlVector<s_boneweight_t,CUtlMemory<s_boneweight_t,int>>::InsertMultipleBefore(
          this: &g_bone,
          elem: g_bone.m_Size,
          num: g_numverts + 1 - g_bone.m_Size);
      g_bone.m_Memory.m_pMemory[v37].weight[0] = 1.0;
LABEL_70:
      LODWORD(vNormal.x) += 12;
      v19 = ++g_numverts;
      ++LODWORD(vNormal.y);
      if ( SLODWORD(vNormal.y) >= j )
        goto LABEL_71;
    }
    _V_memmove(dest: &g_vertex.m_Memory.m_pMemory[(_DWORD)v24], src: &g_vertex.m_Memory.m_pMemory[v23], count: 12 * v26);
LABEL_29:
    m_pMemory = g_vertex.m_Memory.m_pMemory;
    goto LABEL_30;
  }
LABEL_71:
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v115);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v116));
  j = *(_DWORD *)(i + 12);
  v116 = 0.0;
  if ( j > 0 )
  {
    v115 = nullptr;
    do
    {
      v58 = (unsigned __int8 *)v115 + *(_DWORD *)i;
      v103 = *(float *)v58;
      positions = *((const CUtlVector<Vector,CUtlMemory<Vector,int> > **)v58 + 1);
      speeds = *((const CUtlVector<float,CUtlMemory<float,int> > **)v58 + 2);
      VectorNormalize(vec: (Vector *)&v103);
      v59 = 0;
      *(float *)&v59 = fsqrt(
                         (float)((float)(*(float *)&positions * *(float *)&positions)
                               + (float)(*(float *)&speeds * *(float *)&speeds))
                       + (float)(v103 * v103));
      normalMat_36 = v59;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v59 - 1.0) & _mask__AbsFloat_) > 0.01 )
        MdlWarning(
          fmt: "Non-Unit Length Normal [%d] < %8.6f %8.6f %8.6f >\n",
          v116,
          v103,
          *(float *)&positions,
          *(float *)&speeds);
      normals = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)g_numnormals;
      v60 = g_normal.m_Size;
      if ( g_normal.m_Size < g_numnormals + 1 )
      {
        v61 = g_numnormals + 1 - g_normal.m_Size;
        v62 = g_normal.m_Size;
        if ( v61 != 0 )
        {
          nCount = g_numnormals + 1;
          if ( g_numnormals + 1 > g_normal.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
              this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&g_normal,
              num: g_normal.m_Size + v61 - g_normal.m_Memory.m_nAllocationCount);
            v60 = g_normal.m_Size;
          }
          v63 = g_normal.m_Memory.m_pMemory;
          g_normal.m_Size = v61 + v60;
          v64 = v60 - v62;
          g_normal.m_pElements = g_normal.m_Memory.m_pMemory;
          if ( v64 <= 0 || v61 <= 0 )
            goto LABEL_83;
          _V_memmove(
            dest: &g_normal.m_Memory.m_pMemory[nCount],
            src: &g_normal.m_Memory.m_pMemory[v62],
            count: 12 * v64);
        }
      }
      v63 = g_normal.m_Memory.m_pMemory;
LABEL_83:
      VectorRotate(in1: &v103, in2: (const matrix3x4_t *)&pbWarnmap[244], out: &v63[(_DWORD)normals].x);
      ++g_numnormals;
      v115 += 3;
      ++LODWORD(v116);
    }
    while ( SLODWORD(v116) < j );
  }
  v65 = pBindState->m_bFlipVCoordinates.m_Storage;
  j = TextureCoordData->m_Size;
  HIBYTE(nBoneCount) = v65;
  v117 = 0;
  if ( j > 0 )
  {
    v66 = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)g_numtexcoords;
    while ( 1 )
    {
      v67 = &TextureCoordData->m_Memory.m_pMemory[v117].x;
      v68 = g_texcoord.m_Size;
      normals = v66;
      v69 = (int)&v66->m_Memory.m_pMemory + 1;
      if ( g_texcoord.m_Size >= v69 )
        goto LABEL_93;
      v70 = v69 - g_texcoord.m_Size;
      i = g_texcoord.m_Size;
      if ( v69 == g_texcoord.m_Size )
        goto LABEL_93;
      nCount = v69;
      if ( v69 > g_texcoord.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<mergelist_t,int>::Grow(
          this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
          num: g_texcoord.m_Size + v70 - g_texcoord.m_Memory.m_nAllocationCount);
        v68 = g_texcoord.m_Size;
      }
      v71 = g_texcoord.m_Memory.m_pMemory;
      g_texcoord.m_Size = v70 + v68;
      g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
      v72 = v68 - i;
      if ( v72 > 0 && v70 > 0 )
        break;
LABEL_94:
      v33 = HIBYTE(nBoneCount) == 0;
      v71[(_DWORD)normals].x = *v67;
      if ( v33 )
        y = TextureCoordData->m_Memory.m_pMemory[v117].y;
      else
        y = 1.0 - TextureCoordData->m_Memory.m_pMemory[v117].y;
      v74 = g_texcoord.m_Size;
      normals = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)g_numtexcoords;
      v116 = y;
      if ( g_texcoord.m_Size < g_numtexcoords + 1 )
      {
        v75 = g_numtexcoords + 1 - g_texcoord.m_Size;
        v76 = g_texcoord.m_Size;
        if ( v75 != 0 )
        {
          v77 = g_numtexcoords + 1;
          nCount = g_numtexcoords + 1;
          if ( g_numtexcoords + 1 > g_texcoord.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<mergelist_t,int>::Grow(
              this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&g_texcoord,
              num: g_texcoord.m_Size + v75 - g_texcoord.m_Memory.m_nAllocationCount);
            v74 = g_texcoord.m_Size;
            y = v116;
            v77 = nCount;
          }
          v78 = g_texcoord.m_Memory.m_pMemory;
          g_texcoord.m_Size = v75 + v74;
          v79 = v74 - v76;
          g_texcoord.m_pElements = g_texcoord.m_Memory.m_pMemory;
          if ( v79 <= 0 || v75 <= 0 )
            goto LABEL_105;
          _V_memmove(
            dest: &g_texcoord.m_Memory.m_pMemory[v77],
            src: &g_texcoord.m_Memory.m_pMemory[v76],
            count: 8 * v79);
          y = v116;
        }
      }
      v78 = g_texcoord.m_Memory.m_pMemory;
LABEL_105:
      v80 = v117;
      v78[(_DWORD)normals].y = y;
      v66 = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)++g_numtexcoords;
      v117 = v80 + 1;
      if ( v80 + 1 >= j )
        goto LABEL_106;
    }
    _V_memmove(dest: &g_texcoord.m_Memory.m_pMemory[nCount], src: &g_texcoord.m_Memory.m_pMemory[i], count: 8 * v72);
LABEL_93:
    v71 = g_texcoord.m_Memory.m_pMemory;
    goto LABEL_94;
  }
LABEL_106:
  v81 = BalanceData->m_Size;
  if ( v81 != 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::InsertMultipleBefore(
      this: &s_Balance,
      elem: s_Balance.m_Size,
      num: v81,
      pToInsert: BalanceData->m_Memory.m_pMemory);
  }
  else
  {
    v82 = s_Balance.m_Size;
    v83 = s_Balance.m_Size;
    if ( s_Balance.m_Size + 1 > s_Balance.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&s_Balance,
        num: s_Balance.m_Size - s_Balance.m_Memory.m_nAllocationCount + 1);
      v82 = s_Balance.m_Size;
    }
    v84 = s_Balance.m_Memory.m_pMemory;
    s_Balance.m_Size = v82 + 1;
    v85 = v82 - v83;
    s_Balance.m_pElements = s_Balance.m_Memory.m_pMemory;
    if ( v85 > 0 )
    {
      _V_memmove(dest: &s_Balance.m_Memory.m_pMemory[v83 + 1], src: &s_Balance.m_Memory.m_pMemory[v83], count: 4 * v85);
      v84 = s_Balance.m_Memory.m_pMemory;
    }
    v86 = &v84[v83];
    if ( v86 != nullptr )
      *v86 = 1.0;
  }
  v87 = balances->m_Size;
  if ( v87 != 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::InsertMultipleBefore(
      this: &s_Speed,
      elem: s_Speed.m_Size,
      num: v87,
      pToInsert: balances->m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    v89 = s_Speed.m_Size;
    v90 = s_Speed.m_Size;
    if ( s_Speed.m_Size + 1 > s_Speed.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&s_Speed,
        num: s_Speed.m_Size - s_Speed.m_Memory.m_nAllocationCount + 1);
      v89 = s_Speed.m_Size;
    }
    v91 = s_Speed.m_Memory.m_pMemory;
    s_Speed.m_Size = v89 + 1;
    v92 = v89 - v90;
    s_Speed.m_pElements = s_Speed.m_Memory.m_pMemory;
    if ( v92 > 0 )
    {
      _V_memmove(dest: &s_Speed.m_Memory.m_pMemory[v90 + 1], src: &s_Speed.m_Memory.m_pMemory[v90], count: 4 * v92);
      v91 = s_Speed.m_Memory.m_pMemory;
    }
    v93 = &v91[v90];
    if ( v93 != nullptr )
      *v93 = 1.0;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C880
// Name: LoadMesh
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadMesh@<al>(
        int *a1@<edi>,
        int a2@<esi>,
        CDmeDag *pDmeDag,
        CDmeMesh *pMesh,
        CDmeVertexData *pBindState,
        const matrix3x4_t *mat,
        float flScale,
        int nBoneAssign,
        int *pBoneRemap,
        s_source_t *pSource)
{
  CDmeMesh *v10; // edi
  int v11; // esi
  CDmeVertexDeltaData *DeltaState; // eax
  CDmeFaceSet *FaceSet; // ebx
  CDmeMaterial *v14; // eax
  const char *MaterialName; // eax
  int v16; // esi
  char *v17; // eax
  int v19; // eax
  int v20; // eax
  int m_Size; // esi
  int v22; // edi
  int NextPolygonVertexCount; // eax
  int *m_pMemory; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // edx
  int v28; // ebx
  int *v29; // esi
  int *v30; // esi
  unsigned int v31; // ebx
  char pPathNoExt[260]; // [esp+1Ch] [ebp-244h] BYREF
  char pTextureName[260]; // [esp+120h] [ebp-140h] BYREF
  int quadIndices[4]; // [esp+224h] [ebp-3Ch] BYREF
  int *pIndices; // [esp+234h] [ebp-2Ch]
  int nVertexCount; // [esp+238h] [ebp-28h]
  int nFaceSetCount; // [esp+23Ch] [ebp-24h]
  int nIndexCount; // [esp+240h] [ebp-20h]
  int nStartingTexCoord; // [esp+244h] [ebp-1Ch]
  int nStartingNormal; // [esp+248h] [ebp-18h]
  int nStartingVertex; // [esp+24Ch] [ebp-14h]
  CDmeFaceSet *pFaceSet; // [esp+250h] [ebp-10h]
  int i; // [esp+254h] [ebp-Ch]
  bool bQuadSubd; // [esp+25Bh] [ebp-5h]
  int material; // [esp+25Ch] [ebp-4h]
  int savedregs; // [esp+260h] [ebp+0h] BYREF

  v10 = pMesh;
  CDmeMesh::CollapseRedundantNormals(this: pMesh, flNormalBlend: normal_blend);
  nStartingVertex = g_numverts;
  nStartingTexCoord = g_numtexcoords;
  nStartingNormal = g_numnormals;
  i = s_UniqueVertices.m_Size;
  pFaceSet = (CDmeFaceSet *)s_UniqueVerticesMap.m_Size;
  LoadVertices(
    a1: (float *)&savedregs,
    a2: (int)pMesh,
    a3: a2,
    pDmeDag,
    pBindState,
    mat,
    flScale,
    nBoneAssign,
    pBoneRemap,
    pSource);
  v11 = 0;
  material = CDmeMesh::DeltaStateCount(this: pMesh);
  if ( material <= 0 )
  {
LABEL_4:
    nFaceSetCount = CDmeMesh::FaceSetCount(this: pMesh);
    for ( i = 0; i < nFaceSetCount; ++i )
    {
      FaceSet = CDmeMesh::GetFaceSet(this: v10, faceSetIndex: i);
      pFaceSet = FaceSet;
      v14 = CDmeFaceSet::GetMaterial(this: FaceSet);
      MaterialName = CDmeMaterial::GetMaterialName(this: v14);
      V_strncpy(pDest: pTextureName, pSrc: MaterialName, maxLen: 260);
      v16 = 0;
      if ( numrep > 0 )
      {
        v17 = sourcetexture[0];
        material = (int)sourcetexture;
        while ( *v17 != 0 && _V_stricmp(s1: pTextureName, s2: v17) != 0 )
        {
          material += 260;
          if ( ++v16 >= numrep )
            goto LABEL_14;
          v17 = (char *)material;
        }
        V_strncpy(pDest: pTextureName, pSrc: defaulttexture[v16], maxLen: 260);
      }
LABEL_14:
      V_StripExtension(in: pTextureName, out: pPathNoExt, outSize: 260);
      if ( _V_stricmp(s1: pPathNoExt, s2: "null") != 0 )
      {
        v19 = LookupTexture(pTextureName, bRelativePath: true);
        pSource->texmap[v19] = v19;
        v20 = UseTextureAsMaterial(textureindex: v19);
        m_Size = FaceSet->m_indices.m_Storage.m_Size;
        v22 = 0;
        material = v20;
        bQuadSubd = (gflags & 0x80000) != 0;
        nIndexCount = m_Size;
        while ( v22 < m_Size )
        {
          NextPolygonVertexCount = CDmeFaceSet::GetNextPolygonVertexCount(this: FaceSet, nFirstIndex: v22);
          nVertexCount = NextPolygonVertexCount;
          if ( bQuadSubd && NextPolygonVertexCount == 4 )
          {
            m_pMemory = FaceSet->m_indices.m_Storage.m_Memory.m_pMemory;
            v25 = m_pMemory[v22 + 1];
            quadIndices[0] = m_pMemory[v22];
            v26 = m_pMemory[v22 + 2];
            quadIndices[1] = v25;
            v27 = m_pMemory[v22 + 3];
            quadIndices[2] = v26;
            quadIndices[3] = v27;
            ParseQuadFaceData(
              material,
              pIndices: quadIndices,
              pVertexData: pBindState,
              vi: nStartingVertex,
              ni: nStartingNormal,
              ti: nStartingTexCoord);
            v22 += 5;
          }
          else
          {
            if ( NextPolygonVertexCount >= 3 )
            {
              v28 = 3 * NextPolygonVertexCount - 6;
              v29 = (int *)((int (__thiscall *)(IMemAlloc *, int, int *))_g_pMemAlloc->Alloc_2)(
                             a1: _g_pMemAlloc,
                             a2: 4 * v28,
                             a3: a1);
              pIndices = v29;
              CDmeMesh::ComputeTriangulatedIndices(
                this: pMesh,
                pBaseState: pBindState,
                pFaceSet,
                nFirstIndex: v22,
                pIndices: v29,
                nOutCount: v28);
              if ( v28 > 0 )
              {
                v30 = v29 + 2;
                v31 = (v28 - 1) / 3u + 1;
                do
                {
                  ParseFaceData(
                    pVertexData: pBindState,
                    material,
                    v1: *(v30 - 2),
                    v2: *v30,
                    v3: *(v30 - 1),
                    vi: nStartingVertex,
                    ni: nStartingNormal,
                    ti: nStartingTexCoord);
                  v30 += 3;
                  --v31;
                }
                while ( v31 != 0 );
                v29 = pIndices;
              }
              a1 = v29;
              ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
              FaceSet = pFaceSet;
              m_Size = nIndexCount;
              NextPolygonVertexCount = nVertexCount;
            }
            v22 += NextPolygonVertexCount + 1;
          }
        }
        v10 = pMesh;
      }
    }
    return 1;
  }
  else
  {
    while ( 1 )
    {
      DeltaState = CDmeMesh::GetDeltaState(this: pMesh, nDeltaIndex: v11);
      if ( LoadDeltaState(
             pDeltaState: DeltaState,
             nStartingUniqueVertex: i,
             pBindState,
             mat,
             flScale,
             nStartingUniqueVertexMap: (int)pFaceSet) == 0 )
        return 0;
      if ( ++v11 >= material )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CBB0
// Name: LoadMeshes
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadMeshes(
        const LoadMeshInfo_t *info,
        CDmeDag *pDag,
        const matrix3x4_t *parentToBindPose,
        int nBoneAssign)
{
  int JointIndex; // eax
  CDmeTransform *Transform; // eax
  CDmeShape *Shape; // eax
  CDmeMesh *v8; // esi
  CDmeVertexData *BaseState; // eax
  int v11; // esi
  CDmeDag *Child; // eax
  matrix3x4_t dagToParent; // [esp+20h] [ebp-60h] BYREF
  matrix3x4_t dagToBindPose; // [esp+50h] [ebp-30h] BYREF
  int nCount; // [esp+88h] [ebp+8h]

  JointIndex = CDmeModel::GetJointIndex(this: info->m_pModel, pJoint: pDag);
  if ( JointIndex < 0 )
  {
    Transform = CDmeDag::GetTransform(this: pDag);
    CDmeTransform::GetTransform(this: Transform, transform: &dagToParent);
    ConcatTransforms(in1: parentToBindPose, in2: &dagToParent, out: &dagToBindPose);
  }
  else
  {
    nBoneAssign = JointIndex;
    ConcatTransforms(in1: parentToBindPose, in2: &info->m_pBindPose[JointIndex], out: &dagToBindPose);
  }
  Shape = CDmeDag::GetShape(this: pDag);
  v8 = (CDmeMesh *)Shape;
  if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
  {
    BaseState = CDmeMesh::FindBaseState(this: v8, pStateName: "bind");
    if ( BaseState == nullptr
      || LoadMesh(
           a1: (int *)pDag,
           a2: (int)v8,
           pDmeDag: pDag,
           pMesh: v8,
           pBindState: BaseState,
           mat: &dagToBindPose,
           flScale: info->m_flScale,
           nBoneAssign,
           pBoneRemap: info->m_pBoneRemap,
           pSource: info->m_pSource) == 0 )
    {
      return 0;
    }
  }
  v11 = 0;
  nCount = CDmElementFramework::GetPhase(this: pDag);
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      Child = CDmeDag::GetChild(this: pDag, i: v11);
      if ( !LoadMeshes(info, pDag: Child, parentToBindPose: &dagToBindPose, nBoneAssign) )
        break;
      if ( ++v11 >= nCount )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040CCB0
// Name: LoadMeshes_0
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadMeshes_0(CDmeModel *pModel, __int64 flScale, s_source_t *pSource)
{
  CDmeModel *v3; // esi
  CDmeTransformList *BaseState; // eax
  CDmeTransformList *v5; // ebx
  int m_Size; // eax
  int v7; // edi
  int v8; // eax
  CDmeTransform *v9; // esi
  CDmeTransform *JointTransform; // eax
  int Phase; // edi
  int v12; // esi
  CDmeDag *Child; // eax
  LoadMeshInfo_t info; // [esp+Ch] [ebp-C040h] BYREF
  matrix3x4_t matrix; // [esp+C01Ch] [ebp-30h] BYREF
  matrix3x4_t *transform; // [esp+C058h] [ebp+Ch]
  int transform_4; // [esp+C05Ch] [ebp+10h]

  SetIdentityMatrix(&matrix);
  v3 = pModel;
  info.m_pModel = pModel;
  *(_QWORD *)&info.m_flScale = flScale;
  info.m_pSource = pSource;
  BaseState = CDmeModel::FindBaseState(this: pModel, pBaseStateName: "bind");
  v5 = BaseState;
  if ( BaseState != nullptr )
    m_Size = BaseState->m_Transforms.m_Storage.m_Size;
  else
    m_Size = CDmeModel::GetJointCount(this: pModel);
  v7 = 0;
  transform_4 = m_Size;
  if ( m_Size > 0 )
  {
    transform = info.m_pBindPose;
    do
    {
      if ( v5 != nullptr )
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: v5->m_Transforms.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTransform *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTransform::m_classType.u) != 0 )
        {
          JointTransform = v9;
          v3 = pModel;
        }
        else
        {
          v3 = pModel;
          JointTransform = nullptr;
        }
      }
      else
      {
        JointTransform = CDmeModel::GetJointTransform(this: v3, nIndex: v7);
      }
      CDmeTransform::GetTransform(this: JointTransform, transform: transform++);
      ++v7;
    }
    while ( v7 < transform_4 );
  }
  Phase = CDmElementFramework::GetPhase(this: v3);
  v12 = 0;
  if ( Phase <= 0 )
    return 1;
  while ( 1 )
  {
    Child = CDmeDag::GetChild(this: pModel, i: v12);
    if ( LoadMeshes(&info, pDag: Child, parentToBindPose: &matrix, nBoneAssign: -1) == 0 )
      break;
    if ( ++v12 >= Phase )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CEE0
// Name: int Load_DMX(struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_DMX(s_source_t *pSource)
{
  CDmeDag *Value; // ebx
  CDmeModel *v3; // edi
  CDmeCombinationOperator *v4; // eax
  CDmeAnimationList *v5; // eax
  BoneTransformMap_t boneMap; // [esp+2Ch] [ebp-310Ch] BYREF
  char pFullPath[260]; // [esp+3030h] [ebp-108h] BYREF
  CDmElement *pRoot; // [esp+3134h] [ebp-4h] BYREF

  if ( !GetGlobalFilePath(pSrc: pSource->filename, pFullPath, nMaxLen: 260)
    || (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, _DWORD, _DWORD, CDmElement **, _DWORD, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
         a1: g_pDataModel.u,
         a2: pFullPath,
         a3: 0,
         a4: 0,
         a5: &pRoot,
         a6: 0,
         a7: 0) == -1 )
  {
    return 0;
  }
  if ( !g_quiet )
    _Msg(a1: "DMX Model %s\n", pFullPath);
  LoadModelInfo(pRoot, pFullPath);
  LoadConstraints(pDmeRoot: pRoot);
  Value = CDmElement::GetValueElement<CDmeDag>(this: pRoot, pAttributeName: "skeleton");
  v3 = CDmElement::GetValueElement<CDmeModel>(this: pRoot, pAttributeName: "model");
  v4 = CDmElement::GetValueElement<CDmeCombinationOperator>(this: pRoot, pAttributeName: "combinationOperator");
  if ( LoadModelAndSkeleton(
         pSource,
         &boneMap,
         pSkeleton: Value,
         pModel: v3,
         pCombinationOperator: v4,
         bStaticProp: false) )
  {
    LoadQcModelElements(pSource, pModel: g_pCurrentModel, pDmeModel: v3);
    v5 = CDmElement::GetValueElement<CDmeAnimationList>(this: pRoot, pAttributeName: "animationList");
    if ( v5 != nullptr )
      LoadAnimations(pSource, pAnimationList: v5, flScale: g_currentscale, &boneMap);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
      a1: g_pDataModel.u,
      a2: pRoot->m_fileId);
    return 1;
  }
  else
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
      a1: g_pDataModel.u,
      a2: pRoot->m_fileId);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483740
// Name: public: int CDmaElementArrayConstBase<class CDmElement,class CDmaArrayBase<enum DmElementHandle_t,class CDmaDataExternal<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>>>::Find(class CDmElement const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::Find(
        CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > > *this,
        const CDmElement *pValue)
{
  if ( pValue == nullptr )
    return -1;
  pValue = (const CDmElement *)pValue->m_ref.m_hElement;
  return CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
           this,
           value: (const DmElementHandle_t *)&pValue);
}

//------------------------------------------------------------------------------
// Address: 0x004E4330
// Name: public: class CDmeDag __near * CAttributeReferenceIterator::FilterReference<class CDmeDag>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CAttributeReferenceIterator::FilterReference<CDmeDag>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeDag *result; // eax
  CDmeDag *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_24;
    case TD_DEEP:
      goto $LN11_19;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_19:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_24:
      v7 = *(CDmeDag **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeDag::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EC660
// Name: public: class CDmeChannel __near * CAttributeReferenceIterator::FilterReference<class CDmeChannel>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CAttributeReferenceIterator::FilterReference<CDmeChannel>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeChannel *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_25;
      case TD_DEEP:
        goto $LN11_20;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_20:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_25:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeChannel::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeChannel *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004ECE50
// Name: public: class CDmeOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeOperator *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_26;
      case TD_DEEP:
        goto $LN11_21;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_21:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_26:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeOperator::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeOperator *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004FE1D0
// Name: public: class CDmeRigBaseConstraintOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeRigBaseConstraintOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeRigBaseConstraintOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeRigBaseConstraintOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeRigBaseConstraintOperator *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_28;
      case TD_DEEP:
        goto $LN11_22;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_22:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_28:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeRigBaseConstraintOperator::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeRigBaseConstraintOperator *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00508240
// Name: public: class CDmeClip __near * CAttributeReferenceIterator::FilterReference<class CDmeClip>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CAttributeReferenceIterator::FilterReference<CDmeClip>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  CDmeClip *result; // eax
  CDmeClip *v7; // esi

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 == 0 )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_29;
    case TD_DEEP:
      goto $LN11_23;
    case TD_SHALLOW:
      if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
        return nullptr;
$LN11_23:
      if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
        return nullptr;
$LN4_29:
      v7 = *(CDmeClip **)(v5 + 8);
      if ( v7 == nullptr
        || !v7->IsA(this: v7, a2: CDmeClip::m_classType)
        || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id
        || bMustBeInSameFile && v7->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = v7;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A5530
// Name: public: class CDmeFlexRules __near * CAttributeReferenceIterator::FilterReference<class CDmeFlexRules>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // edi
  int v6; // esi
  CDmeFlexRules *result; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 332))(
         a1: g_pDataModel.u,
         a2: this->m_curr);
  if ( v5 != 0 )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_31;
      case TD_DEEP:
        goto $LN11_37;
      case TD_SHALLOW:
        if ( (*(_WORD *)(v5 + 16) & 0x800) == 0 )
          return nullptr;
$LN11_37:
        if ( (*(_WORD *)(v5 + 16) & 0x1000) != 0 )
          return nullptr;
$LN4_31:
        v6 = *(_DWORD *)(v5 + 8);
        if ( v6 == 0 )
          return nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeFlexRules::m_classType.u) == 0 )
          return nullptr;
        result = (CDmeFlexRules *)(v6 - 4);
        if ( v6 == 4 || symAttrName.u.m_Id != -1 && *(_DWORD *)(v5 + 20) != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005E9050
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED080
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00406680
// Name: class CDmElement __near * GetElement<class CDmElement>(enum DmElementHandle_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl GetElement<CDmElement>(DmElementHandle_t hElement)
{
  int v1; // eax
  int v2; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: hElement);
  v2 = v1;
  if ( v1 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v2;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ECF00
// Name: class CDmeOperator __near * FindReferringElement<class CDmeOperator>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeOperator *__cdecl FindReferringElement<CDmeOperator>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeOperator *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeOperator>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E9080
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9090
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED090
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

} // namespace studiomdl
