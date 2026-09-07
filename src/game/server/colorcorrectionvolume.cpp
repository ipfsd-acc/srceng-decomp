// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/colorcorrectionvolume.cpp
// Functions: 23
// ============================================================

#include "game\server\colorcorrectionvolume.h"

//------------------------------------------------------------------------------
// Address: 0x100F45B0
// Name: public: virtual struct datamap_t __near * CColorCorrectionVolume::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CColorCorrectionVolume::GetDataDescMap(CColorCorrectionVolume *this)
{
  return &CColorCorrectionVolume::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F45C0
// Name: public: virtual class ServerClass __near * CColorCorrectionVolume::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CColorCorrectionVolume::GetServerClass(CColorCorrectionVolume *this)
{
  return &g_CColorCorrectionVolume_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100F45D0
// Name: public: virtual bool CColorCorrectionVolume::PassesTriggerFilters(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CColorCorrectionVolume::PassesTriggerFilters(CColorCorrectionVolume *this, CBasePlayer *pEntity)
{
  return pEntity == UTIL_GetLocalPlayer();
}

//------------------------------------------------------------------------------
// Address: 0x100F45F0
// Name: public: virtual void CColorCorrectionVolume::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionVolume::StartTouch(CColorCorrectionVolume *this, CBaseEntity *pEntity)
{
  this->m_LastEnterTime = gpGlobals->curtime;
  this->m_LastEnterWeight = this->m_Weight.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100F4610
// Name: public: virtual void CColorCorrectionVolume::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionVolume::EndTouch(CColorCorrectionVolume *this, CBaseEntity *pEntity)
{
  this->m_LastExitTime = gpGlobals->curtime;
  this->m_LastExitWeight = this->m_Weight.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100F4710
// Name: public: void CColorCorrectionVolume::ThinkFunc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionVolume::ThinkFunc(CColorCorrectionVolume *this)
{
  edict_t *v2; // ecx
  float m_LastEnterTime; // xmm3_4
  float m_LastExitTime; // xmm1_4
  float v5; // xmm0_4
  edict_t *v6; // ecx
  float v7; // xmm0_4
  edict_t *m_pPev; // ecx
  int weight; // [esp+10h] [ebp-4h]

  if ( this->m_bEnabled )
  {
    m_LastEnterTime = this->m_LastEnterTime;
    m_LastExitTime = this->m_LastExitTime;
    if ( m_LastEnterTime <= m_LastExitTime )
    {
      if ( this->m_Weight.m_Value > 0.0 )
      {
        v7 = (float)((float)(gpGlobals->curtime - m_LastExitTime)
                   / (float)(this->m_FadeDuration * this->m_LastExitWeight))
           + (float)(1.0 - this->m_LastExitWeight);
        if ( v7 > 1.0 )
          v7 = 1.0;
        if ( this->m_Weight.m_Value != (float)(1.0 - v7) )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x484u);
          }
          this->m_Weight.m_Value = 1.0 - v7;
        }
      }
    }
    else if ( this->m_Weight.m_Value < 1.0 )
    {
      v5 = (float)((float)(gpGlobals->curtime - m_LastEnterTime)
                 / (float)((float)(1.0 - this->m_LastEnterWeight) * this->m_FadeDuration))
         + this->m_LastEnterWeight;
      weight = LODWORD(v5);
      if ( v5 > 1.0 )
      {
        v5 = 1.0;
        weight = 1065353216;
      }
      if ( this->m_Weight.m_Value != v5 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_Weight.m_Value = v5;
        }
        else
        {
          v6 = this->m_Network.m_pPev;
          if ( v6 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x484u);
            v5 = *(float *)&weight;
          }
          this->m_Weight.m_Value = v5;
        }
      }
    }
  }
  else if ( this->m_Weight.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v2 = this->m_Network.m_pPev;
      if ( v2 != nullptr )
        CBaseEdict::StateChanged(this: &v2->CBaseEdict, offset: 0x484u);
    }
    this->m_Weight.m_Value = 0.0;
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.0099999998, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100F4900
// Name: public: virtual bool CColorCorrectionVolume::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CColorCorrectionVolume::KeyValue(CColorCorrectionVolume *this, char *szKeyName, char *szValue)
{
  edict_t *v4; // ecx
  edict_t *m_pPev; // ecx

  if ( szKeyName != "filename" && _V_stricmp(s1: szKeyName, s2: "filename") != 0 )
  {
    if ( szKeyName != "maxweight" && _V_stricmp(s1: szKeyName, s2: "maxweight") != 0 )
    {
      return CBaseToggle::KeyValue(this, szKeyName, szValue);
    }
    else
    {
      sscanf(string: szValue, format: "%f", &szValue);
      if ( this->m_MaxWeight.m_Value != *(float *)&szValue )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_MaxWeight.m_Value = *(float *)&szValue;
          return true;
        }
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x488u);
        this->m_MaxWeight.m_Value = *(float *)&szValue;
      }
      return true;
    }
  }
  else
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
      {
        v4->m_fStateFlags |= 0x101u;
        CBaseEdict::GetChangeAccessor(this: &v4->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
      }
    }
    V_strncpy(pDest: this->m_lookupFilename.m_Value, pSrc: szValue, maxLen: 260);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4A10
// Name: public: virtual void CColorCorrectionVolume::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionVolume::Spawn(CColorCorrectionVolume *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+18h] [ebp-4h] BYREF

  CBaseTrigger::Spawn(this);
  this->m_iEFlags |= 0x880u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: 0xCu);
  v2 = *(const char **)((int (__thiscall *)(CColorCorrectionVolume *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CColorCorrectionVolume::ThinkFunc,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.0099999998, szContext: nullptr);
  this->m_bEnabled = !this->m_bStartDisabled;
}

//------------------------------------------------------------------------------
// Address: 0x100F4AD0
// Name: public: virtual CBaseTrigger::~CBaseTrigger(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTrigger::~CBaseTrigger(CBaseTrigger *this)
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hTouchingEntities);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnNotTouching);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTouching);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnEndTouchAll);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnEndTouch);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnStartTouchAll);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnStartTouch);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F4B30
// Name: public: CColorCorrectionVolume::CColorCorrectionVolume(void)
// Source: json
//------------------------------------------------------------------------------
CColorCorrectionVolume *__thiscall CColorCorrectionVolume::CColorCorrectionVolume(CColorCorrectionVolume *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  CBaseTrigger::CBaseTrigger(this);
  this->__vftable = (CColorCorrectionVolume_vtbl *)&CColorCorrectionVolume::`vftable';
  this->m_bEnabled = true;
  if ( this->m_MaxWeight.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x488u);
    }
    this->m_MaxWeight.m_Value = 1.0;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
LABEL_9:
    this->m_lookupFilename.m_Value[0] = 0;
    return this;
  }
  v4 = this->m_Network.m_pPev;
  if ( v4 == nullptr )
    goto LABEL_9;
  v4->m_fStateFlags |= 0x101u;
  CBaseEdict::GetChangeAccessor(this: &v4->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
  this->m_lookupFilename.m_Value[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F4BD0
// Name: public: virtual bool CBaseTrigger::UsesFilter(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseTrigger::UsesFilter(CBaseTrigger *this)
{
  unsigned int m_Index; // eax

  m_Index = this->m_hFilter.m_Index;
  return m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10246660
// Name: public: virtual void CColorCorrectionVolume::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionVolume::InputDisable(CColorCorrectionVolume *this, inputdata_t *inputdata)
{
  this->m_bEnabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x10246670
// Name: public: virtual void CColorCorrectionVolume::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionVolume::InputEnable(CColorCorrectionVolume *this, inputdata_t *inputdata)
{
  this->m_bEnabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x10401360
// Name: _dynamic_initializer_for__color_correction__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__color_correction__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CColorCorrection> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &color_correction,
           a3: "color_correction");
}

//------------------------------------------------------------------------------
// Address: 0x10401430
// Name: _dynamic_initializer_for__color_correction_volume__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__color_correction_volume__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CColorCorrectionVolume> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &color_correction_volume,
           a3: "color_correction_volume");
}

//------------------------------------------------------------------------------
// Address: 0x10401450
// Name: CColorCorrectionVolume_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CColorCorrectionVolume_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CColorCorrectionVolume>(__formal: nullptr);
  CColorCorrectionVolume_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401480
// Name: DT_ColorCorrectionVolume::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ColorCorrectionVolume::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ColorCorrectionVolume::g_SendTable);
  return atexit(func: DT_ColorCorrectionVolume::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104014A0
// Name: DT_ColorCorrectionVolume::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ColorCorrectionVolume::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ColorCorrectionVolume::ignored>();
  DT_ColorCorrectionVolume::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A550
// Name: DT_ColorCorrectionVolume::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ColorCorrectionVolume::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ColorCorrectionVolume::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100F4C10
// Name: struct datamap_t __near * DataMapInit<class CColorCorrectionVolume>(class CColorCorrectionVolume __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CColorCorrectionVolume>()
{
  char *Name; // eax

  if ( (_S2_65 & 1) == 0 )
  {
    _S2_65 |= 1u;
    nameHolder_119.m_pszBase = "CColorCorrectionVolume";
    nameHolder_119.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_119.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_119.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_119.m_Names.m_Size = 0;
    nameHolder_119.m_Names.m_pElements = nullptr;
    nameHolder_119.m_nLenBase = 22;
    atexit(func: DataMapInit_CColorCorrectionVolume__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CColorCorrectionVolume::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S2_65 & 2) == 0 )
  {
    _S2_65 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_119, pszIdentifier: "ThinkFunc");
    dataDesc_471[2].fieldSize = 1;
    dataDesc_471[3].fieldSize = 1;
    dataDesc_471[1].flags = 32;
    dataDesc_471[3].flags = 6;
    dataDesc_471[1].fieldName = Name;
    dataDesc_471[4].fieldSize = 260;
    dataDesc_471[1].fieldSize = 1;
    dataDesc_471[4].flags = 2;
    *(_QWORD *)dataDesc_471[2].flatOffset = 0;
    dataDesc_471[2].flags = 6;
    dataDesc_471[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_471[1].td = 0;
    *(_QWORD *)&dataDesc_471[1].override_field = 0;
    *(_QWORD *)&dataDesc_471[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_471[1].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_471[3].flatOffset = 0;
    dataDesc_471[1].fieldOffset = 0;
    dataDesc_471[1].externalName = nullptr;
    dataDesc_471[1].pSaveRestoreOps = nullptr;
    dataDesc_471[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CColorCorrectionVolume::ThinkFunc;
    dataDesc_471[2].fieldType = FIELD_FLOAT;
    dataDesc_471[2].fieldName = "m_FadeDuration";
    dataDesc_471[2].fieldOffset = 1440;
    dataDesc_471[2].externalName = "fadeDuration";
    dataDesc_471[2].pSaveRestoreOps = nullptr;
    dataDesc_471[2].inputFunc = nullptr;
    dataDesc_471[2].td = nullptr;
    dataDesc_471[2].fieldSizeInBytes = 4;
    dataDesc_471[2].override_field = nullptr;
    dataDesc_471[2].override_count = 0;
    dataDesc_471[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_471[2].flatGroup = 0;
    dataDesc_471[3].fieldType = FIELD_FLOAT;
    dataDesc_471[3].fieldName = "m_MaxWeight";
    dataDesc_471[3].fieldOffset = 1160;
    dataDesc_471[3].externalName = "maxweight";
    dataDesc_471[3].pSaveRestoreOps = nullptr;
    dataDesc_471[3].inputFunc = nullptr;
    dataDesc_471[3].td = nullptr;
    dataDesc_471[3].fieldSizeInBytes = 4;
    dataDesc_471[3].override_field = nullptr;
    dataDesc_471[3].override_count = 0;
    dataDesc_471[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_471[3].flatGroup = 0;
    dataDesc_471[4].fieldType = FIELD_CHARACTER;
    dataDesc_471[4].fieldName = "m_lookupFilename";
    dataDesc_471[4].fieldOffset = 1164;
    dataDesc_471[4].externalName = "filename";
    dataDesc_471[4].pSaveRestoreOps = nullptr;
    dataDesc_471[4].inputFunc = nullptr;
    dataDesc_471[4].td = nullptr;
    dataDesc_471[4].fieldSizeInBytes = 260;
    dataDesc_471[4].override_field = nullptr;
    dataDesc_471[4].override_count = 0;
    dataDesc_471[4].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_471[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_471[4].flatGroup = 0;
    dataDesc_471[5].fieldType = FIELD_BOOLEAN;
    dataDesc_471[5].fieldName = "m_bEnabled";
    dataDesc_471[5].fieldOffset = 1152;
    dataDesc_471[5].flags = 6;
    *(_QWORD *)dataDesc_471[5].flatOffset = 0;
    *(_QWORD *)dataDesc_471[6].flatOffset = 0;
    *(_QWORD *)dataDesc_471[7].flatOffset = 0;
    dataDesc_471[6].fieldType = FIELD_BOOLEAN;
    dataDesc_471[6].fieldSize = 1;
    dataDesc_471[6].flags = 6;
    *(_QWORD *)dataDesc_471[8].flatOffset = 0;
    dataDesc_471[5].externalName = "enabled";
    dataDesc_471[5].pSaveRestoreOps = nullptr;
    dataDesc_471[5].inputFunc = nullptr;
    dataDesc_471[5].td = nullptr;
    dataDesc_471[5].fieldSizeInBytes = 1;
    dataDesc_471[5].override_field = nullptr;
    dataDesc_471[5].override_count = 0;
    dataDesc_471[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_471[5].flatGroup = 0;
    dataDesc_471[6].fieldName = "m_bStartDisabled";
    dataDesc_471[6].fieldOffset = 1153;
    dataDesc_471[6].externalName = "StartDisabled";
    dataDesc_471[6].pSaveRestoreOps = nullptr;
    dataDesc_471[6].inputFunc = nullptr;
    dataDesc_471[6].td = nullptr;
    dataDesc_471[6].fieldSizeInBytes = 1;
    dataDesc_471[6].override_field = nullptr;
    dataDesc_471[6].override_count = 0;
    dataDesc_471[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_471[6].flatGroup = 0;
    dataDesc_471[7].fieldType = FIELD_FLOAT;
    dataDesc_471[7].fieldName = "m_Weight";
    dataDesc_471[7].fieldOffset = 1156;
    dataDesc_471[7].fieldSize = 1;
    dataDesc_471[7].flags = 2;
    dataDesc_471[7].externalName = nullptr;
    dataDesc_471[7].pSaveRestoreOps = nullptr;
    dataDesc_471[7].inputFunc = nullptr;
    dataDesc_471[7].td = nullptr;
    dataDesc_471[7].fieldSizeInBytes = 4;
    dataDesc_471[7].override_field = nullptr;
    dataDesc_471[7].override_count = 0;
    dataDesc_471[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_471[7].flatGroup = 0;
    dataDesc_471[8].fieldType = FIELD_FLOAT;
    dataDesc_471[8].fieldName = "m_LastEnterWeight";
    dataDesc_471[8].fieldOffset = 1424;
    dataDesc_471[8].fieldSize = 1;
    dataDesc_471[8].flags = 2;
    dataDesc_471[8].externalName = nullptr;
    dataDesc_471[8].pSaveRestoreOps = nullptr;
    dataDesc_471[8].inputFunc = nullptr;
    dataDesc_471[8].td = nullptr;
    dataDesc_471[8].fieldSizeInBytes = 4;
    dataDesc_471[8].override_field = nullptr;
    dataDesc_471[8].override_count = 0;
    dataDesc_471[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_471[8].flatGroup = 0;
    dataDesc_471[9].fieldType = FIELD_FLOAT;
    dataDesc_471[9].fieldName = "m_LastEnterTime";
    dataDesc_471[9].fieldOffset = 1428;
    dataDesc_471[9].fieldSize = 1;
    dataDesc_471[9].flags = 2;
    dataDesc_471[9].externalName = nullptr;
    dataDesc_471[9].pSaveRestoreOps = nullptr;
    dataDesc_471[9].inputFunc = nullptr;
    dataDesc_471[9].td = nullptr;
    dataDesc_471[9].fieldSizeInBytes = 4;
    dataDesc_471[9].override_field = nullptr;
    dataDesc_471[9].override_count = 0;
    dataDesc_471[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_471[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_471[9].flatGroup = 0;
    dataDesc_471[10].fieldType = FIELD_FLOAT;
    dataDesc_471[10].fieldName = "m_LastExitWeight";
    dataDesc_471[10].fieldOffset = 1432;
    dataDesc_471[10].fieldTolerance = 0.0;
    dataDesc_471[11].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_471[11].flatOffset = 0;
    dataDesc_471[10].fieldSize = 1;
    dataDesc_471[10].fieldSizeInBytes = 4;
    dataDesc_471[11].fieldSize = 1;
    dataDesc_471[11].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_471[12].td = 0;
    *(_QWORD *)&dataDesc_471[12].override_field = 0;
    *(_QWORD *)&dataDesc_471[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_471[12].flatOffset[1] = 0;
    dataDesc_471[10].flags = 2;
    dataDesc_471[10].externalName = nullptr;
    dataDesc_471[10].pSaveRestoreOps = nullptr;
    dataDesc_471[10].inputFunc = nullptr;
    dataDesc_471[10].td = nullptr;
    dataDesc_471[10].override_field = nullptr;
    dataDesc_471[10].override_count = 0;
    *(_QWORD *)dataDesc_471[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_471[10].flatGroup = 0;
    dataDesc_471[11].fieldType = FIELD_FLOAT;
    dataDesc_471[11].fieldName = "m_LastExitTime";
    dataDesc_471[11].fieldOffset = 1436;
    dataDesc_471[11].flags = 2;
    dataDesc_471[11].externalName = nullptr;
    dataDesc_471[11].pSaveRestoreOps = nullptr;
    dataDesc_471[11].inputFunc = nullptr;
    dataDesc_471[11].td = nullptr;
    dataDesc_471[11].override_field = nullptr;
    dataDesc_471[11].override_count = 0;
    *(_DWORD *)&dataDesc_471[11].flatGroup = 0;
    dataDesc_471[12].fieldType = FIELD_VOID;
    dataDesc_471[12].fieldName = "InputEnable";
    dataDesc_471[12].fieldOffset = 0;
    dataDesc_471[12].fieldSize = 1;
    dataDesc_471[12].flags = 8;
    dataDesc_471[12].externalName = "Enable";
    dataDesc_471[12].pSaveRestoreOps = nullptr;
    dataDesc_471[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall vgui::Panel::`vcall'{788,{flat}};
    dataDesc_471[13].fieldType = FIELD_VOID;
    dataDesc_471[13].fieldName = "InputDisable";
    dataDesc_471[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_471[13].fieldSize = 524289;
    dataDesc_471[13].externalName = "Disable";
    dataDesc_471[13].pSaveRestoreOps = nullptr;
    dataDesc_471[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall vgui::Panel::`vcall'{792,{flat}};
    *(_QWORD *)&dataDesc_471[13].td = 0;
    *(_QWORD *)&dataDesc_471[13].override_field = 0;
    *(_QWORD *)&dataDesc_471[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_471[13].flatOffset[1] = 0;
  }
  CColorCorrectionVolume::m_DataMap.dataNumFields = 13;
  CColorCorrectionVolume::m_DataMap.dataDesc = &dataDesc_471[1];
  return &CColorCorrectionVolume::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10401460
// Name: _dynamic_initializer_for__g_CColorCorrectionVolume_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CColorCorrectionVolume_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CColorCorrectionVolume_ClassReg,
           pNetworkName: "CColorCorrectionVolume",
           pTable: &DT_ColorCorrectionVolume::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A560
// Name: _ServerClassInit_DT_ColorCorrectionVolume::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ColorCorrectionVolume::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_36;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A580
// Name: _DataMapInit_CColorCorrectionVolume__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CColorCorrectionVolume__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_119);
}
