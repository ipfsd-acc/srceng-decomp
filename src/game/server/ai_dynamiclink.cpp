// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_dynamiclink.cpp
// Functions: 32
// ============================================================

#include "game\server\ai_dynamiclink.h"

//------------------------------------------------------------------------------
// Address: 0x1004E9D0
// Name: public: virtual struct datamap_t __near * CAI_DynamicLinkController::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_DynamicLinkController::GetDataDescMap(CAI_DynamicLinkController *this)
{
  return &CAI_DynamicLinkController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1004E9E0
// Name: public: virtual struct datamap_t __near * CAI_DynamicLink::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_DynamicLink::GetDataDescMap(CAI_DynamicLink *this)
{
  return &CAI_DynamicLink::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1004E9F0
// Name: public: static class CAI_DynamicLink __near * CAI_DynamicLink::GetDynamicLink(int,int)
// Source: json
//------------------------------------------------------------------------------
CAI_DynamicLink *__cdecl CAI_DynamicLink::GetDynamicLink(int nSrcID, int nDstID)
{
  CAI_DynamicLink *result; // eax
  int m_nSrcID; // ecx

  result = CAI_DynamicLink::m_pAllDynamicLinks;
  if ( CAI_DynamicLink::m_pAllDynamicLinks == nullptr )
    return nullptr;
  while ( 1 )
  {
    m_nSrcID = result->m_nSrcID;
    if ( nSrcID == m_nSrcID && nDstID == result->m_nDestID )
      break;
    if ( nSrcID == result->m_nDestID && nDstID == m_nSrcID )
      break;
    result = result->m_pNextDynamicLink;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004EA30
// Name: public: virtual struct datamap_t __near * CAI_RadialLinkController::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_RadialLinkController::GetDataDescMap(CAI_RadialLinkController *this)
{
  return &CAI_RadialLinkController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1004EA40
// Name: public: static void CAI_DynamicLink::PurgeDynamicLinks(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_DynamicLink::PurgeDynamicLinks()
{
  CAI_DynamicLink *i; // esi
  int m_nSrcID; // eax
  CAI_Node *v2; // eax

  for ( i = CAI_DynamicLink::m_pAllDynamicLinks; i != nullptr; i = i->m_pNextDynamicLink )
  {
    m_nSrcID = i->m_nSrcID;
    if ( m_nSrcID < 0 || m_nSrcID >= g_pBigAINet->m_iNumNodes )
    {
      ++`CAI_Network::GetNode'::`8'::warningCount;
      v2 = nullptr;
    }
    else
    {
      v2 = g_pBigAINet->m_pAInode[m_nSrcID];
    }
    if ( CAI_Node::HasLink(this: v2, nNodeID: i->m_nDestID) == nullptr )
    {
      if ( Editor_DeleteNodeLink(
             nStartID: g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[i->m_nSrcID],
             nEndID: g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable[i->m_nDestID],
             bShowUI: false) == Editor_BadCommand )
        DevMsg(a1: "Worldcraft failed in PurgeDynamicLinks...\n");
      UTIL_Remove(oldObj: i);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EAF0
// Name: public: virtual int CAI_DynamicLink::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_DynamicLink::ObjectCaps(CAI_DynamicLink *this)
{
  int result; // eax

  result = CBaseEntity::ObjectCaps(this) & 0xFFFFFF7F;
  if ( this->m_bNotSaved )
    return result | 0x80000000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004EB10
// Name: public: CAI_DynamicLink::CAI_DynamicLink(void)
// Source: json
//------------------------------------------------------------------------------
CAI_DynamicLink *__thiscall CAI_DynamicLink::CAI_DynamicLink(CAI_DynamicLink *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  *(_WORD *)&this->m_bFixedUpIds = 0;
  this->m_nLinkState = LINK_OFF;
  this->m_bInvertAllow = false;
  this->__vftable = (CAI_DynamicLink_vtbl *)&CAI_DynamicLink::`vftable';
  this->m_nSrcID = -1;
  this->m_nDestID = -1;
  this->m_nLinkType = 1;
  this->m_pNextDynamicLink = CAI_DynamicLink::m_pAllDynamicLinks;
  CAI_DynamicLink::m_pAllDynamicLinks = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004EB70
// Name: public: virtual CAI_DynamicLink::~CAI_DynamicLink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_DynamicLink::~CAI_DynamicLink(CAI_DynamicLink *this)
{
  CAI_DynamicLink *v1; // eax
  CAI_DynamicLink *m_pNextDynamicLink; // edx

  this->__vftable = (CAI_DynamicLink_vtbl *)&CAI_DynamicLink::`vftable';
  v1 = CAI_DynamicLink::m_pAllDynamicLinks;
  if ( CAI_DynamicLink::m_pAllDynamicLinks == this )
  {
    CAI_DynamicLink::m_pAllDynamicLinks = CAI_DynamicLink::m_pAllDynamicLinks->m_pNextDynamicLink;
    CBaseEntity::~CBaseEntity(this);
  }
  else
  {
    if ( CAI_DynamicLink::m_pAllDynamicLinks != nullptr )
    {
      while ( 1 )
      {
        m_pNextDynamicLink = v1->m_pNextDynamicLink;
        if ( m_pNextDynamicLink == this )
          break;
        v1 = v1->m_pNextDynamicLink;
        if ( m_pNextDynamicLink == nullptr )
          goto LABEL_8;
      }
      v1->m_pNextDynamicLink = m_pNextDynamicLink->m_pNextDynamicLink;
    }
LABEL_8:
    CBaseEntity::~CBaseEntity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EBC0
// Name: public: virtual void CAI_RadialLinkController::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_RadialLinkController::Spawn(CAI_RadialLinkController *this)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x1004EBF0
// Name: public: class CAI_Link __near * CAI_DynamicLink::FindLink(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Link *__thiscall CAI_DynamicLink::FindLink(CAI_DynamicLink *this)
{
  int m_nSrcID; // ebx
  CAI_Node *v2; // eax
  int v3; // edi
  CAI_Link **i; // esi
  CAI_Link *result; // eax
  int m_iSrcID; // edx
  int numLinks; // [esp+Ch] [ebp-8h]

  m_nSrcID = this->m_nSrcID;
  if ( m_nSrcID < 0 )
    return nullptr;
  if ( m_nSrcID >= g_pBigAINet->m_iNumNodes )
    return nullptr;
  v2 = g_pBigAINet->m_pAInode[m_nSrcID];
  if ( v2 == nullptr )
    return nullptr;
  v3 = 0;
  numLinks = v2->m_Links.m_Size;
  if ( numLinks <= 0 )
    return nullptr;
  for ( i = v2->m_Links.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    m_iSrcID = (*i)->m_iSrcID;
    if ( m_iSrcID == m_nSrcID )
    {
      if ( result->m_iDestID == this->m_nDestID )
        return result;
      m_nSrcID = this->m_nSrcID;
    }
    if ( m_iSrcID == this->m_nDestID && result->m_iDestID == m_nSrcID )
      break;
    if ( ++v3 >= numLinks )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004EC70
// Name: public: void CAI_DynamicLink::SetLinkState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_DynamicLink::SetLinkState(CAI_DynamicLink *this)
{
  int m_nSrcID; // edi
  int m_nDestID; // ebx
  CAI_Link *Link; // eax
  CBaseEntity *v5; // ecx
  const char *DebugName; // eax
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  if ( CAI_DynamicLink::gm_bInitialized )
  {
    m_nSrcID = this->m_nSrcID;
    if ( m_nSrcID == -1 || (m_nDestID = this->m_nDestID) == -1 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      DevWarning(
        a1: "ERROR: Dynamic link at %f %f %f pointing to invalid node ID!!\n",
        this->m_vecAbsOrigin.x,
        this->m_vecAbsOrigin.y,
        this->m_vecAbsOrigin.z);
    }
    else if ( m_nSrcID >= 0 && m_nSrcID < g_pBigAINet->m_iNumNodes && g_pBigAINet->m_pAInode[m_nSrcID] != nullptr )
    {
      Link = CAI_DynamicLink::FindLink(this);
      if ( Link != nullptr )
      {
        Link->m_pDynamicLink = this;
        if ( this->m_nLinkState != LINK_OFF )
          Link->m_LinkInfo &= ~2u;
        else
          Link->m_LinkInfo |= 2u;
        if ( this->m_bPreciseMovement )
          Link->m_LinkInfo |= 4u;
        else
          Link->m_LinkInfo &= ~4u;
        if ( this->m_nPriority != 0 )
          Link->m_LinkInfo |= 8u;
        else
          Link->m_LinkInfo &= ~8u;
      }
      else
      {
        DebugName = CBaseEntity::GetDebugName(this: v5);
        DevMsg(a1: "Dynamic Link Error: (%s) unable to form between nodes %d and %d\n", DebugName, m_nSrcID, m_nDestID);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EDE0
// Name: public: void CAI_RadialLinkController::ModifyNodeLinks(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_RadialLinkController::ModifyNodeLinks(CAI_RadialLinkController *this, bool bMakeStale)
{
  int m_iNumNodes; // esi
  CAI_Node **m_pAInode; // eax
  int v4; // ebx
  CAI_Node *v5; // eax
  float v6; // xmm0_4
  const Vector *p_m_vOrigin; // edi
  float v8; // xmm1_4
  int v9; // ecx
  CAI_Link *v10; // esi
  __int16 m_iSrcID; // ax
  int v12; // edx
  char v13; // cl
  CAI_Node *v15; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float flRadius; // [esp+14h] [ebp-3Ch]
  Vector vecRayDelta; // [esp+28h] [ebp-28h] BYREF
  int nNodes; // [esp+34h] [ebp-1Ch]
  int nLinks; // [esp+38h] [ebp-18h]
  CAI_Node *pNode; // [esp+3Ch] [ebp-14h]
  int j; // [esp+40h] [ebp-10h]
  float MinDistCareSq; // [esp+44h] [ebp-Ch]
  CAI_Node **ppNodes; // [esp+48h] [ebp-8h]
  CAI_RadialLinkController *v29; // [esp+4Ch] [ebp-4h]

  m_iNumNodes = g_pBigAINet->m_iNumNodes;
  m_pAInode = g_pBigAINet->m_pAInode;
  v29 = this;
  nNodes = m_iNumNodes;
  ppNodes = m_pAInode;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ModifyLinks",
    a3: 0,
    a4: "ModifyLinks",
    a5: false,
    a6: 4);
  v4 = 0;
  for ( MinDistCareSq = (ai_radial_max_link_dist.m_pParent->m_Value.m_fValue + 0.1)
                      * (ai_radial_max_link_dist.m_pParent->m_Value.m_fValue + 0.1); v4 < m_iNumNodes; ++v4 )
  {
    v5 = ppNodes[v4];
    v6 = v29->m_vecAtRestOrigin.x - v5->m_vOrigin.x;
    p_m_vOrigin = &v5->m_vOrigin;
    v8 = (float)((float)((float)(v29->m_vecAtRestOrigin.y - v5->m_vOrigin.y)
                       * (float)(v29->m_vecAtRestOrigin.y - v5->m_vOrigin.y))
               + (float)(v6 * v6))
       + (float)((float)(v29->m_vecAtRestOrigin.z - v5->m_vOrigin.z)
               * (float)(v29->m_vecAtRestOrigin.z - v5->m_vOrigin.z));
    pNode = v5;
    if ( MinDistCareSq > v8 )
    {
      v9 = 0;
      nLinks = v5->m_Links.m_Size;
      j = 0;
      if ( nLinks > 0 )
      {
        while ( 1 )
        {
          v10 = v5->m_Links.m_Memory.m_pMemory[v9];
          m_iSrcID = v10->m_iSrcID;
          if ( v4 == v10->m_iSrcID )
            m_iSrcID = v10->m_iDestID;
          v12 = m_iSrcID;
          if ( m_iSrcID > v4 )
          {
            v13 = 1;
            if ( v10->m_iAcceptedMoveTypes[0] == 0 && v10->m_iAcceptedMoveTypes[2] == 0 )
              v13 = 0;
            v15 = ppNodes[v12];
            if ( v13 != 0 )
            {
              x = v15->m_vOrigin.x;
              y = v15->m_vOrigin.y;
              z = v15->m_vOrigin.z;
              if ( MinDistCareSq > (float)((float)((float)((float)(v29->m_vecAtRestOrigin.y - y)
                                                         * (float)(v29->m_vecAtRestOrigin.y - y))
                                                 + (float)((float)(v29->m_vecAtRestOrigin.x - x)
                                                         * (float)(v29->m_vecAtRestOrigin.x - x)))
                                         + (float)((float)(v29->m_vecAtRestOrigin.z - z)
                                                 * (float)(v29->m_vecAtRestOrigin.z - z))) )
              {
                v19 = y - p_m_vOrigin->y;
                v20 = z - p_m_vOrigin->z;
                flRadius = v29->m_flRadius;
                vecRayDelta.x = x - p_m_vOrigin->x;
                vecRayDelta.y = v19;
                vecRayDelta.z = v20;
                if ( IsRayIntersectingSphere(
                       vecRayOrigin: p_m_vOrigin,
                       &vecRayDelta,
                       vecCenter: &v29->m_vecAtRestOrigin,
                       flRadius,
                       flTolerance: 0.0) )
                {
                  if ( bMakeStale )
                  {
                    v10->m_LinkInfo |= 1u;
                    v10->m_timeStaleExpires = 3.4028235e38;
                  }
                  else
                  {
                    v10->m_LinkInfo &= ~1u;
                  }
                }
              }
            }
          }
          v9 = j + 1;
          j = v9;
          if ( v9 >= nLinks )
            break;
          v5 = pNode;
        }
        m_iNumNodes = nNodes;
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1004F040
// Name: public: void CAI_DynamicLinkController::InputSetAllowed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_DynamicLinkController::InputSetAllowed(CAI_DynamicLinkController *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax
  int v3; // edi
  unsigned int m_Index; // eax
  int m_Size; // edx
  unsigned int v6; // eax
  IHandleEntity *m_pEntity; // edx

  p_value = &inputdata->value;
  v3 = 0;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  this->m_strAllowUse.pszValue = (const char *)p_value->iVal;
  if ( this->m_ControlledLinks.m_Size > 0 )
  {
    do
    {
      m_Index = this->m_ControlledLinks.m_Memory.m_pMemory[v3].m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        m_Size = this->m_ControlledLinks.m_Size;
        if ( m_Size > 0 )
        {
          if ( v3 != m_Size - 1 )
            this->m_ControlledLinks.m_Memory.m_pMemory[v3].m_Index = this->m_ControlledLinks.m_Memory.m_pMemory[m_Size - 1].m_Index;
          --this->m_ControlledLinks.m_Size;
        }
        if ( v3 >= this->m_ControlledLinks.m_Size )
          break;
      }
      v6 = this->m_ControlledLinks.m_Memory.m_pMemory[v3].m_Index;
      if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
      ++v3;
      m_pEntity[219].__vftable = (IHandleEntity_vtbl *)this->m_strAllowUse.pszValue;
    }
    while ( v3 < this->m_ControlledLinks.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F130
// Name: public: void CAI_DynamicLinkController::InputSetInvert(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_DynamicLinkController::InputSetInvert(CAI_DynamicLinkController *this, inputdata_t *inputdata)
{
  bool v2; // al
  int v3; // edi
  unsigned int m_Index; // eax
  int m_Size; // edx
  unsigned int v6; // eax
  IHandleEntity *m_pEntity; // edx

  v2 = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
  v3 = 0;
  for ( this->m_bInvertAllow = v2;
        v3 < this->m_ControlledLinks.m_Size;
        LOBYTE(m_pEntity[220].__vftable) = this->m_bInvertAllow )
  {
    m_Index = this->m_ControlledLinks.m_Memory.m_pMemory[v3].m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      m_Size = this->m_ControlledLinks.m_Size;
      if ( m_Size > 0 )
      {
        if ( v3 != m_Size - 1 )
          this->m_ControlledLinks.m_Memory.m_pMemory[v3].m_Index = this->m_ControlledLinks.m_Memory.m_pMemory[m_Size - 1].m_Index;
        --this->m_ControlledLinks.m_Size;
      }
      if ( v3 >= this->m_ControlledLinks.m_Size )
        break;
    }
    v6 = this->m_ControlledLinks.m_Memory.m_pMemory[v3].m_Index;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F220
// Name: public: static void CAI_DynamicLink::ResetDynamicLinks(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_DynamicLink::ResetDynamicLinks()
{
  CAI_DynamicLink *i; // esi
  int m_nSrcID; // edi
  int m_nDestID; // ebx
  CAI_Link *Link; // eax
  CBaseEntity *v4; // ecx
  const char *DebugName; // eax
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  for ( i = CAI_DynamicLink::m_pAllDynamicLinks; i != nullptr; i = i->m_pNextDynamicLink )
  {
    if ( CAI_DynamicLink::gm_bInitialized )
    {
      m_nSrcID = i->m_nSrcID;
      if ( m_nSrcID == -1 || (m_nDestID = i->m_nDestID) == -1 )
      {
        if ( (i->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
        DevWarning(
          a1: "ERROR: Dynamic link at %f %f %f pointing to invalid node ID!!\n",
          i->m_vecAbsOrigin.x,
          i->m_vecAbsOrigin.y,
          i->m_vecAbsOrigin.z);
      }
      else if ( m_nSrcID >= 0 && m_nSrcID < g_pBigAINet->m_iNumNodes && g_pBigAINet->m_pAInode[m_nSrcID] != nullptr )
      {
        Link = CAI_DynamicLink::FindLink(this: i);
        if ( Link != nullptr )
        {
          Link->m_pDynamicLink = i;
          if ( i->m_nLinkState != LINK_OFF )
            Link->m_LinkInfo &= ~2u;
          else
            Link->m_LinkInfo |= 2u;
          if ( i->m_bPreciseMovement )
            Link->m_LinkInfo |= 4u;
          else
            Link->m_LinkInfo &= ~4u;
          if ( i->m_nPriority != 0 )
            Link->m_LinkInfo |= 8u;
          else
            Link->m_LinkInfo &= ~8u;
        }
        else
        {
          DebugName = CBaseEntity::GetDebugName(this: v4);
          DevMsg(
            a1: "Dynamic Link Error: (%s) unable to form between nodes %d and %d\n",
            DebugName,
            m_nSrcID,
            m_nDestID);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F370
// Name: public: void CAI_DynamicLink::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_DynamicLink::InputTurnOn(CAI_DynamicLink *this, inputdata_t *inputdata)
{
  if ( this->m_nLinkState == LINK_OFF )
  {
    this->m_nLinkState = LINK_ON;
    CAI_DynamicLink::SetLinkState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F390
// Name: public: void CAI_DynamicLink::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_DynamicLink::InputTurnOff(CAI_DynamicLink *this, inputdata_t *inputdata)
{
  if ( this->m_nLinkState == LINK_ON )
  {
    this->m_nLinkState = LINK_OFF;
    CAI_DynamicLink::SetLinkState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F3B0
// Name: public: void CAI_RadialLinkController::PollMotionThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_RadialLinkController::PollMotionThink(CAI_RadialLinkController *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  float v5; // xmm0_4
  _DWORD v6[3]; // [esp+28h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+34h] [ebp+0h]

  v6[0] = a2;
  v6[1] = retaddr;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
  m_Index = this->m_pParent.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      if ( (*((unsigned __int8 (__thiscall **)(IHandleEntity_vtbl *))m_pEntity[82].dtr_IHandleEntity + 2))(a1: m_pEntity[82].__vftable) != 0 )
      {
        if ( !this->m_bAtRest )
        {
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)v6);
          this->m_vecAtRestOrigin.x = this->m_vecAbsOrigin.x;
          this->m_vecAtRestOrigin.y = this->m_vecAbsOrigin.y;
          this->m_vecAtRestOrigin.z = this->m_vecAbsOrigin.z;
          CAI_RadialLinkController::ModifyNodeLinks(this, bMakeStale: true);
          this->m_bAtRest = true;
        }
      }
      else
      {
        if ( !this->m_bAtRest )
          goto LABEL_15;
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)v6);
        v5 = this->m_vecAbsOrigin.x - this->m_vecAtRestOrigin.x;
        if ( fsqrt(
               (float)((float)((float)(this->m_vecAbsOrigin.y - this->m_vecAtRestOrigin.y)
                             * (float)(this->m_vecAbsOrigin.y - this->m_vecAtRestOrigin.y))
                     + (float)((float)(this->m_vecAbsOrigin.z - this->m_vecAtRestOrigin.z)
                             * (float)(this->m_vecAbsOrigin.z - this->m_vecAtRestOrigin.z)))
             + (float)(v5 * v5)) >= 18.0 )
        {
LABEL_15:
          if ( vec3_invalid.x != this->m_vecAtRestOrigin.x
            || vec3_invalid.y != this->m_vecAtRestOrigin.y
            || vec3_invalid.z != this->m_vecAtRestOrigin.z )
          {
            CAI_RadialLinkController::ModifyNodeLinks(this, bMakeStale: false);
            this->m_bAtRest = false;
            this->m_vecAtRestOrigin = vec3_invalid;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F5E0
// Name: public: void CAI_DynamicLinkController::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_DynamicLinkController::InputTurnOn(CAI_DynamicLinkController *this, inputdata_t *inputdata)
{
  int v3; // edi
  unsigned int m_Index; // eax
  int m_Size; // ecx
  unsigned int v6; // eax
  IHandleEntity *m_pEntity; // ecx

  v3 = 0;
  if ( this->m_ControlledLinks.m_Size <= 0 )
  {
    this->m_nLinkState = LINK_ON;
  }
  else
  {
    do
    {
      m_Index = this->m_ControlledLinks.m_Memory.m_pMemory[v3].m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        m_Size = this->m_ControlledLinks.m_Size;
        if ( m_Size > 0 )
        {
          if ( v3 != m_Size - 1 )
            this->m_ControlledLinks.m_Memory.m_pMemory[v3].m_Index = this->m_ControlledLinks.m_Memory.m_pMemory[m_Size - 1].m_Index;
          --this->m_ControlledLinks.m_Size;
        }
        if ( v3 >= this->m_ControlledLinks.m_Size )
          break;
      }
      v6 = this->m_ControlledLinks.m_Memory.m_pMemory[v3].m_Index;
      if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
      if ( m_pEntity[218].__vftable == nullptr )
      {
        m_pEntity[218].__vftable = (IHandleEntity_vtbl *)1;
        CAI_DynamicLink::SetLinkState(this: (CAI_DynamicLink *)m_pEntity);
      }
      ++v3;
    }
    while ( v3 < this->m_ControlledLinks.m_Size );
    this->m_nLinkState = LINK_ON;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F6E0
// Name: public: void CAI_DynamicLinkController::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_DynamicLinkController::InputTurnOff(CAI_DynamicLinkController *this, inputdata_t *inputdata)
{
  int i; // edi
  unsigned int m_Index; // eax
  int m_Size; // ecx
  unsigned int v6; // eax
  IHandleEntity *m_pEntity; // ecx

  for ( i = 0; i < this->m_ControlledLinks.m_Size; ++i )
  {
    m_Index = this->m_ControlledLinks.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      m_Size = this->m_ControlledLinks.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_ControlledLinks.m_Memory.m_pMemory[i].m_Index = this->m_ControlledLinks.m_Memory.m_pMemory[m_Size - 1].m_Index;
        --this->m_ControlledLinks.m_Size;
      }
      if ( i >= this->m_ControlledLinks.m_Size )
        break;
    }
    v6 = this->m_ControlledLinks.m_Memory.m_pMemory[i].m_Index;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    if ( m_pEntity[218].__vftable == (IHandleEntity_vtbl *)1 )
    {
      m_pEntity[218].__vftable = nullptr;
      CAI_DynamicLink::SetLinkState(this: (CAI_DynamicLink *)m_pEntity);
    }
  }
  this->m_nLinkState = LINK_OFF;
}

//------------------------------------------------------------------------------
// Address: 0x1004F7D0
// Name: public: virtual void CAI_RadialLinkController::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_RadialLinkController::Activate(
        CAI_RadialLinkController *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CBaseEntity **v11; // eax
  CBaseEntity *v12; // edi
  float v13; // xmm0_4
  const char *DebugName; // eax
  float v16; // [esp+24h] [ebp-18h]
  const char *v17; // [esp+28h] [ebp-14h]
  _DWORD v18[3]; // [esp+30h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+3Ch] [ebp+0h]

  v18[0] = a2;
  v18[1] = retaddr;
  CBaseEntity::Activate(this);
  this->m_bAtRest = false;
  this->m_vecAtRestOrigin = vec3_invalid;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CAI_RadialLinkController::PollMotionThink,
    thinkTime: 0.0,
    szContext: nullptr);
  v16 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int, _DWORD, int, int))random->RandomFloat)(
          a1: random,
          a2: 0,
          a3: 1065353216,
          a4: 0,
          a5: a3,
          a6: a4)
      + gpGlobals->curtime;
  CBaseEntity::SetNextThink(this, thinkTime: v16, szContext: v17);
  m_Index = this->m_pParent.m_Index;
  if ( m_Index != -1 )
  {
    v6 = (unsigned __int16)m_Index;
    v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v8 = HIWORD(m_Index);
    if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
    {
      v9 = v6;
      v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
      v11 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v9];
      if ( v10 )
        v12 = *v11;
      else
        v12 = nullptr;
      if ( (v12->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v12, a2: (int)v18);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)v18);
      v13 = this->m_vecAbsOrigin.x - v12->m_vecAbsOrigin.x;
      if ( fsqrt(
             (float)((float)((float)(this->m_vecAbsOrigin.y - v12->m_vecAbsOrigin.y)
                           * (float)(this->m_vecAbsOrigin.y - v12->m_vecAbsOrigin.y))
                   + (float)((float)(this->m_vecAbsOrigin.z - v12->m_vecAbsOrigin.z)
                           * (float)(this->m_vecAbsOrigin.z - v12->m_vecAbsOrigin.z)))
           + (float)(v13 * v13)) > 200.0 )
      {
        DebugName = CBaseEntity::GetDebugName(this);
        DevMsg(a1: "RadialLinkController (%s) is far from its parent!\n", DebugName);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F970
// Name: public: void CAI_DynamicLinkController::GenerateLinksFromVolume(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_DynamicLinkController::GenerateLinksFromVolume(CAI_DynamicLinkController *this)
{
  CAI_Node **m_pAInode; // edx
  bool v3; // zf
  float v4; // xmm0_4
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // edx
  const Vector *v6; // esi
  int v7; // ebx
  CAI_Node *v8; // eax
  float v9; // xmm1_4
  int v10; // eax
  CAI_Node *v11; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  CBaseEntity *EntityByName; // esi
  int v18; // eax
  CBaseEntity_vtbl *v19; // edx
  void (__thiscall *Spawn)(CBaseEntity *); // eax
  int m_Index; // ecx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CHandle<CAI_DynamicLink> *m_pMemory; // ecx
  int v25; // eax
  CHandle<CAI_DynamicLink> *v26; // ebx
  Vector vecDelta; // [esp+10h] [ebp-48h] BYREF
  Vector vAbsMins; // [esp+1Ch] [ebp-3Ch] BYREF
  Vector vAbsMaxs; // [esp+28h] [ebp-30h] BYREF
  int nLinks; // [esp+34h] [ebp-24h]
  int iLinkDest; // [esp+38h] [ebp-20h]
  int nNodes; // [esp+3Ch] [ebp-1Ch]
  const Vector *origin; // [esp+40h] [ebp-18h]
  CAI_Node *pNode; // [esp+44h] [ebp-14h]
  CAI_Node **ppNodes; // [esp+48h] [ebp-10h]
  int i; // [esp+4Ch] [ebp-Ch]
  int j; // [esp+50h] [ebp-8h]
  float MinDistCareSq; // [esp+54h] [ebp-4h]

  m_pAInode = g_pBigAINet->m_pAInode;
  v3 = !this->m_bUseAirLinkRadius;
  nNodes = g_pBigAINet->m_iNumNodes;
  ppNodes = m_pAInode;
  if ( v3 )
    v4 = 518544.0;
  else
    v4 = 2073888.0;
  WorldSpaceCenter = this->WorldSpaceCenter;
  MinDistCareSq = v4;
  v6 = WorldSpaceCenter(this);
  origin = v6;
  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &vAbsMins,
    pWorldMaxs: &vAbsMaxs);
  vAbsMins.x = vAbsMins.x - 1.0;
  vAbsMins.y = vAbsMins.y - 1.0;
  vAbsMins.z = vAbsMins.z - 1.0;
  vAbsMaxs.x = vAbsMaxs.x + 1.0;
  vAbsMaxs.y = vAbsMaxs.y + 1.0;
  v7 = 0;
  vAbsMaxs.z = vAbsMaxs.z + 1.0;
  for ( i = 0; v7 < nNodes; i = v7 )
  {
    v8 = ppNodes[v7];
    v9 = (float)((float)((float)(v6->y - v8->m_vOrigin.y) * (float)(v6->y - v8->m_vOrigin.y))
               + (float)((float)(v6->x - v8->m_vOrigin.x) * (float)(v6->x - v8->m_vOrigin.x)))
       + (float)((float)(v6->z - v8->m_vOrigin.z) * (float)(v6->z - v8->m_vOrigin.z));
    pNode = v8;
    if ( v9 < MinDistCareSq )
    {
      nLinks = v8->m_Links.m_Size;
      j = 0;
      if ( nLinks > 0 )
      {
        while ( 1 )
        {
          v10 = (int)v8->m_Links.m_Memory.m_pMemory[j];
          if ( v7 == *(__int16 *)v10 )
            LOWORD(v10) = *(_WORD *)(v10 + 2);
          else
            LOWORD(v10) = *(_WORD *)v10;
          v10 = (__int16)v10;
          iLinkDest = v10;
          if ( (__int16)v10 > v7 )
          {
            v11 = ppNodes[(__int16)v10];
            x = v11->m_vOrigin.x;
            y = v11->m_vOrigin.y;
            z = v11->m_vOrigin.z;
            if ( (float)((float)((float)((float)(v6->y - y) * (float)(v6->y - y))
                               + (float)((float)(v6->x - x) * (float)(v6->x - x)))
                       + (float)((float)(v6->z - z) * (float)(v6->z - z))) < MinDistCareSq )
            {
              v15 = y - pNode->m_vOrigin.y;
              v16 = z - pNode->m_vOrigin.z;
              vecDelta.x = x - pNode->m_vOrigin.x;
              vecDelta.y = v15;
              vecDelta.z = v16;
              if ( IsBoxIntersectingRay(
                     boxMin: &vAbsMins,
                     boxMax: &vAbsMaxs,
                     origin: &pNode->m_vOrigin,
                     &vecDelta,
                     flTolerance: 0.0) )
              {
                EntityByName = CreateEntityByName(className: "info_node_link", iForceEdictIndex: -1, bNotify: true);
                v18 = iLinkDest;
                EntityByName[1].m_Network.__vftable = (CServerNetworkProperty_vtbl *)v7;
                EntityByName[1].m_Network.__vftable = (IEventRegisterCallback_vtbl *)v18;
                EntityByName[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CAI_NetworkEditTools::GetWCIdFromNodeId(
                                                                                      this: g_pAINetworkManager->m_pEditOps,
                                                                                      nNodeId: v7);
                EntityByName[1].m_pfnThink = (void (__thiscall *)(CBaseEntity *))CAI_NetworkEditTools::GetWCIdFromNodeId(
                                                                                   this: g_pAINetworkManager->m_pEditOps,
                                                                                   nNodeId: (int)EntityByName[1].m_Network.__vftable);
                EntityByName[1].m_Network.m_pOuter = (CBaseEntity *)this->m_nLinkState;
                EntityByName[1].m_Network.m_pPev = (edict_t *)this->m_strAllowUse.pszValue;
                v19 = EntityByName->__vftable;
                LOBYTE(EntityByName[1].m_Network.m_PVSInfo.m_nHeadNode) = this->m_bInvertAllow;
                Spawn = v19->Spawn;
                EntityByName[1].m_Network.m_PVSInfo.m_nClusterCount = 257;
                *(_DWORD *)&EntityByName[1].m_Network.m_PVSInfo.m_nAreaNum = this->m_nPriority;
                Spawn(this: EntityByName);
                m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
                m_Size = this->m_ControlledLinks.m_Size;
                m_nAllocationCount = this->m_ControlledLinks.m_Memory.m_nAllocationCount;
                iLinkDest = m_Index;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<CNavLadder *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ControlledLinks,
                    num: m_Size - m_nAllocationCount + 1);
                ++this->m_ControlledLinks.m_Size;
                m_pMemory = this->m_ControlledLinks.m_Memory.m_pMemory;
                v25 = this->m_ControlledLinks.m_Size - m_Size - 1;
                this->m_ControlledLinks.m_pElements = m_pMemory;
                if ( v25 > 0 )
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v25);
                v6 = origin;
                v26 = &this->m_ControlledLinks.m_Memory.m_pMemory[m_Size];
                if ( v26 != nullptr )
                  v26->m_Index = iLinkDest;
                v7 = i;
              }
            }
          }
          if ( ++j >= nLinks )
            break;
          v8 = pNode;
        }
      }
    }
    ++v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FCA0
// Name: public: static void CAI_DynamicLink::GenerateControllerLinks(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_DynamicLink::GenerateControllerLinks()
{
  CBaseEntity *v0; // esi
  CBaseEntity *Ent; // esi
  CAI_DynamicLinkController *v2; // eax

  v0 = nullptr;
  while ( 1 )
  {
    Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: v0);
    if ( Ent == nullptr )
      break;
    while ( 1 )
    {
      v2 = (CAI_DynamicLinkController *)__RTDynamicCast(
                                          inptr: Ent,
                                          VfDelta: 0,
                                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                                          TargetType: &CAI_DynamicLinkController `RTTI Type Descriptor',
                                          isReference: 0);
      if ( v2 != nullptr )
        break;
      Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
      if ( Ent == nullptr )
        return;
    }
    v0 = v2;
    CAI_DynamicLinkController::GenerateLinksFromVolume(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FCF0
// Name: public: static void CAI_DynamicLink::InitDynamicLinks(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_DynamicLink::InitDynamicLinks()
{
  CAI_DynamicLink *v0; // esi
  void (*v1)(const char *, ...); // ebx
  int NodeIdFromWCId; // edi
  int v3; // eax
  int m_nSrcID; // edi
  CAI_Node *v5; // edi
  int m_nDestID; // eax
  CAI_Node *v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // edi
  CBaseEntity *v12; // [esp-10h] [ebp-18h]
  CAI_Link *pLink; // [esp+0h] [ebp-8h]
  bool bUpdateZones; // [esp+7h] [ebp-1h]

  if ( g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable == nullptr )
  {
    _Warning(a1: "ERROR: Trying initialize links with no WC ID table!\n");
    return;
  }
  if ( !CAI_DynamicLink::gm_bInitialized )
  {
    CAI_DynamicLink::gm_bInitialized = true;
    bUpdateZones = false;
    CAI_DynamicLink::GenerateControllerLinks();
    v0 = CAI_DynamicLink::m_pAllDynamicLinks;
    if ( CAI_DynamicLink::m_pAllDynamicLinks != nullptr )
    {
      v1 = DevMsg;
      while ( 1 )
      {
        if ( !v0->m_bFixedUpIds )
        {
          NodeIdFromWCId = CAI_NetworkEditTools::GetNodeIdFromWCId(
                             this: g_pAINetworkManager->m_pEditOps,
                             nWCId: v0->m_nSrcEditID);
          if ( NodeIdFromWCId == -1 )
            v1(a1: "ERROR: Dynamic link source WC node %d not found\n", v0->m_nSrcEditID);
          v3 = CAI_NetworkEditTools::GetNodeIdFromWCId(this: g_pAINetworkManager->m_pEditOps, nWCId: v0->m_nDestEditID);
          if ( v3 == -1 )
          {
            v1(a1: "ERROR: Dynamic link dest WC node %d not found\n", v0->m_nDestEditID);
            v3 = -1;
          }
          v0->m_nSrcID = NodeIdFromWCId;
          v0->m_nDestID = v3;
          v0->m_bFixedUpIds = true;
        }
        m_nSrcID = v0->m_nSrcID;
        if ( m_nSrcID == -1 || v0->m_nDestID == -1 )
        {
          v12 = v0;
          v0 = v0->m_pNextDynamicLink;
          UTIL_RemoveImmediate(oldObj: v12);
          goto LABEL_36;
        }
        if ( (v0->m_spawnflags.m_Value & 0x1FFF) == 0 )
          goto LABEL_34;
        pLink = CAI_DynamicLink::FindLink(this: v0);
        if ( pLink != nullptr )
          break;
        if ( m_nSrcID < 0 || m_nSrcID >= g_pBigAINet->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v5 = nullptr;
        }
        else
        {
          v5 = g_pBigAINet->m_pAInode[m_nSrcID];
        }
        m_nDestID = v0->m_nDestID;
        if ( m_nDestID < 0 || m_nDestID >= g_pBigAINet->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v7 = nullptr;
        }
        else
        {
          v7 = g_pBigAINet->m_pAInode[m_nDestID];
        }
        if ( v5 == nullptr || v7 == nullptr )
          goto LABEL_34;
        pLink = CAI_Network::CreateLink(
                  this: g_pBigAINet,
                  srcID: v0->m_nSrcID,
                  destID: v0->m_nDestID,
                  pDynamicLink: nullptr);
        if ( pLink != nullptr )
          break;
        v1(a1: "Failed to create dynamic link (%d <--> %d)\n", v0->m_nSrcEditID, v0->m_nDestEditID);
        CAI_DynamicLink::SetLinkState(this: v0);
        v0 = v0->m_pNextDynamicLink;
LABEL_36:
        if ( v0 == nullptr )
        {
          if ( bUpdateZones )
            CAI_NetworkBuilder::InitZones(this: &g_AINetworkBuilder, pNetwork: g_pBigAINet);
          return;
        }
      }
      v8 = v0->m_spawnflags.m_Value & 0x1FFF;
      bUpdateZones = true;
      v9 = 0;
      v10 = 1;
      do
      {
        v11 = v10;
        if ( v9 >= 9 )
          v11 = __ROL4__(v10, 1);
        if ( (v11 & v8) != 0 )
        {
          pLink->m_iAcceptedMoveTypes[v9] = v0->m_nLinkType;
          v1 = DevMsg;
        }
        ++v9;
        v10 = __ROL4__(v10, 1);
      }
      while ( v9 < 12 );
LABEL_34:
      CAI_DynamicLink::SetLinkState(this: v0);
      v0 = v0->m_pNextDynamicLink;
      goto LABEL_36;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FBB50
// Name: CAI_DynamicLinkController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_DynamicLinkController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_DynamicLinkController>(__formal: nullptr);
  CAI_DynamicLinkController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FBB80
// Name: CAI_DynamicLink_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_DynamicLink_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_DynamicLink>(__formal: nullptr);
  CAI_DynamicLink_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FBBB0
// Name: CAI_RadialLinkController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_RadialLinkController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_RadialLinkController>(__formal: nullptr);
  CAI_RadialLinkController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF20
// Name: class CAI_DynamicLinkController __near * _CreateEntityTemplate<class CAI_DynamicLinkController>(class CAI_DynamicLinkController __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_DynamicLinkController *__cdecl _CreateEntityTemplate<CAI_DynamicLinkController>(
        CAI_DynamicLinkController *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CAI_DynamicLinkController::`vftable';
    v3[213] = 0;
    v3[214] = 0;
    v3[215] = 0;
    v3[216] = 0;
    v3[217] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CAI_DynamicLinkController *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FFA0
// Name: struct datamap_t __near * DataMapInit<class CAI_DynamicLinkController>(class CAI_DynamicLinkController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_DynamicLinkController>()
{
  if ( (_S2_15 & 1) == 0 )
  {
    _S2_15 |= 1u;
    nameHolder_40.m_pszBase = "CAI_DynamicLinkController";
    nameHolder_40.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_40.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_40.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_40.m_Names.m_Size = 0;
    nameHolder_40.m_Names.m_pElements = nullptr;
    nameHolder_40.m_nLenBase = 25;
    atexit(func: DataMapInit_CAI_DynamicLinkController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_DynamicLinkController::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CAI_DynamicLinkController::m_DataMap.dataNumFields = 9;
  CAI_DynamicLinkController::m_DataMap.dataDesc = &dataDesc_39[1];
  return &CAI_DynamicLinkController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10050020
// Name: struct datamap_t __near * DataMapInit<class CAI_DynamicLink>(class CAI_DynamicLink __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_DynamicLink>()
{
  if ( (_S3_10 & 1) == 0 )
  {
    _S3_10 |= 1u;
    nameHolder_41.m_pszBase = "CAI_DynamicLink";
    nameHolder_41.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_41.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_41.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_41.m_Names.m_Size = 0;
    nameHolder_41.m_Names.m_pElements = nullptr;
    nameHolder_41.m_nLenBase = 15;
    atexit(func: DataMapInit_CAI_DynamicLink__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_DynamicLink::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CAI_DynamicLink::m_DataMap.dataNumFields = 10;
  CAI_DynamicLink::m_DataMap.dataDesc = &dataDesc_40[1];
  return &CAI_DynamicLink::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100500A0
// Name: struct datamap_t __near * DataMapInit<class CAI_RadialLinkController>(class CAI_RadialLinkController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_RadialLinkController>()
{
  if ( (_S4_5 & 1) == 0 )
  {
    _S4_5 |= 1u;
    nameHolder_42.m_pszBase = "CAI_RadialLinkController";
    nameHolder_42.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_42.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_42.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_42.m_Names.m_Size = 0;
    nameHolder_42.m_Names.m_pElements = nullptr;
    nameHolder_42.m_nLenBase = 24;
    atexit(func: DataMapInit_CAI_RadialLinkController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_RadialLinkController::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_5 & 2) == 0 )
  {
    _S4_5 |= 2u;
    dataDesc_41[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_42,
                                 pszIdentifier: "PollMotionThink");
    dataDesc_41[4].fieldOffset = 0;
    *(_DWORD *)&dataDesc_41[4].fieldSize = 2097153;
    dataDesc_41[4].externalName = nullptr;
    dataDesc_41[4].pSaveRestoreOps = nullptr;
    dataDesc_41[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_RadialLinkController::PollMotionThink;
    *(_QWORD *)&dataDesc_41[4].td = 0;
    *(_QWORD *)&dataDesc_41[4].override_field = 0;
    *(_QWORD *)&dataDesc_41[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_41[4].flatOffset[1] = 0;
  }
  CAI_RadialLinkController::m_DataMap.dataNumFields = 4;
  CAI_RadialLinkController::m_DataMap.dataDesc = &dataDesc_41[1];
  return &CAI_RadialLinkController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FBBC0
// Name: _dynamic_initializer_for__ai_radial_max_link_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_radial_max_link_dist__()
{
  ConVar::ConVar(this: &ai_radial_max_link_dist, pName: "ai_radial_max_link_dist", pDefaultValue: "512", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_radial_max_link_dist__);
}
