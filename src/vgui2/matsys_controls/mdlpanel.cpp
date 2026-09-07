// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/mdlpanel.cpp
// Functions: 27
// ============================================================

#include "vgui2\matsys_controls\mdlpanel.h"

//------------------------------------------------------------------------------
// Address: 0x004C9170
// Name: public: static char const __near * CMDLPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPanel::GetPanelClassName()
{
  return "CMDLPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004C9180
// Name: public: virtual void CMDLPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::ApplySchemeSettings(CMDLPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  const Color *v4; // eax
  CMDLPanel_vtbl *v5; // ebx
  int v6; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->GetBgColor(this, result: &pScheme);
  CPotteryWheelPanel::SetBackgroundColor(this, c: v4);
  v5 = this->__vftable;
  v6 = (int)v2->GetBorder(this: v2, a2: "MenuBorder");
  v5->SetBorder(this, a2: (vgui::IBorder *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x004C91D0
// Name: public: void CMDLPanel::SetCollsionModel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetCollsionModel(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (bVisible ^ *((_BYTE *)this + 2876)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C91F0
// Name: public: void CMDLPanel::SetGroundGrid(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetGroundGrid(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (2 * bVisible)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x004C9210
// Name: public: void CMDLPanel::SetWireFrame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetWireFrame(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (8 * bVisible)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x004C9230
// Name: public: void CMDLPanel::SetLockView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetLockView(CMDLPanel *this, bool bLocked)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (4 * bLocked)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x004C9250
// Name: public: void CMDLPanel::SetLookAtCamera(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetLookAtCamera(CMDLPanel *this, bool bLookAtCamera)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (16 * bLookAtCamera)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x004C9270
// Name: public: virtual void CMDLPanel::SetMDL(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, const char *pMDLName, void *pProxyData)
{
  IMDLCache *v4; // eax
  int v5; // esi
  IMDLCache *v6; // eax

  if ( pMDLName != nullptr )
  {
    v4 = vgui::MDLCache();
    v5 = v4->FindMDL(this: v4, a2: pMDLName);
  }
  else
  {
    v5 = 0xFFFF;
  }
  v6 = vgui::MDLCache();
  if ( v6->IsErrorModel(this: v6, a2: v5) )
    v5 = 0xFFFF;
  this->SetMDL_2(this, a2: v5, a3: pProxyData);
}

//------------------------------------------------------------------------------
// Address: 0x004C92D0
// Name: public: bool CMDLPanel::GetBoundingSphere(class Vector __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLPanel::GetBoundingSphere(CMDLPanel *this, Vector *vecCenter, float *flRadius)
{
  unsigned __int16 MDL; // ax
  int m_nSequence; // [esp-4h] [ebp-18h]
  Vector vecEngineCenter; // [esp+8h] [ebp-Ch] BYREF

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) == 0xFFFF )
    return 0;
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
  GetMDLBoundingSphere(pVecCenter: &vecEngineCenter, pRadius: flRadius, h: MDL, nSequence: m_nSequence);
  VectorTransform(in1: &vecEngineCenter.x, in2: &this->m_RootMDL.m_MDLToWorld, out: &vecCenter->x);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C9340
// Name: public: void CMDLPanel::LookAtMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPanel::LookAtMDL(CMDLPanel *this@<ecx>, int a2@<edi>)
{
  Vector vecCenter; // [esp+8h] [ebp-10h] BYREF
  float flRadius; // [esp+14h] [ebp-4h] BYREF

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF && (*((_BYTE *)this + 2876) & 4) == 0 )
  {
    CMDLPanel::GetBoundingSphere(this, &vecCenter, &flRadius);
    CPotteryWheelPanel::LookAt(this, a2, &vecCenter, flRadius);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C93A0
// Name: public: void CMDLPanel::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSequence(CMDLPanel *this, int nSequence)
{
  this->m_RootMDL.m_MDL.m_nSequence = nSequence;
}

//------------------------------------------------------------------------------
// Address: 0x004C93B0
// Name: public: void CMDLPanel::SetSequenceLayers(struct MDLSquenceLayer_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSequenceLayers(CMDLPanel *this, const MDLSquenceLayer_t *pSequenceLayers, int nCount)
{
  const MDLSquenceLayer_t *v3; // eax
  int v4; // esi
  int v5; // edx
  MDLSquenceLayer_t *m_SequenceLayers; // edx

  v3 = pSequenceLayers;
  v4 = 0;
  if ( pSequenceLayers != nullptr )
  {
    v5 = nCount;
    if ( nCount > 8 )
      v5 = 8;
    this->m_nNumSequenceLayers = v5;
    if ( v5 > 0 )
    {
      m_SequenceLayers = this->m_SequenceLayers;
      do
      {
        m_SequenceLayers->m_nSequenceIndex = v3->m_nSequenceIndex;
        m_SequenceLayers->m_flWeight = v3->m_flWeight;
        ++v4;
        ++v3;
        ++m_SequenceLayers;
      }
      while ( v4 < this->m_nNumSequenceLayers );
    }
  }
  else
  {
    this->m_nNumSequenceLayers = 0;
    _V_memset(dest: this->m_SequenceLayers, fill: 0, count: 64);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C9420
// Name: public: void CMDLPanel::SetSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSkin(CMDLPanel *this, int nSkin)
{
  this->m_RootMDL.m_MDL.m_nSkin = nSkin;
}

//------------------------------------------------------------------------------
// Address: 0x004C9430
// Name: public: virtual void CMDLPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::OnTick(CMDLPanel *this)
{
  int v2; // eax
  int v3; // ecx

  CPotteryWheelPanel::OnTick(this);
  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v2 = _Plat_MSTime();
    v3 = dword_77479C;
    if ( dword_77479C == 0 )
      v3 = v2;
    *(float *)&dword_774798 = (float)((float)(v2 - v3) * 0.001) + *(float *)&dword_774798;
    dword_77479C = v2;
    LODWORD(this->m_RootMDL.m_MDL.m_flTime) = dword_774798;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C9490
// Name: private: virtual void CMDLPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMDLPanel::OnMouseDoublePressed(CMDLPanel *this@<ecx>, int a2@<edi>, const char *code)
{
  Vector vecCenter; // [esp+8h] [ebp-10h] BYREF
  float flRadius; // [esp+14h] [ebp-4h] BYREF

  CMDLPanel::GetBoundingSphere(this, &vecCenter, &flRadius);
  CPotteryWheelPanel::LookAt(this, a2, &vecCenter, flRadius);
  CPotteryWheelPanel::OnMouseDoublePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004C94D0
// Name: private: void CMDLPanel::UpdateStudioRenderConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::UpdateStudioRenderConfig(CMDLPanel *this)
{
  char v2; // al
  char v3; // al
  char v4; // al
  IStudioRender *v5; // eax

  memset(dst: (unsigned __int8 *)&s_StudioRenderConfig, value: 0, count: sizeof(s_StudioRenderConfig));
  v2 = (*((_BYTE *)&s_StudioRenderConfig + 36)
      ^ (r_eyemove.m_pParent->m_Value.m_nValue != 0))
     & 1
     ^ *((_BYTE *)&s_StudioRenderConfig + 36);
  *((_BYTE *)&s_StudioRenderConfig + 36) = v2;
  s_StudioRenderConfig.fEyeShiftX = r_eyeshift_x.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftY = r_eyeshift_y.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftZ = r_eyeshift_z.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeSize = r_eyesize.m_pParent->m_Value.m_fValue;
  if ( mat_softwareskin.m_pParent->m_Value.m_nValue != 0 || (*((_BYTE *)this + 2876) & 8) != 0 )
    v3 = v2 | 2;
  else
    v3 = v2 & 0xFD;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v3;
  *((_BYTE *)&s_StudioRenderConfig + 36) = (v3 ^ (4 * (r_nohw.m_pParent->m_Value.m_nValue != 0))) & 4 ^ v3;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ (8 * (r_nosw.m_pParent->m_Value.m_nValue != 0)))
                                          & 8;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ (16 * (r_teeth.m_pParent->m_Value.m_nValue != 0)))
                                          & 0x10;
  s_StudioRenderConfig.drawEntities = r_drawentities.m_pParent->m_Value.m_nValue;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ ((r_flex.m_pParent->m_Value.m_nValue != 0) << 6))
                                          & 0x40;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ (32 * (r_eyes.m_pParent->m_Value.m_nValue != 0)))
                                          & 0x20;
  *((_BYTE *)&s_StudioRenderConfig + 36) = (16 * *((_BYTE *)this + 2876))
                                         ^ (*((_BYTE *)&s_StudioRenderConfig + 36)
                                          ^ (16 * *((_BYTE *)this + 2876)))
                                         & 0x7F;
  *((_BYTE *)&s_StudioRenderConfig + 37) ^= (*((_BYTE *)&s_StudioRenderConfig + 37)
                                           ^ (mat_normals.m_pParent->m_Value.m_nValue != 0))
                                          & 1;
  s_StudioRenderConfig.skin = r_skin.m_pParent->m_Value.m_nValue;
  s_StudioRenderConfig.maxDecalsPerModel = r_maxmodeldecal.m_pParent->m_Value.m_nValue;
  v4 = ((*((_BYTE *)&s_StudioRenderConfig + 37)
       ^ (32 * (r_modelwireframedecal.m_pParent->m_Value.m_nValue != 0)))
      & 0x20
      ^ *((_BYTE *)&s_StudioRenderConfig + 37))
     & 0xF7;
  s_StudioRenderConfig.fullbright = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = v4;
  *((_BYTE *)&s_StudioRenderConfig + 37) = (v4 ^ (16 * (r_showenvcubemap.m_pParent->m_Value.m_nValue != 0))) & 0x10 ^ v4;
  s_StudioRenderConfig.fEyeGlintPixelWidthLODThreshold = r_eyeglintlodpixels.m_pParent->m_Value.m_fValue;
  v5 = vgui::StudioRender();
  v5->UpdateConfig(this: v5, a2: &s_StudioRenderConfig);
}

//------------------------------------------------------------------------------
// Address: 0x004C9740
// Name: public: CMDLPanel::CMDLPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMDLPanel *__thiscall CMDLPanel::CMDLPanel(CMDLPanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  IMaterialSystem *v7; // eax
  ITexture *v8; // eax
  IMaterialSystem *v9; // eax
  ITexture *v10; // eax

  CPotteryWheelPanel::CPotteryWheelPanel(this, pParent, pName);
  this->__vftable = (CMDLPanel_vtbl *)&CMDLPanel::`vftable';
  if ( `CMDLPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
    v4->pfnClassName = CMDLPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  }
  if ( `CMDLPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMDLPanel");
    v5->pfnClassName = CMDLPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
  }
  if ( `CMDLPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
    v6->pfnClassName = CMDLPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  }
  CMDL::CMDL(this: &this->m_RootMDL.m_MDL);
  this->m_aMergeMDLs.m_Memory.m_pMemory = nullptr;
  this->m_aMergeMDLs.m_Memory.m_nAllocationCount = 0;
  this->m_aMergeMDLs.m_Memory.m_nGrowSize = 0;
  this->m_aMergeMDLs.m_Size = 0;
  this->m_aMergeMDLs.m_pElements = nullptr;
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  vgui::Panel::SetVisible(this, state: true);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  v7 = vgui::MaterialSystem();
  v8 = v7->FindTexture(this: v7, a2: "editor/cubemap", a3: nullptr, a4: true, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultEnvCubemap, pTexture: v8);
  v9 = vgui::MaterialSystem();
  v10 = v9->FindTexture(this: v9, a2: "editor/cubemap.hdr", a3: nullptr, a4: true, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultHDREnvCubemap, pTexture: v10);
  SetIdentityMatrix(matrix: &this->m_RootMDL.m_MDLToWorld);
  *((_BYTE *)this + 2876) = *((_BYTE *)this + 2876) & 0xE0 | 0x10;
  this->m_nNumSequenceLayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C98D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPanel::GetMessageMap(CMDLPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetMessageMap'::`2'::s_pMap;
  `CMDLPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
  `CMDLPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C9900
// Name: public: virtual struct PanelAnimationMap __near * CMDLPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPanel::GetAnimMap(CMDLPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004C9910
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPanel::GetKBMap(CMDLPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetKBMap'::`2'::s_pMap;
  `CMDLPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
  `CMDLPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C9940
// Name: public: virtual CMDLPanel::~CMDLPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::~CMDLPanel(CMDLPanel *this)
{
  this->__vftable = (CMDLPanel_vtbl *)&CMDLPanel::`vftable';
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  CTextureReference::Shutdown(this: &this->m_DefaultEnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &this->m_DefaultHDREnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::~CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  if ( this->m_aMergeMDLs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aMergeMDLs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aMergeMDLs.m_Memory.m_pMemory);
      this->m_aMergeMDLs.m_Memory.m_pMemory = nullptr;
    }
    this->m_aMergeMDLs.m_Memory.m_nAllocationCount = 0;
  }
  CMDL::~CMDL(this: &this->m_RootMDL.m_MDL);
  CPotteryWheelPanel::~CPotteryWheelPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C99E0
// Name: private: void CMDLPanel::DrawCollisionModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::DrawCollisionModel(CMDLPanel *this)
{
  IMDLCache *v2; // edi
  IMDLCache_vtbl *v3; // esi
  CMDLPanel::MDLData_t *p_m_RootMDL; // ebx
  unsigned __int16 MDL; // ax
  IMDLCache *v6; // eax
  IVPhysicsKeyParser *v7; // esi
  IMDLCache_vtbl *v8; // edi
  unsigned __int16 v9; // ax
  const studiohdr_t *v10; // eax
  const char *v11; // eax
  int v12; // eax
  IVPhysicsKeyParser_vtbl *v13; // edx
  int v14; // eax
  int (__thiscall *CreateDebugMesh)(IPhysicsCollision *, const struct CPhysCollide *, Vector **); // edx
  int v16; // edi
  IMatRenderContext *v17; // ebx
  IMesh *v18; // esi
  int v19; // edi
  int v20; // edi
  int i; // ebx
  float *m_pCurrPosition; // eax
  int a; // ecx
  float *v24; // eax
  int m_nVertexCount; // eax
  IMDLCache *v26; // [esp-8h] [ebp-38F8h]
  IMDLCache *v27; // [esp-4h] [ebp-38F4h]
  matrix3x4_t pBoneToWorld[256]; // [esp+Ch] [ebp-38E4h] BYREF
  char pName[1548]; // [esp+300Ch] [ebp-8E4h] BYREF
  int v30; // [esp+3618h] [ebp-2D8h]
  CStudioHdr pStudioHdr; // [esp+364Ch] [ebp-2A4h] BYREF
  matrix3x4_t matrix; // [esp+36B0h] [ebp-240h] BYREF
  CMeshBuilder v33; // [esp+36E0h] [ebp-210h] BYREF
  float out[3]; // [esp+38C8h] [ebp-28h] BYREF
  int v35; // [esp+38D4h] [ebp-1Ch]
  IMatRenderContext *v36; // [esp+38D8h] [ebp-18h]
  IMDLCache *v37; // [esp+38DCh] [ebp-14h]
  IVPhysicsKeyParser *v38; // [esp+38E0h] [ebp-10h]
  Vector *v39; // [esp+38E4h] [ebp-Ch] BYREF
  CMDLPanel *v40; // [esp+38E8h] [ebp-8h]
  int v41; // [esp+38ECh] [ebp-4h]

  v40 = this;
  v2 = vgui::MDLCache();
  v3 = v2->__vftable;
  p_m_RootMDL = &this->m_RootMDL;
  MDL = CMDL::GetMDL(this: &p_m_RootMDL->m_MDL);
  v6 = (IMDLCache *)v3->GetVCollide(this: v2, a2: MDL);
  v37 = v6;
  if ( v6 != nullptr && ((int)v6->__vftable & 0x7FFF) != 0 )
  {
    v27 = v6;
    v7 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *))g_pPhysicsCollision->VPhysicsKeyParserCreate)(a1: g_pPhysicsCollision);
    v8 = g_pMDLCache->__vftable;
    v26 = g_pMDLCache;
    v38 = v7;
    v9 = CMDL::GetMDL(this: &p_m_RootMDL->m_MDL);
    v10 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, IMDLCache *))v8->GetStudioHdr)(
                                 a1: g_pMDLCache,
                                 a2: v9,
                                 a3: v26);
    CStudioHdr::CStudioHdr(this: &pStudioHdr, pStudioHdr: v10, mdlcache: v27);
    CMDL::SetUpBones(
      this: &p_m_RootMDL->m_MDL,
      rootToWorld: &v40->m_RootMDL.m_MDLToWorld,
      nMaxBoneCount: 256,
      pBoneToWorld,
      pPoseParameters: nullptr,
      pSequenceLayers: nullptr,
      nNumSequenceLayers: 0);
    while ( !v7->Finished(this: v7) )
    {
      v11 = v7->GetCurrentBlockName(this: v7);
      v12 = _V_stricmp(s1: v11, s2: "solid");
      v13 = v7->__vftable;
      if ( v12 != 0 )
      {
        v13->SkipBlock(this: v7);
      }
      else
      {
        v13->ParseSolid(this: v7, a2: (solid_t *)pName, a3: nullptr);
        v14 = Studio_BoneIndexByName(&pStudioHdr, pName);
        CreateDebugMesh = g_pPhysicsCollision->CreateDebugMesh;
        v35 = v14;
        v16 = CreateDebugMesh(
                this: g_pPhysicsCollision,
                a2: *((const struct CPhysCollide **)&v37[1].Connect + v30),
                a3: &v39);
        v41 = v16;
        if ( v16 != 0 )
        {
          v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
          v36 = v17;
          if ( v17 != nullptr )
            v17->BeginRender(this: v17);
          v17->CullMode(this: v17, a2: MATERIAL_CULLMODE_CCW);
          SetIdentityMatrix(&matrix);
          if ( v35 >= 0 )
            MatrixCopy(in: &pBoneToWorld[v35], out: &matrix);
          v18 = v17->GetDynamicMesh(this: v17, a2: true, a3: nullptr, a4: nullptr, a5: v40->m_Wireframe.m_pMaterial);
          CMeshBuilder::CMeshBuilder(this: &v33);
          v33.m_pMesh = v18;
          v33.m_bGenerateIndices = true;
          v33.m_Type = MATERIAL_TRIANGLES;
          v19 = 3 * (v16 / 3);
          v18->SetPrimitiveType(this: v18, a2: MATERIAL_TRIANGLES);
          v33.m_pMesh->LockMesh(this: v33.m_pMesh, a2: v19, a3: v19, a4: &v33, a5: nullptr);
          v33.m_IndexBuilder.m_pIndices = v33.m_pIndices;
          v33.m_IndexBuilder.m_nIndexOffset = v33.m_nFirstVertex;
          v33.m_IndexBuilder.m_pIndexBuffer = &v18->IIndexBuffer;
          v33.m_IndexBuilder.m_nIndexSize = v33.m_nIndexSize;
          v33.m_IndexBuilder.m_nIndexCount = 0;
          v33.m_IndexBuilder.m_nMaxIndexCount = v19;
          v33.m_IndexBuilder.m_bModify = false;
          v33.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::AttachBegin(this: &v33.m_VertexBuilder, pMesh: v18, nMaxVertexCount: v19, desc: &v33);
          v20 = 0;
          v33.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::Reset(this: &v33.m_VertexBuilder);
          if ( v41 > 0 )
          {
            for ( i = v41; i != 0; --i )
            {
              VectorTransform(in1: &v39[v20].x, in2: &matrix, out);
              m_pCurrPosition = v33.m_VertexBuilder.m_pCurrPosition;
              a = color.a;
              *v33.m_VertexBuilder.m_pCurrPosition = out[0];
              m_pCurrPosition[1] = out[1];
              m_pCurrPosition[2] = out[2];
              *(_DWORD *)v33.m_VertexBuilder.m_pCurrColor = color.b | ((color.g | ((color.r | (a << 8)) << 8)) << 8);
              v24 = v33.m_VertexBuilder.m_pCurrTexCoord[0];
              *v33.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
              v24[1] = 0.0;
              CVertexBuilder::AdvanceVertex(this: &v33.m_VertexBuilder);
              ++v20;
            }
            v17 = v36;
          }
          if ( v33.m_bGenerateIndices )
          {
            switch ( v33.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * v33.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * v33.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * v33.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * v33.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = v33.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &v33.m_IndexBuilder,
              primitiveType: v33.m_Type,
              nIndexCount: m_nVertexCount);
          }
          v33.m_pMesh->UnlockMesh(
            this: v33.m_pMesh,
            a2: v33.m_VertexBuilder.m_nVertexCount,
            a3: v33.m_IndexBuilder.m_nIndexCount,
            a4: &v33);
          v33.m_IndexBuilder.m_pIndexBuffer = nullptr;
          v33.m_IndexBuilder.m_nMaxIndexCount = 0;
          v33.m_VertexBuilder.m_nMaxVertexCount = 0;
          v33.m_VertexBuilder.m_pVertexBuffer = nullptr;
          v33.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          v33.m_pMesh = nullptr;
          v18->Draw_2(this: v18, a2: -1, a3: 0);
          if ( v33.m_VertexBuilder.m_pVertexBuffer != nullptr
            && v33.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v33.m_VertexBuilder.m_pVertexBuffer) )
          {
            v33.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v33.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( v33.m_IndexBuilder.m_pIndexBuffer != nullptr
            && v33.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v33.m_IndexBuilder.m_pIndexBuffer) )
          {
            v33.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v33.m_IndexBuilder.m_pIndexBuffer);
          }
          v17->EndRender(this: v17);
          v17->Release(this: v17);
          v7 = v38;
          v16 = v41;
        }
        g_pPhysicsCollision->DestroyDebugMesh(this: g_pPhysicsCollision, a2: v16, a3: v39);
      }
    }
    g_pPhysicsCollision->VPhysicsKeyParserDestroy(this: g_pPhysicsCollision, a2: v7);
    CStudioHdr::Term(this: &pStudioHdr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&pStudioHdr.m_boneParent);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&pStudioHdr.m_boneFlags);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&pStudioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C9E90
// Name: private: virtual void CMDLPanel::OnPaint3D(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPanel::OnPaint3D(CMDLPanel *this@<ecx>, int a2@<ebx>, IMDLCache *a3@<edi>)
{
  IStudioRender *v4; // eax
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // ebx
  IMaterialSystemHardwareConfig *v8; // eax
  ITexture *LightProbeCubemap; // eax
  float x; // xmm0_4
  IMDLCache_vtbl *v11; // edi
  unsigned __int16 MDL; // ax
  const studiohdr_t *v13; // eax
  matrix3x4_t *v14; // eax
  float v15; // edi
  int v16; // ebx
  IMDLCache_vtbl *v17; // edi
  unsigned __int16 v18; // ax
  const studiohdr_t *v19; // eax
  int *m_pMemory; // eax
  int *v21; // eax
  const studiohdr_t **v22; // eax
  IStudioRender *v23; // eax
  int *v24; // eax
  int *v25; // eax
  const studiohdr_t **v26; // eax
  int numbones; // [esp-18h] [ebp-3168h]
  IMDLCache *v28; // [esp-8h] [ebp-3158h]
  int m_nNumSequenceLayers; // [esp-8h] [ebp-3158h]
  IMDLCache *v30; // [esp-8h] [ebp-3158h]
  matrix3x4_t pMergeBoneToWorld; // [esp+4h] [ebp-314Ch] BYREF
  StudioRenderConfig_t v33; // [esp+3004h] [ebp-14Ch] BYREF
  matrix3x4_t pWorldToCamera; // [esp+303Ch] [ebp-114h] BYREF
  CStudioHdr pMergeHdr; // [esp+306Ch] [ebp-E4h] BYREF
  CStudioHdr pFollow; // [esp+30D0h] [ebp-80h] BYREF
  Vector out; // [esp+3138h] [ebp-18h] BYREF
  int v38; // [esp+3144h] [ebp-Ch]
  int v39; // [esp+3148h] [ebp-8h]
  int m_Size; // [esp+314Ch] [ebp-4h]

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v4 = vgui::StudioRender();
    ((void (__thiscall *)(IStudioRender *, StudioRenderConfig_t *, int))v4->GetCurrentConfig)(a1: v4, a2: &v33, a3: a2);
    CMDLPanel::UpdateStudioRenderConfig(this);
    v5 = vgui::MaterialSystem();
    v6 = (int)v5->GetRenderContext(this: v5);
    v7 = v6;
    v38 = v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v7 + 464))(a1: v7, a2: 10, a3: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 336))(a1: v7, a2: 0);
    v39 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 520))(a1: v7);
    v8 = vgui::MaterialSystemHardwareConfig();
    if ( v8->GetHDRType(this: v8) != HDR_TYPE_NONE )
    {
      if ( CPotteryWheelPanel::HasLightProbe(this) )
        LightProbeCubemap = CPotteryWheelPanel::GetLightProbeCubemap(this, bHDR: true);
      else
        LightProbeCubemap = this->m_DefaultHDREnvCubemap.m_pTexture;
    }
    else if ( CPotteryWheelPanel::HasLightProbe(this) )
    {
      LightProbeCubemap = CPotteryWheelPanel::GetLightProbeCubemap(this, bHDR: false);
    }
    else
    {
      LightProbeCubemap = this->m_DefaultEnvCubemap.m_pTexture;
    }
    (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v7 + 20))(a1: v7, a2: LightProbeCubemap);
    if ( (*((_BYTE *)this + 2876) & 2) != 0 )
      CPotteryWheelPanel::DrawGrid(this);
    if ( (*((_BYTE *)this + 2876) & 0x10) != 0 )
    {
      CPotteryWheelPanel::ComputeCameraTransform(this, &pWorldToCamera);
      MatrixGetColumn(in: &pWorldToCamera, column: 3, &out);
      x = out.x;
      this->m_RootMDL.m_MDL.m_bWorldSpaceViewTarget = true;
      this->m_RootMDL.m_MDL.m_vecViewTarget.x = x;
      this->m_RootMDL.m_MDL.m_vecViewTarget.y = out.y;
      this->m_RootMDL.m_MDL.m_vecViewTarget.z = out.z;
    }
    v11 = g_pMDLCache->__vftable;
    v28 = g_pMDLCache;
    MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
    v13 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, IMDLCache *))v11->GetStudioHdr)(
                                 a1: g_pMDLCache,
                                 a2: MDL,
                                 a3: v28);
    CStudioHdr::CStudioHdr(this: &pFollow, pStudioHdr: v13, mdlcache: a3);
    v14 = (matrix3x4_t *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 392))(
                           a1: v7,
                           a2: 48 * pFollow.m_pStudioHdr->numbones);
    m_nNumSequenceLayers = this->m_nNumSequenceLayers;
    v15 = *(float *)&v14;
    numbones = pFollow.m_pStudioHdr->numbones;
    LODWORD(out.x) = v14;
    CMDL::SetUpBones(
      this: &this->m_RootMDL.m_MDL,
      rootToWorld: &this->m_RootMDL.m_MDLToWorld,
      nMaxBoneCount: numbones,
      pBoneToWorld: v14,
      pPoseParameters: this->m_PoseParameters,
      pSequenceLayers: this->m_SequenceLayers,
      nNumSequenceLayers: m_nNumSequenceLayers);
    CMDL::Draw(
      this: &this->m_RootMDL.m_MDL,
      rootToWorld: &this->m_RootMDL.m_MDLToWorld,
      pBoneToWorld: (const matrix3x4_t *)LODWORD(v15),
      flags: 32);
    if ( this->m_aMergeMDLs.m_Size > 0 )
    {
      v16 = 0;
      m_Size = this->m_aMergeMDLs.m_Size;
      do
      {
        v17 = g_pMDLCache->__vftable;
        v30 = g_pMDLCache;
        v18 = CMDL::GetMDL(this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL);
        v19 = v17->GetStudioHdr(this: g_pMDLCache, a2: v18);
        CStudioHdr::CStudioHdr(this: &pMergeHdr, pStudioHdr: v19, mdlcache: v30);
        CMDL::SetupBonesWithBoneMerge(
          this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL,
          &pMergeHdr,
          &pMergeBoneToWorld,
          &pFollow,
          pFollowBoneToWorld: (const matrix3x4_t *)LODWORD(out.x),
          matModelToWorld: &this->m_RootMDL.m_MDLToWorld);
        CMDL::Draw(
          this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL,
          rootToWorld: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDLToWorld,
          pBoneToWorld: &pMergeBoneToWorld,
          flags: 32);
        CStudioHdr::Term(this: &pMergeHdr);
        m_pMemory = pMergeHdr.m_boneParent.m_Memory.m_pMemory;
        pMergeHdr.m_boneParent.m_Size = 0;
        if ( pMergeHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_boneParent.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            pMergeHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_boneParent.m_pElements = m_pMemory;
        if ( pMergeHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            pMergeHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
        }
        v21 = pMergeHdr.m_boneFlags.m_Memory.m_pMemory;
        pMergeHdr.m_boneFlags.m_Size = 0;
        if ( pMergeHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_boneFlags.m_Memory.m_pMemory);
            v21 = nullptr;
            pMergeHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_boneFlags.m_pElements = v21;
        if ( pMergeHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v21 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
            pMergeHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
        }
        v22 = pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
        pMergeHdr.m_pStudioHdrCache.m_Size = 0;
        if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
            v22 = nullptr;
            pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_pStudioHdrCache.m_pElements = v22;
        if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v22 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        ++v16;
        --m_Size;
      }
      while ( m_Size != 0 );
      v7 = v38;
      v15 = out.x;
    }
    if ( v15 != 0.0 )
      (*(void (__thiscall **)(int, float))(*(_DWORD *)v7 + 396))(a1: v7, a2: COERCE_FLOAT(LODWORD(v15)));
    if ( (*((_BYTE *)this + 2876) & 1) != 0 )
      CMDLPanel::DrawCollisionModel(this);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 16))(a1: v7, a2: 0);
    v23 = vgui::StudioRender();
    v23->UpdateConfig(this: v23, a2: &v33);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 20))(a1: v7, a2: v39);
    CStudioHdr::Term(this: &pFollow);
    v24 = pFollow.m_boneParent.m_Memory.m_pMemory;
    pFollow.m_boneParent.m_Size = 0;
    if ( pFollow.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_boneParent.m_Memory.m_pMemory);
        v24 = nullptr;
        pFollow.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_boneParent.m_pElements = v24;
    if ( pFollow.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v24 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
        pFollow.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v25 = pFollow.m_boneFlags.m_Memory.m_pMemory;
    pFollow.m_boneFlags.m_Size = 0;
    if ( pFollow.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_boneFlags.m_Memory.m_pMemory);
        v25 = nullptr;
        pFollow.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_boneFlags.m_pElements = v25;
    if ( pFollow.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v25 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
        pFollow.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v26 = pFollow.m_pStudioHdrCache.m_Memory.m_pMemory;
    pFollow.m_pStudioHdrCache.m_Size = 0;
    if ( pFollow.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_pStudioHdrCache.m_Memory.m_pMemory);
        v26 = nullptr;
        pFollow.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_pStudioHdrCache.m_pElements = v26;
    if ( pFollow.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v26 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
        pFollow.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CA3A0
// Name: public: void CMDLPanel::SetPoseParameters(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetPoseParameters(CMDLPanel *this, const float *pPoseParameters, int nCount)
{
  int v4; // edi
  int v5; // esi
  float *v6; // eax
  unsigned int v7; // edx
  const float *v8; // ecx
  float *v9; // eax
  double v10; // st7
  IMDLCache_vtbl *v11; // ebx
  unsigned __int16 MDL; // ax
  const studiohdr_t *v13; // eax
  IMDLCache *v14; // [esp-4h] [ebp-78h]
  CStudioHdr studioHdr; // [esp+Ch] [ebp-68h] BYREF
  CMDLPanel *v16; // [esp+70h] [ebp-4h]

  v16 = this;
  if ( pPoseParameters != nullptr )
  {
    v4 = nCount;
    if ( nCount > 24 )
      v4 = 24;
    v5 = 0;
    if ( v4 >= 4 )
    {
      v6 = &v16->m_PoseParameters[1];
      v7 = ((unsigned int)(v4 - 4) >> 2) + 1;
      v8 = pPoseParameters + 2;
      v5 = 4 * v7;
      do
      {
        v6 += 4;
        *(v6 - 5) = *(v8 - 2);
        v8 += 4;
        --v7;
        *(v6 - 4) = *(v8 - 5);
        *(v6 - 3) = *(v8 - 4);
        *(v6 - 2) = *(v8 - 3);
      }
      while ( v7 != 0 );
    }
    if ( v5 < v4 )
    {
      v9 = &v16->m_PoseParameters[v5];
      do
      {
        v10 = pPoseParameters[v5++];
        *v9++ = v10;
      }
      while ( v5 < v4 );
    }
  }
  else if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v11 = g_pMDLCache->__vftable;
    v14 = g_pMDLCache;
    MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
    v13 = v11->GetStudioHdr(this: g_pMDLCache, a2: MDL);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v13, mdlcache: v14);
    Studio_CalcDefaultPoseParameters(pStudioHdr: &studioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
    CStudioHdr::Term(this: &studioHdr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneParent);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneFlags);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CA4B0
// Name: Create_CMDLPanel
// Source: json
//------------------------------------------------------------------------------
CMDLPanel *__cdecl Create_CMDLPanel()
{
  CMDLPanel *v0; // eax

  v0 = (CMDLPanel *)MemAlloc_Alloc(nSize: 0xBE4u);
  if ( v0 != nullptr )
    return CMDLPanel::CMDLPanel(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004CA500
// Name: public: virtual void CMDLPanel::SetMDL(unsigned short,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, unsigned __int16 handle, void *pProxyData)
{
  int m_nSequence; // [esp-4h] [ebp-24h]
  Vector vecMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_RootMDL.m_MDL, h: handle);
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  this->m_RootMDL.m_MDL.m_pProxyData = pProxyData;
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: handle, nSequence: m_nSequence);
  this->m_RootMDL.m_MDL.m_bWorldSpaceViewTarget = false;
  this->m_RootMDL.m_MDL.m_vecViewTarget.x = 100.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.y = 0.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.z = vecMaxs.z;
  CMDLPanel::SetPoseParameters(this, pPoseParameters: nullptr, nCount: 0);
  this->m_nNumSequenceLayers = 0;
  _V_memset(dest: this->m_SequenceLayers, fill: 0, count: 64);
}

//------------------------------------------------------------------------------
// Address: 0x005DB7F0
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10212630
// Name: public: static char const __near * CMDLPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPanel::GetPanelClassName()
{
  return "CMDLPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10212640
// Name: public: virtual void CMDLPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::ApplySchemeSettings(CMDLPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  const Color *v4; // eax
  CMDLPanel_vtbl *v5; // ebx
  int v6; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->GetBgColor(this, result: &pScheme);
  CPotteryWheelPanel::SetBackgroundColor(this, c: v4);
  v5 = this->__vftable;
  v6 = (int)v2->GetBorder(this: v2, a2: "MenuBorder");
  v5->SetBorder(this, a2: (vgui::IBorder *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x10212690
// Name: public: void CMDLPanel::SetCollsionModel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetCollsionModel(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (bVisible ^ *((_BYTE *)this + 2876)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x102126B0
// Name: public: void CMDLPanel::SetGroundGrid(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetGroundGrid(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (2 * bVisible)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x102126D0
// Name: public: void CMDLPanel::SetWireFrame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetWireFrame(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (8 * bVisible)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x102126F0
// Name: public: void CMDLPanel::SetLockView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetLockView(CMDLPanel *this, bool bLocked)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (4 * bLocked)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x10212710
// Name: public: void CMDLPanel::SetLookAtCamera(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetLookAtCamera(CMDLPanel *this, bool bLookAtCamera)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (16 * bLookAtCamera)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x10212730
// Name: public: virtual void CMDLPanel::SetMDL(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, const char *pMDLName, void *pProxyData)
{
  IMDLCache *v4; // eax
  int v5; // esi
  IMDLCache *v6; // eax

  if ( pMDLName != nullptr )
  {
    v4 = vgui::MDLCache();
    v5 = v4->FindMDL(this: v4, a2: pMDLName);
  }
  else
  {
    v5 = 0xFFFF;
  }
  v6 = vgui::MDLCache();
  if ( v6->IsErrorModel(this: v6, a2: v5) )
    v5 = 0xFFFF;
  this->SetMDL_2(this, a2: v5, a3: pProxyData);
}

//------------------------------------------------------------------------------
// Address: 0x10212790
// Name: public: bool CMDLPanel::GetBoundingSphere(class Vector __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLPanel::GetBoundingSphere(CMDLPanel *this, Vector *vecCenter, float *flRadius)
{
  unsigned __int16 MDL; // ax
  int m_nSequence; // [esp-4h] [ebp-18h]
  Vector vecEngineCenter; // [esp+8h] [ebp-Ch] BYREF

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) == 0xFFFF )
    return 0;
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
  GetMDLBoundingSphere(pVecCenter: &vecEngineCenter, pRadius: flRadius, h: MDL, nSequence: m_nSequence);
  VectorTransform(in1: &vecEngineCenter.x, in2: &this->m_RootMDL.m_MDLToWorld, out: &vecCenter->x);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10212800
// Name: public: void CMDLPanel::LookAtMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::LookAtMDL(CMDLPanel *this)
{
  Vector vecCenter; // [esp+4h] [ebp-10h] BYREF
  float v3; // [esp+10h] [ebp-4h] BYREF

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF && (*((_BYTE *)this + 2876) & 4) == 0 )
  {
    CMDLPanel::GetBoundingSphere(this, &vecCenter, flRadius: &v3);
    CPotteryWheelPanel::LookAt(this, &vecCenter, flRadius: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212860
// Name: public: void CMDLPanel::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSequence(CMDLPanel *this, int nSequence)
{
  this->m_RootMDL.m_MDL.m_nSequence = nSequence;
}

//------------------------------------------------------------------------------
// Address: 0x10212870
// Name: public: void CMDLPanel::SetSequenceLayers(struct MDLSquenceLayer_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSequenceLayers(CMDLPanel *this, const MDLSquenceLayer_t *pSequenceLayers, int nCount)
{
  const MDLSquenceLayer_t *v3; // eax
  int v4; // esi
  int v5; // edx
  MDLSquenceLayer_t *m_SequenceLayers; // edx

  v3 = pSequenceLayers;
  v4 = 0;
  if ( pSequenceLayers != nullptr )
  {
    v5 = nCount;
    if ( nCount > 8 )
      v5 = 8;
    this->m_nNumSequenceLayers = v5;
    if ( v5 > 0 )
    {
      m_SequenceLayers = this->m_SequenceLayers;
      do
      {
        m_SequenceLayers->m_nSequenceIndex = v3->m_nSequenceIndex;
        m_SequenceLayers->m_flWeight = v3->m_flWeight;
        ++v4;
        ++v3;
        ++m_SequenceLayers;
      }
      while ( v4 < this->m_nNumSequenceLayers );
    }
  }
  else
  {
    this->m_nNumSequenceLayers = 0;
    _V_memset(dest: this->m_SequenceLayers, fill: 0, count: 64);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102128E0
// Name: public: void CMDLPanel::SetSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSkin(CMDLPanel *this, int nSkin)
{
  this->m_RootMDL.m_MDL.m_nSkin = nSkin;
}

//------------------------------------------------------------------------------
// Address: 0x102128F0
// Name: public: virtual void CMDLPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10212950
// Name: private: virtual void CMDLPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::OnMouseDoublePressed(CMDLPanel *this, ButtonCode_t code)
{
  Vector vecCenter; // [esp+4h] [ebp-10h] BYREF
  float v4; // [esp+10h] [ebp-4h] BYREF

  CMDLPanel::GetBoundingSphere(this, &vecCenter, flRadius: &v4);
  CPotteryWheelPanel::LookAt(this, &vecCenter, flRadius: v4);
  CPotteryWheelPanel::OnMouseDoublePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x10212990
// Name: private: void CMDLPanel::UpdateStudioRenderConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::UpdateStudioRenderConfig(CMDLPanel *this)
{
  int m_nValue; // eax
  char v3; // al
  char v4; // al
  int v5; // ecx
  char v6; // al
  int v7; // ecx
  char v8; // al
  int v9; // ecx
  char v10; // al
  int v11; // ecx
  char v12; // al
  int v13; // ecx
  int v14; // eax
  char v15; // al
  int v16; // ecx
  char v17; // al
  int v18; // ecx
  IStudioRender *v19; // eax

  memset(dst: (unsigned __int8 *)&s_StudioRenderConfig, value: 0, count: sizeof(s_StudioRenderConfig));
  if ( r_eyemove.m_pParent != nullptr )
    m_nValue = r_eyemove.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = (*((_BYTE *)&s_StudioRenderConfig + 36) ^ (m_nValue != 0)) & 1 ^ *((_BYTE *)&s_StudioRenderConfig + 36);
  *((_BYTE *)&s_StudioRenderConfig + 36) = v3;
  s_StudioRenderConfig.fEyeShiftX = r_eyeshift_x.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftY = r_eyeshift_y.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftZ = r_eyeshift_z.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeSize = r_eyesize.m_pParent->m_Value.m_fValue;
  if ( mat_softwareskin.m_pParent != nullptr && mat_softwareskin.m_pParent->m_Value.m_nValue != 0
    || (*((_BYTE *)this + 2876) & 8) != 0 )
  {
    v4 = v3 | 2;
  }
  else
  {
    v4 = v3 & 0xFD;
  }
  *((_BYTE *)&s_StudioRenderConfig + 36) = v4;
  if ( r_nohw.m_pParent != nullptr )
    v5 = r_nohw.m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  v6 = (v4 ^ (4 * (v5 != 0))) & 4 ^ v4;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v6;
  if ( r_nosw.m_pParent != nullptr )
    v7 = r_nosw.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  v8 = (v6 ^ (8 * (v7 != 0))) & 8 ^ v6;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v8;
  if ( r_teeth.m_pParent != nullptr )
    v9 = r_teeth.m_pParent->m_Value.m_nValue;
  else
    v9 = 0;
  v10 = (v8 ^ (16 * (v9 != 0))) & 0x10 ^ v8;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v10;
  if ( r_drawentities.m_pParent != nullptr )
    s_StudioRenderConfig.drawEntities = r_drawentities.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.drawEntities = 0;
  if ( r_flex.m_pParent != nullptr )
    v11 = r_flex.m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  v12 = (v10 ^ ((v11 != 0) << 6)) & 0x40 ^ v10;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v12;
  if ( r_eyes.m_pParent != nullptr )
    v13 = r_eyes.m_pParent->m_Value.m_nValue;
  else
    v13 = 0;
  *((_BYTE *)&s_StudioRenderConfig + 36) = (v12 ^ (32 * (v13 != 0))) & 0x20 ^ v12;
  *((_BYTE *)&s_StudioRenderConfig + 36) = (16 * *((_BYTE *)this + 2876))
                                         ^ (*((_BYTE *)&s_StudioRenderConfig + 36)
                                          ^ (16 * *((_BYTE *)this + 2876)))
                                         & 0x7F;
  if ( mat_normals.m_pParent != nullptr )
    v14 = mat_normals.m_pParent->m_Value.m_nValue;
  else
    v14 = 0;
  v15 = (*((_BYTE *)&s_StudioRenderConfig + 37) ^ (v14 != 0)) & 1 ^ *((_BYTE *)&s_StudioRenderConfig + 37);
  *((_BYTE *)&s_StudioRenderConfig + 37) = v15;
  if ( r_skin.m_pParent != nullptr )
    s_StudioRenderConfig.skin = r_skin.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.skin = 0;
  if ( r_maxmodeldecal.m_pParent != nullptr )
    s_StudioRenderConfig.maxDecalsPerModel = r_maxmodeldecal.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.maxDecalsPerModel = 0;
  if ( r_modelwireframedecal.m_pParent != nullptr )
    v16 = r_modelwireframedecal.m_pParent->m_Value.m_nValue;
  else
    v16 = 0;
  v17 = ((v15 ^ (32 * (v16 != 0))) & 0x20 ^ v15) & 0xF7;
  s_StudioRenderConfig.fullbright = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = v17;
  if ( r_showenvcubemap.m_pParent != nullptr )
    v18 = r_showenvcubemap.m_pParent->m_Value.m_nValue;
  else
    v18 = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = (v17 ^ (16 * (v18 != 0))) & 0x10 ^ v17;
  s_StudioRenderConfig.fEyeGlintPixelWidthLODThreshold = r_eyeglintlodpixels.m_pParent->m_Value.m_fValue;
  v19 = vgui::StudioRender();
  v19->UpdateConfig(this: v19, a2: &s_StudioRenderConfig);
}

//------------------------------------------------------------------------------
// Address: 0x10212CD0
// Name: public: CMDLPanel::CMDLPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMDLPanel *__thiscall CMDLPanel::CMDLPanel(CMDLPanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  IMaterialSystem *v7; // eax
  ITexture *v8; // eax
  IMaterialSystem *v9; // eax
  ITexture *v10; // eax

  CPotteryWheelPanel::CPotteryWheelPanel(this, pParent, pName);
  this->__vftable = (CMDLPanel_vtbl *)&CMDLPanel::`vftable';
  if ( `CMDLPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
    v4->pfnClassName = CMDLPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  }
  if ( `CMDLPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMDLPanel");
    v5->pfnClassName = CMDLPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
  }
  if ( `CMDLPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
    v6->pfnClassName = CMDLPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  }
  CMDL::CMDL(this: &this->m_RootMDL.m_MDL);
  this->m_aMergeMDLs.m_Memory.m_pMemory = nullptr;
  this->m_aMergeMDLs.m_Memory.m_nAllocationCount = 0;
  this->m_aMergeMDLs.m_Memory.m_nGrowSize = 0;
  this->m_aMergeMDLs.m_Size = 0;
  this->m_aMergeMDLs.m_pElements = nullptr;
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  vgui::Panel::SetVisible(this, state: 1);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  v7 = vgui::MaterialSystem();
  v8 = v7->FindTexture(this: v7, a2: "editor/cubemap", a3: nullptr, a4: true, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultEnvCubemap, pTexture: v8);
  v9 = vgui::MaterialSystem();
  v10 = v9->FindTexture(this: v9, a2: "editor/cubemap.hdr", a3: nullptr, a4: true, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultHDREnvCubemap, pTexture: v10);
  SetIdentityMatrix(matrix: &this->m_RootMDL.m_MDLToWorld);
  *((_BYTE *)this + 2876) = *((_BYTE *)this + 2876) & 0xE0 | 0x10;
  this->m_nNumSequenceLayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10212E60
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPanel::GetMessageMap(CMDLPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetMessageMap'::`2'::s_pMap;
  `CMDLPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
  `CMDLPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10212E90
// Name: public: virtual struct PanelAnimationMap __near * CMDLPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPanel::GetAnimMap(CMDLPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10212EA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPanel::GetKBMap(CMDLPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetKBMap'::`2'::s_pMap;
  `CMDLPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
  `CMDLPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10212ED0
// Name: public: virtual CMDLPanel::~CMDLPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::~CMDLPanel(CMDLPanel *this)
{
  this->__vftable = (CMDLPanel_vtbl *)&CMDLPanel::`vftable';
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  CTextureReference::Shutdown(this: &this->m_DefaultEnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &this->m_DefaultHDREnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::~CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  if ( this->m_aMergeMDLs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aMergeMDLs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aMergeMDLs.m_Memory.m_pMemory);
      this->m_aMergeMDLs.m_Memory.m_pMemory = nullptr;
    }
    this->m_aMergeMDLs.m_Memory.m_nAllocationCount = 0;
  }
  CMDL::~CMDL(this: &this->m_RootMDL.m_MDL);
  CPotteryWheelPanel::~CPotteryWheelPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10212F70
// Name: private: void CMDLPanel::DrawCollisionModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::DrawCollisionModel(CMDLPanel *this)
{
  IMDLCache *v2; // edi
  IMDLCache_vtbl *v3; // esi
  CMDLPanel::MDLData_t *p_m_RootMDL; // ebx
  unsigned __int16 MDL; // ax
  IMDLCache *v6; // eax
  IVPhysicsKeyParser *v7; // esi
  IMDLCache_vtbl *v8; // edi
  unsigned __int16 v9; // ax
  const studiohdr_t *v10; // eax
  const char *v11; // eax
  int v12; // eax
  IVPhysicsKeyParser_vtbl *v13; // edx
  int v14; // eax
  int (__thiscall *CreateDebugMesh)(IPhysicsCollision *, const struct CPhysCollide *, Vector **); // edx
  int v16; // edi
  IMatRenderContext *v17; // ebx
  IMesh *v18; // esi
  int v19; // edi
  int v20; // edi
  int i; // ebx
  float *m_pCurrPosition; // eax
  int a; // ecx
  float *v24; // eax
  int m_nVertexCount; // eax
  IMDLCache *v26; // [esp-8h] [ebp-38F8h]
  IMDLCache *v27; // [esp-4h] [ebp-38F4h]
  matrix3x4_t pBoneToWorld[256]; // [esp+Ch] [ebp-38E4h] BYREF
  char pName[1548]; // [esp+300Ch] [ebp-8E4h] BYREF
  int v30; // [esp+3618h] [ebp-2D8h]
  CStudioHdr pStudioHdr; // [esp+364Ch] [ebp-2A4h] BYREF
  matrix3x4_t matrix; // [esp+36B0h] [ebp-240h] BYREF
  CMeshBuilder v33; // [esp+36E0h] [ebp-210h] BYREF
  float out[3]; // [esp+38C8h] [ebp-28h] BYREF
  int v35; // [esp+38D4h] [ebp-1Ch]
  IMatRenderContext *v36; // [esp+38D8h] [ebp-18h]
  IMDLCache *v37; // [esp+38DCh] [ebp-14h]
  IVPhysicsKeyParser *v38; // [esp+38E0h] [ebp-10h]
  Vector *v39; // [esp+38E4h] [ebp-Ch] BYREF
  CMDLPanel *v40; // [esp+38E8h] [ebp-8h]
  int v41; // [esp+38ECh] [ebp-4h]

  v40 = this;
  v2 = vgui::MDLCache();
  v3 = v2->__vftable;
  p_m_RootMDL = &this->m_RootMDL;
  MDL = CMDL::GetMDL(this: &p_m_RootMDL->m_MDL);
  v6 = (IMDLCache *)v3->GetVCollide(this: v2, a2: MDL);
  v37 = v6;
  if ( v6 != nullptr && ((int)v6->__vftable & 0x7FFF) != 0 )
  {
    v27 = v6;
    v7 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *))g_pPhysicsCollision->VPhysicsKeyParserCreate)(a1: g_pPhysicsCollision);
    v8 = g_pMDLCache->__vftable;
    v26 = g_pMDLCache;
    v38 = v7;
    v9 = CMDL::GetMDL(this: &p_m_RootMDL->m_MDL);
    v10 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, IMDLCache *))v8->GetStudioHdr)(
                                 a1: g_pMDLCache,
                                 a2: v9,
                                 a3: v26);
    CStudioHdr::CStudioHdr(this: &pStudioHdr, pStudioHdr: v10, mdlcache: v27);
    CMDL::SetUpBones(
      this: &p_m_RootMDL->m_MDL,
      rootToWorld: &v40->m_RootMDL.m_MDLToWorld,
      nMaxBoneCount: 256,
      pBoneToWorld,
      pPoseParameters: nullptr,
      pSequenceLayers: nullptr,
      nNumSequenceLayers: 0);
    while ( !v7->Finished(this: v7) )
    {
      v11 = v7->GetCurrentBlockName(this: v7);
      v12 = _V_stricmp(s1: v11, s2: "solid");
      v13 = v7->__vftable;
      if ( v12 != 0 )
      {
        v13->SkipBlock(this: v7);
      }
      else
      {
        v13->ParseSolid(this: v7, a2: (solid_t *)pName, a3: nullptr);
        v14 = Studio_BoneIndexByName((mstudiobone_t *)&pStudioHdr, pName);
        CreateDebugMesh = g_pPhysicsCollision->CreateDebugMesh;
        v35 = v14;
        v16 = CreateDebugMesh(
                this: g_pPhysicsCollision,
                a2: *((const struct CPhysCollide **)&v37[1].Connect + v30),
                a3: &v39);
        v41 = v16;
        if ( v16 != 0 )
        {
          v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
          v36 = v17;
          if ( v17 != nullptr )
            v17->BeginRender(this: v17);
          v17->CullMode(this: v17, a2: MATERIAL_CULLMODE_CCW);
          SetIdentityMatrix(&matrix);
          if ( v35 >= 0 )
            MatrixCopy(in: &pBoneToWorld[v35], out: &matrix);
          v18 = v17->GetDynamicMesh(this: v17, a2: true, a3: nullptr, a4: nullptr, a5: v40->m_Wireframe.m_pMaterial);
          CMeshBuilder::CMeshBuilder(this: &v33);
          v33.m_pMesh = v18;
          v33.m_bGenerateIndices = true;
          v33.m_Type = MATERIAL_TRIANGLES;
          v19 = 3 * (v16 / 3);
          v18->SetPrimitiveType(this: v18, a2: MATERIAL_TRIANGLES);
          v33.m_pMesh->LockMesh(this: v33.m_pMesh, a2: v19, a3: v19, a4: &v33, a5: nullptr);
          v33.m_IndexBuilder.m_pIndices = v33.m_pIndices;
          v33.m_IndexBuilder.m_nIndexOffset = v33.m_nFirstVertex;
          v33.m_IndexBuilder.m_pIndexBuffer = &v18->IIndexBuffer;
          v33.m_IndexBuilder.m_nIndexSize = v33.m_nIndexSize;
          v33.m_IndexBuilder.m_nIndexCount = 0;
          v33.m_IndexBuilder.m_nMaxIndexCount = v19;
          v33.m_IndexBuilder.m_bModify = false;
          v33.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::AttachBegin(this: &v33.m_VertexBuilder, pMesh: v18, nMaxVertexCount: v19, desc: &v33);
          v20 = 0;
          v33.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::Reset(this: &v33.m_VertexBuilder);
          if ( v41 > 0 )
          {
            for ( i = v41; i != 0; --i )
            {
              VectorTransform(in1: &v39[v20].x, in2: &matrix, out);
              m_pCurrPosition = v33.m_VertexBuilder.m_pCurrPosition;
              a = color.a;
              *v33.m_VertexBuilder.m_pCurrPosition = out[0];
              m_pCurrPosition[1] = out[1];
              m_pCurrPosition[2] = out[2];
              *(_DWORD *)v33.m_VertexBuilder.m_pCurrColor = color.b | ((color.g | ((color.r | (a << 8)) << 8)) << 8);
              v24 = v33.m_VertexBuilder.m_pCurrTexCoord[0];
              *v33.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
              v24[1] = 0.0;
              CVertexBuilder::AdvanceVertex(this: &v33.m_VertexBuilder);
              ++v20;
            }
            v17 = v36;
          }
          if ( v33.m_bGenerateIndices )
          {
            switch ( v33.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * v33.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * v33.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * v33.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * v33.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = v33.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &v33.m_IndexBuilder,
              primitiveType: v33.m_Type,
              nIndexCount: m_nVertexCount);
          }
          v33.m_pMesh->UnlockMesh(
            this: v33.m_pMesh,
            a2: v33.m_VertexBuilder.m_nVertexCount,
            a3: v33.m_IndexBuilder.m_nIndexCount,
            a4: &v33);
          v33.m_IndexBuilder.m_pIndexBuffer = nullptr;
          v33.m_IndexBuilder.m_nMaxIndexCount = 0;
          v33.m_VertexBuilder.m_nMaxVertexCount = 0;
          v33.m_VertexBuilder.m_pVertexBuffer = nullptr;
          v33.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          v33.m_pMesh = nullptr;
          v18->Draw_2(this: v18, a2: -1, a3: 0);
          if ( v33.m_VertexBuilder.m_pVertexBuffer != nullptr
            && v33.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v33.m_VertexBuilder.m_pVertexBuffer) )
          {
            v33.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v33.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( v33.m_IndexBuilder.m_pIndexBuffer != nullptr
            && v33.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v33.m_IndexBuilder.m_pIndexBuffer) )
          {
            v33.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v33.m_IndexBuilder.m_pIndexBuffer);
          }
          v17->EndRender(this: v17);
          v17->Release(this: v17);
          v7 = v38;
          v16 = v41;
        }
        g_pPhysicsCollision->DestroyDebugMesh(this: g_pPhysicsCollision, a2: v16, a3: v39);
      }
    }
    g_pPhysicsCollision->VPhysicsKeyParserDestroy(this: g_pPhysicsCollision, a2: v7);
    CStudioHdr::Term(this: &pStudioHdr);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&pStudioHdr.m_boneParent);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&pStudioHdr.m_boneFlags);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&pStudioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213420
// Name: private: virtual void CMDLPanel::OnPaint3D(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPanel::OnPaint3D(CMDLPanel *this@<ecx>, int a2@<ebx>, IMDLCache *a3@<edi>)
{
  IStudioRender *v4; // eax
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // ebx
  IMaterialSystemHardwareConfig *v8; // eax
  ITexture *LightProbeCubemap; // eax
  float x; // xmm0_4
  IMDLCache_vtbl *v11; // edi
  unsigned __int16 MDL; // ax
  const studiohdr_t *v13; // eax
  matrix3x4_t *v14; // eax
  float v15; // edi
  int v16; // ebx
  IMDLCache_vtbl *v17; // edi
  unsigned __int16 v18; // ax
  const studiohdr_t *v19; // eax
  int *m_pMemory; // eax
  int *v21; // eax
  const studiohdr_t **v22; // eax
  IStudioRender *v23; // eax
  int *v24; // eax
  int *v25; // eax
  const studiohdr_t **v26; // eax
  int numbones; // [esp-18h] [ebp-3168h]
  IMDLCache *v28; // [esp-8h] [ebp-3158h]
  int m_nNumSequenceLayers; // [esp-8h] [ebp-3158h]
  IMDLCache *v30; // [esp-8h] [ebp-3158h]
  matrix3x4_t pMergeBoneToWorld; // [esp+4h] [ebp-314Ch] BYREF
  StudioRenderConfig_t v33; // [esp+3004h] [ebp-14Ch] BYREF
  matrix3x4_t pWorldToCamera; // [esp+303Ch] [ebp-114h] BYREF
  CStudioHdr pMergeHdr; // [esp+306Ch] [ebp-E4h] BYREF
  CStudioHdr pFollow; // [esp+30D0h] [ebp-80h] BYREF
  Vector out; // [esp+3138h] [ebp-18h] BYREF
  int v38; // [esp+3144h] [ebp-Ch]
  int v39; // [esp+3148h] [ebp-8h]
  int m_Size; // [esp+314Ch] [ebp-4h]

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v4 = vgui::StudioRender();
    ((void (__thiscall *)(IStudioRender *, StudioRenderConfig_t *, int))v4->GetCurrentConfig)(a1: v4, a2: &v33, a3: a2);
    CMDLPanel::UpdateStudioRenderConfig(this);
    v5 = vgui::MaterialSystem();
    v6 = (int)v5->GetRenderContext(this: v5);
    v7 = v6;
    v38 = v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v7 + 464))(a1: v7, a2: 10, a3: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 336))(a1: v7, a2: 0);
    v39 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 520))(a1: v7);
    v8 = vgui::MaterialSystemHardwareConfig();
    if ( v8->GetHDRType(this: v8) != HDR_TYPE_NONE )
    {
      if ( CPotteryWheelPanel::HasLightProbe(this) )
        LightProbeCubemap = CPotteryWheelPanel::GetLightProbeCubemap(this, bHDR: true);
      else
        LightProbeCubemap = this->m_DefaultHDREnvCubemap.m_pTexture;
    }
    else if ( CPotteryWheelPanel::HasLightProbe(this) )
    {
      LightProbeCubemap = CPotteryWheelPanel::GetLightProbeCubemap(this, bHDR: false);
    }
    else
    {
      LightProbeCubemap = this->m_DefaultEnvCubemap.m_pTexture;
    }
    (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v7 + 20))(a1: v7, a2: LightProbeCubemap);
    if ( (*((_BYTE *)this + 2876) & 2) != 0 )
      CPotteryWheelPanel::DrawGrid(this);
    if ( (*((_BYTE *)this + 2876) & 0x10) != 0 )
    {
      CPotteryWheelPanel::ComputeCameraTransform(this, &pWorldToCamera);
      MatrixGetColumn(in: &pWorldToCamera, column: 3, &out);
      x = out.x;
      this->m_RootMDL.m_MDL.m_bWorldSpaceViewTarget = true;
      this->m_RootMDL.m_MDL.m_vecViewTarget.x = x;
      this->m_RootMDL.m_MDL.m_vecViewTarget.y = out.y;
      this->m_RootMDL.m_MDL.m_vecViewTarget.z = out.z;
    }
    v11 = g_pMDLCache->__vftable;
    v28 = g_pMDLCache;
    MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
    v13 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, IMDLCache *))v11->GetStudioHdr)(
                                 a1: g_pMDLCache,
                                 a2: MDL,
                                 a3: v28);
    CStudioHdr::CStudioHdr(this: &pFollow, pStudioHdr: v13, mdlcache: a3);
    v14 = (matrix3x4_t *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 392))(
                           a1: v7,
                           a2: 48 * pFollow.m_pStudioHdr->numbones);
    m_nNumSequenceLayers = this->m_nNumSequenceLayers;
    v15 = *(float *)&v14;
    numbones = pFollow.m_pStudioHdr->numbones;
    LODWORD(out.x) = v14;
    CMDL::SetUpBones(
      this: &this->m_RootMDL.m_MDL,
      rootToWorld: &this->m_RootMDL.m_MDLToWorld,
      nMaxBoneCount: numbones,
      pBoneToWorld: v14,
      pPoseParameters: this->m_PoseParameters,
      pSequenceLayers: this->m_SequenceLayers,
      nNumSequenceLayers: m_nNumSequenceLayers);
    CMDL::Draw(
      this: &this->m_RootMDL.m_MDL,
      rootToWorld: &this->m_RootMDL.m_MDLToWorld,
      pBoneToWorld: (const matrix3x4_t *)LODWORD(v15),
      flags: 32);
    if ( this->m_aMergeMDLs.m_Size > 0 )
    {
      v16 = 0;
      m_Size = this->m_aMergeMDLs.m_Size;
      do
      {
        v17 = g_pMDLCache->__vftable;
        v30 = g_pMDLCache;
        v18 = CMDL::GetMDL(this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL);
        v19 = v17->GetStudioHdr(this: g_pMDLCache, a2: v18);
        CStudioHdr::CStudioHdr(this: &pMergeHdr, pStudioHdr: v19, mdlcache: v30);
        CMDL::SetupBonesWithBoneMerge(
          this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL,
          &pMergeHdr,
          &pMergeBoneToWorld,
          &pFollow,
          pFollowBoneToWorld: (const matrix3x4_t *)LODWORD(out.x),
          matModelToWorld: &this->m_RootMDL.m_MDLToWorld);
        CMDL::Draw(
          this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL,
          rootToWorld: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDLToWorld,
          pBoneToWorld: &pMergeBoneToWorld,
          flags: 32);
        CStudioHdr::Term(this: &pMergeHdr);
        m_pMemory = pMergeHdr.m_boneParent.m_Memory.m_pMemory;
        pMergeHdr.m_boneParent.m_Size = 0;
        if ( pMergeHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_boneParent.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            pMergeHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_boneParent.m_pElements = m_pMemory;
        if ( pMergeHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            pMergeHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
        }
        v21 = pMergeHdr.m_boneFlags.m_Memory.m_pMemory;
        pMergeHdr.m_boneFlags.m_Size = 0;
        if ( pMergeHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_boneFlags.m_Memory.m_pMemory);
            v21 = nullptr;
            pMergeHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_boneFlags.m_pElements = v21;
        if ( pMergeHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v21 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
            pMergeHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
        }
        v22 = pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
        pMergeHdr.m_pStudioHdrCache.m_Size = 0;
        if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
            v22 = nullptr;
            pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_pStudioHdrCache.m_pElements = v22;
        if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v22 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        ++v16;
        --m_Size;
      }
      while ( m_Size != 0 );
      v7 = v38;
      v15 = out.x;
    }
    if ( v15 != 0.0 )
      (*(void (__thiscall **)(int, float))(*(_DWORD *)v7 + 396))(a1: v7, a2: COERCE_FLOAT(LODWORD(v15)));
    if ( (*((_BYTE *)this + 2876) & 1) != 0 )
      CMDLPanel::DrawCollisionModel(this);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 16))(a1: v7, a2: 0);
    v23 = vgui::StudioRender();
    v23->UpdateConfig(this: v23, a2: &v33);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 20))(a1: v7, a2: v39);
    CStudioHdr::Term(this: &pFollow);
    v24 = pFollow.m_boneParent.m_Memory.m_pMemory;
    pFollow.m_boneParent.m_Size = 0;
    if ( pFollow.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_boneParent.m_Memory.m_pMemory);
        v24 = nullptr;
        pFollow.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_boneParent.m_pElements = v24;
    if ( pFollow.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v24 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
        pFollow.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v25 = pFollow.m_boneFlags.m_Memory.m_pMemory;
    pFollow.m_boneFlags.m_Size = 0;
    if ( pFollow.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_boneFlags.m_Memory.m_pMemory);
        v25 = nullptr;
        pFollow.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_boneFlags.m_pElements = v25;
    if ( pFollow.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v25 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
        pFollow.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v26 = pFollow.m_pStudioHdrCache.m_Memory.m_pMemory;
    pFollow.m_pStudioHdrCache.m_Size = 0;
    if ( pFollow.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_pStudioHdrCache.m_Memory.m_pMemory);
        v26 = nullptr;
        pFollow.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_pStudioHdrCache.m_pElements = v26;
    if ( pFollow.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v26 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
        pFollow.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213930
// Name: public: void CMDLPanel::SetPoseParameters(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetPoseParameters(CMDLPanel *this, const float *pPoseParameters, int nCount)
{
  int v4; // edi
  int v5; // esi
  float *v6; // eax
  unsigned int v7; // edx
  const float *v8; // ecx
  float *v9; // eax
  double v10; // st7
  IMDLCache_vtbl *v11; // ebx
  unsigned __int16 MDL; // ax
  const studiohdr_t *v13; // eax
  IMDLCache *v14; // [esp-4h] [ebp-78h]
  CStudioHdr studioHdr; // [esp+Ch] [ebp-68h] BYREF
  CMDLPanel *v16; // [esp+70h] [ebp-4h]

  v16 = this;
  if ( pPoseParameters != nullptr )
  {
    v4 = nCount;
    if ( nCount > 24 )
      v4 = 24;
    v5 = 0;
    if ( v4 >= 4 )
    {
      v6 = &v16->m_PoseParameters[1];
      v7 = ((unsigned int)(v4 - 4) >> 2) + 1;
      v8 = pPoseParameters + 2;
      v5 = 4 * v7;
      do
      {
        v6 += 4;
        *(v6 - 5) = *(v8 - 2);
        v8 += 4;
        --v7;
        *(v6 - 4) = *(v8 - 5);
        *(v6 - 3) = *(v8 - 4);
        *(v6 - 2) = *(v8 - 3);
      }
      while ( v7 != 0 );
    }
    if ( v5 < v4 )
    {
      v9 = &v16->m_PoseParameters[v5];
      do
      {
        v10 = pPoseParameters[v5++];
        *v9++ = v10;
      }
      while ( v5 < v4 );
    }
  }
  else if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v11 = g_pMDLCache->__vftable;
    v14 = g_pMDLCache;
    MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
    v13 = v11->GetStudioHdr(this: g_pMDLCache, a2: MDL);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v13, mdlcache: v14);
    Studio_CalcDefaultPoseParameters(pStudioHdr: &studioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
    CStudioHdr::Term(this: &studioHdr);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&studioHdr.m_boneParent);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&studioHdr.m_boneFlags);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&studioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213A40
// Name: Create_CMDLPanel
// Source: json
//------------------------------------------------------------------------------
CMDLPanel *__cdecl Create_CMDLPanel()
{
  CMDLPanel *v0; // eax

  v0 = (CMDLPanel *)operator new(nSize: 0xBE4u);
  if ( v0 != nullptr )
    return CMDLPanel::CMDLPanel(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10213A90
// Name: public: virtual void CMDLPanel::SetMDL(unsigned short,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, unsigned __int16 handle, void *pProxyData)
{
  int m_nSequence; // [esp-4h] [ebp-24h]
  Vector vecMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_RootMDL.m_MDL, h: handle);
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  this->m_RootMDL.m_MDL.m_pProxyData = pProxyData;
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: handle, nSequence: m_nSequence);
  this->m_RootMDL.m_MDL.m_bWorldSpaceViewTarget = false;
  this->m_RootMDL.m_MDL.m_vecViewTarget.x = 100.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.y = 0.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.z = vecMaxs.z;
  CMDLPanel::SetPoseParameters(this, pPoseParameters: nullptr, nCount: 0);
  this->m_nNumSequenceLayers = 0;
  _V_memset(dest: this->m_SequenceLayers, fill: 0, count: 64);
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0040D760
// Name: public: static char const __near * CMDLPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPanel::GetPanelClassName()
{
  return "CMDLPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0040D770
// Name: public: void CVertexBuilder::AttachBegin(class IMesh __near *,int,struct MeshDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AttachBegin(
        CVertexBuilder *this,
        IMesh *pMesh,
        int nMaxVertexCount,
        const MeshDesc_t *desc)
{
  bool v4; // zf

  this->m_pVertexBuffer = pMesh;
  this->VertexDesc_t = desc->VertexDesc_t;
  this->m_nMaxVertexCount = nMaxVertexCount;
  this->m_NumBoneWeights = this->m_NumBoneWeights != 0 ? 2 : 0;
  v4 = this->m_nBufferOffset == -1;
  this->m_nVertexCount = 0;
  this->m_bModify = false;
  if ( v4 )
  {
    this->m_nTotalVertexCount = 0;
    this->m_nBufferOffset = desc->VertexDesc_t::m_nOffset;
    this->m_nBufferFirstVertex = desc->m_nFirstVertex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D7E0
// Name: public: void CVertexBuilder::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::Reset(CVertexBuilder *this)
{
  float *m_pNormal; // edx
  float *v2; // edx
  float *v3; // eax
  float *v4; // edx
  float *v5; // eax
  float *v6; // edx
  float *v7; // eax
  float *v8; // edx

  m_pNormal = this->m_pNormal;
  this->m_pCurrPosition = this->m_pPosition;
  this->m_nCurrentVertex = 0;
  this->m_pCurrNormal = m_pNormal;
  v2 = this->m_pTexCoord[1];
  this->m_pCurrTexCoord[0] = this->m_pTexCoord[0];
  v3 = this->m_pTexCoord[2];
  this->m_pCurrTexCoord[1] = v2;
  v4 = this->m_pTexCoord[3];
  this->m_pCurrTexCoord[2] = v3;
  v5 = this->m_pTexCoord[4];
  this->m_pCurrTexCoord[3] = v4;
  v6 = this->m_pTexCoord[5];
  this->m_pCurrTexCoord[4] = v5;
  v7 = this->m_pTexCoord[6];
  this->m_pCurrTexCoord[5] = v6;
  v8 = this->m_pTexCoord[7];
  this->m_pCurrTexCoord[6] = v7;
  this->m_pCurrTexCoord[7] = v8;
  this->m_pCurrColor = this->m_pColor;
}

//------------------------------------------------------------------------------
// Address: 0x0040D860
// Name: public: void CIndexBuilder::GenerateIndices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::GenerateIndices(
        CIndexBuilder *this,
        MaterialPrimitiveType_t primitiveType,
        int nIndexCount)
{
  int v4; // edi
  unsigned __int16 *v5; // eax
  int m_nCurrentIndex; // eax

  if ( this->m_nIndexSize != 0 )
  {
    v4 = nIndexCount;
    if ( this->m_nMaxIndexCount - this->m_nCurrentIndex < nIndexCount )
      v4 = this->m_nMaxIndexCount - this->m_nCurrentIndex;
    if ( v4 != 0 )
    {
      v5 = &this->m_pIndices[this->m_nCurrentIndex];
      switch ( primitiveType )
      {
        case MATERIAL_POINTS:
        case MATERIAL_INSTANCED_QUADS:
          break;
        case MATERIAL_LINE_STRIP:
          GenerateLineStripIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_LINE_LOOP:
          GenerateLineLoopIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_POLYGON:
          GeneratePolygonIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_QUADS:
          GenerateQuadIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        default:
          GenerateSequentialIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
      }
      this->m_nCurrentIndex += v4 * this->m_nIndexSize;
      m_nCurrentIndex = this->m_nCurrentIndex;
      if ( m_nCurrentIndex > this->m_nIndexCount )
        this->m_nIndexCount = m_nCurrentIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D930
// Name: public: CMeshBuilder::CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBuilder *__thiscall CMeshBuilder::CMeshBuilder(CMeshBuilder *this)
{
  this->m_pMesh = nullptr;
  this->m_bGenerateIndices = false;
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_IndexBuilder.m_nTotalIndexCount = 0;
  this->m_IndexBuilder.m_nBufferFirstIndex = 0;
  this->m_IndexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_nBufferFirstVertex = 0;
  this->m_VertexBuilder.m_nVertexCount = 0;
  this->m_VertexBuilder.m_nCurrentVertex = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_nTotalVertexCount = 0;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040D9A0
// Name: public: virtual void CMDLPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::ApplySchemeSettings(CMDLPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  const Color *v4; // eax
  CMDLPanel_vtbl *v5; // ebx
  int v6; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->GetBgColor(this, result: &pScheme);
  CPotteryWheelPanel::SetBackgroundColor(this, c: v4);
  v5 = this->__vftable;
  v6 = (int)v2->GetBorder(this: v2, a2: "MenuBorder");
  v5->SetBorder(this, a2: (vgui::IBorder *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x0040D9F0
// Name: public: void CMDLPanel::SetCollsionModel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetCollsionModel(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (bVisible ^ *((_BYTE *)this + 2876)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DA10
// Name: public: void CMDLPanel::SetGroundGrid(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetGroundGrid(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (2 * bVisible)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x0040DA30
// Name: public: void CMDLPanel::SetWireFrame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetWireFrame(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (8 * bVisible)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x0040DA50
// Name: public: void CMDLPanel::SetLockView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetLockView(CMDLPanel *this, bool bLocked)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (4 * bLocked)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x0040DA70
// Name: public: void CMDLPanel::SetLookAtCamera(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetLookAtCamera(CMDLPanel *this, bool bLookAtCamera)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (16 * bLookAtCamera)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x0040DA90
// Name: public: virtual void CMDLPanel::SetMDL(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, const char *pMDLName, void *pProxyData)
{
  IMDLCache *v4; // eax
  int v5; // esi
  IMDLCache *v6; // eax

  if ( pMDLName != nullptr )
  {
    v4 = vgui::MDLCache();
    v5 = v4->FindMDL(this: v4, a2: pMDLName);
  }
  else
  {
    v5 = 0xFFFF;
  }
  v6 = vgui::MDLCache();
  if ( v6->IsErrorModel(this: v6, a2: v5) )
    v5 = 0xFFFF;
  this->SetMDL_2(this, a2: v5, a3: pProxyData);
}

//------------------------------------------------------------------------------
// Address: 0x0040DAF0
// Name: public: bool CMDLPanel::GetBoundingSphere(class Vector __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLPanel::GetBoundingSphere(CMDLPanel *this, Vector *vecCenter, float *flRadius)
{
  unsigned __int16 MDL; // ax
  int m_nSequence; // [esp-4h] [ebp-18h]
  Vector vecEngineCenter; // [esp+8h] [ebp-Ch] BYREF

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) == 0xFFFF )
    return 0;
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
  GetMDLBoundingSphere(pVecCenter: &vecEngineCenter, pRadius: flRadius, h: MDL, nSequence: m_nSequence);
  VectorTransform(in1: &vecEngineCenter.x, in2: &this->m_RootMDL.m_MDLToWorld, out: &vecCenter->x);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DB60
// Name: public: void CMDLPanel::LookAtMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::LookAtMDL(CMDLPanel *this)
{
  Vector vecCenter; // [esp+8h] [ebp-10h] BYREF
  float flRadius; // [esp+14h] [ebp-4h] BYREF

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF && (*((_BYTE *)this + 2876) & 4) == 0 )
  {
    CMDLPanel::GetBoundingSphere(this, &vecCenter, &flRadius);
    CPotteryWheelPanel::LookAt(this, &vecCenter, flRadius);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DBC0
// Name: public: void CMDLPanel::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSequence(CMDLPanel *this, int nSequence)
{
  this->m_RootMDL.m_MDL.m_nSequence = nSequence;
}

//------------------------------------------------------------------------------
// Address: 0x0040DBD0
// Name: public: void CMDLPanel::SetSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSkin(CMDLPanel *this, int nSkin)
{
  this->m_RootMDL.m_MDL.m_nSkin = nSkin;
}

//------------------------------------------------------------------------------
// Address: 0x0040DBE0
// Name: public: virtual void CMDLPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::OnTick(CMDLPanel *this)
{
  int v2; // eax
  int v3; // ecx

  CPotteryWheelPanel::OnTick(this);
  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v2 = _Plat_MSTime();
    v3 = dword_507744;
    if ( dword_507744 == 0 )
      v3 = v2;
    *(float *)&dword_507740 = (float)((float)(v2 - v3) * 0.001) + *(float *)&dword_507740;
    dword_507744 = v2;
    LODWORD(this->m_RootMDL.m_MDL.m_flTime) = dword_507740;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DC40
// Name: private: virtual void CMDLPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::OnMouseDoublePressed(CMDLPanel *this, ButtonCode_t code)
{
  Vector vecCenter; // [esp+8h] [ebp-10h] BYREF
  float flRadius; // [esp+14h] [ebp-4h] BYREF

  CMDLPanel::GetBoundingSphere(this, &vecCenter, &flRadius);
  CPotteryWheelPanel::LookAt(this, &vecCenter, flRadius);
  CPotteryWheelPanel::OnMouseDoublePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x0040DC80
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x0040DD00
// Name: private: void CMDLPanel::UpdateStudioRenderConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::UpdateStudioRenderConfig(CMDLPanel *this)
{
  char v2; // al
  char v3; // al
  char v4; // al
  IStudioRender *v5; // eax

  memset(dst: (unsigned __int8 *)&s_StudioRenderConfig_0, value: 0, count: sizeof(s_StudioRenderConfig_0));
  v2 = (*((_BYTE *)&s_StudioRenderConfig_0 + 36)
      ^ (r_eyemove_0.m_pParent->m_Value.m_nValue != 0))
     & 1
     ^ *((_BYTE *)&s_StudioRenderConfig_0 + 36);
  *((_BYTE *)&s_StudioRenderConfig_0 + 36) = v2;
  s_StudioRenderConfig_0.fEyeShiftX = r_eyeshift_x_0.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig_0.fEyeShiftY = r_eyeshift_y_0.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig_0.fEyeShiftZ = r_eyeshift_z_0.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig_0.fEyeSize = r_eyesize_0.m_pParent->m_Value.m_fValue;
  if ( mat_softwareskin_0.m_pParent->m_Value.m_nValue != 0 || (*((_BYTE *)this + 2876) & 8) != 0 )
    v3 = v2 | 2;
  else
    v3 = v2 & 0xFD;
  *((_BYTE *)&s_StudioRenderConfig_0 + 36) = v3;
  *((_BYTE *)&s_StudioRenderConfig_0 + 36) = (v3 ^ (4 * (r_nohw_0.m_pParent->m_Value.m_nValue != 0))) & 4 ^ v3;
  *((_BYTE *)&s_StudioRenderConfig_0 + 36) ^= (*((_BYTE *)&s_StudioRenderConfig_0 + 36)
                                             ^ (8 * (r_nosw_0.m_pParent->m_Value.m_nValue != 0)))
                                            & 8;
  *((_BYTE *)&s_StudioRenderConfig_0 + 36) ^= (*((_BYTE *)&s_StudioRenderConfig_0 + 36)
                                             ^ (16 * (r_teeth_0.m_pParent->m_Value.m_nValue != 0)))
                                            & 0x10;
  s_StudioRenderConfig_0.drawEntities = r_drawentities_0.m_pParent->m_Value.m_nValue;
  *((_BYTE *)&s_StudioRenderConfig_0 + 36) ^= (*((_BYTE *)&s_StudioRenderConfig_0 + 36)
                                             ^ ((r_flex_0.m_pParent->m_Value.m_nValue != 0) << 6))
                                            & 0x40;
  *((_BYTE *)&s_StudioRenderConfig_0 + 36) ^= (*((_BYTE *)&s_StudioRenderConfig_0 + 36)
                                             ^ (32 * (r_eyes_0.m_pParent->m_Value.m_nValue != 0)))
                                            & 0x20;
  *((_BYTE *)&s_StudioRenderConfig_0 + 36) = (16 * *((_BYTE *)this + 2876))
                                           ^ (*((_BYTE *)&s_StudioRenderConfig_0 + 36)
                                            ^ (16 * *((_BYTE *)this + 2876)))
                                           & 0x7F;
  *((_BYTE *)&s_StudioRenderConfig_0 + 37) ^= (*((_BYTE *)&s_StudioRenderConfig_0 + 37)
                                             ^ (mat_normals_0.m_pParent->m_Value.m_nValue != 0))
                                            & 1;
  s_StudioRenderConfig_0.skin = r_skin_0.m_pParent->m_Value.m_nValue;
  s_StudioRenderConfig_0.maxDecalsPerModel = r_maxmodeldecal_0.m_pParent->m_Value.m_nValue;
  v4 = ((*((_BYTE *)&s_StudioRenderConfig_0 + 37)
       ^ (32 * (r_modelwireframedecal_0.m_pParent->m_Value.m_nValue != 0)))
      & 0x20
      ^ *((_BYTE *)&s_StudioRenderConfig_0 + 37))
     & 0xF7;
  s_StudioRenderConfig_0.fullbright = 0;
  *((_BYTE *)&s_StudioRenderConfig_0 + 37) = v4;
  *((_BYTE *)&s_StudioRenderConfig_0 + 37) = (v4
                                            ^ (16 * (r_showenvcubemap_0.m_pParent->m_Value.m_nValue != 0)))
                                           & 0x10
                                           ^ v4;
  s_StudioRenderConfig_0.fEyeGlintPixelWidthLODThreshold = r_eyeglintlodpixels_0.m_pParent->m_Value.m_fValue;
  v5 = vgui::StudioRender();
  v5->UpdateConfig(this: v5, a2: &s_StudioRenderConfig_0);
}

//------------------------------------------------------------------------------
// Address: 0x0040DF70
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x0040DFA0
// Name: public: CMDLPanel::CMDLPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMDLPanel *__thiscall CMDLPanel::CMDLPanel(CMDLPanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  IMaterialSystem *v7; // eax
  ITexture *v8; // eax
  IMaterialSystem *v9; // eax
  ITexture *v10; // eax

  CPotteryWheelPanel::CPotteryWheelPanel(this, pParent, pName);
  this->__vftable = (CMDLPanel_vtbl *)&CMDLPanel::`vftable';
  if ( `CMDLPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
    v4->pfnClassName = CMDLPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  }
  if ( `CMDLPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMDLPanel");
    v5->pfnClassName = CMDLPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
  }
  if ( `CMDLPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
    v6->pfnClassName = CMDLPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  }
  CMDL::CMDL(this: &this->m_RootMDL.m_MDL);
  this->m_aMergeMDLs.m_Memory.m_pMemory = nullptr;
  this->m_aMergeMDLs.m_Memory.m_nAllocationCount = 0;
  this->m_aMergeMDLs.m_Memory.m_nGrowSize = 0;
  this->m_aMergeMDLs.m_Size = 0;
  this->m_aMergeMDLs.m_pElements = nullptr;
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  vgui::Panel::SetVisible(this, state: true);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  v7 = vgui::MaterialSystem();
  v8 = v7->FindTexture(this: v7, a2: "editor/cubemap", a3: nullptr, a4: true, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultEnvCubemap, pTexture: v8);
  v9 = vgui::MaterialSystem();
  v10 = v9->FindTexture(this: v9, a2: "editor/cubemap.hdr", a3: nullptr, a4: true, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultHDREnvCubemap, pTexture: v10);
  SetIdentityMatrix(matrix: &this->m_RootMDL.m_MDLToWorld);
  *((_BYTE *)this + 2876) = *((_BYTE *)this + 2876) & 0xE0 | 0x10;
  this->m_nNumSequenceLayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040E130
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPanel::GetMessageMap(CMDLPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetMessageMap'::`2'::s_pMap;
  `CMDLPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
  `CMDLPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E160
// Name: public: virtual struct PanelAnimationMap __near * CMDLPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPanel::GetAnimMap(CMDLPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0040E170
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPanel::GetKBMap(CMDLPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetKBMap'::`2'::s_pMap;
  `CMDLPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
  `CMDLPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E1A0
// Name: public: virtual CMDLPanel::~CMDLPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::~CMDLPanel(CMDLPanel *this)
{
  this->__vftable = (CMDLPanel_vtbl *)&CMDLPanel::`vftable';
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  CTextureReference::Shutdown(this: &this->m_DefaultEnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &this->m_DefaultHDREnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::~CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  if ( this->m_aMergeMDLs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aMergeMDLs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aMergeMDLs.m_Memory.m_pMemory);
      this->m_aMergeMDLs.m_Memory.m_pMemory = nullptr;
    }
    this->m_aMergeMDLs.m_Memory.m_nAllocationCount = 0;
  }
  CMDL::~CMDL(this: &this->m_RootMDL.m_MDL);
  CPotteryWheelPanel::~CPotteryWheelPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040E240
// Name: private: void CMDLPanel::DrawCollisionModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::DrawCollisionModel(CMDLPanel *this)
{
  IMDLCache *v2; // edi
  IMDLCache_vtbl *v3; // esi
  CMDLPanel::MDLData_t *p_m_RootMDL; // ebx
  unsigned __int16 MDL; // ax
  IMDLCache *v6; // eax
  IVPhysicsKeyParser *v7; // esi
  IMDLCache_vtbl *v8; // edi
  unsigned __int16 v9; // ax
  const studiohdr_t *v10; // eax
  const char *v11; // eax
  int v12; // eax
  IVPhysicsKeyParser_vtbl *v13; // edx
  int v14; // eax
  int (__thiscall *CreateDebugMesh)(IPhysicsCollision *, const struct CPhysCollide *, Vector **); // edx
  int v16; // edi
  IMatRenderContext *v17; // ebx
  IMesh *v18; // esi
  int v19; // edi
  int v20; // edi
  int i; // ebx
  float *m_pCurrPosition; // eax
  int a; // ecx
  float *v24; // eax
  int m_nVertexCount; // eax
  IMDLCache *v26; // [esp-8h] [ebp-38F8h]
  IMDLCache *v27; // [esp-4h] [ebp-38F4h]
  matrix3x4_t pBoneToWorld[256]; // [esp+Ch] [ebp-38E4h] BYREF
  char pName[1548]; // [esp+300Ch] [ebp-8E4h] BYREF
  int v30; // [esp+3618h] [ebp-2D8h]
  CStudioHdr pStudioHdr; // [esp+364Ch] [ebp-2A4h] BYREF
  matrix3x4_t matrix; // [esp+36B0h] [ebp-240h] BYREF
  CMeshBuilder v33; // [esp+36E0h] [ebp-210h] BYREF
  float out[3]; // [esp+38C8h] [ebp-28h] BYREF
  int v35; // [esp+38D4h] [ebp-1Ch]
  IMatRenderContext *v36; // [esp+38D8h] [ebp-18h]
  IMDLCache *v37; // [esp+38DCh] [ebp-14h]
  IVPhysicsKeyParser *v38; // [esp+38E0h] [ebp-10h]
  Vector *v39; // [esp+38E4h] [ebp-Ch] BYREF
  CMDLPanel *v40; // [esp+38E8h] [ebp-8h]
  int v41; // [esp+38ECh] [ebp-4h]

  v40 = this;
  v2 = vgui::MDLCache();
  v3 = v2->__vftable;
  p_m_RootMDL = &this->m_RootMDL;
  MDL = CMDL::GetMDL(this: &p_m_RootMDL->m_MDL);
  v6 = (IMDLCache *)v3->GetVCollide(this: v2, a2: MDL);
  v37 = v6;
  if ( v6 != nullptr && ((int)v6->__vftable & 0x7FFF) != 0 )
  {
    v27 = v6;
    v7 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *))g_pPhysicsCollision->VPhysicsKeyParserCreate)(a1: g_pPhysicsCollision);
    v8 = g_pMDLCache->__vftable;
    v26 = g_pMDLCache;
    v38 = v7;
    v9 = CMDL::GetMDL(this: &p_m_RootMDL->m_MDL);
    v10 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, IMDLCache *))v8->GetStudioHdr)(
                                 a1: g_pMDLCache,
                                 a2: v9,
                                 a3: v26);
    CStudioHdr::CStudioHdr(this: &pStudioHdr, pStudioHdr: v10, mdlcache: v27);
    CMDL::SetUpBones(
      this: &p_m_RootMDL->m_MDL,
      rootToWorld: &v40->m_RootMDL.m_MDLToWorld,
      nMaxBoneCount: 256,
      pBoneToWorld,
      pPoseParameters: nullptr,
      pSequenceLayers: nullptr,
      nNumSequenceLayers: 0);
    while ( !v7->Finished(this: v7) )
    {
      v11 = v7->GetCurrentBlockName(this: v7);
      v12 = _V_stricmp(s1: v11, s2: "solid");
      v13 = v7->__vftable;
      if ( v12 != 0 )
      {
        v13->SkipBlock(this: v7);
      }
      else
      {
        v13->ParseSolid(this: v7, a2: (solid_t *)pName, a3: nullptr);
        v14 = Studio_BoneIndexByName(&pStudioHdr, pName);
        CreateDebugMesh = g_pPhysicsCollision->CreateDebugMesh;
        v35 = v14;
        v16 = CreateDebugMesh(
                this: g_pPhysicsCollision,
                a2: *((const struct CPhysCollide **)&v37[1].Connect + v30),
                a3: &v39);
        v41 = v16;
        if ( v16 != 0 )
        {
          v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
          v36 = v17;
          if ( v17 != nullptr )
            v17->BeginRender(this: v17);
          v17->CullMode(this: v17, a2: MATERIAL_CULLMODE_CCW);
          SetIdentityMatrix(&matrix);
          if ( v35 >= 0 )
            MatrixCopy(in: &pBoneToWorld[v35], out: &matrix);
          v18 = v17->GetDynamicMesh(this: v17, a2: true, a3: nullptr, a4: nullptr, a5: v40->m_Wireframe.m_pMaterial);
          CMeshBuilder::CMeshBuilder(this: &v33);
          v33.m_pMesh = v18;
          v33.m_bGenerateIndices = true;
          v33.m_Type = MATERIAL_TRIANGLES;
          v19 = 3 * (v16 / 3);
          v18->SetPrimitiveType(this: v18, a2: MATERIAL_TRIANGLES);
          v33.m_pMesh->LockMesh(this: v33.m_pMesh, a2: v19, a3: v19, a4: &v33, a5: nullptr);
          v33.m_IndexBuilder.m_pIndices = v33.m_pIndices;
          v33.m_IndexBuilder.m_nIndexOffset = v33.m_nFirstVertex;
          v33.m_IndexBuilder.m_pIndexBuffer = &v18->IIndexBuffer;
          v33.m_IndexBuilder.m_nIndexSize = v33.m_nIndexSize;
          v33.m_IndexBuilder.m_nIndexCount = 0;
          v33.m_IndexBuilder.m_nMaxIndexCount = v19;
          v33.m_IndexBuilder.m_bModify = false;
          v33.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::AttachBegin(this: &v33.m_VertexBuilder, pMesh: v18, nMaxVertexCount: v19, desc: &v33);
          v20 = 0;
          v33.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::Reset(this: &v33.m_VertexBuilder);
          if ( v41 > 0 )
          {
            for ( i = v41; i != 0; --i )
            {
              VectorTransform(in1: &v39[v20].x, in2: &matrix, out);
              m_pCurrPosition = v33.m_VertexBuilder.m_pCurrPosition;
              a = color.a;
              *v33.m_VertexBuilder.m_pCurrPosition = out[0];
              m_pCurrPosition[1] = out[1];
              m_pCurrPosition[2] = out[2];
              *(_DWORD *)v33.m_VertexBuilder.m_pCurrColor = color.b | ((color.g | ((color.r | (a << 8)) << 8)) << 8);
              v24 = v33.m_VertexBuilder.m_pCurrTexCoord[0];
              *v33.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
              v24[1] = 0.0;
              CVertexBuilder::AdvanceVertex(this: &v33.m_VertexBuilder);
              ++v20;
            }
            v17 = v36;
          }
          if ( v33.m_bGenerateIndices )
          {
            switch ( v33.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * v33.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * v33.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * v33.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * v33.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = v33.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &v33.m_IndexBuilder,
              primitiveType: v33.m_Type,
              nIndexCount: m_nVertexCount);
          }
          v33.m_pMesh->UnlockMesh(
            this: v33.m_pMesh,
            a2: v33.m_VertexBuilder.m_nVertexCount,
            a3: v33.m_IndexBuilder.m_nIndexCount,
            a4: &v33);
          v33.m_IndexBuilder.m_pIndexBuffer = nullptr;
          v33.m_IndexBuilder.m_nMaxIndexCount = 0;
          v33.m_VertexBuilder.m_nMaxVertexCount = 0;
          v33.m_VertexBuilder.m_pVertexBuffer = nullptr;
          v33.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          v33.m_pMesh = nullptr;
          v18->Draw_2(this: v18, a2: -1, a3: 0);
          if ( v33.m_VertexBuilder.m_pVertexBuffer != nullptr
            && v33.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v33.m_VertexBuilder.m_pVertexBuffer) )
          {
            v33.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v33.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( v33.m_IndexBuilder.m_pIndexBuffer != nullptr
            && v33.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v33.m_IndexBuilder.m_pIndexBuffer) )
          {
            v33.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v33.m_IndexBuilder.m_pIndexBuffer);
          }
          v17->EndRender(this: v17);
          v17->Release(this: v17);
          v7 = v38;
          v16 = v41;
        }
        g_pPhysicsCollision->DestroyDebugMesh(this: g_pPhysicsCollision, a2: v16, a3: v39);
      }
    }
    g_pPhysicsCollision->VPhysicsKeyParserDestroy(this: g_pPhysicsCollision, a2: v7);
    CStudioHdr::Term(this: &pStudioHdr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pStudioHdr.m_boneParent);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pStudioHdr.m_boneFlags);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pStudioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E6F0
// Name: private: virtual void CMDLPanel::OnPaint3D(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPanel::OnPaint3D(CMDLPanel *this@<ecx>, int a2@<ebx>, IMDLCache *a3@<edi>)
{
  IStudioRender *v4; // eax
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // ebx
  IMaterialSystemHardwareConfig *v8; // eax
  ITexture *LightProbeCubemap; // eax
  float x; // xmm0_4
  IMDLCache_vtbl *v11; // edi
  unsigned __int16 MDL; // ax
  const studiohdr_t *v13; // eax
  matrix3x4_t *v14; // eax
  float v15; // edi
  int v16; // ebx
  IMDLCache_vtbl *v17; // edi
  unsigned __int16 v18; // ax
  const studiohdr_t *v19; // eax
  int *m_pMemory; // eax
  int *v21; // eax
  const studiohdr_t **v22; // eax
  IStudioRender *v23; // eax
  int *v24; // eax
  int *v25; // eax
  const studiohdr_t **v26; // eax
  int numbones; // [esp-18h] [ebp-3168h]
  IMDLCache *v28; // [esp-8h] [ebp-3158h]
  int m_nNumSequenceLayers; // [esp-8h] [ebp-3158h]
  IMDLCache *v30; // [esp-8h] [ebp-3158h]
  matrix3x4_t pMergeBoneToWorld; // [esp+4h] [ebp-314Ch] BYREF
  StudioRenderConfig_t v33; // [esp+3004h] [ebp-14Ch] BYREF
  matrix3x4_t pWorldToCamera; // [esp+303Ch] [ebp-114h] BYREF
  CStudioHdr pMergeHdr; // [esp+306Ch] [ebp-E4h] BYREF
  CStudioHdr pFollow; // [esp+30D0h] [ebp-80h] BYREF
  Vector out; // [esp+3138h] [ebp-18h] BYREF
  int v38; // [esp+3144h] [ebp-Ch]
  int v39; // [esp+3148h] [ebp-8h]
  int m_Size; // [esp+314Ch] [ebp-4h]

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v4 = vgui::StudioRender();
    ((void (__thiscall *)(IStudioRender *, StudioRenderConfig_t *, int))v4->GetCurrentConfig)(a1: v4, a2: &v33, a3: a2);
    CMDLPanel::UpdateStudioRenderConfig(this);
    v5 = vgui::MaterialSystem();
    v6 = (int)v5->GetRenderContext(this: v5);
    v7 = v6;
    v38 = v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v7 + 464))(a1: v7, a2: 10, a3: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 336))(a1: v7, a2: 0);
    v39 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 520))(a1: v7);
    v8 = vgui::MaterialSystemHardwareConfig();
    if ( v8->GetHDRType(this: v8) != HDR_TYPE_NONE )
    {
      if ( CPotteryWheelPanel::HasLightProbe(this) )
        LightProbeCubemap = CPotteryWheelPanel::GetLightProbeCubemap(this, bHDR: true);
      else
        LightProbeCubemap = this->m_DefaultHDREnvCubemap.m_pTexture;
    }
    else if ( CPotteryWheelPanel::HasLightProbe(this) )
    {
      LightProbeCubemap = CPotteryWheelPanel::GetLightProbeCubemap(this, bHDR: false);
    }
    else
    {
      LightProbeCubemap = this->m_DefaultEnvCubemap.m_pTexture;
    }
    (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v7 + 20))(a1: v7, a2: LightProbeCubemap);
    if ( (*((_BYTE *)this + 2876) & 2) != 0 )
      CPotteryWheelPanel::DrawGrid(this);
    if ( (*((_BYTE *)this + 2876) & 0x10) != 0 )
    {
      CPotteryWheelPanel::ComputeCameraTransform(this, &pWorldToCamera);
      MatrixGetColumn(in: &pWorldToCamera, column: 3, &out);
      x = out.x;
      this->m_RootMDL.m_MDL.m_bWorldSpaceViewTarget = true;
      this->m_RootMDL.m_MDL.m_vecViewTarget.x = x;
      this->m_RootMDL.m_MDL.m_vecViewTarget.y = out.y;
      this->m_RootMDL.m_MDL.m_vecViewTarget.z = out.z;
    }
    v11 = g_pMDLCache->__vftable;
    v28 = g_pMDLCache;
    MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
    v13 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, IMDLCache *))v11->GetStudioHdr)(
                                 a1: g_pMDLCache,
                                 a2: MDL,
                                 a3: v28);
    CStudioHdr::CStudioHdr(this: &pFollow, pStudioHdr: v13, mdlcache: a3);
    v14 = (matrix3x4_t *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 392))(
                           a1: v7,
                           a2: 48 * pFollow.m_pStudioHdr->numbones);
    m_nNumSequenceLayers = this->m_nNumSequenceLayers;
    v15 = *(float *)&v14;
    numbones = pFollow.m_pStudioHdr->numbones;
    LODWORD(out.x) = v14;
    CMDL::SetUpBones(
      this: &this->m_RootMDL.m_MDL,
      rootToWorld: &this->m_RootMDL.m_MDLToWorld,
      nMaxBoneCount: numbones,
      pBoneToWorld: v14,
      pPoseParameters: this->m_PoseParameters,
      pSequenceLayers: this->m_SequenceLayers,
      nNumSequenceLayers: m_nNumSequenceLayers);
    CMDL::Draw(
      this: &this->m_RootMDL.m_MDL,
      rootToWorld: &this->m_RootMDL.m_MDLToWorld,
      pBoneToWorld: (const matrix3x4_t *)LODWORD(v15),
      flags: 32);
    if ( this->m_aMergeMDLs.m_Size > 0 )
    {
      v16 = 0;
      m_Size = this->m_aMergeMDLs.m_Size;
      do
      {
        v17 = g_pMDLCache->__vftable;
        v30 = g_pMDLCache;
        v18 = CMDL::GetMDL(this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL);
        v19 = v17->GetStudioHdr(this: g_pMDLCache, a2: v18);
        CStudioHdr::CStudioHdr(this: &pMergeHdr, pStudioHdr: v19, mdlcache: v30);
        CMDL::SetupBonesWithBoneMerge(
          this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL,
          &pMergeHdr,
          &pMergeBoneToWorld,
          &pFollow,
          pFollowBoneToWorld: (const matrix3x4_t *)LODWORD(out.x),
          matModelToWorld: &this->m_RootMDL.m_MDLToWorld);
        CMDL::Draw(
          this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL,
          rootToWorld: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDLToWorld,
          pBoneToWorld: &pMergeBoneToWorld,
          flags: 32);
        CStudioHdr::Term(this: &pMergeHdr);
        m_pMemory = pMergeHdr.m_boneParent.m_Memory.m_pMemory;
        pMergeHdr.m_boneParent.m_Size = 0;
        if ( pMergeHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_boneParent.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            pMergeHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_boneParent.m_pElements = m_pMemory;
        if ( pMergeHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            pMergeHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
        }
        v21 = pMergeHdr.m_boneFlags.m_Memory.m_pMemory;
        pMergeHdr.m_boneFlags.m_Size = 0;
        if ( pMergeHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_boneFlags.m_Memory.m_pMemory);
            v21 = nullptr;
            pMergeHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_boneFlags.m_pElements = v21;
        if ( pMergeHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v21 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
            pMergeHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
        }
        v22 = pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
        pMergeHdr.m_pStudioHdrCache.m_Size = 0;
        if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
            v22 = nullptr;
            pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_pStudioHdrCache.m_pElements = v22;
        if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v22 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        ++v16;
        --m_Size;
      }
      while ( m_Size != 0 );
      v7 = v38;
      v15 = out.x;
    }
    if ( v15 != 0.0 )
      (*(void (__thiscall **)(int, float))(*(_DWORD *)v7 + 396))(a1: v7, a2: COERCE_FLOAT(LODWORD(v15)));
    if ( (*((_BYTE *)this + 2876) & 1) != 0 )
      CMDLPanel::DrawCollisionModel(this);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 16))(a1: v7, a2: 0);
    v23 = vgui::StudioRender();
    v23->UpdateConfig(this: v23, a2: &v33);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 20))(a1: v7, a2: v39);
    CStudioHdr::Term(this: &pFollow);
    v24 = pFollow.m_boneParent.m_Memory.m_pMemory;
    pFollow.m_boneParent.m_Size = 0;
    if ( pFollow.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_boneParent.m_Memory.m_pMemory);
        v24 = nullptr;
        pFollow.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_boneParent.m_pElements = v24;
    if ( pFollow.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v24 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
        pFollow.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v25 = pFollow.m_boneFlags.m_Memory.m_pMemory;
    pFollow.m_boneFlags.m_Size = 0;
    if ( pFollow.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_boneFlags.m_Memory.m_pMemory);
        v25 = nullptr;
        pFollow.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_boneFlags.m_pElements = v25;
    if ( pFollow.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v25 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
        pFollow.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v26 = pFollow.m_pStudioHdrCache.m_Memory.m_pMemory;
    pFollow.m_pStudioHdrCache.m_Size = 0;
    if ( pFollow.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_pStudioHdrCache.m_Memory.m_pMemory);
        v26 = nullptr;
        pFollow.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_pStudioHdrCache.m_pElements = v26;
    if ( pFollow.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v26 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
        pFollow.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EC00
// Name: public: void CMDLPanel::SetPoseParameters(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetPoseParameters(CMDLPanel *this, const float *pPoseParameters, int nCount)
{
  int v4; // edi
  int v5; // esi
  float *v6; // eax
  unsigned int v7; // edx
  const float *v8; // ecx
  float *v9; // eax
  double v10; // st7
  IMDLCache_vtbl *v11; // ebx
  unsigned __int16 MDL; // ax
  const studiohdr_t *v13; // eax
  IMDLCache *v14; // [esp-4h] [ebp-78h]
  CStudioHdr studioHdr; // [esp+Ch] [ebp-68h] BYREF
  CMDLPanel *v16; // [esp+70h] [ebp-4h]

  v16 = this;
  if ( pPoseParameters != nullptr )
  {
    v4 = nCount;
    if ( nCount > 24 )
      v4 = 24;
    v5 = 0;
    if ( v4 >= 4 )
    {
      v6 = &v16->m_PoseParameters[1];
      v7 = ((unsigned int)(v4 - 4) >> 2) + 1;
      v8 = pPoseParameters + 2;
      v5 = 4 * v7;
      do
      {
        v6 += 4;
        *(v6 - 5) = *(v8 - 2);
        v8 += 4;
        --v7;
        *(v6 - 4) = *(v8 - 5);
        *(v6 - 3) = *(v8 - 4);
        *(v6 - 2) = *(v8 - 3);
      }
      while ( v7 != 0 );
    }
    if ( v5 < v4 )
    {
      v9 = &v16->m_PoseParameters[v5];
      do
      {
        v10 = pPoseParameters[v5++];
        *v9++ = v10;
      }
      while ( v5 < v4 );
    }
  }
  else if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v11 = g_pMDLCache->__vftable;
    v14 = g_pMDLCache;
    MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
    v13 = v11->GetStudioHdr(this: g_pMDLCache, a2: MDL);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v13, mdlcache: v14);
    Studio_CalcDefaultPoseParameters(pStudioHdr: &studioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
    CStudioHdr::Term(this: &studioHdr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ED10
// Name: Create_CMDLPanel
// Source: json
//------------------------------------------------------------------------------
CMDLPanel *__cdecl Create_CMDLPanel()
{
  CMDLPanel *v0; // eax

  v0 = (CMDLPanel *)operator new(nSize: 0xBE4u);
  if ( v0 != nullptr )
    return CMDLPanel::CMDLPanel(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040ED60
// Name: public: virtual void CMDLPanel::SetMDL(unsigned short,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, unsigned __int16 handle, void *pProxyData)
{
  int m_nSequence; // [esp-4h] [ebp-24h]
  Vector vecMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_RootMDL.m_MDL, h: handle);
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  this->m_RootMDL.m_MDL.m_pProxyData = pProxyData;
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: handle, nSequence: m_nSequence);
  this->m_RootMDL.m_MDL.m_bWorldSpaceViewTarget = false;
  this->m_RootMDL.m_MDL.m_vecViewTarget.x = 100.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.y = 0.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.z = vecMaxs.z;
  CMDLPanel::SetPoseParameters(this, pPoseParameters: nullptr, nCount: 0);
  this->m_nNumSequenceLayers = 0;
  _V_memset(dest: this->m_SequenceLayers, fill: 0, count: 64);
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004C8B80
// Name: public: static char const __near * CMDLPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPanel::GetPanelClassName()
{
  return "CMDLPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004C8B90
// Name: public: virtual void CMDLPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::ApplySchemeSettings(CMDLPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  const Color *v4; // eax
  CMDLPanel_vtbl *v5; // ebx
  int v6; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->GetBgColor(this, result: &pScheme);
  CPotteryWheelPanel::SetBackgroundColor(this, c: v4);
  v5 = this->__vftable;
  v6 = (int)v2->GetBorder(this: v2, a2: "MenuBorder");
  v5->SetBorder(this, a2: (vgui::IBorder *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x004C8BE0
// Name: public: void CMDLPanel::SetCollsionModel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetCollsionModel(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (bVisible ^ *((_BYTE *)this + 2876)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C8C00
// Name: public: void CMDLPanel::SetGroundGrid(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetGroundGrid(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (2 * bVisible)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x004C8C20
// Name: public: void CMDLPanel::SetWireFrame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetWireFrame(CMDLPanel *this, bool bVisible)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (8 * bVisible)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x004C8C40
// Name: public: void CMDLPanel::SetLockView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetLockView(CMDLPanel *this, bool bLocked)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (4 * bLocked)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x004C8C60
// Name: public: void CMDLPanel::SetLookAtCamera(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetLookAtCamera(CMDLPanel *this, bool bLookAtCamera)
{
  *((_BYTE *)this + 2876) ^= (*((_BYTE *)this + 2876) ^ (16 * bLookAtCamera)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x004C8C80
// Name: public: virtual void CMDLPanel::SetMDL(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, const char *pMDLName, void *pProxyData)
{
  IMDLCache *v4; // eax
  int v5; // esi
  IMDLCache *v6; // eax

  if ( pMDLName != nullptr )
  {
    v4 = vgui::MDLCache();
    v5 = v4->FindMDL(this: v4, a2: pMDLName);
  }
  else
  {
    v5 = 0xFFFF;
  }
  v6 = vgui::MDLCache();
  if ( v6->IsErrorModel(this: v6, a2: v5) )
    v5 = 0xFFFF;
  this->SetMDL_2(this, a2: v5, a3: pProxyData);
}

//------------------------------------------------------------------------------
// Address: 0x004C8CE0
// Name: public: bool CMDLPanel::GetBoundingSphere(class Vector __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLPanel::GetBoundingSphere(CMDLPanel *this, Vector *vecCenter, float *flRadius)
{
  unsigned __int16 MDL; // ax
  int m_nSequence; // [esp-4h] [ebp-18h]
  Vector vecEngineCenter; // [esp+8h] [ebp-Ch] BYREF

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) == 0xFFFF )
    return 0;
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
  GetMDLBoundingSphere(pVecCenter: &vecEngineCenter, pRadius: flRadius, h: MDL, nSequence: m_nSequence);
  VectorTransform(in1: &vecEngineCenter.x, in2: &this->m_RootMDL.m_MDLToWorld, out: &vecCenter->x);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C8D50
// Name: public: void CMDLPanel::LookAtMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPanel::LookAtMDL(CMDLPanel *this@<ecx>, int a2@<edi>)
{
  Vector vecCenter; // [esp+8h] [ebp-10h] BYREF
  float flRadius; // [esp+14h] [ebp-4h] BYREF

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF && (*((_BYTE *)this + 2876) & 4) == 0 )
  {
    CMDLPanel::GetBoundingSphere(this, &vecCenter, &flRadius);
    CPotteryWheelPanel::LookAt(this, a2, &vecCenter, flRadius);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8DB0
// Name: public: void CMDLPanel::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSequence(CMDLPanel *this, int nSequence)
{
  this->m_RootMDL.m_MDL.m_nSequence = nSequence;
}

//------------------------------------------------------------------------------
// Address: 0x004C8DC0
// Name: public: void CMDLPanel::SetSequenceLayers(struct MDLSquenceLayer_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSequenceLayers(CMDLPanel *this, const MDLSquenceLayer_t *pSequenceLayers, int nCount)
{
  const MDLSquenceLayer_t *v3; // eax
  int v4; // esi
  int v5; // edx
  MDLSquenceLayer_t *m_SequenceLayers; // edx

  v3 = pSequenceLayers;
  v4 = 0;
  if ( pSequenceLayers != nullptr )
  {
    v5 = nCount;
    if ( nCount > 8 )
      v5 = 8;
    this->m_nNumSequenceLayers = v5;
    if ( v5 > 0 )
    {
      m_SequenceLayers = this->m_SequenceLayers;
      do
      {
        m_SequenceLayers->m_nSequenceIndex = v3->m_nSequenceIndex;
        m_SequenceLayers->m_flWeight = v3->m_flWeight;
        ++v4;
        ++v3;
        ++m_SequenceLayers;
      }
      while ( v4 < this->m_nNumSequenceLayers );
    }
  }
  else
  {
    this->m_nNumSequenceLayers = 0;
    _V_memset(dest: this->m_SequenceLayers, fill: 0, count: 64);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8E30
// Name: public: void CMDLPanel::SetSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSkin(CMDLPanel *this, int nSkin)
{
  this->m_RootMDL.m_MDL.m_nSkin = nSkin;
}

//------------------------------------------------------------------------------
// Address: 0x004C8E40
// Name: public: virtual void CMDLPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::OnTick(CMDLPanel *this)
{
  int v2; // eax
  int v3; // ecx

  CPotteryWheelPanel::OnTick(this);
  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v2 = _Plat_MSTime();
    v3 = dword_7BB3CC;
    if ( dword_7BB3CC == 0 )
      v3 = v2;
    *(float *)&dword_7BB3C8 = (float)((float)(v2 - v3) * 0.001) + *(float *)&dword_7BB3C8;
    dword_7BB3CC = v2;
    LODWORD(this->m_RootMDL.m_MDL.m_flTime) = dword_7BB3C8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8EA0
// Name: private: virtual void CMDLPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMDLPanel::OnMouseDoublePressed(CMDLPanel *this@<ecx>, int a2@<edi>, const char *code)
{
  Vector vecCenter; // [esp+8h] [ebp-10h] BYREF
  float flRadius; // [esp+14h] [ebp-4h] BYREF

  CMDLPanel::GetBoundingSphere(this, &vecCenter, &flRadius);
  CPotteryWheelPanel::LookAt(this, a2, &vecCenter, flRadius);
  CPotteryWheelPanel::OnMouseDoublePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004C8EE0
// Name: private: void CMDLPanel::UpdateStudioRenderConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::UpdateStudioRenderConfig(CMDLPanel *this)
{
  char v2; // al
  char v3; // al
  char v4; // al
  IStudioRender *v5; // eax

  memset(dst: (unsigned __int8 *)&s_StudioRenderConfig, value: 0, count: sizeof(s_StudioRenderConfig));
  v2 = (*((_BYTE *)&s_StudioRenderConfig + 36)
      ^ (r_eyemove.m_pParent->m_Value.m_nValue != 0))
     & 1
     ^ *((_BYTE *)&s_StudioRenderConfig + 36);
  *((_BYTE *)&s_StudioRenderConfig + 36) = v2;
  s_StudioRenderConfig.fEyeShiftX = r_eyeshift_x.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftY = r_eyeshift_y.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftZ = r_eyeshift_z.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeSize = r_eyesize.m_pParent->m_Value.m_fValue;
  if ( mat_softwareskin.m_pParent->m_Value.m_nValue != 0 || (*((_BYTE *)this + 2876) & 8) != 0 )
    v3 = v2 | 2;
  else
    v3 = v2 & 0xFD;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v3;
  *((_BYTE *)&s_StudioRenderConfig + 36) = (v3 ^ (4 * (r_nohw.m_pParent->m_Value.m_nValue != 0))) & 4 ^ v3;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ (8 * (r_nosw.m_pParent->m_Value.m_nValue != 0)))
                                          & 8;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ (16 * (r_teeth.m_pParent->m_Value.m_nValue != 0)))
                                          & 0x10;
  s_StudioRenderConfig.drawEntities = r_drawentities.m_pParent->m_Value.m_nValue;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ ((r_flex.m_pParent->m_Value.m_nValue != 0) << 6))
                                          & 0x40;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ (32 * (r_eyes.m_pParent->m_Value.m_nValue != 0)))
                                          & 0x20;
  *((_BYTE *)&s_StudioRenderConfig + 36) = (16 * *((_BYTE *)this + 2876))
                                         ^ (*((_BYTE *)&s_StudioRenderConfig + 36)
                                          ^ (16 * *((_BYTE *)this + 2876)))
                                         & 0x7F;
  *((_BYTE *)&s_StudioRenderConfig + 37) ^= (*((_BYTE *)&s_StudioRenderConfig + 37)
                                           ^ (mat_normals.m_pParent->m_Value.m_nValue != 0))
                                          & 1;
  s_StudioRenderConfig.skin = r_skin.m_pParent->m_Value.m_nValue;
  s_StudioRenderConfig.maxDecalsPerModel = r_maxmodeldecal.m_pParent->m_Value.m_nValue;
  v4 = ((*((_BYTE *)&s_StudioRenderConfig + 37)
       ^ (32 * (r_modelwireframedecal.m_pParent->m_Value.m_nValue != 0)))
      & 0x20
      ^ *((_BYTE *)&s_StudioRenderConfig + 37))
     & 0xF7;
  s_StudioRenderConfig.fullbright = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = v4;
  *((_BYTE *)&s_StudioRenderConfig + 37) = (v4 ^ (16 * (r_showenvcubemap.m_pParent->m_Value.m_nValue != 0))) & 0x10 ^ v4;
  s_StudioRenderConfig.fEyeGlintPixelWidthLODThreshold = r_eyeglintlodpixels.m_pParent->m_Value.m_fValue;
  v5 = vgui::StudioRender();
  v5->UpdateConfig(this: v5, a2: &s_StudioRenderConfig);
}

//------------------------------------------------------------------------------
// Address: 0x004C9150
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x004C9310
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPanel::GetMessageMap(CMDLPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetMessageMap'::`2'::s_pMap;
  `CMDLPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
  `CMDLPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C9350
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPanel::GetKBMap(CMDLPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetKBMap'::`2'::s_pMap;
  `CMDLPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
  `CMDLPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C9380
// Name: public: virtual CMDLPanel::~CMDLPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::~CMDLPanel(CMDLPanel *this)
{
  this->__vftable = (CMDLPanel_vtbl *)&CMDLPanel::`vftable';
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  CTextureReference::Shutdown(this: &this->m_DefaultEnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &this->m_DefaultHDREnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::~CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  if ( this->m_aMergeMDLs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aMergeMDLs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aMergeMDLs.m_Memory.m_pMemory);
      this->m_aMergeMDLs.m_Memory.m_pMemory = nullptr;
    }
    this->m_aMergeMDLs.m_Memory.m_nAllocationCount = 0;
  }
  CMDL::~CMDL(this: &this->m_RootMDL.m_MDL);
  CPotteryWheelPanel::~CPotteryWheelPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C9DE0
// Name: public: void CMDLPanel::SetPoseParameters(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetPoseParameters(CMDLPanel *this, const float *pPoseParameters, int nCount)
{
  int v4; // edi
  int v5; // esi
  float *v6; // eax
  unsigned int v7; // edx
  const float *v8; // ecx
  float *v9; // eax
  double v10; // st7
  IMDLCache_vtbl *v11; // ebx
  unsigned __int16 MDL; // ax
  const studiohdr_t *v13; // eax
  IMDLCache *v14; // [esp-4h] [ebp-78h]
  CStudioHdr studioHdr; // [esp+Ch] [ebp-68h] BYREF
  CMDLPanel *v16; // [esp+70h] [ebp-4h]

  v16 = this;
  if ( pPoseParameters != nullptr )
  {
    v4 = nCount;
    if ( nCount > 24 )
      v4 = 24;
    v5 = 0;
    if ( v4 >= 4 )
    {
      v6 = &v16->m_PoseParameters[1];
      v7 = ((unsigned int)(v4 - 4) >> 2) + 1;
      v8 = pPoseParameters + 2;
      v5 = 4 * v7;
      do
      {
        v6 += 4;
        *(v6 - 5) = *(v8 - 2);
        v8 += 4;
        --v7;
        *(v6 - 4) = *(v8 - 5);
        *(v6 - 3) = *(v8 - 4);
        *(v6 - 2) = *(v8 - 3);
      }
      while ( v7 != 0 );
    }
    if ( v5 < v4 )
    {
      v9 = &v16->m_PoseParameters[v5];
      do
      {
        v10 = pPoseParameters[v5++];
        *v9++ = v10;
      }
      while ( v5 < v4 );
    }
  }
  else if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v11 = g_pMDLCache->__vftable;
    v14 = g_pMDLCache;
    MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
    v13 = v11->GetStudioHdr(this: g_pMDLCache, a2: MDL);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v13, mdlcache: v14);
    Studio_CalcDefaultPoseParameters(pStudioHdr: &studioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
    CStudioHdr::Term(this: &studioHdr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneParent);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneFlags);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C9EF0
// Name: Create_CMDLPanel
// Source: json
//------------------------------------------------------------------------------
CMDLPanel *__cdecl Create_CMDLPanel()
{
  CMDLPanel *v0; // eax

  v0 = (CMDLPanel *)MemAlloc_Alloc(nSize: 0xBE4u);
  if ( v0 != nullptr )
    return CMDLPanel::CMDLPanel(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004C9F40
// Name: public: virtual void CMDLPanel::SetMDL(unsigned short,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, unsigned __int16 handle, void *pProxyData)
{
  int m_nSequence; // [esp-4h] [ebp-24h]
  Vector vecMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_RootMDL.m_MDL, h: handle);
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  this->m_RootMDL.m_MDL.m_pProxyData = pProxyData;
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: handle, nSequence: m_nSequence);
  this->m_RootMDL.m_MDL.m_bWorldSpaceViewTarget = false;
  this->m_RootMDL.m_MDL.m_vecViewTarget.x = 100.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.y = 0.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.z = vecMaxs.z;
  CMDLPanel::SetPoseParameters(this, pPoseParameters: nullptr, nCount: 0);
  this->m_nNumSequenceLayers = 0;
  _V_memset(dest: this->m_SequenceLayers, fill: 0, count: 64);
}

//------------------------------------------------------------------------------
// Address: 0x00607970
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

} // namespace sceneviewer

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102CB3C0
// Name: public: static char const __near * CMDLPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPanel::GetPanelClassName()
{
  return "CMDLPanel";
}

//------------------------------------------------------------------------------
// Address: 0x102CB3D0
// Name: public: virtual void CMDLPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::ApplySchemeSettings(CMDLPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  const Color *v4; // eax
  CMDLPanel_vtbl *v5; // ebx
  int v6; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->GetBgColor(this, result: &pScheme);
  CPotteryWheelPanel::SetBackgroundColor(this, c: v4);
  v5 = this->__vftable;
  v6 = (int)v2->GetBorder(this: v2, a2: "MenuBorder");
  v5->SetBorder(this, a2: (vgui::IBorder *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x102CB420
// Name: public: virtual void CMDLPanel::SetMDL(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, const char *pMDLName, void *pProxyData)
{
  IMDLCache *v4; // eax
  int v5; // esi
  IMDLCache *v6; // eax

  if ( pMDLName != nullptr )
  {
    v4 = vgui::MDLCache();
    v5 = v4->FindMDL(this: v4, a2: pMDLName);
  }
  else
  {
    v5 = 0xFFFF;
  }
  v6 = vgui::MDLCache();
  if ( v6->IsErrorModel(this: v6, a2: v5) )
    v5 = 0xFFFF;
  this->SetMDL_2(this, a2: v5, a3: pProxyData);
}

//------------------------------------------------------------------------------
// Address: 0x102CB480
// Name: public: bool CMDLPanel::GetBoundingBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLPanel::GetBoundingBox(CMDLPanel *this, Vector *vecBoundsMin, Vector *vecBoundsMax)
{
  unsigned __int16 MDL; // ax
  int m_nSequence; // [esp-4h] [ebp-Ch]

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) == 0xFFFF )
    return 0;
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
  GetMDLBoundingBox(pMins: vecBoundsMin, pMaxs: vecBoundsMax, h: MDL, nSequence: m_nSequence);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102CB4E0
// Name: public: bool CMDLPanel::GetBoundingSphere(class Vector __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLPanel::GetBoundingSphere(CMDLPanel *this, Vector *vecCenter, float *flRadius)
{
  unsigned __int16 MDL; // ax
  int m_nSequence; // [esp-4h] [ebp-18h]
  Vector vecEngineCenter; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) == 0xFFFF )
    return 0;
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
  GetMDLBoundingSphere(
    a1: COERCE_FLOAT(&savedregs),
    pVecCenter: &vecEngineCenter,
    pRadius: flRadius,
    h: MDL,
    nSequence: m_nSequence);
  VectorTransform(in1: &vecEngineCenter.x, in2: &this->m_RootMDL.m_MDLToWorld, out: &vecCenter->x);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102CB550
// Name: public: void CMDLPanel::SetModelAnglesAndPosition(class QAngle const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetModelAnglesAndPosition(CMDLPanel *this, const QAngle *angRot, const Vector *vecPos)
{
  matrix3x4_t *p_m_MDLToWorld; // esi

  p_m_MDLToWorld = &this->m_RootMDL.m_MDLToWorld;
  SetIdentityMatrix(matrix: &this->m_RootMDL.m_MDLToWorld);
  AngleMatrix(angles: angRot, position: vecPos, matrix: p_m_MDLToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x102CB580
// Name: public: void CMDLPanel::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetSequence(CMDLPanel *this, int nSequence)
{
  this->m_RootMDL.m_MDL.m_nSequence = nSequence;
}

//------------------------------------------------------------------------------
// Address: 0x102CB590
// Name: public: virtual void CMDLPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::OnTick(CMDLPanel *this)
{
  int v2; // eax
  int v3; // ecx

  CPotteryWheelPanel::OnTick(this);
  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v2 = _Plat_MSTime();
    v3 = dword_106934AC;
    if ( dword_106934AC == 0 )
      v3 = v2;
    *(float *)&dword_106934A8 = (float)((float)(v2 - v3) * 0.001) + *(float *)&dword_106934A8;
    dword_106934AC = v2;
    LODWORD(this->m_RootMDL.m_MDL.m_flTime) = dword_106934A8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CB5F0
// Name: private: virtual void CMDLPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::OnMouseDoublePressed(CMDLPanel *this, ButtonCode_t code)
{
  Vector vecCenter; // [esp+8h] [ebp-10h] BYREF
  float flRadius; // [esp+14h] [ebp-4h] BYREF

  CMDLPanel::GetBoundingSphere(this, &vecCenter, &flRadius);
  CPotteryWheelPanel::LookAt(this, &vecCenter, flRadius);
  CPotteryWheelPanel::OnMouseDoublePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x102CB630
// Name: private: void CMDLPanel::UpdateStudioRenderConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::UpdateStudioRenderConfig(CMDLPanel *this)
{
  int m_nValue; // eax
  char v3; // al
  char v4; // al
  int v5; // ecx
  char v6; // al
  int v7; // ecx
  char v8; // al
  int v9; // ecx
  char v10; // al
  int v11; // ecx
  char v12; // al
  int v13; // ecx
  int v14; // eax
  char v15; // al
  int v16; // ecx
  char v17; // al
  int v18; // ecx
  IStudioRender *v19; // eax

  memset(dst: (int)&s_StudioRenderConfig, value: nullptr, count: sizeof(s_StudioRenderConfig));
  if ( r_eyemove.m_pParent != nullptr )
    m_nValue = r_eyemove.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = (*((_BYTE *)&s_StudioRenderConfig + 36) ^ (m_nValue != 0)) & 1 ^ *((_BYTE *)&s_StudioRenderConfig + 36);
  *((_BYTE *)&s_StudioRenderConfig + 36) = v3;
  s_StudioRenderConfig.fEyeShiftX = r_eyeshift_x.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftY = r_eyeshift_y.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftZ = r_eyeshift_z.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeSize = r_eyesize.m_pParent->m_Value.m_fValue;
  if ( mat_softwareskin.m_pParent != nullptr && mat_softwareskin.m_pParent->m_Value.m_nValue != 0
    || (*((_BYTE *)this + 2876) & 8) != 0 )
  {
    v4 = v3 | 2;
  }
  else
  {
    v4 = v3 & 0xFD;
  }
  *((_BYTE *)&s_StudioRenderConfig + 36) = v4;
  if ( r_nohw.m_pParent != nullptr )
    v5 = r_nohw.m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  v6 = (v4 ^ (4 * (v5 != 0))) & 4 ^ v4;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v6;
  if ( r_nosw.m_pParent != nullptr )
    v7 = r_nosw.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  v8 = (v6 ^ (8 * (v7 != 0))) & 8 ^ v6;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v8;
  if ( r_teeth.m_pParent != nullptr )
    v9 = r_teeth.m_pParent->m_Value.m_nValue;
  else
    v9 = 0;
  v10 = (v8 ^ (16 * (v9 != 0))) & 0x10 ^ v8;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v10;
  if ( r_drawentities.m_pParent != nullptr )
    s_StudioRenderConfig.drawEntities = r_drawentities.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.drawEntities = 0;
  if ( r_flex.m_pParent != nullptr )
    v11 = r_flex.m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  v12 = (v10 ^ ((v11 != 0) << 6)) & 0x40 ^ v10;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v12;
  if ( r_eyes.m_pParent != nullptr )
    v13 = r_eyes.m_pParent->m_Value.m_nValue;
  else
    v13 = 0;
  *((_BYTE *)&s_StudioRenderConfig + 36) = (v12 ^ (32 * (v13 != 0))) & 0x20 ^ v12;
  *((_BYTE *)&s_StudioRenderConfig + 36) = (16 * *((_BYTE *)this + 2876))
                                         ^ (*((_BYTE *)&s_StudioRenderConfig + 36)
                                          ^ (16 * *((_BYTE *)this + 2876)))
                                         & 0x7F;
  if ( mat_normals.m_pParent != nullptr )
    v14 = mat_normals.m_pParent->m_Value.m_nValue;
  else
    v14 = 0;
  v15 = (*((_BYTE *)&s_StudioRenderConfig + 37) ^ (v14 != 0)) & 1 ^ *((_BYTE *)&s_StudioRenderConfig + 37);
  *((_BYTE *)&s_StudioRenderConfig + 37) = v15;
  if ( r_skin.m_pParent != nullptr )
    s_StudioRenderConfig.skin = r_skin.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.skin = 0;
  if ( r_maxmodeldecal.m_pParent != nullptr )
    s_StudioRenderConfig.maxDecalsPerModel = r_maxmodeldecal.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.maxDecalsPerModel = 0;
  if ( r_modelwireframedecal.m_pParent != nullptr )
    v16 = r_modelwireframedecal.m_pParent->m_Value.m_nValue;
  else
    v16 = 0;
  v17 = ((v15 ^ (32 * (v16 != 0))) & 0x20 ^ v15) & 0xF7;
  s_StudioRenderConfig.fullbright = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = v17;
  if ( r_showenvcubemap.m_pParent != nullptr )
    v18 = r_showenvcubemap.m_pParent->m_Value.m_nValue;
  else
    v18 = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = (v17 ^ (16 * (v18 != 0))) & 0x10 ^ v17;
  s_StudioRenderConfig.fEyeGlintPixelWidthLODThreshold = r_eyeglintlodpixels.m_pParent->m_Value.m_fValue;
  v19 = vgui::StudioRender();
  v19->UpdateConfig(this: v19, a2: &s_StudioRenderConfig);
}

//------------------------------------------------------------------------------
// Address: 0x102CB910
// Name: public: CMDLPanel::CMDLPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMDLPanel *__thiscall CMDLPanel::CMDLPanel(CMDLPanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  IMaterialSystem *v7; // eax
  ITexture *v8; // eax
  IMaterialSystem *v9; // eax
  ITexture *v10; // eax

  CPotteryWheelPanel::CPotteryWheelPanel(this, pParent, pName);
  this->__vftable = (CMDLPanel_vtbl *)&CMDLPanel::`vftable';
  if ( `CMDLPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
    v4->pfnClassName = CMDLPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  }
  if ( `CMDLPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMDLPanel");
    v5->pfnClassName = CMDLPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
  }
  if ( `CMDLPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
    v6->pfnClassName = CMDLPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  }
  CMDL::CMDL(this: &this->m_RootMDL.m_MDL);
  this->m_aMergeMDLs.m_Memory.m_pMemory = nullptr;
  this->m_aMergeMDLs.m_Memory.m_nAllocationCount = 0;
  this->m_aMergeMDLs.m_Memory.m_nGrowSize = 0;
  this->m_aMergeMDLs.m_Size = 0;
  this->m_aMergeMDLs.m_pElements = nullptr;
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  vgui::Panel::SetVisible(this, state: 1);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  v7 = vgui::MaterialSystem();
  v8 = v7->FindTexture(this: v7, a2: "editor/cubemap", a3: nullptr, a4: true, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultEnvCubemap, pTexture: v8);
  v9 = vgui::MaterialSystem();
  v10 = v9->FindTexture(this: v9, a2: "editor/cubemap.hdr", a3: nullptr, a4: true, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultHDREnvCubemap, pTexture: v10);
  SetIdentityMatrix(matrix: &this->m_RootMDL.m_MDLToWorld);
  *((_BYTE *)this + 2876) = *((_BYTE *)this + 2876) & 0xE0 | 0x10;
  this->m_nNumSequenceLayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CBAA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPanel::GetMessageMap(CMDLPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetMessageMap'::`2'::s_pMap;
  `CMDLPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
  `CMDLPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CBAD0
// Name: public: virtual struct PanelAnimationMap __near * CMDLPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPanel::GetAnimMap(CMDLPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPanel");
}

//------------------------------------------------------------------------------
// Address: 0x102CBAE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPanel::GetKBMap(CMDLPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPanel::GetKBMap'::`2'::s_pMap;
  `CMDLPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
  `CMDLPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CBB10
// Name: public: virtual CMDLPanel::~CMDLPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::~CMDLPanel(CMDLPanel *this)
{
  this->__vftable = (CMDLPanel_vtbl *)&CMDLPanel::`vftable';
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  CTextureReference::Shutdown(this: &this->m_DefaultEnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &this->m_DefaultHDREnvCubemap, bDeleteIfUnReferenced: false);
  CTextureReference::~CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(this: &this->m_aMergeMDLs);
  if ( this->m_aMergeMDLs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aMergeMDLs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aMergeMDLs.m_Memory.m_pMemory);
      this->m_aMergeMDLs.m_Memory.m_pMemory = nullptr;
    }
    this->m_aMergeMDLs.m_Memory.m_nAllocationCount = 0;
  }
  CMDL::~CMDL(this: &this->m_RootMDL.m_MDL);
  CPotteryWheelPanel::~CPotteryWheelPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102CBBB0
// Name: private: void CMDLPanel::DrawCollisionModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::DrawCollisionModel(CMDLPanel *this)
{
  IMDLCache *v2; // edi
  IMDLCache_vtbl *v3; // esi
  CMDLPanel::MDLData_t *p_m_RootMDL; // ebx
  unsigned __int16 MDL; // ax
  IMDLCache *v6; // eax
  IVPhysicsKeyParser *v7; // esi
  IMDLCache_vtbl *v8; // edi
  unsigned __int16 v9; // ax
  const studiohdr_t *v10; // eax
  const char *v11; // eax
  int v12; // eax
  IVPhysicsKeyParser_vtbl *v13; // edx
  int v14; // eax
  int (__thiscall *CreateDebugMesh)(IPhysicsCollision *, const struct CPhysCollide *, Vector **); // edx
  int v16; // edi
  IMatRenderContext *v17; // ebx
  IMesh *v18; // esi
  int v19; // edi
  int v20; // edi
  int i; // ebx
  float *m_pCurrPosition; // eax
  int a; // ecx
  float *v24; // eax
  int m_nVertexCount; // eax
  IMDLCache *v26; // [esp-8h] [ebp-38F8h]
  IMDLCache *v27; // [esp-4h] [ebp-38F4h]
  matrix3x4_t pBoneToWorld[256]; // [esp+Ch] [ebp-38E4h] BYREF
  char pName[1548]; // [esp+300Ch] [ebp-8E4h] BYREF
  int v30; // [esp+3618h] [ebp-2D8h]
  CStudioHdr pStudioHdr; // [esp+364Ch] [ebp-2A4h] BYREF
  matrix3x4_t matrix; // [esp+36B0h] [ebp-240h] BYREF
  CMeshBuilder v33; // [esp+36E0h] [ebp-210h] BYREF
  float out[3]; // [esp+38C8h] [ebp-28h] BYREF
  int v35; // [esp+38D4h] [ebp-1Ch]
  IMatRenderContext *v36; // [esp+38D8h] [ebp-18h]
  IMDLCache *v37; // [esp+38DCh] [ebp-14h]
  IVPhysicsKeyParser *v38; // [esp+38E0h] [ebp-10h]
  Vector *v39; // [esp+38E4h] [ebp-Ch] BYREF
  CMDLPanel *v40; // [esp+38E8h] [ebp-8h]
  int v41; // [esp+38ECh] [ebp-4h]

  v40 = this;
  v2 = vgui::MDLCache();
  v3 = v2->__vftable;
  p_m_RootMDL = &this->m_RootMDL;
  MDL = CMDL::GetMDL(this: &p_m_RootMDL->m_MDL);
  v6 = (IMDLCache *)v3->GetVCollide(this: v2, a2: MDL);
  v37 = v6;
  if ( v6 != nullptr && ((int)v6->__vftable & 0x7FFF) != 0 )
  {
    v27 = v6;
    v7 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *))g_pPhysicsCollision->VPhysicsKeyParserCreate)(a1: g_pPhysicsCollision);
    v8 = g_pMDLCache->__vftable;
    v26 = g_pMDLCache;
    v38 = v7;
    v9 = CMDL::GetMDL(this: &p_m_RootMDL->m_MDL);
    v10 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, IMDLCache *))v8->GetStudioHdr)(
                                 a1: g_pMDLCache,
                                 a2: v9,
                                 a3: v26);
    CStudioHdr::CStudioHdr(this: &pStudioHdr, pStudioHdr: v10, mdlcache: v27);
    CMDL::SetUpBones(
      this: &p_m_RootMDL->m_MDL,
      rootToWorld: &v40->m_RootMDL.m_MDLToWorld,
      nMaxBoneCount: 256,
      pBoneToWorld,
      pPoseParameters: nullptr,
      pSequenceLayers: nullptr,
      nNumSequenceLayers: 0);
    while ( !v7->Finished(this: v7) )
    {
      v11 = v7->GetCurrentBlockName(this: v7);
      v12 = _V_stricmp(s1: v11, s2: "solid");
      v13 = v7->__vftable;
      if ( v12 != 0 )
      {
        v13->SkipBlock(this: v7);
      }
      else
      {
        v13->ParseSolid(this: v7, a2: (solid_t *)pName, a3: nullptr);
        v14 = Studio_BoneIndexByName((mstudiobone_t *)&pStudioHdr, pName);
        CreateDebugMesh = g_pPhysicsCollision->CreateDebugMesh;
        v35 = v14;
        v16 = CreateDebugMesh(
                this: g_pPhysicsCollision,
                a2: *((const struct CPhysCollide **)&v37[1].Connect + v30),
                a3: &v39);
        v41 = v16;
        if ( v16 != 0 )
        {
          v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
          v36 = v17;
          if ( v17 != nullptr )
            v17->BeginRender(this: v17);
          v17->CullMode(this: v17, a2: MATERIAL_CULLMODE_CCW);
          SetIdentityMatrix(&matrix);
          if ( v35 >= 0 )
            MatrixCopy(in: &pBoneToWorld[v35], out: &matrix);
          v18 = v17->GetDynamicMesh(this: v17, a2: true, a3: nullptr, a4: nullptr, a5: v40->m_Wireframe.m_pMaterial);
          CMeshBuilder::CMeshBuilder(this: &v33);
          v33.m_pMesh = v18;
          v33.m_bGenerateIndices = true;
          v33.m_Type = MATERIAL_TRIANGLES;
          v19 = 3 * (v16 / 3);
          v18->SetPrimitiveType(this: v18, a2: MATERIAL_TRIANGLES);
          v33.m_pMesh->LockMesh(this: v33.m_pMesh, a2: v19, a3: v19, a4: &v33, a5: nullptr);
          v33.m_IndexBuilder.m_pIndices = v33.m_pIndices;
          v33.m_IndexBuilder.m_nIndexOffset = v33.m_nFirstVertex;
          v33.m_IndexBuilder.m_pIndexBuffer = &v18->IIndexBuffer;
          v33.m_IndexBuilder.m_nIndexSize = v33.m_nIndexSize;
          v33.m_IndexBuilder.m_nIndexCount = 0;
          v33.m_IndexBuilder.m_nMaxIndexCount = v19;
          v33.m_IndexBuilder.m_bModify = false;
          v33.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::AttachBegin(this: &v33.m_VertexBuilder, pMesh: v18, nMaxVertexCount: v19, desc: &v33);
          v20 = 0;
          v33.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::Reset(this: &v33.m_VertexBuilder);
          if ( v41 > 0 )
          {
            for ( i = v41; i != 0; --i )
            {
              VectorTransform(in1: &v39[v20].x, in2: &matrix, out);
              m_pCurrPosition = v33.m_VertexBuilder.m_pCurrPosition;
              a = color.a;
              *v33.m_VertexBuilder.m_pCurrPosition = out[0];
              m_pCurrPosition[1] = out[1];
              m_pCurrPosition[2] = out[2];
              *(_DWORD *)v33.m_VertexBuilder.m_pCurrColor = color.b | ((color.g | ((color.r | (a << 8)) << 8)) << 8);
              v24 = v33.m_VertexBuilder.m_pCurrTexCoord[0];
              *v33.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
              v24[1] = 0.0;
              CVertexBuilder::AdvanceVertex(this: &v33.m_VertexBuilder);
              ++v20;
            }
            v17 = v36;
          }
          if ( v33.m_bGenerateIndices )
          {
            switch ( v33.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * v33.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * v33.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * v33.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * v33.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = v33.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &v33.m_IndexBuilder,
              primitiveType: v33.m_Type,
              nIndexCount: m_nVertexCount);
          }
          v33.m_pMesh->UnlockMesh(
            this: v33.m_pMesh,
            a2: v33.m_VertexBuilder.m_nVertexCount,
            a3: v33.m_IndexBuilder.m_nIndexCount,
            a4: &v33);
          v33.m_IndexBuilder.m_pIndexBuffer = nullptr;
          v33.m_IndexBuilder.m_nMaxIndexCount = 0;
          v33.m_VertexBuilder.m_nMaxVertexCount = 0;
          v33.m_VertexBuilder.m_pVertexBuffer = nullptr;
          v33.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          v33.m_pMesh = nullptr;
          v18->Draw_2(this: v18, a2: -1, a3: 0);
          if ( v33.m_VertexBuilder.m_pVertexBuffer != nullptr
            && v33.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v33.m_VertexBuilder.m_pVertexBuffer) )
          {
            v33.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v33.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( v33.m_IndexBuilder.m_pIndexBuffer != nullptr
            && v33.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v33.m_IndexBuilder.m_pIndexBuffer) )
          {
            v33.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v33.m_IndexBuilder.m_pIndexBuffer);
          }
          v17->EndRender(this: v17);
          v17->Release(this: v17);
          v7 = v38;
          v16 = v41;
        }
        g_pPhysicsCollision->DestroyDebugMesh(this: g_pPhysicsCollision, a2: v16, a3: v39);
      }
    }
    g_pPhysicsCollision->VPhysicsKeyParserDestroy(this: g_pPhysicsCollision, a2: v7);
    CStudioHdr::Term(this: &pStudioHdr);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pStudioHdr.m_boneParent);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pStudioHdr.m_boneFlags);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pStudioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CC060
// Name: private: virtual void CMDLPanel::OnPaint3D(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPanel::OnPaint3D(CMDLPanel *this@<ecx>, int a2@<ebx>, IMDLCache *a3@<edi>)
{
  IStudioRender *v4; // eax
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // ebx
  IMaterialSystemHardwareConfig *v8; // eax
  ITexture *LightProbeCubemap; // eax
  float x; // xmm0_4
  IMDLCache_vtbl *v11; // edi
  unsigned __int16 MDL; // ax
  const studiohdr_t *v13; // eax
  matrix3x4_t *v14; // eax
  float v15; // edi
  int v16; // ebx
  IMDLCache_vtbl *v17; // edi
  unsigned __int16 v18; // ax
  const studiohdr_t *v19; // eax
  int *m_pMemory; // eax
  int *v21; // eax
  const studiohdr_t **v22; // eax
  IStudioRender *v23; // eax
  int *v24; // eax
  int *v25; // eax
  const studiohdr_t **v26; // eax
  int numbones; // [esp-18h] [ebp-3168h]
  IMDLCache *v28; // [esp-8h] [ebp-3158h]
  int m_nNumSequenceLayers; // [esp-8h] [ebp-3158h]
  IMDLCache *v30; // [esp-8h] [ebp-3158h]
  matrix3x4_t pMergeBoneToWorld; // [esp+4h] [ebp-314Ch] BYREF
  StudioRenderConfig_t v33; // [esp+3004h] [ebp-14Ch] BYREF
  matrix3x4_t pWorldToCamera; // [esp+303Ch] [ebp-114h] BYREF
  CStudioHdr pMergeHdr; // [esp+306Ch] [ebp-E4h] BYREF
  CStudioHdr pFollow; // [esp+30D0h] [ebp-80h] BYREF
  Vector out; // [esp+3138h] [ebp-18h] BYREF
  int v38; // [esp+3144h] [ebp-Ch]
  int v39; // [esp+3148h] [ebp-8h]
  int m_Size; // [esp+314Ch] [ebp-4h]

  if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v4 = vgui::StudioRender();
    ((void (__thiscall *)(IStudioRender *, StudioRenderConfig_t *, int))v4->GetCurrentConfig)(a1: v4, a2: &v33, a3: a2);
    CMDLPanel::UpdateStudioRenderConfig(this);
    v5 = vgui::MaterialSystem();
    v6 = (int)v5->GetRenderContext(this: v5);
    v7 = v6;
    v38 = v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v7 + 464))(a1: v7, a2: 10, a3: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 336))(a1: v7, a2: 0);
    v39 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 520))(a1: v7);
    v8 = vgui::MaterialSystemHardwareConfig();
    if ( v8->GetHDRType(this: v8) != HDR_TYPE_NONE )
    {
      if ( CPotteryWheelPanel::HasLightProbe(this) )
        LightProbeCubemap = CPotteryWheelPanel::GetLightProbeCubemap(this, bHDR: true);
      else
        LightProbeCubemap = this->m_DefaultHDREnvCubemap.m_pTexture;
    }
    else if ( CPotteryWheelPanel::HasLightProbe(this) )
    {
      LightProbeCubemap = CPotteryWheelPanel::GetLightProbeCubemap(this, bHDR: false);
    }
    else
    {
      LightProbeCubemap = this->m_DefaultEnvCubemap.m_pTexture;
    }
    (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v7 + 20))(a1: v7, a2: LightProbeCubemap);
    if ( (*((_BYTE *)this + 2876) & 2) != 0 )
      CPotteryWheelPanel::DrawGrid(this);
    if ( (*((_BYTE *)this + 2876) & 0x10) != 0 )
    {
      CPotteryWheelPanel::ComputeCameraTransform(this, &pWorldToCamera);
      MatrixGetColumn(in: &pWorldToCamera, column: 3, &out);
      x = out.x;
      this->m_RootMDL.m_MDL.m_bWorldSpaceViewTarget = true;
      this->m_RootMDL.m_MDL.m_vecViewTarget.x = x;
      this->m_RootMDL.m_MDL.m_vecViewTarget.y = out.y;
      this->m_RootMDL.m_MDL.m_vecViewTarget.z = out.z;
    }
    v11 = g_pMDLCache->__vftable;
    v28 = g_pMDLCache;
    MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
    v13 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, IMDLCache *))v11->GetStudioHdr)(
                                 a1: g_pMDLCache,
                                 a2: MDL,
                                 a3: v28);
    CStudioHdr::CStudioHdr(this: &pFollow, pStudioHdr: v13, mdlcache: a3);
    v14 = (matrix3x4_t *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 392))(
                           a1: v7,
                           a2: 48 * pFollow.m_pStudioHdr->numbones);
    m_nNumSequenceLayers = this->m_nNumSequenceLayers;
    v15 = *(float *)&v14;
    numbones = pFollow.m_pStudioHdr->numbones;
    LODWORD(out.x) = v14;
    CMDL::SetUpBones(
      this: &this->m_RootMDL.m_MDL,
      rootToWorld: &this->m_RootMDL.m_MDLToWorld,
      nMaxBoneCount: numbones,
      pBoneToWorld: v14,
      pPoseParameters: this->m_PoseParameters,
      pSequenceLayers: this->m_SequenceLayers,
      nNumSequenceLayers: m_nNumSequenceLayers);
    CMDL::Draw(
      this: &this->m_RootMDL.m_MDL,
      rootToWorld: &this->m_RootMDL.m_MDLToWorld,
      pBoneToWorld: (const matrix3x4_t *)LODWORD(v15),
      flags: 32);
    if ( this->m_aMergeMDLs.m_Size > 0 )
    {
      v16 = 0;
      m_Size = this->m_aMergeMDLs.m_Size;
      do
      {
        v17 = g_pMDLCache->__vftable;
        v30 = g_pMDLCache;
        v18 = CMDL::GetMDL(this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL);
        v19 = v17->GetStudioHdr(this: g_pMDLCache, a2: v18);
        CStudioHdr::CStudioHdr(this: &pMergeHdr, pStudioHdr: v19, mdlcache: v30);
        CMDL::SetupBonesWithBoneMerge(
          this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL,
          &pMergeHdr,
          &pMergeBoneToWorld,
          &pFollow,
          pFollowBoneToWorld: (const matrix3x4_t *)LODWORD(out.x),
          matModelToWorld: &this->m_RootMDL.m_MDLToWorld);
        CMDL::Draw(
          this: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDL,
          rootToWorld: &this->m_aMergeMDLs.m_Memory.m_pMemory[v16].m_MDLToWorld,
          pBoneToWorld: &pMergeBoneToWorld,
          flags: 32);
        CStudioHdr::Term(this: &pMergeHdr);
        m_pMemory = pMergeHdr.m_boneParent.m_Memory.m_pMemory;
        pMergeHdr.m_boneParent.m_Size = 0;
        if ( pMergeHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_boneParent.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            pMergeHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_boneParent.m_pElements = m_pMemory;
        if ( pMergeHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            pMergeHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
        }
        v21 = pMergeHdr.m_boneFlags.m_Memory.m_pMemory;
        pMergeHdr.m_boneFlags.m_Size = 0;
        if ( pMergeHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_boneFlags.m_Memory.m_pMemory);
            v21 = nullptr;
            pMergeHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_boneFlags.m_pElements = v21;
        if ( pMergeHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v21 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
            pMergeHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
        }
        v22 = pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
        pMergeHdr.m_pStudioHdrCache.m_Size = 0;
        if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
            v22 = nullptr;
            pMergeHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
          }
          pMergeHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
        }
        pMergeHdr.m_pStudioHdrCache.m_pElements = v22;
        if ( pMergeHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v22 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        ++v16;
        --m_Size;
      }
      while ( m_Size != 0 );
      v7 = v38;
      v15 = out.x;
    }
    if ( v15 != 0.0 )
      (*(void (__thiscall **)(int, float))(*(_DWORD *)v7 + 396))(a1: v7, a2: COERCE_FLOAT(LODWORD(v15)));
    if ( (*((_BYTE *)this + 2876) & 1) != 0 )
      CMDLPanel::DrawCollisionModel(this);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 16))(a1: v7, a2: 0);
    v23 = vgui::StudioRender();
    v23->UpdateConfig(this: v23, a2: &v33);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 20))(a1: v7, a2: v39);
    CStudioHdr::Term(this: &pFollow);
    v24 = pFollow.m_boneParent.m_Memory.m_pMemory;
    pFollow.m_boneParent.m_Size = 0;
    if ( pFollow.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_boneParent.m_Memory.m_pMemory);
        v24 = nullptr;
        pFollow.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_boneParent.m_pElements = v24;
    if ( pFollow.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v24 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
        pFollow.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v25 = pFollow.m_boneFlags.m_Memory.m_pMemory;
    pFollow.m_boneFlags.m_Size = 0;
    if ( pFollow.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_boneFlags.m_Memory.m_pMemory);
        v25 = nullptr;
        pFollow.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_boneFlags.m_pElements = v25;
    if ( pFollow.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v25 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
        pFollow.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v26 = pFollow.m_pStudioHdrCache.m_Memory.m_pMemory;
    pFollow.m_pStudioHdrCache.m_Size = 0;
    if ( pFollow.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pFollow.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFollow.m_pStudioHdrCache.m_Memory.m_pMemory);
        v26 = nullptr;
        pFollow.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    pFollow.m_pStudioHdrCache.m_pElements = v26;
    if ( pFollow.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v26 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
        pFollow.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      pFollow.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CC570
// Name: public: void CMDLPanel::SetPoseParameters(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetPoseParameters(CMDLPanel *this, const float *pPoseParameters, int nCount)
{
  int v4; // edi
  int v5; // esi
  float *v6; // eax
  unsigned int v7; // edx
  const float *v8; // ecx
  float *v9; // eax
  double v10; // st7
  IMDLCache_vtbl *v11; // ebx
  unsigned __int16 MDL; // ax
  const studiohdr_t *v13; // eax
  IMDLCache *v14; // [esp-4h] [ebp-78h]
  CStudioHdr studioHdr; // [esp+Ch] [ebp-68h] BYREF
  CMDLPanel *v16; // [esp+70h] [ebp-4h]

  v16 = this;
  if ( pPoseParameters != nullptr )
  {
    v4 = nCount;
    if ( nCount > 24 )
      v4 = 24;
    v5 = 0;
    if ( v4 >= 4 )
    {
      v6 = &v16->m_PoseParameters[1];
      v7 = ((unsigned int)(v4 - 4) >> 2) + 1;
      v8 = pPoseParameters + 2;
      v5 = 4 * v7;
      do
      {
        v6 += 4;
        *(v6 - 5) = *(v8 - 2);
        v8 += 4;
        --v7;
        *(v6 - 4) = *(v8 - 5);
        *(v6 - 3) = *(v8 - 4);
        *(v6 - 2) = *(v8 - 3);
      }
      while ( v7 != 0 );
    }
    if ( v5 < v4 )
    {
      v9 = &v16->m_PoseParameters[v5];
      do
      {
        v10 = pPoseParameters[v5++];
        *v9++ = v10;
      }
      while ( v5 < v4 );
    }
  }
  else if ( CMDL::GetMDL(this: &this->m_RootMDL.m_MDL) != 0xFFFF )
  {
    v11 = g_pMDLCache->__vftable;
    v14 = g_pMDLCache;
    MDL = CMDL::GetMDL(this: &this->m_RootMDL.m_MDL);
    v13 = v11->GetStudioHdr(this: g_pMDLCache, a2: MDL);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v13, mdlcache: v14);
    Studio_CalcDefaultPoseParameters(pStudioHdr: &studioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
    CStudioHdr::Term(this: &studioHdr);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CC680
// Name: Create_CMDLPanel
// Source: json
//------------------------------------------------------------------------------
CMDLPanel *__cdecl Create_CMDLPanel()
{
  CMDLPanel *v0; // eax

  v0 = (CMDLPanel *)MemAlloc_Alloc(nSize: 0xBE4u);
  if ( v0 != nullptr )
    return CMDLPanel::CMDLPanel(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CC6D0
// Name: public: virtual void CMDLPanel::SetMDL(unsigned short,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPanel::SetMDL(CMDLPanel *this, int handle, void *pProxyData)
{
  int m_nSequence; // [esp-4h] [ebp-24h]
  Vector vecMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_RootMDL.m_MDL, h: handle);
  m_nSequence = this->m_RootMDL.m_MDL.m_nSequence;
  this->m_RootMDL.m_MDL.m_pProxyData = pProxyData;
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: handle, nSequence: m_nSequence);
  this->m_RootMDL.m_MDL.m_bWorldSpaceViewTarget = false;
  this->m_RootMDL.m_MDL.m_vecViewTarget.x = 100.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.y = 0.0;
  this->m_RootMDL.m_MDL.m_vecViewTarget.z = vecMaxs.z;
  CMDLPanel::SetPoseParameters(this, pPoseParameters: nullptr, nCount: 0);
  this->m_nNumSequenceLayers = 0;
  _V_memset(dest: (int)this->m_SequenceLayers, fill: nullptr, count: 0x40u);
}

} // namespace client
