// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vtfdiff/vtfdiff.cpp
// Functions: 20
// ============================================================

#include "utils\vtfdiff\vtfdiff.h"

//------------------------------------------------------------------------------
// Address: 0x00401150
// Name: char const __near * ResourceToString(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ResourceToString(unsigned int uiResType)
{
  if ( uiResType <= 0x30 )
  {
    switch ( uiResType )
    {
      case 0x30u:
        return "VTF_LEGACY_RSRC_IMAGE";
      case 1u:
        return "VTF_LEGACY_RSRC_LOW_RES_IMAGE";
      case 0x10u:
        return "VTF_RSRC_SHEET";
      default:
        break;
    }
    goto LABEL_10;
  }
  if ( (_UNKNOWN *)uiResType == &loc_435243 )
    return "CRC";
  if ( (_UNKNOWN *)uiResType != (_UNKNOWN *)((char *)&Error_handling_1 + 5) )
  {
LABEL_10:
    sprintf(string: chBuffer, format: "0x%08X", uiResType);
    return chBuffer;
  }
  return "VTF_RSRC_TEXTURE_LOD_SETTINGS";
}

//------------------------------------------------------------------------------
// Address: 0x004011C0
// Name: void PrintFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintFlags(unsigned int flags)
{
  unsigned int v1; // ebx
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  const char *v31; // eax
  const char *v32; // eax

  v1 = flags;
  if ( (flags & 1) != 0 )
  {
    v1 = flags & 0xFFFFFFFE;
    v2 = "|";
    if ( (flags & 0xFFFFFFFE) == 0 )
      v2 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "POINTSAMPLE", v2);
  }
  if ( (v1 & 2) != 0 )
  {
    v1 &= ~2u;
    v3 = "|";
    if ( v1 == 0 )
      v3 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "TRILINEAR", v3);
  }
  if ( (v1 & 4) != 0 )
  {
    v1 &= ~4u;
    v4 = "|";
    if ( v1 == 0 )
      v4 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "CLAMPS", v4);
  }
  if ( (v1 & 8) != 0 )
  {
    v1 &= ~8u;
    v5 = "|";
    if ( v1 == 0 )
      v5 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "CLAMPT", v5);
  }
  if ( (v1 & 0x10) != 0 )
  {
    v1 &= ~0x10u;
    v6 = "|";
    if ( v1 == 0 )
      v6 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "ANISOTROPIC", v6);
  }
  if ( (v1 & 0x20) != 0 )
  {
    v1 &= ~0x20u;
    v7 = "|";
    if ( v1 == 0 )
      v7 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "HINT_DXT5", v7);
  }
  if ( (v1 & 0x80) == 0x80 )
  {
    v1 &= ~0x80u;
    v8 = "|";
    if ( v1 == 0 )
      v8 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "NORMAL", v8);
  }
  if ( (v1 & 0x100) != 0 )
  {
    v1 &= ~0x100u;
    v9 = "|";
    if ( v1 == 0 )
      v9 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "NOMIP", v9);
  }
  if ( (v1 & 0x200) != 0 )
  {
    v1 &= ~0x200u;
    v10 = "|";
    if ( v1 == 0 )
      v10 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "NOLOD", v10);
  }
  if ( (v1 & 0x400) != 0 )
  {
    v1 &= ~0x400u;
    v11 = "|";
    if ( v1 == 0 )
      v11 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "ALL_MIPS", v11);
  }
  if ( (v1 & 0x800) != 0 )
  {
    v1 &= ~0x800u;
    v12 = "|";
    if ( v1 == 0 )
      v12 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "PROCEDURAL", v12);
  }
  if ( (v1 & 0x1000) != 0 )
  {
    v1 &= ~0x1000u;
    v13 = "|";
    if ( v1 == 0 )
      v13 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "ONEBITALPHA", v13);
  }
  if ( (v1 & 0x2000) != 0 )
  {
    v1 &= ~0x2000u;
    v14 = "|";
    if ( v1 == 0 )
      v14 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "EIGHTBITALPHA", v14);
  }
  if ( (v1 & 0x4000) != 0 )
  {
    v1 &= ~0x4000u;
    v15 = "|";
    if ( v1 == 0 )
      v15 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "ENVMAP", v15);
  }
  if ( (v1 & 0x8000) != 0 )
  {
    v1 &= ~0x8000u;
    v16 = "|";
    if ( v1 == 0 )
      v16 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "RENDERTARGET", v16);
  }
  if ( (v1 & 0x10000) != 0 )
  {
    v1 &= ~0x10000u;
    v17 = "|";
    if ( v1 == 0 )
      v17 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "DEPTHRENDERTARGET", v17);
  }
  if ( (v1 & 0x20000) != 0 )
  {
    v1 &= ~0x20000u;
    v18 = "|";
    if ( v1 == 0 )
      v18 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "NODEBUGOVERRIDE", v18);
  }
  if ( (v1 & 0x40000) != 0 )
  {
    v1 &= ~0x40000u;
    v19 = "|";
    if ( v1 == 0 )
      v19 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "SINGLECOPY", v19);
  }
  if ( (v1 & 0x80000) != 0 )
  {
    v1 &= ~0x80000u;
    v20 = "|";
    if ( v1 == 0 )
      v20 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "SRGB", v20);
  }
  if ( (v1 & 0x100000) != 0 )
  {
    v1 &= ~0x100000u;
    v21 = "|";
    if ( v1 == 0 )
      v21 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "DEFAULT_POOL", v21);
  }
  if ( (v1 & 0x200000) != 0 )
  {
    v1 &= ~0x200000u;
    v22 = "|";
    if ( v1 == 0 )
      v22 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "UNUSED_00200000", v22);
  }
  if ( (v1 & 0x400000) != 0 )
  {
    v1 &= ~0x400000u;
    v23 = "|";
    if ( v1 == 0 )
      v23 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "UNUSED_00400000", v23);
  }
  if ( (v1 & 0x800000) != 0 )
  {
    v1 &= ~0x800000u;
    v24 = "|";
    if ( v1 == 0 )
      v24 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "NODEPTHBUFFER", v24);
  }
  if ( (v1 & 0x1000000) != 0 )
  {
    v1 &= ~0x1000000u;
    v25 = "|";
    if ( v1 == 0 )
      v25 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "UNUSED_01000000", v25);
  }
  if ( (v1 & 0x2000000) != 0 )
  {
    v1 &= ~0x2000000u;
    v26 = "|";
    if ( v1 == 0 )
      v26 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "CLAMPU", v26);
  }
  if ( (v1 & 0x4000000) != 0 )
  {
    v1 &= ~0x4000000u;
    v27 = "|";
    if ( v1 == 0 )
      v27 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "VERTEXTEXTURE", v27);
  }
  if ( (v1 & 0x8000000) != 0 )
  {
    v1 &= ~0x8000000u;
    v28 = "|";
    if ( v1 == 0 )
      v28 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "SSBUMP", v28);
  }
  if ( (v1 & 0x10000000) != 0 )
  {
    v1 &= ~0x10000000u;
    v29 = "|";
    if ( v1 == 0 )
      v29 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "MOST_MIPS", v29);
  }
  if ( (v1 & 0x20000000) != 0 )
  {
    v1 &= ~0x20000000u;
    v30 = "|";
    if ( v1 == 0 )
      v30 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "BORDER", v30);
  }
  if ( (v1 & 0x40000000) != 0 )
  {
    v1 &= ~0x40000000u;
    v31 = "|";
    if ( v1 == 0 )
      v31 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "UNUSED_40000000", v31);
  }
  if ( (v1 & 0x80000000) == 0x80000000 )
  {
    v1 &= ~0x80000000;
    v32 = "|";
    if ( v1 == 0 )
      v32 = (const char *)&unk_4495B9;
    printf(format: "%s%s", "UNUSED_80000000", v32);
  }
  if ( v1 != 0 )
    printf(format: "0x%08X", v1);
}

//------------------------------------------------------------------------------
// Address: 0x00401740
// Name: public: static bool CDefOps<int>::LessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<int>::LessFunc(const int *lhs, const int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00401760
// Name: bool LoadFileIntoBuffer(char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadFileIntoBuffer(const char *pFileName, CUtlBuffer *buf)
{
  _iobuf *v2; // esi
  int v4; // ebx
  _stat64i32 statBuf; // [esp+Ch] [ebp-30h] BYREF

  if ( _stat64i32(name: pFileName, buf: &statBuf) == 0
    && (CUtlBuffer::EnsureCapacity(this: buf, num: statBuf.st_size), (v2 = fopen(file: pFileName, mode: "rb")) != nullptr) )
  {
    v4 = fread(buffer: buf->m_Memory.m_pMemory, elementSize: 1u, count: statBuf.st_size, stream: v2);
    fclose(stream: v2);
    CUtlBuffer::SeekPut(this: buf, type: SEEK_HEAD, offset: v4);
    return 1;
  }
  else
  {
    printf(format: "Can't find file %s\n", pFileName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004017F0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004018A0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4A7694 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_4A7694;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4A7694 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00401960
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4A7694 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004019C0
// Name: protected: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<int,bool,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<int,bool,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401AB0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401BB0
// Name: protected: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00401CA0
// Name: protected: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00401D90
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401DC0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<int,bool,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<int,bool,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00401EC0
// Name: public: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F70
// Name: protected: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4A7694 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4A7694 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4A7694 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4A7694 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4A7694 = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_4A7694 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_4A7694 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4A7694 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4A7694 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4A7694 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4A7694 = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_4A7694 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_4A7694 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402560
// Name: public: CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004025D0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v4; // esi
  IVTFTexture *VTFTexture; // esi
  IVTFTexture *v6; // eax
  bool (__thiscall *Unserialize)(IVTFTexture *, CUtlBuffer *, bool, int); // edx
  IVTFTexture *v8; // ebx
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // edi
  int v19; // edi
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // edi
  int v24; // eax
  int v25; // eax
  int v26; // edi
  int v27; // eax
  int v28; // edi
  int v29; // eax
  int v30; // eax
  int v31; // edi
  int v32; // eax
  unsigned int v33; // eax
  unsigned int v34; // eax
  double v35; // st7
  unsigned __int64 v36; // st7
  double v37; // st7
  int v38; // edi
  ImageFormat v39; // eax
  const char *m_pName; // edi
  ImageFormat v41; // eax
  const ImageFormatInfo_t *v42; // eax
  int v43; // edi
  ImageFormat v44; // eax
  const char *v45; // edi
  ImageFormat v46; // eax
  float *v47; // edi
  float *v48; // eax
  int y_low; // xmm0_4
  const Vector *(__thiscall *Reflectivity)(IVTFTexture *); // eax
  unsigned int *x_low; // xmm0_4
  const Vector *(__thiscall *v52)(IVTFTexture *); // eax
  float v53; // xmm0_4
  const Vector *(__thiscall *v54)(IVTFTexture *); // eax
  unsigned int v55; // xmm0_4
  const Vector *(__thiscall *v56)(IVTFTexture *); // eax
  float *v57; // eax
  int v58; // edi
  int v59; // eax
  unsigned __int8 *v60; // eax
  IVTFTexture_vtbl *v61; // edx
  int v62; // edi
  int (__thiscall *ComputeTotalSize)(IVTFTexture *); // eax
  unsigned int v64; // eax
  _BYTE *v65; // ecx
  ImageFormat (__thiscall *Format)(IVTFTexture *); // eax
  int v67; // edi
  int v68; // eax
  int v69; // eax
  int (__thiscall *FrameCount)(IVTFTexture *); // edx
  int v71; // eax
  signed int v72; // edi
  int v73; // ebx
  bool v74; // zf
  int (__thiscall *FaceCount)(IVTFTexture *); // edx
  int v76; // eax
  int v77; // eax
  int v78; // ecx
  int v79; // ebx
  unsigned int v80; // eax
  _BYTE *v81; // edi
  _BYTE *v82; // ecx
  const void *v83; // ecx
  int v84; // ebx
  unsigned __int8 *v85; // edi
  unsigned __int8 *v86; // ebx
  ImageFormat v87; // eax
  unsigned int m_nNumBytes; // eax
  unsigned __int8 *v89; // ecx
  int (__thiscall *v90)(IVTFTexture *); // eax
  int v91; // edi
  unsigned int v92; // edi
  int v93; // edi
  unsigned int *v94; // ecx
  int v95; // ecx
  unsigned __int8 *v96; // eax
  _BYTE *v97; // ecx
  unsigned int *v98; // eax
  IVTFTexture_vtbl *v99; // edx
  int v100; // ecx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v102; // edi
  int v103; // ecx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *v104; // eax
  int v105; // edi
  int v106; // ecx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *v107; // eax
  int v108; // edi
  unsigned int *v109; // edi
  void *v110; // esp
  int v111; // edi
  unsigned int *v112; // edx
  int v113; // eax
  int v114; // ecx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *v115; // eax
  int v116; // edi
  unsigned int v117; // edi
  _BYTE *v118; // edi
  const char *v119; // eax
  unsigned int v120; // ecx
  _BYTE *v121; // edx
  int v122; // eax
  int v123; // [esp+34h] [ebp-ECh]
  int v124; // [esp+38h] [ebp-E8h]
  int v125; // [esp+38h] [ebp-E8h]
  int v126; // [esp+3Ch] [ebp-E4h]
  int v127; // [esp+3Ch] [ebp-E4h]
  const char *v128; // [esp+3Ch] [ebp-E4h]
  const char *v129; // [esp+3Ch] [ebp-E4h]
  int v130; // [esp+40h] [ebp-E0h]
  int v131; // [esp+40h] [ebp-E0h]
  int v132; // [esp+40h] [ebp-E0h]
  double v133; // [esp+40h] [ebp-E0h]
  int v134; // [esp+40h] [ebp-E0h]
  const char *v135; // [esp+40h] [ebp-E0h]
  int v136; // [esp+40h] [ebp-E0h]
  const char *v137; // [esp+40h] [ebp-E0h]
  int v138; // [esp+44h] [ebp-DCh]
  int v139; // [esp+44h] [ebp-DCh]
  int v140; // [esp+44h] [ebp-DCh]
  int v141; // [esp+44h] [ebp-DCh]
  int v142; // [esp+44h] [ebp-DCh]
  int v143; // [esp+44h] [ebp-DCh]
  int v144; // [esp+44h] [ebp-DCh]
  int v145; // [esp+44h] [ebp-DCh]
  const char *v146; // [esp+44h] [ebp-DCh]
  unsigned int v147; // [esp+44h] [ebp-DCh]
  int v148; // [esp+48h] [ebp-D8h] BYREF
  CUtlBuffer file1; // [esp+54h] [ebp-CCh] BYREF
  IVTFTexture *arrTextures[2]; // [esp+84h] [ebp-9Ch]
  CUtlBuffer file2; // [esp+8Ch] [ebp-94h] BYREF
  CUtlMap<int,bool,unsigned short>::Node_t search; // [esp+BCh] [ebp-64h] BYREF
  const void *pvResData2; // [esp+C4h] [ebp-5Ch] BYREF
  CUtlMap<int,bool,unsigned short> mapTypes; // [esp+C8h] [ebp-58h] BYREF
  CUtlMap<int,bool,unsigned short>::Node_t v155; // [esp+E4h] [ebp-3Ch] BYREF
  unsigned int *v156; // [esp+ECh] [ebp-34h]
  IVTFTexture *pTexture2; // [esp+F0h] [ebp-30h]
  int z; // [esp+F4h] [ebp-2Ch]
  unsigned int numBytes2; // [esp+F8h] [ebp-28h] BYREF
  CUtlMap<int,bool,unsigned short>::Node_t insert; // [esp+FCh] [ebp-24h] BYREF
  unsigned int uiResType; // [esp+104h] [ebp-1Ch]
  unsigned int *puiresbuffer; // [esp+108h] [ebp-18h] BYREF
  int y; // [esp+10Ch] [ebp-14h]
  int numRes2; // [esp+110h] [ebp-10h]
  main::__l5::Options_t opts; // [esp+117h] [ebp-9h]
  const void *pvResData1; // [esp+118h] [ebp-8h] BYREF
  bool bImgDataDiffers; // [esp+11Fh] [ebp-1h] BYREF
  float bMatch; // [esp+128h] [ebp+8h]
  char bMatch_3; // [esp+12Bh] [ebp+Bh]

  if ( argc < 3 )
  {
    printf(format: "Usage: vtfdiff file1.vtf file2.vtf\n");
    return 10;
  }
  v4 = 3;
  for ( opts.bStrict = false; v4 < argc; ++v4 )
  {
    if ( _V_stricmp(s1: argv[v4], s2: "-strict") == 0 )
      opts.bStrict = true;
  }
  CUtlBuffer::CUtlBuffer(this: &file1, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &file2, growSize: 0, initSize: 0, nFlags: 0);
  if ( LoadFileIntoBuffer(pFileName: argv[1], buf: &file1) == 0 )
  {
    if ( file2.m_Memory.m_nGrowSize >= 0 )
    {
      if ( file2.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file2.m_Memory.m_pMemory);
        file2.m_Memory.m_pMemory = nullptr;
      }
      file2.m_Memory.m_nAllocationCount = 0;
    }
    if ( file1.m_Memory.m_nGrowSize >= 0 && file1.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file1.m_Memory.m_pMemory);
    return 21;
  }
  if ( LoadFileIntoBuffer(pFileName: argv[2], buf: &file2) == 0 )
  {
    if ( file2.m_Memory.m_nGrowSize >= 0 )
    {
      if ( file2.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file2.m_Memory.m_pMemory);
        file2.m_Memory.m_pMemory = nullptr;
      }
      file2.m_Memory.m_nAllocationCount = 0;
    }
    if ( file1.m_Memory.m_nGrowSize >= 0 && file1.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file1.m_Memory.m_pMemory);
    return 22;
  }
  VTFTexture = CreateVTFTexture();
  v6 = CreateVTFTexture();
  Unserialize = VTFTexture->Unserialize;
  v8 = v6;
  pTexture2 = v6;
  arrTextures[0] = VTFTexture;
  arrTextures[1] = v6;
  bMatch_3 = 1;
  if ( !Unserialize(this: VTFTexture, a2: &file1, a3: false, a4: 0) )
  {
    printf(format: "error loading %s\n", argv[1]);
    if ( file2.m_Memory.m_nGrowSize >= 0 )
    {
      if ( file2.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file2.m_Memory.m_pMemory);
        file2.m_Memory.m_pMemory = nullptr;
      }
      file2.m_Memory.m_nAllocationCount = 0;
    }
    if ( file1.m_Memory.m_nGrowSize >= 0 && file1.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file1.m_Memory.m_pMemory);
    return 31;
  }
  if ( v8->Unserialize(this: v8, a2: &file2, a3: false, a4: 0) )
  {
    v9 = v8->Width(this: v8);
    if ( VTFTexture->Width(this: VTFTexture) != v9
      || (v10 = v8->Height(this: v8), VTFTexture->Height(this: VTFTexture) != v10)
      || (v11 = v8->Depth(this: v8), VTFTexture->Depth(this: VTFTexture) != v11) )
    {
      v12 = v8->Depth(this: v8);
      v13 = ((int (__thiscall *)(IVTFTexture *, int))v8->Height)(a1: v8, a2: v12);
      v14 = ((int (__thiscall *)(IVTFTexture *, int))v8->Width)(a1: v8, a2: v13);
      v15 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->Depth)(a1: VTFTexture, a2: v14);
      v16 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->Height)(a1: VTFTexture, a2: v15);
      v17 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->Width)(a1: VTFTexture, a2: v16);
      printf(format: "%s dimensions differ: %dx%dx%d != %dx%dx%d\n", argv[1], v17, v123, v124, v126, v130, v138);
      bMatch_3 = 0;
    }
    v18 = v8->LowResWidth(this: v8);
    if ( VTFTexture->LowResWidth(this: VTFTexture) != v18
      || (v19 = v8->LowResHeight(this: v8), VTFTexture->LowResHeight(this: VTFTexture) != v19) )
    {
      v20 = v8->LowResHeight(this: v8);
      v21 = ((int (__thiscall *)(IVTFTexture *, int))v8->LowResWidth)(a1: v8, a2: v20);
      v22 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->LowResHeight)(a1: VTFTexture, a2: v21);
      v125 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->LowResWidth)(a1: VTFTexture, a2: v22);
      printf(format: "%s lowres dimensions differ: %dx%d != %dx%d\n", argv[1], v125, v127, v131, v139);
      bMatch_3 = 0;
    }
    v23 = v8->MipCount(this: v8);
    if ( VTFTexture->MipCount(this: VTFTexture) != v23 )
    {
      v24 = v8->MipCount(this: v8);
      v25 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->MipCount)(a1: VTFTexture, a2: v24);
      printf(format: "%s differing mipcounts: %d != %d\n", argv[1], v25, v140);
      bMatch_3 = 0;
    }
    v26 = v8->FaceCount(this: v8);
    if ( VTFTexture->FaceCount(this: VTFTexture) != v26 )
    {
      v27 = v8->FaceCount(this: v8);
      v132 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->FaceCount)(a1: VTFTexture, a2: v27);
      printf(format: "%s differing facecount: %d != %d\n", argv[1], v132, v141);
      bMatch_3 = 0;
    }
    v28 = v8->FrameCount(this: v8);
    if ( VTFTexture->FrameCount(this: VTFTexture) != v28 )
    {
      v29 = v8->FrameCount(this: v8);
      v30 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->FrameCount)(a1: VTFTexture, a2: v29);
      printf(format: "%s differing framecount: %d != %d\n", argv[1], v30, v142);
      bMatch_3 = 0;
    }
    pvResData1 = (const void *)-13569;
    if ( opts.bStrict )
      pvResData1 = (const void *)-1;
    v31 = v8->Flags(this: v8);
    v32 = VTFTexture->Flags(this: VTFTexture);
    if ( ((v32 ^ v31) & (unsigned int)pvResData1) != 0 )
    {
      printf(format: "%s differing flags: \"", argv[1]);
      v33 = VTFTexture->Flags(this: VTFTexture);
      PrintFlags(flags: v33);
      printf(format: "\" != \"");
      v34 = v8->Flags(this: v8);
      PrintFlags(flags: v34);
      printf(format: "\"\n");
      bMatch_3 = 0;
    }
    *(float *)&numRes2 = VTFTexture->BumpScale(this: VTFTexture);
    v35 = ((double (__thiscall *)(IVTFTexture *))v8->BumpScale)(a1: v8);
    if ( *(float *)&numRes2 != v35 )
    {
      *(double *)&v36 = ((double (__thiscall *)(IVTFTexture *))v8->BumpScale)(a1: v8);
      v37 = ((double (__thiscall *)(IVTFTexture *, _DWORD, _DWORD))VTFTexture->BumpScale)(
              a1: VTFTexture,
              a2: v36,
              a3: HIDWORD(v36));
      printf(format: "%s differing bumpscale: %f != %f\n", argv[1], v37, v133);
      bMatch_3 = 0;
    }
    v38 = v8->Format(this: v8);
    if ( VTFTexture->Format(this: VTFTexture) != v38 )
    {
      v39 = v8->Format(this: v8);
      m_pName = ImageLoader::ImageFormatInfo(fmt: v39)->m_pName;
      v41 = VTFTexture->Format(this: VTFTexture);
      v42 = ImageLoader::ImageFormatInfo(fmt: v41);
      printf(format: "%s differing image format: %s != %s\n", argv[1], v42->m_pName, m_pName);
      bMatch_3 = 0;
    }
    v43 = v8->LowResFormat(this: v8);
    if ( VTFTexture->LowResFormat(this: VTFTexture) != v43 )
    {
      v44 = v8->LowResFormat(this: v8);
      v45 = ImageLoader::ImageFormatInfo(fmt: v44)->m_pName;
      v46 = VTFTexture->LowResFormat(this: VTFTexture);
      v128 = ImageLoader::ImageFormatInfo(fmt: v46)->m_pName;
      printf(format: "%s differing lowres image format: %s != %s\n", argv[1], v128, v45);
      bMatch_3 = 0;
    }
    v47 = (float *)VTFTexture->Reflectivity(this: VTFTexture);
    v48 = (float *)v8->Reflectivity(this: v8);
    if ( opts.bStrict
      && (fabs(*v47 - *v48) > 0.000099999997
       || fabs(v47[1] - v48[1]) > 0.000099999997
       || fabs(v47[2] - v48[2]) > 0.000099999997) )
    {
      bMatch = v8->Reflectivity(this: v8)->z;
      y_low = SLODWORD(v8->Reflectivity(this: v8)->y);
      Reflectivity = v8->Reflectivity;
      numRes2 = y_low;
      x_low = (unsigned int *)LODWORD(Reflectivity(this: v8)->x);
      v52 = VTFTexture->Reflectivity;
      puiresbuffer = x_low;
      v53 = v52(this: VTFTexture)->z;
      v54 = VTFTexture->Reflectivity;
      *(float *)&insert.elem = v53;
      v55 = LODWORD(v54(this: VTFTexture)->y);
      v56 = VTFTexture->Reflectivity;
      numBytes2 = v55;
      v57 = (float *)v56(this: VTFTexture);
      printf(
        format: "%s differing reflectivity: [%f,%f,%f] != [%f,%f,%f]\n",
        argv[1],
        *v57,
        *(float *)&numBytes2,
        *(float *)&insert.elem,
        *(float *)&puiresbuffer,
        *(float *)&numRes2,
        bMatch);
      bMatch_3 = 0;
    }
    v58 = v8->ComputeTotalSize(this: v8);
    if ( VTFTexture->ComputeTotalSize(this: VTFTexture) != v58 )
    {
      v59 = v8->ComputeTotalSize(this: v8);
      v134 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->ComputeTotalSize)(a1: VTFTexture, a2: v59);
      printf(format: "%s differing image data size: %d != %d\n", argv[1], v134, v143);
LABEL_130:
      bMatch_3 = 0;
      goto LABEL_131;
    }
    if ( bMatch_3 == 0 )
      goto LABEL_131;
    v60 = VTFTexture->ImageData_3(this: VTFTexture);
    v61 = v8->__vftable;
    pvResData1 = v60;
    *(float *)&v62 = COERCE_FLOAT((int)v61->ImageData_3(this: v8));
    ComputeTotalSize = VTFTexture->ComputeTotalSize;
    puiresbuffer = (unsigned int *)v62;
    *(float *)&v64 = COERCE_FLOAT(ComputeTotalSize(this: VTFTexture));
    v65 = pvResData1;
    numRes2 = v64;
    if ( v64 < 4 )
    {
LABEL_77:
      if ( *(float *)&v64 == 0.0
        || *(_BYTE *)v62 == *v65
        && (v64 <= 1 || *(_BYTE *)(v62 + 1) == v65[1] && (v64 <= 2 || *(_BYTE *)(v62 + 2) == v65[2])) )
      {
        goto LABEL_131;
      }
    }
    else
    {
      while ( *(_DWORD *)v65 == *(_DWORD *)v62 )
      {
        v64 -= 4;
        v62 += 4;
        v65 += 4;
        if ( v64 < 4 )
          goto LABEL_77;
      }
    }
    Format = VTFTexture->Format;
    bImgDataDiffers = false;
    if ( Format(this: VTFTexture) == IMAGE_FORMAT_DXT1
      || VTFTexture->Format(this: VTFTexture) == IMAGE_FORMAT_DXT3
      || VTFTexture->Format(this: VTFTexture) == IMAGE_FORMAT_DXT5
      || VTFTexture->Format(this: VTFTexture) == IMAGE_FORMAT_ATI2N
      || VTFTexture->Format(this: VTFTexture) == IMAGE_FORMAT_ATI1N )
    {
      y = VTFTexture->ComputeMipSize(this: VTFTexture, a2: 0);
      if ( opts.bStrict )
        y = numRes2;
      v93 = 0;
      *(float *)&numRes2 = 0.0;
      if ( y > 0 )
      {
        v94 = (unsigned int *)((char *)puiresbuffer - (_BYTE *)pvResData1);
        puiresbuffer = (unsigned int *)((char *)puiresbuffer - (unsigned int)pvResData1);
        do
        {
          if ( *((_BYTE *)pvResData1 + v93) != *((_BYTE *)pvResData1 + v93 + (_DWORD)v94) )
          {
            printf(format: "image data at offset %d different\n", v93);
            v95 = numRes2++;
            if ( v95 > 10 )
            {
              printf(format: "image data significantly differs!\n");
              break;
            }
            v94 = puiresbuffer;
          }
          ++v93;
        }
        while ( v93 < y );
      }
    }
    else
    {
      v67 = v8->FrameCount(this: v8);
      if ( VTFTexture->FrameCount(this: VTFTexture) != v67 )
      {
        v68 = v8->FrameCount(this: v8);
        v69 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->FrameCount)(a1: VTFTexture, a2: v68);
        printf(format: "%s differing frame count: %d != %d\n", argv[1], v69, v144);
LABEL_129:
        printf(format: "%s image data different\n", argv[1]);
        goto LABEL_130;
      }
      FrameCount = VTFTexture->FrameCount;
      *(_DWORD *)&v155.elem = 0;
      if ( FrameCount(this: VTFTexture) > 0 )
      {
        do
        {
          v71 = 1;
          numRes2 = 1;
          if ( opts.bStrict )
          {
            *(float *)&v71 = COERCE_FLOAT(VTFTexture->MipCount(this: VTFTexture));
            numRes2 = v71;
          }
          v72 = 0;
          uiResType = 0;
          if ( v71 > 0 )
          {
            do
            {
              VTFTexture->ComputeMipLevelDimensions(
                this: VTFTexture,
                a2: v72,
                a3: (int *)&pvResData2,
                a4: (int *)&numBytes2,
                a5: (int *)&insert.elem);
              *(float *)&puiresbuffer = COERCE_FLOAT(VTFTexture->FaceCount(this: VTFTexture));
              v73 = v8->FaceCount(this: v8);
              v74 = VTFTexture->FaceCount(this: VTFTexture) == v73;
              v8 = pTexture2;
              if ( v74 )
              {
                *(_DWORD *)&search.elem = 0;
                if ( (int)puiresbuffer > 0 )
                {
                  v78 = *(_DWORD *)&insert.elem;
                  while ( 1 )
                  {
                    z = 0;
                    if ( v78 > 0 )
                      break;
LABEL_125:
                    ++*(_DWORD *)&search.elem;
                    if ( *(int *)&search.elem >= (int)puiresbuffer )
                      goto LABEL_126;
                  }
                  while ( 2 )
                  {
                    pvResData1 = VTFTexture->ImageData(
                                   this: VTFTexture,
                                   a2: *(_DWORD *)&v155.elem,
                                   a3: *(_DWORD *)&search.elem,
                                   a4: v72,
                                   a5: 0,
                                   a6: 0,
                                   a7: z);
                    v79 = (int)v8->ImageData(
                                 this: v8,
                                 a2: *(_DWORD *)&v155.elem,
                                 a3: *(_DWORD *)&search.elem,
                                 a4: v72,
                                 a5: 0,
                                 a6: 0,
                                 a7: z);
                    v80 = VTFTexture->ComputeMipSize(this: VTFTexture, a2: v72);
                    v81 = pvResData1;
                    v82 = (_BYTE *)v79;
                    if ( v80 < 4 )
                    {
LABEL_102:
                      if ( v80 != 0 && (*v82 != *v81 || v80 > 1 && (v82[1] != v81[1] || v80 > 2 && v82[2] != v81[2])) )
                        goto LABEL_108;
                    }
                    else
                    {
                      while ( *(_DWORD *)v81 == *(_DWORD *)v82 )
                      {
                        v80 -= 4;
                        v82 += 4;
                        v81 += 4;
                        if ( v80 < 4 )
                          goto LABEL_102;
                      }
LABEL_108:
                      y = 0;
                      if ( (int)numBytes2 > 0 )
                      {
                        v83 = pvResData2;
                        while ( 1 )
                        {
                          pvResData1 = nullptr;
                          if ( (int)v83 > 0 )
                            break;
LABEL_121:
                          if ( ++y >= (int)numBytes2 )
                            goto LABEL_124;
                        }
                        while ( 1 )
                        {
                          v84 = *(_DWORD *)&v155.elem;
                          v85 = VTFTexture->ImageData(
                                  this: VTFTexture,
                                  a2: *(_DWORD *)&v155.elem,
                                  a3: *(_DWORD *)&search.elem,
                                  a4: uiResType,
                                  a5: (int)pvResData1,
                                  a6: y,
                                  a7: z);
                          v86 = pTexture2->ImageData(
                                  this: pTexture2,
                                  a2: v84,
                                  a3: *(_DWORD *)&search.elem,
                                  a4: uiResType,
                                  a5: pvResData1,
                                  a6: y,
                                  a7: z);
                          v87 = VTFTexture->Format(this: VTFTexture);
                          m_nNumBytes = ImageLoader::ImageFormatInfo(fmt: v87)->m_nNumBytes;
                          v89 = v86;
                          if ( m_nNumBytes >= 4 )
                            break;
LABEL_114:
                          if ( m_nNumBytes != 0
                            && (*v89 != *v85
                             || m_nNumBytes > 1 && (v89[1] != v85[1] || m_nNumBytes > 2 && v89[2] != v85[2])) )
                          {
                            goto LABEL_123;
                          }
                          v83 = pvResData2;
                          pvResData1 = (char *)pvResData1 + 1;
                          if ( (int)pvResData1 >= (int)pvResData2 )
                            goto LABEL_121;
                        }
                        while ( *(_DWORD *)v85 == *(_DWORD *)v89 )
                        {
                          m_nNumBytes -= 4;
                          v89 += 4;
                          v85 += 4;
                          if ( m_nNumBytes < 4 )
                            goto LABEL_114;
                        }
LABEL_123:
                        printf(
                          format: "Frame %d Mip level %d Face %d Z-slice %d texel (%d,%d) different!\n",
                          *(_DWORD *)&v155.elem,
                          uiResType,
                          *(_DWORD *)&search.elem,
                          z,
                          pvResData1,
                          y);
                        bImgDataDiffers = true;
                      }
                    }
LABEL_124:
                    v78 = *(_DWORD *)&insert.elem;
                    v8 = pTexture2;
                    v72 = uiResType;
                    if ( ++z >= *(int *)&insert.elem )
                      goto LABEL_125;
                    continue;
                  }
                }
              }
              else
              {
                FaceCount = pTexture2->FaceCount;
                bImgDataDiffers = true;
                v76 = FaceCount(this: pTexture2);
                v77 = ((int (__thiscall *)(IVTFTexture *, int))VTFTexture->FaceCount)(a1: VTFTexture, a2: v76);
                printf(
                  format: "%s differing face counts at mip %d frame %d: %d != %d\n",
                  argv[1],
                  v72,
                  *(_DWORD *)&v155.elem,
                  v77,
                  v145);
              }
LABEL_126:
              uiResType = ++v72;
            }
            while ( v72 < numRes2 );
          }
          v90 = VTFTexture->FrameCount;
          v91 = ++*(_DWORD *)&v155.elem;
        }
        while ( v91 < v90(this: VTFTexture) );
        if ( bImgDataDiffers )
          goto LABEL_129;
      }
    }
LABEL_131:
    if ( !opts.bStrict )
      goto LABEL_156;
    VTFTexture->LowResFileInfo(this: VTFTexture, a2: (int *)&puiresbuffer, a3: (int *)&insert.elem);
    v8->LowResFileInfo(this: v8, a2: (int *)&puiresbuffer, a3: (int *)&numBytes2);
    v92 = *(_DWORD *)&insert.elem;
    if ( *(_DWORD *)&insert.elem == numBytes2 )
    {
      if ( bMatch_3 == 0 )
        goto LABEL_156;
      *(float *)&numRes2 = COERCE_FLOAT((int)v8->LowResImageData(this: v8));
      v96 = VTFTexture->LowResImageData(this: VTFTexture);
      v97 = (_BYTE *)numRes2;
      if ( v92 < 4 )
      {
LABEL_148:
        if ( v92 == 0 || *v97 == *v96 && (v92 <= 1 || v97[1] == v96[1] && (v92 <= 2 || v97[2] == v96[2])) )
          goto LABEL_156;
      }
      else
      {
        while ( *(_DWORD *)v96 == *(_DWORD *)v97 )
        {
          v92 -= 4;
          v97 += 4;
          v96 += 4;
          if ( v92 < 4 )
            goto LABEL_148;
        }
      }
      printf(format: "%s differing low res image data\n", argv[1]);
    }
    else
    {
      printf(format: "%s differing low res image data size: %d != %d\n", argv[1], *(_DWORD *)&insert.elem, numBytes2);
    }
    bMatch_3 = 0;
LABEL_156:
    *(float *)&v98 = COERCE_FLOAT(VTFTexture->GetResourceTypes(this: VTFTexture, a2: nullptr, a3: 0));
    v99 = v8->__vftable;
    puiresbuffer = v98;
    *(float *)&numRes2 = COERCE_FLOAT(v99->GetResourceTypes(this: v8, a2: nullptr, a3: 0));
    mapTypes.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<int>::LessFunc;
    memset(&mapTypes.m_Tree.m_Elements, 0, sizeof(mapTypes.m_Tree.m_Elements));
    *(_DWORD *)&mapTypes.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&mapTypes.m_Tree.m_FirstFree = -1;
    mapTypes.m_Tree.m_pElements = nullptr;
    insert.key = 1;
    insert.elem = true;
    pvResData1 = (const void *)0xFFFF;
    bImgDataDiffers = false;
    CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &mapTypes.m_Tree,
      &insert,
      parent: (unsigned __int16 *)&pvResData1,
      leftchild: &bImgDataDiffers);
    v100 = (unsigned __int16)CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &mapTypes.m_Tree);
    m_pMemory = mapTypes.m_Tree.m_Elements.m_pMemory;
    v102 = v100;
    mapTypes.m_Tree.m_Elements.m_pMemory[v102].m_Parent = (unsigned __int16)pvResData1;
    m_pMemory[v102].m_Right = -1;
    m_pMemory[v102].m_Left = -1;
    m_pMemory[v102].m_Tag = 0;
    if ( (_WORD)pvResData1 == 0xFFFF )
    {
      mapTypes.m_Tree.m_Root = v100;
    }
    else if ( bImgDataDiffers )
    {
      m_pMemory[(unsigned __int16)pvResData1].m_Left = v100;
    }
    else
    {
      m_pMemory[(unsigned __int16)pvResData1].m_Right = v100;
    }
    CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &mapTypes.m_Tree,
      elem: v100);
    ++mapTypes.m_Tree.m_NumElements;
    if ( &mapTypes.m_Tree.m_Elements.m_pMemory[v102] != (UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *)-8 )
      mapTypes.m_Tree.m_Elements.m_pMemory[v102].m_Data = insert;
    insert.key = 48;
    insert.elem = true;
    pvResData1 = (const void *)0xFFFF;
    bImgDataDiffers = false;
    CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &mapTypes.m_Tree,
      &insert,
      parent: (unsigned __int16 *)&pvResData1,
      leftchild: &bImgDataDiffers);
    v103 = (unsigned __int16)CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &mapTypes.m_Tree);
    v104 = mapTypes.m_Tree.m_Elements.m_pMemory;
    v105 = v103;
    mapTypes.m_Tree.m_Elements.m_pMemory[v105].m_Parent = (unsigned __int16)pvResData1;
    v104[v105].m_Right = -1;
    v104[v105].m_Left = -1;
    v104[v105].m_Tag = 0;
    if ( (_WORD)pvResData1 == 0xFFFF )
    {
      mapTypes.m_Tree.m_Root = v103;
    }
    else if ( bImgDataDiffers )
    {
      v104[(unsigned __int16)pvResData1].m_Left = v103;
    }
    else
    {
      v104[(unsigned __int16)pvResData1].m_Right = v103;
    }
    CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &mapTypes.m_Tree,
      elem: v103);
    ++mapTypes.m_Tree.m_NumElements;
    if ( &mapTypes.m_Tree.m_Elements.m_pMemory[v105] != (UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *)-8 )
      mapTypes.m_Tree.m_Elements.m_pMemory[v105].m_Data = insert;
    insert.key = (int)&loc_435243;
    insert.elem = true;
    pvResData1 = (const void *)0xFFFF;
    bImgDataDiffers = false;
    CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &mapTypes.m_Tree,
      &insert,
      parent: (unsigned __int16 *)&pvResData1,
      leftchild: &bImgDataDiffers);
    v106 = (unsigned __int16)CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &mapTypes.m_Tree);
    v107 = mapTypes.m_Tree.m_Elements.m_pMemory;
    v108 = v106;
    mapTypes.m_Tree.m_Elements.m_pMemory[v108].m_Parent = (unsigned __int16)pvResData1;
    v107[v108].m_Right = -1;
    v107[v108].m_Left = -1;
    v107[v108].m_Tag = 0;
    if ( (_WORD)pvResData1 == 0xFFFF )
    {
      mapTypes.m_Tree.m_Root = v106;
    }
    else if ( bImgDataDiffers )
    {
      v107[(unsigned __int16)pvResData1].m_Left = v106;
    }
    else
    {
      v107[(unsigned __int16)pvResData1].m_Right = v106;
    }
    CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &mapTypes.m_Tree,
      elem: v106);
    ++mapTypes.m_Tree.m_NumElements;
    if ( &mapTypes.m_Tree.m_Elements.m_pMemory[v108] != (UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *)-8 )
      mapTypes.m_Tree.m_Elements.m_pMemory[v108].m_Data = insert;
    v109 = puiresbuffer;
    v110 = alloca(4 * ((_DWORD)puiresbuffer + numRes2));
    *(float *)&puiresbuffer = COERCE_FLOAT(&v148);
    v156 = v109;
    pTexture2 = (IVTFTexture *)numRes2;
    y = 0;
    while ( 1 )
    {
      v111 = *(int *)((char *)&v156 + y);
      (*(IVTFTexture **)((char *)arrTextures + y))->GetResourceTypes(
        this: *(IVTFTexture **)((char *)arrTextures + y),
        a2: puiresbuffer,
        a3: v111);
      if ( v111 > 0 )
        break;
LABEL_210:
      v122 = y;
      *(unsigned int **)((char *)&v156 + y) = (unsigned int *)(*(char **)((char *)&v156 + y) - 1);
      y = v122 + 4;
      if ( v122 + 4 >= 8 )
      {
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &mapTypes.m_Tree);
        CUtlBuffer::~CUtlBuffer(this: &file2);
        CUtlBuffer::~CUtlBuffer(this: &file1);
        return bMatch_3 == 0;
      }
    }
    numRes2 = v111;
    while ( 1 )
    {
      v112 = puiresbuffer;
      v113 = numRes2 - 1;
      *(unsigned int **)((char *)&v156 + y) = (unsigned int *)(numRes2 - 1);
      numRes2 = v113;
      uiResType = v112[v113];
      search.key = uiResType;
      if ( CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &mapTypes.m_Tree,
             &search) == 0xFFFF )
      {
        pvResData1 = (const void *)0xFFFF;
        v155.key = uiResType;
        v155.elem = true;
        bImgDataDiffers = false;
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: &mapTypes.m_Tree,
          insert: &v155,
          parent: (unsigned __int16 *)&pvResData1,
          leftchild: &bImgDataDiffers);
        v114 = (unsigned __int16)CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &mapTypes.m_Tree);
        v115 = mapTypes.m_Tree.m_Elements.m_pMemory;
        v116 = v114;
        mapTypes.m_Tree.m_Elements.m_pMemory[v116].m_Parent = (unsigned __int16)pvResData1;
        v115[v116].m_Right = -1;
        v115[v116].m_Left = -1;
        v115[v116].m_Tag = 0;
        if ( (_WORD)pvResData1 == 0xFFFF )
        {
          mapTypes.m_Tree.m_Root = v114;
        }
        else if ( bImgDataDiffers )
        {
          v115[(unsigned __int16)pvResData1].m_Left = v114;
        }
        else
        {
          v115[(unsigned __int16)pvResData1].m_Right = v114;
        }
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
          this: &mapTypes.m_Tree,
          elem: v114);
        ++mapTypes.m_Tree.m_NumElements;
        if ( &mapTypes.m_Tree.m_Elements.m_pMemory[v116] != (UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *)-8 )
          mapTypes.m_Tree.m_Elements.m_pMemory[v116].m_Data = v155;
        v117 = uiResType;
        pvResData1 = VTFTexture->GetResourceData(this: VTFTexture, a2: uiResType, a3: (unsigned int *)&insert.elem);
        v118 = v8->GetResourceData(this: v8, a2: v117, a3: &numBytes2);
        pvResData2 = v118;
        if ( (pvResData1 == nullptr) != (v118 == nullptr) )
        {
          v119 = "present";
          if ( pvResData1 == nullptr )
            v119 = "missing";
          v146 = v119;
          v135 = ResourceToString(uiResType);
          printf(format: "%s different resource %s %s\n", argv[1], v135, v146);
          goto LABEL_208;
        }
        v120 = *(_DWORD *)&insert.elem;
        if ( *(_DWORD *)&insert.elem != numBytes2 )
        {
          v147 = numBytes2;
          v136 = *(_DWORD *)&insert.elem;
          v129 = ResourceToString(uiResType);
          printf(format: "%s different resource %s size %d != %d\n", argv[1], v129, v136, v147);
LABEL_208:
          bMatch_3 = 0;
          goto LABEL_209;
        }
        v121 = pvResData1;
        if ( *(_DWORD *)&insert.elem < 4u )
        {
LABEL_197:
          if ( v120 == 0 || *v118 == *v121 && (v120 <= 1 || v118[1] == v121[1] && (v120 <= 2 || v118[2] == v121[2])) )
            goto LABEL_209;
        }
        else
        {
          while ( *(_DWORD *)v121 == *(_DWORD *)v118 )
          {
            v120 -= 4;
            v118 += 4;
            v121 += 4;
            if ( v120 < 4 )
              goto LABEL_197;
          }
        }
        if ( (_UNKNOWN *)uiResType != (_UNKNOWN *)((char *)&Error_handling_1 + 5)
          || *(_DWORD *)&insert.elem != 4
          || *(_BYTE *)pvResData1 != *(_BYTE *)pvResData2
          || *((_BYTE *)pvResData1 + 1) != *((_BYTE *)pvResData2 + 1) )
        {
          v137 = ResourceToString(uiResType);
          printf(format: "%s different resource %s data\n", argv[1], v137);
          goto LABEL_208;
        }
      }
LABEL_209:
      if ( *(int *)((char *)&v156 + y) <= 0 )
        goto LABEL_210;
    }
  }
  printf(format: "error loading %s\n", argv[2]);
  if ( file2.m_Memory.m_nGrowSize >= 0 )
  {
    if ( file2.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file2.m_Memory.m_pMemory);
      file2.m_Memory.m_pMemory = nullptr;
    }
    file2.m_Memory.m_nAllocationCount = 0;
  }
  if ( file1.m_Memory.m_nGrowSize >= 0 && file1.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file1.m_Memory.m_pMemory);
  return 32;
}

//------------------------------------------------------------------------------
// Address: 0x00406150
// Name: public: void CUtlMemory<class S3RGBA,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<S3RGBA,int>::Grow(CUtlMemory<S3RGBA,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  S3RGBA *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 8;
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
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406B30
// Name: public: void CUtlMemory<struct ResourceEntryInfo,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ResourceEntryInfo,int>::Grow(CUtlMemory<ResourceEntryInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ResourceEntryInfo *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 4;
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
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
