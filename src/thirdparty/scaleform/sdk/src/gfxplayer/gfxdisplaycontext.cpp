// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxdisplaycontext.cpp
// Functions: 12
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxdisplaycontext.h"

//------------------------------------------------------------------------------
// Address: 0x10106C70
// Name: public: void GFxDisplayContext::PreDrawMask(class GFxCharacter __near *,class GMatrix2D __near *,class GMatrix3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayContext::PreDrawMask(
        GFxDisplayContext *this,
        struct GFxCharacter *a2,
        CMaterialDict *a3,
        CMatQueuedMesh::MST_MeshInfo_t *pmat)
{
  char v5; // al
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v6; // ecx

  v5 = GFxCharacter::Is3D(this: a2, result: nullptr);
  v6 = *((CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> **)a2
       + 8);
  if ( v5 != 0 )
  {
    GFxCharacter::GetWorldMatrix3D(this: v6, pmat);
    *((_DWORD *)this + 2) = pmat;
    *((_DWORD *)this + 1) = &GMatrix2D::Identity;
  }
  else
  {
    GFxCharacter::GetWorldMatrix(this: (GFxCharacter *)v6, pmat: a3);
    *((_DWORD *)this + 1) = a3;
    *((_DWORD *)this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106CC0
// Name: public: void GFxDisplayContext::Init(class GFxStateBag const __near *,class GFxResourceWeakLib __near *,class GFxResourceBinding __near *,float,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxDisplayContext::Init(
        CUtlVector<void *,CUtlMemory<void *,int> > *this,
        int pstate,
        IShaderDevice *plib,
        _RATE_QUOTA_LIMIT *pbinding,
        float pixelScale,
        float *a6)
{
  void (__thiscall *v7)(int, int *, int (__cdecl *)(__timeb64 *), int); // eax
  IShaderAPI *v8; // ecx
  int v9; // edi
  IShaderAPI *v10; // ecx
  int v11; // edi
  IShaderAPI *v12; // ecx
  int v13; // edi
  IShaderAPI *v14; // ecx
  int v15; // edi
  IShaderAPI *v16; // ecx
  int v17; // edi
  IShaderAPI *v18; // ecx
  int v19; // edi
  IShaderAPI *v20; // ecx
  int v22; // [esp+Ch] [ebp-18h] BYREF
  int v23; // [esp+10h] [ebp-14h]
  int v24; // [esp+14h] [ebp-10h]
  int v25; // [esp+18h] [ebp-Ch]
  int v26; // [esp+1Ch] [ebp-8h]
  int v27; // [esp+20h] [ebp-4h]

  v7 = *(void (__thiscall **)(int, int *, int (__cdecl *)(__timeb64 *), int))(*(_DWORD *)pstate + 16);
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v7(a1: pstate, a2: &v22, a3: stateQuery_0, a4: 6);
  v8 = *((IShaderAPI **)this + 18);
  v9 = v22;
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  *((_DWORD *)this + 18) = v9;
  v10 = *((IShaderAPI **)this + 22);
  v11 = v23;
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
  *((_DWORD *)this + 22) = v11;
  v12 = *((IShaderAPI **)this + 23);
  v13 = v24;
  if ( v12 != nullptr )
    GRefCountImpl::Release(this: v12);
  *((_DWORD *)this + 23) = v13;
  v14 = *((IShaderAPI **)this + 24);
  v15 = v25;
  if ( v14 != nullptr )
    GRefCountImpl::Release(this: v14);
  *((_DWORD *)this + 24) = v15;
  v16 = *((IShaderAPI **)this + 25);
  v17 = v26;
  if ( v16 != nullptr )
    GRefCountImpl::Release(this: v16);
  *((_DWORD *)this + 25) = v17;
  v18 = *((IShaderAPI **)this + 26);
  v19 = v27;
  if ( v18 != nullptr )
    GRefCountImpl::Release(this: v18);
  *((_DWORD *)this + 26) = v19;
  if ( plib != nullptr )
    GRefCountImpl::AddRef(this: plib);
  v20 = *((IShaderAPI **)this + 27);
  if ( v20 != nullptr )
    GRefCountImpl::Release(this: v20);
  *((_DWORD *)this + 27) = plib;
  *((float *)this + 29) = pixelScale;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 28) = pbinding;
  *((float *)this + 30) = *a6;
  *((float *)this + 31) = a6[1];
  *((float *)this + 32) = a6[2];
  *((float *)this + 33) = a6[3];
  *((float *)this + 34) = a6[4];
  *((float *)this + 35) = a6[5];
  *((_DWORD *)this + 20) = 0;
  this->m_Memory.m_nGrowSize = 0;
  *((_BYTE *)this + 20) = 0;
  this->m_pElements = nullptr;
  this->m_Size = 0;
  this->m_Memory.m_nAllocationCount = (int)&GMatrix2D::Identity;
  this->m_Memory.m_pMemory = (void **)GRenderer::Cxform::Identity;
  return a6;
}

//------------------------------------------------------------------------------
// Address: 0x10106E00
// Name: public: void GFxDisplayContext::PushAndDrawMask(class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxDisplayContext::PushAndDrawMask@<eax>(
        CUtlVector<void *,CUtlMemory<void *,int> > *this@<ecx>,
        __vc_attributes::pointer_defaultAttribute pmask,
        void *const *a3)
{
  __vc_attributes::pointer_defaultAttribute::type_e *v4; // edi
  unsigned int v5; // eax
  int v7; // eax
  __vc_attributes::pointer_defaultAttribute pmaska; // [esp+14h] [ebp+8h]

  v4 = *(__vc_attributes::pointer_defaultAttribute::type_e **)(*((_DWORD *)this + 18) + 12);
  (*(void (__thiscall **)(__vc_attributes::pointer_defaultAttribute::type_e *, bool))(*v4 + 156))(
    a1: v4,
    a2: *((_DWORD *)this + 39) != 0);
  v5 = *((_DWORD *)this + 39);
  if ( v5 < 0x40 )
    *((__vc_attributes::pointer_defaultAttribute *)this + v5 + 40) = pmask;
  ++*((_DWORD *)this + 39);
  ++*((_DWORD *)this + 38);
  ++*((_DWORD *)this + 37);
  pmaska.type = *v4;
  v7 = (*(int (__thiscall **)(__vc_attributes::pointer_defaultAttribute))(*(_DWORD *)pmask.type + 20))(a1: pmask);
  (*(void (__thiscall **)(__vc_attributes::pointer_defaultAttribute::type_e *, int))(pmaska.type + 68))(a1: v4, a2: v7);
  (*(void (__thiscall **)(__vc_attributes::pointer_defaultAttribute, CUtlVector<void *,CUtlMemory<void *,int> > *))(*(_DWORD *)pmask.type + 116))(
    a1: pmask,
    a2: this);
  (*(void (__thiscall **)(__vc_attributes::pointer_defaultAttribute::type_e *))(*v4 + 72))(a1: v4);
  --*((_DWORD *)this + 37);
  return (*(int (__thiscall **)(__vc_attributes::pointer_defaultAttribute::type_e *))(*v4 + 160))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10106EA0
// Name: public: void GFxDisplayContext::PopMask(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxDisplayContext::PopMask(CUtlVector<void *,CUtlMemory<void *,int> > *this)
{
  int result; // eax

  if ( (*((_DWORD *)this + 39))-- == 1 )
  {
    result = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*((_DWORD *)this + 18) + 12) + 164))(a1: *(_DWORD *)(*((_DWORD *)this + 18) + 12));
    *((_DWORD *)this + 38) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10106ED0
// Name: public: void GFxDisplayContext::PreDisplay(class GFxDisplayContextTransforms __near &,class GFxCharacter const __near *,class GMatrix2D __near *,class GMatrix3D __near *,class GRenderer::Cxform __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayContext::PreDisplay(
        struct GRenderer::Cxform **this,
        struct GFxDisplayContextTransforms *a2,
        const struct GFxCharacter *a3,
        GMatrix2D *a4,
        CBasePerMaterialContextData *a5,
        struct GRenderer::Cxform *a6)
{
  bool v7; // zf
  const struct GFxCharacter *v8; // esi
  struct GMatrix3D *v9; // esi
  int (__cdecl *v10)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *); // eax
  int v11; // ecx
  int View3D; // eax
  int Perspective3D; // eax
  GMatrix3D *v14; // [esp-4h] [ebp-E0h]
  GMatrix3D *v15; // [esp-4h] [ebp-E0h]
  GMatrix3D v16; // [esp+18h] [ebp-C4h] BYREF
  struct GMatrix3D v17; // [esp+58h] [ebp-84h] BYREF
  struct GMatrix3D v18; // [esp+98h] [ebp-44h] BYREF

  *a4 = *(GMatrix2D *)*(_DWORD *)&a2[4];
  v7 = *((_BYTE *)this + 20) == 0;
  *(this + 20) = (struct GRenderer::Cxform *)a3;
  if ( v7 )
  {
    GMatrix2D::Prepend(this: a4, a2: (const struct GMatrix2D *)((char *)a3 + 68));
    *(this + 1) = (struct GRenderer::Cxform *)a4;
  }
  *a6 = **this;
  v8 = a3;
  GRenderer::Cxform::Concatenate(this: a6, a2: (const struct GRenderer::Cxform *)((char *)a3 + 36));
  v7 = *((_BYTE *)this + 20) == 0;
  *this = a6;
  if ( !v7 || GFxCharacter::Is3D(this: a3, result: nullptr) != 0 )
  {
    v9 = *(struct GMatrix3D **)&a2[8];
    if ( v9 == nullptr )
      v9 = (struct GMatrix3D *)GMatrix3D::Identity;
    *(struct GMatrix3D *)&a5->__vftable = *v9;
    v10 = *((int (__cdecl **)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *))a3 + 23);
    if ( v10 == nullptr )
      v10 = GMatrix3D::Identity;
    qmemcpy((void *)&v18, v10, sizeof(v18));
    if ( GFxCharacter::Is3D(this: a3, result: nullptr) == 0 || *((_BYTE *)this + 20) != 0 )
    {
      if ( *((_BYTE *)this + 20) == 1 )
      {
        v15 = GMatrix3D::GMatrix3D(this: &v16, a2: (const struct GMatrix2D *)((char *)a3 + 68));
        v17 = v18;
        GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v18, a2: (float *)&v17, a3: (float *)v15);
      }
    }
    else
    {
      v14 = GMatrix3D::GMatrix3D(this: &v16, a2: (const struct GMatrix2D *)*(this + 1));
      v17 = v18;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v18, a2: (float *)&v17, a3: (float *)v14);
      *((_BYTE *)this + 20) = 1;
    }
    if ( *((_BYTE *)this + 20) != 0 )
    {
      v17 = *(struct GMatrix3D *)&a5->__vftable;
      GMatrix3D::MultiplyMatrix(this: a5, a2: (float *)&v18, a3: (float *)&v17);
      v11 = (int)*(this + 18);
      *(this + 2) = (struct GRenderer::Cxform *)a5;
      (*(void (__thiscall **)(_DWORD, CBasePerMaterialContextData *))(**(_DWORD **)(v11 + 12) + 92))(
        a1: *(_DWORD *)(v11 + 12),
        a2: a5);
      *(this + 1) = (struct GRenderer::Cxform *)&GMatrix2D::Identity;
    }
    v8 = a3;
  }
  if ( GFxCharacter::GetView3D(this: v8, checkAncestors: false) != 0 )
    View3D = GFxCharacter::GetView3D(this: v8, checkAncestors: false);
  else
    View3D = *(_DWORD *)&a2[16];
  *(this + 4) = (struct GRenderer::Cxform *)View3D;
  if ( GFxCharacter::GetPerspective3D(this: v8, checkAncestors: false) != 0 )
    Perspective3D = GFxCharacter::GetPerspective3D(this: v8, checkAncestors: false);
  else
    Perspective3D = *(_DWORD *)&a2[12];
  v7 = *(this + 21) == nullptr;
  *(this + 3) = (struct GRenderer::Cxform *)Perspective3D;
  if ( v7 )
  {
    if ( *(this + 4) != nullptr )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD((*(this + 18))->M_[1][1]) + 88))(
        a1: LODWORD((*(this + 18))->M_[1][1]),
        a2: *(this + 4));
    if ( *(this + 3) != nullptr )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD((*(this + 18))->M_[1][1]) + 84))(
        a1: LODWORD((*(this + 18))->M_[1][1]),
        a2: *(this + 3));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107120
// Name: public: void GFxDisplayContext::PostDisplay(class GFxDisplayContextTransforms __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxDisplayContext::PostDisplay(CUtlVector<void *,CUtlMemory<void *,int> > *this, int oldXform)
{
  char result; // al

  if ( *((_BYTE *)this + 20) != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(*((_DWORD *)this + 18) + 12) + 92))(
      a1: *(_DWORD *)(*((_DWORD *)this + 18) + 12),
      a2: *(_DWORD *)(oldXform + 8));
  if ( *((_DWORD *)this + 21) == 0 )
  {
    if ( *(_DWORD *)(oldXform + 16) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(*((_DWORD *)this + 18) + 12) + 88))(
        a1: *(_DWORD *)(*((_DWORD *)this + 18) + 12),
        a2: *(_DWORD *)(oldXform + 16));
    if ( *(_DWORD *)(oldXform + 12) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(*((_DWORD *)this + 18) + 12) + 84))(
        a1: *(_DWORD *)(*((_DWORD *)this + 18) + 12),
        a2: *(_DWORD *)(oldXform + 12));
  }
  this->m_Memory.m_pMemory = *(void ***)oldXform;
  this->m_Memory.m_nAllocationCount = *(_DWORD *)(oldXform + 4);
  this->m_Memory.m_nGrowSize = *(_DWORD *)(oldXform + 8);
  this->m_Size = *(_DWORD *)(oldXform + 12);
  this->m_pElements = *(void ***)(oldXform + 16);
  result = *(_BYTE *)(oldXform + 20);
  *((_BYTE *)this + 20) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101071A0
// Name: public: void GFxDisplayContextFilters::CopyFilterStateFrom(class GFxDisplayContextFilters const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayContextFilters::CopyFilterStateFrom(
        GFxDisplayContextFilters *this,
        const struct GFxDisplayContextFilters *a2)
{
  int v4; // eax
  int v5; // ebx
  float v6; // [esp+Ch] [ebp-8h]
  float v7; // [esp+10h] [ebp-4h]
  float v8; // [esp+1Ch] [ebp+8h]

  *(_BYTE *)this = *(_BYTE *)a2;
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  v4 = *((_DWORD *)a2 + 11);
  if ( v4 != 0 )
    InterlockedExchangeAdd(Addend: (volatile LONG *)(v4 + 4), Value: 1);
  v5 = *((_DWORD *)this + 11);
  if ( v5 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v5 + 4), Value: -1) == 1 )
    (**(void (__thiscall ***)(int, int))v5)(a1: v5, a2: 1);
  *((_DWORD *)this + 11) = *((_DWORD *)a2 + 11);
  *((_DWORD *)this + 7) = *((_DWORD *)a2 + 7);
  *((_DWORD *)this + 8) = *((_DWORD *)a2 + 8);
  v8 = *((float *)a2 + 4);
  v7 = *((float *)a2 + 5);
  v6 = *((float *)a2 + 6);
  *((float *)this + 3) = *((float *)a2 + 3);
  *((float *)this + 4) = v8;
  *((float *)this + 5) = v7;
  *((float *)this + 6) = v6;
  *((float *)this + 9) = *((float *)a2 + 9);
  *((float *)this + 10) = *((float *)a2 + 10);
}

//------------------------------------------------------------------------------
// Address: 0x10107240
// Name: public: GFxDisplayContext::GFxDisplayContext(class GFxStateBag const __near *,class GFxResourceWeakLib __near *,class GFxResourceBinding __near *,float,class GMatrix2D const __near &,class GFxAmpViewStats __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<void *,CUtlMemory<void *,int> > *__thiscall GFxDisplayContext::GFxDisplayContext(
        CUtlVector<void *,CUtlMemory<void *,int> > *this,
        int pstate,
        IShaderDevice *plib,
        _RATE_QUOTA_LIMIT *pbinding,
        float pixelScale,
        float *a6,
        int a7,
        bool prepass)
{
  this->m_Memory.m_nAllocationCount = (int)&GMatrix2D::Identity;
  this->m_Memory.m_pMemory = (void **)GRenderer::Cxform::Identity;
  this->m_Memory.m_nGrowSize = 0;
  *((_BYTE *)this + 20) = 0;
  this->m_pElements = nullptr;
  this->m_Size = 0;
  *((_BYTE *)this + 24) = prepass;
  *((float *)this + 9) = 0.0;
  *((_DWORD *)this + 17) = 0;
  *((float *)this + 10) = 0.0;
  *((float *)this + 11) = 0.0;
  *((float *)this + 12) = 0.0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  GMatrix2D::SetIdentity(this: (float *)this + 30);
  *((_DWORD *)this + 36) = a7;
  GFxDisplayContext::Init(this, pstate, plib, pbinding, pixelScale, a6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101072D0
// Name: public: GFxDisplayContext::~GFxDisplayContext(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayContext::~GFxDisplayContext(CUtlVector<void *,CUtlMemory<void *,int> > *this)
{
  IShaderAPI *v2; // ecx
  IShaderAPI *v3; // ecx
  IShaderAPI *v4; // ecx
  IShaderAPI *v5; // ecx
  IShaderAPI *v6; // ecx
  IShaderAPI *v7; // ecx
  IShaderAPI *v8; // ecx
  int v9; // esi

  v2 = *((IShaderAPI **)this + 27);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  v3 = *((IShaderAPI **)this + 26);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = *((IShaderAPI **)this + 25);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  v5 = *((IShaderAPI **)this + 24);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  v6 = *((IShaderAPI **)this + 23);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  v7 = *((IShaderAPI **)this + 22);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  v8 = *((IShaderAPI **)this + 18);
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  v9 = *((_DWORD *)this + 17);
  if ( v9 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v9 + 4), Value: -1) == 1 )
    (**(void (__thiscall ***)(int, int))v9)(a1: v9, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10107350
// Name: public: bool GFxDisplayContext::BeginFilters(class GFxDisplayContextFilters __near &,class GFxCharacter __near *,class GArray<struct GFxFilterDesc,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayContext::BeginFilters(
        CUtlVector<void *,CUtlMemory<void *,int> > *this,
        GFxDisplayContextFilters *oldFilters,
        int ch,
        _DWORD *oldFilters_8)
{
  double v5; // st7
  int v6; // esi
  char v7; // dl
  char v8; // al
  bool v9; // bl
  bool v10; // cl
  bool v11; // al
  double v12; // st7
  double v13; // st7
  int v14; // edx
  double v15; // st6
  double v16; // st7
  double v17; // st7
  int v18; // ecx
  double v19; // st7
  double v20; // st7
  int v21; // edx
  double v22; // st6
  double v23; // st7
  const struct GFxDisplayContextFilters *v24; // eax
  float *v25; // eax
  double v26; // st7
  double v27; // st7
  int v28; // edx
  int v29; // esi
  int v30; // ebx
  bool v31; // zf
  int v32; // eax
  double v33; // [esp+1Ch] [ebp-3Ch]
  _BYTE v34[8]; // [esp+24h] [ebp-34h] BYREF
  float v35; // [esp+2Ch] [ebp-2Ch]
  float v36; // [esp+30h] [ebp-28h]
  double v37; // [esp+34h] [ebp-24h]
  int v38; // [esp+3Ch] [ebp-1Ch]
  unsigned int i; // [esp+40h] [ebp-18h]
  float count; // [esp+44h] [ebp-14h]
  int v41; // [esp+48h] [ebp-10h]
  float FilterSizeY; // [esp+4Ch] [ebp-Ch]
  float FilterSizeX; // [esp+50h] [ebp-8h]
  bool HasFilter; // [esp+57h] [ebp-1h]
  float oldFilters_4; // [esp+64h] [ebp+Ch]
  float oldFilters_8a; // [esp+68h] [ebp+10h]
  float oldFilters_8b; // [esp+68h] [ebp+10h]
  float oldFilters_8c; // [esp+68h] [ebp+10h]
  float oldFilters_8d; // [esp+68h] [ebp+10h]
  float oldFilters_8e; // [esp+68h] [ebp+10h]
  float oldFilters_8f; // [esp+68h] [ebp+10h]
  float oldFilters_8g; // [esp+68h] [ebp+10h]

  if ( oldFilters_8[1] == 0 )
    return;
  v5 = 0.0;
  HasFilter = false;
  FilterSizeX = 0.0;
  i = 0;
  FilterSizeY = 0.0;
  v41 = 0;
  while ( 1 )
  {
    v6 = v41 + *oldFilters_8;
    if ( v5 >= *(float *)(v6 + 12) || (v7 = *(_BYTE *)v6 & 0xF) != 1 )
      v7 = 0;
    v8 = *(_BYTE *)(v6 + 35);
    v9 = v8 != 0 && (*(_BYTE *)v6 & 0xF) == 0;
    v10 = v8 != 0 && (*(_BYTE *)v6 & 0xF) == 2;
    v11 = v8 != 0 && (*(_BYTE *)v6 & 0xF) == 3;
    if ( v7 != 0 )
    {
      v12 = (double)*(unsigned int *)(v6 + 20);
      HasFilter = true;
      count = v12 * *(float *)(v6 + 12);
      v13 = ceil(X: count);
      v14 = *(_DWORD *)(v6 + 20);
      count = v13;
      FilterSizeX = count * 20.0 + FilterSizeX;
      v15 = (double)*(int *)(v6 + 20);
      if ( v14 < 0 )
        v15 = v15 + 4294967300.0;
      count = *(float *)(v6 + 16) * v15;
      count = ceil(X: count);
      v16 = count * 20.0;
      goto LABEL_37;
    }
    if ( v9 || v10 || v11 )
    {
      HasFilter = true;
      if ( v11 )
        v17 = 2.0;
      else
        v17 = 1.0;
      v18 = *(_DWORD *)(v6 + 20);
      count = v17;
      v19 = (double)*(int *)(v6 + 20);
      if ( v18 < 0 )
        v19 = v19 + 4294967300.0;
      *(float *)&v38 = v19 * *(float *)(v6 + 12);
      v37 = count * 20.0;
      v20 = ceil(X: *(float *)&v38);
      v21 = *(_DWORD *)(v6 + 20);
      *(float *)&v38 = v20;
      FilterSizeX = *(float *)&v38 * v37 + FilterSizeX;
      v22 = (double)*(int *)(v6 + 20);
      if ( v21 < 0 )
        v22 = v22 + 4294967300.0;
      *(float *)&v38 = *(float *)(v6 + 16) * v22;
      *(float *)&v38 = ceil(X: *(float *)&v38);
      FilterSizeY = *(float *)&v38 * v37 + FilterSizeY;
      if ( v9 )
      {
        v38 = *(__int16 *)(v6 + 2);
        v23 = (double)v38;
        v38 = *(__int16 *)(v6 + 4);
        count = v23 * 3.141592741012573 / 1800.0;
        v33 = (double)v38;
        *(float *)&v38 = cos(count);
        v35 = *(float *)&v38 * v33 * 0.05000000074505806;
        *(float *)&v38 = sin(count);
        v36 = *(float *)&v38 * v33 * 0.05000000074505806;
        *(float *)&v38 = fabs(v35);
        *(float *)&v38 = *(float *)&v38 * v37;
        *(float *)&v38 = ceil(X: *(float *)&v38);
        FilterSizeX = *(float *)&v38 + FilterSizeX;
        *(float *)&v38 = fabs(v36);
        *(float *)&v38 = *(float *)&v38 * v37;
        *(float *)&v38 = ceil(X: *(float *)&v38);
        v16 = *(float *)&v38;
LABEL_37:
        FilterSizeY = v16 + FilterSizeY;
      }
    }
    else if ( (*(_BYTE *)v6 & 0xF) == 6 )
    {
      HasFilter = true;
    }
    v41 += 156;
    if ( ++i >= oldFilters_8[1] )
      break;
    v5 = 0.0;
  }
  if ( HasFilter )
  {
    if ( this != nullptr )
      v24 = (const struct GFxDisplayContextFilters *)((char *)this + 24);
    else
      v24 = nullptr;
    GFxDisplayContextFilters::CopyFilterStateFrom(this: oldFilters, a2: v24);
    *((float *)this + 15) = GMatrix2D::GetXScale(this: (GMatrix2D *)this + 5);
    *((float *)this + 16) = GMatrix2D::GetYScale(this: (GMatrix2D *)this + 5);
    v25 = (float *)(*(int (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)ch + 52))(
                     a1: ch,
                     a2: v34,
                     a3: this->m_Memory.m_nAllocationCount);
    oldFilters_8a = v25[1];
    oldFilters_4 = v25[2];
    v38 = *((int *)v25 + 3);
    *((float *)this + 9) = *v25;
    *((float *)this + 10) = oldFilters_8a;
    *((float *)this + 11) = oldFilters_4;
    *((float *)this + 12) = *(float *)&v38;
    v26 = FilterSizeX;
    *((float *)this + 9) = *((float *)this + 9) - FilterSizeX;
    *((float *)this + 11) = v26 + *((float *)this + 11);
    v27 = FilterSizeY;
    *((float *)this + 10) = *((float *)this + 10) - FilterSizeY;
    *((float *)this + 12) = v27 + *((float *)this + 12);
    oldFilters_8b = *((float *)this + 11) - *((float *)this + 9);
    oldFilters_8c = oldFilters_8b * *((float *)this + 15);
    oldFilters_8d = ceil(X: oldFilters_8c);
    *((_DWORD *)this + 13) = (__int64)oldFilters_8d;
    oldFilters_8e = *((float *)this + 12) - *((float *)this + 10);
    oldFilters_8f = oldFilters_8e * *((float *)this + 16);
    oldFilters_8g = ceil(X: oldFilters_8f);
    v28 = *((_DWORD *)this + 18);
    *((_DWORD *)this + 14) = (__int64)oldFilters_8g;
    v29 = (*(int (__thiscall **)(_DWORD, char *, _DWORD, _DWORD, int))(**(_DWORD **)(v28 + 12) + 40))(
            a1: *(_DWORD *)(v28 + 12),
            a2: (char *)this + 36,
            a3: *((_DWORD *)this + 13),
            a4: (__int64)oldFilters_8g,
            a5: 1);
    if ( v29 != 0 )
      InterlockedExchangeAdd(Addend: (volatile LONG *)(v29 + 4), Value: 1);
    v30 = *((_DWORD *)this + 17);
    if ( v30 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v30 + 4), Value: -1) == 1 )
      (**(void (__thiscall ***)(int, int))v30)(a1: v30, a2: 1);
    *((_DWORD *)this + 17) = v29;
    if ( v29 != 0 )
    {
      v31 = *((_BYTE *)this + 20) == 0;
      *((_DWORD *)this + 8) = this->m_Memory.m_pMemory;
      this->m_Memory.m_pMemory = (void **)GRenderer::Cxform::Identity;
      if ( !v31 )
      {
        v32 = *((_DWORD *)this + 18);
        *((_DWORD *)this + 21) = this->m_Memory.m_nGrowSize;
        this->m_Memory.m_nGrowSize = (int)GMatrix3D::Identity;
        (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v32 + 12) + 92))(a1: *(_DWORD *)(v32 + 12), a2: 0);
        *((_BYTE *)this + 20) = 0;
      }
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(*((_DWORD *)this + 18) + 12) + 68))(
        a1: *(_DWORD *)(*((_DWORD *)this + 18) + 12),
        a2: 13);
      ++*((_DWORD *)this + 7);
    }
    else
    {
      GFxDisplayContextFilters::CopyFilterStateFrom(
        this: (GFxDisplayContextFilters *)((char *)this + 24),
        a2: (const struct GFxDisplayContextFilters *)oldFilters);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101077C0
// Name: public: void GFxDisplayContext::EndFilters(class GFxDisplayContextFilters const __near &,class GFxCharacter __near *,class GArray<struct GFxFilterDesc,2,struct GArrayDefaultPolicy> const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayContext::EndFilters(
        CUtlVector<void *,CUtlMemory<void *,int> > *this,
        CUtlVector<void *,CUtlMemory<void *,int> > *oldFilters,
        __vc_attributes::pointer_defaultAttribute a3,
        _DWORD *a4,
        bool finishPrePass)
{
  unsigned int v5; // esi
  int v7; // ecx
  int v8; // eax
  int *v9; // edi
  unsigned int v10; // esi
  bool v11; // dl
  char v12; // al
  bool v13; // zf
  char v14; // cl
  bool v15; // cl
  bool v16; // al
  int v17; // edi
  float *v18; // eax
  int v19; // edx
  double v20; // st7
  int v21; // eax
  double v22; // st7
  int v23; // edx
  int v24; // eax
  double v25; // st7
  int v26; // ecx
  double v27; // st7
  int v28; // edx
  float v29; // edx
  float v30; // eax
  double v31; // st7
  float *v32; // esi
  double v33; // st7
  double v34; // st7
  double v35; // st7
  double v36; // st6
  double v37; // st5
  int v38; // eax
  double v39; // st7
  int v40; // ecx
  double v41; // st7
  int v42; // esi
  float v43; // eax
  int v44; // eax
  int v45; // edi
  struct GFxDisplayContextFilters *v46; // eax
  float v47; // [esp+Ch] [ebp-FCh]
  float v48; // [esp+10h] [ebp-F8h]
  float v49; // [esp+14h] [ebp-F4h]
  float v50; // [esp+18h] [ebp-F0h]
  float v51; // [esp+1Ch] [ebp-ECh]
  float v52; // [esp+20h] [ebp-E8h]
  float v53; // [esp+2Ch] [ebp-DCh]
  _BYTE v54[32]; // [esp+30h] [ebp-D8h] BYREF
  float v55[4]; // [esp+50h] [ebp-B8h] BYREF
  float v56[4]; // [esp+60h] [ebp-A8h] BYREF
  float v57[4]; // [esp+70h] [ebp-98h] BYREF
  _DWORD *v58; // [esp+80h] [ebp-88h]
  struct GFxDisplayContextFilters *v59; // [esp+84h] [ebp-84h]
  int v60; // [esp+88h] [ebp-80h]
  float v61; // [esp+8Ch] [ebp-7Ch]
  int *v62; // [esp+90h] [ebp-78h]
  unsigned int filtercount; // [esp+94h] [ebp-74h]
  unsigned int v64; // [esp+98h] [ebp-70h]
  unsigned int i; // [esp+9Ch] [ebp-6Ch]
  bool bColorFilter; // [esp+A3h] [ebp-65h]
  unsigned int lastfilter; // [esp+A4h] [ebp-64h]
  bool bShadowFilter; // [esp+ABh] [ebp-5Dh]
  float v69; // [esp+ACh] [ebp-5Ch]
  bool bBevelFilter; // [esp+B3h] [ebp-55h]
  _FILETIME cxmatrix; // [esp+B4h] [ebp-54h] BYREF
  float v72; // [esp+BCh] [ebp-4Ch]
  float v73; // [esp+C0h] [ebp-48h] BYREF
  float v74; // [esp+C4h] [ebp-44h]
  float v75; // [esp+C8h] [ebp-40h]
  float v76; // [esp+CCh] [ebp-3Ch]
  float v77; // [esp+D0h] [ebp-38h]
  float v78; // [esp+D4h] [ebp-34h]
  float v79; // [esp+D8h] [ebp-30h]
  float v80; // [esp+DCh] [ebp-2Ch]
  float v81; // [esp+E0h] [ebp-28h]
  float v82[8]; // [esp+E4h] [ebp-24h]

  v59 = (struct GFxDisplayContextFilters *)oldFilters;
  v5 = a4[1];
  v58 = a4;
  v7 = *((_DWORD *)this + 18);
  v64 = v5 - 1;
  lastfilter = v5 - 1;
  v8 = *((_DWORD *)this + 21);
  v9 = *(int **)(v7 + 12);
  v62 = v9;
  filtercount = v5;
  if ( v8 != 0 )
    (*(void (__thiscall **)(int *, int))(*v9 + 92))(a1: v9, a2: v8);
  if ( !finishPrePass )
    (*(void (__thiscall **)(int *))(*v9 + 36))(a1: v9);
  if ( *((_BYTE *)this + 24) != 0 )
  {
    ++lastfilter;
    filtercount = v64;
    v5 = v64;
  }
  i = 0;
  if ( v5 != 0 )
  {
    v64 = 0;
    do
    {
      v10 = v64 + *v58;
      v11 = *(float *)(v10 + 12) > 0.0 && (*(_BYTE *)v10 & 0xF) == 1;
      v12 = *(_BYTE *)(v10 + 35);
      if ( v12 == 0 || (v13 = (*(_BYTE *)v10 & 0xF) == 0, bShadowFilter = true, !v13) )
        bShadowFilter = false;
      if ( v12 == 0 || (v14 = *(_BYTE *)v10 & 0xF, bBevelFilter = true, v14 != 3) )
        bBevelFilter = false;
      v15 = v12 != 0 && (*(_BYTE *)v10 & 0xF) == 2;
      v16 = (*(_BYTE *)v10 & 0xF) == 6;
      bColorFilter = v16;
      if ( !v11 && !bShadowFilter && !v15 && !v16 && !bBevelFilter )
        goto LABEL_71;
      (*(void (__thiscall **)(int *, GMatrix2D *))(*v9 + 56))(a1: v9, a2: &GMatrix2D::Identity);
      v60 = 0;
      if ( i != lastfilter )
      {
        v17 = (*(int (__thiscall **)(int *, char *, _DWORD, _DWORD, _DWORD))(*v9 + 40))(
                a1: v9,
                a2: (char *)this + 36,
                a3: *((_DWORD *)this + 13),
                a4: *((_DWORD *)this + 14),
                a5: 0);
        if ( v17 != 0 )
          InterlockedExchangeAdd(Addend: (volatile LONG *)(v17 + 4), Value: 1);
        v60 = v17;
        v13 = v17 == 0;
        v9 = v62;
        if ( !v13 )
          goto LABEL_35;
        lastfilter = i;
        filtercount = i + 1;
      }
      if ( !finishPrePass )
        (*(void (__thiscall **)(int *))(*v9 + 72))(a1: v9);
LABEL_35:
      if ( bColorFilter )
      {
        if ( i == lastfilter )
        {
          v18 = *((float **)this + 8);
          *(float *)&cxmatrix.dwLowDateTime = *(float *)(v10 + 76) * *v18 * v18[6];
          *(float *)&cxmatrix.dwHighDateTime = *(float *)(v10 + 80) * v18[2] * v18[6];
          v72 = *(float *)(v10 + 84) * v18[4] * v18[6];
          v73 = *(float *)(v10 + 88) * v18[6];
          v74 = *(float *)(v10 + 92) * *v18 * v18[6];
          v75 = *(float *)(v10 + 96) * v18[2] * v18[6];
          v76 = *(float *)(v10 + 100) * v18[4] * v18[6];
          v77 = *(float *)(v10 + 104) * v18[6];
          v78 = *(float *)(v10 + 108) * *v18 * v18[6];
          v79 = *(float *)(v10 + 112) * v18[2] * v18[6];
          v80 = *(float *)(v10 + 116) * v18[4] * v18[6];
          v81 = *(float *)(v10 + 120) * v18[6];
          v82[0] = *(float *)(v10 + 124) * *v18 * v18[6];
          v82[1] = *(float *)(v10 + 128) * v18[2] * v18[6];
          v82[2] = *(float *)(v10 + 132) * v18[4] * v18[6];
          v82[3] = *(float *)(v10 + 136) * v18[6];
          v82[4] = *(float *)(v10 + 140) * *v18 * v18[6];
          v82[5] = *(float *)(v10 + 144) * v18[2] * v18[6];
          v82[6] = *(float *)(v10 + 148) * v18[4] * v18[6];
          v82[7] = v18[6] * *(float *)(v10 + 152);
          v19 = *((_DWORD *)this + 13);
          v82[4] = (v18[1] / 255.0 + *(float *)(v10 + 140)) * v18[6];
          v82[5] = (v18[3] / 255.0 + *(float *)(v10 + 144)) * v18[6];
          v82[6] = (v18[5] / 255.0 + *(float *)(v10 + 148)) * v18[6];
          v82[7] = (v18[7] / 255.0 + *(float *)(v10 + 152)) * v18[6];
          v57[0] = 0.0;
          v57[1] = 0.0;
          v20 = (double)*((int *)this + 13);
          if ( v19 < 0 )
            v20 = v20 + 4294967300.0;
          v21 = *((_DWORD *)this + 14);
          v57[2] = v20;
          v22 = (double)*((int *)this + 14);
          if ( v21 < 0 )
            v22 = v22 + 4294967300.0;
          v23 = *v9;
          v57[3] = v22;
          (*(void (__thiscall **)(int *, _DWORD, float *, char *, _FILETIME *))(v23 + 176))(
            a1: v9,
            a2: *((_DWORD *)this + 17),
            a3: v57,
            a4: (char *)this + 36,
            a5: &cxmatrix);
        }
        else
        {
          v24 = *((_DWORD *)this + 13);
          v56[0] = 0.0;
          v56[1] = 0.0;
          v25 = (double)*((int *)this + 13);
          if ( v24 < 0 )
            v25 = v25 + 4294967300.0;
          v26 = *((_DWORD *)this + 14);
          v56[2] = v25;
          v27 = (double)*((int *)this + 14);
          if ( v26 < 0 )
            v27 = v27 + 4294967300.0;
          v28 = *v9;
          v56[3] = v27;
          (*(void (__thiscall **)(int *, _DWORD, float *, char *, unsigned int))(v28 + 176))(
            a1: v9,
            a2: *((_DWORD *)this + 17),
            a3: v56,
            a4: (char *)this + 36,
            a5: v10 + 76);
        }
      }
      else
      {
        v48 = *(float *)(v10 + 12);
        v29 = *(float *)(v10 + 32);
        v49 = *(float *)(v10 + 16);
        v47 = *(float *)(v10 + 8);
        v30 = *(float *)(v10 + 36);
        v51 = *(float *)(v10 + 24);
        v50 = *(float *)(v10 + 20);
        v31 = *(float *)(v10 + 28);
        v32 = (float *)(v10 + 44);
        v52 = v31;
        v53 = *(v32 - 1);
        qmemcpy(v54, v32, sizeof(v54));
        if ( i == lastfilter )
          qmemcpy(v54, *((const void **)this + 8), sizeof(v54));
        v81 = v53;
        v33 = *((float *)this + 15);
        v76 = v50;
        v73 = v47;
        v79 = v29;
        v61 = v33 * 20.0;
        v34 = 20.0 * *((float *)this + 16);
        v80 = v30;
        qmemcpy(v82, v54, sizeof(v82));
        v69 = v34;
        v35 = v61;
        v61 = v48 * v61;
        v36 = 1.0;
        if ( v61 >= 1.0 )
          v74 = v61;
        else
          v74 = 1.0;
        v37 = v69;
        v69 = v49 * v69;
        if ( v69 >= 1.0 )
          v36 = v69;
        v38 = *((_DWORD *)this + 13);
        v75 = v36;
        v77 = v35 * v51;
        v78 = v37 * v52;
        v55[0] = 0.0;
        v55[1] = 0.0;
        v39 = (double)*((int *)this + 13);
        if ( v38 < 0 )
          v39 = v39 + 4294967300.0;
        v40 = *((_DWORD *)this + 14);
        v55[2] = v39;
        v41 = (double)*((int *)this + 14);
        if ( v40 < 0 )
          v41 = v41 + 4294967300.0;
        v55[3] = v41;
        (*(void (__thiscall **)(int *, _DWORD, float *, char *, float *))(*v62 + 172))(
          a1: v62,
          a2: *((_DWORD *)this + 17),
          a3: v55,
          a4: (char *)this + 36,
          a5: &v73);
        v9 = v62;
      }
      if ( i == lastfilter )
      {
        v42 = v60;
      }
      else
      {
        (*(void (__thiscall **)(int *))(*v9 + 36))(a1: v9);
        v42 = v60;
        if ( v60 != 0 )
          InterlockedExchangeAdd(Addend: (volatile LONG *)(v60 + 4), Value: 1);
        v43 = *((float *)this + 17);
        v69 = v43;
        if ( v43 != 0.0
          && InterlockedExchangeAdd(Addend: (volatile LONG *)(LODWORD(v43) + 4), Value: -1) == 1
          && v69 != 0.0 )
        {
          (**(void (__thiscall ***)(float, int))LODWORD(v69))(a1: COERCE_FLOAT(LODWORD(v69)), a2: 1);
        }
        *((_DWORD *)this + 17) = v42;
      }
      if ( v42 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v42 + 4), Value: -1) == 1 )
        (**(void (__thiscall ***)(int, int))v42)(a1: v42, a2: 1);
LABEL_71:
      v64 += 156;
      ++i;
    }
    while ( i < filtercount );
  }
  v44 = *((_DWORD *)this + 21);
  this->m_Memory.m_pMemory = *((void ***)this + 8);
  if ( v44 != 0 )
  {
    this->m_Memory.m_nGrowSize = v44;
    *((_DWORD *)this + 21) = 0;
  }
  --*((_DWORD *)this + 7);
  if ( *((_BYTE *)this + 24) != 0 )
  {
    (*(void (__thiscall **)(int *))(*v9 + 72))(a1: v9);
    if ( *((int *)this + 7) > 0 )
      GFxDisplayContextFilters::CopyFilterStateFrom(this: (GFxDisplayContextFilters *)((char *)this + 24), a2: v59);
  }
  else
  {
    v45 = *((_DWORD *)this + 17);
    if ( v45 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v45 + 4), Value: -1) == 1 )
      (**(void (__thiscall ***)(int, int))v45)(a1: v45, a2: 1);
    v46 = v59;
    *((_DWORD *)this + 17) = 0;
    GFxDisplayContextFilters::CopyFilterStateFrom(this: (GFxDisplayContextFilters *)((char *)this + 24), a2: v46);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107DF0
// Name: public: void GFxDisplayContext::DisplayFilterPrePass(class GFxCharacter __near *,class GArray<struct GFxFilterDesc,2,struct GArrayDefaultPolicy> const __near &,class GTexture __near *,class GRect<float>,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDisplayContext::DisplayFilterPrePass(
        CUtlVector<void *,CUtlMemory<void *,int> > *this,
        void *const *ch,
        _DWORD *a3,
        int a4,
        float mcr,
        float mcr_4,
        float mcr_8,
        float a8,
        unsigned int mcw,
        unsigned int mch)
{
  int v11; // edi

  *((_DWORD *)this + 8) = this->m_Memory.m_pMemory;
  if ( a4 != 0 )
    InterlockedExchangeAdd(Addend: (volatile LONG *)(a4 + 4), Value: 1);
  v11 = *((_DWORD *)this + 17);
  if ( v11 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v11 + 4), Value: -1) == 1 )
    (**(void (__thiscall ***)(int, int))v11)(a1: v11, a2: 1);
  *((_DWORD *)this + 17) = a4;
  *((float *)this + 9) = mcr;
  *((float *)this + 10) = mcr_4;
  *((float *)this + 11) = mcr_8;
  *((float *)this + 12) = a8;
  *((_DWORD *)this + 14) = mch;
  *((_DWORD *)this + 13) = mcw;
  *((float *)this + 15) = GMatrix2D::GetXScale(this: (GMatrix2D *)this + 5);
  *((float *)this + 16) = GMatrix2D::GetYScale(this: (GMatrix2D *)this + 5);
  GFxDisplayContext::EndFilters(
    this,
    oldFilters: (CUtlVector<void *,CUtlMemory<void *,int> > *)((char *)this + 24),
    a3: (__vc_attributes::pointer_defaultAttribute)ch,
    a4: a3,
    finishPrePass: true);
}
