// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt_send_eng.cpp
// Functions: 22
// ============================================================

#include "engine\dt_send_eng.h"

//------------------------------------------------------------------------------
// Address: 0x101731B0
// Name: public: CDeltaCalculator::CDeltaCalculator(class CSendTablePrecalc __near *,void const __near *,int,void const __near *,int,int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CDeltaCalculator *__thiscall CDeltaCalculator::CDeltaCalculator(
        CDeltaCalculator *this,
        CSendTablePrecalc *pPrecalc,
        const unsigned int *pFromState,
        int nFromBits,
        const unsigned int *pToState,
        int nToBits,
        int *pDeltaProps,
        int nMaxDeltaProps,
        int objectID)
{
  bf_read *p_m_bfFromState; // edi
  int NextPropIndex; // eax

  p_m_bfFromState = &this->m_bfFromState;
  this->m_bfFromState.m_bOverflow = false;
  this->m_bfFromState.m_nDataBits = -1;
  this->m_bfFromState.m_nDataBytes = 0;
  this->m_bfFromState.m_pDebugName = "CDeltaCalculator->m_bfFromState";
  CBitRead::StartReading(
    this: &this->m_bfFromState,
    pData: pFromState,
    nBytes: (nFromBits + 7) >> 3,
    iStartBit: 0,
    nBits: nFromBits);
  this->m_bfToState.m_bOverflow = false;
  this->m_bfToState.m_nDataBits = -1;
  this->m_bfToState.m_nDataBytes = 0;
  this->m_bfToState.m_pDebugName = "CDeltaCalculator->m_bfToState";
  CBitRead::StartReading(
    this: &this->m_bfToState,
    pData: pToState,
    nBytes: (nToBits + 7) >> 3,
    iStartBit: 0,
    nBits: nToBits);
  CDeltaBitsReader::CDeltaBitsReader(this: &this->m_FromBitsReader, pBuf: p_m_bfFromState);
  CDeltaBitsReader::CDeltaBitsReader(this: &this->m_ToBitsReader, pBuf: &this->m_bfToState);
  this->m_pPrecalc = pPrecalc;
  this->m_ObjectID = objectID;
  this->m_pDeltaProps = pDeltaProps;
  this->m_nMaxDeltaProps = nMaxDeltaProps;
  this->m_nDeltaProps = 0;
  if ( pFromState != nullptr )
  {
    NextPropIndex = CDeltaBitsReader::ReadNextPropIndex(this: &this->m_FromBitsReader);
    if ( NextPropIndex < 0 )
      NextPropIndex = 0x7FFFFFFF;
    this->m_iFromProp = NextPropIndex;
    this->m_iToProp = -1;
    return this;
  }
  else
  {
    this->m_iFromProp = 0x7FFFFFFF;
    this->m_iToProp = -1;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101732A0
// Name: public: CDeltaCalculator::~CDeltaCalculator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaCalculator::~CDeltaCalculator(CDeltaCalculator *this)
{
  int m_nDeltaProps; // eax
  int m_nMaxDeltaProps; // ecx

  m_nDeltaProps = this->m_nDeltaProps;
  m_nMaxDeltaProps = this->m_nMaxDeltaProps;
  if ( m_nDeltaProps > m_nMaxDeltaProps )
    _Error(
      a1: "SendTable_CalcDelta: overflowed props %d max %d on datatable '%s'.",
      m_nDeltaProps,
      m_nMaxDeltaProps,
      this->m_pPrecalc->m_pSendTable->m_pNetTableName);
  if ( this->m_bfFromState.m_bOverflow )
    _Error(
      a1: "SendTable_CalcDelta: m_bfFromState overflowed %d max %d on datatable '%s'.",
      this->m_nDeltaProps,
      this->m_nMaxDeltaProps,
      this->m_pPrecalc->m_pSendTable->m_pNetTableName);
  if ( this->m_bfToState.m_bOverflow )
    _Error(
      a1: "SendTable_CalcDelta: m_bfToState overflowed %d max %d on datatable '%s'.",
      this->m_nDeltaProps,
      this->m_nMaxDeltaProps,
      this->m_pPrecalc->m_pSendTable->m_pNetTableName);
  CDeltaBitsReader::ForceFinished(this: &this->m_FromBitsReader);
  CDeltaBitsReader::ForceFinished(this: &this->m_ToBitsReader);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&this->m_ToBitsReader);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&this->m_FromBitsReader);
}

//------------------------------------------------------------------------------
// Address: 0x10173350
// Name: bool SendTable_WriteInfos(class SendTable __near *,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SendTable_WriteInfos(SendTable *pTable, bf_write *pBuf)
{
  SendProp *v4; // esi
  SendPropType m_Type; // eax
  int v7; // [esp+10h] [ebp+8h]
  int v8; // [esp+14h] [ebp+Ch]

  bf_write::WriteString(this: pBuf, pStr: pTable->m_pNetTableName);
  bf_write::WriteUBitLong(this: pBuf, curData: pTable->m_nProps, numbits: 10, bCheckRange: true);
  v8 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v7 = 0;
    do
    {
      v4 = &pTable->m_pProps[v7];
      bf_write::WriteUBitLong(this: pBuf, curData: v4->m_Type, numbits: 5, bCheckRange: true);
      bf_write::WriteString(this: pBuf, pStr: v4->m_pVarName);
      bf_write::WriteUBitLong(this: pBuf, curData: v4->m_Flags & 0x7FFFF, numbits: 19, bCheckRange: true);
      bf_write::WriteByte(this: pBuf, val: v4->m_priority);
      m_Type = v4->m_Type;
      if ( m_Type == DPT_DataTable )
      {
        bf_write::WriteString(this: pBuf, pStr: v4->m_pDataTable->m_pNetTableName);
      }
      else if ( (v4->m_Flags & 0x40) != 0 )
      {
        bf_write::WriteString(this: pBuf, pStr: v4->m_pExcludeDTName);
      }
      else if ( m_Type == DPT_Array )
      {
        bf_write::WriteUBitLong(this: pBuf, curData: v4->m_nElements, numbits: 10, bCheckRange: true);
      }
      else
      {
        bf_write::WriteBitFloat(this: pBuf, val: COERCE_UNSIGNED_INT(v4->m_fLowValue));
        bf_write::WriteBitFloat(this: pBuf, val: COERCE_UNSIGNED_INT(v4->m_fHighValue));
        bf_write::WriteUBitLong(this: pBuf, curData: v4->m_nBits, numbits: 7, bCheckRange: true);
      }
      ++v7;
      ++v8;
    }
    while ( v8 < pTable->m_nProps );
  }
  return !pBuf->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x10173460
// Name: SendTable_CalcNextVectorElems
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_CalcNextVectorElems(SendTable *pTable)
{
  int v1; // ebx
  int v2; // esi
  SendProp *v3; // eax

  v1 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v2 = 0;
    do
    {
      v3 = &pTable->m_pProps[v2];
      if ( v3->m_Type == DPT_DataTable )
        SendTable_CalcNextVectorElems(pTable: v3->m_pDataTable);
      ++v1;
      ++v2;
    }
    while ( v1 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101734B0
// Name: unsigned long SendTable_GetCRC(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl SendTable_GetCRC()
{
  return g_SendTableCRC;
}

//------------------------------------------------------------------------------
// Address: 0x101734C0
// Name: public: void CPropCullStack::CullPropsFromProxies(int const __near *,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropCullStack::CullPropsFromProxies(
        CPropCullStack *this,
        const int *pStartProps,
        int nStartProps,
        int *pOutProps,
        int nMaxOutProps)
{
  int v6; // eax
  int *m_NewProxyProps; // edi
  int v8; // ebx
  int j; // eax
  int m_nOutProps; // ecx
  int v11; // eax
  int k; // eax
  int v13; // ecx
  int i; // [esp+1Ch] [ebp+10h]

  this->m_nMaxOutProps = nMaxOutProps;
  this->m_nOutProps = 0;
  this->m_pOutProps = pOutProps;
  this->m_nNewProxyProps = 0;
  CDatatableStack::Init(this, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  v6 = 0;
  this->m_NewProxyProps[this->m_nNewProxyProps] = 0x7FFFFFFF;
  m_NewProxyProps = this->m_NewProxyProps;
  for ( i = 0; v6 < nStartProps; i = v6 )
  {
    v8 = pStartProps[v6];
    for ( j = *m_NewProxyProps; j < v8; ++m_NewProxyProps )
    {
      m_nOutProps = this->m_nOutProps;
      if ( m_nOutProps >= this->m_nMaxOutProps )
        _Error(a1: "CPropCullStack::AddProp - m_pOutProps overflowed");
      else
        this->m_pOutProps[m_nOutProps] = j;
      ++this->m_nOutProps;
      j = m_NewProxyProps[1];
    }
    if ( this->m_pProxies[this->CDatatableStack::m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v8]] != nullptr )
    {
      v11 = this->m_nOutProps;
      if ( v11 >= this->m_nMaxOutProps )
        _Error(a1: "CPropCullStack::AddProp - m_pOutProps overflowed");
      else
        this->m_pOutProps[v11] = v8;
      ++this->m_nOutProps;
      if ( *m_NewProxyProps == v8 )
        ++m_NewProxyProps;
    }
    v6 = i + 1;
  }
  for ( k = *m_NewProxyProps; k != 0x7FFFFFFF; ++m_NewProxyProps )
  {
    v13 = this->m_nOutProps;
    if ( v13 >= this->m_nMaxOutProps )
      _Error(a1: "CPropCullStack::AddProp - m_pOutProps overflowed");
    else
      this->m_pOutProps[v13] = k;
    ++this->m_nOutProps;
    k = m_NewProxyProps[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173610
// Name: int SendTable_CullPropsFromProxies(class SendTable const __near *,int const __near *,int,int,class CSendProxyRecipients const __near *,int,class CSendProxyRecipients const __near *,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SendTable_CullPropsFromProxies(
        const SendTable *pTable,
        int *pStartProps,
        int nStartProps,
        int iClient,
        const CSendProxyRecipients *pOldStateProxies,
        int nOldStateProxies,
        const CSendProxyRecipients *pNewStateProxies,
        int nNewStateProxies,
        int *pOutProps,
        int nMaxOutProps)
{
  CSendTablePrecalc *m_pPrecalc; // esi
  int result; // eax
  CPropCullStack v12; // [esp+8h] [ebp-4148h] BYREF

  m_pPrecalc = pTable->m_pPrecalc;
  CDatatableStack::CDatatableStack(this: &v12, pPrecalc: m_pPrecalc, pStructBase: (unsigned __int8 *)1, objectID: -1);
  v12.m_pOldStateProxies = pOldStateProxies;
  v12.m_pPrecalc = m_pPrecalc;
  v12.m_nOldStateProxies = nOldStateProxies;
  v12.m_pNewStateProxies = pNewStateProxies;
  v12.m_nNewStateProxies = nNewStateProxies;
  v12.m_iClient = iClient;
  v12.__vftable = (CPropCullStack_vtbl *)&CPropCullStack::`vftable';
  CPropCullStack::CullPropsFromProxies(this: &v12, pStartProps, nStartProps, pOutProps, nMaxOutProps);
  result = v12.m_nOutProps;
  if ( v12.m_nOutProps > nMaxOutProps )
  {
    _Error(a1: "CullPropsFromProxies: overflow in '%s'.", pTable->m_pNetTableName);
    return v12.m_nOutProps;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101736C0
// Name: int SendTable_GetNumFlatProps(class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SendTable_GetNumFlatProps(SendTable *pSendTable)
{
  CSendTablePrecalc *m_pPrecalc; // esi

  m_pPrecalc = pSendTable->m_pPrecalc;
  if ( m_pPrecalc == nullptr )
    _Error(a1: "SendTable_GetNumFlatProps: missing pPrecalc.");
  return m_pPrecalc->m_Props.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101736F0
// Name: public: virtual void CPropCullStack::RecurseAndCallProxies(class CSendNode __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropCullStack::RecurseAndCallProxies(
        CPropCullStack *this,
        CSendNode *pNode,
        unsigned __int8 *pStructBase)
{
  CSendNode *v4; // ecx
  int v5; // eax
  CSendNode *v6; // edi
  int v7; // eax
  int m_DataTableProxyIndex; // ecx
  unsigned int m_iClient; // eax
  const CSendProxyRecipients *m_pOldStateProxies; // edx
  bool v11; // bl
  bool v12; // al
  int v13; // ebx
  unsigned int m_nNewProxyProps; // eax
  int iChild; // [esp+8h] [ebp-8h]

  v4 = pNode;
  this->m_pProxies[pNode->m_RecursiveProxyIndex] = pStructBase;
  v5 = 0;
  for ( iChild = 0; v5 < pNode->m_Children.m_Size; iChild = v5 )
  {
    v6 = v4->m_Children.m_Memory.m_pMemory[v5];
    v7 = 0;
    if ( pStructBase != nullptr )
    {
      m_DataTableProxyIndex = v6->m_DataTableProxyIndex;
      if ( (_WORD)m_DataTableProxyIndex == 255 )
      {
        v7 = 1;
      }
      else
      {
        m_iClient = this->m_iClient;
        m_pOldStateProxies = this->m_pOldStateProxies;
        v11 = ((1 << (m_iClient & 0x1F)) & this->m_pNewStateProxies[m_DataTableProxyIndex].m_Bits.m_Ints[m_iClient >> 5]) != 0;
        if ( m_pOldStateProxies == nullptr
          || (v12 = ((1 << (m_iClient & 0x1F)) & m_pOldStateProxies[m_DataTableProxyIndex].m_Bits.m_Ints[m_iClient >> 5]) != 0) == v11 )
        {
          v7 = v11;
        }
        else if ( v12 )
        {
          v7 = 0;
        }
        else
        {
          v13 = 0;
          if ( v6->m_nRecursiveProps != 0 )
          {
            do
            {
              m_nNewProxyProps = this->m_nNewProxyProps;
              if ( m_nNewProxyProps >= 0x1001 )
                _Error(a1: "CPropCullStack::CallPropProxy - overflowed m_nNewProxyProps");
              else
                this->m_NewProxyProps[m_nNewProxyProps] = v13 + v6->m_iFirstRecursiveProp;
              ++this->m_nNewProxyProps;
              ++v13;
            }
            while ( v13 < v6->m_nRecursiveProps );
          }
          v7 = 0;
        }
      }
    }
    this->RecurseAndCallProxies(this, a2: v6, a3: (unsigned __int8 *)v7);
    v4 = pNode;
    v5 = iChild + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173820
// Name: public: void CDeltaCalculator::PropCalcDelta(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101738E0
// Name: ShowEncodeDeltaWatchInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowEncodeDeltaWatchInfo(
        char *what,
        const SendTable *pTable,
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
    if ( host_framecount != lastframe_0 )
    {
      lastframe_0 = host_framecount;
      _ConDMsg(a1: "E: delta entity: %i %s\n", objectID, pTable->m_pNetTableName);
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
      a1: "E[%s]:%s %s, %s, index %i, offset %i, bits %i, value %s\n",
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
// Address: 0x10173A40
// Name: SendTable_EncodeProp
// Source: json
//------------------------------------------------------------------------------
void __usercall SendTable_EncodeProp(CEncodeInfo *pInfo@<esi>, int iProp@<eax>)
{
  int m_iCurProp; // eax
  const SendProp *v3; // edi
  CSendTablePrecalc *m_pPrecalc; // ecx
  unsigned __int8 *v5; // eax
  int m_iCurBit; // ebx
  DVariant var; // [esp+8h] [ebp-18h] BYREF

  CDeltaBitsWriter::WritePropIndex(this: pInfo->m_pDeltaBitsWriter, iProp);
  m_iCurProp = pInfo->m_iCurProp;
  v3 = pInfo->CServerDatatableStack::m_pPrecalc->m_Props.m_Memory.m_pMemory[m_iCurProp];
  m_pPrecalc = pInfo->CServerDatatableStack::CDatatableStack::m_pPrecalc;
  var.m_Type = DPT_Float;
  v5 = pInfo->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[m_iCurProp]];
  v3->m_ProxyFn(a1: v3, a2: v5, a3: &v5[v3->m_Offset & 0xFFFFF], a4: &var, a5: 0, a6: pInfo->m_ObjectID);
  m_iCurBit = pInfo->m_pOut->m_iCurBit;
  ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *))g_PropTypeFns[v3->m_Type].Encode)(
    pStruct: pInfo->m_pProxies[pInfo->CServerDatatableStack::CDatatableStack::m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[pInfo->m_iCurProp]],
    pVar: &var,
    pProp: v3,
    pOut: pInfo->m_pOut);
  pInfo->m_nDataBits += pInfo->m_pOut->m_iCurBit - m_iCurBit;
}

//------------------------------------------------------------------------------
// Address: 0x10173AF0
// Name: SendTable_IsPropZero
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall SendTable_IsPropZero@<eax>(CEncodeInfo *pInfo@<eax>)
{
  const SendProp **m_pMemory; // edx
  int m_iCurProp; // eax
  CSendTablePrecalc *m_pPrecalc; // ecx
  const SendProp *v5; // edi
  unsigned __int8 *v6; // eax
  DVariant var; // [esp+8h] [ebp-18h] BYREF

  m_pMemory = pInfo->CServerDatatableStack::m_pPrecalc->m_Props.m_Memory.m_pMemory;
  m_iCurProp = pInfo->m_iCurProp;
  m_pPrecalc = pInfo->CServerDatatableStack::CDatatableStack::m_pPrecalc;
  v5 = m_pMemory[m_iCurProp];
  var.m_Type = DPT_Float;
  v6 = pInfo->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[m_iCurProp]];
  v5->m_ProxyFn(a1: v5, a2: v6, a3: &v6[v5->m_Offset & 0xFFFFF], a4: &var, a5: 0, a6: pInfo->m_ObjectID);
  return ((BOOL (__cdecl *)(const unsigned __int8 *, DVariant *))*(&funcs_10173B68 + 9 * v5->m_Type))(
           pStruct: pInfo->m_pProxies[pInfo->CServerDatatableStack::CDatatableStack::m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[pInfo->m_iCurProp]],
           pVar: &var);
}

//------------------------------------------------------------------------------
// Address: 0x10173B80
// Name: bool SendTable_Encode(class SendTable const __near *,void const __near *,class bf_write __near *,int,class CUtlMemory<class CSendProxyRecipients,int> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SendTable_Encode(
        const SendTable *pTable,
        unsigned __int8 *pStruct,
        bf_write *pOut,
        int objectID,
        CUtlMemory<CSendProxyRecipients,int> *pRecipients,
        bool bNonZeroOnly)
{
  CSendTablePrecalc *m_pPrecalc; // esi
  int m_Size; // ebx
  int i; // edi
  bool v9; // bl
  CEncodeInfo info; // [esp+Ch] [ebp-160h] BYREF
  CDeltaBitsWriter deltaBitsWriter; // [esp+148h] [ebp-24h] BYREF
  unsigned __int64 v13; // [esp+154h] [ebp-18h]
  CServerDTITimer timer; // [esp+15Ch] [ebp-10h] BYREF

  m_pPrecalc = pTable->m_pPrecalc;
  if ( m_pPrecalc == nullptr )
    _Error(a1: "SendTable_Encode: Missing m_pPrecalc for SendTable %s.", pTable->m_pNetTableName);
  if ( pRecipients != nullptr && pRecipients->m_nAllocationCount < m_pPrecalc->m_nDataTableProxies )
    _Error(a1: "SendTable_Encode: pRecipients array too small.");
  timer.m_Timer.m_Duration.m_Int64 = 0;
  if ( g_bServerDTIEnabled )
  {
    timer.m_pTable = pTable;
    timer.m_Type = SERVERDTI_ENCODE;
    timer.m_Timer.m_Duration.m_Int64 = __rdtsc();
  }
  CDeltaBitsWriter::CDeltaBitsWriter(this: &deltaBitsWriter, pBuf: pOut);
  CDatatableStack::CDatatableStack(this: &info, pPrecalc: m_pPrecalc, pStructBase: pStruct, objectID);
  info.m_pDeltaBitsWriter = &deltaBitsWriter;
  info.CServerDatatableStack::m_pPrecalc = m_pPrecalc;
  info.__vftable = (CEncodeInfo_vtbl *)&CEncodeInfo::`vftable';
  info.m_pOut = pOut;
  info.m_ObjectID = objectID;
  info.m_nDataBits = 0;
  info.m_nOverheadBits = 0;
  info.m_pRecipients = pRecipients;
  CDatatableStack::Init(this: &info, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  m_Size = m_pPrecalc->m_Props.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    if ( info.m_pProxies[info.CServerDatatableStack::CDatatableStack::m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]] != nullptr )
    {
      info.m_iCurProp = i;
      info.m_pCurProp = info.CServerDatatableStack::CDatatableStack::m_pPrecalc->m_Props.m_Memory.m_pMemory[i];
      if ( !bNonZeroOnly || !SendTable_IsPropZero(pInfo: &info) )
        SendTable_EncodeProp(pInfo: &info, iProp: i);
    }
  }
  v9 = !pOut->m_bOverflow;
  CDeltaBitsWriter::~CDeltaBitsWriter(this: &deltaBitsWriter);
  if ( g_bServerDTIEnabled && timer.m_pTable != nullptr )
  {
    v13 = __rdtsc();
    timer.m_Timer.m_Duration.m_Int64 = v13 - timer.m_Timer.m_Duration.m_Int64;
    _ServerDTI_HookTimer(pSendTable: timer.m_pTable, timerType: timer.m_Type, count: &timer.m_Timer.m_Duration);
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10173D10
// Name: void SendTable_WritePropList(class SendTable const __near *,void const __near *,int,class bf_write __near *,int,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SendTable_WritePropList(
        const SendProp *a1@<edi>,
        bf_write *a2@<esi>,
        const SendTable *pTable,
        const unsigned int *pState,
        int nBits,
        bf_write *pOut,
        int objectID,
        const int *pCheckProps,
        int nCheckProps)
{
  bf_write *v9; // ebx
  CSendTablePrecalc *m_pPrecalc; // edi
  int v11; // esi
  const int *v12; // ebx
  const SendProp *v13; // edi
  int m_nDataBits; // ebx
  int v15; // ecx
  int v16; // edi
  int v17; // ecx
  int v18; // eax
  const SendProp *v19; // [esp-8h] [ebp-5Ch]
  bf_write *v20; // [esp-4h] [ebp-58h]
  DVariant *v21; // [esp+0h] [ebp-54h]
  bf_read inputBuffer; // [esp+4h] [ebp-50h] BYREF
  CDeltaBitsReader inputBitsReader; // [esp+28h] [ebp-2Ch] BYREF
  CDeltaBitsWriter deltaBitsWriter; // [esp+38h] [ebp-1Ch] BYREF
  int i; // [esp+44h] [ebp-10h]
  CSendTablePrecalc *pPrecalc; // [esp+48h] [ebp-Ch]
  const int *v27; // [esp+4Ch] [ebp-8h]
  bool bDebugWatch; // [esp+53h] [ebp-1h]

  v9 = pOut;
  CDeltaBitsWriter::CDeltaBitsWriter(this: &deltaBitsWriter, pBuf: pOut);
  if ( nCheckProps != 0 )
  {
    v20 = a2;
    v19 = a1;
    bDebugWatch = Sendprop_UsingDebugWatch();
    s_debug_info_shown = false;
    s_debug_bits_start = pOut->m_iCurBit;
    m_pPrecalc = pTable->m_pPrecalc;
    pPrecalc = m_pPrecalc;
    inputBuffer.m_bOverflow = false;
    inputBuffer.m_nDataBits = -1;
    inputBuffer.m_nDataBytes = 0;
    inputBuffer.m_pDebugName = "SendTable_WritePropList->inputBuffer";
    CBitRead::StartReading(this: &inputBuffer, pData: pState, nBytes: (nBits + 7) >> 3, iStartBit: 0, nBits);
    CDeltaBitsReader::CDeltaBitsReader(this: &inputBitsReader, pBuf: &inputBuffer);
    v11 = CDeltaBitsReader::ReadNextPropIndex(this: &inputBitsReader);
    if ( v11 < 0 )
      v11 = 0x7FFFFFFF;
    i = 0;
    if ( nCheckProps > 0 )
    {
      v12 = pCheckProps;
      v27 = pCheckProps;
      do
      {
        while ( v11 < *v12 )
        {
          ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B172[9 * m_pPrecalc->m_Props.m_Memory.m_pMemory[v11]->m_Type])(
            pStruct: (const unsigned __int8 *)m_pPrecalc->m_Props.m_Memory.m_pMemory[v11],
            pVar: (DVariant *)&inputBuffer,
            pProp: v19,
            pOut: v20,
            objectID: v21);
          v11 = CDeltaBitsReader::ReadNextPropIndex(this: &inputBitsReader);
          if ( v11 < 0 )
            v11 = 0x7FFFFFFF;
        }
        if ( v11 == 0x7FFFFFFF )
          break;
        if ( v11 == *v12 )
        {
          v13 = m_pPrecalc->m_Props.m_Memory.m_pMemory[v11];
          if ( bDebugWatch )
            ShowEncodeDeltaWatchInfo(what: "New", pTable, pProp: v13, buffer: &inputBuffer, objectID, index: v11);
          if ( inputBuffer.m_pData != nullptr )
          {
            m_nDataBits = inputBuffer.m_nDataBits;
            v15 = 32 * (inputBuffer.m_pDataIn - inputBuffer.m_pData) - inputBuffer.m_nBitsAvail;
            if ( v15 + 8 * (inputBuffer.m_nDataBytes & 3) < inputBuffer.m_nDataBits )
              m_nDataBits = v15 + 8 * (inputBuffer.m_nDataBytes & 3);
          }
          else
          {
            m_nDataBits = 0;
          }
          ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B172[9 * v13->m_Type])(
            pStruct: (const unsigned __int8 *)v13,
            pVar: (DVariant *)&inputBuffer,
            pProp: v19,
            pOut: v20,
            objectID: v21);
          if ( inputBuffer.m_pData != nullptr )
          {
            v16 = inputBuffer.m_nDataBits;
            v17 = 32 * (inputBuffer.m_pDataIn - inputBuffer.m_pData) - inputBuffer.m_nBitsAvail;
            if ( v17 + 8 * (inputBuffer.m_nDataBytes & 3) < inputBuffer.m_nDataBits )
              v16 = v17 + 8 * (inputBuffer.m_nDataBytes & 3);
          }
          else
          {
            v16 = 0;
          }
          CDeltaBitsWriter::WritePropIndex(this: &deltaBitsWriter, iProp: v11);
          CBitRead::Seek(this: &inputBuffer, nPosition: m_nDataBits);
          bf_write::WriteBitsFromBuffer(this: pOut, pIn: &inputBuffer, nBits: v16 - m_nDataBits);
          v18 = CDeltaBitsReader::ReadNextPropIndex(this: &inputBitsReader);
          m_pPrecalc = pPrecalc;
          v12 = v27;
          v11 = v18;
          if ( v18 < 0 )
            v11 = 0x7FFFFFFF;
        }
        ++v12;
        ++i;
        v27 = v12;
      }
      while ( i < nCheckProps );
      v9 = pOut;
    }
    if ( s_debug_info_shown )
      _ConDMsg(
        a1: "E= %i bits (%i bytes)\n",
        v9->m_iCurBit - s_debug_bits_start,
        (v9->m_iCurBit - s_debug_bits_start + 7) >> 3);
    CDeltaBitsReader::ForceFinished(this: &inputBitsReader);
    CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&inputBitsReader);
  }
  CDeltaBitsWriter::~CDeltaBitsWriter(this: &deltaBitsWriter);
}

//------------------------------------------------------------------------------
// Address: 0x10173F40
// Name: int SendTable_CalcDelta(class SendTable const __near *,void const __near *,int,void const __near *,int,int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SendTable_CalcDelta(
        const SendTable *pTable,
        unsigned int *pFromState,
        int nFromBits,
        unsigned int *pToState,
        int nToBits,
        int *pDeltaProps,
        int nMaxDeltaProps,
        int objectID)
{
  int NextPropIndex; // eax
  const SendProp *v10; // eax
  int m_nDeltaProps; // esi
  CDeltaCalculator deltaCalc; // [esp+0h] [ebp-A4h] BYREF
  CFastTimer *p_m_Timer; // [esp+88h] [ebp-1Ch]
  CServerDTITimer timer; // [esp+8Ch] [ebp-18h] BYREF
  unsigned __int64 v15; // [esp+9Ch] [ebp-8h] BYREF

  timer.m_Timer.m_Duration.m_Int64 = 0;
  if ( g_bServerDTIEnabled )
  {
    timer.m_pTable = pTable;
    timer.m_Type = SERVERDTI_CALCDELTA;
    p_m_Timer = &timer.m_Timer;
    timer.m_Timer.m_Duration.m_Int64 = __rdtsc();
  }
  if ( CompareBitArrays(pPacked1: pFromState, pPacked2: pToState, nBits1: nFromBits, nBits2: nToBits) != 0 )
  {
    if ( g_bServerDTIEnabled && timer.m_pTable != nullptr )
    {
      p_m_Timer = (CFastTimer *)&v15;
      v15 = __rdtsc();
      timer.m_Timer.m_Duration.m_Int64 = v15 - timer.m_Timer.m_Duration.m_Int64;
      _ServerDTI_HookTimer(pSendTable: timer.m_pTable, timerType: timer.m_Type, count: &timer.m_Timer.m_Duration);
    }
    return 0;
  }
  else
  {
    CDeltaCalculator::CDeltaCalculator(
      this: &deltaCalc,
      pPrecalc: pTable->m_pPrecalc,
      pFromState,
      nFromBits,
      pToState,
      nToBits,
      pDeltaProps,
      nMaxDeltaProps,
      objectID);
    while ( 1 )
    {
      NextPropIndex = CDeltaBitsReader::ReadNextPropIndex(this: &deltaCalc.m_ToBitsReader);
      if ( NextPropIndex < 0 )
        NextPropIndex = 0x7FFFFFFF;
      deltaCalc.m_iToProp = NextPropIndex;
      if ( NextPropIndex == 0x7FFFFFFF )
        break;
      if ( pFromState != nullptr )
      {
        CDeltaCalculator::PropCalcDelta(this: &deltaCalc);
      }
      else
      {
        v10 = deltaCalc.m_pPrecalc->m_Props.m_Memory.m_pMemory[NextPropIndex];
        if ( !(*(&funcs_1016B3E2 + 9 * v10->m_Type))(pProp: v10, pIn: &deltaCalc.m_bfToState) )
        {
          if ( deltaCalc.m_nDeltaProps < deltaCalc.m_nMaxDeltaProps )
            deltaCalc.m_pDeltaProps[deltaCalc.m_nDeltaProps] = deltaCalc.m_iToProp;
          ++deltaCalc.m_nDeltaProps;
        }
      }
    }
    m_nDeltaProps = deltaCalc.m_nDeltaProps;
    CDeltaCalculator::~CDeltaCalculator(this: &deltaCalc);
    if ( g_bServerDTIEnabled && timer.m_pTable != nullptr )
    {
      p_m_Timer = (CFastTimer *)&v15;
      v15 = __rdtsc();
      timer.m_Timer.m_Duration.m_Int64 = v15 - timer.m_Timer.m_Duration.m_Int64;
      _ServerDTI_HookTimer(pSendTable: timer.m_pTable, timerType: timer.m_Type, count: &timer.m_Timer.m_Duration);
    }
    return m_nDeltaProps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101740F0
// Name: SendTable_Validate
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_Validate(CSendTablePrecalc *pPrecalc)
{
  CSendTablePrecalc *v1; // ecx
  SendTable *m_pSendTable; // edi
  int v3; // ebx
  SendProp *v4; // esi
  SendProp *m_pArrayProp; // eax
  int m_Size; // edx
  int v7; // eax
  const SendProp **i; // ecx
  int v9; // [esp+Ch] [ebp-4h]

  v1 = pPrecalc;
  m_pSendTable = pPrecalc->m_pSendTable;
  v3 = 0;
  if ( m_pSendTable->m_nProps > 0 )
  {
    v9 = 0;
    do
    {
      v4 = &m_pSendTable->m_pProps[v9];
      m_pArrayProp = v4->m_pArrayProp;
      if ( m_pArrayProp != nullptr )
      {
        if ( m_pArrayProp->m_Type == DPT_DataTable )
          _Error(
            a1: "Invalid property: %s/%s (array of datatables) [on prop %d of %d (%s)].",
            m_pSendTable->m_pNetTableName,
            v4->m_pVarName,
            v3,
            m_pSendTable->m_nProps,
            m_pArrayProp->m_pVarName);
      }
      else if ( v4->m_nElements != 1 )
      {
        _Error(
          a1: "Prop %s/%s has an invalid element count for a non-array.",
          m_pSendTable->m_pNetTableName,
          v4->m_pVarName);
      }
      if ( v4->m_nBits == 1 && (v4->m_Flags & 1) == 0 )
        DataTable_Warning(
          pInMessage: "SendTable prop %s::%s is a 1-bit signed property. Use SPROP_UNSIGNED or the client will never receive a value.\n",
          m_pSendTable->m_pNetTableName,
          v4->m_pVarName);
      ++v9;
      ++v3;
    }
    while ( v3 < m_pSendTable->m_nProps );
    v1 = pPrecalc;
  }
  m_Size = v1->m_Props.m_Size;
  v7 = 0;
  if ( m_Size > 0 )
  {
    for ( i = v1->m_Props.m_Memory.m_pMemory; ((*i)->m_Flags & 0x80000) == 0; ++i )
    {
      if ( ++v7 >= m_Size )
        return;
    }
    *((_BYTE *)m_pSendTable + 16) |= 4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101741D0
// Name: void SendTable_PrintStats(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_PrintStats()
{
  int v0; // edi
  int v1; // ebx
  SendTable *v2; // eax
  int m_nProps; // ecx
  int *p_m_Flags; // eax
  int i; // esi
  int numTables; // [esp+Ch] [ebp-28h]
  int numExcludeProps; // [esp+10h] [ebp-24h]
  int numSubTables; // [esp+14h] [ebp-20h]
  int numArrays; // [esp+18h] [ebp-1Ch]
  int numStrings; // [esp+1Ch] [ebp-18h]
  int numVecXYs; // [esp+20h] [ebp-14h]
  int numVecs; // [esp+24h] [ebp-10h]
  int numFloats; // [esp+28h] [ebp-Ch]
  int numInts; // [esp+2Ch] [ebp-8h]
  int numSendProps; // [esp+30h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  numTables = 0;
  numFloats = 0;
  numStrings = 0;
  numArrays = 0;
  numInts = 0;
  numVecs = 0;
  numVecXYs = 0;
  numSubTables = 0;
  numSendProps = 0;
  numExcludeProps = 0;
  if ( g_SendTables.m_Size > 0 )
  {
    numTables = g_SendTables.m_Size;
    do
    {
      v2 = g_SendTables.m_Memory.m_pMemory[v1];
      m_nProps = v2->m_nProps;
      numSendProps += m_nProps;
      v0 += v2->m_pPrecalc->m_Props.m_Size;
      if ( m_nProps > 0 )
      {
        p_m_Flags = &v2->m_pProps->m_Flags;
        for ( i = m_nProps; i != 0; --i )
        {
          if ( (*p_m_Flags & 0x40) != 0 )
          {
            ++numExcludeProps;
          }
          else if ( (*p_m_Flags & 0x100) == 0 )
          {
            switch ( *(p_m_Flags - 13) )
            {
              case 0:
                ++numInts;
                break;
              case 1:
                ++numFloats;
                break;
              case 2:
                ++numVecs;
                break;
              case 3:
                ++numVecXYs;
                break;
              case 4:
                ++numStrings;
                break;
              case 5:
                ++numArrays;
                break;
              case 6:
                ++numSubTables;
                break;
              default:
                break;
            }
          }
          p_m_Flags += 21;
        }
      }
      ++v1;
    }
    while ( v1 < g_SendTables.m_Size );
  }
  _Msg(a1: "Total Send Table stats\n");
  _Msg(a1: "Send Tables   : %i\n", numTables);
  _Msg(a1: "Send Props    : %i\n", numSendProps);
  _Msg(a1: "Flat Props    : %i\n", v0);
  _Msg(a1: "Int Props     : %i\n", numInts);
  _Msg(a1: "Float Props   : %i\n", numFloats);
  _Msg(a1: "Vector Props  : %i\n", numVecs);
  _Msg(a1: "VectorXY Props: %i\n", numVecXYs);
  _Msg(a1: "String Props  : %i\n", numStrings);
  _Msg(a1: "Array Props   : %i\n", numArrays);
  _Msg(a1: "Table Props   : %i\n", numSubTables);
  _Msg(a1: "Exclu Props   : %i\n", numExcludeProps);
}

//------------------------------------------------------------------------------
// Address: 0x10174340
// Name: unsigned long SendTable_ComputeCRC(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl SendTable_ComputeCRC()
{
  int m_Size; // edi
  int v1; // esi
  SendTable *v2; // ebx
  int v3; // eax
  SendProp *v4; // esi
  const char *m_pVarName; // edi
  int v6; // eax
  SendPropType v7; // eax
  SendTable *m_pDataTable; // esi
  int v9; // eax
  const char *m_pExcludeDTName; // esi
  int v11; // eax
  int c; // [esp+8h] [ebp-30h]
  int m_nBits; // [esp+Ch] [ebp-2Ch] BYREF
  float m_fHighValue; // [esp+10h] [ebp-28h] BYREF
  float m_fLowValue; // [esp+14h] [ebp-24h] BYREF
  int m_nElements; // [esp+18h] [ebp-20h] BYREF
  int m_Flags; // [esp+1Ch] [ebp-1Ch] BYREF
  SendPropType m_Type; // [esp+20h] [ebp-18h] BYREF
  int pBuffer; // [esp+24h] [ebp-14h] BYREF
  int i; // [esp+28h] [ebp-10h]
  int v22; // [esp+2Ch] [ebp-Ch]
  unsigned int v23; // [esp+30h] [ebp-8h]
  unsigned int v24; // [esp+34h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &v24);
  m_Size = g_SendTables.m_Size;
  v1 = 0;
  c = g_SendTables.m_Size;
  for ( i = 0; v1 < m_Size; i = v1 )
  {
    v2 = g_SendTables.m_Memory.m_pMemory[v1];
    v3 = _V_strlen(str: v2->m_pNetTableName);
    CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: v2->m_pNetTableName, nBuffer: v3);
    pBuffer = v2->m_nProps;
    CRC32_ProcessBuffer(pulCRC: &v24, &pBuffer, nBuffer: 4);
    v22 = 0;
    if ( v2->m_nProps > 0 )
    {
      v23 = 0;
      do
      {
        v4 = &v2->m_pProps[v23 / 0x54];
        m_Type = v4->m_Type;
        CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_Type, nBuffer: 4);
        m_pVarName = v4->m_pVarName;
        v6 = _V_strlen(str: m_pVarName);
        CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: m_pVarName, nBuffer: v6);
        m_Flags = v4->m_Flags;
        CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_Flags, nBuffer: 4);
        v7 = v4->m_Type;
        if ( v7 == DPT_DataTable )
        {
          m_pDataTable = v4->m_pDataTable;
          v9 = _V_strlen(str: m_pDataTable->m_pNetTableName);
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: m_pDataTable->m_pNetTableName, nBuffer: v9);
        }
        else if ( (v4->m_Flags & 0x40) != 0 )
        {
          m_pExcludeDTName = v4->m_pExcludeDTName;
          v11 = _V_strlen(str: m_pExcludeDTName);
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: m_pExcludeDTName, nBuffer: v11);
        }
        else if ( v7 == DPT_Array )
        {
          m_nElements = v4->m_nElements;
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_nElements, nBuffer: 4);
        }
        else
        {
          m_fLowValue = v4->m_fLowValue;
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_fLowValue, nBuffer: 4);
          m_fHighValue = v4->m_fHighValue;
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_fHighValue, nBuffer: 4);
          m_nBits = v4->m_nBits;
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_nBits, nBuffer: 4);
        }
        v23 += 84;
        ++v22;
      }
      while ( v22 < v2->m_nProps );
      v1 = i;
      m_Size = c;
    }
    ++v1;
  }
  CRC32_Final(pulCRC: &v24);
  return v24;
}

//------------------------------------------------------------------------------
// Address: 0x10174500
// Name: int SendTable_WriteAllDeltaProps(class SendTable const __near *,void const __near *,int,void const __near *,int,int,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
bf_write *__cdecl SendTable_WriteAllDeltaProps(
        const SendTable *pTable,
        unsigned int *pFromData,
        int nFromDataBits,
        unsigned int *pToData,
        int nToDataBits,
        const SendProp *nObjectID,
        bf_write *pBufOut)
{
  bf_write *v7; // esi
  int pDeltaProps[4096]; // [esp+Ch] [ebp-4000h] BYREF

  v7 = (bf_write *)SendTable_CalcDelta(
                     pTable,
                     pFromState: pFromData,
                     nFromBits: nFromDataBits,
                     pToState: pToData,
                     nToBits: nToDataBits,
                     pDeltaProps,
                     nMaxDeltaProps: 4096,
                     objectID: (int)nObjectID);
  SendTable_WritePropList(
    a1: nObjectID,
    a2: v7,
    pTable,
    pState: pToData,
    nBits: nToDataBits,
    pOut: pBufOut,
    objectID: (int)nObjectID,
    pCheckProps: pDeltaProps,
    nCheckProps: (int)v7);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10174570
// Name: void SendTable_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_Term()
{
  SendTable **m_pMemory; // edx
  int i; // esi
  CSendTablePrecalc *m_pPrecalc; // ecx

  m_pMemory = g_SendTables.m_Memory.m_pMemory;
  for ( i = 0; i < g_SendTables.m_Size; ++i )
  {
    m_pPrecalc = m_pMemory[i]->m_pPrecalc;
    if ( m_pPrecalc != nullptr )
    {
      ((void (__thiscall *)(CSendTablePrecalc *, int))m_pPrecalc->dtr_CSendTablePrecalc)(a1: m_pPrecalc, a2: 1);
      m_pMemory = g_SendTables.m_Memory.m_pMemory;
    }
  }
  g_SendTables.m_Size = 0;
  if ( g_SendTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      g_SendTables.m_Memory.m_pMemory = nullptr;
    }
    g_SendTables.m_Memory.m_nAllocationCount = 0;
  }
  g_SendTableCRC = 0;
  g_SendTables.m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x101745F0
// Name: bool SendTable_Init(class SendTable __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SendTable_Init(SendTable **pTables, int nTables)
{
  int v2; // eax
  SendTable *v3; // ebx
  CSendTablePrecalc *v4; // eax
  CSendTablePrecalc *v5; // edi
  int m_Size; // eax
  int j; // eax
  int v8; // eax
  int i; // [esp+0h] [ebp-4h]

  if ( g_SendTables.m_Size != 0 )
    _Error(a1: "SendTable_Init: called twice.");
  v2 = 0;
  for ( i = 0; v2 < nTables; i = ++v2 )
  {
    v3 = pTables[v2];
    if ( v3->m_pPrecalc == nullptr )
    {
      v4 = (CSendTablePrecalc *)MemAlloc_Alloc(nSize: 0x118u);
      if ( v4 != nullptr )
        v5 = CSendTablePrecalc::CSendTablePrecalc(this: v4);
      else
        v5 = nullptr;
      v5->m_pSendTable = v3;
      v3->m_pPrecalc = v5;
      SendTable_CalcNextVectorElems(pTable: v3);
      v5->m_pDTITable = ServerDTI_HookTable(pTable: v3);
      if ( !CSendTablePrecalc::SetupFlatPropertyArray(this: v5) )
        return 0;
      SendTable_Validate(pPrecalc: v5);
      v2 = i;
    }
  }
  m_Size = 0;
  g_SendTables.m_Size = 0;
  if ( nTables != 0 )
  {
    if ( nTables > g_SendTables.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&g_SendTables,
        num: nTables - g_SendTables.m_Memory.m_nAllocationCount);
      m_Size = g_SendTables.m_Size;
    }
    g_SendTables.m_Size = nTables + m_Size;
    g_SendTables.m_pElements = g_SendTables.m_Memory.m_pMemory;
    if ( m_Size > 0 && nTables > 0 )
      _V_memmove(
        dest: &g_SendTables.m_Memory.m_pMemory[nTables],
        src: g_SendTables.m_Memory.m_pMemory,
        count: 4 * m_Size);
  }
  for ( j = 0; j < nTables; ++j )
    g_SendTables.m_Memory.m_pMemory[j] = pTables[j];
  g_SendTableCRC = SendTable_ComputeCRC();
  v8 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-dti") != 0 )
    SendTable_PrintStats();
  return 1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10173520
// Name: public: CDeltaCalculator::CDeltaCalculator(class CSendTablePrecalc __near *,void const __near *,int,void const __near *,int,int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CDeltaCalculator *__thiscall CDeltaCalculator::CDeltaCalculator(
        CDeltaCalculator *this,
        CSendTablePrecalc *pPrecalc,
        const void *pFromState,
        int nFromBits,
        const void *pToState,
        int nToBits,
        int *pDeltaProps,
        int nMaxDeltaProps,
        int objectID)
{
  bf_read *p_m_bfFromState; // edi
  int NextPropIndex; // eax

  p_m_bfFromState = &this->m_bfFromState;
  this->m_bfFromState.m_bOverflow = false;
  this->m_bfFromState.m_nDataBits = -1;
  this->m_bfFromState.m_nDataBytes = 0;
  this->m_bfFromState.m_pDebugName = "CDeltaCalculator->m_bfFromState";
  CBitRead::StartReading(
    this: &this->m_bfFromState,
    pData: pFromState,
    nBytes: (nFromBits + 7) >> 3,
    iStartBit: 0,
    nBits: nFromBits);
  this->m_bfToState.m_bOverflow = false;
  this->m_bfToState.m_nDataBits = -1;
  this->m_bfToState.m_nDataBytes = 0;
  this->m_bfToState.m_pDebugName = "CDeltaCalculator->m_bfToState";
  CBitRead::StartReading(
    this: &this->m_bfToState,
    pData: pToState,
    nBytes: (nToBits + 7) >> 3,
    iStartBit: 0,
    nBits: nToBits);
  CDeltaBitsReader::CDeltaBitsReader(this: &this->m_FromBitsReader, pBuf: p_m_bfFromState);
  CDeltaBitsReader::CDeltaBitsReader(this: &this->m_ToBitsReader, pBuf: &this->m_bfToState);
  this->m_pPrecalc = pPrecalc;
  this->m_ObjectID = objectID;
  this->m_pDeltaProps = pDeltaProps;
  this->m_nMaxDeltaProps = nMaxDeltaProps;
  this->m_nDeltaProps = 0;
  if ( pFromState != nullptr )
  {
    NextPropIndex = CDeltaBitsReader::ReadNextPropIndex(this: &this->m_FromBitsReader);
    if ( NextPropIndex < 0 )
      NextPropIndex = 0x7FFFFFFF;
    this->m_iFromProp = NextPropIndex;
    this->m_iToProp = -1;
    return this;
  }
  else
  {
    this->m_iFromProp = 0x7FFFFFFF;
    this->m_iToProp = -1;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101737D0
// Name: SendTable_CalcNextVectorElems
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_CalcNextVectorElems(SendTable *pTable)
{
  int v1; // ebx
  int v2; // esi
  SendProp *v3; // eax

  v1 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v2 = 0;
    do
    {
      v3 = &pTable->m_pProps[v2];
      if ( v3->m_Type == DPT_DataTable )
        SendTable_CalcNextVectorElems(pTable: v3->m_pDataTable);
      ++v1;
      ++v2;
    }
    while ( v1 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173830
// Name: public: void CPropCullStack::CullPropsFromProxies(int const __near *,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropCullStack::CullPropsFromProxies(
        CPropCullStack *this,
        const int *pStartProps,
        int nStartProps,
        int *pOutProps,
        int nMaxOutProps)
{
  int v6; // eax
  int *m_NewProxyProps; // edi
  int v8; // ebx
  int j; // eax
  int m_nOutProps; // ecx
  int v11; // eax
  int k; // eax
  int v13; // ecx
  int i; // [esp+1Ch] [ebp+10h]

  this->m_nMaxOutProps = nMaxOutProps;
  this->m_nOutProps = 0;
  this->m_pOutProps = pOutProps;
  this->m_nNewProxyProps = 0;
  CDatatableStack::Init(this, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  v6 = 0;
  this->m_NewProxyProps[this->m_nNewProxyProps] = 0x7FFFFFFF;
  m_NewProxyProps = this->m_NewProxyProps;
  for ( i = 0; v6 < nStartProps; i = v6 )
  {
    v8 = pStartProps[v6];
    for ( j = *m_NewProxyProps; j < v8; ++m_NewProxyProps )
    {
      m_nOutProps = this->m_nOutProps;
      if ( m_nOutProps >= this->m_nMaxOutProps )
        _Error(a1: "CPropCullStack::AddProp - m_pOutProps overflowed");
      else
        this->m_pOutProps[m_nOutProps] = j;
      ++this->m_nOutProps;
      j = m_NewProxyProps[1];
    }
    if ( this->m_pProxies[this->CDatatableStack::m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v8]] != nullptr )
    {
      v11 = this->m_nOutProps;
      if ( v11 >= this->m_nMaxOutProps )
        _Error(a1: "CPropCullStack::AddProp - m_pOutProps overflowed");
      else
        this->m_pOutProps[v11] = v8;
      ++this->m_nOutProps;
      if ( *m_NewProxyProps == v8 )
        ++m_NewProxyProps;
    }
    v6 = i + 1;
  }
  for ( k = *m_NewProxyProps; k != 0x7FFFFFFF; ++m_NewProxyProps )
  {
    v13 = this->m_nOutProps;
    if ( v13 >= this->m_nMaxOutProps )
      _Error(a1: "CPropCullStack::AddProp - m_pOutProps overflowed");
    else
      this->m_pOutProps[v13] = k;
    ++this->m_nOutProps;
    k = m_NewProxyProps[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173980
// Name: int SendTable_CullPropsFromProxies(class SendTable const __near *,int const __near *,int,int,class CSendProxyRecipients const __near *,int,class CSendProxyRecipients const __near *,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SendTable_CullPropsFromProxies(
        const SendTable *pTable,
        int *pStartProps,
        int nStartProps,
        int iClient,
        const CSendProxyRecipients *pOldStateProxies,
        int nOldStateProxies,
        const CSendProxyRecipients *pNewStateProxies,
        int nNewStateProxies,
        int *pOutProps,
        int nMaxOutProps)
{
  CSendTablePrecalc *m_pPrecalc; // esi
  int result; // eax
  CPropCullStack v12; // [esp+8h] [ebp-4148h] BYREF

  m_pPrecalc = pTable->m_pPrecalc;
  CDatatableStack::CDatatableStack(this: &v12, pPrecalc: m_pPrecalc, pStructBase: (unsigned __int8 *)1, objectID: -1);
  v12.m_pOldStateProxies = pOldStateProxies;
  v12.m_pPrecalc = m_pPrecalc;
  v12.m_nOldStateProxies = nOldStateProxies;
  v12.m_pNewStateProxies = pNewStateProxies;
  v12.m_nNewStateProxies = nNewStateProxies;
  v12.m_iClient = iClient;
  v12.__vftable = (CPropCullStack_vtbl *)&CPropCullStack::`vftable';
  CPropCullStack::CullPropsFromProxies(this: &v12, pStartProps, nStartProps, pOutProps, nMaxOutProps);
  result = v12.m_nOutProps;
  if ( v12.m_nOutProps > nMaxOutProps )
  {
    _Error(a1: "CullPropsFromProxies: overflow in '%s'.", pTable->m_pNetTableName);
    return v12.m_nOutProps;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10173A30
// Name: int SendTable_GetNumFlatProps(class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SendTable_GetNumFlatProps(SendTable *pSendTable)
{
  CSendTablePrecalc *m_pPrecalc; // esi

  m_pPrecalc = pSendTable->m_pPrecalc;
  if ( m_pPrecalc == nullptr )
    _Error(a1: "SendTable_GetNumFlatProps: missing pPrecalc.");
  return m_pPrecalc->m_Props.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10173A60
// Name: public: virtual void CPropCullStack::RecurseAndCallProxies(class CSendNode __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropCullStack::RecurseAndCallProxies(
        CPropCullStack *this,
        CSendNode *pNode,
        unsigned __int8 *pStructBase)
{
  CSendNode *v4; // ecx
  int v5; // eax
  CSendNode *v6; // edi
  int v7; // eax
  int m_DataTableProxyIndex; // ecx
  unsigned int m_iClient; // eax
  const CSendProxyRecipients *m_pOldStateProxies; // edx
  bool v11; // bl
  bool v12; // al
  int v13; // ebx
  unsigned int m_nNewProxyProps; // eax
  int iChild; // [esp+8h] [ebp-8h]

  v4 = pNode;
  this->m_pProxies[pNode->m_RecursiveProxyIndex] = pStructBase;
  v5 = 0;
  for ( iChild = 0; v5 < pNode->m_Children.m_Size; iChild = v5 )
  {
    v6 = v4->m_Children.m_Memory.m_pMemory[v5];
    v7 = 0;
    if ( pStructBase != nullptr )
    {
      m_DataTableProxyIndex = v6->m_DataTableProxyIndex;
      if ( (_WORD)m_DataTableProxyIndex == 255 )
      {
        v7 = 1;
      }
      else
      {
        m_iClient = this->m_iClient;
        m_pOldStateProxies = this->m_pOldStateProxies;
        v11 = ((1 << (m_iClient & 0x1F)) & this->m_pNewStateProxies[m_DataTableProxyIndex].m_Bits.m_Ints[m_iClient >> 5]) != 0;
        if ( m_pOldStateProxies == nullptr
          || (v12 = ((1 << (m_iClient & 0x1F)) & m_pOldStateProxies[m_DataTableProxyIndex].m_Bits.m_Ints[m_iClient >> 5]) != 0) == v11 )
        {
          v7 = v11;
        }
        else if ( v12 )
        {
          v7 = 0;
        }
        else
        {
          v13 = 0;
          if ( v6->m_nRecursiveProps != 0 )
          {
            do
            {
              m_nNewProxyProps = this->m_nNewProxyProps;
              if ( m_nNewProxyProps >= 0x1001 )
                _Error(a1: "CPropCullStack::CallPropProxy - overflowed m_nNewProxyProps");
              else
                this->m_NewProxyProps[m_nNewProxyProps] = v13 + v6->m_iFirstRecursiveProp;
              ++this->m_nNewProxyProps;
              ++v13;
            }
            while ( v13 < v6->m_nRecursiveProps );
          }
          v7 = 0;
        }
      }
    }
    this->RecurseAndCallProxies(this, a2: v6, a3: (unsigned __int8 *)v7);
    v4 = pNode;
    v5 = iChild + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173B90
// Name: public: void CDeltaCalculator::PropCalcDelta(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10173C50
// Name: ShowEncodeDeltaWatchInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowEncodeDeltaWatchInfo(
        char *what,
        const SendTable *pTable,
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
    if ( host_framecount != lastframe_0 )
    {
      lastframe_0 = host_framecount;
      _ConDMsg(a1: "E: delta entity: %i %s\n", objectID, pTable->m_pNetTableName);
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
      a1: "E[%s]:%s %s, %s, index %i, offset %i, bits %i, value %s\n",
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
// Address: 0x10173DB0
// Name: SendTable_EncodeProp
// Source: json
//------------------------------------------------------------------------------
void __usercall SendTable_EncodeProp(CEncodeInfo *pInfo@<esi>, int iProp@<eax>)
{
  int m_iCurProp; // eax
  const SendProp *v3; // edi
  CSendTablePrecalc *m_pPrecalc; // ecx
  unsigned __int8 *v5; // eax
  int m_iCurBit; // ebx
  DVariant var; // [esp+8h] [ebp-18h] BYREF

  CDeltaBitsWriter::WritePropIndex(this: pInfo->m_pDeltaBitsWriter, iProp);
  m_iCurProp = pInfo->m_iCurProp;
  v3 = pInfo->CServerDatatableStack::m_pPrecalc->m_Props.m_Memory.m_pMemory[m_iCurProp];
  m_pPrecalc = pInfo->CServerDatatableStack::CDatatableStack::m_pPrecalc;
  var.m_Type = DPT_Float;
  v5 = pInfo->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[m_iCurProp]];
  v3->m_ProxyFn(a1: v3, a2: v5, a3: &v5[v3->m_Offset & 0xFFFFF], a4: &var, a5: 0, a6: pInfo->m_ObjectID);
  m_iCurBit = pInfo->m_pOut->m_iCurBit;
  ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *))g_PropTypeFns[v3->m_Type].Encode)(
    pStruct: pInfo->m_pProxies[pInfo->CServerDatatableStack::CDatatableStack::m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[pInfo->m_iCurProp]],
    pVar: &var,
    pProp: v3,
    pOut: pInfo->m_pOut);
  pInfo->m_nDataBits += pInfo->m_pOut->m_iCurBit - m_iCurBit;
}

//------------------------------------------------------------------------------
// Address: 0x10173E60
// Name: SendTable_IsPropZero
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall SendTable_IsPropZero@<eax>(CEncodeInfo *pInfo@<eax>)
{
  const SendProp **m_pMemory; // edx
  int m_iCurProp; // eax
  CSendTablePrecalc *m_pPrecalc; // ecx
  const SendProp *v5; // edi
  unsigned __int8 *v6; // eax
  DVariant var; // [esp+8h] [ebp-18h] BYREF

  m_pMemory = pInfo->CServerDatatableStack::m_pPrecalc->m_Props.m_Memory.m_pMemory;
  m_iCurProp = pInfo->m_iCurProp;
  m_pPrecalc = pInfo->CServerDatatableStack::CDatatableStack::m_pPrecalc;
  v5 = m_pMemory[m_iCurProp];
  var.m_Type = DPT_Float;
  v6 = pInfo->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[m_iCurProp]];
  v5->m_ProxyFn(a1: v5, a2: v6, a3: &v6[v5->m_Offset & 0xFFFFF], a4: &var, a5: 0, a6: pInfo->m_ObjectID);
  return ((BOOL (__cdecl *)(const unsigned __int8 *, DVariant *))*(&funcs_10173ED8 + 9 * v5->m_Type))(
           pStruct: pInfo->m_pProxies[pInfo->CServerDatatableStack::CDatatableStack::m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[pInfo->m_iCurProp]],
           pVar: &var);
}

//------------------------------------------------------------------------------
// Address: 0x10173EF0
// Name: bool SendTable_Encode(class SendTable const __near *,void const __near *,class bf_write __near *,int,class CUtlMemory<class CSendProxyRecipients,int> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SendTable_Encode(
        const SendTable *pTable,
        unsigned __int8 *pStruct,
        bf_write *pOut,
        int objectID,
        CUtlMemory<CSendProxyRecipients,int> *pRecipients,
        bool bNonZeroOnly)
{
  CSendTablePrecalc *m_pPrecalc; // esi
  int m_Size; // ebx
  int i; // edi
  bool v9; // bl
  CEncodeInfo info; // [esp+Ch] [ebp-160h] BYREF
  CDeltaBitsWriter deltaBitsWriter; // [esp+148h] [ebp-24h] BYREF
  unsigned __int64 v13; // [esp+154h] [ebp-18h]
  CServerDTITimer timer; // [esp+15Ch] [ebp-10h] BYREF

  m_pPrecalc = pTable->m_pPrecalc;
  if ( m_pPrecalc == nullptr )
    _Error(a1: "SendTable_Encode: Missing m_pPrecalc for SendTable %s.", pTable->m_pNetTableName);
  if ( pRecipients != nullptr && pRecipients->m_nAllocationCount < m_pPrecalc->m_nDataTableProxies )
    _Error(a1: "SendTable_Encode: pRecipients array too small.");
  timer.m_Timer.m_Duration.m_Int64 = 0;
  if ( g_bServerDTIEnabled )
  {
    timer.m_pTable = pTable;
    timer.m_Type = SERVERDTI_ENCODE;
    timer.m_Timer.m_Duration.m_Int64 = __rdtsc();
  }
  CDeltaBitsWriter::CDeltaBitsWriter(this: &deltaBitsWriter, pBuf: pOut);
  CDatatableStack::CDatatableStack(this: &info, pPrecalc: m_pPrecalc, pStructBase: pStruct, objectID);
  info.m_pDeltaBitsWriter = &deltaBitsWriter;
  info.CServerDatatableStack::m_pPrecalc = m_pPrecalc;
  info.__vftable = (CEncodeInfo_vtbl *)&CEncodeInfo::`vftable';
  info.m_pOut = pOut;
  info.m_ObjectID = objectID;
  info.m_nDataBits = 0;
  info.m_nOverheadBits = 0;
  info.m_pRecipients = pRecipients;
  CDatatableStack::Init(this: &info, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  m_Size = m_pPrecalc->m_Props.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    if ( info.m_pProxies[info.CServerDatatableStack::CDatatableStack::m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[i]] != nullptr )
    {
      info.m_iCurProp = i;
      info.m_pCurProp = info.CServerDatatableStack::CDatatableStack::m_pPrecalc->m_Props.m_Memory.m_pMemory[i];
      if ( !bNonZeroOnly || !SendTable_IsPropZero(pInfo: &info) )
        SendTable_EncodeProp(pInfo: &info, iProp: i);
    }
  }
  v9 = !pOut->m_bOverflow;
  CDeltaBitsWriter::~CDeltaBitsWriter(this: &deltaBitsWriter);
  if ( g_bServerDTIEnabled && timer.m_pTable != nullptr )
  {
    v13 = __rdtsc();
    timer.m_Timer.m_Duration.m_Int64 = v13 - timer.m_Timer.m_Duration.m_Int64;
    _ServerDTI_HookTimer(pSendTable: timer.m_pTable, timerType: timer.m_Type, count: &timer.m_Timer.m_Duration);
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10174080
// Name: void SendTable_WritePropList(class SendTable const __near *,void const __near *,int,class bf_write __near *,int,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SendTable_WritePropList(
        const SendProp *a1@<edi>,
        bf_write *a2@<esi>,
        const SendTable *pTable,
        const void *pState,
        int nBits,
        bf_write *pOut,
        int objectID,
        const int *pCheckProps,
        int nCheckProps)
{
  bf_write *v9; // ebx
  CSendTablePrecalc *m_pPrecalc; // edi
  int v11; // esi
  const int *v12; // ebx
  const SendProp *v13; // edi
  int m_nDataBits; // ebx
  int v15; // ecx
  int v16; // edi
  int v17; // ecx
  int v18; // eax
  const SendProp *v19; // [esp-8h] [ebp-5Ch]
  bf_write *v20; // [esp-4h] [ebp-58h]
  DVariant *v21; // [esp+0h] [ebp-54h]
  bf_read inputBuffer; // [esp+4h] [ebp-50h] BYREF
  CDeltaBitsReader inputBitsReader; // [esp+28h] [ebp-2Ch] BYREF
  CDeltaBitsWriter deltaBitsWriter; // [esp+38h] [ebp-1Ch] BYREF
  int i; // [esp+44h] [ebp-10h]
  CSendTablePrecalc *pPrecalc; // [esp+48h] [ebp-Ch]
  const int *v27; // [esp+4Ch] [ebp-8h]
  bool bDebugWatch; // [esp+53h] [ebp-1h]

  v9 = pOut;
  CDeltaBitsWriter::CDeltaBitsWriter(this: &deltaBitsWriter, pBuf: pOut);
  if ( nCheckProps != 0 )
  {
    v20 = a2;
    v19 = a1;
    bDebugWatch = Sendprop_UsingDebugWatch();
    s_debug_info_shown = false;
    s_debug_bits_start = pOut->m_iCurBit;
    m_pPrecalc = pTable->m_pPrecalc;
    pPrecalc = m_pPrecalc;
    inputBuffer.m_bOverflow = false;
    inputBuffer.m_nDataBits = -1;
    inputBuffer.m_nDataBytes = 0;
    inputBuffer.m_pDebugName = "SendTable_WritePropList->inputBuffer";
    CBitRead::StartReading(this: &inputBuffer, pData: pState, nBytes: (nBits + 7) >> 3, iStartBit: 0, nBits);
    CDeltaBitsReader::CDeltaBitsReader(this: &inputBitsReader, pBuf: &inputBuffer);
    v11 = CDeltaBitsReader::ReadNextPropIndex(this: &inputBitsReader);
    if ( v11 < 0 )
      v11 = 0x7FFFFFFF;
    i = 0;
    if ( nCheckProps > 0 )
    {
      v12 = pCheckProps;
      v27 = pCheckProps;
      do
      {
        while ( v11 < *v12 )
        {
          ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B262[9 * m_pPrecalc->m_Props.m_Memory.m_pMemory[v11]->m_Type])(
            pStruct: (const unsigned __int8 *)m_pPrecalc->m_Props.m_Memory.m_pMemory[v11],
            pVar: (DVariant *)&inputBuffer,
            pProp: v19,
            pOut: v20,
            objectID: v21);
          v11 = CDeltaBitsReader::ReadNextPropIndex(this: &inputBitsReader);
          if ( v11 < 0 )
            v11 = 0x7FFFFFFF;
        }
        if ( v11 == 0x7FFFFFFF )
          break;
        if ( v11 == *v12 )
        {
          v13 = m_pPrecalc->m_Props.m_Memory.m_pMemory[v11];
          if ( bDebugWatch )
            ShowEncodeDeltaWatchInfo(what: "New", pTable, pProp: v13, buffer: &inputBuffer, objectID, index: v11);
          if ( inputBuffer.m_pData != nullptr )
          {
            m_nDataBits = inputBuffer.m_nDataBits;
            v15 = 32 * (inputBuffer.m_pDataIn - inputBuffer.m_pData) - inputBuffer.m_nBitsAvail;
            if ( v15 + 8 * (inputBuffer.m_nDataBytes & 3) < inputBuffer.m_nDataBits )
              m_nDataBits = v15 + 8 * (inputBuffer.m_nDataBytes & 3);
          }
          else
          {
            m_nDataBits = 0;
          }
          ((void (__cdecl *)(const unsigned __int8 *, DVariant *, const SendProp *, bf_write *, DVariant *))funcs_1016B262[9 * v13->m_Type])(
            pStruct: (const unsigned __int8 *)v13,
            pVar: (DVariant *)&inputBuffer,
            pProp: v19,
            pOut: v20,
            objectID: v21);
          if ( inputBuffer.m_pData != nullptr )
          {
            v16 = inputBuffer.m_nDataBits;
            v17 = 32 * (inputBuffer.m_pDataIn - inputBuffer.m_pData) - inputBuffer.m_nBitsAvail;
            if ( v17 + 8 * (inputBuffer.m_nDataBytes & 3) < inputBuffer.m_nDataBits )
              v16 = v17 + 8 * (inputBuffer.m_nDataBytes & 3);
          }
          else
          {
            v16 = 0;
          }
          CDeltaBitsWriter::WritePropIndex(this: &deltaBitsWriter, iProp: v11);
          CBitRead::Seek(this: &inputBuffer, nPosition: m_nDataBits);
          bf_write::WriteBitsFromBuffer(this: pOut, pIn: &inputBuffer, nBits: v16 - m_nDataBits);
          v18 = CDeltaBitsReader::ReadNextPropIndex(this: &inputBitsReader);
          m_pPrecalc = pPrecalc;
          v12 = v27;
          v11 = v18;
          if ( v18 < 0 )
            v11 = 0x7FFFFFFF;
        }
        ++v12;
        ++i;
        v27 = v12;
      }
      while ( i < nCheckProps );
      v9 = pOut;
    }
    if ( s_debug_info_shown )
      _ConDMsg(
        a1: "E= %i bits (%i bytes)\n",
        v9->m_iCurBit - s_debug_bits_start,
        (v9->m_iCurBit - s_debug_bits_start + 7) >> 3);
    CDeltaBitsReader::ForceFinished(this: &inputBitsReader);
    CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&inputBitsReader);
  }
  CDeltaBitsWriter::~CDeltaBitsWriter(this: &deltaBitsWriter);
}

//------------------------------------------------------------------------------
// Address: 0x101742B0
// Name: int SendTable_CalcDelta(class SendTable const __near *,void const __near *,int,void const __near *,int,int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SendTable_CalcDelta(
        const SendTable *pTable,
        const void *pFromState,
        int nFromBits,
        const void *pToState,
        int nToBits,
        int *pDeltaProps,
        int nMaxDeltaProps,
        int objectID)
{
  int NextPropIndex; // eax
  const SendProp *v10; // eax
  int m_nDeltaProps; // esi
  CDeltaCalculator deltaCalc; // [esp+0h] [ebp-A4h] BYREF
  CFastTimer *p_m_Timer; // [esp+88h] [ebp-1Ch]
  CServerDTITimer timer; // [esp+8Ch] [ebp-18h] BYREF
  unsigned __int64 v15; // [esp+9Ch] [ebp-8h] BYREF

  timer.m_Timer.m_Duration.m_Int64 = 0;
  if ( g_bServerDTIEnabled )
  {
    timer.m_pTable = pTable;
    timer.m_Type = SERVERDTI_CALCDELTA;
    p_m_Timer = &timer.m_Timer;
    timer.m_Timer.m_Duration.m_Int64 = __rdtsc();
  }
  if ( CompareBitArrays(pPacked1: pFromState, pPacked2: pToState, nBits1: nFromBits, nBits2: nToBits) )
  {
    if ( g_bServerDTIEnabled && timer.m_pTable != nullptr )
    {
      p_m_Timer = (CFastTimer *)&v15;
      v15 = __rdtsc();
      timer.m_Timer.m_Duration.m_Int64 = v15 - timer.m_Timer.m_Duration.m_Int64;
      _ServerDTI_HookTimer(pSendTable: timer.m_pTable, timerType: timer.m_Type, count: &timer.m_Timer.m_Duration);
    }
    return 0;
  }
  else
  {
    CDeltaCalculator::CDeltaCalculator(
      this: &deltaCalc,
      pPrecalc: pTable->m_pPrecalc,
      pFromState,
      nFromBits,
      pToState,
      nToBits,
      pDeltaProps,
      nMaxDeltaProps,
      objectID);
    while ( 1 )
    {
      NextPropIndex = CDeltaBitsReader::ReadNextPropIndex(this: &deltaCalc.m_ToBitsReader);
      if ( NextPropIndex < 0 )
        NextPropIndex = 0x7FFFFFFF;
      deltaCalc.m_iToProp = NextPropIndex;
      if ( NextPropIndex == 0x7FFFFFFF )
        break;
      if ( pFromState != nullptr )
      {
        CDeltaCalculator::PropCalcDelta(this: &deltaCalc);
      }
      else
      {
        v10 = deltaCalc.m_pPrecalc->m_Props.m_Memory.m_pMemory[NextPropIndex];
        if ( !(*(&funcs_1016B4D2 + 9 * v10->m_Type))(pProp: v10, pIn: &deltaCalc.m_bfToState) )
        {
          if ( deltaCalc.m_nDeltaProps < deltaCalc.m_nMaxDeltaProps )
            deltaCalc.m_pDeltaProps[deltaCalc.m_nDeltaProps] = deltaCalc.m_iToProp;
          ++deltaCalc.m_nDeltaProps;
        }
      }
    }
    m_nDeltaProps = deltaCalc.m_nDeltaProps;
    CDeltaCalculator::~CDeltaCalculator(this: &deltaCalc);
    if ( g_bServerDTIEnabled && timer.m_pTable != nullptr )
    {
      p_m_Timer = (CFastTimer *)&v15;
      v15 = __rdtsc();
      timer.m_Timer.m_Duration.m_Int64 = v15 - timer.m_Timer.m_Duration.m_Int64;
      _ServerDTI_HookTimer(pSendTable: timer.m_pTable, timerType: timer.m_Type, count: &timer.m_Timer.m_Duration);
    }
    return m_nDeltaProps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174460
// Name: SendTable_Validate
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_Validate(CSendTablePrecalc *pPrecalc)
{
  CSendTablePrecalc *v1; // ecx
  SendTable *m_pSendTable; // edi
  int v3; // ebx
  SendProp *v4; // esi
  SendProp *m_pArrayProp; // eax
  int m_Size; // edx
  int v7; // eax
  const SendProp **i; // ecx
  int v9; // [esp+Ch] [ebp-4h]

  v1 = pPrecalc;
  m_pSendTable = pPrecalc->m_pSendTable;
  v3 = 0;
  if ( m_pSendTable->m_nProps > 0 )
  {
    v9 = 0;
    do
    {
      v4 = &m_pSendTable->m_pProps[v9];
      m_pArrayProp = v4->m_pArrayProp;
      if ( m_pArrayProp != nullptr )
      {
        if ( m_pArrayProp->m_Type == DPT_DataTable )
          _Error(
            a1: "Invalid property: %s/%s (array of datatables) [on prop %d of %d (%s)].",
            m_pSendTable->m_pNetTableName,
            v4->m_pVarName,
            v3,
            m_pSendTable->m_nProps,
            m_pArrayProp->m_pVarName);
      }
      else if ( v4->m_nElements != 1 )
      {
        _Error(
          a1: "Prop %s/%s has an invalid element count for a non-array.",
          m_pSendTable->m_pNetTableName,
          v4->m_pVarName);
      }
      if ( v4->m_nBits == 1 && (v4->m_Flags & 1) == 0 )
        DataTable_Warning(
          pInMessage: "SendTable prop %s::%s is a 1-bit signed property. Use SPROP_UNSIGNED or the client will never receive a value.\n",
          m_pSendTable->m_pNetTableName,
          v4->m_pVarName);
      ++v9;
      ++v3;
    }
    while ( v3 < m_pSendTable->m_nProps );
    v1 = pPrecalc;
  }
  m_Size = v1->m_Props.m_Size;
  v7 = 0;
  if ( m_Size > 0 )
  {
    for ( i = v1->m_Props.m_Memory.m_pMemory; ((*i)->m_Flags & 0x80000) == 0; ++i )
    {
      if ( ++v7 >= m_Size )
        return;
    }
    *((_BYTE *)m_pSendTable + 16) |= 4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174540
// Name: void SendTable_PrintStats(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_PrintStats()
{
  int v0; // edi
  int v1; // ebx
  SendTable *v2; // eax
  int m_nProps; // ecx
  int *p_m_Flags; // eax
  int i; // esi
  int numTables; // [esp+Ch] [ebp-28h]
  int numExcludeProps; // [esp+10h] [ebp-24h]
  int numSubTables; // [esp+14h] [ebp-20h]
  int numArrays; // [esp+18h] [ebp-1Ch]
  int numStrings; // [esp+1Ch] [ebp-18h]
  int numVecXYs; // [esp+20h] [ebp-14h]
  int numVecs; // [esp+24h] [ebp-10h]
  int numFloats; // [esp+28h] [ebp-Ch]
  int numInts; // [esp+2Ch] [ebp-8h]
  int numSendProps; // [esp+30h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  numTables = 0;
  numFloats = 0;
  numStrings = 0;
  numArrays = 0;
  numInts = 0;
  numVecs = 0;
  numVecXYs = 0;
  numSubTables = 0;
  numSendProps = 0;
  numExcludeProps = 0;
  if ( g_SendTables.m_Size > 0 )
  {
    numTables = g_SendTables.m_Size;
    do
    {
      v2 = g_SendTables.m_Memory.m_pMemory[v1];
      m_nProps = v2->m_nProps;
      numSendProps += m_nProps;
      v0 += v2->m_pPrecalc->m_Props.m_Size;
      if ( m_nProps > 0 )
      {
        p_m_Flags = &v2->m_pProps->m_Flags;
        for ( i = m_nProps; i != 0; --i )
        {
          if ( (*p_m_Flags & 0x40) != 0 )
          {
            ++numExcludeProps;
          }
          else if ( (*p_m_Flags & 0x100) == 0 )
          {
            switch ( *(p_m_Flags - 13) )
            {
              case 0:
                ++numInts;
                break;
              case 1:
                ++numFloats;
                break;
              case 2:
                ++numVecs;
                break;
              case 3:
                ++numVecXYs;
                break;
              case 4:
                ++numStrings;
                break;
              case 5:
                ++numArrays;
                break;
              case 6:
                ++numSubTables;
                break;
              default:
                break;
            }
          }
          p_m_Flags += 21;
        }
      }
      ++v1;
    }
    while ( v1 < g_SendTables.m_Size );
  }
  _Msg(a1: "Total Send Table stats\n");
  _Msg(a1: "Send Tables   : %i\n", numTables);
  _Msg(a1: "Send Props    : %i\n", numSendProps);
  _Msg(a1: "Flat Props    : %i\n", v0);
  _Msg(a1: "Int Props     : %i\n", numInts);
  _Msg(a1: "Float Props   : %i\n", numFloats);
  _Msg(a1: "Vector Props  : %i\n", numVecs);
  _Msg(a1: "VectorXY Props: %i\n", numVecXYs);
  _Msg(a1: "String Props  : %i\n", numStrings);
  _Msg(a1: "Array Props   : %i\n", numArrays);
  _Msg(a1: "Table Props   : %i\n", numSubTables);
  _Msg(a1: "Exclu Props   : %i\n", numExcludeProps);
}

//------------------------------------------------------------------------------
// Address: 0x101746B0
// Name: unsigned long SendTable_ComputeCRC(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl SendTable_ComputeCRC()
{
  int m_Size; // edi
  int v1; // esi
  SendTable *v2; // ebx
  int v3; // eax
  SendProp *v4; // esi
  const char *m_pVarName; // edi
  int v6; // eax
  SendPropType v7; // eax
  SendTable *m_pDataTable; // esi
  int v9; // eax
  const char *m_pExcludeDTName; // esi
  int v11; // eax
  int c; // [esp+8h] [ebp-30h]
  int m_nBits; // [esp+Ch] [ebp-2Ch] BYREF
  float m_fHighValue; // [esp+10h] [ebp-28h] BYREF
  float m_fLowValue; // [esp+14h] [ebp-24h] BYREF
  int m_nElements; // [esp+18h] [ebp-20h] BYREF
  int m_Flags; // [esp+1Ch] [ebp-1Ch] BYREF
  SendPropType m_Type; // [esp+20h] [ebp-18h] BYREF
  int pBuffer; // [esp+24h] [ebp-14h] BYREF
  int i; // [esp+28h] [ebp-10h]
  int v22; // [esp+2Ch] [ebp-Ch]
  unsigned int v23; // [esp+30h] [ebp-8h]
  unsigned int v24; // [esp+34h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &v24);
  m_Size = g_SendTables.m_Size;
  v1 = 0;
  c = g_SendTables.m_Size;
  for ( i = 0; v1 < m_Size; i = v1 )
  {
    v2 = g_SendTables.m_Memory.m_pMemory[v1];
    v3 = _V_strlen(str: v2->m_pNetTableName);
    CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: v2->m_pNetTableName, nBuffer: v3);
    pBuffer = v2->m_nProps;
    CRC32_ProcessBuffer(pulCRC: &v24, &pBuffer, nBuffer: 4);
    v22 = 0;
    if ( v2->m_nProps > 0 )
    {
      v23 = 0;
      do
      {
        v4 = &v2->m_pProps[v23 / 0x54];
        m_Type = v4->m_Type;
        CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_Type, nBuffer: 4);
        m_pVarName = v4->m_pVarName;
        v6 = _V_strlen(str: m_pVarName);
        CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: m_pVarName, nBuffer: v6);
        m_Flags = v4->m_Flags;
        CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_Flags, nBuffer: 4);
        v7 = v4->m_Type;
        if ( v7 == DPT_DataTable )
        {
          m_pDataTable = v4->m_pDataTable;
          v9 = _V_strlen(str: m_pDataTable->m_pNetTableName);
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: m_pDataTable->m_pNetTableName, nBuffer: v9);
        }
        else if ( (v4->m_Flags & 0x40) != 0 )
        {
          m_pExcludeDTName = v4->m_pExcludeDTName;
          v11 = _V_strlen(str: m_pExcludeDTName);
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: m_pExcludeDTName, nBuffer: v11);
        }
        else if ( v7 == DPT_Array )
        {
          m_nElements = v4->m_nElements;
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_nElements, nBuffer: 4);
        }
        else
        {
          m_fLowValue = v4->m_fLowValue;
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_fLowValue, nBuffer: 4);
          m_fHighValue = v4->m_fHighValue;
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_fHighValue, nBuffer: 4);
          m_nBits = v4->m_nBits;
          CRC32_ProcessBuffer(pulCRC: &v24, pBuffer: &m_nBits, nBuffer: 4);
        }
        v23 += 84;
        ++v22;
      }
      while ( v22 < v2->m_nProps );
      v1 = i;
      m_Size = c;
    }
    ++v1;
  }
  CRC32_Final(pulCRC: &v24);
  return v24;
}

//------------------------------------------------------------------------------
// Address: 0x10174870
// Name: int SendTable_WriteAllDeltaProps(class SendTable const __near *,void const __near *,int,void const __near *,int,int,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
bf_write *__cdecl SendTable_WriteAllDeltaProps(
        const SendTable *pTable,
        void *pFromData,
        int nFromDataBits,
        void *pToData,
        int nToDataBits,
        const SendProp *nObjectID,
        bf_write *pBufOut)
{
  bf_write *v7; // esi
  int pDeltaProps[4096]; // [esp+Ch] [ebp-4000h] BYREF

  v7 = (bf_write *)SendTable_CalcDelta(
                     pTable,
                     pFromState: pFromData,
                     nFromBits: nFromDataBits,
                     pToState: pToData,
                     nToBits: nToDataBits,
                     pDeltaProps,
                     nMaxDeltaProps: 4096,
                     objectID: (int)nObjectID);
  SendTable_WritePropList(
    a1: nObjectID,
    a2: v7,
    pTable,
    pState: pToData,
    nBits: nToDataBits,
    pOut: pBufOut,
    objectID: (int)nObjectID,
    pCheckProps: pDeltaProps,
    nCheckProps: (int)v7);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101748E0
// Name: void SendTable_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendTable_Term()
{
  SendTable **m_pMemory; // edx
  int i; // esi
  CSendTablePrecalc *m_pPrecalc; // ecx

  m_pMemory = g_SendTables.m_Memory.m_pMemory;
  for ( i = 0; i < g_SendTables.m_Size; ++i )
  {
    m_pPrecalc = m_pMemory[i]->m_pPrecalc;
    if ( m_pPrecalc != nullptr )
    {
      ((void (__thiscall *)(CSendTablePrecalc *, int))m_pPrecalc->dtr_CSendTablePrecalc)(a1: m_pPrecalc, a2: 1);
      m_pMemory = g_SendTables.m_Memory.m_pMemory;
    }
  }
  g_SendTables.m_Size = 0;
  if ( g_SendTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      g_SendTables.m_Memory.m_pMemory = nullptr;
    }
    g_SendTables.m_Memory.m_nAllocationCount = 0;
  }
  g_SendTableCRC = 0;
  g_SendTables.m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10174960
// Name: bool SendTable_Init(class SendTable __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SendTable_Init(SendTable **pTables, int nTables)
{
  int v2; // eax
  SendTable *v3; // ebx
  CSendTablePrecalc *v4; // eax
  CSendTablePrecalc *v5; // edi
  int m_Size; // eax
  int j; // eax
  int v8; // eax
  int v10; // [esp-Ch] [ebp-10h]
  int i; // [esp+0h] [ebp-4h]

  if ( g_SendTables.m_Size != 0 )
    _Error(a1: "SendTable_Init: called twice.");
  v2 = 0;
  for ( i = 0; v2 < nTables; i = ++v2 )
  {
    v3 = pTables[v2];
    if ( v3->m_pPrecalc == nullptr )
    {
      v4 = (CSendTablePrecalc *)MemAlloc_Alloc(nSize: 0x118u);
      if ( v4 != nullptr )
        v5 = CSendTablePrecalc::CSendTablePrecalc(this: v4);
      else
        v5 = nullptr;
      v5->m_pSendTable = v3;
      v3->m_pPrecalc = v5;
      SendTable_CalcNextVectorElems(pTable: v3);
      v5->m_pDTITable = ServerDTI_HookTable(pTable: v3);
      if ( !CSendTablePrecalc::SetupFlatPropertyArray(this: v5) )
        return 0;
      SendTable_Validate(pPrecalc: v5);
      v2 = i;
    }
  }
  m_Size = 0;
  g_SendTables.m_Size = 0;
  if ( nTables != 0 )
  {
    if ( nTables > g_SendTables.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&g_SendTables,
        num: nTables - g_SendTables.m_Memory.m_nAllocationCount);
      m_Size = g_SendTables.m_Size;
    }
    g_SendTables.m_Size = nTables + m_Size;
    g_SendTables.m_pElements = g_SendTables.m_Memory.m_pMemory;
    if ( m_Size > 0 && nTables > 0 )
      _V_memmove(
        dest: &g_SendTables.m_Memory.m_pMemory[nTables],
        src: g_SendTables.m_Memory.m_pMemory,
        count: 4 * m_Size);
  }
  for ( j = 0; j < nTables; ++j )
    g_SendTables.m_Memory.m_pMemory[j] = pTables[j];
  g_SendTableCRC = SendTable_ComputeCRC();
  v8 = _CommandLine(a1: v10);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-dti") != 0 )
    SendTable_PrintStats();
  return 1;
}

} // namespace engine_xlsp
