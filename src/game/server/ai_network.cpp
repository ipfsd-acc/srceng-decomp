// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_network.cpp
// Functions: 18
// ============================================================

#include "game\server\ai_network.h"

//------------------------------------------------------------------------------
// Address: 0x1006AAD0
// Name: public: static bool CNodeList::IsLowerPriority(struct AI_NearNode_t const __near &,struct AI_NearNode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CNodeList::IsLowerPriority(const AI_NearNode_t *node1, const AI_NearNode_t *node2)
{
  return node1->dist > node2->dist;
}

//------------------------------------------------------------------------------
// Address: 0x1006AAF0
// Name: public: virtual bool CNodeFilter::NodeIsValid(class CAI_Node __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNodeFilter::NodeIsValid(CNodeFilter *this, CAI_Node *node)
{
  CAI_BaseNPC *m_pNPC; // ecx
  NodeType_e m_eNodeType; // eax

  if ( node->m_eNodeType == NODE_DELETED )
    return false;
  m_pNPC = this->m_pNPC;
  if ( m_pNPC == nullptr )
    return true;
  if ( CAI_BaseNPC::GetNavType(this: m_pNPC) == NAV_FLY && node->m_eNodeType != NODE_AIR )
    return false;
  m_eNodeType = node->m_eNodeType;
  if ( m_eNodeType == NODE_AIR && (this->m_capabilities & 4) == 0 )
    return false;
  if ( m_eNodeType == NODE_GROUND && (this->m_capabilities & 1) == 0 )
    return false;
  return !this->m_pNPC->IsUnusableNode(this: this->m_pNPC, a2: node->m_iID, a3: node->m_pHint);
}

//------------------------------------------------------------------------------
// Address: 0x1006AB60
// Name: public: class Vector CAI_Network::GetNodePosition(enum Hull_t,int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_Network::GetNodePosition(CAI_Network *this, Vector *result, Hull_t hull, int nodeID)
{
  CAI_Node **m_pAInode; // edx

  m_pAInode = this->m_pAInode;
  if ( m_pAInode != nullptr )
  {
    if ( nodeID < 0 || nodeID > this->m_iNumNodes )
    {
      *result = vec3_origin;
      return result;
    }
    else
    {
      CAI_Node::GetPosition(this: m_pAInode[nodeID], result, hull);
      return result;
    }
  }
  else
  {
    *result = vec3_origin;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ABD0
// Name: public: float CAI_Network::GetNodeYaw(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Network::GetNodeYaw(CAI_Network *this, int nodeID)
{
  CAI_Node **m_pAInode; // edx

  m_pAInode = this->m_pAInode;
  if ( m_pAInode != nullptr && nodeID >= 0 && nodeID <= this->m_iNumNodes )
    return m_pAInode[nodeID]->m_flYaw;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1006AC00
// Name: public: class CAI_Node __near * CAI_Network::AddNode(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CAI_Node *__thiscall CAI_Network::AddNode(CAI_Network *this, const Vector *origin, float yaw)
{
  CAI_Node **m_pAInode; // eax
  CAI_Node *v5; // eax
  CAI_Node *v6; // eax

  m_pAInode = this->m_pAInode;
  if ( m_pAInode != nullptr )
  {
    if ( *m_pAInode != nullptr )
      goto LABEL_5;
    free(pMem: this->m_pAInode);
  }
  this->m_pAInode = (CAI_Node **)operator new(nSize: 0x1770u);
LABEL_5:
  if ( this->m_iNumNodes >= 1500 )
  {
    DevMsg(a1: "ERROR: too many nodes in map, deleting last node.\n", 1500);
    --this->m_iNumNodes;
  }
  v5 = (CAI_Node *)operator new(nSize: 0x70u);
  if ( v5 != nullptr )
    v6 = CAI_Node::CAI_Node(this: v5, id: this->m_iNumNodes, origin, yaw);
  else
    v6 = nullptr;
  this->m_pAInode[this->m_iNumNodes++] = v6;
  return this->m_pAInode[this->m_iNumNodes - 1];
}

//------------------------------------------------------------------------------
// Address: 0x1006ACA0
// Name: public: bool CAI_Network::IsConnected(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Network::IsConnected(CAI_Network *this, int srcID, int destID)
{
  int m_iNumNodes; // eax
  CAI_Node **m_pAInode; // eax
  int m_zone; // ecx
  int v7; // eax

  m_iNumNodes = this->m_iNumNodes;
  if ( srcID > m_iNumNodes || destID > m_iNumNodes )
  {
    DevMsg(a1: "IsConnected called with invalid node IDs!\n");
    return false;
  }
  if ( srcID == destID )
    return true;
  m_pAInode = this->m_pAInode;
  m_zone = m_pAInode[srcID]->m_zone;
  v7 = m_pAInode[destID]->m_zone;
  if ( m_zone == 1 || v7 == 1 )
    return false;
  if ( m_zone == 3 || v7 == 3 )
    return true;
  return m_zone == v7;
}

//------------------------------------------------------------------------------
// Address: 0x1006AD10
// Name: public: virtual float CNodeFilter::NodeDistanceSqr(class CAI_Node __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNodeFilter::NodeDistanceSqr(CNodeFilter *this, CAI_Node *node)
{
  CAI_BaseNPC *m_pNPC; // eax
  const Vector *m_pos; // esi
  Vector *Position; // eax
  double v5; // st7
  double v6; // st6
  double v7; // st5
  const Vector *v8; // eax
  Vector v10; // [esp+0h] [ebp-Ch] BYREF

  m_pNPC = this->m_pNPC;
  if ( m_pNPC != nullptr )
  {
    m_pos = this->m_pos;
    Position = CAI_Node::GetPosition(this: node, result: &v10, hull: m_pNPC->m_eHull);
    v5 = Position->x - m_pos->x;
    v6 = Position->y - m_pos->y;
    v7 = Position->z - m_pos->z;
  }
  else
  {
    v8 = this->m_pos;
    v5 = node->m_vOrigin.x - v8->x;
    v6 = node->m_vOrigin.y - v8->y;
    v7 = node->m_vOrigin.z - v8->z;
  }
  return v7 * v7 + v6 * v6 + v5 * v5;
}

//------------------------------------------------------------------------------
// Address: 0x1006AD80
// Name: public: CAI_Network::CAI_Network(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Network *__thiscall CAI_Network::CAI_Network(CAI_Network *this)
{
  CAI_Network *result; // eax
  float *p_expiration; // edx
  int i; // ecx

  result = this;
  this->m_iNumNodes = 0;
  this->m_pAInode = nullptr;
  this->__vftable = (CAI_Network_vtbl *)&CAI_Network::`vftable';
  this->m_iNearestCacheNext = 31;
  p_expiration = &this->m_NearestCache[0].expiration;
  for ( i = 32; i != 0; --i )
  {
    *((_DWORD *)p_expiration + 2) = 13;
    *p_expiration = 1.1754944e-38;
    p_expiration += 6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006ADD0
// Name: public: class Vector CAI_Network::GetNodePosition(class CBaseCombatCharacter __near *,int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_Network::GetNodePosition(
        CAI_Network *this,
        Vector *result,
        CBaseCombatCharacter *pNPC,
        int nodeID)
{
  if ( pNPC != nullptr )
    CAI_Network::GetNodePosition(this, result, hull: pNPC->m_eHull, nodeID);
  else
    *result = vec3_origin;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AE20
// Name: public: class CAI_Link __near * CAI_Network::CreateLink(int,int,class CAI_DynamicLink __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Link *__thiscall CAI_Network::CreateLink(CAI_Network *this, int srcID, int destID, CAI_DynamicLink *pDynamicLink)
{
  CAI_Node *v4; // ebx
  CAI_Node *v5; // edi
  CAI_Link *v7; // eax
  CAI_Link *v8; // esi

  if ( srcID < 0 || srcID >= this->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    v4 = nullptr;
  }
  else
  {
    v4 = this->m_pAInode[srcID];
  }
  if ( destID < 0 || destID >= this->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    v5 = nullptr;
  }
  else
  {
    v5 = this->m_pAInode[destID];
  }
  if ( v4 != nullptr && v5 != nullptr )
  {
    if ( v4 == v5 )
    {
      DevMsg(a1: "Attempted to link a node to itself\n");
      return nullptr;
    }
    else if ( v4->m_Links.m_Size == 30 )
    {
      DevMsg(a1: "Node %d has too many links\n", srcID);
      return nullptr;
    }
    else if ( v5->m_Links.m_Size == 30 )
    {
      DevMsg(a1: "Node %d has too many links\n", destID);
      return nullptr;
    }
    else
    {
      v7 = (CAI_Link *)operator new(nSize: 0x20u);
      if ( v7 != nullptr )
        v8 = CAI_Link::CAI_Link(this: v7);
      else
        v8 = nullptr;
      v8->m_iSrcID = srcID;
      v8->m_iDestID = destID;
      v8->m_pDynamicLink = pDynamicLink;
      CAI_Node::AddLink(this: v4, newLink: v8);
      CAI_Node::AddLink(this: v5, newLink: v8);
      return v8;
    }
  }
  else
  {
    DevMsg(a1: "Attempted to create link to node that doesn't exist\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AF30
// Name: public: static int CAI_Network::FindBSSmallest(class CVarBitVec __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CAI_Network::FindBSSmallest(CVarBitVec *bitString, float *float_array, int array_size)
{
  float v3; // xmm0_4
  float *v4; // eax
  int v5; // edi
  int v6; // edx
  int v7; // ecx
  unsigned int *m_pInt; // ebx
  int v9; // esi
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  float *v14; // [esp+0h] [ebp-8h]
  int winIndex; // [esp+4h] [ebp-4h]

  v3 = 3.4028235e38;
  v4 = float_array;
  v5 = array_size;
  v6 = 0;
  winIndex = -1;
  v7 = 1;
  if ( array_size >= 4 )
  {
    m_pInt = bitString->m_pInt;
    v9 = 2;
    v14 = float_array + 2;
    do
    {
      if ( (v7 & m_pInt[v6 >> 5]) != 0 && v3 > *(v14 - 2) )
      {
        winIndex = v6;
        v3 = *(v14 - 2);
      }
      v10 = __ROL4__(v7, 1);
      if ( (v10 & m_pInt[(v9 - 1) >> 5]) != 0 && v3 > *(v14 - 1) )
      {
        winIndex = v9 - 1;
        v3 = *(v14 - 1);
      }
      v11 = __ROL4__(v10, 1);
      if ( (v11 & m_pInt[v9 >> 5]) != 0 && v3 > *v14 )
      {
        winIndex = v9;
        v3 = *v14;
      }
      v12 = __ROL4__(v11, 1);
      if ( (v12 & m_pInt[(v9 + 1) >> 5]) != 0 && v3 > v14[1] )
      {
        winIndex = v9 + 1;
        v3 = v14[1];
      }
      v5 = array_size;
      v14 += 4;
      v6 += 4;
      v7 = __ROL4__(v12, 1);
      v9 += 4;
    }
    while ( v6 < array_size - 3 );
    v4 = float_array;
  }
  for ( ; v6 < v5; v7 = __ROL4__(v7, 1) )
  {
    if ( (v7 & bitString->m_pInt[v6 >> 5]) != 0 && v3 > v4[v6] )
    {
      winIndex = v6;
      v3 = v4[v6];
    }
    ++v6;
  }
  return winIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1006B050
// Name: private: int CAI_Network::GetCachedNode(class Vector const __near &,enum Hull_t,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Network::GetCachedNode(CAI_Network *this, const Vector *checkPos, Hull_t nHull, int *pCachePos)
{
  int v5; // esi
  int v6; // eax
  char *v7; // edx

  if ( ai_no_node_cache.m_pParent != nullptr && ai_no_node_cache.m_pParent->m_Value.m_nValue != 0 )
    return -2;
  v5 = 0;
  while ( 1 )
  {
    v6 = (v5 + this->m_iNearestCacheNext + 1) % 32;
    v7 = (char *)this + 24 * v6;
    if ( *((_DWORD *)v7 + 8) == nHull
      && *((float *)v7 + 6) > gpGlobals->curtime
      && (float)((float)((float)((float)(*((float *)v7 + 3) - checkPos->x) * (float)(*((float *)v7 + 3) - checkPos->x))
                       + (float)((float)(*((float *)v7 + 4) - checkPos->y) * (float)(*((float *)v7 + 4) - checkPos->y)))
               + (float)((float)(*((float *)v7 + 5) - checkPos->z) * (float)(*((float *)v7 + 5) - checkPos->z))) < 576.0 )
    {
      break;
    }
    if ( ++v5 >= 32 )
    {
      if ( pCachePos != nullptr )
        *pCachePos = -1;
      return -2;
    }
  }
  if ( pCachePos != nullptr )
    *pCachePos = v6;
  return this->m_NearestCache[v6].node;
}

//------------------------------------------------------------------------------
// Address: 0x1006B120
// Name: private: int CAI_Network::GetCachedNearestNode(class Vector const __near &,class CAI_BaseNPC __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Network::GetCachedNearestNode(
        CAI_Network *this,
        const Vector *checkPos,
        CAI_BaseNPC *pNPC,
        int *pCachePos)
{
  int (__thiscall *CapabilitiesGet)(CAI_BaseNPC *); // edx
  int CachedNode; // edi
  CNodeFilter filter; // [esp+Ch] [ebp-10h] BYREF

  if ( pNPC != nullptr
    && (CapabilitiesGet = pNPC->CapabilitiesGet,
        filter.__vftable = (CNodeFilter_vtbl *)&CNodeFilter::`vftable',
        filter.m_pos = checkPos,
        filter.m_pNPC = pNPC,
        filter.m_capabilities = CapabilitiesGet(this: pNPC),
        (CachedNode = CAI_Network::GetCachedNode(this, checkPos, nHull: pNPC->m_eHull, pCachePos)) >= 0)
    && CNodeFilter::NodeIsValid(this: &filter, node: this->m_pAInode[CachedNode])
    && CAI_Navigator::CanFitAtNode(this: pNPC->m_pNavigator, nodeNum: CachedNode, collisionMask: 0x2400Bu) )
  {
    return CachedNode;
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B1B0
// Name: private: void CAI_Network::SetCachedNearestNode(class Vector const __near &,int,enum Hull_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Network::SetCachedNearestNode(CAI_Network *this, const Vector *checkPos, int nodeID, Hull_t nHull)
{
  int m_iNearestCacheNext; // eax
  CAI_Network::NearNodeCache_T *v5; // eax

  if ( ai_no_node_cache.m_pParent == nullptr || ai_no_node_cache.m_pParent->m_Value.m_nValue == 0 )
  {
    m_iNearestCacheNext = this->m_iNearestCacheNext;
    this->m_NearestCache[m_iNearestCacheNext].vTestPosition.x = checkPos->x;
    v5 = &this->m_NearestCache[m_iNearestCacheNext];
    v5->vTestPosition.y = checkPos->y;
    v5->vTestPosition.z = checkPos->z;
    this->m_NearestCache[this->m_iNearestCacheNext].node = nodeID;
    this->m_NearestCache[this->m_iNearestCacheNext].hull = nHull;
    this->m_NearestCache[this->m_iNearestCacheNext].expiration = gpGlobals->curtime + 10.0;
    if ( --this->m_iNearestCacheNext < 0 )
      this->m_iNearestCacheNext = 31;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B3E0
// Name: private: int CAI_Network::ListNodesInBox(class CNodeList __near &,int,class Vector const __near &,class Vector const __near &,class INodeListFilter __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Network::ListNodesInBox(
        CAI_Network *this,
        CNodeList *list,
        int maxListCount,
        const Vector *mins,
        const Vector *maxs,
        INodeListFilter *pFilter)
{
  int v6; // edi
  CAI_Node *v8; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  double v12; // st7
  float v13; // xmm0_4
  int m_Size; // esi
  CNodeList v16; // [esp+0h] [ebp-2Ch] BYREF
  AI_NearNode_t element; // [esp+18h] [ebp-14h] BYREF
  float flDist; // [esp+20h] [ebp-Ch]
  float flClosest; // [esp+24h] [ebp-8h]
  bool full; // [esp+2Bh] [ebp-1h]

  v6 = 0;
  memset(&v16, 0, 20);
  v16.m_LessFunc = CThinkSyncTester::ThinkLessFunc;
  full = false;
  flClosest = 1.0e12;
  if ( this->m_iNumNodes > 0 )
  {
    while ( 1 )
    {
      v8 = this->m_pAInode[v6];
      x = v8->m_vOrigin.x;
      if ( mins->x <= x )
      {
        if ( x > maxs->x )
          goto LABEL_15;
        y = v8->m_vOrigin.y;
        if ( mins->y > y )
          goto LABEL_15;
        if ( y > maxs->y )
          goto LABEL_15;
        z = v8->m_vOrigin.z;
        if ( mins->z > z || z > maxs->z || pFilter->NodeIsValid(this: pFilter, a2: this->m_pAInode[v6]) == 0 )
          goto LABEL_15;
        v12 = ((double (__thiscall *)(INodeListFilter *, CAI_Node *))pFilter->NodeDistanceSqr)(a1: pFilter, a2: v8);
        flDist = v12;
        v13 = flDist;
        if ( flClosest > v12 )
          flClosest = flDist;
        if ( !full )
          goto LABEL_14;
        if ( v16.m_heap.m_Memory.m_pMemory->dist > flDist )
          break;
      }
LABEL_15:
      if ( ++v6 >= this->m_iNumNodes )
        goto LABEL_16;
    }
    CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::RemoveAtHead(this: &v16);
    v13 = flDist;
LABEL_14:
    element.dist = v13;
    element.nodeIndex = v6;
    CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::Insert(
      this: &v16,
      &element);
    full = v16.m_heap.m_Size == maxListCount;
    goto LABEL_15;
  }
LABEL_16:
  list->m_heap.m_Size = 0;
  while ( v16.m_heap.m_Size != 0 )
  {
    CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::Insert(
      this: list,
      element: v16.m_heap.m_Memory.m_pMemory);
    CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::RemoveAtHead(this: &v16);
  }
  m_Size = list->m_heap.m_Size;
  if ( v16.m_heap.m_Memory.m_nGrowSize >= 0 && v16.m_heap.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16.m_heap.m_Memory.m_pMemory);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1006B550
// Name: public: int CAI_Network::NearestNodeToPoint(class CAI_BaseNPC __near *,class Vector const __near &,bool,class INearestNodeFilter __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Network::NearestNodeToPoint(
        CAI_Network *this,
        CAI_BaseNPC *pNPC,
        const Vector *vecOrigin,
        bool bCheckVisibility,
        INearestNodeFilter *pFilter)
{
  bool v5; // zf
  const Vector *v7; // edi
  int CachedNearestNode; // eax
  int v9; // ebx
  Hull_t m_eHull; // edi
  const Vector *v11; // ebx
  Vector *Position; // eax
  float v13; // xmm0_4
  Vector *p_vecVisOrigin; // eax
  __int64 v15; // xmm0_8
  unsigned int v16; // eax
  void *v17; // esp
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  int GetTraceType; // ebx
  Vector *(__thiscall *GetNodeViewOffset)(CAI_BaseNPC *, Vector *); // edx
  float *v27; // edi
  Vector *v28; // eax
  float v29; // xmm0_4
  Vector *p_vTestLoc; // eax
  __int64 v31; // xmm0_8
  float v32; // eax
  unsigned int v33; // eax
  Hull_t v34; // esi
  Hull_t v35; // esi
  _DWORD v36[23]; // [esp-50h] [ebp-134h] BYREF
  CGameTrace tr; // [esp+Ch] [ebp-D8h] BYREF
  Vector v38; // [esp+60h] [ebp-84h] BYREF
  CTraceFilterNav v39; // [esp+6Ch] [ebp-78h] BYREF
  Vector v40; // [esp+84h] [ebp-60h] BYREF
  CNodeFilter filter; // [esp+90h] [ebp-54h] BYREF
  Vector v42; // [esp+A0h] [ebp-44h] BYREF
  CTraceFilterNav traceFilter; // [esp+ACh] [ebp-38h] BYREF
  Vector vTestLoc; // [esp+C4h] [ebp-20h] BYREF
  int cachePos; // [esp+D0h] [ebp-14h] BYREF
  Vector vecVisOrigin; // [esp+D4h] [ebp-10h] BYREF
  CAI_Network *v47; // [esp+E0h] [ebp-4h]
  int savedregs; // [esp+E4h] [ebp+0h] BYREF
  int cachedNode; // [esp+ECh] [ebp+8h]

  v5 = this->m_iNumNodes == 0;
  v47 = this;
  if ( v5 )
    return -1;
  v7 = vecOrigin;
  CachedNearestNode = CAI_Network::GetCachedNearestNode(this, checkPos: vecOrigin, pNPC, pCachePos: &cachePos);
  v9 = CachedNearestNode;
  cachedNode = CachedNearestNode;
  if ( CachedNearestNode != -1 )
  {
    if ( !bCheckVisibility )
      goto LABEL_18;
    if ( pNPC != nullptr )
    {
      m_eHull = pNPC->m_eHull;
      v11 = pNPC->GetViewOffset(this: pNPC);
      Position = CAI_Node::GetPosition(this: v47->m_pAInode[cachedNode], result: &v42, hull: m_eHull);
      v7 = vecOrigin;
      vecVisOrigin.x = v11->x + Position->x;
      vecVisOrigin.y = v11->y + Position->y;
      v13 = v11->z + Position->z;
      v9 = cachedNode;
      vecVisOrigin.z = v13;
      p_vecVisOrigin = &vecVisOrigin;
    }
    else
    {
      p_vecVisOrigin = &v47->m_pAInode[CachedNearestNode]->m_vOrigin;
    }
    v15 = *(_QWORD *)&p_vecVisOrigin->x;
    vTestLoc.z = p_vecVisOrigin->z;
    *(_QWORD *)&vTestLoc.x = v15;
    CTraceFilterNav::CTraceFilterNav(
      this: &traceFilter,
      pProber: pNPC,
      bIgnoreTransientEntities: true,
      passedict: pNPC,
      collisionGroup: 0,
      bAllowPlayerAvoid: true);
    v16 = pNPC != nullptr ? pNPC->m_nAITraceMask & 0xFDFFFFFF : 147467;
    UTIL_TraceLine(
      a1: (int)&savedregs,
      a2: (int)pNPC,
      vecAbsStart: v7,
      vecAbsEnd: &vTestLoc,
      mask: v16,
      pFilter: &traceFilter,
      ptr: &tr);
    if ( tr.fraction == 1.0 )
    {
LABEL_18:
      if ( pFilter == nullptr || pFilter->IsValid(this: pFilter, a2: v47->m_pAInode[v9]) != 0 )
      {
        v47->m_NearestCache[cachePos].expiration = gpGlobals->curtime + 10.0;
        return v9;
      }
    }
    else
    {
      cachedNode = -1;
    }
  }
  filter.__vftable = (CNodeFilter_vtbl *)&CNodeFilter::`vftable';
  filter.m_pos = v7;
  filter.m_pNPC = pNPC;
  if ( pNPC != nullptr )
    filter.m_capabilities = pNPC->CapabilitiesGet(this: pNPC);
  v17 = alloca(80);
  x = 720.0;
  y = 720.0;
  z = 720.0;
  traceFilter.__vftable = (CTraceFilterNav_vtbl *)v36;
  traceFilter.m_pPassEnt = (const IHandleEntity *)10;
  traceFilter.m_collisionGroup = -1;
  traceFilter.m_pExtraShouldHitCheckFunction = nullptr;
  traceFilter.m_pProber = (CAI_BaseNPC *)v36;
  *(_DWORD *)&traceFilter.m_bIgnoreTransientEntities = CNodeList::IsLowerPriority;
  vecVisOrigin.x = 720.0;
  vecVisOrigin.y = 720.0;
  vecVisOrigin.z = 720.0;
  if ( pNPC != nullptr )
  {
    if ( (pNPC->CapabilitiesGet(this: pNPC) & 4) != 0 )
    {
      x = 1440.0;
      y = 1440.0;
      z = 1440.0;
    }
    else
    {
      z = vecVisOrigin.z;
      y = vecVisOrigin.y;
      x = vecVisOrigin.x;
    }
  }
  v22 = v7->x;
  vecVisOrigin.x = v7->x + x;
  v23 = v7->y;
  vecVisOrigin.y = v23 + y;
  v24 = v7->z;
  vecVisOrigin.z = v24 + z;
  vTestLoc.x = v22 - x;
  vTestLoc.y = v23 - y;
  vTestLoc.z = v24 - z;
  CAI_Network::ListNodesInBox(
    this: v47,
    list: (CNodeList *)&traceFilter,
    maxListCount: 10,
    mins: &vTestLoc,
    maxs: &vecVisOrigin,
    pFilter: &filter);
  if ( traceFilter.m_pExtraShouldHitCheckFunction == nullptr )
  {
LABEL_37:
    if ( pNPC != nullptr )
      v34 = pNPC->m_eHull;
    else
      v34 = HULL_NONE;
    CAI_Network::SetCachedNearestNode(this: v47, checkPos: v7, nodeID: -1, nHull: v34);
    if ( traceFilter.m_collisionGroup >= 0 && traceFilter.__vftable != nullptr )
      ((void (__thiscall *)(IMemAlloc *, CTraceFilterNav_vtbl *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_g_pMemAlloc->Free_2)(
        a1: _g_pMemAlloc,
        a2: traceFilter.__vftable,
        a3: v36[0],
        a4: v36[1],
        a5: v36[2],
        a6: v36[3],
        a7: v36[4],
        a8: v36[5],
        a9: v36[6],
        a10: v36[7],
        a11: v36[8],
        a12: v36[9],
        a13: v36[10],
        a14: v36[11],
        a15: v36[12],
        a16: v36[13],
        a17: v36[14],
        a18: v36[15],
        a19: v36[16],
        a20: v36[17],
        a21: v36[18],
        a22: v36[19]);
    return -1;
  }
  while ( 1 )
  {
    GetTraceType = (int)traceFilter.GetTraceType;
    if ( GetTraceType != cachedNode
      && (pNPC == nullptr
       || CAI_Navigator::CanFitAtNode(this: pNPC->m_pNavigator, nodeNum: GetTraceType, collisionMask: 0x2400Bu)) )
    {
      if ( !bCheckVisibility )
        break;
      if ( pNPC != nullptr )
      {
        GetNodeViewOffset = pNPC->GetNodeViewOffset;
        cachePos = pNPC->m_eHull;
        v27 = (float *)GetNodeViewOffset(this: pNPC, result: &v40);
        v28 = CAI_Node::GetPosition(this: v47->m_pAInode[GetTraceType], result: &v38, hull: cachePos);
        vTestLoc.x = v28->x + *v27;
        vTestLoc.y = v27[1] + v28->y;
        v29 = v27[2] + v28->z;
        v7 = vecOrigin;
        vTestLoc.z = v29;
        p_vTestLoc = &vTestLoc;
      }
      else
      {
        p_vTestLoc = &v47->m_pAInode[GetTraceType]->m_vOrigin;
      }
      v31 = *(_QWORD *)&p_vTestLoc->x;
      v32 = p_vTestLoc->z;
      *(_QWORD *)&v42.x = v31;
      vecVisOrigin.x = v7->x;
      vecVisOrigin.y = v7->y;
      *(float *)&v31 = v7->z + 1.0;
      v42.z = v32;
      LODWORD(vecVisOrigin.z) = v31;
      CTraceFilterNav::CTraceFilterNav(
        this: &v39,
        pProber: pNPC,
        bIgnoreTransientEntities: true,
        passedict: pNPC,
        collisionGroup: 0,
        bAllowPlayerAvoid: true);
      v33 = pNPC != nullptr ? pNPC->m_nAITraceMask & 0xFDFFFFFF : 147467;
      UTIL_TraceLine(
        a1: (int)&savedregs,
        a2: (int)pNPC,
        vecAbsStart: &vecVisOrigin,
        vecAbsEnd: &v42,
        mask: v33,
        pFilter: &v39,
        ptr: &tr);
      if ( tr.fraction == 1.0 )
        break;
    }
LABEL_36:
    CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::RemoveAtHead(this: (CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int> > *)&traceFilter);
    if ( traceFilter.m_pExtraShouldHitCheckFunction == nullptr )
      goto LABEL_37;
  }
  if ( pFilter != nullptr && pFilter->IsValid(this: pFilter, a2: v47->m_pAInode[GetTraceType]) == 0 )
  {
    if ( !pFilter->ShouldContinue(this: pFilter) )
      goto LABEL_37;
    goto LABEL_36;
  }
  if ( pNPC != nullptr )
    v35 = pNPC->m_eHull;
  else
    v35 = HULL_NONE;
  CAI_Network::SetCachedNearestNode(this: v47, checkPos: v7, nodeID: GetTraceType, nHull: v35);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&traceFilter);
  return GetTraceType;
}

//------------------------------------------------------------------------------
// Address: 0x1006B9D0
// Name: public: CAI_Network::~CAI_Network(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Network::~CAI_Network(CAI_Network *this)
{
  CAI_Network *v1; // esi
  int v2; // ebx
  int v3; // ecx
  CAI_Node *v4; // edi
  CAI_Link *v5; // esi
  __int16 m_iSrcID; // ax
  CAI_Node *v7; // ecx
  int i; // eax
  CAI_Link **m_pMemory; // edx
  bool v10; // zf
  CAI_Link **v11; // edx
  CAI_Link **v12; // eax
  int node; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  this->__vftable = (CAI_Network_vtbl *)&CAI_Network::`vftable';
  if ( this->m_pAInode != nullptr )
  {
    v3 = 0;
    node = 0;
    if ( v1->m_iNumNodes > 0 )
    {
      while ( 1 )
      {
        v4 = v1->m_pAInode[v3];
        if ( v4->m_Links.m_Size > 0 )
        {
          do
          {
            v5 = v4->m_Links.m_Memory.m_pMemory[v2];
            if ( v5 != nullptr )
            {
              m_iSrcID = v5->m_iSrcID;
              if ( v3 == v5->m_iSrcID )
                m_iSrcID = v5->m_iDestID;
              if ( m_iSrcID > v3 && m_iSrcID < this->m_iNumNodes )
              {
                v7 = this->m_pAInode[m_iSrcID];
                for ( i = 0; i < v7->m_Links.m_Size; ++i )
                {
                  m_pMemory = v7->m_Links.m_Memory.m_pMemory;
                  v10 = m_pMemory[i] == v5;
                  v11 = &m_pMemory[i];
                  if ( v10 )
                    *v11 = nullptr;
                }
              }
              free(pMem: v5);
              v3 = node;
            }
            ++v2;
          }
          while ( v2 < v4->m_Links.m_Size );
          v1 = this;
          v2 = 0;
        }
        v4->m_Links.m_Size = 0;
        if ( v4->m_Links.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4->m_Links.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Links.m_Memory.m_pMemory);
            v4->m_Links.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Links.m_Memory.m_nAllocationCount = 0;
        }
        v12 = v4->m_Links.m_Memory.m_pMemory;
        v4->m_Links.m_pElements = v12;
        if ( v4->m_Links.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v12 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
            v4->m_Links.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Links.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v4);
        if ( ++node >= v1->m_iNumNodes )
          break;
        v3 = node;
      }
    }
  }
  free(pMem: v1->m_pAInode);
  v1->m_pAInode = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006BAF0
// Name: public: int CAI_Network::NearestNodeToPoint(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Network::NearestNodeToPoint(CAI_Network *this, const Vector *vPosition, bool bCheckVisibility)
{
  return CAI_Network::NearestNodeToPoint(this, pNPC: nullptr, vecOrigin: vPosition, bCheckVisibility, pFilter: nullptr);
}
