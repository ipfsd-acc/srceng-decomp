// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/text/gfxtexthighlight.cpp
// Functions: 22
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\text\gfxtexthighlight.h"

//------------------------------------------------------------------------------
// Address: 0x1017AD30
// Name: public: bool GFxTextHighlighterPosIterator::IsFinished(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxTextHighlighterPosIterator::IsFinished(GFxTextHighlighterPosIterator *this)
{
  return this->spare >= (void *)*(_DWORD *)this->name;
}

//------------------------------------------------------------------------------
// Address: 0x1017ADA0
// Name: public: void GFxTextHighlighter::UpdateGlyphIndices(class GFxTextCompositionString const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighter::UpdateGlyphIndices(GFxResourceId *this, GFxResourceId *a2)
{
  int v3; // eax
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // edi
  int v8; // edi
  int i; // [esp+8h] [ebp-4h]
  const struct GFxTextCompositionString *v10; // [esp+14h] [ebp+8h]

  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 4) = 0;
  if ( a2 != nullptr )
  {
    *(this + 4) = a2[12];
    *((_DWORD *)this + 5) = GFxTextParagraph::GetLength(this: a2 + 5);
  }
  v3 = *((_DWORD *)this + 1);
  *((_WORD *)this + 12) = 0;
  if ( v3 != 0 )
  {
    v10 = nullptr;
    for ( i = v3; i != 0; --i )
    {
      v4 = (unsigned int *)((char *)v10 + this->Id);
      v5 = *v4;
      v6 = v4[1];
      v4[3] = *v4;
      v4[4] = v6;
      if ( *((_DWORD *)this + 5) != 0 )
      {
        v7 = *((_DWORD *)this + 4);
        if ( v6 != 0 )
        {
          if ( v5 > v7 )
            goto LABEL_13;
          if ( v7 < v6 + v5 )
          {
            v8 = v4[2];
            if ( v8 < 0 )
              v4[4] = v6 + *((_DWORD *)this + 5);
            else
              v4[3] = v5 + v8;
            goto LABEL_14;
          }
        }
        if ( v5 > v7 )
LABEL_13:
          v4[3] = v5 + *((_DWORD *)this + 5);
      }
LABEL_14:
      v10 = (const struct GFxTextCompositionString *)((char *)v10 + 40);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017AE40
// Name: public: bool GFxTextHighlighter::HasUnderlineHighlight(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighter::HasUnderlineHighlight(IVJobs *this)
{
  unsigned int v1; // esi
  int v2; // eax
  void (__thiscall **i)(IVJobs *); // edx

  if ( *((_BYTE *)this + 25) == 0 )
  {
    v1 = *((_DWORD *)this + 1);
    v2 = 0;
    *((_BYTE *)this + 25) = -1;
    if ( v1 != 0 )
    {
      for ( i = &this->AfterReload; (*(_BYTE *)i & 7) == 0; i += 10 )
      {
        if ( ++v2 >= v1 )
          return;
      }
      *((_BYTE *)this + 25) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017AE90
// Name: public: void GFxTextHighlighter::SetSelectColor(class GColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighter::SetSelectColor(GFxTextHighlighter *this, const struct GColor *a2)
{
  int v2; // edx
  int v3; // eax

  v2 = *((_DWORD *)this + 1);
  v3 = 0;
  if ( v2 != 0 )
  {
    do
    {
      *(struct GColor *)(v3 + *(_DWORD *)this + 24) = *a2;
      v3 += 40;
      --v2;
    }
    while ( v2 != 0 );
    *((_WORD *)this + 12) = 0;
  }
  else
  {
    *((_WORD *)this + 12) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017AED0
// Name: public: bool GFxTextHighlighter::IsAnyCharSelected(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextHighlighter::IsAnyCharSelected(
        GFxTextHighlighter *this,
        unsigned int selectStart,
        unsigned int selectEnd)
{
  unsigned int v3; // edi
  int v4; // edx
  unsigned int *i; // ecx
  unsigned int v6; // eax

  v3 = *((_DWORD *)this + 1);
  v4 = 0;
  if ( v3 == 0 )
    return 0;
  for ( i = *(unsigned int **)this; ; i += 10 )
  {
    v6 = *i;
    if ( *i > selectStart )
      goto LABEL_6;
    if ( selectStart < v6 + i[1] )
      return 1;
    if ( v6 >= selectStart )
    {
LABEL_6:
      if ( v6 < selectEnd )
        break;
    }
    if ( ++v4 >= v3 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017AF20
// Name: public: bool GFxTextHighlighterRangeIterator::IsFinished(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighterRangeIterator::IsFinished(IVJobs *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1017AF40
// Name: public: struct GFxTextHighlightDesc __near * GFxTextHighlighter::GetHighlighterPtr(unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFxTextHighlightDesc *__thiscall GFxTextHighlighter::GetHighlighterPtr(
        GFxTextHighlighter *this,
        unsigned int id)
{
  unsigned int v3; // eax
  int v4; // ecx
  struct GFxTextHighlightDesc *result; // eax

  v3 = G_LowerBoundSliced<GArrayLH<GFxTextHighlightDesc,2,GArrayDefaultPolicy>,unsigned int,int (__cdecl *)(GFxTextHighlightDesc const &,unsigned int)>(
         a1: this,
         a2: 0,
         a3: *((_DWORD *)this + 1),
         a4: &id,
         a5: `anonymous namespace'::IdComparator::Less);
  if ( v3 >= *((_DWORD *)this + 1) )
    return nullptr;
  v4 = *(_DWORD *)(*(_DWORD *)this + 40 * v3 + 20);
  result = (struct GFxTextHighlightDesc *)(*(_DWORD *)this + 40 * v3);
  if ( v4 != id )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017AF80
// Name: private: void GFxTextHighlighterRangeIterator::InitCurDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighterRangeIterator::InitCurDesc(GFxTextHighlighterRangeIterator *this)
{
  int v1; // eax
  int v3; // ecx
  int v4; // esi
  unsigned int v5; // edx
  unsigned __int8 *v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // edx
  char v9; // dl
  unsigned int v10; // esi
  unsigned int v11; // ebx
  int v12; // [esp+Ch] [ebp-3Ch]
  int v13; // [esp+10h] [ebp-38h]
  int v14; // [esp+14h] [ebp-34h]
  int v15; // [esp+18h] [ebp-30h]
  int v16; // [esp+20h] [ebp-28h]
  int v17; // [esp+24h] [ebp-24h]
  int v18; // [esp+28h] [ebp-20h]
  int v19; // [esp+2Ch] [ebp-1Ch]
  char v20; // [esp+30h] [ebp-18h]
  unsigned int v21; // [esp+34h] [ebp-14h]
  int v22; // [esp+3Ch] [ebp-Ch]
  _DWORD *v23; // [esp+40h] [ebp-8h]
  unsigned int v24; // [esp+44h] [ebp-4h]

  v1 = 0;
  v3 = 0;
  v12 = -1;
  v13 = 0;
  v14 = -1;
  v15 = 0;
  v4 = 0;
  v16 = 0;
  v19 = 0;
  v18 = 0;
  v17 = 0;
  v20 = 0;
  do
  {
    v5 = -1;
    v24 = -1;
    if ( *(_DWORD *)(*(_DWORD *)this + 4) != 0 )
    {
      v23 = **(_DWORD ***)this;
      v6 = (unsigned __int8 *)(v23 + 9);
      v22 = *(_DWORD *)(*(_DWORD *)this + 4);
      while ( (*((_DWORD *)this + 13) & *v6) == 0 )
      {
LABEL_30:
        v23 += 10;
        v6 += 40;
        if ( --v22 == 0 )
        {
          v1 = v13;
          goto LABEL_32;
        }
      }
      v7 = *((_DWORD *)this + 1);
      if ( *((_DWORD *)v6 - 5) != 0 )
      {
        v8 = *((_DWORD *)v6 - 6);
        if ( v7 >= v8 )
        {
          v21 = v8 + *((_DWORD *)v6 - 5);
          if ( v7 < v21 )
          {
            if ( v13 == 0 )
            {
              v12 = *v23;
              v13 = *((_DWORD *)v6 - 8);
              v14 = *((_DWORD *)v6 - 7);
              v16 = *((_DWORD *)v6 - 4);
              v17 = *((_DWORD *)v6 - 3);
              v18 = *((_DWORD *)v6 - 2);
              v19 = *((_DWORD *)v6 - 1);
              v4 = v8 - v7 + *((_DWORD *)v6 - 5);
              v20 = *v6;
              v3 = *((_DWORD *)this + 1);
              v15 = v3;
              if ( v8 + *((_DWORD *)v6 - 5) > v24 )
                v4 = v24 - v7;
              goto LABEL_24;
            }
            if ( (*((_DWORD *)this + 13) & *v6) != *((_DWORD *)this + 13) )
            {
              v9 = *v6;
              if ( (*v6 & 7) != 0 )
                v20 = *v6 & 7 | v20 & 0xF8;
              if ( (v9 & 8) != 0 )
              {
                v20 |= 8u;
                v17 = *((_DWORD *)v6 - 3);
              }
              if ( (v9 & 0x10) != 0 )
              {
                v20 |= 0x10u;
                v18 = *((_DWORD *)v6 - 2);
              }
              if ( (v9 & 0x20) != 0 )
              {
                v20 |= 0x20u;
                v19 = *((_DWORD *)v6 - 1);
              }
              v3 = v15;
              v10 = v15 + v4;
              if ( v21 < v10 )
                v10 = v21;
              v4 = v10 - v15;
              v24 = v4 + v15;
              goto LABEL_24;
            }
          }
          v3 = v15;
        }
      }
LABEL_24:
      v11 = *((_DWORD *)v6 - 6);
      v5 = v24;
      if ( v11 > *((_DWORD *)this + 1) )
      {
        if ( v24 >= v11 )
        {
          v5 = *((_DWORD *)v6 - 6);
          v24 = v5;
        }
        if ( v13 != 0 && v4 + v3 > v5 )
          v4 = v5 - v3;
      }
      goto LABEL_30;
    }
LABEL_32:
    *((_DWORD *)this + 3) = v12;
    *((_DWORD *)this + 5) = v14;
    *((_DWORD *)this + 8) = v16;
    *((_DWORD *)this + 4) = v1;
    *((_DWORD *)this + 6) = v3;
    *((_DWORD *)this + 7) = v4;
    *((_DWORD *)this + 9) = v17;
    *((_DWORD *)this + 10) = v18;
    *((_DWORD *)this + 11) = v19;
    *((_BYTE *)this + 48) = v20;
    *((_DWORD *)this + 1) = v5;
  }
  while ( v1 == 0 && v5 != -1 );
}

//------------------------------------------------------------------------------
// Address: 0x1017B150
// Name: public: struct GFxTextHighlightDesc GFxTextHighlighterRangeIterator::operator*(void)
// Source: json
//------------------------------------------------------------------------------
IPrecacheHandler *__thiscall GFxTextHighlighterRangeIterator::operator*(
        IPrecacheHandler *this,
        const IPrecacheHandler *a2)
{
  a2->__vftable = (IPrecacheHandler_vtbl *)*(this + 3);
  a2[1].__vftable = (IPrecacheHandler_vtbl *)*(this + 4);
  a2[2].__vftable = (IPrecacheHandler_vtbl *)*(this + 5);
  a2[3].__vftable = (IPrecacheHandler_vtbl *)*(this + 6);
  a2[4].__vftable = (IPrecacheHandler_vtbl *)*(this + 7);
  a2[5].__vftable = (IPrecacheHandler_vtbl *)*(this + 8);
  a2[6].__vftable = (IPrecacheHandler_vtbl *)*(this + 9);
  a2[7].__vftable = (IPrecacheHandler_vtbl *)*(this + 10);
  a2[8].__vftable = (IPrecacheHandler_vtbl *)*(this + 11);
  LOBYTE(a2[9].__vftable) = *((_BYTE *)this + 48);
  return (IPrecacheHandler *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x1017B1A0
// Name: public: void GFxTextHighlighterRangeIterator::operator++(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighterRangeIterator::operator++(int this, int a2)
{
  if ( *(_DWORD *)(this + 8) < *(_DWORD *)(*(_DWORD *)this + 4) && *(_DWORD *)(this + 28) != 0 )
    GFxTextHighlighterRangeIterator::InitCurDesc((GFxTextHighlighterRangeIterator *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1017B1C0
// Name: private: void GFxTextHighlighterPosIterator::InitCurDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighterPosIterator::InitCurDesc(GFxTextHighlighterPosIterator *this)
{
  char v1; // al
  _BYTE *v2; // esi
  int v3; // edi
  unsigned int v4; // edx
  void *spare; // ebx
  char v6; // bl
  void *v7; // eax
  int v8; // [esp+18h] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+20h] [ebp-Ch]
  int v11; // [esp+28h] [ebp-4h]

  if ( this->spare >= (void *)*(_DWORD *)this->name )
  {
    *(_DWORD *)&this->name[36] = 0;
    *(_DWORD *)&this->name[32] = 0;
    *(_DWORD *)&this->name[28] = 0;
    this->name[40] = 0;
    *(_DWORD *)&this->name[20] = 0;
    *(_DWORD *)&this->name[16] = this->spare;
    *(_DWORD *)&this->name[24] = 0;
  }
  else
  {
    v1 = 0;
    v10 = 0;
    v9 = 0;
    v8 = 0;
    if ( *((_DWORD *)this->pVFTable + 1) != 0 )
    {
      v2 = (_BYTE *)(*(_DWORD *)this->pVFTable + 36);
      v11 = *((_DWORD *)this->pVFTable + 1);
      do
      {
        v3 = *((_DWORD *)v2 - 5);
        if ( v3 != 0 )
        {
          v4 = *((_DWORD *)v2 - 6);
          spare = this->spare;
          if ( (unsigned int)spare >= v4 && (unsigned int)spare < v3 + v4 )
          {
            v6 = *v2;
            if ( (*v2 & 7) != 0 )
              v1 = *v2 & 7 | v1 & 0xF8;
            if ( (v6 & 8) != 0 )
            {
              v1 |= 8u;
              v8 = *((_DWORD *)v2 - 3);
            }
            if ( (v6 & 0x10) != 0 )
            {
              v1 |= 0x10u;
              v9 = *((_DWORD *)v2 - 2);
            }
            if ( (v6 & 0x20) != 0 )
            {
              v1 |= 0x20u;
              v10 = *((_DWORD *)v2 - 1);
            }
          }
        }
        v2 += 40;
        --v11;
      }
      while ( v11 != 0 );
    }
    *(_DWORD *)&this->name[4] = -1;
    *(_DWORD *)&this->name[12] = -1;
    *(_DWORD *)&this->name[8] = 0;
    *(_DWORD *)&this->name[16] = 0;
    *(_DWORD *)&this->name[24] = 0;
    *(_DWORD *)&this->name[28] = v8;
    *(_DWORD *)&this->name[32] = v9;
    *(_DWORD *)&this->name[36] = v10;
    this->name[40] = v1;
    v7 = this->spare;
    *(_DWORD *)&this->name[20] = 1;
    *(_DWORD *)&this->name[16] = v7;
    *(_DWORD *)&this->name[24] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017B2B0
// Name: public: void GFxTextHighlighterPosIterator::operator+=(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighterPosIterator::operator+=(
        CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this,
        unsigned int p)
{
  CRefCountServiceBase<1,CRefMT>_vtbl *m_nUserID; // eax

  m_nUserID = (CRefCountServiceBase<1,CRefMT>_vtbl *)this->m_nUserID;
  if ( m_nUserID < this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable
    && p != 0 )
  {
    this->m_nUserID = (unsigned int)m_nUserID + p;
    GFxTextHighlighterPosIterator::InitCurDesc((GFxTextHighlighterPosIterator *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017B3C0
// Name: public: GFxTextHighlighter::GFxTextHighlighter(void)
// Source: json
//------------------------------------------------------------------------------
GFxTextHighlighter *__thiscall GFxTextHighlighter::GFxTextHighlighter(GFxTextHighlighter *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_WORD *)this + 12) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017B3E0
// Name: public: class GFxTextHighlighterPosIterator GFxTextHighlighter::GetPosIterator(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
struct GFxTextHighlighterPosIterator *__thiscall GFxTextHighlighter::GetPosIterator(
        GFxTextHighlighter *this,
        GFxTextHighlighterPosIterator *retstr,
        void *a3,
        unsigned int a4)
{
  int v4; // ecx

  retstr->pVFTable = this;
  retstr->spare = a3;
  *(_DWORD *)retstr->name = a4;
  *(_DWORD *)&retstr->name[4] = -1;
  *(_DWORD *)&retstr->name[8] = 0;
  *(_DWORD *)&retstr->name[12] = -1;
  *(_DWORD *)&retstr->name[16] = 0;
  *(_DWORD *)&retstr->name[20] = 0;
  *(_DWORD *)&retstr->name[24] = 0;
  *(_DWORD *)&retstr->name[36] = 0;
  *(_DWORD *)&retstr->name[32] = 0;
  *(_DWORD *)&retstr->name[28] = 0;
  retstr->name[40] = 0;
  GFxTextHighlighterPosIterator::InitCurDesc(this: retstr);
  return (struct GFxTextHighlighterPosIterator *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1017B430
// Name: public: class GFxTextHighlighterRangeIterator GFxTextHighlighter::GetRangeIterator(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighter::GetRangeIterator(
        IResourceAccessControl *this,
        GFxTextHighlighterRangeIterator *startPos,
        unsigned int flags,
        const char *flagsa)
{
  *(_DWORD *)startPos = this;
  *((_DWORD *)startPos + 1) = flags;
  *((_DWORD *)startPos + 2) = 0;
  *((_DWORD *)startPos + 3) = -1;
  *((_DWORD *)startPos + 5) = -1;
  *((_DWORD *)startPos + 4) = 0;
  *((_DWORD *)startPos + 6) = 0;
  *((_DWORD *)startPos + 7) = 0;
  *((_DWORD *)startPos + 8) = 0;
  *((_DWORD *)startPos + 11) = 0;
  *((_DWORD *)startPos + 10) = 0;
  *((_DWORD *)startPos + 9) = 0;
  *((_BYTE *)startPos + 48) = 0;
  *((_DWORD *)startPos + 13) = flagsa;
  GFxTextHighlighterRangeIterator::InitCurDesc(this: startPos);
}

//------------------------------------------------------------------------------
// Address: 0x1017B510
// Name: public: void GFxTextHighlighter::DrawBackground(class GFxDrawingContext __near &,class GFxTextLineBuffer __near &,class GRect<float> const __near &,unsigned int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighter::DrawBackground(
        void *this,
        IClientTools *a2,
        int *a3,
        float *a4,
        int a5,
        float a6,
        float a7)
{
  int v8; // esi
  int v9; // eax
  _DWORD *v10; // ecx
  double v11; // st6
  double v12; // st7
  float v13; // esi
  unsigned int v14; // edi
  unsigned int v15; // eax
  int v16; // eax
  bool v17; // dl
  unsigned int v18; // ecx
  int v19; // edi
  CFunctor *FormatData; // eax
  int v21; // edx
  int v22; // esi
  int v23; // edi
  unsigned int v24; // ecx
  unsigned int v25; // eax
  struct GFxFontHandle *v26; // esi
  GFxFontManager *v27; // ecx
  IShaderDevice *v28; // ecx
  IShaderDevice *v29; // ecx
  IShaderDevice *v30; // ecx
  volatile LONG *v31; // edi
  CMemoryStack *m_pAllocator; // edi
  char *v33; // esi
  CFunctor *v34; // eax
  char *v35; // esi
  CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *v36; // edi
  CFunctor *NonNegLeading; // eax
  int v38; // eax
  double v39; // st7
  double v40; // st7
  double v41; // st7
  double v42; // st7
  double v43; // st7
  int v44; // eax
  unsigned int v45; // ecx
  unsigned int v46; // eax
  CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *v47; // ecx
  CMemoryStack *v48; // edx
  double v49; // st7
  double v50; // st6
  double v51; // st5
  double v52; // st4
  double v53; // st3
  double v54; // st5
  double v55; // st5
  double v56; // st4
  double v57; // rt2
  double v58; // rtt
  double v59; // st4
  double v60; // st6
  int *v61; // eax
  int v62; // eax
  struct GFxFontHandle *v63; // esi
  GFxFontManager *v64; // ecx
  IShaderDevice *v65; // ecx
  IShaderDevice *v66; // ecx
  IShaderDevice *v67; // ecx
  volatile LONG *v68; // edi
  int *v69; // eax
  int v70; // eax
  float x; // [esp+0h] [ebp-1B4h]
  float v72; // [esp+4h] [ebp-1B0h]
  const FlashlightState_t *v73; // [esp+8h] [ebp-1ACh]
  float v74; // [esp+14h] [ebp-1A0h]
  _DWORD *v75; // [esp+1Ch] [ebp-198h] BYREF
  unsigned int v76; // [esp+24h] [ebp-190h]
  unsigned int v77; // [esp+30h] [ebp-184h] BYREF
  unsigned int v78; // [esp+34h] [ebp-180h]
  CFunctor *v79; // [esp+38h] [ebp-17Ch]
  _DWORD v80[15]; // [esp+3Ch] [ebp-178h] BYREF
  int v81; // [esp+78h] [ebp-13Ch]
  struct GFxFontHandle *v82; // [esp+7Ch] [ebp-138h]
  GRefCountNTSImpl *v83; // [esp+80h] [ebp-134h]
  int v84; // [esp+84h] [ebp-130h]
  unsigned int v85; // [esp+88h] [ebp-12Ch]
  char *v86; // [esp+8Ch] [ebp-128h] BYREF
  char *v87; // [esp+90h] [ebp-124h]
  CFunctor *v88; // [esp+94h] [ebp-120h]
  _DWORD v89[15]; // [esp+98h] [ebp-11Ch] BYREF
  int v90; // [esp+D4h] [ebp-E0h]
  struct GFxFontHandle *v91; // [esp+D8h] [ebp-DCh]
  GRefCountNTSImpl *v92; // [esp+DCh] [ebp-D8h]
  int v93; // [esp+E0h] [ebp-D4h]
  unsigned int v94; // [esp+E4h] [ebp-D0h]
  int v95; // [esp+E8h] [ebp-CCh] BYREF
  int v96; // [esp+ECh] [ebp-C8h] BYREF
  float v97; // [esp+F0h] [ebp-C4h]
  float v98; // [esp+F4h] [ebp-C0h]
  float v99; // [esp+F8h] [ebp-BCh]
  float v100; // [esp+FCh] [ebp-B8h]
  float v101; // [esp+100h] [ebp-B4h]
  float v102; // [esp+104h] [ebp-B0h]
  int v103[2]; // [esp+108h] [ebp-ACh] BYREF
  unsigned int v104; // [esp+110h] [ebp-A4h]
  int v105; // [esp+114h] [ebp-A0h]
  int v106; // [esp+118h] [ebp-9Ch]
  int v107; // [esp+11Ch] [ebp-98h]
  unsigned int v108; // [esp+120h] [ebp-94h]
  int v109; // [esp+124h] [ebp-90h]
  int v110; // [esp+128h] [ebp-8Ch]
  int v111; // [esp+12Ch] [ebp-88h]
  int v112; // [esp+130h] [ebp-84h]
  int v113; // [esp+134h] [ebp-80h]
  char v114; // [esp+138h] [ebp-7Ch]
  int v115; // [esp+13Ch] [ebp-78h]
  float v116; // [esp+140h] [ebp-74h]
  float v117; // [esp+144h] [ebp-70h]
  float v118; // [esp+148h] [ebp-6Ch]
  float v119; // [esp+14Ch] [ebp-68h]
  float v120; // [esp+150h] [ebp-64h]
  float v121; // [esp+154h] [ebp-60h]
  float v122; // [esp+158h] [ebp-5Ch]
  float v123; // [esp+15Ch] [ebp-58h]
  float v124; // [esp+160h] [ebp-54h]
  float v125; // [esp+164h] [ebp-50h]
  float v126; // [esp+168h] [ebp-4Ch]
  float v127; // [esp+16Ch] [ebp-48h]
  int v128; // [esp+170h] [ebp-44h]
  char v129; // [esp+174h] [ebp-40h] BYREF
  __int16 v130; // [esp+175h] [ebp-3Fh]
  char v131; // [esp+177h] [ebp-3Dh]
  char v132; // [esp+178h] [ebp-3Ch] BYREF
  __int16 v133; // [esp+179h] [ebp-3Bh]
  char v134; // [esp+17Bh] [ebp-39h]
  unsigned int v135; // [esp+17Ch] [ebp-38h]
  unsigned int v136; // [esp+180h] [ebp-34h]
  int v137; // [esp+184h] [ebp-30h]
  float v138; // [esp+188h] [ebp-2Ch]
  CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *v139; // [esp+18Ch] [ebp-28h]
  float v140; // [esp+190h] [ebp-24h]
  float v141; // [esp+194h] [ebp-20h]
  float v142; // [esp+198h] [ebp-1Ch]
  float v143; // [esp+19Ch] [ebp-18h]
  float v144; // [esp+1A0h] [ebp-14h]
  float v145; // [esp+1A4h] [ebp-10h]
  float v146; // [esp+1A8h] [ebp-Ch]
  float v147; // [esp+1ACh] [ebp-8h]
  float v148; // [esp+1B0h] [ebp-4h]
  float v149; // [esp+1C8h] [ebp+14h]

  GFxDrawingContext::Clear(this: a2);
  v128 = 0;
  GFxDrawingContext::Clear(this: a2);
  GFxDrawingContext::SetNonZeroFill(this: a2, fill: (const FlashlightState_t *)1);
  v103[1] = a5;
  v103[0] = (int)this;
  v104 = 0;
  v105 = -1;
  v106 = 0;
  v107 = -1;
  v108 = 0;
  v109 = 0;
  v110 = 0;
  v113 = 0;
  v112 = 0;
  v111 = 0;
  v114 = 0;
  v115 = -1;
LABEL_2:
  GFxTextHighlighterRangeIterator::InitCurDesc(this: (GFxTextHighlighterRangeIterator *)v103);
LABEL_3:
  if ( v104 < *(_DWORD *)(v103[0] + 4) )
  {
    v8 = v109;
    if ( v109 != 0 )
    {
      GFxTextLineBuffer::FindLineByTextPos(a1: a3, a2: v103[0], a3: (int)&v75, textPos: v108);
      v9 = v76;
      v145 = 0.0;
      v10 = v75;
      v146 = 0.0;
      v137 = v8;
      v149 = 0.0 + 0.0;
      v147 = v149;
      v148 = v149;
      v142 = v149;
      v143 = v149;
      v11 = 0.0;
      v12 = v149;
      v140 = 0.0;
      v141 = 0.0;
      while ( 1 )
      {
        if ( v10 == nullptr || (unsigned int)v9 >= v10[1] || v9 < 0 || v137 == 0 )
        {
          if ( v147 > (double)v145 && v148 > (double)v146 )
          {
            v97 = *a4;
            v98 = a4[1];
            v99 = a4[2];
            v100 = a4[3];
            if ( v98 > (double)v148 )
            {
              v145 = v11;
              v146 = v11;
              v147 = v12;
              v148 = v12;
            }
            else if ( v100 < (double)v146 )
            {
              v145 = v11;
              v146 = v11;
              v147 = v12;
              v148 = v12;
            }
            else if ( v99 < (double)v145 )
            {
              v145 = v11;
              v146 = v11;
              v147 = v12;
              v148 = v12;
            }
            else if ( v97 <= (double)v147 )
            {
              if ( v145 <= (double)v97 )
                v145 = v97;
              if ( v147 > (double)v99 )
                v147 = v99;
              if ( v146 <= (double)v98 )
                v146 = v98;
              if ( v148 > (double)v100 )
                v148 = v100;
            }
            else
            {
              v145 = v11;
              v146 = v11;
              v147 = v12;
              v148 = v12;
            }
            if ( v147 > (double)v145 && v148 > (double)v146 )
            {
              if ( (v114 & 8) != 0 )
              {
                v96 = v111;
                v69 = &v96;
              }
              else
              {
                v130 = 0;
                v129 = 0;
                v131 = 0;
                v69 = (int *)&v129;
              }
              v70 = *v69;
              if ( v70 != v128 )
              {
                v128 = v70;
                GFxDrawingContext::SetFill(this: a2, rgba: v70, a3: v73);
              }
              GFxDrawingContext::MoveTo(this: a2, x: (void *)LODWORD(v145), y: v146);
              GFxDrawingContext::LineTo(this: a2, x: (void *)LODWORD(v147), y: v146);
              GFxDrawingContext::LineTo(this: a2, x: (void *)LODWORD(v147), y: v148);
              GFxDrawingContext::LineTo(this: a2, x: (void *)LODWORD(v145), y: v148);
              GFxDrawingContext::LineTo(this: a2, x: (void *)LODWORD(v145), y: v146);
              GFxDrawingContext::AddPath(this: a2);
            }
          }
          if ( v104 < *(_DWORD *)(v103[0] + 4) )
            goto LABEL_2;
          goto LABEL_3;
        }
        v13 = *(float *)(*v10 + 4 * v9);
        *(float *)&v139 = v13;
        v14 = v9;
        GFxTextLineBuffer::GetVScrollOffsetInTwips(this: (CMatCallQueue *)a3);
        v144 = -(double)v15;
        if ( GFxTextLineBuffer::IsLineVisible(
               this: (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)a3,
               lineIndex: v14,
               yOffset: v144) )
        {
          break;
        }
LABEL_139:
        v9 = v76;
        v12 = v149;
        v10 = v75;
        v11 = 0.0;
        if ( v76 < v75[1] )
          v9 = ++v76;
      }
      v16 = *(_DWORD *)(LODWORD(v13) + 8);
      v17 = (int)*(_DWORD *)LODWORD(v13) < 0;
      v18 = v16;
      if ( (int)*(_DWORD *)LODWORD(v13) < 0 )
      {
        v18 = v16 & 0xFFFFFF;
        if ( (v16 & 0xFFFFFF) == 0xFFFFFF )
          v18 = -1;
      }
      if ( v18 >= v108 )
      {
        v136 = 0;
        if ( v17 )
        {
          v16 &= 0xFFFFFFu;
          if ( v16 == 0xFFFFFF )
            v16 = -1;
        }
        v137 = v109 + v108 - v16;
      }
      else
      {
        if ( (int)*(_DWORD *)LODWORD(v13) >= 0 )
          v138 = *(float *)(LODWORD(v13) + 4);
        else
          LODWORD(v138) = *(unsigned __int8 *)(LODWORD(v13) + 28);
        v19 = LODWORD(v13) + 30;
        if ( !v17 )
          v19 = LODWORD(v13) + 42;
        FormatData = GFxTextLineBuffer::Line::GetFormatData(this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)LODWORD(v13));
        v80[3] = -1;
        v80[5] = -1;
        v78 = v19 + 8 * LODWORD(v138);
        v80[4] = 0;
        memset(&v80[6], 0, 25);
        v80[2] = 0;
        v80[1] = 0;
        v80[13] = 0;
        v80[14] = 0;
        v81 = 0;
        v82 = nullptr;
        v83 = nullptr;
        v84 = 0;
        v85 = 0;
        v77 = v19;
        v79 = FormatData;
        GFxTextLineBuffer::GlyphIterator::UpdateDesc(this: &v77);
        v21 = *(_DWORD *)LODWORD(v13);
        v22 = *(_DWORD *)(LODWORD(v13) + 8);
        v136 = 0;
        if ( v21 < 0 )
        {
          v22 &= 0xFFFFFFu;
          if ( v22 == 0xFFFFFF )
            v22 = -1;
        }
        v23 = v108 - v22;
        while ( v23 > 0 )
        {
          if ( v77 == 0 || v77 >= v78 )
            break;
          v24 = *(unsigned __int16 *)(v77 + 4);
          if ( (v24 & 0xF000) != 0 )
          {
            v23 -= v24 >> 12;
            ++v136;
          }
          v25 = v85;
          if ( v85 == 0 )
          {
            v25 = v24 >> 12;
            v85 = v24 >> 12;
          }
          v77 += 8;
          if ( (*(_WORD *)(v77 + 4) & 0xF000) != 0 && v25 != 0 && v80[1] < v80[2] )
          {
            v80[1] += v25;
            GFxTextHighlighterPosIterator::InitCurDesc(this: (GFxTextHighlighterPosIterator *)v80);
            v85 = 0;
          }
          GFxTextLineBuffer::GlyphIterator::UpdateDesc(this: &v77);
        }
        if ( v83 != nullptr )
          GRefCountNTSImpl::Release(this: v83);
        v26 = v82;
        if ( v82 != nullptr )
        {
          --*(_DWORD *)v82;
          if ( *(_DWORD *)v26 == 0 )
          {
            v27 = *((GFxFontManager **)v26 + 1);
            if ( v27 != nullptr )
              GFxFontManager::RemoveFontHandle(this: v27, a2: v26);
            v28 = *((IShaderDevice **)v26 + 7);
            if ( v28 != nullptr )
              GFxResource::Release(this: v28);
            *((_DWORD *)v26 + 7) = 0;
            v29 = *((IShaderDevice **)v26 + 8);
            if ( v29 != nullptr )
              GFxResource::Release(this: v29);
            v30 = *((IShaderDevice **)v26 + 7);
            if ( v30 != nullptr )
              GFxResource::Release(this: v30);
            v31 = (volatile LONG *)(*((_DWORD *)v26 + 3) & 0xFFFFFFFC);
            if ( InterlockedExchangeAdd(Addend: v31 + 1, Value: -1) == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v31);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v26);
          }
        }
      }
      if ( (int)v139->m_pAllocator >= 0 )
        m_pAllocator = v139[1].m_pAllocator;
      else
        m_pAllocator = (CMemoryStack *)LOBYTE(v139[7].m_pAllocator);
      v33 = (char *)&v139[7].m_pAllocator + 2;
      if ( (int)v139->m_pAllocator >= 0 )
        v33 = (char *)&v139[10].m_pAllocator + 2;
      v34 = GFxTextLineBuffer::Line::GetFormatData(this: v139);
      v89[3] = -1;
      v89[5] = -1;
      v87 = &v33[8 * (_DWORD)m_pAllocator];
      v89[4] = 0;
      memset(&v89[6], 0, 25);
      v89[2] = 0;
      v89[1] = 0;
      v89[13] = 0;
      v89[14] = 0;
      v90 = 0;
      v91 = nullptr;
      v92 = nullptr;
      v93 = 0;
      v94 = 0;
      v86 = v33;
      v88 = v34;
      GFxTextLineBuffer::GlyphIterator::UpdateDesc(this: &v86);
      v145 = 0.0;
      v138 = 0.0;
      v146 = 0.0;
      v135 = 0;
      v147 = 0.0 + 0.0;
      v148 = v147;
      while ( 1 )
      {
        v35 = v86;
        if ( v86 == nullptr || v86 >= v87 || v137 == 0 )
          break;
        if ( v135 >= v136 )
        {
          if ( (v86[6] & 0x40) != 0 )
            LODWORD(v144) = -*((unsigned __int16 *)v86 + 1);
          else
            LODWORD(v144) = *((unsigned __int16 *)v86 + 1);
          v36 = v139;
          v126 = (float)SLODWORD(v144);
          v144 = COERCE_FLOAT(GFxTextLineBuffer::Line::GetHeight(this: v139));
          NonNegLeading = GFxTextLineBuffer::Line::GetNonNegLeading(this: v36);
          LODWORD(v144) += NonNegLeading;
          v38 = *((unsigned __int16 *)v35 + 2) >> 12;
          v127 = (float)SLODWORD(v144);
          v137 -= v38;
          v74 = (float)SLODWORD(v138);
          v124 = v74 + 0.0;
          v126 = v74 + v126;
          v125 = 0.0 + 0.0;
          v127 = v127 + 0.0;
          if ( v135 == v136 )
          {
            v145 = v124;
            v146 = v125;
            v147 = v126;
            v39 = v127;
          }
          else
          {
            v40 = v145;
            if ( v124 < (double)v145 )
              v40 = v124;
            v120 = v40;
            v41 = v147;
            if ( v126 >= (double)v147 )
              v41 = v126;
            v122 = v41;
            v42 = v146;
            if ( v125 < (double)v146 )
              v42 = v125;
            v121 = v42;
            v43 = v148;
            if ( v127 >= (double)v148 )
              v43 = v127;
            v123 = v43;
            v145 = v120;
            v146 = v121;
            v147 = v122;
            v39 = v123;
          }
          v148 = v39;
        }
        v44 = *((unsigned __int16 *)v35 + 1);
        if ( (v35[6] & 0x40) != 0 )
          v44 = -v44;
        v45 = *((unsigned __int16 *)v35 + 2);
        LODWORD(v138) += v44;
        if ( (v45 & 0xF000) != 0 )
          ++v135;
        v46 = v94;
        if ( v94 == 0 )
        {
          v46 = v45 >> 12;
          v94 = v45 >> 12;
        }
        v86 = v35 + 8;
        if ( (*((_WORD *)v35 + 6) & 0xF000) != 0 && v46 != 0 && v89[1] < v89[2] )
        {
          v89[1] += v46;
          GFxTextHighlighterPosIterator::InitCurDesc(this: (GFxTextHighlighterPosIterator *)v89);
          v94 = 0;
        }
        GFxTextLineBuffer::GlyphIterator::UpdateDesc(this: &v86);
      }
      v47 = v139;
      v144 = -a6;
      v48 = v139[4].m_pAllocator;
      v138 = -a7;
      v139 = (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v48;
      v145 = v144 + v145;
      v147 = v144 + v147;
      v146 = v138 + v146;
      v148 = v138 + v148;
      v144 = *(float *)&v47[3].m_pAllocator;
      v144 = (float)SLODWORD(v144);
      *(float *)&v139 = (float)(int)v48;
      v145 = v144 + v145;
      v147 = v144 + v147;
      v146 = *(float *)&v139 + v146;
      v148 = *(float *)&v139 + v148;
      v101 = *a4;
      v102 = a4[1];
      v145 = v101 + v145;
      v147 = v101 + v147;
      v146 = v102 + v146;
      v148 = v102 + v148;
      v49 = v140;
      v50 = v142;
      v51 = v146;
      if ( v142 <= (double)v140 || (v52 = v141, v53 = v143, v143 <= (double)v141) )
      {
LABEL_124:
        v140 = v145;
        v141 = v146;
        v142 = v147;
        v143 = v148;
        if ( v92 != nullptr )
          GRefCountNTSImpl::Release(this: v92);
        v63 = v91;
        if ( v91 != nullptr )
        {
          --*(_DWORD *)v91;
          if ( *(_DWORD *)v63 == 0 )
          {
            v64 = *((GFxFontManager **)v63 + 1);
            if ( v64 != nullptr )
              GFxFontManager::RemoveFontHandle(this: v64, a2: v63);
            v65 = *((IShaderDevice **)v63 + 7);
            if ( v65 != nullptr )
              GFxResource::Release(this: v65);
            *((_DWORD *)v63 + 7) = 0;
            v66 = *((IShaderDevice **)v63 + 8);
            if ( v66 != nullptr )
              GFxResource::Release(this: v66);
            v67 = *((IShaderDevice **)v63 + 7);
            if ( v67 != nullptr )
              GFxResource::Release(this: v67);
            v68 = (volatile LONG *)(*((_DWORD *)v63 + 3) & 0xFFFFFFFC);
            if ( InterlockedExchangeAdd(Addend: v68 + 1, Value: -1) == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v68);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v63);
          }
        }
        goto LABEL_139;
      }
      if ( v53 >= v51 || v53 + 20.0 < v51 || v147 < v49 || v145 > v50 )
      {
        v54 = v143;
      }
      else
      {
        v143 = v146;
        v54 = v146;
      }
      v116 = *a4;
      v117 = a4[1];
      v118 = a4[2];
      v119 = a4[3];
      if ( v117 <= v54 && v119 >= v52 && v118 >= v49 && v116 <= v50 )
      {
        if ( v116 >= v49 )
        {
          v140 = v116;
          v49 = v116;
        }
        if ( v118 < v50 )
        {
          v142 = v118;
          v50 = v118;
        }
        if ( v117 >= v52 )
        {
          v141 = v117;
          v52 = v117;
        }
        if ( v119 >= v54 )
          goto LABEL_103;
        v55 = v52;
        v143 = v119;
        v56 = v119;
      }
      else
      {
        v140 = 0.0;
        v141 = 0.0;
        v142 = 0.0 + 0.0;
        v143 = v142;
        v50 = v149;
        v55 = (float)0.0;
        v56 = v149;
        v49 = v55;
      }
      v57 = v56;
      v52 = v55;
      v54 = v57;
LABEL_103:
      v58 = v52;
      v59 = v50;
      v60 = v58;
      if ( v59 > v49 && v54 > v60 )
      {
        if ( (v114 & 8) != 0 )
        {
          v95 = v111;
          v61 = &v95;
        }
        else
        {
          v133 = 0;
          v132 = 0;
          v134 = 0;
          v61 = (int *)&v132;
        }
        v62 = *v61;
        if ( v62 != v128 )
        {
          v128 = v62;
          GFxDrawingContext::SetFill(this: a2, rgba: v62, a3: v73);
          v60 = v141;
          v49 = v140;
        }
        v72 = v60;
        x = v49;
        GFxDrawingContext::MoveTo(this: a2, x: (void *)LODWORD(x), y: v72);
        GFxDrawingContext::LineTo(this: a2, x: (void *)LODWORD(v142), y: v141);
        GFxDrawingContext::LineTo(this: a2, x: (void *)LODWORD(v142), y: v143);
        GFxDrawingContext::LineTo(this: a2, x: (void *)LODWORD(v140), y: v143);
        GFxDrawingContext::LineTo(this: a2, x: (void *)LODWORD(v140), y: v141);
        GFxDrawingContext::AddPath(this: a2);
      }
      goto LABEL_124;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017C270
// Name: public: struct GFxTextHighlightDesc __near * GFxTextHighlighter::CreateNewHighlighter(struct GFxTextHighlightDesc __near *)
// Source: json
//------------------------------------------------------------------------------
IVJobs *__thiscall GFxTextHighlighter::CreateNewHighlighter(int this, IVJobs *result)
{
  CUtlMemory<char const *,int> *v2; // edi
  int v3; // edx
  IVJobs_vtbl *m_pMemory; // ebx
  unsigned int v5; // esi
  unsigned int v6; // ecx
  unsigned int v7; // ebx
  int v9; // [esp+Ch] [ebp-10h]

  v2 = (CUtlMemory<char const *,int> *)this;
  v3 = *(_DWORD *)(this + 4);
  *(_WORD *)(this + 24) = 0;
  v9 = v3;
  do
  {
    m_pMemory = (IVJobs_vtbl *)++v2[1].m_pMemory;
    v5 = 0;
    if ( v3 > 0 )
    {
      do
      {
        v6 = (v3 >> 1) + v5;
        m_pMemory = (IVJobs_vtbl *)v2[1].m_pMemory;
        if ( v2->m_pMemory[10 * v6 + 5] - (const char *)m_pMemory >= 0 )
        {
          v3 >>= 1;
        }
        else
        {
          v5 = v6 + 1;
          v3 += -1 - (v3 >> 1);
        }
      }
      while ( v3 > 0 );
      v2 = (CUtlMemory<char const *,int> *)this;
      v3 = v9;
    }
  }
  while ( v5 < v3 && (IVJobs_vtbl *)v2->m_pMemory[10 * v5 + 5] == m_pMemory && &v2->m_pMemory[10 * v5] != nullptr );
  result[5].__vftable = m_pMemory;
  v7 = G_LowerBoundSliced<GArrayLH<GFxTextHighlightDesc,2,GArrayDefaultPolicy>,unsigned int,int (__cdecl *)(GFxTextHighlightDesc const &,unsigned int)>(
         a1: v2,
         a2: 0,
         a3: v2->m_nAllocationCount,
         a4: &result[5],
         a5: `anonymous namespace'::IdComparator::Less);
  GArrayBase<GArrayData<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>>::InsertAt(
    this: v2,
    index: v7,
    a3: (int)result);
  return (IVJobs *)&v2->m_pMemory[10 * v7];
}

//------------------------------------------------------------------------------
// Address: 0x1017C330
// Name: public: struct GFxTextHighlightDesc __near * GFxTextHighlighter::CreateHighlighter(struct GFxTextHighlightDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
IVJobs *__thiscall GFxTextHighlighter::CreateHighlighter(IVJobs *this, const IVJobs *desc)
{
  const IVJobs *v2; // ebx
  unsigned int v4; // eax
  unsigned int v5; // ecx
  const IVJobs **v6; // eax
  unsigned int v7; // edi

  v2 = desc;
  *((_WORD *)this + 12) = 0;
  desc = (const IVJobs *)v2[5].__vftable;
  v4 = G_LowerBoundSliced<GArrayLH<GFxTextHighlightDesc,2,GArrayDefaultPolicy>,unsigned int,int (__cdecl *)(GFxTextHighlightDesc const &,unsigned int)>(
         a1: this,
         a2: 0,
         a3: *((_DWORD *)this + 1),
         a4: &desc,
         a5: `anonymous namespace'::IdComparator::Less);
  v5 = *((_DWORD *)this + 1);
  if ( v4 < v5 )
  {
    v6 = (const IVJobs **)((char *)this->__vftable + 40 * v4);
    if ( v6[5] == desc && v6 != nullptr )
      return nullptr;
  }
  v7 = G_LowerBoundSliced<GArrayLH<GFxTextHighlightDesc,2,GArrayDefaultPolicy>,unsigned int,int (__cdecl *)(GFxTextHighlightDesc const &,unsigned int)>(
         a1: this,
         a2: 0,
         a3: v5,
         a4: &v2[5],
         a5: `anonymous namespace'::IdComparator::Less);
  GArrayBase<GArrayData<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>>::InsertAt(
    (CUtlMemory<char const *,int> *)this,
    index: v7,
    a3: (int)v2);
  return (IVJobs *)((char *)this->__vftable + 40 * v7);
}

//------------------------------------------------------------------------------
// Address: 0x1017C3C0
// Name: public: void GFxTextHighlighter::Add(struct GFxTextHighlightDesc __near &)
// Source: json
//------------------------------------------------------------------------------
IVJobs *__thiscall GFxTextHighlighter::Add(IResourceAccessControl *this, IVJobs *merge)
{
  IVJobs *v2; // edi
  char *v3; // ebx
  IVJobs *result; // eax
  IResourceAccessControl_vtbl *v5; // edi
  IResourceAccessControl_vtbl *v6; // edx
  IResourceAccessControl_vtbl *v7; // esi
  int v8; // edx
  IResourceAccessControl_vtbl *v9; // edx
  int v10; // [esp+8h] [ebp-10h]
  int v11; // [esp+Ch] [ebp-Ch]
  unsigned int mergeEnd; // [esp+10h] [ebp-8h]
  bool bmerged; // [esp+17h] [ebp-1h]

  v2 = merge;
  v3 = (char *)merge->__vftable + (unsigned int)merge[1].__vftable;
  bmerged = false;
  mergeEnd = (unsigned int)v3;
  if ( *((_DWORD *)this + 1) == 0 )
    return GFxTextHighlighter::CreateNewHighlighter((int)this, result: v2);
  v11 = 0;
  v10 = *((_DWORD *)this + 1);
  while ( 1 )
  {
    result = (IVJobs *)((char *)this->__vftable + v11);
    v5 = (IResourceAccessControl_vtbl *)v2->__vftable;
    v6 = (IResourceAccessControl_vtbl *)result->__vftable;
    v7 = (IResourceAccessControl_vtbl *)((char *)result->__vftable + (unsigned int)result[1].__vftable);
    if ( result->__vftable <= (IVJobs_vtbl *)v5 )
    {
      if ( v5 <= v7 )
      {
        if ( v3 > (char *)v7 )
        {
          result[1].__vftable = (IVJobs_vtbl *)((char *)result[1].__vftable + v3 - (char *)v7);
          result[4].__vftable = result[1].__vftable;
          bmerged = true;
          *((_WORD *)this + 12) = 0;
        }
        goto LABEL_12;
      }
      if ( v6 <= v5 )
        goto LABEL_12;
    }
    v3 = (char *)mergeEnd;
    if ( (unsigned int)v6 < mergeEnd )
    {
      v8 = (char *)v6 - (char *)v5;
      result->__vftable = (IVJobs_vtbl *)((char *)result->__vftable - v8);
      result[1].__vftable = (IVJobs_vtbl *)((char *)result[1].__vftable + v8);
      v9 = (IResourceAccessControl_vtbl *)result[1].__vftable;
      result[3].__vftable = result->__vftable;
      result[4].__vftable = (IVJobs_vtbl *)v9;
      bmerged = true;
      *((_WORD *)this + 12) = 0;
      if ( (unsigned int)v7 <= mergeEnd )
      {
        result[1].__vftable = (IVJobs_vtbl *)((char *)result[1].__vftable + mergeEnd - (_DWORD)v7);
        result[4].__vftable = result[1].__vftable;
      }
    }
LABEL_12:
    v11 += 40;
    if ( --v10 == 0 )
      break;
    v2 = merge;
  }
  if ( !bmerged )
  {
    v2 = merge;
    return GFxTextHighlighter::CreateNewHighlighter((int)this, result: v2);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017C4F0
// Name: public: bool GFxTextHighlighter::FreeHighlighter(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighter::FreeHighlighter(IResourceAccessControl *this, unsigned int id)
{
  unsigned int v3; // eax

  v3 = G_LowerBoundSliced<GArrayLH<GFxTextHighlightDesc,2,GArrayDefaultPolicy>,unsigned int,int (__cdecl *)(GFxTextHighlightDesc const &,unsigned int)>(
         a1: this,
         a2: 0,
         a3: *((_DWORD *)this + 1),
         a4: &id,
         a5: `anonymous namespace'::IdComparator::Less);
  if ( v3 < *((_DWORD *)this + 1) && *((_DWORD *)&this->GetDependencies + 10 * v3) == id )
  {
    GArrayBase<GArrayData<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>>::RemoveAt(
      (CUtlMemory<char const *,int> *)this,
      index: v3);
    *((_WORD *)this + 12) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017C540
// Name: public: void GFxTextHighlighter::Remove(struct GFxTextHighlightDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHighlighter::Remove(CUtlMemory<char const *,int> *this, const struct GFxTextHighlightDesc *a2)
{
  const struct GFxTextHighlightDesc *v2; // edx
  unsigned int v3; // edi
  int v5; // ecx
  const char **v6; // eax
  unsigned int v7; // edx
  const char *v8; // ebx
  unsigned int v9; // ecx
  const char *v10; // edx
  int v11; // edx
  int v12; // edx
  char v13; // al
  unsigned int v14; // ebx
  const char *v15; // ecx
  IVJobs *v16; // edi
  int i; // ebx
  int v18[9]; // [esp+Ch] [ebp-3Ch] BYREF
  char v19; // [esp+30h] [ebp-18h]
  IVJobs *result; // [esp+34h] [ebp-14h] BYREF
  int v21; // [esp+38h] [ebp-10h]
  int v22; // [esp+3Ch] [ebp-Ch]
  unsigned int v23; // [esp+40h] [ebp-8h]
  unsigned int v24; // [esp+44h] [ebp-4h]

  v2 = a2;
  v3 = *(_DWORD *)a2 + *((_DWORD *)a2 + 1);
  v5 = 0;
  result = nullptr;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  if ( this->m_nAllocationCount != 0 )
  {
    v24 = 0;
    while ( 1 )
    {
      v6 = &this->m_pMemory[v24 / 4];
      v7 = *(_DWORD *)v2;
      v8 = *v6;
      v9 = (unsigned int)&v6[1][(_DWORD)*v6];
      if ( (unsigned int)*v6 < v7 )
      {
        if ( v7 < v9 )
        {
          if ( v3 >= v9 )
          {
            v6[1] += v7 - v9;
            v6[4] = v6[1];
          }
          else
          {
            v10 = (const char *)(v7 - (_DWORD)v8);
            v6[1] = v10;
            v6[4] = v10;
            v18[2] = (int)v6[2];
            v18[5] = (int)v6[5];
            v18[6] = (int)v6[6];
            v11 = (int)v6[7];
            v18[1] = v9 - v3;
            v18[4] = v9 - v3;
            v18[7] = v11;
            v12 = (int)v6[8];
            v13 = *((_BYTE *)v6 + 36);
            v18[8] = v12;
            v19 = v13;
            v18[0] = v3;
            v18[3] = v3;
            GArrayData<GFxTextHighlightDesc,GAllocatorGH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>::PushBack(
              pheapAddr: (int *)&result,
              a2: (int)v18);
          }
          *((_WORD *)this + 12) = 0;
          goto LABEL_16;
        }
        if ( (unsigned int)v8 < v7 )
          goto LABEL_16;
      }
      if ( (unsigned int)v8 < v3 )
      {
        if ( v9 > v3 )
        {
          *v6 = (const char *)v3;
          v6[1] -= v3 - (_DWORD)v8;
          v15 = v6[1];
          v6[3] = *v6;
          v6[4] = v15;
        }
        else
        {
          v14 = v23;
          GArrayBase<GArrayData<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>>::RemoveAt(
            this,
            index: v23);
          v24 -= 40;
          v23 = v14 - 1;
        }
        *((_WORD *)this + 12) = 0;
      }
LABEL_16:
      v24 += 40;
      if ( ++v23 >= this->m_nAllocationCount )
      {
        v5 = v21;
        break;
      }
      v2 = a2;
    }
  }
  if ( v5 != 0 )
  {
    v16 = result;
    for ( i = v5; i != 0; --i )
    {
      GFxTextHighlighter::CreateNewHighlighter((int)this, result: v16);
      v16 += 10;
    }
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: result);
}

//------------------------------------------------------------------------------
// Address: 0x1017AD40
// Name: unsigned int G_LowerBoundSliced<class GArrayLH<struct GFxTextHighlightDesc,2,struct GArrayDefaultPolicy>,unsigned int,int (*)(struct GFxTextHighlightDesc const __near &,unsigned int)>(class GArrayLH<struct GFxTextHighlightDesc,2,struct GArrayDefaultPolicy> const __near &,unsigned int,unsigned int,unsigned int const __near &,int (*)(struct GFxTextHighlightDesc const __near &,unsigned int))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl G_LowerBoundSliced<GArrayLH<GFxTextHighlightDesc,2,GArrayDefaultPolicy>,unsigned int,int (__cdecl *)(GFxTextHighlightDesc const &,unsigned int)>(
        _DWORD *a1,
        int a2,
        int a3,
        _DWORD *a4,
        int (__cdecl *a5)(int, _DWORD))
{
  int result; // eax
  int i; // ebx
  int v7; // edi

  result = a2;
  for ( i = a3 - a2; i > 0; result = a2 )
  {
    v7 = (i >> 1) + result;
    if ( a5(a1: *a1 + 40 * v7, a2: *a4) != 0 )
    {
      a2 = v7 + 1;
      i += -1 - (i >> 1);
    }
    else
    {
      i >>= 1;
    }
  }
  return result;
}
