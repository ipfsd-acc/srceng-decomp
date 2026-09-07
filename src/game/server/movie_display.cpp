// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/movie_display.cpp
// Functions: 54
// ============================================================

#include "game\server\movie_display.h"

//------------------------------------------------------------------------------
// Address: 0x10174BB0
// Name: public: virtual struct datamap_t __near * CMovieDisplay::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMovieDisplay::GetDataDescMap(CMovieDisplay *this)
{
  return &CMovieDisplay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10174BC0
// Name: public: virtual class ServerClass __near * CMovieDisplay::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CMovieDisplay::GetServerClass(CMovieDisplay *this)
{
  return &g_CMovieDisplay_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10174BD0
// Name: public: virtual int CMovieDisplay::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMovieDisplay::UpdateTransmitState(CMovieDisplay *this)
{
  if ( !this->m_bDoFullTransmit )
    return CBaseEntity::SetTransmitState(this, nFlag: 0);
  this->m_bDoFullTransmit = false;
  return CBaseEntity::SetTransmitState(this, nFlag: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10174BF0
// Name: public: virtual bool CMovieDisplay::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMovieDisplay::KeyValue(CMovieDisplay *this, char *szKeyName, const char *szValue)
{
  VMatrix tmp; // [esp+Ch] [ebp-D8h] BYREF
  VMatrix mat; // [esp+4Ch] [ebp-98h] BYREF
  VMatrix rotation; // [esp+8Ch] [ebp-58h] BYREF
  QAngle angles; // [esp+CCh] [ebp-18h] BYREF
  Vector vAxisOfRot; // [esp+D8h] [ebp-Ch] BYREF

  if ( szKeyName != "angles" && _V_stricmp(s1: szKeyName, s2: "angles") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
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

//------------------------------------------------------------------------------
// Address: 0x10174D00
// Name: public: virtual void CMovieDisplay::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::Precache(CMovieDisplay *this)
{
  const char *pszValue; // eax
  CMovieDisplay::NetworkVar_m_szMovieFilename *p_m_szMovieFilename; // esi

  PrecacheVGuiScreen(pScreenType: "movie_display_screen");
  if ( this->m_bForcePrecache )
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    p_m_szMovieFilename = &this->m_szMovieFilename;
    DevMsg(a1: "Precaching vgui_movie_display %s with movie %s\n", pszValue, p_m_szMovieFilename->m_Value);
    PrecacheMovie(pMovieName: p_m_szMovieFilename->m_Value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174FA0
// Name: public: virtual CMovieDisplay::~CMovieDisplay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::~CMovieDisplay(CMovieDisplay *this)
{
  unsigned int m_Index; // ecx

  this->__vftable = (CMovieDisplay_vtbl *)&CMovieDisplay::`vftable';
  m_Index = this->m_hScreen.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    DestroyVGuiScreen(pVGuiScreen: nullptr);
    CBaseEntity::~CBaseEntity(this);
  }
  else
  {
    DestroyVGuiScreen(pVGuiScreen: (CVGuiScreen *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
    CBaseEntity::~CBaseEntity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175000
// Name: public: virtual void CMovieDisplay::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::SetTransmit(CMovieDisplay *this, CCheckTransmitInfo *pInfo, int bAlways)
{
  edict_t *m_pPev; // eax
  unsigned int m_Index; // eax

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseEntity::SetTransmit(this, pInfo, bAlways);
    m_Index = this->m_hScreen.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      (*(void (__stdcall **)(CCheckTransmitInfo *, int))(MEMORY[0] + 88))(a1: pInfo, a2: bAlways);
    else
      ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, int))g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity->__vftable[7].SetRefEHandle)(
        a1: g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity,
        a2: pInfo,
        a3: bAlways);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101750D0
// Name: public: void CMovieDisplay::InputSetDisplayText(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::InputSetDisplayText(CMovieDisplay *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // edi
  CMovieDisplay::NetworkVar_m_szDisplayText *p_m_szDisplayText; // esi
  CBaseEdict *v7; // ecx

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( iVal != nullptr )
      v5 = iVal;
    else
      v5 = locale;
  }
  else
  {
    v5 = variant_t::ToString(this: p_value);
  }
  p_m_szDisplayText = &this->m_szDisplayText;
  if ( p_m_szDisplayText[-7].m_Value[104] != 0 )
  {
    p_m_szDisplayText[-7].m_Value[108] |= 1u;
    _V_strcpy(dest: p_m_szDisplayText->m_Value, src: v5);
  }
  else
  {
    v7 = *(CBaseEdict **)&p_m_szDisplayText[-7].m_Value[44];
    if ( v7 != nullptr )
    {
      v7->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v7)->m_iChangeInfoSerialNumber = 0;
    }
    _V_strcpy(dest: p_m_szDisplayText->m_Value, src: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175150
// Name: public: void CMovieDisplay::InputSetMovie(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::InputSetMovie(CMovieDisplay *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // edi
  CMovieDisplay::NetworkVar_m_szMovieFilename *p_m_szMovieFilename; // esi
  CBaseEdict *v7; // ecx

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( iVal != nullptr )
      v5 = iVal;
    else
      v5 = locale;
  }
  else
  {
    v5 = variant_t::ToString(this: p_value);
  }
  p_m_szMovieFilename = &this->m_szMovieFilename;
  if ( p_m_szMovieFilename[-8].m_Value[104] != 0 )
  {
    p_m_szMovieFilename[-8].m_Value[108] |= 1u;
  }
  else
  {
    v7 = *(CBaseEdict **)&p_m_szMovieFilename[-8].m_Value[44];
    if ( v7 != nullptr )
    {
      v7->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v7)->m_iChangeInfoSerialNumber = 0;
    }
  }
  V_strncpy(pDest: p_m_szMovieFilename->m_Value, pSrc: v5, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101751D0
// Name: private: void CMovieDisplay::SpawnControlPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::SpawnControlPanels(CMovieDisplay *this)
{
  CVGuiScreen *VGuiScreen; // esi
  CVGuiScreen_vtbl *v3; // ebx
  int TeamNumber; // eax
  float flWidth; // [esp+18h] [ebp-8h]
  float flHeight; // [esp+1Ch] [ebp-4h]

  flWidth = (float)this->m_iScreenWidth;
  flHeight = (float)this->m_iScreenHeight;
  VGuiScreen = CreateVGuiScreen(
                 pScreenClassname: "vgui_screen",
                 pScreenType: "movie_display_screen",
                 pAttachedTo: this,
                 pOwner: this,
                 nAttachmentIndex: 0);
  v3 = VGuiScreen->__vftable;
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  v3->ChangeTeam(this: VGuiScreen, a2: TeamNumber);
  CVGuiScreen::SetActualSize(this: VGuiScreen, flWidth, flHeight);
  CVGuiScreen::SetActive(this: VGuiScreen, bActive: true);
  CVGuiScreen::MakeVisibleOnlyToTeammates(this: VGuiScreen, bActive: false);
  CVGuiScreen::SetTransparency(this: VGuiScreen, bTransparent: true);
  this->m_hScreen.m_Index = VGuiScreen->GetRefEHandle(this: VGuiScreen)->m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10175280
// Name: private: void CMovieDisplay::RestoreControlPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::RestoreControlPanels(CMovieDisplay *this)
{
  CBaseEntity *i; // eax
  CVGuiScreen *v3; // esi
  unsigned int m_Index; // eax
  CMovieDisplay *m_pEntity; // ecx
  const char *PanelName; // eax
  unsigned int v7; // eax

  for ( i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "vgui_screen");
        ;
        i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: v3, szName: "vgui_screen") )
  {
    v3 = (CVGuiScreen *)i;
    if ( i != nullptr )
    {
      m_Index = i->m_hOwnerEntity.m_Value.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CMovieDisplay *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != this )
        continue;
    }
    PanelName = CVGuiScreen::GetPanelName(this: v3);
    if ( _V_strcmp(s1: PanelName, s2: "movie_display_screen") == 0 )
      break;
  }
  if ( v3 != nullptr )
  {
    v7 = v3->GetRefEHandle(this: v3)->m_Index;
    this->m_hScreen.m_Index = v7;
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      CVGuiScreen::SetActive(this: nullptr, bActive: true);
    else
      CVGuiScreen::SetActive(
        this: (CVGuiScreen *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity,
        bActive: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175390
// Name: public: void CMovieDisplay::InputSetUseCustomUVs(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::InputSetUseCustomUVs(CMovieDisplay *this, inputdata_t *inputdata)
{
  bool v2; // bl
  CNetworkVarBase<bool,CMovieDisplay::NetworkVar_m_bUseCustomUVs> *p_m_bUseCustomUVs; // esi
  edict_t *m_pPev; // ecx

  v2 = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
  p_m_bUseCustomUVs = &this->m_bUseCustomUVs;
  if ( this->m_bUseCustomUVs.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bUseCustomUVs->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x359u);
      p_m_bUseCustomUVs->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175570
// Name: public: void CMovieDisplay::ScreenVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::ScreenVisible(CMovieDisplay *this, bool bVisible)
{
  unsigned int m_Index; // eax
  CVGuiScreen *m_pEntity; // ecx
  unsigned int v5; // eax
  IHandleEntity *v6; // ebx
  IHandleEntity_vtbl *v7; // eax
  unsigned int v8; // edi
  CBaseEdict *v9; // ecx

  m_Index = this->m_hScreen.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CVGuiScreen *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CVGuiScreen::SetActive(this: m_pEntity, bActive: bVisible);
  v5 = this->m_hScreen.m_Index;
  if ( bVisible )
  {
    if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
      v6 = nullptr;
    else
      v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
    v7 = v6[41].__vftable;
    v8 = (unsigned int)v7 & 0xFFFFFFDF;
    if ( v7 != (IHandleEntity_vtbl *)((unsigned int)v7 & 0xFFFFFFDF) )
    {
      if ( LOBYTE(v6[21].__vftable) != 0 )
      {
        LOBYTE(v6[22].__vftable) |= 1u;
      }
      else
      {
        v9 = (CBaseEdict *)v6[6].__vftable;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: v9, offset: 0xA4u);
      }
      v6[41].__vftable = (IHandleEntity_vtbl *)v8;
    }
    if ( v6[6].__vftable != nullptr )
      v6[6].dtr_IHandleEntity = (void (__thiscall *)(IHandleEntity *))((int)v6[6].dtr_IHandleEntity | 0x80);
    CBaseEntity::DispatchUpdateTransmitState(this: (CBaseEntity *)v6);
  }
  else if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
  {
    CBaseEntity::AddEffects(this: nullptr, nEffects: 32);
  }
  else
  {
    CBaseEntity::AddEffects(
      this: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity,
      nEffects: 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175680
// Name: public: void CMovieDisplay::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::Enable(CMovieDisplay *this)
{
  edict_t *m_pPev; // ecx

  if ( !this->m_bEnabled.m_Value )
  {
    if ( !this->m_bEnabled.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bEnabled.m_Value = true;
        CMovieDisplay::ScreenVisible(this, bVisible: true);
        return;
      }
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      this->m_bEnabled.m_Value = true;
    }
    CMovieDisplay::ScreenVisible(this, bVisible: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101756E0
// Name: public: void CMovieDisplay::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::InputDisable(CMovieDisplay *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx

  if ( this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
    }
    this->m_bEnabled.m_Value = false;
    CMovieDisplay::ScreenVisible(this, bVisible: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175730
// Name: public: void CMovieDisplay::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMovieDisplay::InputEnable(CMovieDisplay *this, inputdata_t *inputdata)
{
  CMovieDisplay::Enable(this);
}

//------------------------------------------------------------------------------
// Address: 0x10175740
// Name: public: void CMovieDisplay::InputTakeOverAsMaster(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::InputTakeOverAsMaster(CMovieDisplay *this, inputdata_t *inputdata)
{
  CMovieDisplay::Enable(this);
  EntityMessageBegin(entity: this, reliable: 0);
  MessageWriteByte(iValue: 0);
  MessageEnd();
}

//------------------------------------------------------------------------------
// Address: 0x101757F0
// Name: public: virtual void CMovieDisplay::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::Spawn(CMovieDisplay *this)
{
  const char *pszValue; // ebx
  edict_t *m_pPev; // ecx
  const char *v4; // ebx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx

  pszValue = this->m_strMovieFilename.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  _V_strcpy(dest: this->m_szMovieFilename.m_Value, src: pszValue);
  v4 = this->m_strGroupName.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v5 = this->m_Network.m_pPev;
    if ( v5 != nullptr )
    {
      v5->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v5->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  _V_strcpy(dest: this->m_szGroupName.m_Value, src: v4);
  this->Precache(this);
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  if ( this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x354u);
    }
    this->m_bEnabled.m_Value = false;
  }
  CMovieDisplay::SpawnControlPanels(this);
  CMovieDisplay::ScreenVisible(this, bVisible: this->m_bEnabled.m_Value);
  this->m_bDoFullTransmit = true;
  if ( this->m_bUseCustomUVs.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x359u);
    }
    this->m_bUseCustomUVs.m_Value = false;
  }
  if ( this->m_flUMin.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x35Cu);
    }
    this->m_flUMin.m_Value = 0.0;
  }
  if ( this->m_flUMax.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x360u);
    }
    this->m_flUMax.m_Value = 1.0;
  }
  if ( this->m_flVMin.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x364u);
    }
    this->m_flVMin.m_Value = 0.0;
  }
  if ( this->m_flVMax.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flVMax.m_Value = 1.0;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x368u);
      this->m_flVMax.m_Value = 1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175A50
// Name: public: virtual void CMovieDisplay::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplay::OnRestore(CMovieDisplay *this)
{
  CBaseEntity::OnRestore(this);
  this->m_bDoFullTransmit = true;
  CMovieDisplay::RestoreControlPanels(this);
  CMovieDisplay::ScreenVisible(this, bVisible: this->m_bEnabled.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x104064F0
// Name: CMovieDisplay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMovieDisplay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMovieDisplay>(__formal: nullptr);
  CMovieDisplay_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406520
// Name: DT_MovieDisplay::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MovieDisplay::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_MovieDisplay::g_SendTable);
  return atexit(func: DT_MovieDisplay::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10406540
// Name: DT_MovieDisplay::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MovieDisplay::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_MovieDisplay::ignored>();
  DT_MovieDisplay::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C6A0
// Name: DT_MovieDisplay::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MovieDisplay::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_MovieDisplay::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10175770
// Name: struct datamap_t __near * DataMapInit<class CMovieDisplay>(class CMovieDisplay __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMovieDisplay>()
{
  if ( (_S2_156 & 1) == 0 )
  {
    _S2_156 |= 1u;
    nameHolder_283.m_pszBase = "CMovieDisplay";
    nameHolder_283.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_283.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_283.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_283.m_Names.m_Size = 0;
    nameHolder_283.m_Names.m_pElements = nullptr;
    nameHolder_283.m_nLenBase = 13;
    atexit(func: DataMapInit_CMovieDisplay__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMovieDisplay::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CMovieDisplay::m_DataMap.dataNumFields = 29;
  CMovieDisplay::m_DataMap.dataDesc = &dataDesc_270[1];
  return &CMovieDisplay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10406500
// Name: _dynamic_initializer_for__g_CMovieDisplay_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CMovieDisplay_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CMovieDisplay_ClassReg,
           pNetworkName: "CMovieDisplay",
           pTable: &DT_MovieDisplay::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10406550
// Name: _dynamic_initializer_for____g_GameRulesRegister_CMultiplayRules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameRulesRegister *dynamic_initializer_for____g_GameRulesRegister_CMultiplayRules__()
{
  return CGameRulesRegister::CGameRulesRegister(
           this: &_g_GameRulesRegister_CMultiplayRules,
           pClassName: "CMultiplayRules",
           fn: __CreateGameRules_CMultiplayRules);
}

//------------------------------------------------------------------------------
// Address: 0x10406570
// Name: _dynamic_initializer_for__mp_chattime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_chattime__()
{
  ConVar::ConVar(
    this: &mp_chattime,
    pName: "mp_chattime",
    pDefaultValue: "10",
    flags: 0x2000,
    pHelpString: "amount of time players can chat after the game is over",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 120.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_chattime__);
}

//------------------------------------------------------------------------------
// Address: 0x104065C0
// Name: _dynamic_initializer_for__mapcycledisabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mapcycledisabled__()
{
  ConVar::ConVar(
    this: &mapcycledisabled,
    pName: "mapcycledisabled",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "repeats the same map after each match instead of using the map cycle");
  return atexit(func: dynamic_atexit_destructor_for__mapcycledisabled__);
}

//------------------------------------------------------------------------------
// Address: 0x104065F0
// Name: _dynamic_initializer_for__mp_timelimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_timelimit__()
{
  ConVar::ConVar(
    this: &mp_timelimit,
    pName: "mp_timelimit",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "game time per map in minutes",
    callback: MPTimeLimitCallback);
  return atexit(func: dynamic_atexit_destructor_for__mp_timelimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10406620
// Name: _dynamic_initializer_for__fraglimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fraglimit__()
{
  ConVar::ConVar(
    this: &fraglimit,
    pName: "mp_fraglimit",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "The number of kills at which the map ends");
  return atexit(func: dynamic_atexit_destructor_for__fraglimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10406650
// Name: _dynamic_initializer_for__tv_delaymapchange__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tv_delaymapchange__()
{
  ConVar::ConVar(
    this: &tv_delaymapchange,
    pName: "tv_delaymapchange",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Delays map change until broadcast is complete");
  return atexit(func: dynamic_atexit_destructor_for__tv_delaymapchange__);
}

//------------------------------------------------------------------------------
// Address: 0x10406680
// Name: _dynamic_initializer_for__mp_restartgame__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_restartgame__()
{
  ConVar::ConVar(
    this: &mp_restartgame,
    pName: "mp_restartgame",
    pDefaultValue: "0",
    flags: 4,
    pHelpString: "If non-zero, game will restart in the specified number of seconds");
  return atexit(func: dynamic_atexit_destructor_for__mp_restartgame__);
}

//------------------------------------------------------------------------------
// Address: 0x104066B0
// Name: _dynamic_initializer_for__skip_next_map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__skip_next_map__()
{
  ConCommand::ConCommand(
    this: &skip_next_map,
    pName: "skip_next_map",
    callback: cc_SkipNextMapInCycle,
    pHelpString: "Skips the next map in the map rotation for the server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__skip_next_map__);
}

//------------------------------------------------------------------------------
// Address: 0x104066E0
// Name: _dynamic_initializer_for__mp_waitingforplayers_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_waitingforplayers_time__()
{
  ConVar::ConVar(
    this: &mp_waitingforplayers_time,
    pName: "mp_waitingforplayers_time",
    pDefaultValue: "0",
    flags: 4,
    pHelpString: "WaitingForPlayers time length in seconds");
  return atexit(func: dynamic_atexit_destructor_for__mp_waitingforplayers_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10406710
// Name: _dynamic_initializer_for__mp_waitingforplayers_restart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_waitingforplayers_restart__()
{
  ConVar::ConVar(
    this: &mp_waitingforplayers_restart,
    pName: "mp_waitingforplayers_restart",
    pDefaultValue: "0",
    flags: 4,
    pHelpString: "Set to 1 to start or restart the WaitingForPlayers period.");
  return atexit(func: dynamic_atexit_destructor_for__mp_waitingforplayers_restart__);
}

//------------------------------------------------------------------------------
// Address: 0x10406740
// Name: _dynamic_initializer_for__mp_waitingforplayers_cancel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_waitingforplayers_cancel__()
{
  ConVar::ConVar(
    this: &mp_waitingforplayers_cancel,
    pName: "mp_waitingforplayers_cancel",
    pDefaultValue: "0",
    flags: 4,
    pHelpString: "Set to 1 to end the WaitingForPlayers period.");
  return atexit(func: dynamic_atexit_destructor_for__mp_waitingforplayers_cancel__);
}

//------------------------------------------------------------------------------
// Address: 0x10406770
// Name: _dynamic_initializer_for__mp_clan_readyrestart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_clan_readyrestart__()
{
  ConVar::ConVar(
    this: &mp_clan_readyrestart,
    pName: "mp_clan_readyrestart",
    pDefaultValue: "0",
    flags: 4,
    pHelpString: "If non-zero, game will restart once someone from each team gives the ready signal");
  return atexit(func: dynamic_atexit_destructor_for__mp_clan_readyrestart__);
}

//------------------------------------------------------------------------------
// Address: 0x104067A0
// Name: _dynamic_initializer_for__mp_clan_ready_signal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_clan_ready_signal__()
{
  ConVar::ConVar(
    this: &mp_clan_ready_signal,
    pName: "mp_clan_ready_signal",
    pDefaultValue: "ready",
    flags: 4,
    pHelpString: "Text that team leader from each team must speak for the match to begin");
  return atexit(func: dynamic_atexit_destructor_for__mp_clan_ready_signal__);
}

//------------------------------------------------------------------------------
// Address: 0x104067D0
// Name: _dynamic_initializer_for__nextlevel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nextlevel__()
{
  ConVar::ConVar(
    this: &nextlevel,
    pName: "nextlevel",
    pDefaultValue: locale,
    flags: 260,
    pHelpString: "If set to a valid map name, will trigger a changelevel to the specified map at the end of the round");
  return atexit(func: dynamic_atexit_destructor_for__nextlevel__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C6B0
// Name: _ServerClassInit_DT_MovieDisplay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_MovieDisplay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_83;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041C6D0
// Name: _DataMapInit_CMovieDisplay__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMovieDisplay__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_283);
}

//------------------------------------------------------------------------------
// Address: 0x1041C6E0
// Name: _dynamic_atexit_destructor_for__mp_chattime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_chattime__()
{
  ConVar::~ConVar(this: &mp_chattime);
}

//------------------------------------------------------------------------------
// Address: 0x1041C6F0
// Name: _dynamic_atexit_destructor_for__mapcycledisabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mapcycledisabled__()
{
  ConVar::~ConVar(this: &mapcycledisabled);
}

//------------------------------------------------------------------------------
// Address: 0x1041C700
// Name: _dynamic_atexit_destructor_for__mp_timelimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_timelimit__()
{
  ConVar::~ConVar(this: &mp_timelimit);
}

//------------------------------------------------------------------------------
// Address: 0x1041C710
// Name: _dynamic_atexit_destructor_for__fraglimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fraglimit__()
{
  ConVar::~ConVar(this: &fraglimit);
}

//------------------------------------------------------------------------------
// Address: 0x1041C720
// Name: _dynamic_atexit_destructor_for__tv_delaymapchange__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tv_delaymapchange__()
{
  ConVar::~ConVar(this: &tv_delaymapchange);
}

//------------------------------------------------------------------------------
// Address: 0x1041C730
// Name: _dynamic_atexit_destructor_for__mp_restartgame__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_restartgame__()
{
  ConVar::~ConVar(this: &mp_restartgame);
}

//------------------------------------------------------------------------------
// Address: 0x1041C740
// Name: _dynamic_atexit_destructor_for__skip_next_map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__skip_next_map__()
{
  ConCommand::~ConCommand(this: &skip_next_map);
}

//------------------------------------------------------------------------------
// Address: 0x1041C750
// Name: _dynamic_atexit_destructor_for__mp_waitingforplayers_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_waitingforplayers_time__()
{
  ConVar::~ConVar(this: &mp_waitingforplayers_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041C760
// Name: _dynamic_atexit_destructor_for__mp_waitingforplayers_restart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_waitingforplayers_restart__()
{
  ConVar::~ConVar(this: &mp_waitingforplayers_restart);
}

//------------------------------------------------------------------------------
// Address: 0x1041C770
// Name: _dynamic_atexit_destructor_for__mp_waitingforplayers_cancel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_waitingforplayers_cancel__()
{
  ConVar::~ConVar(this: &mp_waitingforplayers_cancel);
}

//------------------------------------------------------------------------------
// Address: 0x1041C780
// Name: _dynamic_atexit_destructor_for__mp_clan_readyrestart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_clan_readyrestart__()
{
  ConVar::~ConVar(this: &mp_clan_readyrestart);
}

//------------------------------------------------------------------------------
// Address: 0x1041C790
// Name: _dynamic_atexit_destructor_for__mp_clan_ready_signal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_clan_ready_signal__()
{
  ConVar::~ConVar(this: &mp_clan_ready_signal);
}

//------------------------------------------------------------------------------
// Address: 0x1041C7A0
// Name: _dynamic_atexit_destructor_for__nextlevel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nextlevel__()
{
  ConVar::~ConVar(this: &nextlevel);
}
