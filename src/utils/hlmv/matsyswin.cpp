// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/matsyswin.cpp
// Functions: 18
// ============================================================

#include "utils\hlmv\matsyswin.h"

//------------------------------------------------------------------------------
// Address: 0x00415340
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415400
// Name: public: CSoundParameters::CSoundParameters(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParameters *__thiscall CSoundParameters::CSoundParameters(CSoundParameters *this)
{
  this->pitch = 100;
  this->pitchlow = 100;
  this->pitchhigh = 100;
  this->channel = 0;
  this->volume = 1.0;
  this->soundlevel = SNDLVL_NORM;
  this->soundname[0] = 0;
  this->play_to_owner_only = false;
  this->count = 0;
  this->delay_msec = 0;
  this->m_nSoundEntryVersion = 1;
  this->m_hSoundScriptHandle = -1;
  this->m_pOperatorsKV = nullptr;
  this->m_nRandomSeed = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415460
// Name: char __near * PSkipSoundChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PSkipSoundChars(char *pch)
{
  char *result; // eax
  char v2; // cl

  for ( result = pch; ; ++result )
  {
    v2 = *result;
    if ( *result != 42
      && v2 != 63
      && v2 != 33
      && v2 != 35
      && v2 != 64
      && v2 != 40
      && v2 != 62
      && v2 != 60
      && v2 != 94
      && v2 != 41
      && v2 != 125
      && v2 != 36 )
    {
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004154B0
// Name: void UpdateSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateSounds()
{
  double v0; // xmm0_8
  float v1; // [esp+0h] [ebp-Ch]

  v0 = (double)(int)mx::getTickCount() * 0.001;
  if ( prev != 0.0 )
  {
    v1 = (v0 - prev) * g_viewerSettings.speedScale;
    ((void (__stdcall *)(_DWORD))g_pSoundSystem->Update)(a1: LODWORD(v1));
  }
  prev = v0;
}

//------------------------------------------------------------------------------
// Address: 0x00415520
// Name: ReleaseMaterialSystemObjects
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ReleaseMaterialSystemObjects()
{
  StudioModel::ReleaseStudioModel();
}

//------------------------------------------------------------------------------
// Address: 0x00415530
// Name: RestoreMaterialSystemObjects
// Source: json
//------------------------------------------------------------------------------
void __cdecl RestoreMaterialSystemObjects()
{
  StudioModel::RestoreStudioModel();
  ControlPanel::OnLoadModel(this: g_ControlPanel);
}

//------------------------------------------------------------------------------
// Address: 0x00415540
// Name: void InitMaterialSystemConfig(struct MaterialSystem_Config_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitMaterialSystemConfig()
{
  ConVar::SetValue(this: (ConVar *)&mat_bumpmap.IConVar, value: g_viewerSettings.enableNormalMapping);
  ConVar::SetValue(this: (ConVar *)&mat_displacementmap.IConVar, value: g_viewerSettings.enableDisplacementMapping);
  ConVar::SetValue(this: (ConVar *)&mat_specular.IConVar, value: g_viewerSettings.enableSpecular);
  ConVar::SetValue(this: (ConVar *)&mat_parallaxmap.IConVar, value: g_viewerSettings.enableParallaxMapping);
}

//------------------------------------------------------------------------------
// Address: 0x00415590
// Name: char const __near * HLMV_TranslateSoundName(char const __near *,class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl HLMV_TranslateSoundName(char *soundname, StudioModel *model)
{
  ISoundEmitterSystemBase_vtbl *v3; // edx
  char *v4; // eax

  if ( V_stristr(pStr: soundname, pSearch: ".wav") != nullptr )
    return PSkipSoundChars(pch: soundname);
  v3 = g_pSoundEmitterBase->__vftable;
  if ( model != nullptr )
    v4 = (char *)((int (__stdcall *)(char *, char *))v3->GetWavFileForSound_2)(a1: soundname, a2: model->m_pModelName);
  else
    v4 = (char *)((int (__stdcall *)(char *, _DWORD))v3->GetWavFileForSound_2)(a1: soundname, a2: 0);
  return PSkipSoundChars(pch: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00415600
// Name: void PlaySoundA(char const __near *,class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PlaySoundA(char *pSoundName, StudioModel *pStudioModel)
{
  char *v2; // eax
  gender_t v3; // ebx
  float v4; // xmm0_4
  char filename[256]; // [esp+1Ch] [ebp-1BCh] BYREF
  CSoundParameters params; // [esp+11Ch] [ebp-BCh] BYREF
  float volume; // [esp+1D0h] [ebp-8h]
  struct CAudioSource *pAudioSource; // [esp+1D4h] [ebp-4h]

  if ( g_viewerSettings.playSounds && pSoundName != nullptr && *pSoundName != 0 )
  {
    v2 = HLMV_TranslateSoundName(soundname: pSoundName, model: pStudioModel);
    sprintf(string: filename, format: "sound/%s", v2);
    pAudioSource = g_pSoundSystem->FindOrAddSound(this: g_pSoundSystem, a2: filename);
    if ( pAudioSource != nullptr )
    {
      v3 = GENDER_NONE;
      volume = 1.0;
      if ( pStudioModel != nullptr )
        v3 = g_pSoundEmitterBase->GetActorGender(this: g_pSoundEmitterBase, a2: pStudioModel->m_pModelName);
      CSoundParameters::CSoundParameters(this: &params);
      if ( V_stristr(pStr: pSoundName, pSearch: ".wav") != nullptr
        || !g_pSoundEmitterBase->GetParametersForSound(
              this: g_pSoundEmitterBase,
              a2: pSoundName,
              a3: &params,
              a4: v3,
              a5: false) )
      {
        v4 = volume;
      }
      else
      {
        v4 = params.volume;
      }
      ((void (__stdcall *)(struct CAudioSource *, _DWORD, _DWORD))g_pSoundSystem->PlaySoundA)(
        a1: pAudioSource,
        a2: LODWORD(v4),
        a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415700
// Name: void PlaySounds(class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PlaySounds(StudioModel *pStudioModel)
{
  int FrameSelection; // eax
  double Duration; // st7
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v5; // eax
  int Sequence; // eax
  const studiohdr_t *v7; // esi
  mstudioseqdesc_t *v8; // ebx
  int v9; // esi
  int v10; // esi
  int v11; // eax
  const char *v12; // esi
  char soundname[256]; // [esp+4h] [ebp-10Ch] BYREF
  float currcycle; // [esp+104h] [ebp-Ch]
  float prevcycle; // [esp+108h] [ebp-8h]
  float v16; // [esp+10Ch] [ebp-4h]
  float ia; // [esp+118h] [ebp+8h]
  int i; // [esp+118h] [ebp+8h]

  if ( pStudioModel != nullptr )
  {
    FrameSelection = ControlPanel::getFrameSelection(this: g_ControlPanel);
    ia = StudioModel::GetFrame(this: pStudioModel, iLayer: FrameSelection) * 0.033333335;
    prevcycle = pStudioModel->m_dt;
    Duration = StudioModel::GetDuration(this: pStudioModel);
    currcycle = Duration;
    v16 = 1.0 / Duration;
    prevcycle = fmod(ia - prevcycle, Duration) * v16;
    m_pStudioHdr = pStudioModel->m_pStudioHdr;
    currcycle = fmod(ia, currcycle) * v16;
    if ( m_pStudioHdr != nullptr )
    {
      if ( m_pStudioHdr->m_pStudioHdr != nullptr
        || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: pStudioModel->m_MDLHandle),
            CStudioHdr::Init(this: pStudioModel->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
            (m_pStudioHdr = pStudioModel->m_pStudioHdr)->m_pStudioHdr != nullptr) )
      {
        if ( m_pStudioHdr != nullptr )
        {
          Sequence = StudioModel::GetSequence(this: pStudioModel);
          if ( m_pStudioHdr->m_pVModel != nullptr )
          {
            v8 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: Sequence);
          }
          else
          {
            v7 = m_pStudioHdr->m_pStudioHdr;
            if ( Sequence < 0 || Sequence >= v7->numlocalseq )
              Sequence = 0;
            v8 = (mstudioseqdesc_t *)((char *)v7 + 212 * Sequence + v7->localseqindex);
          }
          v9 = 0;
          i = 0;
          if ( v8->numevents > 0 )
          {
            v16 = 0.0;
            while ( 1 )
            {
              v10 = (int)v8 + v9 + v8->eventindex;
              if ( prevcycle < *(float *)v10 && *(float *)v10 <= currcycle )
              {
                v11 = *(_DWORD *)(v10 + 4);
                if ( v11 > 1008 )
                  break;
                switch ( v11 )
                {
                  case 1008:
                    goto LABEL_20;
                  case 0:
                    if ( _V_strcmp(s1: (const char *)(v10 + *(_DWORD *)(v10 + 76)), s2: "AE_CL_PLAYSOUND") != 0 )
                      break;
                    goto LABEL_20;
                  case 1004:
                    goto LABEL_20;
                  default:
                    break;
                }
              }
LABEL_21:
              v9 = LODWORD(v16) + 80;
              ++i;
              LODWORD(v16) += 80;
              if ( i >= v8->numevents )
                return;
            }
            if ( v11 != 5004 )
            {
              if ( (unsigned int)(v11 - 6004) <= 1 )
              {
                v12 = (const char *)(v10 + 12);
                if ( v12 == nullptr || *v12 == 0 )
                  v12 = "NPC_CombineS";
                V_snprintf(pDest: soundname, maxLen: 256, pFormat: "%s.RunFootstepLeft", v12);
                PlaySoundA(pSoundName: soundname, pStudioModel);
                V_snprintf(pDest: soundname, maxLen: 256, pFormat: "%s.RunFootstepRight", v12);
                PlaySoundA(pSoundName: soundname, pStudioModel);
                V_snprintf(pDest: soundname, maxLen: 256, pFormat: "%s.FootstepLeft", v12);
                PlaySoundA(pSoundName: soundname, pStudioModel);
                V_snprintf(pDest: soundname, maxLen: 256, pFormat: "%s.FootstepRight", v12);
                PlaySoundA(pSoundName: soundname, pStudioModel);
              }
              goto LABEL_21;
            }
LABEL_20:
            PlaySoundA(pSoundName: (char *)(v10 + 12), pStudioModel);
            goto LABEL_21;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415930
// Name: public: void MatSysWindow::dumpViewport(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::dumpViewport(MatSysWindow *this, const char *filename)
{
  int v3; // esi
  mxImage *v4; // eax
  mxImage *v5; // edi
  void *v6; // eax
  HWND Handle; // eax
  HDC DC; // eax
  _BYTE *data; // ebx
  int v10; // esi
  int i; // edi
  COLORREF Pixel; // eax
  HWND v13; // eax
  HDC__ *hdc; // [esp+10h] [ebp-14h]
  int h; // [esp+14h] [ebp-10h]
  mxImage *image; // [esp+18h] [ebp-Ch]
  int y; // [esp+1Ch] [ebp-8h]
  int w; // [esp+20h] [ebp-4h]

  ((void (__fastcall *)(MatSysWindow *))this->redraw)(a1: this);
  w = mxWidget::w2(this);
  v3 = mxWidget::h2(this);
  h = v3;
  v4 = (mxImage *)operator new(nSize: 0x18u);
  if ( v4 != nullptr )
  {
    v5 = v4;
    v4->__vftable = (mxImage_vtbl *)&mxImage::`vftable';
    v4->width = 0;
    v4->height = 0;
    v4->bpp = 0;
    v4->data = nullptr;
    v4->palette = nullptr;
    image = v4;
  }
  else
  {
    image = nullptr;
    v5 = nullptr;
  }
  if ( v5->data != nullptr )
    free(pMem: v5->data);
  if ( v5->palette != nullptr )
    free(pMem: v5->palette);
  v6 = operator new(nSize: 24 * w * v3 / 8);
  v5->data = v6;
  if ( v6 != nullptr )
  {
    v5->palette = nullptr;
    v5->width = w;
    v5->height = v3;
    v5->bpp = 24;
    Handle = (HWND)mxWidget::getHandle(this);
    DC = GetDC(hWnd: Handle);
    data = v5->data;
    v10 = 0;
    hdc = DC;
    y = 0;
    if ( h > 0 )
    {
      do
      {
        for ( i = 0; i < w; v10 += 3 )
        {
          Pixel = GetPixel(hdc, x: i, y);
          *(_WORD *)&data[v10] = Pixel;
          data[v10 + 2] = BYTE2(Pixel);
          ++i;
        }
        ++y;
      }
      while ( y < h );
      v5 = image;
    }
    v13 = (HWND)mxWidget::getHandle(this);
    ReleaseDC(hWnd: v13, hDC: hdc);
    if ( !mxTgaWrite(filename, image: v5) )
      mxMessageBox(parent: this, msg: "Error writing screenshot.", title: g_appTitle, style: 8);
    ((void (__thiscall *)(mxImage *, int))v5->dtr_mxImage)(a1: v5, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415B50
// Name: public: MatSysWindow::MatSysWindow(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
MatSysWindow *__thiscall MatSysWindow::MatSysWindow(
        MatSysWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        int style)
{
  ITexture *v9; // eax
  IMatRenderContext *v10; // eax
  IMatRenderContext *v11; // esi
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  KeyValues *v14; // eax
  KeyValues *v15; // edi
  MaterialSystem_Config_t config; // [esp+Ch] [ebp-64h] BYREF

  mxMatSysWindow::mxMatSysWindow(this, parent, x, y, w, h, label, style);
  this->__vftable = (MatSysWindow_vtbl *)&MatSysWindow::`vftable';
  g_pMaterialSystem->SetMaterialProxyFactory(this: g_pMaterialSystem, a2: &g_DummyMaterialProxyFactory);
  this->m_pCubemapTexture = nullptr;
  this->m_hWnd = mxWidget::getHandle(this);
  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  config = *g_pMaterialSystem->GetCurrentConfigForVideoCard(this: g_pMaterialSystem);
  ConVar::SetValue(this: (ConVar *)&mat_bumpmap.IConVar, value: g_viewerSettings.enableNormalMapping);
  ConVar::SetValue(this: (ConVar *)&mat_displacementmap.IConVar, value: g_viewerSettings.enableDisplacementMapping);
  ConVar::SetValue(this: (ConVar *)&mat_specular.IConVar, value: g_viewerSettings.enableSpecular);
  ConVar::SetValue(this: (ConVar *)&mat_parallaxmap.IConVar, value: g_viewerSettings.enableParallaxMapping);
  if ( g_dxlevel != 0 )
    config.dxSupportLevel = g_dxlevel;
  config.m_Flags |= 3u;
  if ( g_pMaterialSystem->SetMode(this: g_pMaterialSystem, a2: this->m_hWnd, a3: &config) )
  {
    g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
    g_pMaterialSystem->AddReleaseFunc(this: g_pMaterialSystem, a2: (void (__cdecl *)(int))ReleaseMaterialSystemObjects);
    g_pMaterialSystem->AddRestoreFunc(this: g_pMaterialSystem, a2: (void (__cdecl *)(int))RestoreMaterialSystemObjects);
    v9 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "hlmv/cubemap", a3: 0, a4: 1, a5: 0);
    this->m_pCubemapTexture = v9;
    v9->IncrementReferenceCount(this: v9);
    v10 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v11 = v10;
    if ( v10 != nullptr )
      v10->BeginRender(this: v10);
    v11->BindLocalCubemap(this: v11, a2: this->m_pCubemapTexture);
    g_materialBackground = g_pMaterialSystem->FindMaterial(
                             this: g_pMaterialSystem,
                             a2: "hlmv/background",
                             a3: "Other textures",
                             a4: 1,
                             a5: 0);
    g_materialWireframe = g_pMaterialSystem->FindMaterial(
                            this: g_pMaterialSystem,
                            a2: "debug/debugmrmwireframe",
                            a3: "Other textures",
                            a4: 1,
                            a5: 0);
    g_materialWireframeVertexColor = g_pMaterialSystem->FindMaterial(
                                       this: g_pMaterialSystem,
                                       a2: "debug/debugwireframevertexcolor",
                                       a3: "Other textures",
                                       a4: 1,
                                       a5: 0);
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v13 = KeyValues::KeyValues(this: v12, setName: "Wireframe");
    else
      v13 = nullptr;
    KeyValues::SetInt(this: v13, keyName: "$ignorez", value: 1);
    KeyValues::SetInt(this: v13, keyName: "$nocull", value: 1);
    KeyValues::SetInt(this: v13, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v13, keyName: "$decal", value: 1);
    g_materialWireframeVertexColorNoCull = g_pMaterialSystem->CreateMaterial(
                                             this: g_pMaterialSystem,
                                             a2: "debug/wireframenocull",
                                             a3: v13);
    v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v14 != nullptr )
      v15 = KeyValues::KeyValues(this: v14, setName: "UnlitGeneric");
    else
      v15 = nullptr;
    KeyValues::SetString(this: v15, keyName: "$basetexture", value: "vgui/white");
    g_materialDebugCopyBaseTexture = g_pMaterialSystem->CreateMaterial(
                                       this: g_pMaterialSystem,
                                       a2: "debug/copybasetexture",
                                       a3: v15);
    g_materialFlatshaded = g_pMaterialSystem->FindMaterial(
                             this: g_pMaterialSystem,
                             a2: "debug/debugdrawflatpolygons",
                             a3: "Other textures",
                             a4: 1,
                             a5: 0);
    g_materialSmoothshaded = g_pMaterialSystem->FindMaterial(
                               this: g_pMaterialSystem,
                               a2: "debug/debugmrmfullbright2",
                               a3: "Other textures",
                               a4: 1,
                               a5: 0);
    g_materialBones = g_pMaterialSystem->FindMaterial(
                        this: g_pMaterialSystem,
                        a2: "debug/debugskeleton",
                        a3: "Other textures",
                        a4: 1,
                        a5: 0);
    g_materialLines = g_pMaterialSystem->FindMaterial(
                        this: g_pMaterialSystem,
                        a2: "debug/debugwireframevertexcolor",
                        a3: "Other textures",
                        a4: 1,
                        a5: 0);
    g_materialFloor = g_pMaterialSystem->FindMaterial(
                        this: g_pMaterialSystem,
                        a2: "hlmv/floor",
                        a3: "Other textures",
                        a4: 1,
                        a5: 0);
    g_materialVertexColor = g_pMaterialSystem->FindMaterial(
                              this: g_pMaterialSystem,
                              a2: "debug/debugvertexcolor",
                              a3: "Other textures",
                              a4: 1,
                              a5: 0);
    g_materialShadow = g_pMaterialSystem->FindMaterial(
                         this: g_pMaterialSystem,
                         a2: "hlmv/shadow",
                         a3: "Other textures",
                         a4: 1,
                         a5: 0);
    if ( parent != nullptr )
      mx::setIdleWindow(window: this);
    else
      mxWidget::setVisible(this, b: true);
    v11->EndRender(this: v11);
    v11->Release(this: v11);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415F30
// Name: void DrawBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawBackground(int a1@<edi>, int a2@<esi>)
{
  int v2; // esi
  IMesh *v3; // edi
  float *m_pCurrPosition; // eax
  float *v5; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  float *v11; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1E8h] BYREF

  if ( g_viewerSettings.showBackground )
  {
    v2 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a1,
           a3: a2);
    if ( v2 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v2 + 36))(a1: v2, a2: g_materialBackground, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 80))(a1: v2, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 84))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 124))(a1: v2);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 80))(a1: v2, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 84))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 124))(a1: v2);
    v3 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 228))(
                    a1: v2,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v3;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v3->SetPrimitiveType(this: v3, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v3->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v3, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 15000.0;
    m_pCurrPosition[1] = -15000.0;
    m_pCurrPosition[2] = -15000.0;
    v5 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v5[1] = 1.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v6 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -15000.0;
    v6[1] = -15000.0;
    v6[2] = -15000.0;
    v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v7[1] = 1.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -15000.0;
    v8[1] = 15000.0;
    v8[2] = -15000.0;
    v9 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v9[1] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 15000.0;
    v10[1] = 15000.0;
    v10[2] = -15000.0;
    v11 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v11[1] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v3->Draw_2(this: v3, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(a1: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416290
// Name: void DrawHelpers(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawHelpers(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  int v3; // esi
  int v4; // ebx
  IMesh *v5; // edi
  float v6; // xmm0_4
  float *m_pCurrPosition; // edi
  double v8; // xmm0_8
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1F0h] BYREF
  float a; // [esp+1E8h] [ebp-8h]
  IMesh *pMesh; // [esp+1ECh] [ebp-4h]

  if ( g_viewerSettings.mousedown )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2,
           a3,
           a4: a1);
    v4 = 0;
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v3 + 36))(a1: v3, a2: g_materialBones, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    v5 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 228))(
                    a1: v3,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    pMesh = v5;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 144, a3: 144, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 144;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 144, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = g_viewerSettings.rotating ? -256 : -16711936;
    do
    {
      v6 = (double)v4 * 0.01750829251666667;
      a = v6;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = g_viewerSettings.rotating ? -256 : -16711936;
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      __libm_sse2_sin(x: *(long double *)&meshBuilder.m_VertexSize_Position);
      *m_pCurrPosition = v6;
      v8 = a;
      __libm_sse2_cos(x: *(long double *)&meshBuilder.m_VertexSize_Position);
      *(float *)&v8 = v8;
      m_pCurrPosition[1] = *(float *)&v8;
      m_pCurrPosition[2] = -3.0;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v4 += 5;
    }
    while ( v4 < 360 );
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
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004165A0
// Name: void DrawGroundPlane(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawGroundPlane(int a1@<edi>, int a2@<esi>)
{
  int v2; // esi
  unsigned int v3; // eax
  IMesh *v4; // edi
  float v5; // xmm0_4
  float v6; // xmm1_4
  float *m_pCurrPosition; // eax
  float *v8; // eax
  float v9; // xmm0_4
  float *v10; // eax
  float *v11; // eax
  float v12; // xmm0_4
  float *v13; // eax
  float *v14; // eax
  float v15; // xmm0_4
  float *v16; // eax
  float *v17; // eax
  float v18; // xmm0_4
  float *v19; // eax
  float *v20; // eax
  float v21; // xmm0_4
  float *v22; // eax
  float *v23; // eax
  float v24; // xmm0_4
  float *v25; // eax
  float *v26; // eax
  float v27; // xmm0_4
  float *v28; // eax
  float *v29; // eax
  float v30; // xmm0_4
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+A8h] [ebp-200h] BYREF
  Vector deltaPos; // [esp+290h] [ebp-18h] BYREF
  QAngle deltaAngles; // [esp+29Ch] [ebp-Ch] BYREF

  if ( g_viewerSettings.showGround )
  {
    v2 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a1,
           a3: a2);
    if ( v2 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v2 + 36))(a1: v2, a2: g_materialFloor, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 80))(a1: v2, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 84))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 124))(a1: v2);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 80))(a1: v2, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 84))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 124))(a1: v2);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 80))(a1: v2, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 124))(a1: v2);
    (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)v2 + 140))(
      a1: v2,
      a2: -1028390912,
      a3: 1065353216,
      a4: 0,
      a5: 0);
    (*(void (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)v2 + 140))(
      a1: v2,
      a2: -1028390912,
      a3: 0,
      a4: 0,
      a5: 1065353216);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 144))(
      a1: v2,
      a2: -g_pStudioModel->m_origin.x,
      a3: -g_pStudioModel->m_origin.y,
      a4: -g_pStudioModel->m_origin.z);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v2 + 140))(
      a1: v2,
      a2: LODWORD(g_pStudioModel->m_angles.y),
      a3: 0,
      a4: 0,
      a5: 1065353216);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v2 + 140))(
      a1: v2,
      a2: LODWORD(g_pStudioModel->m_angles.x),
      a3: 0,
      a4: 1065353216,
      a5: 0);
    (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v2 + 140))(
      a1: v2,
      a2: LODWORD(g_pStudioModel->m_angles.z),
      a3: 1065353216,
      a4: 0,
      a5: 0);
    v3 = _S1;
    if ( (_S1 & 1) == 0 )
    {
      v3 = _S1 | 1;
      _S1 |= 1u;
      tMap.x = 0.0;
      tMap.y = 0.0;
      tMap.z = 0.0;
    }
    if ( (v3 & 2) == 0 )
    {
      v3 |= 2u;
      _S1 = v3;
      dxMap.x = 1.0;
      dxMap.y = 0.0;
      dxMap.z = 0.0;
    }
    if ( (v3 & 4) == 0 )
    {
      _S1 = v3 | 4;
      dyMap.x = 0.0;
      dyMap.y = 1.0;
      dyMap.z = 0.0;
    }
    StudioModel::GetMovement(
      this: g_pStudioModel,
      prevcycle: g_pStudioModel->m_prevGroundCycles,
      vecPos: &deltaPos,
      vecAngles: &deltaAngles);
    v4 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 228))(
                    a1: v2,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v4;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v5 = (float)(tMap.x - (float)((float)(dxMap.x * deltaPos.x) * 0.1)) - (float)((float)(dxMap.y * deltaPos.y) * 0.1);
    v6 = (float)(tMap.y - (float)((float)(dyMap.x * deltaPos.x) * 0.1)) - (float)((float)(dyMap.y * deltaPos.y) * 0.1);
    tMap.x = v5;
    tMap.y = v6;
    if ( v5 < 0.0 )
    {
      do
        v5 = v5 + 1.0;
      while ( v5 < 0.0 );
      tMap.x = v5;
    }
    if ( v5 > 1.0 )
    {
      do
        v5 = v5 - 1.0;
      while ( v5 > 1.0 );
      tMap.x = v5;
    }
    if ( v6 < 0.0 )
    {
      do
        v6 = v6 + 1.0;
      while ( v6 < 0.0 );
      tMap.y = v6;
    }
    if ( v6 > 1.0 )
    {
      do
        v6 = v6 - 1.0;
      while ( v6 > 1.0 );
      tMap.y = v6;
    }
    VectorYawRotate(in: &dxMap, flYaw: COERCE_FLOAT(LODWORD(deltaAngles.y) ^ _mask__NegFloat_), out: &dxMap);
    VectorYawRotate(in: &dyMap, flYaw: COERCE_FLOAT(LODWORD(deltaAngles.y) ^ _mask__NegFloat_), out: &dyMap);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    m_pCurrPosition[1] = -100.0;
    m_pCurrPosition[2] = 0.0;
    v8 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v9 = (float)((float)(dyMap.y + dxMap.y) * 10.0) + tMap.y;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float)((float)(COERCE_FLOAT(LODWORD(dxMap.x) ^ _mask__NegFloat_)
                                                                    - dyMap.x)
                                                            * 10.0)
                                                    + tMap.x;
    v8[1] = v9;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -100.0;
    v10[1] = -100.0;
    v10[2] = 0.0;
    v11 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v12 = (float)((float)(dyMap.y - dxMap.y) * 10.0) + tMap.y;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float)((float)(dxMap.x - dyMap.x) * 10.0) + tMap.x;
    v11[1] = v12;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v13 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -100.0;
    v13[1] = 100.0;
    v13[2] = 0.0;
    v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v15 = (float)((float)(COERCE_FLOAT(LODWORD(dxMap.y) ^ _mask__NegFloat_) - dyMap.y) * 10.0) + tMap.y;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float)((float)(dyMap.x + dxMap.x) * 10.0) + tMap.x;
    v14[1] = v15;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    v16[1] = 100.0;
    v16[2] = 0.0;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v18 = tMap.y - (float)((float)(dyMap.y - dxMap.y) * 10.0);
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = tMap.x - (float)((float)(dxMap.x - dyMap.x) * 10.0);
    v17[1] = v18;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    v19[1] = -100.0;
    v19[2] = 0.0;
    v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v21 = (float)((float)(dyMap.y + dxMap.y) * 10.0) + tMap.y;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float)((float)(COERCE_FLOAT(LODWORD(dxMap.x) ^ _mask__NegFloat_)
                                                                    - dyMap.x)
                                                            * 10.0)
                                                    + tMap.x;
    v20[1] = v21;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -2139062144;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    v22[1] = 100.0;
    v22[2] = 0.0;
    v23 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v24 = tMap.y - (float)((float)(dyMap.y - dxMap.y) * 10.0);
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = tMap.x - (float)((float)(dxMap.x - dyMap.x) * 10.0);
    v23[1] = v24;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -2139062144;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v25 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -100.0;
    v25[1] = 100.0;
    v25[2] = 0.0;
    v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v27 = (float)((float)(COERCE_FLOAT(LODWORD(dxMap.y) ^ _mask__NegFloat_) - dyMap.y) * 10.0) + tMap.y;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float)((float)(dyMap.x + dxMap.x) * 10.0) + tMap.x;
    v26[1] = v27;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -2139062144;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v28 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -100.0;
    v28[1] = -100.0;
    v28[2] = 0.0;
    v29 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v30 = (float)((float)(dyMap.y - dxMap.y) * 10.0) + tMap.y;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float)((float)(dxMap.x - dyMap.x) * 10.0) + tMap.x;
    v29[1] = v30;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -2139062144;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v4->Draw_2(this: v4, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 80))(a1: v2, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 88))(a1: v2);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 80))(a1: v2, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 88))(a1: v2);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(a1: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416F80
// Name: void DrawMovementBoxes(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawMovementBoxes(int a1@<esi>)
{
  int v1; // esi
  matrix3x4_t mTemp; // [esp+74h] [ebp-80h] BYREF
  float color[4]; // [esp+A4h] [ebp-50h] BYREF
  float wirecolor[4]; // [esp+B4h] [ebp-40h] BYREF
  QAngle deltaAngles; // [esp+C4h] [ebp-30h] BYREF
  Vector deltaPos; // [esp+D0h] [ebp-24h] BYREF
  Vector bboxMin; // [esp+DCh] [ebp-18h] BYREF
  Vector bboxMax; // [esp+E8h] [ebp-Ch] BYREF

  if ( g_viewerSettings.showMovement )
  {
    v1 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a1);
    if ( v1 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v1 + 36))(a1: v1, a2: g_materialFloor, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v1 + 80))(a1: v1, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 84))(a1: v1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 124))(a1: v1);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v1 + 80))(a1: v1, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 84))(a1: v1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 124))(a1: v1);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v1 + 80))(a1: v1, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 124))(a1: v1);
    (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)v1 + 140))(
      a1: v1,
      a2: -1028390912,
      a3: 1065353216,
      a4: 0,
      a5: 0);
    (*(void (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)v1 + 140))(
      a1: v1,
      a2: -1028390912,
      a3: 0,
      a4: 0,
      a5: 1065353216);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v1 + 144))(
      a1: v1,
      a2: -g_pStudioModel->m_origin.x,
      a3: -g_pStudioModel->m_origin.y,
      a4: -g_pStudioModel->m_origin.z);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v1 + 140))(
      a1: v1,
      a2: LODWORD(g_pStudioModel->m_angles.y),
      a3: 0,
      a4: 0,
      a5: 1065353216);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v1 + 140))(
      a1: v1,
      a2: LODWORD(g_pStudioModel->m_angles.x),
      a3: 0,
      a4: 1065353216,
      a5: 0);
    (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v1 + 140))(
      a1: v1,
      a2: LODWORD(g_pStudioModel->m_angles.z),
      a3: 1065353216,
      a4: 0,
      a5: 0);
    if ( (_S2 & 1) == 0 )
    {
      _S2 |= 1u;
      *(_QWORD *)&mStart.m_flMatVal[0][0] = 1065353216;
      *(_QWORD *)&mStart.m_flMatVal[0][2] = 0;
      *(_QWORD *)&mStart.m_flMatVal[1][0] = 0x3F80000000000000LL;
      *(_QWORD *)&mStart.m_flMatVal[1][2] = 0;
      *(_QWORD *)&mStart.m_flMatVal[2][0] = 0;
      *(_QWORD *)&mStart.m_flMatVal[2][2] = 1065353216;
    }
    StudioModel::GetMovement(this: g_pStudioModel, prevcycle: prevframes, vecPos: &deltaPos, vecAngles: &deltaAngles);
    AngleMatrix(angles: &deltaAngles, position: &deltaPos, matrix: &mTemp);
    MatrixInvert(in: &mTemp, out: &mTemp);
    ConcatTransforms(in1: &mTemp, in2: &mStart, out: &mStart);
    StudioModel::ExtractBbox(this: g_pStudioModel, a2: v1, mins: &bboxMin, maxs: &bboxMax);
    if ( fabs(StudioModel::GetFrame(this: g_pStudioModel, iLayer: 0) - prevCycle) > 0.5 )
      SetIdentityMatrix(matrix: &mStart);
    prevCycle = StudioModel::GetFrame(this: g_pStudioModel, iLayer: 0);
    color[0] = 0.69999999;
    color[1] = 1.0;
    color[2] = 0.0;
    color[3] = 0.5;
    wirecolor[0] = 1.0;
    wirecolor[1] = 1.0;
    wirecolor[2] = 0.0;
    wirecolor[3] = 1.0;
    StudioModel::drawTransparentBox(
      this: g_pStudioModel,
      bbmin: &bboxMin,
      bbmax: &bboxMax,
      m: &mStart,
      color,
      wirecolor);
    wirecolor[1] = 0.69999999;
    wirecolor[0] = 1.0;
    wirecolor[2] = 0.0;
    wirecolor[3] = 0.5;
    color[0] = 1.0;
    color[1] = 0.0;
    color[2] = 0.0;
    color[3] = 1.0;
    SetIdentityMatrix(matrix: &mTemp);
    StudioModel::drawTransparentBox(
      this: g_pStudioModel,
      bbmin: &bboxMin,
      bbmax: &bboxMax,
      m: &mTemp,
      color: wirecolor,
      wirecolor: color);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v1 + 80))(a1: v1, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 88))(a1: v1);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v1 + 80))(a1: v1, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 88))(a1: v1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 12))(a1: v1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 4))(a1: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004173B0
// Name: public: virtual void MatSysWindow::draw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall MatSysWindow::draw(MatSysWindow *this@<ecx>, int a2@<edi>)
{
  IMDLCache *v2; // esi
  IMatRenderContext *v4; // esi
  IMatRenderContext_vtbl *v5; // edi
  int v6; // eax
  int v7; // edi
  float v8; // xmm1_4
  float v9; // xmm1_4
  int v10; // edi
  int LodUsed; // eax
  StudioModel **v12; // edi
  double v13; // xmm0_8
  void (__thiscall *SwapBuffers)(IMaterialSystem *); // eax
  void (__thiscall *EndRender)(IMatRenderContext *); // eax
  int flWeight; // [esp+7Ch] [ebp-1Ch]
  float flWeighta; // [esp+7Ch] [ebp-1Ch]
  IMDLCache *cacheCriticalSection; // [esp+88h] [ebp-10h]
  Vector vecPosition; // [esp+8Ch] [ebp-Ch] BYREF

  v2 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  if ( g_bInError || g_pStudioRender == nullptr || bInDraw )
  {
    v2->EndLock(this: v2);
  }
  else
  {
    bInDraw = true;
    UpdateSounds();
    v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    ((void (__stdcall *)(_DWORD, int))g_pMaterialSystem->BeginFrame)(a1: 0, a2);
    g_pStudioRender->BeginFrame(this: g_pStudioRender);
    v4->ClearColor3ub(
      this: v4,
      a2: (int)(float)(g_viewerSettings.bgColor[0] * 255.0),
      a3: (int)(float)(g_viewerSettings.bgColor[1] * 255.0),
      a4: (int)(float)(g_viewerSettings.bgColor[2] * 255.0));
    v4->ClearBuffers(this: v4, a2: true, a3: true, a4: false);
    v5 = v4->__vftable;
    flWeight = mxWidget::h(this);
    v6 = mxWidget::w(this);
    v5->Viewport(this: v4, a2: 0, a3: 0, a4: v6, a5: flWeight);
    v4->MatrixMode(this: v4, a2: MATERIAL_PROJECTION);
    v4->LoadIdentity(this: v4);
    v7 = (int)v4->__vftable;
    vecPosition.z = (float)mxWidget::w(this);
    v8 = (float)mxWidget::h(this);
    (*(void (__thiscall **)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))(v7 + 132))(
      a1: v4,
      a2: COERCE_UNSIGNED_INT64(g_viewerSettings.fov),
      a3: HIDWORD(COERCE_UNSIGNED_INT64(g_viewerSettings.fov)),
      a4: COERCE_UNSIGNED_INT64((float)(vecPosition.z / v8)),
      a5: HIDWORD(COERCE_UNSIGNED_INT64((float)(vecPosition.z / v8))),
      a6: 0,
      a7: 1072693248,
      a8: 0,
      a9: 1087604736);
    DrawBackground(a1: v7, a2: (int)v4);
    DrawGroundPlane(a1: v7, a2: (int)v4);
    DrawMovementBoxes(a1: (int)v4);
    DrawHelpers(a1: (int)this, a2: v7, a3: (int)v4);
    v4->MatrixMode(this: v4, a2: MATERIAL_VIEW);
    v4->LoadIdentity(this: v4);
    ((void (__thiscall *)(IMatRenderContext *, int, int, _DWORD, _DWORD))v4->Rotate)(
      a1: v4,
      a2: -1028390912,
      a3: 1065353216,
      a4: 0,
      a5: 0);
    ((void (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, int))v4->Rotate)(
      a1: v4,
      a2: -1028390912,
      a3: 0,
      a4: 0,
      a5: 1065353216);
    StudioModel::ClearLookTargets(this: g_pStudioModel);
    if ( StudioModel::GetSolveHeadTurn(this: g_pStudioModel) != 0 )
      v9 = 1.0;
    else
      v9 = 0.0;
    memset(&vecPosition, 0, sizeof(vecPosition));
    StudioModel::AddLookTarget(this: g_pStudioModel, &vecPosition, flWeight: v9);
    v10 = g_pStudioModel->DrawModel(this: g_pStudioModel, a2: false);
    g_pStudioRender->EndFrame(this: g_pStudioRender);
    UpdateSounds();
    ControlPanel::setModelInfo(this: g_ControlPanel);
    vecPosition.z = StudioModel::GetLodMetric(this: g_pStudioModel);
    LodUsed = StudioModel::GetLodUsed(this: g_pStudioModel);
    ControlPanel::setLOD(this: g_ControlPanel, index: LodUsed, setLODchoice: true, force: false);
    ControlPanel::setLODMetric(this: g_ControlPanel, metric: vecPosition.z);
    ControlPanel::setPolycount(this: g_ControlPanel, polycount: v10);
    ControlPanel::setTransparent(this: g_ControlPanel, isTransparent: g_pStudioModel->m_bIsTransparent);
    ControlPanel::updatePoseParameters(this: g_ControlPanel);
    v12 = g_pStudioExtraModel;
    do
    {
      if ( *v12 != nullptr )
      {
        g_pStudioRender->BeginFrame(this: g_pStudioRender);
        (*v12)->DrawModel(this: *v12, a2: true);
        g_pStudioRender->EndFrame(this: g_pStudioRender);
      }
      ++v12;
    }
    while ( (int)v12 < (int)&StudioModel::m_AmbientLightColors );
    ++g_pStudioModel->m_iFramecounter;
    PlaySounds(pStudioModel: g_pStudioModel);
    v13 = (double)(int)mx::getTickCount() * 0.001;
    *(double *)&vecPosition.y = v13;
    if ( prev != 0.0 )
    {
      flWeighta = (v13 - prev) * g_viewerSettings.speedScale;
      ((void (__stdcall *)(_DWORD))g_pSoundSystem->Update)(a1: LODWORD(flWeighta));
      v13 = *(double *)&vecPosition.y;
    }
    SwapBuffers = g_pMaterialSystem->SwapBuffers;
    prev = v13;
    SwapBuffers(this: g_pMaterialSystem);
    g_pMaterialSystem->EndFrame(this: g_pMaterialSystem);
    EndRender = v4->EndRender;
    bInDraw = false;
    EndRender(this: v4);
    v4->Release(this: v4);
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004177F0
// Name: public: virtual int MatSysWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __thiscall MatSysWindow::handleEvent(MatSysWindow *this, mxEvent *event)
{
  IMDLCache *m_pCache; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  double v6; // xmm1_8
  double v7; // xmm0_8
  int Sequence; // eax
  char *SequenceName; // ebx
  StudioModel **v10; // esi
  int v11; // eax
  StudioModel *v12; // ecx
  double v13; // st7
  int x; // ecx
  int y; // edx
  int v16; // ebx
  int v17; // eax
  int v18; // ebx
  float v19; // xmm1_4
  int buttons; // eax
  float v22; // xmm0_4
  int modifiers; // eax
  int v24; // esi
  int v25; // ecx
  float v26; // xmm1_4
  int v27; // esi
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  int v31; // ecx
  float v32; // xmm0_4
  int v33; // esi
  long double v34; // [esp+60h] [ebp-C0h]
  long double v35; // [esp+60h] [ebp-C0h]
  long double v36; // [esp+68h] [ebp-B8h] OVERLAPPED BYREF
  CUtlBuffer cmd; // [esp+9Ch] [ebp-84h] BYREF
  QAngle movement; // [esp+CCh] [ebp-54h] BYREF
  matrix3x4_t m; // [esp+D8h] [ebp-48h] BYREF
  long double dt; // [esp+108h] [ebp-18h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+110h] [ebp-10h]
  QAngle angles; // [esp+114h] [ebp-Ch] BYREF
  float ang1; // [esp+128h] [ebp+8h]
  int ang1a; // [esp+128h] [ebp+8h]
  float ang1b; // [esp+128h] [ebp+8h]
  float ang1c; // [esp+128h] [ebp+8h]

  m_pCache = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  switch ( event->event )
  {
    case 3:
      v6 = (double)(int)mx::getTickCount() * 0.001;
      v7 = v6 - prev_0;
      *(double *)&angles.y = v6;
      dt = v6 - prev_0;
      if ( v6 - prev_0 < 0.0 || v7 >= 0.01 )
      {
        if ( prev_0 != 0.0 )
        {
          ((void (__stdcall *)(_DWORD))g_pStudioModel->AdvanceFrame)(a1: g_viewerSettings.speedScale * v7);
          if ( g_viewerSettings.animateWeapons )
          {
            Sequence = StudioModel::GetSequence(this: g_pStudioModel);
            SequenceName = StudioModel::GetSequenceName(this: g_pStudioModel, iSequence: Sequence);
            if ( SequenceName != nullptr )
            {
              v10 = g_pStudioExtraModel;
              do
              {
                if ( *v10 != nullptr )
                {
                  v11 = StudioModel::LookupSequence(this: *v10, szSequence: SequenceName);
                  v12 = *v10;
                  if ( v11 == -1 )
                  {
                    StudioModel::SetFrame(this: v12, frame: 0);
                  }
                  else
                  {
                    StudioModel::SetSequence(this: v12, iSequence: v11);
                    ang1 = (float)StudioModel::GetMaxFrame(this: *v10);
                    v13 = StudioModel::GetCycle(this: g_pStudioModel) * ang1;
                    StudioModel::SetFrame(this: *v10, frame: (int)v13);
                  }
                }
                ++v10;
              }
              while ( (int)v10 < (int)&StudioModel::m_AmbientLightColors );
            }
            m_pCache = cacheCriticalSection.m_pCache;
          }
          ControlPanel::updateFrameSlider(this: g_ControlPanel);
          ControlPanel::updateGroundSpeed(this: g_ControlPanel);
          v6 = *(double *)&angles.y;
        }
        prev_0 = v6;
        if ( !g_viewerSettings.pause )
          this->redraw(this);
        ControlPanel::updateTransitionAmount(this: g_ControlPanel);
        UpdateSounds();
      }
      else
      {
        cacheCriticalSection.m_pCache = (IMDLCache *)(HIWORD(event) | 0xC00);
        *(_QWORD *)&dt = (__int64)(10.0 - dt * 1000.0);
        Sleep(dwMilliseconds: LODWORD(dt));
      }
      goto LABEL_46;
    case 6:
      g_viewerSettings.mousedown = false;
      goto LABEL_46;
    case 7:
      g_viewerSettings.mousedown = true;
      x = event->x;
      y = event->y;
      oldrx = g_pStudioModel->m_angles.x;
      oldry = g_pStudioModel->m_angles.y;
      oldtx = g_pStudioModel->m_origin.x;
      oldty = g_pStudioModel->m_origin.y;
      oldtz = g_pStudioModel->m_origin.z;
      oldx = x;
      oldlrx = g_viewerSettings.lightrot.y;
      oldy = y;
      oldlry = g_viewerSettings.lightrot.x;
      g_viewerSettings.pause = false;
      v16 = mxWidget::w(this);
      if ( v16 >= mxWidget::h(this) )
        v17 = mxWidget::h(this);
      else
        v17 = mxWidget::w(this);
      ang1a = v17;
      HIDWORD(dt) = event->y - mxWidget::h(this) / 2;
      v18 = HIDWORD(dt) * (event->y - mxWidget::h(this) / 2);
      HIDWORD(dt) = event->x - mxWidget::w(this) / 2;
      v19 = (double)ang1a * 0.3333333333333333;
      g_viewerSettings.rotating = v19 <= fsqrt((float)(v18 + HIDWORD(dt) * (event->x - mxWidget::w(this) / 2)));
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return 1;
    case 9:
      buttons = event->buttons;
      if ( (buttons & 1) != 0 )
      {
        if ( g_viewerSettings.dotaMode )
        {
          if ( (event->modifiers & 2) != 0 )
          {
            g_pStudioModel->m_origin.y = oldty - (float)(event->x - oldx);
            g_pStudioModel->m_origin.z = (float)(event->y - oldy) + oldtz;
          }
          else
          {
            v22 = (float)(event->x - oldx);
            oldx = event->x;
            angles.x = 0.0;
            angles.y = v22;
            angles.z = 0.0;
            AngleMatrix(angles: &g_pStudioModel->m_angles, matrix: (matrix3x4_t *)((char *)&v36 + 4));
            AngleMatrix(&angles, matrix: (matrix3x4_t *)&cmd);
            ConcatTransforms(in1: (const matrix3x4_t *)((char *)&v36 + 4), in2: (const matrix3x4_t *)&cmd, out: &m);
            MatrixAngles(matrix: &m, angles: &g_pStudioModel->m_angles.x);
          }
        }
        else
        {
          modifiers = event->modifiers;
          if ( (modifiers & 2) != 0 )
          {
            g_pStudioModel->m_origin.y = oldty - (float)(event->x - oldx);
            g_pStudioModel->m_origin.z = (float)(event->y - oldy) + oldtz;
          }
          else if ( (modifiers & 1) != 0 )
          {
            v24 = event->x;
            v25 = event->y - oldy;
            oldy = event->y;
            angles.x = (float)v25;
            v26 = (float)(v24 - oldx);
            oldx = v24;
            angles.y = v26;
            angles.z = 0.0;
            AngleMatrix(angles: &g_viewerSettings.lightrot, matrix: (matrix3x4_t *)&cmd);
            AngleMatrix(&angles, matrix: (matrix3x4_t *)((char *)&v36 + 4));
            ConcatTransforms(in1: (const matrix3x4_t *)((char *)&v36 + 4), in2: (const matrix3x4_t *)&cmd, out: &m);
            MatrixAngles(matrix: &m, angles: &g_viewerSettings.lightrot.x);
          }
          else if ( g_viewerSettings.rotating )
          {
            *(double *)&angles.y = (double)oldx;
            dt = (double)oldy;
            *(double *)&angles.y = *(double *)&angles.y - (double)mxWidget::w(this) * 0.5;
            mxWidget::h(this);
            __libm_sse2_atan2(y: v34, x: v36);
            v30 = *(double *)&angles.y * 57.29746936176985;
            ang1c = v30;
            *(double *)&angles.y = (double)event->x;
            dt = (double)event->y;
            *(double *)&angles.y = *(double *)&angles.y - (double)mxWidget::w(this) * 0.5;
            mxWidget::h(this);
            __libm_sse2_atan2(y: v35, x: v36);
            v31 = event->y;
            oldx = event->x;
            v32 = *(double *)&angles.y * 57.29746936176985;
            oldy = v31;
            movement.x = 0.0;
            movement.y = 0.0;
            movement.z = v32 - ang1c;
            AngleMatrix(angles: &g_pStudioModel->m_angles, matrix: (matrix3x4_t *)&cmd);
            AngleMatrix(angles: &movement, matrix: (matrix3x4_t *)((char *)&v36 + 4));
            ConcatTransforms(in1: (const matrix3x4_t *)((char *)&v36 + 4), in2: (const matrix3x4_t *)&cmd, out: &m);
            MatrixAngles(matrix: &m, angles: &g_pStudioModel->m_angles.x);
          }
          else
          {
            v27 = event->x;
            v28 = (float)(event->y - oldy);
            oldy = event->y;
            ang1b = v28;
            v29 = (float)(v27 - oldx);
            oldx = v27;
            angles.x = 0.0;
            angles.y = v29;
            angles.z = 0.0;
            AngleMatrix(angles: &g_pStudioModel->m_angles, matrix: &m);
            AngleMatrix(&angles, matrix: (matrix3x4_t *)((char *)&v36 + 4));
            ConcatTransforms(in1: &m, in2: (const matrix3x4_t *)((char *)&v36 + 4), out: (matrix3x4_t *)&cmd);
            MatrixAngles(matrix: (const matrix3x4_t *)&cmd, angles: &g_pStudioModel->m_angles.x);
            angles.x = ang1b;
            angles.y = 0.0;
            angles.z = 0.0;
            AngleMatrix(angles: &g_pStudioModel->m_angles, matrix: &m);
            AngleMatrix(&angles, matrix: (matrix3x4_t *)((char *)&v36 + 4));
            ConcatTransforms(in1: (const matrix3x4_t *)((char *)&v36 + 4), in2: &m, out: (matrix3x4_t *)&cmd);
            MatrixAngles(matrix: (const matrix3x4_t *)&cmd, angles: &g_pStudioModel->m_angles.x);
          }
        }
      }
      else if ( (buttons & 2) != 0 && !g_viewerSettings.dotaMode )
      {
        g_pStudioModel->m_origin.x = (float)(event->y - oldy) + oldtx;
      }
      if ( g_bHlmvMaster && CValveIpcClient::Connect(this: &g_HlmvIpcClient) != 0 )
      {
        CUtlBuffer::CUtlBuffer(this: &cmd, growSize: 0, initSize: 0, nFlags: 0);
        CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)((char *)&v36 + 4), growSize: 0, initSize: 0, nFlags: 0);
        StudioModel::GetModelTransform(this: g_pStudioModel, mat: &m);
        CUtlBuffer::Printf(
          this: &cmd,
          pFmt: "%s %f %f %f %f %f %f %f %f %f %f %f %f",
          "hlmvModelTransform",
          m.m_flMatVal[0][0],
          m.m_flMatVal[0][1],
          m.m_flMatVal[0][2],
          m.m_flMatVal[0][3],
          m.m_flMatVal[1][0],
          m.m_flMatVal[1][1],
          m.m_flMatVal[1][2],
          m.m_flMatVal[1][3],
          m.m_flMatVal[2][0],
          m.m_flMatVal[2][1],
          m.m_flMatVal[2][2],
          m.m_flMatVal[2][3]);
        CValveIpcClientUtl::ExecuteCommand(this: &g_HlmvIpcClient, &cmd, res: (CUtlBuffer *)((char *)&v36 + 4));
        CValveIpcClient::Disconnect(this: &g_HlmvIpcClient);
        CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)((char *)&v36 + 4));
        CUtlBuffer::~CUtlBuffer(this: &cmd);
      }
      this->redraw(this);
      goto LABEL_46;
    case 0xB:
      if ( event->key == 32 )
      {
        v33 = StudioModel::GetSequence(this: g_pStudioModel);
        if ( v33 == StudioModel::SetSequence(this: g_pStudioModel, iSequence: v33 + 1) )
          StudioModel::SetSequence(this: g_pStudioModel, iSequence: 0);
      }
      goto LABEL_46;
    default:
LABEL_46:
      m_pCache->EndLock(this: m_pCache);
      return 1;
  }
}
