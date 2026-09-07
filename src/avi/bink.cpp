// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: avi/bink.cpp
// Functions: 124
// ============================================================

#include "avi\bink.h"

//------------------------------------------------------------------------------
// Address: 0x10002670
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CAviFile,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CAviFile,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 124 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CAviFile,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: m_pMemory,
                                                                          a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CAviFile,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002960
// Name: protected: unsigned short CUtlLinkedList<class CAviFile,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CAviFile,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CAviFile,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CAviFile,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10002AE0
// Name: protected: unsigned short CUtlLinkedList<class CAVIMaterial __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CAVIMaterial __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10002CA0
// Name: public: void CUtlLinkedList<class CAviFile,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CAviFile,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CAviFile,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D10
// Name: public: void CUtlLinkedList<class CAviFile,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CAviFile,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CAviFile,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002DA0
// Name: public: void CUtlLinkedList<class CBIKMaterial __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CBIKMaterial __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *m_pMemory; // eax
  int m_Previous; // edi
  unsigned __int16 *p_m_Next; // edx
  unsigned __int16 v7; // cx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Previous = m_pMemory[elem].m_Previous;
      p_m_Next = &m_pMemory[elem].m_Next;
      v7 = *p_m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = v7;
      }
      else
      {
        m_pMemory[m_Previous].m_Next = v7;
        v2 = elem;
      }
      if ( v7 == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[v7].m_Previous = m_Previous;
      *p_m_Next = v2;
      --this->m_ElementCount;
      m_pMemory[elem].m_Previous = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002EB0
// Name: public: void CUtlLinkedList<class CAviFile,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CAviFile,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CAviFile,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F40
// Name: public: void CUtlLinkedList<class CBIKMaterial __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CBIKMaterial __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *v7; // ebx

  CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100032A0
// Name: public: virtual void CBIKMaterialYTextureRegenerator::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterialYTextureRegenerator::RegenerateTextureBits(
        CBIKMaterialYTextureRegenerator *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  CBIKMaterial *m_pBIKMaterial; // eax
  unsigned __int8 *Buffer; // edi
  unsigned int BufferPitch; // ebx
  IVTFTexture *v9; // eax
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // eax
  unsigned int v12; // [esp-4h] [ebp-3Ch]
  unsigned __int8 *pixelWriter; // [esp+8h] [ebp-30h]
  unsigned int nWidth; // [esp+30h] [ebp-8h]
  int nHeight; // [esp+34h] [ebp-4h]
  int nHeighta; // [esp+34h] [ebp-4h]
  unsigned __int16 pVTFTexturea; // [esp+44h] [ebp+Ch]
  IVTFTexture *pVTFTextureb; // [esp+44h] [ebp+Ch]

  nWidth = this->m_nSourceWidth;
  nHeight = this->m_nSourceHeight;
  if ( pVTFTexture->FrameCount(this: pVTFTexture) > 1
    || pVTFTexture->FaceCount(this: pVTFTexture) > 1
    || pVTFTexture->MipCount(this: pVTFTexture) > 1
    || pVTFTexture->Depth(this: pVTFTexture) > 1 )
  {
    v12 = pVTFTexture->ComputeTotalSize(this: pVTFTexture);
    v11 = pVTFTexture->ImageData_3(this: pVTFTexture);
    memset(dst: v11, value: 0xFFu, count: v12);
  }
  else
  {
    m_pBIKMaterial = this->m_pBIKMaterial;
    Buffer = (unsigned __int8 *)m_pBIKMaterial->m_buffers.Frames[m_pBIKMaterial->m_buffers.FrameNum].YPlane.Buffer;
    BufferPitch = m_pBIKMaterial->m_buffers.Frames[m_pBIKMaterial->m_buffers.FrameNum].YPlane.BufferPitch;
    pVTFTexturea = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
    pixelWriter = pVTFTexture->ImageData_3(this: pVTFTexture);
    pVTFTexture->Format(this: pVTFTexture);
    v9 = (IVTFTexture *)nHeight;
    if ( nHeight > 0 )
    {
      v10 = pixelWriter;
      nHeighta = pVTFTexturea;
      pVTFTextureb = v9;
      do
      {
        memcpy(dst: v10, src: Buffer, count: nWidth);
        v10 += nHeighta;
        Buffer += BufferPitch;
        pVTFTextureb = (IVTFTexture *)((char *)pVTFTextureb - 1);
      }
      while ( pVTFTextureb != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100033A0
// Name: public: virtual void CBIKMaterialCrTextureRegenerator::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterialCrTextureRegenerator::RegenerateTextureBits(
        CBIKMaterialCrTextureRegenerator *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  CBIKMaterial *m_pBIKMaterial; // eax
  unsigned __int8 *Buffer; // edi
  unsigned int BufferPitch; // ebx
  IVTFTexture *v9; // eax
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // eax
  unsigned int v12; // [esp-4h] [ebp-3Ch]
  unsigned __int8 *pixelWriter; // [esp+8h] [ebp-30h]
  unsigned int nWidth; // [esp+30h] [ebp-8h]
  int nHeight; // [esp+34h] [ebp-4h]
  int nHeighta; // [esp+34h] [ebp-4h]
  unsigned __int16 pVTFTexturea; // [esp+44h] [ebp+Ch]
  IVTFTexture *pVTFTextureb; // [esp+44h] [ebp+Ch]

  nWidth = this->m_nSourceWidth;
  nHeight = this->m_nSourceHeight;
  if ( pVTFTexture->FrameCount(this: pVTFTexture) > 1
    || pVTFTexture->FaceCount(this: pVTFTexture) > 1
    || pVTFTexture->MipCount(this: pVTFTexture) > 1
    || pVTFTexture->Depth(this: pVTFTexture) > 1 )
  {
    v12 = pVTFTexture->ComputeTotalSize(this: pVTFTexture);
    v11 = pVTFTexture->ImageData_3(this: pVTFTexture);
    memset(dst: v11, value: 0xFFu, count: v12);
  }
  else
  {
    m_pBIKMaterial = this->m_pBIKMaterial;
    Buffer = (unsigned __int8 *)m_pBIKMaterial->m_buffers.Frames[m_pBIKMaterial->m_buffers.FrameNum].cRPlane.Buffer;
    BufferPitch = m_pBIKMaterial->m_buffers.Frames[m_pBIKMaterial->m_buffers.FrameNum].cRPlane.BufferPitch;
    pVTFTexturea = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
    pixelWriter = pVTFTexture->ImageData_3(this: pVTFTexture);
    pVTFTexture->Format(this: pVTFTexture);
    v9 = (IVTFTexture *)nHeight;
    if ( nHeight > 0 )
    {
      v10 = pixelWriter;
      nHeighta = pVTFTexturea;
      pVTFTextureb = v9;
      do
      {
        memcpy(dst: v10, src: Buffer, count: nWidth);
        v10 += nHeighta;
        Buffer += BufferPitch;
        pVTFTextureb = (IVTFTexture *)((char *)pVTFTextureb - 1);
      }
      while ( pVTFTextureb != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100034A0
// Name: public: virtual void CBIKMaterialCbTextureRegenerator::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterialCbTextureRegenerator::RegenerateTextureBits(
        CBIKMaterialCbTextureRegenerator *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  CBIKMaterial *m_pBIKMaterial; // eax
  unsigned __int8 *Buffer; // edi
  unsigned int BufferPitch; // ebx
  IVTFTexture *v9; // eax
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // eax
  unsigned int v12; // [esp-4h] [ebp-3Ch]
  unsigned __int8 *pixelWriter; // [esp+8h] [ebp-30h]
  unsigned int nWidth; // [esp+30h] [ebp-8h]
  int nHeight; // [esp+34h] [ebp-4h]
  int nHeighta; // [esp+34h] [ebp-4h]
  unsigned __int16 pVTFTexturea; // [esp+44h] [ebp+Ch]
  IVTFTexture *pVTFTextureb; // [esp+44h] [ebp+Ch]

  nWidth = this->m_nSourceWidth;
  nHeight = this->m_nSourceHeight;
  if ( pVTFTexture->FrameCount(this: pVTFTexture) > 1
    || pVTFTexture->FaceCount(this: pVTFTexture) > 1
    || pVTFTexture->MipCount(this: pVTFTexture) > 1
    || pVTFTexture->Depth(this: pVTFTexture) > 1 )
  {
    v12 = pVTFTexture->ComputeTotalSize(this: pVTFTexture);
    v11 = pVTFTexture->ImageData_3(this: pVTFTexture);
    memset(dst: v11, value: 0xFFu, count: v12);
  }
  else
  {
    m_pBIKMaterial = this->m_pBIKMaterial;
    Buffer = (unsigned __int8 *)m_pBIKMaterial->m_buffers.Frames[m_pBIKMaterial->m_buffers.FrameNum].cBPlane.Buffer;
    BufferPitch = m_pBIKMaterial->m_buffers.Frames[m_pBIKMaterial->m_buffers.FrameNum].cBPlane.BufferPitch;
    pVTFTexturea = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
    pixelWriter = pVTFTexture->ImageData_3(this: pVTFTexture);
    pVTFTexture->Format(this: pVTFTexture);
    v9 = (IVTFTexture *)nHeight;
    if ( nHeight > 0 )
    {
      v10 = pixelWriter;
      nHeighta = pVTFTexturea;
      pVTFTextureb = v9;
      do
      {
        memcpy(dst: v10, src: Buffer, count: nWidth);
        v10 += nHeighta;
        Buffer += BufferPitch;
        pVTFTextureb = (IVTFTexture *)((char *)pVTFTextureb - 1);
      }
      while ( pVTFTextureb != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100035A0
// Name: public: virtual class IVTFTexture __near * CBIKMaterialYTextureRegenerator::GetPreallocatedScratchTexture(void)
// Source: json
//------------------------------------------------------------------------------
IVTFTexture *__thiscall CBIKMaterialYTextureRegenerator::GetPreallocatedScratchTexture(
        CBIKMaterialCbTextureRegenerator *this)
{
  return this->m_pBIKMaterial->m_pScratchTexture;
}

//------------------------------------------------------------------------------
// Address: 0x100035B0
// Name: private: void CBIKMaterial::SetTracks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::SetTracks(CBIKMaterial *this)
{
  BINK *v2; // edx
  BINK *v3; // edx
  BINK *m_pHBINK; // [esp-14h] [ebp-60h]
  BINK *v5; // [esp-14h] [ebp-60h]
  unsigned int nMixBins[8]; // [esp+Ch] [ebp-40h] BYREF
  int nVolumes[8]; // [esp+2Ch] [ebp-20h] BYREF

  m_pHBINK = this->m_pHBINK;
  nMixBins[0] = 0;
  nMixBins[1] = 1;
  nMixBins[2] = 2;
  nMixBins[3] = 3;
  nMixBins[4] = 4;
  nMixBins[5] = 5;
  nMixBins[6] = 6;
  nMixBins[7] = 7;
  memset(&nVolumes[2], 0, 24);
  nVolumes[0] = 0x8000;
  nVolumes[1] = 0x8000;
  BinkSetMixBinVolumes(a1: m_pHBINK, a2: 0, a3: nMixBins, a4: nVolumes, a5: 8);
  v2 = this->m_pHBINK;
  memset(&nVolumes[3], 0, 20);
  *(_QWORD *)nVolumes = 0;
  nVolumes[2] = 0x8000;
  BinkSetMixBinVolumes(a1: v2, a2: 1, a3: nMixBins, a4: nVolumes, a5: 8);
  v3 = this->m_pHBINK;
  memset(nVolumes, 0, 12);
  memset(&nVolumes[4], 0, 16);
  nVolumes[3] = 0x8000;
  BinkSetMixBinVolumes(a1: v3, a2: 2, a3: nMixBins, a4: nVolumes, a5: 8);
  v5 = this->m_pHBINK;
  memset(nVolumes, 0, 16);
  nVolumes[4] = 0x8000;
  nVolumes[5] = 0x8000;
  nVolumes[6] = 0x8000;
  nVolumes[7] = 0x8000;
  BinkSetMixBinVolumes(a1: v5, a2: 3, a3: nMixBins, a4: nVolumes, a5: 8);
}

//------------------------------------------------------------------------------
// Address: 0x100036D0
// Name: public: void CBIKMaterial::UpdateVolume(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::UpdateVolume(CBIKMaterial *this)
{
  float v2; // xmm0_4
  BINK *m_pHBINK; // eax
  int i; // esi
  int TrackID; // eax

  if ( this->m_pHBINK != nullptr && (this->m_nBinkFlags & 4) == 0 )
  {
    if ( (_S2 & 1) == 0 )
    {
      _S2 |= 1u;
      ConVarRef::ConVarRef(this: &volumeConVar, pName: "volume");
    }
    if ( (_S2 & 2) == 0 )
    {
      _S2 |= 2u;
      ConVarRef::ConVarRef(this: &movieVolumeScaleConVar, pName: "movie_volume_scale");
    }
    v2 = (float)(movieVolumeScaleConVar.m_pConVarState->m_Value.m_fValue * volumeConVar.m_pConVarState->m_Value.m_fValue)
       * 32768.0;
    if ( (_S2 & 4) == 0 )
    {
      _S2 |= 4u;
      ConVarRef::ConVarRef(this: &snd_surroundSpeakersConVarRef, pName: "snd_surround_speakers");
    }
    m_pHBINK = this->m_pHBINK;
    for ( i = 0; i != m_pHBINK->NumTracks; ++i )
    {
      TrackID = BinkGetTrackID(a1: m_pHBINK, a2: i);
      BinkSetVolume(a1: this->m_pHBINK, a2: TrackID, a3: (int)v2);
      m_pHBINK = this->m_pHBINK;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100037C0
// Name: private: void CBIKMaterial::CreateProceduralTextures(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::CreateProceduralTextures(CBIKMaterial *this, const char *pTextureName)
{
  int v3; // ebx
  int v4; // edi
  char textureName[260]; // [esp+Ch] [ebp-104h] BYREF

  V_strncpy(pDest: textureName, pSrc: pTextureName, maxLen: 259);
  V_StripExtension(in: textureName, out: textureName, outSize: 260);
  V_strncat(pDest: textureName, pSrc: "Y", destBufferSize: 0x104u, max_chars_to_copy: -1);
  CTextureReference::InitProceduralTexture(
    this: &this->m_TextureY,
    pTextureName: textureName,
    pTextureGroupName: "bik",
    w: this->m_nBIKWidth,
    h: this->m_nBIKHeight,
    fmt: IMAGE_FORMAT_I8,
    nFlags: 264972);
  this->m_TextureY.m_pTexture->SetTextureRegenerator(
    this: this->m_TextureY.m_pTexture,
    a2: &this->m_YTextureRegenerator,
    a3: true);
  V_strncpy(pDest: textureName, pSrc: pTextureName, maxLen: 259);
  V_StripExtension(in: textureName, out: textureName, outSize: 260);
  V_strncat(pDest: textureName, pSrc: "Cr", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v3 = this->m_nBIKHeight >> 1;
  v4 = this->m_nBIKWidth >> 1;
  CTextureReference::InitProceduralTexture(
    this: &this->m_TextureCr,
    pTextureName: textureName,
    pTextureGroupName: "bik",
    w: v4,
    h: v3,
    fmt: IMAGE_FORMAT_I8,
    nFlags: 264972);
  this->m_TextureCr.m_pTexture->SetTextureRegenerator(
    this: this->m_TextureCr.m_pTexture,
    a2: &this->m_CrTextureRegenerator,
    a3: true);
  V_strncpy(pDest: textureName, pSrc: pTextureName, maxLen: 259);
  V_StripExtension(in: textureName, out: textureName, outSize: 260);
  V_strncat(pDest: textureName, pSrc: "Cb", destBufferSize: 0x104u, max_chars_to_copy: -1);
  CTextureReference::InitProceduralTexture(
    this: &this->m_TextureCb,
    pTextureName: textureName,
    pTextureGroupName: "bik",
    w: v4,
    h: v3,
    fmt: IMAGE_FORMAT_I8,
    nFlags: 264972);
  this->m_TextureCb.m_pTexture->SetTextureRegenerator(
    this: this->m_TextureCb.m_pTexture,
    a2: &this->m_CbTextureRegenerator,
    a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10003950
// Name: private: void CBIKMaterial::DestroyProceduralTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::DestroyProceduralTextures(CBIKMaterial *this)
{
  ITexture *m_pTexture; // ecx
  ITexture *v3; // ecx
  ITexture *v4; // ecx

  m_pTexture = this->m_TextureY.m_pTexture;
  if ( m_pTexture != nullptr )
  {
    m_pTexture->SetTextureRegenerator(this: m_pTexture, a2: nullptr, a3: true);
    CTextureReference::Shutdown(this: &this->m_TextureY, bDeleteIfUnReferenced: true);
  }
  v3 = this->m_TextureCr.m_pTexture;
  if ( v3 != nullptr )
  {
    v3->SetTextureRegenerator(this: v3, a2: nullptr, a3: true);
    CTextureReference::Shutdown(this: &this->m_TextureCr, bDeleteIfUnReferenced: true);
  }
  v4 = this->m_TextureCb.m_pTexture;
  if ( v4 != nullptr )
  {
    v4->SetTextureRegenerator(this: v4, a2: nullptr, a3: true);
    CTextureReference::Shutdown(this: &this->m_TextureCb, bDeleteIfUnReferenced: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100039B0
// Name: private: void CBIKMaterial::CreateVideoStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::CreateVideoStream(CBIKMaterial *this)
{
  BINKFRAMEBUFFERS *p_m_buffers; // ebx
  unsigned int *p_BufferPitch; // edi
  unsigned int v4; // eax
  void *v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  void *v11; // eax
  unsigned int v12; // ecx
  int i; // [esp+8h] [ebp-4h]

  p_m_buffers = &this->m_buffers;
  BinkGetFrameBuffersInfo(a1: this->m_pHBINK, a2: &this->m_buffers);
  i = 0;
  if ( p_m_buffers->TotalFrames > 0 )
  {
    p_BufferPitch = &this->m_buffers.Frames[0].YPlane.BufferPitch;
    do
    {
      if ( *(p_BufferPitch - 2) != 0 )
      {
        v4 = (this->m_buffers.YABufferWidth + 15) & 0xFFFFFFF0;
        *p_BufferPitch = v4;
        v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4 * this->m_buffers.YABufferHeight + 19);
        if ( v5 != nullptr )
        {
          v6 = ((unsigned int)v5 + 19) & 0xFFFFFFF0;
          *(_DWORD *)(v6 - 4) = v5;
        }
        else
        {
          v6 = 0;
        }
        *(p_BufferPitch - 1) = v6;
      }
      if ( p_BufferPitch[1] != 0 )
      {
        v7 = (this->m_buffers.cRcBBufferWidth + 15) & 0xFFFFFFF0;
        p_BufferPitch[3] = v7;
        v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 * this->m_buffers.cRcBBufferHeight + 19);
        if ( v8 != nullptr )
        {
          v9 = ((unsigned int)v8 + 19) & 0xFFFFFFF0;
          *(_DWORD *)(v9 - 4) = v8;
        }
        else
        {
          v9 = 0;
        }
        p_BufferPitch[2] = v9;
      }
      if ( p_BufferPitch[4] != 0 )
      {
        v10 = (this->m_buffers.cRcBBufferWidth + 15) & 0xFFFFFFF0;
        p_BufferPitch[6] = v10;
        v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v10 * this->m_buffers.cRcBBufferHeight + 19);
        if ( v11 != nullptr )
        {
          v12 = ((unsigned int)v11 + 19) & 0xFFFFFFF0;
          *(_DWORD *)(v12 - 4) = v11;
        }
        else
        {
          v12 = 0;
        }
        p_BufferPitch[5] = v12;
      }
      p_m_buffers = &this->m_buffers;
      p_BufferPitch += 12;
      ++i;
    }
    while ( i < this->m_buffers.TotalFrames );
  }
  BinkRegisterFrameBuffers(a1: this->m_pHBINK, a2: p_m_buffers);
}

//------------------------------------------------------------------------------
// Address: 0x10003AD0
// Name: private: void CBIKMaterial::DestroyVideoStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::DestroyVideoStream(CBIKMaterial *this)
{
  int v1; // ebx
  void **p_Buffer; // esi
  unsigned int v3; // eax
  unsigned int v4; // eax

  v1 = 0;
  if ( this->m_buffers.TotalFrames > 0 )
  {
    p_Buffer = &this->m_buffers.Frames[0].YPlane.Buffer;
    do
    {
      if ( *(p_Buffer - 1) != nullptr && *p_Buffer != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)*p_Buffer & 0xFFFFFFFC) - 4));
        *p_Buffer = nullptr;
      }
      if ( p_Buffer[2] != nullptr )
      {
        v3 = (unsigned int)p_Buffer[3];
        if ( v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((v3 & 0xFFFFFFFC) - 4));
          p_Buffer[3] = nullptr;
        }
      }
      if ( p_Buffer[5] != nullptr )
      {
        v4 = (unsigned int)p_Buffer[6];
        if ( v4 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((v4 & 0xFFFFFFFC) - 4));
          p_Buffer[6] = nullptr;
        }
      }
      ++v1;
      p_Buffer += 12;
    }
    while ( v1 < this->m_buffers.TotalFrames );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003B70
// Name: private: static void __near * CBik::BinkMemAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__stdcall CBik::BinkMemAlloc(unsigned int bytes)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: bytes);
}

//------------------------------------------------------------------------------
// Address: 0x10003B90
// Name: private: static void CBik::BinkMemFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CBik::BinkMemFree(void *ptr)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10003BC0
// Name: public: virtual bool CBik::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBik::Connect(CBik *this, void *(__cdecl *factory)(const char *, int *))
{
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || materials == nullptr )
    _Msg(a1: "Bik failed to connect to a required system\n");
  return g_pFullFileSystem != nullptr && materials != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003C20
// Name: public: virtual void __near * CBik::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBik *__thiscall CBik::QueryInterface(CBik *this, const char *pInterfaceName)
{
  int v3; // eax

  v3 = _V_strlen(str: "VBik001");
  return V_strncmp(s1: pInterfaceName, s2: "VBik001", count: v3 + 1) == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003C50
// Name: public: virtual enum InitReturnVal_t CBik::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBik::Init(CBik *this)
{
  BinkSetMemory(a1: CBik::BinkMemAlloc, a2: CBik::BinkMemFree);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003C70
// Name: public: virtual bool CBik::SetDirectSoundDevice(void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBik::SetDirectSoundDevice(CBik *this, void *pDevice)
{
  return BinkSetSoundSystem(a1: BinkOpenDirectSound, a2: pDevice) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003C90
// Name: public: virtual bool CBik::SetMilesSoundDevice(void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBik::SetMilesSoundDevice(CBik *this, void *pDevice)
{
  if ( pDevice != nullptr )
    return BinkSetSoundSystem(a1: BinkOpenMiles, a2: pDevice) != 0;
  else
    return BinkSetSoundSystem(a1: BinkOpenWaveOut, a2: 0) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003CD0
// Name: public: void CUtlMemory<struct PrecachedMovie_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<PrecachedMovie_t,int>::Grow(CUtlMemory<PrecachedMovie_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PrecachedMovie_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PrecachedMovie_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PrecachedMovie_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003D60
// Name: public: bool CBIKMaterial::IsVideoFinished(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBIKMaterial::IsVideoFinished(CBIKMaterial *this)
{
  CThreadFastMutex *p_m_BinkFrameCountMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool result; // al

  p_m_BinkFrameCountMutex = &this->m_BinkFrameCountMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkFrameCountMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkFrameCountMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkFrameCountMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkFrameCountMutex->m_depth;
  }
  result = this->m_bShutdown || this->m_nCurrentFrame == this->m_nFrameCount && !this->m_bLoops;
  if ( p_m_BinkFrameCountMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkFrameCountMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003DE0
// Name: private: void CBIKMaterial::UpdateCurrentFrameIndex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::UpdateCurrentFrameIndex(CBIKMaterial *this)
{
  CThreadFastMutex *p_m_BinkUpdateMutex; // edi
  DWORD CurrentThreadId; // ecx
  CThreadFastMutex *p_m_BinkFrameCountMutex; // esi
  DWORD v5; // eax
  bool v6; // zf

  p_m_BinkUpdateMutex = &this->m_BinkUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkUpdateMutex->m_depth;
  }
  p_m_BinkFrameCountMutex = &this->m_BinkFrameCountMutex;
  v5 = GetCurrentThreadId();
  if ( v5 != this->m_BinkFrameCountMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkFrameCountMutex, v5, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_BinkFrameCountMutex, a2: v5, a3: 0);
  }
  else
  {
    ++this->m_BinkFrameCountMutex.m_depth;
  }
  this->m_nCurrentFrame = this->m_pHBINK->FrameNum;
  v6 = this->m_BinkFrameCountMutex.m_depth-- == 1;
  if ( v6 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkFrameCountMutex, 0);
  v6 = p_m_BinkUpdateMutex->m_depth-- == 1;
  if ( v6 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10003E90
// Name: private: void CBIKMaterial::UpdateInternal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::UpdateInternal(CBIKMaterial *this)
{
  CThreadFastMutex *p_m_BinkUpdateMutex; // ebx
  DWORD CurrentThreadId; // ecx
  bool v4; // zf
  DWORD v5; // eax
  bool v6; // al
  CThreadFastMutex *generated_id_6; // [esp+10h] [ebp-4h]

  p_m_BinkUpdateMutex = &this->m_BinkUpdateMutex;
  generated_id_6 = &this->m_BinkUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkUpdateMutex->m_depth;
  }
  _InterlockedExchangeAdd(&this->m_nQueuedUpdateCount, 0xFFFFFFFF);
  if ( BinkWait(a1: this->m_pHBINK) != 0 )
  {
    v4 = p_m_BinkUpdateMutex->m_depth-- == 1;
    if ( !v4 )
      return;
    goto LABEL_26;
  }
  BinkDoFrame(a1: this->m_pHBINK);
  if ( BinkShouldSkip(a1: this->m_pHBINK) != 0 )
  {
    while ( 1 )
    {
      CBIKMaterial::UpdateCurrentFrameIndex(this);
      v5 = GetCurrentThreadId();
      if ( v5 == this->m_BinkFrameCountMutex.m_ownerID )
        goto LABEL_12;
      if ( _InterlockedCompareExchange((volatile signed __int32 *)&this->m_BinkFrameCountMutex, v5, 0) == 0 )
        break;
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_BinkFrameCountMutex, a2: v5, a3: 0);
      p_m_BinkUpdateMutex = generated_id_6;
LABEL_14:
      v6 = this->m_bShutdown || this->m_nCurrentFrame == this->m_nFrameCount && !this->m_bLoops;
      v4 = this->m_BinkFrameCountMutex.m_depth-- == 1;
      if ( v4 )
        _InterlockedExchange((volatile __int32 *)&this->m_BinkFrameCountMutex, 0);
      if ( !v6 )
      {
        BinkNextFrame(a1: this->m_pHBINK);
        BinkDoFrame(a1: this->m_pHBINK);
        if ( BinkShouldSkip(a1: this->m_pHBINK) != 0 )
          continue;
      }
      goto LABEL_23;
    }
    p_m_BinkUpdateMutex = generated_id_6;
LABEL_12:
    ++this->m_BinkFrameCountMutex.m_depth;
    goto LABEL_14;
  }
LABEL_23:
  this->m_TextureY.m_pTexture->Download(this: this->m_TextureY.m_pTexture, a2: nullptr, a3: 0);
  this->m_TextureCr.m_pTexture->Download(this: this->m_TextureCr.m_pTexture, a2: nullptr, a3: 0);
  this->m_TextureCb.m_pTexture->Download(this: this->m_TextureCb.m_pTexture, a2: nullptr, a3: 0);
  CBIKMaterial::UpdateCurrentFrameIndex(this);
  if ( !CBIKMaterial::IsVideoFinished(this) )
  {
    BinkNextFrame(a1: this->m_pHBINK);
    CBIKMaterial::UpdateCurrentFrameIndex(this);
  }
  v4 = p_m_BinkUpdateMutex->m_depth-- == 1;
  if ( v4 )
LABEL_26:
    _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10004040
// Name: public: bool CBIKMaterial::ReadyForSwap(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBIKMaterial::ReadyForSwap(CBIKMaterial *this)
{
  CThreadFastMutex *p_m_BinkUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool result; // al

  p_m_BinkUpdateMutex = &this->m_BinkUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkUpdateMutex->m_depth;
  }
  result = BinkWait(a1: this->m_pHBINK) == 0;
  if ( p_m_BinkUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100040A0
// Name: public: void CBIKMaterial::GetTexCoordRange(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::GetTexCoordRange(CBIKMaterial *this, float *pMaxU, float *pMaxV)
{
  CThreadFastMutex *p_m_BinkUpdateMutex; // edi
  DWORD CurrentThreadId; // ecx
  ITexture *m_pTexture; // ecx
  int v7; // xmm0_4
  float *v8; // ecx
  int v9; // ebx
  int v10; // eax

  p_m_BinkUpdateMutex = &this->m_BinkUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkUpdateMutex->m_depth;
  }
  m_pTexture = this->m_TextureY.m_pTexture;
  if ( m_pTexture != nullptr )
  {
    v9 = m_pTexture->GetActualWidth(this: m_pTexture);
    v10 = this->m_TextureY.m_pTexture->GetActualHeight(this: this->m_TextureY.m_pTexture);
    v7 = 0;
    if ( v9 != 0 )
      *pMaxU = (float)this->m_nBIKWidth / (float)v9;
    else
      *pMaxU = 0.0;
    if ( v10 != 0 )
    {
      *pMaxV = (float)this->m_nBIKHeight / (float)v10;
      goto LABEL_14;
    }
    v8 = pMaxV;
  }
  else
  {
    v7 = 1065353216;
    v8 = pMaxU;
    *pMaxV = 1.0;
  }
  *(_DWORD *)v8 = v7;
LABEL_14:
  if ( p_m_BinkUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10004180
// Name: private: void CBIKMaterial::CreateProceduralMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::CreateProceduralMaterial(CBIKMaterial *this, const char *pMaterialName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IBaseFileSystem *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  char vmtfilename[512]; // [esp+Ch] [ebp-200h] BYREF

  _V_strcpy(dest: vmtfilename, src: pMaterialName);
  V_SetExtension(path: vmtfilename, extension: ".vmt", pathStringLength: 512);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Bik");
  else
    v4 = nullptr;
  if ( bink_try_load_vmt.m_pParent == nullptr
    || bink_try_load_vmt.m_pParent->m_Value.m_nValue == 0
    || (g_pFullFileSystem == nullptr ? (v5 = nullptr) : (v5 = &g_pFullFileSystem->IBaseFileSystem),
        !KeyValues::LoadFromFile(
           this: v4,
           filesystem: v5,
           resourceName: vmtfilename,
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr)) )
  {
    v6 = this->m_TextureY.m_pTexture->GetName(this: this->m_TextureY.m_pTexture);
    KeyValues::SetString(this: v4, keyName: "$ytexture", value: v6);
    v7 = this->m_TextureCr.m_pTexture->GetName(this: this->m_TextureCr.m_pTexture);
    KeyValues::SetString(this: v4, keyName: "$crtexture", value: v7);
    v8 = this->m_TextureCb.m_pTexture->GetName(this: this->m_TextureCb.m_pTexture);
    KeyValues::SetString(this: v4, keyName: "$cbtexture", value: v8);
    KeyValues::SetInt(this: v4, keyName: "$nofog", value: 1);
    KeyValues::SetInt(this: v4, keyName: "$spriteorientation", value: 3);
    KeyValues::SetInt(this: v4, keyName: "$translucent", value: 1);
    KeyValues::SetInt(this: v4, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v4, keyName: "$vertexalpha", value: 1);
    KeyValues::SetInt(this: v4, keyName: "$nolod", value: 1);
    KeyValues::SetInt(this: v4, keyName: "$nomip", value: 1);
    KeyValues::SetInt(this: v4, keyName: "$nobasetexture", value: 1);
  }
  CMaterialReference::Init(this: &this->m_Material, pMaterialName, pVMTKeyValues: v4);
  this->m_Material.m_pMaterial->Refresh(this: this->m_Material.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x100042F0
// Name: private: void CBIKMaterial::SetFrameInternal(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::SetFrameInternal(CBIKMaterial *this, int nFrame)
{
  CThreadFastMutex *p_m_BinkUpdateMutex; // edi
  DWORD CurrentThreadId; // ecx
  BINK *m_pHBINK; // eax

  p_m_BinkUpdateMutex = &this->m_BinkUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkUpdateMutex->m_depth;
  }
  m_pHBINK = this->m_pHBINK;
  if ( m_pHBINK->LastFrameNum != nFrame )
  {
    BinkGoto(a1: m_pHBINK, a2: nFrame, a3: 0);
    this->m_TextureY.m_pTexture->Download(this: this->m_TextureY.m_pTexture, a2: nullptr, a3: 0);
    this->m_TextureCr.m_pTexture->Download(this: this->m_TextureCr.m_pTexture, a2: nullptr, a3: 0);
    this->m_TextureCb.m_pTexture->Download(this: this->m_TextureCb.m_pTexture, a2: nullptr, a3: 0);
  }
  CBIKMaterial::UpdateCurrentFrameIndex(this);
  if ( p_m_BinkUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10004390
// Name: public: int CBIKMaterial::GetFrame(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBIKMaterial::GetFrame(CBIKMaterial *this)
{
  CThreadFastMutex *p_m_BinkFrameCountMutex; // esi
  DWORD CurrentThreadId; // ecx
  int result; // eax

  p_m_BinkFrameCountMutex = &this->m_BinkFrameCountMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkFrameCountMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkFrameCountMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkFrameCountMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkFrameCountMutex->m_depth;
  }
  result = this->m_nCurrentFrame;
  if ( p_m_BinkFrameCountMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkFrameCountMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100043F0
// Name: public: void CBIKMaterial::Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::Pause(CBIKMaterial *this)
{
  CThreadFastMutex *p_m_BinkUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_BinkUpdateMutex = &this->m_BinkUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkUpdateMutex->m_depth;
  }
  BinkPause(a1: this->m_pHBINK, a2: 1);
  if ( p_m_BinkUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10004450
// Name: public: void CBIKMaterial::Unpause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::Unpause(CBIKMaterial *this)
{
  CThreadFastMutex *p_m_BinkUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_BinkUpdateMutex = &this->m_BinkUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkUpdateMutex->m_depth;
  }
  BinkPause(a1: this->m_pHBINK, a2: 0);
  if ( p_m_BinkUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100044B0
// Name: protected: virtual bool CRefCountServiceBase<1,class CRefMT>::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRefCountServiceBase<1,CRefMT>::OnFinalRelease(ConCommand *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100044C0
// Name: public: virtual void CFunctor1<void (*)(class CBIKMaterial __near *),class CBIKMaterial __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor1<void (__cdecl *)(CBIKMaterial *),CBIKMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor1<void (__cdecl*)(CBIKMaterial *),CBIKMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100044E0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x100044F0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004520
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CBIKMaterial __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *m_pMemory; // edx
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                this: _g_pMemAlloc,
                                                                                a2: m_pMemory,
                                                                                a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                this: _g_pMemAlloc,
                                                                                a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100045D0
// Name: public: CBIKMaterial::CBIKMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CBIKMaterial *__thiscall CBIKMaterial::CBIKMaterial(CBIKMaterial *this)
{
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_TextureY);
  CTextureReference::CTextureReference(this: &this->m_TextureCr);
  CTextureReference::CTextureReference(this: &this->m_TextureCb);
  this->m_YTextureRegenerator.__vftable = (CBIKMaterialYTextureRegenerator_vtbl *)&CBIKMaterialYTextureRegenerator::`vftable';
  this->m_CrTextureRegenerator.__vftable = (CBIKMaterialCrTextureRegenerator_vtbl *)&CBIKMaterialCrTextureRegenerator::`vftable';
  this->m_CbTextureRegenerator.__vftable = (CBIKMaterialCbTextureRegenerator_vtbl *)&CBIKMaterialCbTextureRegenerator::`vftable';
  this->m_BinkUpdateMutex.m_ownerID = 0;
  this->m_BinkUpdateMutex.m_depth = 0;
  this->m_BinkFrameCountMutex.m_ownerID = 0;
  this->m_BinkFrameCountMutex.m_depth = 0;
  this->m_pHBINK = nullptr;
  _V_memset(dest: &this->m_buffers, fill: 0, count: 120);
  this->m_nQueuedUpdateCount = 0;
  *(_WORD *)&this->m_bLoops = 0;
  this->m_pScratchTexture = nullptr;
  this->m_nBinkFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004660
// Name: public: bool CBIKMaterial::Init(char const __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBIKMaterial::Init(
        CBIKMaterial *this,
        const char *pMaterialName,
        const char *pFileName,
        const char *pPathID,
        char flags)
{
  char v7; // bl
  unsigned int v8; // edi
  char *v9; // eax
  BINK *v10; // eax
  BINK *m_pHBINK; // edi
  int m_nBIKHeight; // eax
  int v13; // eax
  int v14; // eax
  char pFullBIKFileName[512]; // [esp+8h] [ebp-414h] BYREF
  char pBIKFileName[512]; // [esp+208h] [ebp-214h] BYREF
  unsigned int TrackIDsToPlay[5]; // [esp+408h] [ebp-14h] BYREF

  V_snprintf(pDest: pBIKFileName, maxLen: 512, pFormat: "%s", pFileName);
  V_DefaultExtension(path: pBIKFileName, extension: ".bik", pathStringLength: 512);
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    ConVarRef::ConVarRef(this: &stru_1001F334, pName: "force_audio_english");
  }
  if ( ((int (__stdcall *)(char *, const char *, char *, int, int, const char **))g_pFullFileSystem->RelativePathToFullPath)(
         a1: pBIKFileName,
         a2: pPathID,
         a3: pFullBIKFileName,
         a4: 512,
         a5: stru_1001F334.m_pConVarState->m_Value.m_nValue != 0 ? 4 : 1,
         a6: &pFileName) == 0 )
    return 0;
  v7 = flags;
  v8 = 17408;
  if ( (flags & 2) != 0 )
    v8 = 25600;
  if ( (flags & 4) != 0 )
  {
    BinkSetSoundTrack(a1: 0, a2: 0);
  }
  else
  {
    TrackIDsToPlay[0] = 0;
    TrackIDsToPlay[1] = 1;
    TrackIDsToPlay[2] = 2;
    TrackIDsToPlay[3] = 3;
    TrackIDsToPlay[4] = 4;
    BinkSetSoundTrack(a1: 5, a2: TrackIDsToPlay);
  }
  v9 = (char *)g_pBIK->GetPrecachedMovie(this: g_pBIK, a2: pFullBIKFileName);
  if ( v9 != nullptr )
    v8 = v8 & 0xFBFFDFFF | 0x4000000;
  this->m_nBinkFlags = v8;
  if ( v9 == nullptr )
    v9 = pFullBIKFileName;
  v10 = (BINK *)BinkOpen(a1: v9, a2: v8);
  this->m_pHBINK = v10;
  if ( v10 != nullptr )
  {
    CBIKMaterial::SetTracks(this);
    m_pHBINK = this->m_pHBINK;
    this->m_nBIKWidth = m_pHBINK->Width;
    this->m_nBIKHeight = m_pHBINK->Height;
    this->m_nFrameRate = (int)((double)m_pHBINK->FrameRate / (double)m_pHBINK->FrameRateDiv);
    this->m_nFrameCount = m_pHBINK->Frames;
    this->m_nCurrentFrame = 0;
    CBIKMaterial::CreateVideoStream(this);
    m_nBIKHeight = this->m_nBIKHeight;
    this->m_YTextureRegenerator.m_nSourceWidth = this->m_nBIKWidth;
    this->m_YTextureRegenerator.m_nSourceHeight = m_nBIKHeight;
    this->m_YTextureRegenerator.m_pBIKMaterial = this;
    v13 = this->m_nBIKHeight;
    this->m_CrTextureRegenerator.m_nSourceWidth = this->m_nBIKWidth >> 1;
    this->m_CrTextureRegenerator.m_nSourceHeight = v13 >> 1;
    this->m_CrTextureRegenerator.m_pBIKMaterial = this;
    v14 = this->m_nBIKHeight >> 1;
    this->m_CbTextureRegenerator.m_nSourceWidth = this->m_nBIKWidth >> 1;
    this->m_CbTextureRegenerator.m_pBIKMaterial = this;
    this->m_CbTextureRegenerator.m_nSourceHeight = v14;
    CBIKMaterial::CreateProceduralTextures(this, pTextureName: pMaterialName);
    CBIKMaterial::CreateProceduralMaterial(this, pMaterialName);
    this->m_bLoops = v7 & 1;
    CBIKMaterial::UpdateVolume(this);
    return 1;
  }
  else
  {
    this->m_nBIKWidth = 64;
    this->m_nBIKHeight = 64;
    this->m_nFrameRate = 1;
    this->m_nFrameCount = 1;
    CMaterialReference::Init(
      this: &this->m_Material,
      pMaterialName: "debug/debugempty",
      pTextureGroupName: "Other textures",
      bComplain: true);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100048D0
// Name: ShutdownAndDeleteBinkMaterial
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShutdownAndDeleteBinkMaterial(CBIKMaterial *pBIK)
{
  if ( !CBIKMaterial::Shutdown(this: pBIK) && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
    __debugbreak();
  if ( pBIK != nullptr )
  {
    CTextureReference::~CTextureReference(this: &pBIK->m_TextureCb);
    CTextureReference::~CTextureReference(this: &pBIK->m_TextureCr);
    CTextureReference::~CTextureReference(this: &pBIK->m_TextureY);
    CMaterialReference::~CMaterialReference(this: &pBIK->m_Material);
    free(pMem: pBIK);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004920
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class IBik>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IBik>::GetTier(CBaseAppSystem<IBik> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10004930
// Name: public: virtual void CBaseAppSystem<class IAvi>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IAvi>::Reconnect(
        CBaseAppSystem<IAvi> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10004950
// Name: public: virtual bool CBik::ReadyForSwap(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBik::ReadyForSwap(CBik *this, unsigned __int16 hMaterial)
{
  return hMaterial == 0xFFFF
      || CBIKMaterial::ReadyForSwap(this: this->m_BIKMaterials.m_Memory.m_pMemory[hMaterial].m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x10004980
// Name: public: virtual class IMaterial __near * CBik::GetMaterial(unsigned short)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CBik::GetMaterial(CBik *this, unsigned __int16 h)
{
  if ( h == 0xFFFF )
    return nullptr;
  else
    return this->m_BIKMaterials.m_Memory.m_pMemory[h].m_Element->m_Material.m_pMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x100049B0
// Name: public: virtual void CBik::GetTexCoordRange(unsigned short,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::GetTexCoordRange(CBik *this, unsigned __int16 h, float *pMaxU, float *pMaxV)
{
  if ( h == 0xFFFF )
  {
    *pMaxV = 1.0;
    *pMaxU = 1.0;
  }
  else
  {
    CBIKMaterial::GetTexCoordRange(this: this->m_BIKMaterials.m_Memory.m_pMemory[h].m_Element, pMaxU, pMaxV);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004A00
// Name: public: virtual void CBik::GetFrameSize(unsigned short,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::GetFrameSize(CBik *this, unsigned __int16 h, int *pWidth, int *pHeight)
{
  if ( h == 0xFFFF )
  {
    *pHeight = 1;
    *pWidth = 1;
  }
  else
  {
    *(UtlLinkedListElem_t<CBIKMaterial *,unsigned short> *)pWidth = *(UtlLinkedListElem_t<CBIKMaterial *,unsigned short> *)&this->m_BIKMaterials.m_Memory.m_pMemory[h].m_Element->m_nBIKWidth;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004A50
// Name: public: virtual int CBik::GetFrameRate(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBik::GetFrameRate(CBik *this, unsigned __int16 h)
{
  if ( h == 0xFFFF )
    return -1;
  else
    return this->m_BIKMaterials.m_Memory.m_pMemory[h].m_Element->m_nFrameRate;
}

//------------------------------------------------------------------------------
// Address: 0x10004A80
// Name: public: virtual int CBik::GetFrameCount(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBik::GetFrameCount(CBik *this, unsigned __int16 h)
{
  if ( h == 0xFFFF )
    return -1;
  else
    return this->m_BIKMaterials.m_Memory.m_pMemory[h].m_Element->m_nFrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x10004AB0
// Name: public: virtual int CBik::GetFrame(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBik::GetFrame(CBik *this, unsigned __int16 hMaterial)
{
  if ( hMaterial == 0xFFFF )
    return -1;
  else
    return CBIKMaterial::GetFrame(this: this->m_BIKMaterials.m_Memory.m_pMemory[hMaterial].m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x10004AE0
// Name: public: virtual void CBik::Pause(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::Pause(CBik *this, unsigned __int16 hMaterial)
{
  if ( hMaterial != 0xFFFF )
    CBIKMaterial::Pause(this: this->m_BIKMaterials.m_Memory.m_pMemory[hMaterial].m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x10004B10
// Name: public: virtual void CBik::Unpause(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::Unpause(CBik *this, unsigned __int16 hMaterial)
{
  if ( hMaterial != 0xFFFF )
    CBIKMaterial::Unpause(this: this->m_BIKMaterials.m_Memory.m_pMemory[hMaterial].m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x10004B40
// Name: public: virtual void __near * CBik::GetPrecachedMovie(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CBik::GetPrecachedMovie(CBik *this, const char *pFileName)
{
  int v3; // edi
  int i; // ebx
  const char *v5; // eax
  const char *pBaseName; // [esp+14h] [ebp+8h]

  v3 = 0;
  pBaseName = V_UnqualifiedFileName(in: pFileName);
  if ( this->m_PrecachedMovies.m_Size <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::Get(this: &this->m_PrecachedMovies.m_Memory.m_pMemory[i].m_BaseName);
    if ( _V_stricmp(s1: v5, s2: pBaseName) == 0 )
      break;
    if ( ++v3 >= this->m_PrecachedMovies.m_Size )
      return nullptr;
  }
  return this->m_PrecachedMovies.m_Memory.m_pMemory[v3].m_MemoryBuffer.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10004BA0
// Name: public: virtual void CBik::UpdateVolume(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::UpdateVolume(CBik *this, unsigned __int16 hMaterial)
{
  if ( hMaterial != 0xFFFF )
    CBIKMaterial::UpdateVolume(this: this->m_BIKMaterials.m_Memory.m_pMemory[hMaterial].m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x10004BD0
// Name: public: virtual bool CBik::IsMovieResidentInMemory(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBik::IsMovieResidentInMemory(CBik *this, unsigned __int16 hMaterial)
{
  CBIKMaterial *m_Element; // eax

  return hMaterial != 0xFFFF
      && (m_Element = this->m_BIKMaterials.m_Memory.m_pMemory[hMaterial].m_Element)->m_pHBINK != nullptr
      && (m_Element->m_nBinkFlags & 0x4002000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004C10
// Name: public: void CBik::DumpPrecachedMovieList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::DumpPrecachedMovieList(CBik *this)
{
  int v2; // esi
  int v3; // ebx
  PrecachedMovie_t *m_pMemory; // ecx
  const char *v5; // eax
  int m_nAllocationCount; // [esp-8h] [ebp-10h]

  _Msg(a1: "-- %d precached bink movies -- \n", this->m_PrecachedMovies.m_Size);
  v2 = 0;
  if ( this->m_PrecachedMovies.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      m_pMemory = this->m_PrecachedMovies.m_Memory.m_pMemory;
      m_nAllocationCount = m_pMemory[v3].m_MemoryBuffer.m_Memory.m_nAllocationCount;
      v5 = CUtlString::Get(this: &m_pMemory[v3].m_BaseName);
      _Msg(a1: "%d: %s, %d bytes\n", v2++, v5, m_nAllocationCount);
      ++v3;
    }
    while ( v2 < this->m_PrecachedMovies.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004C60
// Name: bink_dump_precached_movies
// Source: json
//------------------------------------------------------------------------------
void __cdecl bink_dump_precached_movies()
{
  CBik::DumpPrecachedMovieList(this: &g_BIK);
}

//------------------------------------------------------------------------------
// Address: 0x10004C70
// Name: public: virtual void CMemberFunctor0<class CBIKMaterial __near *,void (CBIKMaterial::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CBIKMaterial *,void (__thiscall CBIKMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CBIKMaterial *,void (__thiscall CBIKMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10004C80
// Name: public: virtual void CMemberFunctor1<class CBIKMaterial __near *,void (CBIKMaterial::*)(int),unsigned int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CBIKMaterial *,void (__thiscall CBIKMaterial::*)(int),unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CBIKMaterial *,void (__thiscall CBIKMaterial::*)(int),unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10004CC0
// Name: protected: unsigned short CUtlLinkedList<class CBIKMaterial __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CBIKMaterial __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CBIKMaterial *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10004E40
// Name: public: void ICallQueue::QueueCall<void,class CBIKMaterial __near *,class CBIKMaterial __near *>(void (*)(class CBIKMaterial __near *),class CBIKMaterial __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,CBIKMaterial *,CBIKMaterial *>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(CBIKMaterial *),
        CBIKMaterial *const *arg1)
{
  CFunctor *v4; // eax

  v4 = (CFunctor *)operator new(nSize: 0x18u);
  if ( v4 != nullptr )
  {
    v4[1].m_nUserID = 1;
    v4[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v4->__vftable = (CFunctor_vtbl *)&CFunctor1<void (__cdecl *)(CBIKMaterial *),CBIKMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CFunctor1<void (__cdecl *)(CBIKMaterial *),CBIKMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].m_nUserID = (unsigned int)*arg1;
    this->QueueFunctorInternal(this, a2: v4);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004EA0
// Name: public: void CUtlLinkedList<class CBIKMaterial __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CBIKMaterial __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004F10
// Name: public: bool CBIKMaterial::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBIKMaterial::Shutdown(CBIKMaterial *this)
{
  CThreadFastMutex *p_m_BinkUpdateMutex; // ebx
  DWORD CurrentThreadId; // ecx
  IMatRenderContext *v4; // edi
  ICallQueue *(__thiscall *GetCallQueue)(IMatRenderContext *); // eax
  ICallQueue *v6; // eax
  bool v7; // zf
  CBIKMaterial *arg1; // [esp+Ch] [ebp-4h] BYREF

  this->m_bShutdown = true;
  p_m_BinkUpdateMutex = &this->m_BinkUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkUpdateMutex->m_depth;
  }
  if ( this->m_nQueuedUpdateCount != 0 )
  {
    v4 = materials->GetRenderContext(this: materials);
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    if ( v4->GetCallQueue(this: v4) != nullptr )
    {
      GetCallQueue = v4->GetCallQueue;
      arg1 = this;
      v6 = GetCallQueue(this: v4);
      ICallQueue::QueueCall<void,CBIKMaterial *,CBIKMaterial *>(
        this: v6,
        pfnProxied: ShutdownAndDeleteBinkMaterial,
        &arg1);
      v4->EndRender(this: v4);
      v4->Release(this: v4);
      v7 = p_m_BinkUpdateMutex->m_depth-- == 1;
      if ( v7 )
        _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
      return 0;
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
  CBIKMaterial::DestroyVideoStream(this);
  CMaterialReference::Shutdown(this: &this->m_Material, bDeleteIfUnreferenced: true);
  CBIKMaterial::DestroyProceduralTextures(this);
  if ( this->m_pHBINK != nullptr )
  {
    BinkClose(a1: this->m_pHBINK);
    this->m_pHBINK = nullptr;
  }
  v7 = p_m_BinkUpdateMutex->m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005030
// Name: public: void ICallQueue::QueueCall<class CBIKMaterial __near *,class CBIKMaterial,void>(class CBIKMaterial __near *,void (CBIKMaterial::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CBIKMaterial *,CBIKMaterial,void>(
        ICallQueue *this,
        CBIKMaterial *pObject,
        void (__thiscall *pfnProxied)(CBIKMaterial *this))
{
  CFunctor *v4; // eax

  v4 = (CFunctor *)operator new(nSize: 0x18u);
  if ( v4 != nullptr )
  {
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CBIKMaterial *,void (__thiscall CBIKMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CBIKMaterial *,void (__thiscall CBIKMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v4[2].m_nUserID = (unsigned int)pObject;
    this->QueueFunctorInternal(this, a2: v4);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005090
// Name: public: void ICallQueue::QueueCall<class CBIKMaterial __near *,class CBIKMaterial,void,int,unsigned int>(class CBIKMaterial __near *,void (CBIKMaterial::*)(int),unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CBIKMaterial *,CBIKMaterial,void,int,unsigned int>(
        ICallQueue *this,
        CBIKMaterial *pObject,
        void (__thiscall *pfnProxied)(CBIKMaterial *this, int),
        CFunctor_vtbl **arg1)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)operator new(nSize: 0x1Cu);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CBIKMaterial *,void (__thiscall CBIKMaterial::*)(int),unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CBIKMaterial *,void (__thiscall CBIKMaterial::*)(int),unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5[2].m_nUserID = (unsigned int)pObject;
    v5[3].__vftable = *arg1;
    this->QueueFunctorInternal(this, a2: v5);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100050F0
// Name: public: bool CBIKMaterial::Update(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBIKMaterial::Update(CBIKMaterial *this)
{
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  ICallQueue *v5; // eax

  if ( CBIKMaterial::IsVideoFinished(this) )
    return 0;
  _InterlockedExchangeAdd(&this->m_nQueuedUpdateCount, 1u);
  v3 = materials->GetRenderContext(this: materials);
  v4 = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( v4->GetCallQueue(this: v4) != nullptr
    && bink_mat_queue_mode.m_pParent != nullptr
    && bink_mat_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    v5 = v4->GetCallQueue(this: v4);
    ICallQueue::QueueCall<CBIKMaterial *,CBIKMaterial,void>(
      this: v5,
      pObject: this,
      pfnProxied: CBIKMaterial::UpdateInternal);
LABEL_9:
    v4->EndRender(this: v4);
    v4->Release(this: v4);
    return 1;
  }
  CBIKMaterial::UpdateInternal(this);
  if ( !CBIKMaterial::IsVideoFinished(this) )
    goto LABEL_9;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100051B0
// Name: public: void CBIKMaterial::SetFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBIKMaterial::SetFrame(CBIKMaterial *this, float flFrame)
{
  CThreadFastMutex *p_m_BinkUpdateMutex; // edi
  DWORD CurrentThreadId; // ecx
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v5; // esi
  ICallQueue *v6; // eax
  CBIKMaterial *v8; // [esp-Ch] [ebp-24h]
  unsigned int arg1[2]; // [esp+Ch] [ebp-Ch] BYREF
  CBIKMaterial *pObject; // [esp+14h] [ebp-4h]

  pObject = this;
  p_m_BinkUpdateMutex = &this->m_BinkUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BinkUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BinkUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BinkUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BinkUpdateMutex->m_depth;
  }
  arg1[1] = HIWORD(flFrame) | 0xC00;
  GetRenderContext = materials->GetRenderContext;
  arg1[1] = (__int64)flFrame + 1;
  v5 = (int)GetRenderContext(this: materials);
  if ( v5 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 564))(a1: v5) != 0
    && bink_mat_queue_mode.m_pParent != nullptr
    && bink_mat_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    v8 = pObject;
    v6 = (ICallQueue *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 564))(a1: v5);
    ICallQueue::QueueCall<CBIKMaterial *,CBIKMaterial,void,int,unsigned int>(
      this: v6,
      pObject: v8,
      pfnProxied: CBIKMaterial::SetFrameInternal,
      arg1: (CFunctor_vtbl **)&arg1[1]);
  }
  else
  {
    CBIKMaterial::SetFrameInternal(this: pObject, nFrame: (__int64)flFrame + 1);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  if ( p_m_BinkUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_BinkUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100052B0
// Name: public: virtual bool CBik::Update(unsigned short)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBik::Update(CBik *this, unsigned __int16 hMaterial)
{
  if ( hMaterial == 0xFFFF )
    return 0;
  else
    return CBIKMaterial::Update(this: this->m_BIKMaterials.m_Memory.m_pMemory[hMaterial].m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x100052E0
// Name: public: virtual void CBik::SetFrame(unsigned short,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::SetFrame(CBik *this, unsigned __int16 h, float flFrame)
{
  if ( h != 0xFFFF )
    CBIKMaterial::SetFrame(this: this->m_BIKMaterials.m_Memory.m_pMemory[h].m_Element, flFrame);
}

//------------------------------------------------------------------------------
// Address: 0x10005310
// Name: public: int CUtlVector<struct PrecachedMovie_t,class CUtlMemory<struct PrecachedMovie_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>::InsertBefore(
        CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PrecachedMovie_t *m_pMemory; // ecx
  int v6; // eax
  PrecachedMovie_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<PrecachedMovie_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v6 << 6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_BaseName);
    CUtlBuffer::CUtlBuffer(this: &v7->m_MemoryBuffer, growSize: 0, initSize: 0, nFlags: 0);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10005390
// Name: public: virtual void CBik::DestroyMaterial(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::DestroyMaterial(CBik *this, unsigned __int16 h)
{
  unsigned __int16 v2; // bx
  CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *p_m_BIKMaterials; // edi
  unsigned int v4; // esi
  CAVIMaterial *m_Element; // ebx

  v2 = h;
  if ( h != 0xFFFF )
  {
    p_m_BIKMaterials = (CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *)&this->m_BIKMaterials;
    v4 = h;
    if ( CBIKMaterial::Shutdown(this: this->m_BIKMaterials.m_Memory.m_pMemory[v4].m_Element) != 0 )
    {
      m_Element = p_m_BIKMaterials->m_Memory.m_pMemory[v4].m_Element;
      if ( m_Element != nullptr )
      {
        CTextureReference::~CTextureReference(this: (CTextureReference *)&m_Element->m_pAVIFile);
        CTextureReference::~CTextureReference(this: &m_Element->m_Texture);
        CTextureReference::~CTextureReference(this: (CTextureReference *)&m_Element->m_Material);
        CMaterialReference::~CMaterialReference(this: (CMaterialReference *)m_Element);
        free(pMem: m_Element);
      }
      v2 = h;
    }
    CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::Unlink(
      this: p_m_BIKMaterials,
      elem: v2);
    p_m_BIKMaterials->m_Memory.m_pMemory[v4].m_Next = p_m_BIKMaterials->m_FirstFree;
    p_m_BIKMaterials->m_FirstFree = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005410
// Name: public: void CUtlVector<struct PrecachedMovie_t,class CUtlMemory<struct PrecachedMovie_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>::Remove(
        CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int> > *this,
        int elem)
{
  PrecachedMovie_t *v3; // esi
  bool v4; // sf

  v3 = &this->m_Memory.m_pMemory[elem];
  if ( v3->m_MemoryBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3->m_MemoryBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_MemoryBuffer.m_Memory.m_pMemory);
      v3->m_MemoryBuffer.m_Memory.m_pMemory = nullptr;
    }
    v3->m_MemoryBuffer.m_Memory.m_nAllocationCount = 0;
  }
  v4 = v3->m_BaseName.m_Storage.m_Memory.m_nGrowSize < 0;
  v3->m_BaseName.m_Storage.m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_BaseName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_BaseName.m_Storage.m_Memory.m_pMemory);
      v3->m_BaseName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v3->m_BaseName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: (this->m_Size - elem - 1) << 6);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100054B0
// Name: public: void CUtlVector<struct PrecachedMovie_t,class CUtlMemory<struct PrecachedMovie_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>::RemoveAll(
        CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  void **v3; // esi
  int v4; // [esp+4h] [ebp-8h]
  CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int> > *v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1 << 6;
    v4 = v1 << 6;
    do
    {
      v3 = (void **)((char *)&this->m_Memory.m_pMemory->m_BaseName.m_Storage.m_Memory.m_pMemory + v2);
      if ( (int)v3[6] >= 0 )
      {
        if ( v3[4] != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3[4]);
          this = v5;
          v3[4] = nullptr;
        }
        v3[5] = nullptr;
      }
      v3[3] = nullptr;
      if ( (int)v3[2] >= 0 )
      {
        if ( *v3 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *v3);
          this = v5;
          *v3 = nullptr;
        }
        v3[1] = nullptr;
      }
      --v1;
      v2 = v4 - 64;
      v4 -= 64;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005550
// Name: public: virtual unsigned short CBik::CreateMaterial(char const __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CBik::CreateMaterial(
        CBik *this,
        const char *pMaterialName,
        const char *pFileName,
        const char *pPathID,
        char flags)
{
  CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short> > *p_m_BIKMaterials; // esi
  unsigned __int16 v7; // di
  unsigned __int16 v8; // bx
  CBIKMaterial *v9; // eax
  CBIKMaterial *v10; // eax
  int v11; // edi
  CTextureReference *m_Element; // eax
  char fixedMaterialName[260]; // [esp+Ch] [ebp-104h] BYREF
  char *pMaterialNamea; // [esp+118h] [ebp+8h]

  V_strncpy(pDest: fixedMaterialName, pSrc: pMaterialName, maxLen: 260);
  V_FixSlashes(pname: fixedMaterialName, separator: 47);
  p_m_BIKMaterials = &this->m_BIKMaterials;
  v7 = CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::AllocInternal(
         this: p_m_BIKMaterials,
         multilist: false);
  if ( v7 == 0xFFFF )
  {
    v8 = -1;
  }
  else
  {
    CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *)p_m_BIKMaterials,
      before: 0xFFFFu,
      elem: v7);
    v8 = v7;
  }
  v9 = (CBIKMaterial *)operator new(nSize: 0xF0u);
  if ( v9 != nullptr )
    v10 = CBIKMaterial::CBIKMaterial(this: v9);
  else
    v10 = nullptr;
  v11 = v8;
  p_m_BIKMaterials->m_Memory.m_pMemory[v11].m_Element = v10;
  if ( CBIKMaterial::Init(
         this: p_m_BIKMaterials->m_Memory.m_pMemory[v11].m_Element,
         pMaterialName: fixedMaterialName,
         pFileName,
         pPathID,
         flags) != 0 )
  {
    ++CBik::s_nMaterialAllocation;
    return v8;
  }
  else
  {
    m_Element = (CTextureReference *)p_m_BIKMaterials->m_Memory.m_pMemory[v11].m_Element;
    pMaterialNamea = (char *)m_Element;
    if ( m_Element != nullptr )
    {
      CTextureReference::~CTextureReference(this: m_Element + 3);
      CTextureReference::~CTextureReference(this: (CTextureReference *)pMaterialNamea + 2);
      CTextureReference::~CTextureReference(this: (CTextureReference *)pMaterialNamea + 1);
      CMaterialReference::~CMaterialReference(this: (CMaterialReference *)pMaterialNamea);
      free(pMem: pMaterialNamea);
    }
    CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *)p_m_BIKMaterials,
      elem: v8);
    p_m_BIKMaterials->m_Memory.m_pMemory[v11].m_Next = p_m_BIKMaterials->m_FirstFree;
    p_m_BIKMaterials->m_FirstFree = v8;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005670
// Name: public: virtual bool CBik::PrecacheMovie(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBik::PrecacheMovie(CBik *this, const char *pFileName, const char *pPathID)
{
  int v5; // ebx
  char pFullBIKFileName[512]; // [esp+8h] [ebp-404h] BYREF
  char pBIKFileName[512]; // [esp+208h] [ebp-204h] BYREF
  unsigned int pathType; // [esp+408h] [ebp-4h] BYREF
  const char *pBaseName; // [esp+414h] [ebp+8h]

  if ( this->GetPrecachedMovie(this, a2: pFileName) != nullptr )
    return 1;
  V_snprintf(pDest: pBIKFileName, maxLen: 512, pFormat: "%s", pFileName);
  V_DefaultExtension(path: pBIKFileName, extension: ".bik", pathStringLength: 512);
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    ConVarRef::ConVarRef(this: &stru_1001F334, pName: "force_audio_english");
  }
  if ( ((int (__stdcall *)(char *, const char *, char *, int, int, unsigned int *))g_pFullFileSystem->RelativePathToFullPath)(
         a1: pBIKFileName,
         a2: pPathID,
         a3: pFullBIKFileName,
         a4: 512,
         a5: stru_1001F334.m_pConVarState->m_Value.m_nValue != 0 ? 4 : 1,
         a6: &pathType) == 0 )
    return 0;
  pBaseName = V_UnqualifiedFileName(in: pFullBIKFileName);
  v5 = CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>::InsertBefore(
         this: &this->m_PrecachedMovies,
         elem: this->m_PrecachedMovies.m_Size);
  CUtlString::operator=(this: &this->m_PrecachedMovies.m_Memory.m_pMemory[v5].m_BaseName, src: pBaseName);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pFullBIKFileName,
         a3: nullptr,
         a4: &this->m_PrecachedMovies.m_Memory.m_pMemory[v5].m_MemoryBuffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    return 1;
  }
  CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>::Remove(this: &this->m_PrecachedMovies, elem: v5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100057B0
// Name: public: virtual void CBik::EvictPrecachedMovie(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::EvictPrecachedMovie(CBik *this, const char *pFileName)
{
  int v3; // ebx
  int i; // esi
  const char *v5; // eax
  int v6; // ecx
  PrecachedMovie_t *v7; // esi
  bool v8; // sf
  const char *pBaseName; // [esp+10h] [ebp+8h]

  v3 = 0;
  pBaseName = V_UnqualifiedFileName(in: pFileName);
  if ( this->m_PrecachedMovies.m_Size > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v5 = CUtlString::Get(this: &this->m_PrecachedMovies.m_Memory.m_pMemory[i].m_BaseName);
      if ( _V_stricmp(s1: v5, s2: pBaseName) == 0 )
        break;
      if ( ++v3 >= this->m_PrecachedMovies.m_Size )
        return;
    }
    v6 = v3 << 6;
    v7 = &this->m_PrecachedMovies.m_Memory.m_pMemory[v3];
    if ( v7->m_MemoryBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v7->m_MemoryBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->m_MemoryBuffer.m_Memory.m_pMemory);
        v6 = v3 << 6;
        v7->m_MemoryBuffer.m_Memory.m_pMemory = nullptr;
      }
      v7->m_MemoryBuffer.m_Memory.m_nAllocationCount = 0;
    }
    v8 = v7->m_BaseName.m_Storage.m_Memory.m_nGrowSize < 0;
    v7->m_BaseName.m_Storage.m_nActualLength = 0;
    if ( !v8 )
    {
      if ( v7->m_BaseName.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->m_BaseName.m_Storage.m_Memory.m_pMemory);
        v6 = v3 << 6;
        v7->m_BaseName.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v7->m_BaseName.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    if ( this->m_PrecachedMovies.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: (char *)this->m_PrecachedMovies.m_Memory.m_pMemory + v6,
        src: (char *)&this->m_PrecachedMovies.m_Memory.m_pMemory[1] + v6,
        count: (this->m_PrecachedMovies.m_Size - v3 - 1) << 6);
    --this->m_PrecachedMovies.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100058A0
// Name: public: virtual void CBik::EvictAllPrecachedMovies(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBik::EvictAllPrecachedMovies(CBik *this)
{
  CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int> > *p_m_PrecachedMovies; // esi
  PrecachedMovie_t *m_pMemory; // ecx

  p_m_PrecachedMovies = &this->m_PrecachedMovies;
  CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>::RemoveAll(this: &this->m_PrecachedMovies);
  if ( p_m_PrecachedMovies->m_Memory.m_nGrowSize < 0 )
  {
    p_m_PrecachedMovies->m_pElements = p_m_PrecachedMovies->m_Memory.m_pMemory;
  }
  else
  {
    if ( p_m_PrecachedMovies->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_PrecachedMovies->m_Memory.m_pMemory);
      p_m_PrecachedMovies->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = p_m_PrecachedMovies->m_Memory.m_pMemory;
    p_m_PrecachedMovies->m_Memory.m_nAllocationCount = 0;
    p_m_PrecachedMovies->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100058F0
// Name: public: CUtlVector<struct PrecachedMovie_t,class CUtlMemory<struct PrecachedMovie_t,int>>::~CUtlVector<struct PrecachedMovie_t,class CUtlMemory<struct PrecachedMovie_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>::~CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>(
        CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int> > *this)
{
  bool v2; // sf
  PrecachedMovie_t *m_pMemory; // eax

  CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005950
// Name: public: virtual int CBik::GetGlobalMaterialAllocationNumber(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBik::GetGlobalMaterialAllocationNumber(CBik *this)
{
  return CBik::s_nMaterialAllocation;
}

//------------------------------------------------------------------------------
// Address: 0x10005A60
// Name: public: virtual void CBIKMaterialYTextureRegenerator::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBIKMaterialYTextureRegenerator::Release()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10006A40
// Name: public: void CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
        CUtlMemory<KeyValues *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  KeyValues **m_pMemory; // edx
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
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007B50
// Name: public: virtual bool CBIKMaterialCbTextureRegenerator::HasPreallocatedScratchTexture(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBIKMaterialCbTextureRegenerator::HasPreallocatedScratchTexture(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10008010
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100081E0
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100167A0
// Name: _dynamic_initializer_for__bink_mat_queue_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bink_mat_queue_mode__()
{
  ConVar::ConVar(
    this: &bink_mat_queue_mode,
    pName: "bink_mat_queue_mode",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Update bink on mat queue thread if mat_queue_mode is on (if turned off, always update bink on main thread; may cause stalls!)");
  return atexit(func: dynamic_atexit_destructor_for__bink_mat_queue_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x100167D0
// Name: _dynamic_initializer_for__bink_try_load_vmt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bink_try_load_vmt__()
{
  ConVar::ConVar(
    this: &bink_try_load_vmt,
    pName: "bink_try_load_vmt",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Try and load a VMT with the same name as the BIK file to override settings");
  return atexit(func: dynamic_atexit_destructor_for__bink_try_load_vmt__);
}

//------------------------------------------------------------------------------
// Address: 0x10016800
// Name: _dynamic_initializer_for__bink_use_preallocated_scratch_texture__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bink_use_preallocated_scratch_texture__()
{
  ConVar::ConVar(
    this: &bink_use_preallocated_scratch_texture,
    pName: "bink_use_preallocated_scratch_texture",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use a pre-allocated VTF instead of creating a new one and deleting it for every texture update. Gameconsole only.");
  return atexit(func: dynamic_atexit_destructor_for__bink_use_preallocated_scratch_texture__);
}

//------------------------------------------------------------------------------
// Address: 0x10016860
// Name: _dynamic_initializer_for__bink_dump_precached_movies_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bink_dump_precached_movies_command__()
{
  ConCommand::ConCommand(
    this: &bink_dump_precached_movies_command,
    pName: "bink_dump_precached_movies",
    callback: (void (__cdecl *)(const CCommand *))bink_dump_precached_movies,
    pHelpString: "Dumps information about all precached Bink movies",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bink_dump_precached_movies_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10016980
// Name: _dynamic_atexit_destructor_for__bink_mat_queue_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bink_mat_queue_mode__()
{
  ConVar::~ConVar(this: &bink_mat_queue_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10016990
// Name: _dynamic_atexit_destructor_for__bink_try_load_vmt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bink_try_load_vmt__()
{
  ConVar::~ConVar(this: &bink_try_load_vmt);
}

//------------------------------------------------------------------------------
// Address: 0x100169A0
// Name: _dynamic_atexit_destructor_for__bink_use_preallocated_scratch_texture__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bink_use_preallocated_scratch_texture__()
{
  ConVar::~ConVar(this: &bink_use_preallocated_scratch_texture);
}

//------------------------------------------------------------------------------
// Address: 0x100169B0
// Name: _dynamic_atexit_destructor_for__bink_dump_precached_movies_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bink_dump_precached_movies_command__()
{
  ConCommand::~ConCommand(this: &bink_dump_precached_movies_command);
}

//------------------------------------------------------------------------------
// Address: 0x10003BB0
// Name: __CreateCBikIBik_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBik *__cdecl _CreateCBikIBik_interface()
{
  return &g_BIK;
}

//------------------------------------------------------------------------------
// Address: 0x10005A62
// Name: AVIFileRelease(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
ULONG __stdcall AVIFileRelease(PAVIFILE pfile)
{
  return __imp__AVIFileRelease@4(pfile);
}

//------------------------------------------------------------------------------
// Address: 0x10005A68
// Name: AVIStreamRelease(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
ULONG __stdcall AVIStreamRelease(PAVISTREAM pavi)
{
  return __imp__AVIStreamRelease@4(pavi);
}

//------------------------------------------------------------------------------
// Address: 0x10005A6E
// Name: AVIStreamSetFormat(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AVIStreamSetFormat(PAVISTREAM pavi, LONG lPos, LPVOID lpFormat, LONG cbFormat)
{
  return __imp__AVIStreamSetFormat@16(pavi, lPos, lpFormat, cbFormat);
}

//------------------------------------------------------------------------------
// Address: 0x10005A74
// Name: AVIMakeCompressedStream(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AVIMakeCompressedStream(
        PAVISTREAM *ppsCompressed,
        PAVISTREAM ppsSource,
        AVICOMPRESSOPTIONS *lpOptions,
        CLSID *pclsidHandler)
{
  return __imp__AVIMakeCompressedStream@16(ppsCompressed, ppsSource, lpOptions, pclsidHandler);
}

//------------------------------------------------------------------------------
// Address: 0x10005A7A
// Name: AVISaveOptions(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
INT_PTR __stdcall AVISaveOptions(
        HWND hwnd,
        UINT uiFlags,
        int nStreams,
        PAVISTREAM *ppavi,
        LPAVICOMPRESSOPTIONS *plpOptions)
{
  return __imp__AVISaveOptions@20(hwnd, uiFlags, nStreams, ppavi, plpOptions);
}

//------------------------------------------------------------------------------
// Address: 0x10005A80
// Name: AVIFileCreateStreamA(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AVIFileCreateStreamA(PAVIFILE pfile, PAVISTREAM *ppavi, AVISTREAMINFOA *psi)
{
  return __imp__AVIFileCreateStreamA@12(pfile, ppavi, psi);
}

//------------------------------------------------------------------------------
// Address: 0x10005A86
// Name: AVIStreamWrite(x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AVIStreamWrite(
        PAVISTREAM pavi,
        LONG lStart,
        LONG lSamples,
        LPVOID lpBuffer,
        LONG cbBuffer,
        DWORD dwFlags,
        LONG *plSampWritten,
        LONG *plBytesWritten)
{
  return __imp__AVIStreamWrite@32(pavi, lStart, lSamples, lpBuffer, cbBuffer, dwFlags, plSampWritten, plBytesWritten);
}

//------------------------------------------------------------------------------
// Address: 0x10005A8C
// Name: AVIStreamGetFrameOpen(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
PGETFRAME __stdcall AVIStreamGetFrameOpen(PAVISTREAM pavi, LPBITMAPINFOHEADER lpbiWanted)
{
  return __imp__AVIStreamGetFrameOpen@8(pavi, lpbiWanted);
}

//------------------------------------------------------------------------------
// Address: 0x10005A92
// Name: AVIStreamStart(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
LONG __stdcall AVIStreamStart(PAVISTREAM pavi)
{
  return __imp__AVIStreamStart@4(pavi);
}

//------------------------------------------------------------------------------
// Address: 0x10005A98
// Name: AVIFileGetStream(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AVIFileGetStream(PAVIFILE pfile, PAVISTREAM *ppavi, DWORD fccType, LONG lParam)
{
  return __imp__AVIFileGetStream@16(pfile, ppavi, fccType, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10005A9E
// Name: AVIStreamGetFrameClose(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AVIStreamGetFrameClose(PGETFRAME pg)
{
  return __imp__AVIStreamGetFrameClose@4(pg);
}

//------------------------------------------------------------------------------
// Address: 0x10005AA4
// Name: AVIFileOpenA(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AVIFileOpenA(PAVIFILE *ppfile, LPCSTR szFile, UINT uMode, LPCLSID lpHandler)
{
  return __imp__AVIFileOpenA@16(ppfile, szFile, uMode, lpHandler);
}

//------------------------------------------------------------------------------
// Address: 0x10005AAA
// Name: AVIStreamLength(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
LONG __stdcall AVIStreamLength(PAVISTREAM pavi)
{
  return __imp__AVIStreamLength@4(pavi);
}

//------------------------------------------------------------------------------
// Address: 0x10005AB0
// Name: AVIFileInfoA(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AVIFileInfoA(PAVIFILE pfile, LPAVIFILEINFOA pfi, LONG lSize)
{
  return __imp__AVIFileInfoA@12(pfile, pfi, lSize);
}

//------------------------------------------------------------------------------
// Address: 0x10005AB6
// Name: AVIStreamGetFrame(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
LPVOID __stdcall AVIStreamGetFrame(PGETFRAME pg, LONG lPos)
{
  return __imp__AVIStreamGetFrame@8(pg, lPos);
}

//------------------------------------------------------------------------------
// Address: 0x10005ABC
// Name: AVIFileInit()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall AVIFileInit()
{
  __imp__AVIFileInit@0();
}

//------------------------------------------------------------------------------
// Address: 0x10005AC2
// Name: AVIFileExit()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall AVIFileExit()
{
  __imp__AVIFileExit@0();
}

//------------------------------------------------------------------------------
// Address: 0x10016830
// Name: _dynamic_initializer_for__g_BIK__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BIK__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BIK__);
}

//------------------------------------------------------------------------------
// Address: 0x10016840
// Name: _dynamic_initializer_for____g_CreateCBikIBik_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCBikIBik_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCBikIBik_reg,
           fn: (void *(__cdecl *)())_CreateCBikIBik_interface,
           pName: "VBik001");
}

//------------------------------------------------------------------------------
// Address: 0x10016890
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CTextureReference::CTextureReference(this: (CTextureReference *)&g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x100168B0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100168C0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x100168E0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016940
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016970
// Name: _dynamic_atexit_destructor_for__g_AVI__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AVI__()
{
  CAvi::~CAvi(this: &g_AVI);
}

//------------------------------------------------------------------------------
// Address: 0x100169C0
// Name: _dynamic_atexit_destructor_for__g_BIK__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BIK__()
{
  CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>::~CUtlVector<PrecachedMovie_t,CUtlMemory<PrecachedMovie_t,int>>(this: &g_BIK.m_PrecachedMovies);
  CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *)&g_BIK.m_BIKMaterials);
  if ( g_BIK.m_BIKMaterials.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_BIK.m_BIKMaterials.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_BIK.m_BIKMaterials.m_Memory.m_pMemory);
      g_BIK.m_BIKMaterials.m_Memory.m_pMemory = nullptr;
    }
    g_BIK.m_BIKMaterials.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016A10
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x10016A20
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}
