// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxfontglyphpacker.cpp
// Functions: 19
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxfontglyphpacker.h"

//------------------------------------------------------------------------------
// Address: 0x101221C0
// Name: public: class GASObject __near * __near * GHash<class GASObject __near *,class GASObject __near *,class GIdentityHash<class GASObject __near *>,struct GAllocatorGH<class GASObject __near *,2>,struct GHashNode<class GASObject __near *,class GASObject __near *,class GIdentityHash<class GASObject __near *>>,class GHashsetNodeEntry<struct GHashNode<class GASObject __near *,class GASObject __near *,class GIdentityHash<class GASObject __near *>>,struct GHashNode<class GASObject __near *,class GASObject __near *,class GIdentityHash<class GASObject __near *>>::NodeHashF>,class GHashSet<struct GHashNode<class GASObject __near *,class GASObject __near *,class GIdentityHash<class GASObject __near *>>,struct GHashNode<class GASObject __near *,class GASObject __near *,class GIdentityHash<class GASObject __near *>>::NodeHashF,struct GHashNode<class GASObject __near *,class GASObject __near *,class GIdentityHash<class GASObject __near *>>::NodeAltHashF,struct GAllocatorGH<class GASObject __near *,2>,class GHashsetNodeEntry<struct GHashNode<class GASObject __near *,class GASObject __near *,class GIdentityHash<class GASObject __near *>>,struct GHashNode<class GASObject __near *,class GASObject __near *,class GIdentityHash<class GASObject __near *>>::NodeHashF>>>::Get(class GASObject __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GHash<GASObject *,GASObject *,GIdentityHash<GASObject *>,GAllocatorGH<GASObject *,2>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashsetNodeEntry<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF>,GHashSet<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeAltHashF,GAllocatorGH<GASObject *,2>,GHashsetNodeEntry<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF>>>::Get(
        int *this,
        _DWORD *a2)
{
  int v2; // esi
  int Index; // eax
  int v4; // eax

  v2 = *this;
  if ( *this != 0
    && (Index = GHashSetBase<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeAltHashF,GAllocatorGH<GASObject *,2>,GHashsetNodeEntry<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF>>::findIndexCore<GASObject *>(
                  this,
                  a2,
                  a3: *a2 & *(_DWORD *)(v2 + 4))) >= 0
    && (v4 = v2 + 4 * (3 * Index + 3)) != 0 )
  {
    return v4 + 4;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122E40
// Name: public: void GHash<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor,struct GAllocatorLH<class GASString,323>,struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>,class GHashsetNodeEntry_GC<struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>::NodeHashF>,class GHashSet<struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>::NodeHashF,struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>::NodeAltHashF,struct GAllocatorLH<class GASString,323>,class GHashsetNodeEntry_GC<struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>::NodeHashF>>>::Add(class GASString const __near &,class GASSharedObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GHash<GASString,GASSharedObjectPtr,GASStringHashFunctor,GAllocatorLH<GASString,323>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>,GHashSet<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>>::Add(
        CD3D10_BUFFER_DESC *result,
        _IMAGE_SYMBOL_EX *key,
        int a3)
{
  unsigned int Short; // eax
  int src[2]; // [esp+0h] [ebp-8h] BYREF

  src[0] = (int)key;
  Short = key->N.Name.Short;
  src[1] = a3;
  return GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeRef>(
           result,
           (int)src,
           a3: *(_DWORD *)(Short + 12));
}

//------------------------------------------------------------------------------
// Address: 0x10156480
// Name: private: void GFxFontGlyphPacker::rasterizeGlyph(class GImage __near *,struct GFxFontGlyphPacker::GlyphInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontGlyphPacker::rasterizeGlyph(
        GFxFontGlyphPacker *this,
        struct GImage *a2,
        struct GFxFontGlyphPacker::GlyphInfo *a3)
{
  int v4; // eax
  GFxShapeBase *v5; // esi
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  struct GFxFontGlyphPacker::GlyphInfo *v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // esi
  float v12; // [esp+24h] [ebp-Ch]
  float v13; // [esp+24h] [ebp-Ch]
  GFxShapeBase *v14; // [esp+28h] [ebp-8h]
  float v15; // [esp+2Ch] [ebp-4h]
  GRasterizer *v16; // [esp+2Ch] [ebp-4h]
  float v17; // [esp+3Ch] [ebp+Ch]
  struct GFxFontGlyphPacker::GlyphInfo *v18; // [esp+3Ch] [ebp+Ch]

  v4 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)a3 + 12) + 24))(
         a1: *(_DWORD *)(*(_DWORD *)a3 + 12),
         a2: *((_DWORD *)a3 + 1),
         a3: 0);
  v5 = (GFxShapeBase *)v4;
  v14 = (GFxShapeBase *)v4;
  if ( v4 != 0 )
  {
    v15 = 1536.0 / (double)*((int *)this + 3) * 0.5;
    (*(void (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)v4 + 24))(a1: v4, a2: (char *)this + 256, a3: LODWORD(v15));
    v16 = (GFxFontGlyphPacker *)((char *)this + 148);
    GRasterizer::Clear(this: (GFxFontGlyphPacker *)((char *)this + 148));
    v12 = (double)*((int *)this + 3) / 1536.0;
    GRasterizer::AddShape(
      this: (GFxFontGlyphPacker *)((char *)this + 148),
      a2: (GFxFontGlyphPacker *)((char *)this + 256),
      a3: v12,
      a4: -1);
    if ( GRasterizer::SortCells(this: (GFxFontGlyphPacker *)((char *)this + 148)) )
    {
      v6 = *((_DWORD *)this + 59) - *((_DWORD *)this + 57);
      v7 = *((_DWORD *)this + 4);
      v13 = floor(X: *((float *)a3 + 4));
      v8 = v7 + (int)v13;
      v17 = floor(X: *((float *)a3 + 5));
      v9 = (struct GFxFontGlyphPacker::GlyphInfo *)(v7 + (int)v17);
      v10 = 0;
      v11 = v6 + 1;
      v18 = v9;
      if ( v11 != 0 )
      {
        while ( 1 )
        {
          GRasterizer::SweepScanline(this: v16, a2: v10, a3: &a2->pData[a2->Pitch * ((_DWORD)v9 + v10) + v8], a4: 1u);
          if ( ++v10 >= v11 )
            break;
          v9 = v18;
        }
      }
      v5 = v14;
    }
    GFxShapeBase::Release(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101565A0
// Name: public: static float GFxFontPackParams::GetTextureGlyphMaxHeight(class GFxFontResource const __near *)
// Source: json
//------------------------------------------------------------------------------
double __stdcall GFxFontPackParams::GetTextureGlyphMaxHeight(int a1)
{
  int v1; // eax
  int v3; // [esp+0h] [ebp-10h]

  v1 = *(_DWORD *)(a1 + 16);
  v3 = 48;
  if ( v1 != 0 )
    v3 = *(_DWORD *)(v1 + 8);
  return (float)((double)v3 * 0.6666666666666666);
}

//------------------------------------------------------------------------------
// Address: 0x10156820
// Name: public: GFxFontGlyphPacker::GlyphInfo::GlyphInfo(struct GFxFontGlyphPacker::GlyphInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxFontGlyphPacker::GlyphInfo *__thiscall GFxFontGlyphPacker::GlyphInfo::GlyphInfo(
        GFxFontGlyphPacker::GlyphInfo *this,
        const struct GFxFontGlyphPacker::GlyphInfo *a2)
{
  GFxFontGlyphPacker::GlyphInfo *result; // eax
  float v4; // [esp+0h] [ebp-8h]
  float v5; // [esp+4h] [ebp-4h]
  float v6; // [esp+10h] [ebp+8h]
  float v7; // [esp+10h] [ebp+8h]

  result = this;
  *(_DWORD *)result = *(_DWORD *)a2;
  *((_DWORD *)result + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)result + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)result + 3) = *((_DWORD *)a2 + 3);
  v6 = *((float *)a2 + 5);
  v5 = *((float *)a2 + 6);
  v4 = *((float *)a2 + 7);
  *((float *)result + 4) = *((float *)a2 + 4);
  *((float *)result + 5) = v6;
  *((float *)result + 6) = v5;
  *((float *)result + 7) = v4;
  v7 = *((float *)a2 + 9);
  *((float *)result + 8) = *((float *)a2 + 8);
  *((float *)result + 9) = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10156890
// Name: private: void GFxFontGlyphPacker::generateTextures(class GArray<struct GFxFontGlyphPacker::GlyphInfo,2,struct GArrayDefaultPolicy> __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontGlyphPacker::generateTextures(GFxFontGlyphPacker *this, _DWORD *a2, unsigned int a3)
{
  GFxFontGlyphPacker *v3; // ebx
  _DWORD *v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // edx
  IShaderDevice **v8; // esi
  unsigned int j; // esi
  int v10; // ecx
  int (__thiscall *v11)(int, int, int *); // edx
  GImage *v12; // eax
  GImage *v13; // edi
  _DWORD *v14; // eax
  unsigned int v15; // esi
  struct GFxFontGlyphPacker::GlyphInfo *v16; // eax
  int Height; // ecx
  double v18; // st6
  _DWORD *v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // eax
  int v22; // eax
  char v23; // dl
  int v24; // ecx
  int (__thiscall *v25)(int, CInterlockedIntT<int> *); // edx
  GRefCountNTSImpl *v26; // eax
  int v27; // ecx
  int (__thiscall *v28)(int, int, int *); // eax
  int v29; // esi
  GRefCountNTSImpl *v30; // eax
  GRefCountNTSImpl *v31; // ecx
  bool v32; // zf
  int v33; // edi
  int v34; // eax
  int v35; // ecx
  unsigned int v36; // edx
  double v37; // st7
  int v38; // ecx
  double v39; // st7
  int v40; // edx
  double v41; // st7
  int v42; // ecx
  double v43; // st7
  int v44; // eax
  double v45; // st7
  int v46; // ecx
  int (__thiscall *v47)(int, int, int *); // edx
  int v48; // eax
  int v49; // esi
  IShaderDevice *v50; // ebx
  IShaderDevice *v51; // ecx
  double v52; // st7
  double v53; // st6
  IShaderDevice *v54; // ecx
  int v55; // eax
  double v56; // rt1
  double v57; // st6
  GFxTextureGlyphData *v58; // ebx
  IShaderDevice *v59; // ecx
  unsigned int v60; // edx
  CCallQueueT<CTSQueue<CFunctor *,0,1> > X_4; // [esp+4h] [ebp-ACh] BYREF
  int v62; // [esp+34h] [ebp-7Ch]
  int v63; // [esp+38h] [ebp-78h]
  int v64; // [esp+3Ch] [ebp-74h]
  char v65; // [esp+40h] [ebp-70h]
  int v66; // [esp+44h] [ebp-6Ch] BYREF
  int v67; // [esp+48h] [ebp-68h] BYREF
  float v68; // [esp+4Ch] [ebp-64h]
  GFxFontGlyphPacker *v69; // [esp+50h] [ebp-60h]
  int v70; // [esp+54h] [ebp-5Ch] BYREF
  float v71; // [esp+58h] [ebp-58h]
  int v72; // [esp+5Ch] [ebp-54h]
  unsigned int v73; // [esp+60h] [ebp-50h]
  int v74; // [esp+64h] [ebp-4Ch]
  int v75; // [esp+68h] [ebp-48h]
  float v76; // [esp+6Ch] [ebp-44h]
  float v77; // [esp+70h] [ebp-40h]
  float v78; // [esp+74h] [ebp-3Ch]
  float v79; // [esp+78h] [ebp-38h]
  float v80; // [esp+7Ch] [ebp-34h]
  float v81; // [esp+80h] [ebp-30h]
  __int64 v82; // [esp+84h] [ebp-2Ch]
  float v83; // [esp+8Ch] [ebp-24h]
  float v84; // [esp+90h] [ebp-20h]
  unsigned int i; // [esp+94h] [ebp-1Ch]
  float v86; // [esp+98h] [ebp-18h]
  float v87; // [esp+9Ch] [ebp-14h]
  GRefCountNTSImpl *v88; // [esp+A0h] [ebp-10h]
  float v89; // [esp+A4h] [ebp-Ch]
  float v90; // [esp+A8h] [ebp-8h]
  IShaderDevice *v91; // [esp+ACh] [ebp-4h]

  v3 = this;
  v69 = this;
  for ( i = 0; i < a3; ++i )
  {
    v4 = a2;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v90 = 0.0;
    v89 = 0.0;
    if ( a2[1] != 0 )
    {
      v88 = nullptr;
      do
      {
        v8 = (IShaderDevice **)((char *)v88 + *v4);
        if ( v8[3] == (IShaderDevice *)i )
        {
          v91 = v8[6];
          *(float *)&v91 = ceil(X: *(float *)&v91);
          if ( (int)*(float *)&v91 > SLODWORD(v90) )
          {
            v90 = *((float *)v8 + 6);
            v90 = ceil(X: v90);
            v82 = (__int64)v90;
            v90 = *(float *)&v82;
          }
          v91 = v8[7];
          *(float *)&v91 = ceil(X: *(float *)&v91);
          if ( (int)*(float *)&v91 > SLODWORD(v89) )
          {
            v89 = *((float *)v8 + 7);
            v89 = ceil(X: v89);
            v82 = (__int64)v89;
            v89 = *(float *)&v82;
          }
        }
        v4 = a2;
        v88 += 5;
        ++v5;
      }
      while ( v5 < a2[1] );
      v7 = LODWORD(v89);
      v6 = LODWORD(v90);
    }
    j = *((_DWORD *)v3 + 6);
    v91 = *((IShaderDevice **)v3 + 5);
    if ( v6 <= (unsigned int)v91 >> 1 )
    {
      v91 = (IShaderDevice *)1;
      if ( v6 > 1 )
      {
        do
          v91 = (IShaderDevice *)(2 * (_DWORD)v91);
        while ( (unsigned int)v91 < v6 );
      }
    }
    if ( v7 <= j >> 1 )
    {
      for ( j = 1; j < v7; j *= 2 )
        ;
    }
    v10 = *((_DWORD *)v3 + 11);
    v11 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v10 + 40);
    v66 = 3;
    v12 = (GImage *)v11(a1: v10, a2: 48, a3: &v66);
    if ( v12 != nullptr )
    {
      v13 = GImage::GImage(this: v12, a2: IMAGE_FORMAT_RGB888_BLUESCREEN, a3: (unsigned int)v91, a4: j);
      v89 = *(float *)&v13;
    }
    else
    {
      v89 = 0.0;
      v13 = nullptr;
    }
    memset(dst: v13->pData, value: 0, count: (_DWORD)v91 * j);
    v14 = a2;
    v15 = 0;
    if ( a2[1] != 0 )
    {
      v90 = 0.0;
      do
      {
        v16 = (struct GFxFontGlyphPacker::GlyphInfo *)(LODWORD(v90) + *v14);
        if ( *((_DWORD *)v16 + 3) == i )
          GFxFontGlyphPacker::rasterizeGlyph(this: v3, a2: v13, a3: v16);
        v14 = a2;
        LODWORD(v90) += 40;
        ++v15;
      }
      while ( v15 < a2[1] );
    }
    Height = v13->Height;
    v71 = 1.0 / (double)v13->Width;
    v18 = (double)(int)v13->Height;
    if ( Height < 0 )
      v18 = v18 + 4294967300.0;
    v19 = *((_DWORD **)v3 + 7);
    HIDWORD(v82) = *v19;
    *v19 = HIDWORD(v82) + 1;
    v20 = *((_DWORD *)v3 + 9);
    X_4.m_queue.m_Count.m_value = 1;
    v21 = *((_DWORD *)v3 + 10);
    X_4.m_queue.m_FreeNodes.m_Head.value64 = 0x100000000LL;
    X_4.m_nCurSerialNumber = 0;
    *(&X_4.m_nBreakSerialNumber + 1) = v21;
    v22 = *((_DWORD *)v3 + 11);
    v62 = 0;
    v63 = 0;
    v23 = *((_BYTE *)v3 + 332);
    X_4.m_nBreakSerialNumber = v20;
    v24 = *((_DWORD *)v3 + 8);
    v65 = v23;
    v64 = v22;
    *(_DWORD *)&X_4.m_bNoQueue = v13;
    *((_DWORD *)&X_4.m_queue.m_Count + 1) = 3;
    v25 = *(int (__thiscall **)(int, CInterlockedIntT<int> *))(*(_DWORD *)v24 + 4);
    v68 = 1.0 / v18;
    v26 = (GRefCountNTSImpl *)v25(a1: v24, a2: &X_4.m_queue.m_Count);
    v27 = *((_DWORD *)v3 + 11);
    v88 = v26;
    v28 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v27 + 40);
    v70 = 2;
    v29 = v28(a1: v27, a2: 28, a3: &v70);
    if ( v29 != 0 )
    {
      *(_DWORD *)v29 = &GFxResource::`vftable';
      *(_DWORD *)(v29 + 4) = 1;
      *(_DWORD *)(v29 + 8) = 0;
      *(_DWORD *)v29 = &GFxImageResource::`vftable';
      *(_DWORD *)(v29 + 12) = 0;
      GFxResourceKey::GFxResourceKey(this: (GFxValue *)(v29 + 16));
      v30 = v88;
      if ( v88 != nullptr )
        ++v88->RefCount;
      v31 = *(GRefCountNTSImpl **)(v29 + 12);
      if ( v31 != nullptr )
      {
        GRefCountNTSImpl::Release(this: v31);
        v30 = v88;
      }
      *(_DWORD *)(v29 + 12) = v30;
      *(_DWORD *)(v29 + 24) = 3;
      v91 = (IShaderDevice *)v29;
    }
    else
    {
      *(float *)&v91 = 0.0;
      v30 = v88;
    }
    v32 = a2[1] == 0;
    v90 = 0.0;
    if ( !v32 )
    {
      v33 = 0;
      do
      {
        v34 = *a2;
        v35 = *(_DWORD *)(*a2 + v33);
        v83 = *(float *)(*a2 + v33 + 16);
        v36 = *(_DWORD *)(v34 + v33 + 4);
        v37 = *(float *)(v34 + v33 + 20);
        v72 = v35;
        v84 = v37;
        v38 = *(_DWORD *)(v34 + v33 + 8);
        v39 = *(float *)(v34 + v33 + 24);
        v73 = v36;
        v87 = v39;
        v40 = *(_DWORD *)(v34 + v33 + 12);
        v41 = *(float *)(v34 + v33 + 28);
        v74 = v38;
        v86 = v41;
        v75 = v40;
        v76 = v83;
        v77 = v84;
        v78 = v87;
        v79 = v86;
        v86 = *(float *)(v34 + v33 + 32);
        v87 = *(float *)(v34 + v33 + 36);
        v80 = v86;
        v81 = v87;
        if ( v38 != -1 )
        {
          v42 = 5 * v38;
          v43 = *(float *)(v34 + 8 * v42 + 16);
          v44 = v34 + 8 * v42;
          v86 = v43;
          v40 = *(_DWORD *)(v44 + 12);
          v45 = *(float *)(v44 + 20);
          v75 = v40;
          v87 = v45;
          v84 = *(float *)(v44 + 24);
          v83 = *(float *)(v44 + 28);
          v76 = v86;
          v77 = v87;
          v78 = v84;
          v79 = v83;
          v86 = *(float *)(v44 + 32);
          v87 = *(float *)(v44 + 36);
          v80 = v86;
          v81 = v87;
        }
        if ( v40 == i )
        {
          v46 = *((_DWORD *)v3 + 11);
          v47 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v46 + 40);
          v67 = 261;
          v48 = v47(a1: v46, a2: 40, a3: &v67);
          if ( v48 != 0 )
          {
            *(_DWORD *)v48 = &GRefCountImplCore::`vftable';
            *(_DWORD *)(v48 + 4) = 1;
            *(_DWORD *)v48 = &GFxTextureGlyph::`vftable';
            *(_DWORD *)(v48 + 8) = 0;
            *(_DWORD *)(v48 + 12) = 0;
            *(float *)(v48 + 16) = 0.0;
            *(float *)(v48 + 20) = 0.0;
            v49 = v48;
            *(float *)(v48 + 24) = 0.0;
            *(float *)(v48 + 28) = 0.0;
          }
          else
          {
            v49 = 0;
          }
          v50 = v91;
          if ( *(float *)&v91 != 0.0 )
            GRefCountImpl::AddRef(this: v91);
          if ( *(_DWORD *)(v49 + 8) == 0 )
          {
            v51 = *(IShaderDevice **)(v49 + 12);
            if ( v51 != nullptr )
              GFxResource::Release(this: v51);
          }
          v52 = v76;
          *(_DWORD *)(v49 + 8) = 0;
          v53 = v71;
          *(_DWORD *)(v49 + 12) = v50;
          v54 = v91;
          v55 = v72;
          v56 = v53;
          *(float *)(v49 + 16) = v52 * v53;
          v57 = v68;
          *(float *)(v49 + 20) = v77 * v68;
          *(float *)(v49 + 24) = v78 * v56;
          *(float *)(v49 + 28) = v79 * v57;
          *(float *)(v49 + 32) = v56 * v80;
          *(float *)(v49 + 36) = v57 * v81;
          v58 = *(GFxTextureGlyphData **)(v55 + 16);
          if ( v54 != nullptr )
            GRefCountImpl::AddRef(this: v54);
          if ( *(_DWORD *)(v49 + 8) == 0 )
          {
            v59 = *(IShaderDevice **)(v49 + 12);
            if ( v59 != nullptr )
              GFxResource::Release(this: v59);
          }
          v60 = v73;
          X_4.m_queue.m_Head.value.pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)v49;
          *(float *)(v49 + 12) = *(float *)&v91;
          *(_DWORD *)(v49 + 8) = 0;
          GFxTextureGlyphData::AddTextureGlyph(
            this: v58,
            a2: v60,
            result: (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)X_4.m_queue.m_Head.value.pNode);
          X_4.m_queue.m_Head.value.pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)v91;
          GFxTextureGlyphData::AddTexture(
            this: (CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> >,int> *)v58,
            textureId: SHIDWORD(v82),
            pimageRes: X_4);
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v49);
          v3 = v69;
        }
        v33 += 40;
        ++LODWORD(v90);
      }
      while ( LODWORD(v90) < a2[1] );
      v13 = (GImage *)LODWORD(v89);
      v30 = v88;
    }
    if ( *(float *)&v91 != 0.0 )
    {
      GFxResource::Release(this: v91);
      v30 = v88;
    }
    if ( v30 != nullptr )
      GRefCountNTSImpl::Release(this: v30);
    GRefCountNTSImpl::Release(this: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156F80
// Name: private: unsigned int GFxFontGlyphPacker::packGlyphRects(class GArray<struct GFxFontGlyphPacker::GlyphInfo,2,struct GArrayDefaultPolicy> __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontGlyphPacker::packGlyphRects(_DWORD *this, _DWORD *a2, unsigned int a3, unsigned int a4, int a5)
{
  _DWORD *v5; // esi
  unsigned int *v6; // edi
  int v7; // eax
  int v8; // esi
  double v9; // st7
  unsigned int v10; // ecx
  unsigned int v11; // esi
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // edi
  bool v15; // zf
  _DWORD *v16; // eax
  int *v17; // edi
  int v18; // esi
  double v19; // st7
  int v20; // edx
  double v21; // st7
  unsigned int v22; // edx
  int v23; // ecx
  double X; // [esp+0h] [ebp-44h]
  double Xa; // [esp+0h] [ebp-44h]
  double Xb; // [esp+0h] [ebp-44h]
  _DWORD v28[3]; // [esp+14h] [ebp-30h] BYREF
  __int64 v29; // [esp+20h] [ebp-24h]
  float v30; // [esp+28h] [ebp-1Ch]
  __int64 v31; // [esp+2Ch] [ebp-18h]
  int v32; // [esp+34h] [ebp-10h]
  int v33; // [esp+38h] [ebp-Ch]
  _DWORD *v34; // [esp+3Ch] [ebp-8h]
  unsigned int i; // [esp+40h] [ebp-4h]
  float v36; // [esp+50h] [ebp+Ch]
  float v37; // [esp+50h] [ebp+Ch]
  float v38; // [esp+50h] [ebp+Ch]
  float v39; // [esp+50h] [ebp+Ch]
  int v40; // [esp+50h] [ebp+Ch]
  float v41; // [esp+54h] [ebp+10h]
  float v42; // [esp+54h] [ebp+10h]
  float v43; // [esp+54h] [ebp+10h]
  float v44; // [esp+54h] [ebp+10h]

  v5 = this;
  v6 = this + 12;
  *(this + 17) = 0;
  *(this + 21) = 0;
  *(this + 25) = 0;
  *(this + 29) = 0;
  *(this + 33) = 0;
  v34 = this;
  i = a3;
  if ( a3 < a4 )
  {
    v7 = 40 * a3;
    v33 = 40 * a3;
    do
    {
      v8 = v7 + *a2;
      if ( *(_DWORD *)(v8 + 8) == -1 )
      {
        v36 = ceil(X: *(float *)(v8 + 24));
        X = *(float *)(v8 + 16);
        *(double *)&v29 = v36;
        v37 = floor(X);
        v32 = HIWORD(v37) | 0xC00;
        v29 = (__int64)(*(double *)&v29 - v37);
        HIDWORD(v31) = v29;
        v38 = ceil(X: *(float *)(v8 + 28));
        Xa = *(float *)(v8 + 20);
        *(double *)&v29 = v38;
        v39 = floor(X: Xa);
        v9 = *(double *)&v29 - v39;
        v32 = HIWORD(v39) | 0xC00;
        v29 = (__int64)v9;
        v10 = (__int64)v9;
        if ( HIDWORD(v31) != 0 && v10 != 0 && HIDWORD(v31) <= *v6 && v10 <= v6[1] )
        {
          v28[1] = (__int64)v9;
          v28[0] = HIDWORD(v31);
          v28[2] = i;
          GArrayPagedBase<GRectPacker::RectType,8,64,GAllocatorPagedLH_POD<GRectPacker::RectType,2>>::PushBack(
            this: v6 + 5,
            a2: v28);
        }
        else
        {
          v11 = v6[21] >> 6;
          if ( v11 >= v6[22] )
            GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::allocatePage(
              this: v6 + 21,
              a2: v6[21] >> 6);
          *(_DWORD *)(*(_DWORD *)(v6[24] + 4 * v11) + 4 * (v6[21]++ & 0x3F)) = i;
        }
      }
      v7 = v33 + 40;
      ++i;
      v33 += 40;
    }
    while ( i < a4 );
    v5 = v34;
  }
  GRectPacker::Pack(this: (GRectPacker *)v6);
  v12 = 0;
  for ( i = 0; v12 < v5[25]; i = v12 )
  {
    v13 = *(_DWORD *)(v5[28] + 4 * (v12 >> 4));
    v14 = v12 & 0xF;
    v15 = *(_DWORD *)(v13 + 8 * v14 + 4) == 0;
    v16 = (_DWORD *)(v13 + 8 * v14);
    v33 = (int)v16;
    v40 = 0;
    if ( !v15 )
    {
      while ( 1 )
      {
        v17 = (int *)(*(_DWORD *)(v5[24] + 4 * ((unsigned int)(v40 + *v16) >> 8))
                    + 12 * (unsigned __int8)(v40 + *(_BYTE *)v16));
        v18 = *a2 + 40 * v17[2];
        v41 = ceil(X: *(float *)(v18 + 24));
        *((float *)&v31 + 1) = v41;
        v32 = *(int *)(v18 + 16);
        v19 = ceil(X: *(float *)(v18 + 28));
        v20 = *v17;
        v42 = v19;
        v30 = v42;
        *((float *)&v29 + 1) = *(float *)(v18 + 20);
        v21 = (double)*v17;
        if ( v20 < 0 )
          v21 = v21 + 4294967300.0;
        *(float *)(v18 + 32) = v21 - *(float *)(v18 + 16);
        *(float *)(v18 + 36) = (double)(unsigned int)v17[1] - *(float *)(v18 + 20);
        *(float *)(v18 + 16) = (float)(unsigned int)*v17;
        *(float *)(v18 + 20) = (float)(unsigned int)v17[1];
        *(double *)&v31 = *((float *)&v31 + 1);
        v43 = floor(X: *(float *)&v32);
        v31 = (__int64)(*(double *)&v31 - v43);
        *(float *)(v18 + 24) = (float)(unsigned int)(*v17 + v31);
        Xb = *((float *)&v29 + 1);
        *(double *)&v29 = v30;
        v44 = floor(X: Xb);
        v29 = (__int64)(*(double *)&v29 - v44);
        v22 = i;
        *(float *)(v18 + 28) = (float)(unsigned int)(v17[1] + v29);
        v23 = v33;
        *(_DWORD *)(v18 + 12) = a5 + v22;
        v5 = v34;
        if ( (unsigned int)++v40 >= *(_DWORD *)(v23 + 4) )
          break;
        v16 = (_DWORD *)v33;
      }
      v12 = i;
    }
    ++v12;
  }
  return a5 + v5[25];
}

//------------------------------------------------------------------------------
// Address: 0x101572C0
// Name: private: unsigned int GFxFontGlyphPacker::packGlyphRects(class GArray<struct GFxFontGlyphPacker::GlyphInfo,2,struct GArrayDefaultPolicy> __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontGlyphPacker::packGlyphRects(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // ebx
  int v3; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // edx
  int v10; // [esp+10h] [ebp+8h]

  v2 = this;
  v3 = 0;
  if ( *(_BYTE *)(*(this + 2) + 28) == 0 )
    return GFxFontGlyphPacker::packGlyphRects(this, a2, a3: 0, a4: a2[1], a5: 0);
  v5 = 1;
  v6 = 0;
  if ( a2[1] > 1u )
  {
    v7 = 40;
    v10 = 40;
    do
    {
      v2 = this;
      if ( *(_DWORD *)(*a2 + v7 - 40) != *(_DWORD *)(*a2 + v7) )
      {
        v3 = GFxFontGlyphPacker::packGlyphRects(this, a2, a3: v6, a4: v5, a5: v3);
        v6 = v5;
      }
      ++v5;
      v7 = v10 + 40;
      v10 += 40;
    }
    while ( v5 < a2[1] );
  }
  return GFxFontGlyphPacker::packGlyphRects(this: v2, a2, a3: v6, a4: a2[1], a5: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10157350
// Name: public: unsigned int __near * GHash<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey,struct GAllocatorLH<struct GFxFontGlyphPacker::GlyphGeometryKey,2>,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>,class GHashsetCachedNodeEntry<struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>,class GHashSet<struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,struct GAllocatorLH<struct GFxFontGlyphPacker::GlyphGeometryKey,2>,class GHashsetCachedNodeEntry<struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>>>::Get(struct GFxFontGlyphPacker::GlyphGeometryKey const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GHash<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>,GHashSet<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>>>::Get(
        _DWORD *this,
        _DWORD *a2)
{
  int v3; // eax
  int v4; // eax

  if ( *this != 0
    && (v3 = GHashSetBase<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>>::findIndexCore<GFxFontGlyphPacker::GlyphGeometryKey>(
               this,
               a2,
               a3: *(_DWORD *)(*this + 4) & (*a2 ^ a2[2] ^ (*a2 >> 6)))) >= 0
    && (v4 = *this + 24 * v3 + 16) != 0 )
  {
    return v4 + 12;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10157500
// Name: public: GFxFontGlyphPacker::GFxFontGlyphPacker(class GFxFontPackParams __near *,class GFxImageCreator __near *,class GFxRenderConfig __near *,class GFxLog __near *,class GFxResourceId __near *,class GMemoryHeap __near *,bool)
// Source: json
//------------------------------------------------------------------------------
GFxFontGlyphPacker *__thiscall GFxFontGlyphPacker::GFxFontGlyphPacker(
        GFxFontGlyphPacker *this,
        struct GFxFontPackParams *a2,
        IShaderDevice *a3,
        IShaderDevice *a4,
        IShaderDevice *a5,
        struct GFxResourceId *a6,
        struct GMemoryHeap *a7,
        bool a8)
{
  _DWORD *v9; // eax
  int v10; // ecx

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 2) = a2;
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxFontGlyphPacker::`vftable';
  *((_DWORD *)this + 3) = 48;
  *((_DWORD *)this + 4) = 3;
  *((_DWORD *)this + 5) = 1024;
  *((_DWORD *)this + 6) = 1024;
  *((_DWORD *)this + 7) = a6;
  if ( a3 != nullptr )
    GRefCountImpl::AddRef(this: a3);
  *((_DWORD *)this + 8) = a3;
  if ( a4 != nullptr )
    GRefCountImpl::AddRef(this: a4);
  *((_DWORD *)this + 9) = a4;
  if ( a5 != nullptr )
    GRefCountImpl::AddRef(this: a5);
  *((_DWORD *)this + 10) = a5;
  *((_DWORD *)this + 11) = a7;
  GRectPacker::GRectPacker(this: (GFxFontGlyphPacker *)((char *)this + 48));
  GRasterizer::GRasterizer(this: (GFxFontGlyphPacker *)((char *)this + 148));
  *((float *)this + 64) = 1.0;
  *((float *)this + 65) = 0.0625;
  *((_DWORD *)this + 66) = 0;
  *((_DWORD *)this + 67) = 0;
  *((_DWORD *)this + 68) = 0;
  *((_DWORD *)this + 69) = 0;
  *((_DWORD *)this + 70) = 0;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 72) = 0;
  *((_DWORD *)this + 73) = 0;
  *((float *)this + 77) = 1.0;
  *((float *)this + 78) = 1.0;
  *((_DWORD *)this + 74) = 0;
  *((_DWORD *)this + 75) = 0x7FFFFFFF;
  *((float *)this + 79) = 0.0;
  *((_DWORD *)this + 76) = -2147483647;
  *((float *)this + 80) = 0.0;
  *((_BYTE *)this + 324) = 0;
  *((_DWORD *)this + 82) = 0;
  *((_BYTE *)this + 332) = a8;
  v9 = *((_DWORD **)this + 2);
  if ( v9 != nullptr )
  {
    *((_DWORD *)this + 3) = v9[3];
    *((_DWORD *)this + 4) = v9[4];
    *((_DWORD *)this + 5) = v9[5];
    *((_DWORD *)this + 6) = v9[6];
  }
  v10 = *((_DWORD *)this + 6);
  *((_DWORD *)this + 12) = *((_DWORD *)this + 5);
  *((_DWORD *)this + 13) = v10;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10157650
// Name: public: virtual GFxFontGlyphPacker::~GFxFontGlyphPacker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontGlyphPacker::~GFxFontGlyphPacker(GFxFontGlyphPacker *this)
{
  IShaderAPI *v2; // ecx
  IShaderAPI *v3; // ecx
  IShaderAPI *v4; // ecx

  *(_DWORD *)this = &GFxFontGlyphPacker::`vftable';
  GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>::~GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>(this: (int *)this + 82);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 70);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 66);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 49));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 46));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 42);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 39));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 33);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 29);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 25);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 21);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 17);
  v2 = *((IShaderAPI **)this + 10);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  v3 = *((IShaderAPI **)this + 9);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = *((IShaderAPI **)this + 8);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10157910
// Name: public: void GHash<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey,struct GAllocatorLH<struct GFxFontGlyphPacker::GlyphGeometryKey,2>,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>,class GHashsetCachedNodeEntry<struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>,class GHashSet<struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,struct GAllocatorLH<struct GFxFontGlyphPacker::GlyphGeometryKey,2>,class GHashsetCachedNodeEntry<struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>,struct GHashNode<struct GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,struct GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>>>::Add(struct GFxFontGlyphPacker::GlyphGeometryKey const __near &,unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GHash<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>,GHashSet<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>>>::Add(
        int *this,
        int *a2,
        int *a3)
{
  int v3; // edx
  int v4; // esi
  int *v6[2]; // [esp+4h] [ebp-8h] BYREF

  v6[1] = a3;
  v3 = *a2;
  v4 = a2[2] ^ ((unsigned int)*a2 >> 6);
  v6[0] = a2;
  return GHashSetBase<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>>::add<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeRef>(
           this,
           a2: this,
           a3: v6,
           a4: v3 ^ v4);
}

//------------------------------------------------------------------------------
// Address: 0x10157950
// Name: private: void GFxFontGlyphPacker::generateGlyphInfo(class GArray<struct GFxFontGlyphPacker::GlyphInfo,2,struct GArrayDefaultPolicy> __near *,class GFxFontResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontGlyphPacker::generateGlyphInfo(_DWORD *this, int *pheapAddr, int a3)
{
  int v5; // ecx
  int (__thiscall *v6)(int); // edx
  int v7; // ecx
  int (__thiscall *v8)(int, int, float *); // eax
  GFxTextureGlyphData *v9; // esi
  unsigned int v10; // eax
  GFxTextureGlyphData *v11; // esi
  GRefCountNTSImpl *v12; // ecx
  int v13; // ecx
  int (__thiscall *v14)(int); // eax
  unsigned int v15; // ebx
  GLock *TextureGlyph; // eax
  int v17; // eax
  GFxShapeBase *v18; // esi
  void (__thiscall *v19)(int, float *); // edx
  int v20; // edx
  int (__thiscall *v21)(_DWORD); // eax
  int v22; // eax
  int *v23; // eax
  int v24[2]; // [esp+8h] [ebp-58h] BYREF
  int v25; // [esp+10h] [ebp-50h]
  int v26; // [esp+14h] [ebp-4Ch]
  float v27; // [esp+18h] [ebp-48h]
  float v28; // [esp+1Ch] [ebp-44h]
  float v29; // [esp+20h] [ebp-40h]
  float v30; // [esp+24h] [ebp-3Ch]
  float v31; // [esp+28h] [ebp-38h]
  float v32; // [esp+2Ch] [ebp-34h]
  float v33; // [esp+30h] [ebp-30h] BYREF
  float v34; // [esp+34h] [ebp-2Ch]
  float v35; // [esp+38h] [ebp-28h]
  float v36; // [esp+3Ch] [ebp-24h]
  int v37[3]; // [esp+40h] [ebp-20h] BYREF
  unsigned int v38; // [esp+4Ch] [ebp-14h]
  int v39; // [esp+50h] [ebp-10h] BYREF
  float v40; // [esp+54h] [ebp-Ch]
  float v41; // [esp+58h] [ebp-8h] BYREF
  _DWORD *v42; // [esp+5Ch] [ebp-4h]
  int v43; // [esp+6Ch] [ebp+Ch]

  v5 = *(_DWORD *)(a3 + 12);
  v6 = *(int (__thiscall **)(int))(*(_DWORD *)v5 + 56);
  v42 = this;
  if ( v6(a1: v5) != 0 )
  {
    v7 = *(this + 11);
    v8 = *(int (__thiscall **)(int, int, float *))(*(_DWORD *)v7 + 40);
    LODWORD(v41) = 261;
    v9 = (GFxTextureGlyphData *)v8(a1: v7, a2: 52, a3: &v41);
    if ( v9 != nullptr )
    {
      v10 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 12) + 56))(a1: *(_DWORD *)(a3 + 12));
      v11 = GFxTextureGlyphData::GFxTextureGlyphData(this: v9, a2: v10, a3: false);
      v43 = (int)v11;
    }
    else
    {
      v43 = 0;
      v11 = nullptr;
    }
    *((_DWORD *)v11 + 2) = *(this + 3);
    *((_DWORD *)v11 + 3) = *(this + 4);
    *((_DWORD *)v11 + 4) = *(this + 5);
    *((_DWORD *)v11 + 5) = *(this + 6);
    ++*((_DWORD *)v11 + 1);
    v12 = *(GRefCountNTSImpl **)(a3 + 16);
    if ( v12 != nullptr )
      GRefCountNTSImpl::Release(this: v12);
    *(_DWORD *)(a3 + 16) = v11;
    v13 = *(_DWORD *)(a3 + 12);
    v14 = *(int (__thiscall **)(int))(*(_DWORD *)v13 + 56);
    v40 = (double)(int)*(this + 3) / 1536.0;
    v15 = 0;
    v38 = v14(a1: v13);
    if ( v38 != 0 )
    {
      do
      {
        TextureGlyph = GFxTextureGlyphData::GetTextureGlyph(this: v11, a2: v15);
        if ( TextureGlyph->cs.RecursionCount == 0 && TextureGlyph->cs.OwningThread == nullptr )
        {
          v17 = (*(int (__thiscall **)(_DWORD, unsigned int, _DWORD))(**(_DWORD **)(a3 + 12) + 24))(
                  a1: *(_DWORD *)(a3 + 12),
                  a2: v15,
                  a3: 0);
          v18 = (GFxShapeBase *)v17;
          if ( v17 != 0 )
          {
            v19 = *(void (__thiscall **)(int, float *))(*(_DWORD *)v17 + 20);
            v33 = 0.0;
            v34 = 0.0;
            v35 = 0.0;
            v36 = 0.0;
            v19(a1: v17, a2: &v33);
            v41 = v35 - v33;
            if ( v41 > 0.0 )
            {
              v41 = v36 - v34;
              if ( v41 > 0.0 )
              {
                v41 = (float)(int)v42[4];
                v27 = v33 * v40 - v41;
                v28 = v34 * v40 - v41;
                v29 = v35 * v40 + v41;
                v30 = v41 + v40 * v36;
                v31 = 0.0;
                v32 = 0.0;
                v41 = v29 - v27;
                if ( v41 > 0.0 )
                {
                  v41 = v30 - v28;
                  if ( v41 > 0.0 )
                  {
                    v20 = *(_DWORD *)v18;
                    v25 = -1;
                    v26 = -1;
                    v21 = *(int (__thiscall **)(_DWORD))(v20 + 28);
                    v24[0] = a3;
                    v24[1] = v15;
                    v22 = v21(a1: v18);
                    v37[0] = a3;
                    v37[1] = (int)v18;
                    v37[2] = v22;
                    v23 = (int *)GHash<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>,GHashSet<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>>>::Get(
                                   this: v42 + 82,
                                   a2: v37);
                    if ( v23 != nullptr )
                    {
                      v25 = *v23;
                    }
                    else
                    {
                      v39 = pheapAddr[1];
                      GHash<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>,GHashSet<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,GAllocatorLH<GFxFontGlyphPacker::GlyphGeometryKey,2>,GHashsetCachedNodeEntry<GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>,GHashNode<GFxFontGlyphPacker::GlyphGeometryKey,unsigned int,GFxFontGlyphPacker::GlyphGeometryKey>::NodeHashF>>>::Add(
                        this: v42 + 82,
                        a2: v37,
                        a3: &v39);
                    }
                    GArrayBase<GArrayData<GFxFontGlyphPacker::GlyphInfo,GAllocatorGH<GFxFontGlyphPacker::GlyphInfo,2>,GArrayDefaultPolicy>>::PushBack(
                      pheapAddr,
                      a2: (const struct GFxFontGlyphPacker::GlyphInfo *)v24);
                  }
                }
              }
            }
            GFxShapeBase::Release(this: v18);
          }
          v11 = (GFxTextureGlyphData *)v43;
        }
        ++v15;
      }
      while ( v15 < v38 );
    }
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10157BC0
// Name: public: void GFxFontGlyphPacker::GenerateFontBitmaps(class GArray<class GFxFontResource __near *,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontGlyphPacker::GenerateFontBitmaps(GFxFontGlyphPacker *this, _DWORD *a2)
{
  unsigned int v2; // eax
  unsigned int v3; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  bool v11; // zf
  _DWORD *v12; // eax
  unsigned int i; // edi
  int v14; // eax
  unsigned int v15; // eax
  ButtonCode_t pheapAddr[3]; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v18; // [esp+18h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v18 = 0;
  if ( a2[1] != 0 )
  {
    do
    {
      v5 = *(_DWORD *)(*a2 + 4 * v3);
      if ( *(_DWORD *)(v5 + 16) == 0
        && (*(_DWORD *)(*((_DWORD *)this + 2) + 32) == 0
         || (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v5 + 12) + 56))(a1: *(_DWORD *)(v5 + 12)) <= *(_DWORD *)(*((_DWORD *)this + 2) + 32)) )
      {
        v6 = *(_DWORD *)(*(_DWORD *)(*a2 + 4 * v3) + 12);
        v18 += (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 56))(a1: v6);
      }
      ++v3;
    }
    while ( v3 < a2[1] );
    v2 = v18;
  }
  memset(pheapAddr, 0, sizeof(pheapAddr));
  if ( v2 != 0 )
    GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)pheapAddr,
      (ButtonCode_t)pheapAddr,
      newCapacity: v2);
  v7 = *((_DWORD *)this + 82);
  if ( v7 != 0 )
  {
    v8 = 0;
    v9 = *(_DWORD *)(v7 + 4) + 1;
    do
    {
      v10 = *((_DWORD *)this + 82);
      v11 = *(_DWORD *)(v8 + v10 + 8) == -2;
      v12 = (_DWORD *)(v8 + v10 + 8);
      if ( !v11 )
        *v12 = -2;
      v8 += 24;
      --v9;
    }
    while ( v9 != 0 );
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 82));
    *((_DWORD *)this + 82) = 0;
  }
  for ( i = 0; i < a2[1]; ++i )
  {
    v14 = *(_DWORD *)(*a2 + 4 * i);
    if ( *(_DWORD *)(v14 + 16) == 0
      && (*(_DWORD *)(*((_DWORD *)this + 2) + 32) == 0
       || (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v14 + 12) + 56))(a1: *(_DWORD *)(v14 + 12)) <= *(_DWORD *)(*((_DWORD *)this + 2) + 32)) )
    {
      GFxFontGlyphPacker::generateGlyphInfo(this, (int *)pheapAddr, a3: *(_DWORD *)(*a2 + 4 * i));
    }
  }
  v15 = GFxFontGlyphPacker::packGlyphRects(this, a2: pheapAddr);
  GFxFontGlyphPacker::generateTextures(this, a2: pheapAddr, a3: v15);
  return ((int (__thiscall *)(GMemoryHeap *, ButtonCode_t))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: pheapAddr[0]);
}

//------------------------------------------------------------------------------
// Address: 0x10157D00
// Name: void GFx_GenerateFontBitmaps(class GFxFontPackParams __near *,class GArray<class GFxFontResource __near *,2,struct GArrayDefaultPolicy> const __near &,class GFxImageCreator __near *,class GFxRenderConfig __near *,class GFxLog __near *,class GFxResourceId __near *,class GMemoryHeap __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_GenerateFontBitmaps(
        int a1,
        _DWORD *a2,
        IShaderDevice *a3,
        IShaderDevice *a4,
        IShaderDevice *a5,
        struct GFxResourceId *a6,
        struct GMemoryHeap *a7,
        bool a8)
{
  struct GFxFontPackParams *v8; // edi
  IShaderDevice *v9; // esi
  GFxFontGlyphPacker *v10; // eax
  GFxFontGlyphPacker *v11; // esi

  v8 = (struct GFxFontPackParams *)a1;
  if ( a1 != 0 )
  {
    v9 = a3;
    if ( a3 != nullptr )
    {
      a1 = 2;
      v10 = (GFxFontGlyphPacker *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 336, a3: &a1);
      if ( v10 != nullptr )
        v11 = GFxFontGlyphPacker::GFxFontGlyphPacker(this: v10, a2: v8, a3: v9, a4, a5, a6, a7, a8);
      else
        v11 = nullptr;
      GFxFontGlyphPacker::GenerateFontBitmaps(this: v11, a2);
      if ( v11 != nullptr )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B910
// Name: public: void GHash<class GFxTextFormat const __near *,class GPtr<class GFxFontHandle>,class GIdentityHash<class GFxTextFormat const __near *>,struct GAllocatorDH<class GFxTextFormat const __near *,324>,struct GHashNode<class GFxTextFormat const __near *,class GPtr<class GFxFontHandle>,class GIdentityHash<class GFxTextFormat const __near *>>,class GHashsetNodeEntry<struct GHashNode<class GFxTextFormat const __near *,class GPtr<class GFxFontHandle>,class GIdentityHash<class GFxTextFormat const __near *>>,struct GHashNode<class GFxTextFormat const __near *,class GPtr<class GFxFontHandle>,class GIdentityHash<class GFxTextFormat const __near *>>::NodeHashF>,class GHashSetDH<struct GHashNode<class GFxTextFormat const __near *,class GPtr<class GFxFontHandle>,class GIdentityHash<class GFxTextFormat const __near *>>,struct GHashNode<class GFxTextFormat const __near *,class GPtr<class GFxFontHandle>,class GIdentityHash<class GFxTextFormat const __near *>>::NodeHashF,struct GHashNode<class GFxTextFormat const __near *,class GPtr<class GFxFontHandle>,class GIdentityHash<class GFxTextFormat const __near *>>::NodeAltHashF,324,class GHashsetNodeEntry<struct GHashNode<class GFxTextFormat const __near *,class GPtr<class GFxFontHandle>,class GIdentityHash<class GFxTextFormat const __near *>>,struct GHashNode<class GFxTextFormat const __near *,class GPtr<class GFxFontHandle>,class GIdentityHash<class GFxTextFormat const __near *>>::NodeHashF>>>::Set(class GFxTextFormat const __near * const __near &,class GPtr<class GFxFontHandle> const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *__thiscall GHash<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>,GAllocatorDH<GFxTextFormat const *,324>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashsetNodeEntry<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF>,GHashSetDH<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeAltHashF,324,GHashsetNodeEntry<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF>>>::Set(
        int this,
        int *a2,
        _DWORD *a3)
{
  int v3; // ebx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **v5; // edi
  int v6; // eax
  _DWORD *v8[2]; // [esp+Ch] [ebp-8h] BYREF

  v3 = *a2;
  v5 = *(CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> ***)this;
  v8[0] = a2;
  v8[1] = a3;
  if ( v5 != nullptr
    && (v6 = GHashSetBase<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeAltHashF,GAllocatorDH<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,324>,GHashsetNodeEntry<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF>>::findIndexCore<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeRef>(
               (int *)this,
               a2: v8,
               a3: v3 & (unsigned int)v5[1])) >= 0 )
  {
    return GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::operator=(
             this: &v5[3 * v6 + 3],
             a2: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> ***)v8);
  }
  else
  {
    return GHashSetBase<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeAltHashF,GAllocatorDH<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,324>,GHashsetNodeEntry<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>,GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeHashF>>::add<GHashNode<GFxTextFormat const *,GPtr<GFxFontHandle>,GIdentityHash<GFxTextFormat const *>>::NodeRef>(
             (void **)this,
             a2: *(_DWORD *)(this + 4),
             a3: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> ***)v8,
             a4: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101800C0
// Name: public: struct GFxGlyphNode __near * __near * GHash<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam,struct GAllocatorLH<struct GFxGlyphParam,195>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,class GHashsetCachedNodeEntry<struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeHashF>,class GHashSet<struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeHashF,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeAltHashF,struct GAllocatorLH<struct GFxGlyphParam,195>,class GHashsetCachedNodeEntry<struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeHashF>>>::Get(struct GFxGlyphParam const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GHash<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam,GAllocatorLH<GFxGlyphParam,195>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>,GHashSet<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>>::Get(
        int *this,
        int a2)
{
  int Index; // eax
  int v4; // eax

  Index = GHashSetBase<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>::findIndexAlt<GFxGlyphParam>(
            this,
            a2);
  if ( Index >= 0 && (v4 = *this + 24 * Index + 16) != 0 )
    return v4 + 12;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101819F0
// Name: public: void GHash<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam,struct GAllocatorLH<struct GFxGlyphParam,195>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,class GHashsetCachedNodeEntry<struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeHashF>,class GHashSet<struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeHashF,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeAltHashF,struct GAllocatorLH<struct GFxGlyphParam,195>,class GHashsetCachedNodeEntry<struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeHashF>>>::Add(struct GFxGlyphParam const __near &,struct GFxGlyphNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GHash<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam,GAllocatorLH<GFxGlyphParam,195>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>,GHashSet<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>>::Add(
        int *this,
        int a2,
        int *a3)
{
  int v3; // esi
  int v4; // edi
  int *v6[2]; // [esp+8h] [ebp-8h] BYREF

  v3 = *(unsigned __int8 *)(a2 + 7)
     ^ *(unsigned __int8 *)(a2 + 8)
     ^ *(unsigned __int8 *)(a2 + 10)
     ^ *(unsigned __int8 *)(a2 + 11)
     ^ (2 * *(unsigned __int8 *)(a2 + 9));
  v4 = *(unsigned __int8 *)(a2 + 6);
  v6[0] = (int *)a2;
  v6[1] = a3;
  return GHashSetBase<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>::add<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeRef>(
           this,
           a2: this,
           a3: v6,
           a4: *(_DWORD *)a2 ^ (*(_DWORD *)a2 >> 6) ^ *(unsigned __int16 *)(a2 + 4) ^ v4 ^ v3);
}

//------------------------------------------------------------------------------
// Address: 0x101843D0
// Name: public: void GHash<unsigned long,class GString,class GFixedSizeHash<unsigned long>,struct GAllocatorGH<unsigned long,2>,struct GHashNode<unsigned long,class GString,class GFixedSizeHash<unsigned long>>,class GHashsetCachedNodeEntry<struct GHashNode<unsigned long,class GString,class GFixedSizeHash<unsigned long>>,struct GHashNode<unsigned long,class GString,class GFixedSizeHash<unsigned long>>::NodeHashF>,class GHashSet<struct GHashNode<unsigned long,class GString,class GFixedSizeHash<unsigned long>>,struct GHashNode<unsigned long,class GString,class GFixedSizeHash<unsigned long>>::NodeHashF,struct GHashNode<unsigned long,class GString,class GFixedSizeHash<unsigned long>>::NodeAltHashF,struct GAllocatorGH<unsigned long,2>,class GHashsetCachedNodeEntry<struct GHashNode<unsigned long,class GString,class GFixedSizeHash<unsigned long>>,struct GHashNode<unsigned long,class GString,class GFixedSizeHash<unsigned long>>::NodeHashF>>>::Add(unsigned long const __near &,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GHash<unsigned long,GString,GFixedSizeHash<unsigned long>,GAllocatorGH<unsigned long,2>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeHashF>,GHashSet<GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeHashF,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeAltHashF,GAllocatorGH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeHashF>>>::Add(
        GDelegatedFile *a1@<ecx>,
        int a2@<ebx>,
        int a3,
        int a4)
{
  int v4; // eax
  int v5; // edx
  int v6; // edi
  _DWORD v7[2]; // [esp+8h] [ebp-8h] BYREF

  v7[1] = a4;
  v7[0] = a3;
  v4 = 4;
  v5 = 5381;
  do
  {
    v6 = *(unsigned __int8 *)(v4 + a3 - 1);
    --v4;
    v5 = v6 + 65599 * v5;
  }
  while ( v4 != 0 );
  GHashSetBase<GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeHashF,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeAltHashF,GAllocatorGH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeHashF>>::add<GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeRef>(
    a1,
    a2,
    a3: (int)a1,
    a4: (int)v7,
    a5: v5);
}
