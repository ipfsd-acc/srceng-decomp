// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxstring.cpp
// Functions: 4
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxstring.h"

//------------------------------------------------------------------------------
// Address: 0x100E3D40
// Name: public: GFxWStringBuffer::~GFxWStringBuffer(void)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *__thiscall GFxWStringBuffer::~GFxWStringBuffer(
        CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *result; // eax

  result = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable;
  if ( this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable != (CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable
    && result != nullptr )
  {
    return (CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)((void *(__thiscall *)(GMemoryHeap *, CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: result);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E3D60
// Name: public: bool GFxWStringBuffer::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxWStringBuffer::Resize(GFxWStringBuffer *this, unsigned int a2)
{
  unsigned int v2; // ebx
  unsigned __int8 *v4; // edi

  v2 = a2;
  if ( a2 <= this->Length || a2 < this->Reserved.Size )
  {
    if ( this->pText != nullptr )
      this->pText[a2] = 0;
    this->Length = v2;
    return 1;
  }
  else
  {
    a2 = 2;
    v4 = (unsigned __int8 *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2 * v2 + 2, a3: &a2);
    if ( v4 != nullptr )
    {
      if ( this->pText != nullptr )
        memcpy(dst: v4, src: (unsigned __int8 *)this->pText, count: 2 * this->Length + 2);
      *(_WORD *)&v4[2 * v2] = 0;
      if ( this->pText != this->Reserved.pBuffer && this->pText != nullptr )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->pText);
      this->pText = (wchar_t *)v4;
      this->Length = v2;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3E00
// Name: public: void GFxWStringBuffer::SetString(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxWStringBuffer::SetString(GFxWStringBuffer *this, wchar_t *pwch, unsigned int a3)
{
  unsigned int v3; // esi

  v3 = a3;
  if ( a3 == -1 )
    v3 = G_wcslen(pwch);
  if ( GFxWStringBuffer::Resize(this, a2: v3) != 0 && v3 != 0 )
    memcpy(dst: (unsigned __int8 *)this->pText, src: (unsigned __int8 *)pwch, count: 2 * v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100E3E50
// Name: public: void GFxWStringBuffer::StripTrailingNewLines(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GFxWStringBuffer::StripTrailingNewLines(
        CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  char *result; // eax
  int i; // esi
  int v3; // edx

  result = (char *)this->m_nUserID;
  if ( (int)result > 0
    && *((_WORD *)this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable
       + (_DWORD)result
       - 1) == 0 )
  {
    --result;
  }
  for ( i = (int)(result - 1); i >= 0; *(_WORD *)result = 0 )
  {
    v3 = *((unsigned __int16 *)&this->AddRef + i);
    result = (char *)this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable
           + 2 * i;
    if ( v3 != 10 && v3 != 13 )
      break;
    --this->m_nUserID;
    --i;
  }
  return result;
}
