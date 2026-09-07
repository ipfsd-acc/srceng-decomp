// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_playerresource.cpp
// Functions: 33
// ============================================================

#include "game\client\c_playerresource.h"

//------------------------------------------------------------------------------
// Address: 0x1007DF60
// Name: void RecvProxy_ChangedTeam(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_ChangedTeam(const CRecvProxyData *pData, void *pStruct, void *pOut)
{
  RecvProxy_Int32ToInt32(pData, pStruct, pOut);
  if ( g_PR != nullptr )
    g_PR->TeamChanged(this: g_PR);
}

//------------------------------------------------------------------------------
// Address: 0x1007DF90
// Name: public: virtual class ClientClass __near * C_PlayerResource::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PlayerResource::GetClientClass(C_PlayerResource *this)
{
  return &__g_C_PlayerResourceClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1007E1F0
// Name: public: virtual struct datamap_t __near * C_PlayerResource::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_PlayerResource::GetPredDescMap(C_PlayerResource *this)
{
  return &C_PlayerResource::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1007E200
// Name: class IGameResources __near * GameResources(void)
// Source: json
//------------------------------------------------------------------------------
IGameResources *__cdecl GameResources()
{
  if ( g_PR != nullptr )
    return &g_PR->IGameResources;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007E220
// Name: public: virtual C_PlayerResource::~C_PlayerResource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PlayerResource::~C_PlayerResource(C_PlayerResource *this)
{
  unsigned __int64 *v2; // esi
  int i; // [esp+Ch] [ebp-4h]

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PlayerResource_vtbl *)&C_PlayerResource::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PlayerResource::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PlayerResource::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PlayerResource::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PlayerResource::`vftable'{for `C_BaseEntity'};
  this->IGameResources::__vftable = (IGameResources_vtbl *)&C_PlayerResource::`vftable'{for `IGameResources'};
  v2 = &this->m_Xuids[1];
  for ( i = 64; i != 0; --i )
  {
    if ( *v2 != 0 )
      ((void (__thiscall *)(IScaleformUI *, _DWORD, _DWORD))g_pScaleformUI->AvatarImageRelease)(
        a1: g_pScaleformUI,
        a2: *(_DWORD *)v2,
        a3: *((_DWORD *)v2 + 1));
    ++v2;
  }
  g_PR = nullptr;
  this->IGameResources::__vftable = (IGameResources_vtbl *)&IGameResources::`vftable';
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007E2B0
// Name: protected: void C_PlayerResource::UpdateXuids(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PlayerResource::UpdateXuids(C_PlayerResource *this)
{
  int v1; // eax
  unsigned __int64 *v2; // edi
  bool v3; // zf
  unsigned __int64 xuid; // kr00_8
  unsigned __int64 v5; // rax
  int v6; // [esp-4h] [ebp-B4h]
  player_info_s sPlayerInfo; // [esp+Ch] [ebp-A4h] BYREF
  unsigned __int64 newXuid; // [esp+9Ch] [ebp-14h]
  C_PlayerResource *v9; // [esp+A4h] [ebp-Ch]
  IScaleformUI_vtbl *v10; // [esp+A8h] [ebp-8h]
  int i; // [esp+ACh] [ebp-4h]

  v1 = 1;
  v9 = this;
  i = 1;
  v2 = &this->m_Xuids[1];
  while ( 1 )
  {
    v3 = !this->m_bConnected[v1];
    newXuid = 0;
    if ( v3 || !engine->GetPlayerInfo(this: engine, a2: v1, a3: &sPlayerInfo) )
      xuid = newXuid;
    else
      xuid = sPlayerInfo.xuid;
    v5 = *v2;
    if ( xuid != *v2 )
    {
      if ( v5 != 0 )
      {
        v6 = *((_DWORD *)v2 + 1);
        v10 = g_pScaleformUI->__vftable;
        ((void (__thiscall *)(IScaleformUI *, _DWORD, int))v10->AvatarImageRelease)(a1: g_pScaleformUI, a2: v5, a3: v6);
      }
      if ( xuid != 0 )
        ((void (__thiscall *)(IScaleformUI *, _DWORD, _DWORD))g_pScaleformUI->AvatarImageAddRef)(
          a1: g_pScaleformUI,
          a2: xuid,
          a3: HIDWORD(xuid));
      *v2 = xuid;
    }
    ++v2;
    if ( ++i > 64 )
      break;
    v1 = i;
    this = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E380
// Name: protected: void C_PlayerResource::UpdatePlayerName(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PlayerResource::UpdatePlayerName(C_PlayerResource *this, int slot)
{
  char *name; // ebx
  const char *v4; // eax
  player_info_s sPlayerInfo; // [esp+8h] [ebp-90h] BYREF

  if ( (unsigned int)(slot - 1) > 0x3F )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_10463E1C, a2: (const char *)slot);
  }
  else
  {
    name = "unconnected";
    if ( this->IsConnected(this: &this->IGameResources, a2: slot)
      && engine->GetPlayerInfo(this: engine, a2: slot, a3: &sPlayerInfo) )
    {
      name = sPlayerInfo.name;
    }
    v4 = this->m_szName[slot];
    if ( v4 == nullptr || _V_stricmp(s1: v4, s2: name) != 0 )
      this->m_szName[slot] = AllocPooledString(pszValue: name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E420
// Name: public: virtual void C_PlayerResource::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PlayerResource::ClientThink(C_PlayerResource *this)
{
  C_PlayerResource *v1; // ebx
  unsigned int m_Index; // eax
  int v3; // esi
  const char **v4; // ebx
  const char *v5; // edi
  _BYTE v6[8]; // [esp+Ch] [ebp-94h] BYREF
  char v7; // [esp+14h] [ebp-8Ch] BYREF
  C_PlayerResource *v8; // [esp+9Ch] [ebp-4h]

  v1 = this;
  v8 = this;
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  m_Index = gpGlobals.m_Index;
  v3 = 1;
  if ( *(int *)(gpGlobals.m_Index + 20) >= 1 )
  {
    v4 = (const char **)(&v1->m_bIsBlurred + 4);
    do
    {
      if ( (unsigned int)(v3 - 1) > 0x3F )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_10463E1C, a2: (const char *)v3);
      }
      else
      {
        v5 = "unconnected";
        if ( (*(unsigned __int8 (__thiscall **)(int *, int))(v8->m_CalcAbsoluteVelocityMutex.m_depth + 16))(
               a1: &v8->m_CalcAbsoluteVelocityMutex.m_depth,
               a2: v3) != 0
          && engine->GetPlayerInfo(this: engine, a2: v3, a3: (player_info_s *)v6) )
        {
          v5 = &v7;
        }
        if ( *v4 == nullptr || _V_stricmp(s1: *v4, s2: v5) != 0 )
          *v4 = AllocPooledString(pszValue: v5);
      }
      m_Index = gpGlobals.m_Index;
      ++v3;
      ++v4;
    }
    while ( v3 <= *(_DWORD *)(gpGlobals.m_Index + 20) );
    v1 = v8;
  }
  (*(void (__stdcall **)(_DWORD))(HIDWORD(v1[-1].m_Xuids[63]) + 456))(a1: *(float *)(m_Index + 12) + 0.2);
}

//------------------------------------------------------------------------------
// Address: 0x1007E510
// Name: public: virtual bool C_PlayerResource::IsAlive(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PlayerResource::IsAlive(C_PlayerResource *this, int iIndex)
{
  return *((_BYTE *)&this->m_pIntermediateData[61] + iIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1007E530
// Name: public: virtual int C_PlayerResource::GetTeam(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PlayerResource::GetTeam(C_PlayerResource *this, int iIndex)
{
  if ( (unsigned int)(iIndex - 1) > 0x3F )
    return 0;
  else
    return LODWORD(this->m_rgflCoordinateFrame.m_flMatVal[2][iIndex + 1]);
}

//------------------------------------------------------------------------------
// Address: 0x1007E550
// Name: public: virtual char const __near * C_PlayerResource::GetTeamName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_PlayerResource::GetTeamName(C_PlayerResource *this, int index)
{
  C_Team *GlobalTeam; // eax

  GlobalTeam = GetGlobalTeam(iTeamNumber: index);
  if ( GlobalTeam != nullptr )
    return GlobalTeam->Get_Name(this: GlobalTeam);
  else
    return "Unknown";
}

//------------------------------------------------------------------------------
// Address: 0x1007E580
// Name: public: virtual int C_PlayerResource::GetTeamScore(int)
// Source: json
//------------------------------------------------------------------------------
C_Team *__thiscall C_PlayerResource::GetTeamScore(C_PlayerResource *this, int index)
{
  C_Team *result; // eax

  result = GetGlobalTeam(iTeamNumber: index);
  if ( result != nullptr )
    return (C_Team *)result->Get_Score(this: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007E5B0
// Name: public: virtual int C_PlayerResource::GetFrags(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PlayerResource::GetFrags(C_PlayerResource *this, int index)
{
  return 666;
}

//------------------------------------------------------------------------------
// Address: 0x1007E5C0
// Name: public: virtual bool C_PlayerResource::IsLocalPlayer(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PlayerResource::IsLocalPlayer(C_PlayerResource *this, int index)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  return LocalPlayer != nullptr && index == LocalPlayer->entindex(this: &LocalPlayer->IClientNetworkable);
}

//------------------------------------------------------------------------------
// Address: 0x1007E5F0
// Name: public: virtual bool C_PlayerResource::IsHLTV(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PlayerResource::IsHLTV(C_PlayerResource *this, int index)
{
  bool result; // al
  bool v3; // al
  player_info_s sPlayerInfo; // [esp+4h] [ebp-90h] BYREF

  result = this->IsConnected(this: &this->IGameResources, a2: index);
  if ( result )
  {
    v3 = engine->GetPlayerInfo(this: engine, a2: index, a3: &sPlayerInfo);
    return v3 && sPlayerInfo.ishltv;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007E640
// Name: public: virtual bool C_PlayerResource::IsFakePlayer(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PlayerResource::IsFakePlayer(C_PlayerResource *this, int iIndex)
{
  bool result; // al
  bool v3; // al
  player_info_s sPlayerInfo; // [esp+4h] [ebp-90h] BYREF

  result = ((int (__thiscall *)(C_PlayerResource *, int))this->GetClientNetworkable)(a1: this, a2: iIndex);
  if ( result )
  {
    v3 = engine->GetPlayerInfo(this: engine, a2: iIndex, a3: &sPlayerInfo);
    return v3 && sPlayerInfo.fakeplayer;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007E690
// Name: public: virtual int C_PlayerResource::GetPing(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PlayerResource::GetPing(C_PlayerResource *this, int iIndex)
{
  if ( ((unsigned __int8 (__thiscall *)(C_PlayerResource *, int))this->GetClientNetworkable)(a1: this, a2: iIndex) != 0 )
    return *((_DWORD *)&this->m_vecVelocity.x + iIndex);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007E6C0
// Name: public: virtual int C_PlayerResource::GetKills(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PlayerResource::GetKills(C_PlayerResource *this, int iIndex)
{
  if ( ((unsigned __int8 (__thiscall *)(C_PlayerResource *, int))this->GetClientNetworkable)(a1: this, a2: iIndex) != 0 )
    return *(_DWORD *)&this->m_iName[4 * iIndex + 196];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007E6F0
// Name: public: virtual int C_PlayerResource::GetDeaths(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PlayerResource::GetDeaths(C_PlayerResource *this, int iIndex)
{
  if ( ((unsigned __int8 (__thiscall *)(C_PlayerResource *, int))this->GetClientNetworkable)(a1: this, a2: iIndex) != 0 )
    return *((_DWORD *)&this->m_Collision.m_pOuter + iIndex);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007E720
// Name: public: virtual int C_PlayerResource::GetHealth(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall C_PlayerResource::GetHealth(C_PlayerResource *this, int iIndex)
{
  if ( ((unsigned __int8 (__thiscall *)(C_PlayerResource *, int))this->GetClientNetworkable)(a1: this, a2: iIndex) != 0 )
    return this->m_pIntermediateData[iIndex + 78];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007E750
// Name: public: virtual class Color const __near & C_PlayerResource::GetTeamColor(int)
// Source: json
//------------------------------------------------------------------------------
const Color *__thiscall C_PlayerResource::GetTeamColor(C_PlayerResource *this, unsigned int index)
{
  if ( index <= 0x1F )
    return (const Color *)&this->m_pIntermediateData[index + 143];
  if ( (_S6_16 & 1) == 0 )
  {
    _S6_16 |= 1u;
    blah = 0;
  }
  return &blah;
}

//------------------------------------------------------------------------------
// Address: 0x1007E790
// Name: public: virtual bool C_PlayerResource::IsConnected(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PlayerResource::IsConnected(C_PlayerResource *this, int iIndex)
{
  if ( (unsigned int)(iIndex - 1) > 0x3F )
    return false;
  else
    return *((_BYTE *)&this->m_iv_angRotation.m_bLooping + iIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1007E7B0
// Name: public: unsigned __int64 C_PlayerResource::GetXuid(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall C_PlayerResource::GetXuid(C_PlayerResource *this, int iIndex)
{
  if ( (unsigned int)(iIndex - 1) > 0x3F )
    return 0;
  else
    return this->m_Xuids[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1007E7E0
// Name: public: void C_PlayerResource::FillXuidText(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PlayerResource::FillXuidText(C_PlayerResource *this, int iIndex, char *buf, unsigned int bufSize)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx

  if ( buf != nullptr && bufSize != 0 )
  {
    if ( (unsigned int)(iIndex - 1) > 0x3F )
    {
      v5 = 0;
      v4 = 0;
    }
    else
    {
      v4 = this->m_Xuids[iIndex];
      v5 = HIDWORD(this->m_Xuids[iIndex]);
    }
    *buf = 0;
    V_snprintf(pDest: buf, maxLen: bufSize, pFormat: "%llu", __PAIR64__(v5, v4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E880
// Name: public: virtual void C_PlayerResource::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PlayerResource::OnDataChanged(C_PlayerResource *this, DataUpdateType_t updateType)
{
  C_PlayerResource::UpdateXuids(this: (C_PlayerResource *)((char *)this - 8));
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
    (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 2) + 456))(
      a1: (char *)this - 8,
      a2: *(float *)(gpGlobals.m_Index + 12) + 0.2);
}

//------------------------------------------------------------------------------
// Address: 0x1007E8D0
// Name: public: virtual char const __near * C_PlayerResource::GetPlayerName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_PlayerResource::GetPlayerName(C_PlayerResource *this, int iIndex)
{
  const char *v4; // eax

  if ( cl_names_debug.m_pParent != nullptr && cl_names_debug.m_pParent->m_Value.m_nValue != 0 )
    return "WWWWWWWWWWWWWWW";
  if ( (unsigned int)(iIndex - 1) > 0x3F )
    return "ERRORNAME";
  if ( ((unsigned __int8 (__thiscall *)(C_PlayerResource *, int))this->GetClientNetworkable)(a1: this, a2: iIndex) == 0 )
    return "unconnected";
  v4 = *((const char **)&this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable + iIndex);
  if ( v4 == nullptr || _V_stricmp(s1: v4, s2: "unconnected") == 0 )
    C_PlayerResource::UpdatePlayerName(this: (C_PlayerResource *)((char *)this - 2432), slot: iIndex);
  return *((const char **)&this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable + iIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1007E950
// Name: public: C_PlayerResource::C_PlayerResource(void)
// Source: json
//------------------------------------------------------------------------------
C_PlayerResource *__thiscall C_PlayerResource::C_PlayerResource(C_PlayerResource *this)
{
  Color *m_Colors; // esi
  const char **m_szName; // ebx
  int j; // eax
  int i; // [esp+Ch] [ebp-4h]

  C_BaseEntity::C_BaseEntity(this);
  this->IGameResources::__vftable = (IGameResources_vtbl *)&IGameResources::`vftable';
  m_Colors = this->m_Colors;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PlayerResource_vtbl *)&C_PlayerResource::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PlayerResource::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PlayerResource::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PlayerResource::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PlayerResource::`vftable'{for `C_BaseEntity'};
  this->IGameResources::__vftable = (IGameResources_vtbl *)&C_PlayerResource::`vftable'{for `IGameResources'};
  this->m_Colors[0] = 0;
  this->m_Colors[1] = 0;
  this->m_Colors[2] = 0;
  this->m_Colors[3] = 0;
  this->m_Colors[4] = 0;
  this->m_Colors[5] = 0;
  this->m_Colors[6] = 0;
  this->m_Colors[7] = 0;
  this->m_Colors[8] = 0;
  this->m_Colors[9] = 0;
  this->m_Colors[10] = 0;
  this->m_Colors[11] = 0;
  this->m_Colors[12] = 0;
  this->m_Colors[13] = 0;
  this->m_Colors[14] = 0;
  this->m_Colors[15] = 0;
  this->m_Colors[16] = 0;
  this->m_Colors[17] = 0;
  this->m_Colors[18] = 0;
  this->m_Colors[19] = 0;
  this->m_Colors[20] = 0;
  this->m_Colors[21] = 0;
  this->m_Colors[22] = 0;
  this->m_Colors[23] = 0;
  this->m_Colors[24] = 0;
  this->m_Colors[25] = 0;
  this->m_Colors[26] = 0;
  this->m_Colors[27] = 0;
  this->m_Colors[28] = 0;
  this->m_Colors[29] = 0;
  this->m_Colors[30] = 0;
  this->m_Colors[31] = 0;
  m_szName = this->m_szName;
  for ( i = 65; i != 0; --i )
    *m_szName++ = AllocPooledString(pszValue: "unconnected");
  memset(dst: (int)this->m_iPing, value: nullptr, count: sizeof(this->m_iPing));
  memset(dst: (int)this->m_iKills, value: nullptr, count: sizeof(this->m_iKills));
  memset(dst: (int)this->m_iDeaths, value: nullptr, count: sizeof(this->m_iDeaths));
  memset(dst: (int)this->m_bConnected, value: nullptr, count: sizeof(this->m_bConnected));
  memset(dst: (int)this->m_iTeam, value: nullptr, count: sizeof(this->m_iTeam));
  memset(dst: (int)this->m_bAlive, value: nullptr, count: sizeof(this->m_bAlive));
  memset(dst: (int)this->m_iHealth, value: nullptr, count: sizeof(this->m_iHealth));
  memset(dst: (int)this->m_Xuids, value: nullptr, count: sizeof(this->m_Xuids));
  for ( j = 32; j != 0; --j )
    *m_Colors++ = (Color)-3355444;
  g_PR = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10412DE0
// Name: DT_PlayerResource::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PlayerResource::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PlayerResource::g_RecvTable);
  return atexit(func: DT_PlayerResource::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412E00
// Name: DT_PlayerResource::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PlayerResource::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PlayerResource::ignored>();
  DT_PlayerResource::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412E10
// Name: C_PlayerResource_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_PlayerResource_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_PlayerResource::m_PredMap.dataNumFields = 8;
  C_PlayerResource::m_PredMap.dataDesc = (typedescription_t *)&unk_1059E324;
}

//------------------------------------------------------------------------------
// Address: 0x10430820
// Name: DT_PlayerResource::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PlayerResource::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PlayerResource::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1007EAF0
// Name: _C_PlayerResource_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PlayerResource_CreateObject(int entnum, int serialNum)
{
  C_PlayerResource *v2; // eax
  C_PlayerResource *v3; // eax
  C_PlayerResource *v4; // esi

  v2 = (C_PlayerResource *)C_BaseEntity::operator new(stAllocateBlock: 0x12B0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PlayerResource::C_PlayerResource(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412E30
// Name: _dynamic_initializer_for____g_C_PointCameraClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PointCameraClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PointCameraClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PointCameraClientClass;
  return result;
}
