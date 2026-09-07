// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/rope.cpp
// Functions: 38
// ============================================================

#include "game\server\rope.h"

//------------------------------------------------------------------------------
// Address: 0x10104F20
// Name: public: virtual void CRopeKeyframe::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::Spawn(CPhysicsWire *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F5530
// Name: public: virtual class ServerClass __near * CRopeKeyframe::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CRopeKeyframe::GetServerClass(CRopeKeyframe *this)
{
  return &g_CRopeKeyframe_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101F5540
// Name: public: virtual struct datamap_t __near * CRopeKeyframe::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRopeKeyframe::GetDataDescMap(CRopeKeyframe *this)
{
  return &CRopeKeyframe::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101F5550
// Name: public: static void CRopeKeyframe::PrecacheShakeRopes(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CRopeKeyframe::PrecacheShakeRopes()
{
  PrecacheEffect(pEffectName: "ShakeRopes");
}

//------------------------------------------------------------------------------
// Address: 0x101F5560
// Name: private: void CRopeKeyframe::SetMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::SetMaterial(CRopeKeyframe *this, const char *pName)
{
  this->m_strRopeMaterialModel.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&pName).pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x101F55F0
// Name: public: static void CRopeKeyframe::ShakeRopes(class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRopeKeyframe::ShakeRopes(const Vector *vCenter, float flRadius, float flMagnitude)
{
  CEffectData shakeData; // [esp+0h] [ebp-64h] BYREF

  memset((void *)&shakeData.m_vStart, 0, 44);
  shakeData.m_flScale = 1.0;
  shakeData.m_nAttachmentIndex = 0;
  memset(&shakeData.m_nMaterial, 0, 17);
  shakeData.m_vOrigin = *vCenter;
  shakeData.m_flRadius = flRadius;
  shakeData.m_nSurfaceProp = 0;
  shakeData.m_flMagnitude = flMagnitude;
  DispatchEffect(pName: "ShakeRopes", data: &shakeData);
}

//------------------------------------------------------------------------------
// Address: 0x101F56A0
// Name: private: bool CRopeKeyframe::GetEndPointPos2(class CBaseEntity __near *,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRopeKeyframe::GetEndPointPos2(
        CRopeKeyframe *this,
        CBaseEntity *pAttached,
        int iAttachment,
        Vector *vPos)
{
  CBaseAnimating *v5; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( pAttached == nullptr )
    return 0;
  if ( iAttachment <= 0 )
  {
    if ( (pAttached->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pAttached, a2: (int)&savedregs);
    *vPos = pAttached->m_vecAbsOrigin;
  }
  else
  {
    v5 = pAttached->GetBaseAnimating(this: pAttached);
    if ( v5 == nullptr
      || !CBaseAnimating::GetAttachment(
            this: v5,
            iAttachment,
            absOrigin: vPos,
            forward: nullptr,
            right: nullptr,
            up: nullptr) )
    {
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F5B10
// Name: public: virtual void CRopeKeyframe::SetParent(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::SetParent(CRopeKeyframe *this, CBaseEntity *pNewParent, int iAttachment)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      --m_pEntity->m_nTransmitStateOwnedCounter;
      CBaseEntity::DispatchUpdateTransmitState(this: m_pEntity);
    }
  }
  if ( pNewParent != nullptr )
  {
    ++pNewParent->m_nTransmitStateOwnedCounter;
    CBaseEntity::SetTransmitState(this: pNewParent, nFlag: 8);
  }
  CBaseEntity::SetParent(this, pParentEntity: pNewParent, iAttachment);
}

//------------------------------------------------------------------------------
// Address: 0x101F5B80
// Name: public: void CRopeKeyframe::EndpointsChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::EndpointsChanged(CRopeKeyframe *this)
{
  CBaseEntityList *v1; // edx
  unsigned int m_Index; // eax
  CRopeKeyframe **v4; // ecx
  CRopeKeyframe *v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax
  CRopeKeyframe **v8; // ecx
  CRopeKeyframe *v9; // edi
  unsigned int v10; // eax

  v1 = g_pEntityList;
  m_Index = this->m_hStartPoint.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (CRopeKeyframe **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      v5 = *v4;
      if ( *v4 != nullptr
        && (v5 != this
         || (v6 = this->m_hMoveParent.m_Value.m_Index) != -1
         && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6)
         && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity != nullptr) )
      {
        WatchPositionChanges(pWatcher: this, pMovingEntity: v5);
        v1 = g_pEntityList;
      }
    }
  }
  v7 = this->m_hEndPoint.m_Value.m_Index;
  if ( v7 != -1 )
  {
    v8 = (CRopeKeyframe **)&v1->m_EntPtrArray[(unsigned __int16)v7];
    if ( v1->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
    {
      v9 = *v8;
      if ( *v8 != nullptr
        && (v9 != this
         || (v10 = this->m_hMoveParent.m_Value.m_Index) != -1
         && v1->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == HIWORD(v10)
         && v1->m_EntPtrArray[(unsigned __int16)v10].m_pEntity != nullptr) )
      {
        WatchPositionChanges(pWatcher: this, pMovingEntity: v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5C50
// Name: public: virtual void CRopeKeyframe::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::SetTransmit(CRopeKeyframe *this, CCheckTransmitInfo *pInfo, int bAlways)
{
  edict_t *m_pPev; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseEntity::SetTransmit(this, pInfo, bAlways);
    m_Index = this->m_hStartPoint.m_Value.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, int))m_pEntity->__vftable[7].SetRefEHandle)(
          a1: m_pEntity,
          a2: pInfo,
          a3: bAlways);
    }
    v7 = this->m_hEndPoint.m_Value.m_Index;
    if ( v7 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
    {
      v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      if ( v8 != nullptr )
        ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, int))v8->__vftable[7].SetRefEHandle)(
          a1: v8,
          a2: pInfo,
          a3: bAlways);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5D10
// Name: private: void CRopeKeyframe::UpdateBBox(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::UpdateBBox(CRopeKeyframe *this, bool bForceRelink)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v5; // eax
  CBaseEntity *v6; // ecx
  double x; // xmm0_8
  float v8; // xmm0_4
  double y; // xmm0_8
  float v10; // xmm0_4
  double z; // xmm0_8
  float v12; // xmm4_4
  double v13; // xmm0_8
  float v14; // xmm3_4
  double v15; // xmm0_8
  float v16; // xmm2_4
  double v17; // xmm0_8
  unsigned int v18; // eax
  float v19; // xmm0_4
  int m_iEFlags; // ecx
  float v21; // xmm4_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  const Vector *v26; // eax
  const Vector *v27; // eax
  Vector v2; // [esp+8h] [ebp-30h] BYREF
  Vector v1; // [esp+14h] [ebp-24h] BYREF
  Vector vMin; // [esp+20h] [ebp-18h] BYREF
  Vector vMax; // [esp+2Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  m_Index = this->m_hStartPoint.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( CRopeKeyframe::GetEndPointPos2(
         this,
         pAttached: m_pEntity,
         iAttachment: this->m_iStartAttachment.m_Value,
         vPos: &v1) == 0 )
  {
    v23 = 0.0;
    vMax.x = 0.0;
    vMax.y = 0.0;
    memset((void *)&vMin, 0, sizeof(vMin));
LABEL_32:
    vMax.z = v23;
    goto LABEL_33;
  }
  v5 = this->m_hEndPoint.m_Value.m_Index;
  if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
    v6 = nullptr;
  else
    v6 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  if ( CRopeKeyframe::GetEndPointPos2(this, pAttached: v6, iAttachment: this->m_iEndAttachment.m_Value, vPos: &v2) != 0 )
  {
    x = v1.x;
    if ( v1.x > (double)v2.x )
      x = v2.x;
    v8 = x;
    vMin.x = v8;
    y = v1.y;
    if ( v1.y > (double)v2.y )
      y = v2.y;
    v10 = y;
    vMin.y = v10;
    z = v1.z;
    if ( v1.z > (double)v2.z )
      z = v2.z;
    v12 = z;
    v13 = v1.x;
    vMin.z = v12;
    if ( v1.x < (double)v2.x )
      v13 = v2.x;
    v14 = v13;
    v15 = v1.y;
    vMax.x = v14;
    if ( v1.y < (double)v2.y )
      v15 = v2.y;
    v16 = v15;
    v17 = v1.z;
    vMax.y = v16;
    if ( v1.z < (double)v2.z )
      v17 = v2.z;
    v18 = (unsigned int)this->m_iEFlags >> 11;
    v19 = v17;
    vMax.z = v19;
    if ( (v18 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v12 = vMin.z;
      v19 = vMax.z;
      v16 = vMax.y;
      v14 = vMax.x;
    }
    m_iEFlags = this->m_iEFlags;
    v21 = v12 - this->m_vecAbsOrigin.z;
    vMin.x = vMin.x - this->m_vecAbsOrigin.x;
    vMin.y = vMin.y - this->m_vecAbsOrigin.y;
    vMin.z = v21;
    if ( (m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v19 = vMax.z;
      v16 = vMax.y;
      v14 = vMax.x;
    }
    v22 = v16 - this->m_vecAbsOrigin.y;
    v23 = v19 - this->m_vecAbsOrigin.z;
    vMax.x = v14 - this->m_vecAbsOrigin.x;
    vMax.y = v22;
    goto LABEL_32;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v24 = v1.y - this->m_vecAbsOrigin.y;
  v25 = v1.z - this->m_vecAbsOrigin.z;
  vMax.x = v1.x - this->m_vecAbsOrigin.x;
  vMax.y = v24;
  vMax.z = v25;
  vMin = vMax;
LABEL_33:
  v26 = this->m_Collision.OBBMins(this: &this->m_Collision);
  if ( vMin.x != v26->x
    || vMin.y != v26->y
    || vMin.z != v26->z
    || (v27 = this->m_Collision.OBBMaxs(this: &this->m_Collision), vMax.x != v27->x)
    || vMax.y != v27->y
    || vMax.z != v27->z )
  {
    UTIL_SetSize(pEnt: this, vecMin: &vMin, vecMax: &vMax);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6050
// Name: public: void CRopeKeyframe::PropagateForce(class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::PropagateForce(
        CRopeKeyframe *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CRopeKeyframe *pFirstLink,
        float x,
        float y,
        float z)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CRopeKeyframe *v10; // eax

  while ( 1 )
  {
    EntityMessageBegin(entity: this, reliable: 1);
    MessageWriteFloat(flValue: x);
    MessageWriteFloat(flValue: y);
    MessageWriteFloat(flValue: z);
    MessageEnd();
    m_Index = this->m_hEndPoint.m_Value.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v10 = (CRopeKeyframe *)__RTDynamicCast(
                             inptr: m_pEntity,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CRopeKeyframe `RTTI Type Descriptor',
                             isReference: 0);
    if ( v10 == nullptr || v10 == pFirstLink )
      break;
    this = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6100
// Name: public: void CRopeKeyframe::InputSetForce(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::InputSetForce(CRopeKeyframe *this, inputdata_t *inputdata)
{
  _fieldtypes fieldType; // edx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4

  fieldType = inputdata->value.fieldType;
  if ( fieldType == FIELD_VECTOR || fieldType == FIELD_POSITION_VECTOR )
  {
    x = inputdata->value.flVal;
    y = inputdata->value.vecVal[1];
    z = inputdata->value.vecVal[2];
  }
  else
  {
    x = vec3_origin.x;
    y = vec3_origin.y;
    z = vec3_origin.z;
  }
  CRopeKeyframe::PropagateForce(
    this,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    pFirstLink: this,
    x,
    y,
    z);
}

//------------------------------------------------------------------------------
// Address: 0x101F6170
// Name: protected: void CRopeKeyframe::SetAttachmentPoint(class CBaseHandle __near &,short __near &,class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::SetAttachmentPoint(
        CRopeKeyframe *this,
        CBaseHandle *hOutEnt,
        __int16 *iOutAttachment,
        CBaseEntity *pEnt,
        __int16 iAttachment)
{
  unsigned int m_Index; // eax
  CEntInfo *v7; // ecx
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v9; // eax

  m_Index = hOutEnt->m_Index;
  if ( hOutEnt->m_Index != -1 )
  {
    v7 = &gEntList.m_EntPtrArray[(unsigned __int16)m_Index];
    if ( v7->m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = v7->m_pEntity;
      if ( m_pEntity != nullptr )
      {
        v9 = (CBaseEntity *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
        if ( v9 != nullptr && v9->m_Network.m_pPev != nullptr )
        {
          --v9->m_nTransmitStateOwnedCounter;
          CBaseEntity::DispatchUpdateTransmitState(this: v9);
        }
      }
    }
  }
  if ( pEnt != nullptr )
    hOutEnt->m_Index = pEnt->GetRefEHandle(this: pEnt)->m_Index;
  else
    hOutEnt->m_Index = -1;
  *iOutAttachment = iAttachment;
  if ( pEnt != nullptr )
  {
    CBaseEntity::SetTransmitState(this: pEnt, nFlag: 8);
    ++pEnt->m_nTransmitStateOwnedCounter;
  }
  CRopeKeyframe::EndpointsChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F6210
// Name: public: void CRopeKeyframe::SetStartPoint(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::SetStartPoint(CRopeKeyframe *this, CBaseEntity *pStartPoint, __int16 attachment)
{
  CNetworkVarBase<short,CRopeKeyframe::NetworkVar_m_iStartAttachment> *p_m_iStartAttachment; // ebx
  __int16 v5; // ax
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx

  p_m_iStartAttachment = &this->m_iStartAttachment;
  v5 = (__int16)this;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: (_WORD)p_m_iStartAttachment - v5);
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v7 = this->m_Network.m_pPev;
    if ( v7 != nullptr )
      CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x398u);
  }
  CRopeKeyframe::SetAttachmentPoint(
    this,
    hOutEnt: &this->m_hStartPoint.m_Value,
    iOutAttachment: &p_m_iStartAttachment->m_Value,
    pEnt: pStartPoint,
    iAttachment: attachment);
}

//------------------------------------------------------------------------------
// Address: 0x101F6290
// Name: public: void CRopeKeyframe::SetEndPoint(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::SetEndPoint(CRopeKeyframe *this, CBaseEntity *pEndPoint, __int16 attachment)
{
  CNetworkVarBase<short,CRopeKeyframe::NetworkVar_m_iEndAttachment> *p_m_iEndAttachment; // ebx
  __int16 v5; // ax
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx

  p_m_iEndAttachment = &this->m_iEndAttachment;
  v5 = (__int16)this;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: (_WORD)p_m_iEndAttachment - v5);
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v7 = this->m_Network.m_pPev;
    if ( v7 != nullptr )
      CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x39Cu);
  }
  CRopeKeyframe::SetAttachmentPoint(
    this,
    hOutEnt: &this->m_hEndPoint.m_Value,
    iOutAttachment: &p_m_iEndAttachment->m_Value,
    pEnt: pEndPoint,
    iAttachment: attachment);
}

//------------------------------------------------------------------------------
// Address: 0x101F6310
// Name: public: CRopeKeyframe::CRopeKeyframe(void)
// Source: json
//------------------------------------------------------------------------------
CRopeKeyframe *__thiscall CRopeKeyframe::CRopeKeyframe(CRopeKeyframe *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  CRopeKeyframe *result; // eax
  edict_t *v14; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&IPositionWatcher::`vftable';
  this->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CRopeKeyframe_vtbl *)&CRopeKeyframe::`vftable'{for `CBaseEntity'};
  this->IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&CRopeKeyframe::`vftable'{for `IPositionWatcher'};
  this->m_hStartPoint.m_Value.m_Index = -1;
  this->m_hEndPoint.m_Value.m_Index = -1;
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  if ( this->m_iEndAttachment.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A2u);
    }
    this->m_iEndAttachment.m_Value = 0;
  }
  if ( this->m_iStartAttachment.m_Value != this->m_iEndAttachment.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x3A0u);
    }
    this->m_iStartAttachment.m_Value = this->m_iEndAttachment.m_Value;
  }
  if ( this->m_Slack.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x360u);
    }
    this->m_Slack.m_Value = 0;
  }
  if ( this->m_Width.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x364u);
    }
    this->m_Width.m_Value = 2.0;
  }
  if ( this->m_TextureScale.m_Value != 4.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x368u);
    }
    this->m_TextureScale.m_Value = 4.0;
  }
  if ( this->m_nSegments.m_Value != 5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x36Cu);
    }
    this->m_nSegments.m_Value = 5;
  }
  if ( this->m_RopeLength.m_Value != 20 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x384u);
    }
    this->m_RopeLength.m_Value = 20;
  }
  if ( this->m_fLockedPoints.m_Value != 3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x388u);
    }
    this->m_fLockedPoints.m_Value = 3;
  }
  if ( this->m_flScrollSpeed.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x390u);
    }
    this->m_flScrollSpeed.m_Value = 0.0;
  }
  if ( this->m_RopeFlags.m_Value != 72 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x358u);
    }
    this->m_RopeFlags.m_Value = 72;
  }
  if ( this->m_iRopeMaterialModelIndex.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x378u);
    }
    this->m_iRopeMaterialModelIndex.m_Value = -1;
  }
  result = this;
  if ( this->m_Subdiv.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x37Cu);
    }
    this->m_Subdiv.m_Value = 2;
    result = this;
  }
  this->m_bCreatedFromMapFile = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F6660
// Name: public: virtual CRopeKeyframe::~CRopeKeyframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::~CRopeKeyframe(CRopeKeyframe *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  this->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CRopeKeyframe_vtbl *)&CRopeKeyframe::`vftable'{for `CBaseEntity'};
  this->IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&CRopeKeyframe::`vftable'{for `IPositionWatcher'};
  CRopeKeyframe::SetStartPoint(this, pStartPoint: nullptr, attachment: 0);
  CRopeKeyframe::SetEndPoint(this, pEndPoint: nullptr, attachment: 0);
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      --m_pEntity->m_nTransmitStateOwnedCounter;
      CBaseEntity::DispatchUpdateTransmitState(this: m_pEntity);
    }
  }
  CBaseEntity::SetParent(this, pParentEntity: nullptr, iAttachment: 0);
  this->IPositionWatcher::IWatcherCallback::__vftable = (IPositionWatcher_vtbl *)&IWatcherCallback::`vftable';
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F66E0
// Name: public: static class CRopeKeyframe __near * CRopeKeyframe::CreateWithSecondPointDetached(class CBaseEntity __near *,int,int,int,char const __near *,int,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRopeKeyframe *__cdecl CRopeKeyframe::CreateWithSecondPointDetached(
        CBaseEntity *pStartEnt,
        __int16 iStartAttachment,
        int ropeLength,
        int ropeWidth,
        const char *pMaterialName,
        int numSegments,
        bool bInitialHang,
        const char *pClassName)
{
  CRopeKeyframe *result; // eax
  CRopeKeyframe *v9; // ebx
  CBaseEdict *v10; // ecx
  unsigned int v11; // edi
  CBaseEdict *v12; // ecx
  CBaseEdict *v13; // ecx
  float m_Value; // xmm1_4
  float v15; // xmm0_4
  CBaseEdict *v16; // ecx
  int v17; // edi
  CBaseEdict *v18; // ecx
  char pszValue[4]; // [esp+4h] [ebp-4h] BYREF

  result = (CRopeKeyframe *)CreateEntityByName(className: pClassName, iForceEdictIndex: -1, bNotify: true);
  v9 = result;
  if ( result != nullptr )
  {
    CRopeKeyframe::SetStartPoint(this: result, pStartPoint: pStartEnt, attachment: iStartAttachment);
    CRopeKeyframe::SetEndPoint(this: v9, pEndPoint: nullptr, attachment: 0);
    v9->m_bCreatedFromMapFile = false;
    if ( v9->m_fLockedPoints.m_Value != 1 )
    {
      if ( v9->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v9->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = &v9->m_Network.m_pPev->CBaseEdict;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: v10, offset: 0x388u);
      }
      v9->m_fLockedPoints.m_Value = 1;
    }
    if ( !bInitialHang )
    {
      v11 = v9->m_RopeFlags.m_Value & 0xFFFFFFBF;
      if ( v9->m_RopeFlags.m_Value != v11 )
      {
        if ( v9->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v9->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = &v9->m_Network.m_pPev->CBaseEdict;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: v12, offset: 0x358u);
        }
        v9->m_RopeFlags.m_Value = v11;
      }
    }
    v9->Init(this: v9);
    v9->m_strRopeMaterialModel.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
    if ( v9->m_RopeLength.m_Value != ropeLength )
    {
      if ( v9->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v9->m_Network + 76) |= 1u;
      }
      else
      {
        v13 = &v9->m_Network.m_pPev->CBaseEdict;
        if ( v13 != nullptr )
          CBaseEdict::StateChanged(this: v13, offset: 0x384u);
      }
      v9->m_RopeLength.m_Value = ropeLength;
    }
    m_Value = v9->m_Width.m_Value;
    v15 = (float)ropeWidth;
    *(float *)pszValue = (float)ropeWidth;
    if ( m_Value != (float)ropeWidth )
    {
      if ( v9->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v9->m_Network + 76) |= 1u;
      }
      else
      {
        v16 = &v9->m_Network.m_pPev->CBaseEdict;
        if ( v16 != nullptr )
        {
          CBaseEdict::StateChanged(this: v16, offset: 0x364u);
          v15 = *(float *)pszValue;
        }
      }
      v9->m_Width.m_Value = v15;
    }
    if ( numSegments >= 2 )
    {
      v17 = 10;
      if ( numSegments <= 10 )
        v17 = numSegments;
    }
    else
    {
      v17 = 2;
    }
    if ( v9->m_nSegments.m_Value != v17 )
    {
      result = v9;
      if ( v9->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v9->m_Network + 76) |= 1u;
        v9->m_nSegments.m_Value = v17;
        return result;
      }
      v18 = &v9->m_Network.m_pPev->CBaseEdict;
      if ( v18 != nullptr )
        CBaseEdict::StateChanged(this: v18, offset: 0x36Cu);
      v9->m_nSegments.m_Value = v17;
    }
    return v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F68A0
// Name: public: virtual void CRopeKeyframe::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRopeKeyframe::Activate(CRopeKeyframe *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  int v3; // ebx
  edict_t *m_pPev; // ecx
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  int v7; // edi
  edict_t *v8; // ecx
  unsigned int v9; // ebx
  edict_t *v10; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  CBaseEntity::Activate(this);
  if ( this->m_bCreatedFromMapFile )
  {
    if ( this->m_iRopeMaterialModelIndex.m_Value == -1 )
    {
      v3 = CBaseEntity::PrecacheModel(a1: a2, name: "cable/cable.vmt", bPreload: true);
      if ( this->m_iRopeMaterialModelIndex.m_Value != v3 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
        }
        this->m_iRopeMaterialModelIndex.m_Value = v3;
      }
    }
    pszValue = this->m_iNextLinkName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr && EntityByName->m_Network.m_pPev != nullptr )
    {
      CRopeKeyframe::SetEndPoint(this, pEndPoint: EntityByName, attachment: 0);
      if ( (this->m_spawnflags.m_Value & 1) != 0 )
      {
        v7 = this->m_RopeFlags.m_Value | 1;
        if ( this->m_RopeFlags.m_Value != v7 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
            this->m_RopeFlags.m_Value = v7;
          }
          else
          {
            v8 = this->m_Network.m_pPev;
            if ( v8 != nullptr )
              CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x358u);
            this->m_RopeFlags.m_Value = v7;
          }
        }
      }
    }
    else if ( (this->m_fLockedPoints.m_Value & 2) != 0 )
    {
      v9 = this->m_RopeFlags.m_Value & 0xFFFFFFF7;
      if ( this->m_RopeFlags.m_Value != v9 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v10 = this->m_Network.m_pPev;
          if ( v10 != nullptr )
            CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x358u);
        }
        this->m_RopeFlags.m_Value = v9;
      }
    }
    CRopeKeyframe::SetStartPoint(this, pStartPoint: this, attachment: 0);
    m_Index = this->m_pParent.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    this->SetParent(this, a2: m_pEntity, a3: this->m_iParentAttachment.m_Value);
    CRopeKeyframe::EndpointsChanged(this);
    this->Init(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6A30
// Name: public: void CRopeKeyframe::RecalculateLength(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRopeKeyframe::RecalculateLength(CRopeKeyframe *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // eax
  int v3; // edx
  unsigned int v4; // esi
  unsigned int v5; // eax
  CBaseEntity *m_pEntity; // edi
  int v7; // edx
  CBaseEntity *v8; // esi
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  int v12; // edi
  edict_t *m_pPev; // ecx
  CNetworkVarBase<int,CRopeKeyframe::NetworkVar_m_RopeLength> *p_m_RopeLength; // esi
  edict_t *v15; // ecx
  _DWORD v17[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v17[0] = a2;
  v17[1] = retaddr;
  m_Index = this->m_hEndPoint.m_Value.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = HIWORD(m_Index),
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v5 = this->m_hStartPoint.m_Value.m_Index;
    if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
    v7 = v3;
    if ( g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v4 )
      v8 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[v7].m_pEntity;
    else
      v8 = nullptr;
    if ( (v8->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v8, a2: (int)v17);
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)v17);
    v9 = m_pEntity->m_vecAbsOrigin.x - v8->m_vecAbsOrigin.x;
    v10 = m_pEntity->m_vecAbsOrigin.y - v8->m_vecAbsOrigin.y;
    v11 = m_pEntity->m_vecAbsOrigin.z - v8->m_vecAbsOrigin.z;
    v12 = (int)fsqrt((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v9 * v9));
    if ( this->m_RopeLength.m_Value != v12 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_RopeLength.m_Value = v12;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x384u);
        this->m_RopeLength.m_Value = v12;
      }
    }
  }
  else
  {
    p_m_RopeLength = &this->m_RopeLength;
    if ( this->m_RopeLength.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_RopeLength->m_Value = 0;
      }
      else
      {
        v15 = this->m_Network.m_pPev;
        if ( v15 != nullptr )
          CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x384u);
        p_m_RopeLength->m_Value = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6BF0
// Name: public: bool CRopeKeyframe::Break(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRopeKeyframe::Break(CRopeKeyframe *this)
{
  CNetworkVarBase<int,CRopeKeyframe::NetworkVar_m_fLockedPoints> *p_m_fLockedPoints; // edi
  unsigned int v2; // esi
  edict_t *m_pPev; // ecx
  CRopeKeyframe *EntBy; // ebx
  const char *pszValue; // ecx
  const char *v6; // eax
  unsigned int v7; // esi
  CBaseEdict *v8; // ecx
  CBaseEntity *Ent; // esi
  CRopeKeyframe *v10; // eax

  p_m_fLockedPoints = &this->m_fLockedPoints;
  v2 = this->m_fLockedPoints.m_Value & 0xFFFFFFFE;
  if ( this->m_fLockedPoints.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x388u);
    }
    p_m_fLockedPoints->m_Value = v2;
  }
  EntBy = CGlobalEntityList::NextEntByClass<CRopeKeyframe>(this: &gEntList, start: nullptr);
  if ( EntBy != nullptr )
  {
    while ( 1 )
    {
      pszValue = this->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v6 = EntBy->m_iNextLinkName.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      if ( _V_stricmp(s1: v6, s2: pszValue) == 0 )
      {
        v7 = EntBy->m_fLockedPoints.m_Value & 0xFFFFFFFD;
        if ( EntBy->m_fLockedPoints.m_Value != v7 )
        {
          if ( EntBy->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&EntBy->m_Network + 76) |= 1u;
          }
          else
          {
            v8 = &EntBy->m_Network.m_pPev->CBaseEdict;
            if ( v8 != nullptr )
              CBaseEdict::StateChanged(this: v8, offset: 0x388u);
          }
          EntBy->m_fLockedPoints.m_Value = v7;
        }
      }
      Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: EntBy);
      if ( Ent == nullptr )
        break;
      while ( 1 )
      {
        v10 = (CRopeKeyframe *)__RTDynamicCast(
                                 inptr: Ent,
                                 VfDelta: 0,
                                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                                 TargetType: &CRopeKeyframe `RTTI Type Descriptor',
                                 isReference: 0);
        if ( v10 != nullptr )
          break;
        Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
        if ( Ent == nullptr )
          return 1;
      }
      EntBy = v10;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D10
// Name: public: virtual int CRopeKeyframe::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRopeKeyframe::OnTakeDamage(CRopeKeyframe *this, const CTakeDamageInfo *info)
{
  if ( (this->m_RopeFlags.m_Value & 0x10) != 0 )
    CRopeKeyframe::Break(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D30
// Name: public: virtual void CRopeKeyframe::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRopeKeyframe::Precache(CRopeKeyframe *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *pszValue; // eax
  int v4; // edi
  edict_t *m_pPev; // ecx

  pszValue = this->m_strRopeMaterialModel.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v4 = CBaseEntity::PrecacheModel(a1: a2, name: pszValue, bPreload: true);
  if ( this->m_iRopeMaterialModelIndex.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
    }
    this->m_iRopeMaterialModelIndex.m_Value = v4;
  }
  PrecacheMaterial(pMaterialName: "cable/rope_shadowdepth");
}

//------------------------------------------------------------------------------
// Address: 0x101F6DA0
// Name: public: virtual bool CRopeKeyframe::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRopeKeyframe::KeyValue(CRopeKeyframe *this, char *szKeyName, char *szValue)
{
  char *v3; // edi
  int v5; // edi
  CRopeKeyframe *v6; // eax
  CBaseEdict *v7; // ecx
  unsigned int v9; // edi
  edict_t *v10; // ecx
  int v11; // eax
  edict_t *v12; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v14; // ecx
  int v15; // eax
  const char *v16; // eax
  char *v17; // [esp-4h] [ebp-210h]
  char str[512]; // [esp+Ch] [ebp-200h] BYREF

  v3 = szKeyName;
  if ( _V_stricmp(s1: szKeyName, s2: "Breakable") == 0 )
  {
    if ( atoi(nptr: szValue) != 1 )
      return CBaseEntity::KeyValue(this, szKeyName: v3, szValue);
    v5 = this->m_RopeFlags.m_Value | 0x10;
    if ( this->m_RopeFlags.m_Value == v5 )
    {
LABEL_9:
      v3 = szKeyName;
      return CBaseEntity::KeyValue(this, szKeyName: v3, szValue);
    }
    v6 = this;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
LABEL_8:
      this->m_RopeFlags.m_Value = v5;
      goto LABEL_9;
    }
    goto LABEL_6;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "Collide") == 0 )
  {
    if ( atoi(nptr: szValue) != 1 )
      return CBaseEntity::KeyValue(this, szKeyName: v3, szValue);
    v5 = this->m_RopeFlags.m_Value | 4;
    if ( this->m_RopeFlags.m_Value == v5 )
      goto LABEL_9;
    v6 = this;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      goto LABEL_8;
    }
LABEL_6:
    v7 = &v6->m_Network.m_pPev->CBaseEdict;
    if ( v7 != nullptr )
      CBaseEdict::StateChanged(this: v7, offset: (_WORD)this + 856 - (_WORD)v6);
    goto LABEL_8;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "Barbed") == 0 )
  {
    if ( atoi(nptr: szValue) != 1 )
      return CBaseEntity::KeyValue(this, szKeyName: v3, szValue);
    v5 = this->m_RopeFlags.m_Value | 2;
    if ( this->m_RopeFlags.m_Value == v5 )
      goto LABEL_9;
    v6 = this;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      goto LABEL_8;
    }
    goto LABEL_6;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "UseWind") == 0 )
  {
    if ( atoi(nptr: szValue) != 1 )
      return CBaseEntity::KeyValue(this, szKeyName: v3, szValue);
    v5 = this->m_RopeFlags.m_Value | 0x20;
    if ( this->m_RopeFlags.m_Value == v5 )
      goto LABEL_9;
    v6 = this;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      goto LABEL_8;
    }
    goto LABEL_6;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "Dangling") != 0 )
  {
    if ( _V_stricmp(s1: szKeyName, s2: "Type") != 0 )
    {
      if ( _V_stricmp(s1: szKeyName, s2: "RopeShader") != 0 )
      {
        if ( _V_stricmp(s1: szKeyName, s2: "RopeMaterial") == 0 )
        {
          v16 = V_stristr(pStr: szValue, pSearch: ".vmt");
          v17 = szValue;
          if ( v16 == nullptr )
          {
            V_snprintf(pDest: str, maxLen: 512, pFormat: "%s.vmt", szValue);
            v17 = str;
          }
          CRopeKeyframe::SetMaterial(this, pName: v17);
        }
      }
      else
      {
        v15 = atoi(nptr: szValue);
        if ( v15 != 0 )
        {
          if ( v15 == 1 )
            this->m_strRopeMaterialModel.pszValue = "cable/rope.vmt";
          else
            this->m_strRopeMaterialModel.pszValue = "cable/chain.vmt";
        }
        else
        {
          this->m_strRopeMaterialModel.pszValue = "cable/cable.vmt";
        }
      }
    }
    else
    {
      v11 = atoi(nptr: szValue);
      if ( v11 != 0 )
      {
        if ( v11 == 1 )
        {
          if ( this->m_nSegments.m_Value != 4 )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
              this->m_nSegments.m_Value = 4;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
              this->m_nSegments.m_Value = 4;
            }
          }
        }
        else if ( this->m_nSegments.m_Value != 2 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
            this->m_nSegments.m_Value = 2;
          }
          else
          {
            v14 = this->m_Network.m_pPev;
            if ( v14 != nullptr )
              CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x36Cu);
            this->m_nSegments.m_Value = 2;
          }
        }
      }
      else if ( this->m_nSegments.m_Value != 10 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_nSegments.m_Value = 10;
        }
        else
        {
          v12 = this->m_Network.m_pPev;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x36Cu);
          this->m_nSegments.m_Value = 10;
        }
      }
    }
    return CBaseEntity::KeyValue(this, szKeyName: v3, szValue);
  }
  if ( atoi(nptr: szValue) == 1 )
  {
    v9 = this->m_fLockedPoints.m_Value & 0xFFFFFFFD;
    if ( this->m_fLockedPoints.m_Value != v9 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_fLockedPoints.m_Value = v9;
        return 1;
      }
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x388u);
      this->m_fLockedPoints.m_Value = v9;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F7130
// Name: public: void CRopeKeyframe::InputSetScrollSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::InputSetScrollSpeed(CRopeKeyframe *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CRopeKeyframe::NetworkVar_m_flScrollSpeed> *p_m_flScrollSpeed; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flScrollSpeed = &this->m_flScrollSpeed;
  if ( this->m_flScrollSpeed.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flScrollSpeed->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x390u);
      p_m_flScrollSpeed->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F71E0
// Name: protected: virtual void CRopeKeyframe::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::Init(CRopeKeyframe *this)
{
  int m_Value; // eax
  int v3; // ebx
  edict_t *m_pPev; // ecx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx
  float v9; // xmm0_4
  unsigned int v10; // eax
  float v11; // edx
  CBaseEntity *v12; // ecx
  edict_t *v13; // ecx
  unsigned int v14; // eax
  float z; // ecx
  CBaseEntity *v16; // ecx
  edict_t *v17; // ecx
  Vector origin; // [esp+24h] [ebp-Ch] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  CRopeKeyframe::RecalculateLength(this, a2: (int)&savedregs);
  m_Value = this->m_nSegments.m_Value;
  if ( m_Value >= 2 )
  {
    v3 = 10;
    if ( m_Value <= 10 )
      v3 = this->m_nSegments.m_Value;
  }
  else
  {
    v3 = 2;
  }
  if ( m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
    }
    this->m_nSegments.m_Value = v3;
  }
  CRopeKeyframe::UpdateBBox(this, bForceRelink: true);
  m_Index = this->m_hStartPoint.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  this->m_bStartPointValid = m_pEntity != nullptr;
  v7 = this->m_hEndPoint.m_Value.m_Index;
  if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
    v8 = nullptr;
  else
    v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
  v9 = this->m_TextureScale.m_Value;
  this->m_bEndPointValid = v8 != nullptr;
  if ( v9 >= 0.1 )
  {
    if ( v9 > 10.0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v14 = this->m_hStartPoint.m_Value.m_Index;
      z = this->m_vecAbsOrigin.z;
      *(_QWORD *)&origin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
      origin.z = z;
      if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
        v16 = nullptr;
      else
        v16 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
      CRopeKeyframe::GetEndPointPos2(this, pAttached: v16, iAttachment: this->m_iStartAttachment.m_Value, vPos: &origin);
      DevMsg(a1: "move_rope has TextureScale greater than 10 at (%2.2f, %2.2f, %2.2f)\n", origin.x, origin.y, origin.z);
      if ( this->m_TextureScale.m_Value != 10.0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v17 = this->m_Network.m_pPev;
          if ( v17 != nullptr )
            CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x368u);
        }
        this->m_TextureScale.m_Value = 10.0;
      }
    }
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v10 = this->m_hStartPoint.m_Value.m_Index;
    v11 = this->m_vecAbsOrigin.z;
    *(_QWORD *)&origin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    origin.z = v11;
    if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
      v12 = nullptr;
    else
      v12 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
    CRopeKeyframe::GetEndPointPos2(this, pAttached: v12, iAttachment: this->m_iStartAttachment.m_Value, vPos: &origin);
    DevMsg(a1: "move_rope has TextureScale less than 0.1 at (%2.2f, %2.2f, %2.2f)\n", origin.x, origin.y, origin.z);
    if ( this->m_TextureScale.m_Value != 0.1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_TextureScale.m_Value = 0.1;
      }
      else
      {
        v13 = this->m_Network.m_pPev;
        if ( v13 != nullptr )
          CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x368u);
        this->m_TextureScale.m_Value = 0.1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F74F0
// Name: public: void CRopeKeyframe::InputBreak(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRopeKeyframe::InputBreak(CRopeKeyframe *this, inputdata_t *inputdata)
{
  CRopeKeyframe::Break(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F7500
// Name: public: virtual void CRopeKeyframe::NotifyPositionChanged(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeKeyframe::NotifyPositionChanged(CRopeKeyframe *this, CBaseEntity *pEntity)
{
  char v3; // dl
  char *v4; // eax
  CBaseEdict *v5; // ecx
  CTimedEventMgr *m_pEventMgr; // eax
  float m_flNextEventTime; // eax
  const Vector *AbsOrigin; // esi
  const Vector *v9; // eax
  char *v10; // esi
  char *v11; // edx
  CBaseEdict *v12; // ecx
  CBaseEntity *v13; // [esp-Ch] [ebp-18h]
  CBaseEntity *m_pEntity; // [esp-8h] [ebp-14h]
  char v15; // [esp-1h] [ebp-Dh]

  v3 = LOBYTE(this->m_Network.m_PVSInfo.m_vCenter[1]) + 1;
  v15 = v3;
  v4 = (char *)this - 852;
  if ( *((_BYTE *)this - 768) != 0 )
  {
    v4[88] |= 1u;
  }
  else
  {
    v5 = *((CBaseEdict **)v4 + 6);
    if ( v5 != nullptr )
    {
      CBaseEdict::StateChanged(this: v5, offset: 0x380u);
      v3 = v15;
    }
  }
  LOBYTE(this->m_Network.m_PVSInfo.m_vCenter[1]) = v3;
  CRopeKeyframe::UpdateBBox(this: (CRopeKeyframe *)((char *)this - 852), bForceRelink: false);
  m_pEventMgr = this->m_Network.m_TimerEvent.m_pEventMgr;
  if ( m_pEventMgr == (CTimedEventMgr *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pEventMgr].m_SerialNumber != (unsigned int)m_pEventMgr >> 16 )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pEventMgr].m_pEntity;
  }
  m_flNextEventTime = this->m_Network.m_TimerEvent.m_flNextEventTime;
  if ( m_flNextEventTime == NAN
    || g_pEntityList->m_EntPtrArray[LOWORD(m_flNextEventTime)].m_SerialNumber != HIWORD(LODWORD(m_flNextEventTime)) )
  {
    v13 = nullptr;
  }
  else
  {
    v13 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(m_flNextEventTime)].m_pEntity;
  }
  if ( ((int)this->m_pfnMoveDone & 1) != 0
    && m_pEntity != nullptr
    && m_pEntity->m_Network.m_pPev != nullptr
    && v13 != nullptr
    && v13->m_Network.m_pPev != nullptr )
  {
    AbsOrigin = CBaseEntity::GetAbsOrigin(this: v13);
    v9 = CBaseEntity::GetAbsOrigin(this: m_pEntity);
    v10 = (char *)this->m_Network.CBaseEntity::__vftable
        + (int)fsqrt(
                 (float)((float)((float)(v9->y - AbsOrigin->y) * (float)(v9->y - AbsOrigin->y))
                       + (float)((float)(v9->z - AbsOrigin->z) * (float)(v9->z - AbsOrigin->z)))
               + (float)((float)(v9->x - AbsOrigin->x) * (float)(v9->x - AbsOrigin->x)));
    if ( (char *)LODWORD(this->m_Network.m_PVSInfo.m_vCenter[2]) != v10 )
    {
      v11 = (char *)this - 852;
      if ( *((_BYTE *)this - 768) != 0 )
      {
        v11[88] |= 1u;
      }
      else
      {
        v12 = *((CBaseEdict **)v11 + 6);
        if ( v12 != nullptr )
          CBaseEdict::StateChanged(this: v12, offset: 0x384u);
      }
      LODWORD(this->m_Network.m_PVSInfo.m_vCenter[2]) = v10;
    }
  }
  if ( LOBYTE(this->m_Network.m_hParent.m_Index) != (m_pEntity != nullptr) )
    LOBYTE(this->m_Network.m_hParent.m_Index) = m_pEntity != nullptr;
  if ( BYTE1(this->m_Network.m_hParent.m_Index) != (v13 != nullptr) )
    BYTE1(this->m_Network.m_hParent.m_Index) = v13 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10409690
// Name: DT_RopeKeyframe::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_RopeKeyframe::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_RopeKeyframe::g_SendTable);
  return atexit(func: DT_RopeKeyframe::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104096B0
// Name: DT_RopeKeyframe::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_RopeKeyframe::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_RopeKeyframe::ignored>();
  DT_RopeKeyframe::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104096C0
// Name: CRopeKeyframe_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRopeKeyframe_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRopeKeyframe>();
  CRopeKeyframe_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041DB00
// Name: DT_RopeKeyframe::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_RopeKeyframe::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_RopeKeyframe::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB10
// Name: _ServerClassInit_DT_RopeKeyframe::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_RopeKeyframe::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_193;
  for ( i = 23; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB30
// Name: _DataMapInit_CRopeKeyframe__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRopeKeyframe__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_365);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB40
// Name: _DataMapInit_entitytable_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_entitytable_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_366);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB50
// Name: _DataMapInit_SaveRestoreBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SaveRestoreBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_367);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB60
// Name: _dynamic_atexit_destructor_for__g_SaveRestoreBlockSet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SaveRestoreBlockSet__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_SaveRestoreBlockSet.m_BlockHeaders);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_SaveRestoreBlockSet.m_Handlers);
}
