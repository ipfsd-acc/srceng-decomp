// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeanimationassemblycommand.cpp
// Functions: 64
// ============================================================

#include "mdlobjects\dmeanimationassemblycommand.h"

//------------------------------------------------------------------------------
// Address: 0x004A9450
// Name: protected: virtual void CDmeSubtract::Subtract(class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract(CDmeSubtract *this, Vector *vResult, const Vector *vDst, const Vector *vSrc)
{
  vResult->x = vDst->x - vSrc->x;
  vResult->y = vDst->y - vSrc->y;
  vResult->z = vDst->z - vSrc->z;
}

//------------------------------------------------------------------------------
// Address: 0x004A9490
// Name: protected: virtual void CDmeSubtract::Subtract(class Quaternion __near &,class Quaternion const __near &,class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract(
        CDmeSubtract *this,
        Quaternion *qResult,
        const Quaternion *qDst,
        const Quaternion *qSrc)
{
  QuaternionSM(s: -1.0, p: qSrc, q: qDst, qt: qResult);
}

//------------------------------------------------------------------------------
// Address: 0x004A94C0
// Name: protected: virtual void CDmePreSubtract::Subtract(class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePreSubtract::Subtract(
        CDmePreSubtract *this,
        Vector *vResult,
        const Vector *vDst,
        const Vector *vSrc)
{
  vResult->x = vSrc->x - vDst->x;
  vResult->y = vSrc->y - vDst->y;
  vResult->z = vSrc->z - vDst->z;
}

//------------------------------------------------------------------------------
// Address: 0x004A9500
// Name: protected: virtual void CDmePreSubtract::Subtract(class Quaternion __near &,class Quaternion const __near &,class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePreSubtract::Subtract(
        CDmePreSubtract *this,
        Quaternion *qResult,
        const Quaternion *qDst,
        const Quaternion *qSrc)
{
  QuaternionMA(p: qDst, s: -1.0, q: qSrc, qt: qResult);
}

//------------------------------------------------------------------------------
// Address: 0x004A99F0
// Name: GetDmeChannelsForDag
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetDmeChannelsForDag(
        CDmeTypedLog<Vector> **pDmeTranslateLog,
        CDmeTypedLog<Quaternion> **pDmeRotateLog,
        CDmeDag *pDmeDag,
        CDmeChannelsClip *pDmeChannelsClip)
{
  CDmeChannelsClip *v5; // esi
  CDmeTransform *Transform; // edi
  int v7; // eax
  int v8; // esi
  CDmeChannel *v9; // esi
  CDmeLog *Log; // eax
  CDmElement *v11; // edi
  CDmeTypedLog<Vector> *v12; // eax
  CUtlString *v13; // eax
  CUtlString *v14; // eax
  CUtlString *v15; // eax
  const char *v16; // eax
  CUtlString *v17; // ecx
  CDmeTypedLog<Quaternion> *v18; // eax
  CUtlString *v19; // eax
  CUtlString *v20; // eax
  CUtlString *v21; // eax
  const char *v22; // eax
  const char *v24; // [esp-8h] [ebp-78h]
  const char *v25; // [esp-8h] [ebp-78h]
  const char *v26; // [esp-4h] [ebp-74h]
  const char *v27; // [esp-4h] [ebp-74h]
  CUtlString v28; // [esp+Ch] [ebp-64h] BYREF
  CUtlString v29; // [esp+1Ch] [ebp-54h] BYREF
  CUtlString v30; // [esp+2Ch] [ebp-44h] BYREF
  CUtlString v31; // [esp+3Ch] [ebp-34h] BYREF
  CUtlString v32; // [esp+4Ch] [ebp-24h] BYREF
  CUtlString v33; // [esp+5Ch] [ebp-14h] BYREF
  CDmeTransform *pDmeTransform; // [esp+6Ch] [ebp-4h]
  CDmeTypedLog<Vector> **pDmeTranslateLoga; // [esp+78h] [ebp+8h]

  *pDmeTranslateLog = nullptr;
  *pDmeRotateLog = nullptr;
  if ( pDmeDag == nullptr )
    return 0;
  v5 = pDmeChannelsClip;
  if ( pDmeChannelsClip == nullptr )
    return 0;
  Transform = CDmeDag::GetTransform(this: pDmeDag);
  pDmeTransform = Transform;
  if ( Transform == nullptr )
    return 0;
  if ( pDmeChannelsClip->m_Channels.m_Storage.m_Size != 0 )
  {
    pDmeTranslateLoga = nullptr;
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(CDmeTypedLog<Vector> **)((char *)pDmeTranslateLoga
                                      + (unsigned int)v5->m_Channels.m_Storage.m_Memory.m_pMemory));
      v8 = v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v9 = (CDmeChannel *)(v8 - 4);
        if ( v9 != nullptr && CDmeChannel::GetToElement(this: v9) == Transform )
        {
          Log = CDmeChannel::GetLog(this: v9);
          v11 = Log;
          if ( Log != nullptr )
          {
            v12 = CastElement<CDmeTypedLog<Vector>>(pElement: Log);
            if ( v12 != nullptr )
            {
              if ( *pDmeTranslateLog != nullptr )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) == 0 )
                  goto LABEL_25;
                v13 = ComputeDmElementIdStr(result: &v31, pDmElement: &v9->CDmElement);
                v26 = CUtlString::Get(this: v13);
                v14 = ComputeDmElementIdStr(result: &v32, pDmElement: *pDmeTranslateLog);
                v24 = CUtlString::Get(this: v14);
                v15 = ComputeDmElementIdStr(result: &v33, pDmElement: pDmeDag);
                v16 = CUtlString::Get(this: v15);
                _LoggingSystem_Log(
                  a1: LOG_DME_AAC,
                  a2: 1,
                  a3: "%s: Multiple Translate Channels Found For Dag, Using %s, Ignoring %s\n",
                  v16,
                  v24,
                  v26);
                CUtlString::~CUtlString(this: &v33);
                CUtlString::~CUtlString(this: &v32);
                v17 = &v31;
LABEL_24:
                CUtlString::~CUtlString(this: v17);
                goto LABEL_25;
              }
              *pDmeTranslateLog = v12;
              if ( *pDmeRotateLog != nullptr )
                break;
            }
            else
            {
              v18 = CastElement<CDmeTypedLog<Quaternion>>(pElement: v11);
              if ( v18 == nullptr )
                goto LABEL_25;
              if ( *pDmeRotateLog != nullptr )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) == 0 )
                  goto LABEL_25;
                v19 = ComputeDmElementIdStr(result: &v28, pDmElement: &v9->CDmElement);
                v27 = CUtlString::Get(this: v19);
                v20 = ComputeDmElementIdStr(result: &v29, pDmElement: *pDmeRotateLog);
                v25 = CUtlString::Get(this: v20);
                v21 = ComputeDmElementIdStr(result: &v30, pDmElement: pDmeDag);
                v22 = CUtlString::Get(this: v21);
                _LoggingSystem_Log(
                  a1: LOG_DME_AAC,
                  a2: 1,
                  a3: "%s: Multiple Rotate Channels Found For Dag, Using %s, Ignoring %s\n",
                  v22,
                  v25,
                  v27);
                CUtlString::~CUtlString(this: &v30);
                CUtlString::~CUtlString(this: &v29);
                v17 = &v28;
                goto LABEL_24;
              }
              *pDmeRotateLog = v18;
              if ( *pDmeTranslateLog != nullptr )
                goto LABEL_27;
            }
          }
        }
      }
LABEL_25:
      v5 = pDmeChannelsClip;
      ++pDmeTranslateLoga;
      if ( pDmeChannelsClip->m_Channels.m_Storage.m_Size == 0 )
        break;
      Transform = pDmeTransform;
    }
  }
  if ( *pDmeTranslateLog != nullptr )
  {
LABEL_27:
    if ( *pDmeRotateLog != nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004AA5B0
// Name: ConvertToDmeSequenceAndDmeChannelsClip
// Source: json
//------------------------------------------------------------------------------
char __usercall ConvertToDmeSequenceAndDmeChannelsClip@<al>(
        CDmeSequence *pDmElement@<esi>,
        CUtlString *sDmElementId@<edi>,
        CDmeSequence **pDmeSequence,
        CDmeChannelsClip **pDmeChannelsClip)
{
  const char *v4; // eax
  const char *v6; // eax
  CDmeChannelsClip *DmeChannelsClip; // eax
  CUtlString *v8; // eax
  const char *v9; // eax
  const char *v10; // [esp-4h] [ebp-14h]
  CUtlString v11; // [esp+0h] [ebp-10h] BYREF

  if ( pDmElement == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v4 = CUtlString::operator char const *(this: sDmElementId);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: No DmElement Specified specified\n", v4);
    }
    return 0;
  }
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
         a1: pDmElement,
         a2: (CUtlSymbolLarge)CDmeSequence::m_classType.u.m_Id) )
  {
    DmeChannelsClip = CDmeSequence::GetDmeChannelsClip(this: pDmElement);
    if ( DmeChannelsClip != nullptr )
    {
      *pDmeSequence = pDmElement;
      *pDmeChannelsClip = DmeChannelsClip;
      return 1;
    }
    else
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
      {
        v8 = ComputeDmElementIdStr(result: &v11, pDmElement);
        v10 = CUtlString::Get(this: v8);
        v9 = CUtlString::operator char const *(this: sDmElementId);
        _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No DmeChannelsClip\n", v9, v10);
        v11.m_Storage.m_nActualLength = 0;
        if ( v11.m_Storage.m_Memory.m_nGrowSize >= 0 && v11.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11.m_Storage.m_Memory.m_pMemory);
      }
      return 0;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) == 0 )
      return 0;
    v6 = CUtlString::operator char const *(this: sDmElementId);
    _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: No DmeSequence Specified specified\n", v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AA6E0
// Name: protected: void CDmeFixupLoop::Apply<class Vector>(class CDmeTypedLog<class Vector> __near *,class DmeTime_t const __near &,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::Apply<Vector>(
        CDmeFixupLoop *this,
        CDmeTypedLog<Vector> *pDmeTypedLogDst,
        const DmeTime_t *dmeTimeStart,
        const DmeTime_t *dmeTimeEnd)
{
  int v4; // esi
  int v5; // eax
  int m_Size; // eax
  int v7; // edi
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  DmeTime_t *v10; // edi
  const QAngle *KeyValue; // eax
  Vector *v12; // edi
  DmeTime_t *v13; // ebx
  int v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  int v18; // eax
  int v19; // esi
  int v20; // edx
  int m_tms; // ecx
  float v22; // xmm0_4
  float *p_x; // ecx
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  int v27; // ecx
  float v28; // xmm0_4
  float *v29; // ecx
  float v30; // xmm6_4
  float v31; // xmm7_4
  float v32; // xmm0_4
  int v33; // ecx
  float v34; // xmm0_4
  float *v35; // ecx
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  int v39; // ecx
  float v40; // xmm0_4
  float *v41; // ecx
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm0_4
  int v45; // edx
  int v46; // ecx
  float v47; // xmm0_4
  float *v48; // ecx
  float v49; // xmm6_4
  float v50; // xmm7_4
  float v51; // xmm0_4
  int v52; // esi
  int v53; // ecx
  int v54; // edx
  int v55; // ebx
  float v56; // xmm0_4
  float v57; // xmm0_4
  float *v58; // eax
  float v59; // xmm7_4
  int v60; // edi
  float v61; // xmm0_4
  float v62; // xmm0_4
  Vector *v63; // eax
  float v64; // xmm7_4
  int v65; // edi
  float v66; // xmm0_4
  float v67; // xmm0_4
  Vector *v68; // eax
  float v69; // xmm7_4
  int v70; // edi
  float v71; // xmm0_4
  float v72; // xmm0_4
  Vector *v73; // eax
  float v74; // xmm7_4
  int v75; // ebx
  int v76; // edx
  float v77; // xmm0_4
  float v78; // xmm0_4
  float *v79; // eax
  float v80; // xmm7_4
  CDmeLogLayer *v81; // eax
  CDmeTypedLogLayer<Vector> *v82; // esi
  Vector *v83; // eax
  DmeTime_t *v84; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > values; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+20h] [ebp-30h] BYREF
  Vector newValue; // [esp+34h] [ebp-1Ch]
  float v88; // [esp+40h] [ebp-10h] BYREF
  int nKeyIndex; // [esp+44h] [ebp-Ch]
  float flTimeRange; // [esp+48h] [ebp-8h]
  int nKeyCount; // [esp+4Ch] [ebp-4h]
  float flScale; // [esp+5Ch] [ebp+Ch]

  v4 = 0;
  if ( pDmeTypedLogDst != nullptr )
  {
    v5 = dmeTimeEnd->m_tms - dmeTimeStart->m_tms;
    if ( (float)((float)v5 * 0.000099999997) > 0.0 && (float)((float)dmeTimeStart->m_tms * 0.000099999997) <= 0.0 )
    {
      flTimeRange = (float)v5 * 0.000099999997;
      nKeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLogDst);
      if ( nKeyCount > 0 )
      {
        memset(&times, 0, sizeof(times));
        memset(&values, 0, sizeof(values));
        do
        {
          nKeyIndex = (int)pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &v88, a3: v4);
          m_Size = times.m_Size;
          v7 = times.m_Size;
          if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
              num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
            m_Size = times.m_Size;
          }
          m_pMemory = times.m_Memory.m_pMemory;
          times.m_Size = m_Size + 1;
          v9 = m_Size - v7;
          times.m_pElements = times.m_Memory.m_pMemory;
          if ( v9 > 0 )
          {
            _V_memmove(dest: &times.m_Memory.m_pMemory[v7 + 1], src: &times.m_Memory.m_pMemory[v7], count: 4 * v9);
            m_pMemory = times.m_Memory.m_pMemory;
          }
          v10 = &m_pMemory[v7];
          if ( v10 != nullptr )
            v10->m_tms = *(int *)nKeyIndex;
          KeyValue = (const QAngle *)CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&values,
            elem: values.m_Size,
            src: KeyValue);
          ++v4;
        }
        while ( v4 < nKeyCount );
        v12 = values.m_Memory.m_pMemory;
        v13 = times.m_Memory.m_pMemory;
        v14 = nKeyCount;
        v15 = values.m_Memory.m_pMemory[nKeyCount - 1].x - values.m_Memory.m_pMemory->x;
        v16 = values.m_Memory.m_pMemory[nKeyCount - 1].y - values.m_Memory.m_pMemory->y;
        v17 = values.m_Memory.m_pMemory[nKeyCount - 1].z - values.m_Memory.m_pMemory->z;
        if ( (float)((float)dmeTimeStart->m_tms * 0.000099999997) < 0.0 )
        {
          v18 = dmeTimeStart->m_tms + times.m_Memory.m_pMemory[nKeyCount - 1].m_tms;
          v19 = 0;
          if ( nKeyCount >= 4 )
          {
            LODWORD(v88) = nKeyCount - 3;
            v20 = 0;
            do
            {
              m_tms = v13[v19].m_tms;
              if ( m_tms >= v18 )
              {
                LODWORD(v22) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(m_tms - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                p_x = &v12[v20].x;
                v24 = (float)(v22 * v15) + v12[v20].x;
                v25 = (float)(v22 * v16) + v12[v20].y;
                v26 = (float)(v22 * v17) + v12[v20].z;
                *p_x = v24;
                p_x[1] = v25;
                p_x[2] = v26;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v27 = v13[v19 + 1].m_tms;
              if ( v27 >= v18 )
              {
                LODWORD(v28) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v27 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v29 = &v12[v20 + 1].x;
                v30 = (float)(v28 * v15) + *v29;
                v31 = (float)(v28 * v16) + v12[v20 + 1].y;
                v32 = (float)(v28 * v17) + v12[v20 + 1].z;
                *v29 = v30;
                v29[1] = v31;
                v29[2] = v32;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v33 = v13[v19 + 2].m_tms;
              if ( v33 >= v18 )
              {
                LODWORD(v34) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v33 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v35 = &v12[v20 + 2].x;
                v36 = (float)(v34 * v15) + *v35;
                v37 = (float)(v34 * v16) + v12[v20 + 2].y;
                v38 = (float)(v34 * v17) + v12[v20 + 2].z;
                *v35 = v36;
                v35[1] = v37;
                v35[2] = v38;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v39 = v13[v19 + 3].m_tms;
              if ( v39 >= v18 )
              {
                LODWORD(v40) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v39 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v41 = &v12[v20 + 3].x;
                v42 = (float)(v40 * v15) + *v41;
                v43 = (float)(v40 * v16) + v12[v20 + 3].y;
                v44 = (float)(v40 * v17) + v12[v20 + 3].z;
                *v41 = v42;
                v41[1] = v43;
                v41[2] = v44;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v19 += 4;
              v20 += 4;
              nKeyIndex = v19;
            }
            while ( v19 < SLODWORD(v88) );
            v14 = nKeyCount;
          }
          if ( v19 < v14 )
          {
            v45 = v19;
            do
            {
              v46 = v13[v19].m_tms;
              if ( v46 >= v18 )
              {
                LODWORD(v47) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v46 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v48 = &v12[v45].x;
                v49 = (float)(v47 * v15) + v12[v45].x;
                v50 = (float)(v47 * v16) + v12[v45].y;
                v51 = (float)(v47 * v17) + v12[v45].z;
                *v48 = v49;
                v48[1] = v50;
                v48[2] = v51;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              ++v19;
              ++v45;
            }
            while ( v19 < nKeyCount );
          }
        }
        if ( (float)((float)dmeTimeEnd->m_tms * 0.000099999997) > 0.0 )
        {
          v52 = v13->m_tms;
          v53 = 0;
          if ( nKeyCount < 4 )
          {
LABEL_41:
            if ( v53 < nKeyCount )
            {
              v75 = v53;
              while ( 1 )
              {
                v76 = times.m_Memory.m_pMemory[v53].m_tms;
                if ( v76 > dmeTimeEnd->m_tms )
                  break;
                v77 = (float)((float)(v52 + dmeTimeEnd->m_tms - v76) * 0.000099999997) / flTimeRange;
                v78 = (float)((float)(v77 * 3.0) * v77) - (float)((float)((float)(v77 * 2.0) * v77) * v77);
                v79 = &v12[v75].x;
                newValue.x = (float)(v15 * v78) + v12[v75].x;
                newValue.y = (float)(v16 * v78) + v12[v75].y;
                v80 = (float)(v17 * v78) + v12[v75].z;
                ++v53;
                *v79 = newValue.x;
                ++v75;
                v79[1] = newValue.y;
                v79[2] = v80;
                if ( v53 >= nKeyCount )
                  break;
                v12 = values.m_Memory.m_pMemory;
              }
            }
          }
          else
          {
            v54 = 0;
            while ( 1 )
            {
              v55 = v13[v53].m_tms;
              if ( v55 > dmeTimeEnd->m_tms )
                break;
              flScale = 1.0 / flTimeRange;
              v56 = (float)((float)(v52 + dmeTimeEnd->m_tms - v55) * 0.000099999997) * (float)(1.0 / flTimeRange);
              v88 = (float)(v56 * 3.0) * v56;
              v57 = v88 - (float)((float)((float)(v56 * 2.0) * v56) * v56);
              v58 = &v12[v54].x;
              newValue.x = (float)(v15 * v57) + v12[v54].x;
              newValue.y = (float)(v16 * v57) + v12[v54].y;
              v59 = (float)(v17 * v57) + v12[v54].z;
              *v58 = newValue.x;
              v58[1] = newValue.y;
              v58[2] = v59;
              v60 = times.m_Memory.m_pMemory[v53 + 1].m_tms;
              if ( v60 > dmeTimeEnd->m_tms )
                break;
              v61 = (float)((float)(v52 + dmeTimeEnd->m_tms - v60) * 0.000099999997) * flScale;
              v88 = (float)(v61 * 3.0) * v61;
              v62 = v88 - (float)((float)((float)(v61 * 2.0) * v61) * v61);
              v63 = &values.m_Memory.m_pMemory[v54 + 1];
              newValue.x = (float)(v15 * v62) + v63->x;
              newValue.y = (float)(v16 * v62) + values.m_Memory.m_pMemory[v54 + 1].y;
              v64 = (float)(v17 * v62) + values.m_Memory.m_pMemory[v54 + 1].z;
              v63->x = newValue.x;
              v63->y = newValue.y;
              v63->z = v64;
              v65 = times.m_Memory.m_pMemory[v53 + 2].m_tms;
              if ( v65 > dmeTimeEnd->m_tms )
                break;
              v66 = (float)((float)(v52 + dmeTimeEnd->m_tms - v65) * 0.000099999997) * flScale;
              v88 = (float)(v66 * 3.0) * v66;
              v67 = v88 - (float)((float)((float)(v66 * 2.0) * v66) * v66);
              v68 = &values.m_Memory.m_pMemory[v54 + 2];
              newValue.x = (float)(v15 * v67) + v68->x;
              newValue.y = (float)(v16 * v67) + values.m_Memory.m_pMemory[v54 + 2].y;
              v69 = (float)(v17 * v67) + values.m_Memory.m_pMemory[v54 + 2].z;
              v68->x = newValue.x;
              v68->y = newValue.y;
              v68->z = v69;
              v70 = times.m_Memory.m_pMemory[v53 + 3].m_tms;
              if ( v70 > dmeTimeEnd->m_tms )
                break;
              v71 = (float)((float)(v52 + dmeTimeEnd->m_tms - v70) * 0.000099999997) * flScale;
              v88 = (float)(v71 * 3.0) * v71;
              v72 = v88 - (float)((float)((float)(v71 * 2.0) * v71) * v71);
              v73 = &values.m_Memory.m_pMemory[v54 + 3];
              newValue.x = (float)(v15 * v72) + v73->x;
              newValue.y = (float)(v16 * v72) + values.m_Memory.m_pMemory[v54 + 3].y;
              v74 = (float)(v17 * v72) + values.m_Memory.m_pMemory[v54 + 3].z;
              v73->x = newValue.x;
              v73->y = newValue.y;
              v73->z = v74;
              v12 = values.m_Memory.m_pMemory;
              v53 += 4;
              v54 += 4;
              if ( v53 >= nKeyCount - 3 )
                goto LABEL_41;
              v13 = times.m_Memory.m_pMemory;
            }
          }
        }
        v81 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
        v82 = (CDmeTypedLogLayer<Vector> *)v81;
        if ( v81 != nullptr && v81->IsA(this: v81, a2: CDmeTypedLogLayer<Vector>::m_classType) )
          CDmeTypedLogLayer<Vector>::SetAllKeys(this: v82, &times, &values);
        v83 = values.m_Memory.m_pMemory;
        values.m_Size = 0;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( values.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
            v83 = nullptr;
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        values.m_pElements = v83;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v83 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v83);
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        v84 = times.m_Memory.m_pMemory;
        times.m_Size = 0;
        if ( times.m_Memory.m_nGrowSize >= 0 )
        {
          if ( times.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
            v84 = nullptr;
            times.m_Memory.m_pMemory = nullptr;
          }
          times.m_Memory.m_nAllocationCount = 0;
        }
        times.m_pElements = v84;
        if ( times.m_Memory.m_nGrowSize >= 0 && v84 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v84);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AAF90
// Name: protected: void CDmeFixupLoop::Apply<class Quaternion>(class CDmeTypedLog<class Quaternion> __near *,class DmeTime_t const __near &,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::Apply<Quaternion>(
        CDmeFixupLoop *this,
        CDmeTypedLog<Quaternion> *pDmeTypedLogDst,
        const DmeTime_t *dmeTimeStart,
        const DmeTime_t *dmeTimeEnd)
{
  CDmeTypedLog<Quaternion> *v4; // esi
  int v5; // edi
  int v6; // eax
  int KeyCount; // ebx
  int m_Size; // eax
  int v9; // esi
  DmeTime_t *m_pMemory; // ecx
  int v11; // eax
  DmeTime_t *v12; // esi
  const Quaternion *KeyValue; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // esi
  int m_tms; // eax
  float v18; // xmm0_4
  int v19; // esi
  int v20; // ecx
  float v21; // xmm0_4
  int v22; // eax
  CDmeTypedLogLayer<Quaternion> *v23; // esi
  Quaternion *v24; // eax
  DmeTime_t *v25; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > values; // [esp+24h] [ebp-54h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+38h] [ebp-40h] BYREF
  Quaternion delta; // [esp+4Ch] [ebp-2Ch] BYREF
  Quaternion newValue; // [esp+5Ch] [ebp-1Ch] BYREF
  DmeTime_t v30; // [esp+6Ch] [ebp-Ch] BYREF
  DmeTime_t *v31; // [esp+70h] [ebp-8h]
  float flTimeRange; // [esp+74h] [ebp-4h]
  DmeTime_t dmeTimeBegin; // [esp+84h] [ebp+Ch]
  int dmeTimeBegina; // [esp+84h] [ebp+Ch]

  v4 = pDmeTypedLogDst;
  v5 = 0;
  if ( pDmeTypedLogDst != nullptr )
  {
    v6 = dmeTimeEnd->m_tms - dmeTimeStart->m_tms;
    if ( (float)((float)v6 * 0.000099999997) > 0.0 && (float)((float)dmeTimeStart->m_tms * 0.000099999997) <= 0.0 )
    {
      flTimeRange = (float)v6 * 0.000099999997;
      KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLogDst);
      if ( KeyCount > 0 )
      {
        memset(&times, 0, sizeof(times));
        memset(&values, 0, sizeof(values));
        do
        {
          v31 = v4->GetKeyTime(this: v4, result: &v30, a3: v5);
          m_Size = times.m_Size;
          v9 = times.m_Size;
          if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
              num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
            m_Size = times.m_Size;
          }
          m_pMemory = times.m_Memory.m_pMemory;
          times.m_Size = m_Size + 1;
          v11 = m_Size - v9;
          times.m_pElements = times.m_Memory.m_pMemory;
          if ( v11 > 0 )
          {
            _V_memmove(dest: &times.m_Memory.m_pMemory[v9 + 1], src: &times.m_Memory.m_pMemory[v9], count: 4 * v11);
            m_pMemory = times.m_Memory.m_pMemory;
          }
          v12 = &m_pMemory[v9];
          if ( v12 != nullptr )
            v12->m_tms = v31->m_tms;
          KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v5);
          CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
            this: &values,
            elem: values.m_Size,
            src: KeyValue);
          v4 = pDmeTypedLogDst;
          ++v5;
        }
        while ( v5 < KeyCount );
        v14 = 0;
        QuaternionMA(p: &values.m_Memory.m_pMemory[KeyCount - 1], s: -1.0, q: values.m_Memory.m_pMemory, qt: &delta);
        if ( (float)((float)dmeTimeStart->m_tms * 0.000099999997) < 0.0 )
        {
          v15 = dmeTimeStart->m_tms + times.m_Memory.m_pMemory[KeyCount - 1].m_tms;
          dmeTimeBegin.m_tms = v15;
          v16 = 0;
          do
          {
            m_tms = times.m_Memory.m_pMemory[v14].m_tms;
            if ( m_tms >= v15 )
            {
              v18 = (float)((float)(m_tms - v15) * 0.000099999997) / flTimeRange;
              QuaternionSM(
                s: COERCE_FLOAT(
                  COERCE_UNSIGNED_INT((float)((float)(v18 * 3.0) * v18) - (float)((float)((float)(v18 * 2.0) * v18) * v18))
                ^ _mask__NegFloat_),
                p: &delta,
                q: &values.m_Memory.m_pMemory[v16],
                qt: &newValue);
              v15 = dmeTimeBegin.m_tms;
              values.m_Memory.m_pMemory[v16] = newValue;
            }
            ++v14;
            ++v16;
          }
          while ( v14 < KeyCount );
          v4 = pDmeTypedLogDst;
          v14 = 0;
        }
        if ( (float)((float)dmeTimeEnd->m_tms * 0.000099999997) > 0.0 )
        {
          dmeTimeBegina = times.m_Memory.m_pMemory->m_tms;
          v19 = 0;
          do
          {
            v20 = times.m_Memory.m_pMemory[v14].m_tms;
            if ( v20 > dmeTimeEnd->m_tms )
              break;
            v21 = (float)((float)(dmeTimeBegina + dmeTimeEnd->m_tms - v20) * 0.000099999997) / flTimeRange;
            QuaternionSM(
              s: (float)((float)(v21 * 3.0) * v21) - (float)((float)((float)(v21 * 2.0) * v21) * v21),
              p: &delta,
              q: &values.m_Memory.m_pMemory[v19],
              qt: &newValue);
            values.m_Memory.m_pMemory[v19] = newValue;
            ++v14;
            ++v19;
          }
          while ( v14 < KeyCount );
          v4 = pDmeTypedLogDst;
        }
        v22 = (int)v4->AddNewLayer(this: v4);
        v23 = (CDmeTypedLogLayer<Quaternion> *)v22;
        if ( v22 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
               a1: v22,
               a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v23, &times, &values);
        }
        v24 = values.m_Memory.m_pMemory;
        values.m_Size = 0;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( values.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
            v24 = nullptr;
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        values.m_pElements = v24;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v24 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        v25 = times.m_Memory.m_pMemory;
        times.m_Size = 0;
        if ( times.m_Memory.m_nGrowSize >= 0 )
        {
          if ( times.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
            v25 = nullptr;
            times.m_Memory.m_pMemory = nullptr;
          }
          times.m_Memory.m_nAllocationCount = 0;
        }
        times.m_pElements = v25;
        if ( times.m_Memory.m_nGrowSize >= 0 && v25 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AB350
// Name: protected: void CDmeSubtract::Subtract<class Vector>(class CDmeTypedLog<class Vector> __near *,class CDmeTypedLog<class Vector> const __near *,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract<Vector>(
        CDmeSubtract *this,
        CDmeTypedLog<Vector> *pDmeTypedLogDst,
        CDmeTypedLog<Vector> *pDmeTypedLogSrc,
        const DmeTime_t *dmeTimeSrc)
{
  int v4; // ebx
  int m_Size; // eax
  int v6; // esi
  DmeTime_t *m_pMemory; // ecx
  int v8; // eax
  DmeTime_t *v9; // eax
  CDmeSubtract_vtbl *v10; // esi
  const Vector *KeyValue; // eax
  int v12; // eax
  int v13; // esi
  Vector *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  CDmeLogLayer *v17; // eax
  CDmeTypedLogLayer<Vector> *v18; // esi
  Vector *v19; // eax
  DmeTime_t *v20; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > values; // [esp+20h] [ebp-30h] BYREF
  Vector valueDst; // [esp+34h] [ebp-1Ch] BYREF
  Vector valueSrc; // [esp+40h] [ebp-10h] BYREF
  CDmeSubtract *v25; // [esp+4Ch] [ebp-4h]

  v25 = this;
  v4 = 0;
  valueSrc = *CDmeTypedLog<Vector>::GetValue(this: pDmeTypedLogSrc, time: (DmeTime_t)dmeTimeSrc->m_tms);
  memset(&times, 0, sizeof(times));
  memset(&values, 0, sizeof(values));
  if ( CDmeLog::GetKeyCount(this: pDmeTypedLogDst) > 0 )
  {
    do
    {
      dmeTimeSrc = pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &pDmeTypedLogSrc, a3: v4);
      m_Size = times.m_Size;
      v6 = times.m_Size;
      if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
          num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
        m_Size = times.m_Size;
      }
      m_pMemory = times.m_Memory.m_pMemory;
      times.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      times.m_pElements = times.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &times.m_Memory.m_pMemory[v6 + 1], src: &times.m_Memory.m_pMemory[v6], count: 4 * v8);
        m_pMemory = times.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_tms = dmeTimeSrc->m_tms;
      v10 = v25->__vftable;
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
      v10->Subtract_2(this: v25, a2: &valueDst, a3: KeyValue, a4: &valueSrc);
      v12 = values.m_Size;
      v13 = values.m_Size;
      if ( values.m_Size + 1 > values.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&values,
          num: values.m_Size - values.m_Memory.m_nAllocationCount + 1);
        v12 = values.m_Size;
      }
      v14 = values.m_Memory.m_pMemory;
      values.m_Size = v12 + 1;
      v15 = v12 - v13;
      values.m_pElements = values.m_Memory.m_pMemory;
      if ( v15 > 0 )
      {
        _V_memmove(dest: &values.m_Memory.m_pMemory[v13 + 1], src: &values.m_Memory.m_pMemory[v13], count: 12 * v15);
        v14 = values.m_Memory.m_pMemory;
      }
      v16 = &v14[v13];
      if ( v16 != nullptr )
        *v16 = valueDst;
      ++v4;
    }
    while ( v4 < CDmeLog::GetKeyCount(this: pDmeTypedLogDst) );
  }
  v17 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
  v18 = (CDmeTypedLogLayer<Vector> *)v17;
  if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmeTypedLogLayer<Vector>::m_classType) )
    CDmeTypedLogLayer<Vector>::SetAllKeys(this: v18, &times, &values);
  v19 = values.m_Memory.m_pMemory;
  values.m_Size = 0;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( values.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
      v19 = nullptr;
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  values.m_pElements = v19;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  v20 = times.m_Memory.m_pMemory;
  times.m_Size = 0;
  if ( times.m_Memory.m_nGrowSize >= 0 )
  {
    if ( times.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
      v20 = nullptr;
      times.m_Memory.m_pMemory = nullptr;
    }
    times.m_Memory.m_nAllocationCount = 0;
  }
  times.m_pElements = v20;
  if ( times.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x004AB580
// Name: protected: void CDmeSubtract::Subtract<class Quaternion>(class CDmeTypedLog<class Quaternion> __near *,class CDmeTypedLog<class Quaternion> const __near *,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract<Quaternion>(
        CDmeSubtract *this,
        CDmeTypedLog<Quaternion> *pDmeTypedLogDst,
        CDmeTypedLog<Quaternion> *pDmeTypedLogSrc,
        const DmeTime_t *dmeTimeSrc)
{
  int v4; // ebx
  int m_Size; // eax
  int v6; // esi
  DmeTime_t *m_pMemory; // ecx
  int v8; // eax
  DmeTime_t *v9; // eax
  CDmeSubtract_vtbl *v10; // esi
  const Quaternion *KeyValue; // eax
  int v12; // eax
  int v13; // esi
  Quaternion *v14; // ecx
  int v15; // eax
  Quaternion *v16; // esi
  CDmeLogLayer *v17; // eax
  CDmeTypedLogLayer<Quaternion> *v18; // esi
  Quaternion *v19; // eax
  DmeTime_t *v20; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > values; // [esp+20h] [ebp-38h] BYREF
  Quaternion valueDst; // [esp+34h] [ebp-24h] BYREF
  Quaternion valueSrc; // [esp+44h] [ebp-14h] BYREF
  CDmeSubtract *v25; // [esp+54h] [ebp-4h]

  v25 = this;
  v4 = 0;
  valueSrc = *CDmeTypedLog<Quaternion>::GetValue(this: pDmeTypedLogSrc, time: (DmeTime_t)dmeTimeSrc->m_tms);
  memset(&times, 0, sizeof(times));
  memset(&values, 0, sizeof(values));
  if ( CDmeLog::GetKeyCount(this: pDmeTypedLogDst) > 0 )
  {
    do
    {
      dmeTimeSrc = pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &pDmeTypedLogSrc, a3: v4);
      m_Size = times.m_Size;
      v6 = times.m_Size;
      if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
          num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
        m_Size = times.m_Size;
      }
      m_pMemory = times.m_Memory.m_pMemory;
      times.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      times.m_pElements = times.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &times.m_Memory.m_pMemory[v6 + 1], src: &times.m_Memory.m_pMemory[v6], count: 4 * v8);
        m_pMemory = times.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_tms = dmeTimeSrc->m_tms;
      v10 = v25->__vftable;
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
      v10->Subtract(this: v25, a2: &valueDst, a3: KeyValue, a4: &valueSrc);
      v12 = values.m_Size;
      v13 = values.m_Size;
      if ( values.m_Size + 1 > values.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&values,
          num: values.m_Size - values.m_Memory.m_nAllocationCount + 1);
        v12 = values.m_Size;
      }
      v14 = values.m_Memory.m_pMemory;
      values.m_Size = v12 + 1;
      v15 = v12 - v13;
      values.m_pElements = values.m_Memory.m_pMemory;
      if ( v15 > 0 )
      {
        _V_memmove(dest: &values.m_Memory.m_pMemory[v13 + 1], src: &values.m_Memory.m_pMemory[v13], count: 16 * v15);
        v14 = values.m_Memory.m_pMemory;
      }
      v16 = &v14[v13];
      if ( v16 != nullptr )
        *v16 = valueDst;
      ++v4;
    }
    while ( v4 < CDmeLog::GetKeyCount(this: pDmeTypedLogDst) );
  }
  v17 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
  v18 = (CDmeTypedLogLayer<Quaternion> *)v17;
  if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmeTypedLogLayer<Quaternion>::m_classType) )
    CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v18, &times, &values);
  v19 = values.m_Memory.m_pMemory;
  values.m_Size = 0;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( values.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
      v19 = nullptr;
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  values.m_pElements = v19;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  v20 = times.m_Memory.m_pMemory;
  times.m_Size = 0;
  if ( times.m_Memory.m_nGrowSize >= 0 )
  {
    if ( times.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
      v20 = nullptr;
      times.m_Memory.m_pMemory = nullptr;
    }
    times.m_Memory.m_nAllocationCount = 0;
  }
  times.m_pElements = v20;
  if ( times.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x004AB7B0
// Name: GetAllKeys_Vector_
// Source: json
//------------------------------------------------------------------------------
void __usercall GetAllKeys_Vector_(
        CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *keyTimes@<edi>,
        CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *keyValues@<esi>,
        CDmeTypedLog<Vector> *pDmeTypedLog)
{
  CDmeTypedLog<Vector> *v3; // ebx
  int KeyCount; // eax
  int v5; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  DmeTime_t *v10; // ebx
  const Vector *KeyValue; // eax
  int v12; // ebx
  int v13; // eax
  Vector *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  int *v17; // eoff
  DmeTime_t v18; // [esp+4h] [ebp-10h] BYREF
  int *v19; // [esp+8h] [ebp-Ch]
  int nKeyCount; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v3 = pDmeTypedLog;
  keyTimes->m_Storage.m_Size = 0;
  keyValues->m_Storage.m_Size = 0;
  KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLog);
  nKeyCount = KeyCount;
  if ( KeyCount > 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: keyTimes, num: KeyCount);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(this: keyValues, num: nKeyCount);
    i = 0;
    while ( 1 )
    {
      v5 = (int)v3->GetKeyTime(this: v3, result: &v18, a3: i);
      m_Size = keyTimes->m_Storage.m_Size;
      v19 = (int *)v5;
      m_nAllocationCount = keyTimes->m_Storage.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)keyTimes,
          num: m_Size - m_nAllocationCount + 1);
      ++keyTimes->m_Storage.m_Size;
      m_pMemory = keyTimes->m_Storage.m_Memory.m_pMemory;
      v9 = keyTimes->m_Storage.m_Size - m_Size - 1;
      keyTimes->m_Storage.m_pElements = keyTimes->m_Storage.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v10 = &keyTimes->m_Storage.m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        v10->m_tms = *v19;
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLog, nKeyIndex: i);
      v12 = keyValues->m_Storage.m_Size;
      v19 = (int *)KeyValue;
      v13 = keyValues->m_Storage.m_Memory.m_nAllocationCount;
      if ( v12 + 1 > v13 )
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)keyValues,
          num: v12 - v13 + 1);
      ++keyValues->m_Storage.m_Size;
      v14 = (Vector *)keyValues->m_Storage.m_Memory.m_pMemory;
      v15 = keyValues->m_Storage.m_Size - v12 - 1;
      keyValues->m_Storage.m_pElements = keyValues->m_Storage.m_Memory.m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 12 * v15);
      v16 = (Vector *)&keyValues->m_Storage.m_Memory.m_pMemory[v12];
      if ( v16 != nullptr )
      {
        v17 = v19;
        *(_QWORD *)&v16->x = *(_QWORD *)v19;
        LODWORD(v16->z) = v17[2];
      }
      if ( ++i >= nKeyCount )
        break;
      v3 = pDmeTypedLog;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AB900
// Name: GetAllKeys_Quaternion_
// Source: json
//------------------------------------------------------------------------------
void __usercall GetAllKeys_Quaternion_(
        CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *keyTimes@<esi>,
        CDmaArrayBase<Quaternion,CDmaDataInternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *keyValues,
        CDmeTypedLog<Quaternion> *pDmeTypedLog)
{
  CDmeTypedLog<Quaternion> *v4; // edi
  int KeyCount; // eax
  int v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmeTime_t *m_pMemory; // ecx
  int v10; // eax
  DmeTime_t *v11; // edi
  const Quaternion *KeyValue; // eax
  int v13; // edi
  int v14; // eax
  Quaternion *v15; // ecx
  int v16; // eax
  Quaternion *v17; // edi
  int *v18; // eax
  DmeTime_t v19; // [esp+8h] [ebp-Ch] BYREF
  int *v20; // [esp+Ch] [ebp-8h]
  int nKeyCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v4 = pDmeTypedLog;
  keyTimes->m_Storage.m_Size = 0;
  keyValues->m_Storage.m_Size = 0;
  KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLog);
  nKeyCount = KeyCount;
  if ( KeyCount > 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: keyTimes, num: KeyCount);
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(this: keyValues, num: nKeyCount);
    i = 0;
    while ( 1 )
    {
      v6 = (int)v4->GetKeyTime(this: v4, result: &v19, a3: i);
      m_Size = keyTimes->m_Storage.m_Size;
      v20 = (int *)v6;
      m_nAllocationCount = keyTimes->m_Storage.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)keyTimes,
          num: m_Size - m_nAllocationCount + 1);
      ++keyTimes->m_Storage.m_Size;
      m_pMemory = keyTimes->m_Storage.m_Memory.m_pMemory;
      v10 = keyTimes->m_Storage.m_Size - m_Size - 1;
      keyTimes->m_Storage.m_pElements = keyTimes->m_Storage.m_Memory.m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &keyTimes->m_Storage.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        v11->m_tms = *v20;
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLog, nKeyIndex: i);
      v13 = keyValues->m_Storage.m_Size;
      v20 = (int *)KeyValue;
      v14 = keyValues->m_Storage.m_Memory.m_nAllocationCount;
      if ( v13 + 1 > v14 )
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)keyValues,
          num: v13 - v14 + 1);
      ++keyValues->m_Storage.m_Size;
      v15 = keyValues->m_Storage.m_Memory.m_pMemory;
      v16 = keyValues->m_Storage.m_Size - v13 - 1;
      keyValues->m_Storage.m_pElements = keyValues->m_Storage.m_Memory.m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &v15[v13 + 1], src: &v15[v13], count: 16 * v16);
      v17 = &keyValues->m_Storage.m_Memory.m_pMemory[v13];
      if ( v17 != nullptr )
      {
        v18 = v20;
        *(_QWORD *)&v17->x = *(_QWORD *)v20;
        *(_QWORD *)&v17->z = *((_QWORD *)v18 + 1);
      }
      if ( ++i >= nKeyCount )
        break;
      v4 = pDmeTypedLog;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ABAC0
// Name: public: virtual bool CDmeFixupLoop::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeFixupLoop::Apply(CDmeFixupLoop *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  const char *v3; // ecx
  CDmeSequence *v5; // esi
  const char *v6; // ecx
  CDmeChannelsClip *FrameCount; // eax
  int m_Storage; // esi
  int v9; // ecx
  int i; // edi
  int v11; // eax
  int v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v14; // esi
  CUtlString *v15; // eax
  CUtlString *v16; // eax
  const char *v17; // eax
  const char *v18; // [esp-8h] [ebp-4Ch] BYREF
  const char *TypeString; // [esp-4h] [ebp-48h]
  CUtlString v20; // [esp+Ch] [ebp-38h] BYREF
  CUtlString v21; // [esp+1Ch] [ebp-28h] BYREF
  DmeTime_t nStartTime; // [esp+2Ch] [ebp-18h] BYREF
  DmeTime_t nEndTime; // [esp+30h] [ebp-14h] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+34h] [ebp-10h] BYREF
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+38h] [ebp-Ch] BYREF
  CDmeFixupLoop *v26; // [esp+3Ch] [ebp-8h]
  DmeFramerate_t dmeFrameRateDst; // [esp+40h] [ebp-4h] BYREF
  bool pDmElement_3; // [esp+4Fh] [ebp+Bh]

  v26 = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v20, pDmElement: this);
  pDmElement_3 = ConvertToDmeSequenceAndDmeChannelsClip(
                   pDmElement,
                   sDmElementId: v2,
                   pDmeSequence: &pDmeSequenceDst,
                   pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v20.m_Storage.m_nActualLength = 0;
  if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 && v20.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
  if ( pDmElement_3 )
    return 0;
  TypeString = nullptr;
  v18 = v3;
  DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v18, fps: 0x1Eu);
  v5 = pDmeSequenceDst;
  CDmeSequence::GetFrameRate(
    this: pDmeSequenceDst,
    result: &dmeFrameRateDst,
    fallbackFrameRate: (DmeFramerate_t)v18,
    bForceFallback: (int)TypeString);
  TypeString = nullptr;
  v18 = v6;
  DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v18, fps: 0x1Eu);
  FrameCount = CDmeSequence::GetFrameCount(
                 this: v5,
                 fallbackFrameRate: (DmeFramerate_t)v18,
                 bForceFallback: (int)TypeString);
  m_Storage = v26->m_nEndFrame.m_Storage;
  v9 = v26->m_nStartFrame.m_Storage;
  if ( m_Storage - v9 > (int)FrameCount )
  {
    m_Storage = (int)FrameCount + v9;
    if ( (int)FrameCount + v9 < 0 )
    {
      m_Storage = 0;
      v9 = 1 - (_DWORD)FrameCount;
    }
  }
  DmeTime_t::DmeTime_t(this: &nStartTime, frame: v9, framerate: *(_DWORD *)&dmeFrameRateDst);
  DmeTime_t::DmeTime_t(this: &nEndTime, frame: m_Storage, framerate: *(_DWORD *)&dmeFrameRateDst);
  for ( i = 0; i < pDmeChannelsClipDst->m_Channels.m_Storage.m_Size; ++i )
  {
    v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: pDmeChannelsClipDst->m_Channels.m_Storage.m_Memory.m_pMemory[i]);
    v12 = v11;
    if ( v11 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
           a1: v11,
           a2: CDmeChannel::m_classType.u) != 0
      && v12 != 4 )
    {
      Log = CDmeChannel::GetLog(this: (CDmeChannel *)(v12 - 4));
      v14 = (CDmeTypedLog<Vector> *)Log;
      if ( Log != nullptr )
      {
        if ( Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) )
        {
          CDmeFixupLoop::Apply<Vector>(
            this: v26,
            pDmeTypedLogDst: v14,
            dmeTimeStart: &nStartTime,
            dmeTimeEnd: &nEndTime);
        }
        else if ( v14->IsA(this: v14, a2: CDmeTypedLog<Quaternion>::m_classType) )
        {
          CDmeFixupLoop::Apply<Quaternion>(
            this: v26,
            pDmeTypedLogDst: (CDmeTypedLog<Quaternion> *)v14,
            dmeTimeStart: &nStartTime,
            dmeTimeEnd: &nEndTime);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
        {
          TypeString = CDmElement::GetTypeString(this: v14);
          v15 = ComputeDmElementIdStr(result: &v20, pDmElement: pDmeSequenceDst);
          v18 = CUtlString::Get(this: v15);
          v16 = ComputeDmElementIdStr(result: &v21, pDmElement: v26);
          v17 = CUtlString::Get(this: v16);
          _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 1, a3: "%s: Unsupported DmeLog Type: \"%s\"\n", v17, v18);
          v21.m_Storage.m_nActualLength = 0;
          if ( v21.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v21.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21.m_Storage.m_Memory.m_pMemory);
              v21.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v21.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v20.m_Storage.m_nActualLength = 0;
          if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
              v20.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v20.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ABD50
// Name: public: virtual bool CDmeSubtract::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSubtract::Apply(CDmeSubtract *this, float pDmElement)
{
  CUtlString *v3; // edi
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeSequence *v6; // esi
  CUtlString *v7; // edi
  unsigned int v8; // ecx
  CDmeChannelsClip *v9; // edi
  DmeTime_t *StartTime; // eax
  __m128i v11; // xmm0
  CUtlSymbolLarge::<unnamed_type_u> v12; // eax
  float v13; // xmm0_4
  const char *m_Id; // esi
  CUtlString *v15; // eax
  CUtlString *v16; // eax
  const char *v17; // eax
  DmeTime_t *EndTime; // eax
  __m128i v19; // xmm0
  CUtlSymbolLarge::<unnamed_type_u> v20; // eax
  float v21; // xmm0_4
  const char *v22; // esi
  CUtlString *v23; // eax
  CUtlString *v24; // eax
  const char *v25; // eax
  CDmeChannelsClip *v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // esi
  int v30; // ebx
  CDmeLog *Log; // eax
  CDmeLog *v32; // esi
  char *v33; // ebx
  CDmeTypedLog<Vector> *v34; // edi
  CDmeTypedLog<Quaternion> *v35; // ebx
  int v36; // eax
  int v37; // esi
  CDmeChannel *v38; // esi
  const char *m_pAsString; // eax
  CDmeTypedLog<Vector> *v40; // esi
  CUtlString *v41; // eax
  CUtlString *v42; // eax
  const char *v43; // eax
  int m_Storage; // [esp+10h] [ebp-70h]
  int v45; // [esp+10h] [ebp-70h]
  double v46; // [esp+14h] [ebp-6Ch]
  double v47; // [esp+14h] [ebp-6Ch]
  double FramesPerSecond; // [esp+1Ch] [ebp-64h]
  double v49; // [esp+1Ch] [ebp-64h]
  const char *v50; // [esp+24h] [ebp-5Ch]
  const char *v51; // [esp+24h] [ebp-5Ch]
  double v52; // [esp+28h] [ebp-58h] BYREF
  CUtlString v53; // [esp+3Ch] [ebp-44h] BYREF
  CUtlString v54; // [esp+4Ch] [ebp-34h] BYREF
  DmeTime_t v55; // [esp+5Ch] [ebp-24h] BYREF
  int i; // [esp+60h] [ebp-20h]
  char *s1; // [esp+64h] [ebp-1Ch]
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+68h] [ebp-18h] BYREF
  CDmeSubtract *v59; // [esp+6Ch] [ebp-14h]
  DmeFramerate_t dmeFrameRateSrc; // [esp+70h] [ebp-10h] BYREF
  int j; // [esp+74h] [ebp-Ch] BYREF
  CDmeChannelsClip *pDmeChannelsClipSrc; // [esp+78h] [ebp-8h] BYREF
  DmeTime_t dmeTimeSrc; // [esp+7Ch] [ebp-4h] BYREF

  v59 = this;
  pDmeChannelsClipDst = nullptr;
  v3 = ComputeDmElementIdStr(result: &v53, pDmElement: this);
  HIBYTE(pDmElement) = ConvertToDmeSequenceAndDmeChannelsClip(
                         pDmElement: (CDmeSequence *)LODWORD(pDmElement),
                         sDmElementId: v3,
                         pDmeSequence: (CDmeSequence **)&pDmElement,
                         pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v53.m_Storage.m_nActualLength = 0;
  if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
  if ( HIBYTE(pDmElement) == 0 )
  {
    v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    HIDWORD(v52) = this->m_eSequence.m_Storage.m_Handle;
    j = 0;
    pDmeChannelsClipSrc = nullptr;
    v6 = (CDmeSequence *)((int (__thiscall *)(_DWORD, _DWORD))v5)(
                           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                           a2: HIDWORD(v52));
    v7 = ComputeDmElementIdStr(result: &v53, pDmElement: this);
    HIBYTE(pDmElement) = ConvertToDmeSequenceAndDmeChannelsClip(
                           pDmElement: v6,
                           sDmElementId: v7,
                           pDmeSequence: (CDmeSequence **)&j,
                           pDmeChannelsClip: &pDmeChannelsClipSrc) == 0;
    v53.m_Storage.m_nActualLength = 0;
    if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
    if ( HIBYTE(pDmElement) == 0 )
    {
      *(_QWORD *)&v52 = v8;
      DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v52, fps: 0x1Eu);
      CDmeSequence::GetFrameRate(
        this: (CDmeSequence *)j,
        result: &dmeFrameRateSrc,
        fallbackFrameRate: LODWORD(v52),
        bForceFallback: SHIDWORD(v52));
      DmeTime_t::DmeTime_t(this: &dmeTimeSrc, frame: this->m_nFrame.m_Storage, framerate: *(_DWORD *)&dmeFrameRateSrc);
      v9 = pDmeChannelsClipSrc;
      StartTime = CDmeClip::GetStartTime(this: pDmeChannelsClipSrc, result: (DmeTime_t *)&pDmElement);
      if ( dmeTimeSrc.m_tms < StartTime->m_tms
        && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
      {
        v11 = _mm_cvtsi32_si128(CDmeClip::GetStartTime(this: v9, result: &v55)->m_tms);
        v12.m_Id = (int)this->m_nFrame.m_pAttribute->m_Name.u;
        v13 = _mm_cvtepi32_ps(v11).m128_f32[0] * 0.000099999997;
        pDmElement = (float)dmeTimeSrc.m_tms * 0.000099999997;
        m_Id = WindowName;
        if ( v12.m_Id != -1 )
          m_Id = (const char *)v12.m_Id;
        v52 = v13;
        v15 = ComputeDmElementIdStr(result: &v53, pDmElement: (const CDmElement *)j);
        v50 = CUtlString::Get(this: v15);
        FramesPerSecond = DmeFramerate_t::GetFramesPerSecond(this: &dmeFrameRateSrc);
        v46 = pDmElement;
        m_Storage = this->m_nFrame.m_Storage;
        v16 = ComputeDmElementIdStr(result: &v54, pDmElement: this);
        v17 = CUtlString::Get(this: v16);
        _LoggingSystem_Log(
          a1: LOG_DME_AAC,
          a2: 1,
          a3: "%s: .%s %d (%.2fs @ %g fps) < %s Start Time of %.2fs\n",
          v17,
          m_Id,
          m_Storage,
          v46,
          FramesPerSecond,
          v50,
          v52);
        v54.m_Storage.m_nActualLength = 0;
        if ( v54.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v54.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_Storage.m_Memory.m_pMemory);
            v54.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v54.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v53.m_Storage.m_nActualLength = 0;
        if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
      }
      EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&pDmElement);
      if ( dmeTimeSrc.m_tms > EndTime->m_tms
        && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
      {
        v19 = _mm_cvtsi32_si128(CDmeClip::GetEndTime(this: v9, result: &v55)->m_tms);
        v20.m_Id = (int)this->m_nFrame.m_pAttribute->m_Name.u;
        v21 = _mm_cvtepi32_ps(v19).m128_f32[0] * 0.000099999997;
        pDmElement = (float)dmeTimeSrc.m_tms * 0.000099999997;
        v22 = WindowName;
        if ( v20.m_Id != -1 )
          v22 = (const char *)v20.m_Id;
        v52 = v21;
        v23 = ComputeDmElementIdStr(result: &v53, pDmElement: (const CDmElement *)j);
        v51 = CUtlString::Get(this: v23);
        v49 = DmeFramerate_t::GetFramesPerSecond(this: &dmeFrameRateSrc);
        v47 = pDmElement;
        v45 = this->m_nFrame.m_Storage;
        v24 = ComputeDmElementIdStr(result: &v54, pDmElement: this);
        v25 = CUtlString::Get(this: v24);
        _LoggingSystem_Log(
          a1: LOG_DME_AAC,
          a2: 1,
          a3: "%s: .%s %d (%.2fs @ %g fps) > %s End Time of %.2fs\n",
          v25,
          v22,
          v45,
          v47,
          v49,
          v51,
          v52);
        v54.m_Storage.m_nActualLength = 0;
        if ( v54.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v54.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_Storage.m_Memory.m_pMemory);
            v54.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v54.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v53.m_Storage.m_nActualLength = 0;
        if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
      }
      v26 = pDmeChannelsClipDst;
      v27 = 0;
      i = 0;
      if ( pDmeChannelsClipDst->m_Channels.m_Storage.m_Size <= 0 )
        return 1;
      do
      {
        v28 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v26->m_Channels.m_Storage.m_Memory.m_pMemory[v27]);
        v29 = v28;
        if ( v28 == 0 )
          goto LABEL_66;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v28 + 16))(
               a1: v28,
               a2: CDmeChannel::m_classType.u) == 0 )
          goto LABEL_66;
        v30 = v29 - 4;
        v55.m_tms = v29 - 4;
        if ( v29 == 4 )
          goto LABEL_66;
        Log = CDmeChannel::GetLog(this: (CDmeChannel *)(v29 - 4));
        v32 = Log;
        if ( Log == nullptr )
          goto LABEL_66;
        v33 = *(char **)(v30 + 24);
        s1 = (char *)WindowName;
        if ( v33 != (char *)-1 )
          s1 = v33;
        v34 = Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) ? (CDmeTypedLog<Vector> *)Log : nullptr;
        v35 = v32->IsA(this: v32, a2: CDmeTypedLog<Quaternion>::m_classType) ? (CDmeTypedLog<Quaternion> *)v32 : nullptr;
        HIBYTE(pDmElement) = 0;
        j = 0;
        if ( pDmeChannelsClipSrc->m_Channels.m_Storage.m_Size <= 0 )
        {
LABEL_56:
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
          {
            v41 = ComputeDmElementIdStr(result: &v53, pDmElement: (const CDmElement *)(v55.m_tms + 4));
            HIDWORD(v52) = CUtlString::Get(this: v41);
            v42 = ComputeDmElementIdStr(result: &v54, pDmElement: v59);
            v43 = CUtlString::Get(this: v42);
            _LoggingSystem_Log(
              a1: LOG_DME_AAC,
              a2: 1,
              a3: "%s: No Channel Found To Subtract From %s\n",
              v43,
              (const char *)HIDWORD(v52));
            v54.m_Storage.m_nActualLength = 0;
            if ( v54.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v54.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_Storage.m_Memory.m_pMemory);
                v54.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v54.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            v53.m_Storage.m_nActualLength = 0;
            if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v53.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
                v53.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v53.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
          goto LABEL_65;
        }
        do
        {
          v36 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: pDmeChannelsClipSrc->m_Channels.m_Storage.m_Memory.m_pMemory[j]);
          v37 = v36;
          if ( v36 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v36 + 16))(
                 a1: v36,
                 a2: CDmeChannel::m_classType.u) != 0 )
          {
            v38 = (CDmeChannel *)(v37 - 4);
            if ( v38 != nullptr )
            {
              m_pAsString = v38->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = WindowName;
              if ( _V_stricmp(s1, s2: m_pAsString) == 0 )
              {
                v40 = (CDmeTypedLog<Vector> *)CDmeChannel::GetLog(this: v38);
                if ( v40 != nullptr )
                {
                  if ( v40->IsA(this: v40, a2: CDmeTypedLog<Vector>::m_classType) && v34 != nullptr )
                  {
                    CDmeSubtract::Subtract<Vector>(this: v59, pDmeTypedLogDst: v34, pDmeTypedLogSrc: v40, &dmeTimeSrc);
LABEL_53:
                    HIBYTE(pDmElement) = 1;
                    goto LABEL_54;
                  }
                  if ( v40->IsA(this: v40, a2: CDmeTypedLog<Quaternion>::m_classType) && v35 != nullptr )
                  {
                    CDmeSubtract::Subtract<Quaternion>(
                      this: v59,
                      pDmeTypedLogDst: v35,
                      pDmeTypedLogSrc: (CDmeTypedLog<Quaternion> *)v40,
                      &dmeTimeSrc);
                    goto LABEL_53;
                  }
                }
              }
            }
          }
LABEL_54:
          ++j;
        }
        while ( j < pDmeChannelsClipSrc->m_Channels.m_Storage.m_Size );
        if ( HIBYTE(pDmElement) == 0 )
          goto LABEL_56;
LABEL_65:
        v27 = i;
LABEL_66:
        v26 = pDmeChannelsClipDst;
        i = ++v27;
      }
      while ( v27 < pDmeChannelsClipDst->m_Channels.m_Storage.m_Size );
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004AC350
// Name: protected: void CDmeBoneMaskCmd::SubApply(class CDmeChannelsClip __near *,class CDmeDag __near *,class CDmeBoneMask __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskCmd::SubApply(
        CDmeBoneMaskCmd *this,
        CDmeTypedLog<Vector> *pDmeChannelsClip,
        CDmeTypedLog<Quaternion> *pDmeDag,
        float pDmeBoneMask)
{
  CDmeChannelsClip *v4; // edi
  CDmeDag *v5; // esi
  const char *m_pAsString; // eax
  double BoneWeight; // st7
  CUtlString *v8; // eax
  CUtlString *v9; // eax
  const char *v10; // eax
  float v11; // xmm3_4
  int v12; // ecx
  int v13; // edx
  Vector *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  int v17; // edi
  int v18; // esi
  int v19; // eax
  CDmeTypedLogLayer<Vector> *v20; // esi
  CUtlString *v21; // eax
  const char *v22; // eax
  int v23; // eax
  CDmeTypedLogLayer<Quaternion> *v24; // esi
  CUtlString *v25; // eax
  const char *v26; // eax
  const char *v27; // [esp+4h] [ebp-94h]
  CUtlString result; // [esp+14h] [ebp-84h] BYREF
  Quaternion qTmp; // [esp+24h] [ebp-74h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > qTimes; // [esp+34h] [ebp-64h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > vTimes; // [esp+48h] [ebp-50h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > vValues; // [esp+5Ch] [ebp-3Ch] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > qValues; // [esp+70h] [ebp-28h] BYREF
  CUtlString v34; // [esp+84h] [ebp-14h] BYREF
  CDmElement *pDmElement; // [esp+94h] [ebp-4h]

  v4 = (CDmeChannelsClip *)pDmeChannelsClip;
  pDmElement = this;
  if ( pDmeChannelsClip != nullptr )
  {
    v5 = (CDmeDag *)pDmeDag;
    if ( pDmeDag != nullptr && pDmeBoneMask != 0.0 )
    {
      m_pAsString = pDmeDag->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = WindowName;
      BoneWeight = CDmeBoneMask::GetBoneWeight(this: (CDmeBoneMask *)LODWORD(pDmeBoneMask), pszBoneName: m_pAsString);
      pDmeBoneMask = BoneWeight;
      if ( BoneWeight != 1.0 && CDmeDag::GetTransform(this: v5) != nullptr )
      {
        pDmeChannelsClip = nullptr;
        pDmeDag = nullptr;
        if ( GetDmeChannelsForDag(
               pDmeTranslateLog: &pDmeChannelsClip,
               pDmeRotateLog: &pDmeDag,
               pDmeDag: v5,
               pDmeChannelsClip: v4) != 0 )
        {
          memset(&vTimes, 0, sizeof(vTimes));
          memset(&vValues, 0, sizeof(vValues));
          GetAllKeys_Vector_(
            keyTimes: (CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vTimes,
            keyValues: (CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *)&vValues,
            pDmeTypedLog: pDmeChannelsClip);
          v11 = pDmeBoneMask;
          v12 = 0;
          if ( vValues.m_Size > 0 )
          {
            v13 = 0;
            do
            {
              v14 = &vValues.m_Memory.m_pMemory[v13];
              v15 = vValues.m_Memory.m_pMemory[v13].y * v11;
              v16 = vValues.m_Memory.m_pMemory[v13].z * v11;
              ++v12;
              v14->x = vValues.m_Memory.m_pMemory[v13].x * v11;
              v14->y = v15;
              v14->z = v16;
              ++v13;
            }
            while ( v12 < vValues.m_Size );
          }
          memset(&qTimes, 0, sizeof(qTimes));
          memset(&qValues, 0, sizeof(qValues));
          GetAllKeys_Quaternion_(
            keyTimes: (CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&qTimes,
            keyValues: (CDmaArrayBase<Quaternion,CDmaDataInternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *)&qValues,
            pDmeTypedLog: pDmeDag);
          v17 = 0;
          if ( qValues.m_Size > 0 )
          {
            v18 = 0;
            do
            {
              QuaternionScale(p: &qValues.m_Memory.m_pMemory[v18], t: pDmeBoneMask, q: &qTmp);
              qValues.m_Memory.m_pMemory[v18] = qTmp;
              ++v17;
              ++v18;
            }
            while ( v17 < qValues.m_Size );
          }
          v19 = (int)pDmeChannelsClip->AddNewLayer(this: pDmeChannelsClip);
          v20 = (CDmeTypedLogLayer<Vector> *)v19;
          if ( v19 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v19 + 16))(
                 a1: v19,
                 a2: CDmeTypedLogLayer<Vector>::m_classType.u) != 0 )
          {
            CDmeTypedLogLayer<Vector>::SetAllKeys(this: v20, times: &vTimes, values: &vValues);
            v20->RemoveRedundantKeys_2(this: v20, a2: true);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
          {
            v21 = ComputeDmElementIdStr(result: &v34, pDmElement);
            v22 = CUtlString::Get(this: v21);
            _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Translate Layer\n", v22);
            v34.m_Storage.m_nActualLength = 0;
            if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
          }
          v23 = (int)pDmeDag->AddNewLayer(this: pDmeDag);
          v24 = (CDmeTypedLogLayer<Quaternion> *)v23;
          if ( v23 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v23 + 16))(
                 a1: v23,
                 a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
          {
            CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v24, times: &qTimes, values: &qValues);
            v24->RemoveRedundantKeys_2(this: v24, a2: true);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
          {
            v25 = ComputeDmElementIdStr(result: &v34, pDmElement);
            v26 = CUtlString::Get(this: v25);
            _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Rotate Layer\n", v26);
            v34.m_Storage.m_nActualLength = 0;
            if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
          }
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&qValues);
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&qTimes);
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vValues);
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vTimes);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
        {
          v8 = ComputeDmElementIdStr(&result, pDmElement: v5);
          v27 = CUtlString::Get(this: v8);
          v9 = ComputeDmElementIdStr(result: &v34, pDmElement);
          v10 = CUtlString::Get(this: v9);
          _LoggingSystem_Log(
            a1: LOG_DME_AAC,
            a2: 3,
            a3: "%s: Couldn't Find Translate & Rotate channels for DmeDag %s\n",
            v10,
            v27);
          CUtlString::~CUtlString(this: &v34);
          CUtlString::~CUtlString(this: &result);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AC6C0
// Name: public: virtual bool CDmeBoneMaskCmd::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeBoneMaskCmd::Apply(CDmeBoneMaskCmd *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  const CDmElement *v3; // esi
  CUtlString *v4; // eax
  CUtlString *v5; // eax
  CUtlString *v7; // eax
  CUtlString *v8; // eax
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  CDmeDag **v11; // eax
  CDmeDag *v12; // ebx
  int v13; // eax
  char *v14; // [esp-8h] [ebp-48h]
  char *v15; // [esp-8h] [ebp-48h]
  char *v16; // [esp-4h] [ebp-44h]
  char *v17; // [esp-4h] [ebp-44h]
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > depthFirstStack; // [esp+Ch] [ebp-34h] BYREF
  CUtlString v19; // [esp+20h] [ebp-20h] BYREF
  CDmeBoneMask *pDmeBoneMask; // [esp+30h] [ebp-10h]
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+34h] [ebp-Ch] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+38h] [ebp-8h] BYREF
  CDmElement *pDmElementa; // [esp+3Ch] [ebp-4h]
  int i; // [esp+48h] [ebp+8h]
  int ia; // [esp+48h] [ebp+8h]
  bool i_3; // [esp+4Bh] [ebp+Bh]

  pDmElementa = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v19, pDmElement: this);
  i_3 = ConvertToDmeSequenceAndDmeChannelsClip(
          pDmElement,
          sDmElementId: v2,
          pDmeSequence: &pDmeSequenceDst,
          pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v19.m_Storage.m_nActualLength = 0;
  if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
  if ( i_3 )
    return 0;
  v3 = pDmeSequenceDst;
  i = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
        a1: g_pDataModel.u,
        a2: pDmeSequenceDst->m_eSkeleton.m_Storage.m_Handle);
  if ( i == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v4 = ComputeDmElementIdStr(result: (CUtlString *)&depthFirstStack.m_Memory.m_nAllocationCount, pDmElement: v3);
      v16 = CUtlString::Get(this: v4);
      v5 = ComputeDmElementIdStr(result: &v19, pDmElement: pDmElementa);
      v14 = CUtlString::Get(this: v5);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No Skeleton\n", v14, v16);
LABEL_8:
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v19.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
          v19.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v19.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      depthFirstStack.m_pElements = nullptr;
      if ( depthFirstStack.m_Size >= 0 && depthFirstStack.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)depthFirstStack.m_Memory.m_nAllocationCount);
      return 0;
    }
    return 0;
  }
  pDmeBoneMask = (CDmeBoneMask *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: v3[6].m_pAttributes);
  if ( pDmeBoneMask == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v7 = ComputeDmElementIdStr(result: (CUtlString *)&depthFirstStack.m_Memory.m_nAllocationCount, pDmElement: v3);
      v17 = CUtlString::Get(this: v7);
      v8 = ComputeDmElementIdStr(result: &v19, pDmElement: pDmElementa);
      v15 = CUtlString::Get(this: v8);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No Bone Mask\n", v15, v17);
      goto LABEL_8;
    }
    return 0;
  }
  memset(&depthFirstStack, 0, sizeof(depthFirstStack));
  CUtlMemory<IDmFormatUpdater *,int>::Grow(
    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
    num: 1);
  m_pMemory = depthFirstStack.m_Memory.m_pMemory;
  m_Size = depthFirstStack.m_Size + 1;
  v11 = &depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size++];
  depthFirstStack.m_pElements = depthFirstStack.m_Memory.m_pMemory;
  if ( v11 != nullptr )
    *v11 = (CDmeDag *)i;
  while ( m_Size != 0 )
  {
    v12 = m_pMemory[--m_Size];
    depthFirstStack.m_Size = m_Size;
    if ( v12 != nullptr )
    {
      v13 = CDmElementFramework::GetPhase(this: v12) - 1;
      ia = v13;
      if ( v13 >= 0 )
      {
        while ( 1 )
        {
          pDmeSequenceDst = (CDmeSequence *)CDmeDag::GetChild(this: v12, i: v13);
          if ( m_Size >= depthFirstStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
              num: 1);
            m_Size = depthFirstStack.m_Size;
            m_pMemory = depthFirstStack.m_Memory.m_pMemory;
          }
          depthFirstStack.m_Size = ++m_Size;
          depthFirstStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = (CDmeDag *)pDmeSequenceDst;
          if ( --ia < 0 )
            break;
          v13 = ia;
        }
      }
      CDmeBoneMaskCmd::SubApply(
        this: (CDmeBoneMaskCmd *)pDmElementa,
        pDmeChannelsClip: (CDmeTypedLog<Vector> *)pDmeChannelsClipDst,
        pDmeDag: (CDmeTypedLog<Quaternion> *)v12,
        pDmeBoneMask: *(float *)&pDmeBoneMask);
    }
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&depthFirstStack);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACA00
// Name: public: virtual bool CDmeAnimationAssemblyCommand::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationAssemblyCommand::IsA(CDmeAnimationAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACA30
// Name: public: virtual int CDmeAnimationAssemblyCommand::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationAssemblyCommand::GetInheritanceDepth(
        CDmeAnimationAssemblyCommand *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACB10
// Name: public: virtual bool CDmeFixupLoop::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFixupLoop::IsA(CDmeFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFixupLoop::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACB50
// Name: public: virtual int CDmeFixupLoop::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFixupLoop::GetInheritanceDepth(CDmeFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFixupLoop::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACC10
// Name: protected: virtual void CDmeFixupLoop::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::PerformConstruction(CDmeFixupLoop *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_nStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "startFrame",
                                       type: AT_INT,
                                       pMemory: &this->m_nStartFrame);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004ACCE0
// Name: public: virtual bool CDmeSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSubtract::IsA(CDmeSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACD20
// Name: public: virtual int CDmeSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSubtract::GetInheritanceDepth(CDmeSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACDF0
// Name: protected: virtual void CDmeSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::PerformConstruction(CDmeSubtract *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_eSequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequence",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eSequence);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eSequence.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eSequence.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004ACEE0
// Name: public: virtual bool CDmePreSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePreSubtract::IsA(CDmePreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePreSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACF20
// Name: public: virtual int CDmePreSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePreSubtract::GetInheritanceDepth(CDmePreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePreSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD000
// Name: protected: virtual void CDmePreSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmePreSubtract::PerformConstruction(CDmePreSubtract *this)
{
  CDmeSubtract::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004AD0A0
// Name: public: virtual bool CDmeRotateTo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRotateTo::IsA(CDmeRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRotateTo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD0E0
// Name: public: virtual int CDmeRotateTo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRotateTo::GetInheritanceDepth(CDmeRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRotateTo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD280
// Name: public: virtual bool CDmeBoneMaskCmd::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMaskCmd::IsA(CDmeBoneMaskCmd *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMaskCmd::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD2C0
// Name: public: virtual int CDmeBoneMaskCmd::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMaskCmd::GetInheritanceDepth(CDmeBoneMaskCmd *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMaskCmd::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD470
// Name: ComputeMergedKeyTimes
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeMergedKeyTimes(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *mergedTimes@<esi>,
        CDmeLog *pDmeLogA,
        CDmeLog *pDmeLogB)
{
  int v3; // ebx
  int v4; // eax
  CDmeLog *v5; // edi
  const DmeTime_t *v6; // eax
  unsigned __int16 v7; // dx
  int *v8; // ecx
  int m_pMemory; // edi
  DmeTime_t *p_m_Data; // ebx
  int m_nAllocationCount; // eax
  DmeTime_t *v12; // ecx
  int v13; // eax
  DmeTime_t *v14; // edi
  unsigned __int16 v15; // ax
  CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl*)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short> > timesTree; // [esp+8h] [ebp-24h] BYREF
  DmeTime_t v17; // [esp+24h] [ebp-8h] BYREF
  int i; // [esp+28h] [ebp-4h]

  v3 = 0;
  v4 = 0;
  mergedTimes[1].m_pMemory = nullptr;
  timesTree.m_LessFunc = (bool (__cdecl *)(const DmeTime_t *, const DmeTime_t *))CDefOps<DmeTime_t>::LessFunc;
  memset(&timesTree.m_Elements, 0, sizeof(timesTree.m_Elements));
  *(_DWORD *)&timesTree.m_Root = 0xFFFF;
  *(_DWORD *)&timesTree.m_FirstFree = -1;
  timesTree.m_pElements = nullptr;
  i = 0;
  while ( 1 )
  {
    v5 = pDmeLogA;
    if ( v4 != 0 )
      v5 = pDmeLogB;
    if ( v5 != nullptr && CDmeLog::GetKeyCount(this: v5) > 0 )
    {
      do
      {
        v6 = v5->GetKeyTime(this: v5, result: &v17, a3: v3);
        CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::InsertIfNotFound(
          this: &timesTree,
          insert: v6);
        ++v3;
      }
      while ( v3 < CDmeLog::GetKeyCount(this: v5) );
    }
    v4 = i + 1;
    i = v4;
    if ( v4 >= 2 )
      break;
    v3 = 0;
  }
  v7 = CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::FirstInorder(this: &timesTree);
  i = v7;
  while ( v7 < timesTree.m_Elements.m_nAllocationCount && v7 <= timesTree.m_LastAlloc.index )
  {
    if ( (`CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_7EA64C = 0x1FFFF;
    }
    v8 = v7 == 0xFFFF
       ? &`CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&timesTree.m_Elements.m_pMemory[v7];
    if ( *(_WORD *)v8 == v7 )
      break;
    m_pMemory = (int)mergedTimes[1].m_pMemory;
    p_m_Data = &timesTree.m_Elements.m_pMemory[v7].m_Data;
    m_nAllocationCount = mergedTimes->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: mergedTimes, num: m_pMemory - m_nAllocationCount + 1);
      v7 = i;
    }
    ++mergedTimes[1].m_pMemory;
    v12 = (DmeTime_t *)mergedTimes->m_pMemory;
    v13 = (int)mergedTimes[1].m_pMemory - m_pMemory - 1;
    mergedTimes[1].m_nAllocationCount = (int)mergedTimes->m_pMemory;
    if ( v13 > 0 )
    {
      _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 4 * v13);
      v7 = i;
    }
    v14 = (DmeTime_t *)&mergedTimes->m_pMemory[m_pMemory];
    if ( v14 != nullptr )
      v14->m_tms = p_m_Data->m_tms;
    v15 = CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::NextInorder(
            this: &timesTree,
            i: v7);
    i = v15;
    v7 = v15;
  }
  CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::RemoveAll(this: &timesTree);
  if ( timesTree.m_Elements.m_nGrowSize >= 0 && timesTree.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: timesTree.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004AD630
// Name: protected: void CDmeRotateTo::SubApply(class CDmeDag __near *,class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeRotateTo::SubApply(
        CDmeRotateTo *this,
        CDmeTypedLog<Quaternion> *pDmeDag,
        CDmeLog *pDmeChannelsClip,
        bool bZUp)
{
  CDmeDag *v4; // esi
  CDmeChannelsClip *v5; // edi
  CUtlString *v6; // eax
  CUtlString *v7; // eax
  const char *v8; // eax
  CDmeTypedLog<Vector> *v9; // edi
  const Vector *Value; // esi
  const Vector *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // xmm0_4
  float v16; // xmm1_4
  int v17; // xmm0_4
  int v18; // esi
  DmeTime_t *v19; // ebx
  const Quaternion *v20; // eax
  const Vector *v21; // eax
  int v22; // eax
  CDmeTypedLogLayer<Vector> *v23; // esi
  CUtlString *v24; // eax
  const char *v25; // eax
  int v26; // eax
  CDmeTypedLogLayer<Quaternion> *v27; // esi
  CUtlString *v28; // eax
  const char *v29; // eax
  const char *v30; // [esp-4h] [ebp-124h]
  long double v31; // [esp+0h] [ebp-120h]
  long double v32; // [esp+8h] [ebp-118h] OVERLAPPED BYREF
  matrix3x4_t mSrc; // [esp+3Ch] [ebp-E4h] BYREF
  matrix3x4_t mRoot; // [esp+6Ch] [ebp-B4h] BYREF
  Quaternion qTmp; // [esp+9Ch] [ebp-84h] BYREF
  Vector vTmp; // [esp+ACh] [ebp-74h] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > qValues; // [esp+B8h] [ebp-68h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > vValues; // [esp+CCh] [ebp-54h] BYREF
  DmeTime_t dmeTimeEnd; // [esp+E0h] [ebp-40h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > mergedKeyTimes; // [esp+E4h] [ebp-3Ch] BYREF
  int flDeltaAngle; // [esp+F8h] [ebp-28h]
  CUtlString result; // [esp+FCh] [ebp-24h] BYREF
  CUtlString v43; // [esp+10Ch] [ebp-14h] BYREF
  CDmElement *pDmElement; // [esp+11Ch] [ebp-4h]

  v4 = (CDmeDag *)pDmeDag;
  pDmElement = this;
  if ( pDmeDag != nullptr )
  {
    v5 = (CDmeChannelsClip *)pDmeChannelsClip;
    if ( pDmeChannelsClip != nullptr && CDmeDag::GetTransform(this: (CDmeDag *)pDmeDag) != nullptr )
    {
      pDmeChannelsClip = nullptr;
      pDmeDag = nullptr;
      if ( GetDmeChannelsForDag(
             pDmeTranslateLog: (CDmeTypedLog<Vector> **)&pDmeChannelsClip,
             pDmeRotateLog: &pDmeDag,
             pDmeDag: v4,
             pDmeChannelsClip: v5) != 0 )
      {
        v9 = (CDmeTypedLog<Vector> *)pDmeChannelsClip;
        *(float *)&flDeltaAngle = 0.0;
        CDmeLog::GetBeginTime(this: pDmeChannelsClip, result: (DmeTime_t *)&pDmeChannelsClip);
        CDmeLog::GetEndTime(this: v9, result: &dmeTimeEnd);
        Value = CDmeTypedLog<Vector>::GetValue(this: v9, time: (DmeTime_t)pDmeChannelsClip);
        v11 = CDmeTypedLog<Vector>::GetValue(this: v9, time: dmeTimeEnd);
        v12 = v11->x - Value->x;
        v13 = v11->y - Value->y;
        if ( bZUp )
        {
          if ( v12 == 0.0 && v13 == 0.0 )
          {
            v43.m_Storage.m_Memory.m_nAllocationCount = 0;
            v43.m_Storage.m_Memory.m_nGrowSize = flDeltaAngle;
            v43.m_Storage.m_nActualLength = 0;
          }
          else
          {
            __libm_sse2_atan2(y: v31, x: v32);
            v14 = v13 * 57.29577951308232;
            *(float *)&v15 = *(float *)&pDmElement[1].__vftable - v14;
            v43.m_Storage.m_Memory.m_nAllocationCount = 0;
            v43.m_Storage.m_Memory.m_nGrowSize = v15;
            v43.m_Storage.m_nActualLength = 0;
          }
        }
        else
        {
          if ( v12 == 0.0 && (float)(v11->z - Value->z) == 0.0 )
          {
            v17 = flDeltaAngle;
          }
          else
          {
            __libm_sse2_atan2(y: v31, x: v32);
            v16 = v12 * 57.29577951308232;
            *(float *)&v17 = *(float *)&pDmElement[1].__vftable - v16;
          }
          v43.m_Storage.m_Memory.m_nAllocationCount = v17;
          v43.m_Storage.m_Memory.m_nGrowSize = 0;
          v43.m_Storage.m_nActualLength = 0;
        }
        AngleMatrix(angles: (const QAngle *)&v43.m_Storage.m_Memory.m_nAllocationCount, matrix: &mRoot);
        memset(&mergedKeyTimes, 0, sizeof(mergedKeyTimes));
        ComputeMergedKeyTimes(
          mergedTimes: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&mergedKeyTimes,
          pDmeLogA: v9,
          pDmeLogB: pDmeDag);
        v18 = 0;
        memset(&vValues, 0, sizeof(vValues));
        memset(&qValues, 0, sizeof(qValues));
        if ( mergedKeyTimes.m_Size > 0 )
        {
          do
          {
            v19 = &mergedKeyTimes.m_Memory.m_pMemory[v18];
            v20 = CDmeTypedLog<Quaternion>::GetValue(this: pDmeDag, time: (DmeTime_t)v19->m_tms);
            QuaternionAngles(q: v20, angles: (RadianEuler *)&v43.m_Storage.m_Memory.m_nAllocationCount);
            v21 = CDmeTypedLog<Vector>::GetValue(this: v9, time: (DmeTime_t)v19->m_tms);
            AngleMatrix(
              angles: (const RadianEuler *)&v43.m_Storage.m_Memory.m_nAllocationCount,
              position: v21,
              matrix: &mSrc);
            ConcatTransforms(in1: &mRoot, in2: &mSrc, out: (matrix3x4_t *)((char *)&v32 + 4));
            MatrixAngles(matrix: (const matrix3x4_t *)((char *)&v32 + 4), q: &qTmp, pos: &vTmp);
            CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
              this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&vValues,
              elem: vValues.m_Size,
              src: (const QAngle *)&vTmp);
            CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
              this: &qValues,
              elem: qValues.m_Size,
              src: &qTmp);
            ++v18;
          }
          while ( v18 < mergedKeyTimes.m_Size );
        }
        v22 = (int)v9->AddNewLayer(this: v9);
        v23 = (CDmeTypedLogLayer<Vector> *)v22;
        if ( v22 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
               a1: v22,
               a2: CDmeTypedLogLayer<Vector>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Vector>::SetAllKeys(this: v23, times: &mergedKeyTimes, values: &vValues);
          v23->RemoveRedundantKeys_2(this: v23, a2: true);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
        {
          v24 = ComputeDmElementIdStr(&result, pDmElement);
          v25 = CUtlString::Get(this: v24);
          _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Translate Layer\n", v25);
          result.m_Storage.m_nActualLength = 0;
          if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
        }
        v26 = (int)pDmeDag->AddNewLayer(this: pDmeDag);
        v27 = (CDmeTypedLogLayer<Quaternion> *)v26;
        if ( v26 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v26 + 16))(
               a1: v26,
               a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v27, times: &mergedKeyTimes, values: &qValues);
          v27->RemoveRedundantKeys_2(this: v27, a2: true);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
        {
          v28 = ComputeDmElementIdStr(&result, pDmElement);
          v29 = CUtlString::Get(this: v28);
          _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Rotate Layer\n", v29);
          result.m_Storage.m_nActualLength = 0;
          if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
        }
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&qValues);
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vValues);
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&mergedKeyTimes);
      }
      else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
      {
        v6 = ComputeDmElementIdStr(&result, pDmElement: v4);
        v30 = CUtlString::Get(this: v6);
        v7 = ComputeDmElementIdStr(result: &v43, pDmElement);
        v8 = CUtlString::Get(this: v7);
        _LoggingSystem_Log(
          a1: LOG_DME_AAC,
          a2: 3,
          a3: "%s: Couldn't Find Translate & Rotate channels for DmeDag %s\n",
          v8,
          v30);
        v43.m_Storage.m_nActualLength = 0;
        if ( v43.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v43.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v43.m_Storage.m_Memory.m_pMemory);
            v43.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v43.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        result.m_Storage.m_nActualLength = 0;
        if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ADAD0
// Name: public: virtual bool CDmeRotateTo::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeRotateTo::Apply(CDmeRotateTo *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  CDmeSequence *v3; // edi
  int v4; // eax
  CDmeTypedLog<Quaternion> *v5; // esi
  CUtlString *v6; // eax
  CUtlString *v7; // eax
  const char *v8; // eax
  int v10; // edi
  CDmeChannelsClip *v11; // ebx
  CDmeTypedLog<Quaternion> *Child; // eax
  CUtlString *v13; // eax
  CUtlString *v14; // eax
  const char *v15; // eax
  const char *v16; // [esp-4h] [ebp-3Ch]
  bool IsZUp; // [esp-4h] [ebp-3Ch]
  const char *v18; // [esp-4h] [ebp-3Ch]
  CUtlString v19; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlString v20; // [esp+1Ch] [ebp-1Ch] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+2Ch] [ebp-Ch] BYREF
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+30h] [ebp-8h] BYREF
  CDmElement *v23; // [esp+34h] [ebp-4h]
  bool pDmElement_3; // [esp+43h] [ebp+Bh]

  v23 = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v20, pDmElement: this);
  pDmElement_3 = ConvertToDmeSequenceAndDmeChannelsClip(
                   pDmElement,
                   sDmElementId: v2,
                   pDmeSequence: &pDmeSequenceDst,
                   pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v20.m_Storage.m_nActualLength = 0;
  if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 && v20.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
  if ( pDmElement_3 )
    return 0;
  v3 = pDmeSequenceDst;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: pDmeSequenceDst->m_eSkeleton.m_Storage.m_Handle);
  v5 = (CDmeTypedLog<Quaternion> *)v4;
  if ( v4 == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v6 = ComputeDmElementIdStr(result: &v19, pDmElement: v3);
      v16 = CUtlString::Get(this: v6);
      v7 = ComputeDmElementIdStr(result: &v20, pDmElement: v23);
      v8 = CUtlString::Get(this: v7);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No Skeleton\n", v8, v16);
      v20.m_Storage.m_nActualLength = 0;
      if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
          v20.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v20.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
    }
    return 0;
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeModel::m_classType.u) == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
    {
      v13 = ComputeDmElementIdStr(result: &v19, pDmElement: v3);
      v18 = CUtlString::Get(this: v13);
      v14 = ComputeDmElementIdStr(result: &v20, pDmElement: v23);
      v15 = CUtlString::Get(this: v14);
      _LoggingSystem_Log(
        a1: LOG_DME_AAC,
        a2: 1,
        a3: "%s: Cannot Determine If Sequence %s Is Y Or Z Up, Assuming Z Up\n",
        v15,
        v18);
      v20.m_Storage.m_nActualLength = 0;
      if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
          v20.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v20.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
    }
    CDmeRotateTo::SubApply(
      this: (CDmeRotateTo *)v23,
      pDmeDag: v5,
      pDmeChannelsClip: (CDmeLog *)pDmeChannelsClipDst,
      bZUp: true);
    return 1;
  }
  v10 = 0;
  if ( CDmElementFramework::GetPhase(this: (CDmeDag *)v5) <= 0 )
    return 1;
  v11 = pDmeChannelsClipDst;
  do
  {
    IsZUp = CDmeModel::IsZUp(this: (CDmeModel *)v5);
    Child = (CDmeTypedLog<Quaternion> *)CDmeDag::GetChild(this: (CDmeDag *)v5, i: v10);
    CDmeRotateTo::SubApply(this: (CDmeRotateTo *)v23, pDmeDag: Child, pDmeChannelsClip: (CDmeLog *)v11, bZUp: IsZUp);
    ++v10;
  }
  while ( v10 < CDmElementFramework::GetPhase(this: (CDmeDag *)v5) );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0059A4C0
// Name: _dynamic_initializer_for__CDmeAnimationAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationAssemblyCommand::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationAssemblyCommand pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A520
// Name: _dynamic_initializer_for__CDmeFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFixupLoop::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFixupLoop pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A580
// Name: _dynamic_initializer_for__CDmeSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A5E0
// Name: _dynamic_initializer_for__CDmePreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePreSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePreSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePreSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A640
// Name: _dynamic_initializer_for__CDmeRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRotateTo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRotateTo::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRotateTo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A6A0
// Name: _dynamic_initializer_for__CDmeBoneMaskCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMaskCmd::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMaskCmd::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMaskCmd pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E940
// Name: _dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationAssemblyCommand::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E950
// Name: _dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFixupLoop::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E960
// Name: _dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E970
// Name: _dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePreSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E980
// Name: _dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRotateTo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E990
// Name: _dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMaskCmd::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A4F0
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A500
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationAssemblyCommand_Helper,
           classname: "DmeAnimationAssemblyCommand",
           pFactory: &g_CDmeAnimationAssemblyCommand_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A550
// Name: _dynamic_initializer_for__g_CDmeFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFixupLoop_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A560
// Name: _dynamic_initializer_for__g_CDmeFixupLoop_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFixupLoop_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFixupLoop_Helper,
           classname: "DmeFixupLoop",
           pFactory: &g_CDmeFixupLoop_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A5B0
// Name: _dynamic_initializer_for__g_CDmeSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A5C0
// Name: _dynamic_initializer_for__g_CDmeSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSubtract_Helper,
           classname: "DmeSubtract",
           pFactory: &g_CDmeSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A610
// Name: _dynamic_initializer_for__g_CDmePreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePreSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A620
// Name: _dynamic_initializer_for__g_CDmePreSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePreSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePreSubtract_Helper,
           classname: "DmePreSubtract",
           pFactory: &g_CDmePreSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A670
// Name: _dynamic_initializer_for__g_CDmeRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRotateTo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A680
// Name: _dynamic_initializer_for__g_CDmeRotateTo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRotateTo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRotateTo_Helper,
           classname: "DmeRotateTo",
           pFactory: &g_CDmeRotateTo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A6D0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMaskCmd_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A6E0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmd_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMaskCmd_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMaskCmd_Helper,
           classname: "DmeBoneMaskCmd",
           pFactory: &g_CDmeBoneMaskCmd_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E9A0
// Name: _dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFixupLoop_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E9B0
// Name: _dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E9C0
// Name: _dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePreSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E9D0
// Name: _dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRotateTo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E9E0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneMaskCmd_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E9F0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationAssemblyCommand_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EEC30
// Name: protected: virtual void CDmeSubtract::Subtract(class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract(CDmeSubtract *this, Vector *vResult, const Vector *vDst, const Vector *vSrc)
{
  vResult->x = vDst->x - vSrc->x;
  vResult->y = vDst->y - vSrc->y;
  vResult->z = vDst->z - vSrc->z;
}

//------------------------------------------------------------------------------
// Address: 0x004EEC70
// Name: protected: virtual void CDmeSubtract::Subtract(class Quaternion __near &,class Quaternion const __near &,class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract(
        CDmeSubtract *this,
        Quaternion *qResult,
        const Quaternion *qDst,
        const Quaternion *qSrc)
{
  QuaternionSM(s: -1.0, p: qSrc, q: qDst, qt: qResult);
}

//------------------------------------------------------------------------------
// Address: 0x004EECA0
// Name: protected: virtual void CDmePreSubtract::Subtract(class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePreSubtract::Subtract(
        CDmePreSubtract *this,
        Vector *vResult,
        const Vector *vDst,
        const Vector *vSrc)
{
  vResult->x = vSrc->x - vDst->x;
  vResult->y = vSrc->y - vDst->y;
  vResult->z = vSrc->z - vDst->z;
}

//------------------------------------------------------------------------------
// Address: 0x004EECE0
// Name: protected: virtual void CDmePreSubtract::Subtract(class Quaternion __near &,class Quaternion const __near &,class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePreSubtract::Subtract(
        CDmePreSubtract *this,
        Quaternion *qResult,
        const Quaternion *qDst,
        const Quaternion *qSrc)
{
  QuaternionMA(p: qDst, s: -1.0, q: qSrc, qt: qResult);
}

//------------------------------------------------------------------------------
// Address: 0x004EF1F0
// Name: GetDmeChannelsForDag
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetDmeChannelsForDag(
        CDmeTypedLog<Vector> **pDmeTranslateLog,
        CDmeTypedLog<Quaternion> **pDmeRotateLog,
        CDmeDag *pDmeDag,
        CDmeChannelsClip *pDmeChannelsClip)
{
  CDmeChannelsClip *v5; // esi
  CDmeTransform *Transform; // edi
  int v7; // eax
  int v8; // esi
  CDmeChannel *v9; // esi
  CDmeLog *Log; // eax
  CDmElement *v11; // edi
  CDmeTypedLog<Vector> *v12; // eax
  CUtlString *v13; // eax
  CUtlString *v14; // eax
  CUtlString *v15; // eax
  const char *v16; // eax
  CUtlString *v17; // ecx
  CDmeTypedLog<Quaternion> *v18; // eax
  CUtlString *v19; // eax
  CUtlString *v20; // eax
  CUtlString *v21; // eax
  const char *v22; // eax
  const char *v24; // [esp-8h] [ebp-78h]
  const char *v25; // [esp-8h] [ebp-78h]
  const char *v26; // [esp-4h] [ebp-74h]
  const char *v27; // [esp-4h] [ebp-74h]
  CUtlString v28; // [esp+Ch] [ebp-64h] BYREF
  CUtlString v29; // [esp+1Ch] [ebp-54h] BYREF
  CUtlString v30; // [esp+2Ch] [ebp-44h] BYREF
  CUtlString v31; // [esp+3Ch] [ebp-34h] BYREF
  CUtlString v32; // [esp+4Ch] [ebp-24h] BYREF
  CUtlString v33; // [esp+5Ch] [ebp-14h] BYREF
  CDmeTransform *pDmeTransform; // [esp+6Ch] [ebp-4h]
  CDmeTypedLog<Vector> **pDmeTranslateLoga; // [esp+78h] [ebp+8h]

  *pDmeTranslateLog = nullptr;
  *pDmeRotateLog = nullptr;
  if ( pDmeDag == nullptr )
    return 0;
  v5 = pDmeChannelsClip;
  if ( pDmeChannelsClip == nullptr )
    return 0;
  Transform = CDmeDag::GetTransform(this: pDmeDag);
  pDmeTransform = Transform;
  if ( Transform == nullptr )
    return 0;
  if ( pDmeChannelsClip->m_Channels.m_Storage.m_Size != 0 )
  {
    pDmeTranslateLoga = nullptr;
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(CDmeTypedLog<Vector> **)((char *)pDmeTranslateLoga
                                      + (unsigned int)v5->m_Channels.m_Storage.m_Memory.m_pMemory));
      v8 = v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v9 = (CDmeChannel *)(v8 - 4);
        if ( v9 != nullptr && CDmeChannel::GetToElement(this: v9) == Transform )
        {
          Log = CDmeChannel::GetLog(this: v9);
          v11 = Log;
          if ( Log != nullptr )
          {
            v12 = CastElement<CDmeTypedLog<Vector>>(pElement: Log);
            if ( v12 != nullptr )
            {
              if ( *pDmeTranslateLog != nullptr )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) == 0 )
                  goto LABEL_25;
                v13 = ComputeDmElementIdStr(result: &v31, pDmElement: &v9->CDmElement);
                v26 = CUtlString::Get(this: v13);
                v14 = ComputeDmElementIdStr(result: &v32, pDmElement: *pDmeTranslateLog);
                v24 = CUtlString::Get(this: v14);
                v15 = ComputeDmElementIdStr(result: &v33, pDmElement: pDmeDag);
                v16 = CUtlString::Get(this: v15);
                _LoggingSystem_Log(
                  a1: LOG_DME_AAC,
                  a2: 1,
                  a3: "%s: Multiple Translate Channels Found For Dag, Using %s, Ignoring %s\n",
                  v16,
                  v24,
                  v26);
                CUtlString::~CUtlString(this: &v33);
                CUtlString::~CUtlString(this: &v32);
                v17 = &v31;
LABEL_24:
                CUtlString::~CUtlString(this: v17);
                goto LABEL_25;
              }
              *pDmeTranslateLog = v12;
              if ( *pDmeRotateLog != nullptr )
                break;
            }
            else
            {
              v18 = CastElement<CDmeTypedLog<Quaternion>>(pElement: v11);
              if ( v18 == nullptr )
                goto LABEL_25;
              if ( *pDmeRotateLog != nullptr )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) == 0 )
                  goto LABEL_25;
                v19 = ComputeDmElementIdStr(result: &v28, pDmElement: &v9->CDmElement);
                v27 = CUtlString::Get(this: v19);
                v20 = ComputeDmElementIdStr(result: &v29, pDmElement: *pDmeRotateLog);
                v25 = CUtlString::Get(this: v20);
                v21 = ComputeDmElementIdStr(result: &v30, pDmElement: pDmeDag);
                v22 = CUtlString::Get(this: v21);
                _LoggingSystem_Log(
                  a1: LOG_DME_AAC,
                  a2: 1,
                  a3: "%s: Multiple Rotate Channels Found For Dag, Using %s, Ignoring %s\n",
                  v22,
                  v25,
                  v27);
                CUtlString::~CUtlString(this: &v30);
                CUtlString::~CUtlString(this: &v29);
                v17 = &v28;
                goto LABEL_24;
              }
              *pDmeRotateLog = v18;
              if ( *pDmeTranslateLog != nullptr )
                goto LABEL_27;
            }
          }
        }
      }
LABEL_25:
      v5 = pDmeChannelsClip;
      ++pDmeTranslateLoga;
      if ( pDmeChannelsClip->m_Channels.m_Storage.m_Size == 0 )
        break;
      Transform = pDmeTransform;
    }
  }
  if ( *pDmeTranslateLog != nullptr )
  {
LABEL_27:
    if ( *pDmeRotateLog != nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004EFDB0
// Name: ConvertToDmeSequenceAndDmeChannelsClip
// Source: json
//------------------------------------------------------------------------------
char __usercall ConvertToDmeSequenceAndDmeChannelsClip@<al>(
        CDmeSequence *pDmElement@<esi>,
        CUtlString *sDmElementId@<edi>,
        CDmeSequence **pDmeSequence,
        CDmeChannelsClip **pDmeChannelsClip)
{
  const char *v4; // eax
  const char *v6; // eax
  CDmeChannelsClip *DmeChannelsClip; // eax
  CUtlString *v8; // eax
  const char *v9; // eax
  const char *v10; // [esp-4h] [ebp-14h]
  CUtlString v11; // [esp+0h] [ebp-10h] BYREF

  if ( pDmElement == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v4 = CUtlString::operator char const *(this: sDmElementId);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: No DmElement Specified specified\n", v4);
    }
    return 0;
  }
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
         a1: pDmElement,
         a2: (CUtlSymbolLarge)CDmeSequence::m_classType.u.m_Id) )
  {
    DmeChannelsClip = CDmeSequence::GetDmeChannelsClip(this: pDmElement);
    if ( DmeChannelsClip != nullptr )
    {
      *pDmeSequence = pDmElement;
      *pDmeChannelsClip = DmeChannelsClip;
      return 1;
    }
    else
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
      {
        v8 = ComputeDmElementIdStr(result: &v11, pDmElement);
        v10 = CUtlString::Get(this: v8);
        v9 = CUtlString::operator char const *(this: sDmElementId);
        _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No DmeChannelsClip\n", v9, v10);
        v11.m_Storage.m_nActualLength = 0;
        if ( v11.m_Storage.m_Memory.m_nGrowSize >= 0 && v11.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11.m_Storage.m_Memory.m_pMemory);
      }
      return 0;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) == 0 )
      return 0;
    v6 = CUtlString::operator char const *(this: sDmElementId);
    _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: No DmeSequence Specified specified\n", v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EFEE0
// Name: protected: void CDmeFixupLoop::Apply<class Vector>(class CDmeTypedLog<class Vector> __near *,class DmeTime_t const __near &,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::Apply<Vector>(
        CDmeFixupLoop *this,
        CDmeTypedLog<Vector> *pDmeTypedLogDst,
        const DmeTime_t *dmeTimeStart,
        const DmeTime_t *dmeTimeEnd)
{
  int v4; // esi
  int v5; // eax
  int m_Size; // eax
  int v7; // edi
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  DmeTime_t *v10; // edi
  const QAngle *KeyValue; // eax
  Vector *v12; // edi
  DmeTime_t *v13; // ebx
  int v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  int v18; // eax
  int v19; // esi
  int v20; // edx
  int m_tms; // ecx
  float v22; // xmm0_4
  float *p_x; // ecx
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  int v27; // ecx
  float v28; // xmm0_4
  float *v29; // ecx
  float v30; // xmm6_4
  float v31; // xmm7_4
  float v32; // xmm0_4
  int v33; // ecx
  float v34; // xmm0_4
  float *v35; // ecx
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  int v39; // ecx
  float v40; // xmm0_4
  float *v41; // ecx
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm0_4
  int v45; // edx
  int v46; // ecx
  float v47; // xmm0_4
  float *v48; // ecx
  float v49; // xmm6_4
  float v50; // xmm7_4
  float v51; // xmm0_4
  int v52; // esi
  int v53; // ecx
  int v54; // edx
  int v55; // ebx
  float v56; // xmm0_4
  float v57; // xmm0_4
  float *v58; // eax
  float v59; // xmm7_4
  int v60; // edi
  float v61; // xmm0_4
  float v62; // xmm0_4
  Vector *v63; // eax
  float v64; // xmm7_4
  int v65; // edi
  float v66; // xmm0_4
  float v67; // xmm0_4
  Vector *v68; // eax
  float v69; // xmm7_4
  int v70; // edi
  float v71; // xmm0_4
  float v72; // xmm0_4
  Vector *v73; // eax
  float v74; // xmm7_4
  int v75; // ebx
  int v76; // edx
  float v77; // xmm0_4
  float v78; // xmm0_4
  float *v79; // eax
  float v80; // xmm7_4
  CDmeLogLayer *v81; // eax
  CDmeTypedLogLayer<Vector> *v82; // esi
  Vector *v83; // eax
  DmeTime_t *v84; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > values; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+20h] [ebp-30h] BYREF
  Vector newValue; // [esp+34h] [ebp-1Ch]
  float v88; // [esp+40h] [ebp-10h] BYREF
  int nKeyIndex; // [esp+44h] [ebp-Ch]
  float flTimeRange; // [esp+48h] [ebp-8h]
  int nKeyCount; // [esp+4Ch] [ebp-4h]
  float flScale; // [esp+5Ch] [ebp+Ch]

  v4 = 0;
  if ( pDmeTypedLogDst != nullptr )
  {
    v5 = dmeTimeEnd->m_tms - dmeTimeStart->m_tms;
    if ( (float)((float)v5 * 0.000099999997) > 0.0 && (float)((float)dmeTimeStart->m_tms * 0.000099999997) <= 0.0 )
    {
      flTimeRange = (float)v5 * 0.000099999997;
      nKeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLogDst);
      if ( nKeyCount > 0 )
      {
        memset(&times, 0, sizeof(times));
        memset(&values, 0, sizeof(values));
        do
        {
          nKeyIndex = (int)pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &v88, a3: v4);
          m_Size = times.m_Size;
          v7 = times.m_Size;
          if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
              num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
            m_Size = times.m_Size;
          }
          m_pMemory = times.m_Memory.m_pMemory;
          times.m_Size = m_Size + 1;
          v9 = m_Size - v7;
          times.m_pElements = times.m_Memory.m_pMemory;
          if ( v9 > 0 )
          {
            _V_memmove(dest: &times.m_Memory.m_pMemory[v7 + 1], src: &times.m_Memory.m_pMemory[v7], count: 4 * v9);
            m_pMemory = times.m_Memory.m_pMemory;
          }
          v10 = &m_pMemory[v7];
          if ( v10 != nullptr )
            v10->m_tms = *(int *)nKeyIndex;
          KeyValue = (const QAngle *)CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&values,
            elem: values.m_Size,
            src: KeyValue);
          ++v4;
        }
        while ( v4 < nKeyCount );
        v12 = values.m_Memory.m_pMemory;
        v13 = times.m_Memory.m_pMemory;
        v14 = nKeyCount;
        v15 = values.m_Memory.m_pMemory[nKeyCount - 1].x - values.m_Memory.m_pMemory->x;
        v16 = values.m_Memory.m_pMemory[nKeyCount - 1].y - values.m_Memory.m_pMemory->y;
        v17 = values.m_Memory.m_pMemory[nKeyCount - 1].z - values.m_Memory.m_pMemory->z;
        if ( (float)((float)dmeTimeStart->m_tms * 0.000099999997) < 0.0 )
        {
          v18 = dmeTimeStart->m_tms + times.m_Memory.m_pMemory[nKeyCount - 1].m_tms;
          v19 = 0;
          if ( nKeyCount >= 4 )
          {
            LODWORD(v88) = nKeyCount - 3;
            v20 = 0;
            do
            {
              m_tms = v13[v19].m_tms;
              if ( m_tms >= v18 )
              {
                LODWORD(v22) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(m_tms - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                p_x = &v12[v20].x;
                v24 = (float)(v22 * v15) + v12[v20].x;
                v25 = (float)(v22 * v16) + v12[v20].y;
                v26 = (float)(v22 * v17) + v12[v20].z;
                *p_x = v24;
                p_x[1] = v25;
                p_x[2] = v26;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v27 = v13[v19 + 1].m_tms;
              if ( v27 >= v18 )
              {
                LODWORD(v28) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v27 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v29 = &v12[v20 + 1].x;
                v30 = (float)(v28 * v15) + *v29;
                v31 = (float)(v28 * v16) + v12[v20 + 1].y;
                v32 = (float)(v28 * v17) + v12[v20 + 1].z;
                *v29 = v30;
                v29[1] = v31;
                v29[2] = v32;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v33 = v13[v19 + 2].m_tms;
              if ( v33 >= v18 )
              {
                LODWORD(v34) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v33 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v35 = &v12[v20 + 2].x;
                v36 = (float)(v34 * v15) + *v35;
                v37 = (float)(v34 * v16) + v12[v20 + 2].y;
                v38 = (float)(v34 * v17) + v12[v20 + 2].z;
                *v35 = v36;
                v35[1] = v37;
                v35[2] = v38;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v39 = v13[v19 + 3].m_tms;
              if ( v39 >= v18 )
              {
                LODWORD(v40) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v39 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v41 = &v12[v20 + 3].x;
                v42 = (float)(v40 * v15) + *v41;
                v43 = (float)(v40 * v16) + v12[v20 + 3].y;
                v44 = (float)(v40 * v17) + v12[v20 + 3].z;
                *v41 = v42;
                v41[1] = v43;
                v41[2] = v44;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v19 += 4;
              v20 += 4;
              nKeyIndex = v19;
            }
            while ( v19 < SLODWORD(v88) );
            v14 = nKeyCount;
          }
          if ( v19 < v14 )
          {
            v45 = v19;
            do
            {
              v46 = v13[v19].m_tms;
              if ( v46 >= v18 )
              {
                LODWORD(v47) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v46 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v48 = &v12[v45].x;
                v49 = (float)(v47 * v15) + v12[v45].x;
                v50 = (float)(v47 * v16) + v12[v45].y;
                v51 = (float)(v47 * v17) + v12[v45].z;
                *v48 = v49;
                v48[1] = v50;
                v48[2] = v51;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              ++v19;
              ++v45;
            }
            while ( v19 < nKeyCount );
          }
        }
        if ( (float)((float)dmeTimeEnd->m_tms * 0.000099999997) > 0.0 )
        {
          v52 = v13->m_tms;
          v53 = 0;
          if ( nKeyCount < 4 )
          {
LABEL_41:
            if ( v53 < nKeyCount )
            {
              v75 = v53;
              while ( 1 )
              {
                v76 = times.m_Memory.m_pMemory[v53].m_tms;
                if ( v76 > dmeTimeEnd->m_tms )
                  break;
                v77 = (float)((float)(v52 + dmeTimeEnd->m_tms - v76) * 0.000099999997) / flTimeRange;
                v78 = (float)((float)(v77 * 3.0) * v77) - (float)((float)((float)(v77 * 2.0) * v77) * v77);
                v79 = &v12[v75].x;
                newValue.x = (float)(v15 * v78) + v12[v75].x;
                newValue.y = (float)(v16 * v78) + v12[v75].y;
                v80 = (float)(v17 * v78) + v12[v75].z;
                ++v53;
                *v79 = newValue.x;
                ++v75;
                v79[1] = newValue.y;
                v79[2] = v80;
                if ( v53 >= nKeyCount )
                  break;
                v12 = values.m_Memory.m_pMemory;
              }
            }
          }
          else
          {
            v54 = 0;
            while ( 1 )
            {
              v55 = v13[v53].m_tms;
              if ( v55 > dmeTimeEnd->m_tms )
                break;
              flScale = 1.0 / flTimeRange;
              v56 = (float)((float)(v52 + dmeTimeEnd->m_tms - v55) * 0.000099999997) * (float)(1.0 / flTimeRange);
              v88 = (float)(v56 * 3.0) * v56;
              v57 = v88 - (float)((float)((float)(v56 * 2.0) * v56) * v56);
              v58 = &v12[v54].x;
              newValue.x = (float)(v15 * v57) + v12[v54].x;
              newValue.y = (float)(v16 * v57) + v12[v54].y;
              v59 = (float)(v17 * v57) + v12[v54].z;
              *v58 = newValue.x;
              v58[1] = newValue.y;
              v58[2] = v59;
              v60 = times.m_Memory.m_pMemory[v53 + 1].m_tms;
              if ( v60 > dmeTimeEnd->m_tms )
                break;
              v61 = (float)((float)(v52 + dmeTimeEnd->m_tms - v60) * 0.000099999997) * flScale;
              v88 = (float)(v61 * 3.0) * v61;
              v62 = v88 - (float)((float)((float)(v61 * 2.0) * v61) * v61);
              v63 = &values.m_Memory.m_pMemory[v54 + 1];
              newValue.x = (float)(v15 * v62) + v63->x;
              newValue.y = (float)(v16 * v62) + values.m_Memory.m_pMemory[v54 + 1].y;
              v64 = (float)(v17 * v62) + values.m_Memory.m_pMemory[v54 + 1].z;
              v63->x = newValue.x;
              v63->y = newValue.y;
              v63->z = v64;
              v65 = times.m_Memory.m_pMemory[v53 + 2].m_tms;
              if ( v65 > dmeTimeEnd->m_tms )
                break;
              v66 = (float)((float)(v52 + dmeTimeEnd->m_tms - v65) * 0.000099999997) * flScale;
              v88 = (float)(v66 * 3.0) * v66;
              v67 = v88 - (float)((float)((float)(v66 * 2.0) * v66) * v66);
              v68 = &values.m_Memory.m_pMemory[v54 + 2];
              newValue.x = (float)(v15 * v67) + v68->x;
              newValue.y = (float)(v16 * v67) + values.m_Memory.m_pMemory[v54 + 2].y;
              v69 = (float)(v17 * v67) + values.m_Memory.m_pMemory[v54 + 2].z;
              v68->x = newValue.x;
              v68->y = newValue.y;
              v68->z = v69;
              v70 = times.m_Memory.m_pMemory[v53 + 3].m_tms;
              if ( v70 > dmeTimeEnd->m_tms )
                break;
              v71 = (float)((float)(v52 + dmeTimeEnd->m_tms - v70) * 0.000099999997) * flScale;
              v88 = (float)(v71 * 3.0) * v71;
              v72 = v88 - (float)((float)((float)(v71 * 2.0) * v71) * v71);
              v73 = &values.m_Memory.m_pMemory[v54 + 3];
              newValue.x = (float)(v15 * v72) + v73->x;
              newValue.y = (float)(v16 * v72) + values.m_Memory.m_pMemory[v54 + 3].y;
              v74 = (float)(v17 * v72) + values.m_Memory.m_pMemory[v54 + 3].z;
              v73->x = newValue.x;
              v73->y = newValue.y;
              v73->z = v74;
              v12 = values.m_Memory.m_pMemory;
              v53 += 4;
              v54 += 4;
              if ( v53 >= nKeyCount - 3 )
                goto LABEL_41;
              v13 = times.m_Memory.m_pMemory;
            }
          }
        }
        v81 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
        v82 = (CDmeTypedLogLayer<Vector> *)v81;
        if ( v81 != nullptr && v81->IsA(this: v81, a2: CDmeTypedLogLayer<Vector>::m_classType) )
          CDmeTypedLogLayer<Vector>::SetAllKeys(this: v82, &times, &values);
        v83 = values.m_Memory.m_pMemory;
        values.m_Size = 0;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( values.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
            v83 = nullptr;
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        values.m_pElements = v83;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v83 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v83);
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        v84 = times.m_Memory.m_pMemory;
        times.m_Size = 0;
        if ( times.m_Memory.m_nGrowSize >= 0 )
        {
          if ( times.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
            v84 = nullptr;
            times.m_Memory.m_pMemory = nullptr;
          }
          times.m_Memory.m_nAllocationCount = 0;
        }
        times.m_pElements = v84;
        if ( times.m_Memory.m_nGrowSize >= 0 && v84 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v84);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F0790
// Name: protected: void CDmeFixupLoop::Apply<class Quaternion>(class CDmeTypedLog<class Quaternion> __near *,class DmeTime_t const __near &,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::Apply<Quaternion>(
        CDmeFixupLoop *this,
        CDmeTypedLog<Quaternion> *pDmeTypedLogDst,
        const DmeTime_t *dmeTimeStart,
        const DmeTime_t *dmeTimeEnd)
{
  CDmeTypedLog<Quaternion> *v4; // esi
  int v5; // edi
  int v6; // eax
  int KeyCount; // ebx
  int m_Size; // eax
  int v9; // esi
  DmeTime_t *m_pMemory; // ecx
  int v11; // eax
  DmeTime_t *v12; // esi
  const Quaternion *KeyValue; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // esi
  int m_tms; // eax
  float v18; // xmm0_4
  int v19; // esi
  int v20; // ecx
  float v21; // xmm0_4
  int v22; // eax
  CDmeTypedLogLayer<Quaternion> *v23; // esi
  Quaternion *v24; // eax
  DmeTime_t *v25; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > values; // [esp+24h] [ebp-54h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+38h] [ebp-40h] BYREF
  Quaternion delta; // [esp+4Ch] [ebp-2Ch] BYREF
  Quaternion newValue; // [esp+5Ch] [ebp-1Ch] BYREF
  DmeTime_t v30; // [esp+6Ch] [ebp-Ch] BYREF
  DmeTime_t *v31; // [esp+70h] [ebp-8h]
  float flTimeRange; // [esp+74h] [ebp-4h]
  DmeTime_t dmeTimeBegin; // [esp+84h] [ebp+Ch]
  int dmeTimeBegina; // [esp+84h] [ebp+Ch]

  v4 = pDmeTypedLogDst;
  v5 = 0;
  if ( pDmeTypedLogDst != nullptr )
  {
    v6 = dmeTimeEnd->m_tms - dmeTimeStart->m_tms;
    if ( (float)((float)v6 * 0.000099999997) > 0.0 && (float)((float)dmeTimeStart->m_tms * 0.000099999997) <= 0.0 )
    {
      flTimeRange = (float)v6 * 0.000099999997;
      KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLogDst);
      if ( KeyCount > 0 )
      {
        memset(&times, 0, sizeof(times));
        memset(&values, 0, sizeof(values));
        do
        {
          v31 = v4->GetKeyTime(this: v4, result: &v30, a3: v5);
          m_Size = times.m_Size;
          v9 = times.m_Size;
          if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
              num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
            m_Size = times.m_Size;
          }
          m_pMemory = times.m_Memory.m_pMemory;
          times.m_Size = m_Size + 1;
          v11 = m_Size - v9;
          times.m_pElements = times.m_Memory.m_pMemory;
          if ( v11 > 0 )
          {
            _V_memmove(dest: &times.m_Memory.m_pMemory[v9 + 1], src: &times.m_Memory.m_pMemory[v9], count: 4 * v11);
            m_pMemory = times.m_Memory.m_pMemory;
          }
          v12 = &m_pMemory[v9];
          if ( v12 != nullptr )
            v12->m_tms = v31->m_tms;
          KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v5);
          CUtlVector<VertexLookup_t,CUtlMemory<VertexLookup_t,int>>::InsertBefore(
            this: &values,
            elem: values.m_Size,
            src: KeyValue);
          v4 = pDmeTypedLogDst;
          ++v5;
        }
        while ( v5 < KeyCount );
        v14 = 0;
        QuaternionMA(p: &values.m_Memory.m_pMemory[KeyCount - 1], s: -1.0, q: values.m_Memory.m_pMemory, qt: &delta);
        if ( (float)((float)dmeTimeStart->m_tms * 0.000099999997) < 0.0 )
        {
          v15 = dmeTimeStart->m_tms + times.m_Memory.m_pMemory[KeyCount - 1].m_tms;
          dmeTimeBegin.m_tms = v15;
          v16 = 0;
          do
          {
            m_tms = times.m_Memory.m_pMemory[v14].m_tms;
            if ( m_tms >= v15 )
            {
              v18 = (float)((float)(m_tms - v15) * 0.000099999997) / flTimeRange;
              QuaternionSM(
                s: COERCE_FLOAT(
                  COERCE_UNSIGNED_INT((float)((float)(v18 * 3.0) * v18) - (float)((float)((float)(v18 * 2.0) * v18) * v18))
                ^ _mask__NegFloat_),
                p: &delta,
                q: &values.m_Memory.m_pMemory[v16],
                qt: &newValue);
              v15 = dmeTimeBegin.m_tms;
              values.m_Memory.m_pMemory[v16] = newValue;
            }
            ++v14;
            ++v16;
          }
          while ( v14 < KeyCount );
          v4 = pDmeTypedLogDst;
          v14 = 0;
        }
        if ( (float)((float)dmeTimeEnd->m_tms * 0.000099999997) > 0.0 )
        {
          dmeTimeBegina = times.m_Memory.m_pMemory->m_tms;
          v19 = 0;
          do
          {
            v20 = times.m_Memory.m_pMemory[v14].m_tms;
            if ( v20 > dmeTimeEnd->m_tms )
              break;
            v21 = (float)((float)(dmeTimeBegina + dmeTimeEnd->m_tms - v20) * 0.000099999997) / flTimeRange;
            QuaternionSM(
              s: (float)((float)(v21 * 3.0) * v21) - (float)((float)((float)(v21 * 2.0) * v21) * v21),
              p: &delta,
              q: &values.m_Memory.m_pMemory[v19],
              qt: &newValue);
            values.m_Memory.m_pMemory[v19] = newValue;
            ++v14;
            ++v19;
          }
          while ( v14 < KeyCount );
          v4 = pDmeTypedLogDst;
        }
        v22 = (int)v4->AddNewLayer(this: v4);
        v23 = (CDmeTypedLogLayer<Quaternion> *)v22;
        if ( v22 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
               a1: v22,
               a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v23, &times, &values);
        }
        v24 = values.m_Memory.m_pMemory;
        values.m_Size = 0;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( values.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
            v24 = nullptr;
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        values.m_pElements = v24;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v24 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        v25 = times.m_Memory.m_pMemory;
        times.m_Size = 0;
        if ( times.m_Memory.m_nGrowSize >= 0 )
        {
          if ( times.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
            v25 = nullptr;
            times.m_Memory.m_pMemory = nullptr;
          }
          times.m_Memory.m_nAllocationCount = 0;
        }
        times.m_pElements = v25;
        if ( times.m_Memory.m_nGrowSize >= 0 && v25 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F0B50
// Name: protected: void CDmeSubtract::Subtract<class Vector>(class CDmeTypedLog<class Vector> __near *,class CDmeTypedLog<class Vector> const __near *,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract<Vector>(
        CDmeSubtract *this,
        CDmeTypedLog<Vector> *pDmeTypedLogDst,
        CDmeTypedLog<Vector> *pDmeTypedLogSrc,
        const DmeTime_t *dmeTimeSrc)
{
  int v4; // ebx
  int m_Size; // eax
  int v6; // esi
  DmeTime_t *m_pMemory; // ecx
  int v8; // eax
  DmeTime_t *v9; // eax
  CDmeSubtract_vtbl *v10; // esi
  const Vector *KeyValue; // eax
  int v12; // eax
  int v13; // esi
  Vector *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  CDmeLogLayer *v17; // eax
  CDmeTypedLogLayer<Vector> *v18; // esi
  Vector *v19; // eax
  DmeTime_t *v20; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > values; // [esp+20h] [ebp-30h] BYREF
  Vector valueDst; // [esp+34h] [ebp-1Ch] BYREF
  Vector valueSrc; // [esp+40h] [ebp-10h] BYREF
  CDmeSubtract *v25; // [esp+4Ch] [ebp-4h]

  v25 = this;
  v4 = 0;
  valueSrc = *CDmeTypedLog<Vector>::GetValue(this: pDmeTypedLogSrc, time: (DmeTime_t)dmeTimeSrc->m_tms);
  memset(&times, 0, sizeof(times));
  memset(&values, 0, sizeof(values));
  if ( CDmeLog::GetKeyCount(this: pDmeTypedLogDst) > 0 )
  {
    do
    {
      dmeTimeSrc = pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &pDmeTypedLogSrc, a3: v4);
      m_Size = times.m_Size;
      v6 = times.m_Size;
      if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
          num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
        m_Size = times.m_Size;
      }
      m_pMemory = times.m_Memory.m_pMemory;
      times.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      times.m_pElements = times.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &times.m_Memory.m_pMemory[v6 + 1], src: &times.m_Memory.m_pMemory[v6], count: 4 * v8);
        m_pMemory = times.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_tms = dmeTimeSrc->m_tms;
      v10 = v25->__vftable;
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
      v10->Subtract_2(this: v25, a2: &valueDst, a3: KeyValue, a4: &valueSrc);
      v12 = values.m_Size;
      v13 = values.m_Size;
      if ( values.m_Size + 1 > values.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&values,
          num: values.m_Size - values.m_Memory.m_nAllocationCount + 1);
        v12 = values.m_Size;
      }
      v14 = values.m_Memory.m_pMemory;
      values.m_Size = v12 + 1;
      v15 = v12 - v13;
      values.m_pElements = values.m_Memory.m_pMemory;
      if ( v15 > 0 )
      {
        _V_memmove(dest: &values.m_Memory.m_pMemory[v13 + 1], src: &values.m_Memory.m_pMemory[v13], count: 12 * v15);
        v14 = values.m_Memory.m_pMemory;
      }
      v16 = &v14[v13];
      if ( v16 != nullptr )
        *v16 = valueDst;
      ++v4;
    }
    while ( v4 < CDmeLog::GetKeyCount(this: pDmeTypedLogDst) );
  }
  v17 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
  v18 = (CDmeTypedLogLayer<Vector> *)v17;
  if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmeTypedLogLayer<Vector>::m_classType) )
    CDmeTypedLogLayer<Vector>::SetAllKeys(this: v18, &times, &values);
  v19 = values.m_Memory.m_pMemory;
  values.m_Size = 0;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( values.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
      v19 = nullptr;
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  values.m_pElements = v19;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  v20 = times.m_Memory.m_pMemory;
  times.m_Size = 0;
  if ( times.m_Memory.m_nGrowSize >= 0 )
  {
    if ( times.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
      v20 = nullptr;
      times.m_Memory.m_pMemory = nullptr;
    }
    times.m_Memory.m_nAllocationCount = 0;
  }
  times.m_pElements = v20;
  if ( times.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x004F0D80
// Name: protected: void CDmeSubtract::Subtract<class Quaternion>(class CDmeTypedLog<class Quaternion> __near *,class CDmeTypedLog<class Quaternion> const __near *,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract<Quaternion>(
        CDmeSubtract *this,
        CDmeTypedLog<Quaternion> *pDmeTypedLogDst,
        CDmeTypedLog<Quaternion> *pDmeTypedLogSrc,
        const DmeTime_t *dmeTimeSrc)
{
  int v4; // ebx
  int m_Size; // eax
  int v6; // esi
  DmeTime_t *m_pMemory; // ecx
  int v8; // eax
  DmeTime_t *v9; // eax
  CDmeSubtract_vtbl *v10; // esi
  const Quaternion *KeyValue; // eax
  int v12; // eax
  int v13; // esi
  Quaternion *v14; // ecx
  int v15; // eax
  Quaternion *v16; // esi
  CDmeLogLayer *v17; // eax
  CDmeTypedLogLayer<Quaternion> *v18; // esi
  Quaternion *v19; // eax
  DmeTime_t *v20; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > values; // [esp+20h] [ebp-38h] BYREF
  Quaternion valueDst; // [esp+34h] [ebp-24h] BYREF
  Quaternion valueSrc; // [esp+44h] [ebp-14h] BYREF
  CDmeSubtract *v25; // [esp+54h] [ebp-4h]

  v25 = this;
  v4 = 0;
  valueSrc = *CDmeTypedLog<Quaternion>::GetValue(this: pDmeTypedLogSrc, time: (DmeTime_t)dmeTimeSrc->m_tms);
  memset(&times, 0, sizeof(times));
  memset(&values, 0, sizeof(values));
  if ( CDmeLog::GetKeyCount(this: pDmeTypedLogDst) > 0 )
  {
    do
    {
      dmeTimeSrc = pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &pDmeTypedLogSrc, a3: v4);
      m_Size = times.m_Size;
      v6 = times.m_Size;
      if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
          num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
        m_Size = times.m_Size;
      }
      m_pMemory = times.m_Memory.m_pMemory;
      times.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      times.m_pElements = times.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &times.m_Memory.m_pMemory[v6 + 1], src: &times.m_Memory.m_pMemory[v6], count: 4 * v8);
        m_pMemory = times.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_tms = dmeTimeSrc->m_tms;
      v10 = v25->__vftable;
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
      v10->Subtract(this: v25, a2: &valueDst, a3: KeyValue, a4: &valueSrc);
      v12 = values.m_Size;
      v13 = values.m_Size;
      if ( values.m_Size + 1 > values.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&values,
          num: values.m_Size - values.m_Memory.m_nAllocationCount + 1);
        v12 = values.m_Size;
      }
      v14 = values.m_Memory.m_pMemory;
      values.m_Size = v12 + 1;
      v15 = v12 - v13;
      values.m_pElements = values.m_Memory.m_pMemory;
      if ( v15 > 0 )
      {
        _V_memmove(dest: &values.m_Memory.m_pMemory[v13 + 1], src: &values.m_Memory.m_pMemory[v13], count: 16 * v15);
        v14 = values.m_Memory.m_pMemory;
      }
      v16 = &v14[v13];
      if ( v16 != nullptr )
        *v16 = valueDst;
      ++v4;
    }
    while ( v4 < CDmeLog::GetKeyCount(this: pDmeTypedLogDst) );
  }
  v17 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
  v18 = (CDmeTypedLogLayer<Quaternion> *)v17;
  if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmeTypedLogLayer<Quaternion>::m_classType) )
    CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v18, &times, &values);
  v19 = values.m_Memory.m_pMemory;
  values.m_Size = 0;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( values.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
      v19 = nullptr;
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  values.m_pElements = v19;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  v20 = times.m_Memory.m_pMemory;
  times.m_Size = 0;
  if ( times.m_Memory.m_nGrowSize >= 0 )
  {
    if ( times.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
      v20 = nullptr;
      times.m_Memory.m_pMemory = nullptr;
    }
    times.m_Memory.m_nAllocationCount = 0;
  }
  times.m_pElements = v20;
  if ( times.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x004F0FB0
// Name: GetAllKeys_Vector_
// Source: json
//------------------------------------------------------------------------------
void __usercall GetAllKeys_Vector_(
        CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *keyTimes@<edi>,
        CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *keyValues@<esi>,
        CDmeTypedLog<Vector> *pDmeTypedLog)
{
  CDmeTypedLog<Vector> *v3; // ebx
  int KeyCount; // eax
  int v5; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  DmeTime_t *v10; // ebx
  const Vector *KeyValue; // eax
  int v12; // ebx
  int v13; // eax
  Vector *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  int *v17; // eoff
  DmeTime_t v18; // [esp+4h] [ebp-10h] BYREF
  int *v19; // [esp+8h] [ebp-Ch]
  int nKeyCount; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v3 = pDmeTypedLog;
  keyTimes->m_Storage.m_Size = 0;
  keyValues->m_Storage.m_Size = 0;
  KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLog);
  nKeyCount = KeyCount;
  if ( KeyCount > 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: keyTimes, num: KeyCount);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(this: keyValues, num: nKeyCount);
    i = 0;
    while ( 1 )
    {
      v5 = (int)v3->GetKeyTime(this: v3, result: &v18, a3: i);
      m_Size = keyTimes->m_Storage.m_Size;
      v19 = (int *)v5;
      m_nAllocationCount = keyTimes->m_Storage.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)keyTimes,
          num: m_Size - m_nAllocationCount + 1);
      ++keyTimes->m_Storage.m_Size;
      m_pMemory = keyTimes->m_Storage.m_Memory.m_pMemory;
      v9 = keyTimes->m_Storage.m_Size - m_Size - 1;
      keyTimes->m_Storage.m_pElements = keyTimes->m_Storage.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v10 = &keyTimes->m_Storage.m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        v10->m_tms = *v19;
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLog, nKeyIndex: i);
      v12 = keyValues->m_Storage.m_Size;
      v19 = (int *)KeyValue;
      v13 = keyValues->m_Storage.m_Memory.m_nAllocationCount;
      if ( v12 + 1 > v13 )
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)keyValues,
          num: v12 - v13 + 1);
      ++keyValues->m_Storage.m_Size;
      v14 = (Vector *)keyValues->m_Storage.m_Memory.m_pMemory;
      v15 = keyValues->m_Storage.m_Size - v12 - 1;
      keyValues->m_Storage.m_pElements = keyValues->m_Storage.m_Memory.m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 12 * v15);
      v16 = (Vector *)&keyValues->m_Storage.m_Memory.m_pMemory[v12];
      if ( v16 != nullptr )
      {
        v17 = v19;
        *(_QWORD *)&v16->x = *(_QWORD *)v19;
        LODWORD(v16->z) = v17[2];
      }
      if ( ++i >= nKeyCount )
        break;
      v3 = pDmeTypedLog;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F1100
// Name: GetAllKeys_Quaternion_
// Source: json
//------------------------------------------------------------------------------
void __usercall GetAllKeys_Quaternion_(
        CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *keyTimes@<esi>,
        CDmaArrayBase<Quaternion,CDmaDataInternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *keyValues,
        CDmeTypedLog<Quaternion> *pDmeTypedLog)
{
  CDmeTypedLog<Quaternion> *v4; // edi
  int KeyCount; // eax
  int v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmeTime_t *m_pMemory; // ecx
  int v10; // eax
  DmeTime_t *v11; // edi
  const Quaternion *KeyValue; // eax
  int v13; // edi
  int v14; // eax
  Quaternion *v15; // ecx
  int v16; // eax
  Quaternion *v17; // edi
  int *v18; // eax
  DmeTime_t v19; // [esp+8h] [ebp-Ch] BYREF
  int *v20; // [esp+Ch] [ebp-8h]
  int nKeyCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v4 = pDmeTypedLog;
  keyTimes->m_Storage.m_Size = 0;
  keyValues->m_Storage.m_Size = 0;
  KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLog);
  nKeyCount = KeyCount;
  if ( KeyCount > 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: keyTimes, num: KeyCount);
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(this: keyValues, num: nKeyCount);
    i = 0;
    while ( 1 )
    {
      v6 = (int)v4->GetKeyTime(this: v4, result: &v19, a3: i);
      m_Size = keyTimes->m_Storage.m_Size;
      v20 = (int *)v6;
      m_nAllocationCount = keyTimes->m_Storage.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)keyTimes,
          num: m_Size - m_nAllocationCount + 1);
      ++keyTimes->m_Storage.m_Size;
      m_pMemory = keyTimes->m_Storage.m_Memory.m_pMemory;
      v10 = keyTimes->m_Storage.m_Size - m_Size - 1;
      keyTimes->m_Storage.m_pElements = keyTimes->m_Storage.m_Memory.m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &keyTimes->m_Storage.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        v11->m_tms = *v20;
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLog, nKeyIndex: i);
      v13 = keyValues->m_Storage.m_Size;
      v20 = (int *)KeyValue;
      v14 = keyValues->m_Storage.m_Memory.m_nAllocationCount;
      if ( v13 + 1 > v14 )
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)keyValues,
          num: v13 - v14 + 1);
      ++keyValues->m_Storage.m_Size;
      v15 = keyValues->m_Storage.m_Memory.m_pMemory;
      v16 = keyValues->m_Storage.m_Size - v13 - 1;
      keyValues->m_Storage.m_pElements = keyValues->m_Storage.m_Memory.m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &v15[v13 + 1], src: &v15[v13], count: 16 * v16);
      v17 = &keyValues->m_Storage.m_Memory.m_pMemory[v13];
      if ( v17 != nullptr )
      {
        v18 = v20;
        *(_QWORD *)&v17->x = *(_QWORD *)v20;
        *(_QWORD *)&v17->z = *((_QWORD *)v18 + 1);
      }
      if ( ++i >= nKeyCount )
        break;
      v4 = pDmeTypedLog;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F12C0
// Name: public: virtual bool CDmeFixupLoop::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeFixupLoop::Apply(CDmeFixupLoop *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  const char *v3; // ecx
  CDmeSequence *v5; // esi
  const char *v6; // ecx
  CDmeChannelsClip *FrameCount; // eax
  int m_Storage; // esi
  int v9; // ecx
  int i; // edi
  int v11; // eax
  int v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v14; // esi
  CUtlString *v15; // eax
  CUtlString *v16; // eax
  const char *v17; // eax
  const char *v18; // [esp-8h] [ebp-4Ch] BYREF
  const char *TypeString; // [esp-4h] [ebp-48h]
  CUtlString v20; // [esp+Ch] [ebp-38h] BYREF
  CUtlString v21; // [esp+1Ch] [ebp-28h] BYREF
  DmeTime_t nStartTime; // [esp+2Ch] [ebp-18h] BYREF
  DmeTime_t nEndTime; // [esp+30h] [ebp-14h] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+34h] [ebp-10h] BYREF
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+38h] [ebp-Ch] BYREF
  CDmeFixupLoop *v26; // [esp+3Ch] [ebp-8h]
  DmeFramerate_t dmeFrameRateDst; // [esp+40h] [ebp-4h] BYREF
  bool pDmElement_3; // [esp+4Fh] [ebp+Bh]

  v26 = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v20, pDmElement: this);
  pDmElement_3 = ConvertToDmeSequenceAndDmeChannelsClip(
                   pDmElement,
                   sDmElementId: v2,
                   pDmeSequence: &pDmeSequenceDst,
                   pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v20.m_Storage.m_nActualLength = 0;
  if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 && v20.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
  if ( pDmElement_3 )
    return 0;
  TypeString = nullptr;
  v18 = v3;
  DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v18, fps: 0x1Eu);
  v5 = pDmeSequenceDst;
  CDmeSequence::GetFrameRate(
    this: pDmeSequenceDst,
    result: &dmeFrameRateDst,
    fallbackFrameRate: (DmeFramerate_t)v18,
    bForceFallback: (int)TypeString);
  TypeString = nullptr;
  v18 = v6;
  DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v18, fps: 0x1Eu);
  FrameCount = CDmeSequence::GetFrameCount(
                 this: v5,
                 fallbackFrameRate: (DmeFramerate_t)v18,
                 bForceFallback: (int)TypeString);
  m_Storage = v26->m_nEndFrame.m_Storage;
  v9 = v26->m_nStartFrame.m_Storage;
  if ( m_Storage - v9 > (int)FrameCount )
  {
    m_Storage = (int)FrameCount + v9;
    if ( (int)FrameCount + v9 < 0 )
    {
      m_Storage = 0;
      v9 = 1 - (_DWORD)FrameCount;
    }
  }
  DmeTime_t::DmeTime_t(this: &nStartTime, frame: v9, framerate: *(_DWORD *)&dmeFrameRateDst);
  DmeTime_t::DmeTime_t(this: &nEndTime, frame: m_Storage, framerate: *(_DWORD *)&dmeFrameRateDst);
  for ( i = 0; i < pDmeChannelsClipDst->m_Channels.m_Storage.m_Size; ++i )
  {
    v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: pDmeChannelsClipDst->m_Channels.m_Storage.m_Memory.m_pMemory[i]);
    v12 = v11;
    if ( v11 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
           a1: v11,
           a2: CDmeChannel::m_classType.u) != 0
      && v12 != 4 )
    {
      Log = CDmeChannel::GetLog(this: (CDmeChannel *)(v12 - 4));
      v14 = (CDmeTypedLog<Vector> *)Log;
      if ( Log != nullptr )
      {
        if ( Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) )
        {
          CDmeFixupLoop::Apply<Vector>(
            this: v26,
            pDmeTypedLogDst: v14,
            dmeTimeStart: &nStartTime,
            dmeTimeEnd: &nEndTime);
        }
        else if ( v14->IsA(this: v14, a2: CDmeTypedLog<Quaternion>::m_classType) )
        {
          CDmeFixupLoop::Apply<Quaternion>(
            this: v26,
            pDmeTypedLogDst: (CDmeTypedLog<Quaternion> *)v14,
            dmeTimeStart: &nStartTime,
            dmeTimeEnd: &nEndTime);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
        {
          TypeString = CDmElement::GetTypeString(this: v14);
          v15 = ComputeDmElementIdStr(result: &v20, pDmElement: pDmeSequenceDst);
          v18 = CUtlString::Get(this: v15);
          v16 = ComputeDmElementIdStr(result: &v21, pDmElement: v26);
          v17 = CUtlString::Get(this: v16);
          _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 1, a3: "%s: Unsupported DmeLog Type: \"%s\"\n", v17, v18);
          v21.m_Storage.m_nActualLength = 0;
          if ( v21.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v21.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21.m_Storage.m_Memory.m_pMemory);
              v21.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v21.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v20.m_Storage.m_nActualLength = 0;
          if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
              v20.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v20.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004F1550
// Name: public: virtual bool CDmeSubtract::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSubtract::Apply(CDmeSubtract *this, float pDmElement)
{
  CUtlString *v3; // edi
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeSequence *v6; // esi
  CUtlString *v7; // edi
  unsigned int v8; // ecx
  CDmeChannelsClip *v9; // edi
  DmeTime_t *StartTime; // eax
  __m128i v11; // xmm0
  CUtlSymbolLarge::<unnamed_type_u> v12; // eax
  float v13; // xmm0_4
  const char *m_Id; // esi
  CUtlString *v15; // eax
  CUtlString *v16; // eax
  const char *v17; // eax
  DmeTime_t *EndTime; // eax
  __m128i v19; // xmm0
  CUtlSymbolLarge::<unnamed_type_u> v20; // eax
  float v21; // xmm0_4
  const char *v22; // esi
  CUtlString *v23; // eax
  CUtlString *v24; // eax
  const char *v25; // eax
  CDmeChannelsClip *v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // esi
  int v30; // ebx
  CDmeLog *Log; // eax
  CDmeLog *v32; // esi
  char *v33; // ebx
  CDmeTypedLog<Vector> *v34; // edi
  CDmeTypedLog<Quaternion> *v35; // ebx
  int v36; // eax
  int v37; // esi
  CDmeChannel *v38; // esi
  const char *m_pAsString; // eax
  CDmeTypedLog<Vector> *v40; // esi
  CUtlString *v41; // eax
  CUtlString *v42; // eax
  const char *v43; // eax
  int m_Storage; // [esp+10h] [ebp-70h]
  int v45; // [esp+10h] [ebp-70h]
  double v46; // [esp+14h] [ebp-6Ch]
  double v47; // [esp+14h] [ebp-6Ch]
  double FramesPerSecond; // [esp+1Ch] [ebp-64h]
  double v49; // [esp+1Ch] [ebp-64h]
  const char *v50; // [esp+24h] [ebp-5Ch]
  const char *v51; // [esp+24h] [ebp-5Ch]
  double v52; // [esp+28h] [ebp-58h] BYREF
  CUtlString v53; // [esp+3Ch] [ebp-44h] BYREF
  CUtlString v54; // [esp+4Ch] [ebp-34h] BYREF
  DmeTime_t v55; // [esp+5Ch] [ebp-24h] BYREF
  int i; // [esp+60h] [ebp-20h]
  char *s1; // [esp+64h] [ebp-1Ch]
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+68h] [ebp-18h] BYREF
  CDmeSubtract *v59; // [esp+6Ch] [ebp-14h]
  DmeFramerate_t dmeFrameRateSrc; // [esp+70h] [ebp-10h] BYREF
  int j; // [esp+74h] [ebp-Ch] BYREF
  CDmeChannelsClip *pDmeChannelsClipSrc; // [esp+78h] [ebp-8h] BYREF
  DmeTime_t dmeTimeSrc; // [esp+7Ch] [ebp-4h] BYREF

  v59 = this;
  pDmeChannelsClipDst = nullptr;
  v3 = ComputeDmElementIdStr(result: &v53, pDmElement: this);
  HIBYTE(pDmElement) = ConvertToDmeSequenceAndDmeChannelsClip(
                         pDmElement: (CDmeSequence *)LODWORD(pDmElement),
                         sDmElementId: v3,
                         pDmeSequence: (CDmeSequence **)&pDmElement,
                         pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v53.m_Storage.m_nActualLength = 0;
  if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
  if ( HIBYTE(pDmElement) == 0 )
  {
    v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    HIDWORD(v52) = this->m_eSequence.m_Storage.m_Handle;
    j = 0;
    pDmeChannelsClipSrc = nullptr;
    v6 = (CDmeSequence *)((int (__thiscall *)(_DWORD, _DWORD))v5)(
                           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                           a2: HIDWORD(v52));
    v7 = ComputeDmElementIdStr(result: &v53, pDmElement: this);
    HIBYTE(pDmElement) = ConvertToDmeSequenceAndDmeChannelsClip(
                           pDmElement: v6,
                           sDmElementId: v7,
                           pDmeSequence: (CDmeSequence **)&j,
                           pDmeChannelsClip: &pDmeChannelsClipSrc) == 0;
    v53.m_Storage.m_nActualLength = 0;
    if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
    if ( HIBYTE(pDmElement) == 0 )
    {
      *(_QWORD *)&v52 = v8;
      DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v52, fps: 0x1Eu);
      CDmeSequence::GetFrameRate(
        this: (CDmeSequence *)j,
        result: &dmeFrameRateSrc,
        fallbackFrameRate: LODWORD(v52),
        bForceFallback: SHIDWORD(v52));
      DmeTime_t::DmeTime_t(this: &dmeTimeSrc, frame: this->m_nFrame.m_Storage, framerate: *(_DWORD *)&dmeFrameRateSrc);
      v9 = pDmeChannelsClipSrc;
      StartTime = CDmeClip::GetStartTime(this: pDmeChannelsClipSrc, result: (DmeTime_t *)&pDmElement);
      if ( dmeTimeSrc.m_tms < StartTime->m_tms
        && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
      {
        v11 = _mm_cvtsi32_si128(CDmeClip::GetStartTime(this: v9, result: &v55)->m_tms);
        v12.m_Id = (int)this->m_nFrame.m_pAttribute->m_Name.u;
        v13 = _mm_cvtepi32_ps(v11).m128_f32[0] * 0.000099999997;
        pDmElement = (float)dmeTimeSrc.m_tms * 0.000099999997;
        m_Id = pDeltaStateName;
        if ( v12.m_Id != -1 )
          m_Id = (const char *)v12.m_Id;
        v52 = v13;
        v15 = ComputeDmElementIdStr(result: &v53, pDmElement: (const CDmElement *)j);
        v50 = CUtlString::Get(this: v15);
        FramesPerSecond = DmeFramerate_t::GetFramesPerSecond(this: &dmeFrameRateSrc);
        v46 = pDmElement;
        m_Storage = this->m_nFrame.m_Storage;
        v16 = ComputeDmElementIdStr(result: &v54, pDmElement: this);
        v17 = CUtlString::Get(this: v16);
        _LoggingSystem_Log(
          a1: LOG_DME_AAC,
          a2: 1,
          a3: "%s: .%s %d (%.2fs @ %g fps) < %s Start Time of %.2fs\n",
          v17,
          m_Id,
          m_Storage,
          v46,
          FramesPerSecond,
          v50,
          v52);
        v54.m_Storage.m_nActualLength = 0;
        if ( v54.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v54.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_Storage.m_Memory.m_pMemory);
            v54.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v54.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v53.m_Storage.m_nActualLength = 0;
        if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
      }
      EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&pDmElement);
      if ( dmeTimeSrc.m_tms > EndTime->m_tms
        && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
      {
        v19 = _mm_cvtsi32_si128(CDmeClip::GetEndTime(this: v9, result: &v55)->m_tms);
        v20.m_Id = (int)this->m_nFrame.m_pAttribute->m_Name.u;
        v21 = _mm_cvtepi32_ps(v19).m128_f32[0] * 0.000099999997;
        pDmElement = (float)dmeTimeSrc.m_tms * 0.000099999997;
        v22 = pDeltaStateName;
        if ( v20.m_Id != -1 )
          v22 = (const char *)v20.m_Id;
        v52 = v21;
        v23 = ComputeDmElementIdStr(result: &v53, pDmElement: (const CDmElement *)j);
        v51 = CUtlString::Get(this: v23);
        v49 = DmeFramerate_t::GetFramesPerSecond(this: &dmeFrameRateSrc);
        v47 = pDmElement;
        v45 = this->m_nFrame.m_Storage;
        v24 = ComputeDmElementIdStr(result: &v54, pDmElement: this);
        v25 = CUtlString::Get(this: v24);
        _LoggingSystem_Log(
          a1: LOG_DME_AAC,
          a2: 1,
          a3: "%s: .%s %d (%.2fs @ %g fps) > %s End Time of %.2fs\n",
          v25,
          v22,
          v45,
          v47,
          v49,
          v51,
          v52);
        v54.m_Storage.m_nActualLength = 0;
        if ( v54.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v54.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_Storage.m_Memory.m_pMemory);
            v54.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v54.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v53.m_Storage.m_nActualLength = 0;
        if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
      }
      v26 = pDmeChannelsClipDst;
      v27 = 0;
      i = 0;
      if ( pDmeChannelsClipDst->m_Channels.m_Storage.m_Size <= 0 )
        return 1;
      do
      {
        v28 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v26->m_Channels.m_Storage.m_Memory.m_pMemory[v27]);
        v29 = v28;
        if ( v28 == 0 )
          goto LABEL_66;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v28 + 16))(
               a1: v28,
               a2: CDmeChannel::m_classType.u) == 0 )
          goto LABEL_66;
        v30 = v29 - 4;
        v55.m_tms = v29 - 4;
        if ( v29 == 4 )
          goto LABEL_66;
        Log = CDmeChannel::GetLog(this: (CDmeChannel *)(v29 - 4));
        v32 = Log;
        if ( Log == nullptr )
          goto LABEL_66;
        v33 = *(char **)(v30 + 24);
        s1 = (char *)pDeltaStateName;
        if ( v33 != (char *)-1 )
          s1 = v33;
        v34 = Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) ? (CDmeTypedLog<Vector> *)Log : nullptr;
        v35 = v32->IsA(this: v32, a2: CDmeTypedLog<Quaternion>::m_classType) ? (CDmeTypedLog<Quaternion> *)v32 : nullptr;
        HIBYTE(pDmElement) = 0;
        j = 0;
        if ( pDmeChannelsClipSrc->m_Channels.m_Storage.m_Size <= 0 )
        {
LABEL_56:
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
          {
            v41 = ComputeDmElementIdStr(result: &v53, pDmElement: (const CDmElement *)(v55.m_tms + 4));
            HIDWORD(v52) = CUtlString::Get(this: v41);
            v42 = ComputeDmElementIdStr(result: &v54, pDmElement: v59);
            v43 = CUtlString::Get(this: v42);
            _LoggingSystem_Log(
              a1: LOG_DME_AAC,
              a2: 1,
              a3: "%s: No Channel Found To Subtract From %s\n",
              v43,
              (const char *)HIDWORD(v52));
            v54.m_Storage.m_nActualLength = 0;
            if ( v54.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v54.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_Storage.m_Memory.m_pMemory);
                v54.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v54.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            v53.m_Storage.m_nActualLength = 0;
            if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v53.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
                v53.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v53.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
          goto LABEL_65;
        }
        do
        {
          v36 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: pDmeChannelsClipSrc->m_Channels.m_Storage.m_Memory.m_pMemory[j]);
          v37 = v36;
          if ( v36 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v36 + 16))(
                 a1: v36,
                 a2: CDmeChannel::m_classType.u) != 0 )
          {
            v38 = (CDmeChannel *)(v37 - 4);
            if ( v38 != nullptr )
            {
              m_pAsString = v38->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = pDeltaStateName;
              if ( _V_stricmp(s1, s2: m_pAsString) == 0 )
              {
                v40 = (CDmeTypedLog<Vector> *)CDmeChannel::GetLog(this: v38);
                if ( v40 != nullptr )
                {
                  if ( v40->IsA(this: v40, a2: CDmeTypedLog<Vector>::m_classType) && v34 != nullptr )
                  {
                    CDmeSubtract::Subtract<Vector>(this: v59, pDmeTypedLogDst: v34, pDmeTypedLogSrc: v40, &dmeTimeSrc);
LABEL_53:
                    HIBYTE(pDmElement) = 1;
                    goto LABEL_54;
                  }
                  if ( v40->IsA(this: v40, a2: CDmeTypedLog<Quaternion>::m_classType) && v35 != nullptr )
                  {
                    CDmeSubtract::Subtract<Quaternion>(
                      this: v59,
                      pDmeTypedLogDst: v35,
                      pDmeTypedLogSrc: (CDmeTypedLog<Quaternion> *)v40,
                      &dmeTimeSrc);
                    goto LABEL_53;
                  }
                }
              }
            }
          }
LABEL_54:
          ++j;
        }
        while ( j < pDmeChannelsClipSrc->m_Channels.m_Storage.m_Size );
        if ( HIBYTE(pDmElement) == 0 )
          goto LABEL_56;
LABEL_65:
        v27 = i;
LABEL_66:
        v26 = pDmeChannelsClipDst;
        i = ++v27;
      }
      while ( v27 < pDmeChannelsClipDst->m_Channels.m_Storage.m_Size );
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004F1B50
// Name: protected: void CDmeBoneMaskCmd::SubApply(class CDmeChannelsClip __near *,class CDmeDag __near *,class CDmeBoneMask __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskCmd::SubApply(
        CDmeBoneMaskCmd *this,
        CDmeTypedLog<Vector> *pDmeChannelsClip,
        CDmeTypedLog<Quaternion> *pDmeDag,
        float pDmeBoneMask)
{
  CDmeChannelsClip *v4; // edi
  CDmeDag *v5; // esi
  const char *m_pAsString; // eax
  double BoneWeight; // st7
  CUtlString *v8; // eax
  CUtlString *v9; // eax
  const char *v10; // eax
  float v11; // xmm3_4
  int v12; // ecx
  int v13; // edx
  Vector *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  int v17; // edi
  int v18; // esi
  int v19; // eax
  CDmeTypedLogLayer<Vector> *v20; // esi
  CUtlString *v21; // eax
  const char *v22; // eax
  int v23; // eax
  CDmeTypedLogLayer<Quaternion> *v24; // esi
  CUtlString *v25; // eax
  const char *v26; // eax
  const char *v27; // [esp+4h] [ebp-94h]
  CUtlString result; // [esp+14h] [ebp-84h] BYREF
  Quaternion qTmp; // [esp+24h] [ebp-74h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > qTimes; // [esp+34h] [ebp-64h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > vTimes; // [esp+48h] [ebp-50h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > vValues; // [esp+5Ch] [ebp-3Ch] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > qValues; // [esp+70h] [ebp-28h] BYREF
  CUtlString v34; // [esp+84h] [ebp-14h] BYREF
  CDmElement *pDmElement; // [esp+94h] [ebp-4h]

  v4 = (CDmeChannelsClip *)pDmeChannelsClip;
  pDmElement = this;
  if ( pDmeChannelsClip != nullptr )
  {
    v5 = (CDmeDag *)pDmeDag;
    if ( pDmeDag != nullptr && pDmeBoneMask != 0.0 )
    {
      m_pAsString = pDmeDag->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      BoneWeight = CDmeBoneMask::GetBoneWeight(this: (CDmeBoneMask *)LODWORD(pDmeBoneMask), pszBoneName: m_pAsString);
      pDmeBoneMask = BoneWeight;
      if ( BoneWeight != 1.0 && CDmeDag::GetTransform(this: v5) != nullptr )
      {
        pDmeChannelsClip = nullptr;
        pDmeDag = nullptr;
        if ( GetDmeChannelsForDag(
               pDmeTranslateLog: &pDmeChannelsClip,
               pDmeRotateLog: &pDmeDag,
               pDmeDag: v5,
               pDmeChannelsClip: v4) != 0 )
        {
          memset(&vTimes, 0, sizeof(vTimes));
          memset(&vValues, 0, sizeof(vValues));
          GetAllKeys_Vector_(
            keyTimes: (CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vTimes,
            keyValues: (CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *)&vValues,
            pDmeTypedLog: pDmeChannelsClip);
          v11 = pDmeBoneMask;
          v12 = 0;
          if ( vValues.m_Size > 0 )
          {
            v13 = 0;
            do
            {
              v14 = &vValues.m_Memory.m_pMemory[v13];
              v15 = vValues.m_Memory.m_pMemory[v13].y * v11;
              v16 = vValues.m_Memory.m_pMemory[v13].z * v11;
              ++v12;
              v14->x = vValues.m_Memory.m_pMemory[v13].x * v11;
              v14->y = v15;
              v14->z = v16;
              ++v13;
            }
            while ( v12 < vValues.m_Size );
          }
          memset(&qTimes, 0, sizeof(qTimes));
          memset(&qValues, 0, sizeof(qValues));
          GetAllKeys_Quaternion_(
            keyTimes: (CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&qTimes,
            keyValues: (CDmaArrayBase<Quaternion,CDmaDataInternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *)&qValues,
            pDmeTypedLog: pDmeDag);
          v17 = 0;
          if ( qValues.m_Size > 0 )
          {
            v18 = 0;
            do
            {
              QuaternionScale(p: &qValues.m_Memory.m_pMemory[v18], t: pDmeBoneMask, q: &qTmp);
              qValues.m_Memory.m_pMemory[v18] = qTmp;
              ++v17;
              ++v18;
            }
            while ( v17 < qValues.m_Size );
          }
          v19 = (int)pDmeChannelsClip->AddNewLayer(this: pDmeChannelsClip);
          v20 = (CDmeTypedLogLayer<Vector> *)v19;
          if ( v19 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v19 + 16))(
                 a1: v19,
                 a2: CDmeTypedLogLayer<Vector>::m_classType.u) != 0 )
          {
            CDmeTypedLogLayer<Vector>::SetAllKeys(this: v20, times: &vTimes, values: &vValues);
            v20->RemoveRedundantKeys_2(this: v20, a2: true);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
          {
            v21 = ComputeDmElementIdStr(result: &v34, pDmElement);
            v22 = CUtlString::Get(this: v21);
            _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Translate Layer\n", v22);
            v34.m_Storage.m_nActualLength = 0;
            if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
          }
          v23 = (int)pDmeDag->AddNewLayer(this: pDmeDag);
          v24 = (CDmeTypedLogLayer<Quaternion> *)v23;
          if ( v23 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v23 + 16))(
                 a1: v23,
                 a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
          {
            CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v24, times: &qTimes, values: &qValues);
            v24->RemoveRedundantKeys_2(this: v24, a2: true);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
          {
            v25 = ComputeDmElementIdStr(result: &v34, pDmElement);
            v26 = CUtlString::Get(this: v25);
            _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Rotate Layer\n", v26);
            v34.m_Storage.m_nActualLength = 0;
            if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
          }
          CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&qValues);
          CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&qTimes);
          CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vValues);
          CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vTimes);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
        {
          v8 = ComputeDmElementIdStr(&result, pDmElement: v5);
          v27 = CUtlString::Get(this: v8);
          v9 = ComputeDmElementIdStr(result: &v34, pDmElement);
          v10 = CUtlString::Get(this: v9);
          _LoggingSystem_Log(
            a1: LOG_DME_AAC,
            a2: 3,
            a3: "%s: Couldn't Find Translate & Rotate channels for DmeDag %s\n",
            v10,
            v27);
          CUtlString::~CUtlString(this: &v34);
          CUtlString::~CUtlString(this: &result);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F1EC0
// Name: public: virtual bool CDmeBoneMaskCmd::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeBoneMaskCmd::Apply(CDmeBoneMaskCmd *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  const CDmElement *v3; // esi
  CUtlString *v4; // eax
  CUtlString *v5; // eax
  CUtlString *v7; // eax
  CUtlString *v8; // eax
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  CDmeDag **v11; // eax
  CDmeDag *v12; // ebx
  int v13; // eax
  char *v14; // [esp-8h] [ebp-48h]
  char *v15; // [esp-8h] [ebp-48h]
  char *v16; // [esp-4h] [ebp-44h]
  char *v17; // [esp-4h] [ebp-44h]
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > depthFirstStack; // [esp+Ch] [ebp-34h] BYREF
  CUtlString v19; // [esp+20h] [ebp-20h] BYREF
  CDmeBoneMask *pDmeBoneMask; // [esp+30h] [ebp-10h]
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+34h] [ebp-Ch] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+38h] [ebp-8h] BYREF
  CDmElement *pDmElementa; // [esp+3Ch] [ebp-4h]
  int i; // [esp+48h] [ebp+8h]
  int ia; // [esp+48h] [ebp+8h]
  bool i_3; // [esp+4Bh] [ebp+Bh]

  pDmElementa = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v19, pDmElement: this);
  i_3 = ConvertToDmeSequenceAndDmeChannelsClip(
          pDmElement,
          sDmElementId: v2,
          pDmeSequence: &pDmeSequenceDst,
          pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v19.m_Storage.m_nActualLength = 0;
  if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
  if ( i_3 )
    return 0;
  v3 = pDmeSequenceDst;
  i = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
        a1: g_pDataModel.u,
        a2: pDmeSequenceDst->m_eSkeleton.m_Storage.m_Handle);
  if ( i == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v4 = ComputeDmElementIdStr(result: (CUtlString *)&depthFirstStack.m_Memory.m_nAllocationCount, pDmElement: v3);
      v16 = CUtlString::Get(this: v4);
      v5 = ComputeDmElementIdStr(result: &v19, pDmElement: pDmElementa);
      v14 = CUtlString::Get(this: v5);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No Skeleton\n", v14, v16);
LABEL_8:
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v19.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
          v19.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v19.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      depthFirstStack.m_pElements = nullptr;
      if ( depthFirstStack.m_Size >= 0 && depthFirstStack.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)depthFirstStack.m_Memory.m_nAllocationCount);
      return 0;
    }
    return 0;
  }
  pDmeBoneMask = (CDmeBoneMask *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: v3[6].m_pAttributes);
  if ( pDmeBoneMask == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v7 = ComputeDmElementIdStr(result: (CUtlString *)&depthFirstStack.m_Memory.m_nAllocationCount, pDmElement: v3);
      v17 = CUtlString::Get(this: v7);
      v8 = ComputeDmElementIdStr(result: &v19, pDmElement: pDmElementa);
      v15 = CUtlString::Get(this: v8);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No Bone Mask\n", v15, v17);
      goto LABEL_8;
    }
    return 0;
  }
  memset(&depthFirstStack, 0, sizeof(depthFirstStack));
  CUtlMemory<IDmFormatUpdater *,int>::Grow(
    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
    num: 1);
  m_pMemory = depthFirstStack.m_Memory.m_pMemory;
  m_Size = depthFirstStack.m_Size + 1;
  v11 = &depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size++];
  depthFirstStack.m_pElements = depthFirstStack.m_Memory.m_pMemory;
  if ( v11 != nullptr )
    *v11 = (CDmeDag *)i;
  while ( m_Size != 0 )
  {
    v12 = m_pMemory[--m_Size];
    depthFirstStack.m_Size = m_Size;
    if ( v12 != nullptr )
    {
      v13 = CDmElementFramework::GetPhase(this: v12) - 1;
      ia = v13;
      if ( v13 >= 0 )
      {
        while ( 1 )
        {
          pDmeSequenceDst = (CDmeSequence *)CDmeDag::GetChild(this: v12, i: v13);
          if ( m_Size >= depthFirstStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
              num: 1);
            m_Size = depthFirstStack.m_Size;
            m_pMemory = depthFirstStack.m_Memory.m_pMemory;
          }
          depthFirstStack.m_Size = ++m_Size;
          depthFirstStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = (CDmeDag *)pDmeSequenceDst;
          if ( --ia < 0 )
            break;
          v13 = ia;
        }
      }
      CDmeBoneMaskCmd::SubApply(
        this: (CDmeBoneMaskCmd *)pDmElementa,
        pDmeChannelsClip: (CDmeTypedLog<Vector> *)pDmeChannelsClipDst,
        pDmeDag: (CDmeTypedLog<Quaternion> *)v12,
        pDmeBoneMask: *(float *)&pDmeBoneMask);
    }
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&depthFirstStack);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2200
// Name: public: virtual bool CDmeAnimationAssemblyCommand::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationAssemblyCommand::IsA(CDmeAnimationAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2230
// Name: public: virtual int CDmeAnimationAssemblyCommand::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationAssemblyCommand::GetInheritanceDepth(
        CDmeAnimationAssemblyCommand *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2310
// Name: public: virtual bool CDmeFixupLoop::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFixupLoop::IsA(CDmeFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFixupLoop::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2350
// Name: public: virtual int CDmeFixupLoop::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFixupLoop::GetInheritanceDepth(CDmeFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFixupLoop::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2410
// Name: protected: virtual void CDmeFixupLoop::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::PerformConstruction(CDmeFixupLoop *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_nStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "startFrame",
                                       type: AT_INT,
                                       pMemory: &this->m_nStartFrame);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004F24E0
// Name: public: virtual bool CDmeSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSubtract::IsA(CDmeSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2520
// Name: public: virtual int CDmeSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSubtract::GetInheritanceDepth(CDmeSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F25F0
// Name: protected: virtual void CDmeSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::PerformConstruction(CDmeSubtract *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_eSequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequence",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eSequence);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eSequence.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eSequence.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004F26E0
// Name: public: virtual bool CDmePreSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePreSubtract::IsA(CDmePreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePreSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2720
// Name: public: virtual int CDmePreSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePreSubtract::GetInheritanceDepth(CDmePreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePreSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2800
// Name: protected: virtual void CDmePreSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmePreSubtract::PerformConstruction(CDmePreSubtract *this)
{
  CDmeSubtract::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004F28A0
// Name: public: virtual bool CDmeRotateTo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRotateTo::IsA(CDmeRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRotateTo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F28E0
// Name: public: virtual int CDmeRotateTo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRotateTo::GetInheritanceDepth(CDmeRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRotateTo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2A90
// Name: public: virtual bool CDmeBoneMaskCmd::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMaskCmd::IsA(CDmeBoneMaskCmd *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMaskCmd::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2AD0
// Name: public: virtual int CDmeBoneMaskCmd::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMaskCmd::GetInheritanceDepth(CDmeBoneMaskCmd *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMaskCmd::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F2C80
// Name: ComputeMergedKeyTimes
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeMergedKeyTimes(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *mergedTimes@<esi>,
        CDmeLog *pDmeLogA,
        CDmeLog *pDmeLogB)
{
  int v3; // ebx
  int v4; // eax
  CDmeLog *v5; // edi
  const DmeTime_t *v6; // eax
  unsigned __int16 v7; // dx
  int *v8; // ecx
  int m_pMemory; // edi
  DmeTime_t *p_m_Data; // ebx
  int m_nAllocationCount; // eax
  DmeTime_t *v12; // ecx
  int v13; // eax
  DmeTime_t *v14; // edi
  unsigned __int16 v15; // ax
  CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl*)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short> > timesTree; // [esp+8h] [ebp-24h] BYREF
  DmeTime_t v17; // [esp+24h] [ebp-8h] BYREF
  int i; // [esp+28h] [ebp-4h]

  v3 = 0;
  v4 = 0;
  mergedTimes[1].m_pMemory = nullptr;
  timesTree.m_LessFunc = (bool (__cdecl *)(const DmeTime_t *, const DmeTime_t *))CDefOps<DmeTime_t>::LessFunc;
  memset(&timesTree.m_Elements, 0, sizeof(timesTree.m_Elements));
  *(_DWORD *)&timesTree.m_Root = 0xFFFF;
  *(_DWORD *)&timesTree.m_FirstFree = -1;
  timesTree.m_pElements = nullptr;
  i = 0;
  while ( 1 )
  {
    v5 = pDmeLogA;
    if ( v4 != 0 )
      v5 = pDmeLogB;
    if ( v5 != nullptr && CDmeLog::GetKeyCount(this: v5) > 0 )
    {
      do
      {
        v6 = v5->GetKeyTime(this: v5, result: &v17, a3: v3);
        CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::InsertIfNotFound(
          this: &timesTree,
          insert: v6);
        ++v3;
      }
      while ( v3 < CDmeLog::GetKeyCount(this: v5) );
    }
    v4 = i + 1;
    i = v4;
    if ( v4 >= 2 )
      break;
    v3 = 0;
  }
  v7 = CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::FirstInorder(this: &timesTree);
  i = v7;
  while ( v7 < timesTree.m_Elements.m_nAllocationCount && v7 <= timesTree.m_LastAlloc.index )
  {
    if ( (`CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_3AF144C = 0x1FFFF;
    }
    v8 = v7 == 0xFFFF
       ? &`CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&timesTree.m_Elements.m_pMemory[v7];
    if ( *(_WORD *)v8 == v7 )
      break;
    m_pMemory = (int)mergedTimes[1].m_pMemory;
    p_m_Data = &timesTree.m_Elements.m_pMemory[v7].m_Data;
    m_nAllocationCount = mergedTimes->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: mergedTimes, num: m_pMemory - m_nAllocationCount + 1);
      v7 = i;
    }
    ++mergedTimes[1].m_pMemory;
    v12 = (DmeTime_t *)mergedTimes->m_pMemory;
    v13 = (int)mergedTimes[1].m_pMemory - m_pMemory - 1;
    mergedTimes[1].m_nAllocationCount = (int)mergedTimes->m_pMemory;
    if ( v13 > 0 )
    {
      _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 4 * v13);
      v7 = i;
    }
    v14 = (DmeTime_t *)&mergedTimes->m_pMemory[m_pMemory];
    if ( v14 != nullptr )
      v14->m_tms = p_m_Data->m_tms;
    v15 = CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::NextInorder(
            this: &timesTree,
            i: v7);
    i = v15;
    v7 = v15;
  }
  CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::RemoveAll(this: &timesTree);
  if ( timesTree.m_Elements.m_nGrowSize >= 0 && timesTree.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: timesTree.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004F2E40
// Name: protected: void CDmeRotateTo::SubApply(class CDmeDag __near *,class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeRotateTo::SubApply(
        CDmeRotateTo *this,
        CDmeTypedLog<Quaternion> *pDmeDag,
        CDmeLog *pDmeChannelsClip,
        bool bZUp)
{
  CDmeDag *v4; // esi
  CDmeChannelsClip *v5; // edi
  CUtlString *v6; // eax
  CUtlString *v7; // eax
  const char *v8; // eax
  CDmeTypedLog<Vector> *v9; // edi
  const Vector *Value; // esi
  const Vector *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // xmm0_4
  float v16; // xmm1_4
  int v17; // xmm0_4
  int v18; // esi
  DmeTime_t *v19; // ebx
  const Quaternion *v20; // eax
  const Vector *v21; // eax
  int v22; // eax
  CDmeTypedLogLayer<Vector> *v23; // esi
  CUtlString *v24; // eax
  const char *v25; // eax
  int v26; // eax
  CDmeTypedLogLayer<Quaternion> *v27; // esi
  CUtlString *v28; // eax
  const char *v29; // eax
  const char *v30; // [esp-4h] [ebp-124h]
  long double v31; // [esp+0h] [ebp-120h]
  long double v32; // [esp+8h] [ebp-118h] OVERLAPPED BYREF
  matrix3x4_t mSrc; // [esp+3Ch] [ebp-E4h] BYREF
  matrix3x4_t mRoot; // [esp+6Ch] [ebp-B4h] BYREF
  Quaternion qTmp; // [esp+9Ch] [ebp-84h] BYREF
  Vector vTmp; // [esp+ACh] [ebp-74h] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > qValues; // [esp+B8h] [ebp-68h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > vValues; // [esp+CCh] [ebp-54h] BYREF
  DmeTime_t dmeTimeEnd; // [esp+E0h] [ebp-40h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > mergedKeyTimes; // [esp+E4h] [ebp-3Ch] BYREF
  int flDeltaAngle; // [esp+F8h] [ebp-28h]
  CUtlString result; // [esp+FCh] [ebp-24h] BYREF
  CUtlString v43; // [esp+10Ch] [ebp-14h] BYREF
  CDmElement *pDmElement; // [esp+11Ch] [ebp-4h]

  v4 = (CDmeDag *)pDmeDag;
  pDmElement = this;
  if ( pDmeDag != nullptr )
  {
    v5 = (CDmeChannelsClip *)pDmeChannelsClip;
    if ( pDmeChannelsClip != nullptr && CDmeDag::GetTransform(this: (CDmeDag *)pDmeDag) != nullptr )
    {
      pDmeChannelsClip = nullptr;
      pDmeDag = nullptr;
      if ( GetDmeChannelsForDag(
             pDmeTranslateLog: (CDmeTypedLog<Vector> **)&pDmeChannelsClip,
             pDmeRotateLog: &pDmeDag,
             pDmeDag: v4,
             pDmeChannelsClip: v5) != 0 )
      {
        v9 = (CDmeTypedLog<Vector> *)pDmeChannelsClip;
        *(float *)&flDeltaAngle = 0.0;
        CDmeLog::GetBeginTime(this: pDmeChannelsClip, result: (DmeTime_t *)&pDmeChannelsClip);
        CDmeLog::GetEndTime(this: v9, result: &dmeTimeEnd);
        Value = CDmeTypedLog<Vector>::GetValue(this: v9, time: (DmeTime_t)pDmeChannelsClip);
        v11 = CDmeTypedLog<Vector>::GetValue(this: v9, time: dmeTimeEnd);
        v12 = v11->x - Value->x;
        v13 = v11->y - Value->y;
        if ( bZUp )
        {
          if ( v12 == 0.0 && v13 == 0.0 )
          {
            v43.m_Storage.m_Memory.m_nAllocationCount = 0;
            v43.m_Storage.m_Memory.m_nGrowSize = flDeltaAngle;
            v43.m_Storage.m_nActualLength = 0;
          }
          else
          {
            __libm_sse2_atan2(y: v31, x: v32);
            v14 = v13 * 57.29577951308232;
            *(float *)&v15 = *(float *)&pDmElement[1].__vftable - v14;
            v43.m_Storage.m_Memory.m_nAllocationCount = 0;
            v43.m_Storage.m_Memory.m_nGrowSize = v15;
            v43.m_Storage.m_nActualLength = 0;
          }
        }
        else
        {
          if ( v12 == 0.0 && (float)(v11->z - Value->z) == 0.0 )
          {
            v17 = flDeltaAngle;
          }
          else
          {
            __libm_sse2_atan2(y: v31, x: v32);
            v16 = v12 * 57.29577951308232;
            *(float *)&v17 = *(float *)&pDmElement[1].__vftable - v16;
          }
          v43.m_Storage.m_Memory.m_nAllocationCount = v17;
          v43.m_Storage.m_Memory.m_nGrowSize = 0;
          v43.m_Storage.m_nActualLength = 0;
        }
        AngleMatrix(angles: (const QAngle *)&v43.m_Storage.m_Memory.m_nAllocationCount, matrix: &mRoot);
        memset(&mergedKeyTimes, 0, sizeof(mergedKeyTimes));
        ComputeMergedKeyTimes(
          mergedTimes: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&mergedKeyTimes,
          pDmeLogA: v9,
          pDmeLogB: pDmeDag);
        v18 = 0;
        memset(&vValues, 0, sizeof(vValues));
        memset(&qValues, 0, sizeof(qValues));
        if ( mergedKeyTimes.m_Size > 0 )
        {
          do
          {
            v19 = &mergedKeyTimes.m_Memory.m_pMemory[v18];
            v20 = CDmeTypedLog<Quaternion>::GetValue(this: pDmeDag, time: (DmeTime_t)v19->m_tms);
            QuaternionAngles(q: v20, angles: (RadianEuler *)&v43.m_Storage.m_Memory.m_nAllocationCount);
            v21 = CDmeTypedLog<Vector>::GetValue(this: v9, time: (DmeTime_t)v19->m_tms);
            AngleMatrix(
              angles: (const RadianEuler *)&v43.m_Storage.m_Memory.m_nAllocationCount,
              position: v21,
              matrix: &mSrc);
            ConcatTransforms(in1: &mRoot, in2: &mSrc, out: (matrix3x4_t *)((char *)&v32 + 4));
            MatrixAngles(matrix: (const matrix3x4_t *)((char *)&v32 + 4), q: &qTmp, pos: &vTmp);
            CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
              this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&vValues,
              elem: vValues.m_Size,
              src: (const QAngle *)&vTmp);
            CUtlVector<VertexLookup_t,CUtlMemory<VertexLookup_t,int>>::InsertBefore(
              this: &qValues,
              elem: qValues.m_Size,
              src: &qTmp);
            ++v18;
          }
          while ( v18 < mergedKeyTimes.m_Size );
        }
        v22 = (int)v9->AddNewLayer(this: v9);
        v23 = (CDmeTypedLogLayer<Vector> *)v22;
        if ( v22 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
               a1: v22,
               a2: CDmeTypedLogLayer<Vector>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Vector>::SetAllKeys(this: v23, times: &mergedKeyTimes, values: &vValues);
          v23->RemoveRedundantKeys_2(this: v23, a2: true);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
        {
          v24 = ComputeDmElementIdStr(&result, pDmElement);
          v25 = CUtlString::Get(this: v24);
          _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Translate Layer\n", v25);
          result.m_Storage.m_nActualLength = 0;
          if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
        }
        v26 = (int)pDmeDag->AddNewLayer(this: pDmeDag);
        v27 = (CDmeTypedLogLayer<Quaternion> *)v26;
        if ( v26 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v26 + 16))(
               a1: v26,
               a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v27, times: &mergedKeyTimes, values: &qValues);
          v27->RemoveRedundantKeys_2(this: v27, a2: true);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
        {
          v28 = ComputeDmElementIdStr(&result, pDmElement);
          v29 = CUtlString::Get(this: v28);
          _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Rotate Layer\n", v29);
          result.m_Storage.m_nActualLength = 0;
          if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
        }
        CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&qValues);
        CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vValues);
        CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&mergedKeyTimes);
      }
      else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
      {
        v6 = ComputeDmElementIdStr(&result, pDmElement: v4);
        v30 = CUtlString::Get(this: v6);
        v7 = ComputeDmElementIdStr(result: &v43, pDmElement);
        v8 = CUtlString::Get(this: v7);
        _LoggingSystem_Log(
          a1: LOG_DME_AAC,
          a2: 3,
          a3: "%s: Couldn't Find Translate & Rotate channels for DmeDag %s\n",
          v8,
          v30);
        v43.m_Storage.m_nActualLength = 0;
        if ( v43.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v43.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v43.m_Storage.m_Memory.m_pMemory);
            v43.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v43.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        result.m_Storage.m_nActualLength = 0;
        if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F32E0
// Name: public: virtual bool CDmeRotateTo::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeRotateTo::Apply(CDmeRotateTo *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  CDmeSequence *v3; // edi
  int v4; // eax
  CDmeTypedLog<Quaternion> *v5; // esi
  CUtlString *v6; // eax
  CUtlString *v7; // eax
  const char *v8; // eax
  int v10; // edi
  CDmeChannelsClip *v11; // ebx
  CDmeTypedLog<Quaternion> *Child; // eax
  CUtlString *v13; // eax
  CUtlString *v14; // eax
  const char *v15; // eax
  const char *v16; // [esp-4h] [ebp-3Ch]
  bool IsZUp; // [esp-4h] [ebp-3Ch]
  const char *v18; // [esp-4h] [ebp-3Ch]
  CUtlString v19; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlString v20; // [esp+1Ch] [ebp-1Ch] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+2Ch] [ebp-Ch] BYREF
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+30h] [ebp-8h] BYREF
  CDmElement *v23; // [esp+34h] [ebp-4h]
  bool pDmElement_3; // [esp+43h] [ebp+Bh]

  v23 = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v20, pDmElement: this);
  pDmElement_3 = ConvertToDmeSequenceAndDmeChannelsClip(
                   pDmElement,
                   sDmElementId: v2,
                   pDmeSequence: &pDmeSequenceDst,
                   pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v20.m_Storage.m_nActualLength = 0;
  if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 && v20.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
  if ( pDmElement_3 )
    return 0;
  v3 = pDmeSequenceDst;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: pDmeSequenceDst->m_eSkeleton.m_Storage.m_Handle);
  v5 = (CDmeTypedLog<Quaternion> *)v4;
  if ( v4 == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v6 = ComputeDmElementIdStr(result: &v19, pDmElement: v3);
      v16 = CUtlString::Get(this: v6);
      v7 = ComputeDmElementIdStr(result: &v20, pDmElement: v23);
      v8 = CUtlString::Get(this: v7);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No Skeleton\n", v8, v16);
      v20.m_Storage.m_nActualLength = 0;
      if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
          v20.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v20.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
    }
    return 0;
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeModel::m_classType.u) == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
    {
      v13 = ComputeDmElementIdStr(result: &v19, pDmElement: v3);
      v18 = CUtlString::Get(this: v13);
      v14 = ComputeDmElementIdStr(result: &v20, pDmElement: v23);
      v15 = CUtlString::Get(this: v14);
      _LoggingSystem_Log(
        a1: LOG_DME_AAC,
        a2: 1,
        a3: "%s: Cannot Determine If Sequence %s Is Y Or Z Up, Assuming Z Up\n",
        v15,
        v18);
      v20.m_Storage.m_nActualLength = 0;
      if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
          v20.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v20.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
    }
    CDmeRotateTo::SubApply(
      this: (CDmeRotateTo *)v23,
      pDmeDag: v5,
      pDmeChannelsClip: (CDmeLog *)pDmeChannelsClipDst,
      bZUp: true);
    return 1;
  }
  v10 = 0;
  if ( CDmElementFramework::GetPhase(this: (CDmeDag *)v5) <= 0 )
    return 1;
  v11 = pDmeChannelsClipDst;
  do
  {
    IsZUp = CDmeModel::IsZUp(this: (CDmeModel *)v5);
    Child = (CDmeTypedLog<Quaternion> *)CDmeDag::GetChild(this: (CDmeDag *)v5, i: v10);
    CDmeRotateTo::SubApply(this: (CDmeRotateTo *)v23, pDmeDag: Child, pDmeChannelsClip: (CDmeLog *)v11, bZUp: IsZUp);
    ++v10;
  }
  while ( v10 < CDmElementFramework::GetPhase(this: (CDmeDag *)v5) );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005EF040
// Name: _dynamic_initializer_for__CDmeAnimationAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationAssemblyCommand::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationAssemblyCommand pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF0A0
// Name: _dynamic_initializer_for__CDmeFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFixupLoop::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFixupLoop pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF100
// Name: _dynamic_initializer_for__CDmeSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF160
// Name: _dynamic_initializer_for__CDmePreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePreSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePreSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePreSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF1C0
// Name: _dynamic_initializer_for__CDmeRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRotateTo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRotateTo::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRotateTo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF220
// Name: _dynamic_initializer_for__CDmeBoneMaskCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMaskCmd::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMaskCmd::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMaskCmd pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F25E0
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3BF0
// Name: _dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationAssemblyCommand::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C00
// Name: _dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFixupLoop::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C10
// Name: _dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C20
// Name: _dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePreSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C30
// Name: _dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRotateTo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C40
// Name: _dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMaskCmd::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4E60
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x005EF070
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF080
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationAssemblyCommand_Helper,
           classname: "DmeAnimationAssemblyCommand",
           pFactory: &g_CDmeAnimationAssemblyCommand_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EF0D0
// Name: _dynamic_initializer_for__g_CDmeFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFixupLoop_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF0E0
// Name: _dynamic_initializer_for__g_CDmeFixupLoop_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFixupLoop_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFixupLoop_Helper,
           classname: "DmeFixupLoop",
           pFactory: &g_CDmeFixupLoop_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EF130
// Name: _dynamic_initializer_for__g_CDmeSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF140
// Name: _dynamic_initializer_for__g_CDmeSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSubtract_Helper,
           classname: "DmeSubtract",
           pFactory: &g_CDmeSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EF190
// Name: _dynamic_initializer_for__g_CDmePreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePreSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF1A0
// Name: _dynamic_initializer_for__g_CDmePreSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePreSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePreSubtract_Helper,
           classname: "DmePreSubtract",
           pFactory: &g_CDmePreSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EF1F0
// Name: _dynamic_initializer_for__g_CDmeRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRotateTo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF200
// Name: _dynamic_initializer_for__g_CDmeRotateTo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRotateTo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRotateTo_Helper,
           classname: "DmeRotateTo",
           pFactory: &g_CDmeRotateTo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EF250
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMaskCmd_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF260
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmd_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMaskCmd_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMaskCmd_Helper,
           classname: "DmeBoneMaskCmd",
           pFactory: &g_CDmeBoneMaskCmd_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F2610
// Name: _dynamic_atexit_destructor_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExitStopper__()
{
  if ( g_bStopOnExit )
  {
    _Warning(a1: "\nPress any key to quit.\n");
    getch();
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F2630
// Name: _dynamic_atexit_destructor_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupFunctions__()
{
  CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::RemoveAll(this: &g_CleanupFunctions);
  if ( g_CleanupFunctions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_CleanupFunctions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CleanupFunctions.m_Memory.m_pMemory);
      g_CleanupFunctions.m_Memory.m_pMemory = nullptr;
    }
    g_CleanupFunctions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F2680
// Name: _CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&buf);
}

//------------------------------------------------------------------------------
// Address: 0x005F2690
// Name: _dynamic_atexit_destructor_for__g_JointedModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_JointedModel__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_JointedModel.m_mergeList);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_JointedModel.m_textCommands);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_JointedModel.m_bonemap);
}

//------------------------------------------------------------------------------
// Address: 0x005F26B0
// Name: _dynamic_atexit_destructor_for__s_Balance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_Balance__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_Balance);
}

//------------------------------------------------------------------------------
// Address: 0x005F26C0
// Name: _dynamic_atexit_destructor_for__s_Speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_Speed__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_Speed);
}

//------------------------------------------------------------------------------
// Address: 0x005F26D0
// Name: _dynamic_atexit_destructor_for__s_UniqueVertices__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_UniqueVertices__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_UniqueVertices);
}

//------------------------------------------------------------------------------
// Address: 0x005F26E0
// Name: _dynamic_atexit_destructor_for__s_UniqueVerticesMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_UniqueVerticesMap__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_UniqueVerticesMap);
}

//------------------------------------------------------------------------------
// Address: 0x005F26F0
// Name: _dynamic_atexit_destructor_for__s_DeltaStates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DeltaStates__()
{
  CUtlVector<DeltaState_t,CUtlMemory<DeltaState_t,int>>::~CUtlVector<DeltaState_t,CUtlMemory<DeltaState_t,int>>(this: &s_DeltaStates);
}

//------------------------------------------------------------------------------
// Address: 0x005F2700
// Name: _dynamic_atexit_destructor_for__g_MtlLib__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MtlLib__()
{
  CUtlVector<MtlInfo_t,CUtlMemory<MtlInfo_t,int>>::~CUtlVector<MtlInfo_t,CUtlMemory<MtlInfo_t,int>>(this: &g_MtlLib);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C50
// Name: _dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFixupLoop_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C60
// Name: _dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C70
// Name: _dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePreSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C80
// Name: _dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRotateTo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C90
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneMaskCmd_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3CA0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationAssemblyCommand_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00518EC0
// Name: protected: virtual void CDmeSubtract::Subtract(class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract(CDmeSubtract *this, Vector *vResult, const Vector *vDst, const Vector *vSrc)
{
  vResult->x = vDst->x - vSrc->x;
  vResult->y = vDst->y - vSrc->y;
  vResult->z = vDst->z - vSrc->z;
}

//------------------------------------------------------------------------------
// Address: 0x00518F00
// Name: protected: virtual void CDmeSubtract::Subtract(class Quaternion __near &,class Quaternion const __near &,class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract(
        CDmeSubtract *this,
        Quaternion *qResult,
        const Quaternion *qDst,
        const Quaternion *qSrc)
{
  QuaternionSM(s: -1.0, p: qSrc, q: qDst, qt: qResult);
}

//------------------------------------------------------------------------------
// Address: 0x00518F30
// Name: protected: virtual void CDmePreSubtract::Subtract(class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePreSubtract::Subtract(
        CDmePreSubtract *this,
        Vector *vResult,
        const Vector *vDst,
        const Vector *vSrc)
{
  vResult->x = vSrc->x - vDst->x;
  vResult->y = vSrc->y - vDst->y;
  vResult->z = vSrc->z - vDst->z;
}

//------------------------------------------------------------------------------
// Address: 0x00518F70
// Name: protected: virtual void CDmePreSubtract::Subtract(class Quaternion __near &,class Quaternion const __near &,class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePreSubtract::Subtract(
        CDmePreSubtract *this,
        Quaternion *qResult,
        const Quaternion *qDst,
        const Quaternion *qSrc)
{
  QuaternionMA(p: qDst, s: -1.0, q: qSrc, qt: qResult);
}

//------------------------------------------------------------------------------
// Address: 0x005194B0
// Name: GetDmeChannelsForDag
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetDmeChannelsForDag(
        CDmeTypedLog<Vector> **pDmeTranslateLog,
        CDmeTypedLog<Quaternion> **pDmeRotateLog,
        CDmeDag *pDmeDag,
        CDmeChannelsClip *pDmeChannelsClip)
{
  CDmeChannelsClip *v5; // esi
  CDmeTransform *Transform; // edi
  int v7; // eax
  int v8; // esi
  CDmeChannel *v9; // esi
  CDmeLog *Log; // eax
  CDmElement *v11; // edi
  CDmeTypedLog<Vector> *v12; // eax
  CUtlString *v13; // eax
  CUtlString *v14; // eax
  CUtlString *v15; // eax
  CUtlString *v16; // ecx
  CDmeTypedLog<Quaternion> *v17; // eax
  CUtlString *v18; // eax
  CUtlString *v19; // eax
  CUtlString *v20; // eax
  CUtlString v22; // [esp+Ch] [ebp-64h] BYREF
  CUtlString v23; // [esp+1Ch] [ebp-54h] BYREF
  CUtlString v24; // [esp+2Ch] [ebp-44h] BYREF
  CUtlString v25; // [esp+3Ch] [ebp-34h] BYREF
  CUtlString v26; // [esp+4Ch] [ebp-24h] BYREF
  CUtlString v27; // [esp+5Ch] [ebp-14h] BYREF
  CDmeTransform *pDmeTransform; // [esp+6Ch] [ebp-4h]
  CDmeTypedLog<Vector> **pDmeTranslateLoga; // [esp+78h] [ebp+8h]

  *pDmeTranslateLog = nullptr;
  *pDmeRotateLog = nullptr;
  if ( pDmeDag == nullptr )
    return 0;
  v5 = pDmeChannelsClip;
  if ( pDmeChannelsClip == nullptr )
    return 0;
  Transform = CDmeDag::GetTransform(this: pDmeDag);
  pDmeTransform = Transform;
  if ( Transform == nullptr )
    return 0;
  if ( pDmeChannelsClip->m_Channels.m_Storage.m_Size != 0 )
  {
    pDmeTranslateLoga = nullptr;
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(CDmeTypedLog<Vector> **)((char *)pDmeTranslateLoga
                                      + (unsigned int)v5->m_Channels.m_Storage.m_Memory.m_pMemory));
      v8 = v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v9 = (CDmeChannel *)(v8 - 4);
        if ( v9 != nullptr && CDmeChannel::GetToElement(this: v9) == Transform )
        {
          Log = CDmeChannel::GetLog(this: v9);
          v11 = Log;
          if ( Log != nullptr )
          {
            v12 = CastElement<CDmeTypedLog<Vector>>(pElement: Log);
            if ( v12 != nullptr )
            {
              if ( *pDmeTranslateLog != nullptr )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) == 0 )
                  goto LABEL_25;
                v13 = ComputeDmElementIdStr(result: &v25, pDmElement: &v9->CDmElement);
                CUtlString::Get(this: v13);
                v14 = ComputeDmElementIdStr(result: &v26, pDmElement: *pDmeTranslateLog);
                CUtlString::Get(this: v14);
                v15 = ComputeDmElementIdStr(result: &v27, pDmElement: pDmeDag);
                CUtlString::Get(this: v15);
                _LoggingSystem_Log(a1: LOG_DME_AAC);
                CUtlString::~CUtlString(this: &v27);
                CUtlString::~CUtlString(this: &v26);
                v16 = &v25;
LABEL_24:
                CUtlString::~CUtlString(this: v16);
                goto LABEL_25;
              }
              *pDmeTranslateLog = v12;
              if ( *pDmeRotateLog != nullptr )
                break;
            }
            else
            {
              v17 = CastElement<CDmeTypedLog<Quaternion>>(pElement: v11);
              if ( v17 == nullptr )
                goto LABEL_25;
              if ( *pDmeRotateLog != nullptr )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) == 0 )
                  goto LABEL_25;
                v18 = ComputeDmElementIdStr(result: &v22, pDmElement: &v9->CDmElement);
                CUtlString::Get(this: v18);
                v19 = ComputeDmElementIdStr(result: &v23, pDmElement: *pDmeRotateLog);
                CUtlString::Get(this: v19);
                v20 = ComputeDmElementIdStr(result: &v24, pDmElement: pDmeDag);
                CUtlString::Get(this: v20);
                _LoggingSystem_Log(a1: LOG_DME_AAC);
                CUtlString::~CUtlString(this: &v24);
                CUtlString::~CUtlString(this: &v23);
                v16 = &v22;
                goto LABEL_24;
              }
              *pDmeRotateLog = v17;
              if ( *pDmeTranslateLog != nullptr )
                goto LABEL_27;
            }
          }
        }
      }
LABEL_25:
      v5 = pDmeChannelsClip;
      ++pDmeTranslateLoga;
      if ( pDmeChannelsClip->m_Channels.m_Storage.m_Size == 0 )
        break;
      Transform = pDmeTransform;
    }
  }
  if ( *pDmeTranslateLog != nullptr )
  {
LABEL_27:
    if ( *pDmeRotateLog != nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0051A070
// Name: ConvertToDmeSequenceAndDmeChannelsClip
// Source: json
//------------------------------------------------------------------------------
char __usercall ConvertToDmeSequenceAndDmeChannelsClip@<al>(
        CDmeSequence *pDmElement@<esi>,
        CUtlString *sDmElementId@<edi>,
        CDmeSequence **pDmeSequence,
        CDmeChannelsClip **pDmeChannelsClip)
{
  CDmeChannelsClip *DmeChannelsClip; // eax
  CUtlString *v6; // eax
  CUtlString v7; // [esp+0h] [ebp-10h] BYREF

  if ( pDmElement == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
    {
      CUtlString::operator char const *(this: sDmElementId);
      _LoggingSystem_Log(a1: LOG_DME_AAC);
    }
    return 0;
  }
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
         a1: pDmElement,
         a2: (CUtlSymbolLarge)CDmeSequence::m_classType.u.m_Id) )
  {
    DmeChannelsClip = CDmeSequence::GetDmeChannelsClip(this: pDmElement);
    if ( DmeChannelsClip != nullptr )
    {
      *pDmeSequence = pDmElement;
      *pDmeChannelsClip = DmeChannelsClip;
      return 1;
    }
    else
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
      {
        v6 = ComputeDmElementIdStr(result: &v7, pDmElement);
        CUtlString::Get(this: v6);
        CUtlString::operator char const *(this: sDmElementId);
        _LoggingSystem_Log(a1: LOG_DME_AAC);
        v7.m_Storage.m_nActualLength = 0;
        if ( v7.m_Storage.m_Memory.m_nGrowSize >= 0 && v7.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7.m_Storage.m_Memory.m_pMemory);
      }
      return 0;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) == 0 )
      return 0;
    CUtlString::operator char const *(this: sDmElementId);
    _LoggingSystem_Log(a1: LOG_DME_AAC);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051A1A0
// Name: protected: void CDmeFixupLoop::Apply<class Vector>(class CDmeTypedLog<class Vector> __near *,class DmeTime_t const __near &,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::Apply<Vector>(
        CDmeFixupLoop *this,
        CDmeTypedLog<Vector> *pDmeTypedLogDst,
        const DmeTime_t *dmeTimeStart,
        const DmeTime_t *dmeTimeEnd)
{
  int v4; // esi
  int v5; // eax
  int m_Size; // eax
  int v7; // edi
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  DmeTime_t *v10; // edi
  const QAngle *KeyValue; // eax
  Vector *v12; // edi
  DmeTime_t *v13; // ebx
  int v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  int v18; // eax
  int v19; // esi
  int v20; // edx
  int m_tms; // ecx
  float v22; // xmm0_4
  float *p_x; // ecx
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  int v27; // ecx
  float v28; // xmm0_4
  float *v29; // ecx
  float v30; // xmm6_4
  float v31; // xmm7_4
  float v32; // xmm0_4
  int v33; // ecx
  float v34; // xmm0_4
  float *v35; // ecx
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  int v39; // ecx
  float v40; // xmm0_4
  float *v41; // ecx
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm0_4
  int v45; // edx
  int v46; // ecx
  float v47; // xmm0_4
  float *v48; // ecx
  float v49; // xmm6_4
  float v50; // xmm7_4
  float v51; // xmm0_4
  int v52; // esi
  int v53; // ecx
  int v54; // edx
  int v55; // ebx
  float v56; // xmm0_4
  float v57; // xmm0_4
  float *v58; // eax
  float v59; // xmm7_4
  int v60; // edi
  float v61; // xmm0_4
  float v62; // xmm0_4
  Vector *v63; // eax
  float v64; // xmm7_4
  int v65; // edi
  float v66; // xmm0_4
  float v67; // xmm0_4
  Vector *v68; // eax
  float v69; // xmm7_4
  int v70; // edi
  float v71; // xmm0_4
  float v72; // xmm0_4
  Vector *v73; // eax
  float v74; // xmm7_4
  int v75; // ebx
  int v76; // edx
  float v77; // xmm0_4
  float v78; // xmm0_4
  float *v79; // eax
  float v80; // xmm7_4
  CDmeLogLayer *v81; // eax
  CDmeTypedLogLayer<Vector> *v82; // esi
  Vector *v83; // eax
  DmeTime_t *v84; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > values; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+20h] [ebp-30h] BYREF
  Vector newValue; // [esp+34h] [ebp-1Ch]
  float v88; // [esp+40h] [ebp-10h] BYREF
  int nKeyIndex; // [esp+44h] [ebp-Ch]
  float flTimeRange; // [esp+48h] [ebp-8h]
  int nKeyCount; // [esp+4Ch] [ebp-4h]
  float flScale; // [esp+5Ch] [ebp+Ch]

  v4 = 0;
  if ( pDmeTypedLogDst != nullptr )
  {
    v5 = dmeTimeEnd->m_tms - dmeTimeStart->m_tms;
    if ( (float)((float)v5 * 0.000099999997) > 0.0 && (float)((float)dmeTimeStart->m_tms * 0.000099999997) <= 0.0 )
    {
      flTimeRange = (float)v5 * 0.000099999997;
      nKeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLogDst);
      if ( nKeyCount > 0 )
      {
        memset(&times, 0, sizeof(times));
        memset(&values, 0, sizeof(values));
        do
        {
          nKeyIndex = (int)pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &v88, a3: v4);
          m_Size = times.m_Size;
          v7 = times.m_Size;
          if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&times,
              num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
            m_Size = times.m_Size;
          }
          m_pMemory = times.m_Memory.m_pMemory;
          times.m_Size = m_Size + 1;
          v9 = m_Size - v7;
          times.m_pElements = times.m_Memory.m_pMemory;
          if ( v9 > 0 )
          {
            _V_memmove(dest: &times.m_Memory.m_pMemory[v7 + 1], src: &times.m_Memory.m_pMemory[v7], count: 4 * v9);
            m_pMemory = times.m_Memory.m_pMemory;
          }
          v10 = &m_pMemory[v7];
          if ( v10 != nullptr )
            v10->m_tms = *(int *)nKeyIndex;
          KeyValue = (const QAngle *)CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&values,
            elem: values.m_Size,
            src: KeyValue);
          ++v4;
        }
        while ( v4 < nKeyCount );
        v12 = values.m_Memory.m_pMemory;
        v13 = times.m_Memory.m_pMemory;
        v14 = nKeyCount;
        v15 = values.m_Memory.m_pMemory[nKeyCount - 1].x - values.m_Memory.m_pMemory->x;
        v16 = values.m_Memory.m_pMemory[nKeyCount - 1].y - values.m_Memory.m_pMemory->y;
        v17 = values.m_Memory.m_pMemory[nKeyCount - 1].z - values.m_Memory.m_pMemory->z;
        if ( (float)((float)dmeTimeStart->m_tms * 0.000099999997) < 0.0 )
        {
          v18 = dmeTimeStart->m_tms + times.m_Memory.m_pMemory[nKeyCount - 1].m_tms;
          v19 = 0;
          if ( nKeyCount >= 4 )
          {
            LODWORD(v88) = nKeyCount - 3;
            v20 = 0;
            do
            {
              m_tms = v13[v19].m_tms;
              if ( m_tms >= v18 )
              {
                LODWORD(v22) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(m_tms - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                p_x = &v12[v20].x;
                v24 = (float)(v22 * v15) + v12[v20].x;
                v25 = (float)(v22 * v16) + v12[v20].y;
                v26 = (float)(v22 * v17) + v12[v20].z;
                *p_x = v24;
                p_x[1] = v25;
                p_x[2] = v26;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v27 = v13[v19 + 1].m_tms;
              if ( v27 >= v18 )
              {
                LODWORD(v28) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v27 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v29 = &v12[v20 + 1].x;
                v30 = (float)(v28 * v15) + *v29;
                v31 = (float)(v28 * v16) + v12[v20 + 1].y;
                v32 = (float)(v28 * v17) + v12[v20 + 1].z;
                *v29 = v30;
                v29[1] = v31;
                v29[2] = v32;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v33 = v13[v19 + 2].m_tms;
              if ( v33 >= v18 )
              {
                LODWORD(v34) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v33 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v35 = &v12[v20 + 2].x;
                v36 = (float)(v34 * v15) + *v35;
                v37 = (float)(v34 * v16) + v12[v20 + 2].y;
                v38 = (float)(v34 * v17) + v12[v20 + 2].z;
                *v35 = v36;
                v35[1] = v37;
                v35[2] = v38;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v39 = v13[v19 + 3].m_tms;
              if ( v39 >= v18 )
              {
                LODWORD(v40) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v39 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v41 = &v12[v20 + 3].x;
                v42 = (float)(v40 * v15) + *v41;
                v43 = (float)(v40 * v16) + v12[v20 + 3].y;
                v44 = (float)(v40 * v17) + v12[v20 + 3].z;
                *v41 = v42;
                v41[1] = v43;
                v41[2] = v44;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v19 += 4;
              v20 += 4;
              nKeyIndex = v19;
            }
            while ( v19 < SLODWORD(v88) );
            v14 = nKeyCount;
          }
          if ( v19 < v14 )
          {
            v45 = v19;
            do
            {
              v46 = v13[v19].m_tms;
              if ( v46 >= v18 )
              {
                LODWORD(v47) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v46 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v48 = &v12[v45].x;
                v49 = (float)(v47 * v15) + v12[v45].x;
                v50 = (float)(v47 * v16) + v12[v45].y;
                v51 = (float)(v47 * v17) + v12[v45].z;
                *v48 = v49;
                v48[1] = v50;
                v48[2] = v51;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              ++v19;
              ++v45;
            }
            while ( v19 < nKeyCount );
          }
        }
        if ( (float)((float)dmeTimeEnd->m_tms * 0.000099999997) > 0.0 )
        {
          v52 = v13->m_tms;
          v53 = 0;
          if ( nKeyCount < 4 )
          {
LABEL_41:
            if ( v53 < nKeyCount )
            {
              v75 = v53;
              while ( 1 )
              {
                v76 = times.m_Memory.m_pMemory[v53].m_tms;
                if ( v76 > dmeTimeEnd->m_tms )
                  break;
                v77 = (float)((float)(v52 + dmeTimeEnd->m_tms - v76) * 0.000099999997) / flTimeRange;
                v78 = (float)((float)(v77 * 3.0) * v77) - (float)((float)((float)(v77 * 2.0) * v77) * v77);
                v79 = &v12[v75].x;
                newValue.x = (float)(v15 * v78) + v12[v75].x;
                newValue.y = (float)(v16 * v78) + v12[v75].y;
                v80 = (float)(v17 * v78) + v12[v75].z;
                ++v53;
                *v79 = newValue.x;
                ++v75;
                v79[1] = newValue.y;
                v79[2] = v80;
                if ( v53 >= nKeyCount )
                  break;
                v12 = values.m_Memory.m_pMemory;
              }
            }
          }
          else
          {
            v54 = 0;
            while ( 1 )
            {
              v55 = v13[v53].m_tms;
              if ( v55 > dmeTimeEnd->m_tms )
                break;
              flScale = 1.0 / flTimeRange;
              v56 = (float)((float)(v52 + dmeTimeEnd->m_tms - v55) * 0.000099999997) * (float)(1.0 / flTimeRange);
              v88 = (float)(v56 * 3.0) * v56;
              v57 = v88 - (float)((float)((float)(v56 * 2.0) * v56) * v56);
              v58 = &v12[v54].x;
              newValue.x = (float)(v15 * v57) + v12[v54].x;
              newValue.y = (float)(v16 * v57) + v12[v54].y;
              v59 = (float)(v17 * v57) + v12[v54].z;
              *v58 = newValue.x;
              v58[1] = newValue.y;
              v58[2] = v59;
              v60 = times.m_Memory.m_pMemory[v53 + 1].m_tms;
              if ( v60 > dmeTimeEnd->m_tms )
                break;
              v61 = (float)((float)(v52 + dmeTimeEnd->m_tms - v60) * 0.000099999997) * flScale;
              v88 = (float)(v61 * 3.0) * v61;
              v62 = v88 - (float)((float)((float)(v61 * 2.0) * v61) * v61);
              v63 = &values.m_Memory.m_pMemory[v54 + 1];
              newValue.x = (float)(v15 * v62) + v63->x;
              newValue.y = (float)(v16 * v62) + values.m_Memory.m_pMemory[v54 + 1].y;
              v64 = (float)(v17 * v62) + values.m_Memory.m_pMemory[v54 + 1].z;
              v63->x = newValue.x;
              v63->y = newValue.y;
              v63->z = v64;
              v65 = times.m_Memory.m_pMemory[v53 + 2].m_tms;
              if ( v65 > dmeTimeEnd->m_tms )
                break;
              v66 = (float)((float)(v52 + dmeTimeEnd->m_tms - v65) * 0.000099999997) * flScale;
              v88 = (float)(v66 * 3.0) * v66;
              v67 = v88 - (float)((float)((float)(v66 * 2.0) * v66) * v66);
              v68 = &values.m_Memory.m_pMemory[v54 + 2];
              newValue.x = (float)(v15 * v67) + v68->x;
              newValue.y = (float)(v16 * v67) + values.m_Memory.m_pMemory[v54 + 2].y;
              v69 = (float)(v17 * v67) + values.m_Memory.m_pMemory[v54 + 2].z;
              v68->x = newValue.x;
              v68->y = newValue.y;
              v68->z = v69;
              v70 = times.m_Memory.m_pMemory[v53 + 3].m_tms;
              if ( v70 > dmeTimeEnd->m_tms )
                break;
              v71 = (float)((float)(v52 + dmeTimeEnd->m_tms - v70) * 0.000099999997) * flScale;
              v88 = (float)(v71 * 3.0) * v71;
              v72 = v88 - (float)((float)((float)(v71 * 2.0) * v71) * v71);
              v73 = &values.m_Memory.m_pMemory[v54 + 3];
              newValue.x = (float)(v15 * v72) + v73->x;
              newValue.y = (float)(v16 * v72) + values.m_Memory.m_pMemory[v54 + 3].y;
              v74 = (float)(v17 * v72) + values.m_Memory.m_pMemory[v54 + 3].z;
              v73->x = newValue.x;
              v73->y = newValue.y;
              v73->z = v74;
              v12 = values.m_Memory.m_pMemory;
              v53 += 4;
              v54 += 4;
              if ( v53 >= nKeyCount - 3 )
                goto LABEL_41;
              v13 = times.m_Memory.m_pMemory;
            }
          }
        }
        v81 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
        v82 = (CDmeTypedLogLayer<Vector> *)v81;
        if ( v81 != nullptr && v81->IsA(this: v81, a2: CDmeTypedLogLayer<Vector>::m_classType) )
          CDmeTypedLogLayer<Vector>::SetAllKeys(this: v82, &times, &values);
        v83 = values.m_Memory.m_pMemory;
        values.m_Size = 0;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( values.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
            v83 = nullptr;
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        values.m_pElements = v83;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v83 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v83);
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        v84 = times.m_Memory.m_pMemory;
        times.m_Size = 0;
        if ( times.m_Memory.m_nGrowSize >= 0 )
        {
          if ( times.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
            v84 = nullptr;
            times.m_Memory.m_pMemory = nullptr;
          }
          times.m_Memory.m_nAllocationCount = 0;
        }
        times.m_pElements = v84;
        if ( times.m_Memory.m_nGrowSize >= 0 && v84 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v84);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051AA50
// Name: protected: void CDmeFixupLoop::Apply<class Quaternion>(class CDmeTypedLog<class Quaternion> __near *,class DmeTime_t const __near &,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::Apply<Quaternion>(
        CDmeFixupLoop *this,
        CDmeTypedLog<Quaternion> *pDmeTypedLogDst,
        const DmeTime_t *dmeTimeStart,
        const DmeTime_t *dmeTimeEnd)
{
  CDmeTypedLog<Quaternion> *v4; // esi
  int v5; // edi
  int v6; // eax
  int KeyCount; // ebx
  int m_Size; // eax
  int v9; // esi
  DmeTime_t *m_pMemory; // ecx
  int v11; // eax
  DmeTime_t *v12; // esi
  const Quaternion *KeyValue; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // esi
  int m_tms; // eax
  float v18; // xmm0_4
  int v19; // esi
  int v20; // ecx
  float v21; // xmm0_4
  int v22; // eax
  CDmeTypedLogLayer<Quaternion> *v23; // esi
  Quaternion *v24; // eax
  DmeTime_t *v25; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > values; // [esp+24h] [ebp-54h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+38h] [ebp-40h] BYREF
  Quaternion delta; // [esp+4Ch] [ebp-2Ch] BYREF
  Quaternion newValue; // [esp+5Ch] [ebp-1Ch] BYREF
  DmeTime_t v30; // [esp+6Ch] [ebp-Ch] BYREF
  DmeTime_t *v31; // [esp+70h] [ebp-8h]
  float flTimeRange; // [esp+74h] [ebp-4h]
  DmeTime_t dmeTimeBegin; // [esp+84h] [ebp+Ch]
  int dmeTimeBegina; // [esp+84h] [ebp+Ch]

  v4 = pDmeTypedLogDst;
  v5 = 0;
  if ( pDmeTypedLogDst != nullptr )
  {
    v6 = dmeTimeEnd->m_tms - dmeTimeStart->m_tms;
    if ( (float)((float)v6 * 0.000099999997) > 0.0 && (float)((float)dmeTimeStart->m_tms * 0.000099999997) <= 0.0 )
    {
      flTimeRange = (float)v6 * 0.000099999997;
      KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLogDst);
      if ( KeyCount > 0 )
      {
        memset(&times, 0, sizeof(times));
        memset(&values, 0, sizeof(values));
        do
        {
          v31 = v4->GetKeyTime(this: v4, result: &v30, a3: v5);
          m_Size = times.m_Size;
          v9 = times.m_Size;
          if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&times,
              num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
            m_Size = times.m_Size;
          }
          m_pMemory = times.m_Memory.m_pMemory;
          times.m_Size = m_Size + 1;
          v11 = m_Size - v9;
          times.m_pElements = times.m_Memory.m_pMemory;
          if ( v11 > 0 )
          {
            _V_memmove(dest: &times.m_Memory.m_pMemory[v9 + 1], src: &times.m_Memory.m_pMemory[v9], count: 4 * v11);
            m_pMemory = times.m_Memory.m_pMemory;
          }
          v12 = &m_pMemory[v9];
          if ( v12 != nullptr )
            v12->m_tms = v31->m_tms;
          KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v5);
          CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
            this: &values,
            elem: values.m_Size,
            src: KeyValue);
          v4 = pDmeTypedLogDst;
          ++v5;
        }
        while ( v5 < KeyCount );
        v14 = 0;
        QuaternionMA(p: &values.m_Memory.m_pMemory[KeyCount - 1], s: -1.0, q: values.m_Memory.m_pMemory, qt: &delta);
        if ( (float)((float)dmeTimeStart->m_tms * 0.000099999997) < 0.0 )
        {
          v15 = dmeTimeStart->m_tms + times.m_Memory.m_pMemory[KeyCount - 1].m_tms;
          dmeTimeBegin.m_tms = v15;
          v16 = 0;
          do
          {
            m_tms = times.m_Memory.m_pMemory[v14].m_tms;
            if ( m_tms >= v15 )
            {
              v18 = (float)((float)(m_tms - v15) * 0.000099999997) / flTimeRange;
              QuaternionSM(
                s: COERCE_FLOAT(
                  COERCE_UNSIGNED_INT((float)((float)(v18 * 3.0) * v18) - (float)((float)((float)(v18 * 2.0) * v18) * v18))
                ^ _mask__NegFloat_),
                p: &delta,
                q: &values.m_Memory.m_pMemory[v16],
                qt: &newValue);
              v15 = dmeTimeBegin.m_tms;
              values.m_Memory.m_pMemory[v16] = newValue;
            }
            ++v14;
            ++v16;
          }
          while ( v14 < KeyCount );
          v4 = pDmeTypedLogDst;
          v14 = 0;
        }
        if ( (float)((float)dmeTimeEnd->m_tms * 0.000099999997) > 0.0 )
        {
          dmeTimeBegina = times.m_Memory.m_pMemory->m_tms;
          v19 = 0;
          do
          {
            v20 = times.m_Memory.m_pMemory[v14].m_tms;
            if ( v20 > dmeTimeEnd->m_tms )
              break;
            v21 = (float)((float)(dmeTimeBegina + dmeTimeEnd->m_tms - v20) * 0.000099999997) / flTimeRange;
            QuaternionSM(
              s: (float)((float)(v21 * 3.0) * v21) - (float)((float)((float)(v21 * 2.0) * v21) * v21),
              p: &delta,
              q: &values.m_Memory.m_pMemory[v19],
              qt: &newValue);
            values.m_Memory.m_pMemory[v19] = newValue;
            ++v14;
            ++v19;
          }
          while ( v14 < KeyCount );
          v4 = pDmeTypedLogDst;
        }
        v22 = (int)v4->AddNewLayer(this: v4);
        v23 = (CDmeTypedLogLayer<Quaternion> *)v22;
        if ( v22 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
               a1: v22,
               a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v23, &times, &values);
        }
        v24 = values.m_Memory.m_pMemory;
        values.m_Size = 0;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( values.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
            v24 = nullptr;
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        values.m_pElements = v24;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v24 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        v25 = times.m_Memory.m_pMemory;
        times.m_Size = 0;
        if ( times.m_Memory.m_nGrowSize >= 0 )
        {
          if ( times.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
            v25 = nullptr;
            times.m_Memory.m_pMemory = nullptr;
          }
          times.m_Memory.m_nAllocationCount = 0;
        }
        times.m_pElements = v25;
        if ( times.m_Memory.m_nGrowSize >= 0 && v25 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051AE10
// Name: protected: void CDmeSubtract::Subtract<class Vector>(class CDmeTypedLog<class Vector> __near *,class CDmeTypedLog<class Vector> const __near *,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract<Vector>(
        CDmeSubtract *this,
        CDmeTypedLog<Vector> *pDmeTypedLogDst,
        CDmeTypedLog<Vector> *pDmeTypedLogSrc,
        const DmeTime_t *dmeTimeSrc)
{
  int v4; // ebx
  int m_Size; // eax
  int v6; // esi
  DmeTime_t *m_pMemory; // ecx
  int v8; // eax
  DmeTime_t *v9; // eax
  CDmeSubtract_vtbl *v10; // esi
  const Vector *KeyValue; // eax
  int v12; // eax
  int v13; // esi
  Vector *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  CDmeLogLayer *v17; // eax
  CDmeTypedLogLayer<Vector> *v18; // esi
  Vector *v19; // eax
  DmeTime_t *v20; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > values; // [esp+20h] [ebp-30h] BYREF
  Vector valueDst; // [esp+34h] [ebp-1Ch] BYREF
  Vector valueSrc; // [esp+40h] [ebp-10h] BYREF
  CDmeSubtract *v25; // [esp+4Ch] [ebp-4h]

  v25 = this;
  v4 = 0;
  valueSrc = *CDmeTypedLog<Vector>::GetValue(this: pDmeTypedLogSrc, time: (DmeTime_t)dmeTimeSrc->m_tms);
  memset(&times, 0, sizeof(times));
  memset(&values, 0, sizeof(values));
  if ( CDmeLog::GetKeyCount(this: pDmeTypedLogDst) > 0 )
  {
    do
    {
      dmeTimeSrc = pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &pDmeTypedLogSrc, a3: v4);
      m_Size = times.m_Size;
      v6 = times.m_Size;
      if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&times,
          num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
        m_Size = times.m_Size;
      }
      m_pMemory = times.m_Memory.m_pMemory;
      times.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      times.m_pElements = times.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &times.m_Memory.m_pMemory[v6 + 1], src: &times.m_Memory.m_pMemory[v6], count: 4 * v8);
        m_pMemory = times.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_tms = dmeTimeSrc->m_tms;
      v10 = v25->__vftable;
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
      v10->Subtract_2(this: v25, a2: &valueDst, a3: KeyValue, a4: &valueSrc);
      v12 = values.m_Size;
      v13 = values.m_Size;
      if ( values.m_Size + 1 > values.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&values,
          num: values.m_Size - values.m_Memory.m_nAllocationCount + 1);
        v12 = values.m_Size;
      }
      v14 = values.m_Memory.m_pMemory;
      values.m_Size = v12 + 1;
      v15 = v12 - v13;
      values.m_pElements = values.m_Memory.m_pMemory;
      if ( v15 > 0 )
      {
        _V_memmove(dest: &values.m_Memory.m_pMemory[v13 + 1], src: &values.m_Memory.m_pMemory[v13], count: 12 * v15);
        v14 = values.m_Memory.m_pMemory;
      }
      v16 = &v14[v13];
      if ( v16 != nullptr )
        *v16 = valueDst;
      ++v4;
    }
    while ( v4 < CDmeLog::GetKeyCount(this: pDmeTypedLogDst) );
  }
  v17 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
  v18 = (CDmeTypedLogLayer<Vector> *)v17;
  if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmeTypedLogLayer<Vector>::m_classType) )
    CDmeTypedLogLayer<Vector>::SetAllKeys(this: v18, &times, &values);
  v19 = values.m_Memory.m_pMemory;
  values.m_Size = 0;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( values.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
      v19 = nullptr;
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  values.m_pElements = v19;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  v20 = times.m_Memory.m_pMemory;
  times.m_Size = 0;
  if ( times.m_Memory.m_nGrowSize >= 0 )
  {
    if ( times.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
      v20 = nullptr;
      times.m_Memory.m_pMemory = nullptr;
    }
    times.m_Memory.m_nAllocationCount = 0;
  }
  times.m_pElements = v20;
  if ( times.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x0051B040
// Name: protected: void CDmeSubtract::Subtract<class Quaternion>(class CDmeTypedLog<class Quaternion> __near *,class CDmeTypedLog<class Quaternion> const __near *,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract<Quaternion>(
        CDmeSubtract *this,
        CDmeTypedLog<Quaternion> *pDmeTypedLogDst,
        CDmeTypedLog<Quaternion> *pDmeTypedLogSrc,
        const DmeTime_t *dmeTimeSrc)
{
  int v4; // ebx
  int m_Size; // eax
  int v6; // esi
  DmeTime_t *m_pMemory; // ecx
  int v8; // eax
  DmeTime_t *v9; // eax
  CDmeSubtract_vtbl *v10; // esi
  const Quaternion *KeyValue; // eax
  int v12; // eax
  int v13; // esi
  Quaternion *v14; // ecx
  int v15; // eax
  Quaternion *v16; // esi
  CDmeLogLayer *v17; // eax
  CDmeTypedLogLayer<Quaternion> *v18; // esi
  Quaternion *v19; // eax
  DmeTime_t *v20; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > values; // [esp+20h] [ebp-38h] BYREF
  Quaternion valueDst; // [esp+34h] [ebp-24h] BYREF
  Quaternion valueSrc; // [esp+44h] [ebp-14h] BYREF
  CDmeSubtract *v25; // [esp+54h] [ebp-4h]

  v25 = this;
  v4 = 0;
  valueSrc = *CDmeTypedLog<Quaternion>::GetValue(this: pDmeTypedLogSrc, time: (DmeTime_t)dmeTimeSrc->m_tms);
  memset(&times, 0, sizeof(times));
  memset(&values, 0, sizeof(values));
  if ( CDmeLog::GetKeyCount(this: pDmeTypedLogDst) > 0 )
  {
    do
    {
      dmeTimeSrc = pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &pDmeTypedLogSrc, a3: v4);
      m_Size = times.m_Size;
      v6 = times.m_Size;
      if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&times,
          num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
        m_Size = times.m_Size;
      }
      m_pMemory = times.m_Memory.m_pMemory;
      times.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      times.m_pElements = times.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &times.m_Memory.m_pMemory[v6 + 1], src: &times.m_Memory.m_pMemory[v6], count: 4 * v8);
        m_pMemory = times.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_tms = dmeTimeSrc->m_tms;
      v10 = v25->__vftable;
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
      v10->Subtract(this: v25, a2: &valueDst, a3: KeyValue, a4: &valueSrc);
      v12 = values.m_Size;
      v13 = values.m_Size;
      if ( values.m_Size + 1 > values.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&values,
          num: values.m_Size - values.m_Memory.m_nAllocationCount + 1);
        v12 = values.m_Size;
      }
      v14 = values.m_Memory.m_pMemory;
      values.m_Size = v12 + 1;
      v15 = v12 - v13;
      values.m_pElements = values.m_Memory.m_pMemory;
      if ( v15 > 0 )
      {
        _V_memmove(dest: &values.m_Memory.m_pMemory[v13 + 1], src: &values.m_Memory.m_pMemory[v13], count: 16 * v15);
        v14 = values.m_Memory.m_pMemory;
      }
      v16 = &v14[v13];
      if ( v16 != nullptr )
        *v16 = valueDst;
      ++v4;
    }
    while ( v4 < CDmeLog::GetKeyCount(this: pDmeTypedLogDst) );
  }
  v17 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
  v18 = (CDmeTypedLogLayer<Quaternion> *)v17;
  if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmeTypedLogLayer<Quaternion>::m_classType) )
    CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v18, &times, &values);
  v19 = values.m_Memory.m_pMemory;
  values.m_Size = 0;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( values.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
      v19 = nullptr;
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  values.m_pElements = v19;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  v20 = times.m_Memory.m_pMemory;
  times.m_Size = 0;
  if ( times.m_Memory.m_nGrowSize >= 0 )
  {
    if ( times.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
      v20 = nullptr;
      times.m_Memory.m_pMemory = nullptr;
    }
    times.m_Memory.m_nAllocationCount = 0;
  }
  times.m_pElements = v20;
  if ( times.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x0051B270
// Name: GetAllKeys_Vector_
// Source: json
//------------------------------------------------------------------------------
void __usercall GetAllKeys_Vector_(
        CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *keyTimes@<edi>,
        CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *keyValues@<esi>,
        CDmeTypedLog<Vector> *pDmeTypedLog)
{
  CDmeTypedLog<Vector> *v3; // ebx
  int KeyCount; // eax
  int v5; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  DmeTime_t *v10; // ebx
  const Vector *KeyValue; // eax
  int v12; // ebx
  int v13; // eax
  Vector *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  int *v17; // eoff
  DmeTime_t v18; // [esp+4h] [ebp-10h] BYREF
  int *v19; // [esp+8h] [ebp-Ch]
  int nKeyCount; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v3 = pDmeTypedLog;
  keyTimes->m_Size = 0;
  keyValues->m_Storage.m_Size = 0;
  KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLog);
  nKeyCount = KeyCount;
  if ( KeyCount > 0 )
  {
    CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int>>::EnsureCapacity(
      this: keyTimes,
      num: KeyCount);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(this: keyValues, num: nKeyCount);
    i = 0;
    while ( 1 )
    {
      v5 = (int)v3->GetKeyTime(this: v3, result: &v18, a3: i);
      m_Size = keyTimes->m_Size;
      v19 = (int *)v5;
      m_nAllocationCount = keyTimes->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)keyTimes,
          num: m_Size - m_nAllocationCount + 1);
      ++keyTimes->m_Size;
      m_pMemory = (DmeTime_t *)keyTimes->m_Memory.m_pMemory;
      v9 = keyTimes->m_Size - m_Size - 1;
      keyTimes->m_pElements = keyTimes->m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v10 = (DmeTime_t *)&keyTimes->m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        v10->m_tms = *v19;
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLog, nKeyIndex: i);
      v12 = keyValues->m_Storage.m_Size;
      v19 = (int *)KeyValue;
      v13 = keyValues->m_Storage.m_Memory.m_nAllocationCount;
      if ( v12 + 1 > v13 )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)keyValues,
          num: v12 - v13 + 1);
      ++keyValues->m_Storage.m_Size;
      v14 = (Vector *)keyValues->m_Storage.m_Memory.m_pMemory;
      v15 = keyValues->m_Storage.m_Size - v12 - 1;
      keyValues->m_Storage.m_pElements = keyValues->m_Storage.m_Memory.m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 12 * v15);
      v16 = (Vector *)&keyValues->m_Storage.m_Memory.m_pMemory[v12];
      if ( v16 != nullptr )
      {
        v17 = v19;
        *(_QWORD *)&v16->x = *(_QWORD *)v19;
        LODWORD(v16->z) = v17[2];
      }
      if ( ++i >= nKeyCount )
        break;
      v3 = pDmeTypedLog;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051B3C0
// Name: GetAllKeys_Quaternion_
// Source: json
//------------------------------------------------------------------------------
void __usercall GetAllKeys_Quaternion_(
        CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *keyTimes@<esi>,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *keyValues,
        CDmeTypedLog<Quaternion> *pDmeTypedLog)
{
  CDmeTypedLog<Quaternion> *v4; // edi
  int KeyCount; // eax
  int v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmeTime_t *m_pMemory; // ecx
  int v10; // eax
  DmeTime_t *v11; // edi
  const Quaternion *KeyValue; // eax
  int v13; // edi
  int v14; // eax
  Quaternion *v15; // ecx
  int v16; // eax
  Quaternion *v17; // edi
  int *v18; // eax
  DmeTime_t v19; // [esp+8h] [ebp-Ch] BYREF
  int *v20; // [esp+Ch] [ebp-8h]
  int nKeyCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v4 = pDmeTypedLog;
  keyTimes->m_Size = 0;
  keyValues->m_Size = 0;
  KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLog);
  nKeyCount = KeyCount;
  if ( KeyCount > 0 )
  {
    CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int>>::EnsureCapacity(
      this: keyTimes,
      num: KeyCount);
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(this: keyValues, num: nKeyCount);
    i = 0;
    while ( 1 )
    {
      v6 = (int)v4->GetKeyTime(this: v4, result: &v19, a3: i);
      m_Size = keyTimes->m_Size;
      v20 = (int *)v6;
      m_nAllocationCount = keyTimes->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)keyTimes,
          num: m_Size - m_nAllocationCount + 1);
      ++keyTimes->m_Size;
      m_pMemory = (DmeTime_t *)keyTimes->m_Memory.m_pMemory;
      v10 = keyTimes->m_Size - m_Size - 1;
      keyTimes->m_pElements = keyTimes->m_Memory.m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = (DmeTime_t *)&keyTimes->m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        v11->m_tms = *v20;
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLog, nKeyIndex: i);
      v13 = keyValues->m_Size;
      v20 = (int *)KeyValue;
      v14 = keyValues->m_Memory.m_nAllocationCount;
      if ( v13 + 1 > v14 )
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)keyValues,
          num: v13 - v14 + 1);
      ++keyValues->m_Size;
      v15 = (Quaternion *)keyValues->m_Memory.m_pMemory;
      v16 = keyValues->m_Size - v13 - 1;
      keyValues->m_pElements = keyValues->m_Memory.m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &v15[v13 + 1], src: &v15[v13], count: 16 * v16);
      v17 = (Quaternion *)&keyValues->m_Memory.m_pMemory[v13];
      if ( v17 != nullptr )
      {
        v18 = v20;
        *(_QWORD *)&v17->x = *(_QWORD *)v20;
        *(_QWORD *)&v17->z = *((_QWORD *)v18 + 1);
      }
      if ( ++i >= nKeyCount )
        break;
      v4 = pDmeTypedLog;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051B580
// Name: public: virtual bool CDmeFixupLoop::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeFixupLoop::Apply(CDmeFixupLoop *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  char *v3; // ecx
  CDmeSequence *v5; // esi
  char *v6; // ecx
  CDmeChannelsClip *FrameCount; // eax
  int m_Storage; // esi
  int v9; // ecx
  int i; // edi
  int v11; // eax
  int v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v14; // esi
  CUtlString *v15; // eax
  CUtlString *v16; // eax
  char *v17; // [esp-8h] [ebp-4Ch] BYREF
  int TypeString; // [esp-4h] [ebp-48h]
  CUtlString v19; // [esp+Ch] [ebp-38h] BYREF
  CUtlString v20; // [esp+1Ch] [ebp-28h] BYREF
  DmeTime_t nStartTime; // [esp+2Ch] [ebp-18h] BYREF
  DmeTime_t nEndTime; // [esp+30h] [ebp-14h] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+34h] [ebp-10h] BYREF
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+38h] [ebp-Ch] BYREF
  CDmeFixupLoop *v25; // [esp+3Ch] [ebp-8h]
  DmeFramerate_t dmeFrameRateDst; // [esp+40h] [ebp-4h] BYREF
  bool pDmElement_3; // [esp+4Fh] [ebp+Bh]

  v25 = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v19, pDmElement: this);
  pDmElement_3 = ConvertToDmeSequenceAndDmeChannelsClip(
                   pDmElement,
                   sDmElementId: v2,
                   pDmeSequence: &pDmeSequenceDst,
                   pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v19.m_Storage.m_nActualLength = 0;
  if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
  if ( pDmElement_3 )
    return 0;
  TypeString = 0;
  v17 = v3;
  DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v17, fps: 0x1Eu);
  v5 = pDmeSequenceDst;
  CDmeSequence::GetFrameRate(
    this: pDmeSequenceDst,
    result: &dmeFrameRateDst,
    fallbackFrameRate: (DmeFramerate_t)v17,
    bForceFallback: TypeString);
  TypeString = 0;
  v17 = v6;
  DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v17, fps: 0x1Eu);
  FrameCount = CDmeSequence::GetFrameCount(this: v5, fallbackFrameRate: (DmeFramerate_t)v17, bForceFallback: TypeString);
  m_Storage = v25->m_nEndFrame.m_Storage;
  v9 = v25->m_nStartFrame.m_Storage;
  if ( m_Storage - v9 > (int)FrameCount )
  {
    m_Storage = (int)FrameCount + v9;
    if ( (int)FrameCount + v9 < 0 )
    {
      m_Storage = 0;
      v9 = 1 - (_DWORD)FrameCount;
    }
  }
  DmeTime_t::DmeTime_t(this: &nStartTime, frame: v9, framerate: *(_DWORD *)&dmeFrameRateDst);
  DmeTime_t::DmeTime_t(this: &nEndTime, frame: m_Storage, framerate: *(_DWORD *)&dmeFrameRateDst);
  for ( i = 0; i < pDmeChannelsClipDst->m_Channels.m_Storage.m_Size; ++i )
  {
    v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: pDmeChannelsClipDst->m_Channels.m_Storage.m_Memory.m_pMemory[i]);
    v12 = v11;
    if ( v11 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
           a1: v11,
           a2: CDmeChannel::m_classType.u) != 0
      && v12 != 4 )
    {
      Log = CDmeChannel::GetLog(this: (CDmeChannel *)(v12 - 4));
      v14 = (CDmeTypedLog<Vector> *)Log;
      if ( Log != nullptr )
      {
        if ( Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) )
        {
          CDmeFixupLoop::Apply<Vector>(
            this: v25,
            pDmeTypedLogDst: v14,
            dmeTimeStart: &nStartTime,
            dmeTimeEnd: &nEndTime);
        }
        else if ( v14->IsA(this: v14, a2: CDmeTypedLog<Quaternion>::m_classType) )
        {
          CDmeFixupLoop::Apply<Quaternion>(
            this: v25,
            pDmeTypedLogDst: (CDmeTypedLog<Quaternion> *)v14,
            dmeTimeStart: &nStartTime,
            dmeTimeEnd: &nEndTime);
        }
        else
        {
          TypeString = 1;
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
          {
            TypeString = (int)CDmElement::GetTypeString(this: v14);
            v15 = ComputeDmElementIdStr(result: &v19, pDmElement: pDmeSequenceDst);
            v17 = CUtlString::Get(this: v15);
            v16 = ComputeDmElementIdStr(result: &v20, pDmElement: v25);
            CUtlString::Get(this: v16);
            _LoggingSystem_Log(a1: LOG_DME_AAC);
            v20.m_Storage.m_nActualLength = 0;
            if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
                v20.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v20.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            v19.m_Storage.m_nActualLength = 0;
            if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v19.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
                v19.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v19.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051B810
// Name: public: virtual bool CDmeSubtract::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSubtract::Apply(CDmeSubtract *this, float pDmElement)
{
  CUtlString *v3; // edi
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeSequence *v6; // esi
  CUtlString *v7; // edi
  unsigned int v8; // ecx
  CDmeChannelsClip *v9; // edi
  DmeTime_t *StartTime; // eax
  float v11; // xmm0_4
  CUtlString *v12; // eax
  CUtlString *v13; // eax
  DmeTime_t *EndTime; // eax
  float v15; // xmm0_4
  CUtlString *v16; // eax
  CUtlString *v17; // eax
  CDmeChannelsClip *v18; // eax
  int v19; // edi
  int v20; // eax
  int v21; // esi
  int v22; // ebx
  CDmeLog *Log; // eax
  CDmeLog *v24; // esi
  char *v25; // ebx
  CDmeTypedLog<Vector> *v26; // edi
  CDmeTypedLog<Quaternion> *v27; // ebx
  int v28; // eax
  int v29; // esi
  CDmeChannel *v30; // esi
  const char *m_pAsString; // eax
  CDmeTypedLog<Vector> *v32; // esi
  CUtlString *v33; // eax
  CUtlString *v34; // eax
  double v35; // [esp+28h] [ebp-58h] BYREF
  CUtlString v36; // [esp+3Ch] [ebp-44h] BYREF
  CUtlString v37; // [esp+4Ch] [ebp-34h] BYREF
  DmeTime_t v38; // [esp+5Ch] [ebp-24h] BYREF
  int i; // [esp+60h] [ebp-20h]
  char *s1; // [esp+64h] [ebp-1Ch]
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+68h] [ebp-18h] BYREF
  CDmeSubtract *v42; // [esp+6Ch] [ebp-14h]
  DmeFramerate_t dmeFrameRateSrc; // [esp+70h] [ebp-10h] BYREF
  int j; // [esp+74h] [ebp-Ch] BYREF
  CDmeChannelsClip *pDmeChannelsClipSrc; // [esp+78h] [ebp-8h] BYREF
  DmeTime_t dmeTimeSrc; // [esp+7Ch] [ebp-4h] BYREF

  v42 = this;
  pDmeChannelsClipDst = nullptr;
  v3 = ComputeDmElementIdStr(result: &v36, pDmElement: this);
  HIBYTE(pDmElement) = ConvertToDmeSequenceAndDmeChannelsClip(
                         pDmElement: (CDmeSequence *)LODWORD(pDmElement),
                         sDmElementId: v3,
                         pDmeSequence: (CDmeSequence **)&pDmElement,
                         pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v36.m_Storage.m_nActualLength = 0;
  if ( v36.m_Storage.m_Memory.m_nGrowSize >= 0 && v36.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v36.m_Storage.m_Memory.m_pMemory);
  if ( HIBYTE(pDmElement) == 0 )
  {
    v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    HIDWORD(v35) = this->m_eSequence.m_Storage.m_Handle;
    j = 0;
    pDmeChannelsClipSrc = nullptr;
    v6 = (CDmeSequence *)((int (__thiscall *)(_DWORD, _DWORD))v5)(
                           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                           a2: HIDWORD(v35));
    v7 = ComputeDmElementIdStr(result: &v36, pDmElement: this);
    HIBYTE(pDmElement) = ConvertToDmeSequenceAndDmeChannelsClip(
                           pDmElement: v6,
                           sDmElementId: v7,
                           pDmeSequence: (CDmeSequence **)&j,
                           pDmeChannelsClip: &pDmeChannelsClipSrc) == 0;
    v36.m_Storage.m_nActualLength = 0;
    if ( v36.m_Storage.m_Memory.m_nGrowSize >= 0 && v36.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v36.m_Storage.m_Memory.m_pMemory);
    if ( HIBYTE(pDmElement) == 0 )
    {
      *(_QWORD *)&v35 = v8;
      DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v35, fps: 0x1Eu);
      CDmeSequence::GetFrameRate(
        this: (CDmeSequence *)j,
        result: &dmeFrameRateSrc,
        fallbackFrameRate: LODWORD(v35),
        bForceFallback: SHIDWORD(v35));
      DmeTime_t::DmeTime_t(this: &dmeTimeSrc, frame: this->m_nFrame.m_Storage, framerate: *(_DWORD *)&dmeFrameRateSrc);
      v9 = pDmeChannelsClipSrc;
      StartTime = CDmeClip::GetStartTime(this: pDmeChannelsClipSrc, result: (DmeTime_t *)&pDmElement);
      if ( dmeTimeSrc.m_tms < StartTime->m_tms )
      {
        HIDWORD(v35) = 1;
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
        {
          v11 = (float)CDmeClip::GetStartTime(this: v9, result: &v38)->m_tms * 0.000099999997;
          pDmElement = (float)dmeTimeSrc.m_tms * 0.000099999997;
          v35 = v11;
          v12 = ComputeDmElementIdStr(result: &v36, pDmElement: (const CDmElement *)j);
          CUtlString::Get(this: v12);
          DmeFramerate_t::GetFramesPerSecond(this: &dmeFrameRateSrc);
          v13 = ComputeDmElementIdStr(result: &v37, pDmElement: this);
          CUtlString::Get(this: v13);
          _LoggingSystem_Log(a1: LOG_DME_AAC);
          v37.m_Storage.m_nActualLength = 0;
          if ( v37.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v37.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v37.m_Storage.m_Memory.m_pMemory);
              v37.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v37.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v36.m_Storage.m_nActualLength = 0;
          if ( v36.m_Storage.m_Memory.m_nGrowSize >= 0 && v36.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v36.m_Storage.m_Memory.m_pMemory);
        }
      }
      EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&pDmElement);
      if ( dmeTimeSrc.m_tms > EndTime->m_tms )
      {
        HIDWORD(v35) = 1;
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
        {
          v15 = (float)CDmeClip::GetEndTime(this: v9, result: &v38)->m_tms * 0.000099999997;
          pDmElement = (float)dmeTimeSrc.m_tms * 0.000099999997;
          v35 = v15;
          v16 = ComputeDmElementIdStr(result: &v36, pDmElement: (const CDmElement *)j);
          CUtlString::Get(this: v16);
          DmeFramerate_t::GetFramesPerSecond(this: &dmeFrameRateSrc);
          v17 = ComputeDmElementIdStr(result: &v37, pDmElement: this);
          CUtlString::Get(this: v17);
          _LoggingSystem_Log(a1: LOG_DME_AAC);
          v37.m_Storage.m_nActualLength = 0;
          if ( v37.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v37.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v37.m_Storage.m_Memory.m_pMemory);
              v37.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v37.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v36.m_Storage.m_nActualLength = 0;
          if ( v36.m_Storage.m_Memory.m_nGrowSize >= 0 && v36.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v36.m_Storage.m_Memory.m_pMemory);
        }
      }
      v18 = pDmeChannelsClipDst;
      v19 = 0;
      i = 0;
      if ( pDmeChannelsClipDst->m_Channels.m_Storage.m_Size <= 0 )
        return 1;
      do
      {
        v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v18->m_Channels.m_Storage.m_Memory.m_pMemory[v19]);
        v21 = v20;
        if ( v20 == 0 )
          goto LABEL_62;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v20 + 16))(
               a1: v20,
               a2: CDmeChannel::m_classType.u) == 0 )
          goto LABEL_62;
        v22 = v21 - 4;
        v38.m_tms = v21 - 4;
        if ( v21 == 4 )
          goto LABEL_62;
        Log = CDmeChannel::GetLog(this: (CDmeChannel *)(v21 - 4));
        v24 = Log;
        if ( Log == nullptr )
          goto LABEL_62;
        v25 = *(char **)(v22 + 24);
        s1 = (char *)defaultValue;
        if ( v25 != (char *)-1 )
          s1 = v25;
        v26 = Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) ? (CDmeTypedLog<Vector> *)Log : nullptr;
        v27 = v24->IsA(this: v24, a2: CDmeTypedLog<Quaternion>::m_classType) ? (CDmeTypedLog<Quaternion> *)v24 : nullptr;
        HIBYTE(pDmElement) = 0;
        j = 0;
        if ( pDmeChannelsClipSrc->m_Channels.m_Storage.m_Size <= 0 )
        {
LABEL_52:
          HIDWORD(v35) = 1;
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
          {
            v33 = ComputeDmElementIdStr(result: &v36, pDmElement: (const CDmElement *)(v38.m_tms + 4));
            HIDWORD(v35) = CUtlString::Get(this: v33);
            v34 = ComputeDmElementIdStr(result: &v37, pDmElement: v42);
            LODWORD(v35) = CUtlString::Get(this: v34);
            _LoggingSystem_Log(a1: LOG_DME_AAC);
            v37.m_Storage.m_nActualLength = 0;
            if ( v37.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v37.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v37.m_Storage.m_Memory.m_pMemory);
                v37.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v37.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            v36.m_Storage.m_nActualLength = 0;
            if ( v36.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v36.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v36.m_Storage.m_Memory.m_pMemory);
                v36.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v36.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
          goto LABEL_61;
        }
        do
        {
          v28 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: pDmeChannelsClipSrc->m_Channels.m_Storage.m_Memory.m_pMemory[j]);
          v29 = v28;
          if ( v28 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v28 + 16))(
                 a1: v28,
                 a2: CDmeChannel::m_classType.u) != 0 )
          {
            v30 = (CDmeChannel *)(v29 - 4);
            if ( v30 != nullptr )
            {
              m_pAsString = v30->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = defaultValue;
              if ( _V_stricmp(s1, s2: m_pAsString) == 0 )
              {
                v32 = (CDmeTypedLog<Vector> *)CDmeChannel::GetLog(this: v30);
                if ( v32 != nullptr )
                {
                  if ( v32->IsA(this: v32, a2: CDmeTypedLog<Vector>::m_classType) && v26 != nullptr )
                  {
                    CDmeSubtract::Subtract<Vector>(this: v42, pDmeTypedLogDst: v26, pDmeTypedLogSrc: v32, &dmeTimeSrc);
LABEL_49:
                    HIBYTE(pDmElement) = 1;
                    goto LABEL_50;
                  }
                  if ( v32->IsA(this: v32, a2: CDmeTypedLog<Quaternion>::m_classType) && v27 != nullptr )
                  {
                    CDmeSubtract::Subtract<Quaternion>(
                      this: v42,
                      pDmeTypedLogDst: v27,
                      pDmeTypedLogSrc: (CDmeTypedLog<Quaternion> *)v32,
                      &dmeTimeSrc);
                    goto LABEL_49;
                  }
                }
              }
            }
          }
LABEL_50:
          ++j;
        }
        while ( j < pDmeChannelsClipSrc->m_Channels.m_Storage.m_Size );
        if ( HIBYTE(pDmElement) == 0 )
          goto LABEL_52;
LABEL_61:
        v19 = i;
LABEL_62:
        v18 = pDmeChannelsClipDst;
        i = ++v19;
      }
      while ( v19 < pDmeChannelsClipDst->m_Channels.m_Storage.m_Size );
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0051BE10
// Name: protected: void CDmeBoneMaskCmd::SubApply(class CDmeChannelsClip __near *,class CDmeDag __near *,class CDmeBoneMask __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskCmd::SubApply(
        CDmeBoneMaskCmd *this,
        CDmeTypedLog<Vector> *pDmeChannelsClip,
        CDmeTypedLog<Quaternion> *pDmeDag,
        float pDmeBoneMask)
{
  CDmeChannelsClip *v4; // edi
  CDmeDag *v5; // esi
  const char *m_pAsString; // eax
  double BoneWeight; // st7
  CUtlString *v8; // eax
  CUtlString *v9; // eax
  float v10; // xmm3_4
  int v11; // ecx
  int v12; // edx
  Vector *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  int v16; // edi
  int v17; // esi
  int v18; // eax
  CDmeTypedLogLayer<Vector> *v19; // esi
  CUtlString *v20; // eax
  int v21; // eax
  CDmeTypedLogLayer<Quaternion> *v22; // esi
  CUtlString *v23; // eax
  CUtlString result; // [esp+14h] [ebp-84h] BYREF
  Quaternion qTmp; // [esp+24h] [ebp-74h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > qTimes; // [esp+34h] [ebp-64h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > vTimes; // [esp+48h] [ebp-50h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > vValues; // [esp+5Ch] [ebp-3Ch] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > qValues; // [esp+70h] [ebp-28h] BYREF
  CUtlString v30; // [esp+84h] [ebp-14h] BYREF
  CDmElement *pDmElement; // [esp+94h] [ebp-4h]

  v4 = (CDmeChannelsClip *)pDmeChannelsClip;
  pDmElement = this;
  if ( pDmeChannelsClip != nullptr )
  {
    v5 = (CDmeDag *)pDmeDag;
    if ( pDmeDag != nullptr && pDmeBoneMask != 0.0 )
    {
      m_pAsString = pDmeDag->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      BoneWeight = CDmeBoneMask::GetBoneWeight(this: (CDmeBoneMask *)LODWORD(pDmeBoneMask), pszBoneName: m_pAsString);
      pDmeBoneMask = BoneWeight;
      if ( BoneWeight != 1.0 && CDmeDag::GetTransform(this: v5) != nullptr )
      {
        pDmeChannelsClip = nullptr;
        pDmeDag = nullptr;
        if ( GetDmeChannelsForDag(
               pDmeTranslateLog: &pDmeChannelsClip,
               pDmeRotateLog: &pDmeDag,
               pDmeDag: v5,
               pDmeChannelsClip: v4) != 0 )
        {
          memset(&vTimes, 0, sizeof(vTimes));
          memset(&vValues, 0, sizeof(vValues));
          GetAllKeys_Vector_(
            keyTimes: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)&vTimes,
            keyValues: (CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *)&vValues,
            pDmeTypedLog: pDmeChannelsClip);
          v10 = pDmeBoneMask;
          v11 = 0;
          if ( vValues.m_Size > 0 )
          {
            v12 = 0;
            do
            {
              v13 = &vValues.m_Memory.m_pMemory[v12];
              v14 = vValues.m_Memory.m_pMemory[v12].y * v10;
              v15 = vValues.m_Memory.m_pMemory[v12].z * v10;
              ++v11;
              v13->x = vValues.m_Memory.m_pMemory[v12].x * v10;
              v13->y = v14;
              v13->z = v15;
              ++v12;
            }
            while ( v11 < vValues.m_Size );
          }
          memset(&qTimes, 0, sizeof(qTimes));
          memset(&qValues, 0, sizeof(qValues));
          GetAllKeys_Quaternion_(
            keyTimes: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)&qTimes,
            keyValues: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&qValues,
            pDmeTypedLog: pDmeDag);
          v16 = 0;
          if ( qValues.m_Size > 0 )
          {
            v17 = 0;
            do
            {
              QuaternionScale(p: &qValues.m_Memory.m_pMemory[v17], t: pDmeBoneMask, q: &qTmp);
              qValues.m_Memory.m_pMemory[v17] = qTmp;
              ++v16;
              ++v17;
            }
            while ( v16 < qValues.m_Size );
          }
          v18 = (int)pDmeChannelsClip->AddNewLayer(this: pDmeChannelsClip);
          v19 = (CDmeTypedLogLayer<Vector> *)v18;
          if ( v18 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v18 + 16))(
                 a1: v18,
                 a2: CDmeTypedLogLayer<Vector>::m_classType.u) != 0 )
          {
            CDmeTypedLogLayer<Vector>::SetAllKeys(this: v19, times: &vTimes, values: &vValues);
            v19->RemoveRedundantKeys_2(this: v19, a2: true);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
          {
            v20 = ComputeDmElementIdStr(result: &v30, pDmElement);
            CUtlString::Get(this: v20);
            _LoggingSystem_Log(a1: LOG_DME_AAC);
            v30.m_Storage.m_nActualLength = 0;
            if ( v30.m_Storage.m_Memory.m_nGrowSize >= 0 && v30.m_Storage.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v30.m_Storage.m_Memory.m_pMemory);
          }
          v21 = (int)pDmeDag->AddNewLayer(this: pDmeDag);
          v22 = (CDmeTypedLogLayer<Quaternion> *)v21;
          if ( v21 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v21 + 16))(
                 a1: v21,
                 a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
          {
            CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v22, times: &qTimes, values: &qValues);
            v22->RemoveRedundantKeys_2(this: v22, a2: true);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
          {
            v23 = ComputeDmElementIdStr(result: &v30, pDmElement);
            CUtlString::Get(this: v23);
            _LoggingSystem_Log(a1: LOG_DME_AAC);
            v30.m_Storage.m_nActualLength = 0;
            if ( v30.m_Storage.m_Memory.m_nGrowSize >= 0 && v30.m_Storage.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v30.m_Storage.m_Memory.m_pMemory);
          }
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&qValues);
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&qTimes);
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vValues);
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vTimes);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
        {
          v8 = ComputeDmElementIdStr(&result, pDmElement: v5);
          CUtlString::Get(this: v8);
          v9 = ComputeDmElementIdStr(result: &v30, pDmElement);
          CUtlString::Get(this: v9);
          _LoggingSystem_Log(a1: LOG_DME_AAC);
          CUtlString::~CUtlString(this: &v30);
          CUtlString::~CUtlString(this: &result);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051C180
// Name: public: virtual bool CDmeBoneMaskCmd::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeBoneMaskCmd::Apply(CDmeBoneMaskCmd *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  const CDmElement *v3; // esi
  CUtlString *v4; // eax
  CUtlString *v5; // eax
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  CDmeDag **v9; // eax
  CDmeDag *v10; // ebx
  int v11; // eax
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > depthFirstStack; // [esp+Ch] [ebp-34h] BYREF
  CUtlString v13; // [esp+20h] [ebp-20h] BYREF
  CDmeBoneMask *pDmeBoneMask; // [esp+30h] [ebp-10h]
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+34h] [ebp-Ch] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+38h] [ebp-8h] BYREF
  CDmElement *pDmElementa; // [esp+3Ch] [ebp-4h]
  int i; // [esp+48h] [ebp+8h]
  int ia; // [esp+48h] [ebp+8h]
  bool i_3; // [esp+4Bh] [ebp+Bh]

  pDmElementa = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v13, pDmElement: this);
  i_3 = ConvertToDmeSequenceAndDmeChannelsClip(
          pDmElement,
          sDmElementId: v2,
          pDmeSequence: &pDmeSequenceDst,
          pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v13.m_Storage.m_nActualLength = 0;
  if ( v13.m_Storage.m_Memory.m_nGrowSize >= 0 && v13.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13.m_Storage.m_Memory.m_pMemory);
  if ( i_3 )
    return 0;
  v3 = pDmeSequenceDst;
  i = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
        a1: g_pDataModel.u,
        a2: pDmeSequenceDst->m_eSkeleton.m_Storage.m_Handle);
  if ( i == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
    {
LABEL_7:
      v4 = ComputeDmElementIdStr(result: (CUtlString *)&depthFirstStack.m_Memory.m_nAllocationCount, pDmElement: v3);
      CUtlString::Get(this: v4);
      v5 = ComputeDmElementIdStr(result: &v13, pDmElement: pDmElementa);
      CUtlString::Get(this: v5);
      _LoggingSystem_Log(a1: LOG_DME_AAC);
      v13.m_Storage.m_nActualLength = 0;
      if ( v13.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v13.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13.m_Storage.m_Memory.m_pMemory);
          v13.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v13.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      depthFirstStack.m_pElements = nullptr;
      if ( depthFirstStack.m_Size >= 0 && depthFirstStack.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)depthFirstStack.m_Memory.m_nAllocationCount);
    }
    return 0;
  }
  pDmeBoneMask = (CDmeBoneMask *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: v3[6].m_pAttributes);
  if ( pDmeBoneMask == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
      goto LABEL_7;
    return 0;
  }
  memset(&depthFirstStack, 0, sizeof(depthFirstStack));
  CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&depthFirstStack, num: 1);
  m_pMemory = depthFirstStack.m_Memory.m_pMemory;
  m_Size = depthFirstStack.m_Size + 1;
  v9 = &depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size++];
  depthFirstStack.m_pElements = depthFirstStack.m_Memory.m_pMemory;
  if ( v9 != nullptr )
    *v9 = (CDmeDag *)i;
  while ( m_Size != 0 )
  {
    v10 = m_pMemory[--m_Size];
    depthFirstStack.m_Size = m_Size;
    if ( v10 != nullptr )
    {
      v11 = CDmElementFramework::GetPhase(this: v10) - 1;
      ia = v11;
      if ( v11 >= 0 )
      {
        while ( 1 )
        {
          pDmeSequenceDst = (CDmeSequence *)CDmeDag::GetChild(this: v10, i: v11);
          if ( m_Size >= depthFirstStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&depthFirstStack, num: 1);
            m_Size = depthFirstStack.m_Size;
            m_pMemory = depthFirstStack.m_Memory.m_pMemory;
          }
          depthFirstStack.m_Size = ++m_Size;
          depthFirstStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = (CDmeDag *)pDmeSequenceDst;
          if ( --ia < 0 )
            break;
          v11 = ia;
        }
      }
      CDmeBoneMaskCmd::SubApply(
        this: (CDmeBoneMaskCmd *)pDmElementa,
        pDmeChannelsClip: (CDmeTypedLog<Vector> *)pDmeChannelsClipDst,
        pDmeDag: (CDmeTypedLog<Quaternion> *)v10,
        pDmeBoneMask: *(float *)&pDmeBoneMask);
    }
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&depthFirstStack);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C4C0
// Name: public: virtual bool CDmeAnimationAssemblyCommand::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationAssemblyCommand::IsA(CDmeAnimationAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C4F0
// Name: public: virtual int CDmeAnimationAssemblyCommand::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationAssemblyCommand::GetInheritanceDepth(
        CDmeAnimationAssemblyCommand *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C5E0
// Name: public: virtual bool CDmeFixupLoop::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFixupLoop::IsA(CDmeFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFixupLoop::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C620
// Name: public: virtual int CDmeFixupLoop::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFixupLoop::GetInheritanceDepth(CDmeFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFixupLoop::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C6E0
// Name: protected: virtual void CDmeFixupLoop::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::PerformConstruction(CDmeFixupLoop *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_nStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "startFrame",
                                       type: AT_INT,
                                       pMemory: &this->m_nStartFrame);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x0051C7B0
// Name: public: virtual bool CDmeSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSubtract::IsA(CDmeSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C7F0
// Name: public: virtual int CDmeSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSubtract::GetInheritanceDepth(CDmeSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C8C0
// Name: protected: virtual void CDmeSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::PerformConstruction(CDmeSubtract *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_eSequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequence",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eSequence);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eSequence.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eSequence.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x0051C9B0
// Name: public: virtual bool CDmePreSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePreSubtract::IsA(CDmePreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePreSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C9F0
// Name: public: virtual int CDmePreSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePreSubtract::GetInheritanceDepth(CDmePreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePreSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051CAD0
// Name: protected: virtual void CDmePreSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmePreSubtract::PerformConstruction(CDmePreSubtract *this)
{
  CDmeSubtract::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051CB70
// Name: public: virtual bool CDmeRotateTo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRotateTo::IsA(CDmeRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRotateTo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051CBB0
// Name: public: virtual int CDmeRotateTo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRotateTo::GetInheritanceDepth(CDmeRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRotateTo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051CD50
// Name: public: virtual bool CDmeBoneMaskCmd::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMaskCmd::IsA(CDmeBoneMaskCmd *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMaskCmd::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051CD90
// Name: public: virtual int CDmeBoneMaskCmd::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMaskCmd::GetInheritanceDepth(CDmeBoneMaskCmd *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMaskCmd::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051CF40
// Name: ComputeMergedKeyTimes
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeMergedKeyTimes(
        CUtlMemory<vgui::TreeNode *,int> *mergedTimes@<esi>,
        CDmeLog *pDmeLogA,
        CDmeLog *pDmeLogB)
{
  int v3; // ebx
  int v4; // eax
  CDmeLog *v5; // edi
  const DmeTime_t *v6; // eax
  unsigned __int16 v7; // dx
  int *v8; // ecx
  int m_pMemory; // edi
  DmeTime_t *p_m_Data; // ebx
  int m_nAllocationCount; // eax
  DmeTime_t *v12; // ecx
  int v13; // eax
  DmeTime_t *v14; // edi
  unsigned __int16 v15; // ax
  CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl*)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short> > timesTree; // [esp+8h] [ebp-24h] BYREF
  DmeTime_t v17; // [esp+24h] [ebp-8h] BYREF
  int i; // [esp+28h] [ebp-4h]

  v3 = 0;
  v4 = 0;
  mergedTimes[1].m_pMemory = nullptr;
  timesTree.m_LessFunc = (bool (__cdecl *)(const DmeTime_t *, const DmeTime_t *))CDefOps<DmeTime_t>::LessFunc;
  memset(&timesTree.m_Elements, 0, sizeof(timesTree.m_Elements));
  *(_DWORD *)&timesTree.m_Root = 0xFFFF;
  *(_DWORD *)&timesTree.m_FirstFree = -1;
  timesTree.m_pElements = nullptr;
  i = 0;
  while ( 1 )
  {
    v5 = pDmeLogA;
    if ( v4 != 0 )
      v5 = pDmeLogB;
    if ( v5 != nullptr && CDmeLog::GetKeyCount(this: v5) > 0 )
    {
      do
      {
        v6 = v5->GetKeyTime(this: v5, result: &v17, a3: v3);
        CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::InsertIfNotFound(
          this: &timesTree,
          insert: v6);
        ++v3;
      }
      while ( v3 < CDmeLog::GetKeyCount(this: v5) );
    }
    v4 = i + 1;
    i = v4;
    if ( v4 >= 2 )
      break;
    v3 = 0;
  }
  v7 = CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::FirstInorder(this: &timesTree);
  i = v7;
  while ( v7 < timesTree.m_Elements.m_nAllocationCount && v7 <= timesTree.m_LastAlloc.index )
  {
    if ( (`CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_7C8E4C = 0x1FFFF;
    }
    v8 = v7 == 0xFFFF
       ? &`CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&timesTree.m_Elements.m_pMemory[v7];
    if ( *(_WORD *)v8 == v7 )
      break;
    m_pMemory = (int)mergedTimes[1].m_pMemory;
    p_m_Data = &timesTree.m_Elements.m_pMemory[v7].m_Data;
    m_nAllocationCount = mergedTimes->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: mergedTimes, num: m_pMemory - m_nAllocationCount + 1);
      v7 = i;
    }
    ++mergedTimes[1].m_pMemory;
    v12 = (DmeTime_t *)mergedTimes->m_pMemory;
    v13 = (int)mergedTimes[1].m_pMemory - m_pMemory - 1;
    mergedTimes[1].m_nAllocationCount = (int)mergedTimes->m_pMemory;
    if ( v13 > 0 )
    {
      _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 4 * v13);
      v7 = i;
    }
    v14 = (DmeTime_t *)&mergedTimes->m_pMemory[m_pMemory];
    if ( v14 != nullptr )
      v14->m_tms = p_m_Data->m_tms;
    v15 = CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::NextInorder(
            this: &timesTree,
            i: v7);
    i = v15;
    v7 = v15;
  }
  CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::RemoveAll(this: &timesTree);
  if ( timesTree.m_Elements.m_nGrowSize >= 0 && timesTree.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: timesTree.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0051D100
// Name: protected: void CDmeRotateTo::SubApply(class CDmeDag __near *,class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeRotateTo::SubApply(
        CDmeRotateTo *this,
        CDmeTypedLog<Quaternion> *pDmeDag,
        CDmeLog *pDmeChannelsClip,
        bool bZUp)
{
  CDmeDag *v4; // esi
  CDmeChannelsClip *v5; // edi
  CUtlString *v6; // eax
  CUtlString *v7; // eax
  CDmeTypedLog<Vector> *v8; // edi
  const Vector *Value; // esi
  const Vector *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // xmm0_4
  int v17; // esi
  DmeTime_t *v18; // ebx
  const Quaternion *v19; // eax
  const Vector *v20; // eax
  int v21; // eax
  CDmeTypedLogLayer<Vector> *v22; // esi
  CUtlString *v23; // eax
  int v24; // eax
  CDmeTypedLogLayer<Quaternion> *v25; // esi
  CUtlString *v26; // eax
  long double v27; // [esp+0h] [ebp-120h]
  long double v28; // [esp+8h] [ebp-118h] OVERLAPPED BYREF
  matrix3x4_t mSrc; // [esp+3Ch] [ebp-E4h] BYREF
  matrix3x4_t mRoot; // [esp+6Ch] [ebp-B4h] BYREF
  Quaternion qTmp; // [esp+9Ch] [ebp-84h] BYREF
  Vector vTmp; // [esp+ACh] [ebp-74h] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > qValues; // [esp+B8h] [ebp-68h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > vValues; // [esp+CCh] [ebp-54h] BYREF
  DmeTime_t dmeTimeEnd; // [esp+E0h] [ebp-40h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > mergedKeyTimes; // [esp+E4h] [ebp-3Ch] BYREF
  int flDeltaAngle; // [esp+F8h] [ebp-28h]
  CUtlString result; // [esp+FCh] [ebp-24h] BYREF
  CUtlString v39; // [esp+10Ch] [ebp-14h] BYREF
  CDmElement *pDmElement; // [esp+11Ch] [ebp-4h]

  v4 = (CDmeDag *)pDmeDag;
  pDmElement = this;
  if ( pDmeDag != nullptr )
  {
    v5 = (CDmeChannelsClip *)pDmeChannelsClip;
    if ( pDmeChannelsClip != nullptr && CDmeDag::GetTransform(this: (CDmeDag *)pDmeDag) != nullptr )
    {
      pDmeChannelsClip = nullptr;
      pDmeDag = nullptr;
      if ( GetDmeChannelsForDag(
             pDmeTranslateLog: (CDmeTypedLog<Vector> **)&pDmeChannelsClip,
             pDmeRotateLog: &pDmeDag,
             pDmeDag: v4,
             pDmeChannelsClip: v5) != 0 )
      {
        v8 = (CDmeTypedLog<Vector> *)pDmeChannelsClip;
        *(float *)&flDeltaAngle = 0.0;
        CDmeLog::GetBeginTime(this: pDmeChannelsClip, result: (DmeTime_t *)&pDmeChannelsClip);
        CDmeLog::GetEndTime(this: v8, result: &dmeTimeEnd);
        Value = CDmeTypedLog<Vector>::GetValue(this: v8, time: (DmeTime_t)pDmeChannelsClip);
        v10 = CDmeTypedLog<Vector>::GetValue(this: v8, time: dmeTimeEnd);
        v11 = v10->x - Value->x;
        v12 = v10->y - Value->y;
        if ( bZUp )
        {
          if ( v11 == 0.0 && v12 == 0.0 )
          {
            v39.m_Storage.m_Memory.m_nAllocationCount = 0;
            v39.m_Storage.m_Memory.m_nGrowSize = flDeltaAngle;
            v39.m_Storage.m_nActualLength = 0;
          }
          else
          {
            __libm_sse2_atan2(y: v27, x: v28);
            v13 = v12 * 57.29577951308232;
            *(float *)&v14 = *(float *)&pDmElement[1].__vftable - v13;
            v39.m_Storage.m_Memory.m_nAllocationCount = 0;
            v39.m_Storage.m_Memory.m_nGrowSize = v14;
            v39.m_Storage.m_nActualLength = 0;
          }
        }
        else
        {
          if ( v11 == 0.0 && (float)(v10->z - Value->z) == 0.0 )
          {
            v16 = flDeltaAngle;
          }
          else
          {
            __libm_sse2_atan2(y: v27, x: v28);
            v15 = v11 * 57.29577951308232;
            *(float *)&v16 = *(float *)&pDmElement[1].__vftable - v15;
          }
          v39.m_Storage.m_Memory.m_nAllocationCount = v16;
          v39.m_Storage.m_Memory.m_nGrowSize = 0;
          v39.m_Storage.m_nActualLength = 0;
        }
        AngleMatrix(angles: (const QAngle *)&v39.m_Storage.m_Memory.m_nAllocationCount, matrix: &mRoot);
        memset(&mergedKeyTimes, 0, sizeof(mergedKeyTimes));
        ComputeMergedKeyTimes(
          mergedTimes: (CUtlMemory<vgui::TreeNode *,int> *)&mergedKeyTimes,
          pDmeLogA: v8,
          pDmeLogB: pDmeDag);
        v17 = 0;
        memset(&vValues, 0, sizeof(vValues));
        memset(&qValues, 0, sizeof(qValues));
        if ( mergedKeyTimes.m_Size > 0 )
        {
          do
          {
            v18 = &mergedKeyTimes.m_Memory.m_pMemory[v17];
            v19 = CDmeTypedLog<Quaternion>::GetValue(this: pDmeDag, time: (DmeTime_t)v18->m_tms);
            QuaternionAngles(q: v19, angles: (RadianEuler *)&v39.m_Storage.m_Memory.m_nAllocationCount);
            v20 = CDmeTypedLog<Vector>::GetValue(this: v8, time: (DmeTime_t)v18->m_tms);
            AngleMatrix(
              angles: (const RadianEuler *)&v39.m_Storage.m_Memory.m_nAllocationCount,
              position: v20,
              matrix: &mSrc);
            ConcatTransforms(in1: &mRoot, in2: &mSrc, out: (matrix3x4_t *)((char *)&v28 + 4));
            MatrixAngles(matrix: (const matrix3x4_t *)((char *)&v28 + 4), q: &qTmp, pos: &vTmp);
            CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
              this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&vValues,
              elem: vValues.m_Size,
              src: (const QAngle *)&vTmp);
            CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
              this: &qValues,
              elem: qValues.m_Size,
              src: &qTmp);
            ++v17;
          }
          while ( v17 < mergedKeyTimes.m_Size );
        }
        v21 = (int)v8->AddNewLayer(this: v8);
        v22 = (CDmeTypedLogLayer<Vector> *)v21;
        if ( v21 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v21 + 16))(
               a1: v21,
               a2: CDmeTypedLogLayer<Vector>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Vector>::SetAllKeys(this: v22, times: &mergedKeyTimes, values: &vValues);
          v22->RemoveRedundantKeys_2(this: v22, a2: true);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
        {
          v23 = ComputeDmElementIdStr(&result, pDmElement);
          CUtlString::Get(this: v23);
          _LoggingSystem_Log(a1: LOG_DME_AAC);
          result.m_Storage.m_nActualLength = 0;
          if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
        }
        v24 = (int)pDmeDag->AddNewLayer(this: pDmeDag);
        v25 = (CDmeTypedLogLayer<Quaternion> *)v24;
        if ( v24 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v24 + 16))(
               a1: v24,
               a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v25, times: &mergedKeyTimes, values: &qValues);
          v25->RemoveRedundantKeys_2(this: v25, a2: true);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
        {
          v26 = ComputeDmElementIdStr(&result, pDmElement);
          CUtlString::Get(this: v26);
          _LoggingSystem_Log(a1: LOG_DME_AAC);
          result.m_Storage.m_nActualLength = 0;
          if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
        }
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&qValues);
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vValues);
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&mergedKeyTimes);
      }
      else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
      {
        v6 = ComputeDmElementIdStr(&result, pDmElement: v4);
        CUtlString::Get(this: v6);
        v7 = ComputeDmElementIdStr(result: &v39, pDmElement);
        CUtlString::Get(this: v7);
        _LoggingSystem_Log(a1: LOG_DME_AAC);
        v39.m_Storage.m_nActualLength = 0;
        if ( v39.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v39.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v39.m_Storage.m_Memory.m_pMemory);
            v39.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v39.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        result.m_Storage.m_nActualLength = 0;
        if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051D5A0
// Name: public: virtual bool CDmeRotateTo::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeRotateTo::Apply(CDmeRotateTo *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  CDmeSequence *v3; // edi
  int v4; // eax
  CDmeTypedLog<Quaternion> *v5; // esi
  CUtlString *v6; // eax
  CUtlString *v7; // eax
  int v9; // edi
  CDmeChannelsClip *v10; // ebx
  CDmeTypedLog<Quaternion> *Child; // eax
  CUtlString *v12; // eax
  CUtlString *v13; // eax
  bool IsZUp; // [esp-4h] [ebp-3Ch]
  CUtlString v15; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlString v16; // [esp+1Ch] [ebp-1Ch] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+2Ch] [ebp-Ch] BYREF
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+30h] [ebp-8h] BYREF
  CDmElement *v19; // [esp+34h] [ebp-4h]
  bool pDmElement_3; // [esp+43h] [ebp+Bh]

  v19 = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v16, pDmElement: this);
  pDmElement_3 = ConvertToDmeSequenceAndDmeChannelsClip(
                   pDmElement,
                   sDmElementId: v2,
                   pDmeSequence: &pDmeSequenceDst,
                   pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v16.m_Storage.m_nActualLength = 0;
  if ( v16.m_Storage.m_Memory.m_nGrowSize >= 0 && v16.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16.m_Storage.m_Memory.m_pMemory);
  if ( pDmElement_3 )
    return 0;
  v3 = pDmeSequenceDst;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: pDmeSequenceDst->m_eSkeleton.m_Storage.m_Handle);
  v5 = (CDmeTypedLog<Quaternion> *)v4;
  if ( v4 == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
    {
      v6 = ComputeDmElementIdStr(result: &v15, pDmElement: v3);
      CUtlString::Get(this: v6);
      v7 = ComputeDmElementIdStr(result: &v16, pDmElement: v19);
      CUtlString::Get(this: v7);
      _LoggingSystem_Log(a1: LOG_DME_AAC);
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
      v15.m_Storage.m_nActualLength = 0;
      if ( v15.m_Storage.m_Memory.m_nGrowSize >= 0 && v15.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15.m_Storage.m_Memory.m_pMemory);
    }
    return 0;
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeModel::m_classType.u) == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC) != 0 )
    {
      v12 = ComputeDmElementIdStr(result: &v15, pDmElement: v3);
      CUtlString::Get(this: v12);
      v13 = ComputeDmElementIdStr(result: &v16, pDmElement: v19);
      CUtlString::Get(this: v13);
      _LoggingSystem_Log(a1: LOG_DME_AAC);
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
      v15.m_Storage.m_nActualLength = 0;
      if ( v15.m_Storage.m_Memory.m_nGrowSize >= 0 && v15.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15.m_Storage.m_Memory.m_pMemory);
    }
    CDmeRotateTo::SubApply(
      this: (CDmeRotateTo *)v19,
      pDmeDag: v5,
      pDmeChannelsClip: (CDmeLog *)pDmeChannelsClipDst,
      bZUp: true);
    return 1;
  }
  v9 = 0;
  if ( CDmElementFramework::GetPhase(this: (CDmeDag *)v5) <= 0 )
    return 1;
  v10 = pDmeChannelsClipDst;
  do
  {
    IsZUp = CDmeModel::IsZUp(this: (CDmeModel *)v5);
    Child = (CDmeTypedLog<Quaternion> *)CDmeDag::GetChild(this: (CDmeDag *)v5, i: v9);
    CDmeRotateTo::SubApply(this: (CDmeRotateTo *)v19, pDmeDag: Child, pDmeChannelsClip: (CDmeLog *)v10, bZUp: IsZUp);
    ++v9;
  }
  while ( v9 < CDmElementFramework::GetPhase(this: (CDmeDag *)v5) );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006AE8C0
// Name: _dynamic_initializer_for__CDmeAnimationAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationAssemblyCommand::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationAssemblyCommand pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE920
// Name: _dynamic_initializer_for__CDmeFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFixupLoop::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFixupLoop pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE980
// Name: _dynamic_initializer_for__CDmeSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE9E0
// Name: _dynamic_initializer_for__CDmePreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePreSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePreSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePreSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEA40
// Name: _dynamic_initializer_for__CDmeRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRotateTo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRotateTo::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRotateTo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEAA0
// Name: _dynamic_initializer_for__CDmeBoneMaskCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMaskCmd::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMaskCmd::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMaskCmd pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4710
// Name: _dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationAssemblyCommand::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4720
// Name: _dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFixupLoop::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4730
// Name: _dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4740
// Name: _dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePreSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4750
// Name: _dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRotateTo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4760
// Name: _dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMaskCmd::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE8F0
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE900
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationAssemblyCommand_Helper,
           classname: "DmeAnimationAssemblyCommand",
           pFactory: &g_CDmeAnimationAssemblyCommand_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE950
// Name: _dynamic_initializer_for__g_CDmeFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFixupLoop_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE960
// Name: _dynamic_initializer_for__g_CDmeFixupLoop_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFixupLoop_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFixupLoop_Helper,
           classname: "DmeFixupLoop",
           pFactory: &g_CDmeFixupLoop_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE9B0
// Name: _dynamic_initializer_for__g_CDmeSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE9C0
// Name: _dynamic_initializer_for__g_CDmeSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSubtract_Helper,
           classname: "DmeSubtract",
           pFactory: &g_CDmeSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AEA10
// Name: _dynamic_initializer_for__g_CDmePreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePreSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEA20
// Name: _dynamic_initializer_for__g_CDmePreSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePreSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePreSubtract_Helper,
           classname: "DmePreSubtract",
           pFactory: &g_CDmePreSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AEA70
// Name: _dynamic_initializer_for__g_CDmeRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRotateTo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEA80
// Name: _dynamic_initializer_for__g_CDmeRotateTo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRotateTo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRotateTo_Helper,
           classname: "DmeRotateTo",
           pFactory: &g_CDmeRotateTo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AEAD0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMaskCmd_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEAE0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmd_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMaskCmd_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMaskCmd_Helper,
           classname: "DmeBoneMaskCmd",
           pFactory: &g_CDmeBoneMaskCmd_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4770
// Name: _dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFixupLoop_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4780
// Name: _dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4790
// Name: _dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePreSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B47A0
// Name: _dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeRotateTo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B47B0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBoneMaskCmd_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B47C0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimationAssemblyCommand_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E7D50
// Name: protected: virtual void CDmeSubtract::Subtract(class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract(CDmeSubtract *this, Vector *vResult, const Vector *vDst, const Vector *vSrc)
{
  vResult->x = vDst->x - vSrc->x;
  vResult->y = vDst->y - vSrc->y;
  vResult->z = vDst->z - vSrc->z;
}

//------------------------------------------------------------------------------
// Address: 0x004E7D90
// Name: protected: virtual void CDmeSubtract::Subtract(class Quaternion __near &,class Quaternion const __near &,class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract(
        CDmeSubtract *this,
        Quaternion *qResult,
        const Quaternion *qDst,
        const Quaternion *qSrc)
{
  QuaternionSM(s: -1.0, p: qSrc, q: qDst, qt: qResult);
}

//------------------------------------------------------------------------------
// Address: 0x004E7DC0
// Name: protected: virtual void CDmePreSubtract::Subtract(class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePreSubtract::Subtract(
        CDmePreSubtract *this,
        Vector *vResult,
        const Vector *vDst,
        const Vector *vSrc)
{
  vResult->x = vSrc->x - vDst->x;
  vResult->y = vSrc->y - vDst->y;
  vResult->z = vSrc->z - vDst->z;
}

//------------------------------------------------------------------------------
// Address: 0x004E7E00
// Name: protected: virtual void CDmePreSubtract::Subtract(class Quaternion __near &,class Quaternion const __near &,class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePreSubtract::Subtract(
        CDmePreSubtract *this,
        Quaternion *qResult,
        const Quaternion *qDst,
        const Quaternion *qSrc)
{
  QuaternionMA(p: qDst, s: -1.0, q: qSrc, qt: qResult);
}

//------------------------------------------------------------------------------
// Address: 0x004E82F0
// Name: GetDmeChannelsForDag
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetDmeChannelsForDag(
        CDmeTypedLog<Vector> **pDmeTranslateLog,
        CDmeTypedLog<Quaternion> **pDmeRotateLog,
        CDmeDag *pDmeDag,
        CDmeChannelsClip *pDmeChannelsClip)
{
  CDmeChannelsClip *v5; // esi
  CDmeTransform *Transform; // edi
  int v7; // eax
  int v8; // esi
  CDmeChannel *v9; // esi
  CDmeLog *Log; // eax
  CDmElement *v11; // edi
  CDmeTypedLog<Vector> *v12; // eax
  CUtlString *v13; // eax
  CUtlString *v14; // eax
  CUtlString *v15; // eax
  const char *v16; // eax
  CUtlString *v17; // ecx
  CDmeTypedLog<Quaternion> *v18; // eax
  CUtlString *v19; // eax
  CUtlString *v20; // eax
  CUtlString *v21; // eax
  const char *v22; // eax
  const char *v24; // [esp-8h] [ebp-78h]
  const char *v25; // [esp-8h] [ebp-78h]
  const char *v26; // [esp-4h] [ebp-74h]
  const char *v27; // [esp-4h] [ebp-74h]
  CUtlString v28; // [esp+Ch] [ebp-64h] BYREF
  CUtlString v29; // [esp+1Ch] [ebp-54h] BYREF
  CUtlString v30; // [esp+2Ch] [ebp-44h] BYREF
  CUtlString v31; // [esp+3Ch] [ebp-34h] BYREF
  CUtlString v32; // [esp+4Ch] [ebp-24h] BYREF
  CUtlString v33; // [esp+5Ch] [ebp-14h] BYREF
  CDmeTransform *pDmeTransform; // [esp+6Ch] [ebp-4h]
  CDmeTypedLog<Vector> **pDmeTranslateLoga; // [esp+78h] [ebp+8h]

  *pDmeTranslateLog = nullptr;
  *pDmeRotateLog = nullptr;
  if ( pDmeDag == nullptr )
    return 0;
  v5 = pDmeChannelsClip;
  if ( pDmeChannelsClip == nullptr )
    return 0;
  Transform = CDmeDag::GetTransform(this: pDmeDag);
  pDmeTransform = Transform;
  if ( Transform == nullptr )
    return 0;
  if ( pDmeChannelsClip->m_Channels.m_Storage.m_Size != 0 )
  {
    pDmeTranslateLoga = nullptr;
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(CDmeTypedLog<Vector> **)((char *)pDmeTranslateLoga
                                      + (unsigned int)v5->m_Channels.m_Storage.m_Memory.m_pMemory));
      v8 = v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v9 = (CDmeChannel *)(v8 - 4);
        if ( v9 != nullptr && CDmeChannel::GetToElement(this: v9) == Transform )
        {
          Log = CDmeChannel::GetLog(this: v9);
          v11 = Log;
          if ( Log != nullptr )
          {
            v12 = CastElement<CDmeTypedLog<Vector>>(pElement: Log);
            if ( v12 != nullptr )
            {
              if ( *pDmeTranslateLog != nullptr )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) == 0 )
                  goto LABEL_25;
                v13 = ComputeDmElementIdStr(result: &v31, pDmElement: &v9->CDmElement);
                v26 = CUtlString::Get(this: v13);
                v14 = ComputeDmElementIdStr(result: &v32, pDmElement: *pDmeTranslateLog);
                v24 = CUtlString::Get(this: v14);
                v15 = ComputeDmElementIdStr(result: &v33, pDmElement: pDmeDag);
                v16 = CUtlString::Get(this: v15);
                _LoggingSystem_Log(
                  a1: LOG_DME_AAC,
                  a2: 1,
                  a3: "%s: Multiple Translate Channels Found For Dag, Using %s, Ignoring %s\n",
                  v16,
                  v24,
                  v26);
                CUtlString::~CUtlString(this: &v33);
                CUtlString::~CUtlString(this: &v32);
                v17 = &v31;
LABEL_24:
                CUtlString::~CUtlString(this: v17);
                goto LABEL_25;
              }
              *pDmeTranslateLog = v12;
              if ( *pDmeRotateLog != nullptr )
                break;
            }
            else
            {
              v18 = CastElement<CDmeTypedLog<Quaternion>>(pElement: v11);
              if ( v18 == nullptr )
                goto LABEL_25;
              if ( *pDmeRotateLog != nullptr )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) == 0 )
                  goto LABEL_25;
                v19 = ComputeDmElementIdStr(result: &v28, pDmElement: &v9->CDmElement);
                v27 = CUtlString::Get(this: v19);
                v20 = ComputeDmElementIdStr(result: &v29, pDmElement: *pDmeRotateLog);
                v25 = CUtlString::Get(this: v20);
                v21 = ComputeDmElementIdStr(result: &v30, pDmElement: pDmeDag);
                v22 = CUtlString::Get(this: v21);
                _LoggingSystem_Log(
                  a1: LOG_DME_AAC,
                  a2: 1,
                  a3: "%s: Multiple Rotate Channels Found For Dag, Using %s, Ignoring %s\n",
                  v22,
                  v25,
                  v27);
                CUtlString::~CUtlString(this: &v30);
                CUtlString::~CUtlString(this: &v29);
                v17 = &v28;
                goto LABEL_24;
              }
              *pDmeRotateLog = v18;
              if ( *pDmeTranslateLog != nullptr )
                goto LABEL_27;
            }
          }
        }
      }
LABEL_25:
      v5 = pDmeChannelsClip;
      ++pDmeTranslateLoga;
      if ( pDmeChannelsClip->m_Channels.m_Storage.m_Size == 0 )
        break;
      Transform = pDmeTransform;
    }
  }
  if ( *pDmeTranslateLog != nullptr )
  {
LABEL_27:
    if ( *pDmeRotateLog != nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E8EB0
// Name: ConvertToDmeSequenceAndDmeChannelsClip
// Source: json
//------------------------------------------------------------------------------
char __usercall ConvertToDmeSequenceAndDmeChannelsClip@<al>(
        CDmeSequence *pDmElement@<esi>,
        CUtlString *sDmElementId@<edi>,
        CDmeSequence **pDmeSequence,
        CDmeChannelsClip **pDmeChannelsClip)
{
  const char *v4; // eax
  const char *v6; // eax
  CDmeChannelsClip *DmeChannelsClip; // eax
  CUtlString *v8; // eax
  const char *v9; // eax
  const char *v10; // [esp-4h] [ebp-14h]
  CUtlString v11; // [esp+0h] [ebp-10h] BYREF

  if ( pDmElement == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v4 = CUtlString::operator char const *(this: sDmElementId);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: No DmElement Specified specified\n", v4);
    }
    return 0;
  }
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pDmElement->IsA)(
         a1: pDmElement,
         a2: (CUtlSymbolLarge)CDmeSequence::m_classType.u.m_Id) )
  {
    DmeChannelsClip = CDmeSequence::GetDmeChannelsClip(this: pDmElement);
    if ( DmeChannelsClip != nullptr )
    {
      *pDmeSequence = pDmElement;
      *pDmeChannelsClip = DmeChannelsClip;
      return 1;
    }
    else
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
      {
        v8 = ComputeDmElementIdStr(result: &v11, pDmElement);
        v10 = CUtlString::Get(this: v8);
        v9 = CUtlString::operator char const *(this: sDmElementId);
        _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No DmeChannelsClip\n", v9, v10);
        v11.m_Storage.m_nActualLength = 0;
        if ( v11.m_Storage.m_Memory.m_nGrowSize >= 0 && v11.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11.m_Storage.m_Memory.m_pMemory);
      }
      return 0;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) == 0 )
      return 0;
    v6 = CUtlString::operator char const *(this: sDmElementId);
    _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: No DmeSequence Specified specified\n", v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8FE0
// Name: protected: void CDmeFixupLoop::Apply<class Vector>(class CDmeTypedLog<class Vector> __near *,class DmeTime_t const __near &,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::Apply<Vector>(
        CDmeFixupLoop *this,
        CDmeTypedLog<Vector> *pDmeTypedLogDst,
        const DmeTime_t *dmeTimeStart,
        const DmeTime_t *dmeTimeEnd)
{
  int v4; // esi
  int v5; // eax
  int m_Size; // eax
  int v7; // edi
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  DmeTime_t *v10; // edi
  const QAngle *KeyValue; // eax
  Vector *v12; // edi
  DmeTime_t *v13; // ebx
  int v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  int v18; // eax
  int v19; // esi
  int v20; // edx
  int m_tms; // ecx
  float v22; // xmm0_4
  float *p_x; // ecx
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  int v27; // ecx
  float v28; // xmm0_4
  float *v29; // ecx
  float v30; // xmm6_4
  float v31; // xmm7_4
  float v32; // xmm0_4
  int v33; // ecx
  float v34; // xmm0_4
  float *v35; // ecx
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  int v39; // ecx
  float v40; // xmm0_4
  float *v41; // ecx
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm0_4
  int v45; // edx
  int v46; // ecx
  float v47; // xmm0_4
  float *v48; // ecx
  float v49; // xmm6_4
  float v50; // xmm7_4
  float v51; // xmm0_4
  int v52; // esi
  int v53; // ecx
  int v54; // edx
  int v55; // ebx
  float v56; // xmm0_4
  float v57; // xmm0_4
  float *v58; // eax
  float v59; // xmm7_4
  int v60; // edi
  float v61; // xmm0_4
  float v62; // xmm0_4
  Vector *v63; // eax
  float v64; // xmm7_4
  int v65; // edi
  float v66; // xmm0_4
  float v67; // xmm0_4
  Vector *v68; // eax
  float v69; // xmm7_4
  int v70; // edi
  float v71; // xmm0_4
  float v72; // xmm0_4
  Vector *v73; // eax
  float v74; // xmm7_4
  int v75; // ebx
  int v76; // edx
  float v77; // xmm0_4
  float v78; // xmm0_4
  float *v79; // eax
  float v80; // xmm7_4
  CDmeLogLayer *v81; // eax
  CDmeTypedLogLayer<Vector> *v82; // esi
  Vector *v83; // eax
  DmeTime_t *v84; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > values; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+20h] [ebp-30h] BYREF
  Vector newValue; // [esp+34h] [ebp-1Ch]
  float v88; // [esp+40h] [ebp-10h] BYREF
  int nKeyIndex; // [esp+44h] [ebp-Ch]
  float flTimeRange; // [esp+48h] [ebp-8h]
  int nKeyCount; // [esp+4Ch] [ebp-4h]
  float flScale; // [esp+5Ch] [ebp+Ch]

  v4 = 0;
  if ( pDmeTypedLogDst != nullptr )
  {
    v5 = dmeTimeEnd->m_tms - dmeTimeStart->m_tms;
    if ( (float)((float)v5 * 0.000099999997) > 0.0 && (float)((float)dmeTimeStart->m_tms * 0.000099999997) <= 0.0 )
    {
      flTimeRange = (float)v5 * 0.000099999997;
      nKeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLogDst);
      if ( nKeyCount > 0 )
      {
        memset(&times, 0, sizeof(times));
        memset(&values, 0, sizeof(values));
        do
        {
          nKeyIndex = (int)pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &v88, a3: v4);
          m_Size = times.m_Size;
          v7 = times.m_Size;
          if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
              num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
            m_Size = times.m_Size;
          }
          m_pMemory = times.m_Memory.m_pMemory;
          times.m_Size = m_Size + 1;
          v9 = m_Size - v7;
          times.m_pElements = times.m_Memory.m_pMemory;
          if ( v9 > 0 )
          {
            _V_memmove(dest: &times.m_Memory.m_pMemory[v7 + 1], src: &times.m_Memory.m_pMemory[v7], count: 4 * v9);
            m_pMemory = times.m_Memory.m_pMemory;
          }
          v10 = &m_pMemory[v7];
          if ( v10 != nullptr )
            v10->m_tms = *(int *)nKeyIndex;
          KeyValue = (const QAngle *)CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&values,
            elem: values.m_Size,
            src: KeyValue);
          ++v4;
        }
        while ( v4 < nKeyCount );
        v12 = values.m_Memory.m_pMemory;
        v13 = times.m_Memory.m_pMemory;
        v14 = nKeyCount;
        v15 = values.m_Memory.m_pMemory[nKeyCount - 1].x - values.m_Memory.m_pMemory->x;
        v16 = values.m_Memory.m_pMemory[nKeyCount - 1].y - values.m_Memory.m_pMemory->y;
        v17 = values.m_Memory.m_pMemory[nKeyCount - 1].z - values.m_Memory.m_pMemory->z;
        if ( (float)((float)dmeTimeStart->m_tms * 0.000099999997) < 0.0 )
        {
          v18 = dmeTimeStart->m_tms + times.m_Memory.m_pMemory[nKeyCount - 1].m_tms;
          v19 = 0;
          if ( nKeyCount >= 4 )
          {
            LODWORD(v88) = nKeyCount - 3;
            v20 = 0;
            do
            {
              m_tms = v13[v19].m_tms;
              if ( m_tms >= v18 )
              {
                LODWORD(v22) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(m_tms - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(m_tms - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                p_x = &v12[v20].x;
                v24 = (float)(v22 * v15) + v12[v20].x;
                v25 = (float)(v22 * v16) + v12[v20].y;
                v26 = (float)(v22 * v17) + v12[v20].z;
                *p_x = v24;
                p_x[1] = v25;
                p_x[2] = v26;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v27 = v13[v19 + 1].m_tms;
              if ( v27 >= v18 )
              {
                LODWORD(v28) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v27 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v27 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v29 = &v12[v20 + 1].x;
                v30 = (float)(v28 * v15) + *v29;
                v31 = (float)(v28 * v16) + v12[v20 + 1].y;
                v32 = (float)(v28 * v17) + v12[v20 + 1].z;
                *v29 = v30;
                v29[1] = v31;
                v29[2] = v32;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v33 = v13[v19 + 2].m_tms;
              if ( v33 >= v18 )
              {
                LODWORD(v34) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v33 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v33 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v35 = &v12[v20 + 2].x;
                v36 = (float)(v34 * v15) + *v35;
                v37 = (float)(v34 * v16) + v12[v20 + 2].y;
                v38 = (float)(v34 * v17) + v12[v20 + 2].z;
                *v35 = v36;
                v35[1] = v37;
                v35[2] = v38;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v39 = v13[v19 + 3].m_tms;
              if ( v39 >= v18 )
              {
                LODWORD(v40) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v39 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v39 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v41 = &v12[v20 + 3].x;
                v42 = (float)(v40 * v15) + *v41;
                v43 = (float)(v40 * v16) + v12[v20 + 3].y;
                v44 = (float)(v40 * v17) + v12[v20 + 3].z;
                *v41 = v42;
                v41[1] = v43;
                v41[2] = v44;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              v19 += 4;
              v20 += 4;
              nKeyIndex = v19;
            }
            while ( v19 < SLODWORD(v88) );
            v14 = nKeyCount;
          }
          if ( v19 < v14 )
          {
            v45 = v19;
            do
            {
              v46 = v13[v19].m_tms;
              if ( v46 >= v18 )
              {
                LODWORD(v47) = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange)
                                               * 3.0)
                                       * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange))
                               - (float)((float)((float)((float)((float)((float)(v46 - v18) * 0.000099999997)
                                                               / flTimeRange)
                                                       * 2.0)
                                               * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange))
                                       * (float)((float)((float)(v46 - v18) * 0.000099999997) / flTimeRange)))
                             ^ _mask__NegFloat_;
                v48 = &v12[v45].x;
                v49 = (float)(v47 * v15) + v12[v45].x;
                v50 = (float)(v47 * v16) + v12[v45].y;
                v51 = (float)(v47 * v17) + v12[v45].z;
                *v48 = v49;
                v48[1] = v50;
                v48[2] = v51;
                v12 = values.m_Memory.m_pMemory;
                v13 = times.m_Memory.m_pMemory;
              }
              ++v19;
              ++v45;
            }
            while ( v19 < nKeyCount );
          }
        }
        if ( (float)((float)dmeTimeEnd->m_tms * 0.000099999997) > 0.0 )
        {
          v52 = v13->m_tms;
          v53 = 0;
          if ( nKeyCount < 4 )
          {
LABEL_41:
            if ( v53 < nKeyCount )
            {
              v75 = v53;
              while ( 1 )
              {
                v76 = times.m_Memory.m_pMemory[v53].m_tms;
                if ( v76 > dmeTimeEnd->m_tms )
                  break;
                v77 = (float)((float)(v52 + dmeTimeEnd->m_tms - v76) * 0.000099999997) / flTimeRange;
                v78 = (float)((float)(v77 * 3.0) * v77) - (float)((float)((float)(v77 * 2.0) * v77) * v77);
                v79 = &v12[v75].x;
                newValue.x = (float)(v15 * v78) + v12[v75].x;
                newValue.y = (float)(v16 * v78) + v12[v75].y;
                v80 = (float)(v17 * v78) + v12[v75].z;
                ++v53;
                *v79 = newValue.x;
                ++v75;
                v79[1] = newValue.y;
                v79[2] = v80;
                if ( v53 >= nKeyCount )
                  break;
                v12 = values.m_Memory.m_pMemory;
              }
            }
          }
          else
          {
            v54 = 0;
            while ( 1 )
            {
              v55 = v13[v53].m_tms;
              if ( v55 > dmeTimeEnd->m_tms )
                break;
              flScale = 1.0 / flTimeRange;
              v56 = (float)((float)(v52 + dmeTimeEnd->m_tms - v55) * 0.000099999997) * (float)(1.0 / flTimeRange);
              v88 = (float)(v56 * 3.0) * v56;
              v57 = v88 - (float)((float)((float)(v56 * 2.0) * v56) * v56);
              v58 = &v12[v54].x;
              newValue.x = (float)(v15 * v57) + v12[v54].x;
              newValue.y = (float)(v16 * v57) + v12[v54].y;
              v59 = (float)(v17 * v57) + v12[v54].z;
              *v58 = newValue.x;
              v58[1] = newValue.y;
              v58[2] = v59;
              v60 = times.m_Memory.m_pMemory[v53 + 1].m_tms;
              if ( v60 > dmeTimeEnd->m_tms )
                break;
              v61 = (float)((float)(v52 + dmeTimeEnd->m_tms - v60) * 0.000099999997) * flScale;
              v88 = (float)(v61 * 3.0) * v61;
              v62 = v88 - (float)((float)((float)(v61 * 2.0) * v61) * v61);
              v63 = &values.m_Memory.m_pMemory[v54 + 1];
              newValue.x = (float)(v15 * v62) + v63->x;
              newValue.y = (float)(v16 * v62) + values.m_Memory.m_pMemory[v54 + 1].y;
              v64 = (float)(v17 * v62) + values.m_Memory.m_pMemory[v54 + 1].z;
              v63->x = newValue.x;
              v63->y = newValue.y;
              v63->z = v64;
              v65 = times.m_Memory.m_pMemory[v53 + 2].m_tms;
              if ( v65 > dmeTimeEnd->m_tms )
                break;
              v66 = (float)((float)(v52 + dmeTimeEnd->m_tms - v65) * 0.000099999997) * flScale;
              v88 = (float)(v66 * 3.0) * v66;
              v67 = v88 - (float)((float)((float)(v66 * 2.0) * v66) * v66);
              v68 = &values.m_Memory.m_pMemory[v54 + 2];
              newValue.x = (float)(v15 * v67) + v68->x;
              newValue.y = (float)(v16 * v67) + values.m_Memory.m_pMemory[v54 + 2].y;
              v69 = (float)(v17 * v67) + values.m_Memory.m_pMemory[v54 + 2].z;
              v68->x = newValue.x;
              v68->y = newValue.y;
              v68->z = v69;
              v70 = times.m_Memory.m_pMemory[v53 + 3].m_tms;
              if ( v70 > dmeTimeEnd->m_tms )
                break;
              v71 = (float)((float)(v52 + dmeTimeEnd->m_tms - v70) * 0.000099999997) * flScale;
              v88 = (float)(v71 * 3.0) * v71;
              v72 = v88 - (float)((float)((float)(v71 * 2.0) * v71) * v71);
              v73 = &values.m_Memory.m_pMemory[v54 + 3];
              newValue.x = (float)(v15 * v72) + v73->x;
              newValue.y = (float)(v16 * v72) + values.m_Memory.m_pMemory[v54 + 3].y;
              v74 = (float)(v17 * v72) + values.m_Memory.m_pMemory[v54 + 3].z;
              v73->x = newValue.x;
              v73->y = newValue.y;
              v73->z = v74;
              v12 = values.m_Memory.m_pMemory;
              v53 += 4;
              v54 += 4;
              if ( v53 >= nKeyCount - 3 )
                goto LABEL_41;
              v13 = times.m_Memory.m_pMemory;
            }
          }
        }
        v81 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
        v82 = (CDmeTypedLogLayer<Vector> *)v81;
        if ( v81 != nullptr && v81->IsA(this: v81, a2: CDmeTypedLogLayer<Vector>::m_classType) )
          CDmeTypedLogLayer<Vector>::SetAllKeys(this: v82, &times, &values);
        v83 = values.m_Memory.m_pMemory;
        values.m_Size = 0;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( values.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
            v83 = nullptr;
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        values.m_pElements = v83;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v83 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v83);
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        v84 = times.m_Memory.m_pMemory;
        times.m_Size = 0;
        if ( times.m_Memory.m_nGrowSize >= 0 )
        {
          if ( times.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
            v84 = nullptr;
            times.m_Memory.m_pMemory = nullptr;
          }
          times.m_Memory.m_nAllocationCount = 0;
        }
        times.m_pElements = v84;
        if ( times.m_Memory.m_nGrowSize >= 0 && v84 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v84);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9890
// Name: protected: void CDmeFixupLoop::Apply<class Quaternion>(class CDmeTypedLog<class Quaternion> __near *,class DmeTime_t const __near &,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::Apply<Quaternion>(
        CDmeFixupLoop *this,
        CDmeTypedLog<Quaternion> *pDmeTypedLogDst,
        const DmeTime_t *dmeTimeStart,
        const DmeTime_t *dmeTimeEnd)
{
  CDmeTypedLog<Quaternion> *v4; // esi
  int v5; // edi
  int v6; // eax
  int KeyCount; // ebx
  int m_Size; // eax
  int v9; // esi
  DmeTime_t *m_pMemory; // ecx
  int v11; // eax
  DmeTime_t *v12; // esi
  const Quaternion *KeyValue; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // esi
  int m_tms; // eax
  float v18; // xmm0_4
  int v19; // esi
  int v20; // ecx
  float v21; // xmm0_4
  int v22; // eax
  CDmeTypedLogLayer<Quaternion> *v23; // esi
  Quaternion *v24; // eax
  DmeTime_t *v25; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > values; // [esp+24h] [ebp-54h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+38h] [ebp-40h] BYREF
  Quaternion delta; // [esp+4Ch] [ebp-2Ch] BYREF
  Quaternion newValue; // [esp+5Ch] [ebp-1Ch] BYREF
  DmeTime_t v30; // [esp+6Ch] [ebp-Ch] BYREF
  DmeTime_t *v31; // [esp+70h] [ebp-8h]
  float flTimeRange; // [esp+74h] [ebp-4h]
  DmeTime_t dmeTimeBegin; // [esp+84h] [ebp+Ch]
  int dmeTimeBegina; // [esp+84h] [ebp+Ch]

  v4 = pDmeTypedLogDst;
  v5 = 0;
  if ( pDmeTypedLogDst != nullptr )
  {
    v6 = dmeTimeEnd->m_tms - dmeTimeStart->m_tms;
    if ( (float)((float)v6 * 0.000099999997) > 0.0 && (float)((float)dmeTimeStart->m_tms * 0.000099999997) <= 0.0 )
    {
      flTimeRange = (float)v6 * 0.000099999997;
      KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLogDst);
      if ( KeyCount > 0 )
      {
        memset(&times, 0, sizeof(times));
        memset(&values, 0, sizeof(values));
        do
        {
          v31 = v4->GetKeyTime(this: v4, result: &v30, a3: v5);
          m_Size = times.m_Size;
          v9 = times.m_Size;
          if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
              num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
            m_Size = times.m_Size;
          }
          m_pMemory = times.m_Memory.m_pMemory;
          times.m_Size = m_Size + 1;
          v11 = m_Size - v9;
          times.m_pElements = times.m_Memory.m_pMemory;
          if ( v11 > 0 )
          {
            _V_memmove(dest: &times.m_Memory.m_pMemory[v9 + 1], src: &times.m_Memory.m_pMemory[v9], count: 4 * v11);
            m_pMemory = times.m_Memory.m_pMemory;
          }
          v12 = &m_pMemory[v9];
          if ( v12 != nullptr )
            v12->m_tms = v31->m_tms;
          KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v5);
          CUtlVector<VertexLookup_t,CUtlMemory<VertexLookup_t,int>>::InsertBefore(
            this: &values,
            elem: values.m_Size,
            src: KeyValue);
          v4 = pDmeTypedLogDst;
          ++v5;
        }
        while ( v5 < KeyCount );
        v14 = 0;
        QuaternionMA(p: &values.m_Memory.m_pMemory[KeyCount - 1], s: -1.0, q: values.m_Memory.m_pMemory, qt: &delta);
        if ( (float)((float)dmeTimeStart->m_tms * 0.000099999997) < 0.0 )
        {
          v15 = dmeTimeStart->m_tms + times.m_Memory.m_pMemory[KeyCount - 1].m_tms;
          dmeTimeBegin.m_tms = v15;
          v16 = 0;
          do
          {
            m_tms = times.m_Memory.m_pMemory[v14].m_tms;
            if ( m_tms >= v15 )
            {
              v18 = (float)((float)(m_tms - v15) * 0.000099999997) / flTimeRange;
              QuaternionSM(
                s: COERCE_FLOAT(
                  COERCE_UNSIGNED_INT((float)((float)(v18 * 3.0) * v18) - (float)((float)((float)(v18 * 2.0) * v18) * v18))
                ^ _mask__NegFloat_),
                p: &delta,
                q: &values.m_Memory.m_pMemory[v16],
                qt: &newValue);
              v15 = dmeTimeBegin.m_tms;
              values.m_Memory.m_pMemory[v16] = newValue;
            }
            ++v14;
            ++v16;
          }
          while ( v14 < KeyCount );
          v4 = pDmeTypedLogDst;
          v14 = 0;
        }
        if ( (float)((float)dmeTimeEnd->m_tms * 0.000099999997) > 0.0 )
        {
          dmeTimeBegina = times.m_Memory.m_pMemory->m_tms;
          v19 = 0;
          do
          {
            v20 = times.m_Memory.m_pMemory[v14].m_tms;
            if ( v20 > dmeTimeEnd->m_tms )
              break;
            v21 = (float)((float)(dmeTimeBegina + dmeTimeEnd->m_tms - v20) * 0.000099999997) / flTimeRange;
            QuaternionSM(
              s: (float)((float)(v21 * 3.0) * v21) - (float)((float)((float)(v21 * 2.0) * v21) * v21),
              p: &delta,
              q: &values.m_Memory.m_pMemory[v19],
              qt: &newValue);
            values.m_Memory.m_pMemory[v19] = newValue;
            ++v14;
            ++v19;
          }
          while ( v14 < KeyCount );
          v4 = pDmeTypedLogDst;
        }
        v22 = (int)v4->AddNewLayer(this: v4);
        v23 = (CDmeTypedLogLayer<Quaternion> *)v22;
        if ( v22 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
               a1: v22,
               a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v23, &times, &values);
        }
        v24 = values.m_Memory.m_pMemory;
        values.m_Size = 0;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( values.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
            v24 = nullptr;
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        values.m_pElements = v24;
        if ( values.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v24 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
            values.m_Memory.m_pMemory = nullptr;
          }
          values.m_Memory.m_nAllocationCount = 0;
        }
        v25 = times.m_Memory.m_pMemory;
        times.m_Size = 0;
        if ( times.m_Memory.m_nGrowSize >= 0 )
        {
          if ( times.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
            v25 = nullptr;
            times.m_Memory.m_pMemory = nullptr;
          }
          times.m_Memory.m_nAllocationCount = 0;
        }
        times.m_pElements = v25;
        if ( times.m_Memory.m_nGrowSize >= 0 && v25 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9C50
// Name: protected: void CDmeSubtract::Subtract<class Vector>(class CDmeTypedLog<class Vector> __near *,class CDmeTypedLog<class Vector> const __near *,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract<Vector>(
        CDmeSubtract *this,
        CDmeTypedLog<Vector> *pDmeTypedLogDst,
        CDmeTypedLog<Vector> *pDmeTypedLogSrc,
        const DmeTime_t *dmeTimeSrc)
{
  int v4; // ebx
  int m_Size; // eax
  int v6; // esi
  DmeTime_t *m_pMemory; // ecx
  int v8; // eax
  DmeTime_t *v9; // eax
  CDmeSubtract_vtbl *v10; // esi
  const Vector *KeyValue; // eax
  int v12; // eax
  int v13; // esi
  Vector *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  CDmeLogLayer *v17; // eax
  CDmeTypedLogLayer<Vector> *v18; // esi
  Vector *v19; // eax
  DmeTime_t *v20; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > values; // [esp+20h] [ebp-30h] BYREF
  Vector valueDst; // [esp+34h] [ebp-1Ch] BYREF
  Vector valueSrc; // [esp+40h] [ebp-10h] BYREF
  CDmeSubtract *v25; // [esp+4Ch] [ebp-4h]

  v25 = this;
  v4 = 0;
  valueSrc = *CDmeTypedLog<Vector>::GetValue(this: pDmeTypedLogSrc, time: (DmeTime_t)dmeTimeSrc->m_tms);
  memset(&times, 0, sizeof(times));
  memset(&values, 0, sizeof(values));
  if ( CDmeLog::GetKeyCount(this: pDmeTypedLogDst) > 0 )
  {
    do
    {
      dmeTimeSrc = pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &pDmeTypedLogSrc, a3: v4);
      m_Size = times.m_Size;
      v6 = times.m_Size;
      if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
          num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
        m_Size = times.m_Size;
      }
      m_pMemory = times.m_Memory.m_pMemory;
      times.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      times.m_pElements = times.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &times.m_Memory.m_pMemory[v6 + 1], src: &times.m_Memory.m_pMemory[v6], count: 4 * v8);
        m_pMemory = times.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_tms = dmeTimeSrc->m_tms;
      v10 = v25->__vftable;
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
      v10->Subtract_2(this: v25, a2: &valueDst, a3: KeyValue, a4: &valueSrc);
      v12 = values.m_Size;
      v13 = values.m_Size;
      if ( values.m_Size + 1 > values.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&values,
          num: values.m_Size - values.m_Memory.m_nAllocationCount + 1);
        v12 = values.m_Size;
      }
      v14 = values.m_Memory.m_pMemory;
      values.m_Size = v12 + 1;
      v15 = v12 - v13;
      values.m_pElements = values.m_Memory.m_pMemory;
      if ( v15 > 0 )
      {
        _V_memmove(dest: &values.m_Memory.m_pMemory[v13 + 1], src: &values.m_Memory.m_pMemory[v13], count: 12 * v15);
        v14 = values.m_Memory.m_pMemory;
      }
      v16 = &v14[v13];
      if ( v16 != nullptr )
        *v16 = valueDst;
      ++v4;
    }
    while ( v4 < CDmeLog::GetKeyCount(this: pDmeTypedLogDst) );
  }
  v17 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
  v18 = (CDmeTypedLogLayer<Vector> *)v17;
  if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmeTypedLogLayer<Vector>::m_classType) )
    CDmeTypedLogLayer<Vector>::SetAllKeys(this: v18, &times, &values);
  v19 = values.m_Memory.m_pMemory;
  values.m_Size = 0;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( values.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
      v19 = nullptr;
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  values.m_pElements = v19;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  v20 = times.m_Memory.m_pMemory;
  times.m_Size = 0;
  if ( times.m_Memory.m_nGrowSize >= 0 )
  {
    if ( times.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
      v20 = nullptr;
      times.m_Memory.m_pMemory = nullptr;
    }
    times.m_Memory.m_nAllocationCount = 0;
  }
  times.m_pElements = v20;
  if ( times.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x004E9E80
// Name: protected: void CDmeSubtract::Subtract<class Quaternion>(class CDmeTypedLog<class Quaternion> __near *,class CDmeTypedLog<class Quaternion> const __near *,class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::Subtract<Quaternion>(
        CDmeSubtract *this,
        CDmeTypedLog<Quaternion> *pDmeTypedLogDst,
        CDmeTypedLog<Quaternion> *pDmeTypedLogSrc,
        const DmeTime_t *dmeTimeSrc)
{
  int v4; // ebx
  int m_Size; // eax
  int v6; // esi
  DmeTime_t *m_pMemory; // ecx
  int v8; // eax
  DmeTime_t *v9; // eax
  CDmeSubtract_vtbl *v10; // esi
  const Quaternion *KeyValue; // eax
  int v12; // eax
  int v13; // esi
  Quaternion *v14; // ecx
  int v15; // eax
  Quaternion *v16; // esi
  CDmeLogLayer *v17; // eax
  CDmeTypedLogLayer<Quaternion> *v18; // esi
  Quaternion *v19; // eax
  DmeTime_t *v20; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > times; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > values; // [esp+20h] [ebp-38h] BYREF
  Quaternion valueDst; // [esp+34h] [ebp-24h] BYREF
  Quaternion valueSrc; // [esp+44h] [ebp-14h] BYREF
  CDmeSubtract *v25; // [esp+54h] [ebp-4h]

  v25 = this;
  v4 = 0;
  valueSrc = *CDmeTypedLog<Quaternion>::GetValue(this: pDmeTypedLogSrc, time: (DmeTime_t)dmeTimeSrc->m_tms);
  memset(&times, 0, sizeof(times));
  memset(&values, 0, sizeof(values));
  if ( CDmeLog::GetKeyCount(this: pDmeTypedLogDst) > 0 )
  {
    do
    {
      dmeTimeSrc = pDmeTypedLogDst->GetKeyTime(this: pDmeTypedLogDst, result: &pDmeTypedLogSrc, a3: v4);
      m_Size = times.m_Size;
      v6 = times.m_Size;
      if ( times.m_Size + 1 > times.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&times,
          num: times.m_Size - times.m_Memory.m_nAllocationCount + 1);
        m_Size = times.m_Size;
      }
      m_pMemory = times.m_Memory.m_pMemory;
      times.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      times.m_pElements = times.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &times.m_Memory.m_pMemory[v6 + 1], src: &times.m_Memory.m_pMemory[v6], count: 4 * v8);
        m_pMemory = times.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_tms = dmeTimeSrc->m_tms;
      v10 = v25->__vftable;
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLogDst, nKeyIndex: v4);
      v10->Subtract(this: v25, a2: &valueDst, a3: KeyValue, a4: &valueSrc);
      v12 = values.m_Size;
      v13 = values.m_Size;
      if ( values.m_Size + 1 > values.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&values,
          num: values.m_Size - values.m_Memory.m_nAllocationCount + 1);
        v12 = values.m_Size;
      }
      v14 = values.m_Memory.m_pMemory;
      values.m_Size = v12 + 1;
      v15 = v12 - v13;
      values.m_pElements = values.m_Memory.m_pMemory;
      if ( v15 > 0 )
      {
        _V_memmove(dest: &values.m_Memory.m_pMemory[v13 + 1], src: &values.m_Memory.m_pMemory[v13], count: 16 * v15);
        v14 = values.m_Memory.m_pMemory;
      }
      v16 = &v14[v13];
      if ( v16 != nullptr )
        *v16 = valueDst;
      ++v4;
    }
    while ( v4 < CDmeLog::GetKeyCount(this: pDmeTypedLogDst) );
  }
  v17 = pDmeTypedLogDst->AddNewLayer(this: pDmeTypedLogDst);
  v18 = (CDmeTypedLogLayer<Quaternion> *)v17;
  if ( v17 != nullptr && v17->IsA(this: v17, a2: CDmeTypedLogLayer<Quaternion>::m_classType) )
    CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v18, &times, &values);
  v19 = values.m_Memory.m_pMemory;
  values.m_Size = 0;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( values.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: values.m_Memory.m_pMemory);
      v19 = nullptr;
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  values.m_pElements = v19;
  if ( values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      values.m_Memory.m_pMemory = nullptr;
    }
    values.m_Memory.m_nAllocationCount = 0;
  }
  v20 = times.m_Memory.m_pMemory;
  times.m_Size = 0;
  if ( times.m_Memory.m_nGrowSize >= 0 )
  {
    if ( times.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
      v20 = nullptr;
      times.m_Memory.m_pMemory = nullptr;
    }
    times.m_Memory.m_nAllocationCount = 0;
  }
  times.m_pElements = v20;
  if ( times.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x004EA0B0
// Name: GetAllKeys_Vector_
// Source: json
//------------------------------------------------------------------------------
void __usercall GetAllKeys_Vector_(
        CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *keyTimes@<edi>,
        CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *keyValues@<esi>,
        CDmeTypedLog<Vector> *pDmeTypedLog)
{
  CDmeTypedLog<Vector> *v3; // ebx
  int KeyCount; // eax
  int v5; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  DmeTime_t *v10; // ebx
  const Vector *KeyValue; // eax
  int v12; // ebx
  int v13; // eax
  Vector *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  int *v17; // eoff
  DmeTime_t v18; // [esp+4h] [ebp-10h] BYREF
  int *v19; // [esp+8h] [ebp-Ch]
  int nKeyCount; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v3 = pDmeTypedLog;
  keyTimes->m_Storage.m_Size = 0;
  keyValues->m_Storage.m_Size = 0;
  KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLog);
  nKeyCount = KeyCount;
  if ( KeyCount > 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: keyTimes, num: KeyCount);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(this: keyValues, num: nKeyCount);
    i = 0;
    while ( 1 )
    {
      v5 = (int)v3->GetKeyTime(this: v3, result: &v18, a3: i);
      m_Size = keyTimes->m_Storage.m_Size;
      v19 = (int *)v5;
      m_nAllocationCount = keyTimes->m_Storage.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)keyTimes,
          num: m_Size - m_nAllocationCount + 1);
      ++keyTimes->m_Storage.m_Size;
      m_pMemory = keyTimes->m_Storage.m_Memory.m_pMemory;
      v9 = keyTimes->m_Storage.m_Size - m_Size - 1;
      keyTimes->m_Storage.m_pElements = keyTimes->m_Storage.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v10 = &keyTimes->m_Storage.m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        v10->m_tms = *v19;
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: pDmeTypedLog, nKeyIndex: i);
      v12 = keyValues->m_Storage.m_Size;
      v19 = (int *)KeyValue;
      v13 = keyValues->m_Storage.m_Memory.m_nAllocationCount;
      if ( v12 + 1 > v13 )
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)keyValues,
          num: v12 - v13 + 1);
      ++keyValues->m_Storage.m_Size;
      v14 = (Vector *)keyValues->m_Storage.m_Memory.m_pMemory;
      v15 = keyValues->m_Storage.m_Size - v12 - 1;
      keyValues->m_Storage.m_pElements = keyValues->m_Storage.m_Memory.m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 12 * v15);
      v16 = (Vector *)&keyValues->m_Storage.m_Memory.m_pMemory[v12];
      if ( v16 != nullptr )
      {
        v17 = v19;
        *(_QWORD *)&v16->x = *(_QWORD *)v19;
        LODWORD(v16->z) = v17[2];
      }
      if ( ++i >= nKeyCount )
        break;
      v3 = pDmeTypedLog;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EA200
// Name: GetAllKeys_Quaternion_
// Source: json
//------------------------------------------------------------------------------
void __usercall GetAllKeys_Quaternion_(
        CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *keyTimes@<esi>,
        CDmaArrayBase<Quaternion,CDmaDataInternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *keyValues,
        CDmeTypedLog<Quaternion> *pDmeTypedLog)
{
  CDmeTypedLog<Quaternion> *v4; // edi
  int KeyCount; // eax
  int v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmeTime_t *m_pMemory; // ecx
  int v10; // eax
  DmeTime_t *v11; // edi
  const Quaternion *KeyValue; // eax
  int v13; // edi
  int v14; // eax
  Quaternion *v15; // ecx
  int v16; // eax
  Quaternion *v17; // edi
  int *v18; // eax
  DmeTime_t v19; // [esp+8h] [ebp-Ch] BYREF
  int *v20; // [esp+Ch] [ebp-8h]
  int nKeyCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v4 = pDmeTypedLog;
  keyTimes->m_Storage.m_Size = 0;
  keyValues->m_Storage.m_Size = 0;
  KeyCount = CDmeLog::GetKeyCount(this: pDmeTypedLog);
  nKeyCount = KeyCount;
  if ( KeyCount > 0 )
  {
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: keyTimes, num: KeyCount);
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(this: keyValues, num: nKeyCount);
    i = 0;
    while ( 1 )
    {
      v6 = (int)v4->GetKeyTime(this: v4, result: &v19, a3: i);
      m_Size = keyTimes->m_Storage.m_Size;
      v20 = (int *)v6;
      m_nAllocationCount = keyTimes->m_Storage.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)keyTimes,
          num: m_Size - m_nAllocationCount + 1);
      ++keyTimes->m_Storage.m_Size;
      m_pMemory = keyTimes->m_Storage.m_Memory.m_pMemory;
      v10 = keyTimes->m_Storage.m_Size - m_Size - 1;
      keyTimes->m_Storage.m_pElements = keyTimes->m_Storage.m_Memory.m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &keyTimes->m_Storage.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        v11->m_tms = *v20;
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: pDmeTypedLog, nKeyIndex: i);
      v13 = keyValues->m_Storage.m_Size;
      v20 = (int *)KeyValue;
      v14 = keyValues->m_Storage.m_Memory.m_nAllocationCount;
      if ( v13 + 1 > v14 )
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)keyValues,
          num: v13 - v14 + 1);
      ++keyValues->m_Storage.m_Size;
      v15 = keyValues->m_Storage.m_Memory.m_pMemory;
      v16 = keyValues->m_Storage.m_Size - v13 - 1;
      keyValues->m_Storage.m_pElements = keyValues->m_Storage.m_Memory.m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &v15[v13 + 1], src: &v15[v13], count: 16 * v16);
      v17 = &keyValues->m_Storage.m_Memory.m_pMemory[v13];
      if ( v17 != nullptr )
      {
        v18 = v20;
        *(_QWORD *)&v17->x = *(_QWORD *)v20;
        *(_QWORD *)&v17->z = *((_QWORD *)v18 + 1);
      }
      if ( ++i >= nKeyCount )
        break;
      v4 = pDmeTypedLog;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EA3C0
// Name: public: virtual bool CDmeFixupLoop::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeFixupLoop::Apply(CDmeFixupLoop *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  const char *v3; // ecx
  CDmeSequence *v5; // esi
  const char *v6; // ecx
  CDmeChannelsClip *FrameCount; // eax
  int m_Storage; // esi
  int v9; // ecx
  int i; // edi
  int v11; // eax
  int v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v14; // esi
  CUtlString *v15; // eax
  CUtlString *v16; // eax
  const char *v17; // eax
  const char *v18; // [esp-8h] [ebp-4Ch] BYREF
  const char *TypeString; // [esp-4h] [ebp-48h]
  CUtlString v20; // [esp+Ch] [ebp-38h] BYREF
  CUtlString v21; // [esp+1Ch] [ebp-28h] BYREF
  DmeTime_t nStartTime; // [esp+2Ch] [ebp-18h] BYREF
  DmeTime_t nEndTime; // [esp+30h] [ebp-14h] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+34h] [ebp-10h] BYREF
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+38h] [ebp-Ch] BYREF
  CDmeFixupLoop *v26; // [esp+3Ch] [ebp-8h]
  DmeFramerate_t dmeFrameRateDst; // [esp+40h] [ebp-4h] BYREF
  bool pDmElement_3; // [esp+4Fh] [ebp+Bh]

  v26 = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v20, pDmElement: this);
  pDmElement_3 = ConvertToDmeSequenceAndDmeChannelsClip(
                   pDmElement,
                   sDmElementId: v2,
                   pDmeSequence: &pDmeSequenceDst,
                   pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v20.m_Storage.m_nActualLength = 0;
  if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 && v20.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
  if ( pDmElement_3 )
    return 0;
  TypeString = nullptr;
  v18 = v3;
  DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v18, fps: 0x1Eu);
  v5 = pDmeSequenceDst;
  CDmeSequence::GetFrameRate(
    this: pDmeSequenceDst,
    result: &dmeFrameRateDst,
    fallbackFrameRate: (DmeFramerate_t)v18,
    bForceFallback: (int)TypeString);
  TypeString = nullptr;
  v18 = v6;
  DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v18, fps: 0x1Eu);
  FrameCount = CDmeSequence::GetFrameCount(
                 this: v5,
                 fallbackFrameRate: (DmeFramerate_t)v18,
                 bForceFallback: (int)TypeString);
  m_Storage = v26->m_nEndFrame.m_Storage;
  v9 = v26->m_nStartFrame.m_Storage;
  if ( m_Storage - v9 > (int)FrameCount )
  {
    m_Storage = (int)FrameCount + v9;
    if ( (int)FrameCount + v9 < 0 )
    {
      m_Storage = 0;
      v9 = 1 - (_DWORD)FrameCount;
    }
  }
  DmeTime_t::DmeTime_t(this: &nStartTime, frame: v9, framerate: *(_DWORD *)&dmeFrameRateDst);
  DmeTime_t::DmeTime_t(this: &nEndTime, frame: m_Storage, framerate: *(_DWORD *)&dmeFrameRateDst);
  for ( i = 0; i < pDmeChannelsClipDst->m_Channels.m_Storage.m_Size; ++i )
  {
    v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: pDmeChannelsClipDst->m_Channels.m_Storage.m_Memory.m_pMemory[i]);
    v12 = v11;
    if ( v11 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
           a1: v11,
           a2: CDmeChannel::m_classType.u) != 0
      && v12 != 4 )
    {
      Log = CDmeChannel::GetLog(this: (CDmeChannel *)(v12 - 4));
      v14 = (CDmeTypedLog<Vector> *)Log;
      if ( Log != nullptr )
      {
        if ( Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) )
        {
          CDmeFixupLoop::Apply<Vector>(
            this: v26,
            pDmeTypedLogDst: v14,
            dmeTimeStart: &nStartTime,
            dmeTimeEnd: &nEndTime);
        }
        else if ( v14->IsA(this: v14, a2: CDmeTypedLog<Quaternion>::m_classType) )
        {
          CDmeFixupLoop::Apply<Quaternion>(
            this: v26,
            pDmeTypedLogDst: (CDmeTypedLog<Quaternion> *)v14,
            dmeTimeStart: &nStartTime,
            dmeTimeEnd: &nEndTime);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
        {
          TypeString = CDmElement::GetTypeString(this: v14);
          v15 = ComputeDmElementIdStr(result: &v20, pDmElement: pDmeSequenceDst);
          v18 = CUtlString::Get(this: v15);
          v16 = ComputeDmElementIdStr(result: &v21, pDmElement: v26);
          v17 = CUtlString::Get(this: v16);
          _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 1, a3: "%s: Unsupported DmeLog Type: \"%s\"\n", v17, v18);
          v21.m_Storage.m_nActualLength = 0;
          if ( v21.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v21.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21.m_Storage.m_Memory.m_pMemory);
              v21.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v21.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v20.m_Storage.m_nActualLength = 0;
          if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
              v20.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v20.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA650
// Name: public: virtual bool CDmeSubtract::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSubtract::Apply(CDmeSubtract *this, float pDmElement)
{
  CUtlString *v3; // edi
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeSequence *v6; // esi
  CUtlString *v7; // edi
  unsigned int v8; // ecx
  CDmeChannelsClip *v9; // edi
  DmeTime_t *StartTime; // eax
  __m128i v11; // xmm0
  CUtlSymbolLarge::<unnamed_type_u> v12; // eax
  float v13; // xmm0_4
  const char *m_Id; // esi
  CUtlString *v15; // eax
  CUtlString *v16; // eax
  const char *v17; // eax
  DmeTime_t *EndTime; // eax
  __m128i v19; // xmm0
  CUtlSymbolLarge::<unnamed_type_u> v20; // eax
  float v21; // xmm0_4
  const char *v22; // esi
  CUtlString *v23; // eax
  CUtlString *v24; // eax
  const char *v25; // eax
  CDmeChannelsClip *v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // esi
  int v30; // ebx
  CDmeLog *Log; // eax
  CDmeLog *v32; // esi
  char *v33; // ebx
  CDmeTypedLog<Vector> *v34; // edi
  CDmeTypedLog<Quaternion> *v35; // ebx
  int v36; // eax
  int v37; // esi
  CDmeChannel *v38; // esi
  const char *m_pAsString; // eax
  CDmeTypedLog<Vector> *v40; // esi
  CUtlString *v41; // eax
  CUtlString *v42; // eax
  const char *v43; // eax
  int m_Storage; // [esp+10h] [ebp-70h]
  int v45; // [esp+10h] [ebp-70h]
  double v46; // [esp+14h] [ebp-6Ch]
  double v47; // [esp+14h] [ebp-6Ch]
  double FramesPerSecond; // [esp+1Ch] [ebp-64h]
  double v49; // [esp+1Ch] [ebp-64h]
  const char *v50; // [esp+24h] [ebp-5Ch]
  const char *v51; // [esp+24h] [ebp-5Ch]
  double v52; // [esp+28h] [ebp-58h] BYREF
  CUtlString v53; // [esp+3Ch] [ebp-44h] BYREF
  CUtlString v54; // [esp+4Ch] [ebp-34h] BYREF
  DmeTime_t v55; // [esp+5Ch] [ebp-24h] BYREF
  int i; // [esp+60h] [ebp-20h]
  char *s1; // [esp+64h] [ebp-1Ch]
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+68h] [ebp-18h] BYREF
  CDmeSubtract *v59; // [esp+6Ch] [ebp-14h]
  DmeFramerate_t dmeFrameRateSrc; // [esp+70h] [ebp-10h] BYREF
  int j; // [esp+74h] [ebp-Ch] BYREF
  CDmeChannelsClip *pDmeChannelsClipSrc; // [esp+78h] [ebp-8h] BYREF
  DmeTime_t dmeTimeSrc; // [esp+7Ch] [ebp-4h] BYREF

  v59 = this;
  pDmeChannelsClipDst = nullptr;
  v3 = ComputeDmElementIdStr(result: &v53, pDmElement: this);
  HIBYTE(pDmElement) = ConvertToDmeSequenceAndDmeChannelsClip(
                         pDmElement: (CDmeSequence *)LODWORD(pDmElement),
                         sDmElementId: v3,
                         pDmeSequence: (CDmeSequence **)&pDmElement,
                         pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v53.m_Storage.m_nActualLength = 0;
  if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
  if ( HIBYTE(pDmElement) == 0 )
  {
    v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    HIDWORD(v52) = this->m_eSequence.m_Storage.m_Handle;
    j = 0;
    pDmeChannelsClipSrc = nullptr;
    v6 = (CDmeSequence *)((int (__thiscall *)(_DWORD, _DWORD))v5)(
                           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                           a2: HIDWORD(v52));
    v7 = ComputeDmElementIdStr(result: &v53, pDmElement: this);
    HIBYTE(pDmElement) = ConvertToDmeSequenceAndDmeChannelsClip(
                           pDmElement: v6,
                           sDmElementId: v7,
                           pDmeSequence: (CDmeSequence **)&j,
                           pDmeChannelsClip: &pDmeChannelsClipSrc) == 0;
    v53.m_Storage.m_nActualLength = 0;
    if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
    if ( HIBYTE(pDmElement) == 0 )
    {
      *(_QWORD *)&v52 = v8;
      DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&v52, fps: 0x1Eu);
      CDmeSequence::GetFrameRate(
        this: (CDmeSequence *)j,
        result: &dmeFrameRateSrc,
        fallbackFrameRate: LODWORD(v52),
        bForceFallback: SHIDWORD(v52));
      DmeTime_t::DmeTime_t(this: &dmeTimeSrc, frame: this->m_nFrame.m_Storage, framerate: *(_DWORD *)&dmeFrameRateSrc);
      v9 = pDmeChannelsClipSrc;
      StartTime = CDmeClip::GetStartTime(this: pDmeChannelsClipSrc, result: (DmeTime_t *)&pDmElement);
      if ( dmeTimeSrc.m_tms < StartTime->m_tms
        && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
      {
        v11 = _mm_cvtsi32_si128(CDmeClip::GetStartTime(this: v9, result: &v55)->m_tms);
        v12.m_Id = (int)this->m_nFrame.m_pAttribute->m_Name.u;
        v13 = _mm_cvtepi32_ps(v11).m128_f32[0] * 0.000099999997;
        pDmElement = (float)dmeTimeSrc.m_tms * 0.000099999997;
        m_Id = pDeltaStateName;
        if ( v12.m_Id != -1 )
          m_Id = (const char *)v12.m_Id;
        v52 = v13;
        v15 = ComputeDmElementIdStr(result: &v53, pDmElement: (const CDmElement *)j);
        v50 = CUtlString::Get(this: v15);
        FramesPerSecond = DmeFramerate_t::GetFramesPerSecond(this: &dmeFrameRateSrc);
        v46 = pDmElement;
        m_Storage = this->m_nFrame.m_Storage;
        v16 = ComputeDmElementIdStr(result: &v54, pDmElement: this);
        v17 = CUtlString::Get(this: v16);
        _LoggingSystem_Log(
          a1: LOG_DME_AAC,
          a2: 1,
          a3: "%s: .%s %d (%.2fs @ %g fps) < %s Start Time of %.2fs\n",
          v17,
          m_Id,
          m_Storage,
          v46,
          FramesPerSecond,
          v50,
          v52);
        v54.m_Storage.m_nActualLength = 0;
        if ( v54.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v54.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_Storage.m_Memory.m_pMemory);
            v54.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v54.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v53.m_Storage.m_nActualLength = 0;
        if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
      }
      EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&pDmElement);
      if ( dmeTimeSrc.m_tms > EndTime->m_tms
        && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
      {
        v19 = _mm_cvtsi32_si128(CDmeClip::GetEndTime(this: v9, result: &v55)->m_tms);
        v20.m_Id = (int)this->m_nFrame.m_pAttribute->m_Name.u;
        v21 = _mm_cvtepi32_ps(v19).m128_f32[0] * 0.000099999997;
        pDmElement = (float)dmeTimeSrc.m_tms * 0.000099999997;
        v22 = pDeltaStateName;
        if ( v20.m_Id != -1 )
          v22 = (const char *)v20.m_Id;
        v52 = v21;
        v23 = ComputeDmElementIdStr(result: &v53, pDmElement: (const CDmElement *)j);
        v51 = CUtlString::Get(this: v23);
        v49 = DmeFramerate_t::GetFramesPerSecond(this: &dmeFrameRateSrc);
        v47 = pDmElement;
        v45 = this->m_nFrame.m_Storage;
        v24 = ComputeDmElementIdStr(result: &v54, pDmElement: this);
        v25 = CUtlString::Get(this: v24);
        _LoggingSystem_Log(
          a1: LOG_DME_AAC,
          a2: 1,
          a3: "%s: .%s %d (%.2fs @ %g fps) > %s End Time of %.2fs\n",
          v25,
          v22,
          v45,
          v47,
          v49,
          v51,
          v52);
        v54.m_Storage.m_nActualLength = 0;
        if ( v54.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v54.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_Storage.m_Memory.m_pMemory);
            v54.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v54.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v53.m_Storage.m_nActualLength = 0;
        if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 && v53.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
      }
      v26 = pDmeChannelsClipDst;
      v27 = 0;
      i = 0;
      if ( pDmeChannelsClipDst->m_Channels.m_Storage.m_Size <= 0 )
        return 1;
      do
      {
        v28 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v26->m_Channels.m_Storage.m_Memory.m_pMemory[v27]);
        v29 = v28;
        if ( v28 == 0 )
          goto LABEL_66;
        if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v28 + 16))(
               a1: v28,
               a2: CDmeChannel::m_classType.u) == 0 )
          goto LABEL_66;
        v30 = v29 - 4;
        v55.m_tms = v29 - 4;
        if ( v29 == 4 )
          goto LABEL_66;
        Log = CDmeChannel::GetLog(this: (CDmeChannel *)(v29 - 4));
        v32 = Log;
        if ( Log == nullptr )
          goto LABEL_66;
        v33 = *(char **)(v30 + 24);
        s1 = (char *)pDeltaStateName;
        if ( v33 != (char *)-1 )
          s1 = v33;
        v34 = Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) ? (CDmeTypedLog<Vector> *)Log : nullptr;
        v35 = v32->IsA(this: v32, a2: CDmeTypedLog<Quaternion>::m_classType) ? (CDmeTypedLog<Quaternion> *)v32 : nullptr;
        HIBYTE(pDmElement) = 0;
        j = 0;
        if ( pDmeChannelsClipSrc->m_Channels.m_Storage.m_Size <= 0 )
        {
LABEL_56:
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
          {
            v41 = ComputeDmElementIdStr(result: &v53, pDmElement: (const CDmElement *)(v55.m_tms + 4));
            HIDWORD(v52) = CUtlString::Get(this: v41);
            v42 = ComputeDmElementIdStr(result: &v54, pDmElement: v59);
            v43 = CUtlString::Get(this: v42);
            _LoggingSystem_Log(
              a1: LOG_DME_AAC,
              a2: 1,
              a3: "%s: No Channel Found To Subtract From %s\n",
              v43,
              (const char *)HIDWORD(v52));
            v54.m_Storage.m_nActualLength = 0;
            if ( v54.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v54.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_Storage.m_Memory.m_pMemory);
                v54.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v54.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            v53.m_Storage.m_nActualLength = 0;
            if ( v53.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v53.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53.m_Storage.m_Memory.m_pMemory);
                v53.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v53.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
          goto LABEL_65;
        }
        do
        {
          v36 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: pDmeChannelsClipSrc->m_Channels.m_Storage.m_Memory.m_pMemory[j]);
          v37 = v36;
          if ( v36 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v36 + 16))(
                 a1: v36,
                 a2: CDmeChannel::m_classType.u) != 0 )
          {
            v38 = (CDmeChannel *)(v37 - 4);
            if ( v38 != nullptr )
            {
              m_pAsString = v38->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = pDeltaStateName;
              if ( _V_stricmp(s1, s2: m_pAsString) == 0 )
              {
                v40 = (CDmeTypedLog<Vector> *)CDmeChannel::GetLog(this: v38);
                if ( v40 != nullptr )
                {
                  if ( v40->IsA(this: v40, a2: CDmeTypedLog<Vector>::m_classType) && v34 != nullptr )
                  {
                    CDmeSubtract::Subtract<Vector>(this: v59, pDmeTypedLogDst: v34, pDmeTypedLogSrc: v40, &dmeTimeSrc);
LABEL_53:
                    HIBYTE(pDmElement) = 1;
                    goto LABEL_54;
                  }
                  if ( v40->IsA(this: v40, a2: CDmeTypedLog<Quaternion>::m_classType) && v35 != nullptr )
                  {
                    CDmeSubtract::Subtract<Quaternion>(
                      this: v59,
                      pDmeTypedLogDst: v35,
                      pDmeTypedLogSrc: (CDmeTypedLog<Quaternion> *)v40,
                      &dmeTimeSrc);
                    goto LABEL_53;
                  }
                }
              }
            }
          }
LABEL_54:
          ++j;
        }
        while ( j < pDmeChannelsClipSrc->m_Channels.m_Storage.m_Size );
        if ( HIBYTE(pDmElement) == 0 )
          goto LABEL_56;
LABEL_65:
        v27 = i;
LABEL_66:
        v26 = pDmeChannelsClipDst;
        i = ++v27;
      }
      while ( v27 < pDmeChannelsClipDst->m_Channels.m_Storage.m_Size );
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004EAC50
// Name: protected: void CDmeBoneMaskCmd::SubApply(class CDmeChannelsClip __near *,class CDmeDag __near *,class CDmeBoneMask __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskCmd::SubApply(
        CDmeBoneMaskCmd *this,
        CDmeTypedLog<Vector> *pDmeChannelsClip,
        CDmeTypedLog<Quaternion> *pDmeDag,
        float pDmeBoneMask)
{
  CDmeChannelsClip *v4; // edi
  CDmeDag *v5; // esi
  const char *m_pAsString; // eax
  double BoneWeight; // st7
  CUtlString *v8; // eax
  CUtlString *v9; // eax
  const char *v10; // eax
  float v11; // xmm3_4
  int v12; // ecx
  int v13; // edx
  Vector *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  int v17; // edi
  int v18; // esi
  int v19; // eax
  CDmeTypedLogLayer<Vector> *v20; // esi
  CUtlString *v21; // eax
  const char *v22; // eax
  int v23; // eax
  CDmeTypedLogLayer<Quaternion> *v24; // esi
  CUtlString *v25; // eax
  const char *v26; // eax
  const char *v27; // [esp+4h] [ebp-94h]
  CUtlString result; // [esp+14h] [ebp-84h] BYREF
  Quaternion qTmp; // [esp+24h] [ebp-74h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > qTimes; // [esp+34h] [ebp-64h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > vTimes; // [esp+48h] [ebp-50h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > vValues; // [esp+5Ch] [ebp-3Ch] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > qValues; // [esp+70h] [ebp-28h] BYREF
  CUtlString v34; // [esp+84h] [ebp-14h] BYREF
  CDmElement *pDmElement; // [esp+94h] [ebp-4h]

  v4 = (CDmeChannelsClip *)pDmeChannelsClip;
  pDmElement = this;
  if ( pDmeChannelsClip != nullptr )
  {
    v5 = (CDmeDag *)pDmeDag;
    if ( pDmeDag != nullptr && pDmeBoneMask != 0.0 )
    {
      m_pAsString = pDmeDag->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      BoneWeight = CDmeBoneMask::GetBoneWeight(this: (CDmeBoneMask *)LODWORD(pDmeBoneMask), pszBoneName: m_pAsString);
      pDmeBoneMask = BoneWeight;
      if ( BoneWeight != 1.0 && CDmeDag::GetTransform(this: v5) != nullptr )
      {
        pDmeChannelsClip = nullptr;
        pDmeDag = nullptr;
        if ( GetDmeChannelsForDag(
               pDmeTranslateLog: &pDmeChannelsClip,
               pDmeRotateLog: &pDmeDag,
               pDmeDag: v5,
               pDmeChannelsClip: v4) != 0 )
        {
          memset(&vTimes, 0, sizeof(vTimes));
          memset(&vValues, 0, sizeof(vValues));
          GetAllKeys_Vector_(
            keyTimes: (CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vTimes,
            keyValues: (CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *)&vValues,
            pDmeTypedLog: pDmeChannelsClip);
          v11 = pDmeBoneMask;
          v12 = 0;
          if ( vValues.m_Size > 0 )
          {
            v13 = 0;
            do
            {
              v14 = &vValues.m_Memory.m_pMemory[v13];
              v15 = vValues.m_Memory.m_pMemory[v13].y * v11;
              v16 = vValues.m_Memory.m_pMemory[v13].z * v11;
              ++v12;
              v14->x = vValues.m_Memory.m_pMemory[v13].x * v11;
              v14->y = v15;
              v14->z = v16;
              ++v13;
            }
            while ( v12 < vValues.m_Size );
          }
          memset(&qTimes, 0, sizeof(qTimes));
          memset(&qValues, 0, sizeof(qValues));
          GetAllKeys_Quaternion_(
            keyTimes: (CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&qTimes,
            keyValues: (CDmaArrayBase<Quaternion,CDmaDataInternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *)&qValues,
            pDmeTypedLog: pDmeDag);
          v17 = 0;
          if ( qValues.m_Size > 0 )
          {
            v18 = 0;
            do
            {
              QuaternionScale(p: &qValues.m_Memory.m_pMemory[v18], t: pDmeBoneMask, q: &qTmp);
              qValues.m_Memory.m_pMemory[v18] = qTmp;
              ++v17;
              ++v18;
            }
            while ( v17 < qValues.m_Size );
          }
          v19 = (int)pDmeChannelsClip->AddNewLayer(this: pDmeChannelsClip);
          v20 = (CDmeTypedLogLayer<Vector> *)v19;
          if ( v19 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v19 + 16))(
                 a1: v19,
                 a2: CDmeTypedLogLayer<Vector>::m_classType.u) != 0 )
          {
            CDmeTypedLogLayer<Vector>::SetAllKeys(this: v20, times: &vTimes, values: &vValues);
            v20->RemoveRedundantKeys_2(this: v20, a2: true);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
          {
            v21 = ComputeDmElementIdStr(result: &v34, pDmElement);
            v22 = CUtlString::Get(this: v21);
            _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Translate Layer\n", v22);
            v34.m_Storage.m_nActualLength = 0;
            if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
          }
          v23 = (int)pDmeDag->AddNewLayer(this: pDmeDag);
          v24 = (CDmeTypedLogLayer<Quaternion> *)v23;
          if ( v23 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v23 + 16))(
                 a1: v23,
                 a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
          {
            CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v24, times: &qTimes, values: &qValues);
            v24->RemoveRedundantKeys_2(this: v24, a2: true);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
          {
            v25 = ComputeDmElementIdStr(result: &v34, pDmElement);
            v26 = CUtlString::Get(this: v25);
            _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Rotate Layer\n", v26);
            v34.m_Storage.m_nActualLength = 0;
            if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
          }
          CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&qValues);
          CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&qTimes);
          CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vValues);
          CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vTimes);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
        {
          v8 = ComputeDmElementIdStr(&result, pDmElement: v5);
          v27 = CUtlString::Get(this: v8);
          v9 = ComputeDmElementIdStr(result: &v34, pDmElement);
          v10 = CUtlString::Get(this: v9);
          _LoggingSystem_Log(
            a1: LOG_DME_AAC,
            a2: 3,
            a3: "%s: Couldn't Find Translate & Rotate channels for DmeDag %s\n",
            v10,
            v27);
          CUtlString::~CUtlString(this: &v34);
          CUtlString::~CUtlString(this: &result);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EAFC0
// Name: public: virtual bool CDmeBoneMaskCmd::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeBoneMaskCmd::Apply(CDmeBoneMaskCmd *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  const CDmElement *v3; // esi
  CUtlString *v4; // eax
  CUtlString *v5; // eax
  CUtlString *v7; // eax
  CUtlString *v8; // eax
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  CDmeDag **v11; // eax
  CDmeDag *v12; // ebx
  int v13; // eax
  char *v14; // [esp-8h] [ebp-48h]
  char *v15; // [esp-8h] [ebp-48h]
  char *v16; // [esp-4h] [ebp-44h]
  char *v17; // [esp-4h] [ebp-44h]
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > depthFirstStack; // [esp+Ch] [ebp-34h] BYREF
  CUtlString v19; // [esp+20h] [ebp-20h] BYREF
  CDmeBoneMask *pDmeBoneMask; // [esp+30h] [ebp-10h]
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+34h] [ebp-Ch] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+38h] [ebp-8h] BYREF
  CDmElement *pDmElementa; // [esp+3Ch] [ebp-4h]
  int i; // [esp+48h] [ebp+8h]
  int ia; // [esp+48h] [ebp+8h]
  bool i_3; // [esp+4Bh] [ebp+Bh]

  pDmElementa = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v19, pDmElement: this);
  i_3 = ConvertToDmeSequenceAndDmeChannelsClip(
          pDmElement,
          sDmElementId: v2,
          pDmeSequence: &pDmeSequenceDst,
          pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v19.m_Storage.m_nActualLength = 0;
  if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
  if ( i_3 )
    return 0;
  v3 = pDmeSequenceDst;
  i = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
        a1: g_pDataModel.u,
        a2: pDmeSequenceDst->m_eSkeleton.m_Storage.m_Handle);
  if ( i == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v4 = ComputeDmElementIdStr(result: (CUtlString *)&depthFirstStack.m_Memory.m_nAllocationCount, pDmElement: v3);
      v16 = CUtlString::Get(this: v4);
      v5 = ComputeDmElementIdStr(result: &v19, pDmElement: pDmElementa);
      v14 = CUtlString::Get(this: v5);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No Skeleton\n", v14, v16);
LABEL_8:
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v19.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
          v19.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v19.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      depthFirstStack.m_pElements = nullptr;
      if ( depthFirstStack.m_Size >= 0 && depthFirstStack.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)depthFirstStack.m_Memory.m_nAllocationCount);
      return 0;
    }
    return 0;
  }
  pDmeBoneMask = (CDmeBoneMask *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: v3[6].m_pAttributes);
  if ( pDmeBoneMask == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v7 = ComputeDmElementIdStr(result: (CUtlString *)&depthFirstStack.m_Memory.m_nAllocationCount, pDmElement: v3);
      v17 = CUtlString::Get(this: v7);
      v8 = ComputeDmElementIdStr(result: &v19, pDmElement: pDmElementa);
      v15 = CUtlString::Get(this: v8);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No Bone Mask\n", v15, v17);
      goto LABEL_8;
    }
    return 0;
  }
  memset(&depthFirstStack, 0, sizeof(depthFirstStack));
  CUtlMemory<IDmFormatUpdater *,int>::Grow(
    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
    num: 1);
  m_pMemory = depthFirstStack.m_Memory.m_pMemory;
  m_Size = depthFirstStack.m_Size + 1;
  v11 = &depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size++];
  depthFirstStack.m_pElements = depthFirstStack.m_Memory.m_pMemory;
  if ( v11 != nullptr )
    *v11 = (CDmeDag *)i;
  while ( m_Size != 0 )
  {
    v12 = m_pMemory[--m_Size];
    depthFirstStack.m_Size = m_Size;
    if ( v12 != nullptr )
    {
      v13 = CDmElementFramework::GetPhase(this: v12) - 1;
      ia = v13;
      if ( v13 >= 0 )
      {
        while ( 1 )
        {
          pDmeSequenceDst = (CDmeSequence *)CDmeDag::GetChild(this: v12, i: v13);
          if ( m_Size >= depthFirstStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
              num: 1);
            m_Size = depthFirstStack.m_Size;
            m_pMemory = depthFirstStack.m_Memory.m_pMemory;
          }
          depthFirstStack.m_Size = ++m_Size;
          depthFirstStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = (CDmeDag *)pDmeSequenceDst;
          if ( --ia < 0 )
            break;
          v13 = ia;
        }
      }
      CDmeBoneMaskCmd::SubApply(
        this: (CDmeBoneMaskCmd *)pDmElementa,
        pDmeChannelsClip: (CDmeTypedLog<Vector> *)pDmeChannelsClipDst,
        pDmeDag: (CDmeTypedLog<Quaternion> *)v12,
        pDmeBoneMask: *(float *)&pDmeBoneMask);
    }
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&depthFirstStack);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB300
// Name: public: virtual bool CDmeAnimationAssemblyCommand::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationAssemblyCommand::IsA(CDmeAnimationAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB330
// Name: public: virtual int CDmeAnimationAssemblyCommand::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationAssemblyCommand::GetInheritanceDepth(
        CDmeAnimationAssemblyCommand *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB420
// Name: public: virtual bool CDmeFixupLoop::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFixupLoop::IsA(CDmeFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFixupLoop::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB460
// Name: public: virtual int CDmeFixupLoop::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFixupLoop::GetInheritanceDepth(CDmeFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFixupLoop::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB530
// Name: protected: virtual void CDmeFixupLoop::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFixupLoop::PerformConstruction(CDmeFixupLoop *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_nStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "startFrame",
                                       type: AT_INT,
                                       pMemory: &this->m_nStartFrame);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004EB600
// Name: public: virtual bool CDmeSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSubtract::IsA(CDmeSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB640
// Name: public: virtual int CDmeSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSubtract::GetInheritanceDepth(CDmeSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB710
// Name: protected: virtual void CDmeSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSubtract::PerformConstruction(CDmeSubtract *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_eSequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequence",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eSequence);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eSequence.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eSequence.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004EB800
// Name: public: virtual bool CDmePreSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePreSubtract::IsA(CDmePreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePreSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB840
// Name: public: virtual int CDmePreSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePreSubtract::GetInheritanceDepth(CDmePreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePreSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSubtract::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB930
// Name: protected: virtual void CDmePreSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmePreSubtract::PerformConstruction(CDmePreSubtract *this)
{
  CDmeSubtract::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EB9D0
// Name: public: virtual bool CDmeRotateTo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRotateTo::IsA(CDmeRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRotateTo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EBA10
// Name: public: virtual int CDmeRotateTo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRotateTo::GetInheritanceDepth(CDmeRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRotateTo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EBBB0
// Name: public: virtual bool CDmeBoneMaskCmd::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMaskCmd::IsA(CDmeBoneMaskCmd *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMaskCmd::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EBBF0
// Name: public: virtual int CDmeBoneMaskCmd::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMaskCmd::GetInheritanceDepth(CDmeBoneMaskCmd *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMaskCmd::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimationAssemblyCommand::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EBDA0
// Name: ComputeMergedKeyTimes
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeMergedKeyTimes(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *mergedTimes@<esi>,
        CDmeLog *pDmeLogA,
        CDmeLog *pDmeLogB)
{
  int v3; // ebx
  int v4; // eax
  CDmeLog *v5; // edi
  const DmeTime_t *v6; // eax
  unsigned __int16 v7; // dx
  int *v8; // ecx
  int m_pMemory; // edi
  DmeTime_t *p_m_Data; // ebx
  int m_nAllocationCount; // eax
  DmeTime_t *v12; // ecx
  int v13; // eax
  DmeTime_t *v14; // edi
  unsigned __int16 v15; // ax
  CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl*)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short> > timesTree; // [esp+8h] [ebp-24h] BYREF
  DmeTime_t v17; // [esp+24h] [ebp-8h] BYREF
  int i; // [esp+28h] [ebp-4h]

  v3 = 0;
  v4 = 0;
  mergedTimes[1].m_pMemory = nullptr;
  timesTree.m_LessFunc = (bool (__cdecl *)(const DmeTime_t *, const DmeTime_t *))CDefOps<DmeTime_t>::LessFunc;
  memset(&timesTree.m_Elements, 0, sizeof(timesTree.m_Elements));
  *(_DWORD *)&timesTree.m_Root = 0xFFFF;
  *(_DWORD *)&timesTree.m_FirstFree = -1;
  timesTree.m_pElements = nullptr;
  i = 0;
  while ( 1 )
  {
    v5 = pDmeLogA;
    if ( v4 != 0 )
      v5 = pDmeLogB;
    if ( v5 != nullptr && CDmeLog::GetKeyCount(this: v5) > 0 )
    {
      do
      {
        v6 = v5->GetKeyTime(this: v5, result: &v17, a3: v3);
        CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::InsertIfNotFound(
          this: &timesTree,
          insert: v6);
        ++v3;
      }
      while ( v3 < CDmeLog::GetKeyCount(this: v5) );
    }
    v4 = i + 1;
    i = v4;
    if ( v4 >= 2 )
      break;
    v3 = 0;
  }
  v7 = CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::FirstInorder(this: &timesTree);
  i = v7;
  while ( v7 < timesTree.m_Elements.m_nAllocationCount && v7 <= timesTree.m_LastAlloc.index )
  {
    if ( (`CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_3AE845C = 0x1FFFF;
    }
    v8 = v7 == 0xFFFF
       ? &`CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&timesTree.m_Elements.m_pMemory[v7];
    if ( *(_WORD *)v8 == v7 )
      break;
    m_pMemory = (int)mergedTimes[1].m_pMemory;
    p_m_Data = &timesTree.m_Elements.m_pMemory[v7].m_Data;
    m_nAllocationCount = mergedTimes->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: mergedTimes, num: m_pMemory - m_nAllocationCount + 1);
      v7 = i;
    }
    ++mergedTimes[1].m_pMemory;
    v12 = (DmeTime_t *)mergedTimes->m_pMemory;
    v13 = (int)mergedTimes[1].m_pMemory - m_pMemory - 1;
    mergedTimes[1].m_nAllocationCount = (int)mergedTimes->m_pMemory;
    if ( v13 > 0 )
    {
      _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 4 * v13);
      v7 = i;
    }
    v14 = (DmeTime_t *)&mergedTimes->m_pMemory[m_pMemory];
    if ( v14 != nullptr )
      v14->m_tms = p_m_Data->m_tms;
    v15 = CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::NextInorder(
            this: &timesTree,
            i: v7);
    i = v15;
    v7 = v15;
  }
  CUtlRBTree<DmeTime_t,unsigned short,bool (__cdecl *)(DmeTime_t const &,DmeTime_t const &),CUtlMemory<UtlRBTreeNode_t<DmeTime_t,unsigned short>,unsigned short>>::RemoveAll(this: &timesTree);
  if ( timesTree.m_Elements.m_nGrowSize >= 0 && timesTree.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: timesTree.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004EBF70
// Name: protected: void CDmeRotateTo::SubApply(class CDmeDag __near *,class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeRotateTo::SubApply(
        CDmeRotateTo *this,
        CDmeTypedLog<Quaternion> *pDmeDag,
        CDmeLog *pDmeChannelsClip,
        bool bZUp)
{
  CDmeDag *v4; // esi
  CDmeChannelsClip *v5; // edi
  CUtlString *v6; // eax
  CUtlString *v7; // eax
  const char *v8; // eax
  CDmeTypedLog<Vector> *v9; // edi
  const Vector *Value; // esi
  const Vector *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // xmm0_4
  float v16; // xmm1_4
  int v17; // xmm0_4
  int v18; // esi
  DmeTime_t *v19; // ebx
  const Quaternion *v20; // eax
  const Vector *v21; // eax
  int v22; // eax
  CDmeTypedLogLayer<Vector> *v23; // esi
  CUtlString *v24; // eax
  const char *v25; // eax
  int v26; // eax
  CDmeTypedLogLayer<Quaternion> *v27; // esi
  CUtlString *v28; // eax
  const char *v29; // eax
  const char *v30; // [esp-4h] [ebp-124h]
  long double v31; // [esp+0h] [ebp-120h]
  long double v32; // [esp+8h] [ebp-118h] OVERLAPPED BYREF
  matrix3x4_t mSrc; // [esp+3Ch] [ebp-E4h] BYREF
  matrix3x4_t mRoot; // [esp+6Ch] [ebp-B4h] BYREF
  Quaternion qTmp; // [esp+9Ch] [ebp-84h] BYREF
  Vector vTmp; // [esp+ACh] [ebp-74h] BYREF
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > qValues; // [esp+B8h] [ebp-68h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > vValues; // [esp+CCh] [ebp-54h] BYREF
  DmeTime_t dmeTimeEnd; // [esp+E0h] [ebp-40h] BYREF
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > mergedKeyTimes; // [esp+E4h] [ebp-3Ch] BYREF
  int flDeltaAngle; // [esp+F8h] [ebp-28h]
  CUtlString result; // [esp+FCh] [ebp-24h] BYREF
  CUtlString v43; // [esp+10Ch] [ebp-14h] BYREF
  CDmElement *pDmElement; // [esp+11Ch] [ebp-4h]

  v4 = (CDmeDag *)pDmeDag;
  pDmElement = this;
  if ( pDmeDag != nullptr )
  {
    v5 = (CDmeChannelsClip *)pDmeChannelsClip;
    if ( pDmeChannelsClip != nullptr && CDmeDag::GetTransform(this: (CDmeDag *)pDmeDag) != nullptr )
    {
      pDmeChannelsClip = nullptr;
      pDmeDag = nullptr;
      if ( GetDmeChannelsForDag(
             pDmeTranslateLog: (CDmeTypedLog<Vector> **)&pDmeChannelsClip,
             pDmeRotateLog: &pDmeDag,
             pDmeDag: v4,
             pDmeChannelsClip: v5) != 0 )
      {
        v9 = (CDmeTypedLog<Vector> *)pDmeChannelsClip;
        *(float *)&flDeltaAngle = 0.0;
        CDmeLog::GetBeginTime(this: pDmeChannelsClip, result: (DmeTime_t *)&pDmeChannelsClip);
        CDmeLog::GetEndTime(this: v9, result: &dmeTimeEnd);
        Value = CDmeTypedLog<Vector>::GetValue(this: v9, time: (DmeTime_t)pDmeChannelsClip);
        v11 = CDmeTypedLog<Vector>::GetValue(this: v9, time: dmeTimeEnd);
        v12 = v11->x - Value->x;
        v13 = v11->y - Value->y;
        if ( bZUp )
        {
          if ( v12 == 0.0 && v13 == 0.0 )
          {
            v43.m_Storage.m_Memory.m_nAllocationCount = 0;
            v43.m_Storage.m_Memory.m_nGrowSize = flDeltaAngle;
            v43.m_Storage.m_nActualLength = 0;
          }
          else
          {
            __libm_sse2_atan2(y: v31, x: v32);
            v14 = v13 * 57.29577951308232;
            *(float *)&v15 = *(float *)&pDmElement[1].__vftable - v14;
            v43.m_Storage.m_Memory.m_nAllocationCount = 0;
            v43.m_Storage.m_Memory.m_nGrowSize = v15;
            v43.m_Storage.m_nActualLength = 0;
          }
        }
        else
        {
          if ( v12 == 0.0 && (float)(v11->z - Value->z) == 0.0 )
          {
            v17 = flDeltaAngle;
          }
          else
          {
            __libm_sse2_atan2(y: v31, x: v32);
            v16 = v12 * 57.29577951308232;
            *(float *)&v17 = *(float *)&pDmElement[1].__vftable - v16;
          }
          v43.m_Storage.m_Memory.m_nAllocationCount = v17;
          v43.m_Storage.m_Memory.m_nGrowSize = 0;
          v43.m_Storage.m_nActualLength = 0;
        }
        AngleMatrix(angles: (const QAngle *)&v43.m_Storage.m_Memory.m_nAllocationCount, matrix: &mRoot);
        memset(&mergedKeyTimes, 0, sizeof(mergedKeyTimes));
        ComputeMergedKeyTimes(
          mergedTimes: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&mergedKeyTimes,
          pDmeLogA: v9,
          pDmeLogB: pDmeDag);
        v18 = 0;
        memset(&vValues, 0, sizeof(vValues));
        memset(&qValues, 0, sizeof(qValues));
        if ( mergedKeyTimes.m_Size > 0 )
        {
          do
          {
            v19 = &mergedKeyTimes.m_Memory.m_pMemory[v18];
            v20 = CDmeTypedLog<Quaternion>::GetValue(this: pDmeDag, time: (DmeTime_t)v19->m_tms);
            QuaternionAngles(q: v20, angles: (RadianEuler *)&v43.m_Storage.m_Memory.m_nAllocationCount);
            v21 = CDmeTypedLog<Vector>::GetValue(this: v9, time: (DmeTime_t)v19->m_tms);
            AngleMatrix(
              angles: (const RadianEuler *)&v43.m_Storage.m_Memory.m_nAllocationCount,
              position: v21,
              matrix: &mSrc);
            ConcatTransforms(in1: &mRoot, in2: &mSrc, out: (matrix3x4_t *)((char *)&v32 + 4));
            MatrixAngles(matrix: (const matrix3x4_t *)((char *)&v32 + 4), q: &qTmp, pos: &vTmp);
            CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
              this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&vValues,
              elem: vValues.m_Size,
              src: (const QAngle *)&vTmp);
            CUtlVector<VertexLookup_t,CUtlMemory<VertexLookup_t,int>>::InsertBefore(
              this: &qValues,
              elem: qValues.m_Size,
              src: &qTmp);
            ++v18;
          }
          while ( v18 < mergedKeyTimes.m_Size );
        }
        v22 = (int)v9->AddNewLayer(this: v9);
        v23 = (CDmeTypedLogLayer<Vector> *)v22;
        if ( v22 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
               a1: v22,
               a2: CDmeTypedLogLayer<Vector>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Vector>::SetAllKeys(this: v23, times: &mergedKeyTimes, values: &vValues);
          v23->RemoveRedundantKeys_2(this: v23, a2: true);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
        {
          v24 = ComputeDmElementIdStr(&result, pDmElement);
          v25 = CUtlString::Get(this: v24);
          _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Translate Layer\n", v25);
          result.m_Storage.m_nActualLength = 0;
          if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
        }
        v26 = (int)pDmeDag->AddNewLayer(this: pDmeDag);
        v27 = (CDmeTypedLogLayer<Quaternion> *)v26;
        if ( v26 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v26 + 16))(
               a1: v26,
               a2: CDmeTypedLogLayer<Quaternion>::m_classType.u) != 0 )
        {
          CDmeTypedLogLayer<Quaternion>::SetAllKeys(this: v27, times: &mergedKeyTimes, values: &qValues);
          v27->RemoveRedundantKeys_2(this: v27, a2: true);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
        {
          v28 = ComputeDmElementIdStr(&result, pDmElement);
          v29 = CUtlString::Get(this: v28);
          _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Couldn't Create Rotate Layer\n", v29);
          result.m_Storage.m_nActualLength = 0;
          if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
        }
        CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&qValues);
        CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vValues);
        CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&mergedKeyTimes);
      }
      else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
      {
        v6 = ComputeDmElementIdStr(&result, pDmElement: v4);
        v30 = CUtlString::Get(this: v6);
        v7 = ComputeDmElementIdStr(result: &v43, pDmElement);
        v8 = CUtlString::Get(this: v7);
        _LoggingSystem_Log(
          a1: LOG_DME_AAC,
          a2: 3,
          a3: "%s: Couldn't Find Translate & Rotate channels for DmeDag %s\n",
          v8,
          v30);
        v43.m_Storage.m_nActualLength = 0;
        if ( v43.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v43.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v43.m_Storage.m_Memory.m_pMemory);
            v43.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v43.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        result.m_Storage.m_nActualLength = 0;
        if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EC410
// Name: public: virtual bool CDmeRotateTo::Apply(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeRotateTo::Apply(CDmeRotateTo *this, CDmeSequence *pDmElement)
{
  CUtlString *v2; // edi
  CDmeSequence *v3; // edi
  int v4; // eax
  CDmeTypedLog<Quaternion> *v5; // esi
  CUtlString *v6; // eax
  CUtlString *v7; // eax
  const char *v8; // eax
  int v10; // edi
  CDmeChannelsClip *v11; // ebx
  CDmeTypedLog<Quaternion> *Child; // eax
  CUtlString *v13; // eax
  CUtlString *v14; // eax
  const char *v15; // eax
  const char *v16; // [esp-4h] [ebp-3Ch]
  bool IsZUp; // [esp-4h] [ebp-3Ch]
  const char *v18; // [esp-4h] [ebp-3Ch]
  CUtlString v19; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlString v20; // [esp+1Ch] [ebp-1Ch] BYREF
  CDmeSequence *pDmeSequenceDst; // [esp+2Ch] [ebp-Ch] BYREF
  CDmeChannelsClip *pDmeChannelsClipDst; // [esp+30h] [ebp-8h] BYREF
  CDmElement *v23; // [esp+34h] [ebp-4h]
  bool pDmElement_3; // [esp+43h] [ebp+Bh]

  v23 = this;
  pDmeSequenceDst = nullptr;
  pDmeChannelsClipDst = nullptr;
  v2 = ComputeDmElementIdStr(result: &v20, pDmElement: this);
  pDmElement_3 = ConvertToDmeSequenceAndDmeChannelsClip(
                   pDmElement,
                   sDmElementId: v2,
                   pDmeSequence: &pDmeSequenceDst,
                   pDmeChannelsClip: &pDmeChannelsClipDst) == 0;
  v20.m_Storage.m_nActualLength = 0;
  if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 && v20.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
  if ( pDmElement_3 )
    return 0;
  v3 = pDmeSequenceDst;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: pDmeSequenceDst->m_eSkeleton.m_Storage.m_Handle);
  v5 = (CDmeTypedLog<Quaternion> *)v4;
  if ( v4 == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 3) != 0 )
    {
      v6 = ComputeDmElementIdStr(result: &v19, pDmElement: v3);
      v16 = CUtlString::Get(this: v6);
      v7 = ComputeDmElementIdStr(result: &v20, pDmElement: v23);
      v8 = CUtlString::Get(this: v7);
      _LoggingSystem_Log(a1: LOG_DME_AAC, a2: 3, a3: "%s: Specified Sequence %s Has No Skeleton\n", v8, v16);
      v20.m_Storage.m_nActualLength = 0;
      if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
          v20.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v20.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
    }
    return 0;
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeModel::m_classType.u) == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DME_AAC, a2: 1) != 0 )
    {
      v13 = ComputeDmElementIdStr(result: &v19, pDmElement: v3);
      v18 = CUtlString::Get(this: v13);
      v14 = ComputeDmElementIdStr(result: &v20, pDmElement: v23);
      v15 = CUtlString::Get(this: v14);
      _LoggingSystem_Log(
        a1: LOG_DME_AAC,
        a2: 1,
        a3: "%s: Cannot Determine If Sequence %s Is Y Or Z Up, Assuming Z Up\n",
        v15,
        v18);
      v20.m_Storage.m_nActualLength = 0;
      if ( v20.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v20.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Storage.m_Memory.m_pMemory);
          v20.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v20.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
    }
    CDmeRotateTo::SubApply(
      this: (CDmeRotateTo *)v23,
      pDmeDag: v5,
      pDmeChannelsClip: (CDmeLog *)pDmeChannelsClipDst,
      bZUp: true);
    return 1;
  }
  v10 = 0;
  if ( CDmElementFramework::GetPhase(this: (CDmeDag *)v5) <= 0 )
    return 1;
  v11 = pDmeChannelsClipDst;
  do
  {
    IsZUp = CDmeModel::IsZUp(this: (CDmeModel *)v5);
    Child = (CDmeTypedLog<Quaternion> *)CDmeDag::GetChild(this: (CDmeDag *)v5, i: v10);
    CDmeRotateTo::SubApply(this: (CDmeRotateTo *)v23, pDmeDag: Child, pDmeChannelsClip: (CDmeLog *)v11, bZUp: IsZUp);
    ++v10;
  }
  while ( v10 < CDmElementFramework::GetPhase(this: (CDmeDag *)v5) );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E7EE0
// Name: _dynamic_initializer_for__CDmeAnimationAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationAssemblyCommand::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationAssemblyCommand pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7F40
// Name: _dynamic_initializer_for__CDmeFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFixupLoop::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFixupLoop pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7FA0
// Name: _dynamic_initializer_for__CDmeSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8000
// Name: _dynamic_initializer_for__CDmePreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePreSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePreSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePreSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8060
// Name: _dynamic_initializer_for__CDmeRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRotateTo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRotateTo::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRotateTo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E80C0
// Name: _dynamic_initializer_for__CDmeBoneMaskCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMaskCmd::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMaskCmd::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMaskCmd pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB480
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECA90
// Name: _dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationAssemblyCommand::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECAA0
// Name: _dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFixupLoop::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECAB0
// Name: _dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECAC0
// Name: _dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePreSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePreSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECAD0
// Name: _dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRotateTo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRotateTo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECAE0
// Name: _dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMaskCmd::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMaskCmd::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDD00
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x005E7F10
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7F20
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationAssemblyCommand_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationAssemblyCommand_Helper,
           classname: "DmeAnimationAssemblyCommand",
           pFactory: &g_CDmeAnimationAssemblyCommand_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7F70
// Name: _dynamic_initializer_for__g_CDmeFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFixupLoop_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7F80
// Name: _dynamic_initializer_for__g_CDmeFixupLoop_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFixupLoop_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFixupLoop_Helper,
           classname: "DmeFixupLoop",
           pFactory: &g_CDmeFixupLoop_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7FD0
// Name: _dynamic_initializer_for__g_CDmeSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7FE0
// Name: _dynamic_initializer_for__g_CDmeSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSubtract_Helper,
           classname: "DmeSubtract",
           pFactory: &g_CDmeSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E8030
// Name: _dynamic_initializer_for__g_CDmePreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePreSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8040
// Name: _dynamic_initializer_for__g_CDmePreSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePreSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePreSubtract_Helper,
           classname: "DmePreSubtract",
           pFactory: &g_CDmePreSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E8090
// Name: _dynamic_initializer_for__g_CDmeRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRotateTo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E80A0
// Name: _dynamic_initializer_for__g_CDmeRotateTo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRotateTo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRotateTo_Helper,
           classname: "DmeRotateTo",
           pFactory: &g_CDmeRotateTo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E80F0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMaskCmd_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8100
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmd_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMaskCmd_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMaskCmd_Helper,
           classname: "DmeBoneMaskCmd",
           pFactory: &g_CDmeBoneMaskCmd_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EB4B0
// Name: _dynamic_atexit_destructor_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExitStopper__()
{
  if ( g_bStopOnExit )
  {
    _Warning(a1: "\nPress any key to quit.\n");
    getch();
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EB4D0
// Name: _dynamic_atexit_destructor_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupFunctions__()
{
  CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::RemoveAll(this: &g_CleanupFunctions);
  if ( g_CleanupFunctions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_CleanupFunctions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CleanupFunctions.m_Memory.m_pMemory);
      g_CleanupFunctions.m_Memory.m_pMemory = nullptr;
    }
    g_CleanupFunctions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EB520
// Name: _CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&buf);
}

//------------------------------------------------------------------------------
// Address: 0x005EB530
// Name: _dynamic_atexit_destructor_for__g_JointedModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_JointedModel__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_JointedModel.m_mergeList);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_JointedModel.m_textCommands);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_JointedModel.m_bonemap);
}

//------------------------------------------------------------------------------
// Address: 0x005EB550
// Name: _dynamic_atexit_destructor_for__s_Balance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_Balance__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_Balance);
}

//------------------------------------------------------------------------------
// Address: 0x005EB560
// Name: _dynamic_atexit_destructor_for__s_Speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_Speed__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_Speed);
}

//------------------------------------------------------------------------------
// Address: 0x005EB570
// Name: _dynamic_atexit_destructor_for__s_UniqueVertices__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_UniqueVertices__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_UniqueVertices);
}

//------------------------------------------------------------------------------
// Address: 0x005EB580
// Name: _dynamic_atexit_destructor_for__s_UniqueVerticesMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_UniqueVerticesMap__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_UniqueVerticesMap);
}

//------------------------------------------------------------------------------
// Address: 0x005EB590
// Name: _dynamic_atexit_destructor_for__s_DeltaStates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DeltaStates__()
{
  CUtlVector<DeltaState_t,CUtlMemory<DeltaState_t,int>>::~CUtlVector<DeltaState_t,CUtlMemory<DeltaState_t,int>>(this: &s_DeltaStates);
}

//------------------------------------------------------------------------------
// Address: 0x005EB5A0
// Name: _dynamic_atexit_destructor_for__g_MtlLib__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MtlLib__()
{
  CUtlVector<MtlInfo_t,CUtlMemory<MtlInfo_t,int>>::~CUtlVector<MtlInfo_t,CUtlMemory<MtlInfo_t,int>>(this: &g_MtlLib);
}

//------------------------------------------------------------------------------
// Address: 0x005ECAF0
// Name: _dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFixupLoop_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFixupLoop_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB00
// Name: _dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSubtract_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB10
// Name: _dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePreSubtract_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePreSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB20
// Name: _dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRotateTo_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRotateTo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB30
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMaskCmd_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneMaskCmd_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB40
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationAssemblyCommand_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationAssemblyCommand_Factory.m_CallBackList);
}

} // namespace studiomdl
