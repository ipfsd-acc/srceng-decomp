// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_speechqueue.cpp
// Functions: 13
// ============================================================

#include "game\server\ai_speechqueue.h"

//------------------------------------------------------------------------------
// Address: 0x1008A520
// Name: InferExpresserFromBaseEntity
// Source: json
//------------------------------------------------------------------------------
CAI_Expresser *__usercall InferExpresserFromBaseEntity@<eax>(CBaseEntity *pEnt@<esi>)
{
  void *v1; // eax
  void *v3; // eax
  _DWORD *v4; // eax

  v1 = __RTDynamicCast(
         inptr: pEnt,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CBaseMultiplayerPlayer `RTTI Type Descriptor',
         isReference: 0);
  if ( v1 != nullptr )
    return (*(CAI_Expresser *(__thiscall **)(void *))(*(_DWORD *)v1 + 1916))(a1: v1);
  v3 = __RTDynamicCast(
         inptr: pEnt,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CAI_BaseActor `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr )
    return (*(CAI_Expresser *(__thiscall **)(void *))(*(_DWORD *)v3 + 1900))(a1: v3);
  v4 = __RTDynamicCast(
         inptr: pEnt,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CFlexExpresser `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
    return (CAI_Expresser *)v4[492];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008A870
// Name: public: void CResponseQueue::RemoveSpeechQueuedFor(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseQueue::RemoveSpeechQueuedFor(CResponseQueue *this, const CBaseEntity *pSpeaker)
{
  _DWORD *i; // edx
  unsigned int v3; // eax
  const CBaseEntity *m_pEntity; // ecx

  for ( i = (_DWORD *)this->m_Queue.m_Head; i != nullptr; i = (_DWORD *)i[16] )
  {
    v3 = i[14];
    if ( v3 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3) )
      m_pEntity = nullptr;
    else
      m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
    if ( m_pEntity == pSpeaker )
    {
      i[13] = 3;
      i[14] = -1;
      i[11] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A8E0
// Name: public: void CResponseQueue::RemoveExpresserHost(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseQueue::RemoveExpresserHost(CResponseQueue *this, unsigned int host)
{
  int v3; // eax
  int m_Size; // edx

  if ( host != 0 )
    host = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)host + 8))(a1: host);
  else
    host = -1;
  v3 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: &this->m_ExpresserTargets,
         src: (CHandle<CBaseEntity> *)&host);
  if ( v3 != -1 )
  {
    m_Size = this->m_ExpresserTargets.m_Size;
    if ( m_Size > 0 )
    {
      if ( v3 != m_Size - 1 )
        this->m_ExpresserTargets.m_Memory.m_pMemory[v3].m_Index = this->m_ExpresserTargets.m_Memory.m_pMemory[m_Size - 1].m_Index;
      --this->m_ExpresserTargets.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A9D0
// Name: public: void CResponseQueue::AddExpresserHost(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseQueue::AddExpresserHost(CResponseQueue *this, unsigned int host)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_ExpresserTargets; // esi
  int v4; // edx
  vgui::TreeNode **v5; // edi
  vgui::TreeNode *v6; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v9; // ecx
  int v10; // eax
  unsigned int *v11; // eax
  int count; // [esp+Ch] [ebp-4h]

  if ( host != 0 )
    host = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)host + 8))(a1: host);
  else
    host = -1;
  p_m_ExpresserTargets = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ExpresserTargets;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: &this->m_ExpresserTargets,
         src: (CHandle<CBaseEntity> *)&host) < 0 )
  {
    v4 = 0;
    count = this->m_ExpresserTargets.m_Size;
    if ( count <= 0 )
    {
LABEL_11:
      m_pMemory = p_m_ExpresserTargets[1].m_pMemory;
      m_nAllocationCount = p_m_ExpresserTargets->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_ExpresserTargets, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_ExpresserTargets[1].m_pMemory;
      v9 = p_m_ExpresserTargets->m_pMemory;
      v10 = (char *)p_m_ExpresserTargets[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_ExpresserTargets[1].m_nAllocationCount = (int)p_m_ExpresserTargets->m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[(_DWORD)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: 4 * v10);
      v11 = (unsigned int *)&p_m_ExpresserTargets->m_pMemory[(_DWORD)m_pMemory];
      if ( v11 != nullptr )
        *v11 = host;
    }
    else
    {
      v5 = p_m_ExpresserTargets->m_pMemory;
      while ( 1 )
      {
        v6 = *v5;
        if ( *v5 == (vgui::TreeNode *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != (unsigned int)v6 >> 16
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity == nullptr )
        {
          break;
        }
        ++v4;
        ++v5;
        if ( v4 >= count )
          goto LABEL_11;
      }
      p_m_ExpresserTargets->m_pMemory[v4] = (vgui::TreeNode *)host;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AAC0
// Name: private: bool CResponseQueue::DispatchOneResponse_ThenANY(struct CResponseQueue::CDeferredResponse __near &,class ResponseRules::CriteriaSet restrict __near *,class CBaseEntity restrict __near * const,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResponseQueue::DispatchOneResponse_ThenANY(
        CResponseQueue *this,
        CResponseQueue::CDeferredResponse *response,
        ResponseRules::CriteriaSet *pDeferredCriteria,
        CBaseEntity *const pIssuer,
        float followupMaxDistSq)
{
  float m_fValue; // xmm0_4
  ResponseRules::CRR_Response *v6; // esi
  int i; // edi
  int v8; // eax
  int v9; // ebx
  IUniformRandomStream *v10; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *v12; // esi
  CAI_Expresser *v13; // edi
  const char *v14; // eax
  float v15; // xmm0_4
  double v16; // xmm0_8
  double v17; // xmm1_8
  int v18; // eax
  int v19; // ecx
  char v20; // bl
  ResponseRules::CRR_Response *v21; // esi
  int k; // edi
  ResponseRules::CRR_Response *v24; // esi
  int m; // edi
  ResponseRules::CRR_Response *v26; // esi
  int j; // edi
  ResponseRules::CRR_Response v28[32]; // [esp+1Ch] [ebp-1674h] BYREF
  _DWORD v29[32]; // [esp+151Ch] [ebp-174h] BYREF
  ResponseRules::CRR_Response outResponse; // [esp+159Ch] [ebp-F4h] BYREF
  ResponseRules::CriteriaSet outputSet; // [esp+1644h] [ebp-4Ch] BYREF
  Vector m_vecAbsOrigin; // [esp+1668h] [ebp-28h]
  int m_Size; // [esp+1674h] [ebp-1Ch]
  float v34; // [esp+1678h] [ebp-18h]
  int v35; // [esp+167Ch] [ebp-14h]
  CResponseQueue *v36; // [esp+1680h] [ebp-10h]
  float m_fMatchScore; // [esp+1684h] [ebp-Ch]
  float v38; // [esp+1688h] [ebp-8h]
  float v39; // [esp+168Ch] [ebp-4h]
  int savedregs; // [esp+1690h] [ebp+0h] BYREF

  v39 = 0.0;
  m_fValue = rr_thenany_score_slop.m_pParent->m_Value.m_fValue;
  v36 = this;
  v34 = m_fValue;
  if ( pIssuer != nullptr )
  {
    if ( (pIssuer->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pIssuer, a2: (int)&savedregs);
    m_vecAbsOrigin = pIssuer->m_vecAbsOrigin;
  }
  v6 = v28;
  for ( i = 31; i >= 0; --i )
    ResponseRules::CRR_Response::CRR_Response(this: v6++);
  v8 = 0;
  v9 = 0;
  m_Size = v36->m_ExpresserTargets.m_Size;
  v35 = 0;
  if ( m_Size <= 0 )
    goto LABEL_45;
  do
  {
    v10 = (IUniformRandomStream *)v36;
    m_Index = v36->m_ExpresserTargets.m_Memory.m_pMemory[v8].m_Index;
    if ( m_Index == -1
      || (v10 = (IUniformRandomStream *)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
    {
      v12 = nullptr;
    }
    else
    {
      v12 = (CBaseEntity *)v10->__vftable;
    }
    if ( v12 != pIssuer && v12->IsAlive(this: v12) )
    {
      v38 = 0.0;
      if ( pIssuer == nullptr )
        goto LABEL_18;
      if ( (v12->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v12, a2: (int)&savedregs);
      v38 = (float)((float)((float)(v12->m_vecAbsOrigin.y - m_vecAbsOrigin.y)
                          * (float)(v12->m_vecAbsOrigin.y - m_vecAbsOrigin.y))
                  + (float)((float)(v12->m_vecAbsOrigin.x - m_vecAbsOrigin.x)
                          * (float)(v12->m_vecAbsOrigin.x - m_vecAbsOrigin.x)))
          + (float)((float)(v12->m_vecAbsOrigin.z - m_vecAbsOrigin.z) * (float)(v12->m_vecAbsOrigin.z - m_vecAbsOrigin.z));
      if ( v38 <= followupMaxDistSq )
      {
LABEL_18:
        v13 = InferExpresserFromBaseEntity(pEnt: v12);
        if ( v13 != nullptr )
        {
          ResponseRules::CriteriaSet::CriteriaSet(this: &outputSet);
          CAI_Expresser::GatherCriteria(this: v13, &outputSet, concept: &response->m_concept, modifiers: nullptr);
          ResponseRules::CriteriaSet::Merge(this: &outputSet, otherCriteria: pDeferredCriteria);
          v12->ModifyOrAppendDerivedCriteria(this: v12, a2: &outputSet);
          if ( pIssuer != nullptr )
          {
            v14 = UTIL_VarArgs(format: "%f", fsqrt(v38));
            ResponseRules::CriteriaSet::AppendCriteria(
              this: &outputSet,
              pCriteriaName: "dist_from_issuer",
              value: v14,
              weight: 1.0);
          }
          ResponseRules::CRR_Response::CRR_Response(this: &outResponse);
          if ( CAI_Expresser::FindResponse(this: v13, &outResponse, concept: &response->m_concept, criteria: &outputSet) == 0 )
            goto LABEL_32;
          m_fMatchScore = outResponse.m_fMatchScore;
          if ( outResponse.m_fMatchScore <= 0.0 || outResponse.m_szResponseName[0] == 0 )
            goto LABEL_32;
          if ( outResponse.m_fMatchScore <= (float)(v34 + v39) )
          {
            if ( outResponse.m_fMatchScore < (float)(v39 - v34) || v9 >= 32 )
              goto LABEL_32;
            ResponseRules::CRR_Response::operator=(this: &v28[v9], from: &outResponse);
            v16 = m_fMatchScore;
            v17 = v39;
            v29[v9] = v13;
            if ( v16 < v17 )
              v16 = v17;
            v15 = v16;
            ++v9;
          }
          else
          {
            ResponseRules::CRR_Response::operator=(this: v28, from: &outResponse);
            v15 = m_fMatchScore;
            v29[0] = v13;
            v9 = 1;
          }
          v39 = v15;
LABEL_32:
          ResponseRules::CRR_Response::~CRR_Response(this: &outResponse);
          CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &outputSet.m_Lookup);
        }
      }
    }
    v8 = v35 + 1;
    v35 = v8;
  }
  while ( v8 < m_Size );
  if ( v9 <= 0 )
  {
LABEL_45:
    v26 = (ResponseRules::CRR_Response *)v29;
    for ( j = 31; j >= 0; --j )
      ResponseRules::CRR_Response::~CRR_Response(this: --v26);
    return 0;
  }
  if ( v9 <= 1 )
    v18 = 0;
  else
    v18 = _RandomInt(this: v10, a2: 0, a3: v9 - 1);
  v19 = v29[v18];
  if ( v19 != 0 )
  {
    v20 = (*(int (__thiscall **)(int, CResponseQueue::CDeferredResponse *, ResponseRules::CRR_Response *, ResponseRules::CriteriaSet *, _DWORD))(*(_DWORD *)v19 + 4))(
            a1: v19,
            a2: response,
            a3: &v28[v18],
            a4: pDeferredCriteria,
            a5: 0);
    v21 = (ResponseRules::CRR_Response *)v29;
    for ( k = 31; k >= 0; --k )
      ResponseRules::CRR_Response::~CRR_Response(this: --v21);
    return v20;
  }
  else
  {
    v24 = (ResponseRules::CRR_Response *)v29;
    for ( m = 31; m >= 0; --m )
      ResponseRules::CRR_Response::~CRR_Response(this: --v24);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AE70
// Name: protected: bool CResponseQueue::DispatchOneResponse(struct CResponseQueue::CDeferredResponse __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResponseQueue::DispatchOneResponse(CResponseQueue *this, CResponseQueue::CDeferredResponse *response)
{
  unsigned int m_Index; // eax
  CResponseQueue *v4; // esi
  CBaseEntity *v5; // edi
  CFlexExpresser *v6; // eax
  float m_flThenAnyMaxDist; // xmm0_4
  float v8; // xmm1_4
  DeferredResponseTarget_t m_iTargetType; // eax
  __int32 v10; // eax
  unsigned int v12; // eax
  CBaseEntity *v13; // ecx
  CAI_Expresser *v14; // esi
  int v15; // eax
  unsigned int v16; // eax
  CBaseEntity *v17; // esi
  CAI_Expresser *v18; // edi
  const char *v19; // eax
  bool v20; // zf
  ResponseRules::CRR_Response prospectiveResponse; // [esp+18h] [ebp-114h] BYREF
  ResponseRules::CriteriaSet characterCriteria; // [esp+C0h] [ebp-6Ch] BYREF
  ResponseRules::CriteriaSet outputSet; // [esp+E4h] [ebp-48h] BYREF
  Vector issuerLocation; // [esp+108h] [ebp-24h]
  int numExprs; // [esp+114h] [ebp-18h]
  CResponseQueue *v26; // [esp+118h] [ebp-14h]
  int i; // [esp+11Ch] [ebp-10h]
  float distIssuerToTargetSq; // [esp+120h] [ebp-Ch]
  float followupMaxDistSq; // [esp+124h] [ebp-8h]
  IHandleEntity *m_pEntity; // [esp+128h] [ebp-4h]
  int savedregs; // [esp+12Ch] [ebp+0h] BYREF
  char bSaidAnything_3; // [esp+137h] [ebp+Bh]

  m_Index = response->m_hIssuer.m_Index;
  v4 = this;
  v26 = this;
  if ( m_Index == -1 )
  {
    v5 = nullptr;
    m_pEntity = nullptr;
  }
  else if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v5 = (CBaseEntity *)m_pEntity;
  }
  else
  {
    m_pEntity = nullptr;
    v5 = nullptr;
  }
  v6 = CFlexExpresser::AsFlexExpresser(pEntity: v5);
  if ( v6 != nullptr )
  {
    m_flThenAnyMaxDist = v6->m_flThenAnyMaxDist;
    if ( m_flThenAnyMaxDist <= 0.0 )
    {
      v8 = 3.4028235e38;
      goto LABEL_11;
    }
  }
  else
  {
    m_flThenAnyMaxDist = rr_followup_maxdist.m_pParent->m_Value.m_fValue;
  }
  v8 = m_flThenAnyMaxDist * m_flThenAnyMaxDist;
LABEL_11:
  m_iTargetType = response->m_Target.m_iTargetType;
  followupMaxDistSq = v8;
  if ( m_iTargetType == kDRT_ANY )
    return CResponseQueue::DispatchOneResponse_ThenANY(
             this: v4,
             response,
             pDeferredCriteria: &response->m_contexts,
             pIssuer: v5,
             followupMaxDistSq: v8);
  v10 = m_iTargetType - 1;
  if ( v10 != 0 )
  {
    if ( v10 == 1
      && (v12 = response->m_Target.m_hHandle.m_Index) != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == HIWORD(v12)
      && (v13 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity) != nullptr
      && (v14 = InferExpresserFromBaseEntity(pEnt: v13)) != nullptr )
    {
      ResponseRules::CriteriaSet::CriteriaSet(this: &characterCriteria);
      CAI_Expresser::GatherCriteria(
        this: v14,
        outputSet: &characterCriteria,
        concept: &response->m_concept,
        modifiers: nullptr);
      ResponseRules::CriteriaSet::Merge(this: &characterCriteria, otherCriteria: &response->m_contexts);
      CAI_Expresser::Speak(
        this: v14,
        concept: &response->m_concept,
        criteria: &characterCriteria,
        pszOutResponseChosen: nullptr,
        bufsize: 0,
        filter: nullptr);
      CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &characterCriteria.m_Lookup);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    bSaidAnything_3 = 0;
    if ( v5 != nullptr )
    {
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
      issuerLocation = v5->m_vecAbsOrigin;
    }
    v15 = 0;
    numExprs = v4->m_ExpresserTargets.m_Size;
    i = 0;
    if ( numExprs > 0 )
    {
      while ( 1 )
      {
        v16 = v4->m_ExpresserTargets.m_Memory.m_pMemory[v15].m_Index;
        if ( v16 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16) )
          v17 = nullptr;
        else
          v17 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity;
        distIssuerToTargetSq = 0.0;
        if ( v5 == nullptr )
          goto LABEL_35;
        if ( (v17->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v17, a2: (int)&savedregs);
        distIssuerToTargetSq = (float)((float)((float)(v17->m_vecAbsOrigin.x - issuerLocation.x)
                                             * (float)(v17->m_vecAbsOrigin.x - issuerLocation.x))
                                     + (float)((float)(v17->m_vecAbsOrigin.y - issuerLocation.y)
                                             * (float)(v17->m_vecAbsOrigin.y - issuerLocation.y)))
                             + (float)((float)(v17->m_vecAbsOrigin.z - issuerLocation.z)
                                     * (float)(v17->m_vecAbsOrigin.z - issuerLocation.z));
        if ( distIssuerToTargetSq <= followupMaxDistSq )
        {
LABEL_35:
          v18 = InferExpresserFromBaseEntity(pEnt: v17);
          if ( v18 != nullptr && v17 != m_pEntity )
          {
            ResponseRules::CriteriaSet::CriteriaSet(this: &outputSet);
            CAI_Expresser::GatherCriteria(this: v18, &outputSet, concept: &response->m_concept, modifiers: nullptr);
            ResponseRules::CriteriaSet::Merge(this: &outputSet, otherCriteria: &response->m_contexts);
            if ( m_pEntity != nullptr )
            {
              v19 = UTIL_VarArgs(format: "%f", fsqrt(distIssuerToTargetSq));
              ResponseRules::CriteriaSet::AppendCriteria(
                this: &outputSet,
                pCriteriaName: "dist_from_issuer",
                value: v19,
                weight: 1.0);
            }
            ResponseRules::CRR_Response::CRR_Response(this: &prospectiveResponse);
            if ( CAI_Expresser::FindResponse(
                   this: v18,
                   outResponse: &prospectiveResponse,
                   concept: &response->m_concept,
                   criteria: &outputSet) != 0 )
            {
              if ( v18->SpeakDispatchResponse(
                     this: v18,
                     a2: &response->m_concept,
                     a3: &prospectiveResponse,
                     a4: &response->m_contexts,
                     a5: nullptr)
                || (v20 = bSaidAnything_3 == 0, bSaidAnything_3 = 0, !v20) )
              {
                bSaidAnything_3 = 1;
              }
            }
            ResponseRules::CRR_Response::~CRR_Response(this: &prospectiveResponse);
            CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &outputSet.m_Lookup);
          }
          v5 = (CBaseEntity *)m_pEntity;
        }
        v15 = i + 1;
        i = v15;
        if ( v15 >= numExprs )
          break;
        v4 = v26;
      }
    }
    return bSaidAnything_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B280
// Name: public: void CResponseQueue::Add(class CAI_Concept const __near &,class ResponseRules::CriteriaSet const restrict __near *,float,struct CResponseQueue::CFollowupTargetSpec_t const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseQueue::Add(
        CResponseQueue *this,
        const CAI_Concept *concept,
        const ResponseRules::CriteriaSet *contexts,
        float time,
        const CResponseQueue::CFollowupTargetSpec_t *targetspec,
        CBaseEntity *pIssuer)
{
  int v7; // eax
  int v8; // esi

  v7 = CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::AllocInternal(
         this: &this->m_Queue,
         multilist: false);
  v8 = v7;
  if ( v7 != 0 )
  {
    CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::LinkBefore(
      this: &this->m_Queue,
      before: 0,
      elem: v7);
    *(_WORD *)v8 = -1;
    *(_DWORD *)(v8 + 4) = -1;
    ResponseRules::CriteriaSet::CriteriaSet(this: (ResponseRules::CriteriaSet *)(v8 + 8));
    *(_DWORD *)(v8 + 48) = -1;
    *(_DWORD *)(v8 + 52) = 3;
    *(_DWORD *)(v8 + 56) = -1;
  }
  *(CAI_Concept *)v8 = *concept;
  *(float *)(v8 + 44) = time;
  *(CResponseQueue::CFollowupTargetSpec_t *)(v8 + 52) = *targetspec;
  if ( pIssuer != nullptr )
    *(_DWORD *)(v8 + 48) = pIssuer->GetRefEHandle(this: pIssuer)->m_Index;
  else
    *(_DWORD *)(v8 + 48) = -1;
  ResponseRules::CriteriaSet::Reset(this: (ResponseRules::CriteriaSet *)(v8 + 8));
  if ( contexts != nullptr )
    ResponseRules::CriteriaSet::Merge(this: (ResponseRules::CriteriaSet *)(v8 + 8), otherCriteria: contexts);
}

//------------------------------------------------------------------------------
// Address: 0x1008B320
// Name: public: void CResponseQueue::PerFrameDispatch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseQueue::PerFrameDispatch(CResponseQueue *this)
{
  int m_Head; // esi
  unsigned int v3; // eax
  int *v4; // edi
  int v5; // eax
  int oldLength; // [esp+Ch] [ebp-8h]
  int idx; // [esp+10h] [ebp-4h]

failsafe:
  m_Head = this->m_Queue.m_Head;
  while ( m_Head != 0 )
  {
    v3 = *(_DWORD *)(m_Head + 52);
    if ( v3 > 2 || v3 == 2 && *(_DWORD *)(m_Head + 56) == -1 )
      goto LABEL_8;
    if ( gpGlobals->curtime < *(float *)(m_Head + 44) )
    {
      m_Head = *(_DWORD *)(m_Head + 64);
    }
    else
    {
      oldLength = this->m_Queue.m_ElementCount;
      CResponseQueue::DispatchOneResponse(this, response: (CResponseQueue::CDeferredResponse *)m_Head);
      if ( this->m_Queue.m_ElementCount < oldLength )
        goto failsafe;
LABEL_8:
      v4 = (int *)(m_Head + 64);
      idx = *(_DWORD *)(m_Head + 64);
      if ( !CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::IsIdxAfter(
              this: &this->m_Queue.m_Memory,
              i: m_Head,
              it: &this->m_Queue.m_LastAlloc) )
      {
        v5 = *(_DWORD *)(m_Head + 60);
        if ( v5 != m_Head )
        {
          if ( v5 != 0 )
            *(_DWORD *)(v5 + 64) = *v4;
          else
            this->m_Queue.m_Head = *v4;
          if ( *v4 != 0 )
            *(_DWORD *)(*v4 + 60) = *(_DWORD *)(m_Head + 60);
          else
            this->m_Queue.m_Tail = *(_DWORD *)(m_Head + 60);
          *v4 = m_Head;
          *(_DWORD *)(m_Head + 60) = m_Head;
          --this->m_Queue.m_ElementCount;
        }
      }
      CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::RemoveAll(this: (CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl*)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short> > *)(m_Head + 8));
      *(_WORD *)(m_Head + 28) = -1;
      if ( *(int *)(m_Head + 20) >= 0 )
      {
        if ( *(_DWORD *)(m_Head + 12) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(m_Head + 12));
          *(_DWORD *)(m_Head + 12) = 0;
        }
        *(_DWORD *)(m_Head + 16) = 0;
      }
      *(_WORD *)(m_Head + 30) = -1;
      if ( *(int *)(m_Head + 20) >= 0 )
      {
        if ( *(_DWORD *)(m_Head + 12) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(m_Head + 12));
          *(_DWORD *)(m_Head + 12) = 0;
        }
        *(_DWORD *)(m_Head + 16) = 0;
      }
      *(_DWORD *)(m_Head + 64) = this->m_Queue.m_FirstFree;
      this->m_Queue.m_FirstFree = m_Head;
      m_Head = idx;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B470
// Name: public: virtual void CResponseQueueManager::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseQueueManager::FrameUpdatePostEntityThink(CResponseQueueManager *this)
{
  CResponseQueue::PerFrameDispatch(this: this->m_pQueue);
}

//------------------------------------------------------------------------------
// Address: 0x1008B480
// Name: public: CResponseQueue::CResponseQueue(int)
// Source: json
//------------------------------------------------------------------------------
CResponseQueue *__thiscall CResponseQueue::CResponseQueue(CResponseQueue *this, int queueSize)
{
  CHandle<CBaseEntity> *v3; // eax

  this->m_Queue.m_Memory.m_nGrowSize = queueSize;
  this->m_Queue.m_Memory.m_pBlocks = nullptr;
  this->m_Queue.m_Memory.m_nAllocationCount = 0;
  this->m_Queue.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_Queue.m_LastAlloc.m_nIndex = -1;
  this->m_Queue.m_Head = 0;
  this->m_Queue.m_Tail = 0;
  this->m_Queue.m_FirstFree = 0;
  this->m_Queue.m_ElementCount = 0;
  this->m_Queue.m_NumAlloced = 0;
  this->m_Queue.m_pElements = nullptr;
  this->m_ExpresserTargets.m_Memory.m_nAllocationCount = 8;
  this->m_ExpresserTargets.m_Memory.m_nGrowSize = 8;
  this->m_ExpresserTargets.m_Memory.m_pMemory = nullptr;
  v3 = (CHandle<CBaseEntity> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  this->m_ExpresserTargets.m_Size = 0;
  this->m_ExpresserTargets.m_Memory.m_pMemory = v3;
  this->m_ExpresserTargets.m_pElements = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008B4E0
// Name: public: virtual void CResponseQueueManager::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseQueueManager::LevelInitPreEntity(CResponseQueueManager *this)
{
  CResponseQueue *v2; // eax

  if ( this->m_pQueue == nullptr )
  {
    v2 = (CResponseQueue *)operator new(nSize: 0x40u);
    if ( v2 != nullptr )
      this->m_pQueue = CResponseQueue::CResponseQueue(this: v2, queueSize: 64);
    else
      this->m_pQueue = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B510
// Name: public: virtual void CResponseQueueManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseQueueManager::Shutdown(CResponseQueueManager *this)
{
  CResponseQueue *m_pQueue; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *v4; // [esp-8h] [ebp-10h]

  m_pQueue = this->m_pQueue;
  if ( m_pQueue != nullptr )
  {
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pQueue->m_ExpresserTargets);
    CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::RemoveAll(this: &m_pQueue->m_Queue);
    m_pBlocks = m_pQueue->m_Queue.m_Memory.m_pBlocks;
    if ( m_pQueue->m_Queue.m_Memory.m_pBlocks != nullptr )
    {
      do
      {
        v4 = m_pBlocks;
        m_pBlocks = m_pBlocks->m_pNext;
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      }
      while ( m_pBlocks != nullptr );
      m_pQueue->m_Queue.m_Memory.m_pBlocks = nullptr;
      m_pQueue->m_Queue.m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: m_pQueue);
    this->m_pQueue = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B560
// Name: public: virtual CResponseQueueManager::~CResponseQueueManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResponseQueueManager::~CResponseQueueManager(CResponseQueueManager *this)
{
  CResponseQueue *m_pQueue; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *v4; // [esp-8h] [ebp-10h]

  m_pQueue = this->m_pQueue;
  this->__vftable = (CResponseQueueManager_vtbl *)&CResponseQueueManager::`vftable';
  if ( m_pQueue != nullptr )
  {
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pQueue->m_ExpresserTargets);
    CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::RemoveAll(this: &m_pQueue->m_Queue);
    m_pBlocks = m_pQueue->m_Queue.m_Memory.m_pBlocks;
    if ( m_pQueue->m_Queue.m_Memory.m_pBlocks != nullptr )
    {
      do
      {
        v4 = m_pBlocks;
        m_pBlocks = m_pBlocks->m_pNext;
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      }
      while ( m_pBlocks != nullptr );
      m_pQueue->m_Queue.m_Memory.m_pBlocks = nullptr;
      m_pQueue->m_Queue.m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: m_pQueue);
    this->m_pQueue = nullptr;
  }
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}
