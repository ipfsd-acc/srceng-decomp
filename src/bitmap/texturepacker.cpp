// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/texturepacker.cpp
// Functions: 13
// ============================================================

#include "bitmap\texturepacker.h"

//------------------------------------------------------------------------------
// Address: 0x1001F730
// Name: public: void CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Unlink(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this,
        unsigned __int16 elem)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *m_pMemory; // edx
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v3; // eax
  int m_PrevSibling; // esi
  int m_Parent; // esi
  int m_NextSibling; // edx

  m_pMemory = this->m_Memory.m_pMemory;
  v3 = &this->m_Memory.m_pMemory[elem];
  m_PrevSibling = v3->m_PrevSibling;
  if ( (_WORD)m_PrevSibling == 0xFFFF )
  {
    m_Parent = v3->m_Parent;
    if ( (_WORD)m_Parent == 0xFFFF )
    {
      if ( this->m_Root == elem )
        this->m_Root = v3->m_NextSibling;
    }
    else
    {
      m_pMemory[m_Parent].m_FirstChild = v3->m_NextSibling;
    }
  }
  else
  {
    m_pMemory[m_PrevSibling].m_NextSibling = v3->m_NextSibling;
  }
  m_NextSibling = v3->m_NextSibling;
  if ( (_WORD)m_NextSibling != 0xFFFF )
    this->m_Memory.m_pMemory[m_NextSibling].m_PrevSibling = v3->m_PrevSibling;
  *(_DWORD *)&v3->m_PrevSibling = -1;
  v3->m_Parent = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001F7E0
// Name: public: void CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::LinkChildAfter(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::LinkChildAfter(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this,
        unsigned __int16 parent,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v5; // eax
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v6; // ecx
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v7; // ecx
  int m_Root; // ecx
  int m_NextSibling; // eax

  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Unlink(this, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Parent = parent;
  v5->m_PrevSibling = after;
  if ( after == 0xFFFF )
  {
    if ( parent == 0xFFFF )
    {
      v5->m_NextSibling = this->m_Root;
      m_Root = this->m_Root;
      if ( (_WORD)m_Root != 0xFFFF )
        this->m_Memory.m_pMemory[m_Root].m_PrevSibling = elem;
      this->m_Root = elem;
    }
    else
    {
      v7 = &this->m_Memory.m_pMemory[parent];
      v5->m_NextSibling = v7->m_FirstChild;
      v7->m_FirstChild = elem;
    }
  }
  else
  {
    v6 = &this->m_Memory.m_pMemory[after];
    v5->m_NextSibling = v6->m_NextSibling;
    v6->m_NextSibling = elem;
  }
  m_NextSibling = v5->m_NextSibling;
  if ( (_WORD)m_NextSibling != 0xFFFF )
    this->m_Memory.m_pMemory[m_NextSibling].m_PrevSibling = elem;
}

//------------------------------------------------------------------------------
// Address: 0x1001F8B0
// Name: protected: unsigned short CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::AllocInternal(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::AllocInternal(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this)
{
  int m_FirstFree; // eax
  unsigned __int16 m_MaxElementIndex; // di
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v4; // eax
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *m_pMemory; // eax

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    if ( this->m_MaxElementIndex == this->m_Memory.m_nAllocationCount )
      CUtlMemory<CMatSystemSurface::PaintState_t,int>::Grow(this: &this->m_Memory, num: 1);
    m_MaxElementIndex = this->m_MaxElementIndex;
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
    if ( m_MaxElementIndex == 0xFFFF )
      _Error(a1: "CUtlNTree overflow!\n");
  }
  else
  {
    m_MaxElementIndex = this->m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_NextSibling;
  }
  v4 = &this->m_Memory.m_pMemory[m_MaxElementIndex];
  *(_DWORD *)&v4->m_Parent = -1;
  *(_DWORD *)&v4->m_PrevSibling = -1;
  m_pMemory = this->m_Memory.m_pMemory;
  ++this->m_ElementCount;
  this->m_pElements = m_pMemory;
  return m_MaxElementIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1001F940
// Name: public: void CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this)
{
  int m_MaxElementIndex; // eax
  int v2; // esi
  __int16 v3; // di
  __int16 v4; // dx
  int v5; // ebx
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v6; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (_WORD)m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    v3 = -1;
    do
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      v6 = &this->m_Memory.m_pMemory[v5];
      v6->m_NextSibling = v3;
      v6->m_FirstChild = -1;
      v6->m_Parent = -1;
      v6->m_PrevSibling = v4;
      v3 = v4;
    }
    while ( v2 >= 0 );
    *(_DWORD *)&this->m_Root = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F9A0
// Name: public: unsigned short CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this,
        unsigned __int16 parent,
        unsigned __int16 after)
{
  unsigned __int16 v4; // di

  v4 = CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::AllocInternal(this);
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::LinkChildAfter(this, parent, after, elem: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1001F9D0
// Name: public: int CTexturePacker::InsertRect(struct Rect_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexturePacker::InsertRect(CTexturePacker *this, const Rect_t *texRect, int nodeIndex)
{
  CTexturePacker *v3; // edi
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *p_m_Tree; // esi
  int result; // eax
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *m_pMemory; // ecx
  int v7; // edi
  int m_FirstChild; // edx
  int width; // ecx
  int height; // edx
  int v11; // ebx
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int y; // ecx
  int inserted; // ebx
  int v17; // eax
  unsigned __int16 cacheSlotWidth; // [esp+Ch] [ebp-14h]
  int cacheSlotWidtha; // [esp+Ch] [ebp-14h]
  int cacheSlotHeight; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  int dw; // [esp+18h] [ebp-8h]
  int dwa; // [esp+18h] [ebp-8h]

  v3 = this;
  p_m_Tree = &this->m_Tree;
  while ( 1 )
  {
    while ( 1 )
    {
      result = nodeIndex;
      if ( nodeIndex == -1 )
      {
        result = v3->m_Tree.m_Root;
        LOWORD(nodeIndex) = v3->m_Tree.m_Root;
      }
      m_pMemory = p_m_Tree->m_Memory.m_pMemory;
      v7 = (unsigned __int16)result;
      m_FirstChild = p_m_Tree->m_Memory.m_pMemory[v7].m_FirstChild;
      cacheSlotWidth = p_m_Tree->m_Memory.m_pMemory[v7].m_FirstChild;
      if ( m_FirstChild == 0xFFFF || m_pMemory[(unsigned __int16)m_FirstChild].m_NextSibling == 0xFFFF )
        break;
      v3 = this;
      result = CTexturePacker::InsertRect(this, texRect, nodeIndex: m_FirstChild);
      if ( (unsigned __int16)result < this->m_Tree.m_MaxElementIndex )
        return result;
      nodeIndex = p_m_Tree->m_Memory.m_pMemory[cacheSlotWidth].m_NextSibling;
    }
    if ( m_pMemory[v7].m_Element.bInUse )
      break;
    width = m_pMemory[v7].m_Element.rc.width;
    height = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.height;
    cacheSlotWidtha = width;
    cacheSlotHeight = height;
    dw = texRect->width;
    if ( dw > width )
      break;
    v11 = texRect->height;
    if ( v11 > height )
      break;
    if ( dw == width && v11 == height )
    {
      p_m_Tree->m_Memory.m_pMemory[(unsigned __int16)result].m_Element.bInUse = true;
      return result;
    }
    dwa = width - dw;
    v21 = height - v11;
    if ( dwa <= height - v11 )
    {
      inserted = CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(
                   this: p_m_Tree,
                   parent: result,
                   after: 0xFFFFu);
      v17 = (int)&p_m_Tree->m_Memory.m_pMemory[inserted];
      *(_DWORD *)v17 = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.x;
      *(_DWORD *)(v17 + 4) = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.y;
      *(_DWORD *)(v17 + 8) = cacheSlotWidtha;
      *(_DWORD *)(v17 + 12) = texRect->height;
      *(_BYTE *)(v17 + 16) = 0;
      v14 = (int)&p_m_Tree->m_Memory.m_pMemory[CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(
                                                 this: p_m_Tree,
                                                 parent: nodeIndex,
                                                 after: inserted)];
      *(_DWORD *)v14 = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.x;
      nodeIndex = inserted;
      *(_DWORD *)(v14 + 4) = this->m_PixelGap + texRect->height + p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.y;
      *(_DWORD *)(v14 + 8) = cacheSlotWidtha;
      v3 = this;
      *(_DWORD *)(v14 + 12) = v21 - this->m_PixelGap;
    }
    else
    {
      v12 = CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(
              this: p_m_Tree,
              parent: result,
              after: 0xFFFFu);
      v13 = (int)&p_m_Tree->m_Memory.m_pMemory[v12];
      *(_DWORD *)v13 = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.x;
      *(_DWORD *)(v13 + 4) = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.y;
      *(_DWORD *)(v13 + 8) = texRect->width;
      *(_DWORD *)(v13 + 12) = cacheSlotHeight;
      *(_BYTE *)(v13 + 16) = 0;
      v14 = (int)&p_m_Tree->m_Memory.m_pMemory[CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(
                                                 this: p_m_Tree,
                                                 parent: nodeIndex,
                                                 after: v12)];
      nodeIndex = v12;
      *(_DWORD *)v14 = this->m_PixelGap + texRect->width + p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.x;
      y = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.y;
      v3 = this;
      *(_DWORD *)(v14 + 4) = y;
      *(_DWORD *)(v14 + 8) = dwa - this->m_PixelGap;
      *(_DWORD *)(v14 + 12) = cacheSlotHeight;
    }
    *(_BYTE *)(v14 + 16) = 0;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001FC00
// Name: public: CTexturePacker::CTexturePacker(int,int,int)
// Source: json
//------------------------------------------------------------------------------
CTexturePacker *__thiscall CTexturePacker::CTexturePacker(
        CTexturePacker *this,
        int texWidth,
        int texHeight,
        int pixelGap)
{
  unsigned __int16 v5; // ax
  int v6; // ebx
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v7; // eax

  *(_DWORD *)&this->m_Tree.m_ElementCount = 0;
  this->m_Tree.m_Memory.m_pMemory = nullptr;
  this->m_Tree.m_Memory.m_nAllocationCount = 0;
  this->m_Tree.m_Memory.m_nGrowSize = 0;
  this->m_Tree.m_pElements = nullptr;
  *(_DWORD *)&this->m_Tree.m_Root = -1;
  this->m_PageHeight = texHeight;
  this->m_PageWidth = texWidth;
  this->m_PixelGap = pixelGap;
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(this: &this->m_Tree);
  v5 = CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::AllocInternal(this: &this->m_Tree);
  v6 = v5;
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::LinkChildAfter(
    this: &this->m_Tree,
    parent: 0xFFFFu,
    after: 0xFFFFu,
    elem: v5);
  v7 = &this->m_Tree.m_Memory.m_pMemory[v6];
  v7->m_Element.rc.x = 0;
  v7->m_Element.rc.y = 0;
  v7->m_Element.rc.width = this->m_PageWidth;
  v7->m_Element.rc.height = this->m_PageHeight;
  v7->m_Element.bInUse = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001FC90
// Name: public: CTexturePacker::~CTexturePacker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexturePacker::~CTexturePacker(CTexturePacker *this)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *p_m_Tree; // esi

  p_m_Tree = &this->m_Tree;
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(this: &this->m_Tree);
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(this: p_m_Tree);
  if ( p_m_Tree->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Tree->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Tree->m_Memory.m_pMemory);
      p_m_Tree->m_Memory.m_pMemory = nullptr;
    }
    p_m_Tree->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FCD0
// Name: unsigned long GetProcessorCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl GetProcessorCount()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x100200F0
// Name: public: CATICompressThreadData::CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::CATICompressThreadData(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10020100
// Name: public: CATICompressThreadData::~CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::~CATICompressThreadData(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( v2 != nullptr )
  {
    (**v2)(a1: v2, a2: 1);
    *this = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
  {
    (**v3)(a1: v3, a2: 1);
    *(this + 1) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*(this + 2);
  if ( v4 != nullptr )
  {
    (**v4)(a1: v4, a2: 1);
    *(this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020150
// Name: unsigned long ThreadedCompressProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ThreadedCompressProc(_DWORD *lpThreadParameter)
{
  unsigned int v1; // esi
  int v2; // edi

  v1 = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x8001Fu, mask: 0x8001Fu);
  v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*lpThreadParameter + 32))(
         a1: *lpThreadParameter,
         a2: lpThreadParameter[1],
         a3: lpThreadParameter[2],
         a4: lpThreadParameter[3],
         a5: lpThreadParameter[4],
         a6: lpThreadParameter[5]);
  _controlfp(newctrl: v1, mask: 0x8001Fu);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10020C40
// Name: void S3TCencode(struct _DDSURFACEDESC __near *,struct tagPALETTEENTRY __near *,struct _DDSURFACEDESC __near *,void __near *,unsigned int,float __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl S3TCencode(
        struct _DDSURFACEDESC *a1,
        struct tagPALETTEENTRY *a2,
        struct _DDSURFACEDESC *a3,
        void *a4,
        unsigned int a5,
        float *a6)
{
  unsigned int v6; // ebx
  struct _DDSURFACEDESC *v7; // esi
  int v8; // ecx
  unsigned int v9; // eax
  int i; // edx
  unsigned int dwRGBAlphaBitMask; // edx
  int v12; // ecx
  unsigned int j; // eax
  signed int dwHeight; // eax
  signed int dwWidth; // edx
  int k; // eax
  int v17; // ebx
  _DWORD *v18; // edi
  int v19; // esi
  int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // edx
  double v23; // st7
  int v24; // esi
  int v25; // edi
  int v26; // eax
  _BYTE *v27; // edi
  int jj; // eax
  unsigned int v29; // edi
  _DWORD *v30; // esi
  int v31; // edx
  int v32; // eax
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // ecx
  _DWORD *v38; // esi
  char v39; // di
  int v40; // ecx
  int v41; // eax
  int v42; // eax
  unsigned int v43; // eax
  __int64 v44; // rax
  int v45; // ecx
  int v46; // edi
  unsigned __int8 *v47; // esi
  int v48; // eax
  struct tagPALETTEENTRY *v49; // eax
  unsigned int v50; // ecx
  double *v51; // ecx
  bool v52; // cc
  int v53; // edi
  int v54; // eax
  int nn; // edx
  int v56; // eax
  struct tagPALETTEENTRY *v57; // ecx
  double *v58; // eax
  int v59; // edi
  int v60; // ecx
  unsigned int *v61; // edx
  int v62; // eax
  unsigned int v63; // esi
  double *v64; // edx
  int v65; // eax
  double v66; // st7
  unsigned int v67; // ebx
  unsigned int v68; // eax
  double *v69; // esi
  int v70; // ebx
  int i1; // edx
  int v72; // ecx
  unsigned int v73; // edi
  char *v74; // esi
  int v75; // eax
  int v76; // edx
  int v77; // ecx
  unsigned int v78; // edi
  double *v79; // esi
  int i2; // edx
  unsigned int v81; // eax
  int v82; // ecx
  _DWORD *v83; // eax
  int i3; // ecx
  int v85; // ecx
  char *v86; // eax
  __int16 v87; // dx
  unsigned __int16 v88; // dx
  unsigned __int16 v89; // cx
  bool v90; // cf
  int v91; // eax
  __int16 v92; // ax
  int v93; // ebx
  _DWORD *v94; // esi
  int *v95; // edx
  int v96; // eax
  int i4; // edi
  int lPitch; // edx
  int v99; // [esp+18h] [ebp-888h]
  int v100; // [esp+18h] [ebp-888h]
  int m; // [esp+18h] [ebp-888h]
  int v102; // [esp+18h] [ebp-888h]
  int v103; // [esp+18h] [ebp-888h]
  int v104; // [esp+18h] [ebp-888h]
  int v105; // [esp+18h] [ebp-888h]
  int v106; // [esp+18h] [ebp-888h]
  int v107; // [esp+1Ch] [ebp-884h]
  int kk; // [esp+1Ch] [ebp-884h]
  int n; // [esp+1Ch] [ebp-884h]
  int mm; // [esp+1Ch] [ebp-884h]
  int v111; // [esp+1Ch] [ebp-884h]
  int v112; // [esp+1Ch] [ebp-884h]
  int v113; // [esp+1Ch] [ebp-884h]
  int *v114; // [esp+1Ch] [ebp-884h]
  int ii; // [esp+20h] [ebp-880h]
  int v116; // [esp+20h] [ebp-880h]
  int v117; // [esp+20h] [ebp-880h]
  int v118; // [esp+20h] [ebp-880h]
  int v119; // [esp+20h] [ebp-880h]
  int v120; // [esp+20h] [ebp-880h]
  int v121; // [esp+20h] [ebp-880h]
  int v122; // [esp+20h] [ebp-880h]
  int v123; // [esp+24h] [ebp-87Ch]
  int v124; // [esp+24h] [ebp-87Ch]
  int v125; // [esp+24h] [ebp-87Ch]
  int v126; // [esp+28h] [ebp-878h]
  unsigned int *v127; // [esp+28h] [ebp-878h]
  unsigned int v128; // [esp+2Ch] [ebp-874h]
  _WORD *v129; // [esp+30h] [ebp-870h]
  int v130; // [esp+34h] [ebp-86Ch]
  int v131; // [esp+38h] [ebp-868h]
  int v132; // [esp+3Ch] [ebp-864h]
  _DWORD *v133; // [esp+40h] [ebp-860h]
  int v134; // [esp+44h] [ebp-85Ch]
  int v135; // [esp+48h] [ebp-858h]
  int v136; // [esp+4Ch] [ebp-854h]
  int v137; // [esp+50h] [ebp-850h]
  char *lpSurface; // [esp+54h] [ebp-84Ch]
  signed int v139; // [esp+58h] [ebp-848h]
  _DWORD v140[3]; // [esp+5Ch] [ebp-844h] BYREF
  int v141; // [esp+68h] [ebp-838h]
  unsigned int v142; // [esp+6Ch] [ebp-834h]
  unsigned int v143; // [esp+70h] [ebp-830h]
  unsigned int v144; // [esp+74h] [ebp-82Ch]
  __int64 v145; // [esp+78h] [ebp-828h]
  __int64 v146; // [esp+80h] [ebp-820h]
  __int64 v147; // [esp+88h] [ebp-818h]
  __int64 v148; // [esp+90h] [ebp-810h]
  __int64 v149; // [esp+98h] [ebp-808h]
  __int64 v150; // [esp+A0h] [ebp-800h]
  __int64 v151; // [esp+A8h] [ebp-7F8h]
  __int64 v152; // [esp+B0h] [ebp-7F0h]
  __int64 v153; // [esp+B8h] [ebp-7E8h]
  __int64 v154; // [esp+C0h] [ebp-7E0h]
  _DWORD v155[48]; // [esp+C8h] [ebp-7D8h] BYREF
  float v156[51]; // [esp+188h] [ebp-718h] BYREF
  int v157; // [esp+254h] [ebp-64Ch]
  int v158; // [esp+258h] [ebp-648h]
  int v159; // [esp+25Ch] [ebp-644h]
  _DWORD v160[48]; // [esp+260h] [ebp-640h]
  double v161[176]; // [esp+320h] [ebp-580h] BYREF

  v6 = a5 & 0xFF00;
  v143 = v6;
  if ( (a5 & 0xFF00) != 0 )
  {
    if ( v6 == 256 || v6 == 512 )
      bS3TCForce4 = true;
  }
  else
  {
    bS3TCForce4 = false;
  }
  v7 = a1;
  a3->dwFlags = 6150;
  a3->dwWidth = a1->dwWidth;
  a3->dwHeight = a1->dwHeight;
  a3->lpSurface = a4;
  a3->ddpfPixelFormat.dwSize = 32;
  a3->ddpfPixelFormat.dwFlags = 4;
  a3->ddpfPixelFormat.dwRGBBitCount = a5;
  a3->ddpfPixelFormat.dwFourCC = 305419896;
  v128 = (a1->ddpfPixelFormat.dwRGBBitCount + 7) >> 3;
  v8 = 0;
  v135 = (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140;
  do
  {
    v9 = *(_DWORD *)((char *)&v140[v8] + (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140);
    for ( i = 0; (v9 & 1) == 0; ++i )
      v9 >>= 1;
    v140[v8++] = i;
  }
  while ( v8 < 3 );
  if ( (a5 & 0xFF00) != 0 )
  {
    dwRGBAlphaBitMask = a1->ddpfPixelFormat.dwRGBAlphaBitMask;
    v12 = 0;
    for ( j = dwRGBAlphaBitMask; (j & 1) == 0; ++v12 )
      j >>= 1;
    v137 = v12;
    v144 = (dword_1014572C * (dwRGBAlphaBitMask >> v12) / 0xFF) << v12;
  }
  lpSurface = (char *)a1->lpSurface;
  dwHeight = a1->dwHeight;
  v129 = a4;
  v136 = 0;
  if ( dwHeight > 0 )
  {
    while ( 1 )
    {
      v131 = dwHeight - v136;
      if ( (unsigned int)(dwHeight - v136) >= 4 )
        v131 = 4;
      v139 = 0;
      v133 = lpSurface;
      dwWidth = v7->dwWidth;
      if ( dwWidth > 0 )
        break;
LABEL_171:
      lPitch = a1->lPitch;
      dwHeight = a1->dwHeight;
      v52 = v136 + 4 < dwHeight;
      v136 += 4;
      lpSurface += 4 * lPitch;
      if ( !v52 )
        return;
      v7 = a1;
    }
    v141 = (unsigned __int8)a5;
    while ( 1 )
    {
      memset(v161, 0, sizeof(v161));
      memset(v155, 0xFFu, sizeof(v155));
      for ( k = 0; k < 3; v161[k + 144] = a6[k - 1] )
        ++k;
      v130 = dwWidth - v139;
      if ( dwWidth - v139 >= (unsigned int)S3TC_BLOCK_WIDTH )
        v130 = S3TC_BLOCK_WIDTH;
      v17 = 0;
      LODWORD(v161[0]) = 0;
      if ( v143 == 256 )
      {
        v38 = v133;
        v39 = v137;
        v40 = S3TC_BLOCK_WIDTH;
        v41 = 0;
        for ( m = 0; m < 4; v41 = m )
        {
          if ( v41 >= v131 )
          {
            *v129 = 0;
          }
          else
          {
            v42 = 0;
            for ( n = 0; v42 < v40; n = v42 )
            {
              if ( v42 >= v130 )
              {
                LOWORD(v134) = (unsigned __int16)v134 >> 4;
              }
              else
              {
                v43 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v39;
                v152 = (*v38 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v39;
                v148 = v43;
                v44 = (__int64)floor(X: (double)v152 / (double)v43 * 15.0 + 0.5);
                v17 = LODWORD(v161[0]);
                LOWORD(v45) = (unsigned __int16)v134 >> 4;
                LODWORD(v44) = v45 | ((_DWORD)v44 << 12);
                v40 = S3TC_BLOCK_WIDTH;
                v134 = v44;
                v42 = n;
              }
              ++v42;
              v38 = (_DWORD *)((char *)v38 + v128);
            }
            *v129 = v134;
          }
          ++v129;
          v40 = S3TC_BLOCK_WIDTH;
          ++m;
          v38 = (_DWORD *)((char *)v38 + a1->lPitch - v128 * S3TC_BLOCK_WIDTH);
        }
        goto LABEL_82;
      }
      if ( v143 != 512 )
        goto LABEL_82;
      v18 = v133;
      v19 = 0;
      v20 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
      v156[0] = 0.0;
      v99 = 0;
      v107 = v20;
      do
      {
        for ( ii = 0; ii < S3TC_BLOCK_WIDTH; ++ii )
        {
          if ( ii >= v130 || v99 >= v131 )
          {
            v155[v19++] = -1;
          }
          else
          {
            v21 = (*v18 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v137;
            v22 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v137;
            v155[v19++] = LODWORD(v156[0]);
            if ( v21 == v22 )
            {
              v23 = 1.0;
            }
            else
            {
              v150 = v21;
              v151 = v22;
              v23 = (double)v21 / (double)v22;
            }
            v156[++LODWORD(v156[0])] = v23;
          }
          v18 = (_DWORD *)((char *)v18 + v128);
        }
        v18 = (_DWORD *)((char *)v18 + v107);
        ++v99;
      }
      while ( v99 < 4 );
      v24 = 0;
      v156[49] = 0.0;
      v156[50] = 0.0;
      if ( LODWORD(v156[0]) != 0 )
      {
        CodeAlphaBlock(a1: v156);
        v24 = v158;
        v25 = v159;
        v17 = LODWORD(v161[0]);
        if ( v158 != v159 )
          goto LABEL_45;
      }
      else
      {
        v25 = 0;
        v158 = 0;
      }
      ++v25;
      v26 = 0;
      v159 = v25;
      if ( SLODWORD(v156[0]) > 0 )
      {
        do
          v160[v26++] = 0;
        while ( v26 < SLODWORD(v156[0]) );
        v24 = v158;
        v25 = v159;
      }
      v157 = 6;
LABEL_45:
      if ( v24 > v25 == (v157 == 6) )
      {
        v158 = v25;
        v159 = v24;
        v116 = 1;
      }
      else
      {
        v116 = 0;
      }
      v27 = v129;
      for ( jj = 0; jj < 2; ++jj )
        *v27++ = *((_BYTE *)&v158 + 4 * jj);
      v129 = v27;
      v123 = 0;
      v126 = 0;
      memset(v27, 0, 6 * (S3TC_BLOCK_WIDTH / 4));
      v29 = 0;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v30 = v129;
        while ( 1 )
        {
          v31 = v123;
          v100 = 0;
          do
          {
            for ( kk = 4; kk != 0; --kk )
            {
              v32 = v155[v31];
              v29 >>= 3;
              if ( v32 < 0 )
                goto LABEL_66;
              v33 = v160[v32];
              if ( v116 != 0 )
              {
                if ( v157 == 8 )
                {
                  if ( v33 > 1 )
                  {
                    v34 = 9 - v33;
LABEL_64:
                    v33 = v34;
                    goto LABEL_65;
                  }
                }
                else
                {
                  if ( v157 != 6 || v33 > 5 )
                    goto LABEL_65;
                  if ( v33 > 1 )
                  {
                    v34 = 7 - v33;
                    goto LABEL_64;
                  }
                }
                v34 = v33 == 0;
                goto LABEL_64;
              }
LABEL_65:
              v29 |= v33 << 21;
LABEL_66:
              ++v31;
            }
            v35 = v100;
            if ( (v100 & 1) != 0 )
            {
              v36 = *v30;
              v30 = (_DWORD *)((char *)v30 + 3);
              v37 = v29 | v36;
              v29 = 0;
              *(_DWORD *)((char *)v30 - 3) = v37;
            }
            ++v100;
          }
          while ( v35 + 1 < 4 );
          v123 = v31;
          if ( ++v126 >= S3TC_BLOCK_WIDTH / 4 )
          {
            v129 = v30;
            break;
          }
        }
      }
LABEL_82:
      v46 = 0;
      if ( a2 != nullptr )
      {
        v47 = (unsigned __int8 *)v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v102 = 0;
            v117 = a1->lPitch;
            do
            {
              v48 = 0;
              for ( mm = 0; mm < 4; ++mm )
              {
                if ( v48 >= v130
                  || v102 >= v131
                  || (v49 = &a2[*v47], (v50 = *(_DWORD *)v49 & 0xFFFFFF) >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v50 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v46++] = -1;
                }
                else
                {
                  v155[v46++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v51 = &v161[3 * v17 + 2];
                  *(v51 - 1) = (double)v49->peRed * 0.00392156862745098;
                  *v51 = (double)v49->peGreen * 0.00392156862745098;
                  v51[1] = (double)v49->peBlue * 0.00392156862745098;
                  v17 = LODWORD(v161[0]);
                }
                v48 = mm + 1;
                ++v47;
              }
              v52 = ++v102 < 4;
              v47 = &v47[v117 - 4];
            }
            while ( v52 );
          }
        }
        else
        {
          v53 = 0;
          v54 = 0;
          v103 = 0;
          v118 = a1->lPitch;
          do
          {
            for ( nn = 0; nn < 4; ++nn )
            {
              if ( nn >= v130 || v54 >= v131 )
              {
                v155[v53++] = -1;
              }
              else
              {
                v56 = *v47;
                v155[v53++] = v17;
                v57 = &a2[v56];
                LODWORD(v161[0]) = v17 + 1;
                v58 = &v161[3 * v17 + 2];
                *(v58 - 1) = (double)v57->peRed * 0.00392156862745098;
                *v58 = (double)v57->peGreen * 0.00392156862745098;
                v58[1] = (double)v57->peBlue * 0.00392156862745098;
                v17 = LODWORD(v161[0]);
                v54 = v103;
              }
              ++v47;
            }
            v103 = ++v54;
            v47 = &v47[v118 - 4];
          }
          while ( v54 < 4 );
        }
      }
      else
      {
        v127 = v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v124 = 0;
            v105 = 0;
            v112 = a1->lPitch - 4 * v128;
            do
            {
              v120 = 0;
              do
              {
                if ( v120 >= v130
                  || v105 >= v131
                  || (v68 = *v127, v142 = v68, v68 >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v68 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v124++] = -1;
                }
                else
                {
                  v155[v124] = v17;
                  v69 = &v161[3 * v17 + 1];
                  LODWORD(v161[0]) = v17 + 1;
                  v70 = v135;
                  ++v124;
                  for ( i1 = 0; i1 < 3; ++i1 )
                  {
                    v72 = v140[i1];
                    ++v69;
                    v73 = (v142 & *(_DWORD *)((char *)&v140[i1] + v70)) >> v72;
                    v146 = (unsigned int)(*(_DWORD *)((char *)&v140[i1] + v70) >> v72);
                    v153 = v73;
                    *(v69 - 1) = (double)v73 / (double)v146;
                  }
                  v17 = LODWORD(v161[0]);
                }
                v74 = (char *)v127 + v128;
                v52 = ++v120 < 4;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v52 );
              v52 = ++v105 < 4;
              v127 = (unsigned int *)&v74[v112];
            }
            while ( v52 );
          }
          else if ( v141 == 2 )
          {
            v59 = 0;
            v60 = 0;
            v104 = 0;
            v111 = a1->lPitch - 4 * v128;
            do
            {
              v61 = v127;
              v62 = 0;
              v119 = 0;
              do
              {
                if ( v62 >= v130 || v60 >= v131 || (v63 = *v61, (*v61 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) <= v144) )
                {
                  v155[v59++] = -1;
                }
                else
                {
                  v155[v59++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v64 = &v161[3 * v17 + 1];
                  v65 = 0;
                  v154 = *(&a1->ddpfPixelFormat.dwRBitMask + v59) >> v140[v59];
                  v66 = (double)v154;
                  do
                  {
                    ++v64;
                    v67 = (v63 & *(_DWORD *)((char *)&v140[v65] + v135)) >> v140[v65];
                    ++v65;
                    v145 = v67;
                    *(v64 - 1) = (double)v67 / v66;
                  }
                  while ( v65 < 3 );
                  v17 = LODWORD(v161[0]);
                  v62 = v119;
                  v60 = v104;
                }
                ++v62;
                v61 = (unsigned int *)((char *)v127 + v128);
                v119 = v62;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v62 < 4 );
              v104 = ++v60;
              v127 = (unsigned int *)((char *)v61 + v111);
            }
            while ( v60 < 4 );
          }
        }
        else
        {
          v75 = 0;
          v76 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
          v106 = 0;
          v113 = v76;
          do
          {
            v77 = 0;
            v121 = 0;
            if ( S3TC_BLOCK_WIDTH > 0 )
            {
              do
              {
                if ( v77 >= v130 || v46 >= v131 )
                {
                  v155[v75++] = -1;
                }
                else
                {
                  v155[v75] = v17;
                  v78 = *v127;
                  v79 = &v161[3 * v17 + 1];
                  v125 = v75 + 1;
                  LODWORD(v161[0]) = v17 + 1;
                  for ( i2 = 0; i2 < 3; ++i2 )
                  {
                    ++v79;
                    v81 = *(_DWORD *)((char *)&v140[i2] + v135);
                    v82 = v140[i2];
                    v147 = (v81 & v78) >> v82;
                    v149 = v81 >> v82;
                    *(v79 - 1) = (double)v147 / (double)v149;
                  }
                  v17 = LODWORD(v161[0]);
                  v75 = v125;
                  v77 = v121;
                  v46 = v106;
                }
                ++v77;
                v127 = (unsigned int *)((char *)v127 + v128);
                v121 = v77;
              }
              while ( v77 < S3TC_BLOCK_WIDTH );
              v76 = v113;
            }
            v106 = ++v46;
            v127 = (unsigned int *)((char *)v127 + v76);
          }
          while ( v46 < 4 );
        }
      }
      LODWORD(v161[148]) = (v17 >= v131 * v130) + 3;
      if ( v17 != 0 )
      {
        CodeRGBBlock(a1: v161);
      }
      else
      {
        v83 = (_DWORD *)&v161[149] + 1;
        for ( i3 = 2; i3 != 0; --i3 )
        {
          v83[1] = 0;
          *v83 = 0;
          *(v83 - 1) = 0;
          v83 += 3;
        }
      }
      v85 = 0;
      v86 = (char *)&v161[149] + 4;
      do
      {
        v87 = *((_WORD *)v86 - 2);
        v86 += 12;
        *((_WORD *)&v131 + ++v85 + 1) = *((_WORD *)v86 - 4) | (32 * (*((_WORD *)v86 - 6) | (v87 << 6)));
      }
      while ( v85 < 2 );
      v89 = HIWORD(v132);
      v88 = v132;
      v90 = HIWORD(v132) < (unsigned __int16)v132;
      if ( HIWORD(v132) == (_WORD)v132 )
      {
        v89 = HIWORD(v132) + 1;
        v91 = 0;
        ++HIWORD(v132);
        if ( SLODWORD(v161[0]) > 0 )
        {
          do
            *((_DWORD *)&v161[152] + v91++) = 0;
          while ( v91 < SLODWORD(v161[0]) );
        }
        HIDWORD(v161[148]) = 3;
        v90 = v89 < v88;
      }
      if ( v90 == (HIDWORD(v161[148]) == 3) )
      {
        v92 = v132;
        LOWORD(v132) = v89;
        HIWORD(v132) = v92;
        v122 = 1;
      }
      else
      {
        v122 = 0;
      }
      v93 = 0;
      *(_DWORD *)v129 = v132;
      v94 = v129 + 2;
      v129 += 2;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v114 = &v155[15];
        do
        {
          v95 = v114;
          v96 = 0;
          for ( i4 = 16; i4 != 0; --i4 )
          {
            v96 *= 4;
            if ( *v95 >= 0 )
            {
              v96 |= *((_DWORD *)&v161[152] + *v95);
              if ( v122 != 0 )
              {
                if ( HIDWORD(v161[148]) == 4 )
                  v96 ^= 1u;
                else
                  v96 ^= (~v96 & 2) != 0;
              }
            }
            else
            {
              LOBYTE(v96) = v96 | 3;
            }
            --v95;
          }
          *v94 = v96;
          v114 += 16;
          ++v94;
          ++v93;
        }
        while ( v93 < S3TC_BLOCK_WIDTH / 4 );
        v129 = v94;
      }
      v133 += v128;
      v139 += 4;
      dwWidth = a1->dwWidth;
      if ( v139 >= dwWidth )
        goto LABEL_171;
    }
  }
}

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004312E0
// Name: public: void CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Unlink(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this,
        unsigned __int16 elem)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *m_pMemory; // edx
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v3; // eax
  unsigned __int16 m_PrevSibling; // si
  unsigned __int16 m_Parent; // si
  unsigned __int16 m_NextSibling; // dx

  m_pMemory = this->m_Memory.m_pMemory;
  v3 = &this->m_Memory.m_pMemory[elem];
  m_PrevSibling = v3->m_PrevSibling;
  if ( m_PrevSibling == 0xFFFF )
  {
    m_Parent = v3->m_Parent;
    if ( m_Parent == 0xFFFF )
    {
      if ( this->m_Root == elem )
        this->m_Root = v3->m_NextSibling;
    }
    else
    {
      m_pMemory[m_Parent].m_FirstChild = v3->m_NextSibling;
    }
  }
  else
  {
    m_pMemory[m_PrevSibling].m_NextSibling = v3->m_NextSibling;
  }
  m_NextSibling = v3->m_NextSibling;
  if ( m_NextSibling != 0xFFFF )
    this->m_Memory.m_pMemory[m_NextSibling].m_PrevSibling = v3->m_PrevSibling;
  v3->m_NextSibling = -1;
  v3->m_PrevSibling = -1;
  v3->m_Parent = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00431390
// Name: public: void CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::LinkChildAfter(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::LinkChildAfter(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this,
        unsigned __int16 parent,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v5; // eax
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v6; // ecx
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v7; // ecx
  unsigned __int16 m_Root; // cx
  unsigned __int16 m_NextSibling; // ax

  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Unlink(this, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Parent = parent;
  v5->m_PrevSibling = after;
  if ( after == 0xFFFF )
  {
    if ( parent == 0xFFFF )
    {
      v5->m_NextSibling = this->m_Root;
      m_Root = this->m_Root;
      if ( m_Root != 0xFFFF )
        this->m_Memory.m_pMemory[m_Root].m_PrevSibling = elem;
      this->m_Root = elem;
    }
    else
    {
      v7 = &this->m_Memory.m_pMemory[parent];
      v5->m_NextSibling = v7->m_FirstChild;
      v7->m_FirstChild = elem;
    }
  }
  else
  {
    v6 = &this->m_Memory.m_pMemory[after];
    v5->m_NextSibling = v6->m_NextSibling;
    v6->m_NextSibling = elem;
  }
  m_NextSibling = v5->m_NextSibling;
  if ( m_NextSibling != 0xFFFF )
    this->m_Memory.m_pMemory[m_NextSibling].m_PrevSibling = elem;
}

//------------------------------------------------------------------------------
// Address: 0x00431460
// Name: protected: unsigned short CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::AllocInternal(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::AllocInternal(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this)
{
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 m_MaxElementIndex; // di
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v4; // eax
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *m_pMemory; // eax

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == 0xFFFF )
  {
    if ( this->m_MaxElementIndex == this->m_Memory.m_nAllocationCount )
      CUtlMemory<CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t,int>::Grow(
        (CUtlMemory<CFontAmalgam,int> *)this,
        num: 1);
    m_MaxElementIndex = this->m_MaxElementIndex;
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
    if ( m_MaxElementIndex == 0xFFFF )
      _Error(a1: "CUtlNTree overflow!\n");
  }
  else
  {
    m_MaxElementIndex = this->m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_NextSibling;
  }
  v4 = &this->m_Memory.m_pMemory[m_MaxElementIndex];
  v4->m_FirstChild = -1;
  v4->m_Parent = -1;
  v4->m_PrevSibling = -1;
  v4->m_NextSibling = -1;
  m_pMemory = this->m_Memory.m_pMemory;
  ++this->m_ElementCount;
  this->m_pElements = m_pMemory;
  return m_MaxElementIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00431500
// Name: private: bool CTexturePacker::IsLeaf(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTexturePacker::IsLeaf(CTexturePacker *this, unsigned __int16 nodeIndex)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *m_pMemory; // ecx
  int m_FirstChild; // eax

  m_pMemory = this->m_Tree.m_Memory.m_pMemory;
  m_FirstChild = m_pMemory[nodeIndex].m_FirstChild;
  return m_FirstChild == 0xFFFF || m_pMemory[(unsigned __int16)m_FirstChild].m_NextSibling == 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x00431540
// Name: public: void CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this)
{
  unsigned __int16 m_MaxElementIndex; // ax
  int v2; // esi
  __int16 v3; // di
  __int16 v4; // dx
  int v5; // ebp
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v6; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    v3 = -1;
    do
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      v6 = &this->m_Memory.m_pMemory[v5];
      v6->m_NextSibling = v3;
      v6->m_PrevSibling = v4;
      v6->m_FirstChild = -1;
      v6->m_Parent = -1;
      v3 = v4;
    }
    while ( v2 >= 0 );
    *(_DWORD *)&this->m_Root = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004315A0
// Name: public: unsigned short CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this,
        unsigned __int16 parent,
        unsigned __int16 after)
{
  unsigned __int16 v4; // di

  v4 = CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::AllocInternal(this);
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::LinkChildAfter(this, parent, after, elem: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004315D0
// Name: public: void CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Remove(
        CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *this,
        unsigned __int16 elem)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v3; // eax

  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Unlink(this, elem);
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Unlink(this, elem);
  v3 = &this->m_Memory.m_pMemory[elem];
  v3->m_NextSibling = this->m_FirstFree;
  v3->m_PrevSibling = elem;
  v3->m_FirstChild = -1;
  v3->m_Parent = -1;
  --this->m_ElementCount;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x00431620
// Name: public: void CTexturePacker::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexturePacker::Clear(CTexturePacker *this)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *p_m_Tree; // esi
  unsigned __int16 v3; // di
  int v4; // ecx
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v5; // eax
  unsigned __int16 m_Root; // dx
  unsigned __int16 m_NextSibling; // ax
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v8; // esi

  p_m_Tree = &this->m_Tree;
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(this: &this->m_Tree);
  v3 = CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::AllocInternal(this: p_m_Tree);
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Unlink(this: p_m_Tree, elem: v3);
  v4 = v3;
  v5 = &p_m_Tree->m_Memory.m_pMemory[v4];
  v5->m_Parent = -1;
  v5->m_PrevSibling = -1;
  v5->m_NextSibling = p_m_Tree->m_Root;
  m_Root = p_m_Tree->m_Root;
  if ( m_Root != 0xFFFF )
    p_m_Tree->m_Memory.m_pMemory[m_Root].m_PrevSibling = v3;
  p_m_Tree->m_Root = v3;
  m_NextSibling = v5->m_NextSibling;
  if ( m_NextSibling != 0xFFFF )
    p_m_Tree->m_Memory.m_pMemory[m_NextSibling].m_PrevSibling = v3;
  v8 = &p_m_Tree->m_Memory.m_pMemory[v4];
  v8->m_Element.rc.x = 0;
  v8->m_Element.rc.y = 0;
  v8->m_Element.rc.width = this->m_PageWidth;
  v8->m_Element.rc.height = this->m_PageHeight;
  v8->m_Element.bInUse = false;
}

//------------------------------------------------------------------------------
// Address: 0x004316D0
// Name: public: int CTexturePacker::InsertRect(struct Rect_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexturePacker::InsertRect(CTexturePacker *this, const Rect_t *texRect, int nodeIndex)
{
  CTexturePacker *v3; // edi
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *p_m_Tree; // esi
  int result; // eax
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *m_pMemory; // ecx
  int v7; // edi
  int m_FirstChild; // ebx
  int width; // ebx
  int v10; // edx
  int height; // ecx
  int v12; // ebp
  int v13; // ebx
  bool v14; // cc
  int inserted; // ebp
  int v16; // eax
  int v17; // eax
  int y; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int cacheSlotWidth; // [esp+14h] [ebp-Ch]
  int v24; // [esp+18h] [ebp-8h]
  int v25; // [esp+1Ch] [ebp-4h]

  v3 = this;
  p_m_Tree = &this->m_Tree;
  while ( 1 )
  {
    while ( 1 )
    {
      result = nodeIndex;
      if ( nodeIndex == -1 )
      {
        result = v3->m_Tree.m_Root;
        LOWORD(nodeIndex) = v3->m_Tree.m_Root;
      }
      m_pMemory = p_m_Tree->m_Memory.m_pMemory;
      v7 = (unsigned __int16)result;
      m_FirstChild = p_m_Tree->m_Memory.m_pMemory[v7].m_FirstChild;
      if ( m_FirstChild == 0xFFFF || m_pMemory[(unsigned __int16)m_FirstChild].m_NextSibling == 0xFFFF )
        break;
      v3 = this;
      result = CTexturePacker::InsertRect(this, texRect, nodeIndex: m_FirstChild);
      if ( (unsigned __int16)result < this->m_Tree.m_MaxElementIndex )
        return result;
      nodeIndex = p_m_Tree->m_Memory.m_pMemory[(unsigned __int16)m_FirstChild].m_NextSibling;
    }
    if ( m_pMemory[v7].m_Element.bInUse )
      break;
    width = m_pMemory[v7].m_Element.rc.width;
    v10 = texRect->width;
    height = m_pMemory[v7].m_Element.rc.height;
    v24 = width;
    cacheSlotWidth = height;
    if ( v10 > width )
      break;
    v12 = texRect->height;
    if ( v12 > height )
      break;
    if ( v10 == width && v12 == height )
    {
      p_m_Tree->m_Memory.m_pMemory[(unsigned __int16)result].m_Element.bInUse = true;
      return result;
    }
    v13 = width - v10;
    v25 = height - v12;
    v14 = v13 <= height - v12;
    inserted = CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(
                 this: p_m_Tree,
                 parent: result,
                 after: 0xFFFFu);
    v16 = (int)&p_m_Tree->m_Memory.m_pMemory[inserted];
    *(_DWORD *)v16 = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.x;
    *(_DWORD *)(v16 + 4) = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.y;
    if ( v14 )
    {
      *(_DWORD *)(v16 + 8) = v24;
      *(_DWORD *)(v16 + 12) = texRect->height;
      *(_BYTE *)(v16 + 16) = 0;
      v19 = (int)&p_m_Tree->m_Memory.m_pMemory[CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(
                                                 this: p_m_Tree,
                                                 parent: nodeIndex,
                                                 after: inserted)];
      *(_DWORD *)v19 = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.x;
      v20 = this->m_PixelGap + texRect->height + p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.y;
      *(_DWORD *)(v19 + 8) = v24;
      *(_DWORD *)(v19 + 4) = v20;
      v21 = v25 - this->m_PixelGap;
      *(_BYTE *)(v19 + 16) = 0;
      *(_DWORD *)(v19 + 12) = v21;
      nodeIndex = inserted;
      v3 = this;
    }
    else
    {
      *(_DWORD *)(v16 + 8) = texRect->width;
      *(_DWORD *)(v16 + 12) = cacheSlotWidth;
      *(_BYTE *)(v16 + 16) = 0;
      v17 = (int)&p_m_Tree->m_Memory.m_pMemory[CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::InsertChildAfter(
                                                 this: p_m_Tree,
                                                 parent: nodeIndex,
                                                 after: inserted)];
      nodeIndex = inserted;
      *(_DWORD *)v17 = this->m_PixelGap + texRect->width + p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.x;
      y = p_m_Tree->m_Memory.m_pMemory[v7].m_Element.rc.y;
      v3 = this;
      *(_DWORD *)(v17 + 4) = y;
      *(_DWORD *)(v17 + 8) = v13 - this->m_PixelGap;
      *(_BYTE *)(v17 + 16) = 0;
      *(_DWORD *)(v17 + 12) = cacheSlotWidth;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00431910
// Name: public: bool CTexturePacker::RemoveRect(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTexturePacker::RemoveRect(CTexturePacker *this, int nodeIndex)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *p_m_Tree; // esi
  int v3; // edx
  int m_FirstChild; // eax
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *m_pMemory; // ebx
  int m_Parent; // eax
  unsigned __int16 m_NextSibling; // di
  bool v9; // zf

  p_m_Tree = &this->m_Tree;
  if ( (unsigned __int16)nodeIndex >= this->m_Tree.m_MaxElementIndex )
    return 0;
  v3 = (unsigned __int16)nodeIndex;
  if ( p_m_Tree->m_Memory.m_pMemory[v3].m_PrevSibling == (_WORD)nodeIndex )
    return 0;
  p_m_Tree->m_Memory.m_pMemory[v3].m_Element.bInUse = false;
  m_FirstChild = p_m_Tree->m_Memory.m_pMemory[v3].m_FirstChild;
  if ( m_FirstChild == 0xFFFF || p_m_Tree->m_Memory.m_pMemory[(unsigned __int16)m_FirstChild].m_NextSibling == 0xFFFF )
  {
    m_pMemory = p_m_Tree->m_Memory.m_pMemory;
    m_Parent = p_m_Tree->m_Memory.m_pMemory[v3].m_Parent;
    if ( nodeIndex == p_m_Tree->m_Memory.m_pMemory[m_Parent].m_FirstChild )
    {
      m_NextSibling = m_pMemory[v3].m_NextSibling;
      if ( CTexturePacker::IsLeaf(this, nodeIndex: m_NextSibling) )
      {
        v9 = !m_pMemory[m_NextSibling].m_Element.bInUse;
        goto LABEL_11;
      }
    }
    else
    {
      m_NextSibling = m_pMemory[m_Parent].m_FirstChild;
      if ( CTexturePacker::IsLeaf(this, nodeIndex: m_NextSibling) )
      {
        v9 = !m_pMemory[m_NextSibling].m_Element.bInUse;
LABEL_11:
        if ( v9 )
        {
          CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Remove(this: p_m_Tree, elem: nodeIndex);
          CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Remove(this: p_m_Tree, elem: m_NextSibling);
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004319F0
// Name: public: CTexturePacker::CTexturePacker(int,int,int)
// Source: json
//------------------------------------------------------------------------------
CTexturePacker *__thiscall CTexturePacker::CTexturePacker(
        CTexturePacker *this,
        int texWidth,
        int texHeight,
        int pixelGap)
{
  this->m_Tree.m_Root = -1;
  this->m_Tree.m_FirstFree = -1;
  this->m_Tree.m_Memory.m_pMemory = nullptr;
  this->m_Tree.m_Memory.m_nAllocationCount = 0;
  this->m_Tree.m_Memory.m_nGrowSize = 0;
  this->m_Tree.m_MaxElementIndex = 0;
  this->m_Tree.m_ElementCount = 0;
  this->m_Tree.m_pElements = nullptr;
  this->m_PageHeight = texHeight;
  this->m_PageWidth = texWidth;
  this->m_PixelGap = pixelGap;
  CTexturePacker::Clear(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00431A40
// Name: public: CTexturePacker::~CTexturePacker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexturePacker::~CTexturePacker(CTexturePacker *this)
{
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short> *p_m_Tree; // esi

  p_m_Tree = &this->m_Tree;
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(this: &this->m_Tree);
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::RemoveAll(this: p_m_Tree);
  if ( p_m_Tree->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Tree->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Tree->m_Memory.m_pMemory);
      p_m_Tree->m_Memory.m_pMemory = nullptr;
    }
    p_m_Tree->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9EF0
// Name: public: void CUtlMemory<struct CUtlNTree<struct CTexturePacker::TreeEntry_t,unsigned short>::Node_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t,int>::Grow(
        CUtlMemory<CFontAmalgam,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CFontAmalgam *m_pMemory; // edx
  bool v7; // zf

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (CFontAmalgam *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (CFontAmalgam *)_g_pMemAlloc->Realloc_2(
                                          this: _g_pMemAlloc,
                                          a2: m_pMemory,
                                          a3: 28 * m_nAllocationCount);
  }
}

} // namespace vgui_perftest
