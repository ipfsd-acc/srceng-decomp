// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/clientmode_csnormal.cpp
// Functions: 99
// ============================================================

#include "game\client\cstrike15\clientmode_csnormal.h"

//------------------------------------------------------------------------------
// Address: 0x10010BC0
// Name: public: void CHandle<class C_BaseEntity>::Set(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHandle<C_BaseEntity>::Set(CHandle<C_BaseEntity> *this, const C_BaseEntity *pVal)
{
  if ( pVal != nullptr )
    this->m_Index = pVal->GetRefEHandle(this: pVal)->m_Index;
  else
    this->m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10010BF0
// Name: public: bool CHandle<class C_BaseEntity>::operator!=(class C_BaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHandle<C_BaseEntity>::operator!=(CHandle<C_BaseEntity> *this, C_BaseEntity *val)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return val != nullptr;
  else
    return g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != val;
}

//------------------------------------------------------------------------------
// Address: 0x1003B580
// Name: public: bool CHandle<class C_BaseEntity>::operator!(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHandle<C_BaseEntity>::operator!(CHandle<C_BaseEntity> *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_Index;
  return m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005DF50
// Name: public: virtual float ClientModeCSNormal::GetBlurFade(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ClientModeCSNormal::GetBlurFade(C_BaseCombatWeapon *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1005FDA0
// Name: public: class CBaseHandle const __near & CHandle<class C_ViewmodelAttachmentModel>::operator=(class C_ViewmodelAttachmentModel const __near *)
// Source: json
//------------------------------------------------------------------------------
CHandle<C_BaseEntity> *__thiscall CHandle<C_ViewmodelAttachmentModel>::operator=(
        CHandle<C_BaseEntity> *this,
        const C_BaseEntity *val)
{
  if ( val != nullptr )
    this->m_Index = val->GetRefEHandle(this: val)->m_Index;
  else
    this->m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008EAA0
// Name: public: CHandle<class C_PointCommentaryNode>::operator class C_PointCommentaryNode __near *(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(
        CHandle<C_BaseCombatWeapon> *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101C0210
// Name: public: static char const __near * CounterStrikeViewport::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CounterStrikeViewport::GetPanelClassName()
{
  return "CounterStrikeViewport";
}

//------------------------------------------------------------------------------
// Address: 0x101C0220
// Name: public: static char const __near * RemapText_t::RemapRawText(struct RemapText_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__usercall RemapText_t::RemapRawText@<eax>(
        const char *a1@<ebx>,
        RemapText_t *pRemapTable,
        const char *szRawText)
{
  RemapText_t *i; // esi
  RemapText_t::MatchPolicy_t m_eMatchPolicy; // eax
  __int32 v5; // eax
  bool v6; // al

  for ( i = pRemapTable; i != nullptr; ++i )
  {
    if ( i->m_szRawText == nullptr )
      return szRawText;
    m_eMatchPolicy = i->m_eMatchPolicy;
    if ( m_eMatchPolicy != MATCH_FULL )
    {
      v5 = m_eMatchPolicy - 1;
      if ( v5 != 0 )
      {
        if ( v5 != 1 )
          continue;
        v6 = StringAfterPrefix(str: szRawText, prefix: i->m_szRawText) != nullptr;
      }
      else
      {
        v6 = V_stristr(a1: i->m_szRawText, a2: a1, pStr: szRawText, pSearch: i->m_szRawText) != nullptr;
      }
    }
    else
    {
      v6 = _V_stricmp(s1: szRawText, s2: i->m_szRawText) == 0;
    }
    if ( v6 )
      return i->m_szRemapText;
  }
  return szRawText;
}

//------------------------------------------------------------------------------
// Address: 0x101C0290
// Name: class IClientMode __near * GetClientMode(void)
// Source: json
//------------------------------------------------------------------------------
IClientMode *__cdecl GetClientMode()
{
  return g_pClientMode[0];
}

//------------------------------------------------------------------------------
// Address: 0x101C02A0
// Name: public: virtual class ClientClass __near * C_WeaponCycler::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponCycler::GetClientClass(C_WeaponCycler *this)
{
  return &__g_C_WeaponCyclerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101C0390
// Name: public: virtual struct datamap_t __near * C_WeaponCycler::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponCycler::GetPredDescMap(C_WeaponCycler *this)
{
  return &C_WeaponCycler::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x101C03A0
// Name: CC_WeaponCyclerFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponCyclerFactory()
{
  C_BaseCombatWeapon *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_BaseCombatWeapon *)C_BaseEntity::operator new(stAllocateBlock: 0xD58u);
  v1 = &v0->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_BaseCombatWeapon::C_BaseCombatWeapon(this: v0);
  *v1 = &C_WeaponCycler::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponCycler::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponCycler::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponCycler::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponCycler::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x101C03F0
// Name: public: virtual class ClientClass __near * C_WeaponCubemap::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponCubemap::GetClientClass(C_WeaponCubemap *this)
{
  return &__g_C_WeaponCubemapClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101C04E0
// Name: public: virtual struct datamap_t __near * C_WeaponCubemap::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponCubemap::GetPredDescMap(C_WeaponCubemap *this)
{
  return &C_WeaponCubemap::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x101C04F0
// Name: CC_WeaponCubemapFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponCubemapFactory()
{
  C_BaseCombatWeapon *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_BaseCombatWeapon *)C_BaseEntity::operator new(stAllocateBlock: 0xD58u);
  v1 = &v0->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_BaseCombatWeapon::C_BaseCombatWeapon(this: v0);
  *v1 = &C_WeaponCubemap::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponCubemap::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponCubemap::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponCubemap::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponCubemap::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x101C0540
// Name: void SetBuyData(class ConVar const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall SetBuyData(int a1@<ebx>, const ConVar *buyVar, const char *filename)
{
  char *m_pszString; // eax
  const char *FileForMe; // edi
  const char *v5; // eax
  char *v6; // esi
  char i; // bl
  char token[256]; // [esp+4h] [ebp-200h] BYREF
  char buystring[256]; // [esp+104h] [ebp-100h] BYREF

  if ( (buyVar->m_nFlags & 0x1000) == 0 )
  {
    m_pszString = buyVar->m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr || *m_pszString == 0 )
    {
      FileForMe = (const char *)UTIL_LoadFileForMe(filename, pLength: nullptr);
      if ( FileForMe != nullptr )
      {
        v5 = (const char *)((int (__thiscall *)(const ConVar *, int))buyVar->GetName)(a1: buyVar, a2: a1);
        V_snprintf(pDest: buystring, maxLen: 256, pFormat: "setinfo %s \"", v5);
        v6 = (char *)engine->ParseFile(this: engine, a2: FileForMe, a3: token, a4: 256);
        for ( i = 1; v6 != nullptr; v6 = (char *)engine->ParseFile(this: engine, a2: v6, a3: token, a4: 256) )
        {
          if ( i != 0 )
            i = 0;
          else
            V_strncat(pDest: buystring, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
          V_strncat(pDest: buystring, pSrc: token, destBufferSize: 0x100u, max_chars_to_copy: -1);
        }
        UTIL_FreeFile(buffer: (unsigned __int8 *)v6);
        V_strncat(pDest: buystring, pSrc: "\"", destBufferSize: 0x100u, max_chars_to_copy: -1);
        engine->ClientCmd(this: engine, a2: buystring);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0670
// Name: public: virtual void CCSModeManager::LevelInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSModeManager::LevelInit(CCSModeManager *this@<ecx>, int a2@<ebx>, int a3@<edi>, const char *newmap)
{
  char *m_pszString; // eax
  unsigned __int8 *FileForMe; // esi
  const char *v6; // eax
  char *v7; // esi
  char i; // bl
  int v9; // [esp-8h] [ebp-208h]
  char pSrc[256]; // [esp+0h] [ebp-200h] BYREF
  char pDest[256]; // [esp+100h] [ebp-100h] BYREF

  g_pClientMode[0]->LevelInit(this: g_pClientMode[0], a2: newmap);
  if ( (cl_autobuy.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = cl_autobuy.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr || *m_pszString == 0 )
    {
      FileForMe = UTIL_LoadFileForMe(a1: a3, filename: "autobuy.txt", pLength: nullptr);
      if ( FileForMe != nullptr )
      {
        v6 = (const char *)((int (__thiscall *)(ConVar *, int))cl_autobuy.GetName)(a1: &cl_autobuy, a2);
        V_snprintf(pDest, maxLen: 0x100u, pFormat: "setinfo %s \"", v6);
        v7 = (char *)engine->ParseFile(this: engine, a2: FileForMe, a3: pSrc, a4: 256);
        for ( i = 1; v7 != nullptr; v7 = (char *)engine->ParseFile(this: engine, a2: v7, a3: pSrc, a4: 256) )
        {
          if ( i != 0 )
            i = 0;
          else
            V_strncat(pDest, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
          V_strncat(pDest, pSrc, destBufferSize: 0x100u, max_chars_to_copy: -1);
        }
        UTIL_FreeFile(buffer: (unsigned __int8 *)v7);
        V_strncat(pDest, pSrc: "\"", destBufferSize: 0x100u, max_chars_to_copy: -1);
        engine->ClientCmd(this: engine, a2: pDest);
        a2 = v9;
      }
    }
  }
  SetBuyData(a1: a2, buyVar: &cl_rebuy, filename: "rebuy.txt");
  if ( g_nKillCamMode > 0 )
    g_bForceCLPredictOff = false;
  g_nKillCamMode = 0;
  g_nKillCamTarget1 = 0;
  g_nKillCamTarget2 = 0;
  if ( cl_detail_max_sway.m_pParent->m_Value.m_fValue == 0.0
    && cl_detail_avoid_radius.m_pParent->m_Value.m_fValue == 0.0
    && cl_detail_avoid_force.m_pParent->m_Value.m_fValue == 0.0
    && cl_detail_avoid_recover_speed.m_pParent->m_Value.m_fValue == 0.0 )
  {
    ConVar::SetValue(this: (ConVar *)&cl_detail_max_sway.IConVar, value: "5");
    ConVar::SetValue(this: (ConVar *)&cl_detail_avoid_radius.IConVar, value: "64");
    ConVar::SetValue(this: (ConVar *)&cl_detail_avoid_force.IConVar, value: "0.4");
    ConVar::SetValue(this: (ConVar *)&cl_detail_avoid_recover_speed.IConVar, value: "0.25");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0890
// Name: public: virtual void CCSModeManager::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSModeManager::LevelShutdown(CCSModeManager *this)
{
  g_pClientMode[0]->LevelShutdown(this: g_pClientMode[0]);
}

//------------------------------------------------------------------------------
// Address: 0x101C08A0
// Name: public: virtual wchar_t __near * ClientModeCSNormal::GetServerName(void)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall ClientModeCSNormal::GetServerName(ClientModeCSNormal *this)
{
  return this->m_pServerName;
}

//------------------------------------------------------------------------------
// Address: 0x101C08B0
// Name: public: virtual wchar_t __near * ClientModeCSNormal::GetMapName(void)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall ClientModeCSNormal::GetMapName(ClientModeCSNormal *this)
{
  return this->m_pMapName;
}

//------------------------------------------------------------------------------
// Address: 0x101C08C0
// Name: public: virtual int ClientModeCSNormal::KeyInput(int,enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ClientModeCSNormal::KeyInput(
        ClientModeCSNormal *this,
        int down,
        ButtonCode_t keynum,
        const char *pszCurrentBinding)
{
  if ( g_pGameRules != nullptr && C_CSGameRules::IsLogoMap(this: (C_CSGameRules *)g_pGameRules) )
    return 1;
  else
    return ClientModeShared::KeyInput(this, down, keynum, pszCurrentBinding);
}

//------------------------------------------------------------------------------
// Address: 0x101C0900
// Name: public: static char const __near * ClientModeCSFullscreen::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ClientModeCSFullscreen::GetPanelClassName()
{
  return "ClientModeCSFullscreen";
}

//------------------------------------------------------------------------------
// Address: 0x101C0910
// Name: class IClientMode __near * GetFullscreenClientMode(void)
// Source: json
//------------------------------------------------------------------------------
ClientModeCSFullscreen *__cdecl GetFullscreenClientMode()
{
  return &g_ClientModeFullscreen;
}

//------------------------------------------------------------------------------
// Address: 0x101C0920
// Name: class IClientMode __near * GetClientModeNormal(void)
// Source: json
//------------------------------------------------------------------------------
ClientModeShared *__cdecl GetClientModeNormal()
{
  return &g_ClientModeNormal;
}

//------------------------------------------------------------------------------
// Address: 0x101C0930
// Name: public: virtual bool ClientModeCSNormal::ShouldDrawViewModel(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ClientModeCSNormal::ShouldDrawViewModel(ClientModeCSNormal *this)
{
  C_CSPlayer *LocalPlayer; // esi
  C_GameRules *v3; // edi
  C_BaseCombatWeapon *ActiveCSWeapon; // eax
  bool result; // al
  float v6; // [esp+8h] [ebp-8h]

  LocalPlayer = CClientTools::GetLocalPlayer();
  result = (LocalPlayer == nullptr
         || (v3 = g_pGameRules, (v6 = LocalPlayer->GetFOV(this: LocalPlayer)) == (double)v3->DefaultFOV(this: v3))
         || (ActiveCSWeapon = C_CSPlayer::GetActiveCSWeapon(this: LocalPlayer)) == nullptr
         || ((unsigned __int8 (__thiscall *)(C_BaseCombatWeapon *))ActiveCSWeapon->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetSoundSpatialization)(a1: ActiveCSWeapon) == 0)
        && CMoveHelperClient::PlayerFallingDamage((vgui::PropertySheet *)this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C09B0
// Name: public: virtual bool ClientModeCSNormal::CanRecordDemo(char __near *,int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall ClientModeCSNormal::CanRecordDemo(ClientModeCSNormal *this, char *errorMsg, int length)
{
  C_CSPlayer *LocalPlayer; // esi
  C_BaseEntity *v5; // eax
  char *Classname; // eax
  C_BaseEntityIterator it; // [esp+4h] [ebp-4h] BYREF

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer == nullptr || !LocalPlayer->IsAlive(this: LocalPlayer) )
    return 1;
  if ( LocalPlayer->m_flFlashBangTime > *(float *)(gpGlobals.m_Index + 12) )
  {
    V_strncpy(pDest: errorMsg, pSrc: "Cannot record demos while blind.", maxLen: length);
    return 0;
  }
  C_BaseEntityIterator::C_BaseEntityIterator(this: &it);
  v5 = C_BaseEntityIterator::Next(this: &it);
  if ( v5 == nullptr )
    return 1;
  while ( 1 )
  {
    Classname = C_BaseEntity::GetClassname(this: v5);
    if ( _V_strcmp(s1: Classname, s2: "class C_ParticleSmokeGrenade") == 0 )
      break;
    v5 = C_BaseEntityIterator::Next(this: &it);
    if ( v5 == nullptr )
      return 1;
  }
  V_strncpy(pDest: errorMsg, pSrc: "Cannot record demos while a smoke grenade is active.", maxLen: length);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C0A70
// Name: public: virtual void ClientModeCSNormal::SetServerName(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSNormal::SetServerName(ClientModeCSNormal *this, wchar_t *name)
{
  V_wcsncpy(pDest: this->m_pServerName, pSrc: name, maxLenInBytes: 0x200u);
}

//------------------------------------------------------------------------------
// Address: 0x101C0A90
// Name: public: virtual void ClientModeCSNormal::SetMapName(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSNormal::SetMapName(ClientModeCSNormal *this, wchar_t *name)
{
  V_wcsncpy(pDest: this->m_pMapName, pSrc: name, maxLenInBytes: 0x200u);
}

//------------------------------------------------------------------------------
// Address: 0x101C0AB0
// Name: void __MsgFunc_MatchEndConditions(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_MatchEndConditions(bf_read *msg)
{
  int m_nBitsAvail; // esi
  unsigned int v3; // ecx
  const unsigned int *v4; // edx
  const unsigned int *v5; // esi
  const unsigned int *m_pDataIn; // ecx
  unsigned int m_nInBufWord; // edi
  int v8; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int v10; // esi
  unsigned int v11; // ebx
  int v12; // esi
  unsigned int v13; // ecx
  const unsigned int *v14; // edx
  const unsigned int *v15; // esi
  const unsigned int *v16; // ecx
  unsigned int v17; // edi
  int v18; // edx
  const unsigned int *v19; // esi
  unsigned int v20; // esi
  unsigned int v21; // ebx
  int v22; // esi
  unsigned int v23; // ecx
  const unsigned int *v24; // edx
  const unsigned int *v25; // esi
  const unsigned int *v26; // ecx
  unsigned int v27; // edi
  int v28; // edx
  const unsigned int *v29; // esi
  unsigned int v30; // esi
  unsigned int v31; // ebx
  int v32; // esi
  unsigned int v33; // ecx
  int v34; // edi
  const unsigned int *v35; // edx
  const unsigned int *v36; // esi
  const unsigned int *v37; // ecx
  unsigned int v38; // edi
  int v39; // edx
  const unsigned int *v40; // esi
  unsigned int v41; // esi
  unsigned int v42; // ebx
  IGameEvent *v43; // esi
  int v44; // [esp+Ch] [ebp-8h]
  int v45; // [esp+10h] [ebp-4h]
  bf_read *msga; // [esp+1Ch] [ebp+8h]

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pDataIn = msg->m_pDataIn;
    m_nInBufWord = msg->m_nInBufWord;
    v8 = 32 - m_nBitsAvail;
    m_pBufferEnd = msg->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      msga = nullptr;
    }
    else
    {
      v10 = msg->m_nInBufWord;
      v11 = (v10 & CBitBuffer::s_nMaskTable[v8]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v8;
      msga = (bf_read *)(v11 | m_nInBufWord);
      msg->m_nInBufWord = v10 >> v8;
    }
    goto LABEL_19;
  }
  v3 = msg->m_nInBufWord;
  msg->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v4 = msg->m_pDataIn;
    v5 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v4 == v5 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v4 + 1;
      msga = (bf_read *)v3;
    }
    else
    {
      if ( v4 <= v5 )
      {
        msg->m_nInBufWord = *v4;
        msg->m_pDataIn = v4 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msga = (bf_read *)v3;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    msga = (bf_read *)v3;
  }
LABEL_19:
  v12 = msg->m_nBitsAvail;
  if ( v12 < 32 )
  {
    v16 = msg->m_pDataIn;
    v17 = msg->m_nInBufWord;
    v18 = 32 - v12;
    v19 = msg->m_pBufferEnd;
    if ( v16 == v19 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v16 > v19 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_34;
      }
      msg->m_nInBufWord = *v16;
    }
    msg->m_pDataIn = v16 + 1;
LABEL_34:
    if ( msg->m_bOverflow )
    {
      v45 = 0;
    }
    else
    {
      v20 = msg->m_nInBufWord;
      v21 = (v20 & CBitBuffer::s_nMaskTable[v18]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v18;
      v45 = v21 | v17;
      msg->m_nInBufWord = v20 >> v18;
    }
    goto LABEL_37;
  }
  v13 = msg->m_nInBufWord;
  msg->m_nBitsAvail = v12 - 32;
  if ( v12 == 32 )
  {
    v14 = msg->m_pDataIn;
    v15 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v14 == v15 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v14 + 1;
      v45 = v13;
    }
    else
    {
      if ( v14 <= v15 )
      {
        msg->m_nInBufWord = *v14;
        msg->m_pDataIn = v14 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v45 = v13;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    v45 = v13;
  }
LABEL_37:
  v22 = msg->m_nBitsAvail;
  if ( v22 < 32 )
  {
    v26 = msg->m_pDataIn;
    v27 = msg->m_nInBufWord;
    v28 = 32 - v22;
    v29 = msg->m_pBufferEnd;
    if ( v26 == v29 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v26 > v29 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_52;
      }
      msg->m_nInBufWord = *v26;
    }
    msg->m_pDataIn = v26 + 1;
LABEL_52:
    if ( msg->m_bOverflow )
    {
      v44 = 0;
    }
    else
    {
      v30 = msg->m_nInBufWord;
      v31 = (v30 & CBitBuffer::s_nMaskTable[v28]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v28;
      v44 = v31 | v27;
      msg->m_nInBufWord = v30 >> v28;
    }
    goto LABEL_55;
  }
  v23 = msg->m_nInBufWord;
  msg->m_nBitsAvail = v22 - 32;
  if ( v22 == 32 )
  {
    v24 = msg->m_pDataIn;
    v25 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v24 == v25 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v24 + 1;
      v44 = v23;
    }
    else
    {
      if ( v24 <= v25 )
      {
        msg->m_nInBufWord = *v24;
        msg->m_pDataIn = v24 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v44 = v23;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    v44 = v23;
  }
LABEL_55:
  v32 = msg->m_nBitsAvail;
  if ( v32 < 32 )
  {
    v37 = msg->m_pDataIn;
    v38 = msg->m_nInBufWord;
    v39 = 32 - v32;
    v40 = msg->m_pBufferEnd;
    if ( v37 == v40 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v37 > v40 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_70;
      }
      msg->m_nInBufWord = *v37;
    }
    msg->m_pDataIn = v37 + 1;
LABEL_70:
    if ( msg->m_bOverflow )
    {
      v34 = 0;
    }
    else
    {
      v41 = msg->m_nInBufWord;
      v42 = (v41 & CBitBuffer::s_nMaskTable[v39]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v39;
      v34 = v42 | v38;
      msg->m_nInBufWord = v41 >> v39;
    }
    goto LABEL_73;
  }
  v33 = msg->m_nInBufWord;
  msg->m_nBitsAvail = v32 - 32;
  if ( v32 == 32 )
  {
    v35 = msg->m_pDataIn;
    v36 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v35 == v36 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v35 + 1;
      v34 = v33;
    }
    else
    {
      if ( v35 <= v36 )
      {
        msg->m_nInBufWord = *v35;
        msg->m_pDataIn = v35 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v34 = v33;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    v34 = v33;
  }
LABEL_73:
  v43 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "match_end_conditions", a3: 0, a4: 0);
  if ( v43 != nullptr )
  {
    v43->SetInt(this: v43, a2: "frags", a3: (int)msga);
    v43->SetInt(this: v43, a2: "max_rounds", a3: v45);
    v43->SetInt(this: v43, a2: "win_rounds", a3: v44);
    v43->SetInt(this: v43, a2: "time", a3: v34);
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v43);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0EA0
// Name: public: bool C_BasePlayer::ShouldAnnounceAchievement(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BasePlayer::ShouldAnnounceAchievement(C_BasePlayer *this)
{
  return *(float *)(gpGlobals.m_Index + 12) > this->m_flNextAchievementAnnounceTime;
}

//------------------------------------------------------------------------------
// Address: 0x101C0F00
// Name: void MsgFunc_KillCam(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MsgFunc_KillCam(bf_read *msg)
{
  C_BasePlayer *LocalPlayer; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v8; // edx
  const unsigned int *v9; // esi
  unsigned int v10; // edi
  int v11; // edx
  const unsigned int *v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  int v15; // ecx
  unsigned int v16; // edx
  int v17; // esi
  int v18; // ecx
  int v19; // ecx
  const unsigned int *v20; // ecx
  const unsigned int *v21; // edx
  unsigned int v22; // edx
  const unsigned int *v23; // esi
  unsigned int v24; // edi
  int v25; // edx
  const unsigned int *v26; // ecx
  unsigned int v27; // esi
  unsigned int v28; // ebx
  int v29; // ecx
  unsigned int v30; // edx
  int v31; // esi
  int v32; // ecx
  const unsigned int *v33; // ecx
  const unsigned int *v34; // edx
  unsigned int v35; // edx
  const unsigned int *v36; // esi
  unsigned int v37; // edi
  int v38; // edx
  const unsigned int *v39; // ecx
  unsigned int v40; // esi
  unsigned int v41; // ebx

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer == nullptr || !LocalPlayer->IsPlayer(this: LocalPlayer) )
    return;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = msg->m_nInBufWord;
    v4 = (unsigned __int8)m_nInBufWord;
    v5 = m_nBitsAvail - 8;
    msg->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      msg->m_nInBufWord = m_nInBufWord >> 8;
    }
    else
    {
      m_pDataIn = msg->m_pDataIn;
      m_pBufferEnd = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v8 = *m_pDataIn;
        msg->m_pDataIn = m_pDataIn + 1;
        msg->m_nInBufWord = v8;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
    }
    goto LABEL_20;
  }
  v9 = msg->m_pBufferEnd;
  v10 = msg->m_nInBufWord;
  v11 = 8 - m_nBitsAvail;
  v12 = msg->m_pDataIn;
  if ( v12 == v9 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v12 > v9 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_17;
    }
    msg->m_nInBufWord = *v12;
  }
  msg->m_pDataIn = v12 + 1;
LABEL_17:
  if ( msg->m_bOverflow )
  {
    v4 = 0;
  }
  else
  {
    v13 = msg->m_nInBufWord;
    v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v11;
    msg->m_nInBufWord = v13 >> v11;
    v4 = v14 | v10;
  }
LABEL_20:
  if ( v4 != g_nKillCamMode )
  {
    if ( g_nKillCamMode != 0 )
    {
      if ( v4 == 0 )
        g_bForceCLPredictOff = false;
    }
    else
    {
      g_bForceCLPredictOff = true;
    }
    g_nKillCamMode = v4;
  }
  v15 = msg->m_nBitsAvail;
  if ( v15 < 8 )
  {
    v23 = msg->m_pBufferEnd;
    v24 = msg->m_nInBufWord;
    v25 = 8 - v15;
    v26 = msg->m_pDataIn;
    if ( v26 == v23 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v26 > v23 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_41;
      }
      msg->m_nInBufWord = *v26;
    }
    msg->m_pDataIn = v26 + 1;
LABEL_41:
    if ( msg->m_bOverflow )
    {
      v19 = 0;
    }
    else
    {
      v27 = msg->m_nInBufWord;
      v28 = (v27 & CBitBuffer::s_nMaskTable[v25]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v25;
      v19 = v28 | v24;
      msg->m_nInBufWord = v27 >> v25;
    }
    goto LABEL_44;
  }
  v16 = msg->m_nInBufWord;
  v17 = (unsigned __int8)v16;
  v18 = v15 - 8;
  msg->m_nBitsAvail = v18;
  if ( v18 != 0 )
  {
    msg->m_nInBufWord = v16 >> 8;
    v19 = (unsigned __int8)v16;
  }
  else
  {
    v20 = msg->m_pDataIn;
    v21 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      msg->m_pDataIn = v20 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v19 = v17;
    }
    else
    {
      if ( v20 <= v21 )
      {
        v22 = *v20;
        msg->m_pDataIn = v20 + 1;
        msg->m_nInBufWord = v22;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v19 = v17;
    }
  }
LABEL_44:
  g_nKillCamTarget1 = v19;
  v29 = msg->m_nBitsAvail;
  if ( v29 < 8 )
  {
    v36 = msg->m_pBufferEnd;
    v37 = msg->m_nInBufWord;
    v38 = 8 - v29;
    v39 = msg->m_pDataIn;
    if ( v39 == v36 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v39 > v36 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_59;
      }
      msg->m_nInBufWord = *v39;
    }
    msg->m_pDataIn = v39 + 1;
LABEL_59:
    if ( msg->m_bOverflow )
    {
      g_nKillCamTarget2 = 0;
    }
    else
    {
      v40 = msg->m_nInBufWord;
      v41 = (v40 & CBitBuffer::s_nMaskTable[v38]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v38;
      msg->m_nInBufWord = v40 >> v38;
      g_nKillCamTarget2 = v41 | v37;
    }
    return;
  }
  v30 = msg->m_nInBufWord;
  v31 = (unsigned __int8)v30;
  v32 = v29 - 8;
  msg->m_nBitsAvail = v32;
  if ( v32 != 0 )
  {
    msg->m_nInBufWord = v30 >> 8;
    g_nKillCamTarget2 = (unsigned __int8)v30;
  }
  else
  {
    v33 = msg->m_pDataIn;
    v34 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v33 == v34 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v33 + 1;
      g_nKillCamTarget2 = v31;
    }
    else
    {
      if ( v33 <= v34 )
      {
        v35 = *v33;
        msg->m_pDataIn = v33 + 1;
        msg->m_nInBufWord = v35;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      g_nKillCamTarget2 = v31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C1220
// Name: void MsgFunc_DisplayInventory(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MsgFunc_DisplayInventory(bf_read *msg)
{
  unsigned int m_nInBufWord; // ecx
  int v2; // edx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  C_BasePlayer *LocalPlayer; // eax
  C_CSPlayer *v7; // esi
  bool showPistol; // [esp+Ch] [ebp+8h]

  m_nInBufWord = msg->m_nInBufWord;
  v2 = m_nInBufWord & 1;
  if ( msg->m_nBitsAvail-- == 1 )
  {
    m_pDataIn = msg->m_pDataIn;
    m_pBufferEnd = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      msg->m_nInBufWord = *m_pDataIn;
      msg->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
  }
  else
  {
    msg->m_nInBufWord = m_nInBufWord >> 1;
  }
  showPistol = v2 != 0;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v7 = (C_CSPlayer *)LocalPlayer;
  if ( LocalPlayer != nullptr && LocalPlayer->IsPlayer(this: LocalPlayer) )
    C_CSPlayer::DisplayInventory(this: v7, showPistol);
}

//------------------------------------------------------------------------------
// Address: 0x101C12C0
// Name: public: virtual void CCSModeManager::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSModeManager::Init(CCSModeManager *this)
{
  CPanelMetaClassMgrImp *v1; // eax

  g_pClientMode[0] = &g_ClientModeNormal;
  v1 = PanelMetaClassMgr();
  v1->LoadMetaClassDefinitionFile(this: v1, a2: "scripts/vgui_screens.txt");
}

//------------------------------------------------------------------------------
// Address: 0x101C12E0
// Name: public: CounterStrikeViewport::CounterStrikeViewport(void)
// Source: json
//------------------------------------------------------------------------------
CounterStrikeViewport *__thiscall CounterStrikeViewport::CounterStrikeViewport(CounterStrikeViewport *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi

  CBaseViewport::CBaseViewport(this);
  this->CBaseViewport::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CounterStrikeViewport_vtbl *)&CounterStrikeViewport::`vftable'{for `vgui::EditablePanel'};
  this->CBaseViewport::IViewPort::__vftable = (IViewPort_vtbl *)&CounterStrikeViewport::`vftable'{for `IViewPort'};
  this->CBaseViewport::CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CounterStrikeViewport::`vftable'{for `CGameEventListener'};
  if ( `CounterStrikeViewport::ChainToMap'::`2'::chained == 0 )
  {
    `CounterStrikeViewport::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CounterStrikeViewport");
    v2->pfnClassName = CounterStrikeViewport::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseViewport");
  }
  if ( `CounterStrikeViewport::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CounterStrikeViewport::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CounterStrikeViewport");
    v3->pfnClassName = CounterStrikeViewport::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "CBaseViewport");
  }
  if ( `CounterStrikeViewport::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CounterStrikeViewport::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CounterStrikeViewport");
    v4->pfnClassName = CounterStrikeViewport::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseViewport");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C13B0
// Name: public: virtual int CBaseViewport::GetViewPortScheme(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseViewport::GetViewPortScheme(CBaseViewport *this)
{
  return this->m_pBackGround->GetScheme(this: this->m_pBackGround);
}

//------------------------------------------------------------------------------
// Address: 0x101C13C0
// Name: public: virtual unsigned int CBaseViewport::GetViewPortPanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseViewport::GetViewPortPanel(CBaseViewport *this)
{
  return this->m_pBackGround->GetVParent(this: this->m_pBackGround);
}

//------------------------------------------------------------------------------
// Address: 0x101C13D0
// Name: public: virtual void CounterStrikeViewport::ShowBackGround(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CounterStrikeViewport::ShowBackGround(CounterStrikeViewport *this, bool bShow)
{
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)&this->m_InternalMouseDoublePressed_register + 132))(
    a1: *(_DWORD *)&this->m_InternalMouseDoublePressed_register,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101C13F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CounterStrikeViewport::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CounterStrikeViewport::GetMessageMap(CounterStrikeViewport *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CounterStrikeViewport::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CounterStrikeViewport::GetMessageMap'::`2'::s_pMap;
  `CounterStrikeViewport::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CounterStrikeViewport");
  `CounterStrikeViewport::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1420
// Name: public: virtual struct PanelAnimationMap __near * CounterStrikeViewport::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CounterStrikeViewport::GetAnimMap(CounterStrikeViewport *this)
{
  return FindOrAddPanelAnimationMap(className: "CounterStrikeViewport");
}

//------------------------------------------------------------------------------
// Address: 0x101C1430
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CounterStrikeViewport::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CounterStrikeViewport::GetKBMap(CounterStrikeViewport *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CounterStrikeViewport::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CounterStrikeViewport::GetKBMap'::`2'::s_pMap;
  `CounterStrikeViewport::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CounterStrikeViewport");
  `CounterStrikeViewport::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1460
// Name: public: virtual void ClientModeCSNormal::InitViewport(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSNormal::InitViewport(ClientModeCSNormal *this, bool bOnlyBaseClass)
{
  CounterStrikeViewport *v3; // eax
  CounterStrikeViewport *v4; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( !bOnlyBaseClass )
  {
    v3 = (CounterStrikeViewport *)MemAlloc_Alloc(nSize: 0x1F0u);
    if ( v3 != nullptr )
      v4 = CounterStrikeViewport::CounterStrikeViewport(this: v3);
    else
      v4 = nullptr;
    this->m_pViewport = v4;
    v4->Start(this: v4, a2: gameuifuncs, a3: gameeventmanager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C14B0
// Name: public: virtual void ClientModeCSNormal::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSNormal::Update(ClientModeCSNormal *this)
{
  C_BasePlayer *LocalPlayer; // eax
  C_PostProcessController *ActivePostProcessController; // eax
  PostProcessParameters_t defaultParams; // [esp+4h] [ebp-2Ch] BYREF

  ClientModeShared::Update(this);
  if ( g_pGameRules != nullptr && C_CSGameRules::IsLogoMap(this: (C_CSGameRules *)g_pGameRules) )
    this->m_pViewport->SetVisible(this: this->m_pViewport, a2: false);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    ActivePostProcessController = C_BasePlayer::GetActivePostProcessController(this: LocalPlayer);
    if ( ActivePostProcessController != nullptr )
    {
      SetPostProcessParams(pPostProcessParameters: &ActivePostProcessController->m_PostProcessParameters);
    }
    else
    {
      memset(dst: (int)&defaultParams, value: nullptr, count: sizeof(defaultParams));
      defaultParams.m_flParameters[3] = 0.80000001;
      defaultParams.m_flParameters[4] = 1.1;
      SetPostProcessParams(pPostProcessParameters: &defaultParams);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C1550
// Name: public: ClientModeCSFullscreen::ClientModeCSFullscreen(void)
// Source: json
//------------------------------------------------------------------------------
ClientModeCSFullscreen *__thiscall ClientModeCSFullscreen::ClientModeCSFullscreen(ClientModeCSFullscreen *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi

  ClientModeShared::ClientModeShared(this);
  this->ClientModeCSNormal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->m_hCurrentColorCorrection.m_Index = -1;
  this->ClientModeCSNormal::ClientModeShared::IClientMode::__vftable = (ClientModeCSFullscreen_vtbl *)&ClientModeCSFullscreen::`vftable'{for `IClientMode'};
  this->ClientModeCSNormal::ClientModeShared::CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&ClientModeCSFullscreen::`vftable'{for `CGameEventListener'};
  this->ClientModeCSNormal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&ClientModeCSFullscreen::`vftable';
  if ( `ClientModeCSFullscreen::ChainToMap'::`2'::chained == 0 )
  {
    `ClientModeCSFullscreen::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "ClientModeCSFullscreen");
    v2->pfnClassName = ClientModeCSFullscreen::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "ClientModeCSNormal");
  }
  if ( `ClientModeCSFullscreen::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `ClientModeCSFullscreen::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "ClientModeCSFullscreen");
    v3->pfnClassName = ClientModeCSFullscreen::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "ClientModeCSNormal");
  }
  if ( `ClientModeCSFullscreen::KB_ChainToMap'::`2'::chained == 0 )
  {
    `ClientModeCSFullscreen::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "ClientModeCSFullscreen");
    v4->pfnClassName = ClientModeCSFullscreen::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ClientModeCSNormal");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C1620
// Name: public: static char const __near * CHudViewport::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudViewport::GetPanelClassName()
{
  return "CHudViewport";
}

//------------------------------------------------------------------------------
// Address: 0x101C1630
// Name: public: static char const __near * FullscreenCSViewport::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl FullscreenCSViewport::GetPanelClassName()
{
  return "FullscreenCSViewport";
}

//------------------------------------------------------------------------------
// Address: 0x101C1690
// Name: public: virtual struct vgui::PanelMessageMap __near * ClientModeCSFullscreen::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall ClientModeCSFullscreen::GetMessageMap(ClientModeCSFullscreen *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`ClientModeCSFullscreen::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `ClientModeCSFullscreen::GetMessageMap'::`2'::s_pMap;
  `ClientModeCSFullscreen::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ClientModeCSFullscreen");
  `ClientModeCSFullscreen::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C16C0
// Name: public: virtual struct PanelAnimationMap __near * ClientModeCSFullscreen::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall ClientModeCSFullscreen::GetAnimMap(ClientModeCSFullscreen *this)
{
  return FindOrAddPanelAnimationMap(className: "ClientModeCSFullscreen");
}

//------------------------------------------------------------------------------
// Address: 0x101C16D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * ClientModeCSFullscreen::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall ClientModeCSFullscreen::GetKBMap(ClientModeCSFullscreen *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`ClientModeCSFullscreen::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `ClientModeCSFullscreen::GetKBMap'::`2'::s_pMap;
  `ClientModeCSFullscreen::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ClientModeCSFullscreen");
  `ClientModeCSFullscreen::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1700
// Name: public: CHudViewport::CHudViewport(void)
// Source: json
//------------------------------------------------------------------------------
CHudViewport *__thiscall CHudViewport::CHudViewport(CHudViewport *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi

  CBaseViewport::CBaseViewport(this);
  this->CBaseViewport::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CHudViewport_vtbl *)&CHudViewport::`vftable'{for `vgui::EditablePanel'};
  this->CBaseViewport::IViewPort::__vftable = (IViewPort_vtbl *)&CHudViewport::`vftable'{for `IViewPort'};
  this->CBaseViewport::CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CHudViewport::`vftable'{for `CGameEventListener'};
  if ( `CHudViewport::ChainToMap'::`2'::chained == 0 )
  {
    `CHudViewport::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CHudViewport");
    v2->pfnClassName = CHudViewport::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseViewport");
  }
  if ( `CHudViewport::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudViewport::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CHudViewport");
    v3->pfnClassName = CHudViewport::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "CBaseViewport");
  }
  if ( `CHudViewport::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudViewport::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudViewport");
    v4->pfnClassName = CHudViewport::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseViewport");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C17D0
// Name: public: virtual void CBaseViewport::ShowBackGround(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewport::ShowBackGround(CBaseViewport *this, int bShow)
{
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->m_InternalMouseDoublePressed_register + 132))(
    a1: *(_DWORD *)&this->m_InternalMouseDoublePressed_register,
    a2: bShow);
}

//------------------------------------------------------------------------------
// Address: 0x101C17F0
// Name: protected: virtual void CHudViewport::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudViewport::ApplySchemeSettings(CHudViewport *this, vgui::IScheme *pScheme)
{
  CHud *Hud; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  Hud = GetHud(nSlot: -1);
  CHud::InitColors(this: Hud, scheme: (int)pScheme);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101C1830
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudViewport::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudViewport::GetMessageMap(CHudViewport *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudViewport::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudViewport::GetMessageMap'::`2'::s_pMap;
  `CHudViewport::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudViewport");
  `CHudViewport::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1860
// Name: public: virtual struct PanelAnimationMap __near * CHudViewport::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudViewport::GetAnimMap(CHudViewport *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudViewport");
}

//------------------------------------------------------------------------------
// Address: 0x101C1870
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudViewport::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudViewport::GetKBMap(CHudViewport *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudViewport::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudViewport::GetKBMap'::`2'::s_pMap;
  `CHudViewport::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudViewport");
  `CHudViewport::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C18A0
// Name: public: virtual void ClientModeCSNormal::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSNormal::OnEvent(ClientModeCSNormal *this, KeyValues *pEvent)
{
  const char *Name; // eax

  Name = KeyValues::GetName(this: pEvent);
  _V_strcmp(s1: Name, s2: "OnSysStorageDevicesChanged");
}

//------------------------------------------------------------------------------
// Address: 0x101C18C0
// Name: public: bool CHandle<class C_ColorCorrection>::operator==(class C_ColorCorrection __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHandle<C_ColorCorrection>::operator==(CHandle<C_ColorCorrection> *this, C_ColorCorrection *val)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return val == nullptr;
  else
    return g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == val;
}

//------------------------------------------------------------------------------
// Address: 0x101C1910
// Name: public: virtual void ClientModeCSNormal::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSNormal::Init(ClientModeCSNormal *this)
{
  IMatchEventsSink *v2; // esi
  IMatchEventsSubscription *v3; // eax
  CHud *Hud; // eax
  CHudElement *Element; // eax
  CHudElement *v6; // esi

  ClientModeShared::Init(this);
  if ( this != nullptr )
    v2 = &this->IMatchEventsSink;
  else
    v2 = nullptr;
  v3 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v3->Subscribe(this: v3, a2: v2);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "round_end", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "round_start", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "round_time_warning",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_team", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_death", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "bomb_planted", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "bomb_exploded", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "bomb_defused", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "hostage_killed", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "hostage_hurt", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "write_game_titledata",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "read_game_titledata",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "switch_team", a4: false);
  CUserMessages::HookMessage(this: usermessages, name: "MatchEndConditions", hook: __MsgFunc_MatchEndConditions);
  CUserMessages::HookMessage(this: usermessages, name: "KillCam", hook: MsgFunc_KillCam);
  if ( this != &g_ClientModeFullscreen )
    CUserMessages::HookMessage(this: usermessages, name: "DisplayInventory", hook: MsgFunc_DisplayInventory);
  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudHintDisplay");
  v6 = Element;
  if ( Element != nullptr )
  {
    CHudElement::RegisterForRenderGroup(this: Element, pszGroupName: "hide_for_scoreboard");
    CHudElement::RegisterForRenderGroup(this: v6, pszGroupName: "hide_for_round_panel");
  }
  this->m_hCurrentColorCorrection.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101C1B00
// Name: public: virtual void ClientModeCSNormal::InitViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSNormal::InitViewport(ClientModeCSNormal *this)
{
  CounterStrikeViewport *v2; // eax
  CounterStrikeViewport *v3; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  v2 = (CounterStrikeViewport *)MemAlloc_Alloc(nSize: 0x1F0u);
  if ( v2 != nullptr )
    v3 = CounterStrikeViewport::CounterStrikeViewport(this: v2);
  else
    v3 = nullptr;
  this->m_pViewport = v3;
  v3->Start(this: v3, a2: gameuifuncs, a3: gameeventmanager);
}

//------------------------------------------------------------------------------
// Address: 0x101C1B50
// Name: public: virtual void ClientModeCSNormal::OnColorCorrectionWeightsReset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSNormal::OnColorCorrectionWeightsReset(ClientModeCSNormal *this)
{
  C_BasePlayer *LocalPlayer; // eax
  CHandle<C_ColorCorrection> *p_m_hCurrentColorCorrection; // ebx
  C_ColorCorrection *ActiveColorCorrection; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v7; // ecx
  CEntInfo *v8; // edx
  unsigned int v9; // eax
  int v10; // ecx
  bool v11; // zf
  C_ColorCorrection **v12; // ecx
  C_ColorCorrection *v13; // ecx
  bool v14; // al

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    p_m_hCurrentColorCorrection = &this->m_hCurrentColorCorrection;
    ActiveColorCorrection = C_BasePlayer::GetActiveColorCorrection(this: LocalPlayer);
    m_Index = this->m_hCurrentColorCorrection.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( ActiveColorCorrection != m_pEntity )
    {
      if ( m_Index != -1 )
      {
        v7 = (unsigned __int16)m_Index;
        v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v9 = HIWORD(m_Index);
        if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
        {
          v10 = v7;
          v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
          v12 = (C_ColorCorrection **)&g_pEntityList->m_EntPtrArray[v10];
          if ( v11 )
            v13 = *v12;
          else
            v13 = nullptr;
          C_ColorCorrection::EnableOnClient(this: v13, bEnable: false, bSkipFade: false);
        }
      }
      if ( ActiveColorCorrection != nullptr )
      {
        v14 = CHandle<C_ColorCorrection>::operator==(this: p_m_hCurrentColorCorrection, val: nullptr);
        C_ColorCorrection::EnableOnClient(this: ActiveColorCorrection, bEnable: true, bSkipFade: v14);
        p_m_hCurrentColorCorrection->m_Index = ActiveColorCorrection->GetRefEHandle(this: ActiveColorCorrection)->m_Index;
      }
      else
      {
        p_m_hCurrentColorCorrection->m_Index = -1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C1C20
// Name: public: FullscreenCSViewport::FullscreenCSViewport(void)
// Source: json
//------------------------------------------------------------------------------
FullscreenCSViewport *__thiscall FullscreenCSViewport::FullscreenCSViewport(FullscreenCSViewport *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi

  CHudViewport::CHudViewport(this);
  this->CHudViewport::CBaseViewport::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (FullscreenCSViewport_vtbl *)&FullscreenCSViewport::`vftable'{for `vgui::EditablePanel'};
  this->CHudViewport::CBaseViewport::IViewPort::__vftable = (IViewPort_vtbl *)&FullscreenCSViewport::`vftable'{for `IViewPort'};
  this->CHudViewport::CBaseViewport::CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&FullscreenCSViewport::`vftable'{for `CGameEventListener'};
  if ( `FullscreenCSViewport::ChainToMap'::`2'::chained == 0 )
  {
    `FullscreenCSViewport::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "FullscreenCSViewport");
    v2->pfnClassName = FullscreenCSViewport::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "CHudViewport");
  }
  if ( `FullscreenCSViewport::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `FullscreenCSViewport::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "FullscreenCSViewport");
    v3->pfnClassName = FullscreenCSViewport::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "CHudViewport");
  }
  if ( `FullscreenCSViewport::KB_ChainToMap'::`2'::chained == 0 )
  {
    `FullscreenCSViewport::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "FullscreenCSViewport");
    v4->pfnClassName = FullscreenCSViewport::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CHudViewport");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C1CF0
// Name: private: virtual void FullscreenCSViewport::InitViewportSingletons(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall FullscreenCSViewport::InitViewportSingletons(FullscreenCSViewport *this)
{
  CBaseViewport::SetAsFullscreenViewportInterface(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C1D00
// Name: private: virtual void FullscreenCSViewport::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FullscreenCSViewport::ApplySchemeSettings(FullscreenCSViewport *this, vgui::IScheme *pScheme)
{
  CHud *Hud; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  Hud = GetHud(nSlot: -1);
  CHud::InitColors(this: Hud, scheme: (int)pScheme);
  this->SetPaintBackgroundEnabled(this, a2: false);
  this->SetMouseInputEnabled(this, a2: false);
  this->SetKeyBoardInputEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101C1D70
// Name: public: virtual struct vgui::PanelMessageMap __near * FullscreenCSViewport::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall FullscreenCSViewport::GetMessageMap(FullscreenCSViewport *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`FullscreenCSViewport::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `FullscreenCSViewport::GetMessageMap'::`2'::s_pMap;
  `FullscreenCSViewport::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "FullscreenCSViewport");
  `FullscreenCSViewport::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1DA0
// Name: public: virtual struct PanelAnimationMap __near * FullscreenCSViewport::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall FullscreenCSViewport::GetAnimMap(FullscreenCSViewport *this)
{
  return FindOrAddPanelAnimationMap(className: "FullscreenCSViewport");
}

//------------------------------------------------------------------------------
// Address: 0x101C1DB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * FullscreenCSViewport::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall FullscreenCSViewport::GetKBMap(FullscreenCSViewport *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`FullscreenCSViewport::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `FullscreenCSViewport::GetKBMap'::`2'::s_pMap;
  `FullscreenCSViewport::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "FullscreenCSViewport");
  `FullscreenCSViewport::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1E10
// Name: public: virtual void ClientModeCSFullscreen::InitViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSFullscreen::InitViewport(ClientModeCSFullscreen *this)
{
  FullscreenCSViewport *v2; // eax
  FullscreenCSViewport *v3; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  v2 = (FullscreenCSViewport *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = FullscreenCSViewport::FullscreenCSViewport(this: v2);
  else
    v3 = nullptr;
  this->m_pViewport = v3;
  v3->Start(this: v3, a2: gameuifuncs, a3: gameeventmanager);
}

//------------------------------------------------------------------------------
// Address: 0x101C1E60
// Name: public: virtual void ClientModeCSFullscreen::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeCSFullscreen::OnEvent(ClientModeCSFullscreen *this, KeyValues *pEvent)
{
  const char *Name; // eax
  const char *v4; // eax
  const char *v5; // eax
  RemapText_t arrText[10]; // [esp+4h] [ebp-80h] BYREF
  IKeyValuesDumpContext pDump; // [esp+7Ch] [ebp-8h] BYREF
  int v8; // [esp+80h] [ebp-4h]
  char *szReason; // [esp+8Ch] [ebp+8h]

  Name = KeyValues::GetName(this: pEvent);
  _V_strcmp(s1: Name, s2: "OnSysStorageDevicesChanged");
  v4 = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: v4, s2: "OnEngineDisconnectReason") == 0 )
  {
    DevMsg(a1: "ClientModeCSNormal::OnEvent");
    pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
    v8 = 1;
    KeyValues::Dump(this: pEvent, &pDump, nIndentLevel: 1);
    szReason = KeyValues::GetString(this: pEvent, keyName: "reason", defaultValue: prType);
    if ( KeyValues::GetString(this: pEvent, keyName: "disconnecthdlr", defaultValue: nullptr) == nullptr )
    {
      arrText[0].m_szRawText = prType;
      arrText[0].m_szRemapText = "#SFUI_DisconnectReason_Unknown";
      arrText[0].m_eMatchPolicy = MATCH_FULL;
      arrText[1].m_szRawText = "Lost connection to LIVE";
      arrText[1].m_szRemapText = "#SFUI_DisconnectReason_LostConnectionToLIVE";
      arrText[1].m_eMatchPolicy = MATCH_FULL;
      arrText[2].m_szRawText = "Player removed from host session";
      arrText[2].m_szRemapText = "#SFUI_DisconnectReason_PlayerRemovedFromSession";
      arrText[2].m_eMatchPolicy = MATCH_SUBSTR;
      arrText[3].m_szRawText = "Connection to server timed out";
      arrText[3].m_szRemapText = "#SFUI_DisconnectReason_DisconnectedFromServer";
      arrText[3].m_eMatchPolicy = MATCH_SUBSTR;
      arrText[4].m_szRawText = "Added to banned list";
      arrText[4].m_szRemapText = "#SFUI_SessionError_Kicked";
      arrText[4].m_eMatchPolicy = MATCH_SUBSTR;
      arrText[5].m_szRawText = "Kicked and banned";
      arrText[5].m_szRemapText = "#SFUI_SessionError_Kicked";
      arrText[5].m_eMatchPolicy = MATCH_SUBSTR;
      arrText[6].m_szRawText = "You have been voted off";
      arrText[6].m_szRemapText = "#SFUI_SessionError_Kicked";
      arrText[6].m_eMatchPolicy = MATCH_SUBSTR;
      arrText[7].m_szRawText = "Player idle";
      arrText[7].m_szRemapText = "#SFUI_DisconnectReason_Idle";
      arrText[7].m_eMatchPolicy = MATCH_SUBSTR;
      arrText[8].m_szRawText = "Kicked by";
      arrText[8].m_szRemapText = "#SFUI_SessionError_Kicked";
      arrText[8].m_eMatchPolicy = MATCH_SUBSTR;
      memset(&arrText[9], 0, sizeof(RemapText_t));
      v5 = RemapText_t::RemapRawText(a1: nullptr, pRemapTable: arrText, szRawText: szReason);
      CCommandMsgBox::CreateAndShow(
        pszTitle: "#SFUI_Disconnect_Title",
        pszMessage: v5,
        showOk: true,
        showCancel: false,
        okCommand: nullptr,
        cancelCommand: nullptr,
        closedCommand: nullptr,
        pszLegend: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C1FC0
// Name: public: virtual void ClientModeCSNormal::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ClientModeCSNormal::FireGameEvent(ClientModeCSNormal *this@<ecx>, int a2@<ebx>, C_BasePlayer *event)
{
  int SplitScreenPlayerSlot; // edi
  CBaseHudChat *v5; // ebx
  C_BasePlayer *LocalPlayer; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // ebx
  int i; // edi
  unsigned int m_Index; // edx
  C_BaseCombatWeapon *v13; // eax
  CParticleMgr *v14; // eax
  int v15; // edi
  CBaseHudChat *v16; // eax
  CBaseHudChat *v17; // ebx
  CCenterPrint *CenterPrint; // eax
  CCenterPrint_vtbl *v19; // edi
  IHudTextMessage_vtbl *v20; // ebx
  int v21; // eax
  int v22; // eax
  CBaseHudChat *v23; // edi
  IVEngineClient_vtbl *v24; // ebx
  int v25; // eax
  int v26; // eax
  C_BaseEntity *v27; // eax
  C_CSPlayer *v28; // eax
  C_BasePlayer *v29; // ebx
  int v30; // esi
  CBaseHudChat_vtbl *v31; // esi
  char *v32; // eax
  CBaseHudChat_vtbl *v33; // esi
  char *v34; // eax
  CCenterPrint *v35; // eax
  int v36; // esi
  CCenterPrint *v37; // eax
  int v38; // esi
  CCenterPrint *v39; // eax
  IVEngineClient_vtbl *v40; // edi
  CClientEntityList *v41; // ebx
  int v42; // eax
  int v43; // eax
  C_BaseEntity *BaseEntity; // eax
  C_CSPlayer *v45; // esi
  C_CSPlayer *v46; // eax
  C_CSGameRules *v47; // esi
  int UserID; // eax
  CHud *Hud; // eax
  CBaseHudChat *Element; // edi
  int (__thiscall *GetIClientEntity)(IGameEvent *, const char *, int); // edx
  int v52; // ebx
  IAchievementMgr *v53; // eax
  CAchievementMgr *v54; // edi
  int v55; // eax
  CBaseAchievement *AchievementByID; // eax
  IAchievement *v57; // edi
  void (__thiscall *OnAchievementAchieved)(C_BasePlayer *, int); // edx
  vgui::ILocalize_vtbl *v59; // esi
  int v60; // eax
  const char *v61; // eax
  CFmtStrN<256> *v62; // eax
  wchar_t *v63; // eax
  vgui::ILocalize_vtbl *v64; // esi
  int v65; // eax
  int v66; // edi
  int v67; // ebx
  KeyValues *v68; // eax
  KeyValues *v69; // esi
  const char *v70; // [esp+18h] [ebp-310h]
  const char *PlayerName; // [esp+24h] [ebp-304h]
  int v72; // [esp+24h] [ebp-304h]
  int v73; // [esp+24h] [ebp-304h]
  CFmtStrN<256> v75; // [esp+34h] [ebp-2F4h] BYREF
  wchar_t wszLocalizedString[128]; // [esp+140h] [ebp-1E8h] BYREF
  char szLocalized[128]; // [esp+240h] [ebp-E8h] BYREF
  wchar_t wszPlayerName[32]; // [esp+2C0h] [ebp-68h] BYREF
  CLocalPlayerFilter filter; // [esp+300h] [ebp-28h] BYREF
  int iAchievement; // [esp+320h] [ebp-8h]
  CBaseHudChat *hudChat; // [esp+324h] [ebp-4h]
  C_BasePlayer *pPlayer; // [esp+330h] [ebp+8h]
  C_BasePlayer *pPlayerb; // [esp+330h] [ebp+8h]
  C_BasePlayer *pPlayerc; // [esp+330h] [ebp+8h]
  C_BasePlayer *pPlayera; // [esp+330h] [ebp+8h]

  hudChat = (CBaseHudChat *)this;
  SplitScreenPlayerSlot = ClientModeShared::GetSplitScreenPlayerSlot(this: (ClientModeCSNormal *)((char *)this - 4));
  if ( SplitScreenPlayerSlot == ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                                  a1: event,
                                  a2: "splitscreenplayer",
                                  a3: 0) )
  {
    v5 = CBaseHudChat::GetHudChat();
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    iAchievement = (int)LocalPlayer;
    CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
    v7 = (const char *)((int (__thiscall *)(C_BasePlayer *))event->SetRefEHandle)(a1: event);
    if ( _V_strcmp(s1: "read_game_titledata", s2: v7) == 0
      || (v8 = (const char *)((int (__thiscall *)(C_BasePlayer *))event->SetRefEHandle)(a1: event),
          _V_strcmp(s1: "write_game_titledata", s2: v8) == 0)
      || LocalPlayer != nullptr && v5 != nullptr )
    {
      v9 = (const char *)((int (__thiscall *)(C_BasePlayer *))event->SetRefEHandle)(a1: event);
      v10 = v9;
      pPlayer = (C_BasePlayer *)v9;
      if ( v9 != nullptr && *v9 != 0 )
      {
        if ( _V_strcmp(s1: "round_start", s2: v9) == 0 )
        {
          C_PhysPropClientside::RecreateAll();
          for ( i = 0; i < g_HostageRagdolls.m_Size; ++i )
          {
            m_Index = g_HostageRagdolls.m_Memory.m_pMemory[i].m_Index;
            if ( m_Index != -1 )
            {
              if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
                && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
              {
                v13 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&g_HostageRagdolls.m_Memory.m_pMemory[i]);
                C_BaseEntity::Remove(this: v13);
              }
              v10 = (const char *)pPlayer;
            }
          }
          g_HostageRagdolls.m_Size = 0;
          engine->ClientCmd(this: engine, a2: "r_cleardecals\n");
          enginesound->StopAllSounds(this: enginesound, a2: true);
          Soundscape_OnStopAllSounds();
          v14 = ParticleMgr();
          CParticleMgr::SetRemoveAllParticleEffects(this: v14);
          C_BaseEntity::EmitSound(
            &filter,
            iEntIndex: -1,
            soundname: "Music.StartRound",
            pOrigin: nullptr,
            soundtime: 0.0,
            duration: nullptr);
          LocalPlayer = (C_BasePlayer *)iAchievement;
        }
        if ( _V_strcmp(s1: "round_time_warning", s2: v10) == 0 )
        {
          C_BaseEntity::EmitSound(
            &filter,
            iEntIndex: -1,
            soundname: "Music.TenSecCount",
            pOrigin: nullptr,
            soundtime: 0.0,
            duration: nullptr);
          C_RecipientFilter::~C_RecipientFilter(this: &filter);
          return;
        }
        if ( _V_strcmp(s1: "round_end", s2: v10) == 0 )
        {
          v15 = ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                  a1: event,
                  a2: "winner",
                  a3: 0);
          v16 = (CBaseHudChat *)((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                                  a1: event,
                                  a2: "reason",
                                  a3: 0);
          v17 = v16;
          hudChat = v16;
          if ( v15 == 3 )
          {
            if ( v16 != (CBaseHudChat *)6 )
            {
              C_BaseEntity::EmitSound(
                &filter,
                iEntIndex: -1,
                soundname: "Event.CTWin",
                pOrigin: nullptr,
                soundtime: 0.0,
                duration: nullptr);
              goto LABEL_29;
            }
            v70 = "Event.BombDefused";
          }
          else
          {
            if ( v15 == 2 )
            {
              C_BaseEntity::EmitSound(
                &filter,
                iEntIndex: -1,
                soundname: "Event.TERWin",
                pOrigin: nullptr,
                soundtime: 0.0,
                duration: nullptr);
              goto LABEL_29;
            }
            if ( v16 == (CBaseHudChat *)15 )
            {
LABEL_29:
              if ( (_S7_22 & 1) == 0 )
              {
                _S7_22 |= 1u;
                ConVarRef::ConVarRef(this: &sv_nowinpanel, pName: "sv_nowinpanel");
              }
              if ( (_S7_22 & 2) == 0 )
              {
                _S7_22 |= 2u;
                ConVarRef::ConVarRef(this: &cl_nowinpanel, pName: "cl_nowinpanel");
              }
              if ( C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules)
                && (v17 == (CBaseHudChat *)7 || v17 == (CBaseHudChat *)8)
                || v17 == (CBaseHudChat *)15
                || sv_nowinpanel.m_pConVarState->m_Value.m_nValue != 0
                || cl_nowinpanel.m_pConVarState->m_Value.m_nValue != 0 )
              {
                CenterPrint = GetCenterPrint();
                v19 = CenterPrint->__vftable;
                pPlayerb = (C_BasePlayer *)CenterPrint;
                v20 = hudtextmessage->__vftable;
                v21 = ((int (__thiscall *)(C_BasePlayer *, const char *, const char *, _DWORD))event->GetClientAlphaProperty)(
                        a1: event,
                        a2: "message",
                        a3: prType,
                        a4: 0);
                v22 = ((int (__thiscall *)(IHudTextMessage *, int))v20->LookupString)(a1: hudtextmessage, a2: v21);
                v19->Print_2(this: (CCenterPrint *)pPlayerb, a2: (char *)v22);
                CCSClientGameStats::UpdateLastMatchStats(this: &g_CSClientGameStats);
                CCSClientGameStats::ResetMatchStats(this: &g_CSClientGameStats);
                v17 = hudChat;
              }
              if ( v17 == (CBaseHudChat *)15 )
              {
                CCSClientGameStats::ResetRoundStats(this: &g_CSClientGameStats);
                C_RecipientFilter::~C_RecipientFilter(this: &filter);
                return;
              }
              goto LABEL_101;
            }
            v70 = "Event.RoundDraw";
          }
          C_BaseEntity::EmitSound(
            &filter,
            iEntIndex: -1,
            soundname: v70,
            pOrigin: nullptr,
            soundtime: 0.0,
            duration: nullptr);
          goto LABEL_29;
        }
        if ( _V_strcmp(s1: "player_team", s2: v10) != 0 )
        {
          if ( _V_strcmp(s1: "bomb_planted", s2: v10) == 0 )
          {
            v35 = GetCenterPrint();
            v35->Print_2(this: v35, a2: "#Cstrike_TitlesTXT_Bomb_Planted");
            C_BaseEntity::EmitSound(
              &filter,
              iEntIndex: -1,
              soundname: "Event.BombPlanted",
              pOrigin: nullptr,
              soundtime: 0.0,
              duration: nullptr);
            C_RecipientFilter::~C_RecipientFilter(this: &filter);
            return;
          }
          if ( _V_strcmp(s1: "bomb_defused", s2: v10) != 0 )
          {
            if ( _V_strcmp(s1: "bomb_exploded", s2: v10) != 0 )
            {
              if ( _V_strcmp(s1: "hostage_killed", s2: v10) != 0 )
              {
                if ( _V_strcmp(s1: "hostage_hurt", s2: v10) != 0 )
                {
                  if ( _V_strcmp(s1: "player_death", s2: v10) != 0 )
                  {
                    if ( _V_strcmp(s1: "player_changename", s2: v10) != 0 )
                    {
                      if ( _V_strcmp(s1: "achievement_earned", s2: v10) != 0 )
                      {
                        if ( _V_strcmp(s1: "write_game_titledata", s2: v10) == 0
                          || _V_strcmp(s1: "read_game_titledata", s2: v10) == 0 )
                        {
                          ((void (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                            a1: event,
                            a2: "controllerId",
                            a3: 0);
                          C_RecipientFilter::~C_RecipientFilter(this: &filter);
                          return;
                        }
                        if ( _V_strcmp(s1: "switch_team", s2: v10) != 0 )
                        {
                          ClientModeShared::FireGameEvent(this: (ClientModeShared *)hudChat, (IGameEvent *)event);
                        }
                        else if ( g_pMatchFramework != nullptr && g_PR != nullptr )
                        {
                          v66 = ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD, int))event->GetIClientEntity)(
                                  a1: event,
                                  a2: "numPlayers",
                                  a3: 0,
                                  a4: a2);
                          v67 = ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                                  a1: event,
                                  a2: "numSpectators",
                                  a3: 0);
                          v68 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                          v69 = v68 != nullptr ? KeyValues::KeyValues(this: v68, setName: "switch_team") : nullptr;
                          KeyValues::SetInt(this: v69, keyName: "members/numPlayers", value: v66);
                          KeyValues::SetInt(this: v69, keyName: "members/numSpectators", value: v67);
                          g_pMatchFramework->UpdateTeamProperties(this: g_pMatchFramework, a2: v69);
                          if ( v69 != nullptr )
                          {
                            KeyValues::deleteThis(this: v69);
                            C_RecipientFilter::~C_RecipientFilter(this: &filter);
                            return;
                          }
                        }
                      }
                      else
                      {
                        Hud = GetHud(nSlot: -1);
                        Element = (CBaseHudChat *)CHud::FindElement(this: Hud, pName: "CHudChat");
                        GetIClientEntity = (int (__thiscall *)(IGameEvent *, const char *, int))event->GetIClientEntity;
                        hudChat = Element;
                        v52 = GetIClientEntity(this: (IGameEvent *)event, a2: "player", a3: 0);
                        pPlayera = UTIL_PlayerByIndex(entindex: v52);
                        iAchievement = ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                                         a1: event,
                                         a2: "achievement",
                                         a3: 0);
                        if ( Element != nullptr && pPlayera != nullptr )
                        {
                          v53 = engine->GetAchievementMgr(this: engine);
                          v54 = (CAchievementMgr *)__RTDynamicCast(
                                                     inptr: v53,
                                                     VfDelta: 0,
                                                     SrcType: &IAchievementMgr `RTTI Type Descriptor',
                                                     TargetType: &CAchievementMgr `RTTI Type Descriptor',
                                                     isReference: 0);
                          if ( v54 != nullptr )
                          {
                            v55 = ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                                    a1: event,
                                    a2: "splitscreenplayer",
                                    a3: 0);
                            AchievementByID = CAchievementMgr::GetAchievementByID(
                                                this: v54,
                                                iAchievementID: iAchievement,
                                                nUserSlot: v55);
                            if ( AchievementByID != nullptr )
                            {
                              v57 = &AchievementByID->IAchievement;
                              if ( AchievementByID != (CBaseAchievement *)-12 )
                              {
                                if ( !pPlayera->IsDormant(this: &pPlayera->IClientNetworkable)
                                  && C_BasePlayer::ShouldAnnounceAchievement(this: pPlayera) )
                                {
                                  OnAchievementAchieved = pPlayera->OnAchievementAchieved;
                                  v72 = iAchievement;
                                  pPlayera->m_flNextAchievementAnnounceTime = *(float *)(gpGlobals.m_Index + 12) + 10.0;
                                  OnAchievementAchieved(this: pPlayera, a2: v72);
                                }
                                if ( g_PR != nullptr )
                                {
                                  v59 = g_pVGuiLocalize->__vftable;
                                  v60 = ((int (__thiscall *)(IGameResources *, int, wchar_t *, int))g_PR->GetPlayerName)(
                                          a1: &g_PR->IGameResources,
                                          a2: v52,
                                          a3: wszPlayerName,
                                          a4: 64);
                                  ((void (__thiscall *)(vgui::ILocalize *, int))v59->ConvertANSIToUnicode)(
                                    a1: g_pVGuiLocalize,
                                    a2: v60);
                                  v61 = v57->GetName(this: v57);
                                  v62 = CFmtStrN<256>::CFmtStrN<256>(this: &v75, pszFormat: "#%s_NAME", v61);
                                  v63 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v62->m_szBuf);
                                  if ( v63 != nullptr )
                                  {
                                    v64 = g_pVGuiLocalize->__vftable;
                                    v65 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *, wchar_t *))g_pVGuiLocalize->Find)(
                                            a1: g_pVGuiLocalize,
                                            a2: "#Achievement_Earned",
                                            a3: 2,
                                            a4: wszPlayerName,
                                            a5: v63);
                                    ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v64->ConstructString_3)(
                                      a1: g_pVGuiLocalize,
                                      a2: wszLocalizedString,
                                      a3: 256,
                                      a4: v65);
                                    ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
                                      a1: g_pVGuiLocalize,
                                      a2: wszLocalizedString,
                                      a3: szLocalized,
                                      a4: 128,
                                      a5: v73);
                                    hudChat->ChatPrintf(this: hudChat, a2: v52, a3: 32, a4: "%s", szLocalized);
                                    C_RecipientFilter::~C_RecipientFilter(this: &filter);
                                    return;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else
                  {
                    v40 = engine->__vftable;
                    v41 = (CClientEntityList *)cl_entitylist.m_Index;
                    v42 = ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                            a1: event,
                            a2: "userid",
                            a3: 0);
                    v43 = v40->GetPlayerForUserID(this: engine, a2: v42);
                    BaseEntity = CClientEntityList::GetBaseEntity(this: v41, entnum: v43);
                    v45 = ToBasePlayer(pEntity: BaseEntity);
                    v46 = ToBasePlayer(pEntity: v45);
                    if ( v46 != nullptr )
                      CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&v46->m_SoundEvents);
                    if ( v45 == C_BasePlayer::GetLocalPlayer(nSlot: -1) )
                    {
                      v47 = (C_CSGameRules *)g_pGameRules;
                      UserID = C_BasePlayer::GetUserID(this: (C_BasePlayer *)iAchievement);
                      C_CSGameRules::CloseBuyMenu(this: v47, nPlayerID: UserID);
                      C_RecipientFilter::~C_RecipientFilter(this: &filter);
                      return;
                    }
                  }
                }
                else
                {
                  v38 = ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                          a1: event,
                          a2: "userid",
                          a3: 0);
                  if ( C_BasePlayer::GetUserID(this: LocalPlayer) == v38 )
                  {
                    v39 = GetCenterPrint();
                    v39->Print_2(this: v39, a2: "#Cstrike_TitlesTXT_Injured_Hostage");
                    C_RecipientFilter::~C_RecipientFilter(this: &filter);
                    return;
                  }
                }
              }
              else
              {
                if ( ((int (__thiscall *)(C_BasePlayer *, int))LocalPlayer->GetObserverMode)(a1: LocalPlayer, a2) != 0
                  || LocalPlayer->GetTeamNumber(this: LocalPlayer) == 3 )
                {
                  C_BaseEntity::EmitSound(
                    &filter,
                    iEntIndex: -1,
                    soundname: "Event.HostageKilled",
                    pOrigin: nullptr,
                    soundtime: 0.0,
                    duration: nullptr);
                }
                v36 = ((int (__thiscall *)(C_BasePlayer *, const char *))event->GetIClientEntity)(
                        a1: event,
                        a2: "userid");
                if ( C_BasePlayer::GetUserID(this: LocalPlayer) == v36 )
                {
                  v37 = GetCenterPrint();
                  v37->Print_2(this: v37, a2: "#Cstrike_TitlesTXT_Killed_Hostage");
                  C_RecipientFilter::~C_RecipientFilter(this: &filter);
                  return;
                }
              }
            }
            else if ( g_PlantedC4s.m_Size > 0 )
            {
              C_PlantedC4::Explode(this: *g_PlantedC4s.m_Memory.m_pMemory);
              C_RecipientFilter::~C_RecipientFilter(this: &filter);
              return;
            }
          }
          goto LABEL_101;
        }
        if ( &hudChat[-1].m_bEnteringVoice != (bool *)&g_ClientModeFullscreen )
        {
          v23 = CBaseHudChat::GetHudChat();
          v24 = engine->__vftable;
          pPlayerc = (C_BasePlayer *)cl_entitylist.m_Index;
          v25 = ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                  a1: event,
                  a2: "userid",
                  a3: 0);
          v26 = v24->GetPlayerForUserID(this: engine, a2: v25);
          v27 = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)pPlayerc, entnum: v26);
          v28 = ToBasePlayer(pEntity: v27);
          v29 = v28;
          if ( v23 != nullptr
            && v28 != nullptr
            && ((unsigned __int8 (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetClientRenderable)(
                 a1: event,
                 a2: "disconnect",
                 a3: 0) == 0 )
          {
            v30 = ((int (__thiscall *)(C_BasePlayer *, const char *, _DWORD))event->GetIClientEntity)(
                    a1: event,
                    a2: "team",
                    a3: 0);
            if ( C_BasePlayer::IsLocalPlayer(pEntity: v29) )
              v29->TeamChange(this: v29, a2: v30);
            switch ( v30 )
            {
              case 1:
                v31 = v23->CHudElement::CGameEventListener::IGameEventListener2::__vftable;
                C_BasePlayer::GetPlayerName(this: v29);
                v32 = hudtextmessage->LookupString(this: hudtextmessage, a2: "#Game_join_spectators", a3: 0);
                v31->Printf(this: v23, a2: 0, a3: v32);
                C_RecipientFilter::~C_RecipientFilter(this: &filter);
                return;
              case 2:
                v33 = v23->CHudElement::CGameEventListener::IGameEventListener2::__vftable;
                PlayerName = C_BasePlayer::GetPlayerName(this: v29);
                v34 = hudtextmessage->LookupString(this: hudtextmessage, a2: "#Game_join_terrorist", a3: 0);
LABEL_55:
                v33->Printf(this: v23, a2: 0, a3: v34, PlayerName);
                C_RecipientFilter::~C_RecipientFilter(this: &filter);
                return;
              case 3:
                v33 = v23->CHudElement::CGameEventListener::IGameEventListener2::__vftable;
                PlayerName = C_BasePlayer::GetPlayerName(this: v29);
                v34 = hudtextmessage->LookupString(this: hudtextmessage, a2: "#Game_join_ct", a3: 0);
                goto LABEL_55;
              default:
                break;
            }
          }
        }
      }
    }
LABEL_101:
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104225B0
// Name: DT_WeaponCycler::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCycler::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponCycler::g_RecvTable);
  return atexit(func: DT_WeaponCycler::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104225D0
// Name: DT_WeaponCycler::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCycler::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponCycler::ignored>();
  DT_WeaponCycler::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104225E0
// Name: C_WeaponCycler_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponCycler_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponCycler::m_PredMap.dataNumFields = 1;
  C_WeaponCycler::m_PredMap.dataDesc = (typedescription_t *)&unk_1065BB3C;
}

//------------------------------------------------------------------------------
// Address: 0x10422650
// Name: DT_WeaponCubemap::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCubemap::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponCubemap::g_RecvTable);
  return atexit(func: DT_WeaponCubemap::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10422670
// Name: DT_WeaponCubemap::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCubemap::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponCubemap::ignored>();
  DT_WeaponCubemap::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422680
// Name: C_WeaponCubemap_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponCubemap_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponCubemap::m_PredMap.dataNumFields = 1;
  C_WeaponCubemap::m_PredMap.dataDesc = (typedescription_t *)&unk_1065BBF4;
}

//------------------------------------------------------------------------------
// Address: 0x104353C0
// Name: DT_WeaponCycler::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponCycler::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponCycler::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104353D0
// Name: DT_WeaponCubemap::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponCubemap::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponCubemap::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101C02B0
// Name: _C_WeaponCycler_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponCycler_CreateObject(int entnum, int serialNum)
{
  C_BaseCombatWeapon *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseCombatWeapon *)C_BaseEntity::operator new(stAllocateBlock: 0xD58u);
  v3 = &v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseCombatWeapon::C_BaseCombatWeapon(this: v2);
  *v3 = &C_WeaponCycler::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponCycler::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponCycler::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponCycler::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponCycler::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x101C0400
// Name: _C_WeaponCubemap_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponCubemap_CreateObject(int entnum, int serialNum)
{
  C_BaseCombatWeapon *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseCombatWeapon *)C_BaseEntity::operator new(stAllocateBlock: 0xD58u);
  v3 = &v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseCombatWeapon::C_BaseCombatWeapon(this: v2);
  *v3 = &C_WeaponCubemap::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponCubemap::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponCubemap::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponCubemap::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponCubemap::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10422600
// Name: _dynamic_initializer_for__g_Ccycler_weaponFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Ccycler_weaponFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "cycler_weapon",
             a3: "C_WeaponCycler",
             a4: 3416,
             a5: CC_WeaponCyclerFactory);
  __g_C_WeaponCyclerClientClass.m_pMapClassname = "cycler_weapon";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422630
// Name: _dynamic_initializer_for____g_C_WeaponCubemapClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponCubemapClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponCubemapClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponCubemapClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104226A0
// Name: _dynamic_initializer_for__g_Cweapon_cubemapFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_cubemapFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_cubemap",
             a3: "C_WeaponCubemap",
             a4: 3416,
             a5: CC_WeaponCubemapFactory);
  __g_C_WeaponCubemapClientClass.m_pMapClassname = "weapon_cubemap";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104226D0
// Name: _dynamic_initializer_for__cl_autobuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_autobuy__()
{
  ConVar::ConVar(
    this: &cl_autobuy,
    pName: "cl_autobuy",
    pDefaultValue: prType,
    flags: 512,
    pHelpString: "The order in which autobuy will attempt to purchase items");
  return atexit(func: dynamic_atexit_destructor_for__cl_autobuy__);
}

//------------------------------------------------------------------------------
// Address: 0x10422700
// Name: _dynamic_initializer_for__cl_rebuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_rebuy__()
{
  ConVar::ConVar(
    this: &cl_rebuy,
    pName: "cl_rebuy",
    pDefaultValue: prType,
    flags: 512,
    pHelpString: "The order in which rebuy will attempt to repurchase items");
  return atexit(func: dynamic_atexit_destructor_for__cl_rebuy__);
}

//------------------------------------------------------------------------------
// Address: 0x10422730
// Name: _dynamic_initializer_for__g_ClientModeFullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClientModeFullscreen__()
{
  ClientModeCSFullscreen::ClientModeCSFullscreen(this: &g_ClientModeFullscreen);
  return atexit(func: dynamic_atexit_destructor_for__g_ClientModeFullscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x10422750
// Name: _dynamic_initializer_for__g_ClientModeNormal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClientModeNormal__()
{
  ClientModeShared::ClientModeShared(this: &g_ClientModeNormal);
  g_ClientModeNormal.IClientMode::__vftable = (ClientModeShared_vtbl *)&ClientModeCSNormal::`vftable'{for `IClientMode'};
  g_ClientModeNormal.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&ClientModeCSNormal::`vftable'{for `CGameEventListener'};
  dword_1065B6B8 = (int)&ClientModeCSNormal::`vftable';
  dword_1065BABC = -1;
  return atexit(func: dynamic_atexit_destructor_for__g_ClientModeNormal__);
}

//------------------------------------------------------------------------------
// Address: 0x10422790
// Name: _dynamic_initializer_for__g_CSClientGameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CSClientGameStats__()
{
  CCSClientGameStats::CCSClientGameStats(this: &g_CSClientGameStats);
  return atexit(func: dynamic_atexit_destructor_for__g_CSClientGameStats__);
}

//------------------------------------------------------------------------------
// Address: 0x104227B0
// Name: _dynamic_initializer_for__sv_timebetweenducks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_timebetweenducks__()
{
  ConVar::ConVar(
    this: &sv_timebetweenducks,
    pName: "sv_timebetweenducks",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Minimum time before recognizing consecutive duck key",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 2.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_timebetweenducks__);
}

//------------------------------------------------------------------------------
// Address: 0x10422800
// Name: _dynamic_initializer_for__g_GameMovement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameMovement__()
{
  CGameMovement::CGameMovement(this: &g_GameMovement);
  g_GameMovement.__vftable = (CCSGameMovement_vtbl *)&CCSGameMovement::`vftable';
  g_GameMovement.m_fTimeLastUnducked = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__g_GameMovement__);
}

//------------------------------------------------------------------------------
// Address: 0x10422830
// Name: _dynamic_initializer_for____g_CreateCGameMovementIGameMovement_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCGameMovementIGameMovement_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCGameMovementIGameMovement_reg,
           fn: (void *(__cdecl *)())_CreateCGameMovementIGameMovement_interface,
           pName: "GameMovement001");
}

//------------------------------------------------------------------------------
// Address: 0x10422850
// Name: _dynamic_initializer_for__sv_enablebunnyhopping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_enablebunnyhopping__()
{
  ConVar::ConVar(this: &sv_enablebunnyhopping, pName: "sv_enablebunnyhopping", pDefaultValue: "0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__sv_enablebunnyhopping__);
}

//------------------------------------------------------------------------------
// Address: 0x10422880
// Name: _dynamic_initializer_for____g_GameRulesRegister_CCSGameRules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameRulesRegister *dynamic_initializer_for____g_GameRulesRegister_CCSGameRules__()
{
  return CGameRulesRegister::CGameRulesRegister(
           this: &_g_GameRulesRegister_CCSGameRules,
           pClassName: "CCSGameRules",
           fn: __CreateGameRules_CCSGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x104353E0
// Name: _dynamic_atexit_destructor_for__cl_autobuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_autobuy__()
{
  ConVar::~ConVar(this: &cl_autobuy);
}

//------------------------------------------------------------------------------
// Address: 0x104353F0
// Name: _dynamic_atexit_destructor_for__cl_rebuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_rebuy__()
{
  ConVar::~ConVar(this: &cl_rebuy);
}

//------------------------------------------------------------------------------
// Address: 0x10435400
// Name: _dynamic_atexit_destructor_for__g_ClientModeFullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClientModeFullscreen__()
{
  g_ClientModeFullscreen.ClientModeCSNormal::ClientModeShared::IClientMode::__vftable = (ClientModeCSFullscreen_vtbl *)&ClientModeCSNormal::`vftable'{for `IClientMode'};
  g_ClientModeFullscreen.ClientModeCSNormal::ClientModeShared::CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&ClientModeCSNormal::`vftable'{for `CGameEventListener'};
  g_ClientModeFullscreen.ClientModeCSNormal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&ClientModeCSNormal::`vftable';
  ClientModeShared::~ClientModeShared(this: &g_ClientModeFullscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10435430
// Name: _dynamic_atexit_destructor_for__g_ClientModeNormal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClientModeNormal__()
{
  g_ClientModeNormal.IClientMode::__vftable = (ClientModeShared_vtbl *)&ClientModeCSNormal::`vftable'{for `IClientMode'};
  g_ClientModeNormal.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&ClientModeCSNormal::`vftable'{for `CGameEventListener'};
  dword_1065B6B8 = (int)&ClientModeCSNormal::`vftable';
  ClientModeShared::~ClientModeShared(this: &g_ClientModeNormal);
}

//------------------------------------------------------------------------------
// Address: 0x10435460
// Name: _dynamic_atexit_destructor_for__g_CSClientGameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CSClientGameStats__()
{
  g_CSClientGameStats.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  g_CSClientGameStats.m_nDebugID = 13;
  if ( g_CSClientGameStats.m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &g_CSClientGameStats.CGameEventListener);
    g_CSClientGameStats.m_bRegisteredForEvents = false;
  }
  g_CSClientGameStats.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  IGameSystem::~IGameSystem(this: &g_CSClientGameStats);
}

//------------------------------------------------------------------------------
// Address: 0x104354B0
// Name: _dynamic_atexit_destructor_for__sv_timebetweenducks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_timebetweenducks__()
{
  ConVar::~ConVar(this: &sv_timebetweenducks);
}

//------------------------------------------------------------------------------
// Address: 0x104354C0
// Name: _dynamic_atexit_destructor_for__sv_enablebunnyhopping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_enablebunnyhopping__()
{
  ConVar::~ConVar(this: &sv_enablebunnyhopping);
}

//------------------------------------------------------------------------------
// Address: 0x104354D0
// Name: _dynamic_atexit_destructor_for__g_GameMovement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameMovement__()
{
  CGameMovement::~CGameMovement(this: &g_GameMovement);
}
