// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vguimatsurface/memorybitmap.cpp
// Functions: 13
// ============================================================

#include "vguimatsurface\memorybitmap.h"

//------------------------------------------------------------------------------
// Address: 0x10011160
// Name: public: virtual void vgui::MemoryBitmap::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MemoryBitmap::GetSize(vgui::MemoryBitmap *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
  if ( BYTE1(this->_id) != 0 )
    CMatSystemSurface::DrawGetTextureSize(this: &g_MatSystemSurface, id: this->_h, iWide: wide, iTall: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10011190
// Name: public: virtual void vgui::MemoryBitmap::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MemoryBitmap::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x100111A0
// Name: public: virtual void vgui::MemoryBitmap::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MemoryBitmap::SetColor(vgui::MemoryBitmap *this, Color col)
{
  this->_pos[1] = (int)col;
}

//------------------------------------------------------------------------------
// Address: 0x100111B0
// Name: public: void vgui::MemoryBitmap::ForceUpload(unsigned char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MemoryBitmap::ForceUpload(vgui::MemoryBitmap *this, unsigned __int8 *texture, int wide, int tall)
{
  bool v5; // al
  bool v6; // zf
  CTextureDictionary *v7; // eax
  int h; // [esp-4h] [ebp-10h]

  *(_DWORD *)&this->_uploaded = texture;
  v5 = *(_DWORD *)&this->_color != wide || this->_w != tall;
  v6 = BYTE1(this->_id) == 0;
  this->_color = (Color)wide;
  this->_w = tall;
  if ( !v6 && wide != 0 && tall != 0 )
  {
    if ( v5 )
    {
      if ( this->_h == 0 )
        goto LABEL_12;
      v7 = TextureDictionary();
      v7->DestroyTexture(this: v7, a2: this->_h);
      this->_h = 0;
    }
    if ( this->_h != 0 )
    {
LABEL_13:
      CMatSystemSurface::DrawSetTextureRGBA(this: &g_MatSystemSurface, id: this->_h, rgba: texture, wide, tall);
      h = this->_h;
      LOBYTE(this->_id) = 1;
      BYTE1(this->_id) = CMatSystemSurface::IsTextureIDValid(this: &g_MatSystemSurface, id: h);
      return;
    }
LABEL_12:
    this->_h = CMatSystemSurface::CreateNewTextureID(this: &g_MatSystemSurface, procedural: true);
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011250
// Name: public: virtual unsigned long vgui::MemoryBitmap::GetID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::MemoryBitmap::GetID(vgui::MemoryBitmap *this)
{
  return this->_h;
}

//------------------------------------------------------------------------------
// Address: 0x10011260
// Name: public: vgui::MemoryBitmap::MemoryBitmap(unsigned char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
vgui::MemoryBitmap *__thiscall vgui::MemoryBitmap::MemoryBitmap(
        vgui::MemoryBitmap *this,
        unsigned __int8 *texture,
        int wide,
        int tall)
{
  *(_DWORD *)&this->_uploaded = texture;
  this->__vftable = (vgui::MemoryBitmap_vtbl *)&vgui::MemoryBitmap::`vftable';
  LOBYTE(this->_id) = 0;
  this->_pos[1] = -1;
  this->_pos[0] = 0;
  this->_texture = nullptr;
  BYTE1(this->_id) = 1;
  this->_color = (Color)wide;
  this->_w = tall;
  this->_h = 0;
  vgui::MemoryBitmap::ForceUpload(this, texture, wide, tall);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100112F0
// Name: public: virtual void vgui::MemoryBitmap::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MemoryBitmap::Paint(vgui::MemoryBitmap *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  if ( BYTE1(this->_id) != 0 )
  {
    if ( LOBYTE(this->_id) == 0 )
      vgui::MemoryBitmap::ForceUpload(
        this,
        texture: *(unsigned __int8 **)&this->_uploaded,
        wide: *(_DWORD *)&this->_color,
        tall: this->_w);
    CMatSystemSurface::DrawSetTexture(this: &g_MatSystemSurface, id: this->_h);
    CMatSystemSurface::DrawSetColor(
      this: &g_MatSystemSurface,
      r: this->_pos[1],
      g: BYTE1(this->_pos[1]),
      b: BYTE2(this->_pos[1]),
      a: HIBYTE(this->_pos[1]));
    this->GetSize(this, a2: &wide, a3: &tall);
    CMatSystemSurface::DrawTexturedRect(
      this: &g_MatSystemSurface,
      a2,
      a3,
      x0: (int)this->_texture,
      y0: this->_pos[0],
      x1: (int)&this->_texture[wide],
      y1: this->_pos[0] + tall);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011380
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  void *v2; // edi

  v2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * count);
  memset(dst: (int)v2, value: nullptr, count: size * count);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100113B0
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x100113D0
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  void *v3; // edi

  v3 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: (int)v3, value: nullptr, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10011410
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x10011430
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10011440
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
