// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/imageborder.cpp
// Functions: 6
// ============================================================

#include "vgui2\src\imageborder.h"

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: public: virtual bool ImageBorder::PaintFirst(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ImageBorder::PaintFirst(ImageBorder *this)
{
  return this->m_bPaintFirst;
}

//------------------------------------------------------------------------------
// Address: 0x10001C20
// Name: protected: void ImageBorder::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ImageBorder::SetImage(ImageBorder *this, const char *imageName)
{
  int v3; // edi
  char *v4; // eax

  if ( this->m_pszImageName != nullptr )
  {
    free(pMem: this->m_pszImageName);
    this->m_pszImageName = nullptr;
  }
  if ( *imageName != 0 )
  {
    v3 = _V_strlen(str: imageName) + 6;
    free(pMem: this->m_pszImageName);
    v4 = (char *)operator new(nSize: v3);
    this->m_pszImageName = v4;
    V_snprintf(pDest: v4, maxLen: v3, pFormat: "vgui/%s", imageName);
    vgui::g_pSurface->DrawSetTextureFile(
      this: vgui::g_pSurface,
      a2: this->m_iTextureID,
      a3: this->m_pszImageName,
      a4: 1,
      a5: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001CA0
// Name: public: virtual void ImageBorder::Paint(int,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ImageBorder::Paint(
        ImageBorder *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        float wide,
        int tall,
        int breakSide,
        int breakStart,
        int breakEnd)
{
  char *m_pszImageName; // eax
  int v11; // edi
  int v12; // eax
  int v13; // ebx
  int v14; // esi
  float v15; // xmm4_4
  FontVertex_t verts[4]; // [esp+4h] [ebp-40h] BYREF

  m_pszImageName = this->m_pszImageName;
  if ( m_pszImageName != nullptr && *m_pszImageName != 0 )
  {
    ((void (__thiscall *)(vgui::ISurface *, int, int, int, int, int))vgui::g_pSurface->DrawSetColor_2)(
      a1: vgui::g_pSurface,
      a2: 255,
      a3: 255,
      a4: 255,
      a5: 255,
      a6: a2);
    vgui::g_pSurface->DrawSetTexture(this: vgui::g_pSurface, a2: this->m_iTextureID);
    if ( this->m_bTiled )
    {
      vgui::g_pSurface->DrawGetTextureSize(this: vgui::g_pSurface, a2: this->m_iTextureID, a3: &x, a4: &y);
      v11 = 0;
      if ( tall > 0 )
      {
        v12 = x;
        v13 = LODWORD(wide);
        do
        {
          v14 = 0;
          if ( v13 > 0 )
          {
            v15 = (float)v11;
            for ( wide = (float)v11; ; v15 = wide )
            {
              verts[0].m_Position.y = v15;
              verts[1].m_Position.y = v15;
              verts[0].m_Position.x = (float)v14;
              verts[0].m_TexCoord.x = 0.0;
              verts[0].m_TexCoord.y = 0.0;
              verts[1].m_Position.x = (float)(v14 + v12);
              verts[1].m_TexCoord.x = 1.0;
              verts[1].m_TexCoord.y = 0.0;
              verts[2].m_Position.x = verts[1].m_Position.x;
              verts[2].m_Position.y = (float)(v11 + y);
              verts[2].m_TexCoord.x = 1.0;
              verts[2].m_TexCoord.y = 1.0;
              verts[3].m_Position.x = (float)v14;
              verts[3].m_Position.y = verts[2].m_Position.y;
              verts[3].m_TexCoord.x = 0.0;
              verts[3].m_TexCoord.y = 1.0;
              vgui::g_pSurface->DrawTexturedPolygon(this: vgui::g_pSurface, a2: 4, a3: verts, a4: true);
              v12 = x;
              v14 += x;
              if ( v14 >= v13 )
                break;
            }
          }
          v11 += y;
        }
        while ( v11 < tall );
      }
    }
    else
    {
      verts[0].m_Position.y = (float)y;
      verts[1].m_Position.y = (float)y;
      verts[0].m_Position.x = (float)x;
      verts[0].m_TexCoord.x = 0.0;
      verts[0].m_TexCoord.y = 0.0;
      verts[1].m_Position.x = (float)(LODWORD(wide) + x);
      verts[1].m_TexCoord.x = 1.0;
      verts[1].m_TexCoord.y = 0.0;
      verts[2].m_Position.x = verts[1].m_Position.x;
      verts[2].m_Position.y = (float)(tall + y);
      verts[2].m_TexCoord.x = 1.0;
      verts[2].m_TexCoord.y = 1.0;
      verts[3].m_Position.x = (float)x;
      verts[3].m_Position.y = verts[2].m_Position.y;
      verts[3].m_TexCoord.x = 0.0;
      verts[3].m_TexCoord.y = 1.0;
      vgui::g_pSurface->DrawTexturedPolygon(this: vgui::g_pSurface, a2: 4, a3: verts, a4: true);
    }
    vgui::g_pSurface->DrawSetTexture(this: vgui::g_pSurface, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001EC0
// Name: public: virtual void ImageBorder::ApplySchemeSettings(class vgui::IScheme __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ImageBorder::ApplySchemeSettings(ImageBorder *this, vgui::IScheme *pScheme, KeyValues *inResourceData)
{
  const char *String; // eax

  this->m_eBackgroundType = KeyValues::GetInt(this: inResourceData, keyName: "backgroundtype", defaultValue: 0);
  this->m_bTiled = KeyValues::GetInt(this: inResourceData, keyName: "tiled", defaultValue: 0) != 0;
  String = KeyValues::GetString(this: inResourceData, keyName: "image", defaultValue: pHelpString);
  ImageBorder::SetImage(this, imageName: String);
  this->m_bPaintFirst = KeyValues::GetInt(this: inResourceData, keyName: "paintfirst", defaultValue: 1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001F80
// Name: public: ImageBorder::ImageBorder(void)
// Source: json
//------------------------------------------------------------------------------
ImageBorder *__thiscall ImageBorder::ImageBorder(ImageBorder *this)
{
  this->_name = nullptr;
  this->m_pszImageName = nullptr;
  this->__vftable = (ImageBorder_vtbl *)&ImageBorder::`vftable';
  this->m_eBackgroundType = BACKGROUND_TEXTURED;
  this->m_iTextureID = vgui::g_pSurface->CreateNewTextureID(this: vgui::g_pSurface, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001FB0
// Name: __CreateCInputWin32IInputInternal_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CInputWin32 *__cdecl _CreateCInputWin32IInputInternal_interface()
{
  return &g_Input;
}
