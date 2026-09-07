// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/info_camera_link.cpp
// Functions: 7
// ============================================================

#include "game\server\info_camera_link.h"

//------------------------------------------------------------------------------
// Address: 0x10161AF0
// Name: private: virtual struct datamap_t __near * CInfoCameraLink::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CInfoCameraLink::GetDataDescMap(CInfoCameraLink *this)
{
  return &CInfoCameraLink::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10161E20
// Name: private: void CInfoCameraLink::SetCameraByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoCameraLink::SetCameraByName(CInfoCameraLink *this, const char *szName)
{
  CBasePlayer *EntityByName; // eax
  void *v4; // eax
  unsigned int m_Index; // eax

  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
  {
    v4 = __RTDynamicCast(
           inptr: EntityByName,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CPointCamera `RTTI Type Descriptor',
           isReference: 0);
    this->m_hCamera.m_Index = v4 != nullptr
                            ? *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4)
                            : -1;
    m_Index = this->m_hCamera.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      if ( szName != nullptr && *szName != 0 )
        this->m_strPointCamera.pszValue = szName;
      else
        this->m_strPointCamera.pszValue = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161EE0
// Name: private: void CInfoCameraLink::InputSetCamera(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoCameraLink::InputSetCamera(CInfoCameraLink *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
      CInfoCameraLink::SetCameraByName(this, szName: locale);
      return;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  CInfoCameraLink::SetCameraByName(this, szName: iVal);
}

//------------------------------------------------------------------------------
// Address: 0x10161F20
// Name: class CBaseEntity __near * CreateInfoCameraLink(class CBaseEntity __near *,class CPointCamera __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CreateInfoCameraLink(CBaseEntity *pTarget, CPointCamera *pCamera)
{
  CBaseEntity *result; // eax
  CBaseEntity *v3; // esi

  result = CreateEntityByName(className: "info_camera_link", iForceEdictIndex: -1, bNotify: true);
  v3 = result;
  if ( result != nullptr )
  {
    if ( pCamera != nullptr )
      result[1].__vftable = (CBaseEntity_vtbl *)pCamera->GetRefEHandle(this: pCamera)->m_Index;
    else
      result[1].__vftable = (CBaseEntity_vtbl *)-1;
    if ( pTarget != nullptr )
      v3[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))pTarget->GetRefEHandle(this: pTarget)->m_Index;
    else
      v3[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))-1;
    v3->Spawn(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10161FA0
// Name: void PointCameraSetupVisibility(class CBaseEntity __near *,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PointCameraSetupVisibility(CBaseEntity *pPlayer, int area, unsigned __int8 *pvs, int pvssize)
{
  CPointCamera *i; // esi
  CBaseEntity **m_Head; // ebx
  void (__thiscall *m_pfnMoveDone)(CBaseEntity *); // eax
  CEntInfo *v7; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity *v9; // esi
  IVEngineServer_vtbl *v10; // edi
  int v11; // eax
  CBaseEntity_vtbl *v12; // eax
  CBaseEntity **v13; // ecx
  CPointCamera *v14; // esi
  int nNext; // [esp+8h] [ebp-4h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  for ( i = GetPointCameraList(); i != nullptr; i = i->m_pNext )
    CPointCamera::SetActive(this: i, bActive: false);
  m_Head = (CBaseEntity **)g_InfoCameraLinkList.m_Head;
  if ( g_InfoCameraLinkList.m_Head != 0 )
  {
    do
    {
      nNext = (int)m_Head[2];
      m_pfnMoveDone = (*m_Head)[1].m_pfnMoveDone;
      if ( m_pfnMoveDone != (void (__thiscall *)(CBaseEntity *))-1
        && (v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pfnMoveDone],
            g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pfnMoveDone].m_SerialNumber == (unsigned int)m_pfnMoveDone >> 16)
        && (m_pEntity = v7->m_pEntity, v7->m_pEntity != nullptr) )
      {
        if ( ((int)m_pEntity[41].__vftable & 0x20) == 0 )
        {
          v9 = m_pEntity + 3;
          if ( CServerNetworkProperty::IsInPVS(
                 this: (CServerNetworkProperty *)&m_pEntity[3],
                 pRecipient: pPlayer->m_Network.m_pPev,
                 pvs,
                 pvssize) )
          {
            v10 = engine->__vftable;
            v11 = (int)v9->__vftable[1].GetRefEHandle(this: v9);
            if ( v10->CheckAreasConnected(this: engine, a2: area, a3: v11) != 0 )
            {
              v12 = (*m_Head)[1].__vftable;
              if ( v12 != (CBaseEntity_vtbl *)-1 )
              {
                v13 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v12];
                if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == (unsigned int)v12 >> 16 )
                {
                  v14 = (CPointCamera *)*v13;
                  if ( *v13 != nullptr )
                  {
                    if ( (v14->m_iEFlags & 0x800) != 0 )
                      CBaseEntity::CalcAbsolutePosition(this: *v13, a2: (int)&savedregs);
                    engine->AddOriginToPVS(this: engine, a2: &v14->m_vecAbsOrigin);
                    CPointCamera::SetActive(this: v14, bActive: true);
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        UTIL_Remove(oldObj: *m_Head);
      }
      m_Head = (CBaseEntity **)nNext;
    }
    while ( nNext != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101621C0
// Name: public: virtual void CInfoCameraLink::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoCameraLink::Activate(CInfoCameraLink *this)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  unsigned int v4; // eax
  const char *v5; // eax
  CBasePlayer *EntityByName; // eax

  CBaseEntity::Activate(this);
  m_Index = this->m_hCamera.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    pszValue = this->m_strPointCamera.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CInfoCameraLink::SetCameraByName(this, szName: pszValue);
  }
  v4 = this->m_hTargetEntity.m_Index;
  if ( v4 == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity == nullptr )
  {
    v5 = this->m_target.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: v5,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
      this->m_hTargetEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
    else
      this->m_hTargetEntity.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104053E0
// Name: CInfoCameraLink_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CInfoCameraLink_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CInfoCameraLink>();
  CInfoCameraLink_DataDescInit::g_DataMapHolder = result;
  return result;
}
