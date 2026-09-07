// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/vguiscreen.cpp
// Functions: 34
// ============================================================

#include "game\server\vguiscreen.h"

//------------------------------------------------------------------------------
// Address: 0x1025C160
// Name: public: virtual class ServerClass __near * CVGuiScreen::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CVGuiScreen::GetServerClass(CVGuiScreen *this)
{
  return &g_CVGuiScreen_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1025C170
// Name: public: virtual void vgui_screenPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui_screenPrecache::CResourcePrecacher::Cache(
        vgui_screenPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "vgui_screen",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1025C1A0
// Name: public: virtual struct datamap_t __near * CVGuiScreen::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CVGuiScreen::GetDataDescMap(CVGuiScreen *this)
{
  return &CVGuiScreen::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1025C1B0
// Name: public: virtual void CVGuiScreen::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::OnRestore(CVGuiScreen *this)
{
  CBaseEntity::DispatchUpdateTransmitState(this);
  CBaseEntity::OnRestore(this);
}

//------------------------------------------------------------------------------
// Address: 0x1025C1C0
// Name: void DestroyVGuiScreen(class CVGuiScreen __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyVGuiScreen(CVGuiScreen *pVGuiScreen)
{
  if ( pVGuiScreen != nullptr )
    UTIL_Remove(oldObj: pVGuiScreen);
}

//------------------------------------------------------------------------------
// Address: 0x1025C1E0
// Name: public: virtual void CVGuiScreen::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::Precache(CVGuiScreen *this)
{
  if ( this->m_strOverlayMaterial.pszValue != nullptr )
    PrecacheMaterial(pMaterialName: this->m_strOverlayMaterial.pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x1025C200
// Name: public: char const __near * CVGuiScreen::GetPanelName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVGuiScreen::GetPanelName(CVGuiScreen *this)
{
  return g_pStringTableVguiScreen->GetString(this: g_pStringTableVguiScreen, a2: this->m_nPanelName.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x1025C220
// Name: void PrecacheVGuiScreen(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheVGuiScreen(const char *pScreenType)
{
  g_pStringTableVguiScreen->AddString(this: g_pStringTableVguiScreen, a2: true, a3: pScreenType, a4: -1, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1025C3F0
// Name: public: virtual int CVGuiScreen::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVGuiScreen::UpdateTransmitState(CVGuiScreen *this)
{
  unsigned int m_Index; // edx

  if ( (this->m_fScreenFlags.m_Value & 4) != 0 )
    return CBaseEntity::SetTransmitState(this, nFlag: 0);
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    return CBaseEntity::SetTransmitState(this, nFlag: 32);
  }
  else
  {
    return CBaseEntity::UpdateTransmitState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C440
// Name: public: virtual int CVGuiScreen::ShouldTransmit(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVGuiScreen::ShouldTransmit(CVGuiScreen *this, const CCheckTransmitInfo *pInfo)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return ((int (__thiscall *)(IHandleEntity *, const CCheckTransmitInfo *))m_pEntity->__vftable[6].GetRefEHandle)(
             a1: m_pEntity,
             a2: pInfo);
  }
  else
  {
    return CBaseEntity::ShouldTransmit(this, pInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C490
// Name: public: void CVGuiScreen::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::SetActive(CVGuiScreen *this, bool bActive)
{
  CNetworkVarBase<int,CVGuiScreen::NetworkVar_m_fScreenFlags> *p_m_fScreenFlags; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_fScreenFlags = &this->m_fScreenFlags;
  if ( bActive != (this->m_fScreenFlags.m_Value & 1) )
  {
    v3 = bActive ? p_m_fScreenFlags->m_Value | 1 : p_m_fScreenFlags->m_Value & 0xFFFFFFFE;
    if ( p_m_fScreenFlags->m_Value != v3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_fScreenFlags->m_Value = v3;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
        p_m_fScreenFlags->m_Value = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C500
// Name: public: void CVGuiScreen::SetAttachedToViewModel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::SetAttachedToViewModel(CVGuiScreen *this, bool bAttached)
{
  unsigned int v3; // edi
  edict_t *v4; // ecx
  int v5; // edi
  edict_t *m_pPev; // ecx

  if ( bAttached == (this->m_fScreenFlags.m_Value & 1) )
    return;
  if ( bAttached )
  {
    v5 = this->m_fScreenFlags.m_Value | 4;
    if ( this->m_fScreenFlags.m_Value != v5 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      }
      this->m_fScreenFlags.m_Value = v5;
    }
    CBaseEntity::DispatchUpdateTransmitState(this);
    goto LABEL_16;
  }
  v3 = this->m_fScreenFlags.m_Value & 0xFFFFFFFB;
  if ( this->m_fScreenFlags.m_Value == v3 )
  {
LABEL_16:
    CBaseEntity::DispatchUpdateTransmitState(this);
    return;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    this->m_fScreenFlags.m_Value = v3;
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
  else
  {
    v4 = this->m_Network.m_pPev;
    if ( v4 != nullptr )
      CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x370u);
    this->m_fScreenFlags.m_Value = v3;
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C5D0
// Name: public: void CVGuiScreen::SetTransparency(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::SetTransparency(CVGuiScreen *this, bool bTransparent)
{
  CNetworkVarBase<int,CVGuiScreen::NetworkVar_m_fScreenFlags> *p_m_fScreenFlags; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_fScreenFlags = &this->m_fScreenFlags;
  if ( bTransparent )
    v3 = p_m_fScreenFlags->m_Value | 8;
  else
    v3 = p_m_fScreenFlags->m_Value & 0xFFFFFFF7;
  if ( p_m_fScreenFlags->m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fScreenFlags->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      p_m_fScreenFlags->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C630
// Name: private: void CVGuiScreen::InputSetActive(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::InputSetActive(CVGuiScreen *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CVGuiScreen::NetworkVar_m_fScreenFlags> *p_m_fScreenFlags; // esi
  int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_fScreenFlags = &this->m_fScreenFlags;
  if ( (this->m_fScreenFlags.m_Value & 1) == 0 )
  {
    v3 = p_m_fScreenFlags->m_Value | 1;
    if ( p_m_fScreenFlags->m_Value != v3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_fScreenFlags->m_Value = v3;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
        p_m_fScreenFlags->m_Value = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C680
// Name: private: void CVGuiScreen::InputSetInactive(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::InputSetInactive(CVGuiScreen *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CVGuiScreen::NetworkVar_m_fScreenFlags> *p_m_fScreenFlags; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_fScreenFlags = &this->m_fScreenFlags;
  if ( (this->m_fScreenFlags.m_Value & 1) != 0 )
  {
    v3 = p_m_fScreenFlags->m_Value & 0xFFFFFFFE;
    if ( p_m_fScreenFlags->m_Value != v3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_fScreenFlags->m_Value = v3;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
        p_m_fScreenFlags->m_Value = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C6D0
// Name: public: void CVGuiScreen::MakeVisibleOnlyToTeammates(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::MakeVisibleOnlyToTeammates(CVGuiScreen *this, bool bActive)
{
  int m_Value; // eax
  CNetworkVarBase<int,CVGuiScreen::NetworkVar_m_fScreenFlags> *p_m_fScreenFlags; // esi
  unsigned int v4; // edi
  bool v5; // zf
  edict_t *m_pPev; // ecx

  m_Value = this->m_fScreenFlags.m_Value;
  p_m_fScreenFlags = &this->m_fScreenFlags;
  if ( bActive != ((m_Value & 2) != 0) )
  {
    if ( bActive )
    {
      v4 = m_Value | 2;
      v5 = p_m_fScreenFlags->m_Value == (m_Value | 2);
    }
    else
    {
      v4 = m_Value & 0xFFFFFFFD;
      v5 = m_Value == (m_Value & 0xFFFFFFFD);
    }
    if ( !v5 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_fScreenFlags->m_Value = v4;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
        p_m_fScreenFlags->m_Value = v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C740
// Name: public: CVGuiScreen::CVGuiScreen(void)
// Source: json
//------------------------------------------------------------------------------
CVGuiScreen *__thiscall CVGuiScreen::CVGuiScreen(CVGuiScreen *this)
{
  edict_t *m_pPev; // ecx
  IHandleEntity *m_pEntity; // edi
  unsigned int m_Index; // eax
  IHandleEntity *v5; // ecx
  CVGuiScreen *result; // eax
  edict_t *v7; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CVGuiScreen_vtbl *)&CVGuiScreen::`vftable';
  this->m_hPlayerOwner.m_Value.m_Index = -1;
  if ( this->m_nOverlayMaterial.m_Value != 1023 )
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
    this->m_nOverlayMaterial.m_Value = 1023;
  }
  if ( g_pEntityList->m_EntPtrArray[0].m_SerialNumber != 0 )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[0].m_pEntity;
  m_Index = this->m_hPlayerOwner.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    v5 = nullptr;
  else
    v5 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  result = this;
  if ( v5 != m_pEntity )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x374u);
    }
    this->m_hPlayerOwner.m_Value.m_Index = 0;
    result = this;
  }
  this->m_bIsTransparent = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025C810
// Name: public: void CVGuiScreen::SetOverlayMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::SetOverlayMaterial(CVGuiScreen *this, const char *pMaterial)
{
  int MaterialIndex; // eax
  int v4; // edi
  edict_t *v5; // ecx
  edict_t *m_pPev; // ecx

  MaterialIndex = GetMaterialIndex(pMaterialName: pMaterial);
  v4 = MaterialIndex;
  if ( MaterialIndex != 0 )
  {
    if ( this->m_nOverlayMaterial.m_Value != MaterialIndex )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_nOverlayMaterial.m_Value = MaterialIndex;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
        this->m_nOverlayMaterial.m_Value = v4;
      }
    }
  }
  else if ( this->m_nOverlayMaterial.m_Value != 1023 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nOverlayMaterial.m_Value = 1023;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x36Cu);
      this->m_nOverlayMaterial.m_Value = 1023;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C8C0
// Name: private: void CVGuiScreen::SetPanelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::SetPanelName(CVGuiScreen *this, const char *pPanelName)
{
  int v3; // edi
  edict_t *m_pPev; // ecx

  v3 = g_pStringTableVguiScreen->AddString(
         this: g_pStringTableVguiScreen,
         a2: true,
         a3: pPanelName,
         a4: -1,
         a5: nullptr);
  if ( this->m_nPanelName.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nPanelName.m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
      this->m_nPanelName.m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025C930
// Name: public: void CVGuiScreen::SetActualSize(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::SetActualSize(CVGuiScreen *this, float flWidth, float flHeight)
{
  float v3; // xmm1_4
  edict_t *m_pPev; // ecx
  float v6; // xmm2_4
  edict_t *v7; // ecx
  Vector mins; // [esp+0h] [ebp-18h] BYREF
  Vector maxs; // [esp+Ch] [ebp-Ch] BYREF

  v3 = flWidth;
  if ( this->m_flWidth.m_Value != flWidth )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
        v3 = flWidth;
      }
    }
    this->m_flWidth.m_Value = v3;
  }
  v6 = flHeight;
  if ( this->m_flHeight.m_Value != flHeight )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x360u);
        v6 = flHeight;
        v3 = flWidth;
      }
    }
    this->m_flHeight.m_Value = v6;
  }
  mins.z = -0.1;
  mins.x = 0.0;
  mins.y = 0.0;
  maxs.x = 0.0;
  maxs.y = 0.0;
  maxs.z = 0.1;
  if ( v3 <= 0.0 )
    mins.x = v3;
  else
    maxs.x = v3;
  if ( v6 <= 0.0 )
    mins.y = v6;
  else
    maxs.y = v6;
  UTIL_SetSize(pEnt: this, vecMin: &mins, vecMax: &maxs);
}

//------------------------------------------------------------------------------
// Address: 0x1025CA40
// Name: class CVGuiScreen __near * CreateVGuiScreen(char const __near *,char const __near *,class CBaseEntity __near *,class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
CVGuiScreen *__cdecl CreateVGuiScreen(
        const char *pScreenClassname,
        const char *pScreenType,
        CBaseEntity *pAttachedTo,
        CBaseEntity *pOwner,
        CBaseEntity *nAttachmentIndex)
{
  CBaseEntity *v5; // esi
  int v6; // ebx
  CBaseEdict *v7; // ecx
  CVGuiScreen *result; // eax
  CBaseEdict *v9; // ecx

  v5 = CBaseEntity::Create(
         szName: pScreenClassname,
         vecOrigin: &vec3_origin,
         vecAngles: &vec3_angle,
         pOwner: pAttachedTo);
  v6 = g_pStringTableVguiScreen->AddString(
         this: g_pStringTableVguiScreen,
         a2: true,
         a3: pScreenType,
         a4: -1,
         a5: nullptr);
  if ( v5[1].m_Network.__vftable != (IEventRegisterCallback_vtbl *)v6 )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x364u);
    }
    v5[1].m_Network.__vftable = (IEventRegisterCallback_vtbl *)v6;
  }
  CBaseEntity::FollowEntity(this: v5, pBaseEntity: pAttachedTo, bBoneMerge: true);
  v5->SetOwnerEntity(this: v5, a2: pOwner);
  result = (CVGuiScreen *)v5;
  if ( v5[1].m_Network.m_pOuter != nAttachmentIndex )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
      v5[1].m_Network.m_pOuter = nAttachmentIndex;
    }
    else
    {
      v9 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: v9, offset: 0x368u);
      v5[1].m_Network.m_pOuter = nAttachmentIndex;
      return (CVGuiScreen *)v5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025CB10
// Name: public: virtual bool CVGuiScreen::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVGuiScreen::KeyValue(CVGuiScreen *this, char *szKeyName, const char *szValue)
{
  _BYTE *v4; // eax
  VMatrix tmp; // [esp+Ch] [ebp-D8h] BYREF
  VMatrix mat; // [esp+4Ch] [ebp-98h] BYREF
  VMatrix rotation; // [esp+8Ch] [ebp-58h] BYREF
  QAngle angles; // [esp+CCh] [ebp-18h] BYREF
  Vector vAxisOfRot; // [esp+D8h] [ebp-Ch] BYREF

  strchr(string: szKeyName, chr: 0x23u);
  if ( v4 != nullptr )
    *v4 = 0;
  if ( szKeyName != "panelname" && _V_stricmp(s1: szKeyName, s2: "panelname") != 0 )
  {
    if ( szKeyName != "angles" && _V_stricmp(s1: szKeyName, s2: "angles") != 0 )
    {
      return CBaseEntity::KeyValue(this, szKeyName, szValue);
    }
    else
    {
      UTIL_StringToVector(pVector: &angles.x, pString: szValue);
      MatrixFromAngles(vAngles: &angles, dst: &mat);
      vAxisOfRot.x = 0.0;
      vAxisOfRot.z = 0.0;
      vAxisOfRot.y = 1.0;
      MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
      MatrixMultiply(src1: &mat, src2: &rotation, dst: &tmp);
      MatrixBuildRotateZ(dst: &rotation, angleDegrees: 90.0);
      MatrixMultiply(src1: &tmp, src2: &rotation, dst: &mat);
      MatrixAngles(a1: (int)szKeyName, src: &mat, vAngles: &angles);
      CBaseEntity::SetAbsAngles(this, absAngles: &angles);
      return true;
    }
  }
  else
  {
    CVGuiScreen::SetPanelName(this, pPanelName: szValue);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025CC60
// Name: public: virtual void CVGuiScreen::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::Spawn(CVGuiScreen *this)
{
  edict_t *m_pPev; // ecx
  CNetworkVarBase<int,CVGuiScreen::NetworkVar_m_fScreenFlags> *p_m_fScreenFlags; // edi
  edict_t *v4; // ecx
  unsigned int v5; // esi
  CNetworkVarBase<int,CVGuiScreen::NetworkVar_m_fScreenFlags> *v6; // eax
  CBaseEdict *m_Value; // ecx

  this->Precache(this);
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  if ( this->m_nAttachmentIndex.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x368u);
    }
    this->m_nAttachmentIndex.m_Value = 0;
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_OBB);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CVGuiScreen::SetActualSize(this, flWidth: this->m_flWidth.m_Value, flHeight: this->m_flHeight.m_Value);
  p_m_fScreenFlags = &this->m_fScreenFlags;
  if ( this->m_fScreenFlags.m_Value != 1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x370u);
    }
    p_m_fScreenFlags->m_Value = 1;
  }
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  CBaseEntity::AddFlag(this, flags: 0x10000);
  if ( this->m_bIsTransparent )
    v5 = p_m_fScreenFlags->m_Value | 8;
  else
    v5 = p_m_fScreenFlags->m_Value & 0xFFFFFFF7;
  if ( p_m_fScreenFlags->m_Value != v5 )
  {
    v6 = p_m_fScreenFlags - 220;
    if ( LOBYTE(p_m_fScreenFlags[-199].m_Value) != 0 )
    {
      LOBYTE(v6[22].m_Value) |= 1u;
      p_m_fScreenFlags->m_Value = v5;
    }
    else
    {
      m_Value = (CBaseEdict *)v6[6].m_Value;
      if ( m_Value != nullptr )
        CBaseEdict::StateChanged(this: m_Value, offset: 0x370u);
      p_m_fScreenFlags->m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025CDC0
// Name: public: virtual void CVGuiScreen::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreen::Activate(CVGuiScreen *this)
{
  CBaseEntity::Activate(this);
  if ( this->m_nOverlayMaterial.m_Value == 1023 && this->m_strOverlayMaterial.pszValue != nullptr )
    CVGuiScreen::SetOverlayMaterial(this, pMaterial: this->m_strOverlayMaterial.pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x1040C950
// Name: DT_VGuiScreen::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_VGuiScreen::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_VGuiScreen::g_SendTable);
  return atexit(func: DT_VGuiScreen::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C970
// Name: DT_VGuiScreen::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_VGuiScreen::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_VGuiScreen::ignored>();
  DT_VGuiScreen::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C9C0
// Name: vgui_screenPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int vgui_screenPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  vgui_screenPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&vgui_screenPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C9E0
// Name: CVGuiScreen_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CVGuiScreen_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CVGuiScreen>();
  CVGuiScreen_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041EF60
// Name: DT_VGuiScreen::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_VGuiScreen::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_VGuiScreen::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040C9F0
// Name: _dynamic_initializer_for__g_BanMasks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBitVec<64> *dynamic_initializer_for__g_BanMasks__()
{
  CBitVec<64> *result; // eax
  int i; // ecx

  result = g_BanMasks;
  for ( i = 63; i >= 0; --i )
  {
    if ( result != nullptr )
      *result = 0;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040CA20
// Name: _dynamic_initializer_for__g_SentGameRulesMasks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBitVec<64> *dynamic_initializer_for__g_SentGameRulesMasks__()
{
  CBitVec<64> *result; // eax
  int i; // ecx

  result = g_SentGameRulesMasks;
  for ( i = 63; i >= 0; --i )
  {
    if ( result != nullptr )
      *result = 0;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040CA50
// Name: _dynamic_initializer_for__g_SentBanMasks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBitVec<64> *dynamic_initializer_for__g_SentBanMasks__()
{
  CBitVec<64> *result; // eax
  int i; // ecx

  result = g_SentBanMasks;
  for ( i = 63; i >= 0; --i )
  {
    if ( result != nullptr )
      *result = 0;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041EF70
// Name: _ServerClassInit_DT_VGuiScreen::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_VGuiScreen::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_233;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF90
// Name: _DataMapInit_CVGuiScreen__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CVGuiScreen__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_462);
}
