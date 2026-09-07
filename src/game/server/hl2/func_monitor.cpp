// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/hl2/func_monitor.cpp
// Functions: 14
// ============================================================

#include "game\server\hl2\func_monitor.h"

//------------------------------------------------------------------------------
// Address: 0x1013BB90
// Name: private: virtual struct datamap_t __near * CFuncMonitor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncMonitor::GetDataDescMap(CFuncMonitor *this)
{
  return &CFuncMonitor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013BBA0
// Name: public: virtual class ServerClass __near * CFuncMonitor::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncMonitor::GetServerClass(CFuncMonitor *this)
{
  return &g_CFuncMonitor_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1013BBB0
// Name: private: void CFuncMonitor::ReleaseCameraLink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMonitor::ReleaseCameraLink(CFuncMonitor *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax

  m_Index = this->m_hInfoCameraLink.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        v9 = *v8;
      else
        v9 = nullptr;
      UTIL_Remove(oldObj: v9);
      this->m_hInfoCameraLink.m_Index = -1;
      this->m_target.pszValue = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BC20
// Name: private: void CFuncMonitor::SetCameraByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMonitor::SetCameraByName(CFuncMonitor *this, const char *szName)
{
  CBasePlayer *EntityByName; // eax
  CPointCamera *v4; // eax
  const char *v5; // ecx
  CBaseEntity *InfoCameraLink; // eax

  CFuncMonitor::ReleaseCameraLink(this);
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
    v4 = (CPointCamera *)__RTDynamicCast(
                           inptr: EntityByName,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CPointCamera `RTTI Type Descriptor',
                           isReference: 0);
    if ( v4 != nullptr )
    {
      if ( szName != nullptr && *szName != 0 )
        v5 = szName;
      else
        v5 = nullptr;
      this->m_target.pszValue = v5;
      InfoCameraLink = CreateInfoCameraLink(pTarget: this, pCamera: v4);
      if ( InfoCameraLink != nullptr )
        this->m_hInfoCameraLink.m_Index = InfoCameraLink->GetRefEHandle(this: InfoCameraLink)->m_Index;
      else
        this->m_hInfoCameraLink.m_Index = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BCB0
// Name: private: void CFuncMonitor::InputSetCamera(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMonitor::InputSetCamera(CFuncMonitor *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
      CFuncMonitor::SetCameraByName(this, szName: locale);
      return;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  CFuncMonitor::SetCameraByName(this, szName: iVal);
}

//------------------------------------------------------------------------------
// Address: 0x1013BCF0
// Name: public: virtual int CFuncBrush::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFuncBrush::ObjectCaps(CFuncBrush *this)
{
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
    return CBaseEntity::ObjectCaps(this);
  else
    return CBaseEntity::ObjectCaps(this) | 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013BD90
// Name: public: virtual void CFuncMonitor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMonitor::Activate(CFuncMonitor *this)
{
  const char *pszValue; // eax

  CFuncBrush::Activate(this);
  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CFuncMonitor::SetCameraByName(this, szName: pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x1013BDC0
// Name: public: virtual void CFuncMonitor::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMonitor::UpdateOnRemove(CFuncMonitor *this)
{
  CFuncMonitor::ReleaseCameraLink(this);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10403FD0
// Name: CFuncMonitor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncMonitor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncMonitor>();
  CFuncMonitor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10404020
// Name: DT_FuncMonitor::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncMonitor::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncMonitor::g_SendTable);
  return atexit(func: DT_FuncMonitor::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10404040
// Name: DT_FuncMonitor::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncMonitor::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncMonitor::ignored>();
  DT_FuncMonitor::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B880
// Name: DT_FuncMonitor::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncMonitor::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncMonitor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B890
// Name: _ServerClassInit_DT_FuncMonitor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncMonitor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_66;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B8B0
// Name: _DataMapInit_CFuncMonitor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncMonitor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_219);
}
