// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/amp/gfxampviewstats.cpp
// Functions: 30
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\amp\gfxampviewstats.h"

//------------------------------------------------------------------------------
// Address: 0x1008BD40
// Name: public: void GFxAmpViewStats::ReleaseBufferInstructionTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::ReleaseBufferInstructionTimes(GImageInfo *this)
{
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1008BD50
// Name: public: class GString const __near & GFxAmpViewStats::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::GetName(GImageInfo *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1008BD60
// Name: public: unsigned long GFxAmpViewStats::GetViewHandle(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxAmpViewStats::GetViewHandle(GFxAmpViewStats *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // esi

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 40));
  v3 = *((_DWORD *)this + 16);
  LeaveCriticalSection(lpCriticalSection: v2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008BD80
// Name: public: void GFxAmpViewStats::SetMovieDef(class GFxMovieDef __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::SetMovieDef(GImageInfo *this, unsigned int movieDef)
{
  _RTL_CRITICAL_SECTION *v3; // ebx

  v3 = (_RTL_CRITICAL_SECTION *)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  if ( movieDef != 0 )
  {
    *((_DWORD *)this + 19) = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)movieDef + 16))(a1: movieDef);
    *((float *)this + 20) = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)movieDef + 24))(a1: movieDef);
    *((float *)this + 21) = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)movieDef + 28))(a1: movieDef);
    *((float *)this + 22) = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)movieDef + 36))(a1: movieDef);
    *((_DWORD *)this + 23) = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)movieDef + 32))(a1: movieDef);
  }
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1008BDF0
// Name: public: unsigned long GFxAmpViewStats::GetVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxAmpViewStats::GetVersion(GFxAmpViewStats *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // esi

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 40));
  v3 = *((_DWORD *)this + 19);
  LeaveCriticalSection(lpCriticalSection: v2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008BE10
// Name: public: float GFxAmpViewStats::GetWidth(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxAmpViewStats::GetWidth(int this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  float v4; // [esp+8h] [ebp-4h]

  v2 = (_RTL_CRITICAL_SECTION *)(this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 40));
  v4 = *(float *)(this + 80);
  LeaveCriticalSection(lpCriticalSection: v2);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1008BE40
// Name: public: float GFxAmpViewStats::GetHeight(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxAmpViewStats::GetHeight(int this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  float v4; // [esp+8h] [ebp-4h]

  v2 = (_RTL_CRITICAL_SECTION *)(this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 40));
  v4 = *(float *)(this + 84);
  LeaveCriticalSection(lpCriticalSection: v2);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1008BE70
// Name: public: float GFxAmpViewStats::GetFrameRate(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxAmpViewStats::GetFrameRate(int this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  float v4; // [esp+8h] [ebp-4h]

  v2 = (_RTL_CRITICAL_SECTION *)(this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 40));
  v4 = *(float *)(this + 88);
  LeaveCriticalSection(lpCriticalSection: v2);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1008BEA0
// Name: public: unsigned long GFxAmpViewStats::GetFrameCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxAmpViewStats::GetFrameCount(GFxAmpViewStats *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // esi

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 40));
  v3 = *((_DWORD *)this + 23);
  LeaveCriticalSection(lpCriticalSection: v2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008BEC0
// Name: public: unsigned long GFxAmpViewStats::GetCurrentFrame(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxAmpViewStats::GetCurrentFrame(GFxAmpViewStats *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // esi

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 40));
  v3 = *((_DWORD *)this + 18);
  LeaveCriticalSection(lpCriticalSection: v2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008BEE0
// Name: public: void GFxAmpViewStats::SetCurrentFrame(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::SetCurrentFrame(GImageInfo *this, unsigned int frame)
{
  _RTL_CRITICAL_SECTION *v3; // edi

  v3 = (_RTL_CRITICAL_SECTION *)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  *((_DWORD *)this + 18) = frame;
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1008BF10
// Name: public: unsigned __int64 GFxAmpViewStats::GetInstructionTime(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxAmpViewStats::GetInstructionTime(GImageInfo *this, unsigned int samplePeriod)
{
  int v2; // edi
  int v4; // eax
  int v5; // edi
  int result; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // edx
  unsigned int v12; // eax
  int v13; // [esp+0h] [ebp-Ch]

  v2 = 0;
  if ( samplePeriod != 0 )
  {
    if ( *((_QWORD *)this + 18) != 0 )
    {
      GTimer::GetRawTicks(li: this);
      v2 = (v8 - *((_DWORD *)this + 36)) * samplePeriod;
    }
    v9 = *((_DWORD *)this + 34);
    if ( v9 != 0 )
    {
      *((_DWORD *)this + 34) = v9 - 1;
      *((_DWORD *)this + 36) = 0;
      *((_DWORD *)this + 37) = 0;
    }
    else
    {
      GTimer::GetRawTicks(li: nullptr);
      *((_DWORD *)this + 36) = v10;
      *((_DWORD *)this + 37) = v11;
      LOBYTE(v12) = GFxRandom::Generator::NextRandom(
                      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)((char *)this + 96),
                      a2: v13);
      *((_DWORD *)this + 34) = 2 * samplePeriod * (unsigned __int64)v12 / 0xFFFFFFFF;
    }
    return v2;
  }
  else
  {
    GTimer::GetRawTicks(li: this);
    v5 = v4;
    result = v4 - *((_DWORD *)this + 36);
    *((_DWORD *)this + 36) = v5;
    *((_DWORD *)this + 37) = v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008BFF0
// Name: public: void GFxAmpViewStats::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpViewStats::SetName(GFxAmpViewStats *this@<ecx>, int a2@<ebx>, GString a3)
{
  GString *v3; // edi
  unsigned int Length; // eax
  int v5; // esi
  char v6; // dl
  struct GString v7; // eax
  void *v8; // esi

  v3 = (GString *)((char *)this + 68);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 68),
    a2: (unsigned __int8 *)a3.pData);
  Length = GString::GetLength(this: v3);
  v5 = 0;
  if ( Length != 0 )
  {
    while ( 1 )
    {
      v6 = *(_BYTE *)((v3->HeapTypeBits & 0xFFFFFFFC) + Length - v5 + 7);
      if ( v6 == 47 || v6 == 92 )
        break;
      if ( ++v5 >= Length )
        return;
    }
    v7.pData = GString::Substring(this: v3, a2: &a3, a3: Length - v5, a4: Length).pData;
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v3,
      src: v7.pData,
      a3: a2);
    v8 = (void *)(a3.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a3.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C520
// Name: public: void GFxAmpViewStats::ClearAmpInstructionStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::ClearAmpInstructionStats(GImageInfo *this)
{
  _RTL_CRITICAL_SECTION *v2; // ebx
  unsigned int TargetHeight; // ecx
  unsigned int v4; // eax
  unsigned int v5; // edx
  _DWORD *v6; // ecx
  unsigned int v7; // edi
  signed int v8; // esi
  int v9; // eax
  int v10; // eax
  unsigned int v11; // eax
  _DWORD *v12; // ecx

  v2 = (_RTL_CRITICAL_SECTION *)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  TargetHeight = this->TargetHeight;
  if ( TargetHeight != 0 )
  {
    v5 = *(_DWORD *)(TargetHeight + 4);
    v4 = 0;
    v6 = (_DWORD *)(TargetHeight + 8);
    do
    {
      if ( *v6 != -2 )
        break;
      ++v4;
      v6 += 6;
    }
    while ( v4 <= v5 );
    TargetHeight = (unsigned int)&this->TargetHeight;
  }
  else
  {
    v4 = 0;
  }
  v7 = TargetHeight;
  v8 = v4;
  while ( v7 != 0 )
  {
    v9 = *(_DWORD *)v7;
    if ( *(_DWORD *)v7 == 0 || v8 > *(_DWORD *)(v9 + 4) )
      break;
    v10 = *(_DWORD *)(v9 + 8 * (3 * v8 + 3));
    memset(dst: *(unsigned __int8 **)(v10 + 8), value: 0, count: 8 * *(_DWORD *)(v10 + 12));
    v11 = *(_DWORD *)(*(_DWORD *)v7 + 4);
    if ( v8 <= (int)v11 && ++v8 <= v11 )
    {
      v12 = (_DWORD *)(*(_DWORD *)v7 + 24 * v8 + 8);
      do
      {
        if ( *v12 != -2 )
          break;
        ++v8;
        v12 += 6;
      }
      while ( v8 <= v11 );
    }
  }
  LeaveCriticalSection(lpCriticalSection: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1008C5C0
// Name: public: void GFxAmpViewStats::ClearAmpFunctionStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::ClearAmpFunctionStats(GImageInfo *this)
{
  GTexture::ChangeHandler_vtbl *v2; // ecx
  GTexture::ChangeHandler *v3; // ecx
  unsigned int v4; // eax
  void (__thiscall *OnChange)(GTexture::ChangeHandler *, GRenderer *, GTexture::ChangeHandler::EventType); // edx
  bool (__thiscall **p_Recreate)(GTexture::ChangeHandler *, GRenderer *); // ecx
  GTexture::ChangeHandler *v7; // esi
  GTexture::ChangeHandler_vtbl *v8; // ecx
  bool (__thiscall **v9)(GTexture::ChangeHandler *, GRenderer *); // ecx
  void (__thiscall *v10)(GTexture::ChangeHandler *, GRenderer *, GTexture::ChangeHandler::EventType); // ecx
  bool (__thiscall **v11)(GTexture::ChangeHandler *, GRenderer *); // edx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  v2 = this->GImageInfoBaseImpl::GImageInfoBase::GTexture::ChangeHandler::__vftable;
  if ( v2 != nullptr )
  {
    OnChange = v2->OnChange;
    v4 = 0;
    p_Recreate = &v2->Recreate;
    do
    {
      if ( *p_Recreate != (bool (__thiscall *)(GTexture::ChangeHandler *, GRenderer *))-2 )
        break;
      ++v4;
      p_Recreate += 10;
    }
    while ( v4 <= (unsigned int)OnChange );
    v3 = &this->GTexture::ChangeHandler;
  }
  else
  {
    v3 = nullptr;
    v4 = 0;
  }
  v7 = v3;
  while ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    if ( v7->__vftable == nullptr || (signed int)v4 > (int)v8->OnChange )
      break;
    v9 = &v8[2].Recreate + 10 * v4;
    *v9 = nullptr;
    v9[2] = nullptr;
    v9[3] = nullptr;
    v10 = v7->OnChange;
    if ( (int)v4 <= (int)v10 && ++v4 <= (unsigned int)v10 )
    {
      v11 = &v7->Recreate + 10 * v4;
      do
      {
        if ( *v11 != (bool (__thiscall *)(GTexture::ChangeHandler *, GRenderer *))-2 )
          break;
        ++v4;
        v11 += 10;
      }
      while ( v4 <= (unsigned int)v10 );
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1008C660
// Name: public: void GFxAmpViewStats::ClearAmpSourceLineStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::ClearAmpSourceLineStats(GImageInfo *this)
{
  bool *p_ReleaseImage; // ecx
  unsigned int v3; // eax
  unsigned int v4; // edx
  _DWORD *v5; // ecx
  bool *v6; // esi
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // ecx
  _DWORD *v10; // edx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+8h] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  p_ReleaseImage = *(bool **)&this->ReleaseImage;
  if ( p_ReleaseImage != nullptr )
  {
    v4 = *((_DWORD *)p_ReleaseImage + 1);
    v3 = 0;
    v5 = p_ReleaseImage + 8;
    do
    {
      if ( *v5 != -2 )
        break;
      ++v3;
      v5 += 8;
    }
    while ( v3 <= v4 );
    p_ReleaseImage = &this->ReleaseImage;
  }
  else
  {
    v3 = 0;
  }
  v6 = p_ReleaseImage;
  while ( v6 != nullptr )
  {
    v7 = *(_DWORD *)v6;
    if ( *(_DWORD *)v6 == 0 || (signed int)v3 > *(_DWORD *)(v7 + 4) )
      break;
    v8 = 32 * (v3 + 1);
    *(_DWORD *)(v8 + v7) = 0;
    *(_DWORD *)(v8 + v7 + 4) = 0;
    v9 = *(_DWORD *)(*(_DWORD *)v6 + 4);
    if ( (int)v3 <= (int)v9 && ++v3 <= v9 )
    {
      v10 = (_DWORD *)(32 * v3 + *(_DWORD *)v6 + 8);
      do
      {
        if ( *v10 != -2 )
          break;
        ++v3;
        v10 += 8;
      }
      while ( v3 <= v9 );
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1008C700
// Name: public: void GFxAmpViewStats::CollectTimingStats(class GFxAmpProfileFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::CollectTimingStats(GFxAmpViewStats *this, struct GFxAmpProfileFrame *a2)
{
  int v3; // eax
  _DWORD *v4; // edx
  unsigned int v5; // edi
  unsigned int v6; // ecx
  _DWORD *v7; // eax
  int v8; // esi
  void *v9; // ecx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  unsigned int v12; // eax
  _DWORD *v13; // ecx
  _DWORD *v14; // [esp+Ch] [ebp-18h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+14h] [ebp-10h]
  void *v16; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 40));
  v3 = *((_DWORD *)this + 2);
  v4 = (_DWORD *)((char *)this + 8);
  if ( v3 != 0 )
  {
    v6 = *(_DWORD *)(v3 + 4);
    v5 = 0;
    v7 = (_DWORD *)(v3 + 8);
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 10;
    }
    while ( v5 <= v6 );
  }
  else
  {
    v4 = nullptr;
    v5 = 0;
  }
  v14 = v4;
  while ( v4 != nullptr )
  {
    v8 = *v4;
    if ( *v4 == 0 || (signed int)v5 > *(_DWORD *)(v8 + 4) )
      break;
    v9 = *(void **)(v8 + 40 * v5 + 24);
    v16 = v9;
    v17 = *(_DWORD *)(v8 + 40 * v5 + 28);
    GTimer::GetRawFrequency(freq: v9);
    v11 = 1000000LL * *(_QWORD *)(v8 + 40 * v5 + 40) / v10;
    if ( v17 == 1 )
    {
      switch ( (unsigned int)v16 )
      {
        case 0u:
          a2->DisplayTime += v11;
          break;
        case 9u:
          a2->AdvanceTime += v11;
          break;
        case 0xAu:
          a2->ActionTime += v11;
          break;
        case 0xBu:
          a2->InputTime += v11;
          break;
        case 0xDu:
          a2->MouseTime += v11;
          break;
        case 0xFu:
          a2->TimelineTime += v11;
          break;
        case 0x10u:
          a2->TesselationTime += v11;
          break;
        case 0x11u:
        case 0x12u:
        case 0x13u:
        case 0x14u:
          a2->InvokeTime += v11;
          break;
        case 0x15u:
        case 0x16u:
        case 0x17u:
          a2->SetVariableTime += v11;
          break;
        case 0x18u:
        case 0x19u:
        case 0x1Au:
          a2->GetVariableTime += v11;
          break;
        case 0x1Fu:
          a2->GradientGenTime += v11;
          break;
        case 0x23u:
          a2->UserTime += v11;
          break;
        default:
          break;
      }
    }
    v4 = v14;
    v12 = *(_DWORD *)(*v14 + 4);
    if ( (int)v5 <= (int)v12 && ++v5 <= v12 )
    {
      v13 = (_DWORD *)(*v14 + 40 * v5 + 8);
      do
      {
        if ( *v13 != -2 )
          break;
        ++v5;
        v13 += 10;
      }
      while ( v5 <= v12 );
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1008C9C0
// Name: public: void GFxAmpViewStats::GetStats(class GStatBag __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpViewStats::GetStats(GImageInfo *this@<ecx>, unsigned __int16 a2@<si>, int bag, bool reset)
{
  CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v4; // edi
  CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v5; // eax
  struct GFxAmpProfileFrame *v6; // eax
  struct GFxAmpProfileFrame *v7; // esi
  unsigned __int16 v8; // [esp+0h] [ebp-14h]
  bool v9; // [esp+4h] [ebp-10h]
  unsigned int AdvanceTime; // [esp+8h] [ebp-Ch] BYREF
  int v11; // [esp+Ch] [ebp-8h]
  GImageInfo *v12; // [esp+10h] [ebp-4h]

  v4 = (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)bag;
  v12 = this;
  if ( bag != 0 )
  {
    bag = 2;
    v5 = (CUtlRBTree<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 208, a4: &bag);
    if ( v5 != nullptr )
    {
      GFxAmpProfileFrame::GFxAmpProfileFrame(this: v5, a2, a3: v8, a4: v9);
      v7 = v6;
    }
    else
    {
      v7 = nullptr;
    }
    GFxAmpViewStats::CollectTimingStats(this: (GFxAmpViewStats *)v12, a2: v7);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->AdvanceTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x148,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->TimelineTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x14A,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->ActionTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x149,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->InputTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x14B,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->MouseTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x14C,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->GetVariableTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x14E,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->SetVariableTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x14F,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->InvokeTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x150,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->DisplayTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x151,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->TesselationTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x152,
      a3: (int)&AdvanceTime);
    AdvanceTime = 0;
    v11 = 0;
    AdvanceTime = v7->GradientGenTime;
    v11 = 0;
    GStatBag::Add(
      this: v4,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x153,
      a3: (int)&AdvanceTime);
    GRefCountImpl::Release(this: (IShaderAPI *)v7);
    this = v12;
  }
  if ( reset )
    GFxAmpViewStats::ClearAmpFunctionStats(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008D020
// Name: public: void GFxAmpViewStats::PushCallstack(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::PushCallstack(GFxAmpViewStats *this, unsigned int swdHandle, unsigned int swfOffset)
{
  char *v4; // edi
  unsigned int v5; // esi
  char *v6; // ecx
  char *v7; // esi
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+14h] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 40));
  if ( swdHandle == 1 && swfOffset - 36 <= 0x1B && *((_DWORD *)this + 5) == 0 )
    GFxAmpViewStats::PushCallstack(this, swdHandle: 1u, a3: 0x23u);
  v4 = (char *)this + 16;
  v5 = *((_DWORD *)v4 + 1) + 1;
  if ( v5 >= *((_DWORD *)v4 + 1) )
  {
    if ( v5 >= *((_DWORD *)v4 + 2) )
      GArrayDataBase<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        this: (void **)v4,
        pheapAddr: v4,
        newCapacity: v5 + (v5 >> 2));
  }
  else if ( v5 < *((_DWORD *)v4 + 2) >> 1 )
  {
    GArrayDataBase<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayConstPolicy<0,4,1>>::Reserve(
      this: (void **)v4,
      pheapAddr: v4,
      newCapacity: *((_DWORD *)v4 + 1) + 1);
  }
  v6 = *(char **)v4;
  *((_DWORD *)v4 + 1) = v5;
  v7 = &v6[8 * v5 - 8];
  if ( v7 != nullptr )
    *(_QWORD *)v7 = swfOffset + __PAIR64__(swdHandle, 0);
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1008D100
// Name: public: void GFxAmpViewStats::CollectMarkers(struct GFxMovieStats __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpViewStats::CollectMarkers(
        GImageInfo *this@<ecx>,
        GImage *movieProfile,
        unsigned int locker,
        unsigned int it)
{
  int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // ecx
  _DWORD *v8; // eax
  char *v9; // eax
  char *v10; // esi
  char *v11; // ebx
  _DWORD *v12; // esi
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  int v15; // [esp+0h] [ebp-1Ch]
  char *v16; // [esp+Ch] [ebp-10h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h] BYREF

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  v5 = *((_DWORD *)this + 38);
  v6 = 0;
  if ( v5 != 0 )
  {
    v7 = *(_DWORD *)(v5 + 4);
    v8 = (_DWORD *)(v5 + 8);
    do
    {
      if ( *v8 != -2 )
        break;
      ++v6;
      v8 += 4;
    }
    while ( v6 <= v7 );
    v16 = (char *)this + 152;
  }
  else
  {
    v16 = nullptr;
  }
  while ( v16 != nullptr && *(_DWORD *)v16 != 0 && (signed int)v6 <= *(_DWORD *)(*(_DWORD *)v16 + 4) )
  {
    v18 = 2;
    v9 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: movieProfile, a3: 16, a4: &v18);
    v10 = v9;
    if ( v9 != nullptr )
    {
      *(_DWORD *)v9 = &GRefCountImplCore::`vftable';
      *((_DWORD *)v9 + 1) = 1;
      *(_DWORD *)v9 = &GFxAmpFunctionDesc::`vftable';
      GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v9 + 8));
      v11 = v10;
    }
    else
    {
      v11 = nullptr;
    }
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v11 + 8),
      src: (_DWORD *)(*(_DWORD *)v16 + 16 * v6 + 16),
      a3: v15);
    *((_DWORD *)v11 + 3) = *(_DWORD *)(*(_DWORD *)v16 + 16 * v6 + 20);
    GArrayDataBase<GPtr<GFxMovieStats::MarkerInfo>,GAllocatorLH<GPtr<GFxMovieStats::MarkerInfo>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (GRenderer::CachedData *)&movieProfile->ColorMap.Data.Policy,
      result: (const CSchemaClassBinding<CResourceEnumIntrospection> *)&movieProfile->ColorMap.Data.Policy,
      newSize: (unsigned int)&movieProfile[1].dtr_GRefCountImplCore + 1);
    v12 = (_DWORD *)(movieProfile->ColorMap.Data.Policy.Capacity + 4 * (int)movieProfile[1].__vftable - 4);
    if ( movieProfile->ColorMap.Data.Policy.Capacity + 4 * (int)movieProfile[1].__vftable != 4 )
    {
      GRefCountImpl::AddRef(this: (IShaderDevice *)v11);
      *v12 = v11;
    }
    GRefCountImpl::Release(this: (IShaderAPI *)v11);
    v13 = *(_DWORD *)(*(_DWORD *)v16 + 4);
    if ( (int)v6 <= (int)v13 && ++v6 <= v13 )
    {
      v14 = (_DWORD *)(*(_DWORD *)v16 + 16 * v6 + 8);
      do
      {
        if ( *v14 != -2 )
          break;
        ++v6;
        v14 += 4;
      }
      while ( v6 <= v13 );
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1008D680
// Name: public: void GFxAmpViewStats::CollectAmpInstructionStats(struct GFxMovieStats __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpViewStats::CollectAmpInstructionStats(
        GImageInfo *this@<ecx>,
        GImage *movieProfile,
        unsigned int locker,
        unsigned int it)
{
  unsigned int TargetHeight; // ecx
  unsigned int v6; // eax
  unsigned int v7; // edx
  _DWORD *v8; // ecx
  _DWORD *v9; // esi
  int v10; // ebx
  int v11; // edi
  int v12; // ecx
  int v13; // edx
  _QWORD *v14; // ecx
  IShaderDevice *v15; // esi
  IShaderDevice *v16; // eax
  __int64 v17; // rax
  unsigned int v18; // eax
  ButtonCode_t v19; // esi
  int v20; // eax
  unsigned int v21; // ecx
  char *v22; // esi
  _QWORD *v23; // edi
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // rax
  GImageBase::ImageFormat Format; // edi
  unsigned int v27; // ebx
  unsigned int v28; // eax
  GRenderer::CachedData *v29; // edi
  unsigned int v30; // ebx
  unsigned int v31; // eax
  IShaderAPI **v32; // esi
  GRenderer *pRenderer; // edx
  IShaderDevice *v34; // esi
  IShaderDevice **v35; // ebx
  unsigned int v36; // ecx
  _DWORD *v37; // edx
  _DWORD *v38; // [esp+Ch] [ebp-28h]
  int v39; // [esp+10h] [ebp-24h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+14h] [ebp-20h]
  int v41; // [esp+18h] [ebp-1Ch]
  int v42; // [esp+1Ch] [ebp-18h]
  int v43; // [esp+24h] [ebp-10h] BYREF
  unsigned int i; // [esp+28h] [ebp-Ch]
  IShaderDevice *v45; // [esp+2Ch] [ebp-8h]
  unsigned int nonZeroTimes; // [esp+30h] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  TargetHeight = this->TargetHeight;
  if ( TargetHeight != 0 )
  {
    v7 = *(_DWORD *)(TargetHeight + 4);
    v6 = 0;
    v8 = (_DWORD *)(TargetHeight + 8);
    do
    {
      if ( *v8 != -2 )
        break;
      ++v6;
      v8 += 6;
    }
    while ( v6 <= v7 );
    TargetHeight = (unsigned int)&this->TargetHeight;
  }
  else
  {
    v6 = 0;
  }
  v9 = (_DWORD *)TargetHeight;
  v38 = (_DWORD *)TargetHeight;
  v39 = v6;
  while ( v9 != nullptr )
  {
    v10 = *v9;
    v42 = *v9;
    if ( *v9 == 0 || (signed int)v6 > *(_DWORD *)(v10 + 4) )
      break;
    v11 = 24 * v6;
    v12 = *(_DWORD *)(24 * v6 + v10 + 24);
    v13 = *(_DWORD *)(v12 + 12);
    v41 = 24 * v6;
    nonZeroTimes = 0;
    if ( v13 == 0 )
      goto LABEL_44;
    v14 = *(_QWORD **)(v12 + 8);
    do
    {
      if ( *v14 != 0 )
        ++nonZeroTimes;
      ++v14;
      --v13;
    }
    while ( v13 != 0 );
    v15 = nullptr;
    if ( nonZeroTimes != 0 )
    {
      v43 = 2;
      v16 = (IShaderDevice *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                               this: GMemory::pGlobalHeap,
                               a2: movieProfile,
                               a3: 32,
                               a4: &v43);
      if ( v16 != nullptr )
      {
        v16->__vftable = (IShaderDevice_vtbl *)&GRefCountImplCore::`vftable';
        v16[1].__vftable = (IShaderDevice_vtbl *)1;
        v16->__vftable = (IShaderDevice_vtbl *)&GFxAmpMovieInstructionStats::ScriptBufferStats::`vftable';
        v16[5].__vftable = nullptr;
        v16[6].__vftable = nullptr;
        v16[7].__vftable = nullptr;
        v15 = v16;
      }
      v17 = *(_QWORD *)(v11 + *v38 + 16);
      v45 = v15;
      v15[2].__vftable = *(IShaderDevice_vtbl **)((char *)&v17 + 4);
      v15[3].__vftable = *(IShaderDevice_vtbl **)(v11 + *v38 + 16);
      v18 = nonZeroTimes;
      v15[4].__vftable = *(IShaderDevice_vtbl **)(*(_DWORD *)(v11 + v10 + 24) + 12);
      v19 = (ButtonCode_t)&v15[5];
      if ( v18 >= *(_DWORD *)(v19 + 4) )
      {
        if ( v18 >= *(_DWORD *)(v19 + 8) )
        {
          GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v19,
            pheapAddr: v19,
            newCapacity: v18 + (v18 >> 2));
LABEL_24:
          v18 = nonZeroTimes;
        }
      }
      else if ( v18 < *(_DWORD *)(v19 + 8) >> 1 )
      {
        GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
          this: (void **)v19,
          pheapAddr: v19,
          newCapacity: v18);
        goto LABEL_24;
      }
      *(_DWORD *)(v19 + 4) = v18;
      v20 = *(_DWORD *)(v11 + v10 + 24);
      v21 = 0;
      i = 0;
      if ( *(_DWORD *)(v20 + 12) != 0 )
      {
        nonZeroTimes = 0;
        do
        {
          if ( *(_QWORD *)(8 * v21 + *(_DWORD *)(v20 + 8)) != 0 )
          {
            v22 = (char *)v45[5].__vftable + nonZeroTimes;
            *(_DWORD *)v22 = v21;
            v23 = (_QWORD *)(8 * v21 + *(_DWORD *)(*(_DWORD *)(v11 + v10 + 24) + 8));
            GTimer::GetRawFrequency(freq: (void *)v21);
            v25 = 1000000LL * *v23 / v24;
            nonZeroTimes += 16;
            v10 = v42;
            v21 = i;
            v11 = v41;
            *((_QWORD *)v22 + 1) = v25;
          }
          v20 = *(_DWORD *)(v11 + v10 + 24);
          i = ++v21;
        }
        while ( v21 < *(_DWORD *)(v20 + 12) );
      }
      Format = movieProfile[1].Format;
      v27 = *(_DWORD *)(Format + 12);
      v28 = v27;
      v29 = (GRenderer::CachedData *)(Format + 8);
      v30 = v27 + 1;
      if ( v30 >= v28 )
      {
        if ( (GRenderer *)v30 >= v29[1].pRenderer )
          GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
            this: v29,
            pheapAddr: v29,
            newCapacity: v30 + (v30 >> 2));
      }
      else
      {
        v31 = v28 - v30;
        v32 = (IShaderAPI **)((char *)v29->pRenderer + 4 * v31 + 4 * v30 - 4);
        if ( v31 != 0 )
        {
          for ( i = v31; i != 0; --i )
          {
            if ( *v32 != nullptr )
              GRefCountImpl::Release(this: *v32);
            --v32;
          }
        }
        if ( v30 < (unsigned int)v29[1].pRenderer >> 1 )
          GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
            this: v29,
            pheapAddr: v29,
            newCapacity: v30);
      }
      pRenderer = v29->pRenderer;
      v34 = v45;
      v29->hData = (void *)v30;
      v35 = (IShaderDevice **)((char *)pRenderer + 4 * v30 - 4);
      if ( v35 != nullptr )
      {
        GRefCountImpl::AddRef(this: v34);
        *v35 = v34;
      }
      GRefCountImpl::Release(this: (IShaderAPI *)v34);
      v6 = v39;
    }
    v9 = v38;
LABEL_44:
    v36 = *(_DWORD *)(*v9 + 4);
    if ( (int)v6 <= (int)v36 )
    {
      v39 = ++v6;
      if ( v6 <= v36 )
      {
        v37 = (_DWORD *)(*v9 + 24 * v6 + 8);
        do
        {
          if ( *v37 != -2 )
            break;
          ++v6;
          v37 += 6;
          v39 = v6;
        }
        while ( v6 <= v36 );
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1008D920
// Name: public: void GFxAmpViewStats::ClearMarkers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::ClearMarkers(GImageInfo *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi

  v2 = (_RTL_CRITICAL_SECTION *)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>(this: (ScaleformUIImpl *)((char *)this + 152));
  LeaveCriticalSection(lpCriticalSection: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1008DF20
// Name: public: GFxAmpViewStats::GFxAmpBufferInstructionTimes::GFxAmpBufferInstructionTimes(unsigned long)
// Source: json
//------------------------------------------------------------------------------
GFxAmpViewStats::GFxAmpBufferInstructionTimes *__thiscall GFxAmpViewStats::GFxAmpBufferInstructionTimes::GFxAmpBufferInstructionTimes(
        GFxAmpViewStats::GFxAmpBufferInstructionTimes *this,
        unsigned int size)
{
  CStudioHdr *v3; // esi

  *this = (GFxAmpViewStats::GFxAmpBufferInstructionTimes)&GRefCountImplCore::`vftable';
  v3 = (CStudioHdr *)(this + 2);
  *(this + 1) = (GFxAmpViewStats::GFxAmpBufferInstructionTimes)1;
  *this = (GFxAmpViewStats::GFxAmpBufferInstructionTimes)&GFxAmpViewStats::GFxAmpBufferInstructionTimes::`vftable';
  *(this + 3) = nullptr;
  *(this + 2) = nullptr;
  *(this + 4) = nullptr;
  if ( size >= (unsigned int)*(this + 3) )
    GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
      this: v3,
      pheapAddr: v3,
      newCapacity: size + (size >> 2));
  v3->m_pVModel = (virtualmodel_t *)size;
  memset(dst: (unsigned __int8 *)v3->m_pStudioHdr, value: 0, count: 8 * size);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008E320
// Name: public: GFxAmpViewStats::GFxAmpViewStats(void)
// Source: json
//------------------------------------------------------------------------------
ScaleformUILogging *__thiscall GFxAmpViewStats::GFxAmpViewStats(ScaleformUILogging *this)
{
  _RTL_CRITICAL_SECTION *v2; // ebx
  unsigned int v3; // eax

  this->GFxLog::GFxState::GRefCountBase<GFxState,2>::GRefCountBaseStatImpl<GRefCountImpl,2>::GRefCountImpl::GRefCountImplCore::__vftable = (ScaleformUILogging_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->GFxLog::GFxState::GRefCountBase<GFxState,2>::GRefCountBaseStatImpl<GRefCountImpl,2>::GRefCountImpl::GRefCountImplCore::__vftable = (ScaleformUILogging_vtbl *)&GFxAmpViewStats::`vftable';
  this->SType = State_None;
  this->GFxLog::GFxLogBase<GFxLog>::__vftable = nullptr;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 40);
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 40), spinCount: 0);
  *((_DWORD *)this + 16) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)this + 68));
  *((float *)this + 20) = 0.0;
  *((float *)this + 21) = 0.0;
  *((_DWORD *)this + 18) = 0;
  *((float *)this + 22) = 0.0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 23) = 0;
  GFxRandom::Generator::Generator(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)(this + 6));
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  EnterCriticalSection(lpCriticalSection: v2);
  v3 = nextHandle;
  *((_DWORD *)this + 16) = nextHandle;
  nextHandle = v3 + 1;
  LeaveCriticalSection(lpCriticalSection: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008E3C0
// Name: public: virtual GFxAmpViewStats::~GFxAmpViewStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::~GFxAmpViewStats(GImageInfo *this)
{
  volatile LONG *v2; // edi

  GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>(this: (ScaleformUIImpl *)((char *)this + 152));
  v2 = (volatile LONG *)(*((_DWORD *)this + 17) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  GHashSetBase<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::~GHashSetBase<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeHashF>>(this: &this->ImageId);
  GHashSetBase<GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>,GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>::NodeHashF,GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>::NodeAltHashF,GAllocatorLH<GFxAmpViewStats::FileLinePair,2>,GHashsetCachedNodeEntry<GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>,GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>::NodeHashF>>::~GHashSetBase<GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>,GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>::NodeHashF,GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>::NodeAltHashF,GAllocatorLH<GFxAmpViewStats::FileLinePair,2>,GHashsetCachedNodeEntry<GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>,GHashNode<GFxAmpViewStats::FileLinePair,unsigned __int64,GFixedSizeHash<GFxAmpViewStats::FileLinePair>>::NodeHashF>>(this: (CMemberFuncProxyBase<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1>::*)(void),CFuncMemPolicyNone> *)&this->ReleaseImage);
  GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(this: (int *)&this->TargetHeight);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)this->TextureUsage);
  GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpViewStats::GFxAmpBufferInstructionTimes>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(this: (int *)&this->pTexture);
  GHashSetBase<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeAltHashF,GAllocatorLH<GFxAmpViewStats::ParentChildFunctionPair,2>,GHashsetCachedNodeEntry<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF>>::Clear(this: (int *)&this->GTexture::ChangeHandler);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1008E470
// Name: public: void GFxAmpViewStats::RegisterScriptFunction(unsigned long,unsigned long,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::RegisterScriptFunction(
        GFxAmpViewStats *this,
        IShaderAPI *swdHandle,
        unsigned int swfOffset,
        char *a4,
        IShaderAPI_vtbl *byteCodeLength)
{
  CMeshBuilder *v6; // edi
  char *v7; // eax
  IShaderAPI *v8; // esi
  int *v9[2]; // [esp+8h] [ebp-18h] BYREF
  int *v10[2]; // [esp+10h] [ebp-10h] BYREF
  unsigned __int64 iKey; // [esp+18h] [ebp-8h] BYREF

  iKey = swfOffset + __PAIR64__((unsigned int)swdHandle, 0);
  v6 = (CMeshBuilder *)((char *)this + 12);
  GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::FindAlt<unsigned __int64>(
    this: (int *)this + 3,
    a2: v10,
    a3: &iKey);
  if ( v10[0] == nullptr || *v10[0] == 0 || (int)v10[1] > *(_DWORD *)(*v10[0] + 4) )
  {
    swfOffset = 2;
    v7 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 32, a4: &swfOffset);
    v8 = (IShaderAPI *)v7;
    if ( v7 != nullptr )
    {
      *(_DWORD *)v7 = &GRefCountImplCore::`vftable';
      *((_DWORD *)v7 + 1) = 1;
      *(_DWORD *)v7 = &GFxAmpFunctionDesc::`vftable';
      GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v7 + 8));
    }
    else
    {
      v8 = nullptr;
    }
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v8[2],
      a2: (unsigned __int8 *)a4);
    v8[3].__vftable = byteCodeLength;
    v8[4].__vftable = nullptr;
    v8[5].__vftable = nullptr;
    v8[6].__vftable = nullptr;
    swdHandle = v8;
    v9[0] = (int *)&iKey;
    v9[1] = (int *)&swdHandle;
    GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeRef>(
      a1: v6,
      a2: (int)&iKey,
      pheapAddr: (VertexCompressionType_t)v6,
      a4: v9);
    if ( swdHandle != nullptr )
      GRefCountImpl::Release(this: swdHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E550
// Name: public: void GFxAmpViewStats::PopCallstack(unsigned long,unsigned long,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::PopCallstack(
        int this,
        GImageInfo *result,
        unsigned int swfOffset,
        unsigned __int64 funcTime)
{
  int v5; // eax
  unsigned int v6; // ebx
  int v7; // eax
  int v8; // esi
  void (__thiscall *v9)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // ecx
  const FourQuaternions **v10; // eax
  int v11; // eax
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-30h]
  void (__thiscall *it)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // [esp+10h] [ebp-2Ch] BYREF
  const FourQuaternions **p_stats; // [esp+14h] [ebp-28h]
  const FourQuaternions *stats; // [esp+18h] [ebp-24h] BYREF
  int v16; // [esp+20h] [ebp-1Ch]
  int v17; // [esp+24h] [ebp-18h]
  int v18; // [esp+28h] [ebp-14h] BYREF
  int v19; // [esp+2Ch] [ebp-10h]
  unsigned __int64 v20; // [esp+30h] [ebp-Ch]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)(this + 40);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 40));
  v5 = *(_DWORD *)(this + 20);
  v6 = v5 - 1;
  if ( v5 != 0 )
  {
    if ( v6 < *(_DWORD *)(this + 24) >> 1 )
      GArrayDataBase<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        this: (void **)(this + 16),
        pheapAddr: (const void *)(this + 16),
        newCapacity: v6);
  }
  else if ( v6 >= *(_DWORD *)(this + 24) )
  {
    GArrayDataBase<unsigned __int64,GAllocatorLH<unsigned __int64,2>,GArrayConstPolicy<0,4,1>>::Reserve(
      this: (void **)(this + 16),
      pheapAddr: (const void *)(this + 16),
      newCapacity: v6 + (v6 >> 2));
  }
  *(_DWORD *)(this + 20) = v6;
  v20 = swfOffset + __PAIR64__((unsigned int)result, 0);
  if ( *(_DWORD *)(this + 20) != 0 )
  {
    v7 = *(_DWORD *)(this + 16);
    v8 = *(_DWORD *)(this + 20);
    v18 = *(_DWORD *)(v7 + 8 * v8 - 8);
    v19 = *(_DWORD *)(v7 + 8 * v8 - 4);
  }
  else
  {
    v18 = 0;
    v19 = 0;
  }
  GHashSetBase<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeAltHashF,GAllocatorLH<GFxAmpViewStats::ParentChildFunctionPair,2>,GHashsetCachedNodeEntry<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF>>::FindAlt<GFxAmpViewStats::ParentChildFunctionPair>(
    this: (int *)(this + 8),
    a2: (int **)&it,
    a3: &v18);
  v9 = it;
  if ( it == nullptr || *(_DWORD *)it == 0 || (v10 = p_stats, (int)p_stats > *(_DWORD *)(*(_DWORD *)it + 4)) )
  {
    p_stats = &stats;
    stats = nullptr;
    v16 = 0;
    v17 = 0;
    it = (void (__thiscall *)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *))&v18;
    GHashSetBase<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeAltHashF,GAllocatorLH<GFxAmpViewStats::ParentChildFunctionPair,2>,GHashsetCachedNodeEntry<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF>>::Set<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeRef>(
      this: (int *)(this + 8),
      a2: this + 8,
      a3: &it);
    GHashSetBase<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeAltHashF,GAllocatorLH<GFxAmpViewStats::ParentChildFunctionPair,2>,GHashsetCachedNodeEntry<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF>>::FindAlt<GFxAmpViewStats::ParentChildFunctionPair>(
      this: (int *)(this + 8),
      a2: (int **)&it,
      a3: &v18);
    v9 = it;
    v10 = p_stats;
  }
  v11 = 40 * (_DWORD)v10;
  ++*(_DWORD *)(v11 + *(_DWORD *)v9 + 32);
  *(_QWORD *)(v11 + *(_DWORD *)v9 + 40) += funcTime;
  if ( *(_DWORD *)(this + 20) == 1 && v18 == 35 && v19 == 1 )
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1008E770
// Name: public: void GFxAmpViewStats::AddMarker(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpViewStats::AddMarker(GFxAmpViewStats *this, GString a2)
{
  const char *pData; // ebx
  int *v4; // edi
  void *v5; // esi
  int v6; // eax
  void *v7; // esi
  int v8[2]; // [esp+Ch] [ebp-10h] BYREF
  int *v9; // [esp+14h] [ebp-8h] BYREF
  int v10; // [esp+18h] [ebp-4h] BYREF

  pData = (const char *)a2.pData;
  GString::GString(this: &a2, src: (int)a2.pData);
  v4 = (int *)((char *)this + 152);
  GHashSetBase<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF>>::FindAlt<GString>(
    this: v4,
    a2: &v9,
    a3: &a2);
  v5 = (void *)(a2.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a2.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
  if ( v9 != nullptr && *v9 != 0 && v10 <= *(_DWORD *)(*v9 + 4) )
  {
    ++*(_DWORD *)(*v9 + 16 * v10 + 20);
  }
  else
  {
    v10 = 1;
    GString::GString(this: &a2, src: (int)pData);
    v8[0] = (int)&a2;
    v8[1] = (int)&v10;
    v6 = GString::BernsteinHashFunctionCIS(
           result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((a2.HeapTypeBits & 0xFFFFFFFC)
                                                                                          + 8),
           size: *(_DWORD *)(a2.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
           seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
    GHashSetBase<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF>>::add<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeRef>(
      this: (CUtlHash<int,CKeyValuesGrowableStringTable::CLookupFunctor &,CKeyValuesGrowableStringTable::CLookupFunctor &> *)v4,
      a2: (int)v4,
      a3: (int)v8,
      a4: v6);
    v7 = (void *)(a2.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a2.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E860
// Name: public: void GFxAmpViewStats::CollectAmpFunctionStats(struct GFxMovieStats __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpViewStats::CollectAmpFunctionStats(
        GImageInfo *this@<ecx>,
        GImage *movieProfile,
        unsigned int locker,
        unsigned int funcTimeIter)
{
  _DWORD *p_dtr_ChangeHandler; // ecx
  unsigned int v6; // eax
  unsigned int v7; // edx
  _DWORD *v8; // ecx
  void (__thiscall *v9)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // edi
  int v10; // esi
  int v11; // ebx
  void *v12; // ecx
  unsigned int v13; // ecx
  unsigned __int64 v14; // rax
  unsigned int Width; // esi
  int v16; // edi
  unsigned int v17; // esi
  unsigned int v18; // edi
  char *v19; // eax
  char *v20; // edi
  int v21; // edi
  int v22; // ebx
  CMeshBuilder *v23; // esi
  int v24; // edx
  unsigned int v25; // ecx
  _DWORD *v26; // edx
  _BYTE v27[32]; // [esp+Ch] [ebp-54h]
  int *v28[2]; // [esp+2Ch] [ebp-34h] BYREF
  int *v29[2]; // [esp+34h] [ebp-2Ch] BYREF
  int *v30; // [esp+3Ch] [ebp-24h] BYREF
  int v31; // [esp+40h] [ebp-20h]
  unsigned __int64 swfHandleAndOffset; // [esp+44h] [ebp-1Ch] BYREF
  void (__thiscall *funcTimeItera)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // [esp+4Ch] [ebp-14h]
  int v34; // [esp+50h] [ebp-10h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+54h] [ebp-Ch]
  GImageInfo *v36; // [esp+58h] [ebp-8h]
  int v37; // [esp+5Ch] [ebp-4h]

  v36 = this;
  lpCriticalSection = (LPCRITICAL_SECTION)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  p_dtr_ChangeHandler = &this->dtr_ChangeHandler;
  if ( p_dtr_ChangeHandler != nullptr )
  {
    v7 = p_dtr_ChangeHandler[1];
    v6 = 0;
    v8 = p_dtr_ChangeHandler + 2;
    do
    {
      if ( *v8 != -2 )
        break;
      ++v6;
      v8 += 10;
    }
    while ( v6 <= v7 );
    p_dtr_ChangeHandler = &this->GImageInfoBaseImpl::GImageInfoBase::GTexture::ChangeHandler::__vftable;
  }
  else
  {
    v6 = 0;
  }
  v9 = (void (__thiscall *)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *))p_dtr_ChangeHandler;
  funcTimeItera = (void (__thiscall *)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *))p_dtr_ChangeHandler;
  v34 = v6;
  while ( v9 != nullptr )
  {
    v10 = *(_DWORD *)v9;
    if ( *(_DWORD *)v9 == 0 || (signed int)v6 > *(_DWORD *)(v10 + 4) )
      break;
    v11 = 40 * v6;
    v12 = *(void **)(40 * v6 + v10 + 32);
    if ( v12 != nullptr || *(_QWORD *)(v11 + v10 + 40) != 0 )
    {
      *(_DWORD *)v27 = *(_DWORD *)(v11 + v10 + 24);
      *(_DWORD *)&v27[4] = *(_DWORD *)(v11 + v10 + 28);
      *(_QWORD *)&v27[8] = *(_QWORD *)(v11 + v10 + 16);
      *(_DWORD *)&v27[16] = *(_DWORD *)(40 * v6 + v10 + 32);
      GTimer::GetRawFrequency(freq: v12);
      v13 = *(_DWORD *)(v11 + v10 + 44);
      v37 = HIDWORD(v14);
      *(_QWORD *)&v27[24] = 1000000 * __PAIR64__(v13, *(_DWORD *)(v11 + v10 + 40)) / v14;
      Width = movieProfile[1].Width;
      v16 = *(_DWORD *)(Width + 12);
      v17 = Width + 8;
      v18 = v16 + 1;
      if ( v18 >= *(_DWORD *)(v17 + 4) )
      {
        if ( v18 >= *(_DWORD *)(v17 + 8) )
          GArrayDataBase<GFxAmpMemSegment,GAllocatorLH<GFxAmpMemSegment,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v17,
            result: (mstudiobonecontroller_t *)v17,
            newCapacity: v18 + (v18 >> 2));
      }
      else if ( v18 < *(_DWORD *)(v17 + 8) >> 1 )
      {
        GArrayDataBase<GFxAmpMemSegment,GAllocatorLH<GFxAmpMemSegment,2>,GArrayDefaultPolicy>::Reserve(
          this: (void **)v17,
          result: (mstudiobonecontroller_t *)v17,
          newCapacity: v18);
      }
      v19 = *(char **)v17;
      *(_DWORD *)(v17 + 4) = v18;
      v20 = &v19[32 * v18 - 32];
      if ( v20 != nullptr )
        qmemcpy(v20, v27, 32);
      swfHandleAndOffset = *(_QWORD *)(v11 + *(_DWORD *)funcTimeItera + 24);
      GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::FindAlt<unsigned __int64>(
        this: (int *)&v36->pTexture,
        a2: &v30,
        a3: &swfHandleAndOffset);
      if ( v30 != nullptr && *v30 != 0 )
      {
        v21 = *v30;
        v22 = v31;
        if ( v31 <= *(_DWORD *)(*v30 + 4) )
        {
          v23 = (CMeshBuilder *)(movieProfile[1].Width + 20);
          GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::FindAlt<unsigned __int64>(
            this: &v23->m_VertexSize_Position,
            a2: v29,
            a3: &swfHandleAndOffset);
          if ( v29[0] == nullptr || *v29[0] == 0 || (int)v29[1] > *(_DWORD *)(*v29[0] + 4) )
          {
            v28[0] = (int *)&swfHandleAndOffset;
            v28[1] = (int *)(v21 + 8 * (3 * v22 + 3));
            GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<GHashNode<unsigned __int64,GPtr<GFxAmpFunctionDesc>,GFixedSizeHash<unsigned __int64>>::NodeRef>(
              a1: v23,
              a2: (int)v28,
              pheapAddr: (VertexCompressionType_t)v23,
              a4: v28);
          }
        }
      }
      v9 = funcTimeItera;
      v6 = v34;
    }
    v24 = *(_DWORD *)v9;
    v25 = *(_DWORD *)(*(_DWORD *)v9 + 4);
    if ( (int)v6 <= (int)v25 )
    {
      v34 = ++v6;
      if ( v6 <= v25 )
      {
        v26 = (_DWORD *)(v24 + 40 * v6 + 8);
        do
        {
          if ( *v26 != -2 )
            break;
          ++v6;
          v26 += 10;
          v34 = v6;
        }
        while ( v6 <= v25 );
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1008EA60
// Name: public: void GFxAmpViewStats::CollectAmpSourceLineStats(struct GFxMovieStats __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxAmpViewStats::CollectAmpSourceLineStats(
        GImageInfo *this@<ecx>,
        GImage *movieProfile,
        unsigned int sourceTimeIter,
        unsigned int locker)
{
  int v5; // eax
  bool *p_ReleaseImage; // edx
  unsigned int v7; // ecx
  unsigned int v8; // esi
  _DWORD *v9; // eax
  signed int v10; // ebx
  int v11; // eax
  _DWORD *v12; // esi
  unsigned int v13; // ecx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax
  int v16; // esi
  unsigned int v17; // edi
  int v18; // eax
  int v19; // edi
  int *v20; // esi
  unsigned int v21; // eax
  _DWORD *v22; // ecx
  _DWORD v23[2]; // [esp+Ch] [ebp-4Ch] BYREF
  CMemberFuncProxy0<CParallelProcessor<KMeansQuantizationWorkUnit,CFuncJobItemProcessor<KMeansQuantizationWorkUnit>,1> *,void (__thiscall CParallelProcessor<KMeansQuantizationWorkUnit,CFuncJobItemProcessor<KMeansQuantizationWorkUnit>,1>::*)(void),CFuncMemPolicyNone> sourceTimeItera; // [esp+14h] [ebp-44h]
  int *v25[2]; // [esp+1Ch] [ebp-3Ch] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+24h] [ebp-34h]
  GImageInfo *v27; // [esp+28h] [ebp-30h]
  int v28; // [esp+2Ch] [ebp-2Ch]
  int *v29; // [esp+30h] [ebp-28h] BYREF
  int v30; // [esp+34h] [ebp-24h]
  GImage *v31; // [esp+38h] [ebp-20h]
  int v32; // [esp+3Ch] [ebp-1Ch] BYREF
  int v33; // [esp+40h] [ebp-18h]
  void *v34; // [esp+44h] [ebp-14h]
  int v35; // [esp+48h] [ebp-10h]
  unsigned __int64 v36; // [esp+4Ch] [ebp-Ch]

  v31 = movieProfile;
  v27 = this;
  lpCriticalSection = (LPCRITICAL_SECTION)(this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 1));
  v5 = *(_DWORD *)&this->ReleaseImage;
  p_ReleaseImage = &this->ReleaseImage;
  if ( v5 != 0 )
  {
    v8 = *(_DWORD *)(v5 + 4);
    v7 = 0;
    v9 = (_DWORD *)(v5 + 8);
    do
    {
      if ( *v9 != -2 )
        break;
      ++v7;
      v9 += 8;
    }
    while ( v7 <= v8 );
  }
  else
  {
    p_ReleaseImage = nullptr;
    v7 = 0;
  }
  sourceTimeItera.m_pfnProxied = (void (__thiscall *)(CParallelProcessor<KMeansQuantizationWorkUnit,CFuncJobItemProcessor<KMeansQuantizationWorkUnit>,1> *))p_ReleaseImage;
  v10 = v7;
  while ( p_ReleaseImage != nullptr )
  {
    v11 = *(_DWORD *)p_ReleaseImage;
    if ( *(_DWORD *)p_ReleaseImage == 0 || v10 > *(_DWORD *)(v11 + 4) )
      break;
    v12 = (_DWORD *)(v11 + 32 * v10);
    if ( v12[9] != 0 || v12[8] != 0 )
    {
      v32 = v12[4];
      v33 = v12[5];
      v34 = (void *)v12[6];
      GTimer::GetRawFrequency(freq: v34);
      v13 = v12[8];
      v28 = HIDWORD(v14);
      v15 = 1000000 * __PAIR64__(v12[9], v13) / v14;
      v16 = v31[1].Height + 8;
      v36 = v15;
      v17 = *(_DWORD *)(v16 + 4) + 1;
      if ( v17 >= *(_DWORD *)(v16 + 4) )
      {
        if ( v17 >= *(_DWORD *)(v16 + 8) )
          GArrayDataBase<MovieSourceLineStats::SourceStats,GAllocatorLH<MovieSourceLineStats::SourceStats,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v16,
            a2: (const void *)v16,
            a3: v17 + (v17 >> 2));
      }
      else if ( v17 < *(_DWORD *)(v16 + 8) >> 1 )
      {
        GArrayDataBase<MovieSourceLineStats::SourceStats,GAllocatorLH<MovieSourceLineStats::SourceStats,2>,GArrayDefaultPolicy>::Reserve(
          this: (void **)v16,
          a2: (const void *)v16,
          a3: *(_DWORD *)(v16 + 4) + 1);
      }
      v18 = *(_DWORD *)v16 + 24 * v17 - 24;
      *(_DWORD *)(v16 + 4) = v17;
      if ( v18 != 0 )
      {
        *(_DWORD *)v18 = v32;
        *(_DWORD *)(v18 + 4) = v33;
        *(_DWORD *)(v18 + 8) = v34;
        *(_DWORD *)(v18 + 12) = v35;
        *(_QWORD *)(v18 + 16) = v36;
      }
      GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::FindAlt<unsigned __int64>(
        this: (int *)&v27->ImageId,
        a2: &v29,
        a3: &v32);
      if ( v29 != nullptr && *v29 != 0 )
      {
        v19 = *v29;
        if ( v30 <= *(_DWORD *)(*v29 + 4) )
        {
          v20 = (int *)(v31[1].Height + 20);
          GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::FindAlt<unsigned __int64>(
            this: v20,
            a2: v25,
            a3: &v32);
          if ( v25[0] == nullptr || *v25[0] == 0 || (int)v25[1] > *(_DWORD *)(*v25[0] + 4) )
          {
            v23[0] = &v32;
            v23[1] = v19 + 8 * (3 * v30 + 3);
            GHashSetBase<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeHashF,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<GHashNode<unsigned __int64,GString,GFixedSizeHash<unsigned __int64>>::NodeRef>(
              a1: v20,
              a2: (int)v23,
              a3: v20,
              a4: v23);
          }
        }
      }
      p_ReleaseImage = (bool *)sourceTimeItera.m_pfnProxied;
    }
    v21 = *(_DWORD *)(*(_DWORD *)p_ReleaseImage + 4);
    if ( v10 <= (int)v21 && ++v10 <= v21 )
    {
      v22 = (_DWORD *)(32 * v10 + *(_DWORD *)p_ReleaseImage + 8);
      do
      {
        if ( *v22 != -2 )
          break;
        ++v10;
        v22 += 8;
      }
      while ( v10 <= v21 );
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}
