// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/imagelist.cpp
// Functions: 4
// ============================================================

#include "vgui2\vgui_controls\imagelist.h"

//------------------------------------------------------------------------------
// Address: 0x102C4F30
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102C4F50
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x102C4F60
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C5050
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)MemAlloc_Alloc(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1001AF90
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100668D0
// Name: public: virtual int BlankImage::GetNumFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlankImage::GetNumFrames(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100725A0
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100725C0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100725E0
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x100725F0
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100726E0
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)operator new(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0045C1E0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0045C200
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x0045C210
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x100890D0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100890F0
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10089100
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005DD730
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00637FE0
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00638000
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00638020
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00638030
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00638120
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)MemAlloc_Alloc(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102C5000
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102C5020
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x102C5030
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C50C0
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)MemAlloc_Alloc(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10130FB0
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10318180
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103181A0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103181C0
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x103181D0
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318260
// Name: public: int vgui::ImageList::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ImageList::AddImage(vgui::ImageList *this, vgui::IImage *image)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::IImage **m_pMemory; // ecx
  int v6; // eax
  vgui::IImage **v7; // eax

  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  m_Size = this->m_Images.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v6 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = image;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103182C0
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)operator new(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x1001BBC0
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10062A00
// Name: public: virtual int BlankImage::GetNumFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlankImage::GetNumFrames(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D7C40
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D7C90
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100D7CB0
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x100D7CC0
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7DB0
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)operator new(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00414B50
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00475D00
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00475D20
// Name: public: virtual int BlankImage::GetNumFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlankImage::GetNumFrames(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00475D60
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00475D80
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00475D90
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475E20
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)operator new(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00450A60
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00463910
// Name: public: virtual int BlankImage::GetNumFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlankImage::GetNumFrames(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00463960
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004639B0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004639D0
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x004639E0
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463A70
// Name: public: int vgui::ImageList::AddImage(class vgui::IImage __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ImageList::AddImage(vgui::ImageList *this, vgui::IImage *image)
{
  return CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
           (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this,
           elem: this->m_Images.m_Size,
           src: (vgui::TreeNode **)&image);
}

//------------------------------------------------------------------------------
// Address: 0x00463A90
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, _DWORD *deleteImagesWhenDone)
{
  bool v2; // al
  _DWORD *v4; // eax

  v2 = (char)deleteImagesWhenDone;
  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = v2;
  v4 = operator new(nSize: 4u);
  if ( v4 != nullptr )
  {
    *v4 = &BlankImage::`vftable';
    deleteImagesWhenDone = v4;
  }
  else
  {
    deleteImagesWhenDone = nullptr;
  }
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this,
    elem: this->m_Images.m_Size,
    src: (vgui::TreeNode **)&deleteImagesWhenDone);
  return this;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0048A8E0
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00667BD0
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00667C20
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00667C40
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00667C50
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00667D40
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)MemAlloc_Alloc(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1001BFE0
// Name: public: virtual int BlankImage::GetNumFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlankImage::GetNumFrames(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10026E40
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10026E50
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10026EA0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10026EC0
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10026ED0
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026F60
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)operator new(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10097CE0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10097D00
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10097D10
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00472200
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00472220
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00472230
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004B3BF0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B3C10
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x004B3C20
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0040EFF0
// Name: public: virtual int BlankImage::GetNumFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlankImage::GetNumFrames(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00448C00
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00452C60
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00452CC0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00452CE0
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00452CF0
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452DE0
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)operator new(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00468290
// Name: public: virtual int BlankImage::GetNumFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlankImage::GetNumFrames(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004682F0
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00468310
// Name: public: virtual void BlankImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::SetSize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00468350
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00468370
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00468380
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468410
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)operator new(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103CD250
// Name: public: virtual void BlankImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlankImage::GetContentSize(BlankImage *this, int *wide, int *tall)
{
  *wide = 0;
  *tall = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103CD2B0
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103CD2D0
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x103CD2E0
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CD3D0
// Name: public: vgui::ImageList::ImageList(bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ImageList *__thiscall vgui::ImageList::ImageList(vgui::ImageList *this, bool deleteImagesWhenDone)
{
  vgui::IImage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IImage **m_pMemory; // ecx
  int v7; // eax
  vgui::IImage **v8; // eax
  vgui::IImage *deleteImagesWhenDonea; // [esp+14h] [ebp+8h]

  this->m_Images.m_Memory.m_pMemory = nullptr;
  this->m_Images.m_Memory.m_nAllocationCount = 0;
  this->m_Images.m_Memory.m_nGrowSize = 0;
  this->m_Images.m_Size = 0;
  this->m_Images.m_pElements = nullptr;
  this->m_bDeleteImagesWhenDone = deleteImagesWhenDone;
  v3 = (vgui::IImage *)MemAlloc_Alloc(nSize: 4u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (vgui::IImage_vtbl *)&BlankImage::`vftable';
    deleteImagesWhenDonea = v3;
  }
  else
  {
    deleteImagesWhenDonea = nullptr;
  }
  m_Size = this->m_Images.m_Size;
  m_nAllocationCount = this->m_Images.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Images.m_Size;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  v7 = this->m_Images.m_Size - m_Size - 1;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v7);
  v8 = &this->m_Images.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = deleteImagesWhenDonea;
  return this;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103CC310
// Name: public: bool vgui::ImageList::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::ImageList::IsValidIndex(vgui::ImageList *this, int imageIndex)
{
  return imageIndex >= 0 && imageIndex < this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103CC330
// Name: public: class vgui::IImage __near * vgui::ImageList::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ImageList::GetImage(vgui::ImageList *this, int imageIndex)
{
  return this->m_Images.m_Memory.m_pMemory[imageIndex];
}

//------------------------------------------------------------------------------
// Address: 0x103CC340
// Name: public: vgui::ImageList::~ImageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ImageList::~ImageList(vgui::ImageList *this)
{
  int i; // edi
  vgui::IImage *v3; // ecx
  bool v4; // sf
  vgui::IImage **m_pMemory; // eax

  if ( this->m_bDeleteImagesWhenDone )
  {
    for ( i = 1; i < this->m_Images.m_Size; ++i )
    {
      v3 = this->m_Images.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
        ((void (__thiscall *)(vgui::IImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
    }
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  this->m_Images.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_Images.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Images.m_Memory.m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Images.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Images.m_Memory.m_pMemory;
  this->m_Images.m_pElements = this->m_Images.m_Memory.m_pMemory;
  if ( !v4 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Images.m_Memory.m_pMemory = nullptr;
    }
    this->m_Images.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace server
