// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_particlescript.cpp
// Functions: 19
// ============================================================

#include "game\server\env_particlescript.h"

//------------------------------------------------------------------------------
// Address: 0x10115210
// Name: public: virtual struct datamap_t __near * CEnvParticleScript::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvParticleScript::GetDataDescMap(CEnvParticleScript *this)
{
  return &CEnvParticleScript::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10115220
// Name: public: virtual class ServerClass __near * CEnvParticleScript::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvParticleScript::GetServerClass(CEnvParticleScript *this)
{
  return &g_CEnvParticleScript_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10115230
// Name: private: void CEnvParticleScript::PrecacheAnimationEventMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvParticleScript::PrecacheAnimationEventMaterials(CEnvParticleScript *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  int v3; // ebx
  const studiohdr_t *v4; // ecx
  int v5; // eax
  mstudioseqdesc_t *v6; // edi
  int v7; // esi
  int numevents; // ebx
  int v9; // eax
  int v10; // ecx
  char pAttachmentName[256]; // [esp+4h] [ebp-20Ch] BYREF
  char pSpriteName[256]; // [esp+104h] [ebp-10Ch] BYREF
  CStudioHdr *v13; // [esp+204h] [ebp-Ch]
  int i; // [esp+208h] [ebp-8h]
  int numseq; // [esp+20Ch] [ebp-4h]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  v13 = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    numseq = m_pStudioHdr->m_pVModel != nullptr
           ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
           : m_pStudioHdr->m_pStudioHdr->numlocalseq;
    v3 = 0;
    for ( i = 0; v3 < numseq; i = v3 )
    {
      if ( m_pStudioHdr->m_pVModel != nullptr )
      {
        v6 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: v3);
      }
      else
      {
        v4 = m_pStudioHdr->m_pStudioHdr;
        v5 = v3;
        if ( v3 < 0 || v3 >= v4->numlocalseq )
          v5 = 0;
        v6 = (mstudioseqdesc_t *)((char *)v4 + 212 * v5 + v4->localseqindex);
      }
      if ( v6->numevents > 0 )
      {
        v7 = 0;
        numevents = v6->numevents;
        do
        {
          v9 = (int)v6 + v7 + v6->eventindex;
          if ( (*(_DWORD *)(v9 + 8) & 0x400) != 0 )
            v10 = *(unsigned __int16 *)(v9 + 6);
          else
            v10 = *(_DWORD *)(v9 + 4);
          if ( v10 == 6002
            && sscanf(string: (char *)(v9 + 12), format: "%255s %255s", pAttachmentName, pSpriteName) == 2 )
          {
            PrecacheMaterial(pMaterialName: pSpriteName);
          }
          v7 += 80;
          --numevents;
        }
        while ( numevents != 0 );
        m_pStudioHdr = v13;
        v3 = i;
      }
      ++v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115360
// Name: public: virtual void CEnvParticleScript::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvParticleScript::Precache(CEnvParticleScript *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  const char *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseAnimating::Precache(this);
  v3 = *(const char **)((int (__thiscall *)(CEnvParticleScript *, _BYTE *))this->GetModelName)(a1: this, a2: v5);
  if ( v3 == nullptr )
    v3 = locale;
  CBaseEntity::PrecacheModel(a1: a2, name: v3, bPreload: true);
  v4 = *(const char **)((int (__thiscall *)(CEnvParticleScript *, _BYTE *))this->GetModelName)(a1: this, a2: v5);
  if ( v4 == nullptr )
    v4 = locale;
  this->SetModel(this, a2: v4);
  CEnvParticleScript::PrecacheAnimationEventMaterials(this);
}

//------------------------------------------------------------------------------
// Address: 0x101153C0
// Name: public: virtual void CEnvParticleScript::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvParticleScript::Spawn(CEnvParticleScript *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  this->Precache(this);
  vgui::ListViewPanel::Paint((vgui::ListViewPanel *)this);
  CBaseEntity::AddEffects(this, nEffects: 16);
  v2 = *(const char **)((int (__thiscall *)(CEnvParticleScript *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10115410
// Name: public: void CEnvParticleScript::InputSetSequence(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvParticleScript::InputSetSequence(CEnvParticleScript *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax
  _fieldtypes fieldType; // ecx
  variant_t *p_inputdata; // edx
  const char *iVal; // eax
  int v7; // eax

  p_value = &inputdata->value;
  fieldType = inputdata->value.fieldType;
  if ( fieldType == FIELD_STRING )
  {
    p_inputdata = &inputdata->value;
  }
  else
  {
    inputdata = nullptr;
    p_inputdata = (variant_t *)&inputdata;
  }
  if ( p_inputdata->iVal != 0 )
  {
    if ( fieldType != FIELD_STRING )
    {
      inputdata = nullptr;
      p_value = (variant_t *)&inputdata;
    }
    iVal = (const char *)p_value->iVal;
    if ( iVal == nullptr )
      iVal = locale;
    v7 = CBaseAnimating::LookupSequence(this, label: iVal);
    if ( v7 != -1 )
      CBaseAnimating::SetSequence(this, nSequence: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101155C0
// Name: public: virtual void CEnvParticleScript::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvParticleScript::Activate(CEnvParticleScript *this)
{
  CSkyCamera *EntitySkybox; // eax
  float m_Value; // xmm0_4
  edict_t *v4; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx
  float flSkyboxScale; // [esp+8h] [ebp-4h]

  CBaseAnimating::Activate(this);
  CBaseEntity::DetectInSkybox(this);
  EntitySkybox = CBaseEntity::GetEntitySkybox(this);
  if ( EntitySkybox == nullptr )
  {
    if ( this->m_flSequenceScale.m_Value == 1.0 )
      goto LABEL_16;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x48Cu);
    }
    m_Value = 1.0;
    goto LABEL_15;
  }
  m_Value = (float)EntitySkybox->m_skyboxData.scale.m_Value;
  flSkyboxScale = m_Value;
  if ( m_Value == 0.0 )
  {
    m_Value = 1.0;
    flSkyboxScale = 1.0;
  }
  if ( this->m_flSequenceScale.m_Value != m_Value )
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
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x48Cu);
        m_Value = flSkyboxScale;
      }
    }
LABEL_15:
    this->m_flSequenceScale.m_Value = m_Value;
  }
LABEL_16:
  if ( this->m_flPlaybackRate.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flPlaybackRate.m_Value = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402830
// Name: CEnvParticleScript_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvParticleScript_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvParticleScript>(__formal: nullptr);
  CEnvParticleScript_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402880
// Name: DT_EnvParticleScript::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvParticleScript::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EnvParticleScript::g_SendTable);
  return atexit(func: DT_EnvParticleScript::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104028A0
// Name: DT_EnvParticleScript::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvParticleScript::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EnvParticleScript::ignored>();
  DT_EnvParticleScript::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AE40
// Name: DT_EnvParticleScript::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvParticleScript::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EnvParticleScript::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x101156E0
// Name: struct datamap_t __near * DataMapInit<class CEnvParticleScript>(class CEnvParticleScript __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvParticleScript>()
{
  if ( (_S2_86 & 1) == 0 )
  {
    _S2_86 |= 1u;
    nameHolder_164.m_pszBase = "CEnvParticleScript";
    nameHolder_164.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_164.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_164.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_164.m_Names.m_Size = 0;
    nameHolder_164.m_Names.m_pElements = nullptr;
    nameHolder_164.m_nLenBase = 18;
    atexit(func: DataMapInit_CEnvParticleScript__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvParticleScript::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  CEnvParticleScript::m_DataMap.dataNumFields = 2;
  CEnvParticleScript::m_DataMap.dataDesc = &dataDesc_154[1];
  return &CEnvParticleScript::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10402840
// Name: _dynamic_initializer_for__env_particlescript__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_particlescript__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvParticleScript> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_particlescript,
           a3: "env_particlescript");
}

//------------------------------------------------------------------------------
// Address: 0x10402860
// Name: _dynamic_initializer_for__g_CEnvParticleScript_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvParticleScript_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvParticleScript_ClassReg,
           pNetworkName: "CEnvParticleScript",
           pTable: &DT_EnvParticleScript::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104028B0
// Name: _dynamic_initializer_for__env_player_surface_trigger__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_player_surface_trigger__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvPlayerSurfaceTrigger> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_player_surface_trigger,
           a3: "env_player_surface_trigger");
}

//------------------------------------------------------------------------------
// Address: 0x1041AE50
// Name: _ServerClassInit_DT_EnvParticleScript::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EnvParticleScript::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_50;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE70
// Name: _DataMapInit_CEnvParticleScript__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvParticleScript__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_164);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE80
// Name: _dynamic_atexit_destructor_for__g_PlayerSurfaceTriggers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PlayerSurfaceTriggers__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PlayerSurfaceTriggers);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE90
// Name: _DataMapInit_CEnvPlayerSurfaceTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvPlayerSurfaceTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_165);
}
