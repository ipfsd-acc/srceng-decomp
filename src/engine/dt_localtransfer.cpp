// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt_localtransfer.cpp
// Functions: 20
// ============================================================

#include "engine\dt_localtransfer.h"

//------------------------------------------------------------------------------
// Address: 0x1016DEB0
// Name: public: CClientDatatableStack::CClientDatatableStack(class CRecvDecoder __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
CClientDatatableStack *__thiscall CClientDatatableStack::CClientDatatableStack(
        CClientDatatableStack *this,
        CRecvDecoder *pDecoder,
        unsigned __int8 *pStructBase,
        int objectID)
{
  CDatatableStack::CDatatableStack(this, pPrecalc: &pDecoder->m_Precalc, pStructBase, objectID);
  this->m_pDecoder = pDecoder;
  this->__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016DEF0
// Name: public: CServerDatatableStack::CServerDatatableStack(class CSendTablePrecalc __near *,unsigned char __near *,int,class CUtlMemory<class CSendProxyRecipients,int> __near *)
// Source: json
//------------------------------------------------------------------------------
CServerDatatableStack *__thiscall CServerDatatableStack::CServerDatatableStack(
        CServerDatatableStack *this,
        CSendTablePrecalc *pPrecalc,
        unsigned __int8 *pStructBase,
        int objectID,
        CUtlMemory<CSendProxyRecipients,int> *pRecipients)
{
  CDatatableStack::CDatatableStack(this, pPrecalc, pStructBase, objectID);
  this->m_pPrecalc = pPrecalc;
  this->__vftable = (CServerDatatableStack_vtbl *)&CServerDatatableStack::`vftable';
  this->m_pRecipients = pRecipients;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016DF30
// Name: void FastSortList(unsigned short __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FastSortList(unsigned __int16 *pList, unsigned __int16 nEntries)
{
  int v2; // ecx
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // si
  unsigned __int16 *v5; // eax

  if ( nEntries != 1 )
  {
    v2 = 0;
    do
    {
      while ( 1 )
      {
        v3 = pList[(unsigned __int16)v2 + 1];
        v4 = pList[(unsigned __int16)v2];
        v5 = &pList[(unsigned __int16)v2];
        if ( v3 >= v4 )
          break;
        v5[1] = v4;
        *v5 = v3;
        if ( (_WORD)v2 != 0 )
          v2 += 0xFFFF;
      }
      ++v2;
    }
    while ( (unsigned __int16)v2 < nEntries - 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E050
// Name: public: virtual void CClientDatatableStack::RecurseAndCallProxies(class CSendNode __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientDatatableStack::RecurseAndCallProxies(
        CClientDatatableStack *this,
        CSendNode *pNode,
        unsigned __int8 *pStructBase)
{
  CSendNode *v3; // eax
  unsigned __int8 *v5; // ecx
  int v6; // ebx
  CSendNode *v7; // edi
  unsigned __int8 *v8; // eax
  const RecvProp *v9; // eax
  int m_ObjectID; // [esp-8h] [ebp-14h]
  unsigned __int8 *v11; // [esp+8h] [ebp-4h] BYREF

  v3 = pNode;
  v5 = pStructBase;
  v6 = 0;
  this->m_pProxies[pNode->m_RecursiveProxyIndex] = pStructBase;
  if ( pNode->m_Children.m_Size > 0 )
  {
    while ( 1 )
    {
      v7 = v3->m_Children.m_Memory.m_pMemory[v6];
      v8 = nullptr;
      if ( v5 != nullptr )
      {
        v9 = this->m_pDecoder->m_DatatableProps.m_Memory.m_pMemory[v7->m_iDatatableProp];
        m_ObjectID = this->m_ObjectID;
        v11 = nullptr;
        v9->m_DataTableProxyFn(a1: v9, a2: (void **)&v11, a3: &v5[v9->m_Offset], a4: m_ObjectID);
        v8 = v11;
      }
      this->RecurseAndCallProxies(this, a2: v7, a3: v8);
      if ( ++v6 >= pNode->m_Children.m_Size )
        break;
      v5 = pStructBase;
      v3 = pNode;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E0E0
// Name: public: virtual void CServerDatatableStack::RecurseAndCallProxies(class CSendNode __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerDatatableStack::RecurseAndCallProxies(
        CServerDatatableStack *this,
        CSendNode *pNode,
        unsigned __int8 *pStructBase)
{
  CSendNode *v3; // edi
  int v5; // eax
  CSendNode *v6; // eax
  unsigned __int8 *v7; // ecx
  const SendProp *v8; // ecx
  CUtlMemory<CSendProxyRecipients,int> *m_pRecipients; // edx
  int m_DataTableProxyIndex; // eax
  CSendProxyRecipients *v11; // edi
  int v12; // eax
  int iChild; // [esp+8h] [ebp-8h]
  CSendNode *pCurChild; // [esp+Ch] [ebp-4h]

  v3 = pNode;
  this->m_pProxies[pNode->m_RecursiveProxyIndex] = pStructBase;
  v5 = 0;
  for ( iChild = 0; v5 < v3->m_Children.m_Size; iChild = v5 )
  {
    v6 = v3->m_Children.m_Memory.m_pMemory[v5];
    v7 = nullptr;
    pCurChild = v6;
    if ( pStructBase != nullptr )
    {
      v8 = this->m_pPrecalc->m_DatatableProps.m_Memory.m_pMemory[v6->m_iDatatableProp];
      m_pRecipients = this->m_pRecipients;
      if ( m_pRecipients == nullptr || (_WORD)(m_DataTableProxyIndex = v6->m_DataTableProxyIndex) == 255 )
      {
        v11 = &s_Recipients_1;
      }
      else
      {
        v11 = &m_pRecipients->m_pMemory[m_DataTableProxyIndex];
        if ( v11 != nullptr )
        {
          v11->m_Bits.m_Ints[0] = -1;
          v11->m_Bits.m_Ints[1] = -1;
        }
      }
      v12 = (int)v8->m_DataTableProxyFn(
                   a1: v8,
                   a2: pStructBase,
                   a3: &pStructBase[v8->m_Offset & 0xFFFFF],
                   a4: v11,
                   a5: this->m_ObjectID);
      if ( !this->m_bLocalNetworkBackDoor || v11 == &s_Recipients_1 || (v11->m_Bits.m_Ints[0] & 1) != 0 )
        v7 = (unsigned __int8 *)v12;
      else
        v7 = nullptr;
      v6 = pCurChild;
      v3 = pNode;
    }
    this->RecurseAndCallProxies(this, a2: v6, a3: v7);
    v5 = iChild + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E1C0
// Name: public: static unsigned char __near * CServerDatatableStack::CSendProxyCaller::CallProxy(class CServerDatatableStack __near *,unsigned char __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl CServerDatatableStack::CSendProxyCaller::CallProxy(
        CServerDatatableStack *pStack,
        unsigned __int8 *pStructBase,
        unsigned __int16 iDatatableProp)
{
  const SendProp *v3; // ecx
  CUtlMemory<CSendProxyRecipients,int> *m_pRecipients; // eax
  CSendProxyRecipients *m_pMemory; // edi
  unsigned __int8 *result; // eax

  v3 = pStack->m_pPrecalc->m_DatatableProps.m_Memory.m_pMemory[iDatatableProp];
  if ( pStack->m_bLocalNetworkBackDoor
    && (m_pRecipients = pStack->m_pRecipients) != nullptr
    && m_pRecipients->m_nAllocationCount > 0 )
  {
    m_pMemory = m_pRecipients->m_pMemory;
    if ( m_pRecipients->m_pMemory != nullptr )
    {
      m_pMemory->m_Bits.m_Ints[0] = -1;
      m_pMemory->m_Bits.m_Ints[1] = -1;
    }
  }
  else
  {
    m_pMemory = &s_Recipients_1;
  }
  result = (unsigned __int8 *)v3->m_DataTableProxyFn(
                                a1: v3,
                                a2: pStructBase,
                                a3: &pStructBase[v3->m_Offset & 0xFFFFF],
                                a4: m_pMemory,
                                a5: pStack->m_ObjectID);
  if ( pStack->m_bLocalNetworkBackDoor && m_pMemory != &s_Recipients_1 && (m_pMemory->m_Bits.m_Ints[0] & 1) == 0 )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E250
// Name: public: virtual void CPropMapStack::RecurseAndCallProxies(class CSendNode __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropMapStack::RecurseAndCallProxies(
        CPropMapStack *this,
        CSendNode *pNode,
        unsigned __int8 *pStructBase)
{
  CSendNode *v3; // eax
  int v5; // edi
  CSendNode *v6; // ebx
  unsigned __int8 *v7; // eax
  const SendProp *v8; // edx
  void *(__cdecl *m_DataTableProxyFn)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // ecx
  const CStandardSendProxies *m_pSendProxies; // eax
  CNonModifiedPointerProxy **m_ppNonModifiedPointerProxies; // eax
  CNonModifiedPointerProxy *v12; // eax

  v3 = pNode;
  v5 = 0;
  this->m_pProxies[pNode->m_RecursiveProxyIndex] = pStructBase;
  if ( pNode->m_Children.m_Size > 0 )
  {
    while ( 1 )
    {
      v6 = v3->m_Children.m_Memory.m_pMemory[v5];
      v7 = nullptr;
      if ( pStructBase == nullptr )
        goto LABEL_11;
      v8 = this->m_pPropMapStackPrecalc->m_DatatableProps.m_Memory.m_pMemory[v6->m_iDatatableProp];
      m_DataTableProxyFn = v8->m_DataTableProxyFn;
      m_pSendProxies = this->m_pSendProxies;
      if ( m_DataTableProxyFn != m_pSendProxies->m_DataTableToDataTable )
      {
        m_ppNonModifiedPointerProxies = m_pSendProxies->m_ppNonModifiedPointerProxies;
        if ( m_ppNonModifiedPointerProxies == nullptr || (v12 = *m_ppNonModifiedPointerProxies) == nullptr )
        {
LABEL_10:
          v7 = nullptr;
          goto LABEL_11;
        }
        while ( v12->m_Fn != m_DataTableProxyFn )
        {
          v12 = v12->m_pNext;
          if ( v12 == nullptr )
            goto LABEL_10;
        }
      }
      v7 = &pStructBase[v8->m_Offset & 0xFFFFF];
LABEL_11:
      this->RecurseAndCallProxies(this, a2: v6, a3: v7);
      if ( ++v5 >= pNode->m_Children.m_Size )
        return;
      v3 = pNode;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E2F0
// Name: unsigned char __near * UpdateRoutesExplicit_Template<class CClientDatatableStack,class CClientDatatableStack::CRecvProxyCaller>(class CClientDatatableStack __near *,class CClientDatatableStack::CRecvProxyCaller __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl UpdateRoutesExplicit_Template<CClientDatatableStack,CClientDatatableStack::CRecvProxyCaller>(
        CClientDatatableStack *pStack)
{
  CClientDatatableStack *v1; // esi
  CSendTablePrecalc *m_pPrecalc; // ecx
  int v3; // edx
  unsigned __int8 *result; // eax
  CSendTablePrecalc::CProxyPath *v5; // edx
  unsigned __int16 v6; // bx
  CSendTablePrecalc::CProxyPathEntry *v7; // ecx
  int m_iProxy; // edi
  const RecvProp *v9; // ecx
  CClientDatatableStack *v10; // eax
  int m_ObjectID; // [esp-Ch] [ebp-18h]
  int v12; // [esp+4h] [ebp-8h]
  CSendTablePrecalc::CProxyPath *proxyPath; // [esp+8h] [ebp-4h]

  v1 = pStack;
  m_pPrecalc = pStack->m_pPrecalc;
  v3 = m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[pStack->m_iCurProp];
  result = pStack->m_pProxies[v3];
  v12 = v3;
  if ( result == (unsigned __int8 *)-1 )
  {
    result = pStack->m_pStructBase;
    v5 = &m_pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[v3];
    v6 = 0;
    for ( proxyPath = v5; v6 < v5->m_nEntries; ++v6 )
    {
      v7 = &v1->m_pPrecalc->m_ProxyPathEntries.m_Memory.m_pMemory[v6 + v5->m_iFirstEntry];
      m_iProxy = v7->m_iProxy;
      if ( v1->m_pProxies[m_iProxy] == (unsigned __int8 *)-1 )
      {
        v9 = v1->m_pDecoder->m_DatatableProps.m_Memory.m_pMemory[v7->m_iDatatableProp];
        m_ObjectID = v1->m_ObjectID;
        pStack = nullptr;
        v9->m_DataTableProxyFn(a1: v9, a2: (void **)&pStack, a3: &result[v9->m_Offset], a4: m_ObjectID);
        v10 = pStack;
        v1->m_pProxies[m_iProxy] = (unsigned __int8 *)pStack;
        if ( v10 == nullptr )
        {
          v1->m_pProxies[v12] = nullptr;
          return nullptr;
        }
        v5 = proxyPath;
      }
      result = v1->m_pProxies[m_iProxy];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E3C0
// Name: unsigned char __near * UpdateRoutesExplicit_Template<class CServerDatatableStack,class CServerDatatableStack::CSendProxyCaller>(class CServerDatatableStack __near *,class CServerDatatableStack::CSendProxyCaller __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl UpdateRoutesExplicit_Template<CServerDatatableStack,CServerDatatableStack::CSendProxyCaller>(
        CSendTablePrecalc::CProxyPath *pStack)
{
  CSendTablePrecalc *v2; // ecx
  int v3; // edx
  unsigned __int8 *result; // eax
  CSendTablePrecalc::CProxyPath *v5; // edx
  unsigned __int16 v6; // bx
  CSendTablePrecalc::CProxyPathEntry *v7; // ecx
  int m_iProxy; // edi
  unsigned __int8 *v9; // eax
  int v10; // [esp+4h] [ebp-4h]
  CSendTablePrecalc::CProxyPath *proxyPath; // [esp+10h] [ebp+8h]

  v2 = (CSendTablePrecalc *)pStack[71];
  v3 = v2->m_PropProxyIndices.m_Memory.m_pMemory[*(_DWORD *)&pStack[67]];
  result = (unsigned __int8 *)pStack[v3 + 2];
  v10 = v3;
  if ( result == (unsigned __int8 *)-1 )
  {
    result = (unsigned __int8 *)pStack[66];
    v5 = &v2->m_ProxyPaths.m_Memory.m_pMemory[v3];
    v6 = 0;
    for ( proxyPath = v5; v6 < v5->m_nEntries; ++v6 )
    {
      v7 = (CSendTablePrecalc::CProxyPathEntry *)(*(_DWORD *)(*(_DWORD *)&pStack[71] + 4) + 4 * (v6 + v5->m_iFirstEntry));
      m_iProxy = v7->m_iProxy;
      if ( *(_DWORD *)&pStack[m_iProxy + 2] == -1 )
      {
        v9 = CServerDatatableStack::CSendProxyCaller::CallProxy(
               (CServerDatatableStack *)pStack,
               pStructBase: result,
               iDatatableProp: v7->m_iDatatableProp);
        pStack[m_iProxy + 2] = (CSendTablePrecalc::CProxyPath)v9;
        if ( v9 == nullptr )
        {
          pStack[v10 + 2] = 0;
          return nullptr;
        }
        v5 = proxyPath;
      }
      result = (unsigned __int8 *)pStack[m_iProxy + 2];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E460
// Name: void LocalTransfer_FastType<int>(int __near *,class CServerDatatableStack __near &,class CClientDatatableStack __near &,class CFastLocalTransferPropInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_FastType<int>(
        int *pBlah,
        CServerDatatableStack *serverStack,
        CClientDatatableStack *clientStack,
        CFastLocalTransferPropInfo *pPropList,
        int nProps)
{
  CClientDatatableStack *v5; // esi
  unsigned __int16 *p_m_iProp; // eax
  int v7; // ecx
  CSendTablePrecalc *m_pPrecalc; // edi
  int v9; // ecx
  CSendTablePrecalc *v10; // edi
  unsigned __int8 *pServerBase; // [esp+14h] [ebp+14h]

  if ( nProps > 0 )
  {
    v5 = clientStack;
    p_m_iProp = &pPropList->m_iProp;
    do
    {
      v7 = *p_m_iProp;
      m_pPrecalc = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v7;
      serverStack->m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[v7];
      pServerBase = serverStack->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]];
      if ( pServerBase != nullptr )
      {
        v9 = *p_m_iProp;
        v10 = v5->m_pPrecalc;
        v5->m_iCurProp = v9;
        v5->m_pCurProp = v10->m_Props.m_Memory.m_pMemory[v9];
        *(_DWORD *)&v5->m_pProxies[v10->m_PropProxyIndices.m_Memory.m_pMemory[v9]][*(p_m_iProp - 2)] = *(_DWORD *)&pServerBase[*(p_m_iProp - 1)];
        v5 = clientStack;
      }
      p_m_iProp += 3;
      --nProps;
    }
    while ( nProps != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E4F0
// Name: void LocalTransfer_FastType<short>(short __near *,class CServerDatatableStack __near &,class CClientDatatableStack __near &,class CFastLocalTransferPropInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_FastType<short>(
        __int16 *pBlah,
        CServerDatatableStack *serverStack,
        CClientDatatableStack *clientStack,
        CFastLocalTransferPropInfo *pPropList,
        int nProps)
{
  CClientDatatableStack *v5; // esi
  unsigned __int16 *p_m_iProp; // eax
  int v7; // ecx
  CSendTablePrecalc *m_pPrecalc; // edi
  int v9; // ecx
  CSendTablePrecalc *v10; // edi
  unsigned __int8 *pServerBase; // [esp+14h] [ebp+14h]

  if ( nProps > 0 )
  {
    v5 = clientStack;
    p_m_iProp = &pPropList->m_iProp;
    do
    {
      v7 = *p_m_iProp;
      m_pPrecalc = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v7;
      serverStack->m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[v7];
      pServerBase = serverStack->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]];
      if ( pServerBase != nullptr )
      {
        v9 = *p_m_iProp;
        v10 = v5->m_pPrecalc;
        v5->m_iCurProp = v9;
        v5->m_pCurProp = v10->m_Props.m_Memory.m_pMemory[v9];
        *(_WORD *)&v5->m_pProxies[v10->m_PropProxyIndices.m_Memory.m_pMemory[v9]][*(p_m_iProp - 2)] = *(_WORD *)&pServerBase[*(p_m_iProp - 1)];
        v5 = clientStack;
      }
      p_m_iProp += 3;
      --nProps;
    }
    while ( nProps != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E580
// Name: void LocalTransfer_FastType<char>(char __near *,class CServerDatatableStack __near &,class CClientDatatableStack __near &,class CFastLocalTransferPropInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_FastType<char>(
        char *pBlah,
        CServerDatatableStack *serverStack,
        CClientDatatableStack *clientStack,
        CFastLocalTransferPropInfo *pPropList,
        int nProps)
{
  CClientDatatableStack *v5; // esi
  unsigned __int16 *p_m_iProp; // eax
  int v7; // ecx
  CSendTablePrecalc *m_pPrecalc; // edi
  int v9; // ecx
  CSendTablePrecalc *v10; // edi
  unsigned __int8 *v11; // ecx
  unsigned __int8 *pServerBase; // [esp+14h] [ebp+14h]

  if ( nProps > 0 )
  {
    v5 = clientStack;
    p_m_iProp = &pPropList->m_iProp;
    do
    {
      v7 = *p_m_iProp;
      m_pPrecalc = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v7;
      serverStack->m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[v7];
      pServerBase = serverStack->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]];
      if ( pServerBase != nullptr )
      {
        v9 = *p_m_iProp;
        v10 = v5->m_pPrecalc;
        v5->m_iCurProp = v9;
        v5->m_pCurProp = v10->m_Props.m_Memory.m_pMemory[v9];
        v11 = v5->m_pProxies[v10->m_PropProxyIndices.m_Memory.m_pMemory[v9]];
        v5 = clientStack;
        v11[*(p_m_iProp - 2)] = pServerBase[*(p_m_iProp - 1)];
      }
      p_m_iProp += 3;
      --nProps;
    }
    while ( nProps != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E610
// Name: void LocalTransfer_FastType<class Vector>(class Vector __near *,class CServerDatatableStack __near &,class CClientDatatableStack __near &,class CFastLocalTransferPropInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_FastType<Vector>(
        Vector *pBlah,
        CServerDatatableStack *serverStack,
        CClientDatatableStack *clientStack,
        CFastLocalTransferPropInfo *pPropList,
        int nProps)
{
  int v6; // esi
  int v7; // ebx
  int m_iProp; // esi
  CSendTablePrecalc *m_pPrecalc; // edi
  int v10; // edi
  CSendTablePrecalc *v11; // ebx
  float *v12; // esi
  float *v13; // edi
  int v14; // esi
  CSendTablePrecalc *v15; // edi
  int v16; // edi
  CSendTablePrecalc *v17; // ebx
  float *v18; // esi
  float *v19; // edi
  int v20; // esi
  CSendTablePrecalc *v21; // edi
  int v22; // edi
  CSendTablePrecalc *v23; // ebx
  float *v24; // esi
  float *v25; // edi
  int v26; // esi
  CSendTablePrecalc *v27; // edi
  int v28; // edi
  CSendTablePrecalc *v29; // ebx
  float *v30; // esi
  float *v31; // edi
  unsigned __int16 *p_m_iProp; // edi
  int v33; // ecx
  CSendTablePrecalc *v34; // esi
  int v35; // esi
  CSendTablePrecalc *v36; // ebx
  float *v37; // ecx
  float *v38; // esi
  int i; // [esp+Ch] [ebp-8h]
  unsigned int v40; // [esp+10h] [ebp-4h]
  unsigned __int8 *pServerBase; // [esp+28h] [ebp+14h]
  unsigned __int8 *pServerBasea; // [esp+28h] [ebp+14h]
  unsigned __int8 *pServerBaseb; // [esp+28h] [ebp+14h]
  unsigned __int8 *pServerBasec; // [esp+28h] [ebp+14h]
  unsigned __int8 *pServerBased; // [esp+28h] [ebp+14h]
  int nPropsa; // [esp+2Ch] [ebp+18h]

  v6 = nProps;
  v7 = 0;
  if ( nProps >= 4 )
  {
    v40 = ((unsigned int)(nProps - 4) >> 2) + 1;
    i = 4 * v40;
    do
    {
      m_iProp = pPropList->m_iProp;
      m_pPrecalc = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = m_iProp;
      serverStack->m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[m_iProp];
      pServerBase = serverStack->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[m_iProp]];
      if ( pServerBase != nullptr )
      {
        v10 = pPropList->m_iProp;
        v11 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v10;
        clientStack->m_pCurProp = v11->m_Props.m_Memory.m_pMemory[v10];
        v12 = (float *)&pServerBase[pPropList->m_iSendOffset];
        v13 = (float *)&clientStack->m_pProxies[v11->m_PropProxyIndices.m_Memory.m_pMemory[v10]][pPropList->m_iRecvOffset];
        *v13 = *v12;
        v13[1] = v12[1];
        v13[2] = v12[2];
      }
      v14 = pPropList[1].m_iProp;
      v15 = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v14;
      serverStack->m_pCurProp = v15->m_Props.m_Memory.m_pMemory[v14];
      pServerBasea = serverStack->m_pProxies[v15->m_PropProxyIndices.m_Memory.m_pMemory[v14]];
      if ( pServerBasea != nullptr )
      {
        v16 = pPropList[1].m_iProp;
        v17 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v16;
        clientStack->m_pCurProp = v17->m_Props.m_Memory.m_pMemory[v16];
        v18 = (float *)&pServerBasea[pPropList[1].m_iSendOffset];
        v19 = (float *)&clientStack->m_pProxies[v17->m_PropProxyIndices.m_Memory.m_pMemory[v16]][pPropList[1].m_iRecvOffset];
        *v19 = *v18;
        v19[1] = v18[1];
        v19[2] = v18[2];
      }
      v20 = pPropList[2].m_iProp;
      v21 = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v20;
      serverStack->m_pCurProp = v21->m_Props.m_Memory.m_pMemory[v20];
      pServerBaseb = serverStack->m_pProxies[v21->m_PropProxyIndices.m_Memory.m_pMemory[v20]];
      if ( pServerBaseb != nullptr )
      {
        v22 = pPropList[2].m_iProp;
        v23 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v22;
        clientStack->m_pCurProp = v23->m_Props.m_Memory.m_pMemory[v22];
        v24 = (float *)&pServerBaseb[pPropList[2].m_iSendOffset];
        v25 = (float *)&clientStack->m_pProxies[v23->m_PropProxyIndices.m_Memory.m_pMemory[v22]][pPropList[2].m_iRecvOffset];
        *v25 = *v24;
        v25[1] = v24[1];
        v25[2] = v24[2];
      }
      v26 = pPropList[3].m_iProp;
      v27 = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v26;
      serverStack->m_pCurProp = v27->m_Props.m_Memory.m_pMemory[v26];
      pServerBasec = serverStack->m_pProxies[v27->m_PropProxyIndices.m_Memory.m_pMemory[v26]];
      if ( pServerBasec != nullptr )
      {
        v28 = pPropList[3].m_iProp;
        v29 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v28;
        clientStack->m_pCurProp = v29->m_Props.m_Memory.m_pMemory[v28];
        v30 = (float *)&pServerBasec[pPropList[3].m_iSendOffset];
        v31 = (float *)&clientStack->m_pProxies[v29->m_PropProxyIndices.m_Memory.m_pMemory[v28]][pPropList[3].m_iRecvOffset];
        *v31 = *v30;
        v31[1] = v30[1];
        v31[2] = v30[2];
      }
      v6 = nProps;
      pPropList += 4;
      --v40;
    }
    while ( v40 != 0 );
    v7 = i;
  }
  if ( v7 < v6 )
  {
    p_m_iProp = &pPropList->m_iProp;
    nPropsa = v6 - v7;
    do
    {
      v33 = *p_m_iProp;
      v34 = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v33;
      serverStack->m_pCurProp = v34->m_Props.m_Memory.m_pMemory[v33];
      pServerBased = serverStack->m_pProxies[v34->m_PropProxyIndices.m_Memory.m_pMemory[v33]];
      if ( pServerBased != nullptr )
      {
        v35 = *p_m_iProp;
        v36 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v35;
        clientStack->m_pCurProp = v36->m_Props.m_Memory.m_pMemory[v35];
        v37 = (float *)&pServerBased[*(p_m_iProp - 1)];
        v38 = (float *)&clientStack->m_pProxies[v36->m_PropProxyIndices.m_Memory.m_pMemory[v35]][*(p_m_iProp - 2)];
        *v38 = *v37;
        v38[1] = v37[1];
        v38[2] = v37[2];
      }
      p_m_iProp += 3;
      --nPropsa;
    }
    while ( nPropsa != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F320
// Name: void PrintPartialChangeEntsList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintPartialChangeEntsList()
{
  int v0; // esi
  char v1; // al
  int v2; // esi
  char v3; // al
  int *m_pMemory; // eax
  char tempStr[512]; // [esp+4h] [ebp-400h] BYREF
  char str[512]; // [esp+204h] [ebp-200h] BYREF

  if ( dt_ShowPartialChangeEnts.m_pParent != nullptr && dt_ShowPartialChangeEnts.m_pParent->m_Value.m_nValue != 0 )
  {
    Con_NPrintf(idx: 0xFu, fmt: "----- dt_ShowPartialChangeEnts -----");
    Con_NPrintf(idx: 0x10u, fmt: (char *)defaultValue);
    Con_NPrintf(idx: 0x11u, fmt: "Ent changes: %3d, prop changes: %3d", g_nTotalEntChanges, g_nTotalPropChanges);
    Con_NPrintf(idx: 0x12u, fmt: (char *)defaultValue);
    v0 = 0;
    v1 = 1;
    for ( str[0] = 0; v0 < g_PartialChangeEnts.m_Size; ++v0 )
    {
      if ( g_PartialChangeEnts.m_Memory.m_pMemory[v0] >= 0 )
      {
        if ( v1 == 0 )
          V_strncat(pDest: str, pSrc: ", ", destBufferSize: 0x200u, max_chars_to_copy: -1);
        V_snprintf(pDest: tempStr, maxLen: 512, pFormat: "%d", g_PartialChangeEnts.m_Memory.m_pMemory[v0]);
        V_strncat(pDest: str, pSrc: tempStr, destBufferSize: 0x200u, max_chars_to_copy: -1);
        v1 = 0;
      }
    }
    V_strncat(pDest: str, pSrc: " - PARTIAL", destBufferSize: 0x200u, max_chars_to_copy: -1);
    Con_NPrintf(idx: 0x13u, fmt: "%s", str);
    v2 = 0;
    v3 = 1;
    for ( str[0] = 0; v2 < g_PartialChangeEnts.m_Size; ++v2 )
    {
      if ( g_PartialChangeEnts.m_Memory.m_pMemory[v2] < 0 )
      {
        if ( v3 == 0 )
          V_strncat(pDest: str, pSrc: ", ", destBufferSize: 0x200u, max_chars_to_copy: -1);
        V_snprintf(pDest: tempStr, maxLen: 512, pFormat: "%d", -g_PartialChangeEnts.m_Memory.m_pMemory[v2]);
        V_strncat(pDest: str, pSrc: tempStr, destBufferSize: 0x200u, max_chars_to_copy: -1);
        v3 = 0;
      }
    }
    V_strncat(pDest: str, pSrc: " -    FULL", destBufferSize: 0x200u, max_chars_to_copy: -1);
    Con_NPrintf(idx: 0x14u, fmt: "%s", str);
    m_pMemory = g_PartialChangeEnts.m_Memory.m_pMemory;
    g_PartialChangeEnts.m_Size = 0;
    if ( g_PartialChangeEnts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_PartialChangeEnts.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_PartialChangeEnts.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_PartialChangeEnts.m_Memory.m_pMemory = nullptr;
      }
      g_PartialChangeEnts.m_Memory.m_nAllocationCount = 0;
    }
    g_PartialChangeEnts.m_pElements = m_pMemory;
    g_nTotalEntChanges = 0;
    g_nTotalPropChanges = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F540
// Name: void AddToPartialChangeEntsList(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddToPartialChangeEntsList(int iEnt, bool bPartial)
{
  int v2; // edi
  int m_Size; // eax
  int *m_pMemory; // edx
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  int *v8; // eax

  if ( dt_ShowPartialChangeEnts.m_pParent != nullptr && dt_ShowPartialChangeEnts.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = iEnt;
    if ( !bPartial )
      v2 = -iEnt;
    m_Size = g_PartialChangeEnts.m_Size;
    m_pMemory = g_PartialChangeEnts.m_Memory.m_pMemory;
    v5 = 0;
    if ( g_PartialChangeEnts.m_Size <= 0 )
      goto LABEL_10;
    while ( g_PartialChangeEnts.m_Memory.m_pMemory[v5] != v2 )
    {
      if ( ++v5 >= g_PartialChangeEnts.m_Size )
        goto LABEL_10;
    }
    if ( v5 == -1 )
    {
LABEL_10:
      v6 = g_PartialChangeEnts.m_Size;
      if ( g_PartialChangeEnts.m_Size + 1 > g_PartialChangeEnts.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&g_PartialChangeEnts,
          num: g_PartialChangeEnts.m_Size - g_PartialChangeEnts.m_Memory.m_nAllocationCount + 1);
        m_Size = g_PartialChangeEnts.m_Size;
        m_pMemory = g_PartialChangeEnts.m_Memory.m_pMemory;
      }
      g_PartialChangeEnts.m_Size = m_Size + 1;
      v7 = m_Size - v6;
      g_PartialChangeEnts.m_pElements = m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v7);
        m_pMemory = g_PartialChangeEnts.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v6];
      if ( v8 != nullptr )
        *v8 = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F5F0
// Name: void AddPropOffsetToMap(class CSendTablePrecalc __near *,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddPropOffsetToMap(CSendTablePrecalc *pPrecalc, PropIndicesCollection_t iInProp, int iInOffset)
{
  unsigned __int16 v3; // di
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short> *p_m_PropOffsetToIndexMap; // esi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *v10; // eax
  int v11; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *v13; // ecx
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t *p_m_Data; // edi
  PropIndicesCollection_t *p_elem; // ecx
  unsigned int i; // eax
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  v3 = iInOffset;
  p_m_PropOffsetToIndexMap = &pPrecalc->m_PropOffsetToIndexMap;
  search.key = iInOffset;
  v5 = CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &pPrecalc->m_PropOffsetToIndexMap.m_Tree,
         &search);
  if ( v5 == 0xFFFF )
  {
    iInProp.m_Indices[1] = -1;
    iInOffset = 0xFFFF;
    search.elem = iInProp;
    search.key = v3;
    HIBYTE(iInProp.m_Indices[1]) = 0;
    CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &p_m_PropOffsetToIndexMap->m_Tree,
      insert: &search,
      parent: (unsigned __int16 *)&iInOffset,
      leftchild: (bool *)&iInProp + 3);
    v6 = CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &p_m_PropOffsetToIndexMap->m_Tree);
    v7 = iInOffset;
    v8 = v6;
    v9 = v6;
    v10 = &pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory[v9];
    v10->m_Right = -1;
    v10->m_Left = -1;
    v10->m_Parent = v7;
    v10->m_Tag = 0;
    if ( v7 == 0xFFFF )
    {
      pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Root = v8;
    }
    else
    {
      v11 = v7;
      m_pMemory = pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory;
      if ( HIBYTE(iInProp.m_Indices[1]) != 0 )
        m_pMemory[v11].m_Left = v8;
      else
        m_pMemory[v11].m_Right = v8;
    }
    CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &p_m_PropOffsetToIndexMap->m_Tree,
      elem: v8);
    v13 = pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory;
    ++pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_NumElements;
    p_m_Data = &v13[v9].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = search;
  }
  else
  {
    p_elem = &pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
    for ( i = 0; i < 2; ++i )
    {
      if ( p_elem->m_Indices[i] == 0xFFFF )
      {
        p_elem->m_Indices[i] = iInProp.m_Indices[0];
        return;
      }
    }
    _Error(a1: "Overflowed a PropIndicesCollection_t on %s\n", pPrecalc->m_pSendTable->m_pNetTableName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F740
// Name: void BuildPropOffsetToIndexMap(class CSendTablePrecalc __near *,class CStandardSendProxies const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildPropOffsetToIndexMap(CSendTablePrecalc *pPrecalc, const CStandardSendProxies *pSendProxies)
{
  CSendTablePrecalc *v2; // esi
  int v3; // ebx
  CSendTablePrecalc *m_pPrecalc; // edx
  unsigned __int8 *v5; // eax
  const SendProp *v6; // esi
  int v7; // edi
  int m_nElements; // ecx
  SendPropType m_Type; // eax
  int v10; // eax
  int v11; // eax
  CPropMapStack pmStack; // [esp+8h] [ebp-128h] BYREF
  int v13; // [esp+12Ch] [ebp-4h]
  int elementStride; // [esp+13Ch] [ebp+Ch]

  v2 = pPrecalc;
  CDatatableStack::CDatatableStack(this: &pmStack, pPrecalc, pStructBase: (unsigned __int8 *)1, objectID: -1);
  pmStack.__vftable = (CPropMapStack_vtbl *)&CPropMapStack::`vftable';
  pmStack.m_pPropMapStackPrecalc = pPrecalc;
  pmStack.m_pSendProxies = pSendProxies;
  CDatatableStack::Init(this: &pmStack, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  v3 = 0;
  if ( pPrecalc->m_Props.m_Size > 0 )
  {
    m_pPrecalc = pmStack.m_pPrecalc;
    do
    {
      pmStack.m_iCurProp = v3;
      pmStack.m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[v3];
      v5 = pmStack.m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v3]];
      if ( v5 != nullptr )
      {
        v6 = v2->m_Props.m_Memory.m_pMemory[v3];
        v7 = (int)&v5[(v6->m_Offset & 0xFFFFF) - 1];
        m_nElements = 1;
        elementStride = 0;
        if ( v6->m_Type == DPT_Array )
        {
          v7 = (int)&v5[(v6->m_pArrayProp->m_Offset & 0xFFFFF) - 1];
          m_nElements = v6->m_nElements;
          elementStride = v6->m_ElementStride;
        }
        if ( v7 != 0 && m_nElements > 0 )
        {
          v13 = m_nElements;
          while ( 1 )
          {
            m_Type = v6->m_Type;
            if ( m_Type == DPT_Vector )
            {
              v10 = v6->m_Offset >> 20;
              if ( (v10 & 2) != 0 )
              {
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7);
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7 + 4);
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7 + 8);
              }
              else
              {
                if ( (v10 & 4) == 0 )
                  goto LABEL_18;
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7);
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7 + 8);
              }
            }
            else
            {
              if ( m_Type != DPT_VectorXY || ((v11 = v6->m_Offset >> 20) & 2) == 0 )
              {
LABEL_18:
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7);
                goto LABEL_19;
              }
              AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7);
              AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7 + 4);
            }
LABEL_19:
            v7 += elementStride;
            if ( --v13 == 0 )
            {
              m_pPrecalc = pmStack.m_pPrecalc;
              break;
            }
          }
        }
        v2 = pPrecalc;
      }
      ++v3;
    }
    while ( v3 < v2->m_Props.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F910
// Name: void LocalTransfer_InitFastCopy(class SendTable const __near *,class CStandardSendProxies const __near *,class RecvTable __near *,class CStandardRecvProxies const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_InitFastCopy(
        CSendTablePrecalc *pSendTable,
        const CStandardSendProxies *pSendProxies,
        const RecvProp *pRecvTable,
        const CStandardRecvProxies *pRecvProxies,
        int *nSlowCopyProps,
        int *nFastCopyProps)
{
  CUtlMemory<sentencegroup_t,int> *v6; // esi
  const CStandardSendProxies *v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  CUtlMemory<sentencegroup_t,int> *p_m_FastLocalTransfer; // esi
  void (__cdecl *v12)(const SendProp *, const void *, const void *, DVariant *, int, int); // eax
  void (__cdecl *v13)(const SendProp *, const void *, const void *, DVariant *, int, int); // eax
  void (__cdecl *v14)(const SendProp *, const void *, const void *, DVariant *, int, int); // eax
  sentencegroup_t *m_pMemory; // edi
  int m_nAllocationCount; // eax
  sentencegroup_t *v17; // ecx
  int v18; // eax
  sentencegroup_t *v19; // edx
  int v20; // ecx
  sentencegroup_t *v21; // eax
  int toAdd; // [esp+Ch] [ebp-14h]
  int iNumProp; // [esp+14h] [ebp-Ch]
  CRecvDecoder *pDecoder; // [esp+18h] [ebp-8h]
  int iProp; // [esp+1Ch] [ebp-4h]
  CSendTablePrecalc *pPrecalc; // [esp+28h] [ebp+8h]
  const RecvProp *pRecvProp; // [esp+30h] [ebp+10h]

  pPrecalc = (CSendTablePrecalc *)pSendTable->m_ProxyPathEntries.m_Memory.m_nGrowSize;
  v6 = (CUtlMemory<sentencegroup_t,int> *)pPrecalc;
  CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &pPrecalc->m_PropOffsetToIndexMap.m_Tree);
  v7 = pSendProxies;
  BuildPropOffsetToIndexMap(pPrecalc, pSendProxies);
  pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_FastInt32.m_pElements = pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory;
  pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_FastInt16.m_pElements = pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory;
  pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_FastInt8.m_pElements = pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory;
  pPrecalc->m_FastLocalTransfer.m_FastVector.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_FastVector.m_pElements = pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory;
  pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_OtherProps.m_pElements = pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory;
  pDecoder = (CRecvDecoder *)pRecvTable->m_Flags;
  v8 = 0;
  iNumProp = pPrecalc->m_Props.m_Size;
  iProp = 0;
  if ( iNumProp > 0 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(v6[3].m_nGrowSize + 4 * v8);
      pRecvProp = pDecoder->m_Props.m_Memory.m_pMemory[v8];
      if ( pRecvProp != nullptr )
        break;
LABEL_56:
      iProp = ++v8;
      if ( v8 >= iNumProp )
        return;
    }
    v10 = *(_DWORD *)(v9 + 8);
    p_m_FastLocalTransfer = v6 + 19;
    if ( v10 == 0 )
    {
      v12 = *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64);
      if ( v12 == v7->m_Int32ToInt32 || v12 == v7->m_UInt32ToInt32 )
      {
        if ( pRecvProp->m_ProxyFn == pRecvProxies->m_Int32ToInt32 )
        {
          p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer;
          ++*nFastCopyProps;
LABEL_49:
          m_pMemory = p_m_FastLocalTransfer[1].m_pMemory;
          LOWORD(toAdd) = pRecvProp->m_Offset;
          m_nAllocationCount = p_m_FastLocalTransfer->m_nAllocationCount;
          HIWORD(toAdd) = *(_WORD *)(v9 + 76);
          if ( (int)&m_pMemory->count + 1 > m_nAllocationCount )
            CUtlMemory<sentencegroup_t,int>::Grow(
              this: p_m_FastLocalTransfer,
              num: (int)&m_pMemory->count - m_nAllocationCount + 1);
          ++p_m_FastLocalTransfer[1].m_pMemory;
          v17 = p_m_FastLocalTransfer->m_pMemory;
          v18 = (char *)p_m_FastLocalTransfer[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_FastLocalTransfer[1].m_nAllocationCount = (int)p_m_FastLocalTransfer->m_pMemory;
          if ( v18 > 0 )
            _V_memmove(dest: &v17[(int)m_pMemory + 1], src: &v17[(_DWORD)m_pMemory], count: 6 * v18);
          v19 = p_m_FastLocalTransfer->m_pMemory;
          v6 = (CUtlMemory<sentencegroup_t,int> *)pPrecalc;
          v20 = (int)m_pMemory;
          v7 = pSendProxies;
          v21 = &v19[v20];
          if ( v21 != nullptr )
          {
            *(_DWORD *)&v21->count = toAdd;
            v21->groupname.m_Id = iProp;
          }
          v8 = iProp;
          goto LABEL_56;
        }
        v7 = pSendProxies;
      }
      v13 = *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64);
      if ( v13 == v7->m_Int16ToInt32 || v13 == v7->m_UInt16ToInt32 )
      {
        if ( pRecvProp->m_ProxyFn == pRecvProxies->m_Int32ToInt16 )
        {
          p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer.m_FastInt16;
          ++*nFastCopyProps;
          goto LABEL_49;
        }
        v7 = pSendProxies;
      }
      v14 = *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64);
      if ( v14 == v7->m_Int8ToInt32 || v14 == v7->m_UInt8ToInt32 )
      {
        if ( pRecvProp->m_ProxyFn == pRecvProxies->m_Int32ToInt8 )
        {
          p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer.m_FastInt8;
          ++*nFastCopyProps;
          goto LABEL_49;
        }
        v7 = pSendProxies;
      }
    }
    if ( v10 == 1
      && *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64) == v7->m_FloatToFloat )
    {
      if ( pRecvProp->m_ProxyFn == pRecvProxies->m_FloatToFloat )
      {
        p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer;
        ++*nFastCopyProps;
        goto LABEL_49;
      }
      v7 = pSendProxies;
    }
    if ( v10 == 2
      && *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64) == v7->m_VectorToVector
      && pRecvProp->m_ProxyFn == pRecvProxies->m_VectorToVector )
    {
      p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer.m_FastVector;
      ++*nFastCopyProps;
    }
    else
    {
      ++*nSlowCopyProps;
    }
    goto LABEL_49;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FC50
// Name: int MapPropOffsetsToIndices(class CBaseEdict const __near *,class CSendTablePrecalc __near *,unsigned short const __near *,unsigned short,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MapPropOffsetsToIndices(
        const CBaseEdict *pEdict,
        CSendTablePrecalc *pPrecalc,
        unsigned __int16 *pOffsets,
        unsigned __int16 nOffsets,
        unsigned __int16 *pOut)
{
  int v6; // ebx
  unsigned __int16 *v7; // esi
  CSendTablePrecalc *v8; // edi
  unsigned __int16 v9; // ax
  const char *v10; // eax
  unsigned int i; // edi
  unsigned __int16 v12; // si
  int v13; // eax
  bool v14; // zf
  char str[512]; // [esp+4h] [ebp-218h] BYREF
  CUtlMap<char const *,int,int>::Node_t v17; // [esp+204h] [ebp-18h] BYREF
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t search; // [esp+20Ch] [ebp-10h] BYREF
  const PropIndicesCollection_t *coll; // [esp+214h] [ebp-8h]
  int v20; // [esp+218h] [ebp-4h]
  const unsigned __int16 *nOffsetsa; // [esp+230h] [ebp+14h]

  v6 = 0;
  if ( nOffsets != 0 )
  {
    v7 = pOffsets;
    v8 = pPrecalc;
    nOffsetsa = pOffsets;
    v20 = nOffsets;
    do
    {
      search.key = *v7;
      v9 = CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &v8->m_PropOffsetToIndexMap.m_Tree,
             &search);
      if ( v9 == 0xFFFF )
      {
        if ( dt_ShowPartialChangeEnts.m_pParent != nullptr && dt_ShowPartialChangeEnts.m_pParent->m_Value.m_nValue != 0 )
        {
          if ( (`MapPropOffsetsToIndices'::`10'::`local static guard' & 1) == 0 )
          {
            `MapPropOffsetsToIndices'::`10'::`local static guard' |= 1u;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_Root = -1;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_NumElements = 0;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_FirstFree = -1;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_LastAlloc.index = -1;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_pElements = nullptr;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
            atexit(func: `MapPropOffsetsToIndices'::`10'::`dynamic atexit destructor for 'testDict'');
          }
          if ( pEdict->m_pUnk != nullptr )
            v10 = pEdict->m_pNetworkable->GetClassNameA(this: pEdict->m_pNetworkable);
          else
            v10 = defaultValue;
          V_snprintf(
            pDest: str,
            maxLen: 512,
            pFormat: "LocalTransfer offset miss - class: %s, DT: %s, offset: %d",
            v10,
            v8->m_pSendTable->m_pNetTableName,
            *v7);
          v17.key = str;
          if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                 this: &`MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree,
                 search: &v17) == -1 )
          {
            CUtlDict<int,int>::Insert(this: &`MapPropOffsetsToIndices'::`10'::testDict, pName: str);
            _Warning(a1: "%s\n", str);
          }
        }
      }
      else
      {
        coll = &v8->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
        for ( i = 0; i < 2; ++i )
        {
          v12 = coll->m_Indices[i];
          if ( v12 != 0xFFFF )
          {
            v13 = 0;
            if ( v6 <= 0 )
            {
LABEL_18:
              if ( v6 >= 114 )
                _Error(a1: "Overflowed output list in MapPropOffsetsToIndices");
              pOut[v6++] = v12;
            }
            else
            {
              while ( pOut[v13] != v12 )
              {
                if ( ++v13 >= v6 )
                  goto LABEL_18;
              }
            }
          }
        }
        v8 = pPrecalc;
        v7 = (unsigned __int16 *)nOffsetsa;
      }
      ++v7;
      v14 = v20-- == 1;
      nOffsetsa = v7;
    }
    while ( !v14 );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1016FE30
// Name: void LocalTransfer_TransferEntity(class CBaseEdict const __near *,class SendTable const __near *,void const __near *,class RecvTable __near *,void __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_TransferEntity(
        CBaseEdict *pEdict,
        const SendTable *pSendTable,
        unsigned __int8 *pSrcEnt,
        RecvTable *pRecvTable,
        unsigned __int8 *pDestEnt,
        bool bNewlyCreated,
        bool bJustEnteredPVS,
        int objectID)
{
  CEdictChangeInfo *v8; // edi
  int m_nDataTableProxies; // eax
  CSendTablePrecalc *m_pPrecalc; // ebx
  int v11; // edi
  CSendTablePrecalc *m_pDecoder; // esi
  int v13; // edi
  int v14; // esi
  unsigned __int8 *v15; // ebx
  int v16; // edi
  unsigned __int8 *v17; // eax
  CSendTablePrecalc *v18; // ebx
  char *v19; // edi
  CSendTablePrecalc *v20; // ecx
  int v21; // eax
  const SendProp *v22; // ebx
  const unsigned __int8 *v23; // esi
  int v24; // ecx
  unsigned __int8 tempData[256]; // [esp+Ch] [ebp-480h] BYREF
  CServerDatatableStack serverStack; // [esp+10Ch] [ebp-380h] BYREF
  CClientDatatableStack v27; // [esp+230h] [ebp-25Ch] BYREF
  CServerDatatableStack v28; // [esp+350h] [ebp-13Ch] BYREF
  CUtlMemory<CSendProxyRecipients,int> recip; // [esp+474h] [ebp-18h] BYREF
  const SendProp *pSendProp; // [esp+480h] [ebp-Ch]
  CSendTablePrecalc *pPrecalc; // [esp+484h] [ebp-8h]
  int nChangeOffsets; // [esp+488h] [ebp-4h]
  int iChanged; // [esp+498h] [ebp+Ch]
  unsigned __int16 *iChangeda; // [esp+498h] [ebp+Ch]

  ++g_nTotalEntChanges;
  v8 = &g_pSharedChangeInfo->m_ChangeInfos[CBaseEdict::GetChangeAccessor(this: pEdict)->m_iChangeInfo];
  m_nDataTableProxies = pSendTable->m_pPrecalc->m_nDataTableProxies;
  recip.m_pMemory = (CSendProxyRecipients *)tempData;
  recip.m_nAllocationCount = m_nDataTableProxies;
  recip.m_nGrowSize = -1;
  if ( CBaseEdict::GetChangeAccessor(this: pEdict)->m_iChangeInfoSerialNumber == g_pSharedChangeInfo->m_iSerialNumber
    && !bNewlyCreated
    && !bJustEnteredPVS
    && dt_UsePartialChangeEnts.m_pParent != nullptr
    && dt_UsePartialChangeEnts.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pPrecalc = pSendTable->m_pPrecalc;
    v11 = MapPropOffsetsToIndices(
            pEdict,
            pPrecalc: m_pPrecalc,
            pOffsets: v8->m_ChangeOffsets,
            nOffsets: v8->m_nChangeOffsets,
            pOut: (unsigned __int16 *)&v27.m_pProxies[13]);
    nChangeOffsets = v11;
    if ( v11 == 0 )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&recip);
      return;
    }
    AddToPartialChangeEntsList(iEnt: (edict_t *)pEdict - sv.edicts, bPartial: true);
    FastSortList(pList: (unsigned __int16 *)&v27.m_pProxies[13], nEntries: v11);
    if ( m_pPrecalc == nullptr )
      _Error(a1: "SendTable_Encode: Missing m_pPrecalc for SendTable %s.", pSendTable->m_pNetTableName);
    CServerDatatableStack::CServerDatatableStack(
      this: &serverStack,
      pPrecalc: m_pPrecalc,
      pStructBase: pSrcEnt,
      objectID,
      pRecipients: &recip);
    CDatatableStack::Init(this: &serverStack, bExplicitRoutes: true, bLocalNetworkBackDoor: true);
    m_pDecoder = (CSendTablePrecalc *)pRecvTable->m_pDecoder;
    pPrecalc = m_pDecoder;
    if ( m_pDecoder == nullptr )
      _Error(a1: "RecvTable_Decode: table '%s' missing a decoder.", pRecvTable->m_pNetTableName);
    CClientDatatableStack::CClientDatatableStack(
      this: (CClientDatatableStack *)&v28.CDatatableStack::m_pPrecalc,
      pDecoder: (CRecvDecoder *)m_pDecoder,
      pStructBase: pDestEnt,
      objectID);
    CDatatableStack::Init(
      this: (CDatatableStack *)&v28.CDatatableStack::m_pPrecalc,
      bExplicitRoutes: true,
      bLocalNetworkBackDoor: true);
    v13 = 0;
    for ( iChanged = 0; v13 < nChangeOffsets; iChanged = v13 )
    {
      v14 = *((unsigned __int16 *)&v27.m_pProxies[13] + v13);
      ++g_nTotalPropChanges;
      serverStack.m_iCurProp = v14;
      serverStack.m_pCurProp = serverStack.CDatatableStack::m_pPrecalc->m_Props.m_Memory.m_pMemory[v14];
      pSendProp = serverStack.m_pPrecalc->m_Props.m_Memory.m_pMemory[v14];
      v15 = UpdateRoutesExplicit_Template<CServerDatatableStack,CServerDatatableStack::CSendProxyCaller>(pStack: (CSendTablePrecalc::CProxyPath *)&serverStack);
      if ( v15 != nullptr )
      {
        v16 = *(_DWORD *)(pPrecalc[1].m_ProxyPathEntries.m_Memory.m_nAllocationCount + 4 * v14);
        v28.m_pCurProp = (const SendProp *)v14;
        v28.m_ObjectID = *(_DWORD *)(*((_DWORD *)v28.m_pProxies[0] + 11) + 4 * v14);
        v17 = UpdateRoutesExplicit_Template<CClientDatatableStack,CClientDatatableStack::CRecvProxyCaller>(pStack: (CClientDatatableStack *)&v28.CDatatableStack::m_pPrecalc);
        (*(&funcs_10170030 + 9 * *(_DWORD *)(v16 + 4)))(
          pSendProp,
          pRecvProp: (const RecvProp *)v16,
          pSendData: v15,
          pRecvData: v17,
          objectID);
        v13 = iChanged;
      }
      ++v13;
    }
  }
  else
  {
    v18 = pSendTable->m_pPrecalc;
    pPrecalc = v18;
    if ( v18 == nullptr )
      _Error(a1: "SendTable_Encode: Missing m_pPrecalc for SendTable %s.", pSendTable->m_pNetTableName);
    CDatatableStack::CDatatableStack(this: &v28, pPrecalc: v18, pStructBase: pSrcEnt, objectID);
    v28.__vftable = (CServerDatatableStack_vtbl *)&CServerDatatableStack::`vftable';
    v28.m_pPrecalc = v18;
    v28.m_pRecipients = &recip;
    CDatatableStack::Init(this: &v28, bExplicitRoutes: false, bLocalNetworkBackDoor: true);
    v19 = (char *)pRecvTable->m_pDecoder;
    pSendProp = (const SendProp *)v19;
    if ( v19 == nullptr )
      _Error(a1: "RecvTable_Decode: table '%s' missing a decoder.", pRecvTable->m_pNetTableName);
    CDatatableStack::CDatatableStack(
      this: &v27,
      pPrecalc: (CSendTablePrecalc *)(v19 + 8),
      pStructBase: pDestEnt,
      objectID);
    v27.__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
    v27.m_pDecoder = (CRecvDecoder *)v19;
    CDatatableStack::Init(this: &v27, bExplicitRoutes: false, bLocalNetworkBackDoor: true);
    AddToPartialChangeEntsList(iEnt: (edict_t *)pEdict - sv.edicts, bPartial: false);
    if ( v18->m_FastLocalTransfer.m_OtherProps.m_Size > 0 )
    {
      iChangeda = &v18->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory->m_iProp;
      v20 = v28.CDatatableStack::m_pPrecalc;
      nChangeOffsets = v18->m_FastLocalTransfer.m_OtherProps.m_Size;
      do
      {
        v21 = *iChangeda;
        v28.m_iCurProp = v21;
        v28.m_pCurProp = v20->m_Props.m_Memory.m_pMemory[v21];
        v22 = v28.m_pPrecalc->m_Props.m_Memory.m_pMemory[v21];
        v23 = v28.m_pProxies[v20->m_PropProxyIndices.m_Memory.m_pMemory[v21]];
        if ( v23 != nullptr )
        {
          v24 = *(_DWORD *)(*((_DWORD *)v19 + 72) + 4 * v21);
          v27.m_iCurProp = v21;
          v27.m_pCurProp = v27.m_pPrecalc->m_Props.m_Memory.m_pMemory[v21];
          (*(&funcs_10170030 + 9 * *(_DWORD *)(v24 + 4)))(
            pSendProp: v22,
            pRecvProp: (const RecvProp *)v24,
            pSendData: v23,
            pRecvData: v27.m_pProxies[v27.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v21]],
            objectID);
          v20 = v28.CDatatableStack::m_pPrecalc;
          v19 = (char *)pSendProp;
        }
        iChangeda += 3;
        --nChangeOffsets;
      }
      while ( nChangeOffsets != 0 );
      v18 = pPrecalc;
    }
    LocalTransfer_FastType<int>(
      pBlah: nullptr,
      serverStack: &v28,
      clientStack: &v27,
      pPropList: v18->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory,
      nProps: v18->m_FastLocalTransfer.m_FastInt32.m_Size);
    LocalTransfer_FastType<short>(
      pBlah: nullptr,
      serverStack: &v28,
      clientStack: &v27,
      pPropList: v18->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory,
      nProps: v18->m_FastLocalTransfer.m_FastInt16.m_Size);
    LocalTransfer_FastType<char>(
      pBlah: nullptr,
      serverStack: &v28,
      clientStack: &v27,
      pPropList: v18->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory,
      nProps: v18->m_FastLocalTransfer.m_FastInt8.m_Size);
    LocalTransfer_FastType<Vector>(
      pBlah: nullptr,
      serverStack: &v28,
      clientStack: &v27,
      pPropList: v18->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory,
      nProps: v18->m_FastLocalTransfer.m_FastVector.m_Size);
  }
  if ( recip.m_nGrowSize >= 0 && recip.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: recip.m_pMemory);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1016DFB0
// Name: public: CClientDatatableStack::CClientDatatableStack(class CRecvDecoder __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
CClientDatatableStack *__thiscall CClientDatatableStack::CClientDatatableStack(
        CClientDatatableStack *this,
        CRecvDecoder *pDecoder,
        unsigned __int8 *pStructBase,
        int objectID)
{
  CDatatableStack::CDatatableStack(this, pPrecalc: &pDecoder->m_Precalc, pStructBase, objectID);
  this->m_pDecoder = pDecoder;
  this->__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016DFF0
// Name: public: CServerDatatableStack::CServerDatatableStack(class CSendTablePrecalc __near *,unsigned char __near *,int,class CUtlMemory<class CSendProxyRecipients,int> __near *)
// Source: json
//------------------------------------------------------------------------------
CServerDatatableStack *__thiscall CServerDatatableStack::CServerDatatableStack(
        CServerDatatableStack *this,
        CSendTablePrecalc *pPrecalc,
        unsigned __int8 *pStructBase,
        int objectID,
        CUtlMemory<CSendProxyRecipients,int> *pRecipients)
{
  CDatatableStack::CDatatableStack(this, pPrecalc, pStructBase, objectID);
  this->m_pPrecalc = pPrecalc;
  this->__vftable = (CServerDatatableStack_vtbl *)&CServerDatatableStack::`vftable';
  this->m_pRecipients = pRecipients;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016E030
// Name: void FastSortList(unsigned short __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FastSortList(unsigned __int16 *pList, unsigned __int16 nEntries)
{
  int v2; // ecx
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // si
  unsigned __int16 *v5; // eax

  if ( nEntries != 1 )
  {
    v2 = 0;
    do
    {
      while ( 1 )
      {
        v3 = pList[(unsigned __int16)v2 + 1];
        v4 = pList[(unsigned __int16)v2];
        v5 = &pList[(unsigned __int16)v2];
        if ( v3 >= v4 )
          break;
        v5[1] = v4;
        *v5 = v3;
        if ( (_WORD)v2 != 0 )
          v2 += 0xFFFF;
      }
      ++v2;
    }
    while ( (unsigned __int16)v2 < nEntries - 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E1F0
// Name: public: virtual void CClientDatatableStack::RecurseAndCallProxies(class CSendNode __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientDatatableStack::RecurseAndCallProxies(
        CClientDatatableStack *this,
        CSendNode *pNode,
        unsigned __int8 *pStructBase)
{
  CSendNode *v3; // eax
  unsigned __int8 *v5; // ecx
  int v6; // ebx
  CSendNode *v7; // edi
  unsigned __int8 *v8; // eax
  const RecvProp *v9; // eax
  int m_ObjectID; // [esp-8h] [ebp-14h]
  unsigned __int8 *v11; // [esp+8h] [ebp-4h] BYREF

  v3 = pNode;
  v5 = pStructBase;
  v6 = 0;
  this->m_pProxies[pNode->m_RecursiveProxyIndex] = pStructBase;
  if ( pNode->m_Children.m_Size > 0 )
  {
    while ( 1 )
    {
      v7 = v3->m_Children.m_Memory.m_pMemory[v6];
      v8 = nullptr;
      if ( v5 != nullptr )
      {
        v9 = this->m_pDecoder->m_DatatableProps.m_Memory.m_pMemory[v7->m_iDatatableProp];
        m_ObjectID = this->m_ObjectID;
        v11 = nullptr;
        v9->m_DataTableProxyFn(a1: v9, a2: (void **)&v11, a3: &v5[v9->m_Offset], a4: m_ObjectID);
        v8 = v11;
      }
      this->RecurseAndCallProxies(this, a2: v7, a3: v8);
      if ( ++v6 >= pNode->m_Children.m_Size )
        break;
      v5 = pStructBase;
      v3 = pNode;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E280
// Name: public: virtual void CServerDatatableStack::RecurseAndCallProxies(class CSendNode __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerDatatableStack::RecurseAndCallProxies(
        CServerDatatableStack *this,
        CSendNode *pNode,
        unsigned __int8 *pStructBase)
{
  CSendNode *v3; // edi
  int v5; // eax
  CSendNode *v6; // eax
  unsigned __int8 *v7; // ecx
  const SendProp *v8; // ecx
  CUtlMemory<CSendProxyRecipients,int> *m_pRecipients; // edx
  int m_DataTableProxyIndex; // eax
  CSendProxyRecipients *v11; // edi
  int v12; // eax
  int iChild; // [esp+8h] [ebp-8h]
  CSendNode *pCurChild; // [esp+Ch] [ebp-4h]

  v3 = pNode;
  this->m_pProxies[pNode->m_RecursiveProxyIndex] = pStructBase;
  v5 = 0;
  for ( iChild = 0; v5 < v3->m_Children.m_Size; iChild = v5 )
  {
    v6 = v3->m_Children.m_Memory.m_pMemory[v5];
    v7 = nullptr;
    pCurChild = v6;
    if ( pStructBase != nullptr )
    {
      v8 = this->m_pPrecalc->m_DatatableProps.m_Memory.m_pMemory[v6->m_iDatatableProp];
      m_pRecipients = this->m_pRecipients;
      if ( m_pRecipients == nullptr || (_WORD)(m_DataTableProxyIndex = v6->m_DataTableProxyIndex) == 255 )
      {
        v11 = &s_Recipients_1;
      }
      else
      {
        v11 = &m_pRecipients->m_pMemory[m_DataTableProxyIndex];
        if ( v11 != nullptr )
        {
          v11->m_Bits.m_Ints[0] = -1;
          v11->m_Bits.m_Ints[1] = -1;
        }
      }
      v12 = (int)v8->m_DataTableProxyFn(
                   a1: v8,
                   a2: pStructBase,
                   a3: &pStructBase[v8->m_Offset & 0xFFFFF],
                   a4: v11,
                   a5: this->m_ObjectID);
      if ( !this->m_bLocalNetworkBackDoor || v11 == &s_Recipients_1 || (v11->m_Bits.m_Ints[0] & 1) != 0 )
        v7 = (unsigned __int8 *)v12;
      else
        v7 = nullptr;
      v6 = pCurChild;
      v3 = pNode;
    }
    this->RecurseAndCallProxies(this, a2: v6, a3: v7);
    v5 = iChild + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E360
// Name: public: static unsigned char __near * CServerDatatableStack::CSendProxyCaller::CallProxy(class CServerDatatableStack __near *,unsigned char __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl CServerDatatableStack::CSendProxyCaller::CallProxy(
        CServerDatatableStack *pStack,
        unsigned __int8 *pStructBase,
        unsigned __int16 iDatatableProp)
{
  const SendProp *v3; // ecx
  CUtlMemory<CSendProxyRecipients,int> *m_pRecipients; // eax
  CSendProxyRecipients *m_pMemory; // edi
  unsigned __int8 *result; // eax

  v3 = pStack->m_pPrecalc->m_DatatableProps.m_Memory.m_pMemory[iDatatableProp];
  if ( pStack->m_bLocalNetworkBackDoor
    && (m_pRecipients = pStack->m_pRecipients) != nullptr
    && m_pRecipients->m_nAllocationCount > 0 )
  {
    m_pMemory = m_pRecipients->m_pMemory;
    if ( m_pRecipients->m_pMemory != nullptr )
    {
      m_pMemory->m_Bits.m_Ints[0] = -1;
      m_pMemory->m_Bits.m_Ints[1] = -1;
    }
  }
  else
  {
    m_pMemory = &s_Recipients_1;
  }
  result = (unsigned __int8 *)v3->m_DataTableProxyFn(
                                a1: v3,
                                a2: pStructBase,
                                a3: &pStructBase[v3->m_Offset & 0xFFFFF],
                                a4: m_pMemory,
                                a5: pStack->m_ObjectID);
  if ( pStack->m_bLocalNetworkBackDoor && m_pMemory != &s_Recipients_1 && (m_pMemory->m_Bits.m_Ints[0] & 1) == 0 )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E3F0
// Name: public: virtual void CPropMapStack::RecurseAndCallProxies(class CSendNode __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropMapStack::RecurseAndCallProxies(
        CPropMapStack *this,
        CSendNode *pNode,
        unsigned __int8 *pStructBase)
{
  CSendNode *v3; // eax
  int v5; // edi
  CSendNode *v6; // ebx
  unsigned __int8 *v7; // eax
  const SendProp *v8; // edx
  void *(__cdecl *m_DataTableProxyFn)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // ecx
  const CStandardSendProxies *m_pSendProxies; // eax
  CNonModifiedPointerProxy **m_ppNonModifiedPointerProxies; // eax
  CNonModifiedPointerProxy *v12; // eax

  v3 = pNode;
  v5 = 0;
  this->m_pProxies[pNode->m_RecursiveProxyIndex] = pStructBase;
  if ( pNode->m_Children.m_Size > 0 )
  {
    while ( 1 )
    {
      v6 = v3->m_Children.m_Memory.m_pMemory[v5];
      v7 = nullptr;
      if ( pStructBase == nullptr )
        goto LABEL_11;
      v8 = this->m_pPropMapStackPrecalc->m_DatatableProps.m_Memory.m_pMemory[v6->m_iDatatableProp];
      m_DataTableProxyFn = v8->m_DataTableProxyFn;
      m_pSendProxies = this->m_pSendProxies;
      if ( m_DataTableProxyFn != m_pSendProxies->m_DataTableToDataTable )
      {
        m_ppNonModifiedPointerProxies = m_pSendProxies->m_ppNonModifiedPointerProxies;
        if ( m_ppNonModifiedPointerProxies == nullptr || (v12 = *m_ppNonModifiedPointerProxies) == nullptr )
        {
LABEL_10:
          v7 = nullptr;
          goto LABEL_11;
        }
        while ( v12->m_Fn != m_DataTableProxyFn )
        {
          v12 = v12->m_pNext;
          if ( v12 == nullptr )
            goto LABEL_10;
        }
      }
      v7 = &pStructBase[v8->m_Offset & 0xFFFFF];
LABEL_11:
      this->RecurseAndCallProxies(this, a2: v6, a3: v7);
      if ( ++v5 >= pNode->m_Children.m_Size )
        return;
      v3 = pNode;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E490
// Name: unsigned char __near * UpdateRoutesExplicit_Template<class CClientDatatableStack,class CClientDatatableStack::CRecvProxyCaller>(class CClientDatatableStack __near *,class CClientDatatableStack::CRecvProxyCaller __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl UpdateRoutesExplicit_Template<CClientDatatableStack,CClientDatatableStack::CRecvProxyCaller>(
        CClientDatatableStack *pStack)
{
  CClientDatatableStack *v1; // esi
  CSendTablePrecalc *m_pPrecalc; // ecx
  int v3; // edx
  unsigned __int8 *result; // eax
  CSendTablePrecalc::CProxyPath *v5; // edx
  unsigned __int16 v6; // bx
  CSendTablePrecalc::CProxyPathEntry *v7; // ecx
  int m_iProxy; // edi
  const RecvProp *v9; // ecx
  CClientDatatableStack *v10; // eax
  int m_ObjectID; // [esp-Ch] [ebp-18h]
  int v12; // [esp+4h] [ebp-8h]
  CSendTablePrecalc::CProxyPath *proxyPath; // [esp+8h] [ebp-4h]

  v1 = pStack;
  m_pPrecalc = pStack->m_pPrecalc;
  v3 = m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[pStack->m_iCurProp];
  result = pStack->m_pProxies[v3];
  v12 = v3;
  if ( result == (unsigned __int8 *)-1 )
  {
    result = pStack->m_pStructBase;
    v5 = &m_pPrecalc->m_ProxyPaths.m_Memory.m_pMemory[v3];
    v6 = 0;
    for ( proxyPath = v5; v6 < v5->m_nEntries; ++v6 )
    {
      v7 = &v1->m_pPrecalc->m_ProxyPathEntries.m_Memory.m_pMemory[v6 + v5->m_iFirstEntry];
      m_iProxy = v7->m_iProxy;
      if ( v1->m_pProxies[m_iProxy] == (unsigned __int8 *)-1 )
      {
        v9 = v1->m_pDecoder->m_DatatableProps.m_Memory.m_pMemory[v7->m_iDatatableProp];
        m_ObjectID = v1->m_ObjectID;
        pStack = nullptr;
        v9->m_DataTableProxyFn(a1: v9, a2: (void **)&pStack, a3: &result[v9->m_Offset], a4: m_ObjectID);
        v10 = pStack;
        v1->m_pProxies[m_iProxy] = (unsigned __int8 *)pStack;
        if ( v10 == nullptr )
        {
          v1->m_pProxies[v12] = nullptr;
          return nullptr;
        }
        v5 = proxyPath;
      }
      result = v1->m_pProxies[m_iProxy];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E560
// Name: unsigned char __near * UpdateRoutesExplicit_Template<class CServerDatatableStack,class CServerDatatableStack::CSendProxyCaller>(class CServerDatatableStack __near *,class CServerDatatableStack::CSendProxyCaller __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl UpdateRoutesExplicit_Template<CServerDatatableStack,CServerDatatableStack::CSendProxyCaller>(
        CSendTablePrecalc::CProxyPath *pStack)
{
  CSendTablePrecalc *v2; // ecx
  int v3; // edx
  unsigned __int8 *result; // eax
  CSendTablePrecalc::CProxyPath *v5; // edx
  unsigned __int16 v6; // bx
  CSendTablePrecalc::CProxyPathEntry *v7; // ecx
  int m_iProxy; // edi
  unsigned __int8 *v9; // eax
  int v10; // [esp+4h] [ebp-4h]
  CSendTablePrecalc::CProxyPath *proxyPath; // [esp+10h] [ebp+8h]

  v2 = (CSendTablePrecalc *)pStack[71];
  v3 = v2->m_PropProxyIndices.m_Memory.m_pMemory[*(_DWORD *)&pStack[67]];
  result = (unsigned __int8 *)pStack[v3 + 2];
  v10 = v3;
  if ( result == (unsigned __int8 *)-1 )
  {
    result = (unsigned __int8 *)pStack[66];
    v5 = &v2->m_ProxyPaths.m_Memory.m_pMemory[v3];
    v6 = 0;
    for ( proxyPath = v5; v6 < v5->m_nEntries; ++v6 )
    {
      v7 = (CSendTablePrecalc::CProxyPathEntry *)(*(_DWORD *)(*(_DWORD *)&pStack[71] + 4) + 4 * (v6 + v5->m_iFirstEntry));
      m_iProxy = v7->m_iProxy;
      if ( *(_DWORD *)&pStack[m_iProxy + 2] == -1 )
      {
        v9 = CServerDatatableStack::CSendProxyCaller::CallProxy(
               (CServerDatatableStack *)pStack,
               pStructBase: result,
               iDatatableProp: v7->m_iDatatableProp);
        pStack[m_iProxy + 2] = (CSendTablePrecalc::CProxyPath)v9;
        if ( v9 == nullptr )
        {
          pStack[v10 + 2] = 0;
          return nullptr;
        }
        v5 = proxyPath;
      }
      result = (unsigned __int8 *)pStack[m_iProxy + 2];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E600
// Name: void LocalTransfer_FastType<int>(int __near *,class CServerDatatableStack __near &,class CClientDatatableStack __near &,class CFastLocalTransferPropInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_FastType<int>(
        int *pBlah,
        CServerDatatableStack *serverStack,
        CClientDatatableStack *clientStack,
        CFastLocalTransferPropInfo *pPropList,
        int nProps)
{
  CClientDatatableStack *v5; // esi
  unsigned __int16 *p_m_iProp; // eax
  int v7; // ecx
  CSendTablePrecalc *m_pPrecalc; // edi
  int v9; // ecx
  CSendTablePrecalc *v10; // edi
  unsigned __int8 *pServerBase; // [esp+14h] [ebp+14h]

  if ( nProps > 0 )
  {
    v5 = clientStack;
    p_m_iProp = &pPropList->m_iProp;
    do
    {
      v7 = *p_m_iProp;
      m_pPrecalc = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v7;
      serverStack->m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[v7];
      pServerBase = serverStack->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]];
      if ( pServerBase != nullptr )
      {
        v9 = *p_m_iProp;
        v10 = v5->m_pPrecalc;
        v5->m_iCurProp = v9;
        v5->m_pCurProp = v10->m_Props.m_Memory.m_pMemory[v9];
        *(_DWORD *)&v5->m_pProxies[v10->m_PropProxyIndices.m_Memory.m_pMemory[v9]][*(p_m_iProp - 2)] = *(_DWORD *)&pServerBase[*(p_m_iProp - 1)];
        v5 = clientStack;
      }
      p_m_iProp += 3;
      --nProps;
    }
    while ( nProps != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E690
// Name: void LocalTransfer_FastType<short>(short __near *,class CServerDatatableStack __near &,class CClientDatatableStack __near &,class CFastLocalTransferPropInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_FastType<short>(
        __int16 *pBlah,
        CServerDatatableStack *serverStack,
        CClientDatatableStack *clientStack,
        CFastLocalTransferPropInfo *pPropList,
        int nProps)
{
  CClientDatatableStack *v5; // esi
  unsigned __int16 *p_m_iProp; // eax
  int v7; // ecx
  CSendTablePrecalc *m_pPrecalc; // edi
  int v9; // ecx
  CSendTablePrecalc *v10; // edi
  unsigned __int8 *pServerBase; // [esp+14h] [ebp+14h]

  if ( nProps > 0 )
  {
    v5 = clientStack;
    p_m_iProp = &pPropList->m_iProp;
    do
    {
      v7 = *p_m_iProp;
      m_pPrecalc = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v7;
      serverStack->m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[v7];
      pServerBase = serverStack->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]];
      if ( pServerBase != nullptr )
      {
        v9 = *p_m_iProp;
        v10 = v5->m_pPrecalc;
        v5->m_iCurProp = v9;
        v5->m_pCurProp = v10->m_Props.m_Memory.m_pMemory[v9];
        *(_WORD *)&v5->m_pProxies[v10->m_PropProxyIndices.m_Memory.m_pMemory[v9]][*(p_m_iProp - 2)] = *(_WORD *)&pServerBase[*(p_m_iProp - 1)];
        v5 = clientStack;
      }
      p_m_iProp += 3;
      --nProps;
    }
    while ( nProps != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E720
// Name: void LocalTransfer_FastType<char>(char __near *,class CServerDatatableStack __near &,class CClientDatatableStack __near &,class CFastLocalTransferPropInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_FastType<char>(
        char *pBlah,
        CServerDatatableStack *serverStack,
        CClientDatatableStack *clientStack,
        CFastLocalTransferPropInfo *pPropList,
        int nProps)
{
  CClientDatatableStack *v5; // esi
  unsigned __int16 *p_m_iProp; // eax
  int v7; // ecx
  CSendTablePrecalc *m_pPrecalc; // edi
  int v9; // ecx
  CSendTablePrecalc *v10; // edi
  unsigned __int8 *v11; // ecx
  unsigned __int8 *pServerBase; // [esp+14h] [ebp+14h]

  if ( nProps > 0 )
  {
    v5 = clientStack;
    p_m_iProp = &pPropList->m_iProp;
    do
    {
      v7 = *p_m_iProp;
      m_pPrecalc = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v7;
      serverStack->m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[v7];
      pServerBase = serverStack->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v7]];
      if ( pServerBase != nullptr )
      {
        v9 = *p_m_iProp;
        v10 = v5->m_pPrecalc;
        v5->m_iCurProp = v9;
        v5->m_pCurProp = v10->m_Props.m_Memory.m_pMemory[v9];
        v11 = v5->m_pProxies[v10->m_PropProxyIndices.m_Memory.m_pMemory[v9]];
        v5 = clientStack;
        v11[*(p_m_iProp - 2)] = pServerBase[*(p_m_iProp - 1)];
      }
      p_m_iProp += 3;
      --nProps;
    }
    while ( nProps != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E7B0
// Name: void LocalTransfer_FastType<class Vector>(class Vector __near *,class CServerDatatableStack __near &,class CClientDatatableStack __near &,class CFastLocalTransferPropInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_FastType<Vector>(
        Vector *pBlah,
        CServerDatatableStack *serverStack,
        CClientDatatableStack *clientStack,
        CFastLocalTransferPropInfo *pPropList,
        int nProps)
{
  int v6; // esi
  int v7; // ebx
  int m_iProp; // esi
  CSendTablePrecalc *m_pPrecalc; // edi
  int v10; // edi
  CSendTablePrecalc *v11; // ebx
  float *v12; // esi
  float *v13; // edi
  int v14; // esi
  CSendTablePrecalc *v15; // edi
  int v16; // edi
  CSendTablePrecalc *v17; // ebx
  float *v18; // esi
  float *v19; // edi
  int v20; // esi
  CSendTablePrecalc *v21; // edi
  int v22; // edi
  CSendTablePrecalc *v23; // ebx
  float *v24; // esi
  float *v25; // edi
  int v26; // esi
  CSendTablePrecalc *v27; // edi
  int v28; // edi
  CSendTablePrecalc *v29; // ebx
  float *v30; // esi
  float *v31; // edi
  unsigned __int16 *p_m_iProp; // edi
  int v33; // ecx
  CSendTablePrecalc *v34; // esi
  int v35; // esi
  CSendTablePrecalc *v36; // ebx
  float *v37; // ecx
  float *v38; // esi
  int i; // [esp+Ch] [ebp-8h]
  unsigned int v40; // [esp+10h] [ebp-4h]
  unsigned __int8 *pServerBase; // [esp+28h] [ebp+14h]
  unsigned __int8 *pServerBasea; // [esp+28h] [ebp+14h]
  unsigned __int8 *pServerBaseb; // [esp+28h] [ebp+14h]
  unsigned __int8 *pServerBasec; // [esp+28h] [ebp+14h]
  unsigned __int8 *pServerBased; // [esp+28h] [ebp+14h]
  int nPropsa; // [esp+2Ch] [ebp+18h]

  v6 = nProps;
  v7 = 0;
  if ( nProps >= 4 )
  {
    v40 = ((unsigned int)(nProps - 4) >> 2) + 1;
    i = 4 * v40;
    do
    {
      m_iProp = pPropList->m_iProp;
      m_pPrecalc = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = m_iProp;
      serverStack->m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[m_iProp];
      pServerBase = serverStack->m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[m_iProp]];
      if ( pServerBase != nullptr )
      {
        v10 = pPropList->m_iProp;
        v11 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v10;
        clientStack->m_pCurProp = v11->m_Props.m_Memory.m_pMemory[v10];
        v12 = (float *)&pServerBase[pPropList->m_iSendOffset];
        v13 = (float *)&clientStack->m_pProxies[v11->m_PropProxyIndices.m_Memory.m_pMemory[v10]][pPropList->m_iRecvOffset];
        *v13 = *v12;
        v13[1] = v12[1];
        v13[2] = v12[2];
      }
      v14 = pPropList[1].m_iProp;
      v15 = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v14;
      serverStack->m_pCurProp = v15->m_Props.m_Memory.m_pMemory[v14];
      pServerBasea = serverStack->m_pProxies[v15->m_PropProxyIndices.m_Memory.m_pMemory[v14]];
      if ( pServerBasea != nullptr )
      {
        v16 = pPropList[1].m_iProp;
        v17 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v16;
        clientStack->m_pCurProp = v17->m_Props.m_Memory.m_pMemory[v16];
        v18 = (float *)&pServerBasea[pPropList[1].m_iSendOffset];
        v19 = (float *)&clientStack->m_pProxies[v17->m_PropProxyIndices.m_Memory.m_pMemory[v16]][pPropList[1].m_iRecvOffset];
        *v19 = *v18;
        v19[1] = v18[1];
        v19[2] = v18[2];
      }
      v20 = pPropList[2].m_iProp;
      v21 = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v20;
      serverStack->m_pCurProp = v21->m_Props.m_Memory.m_pMemory[v20];
      pServerBaseb = serverStack->m_pProxies[v21->m_PropProxyIndices.m_Memory.m_pMemory[v20]];
      if ( pServerBaseb != nullptr )
      {
        v22 = pPropList[2].m_iProp;
        v23 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v22;
        clientStack->m_pCurProp = v23->m_Props.m_Memory.m_pMemory[v22];
        v24 = (float *)&pServerBaseb[pPropList[2].m_iSendOffset];
        v25 = (float *)&clientStack->m_pProxies[v23->m_PropProxyIndices.m_Memory.m_pMemory[v22]][pPropList[2].m_iRecvOffset];
        *v25 = *v24;
        v25[1] = v24[1];
        v25[2] = v24[2];
      }
      v26 = pPropList[3].m_iProp;
      v27 = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v26;
      serverStack->m_pCurProp = v27->m_Props.m_Memory.m_pMemory[v26];
      pServerBasec = serverStack->m_pProxies[v27->m_PropProxyIndices.m_Memory.m_pMemory[v26]];
      if ( pServerBasec != nullptr )
      {
        v28 = pPropList[3].m_iProp;
        v29 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v28;
        clientStack->m_pCurProp = v29->m_Props.m_Memory.m_pMemory[v28];
        v30 = (float *)&pServerBasec[pPropList[3].m_iSendOffset];
        v31 = (float *)&clientStack->m_pProxies[v29->m_PropProxyIndices.m_Memory.m_pMemory[v28]][pPropList[3].m_iRecvOffset];
        *v31 = *v30;
        v31[1] = v30[1];
        v31[2] = v30[2];
      }
      v6 = nProps;
      pPropList += 4;
      --v40;
    }
    while ( v40 != 0 );
    v7 = i;
  }
  if ( v7 < v6 )
  {
    p_m_iProp = &pPropList->m_iProp;
    nPropsa = v6 - v7;
    do
    {
      v33 = *p_m_iProp;
      v34 = serverStack->CDatatableStack::m_pPrecalc;
      serverStack->m_iCurProp = v33;
      serverStack->m_pCurProp = v34->m_Props.m_Memory.m_pMemory[v33];
      pServerBased = serverStack->m_pProxies[v34->m_PropProxyIndices.m_Memory.m_pMemory[v33]];
      if ( pServerBased != nullptr )
      {
        v35 = *p_m_iProp;
        v36 = clientStack->m_pPrecalc;
        clientStack->m_iCurProp = v35;
        clientStack->m_pCurProp = v36->m_Props.m_Memory.m_pMemory[v35];
        v37 = (float *)&pServerBased[*(p_m_iProp - 1)];
        v38 = (float *)&clientStack->m_pProxies[v36->m_PropProxyIndices.m_Memory.m_pMemory[v35]][*(p_m_iProp - 2)];
        *v38 = *v37;
        v38[1] = v37[1];
        v38[2] = v37[2];
      }
      p_m_iProp += 3;
      --nPropsa;
    }
    while ( nPropsa != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F4D0
// Name: void PrintPartialChangeEntsList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintPartialChangeEntsList()
{
  int v0; // esi
  char v1; // al
  int v2; // esi
  char v3; // al
  int *m_pMemory; // eax
  char tempStr[512]; // [esp+4h] [ebp-400h] BYREF
  char str[512]; // [esp+204h] [ebp-200h] BYREF

  if ( dt_ShowPartialChangeEnts.m_pParent != nullptr && dt_ShowPartialChangeEnts.m_pParent->m_Value.m_nValue != 0 )
  {
    Con_NPrintf(idx: 15, fmt: "----- dt_ShowPartialChangeEnts -----");
    Con_NPrintf(idx: 16, fmt: defaultValue);
    Con_NPrintf(idx: 17, fmt: "Ent changes: %3d, prop changes: %3d", g_nTotalEntChanges, g_nTotalPropChanges);
    Con_NPrintf(idx: 18, fmt: defaultValue);
    v0 = 0;
    v1 = 1;
    for ( str[0] = 0; v0 < g_PartialChangeEnts.m_Size; ++v0 )
    {
      if ( g_PartialChangeEnts.m_Memory.m_pMemory[v0] >= 0 )
      {
        if ( v1 == 0 )
          V_strncat(pDest: str, pSrc: ", ", destBufferSize: 0x200u, max_chars_to_copy: -1);
        V_snprintf(pDest: tempStr, maxLen: 512, pFormat: "%d", g_PartialChangeEnts.m_Memory.m_pMemory[v0]);
        V_strncat(pDest: str, pSrc: tempStr, destBufferSize: 0x200u, max_chars_to_copy: -1);
        v1 = 0;
      }
    }
    V_strncat(pDest: str, pSrc: " - PARTIAL", destBufferSize: 0x200u, max_chars_to_copy: -1);
    Con_NPrintf(idx: 19, fmt: "%s", str);
    v2 = 0;
    v3 = 1;
    for ( str[0] = 0; v2 < g_PartialChangeEnts.m_Size; ++v2 )
    {
      if ( g_PartialChangeEnts.m_Memory.m_pMemory[v2] < 0 )
      {
        if ( v3 == 0 )
          V_strncat(pDest: str, pSrc: ", ", destBufferSize: 0x200u, max_chars_to_copy: -1);
        V_snprintf(pDest: tempStr, maxLen: 512, pFormat: "%d", -g_PartialChangeEnts.m_Memory.m_pMemory[v2]);
        V_strncat(pDest: str, pSrc: tempStr, destBufferSize: 0x200u, max_chars_to_copy: -1);
        v3 = 0;
      }
    }
    V_strncat(pDest: str, pSrc: " -    FULL", destBufferSize: 0x200u, max_chars_to_copy: -1);
    Con_NPrintf(idx: 20, fmt: "%s", str);
    m_pMemory = g_PartialChangeEnts.m_Memory.m_pMemory;
    g_PartialChangeEnts.m_Size = 0;
    if ( g_PartialChangeEnts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_PartialChangeEnts.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_PartialChangeEnts.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_PartialChangeEnts.m_Memory.m_pMemory = nullptr;
      }
      g_PartialChangeEnts.m_Memory.m_nAllocationCount = 0;
    }
    g_PartialChangeEnts.m_pElements = m_pMemory;
    g_nTotalEntChanges = 0;
    g_nTotalPropChanges = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F6F0
// Name: void AddToPartialChangeEntsList(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddToPartialChangeEntsList(int iEnt, bool bPartial)
{
  int v2; // edi
  int m_Size; // eax
  int *m_pMemory; // edx
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  int *v8; // eax

  if ( dt_ShowPartialChangeEnts.m_pParent != nullptr && dt_ShowPartialChangeEnts.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = iEnt;
    if ( !bPartial )
      v2 = -iEnt;
    m_Size = g_PartialChangeEnts.m_Size;
    m_pMemory = g_PartialChangeEnts.m_Memory.m_pMemory;
    v5 = 0;
    if ( g_PartialChangeEnts.m_Size <= 0 )
      goto LABEL_10;
    while ( g_PartialChangeEnts.m_Memory.m_pMemory[v5] != v2 )
    {
      if ( ++v5 >= g_PartialChangeEnts.m_Size )
        goto LABEL_10;
    }
    if ( v5 == -1 )
    {
LABEL_10:
      v6 = g_PartialChangeEnts.m_Size;
      if ( g_PartialChangeEnts.m_Size + 1 > g_PartialChangeEnts.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&g_PartialChangeEnts,
          num: g_PartialChangeEnts.m_Size - g_PartialChangeEnts.m_Memory.m_nAllocationCount + 1);
        m_Size = g_PartialChangeEnts.m_Size;
        m_pMemory = g_PartialChangeEnts.m_Memory.m_pMemory;
      }
      g_PartialChangeEnts.m_Size = m_Size + 1;
      v7 = m_Size - v6;
      g_PartialChangeEnts.m_pElements = m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v7);
        m_pMemory = g_PartialChangeEnts.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v6];
      if ( v8 != nullptr )
        *v8 = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F7A0
// Name: void AddPropOffsetToMap(class CSendTablePrecalc __near *,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddPropOffsetToMap(CSendTablePrecalc *pPrecalc, PropIndicesCollection_t iInProp, int iInOffset)
{
  unsigned __int16 v3; // di
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short> *p_m_PropOffsetToIndexMap; // esi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *v10; // eax
  int v11; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *v13; // ecx
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t *p_m_Data; // edi
  PropIndicesCollection_t *p_elem; // ecx
  unsigned int i; // eax
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  v3 = iInOffset;
  p_m_PropOffsetToIndexMap = &pPrecalc->m_PropOffsetToIndexMap;
  search.key = iInOffset;
  v5 = CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &pPrecalc->m_PropOffsetToIndexMap.m_Tree,
         &search);
  if ( v5 == 0xFFFF )
  {
    iInProp.m_Indices[1] = -1;
    iInOffset = 0xFFFF;
    search.elem = iInProp;
    search.key = v3;
    HIBYTE(iInProp.m_Indices[1]) = 0;
    CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &p_m_PropOffsetToIndexMap->m_Tree,
      insert: &search,
      parent: (unsigned __int16 *)&iInOffset,
      leftchild: (bool *)&iInProp + 3);
    v6 = CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &p_m_PropOffsetToIndexMap->m_Tree);
    v7 = iInOffset;
    v8 = v6;
    v9 = v6;
    v10 = &pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory[v9];
    v10->m_Right = -1;
    v10->m_Left = -1;
    v10->m_Parent = v7;
    v10->m_Tag = 0;
    if ( v7 == 0xFFFF )
    {
      pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Root = v8;
    }
    else
    {
      v11 = v7;
      m_pMemory = pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory;
      if ( HIBYTE(iInProp.m_Indices[1]) != 0 )
        m_pMemory[v11].m_Left = v8;
      else
        m_pMemory[v11].m_Right = v8;
    }
    CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &p_m_PropOffsetToIndexMap->m_Tree,
      elem: v8);
    v13 = pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory;
    ++pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_NumElements;
    p_m_Data = &v13[v9].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = search;
  }
  else
  {
    p_elem = &pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
    for ( i = 0; i < 2; ++i )
    {
      if ( p_elem->m_Indices[i] == 0xFFFF )
      {
        p_elem->m_Indices[i] = iInProp.m_Indices[0];
        return;
      }
    }
    _Error(a1: "Overflowed a PropIndicesCollection_t on %s\n", pPrecalc->m_pSendTable->m_pNetTableName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F8F0
// Name: void BuildPropOffsetToIndexMap(class CSendTablePrecalc __near *,class CStandardSendProxies const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildPropOffsetToIndexMap(CSendTablePrecalc *pPrecalc, const CStandardSendProxies *pSendProxies)
{
  CSendTablePrecalc *v2; // esi
  int v3; // ebx
  CSendTablePrecalc *m_pPrecalc; // edx
  unsigned __int8 *v5; // eax
  const SendProp *v6; // esi
  int v7; // edi
  int m_nElements; // ecx
  SendPropType m_Type; // eax
  int v10; // eax
  int v11; // eax
  CPropMapStack pmStack; // [esp+8h] [ebp-128h] BYREF
  int v13; // [esp+12Ch] [ebp-4h]
  int elementStride; // [esp+13Ch] [ebp+Ch]

  v2 = pPrecalc;
  CDatatableStack::CDatatableStack(this: &pmStack, pPrecalc, pStructBase: (unsigned __int8 *)1, objectID: -1);
  pmStack.__vftable = (CPropMapStack_vtbl *)&CPropMapStack::`vftable';
  pmStack.m_pPropMapStackPrecalc = pPrecalc;
  pmStack.m_pSendProxies = pSendProxies;
  CDatatableStack::Init(this: &pmStack, bExplicitRoutes: false, bLocalNetworkBackDoor: false);
  v3 = 0;
  if ( pPrecalc->m_Props.m_Size > 0 )
  {
    m_pPrecalc = pmStack.m_pPrecalc;
    do
    {
      pmStack.m_iCurProp = v3;
      pmStack.m_pCurProp = m_pPrecalc->m_Props.m_Memory.m_pMemory[v3];
      v5 = pmStack.m_pProxies[m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v3]];
      if ( v5 != nullptr )
      {
        v6 = v2->m_Props.m_Memory.m_pMemory[v3];
        v7 = (int)&v5[(v6->m_Offset & 0xFFFFF) - 1];
        m_nElements = 1;
        elementStride = 0;
        if ( v6->m_Type == DPT_Array )
        {
          v7 = (int)&v5[(v6->m_pArrayProp->m_Offset & 0xFFFFF) - 1];
          m_nElements = v6->m_nElements;
          elementStride = v6->m_ElementStride;
        }
        if ( v7 != 0 && m_nElements > 0 )
        {
          v13 = m_nElements;
          while ( 1 )
          {
            m_Type = v6->m_Type;
            if ( m_Type == DPT_Vector )
            {
              v10 = v6->m_Offset >> 20;
              if ( (v10 & 2) != 0 )
              {
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7);
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7 + 4);
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7 + 8);
              }
              else
              {
                if ( (v10 & 4) == 0 )
                  goto LABEL_18;
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7);
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7 + 8);
              }
            }
            else
            {
              if ( m_Type != DPT_VectorXY || ((v11 = v6->m_Offset >> 20) & 2) == 0 )
              {
LABEL_18:
                AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7);
                goto LABEL_19;
              }
              AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7);
              AddPropOffsetToMap(pPrecalc, iInProp: (PropIndicesCollection_t)v3, iInOffset: v7 + 4);
            }
LABEL_19:
            v7 += elementStride;
            if ( --v13 == 0 )
            {
              m_pPrecalc = pmStack.m_pPrecalc;
              break;
            }
          }
        }
        v2 = pPrecalc;
      }
      ++v3;
    }
    while ( v3 < v2->m_Props.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FAC0
// Name: void LocalTransfer_InitFastCopy(class SendTable const __near *,class CStandardSendProxies const __near *,class RecvTable __near *,class CStandardRecvProxies const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_InitFastCopy(
        CSendTablePrecalc *pSendTable,
        const CStandardSendProxies *pSendProxies,
        const RecvProp *pRecvTable,
        const CStandardRecvProxies *pRecvProxies,
        int *nSlowCopyProps,
        int *nFastCopyProps)
{
  CUtlMemory<sentencegroup_t,int> *v6; // esi
  const CStandardSendProxies *v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  CUtlMemory<sentencegroup_t,int> *p_m_FastLocalTransfer; // esi
  void (__cdecl *v12)(const SendProp *, const void *, const void *, DVariant *, int, int); // eax
  void (__cdecl *v13)(const SendProp *, const void *, const void *, DVariant *, int, int); // eax
  void (__cdecl *v14)(const SendProp *, const void *, const void *, DVariant *, int, int); // eax
  sentencegroup_t *m_pMemory; // edi
  int m_nAllocationCount; // eax
  sentencegroup_t *v17; // ecx
  int v18; // eax
  sentencegroup_t *v19; // edx
  int v20; // ecx
  sentencegroup_t *v21; // eax
  int toAdd; // [esp+Ch] [ebp-14h]
  int iNumProp; // [esp+14h] [ebp-Ch]
  CRecvDecoder *pDecoder; // [esp+18h] [ebp-8h]
  int iProp; // [esp+1Ch] [ebp-4h]
  CSendTablePrecalc *pPrecalc; // [esp+28h] [ebp+8h]
  const RecvProp *pRecvProp; // [esp+30h] [ebp+10h]

  pPrecalc = (CSendTablePrecalc *)pSendTable->m_ProxyPathEntries.m_Memory.m_nGrowSize;
  v6 = (CUtlMemory<sentencegroup_t,int> *)pPrecalc;
  CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &pPrecalc->m_PropOffsetToIndexMap.m_Tree);
  v7 = pSendProxies;
  BuildPropOffsetToIndexMap(pPrecalc, pSendProxies);
  pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_FastInt32.m_pElements = pPrecalc->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory;
  pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_FastInt16.m_pElements = pPrecalc->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory;
  pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_FastInt8.m_pElements = pPrecalc->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory;
  pPrecalc->m_FastLocalTransfer.m_FastVector.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_FastVector.m_pElements = pPrecalc->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory;
  pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Size = 0;
  if ( pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory);
      pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory = nullptr;
    }
    pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_nAllocationCount = 0;
  }
  pPrecalc->m_FastLocalTransfer.m_OtherProps.m_pElements = pPrecalc->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory;
  pDecoder = (CRecvDecoder *)pRecvTable->m_Flags;
  v8 = 0;
  iNumProp = pPrecalc->m_Props.m_Size;
  iProp = 0;
  if ( iNumProp > 0 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(v6[3].m_nGrowSize + 4 * v8);
      pRecvProp = pDecoder->m_Props.m_Memory.m_pMemory[v8];
      if ( pRecvProp != nullptr )
        break;
LABEL_56:
      iProp = ++v8;
      if ( v8 >= iNumProp )
        return;
    }
    v10 = *(_DWORD *)(v9 + 8);
    p_m_FastLocalTransfer = v6 + 19;
    if ( v10 == 0 )
    {
      v12 = *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64);
      if ( v12 == v7->m_Int32ToInt32 || v12 == v7->m_UInt32ToInt32 )
      {
        if ( pRecvProp->m_ProxyFn == pRecvProxies->m_Int32ToInt32 )
        {
          p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer;
          ++*nFastCopyProps;
LABEL_49:
          m_pMemory = p_m_FastLocalTransfer[1].m_pMemory;
          LOWORD(toAdd) = pRecvProp->m_Offset;
          m_nAllocationCount = p_m_FastLocalTransfer->m_nAllocationCount;
          HIWORD(toAdd) = *(_WORD *)(v9 + 76);
          if ( (int)&m_pMemory->count + 1 > m_nAllocationCount )
            CUtlMemory<sentencegroup_t,int>::Grow(
              this: p_m_FastLocalTransfer,
              num: (int)&m_pMemory->count - m_nAllocationCount + 1);
          ++p_m_FastLocalTransfer[1].m_pMemory;
          v17 = p_m_FastLocalTransfer->m_pMemory;
          v18 = (char *)p_m_FastLocalTransfer[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_FastLocalTransfer[1].m_nAllocationCount = (int)p_m_FastLocalTransfer->m_pMemory;
          if ( v18 > 0 )
            _V_memmove(dest: &v17[(int)m_pMemory + 1], src: &v17[(_DWORD)m_pMemory], count: 6 * v18);
          v19 = p_m_FastLocalTransfer->m_pMemory;
          v6 = (CUtlMemory<sentencegroup_t,int> *)pPrecalc;
          v20 = (int)m_pMemory;
          v7 = pSendProxies;
          v21 = &v19[v20];
          if ( v21 != nullptr )
          {
            *(_DWORD *)&v21->count = toAdd;
            v21->groupname.m_Id = iProp;
          }
          v8 = iProp;
          goto LABEL_56;
        }
        v7 = pSendProxies;
      }
      v13 = *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64);
      if ( v13 == v7->m_Int16ToInt32 || v13 == v7->m_UInt16ToInt32 )
      {
        if ( pRecvProp->m_ProxyFn == pRecvProxies->m_Int32ToInt16 )
        {
          p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer.m_FastInt16;
          ++*nFastCopyProps;
          goto LABEL_49;
        }
        v7 = pSendProxies;
      }
      v14 = *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64);
      if ( v14 == v7->m_Int8ToInt32 || v14 == v7->m_UInt8ToInt32 )
      {
        if ( pRecvProp->m_ProxyFn == pRecvProxies->m_Int32ToInt8 )
        {
          p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer.m_FastInt8;
          ++*nFastCopyProps;
          goto LABEL_49;
        }
        v7 = pSendProxies;
      }
    }
    if ( v10 == 1
      && *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64) == v7->m_FloatToFloat )
    {
      if ( pRecvProp->m_ProxyFn == pRecvProxies->m_FloatToFloat )
      {
        p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer;
        ++*nFastCopyProps;
        goto LABEL_49;
      }
      v7 = pSendProxies;
    }
    if ( v10 == 2
      && *(void (__cdecl **)(const SendProp *, const void *, const void *, DVariant *, int, int))(v9 + 64) == v7->m_VectorToVector
      && pRecvProp->m_ProxyFn == pRecvProxies->m_VectorToVector )
    {
      p_m_FastLocalTransfer = (CUtlMemory<sentencegroup_t,int> *)&pPrecalc->m_FastLocalTransfer.m_FastVector;
      ++*nFastCopyProps;
    }
    else
    {
      ++*nSlowCopyProps;
    }
    goto LABEL_49;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FE00
// Name: int MapPropOffsetsToIndices(class CBaseEdict const __near *,class CSendTablePrecalc __near *,unsigned short const __near *,unsigned short,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MapPropOffsetsToIndices(
        const CBaseEdict *pEdict,
        CSendTablePrecalc *pPrecalc,
        unsigned __int16 *pOffsets,
        unsigned __int16 nOffsets,
        unsigned __int16 *pOut)
{
  int v6; // ebx
  unsigned __int16 *v7; // esi
  CSendTablePrecalc *v8; // edi
  unsigned __int16 v9; // ax
  const char *v10; // eax
  unsigned int i; // edi
  unsigned __int16 v12; // si
  int v13; // eax
  bool v14; // zf
  char str[512]; // [esp+4h] [ebp-218h] BYREF
  CUtlMap<char const *,int,int>::Node_t v17; // [esp+204h] [ebp-18h] BYREF
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t search; // [esp+20Ch] [ebp-10h] BYREF
  const PropIndicesCollection_t *coll; // [esp+214h] [ebp-8h]
  int v20; // [esp+218h] [ebp-4h]
  const unsigned __int16 *nOffsetsa; // [esp+230h] [ebp+14h]

  v6 = 0;
  if ( nOffsets != 0 )
  {
    v7 = pOffsets;
    v8 = pPrecalc;
    nOffsetsa = pOffsets;
    v20 = nOffsets;
    do
    {
      search.key = *v7;
      v9 = CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &v8->m_PropOffsetToIndexMap.m_Tree,
             &search);
      if ( v9 == 0xFFFF )
      {
        if ( dt_ShowPartialChangeEnts.m_pParent != nullptr && dt_ShowPartialChangeEnts.m_pParent->m_Value.m_nValue != 0 )
        {
          if ( (`MapPropOffsetsToIndices'::`10'::`local static guard' & 1) == 0 )
          {
            `MapPropOffsetsToIndices'::`10'::`local static guard' |= 1u;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_Root = -1;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_NumElements = 0;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_FirstFree = -1;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_LastAlloc.index = -1;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_pElements = nullptr;
            `MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
            atexit(func: `MapPropOffsetsToIndices'::`10'::`dynamic atexit destructor for 'testDict'');
          }
          if ( pEdict->m_pUnk != nullptr )
            v10 = pEdict->m_pNetworkable->GetClassNameA(this: pEdict->m_pNetworkable);
          else
            v10 = defaultValue;
          V_snprintf(
            pDest: str,
            maxLen: 512,
            pFormat: "LocalTransfer offset miss - class: %s, DT: %s, offset: %d",
            v10,
            v8->m_pSendTable->m_pNetTableName,
            *v7);
          v17.key = str;
          if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                 this: &`MapPropOffsetsToIndices'::`10'::testDict.m_Elements.m_Tree,
                 search: &v17) == -1 )
          {
            CUtlDict<int,int>::Insert(this: &`MapPropOffsetsToIndices'::`10'::testDict, pName: str);
            _Warning(a1: "%s\n", str);
          }
        }
      }
      else
      {
        coll = &v8->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
        for ( i = 0; i < 2; ++i )
        {
          v12 = coll->m_Indices[i];
          if ( v12 != 0xFFFF )
          {
            v13 = 0;
            if ( v6 <= 0 )
            {
LABEL_18:
              if ( v6 >= 114 )
                _Error(a1: "Overflowed output list in MapPropOffsetsToIndices");
              pOut[v6++] = v12;
            }
            else
            {
              while ( pOut[v13] != v12 )
              {
                if ( ++v13 >= v6 )
                  goto LABEL_18;
              }
            }
          }
        }
        v8 = pPrecalc;
        v7 = (unsigned __int16 *)nOffsetsa;
      }
      ++v7;
      v14 = v20-- == 1;
      nOffsetsa = v7;
    }
    while ( !v14 );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1016FFE0
// Name: void LocalTransfer_TransferEntity(class CBaseEdict const __near *,class SendTable const __near *,void const __near *,class RecvTable __near *,void __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LocalTransfer_TransferEntity(
        CBaseEdict *pEdict,
        const SendTable *pSendTable,
        unsigned __int8 *pSrcEnt,
        RecvTable *pRecvTable,
        unsigned __int8 *pDestEnt,
        bool bNewlyCreated,
        bool bJustEnteredPVS,
        int objectID)
{
  CEdictChangeInfo *v8; // edi
  int m_nDataTableProxies; // eax
  CSendTablePrecalc *m_pPrecalc; // ebx
  int v11; // edi
  CSendTablePrecalc *m_pDecoder; // esi
  int v13; // edi
  int v14; // esi
  unsigned __int8 *v15; // ebx
  int v16; // edi
  unsigned __int8 *v17; // eax
  CSendTablePrecalc *v18; // ebx
  char *v19; // edi
  CSendTablePrecalc *v20; // ecx
  int v21; // eax
  const SendProp *v22; // ebx
  const unsigned __int8 *v23; // esi
  int v24; // ecx
  unsigned __int8 tempData[256]; // [esp+Ch] [ebp-480h] BYREF
  CServerDatatableStack serverStack; // [esp+10Ch] [ebp-380h] BYREF
  CClientDatatableStack v27; // [esp+230h] [ebp-25Ch] BYREF
  CServerDatatableStack v28; // [esp+350h] [ebp-13Ch] BYREF
  CUtlMemory<CSendProxyRecipients,int> recip; // [esp+474h] [ebp-18h] BYREF
  const SendProp *pSendProp; // [esp+480h] [ebp-Ch]
  CSendTablePrecalc *pPrecalc; // [esp+484h] [ebp-8h]
  int nChangeOffsets; // [esp+488h] [ebp-4h]
  int iChanged; // [esp+498h] [ebp+Ch]
  unsigned __int16 *iChangeda; // [esp+498h] [ebp+Ch]

  ++g_nTotalEntChanges;
  v8 = &g_pSharedChangeInfo->m_ChangeInfos[CBaseEdict::GetChangeAccessor(this: pEdict)->m_iChangeInfo];
  m_nDataTableProxies = pSendTable->m_pPrecalc->m_nDataTableProxies;
  recip.m_pMemory = (CSendProxyRecipients *)tempData;
  recip.m_nAllocationCount = m_nDataTableProxies;
  recip.m_nGrowSize = -1;
  if ( CBaseEdict::GetChangeAccessor(this: pEdict)->m_iChangeInfoSerialNumber == g_pSharedChangeInfo->m_iSerialNumber
    && !bNewlyCreated
    && !bJustEnteredPVS
    && dt_UsePartialChangeEnts.m_pParent != nullptr
    && dt_UsePartialChangeEnts.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pPrecalc = pSendTable->m_pPrecalc;
    v11 = MapPropOffsetsToIndices(
            pEdict,
            pPrecalc: m_pPrecalc,
            pOffsets: v8->m_ChangeOffsets,
            nOffsets: v8->m_nChangeOffsets,
            pOut: (unsigned __int16 *)&v27.m_pProxies[13]);
    nChangeOffsets = v11;
    if ( v11 == 0 )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&recip);
      return;
    }
    AddToPartialChangeEntsList(iEnt: (edict_t *)pEdict - sv.edicts, bPartial: true);
    FastSortList(pList: (unsigned __int16 *)&v27.m_pProxies[13], nEntries: v11);
    if ( m_pPrecalc == nullptr )
      _Error(a1: "SendTable_Encode: Missing m_pPrecalc for SendTable %s.", pSendTable->m_pNetTableName);
    CServerDatatableStack::CServerDatatableStack(
      this: &serverStack,
      pPrecalc: m_pPrecalc,
      pStructBase: pSrcEnt,
      objectID,
      pRecipients: &recip);
    CDatatableStack::Init(this: &serverStack, bExplicitRoutes: true, bLocalNetworkBackDoor: true);
    m_pDecoder = (CSendTablePrecalc *)pRecvTable->m_pDecoder;
    pPrecalc = m_pDecoder;
    if ( m_pDecoder == nullptr )
      _Error(a1: "RecvTable_Decode: table '%s' missing a decoder.", pRecvTable->m_pNetTableName);
    CClientDatatableStack::CClientDatatableStack(
      this: (CClientDatatableStack *)&v28.CDatatableStack::m_pPrecalc,
      pDecoder: (CRecvDecoder *)m_pDecoder,
      pStructBase: pDestEnt,
      objectID);
    CDatatableStack::Init(
      this: (CDatatableStack *)&v28.CDatatableStack::m_pPrecalc,
      bExplicitRoutes: true,
      bLocalNetworkBackDoor: true);
    v13 = 0;
    for ( iChanged = 0; v13 < nChangeOffsets; iChanged = v13 )
    {
      v14 = *((unsigned __int16 *)&v27.m_pProxies[13] + v13);
      ++g_nTotalPropChanges;
      serverStack.m_iCurProp = v14;
      serverStack.m_pCurProp = serverStack.CDatatableStack::m_pPrecalc->m_Props.m_Memory.m_pMemory[v14];
      pSendProp = serverStack.m_pPrecalc->m_Props.m_Memory.m_pMemory[v14];
      v15 = UpdateRoutesExplicit_Template<CServerDatatableStack,CServerDatatableStack::CSendProxyCaller>(pStack: (CSendTablePrecalc::CProxyPath *)&serverStack);
      if ( v15 != nullptr )
      {
        v16 = *(_DWORD *)(pPrecalc[1].m_ProxyPathEntries.m_Memory.m_nAllocationCount + 4 * v14);
        v28.m_pCurProp = (const SendProp *)v14;
        v28.m_ObjectID = *(_DWORD *)(*((_DWORD *)v28.m_pProxies[0] + 11) + 4 * v14);
        v17 = UpdateRoutesExplicit_Template<CClientDatatableStack,CClientDatatableStack::CRecvProxyCaller>(pStack: (CClientDatatableStack *)&v28.CDatatableStack::m_pPrecalc);
        (*(&funcs_101701E0 + 9 * *(_DWORD *)(v16 + 4)))(
          pSendProp,
          pRecvProp: (const RecvProp *)v16,
          pSendData: v15,
          pRecvData: v17,
          objectID);
        v13 = iChanged;
      }
      ++v13;
    }
  }
  else
  {
    v18 = pSendTable->m_pPrecalc;
    pPrecalc = v18;
    if ( v18 == nullptr )
      _Error(a1: "SendTable_Encode: Missing m_pPrecalc for SendTable %s.", pSendTable->m_pNetTableName);
    CDatatableStack::CDatatableStack(this: &v28, pPrecalc: v18, pStructBase: pSrcEnt, objectID);
    v28.__vftable = (CServerDatatableStack_vtbl *)&CServerDatatableStack::`vftable';
    v28.m_pPrecalc = v18;
    v28.m_pRecipients = &recip;
    CDatatableStack::Init(this: &v28, bExplicitRoutes: false, bLocalNetworkBackDoor: true);
    v19 = (char *)pRecvTable->m_pDecoder;
    pSendProp = (const SendProp *)v19;
    if ( v19 == nullptr )
      _Error(a1: "RecvTable_Decode: table '%s' missing a decoder.", pRecvTable->m_pNetTableName);
    CDatatableStack::CDatatableStack(
      this: &v27,
      pPrecalc: (CSendTablePrecalc *)(v19 + 8),
      pStructBase: pDestEnt,
      objectID);
    v27.__vftable = (CClientDatatableStack_vtbl *)&CClientDatatableStack::`vftable';
    v27.m_pDecoder = (CRecvDecoder *)v19;
    CDatatableStack::Init(this: &v27, bExplicitRoutes: false, bLocalNetworkBackDoor: true);
    AddToPartialChangeEntsList(iEnt: (edict_t *)pEdict - sv.edicts, bPartial: false);
    if ( v18->m_FastLocalTransfer.m_OtherProps.m_Size > 0 )
    {
      iChangeda = &v18->m_FastLocalTransfer.m_OtherProps.m_Memory.m_pMemory->m_iProp;
      v20 = v28.CDatatableStack::m_pPrecalc;
      nChangeOffsets = v18->m_FastLocalTransfer.m_OtherProps.m_Size;
      do
      {
        v21 = *iChangeda;
        v28.m_iCurProp = v21;
        v28.m_pCurProp = v20->m_Props.m_Memory.m_pMemory[v21];
        v22 = v28.m_pPrecalc->m_Props.m_Memory.m_pMemory[v21];
        v23 = v28.m_pProxies[v20->m_PropProxyIndices.m_Memory.m_pMemory[v21]];
        if ( v23 != nullptr )
        {
          v24 = *(_DWORD *)(*((_DWORD *)v19 + 72) + 4 * v21);
          v27.m_iCurProp = v21;
          v27.m_pCurProp = v27.m_pPrecalc->m_Props.m_Memory.m_pMemory[v21];
          (*(&funcs_101701E0 + 9 * *(_DWORD *)(v24 + 4)))(
            pSendProp: v22,
            pRecvProp: (const RecvProp *)v24,
            pSendData: v23,
            pRecvData: v27.m_pProxies[v27.m_pPrecalc->m_PropProxyIndices.m_Memory.m_pMemory[v21]],
            objectID);
          v20 = v28.CDatatableStack::m_pPrecalc;
          v19 = (char *)pSendProp;
        }
        iChangeda += 3;
        --nChangeOffsets;
      }
      while ( nChangeOffsets != 0 );
      v18 = pPrecalc;
    }
    LocalTransfer_FastType<int>(
      pBlah: nullptr,
      serverStack: &v28,
      clientStack: &v27,
      pPropList: v18->m_FastLocalTransfer.m_FastInt32.m_Memory.m_pMemory,
      nProps: v18->m_FastLocalTransfer.m_FastInt32.m_Size);
    LocalTransfer_FastType<short>(
      pBlah: nullptr,
      serverStack: &v28,
      clientStack: &v27,
      pPropList: v18->m_FastLocalTransfer.m_FastInt16.m_Memory.m_pMemory,
      nProps: v18->m_FastLocalTransfer.m_FastInt16.m_Size);
    LocalTransfer_FastType<char>(
      pBlah: nullptr,
      serverStack: &v28,
      clientStack: &v27,
      pPropList: v18->m_FastLocalTransfer.m_FastInt8.m_Memory.m_pMemory,
      nProps: v18->m_FastLocalTransfer.m_FastInt8.m_Size);
    LocalTransfer_FastType<Vector>(
      pBlah: nullptr,
      serverStack: &v28,
      clientStack: &v27,
      pPropList: v18->m_FastLocalTransfer.m_FastVector.m_Memory.m_pMemory,
      nProps: v18->m_FastLocalTransfer.m_FastVector.m_Size);
  }
  if ( recip.m_nGrowSize >= 0 && recip.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: recip.m_pMemory);
}

} // namespace engine_xlsp
