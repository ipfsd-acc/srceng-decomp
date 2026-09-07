// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/materialmodifycontrol.cpp
// Functions: 21
// ============================================================

#include "game\server\materialmodifycontrol.h"

//------------------------------------------------------------------------------
// Address: 0x101717B0
// Name: public: virtual struct datamap_t __near * CMaterialModifyControl::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMaterialModifyControl::GetDataDescMap(CMaterialModifyControl *this)
{
  return &CMaterialModifyControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101717C0
// Name: public: virtual class ServerClass __near * CMaterialModifyControl::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CMaterialModifyControl::GetServerClass(CMaterialModifyControl *this)
{
  return &g_CMaterialModifyControl_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10171A90
// Name: public: virtual int CMaterialModifyControl::ShouldTransmit(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialModifyControl::ShouldTransmit(CMaterialModifyControl *this, const CCheckTransmitInfo *pInfo)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hMoveParent.m_Value.m_Index;
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
    return 16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171AE0
// Name: public: virtual bool CMaterialModifyControl::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialModifyControl::KeyValue(CMaterialModifyControl *this, char *szKeyName, const char *szValue)
{
  char *m_Value; // esi
  edict_t *m_pPev; // ecx

  if ( szKeyName == "materialName" || _V_stricmp(s1: szKeyName, s2: "materialName") == 0 )
  {
    m_Value = this->m_szMaterialName.m_Value;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
LABEL_8:
      V_strncpy(pDest: m_Value, pSrc: szValue, maxLen: 255);
      return true;
    }
    m_pPev = this->m_Network.m_pPev;
    goto LABEL_6;
  }
  if ( szKeyName == "materialVar" || _V_stricmp(s1: szKeyName, s2: "materialVar") == 0 )
  {
    m_Value = this->m_szMaterialVar.m_Value;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      goto LABEL_8;
    }
    m_pPev = this->m_Network.m_pPev;
LABEL_6:
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    goto LABEL_8;
  }
  return CBaseEntity::KeyValue(this, szKeyName, szValue);
}

//------------------------------------------------------------------------------
// Address: 0x10171BA0
// Name: public: CMaterialModifyControl::CMaterialModifyControl(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialModifyControl *__thiscall CMaterialModifyControl::CMaterialModifyControl(CMaterialModifyControl *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  CMaterialModifyControl *result; // eax
  edict_t *v5; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CMaterialModifyControl_vtbl *)&CMaterialModifyControl::`vftable';
  if ( this->m_iFrameStart.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x654u);
    }
    this->m_iFrameStart.m_Value = -1;
  }
  if ( this->m_iFrameEnd.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x658u);
    }
    this->m_iFrameEnd.m_Value = -1;
  }
  result = this;
  if ( this->m_nModifyMode.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nModifyMode.m_Value = 0;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x674u);
      this->m_nModifyMode.m_Value = 0;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10171C70
// Name: public: void CMaterialModifyControl::SetMaterialVar(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialModifyControl::SetMaterialVar(CMaterialModifyControl *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx

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
  V_strncpy(pDest: this->m_szMaterialVarValue.m_Value, pSrc: v5, maxLen: 255);
  if ( this->m_nModifyMode.m_Value != 1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nModifyMode.m_Value = 1;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x674u);
      this->m_nModifyMode.m_Value = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171D30
// Name: public: void CMaterialModifyControl::SetMaterialVarToCurrentTime(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialModifyControl::SetMaterialVarToCurrentTime(
        CMaterialModifyControl *this,
        inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  char temp[32]; // [esp+10h] [ebp-20h] BYREF

  V_snprintf(pDest: temp, maxLen: 32, pFormat: "%f", gpGlobals->curtime);
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
  V_strncpy(pDest: this->m_szMaterialVarValue.m_Value, pSrc: temp, maxLen: 255);
  if ( this->m_nModifyMode.m_Value != 1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nModifyMode.m_Value = 1;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x674u);
      this->m_nModifyMode.m_Value = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171E00
// Name: public: void CMaterialModifyControl::InputStartAnimSequence(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialModifyControl::InputStartAnimSequence(CMaterialModifyControl *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  bool v4; // zf
  const char *iVal; // eax
  const char *v6; // eax
  int v7; // edi
  const char *v8; // eax
  int v9; // ebx
  const char *v10; // eax
  const char *v11; // eax
  int v12; // eax
  CMaterialModifyControl *v13; // esi
  CBaseEdict *v14; // ecx
  CBaseEdict *v15; // ecx
  CBaseEdict *v16; // ecx
  CBaseEdict *v17; // ecx
  CBaseEdict *v18; // ecx
  bool v19; // bl
  CBaseEdict *v20; // ecx
  const char *pszValue; // esi
  const char *DebugName; // eax
  char parseString[256]; // [esp+Ch] [ebp-108h] BYREF
  float flFramerate; // [esp+10Ch] [ebp-8h]
  CMaterialModifyControl *v25; // [esp+110h] [ebp-4h]
  bool bWrap_3; // [esp+11Fh] [ebp+Bh]

  p_value = &inputdata->value;
  v4 = inputdata->value.fieldType == FIELD_STRING;
  v25 = this;
  if ( v4 )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  V_strncpy(pDest: parseString, pSrc: iVal, maxLen: 255);
  v6 = strtok(string: parseString, control: " ");
  if ( v6 != nullptr && *v6 != 0 )
  {
    v7 = atoi(nptr: v6);
    v8 = strtok(string: nullptr, control: " ");
    if ( v8 != nullptr && *v8 != 0 )
    {
      v9 = atoi(nptr: v8);
      v10 = strtok(string: nullptr, control: " ");
      if ( v10 != nullptr && *v10 != 0 )
      {
        flFramerate = atof(nptr: v10);
        v11 = strtok(string: nullptr, control: " ");
        if ( v11 != nullptr && *v11 != 0 )
        {
          v12 = atoi(nptr: v11);
          v13 = v25;
          bWrap_3 = v12 != 0;
          if ( v25->m_iFrameStart.m_Value != v7 )
          {
            if ( v25->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v25->m_Network + 76) |= 1u;
            }
            else
            {
              v14 = &v25->m_Network.m_pPev->CBaseEdict;
              if ( v14 != nullptr )
                CBaseEdict::StateChanged(this: v14, offset: 0x654u);
            }
            v13->m_iFrameStart.m_Value = v7;
          }
          if ( v13->m_iFrameEnd.m_Value != v9 )
          {
            if ( v13->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v13->m_Network + 76) |= 1u;
            }
            else
            {
              v15 = &v13->m_Network.m_pPev->CBaseEdict;
              if ( v15 != nullptr )
                CBaseEdict::StateChanged(this: v15, offset: 0x658u);
            }
            v13->m_iFrameEnd.m_Value = v9;
          }
          if ( v13->m_flFramerate.m_Value != flFramerate )
          {
            if ( v13->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v13->m_Network + 76) |= 1u;
            }
            else
            {
              v16 = &v13->m_Network.m_pPev->CBaseEdict;
              if ( v16 != nullptr )
                CBaseEdict::StateChanged(this: v16, offset: 0x660u);
            }
            v13->m_flFramerate.m_Value = flFramerate;
          }
          if ( v13->m_bWrap.m_Value != bWrap_3 )
          {
            if ( v13->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v13->m_Network + 76) |= 1u;
            }
            else
            {
              v17 = &v13->m_Network.m_pPev->CBaseEdict;
              if ( v17 != nullptr )
                CBaseEdict::StateChanged(this: v17, offset: 0x65Cu);
            }
            v13->m_bWrap.m_Value = bWrap_3;
          }
          if ( v13->m_nModifyMode.m_Value != 2 )
          {
            if ( v13->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v13->m_Network + 76) |= 1u;
            }
            else
            {
              v18 = &v13->m_Network.m_pPev->CBaseEdict;
              if ( v18 != nullptr )
                CBaseEdict::StateChanged(this: v18, offset: 0x674u);
            }
            v13->m_nModifyMode.m_Value = 2;
          }
          v19 = !v13->m_bNewAnimCommandsSemaphore.m_Value;
          if ( v13->m_bNewAnimCommandsSemaphore.m_Value != v19 )
          {
            if ( v13->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v13->m_Network + 76) |= 1u;
              v13->m_bNewAnimCommandsSemaphore.m_Value = v19;
            }
            else
            {
              v20 = &v13->m_Network.m_pPev->CBaseEdict;
              if ( v20 != nullptr )
                CBaseEdict::StateChanged(this: v20, offset: 0x664u);
              v13->m_bNewAnimCommandsSemaphore.m_Value = v19;
            }
          }
          return;
        }
      }
      this = v25;
    }
  }
  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  DebugName = CBaseEntity::GetDebugName(this);
  _Warning(
    a1: "%s (%s) received StartAnimSequence input without correct parameters. Syntax: <Frame Start> <Frame End> <Frame Rate> "
    "<Loop>\n"
    "Setting <Frame End> to -1 uses the last frame of the texture. <Loop> should be 1 or 0.\n",
    pszValue,
    DebugName);
}

//------------------------------------------------------------------------------
// Address: 0x10172090
// Name: public: void CMaterialModifyControl::InputStartFloatLerp(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialModifyControl::InputStartFloatLerp(CMaterialModifyControl *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  const char *v8; // eax
  edict_t *m_pPev; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  bool v13; // bl
  edict_t *v14; // ecx
  const char *pszValue; // esi
  const char *DebugName; // eax
  char parseString[256]; // [esp+8h] [ebp-108h] BYREF
  float flEndValue; // [esp+108h] [ebp-8h]
  float flTransitionTime; // [esp+10Ch] [ebp-4h]
  float flStartValue; // [esp+118h] [ebp+8h]

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  V_strncpy(pDest: parseString, pSrc: iVal, maxLen: 255);
  v5 = strtok(string: parseString, control: " ");
  if ( v5 != nullptr
    && *v5 != 0
    && (flStartValue = atof(nptr: v5), (v6 = strtok(string: nullptr, control: " ")) != nullptr)
    && *v6 != 0
    && (flEndValue = atof(nptr: v6), (v7 = strtok(string: nullptr, control: " ")) != nullptr)
    && *v7 != 0
    && (flTransitionTime = atof(nptr: v7), (v8 = strtok(string: nullptr, control: " ")) != nullptr)
    && *v8 != 0 )
  {
    atoi(nptr: v8);
    if ( this->m_flFloatLerpStartValue.m_Value != flStartValue )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x668u);
      }
      this->m_flFloatLerpStartValue.m_Value = flStartValue;
    }
    if ( this->m_flFloatLerpEndValue.m_Value != flEndValue )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x66Cu);
      }
      this->m_flFloatLerpEndValue.m_Value = flEndValue;
    }
    if ( this->m_flFloatLerpTransitionTime.m_Value != flTransitionTime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v11 = this->m_Network.m_pPev;
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x670u);
      }
      this->m_flFloatLerpTransitionTime.m_Value = flTransitionTime;
    }
    if ( this->m_nModifyMode.m_Value != 3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v12 = this->m_Network.m_pPev;
        if ( v12 != nullptr )
          CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x674u);
      }
      this->m_nModifyMode.m_Value = 3;
    }
    v13 = !this->m_bNewAnimCommandsSemaphore.m_Value;
    if ( this->m_bNewAnimCommandsSemaphore.m_Value != v13 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bNewAnimCommandsSemaphore.m_Value = v13;
      }
      else
      {
        v14 = this->m_Network.m_pPev;
        if ( v14 != nullptr )
          CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x664u);
        this->m_bNewAnimCommandsSemaphore.m_Value = v13;
      }
    }
  }
  else
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(
      a1: "%s (%s) received StartFloatLerp input without correct parameters. Syntax: <Start Value> <End Value> <Transition Ti"
      "me> <Loop>\n"
      "<Loop> should be 1 or 0.\n",
      pszValue,
      DebugName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405D10
// Name: _dynamic_initializer_for__material_modify_control__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__material_modify_control__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CMaterialModifyControl> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &material_modify_control,
           a3: "material_modify_control");
}

//------------------------------------------------------------------------------
// Address: 0x10405D30
// Name: CMaterialModifyControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMaterialModifyControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMaterialModifyControl>();
  CMaterialModifyControl_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405D60
// Name: DT_MaterialModifyControl::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MaterialModifyControl::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_MaterialModifyControl::g_SendTable);
  return atexit(func: DT_MaterialModifyControl::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10405D80
// Name: DT_MaterialModifyControl::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MaterialModifyControl::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_MaterialModifyControl::ignored>();
  DT_MaterialModifyControl::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C3C0
// Name: DT_MaterialModifyControl::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MaterialModifyControl::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_MaterialModifyControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10405D40
// Name: _dynamic_initializer_for__g_CMaterialModifyControl_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CMaterialModifyControl_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CMaterialModifyControl_ClassReg,
           pNetworkName: "CMaterialModifyControl",
           pTable: &DT_MaterialModifyControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10405D90
// Name: _dynamic_initializer_for__g_MemoryLog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MemoryLog__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_MemoryLog, name: nullptr);
  g_MemoryLog.__vftable = (CMemoryLog_vtbl *)&CMemoryLog::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_MemoryLog__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C3D0
// Name: _ServerClassInit_DT_MaterialModifyControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_MaterialModifyControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_80;
  for ( i = 13; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041C3F0
// Name: _DataMapInit_CMaterialModifyControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMaterialModifyControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_277);
}

//------------------------------------------------------------------------------
// Address: 0x1041C400
// Name: _dynamic_atexit_destructor_for__g_MemoryLog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MemoryLog__()
{
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_MemoryLog);
}

//------------------------------------------------------------------------------
// Address: 0x1041C410
// Name: _dynamic_atexit_destructor_for__g_MessageEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MessageEntities__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_MessageEntities);
}

//------------------------------------------------------------------------------
// Address: 0x1041C420
// Name: _DataMapInit_CMessageEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMessageEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_278);
}
