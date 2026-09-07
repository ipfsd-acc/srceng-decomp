// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxcharacterdef.cpp
// Functions: 2
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxcharacterdef.h"

//------------------------------------------------------------------------------
// Address: 0x1013AEA0
// Name: public: void GFxTimelineDef::Frame::DestroyTags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTimelineDef::Frame::DestroyTags(GFxTimelineDef::Frame *this)
{
  unsigned int v2; // edi

  v2 = 0;
  if ( *((_DWORD *)this + 1) != 0 )
  {
    do
    {
      (***(void (__thiscall ****)(_DWORD, _DWORD))(*(_DWORD *)this + 4 * v2))(
        a1: *(_DWORD *)(*(_DWORD *)this + 4 * v2),
        a2: 0);
      ++v2;
    }
    while ( v2 < *((_DWORD *)this + 1) );
    *(_DWORD *)this = 0;
    *((_DWORD *)this + 1) = 0;
  }
  else
  {
    *(_DWORD *)this = 0;
    *((_DWORD *)this + 1) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013AEE0
// Name: public: virtual class GFxCharacter __near * GFxCharacterDef::CreateCharacterInstance(class GFxASCharacter __near *,class GFxResourceId,class GFxMovieDefImpl __near *)
// Source: json
//------------------------------------------------------------------------------
CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *__thiscall GFxCharacterDef::CreateCharacterInstance(
        CMatRenderContextBase *this,
        __int64 pparent,
        struct GFxMovieDefImpl *pparent_8)
{
  CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *v4; // eax
  __int128 v6; // [esp-8h] [ebp-14h]
  int v7; // [esp+8h] [ebp-4h] BYREF
  void *const *savedregs; // [esp+Ch] [ebp+0h]

  v7 = 322;
  v4 = (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: pparent, a3: 124, a4: &v7);
  if ( v4 == nullptr )
    return nullptr;
  *(_QWORD *)&v6 = pparent;
  return GFxGenericCharacter::GFxGenericCharacter(
           this: v4,
           pdef: this,
           pparent: v6,
           id: (IMaterial *const *)v7,
           a5: savedregs);
}
