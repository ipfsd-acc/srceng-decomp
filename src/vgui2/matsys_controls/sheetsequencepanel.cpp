// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/sheetsequencepanel.cpp
// Functions: 66
// ============================================================

#include "vgui2\matsys_controls\sheetsequencepanel.h"

//------------------------------------------------------------------------------
// Address: 0x004C5840
// Name: public: static char const __near * CSheetSequencePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSheetSequencePanel::GetPanelClassName()
{
  return "CSheetSequencePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004C5850
// Name: GetPowerOfTwoFrameBufferTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetPowerOfTwoFrameBufferTexture()
{
  ITexture *result; // eax
  IMaterialSystem *v1; // eax
  ITexture *v2; // eax

  result = s_pPowerOfTwoFrameBufferTexture_SheetSeq.m_pTexture;
  if ( s_pPowerOfTwoFrameBufferTexture_SheetSeq.m_pTexture == nullptr )
  {
    v1 = vgui::MaterialSystem();
    v2 = v1->FindTexture(this: v1, a2: "_rt_PowerOfTwoFB", a3: "RenderTargets", a4: true, a5: 0);
    CTextureReference::Init(this: &s_pPowerOfTwoFrameBufferTexture_SheetSeq, pTexture: v2);
    return s_pPowerOfTwoFrameBufferTexture_SheetSeq.m_pTexture;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C5890
// Name: private: static void CSheetSequencePanel::EnsureMaterialsExist(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSheetSequencePanel::EnsureMaterialsExist()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( !CSheetSequencePanel::m_sMaterialsInitialized )
  {
    v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v0 != nullptr )
      v1 = KeyValues::KeyValues(this: v0, setName: "DebugTextureView");
    else
      v1 = nullptr;
    KeyValues::SetString(this: v1, keyName: "$basetexture", value: defaultValue);
    KeyValues::SetInt(this: v1, keyName: "$ShowAlpha", value: 1);
    CMaterialReference::Init(
      this: &CSheetSequencePanel::m_sAlphaMat,
      pMaterialName: "SheetSequenceAlphaMaterial",
      pVMTKeyValues: v1);
    CSheetSequencePanel::m_sAlphaMat.m_pMaterial->Refresh(this: CSheetSequencePanel::m_sAlphaMat.m_pMaterial);
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "DebugTextureView");
    else
      v3 = nullptr;
    KeyValues::SetString(this: v3, keyName: "$basetexture", value: defaultValue);
    KeyValues::SetInt(this: v3, keyName: "$ShowAlpha", value: 0);
    CMaterialReference::Init(
      this: &CSheetSequencePanel::m_sColorMat,
      pMaterialName: "SheetSequenceColorMaterial",
      pVMTKeyValues: v3);
    CSheetSequencePanel::m_sColorMat.m_pMaterial->Refresh(this: CSheetSequencePanel::m_sColorMat.m_pMaterial);
    CSheetSequencePanel::m_sMaterialsInitialized = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C5970
// Name: private: void CSheetSequencePanel::PrepareMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::PrepareMaterials(CSheetSequencePanel *this)
{
  bool IsMaterialSeparateAlphaColorMaterial; // al
  IMaterial *m_pMaterial; // ecx
  int v4; // eax
  int (__thiscall ***v5)(_DWORD); // esi
  int v6; // eax
  ITexture *v7; // esi
  IMaterialVar *v8; // eax
  IMaterialVar *v9; // eax
  bool bFound; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_Material.m_pMaterial != nullptr )
  {
    IsMaterialSeparateAlphaColorMaterial = CSheetExtended::IsMaterialSeparateAlphaColorMaterial(pMat: this->m_Material.m_pMaterial);
    m_pMaterial = this->m_Material.m_pMaterial;
    this->m_bSeparateAlphaColorMaterial = IsMaterialSeparateAlphaColorMaterial;
    bFound = false;
    v4 = (int)m_pMaterial->FindVar(this: m_pMaterial, a2: "$basetexture", a3: &bFound, a4: true);
    v5 = (int (__thiscall ***)(_DWORD))v4;
    if ( v4 != 0 && bFound && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 72))(a1: v4) != 0 )
    {
      v6 = (**v5)(a1: v5);
      v7 = (ITexture *)v6;
      if ( v6 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 60))(a1: v6) == 0 )
      {
        v8 = CSheetSequencePanel::m_sAlphaMat.m_pMaterial->FindVar(
               this: CSheetSequencePanel::m_sAlphaMat.m_pMaterial,
               a2: "$basetexture",
               a3: &bFound,
               a4: 1);
        if ( bFound && v8 != nullptr )
        {
          v8->SetTextureValue(this: v8, a2: v7);
          v9 = CSheetSequencePanel::m_sColorMat.m_pMaterial->FindVar(
                 this: CSheetSequencePanel::m_sColorMat.m_pMaterial,
                 a2: "$basetexture",
                 a3: &bFound,
                 a4: 1);
          if ( bFound && v9 != nullptr )
            v9->SetTextureValue(this: v9, a2: v7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C5A50
// Name: public: void CSheetSequencePanel::SetSecondSequenceView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::SetSecondSequenceView(CSheetSequencePanel *this, bool bIsSecondSequenceView)
{
  this->m_bIsSecondSequenceView = bIsSecondSequenceView;
}

//------------------------------------------------------------------------------
// Address: 0x004C5A60
// Name: public: void CSheetSequencePanel::SetFromMaterialName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::SetFromMaterialName(CSheetSequencePanel *this, const char *pMaterialName)
{
  CSheetExtended *m_pSheet; // edi
  CSheetExtended *v4; // eax
  CSheetExtended *v5; // eax

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
  {
    CSheetExtended::~CSheetExtended(this: this->m_pSheet);
    free(pMem: m_pSheet);
  }
  CMaterialReference::Init(
    this: &this->m_Material,
    pMaterialName,
    pTextureGroupName: "editor material",
    bComplain: true);
  v4 = (CSheetExtended *)MemAlloc_Alloc(nSize: 8u);
  if ( v4 != nullptr )
    v5 = CSheetExtended::CSheetExtended(this: v4, pMaterial: this->m_Material.m_pMaterial);
  else
    v5 = nullptr;
  this->m_pSheet = v5;
  CSheetSequencePanel::PrepareMaterials(this);
  this->PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C5AE0
// Name: public: void CSheetSequencePanel::SetFromMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::SetFromMaterial(CSheetSequencePanel *this, IMaterial *sourceMaterial)
{
  CSheetExtended *m_pSheet; // edi
  CSheetExtended *v4; // eax
  CSheetExtended *v5; // eax

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
  {
    CSheetExtended::~CSheetExtended(this: this->m_pSheet);
    free(pMem: m_pSheet);
  }
  CMaterialReference::Init(this: &this->m_Material, pMaterial: sourceMaterial);
  v4 = (CSheetExtended *)MemAlloc_Alloc(nSize: 8u);
  if ( v4 != nullptr )
    v5 = CSheetExtended::CSheetExtended(this: v4, pMaterial: this->m_Material.m_pMaterial);
  else
    v5 = nullptr;
  this->m_pSheet = v5;
  CSheetSequencePanel::PrepareMaterials(this);
  this->PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C5B50
// Name: public: virtual void CSheetSequencePanel::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::OnCursorExited(CSheetSequencePanel *this)
{
  this->m_nHighlightedSequence = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C5B60
// Name: private: int CSheetSequencePanel::SequenceGridSquareSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetSequencePanel::SequenceGridSquareSize(CSheetSequencePanel *this)
{
  CSheetExtended *m_pSheet; // ecx
  int v2; // ecx

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
    v2 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: m_pSheet));
  else
    v2 = 0;
  if ( v2 != 0 )
    return 256 / v2;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C5BD0
// Name: private: int CSheetSequencePanel::SequenceGridRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetSequencePanel::SequenceGridRows(CSheetSequencePanel *this)
{
  CSheetExtended *m_pSheet; // ecx
  int SheetSequenceCount; // eax
  CSheetExtended *v5; // ecx
  int v6; // edi
  int v7; // ecx

  m_pSheet = this->m_pSheet;
  if ( m_pSheet == nullptr )
    return 0;
  SheetSequenceCount = CSheetExtended::GetSheetSequenceCount(this: m_pSheet);
  v5 = this->m_pSheet;
  v6 = SheetSequenceCount;
  if ( v5 != nullptr )
    v7 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v5));
  else
    v7 = 0;
  if ( v6 != 0 )
    return (v7 + v6 - 1) / v7;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C5C60
// Name: public: virtual void CSheetSequencePanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::OnMouseReleased(CSheetSequencePanel *this, ButtonCode_t mouseCode)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi

  if ( this->m_nHighlightedSequence != -1 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "SheetSequenceSelected");
    else
      v4 = nullptr;
    KeyValues::SetPtr(this: v4, keyName: "panel", value: this);
    KeyValues::SetInt(this: v4, keyName: "nSequenceNumber", value: this->m_nHighlightedSequence);
    KeyValues::SetInt(this: v4, keyName: "bIsSecondSequence", value: this->m_bIsSecondSequenceView);
    this->PostActionSignal(this, a2: v4);
  }
  this->SetVisible(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004C5CF0
// Name: public: CSheetSequencePanel::CSheetSequencePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSheetSequencePanel *__thiscall CSheetSequencePanel::CSheetSequencePanel(
        CSheetSequencePanel *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Menu::Menu(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CSheetSequencePanel_vtbl *)&CSheetSequencePanel::`vftable';
  if ( `CSheetSequencePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSheetSequencePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSheetSequencePanel");
    v4->pfnClassName = CSheetSequencePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Menu");
  }
  if ( `CSheetSequencePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSheetSequencePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSheetSequencePanel");
    v5->pfnClassName = CSheetSequencePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Menu");
  }
  if ( `CSheetSequencePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSheetSequencePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSheetSequencePanel");
    v6->pfnClassName = CSheetSequencePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Menu");
  }
  this->m_pSheet = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_nHighlightedSequence = -1;
  *(_WORD *)&this->m_bSeparateAlphaColorMaterial = 0;
  CSheetSequencePanel::EnsureMaterialsExist();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C5DE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSheetSequencePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSheetSequencePanel::GetMessageMap(CSheetSequencePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSheetSequencePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSheetSequencePanel::GetMessageMap'::`2'::s_pMap;
  `CSheetSequencePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSheetSequencePanel");
  `CSheetSequencePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C5E10
// Name: public: virtual struct PanelAnimationMap __near * CSheetSequencePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSheetSequencePanel::GetAnimMap(CSheetSequencePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSheetSequencePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004C5E20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSheetSequencePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSheetSequencePanel::GetKBMap(CSheetSequencePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSheetSequencePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSheetSequencePanel::GetKBMap'::`2'::s_pMap;
  `CSheetSequencePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSheetSequencePanel");
  `CSheetSequencePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C5E50
// Name: public: virtual void CSheetSequencePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::PerformLayout(CSheetSequencePanel *this)
{
  CSheetExtended *m_pSheet; // ecx
  int v3; // esi
  CSheetExtended *v4; // ecx
  int v5; // ecx
  int v6; // eax
  CSheetExtended *v7; // ecx
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  CSheetExtended *v11; // ecx
  int v12; // esi
  int v13; // eax
  int newWidth; // [esp+18h] [ebp-Ch]

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
    v3 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: m_pSheet));
  else
    v3 = 0;
  v4 = this->m_pSheet;
  if ( v4 != nullptr )
    v5 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v4));
  else
    v5 = 0;
  if ( v5 != 0 )
    v6 = 256 / v5;
  else
    v6 = 0;
  v7 = this->m_pSheet;
  newWidth = v3 * v6 + 4;
  if ( v7 != nullptr )
    v8 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v7));
  else
    v8 = 0;
  if ( v8 != 0 )
    v9 = 256 / v8;
  else
    v9 = 0;
  v10 = CSheetSequencePanel::SequenceGridRows(this);
  v11 = this->m_pSheet;
  v12 = v9 * v10 + 4;
  if ( v11 != nullptr && (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v11)) != 0 )
  {
    v13 = newWidth;
  }
  else
  {
    v13 = 32;
    v12 = 32;
  }
  vgui::Panel::SetSize(this, wide: v13, tall: v12);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C5FE0
// Name: public: virtual void CSheetSequencePanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::OnCursorMoved(CSheetSequencePanel *this, int x, int y)
{
  CSheetExtended *m_pSheet; // ecx
  CSheetExtended *v5; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // edi

  vgui::Menu::OnCursorMoved(this, x, y);
  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr && CSheetExtended::GetSheetSequenceCount(this: m_pSheet) != 0 )
  {
    v5 = this->m_pSheet;
    if ( v5 != nullptr )
      v6 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v5));
    else
      v6 = 0;
    v7 = CSheetSequencePanel::SequenceGridSquareSize(this);
    v8 = (x - 2) / v7;
    v9 = (y - 2) / v7;
    if ( v8 < 0
      || v9 < 0
      || v8 >= v6
      || v9 >= v6
      || (v10 = v6 * v9 + v8) >= CSheetExtended::GetSheetSequenceCount(this: this->m_pSheet) )
    {
      this->m_nHighlightedSequence = -1;
    }
    else
    {
      this->m_nHighlightedSequence = v10;
    }
  }
  else
  {
    this->m_nHighlightedSequence = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6130
// Name: public: virtual void CSheetSequencePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CSheetSequencePanel::Paint(CSheetSequencePanel *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  CSheetExtended *m_pSheet; // ecx
  IMaterialSystem *v6; // eax
  int v7; // eax
  int v8; // esi
  IMatSystemSurface *v9; // eax
  ITexture *PowerOfTwoFrameBufferTexture; // eax
  ITexture *v11; // ebx
  int v12; // ebx
  void (__thiscall *v13)(int, IMaterial *); // edx
  long double SequenceTimeSpan; // st6
  CSheetExtended *v15; // ecx
  int v16; // eax
  CSheetExtended *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  IMatSystemSurface *v20; // eax
  int v21; // ecx
  Color v22; // ebx
  void (__thiscall *DrawOutlinedRect)(vgui::ISurface *, int, int, int, int); // edx
  CSheetSequencePanel_vtbl *v24; // edx
  vgui::ISchemeManager_vtbl *v25; // ebx
  int v26; // eax
  vgui::IScheme *v27; // eax
  vgui::ISurface_vtbl *v28; // ebx
  vgui::IScheme_vtbl *v29; // edx
  int v30; // eax
  int v31; // ebx
  void (__thiscall *DrawSetTextColor)(vgui::ISurface *, Color); // eax
  wchar_t strBuffer[8]; // [esp+D4h] [ebp-64h] BYREF
  _BYTE bgColor[6]; // [esp+E4h] [ebp-54h] OVERLAPPED BYREF
  Vector vCenter; // [esp+ECh] [ebp-4Ch] BYREF
  float v36; // [esp+F8h] [ebp-40h]
  IMesh *pMesh; // [esp+FCh] [ebp-3Ch]
  float flOffset; // [esp+100h] [ebp-38h]
  float flAge; // [esp+104h] [ebp-34h]
  int y; // [esp+108h] [ebp-30h] BYREF
  int x; // [esp+10Ch] [ebp-2Ch] BYREF
  int nSequences; // [esp+110h] [ebp-28h]
  float flGridSquareSize; // [esp+114h] [ebp-24h]
  int v44; // [esp+118h] [ebp-20h]
  float v45; // [esp+11Ch] [ebp-1Ch]
  float v46; // [esp+120h] [ebp-18h]
  int i; // [esp+124h] [ebp-14h]
  Color drawColor; // [esp+128h] [ebp-10h]
  int w; // [esp+12Ch] [ebp-Ch] BYREF
  int h; // [esp+130h] [ebp-8h] BYREF
  bool bOnlyAlpha; // [esp+136h] [ebp-2h]
  bool bOnlyColor; // [esp+137h] [ebp-1h]

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::GetPos(this, &x, &y);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  i = -16777216;
  ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -16777216);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 1, a3: 1, a4: w - 1, a5: h - 1);
  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr && CSheetExtended::ValidSheetData(this: m_pSheet) )
  {
    v6 = vgui::MaterialSystem();
    v7 = ((int (__thiscall *)(IMaterialSystem *, int, int))v6->GetRenderContext)(a1: v6, a2: a3, a3: a2);
    v8 = v7;
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    v9 = vgui::MatSystemSurface();
    v9->Begin3DPaint(this: v9, a2: 2, a3: 2, a4: w - 2, a5: h - 2);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    (*(void (__thiscall **)(int, _DWORD, int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)v8 + 128))(
      a1: v8,
      a2: 0,
      a3: 0x40000000,
      a4: 0,
      a5: 0x40000000,
      a6: COERCE_UNSIGNED_INT64((double)(w - 2)),
      a7: HIDWORD(COERCE_UNSIGNED_INT64((double)(w - 2))),
      a8: COERCE_UNSIGNED_INT64((double)(h - 2)),
      a9: HIDWORD(COERCE_UNSIGNED_INT64((double)(h - 2))),
      a10: 0,
      a11: -1074790400,
      a12: 0,
      a13: 1072693248);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    if ( this->m_Material.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(this: this->m_Material.m_pMaterial, a2: true) )
    {
      PowerOfTwoFrameBufferTexture = GetPowerOfTwoFrameBufferTexture();
      v11 = PowerOfTwoFrameBufferTexture;
      if ( PowerOfTwoFrameBufferTexture != nullptr
        && !PowerOfTwoFrameBufferTexture->IsError(this: PowerOfTwoFrameBufferTexture) )
      {
        (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v8 + 68))(a1: v8, a2: v11);
        (*(void (__thiscall **)(int, ITexture *, _DWORD))(*(_DWORD *)v8 + 72))(a1: v8, a2: v11, a3: 0);
      }
    }
    this->GetBgColor(this, result: (Color *)bgColor);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v8 + 296))(
      a1: v8,
      a2: *(_DWORD *)bgColor,
      a3: *(_DWORD *)&bgColor[1],
      a4: *(_DWORD *)&bgColor[2],
      a5: 255);
    v12 = 0;
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v8 + 48))(a1: v8, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 176))(a1: v8, a2: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 216))(a1: v8, a2: 0);
    v13 = *(void (__thiscall **)(int, IMaterial *))(*(_DWORD *)v8 + 36);
    LOBYTE(i) = 0;
    bOnlyColor = false;
    bOnlyAlpha = false;
    if ( this->m_bSeparateAlphaColorMaterial )
    {
      if ( this->m_bIsSecondSequenceView )
      {
        v13(a1: v8, a2: CSheetSequencePanel::m_sColorMat.m_pMaterial);
        bOnlyColor = true;
      }
      else
      {
        v13(a1: v8, a2: CSheetSequencePanel::m_sAlphaMat.m_pMaterial);
        bOnlyAlpha = true;
      }
      LOBYTE(i) = 1;
    }
    else
    {
      v13(a1: v8, a2: this->m_Material.m_pMaterial);
    }
    pMesh = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v8 + 228))(
                       a1: v8,
                       a2: 1,
                       a3: 0,
                       a4: 0);
    *(double *)&vCenter.y = _Plat_FloatTime();
    SequenceTimeSpan = CSheetExtended::GetSequenceTimeSpan(this: this->m_pSheet, nSequenceIndex: 0);
    flAge = fmod(*(long double *)&vCenter.y, SequenceTimeSpan);
    v15 = this->m_pSheet;
    if ( v15 != nullptr )
    {
      flOffset = fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v15));
      nSequences = LOBYTE(flGridSquareSize) | 0x800;
      v44 = (int)flOffset;
    }
    else
    {
      v44 = 0;
    }
    v16 = CSheetSequencePanel::SequenceGridSquareSize(this);
    v17 = this->m_pSheet;
    flGridSquareSize = (float)v16;
    *(float *)&drawColor = (float)v16 * 0.5;
    flOffset = *(float *)&drawColor + 2.0;
    nSequences = CSheetExtended::GetSheetSequenceCount(this: v17);
    if ( nSequences > 0 )
    {
      do
      {
        v18 = (float)(v12 % v44);
        v19 = (float)(v12 / v44);
        v46 = v18;
        v45 = v19;
        if ( bOnlyColor )
        {
          if ( !CSheetExtended::SequenceHasColorData(this: this->m_pSheet, nSequenceIndex: v12) )
            goto LABEL_26;
          v19 = v45;
          v18 = v46;
        }
        if ( !bOnlyAlpha )
          goto LABEL_25;
        if ( CSheetExtended::SequenceHasAlphaData(this: this->m_pSheet, nSequenceIndex: v12) )
        {
          v19 = v45;
          v18 = v46;
LABEL_25:
          vCenter.x = (float)(v18 * flGridSquareSize) + flOffset;
          vCenter.y = (float)h - (float)((float)(v19 * flGridSquareSize) + flOffset);
          vCenter.z = 0.0;
          CSheetExtended::DrawSheet(
            this: this->m_pSheet,
            pMesh,
            &vCenter,
            flRadius: *(float *)&drawColor,
            nSheetSequence: v12,
            flAge,
            flSheetPreviewSpeed: 750.0,
            bLoopSheetPreview: true,
            nSecondarySequence: -1,
            bOverrideSpriteCard: i);
        }
LABEL_26:
        ++v12;
      }
      while ( v12 < nSequences );
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 88))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 80))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 88))(a1: v8);
    v20 = vgui::MatSystemSurface();
    v20->End3DPaint(this: v20);
    v21 = 0;
    i = 0;
    if ( nSequences > 0 )
    {
      while ( 1 )
      {
        *(float *)&drawColor = -1.7014118e38;
        flOffset = (float)(v21 % v44);
        flAge = (float)(v21 / v44);
        if ( this->m_nHighlightedSequence == v21 )
        {
          v46 = NAN;
          v22 = (Color)-1;
          *(float *)&drawColor = NAN;
        }
        else
        {
          v22 = drawColor;
        }
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v22);
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetTextColor)(a1: g_pVGuiSurface, a2: v22);
        DrawOutlinedRect = g_pVGuiSurface->DrawOutlinedRect;
        v36 = (float)(flAge * flGridSquareSize) + 2.0;
        vCenter.z = (float)(flOffset * flGridSquareSize) + 2.0;
        DrawOutlinedRect(
          this: g_pVGuiSurface,
          a2: (int)vCenter.z,
          a3: (int)v36,
          a4: (int)(float)((float)((float)(flOffset + 1.0) * flGridSquareSize) + 2.0),
          a5: (int)(float)((float)((float)(flAge + 1.0) * flGridSquareSize) + 2.0));
        V_snwprintf(pDest: strBuffer, maxLen: 8, pFormat: L"%d", i);
        v24 = this->__vftable;
        v25 = g_pVGuiSchemeManager->__vftable;
        pMesh = (IMesh *)g_pVGuiSchemeManager;
        v26 = v24->GetScheme(this);
        v27 = v25->GetIScheme(this: (vgui::ISchemeManager *)pMesh, a2: v26);
        v28 = g_pVGuiSurface->__vftable;
        v29 = v27->__vftable;
        pMesh = (IMesh *)g_pVGuiSurface;
        v30 = v29->GetFont(this: v27, a2: "DefaultVerySmall", a3: false);
        v28->DrawSetTextFont(this: (vgui::ISurface *)pMesh, a2: v30);
        g_pVGuiSurface->DrawSetTextPos(
          this: g_pVGuiSurface,
          a2: (int)(float)(vCenter.z + 2.0),
          a3: (int)(float)(v36 + 1.0));
        g_pVGuiSurface->DrawUnicodeString(this: g_pVGuiSurface, a2: strBuffer, a3: FONT_DRAW_DEFAULT);
        v31 = i;
        if ( bOnlyColor && !CSheetExtended::SequenceHasColorData(this: this->m_pSheet, nSequenceIndex: i)
          || bOnlyAlpha && !CSheetExtended::SequenceHasAlphaData(this: this->m_pSheet, nSequenceIndex: v31) )
        {
          DrawSetTextColor = g_pVGuiSurface->DrawSetTextColor;
          v45 = -1.7014636e38;
          ((void (__thiscall *)(vgui::ISurface *, int))DrawSetTextColor)(a1: g_pVGuiSurface, a2: -16776961);
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (int)(float)((float)((float)(flOffset + 0.5) * flGridSquareSize) + 2.0),
            a3: (int)(float)((float)((float)((float)(flAge + 0.5) * flGridSquareSize) + 2.0) + 1.0));
          g_pVGuiSurface->DrawUnicodeString(this: g_pVGuiSurface, a2: L"x", a3: FONT_DRAW_DEFAULT);
        }
        i = v31 + 1;
        if ( v31 + 1 >= nSequences )
          break;
        v21 = i;
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 12))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0067C940
// Name: _dynamic_initializer_for__CSheetSequencePanel::m_sColorMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSheetSequencePanel::m_sColorMat__()
{
  CMaterialReference::CMaterialReference(
    this: &CSheetSequencePanel::m_sColorMat,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CSheetSequencePanel::m_sColorMat__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C960
// Name: _dynamic_initializer_for__CSheetSequencePanel::m_sAlphaMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSheetSequencePanel::m_sAlphaMat__()
{
  CMaterialReference::CMaterialReference(
    this: &CSheetSequencePanel::m_sAlphaMat,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CSheetSequencePanel::m_sAlphaMat__);
}

//------------------------------------------------------------------------------
// Address: 0x00681BB0
// Name: _dynamic_atexit_destructor_for__CSheetSequencePanel::m_sColorMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSheetSequencePanel::m_sColorMat__()
{
  CMaterialReference::~CMaterialReference(this: &CSheetSequencePanel::m_sColorMat);
}

//------------------------------------------------------------------------------
// Address: 0x00681BC0
// Name: _dynamic_atexit_destructor_for__CSheetSequencePanel::m_sAlphaMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSheetSequencePanel::m_sAlphaMat__()
{
  CMaterialReference::~CMaterialReference(this: &CSheetSequencePanel::m_sAlphaMat);
}

//------------------------------------------------------------------------------
// Address: 0x0067C980
// Name: _dynamic_initializer_for__g_CMDLPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CMDLPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CMDLPanel_Helper,
           className: "CMDLPanel",
           func: Create_CMDLPanel);
}

//------------------------------------------------------------------------------
// Address: 0x0067C9A0
// Name: _dynamic_initializer_for__r_showenvcubemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_showenvcubemap__()
{
  ConVar::ConVar(this: &r_showenvcubemap, pName: "r_showenvcubemap", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_showenvcubemap__);
}

//------------------------------------------------------------------------------
// Address: 0x0067C9D0
// Name: _dynamic_initializer_for__r_eyegloss__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyegloss__()
{
  ConVar::ConVar(this: &r_eyegloss, pName: "r_eyegloss", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyegloss__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CA00
// Name: _dynamic_initializer_for__r_eyemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyemove__()
{
  ConVar::ConVar(this: &r_eyemove, pName: "r_eyemove", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyemove__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CA30
// Name: _dynamic_initializer_for__r_eyeshift_x__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyeshift_x__()
{
  ConVar::ConVar(this: &r_eyeshift_x, pName: "r_eyeshift_x", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyeshift_x__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CA60
// Name: _dynamic_initializer_for__r_eyeshift_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyeshift_y__()
{
  ConVar::ConVar(this: &r_eyeshift_y, pName: "r_eyeshift_y", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyeshift_y__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CA90
// Name: _dynamic_initializer_for__r_eyeshift_z__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyeshift_z__()
{
  ConVar::ConVar(this: &r_eyeshift_z, pName: "r_eyeshift_z", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyeshift_z__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CAC0
// Name: _dynamic_initializer_for__r_eyesize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyesize__()
{
  ConVar::ConVar(this: &r_eyesize, pName: "r_eyesize", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyesize__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CAF0
// Name: _dynamic_initializer_for__mat_softwareskin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_softwareskin__()
{
  ConVar::ConVar(this: &mat_softwareskin, pName: "mat_softwareskin", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_softwareskin__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CB20
// Name: _dynamic_initializer_for__r_nohw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_nohw__()
{
  ConVar::ConVar(this: &r_nohw, pName: "r_nohw", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_nohw__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CB50
// Name: _dynamic_initializer_for__r_nosw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_nosw__()
{
  ConVar::ConVar(this: &r_nosw, pName: "r_nosw", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_nosw__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CB80
// Name: _dynamic_initializer_for__r_teeth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_teeth__()
{
  ConVar::ConVar(this: &r_teeth, pName: "r_teeth", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_teeth__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CBB0
// Name: _dynamic_initializer_for__r_drawentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawentities__()
{
  ConVar::ConVar(this: &r_drawentities, pName: "r_drawentities", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawentities__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CBE0
// Name: _dynamic_initializer_for__r_flex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flex__()
{
  ConVar::ConVar(this: &r_flex, pName: "r_flex", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flex__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CC10
// Name: _dynamic_initializer_for__r_eyes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyes__()
{
  ConVar::ConVar(this: &r_eyes, pName: "r_eyes", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_eyes__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CC40
// Name: _dynamic_initializer_for__r_skin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_skin__()
{
  ConVar::ConVar(this: &r_skin, pName: "r_skin", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_skin__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CC70
// Name: _dynamic_initializer_for__r_maxmodeldecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_maxmodeldecal__()
{
  ConVar::ConVar(this: &r_maxmodeldecal, pName: "r_maxmodeldecal", pDefaultValue: "50", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_maxmodeldecal__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CCA0
// Name: _dynamic_initializer_for__r_modelwireframedecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_modelwireframedecal__()
{
  ConVar::ConVar(this: &r_modelwireframedecal, pName: "r_modelwireframedecal", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_modelwireframedecal__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CCD0
// Name: _dynamic_initializer_for__mat_normals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_normals__()
{
  ConVar::ConVar(this: &mat_normals, pName: "mat_normals", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_normals__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CD00
// Name: _dynamic_initializer_for__r_eyeglintlodpixels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyeglintlodpixels__()
{
  ConVar::ConVar(this: &r_eyeglintlodpixels, pName: "r_eyeglintlodpixels", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_eyeglintlodpixels__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CD30
// Name: _dynamic_initializer_for__r_rootlod__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_rootlod__()
{
  ConVar::ConVar(this: &r_rootlod, pName: "r_rootlod", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_rootlod__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CD60
// Name: _dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture__()
{
  CTextureReference::CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CD80
// Name: sub_67CD80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_67CD80()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_7755C4 = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x00681C10
// Name: _dynamic_atexit_destructor_for__r_showenvcubemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_showenvcubemap__()
{
  ConVar::~ConVar(this: &r_showenvcubemap);
}

//------------------------------------------------------------------------------
// Address: 0x00681C20
// Name: _dynamic_atexit_destructor_for__r_eyegloss__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyegloss__()
{
  ConVar::~ConVar(this: &r_eyegloss);
}

//------------------------------------------------------------------------------
// Address: 0x00681C30
// Name: _dynamic_atexit_destructor_for__r_eyemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyemove__()
{
  ConVar::~ConVar(this: &r_eyemove);
}

//------------------------------------------------------------------------------
// Address: 0x00681C40
// Name: _dynamic_atexit_destructor_for__r_eyeshift_x__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_x__()
{
  ConVar::~ConVar(this: &r_eyeshift_x);
}

//------------------------------------------------------------------------------
// Address: 0x00681C50
// Name: _dynamic_atexit_destructor_for__r_eyeshift_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_y__()
{
  ConVar::~ConVar(this: &r_eyeshift_y);
}

//------------------------------------------------------------------------------
// Address: 0x00681C60
// Name: _dynamic_atexit_destructor_for__r_eyeshift_z__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_z__()
{
  ConVar::~ConVar(this: &r_eyeshift_z);
}

//------------------------------------------------------------------------------
// Address: 0x00681C70
// Name: _dynamic_atexit_destructor_for__r_eyesize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyesize__()
{
  ConVar::~ConVar(this: &r_eyesize);
}

//------------------------------------------------------------------------------
// Address: 0x00681C80
// Name: _dynamic_atexit_destructor_for__mat_softwareskin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_softwareskin__()
{
  ConVar::~ConVar(this: &mat_softwareskin);
}

//------------------------------------------------------------------------------
// Address: 0x00681C90
// Name: _dynamic_atexit_destructor_for__r_nohw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_nohw__()
{
  ConVar::~ConVar(this: &r_nohw);
}

//------------------------------------------------------------------------------
// Address: 0x00681CA0
// Name: _dynamic_atexit_destructor_for__r_nosw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_nosw__()
{
  ConVar::~ConVar(this: &r_nosw);
}

//------------------------------------------------------------------------------
// Address: 0x00681CB0
// Name: _dynamic_atexit_destructor_for__r_teeth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_teeth__()
{
  ConVar::~ConVar(this: &r_teeth);
}

//------------------------------------------------------------------------------
// Address: 0x00681CC0
// Name: _dynamic_atexit_destructor_for__r_drawentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawentities__()
{
  ConVar::~ConVar(this: &r_drawentities);
}

//------------------------------------------------------------------------------
// Address: 0x00681CD0
// Name: _dynamic_atexit_destructor_for__r_flex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flex__()
{
  ConVar::~ConVar(this: &r_flex);
}

//------------------------------------------------------------------------------
// Address: 0x00681CE0
// Name: _dynamic_atexit_destructor_for__r_eyes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyes__()
{
  ConVar::~ConVar(this: &r_eyes);
}

//------------------------------------------------------------------------------
// Address: 0x00681CF0
// Name: _dynamic_atexit_destructor_for__r_skin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_skin__()
{
  ConVar::~ConVar(this: &r_skin);
}

//------------------------------------------------------------------------------
// Address: 0x00681D00
// Name: _dynamic_atexit_destructor_for__r_maxmodeldecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_maxmodeldecal__()
{
  ConVar::~ConVar(this: &r_maxmodeldecal);
}

//------------------------------------------------------------------------------
// Address: 0x00681D10
// Name: _dynamic_atexit_destructor_for__r_modelwireframedecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_modelwireframedecal__()
{
  ConVar::~ConVar(this: &r_modelwireframedecal);
}

//------------------------------------------------------------------------------
// Address: 0x00681D20
// Name: _dynamic_atexit_destructor_for__mat_normals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_normals__()
{
  ConVar::~ConVar(this: &mat_normals);
}

//------------------------------------------------------------------------------
// Address: 0x00681D30
// Name: _dynamic_atexit_destructor_for__r_eyeglintlodpixels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeglintlodpixels__()
{
  ConVar::~ConVar(this: &r_eyeglintlodpixels);
}

//------------------------------------------------------------------------------
// Address: 0x00681D40
// Name: _dynamic_atexit_destructor_for__r_rootlod__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_rootlod__()
{
  ConVar::~ConVar(this: &r_rootlod);
}

//------------------------------------------------------------------------------
// Address: 0x00681D50
// Name: _dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104CE6B0
// Name: public: static char const __near * CSheetSequencePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSheetSequencePanel::GetPanelClassName()
{
  return "CSheetSequencePanel";
}

//------------------------------------------------------------------------------
// Address: 0x104CE6C0
// Name: GetPowerOfTwoFrameBufferTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetPowerOfTwoFrameBufferTexture()
{
  ITexture *result; // eax
  IMaterialSystem *v1; // eax
  ITexture *v2; // eax

  result = s_pPowerOfTwoFrameBufferTexture_SheetSeq.m_pTexture;
  if ( s_pPowerOfTwoFrameBufferTexture_SheetSeq.m_pTexture == nullptr )
  {
    v1 = vgui::MaterialSystem();
    v2 = v1->FindTexture(this: v1, a2: "_rt_PowerOfTwoFB", a3: "RenderTargets", a4: true, a5: 0);
    CTextureReference::Init(this: &s_pPowerOfTwoFrameBufferTexture_SheetSeq, pTexture: v2);
    return s_pPowerOfTwoFrameBufferTexture_SheetSeq.m_pTexture;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CE700
// Name: private: static void CSheetSequencePanel::EnsureMaterialsExist(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSheetSequencePanel::EnsureMaterialsExist()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( !CSheetSequencePanel::m_sMaterialsInitialized )
  {
    v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v0 != nullptr )
      v1 = KeyValues::KeyValues(this: v0, setName: "DebugTextureView");
    else
      v1 = nullptr;
    KeyValues::SetString(this: v1, keyName: "$basetexture", value: (char *)&var);
    KeyValues::SetInt(this: v1, keyName: "$ShowAlpha", value: 1);
    CMaterialReference::Init(
      this: &CSheetSequencePanel::m_sAlphaMat,
      pMaterialName: "SheetSequenceAlphaMaterial",
      pVMTKeyValues: v1);
    CSheetSequencePanel::m_sAlphaMat.m_pMaterial->Refresh(this: CSheetSequencePanel::m_sAlphaMat.m_pMaterial);
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "DebugTextureView");
    else
      v3 = nullptr;
    KeyValues::SetString(this: v3, keyName: "$basetexture", value: (char *)&var);
    KeyValues::SetInt(this: v3, keyName: "$ShowAlpha", value: 0);
    CMaterialReference::Init(
      this: &CSheetSequencePanel::m_sColorMat,
      pMaterialName: "SheetSequenceColorMaterial",
      pVMTKeyValues: v3);
    CSheetSequencePanel::m_sColorMat.m_pMaterial->Refresh(this: CSheetSequencePanel::m_sColorMat.m_pMaterial);
    CSheetSequencePanel::m_sMaterialsInitialized = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CE7E0
// Name: private: void CSheetSequencePanel::PrepareMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::PrepareMaterials(CSheetSequencePanel *this)
{
  bool IsMaterialSeparateAlphaColorMaterial; // al
  IMaterial *m_pMaterial; // ecx
  int v4; // eax
  int (__thiscall ***v5)(_DWORD); // esi
  int v6; // eax
  ITexture *v7; // esi
  IMaterialVar *v8; // eax
  IMaterialVar *v9; // eax
  bool bFound; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_Material.m_pMaterial != nullptr )
  {
    IsMaterialSeparateAlphaColorMaterial = CSheetExtended::IsMaterialSeparateAlphaColorMaterial(pMat: this->m_Material.m_pMaterial);
    m_pMaterial = this->m_Material.m_pMaterial;
    this->m_bSeparateAlphaColorMaterial = IsMaterialSeparateAlphaColorMaterial;
    bFound = false;
    v4 = (int)m_pMaterial->FindVar(this: m_pMaterial, a2: "$basetexture", a3: &bFound, a4: true);
    v5 = (int (__thiscall ***)(_DWORD))v4;
    if ( v4 != 0 && bFound && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 72))(a1: v4) != 0 )
    {
      v6 = (**v5)(a1: v5);
      v7 = (ITexture *)v6;
      if ( v6 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 60))(a1: v6) == 0 )
      {
        v8 = CSheetSequencePanel::m_sAlphaMat.m_pMaterial->FindVar(
               this: CSheetSequencePanel::m_sAlphaMat.m_pMaterial,
               a2: "$basetexture",
               a3: &bFound,
               a4: 1);
        if ( bFound && v8 != nullptr )
        {
          v8->SetTextureValue(this: v8, a2: v7);
          v9 = CSheetSequencePanel::m_sColorMat.m_pMaterial->FindVar(
                 this: CSheetSequencePanel::m_sColorMat.m_pMaterial,
                 a2: "$basetexture",
                 a3: &bFound,
                 a4: 1);
          if ( bFound && v9 != nullptr )
            v9->SetTextureValue(this: v9, a2: v7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CE8C0
// Name: public: void CSheetSequencePanel::SetSecondSequenceView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::SetSecondSequenceView(CSheetSequencePanel *this, bool bIsSecondSequenceView)
{
  this->m_bIsSecondSequenceView = bIsSecondSequenceView;
}

//------------------------------------------------------------------------------
// Address: 0x104CE8D0
// Name: public: void CSheetSequencePanel::SetFromMaterialName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::SetFromMaterialName(CSheetSequencePanel *this, const char *pMaterialName)
{
  CSheetExtended *m_pSheet; // edi
  CSheetExtended *v4; // eax
  CSheetExtended *v5; // eax

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
  {
    CSheetExtended::~CSheetExtended(this: this->m_pSheet);
    operator delete(p: m_pSheet);
  }
  CMaterialReference::Init(
    this: &this->m_Material,
    pMaterialName,
    pTextureGroupName: "editor material",
    bComplain: true);
  v4 = (CSheetExtended *)operator new(nSize: 8u);
  if ( v4 != nullptr )
    v5 = CSheetExtended::CSheetExtended(this: v4, pMaterial: this->m_Material.m_pMaterial);
  else
    v5 = nullptr;
  this->m_pSheet = v5;
  CSheetSequencePanel::PrepareMaterials(this);
  this->PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CE950
// Name: public: void CSheetSequencePanel::SetFromMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::SetFromMaterial(CSheetSequencePanel *this, IMaterial *sourceMaterial)
{
  CSheetExtended *m_pSheet; // edi
  CSheetExtended *v4; // eax
  CSheetExtended *v5; // eax

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
  {
    CSheetExtended::~CSheetExtended(this: this->m_pSheet);
    operator delete(p: m_pSheet);
  }
  CMaterialReference::Init(this: &this->m_Material, pMaterial: sourceMaterial);
  v4 = (CSheetExtended *)operator new(nSize: 8u);
  if ( v4 != nullptr )
    v5 = CSheetExtended::CSheetExtended(this: v4, pMaterial: this->m_Material.m_pMaterial);
  else
    v5 = nullptr;
  this->m_pSheet = v5;
  CSheetSequencePanel::PrepareMaterials(this);
  this->PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CE9C0
// Name: public: virtual void CSheetSequencePanel::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::OnCursorExited(CSheetSequencePanel *this)
{
  this->m_nHighlightedSequence = -1;
}

//------------------------------------------------------------------------------
// Address: 0x104CE9D0
// Name: private: int CSheetSequencePanel::SequenceGridSquareSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetSequencePanel::SequenceGridSquareSize(CSheetSequencePanel *this)
{
  CSheetExtended *m_pSheet; // ecx
  int v2; // ecx

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
    v2 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: m_pSheet));
  else
    v2 = 0;
  if ( v2 != 0 )
    return 256 / v2;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104CEA40
// Name: private: int CSheetSequencePanel::SequenceGridRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetSequencePanel::SequenceGridRows(CSheetSequencePanel *this)
{
  CSheetExtended *m_pSheet; // ecx
  int SheetSequenceCount; // eax
  CSheetExtended *v5; // ecx
  int v6; // edi
  int v7; // ecx

  m_pSheet = this->m_pSheet;
  if ( m_pSheet == nullptr )
    return 0;
  SheetSequenceCount = CSheetExtended::GetSheetSequenceCount(this: m_pSheet);
  v5 = this->m_pSheet;
  v6 = SheetSequenceCount;
  if ( v5 != nullptr )
    v7 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v5));
  else
    v7 = 0;
  if ( v6 != 0 )
    return (v7 + v6 - 1) / v7;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104CEAD0
// Name: public: virtual void CSheetSequencePanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::OnMouseReleased(CSheetSequencePanel *this, ButtonCode_t mouseCode)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi

  if ( this->m_nHighlightedSequence != -1 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "SheetSequenceSelected");
    else
      v4 = nullptr;
    KeyValues::SetPtr(this: v4, keyName: "panel", value: this);
    KeyValues::SetInt(this: v4, keyName: "nSequenceNumber", value: this->m_nHighlightedSequence);
    KeyValues::SetInt(this: v4, keyName: "bIsSecondSequence", value: this->m_bIsSecondSequenceView);
    this->PostActionSignal(this, a2: v4);
  }
  this->SetVisible(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x104CEB60
// Name: public: CSheetSequencePanel::CSheetSequencePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSheetSequencePanel *__thiscall CSheetSequencePanel::CSheetSequencePanel(
        CSheetSequencePanel *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Menu::Menu(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CSheetSequencePanel_vtbl *)&CSheetSequencePanel::`vftable';
  if ( `CSheetSequencePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSheetSequencePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSheetSequencePanel");
    v4->pfnClassName = CSheetSequencePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Menu");
  }
  if ( `CSheetSequencePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSheetSequencePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSheetSequencePanel");
    v5->pfnClassName = CSheetSequencePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Menu");
  }
  if ( `CSheetSequencePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSheetSequencePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSheetSequencePanel");
    v6->pfnClassName = CSheetSequencePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Menu");
  }
  this->m_pSheet = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_nHighlightedSequence = -1;
  *(_WORD *)&this->m_bSeparateAlphaColorMaterial = 0;
  CSheetSequencePanel::EnsureMaterialsExist();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CEC50
// Name: public: virtual struct vgui::PanelMessageMap __near * CSheetSequencePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSheetSequencePanel::GetMessageMap(CSheetSequencePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSheetSequencePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSheetSequencePanel::GetMessageMap'::`2'::s_pMap;
  `CSheetSequencePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSheetSequencePanel");
  `CSheetSequencePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CEC80
// Name: public: virtual struct PanelAnimationMap __near * CSheetSequencePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSheetSequencePanel::GetAnimMap(CSheetSequencePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSheetSequencePanel");
}

//------------------------------------------------------------------------------
// Address: 0x104CEC90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSheetSequencePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSheetSequencePanel::GetKBMap(CSheetSequencePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSheetSequencePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSheetSequencePanel::GetKBMap'::`2'::s_pMap;
  `CSheetSequencePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSheetSequencePanel");
  `CSheetSequencePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CECC0
// Name: public: virtual void CSheetSequencePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::PerformLayout(CSheetSequencePanel *this)
{
  CSheetExtended *m_pSheet; // ecx
  int v3; // esi
  CSheetExtended *v4; // ecx
  int v5; // ecx
  int v6; // eax
  CSheetExtended *v7; // ecx
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  CSheetExtended *v11; // ecx
  int v12; // esi
  int v13; // eax
  int newWidth; // [esp+18h] [ebp-Ch]

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
    v3 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: m_pSheet));
  else
    v3 = 0;
  v4 = this->m_pSheet;
  if ( v4 != nullptr )
    v5 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v4));
  else
    v5 = 0;
  if ( v5 != 0 )
    v6 = 256 / v5;
  else
    v6 = 0;
  v7 = this->m_pSheet;
  newWidth = v3 * v6 + 4;
  if ( v7 != nullptr )
    v8 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v7));
  else
    v8 = 0;
  if ( v8 != 0 )
    v9 = 256 / v8;
  else
    v9 = 0;
  v10 = CSheetSequencePanel::SequenceGridRows(this);
  v11 = this->m_pSheet;
  v12 = v9 * v10 + 4;
  if ( v11 != nullptr && (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v11)) != 0 )
  {
    v13 = newWidth;
  }
  else
  {
    v13 = 32;
    v12 = 32;
  }
  vgui::Panel::SetSize(this, wide: v13, tall: v12);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CEE50
// Name: public: virtual void CSheetSequencePanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::OnCursorMoved(CSheetSequencePanel *this, int x, int y)
{
  CSheetExtended *m_pSheet; // ecx
  CSheetExtended *v5; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // edi

  vgui::Menu::OnCursorMoved(this, x, y);
  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr && CSheetExtended::GetSheetSequenceCount(this: m_pSheet) != 0 )
  {
    v5 = this->m_pSheet;
    if ( v5 != nullptr )
      v6 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v5));
    else
      v6 = 0;
    v7 = CSheetSequencePanel::SequenceGridSquareSize(this);
    v8 = (x - 2) / v7;
    v9 = (y - 2) / v7;
    if ( v8 < 0
      || v9 < 0
      || v8 >= v6
      || v9 >= v6
      || (v10 = v6 * v9 + v8) >= CSheetExtended::GetSheetSequenceCount(this: this->m_pSheet) )
    {
      this->m_nHighlightedSequence = -1;
    }
    else
    {
      this->m_nHighlightedSequence = v10;
    }
  }
  else
  {
    this->m_nHighlightedSequence = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CEFA0
// Name: public: virtual void CSheetSequencePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSheetSequencePanel::Paint(CSheetSequencePanel *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  CSheetExtended *m_pSheet; // ecx
  IMaterialSystem *v6; // eax
  int v7; // eax
  int v8; // esi
  IMatSystemSurface *v9; // eax
  ITexture *PowerOfTwoFrameBufferTexture; // eax
  ITexture *v11; // ebx
  int v12; // ebx
  void (__thiscall *v13)(int, IMaterial *); // edx
  double SequenceTimeSpan; // st6
  CSheetExtended *v15; // ecx
  int v16; // eax
  CSheetExtended *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  IMatSystemSurface *v20; // eax
  int v21; // ecx
  float v22; // ebx
  void (__thiscall *DrawOutlinedRect)(vgui::ISurface *, int, int, int, int); // edx
  CSheetSequencePanel_vtbl *v24; // edx
  vgui::ISchemeManager_vtbl *v25; // ebx
  int v26; // eax
  vgui::IScheme *v27; // eax
  vgui::ISurface_vtbl *v28; // ebx
  vgui::IScheme_vtbl *v29; // edx
  int v30; // eax
  int v31; // ebx
  void (__thiscall *DrawSetTextColor)(vgui::ISurface *, Color); // eax
  wchar_t pDest[8]; // [esp+34h] [ebp-64h] BYREF
  _DWORD v34[2]; // [esp+44h] [ebp-54h] BYREF
  Vector v35; // [esp+4Ch] [ebp-4Ch] BYREF
  float v36; // [esp+58h] [ebp-40h]
  IMesh *v37; // [esp+5Ch] [ebp-3Ch]
  float v38; // [esp+60h] [ebp-38h]
  unsigned int v39; // [esp+64h] [ebp-34h]
  int v40; // [esp+68h] [ebp-30h] BYREF
  int v41; // [esp+6Ch] [ebp-2Ch] BYREF
  int SheetSequenceCount; // [esp+70h] [ebp-28h]
  float v43; // [esp+74h] [ebp-24h]
  int v44; // [esp+78h] [ebp-20h]
  float v45; // [esp+7Ch] [ebp-1Ch]
  float v46; // [esp+80h] [ebp-18h]
  bool bOverrideSpriteCard[4]; // [esp+84h] [ebp-14h]
  float v48; // [esp+88h] [ebp-10h]
  int wide; // [esp+8Ch] [ebp-Ch] BYREF
  int tall; // [esp+90h] [ebp-8h] BYREF
  char v51; // [esp+96h] [ebp-2h]
  char v52; // [esp+97h] [ebp-1h]

  vgui::Panel::GetSize(this, &wide, &tall);
  vgui::Panel::GetPos(this, x: &v41, y: &v40);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  *(_DWORD *)bOverrideSpriteCard = -16777216;
  ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -16777216);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 1, a3: 1, a4: wide - 1, a5: tall - 1);
  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr && CSheetExtended::ValidSheetData(this: m_pSheet) )
  {
    v6 = vgui::MaterialSystem();
    v7 = ((int (__thiscall *)(IMaterialSystem *, int, int))v6->GetRenderContext)(a1: v6, a2: a3, a3: a2);
    v8 = v7;
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    v9 = vgui::MatSystemSurface();
    v9->Begin3DPaint(this: v9, a2: 2, a3: 2, a4: wide - 2, a5: tall - 2);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    (*(void (__thiscall **)(int, _DWORD, int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)v8 + 128))(
      a1: v8,
      a2: 0,
      a3: 0x40000000,
      a4: 0,
      a5: 0x40000000,
      a6: COERCE_UNSIGNED_INT64((double)(wide - 2)),
      a7: HIDWORD(COERCE_UNSIGNED_INT64((double)(wide - 2))),
      a8: COERCE_UNSIGNED_INT64((double)(tall - 2)),
      a9: HIDWORD(COERCE_UNSIGNED_INT64((double)(tall - 2))),
      a10: 0,
      a11: -1074790400,
      a12: 0,
      a13: 1072693248);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    if ( this->m_Material.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(this: this->m_Material.m_pMaterial, a2: true) )
    {
      PowerOfTwoFrameBufferTexture = GetPowerOfTwoFrameBufferTexture();
      v11 = PowerOfTwoFrameBufferTexture;
      if ( PowerOfTwoFrameBufferTexture != nullptr
        && !PowerOfTwoFrameBufferTexture->IsError(this: PowerOfTwoFrameBufferTexture) )
      {
        (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v8 + 68))(a1: v8, a2: v11);
        (*(void (__thiscall **)(int, ITexture *, _DWORD))(*(_DWORD *)v8 + 72))(a1: v8, a2: v11, a3: 0);
      }
    }
    this->GetBgColor(this, result: (Color *)v34);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v8 + 296))(
      a1: v8,
      a2: v34[0],
      a3: *(_DWORD *)((char *)v34 + 1),
      a4: *(_DWORD *)((char *)v34 + 2),
      a5: 255);
    v12 = 0;
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v8 + 48))(a1: v8, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 176))(a1: v8, a2: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 216))(a1: v8, a2: 0);
    v13 = *(void (__thiscall **)(int, IMaterial *))(*(_DWORD *)v8 + 36);
    bOverrideSpriteCard[0] = false;
    v52 = 0;
    v51 = 0;
    if ( this->m_bSeparateAlphaColorMaterial )
    {
      if ( this->m_bIsSecondSequenceView )
      {
        v13(a1: v8, a2: CSheetSequencePanel::m_sColorMat.m_pMaterial);
        v52 = 1;
      }
      else
      {
        v13(a1: v8, a2: CSheetSequencePanel::m_sAlphaMat.m_pMaterial);
        v51 = 1;
      }
      bOverrideSpriteCard[0] = true;
    }
    else
    {
      v13(a1: v8, a2: this->m_Material.m_pMaterial);
    }
    v37 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v8 + 228))(a1: v8, a2: 1, a3: 0, a4: 0);
    *(double *)&v35.y = _Plat_FloatTime(
                          a1: 0,
                          a2: 0,
                          a3: *(_DWORD *)pDest,
                          a4: *(_DWORD *)&pDest[2],
                          a5: *(_DWORD *)&pDest[4]);
    SequenceTimeSpan = CSheetExtended::GetSequenceTimeSpan(this: this->m_pSheet, nSequenceIndex: 0);
    *(float *)&v39 = fmod(*(long double *)&v35.y, SequenceTimeSpan);
    v15 = this->m_pSheet;
    if ( v15 != nullptr )
    {
      v38 = fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v15));
      SheetSequenceCount = LOBYTE(v43) | 0x800;
      v44 = (int)v38;
    }
    else
    {
      v44 = 0;
    }
    v16 = CSheetSequencePanel::SequenceGridSquareSize(this);
    v17 = this->m_pSheet;
    v43 = (float)v16;
    v48 = (float)v16 * 0.5;
    v38 = v48 + 2.0;
    SheetSequenceCount = CSheetExtended::GetSheetSequenceCount(this: v17);
    if ( SheetSequenceCount > 0 )
    {
      do
      {
        v18 = (float)(v12 % v44);
        v19 = (float)(v12 / v44);
        v46 = v18;
        v45 = v19;
        if ( v52 != 0 )
        {
          if ( !CSheetExtended::SequenceHasColorData(this: this->m_pSheet, nSequenceIndex: v12) )
            goto LABEL_26;
          v19 = v45;
          v18 = v46;
        }
        if ( v51 == 0 )
          goto LABEL_25;
        if ( CSheetExtended::SequenceHasAlphaData(this: this->m_pSheet, nSequenceIndex: v12) )
        {
          v19 = v45;
          v18 = v46;
LABEL_25:
          v35.x = (float)(v18 * v43) + v38;
          v35.y = (float)tall - (float)((float)(v19 * v43) + v38);
          v35.z = 0.0;
          CSheetExtended::DrawSheet(
            this: this->m_pSheet,
            pMesh: v37,
            vCenter: &v35,
            flRadius: v48,
            nSheetSequence: v12,
            flAge: v39 | 0x443B800000000000LL,
            bLoopSheetPreview: true,
            nSecondarySequence: -1,
            bOverrideSpriteCard: bOverrideSpriteCard[0]);
        }
LABEL_26:
        ++v12;
      }
      while ( v12 < SheetSequenceCount );
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 88))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 80))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 88))(a1: v8);
    v20 = vgui::MatSystemSurface();
    v20->End3DPaint(this: v20);
    v21 = 0;
    *(_DWORD *)bOverrideSpriteCard = 0;
    if ( SheetSequenceCount > 0 )
    {
      while ( 1 )
      {
        v48 = -1.7014118e38;
        v38 = (float)(v21 % v44);
        *(float *)&v39 = (float)(v21 / v44);
        if ( this->m_nHighlightedSequence == v21 )
        {
          v46 = NAN;
          v22 = NAN;
          v48 = NAN;
        }
        else
        {
          v22 = v48;
        }
        ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
          a1: g_pVGuiSurface,
          a2: LODWORD(v22));
        ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
          a1: g_pVGuiSurface,
          a2: LODWORD(v22));
        DrawOutlinedRect = g_pVGuiSurface->DrawOutlinedRect;
        v36 = (float)(*(float *)&v39 * v43) + 2.0;
        v35.z = (float)(v38 * v43) + 2.0;
        DrawOutlinedRect(
          this: g_pVGuiSurface,
          a2: (int)v35.z,
          a3: (int)v36,
          a4: (int)(float)((float)((float)(v38 + 1.0) * v43) + 2.0),
          a5: (int)(float)((float)((float)(*(float *)&v39 + 1.0) * v43) + 2.0));
        V_snwprintf(pDest, maxLen: 8, pFormat: L"%d", *(_DWORD *)bOverrideSpriteCard);
        v24 = this->__vftable;
        v25 = g_pVGuiSchemeManager->__vftable;
        v37 = (IMesh *)g_pVGuiSchemeManager;
        v26 = v24->GetScheme(this);
        v27 = v25->GetIScheme(this: (vgui::ISchemeManager *)v37, a2: v26);
        v28 = g_pVGuiSurface->__vftable;
        v29 = v27->__vftable;
        v37 = (IMesh *)g_pVGuiSurface;
        v30 = v29->GetFont(this: v27, a2: "DefaultVerySmall", a3: false);
        v28->DrawSetTextFont(this: (vgui::ISurface *)v37, a2: v30);
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (int)(float)(v35.z + 2.0), a3: (int)(float)(v36 + 1.0));
        g_pVGuiSurface->DrawUnicodeString(this: g_pVGuiSurface, a2: pDest, a3: FONT_DRAW_DEFAULT);
        v31 = *(_DWORD *)bOverrideSpriteCard;
        if ( v52 != 0
          && !CSheetExtended::SequenceHasColorData(this: this->m_pSheet, nSequenceIndex: *(int *)bOverrideSpriteCard)
          || v51 != 0 && !CSheetExtended::SequenceHasAlphaData(this: this->m_pSheet, nSequenceIndex: v31) )
        {
          DrawSetTextColor = g_pVGuiSurface->DrawSetTextColor;
          v45 = -1.7014636e38;
          ((void (__thiscall *)(vgui::ISurface *, int))DrawSetTextColor)(a1: g_pVGuiSurface, a2: -16776961);
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (int)(float)((float)((float)(v38 + 0.5) * v43) + 2.0),
            a3: (int)(float)((float)((float)((float)(*(float *)&v39 + 0.5) * v43) + 2.0) + 1.0));
          g_pVGuiSurface->DrawUnicodeString(this: g_pVGuiSurface, a2: L"x", a3: FONT_DRAW_DEFAULT);
        }
        *(_DWORD *)bOverrideSpriteCard = v31 + 1;
        if ( v31 + 1 >= SheetSequenceCount )
          break;
        v21 = *(_DWORD *)bOverrideSpriteCard;
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 12))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x105C6A50
// Name: _dynamic_initializer_for__CSheetSequencePanel::m_sColorMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSheetSequencePanel::m_sColorMat__()
{
  CMaterialReference::CMaterialReference(
    this: &CSheetSequencePanel::m_sColorMat,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CSheetSequencePanel::m_sColorMat__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6A70
// Name: _dynamic_initializer_for__CSheetSequencePanel::m_sAlphaMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSheetSequencePanel::m_sAlphaMat__()
{
  CMaterialReference::CMaterialReference(
    this: &CSheetSequencePanel::m_sAlphaMat,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CSheetSequencePanel::m_sAlphaMat__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCB80
// Name: _dynamic_atexit_destructor_for__CSheetSequencePanel::m_sColorMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSheetSequencePanel::m_sColorMat__()
{
  CMaterialReference::~CMaterialReference(this: &CSheetSequencePanel::m_sColorMat);
}

//------------------------------------------------------------------------------
// Address: 0x105CCB90
// Name: _dynamic_atexit_destructor_for__CSheetSequencePanel::m_sAlphaMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSheetSequencePanel::m_sAlphaMat__()
{
  CMaterialReference::~CMaterialReference(this: &CSheetSequencePanel::m_sAlphaMat);
}

//------------------------------------------------------------------------------
// Address: 0x105C6A90
// Name: _dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture__()
{
  CTextureReference::CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCBA0
// Name: _dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004D9270
// Name: public: static char const __near * CSheetSequencePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSheetSequencePanel::GetPanelClassName()
{
  return "CSheetSequencePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004D9280
// Name: GetPowerOfTwoFrameBufferTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetPowerOfTwoFrameBufferTexture()
{
  ITexture *result; // eax
  IMaterialSystem *v1; // eax
  ITexture *v2; // eax

  result = s_pPowerOfTwoFrameBufferTexture_SheetSeq.m_pTexture;
  if ( s_pPowerOfTwoFrameBufferTexture_SheetSeq.m_pTexture == nullptr )
  {
    v1 = vgui::MaterialSystem();
    v2 = v1->FindTexture(this: v1, a2: "_rt_PowerOfTwoFB", a3: "RenderTargets", a4: true, a5: 0);
    CTextureReference::Init(this: &s_pPowerOfTwoFrameBufferTexture_SheetSeq, pTexture: v2);
    return s_pPowerOfTwoFrameBufferTexture_SheetSeq.m_pTexture;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D92C0
// Name: private: static void CSheetSequencePanel::EnsureMaterialsExist(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSheetSequencePanel::EnsureMaterialsExist()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( !CSheetSequencePanel::m_sMaterialsInitialized )
  {
    v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v0 != nullptr )
      v1 = KeyValues::KeyValues(this: v0, setName: "DebugTextureView");
    else
      v1 = nullptr;
    KeyValues::SetString(this: v1, keyName: "$basetexture", value: defaultValue);
    KeyValues::SetInt(this: v1, keyName: "$ShowAlpha", value: 1);
    CMaterialReference::Init(
      this: &CSheetSequencePanel::m_sAlphaMat,
      pMaterialName: "SheetSequenceAlphaMaterial",
      pVMTKeyValues: v1);
    CSheetSequencePanel::m_sAlphaMat.m_pMaterial->Refresh(this: CSheetSequencePanel::m_sAlphaMat.m_pMaterial);
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "DebugTextureView");
    else
      v3 = nullptr;
    KeyValues::SetString(this: v3, keyName: "$basetexture", value: defaultValue);
    KeyValues::SetInt(this: v3, keyName: "$ShowAlpha", value: 0);
    CMaterialReference::Init(
      this: &CSheetSequencePanel::m_sColorMat,
      pMaterialName: "SheetSequenceColorMaterial",
      pVMTKeyValues: v3);
    CSheetSequencePanel::m_sColorMat.m_pMaterial->Refresh(this: CSheetSequencePanel::m_sColorMat.m_pMaterial);
    CSheetSequencePanel::m_sMaterialsInitialized = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D93A0
// Name: private: void CSheetSequencePanel::PrepareMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::PrepareMaterials(CSheetSequencePanel *this)
{
  bool IsMaterialSeparateAlphaColorMaterial; // al
  IMaterial *m_pMaterial; // ecx
  int v4; // eax
  int (__thiscall ***v5)(_DWORD); // esi
  int v6; // eax
  ITexture *v7; // esi
  IMaterialVar *v8; // eax
  IMaterialVar *v9; // eax
  bool bFound; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_Material.m_pMaterial != nullptr )
  {
    IsMaterialSeparateAlphaColorMaterial = CSheetExtended::IsMaterialSeparateAlphaColorMaterial(pMat: this->m_Material.m_pMaterial);
    m_pMaterial = this->m_Material.m_pMaterial;
    this->m_bSeparateAlphaColorMaterial = IsMaterialSeparateAlphaColorMaterial;
    bFound = false;
    v4 = (int)m_pMaterial->FindVar(this: m_pMaterial, a2: "$basetexture", a3: &bFound, a4: true);
    v5 = (int (__thiscall ***)(_DWORD))v4;
    if ( v4 != 0 && bFound && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 72))(a1: v4) != 0 )
    {
      v6 = (**v5)(a1: v5);
      v7 = (ITexture *)v6;
      if ( v6 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 60))(a1: v6) == 0 )
      {
        v8 = CSheetSequencePanel::m_sAlphaMat.m_pMaterial->FindVar(
               this: CSheetSequencePanel::m_sAlphaMat.m_pMaterial,
               a2: "$basetexture",
               a3: &bFound,
               a4: 1);
        if ( bFound && v8 != nullptr )
        {
          v8->SetTextureValue(this: v8, a2: v7);
          v9 = CSheetSequencePanel::m_sColorMat.m_pMaterial->FindVar(
                 this: CSheetSequencePanel::m_sColorMat.m_pMaterial,
                 a2: "$basetexture",
                 a3: &bFound,
                 a4: 1);
          if ( bFound && v9 != nullptr )
            v9->SetTextureValue(this: v9, a2: v7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D9480
// Name: public: void CSheetSequencePanel::SetSecondSequenceView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::SetSecondSequenceView(CSheetSequencePanel *this, bool bIsSecondSequenceView)
{
  this->m_bIsSecondSequenceView = bIsSecondSequenceView;
}

//------------------------------------------------------------------------------
// Address: 0x004D9490
// Name: public: void CSheetSequencePanel::SetFromMaterialName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::SetFromMaterialName(CSheetSequencePanel *this, const char *pMaterialName)
{
  CSheetExtended *m_pSheet; // edi
  CSheetExtended *v4; // eax
  CSheetExtended *v5; // eax

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
  {
    CSheetExtended::~CSheetExtended(this: this->m_pSheet);
    free(pMem: m_pSheet);
  }
  CMaterialReference::Init(
    this: &this->m_Material,
    pMaterialName,
    pTextureGroupName: "editor material",
    bComplain: true);
  v4 = (CSheetExtended *)MemAlloc_Alloc(nSize: 8u);
  if ( v4 != nullptr )
    v5 = CSheetExtended::CSheetExtended(this: v4, pMaterial: this->m_Material.m_pMaterial);
  else
    v5 = nullptr;
  this->m_pSheet = v5;
  CSheetSequencePanel::PrepareMaterials(this);
  this->PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D9510
// Name: public: void CSheetSequencePanel::SetFromMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::SetFromMaterial(CSheetSequencePanel *this, IMaterial *sourceMaterial)
{
  CSheetExtended *m_pSheet; // edi
  CSheetExtended *v4; // eax
  CSheetExtended *v5; // eax

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
  {
    CSheetExtended::~CSheetExtended(this: this->m_pSheet);
    free(pMem: m_pSheet);
  }
  CMaterialReference::Init(this: &this->m_Material, pMaterial: sourceMaterial);
  v4 = (CSheetExtended *)MemAlloc_Alloc(nSize: 8u);
  if ( v4 != nullptr )
    v5 = CSheetExtended::CSheetExtended(this: v4, pMaterial: this->m_Material.m_pMaterial);
  else
    v5 = nullptr;
  this->m_pSheet = v5;
  CSheetSequencePanel::PrepareMaterials(this);
  this->PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D9580
// Name: public: virtual void CSheetSequencePanel::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::OnCursorExited(CSheetSequencePanel *this)
{
  this->m_nHighlightedSequence = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D9590
// Name: private: int CSheetSequencePanel::SequenceGridSquareSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetSequencePanel::SequenceGridSquareSize(CSheetSequencePanel *this)
{
  CSheetExtended *m_pSheet; // ecx
  int v2; // ecx

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
    v2 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: m_pSheet));
  else
    v2 = 0;
  if ( v2 != 0 )
    return 256 / v2;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D9600
// Name: private: int CSheetSequencePanel::SequenceGridRows(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetSequencePanel::SequenceGridRows(CSheetSequencePanel *this)
{
  CSheetExtended *m_pSheet; // ecx
  int SheetSequenceCount; // eax
  CSheetExtended *v5; // ecx
  int v6; // edi
  int v7; // ecx

  m_pSheet = this->m_pSheet;
  if ( m_pSheet == nullptr )
    return 0;
  SheetSequenceCount = CSheetExtended::GetSheetSequenceCount(this: m_pSheet);
  v5 = this->m_pSheet;
  v6 = SheetSequenceCount;
  if ( v5 != nullptr )
    v7 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v5));
  else
    v7 = 0;
  if ( v6 != 0 )
    return (v7 + v6 - 1) / v7;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D9690
// Name: public: virtual void CSheetSequencePanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::OnMouseReleased(CSheetSequencePanel *this, ButtonCode_t mouseCode)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi

  if ( this->m_nHighlightedSequence != -1 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "SheetSequenceSelected");
    else
      v4 = nullptr;
    KeyValues::SetPtr(this: v4, keyName: "panel", value: this);
    KeyValues::SetInt(this: v4, keyName: "nSequenceNumber", value: this->m_nHighlightedSequence);
    KeyValues::SetInt(this: v4, keyName: "bIsSecondSequence", value: this->m_bIsSecondSequenceView);
    this->PostActionSignal(this, a2: v4);
  }
  this->SetVisible(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004D9720
// Name: public: CSheetSequencePanel::CSheetSequencePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSheetSequencePanel *__thiscall CSheetSequencePanel::CSheetSequencePanel(
        CSheetSequencePanel *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Menu::Menu(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CSheetSequencePanel_vtbl *)&CSheetSequencePanel::`vftable';
  if ( `CSheetSequencePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSheetSequencePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSheetSequencePanel");
    v4->pfnClassName = CSheetSequencePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Menu");
  }
  if ( `CSheetSequencePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSheetSequencePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSheetSequencePanel");
    v5->pfnClassName = CSheetSequencePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Menu");
  }
  if ( `CSheetSequencePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSheetSequencePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSheetSequencePanel");
    v6->pfnClassName = CSheetSequencePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Menu");
  }
  this->m_pSheet = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_nHighlightedSequence = -1;
  *(_WORD *)&this->m_bSeparateAlphaColorMaterial = 0;
  CSheetSequencePanel::EnsureMaterialsExist();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D9810
// Name: public: virtual struct vgui::PanelMessageMap __near * CSheetSequencePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSheetSequencePanel::GetMessageMap(CSheetSequencePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSheetSequencePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSheetSequencePanel::GetMessageMap'::`2'::s_pMap;
  `CSheetSequencePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSheetSequencePanel");
  `CSheetSequencePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D9840
// Name: public: virtual struct PanelAnimationMap __near * CSheetSequencePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSheetSequencePanel::GetAnimMap(CSheetSequencePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSheetSequencePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004D9850
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSheetSequencePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSheetSequencePanel::GetKBMap(CSheetSequencePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSheetSequencePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSheetSequencePanel::GetKBMap'::`2'::s_pMap;
  `CSheetSequencePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSheetSequencePanel");
  `CSheetSequencePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D9880
// Name: public: virtual void CSheetSequencePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::PerformLayout(CSheetSequencePanel *this)
{
  CSheetExtended *m_pSheet; // ecx
  int v3; // esi
  CSheetExtended *v4; // ecx
  int v5; // ecx
  int v6; // eax
  CSheetExtended *v7; // ecx
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  CSheetExtended *v11; // ecx
  int v12; // esi
  int v13; // eax
  int newWidth; // [esp+18h] [ebp-Ch]

  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr )
    v3 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: m_pSheet));
  else
    v3 = 0;
  v4 = this->m_pSheet;
  if ( v4 != nullptr )
    v5 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v4));
  else
    v5 = 0;
  if ( v5 != 0 )
    v6 = 256 / v5;
  else
    v6 = 0;
  v7 = this->m_pSheet;
  newWidth = v3 * v6 + 4;
  if ( v7 != nullptr )
    v8 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v7));
  else
    v8 = 0;
  if ( v8 != 0 )
    v9 = 256 / v8;
  else
    v9 = 0;
  v10 = CSheetSequencePanel::SequenceGridRows(this);
  v11 = this->m_pSheet;
  v12 = v9 * v10 + 4;
  if ( v11 != nullptr && (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v11)) != 0 )
  {
    v13 = newWidth;
  }
  else
  {
    v13 = 32;
    v12 = 32;
  }
  vgui::Panel::SetSize(this, wide: v13, tall: v12);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D9A10
// Name: public: virtual void CSheetSequencePanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetSequencePanel::OnCursorMoved(CSheetSequencePanel *this, int x, int y)
{
  CSheetExtended *m_pSheet; // ecx
  CSheetExtended *v5; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // edi

  vgui::Menu::OnCursorMoved(this, x, y);
  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr && CSheetExtended::GetSheetSequenceCount(this: m_pSheet) != 0 )
  {
    v5 = this->m_pSheet;
    if ( v5 != nullptr )
      v6 = (int)fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v5));
    else
      v6 = 0;
    v7 = CSheetSequencePanel::SequenceGridSquareSize(this);
    v8 = (x - 2) / v7;
    v9 = (y - 2) / v7;
    if ( v8 < 0
      || v9 < 0
      || v8 >= v6
      || v9 >= v6
      || (v10 = v6 * v9 + v8) >= CSheetExtended::GetSheetSequenceCount(this: this->m_pSheet) )
    {
      this->m_nHighlightedSequence = -1;
    }
    else
    {
      this->m_nHighlightedSequence = v10;
    }
  }
  else
  {
    this->m_nHighlightedSequence = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D9B60
// Name: public: virtual void CSheetSequencePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CSheetSequencePanel::Paint(CSheetSequencePanel *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  CSheetExtended *m_pSheet; // ecx
  IMaterialSystem *v6; // eax
  int v7; // eax
  int v8; // esi
  IMatSystemSurface *v9; // eax
  ITexture *PowerOfTwoFrameBufferTexture; // eax
  ITexture *v11; // ebx
  int v12; // ebx
  void (__thiscall *v13)(int, IMaterial *); // edx
  long double SequenceTimeSpan; // st6
  CSheetExtended *v15; // ecx
  int v16; // eax
  CSheetExtended *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  IMatSystemSurface *v20; // eax
  int v21; // ecx
  Color v22; // ebx
  void (__thiscall *DrawOutlinedRect)(vgui::ISurface *, int, int, int, int); // edx
  CSheetSequencePanel_vtbl *v24; // edx
  vgui::ISchemeManager_vtbl *v25; // ebx
  int v26; // eax
  vgui::IScheme *v27; // eax
  vgui::ISurface_vtbl *v28; // ebx
  vgui::IScheme_vtbl *v29; // edx
  int v30; // eax
  int v31; // ebx
  void (__thiscall *DrawSetTextColor)(vgui::ISurface *, Color); // eax
  wchar_t strBuffer[8]; // [esp+D4h] [ebp-64h] BYREF
  _BYTE bgColor[6]; // [esp+E4h] [ebp-54h] OVERLAPPED BYREF
  Vector vCenter; // [esp+ECh] [ebp-4Ch] BYREF
  float v36; // [esp+F8h] [ebp-40h]
  IMesh *pMesh; // [esp+FCh] [ebp-3Ch]
  float flOffset; // [esp+100h] [ebp-38h]
  float flAge; // [esp+104h] [ebp-34h]
  int y; // [esp+108h] [ebp-30h] BYREF
  int x; // [esp+10Ch] [ebp-2Ch] BYREF
  int nSequences; // [esp+110h] [ebp-28h]
  float flGridSquareSize; // [esp+114h] [ebp-24h]
  int v44; // [esp+118h] [ebp-20h]
  float v45; // [esp+11Ch] [ebp-1Ch]
  float v46; // [esp+120h] [ebp-18h]
  int i; // [esp+124h] [ebp-14h]
  Color drawColor; // [esp+128h] [ebp-10h]
  int w; // [esp+12Ch] [ebp-Ch] BYREF
  int h; // [esp+130h] [ebp-8h] BYREF
  bool bOnlyAlpha; // [esp+136h] [ebp-2h]
  bool bOnlyColor; // [esp+137h] [ebp-1h]

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::GetPos(this, &x, &y);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  i = -16777216;
  ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -16777216);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 1, a3: 1, a4: w - 1, a5: h - 1);
  m_pSheet = this->m_pSheet;
  if ( m_pSheet != nullptr && CSheetExtended::ValidSheetData(this: m_pSheet) )
  {
    v6 = vgui::MaterialSystem();
    v7 = ((int (__thiscall *)(IMaterialSystem *, int, int))v6->GetRenderContext)(a1: v6, a2: a3, a3: a2);
    v8 = v7;
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    v9 = vgui::MatSystemSurface();
    v9->Begin3DPaint(this: v9, a2: 2, a3: 2, a4: w - 2, a5: h - 2);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    (*(void (__thiscall **)(int, _DWORD, int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)v8 + 128))(
      a1: v8,
      a2: 0,
      a3: 0x40000000,
      a4: 0,
      a5: 0x40000000,
      a6: COERCE_UNSIGNED_INT64((double)(w - 2)),
      a7: HIDWORD(COERCE_UNSIGNED_INT64((double)(w - 2))),
      a8: COERCE_UNSIGNED_INT64((double)(h - 2)),
      a9: HIDWORD(COERCE_UNSIGNED_INT64((double)(h - 2))),
      a10: 0,
      a11: -1074790400,
      a12: 0,
      a13: 1072693248);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    if ( this->m_Material.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(this: this->m_Material.m_pMaterial, a2: true) )
    {
      PowerOfTwoFrameBufferTexture = GetPowerOfTwoFrameBufferTexture();
      v11 = PowerOfTwoFrameBufferTexture;
      if ( PowerOfTwoFrameBufferTexture != nullptr
        && !PowerOfTwoFrameBufferTexture->IsError(this: PowerOfTwoFrameBufferTexture) )
      {
        (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v8 + 68))(a1: v8, a2: v11);
        (*(void (__thiscall **)(int, ITexture *, _DWORD))(*(_DWORD *)v8 + 72))(a1: v8, a2: v11, a3: 0);
      }
    }
    this->GetBgColor(this, result: (Color *)bgColor);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v8 + 296))(
      a1: v8,
      a2: *(_DWORD *)bgColor,
      a3: *(_DWORD *)&bgColor[1],
      a4: *(_DWORD *)&bgColor[2],
      a5: 255);
    v12 = 0;
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v8 + 48))(a1: v8, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 176))(a1: v8, a2: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 216))(a1: v8, a2: 0);
    v13 = *(void (__thiscall **)(int, IMaterial *))(*(_DWORD *)v8 + 36);
    LOBYTE(i) = 0;
    bOnlyColor = false;
    bOnlyAlpha = false;
    if ( this->m_bSeparateAlphaColorMaterial )
    {
      if ( this->m_bIsSecondSequenceView )
      {
        v13(a1: v8, a2: CSheetSequencePanel::m_sColorMat.m_pMaterial);
        bOnlyColor = true;
      }
      else
      {
        v13(a1: v8, a2: CSheetSequencePanel::m_sAlphaMat.m_pMaterial);
        bOnlyAlpha = true;
      }
      LOBYTE(i) = 1;
    }
    else
    {
      v13(a1: v8, a2: this->m_Material.m_pMaterial);
    }
    pMesh = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v8 + 228))(
                       a1: v8,
                       a2: 1,
                       a3: 0,
                       a4: 0);
    *(double *)&vCenter.y = _Plat_FloatTime();
    SequenceTimeSpan = CSheetExtended::GetSequenceTimeSpan(this: this->m_pSheet, nSequenceIndex: 0);
    flAge = fmod(*(long double *)&vCenter.y, SequenceTimeSpan);
    v15 = this->m_pSheet;
    if ( v15 != nullptr )
    {
      flOffset = fsqrt((float)CSheetExtended::GetSheetSequenceCount(this: v15));
      nSequences = LOBYTE(flGridSquareSize) | 0x800;
      v44 = (int)flOffset;
    }
    else
    {
      v44 = 0;
    }
    v16 = CSheetSequencePanel::SequenceGridSquareSize(this);
    v17 = this->m_pSheet;
    flGridSquareSize = (float)v16;
    *(float *)&drawColor = (float)v16 * 0.5;
    flOffset = *(float *)&drawColor + 2.0;
    nSequences = CSheetExtended::GetSheetSequenceCount(this: v17);
    if ( nSequences > 0 )
    {
      do
      {
        v18 = (float)(v12 % v44);
        v19 = (float)(v12 / v44);
        v46 = v18;
        v45 = v19;
        if ( bOnlyColor )
        {
          if ( !CSheetExtended::SequenceHasColorData(this: this->m_pSheet, nSequenceIndex: v12) )
            goto LABEL_26;
          v19 = v45;
          v18 = v46;
        }
        if ( !bOnlyAlpha )
          goto LABEL_25;
        if ( CSheetExtended::SequenceHasAlphaData(this: this->m_pSheet, nSequenceIndex: v12) )
        {
          v19 = v45;
          v18 = v46;
LABEL_25:
          vCenter.x = (float)(v18 * flGridSquareSize) + flOffset;
          vCenter.y = (float)h - (float)((float)(v19 * flGridSquareSize) + flOffset);
          vCenter.z = 0.0;
          CSheetExtended::DrawSheet(
            this: this->m_pSheet,
            pMesh,
            &vCenter,
            flRadius: *(float *)&drawColor,
            nSheetSequence: v12,
            flAge,
            flSheetPreviewSpeed: 750.0,
            bLoopSheetPreview: true,
            nSecondarySequence: -1,
            bOverrideSpriteCard: i);
        }
LABEL_26:
        ++v12;
      }
      while ( v12 < nSequences );
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 88))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 80))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 88))(a1: v8);
    v20 = vgui::MatSystemSurface();
    v20->End3DPaint(this: v20);
    v21 = 0;
    i = 0;
    if ( nSequences > 0 )
    {
      while ( 1 )
      {
        *(float *)&drawColor = -1.7014118e38;
        flOffset = (float)(v21 % v44);
        flAge = (float)(v21 / v44);
        if ( this->m_nHighlightedSequence == v21 )
        {
          v46 = NAN;
          v22 = (Color)-1;
          *(float *)&drawColor = NAN;
        }
        else
        {
          v22 = drawColor;
        }
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v22);
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetTextColor)(a1: g_pVGuiSurface, a2: v22);
        DrawOutlinedRect = g_pVGuiSurface->DrawOutlinedRect;
        v36 = (float)(flAge * flGridSquareSize) + 2.0;
        vCenter.z = (float)(flOffset * flGridSquareSize) + 2.0;
        DrawOutlinedRect(
          this: g_pVGuiSurface,
          a2: (int)vCenter.z,
          a3: (int)v36,
          a4: (int)(float)((float)((float)(flOffset + 1.0) * flGridSquareSize) + 2.0),
          a5: (int)(float)((float)((float)(flAge + 1.0) * flGridSquareSize) + 2.0));
        V_snwprintf(pDest: strBuffer, maxLen: 8, pFormat: L"%d", i);
        v24 = this->__vftable;
        v25 = g_pVGuiSchemeManager->__vftable;
        pMesh = (IMesh *)g_pVGuiSchemeManager;
        v26 = v24->GetScheme(this);
        v27 = v25->GetIScheme(this: (vgui::ISchemeManager *)pMesh, a2: v26);
        v28 = g_pVGuiSurface->__vftable;
        v29 = v27->__vftable;
        pMesh = (IMesh *)g_pVGuiSurface;
        v30 = v29->GetFont(this: v27, a2: "DefaultVerySmall", a3: false);
        v28->DrawSetTextFont(this: (vgui::ISurface *)pMesh, a2: v30);
        g_pVGuiSurface->DrawSetTextPos(
          this: g_pVGuiSurface,
          a2: (int)(float)(vCenter.z + 2.0),
          a3: (int)(float)(v36 + 1.0));
        g_pVGuiSurface->DrawUnicodeString(this: g_pVGuiSurface, a2: strBuffer, a3: FONT_DRAW_DEFAULT);
        v31 = i;
        if ( bOnlyColor && !CSheetExtended::SequenceHasColorData(this: this->m_pSheet, nSequenceIndex: i)
          || bOnlyAlpha && !CSheetExtended::SequenceHasAlphaData(this: this->m_pSheet, nSequenceIndex: v31) )
        {
          DrawSetTextColor = g_pVGuiSurface->DrawSetTextColor;
          v45 = -1.7014636e38;
          ((void (__thiscall *)(vgui::ISurface *, int))DrawSetTextColor)(a1: g_pVGuiSurface, a2: -16776961);
          g_pVGuiSurface->DrawSetTextPos(
            this: g_pVGuiSurface,
            a2: (int)(float)((float)((float)(flOffset + 0.5) * flGridSquareSize) + 2.0),
            a3: (int)(float)((float)((float)((float)(flAge + 0.5) * flGridSquareSize) + 2.0) + 1.0));
          g_pVGuiSurface->DrawUnicodeString(this: g_pVGuiSurface, a2: L"x", a3: FONT_DRAW_DEFAULT);
        }
        i = v31 + 1;
        if ( v31 + 1 >= nSequences )
          break;
        v21 = i;
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 12))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006AC960
// Name: _dynamic_initializer_for__CSheetSequencePanel::m_sColorMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSheetSequencePanel::m_sColorMat__()
{
  CMaterialReference::CMaterialReference(
    this: &CSheetSequencePanel::m_sColorMat,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CSheetSequencePanel::m_sColorMat__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC980
// Name: _dynamic_initializer_for__CSheetSequencePanel::m_sAlphaMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSheetSequencePanel::m_sAlphaMat__()
{
  CMaterialReference::CMaterialReference(
    this: &CSheetSequencePanel::m_sAlphaMat,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CSheetSequencePanel::m_sAlphaMat__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3CA0
// Name: _dynamic_atexit_destructor_for__CSheetSequencePanel::m_sColorMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSheetSequencePanel::m_sColorMat__()
{
  CMaterialReference::~CMaterialReference(this: &CSheetSequencePanel::m_sColorMat);
}

//------------------------------------------------------------------------------
// Address: 0x006B3CB0
// Name: _dynamic_atexit_destructor_for__CSheetSequencePanel::m_sAlphaMat__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSheetSequencePanel::m_sAlphaMat__()
{
  CMaterialReference::~CMaterialReference(this: &CSheetSequencePanel::m_sAlphaMat);
}

//------------------------------------------------------------------------------
// Address: 0x006AC9A0
// Name: _dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture__()
{
  CTextureReference::CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture);
  return atexit(func: dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC9C0
// Name: sub_6AC9C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_6AC9C0()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_7BDD3C = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x006B3CC0
// Name: _dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture__()
{
  CTextureReference::~CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture);
}

} // namespace sceneviewer
