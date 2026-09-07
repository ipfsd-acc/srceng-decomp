// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/playerlocaldata.cpp
// Functions: 30
// ============================================================

#include "game\server\playerlocaldata.h"

//------------------------------------------------------------------------------
// Address: 0x101D0880
// Name: public: virtual void CPlayerLocalData::NetworkVar_m_PlayerFog::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLocalData::NetworkVar_m_PlayerFog::NetworkStateChanged(
        CPlayerLocalData::NetworkVar_m_PlayerFog *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 62) + 4))(a1: (char *)this - 248);
}

//------------------------------------------------------------------------------
// Address: 0x101D08A0
// Name: public: virtual void CPlayerLocalData::NetworkVar_m_PlayerFog::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLocalData::NetworkVar_m_PlayerFog::NetworkStateChanged(
        CPlayerLocalData::NetworkVar_m_PlayerFog *this,
        void *pVar)
{
  (**((void (__thiscall ***)(char *, void *))this - 62))(a1: (char *)this - 248, a2: pVar);
}

//------------------------------------------------------------------------------
// Address: 0x101D08B0
// Name: public: virtual void CPlayerLocalData::NetworkVar_m_audio::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLocalData::NetworkVar_m_audio::NetworkStateChanged(CPlayerLocalData::NetworkVar_m_audio *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 96) + 4))(a1: (char *)this - 384);
}

//------------------------------------------------------------------------------
// Address: 0x101D08D0
// Name: public: virtual void CPlayerLocalData::NetworkVar_m_audio::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLocalData::NetworkVar_m_audio::NetworkStateChanged(
        CPlayerLocalData::NetworkVar_m_audio *this,
        void *pVar)
{
  (**((void (__thiscall ***)(char *, void *))this - 96))(a1: (char *)this - 384, a2: pVar);
}

//------------------------------------------------------------------------------
// Address: 0x101D08E0
// Name: public: virtual void sky3dparams_t::NetworkVar_fog::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sky3dparams_t::NetworkVar_fog::NetworkStateChanged(sky3dparams_t::NetworkVar_fog *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 6) + 4))(a1: (char *)this - 24);
}

//------------------------------------------------------------------------------
// Address: 0x101D08F0
// Name: public: virtual void sky3dparams_t::NetworkVar_fog::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sky3dparams_t::NetworkVar_fog::NetworkStateChanged(sky3dparams_t::NetworkVar_fog *this, void *pVar)
{
  (**((void (__thiscall ***)(char *, void *))this - 6))(a1: (char *)this - 24, a2: pVar);
}

//------------------------------------------------------------------------------
// Address: 0x101D0B80
// Name: public: virtual void CPlayerLocalData::NetworkVar_m_skybox3d::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLocalData::NetworkVar_m_skybox3d::NetworkStateChanged(
        CPlayerLocalData::NetworkVar_m_skybox3d *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 37) + 4))(a1: (char *)this - 148);
}

//------------------------------------------------------------------------------
// Address: 0x101D0BA0
// Name: public: virtual void CPlayerLocalData::NetworkVar_m_skybox3d::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLocalData::NetworkVar_m_skybox3d::NetworkStateChanged(
        CPlayerLocalData::NetworkVar_m_skybox3d *this,
        void *pVar)
{
  (**((void (__thiscall ***)(char *, void *))this - 37))(a1: (char *)this - 148, a2: pVar);
}

//------------------------------------------------------------------------------
// Address: 0x101D0BB0
// Name: public: void CPlayerLocalData::UpdateAreaBits(class CBasePlayer __near *,unsigned char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLocalData::UpdateAreaBits(
        CPlayerLocalData *this,
        CBasePlayer *pl,
        unsigned __int8 *chAreaPortalBits)
{
  unsigned int m_Index; // eax
  CBasePlayer *m_pEntity; // ecx
  int v5; // esi
  int *m_pMemory; // edi
  int m_Size; // ebx
  int v8; // eax
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *SplitScreenAndPictureInPicturePlayers; // edi
  int v10; // esi
  unsigned int v11; // eax
  CEntInfo *v12; // ecx
  IHandleEntity *v13; // edx
  IHandleEntity *v14; // ecx
  IHandleEntity_vtbl *v15; // eax
  int v16; // edi
  int v17; // eax
  int v18; // esi
  int *v19; // eax
  int j; // edi
  CPlayerLocalData *v21; // ebx
  unsigned __int8 *v22; // esi
  CPlayerLocalData::NetworkVar_m_chAreaPortalBits *p_m_chAreaPortalBits; // esi
  unsigned __int8 tempBits2[32]; // [esp+Ch] [ebp-74h] BYREF
  unsigned __int8 tempBits[32]; // [esp+2Ch] [ebp-54h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > vecAreasSeen; // [esp+4Ch] [ebp-34h] BYREF
  Vector org2; // [esp+60h] [ebp-20h] BYREF
  Vector origin; // [esp+6Ch] [ebp-14h] BYREF
  CPlayerLocalData *v30; // [esp+78h] [ebp-8h]
  int i; // [esp+7Ch] [ebp-4h]
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *list; // [esp+88h] [ebp+8h]
  int lista; // [esp+88h] [ebp+8h]

  m_Index = pl->m_hViewEntity.m_Value.m_Index;
  v30 = this;
  if ( m_Index == -1 )
  {
    m_pEntity = nullptr;
  }
  else if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  else
  {
    m_pEntity = nullptr;
  }
  if ( m_pEntity == nullptr )
    m_pEntity = pl;
  m_pEntity->EyePosition(this: m_pEntity, result: &origin);
  memset(tempBits, 0, sizeof(tempBits));
  v5 = engine->GetArea(this: engine, a2: &origin);
  engine->GetAreaBits(this: engine, a2: v5, a3: tempBits, a4: 32);
  memset(&vecAreasSeen, 0, sizeof(vecAreasSeen));
  CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&vecAreasSeen, num: 1);
  m_pMemory = vecAreasSeen.m_Memory.m_pMemory;
  m_Size = vecAreasSeen.m_Size + 1;
  v8 = vecAreasSeen.m_Size++;
  vecAreasSeen.m_pElements = vecAreasSeen.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: vecAreasSeen.m_Memory.m_pMemory + 1, src: vecAreasSeen.m_Memory.m_pMemory, count: 4 * v8);
  if ( m_pMemory != nullptr )
    *m_pMemory = v5;
  SplitScreenAndPictureInPicturePlayers = CBasePlayer::GetSplitScreenAndPictureInPicturePlayers(this: pl);
  v10 = 0;
  list = SplitScreenAndPictureInPicturePlayers;
  for ( i = 0; v10 < SplitScreenAndPictureInPicturePlayers->m_Size; i = v10 )
  {
    v11 = SplitScreenAndPictureInPicturePlayers->m_Memory.m_pMemory[v10].m_Index;
    if ( v11 != -1 )
    {
      v12 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v11];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber == HIWORD(v11) )
      {
        v13 = v12->m_pEntity;
        if ( v12->m_pEntity != nullptr )
        {
          v14 = nullptr;
          memset(tempBits2, 0, sizeof(tempBits2));
          v15 = v13[983].__vftable;
          if ( v15 != (IHandleEntity_vtbl *)-1 )
          {
            if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber == (unsigned int)v15 >> 16 )
              v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
            else
              v14 = nullptr;
          }
          if ( v14 == nullptr )
            v14 = v13;
          ((void (__thiscall *)(IHandleEntity *, Vector *))v14->__vftable[42].dtr_IHandleEntity)(a1: v14, a2: &org2);
          v16 = engine->GetArea(this: engine, a2: &org2);
          v17 = 0;
          if ( m_Size <= 0 )
            goto LABEL_27;
          while ( vecAreasSeen.m_Memory.m_pMemory[v17] != v16 )
          {
            if ( ++v17 >= m_Size )
              goto LABEL_27;
          }
          if ( v17 == -1 )
          {
LABEL_27:
            v18 = m_Size;
            if ( m_Size + 1 > vecAreasSeen.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&vecAreasSeen,
                num: m_Size - vecAreasSeen.m_Memory.m_nAllocationCount + 1);
              m_Size = vecAreasSeen.m_Size;
            }
            vecAreasSeen.m_Size = ++m_Size;
            vecAreasSeen.m_pElements = vecAreasSeen.m_Memory.m_pMemory;
            if ( m_Size - v18 - 1 > 0 )
              _V_memmove(
                dest: &vecAreasSeen.m_Memory.m_pMemory[v18 + 1],
                src: &vecAreasSeen.m_Memory.m_pMemory[v18],
                count: 4 * (m_Size - v18 - 1));
            v19 = &vecAreasSeen.m_Memory.m_pMemory[v18];
            if ( v19 != nullptr )
              *v19 = v16;
            engine->GetAreaBits(this: engine, a2: v16, a3: tempBits2, a4: 32);
            *(_DWORD *)tempBits |= *(_DWORD *)tempBits2;
            *(_DWORD *)&tempBits[4] |= *(_DWORD *)&tempBits2[4];
            *(_DWORD *)&tempBits[8] |= *(_DWORD *)&tempBits2[8];
            *(_DWORD *)&tempBits[12] |= *(_DWORD *)&tempBits2[12];
            *(_DWORD *)&tempBits[16] |= *(_DWORD *)&tempBits2[16];
            *(_DWORD *)&tempBits[20] |= *(_DWORD *)&tempBits2[20];
            *(_DWORD *)&tempBits[24] |= *(_DWORD *)&tempBits2[24];
            *(_DWORD *)&tempBits[28] |= *(_DWORD *)&tempBits2[28];
            v10 = i;
          }
          SplitScreenAndPictureInPicturePlayers = list;
        }
      }
    }
    ++v10;
  }
  for ( j = 0; j < 32; ++j )
  {
    v21 = v30;
    v22 = &v30->m_chAreaBits.m_Value[j];
    if ( tempBits[j] != *v22 )
    {
      ((void (__stdcall *)(unsigned __int8 *))v30->NetworkStateChanged)(a1: &v30->m_chAreaBits.m_Value[j]);
      *v22 = tempBits[j];
    }
  }
  p_m_chAreaPortalBits = &v21->m_chAreaPortalBits;
  for ( lista = 24; lista != 0; --lista )
  {
    if ( *chAreaPortalBits != p_m_chAreaPortalBits->m_Value[0] )
    {
      v21->NetworkStateChanged(this: v21, a2: p_m_chAreaPortalBits);
      p_m_chAreaPortalBits->m_Value[0] = *chAreaPortalBits;
    }
    ++chAreaPortalBits;
    p_m_chAreaPortalBits = (CPlayerLocalData::NetworkVar_m_chAreaPortalBits *)((char *)p_m_chAreaPortalBits + 1);
  }
  if ( vecAreasSeen.m_Memory.m_nGrowSize >= 0 && vecAreasSeen.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecAreasSeen.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101D0EB0
// Name: void UpdateAllClientData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateAllClientData()
{
  int v0; // ebx
  CBasePlayer *v1; // edi
  CSkyCamera *CurrentSkyCamera; // eax
  CSkyCamera *v3; // esi
  CPlayerLocalData::NetworkVar_m_skybox3d *p_m_skybox3d; // ebx
  bool v5; // zf
  float *p_x; // edi
  CNetworkVarBase<int,sky3dparams_t::NetworkVar_area> *p_area; // edi
  int i; // [esp+4h] [ebp-4h]

  v0 = 1;
  for ( i = 1; v0 <= gpGlobals->maxClients; i = v0 )
  {
    v1 = UTIL_PlayerByIndex(playerIndex: v0);
    if ( v1 != nullptr )
    {
      CurrentSkyCamera = GetCurrentSkyCamera();
      v3 = CurrentSkyCamera;
      if ( CurrentSkyCamera == v1->m_Local.m_pOldSkyCamera )
      {
        if ( CurrentSkyCamera == nullptr )
        {
          p_area = &v1->m_Local.m_skybox3d.area;
          if ( p_area->m_Value != 255 )
          {
            (*(void (__thiscall **)(int *, CNetworkVarBase<int,sky3dparams_t::NetworkVar_area> *))p_area[-5].m_Value)(
              a1: &p_area[-5].m_Value,
              a2: p_area);
            p_area->m_Value = 255;
          }
        }
      }
      else
      {
        v1->m_Local.m_pOldSkyCamera = CurrentSkyCamera;
        p_m_skybox3d = &v1->m_Local.m_skybox3d;
        v1->m_Local.m_skybox3d.scale.m_Value = CurrentSkyCamera->m_skyboxData.scale.m_Value;
        v5 = CurrentSkyCamera->m_skyboxData.origin.m_Value.x == v1->m_Local.m_skybox3d.origin.m_Value.x;
        p_x = &v1->m_Local.m_skybox3d.origin.m_Value.x;
        if ( !v5
          || CurrentSkyCamera->m_skyboxData.origin.m_Value.y != p_x[1]
          || CurrentSkyCamera->m_skyboxData.origin.m_Value.z != p_x[2] )
        {
          (**((void (__thiscall ***)(int, float *))p_x - 2))(a1: (int)(p_x - 2), a2: p_x);
          *p_x = v3->m_skyboxData.origin.m_Value.x;
          p_x[1] = v3->m_skyboxData.origin.m_Value.y;
          p_x[2] = v3->m_skyboxData.origin.m_Value.z;
        }
        p_m_skybox3d->area.m_Value = v3->m_skyboxData.area.m_Value;
        fogparams_t::operator=(this: &p_m_skybox3d->fog, __that: &v3->m_skyboxData.fog);
        p_m_skybox3d->NetworkStateChanged_2(this: p_m_skybox3d);
        v0 = i;
      }
    }
    ++v0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D0FE0
// Name: public: CPlayerLocalData::CPlayerLocalData(void)
// Source: json
//------------------------------------------------------------------------------
CPlayerLocalData *__thiscall CPlayerLocalData::CPlayerLocalData(CPlayerLocalData *this)
{
  this->__vftable = (CPlayerLocalData_vtbl *)&CPlayerLocalData::`vftable';
  this->m_skybox3d.fog.__vftable = (sky3dparams_t::NetworkVar_fog_vtbl *)&sky3dparams_t::NetworkVar_fog::`vftable';
  this->m_skybox3d.__vftable = (CPlayerLocalData::NetworkVar_m_skybox3d_vtbl *)&CPlayerLocalData::NetworkVar_m_skybox3d::`vftable';
  fogplayerparams_t::fogplayerparams_t(this: &this->m_PlayerFog);
  this->m_PlayerFog.__vftable = (CPlayerLocalData::NetworkVar_m_PlayerFog_vtbl *)&CPlayerLocalData::NetworkVar_m_PlayerFog::`vftable';
  this->m_fog.__vftable = (fogparams_t_vtbl *)&fogparams_t::`vftable';
  this->m_audio.__vftable = (CPlayerLocalData::NetworkVar_m_audio_vtbl *)&CPlayerLocalData::NetworkVar_m_audio::`vftable';
  if ( this->m_audio.soundscapeIndex.m_Value != 0 )
  {
    this->m_audio.NetworkStateChanged(this: &this->m_audio, a2: &this->m_audio.soundscapeIndex);
    this->m_audio.soundscapeIndex.m_Value = 0;
  }
  if ( this->m_audio.localBits.m_Value != 0 )
  {
    this->m_audio.NetworkStateChanged(this: &this->m_audio, a2: &this->m_audio.localBits);
    this->m_audio.localBits.m_Value = 0;
  }
  if ( this->m_audio.entIndex.m_Value != 0 )
  {
    this->m_audio.NetworkStateChanged(this: &this->m_audio, a2: &this->m_audio.entIndex);
    this->m_audio.entIndex.m_Value = 0;
  }
  this->m_pOldSkyCamera = nullptr;
  if ( !this->m_bDrawViewmodel.m_Value )
  {
    this->NetworkStateChanged(this, a2: &this->m_bDrawViewmodel);
    this->m_bDrawViewmodel.m_Value = true;
  }
  if ( this->m_bSlowMovement.m_Value )
  {
    this->NetworkStateChanged(this, a2: &this->m_bSlowMovement);
    this->m_bSlowMovement.m_Value = false;
  }
  if ( this->m_fTBeamEndTime.m_Value != 0.0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_fTBeamEndTime);
    this->m_fTBeamEndTime.m_Value = 0.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104084C0
// Name: DT_Local::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Local::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Local::g_SendTable);
  return atexit(func: DT_Local::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104084E0
// Name: DT_Local::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Local::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Local::ignored>();
  DT_Local::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104084F0
// Name: fogplayerparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *fogplayerparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<fogplayerparams_t>();
  fogplayerparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408500
// Name: fogparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *fogparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<fogparams_t>();
  fogparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408510
// Name: sky3dparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *sky3dparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<sky3dparams_t>();
  sky3dparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408520
// Name: audioparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *audioparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<audioparams_t>();
  audioparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408530
// Name: CPlayerLocalData_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPlayerLocalData_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPlayerLocalData>();
  CPlayerLocalData_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D360
// Name: DT_Local::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Local::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Local::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x101D1110
// Name: __CreateCPluginHelpersCheckIPluginHelpersCheck_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPluginHelpersCheck *__cdecl _CreateCPluginHelpersCheckIPluginHelpersCheck_interface()
{
  return &s_PluginCheck;
}

//------------------------------------------------------------------------------
// Address: 0x10408540
// Name: _dynamic_initializer_for____g_CreateCPluginHelpersCheckIPluginHelpersCheck_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCPluginHelpersCheckIPluginHelpersCheck_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCPluginHelpersCheckIPluginHelpersCheck_reg,
           fn: (void *(__cdecl *)())_CreateCPluginHelpersCheckIPluginHelpersCheck_interface,
           pName: "PluginHelpersCheck001");
}

//------------------------------------------------------------------------------
// Address: 0x10408560
// Name: _dynamic_initializer_for__g_GameUI__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameUI__()
{
  CDllDemandLoader::CDllDemandLoader(this: &g_GameUI, pchModuleName: "gameui");
  return atexit(func: dynamic_atexit_destructor_for__g_GameUI__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D370
// Name: _ServerClassInit_DT_Local::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Local::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_173;
  for ( i = 41; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D390
// Name: _DataMapInit_fogplayerparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_fogplayerparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_329);
}

//------------------------------------------------------------------------------
// Address: 0x1041D3A0
// Name: _DataMapInit_fogparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_fogparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_330);
}

//------------------------------------------------------------------------------
// Address: 0x1041D3B0
// Name: _DataMapInit_sky3dparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_sky3dparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_331);
}

//------------------------------------------------------------------------------
// Address: 0x1041D3C0
// Name: _DataMapInit_audioparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_audioparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_332);
}

//------------------------------------------------------------------------------
// Address: 0x1041D3D0
// Name: _DataMapInit_CPlayerLocalData__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPlayerLocalData__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_333);
}

//------------------------------------------------------------------------------
// Address: 0x1041D3E0
// Name: _dynamic_atexit_destructor_for__g_GameUI__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameUI__()
{
  CDllDemandLoader::~CDllDemandLoader(this: &g_GameUI);
}

//------------------------------------------------------------------------------
// Address: 0x1041D3F0
// Name: _DataMapInit_CPointBonusMapsAccessor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointBonusMapsAccessor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_334);
}
