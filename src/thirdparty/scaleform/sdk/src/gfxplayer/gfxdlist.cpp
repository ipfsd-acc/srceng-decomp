// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxdlist.cpp
// Functions: 21
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxdlist.h"

//------------------------------------------------------------------------------
// Address: 0x1008AB80
// Name: public: int GFxDisplayList::GetLargestDepthInUse(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayList::GetLargestDepthInUse(
        CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1008ABA0
// Name: public: class GFxASCharacter __near * GFxDisplayList::GetCharacterByName(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
__vc_attributes::pointer_defaultAttribute::type_e __thiscall GFxDisplayList::GetCharacterByName(
        CMemberFuncProxy0<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *this,
        unsigned int psc,
        int **a3)
{
  int *v4; // ecx
  _DWORD *m_pfnProxied_high; // esi
  int v7; // eax
  unsigned int v8; // ebx
  int v9; // edi
  int v10; // esi
  int v11; // eax
  _DWORD *v12; // esi
  int v13; // eax
  int **v14; // esi
  unsigned int v15; // eax
  int v16; // ebx
  __vc_attributes::pointer_defaultAttribute::type_e v17; // edi
  int v18; // eax
  int **v19; // esi
  CMemberFuncProxy0<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *v20; // [esp+8h] [ebp-8h]
  __vc_attributes::pointer_defaultAttribute pch; // [esp+Ch] [ebp-4h]
  unsigned int n; // [esp+18h] [ebp+8h]

  v4 = *a3;
  v20 = this;
  if ( (*a3)[4] == 0 )
    return ptr;
  pch.type = ptr;
  if ( *(_BYTE *)(psc + 4) > 6u )
  {
    m_pfnProxied_high = (_DWORD *)HIDWORD(this->m_pfnProxied);
    if ( m_pfnProxied_high != nullptr )
    {
      v7 = m_pfnProxied_high[37];
      if ( v7 == 0 )
      {
        GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)HIDWORD(this->m_pfnProxied));
        if ( v7 == 0 )
          v7 = *(_DWORD *)((*(int (__thiscall **)(_DWORD *))(*m_pfnProxied_high + 108))(a1: m_pfnProxied_high) + 120);
      }
      if ( *(int **)(v7 + 8) == *a3 )
        return HIDWORD(this->m_pfnProxied);
    }
    v8 = DWORD1(this->m_pfnProxied);
    v9 = 0;
    if ( v8 == 0 )
      goto LABEL_44;
    while ( 1 )
    {
      v10 = *(_DWORD *)(LODWORD(v20->m_pfnProxied) + 4 * v9);
      if ( v10 != 0 && *(char *)(v10 + 118) < 0 )
      {
        v11 = *(_DWORD *)(v10 + 148);
        if ( v11 == 0 )
        {
          GFxASCharacter::CreateCharacterHandle(this: *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)(LODWORD(v20->m_pfnProxied) + 4 * v9));
          if ( v11 == 0 )
            v11 = *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v10 + 108))(a1: v10) + 120);
        }
        if ( *(int **)(v11 + 8) == *a3 )
          break;
      }
      if ( ++v9 >= v8 )
      {
        HIDWORD(v20->m_pfnProxied) = 0;
        return ptr;
      }
    }
    HIDWORD(v20->m_pfnProxied) = v10;
    return v10;
  }
  if ( v4[1] == 0 )
    GASStringNode::ResolveLowercase_Impl(a1: v4);
  v12 = (_DWORD *)HIDWORD(this->m_pfnProxied);
  if ( v12 != nullptr )
  {
    v13 = v12[37];
    if ( v13 != 0
      || (GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)HIDWORD(this->m_pfnProxied)),
          v13 != 0) )
    {
      v14 = (int **)(v13 + 8);
    }
    else
    {
      v14 = (int **)(*(_DWORD *)((*(int (__thiscall **)(_DWORD *))(*v12 + 108))(a1: v12) + 120) + 8);
    }
    if ( (*v14)[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: *v14);
    if ( (*a3)[1] == (*v14)[1] )
      return HIDWORD(this->m_pfnProxied);
  }
  v15 = DWORD1(this->m_pfnProxied);
  v16 = 0;
  n = v15;
  if ( v15 == 0 )
    goto LABEL_44;
  while ( 1 )
  {
    v17 = *(_DWORD *)(LODWORD(v20->m_pfnProxied) + 4 * v16);
    if ( v17 != ptr && *(char *)(v17 + 118) < 0 )
    {
      v18 = *(_DWORD *)(v17 + 148);
      if ( v18 != 0
        || (GFxASCharacter::CreateCharacterHandle(this: *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)(LODWORD(v20->m_pfnProxied) + 4 * v16)),
            v18 != 0) )
      {
        v19 = (int **)(v18 + 8);
      }
      else
      {
        v19 = (int **)(*(_DWORD *)((*(int (__thiscall **)(__vc_attributes::pointer_defaultAttribute::type_e))(*(_DWORD *)v17 + 108))(a1: v17)
                                 + 120)
                     + 8);
      }
      if ( (*v19)[1] == 0 )
        GASStringNode::ResolveLowercase_Impl(a1: *v19);
      if ( (*a3)[1] == (*v19)[1] )
        break;
      v15 = n;
    }
    if ( ++v16 >= v15 )
    {
      HIDWORD(v20->m_pfnProxied) = 0;
      return ptr;
    }
  }
  pch.type = v17;
LABEL_44:
  HIDWORD(v20->m_pfnProxied) = pch;
  return pch.type;
}

//------------------------------------------------------------------------------
// Address: 0x1008AD90
// Name: public: void GFxDisplayList::ReplaceDisplayObjectAtIndex(unsigned int,class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxDisplayList::ReplaceDisplayObjectAtIndex(
        _DWORD *this,
        unsigned int index,
        __vc_attributes::pointer_defaultAttribute a3)
{
  int result; // eax
  GRefCountNTSImpl **v4; // esi

  result = index;
  if ( index < *(this + 1) )
  {
    *(this + 3) = 0;
    v4 = (GRefCountNTSImpl **)(*this + 4 * index);
    if ( *v4 != nullptr )
      GRefCountNTSImpl::Release(this: *v4);
    result = a3.type;
    *v4 = (GRefCountNTSImpl *)a3.type;
    if ( a3.type != ptr )
      ++*(_DWORD *)(a3.type + 4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008ADD0
// Name: public: void GFxDisplayList::MarkAllEntriesForRemoval(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayList::MarkAllEntriesForRemoval(
        unsigned int *this,
        const CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *result)
{
  unsigned int v3; // ebx
  unsigned int i; // esi
  GRefCountNTSImpl *v5; // ecx

  v3 = *(this + 1);
  for ( i = 0; i < v3; ++i )
  {
    v5 = *(GRefCountNTSImpl **)(*this + 4 * i);
    if ( v5 != nullptr )
      ++v5->RefCount;
    if ( v5[2].RefCount <= 0x3FFFu && v5[3].__vftable > (GRefCountNTSImpl_vtbl *)result )
      *(_WORD *)(*(_DWORD *)(*this + 4 * i) + 118) |= 0x40u;
    GRefCountNTSImpl::Release(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AE20
// Name: public: void GFxDisplayList::Display(class GFxDisplayContext __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxDisplayList::Display(
        CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *this,
        CUtlVector<void *,CUtlMemory<void *,int> > *context)
{
  GFxAmpViewStats *m_nAllocationCount; // ecx
  float v4; // ecx
  float v5; // ecx
  int v6; // edi
  unsigned int result; // eax
  _BYTE *v8; // ebx
  unsigned int m_Size; // eax
  int v10; // ecx
  int v11; // eax
  void *const *v12; // [esp+0h] [ebp-60h]
  float *v13; // [esp+4h] [ebp-5Ch]
  GFxAmpViewStats *v14; // [esp+14h] [ebp-4Ch]
  unsigned int n; // [esp+24h] [ebp-3Ch]
  CMaterialDict *poldmatrix; // [esp+28h] [ebp-38h]
  CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *v17; // [esp+2Ch] [ebp-34h]
  unsigned int i; // [esp+30h] [ebp-30h]
  GFxCharacter *pparentmask; // [esp+34h] [ebp-2Ch]
  int highestMaskedLayer; // [esp+38h] [ebp-28h]
  void **m_pMemory; // [esp+3Ch] [ebp-24h]
  void (__thiscall **v22)(int, int); // [esp+3Ch] [ebp-24h]
  unsigned int maskCount; // [esp+40h] [ebp-20h]
  struct GMatrix2D v24; // [esp+44h] [ebp-1Ch] BYREF

  m_nAllocationCount = (GFxAmpViewStats *)context[7].m_Memory.m_nAllocationCount;
  v17 = this;
  v14 = m_nAllocationCount;
  if ( m_nAllocationCount != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: m_nAllocationCount, swdHandle: 1u, a3: 3u);
    GTimer::GetRawTicks(li: v4, a2: *(float *)&v12, a3: v13);
  }
  v5 = *((float *)&this->m_pfnProxied + 1);
  maskCount = 0;
  highestMaskedLayer = 0;
  v6 = *(_DWORD *)(context[3].m_Size + 12);
  result = 0;
  i = 0;
  n = LODWORD(v5);
  if ( v5 != 0.0 )
  {
    while ( 1 )
    {
      v5 = *(float *)&this->m_pfnProxied;
      v8 = *(_BYTE **)(LODWORD(this->m_pfnProxied) + 4 * result);
      if ( (*((_WORD *)v8 + 59) & 0x100) == 0
        && *((int *)v8 + 5) >= -1
        && (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)v8 + 16))(a1: v8) != 0
        && (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)v8 + 180))(a1: v8) == 0
        && (v8[118] & 2) == 0 )
      {
        if ( maskCount != 0 && *((_DWORD *)v8 + 5) > highestMaskedLayer )
        {
          --maskCount;
          GFxDisplayContext::PopMask(this: context, a2: v12);
        }
        if ( (void **)context[7].m_Size > context[7].m_pElements && context[7].m_Memory.m_nGrowSize == 0 )
        {
          poldmatrix = (CMaterialDict *)context->m_Memory.m_nAllocationCount;
          m_pMemory = context->m_Memory.m_pMemory;
          context[7].m_Memory.m_nGrowSize = 1;
          do
          {
            m_Size = context[7].m_Size;
            if ( m_Size <= 0x40 )
            {
              pparentmask = *(GFxCharacter **)(*((_DWORD *)&context[7].m_pElements + m_Size) + 32);
              GMatrix2D::SetIdentity(this: (float *)&v24);
              if ( GFxCharacter::Is3D(this: pparentmask, result: nullptr) != 0
                || LOBYTE(context[1].m_Memory.m_pMemory) != 0 )
              {
                context->m_Memory.m_nAllocationCount = (int)&GMatrix2D::Identity;
              }
              else
              {
                GFxCharacter::GetWorldMatrix(this: pparentmask, pmat: (CMaterialDict *)&v24);
                context->m_Memory.m_nAllocationCount = (int)&v24;
              }
              (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 156))(a1: v6, a2: 2);
              v10 = *((_DWORD *)&context[7].m_pElements + context[7].m_Size);
              (*(void (__thiscall **)(int, CUtlVector<void *,CUtlMemory<void *,int> > *))(*(_DWORD *)v10 + 116))(
                a1: v10,
                a2: context);
              (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 160))(a1: v6);
              *((_DWORD *)&context[7].m_pElements + context[7].m_Size) = 0;
            }
            --context[7].m_Size;
          }
          while ( (void **)context[7].m_Size > context[7].m_pElements );
          --context[7].m_Memory.m_nGrowSize;
          context->m_Memory.m_nAllocationCount = (int)poldmatrix;
          context->m_Memory.m_pMemory = m_pMemory;
        }
        if ( *((_WORD *)v8 + 58) == 0 || context[7].m_Memory.m_nGrowSize != 0 )
        {
          v22 = (void (__thiscall **)(int, int))(*(_DWORD *)v6 + 68);
          v11 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v8 + 20))(a1: v8);
          (*v22)(a1: v6, a2: v11);
          (*(void (__thiscall **)(_BYTE *, CUtlVector<void *,CUtlMemory<void *,int> > *))(*(_DWORD *)v8 + 116))(
            a1: v8,
            a2: context);
          (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 72))(a1: v6);
        }
        else
        {
          GFxDisplayContext::PushAndDrawMask(this: context, pmask: (int)v8, a3: v12);
          ++maskCount;
          highestMaskedLayer = *((unsigned __int16 *)v8 + 58);
        }
      }
      result = i + 1;
      i = result;
      if ( result >= n )
        break;
      this = v17;
    }
    for ( ; maskCount != 0; --maskCount )
      result = GFxDisplayContext::PopMask(this: context, a2: v12);
  }
  if ( v14 != nullptr )
  {
    GTimer::GetRawTicks(li: v5, a2: *(float *)&v12, a3: v13);
    return (unsigned int)GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008B0A0
// Name: public: void GFxDisplayList::PropagateMouseEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayList::PropagateMouseEvent(
        CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *this,
        int a2)
{
  int i; // edi
  int v4; // esi

  for ( i = DWORD1(this->m_pfnProxied) - 1; i >= 0; --i )
  {
    v4 = *(_DWORD *)(LODWORD(this->m_pfnProxied) + 4 * i);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 16))(a1: v4) != 0 )
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 160))(a1: v4, a2);
      if ( i >= SDWORD1(this->m_pfnProxied) )
        i = DWORD1(this->m_pfnProxied);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B0F0
// Name: public: void GFxDisplayList::PropagateKeyEvent(class GFxEventId const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *__thiscall GFxDisplayList::PropagateKeyEvent(
        _DWORD *this,
        CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *result,
        int *pkeyMask)
{
  CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *v4; // eax
  unsigned int v5; // edi
  int v6; // esi
  CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *n; // [esp+8h] [ebp-4h]

  v4 = (CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)*(this + 1);
  v5 = 0;
  n = v4;
  if ( v4 != nullptr )
  {
    do
    {
      v6 = *(_DWORD *)(*this + 4 * v5);
      v4 = (CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 16))(a1: v6);
      if ( (_BYTE)v4 != 0 )
      {
        (*(void (__thiscall **)(int, CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *, int *))(*(_DWORD *)v6 + 164))(
          a1: v6,
          a2: result,
          a3: pkeyMask);
        v4 = (CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *)(v5 + 1);
        if ( v5 + 1 >= *(this + 1) )
          break;
      }
      ++v5;
    }
    while ( v5 < (unsigned int)n );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1008B150
// Name: public: void GFxDisplayList::VisitMembers(struct GASObjectInterface::MemberVisitor __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayList::VisitMembers(
        GFxDisplayList *this,
        struct GASObjectInterface::MemberVisitor *visitFlags,
        unsigned int a3)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v5; // edi
  int v6; // eax
  int v7; // ebx
  unsigned int UmsVersion; // esi
  tagAXISINFOA *v9; // eax
  GASValue v10[4]; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int n; // [esp+14h] [ebp-Ch]
  GFxDisplayList *v12; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  v3 = *((_DWORD *)this + 1);
  v4 = 0;
  v12 = this;
  i = 0;
  n = v3;
  if ( v3 != 0 )
  {
    while ( 1 )
    {
      v5 = *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)(*(_DWORD *)this + 4 * v4);
      if ( *((char *)&v5[4].m_pObject + 6) < 0 )
      {
        v6 = DWORD1(v5[6].m_pfnProxied);
        if ( v6 != 0 || (GFxASCharacter::CreateCharacterHandle(this: v5), v6 != 0) )
          v7 = v6 + 8;
        else
          v7 = *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v5->m_pfnProxied) + 108))(a1: v5)
                         + 120)
             + 8;
        if ( *(_DWORD *)(*(_DWORD *)v7 + 16) != 0 )
        {
          UmsVersion = visitFlags->UmsVersion;
          v9 = GASValue::GASValue(this: v10, result: (tagAXISINFOA *)v5);
          (*(void (__thiscall **)(struct GASObjectInterface::MemberVisitor *, int, tagAXISINFOA *, _DWORD))(UmsVersion + 4))(
            a1: visitFlags,
            a2: v7,
            a3: v9,
            a4: 0);
          GASValue::~GASValue(this: v10, a2: (int)v5);
          v4 = i;
        }
      }
      i = ++v4;
      if ( v4 >= n )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B1F0
// Name: public: unsigned int GFxDisplayList::FindDisplayIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxDisplayList::FindDisplayIndex(GFxDisplayList *this, int depth)
{
  int v2; // edx
  int result; // eax
  int v4; // esi

  v2 = *((_DWORD *)this + 1);
  result = 0;
  while ( v2 > 0 )
  {
    v4 = (v2 >> 1) + result;
    if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)this + 4 * v4) + 20) >= depth )
    {
      v2 >>= 1;
    }
    else
    {
      result = v4 + 1;
      v2 += -1 - (v2 >> 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008B240
// Name: public: unsigned int GFxDisplayList::GetDisplayIndex(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxDisplayList::GetDisplayIndex(GFxDisplayList *this, int depth)
{
  unsigned int result; // eax

  result = GFxDisplayList::FindDisplayIndex(this, depth);
  if ( result >= *((_DWORD *)this + 1) || *(_DWORD *)(*(_DWORD *)(*(_DWORD *)this + 4 * result) + 20) != depth )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008B270
// Name: public: class GFxCharacter __near * GFxDisplayList::GetCharacterAtDepth(int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxDisplayList::GetCharacterAtDepth(
        CMemberFuncProxy0<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *this@<ecx>,
        CMatPaintmaps *depth,
        __int128 pisMarkedForRemove)
{
  unsigned int DisplayIndex; // eax
  unsigned int v5; // ecx
  int v6; // eax

  DisplayIndex = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, (int)depth);
  v5 = DisplayIndex;
  if ( DisplayIndex < DWORD1(this->m_pfnProxied) )
  {
    v6 = *(_DWORD *)(LODWORD(this->m_pfnProxied) + 4 * DisplayIndex);
    if ( *(CMatPaintmaps **)(v6 + 20) == depth
      && v5 != -1
      && *(CMatPaintmaps **)(v6 + 20) == depth
      && (_DWORD)pisMarkedForRemove != 0 )
    {
      *(_BYTE *)pisMarkedForRemove = (*(_BYTE *)(v6 + 118) & 0x40) != 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B3A0
// Name: public: bool GFxDisplayList::SwapDepths(int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxDisplayList::SwapDepths(
        CMemberFuncProxyBase<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CFuncMemPolicyNone> *this@<ecx>,
        int a2@<edi>,
        const char *a3@<esi>,
        CMatPaintmaps *depth1,
        __int128 depth2)
{
  unsigned int DisplayIndex; // eax
  unsigned int v7; // edi
  int m_pfnProxied; // esi
  unsigned int v9; // eax
  CMatNullRenderContext *v10; // ecx
  unsigned int v11; // ebx
  GRefCountNTSImpl *v12; // eax
  GRefCountNTSImpl *v13; // ecx
  int v14; // edx
  GRefCountNTSImpl *v15; // ecx
  int v16; // edi
  GRefCountNTSImpl *v17; // esi
  int v18; // ebx
  unsigned __int64 v19; // [esp-Ch] [ebp-20h]
  int v20; // [esp-8h] [ebp-1Ch]
  int v22; // [esp-4h] [ebp-18h]
  IMaterial *v23; // [esp+0h] [ebp-14h]
  int val; // [esp+4h] [ebp-10h] BYREF
  int v25; // [esp+8h] [ebp-Ch]
  GRefCountNTSImpl *v26; // [esp+Ch] [ebp-8h]
  CMatNullRenderContext *v27; // [esp+10h] [ebp-4h]

  v27 = (CMatNullRenderContext *)this;
  if ( depth1 != (CMatPaintmaps *)depth2 )
  {
    HIDWORD(v19) = a2;
    DisplayIndex = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, depth: (int)depth1);
    v7 = DisplayIndex;
    if ( DisplayIndex < DWORD1(this->m_pfnProxied) )
    {
      m_pfnProxied = this->m_pfnProxied;
      if ( *(CMatPaintmaps **)(*(_DWORD *)(LODWORD(this->m_pfnProxied) + 4 * DisplayIndex) + 20) == depth1
        && DisplayIndex != -1 )
      {
        v9 = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, depth: depth2);
        v10 = v27;
        v11 = v9;
        v27->m_pCurrentMaterial = nullptr;
        if ( (CRefCountServiceBase<1,CRefMT>_vtbl *)v9 < v10->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable
          && *(_DWORD *)(*(_DWORD *)(m_pfnProxied + 4 * v9) + 20) == (_DWORD)depth2 )
        {
          v12 = *(GRefCountNTSImpl **)(m_pfnProxied + 4 * v7);
          v26 = v12;
          if ( v12 != nullptr )
            ++v12->RefCount;
          v13 = *(GRefCountNTSImpl **)(m_pfnProxied + 4 * v7);
          v14 = *(_DWORD *)(m_pfnProxied + 4 * v11);
          v25 = v14;
          if ( v13 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v13);
            v14 = v25;
            v12 = v26;
          }
          *(_DWORD *)(m_pfnProxied + 4 * v7) = v14;
          if ( v14 != 0 )
            ++*(_DWORD *)(v14 + 4);
          v15 = *(GRefCountNTSImpl **)(m_pfnProxied + 4 * v11);
          if ( v15 != nullptr )
          {
            GRefCountNTSImpl::Release(this: v15);
            v12 = v26;
          }
          *(_DWORD *)(m_pfnProxied + 4 * v11) = v12;
          if ( v12 != nullptr )
          {
            ++v12->RefCount;
            GRefCountNTSImpl::Release(this: v12);
          }
          v16 = *((_DWORD *)&v27->AddRef + v7);
          if ( v16 != 0 )
          {
            *(_DWORD *)(v16 + 20) = depth1;
            *(_DWORD *)(v16 + 24) = DWORD1(depth2) + 1;
          }
        }
        else
        {
          v17 = *(GRefCountNTSImpl **)(m_pfnProxied + 4 * v7);
          val = (int)v17;
          if ( v17 != nullptr )
            ++v17->RefCount;
          LODWORD(v19) = v7;
          GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::RemoveAt(
            this: v10,
            index: v19,
            a3,
            a4: v23,
            a5: (VertexStreamSpec_t *)val);
          if ( v7 < v11 )
            --v11;
          GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::InsertAt(
            this: v27,
            index: v11,
            (int (__thiscall **)(struct CMatNullRenderContext *))&val,
            a4: v20,
            a5: v22);
          if ( v17 != nullptr )
            GRefCountNTSImpl::Release(this: v17);
        }
        v18 = *((_DWORD *)&v27->AddRef + v11);
        if ( v18 != 0 )
        {
          *(_DWORD *)(v18 + 20) = depth2;
          *(_DWORD *)(v18 + 24) = DWORD1(depth2) + 1;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B4D0
// Name: public: bool GFxDisplayList::RemoveCharacter(class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxDisplayList::RemoveCharacter(IMaterial *this, __vc_attributes::pointer_defaultAttribute a2)
{
  unsigned int DisplayIndex; // eax
  const char *(__thiscall **v4)(IMaterial *); // edx
  const char *(__thiscall *v5)(IMaterial *); // ecx
  unsigned int v6; // esi
  unsigned __int64 v8; // [esp-4h] [ebp-10h]
  const char *v9; // [esp+4h] [ebp-8h]
  IMaterial *depth; // [esp+8h] [ebp-4h]
  VertexStreamSpec_t *savedregs; // [esp+Ch] [ebp+0h]

  depth = *(IMaterial **)(a2.type + 20);
  DisplayIndex = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, (int)depth);
  if ( DisplayIndex >= *((_DWORD *)this + 1) )
    return 0;
  v4 = &this->GetName + DisplayIndex;
  v5 = *v4;
  if ( *v4 != nullptr )
  {
    v6 = DisplayIndex + 1;
    do
    {
      if ( v5 == (const char *(__thiscall *)(IMaterial *))a2.type )
        break;
      if ( depth != *((IMaterial **)v5 + 5) )
        break;
      if ( v6 >= *((_DWORD *)this + 1) )
        break;
      v5 = v4[1];
      ++v4;
      ++DisplayIndex;
      ++v6;
    }
    while ( v5 != nullptr );
  }
  if ( DisplayIndex >= *((_DWORD *)this + 1) || v5 != (const char *(__thiscall *)(IMaterial *))a2.type )
    return 0;
  LODWORD(v8) = DisplayIndex;
  GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::RemoveAt(
    (CMatNullRenderContext *)this,
    index: v8,
    a3: v9,
    a4: depth,
    a5: savedregs);
  *((_DWORD *)this + 3) = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008B550
// Name: public: void GFxDisplayList::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayList::Clear(CMatNullRenderContext *pheapAddr)
{
  unsigned int v2; // esi
  int (__thiscall **v3)(struct CMatNullRenderContext *); // edi
  const MorphWeight_t *v4; // [esp+0h] [ebp-Ch]
  unsigned int n; // [esp+8h] [ebp-4h]

  v2 = 0;
  n = (unsigned int)pheapAddr->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
  if ( n != 0 )
  {
    do
    {
      v3 = &pheapAddr->AddRef + v2;
      (*(void (__thiscall **)(int (__thiscall *)(struct CMatNullRenderContext *)))(*(_DWORD *)*v3 + 136))(a1: *v3);
      ++v2;
      *((_DWORD *)*v3 + 8) = 0;
    }
    while ( v2 < n );
  }
  pheapAddr->m_pCurrentMaterial = nullptr;
  GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: pheapAddr,
    (IMorph *)pheapAddr,
    newSize: 0,
    a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1008B5A0
// Name: public: bool GFxDisplayList::UnloadEntryAtIndex(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxDisplayList::UnloadEntryAtIndex(CMatNullRenderContext *this, unsigned int index)
{
  CMatNullRenderContext_vtbl *v3; // ecx
  _BYTE *v4; // esi
  GRefCountNTSImpl **v5; // ebx
  char result; // al
  char v7; // al
  GRefCountNTSImpl *v8; // esi
  int RefCount; // eax
  int v10; // ebx
  unsigned int DisplayIndex; // eax
  unsigned __int64 v12; // [esp-4h] [ebp-18h]
  int v13; // [esp+0h] [ebp-14h]
  const char *v14; // [esp+4h] [ebp-10h]
  int v15; // [esp+4h] [ebp-10h]
  IMaterial *v16; // [esp+8h] [ebp-Ch]
  int val; // [esp+Ch] [ebp-8h] BYREF
  char v18; // [esp+13h] [ebp-1h]

  v3 = this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable;
  v4 = *((_BYTE **)&v3->AddRef + index);
  v5 = (GRefCountNTSImpl **)(&v3->AddRef + index);
  if ( (v4[118] & 0x40) != 0 )
    return 0;
  if ( v4 != nullptr )
  {
    v7 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v4 + 140))(a1: *((_DWORD *)&v3->AddRef + index));
    *((_WORD *)v4 + 59) |= 0x100u;
    v18 = v7;
    if ( v7 != 0 )
    {
      (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v4 + 136))(a1: v4);
      LODWORD(v12) = index;
      GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::RemoveAt(
        this,
        index: v12,
        a3: v14,
        a4: v16,
        a5: (VertexStreamSpec_t *)val);
      result = v18;
      this->m_pCurrentMaterial = nullptr;
    }
    else
    {
      v8 = *v5;
      RefCount = (*v5)[2].RefCount;
      if ( RefCount >= 0 )
      {
        v10 = -1 - RefCount;
        val = (int)v8;
        if ( v8 != nullptr )
          ++v8->RefCount;
        LODWORD(v12) = index;
        GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::RemoveAt(
          this,
          index: v12,
          a3: v14,
          a4: v16,
          a5: (VertexStreamSpec_t *)val);
        v8[2].RefCount = v10;
        DisplayIndex = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, depth: v10);
        GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::InsertAt(
          this,
          index: DisplayIndex,
          (int (__thiscall **)(struct CMatNullRenderContext *))&val,
          a4: v13,
          a5: v15);
        GRefCountNTSImpl::Release(this: v8);
      }
      result = v18;
      this->m_pCurrentMaterial = nullptr;
    }
  }
  else
  {
    LODWORD(v12) = index;
    GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::RemoveAt(
      this,
      index: v12,
      a3: v14,
      a4: v16,
      a5: (VertexStreamSpec_t *)val);
    this->m_pCurrentMaterial = nullptr;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008B690
// Name: public: void GFxDisplayList::RemoveDisplayObject(int,class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayList::RemoveDisplayObject(CMatNullRenderContext *this, int depth, struct GFxResourceId a3)
{
  CRefCountServiceBase<1,CRefMT>_vtbl *v4; // edi
  unsigned int DisplayIndex; // eax
  int v6; // ecx
  GRefCountNTSImpl *v7; // edi
  CMatNullRenderContext_vtbl *v8; // edi
  unsigned int size; // [esp+Ch] [ebp-8h]
  GRefCountNTSImpl *v10; // [esp+10h] [ebp-4h]

  v4 = this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
  size = (unsigned int)v4;
  DisplayIndex = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, depth);
  if ( DisplayIndex >= (unsigned int)v4 )
    return;
  v6 = 4 * DisplayIndex;
  v7 = *((GRefCountNTSImpl **)&this->AddRef + DisplayIndex);
  v10 = v7;
  if ( v7 != nullptr )
    ++v7->RefCount;
  if ( v7[2].RefCount != depth )
  {
LABEL_12:
    GRefCountNTSImpl::Release(this: v7);
    return;
  }
  this->m_pCurrentMaterial = nullptr;
  if ( a3.Id == 0x40000 )
  {
LABEL_11:
    GFxDisplayList::UnloadEntryAtIndex(this, index: DisplayIndex);
    goto LABEL_12;
  }
  v8 = this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable;
  if ( *(_DWORD *)(*((_DWORD *)&this->AddRef + DisplayIndex) + 16) == a3.Id )
  {
LABEL_10:
    v7 = v10;
    goto LABEL_11;
  }
  while ( ++DisplayIndex < size && (*(_DWORD **)((char *)&v8->Release + v6))[5] == depth )
  {
    v6 = 4 * DisplayIndex;
    if ( *(_DWORD *)(*((_DWORD *)&v8->AddRef + DisplayIndex) + 16) == a3.Id )
      goto LABEL_10;
  }
  GRefCountNTSImpl::Release(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x1008B740
// Name: public: bool GFxDisplayList::UnloadAll(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall GFxDisplayList::UnloadAll@<al>(CMatNullRenderContext *a1@<ecx>, const char *a2@<ebx>, int a3@<edi>)
{
  unsigned int v4; // ecx
  bool v5; // al
  int v6; // ebx
  _BYTE *v7; // edi
  char v8; // cl
  char v9; // al
  GRefCountNTSImpl *v10; // edi
  int v11; // eax
  int v12; // ebx
  unsigned int DisplayIndex; // eax
  bool v14; // zf
  unsigned __int64 v15; // [esp-Ch] [ebp-1Ch]
  int v16; // [esp-8h] [ebp-18h]
  const char *v17; // [esp-4h] [ebp-14h]
  int v18; // [esp-4h] [ebp-14h]
  IMaterial *v19; // [esp+0h] [ebp-10h]
  int val; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h]
  char v22; // [esp+Eh] [ebp-2h]
  bool mayRemove; // [esp+Fh] [ebp-1h]

  v4 = 0;
  v5 = true;
  a1->m_pCurrentMaterial = nullptr;
  mayRemove = true;
  i = 0;
  if ( a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable != nullptr )
  {
    v17 = a2;
    HIDWORD(v15) = a3;
    while ( 1 )
    {
      v6 = 4 * v4;
      v7 = *((_BYTE **)&a1->AddRef + v4);
      v8 = v7[118] >> 6;
      val = (int)a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
          + v6;
      if ( (v8 & 1) == 0 )
      {
        if ( v7 == nullptr )
        {
          if ( a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable == (CRefCountServiceBase<1,CRefMT>_vtbl *)1 )
          {
            GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
              this: a1,
              pheapAddr: (IMorph *)a1,
              newSize: 0,
              a4: (const MorphWeight_t *)HIDWORD(v15));
          }
          else
          {
            memmove(
              dst: (unsigned __int8 *)a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
            + v6,
              src: (unsigned __int8 *)&a1->Release + v6,
              count: 4
            * ((int)a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable
             - i)
            - 4);
            --a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
          }
          a1->m_pCurrentMaterial = nullptr;
          goto LABEL_17;
        }
        v9 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v7 + 140))(a1: v7);
        *((_WORD *)v7 + 59) |= 0x100u;
        v22 = v9;
        if ( v9 != 0 )
        {
          (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v7 + 136))(a1: v7);
          if ( a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable == (CRefCountServiceBase<1,CRefMT>_vtbl *)1 )
          {
            GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
              this: a1,
              pheapAddr: (IMorph *)a1,
              newSize: 0,
              a4: (const MorphWeight_t *)HIDWORD(v15));
          }
          else
          {
            if ( *(int (__thiscall **)(struct CMatNullRenderContext *))((char *)&a1->AddRef + v6) != nullptr )
              GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)((char *)&a1->AddRef + v6));
            memmove(
              dst: (unsigned __int8 *)a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
            + v6,
              src: (unsigned __int8 *)&a1->Release + v6,
              count: 4
            * ((int)a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable
             - i)
            - 4);
            --a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
          }
        }
        else
        {
          v10 = *(GRefCountNTSImpl **)val;
          v11 = *(_DWORD *)(*(_DWORD *)val + 20);
          if ( v11 >= 0 )
          {
            v12 = -1 - v11;
            val = *(_DWORD *)val;
            if ( v10 != nullptr )
              ++v10->RefCount;
            LODWORD(v15) = i;
            GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::RemoveAt(
              this: a1,
              index: v15,
              a3: v17,
              a4: v19,
              a5: (VertexStreamSpec_t *)val);
            v10[2].RefCount = v12;
            DisplayIndex = GFxDisplayList::FindDisplayIndex(this: (GFxDisplayList *)a1, depth: v12);
            GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::InsertAt(
              this: a1,
              index: DisplayIndex,
              (int (__thiscall **)(struct CMatNullRenderContext *))&val,
              a4: v16,
              a5: v18);
            GRefCountNTSImpl::Release(this: v10);
          }
        }
        v14 = v22 == 0;
        a1->m_pCurrentMaterial = nullptr;
        if ( !v14 )
          goto LABEL_17;
      }
      ++i;
      mayRemove = false;
LABEL_17:
      v4 = i;
      if ( (CRefCountServiceBase<1,CRefMT>_vtbl *)i >= a1->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable )
        return mayRemove;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1008B8C0
// Name: public: void GFxDisplayList::UnloadMarkedObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayList::UnloadMarkedObjects(CMatNullRenderContext *this)
{
  unsigned int v2; // esi
  int v3; // eax

  v2 = 0;
  if ( this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable != nullptr )
  {
    do
    {
      v3 = *((_DWORD *)&this->AddRef + v2);
      if ( (*(_BYTE *)(v3 + 118) & 0x40) != 0 )
      {
        *(_WORD *)(v3 + 118) &= ~0x40u;
        if ( GFxDisplayList::UnloadEntryAtIndex(this, index: v2) != 0 )
          --v2;
      }
      ++v2;
    }
    while ( (CRefCountServiceBase<1,CRefMT>_vtbl *)v2 < this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable );
    this->m_pCurrentMaterial = nullptr;
  }
  else
  {
    this->m_pCurrentMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B910
// Name: public: void GFxDisplayList::AddDisplayObject(class GFxCharPosInfo const __near &,class GFxCharacter __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxDisplayList::AddDisplayObject(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        unsigned int pos,
        __int128 ch,
        IMesh *const *addFlags,
        const int *di)
{
  int v5; // edi
  unsigned int DisplayIndex; // eax
  bool v8; // zf
  int v9; // ebx
  void (__thiscall *v10)(_DWORD); // edx
  void (__thiscall *v11)(_DWORD, _DWORD); // edx
  _DWORD v12[6]; // [esp-Ch] [ebp-20h] BYREF
  CMatNullRenderContext *v13; // [esp+Ch] [ebp-8h]
  unsigned int index; // [esp+10h] [ebp-4h]

  v5 = *(_DWORD *)(pos + 72);
  v13 = (CMatNullRenderContext *)this;
  DisplayIndex = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, depth: v5);
  v8 = (BYTE4(ch) & 1) == 0;
  index = DisplayIndex;
  *((_DWORD *)this + 3) = 0;
  if ( !v8
    && DisplayIndex < *((_DWORD *)this + 1)
    && *(_DWORD *)(*((_DWORD *)&this->m_pAllocator->m_pNextAlloc + DisplayIndex) + 20) == v5 )
  {
    GFxDisplayList::UnloadEntryAtIndex((CMatNullRenderContext *)this, index: DisplayIndex);
    index = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, depth: v5);
  }
  v9 = ch;
  *(_DWORD *)(ch + 20) = v5;
  DWORD1(ch) = ch;
  ++*(_DWORD *)(ch + 4);
  v10 = *(void (__thiscall **)(_DWORD))(*(_DWORD *)ch + 4);
  qmemcpy((void *)(ch + 36), (const void *)(pos + 12), 0x20u);
  v10(a1: ch);
  *(float *)(ch + 68) = *(float *)(pos + 44);
  *(float *)(ch + 72) = *(float *)(pos + 48);
  *(float *)(ch + 76) = *(float *)(pos + 52);
  *(float *)(ch + 80) = *(float *)(pos + 56);
  *(float *)(ch + 84) = *(float *)(pos + 60);
  *(float *)(ch + 88) = *(float *)(pos + 64);
  v11 = *(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)ch + 36);
  *(float *)(ch + 28) = *(float *)(pos + 68);
  *(_WORD *)(ch + 116) = *(_WORD *)(pos + 80);
  v11(a1: ch, a2: *(unsigned __int8 *)(pos + 82));
  GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
    this: (CMatQueuedMesh *)v12,
    a: (int *)pos,
    a3: (VertexDesc_t *)v12[0]);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 48))(a1: v9, a2: v12[0], a3: v12[1], a4: v12[2]);
  GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::InsertAt(
    this: v13,
    index,
    val: (int (__thiscall **)(struct CMatNullRenderContext *))&ch + 1,
    a4: v12[3],
    a5: v12[4]);
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 132))(a1: v9);
  GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)ch);
}

//------------------------------------------------------------------------------
// Address: 0x1008BA10
// Name: public: void GFxDisplayList::MoveDisplayObject(class GFxCharPosInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GFxDisplayList::MoveDisplayObject@<eax>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        CLateBoundPtr<IMesh> pos,
        __int128 pos_4)
{
  IMesh **m_ppObject; // esi
  int v4; // edi
  unsigned int result; // eax
  CMemoryStack *m_pAllocator; // ecx
  float *v8; // ebx
  int (__thiscall *v9)(float *); // edx
  VertexDesc_t *v10[6]; // [esp-Ch] [ebp-18h] BYREF

  m_ppObject = pos.m_ppObject;
  v4 = *((_DWORD *)pos.m_ppObject + 18);
  result = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, depth: v4);
  if ( result < *((_DWORD *)this + 1) )
  {
    m_pAllocator = this->m_pAllocator;
    v8 = *((float **)&this->m_pAllocator->m_pNextAlloc + result);
    result = (unsigned int)m_pAllocator + 4 * result;
    if ( *((_DWORD *)v8 + 5) == v4 )
    {
      *((_WORD *)v8 + 59) &= ~0x40u;
      result = (*(int (__thiscall **)(float *))(*(_DWORD *)v8 + 28))(a1: v8);
      if ( (_BYTE)result == 0 )
      {
        result = (*(int (__thiscall **)(float *))(*(_DWORD *)v8 + 24))(a1: v8);
        if ( (_BYTE)result == 0 )
          return result;
        result = (*(int (__thiscall **)(float *, int))(*(_DWORD *)v8 + 32))(a1: v8, a2: 1);
      }
      if ( (*((_BYTE *)pos.m_ppObject + 83) & 8) != 0 )
      {
        v9 = *(int (__thiscall **)(float *))(*(_DWORD *)v8 + 4);
        qmemcpy(v8 + 9, pos.m_ppObject + 3, 0x20u);
        result = v9(a1: v8);
        m_ppObject = pos.m_ppObject;
      }
      if ( (*((_BYTE *)m_ppObject + 83) & 4) != 0 )
      {
        v8[17] = *((float *)m_ppObject + 11);
        v8[18] = *((float *)m_ppObject + 12);
        v8[19] = *((float *)m_ppObject + 13);
        v8[20] = *((float *)m_ppObject + 14);
        v8[21] = *((float *)m_ppObject + 15);
        v8[22] = *((float *)m_ppObject + 16);
      }
      if ( *((char *)m_ppObject + 83) < 0 )
        result = (*(int (__thiscall **)(float *, _DWORD))(*(_DWORD *)v8 + 36))(
                   a1: v8,
                   a2: *((unsigned __int8 *)m_ppObject + 82));
      if ( (*((_BYTE *)m_ppObject + 83) & 0x20) != 0 )
      {
        GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
          this: (CMatQueuedMesh *)v10,
          a: (int *)m_ppObject,
          a3: v10[0]);
        result = (*(int (__thiscall **)(float *, VertexDesc_t *, VertexDesc_t *, VertexDesc_t *))(*(_DWORD *)v8 + 48))(
                   a1: v8,
                   a2: v10[0],
                   a3: v10[1],
                   a4: v10[2]);
      }
      v8[7] = *((float *)m_ppObject + 17);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008BB00
// Name: public: void GFxDisplayList::ReplaceDisplayObject(class GFxCharPosInfo const __near &,class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxDisplayList::ReplaceDisplayObject(CMatCallQueue *this@<ecx>, CLateBoundPtr<IMesh> pos, __int128 ch)
{
  int v3; // edi
  unsigned int DisplayIndex; // eax
  GRefCountNTSImpl **v6; // esi
  GRefCountNTSImpl *v7; // eax
  void (__thiscall *v8)(_DWORD); // eax
  IMesh **p_RefCount; // esi
  void (__thiscall *v10)(_DWORD); // eax
  GRefCountNTSImpl *v11; // edi
  float *v12; // eax
  int v13; // eax
  VertexDesc_t *v14; // [esp-Ch] [ebp-20h] BYREF
  __int128 v15; // [esp-8h] [ebp-1Ch]
  IMesh *const *v16; // [esp+8h] [ebp-Ch]
  CMatCallQueue *v17; // [esp+Ch] [ebp-8h]
  GRefCountNTSImpl *v18; // [esp+10h] [ebp-4h]

  v3 = *((_DWORD *)pos.m_ppObject + 18);
  v17 = this;
  DisplayIndex = GFxDisplayList::FindDisplayIndex((GFxDisplayList *)this, depth: v3);
  if ( (CMatCallQueue::Elem_t *)DisplayIndex < this->m_pTail
    && (v6 = (GRefCountNTSImpl **)&this->m_pHead[DisplayIndex], v7 = *v6, v18 = v7, v7[2].RefCount == v3) )
  {
    if ( v7 != nullptr )
      ++v7->RefCount;
    v8 = *(void (__thiscall **)(_DWORD))(*(_DWORD *)ch + 120);
    *(_DWORD *)(ch + 20) = v3;
    v8(a1: ch);
    HIWORD((*v6)[14].RefCount) &= ~0x40u;
    if ( *v6 != nullptr )
      GRefCountNTSImpl::Release(this: *v6);
    *v6 = (GRefCountNTSImpl *)ch;
    ++*(_DWORD *)(ch + 4);
    if ( (*((_BYTE *)pos.m_ppObject + 83) & 8) != 0 )
      p_RefCount = pos.m_ppObject + 3;
    else
      p_RefCount = (IMesh **)&v18[4].RefCount;
    v10 = *(void (__thiscall **)(_DWORD))(*(_DWORD *)ch + 4);
    qmemcpy((void *)(ch + 36), p_RefCount, 0x20u);
    v10(a1: ch);
    v11 = v18;
    v12 = (float *)(pos.m_ppObject + 11);
    if ( (*((_BYTE *)pos.m_ppObject + 83) & 4) == 0 )
      v12 = (float *)&v18[8].RefCount;
    *(float *)(ch + 68) = *v12;
    *(float *)(ch + 72) = v12[1];
    *(float *)(ch + 76) = v12[2];
    *(float *)(ch + 80) = v12[3];
    *(float *)(ch + 84) = v12[4];
    *(float *)(ch + 88) = v12[5];
    if ( *((char *)pos.m_ppObject + 83) >= 0 )
      v13 = ((int (__thiscall *)(GRefCountNTSImpl *))v11->__vftable[5].dtr_GRefCountImplCore)(a1: v11);
    else
      v13 = *((unsigned __int8 *)pos.m_ppObject + 82);
    (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)ch + 36))(a1: ch, a2: v13);
    *(float *)(ch + 28) = *((float *)pos.m_ppObject + 17);
    *(_WORD *)(ch + 116) = *((_WORD *)pos.m_ppObject + 40);
    GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
      this: (CMatQueuedMesh *)&v14,
      a: (int *)pos.m_ppObject,
      a3: v14);
    (*(void (__thiscall **)(_DWORD, VertexDesc_t *, _DWORD, _DWORD))(*(_DWORD *)ch + 48))(
      a1: ch,
      a2: v14,
      a3: v15,
      a4: DWORD1(v15));
    v11->__vftable[34].dtr_GRefCountImplCore(this: v11);
    v17->m_Allocator.m_pCommitLimit = nullptr;
    GRefCountNTSImpl::Release(this: v11);
  }
  else
  {
    *(_QWORD *)&v15 = (unsigned int)ch | 0x100000000LL;
    GFxDisplayList::AddDisplayObject(
      (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)this,
      pos: (unsigned int)pos.m_ppObject,
      ch: v15,
      addFlags: v16,
      di: (const int *)v17);
  }
}
