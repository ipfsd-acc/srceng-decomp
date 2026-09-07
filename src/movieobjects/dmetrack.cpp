// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmetrack.cpp
// Functions: 20
// ============================================================

#include "movieobjects\dmetrack.h"

//------------------------------------------------------------------------------
// Address: 0x004A7EE0
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipCount(CDmeVertexDataBase *this)
{
  return this->m_VertexFormat.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B95E0
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x004B9740
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9780
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004B9790
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x004B97B0
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x004B97D0
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeClip::m_classType) )
    return (CDmeClip *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B9820
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  CDmeTrack *v4; // edi
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // esi
  CDmElement *v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
      v6 = nullptr;
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips;
        do
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeClip::m_classType) && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9990
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9B00
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9CD0
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B9D50
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9D80
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9DC0
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0054CAB0
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x005AC7E0
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFE80
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AC810
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC820
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFE90
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0050FA30
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x0050FB90
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050FBD0
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0050FBE0
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (const int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x0050FC00
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x0050FC20
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0050FC30
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeClip::m_classType) )
    return (CDmeClip *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0050FC80
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  CDmeTrack *v4; // edi
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<vgui::TreeNode *,int> *v7; // esi
  CDmElement *v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
      v6 = nullptr;
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = clips;
        do
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeClip::m_classType) && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050FDF0
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050FF60
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00510130
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005101B0
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005101E0
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510220
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AF520
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x0067DF10
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682350
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067DF40
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067DF50
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682360
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104FB7E0
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x105859D0
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x10595DF0
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x10595F50
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10595F90
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x10595FA0
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x10595FC0
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x10595FE0
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeClip::m_classType) )
    return (CDmeClip *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10596030
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  CDmeTrack *v4; // edi
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<vgui::TreeNode *,int> *v7; // esi
  CDmElement *v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
      v6 = nullptr;
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = clips;
        do
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeClip::m_classType) && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)&v14[(_DWORD)m_pMemory + 1],
                  src: (unsigned __int8 *)&v14[(_DWORD)m_pMemory],
                  count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x105961A0
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)&v13[(_DWORD)m_pMemory + 1],
                  src: (unsigned __int8 *)&v13[(_DWORD)m_pMemory],
                  count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10596310
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)&v13[(_DWORD)m_pMemory + 1],
                  src: (unsigned __int8 *)&v13[(_DWORD)m_pMemory],
                  count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x105964E0
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10596560
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10596590
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x105965D0
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C98F0
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 0x98u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB10
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9920
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9930
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB20
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004C1D20
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x004C1E80
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1EC0
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004C1ED0
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x004C1EF0
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x004C1F10
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeClip::m_classType.u) != 0 )
  {
    return (CDmeClip *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1F60
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v4; // edi
  int v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // esi
  int v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v6 = nullptr;
    }
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = clips;
        do
        {
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmeClip::m_classType.u) != 0
            && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C20D0
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  int v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  int v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v7 = nullptr;
    }
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                 a1: v9,
                 a2: CDmeClip::m_classType.u) != 0
            && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C2240
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  int v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  int v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v7 = nullptr;
    }
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                 a1: v9,
                 a2: CDmeClip::m_classType.u) != 0
            && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C2410
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C2490
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C24C0
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C2500
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x004C2510
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004CB120
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0059B940
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F030
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059B970
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B980
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F040
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050FB00
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x0050FC60
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050FCA0
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0050FCB0
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x0050FCD0
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x0050FCF0
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0050FD00
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeClip::m_classType.u) != 0 )
  {
    return (CDmeClip *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050FD50
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v4; // edi
  int v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // esi
  int v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v6 = nullptr;
    }
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = clips;
        do
        {
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmeClip::m_classType.u) != 0
            && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050FEC0
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  int v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  int v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v7 = nullptr;
    }
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                 a1: v9,
                 a2: CDmeClip::m_classType.u) != 0
            && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00510030
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  int v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  int v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v7 = nullptr;
    }
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                 a1: v9,
                 a2: CDmeClip::m_classType.u) != 0
            && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00510200
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00510280
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005102B0
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005102F0
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005A2210
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x005F0990
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4480
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F09C0
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F09D0
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4490
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00466290
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0047A980
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x0047AAE0
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047AB20
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0047AB30
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x0047AB50
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x0047AB70
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeClip::m_classType) )
    return (CDmeClip *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047ABC0
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v4; // edi
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // esi
  CDmElement *v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
      v6 = nullptr;
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = clips;
        do
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeClip::m_classType) && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047AD30
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047AEA0
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B070
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047B0F0
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047B120
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047B160
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x0047B170
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056AAF0
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E530
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056AB20
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056AB30
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E540
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00469690
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0047FCB0
// Name: class CDmeTrackGroup __near * GetParentTrackGroup(class CDmeTrack __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__cdecl GetParentTrackGroup(CDmeTrack *pTrack)
{
  IDataModel_vtbl *v1; // esi
  int v2; // eax
  DmAttributeReferenceIterator_t v3; // edi
  CDmAttribute *v4; // eax
  CDmElement *m_pOwner; // esi

  v1 = g_pDataModel->__vftable;
  v2 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pTrack);
  v3 = v1->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v2);
  if ( v3 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v3);
    if ( v4 != nullptr )
    {
      m_pOwner = v4->m_pOwner;
      if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeTrackGroup::m_classType) )
        break;
    }
    v3 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v3);
    if ( v3 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return (CDmeTrackGroup *)m_pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x0047FD40
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x0047FEA0
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FEE0
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0047FEF0
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x0047FF10
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x0047FF30
// Name: public: void CDmeTrack::AddClip(class CDmeClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::AddClip(CDmeTrack *this, CDmeClip *clip)
{
  CExpressionCalculator *v2; // edi
  int m_Storage; // ebx

  v2 = (CExpressionCalculator *)clip;
  m_Storage = this->m_ClipType.m_Storage;
  if ( clip->GetClipType(this: clip) == m_Storage )
  {
    clip = (CDmeClip *)CExpressionCalculator::VariableCount(this: v2);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Clips,
      src: (DmElementHandle_t *)&clip);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FF70
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeClip::m_classType) )
    return (CDmeClip *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047FFC0
// Name: public: int CDmeTrack::FindClip(class CDmeClip __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::FindClip(CDmeTrack *this, CDmeClip *clip)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeClip *v5; // esi

  v3 = this->m_Clips.m_Storage.m_Size - 1;
  if ( v3 < 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeClip *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeClip::m_classType) )
      v5 = nullptr;
    if ( v5 == clip )
      break;
    if ( --v3 < 0 )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00480020
// Name: public: class CDmeClip __near * CDmeTrack::FindNamedClip(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::FindNamedClip(CDmeTrack *this, const char *name)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax

  v3 = this->m_Clips.m_Storage.m_Size - 1;
  if ( v3 < 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeClip::m_classType) )
    {
      m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      if ( _V_stricmp(s1: m_pAsString, s2: name) == 0 )
        break;
    }
    if ( --v3 < 0 )
      return nullptr;
  }
  return (CDmeClip *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004800A0
// Name: public: bool CDmeTrack::RemoveClip(class CDmeClip __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrack::RemoveClip(CDmeTrack *this, CDmeClip *clip)
{
  int v3; // eax

  v3 = CDmeTrack::FindClip(this, clip);
  if ( v3 == -1 )
    return 0;
  this->m_Flags.m_nFlags |= 6u;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: &this->m_Clips,
    elem: v3);
  this->m_Flags.m_nFlags &= 0xF9u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004800E0
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  CDmeTrack *v4; // edi
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // esi
  CDmElement *v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
      v6 = nullptr;
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips;
        do
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeClip::m_classType) && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480250
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004803C0
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480590
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00480610
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480640
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480680
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051F730
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x0057ABF0
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E660
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057AC20
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057AC30
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E670
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0053BF10
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005D9050
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x005D91B0
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D91F0
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005D9200
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (const int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x005D9220
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x005D9240
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeClip::m_classType.u) != 0 )
  {
    return (CDmeClip *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D9290
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  CDmeTrack *v4; // edi
  int v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<vgui::TreeNode *,int> *v7; // esi
  int v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v6 = nullptr;
    }
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = clips;
        do
        {
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmeClip::m_classType.u) != 0
            && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D9400
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  CDmeTrack *v5; // edi
  int v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  int v9; // eax
  CDmeClip *v10; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v7 = nullptr;
    }
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                 a1: v9,
                 a2: CDmeClip::m_classType.u) != 0
            && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D9570
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  CDmeTrack *v5; // edi
  int v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<vgui::TreeNode *,int> *v8; // esi
  int v9; // eax
  CDmeClip *v10; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v7 = nullptr;
    }
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                 a1: v9,
                 a2: CDmeClip::m_classType.u) != 0
            && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D9740
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005D97C0
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D97F0
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D9830
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005DCD90
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x006B0C50
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5350
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0C80
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0C90
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5360
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0047B470
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00480C60
// Name: class CDmeTrackGroup __near * GetParentTrackGroup(class CDmeTrack __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__cdecl GetParentTrackGroup(CDmeTrack *pTrack)
{
  IDataModel_vtbl *v1; // esi
  int v2; // eax
  DmAttributeReferenceIterator_t v3; // edi
  CDmAttribute *v4; // eax
  CDmElement *m_pOwner; // esi

  v1 = g_pDataModel->__vftable;
  v2 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pTrack);
  v3 = v1->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v2);
  if ( v3 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v3);
    if ( v4 != nullptr )
    {
      m_pOwner = v4->m_pOwner;
      if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeTrackGroup::m_classType) )
        break;
    }
    v3 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v3);
    if ( v3 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return (CDmeTrackGroup *)m_pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x00480CF0
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x00480E50
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480E90
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00480EA0
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x00480EC0
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x00480EE0
// Name: public: void CDmeTrack::AddClip(class CDmeClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::AddClip(CDmeTrack *this, CDmeClip *clip)
{
  CExpressionCalculator *v2; // edi
  int m_Storage; // ebx

  v2 = (CExpressionCalculator *)clip;
  m_Storage = this->m_ClipType.m_Storage;
  if ( clip->GetClipType(this: clip) == m_Storage )
  {
    clip = (CDmeClip *)CExpressionCalculator::VariableCount(this: v2);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Clips,
      src: (const DmElementHandle_t *)&clip);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480F20
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeClip::m_classType) )
    return (CDmeClip *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00480F70
// Name: public: int CDmeTrack::FindClip(class CDmeClip __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::FindClip(CDmeTrack *this, CDmeClip *clip)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeClip *v5; // esi

  v3 = this->m_Clips.m_Storage.m_Size - 1;
  if ( v3 < 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeClip *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeClip::m_classType) )
      v5 = nullptr;
    if ( v5 == clip )
      break;
    if ( --v3 < 0 )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00480FE0
// Name: public: class CDmeClip __near * CDmeTrack::FindNamedClip(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::FindNamedClip(CDmeTrack *this, const char *name)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax

  v3 = this->m_Clips.m_Storage.m_Size - 1;
  if ( v3 < 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeClip::m_classType) )
    {
      m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pch;
      if ( _V_stricmp(s1: m_pAsString, s2: name) == 0 )
        break;
    }
    if ( --v3 < 0 )
      return nullptr;
  }
  return (CDmeClip *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00481060
// Name: public: bool CDmeTrack::RemoveClip(class CDmeClip __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrack::RemoveClip(CDmeTrack *this, CDmeClip *clip)
{
  int v3; // eax

  v3 = CDmeTrack::FindClip(this, clip);
  if ( v3 == -1 )
    return 0;
  this->m_Flags.m_nFlags |= 6u;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: &this->m_Clips,
    elem: v3);
  this->m_Flags.m_nFlags &= 0xF9u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004810A0
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  CDmeTrack *v4; // edi
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // esi
  CDmElement *v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
      v6 = nullptr;
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips;
        do
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeClip::m_classType) && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481210
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481380
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481550
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004815D0
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481600
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481640
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x00481650
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057CBE0
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580640
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CC10
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CC20
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580650
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E2B10
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x004EDDC0
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00508B40
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x00508CA0
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00508CE0
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00508CF0
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x00508D10
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x00508D30
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeClip::m_classType.u) != 0 )
  {
    return (CDmeClip *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00508D80
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v4; // edi
  int v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // esi
  int v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v6 = nullptr;
    }
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = clips;
        do
        {
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmeClip::m_classType.u) != 0
            && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00508EF0
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  int v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  int v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v7 = nullptr;
    }
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                 a1: v9,
                 a2: CDmeClip::m_classType.u) != 0
            && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00509060
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  int v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  int v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) == 0 )
    {
      v7 = nullptr;
    }
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                 a1: v9,
                 a2: CDmeClip::m_classType.u) != 0
            && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00509230
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005092B0
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005092E0
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00509320
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E9830
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED320
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E9860
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9870
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED330
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00489540
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x004896A0
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004896E0
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004896F0
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (const int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x00489710
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x00489730
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeClip::m_classType) )
    return (CDmeClip *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00489780
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  CDmeTrack *v4; // edi
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // esi
  CDmElement *v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
      v6 = nullptr;
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips;
        do
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeClip::m_classType) && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004898F0
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489A60
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489C30
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00489CB0
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00489CE0
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00489D20
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004929C0
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTrack::GetClipCount(CDmeTransform *this)
{
  return this->m_Position.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00528A00
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x0057A490
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD50
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057A4C0
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A4D0
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD60
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0058C1D0
// Name: protected: void CDmeTrack::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnConstruction(CDmeTrack *this)
{
  CDmaElementArray<CDmeClip> *p_m_Clips; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Clips = &this->m_Clips;
  this->m_hOwner = DMELEMENT_HANDLE_INVALID;
  this->m_Flags.m_nFlags = 0;
  this->m_Clips.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "children",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_Clips);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Clips->m_pAttribute, typeSymbol: CDmeClip::m_classType);
  p_m_Clips->m_pAttribute->m_nFlags |= 0x100u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "collapsed", type: AT_BOOL, pMemory: &this->m_Collapsed);
  this->m_Collapsed.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "mute", type: AT_BOOL, pMemory: &this->m_Mute);
  this->m_Mute.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "synched", type: AT_BOOL, pMemory: &this->m_Synched);
  this->m_Synched.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v9 = -1;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "clipType", type: AT_INT, pMemory: &this->m_ClipType);
  this->m_ClipType.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v9);
  this->m_ClipType.m_pAttribute->m_nFlags |= 0x100u;
  v9 = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&v9);
  v9 = 1065353216;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v9);
}

//------------------------------------------------------------------------------
// Address: 0x0058C330
// Name: public: virtual void CDmeTrack::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::OnAttributeChanged(CDmeTrack *this, CDmAttribute *pAttribute)
{
  bool v2; // zf

  if ( pAttribute == this->m_ClipType.m_pAttribute )
  {
    v2 = this->m_ClipType.m_Storage == 3;
    goto LABEL_6;
  }
  if ( pAttribute == this->m_Clips.m_pAttribute || pAttribute->m_pOwner != this )
  {
    v2 = (this->m_Flags.m_nFlags & 4) == 0;
LABEL_6:
    if ( v2 )
      this->m_Flags.m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058C370
// Name: public: enum DmeClipType_t CDmeTrack::GetClipType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipType(CDmeTrack *this)
{
  return this->m_ClipType.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0058C380
// Name: public: void CDmeTrack::SetClipType(enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetClipType(CDmeTrack *this, DmeClipType_t type)
{
  CDmAttribute::SetValue<int>(this: this->m_ClipType.m_pAttribute, value: (int *)&type);
}

//------------------------------------------------------------------------------
// Address: 0x0058C3A0
// Name: public: void CDmeTrack::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::SetCollapsed(CDmeTrack *this, bool state)
{
  CDmAttribute::SetValue<bool>(this: this->m_Collapsed.m_pAttribute, value: &state);
}

//------------------------------------------------------------------------------
// Address: 0x0058C3C0
// Name: public: class CDmeClip __near * CDmeTrack::GetClip(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrack::GetClip(CDmeTrack *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Clips.m_Storage.m_Memory.m_pMemory[i]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeClip::m_classType) )
    return (CDmeClip *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0058C410
// Name: public: void CDmeTrack::FindClipsAtTime(class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsAtTime(
        CDmeTrack *this,
        DmeTime_t time,
        int flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  CDmeTrack *v4; // edi
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi
  CUtlMemory<S3RGBA,int> *v7; // esi
  CDmElement *v8; // eax
  CDmeClip *v9; // ebx
  DmeTime_t *EndTime; // edi
  DmeTime_t *StartTime; // eax
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v14; // ecx
  int v15; // eax
  CDmeClip **v16; // edi
  DmeTime_t result; // [esp+Ch] [ebp-10h] BYREF
  int nClipCount; // [esp+10h] [ebp-Ch]
  __int32 v19; // [esp+14h] [ebp-8h]
  CDmeTrack *v20; // [esp+18h] [ebp-4h]

  v4 = this;
  v20 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v19 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v6 = (CDmeTrack *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
      v6 = nullptr;
    if ( !v4->m_Mute.m_Storage && (v6 == v4 || v6 == nullptr) )
    {
LABEL_10:
      nClipCount = v4->m_Clips.m_Storage.m_Size;
      flags = 0;
      if ( nClipCount > 0 )
      {
        v7 = (CUtlMemory<S3RGBA,int> *)clips;
        do
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Clips.m_Storage.m_Memory.m_pMemory[flags]);
          v9 = (CDmeClip *)v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeClip::m_classType) && (v19 == 0 || !v9->m_bMute.m_Storage) )
          {
            EndTime = CDmeClip::GetEndTime(this: v9, result: (DmeTime_t *)&clips);
            StartTime = CDmeClip::GetStartTime(this: v9, &result);
            if ( DmeTime_t::IsInRange(this: &time, lo: (DmeTime_t)StartTime->m_tms, hi: (DmeTime_t)EndTime->m_tms) )
            {
              m_pMemory = v7[1].m_pMemory;
              m_nAllocationCount = v7->m_nAllocationCount;
              if ( (int)&m_pMemory->g > m_nAllocationCount )
                CUtlMemory<HemiLightData_t *,int>::Grow(this: v7, num: (int)(&m_pMemory->g - m_nAllocationCount));
              ++v7[1].m_pMemory;
              v14 = v7->m_pMemory;
              v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
              v7[1].m_nAllocationCount = (int)v7->m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
              v16 = (CDmeClip **)&v7->m_pMemory[(_DWORD)m_pMemory];
              if ( v16 != nullptr )
                *v16 = v9;
            }
            v4 = v20;
          }
          ++flags;
        }
        while ( flags < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058C580
// Name: public: void CDmeTrack::FindClipsIntersectingTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsIntersectingTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<S3RGBA,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<S3RGBA,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipStart; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: &clipStart);
            CDmeClip::GetEndTime(this: v10, result: (DmeTime_t *)&clips);
            if ( (int)clips >= startTime.m_tms && clipStart.m_tms < endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)&m_pMemory->g > m_nAllocationCount )
                CUtlMemory<HemiLightData_t *,int>::Grow(this: v8, num: (int)(&m_pMemory->g - m_nAllocationCount));
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058C6F0
// Name: public: void CDmeTrack::FindClipsWithinTime(class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::FindClipsWithinTime(
        CDmeTrack *this,
        DmeTime_t startTime,
        DmeTime_t endTime,
        int flags,
        CUtlMemory<S3RGBA,int> *clips)
{
  CDmeTrack *v5; // edi
  CDmElement *v6; // eax
  CDmeTrack *v7; // esi
  CUtlMemory<S3RGBA,int> *v8; // esi
  CDmElement *v9; // eax
  CDmeClip *v10; // ebx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v13; // ecx
  int v14; // eax
  CDmeClip **v15; // edi
  int nClipCount; // [esp+Ch] [ebp-10h]
  DmeTime_t clipEnd; // [esp+10h] [ebp-Ch] BYREF
  __int32 v18; // [esp+14h] [ebp-8h]
  CDmeTrack *v19; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  v5 = this;
  v19 = this;
  if ( (flags & 2) == 0 || !this->m_Collapsed.m_Storage )
  {
    v18 = flags & 1;
    if ( (flags & 1) == 0 )
      goto LABEL_10;
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: CDmeTrack::m_hSoloTrack[this->m_ClipType.m_Storage]);
    v7 = (CDmeTrack *)v6;
    if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeTrack::m_classType) )
      v7 = nullptr;
    if ( !v5->m_Mute.m_Storage && (v7 == v5 || v7 == nullptr) )
    {
LABEL_10:
      nClipCount = v5->m_Clips.m_Storage.m_Size;
      j = 0;
      if ( nClipCount > 0 )
      {
        v8 = clips;
        do
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Clips.m_Storage.m_Memory.m_pMemory[j]);
          v10 = (CDmeClip *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeClip::m_classType) && (v18 == 0 || !v10->m_bMute.m_Storage) )
          {
            CDmeClip::GetStartTime(this: v10, result: (DmeTime_t *)&clips);
            CDmeClip::GetEndTime(this: v10, result: &clipEnd);
            if ( (int)clips >= startTime.m_tms && clipEnd.m_tms <= endTime.m_tms )
            {
              m_pMemory = v8[1].m_pMemory;
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( (int)&m_pMemory->g > m_nAllocationCount )
                CUtlMemory<HemiLightData_t *,int>::Grow(this: v8, num: (int)(&m_pMemory->g - m_nAllocationCount));
              ++v8[1].m_pMemory;
              v13 = v8->m_pMemory;
              v14 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
              v15 = (CDmeClip **)&v8->m_pMemory[(_DWORD)m_pMemory];
              if ( v15 != nullptr )
                *v15 = v10;
              v5 = v19;
            }
          }
          ++j;
        }
        while ( j < nClipCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058C8C0
// Name: protected: CDmeTrack::CDmeTrack(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrack::CDmeTrack(
        CDmeTrack *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrack_vtbl *)&CDmeTrack::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Clips);
  this->m_Volume = 0;
  this->m_Collapsed.m_pAttribute = nullptr;
  this->m_Collapsed.m_Storage = false;
  this->m_Mute.m_pAttribute = nullptr;
  this->m_Mute.m_Storage = false;
  this->m_Synched.m_pAttribute = nullptr;
  this->m_Synched.m_Storage = false;
  this->m_ClipType.m_pAttribute = nullptr;
  this->m_ClipType.m_Storage = 0;
  this->m_flDisplayScale = 0;
  this->m_Flags.m_nFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0058C940
// Name: public: virtual bool CDmeTrack::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrack::IsA(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0058C970
// Name: public: virtual int CDmeTrack::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetInheritanceDepth(CDmeTrack *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrack::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0058C9B0
// Name: protected: virtual void CDmeTrack::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrack::PerformConstruction(CDmeTrack *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTrack::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00595820
// Name: public: int CDmeTrack::GetClipCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::GetClipCount(CVTFTexture *this)
{
  return this->m_nLowResImageWidth;
}

//------------------------------------------------------------------------------
// Address: 0x0062B6D0
// Name: protected: virtual int CDmeTrack::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrack::AllocatedSize(CDmeTrack *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x006B83A0
// Name: _dynamic_initializer_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrack::s_Allocator,
    blockSize: 0x98u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrack pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BCB50
// Name: _dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrack::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrack::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B83D0
// Name: _dynamic_initializer_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrack_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrack_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B83E0
// Name: _dynamic_initializer_for__g_CDmeTrack_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrack_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrack_Helper,
           classname: "DmeTrack",
           pFactory: &g_CDmeTrack_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BCB60
// Name: _dynamic_atexit_destructor_for__g_CDmeTrack_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrack_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTrack_Factory.m_CallBackList);
}

} // namespace vmap
