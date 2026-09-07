// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/hierarchy.cpp
// Functions: 8
// ============================================================

#include "game\server\hierarchy.h"

//------------------------------------------------------------------------------
// Address: 0x1015C1C0
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBaseEntity::NetworkVar_m_hMoveParent>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hMoveParent>::Set(
        CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hMoveParent> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hMoveParent> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 54;
    if ( *((_BYTE *)this - 132) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xD8u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x1015C250
// Name: void UnlinkChild(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnlinkChild(CBaseEntity *pParent, CBaseEntity *pChild)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // esi
  CHandle<CBaseEntity> *p_m_hMoveChild; // edi
  IHandleEntity_vtbl *v5; // eax
  IHandleEntity *v6; // ecx
  IHandleEntity_vtbl *v7; // eax
  CBaseEdict *v8; // ecx

  m_Index = pParent->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  p_m_hMoveChild = &pParent->m_hMoveChild;
  if ( m_pEntity != nullptr )
  {
    while ( 1 )
    {
      v5 = m_pEntity[56].__vftable;
      if ( v5 == (IHandleEntity_vtbl *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != (unsigned int)v5 >> 16 )
      {
        v6 = nullptr;
      }
      else
      {
        v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      }
      if ( m_pEntity == pChild )
        break;
      p_m_hMoveChild = (CHandle<CBaseEntity> *)&m_pEntity[56];
      m_pEntity = v6;
      if ( v6 == nullptr )
        return;
    }
    if ( v6 != nullptr )
      p_m_hMoveChild->m_Index = v6->GetRefEHandle(this: v6)->m_Index;
    else
      p_m_hMoveChild->m_Index = -1;
    v7 = m_pEntity[54].__vftable;
    if ( v7 != (IHandleEntity_vtbl *)-1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == (unsigned int)v7 >> 16
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr )
    {
      if ( LOBYTE(m_pEntity[21].__vftable) != 0 )
      {
        LOBYTE(m_pEntity[22].__vftable) |= 1u;
      }
      else
      {
        v8 = (CBaseEdict *)m_pEntity[6].__vftable;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: v8, offset: 0xD8u);
      }
      m_pEntity[54].__vftable = (IHandleEntity_vtbl *)-1;
    }
    m_pEntity[56].__vftable = (IHandleEntity_vtbl *)-1;
    m_pEntity[16].__vftable = (IHandleEntity_vtbl *)-1;
    CBaseEntity::DispatchUpdateTransmitState(this: (CBaseEntity *)m_pEntity);
    ((void (__thiscall *)(IHandleEntity *, int, _DWORD))m_pEntity->__vftable[31].SetRefEHandle)(
      a1: m_pEntity,
      a2: 2,
      a3: 0);
    CBaseEntity::RecalcHasPlayerChildBit(this: pParent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C370
// Name: void UnlinkFromParent(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnlinkFromParent(CBaseEntity *pRemove)
{
  unsigned int m_Index; // eax
  float z; // ecx
  unsigned int v3; // edx
  float v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  float v7; // edx
  CBaseEntity *m_pEntity; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx
  unsigned __int8 m_Value; // al
  Vector vecAbsVelocity; // [esp+4h] [ebp-24h] BYREF
  Vector vecAbsOrigin; // [esp+10h] [ebp-18h] BYREF
  QAngle angAbsRotation; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  m_Index = pRemove->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( (pRemove->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pRemove, a2: (int)&savedregs);
    z = pRemove->m_vecAbsOrigin.z;
    v3 = (unsigned int)pRemove->m_iEFlags >> 11;
    *(_QWORD *)&vecAbsOrigin.x = *(_QWORD *)&pRemove->m_vecAbsOrigin.x;
    vecAbsOrigin.z = z;
    if ( (v3 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pRemove, a2: (int)&savedregs);
    v4 = pRemove->m_angAbsRotation.z;
    v5 = (unsigned int)pRemove->m_iEFlags >> 12;
    *(_QWORD *)&angAbsRotation.x = *(_QWORD *)&pRemove->m_angAbsRotation.x;
    angAbsRotation.z = v4;
    if ( (v5 & 1) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: pRemove, a2: (int)&savedregs);
    v6 = pRemove->m_hMoveParent.m_Value.m_Index;
    v7 = pRemove->m_vecAbsVelocity.z;
    *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&pRemove->m_vecAbsVelocity.x;
    vecAbsVelocity.z = v7;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    UnlinkChild(pParent: m_pEntity, pChild: pRemove);
    CBaseEntity::SetLocalOrigin(this: pRemove, origin: &vecAbsOrigin);
    CBaseEntity::SetLocalAngles(this: pRemove, angles: &angAbsRotation);
    CBaseEntity::SetLocalVelocity(this: pRemove, vecVelocity: &vecAbsVelocity);
    m_pPhysicsObject = pRemove->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
      m_pPhysicsObject->SetPosition(this: m_pPhysicsObject, a2: &vecAbsOrigin, a3: &angAbsRotation, a4: true);
    m_Value = pRemove->m_MoveType.m_Value;
    if ( m_Value != 0 && m_Value != 6 )
      CBaseEntity::UpdateWaterState(this: pRemove);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C4D0
// Name: void LinkChild(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LinkChild(CBaseEntity *pParent, CBaseEntity *pChild)
{
  unsigned int m_Index; // ebx
  unsigned int v3; // eax
  IHandleEntity *m_pEntity; // ecx
  const CBaseEntity *v5; // eax

  if ( pParent != nullptr )
    m_Index = pParent->GetRefEHandle(this: pParent)->m_Index;
  else
    m_Index = -1;
  v3 = pParent->m_hMoveChild.m_Index;
  if ( v3 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
  if ( m_pEntity != nullptr )
    pChild->m_hMovePeer.m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
  else
    pChild->m_hMovePeer.m_Index = -1;
  if ( pChild != nullptr )
    pParent->m_hMoveChild.m_Index = pChild->GetRefEHandle(this: pChild)->m_Index;
  else
    pParent->m_hMoveChild.m_Index = -1;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    v5 = nullptr;
  else
    v5 = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hMoveParent>::Set(this: &pChild->m_hMoveParent, val: v5);
  pChild->m_Network.m_hParent.m_Index = m_Index;
  CBaseEntity::DispatchUpdateTransmitState(this: pChild);
  pChild->OnEntityEvent(this: pChild, a2: ENTITY_EVENT_PARENT_CHANGED, a3: nullptr);
  CBaseEntity::RecalcHasPlayerChildBit(this: pParent);
}

//------------------------------------------------------------------------------
// Address: 0x1015C5C0
// Name: void TransferChildren(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TransferChildren(CBaseEntity *pOldParent, CBaseEntity *pNewParent)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // esi
  Vector vecAbsVelocity; // [esp+8h] [ebp-24h] BYREF
  QAngle angAbsRotation; // [esp+14h] [ebp-18h] BYREF
  Vector vecAbsOrigin; // [esp+20h] [ebp-Ch] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  m_Index = pOldParent->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  for ( ; m_pEntity != nullptr; m_pEntity = CBaseEntity::FirstMoveChild(this: pOldParent) )
  {
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
    vecAbsOrigin = m_pEntity->m_vecAbsOrigin;
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
    angAbsRotation = m_pEntity->m_angAbsRotation;
    if ( (m_pEntity->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: m_pEntity, a2: (int)&savedregs);
    vecAbsVelocity = m_pEntity->m_vecAbsVelocity;
    UnlinkChild(pParent: pOldParent, pChild: m_pEntity);
    LinkChild(pParent: pNewParent, pChild: m_pEntity);
    m_pEntity->m_vecAbsOrigin.x = 3.4028235e38;
    m_pEntity->m_vecAbsOrigin.y = 3.4028235e38;
    m_pEntity->m_vecAbsOrigin.z = 3.4028235e38;
    m_pEntity->m_angAbsRotation.x = 3.4028235e38;
    m_pEntity->m_angAbsRotation.y = 3.4028235e38;
    m_pEntity->m_angAbsRotation.z = 3.4028235e38;
    m_pEntity->m_vecAbsVelocity.x = 3.4028235e38;
    m_pEntity->m_vecAbsVelocity.y = 3.4028235e38;
    m_pEntity->m_vecAbsVelocity.z = 3.4028235e38;
    CBaseEntity::SetAbsOrigin(this: m_pEntity, absOrigin: &vecAbsOrigin);
    CBaseEntity::SetAbsAngles(this: m_pEntity, absAngles: &angAbsRotation);
    CBaseEntity::SetAbsVelocity(this: m_pEntity, &vecAbsVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C720
// Name: GetAllChildren_r
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetAllChildren_r(CBaseEntity *pEntity, CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *list)
{
  CBaseEntity *v2; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBaseEntity **m_pMemory; // ecx
  int v6; // eax
  CBaseEntity **v7; // eax
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v10; // eax
  IHandleEntity *v11; // eax

  v2 = pEntity;
  if ( pEntity != nullptr )
  {
    do
    {
      m_Size = list->m_Size;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)list,
          num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      m_pMemory = list->m_Memory.m_pMemory;
      v6 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v6 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
      v7 = &list->m_Memory.m_pMemory[m_Size];
      if ( v7 != nullptr )
        *v7 = v2;
      m_Index = v2->m_hMoveChild.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      GetAllChildren_r(pEntity: m_pEntity, list);
      v10 = v2->m_hMovePeer.m_Index;
      if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
        v11 = nullptr;
      else
        v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
      v2 = (CBaseEntity *)v11;
    }
    while ( v11 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C800
// Name: int GetAllChildren(class CBaseEntity __near *,class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl GetAllChildren(
        CBaseEntity *pParent,
        CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *list)
{
  CBaseEntity *result; // eax
  unsigned int m_Index; // ecx

  result = pParent;
  if ( pParent != nullptr )
  {
    m_Index = pParent->m_hMoveChild.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      GetAllChildren_r(pEntity: nullptr, list);
      return (CBaseEntity *)list->m_Size;
    }
    else
    {
      GetAllChildren_r(pEntity: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity, list);
      return (CBaseEntity *)list->m_Size;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015C860
// Name: int GetAllInHierarchy(class CBaseEntity __near *,class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAllInHierarchy(CBaseEntity *pParent, CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *list)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CBaseEntity **m_pMemory; // ecx
  int v6; // eax
  CBaseEntity **v7; // eax

  if ( pParent == nullptr )
    return 0;
  m_nAllocationCount = list->m_Memory.m_nAllocationCount;
  m_Size = list->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)list,
      num: m_Size - m_nAllocationCount + 1);
  ++list->m_Size;
  m_pMemory = list->m_Memory.m_pMemory;
  v6 = list->m_Size - m_Size - 1;
  list->m_pElements = list->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &list->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pParent;
  return (int)&GetAllChildren(pParent, list)->__vftable + 1;
}
