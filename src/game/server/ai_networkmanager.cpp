// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_networkmanager.cpp
// Functions: 58
// ============================================================

#include "game\server\ai_networkmanager.h"

//------------------------------------------------------------------------------
// Address: 0x1006BB10
// Name: public: virtual struct datamap_t __near * CAI_NetworkManager::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_NetworkManager::GetDataDescMap(CAI_NetworkManager *this)
{
  return &CAI_NetworkManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1006BB20
// Name: public: void CAI_NetworkManager::MarkDontSaveGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkManager::MarkDontSaveGraph(CAI_NetworkManager *this)
{
  this->m_bDontSaveGraph = true;
}

//------------------------------------------------------------------------------
// Address: 0x1006BB30
// Name: public: static void CAI_NetworkManager::DeleteAllAINetworks(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_NetworkManager::DeleteAllAINetworks()
{
  CAI_DynamicLink::gm_bInitialized = false;
  CAI_NetworkManager::gm_fNetworksLoaded = false;
  g_pBigAINet = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006BB50
// Name: public: void CAI_NetworkManager::FixupHints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkManager::FixupHints(CAI_NetworkManager *this)
{
  CAI_Hint *i; // eax
  AIHintIter_t__ *iter; // [esp+0h] [ebp-4h] BYREF

  iter = (AIHintIter_t__ *)this;
  for ( i = CAI_HintManager::GetFirstHint(pIter: &iter); i != nullptr; i = CAI_HintManager::GetNextHint(pIter: &iter) )
    CAI_Hint::FixupTargetNode(this: i);
}

//------------------------------------------------------------------------------
// Address: 0x1006BB80
// Name: public: int CAI_NetworkEditTools::GetNodeIdFromWCId(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_NetworkEditTools::GetNodeIdFromWCId(CAI_NetworkEditTools *this, int nWCId)
{
  int *m_pNodeIndexTable; // ecx
  int result; // eax
  int m_iNumNodes; // edx

  if ( nWCId == -1 )
    return -1;
  m_pNodeIndexTable = this->m_pNodeIndexTable;
  if ( m_pNodeIndexTable == nullptr )
  {
    DevMsg(a1: "ERROR: Trying to get WC ID with no table!\n");
    return -1;
  }
  m_iNumNodes = this->m_pNetwork->m_iNumNodes;
  if ( m_iNumNodes == 0 )
  {
    DevMsg(a1: "ERROR: Trying to get WC ID with no network!\n");
    return -1;
  }
  result = 0;
  if ( m_iNumNodes <= 0 )
    return -1;
  while ( *m_pNodeIndexTable != nWCId )
  {
    ++result;
    ++m_pNodeIndexTable;
    if ( result >= m_iNumNodes )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006BBF0
// Name: public: int CAI_NetworkEditTools::GetWCIdFromNodeId(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_NetworkEditTools::GetWCIdFromNodeId(CAI_NetworkEditTools *this, int nNodeId)
{
  if ( nNodeId == -1 || nNodeId >= this->m_pNetwork->m_iNumNodes )
    return -1;
  else
    return this->m_pNodeIndexTable[nNodeId];
}

//------------------------------------------------------------------------------
// Address: 0x1006BC20
// Name: class Vector PointOnLineNearestPoint(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__usercall PointOnLineNearestPoint@<eax>(
        float a1@<ebp>,
        Vector *result,
        const Vector *vStartPos,
        const Vector *vEndPos,
        const Vector *vPoint)
{
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  Vector v15; // [esp-Ch] [ebp-1Ch] BYREF
  Vector vEndToStart; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  vEndToStart.y = a1;
  vEndToStart.z = retaddr;
  v5 = vEndPos->z - vStartPos->z;
  v6 = vEndPos->x - vStartPos->x;
  v7 = vPoint->y - vStartPos->y;
  v8 = vPoint->z - vStartPos->z;
  v9 = vPoint->x - vStartPos->x;
  v15.y = vEndPos->y - vStartPos->y;
  v15.x = v6;
  v15.z = v5;
  v10 = fsqrt((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9));
  vEndToStart.x = (float)((float)((float)((float)(v15.y * v7) + (float)(v9 * v6)) + (float)(v8 * v5))
                        / (float)(v10 * fsqrt((float)((float)(v15.y * v15.y) + (float)(v5 * v5)) + (float)(v6 * v6))))
                * v10;
  VectorNormalize(vec: &v15);
  v12 = v15.z * vEndToStart.x;
  v13 = vStartPos->x + (float)(v15.x * vEndToStart.x);
  result->y = vStartPos->y + (float)(v15.y * vEndToStart.x);
  v14 = vStartPos->z + v12;
  result->x = v13;
  result->z = v14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006BD80
// Name: public: void CAI_NetworkEditTools::SetRebuildFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkEditTools::SetRebuildFlags(CAI_NetworkEditTools *this)
{
  this->m_debugNetOverlays = this->m_debugNetOverlays & 0xEFFFFFC3 | 0x10000000;
  CAI_NetworkEditTools::m_bLinkEditMode = false;
}

//------------------------------------------------------------------------------
// Address: 0x1006BDA0
// Name: public: void CAI_NetworkEditTools::ClearRebuildFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkEditTools::ClearRebuildFlags(CAI_NetworkEditTools *this)
{
  CAI_Network *m_pNetwork; // edx
  int v2; // eax
  CAI_Network *v3; // edx
  CAI_Node *v4; // edx
  CAI_Network *v5; // edx
  CAI_Node *v6; // edx

  m_pNetwork = this->m_pNetwork;
  this->m_debugNetOverlays |= 8u;
  v2 = 0;
  if ( m_pNetwork->m_iNumNodes > 0 )
  {
    do
    {
      v3 = this->m_pNetwork;
      if ( v2 < 0 || v2 >= v3->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v4 = nullptr;
      }
      else
      {
        v4 = v3->m_pAInode[v2];
      }
      v4->m_eNodeInfo &= ~0x20000000u;
      v5 = this->m_pNetwork;
      if ( v2 < 0 || v2 >= v5->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v6 = nullptr;
      }
      else
      {
        v6 = v5->m_pAInode[v2];
      }
      v6->m_eNodeInfo &= ~0x10000000u;
      ++v2;
    }
    while ( v2 < this->m_pNetwork->m_iNumNodes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BE10
// Name: public: void CAI_NetworkEditTools::DrawEditInfoOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_NetworkEditTools::DrawEditInfoOverlay(CAI_NetworkEditTools *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  char outTxt2[256]; // [esp+0h] [ebp-2C4h] BYREF
  char outTxt[256]; // [esp+100h] [ebp-1C4h] BYREF
  char hullTypeTxt[52]; // [esp+200h] [ebp-C4h] BYREF
  char editTypeTxt[52]; // [esp+234h] [ebp-90h] BYREF
  char nodeTypeTxt[52]; // [esp+268h] [ebp-5Ch] BYREF
  hudtextparms_s tTextParam; // [esp+29Ch] [ebp-28h] BYREF

  tTextParam.effect = 0;
  tTextParam.channel = 0;
  tTextParam.x = 0.80000001;
  tTextParam.y = 0.80000001;
  *(_DWORD *)&tTextParam.r1 = -1;
  *(_DWORD *)&tTextParam.r2 = -1;
  tTextParam.fadeinTime = 0.0;
  tTextParam.fadeoutTime = 0.0;
  tTextParam.holdTime = 1.0;
  tTextParam.fxTime = 0.0;
  v4 = NAI_Hull::Name(id: CAI_NetworkEditTools::m_iHullDrawNum);
  V_snprintf(pDest: hullTypeTxt, maxLen: 50, pFormat: "  %s", v4);
  V_snprintf(pDest: outTxt, maxLen: 255, pFormat: "Displaying:\n%s\n\n", hullTypeTxt);
  if ( ((int (__thiscall *)(IVEngineServer *, int, int))engine->IsInEditMode)(a1: engine, a2: a3, a3: a2) != 0 )
  {
    v5 = "Links";
    if ( !CAI_NetworkEditTools::m_bLinkEditMode )
      v5 = "Nodes";
    V_snprintf(pDest: nodeTypeTxt, maxLen: 50, pFormat: "  %s (l)", v5);
    v6 = "Air";
    if ( !CAI_NetworkEditTools::m_bAirEditMode )
      v6 = "Ground";
    V_snprintf(pDest: editTypeTxt, maxLen: 50, pFormat: "  %s (m)", v6);
    V_snprintf(pDest: outTxt2, maxLen: 255, pFormat: "Editing:\n%s\n%s", editTypeTxt, nodeTypeTxt);
    V_strncat(pDest: outTxt, pSrc: outTxt2, destBufferSize: 0xFFu, max_chars_to_copy: -1);
    if ( (this->m_debugNetOverlays & 0x10000000) != 0 )
      *(_WORD *)&tTextParam.g1 = 0;
  }
  UTIL_HudMessageAll(textparms: &tTextParam, pMessage: outTxt);
}

//------------------------------------------------------------------------------
// Address: 0x1006BF70
// Name: public: CAI_NetworkEditTools::CAI_NetworkEditTools(class CAI_NetworkManager __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_NetworkEditTools *__thiscall CAI_NetworkEditTools::CAI_NetworkEditTools(
        CAI_NetworkEditTools *this,
        CAI_NetworkManager *pNetworkManager)
{
  int i; // eax
  CAI_Network *m_pNetwork; // edx

  if ( engine->IsInEditMode(this: engine) != 0 )
    this->m_pWCPosition = (Vector *)operator new(nSize: 0x4650u);
  else
    this->m_pWCPosition = nullptr;
  this->m_pNodeIndexTable = nullptr;
  this->m_debugNetOverlays = 0;
  this->m_pNodeIndexTable = (int *)operator new(nSize: 0x1770u);
  for ( i = 0; i < 1500; ++i )
    this->m_pNodeIndexTable[i] = -1;
  this->m_nNextWCIndex = 0;
  m_pNetwork = pNetworkManager->m_pNetwork;
  this->m_pManager = pNetworkManager;
  this->m_pNetwork = m_pNetwork;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006BFF0
// Name: ai_debug_node_connect
// Source: json
//------------------------------------------------------------------------------
void __cdecl ai_debug_node_connect(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // esi

  v1 = locale;
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  g_DebugConnectNode1 = atoi(nptr: v1);
  if ( args->m_nArgc > 2 )
    v2 = args->m_ppArgv[2];
  else
    v2 = locale;
  g_DebugConnectNode2 = atoi(nptr: v2);
  DevMsg(a1: "ai_debug_node_connect: debugging enbabled for %d <--> %d\n", g_DebugConnectNode1, g_DebugConnectNode2);
}

//------------------------------------------------------------------------------
// Address: 0x1006C050
// Name: public: CAI_NetworkManager::CAI_NetworkManager(void)
// Source: json
//------------------------------------------------------------------------------
CAI_NetworkManager *__thiscall CAI_NetworkManager::CAI_NetworkManager(CAI_NetworkManager *this)
{
  CAI_Network *v2; // eax
  CAI_Network *v3; // eax
  CAI_NetworkEditTools *v4; // eax
  CAI_NetworkEditTools *v5; // eax

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CAI_NetworkManager_vtbl *)&CAI_NetworkManager::`vftable';
  CThreadMutex::CThreadMutex(this: &this->m_ThreadedBuild.mutex);
  this->m_ThreadedBuild.pBuildingNetwork = nullptr;
  this->m_ThreadedBuild.nBuildStage.m_value = 0;
  this->m_ThreadedBuild.job = nullptr;
  v2 = (CAI_Network *)operator new(nSize: 0x310u);
  if ( v2 != nullptr )
    v3 = CAI_Network::CAI_Network(this: v2);
  else
    v3 = nullptr;
  this->m_pNetwork = v3;
  v4 = (CAI_NetworkEditTools *)operator new(nSize: 0x18u);
  if ( v4 != nullptr )
    v5 = CAI_NetworkEditTools::CAI_NetworkEditTools(this: v4, pNetworkManager: this);
  else
    v5 = nullptr;
  this->m_pEditOps = v5;
  this->m_bNeedGraphRebuild = false;
  this->m_fInitalized = false;
  CAI_DynamicLink::gm_bInitialized = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006C0F0
// Name: private: static bool CAI_NetworkManager::IsAIFileCurrent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CAI_NetworkManager::IsAIFileCurrent(const char *szMapName)
{
  char szBspFilename[260]; // [esp+0h] [ebp-20Ch] BYREF
  char szGraphFilename[260]; // [esp+104h] [ebp-108h] BYREF
  int iCompare; // [esp+208h] [ebp-4h] BYREF

  if ( g_pGameRules->FAllowNPCs(this: g_pGameRules) )
  {
    V_snprintf(pDest: szBspFilename, maxLen: 260, pFormat: "maps/%s%s.bsp", szMapName, locale);
    V_snprintf(pDest: szGraphFilename, maxLen: 260, pFormat: "maps/graphs/%s%s.ain", szMapName, locale);
    if ( engine->CompareFileTime(this: engine, a2: szBspFilename, a3: szGraphFilename, a4: &iCompare) != 0 )
    {
      if ( iCompare <= 0 )
        return 1;
      if ( g_ai_norebuildgraph.m_pParent != nullptr && g_ai_norebuildgraph.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: szGraphFilename, a3: nullptr) )
        {
          _DevMsg(a1: 2, a2: ".AIN File will *NOT* be updated. User Override.\n\n");
          DevMsg(a1: "\n*****Node Graph Rebuild OVERRIDDEN by user*****\n\n");
        }
        return 1;
      }
      _DevMsg(a1: 2, a2: ".AIN File will be updated\n\n");
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006C1F0
// Name: public: void CAI_NetworkEditTools::RecalcUsableNodesForHull(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkEditTools::RecalcUsableNodesForHull(CAI_NetworkEditTools *this)
{
  CAI_TestHull *TestHull; // ebx
  CAI_Network *m_pNetwork; // eax
  int i; // esi
  CAI_Node *v5; // edx
  char v6; // cl
  CAI_Network *v7; // eax
  CAI_Node *v8; // eax
  CAI_Network *v9; // eax
  CAI_Node *v10; // eax

  TestHull = CAI_TestHull::GetTestHull();
  TestHull->m_pNavigator->m_pAINetwork = g_pBigAINet;
  TestHull->m_eHull = CAI_NetworkEditTools::m_iHullDrawNum;
  CAI_BaseNPC::SetHullSizeNormal(this: TestHull, force: false);
  m_pNetwork = this->m_pNetwork;
  for ( i = 0; i < m_pNetwork->m_iNumNodes; ++i )
  {
    if ( i < 0 || i >= m_pNetwork->m_iNumNodes )
    {
      ++`CAI_Network::GetNode'::`8'::warningCount;
      v5 = nullptr;
    }
    else
    {
      v5 = m_pNetwork->m_pAInode[i];
    }
    v6 = CAI_NetworkEditTools::m_iHullDrawNum;
    if ( CAI_NetworkEditTools::m_iHullDrawNum >= 9 )
      v6 = CAI_NetworkEditTools::m_iHullDrawNum + 1;
    if ( ((32 * (1 << v6)) & v5->m_eNodeInfo) != 0
      || CAI_Navigator::CanFitAtNode(this: TestHull->m_pNavigator, nodeNum: i, collisionMask: 0x2400Bu) )
    {
      v9 = this->m_pNetwork;
      if ( i < 0 || i >= v9->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v10 = nullptr;
      }
      else
      {
        v10 = v9->m_pAInode[i];
      }
      v10->m_eNodeInfo &= ~0x40000000u;
    }
    else
    {
      v7 = this->m_pNetwork;
      if ( i < 0 || i >= v7->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        MEMORY[0x48] |= 0x40000000u;
      }
      else
      {
        v8 = v7->m_pAInode[i];
        v8->m_eNodeInfo |= 0x40000000u;
      }
    }
    m_pNetwork = this->m_pNetwork;
  }
  CAI_TestHull::ReturnTestHull();
}

//------------------------------------------------------------------------------
// Address: 0x1006C3B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C450
// Name: protected: bool CUtlBuffer::GetTypeText<short>(short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<short>(CUtlBuffer *this, __int16 *value, unsigned int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006C4C0
// Name: protected: bool CUtlBuffer::GetTypeText<int>(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<int>(CUtlBuffer *this, int *value, unsigned int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006C530
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006C5A0
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C6A0
// Name: void DebugConnectMsg(int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DebugConnectMsg(int node1, int node2, const char *pszFormat, ...)
{
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+4h] [ebp-10Ch] BYREF

  if ( node1 == g_DebugConnectNode1 && node2 == g_DebugConnectNode2
    || node1 == g_DebugConnectNode2 && node2 == g_DebugConnectNode1 )
  {
    v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, ppszFormat: &pszFormat);
    DevMsg(a1: v3->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C6F0
// Name: public: virtual CAI_NetworkManager::~CAI_NetworkManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkManager::~CAI_NetworkManager(CAI_NetworkManager *this)
{
  CAI_NetworkEditTools *m_pEditOps; // edi
  CAI_Network *m_pNetwork; // edi

  m_pEditOps = this->m_pEditOps;
  this->__vftable = (CAI_NetworkManager_vtbl *)&CAI_NetworkManager::`vftable';
  if ( m_pEditOps != nullptr )
  {
    Editor_EndSession(bShowUI: false);
    free(pMem: m_pEditOps->m_pNodeIndexTable);
    free(pMem: m_pEditOps);
  }
  m_pNetwork = this->m_pNetwork;
  if ( m_pNetwork != nullptr )
  {
    CAI_Network::~CAI_Network(this: this->m_pNetwork);
    free(pMem: m_pNetwork);
  }
  if ( g_pAINetworkManager == this )
    g_pAINetworkManager = nullptr;
  CThreadMutex::~CThreadMutex(this: &this->m_ThreadedBuild.mutex);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006C760
// Name: public: static class CAI_Node __near * CAI_NetworkEditTools::FindAINodeNearestFacing(class Vector const __near &,class Vector const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
CAI_Node *__cdecl CAI_NetworkEditTools::FindAINodeNearestFacing(
        const Vector *origin,
        const Vector *facing,
        float threshold,
        int nNodeType)
{
  CAI_Network *v4; // edi
  int m_iNumNodes; // eax
  int v6; // esi
  CAI_Node *v7; // eax
  CAI_Node *v8; // eax
  CAI_Node *v9; // ecx
  Vector *Position; // eax
  CAI_Node *v11; // ecx
  const Vector *v12; // eax
  CGameTrace tr; // [esp+0h] [ebp-80h] BYREF
  Vector v15; // [esp+54h] [ebp-2Ch] BYREF
  Vector v16; // [esp+60h] [ebp-20h] BYREF
  Vector to_node; // [esp+6Ch] [ebp-14h] BYREF
  float dot; // [esp+78h] [ebp-8h]
  float bestDot; // [esp+7Ch] [ebp-4h]
  IHandleEntity savedregs; // [esp+80h] [ebp+0h] BYREF
  CAI_Node *best; // [esp+90h] [ebp+10h]

  v4 = g_pBigAINet;
  m_iNumNodes = g_pBigAINet->m_iNumNodes;
  v6 = 0;
  bestDot = threshold;
  best = nullptr;
  if ( m_iNumNodes <= 0 )
    return nullptr;
  do
  {
    if ( v6 < 0 || v6 >= m_iNumNodes )
    {
      ++`CAI_Network::GetNode'::`8'::warningCount;
      v7 = nullptr;
    }
    else
    {
      v7 = v4->m_pAInode[v6];
    }
    if ( v7->m_eNodeType != NODE_DELETED )
    {
      if ( nNodeType == 0
        || (v6 < 0 || v6 >= v4->m_iNumNodes
          ? (++`CAI_Network::GetNode'::`8'::warningCount, v8 = nullptr)
          : (v8 = v4->m_pAInode[v6]),
            nNodeType == v8->m_eNodeType) )
      {
        if ( v6 < 0 || v6 >= v4->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v9 = nullptr;
        }
        else
        {
          v9 = v4->m_pAInode[v6];
        }
        Position = CAI_Node::GetPosition(this: v9, result: &v16, hull: CAI_NetworkEditTools::m_iHullDrawNum);
        to_node.x = Position->x - origin->x;
        to_node.y = Position->y - origin->y;
        to_node.z = Position->z - origin->z;
        VectorNormalize(vec: &to_node);
        dot = (float)((float)(facing->y * to_node.y) + (float)(facing->x * to_node.x)) + (float)(facing->z * to_node.z);
        if ( dot > bestDot )
        {
          if ( v6 < 0 || v6 >= v4->m_iNumNodes )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v11 = nullptr;
          }
          else
          {
            v11 = v4->m_pAInode[v6];
          }
          v12 = CAI_Node::GetPosition(this: v11, result: &v15, hull: CAI_NetworkEditTools::m_iHullDrawNum);
          UTIL_TraceLine(
            a1: &savedregs,
            a2: v6,
            vecAbsStart: origin,
            vecAbsEnd: v12,
            mask: 0x4041u,
            ignore: nullptr,
            collisionGroup: 0,
            ptr: &tr);
          if ( tr.fraction == 1.0 )
          {
            bestDot = dot;
            if ( v6 < 0 || v6 >= v4->m_iNumNodes )
            {
              ++`CAI_Network::GetNode'::`8'::warningCount;
              best = nullptr;
            }
            else
            {
              best = v4->m_pAInode[v6];
            }
          }
        }
      }
    }
    m_iNumNodes = v4->m_iNumNodes;
    ++v6;
  }
  while ( v6 < m_iNumNodes );
  return best;
}

//------------------------------------------------------------------------------
// Address: 0x1006C920
// Name: public: static class CAI_Link __near * CAI_NetworkEditTools::FindAILinkNearestFacing(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CAI_Link *__usercall CAI_NetworkEditTools::FindAILinkNearestFacing@<eax>(
        float a1@<ebp>,
        const Vector *vOrigin,
        const Vector *vFacing,
        float threshold)
{
  CAI_Network *v4; // edx
  int m_iNumNodes; // eax
  int v6; // esi
  CAI_Node *v7; // eax
  CAI_Node *v8; // eax
  CAI_Node *v10; // eax
  int v11; // ecx
  CAI_Node *v12; // eax
  CAI_Node *v13; // eax
  CAI_Link *v14; // ecx
  __int16 m_iSrcID; // ax
  int v16; // edi
  CAI_Node *v17; // ecx
  CAI_Node *v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  __int128 v22; // xmm7
  __int128 v23; // xmm7
  __int128 v24; // xmm6
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  __int128 v33; // xmm4
  __int128 v34; // xmm2
  __m128 x_low; // xmm2
  __m128i v36; // xmm0
  double v37; // xmm0_8
  double v38; // st7
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  __int128 v42; // xmm3
  __int128 v43; // xmm3
  float v44; // xmm1_4
  float v45; // xmm2_4
  int v46; // [esp-Ch] [ebp-114h] BYREF
  _BYTE tr_32[60]; // [esp+20h] [ebp-E8h] OVERLAPPED
  __int128 v48; // [esp+5Ch] [ebp-ACh]
  Vector v49; // [esp+6Ch] [ebp-9Ch] BYREF
  Vector vIntersection; // [esp+78h] [ebp-90h]
  float fLineLen; // [esp+84h] [ebp-84h]
  CAI_Link *fIntersectDist; // [esp+88h] [ebp-80h]
  float v53; // [esp+8Ch] [ebp-7Ch]
  float lookDot; // [esp+90h] [ebp-78h]
  CAI_Link *nodeLink; // [esp+94h] [ebp-74h]
  Vector vNearest; // [esp+98h] [ebp-70h] BYREF
  Vector dir; // [esp+A4h] [ebp-64h] BYREF
  Vector toLink; // [esp+B0h] [ebp-58h] BYREF
  __int128 v59; // [esp+BCh] [ebp-4Ch]
  float v60; // [esp+D4h] [ebp-34h]
  float v61; // [esp+D8h] [ebp-30h]
  CAI_Network *v62; // [esp+DCh] [ebp-2Ch]
  CAI_Link *best; // [esp+E0h] [ebp-28h] BYREF
  float bestDot; // [esp+E4h] [ebp-24h]
  CAI_Network *aiNet; // [esp+E8h] [ebp-20h]
  Vector endPos; // [esp+ECh] [ebp-1Ch] BYREF
  int link; // [esp+F8h] [ebp-10h]
  Vector startPos; // [esp+FCh] [ebp-Ch] BYREF
  float retaddr; // [esp+108h] [ebp+0h]

  startPos.x = a1;
  startPos.y = retaddr;
  v4 = g_pBigAINet;
  m_iNumNodes = g_pBigAINet->m_iNumNodes;
  v6 = 0;
  v61 = threshold;
  v60 = 0.0;
  v62 = g_pBigAINet;
  if ( m_iNumNodes > 0 )
  {
    while ( 1 )
    {
      if ( v6 < 0 || v6 >= m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v7 = nullptr;
      }
      else
      {
        v7 = v4->m_pAInode[v6];
      }
      if ( v7->m_eNodeType != NODE_DELETED )
      {
        if ( CAI_NetworkEditTools::m_bAirEditMode )
        {
          if ( v6 < 0 || v6 >= v4->m_iNumNodes )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v8 = nullptr;
          }
          else
          {
            v8 = v4->m_pAInode[v6];
          }
          if ( v8->m_eNodeType == NODE_AIR )
            goto LABEL_20;
        }
        else
        {
          if ( v6 < 0 || v6 >= v4->m_iNumNodes )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v10 = nullptr;
          }
          else
          {
            v10 = v4->m_pAInode[v6];
          }
          if ( v10->m_eNodeType == NODE_GROUND )
          {
LABEL_20:
            v11 = 0;
            endPos.x = 0.0;
            while ( 1 )
            {
              if ( v6 < 0 || v6 >= v4->m_iNumNodes )
              {
                ++`CAI_Network::GetNode'::`8'::warningCount;
                v12 = nullptr;
              }
              else
              {
                v12 = v4->m_pAInode[v6];
              }
              if ( v11 >= v12->m_Links.m_Size )
                break;
              if ( v6 < 0 || v6 >= v4->m_iNumNodes )
              {
                ++`CAI_Network::GetNode'::`8'::warningCount;
                v13 = nullptr;
              }
              else
              {
                v13 = v4->m_pAInode[v6];
              }
              v14 = v13->m_Links.m_Memory.m_pMemory[v11];
              m_iSrcID = v14->m_iSrcID;
              fIntersectDist = v14;
              if ( v6 == m_iSrcID )
                m_iSrcID = v14->m_iDestID;
              v16 = m_iSrcID;
              if ( v6 < 0 || v6 >= v4->m_iNumNodes )
              {
                ++`CAI_Network::GetNode'::`8'::warningCount;
                v17 = nullptr;
              }
              else
              {
                v17 = v4->m_pAInode[v6];
              }
              CAI_Node::GetPosition(this: v17, result: (Vector *)&endPos.y, hull: CAI_NetworkEditTools::m_iHullDrawNum);
              if ( v16 < 0 || v16 >= v62->m_iNumNodes )
              {
                ++`CAI_Network::GetNode'::`8'::warningCount;
                v18 = nullptr;
              }
              else
              {
                v18 = v62->m_pAInode[v16];
              }
              CAI_Node::GetPosition(this: v18, result: (Vector *)&best, hull: CAI_NetworkEditTools::m_iHullDrawNum);
              v19 = vOrigin->y - endPos.z;
              v20 = vOrigin->z - *(float *)&link;
              v21 = vOrigin->x - endPos.y;
              v22 = 0;
              toLink.x = *(float *)&best - endPos.y;
              toLink.y = bestDot - endPos.z;
              toLink.z = *(float *)&aiNet - *(float *)&link;
              *(float *)&v22 = fsqrt(
                                 (float)((float)(toLink.y * toLink.y) + (float)(toLink.z * toLink.z))
                               + (float)(toLink.x * toLink.x));
              v48 = v22;
              v23 = 0;
              *(float *)&v23 = (float)((float)(v19 * v19) + (float)(v20 * v20)) + (float)(v21 * v21);
              v24 = v23;
              *(float *)&v24 = fsqrt(*(float *)&v23);
              *(_OWORD *)&tr_32[44] = v24;
              v59 = v24;
              vIntersection.z = (float)((float)((float)((float)(v19 * (float)(bestDot - endPos.z))
                                                      + (float)(v21 * (float)(*(float *)&best - endPos.y)))
                                              + (float)(v20 * (float)(*(float *)&aiNet - *(float *)&link)))
                                      / (float)(*(float *)&v24 * *(float *)&v48))
                              * *(float *)&v24;
              VectorNormalize(vec: &toLink);
              v53 = (float)(toLink.x * vIntersection.z) + endPos.y;
              v25 = v53 - vOrigin->x;
              lookDot = (float)(vIntersection.z * toLink.y) + endPos.z;
              v26 = lookDot - vOrigin->y;
              *(float *)&nodeLink = (float)(toLink.z * vIntersection.z) + *(float *)&link;
              v27 = *(float *)&nodeLink - vOrigin->z;
              v28 = v26 * v26;
              v29 = v26 * vFacing->y;
              v30 = v27 * v27;
              v31 = v27 * vFacing->z;
              v32 = (float)(v28 + v30) + (float)(v25 * v25);
              v33 = 0;
              *(float *)&v33 = v32;
              v34 = v33;
              *(float *)&v34 = fsqrt(*(float *)&v33);
              v48 = v34;
              v59 = v34;
              x_low = (__m128)LODWORD(vFacing->x);
              x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] * v25) + v29) + v31) / *(float *)&v59;
              v36 = (__m128i)_mm_cvtps_pd(x_low);
              __libm_sse2_acos();
              *(float *)v36.m128i_i32 = *(double *)v36.m128i_i64;
              if ( *(float *)v36.m128i_i32 <= 1.57 )
              {
                v59 = v48;
                *(double *)v36.m128i_i64 = *(float *)v36.m128i_i32;
                __libm_sse2_tan(X: v36);
                *(float *)&v37 = v37;
                vIntersection.y = *(float *)&v37 * *(float *)&v59;
                vNearest.x = *(float *)&best - endPos.y;
                vNearest.y = bestDot - endPos.z;
                vNearest.z = *(float *)&aiNet - *(float *)&link;
                v38 = VectorNormalize(vec: &vNearest);
                vIntersection.x = v38;
                v39 = (float)(vNearest.y * vIntersection.y) + lookDot;
                v40 = (float)(vNearest.z * vIntersection.y) + *(float *)&nodeLink;
                v41 = (float)(vNearest.x * vIntersection.y) + v53;
                v42 = 0;
                *(float *)&v42 = fsqrt(
                                   (float)((float)((float)(v39 - endPos.z) * (float)(v39 - endPos.z))
                                         + (float)((float)(v40 - *(float *)&link) * (float)(v40 - *(float *)&link)))
                                 + (float)((float)(v41 - endPos.y) * (float)(v41 - endPos.y)));
                v59 = v42;
                v49.x = v41;
                v49.y = v39;
                v49.z = v40;
                if ( *(float *)&v42 <= v38 )
                {
                  v43 = 0;
                  *(float *)&v43 = fsqrt(
                                     (float)((float)((float)(v39 - bestDot) * (float)(v39 - bestDot))
                                           + (float)((float)(v40 - *(float *)&aiNet) * (float)(v40 - *(float *)&aiNet)))
                                   + (float)((float)(v41 - *(float *)&best) * (float)(v41 - *(float *)&best)));
                  v59 = v43;
                  if ( *(float *)&v43 <= vIntersection.x )
                  {
                    v44 = v39 - vOrigin->y;
                    v45 = v40 - vOrigin->z;
                    dir.x = v41 - vOrigin->x;
                    dir.y = v44;
                    dir.z = v45;
                    VectorNormalize(vec: &dir);
                    fLineLen = (float)((float)(dir.x * vFacing->x) + (float)(dir.y * vFacing->y))
                             + (float)(dir.z * vFacing->z);
                    if ( fLineLen > v61 )
                    {
                      UTIL_TraceLine(
                        a1: (const IHandleEntity *)&startPos,
                        a2: v6,
                        vecAbsStart: vOrigin,
                        vecAbsEnd: &v49,
                        mask: 0x4041u,
                        ignore: nullptr,
                        collisionGroup: 0,
                        ptr: (CGameTrace *)&v46);
                      if ( *(float *)tr_32 == 1.0 )
                      {
                        v61 = fLineLen;
                        v60 = *(float *)&fIntersectDist;
                      }
                    }
                  }
                }
              }
              v11 = ++LODWORD(endPos.x);
              v4 = v62;
            }
          }
        }
      }
      m_iNumNodes = v4->m_iNumNodes;
      if ( ++v6 >= m_iNumNodes )
        return (CAI_Link *)LODWORD(v60);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006CE60
// Name: private: void CAI_NetworkBuilder::FloodFillZone(class CAI_Node __near * __near *,class CAI_Node __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkBuilder::FloodFillZone(
        CAI_NetworkBuilder *this,
        CAI_Node **ppNodes,
        CAI_Node *pNode,
        int zone)
{
  int v4; // edi
  CAI_Link *v5; // eax
  int m_iDestID; // ecx
  CAI_Node *v7; // eax

  v4 = 0;
  for ( pNode->m_zone = zone; v4 < pNode->m_Links.m_Size; ++v4 )
  {
    v5 = pNode->m_Links.m_Memory.m_pMemory[v4];
    m_iDestID = v5->m_iDestID;
    if ( m_iDestID == pNode->m_iID )
      v7 = ppNodes[v5->m_iSrcID];
    else
      v7 = ppNodes[m_iDestID];
    if ( v7->m_zone == 0 )
      CAI_NetworkBuilder::FloodFillZone(this, ppNodes, pNode: v7, zone);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CEC0
// Name: public: void CAI_NetworkBuilder::InitZones(class CAI_Network __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkBuilder::InitZones(CAI_NetworkBuilder *this, CAI_Network *pNetwork)
{
  int m_iNumNodes; // ebx
  CAI_Node **m_pAInode; // edi
  int j; // eax
  CAI_Node *v5; // ecx
  int k; // eax
  CAI_Node *v7; // ecx
  int v8; // eax
  int v9; // edx
  CAI_Node *v10; // esi
  int v11; // ebx
  CAI_Link *v12; // eax
  int m_iDestID; // ecx
  CAI_Node *v14; // eax
  int nNodes; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]
  int curZone; // [esp+20h] [ebp+8h]

  m_iNumNodes = pNetwork->m_iNumNodes;
  m_pAInode = pNetwork->m_pAInode;
  nNodes = m_iNumNodes;
  if ( m_iNumNodes != 0 )
  {
    for ( j = 0; j < m_iNumNodes; v5->m_zone = 0 )
      v5 = m_pAInode[j++];
    for ( k = 0; k < m_iNumNodes; ++k )
    {
      v7 = m_pAInode[k];
      if ( v7->m_Links.m_Size == 0 )
        v7->m_zone = 1;
    }
    v8 = 0;
    v9 = 4;
    curZone = 4;
    for ( i = 0; v8 < m_iNumNodes; i = v8 )
    {
      v10 = m_pAInode[v8];
      if ( v10->m_zone == 0 )
      {
        v11 = 0;
        v10->m_zone = v9;
        if ( v10->m_Links.m_Size > 0 )
        {
          do
          {
            v12 = v10->m_Links.m_Memory.m_pMemory[v11];
            m_iDestID = v12->m_iDestID;
            if ( m_iDestID == v10->m_iID )
              m_iDestID = v12->m_iSrcID;
            v14 = m_pAInode[m_iDestID];
            if ( v14->m_zone == 0 )
            {
              CAI_NetworkBuilder::FloodFillZone(this, ppNodes: m_pAInode, pNode: v14, zone: v9);
              v9 = curZone;
            }
            ++v11;
          }
          while ( v11 < v10->m_Links.m_Size );
          v8 = i;
        }
        m_iNumNodes = nNodes;
        curZone = ++v9;
      }
      ++v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CF90
// Name: private: void CAI_NetworkBuilder::ForceDynamicLinkNeighbors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkBuilder::ForceDynamicLinkNeighbors(CAI_NetworkBuilder *this)
{
  CAI_DynamicLink *v1; // edi
  int m_nSrcEditID; // esi
  CAI_NetworkEditTools *m_pEditOps; // eax
  int v4; // ebx
  int *m_pNodeIndexTable; // ecx
  int m_iNumNodes; // edx
  int v7; // eax
  int m_nDestEditID; // esi
  CAI_NetworkEditTools *v9; // eax
  int v10; // edi
  int *v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // eax
  CAI_Node *v15; // esi
  CAI_Node *v16; // edx
  unsigned int *v17; // eax
  unsigned int *v18; // eax
  CAI_DynamicLink *pDynamicLink; // [esp+4h] [ebp-4h]

  if ( g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable == nullptr )
  {
    DevMsg(a1: "ERROR: Trying initialize links with no WC ID table!\n");
    return;
  }
  v1 = CAI_DynamicLink::m_pAllDynamicLinks;
  pDynamicLink = CAI_DynamicLink::m_pAllDynamicLinks;
  if ( CAI_DynamicLink::m_pAllDynamicLinks != nullptr )
  {
    while ( 1 )
    {
      m_nSrcEditID = v1->m_nSrcEditID;
      m_pEditOps = g_pAINetworkManager->m_pEditOps;
      if ( m_nSrcEditID == -1 )
        break;
      m_pNodeIndexTable = m_pEditOps->m_pNodeIndexTable;
      if ( m_pNodeIndexTable == nullptr )
      {
        DevMsg(a1: "ERROR: Trying to get WC ID with no table!\n");
        v4 = -1;
        goto LABEL_17;
      }
      m_iNumNodes = m_pEditOps->m_pNetwork->m_iNumNodes;
      if ( m_iNumNodes == 0 )
      {
        DevMsg(a1: "ERROR: Trying to get WC ID with no network!\n");
        v4 = -1;
        goto LABEL_17;
      }
      v7 = 0;
      if ( m_iNumNodes <= 0 )
        break;
      while ( *m_pNodeIndexTable != m_nSrcEditID )
      {
        ++v7;
        ++m_pNodeIndexTable;
        if ( v7 >= m_iNumNodes )
        {
          v4 = -1;
          goto LABEL_17;
        }
      }
      v4 = v7;
      if ( v7 == -1 )
        goto LABEL_17;
LABEL_18:
      m_nDestEditID = v1->m_nDestEditID;
      v9 = g_pAINetworkManager->m_pEditOps;
      if ( m_nDestEditID == -1 )
        goto LABEL_19;
      v11 = v9->m_pNodeIndexTable;
      if ( v11 == nullptr )
      {
        DevMsg(a1: "ERROR: Trying to get WC ID with no table!\n");
        v10 = -1;
        goto LABEL_29;
      }
      v12 = v9->m_pNetwork->m_iNumNodes;
      if ( v12 == 0 )
      {
        DevMsg(a1: "ERROR: Trying to get WC ID with no network!\n");
        v10 = -1;
        goto LABEL_29;
      }
      v13 = 0;
      if ( v12 <= 0 )
      {
LABEL_19:
        v10 = -1;
LABEL_29:
        DevMsg(a1: "ERROR: Dynamic link dest WC node %d not found\n", pDynamicLink->m_nDestEditID);
        goto LABEL_30;
      }
      while ( *v11 != m_nDestEditID )
      {
        ++v13;
        ++v11;
        if ( v13 >= v12 )
        {
          v10 = -1;
          goto LABEL_29;
        }
      }
      v10 = v13;
      if ( v13 == -1 )
        goto LABEL_29;
LABEL_30:
      if ( v4 != -1 && v10 != -1 )
      {
        v14 = g_pBigAINet->m_iNumNodes;
        if ( v4 < v14 && v10 < v14 )
        {
          if ( v4 < 0 )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v15 = nullptr;
          }
          else
          {
            v15 = g_pBigAINet->m_pAInode[v4];
          }
          if ( v10 < 0 || v10 >= g_pBigAINet->m_iNumNodes )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v16 = nullptr;
          }
          else
          {
            v16 = g_pBigAINet->m_pAInode[v10];
          }
          v17 = &this->m_NeighborsTable.m_Memory.m_pMemory[v15->m_iID].m_pInt[v16->m_iID >> 5];
          *v17 |= 1 << (v16->m_iID & 0x1F);
          v18 = &this->m_NeighborsTable.m_Memory.m_pMemory[v16->m_iID].m_pInt[v15->m_iID >> 5];
          *v18 |= 1 << (v15->m_iID & 0x1F);
        }
      }
      pDynamicLink = pDynamicLink->m_pNextDynamicLink;
      if ( pDynamicLink == nullptr )
        return;
      v1 = pDynamicLink;
    }
    v4 = -1;
LABEL_17:
    DevMsg(a1: "ERROR: Dynamic link source WC node %d not found\n", v1->m_nSrcEditID);
    goto LABEL_18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D1B0
// Name: private: void CAI_NetworkBuilder::InitGroundNodePosition(class CAI_Network __near *,class CAI_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAI_NetworkBuilder::InitGroundNodePosition(
        CAI_NetworkBuilder *this@<ecx>,
        float a2@<ebp>,
        CAI_Network *pNetwork,
        CAI_Node *pNode)
{
  int v4; // esi
  float z; // ecx
  const Vector *v6; // eax
  float x; // xmm3_4
  float y; // xmm7_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  Vector v13; // [esp+1Ch] [ebp-E4h] BYREF
  CGameTrace tr; // [esp+28h] [ebp-D8h] BYREF
  float v15[4]; // [esp+84h] [ebp-7Ch] BYREF
  float v16; // [esp+94h] [ebp-6Ch]
  float v17; // [esp+98h] [ebp-68h]
  float v18; // [esp+9Ch] [ebp-64h]
  float v19; // [esp+A4h] [ebp-5Ch]
  float v20; // [esp+A8h] [ebp-58h]
  float v21; // [esp+ACh] [ebp-54h]
  float v22; // [esp+B4h] [ebp-4Ch]
  float v23; // [esp+B8h] [ebp-48h]
  float v24; // [esp+BCh] [ebp-44h]
  int v25; // [esp+C4h] [ebp-3Ch]
  bool v26; // [esp+C8h] [ebp-38h]
  bool v27; // [esp+C9h] [ebp-37h]
  __int64 v28; // [esp+D8h] [ebp-28h]
  float v29; // [esp+E0h] [ebp-20h]
  Vector origin; // [esp+E4h] [ebp-1Ch]
  Vector mins; // [esp+F0h] [ebp-10h]
  float retaddr; // [esp+100h] [ebp+0h]

  mins.y = a2;
  mins.z = retaddr;
  if ( (pNode->m_eNodeInfo & 0x8000000) == 0 )
  {
    v4 = 0;
    LODWORD(mins.x) = pNode->m_flVOffset;
    do
    {
      z = pNode->m_vOrigin.z;
      v28 = *(_QWORD *)&pNode->m_vOrigin.x;
      v29 = z;
      origin = *NAI_Hull::Mins(id: v4);
      v6 = NAI_Hull::Maxs(id: v4);
      x = v6->x;
      y = v6->y;
      v9 = v29 + 0.1;
      v10 = v9 - origin.z;
      v17 = *((float *)&v28 + 1) - *((float *)&v28 + 1);
      v16 = *(float *)&v28 - *(float *)&v28;
      v18 = (float)(v10 - 384.0) - v10;
      v25 = 0;
      v27 = (float)((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v18 * v18)) != 0.0;
      v23 = (float)(y - origin.y) * 0.5;
      v22 = (float)(x - origin.x) * 0.5;
      v24 = 0.0 * 0.5;
      v26 = (float)((float)((float)(v23 * v23) + (float)(v22 * v22)) + (float)(v24 * v24)) < 0.000001;
      v11 = (float)(origin.z * 2.0) * 0.5;
      v12 = (float)(x + origin.x) * 0.5;
      v15[0] = v12 + *(float *)&v28;
      v15[1] = (float)((float)(origin.y + y) * 0.5) + *((float *)&v28 + 1);
      v15[2] = v11 + v10;
      v19 = v12 * -1.0;
      v20 = (float)((float)(origin.y + y) * 0.5) * -1.0;
      v21 = v11 * -1.0;
      CTraceFilterSimple::CTraceFilterSimple(
        this: (CTraceFilterSimple *)&tr.m_pEnt,
        passedict: nullptr,
        collisionGroup: 0,
        pExtraShouldHitFunc: nullptr);
      enginetrace->TraceRay(
        this: enginetrace,
        a2: (const Ray_t *)v15,
        a3: 147467u,
        a4: (ITraceFilter *)&tr.m_pEnt,
        a5: (CGameTrace *)&v13);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v13, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
      if ( tr.plane.pad[1] != 0 )
        *(float *)LODWORD(mins.x) = 0.1 - origin.z;
      else
        *(float *)LODWORD(mins.x) = (float)(tr.startpos.z - pNode->m_vOrigin.z) + 0.1;
      LODWORD(mins.x) += 4;
      ++v4;
    }
    while ( v4 < 12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D450
// Name: private: void CAI_NetworkBuilder::InitVisibility(class CAI_Network __near *,class CAI_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkBuilder::InitVisibility(CAI_NetworkBuilder *this, CAI_Network *pNetwork, CAI_Node *pNode)
{
  CAI_Node *v3; // edi
  bool v4; // zf
  CAI_Network *v5; // ecx
  int m_iNumNodes; // eax
  int v7; // ebx
  int v8; // esi
  int m_iID; // edx
  int v10; // esi
  unsigned int *v11; // eax
  float x; // xmm1_4
  float v13; // xmm0_4
  double v14; // xmm0_8
  CFmtStrN<256> *v15; // eax
  int v16; // eax
  unsigned int *v17; // edx
  float v18; // xmm0_4
  bool v19; // cc
  CAI_Node *v20; // ecx
  double v21; // [esp+8h] [ebp-1D0h]
  double v22; // [esp+10h] [ebp-1C8h]
  CFmtStrN<256> v23; // [esp+24h] [ebp-1B4h] BYREF
  CGameTrace tr; // [esp+130h] [ebp-A8h] BYREF
  Vector v25; // [esp+184h] [ebp-54h] BYREF
  Vector vecAbsStart; // [esp+190h] [ebp-48h] BYREF
  Vector v27; // [esp+19Ch] [ebp-3Ch] BYREF
  Vector vecAbsEnd; // [esp+1A8h] [ebp-30h] BYREF
  Vector destPos; // [esp+1B8h] [ebp-20h] BYREF
  Vector srcPos; // [esp+1C4h] [ebp-14h] BYREF
  CAI_NetworkBuilder *v31; // [esp+1D0h] [ebp-8h]
  int testnode; // [esp+1D4h] [ebp-4h]
  IHandleEntity savedregs; // [esp+1D8h] [ebp+0h] BYREF

  v3 = pNode;
  v4 = pNode->m_eNodeType == NODE_DELETED;
  v31 = this;
  if ( !v4 )
  {
    CAI_Node::GetPosition(this: pNode, result: &srcPos, hull: 1);
    v5 = pNetwork;
    m_iNumNodes = pNetwork->m_iNumNodes;
    v7 = 0;
    testnode = 0;
    if ( m_iNumNodes > 0 )
    {
      while ( 1 )
      {
        if ( v7 < 0 || v7 >= m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v8 = 0;
        }
        else
        {
          v8 = (int)v5->m_pAInode[v7];
        }
        if ( v3->m_iID == g_DebugConnectNode1 && v7 == g_DebugConnectNode2
          || v3->m_iID == g_DebugConnectNode2 && v7 == g_DebugConnectNode1 )
        {
          DevMsg(a1: locale);
        }
        m_iID = v3->m_iID;
        if ( v3->m_iID == v7 )
          break;
        x = v3->m_vOrigin.x;
        v13 = *(float *)(v8 + 4);
        if ( x == v13
          && v3->m_vOrigin.y == *(float *)(v8 + 8)
          && v3->m_vOrigin.z == *(float *)(v8 + 12)
          && *(_DWORD *)(v8 + 68) != 4 )
        {
          v22 = *(float *)(v8 + 12);
          v21 = *(float *)(v8 + 8);
          v14 = *(float *)(v8 + 4);
          *(_DWORD *)(v8 + 68) = 1;
          v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v23, pszFormat: "(%f, %f, %f)", v14, v21, v22);
          _DevMsg(a1: 2, a2: "Probable duplicate node placed at %s\n", v15->m_szBuf);
        }
        else if ( *(_DWORD *)(v8 + 68) != 1 )
        {
          if ( ((1 << (*(_BYTE *)v8 & 0x1F)) & v31->m_DidSetNeighborsTable.m_pInt[*(int *)v8 >> 5]) != 0 )
          {
            v16 = *(_DWORD *)v8;
            v7 = testnode;
            v3 = pNode;
            if ( ((1 << (m_iID & 0x1F)) & v31->m_NeighborsTable.m_Memory.m_pMemory[*(_DWORD *)v8].m_pInt[m_iID >> 5]) != 0 )
            {
              v17 = &v31->m_NeighborsTable.m_Memory.m_pMemory[m_iID].m_pInt[v16 >> 5];
              *v17 |= 1 << (v16 & 0x1F);
            }
            goto LABEL_41;
          }
          v3 = pNode;
          v18 = (float)((float)((float)(*(float *)(v8 + 8) - pNode->m_vOrigin.y)
                              * (float)(*(float *)(v8 + 8) - pNode->m_vOrigin.y))
                      + (float)((float)(v13 - x) * (float)(v13 - x)))
              + (float)((float)(*(float *)(v8 + 12) - pNode->m_vOrigin.z)
                      * (float)(*(float *)(v8 + 12) - pNode->m_vOrigin.z));
          if ( *(_DWORD *)(v8 + 68) == 3 )
            v19 = v18 <= 2073600.0;
          else
            v19 = v18 <= 518400.0;
          v7 = testnode;
          if ( !v19 )
            goto LABEL_41;
          if ( testnode < 0 || testnode >= pNetwork->m_iNumNodes )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v20 = nullptr;
          }
          else
          {
            v20 = pNetwork->m_pAInode[testnode];
          }
          CAI_Node::GetPosition(this: v20, result: &destPos, hull: 1);
          tr.m_pEnt = nullptr;
          UTIL_TraceLine(
            a1: &savedregs,
            a2: v8,
            vecAbsStart: &srcPos,
            vecAbsEnd: &destPos,
            mask: 0x20003u,
            ignore: nullptr,
            collisionGroup: 0,
            ptr: &tr);
          if ( tr.startsolid || tr.fraction != 1.0 )
          {
            vecAbsEnd.x = destPos.x;
            vecAbsEnd.y = destPos.y;
            vecAbsEnd.z = destPos.z + 70.0;
            vecAbsStart.x = srcPos.x;
            vecAbsStart.y = srcPos.y;
            vecAbsStart.z = srcPos.z + 70.0;
            UTIL_TraceLine(
              a1: &savedregs,
              a2: v8,
              &vecAbsStart,
              &vecAbsEnd,
              mask: 0x20003u,
              ignore: nullptr,
              collisionGroup: 0,
              ptr: &tr);
            if ( tr.startsolid || tr.fraction != 1.0 )
            {
              v25.x = srcPos.x;
              v25.y = srcPos.y;
              v25.z = srcPos.z + 70.0;
              UTIL_TraceLine(
                a1: &savedregs,
                a2: v8,
                vecAbsStart: &v25,
                vecAbsEnd: &destPos,
                mask: 0x20003u,
                ignore: nullptr,
                collisionGroup: 0,
                ptr: &tr);
              if ( tr.startsolid || tr.fraction != 1.0 )
              {
                v27.x = destPos.x;
                v27.y = destPos.y;
                v27.z = destPos.z + 70.0;
                UTIL_TraceLine(
                  a1: &savedregs,
                  a2: v8,
                  vecAbsStart: &srcPos,
                  vecAbsEnd: &v27,
                  mask: 0x20003u,
                  ignore: nullptr,
                  collisionGroup: 0,
                  ptr: &tr);
                if ( tr.startsolid || tr.fraction != 1.0 )
                  goto LABEL_41;
              }
            }
          }
          v10 = *(_DWORD *)v8;
          v11 = &v31->m_NeighborsTable.m_Memory.m_pMemory[pNode->m_iID].m_pInt[v10 >> 5];
          goto LABEL_40;
        }
LABEL_41:
        v5 = pNetwork;
        m_iNumNodes = pNetwork->m_iNumNodes;
        testnode = ++v7;
        if ( v7 >= m_iNumNodes )
          return;
      }
      v10 = *(_DWORD *)v8;
      v11 = &v31->m_NeighborsTable.m_Memory.m_pMemory[m_iID].m_pInt[v10 >> 5];
LABEL_40:
      *v11 |= 1 << (v10 & 0x1F);
      goto LABEL_41;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D850
// Name: private: void CAI_NetworkBuilder::InitNeighbors(class CAI_Network __near *,class CAI_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkBuilder::InitNeighbors(CAI_NetworkBuilder *this, CAI_Network *pNetwork, CAI_Node *pNode)
{
  CAI_NetworkBuilder *v4; // ebx
  CVarBitVec *v5; // eax
  int m_pInt; // ecx
  int v7; // edi
  int m_iID; // eax
  unsigned int *v9; // eax
  unsigned int *v10; // eax
  int v11; // ebx
  unsigned int *v12; // ecx
  CAI_Node *v13; // edi
  NodeType_e m_eNodeType; // ecx
  float x; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  CAI_Hint *m_pHint; // eax
  CAI_Hint *v19; // eax
  char v20; // cl
  CAI_Hint *v21; // eax
  char v22; // al
  int v23; // eax
  unsigned int *v24; // eax
  int v25; // ecx
  int v26; // esi
  unsigned int *v27; // eax
  Vector vec2DirToCheckNode; // [esp+Ch] [ebp-38h] BYREF
  Vector vec2DirToTestNode; // [esp+18h] [ebp-2Ch] BYREF
  int v30; // [esp+24h] [ebp-20h]
  int v31; // [esp+28h] [ebp-1Ch]
  int v32; // [esp+2Ch] [ebp-18h]
  int v33; // [esp+30h] [ebp-14h]
  float flDistToTestNode; // [esp+34h] [ebp-10h]
  CAI_Node *pCheckNode; // [esp+38h] [ebp-Ch]
  CAI_NetworkBuilder *v36; // [esp+3Ch] [ebp-8h]
  int checknode; // [esp+40h] [ebp-4h]
  float flDistToCheckNode; // [esp+50h] [ebp+Ch]
  char flDistToCheckNode_3; // [esp+53h] [ebp+Fh]

  v4 = this;
  v5 = &this->m_NeighborsTable.m_Memory.m_pMemory[pNode->m_iID];
  m_pInt = (int)v5->m_pInt;
  v36 = v4;
  if ( m_pInt != 0 )
    memset(dst: m_pInt, value: nullptr, count: 4 * v5->m_numInts);
  CAI_NetworkBuilder::InitVisibility(this: v4, pNetwork, pNode);
  v7 = 0;
  checknode = 0;
  if ( pNetwork->m_iNumNodes > 0 )
  {
    while ( 1 )
    {
      if ( pNode->m_iID == g_DebugConnectNode1 && v7 == g_DebugConnectNode2
        || pNode->m_iID == g_DebugConnectNode2 && v7 == g_DebugConnectNode1 )
      {
        DevMsg(a1: locale);
      }
      m_iID = pNode->m_iID;
      if ( pNode->m_iID != v7 )
        break;
      v9 = &v4->m_NeighborsTable.m_Memory.m_pMemory[m_iID].m_pInt[v7 >> 5];
      *v9 &= ~(1 << (v7 & 0x1F));
LABEL_67:
      checknode = ++v7;
      if ( v7 >= pNetwork->m_iNumNodes )
        goto LABEL_68;
    }
    v10 = v36->m_NeighborsTable.m_Memory.m_pMemory[m_iID].m_pInt;
    v33 = 4 * (v7 >> 5);
    v32 = 1 << (v7 & 0x1F);
    if ( (v32 & v10[v33 / 4u]) == 0
      || ((v11 = 0, v7 < 0) || v7 >= pNetwork->m_iNumNodes
        ? (++`CAI_Network::GetNode'::`8'::warningCount, pCheckNode = nullptr)
        : (pCheckNode = pNetwork->m_pAInode[v7]),
          pNetwork->m_iNumNodes <= 0) )
    {
LABEL_66:
      v4 = v36;
      goto LABEL_67;
    }
    while ( 1 )
    {
      if ( v11 == v7 || v11 == pNode->m_iID )
        goto LABEL_65;
      v12 = v36->m_NeighborsTable.m_Memory.m_pMemory[pNode->m_iID].m_pInt;
      v31 = 4 * (v11 >> 5);
      v30 = 1 << (v11 & 0x1F);
      if ( (v30 & v12[v31 / 4u]) != 0 )
      {
        if ( v11 < 0 || v11 >= pNetwork->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v13 = nullptr;
        }
        else
        {
          v13 = pNetwork->m_pAInode[v11];
        }
        if ( pCheckNode->m_eNodeType == NODE_AIR )
        {
          if ( v13->m_eNodeType == NODE_AIR )
            goto LABEL_28;
        }
        else if ( v13->m_eNodeType != NODE_AIR )
        {
LABEL_28:
          m_eNodeType = pNode->m_eNodeType;
          if ( m_eNodeType != NODE_CLIMB || pCheckNode->m_eNodeType != NODE_CLIMB && v13->m_eNodeType != NODE_CLIMB )
          {
            x = pNode->m_vOrigin.x;
            v16 = pCheckNode->m_vOrigin.x;
            if ( x != v16
              || pNode->m_vOrigin.y != pCheckNode->m_vOrigin.y
              || pNode->m_vOrigin.z != pCheckNode->m_vOrigin.z
              || m_eNodeType != NODE_CLIMB
              || pCheckNode->m_eNodeType != NODE_CLIMB )
            {
              v17 = v13->m_vOrigin.x;
              if ( (x != v17
                 || pNode->m_vOrigin.y != v13->m_vOrigin.y
                 || pNode->m_vOrigin.z != v13->m_vOrigin.z
                 || m_eNodeType != NODE_CLIMB
                 || v13->m_eNodeType != NODE_CLIMB)
                && (v16 != v17
                 || pCheckNode->m_vOrigin.y != v13->m_vOrigin.y
                 || pCheckNode->m_vOrigin.z != v13->m_vOrigin.z
                 || pCheckNode->m_eNodeType != NODE_CLIMB
                 || v13->m_eNodeType != NODE_CLIMB) )
              {
                m_pHint = pNode->m_pHint;
                if ( m_pHint == nullptr || (flDistToCheckNode_3 = 1, m_pHint->m_NodeData.nHintType != 904) )
                  flDistToCheckNode_3 = 0;
                v19 = pCheckNode->m_pHint;
                v20 = v19 != nullptr && v19->m_NodeData.nHintType == 904;
                v21 = v13->m_pHint;
                v22 = v21 != nullptr && v21->m_NodeData.nHintType == 904;
                if ( flDistToCheckNode_3 == 0 || v20 == v22 )
                {
                  vec2DirToCheckNode.x = v16 - x;
                  vec2DirToCheckNode.y = pCheckNode->m_vOrigin.y - pNode->m_vOrigin.y;
                  vec2DirToCheckNode.z = pCheckNode->m_vOrigin.z - pNode->m_vOrigin.z;
                  flDistToCheckNode = VectorNormalize(vec: &vec2DirToCheckNode);
                  vec2DirToTestNode.x = v13->m_vOrigin.x - pNode->m_vOrigin.x;
                  vec2DirToTestNode.y = v13->m_vOrigin.y - pNode->m_vOrigin.y;
                  vec2DirToTestNode.z = v13->m_vOrigin.z - pNode->m_vOrigin.z;
                  flDistToTestNode = VectorNormalize(vec: &vec2DirToTestNode);
                  if ( (float)((float)((float)(vec2DirToTestNode.y * vec2DirToCheckNode.y)
                                     + (float)(vec2DirToTestNode.x * vec2DirToCheckNode.x))
                             + (float)(vec2DirToTestNode.z * vec2DirToCheckNode.z)) >= 0.92387998 )
                  {
                    v23 = pNode->m_iID;
                    if ( flDistToCheckNode <= flDistToTestNode )
                    {
                      DebugConnectMsg(
                        node1: v23,
                        node2: v11,
                        pszFormat: "      Revoking neighbor status to closer redundant link %d\n",
                        checknode);
                      v24 = &v36->m_NeighborsTable.m_Memory.m_pMemory[pNode->m_iID].m_pInt[v31 / 4u];
                      v25 = v30;
                    }
                    else
                    {
                      DebugConnectMsg(
                        node1: v23,
                        node2: checknode,
                        pszFormat: "      Revoking neighbor status to closer redundant link %d\n",
                        v11);
                      v24 = &v36->m_NeighborsTable.m_Memory.m_pMemory[pNode->m_iID].m_pInt[v33 / 4u];
                      v25 = v32;
                    }
                    *v24 &= ~v25;
                  }
                }
              }
            }
          }
        }
      }
      v7 = checknode;
LABEL_65:
      if ( ++v11 >= pNetwork->m_iNumNodes )
        goto LABEL_66;
    }
  }
LABEL_68:
  v26 = pNode->m_iID;
  v27 = &v4->m_DidSetNeighborsTable.m_pInt[v26 >> 5];
  *v27 |= 1 << (v26 & 0x1F);
}

//------------------------------------------------------------------------------
// Address: 0x1006DC60
// Name: private: int CAI_NetworkBuilder::ComputeConnection(class CAI_Node __near *,class CAI_Node __near *,enum Hull_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_NetworkBuilder::ComputeConnection(
        CAI_NetworkBuilder *this,
        CAI_Node *pSrcNode,
        CAI_Node *pDestNode,
        int hull)
{
  int m_iID; // edx
  CAI_TestHull *m_pTestHull; // eax
  char v8; // cl
  CAI_Node *v9; // edx
  unsigned int v10; // eax
  char v12; // cl
  unsigned int v13; // eax
  NodeType_e m_eNodeType; // eax
  NodeType_e v15; // ecx
  const Vector *v16; // eax
  Vector *v17; // ebx
  float y; // xmm0_4
  float v19; // xmm0_4
  CAI_MoveProbe *m_pMoveProbe; // ebx
  unsigned int v21; // eax
  bool v22; // al
  int v23; // ebx
  unsigned int v24; // eax
  CAI_MoveProbe *v25; // ebx
  float v26; // eax
  CAI_MoveProbe *v27; // ebx
  float v28; // eax
  bool v29; // bl
  bool v30; // al
  CAI_TestHull *v31; // edi
  CAI_MoveProbe *v32; // ebx
  unsigned int v33; // eax
  unsigned int v34; // eax
  const Vector *v35; // eax
  const Vector *v36; // [esp+10h] [ebp-FCh]
  const Vector *v37; // [esp+10h] [ebp-FCh]
  unsigned int v38; // [esp+14h] [ebp-F8h]
  unsigned int v39; // [esp+14h] [ebp-F8h]
  CAI_TestHull *pctToCheckStandPositions; // [esp+18h] [ebp-F4h]
  CAI_TestHull *pctToCheckStandPositionsa; // [esp+18h] [ebp-F4h]
  Vector v42; // [esp+30h] [ebp-DCh] BYREF
  Vector v43; // [esp+3Ch] [ebp-D0h] BYREF
  AIMoveTrace_t moveTrace; // [esp+48h] [ebp-C4h] BYREF
  CGameTrace tr; // [esp+80h] [ebp-8Ch] BYREF
  Vector2D vLineB; // [esp+D4h] [ebp-38h] BYREF
  Vector srcPos; // [esp+DCh] [ebp-30h] BYREF
  Vector destPos; // [esp+E8h] [ebp-24h] BYREF
  Vector vec; // [esp+F4h] [ebp-18h] BYREF
  int v50; // [esp+100h] [ebp-Ch]
  int destId; // [esp+104h] [ebp-8h]
  int srcId; // [esp+108h] [ebp-4h]
  IHandleEntity savedregs; // [esp+10Ch] [ebp+0h] BYREF
  bool fJumpLegal_3; // [esp+117h] [ebp+Bh]
  Vector *pDestNodea; // [esp+118h] [ebp+Ch]
  CAI_Navigator *fStandFailed; // [esp+11Ch] [ebp+10h]
  CAI_Navigator *fStandFaileda; // [esp+11Ch] [ebp+10h]
  char fStandFailed_3; // [esp+11Fh] [ebp+13h]

  m_iID = pDestNode->m_iID;
  m_pTestHull = this->m_pTestHull;
  srcId = pSrcNode->m_iID;
  destId = m_iID;
  v50 = 0;
  if ( m_pTestHull->m_eHull != hull )
  {
    m_pTestHull->m_eHull = hull;
    CAI_BaseNPC::SetHullSizeNormal(this: this->m_pTestHull, force: true);
  }
  if ( (this->m_pTestHull->m_fFlags.m_Value & 1) == 0 )
    _DevWarning(a1: 2, a2: "OFFGROUND!\n");
  CBaseEntity::AddFlag(this: this->m_pTestHull, flags: 1);
  v8 = hull;
  if ( hull >= 9 )
    v8 = hull + 1;
  v9 = pSrcNode;
  if ( ((32 * (1 << v8)) & pSrcNode->m_eNodeInfo) == 0 )
  {
    fStandFailed = this->m_pTestHull->m_pNavigator;
    v10 = NAI_Hull::TraceMask(id: hull);
    if ( !CAI_Navigator::CanFitAtNode(this: fStandFailed, nodeNum: srcId, collisionMask: v10) )
    {
      DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Cannot fit at node %d\n", srcId);
      return 0;
    }
    v9 = pSrcNode;
  }
  v12 = hull;
  if ( hull >= 9 )
    v12 = hull + 1;
  if ( ((32 * (1 << v12)) & pDestNode->m_eNodeInfo) == 0 )
  {
    fStandFaileda = this->m_pTestHull->m_pNavigator;
    v13 = NAI_Hull::TraceMask(id: hull);
    if ( !CAI_Navigator::CanFitAtNode(this: fStandFaileda, nodeNum: destId, collisionMask: v13) )
    {
      DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Cannot fit at node %d\n", destId);
      return 0;
    }
    v9 = pSrcNode;
  }
  m_eNodeType = v9->m_eNodeType;
  if ( m_eNodeType == NODE_AIR )
  {
    if ( pDestNode->m_eNodeType == NODE_AIR )
    {
      pctToCheckStandPositionsa = this->m_pTestHull;
      v39 = NAI_Hull::TraceMask(id: hull);
      v37 = NAI_Hull::Maxs(id: hull);
      v35 = NAI_Hull::Mins(id: hull);
      UTIL_TraceHull(
        a1: &savedregs,
        a2: hull,
        vecAbsStart: &pSrcNode->m_vOrigin,
        vecAbsEnd: &pDestNode->m_vOrigin,
        hullMin: v35,
        hullMax: v37,
        mask: v39,
        ignore: pctToCheckStandPositionsa,
        collisionGroup: 0,
        ptr: &tr);
      if ( !tr.startsolid && tr.fraction == 1.0 )
      {
        v50 = 4;
        DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Connect by flying\n");
      }
    }
  }
  else
  {
    v15 = pDestNode->m_eNodeType;
    if ( v15 != NODE_AIR )
    {
      if ( m_eNodeType == NODE_CLIMB && v15 == NODE_CLIMB )
      {
        CAI_Node::GetPosition(this: v9, result: &srcPos, hull);
        CAI_Node::GetPosition(this: pDestNode, result: &destPos, hull);
        if ( !Vector::operator==(this: &pSrcNode->m_vOrigin, src: &pDestNode->m_vOrigin) )
        {
          pDestNodea = UTIL_YawToVector(result: &v43, yaw: pDestNode->m_flYaw);
          v17 = UTIL_YawToVector(result: &v42, yaw: pSrcNode->m_flYaw);
          y = v17->y;
          if ( (float)(1.0
                     - (float)((float)((float)(pDestNodea->y * y) + (float)(v17->x * pDestNodea->x))
                             + (float)(pDestNodea->z * v17->z))) > 0.01
            || (vLineB.x = v17->x + srcPos.x,
                vLineB.y = y + srcPos.y,
                CalcDistanceToLine2D(
                  P: (const Vector2D *)&destPos,
                  vLineA: (const Vector2D *)&srcPos,
                  &vLineB,
                  outT: nullptr) > 0.01)
            || (vec.x = srcPos.x - destPos.x,
                vec.y = srcPos.y - destPos.y,
                vec.z = srcPos.z - destPos.z,
                VectorNormalize(&vec),
                (v19 = fabs((float)((float)(v17->x * vec.x) + (float)(v17->y * vec.y)) + (float)(vec.z * v17->z))) > 0.05)
            && fabs(v19 - 0.4472) > 0.05 )
          {
            DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Not lined up for proper climbing\n");
            return 0;
          }
        }
        pctToCheckStandPositions = this->m_pTestHull;
        v38 = NAI_Hull::TraceMask(id: hull);
        v36 = NAI_Hull::Maxs(id: hull);
        v16 = NAI_Hull::Mins(id: hull);
        UTIL_TraceHull(
          a1: &savedregs,
          a2: hull,
          vecAbsStart: &srcPos,
          vecAbsEnd: &destPos,
          hullMin: v16,
          hullMax: v36,
          mask: v38,
          ignore: pctToCheckStandPositions,
          collisionGroup: 0,
          ptr: &tr);
        if ( !tr.startsolid && tr.fraction == 1.0 )
        {
          v50 = 8;
          DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Connect by climbing\n");
        }
      }
      else if ( m_eNodeType == NODE_GROUND || v15 == NODE_GROUND )
      {
        fStandFailed_3 = 0;
        CAI_Node::GetPosition(this: v9, result: &vec, hull);
        CAI_Node::GetPosition(this: pDestNode, result: &destPos, hull);
        m_pMoveProbe = this->m_pTestHull->m_pMoveProbe;
        v21 = NAI_Hull::TraceMask(id: hull);
        v22 = CAI_MoveProbe::CheckStandPosition(this: m_pMoveProbe, vecStart: &vec, collisionMask: v21);
        v23 = srcId;
        if ( !v22 )
        {
          DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Failed to stand at %d\n", srcId);
          fStandFailed_3 = 1;
        }
        LODWORD(vLineB.y) = this->m_pTestHull->m_pMoveProbe;
        v24 = NAI_Hull::TraceMask(id: hull);
        if ( !CAI_MoveProbe::CheckStandPosition(
                this: (CAI_MoveProbe *)LODWORD(vLineB.y),
                vecStart: &destPos,
                collisionMask: v24) )
        {
          DebugConnectMsg(node1: v23, node2: destId, pszFormat: "      Failed to stand at %d\n", destId);
          return v50;
        }
        if ( fStandFailed_3 == 0 )
        {
          v25 = this->m_pTestHull->m_pMoveProbe;
          v26 = COERCE_FLOAT(NAI_Hull::TraceMask(id: hull));
          if ( CAI_MoveProbe::TestGroundMove(
                 this: v25,
                 a2: COERCE_FLOAT(&savedregs),
                 vecActualStart: &vec,
                 vecDesiredEnd: &destPos,
                 collisionMask: v26,
                 pctToCheckStandPositions: 100.0,
                 flags: COERCE_FLOAT(2),
                 pMoveTrace: nullptr) != 0 )
          {
            v50 = 1;
            DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Nodes connect for ground movement\n");
          }
          else
          {
            DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Failed to walk between nodes\n");
            v27 = this->m_pTestHull->m_pMoveProbe;
            v28 = COERCE_FLOAT(NAI_Hull::TraceMask(id: hull));
            if ( CAI_MoveProbe::TestGroundMove(
                   this: v27,
                   a2: COERCE_FLOAT(&savedregs),
                   vecActualStart: &vec,
                   vecDesiredEnd: &destPos,
                   collisionMask: v28,
                   pctToCheckStandPositions: 100.0,
                   flags: COERCE_FLOAT(18),
                   pMoveTrace: nullptr) != 0 )
            {
              DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Nodes connect for crawl movement\n");
              v50 = 16;
            }
            if ( pSrcNode->m_eNodeType == NODE_GROUND && pDestNode->m_eNodeType == NODE_GROUND )
            {
              CAI_Node::GetPosition(this: pSrcNode, result: &destPos, hull);
              CAI_Node::GetPosition(this: pDestNode, result: &vec, hull);
              v29 = this->m_pTestHull->IsJumpLegal(this: this->m_pTestHull, a2: &destPos, a3: &vec, a4: &vec);
              v30 = this->m_pTestHull->IsJumpLegal(this: this->m_pTestHull, a2: &vec, a3: &destPos, a4: &destPos);
              if ( v29 || v30 )
              {
                v31 = this->m_pTestHull;
                v32 = v31->m_pMoveProbe;
                v31->m_flGravity = 1.0;
                memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
                v33 = NAI_Hull::TraceMask(id: hull);
                CAI_MoveProbe::MoveLimit(
                  this: v32,
                  a2: (int)&savedregs,
                  navType: NAV_JUMP,
                  vecStart: &destPos,
                  vecEnd: &vec,
                  collisionMask: v33,
                  pTarget: nullptr,
                  pctToCheckStandPositions: 100.0,
                  flags: 0,
                  pTrace: &moveTrace);
                fJumpLegal_3 = moveTrace.fStatus >= AIMR_OK;
                v34 = NAI_Hull::TraceMask(id: hull);
                CAI_MoveProbe::MoveLimit(
                  this: v32,
                  a2: (int)&savedregs,
                  navType: NAV_JUMP,
                  vecStart: &vec,
                  vecEnd: &destPos,
                  collisionMask: v34,
                  pTarget: nullptr,
                  pctToCheckStandPositions: 100.0,
                  flags: 0,
                  pTrace: &moveTrace);
                if ( moveTrace.fStatus >= AIMR_OK || fJumpLegal_3 )
                {
                  v50 |= 2u;
                  DebugConnectMsg(node1: srcId, node2: destId, pszFormat: "      Nodes connect for jumping\n");
                  return v50;
                }
              }
            }
          }
        }
      }
    }
  }
  return v50;
}

//------------------------------------------------------------------------------
// Address: 0x1006E320
// Name: private: void CAI_NetworkBuilder::InitLinks(class CAI_Network __near *,class CAI_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkBuilder::InitLinks(CAI_NetworkBuilder *this, CAI_Network *pNetwork, CAI_Node *pNode)
{
  CAI_TestHull *m_pTestHull; // eax
  CAI_Network *v4; // edi
  int v5; // ebx
  CAI_Node *v7; // edi
  int i; // edi
  const char *v9; // eax
  int v10; // eax
  CAI_Link *Link; // eax
  int j; // ecx
  unsigned int *v13; // eax
  int acceptedMotions[13]; // [esp+8h] [ebp-3Ch]
  CAI_NetworkBuilder *v15; // [esp+3Ch] [ebp-8h]
  CAI_Node *pDestNode; // [esp+40h] [ebp-4h]
  CAI_Link *bAllFailed; // [esp+50h] [ebp+Ch]
  char bAllFailed_3; // [esp+53h] [ebp+Fh]

  m_pTestHull = this->m_pTestHull;
  v4 = pNetwork;
  v15 = this;
  v5 = 0;
  for ( m_pTestHull->m_pNavigator->m_pAINetwork = pNetwork; v5 < pNetwork->m_iNumNodes; ++v5 )
  {
    DebugConnectMsg(
      node1: pNode->m_iID,
      node2: v5,
      pszFormat: "Testing connection between %d and %d:\n",
      pNode->m_iID,
      v5);
    if ( CAI_Node::HasLink(this: pNode, nNodeID: v5) != nullptr )
    {
      DebugConnectMsg(node1: pNode->m_iID, node2: v5, pszFormat: "   Nodes already connected\n");
    }
    else
    {
      if ( v5 < 0 || v5 >= v4->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        pDestNode = nullptr;
        v7 = nullptr;
      }
      else
      {
        v7 = v4->m_pAInode[v5];
        pDestNode = v7;
      }
      bAllFailed = CAI_Node::HasLink(this: v7, nNodeID: pNode->m_iID);
      if ( bAllFailed != nullptr )
      {
        DebugConnectMsg(node1: pNode->m_iID, node2: v5, pszFormat: "   Sharing previously establish connection\n");
        CAI_Node::AddLink(this: pNode, newLink: bAllFailed);
      }
      else if ( ((1 << (v7->m_iID & 0x1F))
               & v15->m_NeighborsTable.m_Memory.m_pMemory[pNode->m_iID].m_pInt[v7->m_iID >> 5]) != 0 )
      {
        bAllFailed_3 = 1;
        if ( pNode->m_iID == g_DebugConnectNode1 && v5 == g_DebugConnectNode2
          || pNode->m_iID == g_DebugConnectNode2 && v5 == g_DebugConnectNode1 )
        {
          DevMsg(a1: locale);
        }
        if ( pNode->m_eNodeInfo < 0 || pDestNode->m_eNodeInfo < 0 )
        {
          DebugConnectMsg(node1: pNode->m_iID, node2: v5, pszFormat: "   No connection: one or both are fallen nodes\n");
        }
        else
        {
          for ( i = 0; i < 12; ++i )
          {
            v9 = NAI_Hull::Name(id: i);
            DebugConnectMsg(node1: pNode->m_iID, node2: v5, pszFormat: "   Testing for hull %s\n", v9);
            v10 = CAI_NetworkBuilder::ComputeConnection(this: v15, pSrcNode: pNode, pDestNode, hull: i);
            acceptedMotions[i] = v10;
            if ( v10 != 0 )
              bAllFailed_3 = 0;
          }
          if ( bAllFailed_3 == 0 )
          {
            Link = CAI_Network::CreateLink(
                     this: pNetwork,
                     srcID: pNode->m_iID,
                     destID: pDestNode->m_iID,
                     pDynamicLink: nullptr);
            if ( Link != nullptr )
            {
              for ( j = 0; j < 12; ++j )
                Link->m_iAcceptedMoveTypes[j] = acceptedMotions[j];
              DebugConnectMsg(node1: pNode->m_iID, node2: v5, pszFormat: "   Added link\n");
            }
            goto LABEL_30;
          }
        }
        v13 = &v15->m_NeighborsTable.m_Memory.m_pMemory[pNode->m_iID].m_pInt[pDestNode->m_iID >> 5];
        *v13 &= ~(1 << (pDestNode->m_iID & 0x1F));
        DebugConnectMsg(node1: pNode->m_iID, node2: v5, pszFormat: "   NO LINK\n");
      }
      else
      {
        DebugConnectMsg(node1: pNode->m_iID, node2: v5, pszFormat: "   NO LINK (not neighbors)\n");
      }
    }
LABEL_30:
    v4 = pNetwork;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ECC0
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ED00
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EDB0
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EDF0
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EE90
// Name: private: void CAI_NetworkBuilder::InitClimbNodePosition(class CAI_Network __near *,class CAI_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkBuilder::InitClimbNodePosition(
        CAI_NetworkBuilder *this,
        CAI_Network *pNetwork,
        CAI_Node *pNode)
{
  bool v4; // zf
  const Vector *v6; // eax
  int v7; // esi
  CAI_Node *v8; // eax
  CAI_NetworkBuilder *v9; // ecx
  CAI_Node *v10; // esi
  float *v11; // ecx
  float *v12; // eax
  int v13; // esi
  int v14; // edx
  double v15; // st7
  int v16; // ebx
  float *m_flVOffset; // eax
  char *v18; // ecx
  const char *v19; // eax
  const Vector *v20; // [esp-Ch] [ebp-A4h]
  CGameTrace trace; // [esp+10h] [ebp-88h] BYREF
  Vector origin; // [esp+64h] [ebp-34h] BYREF
  Vector posOnLadder; // [esp+70h] [ebp-28h] BYREF
  CAI_NetworkBuilder *v24; // [esp+7Ch] [ebp-1Ch]
  char *v25; // [esp+80h] [ebp-18h]
  int checkNodeTypes[3]; // [esp+84h] [ebp-14h] BYREF
  float *v27; // [esp+90h] [ebp-8h]
  int i; // [esp+94h] [ebp-4h]
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF
  int numExits; // [esp+A4h] [ebp+Ch]

  v4 = (pNode->m_eNodeInfo & 0x1C) == 0;
  v24 = this;
  if ( v4 )
  {
    CAI_Node::GetPosition(this: pNode, result: &posOnLadder, hull: 1);
    checkNodeTypes[0] = LODWORD(posOnLadder.x);
    checkNodeTypes[1] = LODWORD(posOnLadder.y);
    *(float *)&checkNodeTypes[2] = posOnLadder.z - 37.0;
    v20 = NAI_Hull::Maxs(id: 1);
    v6 = NAI_Hull::Mins(id: 1);
    UTIL_TraceHull(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &posOnLadder,
      vecAbsEnd: (const Vector *)checkNodeTypes,
      hullMin: v6,
      hullMax: v20,
      mask: 0x2400Bu,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &trace);
    if ( trace.startsolid || trace.fraction == 1.0 )
    {
      if ( !CAI_NetworkManager::gm_fNetworksLoaded )
      {
        v7 = 0;
        checkNodeTypes[0] = 4;
        checkNodeTypes[1] = 8;
        checkNodeTypes[2] = 16;
        numExits = 0;
        i = 0;
        do
        {
          pNode->m_eNodeInfo = checkNodeTypes[v7];
          CAI_Node::GetPosition(this: pNode, result: &origin, hull: 1);
          UTIL_TraceLine(
            a1: &savedregs,
            a2: v7,
            vecAbsStart: &posOnLadder,
            vecAbsEnd: &origin,
            mask: 0x2400Bu,
            ignore: nullptr,
            collisionGroup: 0,
            ptr: &trace);
          if ( !trace.startsolid && trace.fraction == 1.0 && fabs(pNode->m_vOrigin.z - GetFloorZ(&origin)) < 36.0 )
          {
            v8 = CAI_Network::AddNode(this: pNetwork, origin: &pNode->m_vOrigin, yaw: pNode->m_flYaw);
            v9 = v24;
            v10 = v8;
            v8->m_pHint = nullptr;
            v8->m_eNodeType = NODE_CLIMB;
            v8->m_eNodeInfo = pNode->m_eNodeInfo;
            CAI_NetworkBuilder::InitGroundNodePosition(this: v9, a2: COERCE_FLOAT(&savedregs), pNetwork, pNode: v8);
            if ( numExits != 0 )
            {
              v16 = 0;
              m_flVOffset = v10->m_flVOffset;
              v18 = (char *)((char *)pNode - (char *)v10);
              v27 = v10->m_flVOffset;
              v25 = (char *)((char *)pNode - (char *)v10);
              do
              {
                if ( COERCE_FLOAT(
                       COERCE_UNSIGNED_INT(*(float *)((char *)m_flVOffset + (_DWORD)v18) - *m_flVOffset)
                     & _mask__AbsFloat_) > 1.0 )
                {
                  v19 = NAI_Hull::Name(id: v16);
                  _DevMsg(
                    a1: 2,
                    a2: "Warning: Climb Node %i has different exit heights for hull %s\n",
                    pNode->m_iID,
                    v19);
                  v18 = v25;
                  m_flVOffset = v27;
                }
                ++v16;
                v27 = ++m_flVOffset;
              }
              while ( v16 < 12 );
            }
            else
            {
              v11 = &v10->m_flVOffset[2];
              v12 = pNode->m_flVOffset;
              v13 = (char *)v10 - (char *)pNode;
              v14 = 2;
              do
              {
                v15 = *(float *)((char *)v12 + v13);
                v12 += 6;
                *(v12 - 6) = v15;
                v11 += 6;
                --v14;
                *(v12 - 5) = *(v11 - 7);
                *(v12 - 4) = *(v11 - 6);
                *(v12 - 3) = *(v11 - 5);
                *(v12 - 2) = *(v11 - 4);
                *(v12 - 1) = *(v11 - 3);
              }
              while ( v14 != 0 );
            }
            ++numExits;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < 3 );
        if ( numExits == 0 )
          DevMsg(a1: "ERROR: Climb Node %i has no way off\n", pNode->m_iID);
        pNode->m_eNodeInfo = 2;
      }
    }
    else
    {
      pNode->m_eNodeInfo = 1;
      CAI_NetworkBuilder::InitGroundNodePosition(this, a2: COERCE_FLOAT(&savedregs), pNetwork, pNode);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F100
// Name: public: void CAI_NetworkBuilder::InitNodePosition(class CAI_Network __near *,class CAI_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkBuilder::InitNodePosition(CAI_NetworkBuilder *this, CAI_Network *pNetwork, CAI_Node *pNode)
{
  NodeType_e m_eNodeType; // eax
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  m_eNodeType = pNode->m_eNodeType;
  if ( m_eNodeType != NODE_AIR )
  {
    switch ( m_eNodeType )
    {
      case NODE_CLIMB:
        CAI_NetworkBuilder::InitClimbNodePosition(this, pNetwork, pNode);
        break;
      case NODE_GROUND:
        CAI_NetworkBuilder::InitGroundNodePosition(this, a2: COERCE_FLOAT(&savedregs), pNetwork, pNode);
        if ( pNode->m_flVOffset[1] < -100.0 )
        {
          DevWarning(
            a1: "ERROR: Node %.0f %.0f %.0f, WC ID# %i, is either too low (fell through floor) or too high (>100 units above floor)\n",
            pNode->m_vOrigin.x,
            pNode->m_vOrigin.y,
            pNode->m_vOrigin.z,
            g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[pNode->m_iID]);
          pNode->m_eNodeInfo |= 0x80000000;
        }
        break;
      case NODE_DELETED:
LABEL_11:
        break;
      default:
        DevMsg(a1: "Bad node type!\n");
        goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100700D0
// Name: public: char CUtlBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10070100
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100702A0
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (__int16 *)&s,
          inputBuffer: (__int16 *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtol(nptr: endptr, &endptr, ibase: 0xAu);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10070340
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 0xAu);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10070520
// Name: public: void CAI_NetworkManager::LoadNetworkGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkManager::LoadNetworkGraph(CAI_NetworkManager *this)
{
  const char *pszValue; // eax
  unsigned __int8 v3; // cl
  unsigned __int8 v4; // cl
  signed int Int; // esi
  int v6; // eax
  int v7; // eax
  signed int i; // edi
  CAI_Node *v9; // esi
  signed __int8 v10; // al
  signed int v11; // eax
  signed int j; // edi
  int Short; // esi
  __int16 v14; // ax
  CAI_Link *Link; // eax
  unsigned __int8 *m_iAcceptedMoveTypes; // eax
  int m_iNumNodes; // eax
  int v18; // eax
  int k; // esi
  CAI_NetworkEditTools *m_pEditOps; // edi
  CAI_Network *m_pNetwork; // edx
  int v22; // eax
  unsigned __int16 v23; // ax
  unsigned __int16 v24; // dx
  unsigned __int16 v25; // cx
  int v26; // esi
  UtlRBTreeNode_t<int,unsigned short> *v27; // eax
  int v28; // esi
  int v29; // edx
  UtlRBTreeNode_t<int,unsigned short> *v30; // eax
  unsigned __int16 v31; // ax
  unsigned __int16 v32; // dx
  unsigned __int16 v33; // cx
  int v34; // esi
  UtlRBTreeNode_t<int,unsigned short> *m_pMemory; // eax
  int v36; // edx
  int *v37; // eax
  CAI_Network *v38; // edx
  char szNrpFilename[260]; // [esp+38h] [ebp-18Ch] BYREF
  unsigned __int8 ignored[12]; // [esp+13Ch] [ebp-88h] BYREF
  float yaw; // [esp+148h] [ebp-7Ch] BYREF
  CUtlRBTree<int,unsigned short,bool (__cdecl*)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short> > usedIds; // [esp+14Ch] [ebp-78h] BYREF
  CUtlRBTree<int,unsigned short,bool (__cdecl*)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short> > reportedIds; // [esp+168h] [ebp-5Ch] BYREF
  CUtlBuffer buf; // [esp+184h] [ebp-40h] BYREF
  int node; // [esp+1B4h] [ebp-10h] BYREF
  int dest; // [esp+1B8h] [ebp-Ch] BYREF
  int editorId; // [esp+1BCh] [ebp-8h] BYREF
  bool printedHeader; // [esp+1C2h] [ebp-2h]
  bool leftchild; // [esp+1C3h] [ebp-1h] BYREF

  if ( engine->IsInEditMode(this: engine) == 0 && g_pGameRules->FAllowNPCs(this: g_pGameRules) )
  {
    V_strncpy(pDest: szNrpFilename, pSrc: "maps", maxLen: 260);
    filesystem->CreateDirHierarchy(this: filesystem, a2: szNrpFilename, a3: "DEFAULT_WRITE_PATH");
    V_strncat(pDest: szNrpFilename, pSrc: "/graphs", destBufferSize: 0x104u, max_chars_to_copy: -1);
    filesystem->CreateDirHierarchy(this: filesystem, a2: szNrpFilename, a3: "DEFAULT_WRITE_PATH");
    V_strncat(pDest: szNrpFilename, pSrc: "/", destBufferSize: 0x104u, max_chars_to_copy: -1);
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    V_strncat(pDest: szNrpFilename, pSrc: pszValue, destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_strncat(pDest: szNrpFilename, pSrc: ".ain", destBufferSize: 0x104u, max_chars_to_copy: -1);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    if ( !filesystem->ReadFile(
            this: &filesystem->IBaseFileSystem,
            a2: szNrpFilename,
            a3: "game",
            a4: &buf,
            a5: 0,
            a6: 0,
            a7: nullptr) )
    {
      _DevWarning(a1: 2, a2: "Couldn't read %s!\n", szNrpFilename);
      CUtlBuffer::~CUtlBuffer(this: &buf);
      return;
    }
    if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1)
      && (v3 = buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset], ++buf.m_Get, v3 == 86)
      && CUtlBuffer::CheckGet(this: &buf, nSize: 1)
      && (v4 = buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset], ++buf.m_Get, v4 == 101)
      && CUtlBuffer::GetChar(this: &buf) == 114
      || (CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0), CUtlBuffer::GetInt(this: &buf) != 41) )
    {
      DevMsg(a1: "AI node graph %s is out of date\n", szNrpFilename);
LABEL_13:
      CUtlBuffer::~CUtlBuffer(this: &buf);
      return;
    }
    if ( CUtlBuffer::GetInt(this: &buf) != gpGlobals->mapversion
      && (g_ai_norebuildgraph.m_pParent == nullptr || g_ai_norebuildgraph.m_pParent->m_Value.m_nValue == 0) )
    {
      DevMsg(a1: "AI node graph %s is out of date (map version changed)\n", szNrpFilename);
      goto LABEL_13;
    }
    Int = CUtlBuffer::GetInt(this: &buf);
    if ( (unsigned int)Int > 0x5DC )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_10442594, a2: szNrpFilename);
      DevMsg(a1: (const char *)buf.m_Memory.m_pMemory);
      DevMsg(a1: "\n");
      CUtlBuffer::~CUtlBuffer(this: &buf);
    }
    else
    {
      if ( engine->IsInEditMode(this: engine) != 0 && Int <= 1024 )
      {
        Int = 1024;
        v6 = 1024;
      }
      else if ( Int <= 1 )
      {
        v6 = 1;
      }
      else
      {
        v6 = Int;
      }
      this->m_pNetwork->m_pAInode = (CAI_Node **)operator new(nSize: 4 * v6);
      v7 = Int;
      if ( Int <= 1 )
        v7 = 1;
      memset(dst: (int)this->m_pNetwork->m_pAInode, value: nullptr, count: 4 * v7);
      if ( Int > 0 )
      {
        for ( i = Int; i != 0; --i )
        {
          CUtlBuffer::GetType<float>(this: &buf, dest: (float *)&node);
          *(_DWORD *)ignored = node;
          CUtlBuffer::GetType<float>(this: &buf, (float *)&dest);
          *(_DWORD *)&ignored[4] = dest;
          CUtlBuffer::GetType<float>(this: &buf, dest: (float *)&editorId);
          *(_DWORD *)&ignored[8] = editorId;
          CUtlBuffer::GetType<float>(this: &buf, dest: &yaw);
          v9 = CAI_Network::AddNode(this: this->m_pNetwork, origin: (const Vector *)ignored, yaw);
          CUtlBuffer::Get(this: &buf, pMem: v9->m_flVOffset, size: 48);
          if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1) )
          {
            v10 = buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset];
            ++buf.m_Get;
          }
          else
          {
            v10 = 0;
          }
          v9->m_eNodeType = v10;
          v9->m_eNodeInfo = CUtlBuffer::GetInt(this: &buf);
          v9->m_zone = (__int16)CUtlBuffer::GetShort(this: &buf);
        }
      }
      v11 = CUtlBuffer::GetInt(this: &buf);
      if ( v11 > 0 )
      {
        for ( j = v11; j != 0; --j )
        {
          Short = (__int16)CUtlBuffer::GetShort(this: &buf);
          v14 = CUtlBuffer::GetShort(this: &buf);
          Link = CAI_Network::CreateLink(this: this->m_pNetwork, srcID: Short, destID: v14, pDynamicLink: nullptr);
          if ( Link != nullptr )
            m_iAcceptedMoveTypes = Link->m_iAcceptedMoveTypes;
          else
            m_iAcceptedMoveTypes = ignored;
          CUtlBuffer::Get(this: &buf, pMem: m_iAcceptedMoveTypes, size: 12);
        }
      }
      free(pMem: this->m_pEditOps->m_pNodeIndexTable);
      m_iNumNodes = this->m_pNetwork->m_iNumNodes;
      if ( m_iNumNodes <= 1 )
        m_iNumNodes = 1;
      this->m_pEditOps->m_pNodeIndexTable = (int *)operator new(nSize: 4 * m_iNumNodes);
      v18 = this->m_pNetwork->m_iNumNodes;
      if ( v18 <= 1 )
        v18 = 1;
      memset(dst: (int)this->m_pEditOps->m_pNodeIndexTable, value: nullptr, count: 4 * v18);
      for ( k = 0; k < this->m_pNetwork->m_iNumNodes; ++k )
      {
        m_pEditOps = this->m_pEditOps;
        m_pEditOps->m_pNodeIndexTable[k] = CUtlBuffer::GetInt(this: &buf);
      }
      usedIds.m_FirstFree = -1;
      usedIds.m_Root = -1;
      usedIds.m_LastAlloc.index = -1;
      reportedIds.m_FirstFree = -1;
      reportedIds.m_NumElements = 0;
      printedHeader = false;
      m_pNetwork = this->m_pNetwork;
      usedIds.m_NumElements = 0;
      usedIds.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CKeyBindingsMgr::KeyBindingContextHandleLessFunc;
      reportedIds.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CKeyBindingsMgr::KeyBindingContextHandleLessFunc;
      v22 = 0;
      memset(&usedIds.m_Elements, 0, sizeof(usedIds.m_Elements));
      usedIds.m_pElements = nullptr;
      memset(&reportedIds.m_Elements, 0, sizeof(reportedIds.m_Elements));
      reportedIds.m_Root = -1;
      reportedIds.m_LastAlloc.index = -1;
      reportedIds.m_pElements = nullptr;
      node = 0;
      if ( m_pNetwork->m_iNumNodes > 0 )
      {
        while ( 1 )
        {
          editorId = this->m_pEditOps->m_pNodeIndexTable[v22];
          if ( editorId != -1 )
          {
            if ( CUtlRBTree<int,unsigned short,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short>>::Find(
                   this: &usedIds,
                   search: &editorId) == 0xFFFF )
            {
              dest = 0xFFFF;
              leftchild = false;
              CUtlRBTree<int,unsigned short,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short>>::FindInsertionPosition(
                this: &usedIds,
                insert: &editorId,
                parent: (unsigned __int16 *)&dest,
                &leftchild);
              v31 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
                      this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&usedIds,
                      a2: (const char *)0xFFFF);
              v32 = dest;
              v33 = v31;
              v34 = 3 * v31;
              m_pMemory = usedIds.m_Elements.m_pMemory;
              v28 = 4 * v34;
              *(unsigned __int16 *)((char *)&usedIds.m_Elements.m_pMemory->m_Right + v28) = -1;
              *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v28) = -1;
              *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v28) = 0;
              *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v28) = v32;
              if ( v32 == 0xFFFF )
              {
                usedIds.m_Root = v33;
              }
              else
              {
                v36 = v32;
                if ( leftchild )
                  m_pMemory[v36].m_Left = v33;
                else
                  m_pMemory[v36].m_Right = v33;
              }
              CUtlRBTree<int,unsigned short,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short>>::InsertRebalance(
                this: &usedIds,
                elem: v33);
              ++usedIds.m_NumElements;
              v30 = usedIds.m_Elements.m_pMemory;
            }
            else
            {
              if ( !printedHeader )
              {
                _Warning(a1: "** Duplicate Hammer Node IDs: ");
                printedHeader = true;
              }
              if ( CUtlRBTree<int,unsigned short,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short>>::Find(
                     this: &reportedIds,
                     search: &editorId) != 0xFFFF )
                goto LABEL_66;
              DevMsg(a1: "%d, ", editorId);
              dest = 0xFFFF;
              leftchild = false;
              CUtlRBTree<int,unsigned short,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short>>::FindInsertionPosition(
                this: &reportedIds,
                insert: &editorId,
                parent: (unsigned __int16 *)&dest,
                &leftchild);
              v23 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
                      this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&reportedIds,
                      a2: (const char *)0xFFFF);
              v24 = dest;
              v25 = v23;
              v26 = 3 * v23;
              v27 = reportedIds.m_Elements.m_pMemory;
              v28 = 4 * v26;
              *(unsigned __int16 *)((char *)&reportedIds.m_Elements.m_pMemory->m_Right + v28) = -1;
              *(unsigned __int16 *)((char *)&v27->m_Left + v28) = -1;
              *(unsigned __int16 *)((char *)&v27->m_Tag + v28) = 0;
              *(unsigned __int16 *)((char *)&v27->m_Parent + v28) = v24;
              if ( v24 == 0xFFFF )
              {
                reportedIds.m_Root = v25;
              }
              else
              {
                v29 = v24;
                if ( leftchild )
                  v27[v29].m_Left = v25;
                else
                  v27[v29].m_Right = v25;
              }
              CUtlRBTree<int,unsigned short,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short>>::InsertRebalance(
                this: &reportedIds,
                elem: v25);
              ++reportedIds.m_NumElements;
              v30 = reportedIds.m_Elements.m_pMemory;
            }
            v37 = (int *)((char *)&v30->m_Data + v28);
            if ( v37 != nullptr )
              *v37 = editorId;
          }
LABEL_66:
          v38 = this->m_pNetwork;
          v22 = node + 1;
          node = v22;
          if ( v22 >= v38->m_iNumNodes )
          {
            if ( printedHeader )
              DevMsg(a1: "\n** Should run \"Check For Problems\" on the VMF then verify dynamic links\n");
            break;
          }
        }
      }
      CAI_NetworkManager::gm_fNetworksLoaded = true;
      CAI_DynamicLink::gm_bInitialized = false;
      CUtlRBTree<int,unsigned short,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short>>::RemoveAll(this: &reportedIds);
      if ( reportedIds.m_Elements.m_nGrowSize >= 0 && reportedIds.m_Elements.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reportedIds.m_Elements.m_pMemory);
      CUtlRBTree<int,unsigned short,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,unsigned short>,unsigned short>>::RemoveAll(this: &usedIds);
      if ( usedIds.m_Elements.m_nGrowSize >= 0 && usedIds.m_Elements.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: usedIds.m_Elements.m_pMemory);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070D10
// Name: private: void CAI_NetworkManager::SaveNetworkGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_NetworkManager::SaveNetworkGraph(CAI_NetworkManager *this@<ecx>, __int64 a2@<esi:edi>)
{
  bool v3; // zf
  const char *pszValue; // eax
  int v5; // edi
  int v6; // kr00_4
  int v7; // ecx
  char *v8; // esi
  const char *v9; // eax
  CAI_Network *m_pNetwork; // eax
  CAI_Node *v11; // ebx
  int x_low; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  int m_flYaw_low; // xmm0_4
  int v16; // esi
  int m_zone; // esi
  int m_Size; // ecx
  CAI_Link **m_pMemory; // eax
  int v20; // edx
  int v21; // esi
  CAI_Network *v22; // eax
  int v23; // ecx
  CAI_Node *v24; // edi
  int v25; // ecx
  __int16 *p_m_iSrcID; // esi
  __int16 v27; // bx
  int v28; // eax
  unsigned __int8 *v29; // eax
  __int16 v30; // bx
  int *v31; // eax
  CAI_Network *v32; // eax
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *v33; // edi
  int v34; // ebx
  int v35; // esi
  int v36; // ecx
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *v37; // eax
  int v38; // esi
  CUtlMap<int,int,unsigned short>::Node_t *p_m_Data; // esi
  CAI_NetworkManager *v40; // esi
  int v41; // eax
  int v42; // eax
  unsigned __int8 *v43; // eax
  void *v44; // eax
  void *v45; // esi
  int v46; // [esp+Ch] [ebp-29Ch]
  int mapversion; // [esp+14h] [ebp-294h]
  int m_iNumNodes; // [esp+14h] [ebp-294h]
  char tempFilename[260]; // [esp+1Ch] [ebp-28Ch] BYREF
  char szNrpFilename[260]; // [esp+120h] [ebp-188h] BYREF
  float v53; // [esp+224h] [ebp-84h]
  float inputBuffer; // [esp+228h] [ebp-80h] BYREF
  CUtlMap<int,int,unsigned short>::Node_t search; // [esp+22Ch] [ebp-7Ch] BYREF
  float v56; // [esp+234h] [ebp-74h]
  float v57; // [esp+238h] [ebp-70h] BYREF
  CUtlMap<int,int,unsigned short> wcIDs; // [esp+23Ch] [ebp-6Ch] BYREF
  CUtlMap<int,int,unsigned short>::Node_t insert; // [esp+258h] [ebp-50h] BYREF
  int link; // [esp+260h] [ebp-48h] BYREF
  __int16 v61[2]; // [esp+264h] [ebp-44h] BYREF
  CAI_NetworkManager *v62; // [esp+268h] [ebp-40h]
  bool leftchild; // [esp+26Eh] [ebp-3Ah] BYREF
  bool bCheckForProblems; // [esp+26Fh] [ebp-39h]
  CUtlBuffer buf; // [esp+270h] [ebp-38h] BYREF
  int node; // [esp+2A0h] [ebp-8h] BYREF
  int totalNumLinks; // [esp+2A4h] [ebp-4h] BYREF

  v3 = !this->m_bDontSaveGraph;
  v62 = this;
  if ( v3 && this->m_bNeedGraphRebuild && g_pGameRules->FAllowNPCs(this: g_pGameRules) )
  {
    V_strncpy(pDest: szNrpFilename, pSrc: "maps/graphs", maxLen: 260);
    pszValue = gpGlobals->mapname.pszValue;
    v5 = 0;
    if ( pszValue == nullptr )
      pszValue = locale;
    V_snprintf(pDest: tempFilename, maxLen: 260, pFormat: "%s/%s", szNrpFilename, pszValue);
    v6 = strlen(tempFilename);
    v7 = 0;
    if ( v6 > 0 )
    {
      v8 = &tempFilename[v6 - 1];
      while ( *v8 != 47 && *v8 != 92 )
      {
        ++v7;
        --v8;
        if ( v7 >= v6 )
          goto LABEL_13;
      }
      tempFilename[v6 - v7 - 1] = 0;
    }
LABEL_13:
    ((void (__thiscall *)(IFileSystem *, char *, const char *, _DWORD, _DWORD))filesystem->CreateDirHierarchy)(
      a1: filesystem,
      a2: tempFilename,
      a3: "DEFAULT_WRITE_PATH",
      a4: a2,
      a5: HIDWORD(a2));
    V_strncat(pDest: szNrpFilename, pSrc: "/", destBufferSize: 0x104u, max_chars_to_copy: -1);
    v9 = gpGlobals->mapname.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    V_strncat(pDest: szNrpFilename, pSrc: v9, destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_strncat(pDest: szNrpFilename, pSrc: ".ain", destBufferSize: 0x104u, max_chars_to_copy: -1);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    if ( (buf.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &buf, pFmt: "%d", 41);
    else
      CUtlBuffer::PutTypeBin<int>(this: &buf, src: 41);
    mapversion = gpGlobals->mapversion;
    if ( (buf.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &buf, pFmt: "%d", mapversion);
    else
      CUtlBuffer::PutTypeBin<int>(this: &buf, src: mapversion);
    m_iNumNodes = this->m_pNetwork->m_iNumNodes;
    if ( (buf.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &buf, pFmt: "%d", m_iNumNodes);
    else
      CUtlBuffer::PutTypeBin<int>(this: &buf, src: m_iNumNodes);
    m_pNetwork = this->m_pNetwork;
    totalNumLinks = 0;
    if ( m_pNetwork->m_iNumNodes > 0 )
    {
      do
      {
        if ( v5 < 0 || v5 >= m_pNetwork->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v11 = nullptr;
        }
        else
        {
          v11 = m_pNetwork->m_pAInode[v5];
        }
        x_low = SLODWORD(v11->m_vOrigin.x);
        node = x_low;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%f", *(float *)&x_low);
        }
        else
        {
          link = x_low;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &buf.m_Byteswap,
                outputBuffer: (float *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                inputBuffer: (float *)&link,
                count: 1);
            else
              *(_DWORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = node;
            buf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        y = v11->m_vOrigin.y;
        v53 = y;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%f", y);
        }
        else
        {
          inputBuffer = y;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &buf.m_Byteswap,
                outputBuffer: (float *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(float *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v53;
            buf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        z = v11->m_vOrigin.z;
        v56 = z;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%f", z);
        }
        else
        {
          v57 = z;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &buf.m_Byteswap,
                outputBuffer: (float *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                inputBuffer: &v57,
                count: 1);
            else
              *(float *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v56;
            buf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        m_flYaw_low = SLODWORD(v11->m_flYaw);
        insert.elem = m_flYaw_low;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%f", *(float *)&m_flYaw_low);
        }
        else
        {
          search.elem = m_flYaw_low;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &buf.m_Byteswap,
                outputBuffer: (float *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                inputBuffer: (float *)&search.elem,
                count: 1);
            else
              *(_DWORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = insert.elem;
            buf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        CUtlBuffer::Put(this: &buf, pMem: v11->m_flVOffset, size: 48);
        *(_DWORD *)v61 = v11->m_eNodeType;
        if ( (buf.m_Flags & 1) != 0 && buf.m_Put != 0 && buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: &buf);
        if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
        {
          buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v61[0];
          CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
        }
        v16 = v11->m_eNodeInfo & 0xFFFFFFF;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%d", v11->m_eNodeInfo & 0xFFFFFFF);
        }
        else
        {
          *(_DWORD *)v61 = v11->m_eNodeInfo & 0xFFFFFFF;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &buf.m_Byteswap,
                outputBuffer: (int *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                inputBuffer: (int *)v61,
                count: 1);
            else
              *(_DWORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v16;
            buf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        m_zone = v11->m_zone;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%hd", (__int16)m_zone);
        }
        else
        {
          *(_DWORD *)v61 = (unsigned __int16)m_zone;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 2) )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned short>(
                this: &buf.m_Byteswap,
                outputBuffer: (__int16 *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                inputBuffer: v61,
                count: 1);
            else
              *(_WORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = m_zone;
            buf.m_Put += 2;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        m_Size = v11->m_Links.m_Size;
        if ( m_Size > 0 )
        {
          m_pMemory = v11->m_Links.m_Memory.m_pMemory;
          v20 = totalNumLinks;
          do
          {
            if ( v5 == (*m_pMemory)->m_iSrcID )
              ++v20;
            ++m_pMemory;
            --m_Size;
          }
          while ( m_Size != 0 );
          totalNumLinks = v20;
        }
        m_pNetwork = v62->m_pNetwork;
        ++v5;
      }
      while ( v5 < m_pNetwork->m_iNumNodes );
    }
    if ( (buf.m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: &buf, pFmt: "%d", totalNumLinks);
    }
    else
    {
      v21 = totalNumLinks;
      *(_DWORD *)v61 = totalNumLinks;
      if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
      {
        if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &buf.m_Byteswap,
            outputBuffer: (int *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
            inputBuffer: (int *)v61,
            count: 1);
        else
          *(_DWORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v21;
        buf.m_Put += 4;
        CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
      }
    }
    v22 = v62->m_pNetwork;
    v23 = 0;
    node = 0;
    if ( v22->m_iNumNodes > 0 )
    {
      while ( 1 )
      {
        if ( v23 < 0 || v23 >= v22->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v24 = nullptr;
        }
        else
        {
          v24 = v22->m_pAInode[node];
        }
        v25 = 0;
        for ( link = 0; v25 < v24->m_Links.m_Size; link = v25 )
        {
          p_m_iSrcID = &v24->m_Links.m_Memory.m_pMemory[v25]->m_iSrcID;
          if ( node == *p_m_iSrcID )
          {
            v27 = *p_m_iSrcID;
            if ( (buf.m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: &buf, pFmt: "%hd", *p_m_iSrcID);
            }
            else
            {
              totalNumLinks = (unsigned __int16)*p_m_iSrcID;
              if ( CUtlBuffer::CheckPut(this: &buf, nSize: 2) )
              {
                v28 = buf.m_Put - buf.m_nOffset;
                if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
                {
                  v29 = &buf.m_Memory.m_pMemory[v28];
                  if ( v29 != nullptr )
                  {
                    if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
                    {
                      HIWORD(totalNumLinks) = 0;
                      LOBYTE(totalNumLinks) = HIBYTE(v27);
                      BYTE1(totalNumLinks) = v27;
                      _V_memcpy(dest: v29, src: &totalNumLinks, count: 2);
                    }
                    else if ( v29 != (unsigned __int8 *)&totalNumLinks )
                    {
                      *(_WORD *)v29 = totalNumLinks;
                    }
                  }
                }
                else
                {
                  *(_WORD *)&buf.m_Memory.m_pMemory[v28] = v27;
                }
                buf.m_Put += 2;
                CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
              }
            }
            v30 = p_m_iSrcID[1];
            if ( (buf.m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: &buf, pFmt: "%hd", v30);
            }
            else
            {
              totalNumLinks = (unsigned __int16)p_m_iSrcID[1];
              if ( CUtlBuffer::CheckPut(this: &buf, nSize: 2) )
              {
                if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
                {
                  v31 = (int *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset];
                  if ( v31 != nullptr )
                  {
                    if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
                    {
                      HIWORD(totalNumLinks) = 0;
                      LOBYTE(totalNumLinks) = HIBYTE(v30);
                      BYTE1(totalNumLinks) = v30;
                      _V_memcpy(dest: &buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset], src: &totalNumLinks, count: 2);
                    }
                    else if ( v31 != &totalNumLinks )
                    {
                      *(_WORD *)v31 = totalNumLinks;
                    }
                  }
                }
                else
                {
                  *(_WORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v30;
                }
                buf.m_Put += 2;
                CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
              }
            }
            CUtlBuffer::Put(this: &buf, pMem: p_m_iSrcID + 2, size: 12);
            v25 = link;
          }
          ++v25;
        }
        v22 = v62->m_pNetwork;
        if ( ++node >= v22->m_iNumNodes )
          break;
        v23 = node;
      }
    }
    v32 = v62->m_pNetwork;
    v33 = nullptr;
    v34 = 0;
    memset(&wcIDs.m_Tree.m_Elements, 0, sizeof(wcIDs.m_Tree.m_Elements));
    *(_DWORD *)&wcIDs.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&wcIDs.m_Tree.m_FirstFree = -1;
    wcIDs.m_Tree.m_pElements = nullptr;
    wcIDs.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CKeyBindingsMgr::KeyBindingContextHandleLessFunc;
    bCheckForProblems = false;
    if ( v32->m_iNumNodes > 0 )
    {
      do
      {
        search.key = v62->m_pEditOps->m_pNodeIndexTable[v34];
        v35 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: &wcIDs.m_Tree,
                &search);
        if ( v35 == 0xFFFF )
        {
          insert.key = v62->m_pEditOps->m_pNodeIndexTable[v34];
          insert.elem = v34;
          node = 0xFFFF;
          leftchild = false;
          CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: &wcIDs.m_Tree,
            &insert,
            parent: (unsigned __int16 *)&node,
            &leftchild);
          v36 = (unsigned __int16)CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
                                    this: (CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short> > *)&wcIDs,
                                    a2: (const char *)v33);
          v37 = wcIDs.m_Tree.m_Elements.m_pMemory;
          v38 = v36;
          wcIDs.m_Tree.m_Elements.m_pMemory[v38].m_Parent = node;
          v37[v38].m_Right = -1;
          v37[v38].m_Left = -1;
          v37[v38].m_Tag = 0;
          if ( (_WORD)node == 0xFFFF )
          {
            wcIDs.m_Tree.m_Root = v36;
          }
          else if ( leftchild )
          {
            v37[(unsigned __int16)node].m_Left = v36;
          }
          else
          {
            v37[(unsigned __int16)node].m_Right = v36;
          }
          CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
            this: &wcIDs.m_Tree,
            elem: v36);
          v33 = wcIDs.m_Tree.m_Elements.m_pMemory;
          ++wcIDs.m_Tree.m_NumElements;
          p_m_Data = &wcIDs.m_Tree.m_Elements.m_pMemory[v38].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = insert;
        }
        else
        {
          if ( !bCheckForProblems )
          {
            DevWarning(a1: "******* MAP CONTAINS DUPLICATE HAMMER NODE IDS! CHECK FOR PROBLEMS IN HAMMER TO CORRECT *******\n");
            bCheckForProblems = true;
          }
          v46 = v62->m_pEditOps->m_pNodeIndexTable[v34];
          DevWarning(
            a1: "   AI node %d is associated with Hammer node %d, but %d is already bound to node %d\n",
            v34,
            v46,
            v46,
            v33[v35].m_Data.elem);
        }
        v40 = v62;
        v41 = v62->m_pEditOps->m_pNodeIndexTable[v34];
        totalNumLinks = v41;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%d", v41);
        }
        else if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
        {
          v42 = buf.m_Put - buf.m_nOffset;
          if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
          {
            v43 = &buf.m_Memory.m_pMemory[v42];
            if ( v43 != nullptr )
            {
              if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              {
                LOBYTE(node) = HIBYTE(totalNumLinks);
                BYTE1(node) = BYTE2(totalNumLinks);
                BYTE2(node) = BYTE1(totalNumLinks);
                HIBYTE(node) = totalNumLinks;
                _V_memcpy(dest: v43, src: &node, count: 4);
              }
              else if ( v43 != (unsigned __int8 *)v61 )
              {
                *(_DWORD *)v43 = totalNumLinks;
              }
            }
          }
          else
          {
            *(_DWORD *)&buf.m_Memory.m_pMemory[v42] = totalNumLinks;
          }
          buf.m_Put += 4;
          CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
        }
        ++v34;
      }
      while ( v34 < v40->m_pNetwork->m_iNumNodes );
    }
    v44 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *))filesystem->Open)(
                    a1: &filesystem->IBaseFileSystem,
                    a2: szNrpFilename);
    v45 = v44;
    if ( v44 != nullptr )
    {
      filesystem->Write(this: &filesystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v44);
      filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v45);
    }
    else
    {
      _DevWarning(a1: 2, a2: "Couldn't create %s!\n", szNrpFilename);
    }
    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &wcIDs.m_Tree);
    if ( wcIDs.m_Tree.m_Elements.m_nGrowSize >= 0 && wcIDs.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wcIDs.m_Tree.m_Elements.m_pMemory);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100717C0
// Name: public: void CAI_NetworkBuilder::Build(class CAI_Network __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CAI_NetworkBuilder::Build(CAI_NetworkBuilder *this, CAI_Network *pNetwork)
{
  CAI_Node **m_pAInode; // eax
  int i; // ebx
  int m_iNumNodes; // ebx
  unsigned int *m_pInt; // eax
  char *v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ebx
  bool v11; // sf
  unsigned int v12; // edx
  unsigned __int64 v13; // kr20_8
  CAI_Hint *j; // eax
  int v15; // ebx
  CAI_Network *v16; // eax
  void **v17; // esi
  CVarBitVecBase<unsigned short> *v18; // ecx
  CFastTimer masterTimer; // [esp+20h] [ebp-38h] BYREF
  CFastTimer timer; // [esp+28h] [ebp-30h] BYREF
  CAI_NetworkBuildHelper *pHelper; // [esp+30h] [ebp-28h]
  CVarBitVecBase<unsigned short> *v22[2]; // [esp+34h] [ebp-24h]
  unsigned __int64 v23; // [esp+3Ch] [ebp-1Ch] BYREF
  unsigned __int64 v24; // [esp+44h] [ebp-14h] OVERLAPPED
  int nNodes; // [esp+4Ch] [ebp-Ch]
  unsigned __int64 v26; // [esp+50h] [ebp-8h]

  m_pAInode = pNetwork->m_pAInode;
  nNodes = pNetwork->m_iNumNodes;
  HIDWORD(v24) = m_pAInode;
  if ( nNodes != 0 )
  {
    pHelper = (CAI_NetworkBuildHelper *)CreateEntityByName(
                                          className: "ai_network_build_helper",
                                          iForceEdictIndex: -1,
                                          bNotify: true);
    this->m_pTestHull = CAI_TestHull::GetTestHull();
    timer.m_Duration.m_Int64 = 0;
    DevMsg(a1: "Building AI node graph...\n");
    v22[1] = (CVarBitVecBase<unsigned short> *)&masterTimer;
    masterTimer.m_Duration.m_Int64 = __rdtsc();
    DevMsg(a1: "Initializing node positions...\n");
    v22[1] = (CVarBitVecBase<unsigned short> *)&timer;
    timer.m_Duration.m_Int64 = __rdtsc();
    for ( i = 0; i < nNodes; ++i )
    {
      CAI_NetworkBuilder::InitNodePosition(this, pNetwork, pNode: *(CAI_Node **)(HIDWORD(v24) + 4 * i));
      if ( pHelper != nullptr )
        pHelper->PostInitNodePosition(this: pHelper, a2: pNetwork, a3: *(CAI_Node **)(HIDWORD(v24) + 4 * i));
    }
    m_iNumNodes = pNetwork->m_iNumNodes;
    nNodes = m_iNumNodes;
    v23 = __rdtsc();
    timer.m_Duration.m_Int64 = v23 - timer.m_Duration.m_Int64;
    *(_QWORD *)v22 = timer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    DevMsg(
      a1: "...done initializing node positions. %f seconds\n",
      (double)((double)timer.m_Duration.m_Int64 * _g_ClockSpeedSecondsMultiplier));
    DevMsg(a1: "Initializing node neighbors...\n");
    timer.m_Duration.m_Int64 = __rdtsc();
    v22[1] = &this->m_DidSetNeighborsTable;
    CVarBitVecBase<unsigned short>::Resize(
      this: &this->m_DidSetNeighborsTable,
      resizeNumBits: m_iNumNodes,
      bClearAll: false);
    m_pInt = v22[1]->m_pInt;
    if ( m_pInt != nullptr )
      memset(dst: (int)m_pInt, value: nullptr, count: 4 * v22[1]->m_numInts);
    CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>::RemoveAll(this: &this->m_NeighborsTable);
    CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>::InsertMultipleBefore(
      this: &this->m_NeighborsTable,
      elem: this->m_NeighborsTable.m_Size,
      num: m_iNumNodes);
    if ( m_iNumNodes > 0 )
    {
      HIDWORD(v26) = 0;
      HIDWORD(v23) = m_iNumNodes;
      do
      {
        CVarBitVecBase<unsigned short>::Resize(
          this: (CVarBitVecBase<unsigned short> *)((char *)this->m_NeighborsTable.m_Memory.m_pMemory + HIDWORD(v26)),
          resizeNumBits: m_iNumNodes,
          bClearAll: false);
        v7 = (char *)this->m_NeighborsTable.m_Memory.m_pMemory + HIDWORD(v26);
        v8 = *((_DWORD *)v7 + 2);
        if ( v8 != 0 )
          memset(dst: v8, value: nullptr, count: 4 * *((unsigned __int16 *)v7 + 1));
        HIDWORD(v26) += 12;
        --HIDWORD(v23);
      }
      while ( HIDWORD(v23) != 0 );
    }
    HIDWORD(v26) = 0;
    if ( m_iNumNodes > 0 )
    {
      do
      {
        CAI_NetworkBuilder::InitNeighbors(this, pNetwork, pNode: *(CAI_Node **)(HIDWORD(v24) + 4 * HIDWORD(v26)));
        ++HIDWORD(v26);
      }
      while ( SHIDWORD(v26) < m_iNumNodes );
    }
    v26 = __rdtsc();
    timer.m_Duration.m_Int64 = v26 - timer.m_Duration.m_Int64;
    v23 = timer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    DevMsg(
      a1: "...done initializing node neighbors. %f seconds\n",
      (double)((double)timer.m_Duration.m_Int64 * _g_ClockSpeedSecondsMultiplier));
    DevMsg(a1: "Forcing dynamic link neighbors...\n");
    HIDWORD(v23) = &timer;
    timer.m_Duration.m_Int64 = __rdtsc();
    CAI_NetworkBuilder::ForceDynamicLinkNeighbors(this);
    v26 = __rdtsc();
    timer.m_Duration.m_Int64 = v26 - timer.m_Duration.m_Int64;
    v23 = timer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    DevMsg(
      a1: "...done forcing dynamic link neighbors. %f seconds\n",
      (double)((double)timer.m_Duration.m_Int64 * _g_ClockSpeedSecondsMultiplier));
    DevMsg(a1: "Determining links...\n");
    HIDWORD(v23) = &timer;
    timer.m_Duration.m_Int64 = __rdtsc();
    v9 = 0;
    HIDWORD(v26) = 0;
    if ( m_iNumNodes > 0 )
    {
      do
      {
        v10 = *(_DWORD *)(HIDWORD(v24) + 4 * v9);
        v11 = *(int *)(v10 + 88) < 0;
        *(_DWORD *)(v10 + 92) = 0;
        if ( !v11 )
        {
          if ( *(_DWORD *)(v10 + 80) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v10 + 80));
            v9 = HIDWORD(v26);
            *(_DWORD *)(v10 + 80) = 0;
          }
          *(_DWORD *)(v10 + 84) = 0;
        }
        ++v9;
        *(_DWORD *)(v10 + 96) = *(_DWORD *)(v10 + 80);
        HIDWORD(v26) = v9;
      }
      while ( v9 < nNodes );
      m_iNumNodes = nNodes;
    }
    HIDWORD(v26) = 0;
    if ( m_iNumNodes > 0 )
    {
      do
      {
        CAI_NetworkBuilder::InitLinks(this, pNetwork, pNode: *(CAI_Node **)(HIDWORD(v24) + 4 * HIDWORD(v26)));
        ++HIDWORD(v26);
      }
      while ( SHIDWORD(v26) < m_iNumNodes );
    }
    v24 = __rdtsc();
    timer.m_Duration.m_Int64 = v24 - timer.m_Duration.m_Int64;
    v23 = timer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    DevMsg(
      a1: "...done determining links. %f seconds\n",
      (double)((double)timer.m_Duration.m_Int64 * _g_ClockSpeedSecondsMultiplier));
    DevMsg(a1: "Determining zones...\n");
    HIDWORD(v23) = &timer;
    timer.m_Duration.m_Int64 = __rdtsc();
    CAI_NetworkBuilder::InitZones(this, pNetwork);
    timer.m_Duration.m_Int64 = __rdtsc() - timer.m_Duration.m_Int64;
    pNetwork = (CAI_Network *)&v23;
    v23 = __rdtsc();
    v13 = v23 - masterTimer.m_Duration.m_Int64;
    v12 = v23 - LODWORD(masterTimer.m_Duration.m_Int64);
    v23 = timer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    masterTimer.m_Duration.m_Int64 = __PAIR64__(HIDWORD(v13), v12);
    DevMsg(
      a1: "...done determining zones. %f seconds\n",
      (double)((double)timer.m_Duration.m_Int64 * _g_ClockSpeedSecondsMultiplier));
    v23 = masterTimer.m_Duration.m_Int64 & 0x8000000000000000uLL;
    DevMsg(
      a1: "...done building AI node graph, %f seconds\n",
      (double)((double)masterTimer.m_Duration.m_Int64 * _g_ClockSpeedSecondsMultiplier));
    for ( j = CAI_HintManager::GetFirstHint(pIter: (AIHintIter_t__ **)&pNetwork);
          j != nullptr;
          j = CAI_HintManager::GetNextHint(pIter: (AIHintIter_t__ **)&pNetwork) )
    {
      CAI_Hint::FixupTargetNode(this: j);
    }
    v15 = this->m_NeighborsTable.m_Size - 1;
    if ( v15 >= 0 )
    {
      v16 = (CAI_Network *)(12 * v15);
      pNetwork = (CAI_Network *)(12 * v15);
      do
      {
        v17 = (void **)((char *)&v16->__vftable + (unsigned int)this->m_NeighborsTable.m_Memory.m_pMemory);
        if ( *((_WORD *)v17 + 1) > 1u )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17[2]);
          v16 = pNetwork;
        }
        v16 = (CAI_Network *)((char *)v16 - 12);
        --v15;
        v17[2] = nullptr;
        pNetwork = v16;
      }
      while ( v15 >= 0 );
    }
    v18 = v22[1];
    this->m_NeighborsTable.m_Size = 0;
    CVarBitVecBase<unsigned short>::Resize(this: v18, resizeNumBits: 0, bClearAll: false);
    CAI_TestHull::ReturnTestHull();
    if ( pHelper != nullptr )
      UTIL_Remove(oldObj: pHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071D50
// Name: public: void CAI_NetworkManager::BuildNetworkGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_NetworkManager::BuildNetworkGraph(CAI_NetworkManager *this@<ecx>, __int64 a2@<esi:edi>)
{
  HIDWORD(a2) = this;
  if ( !this->m_bDontSaveGraph )
  {
    CAI_DynamicLink::gm_bInitialized = false;
    CAI_NetworkBuilder::Build(this: &g_AINetworkBuilder, pNetwork: this->m_pNetwork);
    if ( !CAI_NetworkManager::gm_fNetworksLoaded )
    {
      CAI_NetworkManager::SaveNetworkGraph(this: (CAI_NetworkManager *)HIDWORD(a2), a2);
      CAI_NetworkManager::gm_fNetworksLoaded = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071D90
// Name: private: void CAI_NetworkManager::DelayedInit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_NetworkManager::DelayedInit(CAI_NetworkManager *this@<ecx>, __int64 a2@<esi:edi>)
{
  CAI_Hint *i; // eax
  const char *pszValue; // eax
  EditorSendResult_t v4; // eax
  AIHintIter_t__ *pIter; // [esp+10h] [ebp-4h] BYREF

  HIDWORD(a2) = this;
  if ( !g_pGameRules->FAllowNPCs(this: g_pGameRules) )
    goto LABEL_24;
  if ( g_ai_norebuildgraph.m_pParent != nullptr && g_ai_norebuildgraph.m_pParent->m_Value.m_nValue != 0 )
    goto LABEL_9;
  if ( *(_BYTE *)(HIDWORD(a2) + 852) != 0 )
  {
    CAI_NetworkManager::BuildNetworkGraph(this: (CAI_NetworkManager *)HIDWORD(a2), a2);
    if ( engine->IsInEditMode(this: engine) != 0 )
      engine->ServerCommand(this: engine, a2: "exec map_edit.cfg\n");
    CBaseEntity::ThinkSet(this: (CBaseEntity *)HIDWORD(a2), func: nullptr, thinkTime: 0.0, szContext: nullptr);
    if ( !g_bAIDisabledByUser )
      CAI_BaseNPC::m_nDebugBits &= ~1u;
    goto LABEL_9;
  }
  if ( *(_BYTE *)(HIDWORD(a2) + 865) != 0
    || CAI_NetworkManager::gm_fNetworksLoaded && engine->IsInEditMode(this: engine) == 0 )
  {
LABEL_9:
    CAI_DynamicLink::InitDynamicLinks();
    for ( i = CAI_HintManager::GetFirstHint(&pIter); i != nullptr; i = CAI_HintManager::GetNextHint(&pIter) )
      CAI_Hint::FixupTargetNode(this: i);
    engine->IsInEditMode(this: engine);
    *(_BYTE *)(HIDWORD(a2) + 864) = 1;
    if ( vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager) != 0 && g_pBigAINet->m_iNumNodes == 0 )
      DevMsg(a1: "WARNING: Level contains NPCs but has no path nodes\n");
    return;
  }
  if ( engine->IsInEditMode(this: engine) != 0 )
  {
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v4 = Editor_BeginSession(pszMapName: pszValue, nMapVersion: gpGlobals->mapversion, bShowUI: false);
    if ( v4 == Editor_NotRunning )
    {
      DevMsg(a1: "\nAborting map_edit\nWorldcraft not running...\n\n");
      UTIL_ClientPrintAll(
        msg_dest: 4,
        msg_name: "Worldcraft not running...\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
LABEL_23:
      engine->ServerCommand(this: engine, a2: "disconnect\n");
LABEL_24:
      CBaseEntity::ThinkSet(this: (CBaseEntity *)HIDWORD(a2), func: nullptr, thinkTime: 0.0, szContext: nullptr);
      return;
    }
    if ( v4 == Editor_BadCommand )
    {
      DevMsg(a1: "\nAborting map_edit\nWC/Engine map versions different...\n\n");
      UTIL_ClientPrintAll(
        msg_dest: 4,
        msg_name: "WC/Engine map versions different...\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      goto LABEL_23;
    }
    ++gpGlobals->mapversion;
  }
  DevMsg(a1: "Node Graph out of Date. Rebuilding...\n");
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
    UTIL_ClientPrintAll(
      msg_dest: 4,
      msg_name: "Node Graph out of Date. Rebuilding...\n",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  *(_BYTE *)(HIDWORD(a2) + 852) = 1;
  CBaseEntity::SetNextThink(this: g_pAINetworkManager, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10071FE0
// Name: private: static unsigned int CAI_NetworkManager::ThreadedBuildJob(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CAI_NetworkManager::ThreadedBuildJob(void *pBuildData)
{
  CThreadMutex::Lock(this: (CThreadMutex *)pBuildData);
  CAI_NetworkBuilder::Build(this: &g_AINetworkBuilder, pNetwork: *((CAI_Network **)pBuildData + 8));
  _InterlockedExchange((volatile __int32 *)pBuildData + 9, 2);
  CThreadMutex::Unlock(this: (CThreadMutex *)pBuildData);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10072020
// Name: public: void CAI_NetworkBuilder::Rebuild(class CAI_Network __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkBuilder::Rebuild(CAI_NetworkBuilder *this, CAI_Network *pNetwork)
{
  CAI_Node **m_pAInode; // ebx
  int m_iNumNodes; // edi
  CAI_TestHull *TestHull; // eax
  int v6; // edx
  CAI_Node *v7; // eax
  __int64 v8; // xmm0_8
  int v9; // esi
  _DWORD *v10; // eax
  int v11; // edx
  float v12; // xmm4_4
  bool v13; // cc
  int v14; // edx
  float v15; // xmm4_4
  bool v16; // cc
  float v17; // xmm4_4
  bool v18; // cc
  int v19; // edx
  float v20; // xmm4_4
  bool v21; // cc
  CAI_Node *v22; // eax
  float v23; // xmm4_4
  bool v24; // cc
  int j; // esi
  int v26; // esi
  unsigned int *m_pInt; // eax
  int v28; // edi
  int v29; // ebx
  CVarBitVec *m_pMemory; // esi
  int v31; // esi
  int v32; // edi
  int k; // edi
  int v34; // edi
  CAI_Node *v35; // esi
  int m; // edi
  CAI_Hint *n; // eax
  int v38; // edi
  int v39; // ebx
  CVarBitVec *v40; // esi
  float vRebuildPos_8; // [esp+14h] [ebp-18h]
  CAI_Node **ppNodes; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  unsigned int v44; // [esp+20h] [ebp-Ch]
  int nNodes; // [esp+28h] [ebp-4h]

  m_pAInode = pNetwork->m_pAInode;
  m_iNumNodes = pNetwork->m_iNumNodes;
  ppNodes = m_pAInode;
  if ( m_iNumNodes != 0 )
  {
    TestHull = CAI_TestHull::GetTestHull();
    v6 = 0;
    this->m_pTestHull = TestHull;
    for ( i = 0; v6 < m_iNumNodes; i = v6 )
    {
      v7 = m_pAInode[v6];
      if ( (v7->m_eNodeInfo & 0x20000000) != 0 )
      {
        v8 = *(_QWORD *)&v7->m_vOrigin.x;
        vRebuildPos_8 = v7->m_vOrigin.z;
        m_pAInode[v6]->m_eNodeInfo |= 0x10000000u;
        v9 = 0;
        m_pAInode[v6]->m_zone = 3;
        if ( m_iNumNodes >= 4 )
        {
          v10 = m_pAInode + 2;
          v44 = ((unsigned int)(m_iNumNodes - 4) >> 2) + 1;
          v9 = 4 * v44;
          do
          {
            v11 = *(v10 - 2);
            v12 = (float)((float)((float)(*(float *)(v11 + 8) - *((float *)&v8 + 1))
                                * (float)(*(float *)(v11 + 8) - *((float *)&v8 + 1)))
                        + (float)((float)(*(float *)(v11 + 4) - *(float *)&v8)
                                * (float)(*(float *)(v11 + 4) - *(float *)&v8)))
                + (float)((float)(*(float *)(v11 + 12) - vRebuildPos_8) * (float)(*(float *)(v11 + 12) - vRebuildPos_8));
            if ( *(_DWORD *)(v11 + 68) == 3 )
              v13 = v12 >= 2073600.0;
            else
              v13 = v12 >= 518400.0;
            if ( !v13 )
            {
              *(_DWORD *)(v11 + 72) |= 0x10000000u;
              *(_DWORD *)(*(v10 - 2) + 76) = 3;
            }
            v14 = *(v10 - 1);
            v15 = (float)((float)((float)(*(float *)(v14 + 8) - *((float *)&v8 + 1))
                                * (float)(*(float *)(v14 + 8) - *((float *)&v8 + 1)))
                        + (float)((float)(*(float *)(v14 + 4) - *(float *)&v8)
                                * (float)(*(float *)(v14 + 4) - *(float *)&v8)))
                + (float)((float)(*(float *)(v14 + 12) - vRebuildPos_8) * (float)(*(float *)(v14 + 12) - vRebuildPos_8));
            if ( *(_DWORD *)(v14 + 68) == 3 )
              v16 = v15 >= 2073600.0;
            else
              v16 = v15 >= 518400.0;
            if ( !v16 )
            {
              *(_DWORD *)(v14 + 72) |= 0x10000000u;
              *(_DWORD *)(*(v10 - 1) + 76) = 3;
            }
            v17 = (float)((float)((float)(*(float *)(*v10 + 8) - *((float *)&v8 + 1))
                                * (float)(*(float *)(*v10 + 8) - *((float *)&v8 + 1)))
                        + (float)((float)(*(float *)(*v10 + 4) - *(float *)&v8)
                                * (float)(*(float *)(*v10 + 4) - *(float *)&v8)))
                + (float)((float)(*(float *)(*v10 + 12) - vRebuildPos_8) * (float)(*(float *)(*v10 + 12) - vRebuildPos_8));
            if ( *(_DWORD *)(*v10 + 68) == 3 )
              v18 = v17 >= 2073600.0;
            else
              v18 = v17 >= 518400.0;
            if ( !v18 )
            {
              *(_DWORD *)(*v10 + 72) |= 0x10000000u;
              *(_DWORD *)(*v10 + 76) = 3;
            }
            v19 = v10[1];
            v20 = (float)((float)((float)(*(float *)(v19 + 8) - *((float *)&v8 + 1))
                                * (float)(*(float *)(v19 + 8) - *((float *)&v8 + 1)))
                        + (float)((float)(*(float *)(v19 + 4) - *(float *)&v8)
                                * (float)(*(float *)(v19 + 4) - *(float *)&v8)))
                + (float)((float)(*(float *)(v19 + 12) - vRebuildPos_8) * (float)(*(float *)(v19 + 12) - vRebuildPos_8));
            if ( *(_DWORD *)(v19 + 68) == 3 )
              v21 = v20 >= 2073600.0;
            else
              v21 = v20 >= 518400.0;
            if ( !v21 )
            {
              *(_DWORD *)(v19 + 72) |= 0x10000000u;
              *(_DWORD *)(v10[1] + 76) = 3;
            }
            v10 += 4;
            --v44;
          }
          while ( v44 != 0 );
          v6 = i;
        }
        for ( ; v9 < m_iNumNodes; ++v9 )
        {
          v22 = m_pAInode[v9];
          v23 = (float)((float)((float)(v22->m_vOrigin.y - *((float *)&v8 + 1))
                              * (float)(v22->m_vOrigin.y - *((float *)&v8 + 1)))
                      + (float)((float)(v22->m_vOrigin.x - *(float *)&v8) * (float)(v22->m_vOrigin.x - *(float *)&v8)))
              + (float)((float)(v22->m_vOrigin.z - vRebuildPos_8) * (float)(v22->m_vOrigin.z - vRebuildPos_8));
          if ( v22->m_eNodeType == NODE_AIR )
            v24 = v23 >= 2073600.0;
          else
            v24 = v23 >= 518400.0;
          if ( !v24 )
          {
            v22->m_eNodeInfo |= 0x10000000u;
            m_pAInode[v9]->m_zone = 3;
          }
        }
      }
      ++v6;
    }
    for ( j = 0; j < m_iNumNodes; ++j )
    {
      if ( (m_pAInode[j]->m_eNodeInfo & 0x10000000) != 0 )
        CAI_NetworkBuilder::InitNodePosition(this, pNetwork, pNode: m_pAInode[j]);
    }
    nNodes = pNetwork->m_iNumNodes;
    v26 = nNodes;
    CVarBitVecBase<unsigned short>::Resize(this: &this->m_DidSetNeighborsTable, resizeNumBits: nNodes, bClearAll: false);
    m_pInt = this->m_DidSetNeighborsTable.m_pInt;
    if ( m_pInt != nullptr )
      memset(dst: (int)m_pInt, value: nullptr, count: 4 * this->m_DidSetNeighborsTable.m_numInts);
    v28 = this->m_NeighborsTable.m_Size - 1;
    if ( v28 >= 0 )
    {
      v29 = v28;
      do
      {
        m_pMemory = this->m_NeighborsTable.m_Memory.m_pMemory;
        if ( this->m_NeighborsTable.m_Memory.m_pMemory[v29].m_numInts > 1u )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory[v29].m_pInt);
        m_pMemory[v29--].m_pInt = nullptr;
        --v28;
      }
      while ( v28 >= 0 );
      v26 = nNodes;
      m_pAInode = ppNodes;
    }
    this->m_NeighborsTable.m_Size = 0;
    CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>::InsertMultipleBefore(
      this: &this->m_NeighborsTable,
      elem: 0,
      num: v26);
    if ( v26 > 0 )
    {
      v31 = 0;
      v32 = nNodes;
      do
      {
        CVarBitVecBase<unsigned short>::Resize(
          this: &this->m_NeighborsTable.m_Memory.m_pMemory[v31++],
          resizeNumBits: nNodes,
          bClearAll: false);
        --v32;
      }
      while ( v32 != 0 );
      v26 = nNodes;
      m_pAInode = ppNodes;
    }
    for ( k = 0; k < v26; ++k )
    {
      if ( (m_pAInode[k]->m_eNodeInfo & 0x10000000) != 0 )
        CAI_NetworkBuilder::InitNeighbors(this, pNetwork, pNode: m_pAInode[k]);
    }
    CAI_NetworkBuilder::ForceDynamicLinkNeighbors(this);
    v34 = 0;
    if ( v26 > 0 )
    {
      do
      {
        v35 = m_pAInode[v34];
        if ( (v35->m_eNodeInfo & 0x10000000) != 0 )
        {
          v35->m_Links.m_Size = 0;
          if ( v35->m_Links.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v35->m_Links.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v35->m_Links.m_Memory.m_pMemory);
              v35->m_Links.m_Memory.m_pMemory = nullptr;
            }
            v35->m_Links.m_Memory.m_nAllocationCount = 0;
          }
          v35->m_Links.m_pElements = v35->m_Links.m_Memory.m_pMemory;
        }
        ++v34;
      }
      while ( v34 < nNodes );
      v26 = nNodes;
    }
    for ( m = 0; m < v26; ++m )
    {
      if ( (m_pAInode[m]->m_eNodeInfo & 0x10000000) != 0 )
        CAI_NetworkBuilder::InitLinks(this, pNetwork, pNode: m_pAInode[m]);
    }
    for ( n = CAI_HintManager::GetFirstHint(pIter: (AIHintIter_t__ **)&pNetwork);
          n != nullptr;
          n = CAI_HintManager::GetNextHint(pIter: (AIHintIter_t__ **)&pNetwork) )
    {
      CAI_Hint::FixupTargetNode(this: n);
    }
    v38 = this->m_NeighborsTable.m_Size - 1;
    if ( v38 >= 0 )
    {
      v39 = v38;
      do
      {
        v40 = this->m_NeighborsTable.m_Memory.m_pMemory;
        if ( this->m_NeighborsTable.m_Memory.m_pMemory[v39].m_numInts > 1u )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40[v39].m_pInt);
        v40[v39--].m_pInt = nullptr;
        --v38;
      }
      while ( v38 >= 0 );
    }
    this->m_NeighborsTable.m_Size = 0;
    CVarBitVecBase<unsigned short>::Resize(this: &this->m_DidSetNeighborsTable, resizeNumBits: 0, bClearAll: false);
    CAI_TestHull::ReturnTestHull();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100724C0
// Name: private: void CAI_NetworkManager::ThreadedInit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_NetworkManager::ThreadedInit(CAI_NetworkManager *this@<ecx>, __int64 a2@<esi:edi>)
{
  int v2; // eax
  int v3; // eax
  CAI_Network *v4; // eax
  float curtime; // xmm0_4
  int v6; // [esp+4h] [ebp-10h]

  HIDWORD(a2) = this;
  if ( !g_pGameRules->FAllowNPCs(this: g_pGameRules) )
  {
    CBaseEntity::ThinkSet(this: (CBaseEntity *)HIDWORD(a2), func: nullptr, thinkTime: 0.0, szContext: nullptr);
    return;
  }
  if ( *(_BYTE *)(HIDWORD(a2) + 865) != 0 )
  {
    _Warning(a1: "m_bDontSaveGraph set, using synchronous map rebuild\n");
    CBaseEntity::ThinkSet(
      this: (CBaseEntity *)HIDWORD(a2),
      func: (void (__thiscall *)(CBaseEntity *))CAI_NetworkManager::DelayedInit,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this: (CBaseEntity *)HIDWORD(a2), thinkTime: gpGlobals->curtime, szContext: nullptr);
    CAI_NetworkManager::DelayedInit(this: (CAI_NetworkManager *)HIDWORD(a2), a2);
    return;
  }
  if ( CAI_NetworkManager::gm_fNetworksLoaded )
    goto LABEL_14;
  v2 = *(_DWORD *)(HIDWORD(a2) + 904);
  if ( v2 == 0 )
  {
    if ( !CThreadMutex::TryLock(this: (CThreadMutex *)(HIDWORD(a2) + 868)) )
    {
      _Warning(a1: "FAILED to initiate threaded node graph build due to already locked mutex!");
      return;
    }
    *(_DWORD *)(HIDWORD(a2) + 900) = *(_DWORD *)(HIDWORD(a2) + 860);
    _InterlockedExchange((volatile __int32 *)(HIDWORD(a2) + 904), 1);
    *(_DWORD *)(HIDWORD(a2) + 908) = _CreateSimpleThread(
                                       a1: CAI_NetworkManager::ThreadedBuildJob,
                                       a2: HIDWORD(a2) + 868,
                                       a3: 0);
    CAI_DynamicLink::gm_bInitialized = false;
    CThreadMutex::Unlock(this: (CThreadMutex *)(HIDWORD(a2) + 868));
    UTIL_ClientPrintAll(
      msg_dest: 4,
      msg_name: "Node Graph out of Date. Rebuilding in background.\n",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    curtime = gpGlobals->curtime;
    goto LABEL_22;
  }
  v3 = v2 - 1;
  if ( v3 == 0 )
  {
    UTIL_ClientPrintAll(
      msg_dest: 4,
      msg_name: "Node Graph out of Date. Rebuilding in background.\n",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    curtime = gpGlobals->curtime;
LABEL_22:
    CBaseEntity::SetNextThink(this: (CBaseEntity *)HIDWORD(a2), thinkTime: curtime + 1.0, szContext: nullptr);
    return;
  }
  if ( v3 == 1 )
  {
    if ( !CThreadMutex::TryLock(this: (CThreadMutex *)(HIDWORD(a2) + 868)) )
      CThreadMutex::Lock(this: (CThreadMutex *)(HIDWORD(a2) + 868));
    v4 = *(CAI_Network **)(HIDWORD(a2) + 900);
    *(_DWORD *)(HIDWORD(a2) + 860) = v4;
    g_pBigAINet = v4;
    LODWORD(a2) = 0;
    v6 = *(_DWORD *)(HIDWORD(a2) + 908);
    *(_DWORD *)(HIDWORD(a2) + 900) = 0;
    _ReleaseThreadHandle(a1: v6);
    *(_DWORD *)(HIDWORD(a2) + 908) = 0;
    if ( !CAI_NetworkManager::gm_fNetworksLoaded )
    {
      CAI_NetworkManager::SaveNetworkGraph(this: (CAI_NetworkManager *)HIDWORD(a2), a2);
      CAI_NetworkManager::gm_fNetworksLoaded = true;
    }
    CAI_DynamicLink::InitDynamicLinks();
    CAI_NetworkManager::FixupHints(this: (CAI_NetworkManager *)HIDWORD(a2));
  }
LABEL_14:
  engine->IsInEditMode(this: engine);
  *(_BYTE *)(HIDWORD(a2) + 864) = 1;
  if ( vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager) != 0 && g_pBigAINet->m_iNumNodes == 0 )
    DevMsg(a1: "WARNING: Level contains NPCs but has no path nodes\n");
  CBaseEntity::ThinkSet(this: (CBaseEntity *)HIDWORD(a2), func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10072700
// Name: private: void CAI_NetworkManager::RebuildThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkManager::RebuildThink(CAI_NetworkManager *this)
{
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->m_pEditOps->m_debugNetOverlays &= ~0x10000000u;
  CAI_DynamicLink::gm_bInitialized = false;
  CAI_NetworkBuilder::Rebuild(this: &g_AINetworkBuilder, pNetwork: this->m_pNetwork);
  CAI_DynamicLink::PurgeDynamicLinks();
  CAI_DynamicLink::ResetDynamicLinks();
  CAI_NetworkEditTools::RecalcUsableNodesForHull(this: this->m_pEditOps);
  CAI_NetworkEditTools::ClearRebuildFlags(this: this->m_pEditOps);
}

//------------------------------------------------------------------------------
// Address: 0x10072760
// Name: public: void CAI_NetworkManager::RebuildNetworkGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_NetworkManager::RebuildNetworkGraph(CAI_NetworkManager *this)
{
  if ( (void (__thiscall *)(CAI_NetworkManager *))this->m_pfnThink != CAI_NetworkManager::RebuildThink )
  {
    UTIL_ClientPrintAll(
      msg_dest: 4,
      msg_name: "Doing partial rebuild of Node Graph...\n",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_NetworkManager::RebuildThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100727C0
// Name: public: static void CAI_NetworkManager::InitializeAINetworks(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_NetworkManager::InitializeAINetworks()
{
  CBaseEntity *EntityByName; // eax
  CAI_NetworkManager *v1; // esi
  CAI_Network *m_pNetwork; // eax
  string_t v3; // eax
  const char *v4; // ebx
  CBaseEdict *v5; // ecx
  const char *v6; // eax
  int pszValue; // [esp+4h] [ebp-4h] BYREF

  EntityByName = CreateEntityByName(className: "ai_network", iForceEdictIndex: -1, bNotify: true);
  v1 = (CAI_NetworkManager *)__RTDynamicCast(
                               inptr: EntityByName,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CAI_NetworkManager `RTTI Type Descriptor',
                               isReference: 0);
  if ( v1 == nullptr )
    _Warning(a1: "classname %s used to create wrong class type\n", "ai_network");
  g_pAINetworkManager = v1;
  m_pNetwork = v1->m_pNetwork;
  v1->m_iEFlags |= 0x10u;
  g_pBigAINet = m_pNetwork;
  v3.pszValue = AllocPooledString((const char *)&pszValue).pszValue;
  v4 = *(const char **)v3.pszValue;
  if ( v1->m_iName.m_Value.pszValue != *(const char **)v3.pszValue )
  {
    if ( v1->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v1->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = &v1->m_Network.m_pPev->CBaseEdict;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: 0xCCu);
    }
    v1->m_iName.m_Value.pszValue = v4;
  }
  CGlobalEntityList::UpdateName(this: &gEntList, pEnt: v1);
  v1->Spawn(this: v1);
  if ( engine->IsInEditMode(this: engine) != 0 )
    CCollisionProperty::TestCollision(this: (ConVar *)&g_ai_norebuildgraph.IConVar, value: 0);
  v6 = gpGlobals->mapname.pszValue;
  if ( v6 == nullptr )
    v6 = locale;
  if ( CAI_NetworkManager::IsAIFileCurrent(szMapName: v6) != 0 )
  {
    CAI_NetworkManager::LoadNetworkGraph(this: v1);
    if ( !g_bAIDisabledByUser )
      CAI_BaseNPC::m_nDebugBits &= ~1u;
  }
  CNodeEnt::m_nNodeCount = 0;
  if ( g_ai_threadedgraphbuild.m_pParent != nullptr
    && g_ai_threadedgraphbuild.m_pParent->m_Value.m_nValue != 0
    && engine->IsInEditMode(this: engine) == 0 )
  {
    CBaseEntity::ThinkSet(
      this: v1,
      func: (void (__thiscall *)(CBaseEntity *))CAI_NetworkManager::ThreadedInit,
      thinkTime: 0.0,
      szContext: nullptr);
  }
  else
  {
    CBaseEntity::ThinkSet(
      this: v1,
      func: (void (__thiscall *)(CBaseEntity *))CAI_NetworkManager::DelayedInit,
      thinkTime: 0.0,
      szContext: nullptr);
  }
  pszValue = 0;
  CBaseEntity::SetNextThink(this: v1, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10072940
// Name: public: void CAI_NetworkEditTools::DrawAINetworkOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_NetworkEditTools::DrawAINetworkOverlay(CAI_NetworkEditTools *this@<ecx>, double a2@<esi:edi>)
{
  int m_iNumNodes; // eax
  CBasePlayer *v3; // eax
  CAI_Network *m_pNetwork; // ecx
  int v5; // eax
  int m_pAInode; // ebx
  CAI_NetworkEditTools *v7; // ebx
  int v8; // eax
  __int16 *v9; // ecx
  __int16 v10; // cx
  Vector *v11; // eax
  int v12; // ecx
  __int16 *v13; // eax
  int v14; // ecx
  float *v15; // edx
  float v16; // xmm0_4
  int v17; // ecx
  char v18; // al
  CAI_Node *v19; // ecx
  int m_debugNetOverlays; // eax
  int v21; // eax
  CAI_Node **v22; // ecx
  CAI_Link *v23; // esi
  __int16 m_iSrcID; // ax
  int v25; // edi
  CAI_Node *v26; // ecx
  bool v27; // zf
  bool v28; // sf
  NodeType_e v29; // edi
  NodeType_e v30; // ecx
  unsigned __int8 m_LinkInfo; // dl
  unsigned __int8 v32; // cl
  unsigned __int8 v33; // dl
  unsigned __int8 v34; // al
  int v35; // eax
  char v36; // dl
  int v37; // esi
  int v38; // eax
  int m_iAcceptedMoveTypes; // edx
  _BYTE *v40; // ecx
  int v41; // eax
  _BYTE *v42; // ecx
  CAI_Node *v43; // edx
  int v44; // eax
  int v45; // edi
  int v46; // esi
  int v47; // eax
  int m_eNodeInfo; // ecx
  NodeType_e m_eNodeType; // eax
  __m128 m_flYaw_low; // xmm0
  double v51; // xmm0_8
  double v52; // xmm0_8
  CAI_Node **v53; // esi
  int *m_pNodeIndexTable; // ecx
  CAI_Hint *m_pHint; // eax
  const char *pszValue; // eax
  CAI_NetworkEditTools *v57; // esi
  CAI_Network *v58; // ecx
  CFmtStrN<256> msg; // [esp+14h] [ebp-20Ch] BYREF
  Vector result; // [esp+120h] [ebp-100h] BYREF
  CGameTrace tr; // [esp+12Ch] [ebp-F4h] BYREF
  float v62; // [esp+180h] [ebp-A0h]
  Vector mins; // [esp+18Ch] [ebp-94h] BYREF
  Vector target; // [esp+198h] [ebp-88h] BYREF
  Vector srcPos; // [esp+1A4h] [ebp-7Ch] BYREF
  Vector desPos; // [esp+1B0h] [ebp-70h] BYREF
  int v67; // [esp+1BCh] [ebp-64h]
  int v68; // [esp+1C0h] [ebp-60h]
  Vector vSource; // [esp+1C4h] [ebp-5Ch] BYREF
  int moveTypes; // [esp+1D0h] [ebp-50h]
  Vector hullMins; // [esp+1D4h] [ebp-4Ch] BYREF
  int link; // [esp+1E0h] [ebp-40h]
  Vector vecAbsEnd; // [esp+1E4h] [ebp-3Ch] BYREF
  Vector loc; // [esp+1F0h] [ebp-30h] BYREF
  bool bIsLastResort; // [esp+1FFh] [ebp-21h]
  CAI_Node **pAINode; // [esp+200h] [ebp-20h]
  Vector nodePos; // [esp+204h] [ebp-1Ch] BYREF
  CAI_Node **v78; // [esp+210h] [ebp-10h]
  bool isJump; // [esp+216h] [ebp-Ah]
  bool isFly; // [esp+217h] [ebp-9h]
  int node; // [esp+218h] [ebp-8h]
  CAI_NetworkEditTools *v82; // [esp+21Ch] [ebp-4h]
  IHandleEntity savedregs; // [esp+220h] [ebp+0h] BYREF

  LODWORD(a2) = this;
  v82 = this;
  if ( CAI_NetworkManager::gm_fNetworksLoaded )
  {
    m_iNumNodes = this->m_pNetwork->m_iNumNodes;
    flDrawDuration = (double)(m_iNumNodes - 1) * 0.1 * 0.05;
    endDrawNode = startDrawNode + 20;
    if ( flDrawDuration < 0.1 )
      flDrawDuration = 0.1;
    if ( startDrawNode + 20 > m_iNumNodes )
      endDrawNode = m_iNumNodes;
    if ( (this->m_debugNetOverlays & 0x40) != 0 )
    {
      v3 = UTIL_PlayerByIndex(playerIndex: CBaseEntity::m_nDebugPlayer);
      HIDWORD(a2) = v3;
      if ( v3 != nullptr )
      {
        v3->EyePosition(this: v3, result: &vSource);
        CBasePlayer::EyeVectors(this: (CBasePlayer *)HIDWORD(a2), pForward: &hullMins, pRight: nullptr, pUp: nullptr);
        vecAbsEnd.y = vSource.y + (float)(hullMins.y * 2048.0);
        vecAbsEnd.x = vSource.x + (float)(hullMins.x * 2048.0);
        vecAbsEnd.z = vSource.z + (float)(hullMins.z * 2048.0);
        UTIL_TraceLine(
          a1: &savedregs,
          a2: SHIDWORD(a2),
          vecAbsStart: &vSource,
          &vecAbsEnd,
          mask: 0x200400Bu,
          ignore: (const IHandleEntity *)HIDWORD(a2),
          collisionGroup: 0,
          ptr: &tr);
        if ( tr.fraction != 1.0
          && (float)((float)((float)(tr.plane.normal.x + tr.plane.normal.y) * 0.0) + tr.plane.normal.z) > 0.5 )
        {
          vecAbsEnd.x = tr.endpos.x;
          vecAbsEnd.y = tr.endpos.y;
          vecAbsEnd.z = tr.endpos.z + 1.0;
          NDebugOverlay::Grid(vPosition: &vecAbsEnd);
        }
      }
    }
    m_pNetwork = *(CAI_Network **)(LODWORD(a2) + 20);
    v5 = *(_DWORD *)(LODWORD(a2) + 8);
    m_pAInode = (int)m_pNetwork->m_pAInode;
    pAINode = (CAI_Node **)m_pAInode;
    if ( (v5 & 0x20) != 0 )
    {
      if ( (v5 & 0x10000000) != 0 )
      {
        CAI_NetworkManager::RebuildNetworkGraph(this: *(CAI_NetworkManager **)(LODWORD(a2) + 16));
      }
      else if ( CAI_NetworkEditTools::m_iGConnectivityNode != -1 )
      {
        HIDWORD(a2) = 0;
        if ( m_pNetwork->m_iNumNodes > 0 )
        {
          LODWORD(a2) = m_pAInode;
          v7 = v82;
          do
          {
            if ( CAI_Network::IsConnected(
                   this: m_pNetwork,
                   srcID: CAI_NetworkEditTools::m_iGConnectivityNode,
                   destID: SHIDWORD(a2)) )
            {
              CAI_Node::GetPosition(
                this: *(CAI_Node **)(LODWORD(a2) + 4 * CAI_NetworkEditTools::m_iGConnectivityNode),
                result: &srcPos,
                hull: CAI_NetworkEditTools::m_iHullDrawNum);
              CAI_Node::GetPosition(
                this: *(CAI_Node **)(LODWORD(a2) + 4 * HIDWORD(a2)),
                result: &desPos,
                hull: CAI_NetworkEditTools::m_iHullDrawNum);
              NDebugOverlay::Line(
                origin: &srcPos,
                target: &desPos,
                r: 255,
                g: 0,
                b: 255,
                noDepthTest: false,
                duration: 0.0);
            }
            m_pNetwork = v7->m_pNetwork;
            ++HIDWORD(a2);
          }
          while ( SHIDWORD(a2) < m_pNetwork->m_iNumNodes );
          m_pAInode = LODWORD(a2);
          LODWORD(a2) = v82;
        }
      }
    }
    v8 = *(_DWORD *)(LODWORD(a2) + 8);
    if ( (v8 & 4) != 0 )
    {
      if ( (v8 & 0x10000000) != 0 )
      {
        CAI_NetworkManager::RebuildNetworkGraph(this: *(CAI_NetworkManager **)(LODWORD(a2) + 16));
      }
      else
      {
        node = startDrawNode;
        if ( startDrawNode < endDrawNode )
        {
          LODWORD(a2) = m_pAInode + 4 * startDrawNode;
          do
          {
            HIDWORD(a2) = 0;
            if ( *(int *)(*(_DWORD *)LODWORD(a2) + 92) > 0 )
            {
              do
              {
                v9 = *(__int16 **)(*(_DWORD *)(*(_DWORD *)LODWORD(a2) + 80) + 4 * HIDWORD(a2));
                if ( node == *v9 )
                  v10 = v9[1];
                else
                  v10 = *v9;
                m_pAInode = (int)pAINode;
                if ( v10 < node )
                {
                  CAI_Node::GetPosition(
                    this: pAINode[**(__int16 **)(*(_DWORD *)(*(_DWORD *)LODWORD(a2) + 80) + 4 * HIDWORD(a2))],
                    result: &vecAbsEnd,
                    hull: CAI_NetworkEditTools::m_iHullDrawNum);
                  CAI_Node::GetPosition(
                    this: *(CAI_Node **)(m_pAInode
                                 + 4
                                 * *(__int16 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)LODWORD(a2) + 80) + 4 * HIDWORD(a2))
                                              + 2)),
                    result: &vSource,
                    hull: CAI_NetworkEditTools::m_iHullDrawNum);
                  loc.x = vSource.x - vecAbsEnd.x;
                  loc.y = vSource.y - vecAbsEnd.y;
                  loc.z = vSource.z - vecAbsEnd.z;
                  *(float *)&link = VectorNormalize(vec: &loc);
                  hullMins = *NAI_Hull::Mins(id: CAI_NetworkEditTools::m_iHullDrawNum);
                  v11 = NAI_Hull::Maxs(id: CAI_NetworkEditTools::m_iHullDrawNum);
                  v12 = *(_DWORD *)LODWORD(a2);
                  nodePos = *v11;
                  nodePos.x = nodePos.x + *(float *)&link;
                  if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v12 + 80) + 4 * HIDWORD(a2))
                                 + CAI_NetworkEditTools::m_iHullDrawNum
                                 + 4)
                      & 4) != 0 )
                    NDebugOverlay::BoxDirection(
                      origin: &vecAbsEnd,
                      mins: &hullMins,
                      maxs: &nodePos,
                      orientation: &loc,
                      r: 100,
                      g: 255,
                      b: 255,
                      a: 20,
                      duration: flDrawDuration);
                  if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)LODWORD(a2) + 80) + 4 * HIDWORD(a2))
                                 + CAI_NetworkEditTools::m_iHullDrawNum
                                 + 4)
                      & 8) != 0 )
                  {
                    v13 = *(__int16 **)(*(_DWORD *)(*(_DWORD *)LODWORD(a2) + 80) + 4 * HIDWORD(a2));
                    v14 = *(_DWORD *)(m_pAInode + 4 * v13[1]);
                    v15 = *(float **)(m_pAInode + 4 * *v13);
                    v16 = *(float *)(v14 + 4);
                    v17 = v14 + 4;
                    if ( v16 != v15[1] || *(float *)(v17 + 4) != v15[2] || *(float *)(v17 + 8) != v15[3] )
                    {
                      nodePos.x = nodePos.x - *(float *)&link;
                      if ( vSource.z <= vecAbsEnd.z )
                        hullMins.z = hullMins.z - *(float *)&link;
                      else
                        nodePos.z = nodePos.z + *(float *)&link;
                      loc.x = 0.0;
                      loc.y = 1.0;
                      loc.z = 0.0;
                    }
                    NDebugOverlay::BoxDirection(
                      origin: &vecAbsEnd,
                      mins: &hullMins,
                      maxs: &nodePos,
                      orientation: &loc,
                      r: 255,
                      g: 0,
                      b: 255,
                      a: 20,
                      duration: flDrawDuration);
                  }
                  v18 = *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)LODWORD(a2) + 80) + 4 * HIDWORD(a2))
                                 + CAI_NetworkEditTools::m_iHullDrawNum
                                 + 4);
                  if ( (v18 & 1) != 0 )
                  {
                    NDebugOverlay::BoxDirection(
                      origin: &vecAbsEnd,
                      mins: &hullMins,
                      maxs: &nodePos,
                      orientation: &loc,
                      r: 0,
                      g: 255,
                      b: 50,
                      a: 20,
                      duration: flDrawDuration);
                  }
                  else if ( (v18 & 2) != 0 )
                  {
                    NDebugOverlay::BoxDirection(
                      origin: &vecAbsEnd,
                      mins: &hullMins,
                      maxs: &nodePos,
                      orientation: &loc,
                      r: 0,
                      g: 0,
                      b: 255,
                      a: 20,
                      duration: flDrawDuration);
                  }
                  else if ( (v18 & 0x10) != 0 )
                  {
                    NDebugOverlay::Line(
                      origin: &vecAbsEnd,
                      target: &vSource,
                      r: 255,
                      g: 255,
                      b: 0,
                      noDepthTest: false,
                      duration: flDrawDuration);
                  }
                }
                ++HIDWORD(a2);
              }
              while ( SHIDWORD(a2) < *(_DWORD *)(*(_DWORD *)LODWORD(a2) + 92) );
            }
            LODWORD(a2) += 4;
            ++node;
          }
          while ( node < endDrawNode );
          LODWORD(a2) = v82;
        }
      }
    }
    if ( *(char *)(LODWORD(a2) + 8) < 0 )
      CAI_HintManager::DrawHintOverlays(a1: a2, flDrawDuration: flDrawDuration);
    if ( (*(_BYTE *)(LODWORD(a2) + 8) & 9) != 0 )
    {
      node = startDrawNode;
      if ( startDrawNode < endDrawNode )
      {
        v78 = (CAI_Node **)(m_pAInode + 4 * startDrawNode);
        while ( 1 )
        {
          v19 = *v78;
          if ( (*v78)->m_eNodeType == NODE_DELETED )
            goto LABEL_150;
          m_debugNetOverlays = v82->m_debugNetOverlays;
          if ( (m_debugNetOverlays & 8) != 0 )
          {
            if ( (m_debugNetOverlays & 0x10000000) != 0 )
            {
              CAI_NetworkManager::RebuildNetworkGraph(this: v82->m_pManager);
              goto LABEL_116;
            }
            *(float *)&v21 = 0.0;
            *(float *)&link = 0.0;
            if ( v19->m_Links.m_Size > 0 )
              break;
          }
LABEL_116:
          v44 = v82->m_debugNetOverlays;
          if ( (v44 & 1) != 0 )
          {
            v45 = 0;
            m_pAInode = 0;
            v46 = 255;
            if ( (v44 & 0x10) != 0 && CAI_NetworkEditTools::m_iVisibilityNode != -1 && (v44 & 0x10000000) != 0 )
              CAI_NetworkManager::RebuildNetworkGraph(this: v82->m_pManager);
            v47 = v82->m_debugNetOverlays;
            if ( (v47 & 0x20) != 0 && CAI_NetworkEditTools::m_iGConnectivityNode != -1 )
            {
              if ( (v47 & 0x10000000) != 0 )
              {
                CAI_NetworkManager::RebuildNetworkGraph(this: v82->m_pManager);
              }
              else if ( CAI_Network::IsConnected(
                          this: v82->m_pNetwork,
                          srcID: CAI_NetworkEditTools::m_iGConnectivityNode,
                          destID: node) )
              {
                v46 = 0;
                v45 = 0;
                m_pAInode = 255;
              }
              goto LABEL_138;
            }
            m_eNodeInfo = (*v78)->m_eNodeInfo;
            if ( (m_eNodeInfo & 0x20000000) != 0 )
            {
              v46 = 200;
              v45 = 200;
              m_pAInode = 200;
            }
            else if ( (m_eNodeInfo & 0x40000000) != 0 )
            {
              v45 = 25;
              m_pAInode = 25;
            }
            else
            {
              m_eNodeType = (*v78)->m_eNodeType;
              if ( m_eNodeType != NODE_CLIMB )
              {
                if ( m_eNodeType == NODE_AIR )
                {
                  v45 = 255;
                  m_pAInode = 255;
                }
                else
                {
                  if ( m_eNodeType != NODE_GROUND )
                    goto LABEL_138;
                  v45 = 255;
                  m_pAInode = 100;
                }
                v46 = 0;
                goto LABEL_138;
              }
              v45 = 0;
              m_pAInode = 255;
            }
LABEL_138:
            nodePos = *CAI_Node::GetPosition(this: *v78, &result, hull: CAI_NetworkEditTools::m_iHullDrawNum);
            vecAbsEnd.x = 5.0;
            vecAbsEnd.y = 5.0;
            vecAbsEnd.z = 5.0;
            mins.x = -5.0;
            mins.y = -5.0;
            mins.z = -5.0;
            NDebugOverlay::Box(
              origin: &nodePos,
              &mins,
              maxs: &vecAbsEnd,
              r: v46,
              g: v45,
              b: m_pAInode,
              a: 0,
              flDuration: flDrawDuration);
            if ( (*v78)->m_eNodeType == NODE_CLIMB )
            {
              m_flYaw_low = (__m128)LODWORD((*v78)->m_flYaw);
              m_flYaw_low.m128_f32[0] = m_flYaw_low.m128_f32[0] * 0.017453292;
              v68 = m_flYaw_low.m128_i32[0];
              __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(m_flYaw_low));
              *(float *)&v51 = v51;
              v62 = *(float *)&v51;
              __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)v68));
              *(float *)&v52 = v52;
              target.x = (float)(v62 * 12.0) + nodePos.x;
              target.y = (float)(*(float *)&v52 * 12.0) + nodePos.y;
              target.z = (float)(flDrawDuration * 12.0) + nodePos.z;
              NDebugOverlay::Line(
                origin: &nodePos,
                &target,
                r: v46,
                g: v45,
                b: m_pAInode,
                noDepthTest: false,
                duration: flDrawDuration);
            }
            v53 = v78;
            if ( (*v78)->m_pHint != nullptr )
            {
              srcPos.x = 7.0;
              srcPos.y = 7.0;
              srcPos.z = 7.0;
              desPos.x = -7.0;
              desPos.y = -7.0;
              desPos.z = -7.0;
              NDebugOverlay::Box(
                origin: &nodePos,
                mins: &desPos,
                maxs: &srcPos,
                r: 255,
                g: 255,
                b: 0,
                a: 0,
                flDuration: flDrawDuration);
            }
            if ( (v82->m_debugNetOverlays & 2) != 0 )
            {
              m_pNodeIndexTable = v82->m_pNodeIndexTable;
              msg.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
              *(_WORD *)&msg.m_bQuietTruncation = 1;
              msg.m_nLength = 0;
              if ( m_pNodeIndexTable != nullptr )
                CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
                  this: &msg,
                  pszFormat: "%i (wc:%i; z:%i)",
                  node,
                  m_pNodeIndexTable[(*v53)->m_iID],
                  (*v53)->m_zone);
              else
                CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
                  this: &msg,
                  pszFormat: "%i (z:%i)",
                  node,
                  (*v53)->m_zone);
              loc.x = nodePos.x + 6.0;
              loc.y = nodePos.y + 6.0;
              loc.z = nodePos.z + 6.0;
              NDebugOverlay::Text(origin: &loc, text: msg.m_szBuf, bViewCheck: true, duration: flDrawDuration);
              m_pHint = (*v53)->m_pHint;
              if ( m_pHint != nullptr )
              {
                pszValue = m_pHint->m_NodeData.strGroup.pszValue;
                if ( pszValue == nullptr )
                  pszValue = locale;
                CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "%s", pszValue);
                loc.z = loc.z - 3.0;
                NDebugOverlay::Text(origin: &loc, text: msg.m_szBuf, bViewCheck: true, duration: flDrawDuration);
              }
            }
          }
LABEL_150:
          ++v78;
          if ( ++node >= endDrawNode )
            goto LABEL_151;
        }
        v22 = v78;
        while ( 1 )
        {
          v23 = (*v22)->m_Links.m_Memory.m_pMemory[v21];
          m_iSrcID = v23->m_iSrcID;
          v25 = v23->m_iSrcID;
          if ( node == v25 )
            m_iSrcID = v23->m_iDestID;
          if ( m_iSrcID >= node )
            goto LABEL_115;
          m_pAInode = v23->m_iDestID;
          CAI_Node::GetPosition(this: pAINode[v25], result: &hullMins, hull: CAI_NetworkEditTools::m_iHullDrawNum);
          CAI_Node::GetPosition(this: pAINode[m_pAInode], result: &vSource, hull: CAI_NetworkEditTools::m_iHullDrawNum);
          v26 = pAINode[v25];
          v27 = v23->m_nDangerCount == 0;
          v28 = v23->m_nDangerCount < 0;
          v29 = pAINode[m_pAInode]->m_eNodeType;
          v30 = v26->m_eNodeType;
          m_LinkInfo = v23->m_LinkInfo;
          moveTypes = v23->m_iAcceptedMoveTypes[CAI_NetworkEditTools::m_iHullDrawNum];
          LOBYTE(m_pAInode) = !v28 && !v27;
          bIsLastResort = (m_LinkInfo & 8) != 0;
          if ( v30 == NODE_GROUND )
            hullMins.z = hullMins.z + 1.0;
          if ( v29 == NODE_GROUND )
            vSource.z = vSource.z + 1.0;
          if ( (m_LinkInfo & 1) != 0 )
          {
            v32 = -1;
            v33 = 0;
            v34 = 0;
          }
          else
          {
            if ( (m_LinkInfo & 2) == 0 )
            {
              if ( !v28 && !v27 )
              {
                v32 = -64;
                v33 = -64;
                v34 = 0;
                goto LABEL_112;
              }
              v35 = v82->m_debugNetOverlays;
              v67 = v35 & 0x200;
              v36 = moveTypes;
              if ( (v35 & 0x200) != 0 && (moveTypes & 4) != 0 )
              {
                v33 = -1;
                v34 = -1;
                goto LABEL_111;
              }
              if ( (moveTypes & 8) != 0 )
              {
                v32 = -1;
                v33 = 0;
                v34 = -1;
              }
              else if ( (moveTypes & 1) != 0 )
              {
                v32 = 0;
                v33 = -1;
                v34 = 50;
              }
              else
              {
                moveTypes = v35 & 0x400;
                if ( (v35 & 0x400) != 0 && (v36 & 0x10) != 0 )
                {
                  v32 = -1;
                  v33 = -1;
                  v34 = -1;
                }
                else
                {
                  v37 = v35 & 0x100;
                  if ( (v35 & 0x100) != 0 && (v36 & 2) != 0 )
                  {
                    v32 = 0;
                    v33 = 0;
                    v34 = -1;
                  }
                  else
                  {
                    if ( v30 == NODE_AIR || (isFly = false, v29 == NODE_AIR) )
                      isFly = true;
                    v38 = 0;
                    m_iAcceptedMoveTypes = (int)(*v78)->m_Links.m_Memory.m_pMemory[link]->m_iAcceptedMoveTypes;
                    isJump = true;
                    v40 = (_BYTE *)m_iAcceptedMoveTypes;
                    while ( (*v40 & 0xFD) == 0 )
                    {
                      ++v38;
                      ++v40;
                      if ( v38 >= 12 )
                        goto LABEL_96;
                    }
                    isJump = false;
LABEL_96:
                    LOBYTE(m_pAInode) = 1;
                    v41 = 0;
                    v42 = (_BYTE *)m_iAcceptedMoveTypes;
                    while ( (*v42 & 0xEF) == 0 )
                    {
                      ++v41;
                      ++v42;
                      if ( v41 >= 12 )
                        goto LABEL_101;
                    }
                    LOBYTE(m_pAInode) = 0;
LABEL_101:
                    if ( (!isFly || v67 == 0)
                      && (!isJump || v37 == 0)
                      && ((_BYTE)m_pAInode == 0 || moveTypes == 0)
                      && (isFly || isJump || (_BYTE)m_pAInode != 0) )
                    {
                      goto LABEL_115;
                    }
                    v33 = 25;
                    v34 = 25;
LABEL_111:
                    v32 = 100;
                  }
                }
              }
LABEL_112:
              if ( bIsLastResort )
              {
                v32 >>= 1;
                v33 >>= 1;
                v34 >>= 1;
              }
              goto LABEL_114;
            }
            v32 = 100;
            v33 = 100;
            v34 = 100;
          }
LABEL_114:
          NDebugOverlay::Line(
            origin: &hullMins,
            target: &vSource,
            r: v32,
            g: v33,
            b: v34,
            noDepthTest: false,
            duration: flDrawDuration);
LABEL_115:
          v22 = v78;
          v43 = *v78;
          v21 = link + 1;
          link = v21;
          if ( v21 >= v43->m_Links.m_Size )
            goto LABEL_116;
        }
      }
    }
LABEL_151:
    v57 = v82;
    if ( (v82->m_debugNetOverlays & 0xD) != 0 )
      CAI_NetworkEditTools::DrawEditInfoOverlay(this: v82, a2: m_pAInode, a3: (int)v82);
    v58 = v57->m_pNetwork;
    startDrawNode = endDrawNode;
    if ( endDrawNode >= v58->m_iNumNodes )
      startDrawNode = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DEDC0
// Name: protected: void CUtlBuffer::PutTypeBin<short>(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<short>(CUtlBuffer *this, __int16 src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 2) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned short>(
        this: &this->m_Byteswap,
        outputBuffer: (__int16 *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_WORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 2;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FCB40
// Name: CAI_NetworkManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_NetworkManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_NetworkManager>(__formal: nullptr);
  CAI_NetworkManager_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100735A0
// Name: struct datamap_t __near * DataMapInit<class CAI_NetworkManager>(class CAI_NetworkManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_NetworkManager>()
{
  if ( (_S2_26 & 1) == 0 )
  {
    _S2_26 |= 1u;
    nameHolder_55.m_pszBase = "CAI_NetworkManager";
    nameHolder_55.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_55.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_55.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_55.m_Names.m_Size = 0;
    nameHolder_55.m_Names.m_pElements = nullptr;
    nameHolder_55.m_nLenBase = 18;
    atexit(func: DataMapInit_CAI_NetworkManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_NetworkManager::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_26 & 2) == 0 )
  {
    _S2_26 |= 2u;
    dataDesc_53[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_55,
                                 pszIdentifier: "DelayedInit");
    dataDesc_53[3].flags = 32;
    dataDesc_53[3].fieldOffset = 0;
    dataDesc_53[3].fieldSize = 1;
    dataDesc_53[3].externalName = nullptr;
    dataDesc_53[3].pSaveRestoreOps = nullptr;
    dataDesc_53[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_NetworkManager::DelayedInit;
    *(_QWORD *)&dataDesc_53[3].td = 0;
    *(_QWORD *)&dataDesc_53[3].override_field = 0;
    *(_QWORD *)&dataDesc_53[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_53[3].flatOffset[1] = 0;
    dataDesc_53[4].fieldType = FIELD_VOID;
    dataDesc_53[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_55,
                                 pszIdentifier: "ThreadedInit");
    dataDesc_53[4].fieldOffset = 0;
    dataDesc_53[4].fieldSize = 1;
    dataDesc_53[4].flags = 32;
    dataDesc_53[4].externalName = nullptr;
    dataDesc_53[4].pSaveRestoreOps = nullptr;
    dataDesc_53[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_NetworkManager::ThreadedInit;
    *(_QWORD *)&dataDesc_53[4].td = 0;
    *(_QWORD *)&dataDesc_53[4].override_field = 0;
    *(_QWORD *)&dataDesc_53[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_53[4].flatOffset[1] = 0;
    dataDesc_53[5].fieldType = FIELD_VOID;
    dataDesc_53[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_55,
                                 pszIdentifier: "RebuildThink");
    dataDesc_53[5].fieldOffset = 0;
    *(_DWORD *)&dataDesc_53[5].fieldSize = 2097153;
    dataDesc_53[5].externalName = nullptr;
    dataDesc_53[5].pSaveRestoreOps = nullptr;
    dataDesc_53[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_NetworkManager::RebuildThink;
    *(_QWORD *)&dataDesc_53[5].td = 0;
    *(_QWORD *)&dataDesc_53[5].override_field = 0;
    *(_QWORD *)&dataDesc_53[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_53[5].flatOffset[1] = 0;
  }
  CAI_NetworkManager::m_DataMap.dataNumFields = 5;
  CAI_NetworkManager::m_DataMap.dataDesc = &dataDesc_53[1];
  return &CAI_NetworkManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FCB50
// Name: _dynamic_initializer_for__g_AINetworkBuilder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AINetworkBuilder__()
{
  if ( g_AINetworkBuilder.m_DidSetNeighborsTable.m_pInt != nullptr )
    memset(
      dst: (int)g_AINetworkBuilder.m_DidSetNeighborsTable.m_pInt,
      value: nullptr,
      count: 4 * g_AINetworkBuilder.m_DidSetNeighborsTable.m_numInts);
  return atexit(func: dynamic_atexit_destructor_for__g_AINetworkBuilder__);
}
