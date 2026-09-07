// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/bitmap.cpp
// Functions: 14
// ============================================================

#include "vgui2\src\bitmap.h"

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: public: virtual void vgui::Bitmap::SetRotation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Bitmap::SetRotation(vgui::Bitmap *this, int iRotation)
{
  this->_rotation = iRotation;
}

//------------------------------------------------------------------------------
// Address: 0x10001040
// Name: public: virtual void vgui::Bitmap::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Bitmap::GetSize(vgui::Bitmap *this, int *wide, int *tall)
{
  int *p_wide; // edi

  *wide = 0;
  *tall = 0;
  if ( this->_valid )
  {
    p_wide = &this->_wide;
    if ( this->_wide == 0 && this->_tall == 0 )
      vgui::g_pSurface->DrawGetTextureSize(this: vgui::g_pSurface, a2: this->_id, a3: &this->_wide, a4: &this->_tall);
    *wide = *p_wide;
    *tall = this->_tall;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100010A0
// Name: public: virtual void vgui::Bitmap::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Bitmap::GetContentSize(vgui::Bitmap *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x100010B0
// Name: public: virtual void vgui::Bitmap::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Bitmap::SetSize(vgui::Bitmap *this, int x, int y)
{
  this->_wide = x;
  this->_tall = y;
}

//------------------------------------------------------------------------------
// Address: 0x100010D0
// Name: public: virtual void vgui::Bitmap::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Bitmap::SetPos(vgui::Bitmap *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x100010F0
// Name: public: virtual void vgui::Bitmap::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Bitmap::SetColor(vgui::Bitmap *this, Color col)
{
  this->_color = col;
}

//------------------------------------------------------------------------------
// Address: 0x10001100
// Name: public: void vgui::Bitmap::ForceUpload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Bitmap::ForceUpload(vgui::Bitmap *this)
{
  unsigned int id; // edx

  if ( this->_valid && !this->_uploaded )
  {
    if ( this->_id == -1 )
      this->_id = ((int (__stdcall *)(bool))vgui::g_pSurface->CreateNewTextureID)(a1: this->_bProcedural);
    if ( !this->_bProcedural )
      vgui::g_pSurface->DrawSetTextureFile(
        this: vgui::g_pSurface,
        a2: this->_id,
        a3: this->_filename,
        a4: this->_filtered,
        a5: false);
    id = this->_id;
    this->_uploaded = true;
    this->_valid = vgui::g_pSurface->IsTextureIDValid(this: vgui::g_pSurface, a2: id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001170
// Name: public: virtual unsigned long vgui::Bitmap::GetID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Bitmap::GetID(vgui::Bitmap *this)
{
  return this->_id;
}

//------------------------------------------------------------------------------
// Address: 0x10001180
// Name: public: virtual bool vgui::Bitmap::Evict(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::Bitmap::Evict(vgui::Bitmap *this)
{
  unsigned int id; // eax

  id = this->_id;
  if ( id == -1 )
    return 0;
  vgui::g_pSurface->DestroyTextureID(this: vgui::g_pSurface, a2: id);
  this->_id = -1;
  this->_uploaded = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100011B0
// Name: public: virtual int vgui::Bitmap::GetNumFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Bitmap::GetNumFrames(vgui::Bitmap *this)
{
  if ( this->_valid )
    return vgui::g_pSurface->GetTextureNumFrames(this: vgui::g_pSurface, a2: this->_id);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: virtual void vgui::Bitmap::SetFrame(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Bitmap::SetFrame(vgui::Bitmap *this, int nFrame)
{
  if ( this->_valid )
    vgui::g_pSurface->DrawSetTextureFrame(this: vgui::g_pSurface, a2: this->_id, a3: nFrame, a4: &this->nFrameCache);
}

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: public: vgui::Bitmap::Bitmap(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Bitmap *__thiscall vgui::Bitmap::Bitmap(vgui::Bitmap *this, const char *filename, bool hardwareFiltered)
{
  unsigned int v4; // kr00_4
  char *v5; // eax

  this->__vftable = (vgui::Bitmap_vtbl *)&vgui::Bitmap::`vftable';
  this->_color = 0;
  this->_filtered = hardwareFiltered;
  v4 = strlen(filename);
  v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4 + 1);
  this->_filename = v5;
  V_snprintf(pDest: v5, maxLen: v4 + 1, pFormat: "%s", filename);
  this->_bProcedural = false;
  if ( V_stristr(pStr: filename, pSearch: ".pic") != nullptr )
    this->_bProcedural = true;
  this->_id = -1;
  this->_uploaded = false;
  this->_color = (Color)-1;
  this->_valid = true;
  this->_pos[1] = 0;
  this->_pos[0] = 0;
  this->_wide = 0;
  this->_tall = 0;
  this->nFrameCache = 0;
  this->_rotation = 0;
  vgui::Bitmap::ForceUpload(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100012F0
// Name: public: virtual void vgui::Bitmap::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Bitmap::Paint(vgui::Bitmap *this@<ecx>, int a2@<edi>)
{
  int *p_wide; // edi
  int rotation; // eax
  int v5; // eax
  float tall; // xmm1_4
  int v7; // eax
  FontVertex_t verts[4]; // [esp+4h] [ebp-40h] BYREF

  if ( this->_valid )
  {
    if ( this->_id == -1 )
      this->_id = vgui::g_pSurface->CreateNewTextureID(this: vgui::g_pSurface, a2: false);
    if ( !this->_uploaded )
      vgui::Bitmap::ForceUpload(this);
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, int))vgui::g_pSurface->DrawSetColor_2)(
      a1: this->_color._color[0],
      a2: this->_color._color[1],
      a3: this->_color._color[2],
      a4: this->_color._color[3],
      a5: a2);
    vgui::g_pSurface->DrawSetTexture(this: vgui::g_pSurface, a2: this->_id);
    p_wide = &this->_wide;
    if ( this->_wide == 0 )
      this->GetSize(this, a2: &this->_wide, a3: &this->_tall);
    rotation = this->_rotation;
    if ( rotation == 0 )
    {
      ((void (__thiscall *)(vgui::ISurface *, int, int, int))vgui::g_pSurface->DrawTexturedRect)(
        a1: vgui::g_pSurface,
        a2: this->_pos[0],
        a3: this->_pos[1],
        a4: this->_pos[0] + *p_wide);
      return;
    }
    v5 = rotation - 1;
    verts[1].m_Position.x = (float)*p_wide;
    verts[2].m_Position.x = verts[1].m_Position.x;
    tall = (float)this->_tall;
    verts[0].m_Position.x = 0.0;
    verts[0].m_Position.y = 0.0;
    verts[1].m_Position.y = 0.0;
    verts[2].m_Position.y = tall;
    verts[3].m_Position.x = 0.0;
    verts[3].m_Position.y = tall;
    if ( v5 != 0 )
    {
      v7 = v5 - 1;
      if ( v7 != 0 )
      {
        if ( v7 == 1 )
        {
          verts[0].m_TexCoord.y = 1.0;
          verts[1].m_TexCoord.x = 0.0;
          verts[2].m_TexCoord.y = 0.0;
          verts[3].m_TexCoord.x = 1.0;
LABEL_16:
          verts[3].m_TexCoord.y = 0.0;
          verts[2].m_TexCoord.x = 0.0;
          verts[1].m_TexCoord.y = 1.0;
          verts[0].m_TexCoord.x = 1.0;
        }
      }
      else
      {
        verts[0].m_TexCoord.x = 0.0;
        verts[0].m_TexCoord.y = 1.0;
        verts[1].m_TexCoord.x = 0.0;
        verts[1].m_TexCoord.y = 0.0;
        verts[2].m_TexCoord.x = 1.0;
        verts[2].m_TexCoord.y = 0.0;
        verts[3].m_TexCoord.x = 1.0;
        verts[3].m_TexCoord.y = 1.0;
      }
      ((void (__thiscall *)(vgui::ISurface *, int, FontVertex_t *))vgui::g_pSurface->DrawTexturedPolygon)(
        a1: vgui::g_pSurface,
        a2: 4,
        a3: verts);
      return;
    }
    verts[0].m_TexCoord.y = 0.0;
    verts[1].m_TexCoord.x = 1.0;
    verts[2].m_TexCoord.y = 1.0;
    verts[3].m_TexCoord.x = 0.0;
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DE60
// Name: public: char const __near * vgui::Bitmap::GetName(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Bitmap::GetName(CFontAmalgam *this)
{
  return this->m_Fonts.m_Size;
}
