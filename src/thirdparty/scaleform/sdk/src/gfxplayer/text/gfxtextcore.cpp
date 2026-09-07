// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/text/gfxtextcore.cpp
// Functions: 43
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\text\gfxtextcore.h"

//------------------------------------------------------------------------------
// Address: 0x1013ED00
// Name: public: bool GFxTextHTMLImageTagDesc::operator==(struct GFxTextHTMLImageTagDesc const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHTMLImageTagDesc::operator==(_DWORD *this, _DWORD *a2)
{
  if ( strcmp((const char *)((*(this + 14) & 0xFFFFFFFC) + 8), (const char *)((a2[14] & 0xFFFFFFFC) + 8)) == 0 )
    strcmp((const char *)((*(this + 15) & 0xFFFFFFFC) + 8), (const char *)((a2[15] & 0xFFFFFFFC) + 8));
}

//------------------------------------------------------------------------------
// Address: 0x1013EDC0
// Name: public: void GFxTextFormat::SetUrl(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CImagePacker *__thiscall GFxTextFormat::SetUrl(
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *this,
        char *purl,
        unsigned int urlSz)
{
  int v3; // edi
  CImagePacker *result; // eax

  v3 = urlSz;
  if ( urlSz == -1 )
    v3 = strlen(purl);
  GString::Clear(this: (GString *)this + 4);
  result = GString::AppendString(
             this: (CUtlMemory<CImagePacker,int> *)(this + 2),
             putf8str: (CImagePacker *)purl,
             utf8StrSz: v3);
  *((_WORD *)this + 21) |= 0x100u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013EE10
// Name: public: void GFxTextFormat::SetUrl(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetUrl(
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *this,
        IMaterialInternal *purl,
        void (__thiscall *urlSz)(IMaterial *this))
{
  void (__thiscall *v3)(IMaterial *); // ebx

  v3 = urlSz;
  if ( urlSz == (void (__thiscall *)(IMaterial *))-1 )
    v3 = (void (__thiscall *)(IMaterial *))G_wcslen(pwch: (const wchar_t *)purl);
  GString::Clear(this: (GString *)this + 4);
  GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)(this + 2), pstr: (RGB888_t *)purl, a3: (int)v3);
  *((_WORD *)this + 21) |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x1013EE60
// Name: public: void GFxTextFormat::SetUrl(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetUrl(GFxTextFormat *this, struct GString *src)
{
  int v3; // [esp+0h] [ebp-4h]

  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 16),
    src,
    a3: v3);
  *((_WORD *)this + 21) |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x1013EE80
// Name: public: void GFxTextFormat::SetUnderline(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetUnderline(GFxTextFormat *this, bool a2)
{
  if ( a2 )
    *((_BYTE *)this + 40) |= 4u;
  else
    *((_BYTE *)this + 40) &= ~4u;
  *((_WORD *)this + 21) |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x1013EEB0
// Name: public: void GFxTextFormat::SetKerning(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetKerning(GFxTextFormat *this, bool a2)
{
  if ( a2 )
    *((_BYTE *)this + 40) |= 8u;
  else
    *((_BYTE *)this + 40) &= ~8u;
  *((_WORD *)this + 21) |= 0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x1013EEE0
// Name: public: unsigned int const __near * GFxTextParagraphFormat::GetTabStops(unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraphFormat::GetTabStops(
        CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pnum)
{
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl **v2; // eax

  v2 = (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl **)this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable;
  if ( v2 != nullptr && pnum != nullptr )
    pnum->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = *v2;
}

//------------------------------------------------------------------------------
// Address: 0x1013EF10
// Name: public: void GFxTextParagraphFormat::SetTabStopsElement(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxTextParagraphFormat::SetTabStopsElement(
        GFxTextParagraphFormat *this,
        unsigned int idx,
        unsigned int val)
{
  _DWORD *result; // eax

  result = *((_DWORD **)this + 2);
  if ( result != nullptr && idx < *result )
    result[idx + 1] = val;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013EF30
// Name: protected: void GFxTextParagraphFormat::FreeTabStops(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraphFormat::FreeTabStops(CMaterial *this)
{
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)this->m_minLightmapPageID);
  this->m_minLightmapPageID = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013EF50
// Name: protected: bool GFxTextParagraphFormat::TabStopsEqual(unsigned int const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextParagraphFormat::TabStopsEqual(
        CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CMaterialSystem *psrcTabStops)
{
  CRefCountServiceDestruct<CRefST>_vtbl *v2; // eax
  unsigned int v4; // ecx
  IShaderUtil *v5; // edx
  CRefCountServiceDestruct<CRefST>_vtbl *v6; // esi

  v2 = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable;
  if ( v2 == (CRefCountServiceDestruct<CRefST>_vtbl *)psrcTabStops )
    return true;
  if ( v2 != nullptr
    && psrcTabStops != nullptr
    && v2->dtr_CRefCountServiceDestruct<CRefST> == (void (__thiscall *)(CRefCountServiceDestruct<CRefST> *))psrcTabStops->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable )
  {
    v4 = 4 * (int)v2->dtr_CRefCountServiceDestruct<CRefST>;
    v5 = &psrcTabStops->IShaderUtil;
    v6 = v2 + 1;
    if ( v4 < 4 )
    {
LABEL_9:
      if ( v4 == 0 )
        return true;
    }
    else
    {
      while ( v6->dtr_CRefCountServiceDestruct<CRefST> == (void (__thiscall *)(CRefCountServiceDestruct<CRefST> *))v5->__vftable )
      {
        v4 -= 4;
        ++v5;
        ++v6;
        if ( v4 < 4 )
          goto LABEL_9;
      }
    }
    return LOBYTE(v6->dtr_CRefCountServiceDestruct<CRefST>) == LOBYTE(v5->__vftable)
        && (v4 <= 1
         || BYTE1(v6->dtr_CRefCountServiceDestruct<CRefST>) == BYTE1(v5->__vftable)
         && (v4 <= 2 || BYTE2(v6->dtr_CRefCountServiceDestruct<CRefST>) == BYTE2(v5->__vftable) && v4 <= 3));
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1013F010
// Name: public: bool GFxFontHandle::operator==(class GFxFontHandle const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxFontHandle::operator==(int this, int a2)
{
  return *(_DWORD *)(this + 4) == *(_DWORD *)(a2 + 4)
      && *(_DWORD *)(this + 28) == *(_DWORD *)(a2 + 28)
      && *(_DWORD *)(this + 8) == *(_DWORD *)(a2 + 8)
      && GString::operator==(
           this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 12),
           str: (_DWORD *)(a2 + 12))
      && *(float *)(a2 + 16) == *(float *)(this + 16)
      && *(_DWORD *)(this + 32) == *(_DWORD *)(a2 + 32)
      && *(float *)(a2 + 20) == *(float *)(this + 20)
      && *(float *)(a2 + 24) == *(float *)(this + 24);
}

//------------------------------------------------------------------------------
// Address: 0x1013F090
// Name: public: void GFxTextFormat::SetImageDesc(struct GFxTextHTMLImageTagDesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetImageDesc(GFxTextFormat *this, struct GFxTextHTMLImageTagDesc *a2)
{
  GRefCountNTSImpl *v3; // ecx

  if ( a2 != nullptr )
    ++*((_DWORD *)a2 + 1);
  v3 = *((GRefCountNTSImpl **)this + 6);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  *((_DWORD *)this + 6) = a2;
  *((_WORD *)this + 21) |= 0x200u;
}

//------------------------------------------------------------------------------
// Address: 0x1013F0C0
// Name: public: struct GFxTextHTMLImageTagDesc __near * GFxTextFormat::GetImageDesc(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::GetImageDesc(
        CMemberFuncProxy3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CFuncMemPolicyNone> *this)
{
  int v1; // eax
  char v2; // bl
  GRefCountNTSImpl *v3; // edi
  GRefCountNTSImpl *v4; // ecx
  GRefCountNTSImpl *v5; // [esp+10h] [ebp-4h]

  if ( (*((_WORD *)this + 21) & 0x200) != 0 )
  {
    v1 = *((_DWORD *)this + 6);
    v2 = 1;
    if ( v1 != 0 )
      ++*(_DWORD *)(v1 + 4);
    v3 = *((GRefCountNTSImpl **)this + 6);
    v4 = v5;
  }
  else
  {
    v3 = nullptr;
    v4 = nullptr;
    v2 = 2;
  }
  if ( (v2 & 2) != 0 )
  {
    v2 &= ~2u;
    if ( v4 != nullptr )
      GRefCountNTSImpl::Release(this: v4);
  }
  if ( (v2 & 1) != 0 && v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1013F140
// Name: public: bool GFxTextFormat::operator==(class GFxTextFormat const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextFormat::operator==(int this, int f)
{
  __int16 v3; // ax
  __int16 v4; // cx
  bool v5; // al
  int v6; // ecx
  int v7; // eax
  char v8; // al
  char v9; // bl
  char v10; // al
  char v11; // al
  _DWORD *v12; // esi
  char v13; // al

  v3 = *(_WORD *)(this + 42);
  v4 = *(_WORD *)(f + 42);
  if ( v3 != v4 )
    return 0;
  if ( *(_BYTE *)(this + 40) != *(_BYTE *)(f + 40) )
    return 0;
  if ( *(_DWORD *)(this + 32) != *(_DWORD *)(f + 32) )
    return 0;
  if ( *(_WORD *)(this + 38) != *(_WORD *)(f + 38) )
    return 0;
  v5 = (v3 & 4) != 0;
  if ( v5 != ((v4 & 4) != 0)
    || v5 && GString::CompareNoCase(this: (CUtlMemory<CImagePacker,int> *)(this + 8), a2: (_DWORD *)(f + 8)) != 0 )
  {
    return 0;
  }
  if ( *(_WORD *)(this + 36) != *(_WORD *)(f + 36) )
    return 0;
  if ( ((*(_WORD *)(this + 42) & 0x800) != 0) != ((*(_WORD *)(f + 42) & 0x800) != 0) )
    return 0;
  if ( (*(_WORD *)(this + 42) & 0x800) != 0 )
  {
    v6 = *(_DWORD *)(this + 28);
    v7 = *(_DWORD *)(f + 28);
    if ( v6 != v7 && (v6 == 0 || v7 == 0 || !GFxFontHandle::operator==(this: v6, a2: *(_DWORD *)(f + 28))) )
      return 0;
  }
  if ( (GFxTextFormat::IsUrlSet(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)f),
        v9 = v8,
        GFxTextFormat::IsUrlSet((CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)this),
        v10 == v9)
    && ((GFxTextFormat::IsUrlSet((CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)this),
         v11 == 0)
     || GString::CompareNoCase(this: (CUtlMemory<CImagePacker,int> *)(this + 16), a2: (_DWORD *)(f + 16)) == 0)
    && ((v12 = *(_DWORD **)(this + 24)) != nullptr
     && *(_DWORD *)(f + 24) != 0
     && (GFxTextHTMLImageTagDesc::operator==(this: v12, a2: *(_DWORD **)(f + 24)), v13 != 0)
     || v12 == *(_DWORD **)(f + 24)) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F260
// Name: public: unsigned int GFxTextHTMLImageTagDesc::GetHash(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHTMLImageTagDesc::GetHash(int this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  char v8; // [esp+Bh] [ebp-15h]
  int v9; // [esp+Ch] [ebp-14h]
  int v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+14h] [ebp-Ch]
  int v12; // [esp+18h] [ebp-8h]

  v2 = *(_DWORD *)(this + 64);
  v3 = *(_DWORD *)(this + 68);
  v4 = *(_DWORD *)(this + 72);
  v9 = v2;
  v12 = *(unsigned __int8 *)(this + 76);
  v10 = v3;
  v11 = v4;
  v5 = 16;
  v6 = 5381;
  do
  {
    v7 = (unsigned __int8)*(&v8 + v5--);
    v6 = v7 + 65599 * v6;
  }
  while ( v5 != 0 );
  GString::BernsteinHashFunctionCIS(
    result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*(_DWORD *)(this + 56) & 0xFFFFFFFC)
                                                                                   + 8),
    size: *(_DWORD *)(*(_DWORD *)(this + 56) & 0xFFFFFFFC) & 0x7FFFFFFF,
    seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
  GString::BernsteinHashFunctionCIS(
    result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*(_DWORD *)(this + 60) & 0xFFFFFFFC)
                                                                                   + 8),
    size: *(_DWORD *)(*(_DWORD *)(this + 60) & 0xFFFFFFFC) & 0x7FFFFFFF,
    seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
}

//------------------------------------------------------------------------------
// Address: 0x1013F310
// Name: public: bool GFxTextFormat::IsFontSame(class GFxTextFormat const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxTextFormat::IsFontSame(GFxTextFormat *this, const struct GFxTextFormat *fmt)
{
  unsigned __int8 v3; // cl
  BOOL result; // eax

  result = false;
  if ( (*((_BYTE *)this + 42) & 4) != 0
    && (*((_BYTE *)fmt + 42) & 4) != 0
    && GString::CompareNoCase(
         a1: (char *)((*((_DWORD *)this + 2) & 0xFFFFFFFC) + 8),
         a2: (char *)((*((_DWORD *)fmt + 2) & 0xFFFFFFFC) + 8)) == 0
    || (*((_WORD *)this + 21) & 0x800) != 0
    && (*((_WORD *)fmt + 21) & 0x800) != 0
    && *((_DWORD *)this + 7) == *((_DWORD *)fmt + 7) )
  {
    v3 = *((_BYTE *)fmt + 40);
    if ( ((v3 ^ *((_BYTE *)this + 40)) & 1) == 0 && ((v3 ^ *((_BYTE *)this + 40)) & 2) == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013F3A0
// Name: public: bool GFxTextFormat::IsHTMLFontTagSame(class GFxTextFormat const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxTextFormat::IsHTMLFontTagSame(GFxTextFormat *this, const struct GFxTextFormat *fmt)
{
  double v4; // st6
  double v5; // st7
  BOOL result; // eax
  float fmta; // [esp+10h] [ebp+8h]
  float fmtb; // [esp+10h] [ebp+8h]
  float fmtc; // [esp+10h] [ebp+8h]
  float fmtd; // [esp+10h] [ebp+8h]

  result = false;
  if ( ((*((_BYTE *)this + 42) & 4) != 0
     && (*((_BYTE *)fmt + 42) & 4) != 0
     && GString::CompareNoCase(
          a1: (char *)((*((_DWORD *)this + 2) & 0xFFFFFFFC) + 8),
          a2: (char *)((*((_DWORD *)fmt + 2) & 0xFFFFFFFC) + 8)) == 0
     || (*((_WORD *)this + 21) & 0x800) != 0
     && (*((_WORD *)fmt + 21) & 0x800) != 0
     && *((_DWORD *)this + 7) == *((_DWORD *)fmt + 7))
    && ((*((_DWORD *)this + 8) ^ *((_DWORD *)fmt + 8)) & 0xFFFFFF) == 0
    && *((_BYTE *)this + 35) == *((_BYTE *)fmt + 35) )
  {
    fmta = (double)*((unsigned __int16 *)this + 19) / 20.0;
    v4 = fmta;
    fmtb = (double)*((unsigned __int16 *)fmt + 19) / 20.0;
    if ( fmtb == v4 && ((*((_BYTE *)this + 40) ^ *((_BYTE *)fmt + 40)) & 8) == 0 )
    {
      fmtc = (double)*((__int16 *)this + 18) / 20.0;
      v5 = fmtc;
      fmtd = (double)*((__int16 *)fmt + 18) / 20.0;
      if ( fmtd == v5 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013F4B0
// Name: public: unsigned int GFxTextFormat::HashFunctor::operator()(class GFxTextFormat const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::HashFunctor::operator()(
        GArray<GWaitable::HandlerStruct,2,GArrayConstPolicy<0,16,1> > *this,
        const GArray<GWaitable::HandlerStruct,2,GArrayConstPolicy<0,16,1> > *data)
{
  unsigned int Capacity; // esi
  int Data_low; // ecx
  bool v4; // zf
  int Size_high; // eax
  GWaitable::HandlerStruct *v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // ecx
  char v11; // [esp+7h] [ebp-15h]
  int v12; // [esp+8h] [ebp-14h]
  int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  int v15; // [esp+14h] [ebp-8h]

  Capacity = 0;
  Data_low = 0;
  v4 = (data[3].Data.Size & 0x10000) == 0;
  v14 = 0;
  v15 = 0;
  if ( !v4 || (data[3].Data.Size & 0x4000000) != 0 )
    Capacity = data[2].Data.Policy.Capacity;
  Size_high = HIWORD(data[3].Data.Size);
  if ( (Size_high & 2) != 0 )
    Data_low = SLOWORD(data[3].Data.Data);
  if ( (Size_high & 8) != 0 )
    Data_low |= HIWORD(data[3].Data.Data) << 16;
  v12 = (LOBYTE(data[3].Data.Size) << 24) | Capacity;
  v13 = (Size_high << 24) | Data_low;
  if ( data[2].Data.Size != 0 )
    v14 = 1;
  if ( (Size_high & 0x200) != 0 )
  {
    v6 = data[2].Data.Data;
    if ( v6 != nullptr )
    {
      GFxTextHTMLImageTagDesc::GetHash(this: (int)v6);
      v15 = v7;
    }
  }
  v8 = 16;
  v9 = 5381;
  do
  {
    v10 = (unsigned __int8)*(&v11 + v8--);
    v9 = v10 + 65599 * v9;
  }
  while ( v8 != 0 );
  if ( (data[3].Data.Size & 0x40000) != 0 )
    GString::BernsteinHashFunctionCIS(
      result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((data->Data.Policy.Capacity
                                                                                      & 0xFFFFFFFC)
                                                                                     + 8),
      size: *(_DWORD *)(data->Data.Policy.Capacity & 0xFFFFFFFC) & 0x7FFFFFFF,
      seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
  if ( (data[3].Data.Size & 0x1000000) != 0 && GString::GetLength(this: (GString *)&data[1].Data.Size) != 0 )
    GString::BernsteinHashFunctionCIS(
      result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((data[1].Data.Size & 0xFFFFFFFC)
                                                                                     + 8),
      size: *(_DWORD *)(data[1].Data.Size & 0xFFFFFFFC) & 0x7FFFFFFF,
      seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
}

//------------------------------------------------------------------------------
// Address: 0x1013F600
// Name: public: void GFxTextParagraphFormat::InitByDefaultValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraphFormat::InitByDefaultValues(CMaterial *this)
{
  __int16 m_pShader_high; // dx
  void *m_minLightmapPageID; // eax

  *(_DWORD *)&this->m_MappingWidth = 0;
  m_pShader_high = HIWORD(this->m_pShader);
  this->m_maxLightmapPageID = 0;
  m_minLightmapPageID = (void *)this->m_minLightmapPageID;
  HIWORD(this->m_pShader) = m_pShader_high & 0x7940 | 1;
  LOWORD(this->m_pShader) = 0;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: m_minLightmapPageID);
  HIWORD(this->m_pShader) &= ~0x40u;
  this->m_minLightmapPageID = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013F650
// Name: protected: void GFxTextParagraphFormat::AllocTabStops(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor2<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxTextParagraphFormat::AllocTabStops(
        void **this,
        unsigned int result)
{
  CMemberFunctor2<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // eax
  int v4; // [esp+8h] [ebp-4h] BYREF

  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(this + 2));
  *(this + 2) = nullptr;
  v4 = 324;
  v3 = (CMemberFunctor2<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * result + 4, a3: &v4);
  *(this + 2) = v3;
  v3->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor2<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)result;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1013F6A0
// Name: protected: void GFxTextParagraphFormat::CopyTabStops(unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraphFormat::CopyTabStops(GFxTextParagraphFormat *this, int psrcTabStops)
{
  int v2; // ebx
  _DWORD *v4; // eax
  int v5; // edi
  _DWORD *v6; // eax

  v2 = psrcTabStops;
  v4 = *((_DWORD **)this + 2);
  if ( psrcTabStops != 0 )
  {
    v5 = *(_DWORD *)psrcTabStops;
    if ( v4 == nullptr || *v4 != v5 )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
      *((_DWORD *)this + 2) = 0;
      psrcTabStops = 324;
      v6 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * v5 + 4, a3: &psrcTabStops);
      *((_DWORD *)this + 2) = v6;
      *v6 = v5;
    }
    memcpy(dst: (unsigned __int8 *)(*((_DWORD *)this + 2) + 4), src: (unsigned __int8 *)(v2 + 4), count: 4 * v5);
  }
  else
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
    *((_DWORD *)this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F740
// Name: public: class GFxTextParagraphFormat __near & GFxTextParagraphFormat::operator=(class GFxTextParagraphFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxTextParagraphFormat::operator=(
        int this,
        CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  *(_DWORD *)(this + 12) = result->m_iRefs;
  *(_QWORD *)(this + 16) = *(_QWORD *)&result->m_Proxy.m_pfnProxied;
  GFxTextParagraphFormat::CopyTabStops(
    (GFxTextParagraphFormat *)this,
    psrcTabStops: (int)result->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable);
  return (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x1013F790
// Name: public: unsigned int GFxTextParagraphFormat::HashFunctor::operator()(class GFxTextParagraphFormat const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __stdcall GFxTextParagraphFormat::HashFunctor::operator()(int a1)
{
  __int16 v1; // bx
  int v2; // esi
  _DWORD *v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // esi
  bool v7; // dl

  v1 = *(_WORD *)(a1 + 22);
  v2 = 0;
  if ( (v1 & 0x40) != 0 && *(_DWORD *)(a1 + 8) != 0 )
  {
    v3 = *(_DWORD **)(a1 + 8);
    v4 = 4 * *v3 + 4;
    v5 = 5381;
    if ( 4 * *v3 != -4 )
    {
      do
      {
        v6 = *((unsigned __int8 *)v3 + --v4);
        v5 = v6 + 65599 * v5;
      }
      while ( v4 != 0 );
    }
    v2 = v5;
  }
  if ( (v1 & 2) != 0 )
    v2 ^= *(unsigned __int16 *)(a1 + 12);
  if ( (v1 & 4) != 0 )
    v2 ^= *(__int16 *)(a1 + 14) << 8;
  if ( (v1 & 8) != 0 )
    v2 ^= *(__int16 *)(a1 + 16) << 12;
  if ( (v1 & 0x10) != 0 )
    v2 ^= *(unsigned __int16 *)(a1 + 18) << 16;
  if ( (v1 & 0x20) != 0 )
    v2 ^= *(unsigned __int16 *)(a1 + 20) << 18;
  v7 = (v1 & 0x80u) != 0 && (*(_WORD *)(a1 + 22) & 0x8000) != 0;
  return v2
       ^ (*(unsigned __int16 *)(a1 + 22) >> 1)
       & 0xC00
       ^ (v7 | (*(unsigned __int16 *)(a1 + 22) << 9) | HIBYTE(*(unsigned __int16 *)(a1 + 22)) & 6);
}

//------------------------------------------------------------------------------
// Address: 0x1013F880
// Name: public: GFxTextParagraphFormat::GFxTextParagraphFormat(class GFxTextParagraphFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxTextParagraphFormat *__thiscall GFxTextParagraphFormat::GFxTextParagraphFormat(
        GFxTextParagraphFormat *this,
        const struct GFxTextParagraphFormat *a2)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxTextParagraphFormat::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_WORD *)this + 6) = *((_WORD *)a2 + 6);
  *((_WORD *)this + 7) = *((_WORD *)a2 + 7);
  *((_WORD *)this + 8) = *((_WORD *)a2 + 8);
  *((_WORD *)this + 9) = *((_WORD *)a2 + 9);
  *((_WORD *)this + 10) = *((_WORD *)a2 + 10);
  *((_WORD *)this + 11) = *((_WORD *)a2 + 11);
  GFxTextParagraphFormat::CopyTabStops(this, psrcTabStops: *((_DWORD *)a2 + 2));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013F8F0
// Name: public: class GString const __near & GFxTextFormat::GetFontList(void)const
// Source: json
//------------------------------------------------------------------------------
char **__thiscall GFxTextFormat::GetFontList(char **this)
{
  char **result; // eax

  if ( ((int)GFxRectangle_NaNParams.ChildHeaps.Root.pPrev & 1) == 0 )
  {
    GFxRectangle_NaNParams.ChildHeaps.Root.pPrev = (GMemoryHeap *)((int)GFxRectangle_NaNParams.ChildHeaps.Root.pPrev | 1);
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&GFxRectangle_NaNParams.Info.pName);
    atexit(func: (void (__cdecl *)())GFxTextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__);
  }
  result = this + 2;
  if ( (*((_BYTE *)this + 42) & 4) == 0 )
    return &GFxRectangle_NaNParams.Info.pName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013F930
// Name: public: void GFxTextParagraphFormat::SetTabStops(unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraphFormat::SetTabStops(void **this, CMaterialSystem *psrcTabStops)
{
  if ( psrcTabStops != nullptr
    && psrcTabStops->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable != nullptr )
  {
    GFxTextParagraphFormat::CopyTabStops((GFxTextParagraphFormat *)this, (int)psrcTabStops);
    *((_WORD *)this + 11) |= 0x40u;
  }
  else
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(this + 2));
    *((_WORD *)this + 11) &= ~0x40u;
    *(this + 2) = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FD20
// Name: public: class GFxTextParagraphFormat GFxTextParagraphFormat::Merge(class GFxTextParagraphFormat const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraphFormat::Merge(
        CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        GFxTextParagraphFormat *a2,
        int a3)
{
  __int16 v3; // ax
  __int16 v4; // ax
  __int16 v5; // ax
  __int16 v6; // ax
  __int16 v7; // ax
  _DWORD *v8; // eax

  GFxTextParagraphFormat::GFxTextParagraphFormat(this: a2, a2: (const struct GFxTextParagraphFormat *)this);
  if ( (*(_BYTE *)(a3 + 22) & 1) != 0 )
    *((_WORD *)a2 + 11) = *((_WORD *)a2 + 11) ^ (*((_WORD *)a2 + 11) ^ (((*(_WORD *)(a3 + 22) >> 9) & 3) << 9)) & 0x600
                        | 1;
  if ( (*(_WORD *)(a3 + 22) & 0x80u) != 0 )
  {
    if ( (*(_WORD *)(a3 + 22) & 0x8000) != 0 )
      *((_WORD *)a2 + 11) |= 0x8000u;
    else
      *((_WORD *)a2 + 11) &= ~0x8000u;
    *((_WORD *)a2 + 11) |= 0x80u;
  }
  if ( (*(_BYTE *)(a3 + 22) & 2) != 0 )
  {
    v3 = *(_WORD *)(a3 + 12);
    *((_WORD *)a2 + 11) |= 2u;
    *((_WORD *)a2 + 6) = v3;
  }
  if ( (*(_BYTE *)(a3 + 22) & 4) != 0 )
  {
    v4 = *(_WORD *)(a3 + 14);
    *((_WORD *)a2 + 11) |= 4u;
    *((_WORD *)a2 + 7) = v4;
  }
  if ( (*(_BYTE *)(a3 + 22) & 8) != 0 )
  {
    v5 = *(_WORD *)(a3 + 16);
    *((_WORD *)a2 + 11) |= 8u;
    *((_WORD *)a2 + 8) = v5;
  }
  if ( (*(_BYTE *)(a3 + 22) & 0x10) != 0 )
  {
    v6 = *(_WORD *)(a3 + 18);
    *((_WORD *)a2 + 11) |= 0x10u;
    *((_WORD *)a2 + 9) = v6;
  }
  if ( (*(_BYTE *)(a3 + 22) & 0x20) != 0 )
  {
    v7 = *(_WORD *)(a3 + 20);
    *((_WORD *)a2 + 11) |= 0x20u;
    *((_WORD *)a2 + 10) = v7;
  }
  if ( (*(_BYTE *)(a3 + 22) & 0x40) != 0 )
  {
    v8 = *(_DWORD **)(a3 + 8);
    if ( v8 != nullptr && *v8 != 0 )
    {
      GFxTextParagraphFormat::CopyTabStops(this: a2, psrcTabStops: *(_DWORD *)(a3 + 8));
      *((_WORD *)a2 + 11) |= 0x40u;
    }
    else
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)a2 + 2));
      *((_WORD *)a2 + 11) &= ~0x40u;
      *((_DWORD *)a2 + 2) = 0;
    }
  }
  if ( (*(_WORD *)(a3 + 22) & 0x100) != 0 )
    *((_WORD *)a2 + 11) = *((_WORD *)a2 + 11)
                        ^ (*((_WORD *)a2 + 11)
                         ^ (((*(_WORD *)(a3 + 22) >> 11) & 3) << 11))
                        & 0x1800
                        | 0x100;
}

//------------------------------------------------------------------------------
// Address: 0x1013FE90
// Name: public: class GFxTextParagraphFormat GFxTextParagraphFormat::Intersection(class GFxTextParagraphFormat const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraphFormat::Intersection(
        CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        GFxTextParagraphFormat *a2,
        int a3)
{
  int v4; // edx
  __int16 v5; // ax
  __int16 v6; // ax
  __int16 v7; // ax
  __int16 v8; // ax
  __int16 v9; // ax

  *(_DWORD *)a2 = &GRefCountImplCore::`vftable';
  *((_DWORD *)a2 + 1) = 1;
  *(_DWORD *)a2 = &GFxTextParagraphFormat::`vftable';
  *((_DWORD *)a2 + 2) = 0;
  *((_DWORD *)a2 + 3) = 0;
  *((_DWORD *)a2 + 4) = 0;
  *((_DWORD *)a2 + 5) = 0;
  if ( (BYTE6(this->m_Proxy.m_pfnProxied) & 1) != 0
    && (*(_BYTE *)(a3 + 22) & 1) != 0
    && ((*(_WORD *)(a3 + 22) ^ WORD3(this->m_Proxy.m_pfnProxied)) & 0x600) == 0 )
  {
    *((_WORD *)a2 + 11) = (((*(_WORD *)(a3 + 22) >> 9) & 3) << 9) | 1;
  }
  if ( (WORD3(this->m_Proxy.m_pfnProxied) & 0x80u) != 0 && (*(_WORD *)(a3 + 22) & 0x80u) != 0 )
  {
    v4 = *(_WORD *)(a3 + 22) & 0x8000;
    if ( ((WORD3(this->m_Proxy.m_pfnProxied) & 0x8000) != 0) == (v4 != 0) )
    {
      if ( (_WORD)v4 != 0 )
        *((_WORD *)a2 + 11) |= 0x8000u;
      else
        *((_WORD *)a2 + 11) &= ~0x8000u;
      *((_WORD *)a2 + 11) |= 0x80u;
    }
  }
  if ( (BYTE6(this->m_Proxy.m_pfnProxied) & 2) != 0 && (*(_BYTE *)(a3 + 22) & 2) != 0 )
  {
    v5 = *(_WORD *)(a3 + 12);
    if ( LOWORD(this->m_iRefs) == v5 )
    {
      *((_WORD *)a2 + 11) |= 2u;
      *((_WORD *)a2 + 6) = v5;
    }
  }
  if ( (BYTE6(this->m_Proxy.m_pfnProxied) & 4) != 0 && (*(_BYTE *)(a3 + 22) & 4) != 0 )
  {
    v6 = *(_WORD *)(a3 + 14);
    if ( HIWORD(this->m_iRefs) == v6 )
    {
      *((_WORD *)a2 + 11) |= 4u;
      *((_WORD *)a2 + 7) = v6;
    }
  }
  if ( (BYTE6(this->m_Proxy.m_pfnProxied) & 8) != 0 && (*(_BYTE *)(a3 + 22) & 8) != 0 )
  {
    v7 = *(_WORD *)(a3 + 16);
    if ( LOWORD(this->m_Proxy.m_pfnProxied) == v7 )
    {
      *((_WORD *)a2 + 11) |= 8u;
      *((_WORD *)a2 + 8) = v7;
    }
  }
  if ( (BYTE6(this->m_Proxy.m_pfnProxied) & 0x10) != 0 && (*(_BYTE *)(a3 + 22) & 0x10) != 0 )
  {
    v8 = *(_WORD *)(a3 + 18);
    if ( WORD1(this->m_Proxy.m_pfnProxied) == v8 )
    {
      *((_WORD *)a2 + 11) |= 0x10u;
      *((_WORD *)a2 + 9) = v8;
    }
  }
  if ( (BYTE6(this->m_Proxy.m_pfnProxied) & 0x20) != 0 && (*(_BYTE *)(a3 + 22) & 0x20) != 0 )
  {
    v9 = *(_WORD *)(a3 + 20);
    if ( WORD2(this->m_Proxy.m_pfnProxied) == v9 )
    {
      *((_WORD *)a2 + 11) |= 0x20u;
      *((_WORD *)a2 + 10) = v9;
    }
  }
  if ( (BYTE6(this->m_Proxy.m_pfnProxied) & 0x40) != 0
    && (*(_BYTE *)(a3 + 22) & 0x40) != 0
    && GFxTextParagraphFormat::TabStopsEqual(this, psrcTabStops: *(CMaterialSystem **)(a3 + 8)) )
  {
    GFxTextParagraphFormat::SetTabStops(this: (void **)a2, psrcTabStops: *(CMaterialSystem **)(a3 + 8));
  }
  if ( (WORD3(this->m_Proxy.m_pfnProxied) & 0x100) != 0
    && (*(_WORD *)(a3 + 22) & 0x100) != 0
    && ((*(_WORD *)(a3 + 22) ^ WORD3(this->m_Proxy.m_pfnProxied)) & 0x1800) == 0 )
  {
    *((_WORD *)a2 + 11) = *((_WORD *)a2 + 11)
                        ^ (*((_WORD *)a2 + 11)
                         ^ (((*(_WORD *)(a3 + 22) >> 11) & 3) << 11))
                        & 0x1800
                        | 0x100;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140370
// Name: public: class GFxFontHandle __near * GFxTextFormat::GetFontHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *__thiscall GFxTextFormat::GetFontHandle(
        GFxTextFormat *this)
{
  _DWORD *v1; // eax
  char v2; // bl
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v3; // edi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v4; // esi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *result; // eax
  bool v6; // zf
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v7; // [esp+Ch] [ebp-4h]

  if ( (*((_WORD *)this + 21) & 0x800) != 0 )
  {
    v1 = *((_DWORD **)this + 7);
    v2 = 1;
    if ( v1 != nullptr )
      ++*v1;
    v3 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
         + 7);
    v7 = v3;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
    v7 = nullptr;
    v3 = nullptr;
    v2 = 2;
  }
  result = v7;
  if ( (v2 & 2) != 0 )
  {
    v2 &= ~2u;
    if ( v4 != nullptr )
    {
      v6 = LODWORD(v4->m_pfnProxied)-- == 1;
      if ( v6 )
      {
        GFxFontHandle::~GFxFontHandle(this: v4);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
        result = v7;
      }
    }
  }
  if ( (v2 & 1) != 0 && v3 != nullptr )
  {
    v6 = LODWORD(v3->m_pfnProxied)-- == 1;
    if ( v6 )
    {
      GFxFontHandle::~GFxFontHandle(this: v3);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
      return v7;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10140410
// Name: public: void GFxTextFormat::SetFontList(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetFontList(GString *this, struct GString *src)
{
  int Length; // ebx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v4; // edi
  int v6; // eax
  int v7; // eax
  int v8; // [esp+0h] [ebp-8h]

  if ( (*((_WORD *)this + 21) & 0x800) != 0 )
  {
    Length = GString::GetLength(this: this + 2);
    if ( Length != GString::GetLength(this: src)
      || GString::CompareNoCase(
           a1: (char *)((*(_DWORD *)(this + 2) & 0xFFFFFFFC) + 8),
           a2: (char *)((src->HeapTypeBits & 0xFFFFFFFC) + 8)) != 0 )
    {
      v4 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
           + 7);
      if ( v4 != nullptr && LODWORD(v4->m_pfnProxied)-- == 1 )
      {
        GFxFontHandle::~GFxFontHandle(this: v4);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
      }
      *((_DWORD *)this + 7) = 0;
      *((_WORD *)this + 21) &= ~0x800u;
    }
  }
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 2),
    src,
    a3: v8);
  v6 = *((_DWORD *)this + 2);
  *((_WORD *)this + 21) |= 4u;
  strchr(string: (unsigned __int8 *)((v6 & 0xFFFFFFFC) + 8), chr: 0x2Cu);
  if ( v7 != 0 )
    *((_WORD *)this + 21) &= ~0x1000u;
  else
    *((_WORD *)this + 21) |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x101404E0
// Name: public: void GFxTextFormat::SetFontList(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetFontList(
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *this,
        char *pfontList,
        unsigned int fontListSz)
{
  int v3; // ebx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v5; // edi
  int v7; // edi
  int v8; // eax

  v3 = fontListSz;
  if ( fontListSz == -1 )
    v3 = strlen(pfontList);
  if ( (*((_WORD *)this + 21) & 0x800) != 0
    && (GString::GetLength(this: (GString *)this + 2) != v3
     || GString::CompareNoCase(a1: (const char *)((*(_DWORD *)(this + 1) & 0xFFFFFFFC) + 8), a2: pfontList, a3: v3) != 0) )
  {
    v5 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
         + 7);
    if ( v5 != nullptr && LODWORD(v5->m_pfnProxied)-- == 1 )
    {
      GFxFontHandle::~GFxFontHandle(this: v5);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
    }
    *((_DWORD *)this + 7) = 0;
    *((_WORD *)this + 21) &= ~0x800u;
  }
  GString::Clear(this: (GString *)this + 2);
  GString::AppendString(
    this: (CUtlMemory<CImagePacker,int> *)(this + 1),
    putf8str: (CImagePacker *)pfontList,
    utf8StrSz: v3);
  v7 = *((_DWORD *)this + 2);
  *((_WORD *)this + 21) |= 4u;
  strchr(string: (unsigned __int8 *)((v7 & 0xFFFFFFFC) + 8), chr: 0x2Cu);
  if ( v8 != 0 )
    *((_WORD *)this + 21) &= ~0x1000u;
  else
    *((_WORD *)this + 21) |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x101405C0
// Name: public: void GFxTextFormat::SetFontList(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetFontList(
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *this,
        IMaterialInternal *pfontList,
        void (__thiscall *fontListSz)(IMaterial *this))
{
  void (__thiscall *v3)(IMaterial *); // ebx
  const CFileSystemPassThru *v5; // ecx
  int v6; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v10; // edi
  bool v11; // zf
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v12; // edi
  int v13; // edi
  int v14; // eax

  v3 = fontListSz;
  if ( fontListSz == (void (__thiscall *)(IMaterial *))-1 )
  {
    v3 = (void (__thiscall *)(IMaterial *))G_wcslen(pwch: (const wchar_t *)pfontList);
    fontListSz = v3;
  }
  if ( (*((_WORD *)this + 21) & 0x800) != 0 )
  {
    if ( (void (__thiscall *)(IMaterial *))GString::GetLength(this: (GString *)this + 2) == v3 )
    {
      v6 = 0;
      if ( v3 != nullptr )
      {
        while ( 1 )
        {
          G_towlower(charCode: v5, charCodea: *(char *)((*(_DWORD *)(this + 1) & 0xFFFFFFFC) + v6 + 8));
          v8 = v7;
          G_towlower(
            charCode: (const CFileSystemPassThru *)pfontList,
            charCodea: *((_WORD *)&pfontList->__vftable + v6));
          if ( v8 != v9 )
            break;
          v3 = fontListSz;
          if ( ++v6 >= (unsigned int)fontListSz )
            goto LABEL_17;
        }
        v10 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
              + 7);
        if ( v10 != nullptr )
        {
          v11 = LODWORD(v10->m_pfnProxied)-- == 1;
          if ( v11 )
          {
            GFxFontHandle::~GFxFontHandle(this: v10);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
          }
        }
        v3 = fontListSz;
        *((_DWORD *)this + 7) = 0;
        *((_WORD *)this + 21) &= ~0x800u;
      }
    }
    else
    {
      v12 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
            + 7);
      if ( v12 != nullptr )
      {
        v11 = LODWORD(v12->m_pfnProxied)-- == 1;
        if ( v11 )
        {
          GFxFontHandle::~GFxFontHandle(this: v12);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
        }
      }
      *((_DWORD *)this + 7) = 0;
      *((_WORD *)this + 21) &= ~0x800u;
    }
  }
LABEL_17:
  GString::Clear(this: (GString *)this + 2);
  GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)(this + 1), pstr: (RGB888_t *)pfontList, a3: (int)v3);
  v13 = *((_DWORD *)this + 2);
  *((_WORD *)this + 21) |= 4u;
  strchr(string: (unsigned __int8 *)((v13 & 0xFFFFFFFC) + 8), chr: 0x2Cu);
  if ( v14 != 0 )
    *((_WORD *)this + 21) &= ~0x1000u;
  else
    *((_WORD *)this + 21) |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x10140700
// Name: public: void GFxTextFormat::SetFontName(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetFontName(
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *this,
        char *pfontName,
        unsigned int fontNameSz)
{
  unsigned int v3; // eax

  v3 = fontNameSz;
  if ( fontNameSz == -1 )
    v3 = strlen(pfontName);
  GFxTextFormat::SetFontList(this, pfontList: pfontName, fontListSz: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10140730
// Name: public: void GFxTextFormat::SetFontHandle(class GFxFontHandle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetFontHandle(GFxTextFormat *this, struct GFxFontHandle *a2)
{
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v3; // esi

  if ( a2 != nullptr )
    ++*(_DWORD *)a2;
  v3 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
       + 7);
  if ( v3 != nullptr && LODWORD(v3->m_pfnProxied)-- == 1 )
  {
    GFxFontHandle::~GFxFontHandle(this: v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
  *((_DWORD *)this + 7) = a2;
  *((_WORD *)this + 21) |= 0x800u;
}

//------------------------------------------------------------------------------
// Address: 0x10140780
// Name: public: void GFxTextFormat::SetBold(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetBold(GFxTextFormat *this, bool a2)
{
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v3; // edi

  if ( (*((_WORD *)this + 21) & 0x800) != 0 && (*((_BYTE *)this + 40) & 1) != a2 )
  {
    v3 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
         + 7);
    if ( v3 != nullptr && LODWORD(v3->m_pfnProxied)-- == 1 )
    {
      GFxFontHandle::~GFxFontHandle(this: v3);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
    }
    *((_DWORD *)this + 7) = 0;
    *((_WORD *)this + 21) &= ~0x800u;
  }
  if ( a2 )
    *((_BYTE *)this + 40) |= 1u;
  else
    *((_BYTE *)this + 40) &= ~1u;
  *((_WORD *)this + 21) |= 0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x10140800
// Name: public: void GFxTextFormat::SetItalic(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetItalic(GFxTextFormat *this, bool a2)
{
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v3; // edi

  if ( (*((_WORD *)this + 21) & 0x800) != 0 && ((*((_BYTE *)this + 40) & 2) != 0) != a2 )
  {
    v3 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
         + 7);
    if ( v3 != nullptr && LODWORD(v3->m_pfnProxied)-- == 1 )
    {
      GFxFontHandle::~GFxFontHandle(this: v3);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
    }
    *((_DWORD *)this + 7) = 0;
    *((_WORD *)this + 21) &= ~0x800u;
  }
  if ( a2 )
    *((_BYTE *)this + 40) |= 2u;
  else
    *((_BYTE *)this + 40) &= ~2u;
  *((_WORD *)this + 21) |= 0x20u;
}

//------------------------------------------------------------------------------
// Address: 0x10140880
// Name: public: class GFxTextFormat GFxTextFormat::Merge(class GFxTextFormat const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxTextFormat::Merge@<eax>(int a1@<ecx>, int a2@<ebx>, int a3, int fmt)
{
  int v5; // eax
  _DWORD *v6; // eax
  __int16 v7; // cx
  void (__cdecl **m_pElements)(int); // eax
  __int16 v9; // dx
  __int16 v10; // dx
  __int16 v11; // cx
  void (__cdecl **v12)(int); // ebx
  __int16 v13; // ax
  __int16 v14; // ax
  char **p_pName; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *FontHandle; // eax
  int v17; // ebx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *m_Size; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v19; // edi
  int v20; // eax
  int v21; // esi
  int m_nGrowSize; // eax
  int v23; // eax
  void (__cdecl **v24)(int); // edx
  __int16 v25; // cx
  __int16 v26; // ax
  CUtlBuffer *v28; // [esp-4h] [ebp-3Ch]
  CUtlBuffer *v29; // [esp-4h] [ebp-3Ch]
  CUtlBuffer *pHeap; // [esp-4h] [ebp-3Ch]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v32; // [esp+8h] [ebp-30h] BYREF
  GStringDH v33; // [esp+10h] [ebp-28h] BYREF
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > v34; // [esp+18h] [ebp-20h] BYREF
  __int16 v35; // [esp+2Ch] [ebp-Ch]
  __int16 v36; // [esp+2Eh] [ebp-Ah]
  char v37; // [esp+30h] [ebp-8h]
  __int16 v38; // [esp+32h] [ebp-6h]
  char v39; // [esp+34h] [ebp-4h]
  char v40; // [esp+35h] [ebp-3h]
  char v41; // [esp+36h] [ebp-2h]
  char v42; // [esp+37h] [ebp-1h]

  v28 = *(CUtlBuffer **)(a1 + 12);
  v32.m_pObject = (IMaterialInternal *)1;
  v32.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))&GFxTextFormat::`vftable';
  v42 = 0;
  GStringDH::CopyConstructHelper(this: &v33, a2: (const struct GString *)(a1 + 8), pheap: v28);
  v29 = *(CUtlBuffer **)(a1 + 12);
  v41 = 0;
  GStringDH::CopyConstructHelper(this: (GStringDH *)&v34, a2: (const struct GString *)(a1 + 16), pheap: v29);
  v5 = *(_DWORD *)(a1 + 24);
  if ( v5 != 0 )
    ++*(_DWORD *)(v5 + 4);
  v6 = *(_DWORD **)(a1 + 28);
  v34.m_Memory.m_nGrowSize = *(_DWORD *)(a1 + 24);
  if ( v6 != nullptr )
    ++*v6;
  v7 = *(_WORD *)(a1 + 36);
  m_pElements = *(void (__cdecl ***)(int))(a1 + 32);
  v34.m_Size = *(_DWORD *)(a1 + 28);
  v9 = *(_WORD *)(a1 + 38);
  v35 = v7;
  LOBYTE(v7) = *(_BYTE *)(a1 + 40);
  v36 = v9;
  v10 = *(_WORD *)(a1 + 42);
  v37 = v7;
  LOBYTE(v7) = *(_BYTE *)(fmt + 42) >> 4;
  v34.m_pElements = m_pElements;
  v38 = v10;
  if ( (v7 & 1) != 0 )
  {
    GFxTextFormat::SetBold(this: (GFxTextFormat *)&v32, a2: *(_BYTE *)(fmt + 40) & 1);
    m_pElements = v34.m_pElements;
  }
  if ( (*(_BYTE *)(fmt + 42) & 0x20) != 0 )
  {
    GFxTextFormat::SetItalic(this: (GFxTextFormat *)&v32, a2: (*(_BYTE *)(fmt + 40) & 2) != 0);
    m_pElements = v34.m_pElements;
  }
  v11 = *(_WORD *)(fmt + 42);
  if ( (v11 & 0x40) != 0 )
  {
    if ( (*(_BYTE *)(fmt + 40) & 4) != 0 )
      v37 |= 4u;
    else
      v37 &= ~4u;
    v38 |= 0x40u;
  }
  if ( (v11 & 0x80u) != 0 )
  {
    if ( (*(_BYTE *)(fmt + 40) & 8) != 0 )
      v37 |= 8u;
    else
      v37 &= ~8u;
    v38 |= 0x80u;
  }
  if ( (*(_BYTE *)(fmt + 42) & 1) != 0 )
  {
    m_pElements = *(void (__cdecl ***)(int))(fmt + 32);
    v38 |= 1u;
    v34.m_pElements = m_pElements;
  }
  if ( (v11 & 0x400) != 0 )
  {
    v12 = (void (__cdecl **)(int))((unsigned int)m_pElements & 0xFFFFFF | (*(unsigned __int8 *)(fmt + 35) << 24));
    v38 |= 0x400u;
    v34.m_pElements = v12;
  }
  if ( (v11 & 2) != 0 )
  {
    v13 = *(_WORD *)(fmt + 36);
    v38 |= 2u;
    v35 = v13;
  }
  if ( (v11 & 8) != 0 )
  {
    v14 = *(_WORD *)(fmt + 38);
    v38 |= 8u;
    v36 = v14;
  }
  if ( (v11 & 4) != 0 )
  {
    if ( ((int)GFxRectangle_NaNParams.ChildHeaps.Root.pPrev & 1) == 0 )
    {
      GFxRectangle_NaNParams.ChildHeaps.Root.pPrev = (GMemoryHeap *)((int)GFxRectangle_NaNParams.ChildHeaps.Root.pPrev
                                                                   | 1);
      GString::GString(this: (CUtlMemory<CImagePacker,int> *)&GFxRectangle_NaNParams.Info.pName);
      atexit(func: (void (__cdecl *)())GFxTextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__);
    }
    p_pName = (char **)(fmt + 8);
    if ( (*(_BYTE *)(fmt + 42) & 4) == 0 )
      p_pName = &GFxRectangle_NaNParams.Info.pName;
    GFxTextFormat::SetFontList(this: (GString *)&v32, src: (struct GString *)p_pName);
  }
  if ( (*(_WORD *)(fmt + 42) & 0x800) != 0 )
  {
    FontHandle = GFxTextFormat::GetFontHandle(this: (GFxTextFormat *)fmt);
    v17 = (int)FontHandle;
    if ( FontHandle != nullptr )
      ++LODWORD(FontHandle->m_pfnProxied);
    m_Size = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v34.m_Size;
    if ( v34.m_Size != 0 )
    {
      --*(_DWORD *)v34.m_Size;
      v19 = m_Size;
      if ( LODWORD(m_Size->m_pfnProxied) == 0 )
      {
        GFxFontHandle::~GFxFontHandle(this: m_Size);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v19);
      }
    }
    v38 |= 0x800u;
    v34.m_Size = v17;
  }
  if ( (*(_WORD *)(fmt + 42) & 0x100) == 0 || GString::GetLength(this: (GString *)(fmt + 16)) != 0 )
  {
    if ( (*(_WORD *)(fmt + 42) & 0x100) != 0 && GString::GetLength(this: (GString *)(fmt + 16)) != 0 )
    {
      GString::operator=(this: &v34, src: (_DWORD *)(fmt + 16), a3: a2);
      v38 |= 0x100u;
    }
  }
  else
  {
    GString::Clear(this: (GString *)&v34);
    v38 &= ~0x100u;
  }
  if ( (*(_WORD *)(fmt + 42) & 0x200) != 0 )
  {
    GFxTextFormat::GetImageDesc(this: (CMemberFuncProxy3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CFuncMemPolicyNone> *)fmt);
    v21 = v20;
    if ( v20 != 0 )
      ++*(_DWORD *)(v20 + 4);
    if ( v34.m_Memory.m_nGrowSize != 0 )
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v34.m_Memory.m_nGrowSize);
    v38 |= 0x200u;
    v34.m_Memory.m_nGrowSize = v21;
  }
  pHeap = (CUtlBuffer *)v33.pHeap;
  *(_DWORD *)a3 = &GRefCountImplCore::`vftable';
  *(_DWORD *)(a3 + 4) = 1;
  *(_DWORD *)a3 = &GFxTextFormat::`vftable';
  v40 = 0;
  GStringDH::CopyConstructHelper(this: (GStringDH *)(a3 + 8), a2: &v33, pheap: pHeap);
  v39 = 0;
  GStringDH::CopyConstructHelper(
    this: (GStringDH *)(a3 + 16),
    a2: (const struct GString *)&v34,
    pheap: (CUtlBuffer *)v33.pHeap);
  m_nGrowSize = v34.m_Memory.m_nGrowSize;
  if ( v34.m_Memory.m_nGrowSize != 0 )
  {
    ++*(_DWORD *)(v34.m_Memory.m_nGrowSize + 4);
    m_nGrowSize = v34.m_Memory.m_nGrowSize;
  }
  *(_DWORD *)(a3 + 24) = m_nGrowSize;
  v23 = v34.m_Size;
  if ( v34.m_Size != 0 )
  {
    ++*(_DWORD *)v34.m_Size;
    v23 = v34.m_Size;
  }
  v24 = v34.m_pElements;
  v25 = v36;
  *(_DWORD *)(a3 + 28) = v23;
  *(_WORD *)(a3 + 36) = v35;
  v26 = v38;
  *(_DWORD *)(a3 + 32) = v24;
  LOBYTE(v24) = v37;
  *(_WORD *)(a3 + 38) = v25;
  *(_BYTE *)(a3 + 40) = (_BYTE)v24;
  *(_WORD *)(a3 + 42) = v26;
  GFxTextFormat::~GFxTextFormat(this: &v32);
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x10140BD0
// Name: public: class GFxTextFormat GFxTextFormat::Intersection(class GFxTextFormat const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextFormat::Intersection(int this, int a2, int fmt)
{
  struct GMemoryHeap *v3; // ebx
  char v5; // dl
  int m_pElements; // ecx
  bool v7; // al
  bool v8; // al
  __int16 v9; // dx
  void (__cdecl **v10)(int); // eax
  unsigned __int8 v11; // al
  __int16 v12; // cx
  double v13; // st7
  char **FontList; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *FontHandle; // ebx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v16; // eax
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // eax
  int v21; // esi
  int m_nGrowSize; // eax
  int m_Size; // eax
  __int16 v24; // cx
  __int16 v25; // dx
  void (__cdecl **v26)(int); // eax
  __int16 v27; // cx
  CUtlBuffer *pHeap; // [esp-4h] [ebp-48h]
  int v30; // [esp+0h] [ebp-44h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v31; // [esp+Ch] [ebp-38h] BYREF
  GStringDH v32; // [esp+14h] [ebp-30h] BYREF
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > v33; // [esp+1Ch] [ebp-28h] BYREF
  int v34; // [esp+30h] [ebp-14h]
  char v35; // [esp+34h] [ebp-10h]
  __int16 v36; // [esp+36h] [ebp-Eh]
  void (__cdecl **v37)(int); // [esp+38h] [ebp-Ch]
  float v38; // [esp+3Ch] [ebp-8h]
  char v39; // [esp+43h] [ebp-1h]

  v3 = *(struct GMemoryHeap **)(fmt + 12);
  v31.m_pObject = (IMaterialInternal *)1;
  v31.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))&GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: &v32, a2: v3);
  GStringDH::GStringDH(this: (GStringDH *)&v33, a2: v3);
  v5 = *(_BYTE *)(this + 42) >> 4;
  m_pElements = -16777216;
  v33.m_Memory.m_nGrowSize = 0;
  v33.m_Size = 0;
  v33.m_pElements = (void (__cdecl **)(int))-16777216;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  if ( (v5 & 1) != 0 && (*(_BYTE *)(fmt + 42) & 0x10) != 0 )
  {
    v7 = *(_BYTE *)(fmt + 40) & 1;
    if ( (*(_BYTE *)(this + 40) & 1) == v7 )
    {
      GFxTextFormat::SetBold(this: (GFxTextFormat *)&v31, a2: v7);
      m_pElements = (int)v33.m_pElements;
    }
  }
  if ( (*(_BYTE *)(this + 42) & 0x20) != 0 && (*(_BYTE *)(fmt + 42) & 0x20) != 0 )
  {
    v8 = (*(_BYTE *)(fmt + 40) & 2) != 0;
    if ( ((*(_BYTE *)(this + 40) & 2) != 0) == v8 )
    {
      GFxTextFormat::SetItalic(this: (GFxTextFormat *)&v31, a2: v8);
      m_pElements = (int)v33.m_pElements;
    }
  }
  v9 = *(_WORD *)(this + 42);
  if ( (v9 & 0x40) != 0
    && (*(_BYTE *)(fmt + 42) & 0x40) != 0
    && ((*(_BYTE *)(this + 40) & 4) != 0) == ((*(_BYTE *)(fmt + 40) & 4) != 0) )
  {
    if ( (*(_BYTE *)(fmt + 40) & 4) != 0 )
      v35 |= 4u;
    else
      v35 &= ~4u;
    v36 |= 0x40u;
  }
  if ( (v9 & 0x80u) != 0
    && *(char *)(fmt + 42) < 0
    && ((*(_BYTE *)(this + 40) & 8) != 0) == ((*(_BYTE *)(fmt + 40) & 8) != 0) )
  {
    if ( (*(_BYTE *)(fmt + 40) & 8) != 0 )
      v35 |= 8u;
    else
      v35 &= ~8u;
    v36 |= 0x80u;
  }
  if ( (*(_BYTE *)(this + 42) & 1) != 0 && (*(_BYTE *)(fmt + 42) & 1) != 0 )
  {
    v10 = *(void (__cdecl ***)(int))(fmt + 32);
    v37 = v10;
    if ( *(void (__cdecl ***)(int))(this + 32) == v10 )
    {
      v36 |= 1u;
      m_pElements = (int)v10;
      v33.m_pElements = v10;
    }
  }
  if ( (v9 & 0x400) != 0 && (*(_WORD *)(fmt + 42) & 0x400) != 0 )
  {
    v11 = *(_BYTE *)(fmt + 35);
    if ( *(_BYTE *)(this + 35) == v11 )
    {
      v36 |= 0x400u;
      v33.m_pElements = (void (__cdecl **)(int))(m_pElements & 0xFFFFFF | (v11 << 24));
    }
  }
  if ( (v9 & 2) != 0 && (*(_BYTE *)(fmt + 42) & 2) != 0 )
  {
    LODWORD(v38) = *(__int16 *)(this + 36);
    v12 = *(_WORD *)(fmt + 36);
    v38 = (double)SLODWORD(v38) / 20.0;
    v13 = v38;
    v38 = (double)v12 / 20.0;
    if ( v38 == v13 )
    {
      v36 |= 2u;
      LOWORD(v34) = v12;
    }
  }
  if ( (v9 & 8) != 0 && (*(_BYTE *)(fmt + 42) & 8) != 0 && *(_WORD *)(this + 38) == *(_WORD *)(fmt + 38) )
  {
    HIWORD(v34) = *(_WORD *)(fmt + 38);
    v36 |= 8u;
  }
  if ( (v9 & 4) != 0
    && (*(_BYTE *)(fmt + 42) & 4) != 0
    && GString::CompareNoCase(
         a1: (char *)((*(_DWORD *)(this + 8) & 0xFFFFFFFC) + 8),
         a2: (char *)((*(_DWORD *)(fmt + 8) & 0xFFFFFFFC) + 8)) == 0 )
  {
    FontList = GFxTextFormat::GetFontList(this: (char **)fmt);
    GFxTextFormat::SetFontList(this: (GString *)&v31, src: (struct GString *)FontList);
  }
  if ( (*(_WORD *)(this + 42) & 0x800) != 0 && (*(_WORD *)(fmt + 42) & 0x800) != 0 )
  {
    FontHandle = GFxTextFormat::GetFontHandle(this: (GFxTextFormat *)fmt);
    if ( GFxTextFormat::GetFontHandle((GFxTextFormat *)this) == FontHandle )
    {
      v16 = GFxTextFormat::GetFontHandle(this: (GFxTextFormat *)fmt);
      GFxTextFormat::SetFontHandle(this: (GFxTextFormat *)&v31, a2: (struct GFxFontHandle *)v16);
    }
  }
  if ( (*(_WORD *)(this + 42) & 0x100) != 0
    && GString::GetLength(this: (GString *)(this + 16)) != 0
    && (*(_WORD *)(fmt + 42) & 0x100) != 0
    && GString::GetLength(this: (GString *)(fmt + 16)) != 0
    && GString::CompareNoCase(
         a1: (char *)((*(_DWORD *)(this + 16) & 0xFFFFFFFC) + 8),
         a2: (char *)((*(_DWORD *)(fmt + 16) & 0xFFFFFFFC) + 8)) == 0 )
  {
    GString::operator=(this: &v33, src: (_DWORD *)(fmt + 16), a3: v30);
    v36 |= 0x100u;
  }
  if ( (*(_WORD *)(this + 42) & 0x200) != 0 && (*(_WORD *)(fmt + 42) & 0x200) != 0 )
  {
    GFxTextFormat::GetImageDesc(this: (CMemberFuncProxy3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CFuncMemPolicyNone> *)fmt);
    v18 = v17;
    GFxTextFormat::GetImageDesc((CMemberFuncProxy3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CFuncMemPolicyNone> *)this);
    if ( v19 == v18 )
    {
      GFxTextFormat::GetImageDesc(this: (CMemberFuncProxy3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CFuncMemPolicyNone> *)fmt);
      v21 = v20;
      if ( v20 != 0 )
        ++*(_DWORD *)(v20 + 4);
      if ( v33.m_Memory.m_nGrowSize != 0 )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v33.m_Memory.m_nGrowSize);
      v36 |= 0x200u;
      v33.m_Memory.m_nGrowSize = v21;
    }
  }
  pHeap = (CUtlBuffer *)v32.pHeap;
  *(_DWORD *)a2 = &GRefCountImplCore::`vftable';
  *(_DWORD *)(a2 + 4) = 1;
  *(_DWORD *)a2 = &GFxTextFormat::`vftable';
  GStringDH::CopyConstructHelper(this: (GStringDH *)(a2 + 8), a2: &v32, pheap: pHeap);
  v39 = 0;
  GStringDH::CopyConstructHelper(
    this: (GStringDH *)(a2 + 16),
    a2: (const struct GString *)&v33,
    pheap: (CUtlBuffer *)v32.pHeap);
  m_nGrowSize = v33.m_Memory.m_nGrowSize;
  if ( v33.m_Memory.m_nGrowSize != 0 )
  {
    ++*(_DWORD *)(v33.m_Memory.m_nGrowSize + 4);
    m_nGrowSize = v33.m_Memory.m_nGrowSize;
  }
  *(_DWORD *)(a2 + 24) = m_nGrowSize;
  m_Size = v33.m_Size;
  if ( v33.m_Size != 0 )
  {
    ++*(_DWORD *)v33.m_Size;
    m_Size = v33.m_Size;
  }
  v24 = v34;
  v25 = HIWORD(v34);
  *(_DWORD *)(a2 + 28) = m_Size;
  v26 = v33.m_pElements;
  *(_WORD *)(a2 + 36) = v24;
  v27 = v36;
  *(_DWORD *)(a2 + 32) = v26;
  LOBYTE(v26) = v35;
  *(_WORD *)(a2 + 42) = v27;
  *(_WORD *)(a2 + 38) = v25;
  *(_BYTE *)(a2 + 40) = (_BYTE)v26;
  GFxTextFormat::~GFxTextFormat(this: &v31);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10140FC0
// Name: public: void GFxTextFormat::InitByDefaultValues(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextFormat::InitByDefaultValues(
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *this)
{
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v2; // edi
  bool v3; // zf
  __int16 v4; // ax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v5; // edi
  __int16 v6; // ax

  *((_DWORD *)this + 8) &= 0xFF000000;
  *((_WORD *)this + 21) |= 1u;
  GFxTextFormat::SetFontList(
    (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)this,
    pfontList: (char *)&stru_102A8E54.m_pElements,
    fontListSz: 0xFFFFFFFF);
  *((_WORD *)this + 21) |= 8u;
  *((_WORD *)this + 19) = 240;
  if ( (*((_WORD *)this + 21) & 0x800) != 0 && (*(_BYTE *)(this + 5) & 1) != 0 )
  {
    v2 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
         + 7);
    if ( v2 != nullptr )
    {
      v3 = LODWORD(v2->m_pfnProxied)-- == 1;
      if ( v3 )
      {
        GFxFontHandle::~GFxFontHandle(this: v2);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
      }
    }
    *((_DWORD *)this + 7) = 0;
    *((_WORD *)this + 21) &= ~0x800u;
  }
  *((_WORD *)this + 21) |= 0x10u;
  v4 = *((_WORD *)this + 21);
  *((_BYTE *)this + 40) &= ~1u;
  if ( (v4 & 0x800) != 0 && (*(_BYTE *)(this + 5) & 2) != 0 )
  {
    v5 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
         + 7);
    if ( v5 != nullptr )
    {
      v3 = LODWORD(v5->m_pfnProxied)-- == 1;
      if ( v3 )
      {
        GFxFontHandle::~GFxFontHandle(this: v5);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
      }
    }
    *((_DWORD *)this + 7) = 0;
    *((_WORD *)this + 21) &= ~0x800u;
  }
  v6 = *((_WORD *)this + 21);
  *((_BYTE *)this + 40) &= 0xF1u;
  *((_DWORD *)this + 8) |= 0xFF000000;
  *((_WORD *)this + 18) = 0;
  *((_WORD *)this + 21) = v6 & 0xFB1D | 0xE0;
  GString::Clear(this: (GString *)this + 4);
  *((_WORD *)this + 21) &= ~0x100u;
  return 65279;
}

//------------------------------------------------------------------------------
// Address: 0x10141930
// Name: public: bool GFxTextAllocator::FlushTextFormatCache(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextAllocator::FlushTextFormatCache(CMaterial *this, bool noAllocationsAllowed)
{
  void **p_m_minLightmapPageID; // edi
  unsigned int *m_minLightmapPageID; // ecx
  unsigned int v4; // eax
  void **v5; // esi
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  char *v8; // edx
  unsigned int v9; // ecx
  char *v10; // edx
  _DWORD *v11; // ecx
  _DWORD *v12; // eax
  float v13; // eax
  unsigned int *v14; // eax
  unsigned int v15; // ecx
  void **v17; // [esp+4h] [ebp-10h] BYREF
  signed int v18; // [esp+8h] [ebp-Ch]
  CMaterial *v19; // [esp+Ch] [ebp-8h]
  unsigned int tfSize; // [esp+10h] [ebp-4h]

  p_m_minLightmapPageID = (void **)&this->m_minLightmapPageID;
  v19 = this;
  m_minLightmapPageID = (unsigned int *)this->m_minLightmapPageID;
  v4 = 0;
  if ( m_minLightmapPageID != nullptr )
    tfSize = *m_minLightmapPageID;
  else
    tfSize = 0;
  if ( m_minLightmapPageID != nullptr )
  {
    v6 = m_minLightmapPageID[1];
    v7 = m_minLightmapPageID + 2;
    do
    {
      if ( *v7 != -2 )
        break;
      ++v4;
      v7 += 3;
    }
    while ( v4 <= v6 );
    v5 = p_m_minLightmapPageID;
  }
  else
  {
    v5 = nullptr;
  }
  v18 = v4;
  v17 = v5;
  while ( v5 != nullptr && *v5 != nullptr && (signed int)v4 <= *((_DWORD *)*v5 + 1) )
  {
    if ( *(_DWORD *)(*((_DWORD *)*v5 + 3 * v4 + 4) + 4) == 1 )
      GHashSetBase<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor,GAllocatorLH<GFxTextFormatPtrWrapper<GFxTextFormat>,324>,GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor>>::Iterator::Remove(this: &v17);
    v5 = v17;
    v8 = (char *)*v17;
    v9 = *((_DWORD *)*v17 + 1);
    v4 = v18;
    if ( v18 <= (int)v9 )
    {
      v4 = v18 + 1;
      v18 = v4;
      if ( v4 <= v9 )
      {
        v10 = &v8[12 * v4 + 8];
        do
        {
          if ( *(_DWORD *)v10 != -2 )
            break;
          ++v4;
          v10 += 12;
          v18 = v4;
        }
        while ( v4 <= v9 );
      }
    }
  }
  if ( !noAllocationsAllowed )
  {
    v11 = *p_m_minLightmapPageID;
    if ( *p_m_minLightmapPageID != nullptr )
      v12 = (_DWORD *)*v11;
    else
      v12 = nullptr;
    LODWORD(v13) = (unsigned int)(5 * (_DWORD)v12) >> 2;
    if ( v11 != nullptr )
      v11 = (_DWORD *)*v11;
    if ( LODWORD(v13) > (unsigned int)v11 )
      GHashSetBase<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor,GAllocatorLH<GFxTextFormatPtrWrapper<GFxTextFormat>,324>,GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor>>::setRawCapacity(
        this: p_m_minLightmapPageID,
        pheapAddr: p_m_minLightmapPageID,
        newHash: v13);
  }
  v14 = (unsigned int *)*p_m_minLightmapPageID;
  if ( *p_m_minLightmapPageID != nullptr )
    v15 = *v14;
  else
    v15 = 0;
  if ( v15 < *(_DWORD *)&v19->m_MappingWidth )
  {
    if ( v14 == nullptr || *v14 <= 0x64 )
      *(_DWORD *)&v19->m_MappingWidth = 100;
  }
  else if ( v14 != nullptr )
  {
    *(_DWORD *)&v19->m_MappingWidth = *v14 + 10;
  }
  else
  {
    *(_DWORD *)&v19->m_MappingWidth = 10;
  }
  if ( *p_m_minLightmapPageID != nullptr )
    return tfSize != *(_DWORD *)*p_m_minLightmapPageID;
  else
    return tfSize != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10141A60
// Name: public: bool GFxTextAllocator::FlushParagraphFormatCache(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextAllocator::FlushParagraphFormatCache(CMaterial *this, bool noAllocationsAllowed)
{
  ColorCorrectionLookup_t *p_m_maxLightmapPageID; // edi
  unsigned int *m_maxLightmapPageID; // ecx
  unsigned int v4; // eax
  unsigned int *p_m_Handle; // esi
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // ecx
  _DWORD *v10; // edx
  const CUtlMemory<ColorCorrectionLookup_t *,int> *m_Handle; // ecx
  ColorCorrectionLookup_t **m_pMemory; // eax
  const CUtlMemory<ColorCorrectionLookup_t *,int> *v13; // eax
  IShader **v14; // eax
  IShader *v15; // ecx
  unsigned int *v17; // [esp+4h] [ebp-10h] BYREF
  signed int v18; // [esp+8h] [ebp-Ch]
  CMaterial *v19; // [esp+Ch] [ebp-8h]
  unsigned int pfSize; // [esp+10h] [ebp-4h]

  p_m_maxLightmapPageID = (ColorCorrectionLookup_t *)&this->m_maxLightmapPageID;
  v19 = this;
  m_maxLightmapPageID = (unsigned int *)this->m_maxLightmapPageID;
  v4 = 0;
  if ( m_maxLightmapPageID != nullptr )
    pfSize = *m_maxLightmapPageID;
  else
    pfSize = 0;
  if ( m_maxLightmapPageID != nullptr )
  {
    v6 = m_maxLightmapPageID[1];
    v7 = m_maxLightmapPageID + 2;
    do
    {
      if ( *v7 != -2 )
        break;
      ++v4;
      v7 += 3;
    }
    while ( v4 <= v6 );
    p_m_Handle = &p_m_maxLightmapPageID->m_Handle;
  }
  else
  {
    p_m_Handle = nullptr;
  }
  v18 = v4;
  v17 = p_m_Handle;
  while ( p_m_Handle != nullptr && *p_m_Handle != 0 && (signed int)v4 <= *(_DWORD *)(*p_m_Handle + 4) )
  {
    if ( *(_DWORD *)(*(_DWORD *)(*p_m_Handle + 12 * v4 + 16) + 4) == 1 )
      GHashSetBase<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor,GAllocatorLH<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,324>,GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor>>::Iterator::Remove(this: &v17);
    p_m_Handle = v17;
    v8 = *v17;
    v9 = *(_DWORD *)(*v17 + 4);
    v4 = v18;
    if ( v18 <= (int)v9 )
    {
      v4 = v18 + 1;
      v18 = v4;
      if ( v4 <= v9 )
      {
        v10 = (_DWORD *)(v8 + 12 * v4 + 8);
        do
        {
          if ( *v10 != -2 )
            break;
          ++v4;
          v10 += 3;
          v18 = v4;
        }
        while ( v4 <= v9 );
      }
    }
  }
  if ( !noAllocationsAllowed )
  {
    m_Handle = (const CUtlMemory<ColorCorrectionLookup_t *,int> *)p_m_maxLightmapPageID->m_Handle;
    if ( p_m_maxLightmapPageID->m_Handle != 0 )
      m_pMemory = m_Handle->m_pMemory;
    else
      m_pMemory = nullptr;
    v13 = (const CUtlMemory<ColorCorrectionLookup_t *,int> *)((unsigned int)(5 * (_DWORD)m_pMemory) >> 2);
    if ( m_Handle != nullptr )
      m_Handle = (const CUtlMemory<ColorCorrectionLookup_t *,int> *)m_Handle->m_pMemory;
    if ( v13 > m_Handle )
      GHashSetBase<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor,GAllocatorLH<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,324>,GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor>>::setRawCapacity(
        this: p_m_maxLightmapPageID,
        pheapAddr: (color24 *)p_m_maxLightmapPageID,
        newHash: v13);
  }
  v14 = (IShader **)p_m_maxLightmapPageID->m_Handle;
  if ( p_m_maxLightmapPageID->m_Handle != 0 )
    v15 = *v14;
  else
    v15 = nullptr;
  if ( v15 < v19->m_pShader )
  {
    if ( v14 == nullptr || (unsigned int)*v14 <= 0x64 )
      v19->m_pShader = (IShader *)100;
  }
  else if ( v14 != nullptr )
  {
    v19->m_pShader = (IShader *)((char *)*v14 + 10);
  }
  else
  {
    v19->m_pShader = (IShader *)10;
  }
  if ( p_m_maxLightmapPageID->m_Handle != 0 )
    return pfSize != *(_DWORD *)p_m_maxLightmapPageID->m_Handle;
  else
    return pfSize != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10141B90
// Name: public: class GFxTextFormat __near * GFxTextAllocator::AllocateTextFormat(class GFxTextFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GFxTextAllocator::AllocateTextFormat(CMaterial *this, int srcfmt)
{
  IShaderDevice **v3; // eax
  IShaderDevice **v4; // ebx
  _DWORD *m_minLightmapPageID; // edi
  volatile int m_value; // ecx
  int (__thiscall *v8)(volatile int, int, const CMaterial **); // eax
  GStringDH *v9; // eax
  GStringDH *v10; // edi
  bool v11; // zf
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *pHeap; // ebx
  GArray<GWaitable::HandlerStruct,2,GArrayConstPolicy<0,16,1> > v13; // [esp-4h] [ebp-14h]
  const CMaterial *pfmt; // [esp+Ch] [ebp-4h] BYREF

  if ( (*(_WORD *)(srcfmt + 42) & 0x200) == 0 )
  {
    v13.Data.Data = (GWaitable::HandlerStruct *)&pfmt;
    pfmt = (const CMaterial *)srcfmt;
    v3 = (IShaderDevice **)GHashSetBase<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor,GAllocatorLH<GFxTextFormatPtrWrapper<GFxTextFormat>,324>,GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor>>::Get<GFxTextFormat const *>(
                             a1: &this->m_minLightmapPageID,
                             a2: v13);
    v4 = v3;
    if ( v3 != nullptr )
    {
      GRefCountImpl::AddRef(this: *v3);
      return (GStringDH *)*v4;
    }
    m_minLightmapPageID = (_DWORD *)this->m_minLightmapPageID;
    if ( m_minLightmapPageID != nullptr )
      m_minLightmapPageID = (_DWORD *)*m_minLightmapPageID;
    if ( (unsigned int)m_minLightmapPageID >= *(_DWORD *)&this->m_MappingWidth )
      GFxTextAllocator::FlushTextFormatCache(this, noAllocationsAllowed: false);
  }
  m_value = this->m_RefCount.m_value;
  v8 = *(int (__thiscall **)(volatile int, int, const CMaterial **))(*(_DWORD *)m_value + 40);
  pfmt = (const CMaterial *)324;
  v9 = (GStringDH *)v8(a1: m_value, a2: 44, a3: &pfmt);
  if ( v9 != nullptr )
    v10 = GFxTextFormat::GFxTextFormat(
            this: v9,
            result: (const CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)srcfmt,
            srcfmt_4: (CUtlBuffer *)this->m_RefCount.m_value);
  else
    v10 = nullptr;
  v11 = (*(_BYTE *)(&this->m_ShaderRenderState.m_pSnapshots + 1) & 1) == 0;
  pfmt = (const CMaterial *)v10;
  if ( !v11 && (v10[5].HeapTypeBits & 0x8000000) != 0 )
  {
    pHeap = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v10[3].pHeap;
    if ( pHeap != nullptr )
    {
      v11 = LODWORD(pHeap->m_pfnProxied)-- == 1;
      if ( v11 )
      {
        GFxFontHandle::~GFxFontHandle(this: pHeap);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pHeap);
      }
    }
    v10[3].pHeap = nullptr;
    HIWORD(v10[5].HeapTypeBits) &= ~0x800u;
  }
  if ( (*(_WORD *)(srcfmt + 42) & 0x200) == 0 )
  {
    v13.Data.Data = (GWaitable::HandlerStruct *)&pfmt;
    GHashSetBase<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor,GAllocatorLH<GFxTextFormatPtrWrapper<GFxTextFormat>,324>,GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor>>::Set<GFxTextFormat *>(
      a1: (void **)&this->m_minLightmapPageID,
      a2: &this->m_minLightmapPageID,
      a3: v13);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10141C90
// Name: public: class GFxTextParagraphFormat __near * GFxTextAllocator::AllocateParagraphFormat(class GFxTextParagraphFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxTextParagraphFormat *__userpurge GFxTextAllocator::AllocateParagraphFormat@<eax>(
        CMaterial *this@<ecx>,
        GRefCountNTSImpl *srcfmt,
        int pfmt,
        int a4,
        ImageFormat a5)
{
  CMaterial *v5; // esi
  bool v6; // zf
  ColorCorrectionLookup_t *p_m_maxLightmapPageID; // edi
  int v8; // esi
  int Index; // eax
  int v10; // eax
  IShader *m_Handle; // eax
  volatile int m_value; // ecx
  int (__thiscall *v14)(volatile int, int, int *); // edx
  GFxTextParagraphFormat *v15; // eax
  GFxTextParagraphFormat *v16; // esi
  int v17; // [esp+Ch] [ebp-14h] BYREF
  CMaterial *v18; // [esp+10h] [ebp-10h]
  GRefCountNTSImpl *v19; // [esp+14h] [ebp-Ch] BYREF
  int v20; // [esp+18h] [ebp-8h] BYREF

  v5 = this;
  v6 = this->m_maxLightmapPageID == 0;
  p_m_maxLightmapPageID = (ColorCorrectionLookup_t *)&this->m_maxLightmapPageID;
  v18 = this;
  v19 = srcfmt;
  if ( !v6 )
  {
    if ( srcfmt != nullptr )
      ++srcfmt->RefCount;
    v8 = *(_DWORD *)(p_m_maxLightmapPageID->m_Handle + 4)
       & GFxTextParagraphFormat::HashFunctor::operator()(a1: (int)srcfmt);
    if ( srcfmt != nullptr )
      GRefCountNTSImpl::Release(this: srcfmt);
    Index = GHashSetBase<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor,GAllocatorLH<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,324>,GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor>>::findIndexCore<GFxTextParagraphFormat const *>(
              this: (int *)p_m_maxLightmapPageID,
              a2: (int *)&v19,
              a3: v8);
    if ( Index >= 0 )
    {
      v10 = p_m_maxLightmapPageID->m_Handle + 12 * Index + 16;
      if ( v10 != 0 )
      {
        ++*(_DWORD *)(*(_DWORD *)v10 + 4);
        return *(GFxTextParagraphFormat **)v10;
      }
    }
    v5 = v18;
  }
  m_Handle = (IShader *)p_m_maxLightmapPageID->m_Handle;
  if ( p_m_maxLightmapPageID->m_Handle != 0 )
    m_Handle = (IShader *)m_Handle->__vftable;
  if ( m_Handle >= v5->m_pShader )
    GFxTextAllocator::FlushParagraphFormatCache(this: v5, noAllocationsAllowed: false);
  m_value = v5->m_RefCount.m_value;
  v14 = *(int (__thiscall **)(volatile int, int, int *))(*(_DWORD *)m_value + 40);
  v17 = 324;
  v15 = (GFxTextParagraphFormat *)v14(a1: m_value, a2: 24, a3: &v17);
  if ( v15 != nullptr )
    v16 = GFxTextParagraphFormat::GFxTextParagraphFormat(this: v15, a2: (const struct GFxTextParagraphFormat *)srcfmt);
  else
    v16 = nullptr;
  v20 = (int)v16;
  GHashSetBase<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor,GAllocatorLH<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,324>,GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor>>::Set<GFxTextParagraphFormat *>(
    this: p_m_maxLightmapPageID,
    pheapAddr: (color24 *)p_m_maxLightmapPageID,
    a3: (GRefCountNTSImpl **)&v20);
  return v16;
}
