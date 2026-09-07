// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/slideshow_display.cpp
// Functions: 62
// ============================================================

#include "game\server\slideshow_display.h"

//------------------------------------------------------------------------------
// Address: 0x102142D0
// Name: public: virtual struct datamap_t __near * CSlideshowDisplay::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSlideshowDisplay::GetDataDescMap(CSlideshowDisplay *this)
{
  return &CSlideshowDisplay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102142E0
// Name: public: virtual class ServerClass __near * CSlideshowDisplay::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSlideshowDisplay::GetServerClass(CSlideshowDisplay *this)
{
  return &g_CSlideshowDisplay_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102142F0
// Name: public: virtual int CSlideshowDisplay::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSlideshowDisplay::UpdateTransmitState(CSlideshowDisplay *this)
{
  if ( !this->m_bDoFullTransmit )
    return CBaseEntity::SetTransmitState(this, nFlag: 0);
  this->m_bDoFullTransmit = false;
  return CBaseEntity::SetTransmitState(this, nFlag: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10214310
// Name: public: virtual bool CSlideshowDisplay::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSlideshowDisplay::KeyValue(CSlideshowDisplay *this, char *szKeyName, const char *szValue)
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
// Address: 0x10214630
// Name: public: virtual void CSlideshowDisplay::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::SetTransmit(CSlideshowDisplay *this, CCheckTransmitInfo *pInfo, int bAlways)
{
  edict_t *m_pPev; // eax
  int i; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseEntity::SetTransmit(this, pInfo, bAlways);
    for ( i = 0; i < this->m_hScreens.m_Size; ++i )
    {
      m_Index = this->m_hScreens.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, int))m_pEntity->__vftable[7].SetRefEHandle)(
        a1: m_pEntity,
        a2: pInfo,
        a3: bAlways);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102146D0
// Name: public: void CSlideshowDisplay::InputRemoveAllSlides(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::InputRemoveAllSlides(CSlideshowDisplay *this, inputdata_t *inputdata)
{
  CSlideshowDisplay::NetworkVar_m_chCurrentSlideLists *p_m_chCurrentSlideLists; // ebx
  int i; // esi
  edict_t *m_pPev; // ecx

  p_m_chCurrentSlideLists = &this->m_chCurrentSlideLists;
  for ( i = 0; i < 16; ++i )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: i + (_WORD)p_m_chCurrentSlideLists - (_WORD)this);
    }
    p_m_chCurrentSlideLists->m_Value[i] = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214710
// Name: public: void CSlideshowDisplay::InputAddSlides(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::InputAddSlides(CSlideshowDisplay *this, inputdata_t *inputdata)
{
  int v3; // ebx
  const char *pszValue; // eax
  int v5; // esi
  edict_t *m_pPev; // ecx

  v3 = 0;
  if ( this->m_SlideKeywordList.m_Size > 0 )
  {
    do
    {
      if ( inputdata->value.fieldType == FIELD_STRING )
      {
        pszValue = inputdata->value.iszVal.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
      }
      else
      {
        pszValue = variant_t::ToString(this: &inputdata->value);
      }
      if ( _V_strcmp(s1: this->m_SlideKeywordList.m_Memory.m_pMemory[v3]->szSlideKeyword, s2: pszValue) == 0 )
        break;
      ++v3;
    }
    while ( v3 < this->m_SlideKeywordList.m_Size );
    if ( v3 < this->m_SlideKeywordList.m_Size )
    {
      v5 = 0;
      while ( this->m_chCurrentSlideLists.m_Value[v5] != 0xFF )
      {
        if ( ++v5 >= 16 )
          return;
      }
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_chCurrentSlideLists.m_Value[v5] = v3;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: v5 + 1136);
        this->m_chCurrentSlideLists.m_Value[v5] = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102147E0
// Name: public: void CSlideshowDisplay::InputSetDisplayText(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::InputSetDisplayText(CSlideshowDisplay *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // edi
  CSlideshowDisplay::NetworkVar_m_szDisplayText *p_m_szDisplayText; // esi
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
  if ( p_m_szDisplayText[-7].m_Value[127] != 0 )
  {
    p_m_szDisplayText[-6].m_Value[3] |= 1u;
    _V_strcpy(dest: p_m_szDisplayText->m_Value, src: v5);
  }
  else
  {
    v7 = *(CBaseEdict **)&p_m_szDisplayText[-7].m_Value[67];
    if ( v7 != nullptr )
    {
      v7->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v7)->m_iChangeInfoSerialNumber = 0;
    }
    _V_strcpy(dest: p_m_szDisplayText->m_Value, src: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214860
// Name: public: void CSlideshowDisplay::InputSetMaxSlideTime(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::InputSetMaxSlideTime(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvProjectedTexture::NetworkVar_m_flFarZ> *p_m_flFarZ; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flFarZ = &this->m_flFarZ;
  if ( this->m_flFarZ.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flFarZ->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x484u);
      p_m_flFarZ->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102148E0
// Name: public: void CSlideshowDisplay::InputSetCycleType(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::InputSetCycleType(CSlideshowDisplay *this, inputdata_t *inputdata)
{
  const char *pszValue; // edi
  CNetworkVarBase<int,CSlideshowDisplay::NetworkVar_m_iCycleType> *p_m_iCycleType; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_iCycleType = &this->m_iCycleType;
  if ( (const char *)this->m_iCycleType.m_Value != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iCycleType->m_Value = (int)pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x488u);
      p_m_iCycleType->m_Value = (int)pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214940
// Name: public: void CSlideshowDisplay::InputSetNoListRepeats(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::InputSetNoListRepeats(CSlideshowDisplay *this, inputdata_t *inputdata)
{
  bool v2; // bl
  CNetworkVarBase<bool,CSlideshowDisplay::NetworkVar_m_bNoListRepeats> *p_m_bNoListRepeats; // esi
  edict_t *m_pPev; // ecx

  v2 = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
  p_m_bNoListRepeats = &this->m_bNoListRepeats;
  if ( this->m_bNoListRepeats.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bNoListRepeats->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x48Cu);
      p_m_bNoListRepeats->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102149A0
// Name: public: CSlideshowDisplay::CSlideshowDisplay(void)
// Source: json
//------------------------------------------------------------------------------
CSlideshowDisplay *__thiscall CSlideshowDisplay::CSlideshowDisplay(CSlideshowDisplay *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CSlideshowDisplay_vtbl *)&CSlideshowDisplay::`vftable';
  this->m_SlideKeywordList.m_Memory.m_pMemory = nullptr;
  this->m_SlideKeywordList.m_Memory.m_nAllocationCount = 0;
  this->m_SlideKeywordList.m_Memory.m_nGrowSize = 0;
  this->m_SlideKeywordList.m_Size = 0;
  this->m_SlideKeywordList.m_pElements = nullptr;
  this->m_hScreens.m_Memory.m_pMemory = nullptr;
  this->m_hScreens.m_Memory.m_nAllocationCount = 0;
  this->m_hScreens.m_Memory.m_nGrowSize = 0;
  this->m_hScreens.m_Size = 0;
  this->m_hScreens.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10214A00
// Name: public: virtual CSlideshowDisplay::~CSlideshowDisplay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::~CSlideshowDisplay(CSlideshowDisplay *this)
{
  int v2; // esi
  unsigned int m_Index; // eax
  CVGuiScreen *m_pEntity; // ecx

  v2 = this->m_hScreens.m_Size - 1;
  for ( this->__vftable = (CSlideshowDisplay_vtbl *)&CSlideshowDisplay::`vftable'; v2 >= 0; --v2 )
  {
    m_Index = this->m_hScreens.m_Memory.m_pMemory[v2].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CVGuiScreen *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    DestroyVGuiScreen(pVGuiScreen: m_pEntity);
  }
  this->m_hScreens.m_Size = 0;
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hScreens);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SlideKeywordList);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10214AB0
// Name: public: void CSlideshowDisplay::ScreenVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::ScreenVisible(CSlideshowDisplay *this, bool bVisible)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ebx
  unsigned int v4; // esi
  CBaseEdict *v5; // ecx
  CSlideshowDisplay *v6; // [esp+0h] [ebp-8h]
  int iScreen; // [esp+4h] [ebp-4h]

  v6 = this;
  for ( iScreen = 0; iScreen < v6->m_hScreens.m_Size; ++iScreen )
  {
    m_Index = this->m_hScreens.m_Memory.m_pMemory[iScreen].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( bVisible )
    {
      v4 = (int)m_pEntity[41].__vftable & 0xFFFFFFDF;
      if ( m_pEntity[41].__vftable != (IHandleEntity_vtbl *)v4 )
      {
        if ( LOBYTE(m_pEntity[21].__vftable) != 0 )
        {
          LOBYTE(m_pEntity[22].__vftable) |= 1u;
        }
        else
        {
          v5 = (CBaseEdict *)m_pEntity[6].__vftable;
          if ( v5 != nullptr )
            CBaseEdict::StateChanged(this: v5, offset: 0xA4u);
        }
        m_pEntity[41].__vftable = (IHandleEntity_vtbl *)v4;
      }
      if ( m_pEntity[6].__vftable != nullptr )
        m_pEntity[6].dtr_IHandleEntity = (void (__thiscall *)(IHandleEntity *))((int)m_pEntity[6].dtr_IHandleEntity
                                                                              | 0x80);
      CBaseEntity::DispatchUpdateTransmitState(this: (CBaseEntity *)m_pEntity);
    }
    else
    {
      CBaseEntity::AddEffects(this: (CBaseEntity *)m_pEntity, nEffects: 32);
    }
    this = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214B90
// Name: public: void CSlideshowDisplay::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::Enable(CSlideshowDisplay *this)
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
        CSlideshowDisplay::ScreenVisible(this, bVisible: true);
        return;
      }
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      this->m_bEnabled.m_Value = true;
    }
    CSlideshowDisplay::ScreenVisible(this, bVisible: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214BF0
// Name: public: void CSlideshowDisplay::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::InputDisable(CSlideshowDisplay *this, inputdata_t *inputdata)
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
    CSlideshowDisplay::ScreenVisible(this, bVisible: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214C40
// Name: public: void CSlideshowDisplay::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSlideshowDisplay::InputEnable(CSlideshowDisplay *this, inputdata_t *inputdata)
{
  CSlideshowDisplay::Enable(this);
}

//------------------------------------------------------------------------------
// Address: 0x10214C50
// Name: private: void CSlideshowDisplay::SpawnControlPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::SpawnControlPanels(CSlideshowDisplay *this)
{
  CVGuiScreen *VGuiScreen; // edi
  CVGuiScreen_vtbl *v3; // ebx
  int TeamNumber; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CHandle<CVGuiScreen> *m_pMemory; // ecx
  int v8; // eax
  CHandle<CVGuiScreen> *v9; // eax
  CHandle<CVGuiScreen> *v10; // esi
  float flWidth; // [esp+18h] [ebp-8h]
  float flHeight; // [esp+1Ch] [ebp-4h]

  flWidth = (float)this->m_iScreenWidth;
  flHeight = (float)this->m_iScreenHeight;
  VGuiScreen = CreateVGuiScreen(
                 pScreenClassname: "vgui_screen",
                 pScreenType: "slideshow_display_screen",
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
  m_Size = this->m_hScreens.m_Size;
  m_nAllocationCount = this->m_hScreens.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hScreens,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_hScreens.m_Size;
  m_pMemory = this->m_hScreens.m_Memory.m_pMemory;
  v8 = this->m_hScreens.m_Size - m_Size - 1;
  this->m_hScreens.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_hScreens.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    v9->m_Index = -1;
  v10 = &this->m_hScreens.m_Memory.m_pMemory[m_Size];
  v10->m_Index = VGuiScreen->GetRefEHandle(this: VGuiScreen)->m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10214D70
// Name: private: void CSlideshowDisplay::RestoreControlPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::RestoreControlPanels(CSlideshowDisplay *this)
{
  CBaseEntity *i; // eax
  CVGuiScreen *v3; // esi
  unsigned int m_Index; // eax
  CSlideshowDisplay *m_pEntity; // ecx
  const char *PanelName; // eax
  CHandle<CVGuiScreen> *v7; // edi

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
        m_pEntity = (CSlideshowDisplay *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != this )
        continue;
    }
    PanelName = CVGuiScreen::GetPanelName(this: v3);
    if ( _V_strcmp(s1: PanelName, s2: "slideshow_display_screen") == 0 )
      break;
  }
  if ( v3 != nullptr )
  {
    v7 = &this->m_hScreens.m_Memory.m_pMemory[CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int>>::InsertBefore(
                                                this: &this->m_hScreens,
                                                elem: this->m_hScreens.m_Size)];
    v7->m_Index = v3->GetRefEHandle(this: v3)->m_Index;
    CVGuiScreen::SetActive(this: v3, bActive: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214E20
// Name: private: void CSlideshowDisplay::BuildSlideShowImagesList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::BuildSlideShowImagesList(CSlideshowDisplay *this)
{
  CSlideshowDisplay *v1; // edi
  const char *v2; // eax
  char *v3; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  const char *String; // eax
  char *v8; // ecx
  char *j; // ebx
  char k; // al
  int v11; // esi
  vgui::TreeNode *v12; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_SlideKeywordList; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v17; // eax
  int v18; // edi
  vgui::TreeNode **v19; // eax
  bool v20; // zf
  int v21; // esi
  SlideKeywordList_t *v22; // eax
  int v23; // ecx
  SlideKeywordList_t *v24; // ebx
  int v25; // eax
  SlideKeywordList_t **v26; // eax
  int v27; // ecx
  SlideKeywordList_t **v28; // eax
  const char *v29; // eax
  char szFullFileName[260]; // [esp+4h] [ebp-528h] BYREF
  char szDirectory[260]; // [esp+108h] [ebp-424h] BYREF
  char szKeywords[256]; // [esp+20Ch] [ebp-320h] BYREF
  char szFileName[260]; // [esp+30Ch] [ebp-220h] BYREF
  char szMatFileName[260]; // [esp+410h] [ebp-11Ch] BYREF
  vgui::TreeNode *v35; // [esp+514h] [ebp-18h]
  CSlideshowDisplay *v36; // [esp+518h] [ebp-14h]
  char *i; // [esp+51Ch] [ebp-10h]
  int matHandle; // [esp+520h] [ebp-Ch] BYREF
  KeyValues *pMaterialKeys; // [esp+524h] [ebp-8h]
  char *pchKeyword; // [esp+528h] [ebp-4h]

  v1 = this;
  v36 = this;
  memset(szMatFileName, 0, sizeof(szMatFileName));
  V_snprintf(pDest: szDirectory, maxLen: 260, pFormat: "materials/vgui/%s/*.vmt", this->m_szSlideshowDirectory.m_Value);
  v2 = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: szDirectory, a3: &matHandle);
  if ( v2 != nullptr )
    V_strncpy(pDest: szMatFileName, pSrc: v2, maxLen: 260);
  if ( szMatFileName[0] != 0 )
  {
    v3 = &szKeywords[252];
    for ( i = &szKeywords[252]; ; v3 = i )
    {
      V_snprintf(
        pDest: szFileName,
        maxLen: 260,
        pFormat: "vgui/%s/%s",
        v1->m_szSlideshowDirectory.m_Value,
        szMatFileName);
      v3[_V_strlen(str: szFileName)] = 0;
      PrecacheMaterial(pMaterialName: szFileName);
      V_snprintf(
        pDest: szFullFileName,
        maxLen: 260,
        pFormat: "materials/vgui/%s/%s",
        v1->m_szSlideshowDirectory.m_Value,
        szMatFileName);
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
      {
        v5 = KeyValues::KeyValues(this: v4, setName: "material");
        pMaterialKeys = v5;
      }
      else
      {
        pMaterialKeys = nullptr;
        v5 = nullptr;
      }
      if ( g_pFullFileSystem != nullptr )
        v6 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v6 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v5,
             filesystem: v6,
             resourceName: szFullFileName,
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        String = KeyValues::GetString(this: v5, keyName: "%keywords", defaultValue: locale);
        _V_strcpy(dest: szKeywords, src: String);
        v8 = szKeywords;
        pchKeyword = szKeywords;
        if ( szKeywords[0] != 0 )
        {
          while ( 1 )
          {
            for ( j = v8; *j != 0; ++j )
            {
              if ( *j == 44 )
                break;
            }
            if ( *j != 0 )
            {
              *j = 0;
              for ( k = *++j; k != 0; k = *++j )
              {
                if ( k != 44 && k != 32 )
                  break;
              }
            }
            v11 = 0;
            if ( v1->m_SlideKeywordList.m_Size <= 0 )
              goto LABEL_29;
            while ( _V_strcmp(s1: v1->m_SlideKeywordList.m_Memory.m_pMemory[v11]->szSlideKeyword, s2: v8) != 0 )
            {
              if ( ++v11 >= v1->m_SlideKeywordList.m_Size )
                break;
              v8 = pchKeyword;
            }
            if ( v11 >= v1->m_SlideKeywordList.m_Size )
            {
LABEL_29:
              v12 = (vgui::TreeNode *)operator new(nSize: 0x40u);
              p_m_SlideKeywordList = (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_SlideKeywordList;
              m_Size = v1->m_SlideKeywordList.m_Size;
              v35 = v12;
              m_nAllocationCount = p_m_SlideKeywordList->m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<CNavLadder *,int>::Grow(this: p_m_SlideKeywordList, num: m_Size - m_nAllocationCount + 1);
              ++p_m_SlideKeywordList[1].m_pMemory;
              m_pMemory = p_m_SlideKeywordList->m_pMemory;
              v17 = (int)p_m_SlideKeywordList[1].m_pMemory - m_Size - 1;
              p_m_SlideKeywordList[1].m_nAllocationCount = (int)p_m_SlideKeywordList->m_pMemory;
              if ( v17 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
              v18 = m_Size;
              v19 = &p_m_SlideKeywordList->m_pMemory[v18];
              if ( v19 != nullptr )
                *v19 = v35;
              _V_strcpy(dest: (char *)p_m_SlideKeywordList->m_pMemory[v18], src: pchKeyword);
              v1 = v36;
            }
            v20 = *j == 0;
            pchKeyword = j;
            if ( v20 )
              break;
            v8 = pchKeyword;
          }
          v5 = pMaterialKeys;
        }
      }
      KeyValues::deleteThis(this: v5);
      v21 = 0;
      if ( v1->m_SlideKeywordList.m_Size <= 0 )
        goto LABEL_42;
      do
      {
        if ( _V_strcmp(s1: v1->m_SlideKeywordList.m_Memory.m_pMemory[v21]->szSlideKeyword, s2: locale) == 0 )
          break;
        ++v21;
      }
      while ( v21 < v1->m_SlideKeywordList.m_Size );
      if ( v21 >= v1->m_SlideKeywordList.m_Size )
      {
LABEL_42:
        v22 = (SlideKeywordList_t *)operator new(nSize: 0x40u);
        v23 = v1->m_SlideKeywordList.m_Memory.m_nAllocationCount;
        v24 = v22;
        v25 = v1->m_SlideKeywordList.m_Size;
        if ( v25 + 1 > v23 )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_SlideKeywordList,
            num: v25 - v23 + 1);
        ++v1->m_SlideKeywordList.m_Size;
        v26 = v1->m_SlideKeywordList.m_Memory.m_pMemory;
        v27 = v1->m_SlideKeywordList.m_Size - 1;
        v1->m_SlideKeywordList.m_pElements = v26;
        if ( v27 > 0 )
          _V_memmove(dest: v26 + 1, src: v26, count: 4 * v27);
        v28 = v1->m_SlideKeywordList.m_Memory.m_pMemory;
        if ( v28 != nullptr )
          *v28 = v24;
        _V_strcpy(dest: *(char **)v1->m_SlideKeywordList.m_Memory.m_pMemory, src: locale);
      }
      v29 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: matHandle);
      if ( v29 == nullptr )
        break;
      V_strncpy(pDest: szMatFileName, pSrc: v29, maxLen: 260);
      if ( szMatFileName[0] == 0 )
        goto LABEL_53;
    }
    szMatFileName[0] = 0;
  }
LABEL_53:
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: matHandle);
}

//------------------------------------------------------------------------------
// Address: 0x10215260
// Name: public: virtual void CSlideshowDisplay::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::Spawn(CSlideshowDisplay *this)
{
  const char *pszValue; // edi
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  int i; // edi
  edict_t *v7; // ecx

  pszValue = this->m_String_tSlideshowDirectory.pszValue;
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
  _V_strcpy(dest: this->m_szSlideshowDirectory.m_Value, src: pszValue);
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
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x354u);
    }
    this->m_bEnabled.m_Value = false;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v5 = this->m_Network.m_pPev;
    if ( v5 != nullptr )
      CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x470u);
  }
  this->m_chCurrentSlideLists.m_Value[0] = 0;
  for ( i = 1; i < 16; ++i )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: i + 1136);
    }
    this->m_chCurrentSlideLists.m_Value[i] = -1;
  }
  CSlideshowDisplay::SpawnControlPanels(this);
  CSlideshowDisplay::ScreenVisible(this, bVisible: this->m_bEnabled.m_Value);
  this->m_bDoFullTransmit = true;
}

//------------------------------------------------------------------------------
// Address: 0x10215380
// Name: public: virtual void CSlideshowDisplay::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::Precache(CSlideshowDisplay *this)
{
  CSlideshowDisplay::BuildSlideShowImagesList(this);
  PrecacheVGuiScreen(pScreenType: "slideshow_display_screen");
}

//------------------------------------------------------------------------------
// Address: 0x102153A0
// Name: public: virtual void CSlideshowDisplay::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplay::OnRestore(CSlideshowDisplay *this)
{
  CBaseEntity::OnRestore(this);
  CSlideshowDisplay::BuildSlideShowImagesList(this);
  CSlideshowDisplay::RestoreControlPanels(this);
  CSlideshowDisplay::ScreenVisible(this, bVisible: this->m_bEnabled.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x10409E30
// Name: CSlideshowDisplay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSlideshowDisplay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSlideshowDisplay>(__formal: nullptr);
  CSlideshowDisplay_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409E60
// Name: DT_SlideshowDisplay::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SlideshowDisplay::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SlideshowDisplay::g_SendTable);
  return atexit(func: DT_SlideshowDisplay::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10409E80
// Name: DT_SlideshowDisplay::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SlideshowDisplay::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SlideshowDisplay::ignored>();
  DT_SlideshowDisplay::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041DE50
// Name: DT_SlideshowDisplay::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SlideshowDisplay::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SlideshowDisplay::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102151E0
// Name: struct datamap_t __near * DataMapInit<class CSlideshowDisplay>(class CSlideshowDisplay __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSlideshowDisplay>()
{
  if ( (_S2_203 & 1) == 0 )
  {
    _S2_203 |= 1u;
    nameHolder_386.m_pszBase = "CSlideshowDisplay";
    nameHolder_386.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_386.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_386.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_386.m_Names.m_Size = 0;
    nameHolder_386.m_Names.m_pElements = nullptr;
    nameHolder_386.m_nLenBase = 17;
    atexit(func: DataMapInit_CSlideshowDisplay__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSlideshowDisplay::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CSlideshowDisplay::m_DataMap.dataNumFields = 20;
  CSlideshowDisplay::m_DataMap.dataDesc = &dataDesc_369[1];
  return &CSlideshowDisplay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10409E40
// Name: _dynamic_initializer_for__g_CSlideshowDisplay_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSlideshowDisplay_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSlideshowDisplay_ClassReg,
           pNetworkName: "CSlideshowDisplay",
           pTable: &DT_SlideshowDisplay::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10409E90
// Name: _dynamic_initializer_for__LOG_SND_EMITTERSYSTEM__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_SND_EMITTERSYSTEM__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "SndEmitterSystem",
             a2: Register_LOG_SND_EMITTERSYSTEM_Tags,
             a3: 1,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_22);
  LOG_SND_EMITTERSYSTEM = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409EC0
// Name: _dynamic_initializer_for__sv_soundemitter_version__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_soundemitter_version__()
{
  ConVar::ConVar(
    this: &sv_soundemitter_version,
    pName: "sv_soundemitter_version",
    pDefaultValue: "2",
    flags: 24578,
    pHelpString: "specfies what version of soundemitter system to use\n");
  return atexit(func: dynamic_atexit_destructor_for__sv_soundemitter_version__);
}

//------------------------------------------------------------------------------
// Address: 0x10409EF0
// Name: _dynamic_initializer_for__snd_prevent_ss_duplicates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__snd_prevent_ss_duplicates__()
{
  ConVar::ConVar(
    this: &snd_prevent_ss_duplicates,
    pName: "snd_prevent_ss_duplicates",
    pDefaultValue: "0",
    flags: 24578,
    pHelpString: "switch to en/disable the prevention of splitscreen audio file duplicates\n");
  return atexit(func: dynamic_atexit_destructor_for__snd_prevent_ss_duplicates__);
}

//------------------------------------------------------------------------------
// Address: 0x10409F20
// Name: _dynamic_initializer_for__snd_sos_show_server_xmit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__snd_sos_show_server_xmit__()
{
  ConVar::ConVar(this: &snd_sos_show_server_xmit, pName: "snd_sos_show_server_xmit", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__snd_sos_show_server_xmit__);
}

//------------------------------------------------------------------------------
// Address: 0x10409F50
// Name: _dynamic_initializer_for__sv_soundemitter_trace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_soundemitter_trace__()
{
  ConVar::ConVar(
    this: &sv_soundemitter_trace,
    pName: "sv_soundemitter_trace",
    pDefaultValue: "-1",
    flags: 0x2000,
    pHelpString: "Show all EmitSound calls including their symbolic name and the actual wave file they resolved to. (-1 = for nobody, "
    "0 = for everybody, n = for one entity)\n");
  return atexit(func: dynamic_atexit_destructor_for__sv_soundemitter_trace__);
}

//------------------------------------------------------------------------------
// Address: 0x10409F80
// Name: _dynamic_initializer_for__cc_showmissing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_showmissing__()
{
  ConVar::ConVar(
    this: &cc_showmissing,
    pName: "cc_showmissing",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Show missing closecaption entries.");
  return atexit(func: dynamic_atexit_destructor_for__cc_showmissing__);
}

//------------------------------------------------------------------------------
// Address: 0x10409FB0
// Name: _dynamic_initializer_for__cc_norepeat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_norepeat__()
{
  ConVar::ConVar(
    this: &cc_norepeat,
    pName: "cc_norepeat",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "In multiplayer games, don't repeat captions more often than this many seconds.");
  return atexit(func: dynamic_atexit_destructor_for__cc_norepeat__);
}

//------------------------------------------------------------------------------
// Address: 0x10409FE0
// Name: _dynamic_initializer_for__g_CaptionRepeats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CaptionRepeats__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CaptionRepeats__);
}

//------------------------------------------------------------------------------
// Address: 0x10409FF0
// Name: _dynamic_initializer_for__g_SoundEmitterSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SoundEmitterSystem__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_SoundEmitterSystem.m_PrecachedScriptSounds,
    growSize: 0,
    initSize: 16,
    caseInsensitive: false);
  g_SoundEmitterSystem.m_ServerCaptions.m_Memory.m_pMemory = nullptr;
  g_SoundEmitterSystem.m_ServerCaptions.m_Memory.m_nAllocationCount = 0;
  g_SoundEmitterSystem.m_ServerCaptions.m_Memory.m_nGrowSize = 0;
  g_SoundEmitterSystem.m_ServerCaptions.m_Size = 0;
  g_SoundEmitterSystem.m_ServerCaptions.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_SoundEmitterSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A030
// Name: _dynamic_initializer_for__sv_soundemitter_flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_soundemitter_flush_command__()
{
  ConCommand::ConCommand(
    this: &sv_soundemitter_flush_command,
    pName: "sv_soundemitter_flush",
    callback: (void (__cdecl *)())sv_soundemitter_flush,
    pHelpString: "Flushes the sounds.txt system (server only)",
    flags: 2,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_soundemitter_flush_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A060
// Name: _dynamic_initializer_for__sv_soundemitter_filecheck_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_soundemitter_filecheck_command__()
{
  ConCommand::ConCommand(
    this: &sv_soundemitter_filecheck_command,
    pName: "sv_soundemitter_filecheck",
    callback: sv_soundemitter_filecheck,
    pHelpString: "Report missing wave files for sounds and game_sounds files.",
    flags: 2,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_soundemitter_filecheck_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A090
// Name: _dynamic_initializer_for__sv_findsoundname_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_findsoundname_command__()
{
  ConCommand::ConCommand(
    this: &sv_findsoundname_command,
    pName: "sv_findsoundname",
    callback: (void (__cdecl *)())sv_findsoundname,
    pHelpString: "Find sound names which reference the specified wave files.",
    flags: 2,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_findsoundname_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A0C0
// Name: _dynamic_initializer_for__sv_soundemitter_spew_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_soundemitter_spew_command__()
{
  ConCommand::ConCommand(
    this: &sv_soundemitter_spew_command,
    pName: "sv_soundemitter_spew",
    callback: (void (__cdecl *)())sv_soundemitter_spew,
    pHelpString: "Print details about a sound.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_soundemitter_spew_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE60
// Name: _ServerClassInit_DT_SlideshowDisplay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SlideshowDisplay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_115;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE80
// Name: _DataMapInit_CSlideshowDisplay__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSlideshowDisplay__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_386);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE90
// Name: _dynamic_atexit_destructor_for__sv_soundemitter_version__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_soundemitter_version__()
{
  ConVar::~ConVar(this: &sv_soundemitter_version);
}

//------------------------------------------------------------------------------
// Address: 0x1041DEA0
// Name: _dynamic_atexit_destructor_for__snd_prevent_ss_duplicates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__snd_prevent_ss_duplicates__()
{
  ConVar::~ConVar(this: &snd_prevent_ss_duplicates);
}

//------------------------------------------------------------------------------
// Address: 0x1041DEB0
// Name: _dynamic_atexit_destructor_for__snd_sos_show_server_xmit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__snd_sos_show_server_xmit__()
{
  ConVar::~ConVar(this: &snd_sos_show_server_xmit);
}

//------------------------------------------------------------------------------
// Address: 0x1041DEC0
// Name: _dynamic_atexit_destructor_for__sv_soundemitter_trace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_soundemitter_trace__()
{
  ConVar::~ConVar(this: &sv_soundemitter_trace);
}

//------------------------------------------------------------------------------
// Address: 0x1041DED0
// Name: _dynamic_atexit_destructor_for__cc_showmissing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_showmissing__()
{
  ConVar::~ConVar(this: &cc_showmissing);
}

//------------------------------------------------------------------------------
// Address: 0x1041DEE0
// Name: _dynamic_atexit_destructor_for__cc_norepeat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_norepeat__()
{
  ConVar::~ConVar(this: &cc_norepeat);
}

//------------------------------------------------------------------------------
// Address: 0x1041DEF0
// Name: _WaveTrace_::_5_::_dynamic_atexit_destructor_for__s_WaveTrace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl WaveTrace_::_5_::_dynamic_atexit_destructor_for__s_WaveTrace__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_WaveTrace);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF10
// Name: _dynamic_atexit_destructor_for__sv_soundemitter_flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_soundemitter_flush_command__()
{
  ConCommand::~ConCommand(this: &sv_soundemitter_flush_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF20
// Name: _dynamic_atexit_destructor_for__sv_soundemitter_filecheck_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_soundemitter_filecheck_command__()
{
  ConCommand::~ConCommand(this: &sv_soundemitter_filecheck_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF30
// Name: _dynamic_atexit_destructor_for__sv_findsoundname_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_findsoundname_command__()
{
  ConCommand::~ConCommand(this: &sv_findsoundname_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF40
// Name: _dynamic_atexit_destructor_for__sv_soundemitter_spew_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_soundemitter_spew_command__()
{
  ConCommand::~ConCommand(this: &sv_soundemitter_spew_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF60
// Name: _dynamic_atexit_destructor_for__g_CaptionRepeats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CaptionRepeats__()
{
  CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,float,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,float,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_CaptionRepeats.m_rbCaptionHistory.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF70
// Name: _dynamic_atexit_destructor_for__g_SoundEmitterSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SoundEmitterSystem__()
{
  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::~CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>(this: &g_SoundEmitterSystem.m_ServerCaptions);
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_SoundEmitterSystem.m_PrecachedScriptSounds);
  IGameSystem::~IGameSystem(this: &g_SoundEmitterSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF90
// Name: _DataMapInit_CSound__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSound__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_387);
}

//------------------------------------------------------------------------------
// Address: 0x1041DFA0
// Name: _DataMapInit_CSoundEnt__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSoundEnt__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_388);
}

//------------------------------------------------------------------------------
// Address: 0x1041DFB0
// Name: _DataMapInit_CAISound__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAISound__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_389);
}

//------------------------------------------------------------------------------
// Address: 0x1041DFC0
// Name: _dynamic_atexit_destructor_for__soundpatch_captionlength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundpatch_captionlength__()
{
  ConVar::~ConVar(this: &soundpatch_captionlength);
}

//------------------------------------------------------------------------------
// Address: 0x1041DFD0
// Name: _dynamic_atexit_destructor_for__report_soundpatch_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__report_soundpatch_command__()
{
  ConCommand::~ConCommand(this: &report_soundpatch_command);
}
