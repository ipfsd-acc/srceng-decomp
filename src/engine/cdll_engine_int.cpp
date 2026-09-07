// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cdll_engine_int.cpp
// Functions: 197
// ============================================================

#include "engine\cdll_engine_int.h"

//------------------------------------------------------------------------------
// Address: 0x1006E3A0
// Name: public: virtual char const __near * CEngineClient::GetProductVersionString(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const char *__thiscall CEngineClient::GetProductVersionString(CEngineClient *this)
{
  return Sys_GetVersionString();
}

//------------------------------------------------------------------------------
// Address: 0x1006E3B0
// Name: public: virtual class Vector CEngineClient::GetLightForPoint(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CEngineClient::GetLightForPoint(CEngineClient *this, Vector *result, const Vector *pos, BOOL bClamp)
{
  this->ComputeLighting(this, a2: pos, a3: nullptr, a4: bClamp, a5: result, a6: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006E3E0
// Name: public: virtual class Vector CEngineClient::GetLightForPointFast(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CEngineClient::GetLightForPointFast(
        CEngineClient *this,
        Vector *result,
        const Vector *pos,
        bool bClamp)
{
  int v4; // eax
  double x; // st7
  double y; // st6
  double z; // st5
  double v8; // st4
  double v9; // st7
  double v10; // rt1
  double v11; // st5
  double v12; // st7
  double v13; // st4
  double v14; // st6
  double v15; // rtt
  double v16; // st5
  double v17; // st6
  double v18; // st4
  double v19; // st7
  double v20; // rt1
  double v21; // st5
  double v22; // st7
  double v23; // st4
  double v24; // st6
  double v25; // rtt
  double v26; // st5
  double v27; // st6
  double v28; // st4
  double v29; // st7
  double v30; // rt1
  double v31; // st5
  double v32; // st7
  double v33; // st4
  double v34; // st6
  double v35; // rtt
  double v36; // st5
  double v37; // st6
  double v38; // st4
  double v39; // st7
  double v40; // rt1
  double v41; // st5
  double v42; // st7
  double v43; // st4
  double v44; // st6
  double v45; // rtt
  double v46; // st5
  double v47; // st6
  double v48; // st4
  double v49; // st7
  double v50; // rt1
  double v51; // st5
  double v52; // st7
  double v53; // st4
  double v54; // st6
  double v55; // rtt
  double v56; // st5
  double v57; // st6
  double v58; // st4
  double v59; // st7
  double v60; // rt1
  double v61; // st5
  double v62; // st7
  double v63; // st4
  double v64; // st6
  double v65; // rtt
  double v66; // st5
  double v67; // st6
  double v68; // st4
  double v69; // st7
  double v70; // rt1
  double v71; // st5
  double v72; // st7
  double v73; // st5
  double v74; // st6
  double v75; // st6
  double v76; // st7
  Vector *v77; // eax
  Vector cube[6]; // [esp+8h] [ebp-48h] BYREF

  v4 = CM_PointLeafnum(p: pos);
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  Mod_LeafAmbientColorAtPos(pOut: cube, pos, leafIndex: v4);
  x = cube[0].x;
  if ( result->x >= (double)cube[0].x )
    x = result->x;
  result->x = x;
  y = cube[0].y;
  if ( result->y >= (double)cube[0].y )
    y = result->y;
  result->y = y;
  z = cube[0].z;
  if ( result->z >= (double)cube[0].z )
    z = result->z;
  result->z = z;
  v8 = x;
  v9 = cube[1].x;
  if ( v8 >= cube[1].x )
    v9 = v8;
  v10 = z;
  v11 = v9;
  v12 = v10;
  result->x = v11;
  v13 = y;
  v14 = cube[1].y;
  if ( v13 >= cube[1].y )
    v14 = v13;
  v15 = v11;
  v16 = v14;
  v17 = v15;
  result->y = v16;
  v18 = v12;
  v19 = cube[1].z;
  if ( v18 >= cube[1].z )
    v19 = v18;
  v20 = v16;
  v21 = v19;
  v22 = v20;
  result->z = v21;
  v23 = v17;
  v24 = cube[2].x;
  if ( v23 >= cube[2].x )
    v24 = v23;
  v25 = v21;
  v26 = v24;
  v27 = v25;
  result->x = v26;
  v28 = v22;
  v29 = cube[2].y;
  if ( v28 >= cube[2].y )
    v29 = v28;
  v30 = v26;
  v31 = v29;
  v32 = v30;
  result->y = v31;
  v33 = v27;
  v34 = cube[2].z;
  if ( v33 >= cube[2].z )
    v34 = v33;
  v35 = v31;
  v36 = v34;
  v37 = v35;
  result->z = v36;
  v38 = v32;
  v39 = cube[3].x;
  if ( v38 >= cube[3].x )
    v39 = v38;
  v40 = v36;
  v41 = v39;
  v42 = v40;
  result->x = v41;
  v43 = v37;
  v44 = cube[3].y;
  if ( v43 >= cube[3].y )
    v44 = v43;
  v45 = v41;
  v46 = v44;
  v47 = v45;
  result->y = v46;
  v48 = v42;
  v49 = cube[3].z;
  if ( v48 >= cube[3].z )
    v49 = v48;
  v50 = v46;
  v51 = v49;
  v52 = v50;
  result->z = v51;
  v53 = v47;
  v54 = cube[4].x;
  if ( v53 >= cube[4].x )
    v54 = v53;
  v55 = v51;
  v56 = v54;
  v57 = v55;
  result->x = v56;
  v58 = v52;
  v59 = cube[4].y;
  if ( v58 >= cube[4].y )
    v59 = v58;
  v60 = v56;
  v61 = v59;
  v62 = v60;
  result->y = v61;
  v63 = v57;
  v64 = cube[4].z;
  if ( v63 >= cube[4].z )
    v64 = v63;
  v65 = v61;
  v66 = v64;
  v67 = v65;
  result->z = v66;
  v68 = v62;
  v69 = cube[5].x;
  if ( v68 >= cube[5].x )
    v69 = v68;
  v70 = v66;
  v71 = v69;
  v72 = v70;
  result->x = v71;
  v73 = v67;
  v74 = cube[5].y;
  if ( v73 >= cube[5].y )
    v74 = v73;
  result->y = v74;
  v75 = v72;
  v76 = cube[5].z;
  if ( v75 >= cube[5].z )
    v76 = v75;
  result->z = v76;
  if ( !bClamp )
    return result;
  if ( result->x > 1.0 )
    result->x = 1.0;
  if ( result->y > 1.0 )
    result->y = 1.0;
  v77 = result;
  if ( result->z > 1.0 )
    result->z = 1.0;
  return v77;
}

//------------------------------------------------------------------------------
// Address: 0x1006E5C0
// Name: public: virtual void CEngineClient::ServerCmd(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ServerCmd(CEngineClient *this, const char *szCmdString, bool bReliable)
{
  CCommand args; // [esp+0h] [ebp-608h] BYREF
  char buf[256]; // [esp+508h] [ebp-100h] BYREF

  V_snprintf(pDest: buf, maxLen: 255, pFormat: "cmd %s", szCmdString);
  CCommand::CCommand(this: &args);
  CCommand::Tokenize(this: &args, pCommand: buf, pBreakSet: nullptr);
  Cmd_ForwardToServer(&args, bReliable);
}

//------------------------------------------------------------------------------
// Address: 0x1006E620
// Name: public: virtual void CEngineClient::ClientCmd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ClientCmd(CEngineClient *this, const char *szCmdString)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax

  if ( GetBaseLocalClient()->m_bRestrictClientCommands )
  {
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddExecutionMarker(eTarget: TraceType, marker: eCmdExecutionMarker_Enable_FCVAR_CLIENTCMD_CAN_EXECUTE);
  }
  v4 = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: v4, pText: szCmdString, nTickDelay: 0);
  v6 = CTraceFilter::GetTraceType(this: v5);
  Cbuf_AddText(eTarget: v6, pText: "\n", nTickDelay: 0);
  if ( GetBaseLocalClient()->m_bRestrictClientCommands )
  {
    v8 = CTraceFilter::GetTraceType(this: v7);
    Cbuf_AddExecutionMarker(eTarget: v8, marker: eCmdExecutionMarker_Disable_FCVAR_CLIENTCMD_CAN_EXECUTE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E690
// Name: public: virtual void CEngineClient::SetRestrictServerCommands(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetRestrictServerCommands(CEngineClient *this, bool bRestrict)
{
  GetBaseLocalClient()->m_bRestrictServerCommands = bRestrict;
}

//------------------------------------------------------------------------------
// Address: 0x1006E6B0
// Name: public: virtual void CEngineClient::SetRestrictClientCommands(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetRestrictClientCommands(CEngineClient *this, bool bRestrict)
{
  GetBaseLocalClient()->m_bRestrictClientCommands = bRestrict;
}

//------------------------------------------------------------------------------
// Address: 0x1006E6D0
// Name: public: virtual void CEngineClient::ExecuteClientCmd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ExecuteClientCmd(CEngineClient *this, const char *szCmdString)
{
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t v4; // eax

  TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
  Cbuf_AddText(eTarget: TraceType, pText: szCmdString, nTickDelay: 0);
  v4 = CTraceFilter::GetTraceType(this: v3);
  Cbuf_AddText(eTarget: v4, pText: "\n", nTickDelay: 0);
  Cbuf_Execute();
}

//------------------------------------------------------------------------------
// Address: 0x1006E710
// Name: public: virtual bool CEngineClient::Con_IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineClient::Con_IsVisible(CEngineClient *this)
{
  return Con_IsVisible();
}

//------------------------------------------------------------------------------
// Address: 0x1006E720
// Name: public: virtual int CEngineClient::GetLocalPlayer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetLocalPlayer(CEngineClient *this)
{
  return GetLocalClient(nSlot: -1)->m_nPlayerSlot + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006E740
// Name: public: virtual float CEngineClient::GetLastTimeStamp(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineClient::GetLastTimeStamp(CEngineClient *this)
{
  return GetBaseLocalClient()->m_flLastServerTickTime;
}

//------------------------------------------------------------------------------
// Address: 0x1006E750
// Name: public: virtual int CEngineClient::GetLastAcknowledgedCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetLastAcknowledgedCommand(CEngineClient *this)
{
  return GetBaseLocalClient()->command_ack;
}

//------------------------------------------------------------------------------
// Address: 0x1006E760
// Name: public: virtual bool CEngineClient::MapHasHDRLighting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::MapHasHDRLighting(CEngineClient *this)
{
  return modelloader->LastLoadedMapHasHDRLighting(this: modelloader);
}

//------------------------------------------------------------------------------
// Address: 0x1006E770
// Name: public: virtual struct model_t const __near * CEngineClient::LoadModel(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
const model_t *__thiscall CEngineClient::LoadModel(CEngineClient *this, const char *pName, bool bProp)
{
  return modelloader->GetModelForName(
           this: modelloader,
           a2: pName,
           a3: (IModelLoader::REFERENCETYPE)(bProp ? FMODELLOADER_DETAILPROP : FMODELLOADER_CLIENTDLL));
}

//------------------------------------------------------------------------------
// Address: 0x1006E7A0
// Name: public: virtual class CSentence __near * CEngineClient::GetSentence(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CEngineClient::GetSentence(CEngineClient *this, CAudioSource *pAudioSource)
{
  if ( pAudioSource != nullptr )
    return pAudioSource->GetSentence(this: pAudioSource);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006E7C0
// Name: public: virtual float CEngineClient::GetSentenceLength(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineClient::GetSentenceLength(CEngineClient *this, CAudioSource *pAudioSource)
{
  float v3; // [esp+4h] [ebp-4h]

  if ( pAudioSource == nullptr || pAudioSource->SampleRate(this: pAudioSource) <= 0 )
    return 0.0;
  v3 = (float)pAudioSource->SampleCount(this: pAudioSource);
  return v3 / (double)pAudioSource->SampleRate(this: pAudioSource);
}

//------------------------------------------------------------------------------
// Address: 0x1006E810
// Name: public: virtual bool CEngineClient::IsStreaming(class CAudioSource __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsStreaming(CEngineClient *this, CAudioSource *pAudioSource)
{
  return pAudioSource != nullptr && pAudioSource->IsStreaming(this: pAudioSource);
}

//------------------------------------------------------------------------------
// Address: 0x1006E830
// Name: public: virtual void CEngineClient::GetViewAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetViewAngles(CEngineClient *this, QAngle *va)
{
  *va = GetLocalClient(nSlot: -1)->viewangles;
}

//------------------------------------------------------------------------------
// Address: 0x1006E860
// Name: public: virtual void CEngineClient::SetViewAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetViewAngles(CEngineClient *this, QAngle *va)
{
  float angle; // [esp+28h] [ebp+8h]
  float anglea; // [esp+28h] [ebp+8h]
  float angleb; // [esp+28h] [ebp+8h]
  float anglec; // [esp+28h] [ebp+8h]

  angle = va->x;
  if ( (LODWORD(angle) & 0x7F800000) == 0x7F800000
    || (LODWORD(va->y) & 0x7F800000) == 0x7F800000
    || (LODWORD(va->z) & 0x7F800000) == 0x7F800000 )
  {
    _Warning(a1: "CEngineClient::SetViewAngles:  rejecting invalid value [%f %f %f]\n", angle, va->y, va->z);
    GetLocalClient(nSlot: -1)->viewangles = vec3_angle;
  }
  else
  {
    anglea = AngleNormalize(angle);
    GetLocalClient(nSlot: -1)->viewangles.x = anglea;
    angleb = AngleNormalize(angle: va->y);
    GetLocalClient(nSlot: -1)->viewangles.y = angleb;
    anglec = AngleNormalize(angle: va->z);
    GetLocalClient(nSlot: -1)->viewangles.z = anglec;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E990
// Name: public: virtual void CEngineClient::SetMapLoadFailed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetMapLoadFailed(CEngineClient *this, bool bState)
{
  g_ServerGlobalVariables.bMapLoadFailed = bState;
}

//------------------------------------------------------------------------------
// Address: 0x1006E9A0
// Name: public: virtual bool CEngineClient::MapLoadFailed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::MapLoadFailed(CEngineClient *this)
{
  return g_ServerGlobalVariables.bMapLoadFailed;
}

//------------------------------------------------------------------------------
// Address: 0x1006E9B0
// Name: public: virtual void CEngineClient::ReadConfiguration(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ReadConfiguration(CEngineClient *this, int iController, bool readDefault)
{
  Host_ReadConfiguration(iController, readDefault);
}

//------------------------------------------------------------------------------
// Address: 0x1006E9D0
// Name: public: virtual char const __near * CEngineClient::Key_LookupBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineClient::Key_LookupBinding(CEngineClient *this, const char *pBinding)
{
  return Key_NameForBinding(pBinding, userId: -1, iStartCount: 0, iAllowJoystick: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1006E9F0
// Name: public: virtual char const __near * CEngineClient::Key_BindingForKey(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineClient::Key_BindingForKey(CEngineClient *this, ButtonCode_t code)
{
  return Key_BindingForKey(code);
}

//------------------------------------------------------------------------------
// Address: 0x1006EA10
// Name: public: virtual void CEngineClient::Key_SetBinding(enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::Key_SetBinding(CEngineClient *this, ButtonCode_t code, const char *pBinding)
{
  Key_SetBinding(keynum: code, pBinding);
}

//------------------------------------------------------------------------------
// Address: 0x1006EA30
// Name: public: virtual void CEngineClient::StartKeyTrapMode(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineClient::StartKeyTrapMode(CEngineClient *this)
{
  Key_StartTrapMode();
}

//------------------------------------------------------------------------------
// Address: 0x1006EA40
// Name: public: virtual bool CEngineClient::CheckDoneKeyTrapping(enum ButtonCode_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::CheckDoneKeyTrapping(CEngineClient *this, ButtonCode_t *code)
{
  return Key_CheckDoneTrapping(code);
}

//------------------------------------------------------------------------------
// Address: 0x1006EA60
// Name: public: virtual bool CEngineClient::GameHasShutdownAndFlushedMemory(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineClient::GameHasShutdownAndFlushedMemory(CEngineClient *this)
{
  return HostState_GameHasShutDownAndFlushedMemory();
}

//------------------------------------------------------------------------------
// Address: 0x1006EA70
// Name: public: virtual bool CEngineClient::IsDrawingLoadingImage(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsDrawingLoadingImage(CEngineClient *this)
{
  return scr_drawloading;
}

//------------------------------------------------------------------------------
// Address: 0x1006EA80
// Name: public: virtual void CEngineClient::HideLoadingPlaque(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::HideLoadingPlaque(CEngineClient *this)
{
  if ( !scr_drawloading )
    DevWarning(a1: "Attempted to HideLoadingPlaque when not loading...\n");
  if ( g_ClientDLL != nullptr && !g_ClientDLL->ShouldHideLoadingPlaque(this: g_ClientDLL) )
    DevWarning(a1: "Attempted to HideLoadingPlaque when client prevents hiding loading plaque...\n");
  SCR_EndLoadingPlaque();
}

//------------------------------------------------------------------------------
// Address: 0x1006EAD0
// Name: public: virtual void CEngineClient::Con_NPrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CEngineClient::Con_NPrintf(CEngineClient *this, int pos, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  Con_NPrintf(idx: pos, fmt: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x1006EB20
// Name: public: virtual void CEngineClient::Con_NXPrintf(struct con_nprint_s const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CEngineClient::Con_NXPrintf(CEngineClient *this, const con_nprint_s *info, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  Con_NXPrintf(info, fmt: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x1006EB70
// Name: public: virtual class IMaterial __near * CEngineClient::TraceLineMaterialAndLighting(class Vector const __near &,class Vector const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CEngineClient::TraceLineMaterialAndLighting(
        CEngineClient *this,
        const Vector *start,
        const Vector *end,
        Vector *diffuseLightColor,
        Vector *baseColor)
{
  return BrushModel_GetLightingAndMaterial(start, end, diffuseLightColor, baseColor);
}

//------------------------------------------------------------------------------
// Address: 0x1006EB90
// Name: public: virtual int CEngineClient::IsBoxVisible(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::IsBoxVisible(CEngineClient *this, const Vector *mins, const Vector *maxs)
{
  const unsigned __int8 *v3; // eax
  int v5; // [esp-4h] [ebp-4h]

  v5 = CM_ClusterPVSSize();
  v3 = Map_VisCurrent();
  return CM_BoxVisible(mins, maxs, visbits: v3, vissize: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1006EBC0
// Name: public: virtual int CEngineClient::IsBoxInViewCluster(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::IsBoxInViewCluster(CEngineClient *this, const Vector *mins, const Vector *maxs)
{
  int v3; // eax
  const unsigned __int8 *v5; // eax
  unsigned __int8 dest[8192]; // [esp+0h] [ebp-2000h] BYREF

  v3 = Map_VisCurrentCluster();
  if ( v3 < 0 )
    return 0;
  v5 = CM_Vis(dest, destlen: 0x2000, cluster: v3, visType: 0);
  return CM_BoxVisible(mins, maxs, visbits: v5, vissize: 0x2000);
}

//------------------------------------------------------------------------------
// Address: 0x1006EC10
// Name: public: virtual void CEngineClient::Sound_ExtraUpdate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineClient::Sound_ExtraUpdate(CEngineClient *this)
{
  S_ExtraUpdate();
}

//------------------------------------------------------------------------------
// Address: 0x1006EC20
// Name: public: virtual bool CEngineClient::CullBox(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::CullBox(CEngineClient *this, const Vector *mins, const Vector *maxs)
{
  return Frustum_t::CullBox(this: &g_Frustum, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x1006EC30
// Name: public: virtual char const __near * CEngineClient::GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const char *__thiscall CEngineClient::GetModDirectory(CEngineClient *this)
{
  return COM_GetModDirectory();
}

//------------------------------------------------------------------------------
// Address: 0x1006EC40
// Name: public: virtual class VMatrix const __near & CEngineClient::WorldToScreenMatrix(void)
// Source: json
//------------------------------------------------------------------------------
const VMatrix *__thiscall CEngineClient::WorldToScreenMatrix(CEngineClient *this)
{
  return g_EngineRenderer->WorldToScreenMatrix(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x1006EC50
// Name: public: virtual class VMatrix const __near & CEngineClient::WorldToViewMatrix(void)
// Source: json
//------------------------------------------------------------------------------
const VMatrix *__thiscall CEngineClient::WorldToViewMatrix(CEngineClient *this)
{
  return g_EngineRenderer->ViewMatrix(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x1006EC60
// Name: public: virtual int CEngineClient::GameLumpVersion(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GameLumpVersion(CEngineClient *this, int lumpId)
{
  return Mod_GameLumpVersion(lumpId);
}

//------------------------------------------------------------------------------
// Address: 0x1006EC80
// Name: public: virtual int CEngineClient::GameLumpSize(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GameLumpSize(CEngineClient *this, int lumpId)
{
  return Mod_GameLumpSize(lumpId);
}

//------------------------------------------------------------------------------
// Address: 0x1006ECA0
// Name: public: virtual bool CEngineClient::LoadGameLump(int,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::LoadGameLump(CEngineClient *this, int lumpId, void *pBuffer, int size)
{
  return Mod_LoadGameLump(lumpId, pOutBuffer: pBuffer, size);
}

//------------------------------------------------------------------------------
// Address: 0x1006ECC0
// Name: public: virtual int CEngineClient::LevelLeafCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::LevelLeafCount(CEngineClient *this)
{
  return host_state.worldbrush->numleafs;
}

//------------------------------------------------------------------------------
// Address: 0x1006ECD0
// Name: SetNodeFlagBits
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetNodeFlagBits(mnode_t *node)
{
  if ( node->contents < 0 )
  {
    SetNodeFlagBits(node: node->children[0]);
    SetNodeFlagBits(node: node->children[1]);
    node->flags = node->flags & 7 | node->children[1]->flags | node->children[0]->flags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ED20
// Name: public: virtual void CEngineClient::SetLeafFlag(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetLeafFlag(CEngineClient *this, int nLeafIndex, __int16 nFlagBits)
{
  host_state.worldbrush->leafs[nLeafIndex].flags |= nFlagBits;
}

//------------------------------------------------------------------------------
// Address: 0x1006ED50
// Name: public: virtual void CEngineClient::RecalculateBSPLeafFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::RecalculateBSPLeafFlags(CEngineClient *this)
{
  mnode_t *nodes; // esi

  nodes = host_state.worldbrush->nodes;
  if ( nodes->contents < 0 )
  {
    SetNodeFlagBits(node: nodes->children[0]);
    SetNodeFlagBits(node: nodes->children[1]);
    nodes->flags = nodes->children[1]->flags | nodes->children[0]->flags | nodes->flags & 7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ED90
// Name: public: virtual class ISpatialQuery __near * CEngineClient::GetBSPTreeQuery(void)
// Source: json
//------------------------------------------------------------------------------
IEngineSpatialQuery *__thiscall CEngineClient::GetBSPTreeQuery(CEngineClient *this)
{
  return g_pToolBSPTree;
}

//------------------------------------------------------------------------------
// Address: 0x1006EDA0
// Name: public: virtual void CEngineClient::LinearToGamma(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::LinearToGamma(CEngineClient *this, float *linear, float *gamma)
{
  *gamma = (float)LinearToTexture(f: *linear) * 0.0039215689;
  gamma[1] = (float)LinearToTexture(f: linear[1]) * 0.0039215689;
  gamma[2] = (float)LinearToTexture(f: linear[2]) * 0.0039215689;
}

//------------------------------------------------------------------------------
// Address: 0x1006EE10
// Name: public: virtual float CEngineClient::LightStyleValue(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineClient::LightStyleValue(CEngineClient *this, int style)
{
  return (double)d_lightstylevalue[style] * 0.0037878789;
}

//------------------------------------------------------------------------------
// Address: 0x1006EE30
// Name: public: virtual void CEngineClient::DrawPortals(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineClient::DrawPortals(CEngineClient *this)
{
  R_DrawPortals();
}

//------------------------------------------------------------------------------
// Address: 0x1006EE40
// Name: public: virtual void CEngineClient::ComputeDynamicLighting(class Vector const __near &,class Vector const __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ComputeDynamicLighting(
        CEngineClient *this,
        const Vector *pt,
        const Vector *pNormal,
        Vector *color)
{
  ComputeDynamicLighting(pt, pNormal, color);
}

//------------------------------------------------------------------------------
// Address: 0x1006EE60
// Name: public: virtual void CEngineClient::ComputeLighting(class Vector const __near &,class Vector const __near *,bool,class Vector __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ComputeLighting(
        CEngineClient *this,
        const Vector *pt,
        const Vector *pNormal,
        bool bClamp,
        Vector *color,
        Vector *pBoxColors)
{
  ComputeLighting(pt, pNormal, bClamp, bAddDynamicLightsToBox: false, color, pBoxColors);
}

//------------------------------------------------------------------------------
// Address: 0x1006EE90
// Name: public: virtual void CEngineClient::ComputeLightingCube(class Vector const __near &,bool,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ComputeLightingCube(
        CEngineClient *this,
        const Vector *pt,
        bool bClamp,
        Vector *pBoxColors)
{
  Vector dummy; // [esp+0h] [ebp-Ch] BYREF

  ComputeLighting(pt, pNormal: nullptr, bClamp, bAddDynamicLightsToBox: true, color: &dummy, pBoxColors);
}

//------------------------------------------------------------------------------
// Address: 0x1006EEC0
// Name: public: virtual void CEngineClient::GetAmbientLightColor(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetAmbientLightColor(CEngineClient *this, Vector *color)
{
  dworldlight_t *AmbientLight; // eax

  AmbientLight = FindAmbientLight();
  if ( AmbientLight != nullptr )
  {
    *color = AmbientLight->intensity;
  }
  else
  {
    color->x = 0.0;
    color->y = 0.0;
    color->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EF00
// Name: public: virtual int CEngineClient::GetDXSupportLevel(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetDXSupportLevel(CEngineClient *this)
{
  return g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
}

//------------------------------------------------------------------------------
// Address: 0x1006EF10
// Name: public: virtual void CEngineClient::Mat_Stub(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::Mat_Stub(CEngineClient *this, IMaterialSystem *pMatSys)
{
  materials = pMatSys;
  if ( g_pStudioRender != nullptr )
    g_pStudioRender->Mat_Stub(this: g_pStudioRender, a2: pMatSys);
}

//------------------------------------------------------------------------------
// Address: 0x1006EF40
// Name: public: virtual void CEngineClient::GetChapterName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetChapterName(CEngineClient *this, char *pchBuff, int iMaxLength)
{
  ((void (__thiscall *)(IServerGameDLL *, char *, int, _DWORD, _DWORD, int))serverGameDLL->GetSaveComment)(
    a1: serverGameDLL,
    a2: pchBuff,
    a3: iMaxLength,
    a4: 0.0,
    a5: 0.0,
    a6: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1006EF70
// Name: public: virtual void CEngineClient::GetMainMenuBackgroundName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetMainMenuBackgroundName(CEngineClient *this, char *dest, int destlen)
{
  CL_GetBackgroundLevelName(pszBackgroundName: dest, bufSize: destlen, bMapName: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006EF90
// Name: public: virtual void CEngineClient::GetStartupImage(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetStartupImage(CEngineClient *this, char *dest, int destlen)
{
  CL_GetStartupImage(pOutBuffer: dest, nOutBufferSize: destlen);
}

//------------------------------------------------------------------------------
// Address: 0x1006EFB0
// Name: public: virtual bool CEngineClient::IsUsingLocalNetworkBackdoor(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineClient::IsUsingLocalNetworkBackdoor(CEngineClient *this)
{
  return g_pLocalNetworkBackdoor != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006EFC0
// Name: public: virtual bool CEngineClient::SaveGame(char const __near *,bool,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::SaveGame(
        CEngineClient *this,
        const char *pSaveFilename,
        BOOL bIsXSave,
        char *pOutName,
        int nOutNameSize,
        char *pOutComment,
        int nOutCommentSize)
{
  return saverestore->SaveGame(
           this: saverestore,
           a2: pSaveFilename,
           a3: bIsXSave,
           a4: pOutName,
           a5: nOutNameSize,
           a6: pOutComment,
           a7: nOutCommentSize);
}

//------------------------------------------------------------------------------
// Address: 0x1006EFE0
// Name: public: virtual void CEngineClient::SetOcclusionParameters(struct OcclusionParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetOcclusionParameters(CEngineClient *this, const OcclusionParams_t *params)
{
  IOcclusionSystem *v2; // eax

  v2 = OcclusionSystem();
  v2->SetOcclusionParameters(this: v2, a2: params->m_flMaxOccludeeArea, a3: params->m_flMinOccluderArea);
}

//------------------------------------------------------------------------------
// Address: 0x1006F010
// Name: public: virtual int CEngineClient::GetPlayerForUserID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetPlayerForUserID(CEngineClient *this, int userID)
{
  int v4; // esi
  player_info_s ent_info; // [esp+4h] [ebp-90h] BYREF

  if ( GetBaseLocalClient()->m_pUserInfoTable == nullptr )
    return 0;
  if ( GetBaseLocalClient()->m_nMaxClients <= 0 )
    return 0;
  v4 = 1;
  while ( !this->GetPlayerInfo(this, a2: v4, a3: &ent_info) || ent_info.userID != userID )
  {
    if ( v4++ >= GetBaseLocalClient()->m_nMaxClients )
      return 0;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1006F0A0
// Name: public: virtual struct IVoiceTweak_s __near * CEngineClient::GetVoiceTweakAPI(void)
// Source: json
//------------------------------------------------------------------------------
IVoiceTweak_s *__thiscall CEngineClient::GetVoiceTweakAPI(CEngineClient *this)
{
  return &g_VoiceTweakAPI;
}

//------------------------------------------------------------------------------
// Address: 0x1006F0B0
// Name: public: virtual void CEngineClient::EngineStats_BeginFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::EngineStats_BeginFrame(CEngineClient *this)
{
  CEngineStats::BeginFrame(this: &g_EngineStats);
}

//------------------------------------------------------------------------------
// Address: 0x1006F0C0
// Name: public: virtual void CEngineClient::EngineStats_EndFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::EngineStats_EndFrame(CEngineClient *this)
{
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&g_EngineStats);
}

//------------------------------------------------------------------------------
// Address: 0x1006F0D0
// Name: public: virtual void CEngineClient::FireEvents(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineClient::FireEvents(CEngineClient *this)
{
  CL_FireEvents();
}

//------------------------------------------------------------------------------
// Address: 0x1006F0E0
// Name: public: virtual void CEngineClient::CheckPoint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::CheckPoint(CEngineClient *this, const char *pName)
{
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName);
}

//------------------------------------------------------------------------------
// Address: 0x1006F0F0
// Name: public: virtual int CEngineClient::GetLeavesArea(unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetLeavesArea(CEngineClient *this, unsigned __int16 *pLeaves, int nLeaves)
{
  int result; // eax
  mleaf_t *leafs; // edx
  int v5; // ecx

  if ( nLeaves == 0 )
    return -1;
  leafs = host_state.worldbrush->leafs;
  result = leafs[*pLeaves].area;
  v5 = 1;
  if ( nLeaves > 1 )
  {
    while ( leafs[pLeaves[v5]].area == result )
    {
      if ( ++v5 >= nLeaves )
        return result;
    }
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006F150
// Name: public: virtual bool CEngineClient::DoesBoxTouchAreaFrustum(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::DoesBoxTouchAreaFrustum(
        CEngineClient *this,
        const Vector *mins,
        const Vector *maxs,
        int iArea)
{
  Frustum_t *AreaFrustum; // eax

  AreaFrustum = (Frustum_t *)GetAreaFrustum(area: iArea);
  return !Frustum_t::CullBox(this: AreaFrustum, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x1006F180
// Name: public: virtual int CEngineClient::GetFrustumList(class Frustum_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetFrustumList(CEngineClient *this, Frustum_t **pList, int listMax)
{
  *pList = &g_Frustum;
  return GetAllAreaFrustums(pFrustumList: pList + 1, listMax: listMax - 1) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006F1D0
// Name: public: virtual int CEngineClient::SentenceGroupPick(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::SentenceGroupPick(CEngineClient *this, int groupIndex, char *name, int nameLen)
{
  return VOX_GroupPick(isentenceg: groupIndex, szfound: name, strLen: nameLen);
}

//------------------------------------------------------------------------------
// Address: 0x1006F1F0
// Name: public: virtual int CEngineClient::SentenceGroupPickSequential(int,char __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::SentenceGroupPickSequential(
        CEngineClient *this,
        int groupIndex,
        char *name,
        int nameLen,
        int sentenceIndex,
        int reset)
{
  return VOX_GroupPickSequential(
           isentenceg: groupIndex,
           szfound: name,
           szfoundLen: nameLen,
           ipick: sentenceIndex,
           freset: reset);
}

//------------------------------------------------------------------------------
// Address: 0x1006F220
// Name: public: virtual int CEngineClient::SentenceIndexFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::SentenceIndexFromName(CEngineClient *this, const char *pSentenceName)
{
  int sentenceIndex; // [esp+0h] [ebp-4h] BYREF

  sentenceIndex = -1;
  VOX_LookupString(
    pSentenceName,
    psentencenum: &sentenceIndex,
    pbEmitCaption: nullptr,
    pCaptionSymbol: nullptr,
    pflDuration: nullptr);
  return sentenceIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1006F250
// Name: public: virtual int CEngineClient::SentenceGroupIndexFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::SentenceGroupIndexFromName(CEngineClient *this, const char *pGroupName)
{
  return VOX_GroupIndexFromName(pGroupName);
}

//------------------------------------------------------------------------------
// Address: 0x1006F290
// Name: public: virtual void CEngineClient::ActivateOccluder(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ActivateOccluder(CEngineClient *this, int nOccluderIndex, BOOL bActive)
{
  IOcclusionSystem *v3; // eax

  v3 = OcclusionSystem();
  v3->ActivateOccluder(this: v3, a2: nOccluderIndex, a3: bActive);
}

//------------------------------------------------------------------------------
// Address: 0x1006F2B0
// Name: public: virtual bool CEngineClient::IsOccluded(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsOccluded(CEngineClient *this, const Vector *vecAbsMins, const Vector *vecAbsMaxs)
{
  IOcclusionSystem *v3; // eax

  v3 = OcclusionSystem();
  return v3->IsOccluded(this: v3, a2: vecAbsMins, a3: vecAbsMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x1006F2F0
// Name: public: virtual class INetChannelInfo __near * CEngineClient::GetNetChannelInfo(void)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CEngineClient::GetNetChannelInfo(CEngineClient *this)
{
  return GetBaseLocalClient()->m_NetChannel;
}

//------------------------------------------------------------------------------
// Address: 0x1006F310
// Name: public: virtual bool CEngineClient::IsRecordingDemo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsRecordingDemo(CEngineClient *this)
{
  return demorecorder->IsRecording(this: demorecorder);
}

//------------------------------------------------------------------------------
// Address: 0x1006F320
// Name: public: virtual bool CEngineClient::IsPlayingTimeDemo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsPlayingTimeDemo(CEngineClient *this)
{
  return demoplayer->IsPlayingTimeDemo(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1006F340
// Name: public: virtual bool CEngineClient::IsTakingScreenshot(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsTakingScreenshot(CEngineClient *this)
{
  return cl_takesnapshot;
}

//------------------------------------------------------------------------------
// Address: 0x1006F350
// Name: public: virtual void CEngineClient::WriteScreenshot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::WriteScreenshot(CEngineClient *this, const char *pFilename)
{
  cl_takesnapshot = true;
  cl_takejpeg = true;
  V_strncpy(pDest: cl_snapshot_fullpathname, pSrc: pFilename, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x1006F380
// Name: public: virtual int CEngineClient::GetDemoRecordingTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetDemoRecordingTick(CEngineClient *this)
{
  return demorecorder->GetRecordingTick(this: demorecorder);
}

//------------------------------------------------------------------------------
// Address: 0x1006F390
// Name: public: virtual int CEngineClient::GetDemoPlaybackTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetDemoPlaybackTick(CEngineClient *this)
{
  return demoplayer->GetPlaybackTick(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1006F3A0
// Name: public: virtual int CEngineClient::GetDemoPlaybackStartTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetDemoPlaybackStartTick(CEngineClient *this)
{
  return demoplayer->GetPlaybackStartTick(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1006F3B0
// Name: public: virtual float CEngineClient::GetDemoPlaybackTimeScale(void)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineClient::GetDemoPlaybackTimeScale(CEngineClient *this)
{
  return demoplayer->GetPlaybackTimeScale(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1006F3C0
// Name: public: virtual int CEngineClient::GetDemoPlaybackTotalTicks(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetDemoPlaybackTotalTicks(CEngineClient *this)
{
  return demoplayer->GetTotalTicks(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1006F3D0
// Name: public: virtual bool CEngineClient::IsHLTV(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsHLTV(CEngineClient *this)
{
  return GetBaseLocalClient()->ishltv;
}

//------------------------------------------------------------------------------
// Address: 0x1006F3E0
// Name: public: virtual void CEngineClient::GetUILanguage(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetUILanguage(CEngineClient *this, char *dest, int destlen)
{
  char *m_pszString; // eax

  if ( (cl_language.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = cl_language.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  V_strncpy(pDest: dest, pSrc: m_pszString, maxLen: destlen);
}

//------------------------------------------------------------------------------
// Address: 0x1006F430
// Name: public: virtual bool CEngineClient::IsInEditMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsInEditMode(CEngineClient *this)
{
  return g_bInEditMode;
}

//------------------------------------------------------------------------------
// Address: 0x1006F440
// Name: public: virtual bool CEngineClient::IsInCommentaryMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsInCommentaryMode(CEngineClient *this)
{
  return g_bInCommentaryMode;
}

//------------------------------------------------------------------------------
// Address: 0x1006F450
// Name: public: virtual float CEngineClient::GetScreenAspectRatio(int,int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineClient::GetScreenAspectRatio(CEngineClient *this, int viewportWidth, int viewportHeight)
{
  return GetScreenAspect(viewportWidth, viewportHeight);
}

//------------------------------------------------------------------------------
// Address: 0x1006F480
// Name: public: virtual void CEngineClient::SetOverlayBindProxy(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetOverlayBindProxy(CEngineClient *this, int iOverlayID, void *pBindProxy)
{
  IOverlayMgr *v3; // eax

  v3 = OverlayMgr();
  v3->SetOverlayBindProxy(this: v3, a2: iOverlayID, a3: pBindProxy);
}

//------------------------------------------------------------------------------
// Address: 0x1006F4A0
// Name: public: virtual void CEngineClient::GrabPreColorCorrectedFrame(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GrabPreColorCorrectedFrame(CEngineClient *this, int x, int y, int width, int height)
{
  colorcorrectiontools->GrabPreColorCorrectedFrame(this: colorcorrectiontools, a2: x, a3: y, a4: width, a5: height);
}

//------------------------------------------------------------------------------
// Address: 0x1006F4C0
// Name: public: virtual bool CEngineClient::IsHammerRunning(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsHammerRunning(CEngineClient *this)
{
  return g_pHammer != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006F4D0
// Name: public: virtual void CEngineClient::SetAchievementMgr(class IAchievementMgr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetAchievementMgr(CEngineClient *this, IAchievementMgr *pAchievementMgr)
{
  g_pAchievementMgr = pAchievementMgr;
}

//------------------------------------------------------------------------------
// Address: 0x1006F4E0
// Name: public: virtual char const __near * CEngineClient::GetMostRecentSaveGame(bool)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineClient::GetMostRecentSaveGame(CEngineClient *this, bool bEnsureExists)
{
  const char *result; // eax
  const char *v3; // esi

  result = saverestore->GetMostRecentlyLoadedFileName(this: saverestore);
  v3 = result;
  if ( result != nullptr && bEnsureExists )
  {
    if ( saverestore->SaveFileExists(this: saverestore, a2: result) )
      return v3;
    else
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006F520
// Name: public: virtual void CEngineClient::SetMostRecentSaveGame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetMostRecentSaveGame(CEngineClient *this, const char *lpszFilename)
{
  saverestore->SetMostRecentSaveGame(this: saverestore, a2: lpszFilename);
}

//------------------------------------------------------------------------------
// Address: 0x1006F540
// Name: public: virtual bool CEngineClient::IsSaveInProgress(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsSaveInProgress(CEngineClient *this)
{
  return saverestore->IsSaveInProgress(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x1006F550
// Name: public: virtual bool CEngineClient::IsAutoSaveDangerousInProgress(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsAutoSaveDangerousInProgress(CEngineClient *this)
{
  return saverestore->IsAutoSaveDangerousInProgress(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x1006F560
// Name: public: virtual char const __near * CEngineClient::GetSaveDirName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineClient::GetSaveDirName(CEngineClient *this)
{
  return saverestore->GetSaveDir(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x1006F570
// Name: public: virtual unsigned int CEngineClient::OnStorageDeviceAttached(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEngineClient::OnStorageDeviceAttached(CEngineClient *this, int iController)
{
  return g_pXboxSystem->OpenContainers(this: g_pXboxSystem, a2: iController);
}

//------------------------------------------------------------------------------
// Address: 0x1006F590
// Name: public: virtual void CEngineClient::FinishContainerWrites(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::FinishContainerWrites(CEngineClient *this, int iController)
{
  g_pXboxSystem->FinishContainerWrites(this: g_pXboxSystem, a2: iController);
}

//------------------------------------------------------------------------------
// Address: 0x1006F5B0
// Name: public: virtual void CEngineClient::FinishAsyncSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::FinishAsyncSave(CEngineClient *this)
{
  saverestore->FinishAsyncSave(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x1006F5C0
// Name: public: virtual void CEngineClient::ResetDemoInterpolation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ResetDemoInterpolation(CEngineClient *this)
{
  if ( demorecorder->IsRecording(this: demorecorder) )
    demorecorder->ResetDemoInterpolation(this: demorecorder);
  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    demoplayer->ResetDemoInterpolation(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1006F600
// Name: public: virtual int CEngineClient::SetActiveSplitScreenPlayerSlot(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::SetActiveSplitScreenPlayerSlot(CEngineClient *this, int slot)
{
  return splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: slot);
}

//------------------------------------------------------------------------------
// Address: 0x1006F620
// Name: public: virtual int CEngineClient::GetSplitScreenPlayer(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetSplitScreenPlayer(CEngineClient *this, int nSlot)
{
  return splitscreen->GetSplitScreenPlayerEntity(this: splitscreen, a2: nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1006F640
// Name: public: virtual bool CEngineClient::SetLocalPlayerIsResolvable(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::SetLocalPlayerIsResolvable(
        CEngineClient *this,
        const char *pchContext,
        int nLine,
        BOOL bResolvable)
{
  return splitscreen->SetLocalPlayerIsResolvable(this: splitscreen, a2: pchContext, a3: nLine, a4: bResolvable);
}

//------------------------------------------------------------------------------
// Address: 0x1006F660
// Name: public: virtual bool CEngineClient::IsLocalPlayerResolvable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsLocalPlayerResolvable(CEngineClient *this)
{
  return splitscreen->IsLocalPlayerResolvable(this: splitscreen);
}

//------------------------------------------------------------------------------
// Address: 0x1006F670
// Name: public: virtual bool CEngineClient::IsSplitScreenActive(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineClient::IsSplitScreenActive(CEngineClient *this)
{
  int v1; // esi

  v1 = 1;
  if ( splitscreen->GetNumSplitScreenPlayers(this: splitscreen) <= 1 )
    return 0;
  while ( !splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: v1) )
  {
    if ( ++v1 >= splitscreen->GetNumSplitScreenPlayers(this: splitscreen) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006F6C0
// Name: public: virtual bool CEngineClient::IsValidSplitScreenSlot(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsValidSplitScreenSlot(CEngineClient *this, int nSlot)
{
  return splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1006F6E0
// Name: public: virtual int CEngineClient::FirstValidSplitScreenSlot(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::FirstValidSplitScreenSlot(CEngineClient *this)
{
  return splitscreen->FirstValidSplitScreenSlot(this: splitscreen);
}

//------------------------------------------------------------------------------
// Address: 0x1006F6F0
// Name: public: virtual int CEngineClient::NextValidSplitScreenSlot(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::NextValidSplitScreenSlot(CEngineClient *this, int nPreviousSlot)
{
  return splitscreen->NextValidSplitScreenSlot(this: splitscreen, a2: nPreviousSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1006F730
// Name: public: virtual char const __near * CEngineClient::Key_LookupBindingEx(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineClient::Key_LookupBindingEx(
        CEngineClient *this,
        const char *pBinding,
        int iUserId,
        int iStartCount,
        int iAllowJoystick)
{
  return Key_NameForBinding(pBinding, userId: iUserId, iStartCount, iAllowJoystick);
}

//------------------------------------------------------------------------------
// Address: 0x1006F750
// Name: public: virtual int CEngineClient::Key_CodeForBinding(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::Key_CodeForBinding(
        CEngineClient *this,
        const char *pBinding,
        int iUserId,
        int iStartCount,
        int iAllowJoystick)
{
  return Key_CodeForBinding(pBinding, userId: iUserId, iStartCount, iAllowJoystick);
}

//------------------------------------------------------------------------------
// Address: 0x1006F770
// Name: public: virtual bool CEngineClient::DSPGetCurrentDASRoomNew(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineClient::DSPGetCurrentDASRoomNew(CEngineClient *this)
{
  return S_DSPGetCurrentDASRoomNew();
}

//------------------------------------------------------------------------------
// Address: 0x1006F780
// Name: public: virtual bool CEngineClient::DSPGetCurrentDASRoomChanged(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineClient::DSPGetCurrentDASRoomChanged(CEngineClient *this)
{
  return S_DSPGetCurrentDASRoomChanged();
}

//------------------------------------------------------------------------------
// Address: 0x1006F790
// Name: public: virtual bool CEngineClient::DSPGetCurrentDASRoomSkyAbove(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineClient::DSPGetCurrentDASRoomSkyAbove(CEngineClient *this)
{
  return S_DSPGetCurrentDASRoomSkyAbove();
}

//------------------------------------------------------------------------------
// Address: 0x1006F7A0
// Name: public: virtual float CEngineClient::DSPGetCurrentDASRoomSkyPercent(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
double __thiscall CEngineClient::DSPGetCurrentDASRoomSkyPercent(CEngineClient *this)
{
  return S_DSPGetCurrentDASRoomSkyPercent();
}

//------------------------------------------------------------------------------
// Address: 0x1006F7B0
// Name: public: virtual void CEngineClient::SetMixGroupOfCurrentMixer(char const __near *,char const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetMixGroupOfCurrentMixer(
        CEngineClient *this,
        const char *szgroupname,
        const char *szparam,
        float val,
        const char *setMixerType)
{
  S_SetMixGroupOfCurrentMixer(szgroupname, szparam, val, (int)setMixerType);
}

//------------------------------------------------------------------------------
// Address: 0x1006F7E0
// Name: public: virtual int CEngineClient::GetMixGroupIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetMixGroupIndex(CEngineClient *this, const char *szmixgroupname)
{
  return S_GetMixGroupIndex(pMixGroupName: szmixgroupname);
}

//------------------------------------------------------------------------------
// Address: 0x1006F800
// Name: public: virtual int CEngineClient::GetMixLayerIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetMixLayerIndex(CEngineClient *this, const char *szmixlayername)
{
  return MXR_GetMixLayerIndexFromName(szmixlayername);
}

//------------------------------------------------------------------------------
// Address: 0x1006F820
// Name: public: virtual void CEngineClient::SetMixLayerLevel(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetMixLayerLevel(CEngineClient *this, int index, float level)
{
  S_SetMixLayerLevel(index, level);
}

//------------------------------------------------------------------------------
// Address: 0x1006F840
// Name: public: virtual void CEngineClient::SetMixLayerTriggerFactor(char const __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetMixLayerTriggerFactor(
        CEngineClient *this,
        const char *pLayerName,
        const char *pMixGroupName,
        float flFactor)
{
  S_SetMixLayerTriggerFactor(pMixLayerName: pLayerName, pMixGroupName, flFactor);
}

//------------------------------------------------------------------------------
// Address: 0x1006F860
// Name: public: virtual void CEngineClient::SetMixLayerTriggerFactor(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetMixLayerTriggerFactor(
        CEngineClient *this,
        int nLayerIndex,
        int nMixGroupIndex,
        float flFactor)
{
  S_SetMixLayerTriggerFactor(nMixLayerIndex: nLayerIndex, nMixGroupIndex, flFactor);
}

//------------------------------------------------------------------------------
// Address: 0x1006F880
// Name: public: virtual bool CEngineClient::IsCreatingReslist(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsCreatingReslist(CEngineClient *this)
{
  return MapReslistGenerator()->m_bLoggingEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x1006F890
// Name: public: virtual void CEngineClient::UpdateDAndELights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::UpdateDAndELights(CEngineClient *this)
{
  CL_UpdateDAndELights(bUpdateDecay: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006F8A0
// Name: public: virtual int CEngineClient::GetBugSubmissionCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetBugSubmissionCount(CEngineClient *this)
{
  if ( bugreporter != nullptr )
    return bugreporter->GetBugSubmissionCount(this: bugreporter);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006F8C0
// Name: public: virtual void CEngineClient::ClearBugSubmissionCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ClearBugSubmissionCount(CEngineClient *this)
{
  if ( bugreporter != nullptr )
    bugreporter->ClearBugSubmissionCount(this: bugreporter);
}

//------------------------------------------------------------------------------
// Address: 0x1006F8E0
// Name: public: virtual bool CEngineClient::DoesLevelContainWater(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineClient::DoesLevelContainWater(CEngineClient *this)
{
  return host_state.worldbrush->numleafwaterdata != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006F8F0
// Name: public: virtual float CEngineClient::GetServerSimulationFrameTime(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
double __thiscall CEngineClient::GetServerSimulationFrameTime(CEngineClient *this)
{
  return Host_GetServerSimulationFrameTime();
}

//------------------------------------------------------------------------------
// Address: 0x1006F900
// Name: public: virtual void CEngineClient::SolidMoved(class IClientEntity __near *,class ICollideable __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SolidMoved(
        CEngineClient *this,
        IClientEntity *pSolidEnt,
        ICollideable *pSolidCollide,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  CL_SolidMoved(pTriggerEnt: pSolidEnt, pSolidCollide, pPrevAbsOrigin, accurateBboxTriggerChecks);
}

//------------------------------------------------------------------------------
// Address: 0x1006F920
// Name: public: virtual void CEngineClient::TriggerMoved(class IClientEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::TriggerMoved(
        CEngineClient *this,
        IClientEntity *pTriggerEnt,
        bool accurateBboxTriggerChecks)
{
  CL_TriggerMoved(pTriggerEnt, accurateBboxTriggerChecks);
}

//------------------------------------------------------------------------------
// Address: 0x1006F940
// Name: public: virtual void CEngineClient::ComputeLeavesConnected(class Vector const __near &,int,int const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ComputeLeavesConnected(
        CEngineClient *this,
        const Vector *vecOrigin,
        int nCount,
        const int *pLeaves,
        bool *pIsConnected)
{
  CM_LeavesConnected(vecOrigin, nCount, pLeaves, pIsConnected);
}

//------------------------------------------------------------------------------
// Address: 0x1006F960
// Name: public: virtual void CEngineClient::SetBlurFade(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetBlurFade(CEngineClient *this, float scale)
{
  ((void (__stdcall *)(_DWORD))g_ClientDLL->SetBlurFade)(a1: LODWORD(scale));
}

//------------------------------------------------------------------------------
// Address: 0x1006F980
// Name: public: virtual bool CEngineClient::IsTransitioningToLoad(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineClient::IsTransitioningToLoad(CEngineClient *this)
{
  return HostState_IsTransitioningToLoad();
}

//------------------------------------------------------------------------------
// Address: 0x1006F990
// Name: public: virtual void CEngineClient::SearchPathsChangedAfterInstall(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SearchPathsChangedAfterInstall(CEngineClient *this)
{
  g_ClientDLL->ResetHudCloseCaption(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x1006F9A0
// Name: public: virtual void CEngineClient::ConfigureSystemLevel(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ConfigureSystemLevel(CEngineClient *this, int nCPULevel, int nGPULevel)
{
  IStaticPropMgrEngine *v3; // eax
  IOverlayMgr *v4; // eax

  v3 = StaticPropMgr();
  v3->ConfigureSystemLevel(this: v3, a2: nCPULevel, a3: nGPULevel);
  v4 = OverlayMgr();
  v4->UpdateOverlayRenderLevels(this: v4, a2: nCPULevel, a3: nGPULevel);
}

//------------------------------------------------------------------------------
// Address: 0x1006F9E0
// Name: public: virtual void CEngineClient::SetConnectionPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetConnectionPassword(CEngineClient *this, const char *pchCurrentPW)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  CBaseClientState::SetConnectionPassword(this: BaseLocalClient, pchCurrentPW);
}

//------------------------------------------------------------------------------
// Address: 0x1006FA00
// Name: public: virtual class CSteamAPIContext __near * CEngineClient::GetSteamAPIContext(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
CSteam3Client *__thiscall CEngineClient::GetSteamAPIContext(CEngineClient *this)
{
  return Steam3Client();
}

//------------------------------------------------------------------------------
// Address: 0x1006FA10
// Name: public: virtual void CEngineClient::SubmitStatRecord(char const __near *,unsigned int,unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SubmitStatRecord(
        CEngineClient *this,
        const char *szMapName,
        unsigned int uiBlobVersion,
        unsigned int uiBlobSize,
        const void *pvBlob)
{
  AsyncUpload_QueueData(szMapName, uiBlobVersion, uiBlobSize, pvBlob);
}

//------------------------------------------------------------------------------
// Address: 0x1006FA30
// Name: public: virtual void CEngineClient::ServerCmdKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ServerCmdKeyValues(CEngineClient *this, KeyValues *pKeyValues)
{
  CClientState *LocalClient; // eax

  LocalClient = GetLocalClient(nSlot: -1);
  CClientState::SendServerCmdKeyValues(this: LocalClient, pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x1006FA50
// Name: public: virtual void CEngineClient::SetPitchScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetPitchScale(CEngineClient *this, float flPitchScale)
{
  S_SoundSetPitchScale(flPitchScale);
}

//------------------------------------------------------------------------------
// Address: 0x1006FA70
// Name: public: virtual float CEngineClient::GetPitchScale(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
double __thiscall CEngineClient::GetPitchScale(CEngineClient *this)
{
  return S_SoundGetPitchScale();
}

//------------------------------------------------------------------------------
// Address: 0x1006FA80
// Name: public: virtual bool CEngineClient::LoadFilmmaker(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::LoadFilmmaker(CEngineClient *this)
{
  return toolframework->LoadFilmmaker(this: toolframework);
}

//------------------------------------------------------------------------------
// Address: 0x1006FA90
// Name: public: virtual void CEngineClient::UnloadFilmmaker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::UnloadFilmmaker(CEngineClient *this)
{
  toolframework->UnloadFilmmaker(this: toolframework);
}

//------------------------------------------------------------------------------
// Address: 0x1006FAF0
// Name: public: virtual void CEngineClient::EnablePaintmapRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::EnablePaintmapRender(CEngineClient *this)
{
  ConVar *v1; // eax

  v1 = g_pCVar->FindVar_2(this: g_pCVar, a2: "mat_paint_enabled");
  if ( v1 != nullptr )
    v1->SetValue_4(this: &v1->IConVar, a2: "1");
}

//------------------------------------------------------------------------------
// Address: 0x1006FB20
// Name: public: virtual void CEngineClient::RemoveAllPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::RemoveAllPaint(CEngineClient *this)
{
  CPaintmapDataManager::RemoveAllPaint(this: &g_PaintManager);
}

//------------------------------------------------------------------------------
// Address: 0x1006FB30
// Name: public: virtual void CEngineClient::RemovePaint(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::RemovePaint(CEngineClient *this, const model_t *pModel)
{
  CPaintmapDataManager::RemovePaint(this: &g_PaintManager, pModel);
}

//------------------------------------------------------------------------------
// Address: 0x1006FB50
// Name: public: virtual void CEngineClient::TickProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::TickProgressBar(CEngineClient *this)
{
  IEngineVGuiInternal *v1; // eax

  v1 = EngineVGui();
  v1->UpdateProgressBar(this: v1, a2: PROGRESS_DEFAULT, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1006FB70
// Name: public: virtual struct InputContextHandle_t__ __near * CEngineClient::GetInputContext(enum EngineInputContextId_t)
// Source: json
//------------------------------------------------------------------------------
InputContextHandle_t__ *__thiscall CEngineClient::GetInputContext(CEngineClient *this, EngineInputContextId_t id)
{
  IEngineVGuiInternal *v3; // eax

  if ( id == ENGINE_INPUT_CONTEXT_GAME )
    return GetGameInputContext();
  if ( id != ENGINE_INPUT_CONTEXT_GAMEUI )
    return nullptr;
  v3 = EngineVGui();
  return v3->GetGameUIInputContext(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1006FBB0
// Name: public: virtual int CEngineClient::GetGenericMemoryStats(struct GenericMemoryStat_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetGenericMemoryStats(CEngineClient *this, GenericMemoryStat_t **ppMemoryStats)
{
  int v3; // eax
  int v4; // ecx

  if ( ppMemoryStats == nullptr )
    return 0;
  g_nEngineMemStats = 0;
  v3 = Hunk_LowMark();
  v4 = g_nEngineMemStats;
  if ( g_nEngineMemStats < 64 )
  {
    g_EngineMemStats[g_nEngineMemStats].name = "Hunk";
    dword_104DE7CC[2 * v4] = v3;
    g_nEngineMemStats = v4 + 1;
  }
  *ppMemoryStats = g_EngineMemStats;
  return g_nEngineMemStats;
}

//------------------------------------------------------------------------------
// Address: 0x1006FC10
// Name: public: virtual void CEngineClient::AudioLanguageChanged(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineClient::AudioLanguageChanged(CEngineClient *this)
{
  S_PurgeSoundsDueToLanguageChange();
}

//------------------------------------------------------------------------------
// Address: 0x1006FC20
// Name: public: virtual void CEngineClient::StartLoadingScreenForCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::StartLoadingScreenForCommand(CEngineClient *this, const char *command)
{
  IEngineVGuiInternal *v2; // eax

  v2 = EngineVGui();
  v2->StartLoadingScreenForCommand(this: v2, a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x1006FC40
// Name: public: virtual void CEngineClient::StartLoadingScreenForKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::StartLoadingScreenForKeyValues(CEngineClient *this, KeyValues *keyValues)
{
  IEngineVGuiInternal *v2; // eax

  v2 = EngineVGui();
  v2->StartLoadingScreenForKeyValues(this: v2, a2: keyValues);
}

//------------------------------------------------------------------------------
// Address: 0x1006FC60
// Name: class ClientClass __near * ClientDLL_GetAllClasses(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__cdecl ClientDLL_GetAllClasses()
{
  if ( g_ClientDLL != nullptr )
    return g_ClientDLL->GetAllClasses(this: g_ClientDLL);
  else
    return g_pClientClassHead;
}

//------------------------------------------------------------------------------
// Address: 0x1006FC80
// Name: ClientDLL_InitRecvTableMgr
// Source: json
//------------------------------------------------------------------------------
bool ClientDLL_InitRecvTableMgr()
{
  unsigned int v0; // edi
  ClientClass *v1; // esi
  RecvTable *pTables[1024]; // [esp+8h] [ebp-1000h] BYREF

  v0 = 0;
  if ( g_ClientDLL != nullptr )
    v1 = g_ClientDLL->GetAllClasses(this: g_ClientDLL);
  else
    v1 = g_pClientClassHead;
  for ( ; v1 != nullptr; ++v0 )
  {
    if ( v0 >= 0x400 )
      _Error(a1: "ClientDLL_InitRecvTableMgr: overflowed MAX_DATATABLES");
    pTables[v0] = v1->m_pRecvTable;
    v1 = v1->m_pNext;
  }
  return RecvTable_Init(pTables, nTables: v0);
}

//------------------------------------------------------------------------------
// Address: 0x1006FD00
// Name: void __near * (*ClientDLL_GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl ClientDLL_GetFactory())(const char *, int *)
{
  return g_ClientFactory;
}

//------------------------------------------------------------------------------
// Address: 0x1006FD10
// Name: bool ClientDLL_Load(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ClientDLL_Load()
{
  struct CSysModule *v0; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax

  v0 = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: "client.dll", a3: "GAMEBIN", a4: 0);
  g_ClientDLLModule = v0;
  if ( v0 != nullptr )
  {
    Factory = Sys_GetFactory(pModule: v0);
    g_ClientFactory = Factory;
    if ( Factory != nullptr )
    {
      g_ClientDLL = (IBaseClientDLL *)Factory(a1: "VClient016", a2: nullptr);
      g_bClientGameDLLGreaterThanV13 = true;
      if ( g_ClientDLL == nullptr )
        Sys_Error(error: "Could not get client.dll interface from library client");
    }
    else
    {
      Sys_Error(error: "Could not find factory interface in library client");
    }
  }
  else
  {
    Sys_Error(error: "Could not load library client");
  }
  g_pClientRenderTargets = (IClientRenderTargets *)g_ClientFactory(a1: "ClientRenderTargets001", a2: nullptr);
  return g_pClientRenderTargets != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006FDA0
// Name: void InitExtraClientCmdCanExecuteVars(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitExtraClientCmdCanExecuteVars()
{
  Cmd_AddClientCmdCanExecuteVar(pName: "cancelselect");
  Cmd_AddClientCmdCanExecuteVar(pName: "menuselect");
  Cmd_AddClientCmdCanExecuteVar(pName: "playgamesound");
  Cmd_AddClientCmdCanExecuteVar(pName: "_cl_classmenuopen");
  Cmd_AddClientCmdCanExecuteVar(pName: "cl_buy_favorite");
  Cmd_AddClientCmdCanExecuteVar(pName: "voice_modenable");
  Cmd_AddClientCmdCanExecuteVar(pName: "togglescores");
  Cmd_AddClientCmdCanExecuteVar(pName: "spec_next");
  Cmd_AddClientCmdCanExecuteVar(pName: "spec_prev");
  Cmd_AddClientCmdCanExecuteVar(pName: "spec_mode");
  Cmd_AddClientCmdCanExecuteVar(pName: "spec_menu");
  Cmd_AddClientCmdCanExecuteVar(pName: "spec_autodirector");
  Cmd_AddClientCmdCanExecuteVar(pName: "overview_zoom");
  Cmd_AddClientCmdCanExecuteVar(pName: "overview_mode");
  Cmd_AddClientCmdCanExecuteVar(pName: "overview_health");
  Cmd_AddClientCmdCanExecuteVar(pName: "overview_names");
  Cmd_AddClientCmdCanExecuteVar(pName: "overview_tracks");
  Cmd_AddClientCmdCanExecuteVar(pName: "overview_locked");
  Cmd_AddClientCmdCanExecuteVar(pName: "overview_alpha");
  Cmd_AddClientCmdCanExecuteVar(pName: "cc_lookup_crc");
  Cmd_AddClientCmdCanExecuteVar(pName: "playgamesound");
}

//------------------------------------------------------------------------------
// Address: 0x1006FE80
// Name: void ClientDLL_Connect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Connect()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->Connect(this: g_ClientDLL, a2: g_AppSystemFactory, a3: &g_ClientGlobalVariables);
}

//------------------------------------------------------------------------------
// Address: 0x1006FEA0
// Name: void ClientDLL_Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Disconnect()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->Disconnect(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x1006FED0
// Name: void ClientDLL_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Init()
{
  IPrediction *v0; // eax
  const char *ModDirectory; // eax
  vgui::ILocalize_vtbl *v2; // esi
  int v3; // eax
  vgui::ILocalize_vtbl *v4; // esi
  int v5; // eax
  int v6; // [esp-8h] [ebp-60Ch]
  int v7; // [esp-8h] [ebp-60Ch]
  wchar_t wcMessage[512]; // [esp+4h] [ebp-600h] BYREF
  char pMessage[512]; // [esp+404h] [ebp-200h] BYREF

  CL_SetSteamCrashComment();
  if ( g_ClientDLL != nullptr )
  {
    _COM_TimestampedLog(a1: "g_ClientDLL->Init");
    if ( g_ClientDLL->Init(this: g_ClientDLL, a2: g_GameSystemFactory, a3: &g_ClientGlobalVariables) == 0 )
      Sys_Error(error: "Client.dll Init() in library client failed.");
    if ( g_ClientFactory != nullptr )
    {
      _COM_TimestampedLog(a1: "g_pClientSidePrediction->Init");
      v0 = (IPrediction *)g_ClientFactory(a1: "VClientPrediction001", a2: nullptr);
      g_pClientSidePrediction = v0;
      if ( v0 == nullptr )
      {
        Sys_Error(error: "Could not get IPrediction interface from library client");
        v0 = g_pClientSidePrediction;
      }
      v0->Init(this: v0);
      entitylist = (IClientEntityList *)g_ClientFactory(a1: "VClientEntityList003", a2: nullptr);
      if ( entitylist == nullptr )
        Sys_Error(error: "Could not get client entity list interface from library client");
      clientleafsystem = (IClientLeafSystemEngine *)g_ClientFactory(a1: "ClientLeafSystem002", a2: nullptr);
      if ( clientleafsystem == nullptr )
        Sys_Error(error: "Could not get client leaf system interface from library client");
      g_pClientAlphaPropertyMgr = (IClientAlphaPropertyMgr *)g_ClientFactory(
                                                               a1: "ClientAlphaPropertyMgrV001",
                                                               a2: nullptr);
      if ( g_pClientAlphaPropertyMgr == nullptr )
        Sys_Error(error: "Could not get client alpha property mgr interface from library client");
      toolframework->ClientInit(this: toolframework, a2: g_ClientFactory);
    }
    if ( g_pMaterialSystemHardwareConfig != nullptr )
    {
      if ( g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 90 )
      {
        if ( g_pMaterialSystemHardwareConfig->IsUnsupported(this: g_pMaterialSystemHardwareConfig) )
        {
          v4 = g_pVGuiLocalize->__vftable;
          v5 = ((int (__thiscall *)(vgui::ILocalize *, const char *, _DWORD))g_pVGuiLocalize->Find)(
                 a1: g_pVGuiLocalize,
                 a2: "#Valve_UnsupportedCard",
                 a3: 0);
          ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v4->ConstructString_3)(
            a1: g_pVGuiLocalize,
            a2: wcMessage,
            a3: 1024,
            a4: v5);
          ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
            a1: g_pVGuiLocalize,
            a2: wcMessage,
            a3: pMessage,
            a4: 512,
            a5: v7);
          Sys_MessageBox(title: pMessage, info: nullptr, bShowOkAndCancel: false);
        }
      }
      else
      {
        ModDirectory = COM_GetModDirectory();
        if ( _V_stricmp(s1: ModDirectory, s2: "left4dead") == 0 )
        {
          v2 = g_pVGuiLocalize->__vftable;
          v3 = ((int (__thiscall *)(vgui::ILocalize *, const char *, _DWORD))g_pVGuiLocalize->Find)(
                 a1: g_pVGuiLocalize,
                 a2: "#Valve_MinShaderModel2",
                 a3: 0);
          ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v2->ConstructString_3)(
            a1: g_pVGuiLocalize,
            a2: wcMessage,
            a3: 1024,
            a4: v3);
          ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
            a1: g_pVGuiLocalize,
            a2: wcMessage,
            a3: pMessage,
            a4: 512,
            a5: v6);
          Sys_Error(error: pMessage);
        }
      }
    }
  }
  _COM_TimestampedLog(a1: "ClientDLL_InitRecvTableMgr");
  ClientDLL_InitRecvTableMgr();
  InitExtraClientCmdCanExecuteVars();
}

//------------------------------------------------------------------------------
// Address: 0x10070120
// Name: void ClientDLL_Unload(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Unload()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->Disconnect(this: g_ClientDLL);
  FileSystem_UnloadModule(pModule: g_ClientDLLModule);
  g_ClientDLL = nullptr;
  g_ClientDLLModule = nullptr;
  g_pClientRenderTargets = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10070160
// Name: void ClientDLL_HudVidInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_HudVidInit()
{
  g_ClientDLL->HudVidInit(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10070170
// Name: void ClientDLL_FrameStageNotify(enum ClientFrameStage_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_FrameStageNotify(ClientFrameStage_t frameStage)
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->FrameStageNotify(this: g_ClientDLL, a2: frameStage);
}

//------------------------------------------------------------------------------
// Address: 0x10070190
// Name: void ClientDLL_Update(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Update()
{
  if ( !sv.m_bIsDedicated && g_ClientDLL != nullptr )
    g_ClientDLL->HudUpdate(this: g_ClientDLL, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100701B0
// Name: void ClientDLL_VoiceStatus(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_VoiceStatus(int entindex, int iSsSlot, bool bTalking)
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->VoiceStatus(this: g_ClientDLL, a2: entindex, a3: iSsSlot, a4: bTalking);
}

//------------------------------------------------------------------------------
// Address: 0x100701E0
// Name: bool ClientDLL_IsPlayerAudible(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ClientDLL_IsPlayerAudible(int iPlayerIndex)
{
  return g_ClientDLL != nullptr && g_ClientDLL->PlayerAudible(this: g_ClientDLL, a2: iPlayerIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10070210
// Name: void ClientDLL_OnSplitScreenStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_OnSplitScreenStateChanged()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->OnSplitScreenStateChanged(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10070230
// Name: int ClientDLL_GetSpectatorTarget(enum ClientDLLObserverMode_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientDLL_GetSpectatorTarget(ClientDLLObserverMode_t *pObserverMode)
{
  if ( pObserverMode != nullptr )
    *pObserverMode = CLIENT_DLL_OBSERVER_NONE;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10070250
// Name: unsigned int ClientDLL_GetFullscreenClientDLLVPanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ClientDLL_GetFullscreenClientDLLVPanel()
{
  if ( g_ClientDLL != nullptr )
    return g_ClientDLL->GetFullscreenClientDLLVPanel(this: g_ClientDLL);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10070270
// Name: void AddIntersectingLeafSurfaces(struct mleaf_t __near *,class GetIntersectingSurfaces_Struct __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddIntersectingLeafSurfaces(mleaf_t *pLeaf, GetIntersectingSurfaces_Struct *pStruct)
{
  int v2; // eax
  msurface2_t *v3; // edx
  bool v4; // zf
  int m_nSetInfos; // eax
  int v6; // edi
  void **p_m_pEngineData; // ecx
  float y; // xmm3_4
  SurfInfo *v9; // eax
  __int128 v10; // xmm1
  int v11; // edi
  __int128 v12; // xmm6
  __int128 v13; // xmm5
  __int128 v14; // xmm7
  float v15; // xmm4_4
  float *v16; // ecx
  float *p_x; // edx
  unsigned int m_nVerts; // ecx
  __int128 z_low; // xmm2
  Vector *v20; // edx
  __int128 x_low; // xmm0
  __int128 v22; // xmm0
  __int128 v23; // xmm2
  unsigned int v24; // ecx
  float m_Radius; // xmm1_4
  const Vector *m_pCenter; // edi
  int v27; // ecx
  float *v28; // edx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  int nummarksurfaces; // ecx
  Vector vMax; // [esp+0h] [ebp-2Ch] BYREF
  Vector vMin; // [esp+Ch] [ebp-20h] BYREF
  char *v35; // [esp+18h] [ebp-14h]
  char *v36; // [esp+1Ch] [ebp-10h]
  msurface2_t **pHandle; // [esp+20h] [ebp-Ch]
  int iSurf; // [esp+24h] [ebp-8h]
  int iDim; // [esp+28h] [ebp-4h]

  pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
  v2 = 0;
  iSurf = 0;
  if ( pLeaf->nummarksurfaces != 0 )
  {
    do
    {
      v3 = pHandle[v2];
      v4 = (v3->flags & 4) == 0;
      iDim = (int)v3;
      if ( v4 )
      {
        m_nSetInfos = pStruct->m_nSetInfos;
        v6 = 0;
        if ( m_nSetInfos <= 0 )
        {
LABEL_7:
          if ( m_nSetInfos >= pStruct->m_nMaxInfos )
            return;
          y = 1000000.0;
          v9 = &pStruct->m_pInfos[m_nSetInfos];
          v10 = 0xC9742400;
          v11 = 0;
          v9->m_nVerts = 0;
          v9->m_pEngineData = v3;
          v4 = HIBYTE(v3->flags) == 0;
          v12 = 0x49742400u;
          v13 = 0x49742400u;
          v14 = 0xC9742400;
          v15 = -1000000.0;
          vMin.x = 1000000.0;
          vMin.y = 1000000.0;
          vMin.z = 1000000.0;
          vMax.x = -1000000.0;
          vMax.y = -1000000.0;
          vMax.z = -1000000.0;
          if ( !v4 )
          {
            do
            {
              v16 = (float *)(*(_DWORD *)(pStruct->m_pModel->sprite.numframes + 36)
                            + 12
                            * *(unsigned __int16 *)(*(_DWORD *)(pStruct->m_pModel->sprite.numframes + 148)
                                                  + 2 * (v11 + v3->firstvertindex)));
              p_x = &v9->m_Verts[v9->m_nVerts].x;
              *p_x = *v16;
              p_x[1] = v16[1];
              p_x[2] = v16[2];
              m_nVerts = v9->m_nVerts;
              z_low = LODWORD(v9->m_Verts[m_nVerts].z);
              v20 = &v9->m_Verts[m_nVerts];
              if ( *(float *)&z_low > *(float *)&v13 )
                z_low = v13;
              if ( v20->y <= y )
                y = v20->y;
              x_low = LODWORD(v20->x);
              if ( *(float *)&x_low > *(float *)&v12 )
                x_low = v12;
              v12 = x_low;
              v22 = LODWORD(v20->z);
              v13 = z_low;
              if ( *(float *)&v10 > *(float *)&v22 )
                v22 = v10;
              if ( v15 <= v20->y )
                v15 = v20->y;
              v23 = LODWORD(v20->x);
              if ( *(float *)&v14 > *(float *)&v23 )
                v23 = v14;
              v3 = (msurface2_t *)iDim;
              v24 = m_nVerts + 1;
              v14 = v23;
              v10 = v22;
              v9->m_nVerts = v24;
              if ( v24 >= 0x10 )
                break;
              ++v11;
            }
            while ( v11 < HIBYTE(v3->flags) );
            LODWORD(vMin.x) = v12;
            vMin.y = y;
            LODWORD(vMin.z) = v13;
            LODWORD(vMax.x) = v23;
            vMax.y = v15;
            LODWORD(vMax.z) = v22;
          }
          m_Radius = pStruct->m_Radius;
          m_pCenter = pStruct->m_pCenter;
          iDim = 0;
          v35 = (char *)((char *)&vMax - (char *)m_pCenter);
          v27 = 0;
          v36 = (char *)((char *)&vMin - (char *)m_pCenter);
          do
          {
            if ( *(float *)((char *)&m_pCenter->x + (_DWORD)v36) > (float)(m_pCenter->x + m_Radius) )
              break;
            if ( (float)(m_pCenter->x - m_Radius) > *(float *)((char *)&m_pCenter->x + (_DWORD)v35) )
              break;
            ++v27;
            m_pCenter = (const Vector *)((char *)m_pCenter + 4);
          }
          while ( v27 < 3 );
          if ( v27 == 3 )
          {
            v28 = &v3->plane->normal.x;
            v29 = v28[1];
            v30 = v28[2];
            v31 = v28[3];
            v9->m_Plane.m_Normal.x = *v28;
            v9->m_Plane.m_Normal.y = v29;
            v9->m_Plane.m_Normal.z = v30;
            v9->m_Plane.m_Dist = v31;
            ++pStruct->m_nSetInfos;
          }
        }
        else
        {
          p_m_pEngineData = &pStruct->m_pInfos->m_pEngineData;
          while ( *p_m_pEngineData != v3 )
          {
            ++v6;
            p_m_pEngineData += 54;
            if ( v6 >= m_nSetInfos )
              goto LABEL_7;
          }
        }
      }
      nummarksurfaces = pLeaf->nummarksurfaces;
      v2 = iSurf + 1;
      iSurf = v2;
    }
    while ( v2 < nummarksurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100704E0
// Name: void GetIntersectingSurfaces_R(class GetIntersectingSurfaces_Struct __near *,struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetIntersectingSurfaces_R(GetIntersectingSurfaces_Struct *pStruct, mnode_t *pNode)
{
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v5; // xmm0_4
  float v6; // xmm0_4
  const unsigned __int8 *m_pCenterPVS; // eax
  int v8; // edi
  IDispInfo *v9; // eax

  if ( pStruct->m_nSetInfos < pStruct->m_nMaxInfos )
  {
    while ( pNode->contents < 0 )
    {
      plane = pNode->plane;
      type = plane->type;
      if ( type >= 3u )
        v5 = (float)((float)(pStruct->m_pCenter->y * plane->normal.y) + (float)(plane->normal.x * pStruct->m_pCenter->x))
           + (float)(pStruct->m_pCenter->z * plane->normal.z);
      else
        v5 = *(&pStruct->m_pCenter->x + type);
      v6 = v5 - plane->dist;
      if ( v6 > COERCE_FLOAT(LODWORD(pStruct->m_Radius) ^ _mask__NegFloat_) )
        GetIntersectingSurfaces_R(pStruct, pNode: pNode->children[0]);
      if ( pStruct->m_Radius > v6 )
      {
        pNode = pNode->children[1];
        if ( pStruct->m_nSetInfos < pStruct->m_nMaxInfos )
          continue;
      }
      return;
    }
    if ( !pStruct->m_bOnlyVisible
      || (m_pCenterPVS = pStruct->m_pCenterPVS) == nullptr
      || SLOWORD(pNode->plane) >= 0
      && ((unsigned __int8)(1 << ((int)pNode->plane & 7)) & m_pCenterPVS[SLOWORD(pNode->plane) >> 3]) != 0 )
    {
      v8 = 0;
      if ( pNode->numsurfaces != 0 )
      {
        do
        {
          v9 = DispInfo_IndexArray(
                 hArray: host_state.worldbrush->hDispInfos,
                 iElement: host_state.worldbrush->m_pDispInfoReferences[v8 + pNode->firstsurface]);
          v9->GetIntersectingSurfaces(this: v9, a2: pStruct);
          ++v8;
        }
        while ( v8 < pNode->numsurfaces );
      }
      AddIntersectingLeafSurfaces(pLeaf: (mleaf_t *)pNode, pStruct);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070620
// Name: public: virtual int CEngineClient::GetIntersectingSurfaces(struct model_t const __near *,class Vector const __near &,float,bool,class SurfInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetIntersectingSurfaces(
        CEngineClient *this,
        model_t *model,
        const Vector *vCenter,
        float radius,
        bool bOnlyVisible,
        SurfInfo *pInfos,
        int nMaxInfos)
{
  int v8; // eax
  int v9; // eax
  const unsigned __int8 *v10; // eax
  int firstnode; // ecx
  worldbrushdata_t *pShared; // edx
  unsigned __int8 dest[8192]; // [esp+4h] [ebp-2020h] BYREF
  GetIntersectingSurfaces_Struct pStruct; // [esp+2004h] [ebp-20h] BYREF

  if ( model == nullptr )
    return 0;
  pStruct.m_pModel = model;
  pStruct.m_pCenter = vCenter;
  v8 = CM_PointLeafnum(p: vCenter);
  v9 = CM_LeafCluster(leafnum: v8);
  v10 = CM_Vis(dest, destlen: 0x2000, cluster: v9, visType: 0);
  pStruct.m_bOnlyVisible = bOnlyVisible;
  firstnode = model->brush.firstnode;
  pStruct.m_pCenterPVS = v10;
  pStruct.m_pInfos = pInfos;
  pShared = model->brush.pShared;
  pStruct.m_nMaxInfos = nMaxInfos;
  pStruct.m_Radius = radius;
  pStruct.m_nSetInfos = 0;
  GetIntersectingSurfaces_R(&pStruct, pNode: &pShared->nodes[firstnode]);
  return pStruct.m_nSetInfos;
}

//------------------------------------------------------------------------------
// Address: 0x100706C0
// Name: public: virtual void CEngineClient::ClientCmd_Unrestricted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ClientCmd_Unrestricted(CEngineClient *this, vgui::CTreeViewListControl *szCmdString)
{
  int m_nValue; // eax
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t v5; // eax

  if ( in_forceuser.m_pParent != nullptr )
    m_nValue = in_forceuser.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: m_nValue);
  TraceType = CTraceFilter::GetTraceType(this: szCmdString);
  Cbuf_AddText(eTarget: TraceType, pText: (const char *)szCmdString, nTickDelay: 0);
  v5 = CTraceFilter::GetTraceType(this: v4);
  Cbuf_AddText(eTarget: v5, pText: "\n", nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10070710
// Name: public: virtual int CEngineClient::GetServerTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetServerTick(CEngineClient *this)
{
  return GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick;
}

//------------------------------------------------------------------------------
// Address: 0x10070730
// Name: public: virtual char const __near * CEngineClient::GetLevelName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEngineClient::GetLevelName(CEngineClient *this)
{
  if ( sv.m_bIsDedicated )
    return "Dedicated Server";
  if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    return GetBaseLocalClient()->m_szLevelName;
  return (char *)defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10070760
// Name: public: virtual char const __near * CEngineClient::GetLevelNameShort(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEngineClient::GetLevelNameShort(CEngineClient *this)
{
  if ( sv.m_bIsDedicated )
    return "dedicated";
  if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    return GetBaseLocalClient()->m_szLevelNameShort;
  return (char *)defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10070790
// Name: public: virtual enum SkyboxVisibility_t CEngineClient::IsSkyboxVisibleFromPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::IsSkyboxVisibleFromPoint(CEngineClient *this, const Vector *vecPoint)
{
  unsigned int v3; // eax

  if ( g_pMaterialSystemConfig->nFullbright == 1 )
    return 1;
  v3 = *((__int16 *)&g_BSPData.map_leafs.m_pArray[CM_PointLeafnum(p: vecPoint)] + 3) >> 9;
  if ( (v3 & 1) != 0 )
    return 1;
  else
    return (v3 >> 1) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x100707D0
// Name: public: virtual void CEngineClient::OnStorageDeviceDetached(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::OnStorageDeviceDetached(CEngineClient *this, int iController)
{
  g_pXboxSystem->CloseContainers(this: g_pXboxSystem, a2: iController);
}

//------------------------------------------------------------------------------
// Address: 0x100707F0
// Name: void ClientDLL_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Shutdown()
{
  toolframework->ClientShutdown(this: toolframework);
  RecvTable_Term(clearall: true);
  g_pVGui->RunFrame(this: g_pVGui);
  materials->UncacheAllMaterials(this: materials);
  g_pVGui->RunFrame(this: g_pVGui);
  if ( g_pClientSidePrediction != nullptr )
    g_pClientSidePrediction->Shutdown(this: g_pClientSidePrediction);
  entitylist = nullptr;
  g_pClientSidePrediction = nullptr;
  g_ClientFactory = nullptr;
  g_ClientDLL->Shutdown(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10070870
// Name: void ClientDLL_ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_ProcessInput()
{
  CClientState *LocalClient; // eax

  if ( g_ClientDLL != nullptr )
  {
    LocalClient = GetLocalClient(nSlot: -1);
    ((void (__stdcall *)(bool))g_ClientDLL->HudProcessInput)(a1: LocalClient->m_nSignonState >= 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100708A0
// Name: public: virtual bool CEngineClient::GetPlayerInfo(int,struct player_info_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineClient::GetPlayerInfo(CEngineClient *this, CByteswap ent_num, player_info_s *pinfo)
{
  int v3; // esi
  CClientState *BaseLocalClient; // eax
  const void *v5; // eax
  char *v6; // esi

  v3 = *(_DWORD *)&ent_num - 1;
  if ( v3 < GetBaseLocalClient()->m_nMaxClients
    && v3 >= 0
    && GetBaseLocalClient()->m_pUserInfoTable != nullptr
    && (BaseLocalClient = GetBaseLocalClient(),
        (v5 = BaseLocalClient->m_pUserInfoTable->GetStringUserData(
                this: BaseLocalClient->m_pUserInfoTable,
                a2: v3,
                a3: nullptr)) != nullptr) )
  {
    v6 = (char *)pinfo;
    _V_memcpy(dest: pinfo, src: v5, count: 144);
    ent_num = (CByteswap)(*(_DWORD *)&ent_num | 3);
    CByteswap::SwapFieldsToTargetEndian(
      this: &ent_num,
      pOutputBuffer: v6,
      pBaseData: v6,
      pDataMap: &player_info_s::m_DataMap);
    return 1;
  }
  else
  {
    _V_memset(dest: pinfo, fill: 0, count: 144);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070960
// Name: public: virtual void CEngineClient::RecordDemoCustomData(void (*)(unsigned char __near *,unsigned int),void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::RecordDemoCustomData(
        CEngineClient *this,
        void (__cdecl *pCallback)(unsigned __int8 *, unsigned int),
        const void *pData,
        unsigned int iDataLength)
{
  int v4; // esi
  int v5; // edx
  int v6; // eax
  void (__cdecl *v7)(unsigned __int8 *, unsigned int); // ecx

  if ( !demorecorder->IsRecording(this: demorecorder) )
    _Warning(a1: "IEngineClient::RecordDemoCustomData(): Not recording a demo.\n");
  v4 = 0;
  v5 = g_RegisteredDemoCustomDataCallbacks.m_Size - 1;
  if ( g_RegisteredDemoCustomDataCallbacks.m_Size - 1 < 0 )
  {
LABEL_9:
    _Warning(a1: "Demo recording custom data for unregistered callback.\n");
    return;
  }
  while ( 1 )
  {
    v6 = (v5 + v4) >> 1;
    v7 = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v6].pCallback;
    if ( (unsigned int)pCallback <= (unsigned int)v7 )
      break;
    v4 = v6 + 1;
LABEL_8:
    if ( v4 > v5 )
      goto LABEL_9;
  }
  if ( (unsigned int)pCallback < (unsigned int)v7 )
  {
    v5 = v6 - 1;
    goto LABEL_8;
  }
  demorecorder->RecordCustomData(this: demorecorder, a2: v6, a3: pData, a4: iDataLength);
}

//------------------------------------------------------------------------------
// Address: 0x100709F0
// Name: void DebugDrawPhysCollide(class CPhysCollide const __near *,class IMaterial __near *,struct matrix3x4_t const __near &,struct color32_s const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall DebugDrawPhysCollide(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const struct CPhysCollide *pCollide,
        IMaterial *pMaterial,
        const matrix3x4_t *transform,
        const color32_s *color,
        bool drawAxes)
{
  IMatRenderContext *m_pObject; // edi
  int v9; // esi
  IMesh *v10; // edi
  int v11; // esi
  int v12; // edi
  float *v13; // eax
  int m_nVertexCount; // eax
  float *v15; // eax
  float *m_pCurrPosition; // eax
  float *v17; // eax
  float *v18; // eax
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  float *v22; // eax
  float *v23; // eax
  int v24; // eax
  Vector *v25; // [esp-4h] [ebp-23Ch]
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-238h] BYREF
  Vector yaxis; // [esp+1E8h] [ebp-50h] BYREF
  Vector zaxis; // [esp+1F4h] [ebp-44h] BYREF
  Vector xaxis; // [esp+200h] [ebp-38h] BYREF
  IMesh *pMesh; // [esp+20Ch] [ebp-2Ch]
  Vector *outVerts; // [esp+210h] [ebp-28h] BYREF
  int i; // [esp+214h] [ebp-24h]
  float out; // [esp+218h] [ebp-20h] BYREF
  int v34; // [esp+21Ch] [ebp-1Ch]
  int v35; // [esp+220h] [ebp-18h]
  Vector center; // [esp+224h] [ebp-14h] BYREF
  int vertCount; // [esp+230h] [ebp-8h]
  CMatRenderContextPtr pRenderContext; // [esp+234h] [ebp-4h]
  IMesh *drawAxesa; // [esp+250h] [ebp+18h]

  if ( pMaterial == nullptr )
    pMaterial = materials->FindMaterial(
                  this: materials,
                  a2: "debug/debugwireframevertexcolor",
                  a3: "Other textures",
                  a4: 1,
                  a5: 0);
  m_pObject = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(
                                     a1: materials,
                                     a2);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v9 = ((int (__thiscall *)(IPhysicsCollision *, const struct CPhysCollide *, Vector **, int, int))physcollision->CreateDebugMesh)(
         a1: physcollision,
         a2: pCollide,
         a3: &outVerts,
         a4: a3,
         a5: a1);
  vertCount = v9;
  if ( v9 != 0 )
  {
    v10 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: pMaterial);
    pMesh = v10;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v10;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v11 = 3 * (v9 / 3);
    v10->SetPrimitiveType(this: v10, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v11, a3: v11, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v10->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v11;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(
      this: &meshBuilder.m_VertexBuilder,
      pMesh: v10,
      nMaxVertexCount: v11,
      desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    if ( vertCount > 0 )
    {
      v12 = 0;
      for ( i = vertCount; i != 0; --i )
      {
        VectorTransform(in1: &outVerts[v12].x, in2: transform, out: &center.x);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = center;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = color->b
                                                            | ((color->g | ((color->r | (color->a << 8)) << 8)) << 8);
        v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v13[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ++v12;
      }
      v10 = pMesh;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v10->Draw_2(this: v10, a2: -1, a3: 0);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    m_pObject = pRenderContext.m_pObject;
    v9 = vertCount;
  }
  v25 = outVerts;
  ((void (__thiscall *)(IPhysicsCollision *))physcollision->DestroyDebugMesh)(a1: physcollision);
  if ( drawAxes )
  {
    xaxis.x = 10.0;
    xaxis.y = 0.0;
    xaxis.z = 0.0;
    yaxis.x = 0.0;
    yaxis.y = 10.0;
    yaxis.z = 0.0;
    zaxis.x = 0.0;
    zaxis.y = 0.0;
    zaxis.z = 10.0;
    MatrixGetColumn(in: transform, column: 3, out: &center);
    drawAxesa = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, IMaterial *, int, Vector *))m_pObject->GetDynamicMesh)(
                           a1: m_pObject,
                           a2: 1,
                           a3: 0,
                           a4: 0,
                           a5: pMaterial,
                           a6: v9,
                           a7: v25);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = drawAxesa;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    drawAxesa->SetPrimitiveType(this: drawAxesa, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &drawAxesa->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = drawAxesa;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 6;
    meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
    meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_bModify = false;
    if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
    {
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
    }
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = center;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v15[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    VectorTransform(in1: &xaxis.x, in2: transform, &out);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = out;
    *((_DWORD *)m_pCurrPosition + 1) = v34;
    *((_DWORD *)m_pCurrPosition + 2) = v35;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v17[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = center;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v18[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    VectorTransform(in1: &yaxis.x, in2: transform, &out);
    v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = out;
    *((_DWORD *)v19 + 1) = v34;
    *((_DWORD *)v19 + 2) = v35;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v20[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = center;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v21[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    VectorTransform(in1: &zaxis.x, in2: transform, &out);
    v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = out;
    *((_DWORD *)v22 + 1) = v34;
    *((_DWORD *)v22 + 2) = v35;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v23[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v24 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v24 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v24 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v24 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v24 = 0;
          break;
        default:
          v24 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v24);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    drawAxesa->Draw_2(this: drawAxesa, a2: -1, a3: 0);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    m_pObject = pRenderContext.m_pObject;
  }
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100711C0
// Name: public: virtual void CEngineClient::GetScreenSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetScreenSize(CEngineClient *this, int *w, int *h)
{
  IMatRenderContext *v3; // esi

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v3->GetWindowSize(this: v3, a2: w, a3: h);
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10071210
// Name: public: virtual void CEngineClient::DebugDrawPhysCollide(class CPhysCollide const __near *,class IMaterial __near *,struct matrix3x4_t const __near &,struct color32_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::DebugDrawPhysCollide(
        CEngineClient *this,
        const struct CPhysCollide *pCollide,
        IMaterial *pMaterial,
        const matrix3x4_t *transform,
        const color32_s *color)
{
  DebugDrawPhysCollide(pCollide, pMaterial, transform, color, drawAxes: false);
}

//------------------------------------------------------------------------------
// Address: 0x10071240
// Name: public: virtual void CEngineClient::RegisterDemoCustomDataCallback(struct string_t,void (*)(unsigned char __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::RegisterDemoCustomDataCallback(
        CEngineClient *this,
        string_t szCallbackSaveID,
        void (__cdecl *pCallback)(unsigned __int8 *, unsigned int))
{
  int v3; // esi
  int v4; // ecx
  int v5; // eax
  void (__cdecl *v6)(unsigned __int8 *, unsigned int); // edx
  RegisteredDemoCustomDataCallbackPair_t addPair; // [esp+0h] [ebp-8h] BYREF

  if ( demorecorder->IsRecording(this: demorecorder) )
    _Warning(a1: "Late registration of demo custom data callback.\n");
  v3 = 0;
  v4 = g_RegisteredDemoCustomDataCallbacks.m_Size - 1;
  if ( g_RegisteredDemoCustomDataCallbacks.m_Size - 1 < 0 )
  {
LABEL_9:
    addPair.pCallback = pCallback;
    addPair.szSaveID = szCallbackSaveID;
    CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
      this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_RegisteredDemoCustomDataCallbacks,
      elem: v3,
      src: (const vgui::PropertySheet::Page_t *)&addPair);
    return;
  }
  while ( 1 )
  {
    v5 = (v4 + v3) >> 1;
    v6 = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v5].pCallback;
    if ( (unsigned int)pCallback <= (unsigned int)v6 )
      break;
    v3 = v5 + 1;
LABEL_8:
    if ( v3 > v4 )
      goto LABEL_9;
  }
  if ( (unsigned int)pCallback < (unsigned int)v6 )
  {
    v4 = v5 - 1;
    goto LABEL_8;
  }
  _Warning(a1: "Double registration of demo custom data callback.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10132160
// Name: public: virtual float CEngineClient::SentenceLength(int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineClient::SentenceLength(CEngineClient *this, int sentenceIndex)
{
  return VOX_SentenceLength(sentence_num: sentenceIndex);
}

//------------------------------------------------------------------------------
// Address: 0x101324B0
// Name: public: virtual char const __near * CEngineClient::ParseFile(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineClient::ParseFile(CEngineClient *this, const char *data, char *token, int maxlen)
{
  return COM_ParseFile(data, token, maxtoken: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x101324D0
// Name: public: virtual bool CEngineClient::CopyFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::CopyFile(CEngineClient *this, const char *source, const char *destination)
{
  return COM_CopyFile(netpath: source, cachepath: destination);
}

//------------------------------------------------------------------------------
// Address: 0x101325D0
// Name: public: virtual class IAchievementMgr __near * CEngineClient::GetAchievementMgr(void)
// Source: json
//------------------------------------------------------------------------------
IAchievementMgr *__thiscall CEngineClient::GetAchievementMgr(CEngineClient *this)
{
  return g_pAchievementMgr;
}

//------------------------------------------------------------------------------
// Address: 0x10132720
// Name: public: virtual class CGamestatsData __near * CEngineClient::GetGamestatsData(void)
// Source: json
//------------------------------------------------------------------------------
struct CGamestatsData *__thiscall CEngineClient::GetGamestatsData(CEngineClient *this)
{
  return g_pGamestatsData;
}

//------------------------------------------------------------------------------
// Address: 0x10132830
// Name: public: virtual bool CEngineClient::IsLevelMainMenuBackground(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsLevelMainMenuBackground(CEngineClient *this)
{
  return sv.m_bIsLevelMainMenuBackground;
}

//------------------------------------------------------------------------------
// Address: 0x101FF510
// Name: public: virtual int CEngineClient::GetMaxClients(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetMaxClients(CEngineClient *this)
{
  return GetBaseLocalClient()->m_nMaxClients;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1006E030
// Name: public: virtual char const __near * CEngineClient::GetProductVersionString(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const char *__thiscall CEngineClient::GetProductVersionString(CEngineClient *this)
{
  return Sys_GetVersionString();
}

//------------------------------------------------------------------------------
// Address: 0x1006E050
// Name: public: virtual class Vector CEngineClient::GetLightForPoint(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CEngineClient::GetLightForPoint(CEngineClient *this, Vector *result, const Vector *pos, BOOL bClamp)
{
  this->ComputeLighting(this, a2: pos, a3: nullptr, a4: bClamp, a5: result, a6: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006E080
// Name: public: virtual class Vector CEngineClient::GetLightForPointFast(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CEngineClient::GetLightForPointFast(
        CEngineClient *this,
        Vector *result,
        const Vector *pos,
        bool bClamp)
{
  int v4; // eax
  double x; // st7
  double y; // st6
  double z; // st5
  double v8; // st4
  double v9; // st7
  double v10; // rt1
  double v11; // st5
  double v12; // st7
  double v13; // st4
  double v14; // st6
  double v15; // rtt
  double v16; // st5
  double v17; // st6
  double v18; // st4
  double v19; // st7
  double v20; // rt1
  double v21; // st5
  double v22; // st7
  double v23; // st4
  double v24; // st6
  double v25; // rtt
  double v26; // st5
  double v27; // st6
  double v28; // st4
  double v29; // st7
  double v30; // rt1
  double v31; // st5
  double v32; // st7
  double v33; // st4
  double v34; // st6
  double v35; // rtt
  double v36; // st5
  double v37; // st6
  double v38; // st4
  double v39; // st7
  double v40; // rt1
  double v41; // st5
  double v42; // st7
  double v43; // st4
  double v44; // st6
  double v45; // rtt
  double v46; // st5
  double v47; // st6
  double v48; // st4
  double v49; // st7
  double v50; // rt1
  double v51; // st5
  double v52; // st7
  double v53; // st4
  double v54; // st6
  double v55; // rtt
  double v56; // st5
  double v57; // st6
  double v58; // st4
  double v59; // st7
  double v60; // rt1
  double v61; // st5
  double v62; // st7
  double v63; // st4
  double v64; // st6
  double v65; // rtt
  double v66; // st5
  double v67; // st6
  double v68; // st4
  double v69; // st7
  double v70; // rt1
  double v71; // st5
  double v72; // st7
  double v73; // st5
  double v74; // st6
  double v75; // st6
  double v76; // st7
  Vector *v77; // eax
  Vector cube[6]; // [esp+8h] [ebp-48h] BYREF

  v4 = CM_PointLeafnum(p: pos);
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  Mod_LeafAmbientColorAtPos(pOut: cube, pos, leafIndex: v4);
  x = cube[0].x;
  if ( result->x >= (double)cube[0].x )
    x = result->x;
  result->x = x;
  y = cube[0].y;
  if ( result->y >= (double)cube[0].y )
    y = result->y;
  result->y = y;
  z = cube[0].z;
  if ( result->z >= (double)cube[0].z )
    z = result->z;
  result->z = z;
  v8 = x;
  v9 = cube[1].x;
  if ( v8 >= cube[1].x )
    v9 = v8;
  v10 = z;
  v11 = v9;
  v12 = v10;
  result->x = v11;
  v13 = y;
  v14 = cube[1].y;
  if ( v13 >= cube[1].y )
    v14 = v13;
  v15 = v11;
  v16 = v14;
  v17 = v15;
  result->y = v16;
  v18 = v12;
  v19 = cube[1].z;
  if ( v18 >= cube[1].z )
    v19 = v18;
  v20 = v16;
  v21 = v19;
  v22 = v20;
  result->z = v21;
  v23 = v17;
  v24 = cube[2].x;
  if ( v23 >= cube[2].x )
    v24 = v23;
  v25 = v21;
  v26 = v24;
  v27 = v25;
  result->x = v26;
  v28 = v22;
  v29 = cube[2].y;
  if ( v28 >= cube[2].y )
    v29 = v28;
  v30 = v26;
  v31 = v29;
  v32 = v30;
  result->y = v31;
  v33 = v27;
  v34 = cube[2].z;
  if ( v33 >= cube[2].z )
    v34 = v33;
  v35 = v31;
  v36 = v34;
  v37 = v35;
  result->z = v36;
  v38 = v32;
  v39 = cube[3].x;
  if ( v38 >= cube[3].x )
    v39 = v38;
  v40 = v36;
  v41 = v39;
  v42 = v40;
  result->x = v41;
  v43 = v37;
  v44 = cube[3].y;
  if ( v43 >= cube[3].y )
    v44 = v43;
  v45 = v41;
  v46 = v44;
  v47 = v45;
  result->y = v46;
  v48 = v42;
  v49 = cube[3].z;
  if ( v48 >= cube[3].z )
    v49 = v48;
  v50 = v46;
  v51 = v49;
  v52 = v50;
  result->z = v51;
  v53 = v47;
  v54 = cube[4].x;
  if ( v53 >= cube[4].x )
    v54 = v53;
  v55 = v51;
  v56 = v54;
  v57 = v55;
  result->x = v56;
  v58 = v52;
  v59 = cube[4].y;
  if ( v58 >= cube[4].y )
    v59 = v58;
  v60 = v56;
  v61 = v59;
  v62 = v60;
  result->y = v61;
  v63 = v57;
  v64 = cube[4].z;
  if ( v63 >= cube[4].z )
    v64 = v63;
  v65 = v61;
  v66 = v64;
  v67 = v65;
  result->z = v66;
  v68 = v62;
  v69 = cube[5].x;
  if ( v68 >= cube[5].x )
    v69 = v68;
  v70 = v66;
  v71 = v69;
  v72 = v70;
  result->x = v71;
  v73 = v67;
  v74 = cube[5].y;
  if ( v73 >= cube[5].y )
    v74 = v73;
  result->y = v74;
  v75 = v72;
  v76 = cube[5].z;
  if ( v75 >= cube[5].z )
    v76 = v75;
  result->z = v76;
  if ( !bClamp )
    return result;
  if ( result->x > 1.0 )
    result->x = 1.0;
  if ( result->y > 1.0 )
    result->y = 1.0;
  v77 = result;
  if ( result->z > 1.0 )
    result->z = 1.0;
  return v77;
}

//------------------------------------------------------------------------------
// Address: 0x1006E260
// Name: public: virtual char const __near * CEngineClient::ParseFile(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineClient::ParseFile(CEngineClient *this, const char *data, char *token, int maxlen)
{
  return COM_ParseFile(data, token, maxtoken: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x1006E280
// Name: public: virtual bool CEngineClient::CopyFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::CopyFile(CEngineClient *this, const char *source, const char *destination)
{
  return COM_CopyFile(netpath: source, cachepath: destination);
}

//------------------------------------------------------------------------------
// Address: 0x1006E2A0
// Name: public: virtual void CEngineClient::ServerCmd(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ServerCmd(CEngineClient *this, const char *szCmdString, bool bReliable)
{
  CCommand args; // [esp+0h] [ebp-608h] BYREF
  char buf[256]; // [esp+508h] [ebp-100h] BYREF

  V_snprintf(pDest: buf, maxLen: 255, pFormat: "cmd %s", szCmdString);
  CCommand::CCommand(this: &args);
  CCommand::Tokenize(this: &args, pCommand: buf, pBreakSet: nullptr);
  Cmd_ForwardToServer(&args, bReliable);
}

//------------------------------------------------------------------------------
// Address: 0x1006E300
// Name: public: virtual void CEngineClient::ClientCmd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ClientCmd(CEngineClient *this, const char *szCmdString)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax

  if ( GetBaseLocalClient()->m_bRestrictClientCommands )
  {
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddExecutionMarker(eTarget: TraceType, marker: eCmdExecutionMarker_Enable_FCVAR_CLIENTCMD_CAN_EXECUTE);
  }
  v4 = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: v4, pText: szCmdString, nTickDelay: 0);
  v6 = CTraceFilter::GetTraceType(this: v5);
  Cbuf_AddText(eTarget: v6, pText: "\n", nTickDelay: 0);
  if ( GetBaseLocalClient()->m_bRestrictClientCommands )
  {
    v8 = CTraceFilter::GetTraceType(this: v7);
    Cbuf_AddExecutionMarker(eTarget: v8, marker: eCmdExecutionMarker_Disable_FCVAR_CLIENTCMD_CAN_EXECUTE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E370
// Name: public: virtual void CEngineClient::SetRestrictServerCommands(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetRestrictServerCommands(CEngineClient *this, bool bRestrict)
{
  GetBaseLocalClient()->m_bRestrictServerCommands = bRestrict;
}

//------------------------------------------------------------------------------
// Address: 0x1006E390
// Name: public: virtual void CEngineClient::SetRestrictClientCommands(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetRestrictClientCommands(CEngineClient *this, bool bRestrict)
{
  GetBaseLocalClient()->m_bRestrictClientCommands = bRestrict;
}

//------------------------------------------------------------------------------
// Address: 0x1006E410
// Name: public: virtual bool CEngineClient::Con_IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineClient::Con_IsVisible(CEngineClient *this)
{
  return Con_IsVisible();
}

//------------------------------------------------------------------------------
// Address: 0x1006E420
// Name: public: virtual int CEngineClient::GetLocalPlayer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetLocalPlayer(CEngineClient *this)
{
  return GetLocalClient(nSlot: -1)->m_nPlayerSlot + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006E440
// Name: public: virtual float CEngineClient::GetLastTimeStamp(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineClient::GetLastTimeStamp(CEngineClient *this)
{
  return GetBaseLocalClient()->m_flLastServerTickTime;
}

//------------------------------------------------------------------------------
// Address: 0x1006E450
// Name: public: virtual int CEngineClient::GetLastAcknowledgedCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetLastAcknowledgedCommand(CEngineClient *this)
{
  return GetBaseLocalClient()->command_ack;
}

//------------------------------------------------------------------------------
// Address: 0x1006E460
// Name: public: virtual bool CEngineClient::MapHasHDRLighting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::MapHasHDRLighting(CEngineClient *this)
{
  return modelloader->LastLoadedMapHasHDRLighting(this: modelloader);
}

//------------------------------------------------------------------------------
// Address: 0x1006E470
// Name: public: virtual struct model_t const __near * CEngineClient::LoadModel(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
const model_t *__thiscall CEngineClient::LoadModel(CEngineClient *this, const char *pName, bool bProp)
{
  return modelloader->GetModelForName(
           this: modelloader,
           a2: pName,
           a3: (IModelLoader::REFERENCETYPE)(bProp ? FMODELLOADER_DETAILPROP : FMODELLOADER_CLIENTDLL));
}

//------------------------------------------------------------------------------
// Address: 0x1006E4A0
// Name: public: virtual class CSentence __near * CEngineClient::GetSentence(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CEngineClient::GetSentence(CEngineClient *this, CAudioSource *pAudioSource)
{
  if ( pAudioSource != nullptr )
    return pAudioSource->GetSentence(this: pAudioSource);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006E4C0
// Name: public: virtual float CEngineClient::GetSentenceLength(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineClient::GetSentenceLength(CEngineClient *this, CAudioSource *pAudioSource)
{
  float v3; // [esp+4h] [ebp-4h]

  if ( pAudioSource == nullptr || pAudioSource->SampleRate(this: pAudioSource) <= 0 )
    return 0.0;
  v3 = (float)pAudioSource->SampleCount(this: pAudioSource);
  return v3 / (double)pAudioSource->SampleRate(this: pAudioSource);
}

//------------------------------------------------------------------------------
// Address: 0x1006E510
// Name: public: virtual bool CEngineClient::IsStreaming(class CAudioSource __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsStreaming(CEngineClient *this, CAudioSource *pAudioSource)
{
  return pAudioSource != nullptr && pAudioSource->IsStreaming(this: pAudioSource);
}

//------------------------------------------------------------------------------
// Address: 0x1006E530
// Name: public: virtual void CEngineClient::GetViewAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetViewAngles(CEngineClient *this, QAngle *va)
{
  *va = GetLocalClient(nSlot: -1)->viewangles;
}

//------------------------------------------------------------------------------
// Address: 0x1006E560
// Name: public: virtual void CEngineClient::SetViewAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetViewAngles(CEngineClient *this, QAngle *va)
{
  float vaa; // [esp+28h] [ebp+8h]
  float vab; // [esp+28h] [ebp+8h]
  float vac; // [esp+28h] [ebp+8h]
  float vad; // [esp+28h] [ebp+8h]

  vaa = va->x;
  if ( (LODWORD(vaa) & 0x7F800000) == 0x7F800000
    || (LODWORD(va->y) & 0x7F800000) == 0x7F800000
    || (LODWORD(va->z) & 0x7F800000) == 0x7F800000 )
  {
    _Warning(a1: "CEngineClient::SetViewAngles:  rejecting invalid value [%f %f %f]\n", vaa, va->y, va->z);
    GetLocalClient(nSlot: -1)->viewangles = vec3_angle;
  }
  else
  {
    vab = AngleNormalize(angle: vaa);
    GetLocalClient(nSlot: -1)->viewangles.x = vab;
    vac = AngleNormalize(angle: va->y);
    GetLocalClient(nSlot: -1)->viewangles.y = vac;
    vad = AngleNormalize(angle: va->z);
    GetLocalClient(nSlot: -1)->viewangles.z = vad;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E6A0
// Name: public: virtual bool CEngineClient::MapLoadFailed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::MapLoadFailed(CEngineClient *this)
{
  return g_ServerGlobalVariables.bMapLoadFailed;
}

//------------------------------------------------------------------------------
// Address: 0x1006E6F0
// Name: public: virtual char const __near * CEngineClient::Key_BindingForKey(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineClient::Key_BindingForKey(CEngineClient *this, ButtonCode_t code)
{
  return Key_BindingForKey(code);
}

//------------------------------------------------------------------------------
// Address: 0x1006E730
// Name: public: virtual void CEngineClient::StartKeyTrapMode(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineClient::StartKeyTrapMode(CEngineClient *this)
{
  Key_StartTrapMode();
}

//------------------------------------------------------------------------------
// Address: 0x1006E780
// Name: public: virtual void CEngineClient::HideLoadingPlaque(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::HideLoadingPlaque(CEngineClient *this)
{
  if ( !scr_drawloading )
    DevWarning(a1: "Attempted to HideLoadingPlaque when not loading...\n");
  if ( g_ClientDLL != nullptr && !g_ClientDLL->ShouldHideLoadingPlaque(this: g_ClientDLL) )
    DevWarning(a1: "Attempted to HideLoadingPlaque when client prevents hiding loading plaque...\n");
  SCR_EndLoadingPlaque();
}

//------------------------------------------------------------------------------
// Address: 0x1006E7D0
// Name: public: virtual void CEngineClient::Con_NPrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CEngineClient::Con_NPrintf(CEngineClient *this, int pos, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  Con_NPrintf(idx: pos, fmt: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x1006E820
// Name: public: virtual void CEngineClient::Con_NXPrintf(struct con_nprint_s const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CEngineClient::Con_NXPrintf(CEngineClient *this, const con_nprint_s *info, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: fmt, params);
  Con_NXPrintf(info, fmt: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x1006E870
// Name: public: virtual class IMaterial __near * CEngineClient::TraceLineMaterialAndLighting(class Vector const __near &,class Vector const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CEngineClient::TraceLineMaterialAndLighting(
        CEngineClient *this,
        const Vector *start,
        const Vector *end,
        Vector *diffuseLightColor,
        Vector *baseColor)
{
  return BrushModel_GetLightingAndMaterial(start, end, diffuseLightColor, baseColor);
}

//------------------------------------------------------------------------------
// Address: 0x1006E890
// Name: public: virtual int CEngineClient::IsBoxVisible(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::IsBoxVisible(CEngineClient *this, const Vector *mins, const Vector *maxs)
{
  const unsigned __int8 *v3; // eax
  int v5; // [esp-4h] [ebp-4h]

  v5 = CM_ClusterPVSSize();
  v3 = Map_VisCurrent();
  return CM_BoxVisible(mins, maxs, visbits: v3, vissize: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1006E8C0
// Name: public: virtual int CEngineClient::IsBoxInViewCluster(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::IsBoxInViewCluster(CEngineClient *this, const Vector *mins, const Vector *maxs)
{
  int v3; // eax
  const unsigned __int8 *v5; // eax
  unsigned __int8 dest[8192]; // [esp+0h] [ebp-2000h] BYREF

  v3 = Map_VisCurrentCluster();
  if ( v3 < 0 )
    return 0;
  v5 = CM_Vis(dest, destlen: 0x2000, cluster: v3, visType: 0);
  return CM_BoxVisible(mins, maxs, visbits: v5, vissize: 0x2000);
}

//------------------------------------------------------------------------------
// Address: 0x1006E910
// Name: public: virtual void CEngineClient::Sound_ExtraUpdate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineClient::Sound_ExtraUpdate(CEngineClient *this)
{
  S_ExtraUpdate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006E920
// Name: public: virtual bool CEngineClient::CullBox(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::CullBox(CEngineClient *this, const Vector *mins, const Vector *maxs)
{
  return Frustum_t::CullBox(this: &g_Frustum, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x1006E940
// Name: public: virtual char const __near * CEngineClient::GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const char *__thiscall CEngineClient::GetModDirectory(CEngineClient *this)
{
  return COM_GetModDirectory();
}

//------------------------------------------------------------------------------
// Address: 0x1006E950
// Name: public: virtual class VMatrix const __near & CEngineClient::WorldToScreenMatrix(void)
// Source: json
//------------------------------------------------------------------------------
const VMatrix *__thiscall CEngineClient::WorldToScreenMatrix(CEngineClient *this)
{
  return g_EngineRenderer->WorldToScreenMatrix(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x1006E960
// Name: public: virtual class VMatrix const __near & CEngineClient::WorldToViewMatrix(void)
// Source: json
//------------------------------------------------------------------------------
const VMatrix *__thiscall CEngineClient::WorldToViewMatrix(CEngineClient *this)
{
  return g_EngineRenderer->ViewMatrix(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x1006E970
// Name: public: virtual int CEngineClient::GameLumpVersion(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GameLumpVersion(CEngineClient *this, int lumpId)
{
  return Mod_GameLumpVersion(lumpId);
}

//------------------------------------------------------------------------------
// Address: 0x1006E9E0
// Name: SetNodeFlagBits
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetNodeFlagBits(mnode_t *node)
{
  if ( node->contents < 0 )
  {
    SetNodeFlagBits(node: node->children[0]);
    SetNodeFlagBits(node: node->children[1]);
    node->flags = node->flags & 7 | node->children[1]->flags | node->children[0]->flags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EAA0
// Name: public: virtual class ISpatialQuery __near * CEngineClient::GetBSPTreeQuery(void)
// Source: json
//------------------------------------------------------------------------------
IEngineSpatialQuery *__thiscall CEngineClient::GetBSPTreeQuery(CEngineClient *this)
{
  return g_pToolBSPTree;
}

//------------------------------------------------------------------------------
// Address: 0x1006EAB0
// Name: public: virtual void CEngineClient::LinearToGamma(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::LinearToGamma(CEngineClient *this, float *linear, float *gamma)
{
  *gamma = (float)LinearToTexture(f: *linear) * 0.0039215689;
  gamma[1] = (float)LinearToTexture(f: linear[1]) * 0.0039215689;
  gamma[2] = (float)LinearToTexture(f: linear[2]) * 0.0039215689;
}

//------------------------------------------------------------------------------
// Address: 0x1006EB40
// Name: public: virtual void CEngineClient::DrawPortals(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineClient::DrawPortals(CEngineClient *this)
{
  R_DrawPortals();
}

//------------------------------------------------------------------------------
// Address: 0x1006EB50
// Name: public: virtual void CEngineClient::ComputeDynamicLighting(class Vector const __near &,class Vector const __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ComputeDynamicLighting(
        CEngineClient *this,
        const Vector *pt,
        const Vector *pNormal,
        Vector *color)
{
  ComputeDynamicLighting(pt, pNormal, color);
}

//------------------------------------------------------------------------------
// Address: 0x1006EBA0
// Name: public: virtual void CEngineClient::ComputeLightingCube(class Vector const __near &,bool,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ComputeLightingCube(
        CEngineClient *this,
        const Vector *pt,
        bool bClamp,
        Vector *pBoxColors)
{
  Vector dummy; // [esp+0h] [ebp-Ch] BYREF

  ComputeLighting(pt, pNormal: nullptr, bClamp, bAddDynamicLightsToBox: true, color: &dummy, pBoxColors);
}

//------------------------------------------------------------------------------
// Address: 0x1006EBD0
// Name: public: virtual void CEngineClient::GetAmbientLightColor(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetAmbientLightColor(CEngineClient *this, Vector *color)
{
  dworldlight_t *AmbientLight; // eax

  AmbientLight = FindAmbientLight();
  if ( AmbientLight != nullptr )
  {
    *color = AmbientLight->intensity;
  }
  else
  {
    color->x = 0.0;
    color->y = 0.0;
    color->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EC90
// Name: public: virtual void CEngineClient::GetMainMenuBackgroundName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetMainMenuBackgroundName(CEngineClient *this, char *dest, int destlen)
{
  CL_GetBackgroundLevelName(pszBackgroundName: dest, bufSize: destlen, bMapName: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006ECB0
// Name: public: virtual void CEngineClient::GetStartupImage(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetStartupImage(CEngineClient *this, char *dest, int destlen)
{
  CL_GetStartupImage(pOutBuffer: dest, nOutBufferSize: destlen);
}

//------------------------------------------------------------------------------
// Address: 0x1006ECE0
// Name: public: virtual bool CEngineClient::SaveGame(char const __near *,bool,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::SaveGame(
        CEngineClient *this,
        const char *pSaveFilename,
        BOOL bIsXSave,
        char *pOutName,
        int nOutNameSize,
        char *pOutComment,
        int nOutCommentSize)
{
  return saverestore->SaveGame(
           this: saverestore,
           a2: pSaveFilename,
           a3: bIsXSave,
           a4: pOutName,
           a5: nOutNameSize,
           a6: pOutComment,
           a7: nOutCommentSize);
}

//------------------------------------------------------------------------------
// Address: 0x1006ED00
// Name: public: virtual void CEngineClient::SetOcclusionParameters(struct OcclusionParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetOcclusionParameters(CEngineClient *this, const OcclusionParams_t *params)
{
  IOcclusionSystem *v2; // eax

  v2 = OcclusionSystem();
  v2->SetOcclusionParameters(this: v2, a2: params->m_flMaxOccludeeArea, a3: params->m_flMinOccluderArea);
}

//------------------------------------------------------------------------------
// Address: 0x1006ED30
// Name: public: virtual int CEngineClient::GetPlayerForUserID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetPlayerForUserID(CEngineClient *this, int userID)
{
  int v4; // esi
  player_info_s ent_info; // [esp+4h] [ebp-90h] BYREF

  if ( GetBaseLocalClient()->m_pUserInfoTable == nullptr )
    return 0;
  if ( GetBaseLocalClient()->m_nMaxClients <= 0 )
    return 0;
  v4 = 1;
  while ( !this->GetPlayerInfo(this, a2: v4, a3: &ent_info) || ent_info.userID != userID )
  {
    if ( v4++ >= GetBaseLocalClient()->m_nMaxClients )
      return 0;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1006EDC0
// Name: public: virtual struct IVoiceTweak_s __near * CEngineClient::GetVoiceTweakAPI(void)
// Source: json
//------------------------------------------------------------------------------
IVoiceTweak_s *__thiscall CEngineClient::GetVoiceTweakAPI(CEngineClient *this)
{
  return &g_VoiceTweakAPI;
}

//------------------------------------------------------------------------------
// Address: 0x1006EDD0
// Name: public: virtual void CEngineClient::EngineStats_BeginFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::EngineStats_BeginFrame(CEngineClient *this)
{
  CEngineStats::BeginFrame(this: &g_EngineStats);
}

//------------------------------------------------------------------------------
// Address: 0x1006EDE0
// Name: public: virtual void CEngineClient::EngineStats_EndFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::EngineStats_EndFrame(CEngineClient *this)
{
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&g_EngineStats);
}

//------------------------------------------------------------------------------
// Address: 0x1006EDF0
// Name: public: virtual void CEngineClient::FireEvents(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineClient::FireEvents(CEngineClient *this)
{
  CL_FireEvents();
}

//------------------------------------------------------------------------------
// Address: 0x1006EE00
// Name: public: virtual void CEngineClient::CheckPoint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::CheckPoint(CEngineClient *this, char *pName)
{
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName);
}

//------------------------------------------------------------------------------
// Address: 0x1006EE70
// Name: public: virtual bool CEngineClient::DoesBoxTouchAreaFrustum(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::DoesBoxTouchAreaFrustum(
        CEngineClient *this,
        const Vector *mins,
        const Vector *maxs,
        int iArea)
{
  Frustum_t *AreaFrustum; // eax

  AreaFrustum = (Frustum_t *)GetAreaFrustum(area: iArea);
  return !Frustum_t::CullBox(this: AreaFrustum, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x1006EEA0
// Name: public: virtual int CEngineClient::GetFrustumList(class Frustum_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetFrustumList(CEngineClient *this, Frustum_t **pList, int listMax)
{
  *pList = &g_Frustum;
  return GetAllAreaFrustums(pFrustumList: pList + 1, listMax: listMax - 1) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006EEF0
// Name: public: virtual int CEngineClient::SentenceGroupPick(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::SentenceGroupPick(CEngineClient *this, int groupIndex, char *name, int nameLen)
{
  return VOX_GroupPick(isentenceg: groupIndex, szfound: name, strLen: nameLen);
}

//------------------------------------------------------------------------------
// Address: 0x1006EFD0
// Name: public: virtual bool CEngineClient::IsOccluded(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsOccluded(CEngineClient *this, const Vector *vecAbsMins, const Vector *vecAbsMaxs)
{
  IOcclusionSystem *v3; // eax

  v3 = OcclusionSystem();
  return v3->IsOccluded(this: v3, a2: vecAbsMins, a3: vecAbsMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x1006F030
// Name: public: virtual class INetChannelInfo __near * CEngineClient::GetNetChannelInfo(void)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CEngineClient::GetNetChannelInfo(CEngineClient *this)
{
  return GetBaseLocalClient()->m_NetChannel;
}

//------------------------------------------------------------------------------
// Address: 0x1006F050
// Name: public: virtual bool CEngineClient::IsRecordingDemo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsRecordingDemo(CEngineClient *this)
{
  return demorecorder->IsRecording(this: demorecorder);
}

//------------------------------------------------------------------------------
// Address: 0x1006F060
// Name: public: virtual bool CEngineClient::IsPlayingTimeDemo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsPlayingTimeDemo(CEngineClient *this)
{
  return demoplayer->IsPlayingTimeDemo(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1006F080
// Name: public: virtual bool CEngineClient::IsTakingScreenshot(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsTakingScreenshot(CEngineClient *this)
{
  return cl_takesnapshot;
}

//------------------------------------------------------------------------------
// Address: 0x1006F090
// Name: public: virtual void CEngineClient::WriteScreenshot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::WriteScreenshot(CEngineClient *this, const char *pFilename)
{
  cl_takesnapshot = true;
  cl_takejpeg = true;
  V_strncpy(pDest: cl_snapshot_fullpathname, pSrc: pFilename, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x1006F100
// Name: public: virtual int CEngineClient::GetDemoPlaybackTotalTicks(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetDemoPlaybackTotalTicks(CEngineClient *this)
{
  return demoplayer->GetTotalTicks(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1006F110
// Name: public: virtual bool CEngineClient::IsHLTV(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsHLTV(CEngineClient *this)
{
  return GetBaseLocalClient()->ishltv;
}

//------------------------------------------------------------------------------
// Address: 0x1006F120
// Name: public: virtual void CEngineClient::GetUILanguage(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetUILanguage(CEngineClient *this, char *dest, int destlen)
{
  char *m_pszString; // eax

  if ( (cl_language.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = cl_language.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  V_strncpy(pDest: dest, pSrc: m_pszString, maxLen: destlen);
}

//------------------------------------------------------------------------------
// Address: 0x1006F170
// Name: public: virtual bool CEngineClient::IsInEditMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsInEditMode(CEngineClient *this)
{
  return g_bInEditMode;
}

//------------------------------------------------------------------------------
// Address: 0x1006F190
// Name: public: virtual float CEngineClient::GetScreenAspectRatio(int,int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineClient::GetScreenAspectRatio(CEngineClient *this, int viewportWidth, int viewportHeight)
{
  return GetScreenAspect(viewportWidth, viewportHeight);
}

//------------------------------------------------------------------------------
// Address: 0x1006F1B0
// Name: public: virtual void CEngineClient::SetOverlayBindProxy(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetOverlayBindProxy(CEngineClient *this, int iOverlayID, void *pBindProxy)
{
  IOverlayMgr *v3; // eax

  v3 = OverlayMgr();
  v3->SetOverlayBindProxy(this: v3, a2: iOverlayID, a3: pBindProxy);
}

//------------------------------------------------------------------------------
// Address: 0x1006F200
// Name: public: virtual void CEngineClient::SetAchievementMgr(class IAchievementMgr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetAchievementMgr(CEngineClient *this, IAchievementMgr *pAchievementMgr)
{
  g_pAchievementMgr = pAchievementMgr;
}

//------------------------------------------------------------------------------
// Address: 0x1006F260
// Name: public: virtual void CEngineClient::SetMostRecentSaveGame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetMostRecentSaveGame(CEngineClient *this, const char *lpszFilename)
{
  saverestore->SetMostRecentSaveGame(this: saverestore, a2: lpszFilename);
}

//------------------------------------------------------------------------------
// Address: 0x1006F280
// Name: public: virtual bool CEngineClient::IsSaveInProgress(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsSaveInProgress(CEngineClient *this)
{
  return saverestore->IsSaveInProgress(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x1006F2A0
// Name: public: virtual char const __near * CEngineClient::GetSaveDirName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineClient::GetSaveDirName(CEngineClient *this)
{
  return saverestore->GetSaveDir(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x1006F2D0
// Name: public: virtual void CEngineClient::FinishContainerWrites(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::FinishContainerWrites(CEngineClient *this, int iController)
{
  g_pXboxSystem->FinishContainerWrites(this: g_pXboxSystem, a2: iController);
}

//------------------------------------------------------------------------------
// Address: 0x1006F300
// Name: public: virtual void CEngineClient::ResetDemoInterpolation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ResetDemoInterpolation(CEngineClient *this)
{
  if ( demorecorder->IsRecording(this: demorecorder) )
    demorecorder->ResetDemoInterpolation(this: demorecorder);
  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    demoplayer->ResetDemoInterpolation(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1006F360
// Name: public: virtual int CEngineClient::GetSplitScreenPlayer(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetSplitScreenPlayer(CEngineClient *this, int nSlot)
{
  return splitscreen->GetSplitScreenPlayerEntity(this: splitscreen, a2: nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1006F400
// Name: public: virtual bool CEngineClient::IsValidSplitScreenSlot(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsValidSplitScreenSlot(CEngineClient *this, int nSlot)
{
  return splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1006F420
// Name: public: virtual int CEngineClient::FirstValidSplitScreenSlot(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::FirstValidSplitScreenSlot(CEngineClient *this)
{
  return splitscreen->FirstValidSplitScreenSlot(this: splitscreen);
}

//------------------------------------------------------------------------------
// Address: 0x1006F470
// Name: public: virtual class CGamestatsData __near * CEngineClient::GetGamestatsData(void)
// Source: json
//------------------------------------------------------------------------------
struct CGamestatsData *__thiscall CEngineClient::GetGamestatsData(CEngineClient *this)
{
  return g_pGamestatsData;
}

//------------------------------------------------------------------------------
// Address: 0x1006F4F0
// Name: public: virtual float CEngineClient::DSPGetCurrentDASRoomSkyPercent(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
double __thiscall CEngineClient::DSPGetCurrentDASRoomSkyPercent(CEngineClient *this)
{
  return S_DSPGetCurrentDASRoomSkyPercent();
}

//------------------------------------------------------------------------------
// Address: 0x1006F500
// Name: public: virtual void CEngineClient::SetMixGroupOfCurrentMixer(char const __near *,char const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetMixGroupOfCurrentMixer(
        CEngineClient *this,
        const char *szgroupname,
        const char *szparam,
        float val,
        int setMixerType)
{
  S_SetMixGroupOfCurrentMixer(szgroupname, szparam, val);
}

//------------------------------------------------------------------------------
// Address: 0x1006F530
// Name: public: virtual int CEngineClient::GetMixGroupIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEngineClient::GetMixGroupIndex(CEngineClient *this, const char *szmixgroupname)
{
  return S_GetMixGroupIndex(pMixGroupName: szmixgroupname);
}

//------------------------------------------------------------------------------
// Address: 0x1006F5E0
// Name: public: virtual void CEngineClient::UpdateDAndELights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::UpdateDAndELights(CEngineClient *this)
{
  CL_UpdateDAndELights(bUpdateDecay: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006F5F0
// Name: public: virtual int CEngineClient::GetBugSubmissionCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetBugSubmissionCount(CEngineClient *this)
{
  if ( bugreporter != nullptr )
    return bugreporter->GetBugSubmissionCount(this: bugreporter);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006F610
// Name: public: virtual void CEngineClient::ClearBugSubmissionCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ClearBugSubmissionCount(CEngineClient *this)
{
  if ( bugreporter != nullptr )
    bugreporter->ClearBugSubmissionCount(this: bugreporter);
}

//------------------------------------------------------------------------------
// Address: 0x1006F630
// Name: public: virtual bool CEngineClient::DoesLevelContainWater(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineClient::DoesLevelContainWater(CEngineClient *this)
{
  return host_state.worldbrush->numleafwaterdata != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006F650
// Name: public: virtual void CEngineClient::SolidMoved(class IClientEntity __near *,class ICollideable __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SolidMoved(
        CEngineClient *this,
        IClientEntity *pSolidEnt,
        ICollideable *pSolidCollide,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  CL_SolidMoved(pTriggerEnt: pSolidEnt, pSolidCollide, pPrevAbsOrigin, accurateBboxTriggerChecks);
}

//------------------------------------------------------------------------------
// Address: 0x1006F690
// Name: public: virtual void CEngineClient::ComputeLeavesConnected(class Vector const __near &,int,int const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ComputeLeavesConnected(
        CEngineClient *this,
        const Vector *vecOrigin,
        int nCount,
        const int *pLeaves,
        bool *pIsConnected)
{
  CM_LeavesConnected(vecOrigin, nCount, pLeaves, pIsConnected);
}

//------------------------------------------------------------------------------
// Address: 0x1006F6B0
// Name: public: virtual void CEngineClient::SetBlurFade(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SetBlurFade(CEngineClient *this, float scale)
{
  ((void (__stdcall *)(_DWORD))g_ClientDLL->SetBlurFade)(a1: LODWORD(scale));
}

//------------------------------------------------------------------------------
// Address: 0x1006F6D0
// Name: public: virtual bool CEngineClient::IsTransitioningToLoad(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineClient::IsTransitioningToLoad(CEngineClient *this)
{
  return HostState_IsTransitioningToLoad();
}

//------------------------------------------------------------------------------
// Address: 0x1006F760
// Name: public: virtual void CEngineClient::SubmitStatRecord(char const __near *,unsigned int,unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::SubmitStatRecord(
        CEngineClient *this,
        const char *szMapName,
        unsigned int uiBlobVersion,
        unsigned int uiBlobSize,
        const void *pvBlob)
{
  AsyncUpload_QueueData(szMapName, uiBlobVersion, uiBlobSize, pvBlob);
}

//------------------------------------------------------------------------------
// Address: 0x1006F7C0
// Name: public: virtual float CEngineClient::GetPitchScale(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
double __thiscall CEngineClient::GetPitchScale(CEngineClient *this)
{
  return S_SoundGetPitchScale();
}

//------------------------------------------------------------------------------
// Address: 0x1006F7D0
// Name: public: virtual bool CEngineClient::LoadFilmmaker(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::LoadFilmmaker(CEngineClient *this)
{
  return toolframework->LoadFilmmaker(this: toolframework);
}

//------------------------------------------------------------------------------
// Address: 0x1006F7F0
// Name: public: virtual void CEngineClient::EnablePaintmapRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::EnablePaintmapRender(CEngineClient *this)
{
  ConVar *v1; // eax

  v1 = g_pCVar->FindVar_2(this: g_pCVar, a2: "mat_paint_enabled");
  if ( v1 != nullptr )
    v1->SetValue_4(this: &v1->IConVar, a2: "1");
}

//------------------------------------------------------------------------------
// Address: 0x1006F830
// Name: public: virtual void CEngineClient::TickProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::TickProgressBar(CEngineClient *this)
{
  IEngineVGuiInternal *v1; // eax

  v1 = EngineVGui();
  v1->UpdateProgressBar(this: v1, a2: PROGRESS_DEFAULT, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1006F850
// Name: public: virtual struct InputContextHandle_t__ __near * CEngineClient::GetInputContext(enum EngineInputContextId_t)
// Source: json
//------------------------------------------------------------------------------
InputContextHandle_t__ *__thiscall CEngineClient::GetInputContext(CEngineClient *this, EngineInputContextId_t id)
{
  IEngineVGuiInternal *v3; // eax

  if ( id == ENGINE_INPUT_CONTEXT_GAME )
    return GetGameInputContext();
  if ( id != ENGINE_INPUT_CONTEXT_GAMEUI )
    return nullptr;
  v3 = EngineVGui();
  return v3->GetGameUIInputContext(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1006F9F0
// Name: bool ClientDLL_Load(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ClientDLL_Load()
{
  struct CSysModule *v0; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax

  v0 = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: "client.dll", a3: "GAMEBIN", a4: 0);
  g_ClientDLLModule = v0;
  if ( v0 != nullptr )
  {
    Factory = Sys_GetFactory(pModule: v0);
    g_ClientFactory = Factory;
    if ( Factory != nullptr )
    {
      g_ClientDLL = (IBaseClientDLL *)Factory(a1: "VClient016", a2: nullptr);
      g_bClientGameDLLGreaterThanV13 = true;
      if ( g_ClientDLL == nullptr )
        Sys_Error(error: "Could not get client.dll interface from library client");
    }
    else
    {
      Sys_Error(error: "Could not find factory interface in library client");
    }
  }
  else
  {
    Sys_Error(error: "Could not load library client");
  }
  g_pClientRenderTargets = (IClientRenderTargets *)g_ClientFactory(a1: "ClientRenderTargets001", a2: nullptr);
  return g_pClientRenderTargets != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006FB60
// Name: void ClientDLL_Connect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Connect()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->Connect(this: g_ClientDLL, a2: g_AppSystemFactory, a3: &g_ClientGlobalVariables);
}

//------------------------------------------------------------------------------
// Address: 0x1006FB80
// Name: void ClientDLL_Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Disconnect()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->Disconnect(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x1006FBA0
// Name: void ClientDLL_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Init()
{
  IPrediction *v0; // eax
  const char *ModDirectory; // eax
  vgui::ILocalize_vtbl *v2; // esi
  int v3; // eax
  vgui::ILocalize_vtbl *v4; // esi
  int v5; // eax
  int v6; // [esp-8h] [ebp-60Ch]
  int v7; // [esp-8h] [ebp-60Ch]
  wchar_t wcMessage[512]; // [esp+4h] [ebp-600h] BYREF
  char pMessage[512]; // [esp+404h] [ebp-200h] BYREF

  CL_SetSteamCrashComment();
  if ( g_ClientDLL != nullptr )
  {
    _COM_TimestampedLog(a1: "g_ClientDLL->Init");
    if ( g_ClientDLL->Init(this: g_ClientDLL, a2: g_GameSystemFactory, a3: &g_ClientGlobalVariables) == 0 )
      Sys_Error(error: "Client.dll Init() in library client failed.");
    if ( g_ClientFactory != nullptr )
    {
      _COM_TimestampedLog(a1: "g_pClientSidePrediction->Init");
      v0 = (IPrediction *)g_ClientFactory(a1: "VClientPrediction001", a2: nullptr);
      g_pClientSidePrediction = v0;
      if ( v0 == nullptr )
      {
        Sys_Error(error: "Could not get IPrediction interface from library client");
        v0 = g_pClientSidePrediction;
      }
      v0->Init(this: v0);
      entitylist = (IClientEntityList *)g_ClientFactory(a1: "VClientEntityList003", a2: nullptr);
      if ( entitylist == nullptr )
        Sys_Error(error: "Could not get client entity list interface from library client");
      clientleafsystem = (IClientLeafSystemEngine *)g_ClientFactory(a1: "ClientLeafSystem002", a2: nullptr);
      if ( clientleafsystem == nullptr )
        Sys_Error(error: "Could not get client leaf system interface from library client");
      g_pClientAlphaPropertyMgr = (IClientAlphaPropertyMgr *)g_ClientFactory(
                                                               a1: "ClientAlphaPropertyMgrV001",
                                                               a2: nullptr);
      if ( g_pClientAlphaPropertyMgr == nullptr )
        Sys_Error(error: "Could not get client alpha property mgr interface from library client");
      toolframework->ClientInit(this: toolframework, a2: g_ClientFactory);
    }
    if ( g_pMaterialSystemHardwareConfig != nullptr )
    {
      if ( g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 90 )
      {
        if ( g_pMaterialSystemHardwareConfig->IsUnsupported(this: g_pMaterialSystemHardwareConfig) )
        {
          v4 = g_pVGuiLocalize->__vftable;
          v5 = ((int (__thiscall *)(vgui::ILocalize *, const char *, _DWORD))g_pVGuiLocalize->Find)(
                 a1: g_pVGuiLocalize,
                 a2: "#Valve_UnsupportedCard",
                 a3: 0);
          ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v4->ConstructString_3)(
            a1: g_pVGuiLocalize,
            a2: wcMessage,
            a3: 1024,
            a4: v5);
          ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
            a1: g_pVGuiLocalize,
            a2: wcMessage,
            a3: pMessage,
            a4: 512,
            a5: v7);
          Sys_MessageBox(title: pMessage, info: nullptr, bShowOkAndCancel: false);
        }
      }
      else
      {
        ModDirectory = COM_GetModDirectory();
        if ( _V_stricmp(s1: ModDirectory, s2: "left4dead") == 0 )
        {
          v2 = g_pVGuiLocalize->__vftable;
          v3 = ((int (__thiscall *)(vgui::ILocalize *, const char *, _DWORD))g_pVGuiLocalize->Find)(
                 a1: g_pVGuiLocalize,
                 a2: "#Valve_MinShaderModel2",
                 a3: 0);
          ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v2->ConstructString_3)(
            a1: g_pVGuiLocalize,
            a2: wcMessage,
            a3: 1024,
            a4: v3);
          ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
            a1: g_pVGuiLocalize,
            a2: wcMessage,
            a3: pMessage,
            a4: 512,
            a5: v6);
          Sys_Error(error: pMessage);
        }
      }
    }
  }
  _COM_TimestampedLog(a1: "ClientDLL_InitRecvTableMgr");
  ClientDLL_InitRecvTableMgr();
  InitExtraClientCmdCanExecuteVars();
}

//------------------------------------------------------------------------------
// Address: 0x1006FDF0
// Name: void ClientDLL_Unload(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Unload()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->Disconnect(this: g_ClientDLL);
  FileSystem_UnloadModule(pModule: g_ClientDLLModule);
  g_ClientDLL = nullptr;
  g_ClientDLLModule = nullptr;
  g_pClientRenderTargets = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006FE30
// Name: void ClientDLL_HudVidInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_HudVidInit()
{
  g_ClientDLL->HudVidInit(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x1006FE40
// Name: void ClientDLL_FrameStageNotify(enum ClientFrameStage_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_FrameStageNotify(ClientFrameStage_t frameStage)
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->FrameStageNotify(this: g_ClientDLL, a2: frameStage);
}

//------------------------------------------------------------------------------
// Address: 0x1006FE60
// Name: void ClientDLL_Update(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Update()
{
  if ( !sv.m_bIsDedicated && g_ClientDLL != nullptr )
    g_ClientDLL->HudUpdate(this: g_ClientDLL, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1006FEB0
// Name: bool ClientDLL_IsPlayerAudible(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ClientDLL_IsPlayerAudible(int iPlayerIndex)
{
  return g_ClientDLL != nullptr && g_ClientDLL->PlayerAudible(this: g_ClientDLL, a2: iPlayerIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1006FEE0
// Name: void ClientDLL_OnSplitScreenStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_OnSplitScreenStateChanged()
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->OnSplitScreenStateChanged(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x1006FF00
// Name: int ClientDLL_GetSpectatorTarget(enum ClientDLLObserverMode_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientDLL_GetSpectatorTarget(ClientDLLObserverMode_t *pObserverMode)
{
  if ( pObserverMode != nullptr )
    *pObserverMode = CLIENT_DLL_OBSERVER_NONE;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1006FF20
// Name: unsigned int ClientDLL_GetFullscreenClientDLLVPanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ClientDLL_GetFullscreenClientDLLVPanel()
{
  if ( g_ClientDLL != nullptr )
    return g_ClientDLL->GetFullscreenClientDLLVPanel(this: g_ClientDLL);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006FF40
// Name: void AddIntersectingLeafSurfaces(struct mleaf_t __near *,class GetIntersectingSurfaces_Struct __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddIntersectingLeafSurfaces(mleaf_t *pLeaf, GetIntersectingSurfaces_Struct *pStruct)
{
  int v2; // eax
  msurface2_t *v3; // edx
  bool v4; // zf
  int m_nSetInfos; // eax
  int v6; // edi
  void **p_m_pEngineData; // ecx
  float y; // xmm3_4
  SurfInfo *v9; // eax
  __int128 v10; // xmm1
  int v11; // edi
  __int128 v12; // xmm6
  __int128 v13; // xmm5
  __int128 v14; // xmm7
  float v15; // xmm4_4
  float *v16; // ecx
  float *p_x; // edx
  unsigned int m_nVerts; // ecx
  __int128 z_low; // xmm2
  Vector *v20; // edx
  __int128 x_low; // xmm0
  __int128 v22; // xmm0
  __int128 v23; // xmm2
  unsigned int v24; // ecx
  float m_Radius; // xmm1_4
  const Vector *m_pCenter; // edi
  int v27; // ecx
  float *v28; // edx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  int nummarksurfaces; // ecx
  Vector vMax; // [esp+0h] [ebp-2Ch] BYREF
  Vector vMin; // [esp+Ch] [ebp-20h] BYREF
  char *v35; // [esp+18h] [ebp-14h]
  char *v36; // [esp+1Ch] [ebp-10h]
  msurface2_t **pHandle; // [esp+20h] [ebp-Ch]
  int iSurf; // [esp+24h] [ebp-8h]
  int iDim; // [esp+28h] [ebp-4h]

  pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
  v2 = 0;
  iSurf = 0;
  if ( pLeaf->nummarksurfaces != 0 )
  {
    do
    {
      v3 = pHandle[v2];
      v4 = (v3->flags & 4) == 0;
      iDim = (int)v3;
      if ( v4 )
      {
        m_nSetInfos = pStruct->m_nSetInfos;
        v6 = 0;
        if ( m_nSetInfos <= 0 )
        {
LABEL_7:
          if ( m_nSetInfos >= pStruct->m_nMaxInfos )
            return;
          y = 1000000.0;
          v9 = &pStruct->m_pInfos[m_nSetInfos];
          v10 = 0xC9742400;
          v11 = 0;
          v9->m_nVerts = 0;
          v9->m_pEngineData = v3;
          v4 = HIBYTE(v3->flags) == 0;
          v12 = 0x49742400u;
          v13 = 0x49742400u;
          v14 = 0xC9742400;
          v15 = -1000000.0;
          vMin.x = 1000000.0;
          vMin.y = 1000000.0;
          vMin.z = 1000000.0;
          vMax.x = -1000000.0;
          vMax.y = -1000000.0;
          vMax.z = -1000000.0;
          if ( !v4 )
          {
            do
            {
              v16 = (float *)(*(_DWORD *)(pStruct->m_pModel->sprite.numframes + 36)
                            + 12
                            * *(unsigned __int16 *)(*(_DWORD *)(pStruct->m_pModel->sprite.numframes + 148)
                                                  + 2 * (v11 + v3->firstvertindex)));
              p_x = &v9->m_Verts[v9->m_nVerts].x;
              *p_x = *v16;
              p_x[1] = v16[1];
              p_x[2] = v16[2];
              m_nVerts = v9->m_nVerts;
              z_low = LODWORD(v9->m_Verts[m_nVerts].z);
              v20 = &v9->m_Verts[m_nVerts];
              if ( *(float *)&z_low > *(float *)&v13 )
                z_low = v13;
              if ( v20->y <= y )
                y = v20->y;
              x_low = LODWORD(v20->x);
              if ( *(float *)&x_low > *(float *)&v12 )
                x_low = v12;
              v12 = x_low;
              v22 = LODWORD(v20->z);
              v13 = z_low;
              if ( *(float *)&v10 > *(float *)&v22 )
                v22 = v10;
              if ( v15 <= v20->y )
                v15 = v20->y;
              v23 = LODWORD(v20->x);
              if ( *(float *)&v14 > *(float *)&v23 )
                v23 = v14;
              v3 = (msurface2_t *)iDim;
              v24 = m_nVerts + 1;
              v14 = v23;
              v10 = v22;
              v9->m_nVerts = v24;
              if ( v24 >= 0x10 )
                break;
              ++v11;
            }
            while ( v11 < HIBYTE(v3->flags) );
            LODWORD(vMin.x) = v12;
            vMin.y = y;
            LODWORD(vMin.z) = v13;
            LODWORD(vMax.x) = v23;
            vMax.y = v15;
            LODWORD(vMax.z) = v22;
          }
          m_Radius = pStruct->m_Radius;
          m_pCenter = pStruct->m_pCenter;
          iDim = 0;
          v35 = (char *)((char *)&vMax - (char *)m_pCenter);
          v27 = 0;
          v36 = (char *)((char *)&vMin - (char *)m_pCenter);
          do
          {
            if ( *(float *)((char *)&m_pCenter->x + (_DWORD)v36) > (float)(m_pCenter->x + m_Radius) )
              break;
            if ( (float)(m_pCenter->x - m_Radius) > *(float *)((char *)&m_pCenter->x + (_DWORD)v35) )
              break;
            ++v27;
            m_pCenter = (const Vector *)((char *)m_pCenter + 4);
          }
          while ( v27 < 3 );
          if ( v27 == 3 )
          {
            v28 = &v3->plane->normal.x;
            v29 = v28[1];
            v30 = v28[2];
            v31 = v28[3];
            v9->m_Plane.m_Normal.x = *v28;
            v9->m_Plane.m_Normal.y = v29;
            v9->m_Plane.m_Normal.z = v30;
            v9->m_Plane.m_Dist = v31;
            ++pStruct->m_nSetInfos;
          }
        }
        else
        {
          p_m_pEngineData = &pStruct->m_pInfos->m_pEngineData;
          while ( *p_m_pEngineData != v3 )
          {
            ++v6;
            p_m_pEngineData += 54;
            if ( v6 >= m_nSetInfos )
              goto LABEL_7;
          }
        }
      }
      nummarksurfaces = pLeaf->nummarksurfaces;
      v2 = iSurf + 1;
      iSurf = v2;
    }
    while ( v2 < nummarksurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100702F0
// Name: public: virtual int CEngineClient::GetIntersectingSurfaces(struct model_t const __near *,class Vector const __near &,float,bool,class SurfInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetIntersectingSurfaces(
        CEngineClient *this,
        model_t *model,
        const Vector *vCenter,
        float radius,
        bool bOnlyVisible,
        SurfInfo *pInfos,
        int nMaxInfos)
{
  int v8; // eax
  int v9; // eax
  const unsigned __int8 *v10; // eax
  int firstnode; // ecx
  worldbrushdata_t *pShared; // edx
  unsigned __int8 dest[8192]; // [esp+4h] [ebp-2020h] BYREF
  GetIntersectingSurfaces_Struct pStruct; // [esp+2004h] [ebp-20h] BYREF

  if ( model == nullptr )
    return 0;
  pStruct.m_pModel = model;
  pStruct.m_pCenter = vCenter;
  v8 = CM_PointLeafnum(p: vCenter);
  v9 = CM_LeafCluster(leafnum: v8);
  v10 = CM_Vis(dest, destlen: 0x2000, cluster: v9, visType: 0);
  pStruct.m_bOnlyVisible = bOnlyVisible;
  firstnode = model->brush.firstnode;
  pStruct.m_pCenterPVS = v10;
  pStruct.m_pInfos = pInfos;
  pShared = model->brush.pShared;
  pStruct.m_nMaxInfos = nMaxInfos;
  pStruct.m_Radius = radius;
  pStruct.m_nSetInfos = 0;
  GetIntersectingSurfaces_R(&pStruct, pNode: &pShared->nodes[firstnode]);
  return pStruct.m_nSetInfos;
}

//------------------------------------------------------------------------------
// Address: 0x10070390
// Name: public: virtual void CEngineClient::ClientCmd_Unrestricted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::ClientCmd_Unrestricted(CEngineClient *this, vgui::CTreeViewListControl *szCmdString)
{
  int m_nValue; // eax
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t v5; // eax

  if ( in_forceuser.m_pParent != nullptr )
    m_nValue = in_forceuser.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: m_nValue);
  TraceType = CTraceFilter::GetTraceType(this: szCmdString);
  Cbuf_AddText(eTarget: TraceType, pText: (const char *)szCmdString, nTickDelay: 0);
  v5 = CTraceFilter::GetTraceType(this: v4);
  Cbuf_AddText(eTarget: v5, pText: "\n", nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100703E0
// Name: public: virtual int CEngineClient::GetServerTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetServerTick(CEngineClient *this)
{
  return GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick;
}

//------------------------------------------------------------------------------
// Address: 0x10070410
// Name: public: virtual char const __near * CEngineClient::GetLevelName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEngineClient::GetLevelName(CEngineClient *this)
{
  if ( sv.m_bIsDedicated )
    return "Dedicated Server";
  if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    return GetBaseLocalClient()->m_szLevelName;
  return (char *)defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10070440
// Name: public: virtual char const __near * CEngineClient::GetLevelNameShort(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEngineClient::GetLevelNameShort(CEngineClient *this)
{
  if ( sv.m_bIsDedicated )
    return "dedicated";
  if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    return GetBaseLocalClient()->m_szLevelNameShort;
  return (char *)defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10070470
// Name: public: virtual enum SkyboxVisibility_t CEngineClient::IsSkyboxVisibleFromPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::IsSkyboxVisibleFromPoint(CEngineClient *this, const Vector *vecPoint)
{
  unsigned int v3; // eax

  if ( g_pMaterialSystemConfig->nFullbright == 1 )
    return 1;
  v3 = *((__int16 *)&g_BSPData.map_leafs.m_pArray[CM_PointLeafnum(p: vecPoint)] + 3) >> 9;
  if ( (v3 & 1) != 0 )
    return 1;
  else
    return (v3 >> 1) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x100704B0
// Name: public: virtual void CEngineClient::OnStorageDeviceDetached(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::OnStorageDeviceDetached(CEngineClient *this, int iController)
{
  g_pXboxSystem->CloseContainers(this: g_pXboxSystem, a2: iController);
}

//------------------------------------------------------------------------------
// Address: 0x100704D0
// Name: void ClientDLL_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_Shutdown()
{
  toolframework->ClientShutdown(this: toolframework);
  RecvTable_Term(clearall: true);
  g_pVGui->RunFrame(this: g_pVGui);
  materials->UncacheAllMaterials(this: materials);
  g_pVGui->RunFrame(this: g_pVGui);
  if ( g_pClientSidePrediction != nullptr )
    g_pClientSidePrediction->Shutdown(this: g_pClientSidePrediction);
  entitylist = nullptr;
  g_pClientSidePrediction = nullptr;
  g_ClientFactory = nullptr;
  g_ClientDLL->Shutdown(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10070550
// Name: void ClientDLL_ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientDLL_ProcessInput()
{
  CClientState *LocalClient; // eax

  if ( g_ClientDLL != nullptr )
  {
    LocalClient = GetLocalClient(nSlot: -1);
    ((void (__stdcall *)(bool))g_ClientDLL->HudProcessInput)(a1: LocalClient->m_nSignonState >= 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070580
// Name: public: virtual bool CEngineClient::GetPlayerInfo(int,struct player_info_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineClient::GetPlayerInfo(CEngineClient *this, CByteswap ent_num, player_info_s *pinfo)
{
  int v3; // esi
  CClientState *BaseLocalClient; // eax
  const void *v5; // eax
  player_info_s *v6; // esi

  v3 = *(_DWORD *)&ent_num - 1;
  if ( v3 < GetBaseLocalClient()->m_nMaxClients
    && v3 >= 0
    && GetBaseLocalClient()->m_pUserInfoTable != nullptr
    && (BaseLocalClient = GetBaseLocalClient(),
        (v5 = BaseLocalClient->m_pUserInfoTable->GetStringUserData(
                this: BaseLocalClient->m_pUserInfoTable,
                a2: v3,
                a3: nullptr)) != nullptr) )
  {
    v6 = pinfo;
    _V_memcpy(dest: pinfo, src: v5, count: 144);
    ent_num = (CByteswap)(*(_DWORD *)&ent_num | 3);
    CByteswap::SwapFieldsToTargetEndian(
      this: &ent_num,
      pOutputBuffer: v6,
      pBaseData: v6,
      pDataMap: &player_info_s::m_DataMap);
    return 1;
  }
  else
  {
    _V_memset(dest: pinfo, fill: 0, count: 144);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070640
// Name: public: virtual void CEngineClient::RecordDemoCustomData(void (*)(unsigned char __near *,unsigned int),void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::RecordDemoCustomData(
        CEngineClient *this,
        void (__cdecl *pCallback)(unsigned __int8 *, unsigned int),
        const void *pData,
        unsigned int iDataLength)
{
  int v4; // esi
  int v5; // edx
  int v6; // eax
  void (__cdecl *v7)(unsigned __int8 *, unsigned int); // ecx

  if ( !demorecorder->IsRecording(this: demorecorder) )
    _Warning(a1: "IEngineClient::RecordDemoCustomData(): Not recording a demo.\n");
  v4 = 0;
  v5 = g_RegisteredDemoCustomDataCallbacks.m_Size - 1;
  if ( g_RegisteredDemoCustomDataCallbacks.m_Size - 1 < 0 )
  {
LABEL_9:
    _Warning(a1: "Demo recording custom data for unregistered callback.\n");
    return;
  }
  while ( 1 )
  {
    v6 = (v5 + v4) >> 1;
    v7 = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v6].pCallback;
    if ( (unsigned int)pCallback <= (unsigned int)v7 )
      break;
    v4 = v6 + 1;
LABEL_8:
    if ( v4 > v5 )
      goto LABEL_9;
  }
  if ( (unsigned int)pCallback < (unsigned int)v7 )
  {
    v5 = v6 - 1;
    goto LABEL_8;
  }
  demorecorder->RecordCustomData(this: demorecorder, a2: v6, a3: pData, a4: iDataLength);
}

//------------------------------------------------------------------------------
// Address: 0x100706D0
// Name: void DebugDrawPhysCollide(class CPhysCollide const __near *,class IMaterial __near *,struct matrix3x4_t const __near &,struct color32_s const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall DebugDrawPhysCollide(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const struct CPhysCollide *pCollide,
        IMaterial *pMaterial,
        const matrix3x4_t *transform,
        const color32_s *color,
        bool drawAxes)
{
  IMatRenderContext *m_pObject; // edi
  int v9; // esi
  IMesh *v10; // edi
  int v11; // esi
  int v12; // edi
  float *v13; // eax
  int m_nVertexCount; // eax
  float *v15; // eax
  float *m_pCurrPosition; // eax
  float *v17; // eax
  float *v18; // eax
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  float *v22; // eax
  float *v23; // eax
  int v24; // eax
  Vector *v25; // [esp-4h] [ebp-23Ch]
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-238h] BYREF
  Vector yaxis; // [esp+1E8h] [ebp-50h] BYREF
  Vector zaxis; // [esp+1F4h] [ebp-44h] BYREF
  Vector xaxis; // [esp+200h] [ebp-38h] BYREF
  IMesh *pMesh; // [esp+20Ch] [ebp-2Ch]
  Vector *outVerts; // [esp+210h] [ebp-28h] BYREF
  int i; // [esp+214h] [ebp-24h]
  float out; // [esp+218h] [ebp-20h] BYREF
  int v34; // [esp+21Ch] [ebp-1Ch]
  int v35; // [esp+220h] [ebp-18h]
  Vector center; // [esp+224h] [ebp-14h] BYREF
  int vertCount; // [esp+230h] [ebp-8h]
  CMatRenderContextPtr pRenderContext; // [esp+234h] [ebp-4h]
  IMesh *drawAxesa; // [esp+250h] [ebp+18h]

  if ( pMaterial == nullptr )
    pMaterial = materials->FindMaterial(
                  this: materials,
                  a2: "debug/debugwireframevertexcolor",
                  a3: "Other textures",
                  a4: 1,
                  a5: 0);
  m_pObject = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(
                                     a1: materials,
                                     a2);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v9 = ((int (__thiscall *)(IPhysicsCollision *, const struct CPhysCollide *, Vector **, int, int))physcollision->CreateDebugMesh)(
         a1: physcollision,
         a2: pCollide,
         a3: &outVerts,
         a4: a3,
         a5: a1);
  vertCount = v9;
  if ( v9 != 0 )
  {
    v10 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: pMaterial);
    pMesh = v10;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v10;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v11 = 3 * (v9 / 3);
    v10->SetPrimitiveType(this: v10, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v11, a3: v11, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v10->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v11;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(
      this: &meshBuilder.m_VertexBuilder,
      pMesh: v10,
      nMaxVertexCount: v11,
      desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    if ( vertCount > 0 )
    {
      v12 = 0;
      for ( i = vertCount; i != 0; --i )
      {
        VectorTransform(in1: &outVerts[v12].x, in2: transform, out: &center.x);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = center;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = color->b
                                                            | ((color->g | ((color->r | (color->a << 8)) << 8)) << 8);
        v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v13[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ++v12;
      }
      v10 = pMesh;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v10->Draw_2(this: v10, a2: -1, a3: 0);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    m_pObject = pRenderContext.m_pObject;
    v9 = vertCount;
  }
  v25 = outVerts;
  ((void (__thiscall *)(IPhysicsCollision *))physcollision->DestroyDebugMesh)(a1: physcollision);
  if ( drawAxes )
  {
    xaxis.x = 10.0;
    xaxis.y = 0.0;
    xaxis.z = 0.0;
    yaxis.x = 0.0;
    yaxis.y = 10.0;
    yaxis.z = 0.0;
    zaxis.x = 0.0;
    zaxis.y = 0.0;
    zaxis.z = 10.0;
    MatrixGetColumn(in: transform, column: 3, out: &center);
    drawAxesa = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, IMaterial *, int, Vector *))m_pObject->GetDynamicMesh)(
                           a1: m_pObject,
                           a2: 1,
                           a3: 0,
                           a4: 0,
                           a5: pMaterial,
                           a6: v9,
                           a7: v25);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = drawAxesa;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    drawAxesa->SetPrimitiveType(this: drawAxesa, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &drawAxesa->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = drawAxesa;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 6;
    meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
    meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_bModify = false;
    if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
    {
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
    }
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = center;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v15[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    VectorTransform(in1: &xaxis.x, in2: transform, &out);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = out;
    *((_DWORD *)m_pCurrPosition + 1) = v34;
    *((_DWORD *)m_pCurrPosition + 2) = v35;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v17[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = center;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v18[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    VectorTransform(in1: &yaxis.x, in2: transform, &out);
    v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = out;
    *((_DWORD *)v19 + 1) = v34;
    *((_DWORD *)v19 + 2) = v35;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v20[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = center;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v21[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    VectorTransform(in1: &zaxis.x, in2: transform, &out);
    v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = out;
    *((_DWORD *)v22 + 1) = v34;
    *((_DWORD *)v22 + 2) = v35;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v23[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v24 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v24 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v24 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v24 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v24 = 0;
          break;
        default:
          v24 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v24);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    drawAxesa->Draw_2(this: drawAxesa, a2: -1, a3: 0);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    m_pObject = pRenderContext.m_pObject;
  }
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070EA0
// Name: public: virtual void CEngineClient::GetScreenSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::GetScreenSize(CEngineClient *this, int *w, int *h)
{
  IMatRenderContext *v3; // esi

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v3->GetWindowSize(this: v3, a2: w, a3: h);
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10070EF0
// Name: public: virtual void CEngineClient::DebugDrawPhysCollide(class CPhysCollide const __near *,class IMaterial __near *,struct matrix3x4_t const __near &,struct color32_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineClient::DebugDrawPhysCollide(
        CEngineClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const struct CPhysCollide *pCollide,
        IMaterial *pMaterial,
        const matrix3x4_t *transform,
        const color32_s *color)
{
  DebugDrawPhysCollide(a1: a2, a2: a3, a3: a4, pCollide, pMaterial, transform, color, drawAxes: false);
}

//------------------------------------------------------------------------------
// Address: 0x10070F20
// Name: public: virtual void CEngineClient::RegisterDemoCustomDataCallback(struct string_t,void (*)(unsigned char __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::RegisterDemoCustomDataCallback(
        CEngineClient *this,
        string_t szCallbackSaveID,
        void (__cdecl *pCallback)(unsigned __int8 *, unsigned int))
{
  int v3; // esi
  int v4; // ecx
  int v5; // eax
  void (__cdecl *v6)(unsigned __int8 *, unsigned int); // edx
  RegisteredDemoCustomDataCallbackPair_t addPair; // [esp+0h] [ebp-8h] BYREF

  if ( demorecorder->IsRecording(this: demorecorder) )
    _Warning(a1: "Late registration of demo custom data callback.\n");
  v3 = 0;
  v4 = g_RegisteredDemoCustomDataCallbacks.m_Size - 1;
  if ( g_RegisteredDemoCustomDataCallbacks.m_Size - 1 < 0 )
  {
LABEL_9:
    addPair.pCallback = pCallback;
    addPair.szSaveID = szCallbackSaveID;
    CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
      this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_RegisteredDemoCustomDataCallbacks,
      elem: v3,
      src: (const vgui::PropertySheet::Page_t *)&addPair);
    return;
  }
  while ( 1 )
  {
    v5 = (v4 + v3) >> 1;
    v6 = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v5].pCallback;
    if ( (unsigned int)pCallback <= (unsigned int)v6 )
      break;
    v3 = v5 + 1;
LABEL_8:
    if ( v3 > v4 )
      goto LABEL_9;
  }
  if ( (unsigned int)pCallback < (unsigned int)v6 )
  {
    v4 = v5 - 1;
    goto LABEL_8;
  }
  _Warning(a1: "Double registration of demo custom data callback.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10132180
// Name: public: virtual float CEngineClient::SentenceLength(int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineClient::SentenceLength(CEngineClient *this, int sentenceIndex)
{
  return VOX_SentenceLength(sentence_num: sentenceIndex);
}

//------------------------------------------------------------------------------
// Address: 0x101325B0
// Name: public: virtual class IAchievementMgr __near * CEngineClient::GetAchievementMgr(void)
// Source: json
//------------------------------------------------------------------------------
IAchievementMgr *__thiscall CEngineClient::GetAchievementMgr(CEngineClient *this)
{
  return g_pAchievementMgr;
}

//------------------------------------------------------------------------------
// Address: 0x10132690
// Name: public: virtual bool CEngineClient::IsCreatingReslist(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineClient::IsCreatingReslist(CEngineClient *this)
{
  return MapReslistGenerator()->m_bLoggingEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x10132730
// Name: public: virtual void CEngineClient::RemoveAllPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::RemoveAllPaint(CEngineClient *this)
{
  CPaintmapDataManager::RemoveAllPaint(this: &g_PaintManager);
}

//------------------------------------------------------------------------------
// Address: 0x10132770
// Name: public: virtual void CEngineClient::RemovePaint(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineClient::RemovePaint(CEngineClient *this, const model_t *pModel)
{
  CPaintmapDataManager::RemovePaint(this: &g_PaintManager, pModel);
}

//------------------------------------------------------------------------------
// Address: 0x101FF780
// Name: public: virtual int CEngineClient::GetMaxClients(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineClient::GetMaxClients(CEngineClient *this)
{
  return GetBaseLocalClient()->m_nMaxClients;
}

} // namespace engine_xlsp
