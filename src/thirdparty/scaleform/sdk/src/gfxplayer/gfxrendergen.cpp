// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxrendergen.cpp
// Functions: 6
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxrendergen.h"

//------------------------------------------------------------------------------
// Address: 0x1015DE30
// Name: public: unsigned int GFxRenderGen::GetNumBytes(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GFxRenderGen::GetNumBytes(GFxRenderGen *this)
{
  int v2; // edi
  char *v3; // ebx
  char *v4; // ebx
  int v6; // [esp+Ch] [ebp-Ch]
  unsigned int NumBytes; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  v6 = 4 * (*((_DWORD *)this + 46) + 192 * *((_DWORD *)this + 45));
  v2 = 4
     * (*((_DWORD *)this + 179)
      + *((_DWORD *)this + 184)
      + *((_DWORD *)this + 188)
      + 192 * (*((_DWORD *)this + 178) + 4 * (*((_DWORD *)this + 183) + *((_DWORD *)this + 187))));
  NumBytes = GEdgeAA::GetNumBytes(this: (GFxRenderGen *)((char *)this + 776));
  v8 = *((_DWORD *)this + 231) * *(_DWORD *)(*((_DWORD *)this + 233) + 4);
  v3 = GTessellator::GetNumBytes(this: (UnDecorator *)((char *)this + 196));
  v4 = &v3[GCompoundShape::GetNumBytes(this: (GCompoundShape *)this + 20)];
  return &v4[GCompoundShape::GetNumBytes(this: (GCompoundShape *)this + 2) + v8 + NumBytes + v2 + v6];
}

//------------------------------------------------------------------------------
// Address: 0x1015DEE0
// Name: public: void GFxRenderGen::ClearAndRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxRenderGen::ClearAndRelease(GFxRenderGen *this)
{
  GCompoundShape::ClearAndRelease(this: (GCompoundShape *)this + 2);
  GCompoundShape::ClearAndRelease(this: (GCompoundShape *)this + 20);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 44);
  *((_BYTE *)this + 192) = 0;
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 177);
  *((_BYTE *)this + 724) = 0;
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 182);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 186);
  GEdgeAA::ClearAndRelease(this: (GFxRenderGen *)((char *)this + 776));
  GTessellator::ClearAndRelease(this: (GTessellator *)this + 49);
  GFxVertexArray::Resize(this: (GFxRenderGen *)((char *)this + 920), a2: 0);
  GFxVertexArray::Reserve(this: (GFxRenderGen *)((char *)this + 920), a2: 0, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1015DF70
// Name: public: GTessellator::~GTessellator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTessellator::~GTessellator(GTessellator *this)
{
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 109);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 105);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 101);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 97);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 93);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 89);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 85);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 81);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 77);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 74));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 71));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 65);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 62));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 51));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 47);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 44));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 41));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 38));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 35));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 31);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 28));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 24);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 20);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 16);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 12);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 9));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 6));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*(this + 3));
}

//------------------------------------------------------------------------------
// Address: 0x1015E100
// Name: public: GTessellator::GTessellator(void)
// Source: json
//------------------------------------------------------------------------------
GTessellator *__thiscall GTessellator::GTessellator(GTessellator *this)
{
  *this = nullptr;
  *(this + 1) = (GTessellator)16843009;
  *((_BYTE *)this + 8) = 0;
  *(this + 3) = nullptr;
  *(this + 4) = nullptr;
  *(this + 5) = nullptr;
  *(this + 6) = nullptr;
  *(this + 7) = nullptr;
  *(this + 8) = nullptr;
  *(this + 9) = nullptr;
  *(this + 10) = nullptr;
  *(this + 11) = nullptr;
  *(this + 12) = nullptr;
  *(this + 13) = nullptr;
  *(this + 14) = nullptr;
  *(this + 15) = nullptr;
  *(this + 16) = nullptr;
  *(this + 17) = nullptr;
  *(this + 18) = nullptr;
  *(this + 19) = nullptr;
  *(this + 20) = nullptr;
  *(this + 21) = nullptr;
  *(this + 22) = nullptr;
  *(this + 23) = nullptr;
  *(this + 24) = nullptr;
  *(this + 25) = nullptr;
  *(this + 26) = nullptr;
  *(this + 27) = nullptr;
  *(this + 28) = nullptr;
  *(this + 29) = nullptr;
  *(this + 30) = nullptr;
  *(this + 31) = nullptr;
  *(this + 32) = nullptr;
  *(this + 33) = nullptr;
  *(this + 34) = nullptr;
  *(this + 35) = nullptr;
  *(this + 36) = nullptr;
  *(this + 37) = nullptr;
  *(this + 38) = nullptr;
  *(this + 39) = nullptr;
  *(this + 40) = nullptr;
  *(this + 41) = nullptr;
  *(this + 42) = nullptr;
  *(this + 43) = nullptr;
  *(this + 44) = nullptr;
  *(this + 45) = nullptr;
  *(this + 46) = nullptr;
  *(this + 47) = nullptr;
  *(this + 48) = nullptr;
  *(this + 49) = nullptr;
  *(this + 50) = nullptr;
  *(this + 51) = nullptr;
  *(this + 52) = nullptr;
  *(this + 53) = nullptr;
  *((float *)this + 56) = 1.0e30;
  *((float *)this + 57) = 1.0e30;
  *(this + 54) = (GTessellator)0x3FFFFFFF;
  *(this + 55) = nullptr;
  *((float *)this + 58) = -1.0e30;
  *((float *)this + 59) = -1.0e30;
  *((float *)this + 60) = 0.0;
  *((float *)this + 61) = 0.0;
  *(this + 62) = nullptr;
  *(this + 63) = nullptr;
  *(this + 64) = nullptr;
  *(this + 65) = nullptr;
  *(this + 66) = nullptr;
  *(this + 67) = nullptr;
  *(this + 68) = nullptr;
  *(this + 71) = nullptr;
  *(this + 72) = nullptr;
  *(this + 73) = nullptr;
  *(this + 74) = nullptr;
  *(this + 75) = nullptr;
  *(this + 76) = nullptr;
  *(this + 77) = nullptr;
  *(this + 78) = nullptr;
  *(this + 79) = nullptr;
  *(this + 80) = nullptr;
  *(this + 81) = nullptr;
  *(this + 82) = nullptr;
  *(this + 83) = nullptr;
  *(this + 84) = nullptr;
  *(this + 85) = nullptr;
  *(this + 86) = nullptr;
  *(this + 87) = nullptr;
  *(this + 88) = nullptr;
  *(this + 89) = nullptr;
  *(this + 90) = nullptr;
  *(this + 91) = nullptr;
  *(this + 92) = nullptr;
  *(this + 93) = nullptr;
  *(this + 94) = nullptr;
  *(this + 95) = nullptr;
  *(this + 96) = nullptr;
  *(this + 97) = nullptr;
  *(this + 98) = nullptr;
  *(this + 99) = nullptr;
  *(this + 100) = nullptr;
  *(this + 101) = nullptr;
  *(this + 102) = nullptr;
  *(this + 103) = nullptr;
  *(this + 104) = nullptr;
  *(this + 105) = nullptr;
  *(this + 106) = nullptr;
  *(this + 107) = nullptr;
  *(this + 108) = nullptr;
  *(this + 109) = nullptr;
  *(this + 110) = nullptr;
  *(this + 111) = nullptr;
  *(this + 112) = nullptr;
  *(this + 113) = nullptr;
  *(this + 114) = nullptr;
  *(this + 115) = nullptr;
  *(this + 116) = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015E370
// Name: public: GFxRenderGen::GFxRenderGen(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GFxRenderGen *__thiscall GFxRenderGen::GFxRenderGen(GFxRenderGen *this, struct GMemoryHeap *a2)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxRenderGen::`vftable';
  *((float *)this + 2) = 1.0;
  *((float *)this + 3) = 0.0625;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((float *)this + 15) = 1.0;
  *((float *)this + 16) = 1.0;
  *((_DWORD *)this + 13) = 0x7FFFFFFF;
  *((_DWORD *)this + 12) = 0;
  *((float *)this + 17) = 0.0;
  *((_BYTE *)this + 76) = 0;
  *((float *)this + 18) = 0.0;
  *((_DWORD *)this + 14) = -2147483647;
  *((float *)this + 20) = 1.0;
  *((float *)this + 21) = 0.0625;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((float *)this + 33) = 1.0;
  *((float *)this + 34) = 1.0;
  *((_DWORD *)this + 31) = 0x7FFFFFFF;
  *((_DWORD *)this + 30) = 0;
  *((float *)this + 35) = 0.0;
  *((_DWORD *)this + 32) = -2147483647;
  *((float *)this + 36) = 0.0;
  *((_BYTE *)this + 148) = 0;
  *((_DWORD *)this + 40) = 3;
  *((float *)this + 38) = 1.0;
  *((_DWORD *)this + 41) = 2;
  *((float *)this + 39) = 1.0;
  *((_DWORD *)this + 42) = 2;
  *((float *)this + 43) = 4.0;
  *((_DWORD *)this + 44) = 0;
  *((_DWORD *)this + 45) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_BYTE *)this + 192) = 0;
  GTessellator::GTessellator(this: (GTessellator *)this + 49);
  *((float *)this + 169) = 4.0;
  *((_DWORD *)this + 166) = 3;
  *((_DWORD *)this + 167) = 2;
  *((float *)this + 172) = 0.0;
  *((_DWORD *)this + 168) = 2;
  *((float *)this + 173) = 0.0;
  *((_DWORD *)this + 170) = 0;
  *((_DWORD *)this + 171) = 0;
  *((float *)this + 174) = 0.5;
  *((float *)this + 175) = 0.5;
  *((float *)this + 176) = 1.0;
  *((_DWORD *)this + 177) = 0;
  *((_DWORD *)this + 178) = 0;
  *((_DWORD *)this + 179) = 0;
  *((_DWORD *)this + 180) = 0;
  *((_BYTE *)this + 724) = 0;
  *((_DWORD *)this + 182) = 0;
  *((_DWORD *)this + 183) = 0;
  *((_DWORD *)this + 184) = 0;
  *((_DWORD *)this + 185) = 0;
  *((_DWORD *)this + 186) = 0;
  *((_DWORD *)this + 187) = 0;
  *((_DWORD *)this + 188) = 0;
  *((_DWORD *)this + 189) = 0;
  GFxEdgeAAGenerator::GFxEdgeAAGenerator(this: (GFxRenderGen *)((char *)this + 776));
  GFxVertexArray::GFxVertexArray(this: (GFxRenderGen *)((char *)this + 920), a2, a3: Vertex_None, a4: 0);
  *((_DWORD *)this + 235) = 0;
  *((_DWORD *)this + 236) = 0x40000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015E560
// Name: public: virtual GFxRenderGen::~GFxRenderGen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxRenderGen::~GFxRenderGen(GFxRenderGen *this)
{
  GFxVertexArray::~GFxVertexArray(this: (GFxRenderGen *)((char *)this + 920));
  GFxEdgeAAGenerator::~GFxEdgeAAGenerator(this: (GFxRenderGen *)((char *)this + 776));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 186);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 182);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 177);
  GTessellator::~GTessellator(this: (GTessellator *)this + 49);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 44);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 26);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 22);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 8);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 4);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}
