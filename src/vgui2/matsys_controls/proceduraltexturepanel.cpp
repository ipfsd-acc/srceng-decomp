// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/proceduraltexturepanel.cpp
// Functions: 15
// ============================================================

#include "vgui2\matsys_controls\proceduraltexturepanel.h"

//------------------------------------------------------------------------------
// Address: 0x102641C0
// Name: public: static char const __near * CProceduralTexturePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CProceduralTexturePanel::GetPanelClassName()
{
  return "CProceduralTexturePanel";
}

//------------------------------------------------------------------------------
// Address: 0x102641D0
// Name: public: virtual bool CProceduralTexturePanel::Init(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CProceduralTexturePanel::Init(
        CProceduralTexturePanel *this,
        int nWidth,
        int nHeight,
        bool bAllocateImageBuffer)
{
  const char *(__thiscall *GetName)(vgui::IClientPanel *); // edx
  const char *v6; // eax
  IMaterialSystem *v7; // eax
  ITexture *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  IMaterialSystem *v11; // eax
  IMaterial *v12; // ebx
  IMaterialVar *v13; // eax
  IMatSystemSurface *v14; // eax
  IMatSystemSurface *v15; // eax
  char pTemp[512]; // [esp+Ch] [ebp-200h] BYREF

  this->m_nWidth = nWidth;
  this->m_nHeight = nHeight;
  if ( bAllocateImageBuffer )
    this->m_pImageBuffer = (BGRA8888_t *)MemAlloc_Alloc(
                                           nSize: (unsigned __int64)(unsigned int)(nHeight * nWidth) >> 30 != 0
                                         ? -1
                                         : 4 * nHeight * nWidth);
  this->m_TextureSubRect.y = 0;
  this->m_TextureSubRect.x = 0;
  GetName = this->GetName;
  this->m_TextureSubRect.width = nWidth;
  this->m_TextureSubRect.height = nHeight;
  v6 = GetName(this);
  V_snprintf(pDest: pTemp, maxLen: 512, pFormat: "__%s", v6);
  v7 = vgui::MaterialSystem();
  v8 = v7->CreateProceduralTexture(
         this: v7,
         a2: pTemp,
         a3: "VGUI textures",
         a4: this->m_nWidth,
         a5: this->m_nHeight,
         a6: IMAGE_FORMAT_BGRX8888,
         a7: 264972);
  v8->SetTextureRegenerator(this: v8, a2: &this->ITextureRegenerator, a3: true);
  CTextureReference::Init(this: &this->m_ProceduralTexture, pTexture: v8);
  v8->DecrementReferenceCount(this: v8);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "UnlitGeneric");
  else
    v10 = nullptr;
  KeyValues::SetString(this: v10, keyName: "$basetexture", value: pTemp);
  KeyValues::SetInt(this: v10, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v10, keyName: "$nodebug", value: 1);
  v11 = vgui::MaterialSystem();
  v12 = v11->CreateMaterial(this: v11, a2: pTemp, a3: v10);
  CMaterialReference::Init(this: &this->m_ProceduralMaterial, pMaterial: v12);
  v12->DecrementReferenceCount(this: v12);
  v13 = this->m_ProceduralMaterial.m_pMaterial->FindVarFast(
          this: this->m_ProceduralMaterial.m_pMaterial,
          a2: "$basetexture",
          a3: &textureVarCache_4);
  v13->SetTextureValue(this: v13, a2: v8);
  v14 = vgui::MatSystemSurface();
  this->m_nTextureID = v14->CreateNewTextureID(this: v14, a2: false);
  v15 = vgui::MatSystemSurface();
  v15->DrawSetTextureMaterial(this: v15, a2: this->m_nTextureID, a3: this->m_ProceduralMaterial.m_pMaterial);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102643A0
// Name: public: void CProceduralTexturePanel::MaintainProportions(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::MaintainProportions(CProceduralTexturePanel *this, bool bEnable)
{
  this->m_bMaintainProportions = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x102643B0
// Name: private: void CProceduralTexturePanel::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::CleanUp(CProceduralTexturePanel *this)
{
  IMatSystemSurface *v2; // eax
  ITexture *m_pTexture; // ecx

  if ( this->m_nTextureID != -1 )
  {
    v2 = vgui::MatSystemSurface();
    v2->DestroyTextureID(this: v2, a2: this->m_nTextureID);
    this->m_nTextureID = -1;
  }
  if ( this->m_ProceduralMaterial.m_pMaterial != nullptr )
    CMaterialReference::Shutdown(this: &this->m_ProceduralMaterial, bDeleteIfUnreferenced: true);
  m_pTexture = this->m_ProceduralTexture.m_pTexture;
  if ( m_pTexture != nullptr )
  {
    m_pTexture->SetTextureRegenerator(this: m_pTexture, a2: nullptr, a3: true);
    CTextureReference::Shutdown(this: &this->m_ProceduralTexture, bDeleteIfUnReferenced: true);
  }
  if ( this->m_pImageBuffer != nullptr )
  {
    free(pMem: this->m_pImageBuffer);
    this->m_pImageBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264440
// Name: public: struct BGRA8888_t __near * CProceduralTexturePanel::GetImageBuffer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProceduralTexturePanel::GetImageBuffer(vgui::TreeView *this)
{
  return this->m_nRowHeight;
}

//------------------------------------------------------------------------------
// Address: 0x10264450
// Name: public: void CProceduralTexturePanel::SetTextureSubRect(struct Rect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::SetTextureSubRect(CProceduralTexturePanel *this, const Rect_t *subRect)
{
  this->m_TextureSubRect = *subRect;
}

//------------------------------------------------------------------------------
// Address: 0x10264480
// Name: public: void CProceduralTexturePanel::DownloadTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::DownloadTexture(CProceduralTexturePanel *this)
{
  this->m_ProceduralTexture.m_pTexture->Download(this: this->m_ProceduralTexture.m_pTexture, a2: nullptr, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102644A0
// Name: public: virtual void CProceduralTexturePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProceduralTexturePanel::Paint(CProceduralTexturePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int m_nTextureID; // eax
  int height; // ecx
  int v6; // ecx
  int width; // eax
  int h; // [esp+44h] [ebp-8h] BYREF
  int w; // [esp+48h] [ebp-4h] BYREF

  m_nTextureID = this->m_nTextureID;
  if ( m_nTextureID != -1 )
  {
    ((void (__thiscall *)(vgui::ISurface *, int, int, int))g_pVGuiSurface->DrawSetTexture)(
      a1: g_pVGuiSurface,
      a2: m_nTextureID,
      a3,
      a4: a2);
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    if ( this->m_bUsePaintRect )
    {
      height = this->m_PaintRect.height;
      w = this->m_PaintRect.width;
      h = height;
    }
    if ( this->m_bMaintainProportions )
    {
      v6 = this->m_TextureSubRect.height;
      width = this->m_TextureSubRect.width;
      if ( width <= v6 )
        w = h * width / v6;
      else
        h = w * v6 / this->m_TextureSubRect.width;
    }
    ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawTexturedPolygon)(a1: g_pVGuiSurface, a2: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264650
// Name: public: CProceduralTexturePanel::CProceduralTexturePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CProceduralTexturePanel *__thiscall CProceduralTexturePanel::CProceduralTexturePanel(
        CProceduralTexturePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&ITextureRegenerator::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  if ( `CProceduralTexturePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
    v4->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
    v5->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
    v6->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CTextureReference::CTextureReference(this: &this->m_ProceduralTexture);
  CMaterialReference::CMaterialReference(
    this: &this->m_ProceduralMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_pImageBuffer = nullptr;
  *(_WORD *)&this->m_bMaintainProportions = 0;
  this->m_PaintRect.y = 0;
  this->m_PaintRect.x = 0;
  this->m_PaintRect.height = 0;
  this->m_PaintRect.width = 0;
  this->m_nTextureID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10264770
// Name: public: virtual struct vgui::PanelMessageMap __near * CProceduralTexturePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CProceduralTexturePanel::GetMessageMap(CProceduralTexturePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102647A0
// Name: public: virtual struct PanelAnimationMap __near * CProceduralTexturePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CProceduralTexturePanel::GetAnimMap(CProceduralTexturePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
}

//------------------------------------------------------------------------------
// Address: 0x102647B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CProceduralTexturePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CProceduralTexturePanel::GetKBMap(CProceduralTexturePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102647E0
// Name: public: virtual CProceduralTexturePanel::~CProceduralTexturePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::~CProceduralTexturePanel(CProceduralTexturePanel *this)
{
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  CProceduralTexturePanel::CleanUp(this);
  CMaterialReference::~CMaterialReference(this: &this->m_ProceduralMaterial);
  CTextureReference::~CTextureReference(this: &this->m_ProceduralTexture);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10264820
// Name: public: virtual void CProceduralTexturePanel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CProceduralTexturePanel::Shutdown(CProceduralTexturePanel *this)
{
  CProceduralTexturePanel::CleanUp(this);
}

//------------------------------------------------------------------------------
// Address: 0x10264830
// Name: public: virtual void CProceduralTexturePanel::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::RegenerateTextureBits(
        CProceduralTexturePanel *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture_vtbl *v5; // eax
  __int16 v6; // bx
  int v7; // ecx
  unsigned __int8 *v8; // eax
  BGRA8888_t *v9; // eax
  unsigned __int8 v10; // dl
  int b; // edi
  int r; // esi
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // edx
  int v17; // eax
  unsigned __int64 v18; // rdi
  __int64 v19; // rax
  unsigned __int64 v20; // rdi
  unsigned __int8 *pixelWriter; // [esp+Ch] [ebp-50h]
  unsigned __int8 *pixelWriter_4; // [esp+10h] [ebp-4Ch]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-46h]
  int pixelWriter_12; // [esp+18h] [ebp-44h]
  int pixelWriter_16; // [esp+1Ch] [ebp-40h]
  int pixelWriter_20; // [esp+20h] [ebp-3Ch]
  char pixelWriter_24; // [esp+24h] [ebp-38h]
  int pixelWriter_28; // [esp+28h] [ebp-34h]
  char pixelWriter_32; // [esp+2Ch] [ebp-30h]
  int nDepth; // [esp+38h] [ebp-24h] BYREF
  int v31; // [esp+3Ch] [ebp-20h]
  CProceduralTexturePanel *v32; // [esp+40h] [ebp-1Ch]
  int nHeight; // [esp+44h] [ebp-18h] BYREF
  unsigned __int8 *v34; // [esp+48h] [ebp-14h]
  int y; // [esp+4Ch] [ebp-10h]
  int nWidth; // [esp+50h] [ebp-Ch] BYREF
  int x; // [esp+54h] [ebp-8h]
  int v38; // [esp+58h] [ebp-4h]
  unsigned __int16 pTexel; // [esp+68h] [ebp+Ch]
  BGRA8888_t *pTexela; // [esp+68h] [ebp+Ch]

  v5 = pVTFTexture->__vftable;
  v32 = this;
  v5->ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  pTexel = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
  pixelWriter = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
  switch ( pVTFTexture->Format(this: pVTFTexture) )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      pixelWriter_12 = 0x80000;
      v6 = 16;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case IMAGE_FORMAT_BGR888:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_19;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_17;
    case IMAGE_FORMAT_A8:
      v6 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA8888:
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRX8888:
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case IMAGE_FORMAT_BGR565:
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      v6 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = -4;
      pixelWriter_28 = 248;
      goto LABEL_20;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      v6 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_24 = -8;
      pixelWriter_28 = 248;
      pixelWriter_32 = 0x80;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v6 = -4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = -16;
      pixelWriter_28 = 240;
      pixelWriter_32 = -16;
      goto LABEL_21;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      v6 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      pixelWriter_24 = -1;
      pixelWriter_28 = 0xFFFF;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      v6 = 64;
      pixelWriter_16 = 6291520;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA1010102:
      pixelWriter_10 = 4;
      pixelWriter_12 = 655380;
      v6 = 0;
      pixelWriter_16 = 1966080;
      pixelWriter_20 = 1023;
      pixelWriter_24 = -1;
      pixelWriter_28 = 1023;
      pixelWriter_32 = 3;
      goto LABEL_21;
    default:
      pixelWriter_10 = 0;
LABEL_17:
      pixelWriter_20 = 255;
LABEL_18:
      pixelWriter_12 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_19:
      v6 = 0;
      pixelWriter_16 = 0;
LABEL_20:
      pixelWriter_32 = 0;
LABEL_21:
      v7 = 0;
      y = 0;
      if ( nHeight > 0 )
      {
        v8 = pixelWriter;
        v31 = pTexel;
        v34 = pixelWriter;
        do
        {
          pixelWriter_4 = v8;
          v9 = (BGRA8888_t *)(*(_DWORD *)&v32->m_OnCommand_register + 4 * v7 * *(_DWORD *)&v32->m_OnDelete_register);
          pTexela = v9;
          x = 0;
          if ( nWidth > 0 )
          {
            v10 = pixelWriter_10;
            v38 = pixelWriter_10;
            while ( 1 )
            {
              b = v9->b;
              r = v9->r;
              if ( v10 != 0 )
              {
                v13 = (unsigned __int8)(v9->g & pixelWriter_24);
                if ( v10 >= 5u )
                {
                  v18 = ((unsigned __int64)(unsigned __int8)(pTexela->r & pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)v13 << SBYTE2(pixelWriter_12));
                  if ( v6 <= 0 )
                    v19 = (__int64)(unsigned __int8)(pTexela->b & pixelWriter_28) >> -(char)v6;
                  else
                    v19 = (unsigned __int64)(unsigned __int8)(pTexela->b & pixelWriter_28) << v6;
                  v20 = v19
                      | ((unsigned __int64)(unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16))
                      | v18;
                  if ( v38 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v20;
                    *((_WORD *)pixelWriter_4 + 2) = WORD2(v20);
                  }
                  else if ( v38 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v20;
                  }
                }
                else
                {
                  v14 = ((r & pixelWriter_20) << pixelWriter_12) | (v13 << SBYTE2(pixelWriter_12));
                  v15 = b & pixelWriter_28;
                  if ( v6 <= 0 )
                    v16 = v15 >> -(char)pixelWriter_16;
                  else
                    v16 = v15 << pixelWriter_16;
                  v17 = v16 | ((unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16)) | v14;
                  switch ( v38 )
                  {
                    case 1:
                      *pixelWriter_4 = v17;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v17;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v17;
                      pixelWriter_4[2] = BYTE2(v17);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v17;
                      break;
                    default:
                      break;
                  }
                }
              }
              pixelWriter_4 += v38;
              v9 = pTexela + 1;
              ++x;
              ++pTexela;
              if ( x >= nWidth )
                break;
              v10 = pixelWriter_10;
            }
            v7 = y;
          }
          v8 = &v34[v31];
          y = ++v7;
          v34 += v31;
        }
        while ( v7 < nHeight );
      }
      return;
  }
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004CEC70
// Name: public: static char const __near * CProceduralTexturePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CProceduralTexturePanel::GetPanelClassName()
{
  return "CProceduralTexturePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004CEC80
// Name: public: virtual bool CProceduralTexturePanel::Init(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CProceduralTexturePanel::Init(
        CProceduralTexturePanel *this,
        int nWidth,
        int nHeight,
        bool bAllocateImageBuffer)
{
  const char *(__thiscall *GetName)(vgui::IClientPanel *); // edx
  const char *v6; // eax
  IMaterialSystem *v7; // eax
  ITexture *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  IMaterialSystem *v11; // eax
  IMaterial *v12; // ebx
  IMaterialVar *v13; // eax
  IMatSystemSurface *v14; // eax
  IMatSystemSurface *v15; // eax
  char pTemp[512]; // [esp+Ch] [ebp-200h] BYREF

  this->m_nWidth = nWidth;
  this->m_nHeight = nHeight;
  if ( bAllocateImageBuffer )
    this->m_pImageBuffer = (BGRA8888_t *)MemAlloc_Alloc(
                                           nSize: (unsigned __int64)(unsigned int)(nHeight * nWidth) >> 30 != 0
                                         ? -1
                                         : 4 * nHeight * nWidth);
  this->m_TextureSubRect.y = 0;
  this->m_TextureSubRect.x = 0;
  GetName = this->GetName;
  this->m_TextureSubRect.width = nWidth;
  this->m_TextureSubRect.height = nHeight;
  v6 = GetName(this);
  V_snprintf(pDest: pTemp, maxLen: 512, pFormat: "__%s", v6);
  v7 = vgui::MaterialSystem();
  v8 = v7->CreateProceduralTexture(
         this: v7,
         a2: pTemp,
         a3: "VGUI textures",
         a4: this->m_nWidth,
         a5: this->m_nHeight,
         a6: IMAGE_FORMAT_BGRX8888,
         a7: 264972);
  v8->SetTextureRegenerator(this: v8, a2: &this->ITextureRegenerator, a3: true);
  CTextureReference::Init(this: &this->m_ProceduralTexture, pTexture: v8);
  v8->DecrementReferenceCount(this: v8);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "UnlitGeneric");
  else
    v10 = nullptr;
  KeyValues::SetString(this: v10, keyName: "$basetexture", value: pTemp);
  KeyValues::SetInt(this: v10, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v10, keyName: "$nodebug", value: 1);
  v11 = vgui::MaterialSystem();
  v12 = v11->CreateMaterial(this: v11, a2: pTemp, a3: v10);
  CMaterialReference::Init(this: &this->m_ProceduralMaterial, pMaterial: v12);
  v12->DecrementReferenceCount(this: v12);
  v13 = this->m_ProceduralMaterial.m_pMaterial->FindVarFast(
          this: this->m_ProceduralMaterial.m_pMaterial,
          a2: "$basetexture",
          a3: &textureVarCache);
  v13->SetTextureValue(this: v13, a2: v8);
  v14 = vgui::MatSystemSurface();
  this->m_nTextureID = v14->CreateNewTextureID(this: v14, a2: false);
  v15 = vgui::MatSystemSurface();
  v15->DrawSetTextureMaterial(this: v15, a2: this->m_nTextureID, a3: this->m_ProceduralMaterial.m_pMaterial);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CEE50
// Name: public: void CProceduralTexturePanel::MaintainProportions(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::MaintainProportions(CProceduralTexturePanel *this, bool bEnable)
{
  this->m_bMaintainProportions = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x004CEE60
// Name: private: void CProceduralTexturePanel::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::CleanUp(CProceduralTexturePanel *this)
{
  IMatSystemSurface *v2; // eax
  ITexture *m_pTexture; // ecx

  if ( this->m_nTextureID != -1 )
  {
    v2 = vgui::MatSystemSurface();
    v2->DestroyTextureID(this: v2, a2: this->m_nTextureID);
    this->m_nTextureID = -1;
  }
  if ( this->m_ProceduralMaterial.m_pMaterial != nullptr )
    CMaterialReference::Shutdown(this: &this->m_ProceduralMaterial, bDeleteIfUnreferenced: true);
  m_pTexture = this->m_ProceduralTexture.m_pTexture;
  if ( m_pTexture != nullptr )
  {
    m_pTexture->SetTextureRegenerator(this: m_pTexture, a2: nullptr, a3: true);
    CTextureReference::Shutdown(this: &this->m_ProceduralTexture, bDeleteIfUnReferenced: true);
  }
  if ( this->m_pImageBuffer != nullptr )
  {
    free(pMem: this->m_pImageBuffer);
    this->m_pImageBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CEEF0
// Name: public: struct BGRA8888_t __near * CProceduralTexturePanel::GetImageBuffer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProceduralTexturePanel::GetImageBuffer(vgui::TreeView *this)
{
  return this->m_nRowHeight;
}

//------------------------------------------------------------------------------
// Address: 0x004CEF00
// Name: public: int CProceduralTexturePanel::GetImageWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProceduralTexturePanel::GetImageWidth(CProceduralTexturePanel *this)
{
  return this->m_nWidth;
}

//------------------------------------------------------------------------------
// Address: 0x004CEF20
// Name: public: void CProceduralTexturePanel::SetPaintRect(struct Rect_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::SetPaintRect(CProceduralTexturePanel *this, const Rect_t *pPaintRect)
{
  this->m_bUsePaintRect = pPaintRect != nullptr;
  if ( pPaintRect != nullptr )
    this->m_PaintRect = *pPaintRect;
}

//------------------------------------------------------------------------------
// Address: 0x004CEF60
// Name: public: void CProceduralTexturePanel::DownloadTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::DownloadTexture(CProceduralTexturePanel *this)
{
  this->m_ProceduralTexture.m_pTexture->Download(this: this->m_ProceduralTexture.m_pTexture, a2: nullptr, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004CEF80
// Name: public: virtual void CProceduralTexturePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProceduralTexturePanel::Paint(CProceduralTexturePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int m_nTextureID; // eax
  int height; // ecx
  int v6; // ecx
  int width; // eax
  int h; // [esp+44h] [ebp-8h] BYREF
  int w; // [esp+48h] [ebp-4h] BYREF

  m_nTextureID = this->m_nTextureID;
  if ( m_nTextureID != -1 )
  {
    ((void (__thiscall *)(vgui::ISurface *, int, int, int))g_pVGuiSurface->DrawSetTexture)(
      a1: g_pVGuiSurface,
      a2: m_nTextureID,
      a3,
      a4: a2);
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    if ( this->m_bUsePaintRect )
    {
      height = this->m_PaintRect.height;
      w = this->m_PaintRect.width;
      h = height;
    }
    if ( this->m_bMaintainProportions )
    {
      v6 = this->m_TextureSubRect.height;
      width = this->m_TextureSubRect.width;
      if ( width <= v6 )
        w = h * width / v6;
      else
        h = w * v6 / this->m_TextureSubRect.width;
    }
    ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawTexturedPolygon)(a1: g_pVGuiSurface, a2: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF130
// Name: public: CProceduralTexturePanel::CProceduralTexturePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CProceduralTexturePanel *__thiscall CProceduralTexturePanel::CProceduralTexturePanel(
        CProceduralTexturePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&ITextureRegenerator::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  if ( `CProceduralTexturePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
    v4->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
    v5->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
    v6->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CTextureReference::CTextureReference(this: &this->m_ProceduralTexture);
  CMaterialReference::CMaterialReference(
    this: &this->m_ProceduralMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_pImageBuffer = nullptr;
  *(_WORD *)&this->m_bMaintainProportions = 0;
  this->m_PaintRect.y = 0;
  this->m_PaintRect.x = 0;
  this->m_PaintRect.height = 0;
  this->m_PaintRect.width = 0;
  this->m_nTextureID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CF250
// Name: public: virtual struct vgui::PanelMessageMap __near * CProceduralTexturePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CProceduralTexturePanel::GetMessageMap(CProceduralTexturePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CF280
// Name: public: virtual struct PanelAnimationMap __near * CProceduralTexturePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CProceduralTexturePanel::GetAnimMap(CProceduralTexturePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004CF290
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CProceduralTexturePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CProceduralTexturePanel::GetKBMap(CProceduralTexturePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CF2C0
// Name: public: virtual CProceduralTexturePanel::~CProceduralTexturePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::~CProceduralTexturePanel(CProceduralTexturePanel *this)
{
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  CProceduralTexturePanel::CleanUp(this);
  CMaterialReference::~CMaterialReference(this: &this->m_ProceduralMaterial);
  CTextureReference::~CTextureReference(this: &this->m_ProceduralTexture);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004CF300
// Name: public: virtual void CProceduralTexturePanel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CProceduralTexturePanel::Shutdown(CProceduralTexturePanel *this)
{
  CProceduralTexturePanel::CleanUp(this);
}

//------------------------------------------------------------------------------
// Address: 0x004CF310
// Name: public: virtual void CProceduralTexturePanel::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::RegenerateTextureBits(
        CProceduralTexturePanel *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture_vtbl *v5; // eax
  ImageFormat v6; // eax
  ImageFormat v7; // esi
  __int16 v8; // bx
  int v9; // ecx
  unsigned __int8 *v10; // eax
  BGRA8888_t *v11; // eax
  unsigned __int8 v12; // dl
  int b; // edi
  int r; // esi
  unsigned int v15; // eax
  int v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // edx
  int v19; // eax
  unsigned __int64 v20; // rdi
  __int64 v21; // rax
  unsigned __int64 v22; // rdi
  unsigned __int8 *pixelWriter_4; // [esp+10h] [ebp-4Ch]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-46h]
  int pixelWriter_12; // [esp+18h] [ebp-44h]
  int pixelWriter_16; // [esp+1Ch] [ebp-40h]
  int pixelWriter_20; // [esp+20h] [ebp-3Ch]
  char pixelWriter_24; // [esp+24h] [ebp-38h]
  int pixelWriter_28; // [esp+28h] [ebp-34h]
  char pixelWriter_32; // [esp+2Ch] [ebp-30h]
  int nDepth; // [esp+38h] [ebp-24h] BYREF
  int v32; // [esp+3Ch] [ebp-20h]
  CProceduralTexturePanel *v33; // [esp+40h] [ebp-1Ch]
  int nHeight; // [esp+44h] [ebp-18h] BYREF
  unsigned __int8 *v35; // [esp+48h] [ebp-14h]
  int y; // [esp+4Ch] [ebp-10h]
  int nWidth; // [esp+50h] [ebp-Ch] BYREF
  int x; // [esp+54h] [ebp-8h]
  int v39; // [esp+58h] [ebp-4h]
  unsigned __int16 pTexel; // [esp+68h] [ebp+Ch]
  BGRA8888_t *pTexela; // [esp+68h] [ebp+Ch]

  v5 = pVTFTexture->__vftable;
  v33 = this;
  v5->ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  pTexel = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
  v35 = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
  v6 = pVTFTexture->Format(this: pVTFTexture);
  v7 = v6;
  switch ( v6 )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      pixelWriter_12 = 0x80000;
      v8 = 16;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case IMAGE_FORMAT_BGR888:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_18;
    case IMAGE_FORMAT_A8:
      v8 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA8888:
      pixelWriter_12 = 524304;
      v8 = 0;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      pixelWriter_32 = -1;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRX8888:
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      v8 = 0;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_21;
    case IMAGE_FORMAT_BGR565:
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      v8 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = -4;
      pixelWriter_28 = 248;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      v8 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_24 = -8;
      pixelWriter_28 = 248;
      pixelWriter_32 = 0x80;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v8 = -4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = -16;
      pixelWriter_28 = 240;
      pixelWriter_32 = -16;
      goto LABEL_22;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      v8 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      pixelWriter_24 = -1;
      pixelWriter_28 = 0xFFFF;
      pixelWriter_32 = -1;
      goto LABEL_22;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      v8 = 64;
      pixelWriter_16 = (int)&loc_60003E + 2;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_22;
    default:
      if ( `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v6] == 0 )
      {
        _Msg(a1: "CPixelWriter::SetPixelMemory:  Unsupported image format %i\n", v6);
        `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v7] = 1;
      }
      pixelWriter_10 = 0;
LABEL_18:
      pixelWriter_20 = 255;
LABEL_19:
      pixelWriter_12 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_20:
      v8 = 0;
      pixelWriter_16 = 0;
LABEL_21:
      pixelWriter_32 = 0;
LABEL_22:
      v9 = 0;
      y = 0;
      if ( nHeight > 0 )
      {
        v10 = v35;
        v32 = pTexel;
        do
        {
          pixelWriter_4 = v10;
          v11 = (BGRA8888_t *)(*(_DWORD *)&v33->m_OnCommand_register + 4 * v9 * *(_DWORD *)&v33->m_OnDelete_register);
          pTexela = v11;
          x = 0;
          if ( nWidth > 0 )
          {
            v12 = pixelWriter_10;
            v39 = pixelWriter_10;
            while ( 1 )
            {
              b = v11->b;
              r = v11->r;
              if ( v12 != 0 )
              {
                v15 = (unsigned __int8)(v11->g & pixelWriter_24);
                if ( v12 >= 5u )
                {
                  v20 = ((unsigned __int64)(unsigned __int8)(pTexela->r & pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)v15 << SBYTE2(pixelWriter_12));
                  if ( v8 <= 0 )
                    v21 = (__int64)(unsigned __int8)(pTexela->b & pixelWriter_28) >> -(char)v8;
                  else
                    v21 = (unsigned __int64)(unsigned __int8)(pTexela->b & pixelWriter_28) << v8;
                  v22 = v21
                      | ((unsigned __int64)(unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16))
                      | v20;
                  if ( v39 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v22;
                    *((_WORD *)pixelWriter_4 + 2) = WORD2(v22);
                  }
                  else if ( v39 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v22;
                  }
                }
                else
                {
                  v16 = ((r & pixelWriter_20) << pixelWriter_12) | (v15 << SBYTE2(pixelWriter_12));
                  v17 = b & pixelWriter_28;
                  if ( v8 <= 0 )
                    v18 = v17 >> -(char)pixelWriter_16;
                  else
                    v18 = v17 << pixelWriter_16;
                  v19 = v18 | ((unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16)) | v16;
                  switch ( v39 )
                  {
                    case 1:
                      *pixelWriter_4 = v19;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v19;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v19;
                      pixelWriter_4[2] = BYTE2(v19);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v19;
                      break;
                    default:
                      break;
                  }
                }
              }
              pixelWriter_4 += v39;
              v11 = pTexela + 1;
              ++x;
              ++pTexela;
              if ( x >= nWidth )
                break;
              v12 = pixelWriter_10;
            }
            v9 = y;
          }
          v10 = &v35[v32];
          y = ++v9;
          v35 += v32;
        }
        while ( v9 < nHeight );
      }
      return;
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102641F0
// Name: public: static char const __near * CProceduralTexturePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CProceduralTexturePanel::GetPanelClassName()
{
  return "CProceduralTexturePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10264200
// Name: public: virtual bool CProceduralTexturePanel::Init(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CProceduralTexturePanel::Init(
        CProceduralTexturePanel *this,
        int nWidth,
        int nHeight,
        bool bAllocateImageBuffer)
{
  const char *(__thiscall *GetName)(vgui::IClientPanel *); // edx
  const char *v6; // eax
  IMaterialSystem *v7; // eax
  ITexture *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  IMaterialSystem *v11; // eax
  IMaterial *v12; // ebx
  IMaterialVar *v13; // eax
  IMatSystemSurface *v14; // eax
  IMatSystemSurface *v15; // eax
  char pTemp[512]; // [esp+Ch] [ebp-200h] BYREF

  this->m_nWidth = nWidth;
  this->m_nHeight = nHeight;
  if ( bAllocateImageBuffer )
    this->m_pImageBuffer = (BGRA8888_t *)MemAlloc_Alloc(
                                           nSize: (unsigned __int64)(unsigned int)(nHeight * nWidth) >> 30 != 0
                                         ? -1
                                         : 4 * nHeight * nWidth);
  this->m_TextureSubRect.y = 0;
  this->m_TextureSubRect.x = 0;
  GetName = this->GetName;
  this->m_TextureSubRect.width = nWidth;
  this->m_TextureSubRect.height = nHeight;
  v6 = GetName(this);
  V_snprintf(pDest: pTemp, maxLen: 512, pFormat: "__%s", v6);
  v7 = vgui::MaterialSystem();
  v8 = v7->CreateProceduralTexture(
         this: v7,
         a2: pTemp,
         a3: "VGUI textures",
         a4: this->m_nWidth,
         a5: this->m_nHeight,
         a6: IMAGE_FORMAT_BGRX8888,
         a7: 264972);
  v8->SetTextureRegenerator(this: v8, a2: &this->ITextureRegenerator, a3: true);
  CTextureReference::Init(this: &this->m_ProceduralTexture, pTexture: v8);
  v8->DecrementReferenceCount(this: v8);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "UnlitGeneric");
  else
    v10 = nullptr;
  KeyValues::SetString(this: v10, keyName: "$basetexture", value: pTemp);
  KeyValues::SetInt(this: v10, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v10, keyName: "$nodebug", value: 1);
  v11 = vgui::MaterialSystem();
  v12 = v11->CreateMaterial(this: v11, a2: pTemp, a3: v10);
  CMaterialReference::Init(this: &this->m_ProceduralMaterial, pMaterial: v12);
  v12->DecrementReferenceCount(this: v12);
  v13 = this->m_ProceduralMaterial.m_pMaterial->FindVarFast(
          this: this->m_ProceduralMaterial.m_pMaterial,
          a2: "$basetexture",
          a3: &textureVarCache_4);
  v13->SetTextureValue(this: v13, a2: v8);
  v14 = vgui::MatSystemSurface();
  this->m_nTextureID = v14->CreateNewTextureID(this: v14, a2: false);
  v15 = vgui::MatSystemSurface();
  v15->DrawSetTextureMaterial(this: v15, a2: this->m_nTextureID, a3: this->m_ProceduralMaterial.m_pMaterial);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102643D0
// Name: public: void CProceduralTexturePanel::MaintainProportions(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::MaintainProportions(CProceduralTexturePanel *this, bool bEnable)
{
  this->m_bMaintainProportions = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x102643E0
// Name: private: void CProceduralTexturePanel::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::CleanUp(CProceduralTexturePanel *this)
{
  IMatSystemSurface *v2; // eax
  ITexture *m_pTexture; // ecx

  if ( this->m_nTextureID != -1 )
  {
    v2 = vgui::MatSystemSurface();
    v2->DestroyTextureID(this: v2, a2: this->m_nTextureID);
    this->m_nTextureID = -1;
  }
  if ( this->m_ProceduralMaterial.m_pMaterial != nullptr )
    CMaterialReference::Shutdown(this: &this->m_ProceduralMaterial, bDeleteIfUnreferenced: true);
  m_pTexture = this->m_ProceduralTexture.m_pTexture;
  if ( m_pTexture != nullptr )
  {
    m_pTexture->SetTextureRegenerator(this: m_pTexture, a2: nullptr, a3: true);
    CTextureReference::Shutdown(this: &this->m_ProceduralTexture, bDeleteIfUnReferenced: true);
  }
  if ( this->m_pImageBuffer != nullptr )
  {
    free(pMem: this->m_pImageBuffer);
    this->m_pImageBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264470
// Name: public: void CProceduralTexturePanel::SetTextureSubRect(struct Rect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::SetTextureSubRect(CProceduralTexturePanel *this, const Rect_t *subRect)
{
  this->m_TextureSubRect = *subRect;
}

//------------------------------------------------------------------------------
// Address: 0x102644C0
// Name: public: virtual void CProceduralTexturePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProceduralTexturePanel::Paint(CProceduralTexturePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int m_nTextureID; // eax
  int height; // ecx
  int v6; // ecx
  int width; // eax
  int h; // [esp+44h] [ebp-8h] BYREF
  int w; // [esp+48h] [ebp-4h] BYREF

  m_nTextureID = this->m_nTextureID;
  if ( m_nTextureID != -1 )
  {
    ((void (__thiscall *)(vgui::ISurface *, int, int, int))g_pVGuiSurface->DrawSetTexture)(
      a1: g_pVGuiSurface,
      a2: m_nTextureID,
      a3,
      a4: a2);
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    if ( this->m_bUsePaintRect )
    {
      height = this->m_PaintRect.height;
      w = this->m_PaintRect.width;
      h = height;
    }
    if ( this->m_bMaintainProportions )
    {
      v6 = this->m_TextureSubRect.height;
      width = this->m_TextureSubRect.width;
      if ( width <= v6 )
        w = h * width / v6;
      else
        h = w * v6 / this->m_TextureSubRect.width;
    }
    ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawTexturedPolygon)(a1: g_pVGuiSurface, a2: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264670
// Name: public: CProceduralTexturePanel::CProceduralTexturePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CProceduralTexturePanel *__thiscall CProceduralTexturePanel::CProceduralTexturePanel(
        CProceduralTexturePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&ITextureRegenerator::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  if ( `CProceduralTexturePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
    v4->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
    v5->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
    v6->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CTextureReference::CTextureReference(this: &this->m_ProceduralTexture);
  CMaterialReference::CMaterialReference(
    this: &this->m_ProceduralMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_pImageBuffer = nullptr;
  *(_WORD *)&this->m_bMaintainProportions = 0;
  this->m_PaintRect.y = 0;
  this->m_PaintRect.x = 0;
  this->m_PaintRect.height = 0;
  this->m_PaintRect.width = 0;
  this->m_nTextureID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10264790
// Name: public: virtual struct vgui::PanelMessageMap __near * CProceduralTexturePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CProceduralTexturePanel::GetMessageMap(CProceduralTexturePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102647C0
// Name: public: virtual struct PanelAnimationMap __near * CProceduralTexturePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CProceduralTexturePanel::GetAnimMap(CProceduralTexturePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
}

//------------------------------------------------------------------------------
// Address: 0x102647D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CProceduralTexturePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CProceduralTexturePanel::GetKBMap(CProceduralTexturePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10264800
// Name: public: virtual CProceduralTexturePanel::~CProceduralTexturePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::~CProceduralTexturePanel(CProceduralTexturePanel *this)
{
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  CProceduralTexturePanel::CleanUp(this);
  CMaterialReference::~CMaterialReference(this: &this->m_ProceduralMaterial);
  CTextureReference::~CTextureReference(this: &this->m_ProceduralTexture);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10264840
// Name: public: virtual void CProceduralTexturePanel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CProceduralTexturePanel::Shutdown(CProceduralTexturePanel *this)
{
  CProceduralTexturePanel::CleanUp(this);
}

//------------------------------------------------------------------------------
// Address: 0x10264850
// Name: public: virtual void CProceduralTexturePanel::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::RegenerateTextureBits(
        CProceduralTexturePanel *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture_vtbl *v5; // eax
  __int16 v6; // bx
  int v7; // ecx
  unsigned __int8 *v8; // eax
  BGRA8888_t *v9; // eax
  unsigned __int8 v10; // dl
  int b; // edi
  int r; // esi
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // edx
  int v17; // eax
  unsigned __int64 v18; // rdi
  __int64 v19; // rax
  unsigned __int64 v20; // rdi
  unsigned __int8 *pixelWriter; // [esp+Ch] [ebp-50h]
  unsigned __int8 *pixelWriter_4; // [esp+10h] [ebp-4Ch]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-46h]
  int pixelWriter_12; // [esp+18h] [ebp-44h]
  int pixelWriter_16; // [esp+1Ch] [ebp-40h]
  int pixelWriter_20; // [esp+20h] [ebp-3Ch]
  char pixelWriter_24; // [esp+24h] [ebp-38h]
  int pixelWriter_28; // [esp+28h] [ebp-34h]
  char pixelWriter_32; // [esp+2Ch] [ebp-30h]
  int nDepth; // [esp+38h] [ebp-24h] BYREF
  int v31; // [esp+3Ch] [ebp-20h]
  CProceduralTexturePanel *v32; // [esp+40h] [ebp-1Ch]
  int nHeight; // [esp+44h] [ebp-18h] BYREF
  unsigned __int8 *v34; // [esp+48h] [ebp-14h]
  int y; // [esp+4Ch] [ebp-10h]
  int nWidth; // [esp+50h] [ebp-Ch] BYREF
  int x; // [esp+54h] [ebp-8h]
  int v38; // [esp+58h] [ebp-4h]
  unsigned __int16 pTexel; // [esp+68h] [ebp+Ch]
  BGRA8888_t *pTexela; // [esp+68h] [ebp+Ch]

  v5 = pVTFTexture->__vftable;
  v32 = this;
  v5->ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  pTexel = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
  pixelWriter = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
  switch ( pVTFTexture->Format(this: pVTFTexture) )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      pixelWriter_12 = 0x80000;
      v6 = 16;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case IMAGE_FORMAT_BGR888:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_19;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_17;
    case IMAGE_FORMAT_A8:
      v6 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA8888:
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRX8888:
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case IMAGE_FORMAT_BGR565:
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      v6 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = -4;
      pixelWriter_28 = 248;
      goto LABEL_20;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      v6 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_24 = -8;
      pixelWriter_28 = 248;
      pixelWriter_32 = 0x80;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v6 = -4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = -16;
      pixelWriter_28 = 240;
      pixelWriter_32 = -16;
      goto LABEL_21;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      v6 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      pixelWriter_24 = -1;
      pixelWriter_28 = 0xFFFF;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      v6 = 64;
      pixelWriter_16 = 6291520;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA1010102:
      pixelWriter_10 = 4;
      pixelWriter_12 = 655380;
      v6 = 0;
      pixelWriter_16 = 1966080;
      pixelWriter_20 = 1023;
      pixelWriter_24 = -1;
      pixelWriter_28 = 1023;
      pixelWriter_32 = 3;
      goto LABEL_21;
    default:
      pixelWriter_10 = 0;
LABEL_17:
      pixelWriter_20 = 255;
LABEL_18:
      pixelWriter_12 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_19:
      v6 = 0;
      pixelWriter_16 = 0;
LABEL_20:
      pixelWriter_32 = 0;
LABEL_21:
      v7 = 0;
      y = 0;
      if ( nHeight > 0 )
      {
        v8 = pixelWriter;
        v31 = pTexel;
        v34 = pixelWriter;
        do
        {
          pixelWriter_4 = v8;
          v9 = (BGRA8888_t *)(*(_DWORD *)&v32->m_OnCommand_register + 4 * v7 * *(_DWORD *)&v32->m_OnDelete_register);
          pTexela = v9;
          x = 0;
          if ( nWidth > 0 )
          {
            v10 = pixelWriter_10;
            v38 = pixelWriter_10;
            while ( 1 )
            {
              b = v9->b;
              r = v9->r;
              if ( v10 != 0 )
              {
                v13 = (unsigned __int8)(v9->g & pixelWriter_24);
                if ( v10 >= 5u )
                {
                  v18 = ((unsigned __int64)(unsigned __int8)(pTexela->r & pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)v13 << SBYTE2(pixelWriter_12));
                  if ( v6 <= 0 )
                    v19 = (__int64)(unsigned __int8)(pTexela->b & pixelWriter_28) >> -(char)v6;
                  else
                    v19 = (unsigned __int64)(unsigned __int8)(pTexela->b & pixelWriter_28) << v6;
                  v20 = v19
                      | ((unsigned __int64)(unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16))
                      | v18;
                  if ( v38 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v20;
                    *((_WORD *)pixelWriter_4 + 2) = WORD2(v20);
                  }
                  else if ( v38 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v20;
                  }
                }
                else
                {
                  v14 = ((r & pixelWriter_20) << pixelWriter_12) | (v13 << SBYTE2(pixelWriter_12));
                  v15 = b & pixelWriter_28;
                  if ( v6 <= 0 )
                    v16 = v15 >> -(char)pixelWriter_16;
                  else
                    v16 = v15 << pixelWriter_16;
                  v17 = v16 | ((unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16)) | v14;
                  switch ( v38 )
                  {
                    case 1:
                      *pixelWriter_4 = v17;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v17;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v17;
                      pixelWriter_4[2] = BYTE2(v17);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v17;
                      break;
                    default:
                      break;
                  }
                }
              }
              pixelWriter_4 += v38;
              v9 = pTexela + 1;
              ++x;
              ++pTexela;
              if ( x >= nWidth )
                break;
              v10 = pixelWriter_10;
            }
            v7 = y;
          }
          v8 = &v34[v31];
          y = ++v7;
          v34 += v31;
        }
        while ( v7 < nHeight );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CC4D0
// Name: public: struct BGRA8888_t __near * CProceduralTexturePanel::GetImageBuffer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProceduralTexturePanel::GetImageBuffer(vgui::TreeView *this)
{
  return this->m_nRowHeight;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10306D40
// Name: public: struct BGRA8888_t __near * CProceduralTexturePanel::GetImageBuffer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProceduralTexturePanel::GetImageBuffer(vgui::TreeView *this)
{
  return this->m_nRowHeight;
}

//------------------------------------------------------------------------------
// Address: 0x103663D8
// Name: public: void AFX_GLOBAL_DATA::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AFX_GLOBAL_DATA::CleanUp(AFX_GLOBAL_DATA *this)
{
  CBrush *p_brLight; // ecx
  void (*m_pfBufferedPaintUnInit)(void); // eax

  p_brLight = &this->brLight;
  if ( p_brLight != nullptr && p_brLight->m_hObject != nullptr )
    CGdiObject::DeleteObject(this: p_brLight);
  CGdiObject::DeleteObject(this: &this->fontRegular);
  CGdiObject::DeleteObject(this: &this->fontBold);
  CGdiObject::DeleteObject(this: &this->fontUnderline);
  CGdiObject::DeleteObject(this: &this->fontVert);
  CGdiObject::DeleteObject(this: &this->fontVertCaption);
  CGdiObject::DeleteObject(this: &this->fontTooltip);
  AFX_GLOBAL_DATA::ReleaseTaskBarRefs(this);
  if ( this->m_bBufferedPaintInited != 0 )
  {
    m_pfBufferedPaintUnInit = (void (*)(void))this->m_pfBufferedPaintUnInit;
    if ( m_pfBufferedPaintUnInit != nullptr )
    {
      m_pfBufferedPaintUnInit();
      this->m_bBufferedPaintInited = 0;
    }
  }
  if ( this->m_hinstUXThemeDLL != nullptr )
  {
    FreeLibrary(hLibModule: this->m_hinstUXThemeDLL);
    this->m_hinstUXThemeDLL = nullptr;
  }
  if ( this->m_hinstDwmapiDLL != nullptr )
  {
    FreeLibrary(hLibModule: this->m_hinstDwmapiDLL);
    this->m_hinstDwmapiDLL = nullptr;
  }
  this->m_bEnableAccessibility = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A3296
// Name: protected: void CMFCFontComboBox::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCFontComboBox::CleanUp(CMFCFontComboBox *this)
{
  LRESULT v2; // eax
  signed int i; // [esp+4h] [ebp-4h]

  if ( !IsWindow(hWnd: this->m_hWnd) )
    AfxThrowInvalidArgException();
  if ( this->m_bToolBarMode == 0 )
  {
    for ( i = 0; i < SendMessageA(hWnd: this->m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0); ++i )
    {
      v2 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x150u, wParam: i, lParam: 0);
      if ( v2 != 0 )
        (*(void (__thiscall **)(LRESULT, int))(*(_DWORD *)v2 + 4))(a1: v2, a2: 1);
    }
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A5449
// Name: public: virtual void CMFCButton::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCButton::CleanUp(CMFCButton *this)
{
  this->m_nStdImageId = -1;
  this->m_nStdImageDisabledId = -1;
  this->m_sizeImage.cy = 0;
  this->m_sizeImage.cx = 0;
  CMFCToolBarImages::Clear(this: &this->m_Image);
  CMFCToolBarImages::Clear(this: &this->m_ImageHot);
  CMFCToolBarImages::Clear(this: &this->m_ImageDisabled);
  CMFCToolBarImages::Clear(this: &this->m_ImageChecked);
  CMFCToolBarImages::Clear(this: &this->m_ImageCheckedHot);
  CMFCToolBarImages::Clear(this: &this->m_ImageCheckedDisabled);
}

//------------------------------------------------------------------------------
// Address: 0x103B4488
// Name: public: static void CMenuImages::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
static void __stdcall CMenuImages::CleanUp()
{
  if ( CMenuImages::m_bInitializing == 0 && CMenuImages::m_ImagesBlack.m_iCount > 0 )
  {
    CMFCToolBarImages::Clear(this: &CMenuImages::m_ImagesBlack);
    CMFCToolBarImages::Clear(this: &CMenuImages::m_ImagesGray);
    CMFCToolBarImages::Clear(this: &CMenuImages::m_ImagesDkGray);
    CMFCToolBarImages::Clear(this: &CMenuImages::m_ImagesLtGray);
    CMFCToolBarImages::Clear(this: &CMenuImages::m_ImagesWhite);
    CMFCToolBarImages::Clear(this: &CMenuImages::m_ImagesBlack2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B91D9
// Name: public: static void CPngImage::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
static void __stdcall CPngImage::CleanUp()
{
  if ( CPngImage::m_pImage != nullptr )
  {
    ((void (__thiscall *)(ATL::CImage *, int))CPngImage::m_pImage->dtr_CImage)(a1: CPngImage::m_pImage, a2: 1);
    CPngImage::m_pImage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B95A1
// Name: public: static void CMFCToolBarImages::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
static void __stdcall CMFCToolBarImages::CleanUp()
{
  if ( hDCMono != nullptr )
  {
    DeleteDC(hdc: hDCMono);
    hDCMono = nullptr;
  }
  if ( hDCGlyphs != nullptr )
  {
    DeleteDC(hdc: hDCGlyphs);
    hDCGlyphs = nullptr;
  }
  CPngImage::CleanUp();
}

//------------------------------------------------------------------------------
// Address: 0x103DA518
// Name: public: virtual void CMFCBaseTabCtrl::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::CleanUp(CMFCBaseTabCtrl *this)
{
  int v1; // eax
  CObject **v3; // ebx
  BOOL v4; // edi
  int i; // [esp+4h] [ebp-4h]

  v1 = 0;
  for ( i = 0; v1 < this->m_iTabsNum; i = v1 )
  {
    if ( v1 < 0 || v1 >= this->m_arTabs.m_nSize )
      AfxThrowInvalidArgException();
    v3 = (CObject **)this->m_arTabs.m_pData[v1];
    if ( v3[8][8].__vftable == nullptr || IsWindow(hWnd: (HWND)v3[8][8].__vftable) )
    {
      v4 = CObject::IsKindOf(this: v3[8], pClass: &CPane::classCPane) == 0;
      if ( this->m_bAutoDestroyWindow != 0 )
        v3[8]->__vftable[8].GetRuntimeClass(this: v3[8]);
      if ( v4 || this->m_bAutoDestroyWindow == 0 )
        ((void (__thiscall *)(CObject **, int))(*v3)[1].__vftable)(a1: v3, a2: 1);
    }
    v1 = i + 1;
  }
  CTooltipManager::DeleteToolTip(pToolTip: &this->m_pToolTip);
  CTooltipManager::DeleteToolTip(pToolTip: &this->m_pToolTipClose);
  CUIntArray::SetSize(this: &this->m_arTabs, nNewSize: 0, nGrowBy: -1);
  this->m_iTabsNum = 0;
  this->m_iActiveTab = -1;
}

//------------------------------------------------------------------------------
// Address: 0x103EE47A
// Name: public: virtual void CMFCControlRenderer::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCControlRenderer::CleanUp(CMFCControlRenderer *this)
{
  char *m_pszData; // ecx
  CMFCControlRendererInfo rSrc; // [esp+10h] [ebp-60h] BYREF
  int v4; // [esp+6Ch] [ebp-4h]

  CMFCToolBarImages::Clear(this: &this->m_Bitmap);
  CMFCToolBarImages::SetTransparentColor(this: &this->m_Bitmap, clrTransparent: 0xFFFFFFFF);
  CMFCControlRendererInfo::CMFCControlRendererInfo(this: &rSrc);
  v4 = 0;
  CMFCControlRendererInfo::operator=(this: &this->m_Params, &rSrc);
  m_pszData = rSrc.m_strBmpResID.m_pszData;
  this->m_bMirror = 0;
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103FDF74
// Name: public: void CPaneContainerGC::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaneContainerGC::CleanUp(CPaneContainerGC *this)
{
  CObject *v2; // eax

  while ( this->m_lstDisposedContainers.m_nCount != 0 )
  {
    v2 = CObList::RemoveHead(this: &this->m_lstDisposedContainers);
    if ( v2 != nullptr )
      ((void (__thiscall *)(CObject *, int))v2->dtr_CObject)(a1: v2, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FE038
// Name: protected: void CPaneContainer::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::CleanUp(CPaneContainer *this)
{
  CPaneContainer *m_pLeftContainer; // ecx
  CPaneContainer *v3; // ecx
  CPaneContainer *m_pRightContainer; // ecx
  CPaneContainer *v5; // ecx
  CPaneDivider *m_pSlider; // ecx

  m_pLeftContainer = this->m_pLeftContainer;
  if ( m_pLeftContainer != nullptr )
  {
    CPaneContainer::CleanUp(this: m_pLeftContainer);
    v3 = this->m_pLeftContainer;
    if ( v3 != nullptr )
      ((void (__thiscall *)(CPaneContainer *, int))v3->dtr_CObject)(a1: v3, a2: 1);
    this->m_pLeftContainer = nullptr;
  }
  m_pRightContainer = this->m_pRightContainer;
  if ( m_pRightContainer != nullptr )
  {
    CPaneContainer::CleanUp(this: m_pRightContainer);
    v5 = this->m_pRightContainer;
    if ( v5 != nullptr )
      ((void (__thiscall *)(CPaneContainer *, int))v5->dtr_CObject)(a1: v5, a2: 1);
    this->m_pRightContainer = nullptr;
  }
  m_pSlider = this->m_pSlider;
  if ( m_pSlider != nullptr && m_pSlider->m_bDefaultDivider == 0 && m_pSlider->m_hWnd != nullptr )
  {
    m_pSlider->DestroyWindow(this: m_pSlider);
    this->m_pSlider = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CF630
// Name: public: static char const __near * CProceduralTexturePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CProceduralTexturePanel::GetPanelClassName()
{
  return "CProceduralTexturePanel";
}

//------------------------------------------------------------------------------
// Address: 0x104CF640
// Name: public: virtual bool CProceduralTexturePanel::Init(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CProceduralTexturePanel::Init(
        CProceduralTexturePanel *this,
        int nWidth,
        int nHeight,
        bool bAllocateImageBuffer)
{
  const char *(__thiscall *GetName)(vgui::IClientPanel *); // edx
  const char *v6; // eax
  IMaterialSystem *v7; // eax
  ITexture *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  IMaterialSystem *v11; // eax
  IMaterial *v12; // ebx
  IMaterialVar *v13; // eax
  IMatSystemSurface *v14; // eax
  IMatSystemSurface *v15; // eax
  char pTemp[512]; // [esp+Ch] [ebp-200h] BYREF

  this->m_nWidth = nWidth;
  this->m_nHeight = nHeight;
  if ( bAllocateImageBuffer )
    this->m_pImageBuffer = (BGRA8888_t *)operator new(nSize: 4 * nHeight * nWidth);
  this->m_TextureSubRect.y = 0;
  this->m_TextureSubRect.x = 0;
  GetName = this->GetName;
  this->m_TextureSubRect.width = nWidth;
  this->m_TextureSubRect.height = nHeight;
  v6 = GetName(this);
  V_snprintf(pDest: pTemp, maxLen: 0x200u, pFormat: "__%s", v6);
  v7 = vgui::MaterialSystem();
  v8 = v7->CreateProceduralTexture(
         this: v7,
         a2: pTemp,
         a3: "VGUI textures",
         a4: this->m_nWidth,
         a5: this->m_nHeight,
         a6: IMAGE_FORMAT_BGRX8888,
         a7: 264972);
  v8->SetTextureRegenerator(this: v8, a2: &this->ITextureRegenerator, a3: true);
  CTextureReference::Init(this: &this->m_ProceduralTexture, pTexture: v8);
  v8->DecrementReferenceCount(this: v8);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "UnlitGeneric");
  else
    v10 = nullptr;
  KeyValues::SetString(this: v10, keyName: "$basetexture", value: pTemp);
  KeyValues::SetInt(this: v10, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v10, keyName: "$nodebug", value: 1);
  v11 = vgui::MaterialSystem();
  v12 = v11->CreateMaterial(this: v11, a2: pTemp, a3: v10);
  CMaterialReference::Init(this: &this->m_ProceduralMaterial, pMaterial: v12);
  v12->DecrementReferenceCount(this: v12);
  v13 = this->m_ProceduralMaterial.m_pMaterial->FindVarFast(
          this: this->m_ProceduralMaterial.m_pMaterial,
          a2: "$basetexture",
          a3: &textureVarCache);
  v13->SetTextureValue(this: v13, a2: v8);
  v14 = vgui::MatSystemSurface();
  this->m_nTextureID = v14->CreateNewTextureID(this: v14, a2: false);
  v15 = vgui::MatSystemSurface();
  v15->DrawSetTextureMaterial(this: v15, a2: this->m_nTextureID, a3: this->m_ProceduralMaterial.m_pMaterial);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104CF810
// Name: public: void CProceduralTexturePanel::MaintainProportions(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::MaintainProportions(CProceduralTexturePanel *this, bool bEnable)
{
  this->m_bMaintainProportions = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x104CF820
// Name: private: void CProceduralTexturePanel::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::CleanUp(CProceduralTexturePanel *this)
{
  IMatSystemSurface *v2; // eax
  ITexture *m_pTexture; // ecx

  if ( this->m_nTextureID != -1 )
  {
    v2 = vgui::MatSystemSurface();
    v2->DestroyTextureID(this: v2, a2: this->m_nTextureID);
    this->m_nTextureID = -1;
  }
  if ( this->m_ProceduralMaterial.m_pMaterial != nullptr )
    CMaterialReference::Shutdown(this: &this->m_ProceduralMaterial, bDeleteIfUnreferenced: true);
  m_pTexture = this->m_ProceduralTexture.m_pTexture;
  if ( m_pTexture != nullptr )
  {
    m_pTexture->SetTextureRegenerator(this: m_pTexture, a2: nullptr, a3: true);
    CTextureReference::Shutdown(this: &this->m_ProceduralTexture, bDeleteIfUnReferenced: true);
  }
  if ( this->m_pImageBuffer != nullptr )
  {
    operator delete(p: this->m_pImageBuffer);
    this->m_pImageBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CF8B0
// Name: public: int CProceduralTexturePanel::GetImageWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProceduralTexturePanel::GetImageWidth(CProceduralTexturePanel *this)
{
  return this->m_nWidth;
}

//------------------------------------------------------------------------------
// Address: 0x104CF8D0
// Name: public: void CProceduralTexturePanel::SetPaintRect(struct Rect_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::SetPaintRect(CProceduralTexturePanel *this, const Rect_t *pPaintRect)
{
  this->m_bUsePaintRect = pPaintRect != nullptr;
  if ( pPaintRect != nullptr )
    this->m_PaintRect = *pPaintRect;
}

//------------------------------------------------------------------------------
// Address: 0x104CF910
// Name: public: void CProceduralTexturePanel::DownloadTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::DownloadTexture(CProceduralTexturePanel *this)
{
  this->m_ProceduralTexture.m_pTexture->Download(this: this->m_ProceduralTexture.m_pTexture, a2: nullptr, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104CF930
// Name: public: virtual void CProceduralTexturePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProceduralTexturePanel::Paint(CProceduralTexturePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int m_nTextureID; // eax
  int height; // ecx
  int v6; // ecx
  int width; // eax
  int h; // [esp+44h] [ebp-8h] BYREF
  int w; // [esp+48h] [ebp-4h] BYREF

  m_nTextureID = this->m_nTextureID;
  if ( m_nTextureID != -1 )
  {
    ((void (__thiscall *)(vgui::ISurface *, int, int, int))g_pVGuiSurface->DrawSetTexture)(
      a1: g_pVGuiSurface,
      a2: m_nTextureID,
      a3,
      a4: a2);
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    if ( this->m_bUsePaintRect )
    {
      height = this->m_PaintRect.height;
      w = this->m_PaintRect.width;
      h = height;
    }
    if ( this->m_bMaintainProportions )
    {
      v6 = this->m_TextureSubRect.height;
      width = this->m_TextureSubRect.width;
      if ( width <= v6 )
        w = h * width / v6;
      else
        h = w * v6 / this->m_TextureSubRect.width;
    }
    ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawTexturedPolygon)(a1: g_pVGuiSurface, a2: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CFAE0
// Name: public: CProceduralTexturePanel::CProceduralTexturePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CProceduralTexturePanel *__thiscall CProceduralTexturePanel::CProceduralTexturePanel(
        CProceduralTexturePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&ITextureRegenerator::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  if ( `CProceduralTexturePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
    v4->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
    v5->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
    v6->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CTextureReference::CTextureReference(this: &this->m_ProceduralTexture);
  CMaterialReference::CMaterialReference(
    this: &this->m_ProceduralMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_pImageBuffer = nullptr;
  *(_WORD *)&this->m_bMaintainProportions = 0;
  this->m_PaintRect.y = 0;
  this->m_PaintRect.x = 0;
  this->m_PaintRect.height = 0;
  this->m_PaintRect.width = 0;
  this->m_nTextureID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CFC00
// Name: public: virtual struct vgui::PanelMessageMap __near * CProceduralTexturePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CProceduralTexturePanel::GetMessageMap(CProceduralTexturePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CFC30
// Name: public: virtual struct PanelAnimationMap __near * CProceduralTexturePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CProceduralTexturePanel::GetAnimMap(CProceduralTexturePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
}

//------------------------------------------------------------------------------
// Address: 0x104CFC40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CProceduralTexturePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CProceduralTexturePanel::GetKBMap(CProceduralTexturePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CFC70
// Name: public: virtual CProceduralTexturePanel::~CProceduralTexturePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::~CProceduralTexturePanel(CProceduralTexturePanel *this)
{
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  CProceduralTexturePanel::CleanUp(this);
  CMaterialReference::~CMaterialReference(this: &this->m_ProceduralMaterial);
  CTextureReference::~CTextureReference(this: &this->m_ProceduralTexture);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CFCB0
// Name: public: virtual void CProceduralTexturePanel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CProceduralTexturePanel::Shutdown(CProceduralTexturePanel *this)
{
  CProceduralTexturePanel::CleanUp(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CFCC0
// Name: public: virtual void CProceduralTexturePanel::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::RegenerateTextureBits(
        CProceduralTexturePanel *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture_vtbl *v5; // eax
  __int16 v6; // bx
  int v7; // ecx
  unsigned __int8 *v8; // eax
  BGRA8888_t *v9; // eax
  unsigned __int8 v10; // dl
  int b; // edi
  int r; // esi
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // edx
  int v17; // eax
  unsigned __int64 v18; // rdi
  __int64 v19; // rax
  unsigned __int64 v20; // rdi
  unsigned __int8 *pixelWriter; // [esp+Ch] [ebp-50h]
  unsigned __int8 *pixelWriter_4; // [esp+10h] [ebp-4Ch]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-46h]
  int pixelWriter_12; // [esp+18h] [ebp-44h]
  int pixelWriter_16; // [esp+1Ch] [ebp-40h]
  int pixelWriter_20; // [esp+20h] [ebp-3Ch]
  char pixelWriter_24; // [esp+24h] [ebp-38h]
  int pixelWriter_28; // [esp+28h] [ebp-34h]
  char pixelWriter_32; // [esp+2Ch] [ebp-30h]
  int nDepth; // [esp+38h] [ebp-24h] BYREF
  int v31; // [esp+3Ch] [ebp-20h]
  CProceduralTexturePanel *v32; // [esp+40h] [ebp-1Ch]
  int nHeight; // [esp+44h] [ebp-18h] BYREF
  unsigned __int8 *v34; // [esp+48h] [ebp-14h]
  int y; // [esp+4Ch] [ebp-10h]
  int nWidth; // [esp+50h] [ebp-Ch] BYREF
  int x; // [esp+54h] [ebp-8h]
  int v38; // [esp+58h] [ebp-4h]
  unsigned __int16 pTexel; // [esp+68h] [ebp+Ch]
  BGRA8888_t *pTexela; // [esp+68h] [ebp+Ch]

  v5 = pVTFTexture->__vftable;
  v32 = this;
  v5->ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  pTexel = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
  pixelWriter = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
  switch ( pVTFTexture->Format(this: pVTFTexture) )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      pixelWriter_12 = 0x80000;
      v6 = 16;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case IMAGE_FORMAT_BGR888:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_19;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_17;
    case IMAGE_FORMAT_A8:
      v6 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA8888:
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRX8888:
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case IMAGE_FORMAT_BGR565:
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      v6 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = -4;
      pixelWriter_28 = 248;
      goto LABEL_20;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      v6 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_24 = -8;
      pixelWriter_28 = 248;
      pixelWriter_32 = 0x80;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v6 = -4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = -16;
      pixelWriter_28 = 240;
      pixelWriter_32 = -16;
      goto LABEL_21;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      v6 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      pixelWriter_24 = -1;
      pixelWriter_28 = 0xFFFF;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      v6 = 64;
      pixelWriter_16 = 6291520;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA1010102:
      pixelWriter_10 = 4;
      pixelWriter_12 = 655380;
      v6 = 0;
      pixelWriter_16 = 1966080;
      pixelWriter_20 = 1023;
      pixelWriter_24 = -1;
      pixelWriter_28 = 1023;
      pixelWriter_32 = 3;
      goto LABEL_21;
    default:
      pixelWriter_10 = 0;
LABEL_17:
      pixelWriter_20 = 255;
LABEL_18:
      pixelWriter_12 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_19:
      v6 = 0;
      pixelWriter_16 = 0;
LABEL_20:
      pixelWriter_32 = 0;
LABEL_21:
      v7 = 0;
      y = 0;
      if ( nHeight > 0 )
      {
        v8 = pixelWriter;
        v31 = pTexel;
        v34 = pixelWriter;
        do
        {
          pixelWriter_4 = v8;
          v9 = (BGRA8888_t *)(*(_DWORD *)&v32->m_OnCommand_register + 4 * v7 * *(_DWORD *)&v32->m_OnDelete_register);
          pTexela = v9;
          x = 0;
          if ( nWidth > 0 )
          {
            v10 = pixelWriter_10;
            v38 = pixelWriter_10;
            while ( 1 )
            {
              b = v9->b;
              r = v9->r;
              if ( v10 != 0 )
              {
                v13 = (unsigned __int8)(v9->g & pixelWriter_24);
                if ( v10 >= 5u )
                {
                  v18 = ((unsigned __int64)(unsigned __int8)(pTexela->r & pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)v13 << SBYTE2(pixelWriter_12));
                  if ( v6 <= 0 )
                    v19 = (__int64)(unsigned __int8)(pTexela->b & pixelWriter_28) >> -(char)v6;
                  else
                    v19 = (unsigned __int64)(unsigned __int8)(pTexela->b & pixelWriter_28) << v6;
                  v20 = v19
                      | ((unsigned __int64)(unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16))
                      | v18;
                  if ( v38 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v20;
                    *((_WORD *)pixelWriter_4 + 2) = WORD2(v20);
                  }
                  else if ( v38 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v20;
                  }
                }
                else
                {
                  v14 = ((r & pixelWriter_20) << pixelWriter_12) | (v13 << SBYTE2(pixelWriter_12));
                  v15 = b & pixelWriter_28;
                  if ( v6 <= 0 )
                    v16 = v15 >> -(char)pixelWriter_16;
                  else
                    v16 = v15 << pixelWriter_16;
                  v17 = v16 | ((unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16)) | v14;
                  switch ( v38 )
                  {
                    case 1:
                      *pixelWriter_4 = v17;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v17;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v17;
                      pixelWriter_4[2] = BYTE2(v17);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v17;
                      break;
                    default:
                      break;
                  }
                }
              }
              pixelWriter_4 += v38;
              v9 = pTexela + 1;
              ++x;
              ++pTexela;
              if ( x >= nWidth )
                break;
              v10 = pixelWriter_10;
            }
            v7 = y;
          }
          v8 = &v34[v31];
          y = ++v7;
          v34 += v31;
        }
        while ( v7 < nHeight );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10366491
// Name: class CFrameWnd __near * AFXGetParentFrame(class CWnd const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWnd *__cdecl AFXGetParentFrame(CWnd *pWnd)
{
  CWnd *v1; // esi
  CObject *v3; // eax
  CWnd *v4; // eax
  HWND Parent; // eax

  v1 = pWnd;
  if ( pWnd == nullptr || pWnd->m_hWnd == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( CObject::IsKindOf(this: v1, pClass: &CPaneFrameWnd::classCPaneFrameWnd) != 0 )
    {
      v3 = AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: v1);
      v4 = CWnd::FromHandlePermanent(hWnd: (CDocument *)v3[47].__vftable);
    }
    else
    {
      Parent = GetParent(hWnd: v1->m_hWnd);
      v4 = CWnd::FromHandle(hWnd: Parent);
    }
    v1 = v4;
    if ( v4 == nullptr )
      break;
    if ( v4->IsFrameWnd(this: v4) != 0 )
      return (CFrameWnd *)v1;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103664FD
// Name: public: int AFX_GLOBAL_DATA::Resume(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall AFX_GLOBAL_DATA::Resume(AFX_GLOBAL_DATA *this)
{
  HINSTANCE__ *LibraryW; // eax
  HRESULT (__stdcall *DrawThemeParentBackground)(HWND, HDC, const RECT *); // eax
  HRESULT (__stdcall *DrawThemeTextEx)(HTHEME, HDC, int, int, LPCWSTR, int, DWORD, LPRECT, const DTTOPTS *); // eax
  HPAINTBUFFER (__stdcall *BeginBufferedPaint)(HDC, const RECT *, BP_BUFFERFORMAT, BP_PAINTPARAMS *, HDC *); // eax
  HINSTANCE__ *SystemLibraryUsingFullPath; // eax
  HRESULT (__stdcall *DwmExtendFrameIntoClientArea)(HWND, const MARGINS *); // eax
  BOOL (__stdcall *DwmDefWindowProc)(HWND, UINT, WPARAM, LPARAM, LRESULT *); // eax
  HINSTANCE__ *m_hinstUXThemeDLL; // [esp-8h] [ebp-14h]
  HINSTANCE__ *v11; // [esp-8h] [ebp-14h]
  HINSTANCE__ *v12; // [esp-8h] [ebp-14h]
  HINSTANCE__ *m_hinstDwmapiDLL; // [esp-8h] [ebp-14h]
  HINSTANCE__ *v14; // [esp-8h] [ebp-14h]

  LibraryW = AfxCtxLoadLibraryW(lpLibFileName: L"UxTheme.dll");
  this->m_hinstUXThemeDLL = LibraryW;
  if ( LibraryW != nullptr )
  {
    DrawThemeParentBackground = (HRESULT (__stdcall *)(HWND, HDC, const RECT *))GetProcAddress(
                                                                                  hModule: LibraryW,
                                                                                  lpProcName: "DrawThemeParentBackground");
    m_hinstUXThemeDLL = this->m_hinstUXThemeDLL;
    this->m_pfDrawThemeBackground = DrawThemeParentBackground;
    DrawThemeTextEx = (HRESULT (__stdcall *)(HTHEME, HDC, int, int, LPCWSTR, int, DWORD, LPRECT, const DTTOPTS *))GetProcAddress(hModule: m_hinstUXThemeDLL, lpProcName: "DrawThemeTextEx");
    v11 = this->m_hinstUXThemeDLL;
    this->m_pfDrawThemeTextEx = (HRESULT (__stdcall *)(void *, HDC__ *, int, int, const wchar_t *, int, unsigned int, tagRECT *, const _AFX_DTTOPTS *))DrawThemeTextEx;
    BeginBufferedPaint = (HPAINTBUFFER (__stdcall *)(HDC, const RECT *, BP_BUFFERFORMAT, BP_PAINTPARAMS *, HDC *))GetProcAddress(hModule: v11, lpProcName: "BeginBufferedPaint");
    v12 = this->m_hinstUXThemeDLL;
    this->m_pfBeginBufferedPaint = (void *(__stdcall *)(HDC__ *, const tagRECT *, _AFX_BP_BUFFERFORMAT, _AFX_BP_PAINTPARAMS *, HDC__ **))BeginBufferedPaint;
    this->m_pfEndBufferedPaint = (HRESULT (__stdcall *)(void *, int))GetProcAddress(
                                                                       hModule: v12,
                                                                       lpProcName: "EndBufferedPaint");
  }
  else
  {
    this->m_pfDrawThemeBackground = nullptr;
    this->m_pfDrawThemeTextEx = nullptr;
    this->m_pfBeginBufferedPaint = nullptr;
    this->m_pfEndBufferedPaint = nullptr;
  }
  if ( this->m_hinstDwmapiDLL != nullptr )
  {
    SystemLibraryUsingFullPath = AfxLoadSystemLibraryUsingFullPath(pszLibrary: L"dwmapi.dll");
    this->m_hinstDwmapiDLL = SystemLibraryUsingFullPath;
    if ( SystemLibraryUsingFullPath == nullptr )
      AfxThrowInvalidArgException();
    DwmExtendFrameIntoClientArea = (HRESULT (__stdcall *)(HWND, const MARGINS *))GetProcAddress(
                                                                                   hModule: SystemLibraryUsingFullPath,
                                                                                   lpProcName: "DwmExtendFrameIntoClientArea");
    m_hinstDwmapiDLL = this->m_hinstDwmapiDLL;
    this->m_pfDwmExtendFrameIntoClientArea = (HRESULT (__stdcall *)(HWND__ *, const _AFX_MARGINS *))DwmExtendFrameIntoClientArea;
    DwmDefWindowProc = (BOOL (__stdcall *)(HWND, UINT, WPARAM, LPARAM, LRESULT *))GetProcAddress(
                                                                                    hModule: m_hinstDwmapiDLL,
                                                                                    lpProcName: "DwmDefWindowProc");
    v14 = this->m_hinstDwmapiDLL;
    this->m_pfDwmDefWindowProc = DwmDefWindowProc;
    this->m_pfDwmIsCompositionEnabled = (HRESULT (__stdcall *)(int *))GetProcAddress(
                                                                        hModule: v14,
                                                                        lpProcName: "DwmIsCompositionEnabled");
  }
  if ( this->m_bEnableAccessibility != 0 )
    this->m_bEnableAccessibility = 1;
  CMFCVisualManagerOffice2007::CleanStyle();
  if ( CMFCVisualManager::m_pRTIDefault != nullptr )
    CMFCVisualManager::SetDefaultManager(pRTI: CMFCVisualManager::m_pRTIDefault);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10366601
// Name: public: long AFX_GLOBAL_DATA::ShellCreateItemFromParsingName(wchar_t const __near *,struct IBindCtx __near *,struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall AFX_GLOBAL_DATA::ShellCreateItemFromParsingName(
        AFX_GLOBAL_DATA *this,
        const wchar_t *pszPath,
        IBindCtx *pbc,
        const _GUID *riid,
        void **ppv)
{
  HRESULT (__stdcall *SHCreateItemFromParsingName)(PCWSTR, IBindCtx *, const IID *const, void **); // eax

  if ( (_S1_36 & 1) == 0 )
  {
    _S1_36 |= 1u;
    hShellDll = AfxCtxLoadLibraryA(lpLibFileName: "Shell32.dll");
  }
  if ( hShellDll == nullptr )
    AfxThrowInvalidArgException();
  SHCreateItemFromParsingName = (HRESULT (__stdcall *)(PCWSTR, IBindCtx *, const IID *const, void **))GetProcAddress(hModule: hShellDll, lpProcName: "SHCreateItemFromParsingName");
  if ( SHCreateItemFromParsingName != nullptr )
    return SHCreateItemFromParsingName(pszPath, pbc, riid, ppv);
  else
    return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10366670
// Name: public: int AFX_GLOBAL_DATA::DrawTextOnGlass(void __near *,class CDC __near *,int,int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CRect,unsigned long,int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall AFX_GLOBAL_DATA::DrawTextOnGlass(
        AFX_GLOBAL_DATA *this,
        void *hTheme,
        CDC *pDC,
        int iPartId,
        int iStateId,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText,
        CRect rect,
        unsigned int dwFlags,
        int nGlowSize,
        unsigned int clrText)
{
  wchar_t *m_str; // edi
  UINT v11; // eax
  unsigned __int16 *v12; // ebx
  UINT v13; // eax
  HDC__ *m_hDC; // eax
  _AFX_DTTOPTS dto; // [esp+10h] [ebp-5Ch] BYREF
  CDC *v17; // [esp+50h] [ebp-1Ch]
  AFX_GLOBAL_DATA *v18; // [esp+54h] [ebp-18h]
  ATL::CComBSTR bstmp; // [esp+58h] [ebp-14h] BYREF
  void *v20; // [esp+5Ch] [ebp-10h]
  int v21; // [esp+68h] [ebp-4h]

  v18 = this;
  v20 = hTheme;
  v17 = pDC;
  v21 = 0;
  if ( hTheme != nullptr && this->m_pfDrawThemeTextEx != nullptr && AFX_GLOBAL_DATA::DwmIsCompositionEnabled(this) != 0 )
  {
    ATL::CComBSTR::CComBSTR(this: &bstmp, pSrc: strText.m_pszData);
    m_str = bstmp.m_str;
    LOBYTE(v21) = 1;
    v11 = SysStringLen(pbstr: bstmp.m_str);
    v12 = (unsigned __int16 *)operator new(nSize: 2 * (v11 + 1));
    v13 = SysStringLen(pbstr: m_str);
    wcscpy_s(_Dst: v12, _SizeInWords: v13 + 1, _Src: m_str);
    memset(dst: (unsigned __int8 *)&dto, value: 0, count: sizeof(dto));
    dto.dwSize = 64;
    dto.dwFlags = 0x2000;
    if ( nGlowSize > 0 )
    {
      dto.dwFlags = 10240;
      dto.iGlowSize = nGlowSize;
    }
    if ( clrText != -1 )
    {
      dto.dwFlags |= 1u;
      dto.crText = clrText;
    }
    m_hDC = (HDC__ *)v17;
    if ( v17 != nullptr )
      m_hDC = v17->m_hDC;
    v18->m_pfDrawThemeTextEx(
      a1: v20,
      a2: m_hDC,
      a3: iPartId,
      a4: iStateId,
      a5: v12,
      a6: -1,
      a7: dwFlags,
      a8: &rect,
      a9: &dto);
    operator delete(p: v12);
    SysFreeString(bstrString: m_str);
    ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
    return 1;
  }
  else
  {
    pDC->DrawTextA(this: pDC, a2: strText.m_pszData, a3: *((_DWORD *)strText.m_pszData - 3), a4: &rect, a5: dwFlags);
    ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A3315
// Name: protected: void CMFCFontComboBox::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCFontComboBox::OnDestroy(CMFCFontComboBox *this)
{
  CMFCFontComboBox::CleanUp(this);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A3327
// Name: public: CMFCFontInfo::CMFCFontInfo(class CMFCFontInfo const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCFontInfo *__thiscall CMFCFontInfo::CMFCFontInfo(CMFCFontInfo *this, const CMFCFontInfo *src)
{
  this->__vftable = (CMFCFontInfo_vtbl *)&CMFCFontInfo::`vftable';
  this->m_strName.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)src->m_strName.m_pszData - 1)[1];
  this->m_strScript.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)src->m_strScript.m_pszData - 1)[1];
  this->m_nCharSet = src->m_nCharSet;
  this->m_nPitchAndFamily = src->m_nPitchAndFamily;
  this->m_nType = src->m_nType;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A3387
// Name: public: virtual CMFCFontInfo::~CMFCFontInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCFontInfo::~CMFCFontInfo(CMFCFontInfo *this)
{
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strScript.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103A33A3
// Name: public: virtual int CMFCFontComboBox::CompareItem(struct tagCOMPAREITEMSTRUCT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCFontComboBox::CompareItem(CMFCFontComboBox *this, tagCOMPAREITEMSTRUCT *lpCIS)
{
  tagCOMPAREITEMSTRUCT *v3; // esi
  WPARAM itemID1_low; // edi
  CAfxStringMgr *StringManager; // eax
  WPARAM itemID2_low; // esi
  CAfxStringMgr *v8; // eax
  int v9; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str2; // [esp+10h] [ebp-10h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  v3 = lpCIS;
  itemID1_low = LOWORD(lpCIS->itemID1);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
    this: (ATL::CSimpleStringT<char,0> *)&lpCIS,
    pStringMgr: StringManager);
  v11 = 0;
  CComboBox::GetLBText(
    this,
    nIndex: itemID1_low,
    rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpCIS);
  itemID2_low = LOWORD(v3->itemID2);
  v8 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &str2, pStringMgr: v8);
  LOBYTE(v11) = 1;
  CComboBox::GetLBText(this, nIndex: itemID2_low, rString: &str2);
  v9 = _mbscoll(s1: (const unsigned __int8 *)lpCIS, s2: (const unsigned __int8 *)str2.m_pszData);
  ATL::CStringData::Release(this: (ATL::CStringData *)str2.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)&lpCIS[-1].itemData1);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x103A3459
// Name: public: virtual void CMFCFontComboBox::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCFontComboBox::DrawItem(CMFCFontComboBox *this, tagDRAWITEMSTRUCT *lpDIS)
{
  CImageList *p_m_Images; // ebx
  CDC *v3; // esi
  int v4; // eax
  HBRUSH SolidBrush; // eax
  COLORREF BkColor; // eax
  HBRUSH v7; // eax
  unsigned int itemData; // edi
  HFONT v9; // eax
  CAfxStringMgr *StringManager; // eax
  tagPOINT v11; // [esp-Ch] [ebp-9Ch]
  signed int nIndex; // [esp+10h] [ebp-80h]
  int v14; // [esp+18h] [ebp-78h]
  CGdiObject v15; // [esp+1Ch] [ebp-74h] BYREF
  CGdiObject v16; // [esp+24h] [ebp-6Ch] BYREF
  ATL::CSimpleStringT<char,0> v17; // [esp+2Ch] [ebp-64h] BYREF
  int v18; // [esp+30h] [ebp-60h]
  LOGFONTA pv; // [esp+34h] [ebp-5Ch] BYREF
  tagRECT rcDst; // [esp+70h] [ebp-20h] BYREF
  int v21; // [esp+8Ch] [ebp-4h]

  p_m_Images = &this->m_Images;
  if ( this == (CMFCFontComboBox *)-116 || this->m_Images.m_hImageList == nullptr )
    CImageList::Create(this: &this->m_Images, nBitmapID: (const char *)0x4268, cx: 16, nGrow: 0, crMask: 0xFFFFFFu);
  v3 = CDC::FromHandle(hDC: lpDIS->hDC);
  CopyRect(lprcDst: &rcDst, lprcSrc: &lpDIS->rcItem);
  if ( (lpDIS->itemState & 0x10) != 0 )
    DrawFocusRect(hDC: v3->m_hDC, lprc: &rcDst);
  v4 = v3->SaveDC(this: v3);
  v16.m_hObject = nullptr;
  v14 = v4;
  v16.__vftable = (CGdiObject_vtbl *)&CBrush::`vftable';
  v21 = 0;
  if ( (lpDIS->itemState & 1) != 0 )
  {
    SolidBrush = CreateSolidBrush(color: afxGlobalData.clrHilite);
    CGdiObject::Attach(this: &v16, hObject: SolidBrush);
    v3->SetTextColor(this: v3, a2: afxGlobalData.clrTextHilite);
  }
  else
  {
    BkColor = GetBkColor(hdc: v3->m_hAttribDC);
    v7 = CreateSolidBrush(color: BkColor);
    CGdiObject::Attach(this: &v16, hObject: v7);
  }
  CDC::SetBkMode(this: v3, nBkMode: 1);
  FillRect(hDC: v3->m_hDC, lprc: &rcDst, hbr: (HBRUSH)v16.m_hObject);
  nIndex = lpDIS->itemID;
  if ( nIndex >= 0 )
  {
    v15.m_hObject = nullptr;
    v15.__vftable = (CGdiObject_vtbl *)&CFont::`vftable';
    itemData = lpDIS->itemData;
    v18 = 0;
    LOBYTE(v21) = 1;
    if ( itemData != 0 )
    {
      if ( (*(_DWORD *)(itemData + 16) & 6) != 0 )
      {
        v11.y = rcDst.top + (rcDst.bottom - rcDst.top - 16) / 2;
        v11.x = rcDst.left;
        CImageList::Draw(
          this: p_m_Images,
          pDC: (HDC__ *)v3,
          nImage: (*(_DWORD *)(itemData + 16) & 2) == 0,
          pt: v11,
          nStyle: 0);
      }
      rcDst.left += 22;
      if ( CMFCFontComboBox::m_bDrawUsingFont != 0 && *(_BYTE *)(itemData + 12) != 2 )
      {
        GetObjectA(h: afxGlobalData.fontRegular.m_hObject, c: 60, &pv);
        lstrcpyA(lpString1: pv.lfFaceName, lpString2: *(LPCSTR *)(itemData + 4));
        if ( *(_BYTE *)(itemData + 12) != 1 )
          pv.lfCharSet = *(_BYTE *)(itemData + 12);
        if ( pv.lfHeight >= 0 )
          pv.lfHeight += 4;
        else
          pv.lfHeight -= 4;
        v9 = CreateFontIndirectA(lplf: &pv);
        CGdiObject::Attach(this: &v15, hObject: v9);
        v18 = (int)v3->SelectObject(this: v3, a2: &v15);
      }
    }
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v17, pStringMgr: StringManager);
    LOBYTE(v21) = 2;
    CComboBox::GetLBText(this, nIndex, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v17);
    v3->DrawTextA(this: v3, a2: v17.m_pszData, a3: *((_DWORD *)v17.m_pszData - 3), a4: &rcDst, a5: 36u);
    if ( v18 != 0 )
      v3->SelectObject(this: v3, a2: (CFont *)v18);
    ATL::CStringData::Release(this: (ATL::CStringData *)v17.m_pszData - 1);
    LOBYTE(v21) = 0;
    v15.__vftable = (CGdiObject_vtbl *)&CFont::`vftable';
    CGdiObject::~CGdiObject(this: &v15);
  }
  v3->RestoreDC(this: v3, a2: v14);
  v21 = -1;
  v16.__vftable = (CGdiObject_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &v16);
}

//------------------------------------------------------------------------------
// Address: 0x103A367F
// Name: public: int CMFCFontComboBox::Setup(int,unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCFontComboBox::Setup(
        CMFCFontComboBox *this,
        int nFontType,
        unsigned __int8 nCharSet,
        unsigned __int8 nPitchAndFamily)
{
  const char *Item; // eax
  CMFCFontInfo *v7; // ecx
  WPARAM v8; // eax
  int Count; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-134h]
  unsigned __int8 nCharSeta[4]; // [esp+14h] [ebp-11Ch] BYREF
  int iIndex; // [esp+18h] [ebp-118h]
  unsigned __int8 nPitchAndFamilya[4]; // [esp+1Ch] [ebp-114h]
  CMFCToolBarFontComboBox v14; // [esp+20h] [ebp-110h] BYREF
  int v15; // [esp+12Ch] [ebp-4h]

  m_hWnd = this->m_hWnd;
  nCharSeta[0] = nCharSet;
  nPitchAndFamilya[0] = nPitchAndFamily;
  if ( !IsWindow(hWnd: m_hWnd) )
    AfxThrowInvalidArgException();
  if ( this->m_bToolBarMode != 0 )
    return 0;
  CMFCFontComboBox::CleanUp(this);
  CMFCToolBarFontComboBox::CMFCToolBarFontComboBox(
    this: &v14,
    uiID: 0,
    iImage: -1,
    nFontType,
    nCharSet: nCharSeta[0],
    dwStyle: 2u,
    iWidth: 0,
    nPitchAndFamily: nPitchAndFamilya[0]);
  v15 = 0;
  iIndex = 0;
  if ( CMFCToolBarComboBoxButton::GetCount(this: &v14) > 0 )
  {
    do
    {
      Item = CMFCToolBarComboBoxButton::GetItem(this: &v14, iIndex);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)nCharSeta,
        pszSrc: Item);
      LOBYTE(v15) = 1;
      *(_DWORD *)nPitchAndFamilya = CMFCToolBarComboBoxButton::GetItemData(this: &v14, iIndex);
      if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x158u, wParam: 0xFFFFFFFF, lParam: *(LPARAM *)nCharSeta) <= 0 )
      {
        v7 = (CMFCFontInfo *)operator new(nSize: 0x14u);
        LOBYTE(v15) = 2;
        if ( v7 != nullptr )
          *(_DWORD *)nPitchAndFamilya = CMFCFontInfo::CMFCFontInfo(
                                          this: v7,
                                          src: *(const CMFCFontInfo **)nPitchAndFamilya);
        else
          *(_DWORD *)nPitchAndFamilya = 0;
        v8 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: *(LPARAM *)nCharSeta);
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x151u, wParam: v8, lParam: *(LPARAM *)nPitchAndFamilya);
      }
      LOBYTE(v15) = 0;
      ATL::CStringData::Release(this: (ATL::CStringData *)(*(_DWORD *)nCharSeta - 16));
      ++iIndex;
      Count = CMFCToolBarComboBoxButton::GetCount(this: &v14);
    }
    while ( iIndex < Count );
  }
  v15 = -1;
  CMFCToolBarFontComboBox::~CMFCToolBarFontComboBox(this: &v14);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A37F9
// Name: protected: long CMFCFontComboBox::OnInitControl(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCFontComboBox::OnInitControl(CMFCFontComboBox *this, unsigned int wParam, const char *lParam)
{
  CAfxStringMgr *StringManager; // eax
  int v5; // eax
  CTagManager tagManager; // [esp+10h] [ebp-28h] BYREF
  int bShowDeviceTypeFonts; // [esp+18h] [ebp-20h] BYREF
  int bShowRasterTypeFonts; // [esp+1Ch] [ebp-1Ch] BYREF
  int bShowTrueTypeFonts; // [esp+20h] [ebp-18h] BYREF
  int bDrawUsingFont; // [esp+24h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDst; // [esp+28h] [ebp-10h] BYREF
  int v13; // [esp+34h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDst, pStringMgr: StringManager);
  v13 = 0;
  CMFCControlContainer::UTF8ToString(lpSrc: lParam, &strDst, nLength: wParam);
  CTagManager::CTagManager(this: &tagManager, lpszBuffer: strDst.m_pszData);
  LOBYTE(v13) = 1;
  bDrawUsingFont = 1;
  if ( CMFCControlContainer::ReadBoolProp(&tagManager, lpszTag: "MFCComboBox_DrawUsingFont", bMember: &bDrawUsingFont) != 0 )
    CMFCFontComboBox::m_bDrawUsingFont = bDrawUsingFont;
  bShowTrueTypeFonts = 1;
  CMFCControlContainer::ReadBoolProp(
    &tagManager,
    lpszTag: "MFCComboBox_ShowTrueTypeFonts",
    bMember: &bShowTrueTypeFonts);
  bShowRasterTypeFonts = 1;
  CMFCControlContainer::ReadBoolProp(
    &tagManager,
    lpszTag: "MFCComboBox_ShowRasterTypeFonts",
    bMember: &bShowRasterTypeFonts);
  bShowDeviceTypeFonts = 1;
  CMFCControlContainer::ReadBoolProp(
    &tagManager,
    lpszTag: "MFCComboBox_ShowDeviceTypeFonts",
    bMember: &bShowDeviceTypeFonts);
  v5 = 0;
  if ( bShowTrueTypeFonts != 0 )
    v5 = 4;
  if ( bShowRasterTypeFonts != 0 )
    v5 |= 1u;
  if ( bShowDeviceTypeFonts != 0 )
    v5 |= 2u;
  CMFCFontComboBox::Setup(this, nFontType: v5, nCharSet: 1u, nPitchAndFamily: 0);
  LOBYTE(v13) = 0;
  CTagManager::~CTagManager(this: &tagManager);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDst.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A38DE
// Name: protected: void CMFCFontComboBox::Init(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCFontComboBox::Init(CMFCFontComboBox *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  int IsKindOf; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  IsKindOf = CObject::IsKindOf(this: v3, pClass: &CMFCToolBar::classCMFCToolBar);
  this->m_bToolBarMode = IsKindOf;
  if ( IsKindOf == 0 )
    CMFCFontComboBox::Setup(this, nFontType: 7, nCharSet: 1u, nPitchAndFamily: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A54AF
// Name: public: virtual void CMFCButton::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::DrawItem(CMFCButton *this, tagDRAWITEMSTRUCT *lpDIS)
{
  CDC *v3; // eax
  CDC *p_m_dcMem; // ebx
  CMemDC v5; // [esp+10h] [ebp-5Ch] BYREF
  tagRECT rcDst; // [esp+4Ch] [ebp-20h] BYREF
  int v7; // [esp+68h] [ebp-4h]

  if ( lpDIS == nullptr || lpDIS->CtlType != 4 )
    AfxThrowInvalidArgException();
  v3 = CDC::FromHandle(hDC: lpDIS->hDC);
  CMemDC::CMemDC(this: &v5, dc: v3, pWnd: (HDC__ *)this);
  v7 = 0;
  p_m_dcMem = &v5.m_dcMem;
  if ( v5.m_bMemDC == 0 )
    p_m_dcMem = v5.m_dc;
  CopyRect(lprcDst: &rcDst, lprcSrc: &lpDIS->rcItem);
  this->OnFillBackground(this, a2: p_m_dcMem, a3: (const CRect *)&rcDst);
  this->OnDrawBorder(this, a2: p_m_dcMem, a3: (CRect *)&rcDst, a4: lpDIS->itemState);
  this->OnDraw(this, a2: p_m_dcMem, a3: (const CRect *)&rcDst, a4: lpDIS->itemState);
  if ( (lpDIS->itemState & 0x10) != 0 && this->m_bDrawFocus != 0 )
    this->OnDrawFocusRect(this, a2: p_m_dcMem, a3: (const CRect *)&rcDst);
  v7 = -1;
  CMemDC::~CMemDC(this: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x103A5571
// Name: public: void CMFCButton::SetStdImage(enum CMenuImages::IMAGES_IDS,enum CMenuImages::IMAGE_STATE,enum CMenuImages::IMAGES_IDS)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::SetStdImage(
        CMFCButton *this,
        CMenuImages::IMAGES_IDS id,
        CMenuImages::IMAGE_STATE state,
        CMenuImages::IMAGES_IDS idDisabled)
{
  CSize result; // [esp+4h] [ebp-8h] BYREF

  this->CleanUp(this);
  this->m_sizeImage = *CMenuImages::Size(&result);
  this->m_nStdImageId = id;
  this->m_nStdImageDisabledId = idDisabled;
  this->m_StdImageState = state;
}

//------------------------------------------------------------------------------
// Address: 0x103A55BD
// Name: public: void CMFCButton::SetMouseCursorHand(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::SetMouseCursorHand(CMFCButton *this)
{
  this->m_hCursor = AFX_GLOBAL_DATA::GetHandCursor(this: &afxGlobalData);
}

//------------------------------------------------------------------------------
// Address: 0x103A55D4
// Name: public: virtual void CMFCButton::OnDrawParentBackground(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnDrawParentBackground(CMFCButton *this, CWnd *pDC, CRect rectClient)
{
  AFX_GLOBAL_DATA::DrawParentBackground(this: &afxGlobalData, pWnd: this, pDC, rectClip: &rectClient);
}

//------------------------------------------------------------------------------
// Address: 0x103A55F0
// Name: protected: long CMFCButton::OnGetFont(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HFONT__ *__thiscall CMFCButton::OnGetFont(CMFCButton *this, unsigned int __formal, unsigned int __formala)
{
  return this->m_hFont;
}

//------------------------------------------------------------------------------
// Address: 0x103A55F9
// Name: public: void CMFCButton::EnableFullTextTooltip(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::EnableFullTextTooltip(CMFCButton *this, int bOn)
{
  this->m_bFullTextTooltip = bOn;
  this->m_bDelayFullTextTooltipSet = bOn;
}

//------------------------------------------------------------------------------
// Address: 0x103A5611
// Name: protected: long CMFCButton::OnGetCheck(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCButton::OnGetCheck(CMFCButton *this, unsigned int __formal, unsigned int __formala)
{
  BOOL result; // eax

  result = false;
  if ( this->m_bCheckButton != 0 || this->m_bRadioButton != 0 )
    return this->m_bChecked != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B44D7
// Name: protected: static void CMenuImages::CreateCopy(class CMFCToolBarImages __near &,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMenuImages::CreateCopy(CMFCToolBarImages *images, unsigned int clr)
{
  CMFCToolBarImages::CopyTo(this: &CMenuImages::m_ImagesBlack, dest: images);
  CMFCToolBarImages::MapTo3dColors(this: images, bUseRGBQUAD: 1, clrSrc: 0, clrDest: clr);
}

//------------------------------------------------------------------------------
// Address: 0x103B44FC
// Name: protected: static int CMenuImages::Initialize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMenuImages::Initialize()
{
  int result; // eax
  BOOL v1; // eax
  double dblImageScale_4; // [esp+14h] [ebp-8h]

  if ( CMenuImages::m_bInitializing != 0 )
    return 0;
  if ( CMenuImages::m_ImagesBlack.m_hbmImageWell != nullptr )
    return 1;
  CMenuImages::m_ImagesBlack.m_sizeImage.cy = 9;
  CMenuImages::m_bInitializing = 1;
  CMenuImages::m_ImagesBlack.m_sizeImage.cx = 9;
  v1 = AFX_GLOBAL_DATA::Is32BitIcons(this: &afxGlobalData);
  result = CMFCToolBarImages::Load(
             this: &CMenuImages::m_ImagesBlack,
             uiResID: v1 ? 17080 : 16129,
             hinstRes: nullptr,
             bAdd: 0);
  if ( result != 0 )
  {
    if ( CMFCToolBarImages::m_bIsRTL != 0 )
      CMFCToolBarImages::Mirror(this: &CMenuImages::m_ImagesBlack);
    CMFCToolBarImages::SetTransparentColor(this: &CMenuImages::m_ImagesBlack, clrTransparent: 0xFF00FFu);
    CMenuImages::CreateCopy(images: &CMenuImages::m_ImagesGray, clr: 0x808080u);
    CMenuImages::CreateCopy(images: &CMenuImages::m_ImagesDkGray, clr: 0x484848u);
    CMenuImages::CreateCopy(images: &CMenuImages::m_ImagesLtGray, clr: 0xC0C0C0u);
    CMenuImages::CreateCopy(images: &CMenuImages::m_ImagesWhite, clr: 0xFFFFFFu);
    CMenuImages::CreateCopy(images: &CMenuImages::m_ImagesBlack2, clr: 0);
    if ( CMenuImages::m_ImagesBlack.m_hbmImageWell != nullptr )
    {
      if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
        dblImageScale_4 = afxGlobalData.m_dblRibbonImageScale;
      else
        dblImageScale_4 = 1.0;
      if ( dblImageScale_4 != 1.0 )
      {
        CMFCToolBarImages::SmoothResize(this: &CMenuImages::m_ImagesBlack, dblImageScale: dblImageScale_4);
        CMFCToolBarImages::SmoothResize(this: &CMenuImages::m_ImagesGray, dblImageScale: dblImageScale_4);
        CMFCToolBarImages::SmoothResize(this: &CMenuImages::m_ImagesDkGray, dblImageScale: dblImageScale_4);
        CMFCToolBarImages::SmoothResize(this: &CMenuImages::m_ImagesLtGray, dblImageScale: dblImageScale_4);
        CMFCToolBarImages::SmoothResize(this: &CMenuImages::m_ImagesWhite, dblImageScale: dblImageScale_4);
        CMFCToolBarImages::SmoothResize(this: &CMenuImages::m_ImagesBlack2, dblImageScale: dblImageScale_4);
      }
    }
    result = 1;
  }
  CMenuImages::m_bInitializing = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B4674
// Name: public: static class CSize CMenuImages::Size(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__stdcall CMenuImages::Size(CSize *result)
{
  int v1; // edx
  int v2; // ecx
  long double m_dblRibbonImageScale; // st6

  if ( CMenuImages::m_bInitializing != 0 )
  {
    v1 = 9;
    v2 = 9;
    if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
      m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
    else
      m_dblRibbonImageScale = 1.0;
    if ( m_dblRibbonImageScale != 1.0 )
    {
      v2 = (int)(m_dblRibbonImageScale * 9.0 + 0.5);
      v1 = v2;
    }
    result->cx = v2;
    result->cy = v1;
    return result;
  }
  else
  {
    CMenuImages::Initialize();
    *result = CMenuImages::m_ImagesBlack.m_sizeImage;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B46E9
// Name: public: static void CMenuImages::Draw(class CDC __near *,enum CMenuImages::IMAGES_IDS,class CPoint const __near &,enum CMenuImages::IMAGE_STATE,class CSize const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMenuImages::Draw(
        CDC *pDC,
        CMenuImages::IMAGES_IDS id,
        const CPoint *ptImage,
        CMenuImages::IMAGE_STATE state,
        const CSize *sizeImage)
{
  CMFCToolBarImages *v5; // esi
  tagAFXDrawState v6; // [esp+0h] [ebp-Ch] BYREF

  if ( CMenuImages::Initialize() != 0 )
  {
    if ( state != ImageBlack )
    {
      switch ( state )
      {
        case ImageGray:
          v5 = &CMenuImages::m_ImagesGray;
          break;
        case ImageDkGray:
          v5 = &CMenuImages::m_ImagesDkGray;
          break;
        case ImageLtGray:
          v5 = &CMenuImages::m_ImagesLtGray;
          break;
        default:
          v5 = &CMenuImages::m_ImagesWhite;
          if ( state != ImageWhite )
            v5 = &CMenuImages::m_ImagesBlack2;
          break;
      }
    }
    else
    {
      v5 = &CMenuImages::m_ImagesBlack;
    }
    CMFCToolBarImages::PrepareDrawImage(this: v5, ds: &v6, sizeImageDest: *sizeImage, bFadeInactive: 0);
    CMFCToolBarImages::Draw(
      this: v5,
      pDCDest: pDC,
      xDest: (CDC_vtbl *)ptImage->x,
      yDest: ptImage->y,
      iImage: id,
      bHilite: 0,
      bDisabled: 0,
      bIndeterminate: 0,
      bShadow: 0,
      bInactive: 0,
      alphaSrc: 0xFFu);
    CMFCToolBarImages::EndDrawImage(this: v5, ds: &v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B4787
// Name: public: static void CMenuImages::Draw(class CDC __near *,enum CMenuImages::IMAGES_IDS,class CRect const __near &,enum CMenuImages::IMAGE_STATE,class CSize const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMenuImages::Draw(
        CDC *pDC,
        CMenuImages::IMAGES_IDS id,
        const CRect *rectImage,
        CMenuImages::IMAGE_STATE state,
        CSize *sizeImageDest)
{
  CSize *v5; // eax
  int cx; // edx
  int cy; // edi
  int bottom; // eax
  CPoint ptImage; // [esp+0h] [ebp-8h] BYREF

  if ( CSize::operator==(this: sizeImageDest, size: 0) )
    v5 = CMenuImages::Size(result: (CSize *)&ptImage);
  else
    v5 = sizeImageDest;
  cx = v5->cx;
  cy = v5->cy;
  bottom = rectImage->bottom;
  ptImage.x = (rectImage->right - rectImage->left - cx) / 2
            + (rectImage->right - rectImage->left - cx) % 2
            + rectImage->left;
  ptImage.y = (bottom - rectImage->top - cy) / 2 + (bottom - rectImage->top - cy) % 2 + rectImage->top;
  CMenuImages::Draw(pDC, id, &ptImage, state, sizeImage: sizeImageDest);
}

//------------------------------------------------------------------------------
// Address: 0x103B91F1
// Name: double SinC(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl SinC(long double dValue)
{
  if ( 0.0 == dValue )
    return 1.0;
  else
    return sin(X: dValue * 3.141592653589793) / (dValue * 3.141592653589793);
}

//------------------------------------------------------------------------------
// Address: 0x103B9228
// Name: double Filter_Box(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl Filter_Box(double dValue)
{
  if ( dValue <= -0.5 || dValue > 0.5 )
    return 0.0;
  else
    return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x103B9255
// Name: double Filter_Bilinear(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl Filter_Bilinear(double dValue)
{
  double result; // st7
  long double v2; // st6

  result = 0.0;
  v2 = dValue;
  if ( dValue < 0.0 )
    v2 = -dValue;
  if ( v2 < 1.0 )
    return 1.0 - v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B9281
// Name: double Filter_Bicubic(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl Filter_Bicubic(double dValue)
{
  double result; // st7
  long double v2; // st6

  result = 0.0;
  v2 = dValue;
  if ( dValue < 0.0 )
    v2 = -dValue;
  if ( v2 < 1.0 )
    return v2 * ((v2 + v2 - 3.0) * v2) + 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B92BB
// Name: double Filter_Bell(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl Filter_Bell(double dValue)
{
  double result; // st7
  long double v2; // st6

  result = 0.0;
  v2 = dValue;
  if ( dValue < 0.0 )
    v2 = -dValue;
  if ( v2 < 0.5 )
    return 0.75 - v2 * v2;
  if ( v2 < 1.5 )
    return (v2 - 1.5) * (0.5 * (v2 - 1.5));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B9314
// Name: double Filter_BSpline(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl Filter_BSpline(double dValue)
{
  double result; // st7
  long double v2; // st6

  result = 0.0;
  v2 = dValue;
  if ( dValue < 0.0 )
    v2 = -dValue;
  if ( v2 < 1.0 )
    return v2 * (0.5 * (v2 * v2)) - v2 * v2 + 0.6666666666666666;
  if ( v2 < 2.0 )
    return (2.0 - v2) * ((2.0 - v2) * (2.0 - v2)) / 6.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B9375
// Name: double Filter_Lanczos3(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl Filter_Lanczos3(long double dValue)
{
  long double result; // st7
  long double v2; // [esp+0h] [ebp-8h]

  result = 0.0;
  if ( dValue < 0.0 )
    dValue = -dValue;
  if ( dValue < 3.0 )
  {
    v2 = SinC(dValue: dValue / 3.0);
    return SinC(dValue) * v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B93C8
// Name: double Filter_Mitchell(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl Filter_Mitchell(double dValue)
{
  long double v1; // st6
  long double v2; // st4
  long double v3; // st3

  if ( (`Filter_Mitchell'::`2'::`local static guard' & 1) != 0 )
  {
    v1 = `Filter_Mitchell'::`2'::C;
  }
  else
  {
    `Filter_Mitchell'::`2'::`local static guard' |= 1u;
    v1 = `Filter_Mitchell'::`2'::B;
    `Filter_Mitchell'::`2'::C = `Filter_Mitchell'::`2'::B;
  }
  v2 = dValue;
  if ( dValue < 0.0 )
    v2 = -dValue;
  v3 = v2 * v2;
  if ( v2 < 1.0 )
    return (v3 * (v1 * 6.0 + 12.0 * `Filter_Mitchell'::`2'::B - 18.0)
          + v2 * v3 * (12.0 - `Filter_Mitchell'::`2'::B * 9.0 - v1 * 6.0)
          + 6.0
          - (`Filter_Mitchell'::`2'::B
           + `Filter_Mitchell'::`2'::B))
         / 6.0;
  if ( v2 >= 2.0 )
    return 0.0;
  return (`Filter_Mitchell'::`2'::B * 8.0
        + v1 * 24.0
        + v2 * (`Filter_Mitchell'::`2'::B * -12.0 - v1 * 48.0)
        + v3 * (`Filter_Mitchell'::`2'::B * 6.0 + v1 * 30.0)
        + (`Filter_Mitchell'::`2'::B * -1.0 - v1 * 6.0) * (v3 * v2))
       / 6.0;
}

//------------------------------------------------------------------------------
// Address: 0x103B95D4
// Name: protected: void CMFCToolBarImages::CreateMask(int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarImages::CreateMask(CMFCToolBarImages *this, int iImage, int bHilite, int bHiliteShadow)
{
  COLORREF clrBtnFace; // eax

  PatBlt(hdc: hDCMono, x: 0, y: 0, w: this->m_sizeImage.cx + 2, h: this->m_sizeImage.cy + 2, rop: 0xFF0062u);
  if ( this->m_nBitsPerPixel == 32 || (clrBtnFace = this->m_clrTransparent) == -1 )
    clrBtnFace = afxGlobalData.clrBtnFace;
  SetBkColor(hdc: hDCGlyphs, color: clrBtnFace);
  BitBlt(
    hdc: hDCMono,
    x: 0,
    y: 0,
    cx: this->m_sizeImage.cx,
    cy: this->m_sizeImage.cy,
    hdcSrc: hDCGlyphs,
    x1: iImage * this->m_sizeImage.cx,
    y1: 0,
    rop: 0xCC0020u);
  if ( bHilite != 0 )
  {
    SetBkColor(hdc: hDCGlyphs, color: afxGlobalData.clrBtnHilite);
    BitBlt(
      hdc: hDCMono,
      x: 0,
      y: 0,
      cx: this->m_sizeImage.cx,
      cy: this->m_sizeImage.cy,
      hdcSrc: hDCGlyphs,
      x1: iImage * this->m_sizeImage.cx,
      y1: 0,
      rop: 0xEE0086u);
    if ( bHiliteShadow != 0 )
      BitBlt(
        hdc: hDCMono,
        x: 1,
        y: 1,
        cx: this->m_sizeImage.cx + 1,
        cy: this->m_sizeImage.cy + 1,
        hdcSrc: hDCMono,
        x1: 0,
        y1: 0,
        rop: 0x8800C6u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B96B3
// Name: protected: void CMFCToolBarImages::UpdateCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarImages::UpdateCount(CMFCToolBarImages *this)
{
  HBITMAP__ *m_hbmImageWell; // eax
  tagBITMAP bmp; // [esp+4h] [ebp-18h] BYREF

  m_hbmImageWell = this->m_hbmImageWell;
  if ( m_hbmImageWell != nullptr && GetObjectA(h: m_hbmImageWell, c: 24, pv: &bmp) != 0 )
    this->m_iCount = bmp.bmWidth / this->m_sizeImage.cx;
  else
    this->m_iCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103B96EC
// Name: public: static unsigned long CMFCToolBarImages::MapToSysColor(unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCToolBarImages::MapToSysColor(unsigned int color, int bUseRGBQUAD)
{
  int result; // eax
  int v3; // ecx
  int *v4; // esi
  int v5; // edi
  unsigned int colora; // [esp+8h] [ebp+8h]

  result = color;
  v3 = 0;
  while ( color != sysColorMap[v3].rgbTo )
  {
    if ( ++v3 >= 4 )
      return result;
  }
  if ( bUseRGBQUAD == 0 )
    return AFX_GLOBAL_DATA::GetColor(this: &afxGlobalData, nColor: nColor[2 * v3]);
  v4 = &nColor[2 * v3];
  colora = (unsigned __int8)((unsigned __int16)AFX_GLOBAL_DATA::GetColor(this: &afxGlobalData, nColor: *v4) >> 8);
  v5 = (colora | ((unsigned __int8)AFX_GLOBAL_DATA::GetColor(this: &afxGlobalData, nColor: *v4) << 8)) << 8;
  return v5 | (unsigned __int8)(AFX_GLOBAL_DATA::GetColor(this: &afxGlobalData, nColor: *v4) >> 16);
}

//------------------------------------------------------------------------------
// Address: 0x103B976E
// Name: public: static unsigned long CMFCToolBarImages::MapToSysColorAlpha(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCToolBarImages::MapToSysColorAlpha(unsigned int color)
{
  if ( (int)abs(lnumber: (unsigned __int8)color - BYTE2(color)) > 10
    || (int)abs(lnumber: (unsigned __int8)color - BYTE1(color)) > 10
    || (int)abs(lnumber: BYTE2(color) - BYTE1(color)) > 10 )
  {
    return color;
  }
  else
  {
    return CDrawingManager::PixelAlpha(
             srcPixel: afxGlobalData.clrBarFace,
             percentR: ((double)(unsigned __int8)color - 192.0) / 255.0 + 1.0,
             percentG: ((double)BYTE1(color) - 192.0) / 255.0 + 1.0,
             percentB: ((double)BYTE2(color) - 192.0) / 255.0 + 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B9814
// Name: public: static unsigned long CMFCToolBarImages::MapFromSysColor(unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall CMFCToolBarImages::MapFromSysColor(unsigned int color, int bUseRGBQUAD)
{
  int v2; // esi
  unsigned int v3; // eax

  v2 = 0;
  while ( 1 )
  {
    v3 = AFX_GLOBAL_DATA::GetColor(this: &afxGlobalData, nColor: nColor[2 * v2]);
    if ( bUseRGBQUAD != 0 )
    {
      if ( color == (BYTE2(v3) | ((((unsigned __int8)v3 << 8) | BYTE1(v3)) << 8)) )
        return BYTE2(sysColorMap[v2].rgbTo)
             | ((BYTE1(sysColorMap[v2].rgbTo) | (LOBYTE(sysColorMap[v2].rgbTo) << 8)) << 8);
      goto LABEL_6;
    }
    if ( color == v3 )
      return sysColorMap[v2].rgbTo;
LABEL_6:
    if ( ++v2 >= 4 )
      return color;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B9895
// Name: public: static int CMFCToolBarImages::PreMultiplyAlpha(struct HBITMAP__ __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCToolBarImages::PreMultiplyAlpha(HBITMAP__ *hbmp, int bAutoCheckPremlt)
{
  int v3; // edx
  int v4; // esi
  unsigned __int8 *i; // eax
  unsigned __int8 v6; // cl
  _BYTE *v7; // ecx
  int v8; // edi
  int v9; // eax
  bool v10; // zf
  int v11; // [esp+0h] [ebp-5Ch]
  tagDIBSECTION pv; // [esp+4h] [ebp-58h] BYREF

  if ( GetObjectA(h: hbmp, c: 84, &pv) == 0 || pv.dsBm.bmBitsPixel != 32 )
    return 0;
  if ( pv.dsBm.bmBits == nullptr )
    return 0;
  v3 = pv.dsBm.bmWidth * pv.dsBm.bmHeight;
  if ( bAutoCheckPremlt == 0 )
    goto LABEL_14;
  v4 = 0;
  if ( v3 > 0 )
  {
    for ( i = (unsigned __int8 *)pv.dsBm.bmBits + 3; ; i += 4 )
    {
      v6 = *i;
      if ( *(i - 1) > *i || *(i - 2) > v6 || *(i - 3) > v6 )
        break;
      if ( ++v4 >= v3 )
        return 1;
    }
LABEL_14:
    if ( v3 > 0 )
    {
      v7 = (char *)pv.dsBm.bmBits + 1;
      v11 = pv.dsBm.bmWidth * pv.dsBm.bmHeight;
      do
      {
        v8 = (unsigned __int8)v7[2];
        v7[1] = v8 * (unsigned __int8)v7[1] / 255;
        *v7 = v8 * (unsigned __int8)*v7 / 255;
        v9 = v8 * (unsigned __int8)*(v7 - 1) / 255;
        v7 += 4;
        v10 = v11-- == 1;
        *(v7 - 5) = v9;
      }
      while ( !v10 );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103B9960
// Name: public: static void CMFCToolBarImages::EnableRTL(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMFCToolBarImages::EnableRTL(int bIsRTL)
{
  CMFCToolBarImages::m_bIsRTL = bIsRTL;
}

//------------------------------------------------------------------------------
// Address: 0x103B9971
// Name: public: CList<struct HINSTANCE__ __near *,struct HINSTANCE__ __near *>::CList<struct HINSTANCE__ __near *,struct HINSTANCE__ __near *>(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<HINSTANCE__ *,HINSTANCE__ *> *__thiscall CList<HINSTANCE__ *,HINSTANCE__ *>::CList<HINSTANCE__ *,HINSTANCE__ *>(
        CList<HINSTANCE__ *,HINSTANCE__ *> *this,
        int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CList<HINSTANCE__ *,HINSTANCE__ *>_vtbl *)&CList<HINSTANCE__ *,HINSTANCE__ *>::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B9999
// Name: public: virtual CList<struct HINSTANCE__ __near *,struct HINSTANCE__ __near *>::~CList<struct HINSTANCE__ __near *,struct HINSTANCE__ __near *>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<HINSTANCE__ *,HINSTANCE__ *>::~CList<HINSTANCE__ *,HINSTANCE__ *>(
        CList<HINSTANCE__ *,HINSTANCE__ *> *this)
{
  this->__vftable = (CList<HINSTANCE__ *,HINSTANCE__ *>_vtbl *)&CList<HINSTANCE__ *,HINSTANCE__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103B99CB
// Name: void SerializeElements<long>(class CArchive __near &,long __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SerializeElements<long>(CArchive *ar, CDocument **pElements, CDocument **nCount)
{
  unsigned int v4; // ebx
  int v5; // edi
  int v6; // edi
  CDocument **pData; // [esp+10h] [ebp+10h]

  if ( nCount != nullptr && pElements == nullptr )
    AfxThrowInvalidArgException();
  v4 = (unsigned int)nCount;
  pData = pElements;
  if ( (ar->m_nMode & 1) != 0 )
  {
    if ( nCount != nullptr )
    {
      do
      {
        v6 = 0x1FFFFFFF;
        if ( v4 < 0x1FFFFFFF )
          v6 = v4;
        CArchive::EnsureRead(this: ar, lpBuf: pData, nCount: 4 * v6);
        pData += v6;
        v4 -= v6;
      }
      while ( v4 != 0 );
    }
  }
  else if ( nCount != nullptr )
  {
    do
    {
      v5 = 0x1FFFFFFF;
      if ( v4 < 0x1FFFFFFF )
        v5 = v4;
      CArchive::Write(this: ar, lpBuf: pData, nMax: 4 * v5);
      pData += v5;
      v4 -= v5;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B9A4F
// Name: private: long CCriticalSection::Init(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CCriticalSection::Init(CCriticalSection *this)
{
  HRESULT result; // eax

  if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: &this->m_sect, dwSpinCount: 0) )
    return 0;
  result = GetLastError();
  if ( result > 0 )
    return (unsigned __int16)result | 0x80070000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B9A77
// Name: public: CCriticalSection::CCriticalSection(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCriticalSection *__thiscall CCriticalSection::CCriticalSection(CCriticalSection *this)
{
  HRESULT v2; // eax

  CSyncObject::CSyncObject(this, pstrName: nullptr);
  this->__vftable = (CCriticalSection_vtbl *)&CCriticalSection::`vftable';
  v2 = CCriticalSection::Init(this);
  if ( v2 < 0 )
    ATL::AtlThrowImpl(hr: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B9AB2
// Name: public: virtual CCriticalSection::~CCriticalSection(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::~CCriticalSection(CCriticalSection *this)
{
  this->__vftable = (CCriticalSection_vtbl *)&CCriticalSection::`vftable';
  DeleteCriticalSection(lpCriticalSection: &this->m_sect);
  CSyncObject::~CSyncObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B9ACF
// Name: public: virtual int CCriticalSection::Lock(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CCriticalSection::Lock(CCriticalSection *this, unsigned int dwTimeout)
{
  EnterCriticalSection(lpCriticalSection: &this->m_sect);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103B9ADF
// Name: public: virtual int CCriticalSection::Unlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CCriticalSection::Unlock(CCriticalSection *this)
{
  LeaveCriticalSection(lpCriticalSection: &this->m_sect);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103B9AED
// Name: public: Gdiplus::Graphics::Graphics(class Gdiplus::Image __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Gdiplus::Graphics *__thiscall Gdiplus::Graphics::Graphics(Gdiplus::Graphics *this, Gdiplus::Image *image)
{
  Gdiplus::GpGraphics *graphics; // [esp+4h] [ebp-4h] BYREF

  graphics = nullptr;
  if ( image != nullptr )
    this->lastResult = GdipGetImageGraphicsContext(a1: (int)image->nativeImage, a2: (int)&graphics);
  this->nativeGraphics = graphics;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B9B1C
// Name: public: enum Gdiplus::Status Gdiplus::Graphics::DrawImage(class Gdiplus::Image __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Gdiplus::Status __thiscall Gdiplus::Graphics::DrawImage(Gdiplus::Graphics *this, Gdiplus::Image *image, int x, int y)
{
  Gdiplus::GpImage *nativeImage; // eax
  Gdiplus::Status result; // eax

  if ( image != nullptr )
    nativeImage = image->nativeImage;
  else
    nativeImage = nullptr;
  result = GdipDrawImageI(a1: (int)this->nativeGraphics, a2: (int)nativeImage, a3: x, a4: y);
  if ( result == Ok )
    return Ok;
  this->lastResult = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B9B50
// Name: public: virtual CMFCZoomKernel::~CMFCZoomKernel(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCZoomKernel::~CMFCZoomKernel(CMFCZoomKernel *this)
{
  this->__vftable = (CMFCZoomKernel_vtbl *)&CMFCZoomKernel::`vftable';
  CMFCZoomKernel::Empty(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B9B5B
// Name: public: void CMFCZoomKernel::Create(long,long,long,long,enum CMFCZoomKernel::XFilterType)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCZoomKernel::Create(
        CMFCZoomKernel *this,
        int sizeSrc,
        int sizeDst,
        int originSrc,
        int widthSrc,
        CMFCZoomKernel::XFilterType ft)
{
  int v7; // ebx
  unsigned int v8; // edi
  int v9; // ebx
  long double v10; // st7
  double v11; // st7
  int v12; // eax
  unsigned int v13; // ecx
  CMFCZoomKernel::XKernel *v14; // edx
  long double v15; // st6
  unsigned int v16; // ecx
  int v17; // edx
  long double *p_weight; // eax
  double v19; // [esp+0h] [ebp-60h]
  double v20; // [esp+14h] [ebp-4Ch]
  double v21; // [esp+1Ch] [ebp-44h]
  double correction_4; // [esp+24h] [ebp-3Ch]
  double correction_4a; // [esp+24h] [ebp-3Ch]
  double scale_4; // [esp+2Ch] [ebp-34h]
  double center_4; // [esp+34h] [ebp-2Ch]
  double width_4; // [esp+3Ch] [ebp-24h]
  long double (__cdecl *weightSum_4)(long double); // [esp+44h] [ebp-1Ch]
  int dScale; // [esp+48h] [ebp-18h]
  CMFCZoomKernel::XKernel *dScale_4; // [esp+4Ch] [ebp-14h]
  CMFCZoomKernel::XKernel *lpFilterProc; // [esp+50h] [ebp-10h]
  int right; // [esp+54h] [ebp-Ch]
  unsigned int v32; // [esp+58h] [ebp-8h]
  CMFCZoomKernel::XKernel *pStat; // [esp+5Ch] [ebp-4h]
  char j_3; // [esp+6Bh] [ebp+Bh]
  char v35; // [esp+6Fh] [ebp+Fh]
  unsigned int bFirst; // [esp+78h] [ebp+18h]

  if ( sizeSrc <= 0 || sizeDst <= 0 )
    return;
  CMFCZoomKernel::Empty(this);
  this->m_Size = sizeDst;
  width_4 = (double)(unsigned int)sizeDst / (double)sizeSrc;
  weightSum_4 = Filters[ft].Proc;
  correction_4 = Filters[ft].Width;
  scale_4 = correction_4;
  this->m_List = (CMFCZoomKernel::XKernelList *)operator new(nSize: 8 * sizeDst);
  v21 = 1.0;
  v20 = -0.25;
  if ( width_4 < 1.0 )
  {
    scale_4 = correction_4 / width_4;
    v21 = width_4;
    v20 = 0.25;
  }
  v32 = 0;
  if ( this->m_Size == 0 )
    return;
  do
  {
    correction_4a = (double)v32 / width_4;
    v7 = (int)floor(X: correction_4a - scale_4);
    dScale = (int)ceil(X: correction_4a + scale_4);
    v8 = v32;
    this->m_List[v32].count = 0;
    if ( dScale - v7 == -1 )
      goto LABEL_27;
    bFirst = 0;
    center_4 = 0.0;
    this->m_List[v8].stat = (CMFCZoomKernel::XKernel *)operator new(nSize: 12 * (dScale - v7 + 1));
    j_3 = 0;
    lpFilterProc = this->m_List[v8].stat;
    v35 = 1;
    pStat = (CMFCZoomKernel::XKernel *)v7;
    if ( v7 > dScale )
      goto LABEL_27;
    v9 = originSrc + v7;
    dScale_4 = this->m_List[v8].stat;
    right = -v9;
    do
    {
      v19 = (correction_4a - (double)(int)pStat + v20) * v21;
      v10 = ((double (__cdecl *)(_DWORD, _DWORD))weightSum_4)(a1: LODWORD(v19), a2: HIDWORD(v19)) * v21;
      if ( 0.0 != v10 )
      {
        v35 = 0;
        v12 = v9;
        if ( v9 >= 0 )
        {
          if ( v9 >= widthSrc )
          {
            v12 = 2 * widthSrc - v9 - 1;
            j_3 = 1;
          }
          if ( j_3 == 0 )
            goto LABEL_21;
        }
        else
        {
          v12 = right;
          j_3 = 1;
        }
        v13 = 0;
        if ( bFirst != 0 )
        {
          v14 = lpFilterProc;
          while ( v14->pixel != v12 )
          {
            ++v13;
            ++v14;
            if ( v13 >= bFirst )
              goto LABEL_21;
          }
          lpFilterProc[v13].weight = lpFilterProc[v13].weight + v10;
          goto LABEL_22;
        }
LABEL_21:
        ++bFirst;
        dScale_4->weight = v10;
        dScale_4->pixel = v12;
        ++dScale_4;
        this->m_List[v8].count = bFirst;
LABEL_22:
        v15 = v10;
        v11 = 0.0;
        center_4 = v15 + center_4;
        goto LABEL_23;
      }
      v11 = 0.0;
      if ( v35 == 0 )
        break;
LABEL_23:
      pStat = (CMFCZoomKernel::XKernel *)((char *)pStat + 1);
      ++v9;
      --right;
    }
    while ( (int)pStat <= dScale );
    if ( center_4 != v11 )
    {
      v16 = 0;
      v17 = 0;
      do
      {
        p_weight = &this->m_List[v8].stat[v17].weight;
        ++v16;
        ++v17;
        *p_weight = *p_weight / center_4;
      }
      while ( v16 <= this->m_List[v8].count );
    }
LABEL_27:
    ++v32;
  }
  while ( v32 < this->m_Size );
}

//------------------------------------------------------------------------------
// Address: 0x103B9DD8
// Name: public: void CMFCScanliner::attach(unsigned char __near *,class CRect const __near &,unsigned int,unsigned int,unsigned char,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCScanliner::attach(
        CMFCScanliner *this,
        unsigned __int8 *data,
        const CRect *rect,
        int height,
        unsigned int pitch,
        unsigned __int8 channels,
        int invert)
{
  unsigned int top; // edi
  int v9; // edx
  int v10; // eax
  unsigned __int8 *v11; // edi
  unsigned __int8 *v12; // eax
  unsigned int point; // [esp+8h] [ebp-8h]

  CMFCScanliner::empty(this);
  top = rect->top;
  v9 = rect->right - rect->left;
  point = rect->left;
  v10 = pitch;
  if ( pitch == 0 )
    v10 = rect->right - rect->left;
  if ( height == 0 )
    height = rect->bottom;
  this->m_rows = rect->bottom - top;
  this->m_cols = v9 * channels;
  this->m_pitch = v10;
  this->m_offset = v10;
  if ( invert != 0 )
    this->m_offset = -v10;
  this->m_height = height;
  this->m_channels = channels;
  this->m_start_row = top;
  this->m_start_col = point;
  v11 = CMFCScanliner::_begin(this, data);
  this->m_line_begin = v11;
  v12 = CMFCScanliner::_end(this, data);
  this->m_line = v11;
  this->m_line_end = v12;
}

//------------------------------------------------------------------------------
// Address: 0x103B9E6A
// Name: public: void CMFCToolBarImages::EndDrawImage(struct tagAFXDrawState __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarImages::EndDrawImage(CMFCToolBarImages *this, tagAFXDrawState *ds)
{
  bool v3; // zf
  unsigned int m_clrTransparent; // eax
  CBitmap *m_pBmpOriginal; // eax
  void *v6; // eax
  HDC v7; // eax

  if ( this->m_bCreateMonoDC != 0 )
  {
    SelectObject(hdc: hDCMono, h: ds->hbmMonoOld);
    AfxDeleteObject(pObject: (void **)&ds->hbmMono);
  }
  SelectObject(hdc: hDCGlyphs, h: ds->hbmOldGlyphs);
  this->m_rectLastDraw.left = 0;
  this->m_rectLastDraw.top = 0;
  this->m_rectLastDraw.right = 0;
  v3 = this->m_nBitsPerPixel == 32;
  this->m_sizeImageDest.cx = 0;
  this->m_sizeImageDest.cy = 0;
  this->m_rectLastDraw.bottom = 0;
  if ( v3 )
    m_clrTransparent = -1;
  else
    m_clrTransparent = this->m_clrTransparent;
  if ( this->m_bStretch != 0 || m_clrTransparent != -1 )
  {
    m_pBmpOriginal = this->m_pBmpOriginal;
    if ( m_pBmpOriginal == nullptr )
      AfxThrowInvalidArgException();
    CDC::SelectGdiObject(hDC: this->m_dcMem.m_hDC, h: m_pBmpOriginal->m_hObject);
    this->m_pBmpOriginal = nullptr;
    v6 = CGdiObject::Detach(this: &this->m_bmpMem);
    DeleteObject(ho: v6);
    v7 = CDC::Detach(this: &this->m_dcMem);
    DeleteDC(hdc: v7);
  }
  this->m_bFadeInactive = 0;
  if ( CMFCToolBarImages::m_bMultiThreaded != 0 )
    LeaveCriticalSection(lpCriticalSection: &CMFCToolBarImages::m_CriticalSection.m_sect);
}

//------------------------------------------------------------------------------
// Address: 0x103B9F43
// Name: public: static void CMFCToolBarImages::FillDitheredRect(class CDC __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMFCToolBarImages::FillDitheredRect(CDC *pDC, const CRect *rect)
{
  FillRect(hDC: pDC->m_hDC, lprc: rect, hbr: (HBRUSH)afxGlobalData.brLight.m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x103B9F61
// Name: public: int CMFCToolBarImages::MapTo3dColors(int,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::MapTo3dColors(
        CMFCToolBarImages *this,
        int bUseRGBQUAD,
        unsigned int clrSrc,
        COLORREF clrDest)
{
  HDC CompatibleDC; // eax
  HDC v7; // eax
  COLORREF Pixel; // eax
  COLORREF v9; // edi
  COLORREF v10; // eax
  _BYTE pv[4]; // [esp+10h] [ebp-60h] BYREF
  int v12; // [esp+14h] [ebp-5Ch]
  int cy; // [esp+18h] [ebp-58h]
  __int16 v14; // [esp+22h] [ebp-4Eh]
  CDC v15; // [esp+28h] [ebp-48h] BYREF
  CDC v16; // [esp+38h] [ebp-38h] BYREF
  HGDIOBJ v17; // [esp+48h] [ebp-28h]
  HGDIOBJ ho; // [esp+4Ch] [ebp-24h]
  int v19; // [esp+50h] [ebp-20h]
  int v20; // [esp+54h] [ebp-1Ch]
  HGDIOBJ h; // [esp+58h] [ebp-18h]
  int x; // [esp+5Ch] [ebp-14h]
  int y; // [esp+60h] [ebp-10h]
  int v24; // [esp+6Ch] [ebp-4h]

  if ( this->m_hbmImageWell == nullptr || clrSrc != -1 && clrDest == -1 )
    return 0;
  CDC::CDC(this: &v16);
  v24 = 0;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  CDC::Attach(this: &v16, hDC: CompatibleDC);
  if ( GetObjectA(h: this->m_hbmImageWell, c: 24, pv) == 0
    || (this->m_hbmImageWell == nullptr ? (h = nullptr) : (h = SelectObject(hdc: v16.m_hDC, h: this->m_hbmImageWell)),
        h == nullptr) )
  {
LABEL_6:
    v24 = -1;
    CDC::~CDC(this: &v16);
    return 0;
  }
  v19 = v12;
  v20 = cy;
  ho = CreateCompatibleBitmap(hdc: v16.m_hDC, cx: v12, cy);
  if ( ho == nullptr )
  {
    SelectObject(hdc: v16.m_hDC, h);
    goto LABEL_6;
  }
  CDC::CDC(this: &v15);
  LOBYTE(v24) = 1;
  v7 = CreateCompatibleDC(hdc: v16.m_hDC);
  CDC::Attach(this: &v15, hDC: v7);
  v17 = SelectObject(hdc: v15.m_hDC, h: ho);
  if ( v17 == nullptr )
  {
    SelectObject(hdc: v16.m_hDC, h);
    DeleteObject(ho);
    LOBYTE(v24) = 0;
    CDC::~CDC(this: &v15);
    goto LABEL_6;
  }
  BitBlt(hdc: v15.m_hDC, x: 0, y: 0, cx: v19, cy: v20, hdcSrc: v16.m_hDC, x1: 0, y1: 0, rop: 0xCC0020u);
  for ( x = 0; x < v19; ++x )
  {
    for ( y = 0; y < v20; ++y )
    {
      Pixel = GetPixel(hdc: v15.m_hDC, x, y);
      v9 = Pixel;
      if ( clrSrc == -1 )
      {
        if ( v14 != 24 || CMFCToolBarImages::m_bDisableTrueColorAlpha != 0 )
          v10 = CMFCToolBarImages::MapToSysColor(color: Pixel, bUseRGBQUAD);
        else
          v10 = CMFCToolBarImages::MapToSysColorAlpha(color: Pixel);
        if ( v9 != v10 )
          SetPixel(hdc: v15.m_hDC, x, y, color: v10);
      }
      else if ( Pixel == clrSrc )
      {
        SetPixel(hdc: v15.m_hDC, x, y, color: clrDest);
      }
    }
  }
  SelectObject(hdc: v15.m_hDC, h: v17);
  SelectObject(hdc: v16.m_hDC, h);
  DeleteObject(ho: this->m_hbmImageWell);
  this->m_hbmImageWell = (HBITMAP__ *)ho;
  LOBYTE(v24) = 0;
  CDC::~CDC(this: &v15);
  v24 = -1;
  CDC::~CDC(this: &v16);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103BA148
// Name: protected: int CMFCToolBarImages::UpdateInternalImage(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::UpdateInternalImage(CMFCToolBarImages *this, int nIndex)
{
  int m_nBitsPerPixel; // eax
  void **p_m_hbmImageShadow; // edi
  HDC CompatibleDC; // eax
  void (__stdcall *v7)(HDC, HGDIOBJ); // edi
  HDC v8; // eax
  HBITMAP v9; // eax
  _DWORD *v10; // esi
  int v11; // esi
  unsigned int v12; // eax
  unsigned int clrBtnFace; // eax
  CMFCVisualManager *Instance; // eax
  int v15; // eax
  CDC *clrBtnShadow; // eax
  int i; // esi
  COLORREF Pixel; // eax
  CRect v19; // [esp-20h] [ebp-D8h]
  int m_nLightPercentage; // [esp-10h] [ebp-C8h]
  _BYTE pv[4]; // [esp+10h] [ebp-A8h] BYREF
  int v22; // [esp+14h] [ebp-A4h]
  int v23; // [esp+18h] [ebp-A0h]
  int v24; // [esp+28h] [ebp-90h]
  int v25; // [esp+2Ch] [ebp-8Ch]
  int v26; // [esp+30h] [ebp-88h]
  int v27; // [esp+34h] [ebp-84h]
  HGDIOBJ v28; // [esp+38h] [ebp-80h]
  void *ppvBits; // [esp+3Ch] [ebp-7Ch] BYREF
  CDC m_dc; // [esp+40h] [ebp-78h] BYREF
  CDrawingManager v31; // [esp+50h] [ebp-68h] BYREF
  CDC v32; // [esp+58h] [ebp-60h] BYREF
  unsigned int v33; // [esp+68h] [ebp-50h]
  int cy; // [esp+6Ch] [ebp-4Ch]
  HGDIOBJ h; // [esp+70h] [ebp-48h]
  int v36; // [esp+74h] [ebp-44h]
  unsigned int clrTransparent; // [esp+78h] [ebp-40h]
  BITMAPINFO pbmi; // [esp+7Ch] [ebp-3Ch] BYREF
  int v39; // [esp+B4h] [ebp-4h]

  if ( nIndex != 0 )
  {
    clrTransparent = (unsigned int)&this->m_hbmImageShadow;
    p_m_hbmImageShadow = (void **)&this->m_hbmImageShadow;
  }
  else
  {
    m_nBitsPerPixel = this->m_nBitsPerPixel;
    p_m_hbmImageShadow = (void **)&this->m_hbmImageLight;
    clrTransparent = (unsigned int)&this->m_hbmImageLight;
    if ( m_nBitsPerPixel > 4 && this->m_bAlwaysLight == 0 || m_nBitsPerPixel == 0 )
      return 0;
  }
  AfxDeleteObject(pObject: p_m_hbmImageShadow);
  *p_m_hbmImageShadow = nullptr;
  if ( this->m_hbmImageWell == nullptr || afxGlobalData.m_nBitsPerPixel <= 8 )
    return 1;
  CDC::CDC(this: &v32);
  v39 = 0;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  CDC::Attach(this: &v32, hDC: CompatibleDC);
  if ( GetObjectA(h: this->m_hbmImageWell, c: 24, pv) == 0 )
    goto LABEL_11;
  v7 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  v36 = v22;
  cy = v23;
  h = this->m_hbmImageWell != nullptr ? SelectObject(hdc: v32.m_hDC, h: this->m_hbmImageWell) : nullptr;
  if ( h == nullptr )
    goto LABEL_11;
  CDC::CDC(this: &m_dc);
  LOBYTE(v39) = 1;
  v8 = CreateCompatibleDC(hdc: v32.m_hDC);
  CDC::Attach(this: &m_dc, hDC: v8);
  pbmi.bmiHeader.biPlanes = 1;
  pbmi.bmiHeader.biWidth = v36;
  pbmi.bmiHeader.biHeight = cy;
  pbmi.bmiHeader.biSize = 40;
  pbmi.bmiHeader.biBitCount = 32;
  pbmi.bmiHeader.biCompression = 0;
  pbmi.bmiHeader.biSizeImage = v36 * cy;
  memset(&pbmi.bmiHeader.biXPelsPerMeter, 0, 16);
  ppvBits = nullptr;
  v9 = CreateDIBSection(hdc: m_dc.m_hDC, &pbmi, usage: 0, &ppvBits, hSection: nullptr, offset: 0);
  *(_DWORD *)clrTransparent = v9;
  if ( v9 == nullptr )
  {
    SelectObject(hdc: v32.m_hDC, h);
    LOBYTE(v39) = 0;
    CDC::~CDC(this: &m_dc);
LABEL_11:
    v39 = -1;
    CDC::~CDC(this: &v32);
    return 0;
  }
  v28 = SelectObject(hdc: m_dc.m_hDC, h: v9);
  if ( v28 != nullptr )
  {
    if ( this->m_nBitsPerPixel == 32 )
      clrTransparent = -1;
    else
      clrTransparent = this->m_clrTransparent;
    BitBlt(hdc: m_dc.m_hDC, x: 0, y: 0, cx: v36, cy, hdcSrc: v32.m_hDC, x1: 0, y1: 0, rop: 0xCC0020u);
    if ( nIndex != 0 )
    {
      clrBtnFace = clrTransparent;
      if ( clrTransparent == -1 )
        clrBtnFace = afxGlobalData.clrBtnFace;
      v33 = clrBtnFace;
      Instance = CMFCVisualManager::GetInstance();
      v15 = Instance->GetToolbarHighlightColor(this: Instance);
      if ( afxGlobalData.m_nBitsPerPixel > 8 )
        clrBtnShadow = (CDC *)CDrawingManager::PixelAlpha(srcPixel: v15, percent: 67);
      else
        clrBtnShadow = (CDC *)afxGlobalData.clrBtnShadow;
      v31.m_dc = clrBtnShadow;
      for ( clrTransparent = 0; (int)clrTransparent < v36; ++clrTransparent )
      {
        for ( i = 0; i < cy; ++i )
        {
          Pixel = GetPixel(hdc: m_dc.m_hDC, x: clrTransparent, y: i);
          if ( Pixel != v33 )
            SetPixel(hdc: m_dc.m_hDC, x: clrTransparent, y: i, color: (COLORREF)v31.m_dc);
        }
      }
      SelectObject(hdc: m_dc.m_hDC, h: v28);
    }
    else
    {
      CDrawingManager::CDrawingManager(this: &v31, &m_dc);
      v12 = clrTransparent;
      LOBYTE(v39) = 2;
      if ( clrTransparent == -1 )
        v12 = afxGlobalData.clrBtnFace;
      m_nLightPercentage = this->m_nLightPercentage;
      v26 = v36;
      v27 = cy;
      v24 = 0;
      v25 = 0;
      *(_QWORD *)&v19.left = 0;
      *(_QWORD *)&v19.right = __PAIR64__(cy, v36);
      CDrawingManager::HighlightRect(
        this: &v31,
        rect: v19,
        nPercentage: m_nLightPercentage,
        clrTransparent: v12,
        nTolerance: 0,
        clrBlend: 0xFFFFFFFF);
      LOBYTE(v39) = 1;
      CDrawingManager::~CDrawingManager(this: &v31);
      v7 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
      SelectObject(hdc: m_dc.m_hDC, h: v28);
    }
    v7(hdc: v32.m_hDC, h);
    v11 = 1;
  }
  else
  {
    SelectObject(hdc: v32.m_hDC, h);
    v10 = (_DWORD *)clrTransparent;
    DeleteObject(ho: *(HGDIOBJ *)clrTransparent);
    *v10 = 0;
    v11 = 0;
  }
  LOBYTE(v39) = 0;
  CDC::~CDC(this: &m_dc);
  v39 = -1;
  CDC::~CDC(this: &v32);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x103BA428
// Name: public: int CMFCToolBarImages::GrayImages(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::GrayImages(CMFCToolBarImages *this, int nGrayImageLuminancePercentage)
{
  int result; // eax
  int v4; // esi
  HDC CompatibleDC; // eax
  void (__stdcall *v6)(HDC, HGDIOBJ); // edi
  HDC v7; // eax
  HBITMAP v8; // eax
  CDC_vtbl *m_nGrayImageLuminancePercentage; // eax
  unsigned __int8 *v10; // esi
  unsigned int v11; // eax
  CDC_vtbl *v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  unsigned int m_clrTransparent; // eax
  CRect v17; // [esp+14h] [ebp-134h]
  double v18; // [esp+18h] [ebp-130h]
  double v19; // [esp+20h] [ebp-128h]
  double v20; // [esp+28h] [ebp-120h]
  CRect v21; // [esp+2Ch] [ebp-11Ch]
  long double v22; // [esp+40h] [ebp-108h] BYREF
  long double percentR; // [esp+48h] [ebp-100h]
  double percentB; // [esp+58h] [ebp-F0h] BYREF
  int v25; // [esp+60h] [ebp-E8h]
  int v26; // [esp+64h] [ebp-E4h]
  unsigned __int64 S; // [esp+68h] [ebp-E0h] BYREF
  HGDIOBJ pv; // [esp+70h] [ebp-D8h]
  void *v29; // [esp+74h] [ebp-D4h] BYREF
  CDrawingManager v30; // [esp+78h] [ebp-D0h] BYREF
  CDC v31; // [esp+80h] [ebp-C8h] BYREF
  CDC v32; // [esp+90h] [ebp-B8h] BYREF
  double v33; // [esp+A0h] [ebp-A8h]
  HBITMAP__ *L; // [esp+A8h] [ebp-A0h]
  HGDIOBJ L_4; // [esp+ACh] [ebp-9Ch]
  CDC m_dc; // [esp+B0h] [ebp-98h] BYREF
  CDC v37; // [esp+C0h] [ebp-88h]
  BITMAPINFO v38; // [esp+10Ch] [ebp-3Ch] BYREF
  int v39; // [esp+144h] [ebp-4h]

  result = 1;
  v4 = 0;
  this->m_bIsGray = 1;
  this->m_nGrayImageLuminancePercentage = nGrayImageLuminancePercentage;
  if ( this->m_hbmImageWell != nullptr && afxGlobalData.m_nBitsPerPixel > 8 )
  {
    CDC::CDC(this: &v32);
    v39 = 0;
    CompatibleDC = CreateCompatibleDC(hdc: nullptr);
    CDC::Attach(this: &v32, hDC: CompatibleDC);
    if ( GetObjectA(h: this->m_hbmImageWell, c: 24, pv: &v22) == 0 )
      goto LABEL_4;
    v6 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
    m_dc.m_hDC = (HDC__ *)HIDWORD(v22);
    HIDWORD(v33) = LODWORD(percentR);
    L_4 = this->m_hbmImageWell != nullptr ? SelectObject(hdc: v32.m_hDC, h: this->m_hbmImageWell) : nullptr;
    if ( L_4 == nullptr )
      goto LABEL_4;
    CDC::CDC(this: &v31);
    LOBYTE(v39) = 1;
    v7 = CreateCompatibleDC(hdc: v32.m_hDC);
    CDC::Attach(this: &v31, hDC: v7);
    v38.bmiHeader.biPlanes = 1;
    v38.bmiHeader.biWidth = (int)m_dc.m_hDC;
    v38.bmiHeader.biHeight = HIDWORD(v33);
    v38.bmiHeader.biSize = 40;
    v38.bmiHeader.biBitCount = 32;
    v38.bmiHeader.biCompression = 0;
    v38.bmiHeader.biSizeImage = (int)m_dc.m_hDC * HIDWORD(v33);
    memset(&v38.bmiHeader.biXPelsPerMeter, 0, 16);
    v29 = nullptr;
    v8 = CreateDIBSection(hdc: v31.m_hDC, pbmi: &v38, usage: 0, ppvBits: &v29, hSection: nullptr, offset: 0);
    L = v8;
    if ( v8 == nullptr )
    {
      SelectObject(hdc: v32.m_hDC, h: L_4);
LABEL_12:
      LOBYTE(v39) = 0;
      CDC::~CDC(this: &v31);
LABEL_4:
      v39 = -1;
      CDC::~CDC(this: &v32);
      return 0;
    }
    pv = SelectObject(hdc: v31.m_hDC, h: v8);
    if ( pv == nullptr )
    {
      SelectObject(hdc: v32.m_hDC, h: L_4);
      DeleteObject(ho: L);
      goto LABEL_12;
    }
    BitBlt(
      hdc: v31.m_hDC,
      x: 0,
      y: 0,
      cx: (int)m_dc.m_hDC,
      cy: SHIDWORD(v33),
      hdcSrc: v32.m_hDC,
      x1: 0,
      y1: 0,
      rop: 0xCC0020u);
    m_nGrayImageLuminancePercentage = (CDC_vtbl *)this->m_nGrayImageLuminancePercentage;
    m_dc.__vftable = (CDC_vtbl *)130;
    if ( (int)m_nGrayImageLuminancePercentage > 0 )
      m_dc.__vftable = m_nGrayImageLuminancePercentage;
    if ( this->m_nBitsPerPixel == 32 )
    {
      if ( GetObjectA(h: L, c: 84, pv: &m_dc.m_hAttribDC) == 0 || HIWORD(v37.m_hAttribDC) != 32 )
        goto LABEL_12;
      if ( v37.m_bPrinting == 0 )
      {
LABEL_21:
        LOBYTE(v39) = 0;
        CDC::~CDC(this: &v31);
        v39 = -1;
        CDC::~CDC(this: &v32);
        return v4;
      }
      m_dc.m_hDC = nullptr;
      if ( m_dc.m_bPrinting * (int)v37.__vftable > 0 )
      {
        v10 = (unsigned __int8 *)(v37.m_bPrinting + 1);
        v33 = (double)(int)m_dc.__vftable * 0.01;
        do
        {
          CDrawingManager::RGBtoHSL(
            rgb: v10[1] | ((*v10 | (*(v10 - 1) << 8)) << 8),
            H: &percentB,
            (long double *)&S,
            L: (long double *)&v30);
          v20 = v33;
          v19 = v33;
          v18 = v33;
          v11 = CDrawingManager::HLStoRGB_ONE(H: percentB, L: *(double *)&v30, S: 0.0);
          v12 = (CDC_vtbl *)CDrawingManager::PixelAlpha(srcPixel: v11, percentR: v18, percentG: v19, percentB: v20);
          v13 = v10[2];
          m_dc.__vftable = v12;
          LOBYTE(v12) = v13 * (unsigned __int8)v12 / 255;
          v14 = v10[2];
          v10[1] = (unsigned __int8)v12;
          LOBYTE(v12) = v14 * BYTE1(m_dc.__vftable) / 255;
          v15 = v10[2];
          *v10 = (unsigned __int8)v12;
          ++m_dc.m_hDC;
          v10 += 4;
          *(v10 - 5) = v15 * BYTE2(m_dc.__vftable) / 255;
        }
        while ( (int)m_dc.m_hDC < m_dc.m_bPrinting * (int)v37.__vftable );
      }
    }
    else
    {
      CDrawingManager::CDrawingManager(this: &v30, m_dc: &v31);
      m_clrTransparent = this->m_clrTransparent;
      LOBYTE(v39) = 2;
      if ( m_clrTransparent == -1 )
        m_clrTransparent = afxGlobalData.clrBtnFace;
      v21.left = -1;
      S = __PAIR64__(HIDWORD(v33), (unsigned int)m_dc.m_hDC);
      v25 = 0;
      v26 = 0;
      *(_QWORD *)&v17.left = 0;
      *(_QWORD *)&v17.right = __PAIR64__(HIDWORD(v33), (unsigned int)m_dc.m_hDC);
      CDrawingManager::GrayRect(
        this: &v30,
        rect: v17,
        nPercentage: (int)m_dc.__vftable,
        clrTransparent: m_clrTransparent,
        clrDisabled: v21);
      LOBYTE(v39) = 1;
      CDrawingManager::~CDrawingManager(this: &v30);
      v6 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
    }
    v6(hdc: v31.m_hDC, h: pv);
    v6(hdc: v32.m_hDC, h: L_4);
    DeleteObject(ho: this->m_hbmImageWell);
    this->m_hbmImageWell = L;
    v4 = 1;
    goto LABEL_21;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BA84C
// Name: public: static int CMFCToolBarImages::MirrorBitmap(struct HBITMAP__ __near * __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCToolBarImages::MirrorBitmap(HANDLE *hbmp, int cxImage)
{
  HANDLE v2; // eax
  int v3; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // edi
  int *v8; // edx
  int *v9; // ecx
  int v10; // esi
  HDC CompatibleDC; // eax
  int v12; // esi
  int v13; // ebx
  int v14; // ebx
  COLORREF Pixel; // eax
  bool v16; // zf
  _BYTE pv[4]; // [esp+10h] [ebp-B4h] BYREF
  int v18; // [esp+14h] [ebp-B0h]
  int v19; // [esp+18h] [ebp-ACh]
  __int16 v20; // [esp+22h] [ebp-A2h]
  COLORREF color; // [esp+28h] [ebp-9Ch]
  CDC v22; // [esp+2Ch] [ebp-98h] BYREF
  int j; // [esp+3Ch] [ebp-88h]
  int v24; // [esp+40h] [ebp-84h]
  int v25; // [esp+44h] [ebp-80h]
  int v26; // [esp+48h] [ebp-7Ch]
  int i; // [esp+4Ch] [ebp-78h]
  HGDIOBJ h; // [esp+50h] [ebp-74h]
  int v29; // [esp+54h] [ebp-70h]
  int x; // [esp+58h] [ebp-6Ch]
  int y; // [esp+5Ch] [ebp-68h]
  _BYTE v32[18]; // [esp+60h] [ebp-64h] BYREF
  __int16 v33; // [esp+72h] [ebp-52h]
  int v34; // [esp+74h] [ebp-50h]
  int v35; // [esp+C0h] [ebp-4h]

  v2 = *hbmp;
  v3 = cxImage;
  v24 = cxImage;
  if ( v2 == nullptr )
    return 1;
  if ( GetObjectA(h: v2, c: 24, pv) == 0 )
    return 0;
  v26 = v18;
  v25 = v19;
  y = v18 / cxImage;
  if ( v20 == 32 )
  {
    if ( GetObjectA(h: *hbmp, c: 84, pv: v32) != 0 && v33 == 32 && v34 != 0 )
    {
      if ( y > 0 )
      {
        x = v34;
        v5 = 4 * cxImage;
        do
        {
          if ( v25 > 0 )
          {
            v6 = v3;
            v7 = x;
            v29 = v6 / 2;
            for ( i = v25; i != 0; --i )
            {
              v8 = (int *)v7;
              v9 = (int *)(v7 + v5 - 4);
              if ( v29 > 0 )
              {
                for ( h = (HGDIOBJ)v29; h != nullptr; h = (char *)h - 1 )
                {
                  v10 = *v8;
                  *v8 = *v9;
                  *v9 = v10;
                  ++v8;
                  --v9;
                }
              }
              v7 += 4 * v26;
            }
            v3 = v24;
          }
          x += v5;
          --y;
        }
        while ( y != 0 );
      }
      return 1;
    }
    return 0;
  }
  CDC::CDC(this: &v22);
  v35 = 0;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  CDC::Attach(this: &v22, hDC: CompatibleDC);
  if ( *hbmp != nullptr )
    h = SelectObject(hdc: v22.m_hDC, h: *hbmp);
  else
    h = nullptr;
  if ( h != nullptr )
  {
    if ( y > 0 )
    {
      v13 = 0;
      i = 0;
      v26 = y;
      do
      {
        y = 0;
        if ( v25 > 0 )
        {
          v29 = v24 / 2;
          do
          {
            x = v13;
            v14 = v13 + v24 - 1;
            if ( v29 > 0 )
            {
              for ( j = v29; j != 0; --j )
              {
                color = GetPixel(hdc: v22.m_hDC, x, y);
                Pixel = GetPixel(hdc: v22.m_hDC, x: v14, y);
                SetPixel(hdc: v22.m_hDC, x, y, color: Pixel);
                SetPixel(hdc: v22.m_hDC, x: v14, y, color);
                ++x;
                --v14;
              }
            }
            ++y;
            v13 = i;
          }
          while ( y < v25 );
        }
        v13 += v24;
        v16 = v26-- == 1;
        i = v13;
      }
      while ( !v16 );
    }
    SelectObject(hdc: v22.m_hDC, h);
    v12 = 1;
  }
  else
  {
    v12 = 0;
  }
  v35 = -1;
  CDC::~CDC(this: &v22);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x103BAA7A
// Name: public: int CMFCToolBarImages::Mirror(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::Mirror(CMFCToolBarImages *this)
{
  int result; // eax

  result = CMFCToolBarImages::MirrorBitmap(hbmp: (HANDLE *)&this->m_hbmImageWell, cxImage: this->m_sizeImage.cx);
  if ( result != 0 )
  {
    if ( this->m_hbmImageLight != nullptr )
      CMFCToolBarImages::MirrorBitmap(hbmp: (HANDLE *)&this->m_hbmImageLight, cxImage: this->m_sizeImage.cx);
    if ( this->m_hbmImageShadow != nullptr )
      CMFCToolBarImages::MirrorBitmap(hbmp: (HANDLE *)&this->m_hbmImageShadow, cxImage: this->m_sizeImage.cx);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BAAC1
// Name: public: static int CMFCToolBarImages::MirrorBitmapVert(struct HBITMAP__ __near * __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCToolBarImages::MirrorBitmapVert(HANDLE *hbmp, int cyImage)
{
  HANDLE v2; // eax
  int v3; // esi
  unsigned int v5; // ebx
  unsigned __int8 *v6; // eax
  int v7; // edi
  bool v8; // zf
  HDC CompatibleDC; // eax
  int v10; // esi
  int k; // esi
  COLORREF Pixel; // eax
  _BYTE pv[4]; // [esp+10h] [ebp-B4h] BYREF
  unsigned __int8 *v14; // [esp+14h] [ebp-B0h]
  int v15; // [esp+18h] [ebp-ACh]
  unsigned __int16 v16; // [esp+22h] [ebp-A2h]
  COLORREF color; // [esp+28h] [ebp-9Ch]
  CDC v18; // [esp+2Ch] [ebp-98h] BYREF
  int v19; // [esp+3Ch] [ebp-88h]
  unsigned __int8 *i; // [esp+40h] [ebp-84h]
  unsigned __int8 *j; // [esp+44h] [ebp-80h]
  unsigned __int8 *v22; // [esp+48h] [ebp-7Ch]
  HGDIOBJ h; // [esp+4Ch] [ebp-78h]
  int v24; // [esp+50h] [ebp-74h]
  unsigned __int8 *dst; // [esp+54h] [ebp-70h]
  unsigned __int8 *src; // [esp+58h] [ebp-6Ch]
  unsigned __int8 *v27; // [esp+5Ch] [ebp-68h]
  _BYTE v28[18]; // [esp+60h] [ebp-64h] BYREF
  unsigned __int16 v29; // [esp+72h] [ebp-52h]
  unsigned __int8 *v30; // [esp+74h] [ebp-50h]
  int v31; // [esp+C0h] [ebp-4h]

  v2 = *hbmp;
  v3 = cyImage;
  v19 = cyImage;
  if ( v2 == nullptr )
    return 1;
  if ( GetObjectA(h: v2, c: 24, pv) == 0 )
    return 0;
  dst = v14;
  v27 = (unsigned __int8 *)(v15 / cyImage);
  if ( v16 >= 0x10u )
  {
    if ( GetObjectA(h: *hbmp, c: 84, pv: v28) != 0 && v29 == v16 && v30 != nullptr )
    {
      i = v30;
      v5 = (int)dst * v29 / 8;
      if ( (v5 & 3) != 0 )
        v5 = 4 * (v5 >> 2) + 4;
      dst = (unsigned __int8 *)operator new(nSize: v5);
      if ( (int)v27 > 0 )
      {
        v6 = i;
        v24 = v19 / 2;
        v7 = v5 * v19;
        v22 = i;
        j = v27;
        do
        {
          src = v6;
          v27 = &v6[v5 * (cyImage - 1)];
          if ( v24 > 0 )
          {
            for ( h = (HGDIOBJ)v24; h != nullptr; h = (char *)h - 1 )
            {
              memcpy(dst, src, count: v5);
              memcpy(dst: src, src: v27, count: v5);
              memcpy(dst: v27, src: dst, count: v5);
              src += v5;
              v27 -= v5;
            }
          }
          v6 = &v22[v7];
          v8 = j-- == (unsigned __int8 *)1;
          v22 += v7;
        }
        while ( !v8 );
      }
      operator delete(p: dst);
      return 1;
    }
    return 0;
  }
  CDC::CDC(this: &v18);
  v31 = 0;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  CDC::Attach(this: &v18, hDC: CompatibleDC);
  if ( *hbmp != nullptr )
    h = SelectObject(hdc: v18.m_hDC, h: *hbmp);
  else
    h = nullptr;
  if ( h != nullptr )
  {
    if ( (int)v27 > 0 )
    {
      v24 = cyImage / 2;
      v22 = nullptr;
      for ( i = v27; i != nullptr; --i )
      {
        v27 = v22;
        src = &v22[v3 - 1];
        if ( v24 > 0 )
        {
          for ( j = (unsigned __int8 *)v24; j != nullptr; --j )
          {
            for ( k = 0; k < (int)dst; ++k )
            {
              color = GetPixel(hdc: v18.m_hDC, x: k, y: (int)v27);
              Pixel = GetPixel(hdc: v18.m_hDC, x: k, y: (int)src);
              SetPixel(hdc: v18.m_hDC, x: k, y: (int)v27, color: Pixel);
              SetPixel(hdc: v18.m_hDC, x: k, y: (int)src, color);
            }
            ++v27;
            --src;
          }
          v3 = v19;
        }
        v22 += v3;
      }
    }
    SelectObject(hdc: v18.m_hDC, h);
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  v31 = -1;
  CDC::~CDC(this: &v18);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x103BAD22
// Name: public: int CMFCToolBarImages::MirrorVert(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::MirrorVert(CMFCToolBarImages *this)
{
  int result; // eax

  result = CMFCToolBarImages::MirrorBitmapVert(hbmp: (HANDLE *)&this->m_hbmImageWell, cyImage: this->m_sizeImage.cy);
  if ( result != 0 )
  {
    if ( this->m_hbmImageLight != nullptr )
      CMFCToolBarImages::MirrorBitmapVert(hbmp: (HANDLE *)&this->m_hbmImageLight, cyImage: this->m_sizeImage.cy);
    if ( this->m_hbmImageShadow != nullptr )
      CMFCToolBarImages::MirrorBitmapVert(hbmp: (HANDLE *)&this->m_hbmImageShadow, cyImage: this->m_sizeImage.cy);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BAD69
// Name: public: void CMFCToolBarImages::AdaptColors(unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarImages::AdaptColors(CMFCToolBarImages *this, unsigned int clrBase, unsigned int clrTone)
{
  bool v4; // zf
  int v5; // edi
  unsigned __int8 *i; // esi
  long double v7; // st7
  long double v8; // st6
  long double v9; // st5
  double v10; // st7
  long double v11; // rt0
  long double v12; // st6
  long double v13; // st5
  long double v14; // rt1
  long double v15; // st4
  long double v16; // st3
  long double v17; // st6
  long double v18; // rt2
  long double v19; // st4
  double v20; // st7
  double v21; // st5
  long double v22; // rtt
  int v23; // eax
  HDC CompatibleDC; // eax
  HDC v25; // eax
  HDC__ *m_clrTransparent; // eax
  HDC__ *Pixel; // eax
  long double v28; // st7
  long double v29; // st6
  long double v30; // st5
  double v31; // st7
  long double v32; // rt1
  long double v33; // st6
  long double v34; // st5
  long double v35; // rt2
  long double v36; // st4
  long double v37; // st3
  long double v38; // st6
  long double v39; // rtt
  long double v40; // st4
  double v41; // st7
  double v42; // st5
  long double v43; // rt0
  COLORREF v44; // eax
  HBITMAP__ **p_m_hbmImageLight; // edi
  void **p_m_hbmImageShadow; // esi
  HGDIOBJ v47[6]; // [esp+10h] [ebp-12Ch] BYREF
  long double v48; // [esp+28h] [ebp-114h] BYREF
  long double cy; // [esp+30h] [ebp-10Ch] BYREF
  long double v50; // [esp+38h] [ebp-104h] BYREF
  long double H; // [esp+40h] [ebp-FCh] BYREF
  long double v52; // [esp+48h] [ebp-F4h] BYREF
  long double v53; // [esp+50h] [ebp-ECh] BYREF
  long double L; // [esp+58h] [ebp-E4h] BYREF
  long double S; // [esp+60h] [ebp-DCh]
  double v56; // [esp+68h] [ebp-D4h] BYREF
  long double v57; // [esp+70h] [ebp-CCh]
  long double v58; // [esp+78h] [ebp-C4h]
  double v59; // [esp+80h] [ebp-BCh] BYREF
  long double v60; // [esp+88h] [ebp-B4h] BYREF
  CDC v61; // [esp+90h] [ebp-ACh] BYREF
  HGDIOBJ v62[2]; // [esp+A0h] [ebp-9Ch] BYREF
  CDC v63; // [esp+A8h] [ebp-94h] BYREF
  HGDIOBJ v64[2]; // [esp+C0h] [ebp-7Ch]
  CDC v65; // [esp+C8h] [ebp-74h]
  HGDIOBJ ho; // [esp+D8h] [ebp-64h] BYREF
  int v67; // [esp+DCh] [ebp-60h]
  int v68; // [esp+E0h] [ebp-5Ch]
  HGDIOBJ h; // [esp+E8h] [ebp-54h]
  int x; // [esp+ECh] [ebp-50h]
  int v71; // [esp+138h] [ebp-4h]

  CDrawingManager::RGBtoHSL(rgb: clrBase, H: &v48, S: &v52, L: &H);
  CDrawingManager::RGBtoHSL(rgb: clrTone, H: &v59, S: &cy, L: &v53);
  v4 = this->m_nBitsPerPixel == 32;
  S = v59 - v48;
  v58 = v53 - H;
  v57 = cy - v52;
  if ( !v4 )
  {
    CDC::CDC(this: (CDC *)&v63.m_hAttribDC);
    v71 = 0;
    CompatibleDC = CreateCompatibleDC(hdc: nullptr);
    CDC::Attach(this: (CDC *)&v63.m_hAttribDC, hDC: CompatibleDC);
    if ( GetObjectA(h: this->m_hbmImageWell, c: 24, pv: v47) == 0 )
      goto LABEL_71;
    v65.m_hAttribDC = this->m_hbmImageWell != nullptr
                    ? (HDC__ *)SelectObject(hdc: (HDC)v63.m_bPrinting, h: this->m_hbmImageWell)
                    : nullptr;
    if ( v65.m_hAttribDC == nullptr )
      goto LABEL_71;
    v64[1] = v47[1];
    v65.__vftable = (CDC_vtbl *)v47[2];
    v64[0] = CreateCompatibleBitmap(hdc: (HDC)v63.m_bPrinting, cx: (int)v47[1], cy: (int)v47[2]);
    if ( v64[0] == nullptr )
    {
      SelectObject(hdc: (HDC)v63.m_bPrinting, h: v65.m_hAttribDC);
LABEL_71:
      v71 = -1;
      CDC::~CDC(this: (CDC *)&v63.m_hAttribDC);
      return;
    }
    CDC::CDC(this: &v61);
    LOBYTE(v71) = 1;
    v25 = CreateCompatibleDC(hdc: (HDC)v63.m_bPrinting);
    CDC::Attach(this: &v61, hDC: v25);
    v62[1] = SelectObject(hdc: v61.m_hDC, h: v64[0]);
    if ( v62[1] == nullptr )
    {
      SelectObject(hdc: (HDC)v63.m_bPrinting, h: v65.m_hAttribDC);
      DeleteObject(ho: v64[0]);
LABEL_70:
      LOBYTE(v71) = 0;
      CDC::~CDC(this: &v61);
      goto LABEL_71;
    }
    BitBlt(
      hdc: v61.m_hDC,
      x: 0,
      y: 0,
      cx: (int)v64[1],
      cy: (int)v65.__vftable,
      hdcSrc: (HDC)v63.m_bPrinting,
      x1: 0,
      y1: 0,
      rop: 0xCC0020u);
    m_clrTransparent = (HDC__ *)this->m_clrTransparent;
    if ( m_clrTransparent == (HDC__ *)-1 )
      m_clrTransparent = (HDC__ *)afxGlobalData.clrBtnFace;
    v63.m_hDC = m_clrTransparent;
    v65.m_bPrinting = 0;
    if ( (int)v64[1] <= 0 )
    {
LABEL_69:
      SelectObject(hdc: v61.m_hDC, h: v62[1]);
      SelectObject(hdc: (HDC)v63.m_bPrinting, h: v65.m_hAttribDC);
      DeleteObject(ho: this->m_hbmImageWell);
      p_m_hbmImageLight = &this->m_hbmImageLight;
      this->m_hbmImageWell = (HBITMAP__ *)v64[0];
      AfxDeleteObject(pObject: (void **)&this->m_hbmImageLight);
      p_m_hbmImageShadow = (void **)&this->m_hbmImageShadow;
      *p_m_hbmImageLight = nullptr;
      AfxDeleteObject(pObject: p_m_hbmImageShadow);
      *p_m_hbmImageShadow = nullptr;
      goto LABEL_70;
    }
    while ( 1 )
    {
      v65.m_hDC = nullptr;
      if ( (int)v65.__vftable > 0 )
        break;
LABEL_68:
      if ( ++v65.m_bPrinting >= (int)v64[1] )
        goto LABEL_69;
    }
    while ( 1 )
    {
      Pixel = (HDC__ *)GetPixel(hdc: v61.m_hDC, x: v65.m_bPrinting, y: (int)v65.m_hDC);
      HIDWORD(v60) = Pixel;
      if ( Pixel != v63.m_hDC )
        break;
LABEL_67:
      if ( (int)++v65.m_hDC >= (int)v65.__vftable )
        goto LABEL_68;
    }
    CDrawingManager::RGBtoHSL(rgb: (unsigned int)Pixel, H: &L, S: &v50, L: &v56);
    v28 = L + S;
    v29 = 1.0;
    if ( L + S > 1.0 )
    {
      v30 = 0.0;
    }
    else
    {
      v30 = 0.0;
      if ( v28 < 0.0 )
      {
        v31 = 0.0;
LABEL_52:
        v36 = v50 + v57;
        if ( v50 + v57 > v29 || v36 >= v31 )
        {
          if ( v36 > v29 )
            v36 = v29;
        }
        else
        {
          v36 = v31;
        }
        v37 = v56 + v58;
        if ( v56 + v58 > v29 || v37 >= v31 )
        {
          v31 = v37;
          v39 = v36;
          v40 = v29;
          v38 = v39;
          if ( v40 < v37 )
            v31 = v40;
        }
        else
        {
          v38 = v36;
        }
        if ( v59 <= 0.5 )
        {
          v43 = v30;
          v42 = v31;
          v41 = v43;
        }
        else
        {
          v41 = v30;
          v42 = v56;
        }
        v44 = CDrawingManager::HLStoRGB_ONE(H: v41, L: v42, S: v38);
        if ( HIDWORD(v60) != v44 )
          SetPixel(hdc: v61.m_hDC, x: v65.m_bPrinting, y: (int)v65.m_hDC, color: v44);
        goto LABEL_67;
      }
    }
    v32 = v30;
    v30 = 1.0;
    v33 = v32;
    if ( v28 <= 1.0 )
    {
      v34 = v33;
      v29 = 1.0;
      v35 = v34;
      v30 = v28;
      v31 = v35;
    }
    else
    {
      v31 = v33;
      v29 = 1.0;
    }
    goto LABEL_52;
  }
  if ( GetObjectA(h: this->m_hbmImageWell, c: 84, pv: &ho) != 0 && HIWORD(h) == 32 && x != 0 )
  {
    v5 = 0;
    if ( v67 * v68 > 0 )
    {
      for ( i = (unsigned __int8 *)(x + 2); i[1] == 0; i += 4 )
      {
LABEL_29:
        if ( ++v5 >= v67 * v68 )
          return;
      }
      CDrawingManager::RGBtoHSL(
        rgb: *i | ((*(i - 1) | (*(i - 2) << 8)) << 8),
        H: &v60,
        S: (long double *)&v63,
        L: (long double *)v62);
      v7 = v60 + S;
      v8 = 1.0;
      if ( v60 + S > 1.0 )
      {
        v9 = 0.0;
      }
      else
      {
        v9 = 0.0;
        if ( v7 < 0.0 )
        {
          v10 = 0.0;
LABEL_15:
          v15 = *(double *)&v63.__vftable + v57;
          if ( *(double *)&v63.__vftable + v57 > v8 || v15 >= v10 )
          {
            if ( v15 > v8 )
              v15 = v8;
          }
          else
          {
            v15 = v10;
          }
          v16 = *(double *)v62 + v58;
          if ( *(double *)v62 + v58 > v8 || v16 >= v10 )
          {
            v10 = v16;
            v18 = v15;
            v19 = v8;
            v17 = v18;
            if ( v19 < v16 )
              v10 = v19;
          }
          else
          {
            v17 = v15;
          }
          if ( v59 <= 0.5 )
          {
            v22 = v9;
            v21 = v10;
            v20 = v22;
          }
          else
          {
            v20 = v9;
            v21 = *(double *)v62;
          }
          v23 = CDrawingManager::HLStoRGB_ONE(H: v20, L: v21, S: v17);
          *i = v23;
          *(i - 1) = BYTE1(v23);
          *(i - 2) = BYTE2(v23);
          goto LABEL_29;
        }
      }
      v11 = v9;
      v9 = 1.0;
      v12 = v11;
      if ( v7 <= 1.0 )
      {
        v13 = v12;
        v8 = 1.0;
        v14 = v13;
        v9 = v7;
        v10 = v14;
      }
      else
      {
        v10 = v12;
        v8 = 1.0;
      }
      goto LABEL_15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BB291
// Name: public: void CMFCToolBarImages::SetSingleImage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarImages::SetSingleImage(CMFCToolBarImages *this)
{
  HBITMAP__ *m_hbmImageWell; // eax
  tagBITMAP bmp; // [esp+4h] [ebp-18h] BYREF

  m_hbmImageWell = this->m_hbmImageWell;
  if ( m_hbmImageWell != nullptr && GetObjectA(h: m_hbmImageWell, c: 24, pv: &bmp) != 0 )
  {
    this->m_sizeImage.cx = bmp.bmWidth;
    this->m_sizeImage.cy = bmp.bmHeight;
    this->m_iCount = 1;
    CMFCToolBarImages::UpdateInternalImage(this, nIndex: 0);
    CMFCToolBarImages::UpdateInternalImage(this, nIndex: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BB2DF
// Name: public: CMFCScanlinerBitmap::~CMFCScanlinerBitmap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMFCScanlinerBitmap::~CMFCScanlinerBitmap(CMFCScanlinerBitmap *this)
{
  CMFCScanliner::empty(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BB32C
// Name: public: void CMFCScanliner::attach(unsigned char __near *,class CSize const __near &,unsigned int,unsigned int,unsigned char,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCScanliner::attach(
        CMFCScanliner *this,
        unsigned __int8 *data,
        const CSize *size,
        unsigned int height,
        unsigned int pitch,
        unsigned __int8 channels,
        int invert)
{
  int cx; // edx
  int cy; // eax
  CRect rect; // [esp+0h] [ebp-10h] BYREF

  cx = size->cx;
  cy = size->cy;
  rect.left = 0;
  rect.top = 0;
  rect.bottom = cy;
  rect.right = cx;
  CMFCScanliner::attach(this, data, &rect, height, pitch, channels, invert);
}

//------------------------------------------------------------------------------
// Address: 0x103BB366
// Name: public: void CMFCScanlinerBitmap::attach(struct HBITMAP__ __near *,class CPoint const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCScanlinerBitmap::attach(CMFCScanlinerBitmap *this, HBITMAP__ *bitmap, const CPoint *ptBegin)
{
  unsigned int v3; // eax
  int bmWidth; // edi
  unsigned int v5; // esi
  int y; // ecx
  signed int v7; // edi
  tagBITMAP bmp; // [esp+4h] [ebp-48h] BYREF
  CSize size; // [esp+1Ch] [ebp-30h] BYREF
  CMFCScanliner *v10; // [esp+24h] [ebp-28h]
  RECT rcSrc1; // [esp+28h] [ebp-24h] BYREF
  CRect rect; // [esp+38h] [ebp-14h] BYREF

  v10 = this;
  if ( bitmap != nullptr
    && GetObjectA(h: bitmap, c: 24, pv: &bmp) != 0
    && bmp.bmBits != nullptr
    && bmp.bmBitsPixel >= 0x18u )
  {
    v3 = abs(lnumber: bmp.bmHeight);
    bmWidth = bmp.bmWidth;
    rect.left = 0;
    rect.top = 0;
    v5 = v3;
    rcSrc1.left = ptBegin->x;
    y = ptBegin->y;
    rcSrc1.right = bmp.bmWidth + rcSrc1.left;
    rcSrc1.top = y;
    size.cx = bmp.bmWidth;
    size.cy = v3;
    rect.right = bmp.bmWidth;
    rect.bottom = v3;
    rcSrc1.bottom = v3 + y;
    IntersectRect(lprcDst: &rect, lprcSrc1: &rcSrc1, lprcSrc2: &rect);
    v7 = (bmp.bmBitsPixel >> 3) * bmWidth;
    if ( v7 % 4 != 0 )
      v7 += 4 - v7 % 4;
    CMFCScanliner::attach(
      this: v10,
      data: (unsigned __int8 *)bmp.bmBits,
      &size,
      height: v5,
      pitch: v7,
      channels: bmp.bmBitsPixel >> 3,
      invert: bmp.bmHeight < 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BB44D
// Name: public: int CMFCToolBarImages::PrepareDrawImage(struct tagAFXDrawState __near &,class CSize,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::PrepareDrawImage(
        CMFCToolBarImages *this,
        tagAFXDrawState *ds,
        CSize sizeImageDest,
        int bFadeInactive)
{
  HBITMAP__ *m_hbmImageLight; // edx
  int m_nBitsPerPixel; // eax
  HBITMAP__ *m_hbmImageWell; // ecx
  HDC__ *v9; // eax
  void *v10; // eax
  HBITMAP__ *v11; // eax
  HBITMAP__ *v12; // eax
  bool v13; // zf
  HBITMAP__ *Bitmap; // eax
  HBITMAP__ *v15; // eax
  int cy; // eax
  CPoint *p_m_sizeImageDest; // edi
  unsigned int m_clrTransparent; // ebx
  HDC CompatibleDC; // eax
  HBITMAP CompatibleBitmap; // eax
  void *m_hObject; // edi
  CBitmap *v22; // eax
  HDC v23; // [esp-8h] [ebp-38h]
  CSize m_sizeImage; // [esp-8h] [ebp-38h]
  CWindowDC dc; // [esp+10h] [ebp-20h] BYREF
  int v26; // [esp+2Ch] [ebp-4h]

  if ( this->m_hbmImageWell == nullptr )
    return 0;
  if ( CMFCToolBarImages::m_bMultiThreaded != 0 )
    EnterCriticalSection(lpCriticalSection: &CMFCToolBarImages::m_CriticalSection.m_sect);
  if ( bFadeInactive != 0 )
  {
    if ( this->m_nBitsPerPixel >= 32 )
      goto LABEL_15;
    if ( this->m_hbmImageLight == nullptr )
      CMFCToolBarImages::UpdateInternalImage(this, nIndex: 0);
  }
  if ( this->m_nBitsPerPixel < 32
    && this->m_hbmImageShadow == nullptr
    && CMFCVisualManager::GetInstance()->m_bShadowHighlightedImage != 0
    && afxGlobalData.m_bIsWhiteHighContrast == 0
    && afxGlobalData.m_bIsBlackHighContrast == 0 )
  {
    CMFCToolBarImages::UpdateInternalImage(this, nIndex: 1);
  }
LABEL_15:
  m_hbmImageLight = this->m_hbmImageLight;
  this->m_bStretch = 0;
  if ( m_hbmImageLight == nullptr
    || (m_nBitsPerPixel = this->m_nBitsPerPixel) > 4 && this->m_bAlwaysLight == 0
    || m_nBitsPerPixel == 0 )
  {
    bFadeInactive = 0;
  }
  m_hbmImageWell = this->m_hbmImageWell;
  this->m_bFadeInactive = bFadeInactive;
  if ( m_hbmImageWell == nullptr )
    goto LABEL_21;
  v9 = this == (CMFCToolBarImages *)-64 ? nullptr : this->m_dcMem.m_hDC;
  if ( v9 != nullptr )
    goto LABEL_21;
  v10 = this == (CMFCToolBarImages *)-152 ? nullptr : this->m_bmpMem.m_hObject;
  if ( v10 != nullptr || this->m_pBmpOriginal != nullptr )
    goto LABEL_21;
  if ( bFadeInactive == 0 || (v11 = m_hbmImageLight, this->m_nBitsPerPixel >= 32) )
    v11 = m_hbmImageWell;
  v12 = (HBITMAP__ *)SelectObject(hdc: hDCGlyphs, h: v11);
  ds->hbmOldGlyphs = v12;
  if ( v12 == nullptr )
  {
    v13 = CMFCToolBarImages::m_bMultiThreaded == 0;
    goto LABEL_36;
  }
  if ( this->m_bCreateMonoDC != 0 )
  {
    Bitmap = CreateBitmap(
               nWidth: this->m_sizeImage.cx + 2,
               nHeight: this->m_sizeImage.cy + 2,
               nPlanes: 1u,
               nBitCount: 1u,
               lpBits: nullptr);
    v23 = hDCMono;
    ds->hbmMono = Bitmap;
    v15 = (HBITMAP__ *)SelectObject(hdc: v23, h: Bitmap);
    v13 = ds->hbmMono == nullptr;
    ds->hbmMonoOld = v15;
    if ( v13 || v15 == nullptr )
    {
      AfxDeleteObject(pObject: (void **)&ds->hbmMono);
      v13 = CMFCToolBarImages::m_bMultiThreaded == 0;
LABEL_36:
      if ( !v13 )
        LeaveCriticalSection(lpCriticalSection: &CMFCToolBarImages::m_CriticalSection.m_sect);
      return 0;
    }
  }
  if ( sizeImageDest.cx <= 0 || (cy = sizeImageDest.cy, sizeImageDest.cy <= 0) )
  {
    p_m_sizeImageDest = (CPoint *)&this->m_sizeImageDest;
    this->m_sizeImageDest.cx = this->m_sizeImage.cx;
    cy = this->m_sizeImage.cy;
  }
  else
  {
    p_m_sizeImageDest = (CPoint *)&this->m_sizeImageDest;
    this->m_sizeImageDest.cx = sizeImageDest.cx;
  }
  v13 = this->m_nBitsPerPixel == 32;
  p_m_sizeImageDest->y = cy;
  if ( v13 )
    m_clrTransparent = -1;
  else
    m_clrTransparent = this->m_clrTransparent;
  if ( CPoint::operator!=(this: p_m_sizeImageDest, point: (tagPOINT)this->m_sizeImage) || m_clrTransparent != -1 )
  {
    CWindowDC::CWindowDC(this: &dc, pWnd: nullptr);
    m_sizeImage = this->m_sizeImage;
    v26 = 0;
    this->m_bStretch = CPoint::operator!=(this: p_m_sizeImageDest, point: (tagPOINT)m_sizeImage);
    CompatibleDC = CreateCompatibleDC(hdc: nullptr);
    CDC::Attach(this: &this->m_dcMem, hDC: CompatibleDC);
    CompatibleBitmap = CreateCompatibleBitmap(hdc: dc.m_hDC, cx: this->m_sizeImage.cx + 2, cy: this->m_sizeImage.cy + 2);
    CGdiObject::Attach(this: &this->m_bmpMem, hObject: CompatibleBitmap);
    if ( this == (CMFCToolBarImages *)-152 )
      m_hObject = nullptr;
    else
      m_hObject = this->m_bmpMem.m_hObject;
    v22 = (CBitmap *)CDC::SelectGdiObject(hDC: this->m_dcMem.m_hDC, h: m_hObject);
    this->m_pBmpOriginal = v22;
    if ( v22 != nullptr )
    {
      v26 = -1;
      CWindowDC::~CWindowDC(this: &dc);
      return 1;
    }
LABEL_21:
    AfxThrowInvalidArgException();
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103BB6B7
// Name: public: struct HICON__ __near * CMFCToolBarImages::ExtractIconA(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HICON__ *__thiscall CMFCToolBarImages::ExtractIconA(CMFCToolBarImages *this, int nIndex)
{
  int m_nBitsPerPixel; // eax
  BOOL v4; // edi
  unsigned int v5; // edi
  HBITMAP__ *v6; // eax
  unsigned int m_clrTransparent; // esi
  CGdiObject *v8; // eax
  HBITMAP__ *m_hObject; // eax
  HICON__ *v10; // eax
  HICON__ *v11; // esi
  int cx; // [esp-14h] [ebp-3Ch]
  int cy; // [esp-10h] [ebp-38h]
  CImageList images; // [esp+10h] [ebp-18h] BYREF
  HBITMAP__ *hbmImageWellCopy; // [esp+18h] [ebp-10h] BYREF
  int v17; // [esp+24h] [ebp-4h]

  if ( nIndex < 0 || nIndex >= this->m_iCount )
    return nullptr;
  m_nBitsPerPixel = this->m_nBitsPerPixel;
  v4 = m_nBitsPerPixel != 32;
  switch ( m_nBitsPerPixel )
  {
    case 8:
      v5 = v4 | 8;
      break;
    case 16:
      v5 = v4 | 0x10;
      break;
    case 24:
      v5 = v4 | 0x18;
      break;
    case 32:
      v5 = v4 | 0x20;
      break;
    default:
      v5 = v4 | 4;
      break;
  }
  CImageList::CImageList(this: &images);
  cy = this->m_sizeImage.cy;
  cx = this->m_sizeImage.cx;
  v17 = 0;
  CImageList::Create(this: &images, cx, cy, nFlags: v5, nInitial: 0, nGrow: 0);
  v6 = (HBITMAP__ *)CopyImage(h: this->m_hbmImageWell, type: 0, cx: 0, cy: 0, flags: 0x2000u);
  m_clrTransparent = this->m_clrTransparent;
  hbmImageWellCopy = v6;
  if ( m_clrTransparent == -1 )
    m_clrTransparent = afxGlobalData.clrBtnFace;
  v8 = CGdiObject::FromHandle(h: v6);
  if ( v8 != nullptr )
    m_hObject = (HBITMAP__ *)v8->m_hObject;
  else
    m_hObject = nullptr;
  AfxImageList_AddMasked(himl: images.m_hImageList, hbmImage: m_hObject, crMask: m_clrTransparent);
  AfxDeleteObject(pObject: (void **)&hbmImageWellCopy);
  v10 = CImageList::ExtractIconA(this: &images, nImage: nIndex);
  v17 = -1;
  v11 = v10;
  CImageList::~CImageList(this: &images);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x103BB7A2
// Name: public: void CMFCToolBarImages::Clear(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarImages::Clear(CMFCToolBarImages *this)
{
  HBITMAP__ **p_m_hbmImageWell; // ebx
  long double m_dblScale; // st7
  int cx; // eax

  if ( this->m_bIsTemporary == 0 )
  {
    p_m_hbmImageWell = &this->m_hbmImageWell;
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageWell);
    *p_m_hbmImageWell = nullptr;
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageLight);
    this->m_hbmImageLight = nullptr;
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageShadow);
    this->m_hbmImageShadow = nullptr;
    CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstOrigResIds);
    CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapOrigResOffsets);
    CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstOrigResInstances);
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strUDLPath);
    m_dblScale = this->m_dblScale;
    this->m_bUserImagesList = 0;
    this->m_iCount = 0;
    this->m_bModified = 0;
    this->m_bIsGray = 0;
    this->m_nGrayImageLuminancePercentage = 0;
    this->m_nBitsPerPixel = 0;
    if ( 1.0 != m_dblScale )
    {
      cx = this->m_sizeImageOriginal.cx;
      this->m_dblScale = 1.0;
      this->m_sizeImage.cx = cx;
      this->m_sizeImage.cy = this->m_sizeImageOriginal.cy;
      this->m_sizeImageOriginal.cx = 0;
      this->m_sizeImageOriginal.cy = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BB853
// Name: protected: void CMFCToolBarImages::CopyTemp(class CMFCToolBarImages __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarImages::CopyTemp(CMFCToolBarImages *this, CMFCToolBarImages *imagesDest)
{
  CMFCToolBarImages::Clear(this: imagesDest);
  imagesDest->m_bIsTemporary = 1;
  imagesDest->m_sizeImage = this->m_sizeImage;
  imagesDest->m_sizeImageDest = this->m_sizeImageDest;
  imagesDest->m_hbmImageWell = this->m_hbmImageWell;
  imagesDest->m_bUserImagesList = this->m_bUserImagesList;
  imagesDest->m_iCount = this->m_iCount;
  imagesDest->m_bReadOnly = 1;
  imagesDest->m_nBitsPerPixel = this->m_nBitsPerPixel;
}

//------------------------------------------------------------------------------
// Address: 0x103BB8AB
// Name: public: int CMFCToolBarImages::SmoothResize(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarImages::SmoothResize(CMFCToolBarImages *this, double dblImageScale)
{
  int cy; // ecx
  unsigned int m_iCount; // ebx
  signed int v6; // eax
  bool v7; // sf
  int v8; // ecx
  bool v9; // c0
  bool v10; // c3
  int m_channels; // ebx
  int v12; // eax
  int y; // ebx
  long double *v14; // ebx
  CMFCZoomKernel::XKernel *v15; // eax
  unsigned __int8 *v16; // ebx
  CMFCZoomKernel::XKernelList *v17; // eax
  CMFCZoomKernel::XKernel *v18; // ecx
  long double v19; // st7
  unsigned __int8 *j; // eax
  double *v21; // ecx
  int v22; // edx
  long double *v23; // eax
  int v24; // ecx
  int v25; // ecx
  long double v26; // st7
  long double v27; // st7
  long double v28; // st7
  long double v29; // st5
  unsigned __int8 *v30; // ecx
  unsigned int m_clrTransparent; // eax
  bool v32; // zf
  BOOL v33; // edi
  int cx; // [esp-14h] [ebp-134h]
  int v35; // [esp-14h] [ebp-134h]
  double weight; // [esp+10h] [ebp-110h]
  CMFCScanlinerBitmap md; // [esp+18h] [ebp-108h] BYREF
  char pv[8]; // [esp+44h] [ebp-DCh] BYREF
  int lnumber; // [esp+4Ch] [ebp-D4h]
  CMFCZoomKernel KernelX; // [esp+50h] [ebp-D0h] BYREF
  CMFCScanlinerBitmap ms; // [esp+5Ch] [ebp-C4h] BYREF
  CMFCZoomKernel::XKernel **p_stat; // [esp+88h] [ebp-98h]
  CMFCZoomKernel::XKernelList *v43; // [esp+8Ch] [ebp-94h]
  int v44; // [esp+90h] [ebp-90h]
  int v45; // [esp+94h] [ebp-8Ch]
  CMFCZoomKernel KernelY; // [esp+98h] [ebp-88h] BYREF
  int i; // [esp+A4h] [ebp-7Ch]
  unsigned int val_size; // [esp+A8h] [ebp-78h]
  CPoint offSrc; // [esp+ACh] [ebp-74h]
  CSize sizeNew; // [esp+B4h] [ebp-6Ch]
  unsigned int sy; // [esp+BCh] [ebp-64h]
  HBITMAP__ *hBmpSrc; // [esp+C0h] [ebp-60h]
  CPoint offDst; // [esp+C4h] [ebp-5Ch]
  unsigned __int8 *pRowDst; // [esp+CCh] [ebp-54h]
  unsigned int v55; // [esp+D0h] [ebp-50h]
  unsigned __int8 *m_line_begin; // [esp+D4h] [ebp-4Ch]
  int v57; // [esp+D8h] [ebp-48h]
  unsigned int v58; // [esp+DCh] [ebp-44h]
  unsigned int sx; // [esp+E0h] [ebp-40h]
  unsigned __int8 *v60; // [esp+E4h] [ebp-3Ch]
  CSize sizeNewIW; // [esp+E8h] [ebp-38h] BYREF
  CMFCZoomKernel::XKernelList *m_List; // [esp+F0h] [ebp-30h]
  long double *values; // [esp+F4h] [ebp-2Ch]
  long double *values2; // [esp+F8h] [ebp-28h]
  int bInvert; // [esp+FCh] [ebp-24h]
  HBITMAP__ *hBmpDst; // [esp+100h] [ebp-20h]
  CPoint offSrcSum; // [esp+104h] [ebp-1Ch] BYREF
  int sizeDst; // [esp+10Ch] [ebp-14h]
  unsigned int dy; // [esp+110h] [ebp-10h]
  int v70; // [esp+11Ch] [ebp-4h]
  CMFCZoomKernel::XFilterType ft_4; // [esp+12Ch] [ebp+Ch]
  unsigned int ft_4a; // [esp+12Ch] [ebp+Ch]
  unsigned int ft_4b; // [esp+12Ch] [ebp+Ch]

  if ( this->m_hbmImageWell == nullptr || this->m_nBitsPerPixel < 24 || 0.0 == dblImageScale )
    return false;
  if ( 1.0 == dblImageScale )
    return true;
  hBmpDst = (HBITMAP__ *)this->m_sizeImage.cy;
  bInvert = this->m_sizeImage.cx;
  sizeDst = (int)((double)(int)hBmpDst * dblImageScale + 0.5);
  cy = this->m_sizeImage.cy;
  sizeNew.cx = (int)(dblImageScale * (double)bInvert + 0.5);
  if ( __PAIR64__(sizeDst, sizeNew.cx) == __PAIR64__(cy, bInvert) )
    return true;
  if ( bInvert <= 0 )
    return true;
  if ( (int)hBmpDst <= 0 )
    return true;
  if ( sizeNew.cx <= 0 )
    return true;
  if ( sizeDst <= 0 )
    return true;
  m_iCount = this->m_iCount;
  dy = m_iCount;
  if ( m_iCount == 0 )
    return true;
  if ( GetObjectA(h: this->m_hbmImageWell, c: 24, pv) == 0 )
    return false;
  v6 = abs(lnumber);
  v7 = lnumber < 0;
  this->m_dblScale = this->m_dblScale * dblImageScale;
  offSrc.y = 0;
  offDst.x = 0;
  offDst.y = 0;
  bInvert = v7;
  offSrc.x = this->m_sizeImage.cx;
  if ( m_iCount == 1 )
  {
    v8 = this->m_sizeImage.cy;
    if ( v6 > v8 )
    {
      offSrc.x = 0;
      offSrc.y = v8;
      dy = v6 / v8;
      m_iCount = v6 / v8;
    }
  }
  hBmpSrc = CDrawingManager::CreateBitmap_32(bitmap: this->m_hbmImageWell, clrTransparent: this->m_clrTransparent);
  if ( hBmpSrc == nullptr )
    return false;
  sizeNewIW.cx = sizeNew.cx;
  sizeNewIW.cy = sizeDst;
  if ( offSrc.x <= 0 )
  {
    sizeNewIW.cy = m_iCount * sizeDst;
    offDst.y = sizeDst;
  }
  else
  {
    sizeNewIW.cx = sizeNew.cx * m_iCount;
    offDst.x = sizeNew.cx;
  }
  if ( bInvert != 0 )
    sizeNewIW.cy = -sizeNewIW.cy;
  hBmpDst = CDrawingManager::CreateBitmap_32(size: &sizeNewIW, pBits: nullptr);
  sizeNewIW.cy = abs(lnumber: sizeNewIW.cy);
  if ( hBmpDst == nullptr )
  {
    DeleteObject(ho: hBmpSrc);
    return false;
  }
  v9 = dblImageScale > 1.0;
  v10 = 1.0 == dblImageScale;
  ft_4 = e_FilterTypeLanczos3;
  if ( v9 || v10 )
    ft_4 = e_FilterTypeMitchell;
  memset(&ms, 0, 36);
  ms.m_height = 0;
  v70 = 0;
  offSrcSum.x = 0;
  offSrcSum.y = 0;
  CMFCScanlinerBitmap::attach(this: &ms, bitmap: hBmpSrc, ptBegin: &offSrcSum);
  memset(&md, 0, 36);
  md.m_height = 0;
  offSrcSum.x = 0;
  offSrcSum.y = 0;
  CMFCScanlinerBitmap::attach(this: &md, bitmap: hBmpDst, ptBegin: &offSrcSum);
  m_channels = ms.m_channels;
  KernelX.__vftable = (CMFCZoomKernel_vtbl *)&CMFCZoomKernel::`vftable';
  KernelX.m_Size = 0;
  KernelX.m_List = nullptr;
  cx = this->m_sizeImage.cx;
  LOBYTE(v70) = 2;
  CMFCZoomKernel::Create(this: &KernelX, sizeSrc: cx, sizeDst: sizeNew.cx, originSrc: 0, widthSrc: cx, ft: ft_4);
  KernelY.__vftable = (CMFCZoomKernel_vtbl *)&CMFCZoomKernel::`vftable';
  KernelY.m_Size = 0;
  KernelY.m_List = nullptr;
  v35 = this->m_sizeImage.cy;
  LOBYTE(v70) = 3;
  CMFCZoomKernel::Create(this: &KernelY, sizeSrc: v35, sizeDst, originSrc: 0, widthSrc: v35, ft: ft_4);
  values = (long double *)operator new(nSize: 8 * m_channels);
  values2 = (long double *)operator new(nSize: 8 * m_channels);
  offSrcSum.x = 0;
  offSrcSum.y = 0;
  if ( (int)dy > 0 )
  {
    val_size = 8 * m_channels;
    v12 = offDst.y * md.m_offset;
    y = offDst.x * m_channels;
    v57 = 0;
    v45 = offDst.y * md.m_offset;
    offDst.y = y;
    m_line_begin = md.m_line_begin;
    for ( bInvert = dy; bInvert != 0; --bInvert )
    {
      dy = 0;
      if ( sizeDst != 0 )
      {
        v60 = &m_line_begin[v57];
        do
        {
          pRowDst = v60;
          if ( sizeNew.cx != 0 )
          {
            m_List = KernelX.m_List;
            for ( i = sizeNew.cx; i != 0; --i )
            {
              v14 = values;
              memset(dst: (unsigned __int8 *)values, value: 0, count: val_size);
              sy = 0;
              v43 = &KernelY.m_List[dy];
              if ( v43->count != 0 )
              {
                p_stat = &KernelY.m_List[dy].stat;
                v55 = 0;
                do
                {
                  v15 = &(*p_stat)[v55 / 0xC];
                  weight = v15->weight;
                  v16 = &ms.m_line_begin[ms.m_offset * (offSrcSum.y + v15->pixel)];
                  memset(dst: (unsigned __int8 *)values2, value: 0, count: val_size);
                  v17 = m_List;
                  sx = 0;
                  if ( m_List->count != 0 )
                  {
                    v58 = 0;
                    do
                    {
                      v18 = &v17->stat[v58 / 0xC];
                      v19 = v18->weight;
                      ft_4a = 0;
                      for ( j = &v16[ms.m_channels * (offSrcSum.x + v18->pixel)];
                            ft_4a < ms.m_channels;
                            *v21 = (double)v44 * v19 + *v21 )
                      {
                        v21 = &values2[ft_4a];
                        v44 = *j++;
                        ++ft_4a;
                      }
                      ++sx;
                      v17 = m_List;
                      v58 += 12;
                    }
                    while ( sx < m_List->count );
                  }
                  v22 = ms.m_channels;
                  if ( ms.m_channels != 0 )
                  {
                    v23 = values;
                    v24 = (char *)values2 - (char *)values;
                    do
                    {
                      *v23 = *(long double *)((char *)v23 + v24) * weight + *v23;
                      ++v23;
                      --v22;
                    }
                    while ( v22 != 0 );
                  }
                  ++sy;
                  v55 += 12;
                }
                while ( sy < v43->count );
                v14 = values;
              }
              v25 = ms.m_channels;
              if ( ms.m_channels == 4 )
              {
                if ( v14[3] <= *v14 )
                  v26 = v14[3];
                else
                  v26 = *v14;
                *v14 = v26;
                if ( v14[3] <= v14[1] )
                  v27 = v14[3];
                else
                  v27 = v14[1];
                v14[1] = v27;
                if ( v14[3] <= v14[2] )
                  v28 = v14[3];
                else
                  v28 = v14[2];
                v14[2] = v28;
              }
              ft_4b = 0;
              if ( v25 != 0 )
              {
                do
                {
                  v29 = v14[ft_4b];
                  if ( v29 >= 0.0 )
                  {
                    if ( v29 > 255.0 )
                      v29 = 255.0;
                  }
                  else
                  {
                    v29 = 0.0;
                  }
                  v30 = pRowDst++;
                  ++ft_4b;
                  *v30 = (unsigned __int64)v29;
                }
                while ( ft_4b < ms.m_channels );
              }
              ++m_List;
            }
            v12 = v45;
            y = offDst.y;
          }
          ++dy;
          v60 += md.m_offset;
        }
        while ( dy < sizeDst );
      }
      offSrcSum.x += offSrc.x;
      offSrcSum.y += offSrc.y;
      v57 += y;
      m_line_begin += v12;
    }
  }
  operator delete(p: values);
  operator delete(p: values2);
  DeleteObject(ho: hBmpSrc);
  if ( CSize::operator==(this: &this->m_sizeImageOriginal, size: 0) )
  {
    this->m_sizeImageOriginal.cx = this->m_sizeImage.cx;
    this->m_sizeImageOriginal.cy = this->m_sizeImage.cy;
  }
  this->m_sizeImage.cx = sizeNew.cx;
  this->m_sizeImage.cy = sizeDst;
  m_clrTransparent = this->m_clrTransparent;
  this->m_clrTransparent = -1;
  this->m_clrTransparentOriginal = m_clrTransparent;
  this->m_hbmImageWell = hBmpDst;
  this->m_nBitsPerPixel = 32;
  CMFCToolBarImages::UpdateInternalImage(this, nIndex: 0);
  CMFCToolBarImages::UpdateInternalImage(this, nIndex: 1);
  v32 = this->m_hbmImageWell == nullptr;
  LOBYTE(v70) = 2;
  KernelY.__vftable = (CMFCZoomKernel_vtbl *)&CMFCZoomKernel::`vftable';
  v33 = !v32;
  CMFCZoomKernel::Empty(this: &KernelY);
  LOBYTE(v70) = 1;
  KernelX.__vftable = (CMFCZoomKernel_vtbl *)&CMFCZoomKernel::`vftable';
  CMFCZoomKernel::Empty(this: &KernelX);
  return v33;
}

//------------------------------------------------------------------------------
// Address: 0x103DA5EB
// Name: public: virtual int CMFCBaseTabCtrl::GetVisibleTabsNum(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::GetVisibleTabsNum(CMFCBaseTabCtrl *this)
{
  int m_iTabsNum; // esi
  __int64 v2; // rax

  m_iTabsNum = this->m_iTabsNum;
  v2 = 0;
  if ( m_iTabsNum > 0 )
  {
    do
    {
      if ( v2 < 0 || SHIDWORD(v2) >= this->m_arTabs.m_nSize )
        AfxThrowInvalidArgException();
      if ( *((_DWORD *)this->m_arTabs.m_pData[HIDWORD(v2)] + 13) != 0 )
        LODWORD(v2) = v2 + 1;
      ++HIDWORD(v2);
    }
    while ( SHIDWORD(v2) < m_iTabsNum );
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x103DA627
// Name: public: virtual int CMFCBaseTabCtrl::ShowTab(int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::ShowTab(CMFCBaseTabCtrl *this, int iTab, int bShow, int bRecalcLayout, int bActivate)
{
  void *v7; // edi
  int m_iTabsNum; // eax
  int nVisibleCount; // [esp+Ch] [ebp-4h]
  int iActiveTab; // [esp+18h] [ebp+8h]

  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
LABEL_21:
    AfxThrowInvalidArgException();
  v7 = this->m_arTabs.m_pData[iTab];
  if ( *((_DWORD *)v7 + 13) != bShow )
  {
    nVisibleCount = this->GetVisibleTabsNum(this);
    *((_DWORD *)v7 + 13) = bShow;
    if ( bShow != 0 )
      iActiveTab = this->m_iActiveTab;
    else
      iActiveTab = -1;
    if ( bShow != 0 )
    {
      if ( nVisibleCount == 0 )
        iActiveTab = iTab;
    }
    else
    {
      if ( this->m_bHideInactiveWnd != 0 )
        CWnd::ShowWindow(this: *((CWnd **)v7 + 8), nCmdShow: 0);
      if ( iTab == this->m_iActiveTab )
      {
        m_iTabsNum = this->m_iTabsNum;
        while ( --m_iTabsNum >= 0 )
        {
          if ( m_iTabsNum >= this->m_arTabs.m_nSize )
            goto LABEL_21;
          if ( m_iTabsNum < iTab && iActiveTab >= 0 )
            break;
          if ( *((_DWORD *)this->m_arTabs.m_pData[m_iTabsNum] + 13) != 0 )
            iActiveTab = m_iTabsNum;
        }
        this->m_iActiveTab = -1;
      }
    }
    if ( bRecalcLayout != 0 )
      this->RecalcLayout(this);
    if ( iActiveTab >= 0 && bShow == 0 && this->m_iActiveTab == -1 || bActivate != 0 || nVisibleCount == 0 )
    {
      this->SetActiveTab(this, a2: iActiveTab);
      this->FireChangeActiveTab(this, a2: this->m_iActiveTab);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DA757
// Name: public: virtual class CWnd __near * CMFCBaseTabCtrl::GetTabWnd(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCBaseTabCtrl::GetTabWnd(CMFCBaseTabCtrl *this, int iTab)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return nullptr;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((CWnd **)this->m_arTabs.m_pData[iTab] + 8);
}

//------------------------------------------------------------------------------
// Address: 0x103DA78C
// Name: public: virtual class CWnd __near * CMFCBaseTabCtrl::GetTabWndNoWrapper(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCBaseTabCtrl::GetTabWndNoWrapper(CMFCBaseTabCtrl *this, int iTab)
{
  CObject **v2; // esi
  CObject *v3; // eax

  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return nullptr;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  v2 = (CObject **)this->m_arTabs.m_pData[iTab];
  v3 = AfxDynamicDownCast(pClass: &CDockablePaneAdapter::classCDockablePaneAdapter, pObject: v2[8]);
  if ( v3 != nullptr )
    return (CWnd *)v3->__vftable[78].GetRuntimeClass(this: v3);
  else
    return (CWnd *)v2[8];
}

//------------------------------------------------------------------------------
// Address: 0x103DA7E2
// Name: public: virtual int CMFCBaseTabCtrl::GetTabRect(int,class CRect __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::GetTabRect(CMFCBaseTabCtrl *this, int iTab, CRect *rect)
{
  CRect *v3; // eax

  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  v3 = (CRect *)this->m_arTabs.m_pData[iTab];
  if ( v3[3].top == 0 )
  {
    SetRectEmpty(lprc: rect);
    return 0;
  }
  *rect = v3[1];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DA835
// Name: public: int CMFCBaseTabCtrl::GetTabID(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::GetTabID(CMFCBaseTabCtrl *this, int iTab)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return -1;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((_DWORD *)this->m_arTabs.m_pData[iTab] + 10);
}

//------------------------------------------------------------------------------
// Address: 0x103DA86B
// Name: public: virtual unsigned int CMFCBaseTabCtrl::GetTabIcon(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCBaseTabCtrl::GetTabIcon(CMFCBaseTabCtrl *this, int iTab)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return -1;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((_DWORD *)this->m_arTabs.m_pData[iTab] + 2);
}

//------------------------------------------------------------------------------
// Address: 0x103DA8A1
// Name: public: virtual int CMFCBaseTabCtrl::SetTabIcon(int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::SetTabIcon(CMFCBaseTabCtrl *this, int iTab, HICON uiIcon)
{
  HICON *v3; // esi

  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  v3 = (HICON *)this->m_arTabs.m_pData[iTab];
  if ( v3[3] != nullptr )
    DestroyIcon(hIcon: v3[3]);
  v3[3] = nullptr;
  v3[2] = uiIcon;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DA8F0
// Name: public: virtual struct HICON__ __near * CMFCBaseTabCtrl::GetTabHicon(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HICON__ *__thiscall CMFCBaseTabCtrl::GetTabHicon(CMFCBaseTabCtrl *this, int iTab)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return nullptr;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((HICON__ **)this->m_arTabs.m_pData[iTab] + 3);
}

//------------------------------------------------------------------------------
// Address: 0x103DA925
// Name: public: virtual int CMFCBaseTabCtrl::SetTabHicon(int,struct HICON__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::SetTabHicon(CMFCBaseTabCtrl *this, int iTab, HICON__ *hIcon)
{
  HICON *v4; // edi
  int cx; // ecx
  int cy; // edx
  int v7; // ecx
  CMFCBaseTabCtrl_vtbl *v8; // eax

  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  v4 = (HICON *)this->m_arTabs.m_pData[iTab];
  if ( v4[3] != nullptr )
    DestroyIcon(hIcon: v4[3]);
  if ( hIcon != nullptr )
    v4[3] = CopyIcon(hIcon);
  else
    v4[3] = nullptr;
  v4[2] = (HICON)-1;
  cx = afxGlobalData.m_sizeSmallIcon.cx;
  if ( this->m_sizeImage.cx > afxGlobalData.m_sizeSmallIcon.cx )
    cx = this->m_sizeImage.cx;
  cy = this->m_sizeImage.cy;
  this->m_sizeImage.cx = cx;
  v7 = afxGlobalData.m_sizeSmallIcon.cy;
  if ( cy > afxGlobalData.m_sizeSmallIcon.cy )
    v7 = cy;
  v8 = this->__vftable;
  this->m_sizeImage.cy = v7;
  v8->SetTabsHeight(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DA9CC
// Name: public: virtual int CMFCBaseTabCtrl::IsTabIconOnly(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::IsTabIconOnly(CMFCBaseTabCtrl *this, int iTab)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((_DWORD *)this->m_arTabs.m_pData[iTab] + 15);
}

//------------------------------------------------------------------------------
// Address: 0x103DAA01
// Name: public: virtual int CMFCBaseTabCtrl::SetTabIconOnly(int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::SetTabIconOnly(CMFCBaseTabCtrl *this, int iTab, int bIconOnly, int bAlwaysShowToolTip)
{
  _DWORD *v4; // eax

  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  v4 = this->m_arTabs.m_pData[iTab];
  v4[15] = bIconOnly;
  v4[16] = bAlwaysShowToolTip;
  this->RecalcLayout(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DAA4A
// Name: public: virtual int CMFCBaseTabCtrl::IsTabDetachable(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::IsTabDetachable(CMFCBaseTabCtrl *this, int iTab)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((_DWORD *)this->m_arTabs.m_pData[iTab] + 17);
}

//------------------------------------------------------------------------------
// Address: 0x103DAA7F
// Name: public: virtual int CMFCBaseTabCtrl::EnableTabDetach(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::EnableTabDetach(CMFCBaseTabCtrl *this, int iTab, int bEnable)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  *((_DWORD *)this->m_arTabs.m_pData[iTab] + 17) = bEnable;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DAABA
// Name: public: virtual class CWnd __near * CMFCBaseTabCtrl::GetActiveWnd(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCBaseTabCtrl::GetActiveWnd(CMFCBaseTabCtrl *this)
{
  int m_iActiveTab; // eax

  m_iActiveTab = this->m_iActiveTab;
  if ( m_iActiveTab == -1 )
    return nullptr;
  if ( m_iActiveTab < 0 || m_iActiveTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((CWnd **)this->m_arTabs.m_pData[m_iActiveTab] + 8);
}

//------------------------------------------------------------------------------
// Address: 0x103DAAE6
// Name: public: virtual int CMFCBaseTabCtrl::GetTabFromPoint(class CPoint __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::GetTabFromPoint(CMFCBaseTabCtrl *this, CPoint *pt)
{
  int v3; // edi
  const RECT *v4; // eax

  v3 = 0;
  if ( this->m_iTabsNum <= 0 )
    return -1;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_arTabs.m_nSize )
      AfxThrowInvalidArgException();
    v4 = (const RECT *)this->m_arTabs.m_pData[v3];
    if ( v4[3].top != 0 && PtInRect(lprc: v4 + 1, pt: pt->tagPOINT) )
      break;
    if ( ++v3 >= this->m_iTabsNum )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103DAB48
// Name: public: virtual int CMFCBaseTabCtrl::GetTabByID(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::GetTabByID(CMFCBaseTabCtrl *this, int id)
{
  int m_iTabsNum; // edx
  int result; // eax

  m_iTabsNum = this->m_iTabsNum;
  result = 0;
  if ( m_iTabsNum <= 0 )
    return -1;
  while ( 1 )
  {
    if ( result < 0 || result >= this->m_arTabs.m_nSize )
      AfxThrowInvalidArgException();
    if ( *((_DWORD *)this->m_arTabs.m_pData[result] + 10) == id )
      break;
    if ( ++result >= m_iTabsNum )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DAB8A
// Name: public: virtual int CMFCBaseTabCtrl::IsTabVisible(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::IsTabVisible(CMFCBaseTabCtrl *this, int iTab)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((_DWORD *)this->m_arTabs.m_pData[iTab] + 13);
}

//------------------------------------------------------------------------------
// Address: 0x103DABBF
// Name: protected: virtual int CMFCBaseTabCtrl::GetTabNumberToDetach(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::GetTabNumberToDetach(CMFCBaseTabCtrl *this, int nTabNum)
{
  int result; // eax

  result = nTabNum;
  if ( nTabNum == -1 )
    return this->m_iActiveTab;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DABD6
// Name: protected: void CMFCBaseTabCtrl::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::OnDestroy(CMFCBaseTabCtrl *this)
{
  this->CleanUp(this);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103DABEB
// Name: protected: int CMFCBaseTabCtrl::FindTabInfo(int,class CMFCTabInfo __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::FindTabInfo(CMFCBaseTabCtrl *this, int nBarID, CMFCTabInfo **ppTabInfo)
{
  int v3; // ebx
  CMFCTabInfo *v5; // edi
  CWnd *m_pWnd; // ecx

  v3 = 0;
  *ppTabInfo = nullptr;
  if ( this->m_arTabs.m_nSize <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_arTabs.m_nSize )
      AfxThrowInvalidArgException();
    v5 = (CMFCTabInfo *)this->m_arTabs.m_pData[v3];
    m_pWnd = v5->m_pWnd;
    if ( m_pWnd != nullptr && CWnd::GetDlgCtrlID(this: m_pWnd) == nBarID )
      break;
    if ( ++v3 >= this->m_arTabs.m_nSize )
      return 0;
  }
  *ppTabInfo = v5;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103DAC4B
// Name: public: virtual void CMFCBaseTabCtrl::SwapTabs(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::SwapTabs(CMFCBaseTabCtrl *this, int nFisrtTabID, int nSecondTabID)
{
  int m_nSize; // edx
  void **v4; // eax
  void *v5; // edi

  m_nSize = this->m_arTabs.m_nSize;
  if ( m_nSize > nFisrtTabID && m_nSize > nSecondTabID )
  {
    if ( nFisrtTabID < 0
      || nFisrtTabID >= m_nSize
      || (v4 = &this->m_arTabs.m_pData[nFisrtTabID], v5 = *v4, nSecondTabID < 0)
      || nSecondTabID >= m_nSize
      || (*v4 = this->m_arTabs.m_pData[nSecondTabID], nSecondTabID >= this->m_arTabs.m_nSize) )
    {
      AfxThrowInvalidArgException();
    }
    this->m_arTabs.m_pData[nSecondTabID] = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DACAD
// Name: public: virtual void CMFCBaseTabCtrl::MoveTab(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::MoveTab(CMFCBaseTabCtrl *this, int nSource, int nDest)
{
  int m_nSize; // edx
  void **m_pData; // eax
  int m_iActiveTab; // ecx
  CPtrArray *p_m_arTabs; // ecx
  int v9; // ecx
  int v10; // eax
  CMFCTabInfo *pActive; // [esp+8h] [ebp-4h]
  CMFCTabInfo *pSource; // [esp+14h] [ebp+8h]

  if ( nSource != nDest )
  {
    if ( nSource < 0
      || (m_nSize = this->m_arTabs.m_nSize, nSource >= m_nSize)
      || (m_pData = this->m_arTabs.m_pData,
          pSource = (CMFCTabInfo *)m_pData[nSource],
          (m_iActiveTab = this->m_iActiveTab) < 0)
      || m_iActiveTab >= m_nSize )
    {
LABEL_18:
      AfxThrowInvalidArgException();
    }
    pActive = (CMFCTabInfo *)m_pData[m_iActiveTab];
    p_m_arTabs = &this->m_arTabs;
    if ( nDest == -1 )
    {
      CUIntArray::SetAtGrow(this: p_m_arTabs, nIndex: m_nSize, newElement: pSource);
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arTabs,
        nIndex: nSource,
        nCount: 1);
    }
    else
    {
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)p_m_arTabs,
        nIndex: nSource,
        nCount: 1);
      CPtrArray::InsertAt(this: &this->m_arTabs, nIndex: nDest, newElement: pSource, nCount: 1);
    }
    v9 = this->m_arTabs.m_nSize;
    v10 = 0;
    if ( v9 > 0 )
    {
      while ( 1 )
      {
        if ( v10 < 0 || v10 >= v9 )
          goto LABEL_18;
        if ( pActive == this->m_arTabs.m_pData[v10] )
          break;
        if ( ++v10 >= v9 )
          goto LABEL_14;
      }
      if ( v10 != this->m_iActiveTab )
      {
        this->SetActiveTab(this, a2: v10);
        this->FireChangeActiveTab(this, a2: this->m_iActiveTab);
      }
    }
LABEL_14:
    this->RecalcLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DADA5
// Name: protected: virtual class CWnd __near * CMFCBaseTabCtrl::CreateWrapper(class CWnd __near *,char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCBaseTabCtrl::CreateWrapper(
        CMFCBaseTabCtrl *this,
        CWnd *pWndToWrap,
        const char *lpszTabLabel,
        int bDetachable)
{
  CWnd *v4; // edi
  CRuntimeClass *m_pDockingBarWrapperRTC; // ecx
  CObject *Object; // eax
  CDockablePaneAdapter *v8; // eax
  CDockablePaneAdapter *v9; // eax
  _DWORD *v10; // ebx
  int v11; // esi
  int DlgCtrlID; // eax
  bool v13; // zf
  int v14; // eax
  CRuntimeClass *pData; // [esp+1Ch] [ebp-2Ch]
  int v18; // [esp+20h] [ebp-28h]
  int v19; // [esp+24h] [ebp-24h]
  int left; // [esp+28h] [ebp-20h] BYREF
  int top; // [esp+2Ch] [ebp-1Ch]
  int right; // [esp+30h] [ebp-18h]
  int bottom; // [esp+34h] [ebp-14h]
  int v24; // [esp+44h] [ebp-4h]

  v4 = pWndToWrap;
  if ( CObject::IsKindOf(this: pWndToWrap, pClass: &CDockablePane::classCDockablePane) != 0
    || bDetachable == 0
    || this->m_bEnableWrapping == 0 )
  {
    return v4;
  }
  m_pDockingBarWrapperRTC = this->m_pDockingBarWrapperRTC;
  if ( m_pDockingBarWrapperRTC != nullptr )
  {
    Object = CRuntimeClass::CreateObject(this: m_pDockingBarWrapperRTC);
    v8 = (CDockablePaneAdapter *)AfxDynamicDownCast(
                                   pClass: &CDockablePaneAdapter::classCDockablePaneAdapter,
                                   pObject: Object);
  }
  else
  {
    v9 = (CDockablePaneAdapter *)operator new(nSize: 0x368u);
    v24 = 0;
    if ( v9 != nullptr )
      v8 = CDockablePaneAdapter::CDockablePaneAdapter(this: v9);
    else
      v8 = nullptr;
    v24 = -1;
  }
  v10 = &v8->__vftable;
  left = v8->m_rectInitial.left;
  top = v8->m_rectInitial.top;
  right = v8->m_rectInitial.right;
  bottom = v8->m_rectInitial.bottom;
  v4 = pWndToWrap;
  pData = v8->m_pTabbedControlBarRTC;
  v19 = 1442840576;
  v18 = 15;
  if ( CObject::IsKindOf(this: pWndToWrap, pClass: &CBasePane::classCBasePane) != 0 )
  {
    v19 = ((int (__thiscall *)(CWnd *))pWndToWrap->__vftable[1].CreateEx_2)(a1: pWndToWrap) | 0x56000000;
    v18 = pWndToWrap->__vftable[1].DestroyWindow(this: pWndToWrap);
  }
  v11 = *v10;
  DlgCtrlID = CWnd::GetDlgCtrlID(this: pWndToWrap);
  v13 = (*(int (__thiscall **)(_DWORD *, const char *, CMFCBaseTabCtrl *, int *, int, int, int, int, int, _DWORD))(v11 + 804))(
          a1: v10,
          a2: lpszTabLabel,
          a3: this,
          a4: &left,
          a5: 1,
          a6: DlgCtrlID,
          a7: v19,
          a8: 32,
          a9: v18,
          a10: 0) == 0;
  v14 = *v10;
  if ( v13 )
  {
    (*(void (__thiscall **)(_DWORD *, int))(v14 + 4))(a1: v10, a2: 1);
    return v4;
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD))(v14 + 492))(a1: v10, a2: 0);
  (*(void (__thiscall **)(_DWORD *, CWnd *))(*v10 + 932))(a1: v10, a2: pWndToWrap);
  v10[118] = left;
  v10[119] = top;
  v10[120] = right;
  v10[121] = bottom;
  if ( pData != nullptr )
    v10[205] = pData;
  return (CWnd *)v10;
}

//------------------------------------------------------------------------------
// Address: 0x103DAEF2
// Name: public: virtual void CMFCBaseTabCtrl::SetActiveTabTextColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::SetActiveTabTextColor(CMFCBaseTabCtrl *this, unsigned int clr)
{
  this->m_clrActiveTabFg = clr;
}

//------------------------------------------------------------------------------
// Address: 0x103DAF04
// Name: public: virtual int CMFCBaseTabCtrl::SetTabBkColor(int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::SetTabBkColor(CMFCBaseTabCtrl *this, int iTab, unsigned int color)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  *((_DWORD *)this->m_arTabs.m_pData[iTab] + 12) = color;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DAF3F
// Name: public: virtual unsigned long CMFCBaseTabCtrl::GetTabTextColor(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCBaseTabCtrl::GetTabTextColor(CMFCBaseTabCtrl *this, int iTab)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return -1;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((_DWORD *)this->m_arTabs.m_pData[iTab] + 11);
}

//------------------------------------------------------------------------------
// Address: 0x103DAF75
// Name: public: virtual int CMFCBaseTabCtrl::SetTabTextColor(int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::SetTabTextColor(CMFCBaseTabCtrl *this, int iTab, unsigned int color)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  *((_DWORD *)this->m_arTabs.m_pData[iTab] + 11) = color;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DAFB0
// Name: public: virtual int CMFCBaseTabCtrl::GetTabFullWidth(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::GetTabFullWidth(CMFCBaseTabCtrl *this, int iTab)
{
  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  return *((_DWORD *)this->m_arTabs.m_pData[iTab] + 9);
}

//------------------------------------------------------------------------------
// Address: 0x103DAFE5
// Name: public: virtual void CMFCBaseTabCtrl::SetTabsHeight(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::SetTabsHeight(CMFCBaseTabCtrl *this)
{
  int cy; // eax
  int v2; // edx
  int v3; // eax

  cy = this->m_sizeImage.cy;
  if ( cy > 0 )
    v2 = cy + 7;
  else
    v2 = 0;
  if ( v2 <= afxGlobalData.m_nTextHeightHorz + 5 )
    v3 = afxGlobalData.m_nTextHeightHorz + 5;
  else
    v3 = v2;
  this->m_nTabsHeight = v3;
}

//------------------------------------------------------------------------------
// Address: 0x103DB012
// Name: public: virtual class CWnd __near * CMFCBaseTabCtrl::GetFirstVisibleTab(int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCBaseTabCtrl::GetFirstVisibleTab(CMFCBaseTabCtrl *this, int *iTabNum)
{
  return this->GetFirstVisibleTab(this, a2: 0, a3: iTabNum);
}

//------------------------------------------------------------------------------
// Address: 0x103DB028
// Name: public: virtual class CWnd __near * CMFCBaseTabCtrl::GetFirstVisibleTab(int,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCBaseTabCtrl::GetFirstVisibleTab(CMFCBaseTabCtrl *this, int iStartFrom, int *iTabNum)
{
  int i; // eax
  _DWORD *v4; // edx

  for ( i = iStartFrom; i < this->m_iTabsNum; ++i )
  {
    if ( i < 0 || i >= this->m_arTabs.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arTabs.m_pData[i];
    if ( v4[13] != 0 )
    {
      *iTabNum = i;
      return (CWnd *)v4[8];
    }
  }
  if ( iStartFrom > 0 )
    return this->GetFirstVisibleTab(this, a2: 0, a3: iTabNum);
  *iTabNum = -1;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103DB08A
// Name: public: virtual class CWnd __near * CMFCBaseTabCtrl::GetLastVisibleTab(int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCBaseTabCtrl::GetLastVisibleTab(CMFCBaseTabCtrl *this, int *iTabNum)
{
  int m_iTabsNum; // eax
  _DWORD *v3; // edx

  m_iTabsNum = this->m_iTabsNum;
  do
  {
    if ( --m_iTabsNum < 0 )
    {
      *iTabNum = -1;
      return nullptr;
    }
    if ( m_iTabsNum >= this->m_arTabs.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arTabs.m_pData[m_iTabsNum];
  }
  while ( v3[13] == 0 );
  *iTabNum = m_iTabsNum;
  return (CWnd *)v3[8];
}

//------------------------------------------------------------------------------
// Address: 0x103DB0D1
// Name: protected: void CMFCBaseTabCtrl::OnSysColorChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::OnSysColorChange(CMFCBaseTabCtrl *this)
{
  CWnd::OnSysColorChange(this);
  this->InitAutoColors(this);
}

//------------------------------------------------------------------------------
// Address: 0x103DB0E6
// Name: public: virtual int CMFCBaseTabCtrl::IsColored(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::IsColored(CMFCBaseTabCtrl *this)
{
  int v2; // edi

  v2 = 0;
  if ( this->m_iTabsNum <= 0 )
    return 0;
  while ( this->GetTabBkColor(this, a2: v2) == -1 )
  {
    if ( ++v2 >= this->m_iTabsNum )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DB119
// Name: public: virtual int CMFCBaseTabCtrl::HasImage(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCBaseTabCtrl::HasImage(CMFCBaseTabCtrl *this, int iTab)
{
  _DWORD *v2; // esi

  if ( iTab < 0 || iTab >= this->m_iTabsNum )
    return false;
  if ( iTab >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  v2 = this->m_arTabs.m_pData[iTab];
  return v2[3] != 0 || this->GetImageList(this) != nullptr && v2[2] != -1;
}

//------------------------------------------------------------------------------
// Address: 0x103DB169
// Name: public: CList<struct CMFCRestoredTabInfo,struct CMFCRestoredTabInfo>::CList<struct CMFCRestoredTabInfo,struct CMFCRestoredTabInfo>(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo> *__thiscall CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo>::CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo>(
        CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo> *this,
        int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo>_vtbl *)&CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo>::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103DB191
// Name: void SerializeElements<struct CMFCRestoredTabInfo>(class CArchive __near &,struct CMFCRestoredTabInfo __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SerializeElements<CMFCRestoredTabInfo>(
        CArchive *ar,
        CMFCRestoredTabInfo *pElements,
        CMFCRestoredTabInfo *nCount)
{
  unsigned int v4; // edi
  int v5; // ebx
  int v6; // ebx
  CMFCRestoredTabInfo *pData; // [esp+10h] [ebp+10h]

  if ( nCount != nullptr && pElements == nullptr )
    AfxThrowInvalidArgException();
  v4 = (unsigned int)nCount;
  pData = pElements;
  if ( (ar->m_nMode & 1) != 0 )
  {
    if ( nCount != nullptr )
    {
      do
      {
        v6 = 89478485;
        if ( v4 < 0x5555555 )
          v6 = v4;
        CArchive::EnsureRead(this: ar, lpBuf: pData, nCount: 24 * v6);
        pData += v6;
        v4 -= v6;
      }
      while ( v4 != 0 );
    }
  }
  else if ( nCount != nullptr )
  {
    do
    {
      v5 = 89478485;
      if ( v4 < 0x5555555 )
        v5 = v4;
      CArchive::Write(this: ar, lpBuf: pData, nMax: 24 * v5);
      pData += v5;
      v4 -= v5;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DB236
// Name: public: virtual void CMFCBaseTabCtrl::AddTab(class CWnd __near *,char const __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::AddTab(
        CMFCBaseTabCtrl *this,
        CWnd *pNewWnd,
        const char *lpszName,
        unsigned int uiImageId,
        int bDetachable)
{
  CWnd *v6; // eax

  if ( pNewWnd == nullptr || pNewWnd->m_hWnd == nullptr || CWnd::GetDlgCtrlID(this: pNewWnd) != -1 )
  {
    v6 = this->CreateWrapper(this, a2: pNewWnd, a3: lpszName, a4: bDetachable);
    this->InsertTab_2(this, a2: v6, a3: lpszName, a4: -1, a5: uiImageId, a6: bDetachable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DB285
// Name: public: virtual int CMFCBaseTabCtrl::RemoveTab(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::RemoveTab(CMFCBaseTabCtrl *this, int iTab, int bRecalcLayout)
{
  int v3; // eax
  int m_iTabsNum; // ecx
  _DWORD *v7; // edi
  CToolTipCtrl *m_pToolTip; // ecx
  int m_iLastActiveTab; // eax
  CMFCBaseTabCtrl_vtbl *v10; // edx
  int v11; // edx
  int v12; // eax
  CMFCBaseTabCtrl_vtbl *v13; // eax
  int iActiveTab; // [esp+4h] [ebp-4h] BYREF

  v3 = iTab;
  if ( iTab >= 0 )
  {
    m_iTabsNum = this->m_iTabsNum;
    if ( iTab < m_iTabsNum )
    {
      if ( m_iTabsNum == 1 )
      {
        this->RemoveAllTabs(this);
        return 1;
      }
      if ( iTab < this->m_arTabs.m_nSize )
      {
        v7 = this->m_arTabs.m_pData[iTab];
        m_pToolTip = this->m_pToolTip;
        if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
        {
          CToolTipCtrl::DelTool(this: m_pToolTip, pWnd: this, nIDTool: v7[10]);
          v3 = iTab;
        }
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
          this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arTabs,
          nIndex: v3,
          nCount: 1);
        --this->m_iTabsNum;
        if ( this->m_bAutoDestroyWindow != 0 )
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v7[8] + 96))(a1: v7[8]);
        if ( v7 != nullptr )
          (*(void (__thiscall **)(_DWORD *, int))(*v7 + 4))(a1: v7, a2: 1);
        iActiveTab = this->m_iActiveTab;
        if ( iActiveTab < iTab )
          goto LABEL_18;
        if ( this->m_bActivateLastVisibleTab != 0 )
        {
          this->GetLastVisibleTab(this, a2: &iActiveTab);
LABEL_17:
          this->m_iActiveTab = -1;
LABEL_18:
          this->OnChangeTabs(this);
          if ( bRecalcLayout != 0 )
          {
            this->RecalcLayout(this);
            if ( iActiveTab != -1 )
            {
              if ( this->m_bActivateLastActiveTab == 0 || (m_iLastActiveTab = this->m_iLastActiveTab) == -1 )
              {
                v13 = this->__vftable;
                iTab = -1;
                v13->GetFirstVisibleTab(this, a2: iActiveTab, a3: &iTab);
              }
              else
              {
                if ( iTab < m_iLastActiveTab )
                  --m_iLastActiveTab;
                v10 = this->__vftable;
                iTab = -1;
                v10->GetFirstVisibleTab(this, a2: m_iLastActiveTab, a3: &iTab);
              }
              this->SetActiveTab(this, a2: iTab);
              this->FireChangeActiveTab(this, a2: this->m_iActiveTab);
            }
          }
          return 1;
        }
        v11 = this->m_iTabsNum;
        v12 = v11 - 1;
        if ( v11 - 1 < 0 )
          goto LABEL_17;
        while ( v12 >= 0 && v12 < this->m_arTabs.m_nSize )
        {
          if ( v12 >= iTab || iActiveTab < 0 || iActiveTab >= v11 )
          {
            if ( *((_DWORD *)this->m_arTabs.m_pData[v12] + 13) != 0 )
              iActiveTab = v12;
            if ( --v12 >= 0 )
              continue;
          }
          goto LABEL_17;
        }
      }
      AfxThrowInvalidArgException();
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103DB42F
// Name: public: virtual void CMFCBaseTabCtrl::RemoveAllTabs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::RemoveAllTabs(CMFCBaseTabCtrl *this)
{
  int v2; // eax
  _DWORD *v3; // edi
  CToolTipCtrl *m_pToolTip; // ecx

  this->m_iActiveTab = -1;
  this->m_nNextTabID = 1;
  while ( this->m_iTabsNum > 0 )
  {
    v2 = this->m_iTabsNum - 1;
    if ( v2 < 0 || v2 >= this->m_arTabs.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arTabs.m_pData[v2];
    m_pToolTip = this->m_pToolTip;
    this->m_iTabsNum = v2;
    if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
      CToolTipCtrl::DelTool(this: m_pToolTip, pWnd: this, nIDTool: v3[10]);
    if ( this->m_bAutoDestroyWindow != 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v3[8] + 96))(a1: v3[8]);
    if ( v3 != nullptr )
      (*(void (__thiscall **)(_DWORD *, int))(*v3 + 4))(a1: v3, a2: 1);
  }
  CUIntArray::SetSize(this: &this->m_arTabs, nNewSize: 0, nGrowBy: -1);
  this->OnChangeTabs(this);
  this->RecalcLayout(this);
  this->FireChangeActiveTab(this, a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x103DB4EC
// Name: public: virtual int CMFCBaseTabCtrl::GetTabFromHwnd(struct HWND__ __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::GetTabFromHwnd(CMFCBaseTabCtrl *this, HWND__ *hwnd)
{
  int v3; // edi
  int v4; // eax
  CObject *v5; // eax
  int v6; // eax

  v3 = 0;
  if ( this->m_iTabsNum <= 0 )
    return -1;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_arTabs.m_nSize )
      AfxThrowInvalidArgException();
    v4 = *((_DWORD *)this->m_arTabs.m_pData[v3] + 8);
    if ( v4 != 0 )
    {
      if ( *(HWND__ **)(v4 + 32) == hwnd )
        break;
      v5 = AfxDynamicDownCast(
             pClass: &CDockablePaneAdapter::classCDockablePaneAdapter,
             pObject: *((CObject **)this->m_arTabs.m_pData[v3] + 8));
      if ( v5 != nullptr )
      {
        v6 = (int)v5->__vftable[78].GetRuntimeClass(this: v5);
        if ( v6 != 0 && *(HWND__ **)(v6 + 32) == hwnd )
          break;
      }
    }
    if ( ++v3 >= this->m_iTabsNum )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103DB566
// Name: public: virtual int CMFCBaseTabCtrl::DetachTab(enum AFX_DOCK_METHOD,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __thiscall CMFCBaseTabCtrl::DetachTab(CMFCBaseTabCtrl *this, AFX_DOCK_METHOD dockMethod, int nTabNum, BOOL bHide)
{
  CPaneFrameWnd *v5; // esi
  CWnd *v6; // eax
  CWnd *v7; // esi
  int v8; // eax
  int v9; // ebx
  signed int v10; // eax
  signed int v11; // eax
  AFX_DOCK_TYPE v12; // eax
  HWND Parent; // eax
  CWnd *v14; // eax
  CObject *v15; // eax
  CDockablePane *v16; // ebx
  HWND v17; // eax
  CWnd *v18; // eax
  CMFCBaseTabCtrl_vtbl *v19; // eax
  CWnd *v20; // eax
  CDockablePane *v21; // esi
  int v22; // eax
  CWnd *v23; // eax
  HWND v24; // eax
  CWnd *v25; // eax
  HWND v26; // eax
  CWnd *v27; // eax
  HWND__ *cy; // ebx
  CPaneFrameWnd *v29; // edi
  HWND v31; // [esp-8h] [ebp-54h]
  HWND__ *m_hWnd; // [esp-4h] [ebp-50h]
  CPoint ptMouse; // [esp+Ch] [ebp-40h] BYREF
  AFX_DOCK_TYPE dockType; // [esp+14h] [ebp-38h]
  CSize hWndToDestroy; // [esp+18h] [ebp-34h] OVERLAPPED
  CPaneFrameWnd *pParentFrame; // [esp+20h] [ebp-2Ch]
  CWnd *pNewParent; // [esp+24h] [ebp-28h]
  CRect rectFloat; // [esp+28h] [ebp-24h] BYREF
  CRect rectWnd; // [esp+38h] [ebp-14h] BYREF

  v5 = (CPaneFrameWnd *)this->GetTabNumberToDetach(this, a2: nTabNum);
  pParentFrame = v5;
  if ( (int)v5 < 0 )
    return 0;
  if ( this->IsTabDetachable(this, a2: (int)v5) == 0 )
    return 0;
  v6 = this->GetTabWnd(this, a2: v5);
  v7 = (CWnd *)AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: v6);
  if ( v7 == nullptr )
    return 0;
  if ( ((int (__thiscall *)(CWnd *))v7->__vftable[1].CalcWindowRect)(a1: v7) == 0 )
    return 0;
  memset(&rectFloat, 0, sizeof(rectFloat));
  SetRectEmpty(lprc: &rectFloat);
  if ( ((int (__thiscall *)(CWnd *, CRect *, AFX_DOCK_METHOD))v7->__vftable[2].GetRuntimeClass)(
         a1: v7,
         a2: &rectFloat,
         a3: dockMethod) == 0 )
    return 0;
  if ( dockMethod == DM_MOUSE )
  {
    ptMouse.x = 0;
    ptMouse.y = 0;
    GetCursorPos(lpPoint: &ptMouse);
    v8 = this->m_ptHot.x - ptMouse.x;
    v9 = this->m_ptHot.y - ptMouse.y;
    hWndToDestroy = CDockablePane::m_sizeDragSensitivity;
    v10 = abs(lnumber: v8);
    if ( v10 < hWndToDestroy.cx )
    {
      v11 = abs(lnumber: v9);
      if ( v11 < hWndToDestroy.cy )
        return 0;
    }
  }
  if ( v7->__vftable[1].GetMessageMap(this: v7) == nullptr )
    return 0;
  v12 = ((int (__thiscall *)(CWnd *))v7->__vftable[1].Create)(a1: v7);
  m_hWnd = this->m_hWnd;
  dockType = v12;
  Parent = GetParent(hWnd: m_hWnd);
  v14 = CWnd::FromHandle(hWnd: Parent);
  v15 = AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: v14);
  v16 = (CDockablePane *)v15;
  if ( v15 != nullptr )
  {
    pNewParent = (CWnd *)((int (__thiscall *)(CObject *, _DWORD))v15->__vftable[45].Serialize)(a1: v15, a2: 0);
    if ( v16->CanFloat(this: &v16->CPane) != 0 || this->GetVisibleTabsNum(this) != 1 )
    {
      if ( CObject::IsKindOf(this: v7, pClass: &CDockablePane::classCDockablePane) != 0 )
        v7->__vftable[1].EndModalLoop(this: v7, a2: 1);
      if ( !bHide && (dockType & 2) != 0 )
        bHide = dockMethod == DM_MOUSE;
      if ( pParentFrame != (CPaneFrameWnd *)this->m_iActiveTab )
        CWnd::ShowWindow(this: v7, nCmdShow: 5);
      ((void (__thiscall *)(CDockablePane *, CWnd *, CPaneFrameWnd *, AFX_DOCK_METHOD, BOOL))v16->__vftable[1].GetDispatchIID)(
        a1: v16,
        a2: v7,
        a3: pParentFrame,
        a4: dockMethod,
        a5: bHide);
      if ( this->GetTabsNum(this) != 0 )
      {
        if ( this->GetVisibleTabsNum(this) == 0 )
          v16->ShowPane(this: &v16->CPane, a2: 0, a3: 0, a4: 0);
      }
      else if ( pNewParent != nullptr )
      {
        ((void (__thiscall *)(CWnd *, CDockablePane *, int, _DWORD))pNewParent->__vftable[1].GetDispatchIID)(
          a1: pNewParent,
          a2: v16,
          a3: 1,
          a4: 0);
      }
      else if ( ((int (__thiscall *)(CDockablePane *))v16->__vftable[1].OnFinalRelease)(a1: v16) != 0 )
      {
        v16->DestroyWindow(this: &v16->CPane);
      }
      else
      {
        CWnd::ShowWindow(this, nCmdShow: 0);
      }
      this->RecalcLayout(this);
      goto LABEL_30;
    }
    return 0;
  }
  pNewParent = nullptr;
LABEL_30:
  pParentFrame = (CPaneFrameWnd *)v7->__vftable[1].get_accFocus(this: v7, a2: nullptr);
  ptMouse.y = dockType & 2;
  if ( (dockType & 2) != 0 && dockMethod == DM_MOUSE && pParentFrame != nullptr )
  {
    ReleaseCapture();
    CWnd::SetFocus(this: pParentFrame);
    v17 = GetParent(hWnd: this->m_hWnd);
    v18 = CWnd::FromHandle(hWnd: v17);
    SendMessageA(hWnd: v18->m_hWnd, Msg: 0x363u, wParam: 0, lParam: 0);
  }
  v19 = this->__vftable;
  this->m_bReadyToDetach = 0;
  hWndToDestroy.cy = 0;
  if ( v19->GetTabsNum(this) == 1 && this->m_bHideSingleTab != 0 )
  {
    v31 = v16->m_hWnd;
    memset(&rectWnd, 0, sizeof(rectWnd));
    GetWindowRect(hWnd: v31, lpRect: &rectWnd);
    v20 = this->GetTabWnd(this, a2: 0);
    v21 = (CDockablePane *)AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: v20);
    CBasePane::InsertPane(this: &v16->CPane, pControlBar: &v21->CPane, pTarget: &v16->CPane, bAfter: 1);
    CDockablePane::ReplacePane(this: v16, pBarToReplaceWith: v21, __formal: dockMethod, bRegisterWithFrame: 0);
    hWndToDestroy.cy = (int)v21->__vftable;
    v22 = v16->GetCurrentAlignment(this: &v16->CPane);
    (*(void (__thiscall **)(CDockablePane *, int))(hWndToDestroy.cy + 476))(a1: v21, a2: v22);
    this->RemoveTab(this, a2: 0, a3: 1);
    v23 = pNewParent;
    if ( pNewParent == nullptr )
      v23 = v16->GetDockSiteFrameWnd(this: &v16->CPane);
    pNewParent = v23;
    v21->EnableGripper(this: &v21->CPane, a2: 1);
    CWnd::ScreenToClient(this: pNewParent, lpRect: (tagPOINT *)&rectWnd);
    CWnd::SetParent(this: &v21->CPane, pWndNewParent: pNewParent);
    v21->SetWindowPos(
      this: &v21->CPane,
      a2: nullptr,
      a3: rectWnd.left,
      a4: rectWnd.top,
      a5: rectWnd.right - rectWnd.left,
      a6: rectWnd.bottom - rectWnd.top,
      a7: 148u,
      a8: nullptr);
    v21->ShowPane(this: &v21->CPane, a2: 1, a3: 0, a4: 0);
    CWnd::ShowWindow(this: &v16->CPane, nCmdShow: 0);
    v24 = GetParent(hWnd: v21->m_hWnd);
    v25 = CWnd::FromHandle(hWnd: v24);
    InvalidateRect(hWnd: v25->m_hWnd, lpRect: nullptr, bErase: true);
    v26 = GetParent(hWnd: v21->m_hWnd);
    v27 = CWnd::FromHandle(hWnd: v26);
    UpdateWindow(hWnd: v27->m_hWnd);
    cy = v16->m_hWnd;
  }
  else
  {
    cy = (HWND__ *)hWndToDestroy.cy;
  }
  if ( dockMethod == DM_MOUSE )
  {
    v29 = pParentFrame;
    if ( pParentFrame != nullptr )
    {
      if ( ptMouse.y != 0 )
      {
        pParentFrame->EnterDragMode(this: pParentFrame, a2: cy);
        CPaneFrameWnd::MoveDragFrame(this: v29);
      }
      else if ( (dockType & 1) != 0 )
      {
        CWnd::SetFocus(this: pParentFrame);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DB990
// Name: protected: void CMFCBaseTabCtrl::OnRButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::OnRButtonDown(CMFCBaseTabCtrl *this, unsigned int nFlags, CPoint point)
{
  int v4; // eax
  CMFCBaseTabCtrl_vtbl *v5; // edx
  int v6; // eax
  CWnd *v7; // eax

  CWnd::Default(this);
  if ( this->m_bActivateTabOnRightClick == 0 )
    return;
  v4 = this->GetTabFromPoint(this, a2: &point);
  if ( v4 < 0 )
  {
    if ( v4 != this->m_iActiveTab )
      return;
  }
  else if ( v4 != this->m_iActiveTab )
  {
    v5 = this->__vftable;
    this->m_bSetActiveTabFired = 0;
    this->m_bSetActiveTabByMouseClick = 1;
    this->m_bUserSelectedTab = 0;
    v6 = v5->SetActiveTab(this, a2: v4);
    this->m_bSetActiveTabByMouseClick = 0;
    this->m_bUserSelectedTab = 0;
    if ( v6 != 0 )
    {
      if ( this->m_bSetActiveTabFired == 0 )
        this->FireChangeActiveTab(this, a2: this->m_iActiveTab);
      this->m_bSetActiveTabFired = 0;
    }
    return;
  }
  v7 = this->GetTabWnd(this, a2: v4);
  if ( v7 != nullptr && v7->m_hWnd != nullptr )
    CWnd::SetFocus(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x103DBA40
// Name: public: void CMFCBaseTabCtrl::EnterDragMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::EnterDragMode(CMFCBaseTabCtrl *this)
{
  HWND v2; // eax
  int m_iActiveTab; // [esp-8h] [ebp-28h]
  HWND__ *m_hWnd; // [esp-4h] [ebp-24h]
  CRect rectTab; // [esp+Ch] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  this->m_bReadyToDetach = 1;
  v2 = SetCapture(hWnd: m_hWnd);
  CWnd::FromHandle(hWnd: v2);
  GetCursorPos(lpPoint: &this->m_ptHot);
  m_iActiveTab = this->m_iActiveTab;
  memset(&rectTab, 0, sizeof(rectTab));
  this->GetTabRect(this, a2: m_iActiveTab, a3: &rectTab);
  this->m_iTabBeforeDrag = this->m_iActiveTab;
  CWnd::ClientToScreen(this, lpRect: (tagPOINT *)&rectTab);
  this->m_nOffsetFromTabLeft = this->m_ptHot.x - rectTab.left;
}

//------------------------------------------------------------------------------
// Address: 0x103DBAD0
// Name: protected: void CMFCBaseTabCtrl::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::OnLButtonDblClk(CMFCBaseTabCtrl *this, unsigned int nFlags, CPoint point)
{
  CMFCBaseTabCtrl_vtbl *v4; // eax
  int v5; // edi

  CWnd::Default(this);
  v4 = this->__vftable;
  if ( this->m_bIsInPlaceEdit != 0 )
  {
    v5 = v4->GetTabFromPoint(this, a2: &point);
    if ( v5 == this->GetActiveTab(this) )
      this->StartRenameTab(this, a2: v5);
  }
  else if ( v4->FindTargetWnd(this, a2: &point) == nullptr )
  {
    this->DetachTab(this, a2: DM_DBL_CLICK, a3: -1, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DBB32
// Name: public: void CMFCBaseTabCtrl::InvalidateTab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::InvalidateTab(CMFCBaseTabCtrl *this, int iTab)
{
  CRect rectTab; // [esp+4h] [ebp-14h] BYREF

  if ( iTab >= 0 )
  {
    memset(&rectTab, 0, sizeof(rectTab));
    if ( this->GetTabRect(this, a2: iTab, a3: &rectTab) != 0 )
    {
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectTab, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DBB96
// Name: public: virtual int CMFCBaseTabCtrl::StartRenameTab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::StartRenameTab(CMFCBaseTabCtrl *this, int iTab)
{
  HWND__ *m_hWnd; // esi
  const RECT *v4; // esi
  CWnd *v5; // edi
  CEdit *v6; // eax
  CMFCBaseTabCtrl_vtbl *v7; // eax
  int *p_top; // esi
  int v9; // eax
  CEdit *m_pInPlaceEdit; // ecx
  HWND v12; // eax
  HWND__ *v13; // [esp-4h] [ebp-40h]
  const char **v14; // [esp+14h] [ebp-28h]
  tagRECT rect; // [esp+1Ch] [ebp-20h] BYREF
  int v16; // [esp+38h] [ebp-4h]

  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( m_hWnd == nullptr )
LABEL_5:
    AfxThrowInvalidArgException();
  if ( this->m_bIsInPlaceEdit == 0 )
    return 0;
  if ( iTab < 0 )
    return 0;
  if ( iTab >= this->m_arTabs.m_nSize )
    return 0;
  v4 = (const RECT *)((char *)this->m_arTabs.m_pData[iTab] + 16);
  v14 = (const char **)this->m_arTabs.m_pData[iTab];
  if ( IsRectEmpty(lprc: v4) )
    return 0;
  if ( this->m_pInPlaceEdit != nullptr )
    goto LABEL_5;
  v5 = (CWnd *)operator new(nSize: 0x74u);
  v6 = nullptr;
  v16 = 0;
  if ( v5 != nullptr )
  {
    CWnd::CWnd(this: v5);
    v5->__vftable = (CWnd_vtbl *)&CEdit::`vftable';
    v6 = (CEdit *)v5;
  }
  v16 = -1;
  this->m_pInPlaceEdit = v6;
  v7 = this->__vftable;
  rect.left = v4->left;
  p_top = &v4->top;
  rect.top = *p_top++;
  rect.right = *p_top;
  rect.bottom = p_top[1];
  v7->CalcRectEdit(this, a2: (CRect *)&rect);
  v9 = CEdit::Create(this: this->m_pInPlaceEdit, dwStyle: 0x50800080u, &rect, pParentWnd: this, nID: 1u);
  m_pInPlaceEdit = this->m_pInPlaceEdit;
  if ( v9 == 0 )
  {
    if ( m_pInPlaceEdit != nullptr )
      ((void (__thiscall *)(CEdit *, int))m_pInPlaceEdit->dtr_CObject)(a1: m_pInPlaceEdit, a2: 1);
    this->m_pInPlaceEdit = nullptr;
    return 0;
  }
  CWnd::SetWindowTextA(this: m_pInPlaceEdit, lpszString: v14[1]);
  SendMessageA(
    hWnd: this->m_pInPlaceEdit->m_hWnd,
    Msg: 0x30u,
    wParam: (WPARAM)afxGlobalData.fontRegular.m_hObject,
    lParam: 1);
  SendMessageA(hWnd: this->m_pInPlaceEdit->m_hWnd, Msg: 0xB1u, wParam: 0, lParam: -1);
  CWnd::SetFocus(this: this->m_pInPlaceEdit);
  v13 = this->m_hWnd;
  this->m_iEditedTab = iTab;
  v12 = SetCapture(hWnd: v13);
  CWnd::FromHandle(hWnd: v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DBCF4
// Name: public: virtual int CMFCBaseTabCtrl::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::PreTranslateMessage(CMFCBaseTabCtrl *this, tagMSG *pMsg)
{
  CEdit *m_pInPlaceEdit; // eax
  unsigned int message; // ecx
  unsigned int wParam; // edi
  CEdit *v7; // ecx
  CPoint ptCursor; // [esp+Ch] [ebp-1Ch] BYREF
  CRect rectEdit; // [esp+14h] [ebp-14h] BYREF

  m_pInPlaceEdit = this->m_pInPlaceEdit;
  if ( m_pInPlaceEdit != nullptr )
  {
    message = pMsg->message;
    if ( message < 0x100 || message > 0x109 )
    {
      if ( message < 0x200 || message > 0x20E )
        return 0;
      memset(&rectEdit, 0, sizeof(rectEdit));
      GetClientRect(hWnd: m_pInPlaceEdit->m_hWnd, lpRect: &rectEdit);
      MapWindowPoints(
        hWndFrom: this->m_pInPlaceEdit->m_hWnd,
        hWndTo: this->m_hWnd,
        lpPoints: (LPPOINT)&rectEdit,
        cPoints: 2u);
      ptCursor = 0;
      GetCursorPos(lpPoint: &ptCursor);
      ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
      if ( PtInRect(lprc: &rectEdit, pt: ptCursor.tagPOINT) )
      {
        SendMessageA(hWnd: this->m_pInPlaceEdit->m_hWnd, Msg: pMsg->message, wParam: pMsg->wParam, lParam: pMsg->lParam);
        return 1;
      }
      if ( pMsg->message == 512 )
        return 1;
    }
    else
    {
      wParam = pMsg->wParam;
      if ( wParam != 13 )
      {
        if ( wParam != 27 )
          return 0;
        goto LABEL_10;
      }
      if ( this->RenameTab(this) == 0 )
      {
        MessageBeep(uType: 0xFFFFFFFF);
        return 1;
      }
    }
LABEL_10:
    this->m_pInPlaceEdit->DestroyWindow(this: this->m_pInPlaceEdit);
    v7 = this->m_pInPlaceEdit;
    if ( v7 != nullptr )
      ((void (__thiscall *)(CEdit *, int))v7->dtr_CObject)(a1: v7, a2: 1);
    this->m_iEditedTab = -1;
    this->m_pInPlaceEdit = nullptr;
    ReleaseCapture();
    return 1;
  }
  return CWnd::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103DBE4D
// Name: public: virtual void CMFCBaseTabCtrl::SetActiveTabColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::SetActiveTabColor(CMFCBaseTabCtrl *this, unsigned int clr)
{
  CBrush *p_m_brActiveTab; // edi
  COLORREF v4; // eax
  HBRUSH SolidBrush; // eax

  p_m_brActiveTab = &this->m_brActiveTab;
  this->m_clrActiveTabBk = clr;
  if ( this != (CMFCBaseTabCtrl *)-292 && this->m_brActiveTab.m_hObject != nullptr )
    CGdiObject::DeleteObject(this: &this->m_brActiveTab);
  v4 = this->GetActiveTabColor(this);
  SolidBrush = CreateSolidBrush(color: v4);
  CGdiObject::Attach(this: p_m_brActiveTab, hObject: SolidBrush);
}

//------------------------------------------------------------------------------
// Address: 0x103DBE95
// Name: public: virtual void CMFCBaseTabCtrl::ClearImageList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::ClearImageList(CMFCBaseTabCtrl *this)
{
  CImageList *p_m_Images; // ecx
  CMFCBaseTabCtrl_vtbl *v3; // eax

  p_m_Images = &this->m_Images;
  if ( p_m_Images != nullptr && p_m_Images->m_hImageList != nullptr )
    CImageList::DeleteImageList(this: p_m_Images);
  this->m_sizeImage.cx = 0;
  v3 = this->__vftable;
  this->m_sizeImage.cy = 0;
  v3->SetTabsHeight(this);
}

//------------------------------------------------------------------------------
// Address: 0x103DBECA
// Name: public: void CMFCBaseTabCtrl::ResetImageList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::ResetImageList(CMFCBaseTabCtrl *this)
{
  this->ClearImageList(this);
  this->m_hImageList = nullptr;
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapAddedIcons);
}

//------------------------------------------------------------------------------
// Address: 0x103DBEEA
// Name: public: virtual void CMFCBaseTabCtrl::HideSingleTab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::HideSingleTab(CMFCBaseTabCtrl *this, int bHide)
{
  bool v2; // zf

  if ( this->m_bHideSingleTab != bHide )
  {
    v2 = this->m_hWnd == nullptr;
    this->m_bHideSingleTab = bHide;
    if ( !v2 )
      this->RecalcLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DBF12
// Name: public: void CMFCBaseTabCtrl::SetDrawNoPrefix(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::SetDrawNoPrefix(CMFCBaseTabCtrl *this, int bNoPrefix, int bRedraw)
{
  HWND__ *m_hWnd; // ecx

  this->m_bLabelNoPrefix = bNoPrefix;
  if ( bRedraw != 0 )
  {
    m_hWnd = this->m_hWnd;
    if ( m_hWnd != nullptr )
      RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DBF40
// Name: protected: int CMFCBaseTabCtrl::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::OnCreate(CMFCBaseTabCtrl *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    if ( AFXGetParentFrame(pWnd: this) == nullptr )
      this->m_bEnableWrapping = 0;
    if ( AfxGetThreadState()->m_bNeedTerm != 0 )
    {
      this->m_DropTarget.m_pOwner = this;
      COleDropTarget::Register(this: &this->m_DropTarget, pWnd: this);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DBF84
// Name: public: virtual class CSize CMFCBaseTabCtrl::GetMaxWindowSize(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCBaseTabCtrl::GetMaxWindowSize(CMFCBaseTabCtrl *this, CSize *result)
{
  int v2; // edx
  CMFCBaseTabCtrl *v3; // eax
  int m_nSize; // ecx
  int cx; // ebx
  void *v6; // esi
  CObject *v7; // ecx
  CObject *v8; // eax
  int *v9; // eax
  int cy; // eax
  _BYTE v12[8]; // [esp+4h] [ebp-30h] BYREF
  CMFCBaseTabCtrl *v13; // [esp+Ch] [ebp-28h]
  int nTabCount; // [esp+10h] [ebp-24h]
  CSize sizeCurr; // [esp+14h] [ebp-20h]
  int i; // [esp+1Ch] [ebp-18h]
  CRect rectWnd; // [esp+20h] [ebp-14h] BYREF

  v2 = 0;
  v3 = this;
  result->cx = 0;
  result->cy = 0;
  m_nSize = this->m_arTabs.m_nSize;
  v13 = v3;
  nTabCount = m_nSize;
  i = 0;
  if ( m_nSize > 0 )
  {
    do
    {
      cx = 0;
      if ( v2 < 0 || v2 >= v3->m_arTabs.m_nSize )
        AfxThrowInvalidArgException();
      v6 = v3->m_arTabs.m_pData[v2];
      v7 = *((CObject **)v6 + 8);
      if ( v7 != nullptr )
      {
        sizeCurr.cy = 0;
        if ( CObject::IsKindOf(this: v7, pClass: &CBasePane::classCBasePane) != 0 )
        {
          v8 = AfxDynamicDownCast(pClass: &CBasePane::classCBasePane, pObject: *((CObject **)v6 + 8));
          if ( v8 != nullptr )
          {
            v9 = (int *)((int (__thiscall *)(CObject *, _BYTE *, _DWORD, int))v8->__vftable[50].dtr_CObject)(
                          a1: v8,
                          a2: v12,
                          a3: 0,
                          a4: 1);
            cx = *v9;
            sizeCurr.cy = v9[1];
          }
        }
        else
        {
          memset(&rectWnd, 0, sizeof(rectWnd));
          GetWindowRect(hWnd: *(HWND *)(*((_DWORD *)v6 + 8) + 32), lpRect: &rectWnd);
          cx = rectWnd.right - rectWnd.left;
          sizeCurr.cy = rectWnd.bottom - rectWnd.top;
        }
        if ( cx <= result->cx )
          cx = result->cx;
        cy = result->cy;
        result->cx = cx;
        if ( sizeCurr.cy > cy )
          cy = sizeCurr.cy;
        v2 = i;
        result->cy = cy;
        v3 = v13;
      }
      i = ++v2;
    }
    while ( v2 < nTabCount );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DC096
// Name: public: void CMFCBaseTabCtrl::EnableAutoColor(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::EnableAutoColor(CMFCBaseTabCtrl *this, int bEnable)
{
  int i; // eax
  CMFCBaseTabCtrl_vtbl *v4; // eax
  HWND__ *m_hWnd; // esi

  if ( this->m_bIsAutoColor != 0 && bEnable == 0 )
  {
    for ( i = 0; i < this->m_iTabsNum; ++i )
    {
      if ( i < 0 || i >= this->m_arTabs.m_nSize )
        AfxThrowInvalidArgException();
      *((_DWORD *)this->m_arTabs.m_pData[i] + 12) = -1;
    }
  }
  v4 = this->__vftable;
  this->m_bIsAutoColor = bEnable;
  v4->InitAutoColors(this);
  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x103DC10C
// Name: public: virtual void CMFCBaseTabCtrl::SetLocation(enum CMFCBaseTabCtrl::Location)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::SetLocation(CMFCBaseTabCtrl *this, CMFCBaseTabCtrl::Location location)
{
  HWND__ *m_hWnd; // esi
  HWND Parent; // eax
  CWnd *v5; // eax

  this->m_location = location;
  this->RecalcLayout(this);
  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
  {
    Parent = GetParent(hWnd: m_hWnd);
    v5 = CWnd::FromHandle(hWnd: Parent);
    RedrawWindow(hWnd: v5->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x185u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DC150
// Name: public: virtual void CMFCBaseTabCtrl::FireChangeActiveTab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::FireChangeActiveTab(CMFCBaseTabCtrl *this, WPARAM nNewTab)
{
  CFrameWnd *TopLevelFrame; // eax
  HWND Parent; // eax
  CWnd *v5; // ebx
  CFrameWnd *pParentFrame; // [esp+Ch] [ebp-4h]

  TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
  if ( g_pTopLevelFrame == nullptr )
    TopLevelFrame = CWnd::GetTopLevelFrame(this);
  pParentFrame = TopLevelFrame;
  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  SendMessageA(hWnd: v5->m_hWnd, Msg: AFX_WM_CHANGE_ACTIVE_TAB, wParam: nNewTab, lParam: (LPARAM)this);
  if ( v5 != pParentFrame && pParentFrame != nullptr )
    SendMessageA(hWnd: pParentFrame->m_hWnd, Msg: AFX_WM_CHANGE_ACTIVE_TAB, wParam: nNewTab, lParam: (LPARAM)this);
  this->m_bSetActiveTabFired = 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DC1BD
// Name: public: virtual int CMFCBaseTabCtrl::FireChangingActiveTab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::FireChangingActiveTab(CMFCBaseTabCtrl *this, WPARAM nNewTab)
{
  CFrameWnd *TopLevelFrame; // eax
  HWND Parent; // eax
  CWnd *v5; // ebx
  int result; // eax
  CFrameWnd *pParentFrame; // [esp+Ch] [ebp-4h]

  TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
  if ( g_pTopLevelFrame == nullptr )
    TopLevelFrame = CWnd::GetTopLevelFrame(this);
  pParentFrame = TopLevelFrame;
  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  result = SendMessageA(hWnd: v5->m_hWnd, Msg: AFX_WM_CHANGING_ACTIVE_TAB, wParam: nNewTab, lParam: (LPARAM)this);
  if ( result != 0 )
    return 1;
  if ( v5 != pParentFrame && pParentFrame != nullptr )
    return SendMessageA(
             hWnd: pParentFrame->m_hWnd,
             Msg: AFX_WM_CHANGING_ACTIVE_TAB,
             wParam: nNewTab,
             lParam: (LPARAM)this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DC229
// Name: public: virtual void CMFCBaseTabCtrl::SetTabBorderSize(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::SetTabBorderSize(CMFCBaseTabCtrl *this, int nTabBorderSize, int bRepaint)
{
  int v4; // ecx
  CMFCBaseTabCtrl_vtbl *v5; // eax
  HWND__ *m_hWnd; // eax

  v4 = nTabBorderSize;
  if ( nTabBorderSize == -1 )
    v4 = 2;
  if ( this->m_nTabBorderSize != v4 )
  {
    v5 = this->__vftable;
    this->m_nTabBorderSize = v4;
    v5->RecalcLayout(this);
    if ( bRepaint != 0 )
    {
      m_hWnd = this->m_hWnd;
      if ( m_hWnd != nullptr )
      {
        InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
        UpdateWindow(hWnd: this->m_hWnd);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DC27A
// Name: public: int CMFCBaseTabCtrl::EnableCustomToolTips(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::EnableCustomToolTips(CMFCBaseTabCtrl *this, int bEnable)
{
  CToolTipCtrl *m_pToolTip; // eax
  int v4; // ebx
  void *v5; // edi
  CToolTipCtrl *v6; // ecx
  CToolInfo info; // [esp+4h] [ebp-134h] BYREF

  if ( this->m_bCustomToolTips != bEnable )
  {
    this->m_bCustomToolTips = bEnable;
    m_pToolTip = this->m_pToolTip;
    v4 = 0;
    if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
    {
      if ( this->m_iTabsNum > 0 )
      {
        do
        {
          if ( v4 < 0 || v4 >= this->m_arTabs.m_nSize )
            AfxThrowInvalidArgException();
          v5 = this->m_arTabs.m_pData[v4];
          v6 = this->m_pToolTip;
          if ( this->m_bCustomToolTips != 0 )
          {
            CToolTipCtrl::GetToolInfo(this: v6, ToolInfo: &info, pWnd: this, nIDTool: *((_DWORD *)v5 + 10));
            CToolTipCtrl::DelTool(this: this->m_pToolTip, pWnd: this, nIDTool: *((_DWORD *)v5 + 10));
            CToolTipCtrl::AddTool(
              this: this->m_pToolTip,
              pWnd: this,
              lpszText: (char *)0xFFFFFFFF,
              lpRectTool: &info.rect,
              nIDTool: *((_DWORD *)v5 + 10));
          }
          else
          {
            CToolTipCtrl::UpdateTipText(
              this: v6,
              lpszText: *((char **)v5 + 1),
              pWnd: this,
              nIDTool: *((_DWORD *)v5 + 10));
          }
          ++v4;
        }
        while ( v4 < this->m_iTabsNum );
      }
      this->RecalcLayout(this);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DC368
// Name: protected: void CMFCBaseTabCtrl::OnWindowPosChanged(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::OnWindowPosChanged(CMFCBaseTabCtrl *this, tagWINDOWPOS *lpwndpos)
{
  CWnd::Default(this);
  this->m_bWindowPosChanged = 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DC380
// Name: protected: void CMFCBaseTabCtrl::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::OnLButtonDown(CMFCBaseTabCtrl *this, unsigned int nFlags, CPoint point)
{
  BOOL v4; // ebx
  int v5; // ebx
  int m_iActiveTab; // eax
  CMFCBaseTabCtrl_vtbl *v7; // eax
  CWnd *v8; // eax
  int v9; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-20h]
  int iTab; // [esp+Ch] [ebp-4h]

  this->m_bWindowPosChanged = 0;
  CWnd::Default(this);
  if ( PtInRect(lprc: &this->m_rectCloseButton, pt: point.tagPOINT) )
  {
    m_hWnd = this->m_hWnd;
    this->m_bTabCloseButtonPressed = 1;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: &this->m_rectCloseButton, hrgnUpdate: nullptr, flags: 0x105u);
    return;
  }
  iTab = this->GetTabFromPoint(this, a2: &point);
  this->m_iHighlighted = iTab;
  if ( iTab >= 0 )
  {
    v4 = false;
    if ( this->ActivateOnBtnUp(this) != 0 )
    {
      this->m_iPressed = this->m_iHighlighted;
    }
    else
    {
      v5 = this->GetTabFromPoint(this, a2: &point);
      if ( v5 < 0 || (m_iActiveTab = this->m_iActiveTab, v5 == m_iActiveTab) )
      {
        if ( v5 == this->m_iActiveTab )
        {
          v8 = this->GetTabWnd(this, a2: v5);
          if ( v8 != nullptr && v8->m_hWnd != nullptr )
            CWnd::SetFocus(this: v8);
        }
      }
      else
      {
        this->m_bSetActiveTabFired = 0;
        this->m_iLastActiveTab = m_iActiveTab;
        v7 = this->__vftable;
        this->m_bSetActiveTabByMouseClick = 1;
        this->m_bUserSelectedTab = 1;
        if ( v7->SetActiveTab(this, a2: v5) == 0 )
        {
          this->m_bSetActiveTabFired = 1;
          this->m_bSetActiveTabByMouseClick = 0;
          this->m_bUserSelectedTab = 0;
          this->m_bWindowPosChanged = 0;
          return;
        }
        this->m_bSetActiveTabByMouseClick = 0;
        this->m_bUserSelectedTab = 0;
        if ( this->m_bSetActiveTabFired == 0 )
          this->FireChangeActiveTab(this, a2: this->m_iActiveTab);
        this->m_bSetActiveTabFired = 0;
      }
      v9 = this->GetTabFromPoint(this, a2: &point);
      this->m_iHighlighted = -1;
      v4 = v5 != v9;
      ReleaseCapture();
    }
    if ( iTab != this->m_iActiveTab )
      CMFCBaseTabCtrl::InvalidateTab(this, iTab);
    if ( !v4 && this->m_bWindowPosChanged == 0 )
      CMFCBaseTabCtrl::EnterDragMode(this);
  }
  this->m_bWindowPosChanged = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103DC522
// Name: protected: void CMFCBaseTabCtrl::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::OnLButtonUp(CMFCBaseTabCtrl *this, unsigned int nFlags, CPoint point)
{
  CWnd *v4; // eax
  HWND Parent; // eax
  CFrameWnd *v6; // eax
  int m_iHighlighted; // eax
  int m_iActiveTab; // ecx
  CMFCBaseTabCtrl_vtbl *v9; // edx
  bool v10; // zf
  CMFCBaseTabCtrl_vtbl *v11; // eax
  int m_iPressed; // eax
  int v13; // edi
  CMFCBaseTabCtrl_vtbl *v14; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-48h]
  CWnd *iPressed; // [esp+Ch] [ebp-2Ch]
  int iPresseda; // [esp+Ch] [ebp-2Ch]
  bool bNewActiveTab; // [esp+13h] [ebp-25h]
  CRect rectTabAreaBottom; // [esp+14h] [ebp-24h] BYREF
  CRect rectTabAreaTop; // [esp+24h] [ebp-14h] BYREF

  if ( this->m_bTabCloseButtonPressed != 0 )
  {
    m_hWnd = this->m_hWnd;
    this->m_bTabCloseButtonPressed = 0;
    this->m_bTabCloseButtonHighlighted = 0;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: &this->m_rectCloseButton, hrgnUpdate: nullptr, flags: 0x105u);
    if ( PtInRect(lprc: &this->m_rectCloseButton, pt: point.tagPOINT) )
    {
      v4 = this->GetActiveWnd(this);
      if ( v4 != nullptr )
        SendMessageA(hWnd: v4->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
      return;
    }
  }
  if ( this->m_iTabBeforeDrag != this->m_iActiveTab )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    iPressed = CWnd::FromHandle(hWnd: Parent);
    SendMessageA(
      hWnd: iPressed->m_hWnd,
      Msg: AFX_WM_ON_MOVE_TAB,
      wParam: this->m_iTabBeforeDrag,
      lParam: this->m_iActiveTab);
    if ( CObject::IsKindOf(this: iPressed, pClass: &CBaseTabbedPane::classCBaseTabbedPane) != 0
      || CObject::IsKindOf(this: iPressed, pClass: &CMDIClientAreaWnd::classCMDIClientAreaWnd) != 0 )
    {
      v6 = AFXGetParentFrame(pWnd: iPressed);
      if ( v6 != nullptr )
        SendMessageA(
          hWnd: v6->m_hWnd,
          Msg: AFX_WM_ON_MOVE_TAB,
          wParam: this->m_iTabBeforeDrag,
          lParam: this->m_iActiveTab);
    }
  }
  if ( this->m_bReadyToDetach != 0 )
  {
    this->m_bReadyToDetach = 0;
    ReleaseCapture();
    if ( this->ActivateOnBtnUp(this) == 0 )
    {
      this->m_iPressed = -1;
      this->m_iHighlighted = -1;
    }
  }
  if ( this->ActivateOnBtnUp(this) != 0 )
  {
    m_iHighlighted = this->m_iHighlighted;
    m_iActiveTab = this->m_iActiveTab;
    bNewActiveTab = m_iActiveTab != m_iHighlighted;
    if ( m_iHighlighted == this->m_iPressed && m_iHighlighted >= 0 && m_iHighlighted != m_iActiveTab )
    {
      v9 = this->__vftable;
      this->m_iLastActiveTab = m_iActiveTab;
      this->m_bSetActiveTabByMouseClick = 1;
      this->m_bUserSelectedTab = 0;
      v10 = v9->SetActiveTab(this, a2: m_iHighlighted) == 0;
      v11 = this->__vftable;
      if ( v10 )
      {
        this->m_iPressed = -1;
        this->m_bSetActiveTabByMouseClick = 0;
        this->m_bUserSelectedTab = 0;
        if ( v11->IsOneNoteStyle(this) == 0 )
          this->m_iHighlighted = -1;
        ReleaseCapture();
        return;
      }
      v11->FireChangeActiveTab(this, a2: this->m_iActiveTab);
      this->m_bSetActiveTabByMouseClick = 0;
      this->m_bUserSelectedTab = 0;
    }
    m_iPressed = this->m_iPressed;
    v13 = this->m_iHighlighted;
    this->m_iPressed = -1;
    iPresseda = m_iPressed;
    if ( this->IsOneNoteStyle(this) == 0 )
      this->m_iHighlighted = -1;
    ReleaseCapture();
    if ( bNewActiveTab )
    {
      CMFCBaseTabCtrl::InvalidateTab(this, iTab: v13);
      if ( iPresseda != v13 )
        CMFCBaseTabCtrl::InvalidateTab(this, iTab: iPresseda);
    }
  }
  if ( this->IsOneNoteStyle(this) != 0 )
  {
    v14 = this->__vftable;
    memset(&rectTabAreaTop, 0, sizeof(rectTabAreaTop));
    memset(&rectTabAreaBottom, 0, sizeof(rectTabAreaBottom));
    v14->GetTabArea(this, a2: &rectTabAreaTop, a3: &rectTabAreaBottom);
    if ( !IsRectEmpty(lprc: &rectTabAreaTop) )
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectTabAreaTop, bErase: false);
    if ( !IsRectEmpty(lprc: &rectTabAreaBottom) )
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectTabAreaBottom, bErase: false);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103DC7CD
// Name: protected: void CMFCBaseTabCtrl::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::OnMouseMove(CMFCBaseTabCtrl *this, char nFlags, CPoint point)
{
  int m_bTabCloseButtonHighlighted; // edi
  int v5; // eax
  HWND v6; // eax
  CWnd *v7; // eax
  int v8; // eax
  int m_iPressed; // ecx
  int y; // ebx
  HWND v11; // eax
  int m_iTabsNum; // ebx
  CMFCBaseTabCtrl_vtbl *v13; // eax
  int v14; // edi
  int v15; // [esp-4h] [ebp-2Ch]
  tagPOINT Point; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD v17[2]; // [esp+14h] [ebp-14h] BYREF
  CPoint pt; // [esp+1Ch] [ebp-Ch] BYREF

  CWnd::Default(this);
  m_bTabCloseButtonHighlighted = this->m_bTabCloseButtonHighlighted;
  Point.y = this->m_iHighlighted;
  v5 = PtInRect(lprc: &this->m_rectCloseButton, pt: point.tagPOINT);
  this->m_bTabCloseButtonHighlighted = v5;
  if ( m_bTabCloseButtonHighlighted != v5 )
  {
    if ( v5 != 0 )
      this->m_bTabCloseButtonPressed = nFlags & 1;
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: &this->m_rectCloseButton, hrgnUpdate: nullptr, flags: 0x105u);
  }
  if ( this->m_iHighlighted < 0
    || this->m_iPressed >= 0
    || this->m_bReadyToDetach != 0
    || (pt = point,
        ClientToScreen(hWnd: this->m_hWnd, lpPoint: &pt),
        v6 = WindowFromPoint(Point: pt.tagPOINT),
        (v7 = CWnd::FromHandle(hWnd: v6)) == nullptr)
    || v7->m_hWnd == this->m_hWnd )
  {
    v8 = this->GetTabFromPoint(this, a2: &point);
    m_iPressed = this->m_iPressed;
    this->m_iHighlighted = v8;
    if ( m_iPressed >= 0 && v8 != m_iPressed )
      this->m_iHighlighted = -1;
    y = Point.y;
    if ( this->m_iHighlighted != Point.y && (this->m_bHighLightTabs != 0 || this->IsActiveTabCloseButton(this) != 0) )
    {
      if ( Point.y >= 0 )
      {
        if ( this->m_iHighlighted < 0 && this->m_iPressed < 0 )
        {
          this->m_bTabCloseButtonHighlighted = 0;
          this->m_bTabCloseButtonPressed = 0;
          if ( this->m_bReadyToDetach == 0 )
            ReleaseCapture();
        }
      }
      else if ( this->m_iHighlighted >= 0 )
      {
        v11 = SetCapture(hWnd: this->m_hWnd);
        CWnd::FromHandle(hWnd: v11);
      }
      CMFCBaseTabCtrl::InvalidateTab(this, iTab: this->m_iHighlighted);
      CMFCBaseTabCtrl::InvalidateTab(this, iTab: y);
    }
    if ( this->m_bReadyToDetach != 0 )
    {
      m_iTabsNum = this->m_iTabsNum;
      if ( ((int (__thiscall *)(CMFCBaseTabCtrl *, int, int))this->IsPtInTabArea)(a1: this, a2: point.x, a3: point.y) != 0
        && m_iTabsNum > 1
        && this->m_bEnableTabSwap != 0 )
      {
        v13 = this->__vftable;
        v17[0] = 0;
        v17[1] = 0;
        pt.x = 0;
        pt.y = 0;
        v14 = v13->GetTabFromPoint(this, a2: &point);
        if ( v14 != this->m_iActiveTab && v14 != -1 )
        {
          this->SwapTabs(this, a2: v14, a3: this->m_iActiveTab);
          this->RecalcLayout(this);
          this->SetActiveTab(this, a2: v14);
          if ( this->GetTabFromPoint(this, a2: &point) != v14 )
          {
            this->GetTabRect(this, a2: v14, a3: (CRect *)v17);
            Point = point.tagPOINT;
            Point.x = v17[0] + this->m_nOffsetFromTabLeft;
            ClientToScreen(hWnd: this->m_hWnd, lpPoint: &Point);
            SetCursorPos(X: Point.x, Y: Point.y);
          }
        }
      }
      else if ( ((int (__thiscall *)(CMFCBaseTabCtrl *, int, int))this->IsPtInTabArea)(
                  a1: this,
                  a2: point.x,
                  a3: point.y) == 0
             && this->DetachTab(this, a2: DM_MOUSE, a3: -1, a4: 0) != 0
             && m_iTabsNum > 2 )
      {
        this->m_bReadyToDetach = 0;
      }
    }
  }
  else
  {
    ReleaseCapture();
    v15 = Point.y;
    this->m_iHighlighted = -1;
    CMFCBaseTabCtrl::InvalidateTab(this, iTab: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DCA73
// Name: protected: void CMFCBaseTabCtrl::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::OnCancelMode(CMFCBaseTabCtrl *this)
{
  int m_iHighlighted; // ebx
  CEdit *m_pInPlaceEdit; // ecx
  CEdit *v4; // ecx
  HWND__ *m_hWnd; // [esp-10h] [ebp-14h]

  CWnd::Default(this);
  if ( this->m_bTabCloseButtonPressed != 0 || this->m_bTabCloseButtonHighlighted != 0 )
  {
    m_hWnd = this->m_hWnd;
    this->m_bTabCloseButtonPressed = 0;
    this->m_bTabCloseButtonHighlighted = 0;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: &this->m_rectCloseButton, hrgnUpdate: nullptr, flags: 0x105u);
  }
  m_iHighlighted = this->m_iHighlighted;
  if ( m_iHighlighted >= 0 )
  {
    ReleaseCapture();
    this->m_iHighlighted = -1;
    this->m_iPressed = -1;
    CMFCBaseTabCtrl::InvalidateTab(this, iTab: m_iHighlighted);
  }
  m_pInPlaceEdit = this->m_pInPlaceEdit;
  if ( m_pInPlaceEdit != nullptr )
  {
    m_pInPlaceEdit->DestroyWindow(this: m_pInPlaceEdit);
    v4 = this->m_pInPlaceEdit;
    if ( v4 != nullptr )
      ((void (__thiscall *)(CEdit *, int))v4->dtr_CObject)(a1: v4, a2: 1);
    this->m_pInPlaceEdit = nullptr;
    this->m_iEditedTab = -1;
    ReleaseCapture();
  }
  this->m_bReadyToDetach = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103DCB18
// Name: public: int CMFCBaseTabCtrl::SetTabsOrder(class CArray<int,int> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::SetTabsOrder(CMFCBaseTabCtrl *this, const CArray<int,int> *arOrder)
{
  int v4; // ebx
  int v5; // eax
  int v6; // edi
  CPtrArray arTabsSaved; // [esp+10h] [ebp-28h] BYREF
  int bActiveTabIsChamged; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  int v10; // [esp+34h] [ebp-4h]

  if ( arOrder->m_nSize != this->m_iTabsNum )
    return 0;
  CPtrArray::CPtrArray(this: &arTabsSaved);
  v4 = 0;
  v10 = 0;
  if ( this->m_iTabsNum > 0 )
  {
    while ( v4 >= 0 && v4 < this->m_arTabs.m_nSize )
    {
      CUIntArray::SetAtGrow(this: &arTabsSaved, nIndex: arTabsSaved.m_nSize, newElement: this->m_arTabs.m_pData[v4++]);
      if ( v4 >= this->m_iTabsNum )
        goto LABEL_7;
    }
LABEL_9:
    AfxThrowInvalidArgException();
  }
LABEL_7:
  CUIntArray::SetSize(this: &this->m_arTabs, nNewSize: 0, nGrowBy: -1);
  v5 = 0;
  bActiveTabIsChamged = 0;
  i = 0;
  if ( this->m_iTabsNum > 0 )
  {
    while ( v5 >= 0 )
    {
      if ( v5 >= arOrder->m_nSize )
        break;
      v6 = arOrder->m_pData[v5];
      if ( v6 < 0 || v6 >= arTabsSaved.m_nSize )
        break;
      CUIntArray::SetAtGrow(this: &this->m_arTabs, nIndex: this->m_arTabs.m_nSize, newElement: arTabsSaved.m_pData[v6]);
      if ( v6 == this->m_iActiveTab && bActiveTabIsChamged == 0 )
      {
        this->m_iActiveTab = i;
        bActiveTabIsChamged = 1;
      }
      if ( ++i >= this->m_iTabsNum )
        goto LABEL_19;
      v5 = i;
    }
    goto LABEL_9;
  }
LABEL_19:
  v10 = -1;
  CPtrArray::~CPtrArray(this: &arTabsSaved);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DCC22
// Name: public: virtual unsigned long CMFCBaseTabCtrl::GetTabBkColor(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCBaseTabCtrl::GetTabBkColor(CMFCBaseTabCtrl *this, int iTab)
{
  void **m_pData; // edx
  _DWORD *v4; // edi
  unsigned int v5; // esi
  _DWORD *v6; // ebx
  int m_nSize; // esi
  int v8; // edx
  int iTaba; // [esp+8h] [ebp+8h]

  if ( iTab >= 0 && iTab < this->m_iTabsNum )
  {
    if ( iTab >= this->m_arTabs.m_nSize )
      goto LABEL_21;
    m_pData = this->m_arTabs.m_pData;
    v4 = m_pData[iTab];
    v5 = v4[12];
    v6 = nullptr;
    if ( iTab > 0 )
    {
      iTaba = iTab - 1;
      if ( iTab - 1 < 0 || iTaba >= this->m_arTabs.m_nSize )
        goto LABEL_21;
      v6 = m_pData[iTaba];
    }
    if ( v5 != -1 || this->m_bIsAutoColor == 0 )
      return v5;
    m_nSize = this->m_arAutoColors.m_nSize;
    v8 = iTab % m_nSize;
    if ( iTab % m_nSize == nLastColorIndexUsed )
      v8 = ++nCyclicalColor % m_nSize;
    if ( v6 != nullptr )
    {
      if ( v8 < 0 || v8 >= m_nSize )
        goto LABEL_21;
      if ( v6[12] == this->m_arAutoColors.m_pData[v8] )
        v8 = ++nCyclicalColor % m_nSize;
    }
    if ( v8 >= 0 && v8 < m_nSize )
    {
      v5 = this->m_arAutoColors.m_pData[v8];
      v4[12] = v5;
      nLastColorIndexUsed = v8;
      return v5;
    }
LABEL_21:
    AfxThrowInvalidArgException();
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103DCD00
// Name: public: virtual int CMFCBaseTabCtrl::SetImageList(struct _IMAGELIST __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseTabCtrl::SetImageList(CMFCBaseTabCtrl *this, struct _IMAGELIST *hImageList)
{
  CImageList *p_m_Images; // ecx
  int result; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  int v6; // ecx
  CMFCBaseTabCtrl_vtbl *v7; // eax
  struct _IMAGELIST *v8; // [esp-Ch] [ebp-48h]
  _IMAGEINFO info; // [esp+8h] [ebp-34h] BYREF
  CRect rectImage; // [esp+28h] [ebp-14h] BYREF

  if ( hImageList == nullptr )
    AfxThrowInvalidArgException();
  p_m_Images = &this->m_Images;
  if ( this != (CMFCBaseTabCtrl *)-168 && this->m_Images.m_hImageList != nullptr )
    CImageList::DeleteImageList(this: p_m_Images);
  result = (int)CImageList::FromHandle(h: hImageList);
  if ( result != 0 )
  {
    v8 = *(struct _IMAGELIST **)(result + 4);
    ModuleState = AfxGetModuleState();
    CComCtlWrapper::_ImageList_GetImageInfo(
      this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
      himl: v8,
      i: 0,
      pImageInfo: &info);
    CopyRect(lprcDst: &rectImage, lprcSrc: &info.rcImage);
    v6 = rectImage.bottom - rectImage.top;
    this->m_sizeImage.cx = rectImage.right - rectImage.left;
    v7 = this->__vftable;
    this->m_sizeImage.cy = v6;
    this->m_hImageList = hImageList;
    v7->SetTabsHeight(this);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DCDA3
// Name: protected: virtual void CMFCBaseTabCtrl::InitAutoColors(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::InitAutoColors(CMFCBaseTabCtrl *this)
{
  CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *p_m_arAutoColors; // esi

  if ( this->m_bIsDefaultAutoColor != 0 )
  {
    p_m_arAutoColors = (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arAutoColors;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arAutoColors,
      nNewSize: 0,
      nGrowBy: -1);
    if ( afxGlobalData.m_nBitsPerPixel <= 8 )
    {
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xFF00);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xFFFF00);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xFF00FF);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xC0C0C0);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xFFFF);
    }
    else
    {
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xF2D4C5);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0x78DCFF);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xA1CEBE);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xA1A0F0);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xE1A8BC);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xB6C19C);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0x86B8F7);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xC2ADD9);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xD7C2A5);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xBEA6B3);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xA3D6EA);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0x7DFAF6);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0x9DE9B5);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xCFC35F);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0x8383C1);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: p_m_arAutoColors,
        nIndex: p_m_arAutoColors->m_nSize,
        newElement: (CMFCRibbonKeyTip *)0xD5CACA);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DCF02
// Name: public: void CMFCBaseTabCtrl::SetAutoColors(class CArray<unsigned long,unsigned long> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseTabCtrl::SetAutoColors(
        CMFCBaseTabCtrl *this,
        const CArray<unsigned long,unsigned long> *arColors)
{
  int v3; // ebx
  int v4; // eax
  CMFCBaseTabCtrl_vtbl *v5; // eax
  int m_nSize; // eax
  HWND__ *m_hWnd; // esi

  v3 = 0;
  v4 = 0;
  if ( this->m_iTabsNum > 0 )
  {
    while ( v4 >= 0 && v4 < this->m_arTabs.m_nSize )
    {
      *((_DWORD *)this->m_arTabs.m_pData[v4++] + 12) = -1;
      if ( v4 >= this->m_iTabsNum )
        goto LABEL_5;
    }
LABEL_7:
    AfxThrowInvalidArgException();
  }
LABEL_5:
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arAutoColors,
    nNewSize: 0,
    nGrowBy: -1);
  if ( arColors->m_nSize != 0 )
  {
    this->m_bIsDefaultAutoColor = 0;
    m_nSize = arColors->m_nSize;
    if ( m_nSize > 0 )
    {
      while ( v3 >= 0 && v3 < m_nSize )
      {
        CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
          this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arAutoColors,
          nIndex: this->m_arAutoColors.m_nSize,
          newElement: (CMFCRibbonKeyTip *)arColors->m_pData[v3]);
        m_nSize = arColors->m_nSize;
        if ( ++v3 >= m_nSize )
          goto LABEL_12;
      }
      goto LABEL_7;
    }
  }
  else
  {
    v5 = this->__vftable;
    this->m_bIsDefaultAutoColor = 1;
    v5->InitAutoColors(this);
  }
LABEL_12:
  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x103DCFBA
// Name: public: CMFCRestoredTabInfo::CMFCRestoredTabInfo(struct CMFCRestoredTabInfo const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRestoredTabInfo *__thiscall CMFCRestoredTabInfo::CMFCRestoredTabInfo(
        CMFCRestoredTabInfo *this,
        const CMFCRestoredTabInfo *__that)
{
  this->m_strText.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)__that->m_strText.m_pszData - 1)[1];
  this->m_bVisible = __that->m_bVisible;
  this->m_nControlBarID = __that->m_nControlBarID;
  this->m_bDetachable = __that->m_bDetachable;
  this->m_clrText = __that->m_clrText;
  this->m_clrBack = __that->m_clrBack;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103EE4CD
// Name: public: virtual CMFCControlRenderer::~CMFCControlRenderer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCControlRenderer::~CMFCControlRenderer(CMFCControlRenderer *this)
{
  this->__vftable = (CMFCControlRenderer_vtbl *)&CMFCControlRenderer::`vftable';
  CMFCControlRenderer::CleanUp(this);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_Params.m_strBmpResID.m_pszData - 1);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_Bitmap);
}

//------------------------------------------------------------------------------
// Address: 0x103EE510
// Name: public: CMFCShadowRenderer::CMFCShadowRenderer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCShadowRenderer *__thiscall CMFCShadowRenderer::CMFCShadowRenderer(CMFCShadowRenderer *this)
{
  CMFCControlRenderer::CMFCControlRenderer(this);
  this->__vftable = (CMFCShadowRenderer_vtbl *)&CMFCShadowRenderer::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103EE524
// Name: public: virtual CMFCShadowRenderer::~CMFCShadowRenderer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShadowRenderer::~CMFCShadowRenderer(CMFCShadowRenderer *this)
{
  this->__vftable = (CMFCShadowRenderer_vtbl *)&CMFCShadowRenderer::`vftable';
  CMFCControlRenderer::~CMFCControlRenderer(this);
}

//------------------------------------------------------------------------------
// Address: 0x103EE550
// Name: public: static class CObject __near * CMFCShadowRenderer::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCShadowRenderer *__stdcall CMFCShadowRenderer::CreateObject()
{
  CMFCShadowRenderer *v0; // ecx
  CMFCShadowRenderer *result; // eax

  v0 = (CMFCShadowRenderer *)operator new(nSize: 0x168u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCShadowRenderer::CMFCShadowRenderer(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EE5A7
// Name: public: virtual struct CRuntimeClass __near * CMFCPropertyPage::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCPropertyPage::GetRuntimeClass(CMFCPropertyPage *this)
{
  return &CMFCPropertyPage::classCMFCPropertyPage;
}

//------------------------------------------------------------------------------
// Address: 0x103EE5AD
// Name: protected: void CMFCPropertyPage::CommonInit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyPage::CommonInit(CMFCPropertyPage *this)
{
  this->m_pCategory = nullptr;
  this->m_nIcon = -1;
  this->m_nSelIconNum = -1;
  this->m_hTreeNode = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103EE5CA
// Name: public: virtual CMFCPropertyPage::~CMFCPropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyPage::~CMFCPropertyPage(CMFCPropertyPage *this)
{
  this->__vftable = (CMFCPropertyPage_vtbl *)&CMFCPropertyPage::`vftable';
  CDialogImpl::~CDialogImpl(this: &this->m_Impl);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x103EE601
// Name: protected: int CMFCPropertyPage::OnNcActivate(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyPage::OnNcActivate(CMFCPropertyPage *this, unsigned int bActive)
{
  CDialogImpl::OnNcActivate(this: &this->m_Impl, (int *)&bActive);
  return this->DefWindowProcA(this, a2: 134u, a3: bActive, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103EE631
// Name: protected: void CMFCPropertyPage::SetActiveMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyPage::SetActiveMenu(CMFCPropertyPage *this, CMFCPopupMenu *pMenu)
{
  CDialogImpl::SetActiveMenu(this: &this->m_Impl, pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x103EE642
// Name: public: virtual int CMFCPropertyPage::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyPage::PreTranslateMessage(CMFCPropertyPage *this, tagMSG *pMsg)
{
  if ( CDialogImpl::PreTranslateMessage(this: &this->m_Impl, pMsg) )
    return 1;
  else
    return CPropertyPage::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103EE670
// Name: protected: virtual int CMFCPropertyPage::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyPage::OnCommand(CMFCPropertyPage *this, unsigned int wParam, HWND__ *lParam)
{
  if ( CDialogImpl::OnCommand(this: &this->m_Impl, wParam, __formal: (int)lParam) != 0 )
    return 1;
  else
    return CWnd::OnCommand(this, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x103EE6A4
// Name: public: CMFCPropertyPage::CMFCPropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPropertyPage *__thiscall CMFCPropertyPage::CMFCPropertyPage(CMFCPropertyPage *this)
{
  CPropertyPage::CPropertyPage(this);
  this->__vftable = (CMFCPropertyPage_vtbl *)&CMFCPropertyPage::`vftable';
  CDialogImpl::CDialogImpl(this: &this->m_Impl, dlg: this);
  CMFCPropertyPage::CommonInit(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103EE700
// Name: protected: void CMFCPropertyPage::OnActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyPage::OnActivate(
        CMFCPropertyPage *this,
        unsigned int nState,
        CWnd *pWndOther,
        int bMinimized)
{
  CDialogImpl::OnActivate(this: &this->m_Impl, nState, pWndOther);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103EE725
// Name: public: virtual int CMFCPropertyPage::OnSetActive(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyPage::OnSetActive(CMFCPropertyPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  CObject *v4; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = AfxDynamicDownCast(pClass: &CMFCPropertySheet::classCMFCPropertySheet, pObject: v3);
  if ( v4 != nullptr )
    v4->__vftable[30].Serialize(this: v4, a2: (CArchive *)this);
  return CPropertyPage::OnSetActive(this);
}

//------------------------------------------------------------------------------
// Address: 0x103EE75D
// Name: protected: virtual int CMFCPropertyPage::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyPage::OnInitDialog(CMFCPropertyPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  CObject *v4; // eax
  HWND i; // eax
  CWnd *v6; // esi
  int dy; // [esp+8h] [ebp-20h]
  int bRes; // [esp+10h] [ebp-18h]
  CRect rectChild; // [esp+14h] [ebp-14h] BYREF

  bRes = CDialog::OnInitDialog(this);
  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = AfxDynamicDownCast(pClass: &CMFCPropertySheet::classCMFCPropertySheet, pObject: v3);
  if ( v4 != nullptr )
  {
    dy = (int)v4[4744].__vftable;
    if ( dy != 0 )
    {
      for ( i = GetWindow(hWnd: this->m_hWnd, uCmd: 5u); ; i = GetWindow(hWnd: v6->m_hWnd, uCmd: 2u) )
      {
        v6 = CWnd::FromHandle(hWnd: i);
        if ( v6 == nullptr )
          break;
        memset(&rectChild, 0, sizeof(rectChild));
        GetWindowRect(hWnd: v6->m_hWnd, lpRect: &rectChild);
        CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectChild);
        OffsetRect(lprc: &rectChild, dx: 0, dy);
        CWnd::SetWindowPos(
          this: v6,
          pWndInsertAfter: nullptr,
          x: rectChild.left,
          y: rectChild.top,
          cx: -1,
          cy: -1,
          nFlags: 0x15u);
      }
    }
  }
  return bRes;
}

//------------------------------------------------------------------------------
// Address: 0x103EE828
// Name: protected: int CMFCPropertyPage::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyPage::OnEraseBkgnd(CMFCPropertyPage *this, CDC *pDC)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  CPropertySheet *v5; // ebx
  CPropertySheet_vtbl *v6; // eax
  int PageIndex; // eax
  int rectHeader; // [esp+Ch] [ebp-44h]
  int rectHeader_4; // [esp+10h] [ebp-40h]
  int rectHeader_8; // [esp+14h] [ebp-3Ch]
  int rectHeader_12; // [esp+18h] [ebp-38h]
  CPropertySheet_vtbl *v13; // [esp+1Ch] [ebp-34h]
  int bRes; // [esp+24h] [ebp-2Ch]
  CRect rectParent; // [esp+2Ch] [ebp-24h] BYREF
  CRect rectClient; // [esp+3Ch] [ebp-14h] BYREF

  bRes = CWnd::Default(this);
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  v5 = (CPropertySheet *)AfxDynamicDownCast(pClass: &CMFCPropertySheet::classCMFCPropertySheet, pObject: v4);
  if ( v5 != nullptr && v5[93].m_dwRef > 0 )
  {
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: this->m_hWnd, lpRect: &rectClient);
    rectHeader = rectClient.left;
    rectHeader_4 = rectClient.top;
    rectHeader_8 = rectClient.right;
    rectHeader_12 = rectClient.top + v5[93].m_dwRef;
    v6 = v5[1].__vftable;
    if ( v6 == (CPropertySheet_vtbl *)1 || v6 == (CPropertySheet_vtbl *)2 || v6 == (CPropertySheet_vtbl *)4 )
    {
      memset(&rectParent, 0, sizeof(rectParent));
      GetWindowRect(hWnd: v5->m_hWnd, lpRect: &rectParent);
      CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectParent);
      rectHeader_8 = rectParent.right - GetSystemMetrics(nIndex: 7);
    }
    v13 = v5->__vftable;
    PageIndex = CPropertySheet::GetPageIndex(this: v5, pPage: this);
    ((void (__thiscall *)(CPropertySheet *, CDC *, int, int, int, int, int))v13[1].OnCmdMsg)(
      a1: v5,
      a2: pDC,
      a3: PageIndex,
      a4: rectHeader,
      a5: rectHeader_4,
      a6: rectHeader_8,
      a7: rectHeader_12);
  }
  return bRes;
}

//------------------------------------------------------------------------------
// Address: 0x103EE93D
// Name: public: static class CObject __near * CMFCPropertyPage::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPropertyPage *__stdcall CMFCPropertyPage::CreateObject()
{
  CMFCPropertyPage *v0; // ecx
  CMFCPropertyPage *result; // eax

  v0 = (CMFCPropertyPage *)operator new(nSize: 0xC0u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCPropertyPage::CMFCPropertyPage(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EE96D
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCPropertyPage::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCPropertyPage::GetMessageMap(CMFCPropertyPage *this)
{
  return (const AFX_MSGMAP *)&off_106880C8;
}

//------------------------------------------------------------------------------
// Address: 0x103EE973
// Name: public: virtual struct CRuntimeClass __near * CDialogEx::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDialogEx::GetRuntimeClass(CDialogEx *this)
{
  return &CDialogEx::classCDialogEx;
}

//------------------------------------------------------------------------------
// Address: 0x103EE979
// Name: protected: void CDialogEx::CommonConstruct(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDialogEx::CommonConstruct(CDialogEx *this)
{
  this->m_BkgrLocation = -1;
  this->m_hBkgrBitmap = nullptr;
  this->m_sizeBkgrBitmap.cx = 0;
  this->m_sizeBkgrBitmap.cy = 0;
  this->m_bAutoDestroyBmp = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103EE99D
// Name: protected: void CDialogEx::OnActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDialogEx::OnActivate(CDialogEx *this, unsigned int nState, CWnd *pWndOther, int __formal)
{
  CDialogImpl::OnActivate(this: &this->m_Impl, nState, pWndOther);
}

//------------------------------------------------------------------------------
// Address: 0x103EE9B7
// Name: protected: int CDialogEx::OnNcActivate(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDialogEx::OnNcActivate(CDialogEx *this, unsigned int bActive)
{
  CDialogImpl::OnNcActivate(this: &this->m_Impl, (int *)&bActive);
  return this->DefWindowProcA(this, a2: 134u, a3: bActive, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103EE9E7
// Name: protected: void CDialogEx::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDialogEx::OnDestroy(CDialogEx *this)
{
  HBITMAP__ *m_hBkgrBitmap; // eax

  if ( this->m_bAutoDestroyBmp != 0 )
  {
    m_hBkgrBitmap = this->m_hBkgrBitmap;
    if ( m_hBkgrBitmap != nullptr )
    {
      DeleteObject(ho: m_hBkgrBitmap);
      this->m_hBkgrBitmap = nullptr;
    }
  }
  CDialogImpl::OnDestroy(this: &this->m_Impl);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103EEA22
// Name: public: virtual int CDialogEx::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDialogEx::PreTranslateMessage(CDialogEx *this, tagMSG *pMsg)
{
  if ( CDialogImpl::PreTranslateMessage(this: &this->m_Impl, pMsg) )
    return 1;
  else
    return CDialog::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103EEA50
// Name: protected: void CDialogEx::SetActiveMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDialogEx::SetActiveMenu(CDialogEx *this, CMFCPopupMenu *pMenu)
{
  CDialogImpl::SetActiveMenu(this: &this->m_Impl, pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x103EEA61
// Name: protected: virtual int CDialogEx::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDialogEx::OnCommand(CDialogEx *this, unsigned int wParam, HWND__ *lParam)
{
  if ( CDialogImpl::OnCommand(this: &this->m_Impl, wParam, __formal: (int)lParam) != 0 )
    return 1;
  else
    return CWnd::OnCommand(this, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x103FDF97
// Name: public: CPaneContainer::CPaneContainer(class CPaneContainerManager __near *,class CDockablePane __near *,class CDockablePane __near *,class CPaneDivider __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneContainer *__thiscall CPaneContainer::CPaneContainer(
        CPaneContainer *this,
        CPaneContainerManager *pManager,
        CDockablePane *pLeftBar,
        CDockablePane *pRightBar,
        CPaneDivider *pSlider)
{
  this->m_pBarLeftTop = pLeftBar;
  this->m_pBarRightBottom = pRightBar;
  this->m_pSlider = pSlider;
  this->m_pContainerManager = pManager;
  this->__vftable = (CPaneContainer_vtbl *)&CPaneContainer::`vftable';
  this->m_pLeftContainer = nullptr;
  this->m_pRightContainer = nullptr;
  this->m_pParentContainer = nullptr;
  this->m_dwRefCount = 0;
  this->m_rectRecentSlider.left = 0;
  this->m_rectRecentSlider.top = 0;
  this->m_rectRecentSlider.right = 0;
  this->m_rectRecentSlider.bottom = 0;
  this->m_rectSavedSliderRect.left = 0;
  this->m_rectSavedSliderRect.top = 0;
  this->m_rectSavedSliderRect.right = 0;
  this->m_rectSavedSliderRect.bottom = 0;
  CList<unsigned int,unsigned int>::CList<unsigned int,unsigned int>(
    this: &this->m_lstSavedSiblingBarIDsLeft,
    nBlockSize: 10);
  CList<unsigned int,unsigned int>::CList<unsigned int,unsigned int>(
    this: &this->m_lstSavedSiblingBarIDsRight,
    nBlockSize: 10);
  this->m_nSavedLeftBarID = -1;
  this->m_nSavedRightBarID = -1;
  this->m_nSavedSliderID = -1;
  this->m_bSavedSliderVisibility = 0;
  SetRectEmpty(lprc: &this->m_rectSavedSliderRect);
  this->m_dwRecentSliderStyle = 0;
  SetRectEmpty(lprc: &this->m_rectRecentSlider);
  this->m_bIsRecentSliderHorz = 0;
  this->m_bDisposed = 0;
  this->m_nRecentPercent = 50;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103FE099
// Name: public: virtual void CPaneContainer::GetWindowRect(class CRect __near &,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::GetWindowRect(CPaneContainer *this, CRect *rect, int bIgnoreVisibility)
{
  BOOL IsAutoHideMode; // eax
  CDockablePane *m_pBarLeftTop; // ecx
  CDockablePane *v6; // ecx
  CDockablePane *m_pBarRightBottom; // ecx
  CDockablePane *v8; // ecx
  CPaneContainer *m_pLeftContainer; // ecx
  CPaneContainer *m_pRightContainer; // ecx
  int bAutoHideMode; // [esp+Ch] [ebp-44h]
  CSize sz; // [esp+10h] [ebp-40h] BYREF
  LPRECT lprcDst; // [esp+18h] [ebp-38h]
  CRect rectContainer; // [esp+1Ch] [ebp-34h] BYREF
  CRect rectLeft; // [esp+2Ch] [ebp-24h] BYREF
  CRect rectRight; // [esp+3Ch] [ebp-14h] BYREF

  lprcDst = rect;
  memset(&rectLeft, 0, sizeof(rectLeft));
  memset(&rectRight, 0, sizeof(rectRight));
  memset(&rectContainer, 0, sizeof(rectContainer));
  SetRectEmpty(lprc: rect);
  SetRectEmpty(lprc: &rectLeft);
  SetRectEmpty(lprc: &rectRight);
  IsAutoHideMode = CPaneContainerManager::IsAutoHideMode(this: this->m_pContainerManager);
  m_pBarLeftTop = this->m_pBarLeftTop;
  bAutoHideMode = IsAutoHideMode;
  if ( m_pBarLeftTop != nullptr
    && ((CWnd::GetStyle(this: &m_pBarLeftTop->CPane) & 0x10000000) != 0 || bIgnoreVisibility != 0 || bAutoHideMode != 0) )
  {
    GetWindowRect(hWnd: this->m_pBarLeftTop->m_hWnd, lpRect: &rectLeft);
    if ( IsRectEmpty(lprc: &rectLeft) )
    {
      v6 = this->m_pBarLeftTop;
      sz.cx = 0;
      sz.cy = 0;
      v6->GetMinSize(this: &v6->CPane, a2: &sz);
      if ( rectLeft.right == rectLeft.left )
        rectLeft.right += sz.cx;
      if ( rectLeft.bottom == rectLeft.top )
        rectLeft.bottom += sz.cy;
    }
  }
  m_pBarRightBottom = this->m_pBarRightBottom;
  if ( m_pBarRightBottom != nullptr
    && ((CWnd::GetStyle(this: &m_pBarRightBottom->CPane) & 0x10000000) != 0
     || bIgnoreVisibility != 0
     || bAutoHideMode != 0) )
  {
    GetWindowRect(hWnd: this->m_pBarRightBottom->m_hWnd, lpRect: &rectRight);
    if ( IsRectEmpty(lprc: &rectRight) )
    {
      v8 = this->m_pBarRightBottom;
      sz.cx = 0;
      sz.cy = 0;
      v8->GetMinSize(this: &v8->CPane, a2: &sz);
      if ( rectRight.right == rectRight.left )
        rectRight.right += sz.cx;
      if ( rectRight.bottom == rectRight.top )
        rectRight.bottom += sz.cy;
    }
  }
  UnionRect(lprcDst, lprcSrc1: &rectLeft, lprcSrc2: &rectRight);
  m_pLeftContainer = this->m_pLeftContainer;
  if ( m_pLeftContainer != nullptr
    && (CPaneContainer::IsVisible(this: m_pLeftContainer) || bIgnoreVisibility != 0 || bAutoHideMode != 0) )
  {
    this->m_pLeftContainer->GetWindowRect(this: this->m_pLeftContainer, a2: &rectContainer, a3: 0);
    UnionRect(lprcDst, lprcSrc1: lprcDst, lprcSrc2: &rectContainer);
  }
  m_pRightContainer = this->m_pRightContainer;
  if ( m_pRightContainer != nullptr
    && (CPaneContainer::IsVisible(this: m_pRightContainer) || bIgnoreVisibility != 0 || bAutoHideMode != 0) )
  {
    this->m_pRightContainer->GetWindowRect(this: this->m_pRightContainer, a2: &rectContainer, a3: 0);
    UnionRect(lprcDst, lprcSrc1: lprcDst, lprcSrc2: &rectContainer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FE266
// Name: public: virtual void CPaneContainer::GetMinSize(class CSize __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::GetMinSize(CPaneContainer *this, CSize *size)
{
  CPaneContainerManager *m_pContainerManager; // ecx
  BOOL IsAutoHideMode; // eax
  CDockablePane *m_pBarLeftTop; // ecx
  CDockablePane *m_pBarRightBottom; // ecx
  CPaneContainer *m_pLeftContainer; // ecx
  CPaneContainer *m_pRightContainer; // ecx
  CPaneDivider *m_pSlider; // ecx
  int cx; // eax
  int v12; // eax
  int cy; // eax
  int v14; // eax
  int v15; // eax
  CPaneContainer *v16; // ecx
  CPaneContainer *v17; // ecx
  CSize minSizeLeft; // [esp+Ch] [ebp-20h] BYREF
  CSize sizeRightContainer; // [esp+14h] [ebp-18h] BYREF
  CSize sizeLeftContainer; // [esp+1Ch] [ebp-10h] BYREF
  CSize minSizeRight; // [esp+24h] [ebp-8h] BYREF
  int bAutoHideMode; // [esp+34h] [ebp+8h]

  if ( this->m_pContainerManager == nullptr )
    AfxThrowInvalidArgException();
  size->cy = 0;
  size->cx = 0;
  m_pContainerManager = this->m_pContainerManager;
  minSizeLeft.cx = 0;
  minSizeLeft.cy = 0;
  minSizeRight.cx = 0;
  minSizeRight.cy = 0;
  IsAutoHideMode = CPaneContainerManager::IsAutoHideMode(this: m_pContainerManager);
  m_pBarLeftTop = this->m_pBarLeftTop;
  bAutoHideMode = IsAutoHideMode;
  if ( m_pBarLeftTop != nullptr
    && ((CWnd::GetStyle(this: &m_pBarLeftTop->CPane) & 0x10000000) != 0 || bAutoHideMode != 0) )
  {
    this->m_pBarLeftTop->GetMinSize(this: (CPane *)this->m_pBarLeftTop, a2: &minSizeLeft);
  }
  m_pBarRightBottom = this->m_pBarRightBottom;
  if ( m_pBarRightBottom != nullptr
    && ((CWnd::GetStyle(this: &m_pBarRightBottom->CPane) & 0x10000000) != 0 || bAutoHideMode != 0) )
  {
    this->m_pBarRightBottom->GetMinSize(this: (CPane *)this->m_pBarRightBottom, a2: &minSizeRight);
  }
  m_pLeftContainer = this->m_pLeftContainer;
  sizeLeftContainer.cx = 0;
  sizeLeftContainer.cy = 0;
  if ( m_pLeftContainer != nullptr && (CPaneContainer::IsVisible(this: m_pLeftContainer) || bAutoHideMode != 0) )
    this->m_pLeftContainer->GetMinSize(this: this->m_pLeftContainer, a2: &sizeLeftContainer);
  m_pRightContainer = this->m_pRightContainer;
  sizeRightContainer.cx = 0;
  sizeRightContainer.cy = 0;
  if ( m_pRightContainer != nullptr && (CPaneContainer::IsVisible(this: m_pRightContainer) || bAutoHideMode != 0) )
    this->m_pRightContainer->GetMinSize(this: this->m_pRightContainer, a2: &sizeRightContainer);
  m_pSlider = this->m_pSlider;
  if ( m_pSlider != nullptr && ((CWnd::GetStyle(this: m_pSlider) & 0x10000000) != 0 || bAutoHideMode != 0) )
  {
    if ( CPaneContainer::IsPaneDividerHorz(this) != 0 )
    {
      cx = minSizeLeft.cx;
      if ( minSizeLeft.cx <= minSizeRight.cx )
        cx = minSizeRight.cx;
      size->cx = cx;
      if ( sizeLeftContainer.cx > cx )
        cx = sizeLeftContainer.cx;
      size->cx = cx;
      if ( sizeRightContainer.cx > cx )
        cx = sizeRightContainer.cx;
      size->cx = cx;
      v12 = minSizeLeft.cy + minSizeRight.cy + sizeLeftContainer.cy + sizeRightContainer.cy + this->m_pSlider->m_nWidth;
      goto LABEL_47;
    }
    cy = minSizeLeft.cy;
    if ( minSizeLeft.cy <= minSizeRight.cy )
      cy = minSizeRight.cy;
    size->cy = cy;
    if ( sizeLeftContainer.cy > cy )
      cy = sizeLeftContainer.cy;
    size->cy = cy;
    if ( sizeRightContainer.cy > cy )
      cy = sizeRightContainer.cy;
    size->cy = cy;
    size->cx = minSizeLeft.cx
             + minSizeRight.cx
             + sizeLeftContainer.cx
             + sizeRightContainer.cx
             + this->m_pSlider->m_nWidth;
  }
  else
  {
    v14 = minSizeLeft.cx;
    if ( minSizeLeft.cx <= minSizeRight.cx )
      v14 = minSizeRight.cx;
    size->cx = v14;
    v15 = minSizeLeft.cy;
    if ( minSizeLeft.cy <= minSizeRight.cy )
      v15 = minSizeRight.cy;
    size->cy = v15;
    v16 = this->m_pLeftContainer;
    if ( v16 != nullptr && CPaneContainer::IsVisible(this: v16) )
      *size = sizeLeftContainer;
    v17 = this->m_pRightContainer;
    if ( v17 != nullptr && CPaneContainer::IsVisible(this: v17) )
    {
      size->cx = sizeRightContainer.cx;
      v12 = sizeRightContainer.cy;
LABEL_47:
      size->cy = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FE435
// Name: public: virtual void CPaneContainer::GetMinSizeLeft(class CSize __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::GetMinSizeLeft(CPaneContainer *this, CSize *size)
{
  BOOL IsAutoHideMode; // eax
  CDockablePane *m_pBarLeftTop; // ecx
  BOOL v5; // edi
  CPaneContainer *m_pLeftContainer; // ecx
  int cx; // eax
  int cy; // eax
  CSize minSizeLeft; // [esp+8h] [ebp-10h] BYREF
  CSize sizeLeftContainer; // [esp+10h] [ebp-8h] BYREF

  IsAutoHideMode = CPaneContainerManager::IsAutoHideMode(this: this->m_pContainerManager);
  m_pBarLeftTop = this->m_pBarLeftTop;
  minSizeLeft.cx = 0;
  minSizeLeft.cy = 0;
  v5 = IsAutoHideMode;
  if ( m_pBarLeftTop != nullptr && ((CWnd::GetStyle(this: &m_pBarLeftTop->CPane) & 0x10000000) != 0 || v5) )
    this->m_pBarLeftTop->GetMinSize(this: (CPane *)this->m_pBarLeftTop, a2: &minSizeLeft);
  m_pLeftContainer = this->m_pLeftContainer;
  sizeLeftContainer.cx = 0;
  sizeLeftContainer.cy = 0;
  if ( m_pLeftContainer != nullptr && (CPaneContainer::IsVisible(this: m_pLeftContainer) || v5) )
    this->m_pLeftContainer->GetMinSize(this: this->m_pLeftContainer, a2: &sizeLeftContainer);
  cx = minSizeLeft.cx;
  if ( minSizeLeft.cx <= sizeLeftContainer.cx )
    cx = sizeLeftContainer.cx;
  size->cx = cx;
  cy = minSizeLeft.cy;
  if ( minSizeLeft.cy <= sizeLeftContainer.cy )
    cy = sizeLeftContainer.cy;
  size->cy = cy;
}

//------------------------------------------------------------------------------
// Address: 0x103FE4C5
// Name: public: virtual void CPaneContainer::GetMinSizeRight(class CSize __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::GetMinSizeRight(CPaneContainer *this, CSize *size)
{
  BOOL IsAutoHideMode; // eax
  CDockablePane *m_pBarRightBottom; // ecx
  BOOL v5; // edi
  CPaneContainer *m_pRightContainer; // ecx
  int cx; // eax
  int cy; // eax
  CSize minSizeRight; // [esp+8h] [ebp-10h] BYREF
  CSize sizeRightContainer; // [esp+10h] [ebp-8h] BYREF

  IsAutoHideMode = CPaneContainerManager::IsAutoHideMode(this: this->m_pContainerManager);
  m_pBarRightBottom = this->m_pBarRightBottom;
  minSizeRight.cx = 0;
  minSizeRight.cy = 0;
  v5 = IsAutoHideMode;
  if ( m_pBarRightBottom != nullptr && ((CWnd::GetStyle(this: &m_pBarRightBottom->CPane) & 0x10000000) != 0 || v5) )
    this->m_pBarRightBottom->GetMinSize(this: (CPane *)this->m_pBarRightBottom, a2: &minSizeRight);
  m_pRightContainer = this->m_pRightContainer;
  sizeRightContainer.cx = 0;
  sizeRightContainer.cy = 0;
  if ( m_pRightContainer != nullptr && (CPaneContainer::IsVisible(this: m_pRightContainer) || v5) )
    this->m_pRightContainer->GetMinSize(this: this->m_pRightContainer, a2: &sizeRightContainer);
  cx = minSizeRight.cx;
  if ( minSizeRight.cx <= sizeRightContainer.cx )
    cx = sizeRightContainer.cx;
  size->cx = cx;
  cy = minSizeRight.cy;
  if ( minSizeRight.cy <= sizeRightContainer.cy )
    cy = sizeRightContainer.cy;
  size->cy = cy;
}

//------------------------------------------------------------------------------
// Address: 0x103FE555
// Name: public: class CDockablePane __near * CPaneContainer::AddPane(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockablePane *__thiscall CPaneContainer::AddPane(CPaneContainer *this, CDockablePane *pBar)
{
  CPaneContainerManager *m_pContainerManager; // ecx
  CPaneContainerManager_vtbl *v4; // eax
  CPaneContainer *i; // esi
  int v6; // edi
  int v7; // eax
  int top; // eax
  CDockablePane *v9; // esi
  CDockablePane_vtbl *v10; // eax
  int RecentDockedPercent; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  CPaneDivider *m_pSlider; // edx
  int left; // ecx
  int v17; // eax
  CPaneDivider *v18; // edx
  HDWP v19; // eax
  CDockablePane_vtbl *v20; // edx
  void *v21; // eax
  CPaneContainer *m_pLeftContainer; // ecx
  CDockablePane *v24; // eax
  CDockablePane_vtbl *v25; // edx
  CDockablePane *v26; // eax
  CPaneContainerManager *v27; // ecx
  CDockablePane *m_pBarLeftTop; // eax
  CDockablePane_vtbl *v29; // edx
  CDockablePane *m_pBarRightBottom; // eax
  CPaneContainer *m_pRightContainer; // ecx
  bool v32; // zf
  CPaneDivider *v33; // eax
  CDockablePane *v34; // ecx
  CPaneContainer *v35; // ecx
  CDockablePane *v36; // eax
  CPaneContainer *v37; // ecx
  int IsPaneDividerHorz; // eax
  CPaneDivider *v39; // ecx
  CPaneDivider *v40; // ecx
  CPaneDivider *v41; // esi
  CPaneContainer *v42; // ecx
  CPaneContainer *v43; // edi
  int m_nWidth; // edi
  int v45; // eax
  int v46; // edi
  int v47; // edi
  CPaneDivider *v48; // ebx
  CDockablePane *v49; // [esp-4h] [ebp-90h]
  BOOL bExpandParentContainer; // [esp+Ch] [ebp-80h]
  CSize sizeMin; // [esp+10h] [ebp-7Ch] BYREF
  CRecentDockSiteInfo *p_m_recentDockInfo; // [esp+18h] [ebp-74h]
  CPaneContainer *pNextContainer; // [esp+1Ch] [ebp-70h]
  CWnd *pDockSite; // [esp+20h] [ebp-6Ch]
  int nNewHeight; // [esp+24h] [ebp-68h]
  CDockablePane *v56; // [esp+28h] [ebp-64h]
  void *hdwp; // [esp+2Ch] [ebp-60h] BYREF
  int bIsLeftContainer; // [esp+30h] [ebp-5Ch]
  CDockablePane *pTabbedControlBar; // [esp+34h] [ebp-58h] BYREF
  CRect rectParentContainer; // [esp+38h] [ebp-54h] BYREF
  CRect rectSecondBar; // [esp+48h] [ebp-44h] BYREF
  CRect rectSlider; // [esp+58h] [ebp-34h] BYREF
  CRect rectNew; // [esp+68h] [ebp-24h] BYREF
  CRect rectContainer; // [esp+78h] [ebp-14h] BYREF

  m_pContainerManager = this->m_pContainerManager;
  v4 = m_pContainerManager->__vftable;
  v56 = pBar;
  pDockSite = v4->GetDockSiteFrameWnd(this: m_pContainerManager);
  bIsLeftContainer = CObject::IsKindOf(this: pDockSite, pClass: &CPaneFrameWnd::classCPaneFrameWnd) == 0;
  rectNew = *CRecentDockSiteInfo::GetRecentDockedRect(this: &pBar->m_recentDockInfo, bForSlider: bIsLeftContainer);
  memset(&rectContainer, 0, sizeof(rectContainer));
  SetRectEmpty(lprc: &rectContainer);
  this->GetWindowRect(this, a2: &rectContainer, a3: 0);
  CWnd::ScreenToClient(this: pDockSite, lpRect: (tagPOINT *)&rectContainer);
  bExpandParentContainer = CPaneContainer::IsEmpty(this);
  pNextContainer = this->m_pParentContainer;
  for ( i = pNextContainer; i != nullptr; pNextContainer = i )
  {
    if ( !CPaneContainer::IsEmpty(this: i) )
      break;
    i = i->m_pParentContainer;
  }
  memset(&rectParentContainer, 0, sizeof(rectParentContainer));
  SetRectEmpty(lprc: &rectParentContainer);
  if ( i != nullptr )
  {
    i->GetWindowRect(this: i, a2: &rectParentContainer, a3: 0);
    CWnd::ScreenToClient(this: pDockSite, lpRect: (tagPOINT *)&rectParentContainer);
  }
  if ( rectContainer.right - rectContainer.left <= 0 )
  {
    v6 = rectParentContainer.right - rectParentContainer.left;
    pTabbedControlBar = (CDockablePane *)(rectParentContainer.right - rectParentContainer.left);
  }
  else
  {
    v6 = rectContainer.right - rectContainer.left;
    pTabbedControlBar = (CDockablePane *)(rectContainer.right - rectContainer.left);
  }
  v7 = rectContainer.bottom - rectContainer.top;
  if ( rectContainer.bottom - rectContainer.top <= 0 )
    v7 = rectParentContainer.bottom - rectParentContainer.top;
  nNewHeight = v7;
  if ( v6 == 0 )
  {
    v6 = rectNew.right - rectNew.left;
    pTabbedControlBar = (CDockablePane *)(rectNew.right - rectNew.left);
  }
  if ( nNewHeight == 0 )
    nNewHeight = rectNew.bottom - rectNew.top;
  if ( IsRectEmpty(lprc: &rectContainer) )
  {
    if ( IsRectEmpty(lprc: &rectParentContainer) )
      goto LABEL_20;
    rectNew.left = rectParentContainer.left;
    top = rectParentContainer.top;
  }
  else
  {
    rectNew.left = rectContainer.left;
    top = rectContainer.top;
  }
  rectNew.top = top;
LABEL_20:
  v9 = v56;
  v10 = v56->__vftable;
  sizeMin.cx = 0;
  sizeMin.cy = 0;
  v10->GetMinSize(this: &v56->CPane, a2: &sizeMin);
  if ( v6 < sizeMin.cx )
    pTabbedControlBar = (CDockablePane *)sizeMin.cx;
  if ( nNewHeight < sizeMin.cy )
    nNewHeight = sizeMin.cy;
  p_m_recentDockInfo = &v9->m_recentDockInfo;
  RecentDockedPercent = CRecentDockSiteInfo::GetRecentDockedPercent(
                          this: &v9->m_recentDockInfo,
                          bForSlider: bIsLeftContainer);
  v12 = RecentDockedPercent;
  if ( RecentDockedPercent == 100 || RecentDockedPercent == 0 )
    v12 = 50;
  if ( !CPaneContainer::IsEmpty(this) && this->m_pSlider != nullptr )
  {
    if ( CPaneContainer::IsPaneDividerHorz(this) != 0 )
    {
      if ( CRecentDockSiteInfo::IsRecentLeftPane(this: p_m_recentDockInfo, bForSlider: bIsLeftContainer) != 0 )
      {
        v13 = rectContainer.top;
        v14 = v12 * (rectContainer.bottom - rectContainer.top) / 100;
      }
      else
      {
        m_pSlider = this->m_pSlider;
        v14 = rectContainer.bottom
            - (100 - v12) * (rectContainer.bottom - rectContainer.top) / 100
            - m_pSlider->m_nWidth
            - rectContainer.top;
        v13 = rectContainer.top
            - ((100 - v12) * (rectContainer.bottom - rectContainer.top) / -100
             - m_pSlider->m_nWidth);
      }
      nNewHeight = v14;
      rectNew.top = v13;
    }
    else
    {
      if ( CRecentDockSiteInfo::IsRecentLeftPane(this: p_m_recentDockInfo, bForSlider: bIsLeftContainer) != 0 )
      {
        left = rectContainer.left;
        v17 = v12 * (rectContainer.right - rectContainer.left) / 100;
      }
      else
      {
        v18 = this->m_pSlider;
        v17 = rectContainer.right
            - (100 - v12) * (rectContainer.right - rectContainer.left) / 100
            - v18->m_nWidth
            - rectContainer.left;
        left = rectContainer.left - ((100 - v12) * (rectContainer.right - rectContainer.left) / -100 - v18->m_nWidth);
      }
      rectNew.left = left;
      pTabbedControlBar = (CDockablePane *)v17;
    }
  }
  rectNew.bottom = nNewHeight + rectNew.top;
  rectNew.right = (int)pTabbedControlBar + rectNew.left;
  v19 = BeginDeferWindowPos(nNumWindows: 10);
  v20 = v56->__vftable;
  hdwp = v19;
  v21 = v20->MoveWindow(this: &v56->CPane, a2: &rectNew, a3: 0, a4: v19);
  rectSlider = rectNew;
  hdwp = v21;
  memset(&rectSecondBar, 0, sizeof(rectSecondBar));
  if ( CRecentDockSiteInfo::IsRecentLeftPane(this: &v56->m_recentDockInfo, bForSlider: bIsLeftContainer) != 0 )
  {
    m_pLeftContainer = this->m_pLeftContainer;
    if ( m_pLeftContainer != nullptr )
      return CPaneContainer::AddPane(this: m_pLeftContainer, pBar: v56);
    m_pBarLeftTop = this->m_pBarLeftTop;
    if ( m_pBarLeftTop != nullptr )
    {
      v29 = v56->__vftable;
      pTabbedControlBar = nullptr;
      v29->AttachToTabWnd(this: v56, a2: m_pBarLeftTop, a3: DM_DBL_CLICK, a4: 1, a5: &pTabbedControlBar);
      if ( pTabbedControlBar != nullptr )
      {
        v26 = this->m_pBarLeftTop;
        v27 = this->m_pContainerManager;
        v49 = pTabbedControlBar;
        if ( v26 == nullptr )
        {
          CPaneContainerManager::AddPaneToList(this: v27, pControlBarToAdd: pTabbedControlBar);
          this->m_pBarLeftTop = pTabbedControlBar;
          return pTabbedControlBar;
        }
        goto LABEL_49;
      }
      return pTabbedControlBar;
    }
    this->m_pBarLeftTop = v56;
    m_pBarRightBottom = this->m_pBarRightBottom;
    if ( m_pBarRightBottom != nullptr || (bIsLeftContainer = 0, this->m_pRightContainer != nullptr) )
      bIsLeftContainer = 1;
    if ( m_pBarRightBottom != nullptr )
    {
      GetWindowRect(hWnd: m_pBarRightBottom->m_hWnd, lpRect: &rectSecondBar);
    }
    else
    {
      m_pRightContainer = this->m_pRightContainer;
      if ( m_pRightContainer != nullptr )
        m_pRightContainer->GetWindowRect(this: m_pRightContainer, a2: &rectSecondBar, a3: 0);
    }
    CWnd::ScreenToClient(this: pDockSite, lpRect: (tagPOINT *)&rectSecondBar);
    if ( this->m_pSlider != nullptr )
    {
      v32 = CPaneContainer::IsPaneDividerHorz(this) == 0;
      v33 = this->m_pSlider;
      if ( v32 )
      {
        rectSlider.left = rectNew.right;
        rectSlider.right = rectNew.right + v33->m_nWidth;
        rectSecondBar.left = rectSlider.right;
      }
      else
      {
        rectSlider.top = rectNew.bottom;
        rectSlider.bottom = rectNew.bottom + v33->m_nWidth;
        rectSecondBar.top = rectSlider.bottom;
      }
    }
    v34 = this->m_pBarRightBottom;
    if ( v34 == nullptr )
    {
      v35 = this->m_pRightContainer;
      goto LABEL_79;
    }
LABEL_77:
    hdwp = v34->MoveWindow(this: &v34->CPane, a2: &rectSecondBar, a3: 0, a4: hdwp);
    goto LABEL_81;
  }
  m_pLeftContainer = this->m_pRightContainer;
  if ( m_pLeftContainer != nullptr )
    return CPaneContainer::AddPane(this: m_pLeftContainer, pBar: v56);
  v24 = this->m_pBarRightBottom;
  if ( v24 != nullptr )
  {
    v25 = v56->__vftable;
    pTabbedControlBar = nullptr;
    v25->AttachToTabWnd(this: v56, a2: v24, a3: DM_DBL_CLICK, a4: 1, a5: &pTabbedControlBar);
    if ( pTabbedControlBar != nullptr )
    {
      v26 = this->m_pBarRightBottom;
      v27 = this->m_pContainerManager;
      v49 = pTabbedControlBar;
      if ( v26 != nullptr )
      {
LABEL_49:
        v27->ReplacePane(this: v27, a2: v26, a3: v49);
        return pTabbedControlBar;
      }
      CPaneContainerManager::AddPaneToList(this: v27, pControlBarToAdd: pTabbedControlBar);
      this->m_pBarRightBottom = pTabbedControlBar;
    }
    return pTabbedControlBar;
  }
  this->m_pBarRightBottom = v56;
  v36 = this->m_pBarLeftTop;
  if ( v36 != nullptr || (bIsLeftContainer = 0, this->m_pLeftContainer != nullptr) )
    bIsLeftContainer = 1;
  if ( v36 != nullptr )
  {
    GetWindowRect(hWnd: v36->m_hWnd, lpRect: &rectSecondBar);
  }
  else
  {
    v37 = this->m_pLeftContainer;
    if ( v37 != nullptr )
      v37->GetWindowRect(this: v37, a2: &rectSecondBar, a3: 0);
  }
  CWnd::ScreenToClient(this: pDockSite, lpRect: (tagPOINT *)&rectSecondBar);
  if ( this->m_pSlider != nullptr )
  {
    IsPaneDividerHorz = CPaneContainer::IsPaneDividerHorz(this);
    v39 = this->m_pSlider;
    if ( IsPaneDividerHorz != 0 )
    {
      rectSlider.bottom = rectNew.top;
      rectSlider.top = rectNew.top - v39->m_nWidth;
      rectSecondBar.bottom = rectSlider.top;
    }
    else
    {
      rectSlider.right = rectNew.left;
      rectSlider.left = rectNew.left - v39->m_nWidth;
      rectSecondBar.right = rectSlider.left;
    }
  }
  v34 = this->m_pBarLeftTop;
  if ( v34 != nullptr )
    goto LABEL_77;
  v35 = this->m_pLeftContainer;
LABEL_79:
  if ( v35 != nullptr )
    ((void (__thiscall *)(CPaneContainer *, int, int, int, int, void **, _DWORD))v35->Resize)(
      a1: v35,
      a2: rectSecondBar.left,
      a3: rectSecondBar.top,
      a4: rectSecondBar.right,
      a5: rectSecondBar.bottom,
      a6: &hdwp,
      a7: 0);
LABEL_81:
  v40 = this->m_pSlider;
  if ( v40 != nullptr )
  {
    if ( bIsLeftContainer != 0 )
      hdwp = v40->MoveWindow(this: v40, a2: &rectSlider, a3: 0, a4: hdwp);
    else
      CPaneDivider::ShowWindow(this: v40, nCmdShow: 0);
  }
  UnionRect(lprcDst: &rectContainer, lprcSrc1: &rectNew, lprcSrc2: &rectSecondBar);
  CWnd::ClientToScreen(this: pDockSite, lpRect: (tagPOINT *)&rectContainer);
  if ( bExpandParentContainer && pNextContainer != nullptr )
  {
    v41 = pNextContainer->m_pSlider;
    if ( v41 != nullptr )
    {
      v42 = pNextContainer->m_pLeftContainer;
      v43 = pNextContainer->m_pRightContainer;
      if ( v42 != nullptr
        && CPaneContainer::FindSubPaneContainer(this: v42, pObject: this, findCriteria: BC_FIND_BY_CONTAINER) != nullptr )
      {
        bIsLeftContainer = 1;
      }
      else
      {
        if ( v43 == nullptr
          || CPaneContainer::FindSubPaneContainer(this: v43, pObject: this, findCriteria: BC_FIND_BY_CONTAINER) == nullptr )
        {
          return v56;
        }
        bIsLeftContainer = 0;
      }
      GetWindowRect(hWnd: v41->m_hWnd, lpRect: &rectSlider);
      m_nWidth = v41->m_nWidth;
      v45 = v41->IsHorizontal(this: v41);
      if ( bIsLeftContainer != 0 )
      {
        if ( v45 != 0 )
        {
          v46 = nNewHeight + m_nWidth;
          rectSlider.top = rectContainer.bottom;
          rectSlider.bottom = rectContainer.bottom + v41->m_nWidth;
        }
        else
        {
          v46 = (int)pTabbedControlBar + m_nWidth;
          rectSlider.left = rectContainer.right;
          rectSlider.right = rectContainer.right + v41->m_nWidth;
        }
      }
      else
      {
        v47 = v41->m_nWidth;
        if ( v45 != 0 )
        {
          v46 = -(nNewHeight + v47);
          rectSlider.bottom = rectContainer.top;
          rectSlider.top = rectContainer.top - v41->m_nWidth;
        }
        else
        {
          v46 = -((int)pTabbedControlBar + v47);
          rectSlider.right = rectContainer.left;
          rectSlider.left = rectContainer.left - v41->m_nWidth;
        }
      }
      CWnd::ScreenToClient(this: pDockSite, lpRect: (tagPOINT *)&rectSlider);
      v48 = this->m_pSlider;
      if ( v48 != nullptr )
        hdwp = v48->MoveWindow(this: v48, a2: &rectSlider, a3: 0, a4: hdwp);
      pNextContainer->ResizePartOfPaneContainer(this: pNextContainer, a2: v46, a3: bIsLeftContainer == 0, a4: &hdwp);
    }
  }
  EndDeferWindowPos(hWinPosInfo: hdwp);
  return v56;
}

//------------------------------------------------------------------------------
// Address: 0x103FEBA2
// Name: public: virtual void CPaneContainer::ResizePartOfPaneContainer(int,int,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::ResizePartOfPaneContainer(
        CPaneContainer *this,
        int nOffset,
        int bLeftPart,
        void **hdwp)
{
  CDockablePane *m_pBarLeftTop; // eax
  CDockablePane *v6; // ecx
  int v7; // edx
  CDockablePane *m_pBarRightBottom; // eax
  int v9; // edx
  CWnd *v10; // eax
  CPaneContainer *m_pLeftContainer; // ecx
  CDockablePane *v12; // ecx
  CSize sizeMin; // [esp+Ch] [ebp-1Ch] BYREF
  CRect rectPart; // [esp+14h] [ebp-14h] BYREF

  if ( this->m_pSlider == nullptr )
    return;
  memset(&rectPart, 0, sizeof(rectPart));
  SetRectEmpty(lprc: &rectPart);
  sizeMin.cx = 0;
  sizeMin.cy = 0;
  if ( bLeftPart != 0 )
  {
    if ( this->m_pLeftContainer != nullptr )
    {
      this->m_pLeftContainer->GetWindowRect(this: this->m_pLeftContainer, a2: &rectPart, a3: 0);
      this->m_pLeftContainer->GetMinSize(this: this->m_pLeftContainer, a2: &sizeMin);
      goto LABEL_15;
    }
    m_pBarLeftTop = this->m_pBarLeftTop;
    if ( m_pBarLeftTop == nullptr )
      return;
    GetWindowRect(hWnd: m_pBarLeftTop->m_hWnd, lpRect: &rectPart);
    v6 = this->m_pBarLeftTop;
  }
  else
  {
    if ( this->m_pRightContainer != nullptr )
    {
      this->m_pRightContainer->GetWindowRect(this: this->m_pRightContainer, a2: &rectPart, a3: 0);
      this->m_pRightContainer->GetMinSize(this: this->m_pRightContainer, a2: &sizeMin);
      goto LABEL_9;
    }
    m_pBarRightBottom = this->m_pBarRightBottom;
    if ( m_pBarRightBottom == nullptr )
      return;
    GetWindowRect(hWnd: m_pBarRightBottom->m_hWnd, lpRect: &rectPart);
    v6 = this->m_pBarRightBottom;
  }
  v6->GetMinSize(this: &v6->CPane, a2: &sizeMin);
LABEL_15:
  if ( bLeftPart == 0 )
  {
LABEL_9:
    if ( CPaneContainer::IsPaneDividerHorz(this) != 0 )
    {
      v7 = rectPart.bottom - (nOffset + rectPart.top);
      rectPart.top += nOffset;
      if ( v7 < sizeMin.cy )
        rectPart.top = rectPart.bottom - sizeMin.cy;
      goto LABEL_24;
    }
    goto LABEL_22;
  }
  if ( CPaneContainer::IsPaneDividerHorz(this) == 0 )
  {
    if ( CPaneContainer::IsPaneDividerHorz(this) == 0 )
    {
      rectPart.right += nOffset;
      if ( rectPart.right - rectPart.left < sizeMin.cx )
        rectPart.right = sizeMin.cx + rectPart.left;
      goto LABEL_24;
    }
LABEL_22:
    v9 = rectPart.right - (nOffset + rectPart.left);
    rectPart.left += nOffset;
    if ( v9 < sizeMin.cx )
      rectPart.left = rectPart.right - sizeMin.cx;
    goto LABEL_24;
  }
  rectPart.bottom += nOffset;
  if ( rectPart.bottom - rectPart.top < sizeMin.cy )
    rectPart.bottom = sizeMin.cy + rectPart.top;
LABEL_24:
  v10 = this->m_pContainerManager->GetDockSiteFrameWnd(this: this->m_pContainerManager);
  CWnd::ScreenToClient(this: v10, lpRect: (tagPOINT *)&rectPart);
  if ( bLeftPart != 0 )
  {
    if ( this->m_pLeftContainer != nullptr )
    {
      m_pLeftContainer = this->m_pLeftContainer;
LABEL_31:
      ((void (__thiscall *)(CPaneContainer *, int, int, int, int, void **, _DWORD))m_pLeftContainer->Resize)(
        a1: m_pLeftContainer,
        a2: rectPart.left,
        a3: rectPart.top,
        a4: rectPart.right,
        a5: rectPart.bottom,
        a6: hdwp,
        a7: 0);
      return;
    }
    if ( this->m_pBarLeftTop == nullptr )
      return;
    v12 = this->m_pBarLeftTop;
    goto LABEL_34;
  }
  if ( this->m_pRightContainer != nullptr )
  {
    m_pLeftContainer = this->m_pRightContainer;
    goto LABEL_31;
  }
  if ( this->m_pBarRightBottom != nullptr )
  {
    v12 = this->m_pBarRightBottom;
LABEL_34:
    *hdwp = v12->MoveWindow(this: &v12->CPane, a2: &rectPart, a3: 0, a4: *hdwp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FED81
// Name: public: int CPaneContainer::AddSubPaneContainer(class CPaneContainer __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneContainer *__thiscall CPaneContainer::AddSubPaneContainer(
        CPaneContainer *this,
        CPaneContainer *pContainer,
        int bRightNodeNew)
{
  CDockablePane *m_pBarLeftTop; // esi
  CPaneContainer *result; // eax

  if ( this->m_pSlider == pContainer->m_pSlider
    || (m_pBarLeftTop = pContainer->m_pBarLeftTop) == nullptr && pContainer->m_pBarRightBottom == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  if ( bRightNodeNew == 0 )
    m_pBarLeftTop = pContainer->m_pBarRightBottom;
  result = CPaneContainer::FindSubPaneContainer(this, pObject: m_pBarLeftTop, findCriteria: BC_FIND_BY_LEFT_BAR);
  if ( result != nullptr
    || (result = CPaneContainer::FindSubPaneContainer(this, pObject: m_pBarLeftTop, findCriteria: BC_FIND_BY_RIGHT_BAR)) != nullptr )
  {
    CPaneContainer::AddNode(this: result, pContainer);
    return (CPaneContainer *)1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEDDC
// Name: public: virtual void CPaneContainer::RemovePane(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::RemovePane(CPaneContainer *this, CDockablePane *pBar)
{
  int v2; // edi
  CPaneContainer *SubPaneContainer; // eax

  v2 = 0;
  SubPaneContainer = CPaneContainer::FindSubPaneContainer(this, pObject: pBar, findCriteria: BC_FIND_BY_LEFT_BAR);
  if ( SubPaneContainer != nullptr
    || (v2 = 1,
        (SubPaneContainer = CPaneContainer::FindSubPaneContainer(
                              this,
                              pObject: pBar,
                              findCriteria: BC_FIND_BY_RIGHT_BAR)) != nullptr) )
  {
    SubPaneContainer->DeletePane(this: SubPaneContainer, a2: pBar, a3: (CPaneContainer::BC_FIND_CRITERIA)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FEE15
// Name: protected: void CPaneContainer::FreeReleasedPaneContainer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::FreeReleasedPaneContainer(CPaneContainer *this)
{
  int v2; // eax
  CPaneDivider *m_pSlider; // eax
  CPaneContainer *m_pParentContainer; // eax
  CPaneContainer *m_pLeftContainer; // ecx
  BOOL v6; // ecx
  CDockablePane *m_pBarLeftTop; // eax
  CDockablePane *m_pBarRightBottom; // eax
  CPaneContainer *v9; // eax
  CPaneContainer *m_pRightContainer; // eax
  CPaneDivider *v11; // ecx

  v2 = this->m_pBarLeftTop != nullptr;
  if ( this->m_pBarRightBottom != nullptr )
    ++v2;
  if ( this->m_pLeftContainer != nullptr )
    ++v2;
  if ( this->m_pRightContainer != nullptr )
    ++v2;
  if ( v2 <= 1 && this->m_dwRefCount <= 0 )
  {
    m_pSlider = this->m_pSlider;
    if ( m_pSlider != nullptr && m_pSlider->m_bDefaultDivider != 0
      || (m_pParentContainer = this->m_pParentContainer) == nullptr
      || m_pParentContainer == this->m_pContainerManager->m_pRootContainer )
    {
      CPaneContainerManager::NotifyPaneDivider(this: this->m_pContainerManager);
    }
    else
    {
      m_pLeftContainer = m_pParentContainer->m_pLeftContainer;
      if ( m_pLeftContainer == nullptr && m_pParentContainer->m_pRightContainer == nullptr )
        AfxThrowInvalidArgException();
      v6 = m_pLeftContainer == this;
      if ( v6 )
        m_pParentContainer->m_pLeftContainer = nullptr;
      else
        m_pParentContainer->m_pRightContainer = nullptr;
      m_pBarLeftTop = this->m_pBarLeftTop;
      if ( m_pBarLeftTop != nullptr )
      {
        CPaneContainer::SetPane(this: this->m_pParentContainer, pBar: m_pBarLeftTop, bLeft: v6);
        this->m_pBarLeftTop = nullptr;
      }
      else
      {
        m_pBarRightBottom = this->m_pBarRightBottom;
        if ( m_pBarRightBottom != nullptr )
        {
          CPaneContainer::SetPane(this: this->m_pParentContainer, pBar: m_pBarRightBottom, bLeft: v6);
          this->m_pBarRightBottom = nullptr;
        }
        else
        {
          v9 = this->m_pLeftContainer;
          if ( v9 != nullptr )
          {
            CPaneContainer::SetPaneContainer(this: this->m_pParentContainer, pContainer: v9, bLeft: v6);
            this->m_pLeftContainer = nullptr;
          }
          else
          {
            m_pRightContainer = this->m_pRightContainer;
            if ( m_pRightContainer != nullptr )
            {
              CPaneContainer::SetPaneContainer(this: this->m_pParentContainer, pContainer: m_pRightContainer, bLeft: v6);
              this->m_pRightContainer = nullptr;
            }
          }
        }
      }
      v11 = this->m_pSlider;
      if ( v11 != nullptr )
      {
        v11->DestroyWindow(this: v11);
        this->m_pSlider = nullptr;
      }
      this->m_bDisposed = 1;
      CPtrList::AddTail(this: &gc.m_lstDisposedContainers, newElement: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FEF21
// Name: public: void CPaneContainer::ReleaseEmptyPaneContainer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::ReleaseEmptyPaneContainer(CPaneContainer *this)
{
  CPaneContainer *m_pLeftContainer; // ecx
  CPaneContainer *m_pRightContainer; // ecx

  m_pLeftContainer = this->m_pLeftContainer;
  if ( m_pLeftContainer != nullptr )
    CPaneContainer::ReleaseEmptyPaneContainer(this: m_pLeftContainer);
  m_pRightContainer = this->m_pRightContainer;
  if ( m_pRightContainer != nullptr )
    CPaneContainer::ReleaseEmptyPaneContainer(this: m_pRightContainer);
  if ( this->m_pParentContainer != this->m_pContainerManager->m_pRootContainer )
    CPaneContainer::FreeReleasedPaneContainer(this);
}

//------------------------------------------------------------------------------
// Address: 0x103FEF53
// Name: public: virtual int CPaneContainer::StretchPaneContainer(int,int,int,int,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CPaneContainer::StretchPaneContainer(
        CPaneContainer *this,
        int nOffset,
        int bStretchHorz,
        int bLeftBar,
        int bMoveSlider,
        void **hdwp)
{
  CWnd *MainWnd; // eax
  LONG v8; // eax
  int v9; // ecx
  int v10; // eax
  CPaneContainer_vtbl *v11; // edx
  int v12; // edi
  signed int v13; // eax
  unsigned int v14; // eax
  unsigned int result; // eax
  int v16; // edi
  int v17; // eax
  unsigned int v18; // ebx
  int v19; // eax
  CPaneContainer_vtbl *v20; // eax
  CPaneDivider *m_pSlider; // eax
  HWND Parent; // eax
  CWnd *v23; // eax
  int nDirection; // [esp+Ch] [ebp-28h]
  _BYTE v25[4]; // [esp+18h] [ebp-1Ch] BYREF
  int nActualSize; // [esp+1Ch] [ebp-18h]
  CPoint pt; // [esp+20h] [ebp-14h] BYREF
  int v28; // [esp+28h] [ebp-Ch] BYREF
  int v29; // [esp+2Ch] [ebp-8h]

  MainWnd = AfxGetMainWnd();
  v8 = CWnd::GetExStyle(this: MainWnd);
  v9 = 0;
  if ( (v8 & 0x400000) != 0 && bStretchHorz != 0 )
    nOffset = -nOffset;
  nDirection = 2 * (nOffset >= 0) - 1;
  v10 = 0;
  if ( bStretchHorz != 0 )
    v9 = nOffset;
  else
    v10 = nOffset;
  v11 = this->__vftable;
  if ( bStretchHorz != 0 )
    v12 = *(_DWORD *)((int (__thiscall *)(CPaneContainer *, int *, int, int, int))v11->CalcAvailableSpace)(
                       a1: this,
                       a2: &v28,
                       a3: v9,
                       a4: v10,
                       a5: bLeftBar);
  else
    v12 = *(_DWORD *)(((int (__thiscall *)(CPaneContainer *, _BYTE *, int, int, int))v11->CalcAvailableSpace)(
                        a1: this,
                        a2: v25,
                        a3: v9,
                        a4: v10,
                        a5: bLeftBar)
                    + 4);
  nActualSize = abs(lnumber: v12);
  v13 = abs(lnumber: nOffset);
  if ( v13 >= nActualSize )
    v14 = abs(lnumber: v12);
  else
    v14 = abs(lnumber: nOffset);
  nActualSize = nDirection * v14;
  result = abs(lnumber: nDirection * v14);
  if ( result != 0 )
  {
    if ( this->m_pSlider != nullptr
      && (this->m_pSlider->IsHorizontal(this: this->m_pSlider) == 0 || bStretchHorz == 0)
      && (this->m_pSlider->IsHorizontal(this: this->m_pSlider) != 0 || bStretchHorz != 0) )
    {
      v16 = this->CalcAvailablePaneSpace(
              this,
              a2: nOffset,
              a3: (CPane *)this->m_pBarLeftTop,
              a4: this->m_pLeftContainer,
              a5: bLeftBar);
      v17 = this->CalcAvailablePaneSpace(
              this,
              a2: nOffset,
              a3: (CPane *)this->m_pBarRightBottom,
              a4: this->m_pRightContainer,
              a5: bLeftBar);
      v18 = abs(lnumber: v17);
      if ( abs(lnumber: v16) == v18 )
        v19 = nDirection * ((int)abs(lnumber: v16) / 2 + 1);
      else
        v19 = nActualSize;
      v28 = 0;
      v29 = 0;
      if ( bStretchHorz != 0 )
        v28 = v19;
      else
        v29 = v19;
      if ( bMoveSlider != 0 )
        this->m_pSlider->Move(this: this->m_pSlider, a2: (CPoint *)&v28, a3: 1);
      v20 = this->__vftable;
      if ( bLeftBar != 0 )
        ((void (__stdcall *)(int, CDockablePane *, CPaneContainer *, int, int, void **))v20->ResizePane)(
          a1: nActualSize,
          a2: this->m_pBarRightBottom,
          a3: this->m_pRightContainer,
          a4: bStretchHorz,
          a5: bLeftBar,
          a6: hdwp);
      else
        ((void (__stdcall *)(int, CDockablePane *, CPaneContainer *, int, _DWORD, void **))v20->ResizePane)(
          a1: nActualSize,
          a2: this->m_pBarLeftTop,
          a3: this->m_pLeftContainer,
          a4: bStretchHorz,
          a5: 0,
          a6: hdwp);
    }
    else
    {
      this->ResizePane(
        this,
        a2: nActualSize,
        a3: (CPane *)this->m_pBarLeftTop,
        a4: this->m_pLeftContainer,
        a5: bStretchHorz,
        a6: bLeftBar,
        a7: hdwp);
      this->ResizePane(
        this,
        a2: nActualSize,
        a3: (CPane *)this->m_pBarRightBottom,
        a4: this->m_pRightContainer,
        a5: bStretchHorz,
        a6: bLeftBar,
        a7: hdwp);
      if ( bMoveSlider != 0 )
      {
        m_pSlider = this->m_pSlider;
        if ( m_pSlider != nullptr )
        {
          pt.x = 0;
          pt.y = 0;
          v28 = 0;
          v29 = 0;
          GetWindowRect(hWnd: m_pSlider->m_hWnd, lpRect: (LPRECT)&pt);
          if ( this->m_pSlider->IsHorizontal(this: this->m_pSlider) != 0 )
          {
            if ( bLeftBar != 0 )
              v28 += nActualSize;
            else
              pt.x += nActualSize;
          }
          else if ( bLeftBar != 0 )
          {
            v29 += nActualSize;
          }
          else
          {
            pt.y += nActualSize;
          }
          if ( (CWnd::GetStyle(this: this->m_pSlider) & 0x10000000) != 0 )
          {
            Parent = GetParent(hWnd: this->m_pSlider->m_hWnd);
            v23 = CWnd::FromHandle(hWnd: Parent);
            CWnd::ScreenToClient(this: v23, lpRect: &pt);
            this->m_pSlider->MoveWindow(this: this->m_pSlider, a2: (CRect *)&pt, a3: 0, a4: *hdwp);
          }
        }
      }
    }
    return nActualSize;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF1D3
// Name: public: virtual int CPaneContainer::OnMoveInternalPaneDivider(int,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneContainer::OnMoveInternalPaneDivider(CPaneContainer *this, int nOffset, void **hdwp)
{
  CDockablePane *m_pBarLeftTop; // eax
  CDockablePane *m_pBarRightBottom; // eax
  HWND Parent; // eax
  CWnd *v7; // eax
  HWND v8; // eax
  CWnd *v9; // eax
  void **v10; // edi
  CSize sizeMinLeft; // [esp+Ch] [ebp-38h] BYREF
  void **v13; // [esp+14h] [ebp-30h]
  CSize sizeMinRight; // [esp+18h] [ebp-2Ch] BYREF
  CRect rectLeft; // [esp+20h] [ebp-24h] BYREF
  CRect rectRight; // [esp+30h] [ebp-14h] BYREF

  v13 = hdwp;
  memset(&rectLeft, 0, sizeof(rectLeft));
  SetRectEmpty(lprc: &rectLeft);
  memset(&rectRight, 0, sizeof(rectRight));
  SetRectEmpty(lprc: &rectRight);
  m_pBarLeftTop = this->m_pBarLeftTop;
  sizeMinLeft.cx = 0;
  sizeMinLeft.cy = 0;
  sizeMinRight.cx = 0;
  sizeMinRight.cy = 0;
  if ( m_pBarLeftTop != nullptr )
  {
    GetWindowRect(hWnd: m_pBarLeftTop->m_hWnd, lpRect: &rectLeft);
    this->m_pBarLeftTop->GetMinSize(this: (CPane *)this->m_pBarLeftTop, a2: &sizeMinLeft);
  }
  if ( this->m_pLeftContainer != nullptr )
  {
    this->m_pLeftContainer->GetWindowRect(this: this->m_pLeftContainer, a2: &rectLeft, a3: 0);
    this->m_pLeftContainer->GetMinSize(this: this->m_pLeftContainer, a2: &sizeMinLeft);
  }
  m_pBarRightBottom = this->m_pBarRightBottom;
  if ( m_pBarRightBottom != nullptr )
  {
    GetWindowRect(hWnd: m_pBarRightBottom->m_hWnd, lpRect: &rectRight);
    this->m_pBarRightBottom->GetMinSize(this: (CPane *)this->m_pBarRightBottom, a2: &sizeMinRight);
  }
  if ( this->m_pRightContainer != nullptr )
  {
    this->m_pRightContainer->GetWindowRect(this: this->m_pRightContainer, a2: &rectRight, a3: 0);
    this->m_pRightContainer->GetMinSize(this: this->m_pRightContainer, a2: &sizeMinRight);
  }
  Parent = GetParent(hWnd: this->m_pSlider->m_hWnd);
  v7 = CWnd::FromHandle(hWnd: Parent);
  CWnd::ScreenToClient(this: v7, lpRect: (tagPOINT *)&rectLeft);
  v8 = GetParent(hWnd: this->m_pSlider->m_hWnd);
  v9 = CWnd::FromHandle(hWnd: v8);
  CWnd::ScreenToClient(this: v9, lpRect: (tagPOINT *)&rectRight);
  if ( !IsRectEmpty(lprc: &rectLeft) )
  {
    if ( CPaneContainer::IsPaneDividerHorz(this) != 0 )
    {
      rectLeft.bottom += nOffset;
      if ( rectLeft.bottom - rectLeft.top < sizeMinLeft.cy )
        rectLeft.bottom = sizeMinLeft.cy + rectLeft.top;
    }
    else
    {
      rectLeft.right += nOffset;
      if ( rectLeft.right - rectLeft.left < sizeMinLeft.cx )
        rectLeft.right = sizeMinLeft.cx + rectLeft.left;
    }
  }
  if ( !IsRectEmpty(lprc: &rectRight) )
  {
    if ( CPaneContainer::IsPaneDividerHorz(this) != 0 )
    {
      rectRight.top += nOffset;
      if ( rectRight.bottom - rectRight.top < sizeMinRight.cy )
        rectRight.top = rectRight.bottom - sizeMinRight.cy;
    }
    else
    {
      rectRight.left += nOffset;
      if ( rectRight.right - rectRight.left < sizeMinRight.cx )
        rectRight.left = rectRight.right - sizeMinRight.cx;
    }
  }
  v10 = v13;
  if ( this->m_pBarLeftTop != nullptr )
    *v10 = this->m_pBarLeftTop->MoveWindow(this: this->m_pBarLeftTop, a2: &rectLeft, a3: 1, a4: *v13);
  if ( this->m_pLeftContainer != nullptr )
  {
    ((void (__thiscall *)(CPaneContainer *, int, int, int, int, void **, _DWORD))this->m_pLeftContainer->Resize)(
      a1: this->m_pLeftContainer,
      a2: rectLeft.left,
      a3: rectLeft.top,
      a4: rectLeft.right,
      a5: rectLeft.bottom,
      a6: v10,
      a7: 0);
    v10 = v13;
  }
  if ( this->m_pBarRightBottom != nullptr )
    *v10 = this->m_pBarRightBottom->MoveWindow(this: this->m_pBarRightBottom, a2: &rectRight, a3: 1, a4: *v10);
  if ( this->m_pRightContainer != nullptr )
    ((void (__thiscall *)(CPaneContainer *, int, int, int, int, void **, _DWORD))this->m_pRightContainer->Resize)(
      a1: this->m_pRightContainer,
      a2: rectRight.left,
      a3: rectRight.top,
      a4: rectRight.right,
      a5: rectRight.bottom,
      a6: v10,
      a7: 0);
  return nOffset;
}

//------------------------------------------------------------------------------
// Address: 0x103FF3FF
// Name: public: virtual void CPaneContainer::ResizePane(int,class CPane __near *,class CPaneContainer __near *,int,int,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::ResizePane(
        CPaneContainer *this,
        int nOffset,
        CPane *pBar,
        CPaneContainer *pContainer,
        int bHorz,
        int bLeftBar,
        void **hdwp)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-30h]
  _BYTE v8[8]; // [esp+Ch] [ebp-1Ch] BYREF
  CRect rectBar; // [esp+14h] [ebp-14h] BYREF

  if ( pBar != nullptr )
  {
    m_hWnd = pBar->m_hWnd;
    memset(&rectBar, 0, sizeof(rectBar));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rectBar);
    if ( bHorz != 0 )
    {
      if ( bLeftBar != 0 )
        rectBar.bottom += nOffset;
      else
        rectBar.top -= nOffset;
    }
    else if ( bLeftBar != 0 )
    {
      rectBar.right += nOffset;
    }
    else
    {
      rectBar.left += nOffset;
    }
    ((void (__thiscall *)(CPane *, _BYTE *, int, int, int, int, _DWORD, void **))pBar->MovePane)(
      a1: pBar,
      a2: v8,
      a3: rectBar.left,
      a4: rectBar.top,
      a5: rectBar.right,
      a6: rectBar.bottom,
      a7: 0,
      a8: hdwp);
  }
  else if ( pContainer != nullptr )
  {
    pContainer->StretchPaneContainer(this: pContainer, a2: nOffset, a3: bHorz, a4: bLeftBar, a5: 1, a6: hdwp);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004E9F90
// Name: public: static char const __near * CProceduralTexturePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CProceduralTexturePanel::GetPanelClassName()
{
  return "CProceduralTexturePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004E9FA0
// Name: public: virtual bool CProceduralTexturePanel::Init(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CProceduralTexturePanel::Init(
        CProceduralTexturePanel *this,
        int nWidth,
        int nHeight,
        bool bAllocateImageBuffer)
{
  const char *(__thiscall *GetName)(vgui::IClientPanel *); // edx
  const char *v6; // eax
  IMaterialSystem *v7; // eax
  ITexture *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  IMaterialSystem *v11; // eax
  IMaterial *v12; // ebx
  IMaterialVar *v13; // eax
  IMatSystemSurface *v14; // eax
  IMatSystemSurface *v15; // eax
  char pTemp[512]; // [esp+Ch] [ebp-200h] BYREF

  this->m_nWidth = nWidth;
  this->m_nHeight = nHeight;
  if ( bAllocateImageBuffer )
    this->m_pImageBuffer = (BGRA8888_t *)MemAlloc_Alloc(
                                           nSize: (unsigned __int64)(unsigned int)(nHeight * nWidth) >> 30 != 0
                                         ? -1
                                         : 4 * nHeight * nWidth);
  this->m_TextureSubRect.y = 0;
  this->m_TextureSubRect.x = 0;
  GetName = this->GetName;
  this->m_TextureSubRect.width = nWidth;
  this->m_TextureSubRect.height = nHeight;
  v6 = GetName(this);
  V_snprintf(pDest: pTemp, maxLen: 512, pFormat: "__%s", v6);
  v7 = vgui::MaterialSystem();
  v8 = v7->CreateProceduralTexture(
         this: v7,
         a2: pTemp,
         a3: "VGUI textures",
         a4: this->m_nWidth,
         a5: this->m_nHeight,
         a6: IMAGE_FORMAT_BGRX8888,
         a7: 264972);
  v8->SetTextureRegenerator(this: v8, a2: &this->ITextureRegenerator, a3: true);
  CTextureReference::Init(this: &this->m_ProceduralTexture, pTexture: v8);
  v8->DecrementReferenceCount(this: v8);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "UnlitGeneric");
  else
    v10 = nullptr;
  KeyValues::SetString(this: v10, keyName: "$basetexture", value: pTemp);
  KeyValues::SetInt(this: v10, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v10, keyName: "$nodebug", value: 1);
  v11 = vgui::MaterialSystem();
  v12 = v11->CreateMaterial(this: v11, a2: pTemp, a3: v10);
  CMaterialReference::Init(this: &this->m_ProceduralMaterial, pMaterial: v12);
  v12->DecrementReferenceCount(this: v12);
  v13 = this->m_ProceduralMaterial.m_pMaterial->FindVarFast(
          this: this->m_ProceduralMaterial.m_pMaterial,
          a2: "$basetexture",
          a3: &textureVarCache);
  v13->SetTextureValue(this: v13, a2: v8);
  v14 = vgui::MatSystemSurface();
  this->m_nTextureID = v14->CreateNewTextureID(this: v14, a2: false);
  v15 = vgui::MatSystemSurface();
  v15->DrawSetTextureMaterial(this: v15, a2: this->m_nTextureID, a3: this->m_ProceduralMaterial.m_pMaterial);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA170
// Name: public: void CProceduralTexturePanel::MaintainProportions(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::MaintainProportions(CProceduralTexturePanel *this, bool bEnable)
{
  this->m_bMaintainProportions = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x004EA180
// Name: private: void CProceduralTexturePanel::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::CleanUp(CProceduralTexturePanel *this)
{
  IMatSystemSurface *v2; // eax
  ITexture *m_pTexture; // ecx

  if ( this->m_nTextureID != -1 )
  {
    v2 = vgui::MatSystemSurface();
    v2->DestroyTextureID(this: v2, a2: this->m_nTextureID);
    this->m_nTextureID = -1;
  }
  if ( this->m_ProceduralMaterial.m_pMaterial != nullptr )
    CMaterialReference::Shutdown(this: &this->m_ProceduralMaterial, bDeleteIfUnreferenced: true);
  m_pTexture = this->m_ProceduralTexture.m_pTexture;
  if ( m_pTexture != nullptr )
  {
    m_pTexture->SetTextureRegenerator(this: m_pTexture, a2: nullptr, a3: true);
    CTextureReference::Shutdown(this: &this->m_ProceduralTexture, bDeleteIfUnReferenced: true);
  }
  if ( this->m_pImageBuffer != nullptr )
  {
    free(pMem: this->m_pImageBuffer);
    this->m_pImageBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EA210
// Name: public: struct BGRA8888_t __near * CProceduralTexturePanel::GetImageBuffer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProceduralTexturePanel::GetImageBuffer(vgui::TreeView *this)
{
  return this->m_nRowHeight;
}

//------------------------------------------------------------------------------
// Address: 0x004EA220
// Name: public: int CProceduralTexturePanel::GetImageWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProceduralTexturePanel::GetImageWidth(CProceduralTexturePanel *this)
{
  return this->m_nWidth;
}

//------------------------------------------------------------------------------
// Address: 0x004EA230
// Name: public: void CProceduralTexturePanel::SetPaintRect(struct Rect_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::SetPaintRect(CProceduralTexturePanel *this, const Rect_t *pPaintRect)
{
  this->m_bUsePaintRect = pPaintRect != nullptr;
  if ( pPaintRect != nullptr )
    this->m_PaintRect = *pPaintRect;
}

//------------------------------------------------------------------------------
// Address: 0x004EA270
// Name: public: void CProceduralTexturePanel::DownloadTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::DownloadTexture(CProceduralTexturePanel *this)
{
  this->m_ProceduralTexture.m_pTexture->Download(this: this->m_ProceduralTexture.m_pTexture, a2: nullptr, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004EA290
// Name: public: virtual void CProceduralTexturePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProceduralTexturePanel::Paint(CProceduralTexturePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int m_nTextureID; // eax
  int height; // ecx
  int v6; // ecx
  int width; // eax
  int h; // [esp+44h] [ebp-8h] BYREF
  int w; // [esp+48h] [ebp-4h] BYREF

  m_nTextureID = this->m_nTextureID;
  if ( m_nTextureID != -1 )
  {
    ((void (__thiscall *)(vgui::ISurface *, int, int, int))g_pVGuiSurface->DrawSetTexture)(
      a1: g_pVGuiSurface,
      a2: m_nTextureID,
      a3,
      a4: a2);
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    if ( this->m_bUsePaintRect )
    {
      height = this->m_PaintRect.height;
      w = this->m_PaintRect.width;
      h = height;
    }
    if ( this->m_bMaintainProportions )
    {
      v6 = this->m_TextureSubRect.height;
      width = this->m_TextureSubRect.width;
      if ( width <= v6 )
        w = h * width / v6;
      else
        h = w * v6 / this->m_TextureSubRect.width;
    }
    ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawTexturedPolygon)(a1: g_pVGuiSurface, a2: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EA440
// Name: public: CProceduralTexturePanel::CProceduralTexturePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CProceduralTexturePanel *__thiscall CProceduralTexturePanel::CProceduralTexturePanel(
        CProceduralTexturePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&ITextureRegenerator::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  if ( `CProceduralTexturePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
    v4->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
    v5->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CProceduralTexturePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
    v6->pfnClassName = CProceduralTexturePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CTextureReference::CTextureReference(this: &this->m_ProceduralTexture);
  CMaterialReference::CMaterialReference(
    this: &this->m_ProceduralMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_pImageBuffer = nullptr;
  *(_WORD *)&this->m_bMaintainProportions = 0;
  this->m_PaintRect.y = 0;
  this->m_PaintRect.x = 0;
  this->m_PaintRect.height = 0;
  this->m_PaintRect.width = 0;
  this->m_nTextureID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EA560
// Name: public: virtual struct vgui::PanelMessageMap __near * CProceduralTexturePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CProceduralTexturePanel::GetMessageMap(CProceduralTexturePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EA590
// Name: public: virtual struct PanelAnimationMap __near * CProceduralTexturePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CProceduralTexturePanel::GetAnimMap(CProceduralTexturePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004EA5A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CProceduralTexturePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CProceduralTexturePanel::GetKBMap(CProceduralTexturePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap;
  `CProceduralTexturePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  `CProceduralTexturePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EA5D0
// Name: public: virtual CProceduralTexturePanel::~CProceduralTexturePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::~CProceduralTexturePanel(CProceduralTexturePanel *this)
{
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CProceduralTexturePanel_vtbl *)&CProceduralTexturePanel::`vftable'{for `vgui::EditablePanel'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CProceduralTexturePanel::`vftable'{for `ITextureRegenerator'};
  CProceduralTexturePanel::CleanUp(this);
  CMaterialReference::~CMaterialReference(this: &this->m_ProceduralMaterial);
  CTextureReference::~CTextureReference(this: &this->m_ProceduralTexture);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EA610
// Name: public: virtual void CProceduralTexturePanel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CProceduralTexturePanel::Shutdown(CProceduralTexturePanel *this)
{
  CProceduralTexturePanel::CleanUp(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EA620
// Name: public: virtual void CProceduralTexturePanel::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProceduralTexturePanel::RegenerateTextureBits(
        CProceduralTexturePanel *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture_vtbl *v5; // eax
  ImageFormat v6; // eax
  ImageFormat v7; // esi
  __int16 v8; // bx
  int v9; // ecx
  unsigned __int8 *v10; // eax
  BGRA8888_t *v11; // eax
  unsigned __int8 v12; // dl
  int b; // edi
  int r; // esi
  unsigned int v15; // eax
  int v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // edx
  int v19; // eax
  unsigned __int64 v20; // rdi
  __int64 v21; // rax
  unsigned __int64 v22; // rdi
  unsigned __int8 *pixelWriter_4; // [esp+10h] [ebp-4Ch]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-46h]
  int pixelWriter_12; // [esp+18h] [ebp-44h]
  int pixelWriter_16; // [esp+1Ch] [ebp-40h]
  int pixelWriter_20; // [esp+20h] [ebp-3Ch]
  char pixelWriter_24; // [esp+24h] [ebp-38h]
  int pixelWriter_28; // [esp+28h] [ebp-34h]
  char pixelWriter_32; // [esp+2Ch] [ebp-30h]
  int nDepth; // [esp+38h] [ebp-24h] BYREF
  int v32; // [esp+3Ch] [ebp-20h]
  CProceduralTexturePanel *v33; // [esp+40h] [ebp-1Ch]
  int nHeight; // [esp+44h] [ebp-18h] BYREF
  unsigned __int8 *v35; // [esp+48h] [ebp-14h]
  int y; // [esp+4Ch] [ebp-10h]
  int nWidth; // [esp+50h] [ebp-Ch] BYREF
  int x; // [esp+54h] [ebp-8h]
  int v39; // [esp+58h] [ebp-4h]
  unsigned __int16 pTexel; // [esp+68h] [ebp+Ch]
  BGRA8888_t *pTexela; // [esp+68h] [ebp+Ch]

  v5 = pVTFTexture->__vftable;
  v33 = this;
  v5->ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  pTexel = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
  v35 = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
  v6 = pVTFTexture->Format(this: pVTFTexture);
  v7 = v6;
  switch ( v6 )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      pixelWriter_12 = 0x80000;
      v8 = 16;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case IMAGE_FORMAT_BGR888:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_18;
    case IMAGE_FORMAT_A8:
      v8 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA8888:
      pixelWriter_12 = 524304;
      v8 = 0;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      pixelWriter_32 = -1;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRX8888:
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      v8 = 0;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_24 = -1;
      pixelWriter_28 = 255;
      goto LABEL_21;
    case IMAGE_FORMAT_BGR565:
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      v8 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = -4;
      pixelWriter_28 = 248;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      v8 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_24 = -8;
      pixelWriter_28 = 248;
      pixelWriter_32 = 0x80;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v8 = -4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = -16;
      pixelWriter_28 = 240;
      pixelWriter_32 = -16;
      goto LABEL_22;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      v8 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      pixelWriter_24 = -1;
      pixelWriter_28 = 0xFFFF;
      pixelWriter_32 = -1;
      goto LABEL_22;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      v8 = 64;
      pixelWriter_16 = (int)&loc_60003D + 3;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_22;
    default:
      if ( `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v6] == 0 )
      {
        _Msg(a1: "CPixelWriter::SetPixelMemory:  Unsupported image format %i\n", v6);
        `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v7] = 1;
      }
      pixelWriter_10 = 0;
LABEL_18:
      pixelWriter_20 = 255;
LABEL_19:
      pixelWriter_12 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_20:
      v8 = 0;
      pixelWriter_16 = 0;
LABEL_21:
      pixelWriter_32 = 0;
LABEL_22:
      v9 = 0;
      y = 0;
      if ( nHeight > 0 )
      {
        v10 = v35;
        v32 = pTexel;
        do
        {
          pixelWriter_4 = v10;
          v11 = (BGRA8888_t *)(*(_DWORD *)&v33->m_OnCommand_register + 4 * v9 * *(_DWORD *)&v33->m_OnDelete_register);
          pTexela = v11;
          x = 0;
          if ( nWidth > 0 )
          {
            v12 = pixelWriter_10;
            v39 = pixelWriter_10;
            while ( 1 )
            {
              b = v11->b;
              r = v11->r;
              if ( v12 != 0 )
              {
                v15 = (unsigned __int8)(v11->g & pixelWriter_24);
                if ( v12 >= 5u )
                {
                  v20 = ((unsigned __int64)(unsigned __int8)(pTexela->r & pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)v15 << SBYTE2(pixelWriter_12));
                  if ( v8 <= 0 )
                    v21 = (__int64)(unsigned __int8)(pTexela->b & pixelWriter_28) >> -(char)v8;
                  else
                    v21 = (unsigned __int64)(unsigned __int8)(pTexela->b & pixelWriter_28) << v8;
                  v22 = v21
                      | ((unsigned __int64)(unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16))
                      | v20;
                  if ( v39 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v22;
                    *((_WORD *)pixelWriter_4 + 2) = WORD2(v22);
                  }
                  else if ( v39 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v22;
                  }
                }
                else
                {
                  v16 = ((r & pixelWriter_20) << pixelWriter_12) | (v15 << SBYTE2(pixelWriter_12));
                  v17 = b & pixelWriter_28;
                  if ( v8 <= 0 )
                    v18 = v17 >> -(char)pixelWriter_16;
                  else
                    v18 = v17 << pixelWriter_16;
                  v19 = v18 | ((unsigned __int8)(pTexela->a & pixelWriter_32) << SBYTE2(pixelWriter_16)) | v16;
                  switch ( v39 )
                  {
                    case 1:
                      *pixelWriter_4 = v19;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v19;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v19;
                      pixelWriter_4[2] = BYTE2(v19);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v19;
                      break;
                    default:
                      break;
                  }
                }
              }
              pixelWriter_4 += v39;
              v11 = pTexela + 1;
              ++x;
              ++pTexela;
              if ( x >= nWidth )
                break;
              v12 = pixelWriter_10;
            }
            v9 = y;
          }
          v10 = &v35[v32];
          y = ++v9;
          v35 += v32;
        }
        while ( v9 < nHeight );
      }
      return;
  }
}

} // namespace sceneviewer
