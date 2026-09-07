// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_areaportalwindow.cpp
// Functions: 15
// ============================================================

#include "game\server\func_areaportalwindow.h"

//------------------------------------------------------------------------------
// Address: 0x10131220
// Name: public: virtual class ServerClass __near * CFuncAreaPortalWindow::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncAreaPortalWindow::GetServerClass(CFuncAreaPortalWindow *this)
{
  return &g_CFuncAreaPortalWindow_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10131230
// Name: public: virtual struct datamap_t __near * CFuncAreaPortalWindow::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncAreaPortalWindow::GetDataDescMap(CFuncAreaPortalWindow *this)
{
  return &CFuncAreaPortalWindow::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10131240
// Name: public: virtual void CFuncAreaPortalWindow::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncAreaPortalWindow::Spawn(CFuncAreaPortalWindow *this)
{
  this->Precache(this);
  engine->SetAreaPortalState(this: engine, a2: this->m_portalNumber, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10131410
// Name: public: bool CFuncAreaPortalWindow::IsWindowOpen(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFuncAreaPortalWindow::IsWindowOpen(
        CFuncAreaPortalWindow *this,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *vecOrigins,
        float fovDistanceAdjustFactor)
{
  int v4; // ebx
  int v5; // esi
  double v6; // st7
  float v7; // xmm0_4
  float flClosestDistance; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF
  float flDist; // [esp+10h] [ebp+8h]

  v4 = 0;
  flClosestDistance = 3.4028235e38;
  if ( vecOrigins->m_Size <= 0 )
    return false;
  v5 = 0;
  do
  {
    v6 = CCollisionProperty::CalcDistanceFromPoint(
           this: &this->m_Collision,
           a2: COERCE_FLOAT(&savedregs),
           vecWorldPt: &vecOrigins->m_Memory.m_pMemory[v5]);
    if ( flClosestDistance <= v6 )
    {
      v7 = flClosestDistance;
    }
    else
    {
      flDist = v6;
      v7 = flDist;
      flClosestDistance = v6;
    }
    ++v4;
    ++v5;
  }
  while ( v4 < vecOrigins->m_Size );
  return v7 != 3.4028235e38 && (float)(this->m_flFadeDist.m_Value + 10.0) >= (float)(v7 * fovDistanceAdjustFactor);
}

//------------------------------------------------------------------------------
// Address: 0x101314C0
// Name: public: virtual bool CFuncAreaPortalWindow::UpdateVisibility(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,float,bool __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFuncAreaPortalWindow::UpdateVisibility(
        CFuncAreaPortalWindow *this,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *vecOrigins,
        float fovDistanceAdjustFactor,
        bool *bIsOpenOnClient)
{
  if ( CFuncAreaPortalWindow::IsWindowOpen(this, vecOrigins, fovDistanceAdjustFactor) )
    return CFuncAreaPortalBase::UpdateVisibility(this, vecOrigins, fovDistanceAdjustFactor, bIsOpenOnClient);
  *bIsOpenOnClient = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10131510
// Name: public: CFuncAreaPortalWindow::CFuncAreaPortalWindow(void)
// Source: json
//------------------------------------------------------------------------------
CFuncAreaPortalWindow *__thiscall CFuncAreaPortalWindow::CFuncAreaPortalWindow(CFuncAreaPortalWindow *this)
{
  CFuncAreaPortalWindow *result; // eax
  edict_t *m_pPev; // ecx

  CFuncAreaPortalBase::CFuncAreaPortalBase(this);
  this->__vftable = (CFuncAreaPortalWindow_vtbl *)&CFuncAreaPortalWindow::`vftable';
  result = this;
  if ( this->m_iBackgroundModelIndex.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iBackgroundModelIndex.m_Value = -1;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      this->m_iBackgroundModelIndex.m_Value = -1;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10131570
// Name: public: virtual void CFuncAreaPortalWindow::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncAreaPortalWindow::Activate(CFuncAreaPortalWindow *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // edi
  const char *v4; // eax
  int v5; // ebx
  edict_t *m_pPev; // ecx
  const char *v7; // eax
  CBasePlayer *v8; // esi
  const char *v9; // eax
  CBaseEntity *v10; // edi
  _BYTE v11[4]; // [esp+8h] [ebp-8h] BYREF
  CBaseEntity *v12; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v12 = this;
  CBaseEntity::Activate(this);
  pszValue = this->m_iBackgroundBModelName.pszValue;
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
  if ( EntityByName != nullptr )
  {
    v4 = *(const char **)((int (__thiscall *)(CBasePlayer *, _BYTE *))EntityByName->GetModelName)(
                           a1: EntityByName,
                           a2: v11);
    if ( v4 == nullptr )
      v4 = locale;
    v5 = modelinfo->GetModelIndex(this: modelinfo, a2: v4);
    if ( this->m_iBackgroundModelIndex.m_Value != v5 )
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
      this->m_iBackgroundModelIndex.m_Value = v5;
    }
    CBaseEntity::AddEffects(this: EntityByName, nEffects: 32);
  }
  v7 = this->m_target.pszValue;
  if ( v7 == nullptr )
    v7 = locale;
  v8 = CGlobalEntityList::FindEntityByName(
         this: &gEntList,
         pStartEntity: nullptr,
         szName: v7,
         pSearchingEntity: nullptr,
         pActivator: nullptr,
         pCaller: nullptr,
         pFilter: nullptr);
  if ( v8 != nullptr )
  {
    v9 = *(const char **)((int (__thiscall *)(CBasePlayer *, _BYTE *))v8->GetModelName)(a1: v8, a2: v11);
    if ( v9 == nullptr )
      v9 = locale;
    v10 = v12;
    v12->SetModel(this: v12, a2: v9);
    if ( (v8->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v8, a2: (int)&savedregs);
    CBaseEntity::SetAbsOrigin(this: v10, absOrigin: &v8->m_vecAbsOrigin);
    CBaseEntity::AddEffects(this: v8, nEffects: 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101316A0
// Name: public: void CFuncAreaPortalWindow::InputSetFadeStartDistance(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncAreaPortalWindow::InputSetFadeStartDistance(CFuncAreaPortalWindow *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CFuncAreaPortalWindow::NetworkVar_m_flFadeStartDist> *p_m_flFadeStartDist; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flFadeStartDist = &this->m_flFadeStartDist;
  if ( this->m_flFadeStartDist.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flFadeStartDist->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
      p_m_flFadeStartDist->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10403A50
// Name: DT_FuncAreaPortalWindow::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncAreaPortalWindow::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncAreaPortalWindow::g_SendTable);
  return atexit(func: DT_FuncAreaPortalWindow::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10403A70
// Name: DT_FuncAreaPortalWindow::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncAreaPortalWindow::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncAreaPortalWindow::ignored>();
  DT_FuncAreaPortalWindow::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403A80
// Name: CFuncAreaPortalWindow_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncAreaPortalWindow_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncAreaPortalWindow>();
  CFuncAreaPortalWindow_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403B40
// Name: _dynamic_initializer_for__window_pane__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__window_pane__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CWindowPane> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &window_pane,
           a3: "window_pane");
}

//------------------------------------------------------------------------------
// Address: 0x1041B640
// Name: DT_FuncAreaPortalWindow::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncAreaPortalWindow::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncAreaPortalWindow::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B650
// Name: _ServerClassInit_DT_FuncAreaPortalWindow::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncAreaPortalWindow::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_113;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B670
// Name: _DataMapInit_CFuncAreaPortalWindow__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncAreaPortalWindow__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_210);
}
