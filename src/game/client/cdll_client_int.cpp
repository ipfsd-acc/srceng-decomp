// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cdll_client_int.cpp
// Functions: 145
// ============================================================

#include "game\client\cdll_client_int.h"

//------------------------------------------------------------------------------
// Address: 0x1002DE50
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x1002DE60
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100988D0
// Name: public: bool CSteamAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamAPIContext::Init(CSteamAPIContext *this)
{
  int HSteamPipe; // esi
  int v4; // eax
  ISteamUser *v5; // eax
  int v6; // eax
  ISteamFriends *v7; // eax
  int v8; // eax
  ISteamUtils *v9; // eax
  int v10; // eax
  ISteamMatchmaking *v11; // eax
  int v12; // eax
  ISteamMatchmakingServers *v13; // eax
  int v14; // eax
  ISteamUserStats *v15; // eax
  int v16; // eax
  ISteamApps *v17; // eax
  int v18; // eax
  ISteamNetworking *v19; // eax
  int v20; // eax
  ISteamRemoteStorage *v21; // eax
  int hSteamUser; // [esp+8h] [ebp-4h]

  if ( _SteamClient() == 0 )
    return false;
  hSteamUser = _SteamAPI_GetHSteamUser();
  HSteamPipe = _SteamAPI_GetHSteamPipe();
  v4 = _SteamClient();
  v5 = (ISteamUser *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v4 + 20))(
                       a1: v4,
                       a2: hSteamUser,
                       a3: HSteamPipe,
                       a4: "SteamUser014");
  this->m_pSteamUser = v5;
  if ( v5 == nullptr )
    return false;
  v6 = _SteamClient();
  v7 = (ISteamFriends *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v6 + 32))(
                          a1: v6,
                          a2: hSteamUser,
                          a3: HSteamPipe,
                          a4: "SteamFriends008");
  this->m_pSteamFriends = v7;
  if ( v7 == nullptr )
    return false;
  v8 = _SteamClient();
  v9 = (ISteamUtils *)(*(int (__thiscall **)(int, int, const char *))(*(_DWORD *)v8 + 36))(
                        a1: v8,
                        a2: HSteamPipe,
                        a3: "SteamUtils005");
  this->m_pSteamUtils = v9;
  if ( v9 == nullptr )
    return false;
  v10 = _SteamClient();
  v11 = (ISteamMatchmaking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v10 + 40))(
                               a1: v10,
                               a2: hSteamUser,
                               a3: HSteamPipe,
                               a4: "SteamMatchMaking008");
  this->m_pSteamMatchmaking = v11;
  if ( v11 == nullptr )
    return false;
  v12 = _SteamClient();
  v13 = (ISteamMatchmakingServers *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v12 + 48))(
                                      a1: v12,
                                      a2: hSteamUser,
                                      a3: HSteamPipe,
                                      a4: "SteamMatchMakingServers002");
  this->m_pSteamMatchmakingServers = v13;
  if ( v13 == nullptr )
    return false;
  v14 = _SteamClient();
  v15 = (ISteamUserStats *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v14 + 56))(
                             a1: v14,
                             a2: hSteamUser,
                             a3: HSteamPipe,
                             a4: "STEAMUSERSTATS_INTERFACE_VERSION009");
  this->m_pSteamUserStats = v15;
  if ( v15 == nullptr )
    return false;
  v16 = _SteamClient();
  v17 = (ISteamApps *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v16 + 64))(
                        a1: v16,
                        a2: hSteamUser,
                        a3: HSteamPipe,
                        a4: "STEAMAPPS_INTERFACE_VERSION004");
  this->m_pSteamApps = v17;
  if ( v17 == nullptr )
    return false;
  v18 = _SteamClient();
  v19 = (ISteamNetworking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v18 + 68))(
                              a1: v18,
                              a2: hSteamUser,
                              a3: HSteamPipe,
                              a4: "SteamNetworking005");
  this->m_pSteamNetworking = v19;
  if ( v19 == nullptr )
    return false;
  v20 = _SteamClient();
  v21 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v20 + 72))(
                                 a1: v20,
                                 a2: hSteamUser,
                                 a3: HSteamPipe,
                                 a4: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
  this->m_pSteamRemoteStorage = v21;
  return v21 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10098A20
// Name: public: static bool CDefOps<char const __near *>::LessFunc(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDefOps<char const *>::LessFunc(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10098A80
// Name: void ProcessCacheUsedMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessCacheUsedMaterials()
{
  if ( g_bRequestCacheUsedMaterials )
  {
    g_bRequestCacheUsedMaterials = false;
    if ( materials != nullptr )
      materials->CacheUsedMaterials(this: materials);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098AB0
// Name: public: C_BaseEntityClassList::C_BaseEntityClassList(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntityClassList *__thiscall C_BaseEntityClassList::C_BaseEntityClassList(C_BaseEntityClassList *this)
{
  C_BaseEntityClassList *result; // eax
  C_BaseEntityClassList *v2; // ecx

  result = this;
  v2 = s_pClassLists;
  result->__vftable = (C_BaseEntityClassList_vtbl *)&C_BaseEntityClassList::`vftable';
  result->m_pNextClassList = v2;
  s_pClassLists = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10098AD0
// Name: public: C_BaseEntityClassList::~C_BaseEntityClassList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntityClassList::~C_BaseEntityClassList(C_BaseEntityClassList *this)
{
  this->__vftable = (C_BaseEntityClassList_vtbl *)&C_BaseEntityClassList::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10098B00
// Name: bool BoneSetupCompare(class CBoneSetupEnt const __near &,class CBoneSetupEnt const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl BoneSetupCompare(const CBoneSetupEnt *a, const CBoneSetupEnt *b)
{
  return a->m_Index < b->m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10098B30
// Name: int GetMaterialIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialIndex(const char *pMaterialName)
{
  int result; // eax

  if ( pMaterialName == nullptr )
    return 0;
  result = g_pStringTableMaterials->FindStringIndex(this: g_pStringTableMaterials, a2: pMaterialName);
  if ( result < 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10098B50
// Name: char const __near * GetMaterialNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialNameFromIndex(int nIndex)
{
  if ( nIndex == g_pStringTableMaterials->GetMaxStrings(this: g_pStringTableMaterials) - 1 )
    return nullptr;
  else
    return g_pStringTableMaterials->GetString(this: g_pStringTableMaterials, a2: nIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10098B80
// Name: int PrecacheParticleSystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PrecacheParticleSystem(const char *pParticleSystemName)
{
  int v1; // esi

  v1 = g_pStringTableParticleEffectNames->AddString(
         this: g_pStringTableParticleEffectNames,
         a2: false,
         a3: pParticleSystemName,
         a4: -1,
         a5: nullptr);
  CParticleSystemMgr::PrecacheParticleSystem(this: g_pParticleSystemMgr, nStringNumber: v1, pName: pParticleSystemName);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10098BC0
// Name: int GetParticleSystemIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetParticleSystemIndex(const char *pParticleSystemName)
{
  int result; // eax

  if ( pParticleSystemName != nullptr )
  {
    result = g_pStringTableParticleEffectNames->FindStringIndex(
               this: g_pStringTableParticleEffectNames,
               a2: pParticleSystemName);
    if ( result != 0xFFFF )
      return result;
    DevWarning(a1: "Client: Missing precache for particle system \"%s\"!\n", pParticleSystemName);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10098C00
// Name: char const __near * GetParticleSystemNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetParticleSystemNameFromIndex(int nIndex)
{
  if ( nIndex >= g_pStringTableParticleEffectNames->GetMaxStrings(this: g_pStringTableParticleEffectNames) )
    return "error";
  else
    return g_pStringTableParticleEffectNames->GetString(this: g_pStringTableParticleEffectNames, a2: nIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10098C30
// Name: void PrecacheEffect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheEffect(const char *pEffectName)
{
  g_pPrecacheSystem->Cache(
    this: g_pPrecacheSystem,
    a2: g_pPrecacheHandler,
    a3: DISPATCH_EFFECT,
    a4: pEffectName,
    a5: true,
    a6: (struct ResourceList_t__ *)-1,
    a7: true);
}

//------------------------------------------------------------------------------
// Address: 0x10098C60
// Name: bool InitParticleManager(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl InitParticleManager()
{
  CParticleMgr *v0; // eax
  IMaterialSystem *v2; // [esp-4h] [ebp-4h]

  v2 = materials;
  v0 = ParticleMgr();
  return CParticleMgr::Init(this: v0, count: 0x800u, pMaterials: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10098C80
// Name: public: virtual int CHLClient::Connect(void __near * (*)(char const __near *,int __near *),class CGlobalVarsBase __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLClient::Connect(
        CHLClient *this,
        void *(__cdecl *appSystemFactory)(const char *, int *),
        CGlobalVarsBase *pGlobals)
{
  vgui::PropertyPage *v3; // ecx

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  MathLib_Init(gamma: 2.2, texGamma: 2.2, brightness: 0.0, overbright: 2);
  gpGlobals.m_Index = (unsigned int)pGlobals;
  ConnectTier1Libraries(pFactoryList: &appSystemFactory, nFactoryCount: 1);
  ConnectTier2Libraries();
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v3);
  g_pScaleformUI = (IScaleformUI *)((int (__cdecl *)(const char *, _DWORD, void *(__cdecl **)(const char *, int *), int, void *(__cdecl **)(const char *, int *), int))appSystemFactory)(
                                     a1: "ScaleformUI001",
                                     a2: 0,
                                     a3: &appSystemFactory,
                                     a4: 1,
                                     a5: &appSystemFactory,
                                     a6: 1);
  _SteamAPI_InitSafe();
  _SteamAPI_SetTryCatchCallbacks(a1: 0);
  CSteamAPIContext::Init(this: &g_SteamAPIContext);
  ConVar_Register(nCVarFlag: 8, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10098D30
// Name: public: virtual void CHLClient::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CHLClient::Disconnect(CHLClient *this)
{
  ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10098D40
// Name: public: virtual void CHLClient::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::PostInit(CHLClient *this)
{
  int v1; // ecx

  _COM_TimestampedLog(a1: this, a2: "IGameSystem::PostInitAllSystems - Start");
  IGameSystem::PostInitAllSystems();
  _COM_TimestampedLog(a1: v1, a2: "IGameSystem::PostInitAllSystems - Finish");
}

//------------------------------------------------------------------------------
// Address: 0x10098D60
// Name: public: virtual int CHLClient::HudVidInit(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLClient::HudVidInit(CHLClient *this)
{
  CHud *Hud; // eax
  CVoiceStatus *ClientVoiceMgr; // eax

  Hud = GetHud(nSlot: -1);
  CHud::VidInit(this: Hud);
  ClientVoiceMgr = GetClientVoiceMgr();
  ClientVoiceMgr->VidInit(this: ClientVoiceMgr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10098D90
// Name: public: virtual void CHLClient::HudProcessInput(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::HudProcessInput(CHLClient *this, BOOL bActive)
{
  IClientMode *ClientMode; // eax

  ClientMode = GetClientMode();
  ClientMode->ProcessInput(this: ClientMode, a2: bActive);
}

//------------------------------------------------------------------------------
// Address: 0x10098DB0
// Name: public: virtual void CHLClient::HudUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::HudUpdate(CHLClient *this, BOOL bActive)
{
  CVoiceStatus *ClientVoiceMgr; // eax
  CHud *Hud; // eax
  vgui::AnimationController *AnimationController; // eax
  IHudLCD_vtbl *v5; // esi
  char *v6; // eax
  IHudLCD_vtbl *v7; // esi
  char *v8; // eax
  float frametime; // [esp+14h] [ebp-4h]
  float frametimea; // [esp+14h] [ebp-4h]

  frametime = *(float *)(gpGlobals.m_Index + 16);
  ClientVoiceMgr = GetClientVoiceMgr();
  CVoiceStatus::Frame(this: ClientVoiceMgr, frametime);
  Hud = GetHud(nSlot: -1);
  CHud::UpdateHud(this: Hud, bActive);
  C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
    this: (C_BaseAnimating::AutoAllowBoneAccess *)&bActive + 3,
    bAllowForNormalModels: true,
    bAllowForViewModels: false);
  IGameSystem::UpdateAllSystems(frametime);
  C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: (C_BaseAnimating::AutoAllowBoneAccess *)&bActive + 3);
  frametimea = _Plat_FloatTime(a1: LODWORD(frametime));
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime: frametimea);
  if ( hudlcd != nullptr )
  {
    v5 = hudlcd->__vftable;
    v6 = VarArgs(format: "%d", (int)*(float *)(gpGlobals.m_Index + 12));
    v5->SetGlobalStat(this: hudlcd, a2: "(time_int)", a3: v6);
    v7 = hudlcd->__vftable;
    v8 = VarArgs(format: "%.2f", *(float *)(gpGlobals.m_Index + 12));
    v7->SetGlobalStat(this: hudlcd, a2: "(time_float)", a3: v8);
  }
  C_BaseTempEntity::CheckDynamicTempEnts();
}

//------------------------------------------------------------------------------
// Address: 0x10098EB0
// Name: public: virtual void CHLClient::HudReset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::HudReset(CHLClient *this)
{
  CHud *Hud; // eax

  Hud = GetHud(nSlot: -1);
  CHud::VidInit(this: Hud);
  PhysicsReset();
}

//------------------------------------------------------------------------------
// Address: 0x10098ED0
// Name: public: virtual void CHLClient::HudText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::HudText(CHLClient *this, const char *message)
{
  DispatchHudText(pszText: message);
}

//------------------------------------------------------------------------------
// Address: 0x10098EF0
// Name: public: virtual class ClientClass __near * CHLClient::GetAllClasses(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall CHLClient::GetAllClasses(CHLClient *this)
{
  return g_pClientClassHead;
}

//------------------------------------------------------------------------------
// Address: 0x10098F00
// Name: public: virtual void CHLClient::IN_ActivateMouse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::IN_ActivateMouse(CHLClient *this)
{
  input->ActivateMouse(this: input);
}

//------------------------------------------------------------------------------
// Address: 0x10098F10
// Name: public: virtual void CHLClient::IN_DeactivateMouse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::IN_DeactivateMouse(CHLClient *this)
{
  input->DeactivateMouse(this: input);
}

//------------------------------------------------------------------------------
// Address: 0x10098F20
// Name: public: virtual void CHLClient::IN_Accumulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::IN_Accumulate(CHLClient *this)
{
  input->AccumulateMouse(this: input, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10098F30
// Name: public: virtual void CHLClient::IN_ClearStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::IN_ClearStates(CHLClient *this)
{
  input->ClearStates(this: input);
}

//------------------------------------------------------------------------------
// Address: 0x10098F40
// Name: public: virtual bool CHLClient::IN_IsKeyDown(char const __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLClient::IN_IsKeyDown(CHLClient *this, const char *name, bool *isdown)
{
  kbutton_t *v3; // eax

  v3 = input->FindKey(this: input, a2: name);
  if ( v3 == nullptr )
    return 0;
  *isdown = kbutton_t::GetPerUser(this: v3, nSlot: -1)->state & 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10098F80
// Name: public: virtual int CHLClient::IN_KeyEvent(int,enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLClient::IN_KeyEvent(
        CHLClient *this,
        int eventcode,
        ButtonCode_t keynum,
        const char *pszCurrentBinding)
{
  return input->KeyEvent(this: input, a2: eventcode, a3: keynum, a4: pszCurrentBinding);
}

//------------------------------------------------------------------------------
// Address: 0x10098FA0
// Name: public: virtual void CHLClient::IN_SetSampleTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::IN_SetSampleTime(CHLClient *this, float frametime)
{
  ((void (__stdcall *)(_DWORD))input->Joystick_SetSampleTime)(a1: LODWORD(frametime));
  ((void (__stdcall *)(_DWORD))input->IN_SetSampleTime)(a1: LODWORD(frametime));
}

//------------------------------------------------------------------------------
// Address: 0x10098FE0
// Name: public: virtual bool CHLClient::WriteUsercmdDeltaToBuffer(int,class bf_write __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLClient::WriteUsercmdDeltaToBuffer(
        CHLClient *this,
        int nSlot,
        bf_write *buf,
        int from,
        int to,
        BOOL isnewcommand)
{
  return input->WriteUsercmdDeltaToBuffer(this: input, a2: nSlot, a3: buf, a4: from, a5: to, a6: isnewcommand);
}

//------------------------------------------------------------------------------
// Address: 0x10099000
// Name: public: virtual void CHLClient::EncodeUserCmdToBuffer(int,class bf_write __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::EncodeUserCmdToBuffer(CHLClient *this, int nSlot, bf_write *buf, int slot)
{
  input->EncodeUserCmdToBuffer(this: input, a2: nSlot, a3: buf, a4: slot);
}

//------------------------------------------------------------------------------
// Address: 0x10099020
// Name: public: virtual void CHLClient::DecodeUserCmdFromBuffer(int,class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::DecodeUserCmdFromBuffer(CHLClient *this, int nSlot, bf_read *buf, int slot)
{
  input->DecodeUserCmdFromBuffer(this: input, a2: nSlot, a3: buf, a4: slot);
}

//------------------------------------------------------------------------------
// Address: 0x10099040
// Name: public: virtual void CHLClient::View_Render(struct vrect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::View_Render(CHLClient *this, vrect_t *rect)
{
  if ( rect->width != 0 && rect->height != 0 )
  {
    view->Render(this: view, a2: rect);
    UpdatePerfStats();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099070
// Name: public: class CViewSetup __near & CViewSetup::operator=(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
CViewSetup *__thiscall CViewSetup::operator=(CViewSetup *this, const CViewSetup *__that)
{
  CViewSetup *result; // eax
  char v3; // cl
  char v4; // cl
  char v5; // dl
  char v6; // cl
  char v7; // dl
  char v8; // cl
  char v9; // dl

  result = this;
  this->x = __that->x;
  this->y = __that->y;
  this->width = __that->width;
  this->height = __that->height;
  this->m_bOrtho = __that->m_bOrtho;
  this->m_OrthoLeft = __that->m_OrthoLeft;
  this->m_OrthoTop = __that->m_OrthoTop;
  this->m_OrthoRight = __that->m_OrthoRight;
  this->m_OrthoBottom = __that->m_OrthoBottom;
  this->m_bCustomViewMatrix = __that->m_bCustomViewMatrix;
  this->m_matCustomViewMatrix = __that->m_matCustomViewMatrix;
  this->fov = __that->fov;
  this->fovViewmodel = __that->fovViewmodel;
  this->origin = __that->origin;
  this->angles = __that->angles;
  this->zNear = __that->zNear;
  this->zFar = __that->zFar;
  this->zNearViewmodel = __that->zNearViewmodel;
  this->zFarViewmodel = __that->zFarViewmodel;
  this->m_flAspectRatio = __that->m_flAspectRatio;
  this->m_flNearBlurDepth = __that->m_flNearBlurDepth;
  this->m_flNearFocusDepth = __that->m_flNearFocusDepth;
  this->m_flFarFocusDepth = __that->m_flFarFocusDepth;
  this->m_flFarBlurDepth = __that->m_flFarBlurDepth;
  this->m_flNearBlurRadius = __that->m_flNearBlurRadius;
  this->m_flFarBlurRadius = __that->m_flFarBlurRadius;
  this->m_nDoFQuality = __that->m_nDoFQuality;
  this->m_nMotionBlurMode = __that->m_nMotionBlurMode;
  this->m_flShutterTime = __that->m_flShutterTime;
  this->m_vShutterOpenPosition = __that->m_vShutterOpenPosition;
  this->m_shutterOpenAngles = __that->m_shutterOpenAngles;
  this->m_vShutterClosePosition = __that->m_vShutterClosePosition;
  this->m_shutterCloseAngles = __that->m_shutterCloseAngles;
  v3 = *((_BYTE *)this + 240);
  result->m_flOffCenterTop = __that->m_flOffCenterTop;
  result->m_flOffCenterBottom = __that->m_flOffCenterBottom;
  result->m_flOffCenterLeft = __that->m_flOffCenterLeft;
  result->m_flOffCenterRight = __that->m_flOffCenterRight;
  *((_BYTE *)result + 240) ^= (*((_BYTE *)__that + 240) ^ v3) & 1;
  v4 = *((_BYTE *)result + 240) ^ (*((_BYTE *)result + 240) ^ *((_BYTE *)__that + 240)) & 2;
  *((_BYTE *)result + 240) = v4;
  v5 = v4 ^ (v4 ^ *((_BYTE *)__that + 240)) & 4;
  *((_BYTE *)result + 240) = v5;
  v6 = v5 ^ (v5 ^ *((_BYTE *)__that + 240)) & 8;
  *((_BYTE *)result + 240) = v6;
  v7 = v6 ^ (v6 ^ *((_BYTE *)__that + 240)) & 0x10;
  *((_BYTE *)result + 240) = v7;
  v8 = v7 ^ (v7 ^ *((_BYTE *)__that + 240)) & 0x20;
  *((_BYTE *)result + 240) = v8;
  v9 = v8 ^ (v8 ^ *((_BYTE *)__that + 240)) & 0x40;
  *((_BYTE *)result + 240) = v9;
  *((_BYTE *)result + 240) = *((_BYTE *)__that + 240) ^ (v9 ^ *((_BYTE *)__that + 240)) & 0x7F;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10099330
// Name: public: virtual void CHLClient::View_Fade(struct ScreenFade_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::View_Fade(CHLClient *this, ScreenFade_t *pSF)
{
  CViewEffects *ViewEffects; // eax

  if ( pSF != nullptr )
  {
    ViewEffects = GetViewEffects();
    ViewEffects->Fade(this: ViewEffects, a2: pSF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099350
// Name: public: virtual void CHLClient::LevelInitPreEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::LevelInitPreEntity(CHLClient *this, const char *pMapName)
{
  CViewEffects *ViewEffects; // eax
  CParticleMgr *v3; // eax
  int (*GetInt)(void); // eax
  CHud *Hud; // eax

  if ( !g_bLevelInitialized )
  {
    g_bLevelInitialized = true;
    engine->TickProgressBar(this: engine);
    input->LevelInit(this: input);
    ViewEffects = GetViewEffects();
    ViewEffects->LevelInit(this: ViewEffects);
    modemanager->LevelInit(this: modemanager, a2: pMapName);
    v3 = ParticleMgr();
    CParticleMgr::LevelInit(this: v3);
    ClientVoiceMgr_LevelInit();
    if ( hudlcd != nullptr )
      hudlcd->SetGlobalStat(this: hudlcd, a2: "(mapname)", a3: pMapName);
    C_BaseTempEntity::ClearDynamicTempEnts();
    clienteffects->Flush(this: clienteffects);
    view->LevelInit(this: view);
    tempents->LevelInit(this: tempents);
    ResetToneMapping(a1: (int)pMapName, flTonemappingScale: 1.0);
    IGameSystem::LevelInitPreEntityAllSystems(pMapName);
    ResetWindspeed();
    GetInt = (int (*)(void))cl_predict->GetInt;
    if ( *(int *)(gpGlobals.m_Index + 20) <= 1 )
    {
      if ( GetInt() != 0 )
        engine->ClientCmd(this: engine, a2: "cl_predict 0");
    }
    else if ( GetInt() == 0 )
    {
      engine->ClientCmd(this: engine, a2: "cl_predict 1");
    }
    CRagdollLowViolenceManager::SetLowViolence(this: &g_RagdollLVManager, pMapName);
    engine->TickProgressBar(this: engine);
    Hud = GetHud(nSlot: -1);
    CHud::LevelInit(this: Hud);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099490
// Name: public: virtual void CHLClient::SetCrosshairAngle(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::SetCrosshairAngle(CHLClient *this, const QAngle *angle)
{
  CHud *Hud; // eax
  CHudCrosshair *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CHudCrosshair *)CHud::FindElement(this: Hud, pName: "CHudCrosshair");
  if ( Element != nullptr )
    CHudCrosshair::SetCrosshairAngle(this: Element, angle);
}

//------------------------------------------------------------------------------
// Address: 0x100994C0
// Name: public: virtual void CHLClient::InitSprite(class CEngineSprite __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::InitSprite(CHLClient *this, CEngineSprite *pSprite, const char *loadname)
{
  if ( pSprite != nullptr )
    CEngineSprite::Init(this: pSprite, pName: loadname);
}

//------------------------------------------------------------------------------
// Address: 0x100994E0
// Name: public: virtual void CHLClient::ShutdownSprite(class CEngineSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::ShutdownSprite(CHLClient *this, CEngineSprite *pSprite)
{
  if ( pSprite != nullptr )
    CEngineSprite::Shutdown(this: pSprite);
}

//------------------------------------------------------------------------------
// Address: 0x10099500
// Name: public: virtual int CHLClient::GetSpriteSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLClient::GetSpriteSize(CHLClient *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x10099510
// Name: public: virtual void CHLClient::VoiceStatus(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::VoiceStatus(CHLClient *this, int entindex, int iSsSlot, int bTalking)
{
  CVoiceStatus *ClientVoiceMgr; // eax

  ClientVoiceMgr = GetClientVoiceMgr();
  CVoiceStatus::UpdateSpeakerStatus(this: ClientVoiceMgr, entindex, iSsSlot, bTalking: bTalking != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10099540
// Name: void OnEffectStringTableChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnEffectStringTableChanged(
        void *object,
        INetworkStringTable *stringTable,
        int stringNumber,
        const char *newString)
{
  g_pPrecacheSystem->Cache(
    this: g_pPrecacheSystem,
    a2: g_pPrecacheHandler,
    a3: DISPATCH_EFFECT,
    a4: newString,
    a5: true,
    a6: (struct ResourceList_t__ *)-1,
    a7: true);
  g_bRequestCacheUsedMaterials = true;
}

//------------------------------------------------------------------------------
// Address: 0x10099570
// Name: void OnParticleSystemStringTableChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnParticleSystemStringTableChanged(
        void *object,
        INetworkStringTable *stringTable,
        int stringNumber,
        const char *newString)
{
  CParticleSystemMgr::PrecacheParticleSystem(this: g_pParticleSystemMgr, nStringNumber: stringNumber, pName: newString);
  g_bRequestCacheUsedMaterials = true;
}

//------------------------------------------------------------------------------
// Address: 0x10099590
// Name: void OnPrecacheParticleFile(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnPrecacheParticleFile(
        void *object,
        INetworkStringTable *stringTable,
        int stringNumber,
        const char *newString)
{
  CParticleSystemMgr::ShouldLoadSheets(this: g_pParticleSystemMgr, bLoadSheets: true);
  CParticleSystemMgr::ReadParticleConfigFile(
    this: g_pParticleSystemMgr,
    pFileName: newString,
    bPrecache: true,
    bDecommitTempMemory: false);
  CParticleSystemMgr::DecommitTempMemory(this: g_pParticleSystemMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100995C0
// Name: void OnVguiScreenTableChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnVguiScreenTableChanged(
        void *object,
        INetworkStringTable *stringTable,
        int stringNumber,
        const char *newString)
{
  CPanelMetaClassMgrImp *v4; // eax
  int v5; // esi
  CPanelMetaClassMgrImp *v6; // eax

  v4 = PanelMetaClassMgr();
  v5 = (int)v4->CreatePanelMetaClass(this: v4, a2: newString, a3: 100, a4: nullptr, a5: nullptr, a6: nullptr);
  if ( v5 != 0 )
  {
    v6 = PanelMetaClassMgr();
    v6->DestroyPanelMetaClass(this: v6, a2: (vgui::Panel *)v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099600
// Name: public: virtual bool CHLClient::DispatchUserMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLClient::DispatchUserMessage(CHLClient *this, int msg_type, bf_read *msg_data)
{
  return CUserMessages::DispatchUserMessage(this: usermessages, msg_type, msg_data);
}

//------------------------------------------------------------------------------
// Address: 0x10099610
// Name: public: virtual class CSaveRestoreData __near * CHLClient::SaveInit(int)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CHLClient::SaveInit(CHLClient *this, int size)
{
  return SaveInit(size);
}

//------------------------------------------------------------------------------
// Address: 0x10099630
// Name: public: virtual void CHLClient::PreSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::PreSave(CHLClient *this, CSaveRestoreData *s)
{
  g_pGameSaveRestoreBlockSet->PreSave(this: g_pGameSaveRestoreBlockSet, a2: s);
}

//------------------------------------------------------------------------------
// Address: 0x10099650
// Name: public: virtual void CHLClient::WriteSaveGameScreenshot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::WriteSaveGameScreenshot(CHLClient *this, const char *pFilename)
{
  view->WriteSaveGameScreenshot(this: view, a2: pFilename);
}

//------------------------------------------------------------------------------
// Address: 0x10099670
// Name: public: virtual class CStandardRecvProxies __near * CHLClient::GetStandardRecvProxies(void)
// Source: json
//------------------------------------------------------------------------------
CStandardRecvProxies *__thiscall CHLClient::GetStandardRecvProxies(CHLClient *this)
{
  return &g_StandardRecvProxies;
}

//------------------------------------------------------------------------------
// Address: 0x10099680
// Name: public: virtual bool CHLClient::CanRecordDemo(char __near *,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLClient::CanRecordDemo(CHLClient *this, char *errorMsg, int length)
{
  ClientModeShared *ClientModeNormal; // eax

  if ( GetClientModeNormal() == nullptr )
    return true;
  ClientModeNormal = GetClientModeNormal();
  return ClientModeNormal->CanRecordDemo(this: ClientModeNormal, a2: errorMsg, a3: length);
}

//------------------------------------------------------------------------------
// Address: 0x100996B0
// Name: public: virtual int CHLClient::GetScreenWidth(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CHLClient::GetScreenWidth(CHLClient *this)
{
  return ScreenWidth();
}

//------------------------------------------------------------------------------
// Address: 0x100996C0
// Name: public: virtual int CHLClient::GetScreenHeight(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CHLClient::GetScreenHeight(CHLClient *this)
{
  return ScreenHeight();
}

//------------------------------------------------------------------------------
// Address: 0x100996D0
// Name: public: virtual void CHLClient::WriteSaveGameScreenshotOfSize(char const __near *,int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::WriteSaveGameScreenshotOfSize(
        CHLClient *this,
        const char *pFilename,
        int width,
        int height,
        bool bCreatePowerOf2Padded,
        bool bWriteVTF)
{
  view->WriteSaveGameScreenshotOfSize(this: view, a2: pFilename, a3: width, a4: height);
}

//------------------------------------------------------------------------------
// Address: 0x100996F0
// Name: public: virtual void CHLClient::RenderView(class CViewSetup const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::RenderView(CHLClient *this, const CViewSetup *setup, int nClearFlags, int whatToDraw)
{
  view->RenderView(this: view, a2: setup, a3: setup, a4: nClearFlags, a5: whatToDraw);
}

//------------------------------------------------------------------------------
// Address: 0x10099720
// Name: public: virtual void CHLClient::OnSplitScreenStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CHLClient::OnSplitScreenStateChanged(CHLClient *this)
{
  IClientMode *ClientMode; // eax
  CHud *Hud; // eax
  ClientModeCSFullscreen *FullscreenClientMode; // eax
  C_BaseEntity *i; // eax
  CHLClient *iterator; // [esp+0h] [ebp-4h] OVERLAPPED BYREF

  iterator = this;
  VGui_OnSplitScreenStateChanged();
  IterateRemoteSplitScreenViewSlots_Push(bSet: true);
  ClientMode = GetClientMode();
  ((void (__thiscall *)(IClientMode *, _DWORD, CHLClient *))ClientMode->Layout)(a1: ClientMode, a2: 0, a3: iterator);
  Hud = GetHud(nSlot: -1);
  CHud::OnSplitScreenStateChanged(this: Hud);
  IterateRemoteSplitScreenViewSlots_Pop();
  FullscreenClientMode = GetFullscreenClientMode();
  FullscreenClientMode->Layout(this: FullscreenClientMode, a2: true);
  g_pVGuiSurface->ResetFontCaches(this: g_pVGuiSurface);
  C_BaseEntityIterator::C_BaseEntityIterator(this: (C_BaseEntityIterator *)&iterator);
  for ( i = C_BaseEntityIterator::Next(this: (C_BaseEntityIterator *)&iterator);
        i != nullptr;
        i = C_BaseEntityIterator::Next(this: (C_BaseEntityIterator *)&iterator) )
  {
    C_BaseEntity::UpdateVisibility(this: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100997B0
// Name: public: virtual void CHLClient::CenterStringOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::CenterStringOff(CHLClient *this)
{
  CCenterPrint *CenterPrint; // eax

  CenterPrint = GetCenterPrint();
  CenterPrint->Clear(this: CenterPrint);
}

//------------------------------------------------------------------------------
// Address: 0x100997C0
// Name: public: virtual void CHLClient::OnScreenSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CHLClient::OnScreenSizeChanged(CHLClient *this, int nOldWidth, int nOldHeight)
{
  VGui_OnScreenSizeChanged();
}

//------------------------------------------------------------------------------
// Address: 0x100997D0
// Name: public: virtual class IMaterialProxy __near * CHLClient::InstantiateMaterialProxy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__thiscall CHLClient::InstantiateMaterialProxy(CHLClient *this, const char *proxyName)
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return MaterialProxyDict->CreateProxy(this: MaterialProxyDict, a2: proxyName);
}

//------------------------------------------------------------------------------
// Address: 0x100997F0
// Name: public: virtual void CHLClient::SetBlurFade(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::SetBlurFade(CHLClient *this, float scale)
{
  IClientMode *ClientMode; // eax

  ClientMode = GetClientMode();
  ((void (__thiscall *)(IClientMode *, _DWORD))ClientMode->SetBlurFade)(a1: ClientMode, a2: LODWORD(scale));
}

//------------------------------------------------------------------------------
// Address: 0x10099820
// Name: public: virtual void CHLClient::Hud_SaveStarted(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::Hud_SaveStarted(CHLClient *this)
{
  CHud *Hud; // eax
  CHudSaveStatus *Element; // eax

  Hud = GetHud(nSlot: 0);
  Element = (CHudSaveStatus *)CHud::FindElement(this: Hud, pName: "CHudSaveStatus");
  if ( Element != nullptr )
    CHudSaveStatus::SaveStarted(this: Element);
}

//------------------------------------------------------------------------------
// Address: 0x100998C0
// Name: public: CSetActiveSplitScreenPlayerGuard::CSetActiveSplitScreenPlayerGuard(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSetActiveSplitScreenPlayerGuard *__thiscall CSetActiveSplitScreenPlayerGuard::CSetActiveSplitScreenPlayerGuard(
        CSetActiveSplitScreenPlayerGuard *this,
        const char *pchContext,
        int nLine)
{
  engine->GetActiveSplitScreenPlayerSlot(this: engine);
  engine->GetActiveSplitScreenPlayerSlot(this: engine);
  this->m_bNoRestore = true;
  this->m_bChanged = true;
  this->m_pchContext = pchContext;
  this->m_nLine = nLine;
  this->m_nSaveSlot = engine->SetActiveSplitScreenPlayerSlot(this: engine, a2: -1);
  this->m_bSaveGetLocalPlayerAllowed = engine->SetLocalPlayerIsResolvable(
                                         this: engine,
                                         a2: pchContext,
                                         a3: nLine,
                                         a4: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10099930
// Name: public: CSetActiveSplitScreenPlayerGuard::~CSetActiveSplitScreenPlayerGuard(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSetActiveSplitScreenPlayerGuard::~CSetActiveSplitScreenPlayerGuard(
        CSetActiveSplitScreenPlayerGuard *this)
{
  if ( this->m_bChanged )
  {
    engine->SetActiveSplitScreenPlayerSlot(this: engine, a2: this->m_nSaveSlot);
    engine->SetLocalPlayerIsResolvable(
      this: engine,
      a2: this->m_pchContext,
      a3: this->m_nLine,
      a4: this->m_bSaveGetLocalPlayerAllowed);
  }
  if ( !this->m_bNoRestore )
    ((void (__stdcall *)(bool, int, int))g_pVGuiSurface->ForceScreenSizeOverride)(
      a1: this->m_bOldSetting,
      a2: this->m_nOldSize[0],
      a3: this->m_nOldSize[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10099990
// Name: public: virtual void CHLVoiceStatusHelper::GetPlayerTextColor(int,int __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLVoiceStatusHelper::GetPlayerTextColor(CHLVoiceStatusHelper *this, int entindex, int *color)
{
  color[2] = 128;
  color[1] = 128;
  *color = 128;
}

//------------------------------------------------------------------------------
// Address: 0x100999E0
// Name: bool IsEngineThreaded(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsEngineThreaded()
{
  ConVar *m_pParent; // eax

  if ( g_pcv_ThreadMode == nullptr )
    return false;
  m_pParent = g_pcv_ThreadMode->m_pParent;
  return m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10099A10
// Name: bool InitGameSystems(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __usercall InitGameSystems@<al>(const char *a1@<edi>, void *(__cdecl *appSystemFactory)(const char *, int *))
{
  bool result; // al
  CGameStringPool *v3; // eax
  CSoundEmitterSystem *v4; // eax
  IGameSystem *v5; // eax
  IGameSystemPerFrame *v6; // eax
  IGameSystem *v7; // eax
  C_SoundscapeSystem *v8; // eax
  IGameSystem *v9; // eax
  vgui::ISchemeManager *v10; // edi
  vgui::ISchemeManager_vtbl *v11; // esi
  unsigned int FullscreenRootVPANEL; // eax
  int i; // esi
  IClientMode *ClientMode; // eax
  ClientModeCSFullscreen *FullscreenClientMode; // eax
  CHud *Hud; // eax
  int j; // esi
  IClientMode *v18; // eax
  ClientModeCSFullscreen *v19; // eax
  int k; // ebx
  IClientMode *v21; // eax
  ClientModeCSFullscreen *v22; // edi
  ClientModeCSFullscreen_vtbl *v23; // esi
  unsigned int v24; // eax
  CCSViewRender *ViewRenderInstance; // eax
  CViewEffects *ViewEffects; // eax
  unsigned int v27; // esi
  CVoiceStatus *ClientVoiceMgr; // eax
  ISaveRestoreBlockSet_vtbl *v29; // esi
  CEntitySaveRestoreBlockHandler *EntitySaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v31; // esi
  CPhysSaveRestoreBlockHandler *PhysSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v33; // esi
  CViewEffectsSaveRestoreBlockHandler *ViewEffectsRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v35; // esi
  CGameInstructorSaveRestoreBlockHandler *GameInstructorRestoreBlockHandler; // eax

  result = VGui_Startup(appSystemFactory);
  if ( result )
  {
    materials->RefreshFrontBufferNonInteractive(this: materials);
    vgui::VGui_InitMatSysInterfacesList(moduleName: "ClientDLL", factoryList: &appSystemFactory, numFactories: 1);
    materials->RefreshFrontBufferNonInteractive(this: materials);
    v3 = GameStringSystem();
    IGameSystem::Add(pSys: v3);
    IGameSystem::Add(pSys: g_pPrecacheRegister);
    v4 = SoundEmitterSystem();
    IGameSystem::Add(pSys: v4);
    v5 = ToolFrameworkClientSystem();
    IGameSystem::Add(pSys: v5);
    if ( g_pClientLeafSystem != nullptr )
      v6 = &g_pClientLeafSystem->IGameSystemPerFrame;
    else
      v6 = nullptr;
    IGameSystem::Add(pSys: v6);
    IGameSystem::Add(pSys: g_pDetailObjectSystem);
    v7 = ViewportClientSystem();
    IGameSystem::Add(pSys: v7);
    IGameSystem::Add(pSys: g_pClientShadowMgr);
    IGameSystem::Add(pSys: g_pColorCorrectionMgr);
    IGameSystem::Add(pSys: &g_ClientThinkList);
    v8 = ClientSoundscapeSystem();
    IGameSystem::Add(pSys: v8);
    v9 = PerfVisualBenchmark();
    IGameSystem::Add(pSys: v9);
    ActivityList_Init();
    ActivityList_RegisterSharedActivities();
    EventList_Init();
    EventList_RegisterSharedEvents();
    modemanager->Init(this: modemanager);
    v10 = g_pVGuiSchemeManager;
    v11 = g_pVGuiSchemeManager->__vftable;
    FullscreenRootVPANEL = VGui_GetFullscreenRootVPANEL();
    v11->LoadSchemeFromFileEx(this: v10, a2: FullscreenRootVPANEL, a3: "resource/ClientScheme.res", a4: "ClientScheme");
    for ( i = 0; i < 1; ++i )
    {
      ClientMode = GetClientMode();
      ClientMode->InitViewport(this: ClientMode);
      if ( i == 0 )
      {
        FullscreenClientMode = GetFullscreenClientMode();
        FullscreenClientMode->InitViewport(this: FullscreenClientMode);
      }
    }
    Hud = GetHud(nSlot: -1);
    CHud::Init(this: Hud);
    for ( j = 0; j < 1; ++j )
    {
      v18 = GetClientMode();
      v18->Init(this: v18);
      if ( j == 0 )
      {
        v19 = GetFullscreenClientMode();
        v19->Init(this: v19);
      }
    }
    if ( !IGameSystem::InitAllSystems() )
      return false;
    for ( k = 0; k < 1; ++k )
    {
      v21 = GetClientMode();
      v21->Enable(this: v21);
      if ( k == 0 )
      {
        v22 = GetFullscreenClientMode();
        v23 = v22->ClientModeCSNormal::ClientModeShared::IClientMode::__vftable;
        v24 = VGui_GetFullscreenRootVPANEL();
        v23->EnableWithRootPanel(this: v22, a2: v24);
      }
    }
    ViewRenderInstance = GetViewRenderInstance();
    view = ViewRenderInstance;
    if ( ViewRenderInstance == nullptr )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_1046F144, a2: a1);
      ViewRenderInstance = (CCSViewRender *)view;
    }
    ViewRenderInstance->Init(this: ViewRenderInstance);
    ViewEffects = GetViewEffects();
    ViewEffects->Init(this: ViewEffects);
    C_BaseTempEntity::PrecacheTempEnts();
    input->Init_All(this: input);
    VGui_CreateGlobalPanels();
    InitSmokeFogOverlay();
    CUserMessageRegister::RegisterAll();
    ClientVoiceMgr_Init();
    v27 = enginevgui->GetPanel(this: enginevgui, a2: PANEL_CLIENTDLL);
    ClientVoiceMgr = GetClientVoiceMgr();
    ClientVoiceMgr->Init(this: ClientVoiceMgr, a2: &g_VoiceStatusHelper, a3: v27);
    if ( PhysicsDLLInit(physicsFactory: appSystemFactory) )
    {
      v29 = g_pGameSaveRestoreBlockSet->__vftable;
      EntitySaveRestoreBlockHandler = GetEntitySaveRestoreBlockHandler();
      v29->AddBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: EntitySaveRestoreBlockHandler);
      v31 = g_pGameSaveRestoreBlockSet->__vftable;
      PhysSaveRestoreBlockHandler = GetPhysSaveRestoreBlockHandler();
      v31->AddBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: PhysSaveRestoreBlockHandler);
      v33 = g_pGameSaveRestoreBlockSet->__vftable;
      ViewEffectsRestoreBlockHandler = GetViewEffectsRestoreBlockHandler();
      v33->AddBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: ViewEffectsRestoreBlockHandler);
      v35 = g_pGameSaveRestoreBlockSet->__vftable;
      GameInstructorRestoreBlockHandler = GetGameInstructorRestoreBlockHandler();
      v35->AddBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: GameInstructorRestoreBlockHandler);
      ClientWorldFactoryInit();
      materials->RefreshFrontBufferNonInteractive(this: materials);
      return true;
    }
    else
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10099CF0
// Name: public: virtual void CHLClient::ExtraMouseSample(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::ExtraMouseSample(CHLClient *this, float frametime, int active)
{
  IMDLCache *v3; // esi
  bool s_AbsQueryGuard; // [esp+Fh] [ebp-9h]
  bool bSave; // [esp+13h] [ebp-5h]
  C_BaseAnimating::AutoAllowBoneAccess boneaccess; // [esp+17h] [ebp-1h] BYREF

  bSave = C_BaseEntity::IsAbsRecomputationsEnabled();
  C_BaseEntity::EnableAbsRecomputations(bEnable: true);
  s_AbsQueryGuard = C_BaseEntity::IsAbsQueriesValid();
  C_BaseEntity::SetAbsQueriesValid(bValid: true);
  C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
    this: &boneaccess,
    bAllowForNormalModels: true,
    bAllowForViewModels: false);
  v3 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  ((void (__stdcall *)(_DWORD, int))input->ExtraMouseSample)(a1: LODWORD(frametime), a2: active);
  C_BaseEntity::EnableAbsRecomputations(bEnable: bSave);
  v3->EndLock(this: v3);
  C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: &boneaccess);
  C_BaseEntity::SetAbsQueriesValid(bValid: s_AbsQueryGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10099D80
// Name: public: virtual void CHLClient::CreateMove(int,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::CreateMove(CHLClient *this, int sequence_number, float input_sample_frametime, int active)
{
  IMDLCache *v4; // esi
  C_BaseAnimating::AutoAllowBoneAccess boneaccess; // [esp+Fh] [ebp-1h] BYREF

  C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
    this: &boneaccess,
    bAllowForNormalModels: true,
    bAllowForViewModels: false);
  v4 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  ((void (__stdcall *)(int, _DWORD, int))input->CreateMove)(
    a1: sequence_number,
    a2: LODWORD(input_sample_frametime),
    a3: active);
  v4->EndLock(this: v4);
  C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: &boneaccess);
}

//------------------------------------------------------------------------------
// Address: 0x10099DE0
// Name: public: virtual bool CHLClient::GetPlayerView(class CViewSetup __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLClient::GetPlayerView(CHLClient *this, CViewSetup *playerView)
{
  const CViewSetup *v2; // eax

  v2 = view->GetPlayerViewSetup(this: view, a2: -1);
  CViewSetup::operator=(this: playerView, __that: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10099E10
// Name: enum CPULevel_t GetActualCPULevel(void)
// Source: json
//------------------------------------------------------------------------------
CPULevel_t __cdecl GetActualCPULevel()
{
  CPULevel_t result; // eax

  if ( cpu_level.m_pParent == nullptr )
    return CPU_LEVEL_LOW;
  result = cpu_level.m_pParent->m_Value.m_nValue;
  if ( result < CPU_LEVEL_LOW )
    return CPU_LEVEL_LOW;
  if ( result > CPU_LEVEL_HIGH )
    return CPU_LEVEL_HIGH;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10099E30
// Name: enum GPULevel_t GetGPULevel(void)
// Source: json
//------------------------------------------------------------------------------
GPULevel_t __cdecl GetGPULevel()
{
  GPULevel_t result; // eax

  if ( gpu_level.m_pParent == nullptr )
    return GPU_LEVEL_LOW;
  result = gpu_level.m_pParent->m_Value.m_nValue;
  if ( result < GPU_LEVEL_LOW )
    return GPU_LEVEL_LOW;
  if ( result > GPU_LEVEL_VERYHIGH )
    return GPU_LEVEL_VERYHIGH;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10099E50
// Name: public: virtual void CHLClient::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLClient::LevelInitPostEntity(CHLClient *this@<ecx>, const char *a2@<edi>)
{
  CCenterPrint *CenterPrint; // eax
  bool s_AbsQueryGuarda; // [esp+0h] [ebp-4h]

  LOBYTE(this) = C_BaseEntity::IsAbsQueriesValid();
  C_BaseEntity::SetAbsQueriesValid(bValid: true);
  IGameSystem::LevelInitPostEntityAllSystems();
  C_PhysPropClientside::RecreateAll();
  C_Sprite::RecreateAllClientside(a1: a2);
  CenterPrint = GetCenterPrint();
  ((void (__thiscall *)(CCenterPrint *, CHLClient *))CenterPrint->Clear)(a1: CenterPrint, a2: this);
  C_BaseEntity::SetAbsQueriesValid(bValid: s_AbsQueryGuarda);
}

//------------------------------------------------------------------------------
// Address: 0x10099EA0
// Name: public: virtual void CHLClient::EmitSentenceCloseCaption(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::EmitSentenceCloseCaption(CHLClient *this, const char *tokenstream)
{
  CHudCloseCaption *m_pHudCloseCaption; // ecx

  if ( closecaption.m_pParent != nullptr && closecaption.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pHudCloseCaption = this->m_pHudCloseCaption;
    if ( m_pHudCloseCaption != nullptr )
      CHudCloseCaption::ProcessSentenceCaptionStream(this: m_pHudCloseCaption, tokenstream);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099ED0
// Name: public: virtual void CHLClient::EmitCloseCaption(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::EmitCloseCaption(CHLClient *this, const char *captionname, float duration)
{
  CHudCloseCaption *m_pHudCloseCaption; // ecx

  if ( closecaption.m_pParent != nullptr && closecaption.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pHudCloseCaption = this->m_pHudCloseCaption;
    if ( m_pHudCloseCaption != nullptr )
      CHudCloseCaption::ProcessCaption(
        this: m_pHudCloseCaption,
        tokenname: captionname,
        duration,
        fromplayer: false,
        direct: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099F10
// Name: public: virtual void CHLClient::MarkEntitiesAsTouching(class IClientEntity __near *,class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::MarkEntitiesAsTouching(CHLClient *this, IClientEntity *e1, IClientEntity *e2)
{
  C_BaseEntity *v3; // esi
  C_BaseEntity *v4; // eax
  C_BaseEntity *v5; // edi
  float *v6; // ebx
  float *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  CGameTrace tr; // [esp+8h] [ebp-54h] BYREF

  v3 = e1->GetBaseEntity(this: e1);
  v4 = e2->GetBaseEntity(this: e2);
  v5 = v4;
  if ( v3 != nullptr && v4 != nullptr )
  {
    UTIL_ClearTrace(trace: &tr);
    v6 = (float *)v5->GetAbsOrigin(this: v5);
    v7 = (float *)v3->GetAbsOrigin(this: v3);
    v8 = (float)(v6[1] + v7[1]) * 0.5;
    v9 = (float)(v6[2] + v7[2]) * 0.5;
    tr.endpos.x = (float)(*v6 + *v7) * 0.5;
    tr.endpos.y = v8;
    tr.endpos.z = v9;
    C_BaseEntity::PhysicsMarkEntitiesAsTouching(this: v3, other: v5, trace: &tr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099FB0
// Name: private: virtual void CClientMaterialSystem::PostToolMessage(unsigned int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientMaterialSystem::PostToolMessage(
        CClientMaterialSystem *this,
        unsigned int hEntity,
        KeyValues *pMsg)
{
  ToolFramework_PostToolMessage(hEntity, msg: pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10099FE0
// Name: private: virtual unsigned int CClientMaterialSystem::GetCurrentRecordingEntity(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CClientMaterialSystem::GetCurrentRecordingEntity(CClientMaterialSystem *this)
{
  CClientEntityList *m_Index; // edi
  C_BaseEntity *BaseEntity; // esi

  if ( !ToolsEnabled() || !clienttools->IsInRecordingMode(this: clienttools) )
    return 0;
  if ( this->m_pProxyData != nullptr
    && (m_Index = (CClientEntityList *)cl_entitylist.m_Index,
        (BaseEntity = CClientEntityList::FirstBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index)) != nullptr) )
  {
    while ( BaseEntity != this->m_pProxyData && BaseEntity->GetClientRenderable(this: BaseEntity) != this->m_pProxyData )
    {
      BaseEntity = CClientEntityList::NextBaseEntity(this: m_Index, pEnt: BaseEntity);
      if ( BaseEntity == nullptr )
        goto LABEL_11;
    }
  }
  else
  {
LABEL_11:
    if ( materials->GetThreadMode(this: materials) != MATERIAL_SINGLE_THREADED )
      return 0;
    BaseEntity = view->GetCurrentlyDrawingEntity(this: view);
    if ( BaseEntity == nullptr )
      return 0;
  }
  if ( C_BaseEntity::IsToolRecording(this: BaseEntity) )
    return BaseEntity->m_ToolHandle;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009A090
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x1009A0A0
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1009A0C0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x1009A0D0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A100
// Name: public: CFunctorJob::CFunctorJob(class CFunctor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFunctorJob *__thiscall CFunctorJob::CFunctorJob(CFunctorJob *this, CFunctor *pFunctor, char *pszDescription)
{
  this->m_iRefs = 1;
  this->m_priority = JP_NORMAL;
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CFunctorJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctorJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pFunctor.m_pObject = pFunctor;
  if ( pszDescription != nullptr )
    V_strncpy(pDest: this->m_szDescription, pSrc: pszDescription, maxLen: 16);
  else
    this->m_szDescription[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009A190
// Name: public: virtual char const __near * CFunctorJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFunctorJob::Describe(CFunctorJob *this)
{
  return this->m_szDescription;
}

//------------------------------------------------------------------------------
// Address: 0x1009A1B0
// Name: public: virtual int CFunctorJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFunctorJob::DoExecute(CFunctorJob *this)
{
  this->m_pFunctor.m_pObject->operator()(this: this->m_pFunctor.m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009A1C0
// Name: public: virtual bool CGameClientExports::IsPlayerGameVoiceMuted(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameClientExports::IsPlayerGameVoiceMuted(CGameClientExports *this, int playerIndex)
{
  CVoiceStatus *ClientVoiceMgr; // eax

  ClientVoiceMgr = GetClientVoiceMgr();
  return CVoiceStatus::IsPlayerBlocked(this: ClientVoiceMgr, iPlayer: playerIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1009A1E0
// Name: public: virtual void CGameClientExports::MutePlayerGameVoice(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClientExports::MutePlayerGameVoice(CGameClientExports *this, int playerIndex)
{
  CVoiceStatus *ClientVoiceMgr; // eax

  ClientVoiceMgr = GetClientVoiceMgr();
  CVoiceStatus::SetPlayerBlockedState(this: ClientVoiceMgr, iPlayer: playerIndex, blocked: true);
}

//------------------------------------------------------------------------------
// Address: 0x1009A200
// Name: public: virtual void CGameClientExports::UnmutePlayerGameVoice(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClientExports::UnmutePlayerGameVoice(CGameClientExports *this, int playerIndex)
{
  CVoiceStatus *ClientVoiceMgr; // eax

  ClientVoiceMgr = GetClientVoiceMgr();
  CVoiceStatus::SetPlayerBlockedState(this: ClientVoiceMgr, iPlayer: playerIndex, blocked: false);
}

//------------------------------------------------------------------------------
// Address: 0x1009A220
// Name: public: virtual void CGameClientExports::OnGameUIActivated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClientExports::OnGameUIActivated(CGameClientExports *this)
{
  IGameEvent *v1; // eax

  v1 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gameui_activated", a3: 0, a4: 0);
  if ( v1 != nullptr )
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1009A250
// Name: public: virtual void CGameClientExports::OnGameUIHidden(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClientExports::OnGameUIHidden(CGameClientExports *this)
{
  IGameEvent *v1; // eax

  v1 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gameui_hidden", a3: 0, a4: 0);
  if ( v1 != nullptr )
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1009A280
// Name: public: virtual bool CGameClientExports::ClientWantsBlurEffect(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameClientExports::ClientWantsBlurEffect(CGameClientExports *this)
{
  IViewPort *ViewPortInterface; // eax
  IViewPort *v2; // eax
  int v3; // eax
  bool result; // al

  ViewPortInterface = GetViewPortInterface();
  result = false;
  if ( ViewPortInterface->GetActivePanel(this: ViewPortInterface) != nullptr )
  {
    v2 = GetViewPortInterface();
    v3 = (int)v2->GetActivePanel(this: v2);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 56))(a1: v3) != 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A2C0
// Name: public: virtual void CGameClientExports::CreateAchievementsPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClientExports::CreateAchievementsPanel(CGameClientExports *this, vgui::Panel *pParent)
{
  if ( g_pAchievementsAndStatsInterface != nullptr )
    g_pAchievementsAndStatsInterface->CreatePanel(this: g_pAchievementsAndStatsInterface, a2: pParent);
}

//------------------------------------------------------------------------------
// Address: 0x1009A2E0
// Name: public: virtual void CGameClientExports::DisplayAchievementPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClientExports::DisplayAchievementPanel(CGameClientExports *this)
{
  if ( g_pAchievementsAndStatsInterface != nullptr )
    g_pAchievementsAndStatsInterface->DisplayPanel(this: g_pAchievementsAndStatsInterface);
}

//------------------------------------------------------------------------------
// Address: 0x1009A300
// Name: public: virtual void CGameClientExports::ShutdownAchievementPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClientExports::ShutdownAchievementPanel(CGameClientExports *this)
{
  if ( g_pAchievementsAndStatsInterface != nullptr )
    g_pAchievementsAndStatsInterface->ReleasePanel(this: g_pAchievementsAndStatsInterface);
}

//------------------------------------------------------------------------------
// Address: 0x1009A320
// Name: public: virtual int CGameClientExports::GetAchievementsPanelMinWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameClientExports::GetAchievementsPanelMinWidth(CGameClientExports *this)
{
  if ( g_pAchievementsAndStatsInterface != nullptr )
    return g_pAchievementsAndStatsInterface->GetAchievementsPanelMinWidth(this: g_pAchievementsAndStatsInterface);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009A370
// Name: void ConfigureCurrentSystemLevel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigureCurrentSystemLevel()
{
  int m_nValue; // eax
  int v1; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // esi
  bool IsSplitScreen; // al
  int v8; // esi
  int v9; // [esp-18h] [ebp-40h]
  char szModName[32]; // [esp+0h] [ebp-28h] BYREF
  BOOL bVGUIIsSplitscreen; // [esp+20h] [ebp-8h]
  int nCPULevel; // [esp+24h] [ebp-4h]

  if ( cpu_level.m_pParent != nullptr && (m_nValue = cpu_level.m_pParent->m_Value.m_nValue) >= 0 )
  {
    if ( m_nValue > 2 )
      m_nValue = 2;
  }
  else
  {
    m_nValue = 0;
  }
  nCPULevel = m_nValue;
  if ( gpu_level.m_pParent != nullptr && (v1 = gpu_level.m_pParent->m_Value.m_nValue) >= 0 )
  {
    if ( v1 > 3 )
      v1 = 3;
  }
  else
  {
    v1 = 0;
  }
  v2 = v1;
  if ( mem_level.m_pParent != nullptr && (v3 = mem_level.m_pParent->m_Value.m_nValue) >= 0 )
  {
    if ( v3 > 2 )
      v3 = 2;
  }
  else
  {
    v3 = 0;
  }
  v4 = v3;
  if ( gpu_mem_level.m_pParent != nullptr && (v5 = gpu_mem_level.m_pParent->m_Value.m_nValue) >= 0 )
  {
    if ( v5 > 2 )
      v5 = 2;
  }
  else
  {
    v5 = 0;
  }
  v6 = v5;
  strcpy(szModName, "cstrike15");
  memset(&szModName[10], 0, 22);
  IsSplitScreen = VGui_IsSplitScreen();
  LOBYTE(bVGUIIsSplitscreen) = IsSplitScreen;
  if ( cl_disable_splitscreen_cpu_level_cfgs_in_pip.m_pParent != nullptr
    && cl_disable_splitscreen_cpu_level_cfgs_in_pip.m_pParent->m_Value.m_nValue != 0
    && IsSplitScreen
    && VGui_IsSplitScreenPIP() )
  {
    LOBYTE(bVGUIIsSplitscreen) = 0;
  }
  v9 = v6;
  v8 = nCPULevel;
  UpdateSystemLevel(nCPULevel, nGPULevel: v2, nMemLevel: v4, nGPUMemLevel: v9, bVGUIIsSplitscreen, pModName: szModName);
  if ( engine != nullptr )
    engine->ConfigureSystemLevel(this: engine, a2: v8, a3: v2);
  C_BaseEntity::UpdateVisibilityAllEntities();
  if ( view != nullptr )
    ((void (__thiscall *)(IViewRender *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))view->InitFadeData)(
      a1: view,
      a2: *(_DWORD *)szModName,
      a3: *(_DWORD *)&szModName[4],
      a4: *(_DWORD *)&szModName[8],
      a5: *(_DWORD *)&szModName[12],
      a6: *(_DWORD *)&szModName[16],
      a7: *(_DWORD *)&szModName[20],
      a8: *(_DWORD *)&szModName[24],
      a9: *(_DWORD *)&szModName[28]);
}

//------------------------------------------------------------------------------
// Address: 0x1009A500
// Name: public: virtual bool CHLClient::PlayerAudible(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHLClient::PlayerAudible(CHLClient *this, int iPlayerIndex)
{
  return (GetClientVoiceMgr()->m_AudiblePlayers.m_Ints[(iPlayerIndex - 1) >> 5] & (1 << ((iPlayerIndex - 1) & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009A530
// Name: void OnMovieStringTableChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnMovieStringTableChanged(
        void *object,
        INetworkStringTable *stringTable,
        int stringNumber,
        const char *newString)
{
  CUtlSymbol result; // [esp+6h] [ebp-2h] BYREF

  if ( CUtlSymbolTable::Find(this: &gHLClient.m_CachedMovies, &result, pString: newString)->m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: &gHLClient.m_CachedMovies, &result, pString: newString);
    g_pBIK->PrecacheMovie(this: g_pBIK, a2: newString, a3: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B4A0
// Name: void OnGPUMemLevelChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl OnGPUMemLevelChanged()
{
  ConfigureCurrentSystemLevel();
}

//------------------------------------------------------------------------------
// Address: 0x1009B4B0
// Name: void UpdateClientRenderableInPVSStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateClientRenderableInPVSStatus()
{
  unsigned int m_Index; // ebx
  int i; // eax
  int v2; // esi
  int v3; // edi
  char v4; // al
  int v5; // esi

  m_Index = cl_entitylist.m_Index;
  for ( i = *(unsigned __int16 *)(cl_entitylist.m_Index + 196708);
        i != 0xFFFF;
        i = *(unsigned __int16 *)(v3 + *(_DWORD *)(m_Index + 196696) + 14) )
  {
    v2 = *(_DWORD *)(m_Index + 196696);
    v3 = 16 * (unsigned __int16)i;
    v4 = *(_BYTE *)(v2 + v3 + 8);
    v5 = v3 + v2;
    if ( (v4 & 1) != 0 )
    {
      if ( (v4 & 2) == 0
        && g_pClientLeafSystem->IsRenderableInPVS(this: g_pClientLeafSystem, a2: *(IClientRenderable **)(v5 + 4)) )
      {
        *(_BYTE *)(v5 + 8) |= 2u;
      }
    }
    else if ( g_pClientLeafSystem->IsRenderableInPVS(this: g_pClientLeafSystem, a2: *(IClientRenderable **)(v5 + 4)) )
    {
      *(_BYTE *)(v5 + 8) |= 7u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B540
// Name: void UpdatePVSNotifiers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePVSNotifiers()
{
  IMDLCache *v0; // esi
  unsigned int m_Index; // ebx
  int v2; // eax
  int v3; // esi
  int v4; // edi
  char v5; // al
  int v6; // esi
  void (__thiscall ***v7)(_DWORD, _DWORD); // ecx
  IMDLCache *cacheCriticalSection; // [esp+8h] [ebp-4h]

  v0 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  m_Index = cl_entitylist.m_Index;
  v2 = *(unsigned __int16 *)(cl_entitylist.m_Index + 196708);
  if ( v2 != 0xFFFF )
  {
    do
    {
      v3 = *(_DWORD *)(m_Index + 196696);
      v4 = 16 * (unsigned __int16)v2;
      v5 = *(_BYTE *)(v3 + v4 + 8);
      v6 = v4 + v3;
      if ( (v5 & 1) != 0 )
      {
        if ( (v5 & 2) != 0 )
        {
          if ( (v5 & 4) != 0 )
            (***(void (__thiscall ****)(_DWORD, int))v6)(a1: *(_DWORD *)v6, a2: 1);
          *(_BYTE *)(v6 + 8) &= 0xF9u;
        }
        else
        {
          v7 = *(void (__thiscall ****)(_DWORD, _DWORD))v6;
          *(_BYTE *)(v6 + 8) = v5 & 0xFE;
          (**v7)(a1: v7, a2: 0);
        }
      }
      v2 = *(unsigned __int16 *)(*(_DWORD *)(m_Index + 196696) + v4 + 14);
    }
    while ( v2 != 0xFFFF );
    v0 = cacheCriticalSection;
  }
  v0->EndLock(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x1009B5E0
// Name: void OnRenderEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnRenderEnd()
{
  C_BaseAnimating::AutoAllowBoneAccess *v0; // ecx

  g_pClientLeafSystem->DisableLeafReinsertion(this: g_pClientLeafSystem, a2: false);
  C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: v0);
  UpdatePVSNotifiers();
}

//------------------------------------------------------------------------------
// Address: 0x1009B610
// Name: public: virtual void CHLClient::DispatchOnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::DispatchOnRestore(CHLClient *this)
{
  int v1; // edi
  unsigned int m_Index; // ecx
  IMDLCache *v3; // esi
  unsigned int v4; // ecx
  IHandleEntity *m_pEntity; // ecx

  v1 = 0;
  if ( g_RestoredEntities.m_Size <= 0 )
  {
    g_RestoredEntities.m_Size = 0;
  }
  else
  {
    do
    {
      m_Index = g_RestoredEntities.m_Memory.m_pMemory[v1].m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v3 = mdlcache;
        mdlcache->BeginLock(this: mdlcache);
        v4 = g_RestoredEntities.m_Memory.m_pMemory[v1].m_Index;
        if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
        m_pEntity->__vftable[19].GetRefEHandle(this: m_pEntity);
        v3->EndLock(this: v3);
      }
      ++v1;
    }
    while ( v1 < g_RestoredEntities.m_Size );
    g_RestoredEntities.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BD60
// Name: public: virtual void CFunctor0<bool (*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor0<bool (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor0<bool (__cdecl*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied();
}

//------------------------------------------------------------------------------
// Address: 0x1009CB40
// Name: cl_dumpsplithacks
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_dumpsplithacks()
{
  int i; // esi

  for ( i = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FirstInorder(this: &g_Hacks);
        i != -1;
        i = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
              this: &g_Hacks,
              i) )
  {
    _Msg(a1: "%s\n", g_Hacks.m_Elements.m_pMemory[i].m_Data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CB90
// Name: private: void CHLClient::UncacheAllMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::UncacheAllMaterials(CHLClient *this)
{
  int i; // esi
  IMaterial *m_Data; // ecx

  for ( i = (unsigned __int16)CUtlRBTree<IMaterial *,unsigned short,bool (__cdecl *)(IMaterial * const &,IMaterial * const &),CUtlMemory<UtlRBTreeNode_t<IMaterial *,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_CachedMaterials);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<IMaterial *,unsigned short,bool (__cdecl *)(IMaterial * const &,IMaterial * const &),CUtlMemory<UtlRBTreeNode_t<IMaterial *,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_CachedMaterials,
                                i) )
  {
    m_Data = this->m_CachedMaterials.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
    m_Data->DecrementReferenceCount(this: m_Data);
  }
  CUtlRBTree<IMaterial *,unsigned short,bool (__cdecl *)(IMaterial * const &,IMaterial * const &),CUtlMemory<UtlRBTreeNode_t<IMaterial *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_CachedMaterials);
}

//------------------------------------------------------------------------------
// Address: 0x1009CBF0
// Name: void ProcessOnDataChangedEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessOnDataChangedEvents()
{
  char v0; // al
  int m_Next; // ecx
  UtlLinkedListElem_t<CDataChangedEvent,unsigned short> *m_pMemory; // eax
  int v3; // esi
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  C_BaseEntity *v7; // eax
  UtlLinkedListElem_t<CDataChangedEvent,unsigned short> *v8; // eax
  bool bSaveAccess; // [esp+4h] [ebp-4h]

  v0 = ((int (__thiscall *)(IVEngineClient *, const char *, int))engine->SetLocalPlayerIsResolvable)(
         a1: engine,
         a2: "cdll_client_int.cpp",
         a3: 2740);
  LOWORD(m_Next) = g_DataChangedEvents.m_Head;
  bSaveAccess = v0;
  m_pMemory = g_DataChangedEvents.m_Memory.m_pMemory;
  if ( g_DataChangedEvents.m_Head != 0xFFFF )
  {
    do
    {
      v3 = (unsigned __int16)m_Next;
      *m_pMemory[(unsigned __int16)m_Next].m_Element.m_pStoredEvent = -1;
      m_pMemory[(unsigned __int16)m_Next].m_Element.m_pEntity->OnDataChanged(
        this: m_pMemory[(unsigned __int16)m_Next].m_Element.m_pEntity,
        a2: m_pMemory[(unsigned __int16)m_Next].m_Element.m_UpdateType);
      m_pMemory = g_DataChangedEvents.m_Memory.m_pMemory;
      m_Next = g_DataChangedEvents.m_Memory.m_pMemory[v3].m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  LOWORD(v4) = g_DataChangedEvents.m_Head;
  if ( g_DataChangedEvents.m_Head != 0xFFFF )
  {
    do
    {
      v5 = (unsigned __int16)v4;
      v6 = (int)m_pMemory[(unsigned __int16)v4].m_Element.m_pEntity->GetIClientUnknown(this: m_pMemory[(unsigned __int16)v4].m_Element.m_pEntity);
      v7 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 28))(a1: v6);
      C_BaseEntity::CheckInitPredictable(this: v7, context: "ProcessOnDataChangedEvents()");
      m_pMemory = g_DataChangedEvents.m_Memory.m_pMemory;
      v4 = g_DataChangedEvents.m_Memory.m_pMemory[v5].m_Next;
    }
    while ( v4 != 0xFFFF );
  }
  CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *)&g_DataChangedEvents);
  v8 = g_DataChangedEvents.m_Memory.m_pMemory;
  if ( g_DataChangedEvents.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DataChangedEvents.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DataChangedEvents.m_Memory.m_pMemory);
      v8 = nullptr;
      g_DataChangedEvents.m_Memory.m_pMemory = nullptr;
    }
    g_DataChangedEvents.m_Memory.m_nAllocationCount = 0;
  }
  g_DataChangedEvents.m_FirstFree = -1;
  g_DataChangedEvents.m_pElements = v8;
  *(_DWORD *)&g_DataChangedEvents.m_NumAlloced = -65536;
  engine->SetActiveSplitScreenPlayerSlot(this: engine, a2: 0);
  engine->SetLocalPlayerIsResolvable(this: engine, a2: "cdll_client_int.cpp", a3: 2764, a4: bSaveAccess);
}

//------------------------------------------------------------------------------
// Address: 0x1009CD40
// Name: void OnRenderStart(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall OnRenderStart(int a1@<ebp>, int a2@<edi>)
{
  IMatRenderContext *v2; // ebx
  IMDLCache *v3; // esi
  IMDLCache *v4; // edi
  C_BaseAnimating::AutoAllowBoneAccess *v5; // ecx
  CParticleMgr *v6; // eax
  vgui::PropertyPage *v7; // ecx
  float flTimeDelta; // [esp+50h] [ebp-Ch]

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = mdlcache;
  ((void (__thiscall *)(IMDLCache *, int))mdlcache->BeginLock)(a1: mdlcache, a2);
  v4 = mdlcache;
  mdlcache->BeginCoarseLock(this: mdlcache);
  partition->SuppressLists(this: partition, a2: 428, a3: true);
  C_BaseEntity::SetAbsQueriesValid(bValid: false);
  Rope_ResetCounters();
  C_BaseEntity::InterpolateServerEntities();
  C_BaseAnimating::InvalidateBoneCaches();
  C_BaseFlex::InvalidateFlexCaches();
  C_BaseEntity::SetAbsQueriesValid(bValid: true);
  C_BaseEntity::EnableAbsRecomputations(bEnable: true);
  C_BaseAnimating::PushAllowBoneAccess(
    bAllowForNormalModels: true,
    bAllowForViewModels: false,
    tagPush: "OnRenderStart->CViewRender::SetUpView");
  C_BaseEntity::MarkAimEntsDirty();
  input->CAM_Think(this: input);
  C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: v5);
  C_BaseAnimating::PushAllowBoneAccess(
    bAllowForNormalModels: true,
    bAllowForViewModels: true,
    tagPush: "CViewRender::SetUpView->OnRenderEnd");
  C_BaseAnimating::UpdateClientSideAnimations();
  view->OnRenderStart(this: view);
  partition->SuppressLists(this: partition, a2: 428, a3: false);
  ProcessOnDataChangedEvents();
  g_SmokeFogOverlayAlpha = 0.0;
  g_SmokeFogOverlayColor.x = 0.0;
  g_SmokeFogOverlayColor.y = 0.0;
  g_SmokeFogOverlayColor.z = 0.0;
  C_BaseAnimating::ThreadedBoneSetup();
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "Client SimulateEntities",
    a3: 0,
    a4: "Client Simulation",
    a5: false,
    a6: 4);
  CClientThinkList::PerformThinkFunctions(this: &g_ClientThinkList);
  C_BaseEntity::SimulateEntities();
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  PhysicsSimulate();
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "Client TempEnts",
    a3: 0,
    a4: "Client Simulation",
    a5: false,
    a6: 1);
  engine->FireEvents(this: engine);
  tempents->Update(this: tempents);
  beams->UpdateTempEntBeams(this: beams);
  SetBeamCreationAllowed(state: false);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ParticleMgr()->Simulate",
    a3: 0,
    a4: "Particle Simulation",
    a5: false,
    a6: 4);
  flTimeDelta = *(float *)(gpGlobals.m_Index + 16);
  v6 = ParticleMgr();
  CParticleMgr::Simulate(this: v6, flTimeDelta);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  C_BaseEntity::CalcAimEntPositions(a1);
  if ( ToolsEnabled() )
    C_BaseEntity::ToolRecordEntities();
  engine->UpdateDAndELights(this: engine);
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v7);
  g_pClientLeafSystem->RecomputeRenderableLeaves(this: g_pClientLeafSystem);
  g_pClientShadowMgr->ReprojectShadows(this: g_pClientShadowMgr);
  g_pClientShadowMgr->AdvanceFrame(this: g_pClientShadowMgr);
  g_pClientLeafSystem->DisableLeafReinsertion(this: g_pClientLeafSystem, a2: true);
  v4->EndCoarseLock(this: v4);
  v3->EndLock(this: v3);
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D000
// Name: public: virtual void CHLClient::FrameStageNotify(enum ClientFrameStage_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::FrameStageNotify(CHLClient *this, ClientFrameStage_t curStage)
{
  C_HLTVCamera *v2; // eax

  g_CurFrameStage = curStage;
  g_bEngineIsHLTV = engine->IsHLTV(this: engine);
  switch ( curStage )
  {
    case FRAME_START:
      SetFXCreationAllowed(state: true);
      SetBeamCreationAllowed(state: true);
      C_BaseEntity::CheckCLInterpChanged();
      engine->SetLocalPlayerIsResolvable(this: engine, a2: "cdll_client_int.cpp", a3: 3085, a4: false);
      break;
    case FRAME_NET_UPDATE_START:
      C_BaseEntity::EnableAbsRecomputations(bEnable: false);
      C_BaseEntity::SetAbsQueriesValid(bValid: false);
      g_flLastPacketTimestamp = engine->GetLastTimeStamp(this: engine);
      partition->SuppressLists(this: partition, a2: 428, a3: true);
      break;
    case FRAME_NET_UPDATE_POSTDATAUPDATE_END:
      prediction->PostEntityPacketReceived(this: prediction);
      v2 = HLTVCamera();
      C_HLTVCamera::PostEntityPacketReceived(this: v2);
      break;
    case FRAME_NET_UPDATE_END:
      ProcessCacheUsedMaterials();
      C_BaseEntity::EnableAbsRecomputations(bEnable: true);
      C_BaseEntity::SetAbsQueriesValid(bValid: true);
      partition->SuppressLists(this: partition, a2: 428, a3: false);
      break;
    case FRAME_RENDER_START:
      engine->SetLocalPlayerIsResolvable(this: engine, a2: "cdll_client_int.cpp", a3: 3016, a4: false);
      OnRenderStart();
      break;
    case FRAME_RENDER_END:
      OnRenderEnd();
      engine->SetLocalPlayerIsResolvable(this: engine, a2: "cdll_client_int.cpp", a3: 3028, a4: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D150
// Name: public: virtual void CHLClient::Save(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::Save(CHLClient *this, CSaveRestoreData *s)
{
  CSave saveHelper; // [esp+0h] [ebp-28h] BYREF

  CSave::CSave(this: &saveHelper, pdata: s);
  g_pGameSaveRestoreBlockSet->Save(this: g_pGameSaveRestoreBlockSet, a2: &saveHelper);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&saveHelper.m_BlockStartStack);
}

//------------------------------------------------------------------------------
// Address: 0x1009D190
// Name: public: virtual void CHLClient::WriteSaveHeaders(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::WriteSaveHeaders(CHLClient *this, CSaveRestoreData *s)
{
  CSave saveHelper; // [esp+0h] [ebp-28h] BYREF

  CSave::CSave(this: &saveHelper, pdata: s);
  g_pGameSaveRestoreBlockSet->WriteSaveHeaders(this: g_pGameSaveRestoreBlockSet, a2: &saveHelper);
  g_pGameSaveRestoreBlockSet->PostSave(this: g_pGameSaveRestoreBlockSet);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&saveHelper.m_BlockStartStack);
}

//------------------------------------------------------------------------------
// Address: 0x1009D1D0
// Name: public: virtual void CHLClient::ReadRestoreHeaders(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::ReadRestoreHeaders(CHLClient *this, CSaveRestoreData *s)
{
  CRestore restoreHelper; // [esp+0h] [ebp-28h] BYREF

  CRestore::CRestore(this: &restoreHelper, pdata: s);
  g_pGameSaveRestoreBlockSet->PreRestore(this: g_pGameSaveRestoreBlockSet);
  g_pGameSaveRestoreBlockSet->ReadRestoreHeaders(this: g_pGameSaveRestoreBlockSet, a2: &restoreHelper);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restoreHelper.m_BlockEndStack);
}

//------------------------------------------------------------------------------
// Address: 0x1009D210
// Name: public: virtual void CHLClient::Restore(class CSaveRestoreData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::Restore(CHLClient *this, CSaveRestoreData *s, BOOL b)
{
  CRestore restore; // [esp+0h] [ebp-28h] BYREF

  CRestore::CRestore(this: &restore, pdata: s);
  g_pGameSaveRestoreBlockSet->Restore(this: g_pGameSaveRestoreBlockSet, a2: &restore, a3: b);
  g_pGameSaveRestoreBlockSet->PostRestore(this: g_pGameSaveRestoreBlockSet);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restore.m_BlockEndStack);
}

//------------------------------------------------------------------------------
// Address: 0x1009D2D0
// Name: class CFunctor __near * CreateFunctor<bool>(bool (*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__cdecl CreateFunctor<bool>(bool (__cdecl *pfnProxied)())
{
  CFunctor *result; // eax

  result = (CFunctor *)MemAlloc_Alloc(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result[1].m_nUserID = 1;
  result->__vftable = (CFunctor_vtbl *)&CFunctor0<bool (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
  result[1].__vftable = (CFunctor_vtbl *)&CFunctor0<bool (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  result[2].__vftable = (CFunctor_vtbl *)pfnProxied;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009D4C0
// Name: public: virtual int CHLClient::Init(void __near * (*)(char const __near *,int __near *),class CGlobalVarsBase __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLClient::Init(
        CHLClient *this,
        void *(__cdecl *appSystemFactory)(const char *, int *),
        CGlobalVarsBase *pGlobals)
{
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  void (__thiscall *v13)(int, const char *); // edi
  int v14; // ecx
  int v15; // ecx
  CFunctorJob *v16; // edi
  CFunctor *v17; // eax
  char *v18; // edi
  int v19; // ecx
  CParticleMgr *v20; // eax
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  CHud *Hud; // eax
  int v25; // ecx
  IMaterialSystem *v26; // [esp-8h] [ebp-18h]
  int v27; // [esp-4h] [ebp-14h]
  factorylist_t factories; // [esp+Ch] [ebp-4h] BYREF

  _COM_TimestampedLog(a1: this, a2: "ClientDLL factories - Start");
  engine = (IVEngineClient *)appSystemFactory(a1: "VEngineClient013", a2: nullptr);
  if ( engine != nullptr )
  {
    modelrender = (IVModelRender *)appSystemFactory(a1: "VEngineModel016", a2: nullptr);
    if ( modelrender != nullptr )
    {
      effects = (IVEfx *)appSystemFactory(a1: "VEngineEffects001", a2: nullptr);
      if ( effects != nullptr )
      {
        enginetrace = (IEngineTrace *)appSystemFactory(a1: "EngineTraceClient004", a2: nullptr);
        if ( enginetrace != nullptr )
        {
          filelogginglistener = (IFileLoggingListener *)appSystemFactory(a1: "FileLoggingListener001", a2: nullptr);
          if ( filelogginglistener != nullptr )
          {
            render = (IVRenderView *)appSystemFactory(a1: "VEngineRenderView013", a2: nullptr);
            if ( render != nullptr )
            {
              debugoverlay = (IVDebugOverlay *)appSystemFactory(a1: "VDebugOverlay004", a2: nullptr);
              if ( debugoverlay != nullptr )
              {
                datacache = (IDataCache *)appSystemFactory(a1: "VDataCache003", a2: nullptr);
                if ( datacache != nullptr && mdlcache != nullptr )
                {
                  modelinfo = (IVModelInfoClient *)appSystemFactory(a1: "VModelInfoClient004", a2: nullptr);
                  if ( modelinfo != nullptr )
                  {
                    enginevgui = (IEngineVGui *)appSystemFactory(a1: "VEngineVGui001", a2: nullptr);
                    if ( enginevgui != nullptr )
                    {
                      networkstringtable = (INetworkStringTableContainer *)appSystemFactory(
                                                                             a1: "VEngineClientStringTable001",
                                                                             a2: nullptr);
                      if ( networkstringtable != nullptr )
                      {
                        partition = (ISpatialPartition *)appSystemFactory(a1: "SpatialPartition001", a2: nullptr);
                        if ( partition != nullptr )
                        {
                          shadowmgr = (IShadowMgr *)appSystemFactory(a1: "VEngineShadowMgr002", a2: nullptr);
                          if ( shadowmgr != nullptr )
                          {
                            staticpropmgr = (IStaticPropMgrClient *)appSystemFactory(
                                                                      a1: "StaticPropMgrClient005",
                                                                      a2: nullptr);
                            if ( staticpropmgr != nullptr )
                            {
                              enginesound = (IEngineSound *)appSystemFactory(a1: "IEngineSoundClient003", a2: nullptr);
                              if ( enginesound != nullptr )
                              {
                                filesystem = (IFileSystem *)appSystemFactory(a1: "VFileSystem017", a2: nullptr);
                                if ( filesystem != nullptr )
                                {
                                  random = (IUniformRandomStream *)appSystemFactory(a1: "VEngineRandom001", a2: nullptr);
                                  if ( random != nullptr )
                                  {
                                    gameuifuncs = (IGameUIFuncs *)appSystemFactory(
                                                                    a1: "VENGINE_GAMEUIFUNCS_VERSION005",
                                                                    a2: nullptr);
                                    if ( gameuifuncs != nullptr )
                                    {
                                      gameeventmanager = (IGameEventManager2 *)appSystemFactory(
                                                                                 a1: "GAMEEVENTSMANAGER002",
                                                                                 a2: nullptr);
                                      if ( gameeventmanager != nullptr )
                                      {
                                        soundemitterbase = (ISoundEmitterSystemBase *)appSystemFactory(
                                                                                        a1: "VSoundEmitter003",
                                                                                        a2: nullptr);
                                        if ( soundemitterbase != nullptr )
                                        {
                                          inputsystem = (IInputSystem *)appSystemFactory(
                                                                          a1: "InputSystemVersion001",
                                                                          a2: nullptr);
                                          if ( inputsystem != nullptr )
                                          {
                                            avi = (IAvi *)appSystemFactory(a1: "VAvi001", a2: nullptr);
                                            if ( avi != nullptr )
                                            {
                                              bik = (IBik *)appSystemFactory(a1: "VBik001", a2: nullptr);
                                              if ( bik != nullptr )
                                              {
                                                scenefilecache = (ISceneFileCache *)appSystemFactory(
                                                                                      a1: "SceneFileCache002",
                                                                                      a2: nullptr);
                                                if ( scenefilecache != nullptr )
                                                {
                                                  blackboxrecorder = (IBlackBox *)appSystemFactory(
                                                                                    a1: "BlackBoxVersion001",
                                                                                    a2: nullptr);
                                                  if ( blackboxrecorder != nullptr )
                                                  {
                                                    xboxsystem = (IXboxSystem *)appSystemFactory(
                                                                                  a1: "XboxSystemInterface002",
                                                                                  a2: nullptr);
                                                    if ( xboxsystem != nullptr )
                                                    {
                                                      g_pGameTypes = (IGameTypes *)appSystemFactory(
                                                                                     a1: "VENGINE_GAMETYPES_VERSION001",
                                                                                     a2: nullptr);
                                                      if ( g_pGameTypes != nullptr )
                                                      {
                                                        gamestatsuploader = (IUploadGameStats *)appSystemFactory(
                                                                                                  a1: "ServerUploadGameStats001",
                                                                                                  a2: nullptr);
                                                        if ( gamestatsuploader != nullptr
                                                          && g_pMatSystemSurface != nullptr )
                                                        {
                                                          v5 = _CommandLine(a1: v4);
                                                          if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(
                                                                 a1: v5,
                                                                 a2: "-noscripting",
                                                                 a3: 0) == 0 )
                                                            scriptmanager = (IScriptManager *)appSystemFactory(
                                                                                                a1: "VScriptManager009",
                                                                                                a2: nullptr);
                                                          factories.appSystemFactory = appSystemFactory;
                                                          FactoryList_Store(sourceData: &factories);
                                                          _COM_TimestampedLog(a1: v6, a2: "soundemitterbase->Connect");
                                                          if ( soundemitterbase->Connect(
                                                                 this: soundemitterbase,
                                                                 a2: appSystemFactory) != 0 )
                                                          {
                                                            v8 = _CommandLine(a1: v7);
                                                            if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(
                                                                   a1: v8,
                                                                   a2: "-textmode") != 0 )
                                                              g_bTextMode = true;
                                                            v10 = _CommandLine(a1: v9);
                                                            if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(
                                                                   a1: v10,
                                                                   a2: "-makedevshots") != 0 )
                                                              g_MakingDevShots = true;
                                                            v12 = _CommandLine(a1: v11);
                                                            if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(
                                                                   a1: v12,
                                                                   a2: "-headtracking") != 0 )
                                                              g_bHeadTrackingEnabled = true;
                                                            materials_stub = (IMaterialSystemStub *)appSystemFactory(a1: "VMaterialSystemStub001", a2: nullptr);
                                                            if ( g_pMaterialSystemHardwareConfig != nullptr )
                                                            {
                                                              CGaussianRandomStream::AttachToStream(
                                                                this: &s_GaussianRandomStream,
                                                                a2: random);
                                                              v13 = (void (__thiscall *)(int, const char *))_COM_TimestampedLog;
                                                              g_pcv_ThreadMode = g_pCVar->FindVar_2(
                                                                                   this: g_pCVar,
                                                                                   a2: "host_thread_mode");
                                                              _COM_TimestampedLog(a1: v14, a2: "InitGameSystems");
                                                              if ( cl_threaded_init.m_pParent != nullptr
                                                                && cl_threaded_init.m_pParent->m_Value.m_nValue != 0 )
                                                              {
                                                                v16 = (CFunctorJob *)MemAlloc_Alloc(nSize: 0x44u);
                                                                if ( v16 != nullptr )
                                                                {
                                                                  v17 = CreateFunctor<bool>(pfnProxied: InitParticleManager);
                                                                  v18 = (char *)CFunctorJob::CFunctorJob(
                                                                                  this: v16,
                                                                                  pFunctor: v17,
                                                                                  pszDescription: nullptr);
                                                                }
                                                                else
                                                                {
                                                                  v18 = nullptr;
                                                                }
                                                                ((void (__thiscall *)(IThreadPool *, char *, int))_g_pThreadPool->AddJob)(
                                                                  a1: _g_pThreadPool,
                                                                  a2: v18,
                                                                  a3: v27);
                                                                InitGameSystems(a1: v18, appSystemFactory);
                                                                while ( !CJob::IsFinished(this: (CJob *)v18) )
                                                                {
                                                                  g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
                                                                  _ThreadSleep(a1: 50);
                                                                }
                                                                (*(void (__thiscall **)(char *))(*(_DWORD *)v18 + 4))(a1: v18);
                                                                v13 = (void (__thiscall *)(int, const char *))_COM_TimestampedLog;
                                                                _COM_TimestampedLog(
                                                                  a1: v19,
                                                                  a2: "C_BaseAnimating::InitBoneSetupThreadPool");
                                                                goto LABEL_53;
                                                              }
                                                              _COM_TimestampedLog(a1: v15, a2: "ParticleMgr()->Init");
                                                              v26 = materials;
                                                              v20 = ParticleMgr();
                                                              if ( CParticleMgr::Init(
                                                                     this: v20,
                                                                     count: 0x800u,
                                                                     pMaterials: v26) != 0 )
                                                              {
                                                                _COM_TimestampedLog(
                                                                  a1: v21,
                                                                  a2: "InitGameSystems - Start");
                                                                InitGameSystems(
                                                                  a1: (const char *)_COM_TimestampedLog,
                                                                  appSystemFactory);
                                                                _COM_TimestampedLog(
                                                                  a1: v22,
                                                                  a2: "InitGameSystems - End");
                                                                _COM_TimestampedLog(
                                                                  a1: v23,
                                                                  a2: "C_BaseAnimating::InitBoneSetupThreadPool");
LABEL_53:
                                                                C_BaseAnimating::InitBoneSetupThreadPool();
                                                                Hud = GetHud(nSlot: 0);
                                                                this->m_pHudCloseCaption = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
                                                                g_pGameTypes->Initialize(this: g_pGameTypes, a2: false);
                                                                v13(a1: v25, a2: "ClientDLL Init - Finish");
                                                                return 1;
                                                              }
                                                            }
                                                          }
                                                          return 0;
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009D9F0
// Name: public: virtual void CHLClient::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::Shutdown(CHLClient *this)
{
  vgui::PropertyPage *v2; // ecx
  ISaveRestoreBlockSet_vtbl *v3; // esi
  CGameInstructorSaveRestoreBlockHandler *GameInstructorRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v5; // esi
  CViewEffectsSaveRestoreBlockHandler *ViewEffectsRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v7; // esi
  CPhysSaveRestoreBlockHandler *PhysSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v9; // esi
  CEntitySaveRestoreBlockHandler *EntitySaveRestoreBlockHandler; // eax
  int i; // esi
  IClientMode *ClientMode; // eax
  ClientModeCSFullscreen *FullscreenClientMode; // eax
  int j; // esi
  IClientMode *v15; // eax
  ClientModeCSFullscreen *v16; // eax
  int v17; // esi
  const char *v18; // eax
  CHud *Hud; // eax
  vgui::PropertyPage *v20; // ecx
  CParticleMgr *v21; // eax
  vgui::PropertyPage *v22; // ecx

  if ( g_pAchievementsAndStatsInterface != nullptr )
    g_pAchievementsAndStatsInterface->ReleasePanel(this: g_pAchievementsAndStatsInterface);
  ActivityList_Free();
  EventList_Free();
  VGui_ClearVideoPanels();
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v2);
  ClientWorldFactoryShutdown();
  v3 = g_pGameSaveRestoreBlockSet->__vftable;
  GameInstructorRestoreBlockHandler = GetGameInstructorRestoreBlockHandler();
  v3->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: GameInstructorRestoreBlockHandler);
  v5 = g_pGameSaveRestoreBlockSet->__vftable;
  ViewEffectsRestoreBlockHandler = GetViewEffectsRestoreBlockHandler();
  v5->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: ViewEffectsRestoreBlockHandler);
  v7 = g_pGameSaveRestoreBlockSet->__vftable;
  PhysSaveRestoreBlockHandler = GetPhysSaveRestoreBlockHandler();
  v7->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: PhysSaveRestoreBlockHandler);
  v9 = g_pGameSaveRestoreBlockSet->__vftable;
  EntitySaveRestoreBlockHandler = GetEntitySaveRestoreBlockHandler();
  v9->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: EntitySaveRestoreBlockHandler);
  ClientVoiceMgr_Shutdown();
  for ( i = 0; i < 1; ++i )
  {
    ClientMode = GetClientMode();
    ClientMode->Disable(this: ClientMode);
    if ( i == 0 )
    {
      FullscreenClientMode = GetFullscreenClientMode();
      FullscreenClientMode->Disable(this: FullscreenClientMode);
    }
  }
  for ( j = 0; j < 1; ++j )
  {
    v15 = GetClientMode();
    v15->Shutdown(this: v15);
    if ( j == 0 )
    {
      v16 = GetFullscreenClientMode();
      v16->Shutdown(this: v16);
    }
  }
  input->Shutdown_All(this: input);
  C_BaseTempEntity::ClearDynamicTempEnts();
  TermSmokeFogOverlay();
  view->Shutdown(this: view);
  CParticleSystemMgr::UncacheAllParticleSystems(this: g_pParticleSystemMgr);
  v17 = 0;
  if ( this->m_CachedMovies.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v18 = CUtlSymbolTable::String(this: &this->m_CachedMovies, id: (CUtlSymbol)v17);
      g_pBIK->EvictPrecachedMovie(this: g_pBIK, a2: v18);
      ++v17;
    }
    while ( v17 < this->m_CachedMovies.m_Lookup.m_NumElements );
  }
  CUtlSymbolTable::RemoveAll(this: &this->m_CachedMovies);
  CHLClient::UncacheAllMaterials(this);
  IGameSystem::ShutdownAllSystems();
  Hud = GetHud(nSlot: -1);
  CHud::Shutdown(this: Hud);
  VGui_Shutdown(this: v20);
  v21 = ParticleMgr();
  CParticleMgr::Term(this: v21, bCanReferenceOtherStaticObjects: true);
  ClearKeyValuesCache();
  g_SteamAPIContext.m_pSteamUser = nullptr;
  g_SteamAPIContext.m_pSteamFriends = nullptr;
  g_SteamAPIContext.m_pSteamUtils = nullptr;
  g_SteamAPIContext.m_pSteamMatchmaking = nullptr;
  g_SteamAPIContext.m_pSteamUserStats = nullptr;
  g_SteamAPIContext.m_pSteamApps = nullptr;
  g_SteamAPIContext.m_pSteamMatchmakingServers = nullptr;
  g_SteamAPIContext.m_pSteamNetworking = nullptr;
  g_SteamAPIContext.m_pSteamRemoteStorage = nullptr;
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v22);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
  gameeventmanager = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009DBD0
// Name: public: virtual void CHLClient::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::LevelShutdown(CHLClient *this)
{
  C_BaseEntityClassList *i; // esi
  CParticleMgr *v3; // eax
  vgui::PropertyPage *v4; // ecx
  CHud *Hud; // eax
  CCenterPrint *CenterPrint; // eax
  int v7; // esi
  const char *v8; // eax

  if ( g_bLevelInitialized )
  {
    g_bLevelInitialized = false;
    C_BaseEntity::EnableAbsRecomputations(bEnable: false);
    IGameSystem::LevelShutdownPreEntityAllSystems();
    C_Sprite::DestroyAllClientside();
    C_PhysPropClientside::DestroyAll();
    modemanager->LevelShutdown(this: modemanager);
    tempents->LevelShutdown(this: tempents);
    CClientEntityList::Release(this: (CClientEntityList *)cl_entitylist.m_Index);
    for ( i = s_pClassLists; i != nullptr; i = i->m_pNextClassList )
      i->LevelShutdown(this: i);
    IGameSystem::LevelShutdownPostEntityAllSystems();
    view->LevelShutdown(this: view);
    beams->ClearBeams(this: beams);
    v3 = ParticleMgr();
    CParticleMgr::RemoveAllEffects(this: v3);
    C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v4);
    Hud = GetHud(nSlot: -1);
    CHud::LevelShutdown(this: Hud);
    CenterPrint = GetCenterPrint();
    CenterPrint->Clear(this: CenterPrint);
    ClientVoiceMgr_LevelInit();
    messagechars->Clear(this: messagechars);
    C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)g_pParticleSystemMgr);
    CParticleSystemMgr::UncacheAllParticleSystems(this: g_pParticleSystemMgr);
    v7 = 0;
    if ( this->m_CachedMovies.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v8 = CUtlSymbolTable::String(this: &this->m_CachedMovies, id: (CUtlSymbol)v7);
        g_pBIK->EvictPrecachedMovie(this: g_pBIK, a2: v8);
        ++v7;
      }
      while ( v7 < this->m_CachedMovies.m_Lookup.m_NumElements );
    }
    CUtlSymbolTable::RemoveAll(this: &this->m_CachedMovies);
    CHLClient::UncacheAllMaterials(this);
    g_pStringTableParticleEffectNames = nullptr;
    g_StringTableEffectDispatch = nullptr;
    g_StringTableVguiScreen = nullptr;
    g_pStringTableMaterials = nullptr;
    g_pStringTableInfoPanel = nullptr;
    g_pStringTableClientSideChoreoScenes = nullptr;
    g_pStringTableMovies = nullptr;
    CStudioHdr::CActivityToSequenceMapping::ResetMappings();
  }
  else
  {
    g_pStringTableParticleEffectNames = nullptr;
    g_StringTableEffectDispatch = nullptr;
    g_StringTableVguiScreen = nullptr;
    g_pStringTableMaterials = nullptr;
    g_pStringTableInfoPanel = nullptr;
    g_pStringTableClientSideChoreoScenes = nullptr;
    g_pStringTableMovies = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DD50
// Name: public: virtual void CHLClient::SaveWriteFields(class CSaveRestoreData __near *,char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::SaveWriteFields(
        CHLClient *this,
        CSaveRestoreData *pSaveData,
        const char *pname,
        void *pBaseData,
        datamap_t *pMap,
        typedescription_t *pFields,
        int fieldCount)
{
  CSave saveHelper; // [esp+0h] [ebp-28h] BYREF

  CSave::CSave(this: &saveHelper, pdata: pSaveData);
  CSave::WriteFields(this: &saveHelper, pname, pBaseData, pRootMap: pMap, pFields, fieldCount);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&saveHelper.m_BlockStartStack);
}

//------------------------------------------------------------------------------
// Address: 0x1009DD90
// Name: public: virtual void CHLClient::SaveReadFields(class CSaveRestoreData __near *,char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::SaveReadFields(
        CHLClient *this,
        CSaveRestoreData *pSaveData,
        const char *pname,
        void *pBaseData,
        datamap_t *pMap,
        typedescription_t *pFields,
        int fieldCount)
{
  CRestore restoreHelper; // [esp+0h] [ebp-28h] BYREF

  CRestore::CRestore(this: &restoreHelper, pdata: pSaveData);
  CRestore::ReadFields(this: &restoreHelper, pname, pBaseData, pRootMap: pMap, pFields, fieldCount);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restoreHelper.m_BlockEndStack);
}

//------------------------------------------------------------------------------
// Address: 0x1009DDD0
// Name: void AddRestoredEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddRestoredEntity(C_BaseEntity *pEntity)
{
  unsigned int m_Index; // edi
  int m_Size; // eax
  int v3; // esi
  CHandle<C_BaseEntity> *m_pMemory; // ecx
  int v5; // eax
  CHandle<C_BaseEntity> *v6; // eax

  if ( pEntity != nullptr )
  {
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    m_Size = g_RestoredEntities.m_Size;
    v3 = g_RestoredEntities.m_Size;
    if ( g_RestoredEntities.m_Size + 1 > g_RestoredEntities.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_RestoredEntities,
        num: g_RestoredEntities.m_Size - g_RestoredEntities.m_Memory.m_nAllocationCount + 1);
      m_Size = g_RestoredEntities.m_Size;
    }
    m_pMemory = g_RestoredEntities.m_Memory.m_pMemory;
    g_RestoredEntities.m_Size = m_Size + 1;
    v5 = m_Size - v3;
    g_RestoredEntities.m_pElements = g_RestoredEntities.m_Memory.m_pMemory;
    if ( v5 > 0 )
    {
      _V_memmove(
        dest: (void *)&g_RestoredEntities.m_Memory.m_pMemory[v3 + 1],
        src: &g_RestoredEntities.m_Memory.m_pMemory[v3],
        count: 4 * v5);
      m_pMemory = g_RestoredEntities.m_Memory.m_pMemory;
    }
    v6 = &m_pMemory[v3];
    if ( v6 != nullptr )
      v6->m_Index = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DEB0
// Name: public: virtual char const __near * CClientDLLSharedAppSystems::GetDllName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CClientDLLSharedAppSystems::GetDllName(CClientDLLSharedAppSystems *this, int idx)
{
  return this->m_Systems.m_Memory.m_pMemory[idx].m_pModuleName;
}

//------------------------------------------------------------------------------
// Address: 0x1009DEC0
// Name: public: virtual char const __near * CClientDLLSharedAppSystems::GetInterfaceName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CClientDLLSharedAppSystems::GetInterfaceName(CClientDLLSharedAppSystems *this, int idx)
{
  return this->m_Systems.m_Memory.m_pMemory[idx].m_pInterfaceName;
}

//------------------------------------------------------------------------------
// Address: 0x1009DEE0
// Name: void ClearDataChangedEvent(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearDataChangedEvent(int iStoredEvent)
{
  if ( iStoredEvent != -1 )
  {
    CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *)&g_DataChangedEvents,
      elem: iStoredEvent);
    g_DataChangedEvents.m_Memory.m_pMemory[(unsigned __int16)iStoredEvent].m_Next = g_DataChangedEvents.m_FirstFree;
    g_DataChangedEvents.m_FirstFree = iStoredEvent;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E0E0
// Name: public: virtual void CHLClient::InvalidateMdlCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::InvalidateMdlCache(CHLClient *this)
{
  C_BaseEntity *i; // ebx
  C_BaseAnimating *v2; // eax
  C_BaseAnimating *v3; // edi
  CStudioHdr *m_pStudioHdr; // esi

  for ( i = CClientEntityList::FirstBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index);
        i != nullptr;
        i = CClientEntityList::NextBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, pEnt: i) )
  {
    v2 = i->GetBaseAnimating(this: i);
    v3 = v2;
    if ( v2 != nullptr )
    {
      C_BaseAnimating::UnlockStudioHdr(this: v2);
      m_pStudioHdr = v3->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr )
      {
        CStudioHdr::Term(this: v3->m_pStudioHdr);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneParent);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneFlags);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
        C_BaseEntity::operator delete(pMem: m_pStudioHdr);
        v3->m_pStudioHdr = nullptr;
      }
    }
  }
  CStudioHdr::CActivityToSequenceMapping::ResetMappings();
}

//------------------------------------------------------------------------------
// Address: 0x1009E170
// Name: public: void CHLClient::PrecacheMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::PrecacheMaterial(CHLClient *this, char *pMaterialName)
{
  unsigned __int8 *v2; // ebx
  int v3; // edi
  void *v4; // esp
  const char *v5; // edi
  char *v6; // eax
  const char *v7; // eax
  CHLClient *v8; // esi
  unsigned __int8 v9[12]; // [esp+0h] [ebp-10h] BYREF
  CHLClient *v10; // [esp+Ch] [ebp-4h]

  v2 = (unsigned __int8 *)pMaterialName;
  v10 = this;
  v3 = _V_strlen(str: pMaterialName);
  v4 = alloca(v3 + 1);
  v5 = (const char *)(v3 + 1);
  memcpy(dst: v9, src: v2, count: (unsigned int)v5);
  v6 = _V_strstr(s1: (const char *)v9, search: ".vmt");
  if ( v6 != nullptr )
    *v6 = 0;
  v7 = (const char *)materials->FindMaterial(this: materials, a2: v9, a3: "Precached", a4: 1, a5: 0);
  pMaterialName = (char *)v7;
  if ( v7 != nullptr && (*(unsigned __int8 (__thiscall **)(const char *))(*(_DWORD *)v7 + 168))(a1: v7) == 0 )
  {
    v8 = v10;
    if ( CUtlRBTree<IMaterial *,unsigned short,bool (__cdecl *)(IMaterial * const &,IMaterial * const &),CUtlMemory<UtlRBTreeNode_t<IMaterial *,unsigned short>,unsigned short>>::Find(
           this: &v10->m_CachedMaterials,
           search: (IMaterial *const *)&pMaterialName) == 0xFFFF )
    {
      (*(void (__thiscall **)(char *))(*(_DWORD *)pMaterialName + 48))(a1: pMaterialName);
      CUtlRBTree<IMaterial *,unsigned short,bool (__cdecl *)(IMaterial * const &,IMaterial * const &),CUtlMemory<UtlRBTreeNode_t<IMaterial *,unsigned short>,unsigned short>>::Insert(
        this: &v8->m_CachedMaterials,
        a2: v5,
        insert: (IMaterial *const *)&pMaterialName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E220
// Name: bool AddDataChangeEvent(class IClientNetworkable __near *,enum DataUpdateType_t,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddDataChangeEvent(IClientNetworkable *ent, DataUpdateType_t updateType, int *pStoredEvent)
{
  unsigned __int16 v4; // ax
  int v5; // esi
  UtlLinkedListElem_t<CDataChangedEvent,unsigned short> *v6; // eax

  if ( *pStoredEvent < 0 )
  {
    v4 = CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::AllocInternal(
           this: &g_DataChangedEvents,
           multilist: false);
    v5 = v4;
    if ( v4 == 0xFFFF )
    {
      *pStoredEvent = 0xFFFF;
      return 1;
    }
    else
    {
      CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *)&g_DataChangedEvents,
        before: 0xFFFFu,
        elem: v4);
      v6 = &g_DataChangedEvents.m_Memory.m_pMemory[v5];
      if ( v6 != nullptr )
      {
        *(_QWORD *)&v6->m_Element.m_pEntity = __PAIR64__(updateType, (unsigned int)ent);
        v6->m_Element.m_pStoredEvent = pStoredEvent;
      }
      *pStoredEvent = (unsigned __int16)v5;
      return 1;
    }
  }
  else
  {
    if ( updateType == DATA_UPDATE_CREATED )
      g_DataChangedEvents.m_Memory.m_pMemory[*(unsigned __int16 *)pStoredEvent].m_Element.m_UpdateType = DATA_UPDATE_CREATED;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E2C0
// Name: public: void CKeyBindingListenerMgr::OnKeyBindingChanged(enum ButtonCode_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyBindingListenerMgr::OnKeyBindingChanged(
        CKeyBindingListenerMgr *this,
        ButtonCode_t buttonCode,
        const char *pchKeyName,
        const char *pchNewBinding)
{
  CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int> > *v4; // edi
  int v5; // esi
  int v6; // esi
  int v7; // edi
  IKeyBindingListener **m_pMemory; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int> *v9; // eax
  bool v10; // cc
  CKeyBindingListenerMgr::BindingListeners_t *p_elem; // edi
  CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t search; // [esp+Ch] [ebp-1Ch] BYREF
  CKeyBindingListenerMgr *v13; // [esp+24h] [ebp-4h]

  v4 = &this->m_CodeListeners[buttonCode];
  v5 = 0;
  v13 = this;
  if ( this->m_CodeListeners[buttonCode].m_Size > 0 )
  {
    do
    {
      v4->m_Memory.m_pMemory[v5]->OnKeyBindingChanged(
        this: v4->m_Memory.m_pMemory[v5],
        a2: 0,
        a3: buttonCode,
        a4: pchKeyName,
        a5: pchNewBinding);
      ++v5;
    }
    while ( v5 < v4->m_Size );
    this = v13;
  }
  if ( pchNewBinding != nullptr )
  {
    search.key = pchNewBinding;
    memset(&search.elem, 0, sizeof(search.elem));
    v6 = 0;
    v7 = CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::Find(
           this: &this->m_BindingListeners.m_Elements.m_Tree,
           &search);
    m_pMemory = search.elem.m_List.m_Memory.m_pMemory;
    search.elem.m_List.m_Size = 0;
    if ( search.elem.m_List.m_Memory.m_nGrowSize >= 0 )
    {
      if ( search.elem.m_List.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_List.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        search.elem.m_List.m_Memory.m_pMemory = nullptr;
      }
      search.elem.m_List.m_Memory.m_nAllocationCount = 0;
    }
    search.elem.m_List.m_pElements = m_pMemory;
    if ( search.elem.m_List.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        search.elem.m_List.m_Memory.m_pMemory = nullptr;
      }
      search.elem.m_List.m_Memory.m_nAllocationCount = 0;
    }
    if ( v7 != -1 )
    {
      v9 = v13->m_BindingListeners.m_Elements.m_Tree.m_Elements.m_pMemory;
      v10 = v9[v7].m_Data.elem.m_List.m_Size <= 0;
      p_elem = &v9[v7].m_Data.elem;
      if ( !v10 )
      {
        do
        {
          p_elem->m_List.m_Memory.m_pMemory[v6]->OnKeyBindingChanged(
            this: p_elem->m_List.m_Memory.m_pMemory[v6],
            a2: 0,
            a3: buttonCode,
            a4: pchKeyName,
            a5: pchNewBinding);
          ++v6;
        }
        while ( v6 < p_elem->m_List.m_Size );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E3C0
// Name: public: virtual void CHLClient::OnKeyBindingChanged(enum ButtonCode_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::OnKeyBindingChanged(
        CHLClient *this,
        ButtonCode_t buttonCode,
        const char *pchKeyName,
        const char *pchNewBinding)
{
  CKeyBindingListenerMgr::OnKeyBindingChanged(this: &g_KeyBindingListenerMgr, buttonCode, pchKeyName, pchNewBinding);
}

//------------------------------------------------------------------------------
// Address: 0x1009E3D0
// Name: void PrecacheMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheMaterial(const char *pMaterialName)
{
  CHLClient::PrecacheMaterial(this: &gHLClient, pMaterialName);
}

//------------------------------------------------------------------------------
// Address: 0x1009E3F0
// Name: void OnMaterialStringTableChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnMaterialStringTableChanged(
        void *object,
        INetworkStringTable *stringTable,
        int stringNumber,
        char *newString)
{
  CHLClient::PrecacheMaterial(this: &gHLClient, pMaterialName: newString);
  g_bRequestCacheUsedMaterials = true;
}

//------------------------------------------------------------------------------
// Address: 0x1009E410
// Name: public: virtual void CHLClient::InstallStringTableCallback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLClient::InstallStringTableCallback(CHLClient *this, const char *tableName)
{
  if ( V_strcasecmp(s1: tableName, s2: "VguiScreen") != 0 )
  {
    if ( V_strcasecmp(s1: tableName, s2: "Materials") != 0 )
    {
      if ( V_strcasecmp(s1: tableName, s2: "EffectDispatch") != 0 )
      {
        if ( V_strcasecmp(s1: tableName, s2: "InfoPanel") != 0 )
        {
          if ( V_strcasecmp(s1: tableName, s2: "Scenes") != 0 )
          {
            if ( V_strcasecmp(s1: tableName, s2: "ParticleEffectNames") != 0 )
            {
              if ( V_strcasecmp(s1: tableName, s2: "ExtraParticleFilesTable") != 0 )
              {
                if ( V_strcasecmp(s1: tableName, s2: "Movies") != 0 )
                {
                  InstallStringTableCallback_GameRules(tableName);
                }
                else
                {
                  g_pStringTableMovies = networkstringtable->FindTable(this: networkstringtable, a2: tableName);
                  g_pStringTableMovies->SetStringChangedCallback(
                    this: g_pStringTableMovies,
                    a2: nullptr,
                    a3: OnMovieStringTableChanged);
                }
              }
              else
              {
                g_pStringTableExtraParticleFiles = networkstringtable->FindTable(
                                                     this: networkstringtable,
                                                     a2: tableName);
                networkstringtable->SetAllowClientSideAddString(
                  this: networkstringtable,
                  a2: g_pStringTableExtraParticleFiles,
                  a3: true);
                g_pStringTableExtraParticleFiles->SetStringChangedCallback(
                  this: g_pStringTableExtraParticleFiles,
                  a2: nullptr,
                  a3: OnPrecacheParticleFile);
              }
            }
            else
            {
              g_pStringTableParticleEffectNames = networkstringtable->FindTable(this: networkstringtable, a2: tableName);
              networkstringtable->SetAllowClientSideAddString(
                this: networkstringtable,
                a2: g_pStringTableParticleEffectNames,
                a3: true);
              g_pStringTableParticleEffectNames->SetStringChangedCallback(
                this: g_pStringTableParticleEffectNames,
                a2: nullptr,
                a3: OnParticleSystemStringTableChanged);
            }
          }
          else
          {
            g_pStringTableClientSideChoreoScenes = networkstringtable->FindTable(
                                                     this: networkstringtable,
                                                     a2: tableName);
            networkstringtable->SetAllowClientSideAddString(
              this: networkstringtable,
              a2: g_pStringTableClientSideChoreoScenes,
              a3: true);
            g_pStringTableClientSideChoreoScenes->SetStringChangedCallback(
              this: g_pStringTableClientSideChoreoScenes,
              a2: nullptr,
              a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))C_BaseAnimating::ShutdownBoneSetupThreadPool);
          }
        }
        else
        {
          g_pStringTableInfoPanel = networkstringtable->FindTable(this: networkstringtable, a2: tableName);
        }
      }
      else
      {
        g_StringTableEffectDispatch = networkstringtable->FindTable(this: networkstringtable, a2: tableName);
        g_StringTableEffectDispatch->SetStringChangedCallback(
          this: g_StringTableEffectDispatch,
          a2: nullptr,
          a3: OnEffectStringTableChanged);
      }
    }
    else
    {
      g_pStringTableMaterials = networkstringtable->FindTable(this: networkstringtable, a2: tableName);
      g_pStringTableMaterials->SetStringChangedCallback(
        this: g_pStringTableMaterials,
        a2: nullptr,
        a3: OnMaterialStringTableChanged);
    }
  }
  else
  {
    g_StringTableVguiScreen = networkstringtable->FindTable(this: networkstringtable, a2: tableName);
    g_StringTableVguiScreen->SetStringChangedCallback(
      this: g_StringTableVguiScreen,
      a2: nullptr,
      a3: OnVguiScreenTableChanged);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E680
// Name: public: void CUtlDict<struct CKeyBindingListenerMgr::BindingListeners_t,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CKeyBindingListenerMgr::BindingListeners_t,int>::RemoveAll(
        CUtlDict<CKeyBindingListenerMgr::BindingListeners_t,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1009E6D0
// Name: public: CKeyBindingListenerMgr::CKeyBindingListenerMgr(void)
// Source: json
//------------------------------------------------------------------------------
CKeyBindingListenerMgr *__thiscall CKeyBindingListenerMgr::CKeyBindingListenerMgr(CKeyBindingListenerMgr *this)
{
  CKeyBindingListenerMgr *result; // eax
  CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int> > *m_CodeListeners; // edx
  int i; // esi

  result = this;
  this->__vftable = (CKeyBindingListenerMgr_vtbl *)&CKeyBindingListenerMgr::`vftable';
  m_CodeListeners = this->m_CodeListeners;
  for ( i = 306; i >= 0; --i )
  {
    m_CodeListeners->m_Memory.m_pMemory = nullptr;
    m_CodeListeners->m_Memory.m_nAllocationCount = 0;
    m_CodeListeners->m_Memory.m_nGrowSize = 0;
    m_CodeListeners->m_Size = 0;
    m_CodeListeners->m_pElements = nullptr;
    ++m_CodeListeners;
  }
  this->m_BindingListeners.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_BindingListeners.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_BindingListeners.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_BindingListeners.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_BindingListeners.m_Elements.m_Tree.m_Root = -1;
  this->m_BindingListeners.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_BindingListeners.m_Elements.m_Tree.m_NumElements = 0;
  this->m_BindingListeners.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_BindingListeners.m_Elements.m_Tree.m_pElements = this->m_BindingListeners.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_BindingListeners.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_BindingListeners.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009F0F0
// Name: public: virtual void CKeyBindingListenerMgr::AddListenerForCode(class IKeyBindingListener __near *,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyBindingListenerMgr::AddListenerForCode(
        CKeyBindingListenerMgr *this,
        IKeyBindingListener *pListener,
        ButtonCode_t buttonCode)
{
  CUtlMemory<vgui::TreeNode *,int> *v3; // esi
  int m_Size; // edi
  int v5; // eax
  IKeyBindingListener **m_pMemory; // ecx
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v3 = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_CodeListeners[buttonCode];
  m_Size = this->m_CodeListeners[buttonCode].m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IKeyBindingListener **)v3->m_pMemory;
  while ( *m_pMemory != pListener )
  {
    ++v5;
    ++m_pMemory;
    if ( v5 >= m_Size )
      goto LABEL_7;
  }
  if ( v5 == -1 )
  {
LABEL_7:
    m_nAllocationCount = v3->m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: v3, num: m_Size - m_nAllocationCount + 1);
    ++v3[1].m_pMemory;
    v8 = v3->m_pMemory;
    v9 = (int)v3[1].m_pMemory - m_Size - 1;
    v3[1].m_nAllocationCount = (int)v3->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[m_Size + 1], src: &v8[m_Size], count: 4 * v9);
    v10 = &v3->m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)pListener;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F180
// Name: public: virtual void CKeyBindingListenerMgr::RemoveListener(class IKeyBindingListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyBindingListenerMgr::RemoveListener(CKeyBindingListenerMgr *this, IKeyBindingListener *pListener)
{
  CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int> > *m_CodeListeners; // esi
  int m_Size; // ecx
  int v4; // eax
  IKeyBindingListener **m_pMemory; // edx
  int v6; // ecx
  int j; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int> *v8; // edx
  int v9; // ecx
  int p_elem; // esi
  int v11; // eax
  IKeyBindingListener **v12; // edx
  int v13; // ecx
  int i; // [esp+Ch] [ebp-8h]

  m_CodeListeners = this->m_CodeListeners;
  for ( i = 307; i != 0; --i )
  {
    m_Size = m_CodeListeners->m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = m_CodeListeners->m_Memory.m_pMemory;
      while ( *m_pMemory != pListener )
      {
        ++v4;
        ++m_pMemory;
        if ( v4 >= m_Size )
          goto LABEL_11;
      }
      if ( v4 != -1 )
      {
        v6 = m_Size - v4 - 1;
        if ( v6 > 0 )
          _V_memmove(
            dest: &m_CodeListeners->m_Memory.m_pMemory[v4],
            src: &m_CodeListeners->m_Memory.m_pMemory[v4 + 1],
            count: 4 * v6);
        --m_CodeListeners->m_Size;
      }
    }
LABEL_11:
    ++m_CodeListeners;
  }
  for ( j = CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_BindingListeners.m_Elements.m_Tree);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_BindingListeners.m_Elements.m_Tree,
              i: j) )
  {
    v8 = this->m_BindingListeners.m_Elements.m_Tree.m_Elements.m_pMemory;
    v9 = v8[j].m_Data.elem.m_List.m_Size;
    p_elem = (int)&v8[j].m_Data.elem;
    v11 = 0;
    if ( v9 > 0 )
    {
      v12 = *(IKeyBindingListener ***)p_elem;
      while ( *v12 != pListener )
      {
        ++v11;
        ++v12;
        if ( v11 >= v9 )
          goto LABEL_22;
      }
      if ( v11 != -1 )
      {
        v13 = v9 - v11 - 1;
        if ( v13 > 0 )
          _V_memmove(
            dest: (void *)(*(_DWORD *)p_elem + 4 * v11),
            src: (const void *)(*(_DWORD *)p_elem + 4 * v11 + 4),
            count: 4 * v13);
        --*(_DWORD *)(p_elem + 12);
      }
    }
LABEL_22:
    ;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F280
// Name: public: CUtlMap<char const __near *,struct CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t::Node_t(struct CUtlMap<char const __near *,struct CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t *__thiscall CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t::Node_t(
        CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t *this,
        const CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t *from)
{
  int m_Size; // edi
  IKeyBindingListener **m_pMemory; // edx
  int i; // eax
  const CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t *froma; // [esp+14h] [ebp+8h]

  this->key = from->key;
  this->elem.m_List.m_Size = 0;
  this->elem.m_List.m_Memory.m_pMemory = nullptr;
  this->elem.m_List.m_Memory.m_nAllocationCount = 0;
  this->elem.m_List.m_Memory.m_nGrowSize = 0;
  this->elem.m_List.m_pElements = nullptr;
  m_Size = from->elem.m_List.m_Size;
  m_pMemory = from->elem.m_List.m_Memory.m_pMemory;
  this->elem.m_List.m_Size = 0;
  froma = (const CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t *)m_pMemory;
  CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&this->elem,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    this->elem.m_List.m_Memory.m_pMemory[i] = *((IKeyBindingListener **)&froma->key + i);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009F2E0
// Name: public: int CUtlMap<char const __near *,struct CKeyBindingListenerMgr::BindingListeners_t,int>::Insert(char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Insert@<eax>(
        CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key)
{
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int> *m_pMemory; // edx
  CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t node; // [esp+Ch] [ebp-1Ch] BYREF
  int parent; // [esp+24h] [ebp-4h] BYREF

  node.key = *key;
  memset(&node.elem, 0, sizeof(node.elem));
  parent = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    &parent,
    leftchild: (bool *)&key);
  v4 = CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::NewNode(
         this: &this->m_Tree,
         a2);
  CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v4,
    parent,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int> *)-16 )
    CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t::Node_t(
      this: &m_pMemory[v4].m_Data,
      from: &node);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&node.elem);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1009F370
// Name: public: CKeyBindingListenerMgr::~CKeyBindingListenerMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyBindingListenerMgr::~CKeyBindingListenerMgr(CKeyBindingListenerMgr *this)
{
  CUtlDict<CKeyBindingListenerMgr::BindingListeners_t,int> *p_m_BindingListeners; // esi
  int i; // ebx
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // eax

  CUtlDict<CKeyBindingListenerMgr::BindingListeners_t,int>::RemoveAll(this: &this->m_BindingListeners);
  CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>(this: &this->m_BindingListeners.m_Elements.m_Tree);
  p_m_BindingListeners = &this->m_BindingListeners;
  for ( i = 306; i >= 0; --i )
  {
    p_m_BindingListeners = (CUtlDict<CKeyBindingListenerMgr::BindingListeners_t,int> *)((char *)p_m_BindingListeners - 20);
    p_m_BindingListeners->m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( p_m_BindingListeners->m_Elements.m_Tree.m_Elements.m_nAllocationCount >= 0 )
    {
      if ( p_m_BindingListeners->m_Elements.m_Tree.m_LessFunc.m_LessFunc != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_BindingListeners->m_Elements.m_Tree.m_LessFunc.m_LessFunc);
        p_m_BindingListeners->m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
      }
      p_m_BindingListeners->m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    m_LessFunc = p_m_BindingListeners->m_Elements.m_Tree.m_LessFunc.m_LessFunc;
    p_m_BindingListeners->m_Elements.m_Tree.m_Root = (int)p_m_BindingListeners->m_Elements.m_Tree.m_LessFunc.m_LessFunc;
    if ( p_m_BindingListeners->m_Elements.m_Tree.m_Elements.m_nAllocationCount >= 0 )
    {
      if ( m_LessFunc != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_LessFunc);
        p_m_BindingListeners->m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
      }
      p_m_BindingListeners->m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F3F0
// Name: public: int CUtlDict<struct CKeyBindingListenerMgr::BindingListeners_t,int>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CKeyBindingListenerMgr::BindingListeners_t,int>::Insert(
        CUtlDict<CKeyBindingListenerMgr::BindingListeners_t,int> *this,
        char *pName)
{
  const char *v2; // edi
  char *v4; // eax

  v2 = pName;
  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v4, v2);
    pName = v4;
    return CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Insert(
             this: &this->m_Elements,
             key: (const char *const *)&pName);
  }
  else
  {
    pName = nullptr;
    return CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Insert(
             this: &this->m_Elements,
             key: (const char *const *)&pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F460
// Name: public: virtual void CKeyBindingListenerMgr::AddListenerForBinding(class IKeyBindingListener __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyBindingListenerMgr::AddListenerForBinding(
        CKeyBindingListenerMgr *this,
        IKeyBindingListener *pListener,
        char *pchBindingString)
{
  int v4; // edi
  int v5; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int> *m_pMemory; // edx
  int m_Size; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_elem; // esi
  int v9; // eax
  IKeyBindingListener **v10; // ecx
  int m_nAllocationCount; // eax
  vgui::TreeNode **v12; // ecx
  int v13; // eax
  vgui::TreeNode **v14; // edi
  CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t search; // [esp+Ch] [ebp-18h] BYREF

  if ( pchBindingString == nullptr
    || (memset(&search.elem, 0, sizeof(search.elem)),
        search.key = pchBindingString,
        v4 = CUtlRBTree<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int,CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CKeyBindingListenerMgr::BindingListeners_t,int>::Node_t,int>,int>>::Find(
               this: &this->m_BindingListeners.m_Elements.m_Tree,
               &search),
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem),
        v5 = v4,
        v4 == -1) )
  {
    v5 = CUtlDict<CKeyBindingListenerMgr::BindingListeners_t,int>::Insert(
           this: &this->m_BindingListeners,
           pName: pchBindingString);
  }
  m_pMemory = this->m_BindingListeners.m_Elements.m_Tree.m_Elements.m_pMemory;
  m_Size = m_pMemory[v5].m_Data.elem.m_List.m_Size;
  p_elem = (CUtlMemory<vgui::TreeNode *,int> *)&m_pMemory[v5].m_Data.elem;
  v9 = 0;
  if ( m_Size <= 0 )
    goto LABEL_10;
  v10 = (IKeyBindingListener **)p_elem->m_pMemory;
  while ( *v10 != pListener )
  {
    ++v9;
    ++v10;
    if ( v9 >= m_Size )
      goto LABEL_10;
  }
  if ( v9 == -1 )
  {
LABEL_10:
    m_nAllocationCount = p_elem->m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_elem, num: m_Size - m_nAllocationCount + 1);
    ++p_elem[1].m_pMemory;
    v12 = p_elem->m_pMemory;
    v13 = (int)p_elem[1].m_pMemory - m_Size - 1;
    p_elem[1].m_nAllocationCount = (int)p_elem->m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &v12[m_Size + 1], src: &v12[m_Size], count: 4 * v13);
    v14 = &p_elem->m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = (vgui::TreeNode *)pListener;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098AE0
// Name: __CreateCGameClientExportsIGameClientExports_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameClientExports *__cdecl _CreateCGameClientExportsIGameClientExports_interface()
{
  return &_g_CGameClientExports_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x10098AF0
// Name: __CreateCClientDLLSharedAppSystemsIClientDLLSharedAppSystems_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientDLLSharedAppSystems *__cdecl _CreateCClientDLLSharedAppSystemsIClientDLLSharedAppSystems_interface()
{
  return &_g_CClientDLLSharedAppSystems_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x10098B20
// Name: __CreateCHLClientIBaseClientDLL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHLClient *__cdecl _CreateCHLClientIBaseClientDLL_interface()
{
  return &gHLClient;
}

//------------------------------------------------------------------------------
// Address: 0x10099850
// Name: __CreateCClientMaterialSystemIClientMaterialSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientMaterialSystem *__cdecl _CreateCClientMaterialSystemIClientMaterialSystem_interface()
{
  return &s_ClientMaterialSystem;
}
