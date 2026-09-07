// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gstats.cpp
// Functions: 176
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gstats.h"

//------------------------------------------------------------------------------
// Address: 0x10063C90
// Name: public: void GStatDescRegistry::RegisterDesc(struct GStatDesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStatDescRegistry::RegisterDesc(GStatDescRegistry *this, struct GStatDesc *a2)
{
  unsigned int v2; // eax
  unsigned __int16 v3; // dx
  unsigned __int16 *v4; // eax
  _DWORD *v5; // eax

  v2 = a2->Id >> 3;
  v3 = *((_WORD *)this + v2 + 2);
  v4 = (unsigned __int16 *)((char *)this + 2 * v2 + 4);
  if ( v3 == 0 )
  {
    if ( (unsigned int)(*(_DWORD *)this + 8) > 0x400 )
      return;
    v3 = *(_WORD *)this + 1;
    *v4 = v3;
    v5 = (_DWORD *)((char *)this + 4 * *(_DWORD *)this + 1028);
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    v5[4] = 0;
    v5[5] = 0;
    v5[6] = 0;
    v5[7] = 0;
    *(_DWORD *)this += 8;
  }
  *((_DWORD *)this + v3 + (a2->Id & 7) + 256) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x10063D10
// Name: public: static void GStatDesc::RegisterDesc(struct GStatDesc __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GStatDesc::RegisterDesc(void *pdesc, struct GStatDesc *a2)
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)a2;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = a2;
  else
    GStats_pFirstDesc = (int)a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063D40
// Name: public: void GStatBag::Clear(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GStatBag::Clear(
        CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = nullptr;
  memset(&this->m_iRefs, 0xFFu, 0x200u);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10063D70
// Name: private: void GStatBag::CombineStatBags(class GStatBag const __near &,bool (GStatBag::*)(unsigned int,class GStat __near *))
// Source: json
//------------------------------------------------------------------------------
int __thiscall GStatBag::CombineStatBags(
        void *this,
        const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *other,
        IShaderAPI *const combineFunc)
{
  int v4; // edi
  int result; // eax
  int i; // esi
  unsigned __int16 *ptable; // [esp+10h] [ebp-4h]
  int *othera; // [esp+1Ch] [ebp+8h]

  v4 = 0;
  othera = &other->m_iRefs;
  do
  {
    result = *(unsigned __int16 *)othera;
    if ( result != 0xFFFF )
    {
      ptable = (unsigned __int16 *)other->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable
             + 4 * result;
      for ( i = 0; i < 16; ++i )
      {
        result = ptable[i];
        if ( (_WORD)result != 0xFFFF )
          result = ((int (__thiscall *)(void *, int, char *))combineFunc)(
                     a1: this,
                     a2: i | (16 * v4),
                     a3: (char *)other->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable
                   + 8 * result);
      }
    }
    othera = (int *)((char *)othera + 2);
    ++v4;
  }
  while ( v4 < 256 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063E00
// Name: private: unsigned char __near * GStatBag::AllocStatData(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall GStatBag::AllocStatData(GStatBag *this, unsigned int statId, unsigned int size)
{
  char v3; // dl
  unsigned __int16 v4; // si
  unsigned int v5; // edi
  unsigned int MemAllocOffset; // eax
  unsigned __int8 *result; // eax
  unsigned __int8 *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx

  v3 = statId;
  v4 = this->IdPageTable[statId >> 4];
  v5 = (size + 7) & 0xFFFFFFF8;
  if ( v4 == 0xFFFF )
  {
    MemAllocOffset = this->MemAllocOffset;
    if ( this->MemSize < MemAllocOffset + 32 )
      return nullptr;
    v4 = MemAllocOffset >> 3;
    this->IdPageTable[statId >> 4] = v4;
    v8 = &this->pMem[this->MemAllocOffset];
    *(_DWORD *)v8 = -1;
    *((_DWORD *)v8 + 1) = -1;
    *((_DWORD *)v8 + 2) = -1;
    *((_DWORD *)v8 + 3) = -1;
    *((_DWORD *)v8 + 4) = -1;
    *((_DWORD *)v8 + 5) = -1;
    *((_DWORD *)v8 + 6) = -1;
    *((_DWORD *)v8 + 7) = -1;
    this->MemAllocOffset += 32;
    v3 = statId;
  }
  v9 = this->MemAllocOffset;
  if ( this->MemSize < v9 + v5 )
    return nullptr;
  *(_WORD *)&this->pMem[8 * v4 + 2 * (v3 & 0xF)] = v9 >> 3;
  v10 = this->MemAllocOffset;
  result = &this->pMem[v10];
  this->MemAllocOffset = v5 + v10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063EB0
// Name: private: virtual void GStatInfo_InterfaceImpl<class GTimerStat>::GetStat(class GStat __near *,struct GStat::StatValue __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__stdcall GStatInfo_InterfaceImpl<GTimerStat>::GetStat(int *a1, _DWORD *a2, unsigned int index)
{
  int v3; // ecx
  int v4; // edx
  _DWORD *result; // eax

  if ( index == 0 )
  {
    v3 = *a1;
    v4 = a1[1];
    *a2 = 2;
    a2[1] = "Ticks";
    a2[2] = v3;
    a2[3] = v4;
    return a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063EE0
// Name: private: virtual void GStatInfo_InterfaceImpl<class GTimerStat>::Add(class GStat __near *,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__stdcall GStatInfo_InterfaceImpl<GTimerStat>::Add(_DWORD *a1, _DWORD *a2)
{
  bool v3; // cf

  v3 = __CFADD__(*a2, *a1);
  *a1 += *a2;
  a1[1] += a2[1] + v3;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10063F00
// Name: private: virtual void GStatInfo_InterfaceImpl<class GTimerStat>::SetMin(class GStat __near *,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GStatInfo_InterfaceImpl<GTimerStat>::SetMin(int *a1, int *a2)
{
  int v2; // esi
  int result; // eax

  v2 = *a2;
  result = a2[1];
  if ( *(_QWORD *)a2 >= *(_QWORD *)a1 )
  {
    v2 = *a1;
    result = a1[1];
  }
  *a1 = v2;
  a1[1] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063F30
// Name: private: virtual void GStatInfo_InterfaceImpl<class GTimerStat>::SetMax(class GStat __near *,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GStatInfo_InterfaceImpl<GTimerStat>::SetMax(int *a1, int *a2)
{
  int v2; // esi
  int result; // eax

  v2 = *a2;
  result = a2[1];
  if ( *(_QWORD *)a2 <= *(_QWORD *)a1 )
  {
    v2 = *a1;
    result = a1[1];
  }
  *a1 = v2;
  a1[1] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063F60
// Name: private: virtual void GStatInfo_InterfaceImpl<class GCounterStat>::GetStat(class GStat __near *,struct GStat::StatValue __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__stdcall GStatInfo_InterfaceImpl<GCounterStat>::GetStat(int *a1, _DWORD *a2, int a3)
{
  int v3; // ecx
  _DWORD *result; // eax

  if ( a3 == 0 )
  {
    v3 = *a1;
    *a2 = 1;
    a2[1] = "Count";
    a2[2] = v3;
    return a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063FA0
// Name: private: virtual void GStatInfo_InterfaceImpl<class GCounterStat>::Add(class GStat __near *,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GStatInfo_InterfaceImpl<GCounterStat>::Add(
        CUtlMemory<unsigned short,int> *this,
        _DWORD *a2,
        _DWORD *a3)
{
  *a2 += *a3;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10063FC0
// Name: private: virtual void GStatInfo_InterfaceImpl<class GCounterStat>::SetMin(class GStat __near *,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GStatInfo_InterfaceImpl<GCounterStat>::SetMin(CUtlMemory<unsigned short,int> *this, _DWORD *a2, int *a3)
{
  int result; // eax

  result = *a3;
  if ( (unsigned int)*a3 >= *a2 )
    *a2 = *a2;
  else
    *a2 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063FE0
// Name: private: virtual void GStatInfo_InterfaceImpl<class GCounterStat>::SetMax(class GStat __near *,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GStatInfo_InterfaceImpl<GCounterStat>::SetMax(CUtlMemory<unsigned short,int> *this, _DWORD *a2, int *a3)
{
  int result; // eax

  result = *a3;
  if ( (unsigned int)*a3 <= *a2 )
    *a2 = *a2;
  else
    *a2 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064000
// Name: public: void GMemoryStat::GetStat(struct GStat::StatValue __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryStat::GetStat(GMemoryStat *this, struct GStat::StatValue *a2, unsigned int index)
{
  unsigned int AllocCount; // ecx
  unsigned int Used; // ecx
  unsigned int Allocated; // ecx

  if ( index != 0 )
  {
    if ( index == 1 )
    {
      Used = this->Used;
      a2->pName = "Used";
      a2->Type = VT_Int;
      a2->IValue = Used;
    }
    else if ( index == 2 )
    {
      AllocCount = this->AllocCount;
      a2->pName = "AllocCount";
      a2->Type = VT_Int;
      a2->IValue = AllocCount;
    }
  }
  else
  {
    Allocated = this->Allocated;
    a2->pName = "Allocated";
    a2->Type = VT_Int;
    a2->IValue = Allocated;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064060
// Name: private: virtual void GStatInfo_InterfaceImpl<class GMemoryStat>::GetStat(class GStat __near *,struct GStat::StatValue __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GStatInfo_InterfaceImpl<GMemoryStat>::GetStat(
        GMemoryStat *a1,
        struct GStat::StatValue *a2,
        unsigned int a3)
{
  GMemoryStat::GetStat(this: a1, a2, index: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10064080
// Name: private: virtual void GStatInfo_InterfaceImpl<class GMemoryStat>::Init(class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStatInfo_InterfaceImpl<GMemoryStat>::Init(
        UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *this,
        const UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *p)
{
  p->m_Left = 0;
  p->m_Right = 0;
  p->m_Parent = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100640A0
// Name: private: virtual void GStatInfo_InterfaceImpl<class GMemoryStat>::Add(class GStat __near *,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStatInfo_InterfaceImpl<GMemoryStat>::Add(
        UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *this,
        _DWORD *a2,
        _DWORD *a3)
{
  *a2 += *a3;
  a2[1] += a3[1];
  a2[2] += a3[2];
}

//------------------------------------------------------------------------------
// Address: 0x100640C0
// Name: private: virtual void GStatInfo_InterfaceImpl<class GMemoryStat>::SetMin(class GStat __near *,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStatInfo_InterfaceImpl<GMemoryStat>::SetMin(
        UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *this,
        int *a2,
        int *a3)
{
  int v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // ecx

  v3 = *a3;
  if ( *a3 >= (unsigned int)*a2 )
    v3 = *a2;
  v4 = a2[1];
  *a2 = v3;
  v5 = a3[1];
  if ( v5 >= v4 )
    v5 = v4;
  v6 = a2[2];
  a2[1] = v5;
  v7 = a3[2];
  if ( v7 >= v6 )
    a2[2] = v6;
  else
    a2[2] = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10064100
// Name: private: virtual void GStatInfo_InterfaceImpl<class GMemoryStat>::SetMax(class GStat __near *,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStatInfo_InterfaceImpl<GMemoryStat>::SetMax(
        UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *this,
        int *a2,
        int *a3)
{
  int v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // ecx

  v3 = *a3;
  if ( *a3 <= (unsigned int)*a2 )
    v3 = *a2;
  v4 = a2[1];
  *a2 = v3;
  v5 = a3[1];
  if ( v5 <= v4 )
    v5 = v4;
  v6 = a2[2];
  a2[1] = v5;
  v7 = a3[2];
  if ( v7 <= v6 )
    a2[2] = v6;
  else
    a2[2] = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10064140
// Name: public: GStatBag::GStatBag(class GMemoryHeap __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GStatBag::GStatBag(
        _DWORD *this,
        int result,
        unsigned int memReserve)
{
  GMemoryHeap *v4; // ecx
  unsigned int v5; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax

  v4 = (GMemoryHeap *)result;
  if ( result == 0 )
    v4 = GMemory::pGlobalHeap;
  v5 = memReserve;
  Alloc_2 = v4->Alloc_2;
  result = 10;
  *this = Alloc_2(this: v4, a2: memReserve, a3: (const GAllocDebugInfo *)&result);
  *(this + 1) = v5;
  *(this + 2) = 0;
  memset(this + 3, 0xFFu, 0x200u);
  return (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100641A0
// Name: public: bool GStatBag::IncrementMemoryStat(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GStatBag::IncrementMemoryStat(GStatBag *this, unsigned int statId, unsigned int a3, unsigned int a4)
{
  int v4; // edx
  int v5; // edx
  unsigned __int8 *v6; // eax

  if ( statId >= 0x1000
    || (v4 = this->IdPageTable[statId >> 4]) == 0xFFFF
    || (v5 = *(unsigned __int16 *)&this->pMem[8 * v4 + 2 * (statId & 0xF)]) == 0xFFFF
    || (v6 = &this->pMem[8 * v5]) == nullptr )
  {
    v6 = GStatBag::AllocStatData(this, statId, size: 0xCu);
    if ( v6 == nullptr )
      return 0;
    *(_DWORD *)v6 = 0;
    *((_DWORD *)v6 + 1) = 0;
    *((_DWORD *)v6 + 2) = 0;
  }
  *(_DWORD *)v6 += a3;
  *((_DWORD *)v6 + 1) += a4;
  ++*((_DWORD *)v6 + 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10064220
// Name: public: static void GStatDesc::InitChildTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStatDesc::InitChildTree(void *this)
{
  IHardwareConfigInternal_vtbl *v1; // esi
  int v2; // ecx
  unsigned int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // edx
  int v7; // eax

  if ( GStats_InitDone.__vftable == nullptr )
  {
    do
    {
      v1 = GStats_InitByUs.__vftable;
      if ( GStats_InitByUs.__vftable == (IHardwareConfigInternal_vtbl *)1 )
      {
        while ( GStats_InitDone.__vftable == nullptr )
          ;
        return;
      }
    }
    while ( (IHardwareConfigInternal_vtbl *)InterlockedCompareExchange(
                                              Destination: (volatile LONG *)&GStats_InitByUs,
                                              Exchange: 1,
                                              Comperand: (LONG)GStats_InitByUs.__vftable) != v1 );
    v2 = GStats_pFirstDesc;
    if ( GStats_pFirstDesc != 0 )
    {
      do
      {
        v3 = *(_DWORD *)(v2 + 8);
        v4 = *(_DWORD *)(v2 + 20);
        *(_DWORD *)(v2 + 20) = 0;
        if ( word_10357F6C[v3 >> 3] != 0 )
          v5 = dword_10358368[(unsigned __int16)word_10357F6C[v3 >> 3] + (v3 & 7)];
        else
          v5 = 0;
        if ( v5 != v2 )
        {
          v6 = *(_DWORD *)(v5 + 16);
          if ( v6 != 0 )
          {
            v7 = *(_DWORD *)(v5 + 16);
            if ( *(_DWORD *)(v6 + 20) != 0 )
            {
              do
                v7 = *(_DWORD *)(v7 + 20);
              while ( *(_DWORD *)(v7 + 20) != 0 );
            }
            *(_DWORD *)(v7 + 20) = v2;
          }
          else
          {
            *(_DWORD *)(v5 + 16) = v2;
          }
        }
        v2 = v4;
      }
      while ( v4 != 0 );
    }
    GStats_pFirstDesc = 0;
    GStats_pLastDesc = 0;
    InterlockedExchange(Target: (volatile LONG *)&GStats_InitDone, Value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100642E0
// Name: public: static struct GStatDesc const __near * GStatDesc::GetDesc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl GStatDesc::GetDesc(unsigned int id)
{
  void *v1; // ecx

  if ( GStats_InitDone.__vftable == nullptr )
    GStatDesc::InitChildTree(this: v1);
  if ( word_10357F6C[id >> 3] != 0 )
    return dword_10358368[(unsigned __int16)word_10357F6C[id >> 3] + (id & 7)];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10064320
// Name: public: bool GStatBag::Add(unsigned int,class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStatBag::Add(
        CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *statId,
        int a3)
{
  GStatBag *v3; // esi
  int v4; // eax
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax

  v3 = (GStatBag *)this;
  if ( GStats_InitDone.__vftable == nullptr )
    GStatDesc::InitChildTree(this);
  v4 = (unsigned __int16)word_10357F6C[(unsigned int)statId >> 3];
  if ( word_10357F6C[(unsigned int)statId >> 3] != 0 )
    v4 = dword_10358368[v4 + ((unsigned __int8)statId & 7)];
  v5 = *((_DWORD *)GStats_InterfaceTable + *(unsigned __int8 *)v4);
  if ( (unsigned int)statId < 0x1000 )
  {
    v6 = v3->IdPageTable[(unsigned int)statId >> 4];
    if ( v6 != 0xFFFF )
    {
      v7 = *(unsigned __int16 *)&v3->pMem[8 * v6 + 2 * ((unsigned __int8)statId & 0xF)];
      if ( v7 != 0xFFFF )
      {
        v8 = &v3->pMem[8 * v7];
        if ( v8 != nullptr )
          goto LABEL_12;
        v3 = (GStatBag *)this;
      }
    }
  }
  v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 16))(a1: v5);
  v8 = GStatBag::AllocStatData(this: v3, (unsigned int)statId, size: v9);
  if ( v8 == nullptr )
    return;
  (*(void (__thiscall **)(int, unsigned __int8 *))(*(_DWORD *)v5 + 20))(a1: v5, a2: v8);
LABEL_12:
  (*(void (__thiscall **)(int, unsigned __int8 *, int))(*(_DWORD *)v5 + 24))(a1: v5, a2: v8, a3);
}

//------------------------------------------------------------------------------
// Address: 0x100643F0
// Name: private: void GStatBag::RecursiveGroupUpdate(class GStatDesc::Iterator)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStatBag::RecursiveGroupUpdate(GStatBag *this, struct GStatDesc::Iterator a2)
{
  GStatDesc *pChild; // esi
  unsigned int Id; // eax
  int v5; // edx
  int v6; // eax
  unsigned __int8 *v7; // eax

  if ( a2.pDesc != nullptr )
  {
    pChild = a2.pDesc->pChild;
    if ( (a2.pDesc->Flags & 5) == 5 )
    {
      for ( ; pChild != nullptr; pChild = pChild->pNextSibling )
      {
        GStatBag::RecursiveGroupUpdate(this, a2: (struct GStatDesc::Iterator)pChild);
        Id = pChild->Id;
        if ( Id < 0x1000 )
        {
          v5 = this->IdPageTable[Id >> 4];
          if ( v5 != 0xFFFF )
          {
            v6 = *(unsigned __int16 *)&this->pMem[8 * v5 + 2 * (pChild->Id & 0xF)];
            if ( v6 != 0xFFFF )
            {
              v7 = &this->pMem[8 * v6];
              if ( v7 != nullptr )
                GStatBag::Add(
                  (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
                  statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)a2.pDesc->Id,
                  a3: (int)v7);
            }
          }
        }
      }
    }
    else
    {
      for ( ; pChild != nullptr; pChild = pChild->pNextSibling )
        GStatBag::RecursiveGroupUpdate(this, a2: (struct GStatDesc::Iterator)pChild);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100644A0
// Name: public: bool GStatBag::GetStat(class GStatInfo __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GStatBag::GetStat(GStatBag *this, struct GStatInfo *a2, unsigned int statId)
{
  int v3; // edx
  unsigned __int8 *pMem; // eax
  void *v5; // ecx
  GStat *v6; // edi
  int v8; // eax
  GStatInfo::StatInterface *v9; // ecx

  if ( statId >= 0x1000 )
    return 0;
  v3 = this->IdPageTable[statId >> 4];
  if ( v3 == 0xFFFF )
    return 0;
  pMem = this->pMem;
  v5 = (void *)*(unsigned __int16 *)&this->pMem[8 * v3 + 2 * (statId & 0xF)];
  if ( v5 == (void *)0xFFFF )
    return 0;
  v6 = (GStat *)&pMem[8 * (_DWORD)v5];
  if ( v6 == nullptr )
    return 0;
  if ( GStats_InitDone.__vftable == nullptr )
    GStatDesc::InitChildTree(this: v5);
  v8 = (unsigned __int16)word_10357F6C[statId >> 3];
  if ( word_10357F6C[statId >> 3] != 0 )
    v8 = dword_10358368[v8 + (statId & 7)];
  v9 = *((GStatInfo::StatInterface **)GStats_InterfaceTable + *(unsigned __int8 *)v8);
  a2->StatId = statId;
  a2->pInterface = v9;
  a2->pData = v6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10064540
// Name: public: GStatBag::GStatBag(class GStatBag const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GStatBag::GStatBag(
        CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this@<ecx>,
        CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *source,
        __int128 a3)
{
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 10;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 0x2000, a3: &v4);
  this->m_nUserID = 0x2000;
  if ( this != source )
  {
    this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = nullptr;
    memset(&this->m_iRefs, 0xFFu, 0x200u);
    GStatBag::CombineStatBags(this, other: source, combineFunc: (IShaderAPI *const)GStatBag::Add);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100645B0
// Name: public: void GStatBag::UpdateGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStatBag::UpdateGroups(
        CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  if ( GStats_InitDone.__vftable == nullptr )
    GStatDesc::InitChildTree(this);
  if ( GStats_InitDone.__vftable == nullptr )
    GStatDesc::InitChildTree(this);
  if ( word_10357F6C[0] != 0 )
    GStatBag::RecursiveGroupUpdate(
      (GStatBag *)this,
      a2: (struct GStatDesc::Iterator)dword_10358368[(unsigned __int16)word_10357F6C[0]]);
  else
    GStatBag::RecursiveGroupUpdate((GStatBag *)this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100D45C0
// Name: private: virtual enum GStat::StatType GStatInfo_InterfaceImpl<class GTimerStat>::GetType(class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GStatInfo_InterfaceImpl<GTimerStat>::GetType(const CUtlMemory<unsigned short,int> *result)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x101092A0
// Name: private: virtual unsigned int GStatInfo_InterfaceImpl<class GTimerStat>::GetStatDataSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __cdecl GStatInfo_InterfaceImpl<GTimerStat>::GetStatDataSize()
{
  return 8;
}

//------------------------------------------------------------------------------
// Address: 0x1010D530
// Name: private: virtual unsigned int GStatInfo_InterfaceImpl<class GMemoryStat>::GetStatDataSize(void)const
// Source: json
//------------------------------------------------------------------------------
int GStatInfo_InterfaceImpl<GMemoryStat>::GetStatDataSize()
{
  return 12;
}

//------------------------------------------------------------------------------
// Address: 0x1013B890
// Name: private: virtual unsigned int GStatInfo_InterfaceImpl<class GMemoryStat>::GetStatCount(class GStat __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GStatInfo_InterfaceImpl<GMemoryStat>::GetStatCount(CBitVecT<CVarBitVecBase<int> > *this, unsigned int p)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x101DA385
// Name: public: long D3DXShader::CConstant::GetDesc(struct _D3DXCONSTANT_DESC __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CConstant::GetDesc(D3DXShader::CConstant *this, struct _D3DXCONSTANT_DESC *a2)
{
  int v2; // esi
  const char *v3; // eax
  int v4; // esi
  const void *v5; // eax

  a2->Name = nullptr;
  a2->RegisterSet = D3DXRS_BOOL;
  a2->RegisterIndex = 0;
  v2 = *((_DWORD *)this + 1);
  if ( v2 != 0 )
    v3 = (const char *)(v2 + *(_DWORD *)(*(_DWORD *)this + 8));
  else
    v3 = nullptr;
  a2->Name = v3;
  a2->RegisterSet = *((unsigned __int16 *)this + 4);
  a2->RegisterIndex = *((unsigned __int16 *)this + 5);
  a2->RegisterCount = *((unsigned __int16 *)this + 6);
  a2->Class = **((unsigned __int16 **)this + 6);
  a2->Type = *(unsigned __int16 *)(*((_DWORD *)this + 6) + 2);
  a2->Rows = *(unsigned __int16 *)(*((_DWORD *)this + 6) + 4);
  a2->Columns = *(unsigned __int16 *)(*((_DWORD *)this + 6) + 6);
  a2->Elements = *(unsigned __int16 *)(*((_DWORD *)this + 6) + 8);
  a2->StructMembers = *(unsigned __int16 *)(*((_DWORD *)this + 6) + 10);
  a2->Bytes = 4 * a2->Columns * a2->Rows * a2->Elements;
  v4 = *((_DWORD *)this + 5);
  if ( v4 != 0 )
    v5 = (const void *)(v4 + *(_DWORD *)(*(_DWORD *)this + 8));
  else
    v5 = nullptr;
  a2->DefaultValue = v5;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DA4FF
// Name: public: virtual long D3DXShader::CConstantTable::GetDesc(struct _D3DXCONSTANTTABLE_DESC __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::GetDesc(D3DXShader::CConstantTable *this, struct _D3DXCONSTANTTABLE_DESC *a2)
{
  unsigned int v3; // eax
  _DWORD *v4; // ecx
  int v5; // edi
  const char *v6; // eax

  if ( a2 == nullptr )
    return -2005530516;
  v3 = *((_DWORD *)this + 3);
  if ( v3 < 0x1C )
    return -2005529767;
  v4 = *((_DWORD **)this + 2);
  if ( *v4 < 0x1Cu || v4[1] >= v3 )
    return -2005529767;
  a2->Creator = nullptr;
  a2->Version = 0;
  a2->Constants = 0;
  v5 = v4[1];
  if ( v5 != 0 )
    v6 = (const char *)(v5 + *((_DWORD *)this + 2));
  else
    v6 = nullptr;
  a2->Creator = v6;
  a2->Version = v4[2];
  a2->Constants = v4[3];
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1028B650
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_Summary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_Summary__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_Summary);
}

//------------------------------------------------------------------------------
// Address: 0x1028B660
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_TotalFootprint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_TotalFootprint__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_TotalFootprint);
}

//------------------------------------------------------------------------------
// Address: 0x1028B670
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_LocalFootprint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_LocalFootprint__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_LocalFootprint);
}

//------------------------------------------------------------------------------
// Address: 0x1028B680
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_ChildFootprint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_ChildFootprint__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_ChildFootprint);
}

//------------------------------------------------------------------------------
// Address: 0x1028B690
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_ChildHeaps__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_ChildHeaps__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_ChildHeaps);
}

//------------------------------------------------------------------------------
// Address: 0x1028B6A0
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_LocalUsedSpace__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_LocalUsedSpace__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_LocalUsedSpace);
}

//------------------------------------------------------------------------------
// Address: 0x1028B6B0
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_SysDirectSpace__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_SysDirectSpace__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_SysDirectSpace);
}

//------------------------------------------------------------------------------
// Address: 0x1028B6C0
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_Bookkeeping__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_Bookkeeping__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_Bookkeeping);
}

//------------------------------------------------------------------------------
// Address: 0x1028B6D0
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_DebugInfo__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_DebugInfo__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_DebugInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1028B6E0
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_Segments__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_Segments__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_Segments);
}

//------------------------------------------------------------------------------
// Address: 0x1028B6F0
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_Granularity__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_Granularity__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_Granularity);
}

//------------------------------------------------------------------------------
// Address: 0x1028B700
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_DynamicGranularity__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_DynamicGranularity__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_DynamicGranularity);
}

//------------------------------------------------------------------------------
// Address: 0x1028B710
// Name: _dynamic_initializer_for__GSTAT_GStatHeap_Reserve__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatHeap_Reserve__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatHeap_Reserve);
}

//------------------------------------------------------------------------------
// Address: 0x1028B720
// Name: _dynamic_initializer_for__GSTAT_GStatRender_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028B730
// Name: _dynamic_initializer_for__GSTAT_GStatRender_VMem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_VMem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_VMem);
}

//------------------------------------------------------------------------------
// Address: 0x1028B740
// Name: _dynamic_initializer_for__GSTAT_GStatRender_Texture_VMem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_Texture_VMem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_Texture_VMem);
}

//------------------------------------------------------------------------------
// Address: 0x1028B750
// Name: _dynamic_initializer_for__GSTAT_GStatRender_Buffer_VMem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_Buffer_VMem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_Buffer_VMem);
}

//------------------------------------------------------------------------------
// Address: 0x1028B760
// Name: _dynamic_initializer_for__GSTAT_GStatRender_Counters__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_Counters__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_Counters);
}

//------------------------------------------------------------------------------
// Address: 0x1028B770
// Name: _dynamic_initializer_for__GSTAT_GStatRender_TextureUpload_Cnt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_TextureUpload_Cnt__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_TextureUpload_Cnt);
}

//------------------------------------------------------------------------------
// Address: 0x1028B780
// Name: _dynamic_initializer_for__GSTAT_GStatRender_TextureUpdate_Cnt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_TextureUpdate_Cnt__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_TextureUpdate_Cnt);
}

//------------------------------------------------------------------------------
// Address: 0x1028B790
// Name: _dynamic_initializer_for__GSTAT_GStatRender_DP_Cnt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_DP_Cnt__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_DP_Cnt);
}

//------------------------------------------------------------------------------
// Address: 0x1028B7A0
// Name: _dynamic_initializer_for__GSTAT_GStatRender_DP_Line_Cnt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_DP_Line_Cnt__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_DP_Line_Cnt);
}

//------------------------------------------------------------------------------
// Address: 0x1028B7B0
// Name: _dynamic_initializer_for__GSTAT_GStatRender_DP_Triangle_Cnt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_DP_Triangle_Cnt__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_DP_Triangle_Cnt);
}

//------------------------------------------------------------------------------
// Address: 0x1028B7C0
// Name: _dynamic_initializer_for__GSTAT_GStatRender_Triangle_Cnt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_Triangle_Cnt__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_Triangle_Cnt);
}

//------------------------------------------------------------------------------
// Address: 0x1028B7D0
// Name: _dynamic_initializer_for__GSTAT_GStatRender_Line_Cnt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_Line_Cnt__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_Line_Cnt);
}

//------------------------------------------------------------------------------
// Address: 0x1028B7E0
// Name: _dynamic_initializer_for__GSTAT_GStatRender_Mask_Cnt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_Mask_Cnt__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_Mask_Cnt);
}

//------------------------------------------------------------------------------
// Address: 0x1028B7F0
// Name: _dynamic_initializer_for__GSTAT_GStatRender_Filter_Cnt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRender_Filter_Cnt__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRender_Filter_Cnt);
}

//------------------------------------------------------------------------------
// Address: 0x1028B800
// Name: _dynamic_initializer_for__GSTAT_GStatGroup_Default__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStatGroup_Default__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStatGroup_Default);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStatGroup_Default;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStatGroup_Default;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStatGroup_Default;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B830
// Name: _dynamic_initializer_for__GSTAT_GStat_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B860
// Name: _dynamic_initializer_for__GSTAT_GStat_Default_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_Default_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_Default_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_Default_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_Default_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_Default_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B890
// Name: _dynamic_initializer_for__GSTAT_GStat_Image_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_Image_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_Image_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_Image_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_Image_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_Image_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B8C0
// Name: _dynamic_initializer_for__GSTAT_GStat_Sound_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_Sound_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_Sound_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_Sound_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_Sound_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_Sound_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B8F0
// Name: _dynamic_initializer_for__GSTAT_GStat_String_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_String_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_String_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_String_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_String_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_String_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B920
// Name: _dynamic_initializer_for__GSTAT_GStat_Video_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_Video_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_Video_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_Video_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_Video_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_Video_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B950
// Name: _dynamic_initializer_for__GSTAT_GStat_Debug_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_Debug_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_Debug_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_Debug_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_Debug_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_Debug_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B980
// Name: _dynamic_initializer_for__GSTAT_GStat_DebugHUD_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_DebugHUD_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_DebugHUD_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_DebugHUD_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_DebugHUD_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_DebugHUD_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B9B0
// Name: _dynamic_initializer_for__GSTAT_GStat_DebugTracker_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_DebugTracker_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_DebugTracker_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_DebugTracker_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_DebugTracker_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_DebugTracker_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028B9E0
// Name: _dynamic_initializer_for__GSTAT_GStat_StatBag_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GSTAT_GStat_StatBag_Mem__()
{
  int result; // eax

  GStatDescRegistry::RegisterDesc(this: GStatDescRegistryInstance, a2: &GSTAT_GStat_StatBag_Mem);
  result = GStats_pLastDesc;
  GStats_pLastDesc = (int)&GSTAT_GStat_StatBag_Mem;
  if ( result != 0 )
    *(_DWORD *)(result + 20) = &GSTAT_GStat_StatBag_Mem;
  else
    GStats_pFirstDesc = (int)&GSTAT_GStat_StatBag_Mem;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028BA10
// Name: _dynamic_initializer_for__GStat_MemoryInterface__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GStat_MemoryInterface__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__GStat_MemoryInterface__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BA20
// Name: _dynamic_initializer_for__GStat_TimerInterface__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GStat_TimerInterface__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__GStat_TimerInterface__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BA30
// Name: _dynamic_initializer_for__GStat_CounterInterface__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__GStat_CounterInterface__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__GStat_CounterInterface__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BA50
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BA60
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_CharDefs_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_CharDefs_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_CharDefs_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BA70
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_ShapeData_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_ShapeData_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_ShapeData_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BA80
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_Tags_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_Tags_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_Tags_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BA90
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_Fonts_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_Fonts_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_Fonts_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BAA0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_Images_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_Images_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_Images_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BAB0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_Sounds_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_Sounds_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_Sounds_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BAC0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_ActionOps_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_ActionOps_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_ActionOps_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BAD0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_Other_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_Other_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_Other_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BAE0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_Time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_Time__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_Time);
}

//------------------------------------------------------------------------------
// Address: 0x1028BAF0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_Load_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_Load_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_Load_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB00
// Name: _dynamic_initializer_for__GSTAT_GFxStatMD_Bind_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMD_Bind_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMD_Bind_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB10
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB20
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_MovieClip_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_MovieClip_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_MovieClip_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB30
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_ActionScript_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_ActionScript_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_ActionScript_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB40
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Text_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Text_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Text_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB50
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_XML_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_XML_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_XML_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB60
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Other_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Other_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Other_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB70
// Name: _dynamic_initializer_for__GSTAT_GFxStatIME_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatIME_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatIME_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB80
// Name: _dynamic_initializer_for__GSTAT_GFxStatFC_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatFC_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatFC_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BB90
// Name: _dynamic_initializer_for__GSTAT_GFxStatFC_Batch_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatFC_Batch_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatFC_Batch_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BBA0
// Name: _dynamic_initializer_for__GSTAT_GFxStatFC_GlyphCache_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatFC_GlyphCache_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatFC_GlyphCache_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BBB0
// Name: _dynamic_initializer_for__GSTAT_GFxStatFC_Other_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatFC_Other_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatFC_Other_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BBC0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BBD0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Advance_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Advance_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Advance_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BBE0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Action_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Action_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Action_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BBF0
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Timeline_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Timeline_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Timeline_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC00
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Input_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Input_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Input_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC10
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Mouse_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Mouse_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Mouse_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC20
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_ScriptCommunication_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_ScriptCommunication_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_ScriptCommunication_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC30
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_GetVariable_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_GetVariable_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_GetVariable_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC40
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_SetVariable_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_SetVariable_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_SetVariable_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC50
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Invoke_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Invoke_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Invoke_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC60
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Display_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Display_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Display_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC70
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_Tessellate_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_Tessellate_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_Tessellate_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC80
// Name: _dynamic_initializer_for__GSTAT_GFxStatMV_GradientGen_Tks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GFxStatMV_GradientGen_Tks__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GFxStatMV_GradientGen_Tks);
}

//------------------------------------------------------------------------------
// Address: 0x1028BDD0
// Name: _dynamic_initializer_for__GSTAT_GStatRG_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BDE0
// Name: _dynamic_initializer_for__GSTAT_GStatRG_Vertices_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_Vertices_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_Vertices_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BDF0
// Name: _dynamic_initializer_for__GSTAT_GStatRG_MeshFill_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_MeshFill_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_MeshFill_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BE00
// Name: _dynamic_initializer_for__GSTAT_GStatRG_MeshStroke_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_MeshStroke_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_MeshStroke_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BE10
// Name: _dynamic_initializer_for__GSTAT_GStatRG_Tessellator_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_Tessellator_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_Tessellator_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BE20
// Name: _dynamic_initializer_for__GSTAT_GStatRG_Rasterizer_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_Rasterizer_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_Rasterizer_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BE30
// Name: _dynamic_initializer_for__GSTAT_GStatRG_Stroker_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_Stroker_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_Stroker_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BE40
// Name: _dynamic_initializer_for__GSTAT_GStatRG_EdgeAA_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_EdgeAA_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_EdgeAA_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BE50
// Name: _dynamic_initializer_for__GSTAT_GStatRG_StrokerAA_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_StrokerAA_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_StrokerAA_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028BE60
// Name: _dynamic_initializer_for__GSTAT_GStatRG_Other_Mem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int __thiscall dynamic_initializer_for__GSTAT_GStatRG_Other_Mem__(void *this)
{
  return GStatDesc::RegisterDesc(pdesc: this, a2: (struct GStatDesc *)&GSTAT_GStatRG_Other_Mem);
}

//------------------------------------------------------------------------------
// Address: 0x1028CA50
// Name: _dynamic_atexit_destructor_for__GStat_MemoryInterface__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GStat_MemoryInterface__()
{
  GStat_MemoryInterface[0] = &GStatInfo::StatInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CA60
// Name: _dynamic_atexit_destructor_for__GStat_TimerInterface__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GStat_TimerInterface__()
{
  *(_DWORD *)GStat_TimerInterface = &GStatInfo::StatInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CA70
// Name: _dynamic_atexit_destructor_for__GStat_CounterInterface__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GStat_CounterInterface__()
{
  GStat_CounterInterface.m_Func = (void (__cdecl *)(void *))&GStatInfo::StatInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101DA428
// Name: public: class D3DXShader::CConstant __near * D3DXShader::CConstant::GetConstantMember(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CConstant *__thiscall D3DXShader::CConstant::GetConstantMember(
        D3DXShader::CConstant *this,
        unsigned int a2)
{
  if ( a2 < *(unsigned __int16 *)(*((_DWORD *)this + 6) + 10) )
    return *(struct D3DXShader::CConstant **)(*((_DWORD *)this + 14) + 4 * a2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DA449
// Name: public: long D3DXShader::CConstant::SetDefaults(void const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CConstant::SetDefaults(D3DXShader::CConstant *this, const void *a2, unsigned int a3)
{
  int v3; // edx
  int result; // eax

  v3 = *((_DWORD *)this + 5);
  if ( v3 == 0 )
    return 0;
  result = (*((int (__stdcall **)(const void *, unsigned int, unsigned int, _DWORD, _DWORD))this + 7))(
             a1: a2,
             a2: a3 + *((unsigned __int16 *)this + 5),
             a3: 4 * a3 * (*((_WORD *)this + 4) != 0 ? 4 : 1) + v3 + *(_DWORD *)(*(_DWORD *)this + 8),
             a4: *((_DWORD *)this + 8),
             a5: *((unsigned __int16 *)this + 6));
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DA495
// Name: public: virtual long D3DXShader::CConstantTable::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::QueryInterface(
        D3DXShader::CConstantTable *this,
        const struct _GUID *a2,
        void **a3)
{
  *a3 = nullptr;
  if ( memcmp(a2, &IID_IUnknown, 0x10u) != 0 && memcmp(a2, &IID_ID3DXConstantTable, 0x10u) != 0 )
    return -2147467262;
  *a3 = this;
  (*(void (__stdcall **)(D3DXShader::CConstantTable *))(*(_DWORD *)this + 4))(a1: this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DA4DE
// Name: public: virtual unsigned long D3DXShader::CConstantTable::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall D3DXShader::CConstantTable::AddRef(D3DXShader::CConstantTable *this)
{
  return ++*((_DWORD *)this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x101DA4F0
// Name: public: virtual void __near * D3DXCore::CBuffer::GetBufferPointer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__stdcall D3DXCore::CBuffer::GetBufferPointer(D3DXCore::CBuffer *this)
{
  return *((void **)this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x101DA560
// Name: public: virtual long D3DXShader::CConstantTable::SetDefaults(struct IDirect3DDevice9 __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::SetDefaults(D3DXShader::CConstantTable *this, struct IDirect3DDevice9 *a2)
{
  int v2; // edi
  int result; // eax

  v2 = 0;
  if ( *((_DWORD *)this + 6) == 0 )
    return 0;
  while ( 1 )
  {
    result = D3DXShader::CConstant::SetDefaults(
               this: *(D3DXShader::CConstant **)(*((_DWORD *)this + 5) + 4 * v2),
               a2,
               a3: 0);
    if ( result < 0 )
      break;
    if ( (unsigned int)++v2 >= *((_DWORD *)this + 6) )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DA593
// Name: public: static long D3DXShader::SetShaderConstant<1,1,2>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<1,1,2>::Set(int a1, int a2, int a3, int a4, int a5)
{
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 444))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA5B1
// Name: public: static long D3DXShader::SetShaderConstant<1,1,1>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<1,1,1>::Set(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // eax
  int v6; // esi

  if ( 4 * a5 != 0 )
  {
    v5 = a4;
    v6 = 4 * a5;
    do
    {
      *v5 = *(_DWORD *)((char *)v5 + a3 - (_DWORD)a4) != 0;
      ++v5;
      --v6;
    }
    while ( v6 != 0 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 444))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA5F5
// Name: public: static long D3DXShader::SetShaderConstant<1,1,3>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<1,1,3>::Set(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int v5; // edx
  _DWORD *v6; // eax

  v5 = 4 * a5;
  if ( 4 * a5 != 0 )
  {
    v6 = a4;
    do
    {
      *v6 = (int)*(float *)((char *)v6 + a3 - (_DWORD)a4);
      ++v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 444))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA65B
// Name: public: static long D3DXShader::SetShaderConstant<1,2,3>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<1,2,3>::Set(int a1, int a2, int a3, int a4, int a5)
{
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 436))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA679
// Name: public: static long D3DXShader::SetShaderConstant<1,2,1>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<1,2,1>::Set(int a1, int a2, int a3, float *a4, int a5)
{
  float *v5; // eax
  int v6; // esi

  if ( 4 * a5 != 0 )
  {
    v5 = a4;
    v6 = 4 * a5;
    do
    {
      *v5 = (float)(*(_DWORD *)((char *)v5 + a3 - (_DWORD)a4) != 0);
      ++v5;
      --v6;
    }
    while ( v6 != 0 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 436))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA6C3
// Name: public: static long D3DXShader::SetShaderConstant<1,2,2>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<1,2,2>::Set(int a1, int a2, int a3, float *a4, int a5)
{
  int v5; // edx
  float *v6; // eax

  v5 = 4 * a5;
  if ( 4 * a5 != 0 )
  {
    v6 = a4;
    do
    {
      *v6 = (float)*(int *)((char *)v6 + a3 - (_DWORD)a4);
      ++v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 436))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA6FE
// Name: public: static long D3DXShader::SetShaderConstant<2,2,3>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<2,2,3>::Set(int a1, int a2, const void *a3, int a4, int a5)
{
  qmemcpy(
    (void *)(16 * a2 + (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 12))(a1)),
    a3,
    4 * ((unsigned int)(16 * a5) >> 2));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DA73B
// Name: public: static long D3DXShader::SetShaderConstant<2,2,1>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<2,2,1>::Set(int a1, int a2, char *a3, float *a4, int a5)
{
  float *v5; // eax
  int v6; // esi

  if ( 4 * a5 != 0 )
  {
    v5 = a4;
    v6 = 4 * a5;
    do
    {
      *v5 = (float)(*(_DWORD *)((char *)v5 + a3 - (char *)a4) != 0);
      ++v5;
      --v6;
    }
    while ( v6 != 0 );
  }
  qmemcpy((void *)(16 * a2 + (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 12))(a1)), a3, 16 * a5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DA79F
// Name: public: static long D3DXShader::SetShaderConstant<2,2,2>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<2,2,2>::Set(int a1, int a2, char *a3, float *a4, int a5)
{
  int v5; // edx
  float *v6; // eax

  v5 = 4 * a5;
  if ( 4 * a5 != 0 )
  {
    v6 = a4;
    do
    {
      *v6 = (float)*(int *)((char *)v6 + a3 - (char *)a4);
      ++v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  qmemcpy((void *)(16 * a2 + (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 12))(a1)), a3, 16 * a5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DA816
// Name: public: D3DXShader::CConstantTable::~CConstantTable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CConstantTable::~CConstantTable(D3DXShader::CConstantTable *this)
{
  bool v2; // zf
  unsigned int i; // edi
  D3DXShader::CConstant *v4; // ecx

  v2 = *((_DWORD *)this + 5) == 0;
  *(_DWORD *)this = &D3DXShader::CConstantTable::`vftable';
  if ( !v2 )
  {
    for ( i = 0; i < *((_DWORD *)this + 6); ++i )
    {
      v4 = *(D3DXShader::CConstant **)(*((_DWORD *)this + 5) + 4 * i);
      if ( v4 != nullptr )
        D3DXShader::CConstant::`scalar deleting destructor'(this: v4, a2: 1);
    }
    free(pMem: *((void **)this + 5));
  }
  free(pMem: *((void **)this + 2));
  free(pMem: *((void **)this + 7));
}

//------------------------------------------------------------------------------
// Address: 0x101DA864
// Name: public: static long D3DXShader::SetShaderConstant<0,0,1>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<0,0,1>::Set(int a1, int a2, int a3, int a4, int a5)
{
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 392))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA882
// Name: public: static long D3DXShader::SetShaderConstant<0,0,2>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<0,0,2>::Set(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // eax
  int i; // esi

  if ( a5 != 0 )
  {
    v5 = a4;
    for ( i = a5; i != 0; --i )
    {
      *v5 = *(_DWORD *)((char *)v5 + a3 - (_DWORD)a4) != 0;
      ++v5;
    }
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 392))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA8C3
// Name: public: static long D3DXShader::SetShaderConstant<0,0,3>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<0,0,3>::Set(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ecx
  int i; // esi

  if ( a5 != 0 )
  {
    v5 = a4;
    for ( i = a5; i != 0; --i )
    {
      *v5 = *(float *)((char *)v5 + a3 - (_DWORD)a4) != 0.0;
      ++v5;
    }
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 392))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA915
// Name: public: static long D3DXShader::SetShaderConstant<0,1,1>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<0,1,1>::Set(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // eax
  int v6; // esi

  if ( 4 * a5 != 0 )
  {
    v5 = a4;
    v6 = 4 * a5;
    do
    {
      *v5 = *(_DWORD *)((char *)v5 + a3 - (_DWORD)a4) != 0;
      ++v5;
      --v6;
    }
    while ( v6 != 0 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 384))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA959
// Name: public: static long D3DXShader::SetShaderConstant<0,1,2>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<0,1,2>::Set(int a1, int a2, int a3, int a4, int a5)
{
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 384))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA977
// Name: public: static long D3DXShader::SetShaderConstant<0,1,3>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<0,1,3>::Set(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int v5; // edx
  _DWORD *v6; // eax

  v5 = 4 * a5;
  if ( 4 * a5 != 0 )
  {
    v6 = a4;
    do
    {
      *v6 = (int)*(float *)((char *)v6 + a3 - (_DWORD)a4);
      ++v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 384))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA9DD
// Name: public: static long D3DXShader::SetShaderConstant<0,2,1>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<0,2,1>::Set(int a1, int a2, int a3, float *a4, int a5)
{
  float *v5; // eax
  int v6; // esi

  if ( 4 * a5 != 0 )
  {
    v5 = a4;
    v6 = 4 * a5;
    do
    {
      *v5 = (float)(*(_DWORD *)((char *)v5 + a3 - (_DWORD)a4) != 0);
      ++v5;
      --v6;
    }
    while ( v6 != 0 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 376))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DAA27
// Name: public: static long D3DXShader::SetShaderConstant<0,2,2>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<0,2,2>::Set(int a1, int a2, int a3, float *a4, int a5)
{
  int v5; // edx
  float *v6; // eax

  v5 = 4 * a5;
  if ( 4 * a5 != 0 )
  {
    v6 = a4;
    do
    {
      *v6 = (float)*(int *)((char *)v6 + a3 - (_DWORD)a4);
      ++v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 376))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DAA62
// Name: public: static long D3DXShader::SetShaderConstant<0,2,3>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<0,2,3>::Set(int a1, int a2, int a3, int a4, int a5)
{
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 376))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DAA80
// Name: public: static long D3DXShader::SetShaderConstant<1,0,0>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<1,0,0>::Set(int a1, int a2, int a3, int a4, int a5)
{
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 452))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DAA9E
// Name: public: static long D3DXShader::SetShaderConstant<1,0,2>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<1,0,2>::Set(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // eax
  int i; // esi

  if ( a5 != 0 )
  {
    v5 = a4;
    for ( i = a5; i != 0; --i )
    {
      *v5 = *(_DWORD *)((char *)v5 + a3 - (_DWORD)a4) != 0;
      ++v5;
    }
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 452))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DAADF
// Name: public: static long D3DXShader::SetShaderConstant<1,0,3>::Set(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetShaderConstant<1,0,3>::Set(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ecx
  int i; // esi

  if ( a5 != 0 )
  {
    v5 = a4;
    for ( i = a5; i != 0; --i )
    {
      *v5 = *(float *)((char *)v5 + a3 - (_DWORD)a4) != 0.0;
      ++v5;
    }
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 452))(a1, a2, a3, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x101DAB31
// Name: public: static long D3DXShader::SetTyped<0,0,1,1,0>::Set(class D3DXShader::CConstant __near *,void const __near *,void const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetTyped<0,0,1,1,0>::Set(int a1, int a2, int a3, unsigned int a4, int a5)
{
  int v5; // edi
  _WORD *v6; // esi
  int result; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  _DWORD *i; // edx
  unsigned int k; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  bool v14; // cc
  __int16 v15; // cx
  unsigned int v16; // ebx
  int v17; // eax
  int v18; // eax
  unsigned int v19; // esi
  int v20; // ecx
  int v21; // edx
  _DWORD *v22; // ecx
  _DWORD *v23; // eax
  _DWORD *v24; // edx
  _DWORD *v25; // edx
  bool v26; // zf
  unsigned int v27; // eax
  int v28; // [esp+Ch] [ebp-14h]
  _DWORD *v29; // [esp+10h] [ebp-10h]
  unsigned int v30; // [esp+14h] [ebp-Ch]
  _DWORD *v31; // [esp+14h] [ebp-Ch]
  int v32; // [esp+18h] [ebp-8h]
  int v33; // [esp+1Ch] [ebp-4h]
  unsigned int j; // [esp+1Ch] [ebp-4h]
  unsigned int v35; // [esp+1Ch] [ebp-4h]
  int v36; // [esp+28h] [ebp+8h]
  int v37; // [esp+30h] [ebp+10h]
  int v38; // [esp+30h] [ebp+10h]
  unsigned int v39; // [esp+30h] [ebp+10h]
  _DWORD *v40; // [esp+30h] [ebp+10h]
  unsigned int v41; // [esp+34h] [ebp+14h]

  v5 = a1;
  v6 = *(_WORD **)(a1 + 24);
  v32 = *(_DWORD *)(a1 + 32);
  v33 = a3;
  switch ( *v6 )
  {
    case 0:
      v13 = (unsigned __int16)v6[4];
      v14 = a4 <= v13;
LABEL_28:
      if ( !v14 )
        a4 = v13;
LABEL_30:
      v15 = *(_WORD *)(a1 + 8);
      if ( v15 != 0 )
      {
        if ( *v6 == 3 )
        {
          v16 = (unsigned __int16)v6[2];
          v17 = (unsigned __int16)v6[3];
        }
        else
        {
          v16 = (unsigned __int16)v6[3];
          v17 = (unsigned __int16)v6[2];
        }
        if ( (v16 & 3) != 0 )
        {
          v29 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefInt4;
          if ( v15 != 1 )
            v29 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefFloat4;
          v18 = a4 * v17;
          v19 = (v16 + 3) & 0xFFFFFFFC;
          v38 = v18;
          if ( v18 != 0 )
          {
            v20 = 4 * v18 + 4;
            v21 = v19 * v20;
            v22 = (_DWORD *)(v33 + v16 * v20);
            v31 = (_DWORD *)(v32 + v21);
            v23 = (_DWORD *)(v32 + 4 * (v16 + v19 * v18));
            v28 = v38;
            do
            {
              v31 -= v19;
              v23 -= v19;
              v22 -= v16;
              v39 = (v16 + 3) & 0xFFFFFFFC;
              if ( v19 > v16 )
              {
                v24 = v31;
                do
                  *--v24 = v29[--v39 & 3];
                while ( v39 > v16 );
              }
              if ( v16 != 0 )
              {
                v25 = v23;
                v40 = v22;
                v35 = v16;
                do
                {
                  --v40;
                  --v25;
                  v26 = v35-- == 1;
                  *v25 = *v40;
                }
                while ( !v26 );
              }
              --v28;
            }
            while ( v28 != 0 );
            v5 = a1;
          }
          v33 = v32;
        }
      }
      v27 = a4 * *(_DWORD *)(v5 + 44);
      if ( v27 > *(unsigned __int16 *)(v5 + 12) )
        v27 = *(unsigned __int16 *)(v5 + 12);
      result = (*(int (__stdcall **)(int, int, int, int, unsigned int))(v5 + 28))(
                 a1: a2,
                 a2: a5 + *(unsigned __int16 *)(v5 + 10),
                 a3: v33,
                 a4: v32,
                 a5: v27);
      if ( result < 0 )
        return result;
      return 0;
    case 1:
      v12 = (unsigned __int16)v6[3];
      goto LABEL_26;
    case 2:
      v12 = (unsigned __int16)v6[2] * (unsigned __int16)v6[3];
LABEL_26:
      a4 /= v12;
      v13 = (unsigned __int16)v6[4];
      v14 = a4 <= v13;
      goto LABEL_28;
    case 3:
      v9 = (unsigned __int16)v6[2];
      a4 /= (unsigned __int16)v6[3] * v9;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v30 = 0;
      for ( i = *(_DWORD **)(a1 + 32); v30 < a4; ++v30 )
      {
        for ( j = 0; j < (unsigned __int16)v6[3]; ++j )
        {
          for ( k = 0; k < v9; ++k )
          {
            *i = *(_DWORD *)(a3 + 4 * (j + (unsigned __int16)v6[3] * (k + v30 * v9)));
            v9 = (unsigned __int16)v6[2];
            ++i;
          }
        }
      }
      v33 = v32;
      goto LABEL_30;
    default:
      break;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v41 = a4 / *(_DWORD *)(a1 + 52);
  if ( v41 > (unsigned __int16)v6[4] )
    v41 = (unsigned __int16)v6[4];
  v36 = 0;
  if ( v41 == 0 )
    return 0;
  while ( 1 )
  {
    v37 = 0;
    if ( v6[5] != 0 )
      break;
LABEL_13:
    if ( ++v36 >= v41 )
      return 0;
  }
  while ( 1 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 4 * v37);
    result = D3DXShader::SetTyped<0,0,1,1,0>::Set(a1: v5, a2, a3: v33, a4: *(_DWORD *)(v8 + 48), a5);
    if ( result < 0 )
      return result;
    v33 += 4 * *(_DWORD *)(v8 + 48);
    a5 += *(_DWORD *)(v8 + 40);
    if ( ++v37 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DADD0
// Name: public: static long D3DXShader::SetTyped<0,1,1,1,0>::Set(class D3DXShader::CConstant __near *,void const __near *,void const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetTyped<0,1,1,1,0>::Set(int a1, int a2, float *a3, unsigned int a4, int a5)
{
  int v5; // edi
  _WORD *v6; // esi
  int result; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  _DWORD *i; // edx
  unsigned int k; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  bool v14; // cc
  unsigned __int16 v15; // cx
  int v16; // eax
  int v17; // ecx
  int v18; // ecx
  float *v19; // ecx
  double v20; // st7
  float *v21; // ecx
  __int16 v22; // cx
  unsigned int v23; // ebx
  int v24; // eax
  int v25; // eax
  unsigned int v26; // esi
  int v27; // ecx
  int v28; // edx
  float *v29; // ecx
  float *v30; // eax
  _DWORD *v31; // edx
  float *v32; // edx
  bool v33; // zf
  unsigned int v34; // eax
  int v35; // [esp+Ch] [ebp-14h]
  _DWORD *v36; // [esp+10h] [ebp-10h]
  unsigned int v37; // [esp+14h] [ebp-Ch]
  _DWORD *v38; // [esp+14h] [ebp-Ch]
  float *v39; // [esp+18h] [ebp-8h]
  float *v40; // [esp+1Ch] [ebp-4h]
  unsigned int j; // [esp+1Ch] [ebp-4h]
  unsigned int v42; // [esp+1Ch] [ebp-4h]
  int v43; // [esp+28h] [ebp+8h]
  int v44; // [esp+30h] [ebp+10h]
  int v45; // [esp+30h] [ebp+10h]
  unsigned int v46; // [esp+30h] [ebp+10h]
  float *v47; // [esp+30h] [ebp+10h]
  unsigned int v48; // [esp+34h] [ebp+14h]

  v5 = a1;
  v6 = *(_WORD **)(a1 + 24);
  v39 = *(float **)(a1 + 32);
  v40 = a3;
  switch ( *v6 )
  {
    case 0:
      v13 = (unsigned __int16)v6[4];
      v14 = a4 <= v13;
LABEL_28:
      if ( !v14 )
        a4 = v13;
LABEL_30:
      v15 = v6[1];
      if ( v15 != 1 )
      {
        v16 = a4 * *(_DWORD *)(a1 + 52);
        v17 = v15 - 1;
        if ( v17 != 0 )
        {
          v18 = v17 - 1;
          if ( v18 != 0 )
          {
            if ( v18 == 1 && v16 != 0 )
            {
              v19 = v39;
              do
              {
                if ( *(_DWORD *)((char *)v19 + (char *)v40 - (char *)v39) != 0 )
                  v20 = 1.0;
                else
                  v20 = 0.0;
                *v19++ = v20;
                --v16;
              }
              while ( v16 != 0 );
            }
          }
          else if ( v16 != 0 )
          {
            v21 = v39;
            do
            {
              *(_DWORD *)v21 = *(_DWORD *)((char *)v21 + (char *)v40 - (char *)v39) != 0;
              ++v21;
              --v16;
            }
            while ( v16 != 0 );
          }
        }
        v40 = v39;
      }
      v22 = *(_WORD *)(a1 + 8);
      if ( v22 != 0 )
      {
        if ( *v6 == 3 )
        {
          v23 = (unsigned __int16)v6[2];
          v24 = (unsigned __int16)v6[3];
        }
        else
        {
          v23 = (unsigned __int16)v6[3];
          v24 = (unsigned __int16)v6[2];
        }
        if ( (v23 & 3) != 0 )
        {
          v36 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefInt4;
          if ( v22 != 1 )
            v36 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefFloat4;
          v25 = a4 * v24;
          v26 = (v23 + 3) & 0xFFFFFFFC;
          v45 = v25;
          if ( v25 != 0 )
          {
            v27 = 4 * v25 + 4;
            v28 = v26 * v27;
            v29 = (float *)((char *)v40 + v23 * v27);
            v38 = (_DWORD *)((char *)v39 + v28);
            v30 = &v39[v23 + v26 * v25];
            v35 = v45;
            do
            {
              v38 -= v26;
              v30 -= v26;
              v29 -= v23;
              v46 = (v23 + 3) & 0xFFFFFFFC;
              if ( v26 > v23 )
              {
                v31 = v38;
                do
                  *--v31 = v36[--v46 & 3];
                while ( v46 > v23 );
              }
              if ( v23 != 0 )
              {
                v32 = v30;
                v47 = v29;
                v42 = v23;
                do
                {
                  --v47;
                  --v32;
                  v33 = v42-- == 1;
                  *v32 = *v47;
                }
                while ( !v33 );
              }
              --v35;
            }
            while ( v35 != 0 );
            v5 = a1;
          }
          v40 = v39;
        }
      }
      v34 = a4 * *(_DWORD *)(v5 + 44);
      if ( v34 > *(unsigned __int16 *)(v5 + 12) )
        v34 = *(unsigned __int16 *)(v5 + 12);
      result = (*(int (__stdcall **)(int, int, float *, float *, unsigned int))(v5 + 28))(
                 a1: a2,
                 a2: a5 + *(unsigned __int16 *)(v5 + 10),
                 a3: v40,
                 a4: v39,
                 a5: v34);
      if ( result < 0 )
        return result;
      return 0;
    case 1:
      v12 = (unsigned __int16)v6[3];
      goto LABEL_26;
    case 2:
      v12 = (unsigned __int16)v6[2] * (unsigned __int16)v6[3];
LABEL_26:
      a4 /= v12;
      v13 = (unsigned __int16)v6[4];
      v14 = a4 <= v13;
      goto LABEL_28;
    case 3:
      v9 = (unsigned __int16)v6[2];
      a4 /= (unsigned __int16)v6[3] * v9;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v37 = 0;
      for ( i = *(_DWORD **)(a1 + 32); v37 < a4; ++v37 )
      {
        for ( j = 0; j < (unsigned __int16)v6[3]; ++j )
        {
          for ( k = 0; k < v9; ++k )
          {
            *i = LODWORD(a3[j + (unsigned __int16)v6[3] * (k + v37 * v9)]);
            v9 = (unsigned __int16)v6[2];
            ++i;
          }
        }
      }
      v40 = v39;
      goto LABEL_30;
    default:
      break;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v48 = a4 / *(_DWORD *)(a1 + 52);
  if ( v48 > (unsigned __int16)v6[4] )
    v48 = (unsigned __int16)v6[4];
  v43 = 0;
  if ( v48 == 0 )
    return 0;
  while ( 1 )
  {
    v44 = 0;
    if ( v6[5] != 0 )
      break;
LABEL_13:
    if ( ++v43 >= v48 )
      return 0;
  }
  while ( 1 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 4 * v44);
    result = D3DXShader::SetTyped<0,1,1,1,0>::Set(a1: v5, a2, a3: v40, a4: *(_DWORD *)(v8 + 48), a5);
    if ( result < 0 )
      return result;
    v40 += *(_DWORD *)(v8 + 48);
    a5 += *(_DWORD *)(v8 + 40);
    if ( ++v44 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB0D2
// Name: public: static long D3DXShader::SetTyped<0,2,1,1,0>::Set(class D3DXShader::CConstant __near *,void const __near *,void const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetTyped<0,2,1,1,0>::Set(int a1, int a2, float *a3, unsigned int a4, int a5)
{
  int v5; // edi
  _WORD *v6; // esi
  float *v7; // ebx
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _DWORD *i; // edx
  unsigned int k; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  bool v15; // cc
  unsigned __int16 v16; // cx
  int v17; // eax
  int v18; // ecx
  float *v19; // ecx
  float *v20; // ecx
  __int16 v21; // cx
  unsigned int v22; // ebx
  int v23; // eax
  int v24; // eax
  unsigned int v25; // esi
  int v26; // ecx
  int v27; // edx
  float *v28; // ecx
  float *v29; // eax
  _DWORD *v30; // edx
  float *v31; // edx
  bool v32; // zf
  unsigned int v33; // eax
  int v34; // [esp+Ch] [ebp-14h]
  _DWORD *v35; // [esp+10h] [ebp-10h]
  unsigned int v36; // [esp+14h] [ebp-Ch]
  _DWORD *v37; // [esp+14h] [ebp-Ch]
  float *v38; // [esp+18h] [ebp-8h]
  float *v39; // [esp+1Ch] [ebp-4h]
  unsigned int j; // [esp+1Ch] [ebp-4h]
  unsigned int v41; // [esp+1Ch] [ebp-4h]
  int v42; // [esp+28h] [ebp+8h]
  int v43; // [esp+30h] [ebp+10h]
  int v44; // [esp+30h] [ebp+10h]
  unsigned int v45; // [esp+30h] [ebp+10h]
  float *v46; // [esp+30h] [ebp+10h]
  unsigned int v47; // [esp+34h] [ebp+14h]

  v5 = a1;
  v6 = *(_WORD **)(a1 + 24);
  v7 = *(float **)(a1 + 32);
  v39 = a3;
  v38 = v7;
  switch ( *v6 )
  {
    case 0:
      v14 = (unsigned __int16)v6[4];
      v15 = a4 <= v14;
LABEL_28:
      if ( !v15 )
        a4 = v14;
LABEL_30:
      v16 = v6[1];
      if ( v16 != 2 )
      {
        v17 = a4 * *(_DWORD *)(a1 + 52);
        v18 = v16 - 1;
        if ( v18 != 0 )
        {
          if ( v18 == 2 && v17 != 0 )
          {
            v19 = v7;
            do
            {
              *v19 = (float)*(int *)((char *)v19 + (char *)v39 - (char *)v7);
              ++v19;
              --v17;
            }
            while ( v17 != 0 );
          }
        }
        else if ( v17 != 0 )
        {
          v20 = v7;
          do
          {
            *(_DWORD *)v20 = *(_DWORD *)((char *)v20 + (char *)v39 - (char *)v7) != 0;
            ++v20;
            --v17;
          }
          while ( v17 != 0 );
        }
        v39 = v7;
      }
      v21 = *(_WORD *)(a1 + 8);
      if ( v21 != 0 )
      {
        if ( *v6 == 3 )
        {
          v22 = (unsigned __int16)v6[2];
          v23 = (unsigned __int16)v6[3];
        }
        else
        {
          v22 = (unsigned __int16)v6[3];
          v23 = (unsigned __int16)v6[2];
        }
        if ( (v22 & 3) != 0 )
        {
          v35 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefInt4;
          if ( v21 != 1 )
            v35 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefFloat4;
          v24 = a4 * v23;
          v25 = (v22 + 3) & 0xFFFFFFFC;
          v44 = v24;
          if ( v24 != 0 )
          {
            v26 = 4 * v24 + 4;
            v27 = v25 * v26;
            v28 = (float *)((char *)v39 + v22 * v26);
            v37 = (_DWORD *)((char *)v38 + v27);
            v29 = &v38[v22 + v25 * v24];
            v34 = v44;
            do
            {
              v37 -= v25;
              v29 -= v25;
              v28 -= v22;
              v45 = (v22 + 3) & 0xFFFFFFFC;
              if ( v25 > v22 )
              {
                v30 = v37;
                do
                  *--v30 = v35[--v45 & 3];
                while ( v45 > v22 );
              }
              if ( v22 != 0 )
              {
                v31 = v29;
                v46 = v28;
                v41 = v22;
                do
                {
                  --v46;
                  --v31;
                  v32 = v41-- == 1;
                  *v31 = *v46;
                }
                while ( !v32 );
              }
              --v34;
            }
            while ( v34 != 0 );
            v5 = a1;
          }
          v39 = v38;
        }
      }
      v33 = a4 * *(_DWORD *)(v5 + 44);
      if ( v33 > *(unsigned __int16 *)(v5 + 12) )
        v33 = *(unsigned __int16 *)(v5 + 12);
      result = (*(int (__stdcall **)(int, int, float *, float *, unsigned int))(v5 + 28))(
                 a1: a2,
                 a2: a5 + *(unsigned __int16 *)(v5 + 10),
                 a3: v39,
                 a4: v38,
                 a5: v33);
      if ( result < 0 )
        return result;
      return 0;
    case 1:
      v13 = (unsigned __int16)v6[3];
      goto LABEL_26;
    case 2:
      v13 = (unsigned __int16)v6[2] * (unsigned __int16)v6[3];
LABEL_26:
      a4 /= v13;
      v14 = (unsigned __int16)v6[4];
      v15 = a4 <= v14;
      goto LABEL_28;
    case 3:
      v10 = (unsigned __int16)v6[2];
      a4 /= (unsigned __int16)v6[3] * v10;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v36 = 0;
      for ( i = *(_DWORD **)(a1 + 32); v36 < a4; ++v36 )
      {
        for ( j = 0; j < (unsigned __int16)v6[3]; ++j )
        {
          for ( k = 0; k < v10; ++k )
          {
            *i = LODWORD(a3[j + (unsigned __int16)v6[3] * (k + v36 * v10)]);
            v10 = (unsigned __int16)v6[2];
            ++i;
          }
        }
      }
      v39 = v7;
      goto LABEL_30;
    default:
      break;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v47 = a4 / *(_DWORD *)(a1 + 52);
  if ( v47 > (unsigned __int16)v6[4] )
    v47 = (unsigned __int16)v6[4];
  v42 = 0;
  if ( v47 == 0 )
    return 0;
  while ( 1 )
  {
    v43 = 0;
    if ( v6[5] != 0 )
      break;
LABEL_13:
    if ( ++v42 >= v47 )
      return 0;
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 4 * v43);
    result = D3DXShader::SetTyped<0,2,1,1,0>::Set(a1: v5, a2, a3: v39, a4: *(_DWORD *)(v9 + 48), a5);
    if ( result < 0 )
      return result;
    v39 += *(_DWORD *)(v9 + 48);
    a5 += *(_DWORD *)(v9 + 40);
    if ( ++v43 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB3C8
// Name: public: static long D3DXShader::SetTyped<0,3,1,1,0>::Set(class D3DXShader::CConstant __near *,void const __near *,void const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetTyped<0,3,1,1,0>::Set(int a1, int a2, char *a3, unsigned int a4, int a5)
{
  int v5; // ebx
  _WORD *v6; // esi
  int result; // eax
  int v8; // edi
  unsigned int v9; // ecx
  _DWORD *i; // edx
  unsigned int k; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  bool v14; // cc
  unsigned __int16 v15; // ax
  int v16; // ecx
  int v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // edx
  __int16 v20; // ax
  unsigned int v21; // edx
  int v22; // edi
  int v23; // edi
  unsigned int v24; // esi
  int v25; // eax
  int v26; // ecx
  char *v27; // eax
  _DWORD *v28; // edi
  _DWORD *v29; // ecx
  _DWORD *v30; // ecx
  bool v31; // zf
  unsigned int v32; // eax
  int v33; // [esp+Ch] [ebp-14h]
  _DWORD *v34; // [esp+10h] [ebp-10h]
  unsigned int v35; // [esp+14h] [ebp-Ch]
  _DWORD *v36; // [esp+14h] [ebp-Ch]
  _DWORD *v37; // [esp+18h] [ebp-8h]
  char *v38; // [esp+1Ch] [ebp-4h]
  unsigned int j; // [esp+1Ch] [ebp-4h]
  unsigned int v40; // [esp+1Ch] [ebp-4h]
  int v41; // [esp+28h] [ebp+8h]
  int v42; // [esp+30h] [ebp+10h]
  int v43; // [esp+30h] [ebp+10h]
  unsigned int v44; // [esp+30h] [ebp+10h]
  char *v45; // [esp+30h] [ebp+10h]
  unsigned int v46; // [esp+34h] [ebp+14h]

  v5 = a1;
  v37 = *(_DWORD **)(a1 + 32);
  v6 = *(_WORD **)(a1 + 24);
  v38 = a3;
  switch ( *v6 )
  {
    case 0:
      v13 = (unsigned __int16)v6[4];
      v14 = a4 <= v13;
LABEL_28:
      if ( !v14 )
        a4 = v13;
LABEL_30:
      v15 = v6[1];
      if ( v15 != 3 )
      {
        v16 = a4 * *(_DWORD *)(a1 + 52);
        v17 = v15 - 1;
        if ( v17 != 0 )
        {
          if ( v17 == 1 && v16 != 0 )
          {
            v18 = v37;
            do
            {
              *v18 = (int)*(float *)((char *)v18 + v38 - (char *)v37);
              ++v18;
              --v16;
            }
            while ( v16 != 0 );
          }
        }
        else if ( v16 != 0 )
        {
          v19 = v37;
          do
          {
            *v19 = *(float *)((char *)v19 + v38 - (char *)v37) != 0.0;
            ++v19;
            --v16;
          }
          while ( v16 != 0 );
        }
        v38 = (char *)v37;
      }
      v20 = *(_WORD *)(a1 + 8);
      if ( v20 != 0 )
      {
        if ( *v6 == 3 )
        {
          v21 = (unsigned __int16)v6[2];
          v22 = (unsigned __int16)v6[3];
        }
        else
        {
          v21 = (unsigned __int16)v6[3];
          v22 = (unsigned __int16)v6[2];
        }
        if ( (v21 & 3) != 0 )
        {
          v34 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefInt4;
          if ( v20 != 1 )
            v34 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefFloat4;
          v23 = a4 * v22;
          v24 = (v21 + 3) & 0xFFFFFFFC;
          v43 = v23;
          if ( v23 != 0 )
          {
            v25 = 4 * v23 + 4;
            v26 = v24 * v25;
            v27 = &v38[v21 * v25];
            v36 = (_DWORD *)((char *)v37 + v26);
            v28 = &v37[v21 + v24 * v23];
            v33 = v43;
            do
            {
              v36 -= v24;
              v28 -= v24;
              v27 -= 4 * v21;
              v44 = (v21 + 3) & 0xFFFFFFFC;
              if ( v24 > v21 )
              {
                v29 = v36;
                do
                  *--v29 = v34[--v44 & 3];
                while ( v44 > v21 );
              }
              if ( v21 != 0 )
              {
                v30 = v28;
                v45 = v27;
                v40 = v21;
                do
                {
                  v45 -= 4;
                  --v30;
                  v31 = v40-- == 1;
                  *v30 = *(_DWORD *)v45;
                }
                while ( !v31 );
              }
              --v33;
            }
            while ( v33 != 0 );
            v5 = a1;
          }
          v38 = (char *)v37;
        }
      }
      v32 = a4 * *(_DWORD *)(v5 + 44);
      if ( v32 > *(unsigned __int16 *)(v5 + 12) )
        v32 = *(unsigned __int16 *)(v5 + 12);
      result = (*(int (__stdcall **)(int, int, char *, _DWORD *, unsigned int))(v5 + 28))(
                 a1: a2,
                 a2: a5 + *(unsigned __int16 *)(v5 + 10),
                 a3: v38,
                 a4: v37,
                 a5: v32);
      if ( result < 0 )
        return result;
      return 0;
    case 1:
      v12 = (unsigned __int16)v6[3];
      goto LABEL_26;
    case 2:
      v12 = (unsigned __int16)v6[2] * (unsigned __int16)v6[3];
LABEL_26:
      a4 /= v12;
      v13 = (unsigned __int16)v6[4];
      v14 = a4 <= v13;
      goto LABEL_28;
    case 3:
      v9 = (unsigned __int16)v6[2];
      a4 /= (unsigned __int16)v6[3] * v9;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v35 = 0;
      for ( i = *(_DWORD **)(a1 + 32); v35 < a4; ++v35 )
      {
        for ( j = 0; j < (unsigned __int16)v6[3]; ++j )
        {
          for ( k = 0; k < v9; ++k )
          {
            *i = *(_DWORD *)&a3[4 * j + 4 * (unsigned __int16)v6[3] * (k + v35 * v9)];
            v9 = (unsigned __int16)v6[2];
            ++i;
          }
        }
      }
      v38 = (char *)v37;
      goto LABEL_30;
    default:
      break;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v46 = a4 / *(_DWORD *)(a1 + 52);
  if ( v46 > (unsigned __int16)v6[4] )
    v46 = (unsigned __int16)v6[4];
  v41 = 0;
  if ( v46 == 0 )
    return 0;
  while ( 1 )
  {
    v42 = 0;
    if ( v6[5] != 0 )
      break;
LABEL_13:
    if ( ++v41 >= v46 )
      return 0;
  }
  while ( 1 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 4 * v42);
    result = D3DXShader::SetTyped<0,3,1,1,0>::Set(a1: v5, a2, a3: v38, a4: *(_DWORD *)(v8 + 48), a5);
    if ( result < 0 )
      return result;
    v38 += 4 * *(_DWORD *)(v8 + 48);
    a5 += *(_DWORD *)(v8 + 40);
    if ( ++v42 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB6F9
// Name: public: static long D3DXShader::SetTyped<1,3,1,4,0>::Set(class D3DXShader::CConstant __near *,void const __near *,void const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetTyped<1,3,1,4,0>::Set(int a1, int a2, char *a3, unsigned int a4, int a5)
{
  _DWORD *v5; // ebx
  _WORD *v6; // esi
  int result; // eax
  int v8; // ebx
  int v9; // edi
  unsigned int v10; // ecx
  _DWORD *k; // edi
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int m; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  unsigned __int16 v17; // dx
  _DWORD *v18; // edi
  unsigned int v19; // ebx
  int v20; // eax
  unsigned int v21; // ecx
  int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // edi
  _DWORD *v25; // edx
  unsigned int i; // ecx
  int v27; // eax
  unsigned __int16 v28; // ax
  int v29; // ecx
  int v30; // eax
  _DWORD *v31; // eax
  _DWORD *v32; // edx
  __int16 v33; // ax
  unsigned int v34; // edx
  int v35; // edi
  int v36; // edi
  unsigned int v37; // esi
  char *v38; // eax
  _DWORD *v39; // ecx
  _DWORD *v40; // edi
  bool v41; // zf
  unsigned int v42; // eax
  int j; // [esp+Ch] [ebp-14h]
  _DWORD *v44; // [esp+10h] [ebp-10h]
  _DWORD *v45; // [esp+14h] [ebp-Ch]
  _DWORD *v46; // [esp+18h] [ebp-8h]
  char *v47; // [esp+1Ch] [ebp-4h]
  unsigned int v48; // [esp+1Ch] [ebp-4h]
  unsigned int v49; // [esp+1Ch] [ebp-4h]
  _DWORD *v50; // [esp+1Ch] [ebp-4h]
  unsigned int v51; // [esp+1Ch] [ebp-4h]
  int v52; // [esp+30h] [ebp+10h]
  unsigned int v53; // [esp+30h] [ebp+10h]
  char *v54; // [esp+30h] [ebp+10h]
  unsigned int v55; // [esp+34h] [ebp+14h]

  v5 = *(_DWORD **)(a1 + 32);
  v6 = *(_WORD **)(a1 + 24);
  v47 = a3;
  v46 = v5;
  switch ( *v6 )
  {
    case 0:
      a4 *= 4;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      goto LABEL_56;
    case 1:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      LOWORD(v23) = v6[3];
      if ( (_WORD)v23 != 4 )
      {
        v24 = 0;
        v25 = *(_DWORD **)(a1 + 32);
        if ( a4 != 0 )
        {
          v23 = (unsigned __int16)v23;
          do
          {
            for ( i = 0; i < v23; ++i )
            {
              if ( i <= 4 )
              {
                v27 = *(_DWORD *)&a3[16 * v24 + 4 * i];
                v5 = v46;
              }
              else
              {
                v27 = 0;
              }
              *v25 = v27;
              v23 = (unsigned __int16)v6[3];
              ++v25;
            }
            ++v24;
          }
          while ( v24 < a4 );
        }
        goto LABEL_27;
      }
      goto LABEL_56;
    case 2:
      v16 = (unsigned __int16)v6[2];
      a4 /= v16;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v17 = v6[3];
      if ( v17 != 4 )
      {
        v49 = 0;
        v18 = *(_DWORD **)(a1 + 32);
        if ( a4 != 0 )
        {
          do
          {
            v19 = 0;
            if ( v16 != 0 )
            {
              v20 = v17;
              do
              {
                v21 = 0;
                if ( v20 != 0 )
                {
                  do
                  {
                    if ( v21 <= 4 )
                      v22 = *(_DWORD *)&a3[16 * v19 + 16 * v49 * (unsigned __int16)v6[2] + 4 * v21];
                    else
                      v22 = 0;
                    *v18 = v22;
                    v17 = v6[3];
                    ++v18;
                    v20 = v17;
                    ++v21;
                  }
                  while ( v21 < v17 );
                }
                v16 = (unsigned __int16)v6[2];
                ++v19;
              }
              while ( v19 < v16 );
            }
            ++v49;
          }
          while ( v49 < a4 );
          v5 = v46;
        }
        goto LABEL_27;
      }
LABEL_56:
      v28 = v6[1];
      if ( v28 != 3 )
      {
        v29 = a4 * *(_DWORD *)(a1 + 52);
        v30 = v28 - 1;
        if ( v30 != 0 )
        {
          if ( v30 == 1 && v29 != 0 )
          {
            v31 = v5;
            do
            {
              *v31 = (int)*(float *)((char *)v31 + v47 - (char *)v5);
              ++v31;
              --v29;
            }
            while ( v29 != 0 );
          }
        }
        else if ( v29 != 0 )
        {
          v32 = v5;
          do
          {
            *v32 = *(float *)((char *)v32 + v47 - (char *)v5) != 0.0;
            ++v32;
            --v29;
          }
          while ( v29 != 0 );
        }
        v47 = (char *)v5;
      }
      v33 = *(_WORD *)(a1 + 8);
      if ( v33 != 0 )
      {
        if ( *v6 == 3 )
        {
          v34 = (unsigned __int16)v6[2];
          v35 = (unsigned __int16)v6[3];
        }
        else
        {
          v34 = (unsigned __int16)v6[3];
          v35 = (unsigned __int16)v6[2];
        }
        if ( (v34 & 3) != 0 )
        {
          v44 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefInt4;
          if ( v33 != 1 )
            v44 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefFloat4;
          v36 = a4 * v35;
          v37 = (v34 + 3) & 0xFFFFFFFC;
          if ( v36 != 0 )
          {
            v38 = &v47[(4 * v36 + 4) * v34];
            v45 = &v5[v34 + v37 * v36];
            v39 = (_DWORD *)((char *)v46 + (4 * v36 + 4) * v37);
            for ( j = v36; j != 0; --j )
            {
              v45 -= v37;
              v39 -= v37;
              v38 -= 4 * v34;
              v53 = (v34 + 3) & 0xFFFFFFFC;
              if ( v37 > v34 )
              {
                v50 = v39;
                do
                  *--v50 = v44[--v53 & 3];
                while ( v53 > v34 );
              }
              if ( v34 != 0 )
              {
                v40 = v45;
                v54 = v38;
                v51 = v34;
                do
                {
                  v54 -= 4;
                  --v40;
                  v41 = v51-- == 1;
                  *v40 = *(_DWORD *)v54;
                }
                while ( !v41 );
              }
            }
            v5 = v46;
          }
          v47 = (char *)v5;
        }
      }
      v42 = a4 * *(_DWORD *)(a1 + 44);
      if ( v42 > *(unsigned __int16 *)(a1 + 12) )
        v42 = *(unsigned __int16 *)(a1 + 12);
      result = (*(int (__stdcall **)(int, int, char *, _DWORD *, unsigned int))(a1 + 28))(
                 a1: a2,
                 a2: a5 + *(unsigned __int16 *)(a1 + 10),
                 a3: v47,
                 a4: v5,
                 a5: v42);
      if ( result < 0 )
        return result;
      return 0;
    case 3:
      v10 = (unsigned __int16)v6[3];
      a4 /= v10;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v48 = 0;
      for ( k = *(_DWORD **)(a1 + 32); v48 < a4; ++v48 )
      {
        v12 = 0;
        if ( v10 != 0 )
        {
          v13 = (unsigned __int16)v6[2];
          do
          {
            for ( m = 0; m < v13; ++m )
            {
              if ( v12 <= 4 )
              {
                v15 = *(_DWORD *)&a3[16 * m + 16 * v48 * v13 + 4 * v12];
                v5 = v46;
              }
              else
              {
                v15 = 0;
              }
              *k = v15;
              v13 = (unsigned __int16)v6[2];
              ++k;
            }
            v10 = (unsigned __int16)v6[3];
            ++v12;
          }
          while ( v12 < v10 );
        }
      }
LABEL_27:
      v47 = (char *)v5;
      goto LABEL_56;
    default:
      break;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v55 = 4 * a4 / *(_DWORD *)(a1 + 52);
  if ( v55 > (unsigned __int16)v6[4] )
    v55 = (unsigned __int16)v6[4];
  v52 = 0;
  if ( v55 == 0 )
    return 0;
  while ( 1 )
  {
    v8 = 0;
    if ( v6[5] != 0 )
      break;
LABEL_13:
    if ( ++v52 >= v55 )
      return 0;
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 4 * v8);
    result = D3DXShader::SetTyped<0,3,1,1,0>::Set(a1, a2, a3: v47, a4: *(_DWORD *)(v9 + 48), a5);
    if ( result < 0 )
      return result;
    v47 += 4 * *(_DWORD *)(v9 + 48);
    a5 += *(_DWORD *)(v9 + 40);
    if ( ++v8 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBAE6
// Name: public: static long D3DXShader::SetTyped<2,3,4,4,0>::Set(class D3DXShader::CConstant __near *,void const __near *,void const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetTyped<2,3,4,4,0>::Set(int a1, int a2, int a3, unsigned int a4, int a5)
{
  char *v5; // ebx
  _WORD *v6; // esi
  _DWORD *v7; // edi
  int result; // eax
  int v9; // ebx
  int v10; // edi
  unsigned __int16 v11; // dx
  _DWORD *v12; // ecx
  float *v13; // eax
  unsigned int n; // edi
  unsigned int ii; // ebx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  unsigned __int16 v19; // cx
  _DWORD *j; // edi
  unsigned int v21; // edx
  unsigned int v22; // eax
  unsigned int k; // ecx
  int v24; // eax
  unsigned int v25; // eax
  _DWORD *v26; // edx
  unsigned int v27; // edi
  unsigned int i; // ecx
  int v29; // eax
  unsigned __int16 v30; // ax
  int v31; // ecx
  int v32; // eax
  _DWORD *v33; // eax
  _DWORD *v34; // edx
  __int16 v35; // ax
  unsigned int v36; // edx
  int v37; // edi
  int v38; // edi
  unsigned int v39; // esi
  int v40; // eax
  int v41; // ecx
  char *v42; // eax
  _DWORD *v43; // ebx
  _DWORD *v44; // ecx
  _DWORD *v45; // ecx
  bool v46; // zf
  unsigned int v47; // eax
  int m; // [esp+Ch] [ebp-14h]
  unsigned int v49; // [esp+10h] [ebp-10h]
  _DWORD *v50; // [esp+14h] [ebp-Ch]
  char *v51; // [esp+18h] [ebp-8h]
  unsigned int v52; // [esp+18h] [ebp-8h]
  unsigned int v53; // [esp+18h] [ebp-8h]
  _DWORD *v54; // [esp+18h] [ebp-8h]
  _DWORD *v55; // [esp+1Ch] [ebp-4h]
  int v56; // [esp+30h] [ebp+10h]
  unsigned int v57; // [esp+30h] [ebp+10h]
  char *v58; // [esp+30h] [ebp+10h]
  unsigned int v59; // [esp+34h] [ebp+14h]

  v5 = (char *)a3;
  v6 = *(_WORD **)(a1 + 24);
  v7 = *(_DWORD **)(a1 + 32);
  v55 = v7;
  v51 = (char *)a3;
  switch ( *v6 )
  {
    case 0:
      a4 *= 16;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      goto LABEL_65;
    case 1:
      a4 *= 4;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      LOWORD(v25) = v6[3];
      if ( (_WORD)v25 != 4 )
      {
        v26 = *(_DWORD **)(a1 + 32);
        v27 = 0;
        if ( a4 != 0 )
        {
          v25 = (unsigned __int16)v25;
          do
          {
            for ( i = 0; i < v25; ++i )
            {
              if ( i <= 4 )
                v29 = *(_DWORD *)(a3 + 4 * (i + 4 * v27));
              else
                v29 = 0;
              *v26 = v29;
              v25 = (unsigned __int16)v6[3];
              ++v26;
            }
            ++v27;
          }
          while ( v27 < a4 );
        }
        goto LABEL_22;
      }
      goto LABEL_65;
    case 2:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v19 = v6[2];
      if ( v19 != 4 || v6[3] != 4 )
      {
        v53 = 0;
        for ( j = *(_DWORD **)(a1 + 32); v53 < a4; ++v53 )
        {
          v21 = 0;
          if ( v19 != 0 )
          {
            v22 = (unsigned __int16)v6[3];
            do
            {
              for ( k = 0; k < v22; ++k )
              {
                if ( v21 > 4 || k > 4 )
                  v24 = 0;
                else
                  v24 = *(_DWORD *)(a3 + 4 * (k + 4 * (v21 + 4 * v53)));
                *j = v24;
                v22 = (unsigned __int16)v6[3];
                ++j;
              }
              v19 = v6[2];
              ++v21;
            }
            while ( v21 < v19 );
          }
        }
        goto LABEL_22;
      }
LABEL_65:
      v30 = v6[1];
      if ( v30 != 3 )
      {
        v31 = a4 * *(_DWORD *)(a1 + 52);
        v32 = v30 - 1;
        if ( v32 != 0 )
        {
          if ( v32 == 1 && v31 != 0 )
          {
            v33 = v55;
            do
            {
              *v33 = (int)*(float *)((char *)v33 + v5 - (char *)v55);
              ++v33;
              --v31;
            }
            while ( v31 != 0 );
          }
        }
        else if ( v31 != 0 )
        {
          v34 = v55;
          do
          {
            *v34 = *(float *)((char *)v34 + v5 - (char *)v55) != 0.0;
            ++v34;
            --v31;
          }
          while ( v31 != 0 );
        }
        v51 = (char *)v55;
      }
      v35 = *(_WORD *)(a1 + 8);
      if ( v35 != 0 )
      {
        if ( *v6 == 3 )
        {
          v36 = (unsigned __int16)v6[2];
          v37 = (unsigned __int16)v6[3];
        }
        else
        {
          v36 = (unsigned __int16)v6[3];
          v37 = (unsigned __int16)v6[2];
        }
        if ( (v36 & 3) != 0 )
        {
          v50 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefInt4;
          if ( v35 != 1 )
            v50 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefFloat4;
          v38 = a4 * v37;
          v39 = (v36 + 3) & 0xFFFFFFFC;
          if ( v38 != 0 )
          {
            v40 = 4 * v38 + 4;
            v41 = v39 * v40;
            v42 = &v51[v36 * v40];
            v43 = &v55[v36 + v39 * v38];
            v54 = (_DWORD *)((char *)v55 + v41);
            for ( m = v38; m != 0; --m )
            {
              v54 -= v39;
              v43 -= v39;
              v42 -= 4 * v36;
              v57 = (v36 + 3) & 0xFFFFFFFC;
              if ( v39 > v36 )
              {
                v44 = v54;
                do
                  *--v44 = v50[--v57 & 3];
                while ( v57 > v36 );
              }
              if ( v36 != 0 )
              {
                v45 = v43;
                v58 = v42;
                v49 = v36;
                do
                {
                  v58 -= 4;
                  --v45;
                  v46 = v49-- == 1;
                  *v45 = *(_DWORD *)v58;
                }
                while ( !v46 );
              }
            }
          }
          v51 = (char *)v55;
        }
      }
      v47 = a4 * *(_DWORD *)(a1 + 44);
      if ( v47 > *(unsigned __int16 *)(a1 + 12) )
        v47 = *(unsigned __int16 *)(a1 + 12);
      result = (*(int (__stdcall **)(int, int, char *, _DWORD *, unsigned int))(a1 + 28))(
                 a1: a2,
                 a2: a5 + *(unsigned __int16 *)(a1 + 10),
                 a3: v51,
                 a4: v55,
                 a5: v47);
      if ( result < 0 )
        return result;
      return 0;
    case 3:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v11 = v6[2];
      if ( v11 == 4 && v6[3] == 4 )
      {
        if ( a4 != 0 )
        {
          v12 = v7 + 2;
          v13 = (float *)(a3 + 32);
          for ( n = a4; n != 0; --n )
          {
            *(v12 - 2) = *((_DWORD *)v13 - 8);
            *(v12 - 1) = *((_DWORD *)v13 - 4);
            *v12 = *(_DWORD *)v13;
            v12[1] = *((_DWORD *)v13 + 4);
            v12[2] = *((_DWORD *)v13 - 7);
            v12[3] = *((_DWORD *)v13 - 3);
            v12[4] = *((_DWORD *)v13 + 1);
            v12[5] = *((_DWORD *)v13 + 5);
            *(float *)((char *)v55 + (_DWORD)v13 - a3) = *(v13 - 6);
            v12[7] = *((_DWORD *)v13 - 2);
            v12[8] = *((_DWORD *)v13 + 2);
            v12[9] = *((_DWORD *)v13 + 6);
            v12[10] = *((_DWORD *)v13 - 5);
            v12[11] = *((_DWORD *)v13 - 1);
            v12[12] = *((_DWORD *)v13 + 3);
            v12[13] = *((_DWORD *)v13 + 7);
            v13 += 16;
            v12 += 16;
          }
        }
      }
      else
      {
        for ( ii = 0; ii < a4; ++ii )
        {
          v52 = 0;
          if ( v6[3] != 0 )
          {
            v16 = v11;
            do
            {
              v17 = 0;
              if ( v16 != 0 )
              {
                do
                {
                  if ( v17 > 4 || v52 > 4 )
                    v18 = 0;
                  else
                    v18 = *(_DWORD *)(a3 + 4 * (v52 + 4 * (v17 + 4 * ii)));
                  *v7 = v18;
                  v11 = v6[2];
                  ++v7;
                  v16 = v11;
                  ++v17;
                }
                while ( v17 < v11 );
              }
              ++v52;
            }
            while ( v52 < (unsigned __int16)v6[3] );
          }
        }
      }
LABEL_22:
      v5 = (char *)v55;
      v51 = (char *)v55;
      goto LABEL_65;
    default:
      break;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v59 = 16 * a4 / *(_DWORD *)(a1 + 52);
  if ( v59 > (unsigned __int16)v6[4] )
    v59 = (unsigned __int16)v6[4];
  v56 = 0;
  if ( v59 == 0 )
    return 0;
  while ( 1 )
  {
    v9 = 0;
    if ( v6[5] != 0 )
      break;
LABEL_13:
    if ( ++v56 >= v59 )
      return 0;
  }
  while ( 1 )
  {
    v10 = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 4 * v9);
    result = D3DXShader::SetTyped<0,3,1,1,0>::Set(a1, a2, a3: v51, a4: *(_DWORD *)(v10 + 48), a5);
    if ( result < 0 )
      return result;
    v51 += 4 * *(_DWORD *)(v10 + 48);
    a5 += *(_DWORD *)(v10 + 40);
    if ( ++v9 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBF7B
// Name: public: static long D3DXShader::SetTyped<2,3,4,4,1>::Set(class D3DXShader::CConstant __near *,void const __near *,void const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetTyped<2,3,4,4,1>::Set(int a1, int a2, int a3, unsigned int a4, int a5)
{
  _WORD *v5; // esi
  unsigned int v6; // edx
  int result; // eax
  unsigned int v8; // ecx
  unsigned int v9; // edi
  _DWORD *kk; // edx
  int v11; // ebx
  int v12; // edi
  _DWORD *v13; // edi
  unsigned int jj; // ebx
  unsigned int v15; // eax
  unsigned int v16; // edx
  int v17; // ecx
  int v18; // eax
  unsigned int v19; // edi
  unsigned int v20; // edx
  unsigned int v21; // eax
  unsigned int ii; // ecx
  int v23; // eax
  _DWORD *v24; // ebx
  _DWORD *v25; // edx
  unsigned int v26; // eax
  unsigned int m; // ecx
  int v28; // eax
  int v29; // edi
  _DWORD *v30; // ecx
  unsigned __int16 v31; // ax
  unsigned int v32; // ecx
  int v33; // eax
  unsigned int i; // eax
  float *v35; // edx
  unsigned int j; // edx
  float *v37; // edi
  __int16 v38; // ax
  unsigned int v39; // edx
  int v40; // edi
  int v41; // edi
  unsigned int v42; // esi
  int v43; // eax
  int v44; // ecx
  char *v45; // eax
  char *v46; // ebx
  char *v47; // ecx
  char *v48; // ecx
  bool v49; // zf
  unsigned int v50; // eax
  int k; // [esp+Ch] [ebp-14h]
  unsigned int v52; // [esp+10h] [ebp-10h]
  _DWORD *v53; // [esp+14h] [ebp-Ch]
  int v54; // [esp+18h] [ebp-8h]
  unsigned int v55; // [esp+18h] [ebp-8h]
  _DWORD *n; // [esp+18h] [ebp-8h]
  unsigned int v57; // [esp+18h] [ebp-8h]
  char *v58; // [esp+18h] [ebp-8h]
  char *v59; // [esp+1Ch] [ebp-4h]
  char *v60; // [esp+30h] [ebp+10h]
  unsigned int v61; // [esp+30h] [ebp+10h]
  char *v62; // [esp+30h] [ebp+10h]
  unsigned int v63; // [esp+34h] [ebp+14h]

  v5 = *(_WORD **)(a1 + 24);
  v6 = 0;
  v59 = *(char **)(a1 + 32);
  switch ( *v5 )
  {
    case 0:
      v29 = 16 * a4;
      a4 *= 16;
      if ( a4 > (unsigned __int16)v5[4] )
      {
        v29 = (unsigned __int16)v5[4];
        a4 = v29;
      }
      v30 = *(_DWORD **)(a1 + 32);
      if ( v29 != 0 )
      {
        do
        {
          *v30++ = *(_DWORD *)(*(_DWORD *)(a3 + 4 * (v6 >> 4)) + 4 * ((v6 & 3) + 4 * ((v6 >> 2) & 3)));
          ++v6;
        }
        while ( v6 < a4 );
      }
LABEL_61:
      v31 = v5[1];
      if ( v31 != 3 )
      {
        v32 = a4 * *(_DWORD *)(a1 + 52);
        v33 = v31 - 1;
        if ( v33 != 0 )
        {
          if ( v33 == 1 )
          {
            for ( i = 0; i < v32; *(_DWORD *)v35 = (int)*v35 )
              v35 = (float *)&v59[4 * i++];
          }
        }
        else
        {
          for ( j = 0; j < v32; *(_DWORD *)v37 = *v37 != 0.0 )
            v37 = (float *)&v59[4 * j++];
        }
      }
      v38 = *(_WORD *)(a1 + 8);
      if ( v38 != 0 )
      {
        if ( *v5 == 3 )
        {
          v39 = (unsigned __int16)v5[2];
          v40 = (unsigned __int16)v5[3];
        }
        else
        {
          v39 = (unsigned __int16)v5[3];
          v40 = (unsigned __int16)v5[2];
        }
        if ( (v39 & 3) != 0 )
        {
          v53 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefInt4;
          if ( v38 != 1 )
            v53 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefFloat4;
          v41 = a4 * v40;
          v42 = (v39 + 3) & 0xFFFFFFFC;
          if ( v41 != 0 )
          {
            v43 = 4 * v41 + 4;
            v44 = v42 * v43;
            v45 = &v59[v39 * v43];
            v46 = &v59[4 * v39 + 4 * v42 * v41];
            v58 = &v59[v44];
            for ( k = v41; k != 0; --k )
            {
              v58 -= 4 * v42;
              v46 -= 4 * v42;
              v45 -= 4 * v39;
              v61 = (v39 + 3) & 0xFFFFFFFC;
              if ( v42 > v39 )
              {
                v47 = v58;
                do
                {
                  --v61;
                  v47 -= 4;
                  *(_DWORD *)v47 = v53[v61 & 3];
                }
                while ( v61 > v39 );
              }
              if ( v39 != 0 )
              {
                v48 = v46;
                v62 = v45;
                v52 = v39;
                do
                {
                  v62 -= 4;
                  v48 -= 4;
                  v49 = v52-- == 1;
                  *(_DWORD *)v48 = *(_DWORD *)v62;
                }
                while ( !v49 );
              }
            }
          }
        }
      }
      v50 = a4 * *(_DWORD *)(a1 + 44);
      if ( v50 > *(unsigned __int16 *)(a1 + 12) )
        v50 = *(unsigned __int16 *)(a1 + 12);
      result = (*(int (__stdcall **)(int, int, char *, char *, unsigned int))(a1 + 28))(
                 a1: a2,
                 a2: a5 + *(unsigned __int16 *)(a1 + 10),
                 a3: v59,
                 a4: v59,
                 a5: v50);
      if ( result < 0 )
        return result;
      return 0;
    case 1:
      a4 *= 4;
      if ( a4 > (unsigned __int16)v5[4] )
        a4 = (unsigned __int16)v5[4];
      v57 = 0;
      v25 = *(_DWORD **)(a1 + 32);
      if ( a4 != 0 )
      {
        v26 = (unsigned __int16)v5[3];
        do
        {
          for ( m = 0; m < v26; ++m )
          {
            if ( m <= 4 )
              v28 = *(_DWORD *)(*(_DWORD *)(a3 + 4 * (v57 >> 2)) + 4 * (m + 4 * (v57 & 3)));
            else
              v28 = 0;
            *v25 = v28;
            v26 = (unsigned __int16)v5[3];
            ++v25;
          }
          ++v57;
        }
        while ( v57 < a4 );
      }
      goto LABEL_61;
    case 2:
      if ( a4 > (unsigned __int16)v5[4] )
        a4 = (unsigned __int16)v5[4];
      v19 = 0;
      for ( n = *(_DWORD **)(a1 + 32); v19 < a4; ++v19 )
      {
        v20 = 0;
        if ( v5[2] != 0 )
        {
          v21 = (unsigned __int16)v5[3];
          do
          {
            for ( ii = 0; ii < v21; ++ii )
            {
              if ( v20 > 4 || ii > 4 )
                v23 = 0;
              else
                v23 = *(_DWORD *)(*(_DWORD *)(a3 + 4 * v19) + 4 * (ii + 4 * v20));
              v24 = n++;
              *v24 = v23;
              v21 = (unsigned __int16)v5[3];
            }
            ++v20;
          }
          while ( v20 < (unsigned __int16)v5[2] );
        }
      }
      goto LABEL_61;
    case 3:
      if ( a4 > (unsigned __int16)v5[4] )
        a4 = (unsigned __int16)v5[4];
      v13 = *(_DWORD **)(a1 + 32);
      for ( jj = 0; jj < a4; ++jj )
      {
        v55 = 0;
        if ( v5[3] != 0 )
        {
          v15 = (unsigned __int16)v5[2];
          do
          {
            v16 = 0;
            if ( v15 != 0 )
            {
              v17 = 4 * v55;
              do
              {
                if ( v16 > 4 || v55 > 4 )
                  v18 = 0;
                else
                  v18 = *(_DWORD *)(v17 + *(_DWORD *)(a3 + 4 * jj));
                *v13 = v18;
                v15 = (unsigned __int16)v5[2];
                ++v13;
                ++v16;
                v17 += 16;
              }
              while ( v16 < v15 );
            }
            ++v55;
          }
          while ( v55 < (unsigned __int16)v5[3] );
        }
      }
      goto LABEL_61;
    default:
      break;
  }
  if ( *v5 != 5 )
    return -2147467263;
  v8 = *(_DWORD *)(a1 + 52);
  v63 = 16 * a4 / v8;
  if ( v63 > (unsigned __int16)v5[4] )
    v63 = (unsigned __int16)v5[4];
  v9 = 0;
  for ( kk = *(_DWORD **)(a1 + 32); v9 < v63 * v8; ++v9 )
    *kk++ = *(_DWORD *)(*(_DWORD *)(a3 + 4 * (v9 >> 4)) + 4 * ((v9 & 3) + 4 * ((v9 >> 2) & 3)));
  v54 = 0;
  v60 = v59;
  if ( v63 == 0 )
    return 0;
  while ( 1 )
  {
    v11 = 0;
    if ( v5[5] != 0 )
      break;
LABEL_15:
    if ( ++v54 >= v63 )
      return 0;
  }
  while ( 1 )
  {
    v12 = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 4 * v11);
    result = D3DXShader::SetTyped<0,3,1,1,0>::Set(a1, a2, a3: v60, a4: *(_DWORD *)(v12 + 48), a5);
    if ( result < 0 )
      return result;
    v60 += 4 * *(_DWORD *)(v12 + 48);
    a5 += *(_DWORD *)(v12 + 40);
    if ( ++v11 >= (unsigned int)(unsigned __int16)v5[5] )
      goto LABEL_15;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC3B5
// Name: public: static long D3DXShader::SetTyped<3,3,4,4,0>::Set(class D3DXShader::CConstant __near *,void const __near *,void const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetTyped<3,3,4,4,0>::Set(int a1, int a2, int a3, unsigned int a4, int a5)
{
  char *v5; // ebx
  _WORD *v6; // esi
  int result; // eax
  unsigned int v8; // ecx
  _DWORD *v9; // edx
  unsigned int jj; // edi
  int v11; // ebx
  int v12; // edi
  unsigned __int16 v13; // dx
  _DWORD *v14; // edi
  unsigned int ii; // ebx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  unsigned __int16 v19; // cx
  _DWORD *v20; // ecx
  float *v21; // eax
  unsigned int j; // edi
  _DWORD *k; // edi
  unsigned int v24; // edx
  unsigned int v25; // eax
  unsigned int m; // ecx
  int v27; // eax
  _DWORD *v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int i; // ecx
  int v32; // eax
  int v33; // edi
  _DWORD *v34; // ecx
  unsigned int v35; // edx
  unsigned __int16 v36; // ax
  int v37; // ecx
  int v38; // eax
  _DWORD *v39; // eax
  _DWORD *v40; // edx
  __int16 v41; // ax
  unsigned int v42; // edx
  int v43; // edi
  int v44; // edi
  unsigned int v45; // esi
  int v46; // eax
  int v47; // ecx
  _DWORD *v48; // eax
  _DWORD *v49; // ebx
  _DWORD *v50; // ecx
  _DWORD *v51; // ecx
  bool v52; // zf
  unsigned int v53; // eax
  int n; // [esp+Ch] [ebp-14h]
  unsigned int v55; // [esp+10h] [ebp-10h]
  _DWORD *v56; // [esp+14h] [ebp-Ch]
  _DWORD *v57; // [esp+18h] [ebp-8h]
  char *v58; // [esp+18h] [ebp-8h]
  unsigned int v59; // [esp+18h] [ebp-8h]
  unsigned int v60; // [esp+18h] [ebp-8h]
  _DWORD *v61; // [esp+18h] [ebp-8h]
  _DWORD *v62; // [esp+1Ch] [ebp-4h]
  int v63; // [esp+30h] [ebp+10h]
  unsigned int v64; // [esp+30h] [ebp+10h]
  _DWORD *v65; // [esp+30h] [ebp+10h]
  unsigned int v66; // [esp+34h] [ebp+14h]

  v5 = (char *)a3;
  v6 = *(_WORD **)(a1 + 24);
  v62 = *(_DWORD **)(a1 + 32);
  v57 = (_DWORD *)a3;
  switch ( *v6 )
  {
    case 0:
      v33 = 16 * a4;
      a4 *= 16;
      if ( a4 > (unsigned __int16)v6[4] )
      {
        v33 = (unsigned __int16)v6[4];
        a4 = v33;
      }
      v34 = *(_DWORD **)(a1 + 32);
      v35 = 0;
      if ( v33 != 0 )
      {
        do
        {
          *v34++ = *(_DWORD *)(a3 + 4 * (((v35 >> 2) & 3) + 4 * ((v35 & 3) + 4 * (v35 >> 4))));
          ++v35;
        }
        while ( v35 < a4 );
      }
      goto LABEL_68;
    case 1:
      a4 *= 4;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v28 = *(_DWORD **)(a1 + 32);
      v29 = 0;
      if ( a4 != 0 )
      {
        v30 = (unsigned __int16)v6[3];
        do
        {
          for ( i = 0; i < v30; ++i )
          {
            if ( i <= 4 )
              v32 = *(_DWORD *)(a3 + 4 * ((v29 & 3) + 4 * (i + 4 * (v29 >> 2))));
            else
              v32 = 0;
            *v28 = v32;
            v30 = (unsigned __int16)v6[3];
            ++v28;
          }
          ++v29;
        }
        while ( v29 < a4 );
      }
      goto LABEL_68;
    case 2:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v19 = v6[2];
      if ( v19 == 4 && v6[3] == 4 )
      {
        if ( a4 != 0 )
        {
          v20 = v62 + 2;
          v21 = (float *)(a3 + 32);
          for ( j = a4; j != 0; --j )
          {
            *(v20 - 2) = *((_DWORD *)v21 - 8);
            *(v20 - 1) = *((_DWORD *)v21 - 4);
            *v20 = *(_DWORD *)v21;
            v20[1] = *((_DWORD *)v21 + 4);
            v20[2] = *((_DWORD *)v21 - 7);
            v20[3] = *((_DWORD *)v21 - 3);
            v20[4] = *((_DWORD *)v21 + 1);
            v20[5] = *((_DWORD *)v21 + 5);
            *(float *)((char *)v21 + (_DWORD)v62 - a3) = *(v21 - 6);
            v20[7] = *((_DWORD *)v21 - 2);
            v20[8] = *((_DWORD *)v21 + 2);
            v20[9] = *((_DWORD *)v21 + 6);
            v20[10] = *((_DWORD *)v21 - 5);
            v20[11] = *((_DWORD *)v21 - 1);
            v20[12] = *((_DWORD *)v21 + 3);
            v20[13] = *((_DWORD *)v21 + 7);
            v21 += 16;
            v20 += 16;
          }
        }
      }
      else
      {
        v60 = 0;
        for ( k = *(_DWORD **)(a1 + 32); v60 < a4; ++v60 )
        {
          v24 = 0;
          if ( v19 != 0 )
          {
            v25 = (unsigned __int16)v6[3];
            do
            {
              for ( m = 0; m < v25; ++m )
              {
                if ( v24 > 4 || m > 4 )
                  v27 = 0;
                else
                  v27 = *(_DWORD *)(a3 + 4 * (v24 + 4 * (m + 4 * v60)));
                *k = v27;
                v25 = (unsigned __int16)v6[3];
                ++k;
              }
              v19 = v6[2];
              ++v24;
            }
            while ( v24 < v19 );
          }
        }
      }
      goto LABEL_68;
    case 3:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v13 = v6[2];
      if ( v13 == 4 && v6[3] == 4 )
      {
LABEL_69:
        v36 = v6[1];
        if ( v36 != 3 )
        {
          v37 = a4 * *(_DWORD *)(a1 + 52);
          v38 = v36 - 1;
          if ( v38 != 0 )
          {
            if ( v38 == 1 && v37 != 0 )
            {
              v39 = v62;
              do
              {
                *v39 = (int)*(float *)((char *)v39 + v5 - (char *)v62);
                ++v39;
                --v37;
              }
              while ( v37 != 0 );
            }
          }
          else if ( v37 != 0 )
          {
            v40 = v62;
            do
            {
              *v40 = *(float *)((char *)v40 + v5 - (char *)v62) != 0.0;
              ++v40;
              --v37;
            }
            while ( v37 != 0 );
          }
          v5 = (char *)v62;
          v57 = v62;
        }
        v41 = *(_WORD *)(a1 + 8);
        if ( v41 != 0 )
        {
          if ( *v6 == 3 )
          {
            v42 = (unsigned __int16)v6[2];
            v43 = (unsigned __int16)v6[3];
          }
          else
          {
            v42 = (unsigned __int16)v6[3];
            v43 = (unsigned __int16)v6[2];
          }
          if ( (v42 & 3) != 0 )
          {
            v56 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefInt4;
            if ( v41 != 1 )
              v56 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefFloat4;
            v44 = a4 * v43;
            v45 = (v42 + 3) & 0xFFFFFFFC;
            if ( v44 != 0 )
            {
              v46 = 4 * v44 + 4;
              v47 = v45 * v46;
              v48 = (_DWORD *)((char *)v57 + v42 * v46);
              v49 = &v62[v42 + v45 * v44];
              v61 = (_DWORD *)((char *)v62 + v47);
              for ( n = v44; n != 0; --n )
              {
                v61 -= v45;
                v49 -= v45;
                v48 -= v42;
                v64 = (v42 + 3) & 0xFFFFFFFC;
                if ( v45 > v42 )
                {
                  v50 = v61;
                  do
                    *--v50 = v56[--v64 & 3];
                  while ( v64 > v42 );
                }
                if ( v42 != 0 )
                {
                  v51 = v49;
                  v65 = v48;
                  v55 = v42;
                  do
                  {
                    --v65;
                    --v51;
                    v52 = v55-- == 1;
                    *v51 = *v65;
                  }
                  while ( !v52 );
                }
              }
            }
            v5 = (char *)v62;
          }
        }
        v53 = a4 * *(_DWORD *)(a1 + 44);
        if ( v53 > *(unsigned __int16 *)(a1 + 12) )
          v53 = *(unsigned __int16 *)(a1 + 12);
        result = (*(int (__stdcall **)(int, int, char *, _DWORD *, unsigned int))(a1 + 28))(
                   a1: a2,
                   a2: a5 + *(unsigned __int16 *)(a1 + 10),
                   a3: v5,
                   a4: v62,
                   a5: v53);
        if ( result < 0 )
          return result;
        return 0;
      }
      v14 = *(_DWORD **)(a1 + 32);
      for ( ii = 0; ii < a4; ++ii )
      {
        v59 = 0;
        if ( v6[3] != 0 )
        {
          v16 = v13;
          do
          {
            v17 = 0;
            if ( v16 != 0 )
            {
              do
              {
                if ( v17 > 4 || v59 > 4 )
                  v18 = 0;
                else
                  v18 = *(_DWORD *)(a3 + 4 * (v17 + 4 * (v59 + 4 * ii)));
                *v14 = v18;
                v13 = v6[2];
                ++v14;
                v16 = v13;
                ++v17;
              }
              while ( v17 < v13 );
            }
            ++v59;
          }
          while ( v59 < (unsigned __int16)v6[3] );
        }
      }
LABEL_68:
      v5 = (char *)v62;
      v57 = v62;
      goto LABEL_69;
    default:
      break;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v8 = *(_DWORD *)(a1 + 52);
  v66 = 16 * a4 / v8;
  if ( v66 > (unsigned __int16)v6[4] )
    v66 = (unsigned __int16)v6[4];
  v9 = *(_DWORD **)(a1 + 32);
  for ( jj = 0; jj < v66 * v8; ++jj )
    *v9++ = *(_DWORD *)(a3 + 4 * (((jj >> 2) & 3) + 4 * ((jj & 3) + 4 * (jj >> 4))));
  v63 = 0;
  v58 = (char *)v62;
  if ( v66 == 0 )
    return 0;
  while ( 1 )
  {
    v11 = 0;
    if ( v6[5] != 0 )
      break;
LABEL_15:
    if ( ++v63 >= v66 )
      return 0;
  }
  while ( 1 )
  {
    v12 = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 4 * v11);
    result = D3DXShader::SetTyped<0,3,1,1,0>::Set(a1, a2, a3: v58, a4: *(_DWORD *)(v12 + 48), a5);
    if ( result < 0 )
      return result;
    v58 += 4 * *(_DWORD *)(v12 + 48);
    a5 += *(_DWORD *)(v12 + 40);
    if ( ++v11 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_15;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC8BD
// Name: public: static long D3DXShader::SetTyped<3,3,4,4,1>::Set(class D3DXShader::CConstant __near *,void const __near *,void const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::SetTyped<3,3,4,4,1>::Set(int a1, int a2, int a3, unsigned int a4, int a5)
{
  _WORD *v5; // esi
  unsigned int v6; // edx
  int result; // eax
  unsigned int v8; // ecx
  unsigned int v9; // edi
  _DWORD *kk; // edx
  int v11; // ebx
  int v12; // edi
  unsigned int v13; // edi
  unsigned int v14; // edx
  unsigned int v15; // eax
  unsigned int jj; // ecx
  int v17; // eax
  _DWORD *v18; // ebx
  _DWORD *v19; // edi
  unsigned int n; // ebx
  unsigned int v21; // eax
  unsigned int v22; // edx
  int v23; // ecx
  int v24; // eax
  _DWORD *v25; // edx
  unsigned int v26; // eax
  unsigned int m; // ecx
  int v28; // eax
  int v29; // edi
  _DWORD *v30; // ecx
  unsigned __int16 v31; // ax
  unsigned int v32; // ecx
  int v33; // eax
  unsigned int i; // eax
  float *v35; // edx
  unsigned int j; // edx
  float *v37; // edi
  __int16 v38; // ax
  unsigned int v39; // edx
  int v40; // edi
  int v41; // edi
  unsigned int v42; // esi
  int v43; // eax
  int v44; // ecx
  char *v45; // eax
  char *v46; // ebx
  char *v47; // ecx
  char *v48; // ecx
  bool v49; // zf
  unsigned int v50; // eax
  int k; // [esp+Ch] [ebp-14h]
  unsigned int v52; // [esp+10h] [ebp-10h]
  _DWORD *v53; // [esp+14h] [ebp-Ch]
  int v54; // [esp+18h] [ebp-8h]
  _DWORD *ii; // [esp+18h] [ebp-8h]
  unsigned int v56; // [esp+18h] [ebp-8h]
  unsigned int v57; // [esp+18h] [ebp-8h]
  char *v58; // [esp+18h] [ebp-8h]
  char *v59; // [esp+1Ch] [ebp-4h]
  char *v60; // [esp+30h] [ebp+10h]
  unsigned int v61; // [esp+30h] [ebp+10h]
  char *v62; // [esp+30h] [ebp+10h]
  unsigned int v63; // [esp+34h] [ebp+14h]

  v5 = *(_WORD **)(a1 + 24);
  v6 = 0;
  v59 = *(char **)(a1 + 32);
  switch ( *v5 )
  {
    case 0:
      v29 = 16 * a4;
      a4 *= 16;
      if ( a4 > (unsigned __int16)v5[4] )
      {
        v29 = (unsigned __int16)v5[4];
        a4 = v29;
      }
      v30 = *(_DWORD **)(a1 + 32);
      if ( v29 != 0 )
      {
        do
        {
          *v30++ = *(_DWORD *)(*(_DWORD *)(a3 + 4 * (v6 >> 4)) + 4 * (((v6 >> 2) & 3) + 4 * (v6 & 3)));
          ++v6;
        }
        while ( v6 < a4 );
      }
LABEL_61:
      v31 = v5[1];
      if ( v31 != 3 )
      {
        v32 = a4 * *(_DWORD *)(a1 + 52);
        v33 = v31 - 1;
        if ( v33 != 0 )
        {
          if ( v33 == 1 )
          {
            for ( i = 0; i < v32; *(_DWORD *)v35 = (int)*v35 )
              v35 = (float *)&v59[4 * i++];
          }
        }
        else
        {
          for ( j = 0; j < v32; *(_DWORD *)v37 = *v37 != 0.0 )
            v37 = (float *)&v59[4 * j++];
        }
      }
      v38 = *(_WORD *)(a1 + 8);
      if ( v38 != 0 )
      {
        if ( *v5 == 3 )
        {
          v39 = (unsigned __int16)v5[2];
          v40 = (unsigned __int16)v5[3];
        }
        else
        {
          v39 = (unsigned __int16)v5[3];
          v40 = (unsigned __int16)v5[2];
        }
        if ( (v39 & 3) != 0 )
        {
          v53 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefInt4;
          if ( v38 != 1 )
            v53 = &`D3DXShader::SetTyped<2,3,4,4,0>::Set'[::M]::pDefFloat4;
          v41 = a4 * v40;
          v42 = (v39 + 3) & 0xFFFFFFFC;
          if ( v41 != 0 )
          {
            v43 = 4 * v41 + 4;
            v44 = v42 * v43;
            v45 = &v59[v39 * v43];
            v46 = &v59[4 * v39 + 4 * v42 * v41];
            v58 = &v59[v44];
            for ( k = v41; k != 0; --k )
            {
              v58 -= 4 * v42;
              v46 -= 4 * v42;
              v45 -= 4 * v39;
              v61 = (v39 + 3) & 0xFFFFFFFC;
              if ( v42 > v39 )
              {
                v47 = v58;
                do
                {
                  --v61;
                  v47 -= 4;
                  *(_DWORD *)v47 = v53[v61 & 3];
                }
                while ( v61 > v39 );
              }
              if ( v39 != 0 )
              {
                v48 = v46;
                v62 = v45;
                v52 = v39;
                do
                {
                  v62 -= 4;
                  v48 -= 4;
                  v49 = v52-- == 1;
                  *(_DWORD *)v48 = *(_DWORD *)v62;
                }
                while ( !v49 );
              }
            }
          }
        }
      }
      v50 = a4 * *(_DWORD *)(a1 + 44);
      if ( v50 > *(unsigned __int16 *)(a1 + 12) )
        v50 = *(unsigned __int16 *)(a1 + 12);
      result = (*(int (__stdcall **)(int, int, char *, char *, unsigned int))(a1 + 28))(
                 a1: a2,
                 a2: a5 + *(unsigned __int16 *)(a1 + 10),
                 a3: v59,
                 a4: v59,
                 a5: v50);
      if ( result < 0 )
        return result;
      return 0;
    case 1:
      a4 *= 4;
      if ( a4 > (unsigned __int16)v5[4] )
        a4 = (unsigned __int16)v5[4];
      v57 = 0;
      v25 = *(_DWORD **)(a1 + 32);
      if ( a4 != 0 )
      {
        v26 = (unsigned __int16)v5[3];
        do
        {
          for ( m = 0; m < v26; ++m )
          {
            if ( m <= 4 )
              v28 = *(_DWORD *)(*(_DWORD *)(a3 + 4 * (v57 >> 2)) + 4 * ((v57 & 3) + 4 * m));
            else
              v28 = 0;
            *v25 = v28;
            v26 = (unsigned __int16)v5[3];
            ++v25;
          }
          ++v57;
        }
        while ( v57 < a4 );
      }
      goto LABEL_61;
    case 2:
      if ( a4 > (unsigned __int16)v5[4] )
        a4 = (unsigned __int16)v5[4];
      v19 = *(_DWORD **)(a1 + 32);
      for ( n = 0; n < a4; ++n )
      {
        v56 = 0;
        if ( v5[2] != 0 )
        {
          v21 = (unsigned __int16)v5[3];
          do
          {
            v22 = 0;
            if ( v21 != 0 )
            {
              v23 = 4 * v56;
              do
              {
                if ( v56 > 4 || v22 > 4 )
                  v24 = 0;
                else
                  v24 = *(_DWORD *)(v23 + *(_DWORD *)(a3 + 4 * n));
                *v19 = v24;
                v21 = (unsigned __int16)v5[3];
                ++v19;
                ++v22;
                v23 += 16;
              }
              while ( v22 < v21 );
            }
            ++v56;
          }
          while ( v56 < (unsigned __int16)v5[2] );
        }
      }
      goto LABEL_61;
    case 3:
      if ( a4 > (unsigned __int16)v5[4] )
        a4 = (unsigned __int16)v5[4];
      v13 = 0;
      for ( ii = *(_DWORD **)(a1 + 32); v13 < a4; ++v13 )
      {
        v14 = 0;
        if ( v5[3] != 0 )
        {
          v15 = (unsigned __int16)v5[2];
          do
          {
            for ( jj = 0; jj < v15; ++jj )
            {
              if ( jj > 4 || v14 > 4 )
                v17 = 0;
              else
                v17 = *(_DWORD *)(*(_DWORD *)(a3 + 4 * v13) + 4 * (jj + 4 * v14));
              v18 = ii++;
              *v18 = v17;
              v15 = (unsigned __int16)v5[2];
            }
            ++v14;
          }
          while ( v14 < (unsigned __int16)v5[3] );
        }
      }
      goto LABEL_61;
    default:
      break;
  }
  if ( *v5 != 5 )
    return -2147467263;
  v8 = *(_DWORD *)(a1 + 52);
  v63 = 16 * a4 / v8;
  if ( v63 > (unsigned __int16)v5[4] )
    v63 = (unsigned __int16)v5[4];
  v9 = 0;
  for ( kk = *(_DWORD **)(a1 + 32); v9 < v63 * v8; ++v9 )
    *kk++ = *(_DWORD *)(*(_DWORD *)(a3 + 4 * (v9 >> 4)) + 4 * (((v9 >> 2) & 3) + 4 * (v9 & 3)));
  v54 = 0;
  v60 = v59;
  if ( v63 == 0 )
    return 0;
  while ( 1 )
  {
    v11 = 0;
    if ( v5[5] != 0 )
      break;
LABEL_15:
    if ( ++v54 >= v63 )
      return 0;
  }
  while ( 1 )
  {
    v12 = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 4 * v11);
    result = D3DXShader::SetTyped<0,3,1,1,0>::Set(a1, a2, a3: v60, a4: *(_DWORD *)(v12 + 48), a5);
    if ( result < 0 )
      return result;
    v60 += 4 * *(_DWORD *)(v12 + 48);
    a5 += *(_DWORD *)(v12 + 40);
    if ( ++v11 >= (unsigned int)(unsigned __int16)v5[5] )
      goto LABEL_15;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCCF7
// Name: public: static class D3DXShader::CConstant __near * D3DXShader::CConstant::Create(class D3DXShader::CConstantTable __near *,struct _D3DXSHADER_CONSTANTINFO __near *,struct _D3DXSHADER_TYPEINFO __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static struct D3DXShader::CConstant *__stdcall D3DXShader::CConstant::Create(
        struct D3DXShader::CConstantTable *a1,
        struct _D3DXSHADER_CONSTANTINFO *a2,
        struct _D3DXSHADER_TYPEINFO *a3,
        unsigned int *a4)
{
  int (__stdcall *v4)(const void *, unsigned int, const void *, unsigned int *, unsigned int); // edi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  D3DXShader::CConstant *v8; // eax
  D3DXShader::CConstant *v9; // esi

  v4 = nullptr;
  v5 = *(_DWORD *)(*((_DWORD *)a1 + 4) + 8) & 0xFFFF0000;
  if ( *((_WORD *)a3 + 5) != 0 )
  {
    if ( v5 != -131072 )
    {
      if ( v5 != -65536 )
        goto LABEL_75;
      if ( *((_WORD *)a2 + 2) != 0 )
      {
        v6 = *((unsigned __int16 *)a2 + 2) - 1;
        if ( *((_WORD *)a2 + 2) != 1 )
        {
LABEL_68:
          if ( v6 == 1 )
            v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,2,3>::Set;
          goto LABEL_75;
        }
        goto LABEL_70;
      }
      goto LABEL_27;
    }
    if ( *((_WORD *)a2 + 2) != 0 )
    {
      v7 = *((unsigned __int16 *)a2 + 2) - 1;
      if ( *((_WORD *)a2 + 2) != 1 )
      {
LABEL_35:
        if ( v7 == 1 )
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,2,3>::Set;
        goto LABEL_75;
      }
      goto LABEL_45;
    }
    goto LABEL_74;
  }
  if ( v5 != 1415053312 )
  {
    if ( v5 != -131072 )
    {
      if ( v5 != -65536 )
        goto LABEL_75;
      if ( *((_WORD *)a2 + 2) != 0 )
      {
        if ( *((_WORD *)a2 + 2) != 1 )
        {
          if ( *((_WORD *)a2 + 2) != 2 )
            goto LABEL_75;
          if ( *((_WORD *)a3 + 1) == 0 )
          {
            v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,2,3>::Set;
            goto LABEL_75;
          }
          if ( *((_WORD *)a3 + 1) == 1 )
          {
            v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,2,1>::Set;
            goto LABEL_75;
          }
          v6 = *((unsigned __int16 *)a3 + 1) - 2;
          if ( *((_WORD *)a3 + 1) == 2 )
          {
            v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,2,2>::Set;
            goto LABEL_75;
          }
          goto LABEL_68;
        }
        if ( *((_WORD *)a3 + 1) == 0 )
        {
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,1,2>::Set;
          goto LABEL_75;
        }
        if ( *((_WORD *)a3 + 1) == 1 )
        {
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,1,1>::Set;
          goto LABEL_75;
        }
        if ( *((_WORD *)a3 + 1) != 2 )
        {
          if ( *((_WORD *)a3 + 1) == 3 )
            v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,1,3>::Set;
          goto LABEL_75;
        }
LABEL_70:
        v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,1,2>::Set;
        goto LABEL_75;
      }
      if ( *((_WORD *)a3 + 1) == 0 )
      {
        v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,0,0>::Set;
        goto LABEL_75;
      }
      if ( *((_WORD *)a3 + 1) != 1 )
      {
        if ( *((_WORD *)a3 + 1) == 2 )
        {
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,0,2>::Set;
        }
        else if ( *((_WORD *)a3 + 1) == 3 )
        {
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,0,3>::Set;
        }
        goto LABEL_75;
      }
LABEL_27:
      v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<1,0,0>::Set;
      goto LABEL_75;
    }
    if ( *((_WORD *)a2 + 2) != 0 )
    {
      if ( *((_WORD *)a2 + 2) != 1 )
      {
        if ( *((_WORD *)a2 + 2) != 2 )
          goto LABEL_75;
        if ( *((_WORD *)a3 + 1) == 0 )
        {
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,2,3>::Set;
          goto LABEL_75;
        }
        if ( *((_WORD *)a3 + 1) == 1 )
        {
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,2,1>::Set;
          goto LABEL_75;
        }
        v7 = *((unsigned __int16 *)a3 + 1) - 2;
        if ( *((_WORD *)a3 + 1) == 2 )
        {
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,2,2>::Set;
          goto LABEL_75;
        }
        goto LABEL_35;
      }
      if ( *((_WORD *)a3 + 1) == 0 )
      {
        v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,1,2>::Set;
        goto LABEL_75;
      }
      if ( *((_WORD *)a3 + 1) == 1 )
      {
        v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,1,1>::Set;
        goto LABEL_75;
      }
      if ( *((_WORD *)a3 + 1) != 2 )
      {
        if ( *((_WORD *)a3 + 1) == 3 )
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,1,3>::Set;
        goto LABEL_75;
      }
LABEL_45:
      v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,1,2>::Set;
      goto LABEL_75;
    }
    if ( *((_WORD *)a3 + 1) == 0 )
    {
      v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,0,1>::Set;
      goto LABEL_75;
    }
    if ( *((_WORD *)a3 + 1) != 1 )
    {
      if ( *((_WORD *)a3 + 1) == 2 )
      {
        v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,0,2>::Set;
      }
      else if ( *((_WORD *)a3 + 1) == 3 )
      {
        v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,0,3>::Set;
      }
      goto LABEL_75;
    }
LABEL_74:
    v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<0,0,1>::Set;
    goto LABEL_75;
  }
  if ( *((_WORD *)a2 + 2) == 2 )
  {
    if ( *((_WORD *)a3 + 1) != 0 )
    {
      switch ( *((_WORD *)a3 + 1) )
      {
        case 1:
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<2,2,1>::Set;
          break;
        case 2:
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<2,2,2>::Set;
          break;
        case 3:
          v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<2,2,3>::Set;
          break;
        default:
          break;
      }
    }
    else
    {
      v4 = (int (__stdcall *)(const void *, unsigned int, const void *, unsigned int *, unsigned int))D3DXShader::SetShaderConstant<2,2,3>::Set;
    }
  }
LABEL_75:
  v8 = (D3DXShader::CConstant *)MemAlloc_Alloc(nSize: 0x44u);
  if ( v8 != nullptr )
    v9 = (D3DXShader::CConstant *)D3DXShader::CConstant::CConstant(this: v8, a2: a1, a3: a2, a4: a3, a5: v4, a6: a4);
  else
    v9 = nullptr;
  if ( v9 == nullptr )
    return nullptr;
  if ( D3DXShader::CConstant::Initialize(this: v9) < 0 )
  {
    D3DXShader::CConstant::`scalar deleting destructor'(this: v9, a2: 1);
    return nullptr;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x101DCF8F
// Name: public: long D3DXShader::CConstant::Initialize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CConstant::Initialize(D3DXShader::CConstant *this)
{
  int v2; // eax
  void *v3; // edi
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edi
  _DWORD *v8; // edi
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  int v12; // esi
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // ecx
  int v16; // ecx
  struct D3DXShader::CConstant *v17; // eax
  int v18; // edx
  int v19; // eax
  unsigned int v20; // eax
  _DWORD v22[5]; // [esp+Ch] [ebp-24h] BYREF
  int v23; // [esp+20h] [ebp-10h] BYREF
  int v24; // [esp+24h] [ebp-Ch] BYREF
  unsigned int *v25; // [esp+28h] [ebp-8h]
  int v26; // [esp+2Ch] [ebp-4h]

  v2 = *((_DWORD *)this + 6);
  if ( *(_WORD *)(v2 + 10) == 0 )
    return 0;
  v3 = MemAlloc_Alloc(nSize: 4 * *(unsigned __int16 *)(v2 + 10));
  *((_DWORD *)this + 14) = v3;
  if ( v3 != nullptr )
  {
    memset(v3, 0, 4 * *(unsigned __int16 *)(*((_DWORD *)this + 6) + 10));
    v25 = *((unsigned int **)this + 8);
    v4 = *((_DWORD *)this + 6);
    qmemcpy(v22, (char *)this + 4, sizeof(v22));
    v5 = *(unsigned __int16 *)(v4 + 10);
    v6 = *(_DWORD *)(v4 + 12);
    if ( (unsigned int)(v6 + 8 * v5) > *(_DWORD *)(*(_DWORD *)this + 12) )
      return -2147467259;
    v7 = *(_DWORD *)(*(_DWORD *)this + 8);
    v26 = 0;
    v8 = (_DWORD *)(v6 + v7);
    if ( v5 != 0 )
    {
      while ( 1 )
      {
        v9 = v8[1];
        v10 = *(_DWORD *)this;
        if ( (unsigned int)(v9 + 16) > *(_DWORD *)(*(_DWORD *)this + 12) )
          break;
        v11 = *(_DWORD *)(v10 + 8);
        v24 = 0;
        v23 = 0;
        v12 = v9 + v11;
        sub_101DA11E(a1: v10, a2: v22, a3: v12, a4: 1, a5: &v24, a6: &v23);
        v13 = *((unsigned __int16 *)this + 5);
        v14 = *((unsigned __int16 *)this + 6);
        v22[0] = *v8;
        v22[3] = v8[1];
        LOWORD(v22[2]) = v24 * *(_WORD *)(v12 + 8);
        v15 = v13 + v14;
        if ( HIWORD(v22[1]) + (unsigned int)LOWORD(v22[2]) > v15 )
        {
          v16 = v15 - HIWORD(v22[1]);
          if ( v16 >= 0 )
            LOWORD(v22[2]) = v16;
          else
            LOWORD(v22[2]) = 0;
        }
        v17 = D3DXShader::CConstant::Create(
                a1: *(struct D3DXShader::CConstantTable **)this,
                a2: (struct _D3DXSHADER_CONSTANTINFO *)v22,
                a3: (struct _D3DXSHADER_TYPEINFO *)v12,
                a4: v25);
        v18 = v26;
        *(_DWORD *)(*((_DWORD *)this + 14) + 4 * v26) = v17;
        v19 = *((_DWORD *)this + 14) + 4 * v18;
        if ( *(_DWORD *)v19 == 0 )
          return -2147024882;
        HIWORD(v22[1]) += LOWORD(v22[2]);
        v25 += *(unsigned __int16 *)(v12 + 8) * *(_DWORD *)(*(_DWORD *)v19 + 44) * (LOWORD(v22[1]) != 0 ? 4 : 1);
        v20 = *(unsigned __int16 *)(*((_DWORD *)this + 6) + 10);
        v8 += 2;
        if ( ++v26 >= v20 )
          return 0;
      }
      return -2147467259;
    }
    return 0;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x101DD105
// Name: public: class D3DXShader::CConstant __near * D3DXShader::CConstant::GetConstantElement(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CConstant *__thiscall D3DXShader::CConstant::GetConstantElement(
        D3DXShader::CConstant *this,
        unsigned int a2)
{
  unsigned __int16 v3; // cx
  void *v5; // edi
  unsigned int v6; // eax
  bool v7; // zf
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  __int16 v10; // ax
  unsigned __int16 v11; // dx
  int v12; // esi
  unsigned __int16 v13; // cx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  unsigned int *v17; // esi
  D3DXShader::CConstant *v18; // eax
  int v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // esi
  D3DXShader::CConstant *v22; // ecx
  _DWORD v23[5]; // [esp+8h] [ebp-18h] BYREF
  unsigned int v24; // [esp+1Ch] [ebp-4h]

  v3 = *(_WORD *)(*((_DWORD *)this + 6) + 8);
  if ( a2 >= v3 )
    return nullptr;
  if ( v3 == 1 )
    return this;
  if ( *((_DWORD *)this + 15) == 0 )
  {
    v5 = MemAlloc_Alloc(nSize: 4 * v3);
    *((_DWORD *)this + 15) = v5;
    if ( v5 == nullptr )
      return nullptr;
    memset(v5, 0, 4 * *(unsigned __int16 *)(*((_DWORD *)this + 6) + 8));
  }
  v6 = 4 * a2;
  v7 = *(_DWORD *)(4 * a2 + *((_DWORD *)this + 15)) == 0;
  v24 = 4 * a2;
  if ( v7 )
  {
    if ( *((_DWORD *)this + 16) == 0 )
    {
      v8 = MemAlloc_Alloc(nSize: 0x10u);
      *((_DWORD *)this + 16) = v8;
      if ( v8 == nullptr )
        return nullptr;
      v9 = *((_DWORD **)this + 6);
      *v8 = *v9++;
      v8[1] = *v9++;
      v8[2] = *v9;
      v8[3] = v9[1];
      *(_WORD *)(*((_DWORD *)this + 16) + 8) = 1;
    }
    v10 = a2 * *((_WORD *)this + 22);
    v11 = *((_WORD *)this + 22);
    qmemcpy(v23, (char *)this + 4, sizeof(v23));
    v12 = *((unsigned __int16 *)this + 6);
    v13 = *((_WORD *)this + 5);
    LOWORD(v23[2]) = v11;
    HIWORD(v23[1]) = v13 + v10;
    v14 = v12 - (unsigned __int16)(v13 + v10) + v13;
    if ( v11 > v14 )
    {
      if ( v14 >= 0 )
        LOWORD(v23[2]) = v14;
      else
        LOWORD(v23[2]) = 0;
    }
    v15 = *((_DWORD *)this + 5);
    v16 = *((_WORD *)this + 4) != 0 ? 4 : 1;
    if ( v15 != 0 )
      v23[4] = v15 + 4 * a2 * v16 * *((_DWORD *)this + 11);
    v17 = (unsigned int *)(*((_DWORD *)this + 8) + 4 * a2 * v16 * *((_DWORD *)this + 11));
    v18 = (D3DXShader::CConstant *)MemAlloc_Alloc(nSize: 0x44u);
    if ( v18 != nullptr )
      v19 = D3DXShader::CConstant::CConstant(
              this: v18,
              a2: *(struct D3DXShader::CConstantTable **)this,
              a3: (struct _D3DXSHADER_CONSTANTINFO *)v23,
              a4: *((struct _D3DXSHADER_TYPEINFO **)this + 16),
              a5: *((int (__stdcall **)(const void *, unsigned int, const void *, unsigned int *, unsigned int))this + 7),
              a6: v17);
    else
      v19 = 0;
    v20 = v24;
    *(_DWORD *)(v24 + *((_DWORD *)this + 15)) = v19;
    if ( v19 == 0 )
      return nullptr;
    if ( D3DXShader::CConstant::Initialize(this: *(D3DXShader::CConstant **)(v20 + *((_DWORD *)this + 15))) < 0 )
    {
      v21 = v24;
      v22 = *(D3DXShader::CConstant **)(v24 + *((_DWORD *)this + 15));
      if ( v22 != nullptr )
        D3DXShader::CConstant::`scalar deleting destructor'(this: v22, a2: 1);
      *(_DWORD *)(v21 + *((_DWORD *)this + 15)) = 0;
      return nullptr;
    }
    v6 = v24;
  }
  return *(struct D3DXShader::CConstant **)(v6 + *((_DWORD *)this + 15));
}

//------------------------------------------------------------------------------
// Address: 0x101DD2A3
// Name: public: D3DXShader::CConstantTable::CConstantTable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CConstantTable *__thiscall D3DXShader::CConstantTable::CConstantTable(D3DXShader::CConstantTable *this)
{
  *(_DWORD *)this = &D3DXShader::CConstantTable::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DD2C4
// Name: public: long D3DXShader::CConstantTable::Initialize(unsigned long const __near *,struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CConstantTable::Initialize(
        D3DXShader::CConstantTable *this,
        const unsigned int *a2,
        struct ID3DXBuffer **a3)
{
  int result; // eax
  unsigned int *v5; // esi
  void *v6; // eax
  _DWORD *v7; // eax
  void *v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // esi
  int v12; // edi
  _DWORD *v13; // ecx
  int *v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  void *v18; // eax
  unsigned int v19; // edi
  int v20; // ecx
  unsigned int v21; // ecx
  int v22; // ebx
  unsigned __int16 *v23; // eax
  int v24; // esi
  const void *v25; // [esp+8h] [ebp-8h] BYREF
  _DWORD *v26; // [esp+Ch] [ebp-4h]
  const unsigned int *v27; // [esp+18h] [ebp+8h]
  const unsigned int *v28; // [esp+18h] [ebp+8h]

  if ( a2 == nullptr )
    return -2005530516;
  v5 = (unsigned int *)((char *)this + 12);
  result = D3DXFindShaderComment(a1: a2, a2: 1111577667, a3: &v25, a4: (char *)this + 12);
  if ( result >= 0 )
  {
    if ( result == 1 )
      return -2005529767;
    v6 = MemAlloc_Alloc(nSize: *v5);
    *((_DWORD *)this + 2) = v6;
    if ( v6 == nullptr )
      return -2147024882;
    qmemcpy(v6, v25, *v5);
    v7 = *((_DWORD **)this + 2);
    *((_DWORD *)this + 4) = v7;
    if ( *v7 < 0x1Cu )
      return -2005529767;
    v8 = MemAlloc_Alloc(nSize: 4 * v7[3]);
    *((_DWORD *)this + 5) = v8;
    if ( v8 == nullptr )
      return -2147024882;
    memset(v8, 0, 4 * *(_DWORD *)(*((_DWORD *)this + 4) + 12));
    v9 = *((_DWORD *)this + 4);
    *((_DWORD *)this + 6) = *(_DWORD *)(v9 + 12);
    v10 = *(_DWORD *)(v9 + 16);
    if ( (unsigned int)(v10 + 20 * *(_DWORD *)(v9 + 12)) > *((_DWORD *)this + 3) )
      return -2005529767;
    v27 = nullptr;
    v11 = v10 + *((_DWORD *)this + 2);
    v12 = 0;
    if ( *((_DWORD *)this + 6) != 0 )
    {
      v13 = (_DWORD *)(v11 + 12);
      v26 = (_DWORD *)(v11 + 12);
      while ( (unsigned int)(*v13 + 16) <= *((_DWORD *)this + 3) )
      {
        *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v12) = D3DXShader::CConstant::Create(
                                                         a1: this,
                                                         a2: (struct _D3DXSHADER_CONSTANTINFO *)(v13 - 3),
                                                         a3: (struct _D3DXSHADER_TYPEINFO *)(*v13 + *((_DWORD *)this + 2)),
                                                         a4: nullptr);
        v14 = (int *)(*((_DWORD *)this + 5) + 4 * v12);
        if ( *v14 == 0 )
          return -2147024882;
        v15 = *v14;
        v16 = *(unsigned __int16 *)(*(_DWORD *)(v15 + 24) + 8);
        v17 = *(_WORD *)(v15 + 8) != 0 ? 3 : 0;
        v26 += 5;
        v27 = (const unsigned int *)((char *)v27 + *(_DWORD *)(v15 + 44) * v16 * (v17 + 1));
        if ( (unsigned int)++v12 >= *((_DWORD *)this + 6) )
          goto LABEL_19;
        v13 = v26;
      }
      return -2005529767;
    }
LABEL_19:
    v18 = MemAlloc_Alloc(nSize: 4 * (_DWORD)v27);
    v19 = 0;
    *((_DWORD *)this + 7) = v18;
    if ( v18 == nullptr )
      return -2147024882;
    v28 = nullptr;
    if ( *((_DWORD *)this + 6) != 0 )
    {
      v20 = *((_DWORD *)this + 5);
      do
      {
        D3DXShader::CConstant::SetScratch(
          this: *(D3DXShader::CConstant **)(v20 + 4 * v19),
          a2: (unsigned int *)(*((_DWORD *)this + 7) + 4 * (_DWORD)v28));
        v20 = *((_DWORD *)this + 5);
        v28 = (const unsigned int *)((char *)v28
                                   + *(_DWORD *)(*(_DWORD *)(v20 + 4 * v19) + 44)
                                   * *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v20 + 4 * v19) + 24) + 8)
                                   * (*(_WORD *)(*(_DWORD *)(v20 + 4 * v19) + 8) != 0 ? 4 : 1));
        ++v19;
      }
      while ( v19 < *((_DWORD *)this + 6) );
    }
    v21 = 0;
    if ( a3 == nullptr )
      return 0;
    if ( *((_DWORD *)this + 6) != 0 )
    {
      v22 = *((_DWORD *)this + 6);
      v23 = (unsigned __int16 *)(v11 + 8);
      do
      {
        if ( *(v23 - 2) == 2 )
        {
          v24 = *v23;
          if ( v21 < v24 + (unsigned int)*(v23 - 1) )
            v21 = v24 + *(v23 - 1);
        }
        v23 += 10;
        --v22;
      }
      while ( v22 != 0 );
    }
    result = D3DXCreateBuffer(a1: 16 * v21, a2: a3);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DD4CB
// Name: public: virtual unsigned long D3DXShader::CConstantTable::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall D3DXShader::CConstantTable::Release(D3DXShader::CConstantTable *this)
{
  int v1; // eax
  int v2; // esi

  v1 = *((_DWORD *)this + 1);
  v2 = v1 - 1;
  *((_DWORD *)this + 1) = v1 - 1;
  if ( v1 == 1 )
    D3DXShader::CConstantTable::`scalar deleting destructor'(this, a2: 1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101DD4EF
// Name: public: class D3DXShader::CConstant __near * D3DXShader::CConstant::GetConstantByName(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CConstant *__thiscall D3DXShader::CConstant::GetConstantByName(
        D3DXShader::CConstant *this,
        const char *a2,
        unsigned int a3)
{
  char v4; // al
  unsigned int v5; // edi
  D3DXShader::CConstant *ConstantElement; // eax
  int i; // edi
  D3DXShader::CConstant *v8; // ecx
  const char *v11; // [esp+18h] [ebp+8h]
  unsigned int v12; // [esp+1Ch] [ebp+Ch]

  while ( 1 )
  {
    while ( isspace(c: *a2) != 0 )
      ++a2;
    v4 = *a2;
    if ( *a2 == 0 )
      return this;
    if ( v4 != 91 )
      break;
    do
      ++a2;
    while ( isspace(c: *a2) != 0 );
    if ( isdigit(c: *a2) == 0 )
      return nullptr;
    v5 = 0;
    while ( isdigit(c: *a2) != 0 )
      v5 = *a2++ + 10 * v5 - 48;
    while ( isspace(c: *a2) != 0 )
      ++a2;
    if ( *a2 != 93 )
      return nullptr;
    ConstantElement = D3DXShader::CConstant::GetConstantElement(this, a2: v5);
    if ( ConstantElement == nullptr )
      return nullptr;
    a3 = 0;
    ++a2;
LABEL_34:
    this = ConstantElement;
  }
  if ( v4 == 46 )
    goto LABEL_20;
  if ( a3 != 0 )
  {
    while ( isspace(c: *a2) != 0 )
LABEL_20:
      ++a2;
    for ( i = 0; isalnum(c: a2[i]) != 0 || a2[i] == 95; ++i )
      ;
    if ( i != 0 )
    {
      v8 = this;
      v12 = 0;
      v11 = (const char *)*(unsigned __int16 *)(*((_DWORD *)this + 6) + 10);
      while ( v12 < (unsigned int)v11 )
      {
        if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v8 + 14) + 4 * v12) + 4) != 0 && sub_101DA1D9(a1: i) == 0 )
        {
          ConstantElement = D3DXShader::CConstant::GetConstantMember(this, a2: v12);
          if ( ConstantElement == nullptr )
            return nullptr;
          a3 = 0;
          a2 += i;
          goto LABEL_34;
        }
        ++v12;
        v8 = this;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DD63D
// Name: public: long D3DXShader::CConstantTable::FindConstantByName(char const __near *,class D3DXShader::CConstant __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CConstantTable::FindConstantByName(
        D3DXShader::CConstantTable *this,
        const char *a2,
        struct D3DXShader::CConstant **a3)
{
  const char *v3; // edi
  D3DXShader::CConstantTable *v4; // ebx
  int v6; // eax
  unsigned int v7; // esi
  int v8; // edi
  int v9; // eax
  _DWORD *v10; // eax
  const char *v11; // ecx
  char *v12; // eax
  const char *v13; // eax
  struct D3DXShader::CConstant **ConstantByName; // eax
  const char *j; // edi
  const char *v16; // edi
  const char *v17; // eax
  const char *v18; // [esp+8h] [ebp-18h]
  char *v19; // [esp+Ch] [ebp-14h]
  const char *v20; // [esp+10h] [ebp-10h]
  unsigned int v22; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  const char *v24; // [esp+28h] [ebp+8h]
  const char *v25; // [esp+28h] [ebp+8h]

  v3 = a2;
  v4 = this;
  if ( (int)a2 >= 0 )
  {
    v20 = a2;
    if ( isspace(c: *a2) != 0 )
    {
      do
        ++v3;
      while ( isspace(c: *v3) != 0 );
      v20 = v3;
    }
    if ( isalnum(c: *v3) != 0 || *v3 == 95 || *v3 == 36 )
    {
      for ( i = 1; isalnum(c: v3[i]) != 0 || v3[i] == 95; ++i )
        ;
      v6 = *((_DWORD *)v4 + 4);
      v7 = 0;
      v22 = 0;
      v8 = *((_DWORD *)v4 + 2) + *(_DWORD *)(v6 + 16);
      v24 = *(const char **)(v6 + 12);
      if ( v24 != nullptr )
      {
        do
        {
          v7 = (unsigned int)&v24[v22] >> 1;
          v9 = sub_101DA1D9(a1: i);
          if ( v9 == 0 )
            break;
          if ( v9 >= 0 )
            v24 = (const char *)((unsigned int)&v24[v22] >> 1);
          else
            v22 = v7 + 1;
        }
        while ( v22 < (unsigned int)v24 );
        v4 = this;
      }
      if ( (const char *)v22 == v24 )
        return -2005530516;
      v10 = (_DWORD *)(v8 + 20 * v7);
      v11 = (const char *)(*((_DWORD *)v4 + 2) + *v10);
      v18 = v11;
      if ( v7 != 0 )
      {
        v12 = (char *)(v10 - 5);
        v19 = v12;
        do
        {
          v13 = (const char *)(*((_DWORD *)v4 + 2) + *(_DWORD *)v12);
          if ( v11 != v13 && strcmp(v11, v13) != 0 )
            break;
          --v7;
          v12 = v19 - 20;
          v19 -= 20;
        }
        while ( v7 != 0 );
      }
      ConstantByName = (struct D3DXShader::CConstant **)D3DXShader::CConstant::GetConstantByName(
                                                          this: *(D3DXShader::CConstant **)(*((_DWORD *)v4 + 5) + 4 * v7),
                                                          a2: &v20[i],
                                                          a3: 0);
      if ( ConstantByName == nullptr )
      {
        return -2005530516;
      }
      else
      {
        for ( j = (const char *)(v8 + 20 * v7); ; j = v25 )
        {
          *a3 = (struct D3DXShader::CConstant *)ConstantByName;
          a3 = ConstantByName + 9;
          ++v7;
          v16 = j + 20;
          v25 = v16;
          if ( v7 >= *(_DWORD *)(*((_DWORD *)v4 + 4) + 12) )
            break;
          v17 = (const char *)(*((_DWORD *)v4 + 2) + *(_DWORD *)v16);
          if ( v18 != v17 && strcmp(v18, v17) != 0 )
            break;
          ConstantByName = (struct D3DXShader::CConstant **)D3DXShader::CConstant::GetConstantByName(
                                                              this: *(D3DXShader::CConstant **)(*((_DWORD *)v4 + 5) + 4 * v7),
                                                              a2: &v20[i],
                                                              a3: 0);
          if ( ConstantByName == nullptr )
            return -2005530516;
        }
        return 0;
      }
    }
    else
    {
      return -2005530516;
    }
  }
  else
  {
    *a3 = (struct D3DXShader::CConstant *)-(int)a2;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD844
// Name: public: virtual long D3DXShader::CConstantTable::GetConstantDesc(char const __near *,struct _D3DXCONSTANT_DESC __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::GetConstantDesc(
        D3DXShader::CConstantTable *this,
        char *a2,
        struct _D3DXCONSTANT_DESC *a3,
        unsigned int *a4)
{
  struct _D3DXCONSTANT_DESC *v4; // ebx
  unsigned int *v5; // edi
  int result; // eax
  D3DXShader::CConstant *v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // esi
  D3DXShader::CConstant *i; // eax
  int v11; // ecx

  v4 = a3;
  v5 = a4;
  if ( a3 == nullptr && a4 == nullptr )
    return -2005530516;
  if ( (int)a2 >= 0 )
  {
    result = D3DXShader::CConstantTable::FindConstantByName(this, a2, (struct D3DXShader::CConstant **)&a3);
    if ( result < 0 )
      return result;
    v7 = (D3DXShader::CConstant *)a3;
  }
  else
  {
    v7 = (D3DXShader::CConstant *)-(int)a2;
  }
  v8 = 0;
  v9 = 1;
  for ( i = v7; i != nullptr; ++v8 )
    i = *((D3DXShader::CConstant **)i + 9);
  if ( v5 != nullptr )
  {
    if ( *v5 != 0 )
      v9 = *v5;
    if ( v9 > v8 )
      v9 = v8;
    *v5 = v8;
  }
  if ( v4 != nullptr )
  {
    while ( v7 != nullptr && v9 != 0 )
    {
      result = D3DXShader::CConstant::GetDesc(this: v7, a2: v4);
      if ( result < 0 )
        return result;
      v7 = *(D3DXShader::CConstant **)(v11 + 36);
      ++v4;
      --v9;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DD8CF
// Name: public: virtual unsigned int D3DXShader::CConstantTable::GetSamplerIndex(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall D3DXShader::CConstantTable::GetSamplerIndex(D3DXShader::CConstantTable *this, int a2)
{
  int v2; // eax

  if ( a2 >= 0 )
  {
    if ( D3DXShader::CConstantTable::FindConstantByName(
           this,
           (const char *)a2,
           a3: (struct D3DXShader::CConstant **)&a2) < 0 )
      return -1;
    v2 = a2;
  }
  else
  {
    v2 = -a2;
  }
  if ( *(_WORD *)(v2 + 8) != 3 )
    return -1;
  return *(unsigned __int16 *)(v2 + 10);
}

//------------------------------------------------------------------------------
// Address: 0x101DD907
// Name: public: virtual char const __near * D3DXShader::CConstantTable::GetConstant(char const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__stdcall D3DXShader::CConstantTable::GetConstant(
        D3DXShader::CConstantTable *this,
        char *a2,
        unsigned int a3)
{
  int ConstantMember; // eax

  if ( a2 != nullptr )
  {
    if ( (int)a2 >= 0 )
    {
      if ( D3DXShader::CConstantTable::FindConstantByName(this, a2, a3: &this) < 0 )
        return nullptr;
    }
    else
    {
      this = (D3DXShader::CConstantTable *)-(int)a2;
    }
    ConstantMember = (int)D3DXShader::CConstant::GetConstantMember(this, a2: a3);
    if ( ConstantMember != 0 )
      return (const char *)-ConstantMember;
  }
  else if ( a3 < *((_DWORD *)this + 6) )
  {
    ConstantMember = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3);
    return (const char *)-ConstantMember;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DD957
// Name: public: virtual char const __near * D3DXShader::CConstantTable::GetConstantByName(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__stdcall D3DXShader::CConstantTable::GetConstantByName(int this, char *a2, char *a3)
{
  int ConstantByName; // eax

  if ( a2 != nullptr )
  {
    if ( (int)a2 >= 0 )
    {
      if ( D3DXShader::CConstantTable::FindConstantByName(
             (D3DXShader::CConstantTable *)this,
             a2,
             a3: (struct D3DXShader::CConstant **)&this) < 0 )
        return nullptr;
    }
    else
    {
      this = -(int)a2;
    }
    ConstantByName = (int)D3DXShader::CConstant::GetConstantByName((D3DXShader::CConstant *)this, a2: a3, a3: 1u);
    if ( ConstantByName != 0 )
      return (const char *)-ConstantByName;
  }
  else
  {
    if ( (int)a3 < 0 )
    {
      ConstantByName = -(int)a3;
      return (const char *)-ConstantByName;
    }
    if ( D3DXShader::CConstantTable::FindConstantByName(
           (D3DXShader::CConstantTable *)this,
           a2: a3,
           a3: (struct D3DXShader::CConstant **)&this) >= 0 )
    {
      ConstantByName = this;
      return (const char *)-ConstantByName;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DD9B7
// Name: public: virtual char const __near * D3DXShader::CConstantTable::GetConstantElement(char const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__stdcall D3DXShader::CConstantTable::GetConstantElement(
        D3DXShader::CConstantTable *this,
        int a2,
        unsigned int a3)
{
  int ConstantElement; // eax

  if ( a2 >= 0 )
  {
    if ( D3DXShader::CConstantTable::FindConstantByName(
           this,
           (const char *)a2,
           a3: (struct D3DXShader::CConstant **)&a2) < 0 )
      return nullptr;
  }
  else
  {
    a2 = -a2;
  }
  ConstantElement = (int)D3DXShader::CConstant::GetConstantElement(this: (D3DXShader::CConstant *)a2, a2: a3);
  if ( ConstantElement == 0 )
    return nullptr;
  return (const char *)-ConstantElement;
}

//------------------------------------------------------------------------------
// Address: 0x101DD9F4
// Name: public: virtual long D3DXShader::CConstantTable::SetValue(struct IDirect3DDevice9 __near *,char const __near *,void const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::SetValue(
        D3DXShader::CConstantTable *this,
        struct IDirect3DDevice9 *a2,
        int a3,
        const void *a4,
        unsigned int a5)
{
  int v5; // edi
  int result; // eax
  unsigned int v7; // esi

  if ( a3 >= 0 )
  {
    result = D3DXShader::CConstantTable::FindConstantByName(
               this,
               a2: (const char *)a3,
               (struct D3DXShader::CConstant **)&a3);
    if ( result < 0 )
      return result;
    v5 = a3;
  }
  else
  {
    v5 = -a3;
  }
  v7 = a5 >> 2;
  while ( 1 )
  {
    result = D3DXShader::SetTyped<0,0,1,1,0>::Set(a1: v5, (int)a2, a3: (int)a4, a4: v7, a5: 0);
    if ( result < 0 )
      break;
    v5 = *(_DWORD *)(v5 + 36);
    if ( v5 == 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028BA40
// Name: _dynamic_initializer_for__notsetVal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__notsetVal__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__notsetVal__);
}
