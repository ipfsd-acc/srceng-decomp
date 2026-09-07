// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/postprocesscontroller.cpp
// Functions: 36
// ============================================================

#include "game\server\postprocesscontroller.h"

//------------------------------------------------------------------------------
// Address: 0x100F2DE0
// Name: public: virtual void CPostProcessSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessSystem::LevelInitPreEntity(CColorCorrectionSystem *this)
{
  this->m_hMasterController.m_Index = -1;
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "round_start", a4: true);
}

//------------------------------------------------------------------------------
// Address: 0x101DB720
// Name: class CPostProcessSystem __near * PostProcessSystem(void)
// Source: json
//------------------------------------------------------------------------------
CPostProcessSystem *__cdecl PostProcessSystem()
{
  return &s_PostProcessSystem;
}

//------------------------------------------------------------------------------
// Address: 0x101DB730
// Name: public: virtual struct datamap_t __near * CPostProcessController::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPostProcessController::GetDataDescMap(CPostProcessController *this)
{
  return &CPostProcessController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DB740
// Name: public: virtual class ServerClass __near * CPostProcessController::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPostProcessController::GetServerClass(CPostProcessController *this)
{
  return &g_CPostProcessController_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101DB890
// Name: public: void CPostProcessController::InputSetFadeTime(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetFadeTime(CPostProcessController *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[0]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(p_m_flPostProcessParameters->m_Value[0]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      LODWORD(p_m_flPostProcessParameters->m_Value[0]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB900
// Name: public: void CPostProcessController::InputSetLocalContrastStrength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetLocalContrastStrength(
        CPostProcessController *this,
        inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[1]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[1]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
      LODWORD(p_m_flPostProcessParameters->m_Value[1]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB970
// Name: public: void CPostProcessController::InputSetLocalContrastEdgeStrength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetLocalContrastEdgeStrength(
        CPostProcessController *this,
        inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[2]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[2]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
      LODWORD(p_m_flPostProcessParameters->m_Value[2]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB9E0
// Name: public: void CPostProcessController::InputSetVignetteStart(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetVignetteStart(CPostProcessController *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[3]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[3]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
      LODWORD(p_m_flPostProcessParameters->m_Value[3]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBA50
// Name: public: void CPostProcessController::InputSetVignetteEnd(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetVignetteEnd(CPostProcessController *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[4]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[4]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
      LODWORD(p_m_flPostProcessParameters->m_Value[4]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBAC0
// Name: public: void CPostProcessController::InputSetVignetteBlurStrength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetVignetteBlurStrength(
        CPostProcessController *this,
        inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[5]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[5]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x368u);
      LODWORD(p_m_flPostProcessParameters->m_Value[5]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBB30
// Name: public: void CPostProcessController::InputSetFadeToBlackStrength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetFadeToBlackStrength(
        CPostProcessController *this,
        inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[6]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[6]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
      LODWORD(p_m_flPostProcessParameters->m_Value[6]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBBA0
// Name: public: void CPostProcessController::InputSetDepthBlurFocalDistance(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetDepthBlurFocalDistance(
        CPostProcessController *this,
        inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[7]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[7]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      LODWORD(p_m_flPostProcessParameters->m_Value[7]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBC10
// Name: public: void CPostProcessController::InputSetDepthBlurStrength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetDepthBlurStrength(CPostProcessController *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[8]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[8]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x374u);
      LODWORD(p_m_flPostProcessParameters->m_Value[8]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBC80
// Name: public: void CPostProcessController::InputSetScreenBlurStrength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetScreenBlurStrength(
        CPostProcessController *this,
        inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[9]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[9]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
      LODWORD(p_m_flPostProcessParameters->m_Value[9]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBCF0
// Name: public: void CPostProcessController::InputSetFilmGrainStrength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::InputSetFilmGrainStrength(CPostProcessController *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  CPostProcessController::NetworkVar_m_flPostProcessParameters *p_m_flPostProcessParameters; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_flPostProcessParameters = &this->m_flPostProcessParameters;
  if ( (const char *)LODWORD(this->m_flPostProcessParameters.m_Value[10]) != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      LODWORD(this->m_flPostProcessParameters.m_Value[10]) = pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
      LODWORD(p_m_flPostProcessParameters->m_Value[10]) = pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBD60
// Name: private: void CPostProcessSystem::InitMasterController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessSystem::InitMasterController(CPostProcessSystem *this)
{
  CBaseEntity *v2; // esi
  CBaseEntity *EntityByClassname; // eax
  unsigned int m_Index; // eax

  v2 = nullptr;
  while ( 1 )
  {
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: v2,
                          szName: "postprocess_controller");
    v2 = (CBaseEntity *)__RTDynamicCast(
                          inptr: EntityByClassname,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CPostProcessController `RTTI Type Descriptor',
                          isReference: 0);
    if ( v2 == nullptr )
      break;
    m_Index = this->m_hMasterController.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
      || (v2->m_spawnflags.m_Value & 1) != 0 )
    {
      this->m_hMasterController.m_Index = v2->GetRefEHandle(this: v2)->m_Index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBE00
// Name: public: virtual void CPostProcessSystem::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessSystem::FireGameEvent(CPostProcessSystem *this, IGameEvent *pEvent)
{
  CPostProcessSystem::InitMasterController(this: (CPostProcessSystem *)((char *)this - 12));
}

//------------------------------------------------------------------------------
// Address: 0x101DBE10
// Name: public: virtual void CPostProcessSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessSystem::LevelInitPostEntity(CPostProcessSystem *this)
{
  CBasePlayer *LocalPlayer; // eax
  unsigned int m_Index; // esi

  CPostProcessSystem::InitMasterController(this);
  if ( gpGlobals->maxClients == 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer != nullptr )
    {
      m_Index = LocalPlayer->m_hPostProcessCtrl.m_Value.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        CBasePlayer::InitPostProcessController(this: LocalPlayer);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBEF0
// Name: public: virtual void CPostProcessController::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostProcessController::Spawn(CPostProcessController *this)
{
  bool v2; // bl
  edict_t *m_pPev; // ecx

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  v2 = this->m_spawnflags.m_Value & 1;
  if ( this->m_bMaster.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bMaster.m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x380u);
      this->m_bMaster.m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104089E0
// Name: _dynamic_initializer_for__postprocess_controller__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__postprocess_controller__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPostProcessController> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &postprocess_controller,
           a3: "postprocess_controller");
}

//------------------------------------------------------------------------------
// Address: 0x10408A00
// Name: CPostProcessController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPostProcessController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPostProcessController>();
  CPostProcessController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408A30
// Name: DT_PostProcessController::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PostProcessController::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PostProcessController::g_SendTable);
  return atexit(func: DT_PostProcessController::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408A50
// Name: DT_PostProcessController::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PostProcessController::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PostProcessController::ignored>();
  DT_PostProcessController::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F3B0
// Name: _dynamic_initializer_for__post_jump_crouch__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__post_jump_crouch__()
{
  ConVar::ConVar(
    this: &post_jump_crouch,
    pName: "post_jump_crouch",
    pDefaultValue: "0.2f",
    flags: 0x4000,
    pHelpString: "This determines how long the player character will crouch for after landing a jump.  This only affects the third per"
    "son animation visuals and does not affect gameplay timing.");
  return atexit(func: dynamic_atexit_destructor_for__post_jump_crouch__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D590
// Name: DT_PostProcessController::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PostProcessController::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PostProcessController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041FDF0
// Name: _dynamic_atexit_destructor_for__post_jump_crouch__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__post_jump_crouch__()
{
  ConVar::~ConVar(this: &post_jump_crouch);
}

//------------------------------------------------------------------------------
// Address: 0x101DBF40
// Name: class CPostProcessController __near * _CreateEntityTemplate<class CPostProcessController>(class CPostProcessController __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPostProcessController *__cdecl _CreateEntityTemplate<CPostProcessController>(
        CPostProcessController *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi
  CBaseEdict *v5; // ecx

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x384u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPostProcessController::`vftable';
    LOBYTE(v3[1].m_Network.m_PVSInfo.m_vCenter[1]) = 0;
    if ( v3->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v3->m_Network + 76) |= 1u;
      v3->PostConstructor(this: v3, a2: className);
      return (CPostProcessController *)v3;
    }
    v5 = &v3->m_Network.m_pPev->CBaseEdict;
    if ( v5 != nullptr )
    {
      CBaseEdict::StateChanged(this: v5, offset: 0x380u);
      v3->PostConstructor(this: v3, a2: className);
      return (CPostProcessController *)v3;
    }
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: className);
  return (CPostProcessController *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10408A10
// Name: _dynamic_initializer_for__g_CPostProcessController_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPostProcessController_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPostProcessController_ClassReg,
           pNetworkName: "CPostProcessController",
           pTable: &DT_PostProcessController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10408A60
// Name: _dynamic_initializer_for__s_PrecacheRegister__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PrecacheRegister__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PrecacheRegister__);
}

//------------------------------------------------------------------------------
// Address: 0x10408A70
// Name: _dynamic_initializer_for__g_CPredictedViewModel_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPredictedViewModel_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPredictedViewModel_ClassReg,
           pNetworkName: "CPredictedViewModel",
           pTable: &DT_PredictedViewModel::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040F3E0
// Name: _dynamic_initializer_for__g_PlayerMove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PlayerMove__()
{
  CPlayerMove::CPlayerMove(this: &g_PlayerMove);
  g_PlayerMove.__vftable = (CCSPlayerMove_vtbl *)&CCSPlayerMove::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_PlayerMove__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F400
// Name: _dynamic_initializer_for__g_CCSTeam_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CCSTeam_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CCSTeam_ClassReg, pNetworkName: "CCSTeam", pTable: &DT_CSTeam::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D5A0
// Name: _ServerClassInit_DT_PostProcessController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PostProcessController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_103;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D5C0
// Name: _dynamic_atexit_destructor_for__s_PostProcessSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PostProcessSystem__()
{
  s_PostProcessSystem.CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CPostProcessSystem_vtbl *)&CPostProcessSystem::`vftable'{for `CAutoGameSystem'};
  s_PostProcessSystem.m_hMasterController.m_Index = -1;
  s_PostProcessSystem.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  s_PostProcessSystem.m_nDebugID = 13;
  if ( s_PostProcessSystem.m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &s_PostProcessSystem.CGameEventListener);
    s_PostProcessSystem.m_bRegisteredForEvents = false;
  }
  s_PostProcessSystem.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  IGameSystem::~IGameSystem(this: &s_PostProcessSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041D630
// Name: _DataMapInit_CPostProcessController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPostProcessController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_349);
}

//------------------------------------------------------------------------------
// Address: 0x1041D640
// Name: _dynamic_atexit_destructor_for__s_PrecacheRegister__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PrecacheRegister__()
{
  s_PrecacheRegister.__vftable = (CPrecacheRegister_vtbl *)&CPrecacheRegister::`vftable';
  IGameSystem::~IGameSystem(this: &s_PrecacheRegister);
}
