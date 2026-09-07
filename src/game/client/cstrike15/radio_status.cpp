// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/radio_status.cpp
// Functions: 12
// ============================================================

#include "game\client\cstrike15\radio_status.h"

//------------------------------------------------------------------------------
// Address: 0x10204E30
// Name: class CRadioStatus __near * RadioManager(void)
// Source: json
//------------------------------------------------------------------------------
CRadioStatus *__cdecl RadioManager()
{
  return &s_RadioStatus;
}

//------------------------------------------------------------------------------
// Address: 0x10204E40
// Name: public: virtual void CRadioStatus::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRadioStatus::Shutdown(CRadioStatus *this)
{
  IMaterial *m_pHeadLabelMaterial; // ecx

  m_pHeadLabelMaterial = this->m_pHeadLabelMaterial;
  if ( m_pHeadLabelMaterial != nullptr )
    m_pHeadLabelMaterial->DecrementReferenceCount(this: m_pHeadLabelMaterial);
  this->m_pHeadLabelMaterial = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10204E60
// Name: public: void CRadioStatus::UpdateRadioStatus(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRadioStatus::UpdateRadioStatus(CRadioStatus *this, int entindex, float duration)
{
  if ( (unsigned int)(entindex - 1) <= 0x3F )
    *((float *)&this->m_pszName + entindex) = *(float *)(gpGlobals.m_Index + 12) + duration;
}

//------------------------------------------------------------------------------
// Address: 0x10204E90
// Name: public: void CRadioStatus::UpdateVoiceStatus(int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRadioStatus::UpdateVoiceStatus(
        CRadioStatus *this@<ecx>,
        _BYTE *a2@<ebx>,
        int entindex,
        float duration)
{
  unsigned int m_Index; // esi
  CVoiceStatus *ClientVoiceMgr; // eax

  if ( (unsigned int)(entindex - 1) <= 0x3F )
  {
    m_Index = gpGlobals.m_Index;
    this->m_radioUntil[entindex + 64] = *(float *)(gpGlobals.m_Index + 12) + duration;
    ClientVoiceMgr = GetClientVoiceMgr();
    CVoiceStatus::UpdateSpeakerStatus(this: ClientVoiceMgr, a2, a3: m_Index, entindex, iSsSlot: -1, bTalking: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204EE0
// Name: radio1_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl radio1_f()
{
  C_CSPlayer *LocalPlayer; // esi
  CHud *Hud; // eax
  CHudMenu *Element; // eax

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr
    && LocalPlayer->IsAlive(this: LocalPlayer)
    && LocalPlayer->GetObserverMode(this: LocalPlayer) == 0 )
  {
    Hud = GetHud(nSlot: -1);
    Element = (CHudMenu *)CHud::FindElement(this: Hud, pName: "CHudMenu");
    if ( Element != nullptr )
    {
      g_whichMenu = 1;
      CHudMenu::ShowMenu(this: Element, menuName: "#RadioA", validSlots: 575);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204F50
// Name: radio2_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl radio2_f()
{
  C_CSPlayer *LocalPlayer; // esi
  CHud *Hud; // eax
  CHudMenu *Element; // eax

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr
    && LocalPlayer->IsAlive(this: LocalPlayer)
    && LocalPlayer->GetObserverMode(this: LocalPlayer) == 0 )
  {
    Hud = GetHud(nSlot: -1);
    Element = (CHudMenu *)CHud::FindElement(this: Hud, pName: "CHudMenu");
    if ( Element != nullptr )
    {
      g_whichMenu = 2;
      CHudMenu::ShowMenu(this: Element, menuName: "#RadioB", validSlots: 575);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204FC0
// Name: radio3_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl radio3_f()
{
  C_CSPlayer *LocalPlayer; // esi
  CHud *Hud; // eax
  CHudMenu *Element; // eax

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr
    && LocalPlayer->IsAlive(this: LocalPlayer)
    && LocalPlayer->GetObserverMode(this: LocalPlayer) == 0 )
  {
    Hud = GetHud(nSlot: -1);
    Element = (CHudMenu *)CHud::FindElement(this: Hud, pName: "CHudMenu");
    if ( Element != nullptr )
    {
      g_whichMenu = 3;
      CHudMenu::ShowMenu(this: Element, menuName: "#RadioC", validSlots: 1023);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205030
// Name: menuselect
// Source: json
//------------------------------------------------------------------------------
void __cdecl menuselect(const CCommand *args)
{
  int m_nArgc; // eax
  bool v2; // cc
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  int v6; // eax
  const char *v7; // eax

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    if ( g_whichMenu != 0 )
    {
      v2 = m_nArgc <= 1;
      v5 = prType;
      if ( !v2 )
        v5 = args->m_ppArgv[1];
      v6 = atoi(nptr: v5);
      switch ( g_whichMenu )
      {
        case 1:
          switch ( v6 )
          {
            case 1:
              engine->ClientCmd(this: engine, a2: "coverme");
              break;
            case 2:
              engine->ClientCmd(this: engine, a2: "takepoint");
              break;
            case 3:
              engine->ClientCmd(this: engine, a2: "holdpos");
              break;
            case 4:
              engine->ClientCmd(this: engine, a2: "regroup");
              break;
            case 5:
              engine->ClientCmd(this: engine, a2: "followme");
              break;
            case 6:
              engine->ClientCmd(this: engine, a2: "takingfire");
              break;
            default:
              goto LABEL_36;
          }
          break;
        case 2:
          switch ( v6 )
          {
            case 1:
              engine->ClientCmd(this: engine, a2: "go");
              break;
            case 2:
              engine->ClientCmd(this: engine, a2: "fallback");
              break;
            case 3:
              engine->ClientCmd(this: engine, a2: "sticktog");
              break;
            case 4:
              engine->ClientCmd(this: engine, a2: "getinpos");
              break;
            case 5:
              engine->ClientCmd(this: engine, a2: "stormfront");
              break;
            case 6:
              engine->ClientCmd(this: engine, a2: "report");
              break;
            default:
              goto LABEL_36;
          }
          break;
        case 3:
          switch ( v6 )
          {
            case 1:
              engine->ClientCmd(this: engine, a2: "roger");
              break;
            case 2:
              engine->ClientCmd(this: engine, a2: "enemyspot");
              break;
            case 3:
              engine->ClientCmd(this: engine, a2: "needbackup");
              break;
            case 4:
              engine->ClientCmd(this: engine, a2: "sectorclear");
              break;
            case 5:
              engine->ClientCmd(this: engine, a2: "inposition");
              break;
            case 6:
              engine->ClientCmd(this: engine, a2: "reportingin");
              break;
            case 7:
              engine->ClientCmd(this: engine, a2: "getout");
              break;
            case 8:
              engine->ClientCmd(this: engine, a2: "negative");
              break;
            case 9:
              engine->ClientCmd(this: engine, a2: "enemydown");
              break;
            default:
              goto LABEL_36;
          }
          break;
        default:
          v7 = VarArgs(format: "menuselect %d", v6);
          engine->ServerCmd(this: engine, a2: v7, a3: true);
          g_whichMenu = 0;
          return;
      }
LABEL_36:
      g_whichMenu = 0;
    }
    else
    {
      v2 = m_nArgc <= 1;
      v3 = prType;
      if ( !v2 )
        v3 = args->m_ppArgv[1];
      v4 = VarArgs(format: "menuselect %s", v3);
      engine->ServerCmd(this: engine, a2: v4, a3: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205210
// Name: public: virtual bool CRadioStatus::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRadioStatus::Init(CRadioStatus *this)
{
  IMaterial *m_pHeadLabelMaterial; // ecx

  if ( this->m_pHeadLabelMaterial == nullptr )
    this->m_pHeadLabelMaterial = materials->FindMaterial(
                                   this: materials,
                                   a2: "sprites/radio",
                                   a3: "VGUI textures",
                                   a4: 1,
                                   a5: 0);
  m_pHeadLabelMaterial = this->m_pHeadLabelMaterial;
  if ( m_pHeadLabelMaterial == nullptr || m_pHeadLabelMaterial->IsErrorMaterial(this: m_pHeadLabelMaterial) )
    return 0;
  this->m_pHeadLabelMaterial->IncrementReferenceCount(this: this->m_pHeadLabelMaterial);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10205270
// Name: private: void CRadioStatus::ExpireBotVoice(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRadioStatus::ExpireBotVoice(CRadioStatus *this, bool force)
{
  int v2; // edi
  float *m_voiceUntil; // esi
  int i; // ebx
  CVoiceStatus *ClientVoiceMgr; // eax

  v2 = 1;
  m_voiceUntil = this->m_voiceUntil;
  for ( i = 64; i != 0; --i )
  {
    if ( *m_voiceUntil > 0.0
      && (CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v2) == nullptr
       || *(float *)(gpGlobals.m_Index + 12) > *m_voiceUntil
       || force) )
    {
      *m_voiceUntil = 0.0;
      ClientVoiceMgr = GetClientVoiceMgr();
      CVoiceStatus::UpdateSpeakerStatus(
        this: ClientVoiceMgr,
        a2: (_BYTE *)i,
        a3: (int)m_voiceUntil,
        entindex: v2,
        iSsSlot: -1,
        bTalking: false);
    }
    ++m_voiceUntil;
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102052F0
// Name: public: virtual void CRadioStatus::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRadioStatus::LevelShutdownPreEntity(CRadioStatus *this)
{
  CRadioStatus::ExpireBotVoice(this, force: true);
  _V_memset(dest: (int)this->m_radioUntil, fill: nullptr, count: 0x100u);
  _V_memset(dest: (int)this->m_voiceUntil, fill: nullptr, count: 0x100u);
}

//------------------------------------------------------------------------------
// Address: 0x10205330
// Name: public: void CRadioStatus::DrawHeadLabels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRadioStatus::DrawHeadLabels(CRadioStatus *this)
{
  int v2; // esi
  float *m_radioUntil; // edi
  int v4; // eax
  int v5; // eax
  C_BasePlayer *v6; // eax
  C_BasePlayer *v7; // ebx
  int v8; // edi
  int v9; // esi
  int v10; // eax
  float v11; // ecx
  CVoiceStatus *ClientVoiceMgr; // eax
  double HeadLabelOffset; // st7
  IMatRenderContext *m_pObject; // esi
  IMesh *v15; // esi
  float v16; // xmm0_4
  float *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm0_4
  float *m_pCurrPosition; // eax
  float v21; // xmm2_4
  float *v22; // eax
  float *v23; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float *v29; // eax
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float *v34; // eax
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float *v39; // eax
  float *v40; // eax
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-290h] BYREF
  float v45; // [esp+1ECh] [ebp-A8h]
  float v46; // [esp+1F0h] [ebp-A4h]
  float v47; // [esp+1F4h] [ebp-A0h]
  float v48; // [esp+1F8h] [ebp-9Ch]
  float v49; // [esp+1FCh] [ebp-98h]
  float v50; // [esp+200h] [ebp-94h]
  float v51; // [esp+204h] [ebp-90h]
  float v52; // [esp+208h] [ebp-8Ch]
  float v53; // [esp+20Ch] [ebp-88h]
  float v54; // [esp+210h] [ebp-84h]
  float v55; // [esp+214h] [ebp-80h]
  float v56; // [esp+218h] [ebp-7Ch]
  ConVarRef voice_head_icon_height; // [esp+21Ch] [ebp-78h] BYREF
  int v58; // [esp+224h] [ebp-70h]
  int v59; // [esp+228h] [ebp-6Ch]
  int v60; // [esp+22Ch] [ebp-68h]
  int v61; // [esp+230h] [ebp-64h]
  CRadioStatus *v62; // [esp+234h] [ebp-60h]
  int v63; // [esp+238h] [ebp-5Ch]
  float v64; // [esp+23Ch] [ebp-58h]
  int v65; // [esp+240h] [ebp-54h]
  int v66; // [esp+244h] [ebp-50h]
  float v67; // [esp+248h] [ebp-4Ch]
  float v68; // [esp+24Ch] [ebp-48h]
  int v69; // [esp+250h] [ebp-44h]
  float v70; // [esp+254h] [ebp-40h]
  int v71; // [esp+258h] [ebp-3Ch]
  int v72; // [esp+25Ch] [ebp-38h]
  int v73; // [esp+260h] [ebp-34h]
  int v74; // [esp+264h] [ebp-30h]
  float *v75; // [esp+268h] [ebp-2Ch]
  float v76; // [esp+26Ch] [ebp-28h]
  CMatRenderContextPtr pRenderContext; // [esp+270h] [ebp-24h] BYREF
  float flSize; // [esp+274h] [ebp-20h]
  int i; // [esp+278h] [ebp-1Ch]
  Vector vRight; // [esp+27Ch] [ebp-18h] BYREF
  Vector vOrigin; // [esp+288h] [ebp-Ch]

  v62 = this;
  CRadioStatus::ExpireBotVoice(this, force: false);
  ConVarRef::ConVarRef(this: &voice_head_icon_height, pName: "voice_head_icon_height");
  if ( this->m_pHeadLabelMaterial != nullptr )
  {
    v2 = 0;
    m_radioUntil = this->m_radioUntil;
    i = 0;
    v75 = m_radioUntil;
    do
    {
      if ( *(float *)(gpGlobals.m_Index + 12) <= *m_radioUntil )
      {
        v4 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 12))(
               a1: cl_entitylist.m_Index + 131092,
               a2: v2 + 1);
        if ( v4 != 0 )
        {
          v5 = v4 + 8;
          if ( v5 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 36))(a1: v5) == 0 )
          {
            v6 = UTIL_PlayerByIndex(entindex: v2 + 1);
            v7 = v6;
            if ( v6 != nullptr && !C_BasePlayer::IsPlayerDead(this: v6) )
            {
              v8 = 1 << (v2 & 0x1F);
              v9 = v2 >> 5;
              if ( (v8 & GetClientVoiceMgr()->m_AudiblePlayers.m_Ints[v9]) != 0 )
              {
                v10 = (int)v7->WorldSpaceCenter(this: v7);
                v11 = *(float *)(v10 + 8);
                *(_QWORD *)&vOrigin.x = *(_QWORD *)v10;
                vOrigin.z = v11;
                ClientVoiceMgr = GetClientVoiceMgr();
                HeadLabelOffset = CVoiceStatus::GetHeadLabelOffset(this: ClientVoiceMgr);
                vOrigin.z = HeadLabelOffset + s_flHeadOffset + vOrigin.z;
                if ( (v8 & GetClientVoiceMgr()->m_VoicePlayers.m_Ints[v9]) != 0 )
                  vOrigin.z = voice_head_icon_height.m_pConVarState->m_Value.m_fValue + vOrigin.z;
                vRight = *CurrentViewRight();
                if ( COERCE_FLOAT(LODWORD(vRight.z) & _mask__AbsFloat_) <= 0.95 )
                {
                  vRight.z = 0.0;
                  VectorNormalize(vec: &vRight);
                  flSize = s_flHeadIconSize;
                  CMatRenderContextPtr::CMatRenderContextPtr(this: &pRenderContext, pFrom: materials);
                  m_pObject = pRenderContext.m_pObject;
                  pRenderContext.m_pObject->Bind(
                    this: pRenderContext.m_pObject,
                    a2: v62->m_pHeadLabelMaterial,
                    a3: nullptr);
                  v15 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
                  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
                  CMeshBuilder::Begin(this: &meshBuilder, pMesh: v15, type: 7, numPrimitives: 1);
                  v59 = 1258291455;
                  v65 = 1258291455;
                  v58 = 1258291455;
                  v16 = flSize;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
                  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
                  v17[1] = 0.0;
                  v67 = v16;
                  v64 = v16 * 0.0;
                  LODWORD(v76) = LODWORD(v16) ^ _mask__NegFloat_;
                  v18 = (float)(vOrigin.y + (float)(COERCE_FLOAT(LODWORD(v16) ^ _mask__NegFloat_) * vRight.y))
                      + (float)(v16 * 0.0);
                  v51 = (float)(vOrigin.x + (float)(COERCE_FLOAT(LODWORD(v16) ^ _mask__NegFloat_) * vRight.x))
                      + (float)(v16 * 0.0);
                  v52 = v18;
                  v19 = (float)((float)(COERCE_FLOAT(LODWORD(v16) ^ _mask__NegFloat_) * vRight.z) + vOrigin.z) + v16;
                  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v51;
                  m_pCurrPosition[1] = v18;
                  v53 = v19;
                  m_pCurrPosition[2] = v19;
                  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                  v21 = flSize;
                  v69 = 1258291455;
                  v66 = 1258291455;
                  v71 = 1258291455;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
                  v22 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
                  v22[1] = 0.0;
                  v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                  v24 = (float)((float)(vRight.x * v21) + vOrigin.x) + v64;
                  v25 = (float)((float)(vRight.y * v21) + vOrigin.y) + v64;
                  v26 = (float)((float)(v21 * vRight.z) + vOrigin.z) + v67;
                  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
                  v23[1] = v25;
                  v45 = v24;
                  v46 = v25;
                  v47 = v26;
                  v23[2] = v26;
                  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                  v27 = v76;
                  v61 = 1258291455;
                  v28 = flSize;
                  v60 = 1258291455;
                  v74 = 1258291455;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
                  v29 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
                  v29[1] = 1.0;
                  v70 = v27 * 0.0;
                  v30 = v27 * 0.0;
                  v68 = v27;
                  v31 = v27;
                  v32 = (float)(vRight.x * v28) + vOrigin.x;
                  v33 = vRight.y * v28;
                  v34 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                  v35 = (float)(v28 * vRight.z) + vOrigin.z;
                  v36 = v32 + v30;
                  v37 = (float)(v33 + vOrigin.y) + v30;
                  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v36;
                  v34[1] = v37;
                  v54 = v36;
                  v55 = v37;
                  v56 = v35 + v31;
                  v34[2] = v35 + v31;
                  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                  v38 = v76;
                  v72 = 1258291455;
                  v73 = 1258291455;
                  v63 = 1258291455;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
                  v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
                  v39[1] = 1.0;
                  v40 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                  v41 = (float)((float)(v38 * vRight.x) + vOrigin.x) + v70;
                  v42 = (float)((float)(v38 * vRight.y) + vOrigin.y) + v70;
                  v43 = (float)((float)(v38 * vRight.z) + vOrigin.z) + v68;
                  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v41;
                  v40[1] = v42;
                  v48 = v41;
                  v49 = v42;
                  v50 = v43;
                  v40[2] = v43;
                  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                  CMeshBuilder::End(this: &meshBuilder, bSpewData: false, bDraw: false);
                  v15->Draw_2(this: v15, a2: -1, a3: 0);
                  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
                  CMatRenderContextPtr::~CMatRenderContextPtr(this: &pRenderContext);
                }
              }
              v2 = i;
            }
          }
        }
      }
      ++v2;
      m_radioUntil = v75 + 1;
      i = v2;
      ++v75;
    }
    while ( v2 < 64 );
  }
}
