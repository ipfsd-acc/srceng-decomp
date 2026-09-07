// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt_recv_eng.cpp
// Functions: 23
// ============================================================

#include "engine\dt_recv_eng.h"

//------------------------------------------------------------------------------
// Address: 0x10170500
// Name: public: char const __near * DVariant::ToString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DVariant::ToString(DVariant *this)
{
  const char *result; // eax

  switch ( this->m_Type )
  {
    case DPT_Int:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "%i", this->m_Int);
      goto LABEL_14;
    case DPT_Float:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "%.3f", this->m_Float);
      goto LABEL_4;
    case DPT_Vector:
      V_snprintf(
        pDest: `DVariant::ToString'::`2'::text,
        maxLen: 128,
        pFormat: "(%.3f,%.3f,%.3f)",
        this->m_Float,
        this->m_Vector[1],
        this->m_Vector[2]);
      return `DVariant::ToString'::`2'::text;
    case DPT_VectorXY:
      V_snprintf(
        pDest: `DVariant::ToString'::`2'::text,
        maxLen: 128,
        pFormat: "(%.3f,%.3f)",
        this->m_Float,
        this->m_Vector[1]);
      return `DVariant::ToString'::`2'::text;
    case DPT_String:
      result = (const char *)this->m_Int;
      if ( this->m_Int == 0 )
        return "NULL";
      return result;
    case DPT_Array:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "Array");
      goto LABEL_10;
    case DPT_DataTable:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "DataTable");
LABEL_10:
      result = `DVariant::ToString'::`2'::text;
      break;
    case DPT_Int64:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "%lld", this->m_Int64);
LABEL_4:
      result = `DVariant::ToString'::`2'::text;
      break;
    default:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "DVariant type %i unknown", this->m_Type);
LABEL_14:
      result = `DVariant::ToString'::`2'::text;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10170630
// Name: FindRecvProp
// Source: json
//------------------------------------------------------------------------------
RecvProp *__usercall FindRecvProp@<eax>(RecvTable *pTable@<edi>, const char *pName)
{
  int v2; // ebx
  RecvProp *v3; // esi
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  i = 0;
  if ( pTable->m_nProps <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = &pTable->m_pProps[v2];
    if ( _V_stricmp(s1: v3->m_pVarName, s2: pName) == 0 )
      break;
    ++v2;
    if ( ++i >= pTable->m_nProps )
      return nullptr;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10170680
// Name: bool CompareRecvPropToSendProp(class RecvProp const __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CompareRecvPropToSendProp(const RecvProp *pRecvProp, const SendProp *pSendProp)
{
  SendPropType m_RecvType; // eax

  while ( 1 )
  {
    if ( pRecvProp == nullptr || pSendProp == nullptr )
      _Error(a1: "CompareRecvPropToSendProp: missing a property.");
    m_RecvType = pRecvProp->m_RecvType;
    if ( m_RecvType != pSendProp->m_Type || pRecvProp->m_bInsideArray != (BYTE1(pSendProp->m_Flags) & 1) )
      break;
    if ( m_RecvType != DPT_Array )
      return 1;
    if ( pRecvProp->m_nElements != pSendProp->m_nElements )
      break;
    pRecvProp = pRecvProp->m_pArrayProp;
    pSendProp = pSendProp->m_pArrayProp;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10170730
// Name: class SendTable __near * RecvTable_ReadInfos(class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
SendTable *__cdecl RecvTable_ReadInfos(SendProp *pBuf, int nDemoProtocol)
{
  SendTable *v2; // eax
  int m_fHighValue_low; // ecx
  unsigned int m_fLowValue_low; // eax
  int v6; // edi
  int v7; // ecx
  const unsigned int *m_pArrayProp; // eax
  const unsigned int *m_ArrayLengthProxy; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // edi
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ebx
  int v16; // ecx
  int *v17; // eax
  int v18; // edi
  SendProp *v19; // ebx
  SendProp *v20; // eax
  int v21; // edi
  int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // edx
  const unsigned int *v27; // ecx
  const unsigned int *v28; // edx
  const unsigned int *v29; // edx
  unsigned int v30; // edi
  int v31; // eax
  const unsigned int *v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  int v35; // ecx
  int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // edi
  int v39; // edx
  unsigned int v40; // eax
  const unsigned int *v41; // eax
  const unsigned int *v42; // ecx
  const unsigned int *v43; // eax
  unsigned int v44; // edi
  int v45; // edx
  const unsigned int *v46; // ecx
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // ebx
  int v50; // ecx
  unsigned int v51; // eax
  char v52; // dl
  int v53; // ecx
  const unsigned int *v54; // ecx
  unsigned int v55; // ecx
  const unsigned int *v56; // edx
  unsigned int v57; // edi
  const unsigned int *v58; // ecx
  unsigned int v59; // edx
  unsigned int v60; // ebx
  unsigned int v61; // edx
  SendProp *v62; // edi
  SendPropType m_Type; // eax
  int v64; // ecx
  unsigned int v65; // eax
  int v66; // edi
  int v67; // ecx
  const unsigned int *v68; // eax
  const unsigned int *v69; // ecx
  const unsigned int *v70; // edx
  unsigned int v71; // edi
  int v72; // eax
  const unsigned int *v73; // ecx
  unsigned int v74; // edx
  unsigned int v75; // ebx
  unsigned int v76; // eax
  int v77; // ecx
  const unsigned int *v78; // ecx
  const unsigned int *v79; // edx
  const unsigned int *v80; // edx
  unsigned int v81; // edi
  int v82; // eax
  const unsigned int *v83; // ecx
  unsigned int v84; // edx
  unsigned int v85; // ebx
  int v86; // ecx
  unsigned int v87; // eax
  int v88; // ecx
  const unsigned int *v89; // ecx
  const unsigned int *v90; // edx
  const unsigned int *v91; // edx
  unsigned int v92; // edi
  int v93; // eax
  const unsigned int *v94; // ecx
  unsigned int v95; // edx
  unsigned int v96; // ebx
  int v97; // ecx
  unsigned int v98; // eax
  int v99; // edi
  int v100; // ecx
  const unsigned int *v101; // eax
  const unsigned int *v102; // ecx
  const unsigned int *v103; // edx
  unsigned int v104; // edi
  int v105; // eax
  const unsigned int *v106; // ecx
  unsigned int v107; // edx
  unsigned int v108; // ebx
  int iProp; // [esp+Ch] [ebp-Ch]
  int v111; // [esp+10h] [ebp-8h]
  int v112; // [esp+10h] [ebp-8h]
  SendTable *pTable; // [esp+14h] [ebp-4h]
  SendProp *pProp; // [esp+20h] [ebp+8h]
  SendProp *pPropa; // [esp+20h] [ebp+8h]

  v2 = (SendTable *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
    pTable = SendTable::SendTable(this: v2);
  else
    pTable = nullptr;
  pTable->m_pNetTableName = CBitRead::ReadAndAllocateString(this: (CBitRead *)pBuf, pOverflow: nullptr);
  m_fHighValue_low = LODWORD(pBuf->m_fHighValue);
  if ( m_fHighValue_low >= 10 )
  {
    m_fLowValue_low = LODWORD(pBuf->m_fLowValue);
    v6 = m_fLowValue_low & 0x3FF;
    v7 = m_fHighValue_low - 10;
    LODWORD(pBuf->m_fHighValue) = v7;
    if ( v7 != 0 )
    {
      LODWORD(pBuf->m_fLowValue) = m_fLowValue_low >> 10;
    }
    else
    {
      m_pArrayProp = (const unsigned int *)pBuf->m_pArrayProp;
      m_ArrayLengthProxy = (const unsigned int *)pBuf->m_ArrayLengthProxy;
      LODWORD(pBuf->m_fHighValue) = 32;
      if ( m_pArrayProp == m_ArrayLengthProxy )
      {
        LODWORD(pBuf->m_fHighValue) = 1;
        pBuf->m_fLowValue = 0.0;
        pBuf->m_pArrayProp = (SendProp *)(m_pArrayProp + 1);
      }
      else if ( m_pArrayProp <= m_ArrayLengthProxy )
      {
        LODWORD(pBuf->m_fLowValue) = *m_pArrayProp;
        pBuf->m_pArrayProp = (SendProp *)(m_pArrayProp + 1);
      }
      else
      {
        LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
        pBuf->m_fLowValue = 0.0;
      }
    }
    goto LABEL_21;
  }
  v10 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
  v11 = LODWORD(pBuf->m_fLowValue);
  v12 = 10 - m_fHighValue_low;
  v13 = (const unsigned int *)pBuf->m_pArrayProp;
  if ( v13 == v10 )
  {
    LODWORD(pBuf->m_fHighValue) = 1;
    pBuf->m_fLowValue = 0.0;
    LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
  }
  else
  {
    if ( v13 > v10 )
    {
      LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
      pBuf->m_fLowValue = 0.0;
      goto LABEL_18;
    }
    LODWORD(pBuf->m_fLowValue) = *v13;
  }
  pBuf->m_pArrayProp = (SendProp *)(v13 + 1);
LABEL_18:
  if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
  {
    v6 = 0;
  }
  else
  {
    v14 = LODWORD(pBuf->m_fLowValue);
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << LODWORD(pBuf->m_fHighValue);
    LODWORD(pBuf->m_fHighValue) = 32 - v12;
    v6 = v15 | v11;
    LODWORD(pBuf->m_fLowValue) = v14 >> v12;
  }
LABEL_21:
  pTable->m_nProps = v6;
  if ( v6 != 0
    && (v16 = (84 * (unsigned __int64)(unsigned int)v6) >> 32 != 0 ? -1 : 84 * v6,
        (v17 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v16, 4) ? -1 : v16 + 4)) != nullptr) )
  {
    *v17 = v6;
    v18 = v6 - 1;
    v19 = (SendProp *)(v17 + 1);
    for ( pProp = (SendProp *)(v17 + 1); v18 >= 0; --v18 )
      SendProp::SendProp(this: v19++);
    v20 = pProp;
  }
  else
  {
    v20 = nullptr;
  }
  pTable->m_pProps = v20;
  iProp = 0;
  if ( pTable->m_nProps > 0 )
  {
    while ( 1 )
    {
      v21 = (int)&pTable->m_pProps[iProp];
      v22 = LODWORD(pBuf->m_fHighValue);
      pPropa = (SendProp *)v21;
      if ( v22 >= 5 )
      {
        v23 = LODWORD(pBuf->m_fLowValue);
        v24 = v23 & 0x1F;
        v25 = v22 - 5;
        LODWORD(pBuf->m_fHighValue) = v25;
        if ( v25 != 0 )
        {
          v26 = v23 >> 5;
        }
        else
        {
          v27 = (const unsigned int *)pBuf->m_pArrayProp;
          v28 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
          LODWORD(pBuf->m_fHighValue) = 32;
          if ( v27 == v28 )
          {
            LODWORD(pBuf->m_fHighValue) = 1;
            pBuf->m_fLowValue = 0.0;
            pBuf->m_pArrayProp = (SendProp *)(v27 + 1);
            goto LABEL_46;
          }
          if ( v27 > v28 )
          {
            LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
            pBuf->m_fLowValue = 0.0;
            goto LABEL_46;
          }
          v26 = *v27;
          pBuf->m_pArrayProp = (SendProp *)(v27 + 1);
        }
        goto LABEL_45;
      }
      v29 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
      v30 = LODWORD(pBuf->m_fLowValue);
      v31 = 5 - v22;
      v32 = (const unsigned int *)pBuf->m_pArrayProp;
      if ( v32 == v29 )
        break;
      if ( v32 <= v29 )
      {
        LODWORD(pBuf->m_fLowValue) = *v32;
        goto LABEL_41;
      }
      LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
      pBuf->m_fLowValue = 0.0;
LABEL_42:
      if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
      {
        v21 = (int)pPropa;
        v24 = 0;
        goto LABEL_46;
      }
      v33 = LODWORD(pBuf->m_fLowValue);
      v34 = (v33 & CBitBuffer::s_nMaskTable[v31]) << LODWORD(pBuf->m_fHighValue);
      LODWORD(pBuf->m_fHighValue) = 32 - v31;
      v26 = v33 >> v31;
      v24 = v34 | v30;
      v21 = (int)pPropa;
LABEL_45:
      LODWORD(pBuf->m_fLowValue) = v26;
LABEL_46:
      *(_DWORD *)(v21 + 8) = v24;
      *(_DWORD *)(v21 + 48) = CBitRead::ReadAndAllocateString(this: (CBitRead *)pBuf, pOverflow: nullptr);
      v35 = 19;
      if ( nDemoProtocol == 2 )
        v35 = 11;
      v36 = LODWORD(pBuf->m_fHighValue);
      if ( v36 < v35 )
      {
        v43 = (const unsigned int *)pBuf->m_pArrayProp;
        v44 = LODWORD(pBuf->m_fLowValue);
        v45 = v35 - v36;
        v46 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        if ( v43 == v46 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_61;
        }
        if ( v43 <= v46 )
        {
          LODWORD(pBuf->m_fLowValue) = *v43;
LABEL_61:
          pBuf->m_pArrayProp = (SendProp *)(v43 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          v47 = 0;
          goto LABEL_67;
        }
        v48 = LODWORD(pBuf->m_fLowValue);
        v49 = (v48 & CBitBuffer::s_nMaskTable[v45]) << LODWORD(pBuf->m_fHighValue);
        LODWORD(pBuf->m_fHighValue) = 32 - v45;
        v38 = v49 | v44;
        v40 = v48 >> v45;
        goto LABEL_65;
      }
      v37 = LODWORD(pBuf->m_fLowValue);
      v38 = v37 & CBitBuffer::s_nMaskTable[v35];
      v39 = v36 - v35;
      LODWORD(pBuf->m_fHighValue) = v39;
      if ( v39 == 0 )
      {
        v41 = (const unsigned int *)pBuf->m_pArrayProp;
        v42 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        LODWORD(pBuf->m_fHighValue) = 32;
        if ( v41 == v42 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          pBuf->m_pArrayProp = (SendProp *)(v41 + 1);
        }
        else if ( v41 <= v42 )
        {
          LODWORD(pBuf->m_fLowValue) = *v41;
          pBuf->m_pArrayProp = (SendProp *)(v41 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        goto LABEL_66;
      }
      v40 = v37 >> v35;
LABEL_65:
      LODWORD(pBuf->m_fLowValue) = v40;
LABEL_66:
      v47 = v38;
LABEL_67:
      pPropa->m_Flags = v47;
      v50 = LODWORD(pBuf->m_fHighValue);
      if ( v50 < 8 )
      {
        v56 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        v57 = LODWORD(pBuf->m_fLowValue);
        v51 = 8 - v50;
        v58 = (const unsigned int *)pBuf->m_pArrayProp;
        if ( v58 == v56 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_81;
        }
        if ( v58 <= v56 )
        {
          LODWORD(pBuf->m_fLowValue) = *v58;
LABEL_81:
          pBuf->m_pArrayProp = (SendProp *)(v58 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          LOBYTE(v51) = 0;
        }
        else
        {
          v59 = LODWORD(pBuf->m_fLowValue);
          v60 = (v59 & CBitBuffer::s_nMaskTable[v51]) << LODWORD(pBuf->m_fHighValue);
          LODWORD(pBuf->m_fHighValue) = 32 - v51;
          v61 = v59 >> v51;
          LOBYTE(v51) = v60 | v57;
          LODWORD(pBuf->m_fLowValue) = v61;
        }
        goto LABEL_85;
      }
      v51 = LODWORD(pBuf->m_fLowValue);
      v52 = v51;
      v53 = v50 - 8;
      LODWORD(pBuf->m_fHighValue) = v53;
      if ( v53 != 0 )
      {
        LODWORD(pBuf->m_fLowValue) = v51 >> 8;
      }
      else
      {
        v51 = (unsigned int)pBuf->m_pArrayProp;
        v54 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        LODWORD(pBuf->m_fHighValue) = 32;
        if ( (const unsigned int *)v51 == v54 )
        {
          pBuf->m_pArrayProp = (SendProp *)(v51 + 4);
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(v51) = v52;
        }
        else
        {
          if ( v51 <= (unsigned int)v54 )
          {
            v55 = *(_DWORD *)v51;
            pBuf->m_pArrayProp = (SendProp *)(v51 + 4);
            LODWORD(pBuf->m_fLowValue) = v55;
          }
          else
          {
            LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
            pBuf->m_fLowValue = 0.0;
          }
          LOBYTE(v51) = v52;
        }
      }
LABEL_85:
      v62 = pPropa;
      pPropa->m_priority = v51;
      m_Type = pPropa->m_Type;
      if ( m_Type != DPT_DataTable && (pPropa->m_Flags & 0x40) == 0 )
      {
        v64 = LODWORD(pBuf->m_fHighValue);
        if ( m_Type == DPT_Array )
        {
          if ( v64 >= 10 )
          {
            v65 = LODWORD(pBuf->m_fLowValue);
            v66 = v65 & 0x3FF;
            v67 = v64 - 10;
            LODWORD(pBuf->m_fHighValue) = v67;
            if ( v67 != 0 )
            {
              LODWORD(pBuf->m_fLowValue) = v65 >> 10;
              pPropa->m_nElements = v66;
            }
            else
            {
              v68 = (const unsigned int *)pBuf->m_pArrayProp;
              v69 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
              LODWORD(pBuf->m_fHighValue) = 32;
              if ( v68 == v69 )
              {
                LODWORD(pBuf->m_fHighValue) = 1;
                pBuf->m_fLowValue = 0.0;
                pBuf->m_pArrayProp = (SendProp *)(v68 + 1);
                pPropa->m_nElements = v66;
              }
              else
              {
                if ( v68 <= v69 )
                {
                  LODWORD(pBuf->m_fLowValue) = *v68;
                  pBuf->m_pArrayProp = (SendProp *)(v68 + 1);
                }
                else
                {
                  LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
                  pBuf->m_fLowValue = 0.0;
                }
                pPropa->m_nElements = v66;
              }
            }
            goto LABEL_163;
          }
          v70 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
          v71 = LODWORD(pBuf->m_fLowValue);
          v72 = 10 - v64;
          v73 = (const unsigned int *)pBuf->m_pArrayProp;
          if ( v73 == v70 )
          {
            LODWORD(pBuf->m_fHighValue) = 1;
            pBuf->m_fLowValue = 0.0;
            LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
            goto LABEL_103;
          }
          if ( v73 <= v70 )
          {
            LODWORD(pBuf->m_fLowValue) = *v73;
LABEL_103:
            pBuf->m_pArrayProp = (SendProp *)(v73 + 1);
          }
          else
          {
            LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
            pBuf->m_fLowValue = 0.0;
          }
          if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
          {
            pPropa->m_nElements = 0;
          }
          else
          {
            v74 = LODWORD(pBuf->m_fLowValue);
            v75 = (v74 & CBitBuffer::s_nMaskTable[v72]) << LODWORD(pBuf->m_fHighValue);
            LODWORD(pBuf->m_fHighValue) = 32 - v72;
            LODWORD(pBuf->m_fLowValue) = v74 >> v72;
            pPropa->m_nElements = v75 | v71;
          }
          goto LABEL_163;
        }
        if ( v64 >= 32 )
        {
          v76 = LODWORD(pBuf->m_fLowValue);
          v77 = v64 - 32;
          LODWORD(pBuf->m_fHighValue) = v77;
          if ( v77 != 0 )
          {
            pBuf->m_fLowValue = 0.0;
            v111 = v76;
          }
          else
          {
            v78 = (const unsigned int *)pBuf->m_pArrayProp;
            v79 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
            LODWORD(pBuf->m_fHighValue) = 32;
            if ( v78 == v79 )
            {
              LODWORD(pBuf->m_fHighValue) = 1;
              pBuf->m_fLowValue = 0.0;
              pBuf->m_pArrayProp = (SendProp *)(v78 + 1);
              v111 = v76;
            }
            else
            {
              if ( v78 <= v79 )
              {
                LODWORD(pBuf->m_fLowValue) = *v78;
                pBuf->m_pArrayProp = (SendProp *)(v78 + 1);
              }
              else
              {
                LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
                pBuf->m_fLowValue = 0.0;
              }
              v111 = v76;
            }
          }
          goto LABEL_126;
        }
        v80 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        v81 = LODWORD(pBuf->m_fLowValue);
        v82 = 32 - v64;
        v83 = (const unsigned int *)pBuf->m_pArrayProp;
        if ( v83 == v80 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_121;
        }
        if ( v83 <= v80 )
        {
          LODWORD(pBuf->m_fLowValue) = *v83;
LABEL_121:
          pBuf->m_pArrayProp = (SendProp *)(v83 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          v111 = 0;
        }
        else
        {
          v84 = LODWORD(pBuf->m_fLowValue);
          v85 = (v84 & CBitBuffer::s_nMaskTable[v82]) << LODWORD(pBuf->m_fHighValue);
          LODWORD(pBuf->m_fHighValue) = 32 - v82;
          v111 = v85 | v81;
          LODWORD(pBuf->m_fLowValue) = v84 >> v82;
        }
        v62 = pPropa;
LABEL_126:
        LODWORD(v62->m_fLowValue) = v111;
        v86 = LODWORD(pBuf->m_fHighValue);
        if ( v86 >= 32 )
        {
          v87 = LODWORD(pBuf->m_fLowValue);
          v88 = v86 - 32;
          LODWORD(pBuf->m_fHighValue) = v88;
          if ( v88 != 0 )
          {
            pBuf->m_fLowValue = 0.0;
            v112 = v87;
          }
          else
          {
            v89 = (const unsigned int *)pBuf->m_pArrayProp;
            v90 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
            LODWORD(pBuf->m_fHighValue) = 32;
            if ( v89 == v90 )
            {
              LODWORD(pBuf->m_fHighValue) = 1;
              pBuf->m_fLowValue = 0.0;
              pBuf->m_pArrayProp = (SendProp *)(v89 + 1);
              v112 = v87;
            }
            else
            {
              if ( v89 <= v90 )
              {
                LODWORD(pBuf->m_fLowValue) = *v89;
                pBuf->m_pArrayProp = (SendProp *)(v89 + 1);
              }
              else
              {
                LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
                pBuf->m_fLowValue = 0.0;
              }
              v112 = v87;
            }
          }
          goto LABEL_145;
        }
        v91 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        v92 = LODWORD(pBuf->m_fLowValue);
        v93 = 32 - v86;
        v94 = (const unsigned int *)pBuf->m_pArrayProp;
        if ( v94 == v91 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_140;
        }
        if ( v94 <= v91 )
        {
          LODWORD(pBuf->m_fLowValue) = *v94;
LABEL_140:
          pBuf->m_pArrayProp = (SendProp *)(v94 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          v112 = 0;
        }
        else
        {
          v95 = LODWORD(pBuf->m_fLowValue);
          v96 = (v95 & CBitBuffer::s_nMaskTable[v93]) << LODWORD(pBuf->m_fHighValue);
          LODWORD(pBuf->m_fHighValue) = 32 - v93;
          v112 = v96 | v92;
          LODWORD(pBuf->m_fLowValue) = v95 >> v93;
        }
        v62 = pPropa;
LABEL_145:
        LODWORD(v62->m_fHighValue) = v112;
        v97 = LODWORD(pBuf->m_fHighValue);
        if ( v97 >= 7 )
        {
          v98 = LODWORD(pBuf->m_fLowValue);
          v99 = v98 & 0x7F;
          v100 = v97 - 7;
          LODWORD(pBuf->m_fHighValue) = v100;
          if ( v100 != 0 )
          {
            LODWORD(pBuf->m_fLowValue) = v98 >> 7;
          }
          else
          {
            v101 = (const unsigned int *)pBuf->m_pArrayProp;
            v102 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
            LODWORD(pBuf->m_fHighValue) = 32;
            if ( v101 == v102 )
            {
              LODWORD(pBuf->m_fHighValue) = 1;
              pBuf->m_fLowValue = 0.0;
              pBuf->m_pArrayProp = (SendProp *)(v101 + 1);
            }
            else if ( v101 <= v102 )
            {
              LODWORD(pBuf->m_fLowValue) = *v101;
              pBuf->m_pArrayProp = (SendProp *)(v101 + 1);
            }
            else
            {
              LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
              pBuf->m_fLowValue = 0.0;
            }
          }
LABEL_162:
          pPropa->m_nBits = v99;
          goto LABEL_163;
        }
        v103 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        v104 = LODWORD(pBuf->m_fLowValue);
        v105 = 7 - v97;
        v106 = (const unsigned int *)pBuf->m_pArrayProp;
        if ( v106 == v103 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_158;
        }
        if ( v106 <= v103 )
        {
          LODWORD(pBuf->m_fLowValue) = *v106;
LABEL_158:
          pBuf->m_pArrayProp = (SendProp *)(v106 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          v99 = 0;
        }
        else
        {
          v107 = LODWORD(pBuf->m_fLowValue);
          v108 = (v107 & CBitBuffer::s_nMaskTable[v105]) << LODWORD(pBuf->m_fHighValue);
          LODWORD(pBuf->m_fHighValue) = 32 - v105;
          v99 = v108 | v104;
          LODWORD(pBuf->m_fLowValue) = v107 >> v105;
        }
        goto LABEL_162;
      }
      pPropa->m_pExcludeDTName = CBitRead::ReadAndAllocateString(this: (CBitRead *)pBuf, pOverflow: nullptr);
LABEL_163:
      if ( ++iProp >= pTable->m_nProps )
        return pTable;
    }
    LODWORD(pBuf->m_fHighValue) = 1;
    pBuf->m_fLowValue = 0.0;
    LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
LABEL_41:
    pBuf->m_pArrayProp = (SendProp *)(v32 + 1);
    goto LABEL_42;
  }
  return pTable;
}

//------------------------------------------------------------------------------
// Address: 0x10170F60
// Name: void RecvTable_FreeSendTable(class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvTable_FreeSendTable(SendTable *pTable)
{
  int v1; // esi
  SendProp *m_pProps; // edi
  char *m_pExcludeDTName; // edi
  SendProp *v4; // ecx
  int iProp; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( iProp = 0; iProp < pTable->m_nProps; ++iProp )
  {
    m_pProps = pTable->m_pProps;
    free(pMem: pTable->m_pProps[v1].m_pVarName);
    m_pExcludeDTName = m_pProps[v1].m_pExcludeDTName;
    if ( m_pExcludeDTName != nullptr )
      free(pMem: m_pExcludeDTName);
    ++v1;
  }
  v4 = pTable->m_pProps;
  if ( pTable->m_pProps != nullptr )
  {
    if ( v4[-1].m_pExtraData != nullptr )
      ((void (__thiscall *)(SendProp *, int))v4->dtr_SendProp)(a1: v4, a2: 3);
    else
      free(pMem: &v4[-1].m_pExtraData);
  }
  free(pMem: pTable->m_pNetTableName);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)pTable);
  free(pMem: pTable);
}

//------------------------------------------------------------------------------
// Address: 0x10170FF0
// Name: bool RecvTable_RecvClassInfos(class bf_read __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RecvTable_RecvClassInfos(SendProp *pBuf, bool bNeedsDecoder, int nDemoProtocol)
{
  SendTable *Infos; // eax
  SendTable *v4; // esi
  char v6; // bl

  Infos = RecvTable_ReadInfos(pBuf, nDemoProtocol);
  v4 = Infos;
  if ( Infos == nullptr )
    return 0;
  v6 = DataTable_SetupReceiveTableFromSendTable(sendTable: Infos, bNeedsDecoder);
  RecvTable_FreeSendTable(pTable: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10171090
// Name: ShowDecodeDeltaWatchInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDecodeDeltaWatchInfo(
        char *what,
        const RecvTable *pTable,
        const SendProp *pProp,
        bf_read *buffer,
        int objectID,
        int index)
{
  int m_nDataBits; // esi
  SendPropType m_Type; // edx
  int v9; // ecx
  const char *v10; // edi
  const char *v11; // eax
  DecodeInfo info; // [esp+Ch] [ebp-25Ch] BYREF
  bf_read copy; // [esp+244h] [ebp-24h] BYREF
  int startBit; // [esp+278h] [ebp+10h]

  if ( ShouldWatchThisProp(pTable, objectID, pPropName: pProp->m_pVarName) != 0 )
  {
    if ( host_framecount != lastframe )
    {
      lastframe = host_framecount;
      _ConDMsg(a1: "D: delta entity: %i %s\n", objectID, pTable->m_pNetTableName);
    }
    copy = *buffer;
    m_nDataBits = 0;
    s_debug_info_shown = true;
    info.m_ObjectID = objectID;
    m_Type = pProp->m_Type;
    info.m_pStruct = nullptr;
    info.m_pData = nullptr;
    info.m_pRecvProp = nullptr;
    info.m_pProp = pProp;
    info.m_pIn = &copy;
    info.m_Value.m_Type = m_Type;
    if ( copy.m_pData != nullptr )
    {
      startBit = 32 * (copy.m_pDataIn - copy.m_pData) - copy.m_nBitsAvail + 8 * (copy.m_nDataBytes & 3);
      if ( startBit >= copy.m_nDataBits )
        startBit = copy.m_nDataBits;
    }
    else
    {
      startBit = 0;
    }
    (*(&funcs_1016CA94 + 9 * m_Type))(pInfo: &info);
    if ( copy.m_pData != nullptr )
    {
      m_nDataBits = copy.m_nDataBits;
      v9 = 32 * (copy.m_pDataIn - copy.m_pData) - copy.m_nBitsAvail;
      if ( v9 + 8 * (copy.m_nDataBytes & 3) < copy.m_nDataBits )
        m_nDataBits = v9 + 8 * (copy.m_nDataBytes & 3);
    }
    v10 = (*(&funcs_101711AD + 9 * pProp->m_Type))();
    v11 = DVariant::ToString(this: &info.m_Value);
    _ConDMsg(
      a1: "D[%s]:%s %s, %s, index %i, offset %i, bits %i, value %s\n",
      what,
      pTable->m_pNetTableName,
      pProp->m_pVarName,
      v10,
      index,
      startBit,
      m_nDataBits - startBit,
      v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101711F0
// Name: void RecvTable_DecodeZeros(class RecvTable __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvTable_DecodeZeros(RecvTable *pTable, unsigned __int8 *pStruct, int objectID)
{
  CRecvDecoder *m_pDecoder; // edi
  int i; // esi
  const RecvProp *v5; // ecx
  const SendProp **m_pMemory; // edx
  DecodeInfo decodeInfo; // [esp+Ch] [ebp-358h] BYREF
  CClientDatatableStack theStack; // [esp+244h] [ebp-120h] BYREF

  m_pDecoder = pTable->m_pDecoder;
  if ( m_pDecoder == nullptr )
    _Error(a1: "RecvTable_DecodeZeros: table '%s' missing a decoder.", pTable->m_pNetTableName);
  CDatatableStack::CDatatableStack(this: &theStack, pPrecalc: &m_pDecoder->m_Precalc, pStructBase: pStruct, objectID);
  theStack.__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
  theStack.m_pDecoder = m_pDecoder;
  CDatatableStack::Init(this: &theStack, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  for ( i = 0; i < m_pDecoder->m_Props.m_Size; ++i )
  {
    theStack.m_iCurProp = i;
    theStack.m_pCurProp = theStack.m_pPrecalc->m_Props.m_Memory.m_pMemory[i];
    v5 = m_pDecoder->m_Props.m_Memory.m_pMemory[i];
    decodeInfo.m_Value.m_Type = DPT_Float;
    decodeInfo.m_pStruct = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]];
    decodeInfo.m_pData = &theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]][v5->m_Offset];
    m_pMemory = m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory;
    decodeInfo.m_pRecvProp = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]] != nullptr
                           ? v5
                           : nullptr;
    decodeInfo.m_pProp = m_pMemory[i];
    decodeInfo.m_pIn = nullptr;
    decodeInfo.m_ObjectID = objectID;
    (*(&funcs_101712FA + 9 * v5->m_RecvType))(pInfo: &decodeInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171320
// Name: CopyPropState
// Source: json
//------------------------------------------------------------------------------
void __usercall CopyPropState(CRecvDecoder *pDecoder@<eax>, DVariant *pIn@<esi>, int iSendProp, CDeltaBitsWriter *pOut)
{
  const SendProp **m_pMemory; // ecx
  const unsigned int *v5; // eax
  signed int v6; // ebx
  const unsigned int *v7; // eax
  int v8; // edi
  int v9; // ecx
  const SendProp *v10; // [esp+0h] [ebp-8h]
  bf_write *v11; // [esp+4h] [ebp-4h]
  DVariant *savedregs; // [esp+8h] [ebp+0h]

  m_pMemory = pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory;
  v5 = (const unsigned int *)LODWORD(pIn[1].m_Vector[2]);
  if ( v5 != nullptr )
  {
    v6 = 32 * ((pIn[1].m_Int - (int)v5) >> 2) - *((_DWORD *)&pIn->m_Type + 1) + 8 * (*(_DWORD *)(&pIn->___u0 + 1) & 3);
    if ( v6 >= SLODWORD(pIn->m_Vector[2]) )
      v6 = LODWORD(pIn->m_Vector[2]);
  }
  else
  {
    v6 = 0;
  }
  ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B172[9 * m_pMemory[iSendProp]->m_Type])(
    pStruct: (const unsigned __int8 *)m_pMemory[iSendProp],
    pVar: pIn,
    pProp: v10,
    pOut: v11,
    objectID: savedregs);
  v7 = (const unsigned int *)LODWORD(pIn[1].m_Vector[2]);
  if ( v7 != nullptr )
  {
    v8 = LODWORD(pIn->m_Vector[2]);
    v9 = 32 * ((pIn[1].m_Int - (int)v7) >> 2) - *((_DWORD *)&pIn->m_Type + 1);
    if ( v9 + 8 * (*(_DWORD *)(&pIn->___u0 + 1) & 3) < v8 )
      v8 = v9 + 8 * (*(_DWORD *)(&pIn->___u0 + 1) & 3);
  }
  else
  {
    v8 = 0;
  }
  CBitRead::Seek(this: (CBitRead *)pIn, nPosition: v6);
  CDeltaBitsWriter::WritePropIndex(this: pOut, iProp: iSendProp);
  bf_write::WriteBitsFromBuffer(this: pOut->m_pBuf, (bf_read *)pIn, nBits: v8 - v6);
}

//------------------------------------------------------------------------------
// Address: 0x101713D0
// Name: int RecvTable_MergeDeltas(class RecvTable __near *,class bf_read __near *,class bf_read __near *,class bf_write __near *,int,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall RecvTable_MergeDeltas@<eax>(
        const SendProp *a1@<ebx>,
        RecvTable *pTable,
        bf_read *pOldState,
        bf_read *pNewState,
        bf_write *pOut,
        int objectID,
        bool bDebugWatchInfo,
        int *pChangedProps)
{
  bf_write *v8; // edi
  CRecvDecoder *m_pDecoder; // ebx
  bool v10; // al
  bf_read *v11; // esi
  int v12; // edi
  int v13; // eax
  const SendProp *v14; // edi
  int v15; // eax
  const SendProp *v17; // [esp-4h] [ebp-44h]
  bf_write *v18; // [esp+0h] [ebp-40h]
  DVariant *v19; // [esp+4h] [ebp-3Ch]
  CDeltaBitsReader newStateReader; // [esp+8h] [ebp-38h] BYREF
  CDeltaBitsReader oldStateReader; // [esp+18h] [ebp-28h] BYREF
  CDeltaBitsWriter deltaBitsWriter; // [esp+28h] [ebp-18h] BYREF
  int nChanged; // [esp+34h] [ebp-Ch]
  int iNewProp; // [esp+38h] [ebp-8h]
  bool bDebugWatch; // [esp+3Fh] [ebp-1h]

  if ( pTable == nullptr || pNewState == nullptr || (v8 = pOut, pOut == nullptr) )
  {
    _Error(a1: "RecvTable_MergeDeltas: invalid parameters passed.");
    v8 = pOut;
  }
  v17 = a1;
  m_pDecoder = pTable->m_pDecoder;
  if ( m_pDecoder == nullptr )
    _Error(a1: "RecvTable_MergeDeltas: table '%s' is missing its decoder.", pTable->m_pNetTableName);
  nChanged = 0;
  v10 = Sendprop_UsingDebugWatch();
  v11 = pOldState;
  s_debug_info_shown = false;
  s_debug_bits_start = v8->m_iCurBit;
  bDebugWatch = v10;
  CDeltaBitsReader::CDeltaBitsReader(this: &oldStateReader, pBuf: pOldState);
  CDeltaBitsReader::CDeltaBitsReader(this: &newStateReader, pBuf: pNewState);
  CDeltaBitsWriter::CDeltaBitsWriter(this: &deltaBitsWriter, pBuf: v8);
  v12 = 0x7FFFFFFF;
  if ( pOldState != nullptr )
  {
    v13 = CDeltaBitsReader::ReadNextPropIndex(this: &oldStateReader);
    if ( v13 >= 0 )
      v12 = v13;
  }
  iNewProp = CDeltaBitsReader::ReadNextPropIndex(this: &newStateReader);
  if ( iNewProp < 0 )
  {
LABEL_11:
    iNewProp = 0x7FFFFFFF;
    goto LABEL_12;
  }
  while ( 1 )
  {
LABEL_12:
    while ( v12 < iNewProp )
    {
      if ( bDebugWatch )
        ShowDecodeDeltaWatchInfo(
          what: "Old",
          pTable,
          pProp: m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v12],
          buffer: v11,
          objectID,
          index: v12);
      CopyPropState(pDecoder: m_pDecoder, pIn: (DVariant *)v11, iSendProp: v12, pOut: &deltaBitsWriter);
      v12 = CDeltaBitsReader::ReadNextPropIndex(this: &oldStateReader);
      if ( v12 < 0 )
        v12 = 0x7FFFFFFF;
      v11 = pOldState;
    }
    if ( iNewProp == 0x7FFFFFFF )
      break;
    if ( v12 == iNewProp )
    {
      if ( bDebugWatch )
        ShowDecodeDeltaWatchInfo(
          what: "Skip",
          pTable,
          pProp: m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v12],
          buffer: v11,
          objectID,
          index: v12);
      v14 = m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v12];
      ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B172[9 * v14->m_Type])(
        pStruct: (const unsigned __int8 *)v14,
        pVar: (DVariant *)v11,
        pProp: v17,
        pOut: v18,
        objectID: v19);
      v12 = CDeltaBitsReader::ReadNextPropIndex(this: &oldStateReader);
      if ( v12 < 0 )
        v12 = 0x7FFFFFFF;
    }
    if ( bDebugWatch )
      ShowDecodeDeltaWatchInfo(
        what: "New",
        pTable,
        pProp: m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[iNewProp],
        buffer: pNewState,
        objectID,
        index: iNewProp);
    CopyPropState(pDecoder: m_pDecoder, pIn: (DVariant *)pNewState, iSendProp: iNewProp, pOut: &deltaBitsWriter);
    if ( pChangedProps != nullptr )
      pChangedProps[nChanged] = iNewProp;
    ++nChanged;
    v15 = CDeltaBitsReader::ReadNextPropIndex(this: &newStateReader);
    v11 = pOldState;
    if ( v15 < 0 )
      goto LABEL_11;
    iNewProp = v15;
  }
  if ( v11 != nullptr && v11->m_bOverflow || pNewState->m_bOverflow || pOut->m_bOverflow )
    _Error(a1: "RecvTable_MergeDeltas: overflowed in RecvTable '%s'.", pTable->m_pNetTableName);
  if ( s_debug_info_shown )
    _ConDMsg(
      a1: "D= %i bits (%i bytes)\n",
      pOut->m_iCurBit - s_debug_bits_start,
      (pOut->m_iCurBit - s_debug_bits_start + 7) >> 3);
  CDeltaBitsWriter::~CDeltaBitsWriter(this: &deltaBitsWriter);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&newStateReader);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&oldStateReader);
  return nChanged;
}

//------------------------------------------------------------------------------
// Address: 0x10171630
// Name: bool RecvTable_Decode_Guts<1>(class RecvTable __near *,void __near *,class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RecvTable_Decode_Guts<1>(RecvTable *pTable, unsigned __int8 *pStruct, bf_read *pIn, int objectID)
{
  CRecvDecoder *m_pDecoder; // ebx
  const unsigned int *m_pData; // eax
  int v7; // edi
  const unsigned int *v8; // edx
  const RecvProp *v9; // ecx
  int m_nDataBits; // ebx
  int v11; // ebx
  const unsigned int *v12; // eax
  signed int v13; // edx
  bool m_bOverflow; // bl
  DecodeInfo decodeInfo; // [esp+Ch] [ebp-36Ch] BYREF
  CClientDatatableStack theStack; // [esp+244h] [ebp-134h] BYREF
  CDeltaBitsReader deltaBitsReader; // [esp+364h] [ebp-14h] BYREF
  CRecvDecoder *pDecoder; // [esp+374h] [ebp-4h]
  signed int iLastBit; // [esp+380h] [ebp+8h]
  int iStartBit; // [esp+388h] [ebp+10h]

  m_pDecoder = pTable->m_pDecoder;
  pDecoder = m_pDecoder;
  if ( m_pDecoder == nullptr )
    _Error(a1: "RecvTable_Decode: table '%s' missing a decoder.", pTable->m_pNetTableName);
  CDatatableStack::CDatatableStack(this: &theStack, pPrecalc: &m_pDecoder->m_Precalc, pStructBase: pStruct, objectID);
  theStack.__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
  theStack.m_pDecoder = m_pDecoder;
  CDatatableStack::Init(this: &theStack, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  m_pData = pIn->m_pData;
  if ( m_pData != nullptr )
  {
    iLastBit = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
    if ( iLastBit >= pIn->m_nDataBits )
      iLastBit = pIn->m_nDataBits;
  }
  else
  {
    iLastBit = 0;
  }
  CDeltaBitsReader::CDeltaBitsReader(this: &deltaBitsReader, pBuf: pIn);
  v7 = CDeltaBitsReader::ReadNextPropIndex(this: &deltaBitsReader);
  if ( v7 != -1 )
  {
    while ( 1 )
    {
      theStack.m_iCurProp = v7;
      theStack.m_pCurProp = theStack.m_pPrecalc->m_Props.m_Memory.m_pMemory[v7];
      v8 = pIn->m_pData;
      v9 = m_pDecoder->m_Props.m_Memory.m_pMemory[v7];
      if ( v8 == nullptr )
        break;
      v13 = 32 * (pIn->m_pDataIn - v8) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      m_nDataBits = pIn->m_nDataBits;
      if ( v13 >= m_nDataBits )
        goto LABEL_12;
      m_nDataBits = v13;
      iStartBit = v13;
LABEL_13:
      decodeInfo.m_Value.m_Type = DPT_Float;
      v11 = m_nDataBits - iLastBit;
      decodeInfo.m_pStruct = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]];
      decodeInfo.m_pData = &theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]][v9->m_Offset];
      decodeInfo.m_pRecvProp = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]] != nullptr
                             ? v9
                             : nullptr;
      decodeInfo.m_pProp = pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v7];
      decodeInfo.m_ObjectID = objectID;
      decodeInfo.m_pIn = pIn;
      (*(&funcs_1016CA94 + 9 * v9->m_RecvType))(pInfo: &decodeInfo);
      ++g_nPropsDecoded;
      v12 = pIn->m_pData;
      if ( v12 != nullptr )
      {
        iLastBit = 32 * (pIn->m_pDataIn - v12) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
        if ( iLastBit >= pIn->m_nDataBits )
          iLastBit = pIn->m_nDataBits;
      }
      else
      {
        iLastBit = 0;
      }
      if ( g_bDTIEnabled )
        _DTI_HookDeltaBits(pDecoder, iProp: v7, nDataBits: iLastBit - iStartBit, nIndexBits: v11);
      v7 = CDeltaBitsReader::ReadNextPropIndex(this: &deltaBitsReader);
      if ( v7 == -1 )
        goto LABEL_22;
      m_pDecoder = pDecoder;
    }
    m_nDataBits = 0;
LABEL_12:
    iStartBit = m_nDataBits;
    goto LABEL_13;
  }
LABEL_22:
  m_bOverflow = pIn->m_bOverflow;
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&deltaBitsReader);
  return !m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x10171850
// Name: bool RecvTable_Decode_Guts<0>(class RecvTable __near *,void __near *,class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RecvTable_Decode_Guts<0>(RecvTable *pTable, unsigned __int8 *pStruct, bf_read *pIn, int objectID)
{
  CRecvDecoder *m_pDecoder; // esi
  int i; // eax
  const RecvProp *v6; // edx
  bool m_bOverflow; // bl
  DecodeInfo decodeInfo; // [esp+Ch] [ebp-368h] BYREF
  CClientDatatableStack theStack; // [esp+244h] [ebp-130h] BYREF
  CDeltaBitsReader deltaBitsReader; // [esp+364h] [ebp-10h] BYREF

  m_pDecoder = pTable->m_pDecoder;
  if ( m_pDecoder == nullptr )
    _Error(a1: "RecvTable_Decode: table '%s' missing a decoder.", pTable->m_pNetTableName);
  CDatatableStack::CDatatableStack(this: &theStack, pPrecalc: &m_pDecoder->m_Precalc, pStructBase: pStruct, objectID);
  theStack.__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
  theStack.m_pDecoder = m_pDecoder;
  CDatatableStack::Init(this: &theStack, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  CDeltaBitsReader::CDeltaBitsReader(this: &deltaBitsReader, pBuf: pIn);
  for ( i = CDeltaBitsReader::ReadNextPropIndex(this: &deltaBitsReader);
        i != -1;
        i = CDeltaBitsReader::ReadNextPropIndex(this: &deltaBitsReader) )
  {
    theStack.m_iCurProp = i;
    theStack.m_pCurProp = theStack.m_pPrecalc->m_Props.m_Memory.m_pMemory[i];
    v6 = m_pDecoder->m_Props.m_Memory.m_pMemory[i];
    decodeInfo.m_Value.m_Type = DPT_Float;
    decodeInfo.m_pStruct = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]];
    decodeInfo.m_pData = &theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]][v6->m_Offset];
    decodeInfo.m_pRecvProp = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]] != nullptr
                           ? v6
                           : nullptr;
    decodeInfo.m_pProp = m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[i];
    decodeInfo.m_ObjectID = objectID;
    decodeInfo.m_pIn = pIn;
    (*(&funcs_1016CA94 + 9 * v6->m_RecvType))(pInfo: &decodeInfo);
    ++g_nPropsDecoded;
  }
  m_bOverflow = pIn->m_bOverflow;
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&deltaBitsReader);
  return !m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x10171EB0
// Name: class RecvTable __near * FindRecvTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
RecvTable *__cdecl FindRecvTable(const char *pName)
{
  int m_Next; // edi
  UtlLinkedListElem_t<RecvTable *,unsigned short> *m_pMemory; // eax
  int v3; // esi

  LOWORD(m_Next) = g_RecvTables.m_Head;
  if ( g_RecvTables.m_Head == 0xFFFF )
    return nullptr;
  m_pMemory = g_RecvTables.m_Memory.m_pMemory;
  while ( 1 )
  {
    v3 = (unsigned __int16)m_Next;
    if ( _V_stricmp(s1: m_pMemory[v3].m_Element->m_pNetTableName, s2: pName) == 0 )
      break;
    m_pMemory = g_RecvTables.m_Memory.m_pMemory;
    m_Next = g_RecvTables.m_Memory.m_pMemory[v3].m_Next;
    if ( m_Next == 0xFFFF )
      return nullptr;
  }
  return g_RecvTables.m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x10171F20
// Name: FindClientSendTable
// Source: json
//------------------------------------------------------------------------------
CClientSendTable *__cdecl FindClientSendTable(const char *pName)
{
  int m_Next; // eax
  UtlLinkedListElem_t<CClientSendTable *,unsigned short> *m_pMemory; // ecx
  int v3; // esi
  CClientSendTable *m_Element; // edi

  LOWORD(m_Next) = g_ClientSendTables.m_Head;
  if ( g_ClientSendTables.m_Head == 0xFFFF )
    return nullptr;
  m_pMemory = g_ClientSendTables.m_Memory.m_pMemory;
  while ( 1 )
  {
    v3 = (unsigned __int16)m_Next;
    m_Element = m_pMemory[v3].m_Element;
    if ( _V_stricmp(s1: m_Element->m_SendTable.m_pNetTableName, s2: pName) == 0 )
      break;
    m_pMemory = g_ClientSendTables.m_Memory.m_pMemory;
    m_Next = g_ClientSendTables.m_Memory.m_pMemory[v3].m_Next;
    if ( m_Next == 0xFFFF )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x10171F80
// Name: bool SetupClientSendTableHierarchy(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetupClientSendTableHierarchy()
{
  int v0; // eax
  UtlLinkedListElem_t<CClientSendTable *,unsigned short> *m_pMemory; // ecx
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // esi
  const char *v6; // eax
  CClientSendTable *ClientSendTable; // eax
  int v9; // [esp+Ch] [ebp-Ch]
  const char *pTableName; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  LOWORD(v0) = g_ClientSendTables.m_Head;
  if ( g_ClientSendTables.m_Head == 0xFFFF )
    return 1;
  m_pMemory = g_ClientSendTables.m_Memory.m_pMemory;
  while ( 1 )
  {
    v2 = 8 * (unsigned __int16)v0;
    v3 = *(int *)((char *)&m_pMemory->m_Element + v2);
    v4 = 0;
    v9 = v2;
    if ( *(int *)(v3 + 4) > 0 )
      break;
LABEL_12:
    v0 = *(unsigned __int16 *)((char *)&m_pMemory->m_Next + v2);
    if ( v0 == 0xFFFF )
      return 1;
  }
  v11 = 0;
  while ( 1 )
  {
    v5 = v11 + *(_DWORD *)v3;
    if ( *(_DWORD *)(v5 + 8) == 6 )
      break;
LABEL_10:
    v11 += 84;
    if ( ++v4 >= *(_DWORD *)(v3 + 4) )
    {
      m_pMemory = g_ClientSendTables.m_Memory.m_pMemory;
      goto LABEL_12;
    }
  }
  v6 = *(const char **)(*(_DWORD *)(v3 + 20) + 4 * v4);
  pTableName = v6;
  if ( v6 == nullptr )
  {
    _Error(a1: "SetupClientSendTableHierarchy: missing table name for prop '%s'.", *(const char **)(v5 + 48));
    v6 = nullptr;
  }
  ClientSendTable = FindClientSendTable(pName: v6);
  if ( ClientSendTable != nullptr )
  {
    *(_DWORD *)(v5 + 72) = ClientSendTable;
    v2 = v9;
    goto LABEL_10;
  }
  DataTable_Warning(
    pInMessage: "SetupClientSendTableHierarchy: missing SendTable '%s' (referenced by '%s').\n",
    pTableName,
    *(const char **)(v3 + 8));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10172050
// Name: bool RecvTable_Decode(class RecvTable __near *,void __near *,class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RecvTable_Decode(RecvTable *pTable, unsigned __int8 *pStruct, bf_read *pIn, int objectID)
{
  if ( g_bDTIEnabled )
    return RecvTable_Decode_Guts<1>(pTable, pStruct, pIn, objectID);
  else
    return RecvTable_Decode_Guts<0>(pTable, pStruct, pIn, objectID);
}

//------------------------------------------------------------------------------
// Address: 0x10172A00
// Name: MatchRecvPropsToSendProps_R
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatchRecvPropsToSendProps_R(
        CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl*)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short> > *lookup,
        const char *sendTableName,
        SendTable *pSendTable,
        RecvTable *pRecvTable)
{
  SendProp *v5; // esi
  const RecvProp *RecvProp; // eax
  RecvProp *v7; // edi
  MatchingProp_t info; // [esp+Ch] [ebp-Ch] BYREF
  int i; // [esp+14h] [ebp-4h]
  SendTable *pSendTablea; // [esp+28h] [ebp+10h]

  i = 0;
  if ( pSendTable->m_nProps <= 0 )
    return 1;
  for ( pSendTablea = nullptr; ; pSendTablea = (SendTable *)((char *)pSendTablea + 84) )
  {
    v5 = (SendProp *)((char *)pSendTablea + (unsigned int)pSendTable->m_pProps);
    if ( (v5->m_Flags & 0x40) == 0 && (v5->m_Flags & 0x100) == 0 )
    {
      if ( pRecvTable == nullptr )
        break;
      RecvProp = FindRecvProp(pTable: pRecvTable, pName: v5->m_pVarName);
      v7 = (RecvProp *)RecvProp;
      if ( RecvProp == nullptr )
        break;
      if ( CompareRecvPropToSendProp(pRecvProp: RecvProp, pSendProp: v5) == 0 )
      {
        _Warning(a1: "RecvProp type doesn't match server type for %s/%s\n", pSendTable->m_pNetTableName, v5->m_pVarName);
        return 0;
      }
      info.m_pProp = v5;
      info.m_pMatchingRecvProp = v7;
      CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl *)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>>::Insert(
        this: lookup,
        insert: &info);
      if ( v5->m_Type == DPT_DataTable
        && !MatchRecvPropsToSendProps_R(
              lookup,
              sendTableName,
              pSendTable: v5->m_pDataTable,
              pRecvTable: v7->m_pDataTable) )
      {
        return 0;
      }
    }
    if ( ++i >= pSendTable->m_nProps )
      return 1;
  }
  _Warning(a1: "Missing RecvProp for %s - %s/%s\n", sendTableName, pSendTable->m_pNetTableName, v5->m_pVarName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10172BA0
// Name: CopySendPropsToRecvProps
// Source: json
//------------------------------------------------------------------------------
void __usercall CopySendPropsToRecvProps(
        const CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int> > *sendProps@<edi>,
        CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl*)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short> > *lookup,
        CUtlVector<RecvProp const *,CUtlMemory<RecvProp const *,int> > *recvProps)
{
  int v3; // esi
  unsigned __int16 v4; // ax
  int m_Size; // [esp-4h] [ebp-14h]
  MatchingProp_t search; // [esp+8h] [ebp-8h] BYREF

  v3 = 0;
  m_Size = sendProps->m_Size;
  recvProps->m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)recvProps,
    elem: 0,
    num: m_Size);
  if ( sendProps->m_Size > 0 )
  {
    do
    {
      search.m_pProp = (SendProp *)sendProps->m_Memory.m_pMemory[v3];
      v4 = CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl *)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>>::Find(
             this: lookup,
             &search);
      if ( v4 == 0xFFFF )
        recvProps->m_Memory.m_pMemory[v3] = nullptr;
      else
        recvProps->m_Memory.m_pMemory[v3] = lookup->m_Elements.m_pMemory[v4].m_Data.m_pMatchingRecvProp;
      ++v3;
    }
    while ( v3 < sendProps->m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172C10
// Name: bool RecvTable_CreateDecoders(class CStandardSendProxies const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RecvTable_CreateDecoders()
{
  char result; // al
  int m_Next; // eax
  UtlLinkedListElem_t<CRecvDecoder *,unsigned short> *m_pMemory; // ecx
  int v3; // ebx
  CRecvDecoder *m_Element; // esi
  CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl*)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short> > PropLookup; // [esp+0h] [ebp-20h] BYREF
  bool bRet; // [esp+1Fh] [ebp-1h]

  DTI_Init();
  result = SetupClientSendTableHierarchy();
  if ( result != 0 )
  {
    LOWORD(m_Next) = g_RecvDecoders.m_Head;
    bRet = true;
    if ( g_RecvDecoders.m_Head == 0xFFFF )
    {
      return bRet;
    }
    else
    {
      m_pMemory = g_RecvDecoders.m_Memory.m_pMemory;
      while ( 1 )
      {
        v3 = (unsigned __int16)m_Next;
        m_Element = m_pMemory[v3].m_Element;
        if ( m_Element->m_pClientSendTable == nullptr
          || !CSendTablePrecalc::SetupFlatPropertyArray(this: &m_Element->m_Precalc) )
        {
          break;
        }
        PropLookup.m_LessFunc = (bool (__cdecl *)(const MatchingProp_t *, const MatchingProp_t *))CDmxSerializationDictionary::LessFunc;
        memset(&PropLookup.m_Elements, 0, sizeof(PropLookup.m_Elements));
        *(_DWORD *)&PropLookup.m_Root = 0xFFFF;
        *(_DWORD *)&PropLookup.m_FirstFree = -1;
        PropLookup.m_pElements = nullptr;
        if ( MatchRecvPropsToSendProps_R(
               lookup: &PropLookup,
               sendTableName: m_Element->m_Precalc.m_pSendTable->m_pNetTableName,
               pSendTable: m_Element->m_Precalc.m_pSendTable,
               pRecvTable: m_Element->m_pTable) != 0 )
        {
          CopySendPropsToRecvProps(
            sendProps: &m_Element->m_Precalc.m_Props,
            lookup: &PropLookup,
            recvProps: &m_Element->m_Props);
          CopySendPropsToRecvProps(
            sendProps: &m_Element->m_Precalc.m_DatatableProps,
            lookup: &PropLookup,
            recvProps: &m_Element->m_DatatableProps);
          DTI_HookRecvDecoder(pDecoder: m_Element);
        }
        else
        {
          bRet = false;
        }
        CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl *)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>>::~CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl *)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>>(this: &PropLookup);
        m_pMemory = g_RecvDecoders.m_Memory.m_pMemory;
        m_Next = g_RecvDecoders.m_Memory.m_pMemory[v3].m_Next;
        if ( m_Next == 0xFFFF )
          return bRet;
      }
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10172EA0
// Name: bool RecvTable_Init(class RecvTable __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RecvTable_Init(RecvTable **pTables, int nTables)
{
  int v2; // eax
  RecvTable *v3; // esi
  unsigned __int16 v4; // ax
  int v5; // edi
  UtlLinkedListElem_t<RecvTable *,unsigned short> *v6; // eax
  int v7; // ebx
  int v8; // edi
  int i; // [esp+0h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < nTables; i = v2 )
  {
    v3 = pTables[v2];
    if ( !v3->m_bInMainList )
    {
      if ( v3->m_pDecoder != nullptr )
        _Error(a1: "RecvTable_Init: table '%s' has a decoder already.", v3->m_pNetTableName);
      v3->m_bInMainList = true;
      v4 = CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal(
             this: &g_RecvTables,
             multilist: false);
      v5 = v4;
      if ( v4 != 0xFFFF )
      {
        CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
          this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvTables,
          before: 0xFFFFu,
          elem: v4);
        v6 = &g_RecvTables.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
          v6->m_Element = v3;
      }
      v7 = 0;
      if ( v3->m_nProps > 0 )
      {
        v8 = 0;
        do
        {
          if ( v3->m_pProps[v8].m_RecvType == DPT_DataTable )
            RecvTable_Init_::_4_::CPropVisitor::Visit_R(pTable: v3->m_pProps[v8].m_pDataTable);
          ++v7;
          ++v8;
        }
        while ( v7 < v3->m_nProps );
      }
    }
    v2 = i + 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10172F70
// Name: void RecvTable_Term(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvTable_Term(bool clearall)
{
  int m_Next; // eax
  int v2; // edi
  RecvTable *m_Element; // ecx
  int v4; // edx
  int v5; // esi
  UtlLinkedListElem_t<RecvTable *,unsigned short> *m_pMemory; // eax

  DTI_Term();
  LOWORD(m_Next) = g_RecvTables.m_Head;
  if ( g_RecvTables.m_Head != 0xFFFF )
  {
    do
    {
      v2 = (unsigned __int16)m_Next;
      m_Element = g_RecvTables.m_Memory.m_pMemory[v2].m_Element;
      if ( m_Element->m_bInMainList )
      {
        v4 = 0;
        v5 = 0;
        m_Element->m_bInMainList = false;
        for ( m_Element->m_pDecoder = nullptr; v5 < m_Element->m_nProps; ++v4 )
        {
          if ( m_Element->m_pProps[v4].m_RecvType == DPT_DataTable )
            RecvTable_Term_::_4_::CPropVisitor::Visit_R(pTable: m_Element->m_pProps[v4].m_pDataTable);
          ++v5;
        }
      }
      m_Next = g_RecvTables.m_Memory.m_pMemory[v2].m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  if ( clearall )
  {
    CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvTables);
    m_pMemory = g_RecvTables.m_Memory.m_pMemory;
    if ( g_RecvTables.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_RecvTables.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RecvTables.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_RecvTables.m_Memory.m_pMemory = nullptr;
      }
      g_RecvTables.m_Memory.m_nAllocationCount = 0;
    }
    g_RecvTables.m_FirstFree = -1;
    *(_DWORD *)&g_RecvTables.m_NumAlloced = -65536;
    g_RecvTables.m_pElements = m_pMemory;
  }
  CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_RecvDecoders);
  CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_ClientSendTables);
}

//------------------------------------------------------------------------------
// Address: 0x101706E0
// Name: _RecvTable_Term_::_4_::CPropVisitor::Visit_R
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl RecvTable_Term_::_4_::CPropVisitor::Visit_R(RecvTable *pTable)
{
  int v1; // ebx
  int v2; // edi

  v1 = 0;
  if ( pTable->m_bInMainList )
  {
    pTable->m_bInMainList = false;
    pTable->m_pDecoder = nullptr;
    if ( pTable->m_nProps > 0 )
    {
      v2 = 0;
      do
      {
        if ( pTable->m_pProps[v2].m_RecvType == DPT_DataTable )
          RecvTable_Term_::_4_::CPropVisitor::Visit_R(pTable: pTable->m_pProps[v2].m_pDataTable);
        ++v1;
        ++v2;
      }
      while ( v1 < pTable->m_nProps );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172B00
// Name: _RecvTable_Init_::_4_::CPropVisitor::Visit_R
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl RecvTable_Init_::_4_::CPropVisitor::Visit_R(RecvTable *pTable)
{
  unsigned __int16 v1; // ax
  int v2; // edi
  UtlLinkedListElem_t<RecvTable *,unsigned short> *v3; // eax
  int v4; // ebx
  int v5; // edi

  if ( !pTable->m_bInMainList )
  {
    if ( pTable->m_pDecoder != nullptr )
      _Error(a1: "RecvTable_Init: table '%s' has a decoder already.", pTable->m_pNetTableName);
    pTable->m_bInMainList = true;
    v1 = CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal(
           this: &g_RecvTables,
           multilist: false);
    v2 = v1;
    if ( v1 != 0xFFFF )
    {
      CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvTables,
        before: 0xFFFFu,
        elem: v1);
      v3 = &g_RecvTables.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
        v3->m_Element = pTable;
    }
    v4 = 0;
    if ( pTable->m_nProps > 0 )
    {
      v5 = 0;
      do
      {
        if ( pTable->m_pProps[v5].m_RecvType == DPT_DataTable )
          RecvTable_Init_::_4_::CPropVisitor::Visit_R(pTable: pTable->m_pProps[v5].m_pDataTable);
        ++v4;
        ++v5;
      }
      while ( v4 < pTable->m_nProps );
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101706C0
// Name: public: char const __near * DVariant::ToString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DVariant::ToString(DVariant *this)
{
  const char *result; // eax

  switch ( this->m_Type )
  {
    case DPT_Int:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "%i", this->m_Int);
      goto LABEL_14;
    case DPT_Float:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "%.3f", this->m_Float);
      goto LABEL_4;
    case DPT_Vector:
      V_snprintf(
        pDest: `DVariant::ToString'::`2'::text,
        maxLen: 128,
        pFormat: "(%.3f,%.3f,%.3f)",
        this->m_Float,
        this->m_Vector[1],
        this->m_Vector[2]);
      return `DVariant::ToString'::`2'::text;
    case DPT_VectorXY:
      V_snprintf(
        pDest: `DVariant::ToString'::`2'::text,
        maxLen: 128,
        pFormat: "(%.3f,%.3f)",
        this->m_Float,
        this->m_Vector[1]);
      return `DVariant::ToString'::`2'::text;
    case DPT_String:
      result = (const char *)this->m_Int;
      if ( this->m_Int == 0 )
        return "NULL";
      return result;
    case DPT_Array:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "Array");
      goto LABEL_10;
    case DPT_DataTable:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "DataTable");
LABEL_10:
      result = `DVariant::ToString'::`2'::text;
      break;
    case DPT_Int64:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "%lld", this->m_Int64);
LABEL_4:
      result = `DVariant::ToString'::`2'::text;
      break;
    default:
      V_snprintf(pDest: `DVariant::ToString'::`2'::text, maxLen: 128, pFormat: "DVariant type %i unknown", this->m_Type);
LABEL_14:
      result = `DVariant::ToString'::`2'::text;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101707F0
// Name: FindRecvProp
// Source: json
//------------------------------------------------------------------------------
RecvProp *__usercall FindRecvProp@<eax>(RecvTable *pTable@<edi>, const char *pName)
{
  int v2; // ebx
  RecvProp *v3; // esi
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  i = 0;
  if ( pTable->m_nProps <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = &pTable->m_pProps[v2];
    if ( _V_stricmp(s1: v3->m_pVarName, s2: pName) == 0 )
      break;
    ++v2;
    if ( ++i >= pTable->m_nProps )
      return nullptr;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10170840
// Name: bool CompareRecvPropToSendProp(class RecvProp const __near *,class SendProp const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CompareRecvPropToSendProp(const RecvProp *pRecvProp, const SendProp *pSendProp)
{
  SendPropType m_RecvType; // eax

  while ( 1 )
  {
    if ( pRecvProp == nullptr || pSendProp == nullptr )
      _Error(a1: "CompareRecvPropToSendProp: missing a property.");
    m_RecvType = pRecvProp->m_RecvType;
    if ( m_RecvType != pSendProp->m_Type || pRecvProp->m_bInsideArray != (BYTE1(pSendProp->m_Flags) & 1) )
      break;
    if ( m_RecvType != DPT_Array )
      return 1;
    if ( pRecvProp->m_nElements != pSendProp->m_nElements )
      break;
    pRecvProp = pRecvProp->m_pArrayProp;
    pSendProp = pSendProp->m_pArrayProp;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101708F0
// Name: class SendTable __near * RecvTable_ReadInfos(class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
SendTable *__cdecl RecvTable_ReadInfos(SendProp *pBuf, int nDemoProtocol)
{
  SendTable *v2; // eax
  int m_fHighValue_low; // ecx
  unsigned int m_fLowValue_low; // eax
  int v6; // edi
  int v7; // ecx
  const unsigned int *m_pArrayProp; // eax
  const unsigned int *m_ArrayLengthProxy; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // edi
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ebx
  int v16; // ecx
  int *v17; // eax
  int v18; // edi
  SendProp *v19; // ebx
  SendProp *v20; // eax
  int v21; // edi
  int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // edx
  const unsigned int *v27; // ecx
  const unsigned int *v28; // edx
  const unsigned int *v29; // edx
  unsigned int v30; // edi
  int v31; // eax
  const unsigned int *v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  int v35; // ecx
  int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // edi
  int v39; // edx
  unsigned int v40; // eax
  const unsigned int *v41; // eax
  const unsigned int *v42; // ecx
  const unsigned int *v43; // eax
  unsigned int v44; // edi
  int v45; // edx
  const unsigned int *v46; // ecx
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // ebx
  int v50; // ecx
  unsigned int v51; // eax
  char v52; // dl
  int v53; // ecx
  const unsigned int *v54; // ecx
  unsigned int v55; // ecx
  const unsigned int *v56; // edx
  unsigned int v57; // edi
  const unsigned int *v58; // ecx
  unsigned int v59; // edx
  unsigned int v60; // ebx
  unsigned int v61; // edx
  SendProp *v62; // edi
  SendPropType m_Type; // eax
  int v64; // ecx
  unsigned int v65; // eax
  int v66; // edi
  int v67; // ecx
  const unsigned int *v68; // eax
  const unsigned int *v69; // ecx
  const unsigned int *v70; // edx
  unsigned int v71; // edi
  int v72; // eax
  const unsigned int *v73; // ecx
  unsigned int v74; // edx
  unsigned int v75; // ebx
  unsigned int v76; // eax
  int v77; // ecx
  const unsigned int *v78; // ecx
  const unsigned int *v79; // edx
  const unsigned int *v80; // edx
  unsigned int v81; // edi
  int v82; // eax
  const unsigned int *v83; // ecx
  unsigned int v84; // edx
  unsigned int v85; // ebx
  int v86; // ecx
  unsigned int v87; // eax
  int v88; // ecx
  const unsigned int *v89; // ecx
  const unsigned int *v90; // edx
  const unsigned int *v91; // edx
  unsigned int v92; // edi
  int v93; // eax
  const unsigned int *v94; // ecx
  unsigned int v95; // edx
  unsigned int v96; // ebx
  int v97; // ecx
  unsigned int v98; // eax
  int v99; // edi
  int v100; // ecx
  const unsigned int *v101; // eax
  const unsigned int *v102; // ecx
  const unsigned int *v103; // edx
  unsigned int v104; // edi
  int v105; // eax
  const unsigned int *v106; // ecx
  unsigned int v107; // edx
  unsigned int v108; // ebx
  int iProp; // [esp+Ch] [ebp-Ch]
  int v111; // [esp+10h] [ebp-8h]
  int v112; // [esp+10h] [ebp-8h]
  SendTable *pTable; // [esp+14h] [ebp-4h]
  SendProp *pProp; // [esp+20h] [ebp+8h]
  SendProp *pPropa; // [esp+20h] [ebp+8h]

  v2 = (SendTable *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
    pTable = SendTable::SendTable(this: v2);
  else
    pTable = nullptr;
  pTable->m_pNetTableName = CBitRead::ReadAndAllocateString(this: (CBitRead *)pBuf, pOverflow: nullptr);
  m_fHighValue_low = LODWORD(pBuf->m_fHighValue);
  if ( m_fHighValue_low >= 10 )
  {
    m_fLowValue_low = LODWORD(pBuf->m_fLowValue);
    v6 = m_fLowValue_low & 0x3FF;
    v7 = m_fHighValue_low - 10;
    LODWORD(pBuf->m_fHighValue) = v7;
    if ( v7 != 0 )
    {
      LODWORD(pBuf->m_fLowValue) = m_fLowValue_low >> 10;
    }
    else
    {
      m_pArrayProp = (const unsigned int *)pBuf->m_pArrayProp;
      m_ArrayLengthProxy = (const unsigned int *)pBuf->m_ArrayLengthProxy;
      LODWORD(pBuf->m_fHighValue) = 32;
      if ( m_pArrayProp == m_ArrayLengthProxy )
      {
        LODWORD(pBuf->m_fHighValue) = 1;
        pBuf->m_fLowValue = 0.0;
        pBuf->m_pArrayProp = (SendProp *)(m_pArrayProp + 1);
      }
      else if ( m_pArrayProp <= m_ArrayLengthProxy )
      {
        LODWORD(pBuf->m_fLowValue) = *m_pArrayProp;
        pBuf->m_pArrayProp = (SendProp *)(m_pArrayProp + 1);
      }
      else
      {
        LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
        pBuf->m_fLowValue = 0.0;
      }
    }
    goto LABEL_21;
  }
  v10 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
  v11 = LODWORD(pBuf->m_fLowValue);
  v12 = 10 - m_fHighValue_low;
  v13 = (const unsigned int *)pBuf->m_pArrayProp;
  if ( v13 == v10 )
  {
    LODWORD(pBuf->m_fHighValue) = 1;
    pBuf->m_fLowValue = 0.0;
    LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
  }
  else
  {
    if ( v13 > v10 )
    {
      LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
      pBuf->m_fLowValue = 0.0;
      goto LABEL_18;
    }
    LODWORD(pBuf->m_fLowValue) = *v13;
  }
  pBuf->m_pArrayProp = (SendProp *)(v13 + 1);
LABEL_18:
  if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
  {
    v6 = 0;
  }
  else
  {
    v14 = LODWORD(pBuf->m_fLowValue);
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << LODWORD(pBuf->m_fHighValue);
    LODWORD(pBuf->m_fHighValue) = 32 - v12;
    v6 = v15 | v11;
    LODWORD(pBuf->m_fLowValue) = v14 >> v12;
  }
LABEL_21:
  pTable->m_nProps = v6;
  if ( v6 != 0
    && (v16 = (84 * (unsigned __int64)(unsigned int)v6) >> 32 != 0 ? -1 : 84 * v6,
        (v17 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v16, 4) ? -1 : v16 + 4)) != nullptr) )
  {
    *v17 = v6;
    v18 = v6 - 1;
    v19 = (SendProp *)(v17 + 1);
    for ( pProp = (SendProp *)(v17 + 1); v18 >= 0; --v18 )
      SendProp::SendProp(this: v19++);
    v20 = pProp;
  }
  else
  {
    v20 = nullptr;
  }
  pTable->m_pProps = v20;
  iProp = 0;
  if ( pTable->m_nProps > 0 )
  {
    while ( 1 )
    {
      v21 = (int)&pTable->m_pProps[iProp];
      v22 = LODWORD(pBuf->m_fHighValue);
      pPropa = (SendProp *)v21;
      if ( v22 >= 5 )
      {
        v23 = LODWORD(pBuf->m_fLowValue);
        v24 = v23 & 0x1F;
        v25 = v22 - 5;
        LODWORD(pBuf->m_fHighValue) = v25;
        if ( v25 != 0 )
        {
          v26 = v23 >> 5;
        }
        else
        {
          v27 = (const unsigned int *)pBuf->m_pArrayProp;
          v28 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
          LODWORD(pBuf->m_fHighValue) = 32;
          if ( v27 == v28 )
          {
            LODWORD(pBuf->m_fHighValue) = 1;
            pBuf->m_fLowValue = 0.0;
            pBuf->m_pArrayProp = (SendProp *)(v27 + 1);
            goto LABEL_46;
          }
          if ( v27 > v28 )
          {
            LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
            pBuf->m_fLowValue = 0.0;
            goto LABEL_46;
          }
          v26 = *v27;
          pBuf->m_pArrayProp = (SendProp *)(v27 + 1);
        }
        goto LABEL_45;
      }
      v29 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
      v30 = LODWORD(pBuf->m_fLowValue);
      v31 = 5 - v22;
      v32 = (const unsigned int *)pBuf->m_pArrayProp;
      if ( v32 == v29 )
        break;
      if ( v32 <= v29 )
      {
        LODWORD(pBuf->m_fLowValue) = *v32;
        goto LABEL_41;
      }
      LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
      pBuf->m_fLowValue = 0.0;
LABEL_42:
      if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
      {
        v21 = (int)pPropa;
        v24 = 0;
        goto LABEL_46;
      }
      v33 = LODWORD(pBuf->m_fLowValue);
      v34 = (v33 & CBitBuffer::s_nMaskTable[v31]) << LODWORD(pBuf->m_fHighValue);
      LODWORD(pBuf->m_fHighValue) = 32 - v31;
      v26 = v33 >> v31;
      v24 = v34 | v30;
      v21 = (int)pPropa;
LABEL_45:
      LODWORD(pBuf->m_fLowValue) = v26;
LABEL_46:
      *(_DWORD *)(v21 + 8) = v24;
      *(_DWORD *)(v21 + 48) = CBitRead::ReadAndAllocateString(this: (CBitRead *)pBuf, pOverflow: nullptr);
      v35 = 19;
      if ( nDemoProtocol == 2 )
        v35 = 11;
      v36 = LODWORD(pBuf->m_fHighValue);
      if ( v36 < v35 )
      {
        v43 = (const unsigned int *)pBuf->m_pArrayProp;
        v44 = LODWORD(pBuf->m_fLowValue);
        v45 = v35 - v36;
        v46 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        if ( v43 == v46 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_61;
        }
        if ( v43 <= v46 )
        {
          LODWORD(pBuf->m_fLowValue) = *v43;
LABEL_61:
          pBuf->m_pArrayProp = (SendProp *)(v43 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          v47 = 0;
          goto LABEL_67;
        }
        v48 = LODWORD(pBuf->m_fLowValue);
        v49 = (v48 & CBitBuffer::s_nMaskTable[v45]) << LODWORD(pBuf->m_fHighValue);
        LODWORD(pBuf->m_fHighValue) = 32 - v45;
        v38 = v49 | v44;
        v40 = v48 >> v45;
        goto LABEL_65;
      }
      v37 = LODWORD(pBuf->m_fLowValue);
      v38 = v37 & CBitBuffer::s_nMaskTable[v35];
      v39 = v36 - v35;
      LODWORD(pBuf->m_fHighValue) = v39;
      if ( v39 == 0 )
      {
        v41 = (const unsigned int *)pBuf->m_pArrayProp;
        v42 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        LODWORD(pBuf->m_fHighValue) = 32;
        if ( v41 == v42 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          pBuf->m_pArrayProp = (SendProp *)(v41 + 1);
        }
        else if ( v41 <= v42 )
        {
          LODWORD(pBuf->m_fLowValue) = *v41;
          pBuf->m_pArrayProp = (SendProp *)(v41 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        goto LABEL_66;
      }
      v40 = v37 >> v35;
LABEL_65:
      LODWORD(pBuf->m_fLowValue) = v40;
LABEL_66:
      v47 = v38;
LABEL_67:
      pPropa->m_Flags = v47;
      v50 = LODWORD(pBuf->m_fHighValue);
      if ( v50 < 8 )
      {
        v56 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        v57 = LODWORD(pBuf->m_fLowValue);
        v51 = 8 - v50;
        v58 = (const unsigned int *)pBuf->m_pArrayProp;
        if ( v58 == v56 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_81;
        }
        if ( v58 <= v56 )
        {
          LODWORD(pBuf->m_fLowValue) = *v58;
LABEL_81:
          pBuf->m_pArrayProp = (SendProp *)(v58 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          LOBYTE(v51) = 0;
        }
        else
        {
          v59 = LODWORD(pBuf->m_fLowValue);
          v60 = (v59 & CBitBuffer::s_nMaskTable[v51]) << LODWORD(pBuf->m_fHighValue);
          LODWORD(pBuf->m_fHighValue) = 32 - v51;
          v61 = v59 >> v51;
          LOBYTE(v51) = v60 | v57;
          LODWORD(pBuf->m_fLowValue) = v61;
        }
        goto LABEL_85;
      }
      v51 = LODWORD(pBuf->m_fLowValue);
      v52 = v51;
      v53 = v50 - 8;
      LODWORD(pBuf->m_fHighValue) = v53;
      if ( v53 != 0 )
      {
        LODWORD(pBuf->m_fLowValue) = v51 >> 8;
      }
      else
      {
        v51 = (unsigned int)pBuf->m_pArrayProp;
        v54 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        LODWORD(pBuf->m_fHighValue) = 32;
        if ( (const unsigned int *)v51 == v54 )
        {
          pBuf->m_pArrayProp = (SendProp *)(v51 + 4);
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(v51) = v52;
        }
        else
        {
          if ( v51 <= (unsigned int)v54 )
          {
            v55 = *(_DWORD *)v51;
            pBuf->m_pArrayProp = (SendProp *)(v51 + 4);
            LODWORD(pBuf->m_fLowValue) = v55;
          }
          else
          {
            LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
            pBuf->m_fLowValue = 0.0;
          }
          LOBYTE(v51) = v52;
        }
      }
LABEL_85:
      v62 = pPropa;
      pPropa->m_priority = v51;
      m_Type = pPropa->m_Type;
      if ( m_Type != DPT_DataTable && (pPropa->m_Flags & 0x40) == 0 )
      {
        v64 = LODWORD(pBuf->m_fHighValue);
        if ( m_Type == DPT_Array )
        {
          if ( v64 >= 10 )
          {
            v65 = LODWORD(pBuf->m_fLowValue);
            v66 = v65 & 0x3FF;
            v67 = v64 - 10;
            LODWORD(pBuf->m_fHighValue) = v67;
            if ( v67 != 0 )
            {
              LODWORD(pBuf->m_fLowValue) = v65 >> 10;
              pPropa->m_nElements = v66;
            }
            else
            {
              v68 = (const unsigned int *)pBuf->m_pArrayProp;
              v69 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
              LODWORD(pBuf->m_fHighValue) = 32;
              if ( v68 == v69 )
              {
                LODWORD(pBuf->m_fHighValue) = 1;
                pBuf->m_fLowValue = 0.0;
                pBuf->m_pArrayProp = (SendProp *)(v68 + 1);
                pPropa->m_nElements = v66;
              }
              else
              {
                if ( v68 <= v69 )
                {
                  LODWORD(pBuf->m_fLowValue) = *v68;
                  pBuf->m_pArrayProp = (SendProp *)(v68 + 1);
                }
                else
                {
                  LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
                  pBuf->m_fLowValue = 0.0;
                }
                pPropa->m_nElements = v66;
              }
            }
            goto LABEL_163;
          }
          v70 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
          v71 = LODWORD(pBuf->m_fLowValue);
          v72 = 10 - v64;
          v73 = (const unsigned int *)pBuf->m_pArrayProp;
          if ( v73 == v70 )
          {
            LODWORD(pBuf->m_fHighValue) = 1;
            pBuf->m_fLowValue = 0.0;
            LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
            goto LABEL_103;
          }
          if ( v73 <= v70 )
          {
            LODWORD(pBuf->m_fLowValue) = *v73;
LABEL_103:
            pBuf->m_pArrayProp = (SendProp *)(v73 + 1);
          }
          else
          {
            LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
            pBuf->m_fLowValue = 0.0;
          }
          if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
          {
            pPropa->m_nElements = 0;
          }
          else
          {
            v74 = LODWORD(pBuf->m_fLowValue);
            v75 = (v74 & CBitBuffer::s_nMaskTable[v72]) << LODWORD(pBuf->m_fHighValue);
            LODWORD(pBuf->m_fHighValue) = 32 - v72;
            LODWORD(pBuf->m_fLowValue) = v74 >> v72;
            pPropa->m_nElements = v75 | v71;
          }
          goto LABEL_163;
        }
        if ( v64 >= 32 )
        {
          v76 = LODWORD(pBuf->m_fLowValue);
          v77 = v64 - 32;
          LODWORD(pBuf->m_fHighValue) = v77;
          if ( v77 != 0 )
          {
            pBuf->m_fLowValue = 0.0;
            v111 = v76;
          }
          else
          {
            v78 = (const unsigned int *)pBuf->m_pArrayProp;
            v79 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
            LODWORD(pBuf->m_fHighValue) = 32;
            if ( v78 == v79 )
            {
              LODWORD(pBuf->m_fHighValue) = 1;
              pBuf->m_fLowValue = 0.0;
              pBuf->m_pArrayProp = (SendProp *)(v78 + 1);
              v111 = v76;
            }
            else
            {
              if ( v78 <= v79 )
              {
                LODWORD(pBuf->m_fLowValue) = *v78;
                pBuf->m_pArrayProp = (SendProp *)(v78 + 1);
              }
              else
              {
                LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
                pBuf->m_fLowValue = 0.0;
              }
              v111 = v76;
            }
          }
          goto LABEL_126;
        }
        v80 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        v81 = LODWORD(pBuf->m_fLowValue);
        v82 = 32 - v64;
        v83 = (const unsigned int *)pBuf->m_pArrayProp;
        if ( v83 == v80 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_121;
        }
        if ( v83 <= v80 )
        {
          LODWORD(pBuf->m_fLowValue) = *v83;
LABEL_121:
          pBuf->m_pArrayProp = (SendProp *)(v83 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          v111 = 0;
        }
        else
        {
          v84 = LODWORD(pBuf->m_fLowValue);
          v85 = (v84 & CBitBuffer::s_nMaskTable[v82]) << LODWORD(pBuf->m_fHighValue);
          LODWORD(pBuf->m_fHighValue) = 32 - v82;
          v111 = v85 | v81;
          LODWORD(pBuf->m_fLowValue) = v84 >> v82;
        }
        v62 = pPropa;
LABEL_126:
        LODWORD(v62->m_fLowValue) = v111;
        v86 = LODWORD(pBuf->m_fHighValue);
        if ( v86 >= 32 )
        {
          v87 = LODWORD(pBuf->m_fLowValue);
          v88 = v86 - 32;
          LODWORD(pBuf->m_fHighValue) = v88;
          if ( v88 != 0 )
          {
            pBuf->m_fLowValue = 0.0;
            v112 = v87;
          }
          else
          {
            v89 = (const unsigned int *)pBuf->m_pArrayProp;
            v90 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
            LODWORD(pBuf->m_fHighValue) = 32;
            if ( v89 == v90 )
            {
              LODWORD(pBuf->m_fHighValue) = 1;
              pBuf->m_fLowValue = 0.0;
              pBuf->m_pArrayProp = (SendProp *)(v89 + 1);
              v112 = v87;
            }
            else
            {
              if ( v89 <= v90 )
              {
                LODWORD(pBuf->m_fLowValue) = *v89;
                pBuf->m_pArrayProp = (SendProp *)(v89 + 1);
              }
              else
              {
                LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
                pBuf->m_fLowValue = 0.0;
              }
              v112 = v87;
            }
          }
          goto LABEL_145;
        }
        v91 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        v92 = LODWORD(pBuf->m_fLowValue);
        v93 = 32 - v86;
        v94 = (const unsigned int *)pBuf->m_pArrayProp;
        if ( v94 == v91 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_140;
        }
        if ( v94 <= v91 )
        {
          LODWORD(pBuf->m_fLowValue) = *v94;
LABEL_140:
          pBuf->m_pArrayProp = (SendProp *)(v94 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          v112 = 0;
        }
        else
        {
          v95 = LODWORD(pBuf->m_fLowValue);
          v96 = (v95 & CBitBuffer::s_nMaskTable[v93]) << LODWORD(pBuf->m_fHighValue);
          LODWORD(pBuf->m_fHighValue) = 32 - v93;
          v112 = v96 | v92;
          LODWORD(pBuf->m_fLowValue) = v95 >> v93;
        }
        v62 = pPropa;
LABEL_145:
        LODWORD(v62->m_fHighValue) = v112;
        v97 = LODWORD(pBuf->m_fHighValue);
        if ( v97 >= 7 )
        {
          v98 = LODWORD(pBuf->m_fLowValue);
          v99 = v98 & 0x7F;
          v100 = v97 - 7;
          LODWORD(pBuf->m_fHighValue) = v100;
          if ( v100 != 0 )
          {
            LODWORD(pBuf->m_fLowValue) = v98 >> 7;
          }
          else
          {
            v101 = (const unsigned int *)pBuf->m_pArrayProp;
            v102 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
            LODWORD(pBuf->m_fHighValue) = 32;
            if ( v101 == v102 )
            {
              LODWORD(pBuf->m_fHighValue) = 1;
              pBuf->m_fLowValue = 0.0;
              pBuf->m_pArrayProp = (SendProp *)(v101 + 1);
            }
            else if ( v101 <= v102 )
            {
              LODWORD(pBuf->m_fLowValue) = *v101;
              pBuf->m_pArrayProp = (SendProp *)(v101 + 1);
            }
            else
            {
              LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
              pBuf->m_fLowValue = 0.0;
            }
          }
LABEL_162:
          pPropa->m_nBits = v99;
          goto LABEL_163;
        }
        v103 = (const unsigned int *)pBuf->m_ArrayLengthProxy;
        v104 = LODWORD(pBuf->m_fLowValue);
        v105 = 7 - v97;
        v106 = (const unsigned int *)pBuf->m_pArrayProp;
        if ( v106 == v103 )
        {
          LODWORD(pBuf->m_fHighValue) = 1;
          pBuf->m_fLowValue = 0.0;
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          goto LABEL_158;
        }
        if ( v106 <= v103 )
        {
          LODWORD(pBuf->m_fLowValue) = *v106;
LABEL_158:
          pBuf->m_pArrayProp = (SendProp *)(v106 + 1);
        }
        else
        {
          LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
          pBuf->m_fLowValue = 0.0;
        }
        if ( LOBYTE(pBuf->m_pMatchingRecvProp) != 0 )
        {
          v99 = 0;
        }
        else
        {
          v107 = LODWORD(pBuf->m_fLowValue);
          v108 = (v107 & CBitBuffer::s_nMaskTable[v105]) << LODWORD(pBuf->m_fHighValue);
          LODWORD(pBuf->m_fHighValue) = 32 - v105;
          v99 = v108 | v104;
          LODWORD(pBuf->m_fLowValue) = v107 >> v105;
        }
        goto LABEL_162;
      }
      pPropa->m_pExcludeDTName = CBitRead::ReadAndAllocateString(this: (CBitRead *)pBuf, pOverflow: nullptr);
LABEL_163:
      if ( ++iProp >= pTable->m_nProps )
        return pTable;
    }
    LODWORD(pBuf->m_fHighValue) = 1;
    pBuf->m_fLowValue = 0.0;
    LOBYTE(pBuf->m_pMatchingRecvProp) = 1;
LABEL_41:
    pBuf->m_pArrayProp = (SendProp *)(v32 + 1);
    goto LABEL_42;
  }
  return pTable;
}

//------------------------------------------------------------------------------
// Address: 0x101711D0
// Name: void RecvTable_FreeSendTable(class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvTable_FreeSendTable(SendTable *pTable)
{
  int v1; // esi
  SendProp *m_pProps; // edi
  char *m_pExcludeDTName; // edi
  SendProp *v4; // ecx
  int iProp; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( iProp = 0; iProp < pTable->m_nProps; ++iProp )
  {
    m_pProps = pTable->m_pProps;
    free(pMem: pTable->m_pProps[v1].m_pVarName);
    m_pExcludeDTName = m_pProps[v1].m_pExcludeDTName;
    if ( m_pExcludeDTName != nullptr )
      free(pMem: m_pExcludeDTName);
    ++v1;
  }
  v4 = pTable->m_pProps;
  if ( pTable->m_pProps != nullptr )
  {
    if ( v4[-1].m_pExtraData != nullptr )
      ((void (__thiscall *)(SendProp *, int))v4->dtr_SendProp)(a1: v4, a2: 3);
    else
      free(pMem: &v4[-1].m_pExtraData);
  }
  free(pMem: pTable->m_pNetTableName);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)pTable);
  free(pMem: pTable);
}

//------------------------------------------------------------------------------
// Address: 0x10171260
// Name: bool RecvTable_RecvClassInfos(class bf_read __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RecvTable_RecvClassInfos(SendProp *pBuf, bool bNeedsDecoder, int nDemoProtocol)
{
  SendTable *Infos; // eax
  SendTable *v4; // esi
  char v6; // bl

  Infos = RecvTable_ReadInfos(pBuf, nDemoProtocol);
  v4 = Infos;
  if ( Infos == nullptr )
    return 0;
  v6 = DataTable_SetupReceiveTableFromSendTable(sendTable: Infos, bNeedsDecoder);
  RecvTable_FreeSendTable(pTable: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101713B0
// Name: ShowDecodeDeltaWatchInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDecodeDeltaWatchInfo(
        char *what,
        const RecvTable *pTable,
        const SendProp *pProp,
        bf_read *buffer,
        int objectID,
        int index)
{
  int m_nDataBits; // esi
  SendPropType m_Type; // edx
  int v9; // ecx
  const char *v10; // edi
  const char *v11; // eax
  DecodeInfo info; // [esp+Ch] [ebp-25Ch] BYREF
  bf_read copy; // [esp+244h] [ebp-24h] BYREF
  int startBit; // [esp+278h] [ebp+10h]

  if ( ShouldWatchThisProp(pTable, objectID, pPropName: pProp->m_pVarName) )
  {
    if ( host_framecount != lastframe )
    {
      lastframe = host_framecount;
      _ConDMsg(a1: "D: delta entity: %i %s\n", objectID, pTable->m_pNetTableName);
    }
    copy = *buffer;
    m_nDataBits = 0;
    s_debug_info_shown = true;
    info.m_ObjectID = objectID;
    m_Type = pProp->m_Type;
    info.m_pStruct = nullptr;
    info.m_pData = nullptr;
    info.m_pRecvProp = nullptr;
    info.m_pProp = pProp;
    info.m_pIn = &copy;
    info.m_Value.m_Type = m_Type;
    if ( copy.m_pData != nullptr )
    {
      startBit = 32 * (copy.m_pDataIn - copy.m_pData) - copy.m_nBitsAvail + 8 * (copy.m_nDataBytes & 3);
      if ( startBit >= copy.m_nDataBits )
        startBit = copy.m_nDataBits;
    }
    else
    {
      startBit = 0;
    }
    (*(&funcs_1016CB84 + 9 * m_Type))(pInfo: &info);
    if ( copy.m_pData != nullptr )
    {
      m_nDataBits = copy.m_nDataBits;
      v9 = 32 * (copy.m_pDataIn - copy.m_pData) - copy.m_nBitsAvail;
      if ( v9 + 8 * (copy.m_nDataBytes & 3) < copy.m_nDataBits )
        m_nDataBits = v9 + 8 * (copy.m_nDataBytes & 3);
    }
    v10 = (*(&funcs_101714CD + 9 * pProp->m_Type))();
    v11 = DVariant::ToString(this: &info.m_Value);
    _ConDMsg(
      a1: "D[%s]:%s %s, %s, index %i, offset %i, bits %i, value %s\n",
      what,
      pTable->m_pNetTableName,
      pProp->m_pVarName,
      v10,
      index,
      startBit,
      m_nDataBits - startBit,
      v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171510
// Name: void RecvTable_DecodeZeros(class RecvTable __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvTable_DecodeZeros(RecvTable *pTable, unsigned __int8 *pStruct, int objectID)
{
  CRecvDecoder *m_pDecoder; // edi
  int i; // esi
  const RecvProp *v5; // ecx
  const SendProp **m_pMemory; // edx
  DecodeInfo decodeInfo; // [esp+Ch] [ebp-358h] BYREF
  CClientDatatableStack theStack; // [esp+244h] [ebp-120h] BYREF

  m_pDecoder = pTable->m_pDecoder;
  if ( m_pDecoder == nullptr )
    _Error(a1: "RecvTable_DecodeZeros: table '%s' missing a decoder.", pTable->m_pNetTableName);
  CDatatableStack::CDatatableStack(this: &theStack, pPrecalc: &m_pDecoder->m_Precalc, pStructBase: pStruct, objectID);
  theStack.__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
  theStack.m_pDecoder = m_pDecoder;
  CDatatableStack::Init(this: &theStack, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  for ( i = 0; i < m_pDecoder->m_Props.m_Size; ++i )
  {
    theStack.m_iCurProp = i;
    theStack.m_pCurProp = theStack.m_pPrecalc->m_Props.m_Memory.m_pMemory[i];
    v5 = m_pDecoder->m_Props.m_Memory.m_pMemory[i];
    decodeInfo.m_Value.m_Type = DPT_Float;
    decodeInfo.m_pStruct = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]];
    decodeInfo.m_pData = &theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]][v5->m_Offset];
    m_pMemory = m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory;
    decodeInfo.m_pRecvProp = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]] != nullptr
                           ? v5
                           : nullptr;
    decodeInfo.m_pProp = m_pMemory[i];
    decodeInfo.m_pIn = nullptr;
    decodeInfo.m_ObjectID = objectID;
    (*(&funcs_1017161A + 9 * v5->m_RecvType))(pInfo: &decodeInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171640
// Name: CopyPropState
// Source: json
//------------------------------------------------------------------------------
void __usercall CopyPropState(CRecvDecoder *pDecoder@<eax>, DVariant *pIn@<esi>, int iSendProp, CDeltaBitsWriter *pOut)
{
  const SendProp **m_pMemory; // ecx
  const unsigned int *v5; // eax
  signed int v6; // ebx
  const unsigned int *v7; // eax
  int v8; // edi
  int v9; // ecx
  const SendProp *v10; // [esp+0h] [ebp-8h]
  bf_write *v11; // [esp+4h] [ebp-4h]
  DVariant *savedregs; // [esp+8h] [ebp+0h]

  m_pMemory = pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory;
  v5 = (const unsigned int *)LODWORD(pIn[1].m_Vector[2]);
  if ( v5 != nullptr )
  {
    v6 = 32 * ((pIn[1].m_Int - (int)v5) >> 2) - *((_DWORD *)&pIn->m_Type + 1) + 8 * (*(_DWORD *)(&pIn->___u0 + 1) & 3);
    if ( v6 >= SLODWORD(pIn->m_Vector[2]) )
      v6 = LODWORD(pIn->m_Vector[2]);
  }
  else
  {
    v6 = 0;
  }
  ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B262[9 * m_pMemory[iSendProp]->m_Type])(
    pStruct: (const unsigned __int8 *)m_pMemory[iSendProp],
    pVar: pIn,
    pProp: v10,
    pOut: v11,
    objectID: savedregs);
  v7 = (const unsigned int *)LODWORD(pIn[1].m_Vector[2]);
  if ( v7 != nullptr )
  {
    v8 = LODWORD(pIn->m_Vector[2]);
    v9 = 32 * ((pIn[1].m_Int - (int)v7) >> 2) - *((_DWORD *)&pIn->m_Type + 1);
    if ( v9 + 8 * (*(_DWORD *)(&pIn->___u0 + 1) & 3) < v8 )
      v8 = v9 + 8 * (*(_DWORD *)(&pIn->___u0 + 1) & 3);
  }
  else
  {
    v8 = 0;
  }
  CBitRead::Seek(this: (CBitRead *)pIn, nPosition: v6);
  CDeltaBitsWriter::WritePropIndex(this: pOut, iProp: iSendProp);
  bf_write::WriteBitsFromBuffer(this: pOut->m_pBuf, (bf_read *)pIn, nBits: v8 - v6);
}

//------------------------------------------------------------------------------
// Address: 0x101716F0
// Name: int RecvTable_MergeDeltas(class RecvTable __near *,class bf_read __near *,class bf_read __near *,class bf_write __near *,int,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall RecvTable_MergeDeltas@<eax>(
        const SendProp *a1@<ebx>,
        RecvTable *pTable,
        bf_read *pOldState,
        bf_read *pNewState,
        bf_write *pOut,
        int objectID,
        bool bDebugWatchInfo,
        int *pChangedProps)
{
  bf_write *v8; // edi
  CRecvDecoder *m_pDecoder; // ebx
  bool v10; // al
  bf_read *v11; // esi
  int v12; // edi
  int v13; // eax
  const SendProp *v14; // edi
  int v15; // eax
  const SendProp *v17; // [esp-4h] [ebp-44h]
  bf_write *v18; // [esp+0h] [ebp-40h]
  DVariant *v19; // [esp+4h] [ebp-3Ch]
  CDeltaBitsReader newStateReader; // [esp+8h] [ebp-38h] BYREF
  CDeltaBitsReader oldStateReader; // [esp+18h] [ebp-28h] BYREF
  CDeltaBitsWriter deltaBitsWriter; // [esp+28h] [ebp-18h] BYREF
  int nChanged; // [esp+34h] [ebp-Ch]
  int iNewProp; // [esp+38h] [ebp-8h]
  bool bDebugWatch; // [esp+3Fh] [ebp-1h]

  if ( pTable == nullptr || pNewState == nullptr || (v8 = pOut, pOut == nullptr) )
  {
    _Error(a1: "RecvTable_MergeDeltas: invalid parameters passed.");
    v8 = pOut;
  }
  v17 = a1;
  m_pDecoder = pTable->m_pDecoder;
  if ( m_pDecoder == nullptr )
    _Error(a1: "RecvTable_MergeDeltas: table '%s' is missing its decoder.", pTable->m_pNetTableName);
  nChanged = 0;
  v10 = Sendprop_UsingDebugWatch();
  v11 = pOldState;
  s_debug_info_shown = false;
  s_debug_bits_start = v8->m_iCurBit;
  bDebugWatch = v10;
  CDeltaBitsReader::CDeltaBitsReader(this: &oldStateReader, pBuf: pOldState);
  CDeltaBitsReader::CDeltaBitsReader(this: &newStateReader, pBuf: pNewState);
  CDeltaBitsWriter::CDeltaBitsWriter(this: &deltaBitsWriter, pBuf: v8);
  v12 = 0x7FFFFFFF;
  if ( pOldState != nullptr )
  {
    v13 = CDeltaBitsReader::ReadNextPropIndex(this: &oldStateReader);
    if ( v13 >= 0 )
      v12 = v13;
  }
  iNewProp = CDeltaBitsReader::ReadNextPropIndex(this: &newStateReader);
  if ( iNewProp < 0 )
  {
LABEL_11:
    iNewProp = 0x7FFFFFFF;
    goto LABEL_12;
  }
  while ( 1 )
  {
LABEL_12:
    while ( v12 < iNewProp )
    {
      if ( bDebugWatch )
        ShowDecodeDeltaWatchInfo(
          what: "Old",
          pTable,
          pProp: m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v12],
          buffer: v11,
          objectID,
          index: v12);
      CopyPropState(pDecoder: m_pDecoder, pIn: (DVariant *)v11, iSendProp: v12, pOut: &deltaBitsWriter);
      v12 = CDeltaBitsReader::ReadNextPropIndex(this: &oldStateReader);
      if ( v12 < 0 )
        v12 = 0x7FFFFFFF;
      v11 = pOldState;
    }
    if ( iNewProp == 0x7FFFFFFF )
      break;
    if ( v12 == iNewProp )
    {
      if ( bDebugWatch )
        ShowDecodeDeltaWatchInfo(
          what: "Skip",
          pTable,
          pProp: m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v12],
          buffer: v11,
          objectID,
          index: v12);
      v14 = m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v12];
      ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B262[9 * v14->m_Type])(
        pStruct: (const unsigned __int8 *)v14,
        pVar: (DVariant *)v11,
        pProp: v17,
        pOut: v18,
        objectID: v19);
      v12 = CDeltaBitsReader::ReadNextPropIndex(this: &oldStateReader);
      if ( v12 < 0 )
        v12 = 0x7FFFFFFF;
    }
    if ( bDebugWatch )
      ShowDecodeDeltaWatchInfo(
        what: "New",
        pTable,
        pProp: m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[iNewProp],
        buffer: pNewState,
        objectID,
        index: iNewProp);
    CopyPropState(pDecoder: m_pDecoder, pIn: (DVariant *)pNewState, iSendProp: iNewProp, pOut: &deltaBitsWriter);
    if ( pChangedProps != nullptr )
      pChangedProps[nChanged] = iNewProp;
    ++nChanged;
    v15 = CDeltaBitsReader::ReadNextPropIndex(this: &newStateReader);
    v11 = pOldState;
    if ( v15 < 0 )
      goto LABEL_11;
    iNewProp = v15;
  }
  if ( v11 != nullptr && v11->m_bOverflow || pNewState->m_bOverflow || pOut->m_bOverflow )
    _Error(a1: "RecvTable_MergeDeltas: overflowed in RecvTable '%s'.", pTable->m_pNetTableName);
  if ( s_debug_info_shown )
    _ConDMsg(
      a1: "D= %i bits (%i bytes)\n",
      pOut->m_iCurBit - s_debug_bits_start,
      (pOut->m_iCurBit - s_debug_bits_start + 7) >> 3);
  CDeltaBitsWriter::~CDeltaBitsWriter(this: &deltaBitsWriter);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&newStateReader);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&oldStateReader);
  return nChanged;
}

//------------------------------------------------------------------------------
// Address: 0x10171950
// Name: bool RecvTable_Decode_Guts<1>(class RecvTable __near *,void __near *,class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RecvTable_Decode_Guts<1>(RecvTable *pTable, unsigned __int8 *pStruct, bf_read *pIn, int objectID)
{
  CRecvDecoder *m_pDecoder; // ebx
  const unsigned int *m_pData; // eax
  int v7; // edi
  const unsigned int *v8; // edx
  const RecvProp *v9; // ecx
  int m_nDataBits; // ebx
  int v11; // ebx
  const unsigned int *v12; // eax
  signed int v13; // edx
  bool m_bOverflow; // bl
  DecodeInfo decodeInfo; // [esp+Ch] [ebp-36Ch] BYREF
  CClientDatatableStack theStack; // [esp+244h] [ebp-134h] BYREF
  CDeltaBitsReader deltaBitsReader; // [esp+364h] [ebp-14h] BYREF
  CRecvDecoder *pDecoder; // [esp+374h] [ebp-4h]
  signed int iLastBit; // [esp+380h] [ebp+8h]
  int iStartBit; // [esp+388h] [ebp+10h]

  m_pDecoder = pTable->m_pDecoder;
  pDecoder = m_pDecoder;
  if ( m_pDecoder == nullptr )
    _Error(a1: "RecvTable_Decode: table '%s' missing a decoder.", pTable->m_pNetTableName);
  CDatatableStack::CDatatableStack(this: &theStack, pPrecalc: &m_pDecoder->m_Precalc, pStructBase: pStruct, objectID);
  theStack.__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
  theStack.m_pDecoder = m_pDecoder;
  CDatatableStack::Init(this: &theStack, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  m_pData = pIn->m_pData;
  if ( m_pData != nullptr )
  {
    iLastBit = 32 * (pIn->m_pDataIn - m_pData) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
    if ( iLastBit >= pIn->m_nDataBits )
      iLastBit = pIn->m_nDataBits;
  }
  else
  {
    iLastBit = 0;
  }
  CDeltaBitsReader::CDeltaBitsReader(this: &deltaBitsReader, pBuf: pIn);
  v7 = CDeltaBitsReader::ReadNextPropIndex(this: &deltaBitsReader);
  if ( v7 != -1 )
  {
    while ( 1 )
    {
      theStack.m_iCurProp = v7;
      theStack.m_pCurProp = theStack.m_pPrecalc->m_Props.m_Memory.m_pMemory[v7];
      v8 = pIn->m_pData;
      v9 = m_pDecoder->m_Props.m_Memory.m_pMemory[v7];
      if ( v8 == nullptr )
        break;
      v13 = 32 * (pIn->m_pDataIn - v8) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
      m_nDataBits = pIn->m_nDataBits;
      if ( v13 >= m_nDataBits )
        goto LABEL_12;
      m_nDataBits = v13;
      iStartBit = v13;
LABEL_13:
      decodeInfo.m_Value.m_Type = DPT_Float;
      v11 = m_nDataBits - iLastBit;
      decodeInfo.m_pStruct = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]];
      decodeInfo.m_pData = &theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]][v9->m_Offset];
      decodeInfo.m_pRecvProp = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]] != nullptr
                             ? v9
                             : nullptr;
      decodeInfo.m_pProp = pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[v7];
      decodeInfo.m_ObjectID = objectID;
      decodeInfo.m_pIn = pIn;
      (*(&funcs_1016CB84 + 9 * v9->m_RecvType))(pInfo: &decodeInfo);
      ++g_nPropsDecoded;
      v12 = pIn->m_pData;
      if ( v12 != nullptr )
      {
        iLastBit = 32 * (pIn->m_pDataIn - v12) - pIn->m_nBitsAvail + 8 * (pIn->m_nDataBytes & 3);
        if ( iLastBit >= pIn->m_nDataBits )
          iLastBit = pIn->m_nDataBits;
      }
      else
      {
        iLastBit = 0;
      }
      if ( g_bDTIEnabled )
        _DTI_HookDeltaBits(pDecoder, iProp: v7, nDataBits: iLastBit - iStartBit, nIndexBits: v11);
      v7 = CDeltaBitsReader::ReadNextPropIndex(this: &deltaBitsReader);
      if ( v7 == -1 )
        goto LABEL_22;
      m_pDecoder = pDecoder;
    }
    m_nDataBits = 0;
LABEL_12:
    iStartBit = m_nDataBits;
    goto LABEL_13;
  }
LABEL_22:
  m_bOverflow = pIn->m_bOverflow;
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&deltaBitsReader);
  return !m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x10171B70
// Name: bool RecvTable_Decode_Guts<0>(class RecvTable __near *,void __near *,class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RecvTable_Decode_Guts<0>(RecvTable *pTable, unsigned __int8 *pStruct, bf_read *pIn, int objectID)
{
  CRecvDecoder *m_pDecoder; // esi
  int i; // eax
  const RecvProp *v6; // edx
  bool m_bOverflow; // bl
  DecodeInfo decodeInfo; // [esp+Ch] [ebp-368h] BYREF
  CClientDatatableStack theStack; // [esp+244h] [ebp-130h] BYREF
  CDeltaBitsReader deltaBitsReader; // [esp+364h] [ebp-10h] BYREF

  m_pDecoder = pTable->m_pDecoder;
  if ( m_pDecoder == nullptr )
    _Error(a1: "RecvTable_Decode: table '%s' missing a decoder.", pTable->m_pNetTableName);
  CDatatableStack::CDatatableStack(this: &theStack, pPrecalc: &m_pDecoder->m_Precalc, pStructBase: pStruct, objectID);
  theStack.__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
  theStack.m_pDecoder = m_pDecoder;
  CDatatableStack::Init(this: &theStack, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  CDeltaBitsReader::CDeltaBitsReader(this: &deltaBitsReader, pBuf: pIn);
  for ( i = CDeltaBitsReader::ReadNextPropIndex(this: &deltaBitsReader);
        i != -1;
        i = CDeltaBitsReader::ReadNextPropIndex(this: &deltaBitsReader) )
  {
    theStack.m_iCurProp = i;
    theStack.m_pCurProp = theStack.m_pPrecalc->m_Props.m_Memory.m_pMemory[i];
    v6 = m_pDecoder->m_Props.m_Memory.m_pMemory[i];
    decodeInfo.m_Value.m_Type = DPT_Float;
    decodeInfo.m_pStruct = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]];
    decodeInfo.m_pData = &theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]][v6->m_Offset];
    decodeInfo.m_pRecvProp = theStack.m_pProxies[theStack.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]] != nullptr
                           ? v6
                           : nullptr;
    decodeInfo.m_pProp = m_pDecoder->m_Precalc.m_Props.m_Memory.m_pMemory[i];
    decodeInfo.m_ObjectID = objectID;
    decodeInfo.m_pIn = pIn;
    (*(&funcs_1016CB84 + 9 * v6->m_RecvType))(pInfo: &decodeInfo);
    ++g_nPropsDecoded;
  }
  m_bOverflow = pIn->m_bOverflow;
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&deltaBitsReader);
  return !m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x10172240
// Name: class RecvTable __near * FindRecvTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
RecvTable *__cdecl FindRecvTable(const char *pName)
{
  int m_Next; // edi
  UtlLinkedListElem_t<RecvTable *,unsigned short> *m_pMemory; // eax
  int v3; // esi

  LOWORD(m_Next) = g_RecvTables.m_Head;
  if ( g_RecvTables.m_Head == 0xFFFF )
    return nullptr;
  m_pMemory = g_RecvTables.m_Memory.m_pMemory;
  while ( 1 )
  {
    v3 = (unsigned __int16)m_Next;
    if ( _V_stricmp(s1: m_pMemory[v3].m_Element->m_pNetTableName, s2: pName) == 0 )
      break;
    m_pMemory = g_RecvTables.m_Memory.m_pMemory;
    m_Next = g_RecvTables.m_Memory.m_pMemory[v3].m_Next;
    if ( m_Next == 0xFFFF )
      return nullptr;
  }
  return g_RecvTables.m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x101722B0
// Name: FindClientSendTable
// Source: json
//------------------------------------------------------------------------------
CClientSendTable *__cdecl FindClientSendTable(const char *pName)
{
  int m_Next; // eax
  UtlLinkedListElem_t<CClientSendTable *,unsigned short> *m_pMemory; // ecx
  int v3; // esi
  CClientSendTable *m_Element; // edi

  LOWORD(m_Next) = g_ClientSendTables.m_Head;
  if ( g_ClientSendTables.m_Head == 0xFFFF )
    return nullptr;
  m_pMemory = g_ClientSendTables.m_Memory.m_pMemory;
  while ( 1 )
  {
    v3 = (unsigned __int16)m_Next;
    m_Element = m_pMemory[v3].m_Element;
    if ( _V_stricmp(s1: m_Element->m_SendTable.m_pNetTableName, s2: pName) == 0 )
      break;
    m_pMemory = g_ClientSendTables.m_Memory.m_pMemory;
    m_Next = g_ClientSendTables.m_Memory.m_pMemory[v3].m_Next;
    if ( m_Next == 0xFFFF )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x10172310
// Name: bool SetupClientSendTableHierarchy(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetupClientSendTableHierarchy()
{
  int v0; // eax
  UtlLinkedListElem_t<CClientSendTable *,unsigned short> *m_pMemory; // ecx
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // esi
  const char *v6; // eax
  CClientSendTable *ClientSendTable; // eax
  int v9; // [esp+Ch] [ebp-Ch]
  const char *pTableName; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  LOWORD(v0) = g_ClientSendTables.m_Head;
  if ( g_ClientSendTables.m_Head == 0xFFFF )
    return 1;
  m_pMemory = g_ClientSendTables.m_Memory.m_pMemory;
  while ( 1 )
  {
    v2 = 8 * (unsigned __int16)v0;
    v3 = *(int *)((char *)&m_pMemory->m_Element + v2);
    v4 = 0;
    v9 = v2;
    if ( *(int *)(v3 + 4) > 0 )
      break;
LABEL_12:
    v0 = *(unsigned __int16 *)((char *)&m_pMemory->m_Next + v2);
    if ( v0 == 0xFFFF )
      return 1;
  }
  v11 = 0;
  while ( 1 )
  {
    v5 = v11 + *(_DWORD *)v3;
    if ( *(_DWORD *)(v5 + 8) == 6 )
      break;
LABEL_10:
    v11 += 84;
    if ( ++v4 >= *(_DWORD *)(v3 + 4) )
    {
      m_pMemory = g_ClientSendTables.m_Memory.m_pMemory;
      goto LABEL_12;
    }
  }
  v6 = *(const char **)(*(_DWORD *)(v3 + 20) + 4 * v4);
  pTableName = v6;
  if ( v6 == nullptr )
  {
    _Error(a1: "SetupClientSendTableHierarchy: missing table name for prop '%s'.", *(const char **)(v5 + 48));
    v6 = nullptr;
  }
  ClientSendTable = FindClientSendTable(pName: v6);
  if ( ClientSendTable != nullptr )
  {
    *(_DWORD *)(v5 + 72) = ClientSendTable;
    v2 = v9;
    goto LABEL_10;
  }
  DataTable_Warning(
    pInMessage: "SetupClientSendTableHierarchy: missing SendTable '%s' (referenced by '%s').\n",
    pTableName,
    *(const char **)(v3 + 8));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101723E0
// Name: bool RecvTable_Decode(class RecvTable __near *,void __near *,class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RecvTable_Decode(RecvTable *pTable, unsigned __int8 *pStruct, bf_read *pIn, int objectID)
{
  if ( g_bDTIEnabled )
    return RecvTable_Decode_Guts<1>(pTable, pStruct, pIn, objectID);
  else
    return RecvTable_Decode_Guts<0>(pTable, pStruct, pIn, objectID);
}

//------------------------------------------------------------------------------
// Address: 0x10172D90
// Name: MatchRecvPropsToSendProps_R
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatchRecvPropsToSendProps_R(
        CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl*)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short> > *lookup,
        const char *sendTableName,
        SendTable *pSendTable,
        RecvTable *pRecvTable)
{
  SendProp *v5; // esi
  const RecvProp *RecvProp; // eax
  RecvProp *v7; // edi
  MatchingProp_t info; // [esp+Ch] [ebp-Ch] BYREF
  int i; // [esp+14h] [ebp-4h]
  SendTable *pSendTablea; // [esp+28h] [ebp+10h]

  i = 0;
  if ( pSendTable->m_nProps <= 0 )
    return 1;
  for ( pSendTablea = nullptr; ; pSendTablea = (SendTable *)((char *)pSendTablea + 84) )
  {
    v5 = (SendProp *)((char *)pSendTablea + (unsigned int)pSendTable->m_pProps);
    if ( (v5->m_Flags & 0x40) == 0 && (v5->m_Flags & 0x100) == 0 )
    {
      if ( pRecvTable == nullptr )
        break;
      RecvProp = FindRecvProp(pTable: pRecvTable, pName: v5->m_pVarName);
      v7 = (RecvProp *)RecvProp;
      if ( RecvProp == nullptr )
        break;
      if ( CompareRecvPropToSendProp(pRecvProp: RecvProp, pSendProp: v5) == 0 )
      {
        _Warning(a1: "RecvProp type doesn't match server type for %s/%s\n", pSendTable->m_pNetTableName, v5->m_pVarName);
        return 0;
      }
      info.m_pProp = v5;
      info.m_pMatchingRecvProp = v7;
      CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl *)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>>::Insert(
        this: lookup,
        insert: &info);
      if ( v5->m_Type == DPT_DataTable
        && !MatchRecvPropsToSendProps_R(
              lookup,
              sendTableName,
              pSendTable: v5->m_pDataTable,
              pRecvTable: v7->m_pDataTable) )
      {
        return 0;
      }
    }
    if ( ++i >= pSendTable->m_nProps )
      return 1;
  }
  _Warning(a1: "Missing RecvProp for %s - %s/%s\n", sendTableName, pSendTable->m_pNetTableName, v5->m_pVarName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10172F30
// Name: CopySendPropsToRecvProps
// Source: json
//------------------------------------------------------------------------------
void __usercall CopySendPropsToRecvProps(
        const CUtlVector<SendProp const *,CUtlMemory<SendProp const *,int> > *sendProps@<edi>,
        CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl*)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short> > *lookup,
        CUtlVector<RecvProp const *,CUtlMemory<RecvProp const *,int> > *recvProps)
{
  int v3; // esi
  unsigned __int16 v4; // ax
  int m_Size; // [esp-4h] [ebp-14h]
  MatchingProp_t search; // [esp+8h] [ebp-8h] BYREF

  v3 = 0;
  m_Size = sendProps->m_Size;
  recvProps->m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)recvProps,
    elem: 0,
    num: m_Size);
  if ( sendProps->m_Size > 0 )
  {
    do
    {
      search.m_pProp = (SendProp *)sendProps->m_Memory.m_pMemory[v3];
      v4 = CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl *)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>>::Find(
             this: lookup,
             &search);
      if ( v4 == 0xFFFF )
        recvProps->m_Memory.m_pMemory[v3] = nullptr;
      else
        recvProps->m_Memory.m_pMemory[v3] = lookup->m_Elements.m_pMemory[v4].m_Data.m_pMatchingRecvProp;
      ++v3;
    }
    while ( v3 < sendProps->m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172FA0
// Name: bool RecvTable_CreateDecoders(class CStandardSendProxies const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RecvTable_CreateDecoders()
{
  char result; // al
  int m_Next; // eax
  UtlLinkedListElem_t<CRecvDecoder *,unsigned short> *m_pMemory; // ecx
  int v3; // ebx
  CRecvDecoder *m_Element; // esi
  CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl*)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short> > PropLookup; // [esp+0h] [ebp-20h] BYREF
  bool bRet; // [esp+1Fh] [ebp-1h]

  DTI_Init();
  result = SetupClientSendTableHierarchy();
  if ( result != 0 )
  {
    LOWORD(m_Next) = g_RecvDecoders.m_Head;
    bRet = true;
    if ( g_RecvDecoders.m_Head == 0xFFFF )
    {
      return bRet;
    }
    else
    {
      m_pMemory = g_RecvDecoders.m_Memory.m_pMemory;
      while ( 1 )
      {
        v3 = (unsigned __int16)m_Next;
        m_Element = m_pMemory[v3].m_Element;
        if ( m_Element->m_pClientSendTable == nullptr
          || !CSendTablePrecalc::SetupFlatPropertyArray(this: &m_Element->m_Precalc) )
        {
          break;
        }
        PropLookup.m_LessFunc = (bool (__cdecl *)(const MatchingProp_t *, const MatchingProp_t *))CDmxSerializationDictionary::LessFunc;
        memset(&PropLookup.m_Elements, 0, sizeof(PropLookup.m_Elements));
        *(_DWORD *)&PropLookup.m_Root = 0xFFFF;
        *(_DWORD *)&PropLookup.m_FirstFree = -1;
        PropLookup.m_pElements = nullptr;
        if ( MatchRecvPropsToSendProps_R(
               lookup: &PropLookup,
               sendTableName: m_Element->m_Precalc.m_pSendTable->m_pNetTableName,
               pSendTable: m_Element->m_Precalc.m_pSendTable,
               pRecvTable: m_Element->m_pTable) != 0 )
        {
          CopySendPropsToRecvProps(
            sendProps: &m_Element->m_Precalc.m_Props,
            lookup: &PropLookup,
            recvProps: &m_Element->m_Props);
          CopySendPropsToRecvProps(
            sendProps: &m_Element->m_Precalc.m_DatatableProps,
            lookup: &PropLookup,
            recvProps: &m_Element->m_DatatableProps);
          DTI_HookRecvDecoder(pDecoder: m_Element);
        }
        else
        {
          bRet = false;
        }
        CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl *)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>>::~CUtlRBTree<MatchingProp_t,unsigned short,bool (__cdecl *)(MatchingProp_t const &,MatchingProp_t const &),CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>>(this: &PropLookup);
        m_pMemory = g_RecvDecoders.m_Memory.m_pMemory;
        m_Next = g_RecvDecoders.m_Memory.m_pMemory[v3].m_Next;
        if ( m_Next == 0xFFFF )
          return bRet;
      }
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10173230
// Name: bool RecvTable_Init(class RecvTable __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RecvTable_Init(RecvTable **pTables, int nTables)
{
  int v2; // eax
  RecvTable *v3; // esi
  unsigned __int16 v4; // ax
  int v5; // edi
  UtlLinkedListElem_t<RecvTable *,unsigned short> *v6; // eax
  int v7; // ebx
  int v8; // edi
  int i; // [esp+0h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < nTables; i = v2 )
  {
    v3 = pTables[v2];
    if ( !v3->m_bInMainList )
    {
      if ( v3->m_pDecoder != nullptr )
        _Error(a1: "RecvTable_Init: table '%s' has a decoder already.", v3->m_pNetTableName);
      v3->m_bInMainList = true;
      v4 = CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal(
             this: &g_RecvTables,
             multilist: false);
      v5 = v4;
      if ( v4 != 0xFFFF )
      {
        CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
          this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvTables,
          before: 0xFFFFu,
          elem: v4);
        v6 = &g_RecvTables.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
          v6->m_Element = v3;
      }
      v7 = 0;
      if ( v3->m_nProps > 0 )
      {
        v8 = 0;
        do
        {
          if ( v3->m_pProps[v8].m_RecvType == DPT_DataTable )
            RecvTable_Init_::_4_::CPropVisitor::Visit_R(pTable: v3->m_pProps[v8].m_pDataTable);
          ++v7;
          ++v8;
        }
        while ( v7 < v3->m_nProps );
      }
    }
    v2 = i + 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101732F0
// Name: void RecvTable_Term(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvTable_Term(bool clearall)
{
  int m_Next; // eax
  int v2; // edi
  RecvTable *m_Element; // ecx
  int v4; // edx
  int v5; // esi
  UtlLinkedListElem_t<RecvTable *,unsigned short> *m_pMemory; // eax

  DTI_Term();
  LOWORD(m_Next) = g_RecvTables.m_Head;
  if ( g_RecvTables.m_Head != 0xFFFF )
  {
    do
    {
      v2 = (unsigned __int16)m_Next;
      m_Element = g_RecvTables.m_Memory.m_pMemory[v2].m_Element;
      if ( m_Element->m_bInMainList )
      {
        v4 = 0;
        v5 = 0;
        m_Element->m_bInMainList = false;
        for ( m_Element->m_pDecoder = nullptr; v5 < m_Element->m_nProps; ++v4 )
        {
          if ( m_Element->m_pProps[v4].m_RecvType == DPT_DataTable )
            RecvTable_Term_::_4_::CPropVisitor::Visit_R(pTable: m_Element->m_pProps[v4].m_pDataTable);
          ++v5;
        }
      }
      m_Next = g_RecvTables.m_Memory.m_pMemory[v2].m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  if ( clearall )
  {
    CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvTables);
    m_pMemory = g_RecvTables.m_Memory.m_pMemory;
    if ( g_RecvTables.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_RecvTables.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RecvTables.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_RecvTables.m_Memory.m_pMemory = nullptr;
      }
      g_RecvTables.m_Memory.m_nAllocationCount = 0;
    }
    g_RecvTables.m_FirstFree = -1;
    *(_DWORD *)&g_RecvTables.m_NumAlloced = -65536;
    g_RecvTables.m_pElements = m_pMemory;
  }
  CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_RecvDecoders);
  CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_ClientSendTables);
}

//------------------------------------------------------------------------------
// Address: 0x101708A0
// Name: _RecvTable_Term_::_4_::CPropVisitor::Visit_R
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl RecvTable_Term_::_4_::CPropVisitor::Visit_R(RecvTable *pTable)
{
  int v1; // ebx
  int v2; // edi

  v1 = 0;
  if ( pTable->m_bInMainList )
  {
    pTable->m_bInMainList = false;
    pTable->m_pDecoder = nullptr;
    if ( pTable->m_nProps > 0 )
    {
      v2 = 0;
      do
      {
        if ( pTable->m_pProps[v2].m_RecvType == DPT_DataTable )
          RecvTable_Term_::_4_::CPropVisitor::Visit_R(pTable: pTable->m_pProps[v2].m_pDataTable);
        ++v1;
        ++v2;
      }
      while ( v1 < pTable->m_nProps );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172E90
// Name: _RecvTable_Init_::_4_::CPropVisitor::Visit_R
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl RecvTable_Init_::_4_::CPropVisitor::Visit_R(RecvTable *pTable)
{
  unsigned __int16 v1; // ax
  int v2; // edi
  UtlLinkedListElem_t<RecvTable *,unsigned short> *v3; // eax
  int v4; // ebx
  int v5; // edi

  if ( !pTable->m_bInMainList )
  {
    if ( pTable->m_pDecoder != nullptr )
      _Error(a1: "RecvTable_Init: table '%s' has a decoder already.", pTable->m_pNetTableName);
    pTable->m_bInMainList = true;
    v1 = CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal(
           this: &g_RecvTables,
           multilist: false);
    v2 = v1;
    if ( v1 != 0xFFFF )
    {
      CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvTables,
        before: 0xFFFFu,
        elem: v1);
      v3 = &g_RecvTables.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
        v3->m_Element = pTable;
    }
    v4 = 0;
    if ( pTable->m_nProps > 0 )
    {
      v5 = 0;
      do
      {
        if ( pTable->m_pProps[v5].m_RecvType == DPT_DataTable )
          RecvTable_Init_::_4_::CPropVisitor::Visit_R(pTable: pTable->m_pProps[v5].m_pDataTable);
        ++v4;
        ++v5;
      }
      while ( v4 < pTable->m_nProps );
    }
  }
}

} // namespace engine_xlsp
