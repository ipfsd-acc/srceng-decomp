// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_node.cpp
// Functions: 8
// ============================================================

#include "game\server\ai_node.h"

//------------------------------------------------------------------------------
// Address: 0x10073770
// Name: public: void CAI_Node::ShuffleLinks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Node::ShuffleLinks(CAI_Node *this)
{
  if ( ++this->m_iFirstShuffledLink >= this->m_Links.m_Size )
    this->m_iFirstShuffledLink = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10073790
// Name: public: class Vector CAI_Node::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_Node::GetPosition(CAI_Node *this, Vector *result, int hull)
{
  NodeType_e m_eNodeType; // eax
  double v6; // st7
  __m128 m_flYaw_low; // xmm0
  double v8; // xmm0_8
  int m_eNodeInfo; // eax
  double v10; // xmm0_8
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm7_4
  float v19; // xmm0_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm3_4
  Vector *v33; // eax
  float v34; // xmm0_4
  bool v35; // zf
  float v36; // xmm0_4
  float v37; // xmm0_4
  float z; // edx
  float offsetDir; // [esp+4h] [ebp-10h]
  int v40; // [esp+10h] [ebp-4h]
  float shift; // [esp+20h] [ebp+Ch]
  float shifta; // [esp+20h] [ebp+Ch]

  m_eNodeType = this->m_eNodeType;
  if ( m_eNodeType == NODE_CLIMB )
  {
    v6 = NAI_Hull::Length(id: hull);
    m_flYaw_low = (__m128)LODWORD(this->m_flYaw);
    m_flYaw_low.m128_f32[0] = m_flYaw_low.m128_f32[0] * 0.017453292;
    v40 = m_flYaw_low.m128_i32[0];
    shift = v6 * 0.5 + 8.0;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(m_flYaw_low));
    *(float *)&v8 = v8;
    offsetDir = *(float *)&v8;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)v40));
    m_eNodeInfo = this->m_eNodeInfo;
    v11 = v10;
    if ( (m_eNodeInfo & 4) != 0 )
    {
      v12 = v11 * shift;
      v13 = this->m_vOrigin.x + (float)(offsetDir * shift);
      v14 = this->m_vOrigin.y + v12;
      v15 = this->m_vOrigin.z + (float)(shift * 0.0);
    }
    else
    {
      if ( (m_eNodeInfo & 8) != 0 )
      {
        v16 = (float)(offsetDir * 0.0) - (float)(v11 * 0.0);
        v17 = shift;
        v18 = v11;
        shifta = offsetDir * shift;
        v19 = v11 * v17;
        v20 = v17 * 0.0;
        v21 = v17 * 2.0;
        v22 = (float)(v17 * 2.0) * v16;
        v23 = this->m_vOrigin.x - (float)(v21 * v18);
        v24 = this->m_vOrigin.y - (float)(v21 * COERCE_FLOAT(LODWORD(offsetDir) ^ _mask__NegFloat_));
        v25 = this->m_vOrigin.z - v22;
      }
      else
      {
        if ( (m_eNodeInfo & 0x10) == 0 )
        {
          v32 = v11 * shift;
          v13 = this->m_vOrigin.x - (float)(offsetDir * shift);
          v14 = this->m_vOrigin.y - v32;
          v15 = this->m_vOrigin.z - (float)(shift * 0.0);
          goto LABEL_10;
        }
        v26 = (float)(offsetDir * 0.0) - (float)(v11 * 0.0);
        v27 = shift;
        v28 = v11;
        shifta = offsetDir * shift;
        v19 = v11 * v27;
        v20 = v27 * 0.0;
        v29 = v27 * 2.0;
        v30 = (float)(v27 * 2.0) * v26;
        v23 = this->m_vOrigin.x + (float)(v29 * v28);
        v24 = this->m_vOrigin.y + (float)(v29 * COERCE_FLOAT(LODWORD(offsetDir) ^ _mask__NegFloat_));
        v25 = this->m_vOrigin.z + v30;
      }
      v31 = v24 - v19;
      v13 = v23 - shifta;
      v14 = v31;
      v15 = v25 - v20;
    }
LABEL_10:
    result->x = v13;
    v34 = this->m_flVOffset[hull] + v15;
    result->y = v14;
    result->z = v34;
    return result;
  }
  v35 = m_eNodeType == NODE_GROUND;
  v33 = result;
  if ( v35 )
  {
    v36 = this->m_flVOffset[hull];
    result->x = this->m_vOrigin.x;
    v37 = v36 + this->m_vOrigin.z;
    result->y = this->m_vOrigin.y;
    result->z = v37;
  }
  else
  {
    z = this->m_vOrigin.z;
    *(_QWORD *)&result->x = *(_QWORD *)&this->m_vOrigin.x;
    result->z = z;
  }
  return v33;
}

//------------------------------------------------------------------------------
// Address: 0x100739F0
// Name: public: class CAI_Link __near * CAI_Node::HasLink(int)
// Source: json
//------------------------------------------------------------------------------
CAI_Link *__thiscall CAI_Node::HasLink(CAI_Node *this, int nNodeID)
{
  int v2; // esi
  CAI_Link **i; // edx
  __int16 v4; // ax
  int m_Size; // [esp+10h] [ebp-4h]

  v2 = 0;
  m_Size = this->m_Links.m_Size;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = this->m_Links.m_Memory.m_pMemory; ; ++i )
  {
    v4 = this->m_iID == (*i)->m_iSrcID ? (*i)->m_iDestID : (*i)->m_iSrcID;
    if ( v4 == nNodeID )
      break;
    if ( ++v2 >= m_Size )
      return nullptr;
  }
  return this->m_Links.m_Memory.m_pMemory[v2];
}

//------------------------------------------------------------------------------
// Address: 0x10073A50
// Name: public: class CAI_Link __near * CAI_Node::GetShuffeledLink(int)
// Source: json
//------------------------------------------------------------------------------
CAI_Link *__thiscall CAI_Node::GetShuffeledLink(CAI_Node *this, int nNum)
{
  int v2; // eax
  int m_Size; // edx

  v2 = nNum + this->m_iFirstShuffledLink;
  m_Size = this->m_Links.m_Size;
  if ( v2 < m_Size )
    return this->m_Links.m_Memory.m_pMemory[v2];
  else
    return this->m_Links.m_Memory.m_pMemory[v2 - m_Size];
}

//------------------------------------------------------------------------------
// Address: 0x10073A80
// Name: float GetFloorZ(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetFloorZ(const Vector *origin, float fMaxDrop)
{
  CGameTrace trEnt; // [esp+4h] [ebp-B4h] BYREF
  CGameTrace tr; // [esp+58h] [ebp-60h] BYREF
  Vector vecAbsEnd; // [esp+ACh] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+B8h] [ebp+0h] BYREF

  vecAbsEnd.x = origin->x;
  vecAbsEnd.y = origin->y;
  vecAbsEnd.z = origin->z - fMaxDrop;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)origin,
    vecAbsStart: origin,
    &vecAbsEnd,
    mask: 0x2400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  vecAbsEnd.x = origin->x;
  vecAbsEnd.y = origin->y;
  vecAbsEnd.z = origin->z - fMaxDrop;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)origin,
    vecAbsStart: origin,
    &vecAbsEnd,
    mask: 0x202400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &trEnt);
  if ( tr.fraction > trEnt.fraction && trEnt.m_pEnt != nullptr && (trEnt.m_pEnt->m_fFlags.m_Value & 0x2000000) != 0 )
    tr.endpos.z = trEnt.endpos.z;
  return tr.endpos.z;
}

//------------------------------------------------------------------------------
// Address: 0x10073B40
// Name: float GetFloorZ(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetFloorZ(const Vector *origin)
{
  return GetFloorZ(origin, fMaxDrop: 384.0);
}

//------------------------------------------------------------------------------
// Address: 0x10073B60
// Name: public: void CAI_Node::AddLink(class CAI_Link __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Node::AddLink(CAI_Node *this, CAI_Link *newLink)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Links; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  if ( this->m_Links.m_Size == 30 )
  {
    DevMsg(a1: "Node %d has too many links\n", this->m_iID);
  }
  else
  {
    m_nAllocationCount = this->m_Links.m_Memory.m_nAllocationCount;
    p_m_Links = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Links;
    m_Size = this->m_Links.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Links, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Links[1].m_pMemory;
    m_pMemory = p_m_Links->m_pMemory;
    v6 = (int)p_m_Links[1].m_pMemory - m_Size - 1;
    p_m_Links[1].m_nAllocationCount = (int)p_m_Links->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &p_m_Links->m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (vgui::TreeNode *)newLink;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073BE0
// Name: public: CAI_Node::CAI_Node(int,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CAI_Node *__thiscall CAI_Node::CAI_Node(CAI_Node *this, int id, const Vector *origin, float yaw)
{
  CAI_Link **v5; // eax

  this->m_Links.m_Memory.m_pMemory = nullptr;
  this->m_Links.m_Memory.m_nAllocationCount = 4;
  this->m_Links.m_Memory.m_nGrowSize = 0;
  v5 = (CAI_Link **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16);
  this->m_Links.m_Memory.m_pMemory = v5;
  this->m_Links.m_pElements = v5;
  this->m_Links.m_Size = 0;
  this->m_vOrigin = *origin;
  this->m_iID = id;
  *(_QWORD *)this->m_flVOffset = 0;
  *(_QWORD *)&this->m_flVOffset[2] = 0;
  *(_QWORD *)&this->m_flVOffset[4] = 0;
  *(_QWORD *)&this->m_flVOffset[6] = 0;
  *(_QWORD *)&this->m_flVOffset[8] = 0;
  *(_QWORD *)&this->m_flVOffset[10] = 0;
  this->m_eNodeInfo = 0;
  this->m_iFirstShuffledLink = 0;
  this->m_pHint = nullptr;
  this->m_flYaw = yaw;
  this->m_zone = 0;
  this->m_eNodeType = NODE_GROUND;
  this->m_flNextUseTime = 0.0;
  return this;
}
