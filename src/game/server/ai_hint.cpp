// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_hint.cpp
// Functions: 53
// ============================================================

#include "game\server\ai_hint.h"

//------------------------------------------------------------------------------
// Address: 0x10053680
// Name: public: void CHintCriteria::SetFlag(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintCriteria::SetFlag(CHintCriteria *this, int bitmask)
{
  this->m_iFlags |= bitmask;
}

//------------------------------------------------------------------------------
// Address: 0x10053690
// Name: public: void CHintCriteria::SetGroup(struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintCriteria::SetGroup(CHintCriteria *this, string_t group)
{
  this->m_strGroup = group;
}

//------------------------------------------------------------------------------
// Address: 0x100536A0
// Name: public: static int CAI_HintManager::GetFlags(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CAI_HintManager::GetFlags(const char *token)
{
  int v1; // eax
  void *v3; // esp
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned __int8 v9[12]; // [esp+0h] [ebp-Ch] BYREF

  v1 = strlen(token);
  if ( v1 <= 0 )
    return 0;
  v3 = alloca(v1 + 1);
  V_strncpy(pDest: (char *)v9, pSrc: token, maxLen: v1 + 1);
  strlwr(string: (char *)v9);
  strstr(str1: "none", str2: v9);
  if ( v4 != 0 )
    return 0;
  strstr(str1: "visible", str2: v9);
  v6 = v5 != 0;
  strstr(str1: "nearest", str2: v9);
  if ( v7 != 0 )
    v6 |= 2u;
  strstr(str1: "random", str2: v9);
  if ( v8 != 0 )
    v6 |= 4u;
  if ( (v6 & 2) != 0 && (v6 & 4) != 0 )
  {
    v6 &= ~4u;
    DevMsg(
      a1: "HINTFLAGS:%s, inconsistent, the nearest node is never a random hint node, treating as nearest request!\n",
      token);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10053760
// Name: private: virtual struct datamap_t __near * CAI_Hint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_Hint::GetDataDescMap(CAI_Hint *this)
{
  return &CAI_Hint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10053770
// Name: private: void CAI_Hint::InputEnableHint(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Hint::InputEnableHint(CAI_Hint *this, inputdata_t *inputdata)
{
  this->m_NodeData.iDisabled = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10053780
// Name: private: void CAI_Hint::InputDisableHint(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Hint::InputDisableHint(CAI_Hint *this, inputdata_t *inputdata)
{
  this->m_NodeData.iDisabled = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10053790
// Name: private: virtual bool CAI_Hint::IsViewable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Hint::IsViewable(CAI_Hint *this)
{
  int nHintType; // eax
  bool result; // al

  result = false;
  if ( this->m_NodeData.iDisabled == 0 )
  {
    nHintType = this->m_NodeData.nHintType;
    if ( nHintType >= 13 && (nHintType <= 14 || nHintType == 16) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100537C0
// Name: public: void CAI_Hint::EnableThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Hint::EnableThink(CAI_Hint *this)
{
  this->m_NodeData.iDisabled = 0;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100537E0
// Name: public: void CAI_Hint::FixupTargetNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Hint::FixupTargetNode(CAI_Hint *this)
{
  int nTargetWCNodeID; // eax

  nTargetWCNodeID = this->m_NodeData.nTargetWCNodeID;
  if ( nTargetWCNodeID == -1 )
    this->m_nTargetNodeID = -1;
  else
    this->m_nTargetNodeID = CAI_NetworkEditTools::GetNodeIdFromWCId(
                              this: g_pAINetworkManager->m_pEditOps,
                              nWCId: nTargetWCNodeID);
}

//------------------------------------------------------------------------------
// Address: 0x10053820
// Name: private: virtual void CAI_Hint::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Hint::OnRestore(CAI_Hint *this)
{
  int nNodeID; // eax
  CAI_Node *v3; // edi

  CBaseEntity::OnRestore(this);
  this->m_NodeData.nNodeID = CAI_NetworkEditTools::GetNodeIdFromWCId(
                               this: g_pAINetworkManager->m_pEditOps,
                               nWCId: this->m_NodeData.nWCNodeID);
  if ( this->m_NodeData.nTargetWCNodeID == -1 )
    this->m_nTargetNodeID = -1;
  else
    this->m_nTargetNodeID = CAI_NetworkEditTools::GetNodeIdFromWCId(
                              this: g_pAINetworkManager->m_pEditOps,
                              nWCId: this->m_NodeData.nTargetWCNodeID);
  nNodeID = this->m_NodeData.nNodeID;
  if ( nNodeID >= 0 && nNodeID < g_pBigAINet->m_iNumNodes && (v3 = g_pBigAINet->m_pAInode[nNodeID]) != nullptr )
  {
    this->m_NodeData.vecPosition.x = v3->m_vOrigin.x;
    this->m_NodeData.vecPosition.y = v3->m_vOrigin.y;
    this->m_NodeData.vecPosition.z = v3->m_vOrigin.z;
    this->Teleport(this, a2: &this->m_NodeData.vecPosition, a3: nullptr, a4: nullptr, a5: true);
    v3->m_pHint = this;
  }
  else if ( this->m_NodeData.nWCNodeID > 0 )
  {
    DevMsg(a1: "Warning: AI hint has incorrect or no AI node\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100538F0
// Name: char const __near * GetHintTypeDescription(class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetHintTypeDescription(CAI_Hint *pHint)
{
  int v1; // eax

  v1 = 0;
  while ( g_pszHintDescriptions[v1].iType != pHint->m_NodeData.nHintType )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return "Obsolete / Unused";
  }
  return (&off_10568F3C)[2 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x100539B0
// Name: private: virtual void CAI_Hint::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10053A20
// Name: public: void CAI_Hint::GetPosition(class CBaseCombatCharacter __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Hint::GetPosition(CAI_Hint *this, CBaseCombatCharacter *pBCC, Vector *vPosition)
{
  Vector result; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( this->m_NodeData.nNodeID == -1 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    *vPosition = this->m_vecAbsOrigin;
  }
  else
  {
    *vPosition = *CAI_Network::GetNodePosition(this: g_pBigAINet, &result, pNPC: pBCC, nodeID: this->m_NodeData.nNodeID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053AA0
// Name: public: bool CAI_Hint::IsInNodeFOV(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Hint::IsInNodeFOV(CAI_Hint *this, CBaseEntity *pOther)
{
  Vector vecToNPC; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( this->m_nodeFOV == 360.0 )
    return true;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (pOther->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pOther, a2: (int)&savedregs);
  vecToNPC.x = pOther->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  vecToNPC.y = pOther->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
  vecToNPC.z = pOther->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
  VectorNormalize(vec: &vecToNPC);
  return (float)((float)((float)(this->m_vecForward.y * vecToNPC.y) + (float)(this->m_vecForward.x * vecToNPC.x))
               + (float)(this->m_vecForward.z * vecToNPC.z)) > this->m_nodeFOV;
}

//------------------------------------------------------------------------------
// Address: 0x10053B90
// Name: public: bool CAI_Hint::IsLockedBy(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Hint::IsLockedBy(CAI_Hint *this, CBaseEntity *pNPC)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hHintOwner.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return pNPC == nullptr;
  else
    return g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == pNPC;
}

//------------------------------------------------------------------------------
// Address: 0x10053BE0
// Name: private: virtual int CAI_Hint::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Hint::DrawDebugTextOverlays(CAI_Hint *this)
{
  int result; // eax
  int v3; // esi
  int v4; // eax
  const char *v5; // eax
  float v6; // xmm0_4
  int v7; // esi
  int v8; // esi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    v4 = 0;
    while ( g_pszHintDescriptions[v4].iType != this->m_NodeData.nHintType )
    {
      if ( (unsigned int)++v4 >= 0x16 )
      {
        v5 = "Obsolete / Unused";
        goto LABEL_6;
      }
    }
    v5 = (&off_10568F3C)[2 * v4];
LABEL_6:
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "%s (%i)", v5, this->m_NodeData.nHintType);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v6 = this->m_flNextUseTime - gpGlobals->curtime;
    v7 = v3 + 1;
    if ( v6 < 0.0 )
      v6 = 0.0;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "delay %f", v6);
    CBaseEntity::EntityText(this, text_offset: v7, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v8 = v7 + 1;
    if ( this->m_NodeData.iDisabled != 0 )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "DISABLED");
      CBaseEntity::EntityText(this, text_offset: v8, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      return v8 + 1;
    }
    else
    {
      return v8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10053D50
// Name: public: void CAI_Hint::Unlock(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Hint::Unlock(CAI_Hint *this, float flSeconds)
{
  this->m_hHintOwner.m_Index = -1;
  this->m_flNextUseTime = gpGlobals->curtime + flSeconds;
}

//------------------------------------------------------------------------------
// Address: 0x10053EA0
// Name: public: bool CHintCriteria::MatchesHintType(int,struct string_t)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHintCriteria::MatchesHintType(CHintCriteria *this, int hintType, string_t iszGenericType)
{
  int m_Size; // edx
  int v4; // eax
  int *m_pMemory; // esi
  int m_iFirstHintType; // edx
  int m_iLastHintType; // eax

  m_Size = this->m_HintTypes.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_HintTypes.m_Memory.m_pMemory;
    while ( *m_pMemory != hintType )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    return true;
  }
LABEL_5:
  m_iFirstHintType = this->m_iFirstHintType;
  if ( m_iFirstHintType != -1 )
  {
    m_iLastHintType = this->m_iLastHintType;
    if ( m_iLastHintType == 0 )
      return m_iFirstHintType == hintType;
    if ( hintType < m_iFirstHintType || hintType > m_iLastHintType )
      return false;
    if ( hintType != 17 )
      return true;
    return iszGenericType.pszValue == this->m_strGenericType.pszValue;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10053F00
// Name: private: bool CHintCriteria::InZone(class CUtlVector<struct CHintCriteria::hintZone_t,class CUtlMemory<struct CHintCriteria::hintZone_t,int>> const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHintCriteria::InZone(
        CHintCriteria *this,
        const CUtlVector<CHintCriteria::hintZone_t,CUtlMemory<CHintCriteria::hintZone_t,int> > *zone,
        const Vector *testPosition)
{
  int m_Size; // edx
  int v4; // eax
  CHintCriteria::hintZone_t *i; // ecx

  m_Size = zone->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = zone->m_Memory.m_pMemory;
        i->radiussqr <= (float)((float)((float)((float)(i->position.x - testPosition->x)
                                              * (float)(i->position.x - testPosition->x))
                                      + (float)((float)(i->position.y - testPosition->y)
                                              * (float)(i->position.y - testPosition->y)))
                              + (float)((float)(i->position.z - testPosition->z)
                                      * (float)(i->position.z - testPosition->z)));
        ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10053F80
// Name: public: static class CAI_Hint __near * CAI_HintManager::GetFirstHint(struct AIHintIter_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__cdecl CAI_HintManager::GetFirstHint(AIHintIter_t__ **pIter)
{
  if ( CAI_HintManager::gm_AllHints.m_Size != 0 )
  {
    *pIter = nullptr;
    return *CAI_HintManager::gm_AllHints.m_Memory.m_pMemory;
  }
  else
  {
    *pIter = (AIHintIter_t__ *)-1;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053FB0
// Name: public: static class CAI_Hint __near * CAI_HintManager::GetNextHint(struct AIHintIter_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__cdecl CAI_HintManager::GetNextHint(AIHintIter_t__ **pIter)
{
  int v1; // eax

  if ( *pIter == (AIHintIter_t__ *)-1 )
    return nullptr;
  v1 = (int)*pIter + 1;
  if ( CAI_HintManager::gm_AllHints.m_Size <= v1 )
  {
    *pIter = (AIHintIter_t__ *)-1;
    return nullptr;
  }
  *pIter = (AIHintIter_t__ *)v1;
  return CAI_HintManager::gm_AllHints.m_Memory.m_pMemory[v1];
}

//------------------------------------------------------------------------------
// Address: 0x10053FE0
// Name: public: static void CAI_HintManager::DumpHints(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAI_HintManager::DumpHints(int a1@<ebp>)
{
  CAI_Hint *v1; // esi
  int i; // edi

  if ( CAI_HintManager::gm_AllHints.m_Size != 0 )
  {
    v1 = *CAI_HintManager::gm_AllHints.m_Memory.m_pMemory;
    for ( i = 0; v1 != nullptr; v1 = CAI_HintManager::gm_AllHints.m_Memory.m_pMemory[++i] )
    {
      if ( (v1->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v1, a2: a1);
      _Msg(
        a1: "(%.1f, %.1f, %.1f) -- Node ID: %d; WC id %d; type %d\n",
        v1->m_vecAbsOrigin.x,
        v1->m_vecAbsOrigin.y,
        v1->m_vecAbsOrigin.z,
        v1->m_NodeData.nNodeID,
        v1->m_NodeData.nWCNodeID,
        v1->m_NodeData.nHintType);
      if ( i == -1 )
        break;
      if ( CAI_HintManager::gm_AllHints.m_Size <= i + 1 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100540B0
// Name: public: float CAI_Hint::Yaw(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Hint::Yaw(CAI_Hint *this)
{
  int nNodeID; // eax

  nNodeID = this->m_NodeData.nNodeID;
  if ( nNodeID == -1 )
    return this->m_angRotation.m_Value.y;
  else
    return CAI_Network::GetNodeYaw(this: g_pBigAINet, nodeID: nNodeID);
}

//------------------------------------------------------------------------------
// Address: 0x100540D0
// Name: public: bool CAI_Hint::Lock(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Hint::Lock(CAI_Hint *this, CBaseEntity *pNPC)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  m_Index = this->m_hHintOwner.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != pNPC
    && m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    return 0;
  }
  if ( pNPC != nullptr )
    this->m_hHintOwner.m_Index = pNPC->GetRefEHandle(this: pNPC)->m_Index;
  else
    this->m_hHintOwner.m_Index = -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10054170
// Name: public: bool CAI_Hint::HintMatchesCriteria(class CAI_BaseNPC __near *,class CHintCriteria const __near &,class Vector const __near &,float __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CAI_Hint::HintMatchesCriteria@<al>(
        CAI_Hint *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        CAI_BaseNPC *pNPC,
        CHintCriteria *hintCriteria,
        const Vector *position,
        float *flNearestDistance,
        bool bIgnoreLock,
        bool bIgnoreHintType)
{
  unsigned int m_Index; // eax
  NPC_STATE minState; // eax
  NPC_STATE m_NPCState; // ecx
  const char *pszValue; // ecx
  const char *v15; // eax
  bool (__cdecl *m_pfnFilter)(void *, CAI_Hint *); // eax
  const Vector *v17; // eax
  const Vector *v18; // eax
  CBaseEntity *v19; // eax
  const Vector *v20; // eax
  CAI_BaseNPC_vtbl *v21; // edx
  float *v22; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  const Vector *v24; // eax
  const Vector *BoundingMaxs; // eax
  double v26; // st7
  float v27; // xmm0_4
  const Vector *v28; // eax
  float x; // xmm0_4
  const Vector *v30; // eax
  const Vector *v31; // eax
  __int128 v32; // xmm0
  Vector *v33; // eax
  int m_iFlags; // edx
  Vector *v35; // eax
  Vector *(__thiscall *GetNodeViewOffset)(CAI_BaseNPC *, Vector *); // edx
  float *v37; // eax
  float v38; // xmm0_4
  unsigned __int8 (__thiscall *v39)(_DWORD, Vector *, int, _DWORD); // eax
  CBasePlayer *v40; // esi
  const Vector *v41; // eax
  const Vector *v42; // eax
  int v43; // eax
  const Vector *BoundingMins; // [esp-4h] [ebp-C4h]
  const Vector *v45; // [esp+0h] [ebp-C0h]
  const Vector *AbsOrigin; // [esp+4h] [ebp-BCh]
  const Vector *v47; // [esp+4h] [ebp-BCh]
  const Vector *v48; // [esp+4h] [ebp-BCh]
  const Vector *v49; // [esp+4h] [ebp-BCh]
  const Vector *v50; // [esp+4h] [ebp-BCh]
  const Vector *v51; // [esp+4h] [ebp-BCh]
  const Vector *v52; // [esp+4h] [ebp-BCh]
  const Vector *v53; // [esp+4h] [ebp-BCh]
  const Vector *v54; // [esp+4h] [ebp-BCh]
  const Vector *v55; // [esp+4h] [ebp-BCh]
  const Vector *v56; // [esp+4h] [ebp-BCh]
  const Vector *v57; // [esp+4h] [ebp-BCh]
  const Vector *v58; // [esp+4h] [ebp-BCh]
  const Vector *v59; // [esp+4h] [ebp-BCh]
  const Vector *v60; // [esp+4h] [ebp-BCh]
  const Vector *v61; // [esp+4h] [ebp-BCh]
  const Vector *v62; // [esp+4h] [ebp-BCh]
  const char *v63; // [esp+8h] [ebp-B8h]
  float y; // [esp+8h] [ebp-B8h]
  _BYTE v66[12]; // [esp+1Ch] [ebp-A4h] BYREF
  _BYTE tr_32[60]; // [esp+48h] [ebp-78h] OVERLAPPED BYREF
  float *v68; // [esp+84h] [ebp-3Ch]
  Vector v69; // [esp+88h] [ebp-38h] BYREF
  Vector vStep; // [esp+94h] [ebp-2Ch] BYREF
  Vector vLookDir; // [esp+A0h] [ebp-20h] BYREF
  Vector vTargetDir; // [esp+ACh] [ebp-14h] BYREF
  void *v73; // [esp+B8h] [ebp-8h] OVERLAPPED
  void *retaddr; // [esp+C0h] [ebp+0h]

  vTargetDir.z = a2;
  v73 = retaddr;
  if ( !bIgnoreLock
    && (this->m_NodeData.iDisabled != 0
     || this->m_flNextUseTime > gpGlobals->curtime
     || (m_Index = this->m_hHintOwner.m_Index) != -1
     && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
     && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr) )
  {
    if ( (hintCriteria->m_iFlags & 0x80) == 0 )
      return 0;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vTargetDir.z);
    v63 = "Node is locked.";
LABEL_11:
    NDebugOverlay::Text(origin: &this->m_vecAbsOrigin, text: v63, bViewCheck: false, duration: 60.0);
    return 0;
  }
  if ( !bIgnoreHintType
    && !CHintCriteria::MatchesHintType(this: hintCriteria, hintType: this->m_NodeData.nHintType, iszGenericType: 0) )
  {
    return 0;
  }
  minState = this->m_NodeData.minState;
  if ( (minState > NPC_STATE_IDLE || this->m_NodeData.maxState < NPC_STATE_COMBAT) && pNPC != nullptr )
  {
    m_NPCState = pNPC->m_NPCState;
    if ( m_NPCState < minState || m_NPCState > this->m_NodeData.maxState )
    {
      if ( (hintCriteria->m_iFlags & 0x80) == 0 )
        return 0;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vTargetDir.z);
      v63 = "NPC not in correct state.";
      goto LABEL_11;
    }
  }
  pszValue = hintCriteria->m_strGroup.pszValue;
  if ( pszValue != nullptr )
  {
    v15 = this->m_NodeData.strGroup.pszValue;
    if ( v15 == nullptr || v15 != pszValue )
    {
      if ( (hintCriteria->m_iFlags & 0x80) == 0 )
        return 0;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vTargetDir.z);
      v63 = "Doesn't match NPC hint group.";
      goto LABEL_11;
    }
  }
  if ( hintCriteria->m_zoneInclude.m_Size != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vTargetDir.z);
    if ( CHintCriteria::InZone(
           this: hintCriteria,
           zone: &hintCriteria->m_zoneInclude,
           testPosition: &this->m_vecAbsOrigin) == 0 )
    {
      if ( (hintCriteria->m_iFlags & 0x80) != 0 )
      {
        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Text(origin: AbsOrigin, text: "Not inside include zones.", bViewCheck: false, duration: 60.0);
      }
      return 0;
    }
  }
  if ( hintCriteria->m_zoneExclude.m_Size != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vTargetDir.z);
    if ( CHintCriteria::InZone(
           this: hintCriteria,
           zone: &hintCriteria->m_zoneExclude,
           testPosition: &this->m_vecAbsOrigin) != 0 )
    {
      if ( (hintCriteria->m_iFlags & 0x80) != 0 )
      {
        v47 = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Text(origin: v47, text: "Inside exclude zones.", bViewCheck: false, duration: 60.0);
      }
      return 0;
    }
  }
  if ( pNPC != nullptr && !pNPC->FValidateHintType(this: pNPC, a2: this) )
  {
    if ( (hintCriteria->m_iFlags & 0x80) != 0 )
    {
      v48 = CBaseEntity::GetAbsOrigin(this);
      NDebugOverlay::Text(
        origin: v48,
        text: "NPC doesn't know how to handle that type.",
        bViewCheck: false,
        duration: 60.0);
    }
    return 0;
  }
  m_pfnFilter = hintCriteria->m_pfnFilter;
  if ( m_pfnFilter != nullptr && !m_pfnFilter(a1: hintCriteria->m_pFilterContext, a2: this) )
  {
    if ( (hintCriteria->m_iFlags & 0x80) != 0 )
    {
      v49 = CBaseEntity::GetAbsOrigin(this);
      NDebugOverlay::Text(origin: v49, text: "Failed filter test", bViewCheck: false, duration: 60.0);
    }
    return 0;
  }
  LODWORD(vTargetDir.y) = this->m_NodeData.nRadius;
  if ( LODWORD(vTargetDir.y) != 0 )
  {
    v17 = CBaseEntity::GetAbsOrigin(this);
    if ( (float)((float)((float)((float)(v17->y - position->y) * (float)(v17->y - position->y))
                       + (float)((float)(v17->x - position->x) * (float)(v17->x - position->x)))
               + (float)((float)(v17->z - position->z) * (float)(v17->z - position->z))) > (float)(LODWORD(vTargetDir.y)
                                                                                                 * LODWORD(vTargetDir.y)) )
    {
      if ( (hintCriteria->m_iFlags & 0x80) != 0 )
      {
        v50 = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Text(
          origin: v50,
          text: "NPC is not within the node's radius.",
          bViewCheck: false,
          duration: 60.0);
      }
      return 0;
    }
  }
  if ( (hintCriteria->m_iFlags & 0x400) != 0 && pNPC != nullptr && !CAI_Hint::IsInNodeFOV(this, pOther: pNPC) )
  {
    if ( (hintCriteria->m_iFlags & 0x80) != 0 )
    {
      v51 = CBaseEntity::GetAbsOrigin(this);
      NDebugOverlay::Text(origin: v51, text: "NPC Not in hint's FOV", bViewCheck: false, duration: 60.0);
    }
    return 0;
  }
  if ( (hintCriteria->m_iFlags & 0x200) != 0 && pNPC != nullptr )
  {
    LODWORD(vTargetDir.y) = &pNPC->FInAimCone;
    v18 = CBaseEntity::GetAbsOrigin(this);
    if ( (*(unsigned __int8 (__thiscall **)(CAI_BaseNPC *, const Vector *))LODWORD(vTargetDir.y))(a1: pNPC, a2: v18) == 0 )
    {
      if ( (hintCriteria->m_iFlags & 0x80) != 0 )
      {
        v52 = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Text(origin: v52, text: "Hint isn't in NPC's aimcone", bViewCheck: false, duration: 60.0);
      }
      return 0;
    }
  }
  if ( (hintCriteria->m_iFlags & 0x100) != 0 && pNPC != nullptr && !pNPC->FInViewCone(this: pNPC, a2: this) )
  {
    if ( (hintCriteria->m_iFlags & 0x80) != 0 )
    {
      v53 = CBaseEntity::GetAbsOrigin(this);
      NDebugOverlay::Text(origin: v53, text: "Hint isn't in NPC's viewcone", bViewCheck: false, duration: 60.0);
    }
    return 0;
  }
  if ( (hintCriteria->m_iFlags & 0x800) != 0 && pNPC != nullptr && pNPC->GetEnemy_2(this: pNPC) != nullptr )
  {
    v19 = pNPC->GetEnemy_2(this: pNPC);
    LODWORD(vTargetDir.y) = CBaseEntity::GetAbsOrigin(this: v19);
    v20 = CBaseEntity::GetAbsOrigin(this);
    if ( (float)((float)((float)((float)(v20->y - *(float *)(LODWORD(vTargetDir.y) + 4))
                               * (float)(v20->y - *(float *)(LODWORD(vTargetDir.y) + 4)))
                       + (float)((float)(v20->x - *(float *)LODWORD(vTargetDir.y))
                               * (float)(v20->x - *(float *)LODWORD(vTargetDir.y))))
               + (float)((float)(v20->z - *(float *)(LODWORD(vTargetDir.y) + 8))
                       * (float)(v20->z - *(float *)(LODWORD(vTargetDir.y) + 8)))) < 129600.0 )
    {
      if ( (hintCriteria->m_iFlags & 0x80) != 0 )
      {
        v54 = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Text(origin: v54, text: "Hint takes NPC close to Enemy", bViewCheck: false, duration: 60.0);
      }
      return 0;
    }
  }
  if ( (hintCriteria->m_iFlags & 1) != 0 && pNPC != nullptr )
  {
    if ( this->m_NodeData.nNodeID == -1 )
    {
      if ( !pNPC->FVisible_2(this: pNPC, a2: this, a3: 16449, a4: nullptr) )
      {
        if ( (hintCriteria->m_iFlags & 0x80) != 0 )
        {
          v55 = CBaseEntity::GetAbsOrigin(this);
          NDebugOverlay::Text(origin: v55, text: "Hint isn't visible to NPC.", bViewCheck: false, duration: 60.0);
        }
        return 0;
      }
    }
    else
    {
      CAI_Hint::GetPosition(this, pBCC: pNPC, vPosition: &vLookDir);
      v21 = pNPC->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      LODWORD(vTargetDir.y) = pNPC->m_nAITraceMask & 0xFDFFFFFF;
      v22 = (float *)((int (__thiscall *)(CAI_BaseNPC *, int))v21->GetViewOffset)(a1: pNPC, a2: a3);
      vStep.x = vLookDir.x + *v22;
      vStep.y = v22[1] + vLookDir.y;
      y = vTargetDir.y;
      EyePosition = pNPC->EyePosition;
      vStep.z = v22[2] + vLookDir.z;
      v24 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))EyePosition)(a1: pNPC);
      UTIL_TraceLine(
        a1: (const IHandleEntity *)&vTargetDir.z,
        a2: (int)pNPC,
        vecAbsStart: v24,
        vecAbsEnd: &v69,
        mask: (unsigned int)&vStep,
        ignore: (const IHandleEntity *)LODWORD(y),
        collisionGroup: (int)pNPC,
        ptr: nullptr);
      if ( *(float *)tr_32 != 1.0 )
      {
        if ( (hintCriteria->m_iFlags & 0x80) != 0 )
        {
          v56 = CBaseEntity::GetAbsOrigin(this);
          NDebugOverlay::Text(origin: v56, text: "Node isn't visible to NPC.", bViewCheck: false, duration: 60.0);
        }
        return 0;
      }
    }
  }
  if ( (hintCriteria->m_iFlags & 8) != 0 && pNPC != nullptr )
  {
    v69.z = pNPC->StepHeight(this: pNPC);
    BoundingMaxs = CBaseEntity::ScriptGetBoundingMaxs(this: pNPC);
    v26 = BoundingMaxs->z - v69.z;
    vStep.x = BoundingMaxs->x;
    v27 = BoundingMaxs->y;
    vStep.z = v26;
    vStep.y = v27;
    v28 = CBaseEntity::GetAbsOrigin(this);
    x = v28->x;
    vLookDir.z = v28->z + v69.z;
    vLookDir.x = x;
    vLookDir.y = v28->y;
    BoundingMins = CBaseEntity::ScriptGetBoundingMins(this: pNPC);
    v30 = CBaseEntity::GetAbsOrigin(this);
    UTIL_TraceHull(
      a1: (const IHandleEntity *)&vTargetDir.z,
      a2: (int)pNPC,
      vecAbsStart: &vLookDir,
      vecAbsEnd: v30,
      hullMin: BoundingMins,
      hullMax: &vStep,
      mask: 0x200400Bu,
      ignore: pNPC,
      collisionGroup: 0,
      ptr: (CGameTrace *)v66);
    if ( *(float *)tr_32 < 0.95 )
    {
      if ( (hintCriteria->m_iFlags & 0x80) != 0 )
      {
        v57 = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Text(origin: v57, text: "Node isn't clear.", bViewCheck: false, duration: 60.0);
      }
      return 0;
    }
  }
  if ( (hintCriteria->m_iFlags & 2) != 0 )
  {
    v31 = CBaseEntity::GetAbsOrigin(this);
    v32 = 0;
    *(float *)&v32 = fsqrt(
                       (float)((float)((float)(v31->y - position->y) * (float)(v31->y - position->y))
                             + (float)((float)(v31->z - position->z) * (float)(v31->z - position->z)))
                     + (float)((float)(v31->x - position->x) * (float)(v31->x - position->x)));
    *(_OWORD *)&tr_32[44] = v32;
    if ( *(float *)&v32 > *flNearestDistance )
    {
      if ( (hintCriteria->m_iFlags & 0x80) != 0 )
      {
        v58 = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Text(origin: v58, text: "Not the nearest node.", bViewCheck: false, duration: 60.0);
      }
      return 0;
    }
    *flNearestDistance = *(float *)&tr_32[44];
  }
  if ( (hintCriteria->m_iFlags & 0x3000) != 0 && gpGlobals->maxClients <= 1 )
  {
    LODWORD(vTargetDir.y) = UTIL_GetLocalPlayer();
    if ( LODWORD(vTargetDir.y) != 0 )
    {
      v33 = CBaseEntity::GetAbsOrigin(this);
      m_iFlags = hintCriteria->m_iFlags;
      vLookDir = *v33;
      if ( (m_iFlags & 0x2000) != 0 )
      {
        vLookDir.x = vLookDir.x + pNPC->m_vDefaultEyeOffset.x;
        vLookDir.y = pNPC->m_vDefaultEyeOffset.y + vLookDir.y;
        vLookDir.z = pNPC->m_vDefaultEyeOffset.z + vLookDir.z;
      }
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD, Vector *, int, _DWORD))(*(_DWORD *)LODWORD(vTargetDir.y) + 552))(
             a1: LODWORD(vTargetDir.y),
             a2: &vLookDir,
             a3: 16449,
             a4: 0) == 0 )
      {
        if ( (hintCriteria->m_iFlags & 0x80) != 0 )
        {
          v59 = CBaseEntity::GetAbsOrigin(this);
          NDebugOverlay::Text(origin: v59, text: "Do not have LOS to player", bViewCheck: false, duration: 60.0);
        }
        return 0;
      }
    }
  }
  if ( (hintCriteria->m_iFlags & 0x4000) != 0 )
  {
    LODWORD(vTargetDir.y) = pNPC->GetEnemy_2(this: pNPC);
    if ( LODWORD(vTargetDir.y) != 0 )
    {
      v35 = CBaseEntity::GetAbsOrigin(this);
      GetNodeViewOffset = pNPC->GetNodeViewOffset;
      vLookDir = *v35;
      v37 = (float *)GetNodeViewOffset(this: pNPC, result: &v69);
      vLookDir.x = vLookDir.x + *v37;
      vLookDir.y = v37[1] + vLookDir.y;
      v38 = v37[2] + vLookDir.z;
      v39 = *(unsigned __int8 (__thiscall **)(_DWORD, Vector *, int, _DWORD))(*(_DWORD *)LODWORD(vTargetDir.y) + 552);
      vLookDir.z = v38;
      if ( v39(a1: LODWORD(vTargetDir.y), a2: &vLookDir, a3: 16449, a4: 0) != 0 )
      {
        if ( (hintCriteria->m_iFlags & 0x80) != 0 )
        {
          v60 = CBaseEntity::GetAbsOrigin(this);
          NDebugOverlay::Text(origin: v60, text: "Has LOS to enemy", bViewCheck: false, duration: 60.0);
        }
        return 0;
      }
    }
  }
  if ( (hintCriteria->m_iFlags & 0x60) != 0 )
  {
    HIBYTE(vTargetDir.x) = 0;
    LODWORD(vTargetDir.y) = 1;
    if ( gpGlobals->maxClients >= 1 )
    {
      do
      {
        v40 = UTIL_PlayerByIndex(playerIndex: SLODWORD(vTargetDir.y));
        if ( v40 != nullptr )
        {
          v40->EyeDirection3D(this: v40, result: &vStep);
          v68 = (float *)v40->EyePosition(this: v40, result: &v69);
          v41 = CBaseEntity::GetAbsOrigin(this);
          vLookDir.x = v41->x - *v68;
          vLookDir.y = v41->y - v68[1];
          vLookDir.z = v41->z - v68[2];
          VectorNormalize(vec: &vLookDir);
          if ( (float)((float)((float)(vStep.y * vLookDir.y) + (float)(vLookDir.x * vStep.x))
                     + (float)(vStep.z * vLookDir.z)) > 0.0 )
          {
            v45 = CBaseEntity::GetAbsOrigin(this);
            v42 = v40->EyePosition(this: v40, result: (Vector *)&tr_32[48]);
            UTIL_TraceLine(
              a1: (const IHandleEntity *)&vTargetDir.z,
              a2: (int)v40,
              vecAbsStart: v42,
              vecAbsEnd: v45,
              mask: 0x400Bu,
              ignore: v40,
              collisionGroup: 0,
              ptr: (CGameTrace *)v66);
            if ( *(float *)tr_32 == 1.0 )
            {
              if ( (hintCriteria->m_iFlags & 0x40) != 0 )
              {
                if ( (hintCriteria->m_iFlags & 0x80) != 0 )
                {
                  v62 = CBaseEntity::GetAbsOrigin(this);
                  NDebugOverlay::Text(
                    origin: v62,
                    text: "Node is visible to player.",
                    bViewCheck: false,
                    duration: 60.0);
                }
                return 0;
              }
              HIBYTE(vTargetDir.x) = 1;
            }
          }
        }
        ++LODWORD(vTargetDir.y);
      }
      while ( SLODWORD(vTargetDir.y) <= gpGlobals->maxClients );
      if ( HIBYTE(vTargetDir.x) != 0 )
        return 1;
    }
    v43 = hintCriteria->m_iFlags;
    if ( (v43 & 0x20) != 0 )
    {
      if ( (v43 & 0x80) != 0 )
      {
        v61 = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Text(origin: v61, text: "Node isn't visible to player.", bViewCheck: false, duration: 60.0);
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10054D40
// Name: ai_dump_hints
// Source: json
//------------------------------------------------------------------------------
void __usercall ai_dump_hints(int a1@<ebp>)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CAI_HintManager::DumpHints(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100550E0
// Name: public: void CHintCriteria::SetHintType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintCriteria::SetHintType(CHintCriteria *this, int nHintType)
{
  bool v3; // sf
  int *m_pMemory; // ecx

  v3 = this->m_HintTypes.m_Memory.m_nGrowSize < 0;
  this->m_iFirstHintType = nHintType;
  this->m_iLastHintType = 0;
  this->m_HintTypes.m_Size = 0;
  if ( v3 )
  {
    this->m_HintTypes.m_pElements = this->m_HintTypes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_HintTypes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HintTypes.m_Memory.m_pMemory);
      this->m_HintTypes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_HintTypes.m_Memory.m_pMemory;
    this->m_HintTypes.m_Memory.m_nAllocationCount = 0;
    this->m_HintTypes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055140
// Name: public: static void CAI_HintManager::DrawHintOverlays(float)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_HintManager::DrawHintOverlays(double a1@<esi:edi>, float flDrawDuration)
{
  int v2; // eax
  CAI_Hint *v3; // esi
  int nNodeID; // eax
  int v5; // ebx
  CAI_Node *v6; // eax
  Vector *Position; // eax
  float z; // xmm0_4
  CFmtStrN<256> *v9; // eax
  CFmtStrN<256> *v10; // eax
  unsigned int m_Index; // ecx
  CBaseEntity **v12; // eax
  CBaseEntity *v13; // edi
  const char *DebugName; // eax
  const Vector *v15; // eax
  int v16; // edi
  int y_low; // xmm0_4
  int v18; // eax
  int v19; // xmm0_4
  long double v20; // [esp+4h] [ebp-190h]
  long double v21; // [esp+4h] [ebp-190h]
  CFmtStrN<256> v22; // [esp+10h] [ebp-184h] BYREF
  Vector result; // [esp+11Ch] [ebp-78h] BYREF
  Vector origin; // [esp+128h] [ebp-6Ch] BYREF
  Vector v25; // [esp+134h] [ebp-60h] BYREF
  Vector target; // [esp+140h] [ebp-54h] BYREF
  Vector mins; // [esp+14Ch] [ebp-48h] BYREF
  Vector maxs; // [esp+158h] [ebp-3Ch] BYREF
  int c; // [esp+164h] [ebp-30h]
  float v30; // [esp+168h] [ebp-2Ch]
  Vector loc; // [esp+16Ch] [ebp-28h] BYREF
  int i; // [esp+178h] [ebp-1Ch]
  int g; // [esp+17Ch] [ebp-18h]
  int b; // [esp+180h] [ebp-14h]
  int r; // [esp+184h] [ebp-10h]
  Vector vHintPos; // [esp+188h] [ebp-Ch] BYREF
  int savedregs; // [esp+194h] [ebp+0h] BYREF

  v2 = 0;
  c = CAI_HintManager::gm_AllHints.m_Size;
  i = 0;
  if ( CAI_HintManager::gm_AllHints.m_Size > 0 )
  {
    v20 = a1;
    do
    {
      v3 = CAI_HintManager::gm_AllHints.m_Memory.m_pMemory[v2];
      nNodeID = v3->m_NodeData.nNodeID;
      v5 = 0;
      *(float *)&r = 0.0;
      g = 0;
      b = 255;
      if ( nNodeID == -1 )
      {
        if ( (v3->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
        vHintPos.x = v3->m_vecAbsOrigin.x;
        vHintPos.y = v3->m_vecAbsOrigin.y;
        z = v3->m_vecAbsOrigin.z;
      }
      else
      {
        if ( nNodeID < 0 || nNodeID >= g_pBigAINet->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          v6 = nullptr;
        }
        else
        {
          v6 = g_pBigAINet->m_pAInode[nNodeID];
        }
        Position = CAI_Node::GetPosition(this: v6, &result, hull: CAI_NetworkEditTools::m_iHullDrawNum);
        vHintPos.x = Position->x;
        vHintPos.y = Position->y;
        z = Position->z;
      }
      vHintPos.z = z;
      if ( v3->m_NodeData.nNodeID == -1 )
      {
        v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v22, pszFormat: "(%d)", v3->m_NodeData.nHintType);
        origin.x = vHintPos.x;
        origin.y = vHintPos.y + 6.0;
        origin.z = vHintPos.z + 8.0;
        NDebugOverlay::Text(&origin, text: v10->m_szBuf, bViewCheck: true, duration: flDrawDuration);
      }
      else
      {
        v9 = CFmtStrN<256>::CFmtStrN<256>(
               this: &v22,
               pszFormat: "(%d), (%d)",
               v3->m_NodeData.nHintType,
               v3->m_NodeData.nNodeID);
        v25.x = vHintPos.x;
        v25.y = vHintPos.y + 6.0;
        v25.z = vHintPos.z + 8.0;
        NDebugOverlay::Text(origin: &v25, text: v9->m_szBuf, bViewCheck: true, duration: flDrawDuration);
      }
      if ( v3->m_NodeData.iDisabled != 0 )
      {
        v5 = 100;
        g = 100;
        b = 100;
      }
      else
      {
        m_Index = v3->m_hHintOwner.m_Index;
        if ( m_Index == -1 )
          goto LABEL_24;
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
        {
          v5 = r;
LABEL_24:
          if ( v3->m_flNextUseTime > gpGlobals->curtime
            || m_Index != -1
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
          {
            v5 = 200;
            g = 150;
            b = 10;
          }
          goto LABEL_29;
        }
        v12 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v5 = 255;
        g = 0;
        b = 0;
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          v13 = *v12;
          if ( *v12 != nullptr )
          {
            DebugName = CBaseEntity::GetDebugName(this: v13);
            V_strncpy(pDest: &v22.m_szBuf[7], pSrc: DebugName, maxLen: 255);
            loc.x = vHintPos.x + 6.0;
            loc.y = vHintPos.y + 6.0;
            loc.z = vHintPos.z + 6.0;
            NDebugOverlay::Text(origin: &loc, text: &v22.m_szBuf[7], bViewCheck: true, duration: flDrawDuration);
            v15 = v13->WorldSpaceCenter(this: v13);
            NDebugOverlay::Line(
              origin: &vHintPos,
              target: v15,
              r: 128,
              g: 128,
              b: 128,
              noDepthTest: false,
              duration: 0.0);
          }
        }
      }
LABEL_29:
      v16 = g;
      maxs.x = 3.0;
      maxs.y = 3.0;
      maxs.z = 3.0;
      mins.x = -3.0;
      mins.y = -3.0;
      mins.z = -3.0;
      NDebugOverlay::Box(origin: &vHintPos, &mins, &maxs, r: v5, g, b, a: 0, flDuration: flDrawDuration);
      if ( v3->m_NodeData.nNodeID == -1 )
      {
        y_low = SLODWORD(v3->m_angRotation.m_Value.y);
      }
      else
      {
        *(float *)&r = CAI_Network::GetNodeYaw(this: g_pBigAINet, nodeID: v3->m_NodeData.nNodeID);
        y_low = r;
      }
      __libm_sse2_sin(x: v20);
      v18 = v3->m_NodeData.nNodeID;
      v30 = *(float *)&y_low * 0.017453292;
      if ( v18 == -1 )
      {
        v19 = SLODWORD(v3->m_angRotation.m_Value.y);
      }
      else
      {
        *(float *)&r = CAI_Network::GetNodeYaw(this: g_pBigAINet, nodeID: v18);
        v19 = r;
      }
      __libm_sse2_cos(x: v21);
      target.x = (float)((float)(*(float *)&v19 * 0.017453292) * 12.0) + vHintPos.x;
      target.z = vHintPos.z;
      target.y = (float)(v30 * 12.0) + vHintPos.y;
      NDebugOverlay::Line(origin: &vHintPos, &target, r: v5, g: v16, b, noDepthTest: false, duration: flDrawDuration);
      v2 = i + 1;
      i = v2;
    }
    while ( v2 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100555A0
// Name: public: class Vector CAI_Hint::GetDirection(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_Hint::GetDirection(CAI_Hint *this, Vector *result)
{
  int nNodeID; // eax
  float yaw; // xmm0_4
  float NodeYaw; // [esp+8h] [ebp-4h]

  nNodeID = this->m_NodeData.nNodeID;
  if ( nNodeID == -1 )
  {
    yaw = this->m_angRotation.m_Value.y;
  }
  else
  {
    NodeYaw = CAI_Network::GetNodeYaw(this: g_pBigAINet, nodeID: nNodeID);
    yaw = NodeYaw;
  }
  UTIL_YawToVector(result, yaw);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100555F0
// Name: public: CAI_Hint::CAI_Hint(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__thiscall CAI_Hint::CAI_Hint(CAI_Hint *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CAI_Hint_vtbl *)&CAI_Hint::`vftable';
  this->m_hHintOwner.m_Index = -1;
  this->m_OnNPCStartedUsing.m_Value.iVal = 0;
  this->m_OnNPCStartedUsing.m_Value.eVal.m_Index = -1;
  this->m_OnNPCStartedUsing.m_Value.fieldType = FIELD_VOID;
  this->m_OnNPCStoppedUsing.m_Value.iVal = 0;
  this->m_OnNPCStoppedUsing.m_Value.eVal.m_Index = -1;
  this->m_OnNPCStoppedUsing.m_Value.fieldType = FIELD_VOID;
  this->m_flNextUseTime = 0.0;
  this->m_nTargetNodeID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10055E00
// Name: public: CHintCriteria::CHintCriteria(void)
// Source: json
//------------------------------------------------------------------------------
CHintCriteria *__thiscall CHintCriteria::CHintCriteria(CHintCriteria *this)
{
  int *m_pMemory; // ecx

  this->m_HintTypes.m_Memory.m_nGrowSize = 0;
  this->m_HintTypes.m_Memory.m_pMemory = nullptr;
  this->m_HintTypes.m_Memory.m_nAllocationCount = 0;
  this->m_HintTypes.m_pElements = nullptr;
  this->m_zoneInclude.m_Memory.m_pMemory = nullptr;
  this->m_zoneInclude.m_Memory.m_nAllocationCount = 0;
  this->m_zoneInclude.m_Memory.m_nGrowSize = 0;
  this->m_zoneInclude.m_Size = 0;
  this->m_zoneInclude.m_pElements = nullptr;
  this->m_zoneExclude.m_Memory.m_pMemory = nullptr;
  this->m_zoneExclude.m_Memory.m_nAllocationCount = 0;
  this->m_zoneExclude.m_Memory.m_nGrowSize = 0;
  this->m_zoneExclude.m_Size = 0;
  this->m_zoneExclude.m_pElements = nullptr;
  this->m_iFirstHintType = 0;
  this->m_iLastHintType = 0;
  this->m_strGroup.pszValue = nullptr;
  this->m_strGenericType.pszValue = nullptr;
  this->m_iFlags = 0;
  this->m_HintTypes.m_Size = 0;
  if ( this->m_HintTypes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_HintTypes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HintTypes.m_Memory.m_pMemory);
      this->m_HintTypes.m_Memory.m_pMemory = nullptr;
    }
    this->m_HintTypes.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_HintTypes.m_Memory.m_pMemory;
  this->m_pfnFilter = nullptr;
  this->m_pFilterContext = nullptr;
  this->m_HintTypes.m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10055E80
// Name: public: CHintCriteria::~CHintCriteria(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintCriteria::~CHintCriteria(CHintCriteria *this)
{
  this->m_zoneInclude.m_Size = 0;
  if ( this->m_zoneInclude.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_zoneInclude.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_zoneInclude.m_Memory.m_pMemory);
      this->m_zoneInclude.m_Memory.m_pMemory = nullptr;
    }
    this->m_zoneInclude.m_Memory.m_nAllocationCount = 0;
  }
  this->m_zoneInclude.m_pElements = this->m_zoneInclude.m_Memory.m_pMemory;
  this->m_zoneExclude.m_Size = 0;
  if ( this->m_zoneExclude.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_zoneExclude.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_zoneExclude.m_Memory.m_pMemory);
      this->m_zoneExclude.m_Memory.m_pMemory = nullptr;
    }
    this->m_zoneExclude.m_Memory.m_nAllocationCount = 0;
  }
  this->m_zoneExclude.m_pElements = this->m_zoneExclude.m_Memory.m_pMemory;
  this->m_HintTypes.m_Size = 0;
  if ( this->m_HintTypes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_HintTypes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HintTypes.m_Memory.m_pMemory);
      this->m_HintTypes.m_Memory.m_pMemory = nullptr;
    }
    this->m_HintTypes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_HintTypes.m_pElements = this->m_HintTypes.m_Memory.m_pMemory;
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_zoneExclude);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_zoneInclude);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10055F40
// Name: private: void CHintCriteria::AddZone(class CUtlVector<struct CHintCriteria::hintZone_t,class CUtlMemory<struct CHintCriteria::hintZone_t,int>> __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintCriteria::AddZone(
        CHintCriteria *this,
        CUtlVector<CHintCriteria::hintZone_t,CUtlMemory<CHintCriteria::hintZone_t,int> > *list,
        const Vector *position,
        float radius)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHintCriteria::hintZone_t *m_pMemory; // ecx
  int v7; // eax
  int v8; // edi

  m_nAllocationCount = list->m_Memory.m_nAllocationCount;
  m_Size = list->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)list,
      num: m_Size - m_nAllocationCount + 1);
  ++list->m_Size;
  m_pMemory = list->m_Memory.m_pMemory;
  v7 = list->m_Size - m_Size - 1;
  list->m_pElements = list->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v7);
  v8 = m_Size;
  list->m_Memory.m_pMemory[v8].position = *position;
  list->m_Memory.m_pMemory[v8].radiussqr = radius * radius;
}

//------------------------------------------------------------------------------
// Address: 0x10055FC0
// Name: public: void CHintCriteria::AddIncludePosition(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintCriteria::AddIncludePosition(CHintCriteria *this, const Vector *position, float radius)
{
  CHintCriteria::AddZone(this, list: &this->m_zoneInclude, position, radius);
}

//------------------------------------------------------------------------------
// Address: 0x10055FE0
// Name: public: void CHintCriteria::AddExcludePosition(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintCriteria::AddExcludePosition(CHintCriteria *this, const Vector *position, float radius)
{
  CHintCriteria::AddZone(this, list: &this->m_zoneExclude, position, radius);
}

//------------------------------------------------------------------------------
// Address: 0x10056000
// Name: public: static int CAI_HintManager::FindAllHints(class CAI_BaseNPC __near *,class Vector const __near &,class CHintCriteria const __near &,class CUtlVector<class CAI_Hint __near *,class CUtlMemory<class CAI_Hint __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CAI_HintManager::FindAllHints(
        CAI_BaseNPC *pNPC,
        const Vector *position,
        CHintCriteria *hintCriteria,
        CUtlVector<CAI_Hint *,CUtlMemory<CAI_Hint *,int> > *pResult)
{
  int m_Size; // ecx
  CHintCriteria *v6; // edi
  int v7; // ebx
  int v8; // edi
  int m_nAllocationCount; // eax
  CAI_Hint **m_pMemory; // ecx
  int v11; // eax
  CAI_Hint **v12; // eax
  int c; // [esp+0h] [ebp-Ch]
  CAI_Hint *pTestHint; // [esp+4h] [ebp-8h]
  bool hadNearest; // [esp+Bh] [ebp-1h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  m_Size = CAI_HintManager::gm_AllHints.m_Size;
  c = CAI_HintManager::gm_AllHints.m_Size;
  if ( CAI_HintManager::gm_AllHints.m_Size == 0 )
    return 0;
  v6 = hintCriteria;
  v7 = 0;
  hadNearest = (hintCriteria->m_iFlags & 2) != 0;
  hintCriteria->m_iFlags &= ~2u;
  if ( m_Size > 0 )
  {
    do
    {
      pTestHint = CAI_HintManager::gm_AllHints.m_Memory.m_pMemory[v7];
      if ( CAI_Hint::HintMatchesCriteria(
             this: pTestHint,
             a2: COERCE_FLOAT(&savedregs),
             a3: (int)v6,
             pNPC,
             hintCriteria: v6,
             position,
             flNearestDistance: nullptr,
             bIgnoreLock: false,
             bIgnoreHintType: false) != 0 )
      {
        v8 = pResult->m_Size;
        m_nAllocationCount = pResult->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)pResult,
            num: v8 - m_nAllocationCount + 1);
        ++pResult->m_Size;
        m_pMemory = pResult->m_Memory.m_pMemory;
        v11 = pResult->m_Size - v8 - 1;
        pResult->m_pElements = pResult->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &pResult->m_Memory.m_pMemory[v8];
        v6 = hintCriteria;
        if ( v12 != nullptr )
          *v12 = pTestHint;
      }
      ++v7;
    }
    while ( v7 < c );
  }
  if ( hadNearest )
    v6->m_iFlags |= 2u;
  return pResult->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100560D0
// Name: public: static class CAI_Hint __near * CAI_HintManager::FindHintRandom(class CAI_BaseNPC __near *,class Vector const __near &,class CHintCriteria const __near &)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__cdecl CAI_HintManager::FindHintRandom(
        CAI_BaseNPC *pNPC,
        const Vector *position,
        CHintCriteria *hintCriteria)
{
  int v3; // eax
  CAI_Hint *v4; // esi
  CUtlVector<CAI_Hint *,CUtlMemory<CAI_Hint *,int> > hintList; // [esp+4h] [ebp-14h] BYREF

  memset(&hintList, 0, sizeof(hintList));
  if ( CAI_HintManager::FindAllHints(pNPC, position, hintCriteria, pResult: &hintList) <= 0 )
  {
    _V_memset(dest: CAI_HintManager::gm_pLastFoundHints, fill: 0, count: 32);
    CAI_HintManager::gm_nFoundHintIndex = 0;
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hintList);
    return nullptr;
  }
  else
  {
    v3 = random->RandomInt(this: random, a2: 0, a3: hintList.m_Size - 1);
    v4 = hintList.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      CAI_HintManager::gm_nFoundHintIndex = ((_BYTE)CAI_HintManager::gm_nFoundHintIndex + 1) & 7;
      CAI_HintManager::gm_pLastFoundHints[CAI_HintManager::gm_nFoundHintIndex] = v4;
    }
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hintList);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056170
// Name: public: static class CAI_Hint __near * CAI_HintManager::CreateHint(struct HintNodeData __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__cdecl CAI_HintManager::CreateHint(HintNodeData *pNodeData, char *pMapData)
{
  CBaseEntity *EntityByName; // ebx
  const char *pszValue; // esi
  CBaseEdict *v4; // ecx
  CEntityMapData entData; // [esp+4h] [ebp-Ch] BYREF

  _V_memset(dest: CAI_HintManager::gm_pLastFoundHints, fill: 0, count: 32);
  CAI_HintManager::gm_nFoundHintIndex = 0;
  EntityByName = CreateEntityByName(className: "ai_hint", iForceEdictIndex: -1, bNotify: true);
  if ( EntityByName == nullptr )
    return nullptr;
  if ( pMapData != nullptr )
  {
    entData.m_pEntData = pMapData;
    entData.m_pCurrentKey = pMapData;
    entData.m_nEntDataSize = -1;
    CBaseEntity::ParseMapData(this: EntityByName, mapData: &entData);
    CBaseEntity::SetClassname(this: EntityByName, className: "ai_hint");
  }
  pszValue = pNodeData->strEntityName.pszValue;
  if ( EntityByName->m_iName.m_Value.pszValue != pNodeData->strEntityName.pszValue )
  {
    if ( EntityByName->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&EntityByName->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = &EntityByName->m_Network.m_pPev->CBaseEdict;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: v4, offset: 0xCCu);
    }
    EntityByName->m_iName.m_Value.pszValue = pszValue;
  }
  CGlobalEntityList::UpdateName(this: &gEntList, pEnt: EntityByName);
  CBaseEntity::SetAbsOrigin(this: EntityByName, absOrigin: &pNodeData->vecPosition);
  qmemcpy(&EntityByName[1], pNodeData, 0x40u);
  DispatchSpawn(pEntity: EntityByName, bRunVScripts: true);
  return (CAI_Hint *)EntityByName;
}

//------------------------------------------------------------------------------
// Address: 0x10056250
// Name: void CC_ai_drop_hint(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_ai_drop_hint(const CCommand *args)
{
  CBasePlayer *CommandClient; // edi
  unsigned int v2; // esi
  Vector *v3; // eax
  bool v4; // cc
  const char *v5; // eax
  CAI_Hint *v6; // eax
  _DWORD *v7; // edi
  HintNodeData nodeData; // [esp+8h] [ebp-4Ch] BYREF
  Vector v9; // [esp+48h] [ebp-Ch] BYREF

  CommandClient = UTIL_GetCommandClient();
  v2 = 0;
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    if ( args->m_nArgc >= 2 )
    {
      nodeData.strEntityName.pszValue = "ai_drop_hint";
      v3 = CommandClient->EyePosition(this: CommandClient, result: &v9);
      v4 = args->m_nArgc <= 1;
      nodeData.vecPosition = *v3;
      v5 = locale;
      if ( !v4 )
        v5 = args->m_ppArgv[1];
      nodeData.nHintType = atoi(nptr: v5);
      nodeData.nNodeID = -1;
      nodeData.strGroup.pszValue = nullptr;
      nodeData.iDisabled = 0;
      nodeData.iszActivityName.pszValue = nullptr;
      nodeData.fIgnoreFacing = HIF_DEFAULT;
      nodeData.minState = NPC_STATE_IDLE;
      nodeData.maxState = NPC_STATE_COMBAT;
      nodeData.nRadius = 0;
      v6 = CAI_HintManager::CreateHint(pNodeData: &nodeData, pMapData: nullptr);
      v7 = &v6->__vftable;
      if ( v6 != nullptr )
      {
        v6->Activate(this: v6);
        (*(void (__thiscall **)(_DWORD *, const char *, const char *))(*v7 + 136))(a1: v7, a2: "nodeFOV", a3: "360");
        v7[201] |= 5u;
      }
    }
    else
    {
      _Msg(a1: "Invalid hint type specified. Format: ai_drop_hint <hint type>\nValid hint types:\n");
      do
      {
        _Msg(a1: "%d : %s\n", g_pszHintDescriptions[v2 / 2].iType, (&off_10568F3C)[v2]);
        v2 += 2;
      }
      while ( v2 < 44 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100564C0
// Name: public: void CHintCriteria::AddHintType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintCriteria::AddHintType(CHintCriteria *this, int hintType)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // eax

  m_nAllocationCount = this->m_HintTypes.m_Memory.m_nAllocationCount;
  m_Size = this->m_HintTypes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_HintTypes.m_Size;
  m_pMemory = this->m_HintTypes.m_Memory.m_pMemory;
  v6 = this->m_HintTypes.m_Size - m_Size - 1;
  this->m_HintTypes.m_pElements = this->m_HintTypes.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_HintTypes.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hintType;
}

//------------------------------------------------------------------------------
// Address: 0x10056520
// Name: public: static class CAI_Hint __near * CAI_HintManager::FindHint(class CAI_BaseNPC __near *,class Vector const __near &,class CHintCriteria const __near &)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__cdecl CAI_HintManager::FindHint(CAI_BaseNPC *pNPC, const Vector *position, CHintCriteria *hintCriteria)
{
  CHintCriteria *v3; // edi
  CAI_Hint *m_Size; // ecx
  int v5; // ebx
  bool v6; // al
  int v7; // esi
  int m_iFirstHintType; // edi
  int v9; // edi
  CAIHintVector *p_elem; // edi
  CAIHintVector **m_pMemory; // esi
  int v12; // eax
  int v13; // edi
  int v14; // edi
  CAIHintVector **v15; // ecx
  int v16; // eax
  int *v17; // edi
  CAIHintVector **v18; // esi
  CAI_Hint *v20; // edi
  int v21; // ecx
  CAIHintVector *v22; // ebx
  int v23; // eax
  int v24; // edi
  CAI_Hint *v25; // esi
  CUtlMap<int,CAIHintVector,unsigned short>::Node_t search; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<CAIHintVector *,CUtlMemory<CAIHintVector *,int> > lists; // [esp+24h] [ebp-30h] BYREF
  int count; // [esp+38h] [ebp-1Ch]
  int listNum; // [esp+3Ch] [ebp-18h]
  BOOL bIgnoreHintType; // [esp+40h] [ebp-14h]
  CAI_Hint *pBestHint; // [esp+44h] [ebp-10h]
  float flBestDistance; // [esp+48h] [ebp-Ch] BYREF
  int listType; // [esp+4Ch] [ebp-8h]
  bool lookingForNearest; // [esp+53h] [ebp-1h]
  int savedregs; // [esp+54h] [ebp+0h] BYREF

  v3 = hintCriteria;
  m_Size = (CAI_Hint *)hintCriteria->m_HintTypes.m_Size;
  v5 = 0;
  pBestHint = m_Size;
  v6 = m_Size == nullptr && hintCriteria->m_iFirstHintType != -1 && hintCriteria->m_iLastHintType == 0;
  v7 = 0;
  lookingForNearest = (hintCriteria->m_iFlags & 2) != 0;
  LOBYTE(bIgnoreHintType) = 1;
  memset(&lists, 0, sizeof(lists));
  if ( v6 )
  {
    m_iFirstHintType = hintCriteria->m_iFirstHintType;
    search.elem.m_Memory.m_pMemory = nullptr;
    search.elem.m_Memory.m_nAllocationCount = 0;
    search.elem.m_Memory.m_nGrowSize = 1;
    search.elem.m_Size = 0;
    search.elem.m_pElements = nullptr;
    search.key = m_iFirstHintType;
    v9 = CUtlRBTree<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short,CUtlMap<int,CAIHintVector,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &CAI_HintManager::gm_TypedHints.m_Tree,
           &search);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem);
    if ( v9 == 0xFFFF )
      goto LABEL_30;
    p_elem = &CAI_HintManager::gm_TypedHints.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&lists, num: 1);
    m_pMemory = lists.m_Memory.m_pMemory;
    ++lists.m_Size;
    lists.m_pElements = lists.m_Memory.m_pMemory;
    if ( lists.m_Size - 1 > 0 )
      _V_memmove(dest: lists.m_Memory.m_pMemory + 1, src: lists.m_Memory.m_pMemory, count: 4 * (lists.m_Size - 1));
    if ( m_pMemory != nullptr )
      *m_pMemory = p_elem;
    goto LABEL_29;
  }
  if ( (int)m_Size <= 0 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&lists, num: 1);
    v18 = lists.m_Memory.m_pMemory;
    ++lists.m_Size;
    lists.m_pElements = lists.m_Memory.m_pMemory;
    if ( lists.m_Size - 1 > 0 )
      _V_memmove(dest: lists.m_Memory.m_pMemory + 1, src: lists.m_Memory.m_pMemory, count: 4 * (lists.m_Size - 1));
    if ( v18 != nullptr )
      *v18 = &CAI_HintManager::gm_AllHints;
    LOBYTE(bIgnoreHintType) = 0;
LABEL_29:
    v7 = lists.m_Size;
    goto LABEL_30;
  }
  listType = 0;
  while ( 1 )
  {
    v12 = v3->m_HintTypes.m_Memory.m_pMemory[listType];
    search.elem.m_Memory.m_pMemory = nullptr;
    search.elem.m_Memory.m_nAllocationCount = 0;
    search.elem.m_Memory.m_nGrowSize = 1;
    search.elem.m_Size = 0;
    search.elem.m_pElements = nullptr;
    search.key = v12;
    v13 = CUtlRBTree<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short,CUtlMap<int,CAIHintVector,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: &CAI_HintManager::gm_TypedHints.m_Tree,
            &search);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem);
    if ( v13 != 0xFFFF )
    {
      listNum = (int)&CAI_HintManager::gm_TypedHints.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem;
      v14 = v7;
      if ( v7 + 1 > lists.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&lists,
          num: v7 - lists.m_Memory.m_nAllocationCount + 1);
        v7 = lists.m_Size;
      }
      v15 = lists.m_Memory.m_pMemory;
      v16 = ++v7 - v14 - 1;
      lists.m_Size = v7;
      lists.m_pElements = lists.m_Memory.m_pMemory;
      if ( v16 > 0 )
      {
        _V_memmove(dest: &lists.m_Memory.m_pMemory[v14 + 1], src: &lists.m_Memory.m_pMemory[v14], count: 4 * v16);
        v15 = lists.m_Memory.m_pMemory;
      }
      v17 = (int *)&v15[v14];
      if ( v17 != nullptr )
        *v17 = listNum;
    }
    if ( ++listType >= (int)pBestHint )
      break;
    v3 = hintCriteria;
  }
LABEL_30:
  pBestHint = nullptr;
  listType = 0;
  if ( v7 == 0 )
  {
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&lists);
    return nullptr;
  }
  flBestDistance = 56755.84;
  if ( !lookingForNearest )
  {
    do
    {
      v20 = CAI_HintManager::gm_pLastFoundHints[((_BYTE)v5 + (_BYTE)CAI_HintManager::gm_nFoundHintIndex) & 7];
      if ( v20 != nullptr )
      {
        ++listType;
        if ( CAI_Hint::HintMatchesCriteria(
               this: v20,
               a2: COERCE_FLOAT(&savedregs),
               a3: (int)v20,
               pNPC,
               hintCriteria,
               position,
               flNearestDistance: &flBestDistance,
               bIgnoreLock: false,
               bIgnoreHintType: false) != 0 )
        {
          CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&lists);
          return v20;
        }
      }
      ++v5;
    }
    while ( v5 < 8 );
  }
  v21 = 0;
  flBestDistance = 56755.84;
  listNum = 0;
  if ( v7 <= 0 )
    goto LABEL_47;
  while ( 1 )
  {
    v22 = lists.m_Memory.m_pMemory[v21];
    v23 = v22->m_Size;
    count = v23;
    if ( v23 != 0 )
    {
      v24 = 0;
      if ( v23 > 0 )
        break;
    }
LABEL_44:
    listNum = ++v21;
    if ( v21 >= v7 )
    {
      if ( pBestHint != nullptr )
      {
        CAI_HintManager::gm_nFoundHintIndex = ((_BYTE)CAI_HintManager::gm_nFoundHintIndex + 1) & 7;
        CAI_HintManager::gm_pLastFoundHints[CAI_HintManager::gm_nFoundHintIndex] = pBestHint;
      }
LABEL_47:
      if ( lists.m_Memory.m_nGrowSize >= 0 && lists.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: lists.m_Memory.m_pMemory);
      return pBestHint;
    }
  }
  while ( 1 )
  {
    v25 = v22->m_Memory.m_pMemory[v24];
    ++listType;
    if ( CAI_Hint::HintMatchesCriteria(
           this: v25,
           a2: COERCE_FLOAT(&savedregs),
           a3: v24,
           pNPC,
           hintCriteria,
           position,
           flNearestDistance: &flBestDistance,
           bIgnoreLock: false,
           bIgnoreHintType) != 0 )
      break;
LABEL_42:
    if ( ++v24 >= count )
    {
      v21 = listNum;
      v7 = lists.m_Size;
      goto LABEL_44;
    }
  }
  if ( lookingForNearest )
  {
    pBestHint = v25;
    goto LABEL_42;
  }
  if ( v25 != nullptr )
  {
    CAI_HintManager::gm_nFoundHintIndex = ((_BYTE)CAI_HintManager::gm_nFoundHintIndex + 1) & 7;
    CAI_HintManager::gm_pLastFoundHints[CAI_HintManager::gm_nFoundHintIndex] = v25;
  }
  if ( lists.m_Memory.m_nGrowSize >= 0 && lists.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: lists.m_Memory.m_pMemory);
  return v25;
}

//------------------------------------------------------------------------------
// Address: 0x10056890
// Name: public: static class CAI_Hint __near * CAI_HintManager::FindHint(class CAI_BaseNPC __near *,enum Hint_e,int,float,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__cdecl CAI_HintManager::FindHint(
        CAI_BaseNPC *pNPC,
        Hint_e nHintType,
        int nFlags,
        float flMaxDist,
        const Vector *pMaxDistFrom)
{
  int *m_pMemory; // eax
  Vector *p_m_vecAbsOrigin; // eax
  __int64 v8; // xmm0_8
  float z; // eax
  CAI_Hint *HintRandom; // esi
  CHintCriteria hintCriteria; // [esp+10h] [ebp-64h] BYREF
  Vector vecPosition; // [esp+68h] [ebp-Ch] BYREF
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  if ( pNPC == nullptr )
    return nullptr;
  CHintCriteria::CHintCriteria(this: &hintCriteria);
  hintCriteria.m_iFirstHintType = nHintType;
  m_pMemory = hintCriteria.m_HintTypes.m_Memory.m_pMemory;
  hintCriteria.m_iLastHintType = 0;
  hintCriteria.m_HintTypes.m_Size = 0;
  if ( hintCriteria.m_HintTypes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( hintCriteria.m_HintTypes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hintCriteria.m_HintTypes.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      hintCriteria.m_HintTypes.m_Memory.m_pMemory = nullptr;
    }
    hintCriteria.m_HintTypes.m_Memory.m_nAllocationCount = 0;
  }
  hintCriteria.m_iFlags |= nFlags;
  hintCriteria.m_HintTypes.m_pElements = m_pMemory;
  if ( (nFlags & 0x10) != 0 )
    hintCriteria.m_strGroup.pszValue = pNPC->m_strHintGroup.pszValue;
  p_m_vecAbsOrigin = pMaxDistFrom;
  if ( pMaxDistFrom == nullptr )
  {
    if ( (pNPC->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pNPC, a2: (int)&savedregs);
    p_m_vecAbsOrigin = &pNPC->m_vecAbsOrigin;
  }
  v8 = *(_QWORD *)&p_m_vecAbsOrigin->x;
  z = p_m_vecAbsOrigin->z;
  *(_QWORD *)&vecPosition.x = v8;
  vecPosition.z = z;
  CHintCriteria::AddZone(
    this: &hintCriteria,
    list: &hintCriteria.m_zoneInclude,
    position: &vecPosition,
    radius: flMaxDist);
  if ( (nFlags & 4) != 0 )
    HintRandom = CAI_HintManager::FindHintRandom(pNPC, position: &vecPosition, &hintCriteria);
  else
    HintRandom = CAI_HintManager::FindHint(pNPC, position: &vecPosition, &hintCriteria);
  CHintCriteria::~CHintCriteria(this: &hintCriteria);
  return HintRandom;
}

//------------------------------------------------------------------------------
// Address: 0x100569A0
// Name: public: static class CAI_Hint __near * CAI_HintManager::FindHint(class Vector const __near &,class CHintCriteria const __near &)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__cdecl CAI_HintManager::FindHint(const Vector *position, CHintCriteria *hintCriteria)
{
  return CAI_HintManager::FindHint(pNPC: nullptr, position, hintCriteria);
}

//------------------------------------------------------------------------------
// Address: 0x100569C0
// Name: public: static class CAI_Hint __near * CAI_HintManager::FindHint(class CAI_BaseNPC __near *,class CHintCriteria const __near &)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__cdecl CAI_HintManager::FindHint(CAI_BaseNPC *pNPC, CHintCriteria *hintCriteria)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( pNPC == nullptr )
    return nullptr;
  if ( (pNPC->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pNPC, a2: (int)&savedregs);
  return CAI_HintManager::FindHint(pNPC, position: &pNPC->m_vecAbsOrigin, hintCriteria);
}

//------------------------------------------------------------------------------
// Address: 0x10056A00
// Name: public: static void CAI_HintManager::RemoveHint(class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_HintManager::RemoveHint(CAI_Hint *pHintToRemove)
{
  CAI_Hint *v1; // edi
  int nHintType; // eax
  int v3; // esi
  CAI_Hint **v4; // eax
  CUtlMap<int,CAIHintVector,unsigned short>::Node_t search; // [esp+Ch] [ebp-18h] BYREF

  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CAI_HintManager::gm_AllHints,
    src: (vgui::TreeNode **)&pHintToRemove);
  v1 = pHintToRemove;
  nHintType = pHintToRemove->m_NodeData.nHintType;
  search.elem.m_Memory.m_pMemory = nullptr;
  search.elem.m_Memory.m_nAllocationCount = 0;
  search.elem.m_Memory.m_nGrowSize = 1;
  search.elem.m_Size = 0;
  search.elem.m_pElements = nullptr;
  search.key = nHintType;
  v3 = CUtlRBTree<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short,CUtlMap<int,CAIHintVector,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &CAI_HintManager::gm_TypedHints.m_Tree,
         &search);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem);
  if ( v3 != 0xFFFF )
    CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CAI_HintManager::gm_TypedHints.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem,
      src: (vgui::TreeNode **)&pHintToRemove);
  v4 = CAI_HintManager::gm_pLastFoundHints;
  while ( *v4 != v1 )
  {
    if ( (int)++v4 >= (int)&CAI_HintManager::gm_nFoundHintIndex )
      return;
  }
  _V_memset(dest: CAI_HintManager::gm_pLastFoundHints, fill: 0, count: 32);
  CAI_HintManager::gm_nFoundHintIndex = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10056D60
// Name: private: virtual void CAI_Hint::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Hint::UpdateOnRemove(CAI_Hint *this)
{
  CAI_HintManager::RemoveHint(pHintToRemove: this);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10056FB0
// Name: public: static void CAI_HintManager::AddHintByType(class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_HintManager::AddHintByType(CAI_Hint *pHint)
{
  int nHintType; // esi
  int v2; // edi
  unsigned __int16 v3; // ax
  int v4; // eax
  int m_Size; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_elem; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax
  CUtlMap<int,CAIHintVector,unsigned short>::Node_t search; // [esp+Ch] [ebp-1Ch] BYREF
  int key; // [esp+24h] [ebp-4h] BYREF

  nHintType = pHint->m_NodeData.nHintType;
  search.elem.m_Memory.m_pMemory = nullptr;
  search.elem.m_Memory.m_nAllocationCount = 0;
  search.elem.m_Memory.m_nGrowSize = 1;
  search.elem.m_Size = 0;
  search.elem.m_pElements = nullptr;
  search.key = nHintType;
  v2 = CUtlRBTree<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short,CUtlMap<int,CAIHintVector,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CAIHintVector,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &CAI_HintManager::gm_TypedHints.m_Tree,
         &search);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem);
  v3 = v2;
  if ( v2 == 0xFFFF )
  {
    key = nHintType;
    v3 = CUtlMap<int,CAIHintVector,unsigned short>::Insert(
           this: &CAI_HintManager::gm_TypedHints,
           a2: (const char *)0xFFFF,
           &key);
  }
  v4 = v3;
  m_Size = CAI_HintManager::gm_TypedHints.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.m_Size;
  p_elem = (CUtlMemory<vgui::TreeNode *,int> *)&CAI_HintManager::gm_TypedHints.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  m_nAllocationCount = CAI_HintManager::gm_TypedHints.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_elem, num: m_Size - m_nAllocationCount + 1);
  ++p_elem[1].m_pMemory;
  m_pMemory = p_elem->m_pMemory;
  v9 = (int)p_elem[1].m_pMemory - m_Size - 1;
  p_elem[1].m_nAllocationCount = (int)p_elem->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &p_elem->m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = (vgui::TreeNode *)pHint;
}

//------------------------------------------------------------------------------
// Address: 0x10057080
// Name: public: static void CAI_HintManager::AddHint(class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_HintManager::AddHint(CAI_Hint *pHint)
{
  int m_Size; // eax
  int v2; // esi
  CAI_Hint **m_pMemory; // ecx
  int v4; // eax
  CAI_Hint **v5; // eax

  m_Size = CAI_HintManager::gm_AllHints.m_Size;
  v2 = CAI_HintManager::gm_AllHints.m_Size;
  if ( CAI_HintManager::gm_AllHints.m_Size + 1 > CAI_HintManager::gm_AllHints.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CAI_HintManager::gm_AllHints,
      num: CAI_HintManager::gm_AllHints.m_Size - CAI_HintManager::gm_AllHints.m_Memory.m_nAllocationCount + 1);
    m_Size = CAI_HintManager::gm_AllHints.m_Size;
  }
  m_pMemory = CAI_HintManager::gm_AllHints.m_Memory.m_pMemory;
  CAI_HintManager::gm_AllHints.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  CAI_HintManager::gm_AllHints.m_pElements = CAI_HintManager::gm_AllHints.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &CAI_HintManager::gm_AllHints.m_Memory.m_pMemory[v2 + 1],
      src: &CAI_HintManager::gm_AllHints.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = CAI_HintManager::gm_AllHints.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pHint;
  CAI_HintManager::AddHintByType(pHint);
}

//------------------------------------------------------------------------------
// Address: 0x10057100
// Name: private: virtual void CAI_Hint::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Hint::Activate(CAI_Hint *this)
{
  CBaseEntity::Activate(this);
  CAI_HintManager::AddHint(pHint: this);
}

//------------------------------------------------------------------------------
// Address: 0x103FBCA0
// Name: CAI_Hint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Hint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Hint>(__formal: nullptr);
  CAI_Hint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10056AC0
// Name: struct datamap_t __near * DataMapInit<class CAI_Hint>(class CAI_Hint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Hint>()
{
  if ( (_S2_17 & 1) == 0 )
  {
    _S2_17 |= 1u;
    nameHolder_44.m_pszBase = "CAI_Hint";
    nameHolder_44.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_44.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_44.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_44.m_Names.m_Size = 0;
    nameHolder_44.m_Names.m_pElements = nullptr;
    nameHolder_44.m_nLenBase = 8;
    atexit(func: DataMapInit_CAI_Hint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Hint::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_17 & 2) == 0 )
  {
    _S2_17 |= 2u;
    dataDesc_43[6].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_44,
                                 pszIdentifier: "EnableThink");
    dataDesc_43[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_43[6].td = 0;
    *(_QWORD *)&dataDesc_43[6].override_field = 0;
    *(_QWORD *)&dataDesc_43[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_43[6].flatOffset[1] = 0;
    dataDesc_43[7].fieldSize = 1;
    *(_QWORD *)&dataDesc_43[7].td = 0;
    *(_QWORD *)&dataDesc_43[7].override_field = 0;
    *(_QWORD *)&dataDesc_43[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_43[7].flatOffset[1] = 0;
    dataDesc_43[6].flags = 32;
    dataDesc_43[7].flags = 8;
    *(_QWORD *)&dataDesc_43[8].td = 0;
    *(_QWORD *)&dataDesc_43[8].override_field = 0;
    *(_QWORD *)&dataDesc_43[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_43[8].flatOffset[1] = 0;
    dataDesc_43[8].fieldSize = 1;
    dataDesc_43[8].flags = 8;
    dataDesc_43[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_43[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_43[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_43[9].override_count = 0;
    *(_QWORD *)dataDesc_43[9].flatOffset = 0;
    dataDesc_43[6].fieldOffset = 0;
    dataDesc_43[6].externalName = nullptr;
    dataDesc_43[6].pSaveRestoreOps = nullptr;
    dataDesc_43[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_Hint::EnableThink;
    dataDesc_43[7].fieldType = FIELD_VOID;
    dataDesc_43[7].fieldName = "InputEnableHint";
    dataDesc_43[7].fieldOffset = 0;
    dataDesc_43[7].externalName = "EnableHint";
    dataDesc_43[7].pSaveRestoreOps = nullptr;
    dataDesc_43[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_Hint::InputEnableHint;
    dataDesc_43[8].fieldType = FIELD_VOID;
    dataDesc_43[8].fieldName = "InputDisableHint";
    dataDesc_43[8].fieldOffset = 0;
    dataDesc_43[8].externalName = "DisableHint";
    dataDesc_43[8].pSaveRestoreOps = nullptr;
    dataDesc_43[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_Hint::InputDisableHint;
    dataDesc_43[9].fieldType = FIELD_CUSTOM;
    dataDesc_43[9].fieldName = "m_OnNPCStartedUsing";
    dataDesc_43[9].fieldOffset = 928;
    dataDesc_43[9].flags = 22;
    dataDesc_43[9].externalName = "OnNPCStartedUsing";
    dataDesc_43[9].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_43[9].flatGroup = 0;
    dataDesc_43[10].fieldType = FIELD_CUSTOM;
    dataDesc_43[10].fieldName = "m_OnNPCStoppedUsing";
    dataDesc_43[10].fieldOffset = 952;
    *(_DWORD *)&dataDesc_43[10].fieldSize = 1441793;
    dataDesc_43[10].externalName = "OnNPCStoppedUsing";
    dataDesc_43[10].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_43[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_43[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_43[10].override_count = 0;
    *(_QWORD *)dataDesc_43[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_43[10].flatGroup = 0;
  }
  CAI_Hint::m_DataMap.dataNumFields = 10;
  CAI_Hint::m_DataMap.dataDesc = &dataDesc_43[1];
  return &CAI_Hint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FBCB0
// Name: _dynamic_initializer_for__ai_dump_hints_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_dump_hints_command__()
{
  ConCommand::ConCommand(
    this: &ai_dump_hints_command,
    pName: "ai_dump_hints",
    callback: (void (__cdecl *)(const CCommand *))ai_dump_hints,
    pHelpString: locale,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ai_dump_hints_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103FBCE0
// Name: _dynamic_initializer_for__ai_drop_hint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_drop_hint__()
{
  ConCommand::ConCommand(
    this: &ai_drop_hint,
    pName: "ai_drop_hint",
    callback: CC_ai_drop_hint,
    pHelpString: "Drop an ai_hint at the player's current eye position.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ai_drop_hint__);
}
